// FtdPackageDesc.cpp: 
//
//////////////////////////////////////////////////////////////////////

#include "public.h"
#include "FtdPackageDesc.h"
#include "HashMap.h"

TFieldUse FTDRspErrorFieldUse[]=
{
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqUserLoginFieldUse[]=
{
		{ FTD_FID_ReqUserLogin, &(CFTDReqUserLoginField::m_Describe), 1,  1  }
			,
		{ FTD_FID_Dissemination, &(CFTDDisseminationField::m_Describe), 0,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspUserLoginFieldUse[]=
{
		{ FTD_FID_RspUserLogin, &(CFTDRspUserLoginField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqUserLogoutFieldUse[]=
{
		{ FTD_FID_ReqUserLogout, &(CFTDReqUserLogoutField::m_Describe), 1,  1  }
};

TFieldUse FTDRspUserLogoutFieldUse[]=
{
		{ FTD_FID_RspUserLogout, &(CFTDRspUserLogoutField::m_Describe), 1,  1  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqOrderInsertFieldUse[]=
{
		{ FTD_FID_InputOrder, &(CFTDInputOrderField::m_Describe), 1,  1  }
};

TFieldUse FTDRspOrderInsertFieldUse[]=
{
		{ FTD_FID_InputOrder, &(CFTDInputOrderField::m_Describe), 1,  1  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqOrderActionFieldUse[]=
{
		{ FTD_FID_OrderAction, &(CFTDOrderActionField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspOrderActionFieldUse[]=
{
		{ FTD_FID_OrderAction, &(CFTDOrderActionField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQuoteInsertFieldUse[]=
{
		{ FTD_FID_InputQuote, &(CFTDInputQuoteField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQuoteInsertFieldUse[]=
{
		{ FTD_FID_InputQuote, &(CFTDInputQuoteField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQuoteActionFieldUse[]=
{
		{ FTD_FID_QuoteAction, &(CFTDQuoteActionField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQuoteActionFieldUse[]=
{
		{ FTD_FID_QuoteAction, &(CFTDQuoteActionField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqOTCOrderInsertFieldUse[]=
{
		{ FTD_FID_OTCOrder, &(CFTDOTCOrderField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspOTCOrderInsertFieldUse[]=
{
		{ FTD_FID_OTCOrder, &(CFTDOTCOrderField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqUserPasswordUpdateFieldUse[]=
{
		{ FTD_FID_UserPasswordUpdate, &(CFTDUserPasswordUpdateField::m_Describe), 1,  1  }
};

TFieldUse FTDRspUserPasswordUpdateFieldUse[]=
{
		{ FTD_FID_UserPasswordUpdate, &(CFTDUserPasswordUpdateField::m_Describe), 1,  1  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqExecOrderInsertFieldUse[]=
{
		{ FTD_FID_InputExecOrder, &(CFTDInputExecOrderField::m_Describe), 1,  1  }
};

TFieldUse FTDRspExecOrderInsertFieldUse[]=
{
		{ FTD_FID_InputExecOrder, &(CFTDInputExecOrderField::m_Describe), 1,  1  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqExecOrderActionFieldUse[]=
{
		{ FTD_FID_ExecOrderAction, &(CFTDExecOrderActionField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspExecOrderActionFieldUse[]=
{
		{ FTD_FID_ExecOrderAction, &(CFTDExecOrderActionField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqAdminOrderInsertFieldUse[]=
{
		{ FTD_FID_InputAdminOrder, &(CFTDInputAdminOrderField::m_Describe), 1,  1  }
};

TFieldUse FTDRspAdminOrderInsertFieldUse[]=
{
		{ FTD_FID_InputAdminOrder, &(CFTDInputAdminOrderField::m_Describe), 1,  1  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqCombOrderInsertFieldUse[]=
{
		{ FTD_FID_InputCombOrder, &(CFTDInputCombOrderField::m_Describe), 1,  1  }
};

TFieldUse FTDRspCombOrderInsertFieldUse[]=
{
		{ FTD_FID_InputCombOrder, &(CFTDInputCombOrderField::m_Describe), 1,  1  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqSubscribeTopicFieldUse[]=
{
		{ FTD_FID_Dissemination, &(CFTDDisseminationField::m_Describe), 0,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspSubscribeTopicFieldUse[]=
{
		{ FTD_FID_Dissemination, &(CFTDDisseminationField::m_Describe), 0,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqBulletinFieldUse[]=
{
		{ FTD_FID_Bulletin, &(CFTDBulletinField::m_Describe), 1,  1  }
};

TFieldUse FTDRspBulletinFieldUse[]=
{
		{ FTD_FID_Bulletin, &(CFTDBulletinField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqInformationFieldUse[]=
{
		{ FTD_FID_Information, &(CFTDInformationField::m_Describe), 1,  1  }
};

TFieldUse FTDRspInformationFieldUse[]=
{
		{ FTD_FID_Information, &(CFTDInformationField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqInstrumentStatusUpdateFieldUse[]=
{
		{ FTD_FID_InstrumentStatus, &(CFTDInstrumentStatusField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspInstrumentStatusUpdateFieldUse[]=
{
		{ FTD_FID_InstrumentStatus, &(CFTDInstrumentStatusField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqForceUserExitFieldUse[]=
{
		{ FTD_FID_ForceUserExit, &(CFTDForceUserExitField::m_Describe), 1,  1  }
};

TFieldUse FTDRspForceUserExitFieldUse[]=
{
		{ FTD_FID_ForceUserExit, &(CFTDForceUserExitField::m_Describe), 1,  1  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqForceUserLogoutFieldUse[]=
{
		{ FTD_FID_ForceUserExit, &(CFTDForceUserExitField::m_Describe), 1,  1  }
};

TFieldUse FTDRspForceUserLogoutFieldUse[]=
{
		{ FTD_FID_ForceUserExit, &(CFTDForceUserExitField::m_Describe), 1,  1  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqExchangeDataSyncStatusUpdateFieldUse[]=
{
		{ FTD_FID_ExchangeDataSyncStatus, &(CFTDExchangeDataSyncStatusField::m_Describe), 1,  1  }
};

TFieldUse FTDRspExchangeDataSyncStatusUpdateFieldUse[]=
{
		{ FTD_FID_ExchangeDataSyncStatus, &(CFTDExchangeDataSyncStatusField::m_Describe), 1,  1  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqSGDataSyncStatusUpdateFieldUse[]=
{
		{ FTD_FID_SGDataSyncStatus, &(CFTDSGDataSyncStatusField::m_Describe), 1,  1  }
};

TFieldUse FTDRspSGDataSyncStatusUpdateFieldUse[]=
{
		{ FTD_FID_SGDataSyncStatus, &(CFTDSGDataSyncStatusField::m_Describe), 1,  1  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqQryPartAccountFieldUse[]=
{
		{ FTD_FID_QryPartAccount, &(CFTDQryPartAccountField::m_Describe), 1,  1  }
};

TFieldUse FTDRspQryPartAccountFieldUse[]=
{
		{ FTD_FID_RspPartAccount, &(CFTDRspPartAccountField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryOrderFieldUse[]=
{
		{ FTD_FID_QryOrder, &(CFTDQryOrderField::m_Describe), 1,  1  }
};

TFieldUse FTDRspQryOrderFieldUse[]=
{
		{ FTD_FID_Order, &(CFTDOrderField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryQuoteFieldUse[]=
{
		{ FTD_FID_QryQuote, &(CFTDQryQuoteField::m_Describe), 1,  1  }
};

TFieldUse FTDRspQryQuoteFieldUse[]=
{
		{ FTD_FID_Quote, &(CFTDQuoteField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryTradeFieldUse[]=
{
		{ FTD_FID_QryTrade, &(CFTDQryTradeField::m_Describe), 1,  1  }
};

TFieldUse FTDRspQryTradeFieldUse[]=
{
		{ FTD_FID_Trade, &(CFTDTradeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryClientFieldUse[]=
{
		{ FTD_FID_QryClient, &(CFTDQryClientField::m_Describe), 1,  1  }
};

TFieldUse FTDRspQryClientFieldUse[]=
{
		{ FTD_FID_RspClient, &(CFTDRspClientField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryPartPositionFieldUse[]=
{
		{ FTD_FID_QryPartPosition, &(CFTDQryPartPositionField::m_Describe), 1,  1  }
};

TFieldUse FTDRspQryPartPositionFieldUse[]=
{
		{ FTD_FID_RspPartPosition, &(CFTDRspPartPositionField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryClientPositionFieldUse[]=
{
		{ FTD_FID_QryClientPosition, &(CFTDQryClientPositionField::m_Describe), 1,  1  }
};

TFieldUse FTDRspQryClientPositionFieldUse[]=
{
		{ FTD_FID_RspClientPosition, &(CFTDRspClientPositionField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryInstrumentFieldUse[]=
{
		{ FTD_FID_QryInstrument, &(CFTDQryInstrumentField::m_Describe), 1,  1  }
};

TFieldUse FTDRspQryInstrumentFieldUse[]=
{
		{ FTD_FID_RspInstrument, &(CFTDRspInstrumentField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryInstrumentStatusFieldUse[]=
{
		{ FTD_FID_QryInstrumentStatus, &(CFTDQryInstrumentStatusField::m_Describe), 1,  1  }
};

TFieldUse FTDRspQryInstrumentStatusFieldUse[]=
{
		{ FTD_FID_InstrumentStatus, &(CFTDInstrumentStatusField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQrySGDataSyncStatusFieldUse[]=
{
		{ FTD_FID_QrySGDataSyncStatus, &(CFTDQrySGDataSyncStatusField::m_Describe), 1,  1  }
};

TFieldUse FTDRspQrySGDataSyncStatusFieldUse[]=
{
		{ FTD_FID_SGDataSyncStatus, &(CFTDSGDataSyncStatusField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqQryHedgeVolumeFieldUse[]=
{
		{ FTD_FID_QryHedgeVolume, &(CFTDQryHedgeVolumeField::m_Describe), 1,  1  }
};

TFieldUse FTDRspQryHedgeVolumeFieldUse[]=
{
		{ FTD_FID_HedgeVolume, &(CFTDHedgeVolumeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqQryCreditLimitFieldUse[]=
{
		{ FTD_FID_QryCreditLimit, &(CFTDQryCreditLimitField::m_Describe), 1,  1  }
};

TFieldUse FTDRspQryCreditLimitFieldUse[]=
{
		{ FTD_FID_CreditLimit, &(CFTDCreditLimitField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqQryCombOrderFieldUse[]=
{
		{ FTD_FID_QryCombOrder, &(CFTDQryCombOrderField::m_Describe), 1,  1  }
};

TFieldUse FTDRspQryCombOrderFieldUse[]=
{
		{ FTD_FID_CombOrder, &(CFTDCombOrderField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryExecOrderFieldUse[]=
{
		{ FTD_FID_QryExecOrder, &(CFTDQryExecOrderField::m_Describe), 1,  1  }
};

TFieldUse FTDRspQryExecOrderFieldUse[]=
{
		{ FTD_FID_ExecOrder, &(CFTDExecOrderField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryMarketDataFieldUse[]=
{
		{ FTD_FID_QryMarketData, &(CFTDQryMarketDataField::m_Describe), 1,  1  }
};

TFieldUse FTDRspQryMarketDataFieldUse[]=
{
		{ FTD_FID_MarketData, &(CFTDMarketDataField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryBulletinFieldUse[]=
{
		{ FTD_FID_QryBulletin, &(CFTDQryBulletinField::m_Describe), 1,  1  }
};

TFieldUse FTDRspQryBulletinFieldUse[]=
{
		{ FTD_FID_Bulletin, &(CFTDBulletinField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqQryTopicFieldUse[]=
{
		{ FTD_FID_Dissemination, &(CFTDDisseminationField::m_Describe), 1,  1  }
};

TFieldUse FTDRspQryTopicFieldUse[]=
{
		{ FTD_FID_Dissemination, &(CFTDDisseminationField::m_Describe), 1,  1  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqQryUserSessionFieldUse[]=
{
		{ FTD_FID_QryUserSession, &(CFTDQryUserSessionField::m_Describe), 1,  1  }
};

TFieldUse FTDRspQryUserSessionFieldUse[]=
{
		{ FTD_FID_UserSession, &(CFTDUserSessionField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqQryUserFieldUse[]=
{
		{ FTD_FID_QryUser, &(CFTDQryUserField::m_Describe), 1,  1  }
};

TFieldUse FTDRspQryUserFieldUse[]=
{
		{ FTD_FID_User, &(CFTDUserField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqQryParticipantFieldUse[]=
{
		{ FTD_FID_QryParticipant, &(CFTDQryParticipantField::m_Describe), 1,  1  }
};

TFieldUse FTDRspQryParticipantFieldUse[]=
{
		{ FTD_FID_Participant, &(CFTDParticipantField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqQryMBLMarketDataFieldUse[]=
{
		{ FTD_FID_QryMBLMarketData, &(CFTDQryMBLMarketDataField::m_Describe), 1,  1  }
};

TFieldUse FTDRspQryMBLMarketDataFieldUse[]=
{
		{ FTD_FID_MBLMarketData, &(CFTDMBLMarketDataField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqQryInformationFieldUse[]=
{
		{ FTD_FID_QryInformation, &(CFTDQryInformationField::m_Describe), 1,  1  }
};

TFieldUse FTDRspQryInformationFieldUse[]=
{
		{ FTD_FID_Information, &(CFTDInformationField::m_Describe), 1,  1  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnTradeFieldUse[]=
{
		{ FTD_FID_Trade, &(CFTDTradeField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnOrderFieldUse[]=
{
		{ FTD_FID_Order, &(CFTDOrderField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnExecOrderFieldUse[]=
{
		{ FTD_FID_ExecOrder, &(CFTDExecOrderField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRtnQuoteFieldUse[]=
{
		{ FTD_FID_Quote, &(CFTDQuoteField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRtnCombOrderFieldUse[]=
{
		{ FTD_FID_CombOrder, &(CFTDCombOrderField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnInstrumentStatusFieldUse[]=
{
		{ FTD_FID_InstrumentStatus, &(CFTDInstrumentStatusField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRtnInsInstrumentFieldUse[]=
{
		{ FTD_FID_Instrument, &(CFTDInstrumentField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRtnDelInstrumentFieldUse[]=
{
		{ FTD_FID_Instrument, &(CFTDInstrumentField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRtnInsCombinationLegFieldUse[]=
{
		{ FTD_FID_CombinationLeg, &(CFTDCombinationLegField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRtnDelCombinationLegFieldUse[]=
{
		{ FTD_FID_CombinationLeg, &(CFTDCombinationLegField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRtnAliasDefineFieldUse[]=
{
		{ FTD_FID_AliasDefine, &(CFTDAliasDefineField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRtnFlowMessageCancelFieldUse[]=
{
		{ FTD_FID_FlowMessageCancel, &(CFTDFlowMessageCancelField::m_Describe), 0,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRtnBulletinFieldUse[]=
{
		{ FTD_FID_Bulletin, &(CFTDBulletinField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRtnMarketDataFieldUse[]=
{
		{ FTD_FID_MarketData, &(CFTDMarketDataField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRtnDepthMarketDataFieldUse[]=
{
		{ FTD_FID_DepthMarketData, &(CFTDDepthMarketDataField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDIntlRtnDisseminationFieldUse[]=
{
		{ FTD_FID_Dissemination, &(CFTDDisseminationField::m_Describe), 0,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDIntlRtnDepthMarketDataFieldUse[]=
{
		{ FTD_FID_MarketDataBase, &(CFTDMarketDataBaseField::m_Describe), 0,  1  }
			,
		{ FTD_FID_MarketDataStatic, &(CFTDMarketDataStaticField::m_Describe), 0,  1  }
			,
		{ FTD_FID_MarketDataLastMatch, &(CFTDMarketDataLastMatchField::m_Describe), 0,  1  }
			,
		{ FTD_FID_MarketDataBestPrice, &(CFTDMarketDataBestPriceField::m_Describe), 0,  1  }
			,
		{ FTD_FID_MarketDataBid23, &(CFTDMarketDataBid23Field::m_Describe), 0,  1  }
			,
		{ FTD_FID_MarketDataAsk23, &(CFTDMarketDataAsk23Field::m_Describe), 0,  1  }
			,
		{ FTD_FID_MarketDataBid45, &(CFTDMarketDataBid45Field::m_Describe), 0,  1  }
			,
		{ FTD_FID_MarketDataAsk45, &(CFTDMarketDataAsk45Field::m_Describe), 0,  1  }
			,
		{ FTD_FID_MarketDataUpdateTime, &(CFTDMarketDataUpdateTimeField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnAdminOrderFieldUse[]=
{
		{ FTD_FID_AdminOrder, &(CFTDAdminOrderField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDErrRtnOrderInsertFieldUse[]=
{
		{ FTD_FID_InputOrder, &(CFTDInputOrderField::m_Describe), 1,  1  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDErrRtnOrderActionFieldUse[]=
{
		{ FTD_FID_OrderAction, &(CFTDOrderActionField::m_Describe), 1,  1  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDErrRtnQuoteInsertFieldUse[]=
{
		{ FTD_FID_InputQuote, &(CFTDInputQuoteField::m_Describe), 1,  1  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDErrRtnQuoteActionFieldUse[]=
{
		{ FTD_FID_QuoteAction, &(CFTDQuoteActionField::m_Describe), 1,  1  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDErrRtnExecOrderInsertFieldUse[]=
{
		{ FTD_FID_InputExecOrder, &(CFTDInputExecOrderField::m_Describe), 1,  1  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDErrRtnExecOrderActionFieldUse[]=
{
		{ FTD_FID_ExecOrderAction, &(CFTDExecOrderActionField::m_Describe), 1,  1  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDErrAdminOrderInsertFieldUse[]=
{
		{ FTD_FID_InputAdminOrder, &(CFTDInputAdminOrderField::m_Describe), 1,  1  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDErrRtnCombOrderInsertFieldUse[]=
{
		{ FTD_FID_InputCombOrder, &(CFTDInputCombOrderField::m_Describe), 1,  1  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqQryClientPositionV1FieldUse[]=
{
		{ FTD_FID_QryClientPositionV1, &(CFTDQryClientPositionV1Field::m_Describe), 1,  1  }
};

TFieldUse FTDReqQryExchangeRateFieldUse[]=
{
		{ FTD_FID_QryExchangeRate, &(CFTDQryExchangeRateField::m_Describe), 1,  1  }
};

TFieldUse FTDRspQryExchangeRateFieldUse[]=
{
		{ FTD_FID_RspExchangeRate, &(CFTDRspExchangeRateField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDIntlLoopMeasureDataFieldUse[]=
{
		{ FTD_FID_LoopMeasure, &(CFTDLoopMeasureField::m_Describe), 1,  1  }
			,
		{ FTD_FID_NodeMeasure, &(CFTDNodeMeasureField::m_Describe), 0,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryTopCpuInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryTopCpuInfo, &(CFTDReqQryTopCpuInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryTopCpuInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryTopCpuInfo, &(CFTDRspQryTopCpuInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnTopCpuInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnTopCpuInfo, &(CFTDRtnTopCpuInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryTopMemInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryTopMemInfo, &(CFTDReqQryTopMemInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryTopMemInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryTopMemInfo, &(CFTDRspQryTopMemInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnTopMemInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnTopMemInfo, &(CFTDRtnTopMemInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryTopProcessInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryTopProcessInfo, &(CFTDReqQryTopProcessInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryTopProcessInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryTopProcessInfo, &(CFTDRspQryTopProcessInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnTopProcessInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnTopProcessInfo, &(CFTDRtnTopProcessInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryFileSystemInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryFileSystemInfo, &(CFTDReqQryFileSystemInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryFileSystemInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryFileSystemInfo, &(CFTDRspQryFileSystemInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnFileSystemInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnFileSystemInfo, &(CFTDRtnFileSystemInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetworkInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetworkInfo, &(CFTDReqQryNetworkInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetworkInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetworkInfo, &(CFTDRspQryNetworkInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetworkInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnNetworkInfo, &(CFTDRtnNetworkInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryHostEnvTopicFieldUse[]=
{
		{ FTD_FID_ReqQryHostEnv, &(CFTDReqQryHostEnvField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryClientLoginTopicFieldUse[]=
{
		{ FTD_FID_ReqQryClientLogin, &(CFTDReqQryClientLoginField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryClientLoginTopicFieldUse[]=
{
		{ FTD_FID_RspQryClientLogin, &(CFTDRspQryClientLoginField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqQryMonitorObjectTopicFieldUse[]=
{
		{ FTD_FID_ReqQryMonitorObject, &(CFTDReqQryMonitorObjectField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryMonitorObjectTopicFieldUse[]=
{
		{ FTD_FID_RspQryMonitorObject, &(CFTDRspQryMonitorObjectField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnMonitorObjectTopicFieldUse[]=
{
		{ FTD_FID_RtnMonitorObject, &(CFTDRtnMonitorObjectField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryObjectRationalTopicFieldUse[]=
{
		{ FTD_FID_ReqQryObjectRational, &(CFTDReqQryObjectRationalField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryObjectRationalTopicFieldUse[]=
{
		{ FTD_FID_RspQryObjectRational, &(CFTDRspQryObjectRationalField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnObjectRationalTopicFieldUse[]=
{
		{ FTD_FID_RtnObjectRational, &(CFTDRtnObjectRationalField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQrySyslogInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQrySyslogInfo, &(CFTDReqQrySyslogInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQrySyslogInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQrySyslogInfo, &(CFTDRspQrySyslogInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnSyslogInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnSyslogInfo, &(CFTDRtnSyslogInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQrySubscriberTopicFieldUse[]=
{
		{ FTD_FID_ReqQrySubscriber, &(CFTDReqQrySubscriberField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQrySubscriberTopicFieldUse[]=
{
		{ FTD_FID_RspQrySubscriber, &(CFTDRspQrySubscriberField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqQryOidRelationTopicFieldUse[]=
{
		{ FTD_FID_ReqQryOidRelation, &(CFTDReqQryOidRelationField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryOidRelationTopicFieldUse[]=
{
		{ FTD_FID_RspQryOidRelation, &(CFTDRspQryOidRelationField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnOidRelationTopicFieldUse[]=
{
		{ FTD_FID_RtnOidRelation, &(CFTDRtnOidRelationField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryUserInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryUserInfo, &(CFTDReqQryUserInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryUserInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryUserInfo, &(CFTDRspQryUserInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnUserInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnUserInfo, &(CFTDRtnUserInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryOnlineUserInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryOnlineUserInfo, &(CFTDReqQryOnlineUserInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryOnlineUserInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryOnlineUserInfo, &(CFTDRspQryOnlineUserInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnOnlineUserInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnOnlineUserInfo, &(CFTDRtnOnlineUserInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryWarningEventTopicFieldUse[]=
{
		{ FTD_FID_ReqQryWarningEvent, &(CFTDReqQryWarningEventField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryWarningEventTopicFieldUse[]=
{
		{ FTD_FID_RspQryWarningEvent, &(CFTDRspQryWarningEventField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnWarningEventTopicFieldUse[]=
{
		{ FTD_FID_RtnWarningEvent, &(CFTDRtnWarningEventField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryCPUUsageTopicFieldUse[]=
{
		{ FTD_FID_ReqQryCPUUsage, &(CFTDReqQryCPUUsageField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryCPUUsageTopicFieldUse[]=
{
		{ FTD_FID_RspQryCPUUsage, &(CFTDRspQryCPUUsageField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnCPUUsageTopicFieldUse[]=
{
		{ FTD_FID_RtnCPUUsage, &(CFTDRtnCPUUsageField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryMemoryUsageTopicFieldUse[]=
{
		{ FTD_FID_ReqQryMemoryUsage, &(CFTDReqQryMemoryUsageField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryMemoryUsageTopicFieldUse[]=
{
		{ FTD_FID_RspQryMemoryUsage, &(CFTDRspQryMemoryUsageField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnMemoryUsageTopicFieldUse[]=
{
		{ FTD_FID_RtnMemoryUsage, &(CFTDRtnMemoryUsageField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryDiskUsageTopicFieldUse[]=
{
		{ FTD_FID_ReqQryDiskUsage, &(CFTDReqQryDiskUsageField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryDiskUsageTopicFieldUse[]=
{
		{ FTD_FID_RspQryDiskUsage, &(CFTDRspQryDiskUsageField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnDiskUsageTopicFieldUse[]=
{
		{ FTD_FID_RtnDiskUsage, &(CFTDRtnDiskUsageField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryObjectAttrTopicFieldUse[]=
{
		{ FTD_FID_ReqQryObjectAttr, &(CFTDReqQryObjectAttrField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryObjectAttrTopicFieldUse[]=
{
		{ FTD_FID_RspQryObjectAttr, &(CFTDRspQryObjectAttrField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnObjectAttrTopicFieldUse[]=
{
		{ FTD_FID_RtnObjectAttr, &(CFTDRtnObjectAttrField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryKeyFileInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryKeyFileInfo, &(CFTDReqQryKeyFileInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryHostMonitorCfgTopicFieldUse[]=
{
		{ FTD_FID_ReqQryHostMonitorCfg, &(CFTDReqQryHostMonitorCfgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryAppMonitorCfgTopicFieldUse[]=
{
		{ FTD_FID_ReqQryAppMonitorCfg, &(CFTDReqQryAppMonitorCfgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryHostConfigTopicFieldUse[]=
{
		{ FTD_FID_ReqQryHostConfig, &(CFTDReqQryHostConfigField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryInvalidateOrderTopicFieldUse[]=
{
		{ FTD_FID_ReqQryInvalidateOrder, &(CFTDReqQryInvalidateOrderField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryInvalidateOrderTopicFieldUse[]=
{
		{ FTD_FID_RspQryInvalidateOrder, &(CFTDRspQryInvalidateOrderField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnInvalidateOrderTopicFieldUse[]=
{
		{ FTD_FID_RtnInvalidateOrder, &(CFTDRtnInvalidateOrderField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryOrderStatusTopicFieldUse[]=
{
		{ FTD_FID_ReqQryOrderStatus, &(CFTDReqQryOrderStatusField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryOrderStatusTopicFieldUse[]=
{
		{ FTD_FID_RspQryOrderStatus, &(CFTDRspQryOrderStatusField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnOrderStatusTopicFieldUse[]=
{
		{ FTD_FID_RtnOrderStatus, &(CFTDRtnOrderStatusField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryBargainOrderTopicFieldUse[]=
{
		{ FTD_FID_ReqQryBargainOrder, &(CFTDReqQryBargainOrderField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryBargainOrderTopicFieldUse[]=
{
		{ FTD_FID_RspQryBargainOrder, &(CFTDRspQryBargainOrderField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnBargainOrderTopicFieldUse[]=
{
		{ FTD_FID_RtnBargainOrder, &(CFTDRtnBargainOrderField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryInstPropertyTopicFieldUse[]=
{
		{ FTD_FID_ReqQryInstProperty, &(CFTDReqQryInstPropertyField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryInstPropertyTopicFieldUse[]=
{
		{ FTD_FID_RspQryInstProperty, &(CFTDRspQryInstPropertyField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnInstPropertyTopicFieldUse[]=
{
		{ FTD_FID_RtnInstProperty, &(CFTDRtnInstPropertyField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryMarginRateTopicFieldUse[]=
{
		{ FTD_FID_ReqQryMarginRate, &(CFTDReqQryMarginRateField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryMarginRateTopicFieldUse[]=
{
		{ FTD_FID_RspQryMarginRate, &(CFTDRspQryMarginRateField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnMarginRateTopicFieldUse[]=
{
		{ FTD_FID_RtnMarginRate, &(CFTDRtnMarginRateField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryPriceLimitTopicFieldUse[]=
{
		{ FTD_FID_ReqQryPriceLimit, &(CFTDReqQryPriceLimitField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryPriceLimitTopicFieldUse[]=
{
		{ FTD_FID_RspQryPriceLimit, &(CFTDRspQryPriceLimitField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnPriceLimitTopicFieldUse[]=
{
		{ FTD_FID_RtnPriceLimit, &(CFTDRtnPriceLimitField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryPartPosiLimitTopicFieldUse[]=
{
		{ FTD_FID_ReqQryPartPosiLimit, &(CFTDReqQryPartPosiLimitField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryPartPosiLimitTopicFieldUse[]=
{
		{ FTD_FID_RspQryPartPosiLimit, &(CFTDRspQryPartPosiLimitField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnPartPosiLimitTopicFieldUse[]=
{
		{ FTD_FID_RtnPartPosiLimit, &(CFTDRtnPartPosiLimitField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryClientPosiLimitTopicFieldUse[]=
{
		{ FTD_FID_ReqQryClientPosiLimit, &(CFTDReqQryClientPosiLimitField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryClientPosiLimitTopicFieldUse[]=
{
		{ FTD_FID_RspQryClientPosiLimit, &(CFTDRspQryClientPosiLimitField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnClientPosiLimitTopicFieldUse[]=
{
		{ FTD_FID_RtnClientPosiLimit, &(CFTDRtnClientPosiLimitField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQrySpecialPosiLimitTopicFieldUse[]=
{
		{ FTD_FID_ReqQrySpecialPosiLimit, &(CFTDReqQrySpecialPosiLimitField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQrySpecialPosiLimitTopicFieldUse[]=
{
		{ FTD_FID_RspQrySpecialPosiLimit, &(CFTDRspQrySpecialPosiLimitField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnSpecialPosiLimitTopicFieldUse[]=
{
		{ FTD_FID_RtnSpecialPosiLimit, &(CFTDRtnSpecialPosiLimitField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryTransactionChgTopicFieldUse[]=
{
		{ FTD_FID_ReqQryTransactionChg, &(CFTDReqQryTransactionChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryTransactionChgTopicFieldUse[]=
{
		{ FTD_FID_RspQryTransactionChg, &(CFTDRspQryTransactionChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnTransactionChgTopicFieldUse[]=
{
		{ FTD_FID_RtnTransactionChg, &(CFTDRtnTransactionChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryClientChgTopicFieldUse[]=
{
		{ FTD_FID_ReqQryClientChg, &(CFTDReqQryClientChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryClientChgTopicFieldUse[]=
{
		{ FTD_FID_RspQryClientChg, &(CFTDRspQryClientChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnClientChgTopicFieldUse[]=
{
		{ FTD_FID_RtnClientChg, &(CFTDRtnClientChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryPartClientChgTopicFieldUse[]=
{
		{ FTD_FID_ReqQryPartClientChg, &(CFTDReqQryPartClientChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryPartClientChgTopicFieldUse[]=
{
		{ FTD_FID_RspQryPartClientChg, &(CFTDRspQryPartClientChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnPartClientChgTopicFieldUse[]=
{
		{ FTD_FID_RtnPartClientChg, &(CFTDRtnPartClientChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryPosiLimitChgTopicFieldUse[]=
{
		{ FTD_FID_ReqQryPosiLimitChg, &(CFTDReqQryPosiLimitChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryPosiLimitChgTopicFieldUse[]=
{
		{ FTD_FID_RspQryPosiLimitChg, &(CFTDRspQryPosiLimitChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnPosiLimitChgTopicFieldUse[]=
{
		{ FTD_FID_RtnPosiLimitChg, &(CFTDRtnPosiLimitChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryHedgeDetailChgTopicFieldUse[]=
{
		{ FTD_FID_ReqQryHedgeDetailChg, &(CFTDReqQryHedgeDetailChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryHedgeDetailChgTopicFieldUse[]=
{
		{ FTD_FID_RspQryHedgeDetailChg, &(CFTDRspQryHedgeDetailChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnHedgeDetailChgTopicFieldUse[]=
{
		{ FTD_FID_RtnHedgeDetailChg, &(CFTDRtnHedgeDetailChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryParticipantChgTopicFieldUse[]=
{
		{ FTD_FID_ReqQryParticipantChg, &(CFTDReqQryParticipantChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryParticipantChgTopicFieldUse[]=
{
		{ FTD_FID_RspQryParticipantChg, &(CFTDRspQryParticipantChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnParticipantChgTopicFieldUse[]=
{
		{ FTD_FID_RtnParticipantChg, &(CFTDRtnParticipantChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryMarginRateChgTopicFieldUse[]=
{
		{ FTD_FID_ReqQryMarginRateChg, &(CFTDReqQryMarginRateChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryMarginRateChgTopicFieldUse[]=
{
		{ FTD_FID_RspQryMarginRateChg, &(CFTDRspQryMarginRateChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnMarginRateChgTopicFieldUse[]=
{
		{ FTD_FID_RtnMarginRateChg, &(CFTDRtnMarginRateChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryUserIpChgTopicFieldUse[]=
{
		{ FTD_FID_ReqQryUserIpChg, &(CFTDReqQryUserIpChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryUserIpChgTopicFieldUse[]=
{
		{ FTD_FID_RspQryUserIpChg, &(CFTDRspQryUserIpChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnUserIpChgTopicFieldUse[]=
{
		{ FTD_FID_RtnUserIpChg, &(CFTDRtnUserIpChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryClientPosiLimitChgTopicFieldUse[]=
{
		{ FTD_FID_ReqQryClientPosiLimitChg, &(CFTDReqQryClientPosiLimitChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryClientPosiLimitChgTopicFieldUse[]=
{
		{ FTD_FID_RspQryClientPosiLimitChg, &(CFTDRspQryClientPosiLimitChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnClientPosiLimitChgTopicFieldUse[]=
{
		{ FTD_FID_RtnClientPosiLimitChg, &(CFTDRtnClientPosiLimitChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQrySpecPosiLimitChgTopicFieldUse[]=
{
		{ FTD_FID_ReqQrySpecPosiLimitChg, &(CFTDReqQrySpecPosiLimitChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQrySpecPosiLimitChgTopicFieldUse[]=
{
		{ FTD_FID_RspQrySpecPosiLimitChg, &(CFTDRspQrySpecPosiLimitChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnSpecPosiLimitChgTopicFieldUse[]=
{
		{ FTD_FID_RtnSpecPosiLimitChg, &(CFTDRtnSpecPosiLimitChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryHistoryObjectAttrTopicFieldUse[]=
{
		{ FTD_FID_ReqQryHistoryObjectAttr, &(CFTDReqQryHistoryObjectAttrField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryHistoryObjectAttrTopicFieldUse[]=
{
		{ FTD_FID_RspQryHistoryObjectAttr, &(CFTDRspQryHistoryObjectAttrField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnHistoryObjectAttrTopicFieldUse[]=
{
		{ FTD_FID_RtnHistoryObjectAttr, &(CFTDRtnHistoryObjectAttrField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryFrontInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryFrontInfo, &(CFTDReqQryFrontInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryFrontInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryFrontInfo, &(CFTDRspQryFrontInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnFrontInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnFrontInfo, &(CFTDRtnFrontInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQrySysUserLoginTopicFieldUse[]=
{
		{ FTD_FID_ReqQrySysUserLogin, &(CFTDReqQrySysUserLoginField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQrySysUserLoginTopicFieldUse[]=
{
		{ FTD_FID_RspQrySysUserLogin, &(CFTDRspQrySysUserLoginField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqQrySysUserLogoutTopicFieldUse[]=
{
		{ FTD_FID_ReqQrySysUserLogout, &(CFTDReqQrySysUserLogoutField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQrySysUserLogoutTopicFieldUse[]=
{
		{ FTD_FID_RspQrySysUserLogout, &(CFTDRspQrySysUserLogoutField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqQrySysUserPasswordUpdateTopicFieldUse[]=
{
		{ FTD_FID_ReqQrySysUserPasswordUpdate, &(CFTDReqQrySysUserPasswordUpdateField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQrySysUserPasswordUpdateTopicFieldUse[]=
{
		{ FTD_FID_RspQrySysUserPasswordUpdate, &(CFTDRspQrySysUserPasswordUpdateField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqQrySysUserRegisterTopicFieldUse[]=
{
		{ FTD_FID_ReqQrySysUserRegister, &(CFTDReqQrySysUserRegisterField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQrySysUserRegisterTopicFieldUse[]=
{
		{ FTD_FID_RspQrySysUserRegister, &(CFTDRspQrySysUserRegisterField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqQrySysUserDeleteTopicFieldUse[]=
{
		{ FTD_FID_ReqQrySysUserDelete, &(CFTDReqQrySysUserDeleteField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQrySysUserDeleteTopicFieldUse[]=
{
		{ FTD_FID_RspQrySysUserDelete, &(CFTDRspQrySysUserDeleteField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRspQryParticipantInitTopicFieldUse[]=
{
		{ FTD_FID_RspQryParticipantInit, &(CFTDRspQryParticipantInitField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnParticipantInitTopicFieldUse[]=
{
		{ FTD_FID_RtnParticipantInit, &(CFTDRtnParticipantInitField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryUserInitTopicFieldUse[]=
{
		{ FTD_FID_RspQryUserInit, &(CFTDRspQryUserInitField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnUserInitTopicFieldUse[]=
{
		{ FTD_FID_RtnUserInit, &(CFTDRtnUserInitField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryClientInitTopicFieldUse[]=
{
		{ FTD_FID_RspQryClientInit, &(CFTDRspQryClientInitField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnClientInitTopicFieldUse[]=
{
		{ FTD_FID_RtnClientInit, &(CFTDRtnClientInitField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryTradeLogTopicFieldUse[]=
{
		{ FTD_FID_ReqQryTradeLog, &(CFTDReqQryTradeLogField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryTradeLogTopicFieldUse[]=
{
		{ FTD_FID_RspQryTradeLog, &(CFTDRspQryTradeLogField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnTradeLogTopicFieldUse[]=
{
		{ FTD_FID_RtnTradeLog, &(CFTDRtnTradeLogField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryWarningEventUpdateTopicFieldUse[]=
{
		{ FTD_FID_ReqQryWarningEventUpdate, &(CFTDReqQryWarningEventUpdateField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryTradeUserLoginInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryTradeUserLoginInfo, &(CFTDReqQryTradeUserLoginInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryTradeUserLoginInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryTradeUserLoginInfo, &(CFTDRspQryTradeUserLoginInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnTradeUserLoginInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnTradeUserLoginInfo, &(CFTDRtnTradeUserLoginInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryPartTradeTopicFieldUse[]=
{
		{ FTD_FID_ReqQryPartTrade, &(CFTDReqQryPartTradeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryPartTradeTopicFieldUse[]=
{
		{ FTD_FID_RspQryPartTrade, &(CFTDRspQryPartTradeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqQryTradepeakTopicFieldUse[]=
{
		{ FTD_FID_ReqQryTradepeak, &(CFTDReqQryTradepeakField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryTradepeakTopicFieldUse[]=
{
		{ FTD_FID_RspQryTradepeak, &(CFTDRspQryTradepeakField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnUpdateSysConfigTopicFieldUse[]=
{
		{ FTD_FID_RtnUpdateSysConfig, &(CFTDRtnUpdateSysConfigField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRtnSysUserFieldUse[]=
{
		{ FTD_FID_RtnSysUser, &(CFTDRtnSysUserField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRtnPriceLimitChgTopicFieldUse[]=
{
		{ FTD_FID_RtnPriceLimitChg, &(CFTDRtnPriceLimitChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryParticipantInitTopicFieldUse[]=
{
		{ FTD_FID_ReqQryParticipantInit, &(CFTDReqQryParticipantInitField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryUserInitTopicFieldUse[]=
{
		{ FTD_FID_ReqQryUserInit, &(CFTDReqQryUserInitField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryHistoryCpuInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryHistoryCpuInfo, &(CFTDReqQryHistoryCpuInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryHistoryCpuInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryHistoryCpuInfo, &(CFTDRspQryHistoryCpuInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqQryHistoryMemInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryHistoryMemInfo, &(CFTDReqQryHistoryMemInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryHistoryMemInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryHistoryMemInfo, &(CFTDRspQryHistoryMemInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqQryHistoryNetworkInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryHistoryNetworkInfo, &(CFTDReqQryHistoryNetworkInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryHistoryNetworkInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryHistoryNetworkInfo, &(CFTDRspQryHistoryNetworkInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRspQryHostConfigFieldUse[]=
{
		{ FTD_FID_RspQryHostConfig, &(CFTDRspQryHostConfigField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryMonitorOnlineUserFieldUse[]=
{
		{ FTD_FID_ReqQryMonitorOnlineUser, &(CFTDReqQryMonitorOnlineUserField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryMonitorOnlineUserFieldUse[]=
{
		{ FTD_FID_RspQryMonitorOnlineUser, &(CFTDRspQryMonitorOnlineUserField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqQryFrontStatFieldUse[]=
{
		{ FTD_FID_ReqQryFrontStat, &(CFTDReqQryFrontStatField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryFrontStatFieldUse[]=
{
		{ FTD_FID_RspQryFrontStat, &(CFTDRspQryFrontStatField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnSysTimeSyncTopicFieldUse[]=
{
		{ FTD_FID_RtnSysTimeSync, &(CFTDRtnSysTimeSyncField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRtnDataCenterChgTopicFieldUse[]=
{
		{ FTD_FID_RtnDataCenterChg, &(CFTDRtnDataCenterChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryHistoryTradePeakTopicFieldUse[]=
{
		{ FTD_FID_ReqQryHistoryTradePeak, &(CFTDReqQryHistoryTradePeakField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryHistoryTradePeakTopicFieldUse[]=
{
		{ FTD_FID_RspQryHistoryTradePeak, &(CFTDRspQryHistoryTradePeakField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnHistoryTradePeakTopicFieldUse[]=
{
		{ FTD_FID_RtnHistoryTradePeak, &(CFTDRtnHistoryTradePeakField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQrySyslogEventTopicFieldUse[]=
{
		{ FTD_FID_ReqQrySyslogEvent, &(CFTDReqQrySyslogEventField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQrySyslogEventTopicFieldUse[]=
{
		{ FTD_FID_RspQrySyslogEvent, &(CFTDRspQrySyslogEventField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnSyslogEventTopicFieldUse[]=
{
		{ FTD_FID_RtnSyslogEvent, &(CFTDRtnSyslogEventField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQrySyslogEventSubcriberTopicFieldUse[]=
{
		{ FTD_FID_ReqQrySyslogEventSubcriber, &(CFTDReqQrySyslogEventSubcriberField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryTradeDayChangeTopicFieldUse[]=
{
		{ FTD_FID_ReqQryTradeDayChange, &(CFTDReqQryTradeDayChangeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryTradeDayChangeTopicFieldUse[]=
{
		{ FTD_FID_RspQryTradeDayChange, &(CFTDRspQryTradeDayChangeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqQryTomcatInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryTomcatInfo, &(CFTDReqQryTomcatInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryWebAppInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryWebAppInfo, &(CFTDRspQryWebAppInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnWebAppInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnWebAppInfo, &(CFTDRtnWebAppInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryServletInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryServletInfo, &(CFTDRspQryServletInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnServletInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnServletInfo, &(CFTDRtnServletInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryFileInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryFileInfo, &(CFTDRspQryFileInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnFileInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnFileInfo, &(CFTDRtnFileInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQrySessionInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQrySessionInfo, &(CFTDRspQrySessionInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnSessionInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnSessionInfo, &(CFTDRtnSessionInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryJDBCInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryJDBCInfo, &(CFTDRspQryJDBCInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnJDBCInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnJDBCInfo, &(CFTDRtnJDBCInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryThreadInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryThreadInfo, &(CFTDRspQryThreadInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnThreadInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnThreadInfo, &(CFTDRtnThreadInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryVMInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryVMInfo, &(CFTDReqQryVMInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryVMInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryVMInfo, &(CFTDRspQryVMInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnVMInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnVMInfo, &(CFTDRtnVMInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryPropertyInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryPropertyInfo, &(CFTDReqQryPropertyInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryPropertyInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryPropertyInfo, &(CFTDRspQryPropertyInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnPropertyInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnPropertyInfo, &(CFTDRtnPropertyInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryMemPoolInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryMemPoolInfo, &(CFTDReqQryMemPoolInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryMemPoolInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryMemPoolInfo, &(CFTDRspQryMemPoolInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnMemPoolInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnMemPoolInfo, &(CFTDRtnMemPoolInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryFileContentInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryFileContentInfo, &(CFTDReqQryFileContentInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryFileContentInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryFileContentInfo, &(CFTDRspQryFileContentInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnFileContentInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnFileContentInfo, &(CFTDRtnFileContentInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryConnectionInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryConnectionInfo, &(CFTDReqQryConnectionInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryConnectionInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryConnectionInfo, &(CFTDRspQryConnectionInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnConnectionInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnConnectionInfo, &(CFTDRtnConnectionInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryConnectorInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryConnectorInfo, &(CFTDReqQryConnectorInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryConnectorInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryConnectorInfo, &(CFTDRspQryConnectorInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnConnectorInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnConnectorInfo, &(CFTDRtnConnectorInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryDBQueryTopicFieldUse[]=
{
		{ FTD_FID_ReqQryDBQuery, &(CFTDReqQryDBQueryField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryDBQueryTopicFieldUse[]=
{
		{ FTD_FID_RspQryDBQuery, &(CFTDRspQryDBQueryField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnDBQueryTopicFieldUse[]=
{
		{ FTD_FID_RtnDBQuery, &(CFTDRtnDBQueryField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryGeneralFieldTopicFieldUse[]=
{
		{ FTD_FID_SysGeneralField, &(CFTDSysGeneralFieldField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnGeneralFieldTopicFieldUse[]=
{
		{ FTD_FID_SysGeneralField, &(CFTDSysGeneralFieldField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryGetFileTopicFieldUse[]=
{
		{ FTD_FID_ReqQryGetFile, &(CFTDReqQryGetFileField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryGetFileTopicFieldUse[]=
{
		{ FTD_FID_RspQryGetFile, &(CFTDRspQryGetFileField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqQrySyslogEventUpdateTopicFieldUse[]=
{
		{ FTD_FID_ReqQrySyslogEventUpdate, &(CFTDReqQrySyslogEventUpdateField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryWarningQueryTopicFieldUse[]=
{
		{ FTD_FID_ReqQryWarningQuery, &(CFTDReqQryWarningQueryField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryWarningQueryTopicFieldUse[]=
{
		{ FTD_FID_RspQryWarningQuery, &(CFTDRspQryWarningQueryField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnWarningQueryTopicFieldUse[]=
{
		{ FTD_FID_RtnWarningQuery, &(CFTDRtnWarningQueryField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryWebVisitTopicFieldUse[]=
{
		{ FTD_FID_ReqQryWebVisit, &(CFTDReqQryWebVisitField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRtnHostConfigFieldUse[]=
{
		{ FTD_FID_RtnHostConfig, &(CFTDRtnHostConfigField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryWarningActiveChangeFieldUse[]=
{
		{ FTD_FID_ReqQryWarningActiveChange, &(CFTDReqQryWarningActiveChangeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryWarningActiveChangeFieldUse[]=
{
		{ FTD_FID_RspQryWarningActiveChange, &(CFTDRspQryWarningActiveChangeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRtnWarningActiveChangeFieldUse[]=
{
		{ FTD_FID_RtnWarningActiveChange, &(CFTDRtnWarningActiveChangeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryGeneralOperateTopicFieldUse[]=
{
		{ FTD_FID_ReqQryGeneralOperate, &(CFTDReqQryGeneralOperateField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryGeneralOperateTopicFieldUse[]=
{
		{ FTD_FID_RspQryGeneralOperate, &(CFTDRspQryGeneralOperateField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnGeneralOperateTopicFieldUse[]=
{
		{ FTD_FID_RtnGeneralOperate, &(CFTDRtnGeneralOperateField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetDeviceLinkedTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetDeviceLinked, &(CFTDReqQryNetDeviceLinkedField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetDeviceLinkedTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetDeviceLinked, &(CFTDRspQryNetDeviceLinkedField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetDeviceLinkedTopicFieldUse[]=
{
		{ FTD_FID_RtnNetDeviceLinked, &(CFTDRtnNetDeviceLinkedField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryTradeUserLoginStatTopicFieldUse[]=
{
		{ FTD_FID_ReqQryTradeUserLoginStat, &(CFTDReqQryTradeUserLoginStatField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryTradeUserLoginStatTopicFieldUse[]=
{
		{ FTD_FID_RspQryTradeUserLoginStat, &(CFTDRspQryTradeUserLoginStatField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqQryTradeFrontOrderRttStatTopicFieldUse[]=
{
		{ FTD_FID_ReqQryTradeFrontOrderRttStat, &(CFTDReqQryTradeFrontOrderRttStatField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryTradeFrontOrderRttStatTopicFieldUse[]=
{
		{ FTD_FID_RspQryTradeFrontOrderRttStat, &(CFTDRspQryTradeFrontOrderRttStatField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnTradeFrontOrderRttStatTopicFieldUse[]=
{
		{ FTD_FID_RtnTradeFrontOrderRttStat, &(CFTDRtnTradeFrontOrderRttStatField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryParticTradeOrderStatesTopicFieldUse[]=
{
		{ FTD_FID_ReqQryParticTradeOrderStates, &(CFTDReqQryParticTradeOrderStatesField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryParticTradeOrderStatesTopicFieldUse[]=
{
		{ FTD_FID_RspQryParticTradeOrderStates, &(CFTDRspQryParticTradeOrderStatesField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnParticTradeOrderStatesTopicFieldUse[]=
{
		{ FTD_FID_RtnParticTradeOrderStates, &(CFTDRtnParticTradeOrderStatesField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryRouterInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryRouterInfo, &(CFTDReqQryRouterInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryRouterInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryRouterInfo, &(CFTDRspQryRouterInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnRouterInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnRouterInfo, &(CFTDRtnRouterInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryDiskIOTopicFieldUse[]=
{
		{ FTD_FID_ReqQryDiskIO, &(CFTDReqQryDiskIOField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryDiskIOTopicFieldUse[]=
{
		{ FTD_FID_RspQryDiskIO, &(CFTDRspQryDiskIOField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnDiskIOTopicFieldUse[]=
{
		{ FTD_FID_RtnDiskIO, &(CFTDRtnDiskIOField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryStatInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryStatInfo, &(CFTDReqQryStatInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryStatInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryStatInfo, &(CFTDRspQryStatInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnStatInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnStatInfo, &(CFTDRtnStatInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryTradeOrderRttCutLineTopicFieldUse[]=
{
		{ FTD_FID_ReqQryTradeOrderRttCutLine, &(CFTDReqQryTradeOrderRttCutLineField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryTradeOrderRttCutLineTopicFieldUse[]=
{
		{ FTD_FID_RspQryTradeOrderRttCutLine, &(CFTDRspQryTradeOrderRttCutLineField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnTradeOrderRttCutLineTopicFieldUse[]=
{
		{ FTD_FID_RtnTradeOrderRttCutLine, &(CFTDRtnTradeOrderRttCutLineField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryClientInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryClientInfo, &(CFTDReqQryClientInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryClientInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryClientInfo, &(CFTDRspQryClientInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnClientInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnClientInfo, &(CFTDRtnClientInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryEventDescriptionTopicFieldUse[]=
{
		{ FTD_FID_ReqQryEventDescription, &(CFTDReqQryEventDescriptionField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryEventDescriptionTopicFieldUse[]=
{
		{ FTD_FID_RspQryEventDescription, &(CFTDRspQryEventDescriptionField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnEventDescriptionTopicFieldUse[]=
{
		{ FTD_FID_RtnEventDescription, &(CFTDRtnEventDescriptionField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryFrontUniqueIDTopicFieldUse[]=
{
		{ FTD_FID_ReqQryFrontUniqueID, &(CFTDReqQryFrontUniqueIDField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryFrontUniqueIDTopicFieldUse[]=
{
		{ FTD_FID_RspQryFrontUniqueID, &(CFTDRspQryFrontUniqueIDField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnFrontUniqueIDTopicFieldUse[]=
{
		{ FTD_FID_RtnFrontUniqueID, &(CFTDRtnFrontUniqueIDField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetPartyLinkAddrChangeTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetPartyLinkAddrChange, &(CFTDReqQryNetPartyLinkAddrChangeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetPartyLinkAddrChangeTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetPartyLinkAddrChange, &(CFTDRspQryNetPartyLinkAddrChangeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetPartyLinkAddrChangeTopicFieldUse[]=
{
		{ FTD_FID_RtnNetPartyLinkAddrChange, &(CFTDRtnNetPartyLinkAddrChangeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetDelPartyLinkInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetDelPartyLinkInfo, &(CFTDReqQryNetDelPartyLinkInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetDelPartyLinkInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetDelPartyLinkInfo, &(CFTDRspQryNetDelPartyLinkInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetDelPartyLinkInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnNetDelPartyLinkInfo, &(CFTDRtnNetDelPartyLinkInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryPerformanceTopTopicFieldUse[]=
{
		{ FTD_FID_ReqQryPerformanceTop, &(CFTDReqQryPerformanceTopField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryPerformanceTopTopicFieldUse[]=
{
		{ FTD_FID_RspQryPerformanceTop, &(CFTDRspQryPerformanceTopField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnPerformanceTopTopicFieldUse[]=
{
		{ FTD_FID_RtnPerformanceTop, &(CFTDRtnPerformanceTopField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryInstrumentStatusTopicFieldUse[]=
{
		{ FTD_FID_ReqQryInstrumentStatus, &(CFTDReqQryInstrumentStatusField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryInstrumentStatusTopicFieldUse[]=
{
		{ FTD_FID_RspQryInstrumentStatus, &(CFTDRspQryInstrumentStatusField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnInstrumentStatusTopicFieldUse[]=
{
		{ FTD_FID_RtnInstrumentStatus, &(CFTDRtnInstrumentStatusField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryCurrTradingSegmentAttrTopicFieldUse[]=
{
		{ FTD_FID_ReqQryCurrTradingSegmentAttr, &(CFTDReqQryCurrTradingSegmentAttrField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryCurrTradingSegmentAttrTopicFieldUse[]=
{
		{ FTD_FID_RspQryCurrTradingSegmentAttr, &(CFTDRspQryCurrTradingSegmentAttrField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnCurrTradingSegmentAttrTopicFieldUse[]=
{
		{ FTD_FID_RtnCurrTradingSegmentAttr, &(CFTDRtnCurrTradingSegmentAttrField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryRealTimeNetObjectAttrTopicFieldUse[]=
{
		{ FTD_FID_ReqQryRealTimeNetObjectAttr, &(CFTDReqQryRealTimeNetObjectAttrField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetAreaTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetArea, &(CFTDReqQryNetAreaField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetAreaTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetArea, &(CFTDRspQryNetAreaField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetAreaTopicFieldUse[]=
{
		{ FTD_FID_RtnNetArea, &(CFTDRtnNetAreaField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetSubAreaTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetSubArea, &(CFTDReqQryNetSubAreaField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetSubAreaTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetSubArea, &(CFTDRspQryNetSubAreaField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetSubAreaTopicFieldUse[]=
{
		{ FTD_FID_RtnNetSubArea, &(CFTDRtnNetSubAreaField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetSubAreaIPTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetSubAreaIP, &(CFTDReqQryNetSubAreaIPField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetSubAreaIPTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetSubAreaIP, &(CFTDRspQryNetSubAreaIPField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetSubAreaIPTopicFieldUse[]=
{
		{ FTD_FID_RtnNetSubAreaIP, &(CFTDRtnNetSubAreaIPField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetDeviceDetectTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetDeviceDetect, &(CFTDReqQryNetDeviceDetectField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetDeviceRequestTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetDeviceRequest, &(CFTDReqQryNetDeviceRequestField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetDeviceTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetDevice, &(CFTDRspQryNetDeviceField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetDeviceTopicFieldUse[]=
{
		{ FTD_FID_RtnNetDevice, &(CFTDRtnNetDeviceField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetDeviceDetectTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetDeviceDetect, &(CFTDRspQryNetDeviceDetectField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDReqQryNetBuildingTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetBuilding, &(CFTDReqQryNetBuildingField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetBuildingTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetBuilding, &(CFTDRspQryNetBuildingField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetBuildingTopicFieldUse[]=
{
		{ FTD_FID_RtnNetBuilding, &(CFTDRtnNetBuildingField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetRoomTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetRoom, &(CFTDReqQryNetRoomField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetRoomTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetRoom, &(CFTDRspQryNetRoomField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetRoomTopicFieldUse[]=
{
		{ FTD_FID_RtnNetRoom, &(CFTDRtnNetRoomField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetCabinetsTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetCabinets, &(CFTDReqQryNetCabinetsField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetCabinetsTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetCabinets, &(CFTDRspQryNetCabinetsField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetCabinetsTopicFieldUse[]=
{
		{ FTD_FID_RtnNetCabinets, &(CFTDRtnNetCabinetsField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetOIDTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetOID, &(CFTDReqQryNetOIDField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetOIDTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetOID, &(CFTDRspQryNetOIDField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetOIDTopicFieldUse[]=
{
		{ FTD_FID_RtnNetOID, &(CFTDRtnNetOIDField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetTimePolicyTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetTimePolicy, &(CFTDReqQryNetTimePolicyField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetTimePolicyTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetTimePolicy, &(CFTDRspQryNetTimePolicyField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetTimePolicyTopicFieldUse[]=
{
		{ FTD_FID_RtnNetTimePolicy, &(CFTDRtnNetTimePolicyField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetGatherTaskTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetGatherTask, &(CFTDReqQryNetGatherTaskField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetGatherTaskTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetGatherTask, &(CFTDRspQryNetGatherTaskField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetGatherTaskTopicFieldUse[]=
{
		{ FTD_FID_RtnNetGatherTask, &(CFTDRtnNetGatherTaskField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetDeviceChgTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetDeviceChg, &(CFTDReqQryNetDeviceChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetDeviceChgTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetDeviceChg, &(CFTDRspQryNetDeviceChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetDeviceChgTopicFieldUse[]=
{
		{ FTD_FID_RtnNetDeviceChg, &(CFTDRtnNetDeviceChgField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetDeviceTypeTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetDeviceType, &(CFTDReqQryNetDeviceTypeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetDeviceTypeTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetDeviceType, &(CFTDRspQryNetDeviceTypeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetDeviceTypeTopicFieldUse[]=
{
		{ FTD_FID_RtnNetDeviceType, &(CFTDRtnNetDeviceTypeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetDeviceCategoryTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetDeviceCategory, &(CFTDReqQryNetDeviceCategoryField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetDeviceCategoryTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetDeviceCategory, &(CFTDRspQryNetDeviceCategoryField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetDeviceCategoryTopicFieldUse[]=
{
		{ FTD_FID_RtnNetDeviceCategory, &(CFTDRtnNetDeviceCategoryField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetManufactoryTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetManufactory, &(CFTDReqQryNetManufactoryField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetManufactoryTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetManufactory, &(CFTDRspQryNetManufactoryField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetManufactoryTopicFieldUse[]=
{
		{ FTD_FID_RtnNetManufactory, &(CFTDRtnNetManufactoryField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetCommunityTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetCommunity, &(CFTDReqQryNetCommunityField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetCommunityTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetCommunity, &(CFTDRspQryNetCommunityField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetCommunityTopicFieldUse[]=
{
		{ FTD_FID_RtnNetCommunity, &(CFTDRtnNetCommunityField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetPortTypeTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetPortType, &(CFTDReqQryNetPortTypeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetPortTypeTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetPortType, &(CFTDRspQryNetPortTypeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetPortTypeTopicFieldUse[]=
{
		{ FTD_FID_RtnNetPortType, &(CFTDRtnNetPortTypeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetPartAccessSpotTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetPartAccessSpot, &(CFTDReqQryNetPartAccessSpotField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetPartAccessSpotTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetPartAccessSpot, &(CFTDRspQryNetPartAccessSpotField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetPartAccessSpotTopicFieldUse[]=
{
		{ FTD_FID_RtnNetPartAccessSpot, &(CFTDRtnNetPartAccessSpotField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetInterfaceTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetInterface, &(CFTDReqQryNetInterfaceField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetInterfaceTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetInterface, &(CFTDRspQryNetInterfaceField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetInterfaceTopicFieldUse[]=
{
		{ FTD_FID_RtnNetInterface, &(CFTDRtnNetInterfaceField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetGeneralOIDTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetGeneralOID, &(CFTDReqQryNetGeneralOIDField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetGeneralOIDTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetGeneralOID, &(CFTDRspQryNetGeneralOIDField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetGeneralOIDTopicFieldUse[]=
{
		{ FTD_FID_RtnNetGeneralOID, &(CFTDRtnNetGeneralOIDField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetMonitorTypeTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetMonitorType, &(CFTDReqQryNetMonitorTypeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetMonitorTypeTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetMonitorType, &(CFTDRspQryNetMonitorTypeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetMonitorTypeTopicFieldUse[]=
{
		{ FTD_FID_RtnNetMonitorType, &(CFTDRtnNetMonitorTypeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetMonitorAttrScopeTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetMonitorAttrScope, &(CFTDReqQryNetMonitorAttrScopeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetMonitorAttrScopeTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetMonitorAttrScope, &(CFTDRspQryNetMonitorAttrScopeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetMonitorAttrScopeTopicFieldUse[]=
{
		{ FTD_FID_RtnNetMonitorAttrScope, &(CFTDRtnNetMonitorAttrScopeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetMonitorAttrTypeTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetMonitorAttrType, &(CFTDReqQryNetMonitorAttrTypeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetMonitorAttrTypeTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetMonitorAttrType, &(CFTDRspQryNetMonitorAttrTypeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetMonitorAttrTypeTopicFieldUse[]=
{
		{ FTD_FID_RtnNetMonitorAttrType, &(CFTDRtnNetMonitorAttrTypeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetMonitorObjectAttrTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetMonitorObjectAttr, &(CFTDReqQryNetMonitorObjectAttrField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetMonitorObjectAttrTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetMonitorObjectAttr, &(CFTDRspQryNetMonitorObjectAttrField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetMonitorObjectAttrTopicFieldUse[]=
{
		{ FTD_FID_RtnNetMonitorObjectAttr, &(CFTDRtnNetMonitorObjectAttrField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetFuncAreaTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetFuncArea, &(CFTDReqQryNetFuncAreaField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetFuncAreaTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetFuncArea, &(CFTDRspQryNetFuncAreaField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetFuncAreaTopicFieldUse[]=
{
		{ FTD_FID_RtnNetFuncArea, &(CFTDRtnNetFuncAreaField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetMonitorCommandTypeTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetMonitorCommandType, &(CFTDReqQryNetMonitorCommandTypeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetMonitorCommandTypeTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetMonitorCommandType, &(CFTDRspQryNetMonitorCommandTypeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetMonitorCommandTypeTopicFieldUse[]=
{
		{ FTD_FID_RtnNetMonitorCommandType, &(CFTDRtnNetMonitorCommandTypeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetMonitorActionGroupTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetMonitorActionGroup, &(CFTDReqQryNetMonitorActionGroupField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetMonitorActionGroupTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetMonitorActionGroup, &(CFTDRspQryNetMonitorActionGroupField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetMonitorActionGroupTopicFieldUse[]=
{
		{ FTD_FID_RtnNetMonitorActionGroup, &(CFTDRtnNetMonitorActionGroupField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetMonitorDeviceGroupTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetMonitorDeviceGroup, &(CFTDReqQryNetMonitorDeviceGroupField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetMonitorDeviceGroupTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetMonitorDeviceGroup, &(CFTDRspQryNetMonitorDeviceGroupField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetMonitorDeviceGroupTopicFieldUse[]=
{
		{ FTD_FID_RtnNetMonitorDeviceGroup, &(CFTDRtnNetMonitorDeviceGroupField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetMonitorTaskInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetMonitorTaskInfo, &(CFTDReqQryNetMonitorTaskInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetMonitorTaskInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetMonitorTaskInfo, &(CFTDRspQryNetMonitorTaskInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetMonitorTaskInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnNetMonitorTaskInfo, &(CFTDRtnNetMonitorTaskInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetMonitorTaskResultTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetMonitorTaskResult, &(CFTDReqQryNetMonitorTaskResultField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetMonitorTaskResultTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetMonitorTaskResult, &(CFTDRspQryNetMonitorTaskResultField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetMonitorTaskResultTopicFieldUse[]=
{
		{ FTD_FID_RtnNetMonitorTaskResult, &(CFTDRtnNetMonitorTaskResultField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetMonitorTaskObjectSetTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetMonitorTaskObjectSet, &(CFTDReqQryNetMonitorTaskObjectSetField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetMonitorTaskObjectSetTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetMonitorTaskObjectSet, &(CFTDRspQryNetMonitorTaskObjectSetField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetMonitorTaskObjectSetTopicFieldUse[]=
{
		{ FTD_FID_RtnNetMonitorTaskObjectSet, &(CFTDRtnNetMonitorTaskObjectSetField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetPartyLinkInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetPartyLinkInfo, &(CFTDReqQryNetPartyLinkInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetPartyLinkInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetPartyLinkInfo, &(CFTDRspQryNetPartyLinkInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetPartyLinkInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnNetPartyLinkInfo, &(CFTDRtnNetPartyLinkInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetMonitorActionAttrTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetMonitorActionAttr, &(CFTDReqQryNetMonitorActionAttrField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetMonitorActionAttrTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetMonitorActionAttr, &(CFTDRspQryNetMonitorActionAttrField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetMonitorActionAttrTopicFieldUse[]=
{
		{ FTD_FID_RtnNetMonitorActionAttr, &(CFTDRtnNetMonitorActionAttrField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetModuleTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetModule, &(CFTDReqQryNetModuleField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetModuleTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetModule, &(CFTDRspQryNetModuleField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetModuleTopicFieldUse[]=
{
		{ FTD_FID_RtnNetModule, &(CFTDRtnNetModuleField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetEventExprTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetEventExpr, &(CFTDReqQryNetEventExprField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetEventExprTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetEventExpr, &(CFTDRspQryNetEventExprField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetEventExprTopicFieldUse[]=
{
		{ FTD_FID_RtnNetEventExpr, &(CFTDRtnNetEventExprField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetEventTypeTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetEventType, &(CFTDReqQryNetEventTypeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetEventTypeTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetEventType, &(CFTDRspQryNetEventTypeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetEventTypeTopicFieldUse[]=
{
		{ FTD_FID_RtnNetEventType, &(CFTDRtnNetEventTypeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetSubEventTypeTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetSubEventType, &(CFTDReqQryNetSubEventTypeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetSubEventTypeTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetSubEventType, &(CFTDRspQryNetSubEventTypeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetSubEventTypeTopicFieldUse[]=
{
		{ FTD_FID_RtnNetSubEventType, &(CFTDRtnNetSubEventTypeField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetEventLevelTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetEventLevel, &(CFTDReqQryNetEventLevelField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetEventLevelTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetEventLevel, &(CFTDRspQryNetEventLevelField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetEventLevelTopicFieldUse[]=
{
		{ FTD_FID_RtnNetEventLevel, &(CFTDRtnNetEventLevelField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetMonitorTaskStatusResultTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetMonitorTaskStatusResult, &(CFTDReqQryNetMonitorTaskStatusResultField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetMonitorTaskStatusResultTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetMonitorTaskStatusResult, &(CFTDRspQryNetMonitorTaskStatusResultField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetMonitorTaskStatusResultTopicFieldUse[]=
{
		{ FTD_FID_RtnNetMonitorTaskStatusResult, &(CFTDRtnNetMonitorTaskStatusResultField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqConfigLoginTopicFieldUse[]=
{
		{ FTD_FID_ReqConfigLogin, &(CFTDReqConfigLoginField::m_Describe), 1,  1  }
};

TFieldUse FTDRspConfigLoginTopicFieldUse[]=
{
		{ FTD_FID_RspQryConfigLogin, &(CFTDRspQryConfigLoginField::m_Describe), 1,  1  }
};

TFieldUse FTDRspServerTypeTopicFieldUse[]=
{
		{ FTD_FID_RspServerType, &(CFTDRspServerTypeField::m_Describe), 1,  1  }
};

TFieldUse FTDReqSysServerExitTopicFieldUse[]=
{
		{ FTD_FID_ReqSysServerExit, &(CFTDReqSysServerExitField::m_Describe), 1,  1  }
};

TFieldUse FTDReqQryNetCfgFileTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetCfgFile, &(CFTDReqQryNetCfgFileField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetCfgFileTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetCfgFile, &(CFTDRspQryNetCfgFileField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetCfgFileTopicFieldUse[]=
{
		{ FTD_FID_RtnNetCfgFile, &(CFTDRtnNetCfgFileField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetMonitorDeviceTaskTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetMonitorDeviceTask, &(CFTDReqQryNetMonitorDeviceTaskField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetMonitorDeviceTaskTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetMonitorDeviceTask, &(CFTDRspQryNetMonitorDeviceTaskField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetMonitorDeviceTaskTopicFieldUse[]=
{
		{ FTD_FID_RtnNetMonitorDeviceTask, &(CFTDRtnNetMonitorDeviceTaskField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetMonitorTaskInstAttrsTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetMonitorTaskInstAttrs, &(CFTDReqQryNetMonitorTaskInstAttrsField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetMonitorTaskInstAttrsTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetMonitorTaskInstAttrs, &(CFTDRspQryNetMonitorTaskInstAttrsField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetMonitorTaskInstAttrsTopicFieldUse[]=
{
		{ FTD_FID_RtnNetMonitorTaskInstAttrs, &(CFTDRtnNetMonitorTaskInstAttrsField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryFileGeneralOperTopicFieldUse[]=
{
		{ FTD_FID_ReqQryFileGeneralOper, &(CFTDReqQryFileGeneralOperField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryFileGeneralOperTopicFieldUse[]=
{
		{ FTD_FID_RspQryFileGeneralOper, &(CFTDRspQryFileGeneralOperField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnFileGeneralOperTopicFieldUse[]=
{
		{ FTD_FID_RtnFileGeneralOper, &(CFTDRtnFileGeneralOperField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetBaseLineTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetBaseLine, &(CFTDReqQryNetBaseLineField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetBaseLineTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetBaseLine, &(CFTDRspQryNetBaseLineField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetBaseLineTopicFieldUse[]=
{
		{ FTD_FID_RtnNetBaseLine, &(CFTDRtnNetBaseLineField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetBaseLineTaskTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetBaseLineTask, &(CFTDReqQryNetBaseLineTaskField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetBaseLineTaskTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetBaseLineTask, &(CFTDRspQryNetBaseLineTaskField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetBaseLineTaskTopicFieldUse[]=
{
		{ FTD_FID_RtnNetBaseLineTask, &(CFTDRtnNetBaseLineTaskField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetBaseLineResultTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetBaseLineResult, &(CFTDReqQryNetBaseLineResultField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetBaseLineResultTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetBaseLineResult, &(CFTDRspQryNetBaseLineResultField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetBaseLineResultTopicFieldUse[]=
{
		{ FTD_FID_RtnNetBaseLineResult, &(CFTDRtnNetBaseLineResultField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetPartyLinkStatusInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetPartyLinkStatusInfo, &(CFTDReqQryNetPartyLinkStatusInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetPartyLinkStatusInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetPartyLinkStatusInfo, &(CFTDRspQryNetPartyLinkStatusInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetPartyLinkStatusInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnNetPartyLinkStatusInfo, &(CFTDRtnNetPartyLinkStatusInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetMemberSDHLineInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetMemberSDHLineInfo, &(CFTDReqQryNetMemberSDHLineInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetMemberSDHLineInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetMemberSDHLineInfo, &(CFTDRspQryNetMemberSDHLineInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetMemberSDHLineInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnNetMemberSDHLineInfo, &(CFTDRtnNetMemberSDHLineInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetDDNLinkInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetDDNLinkInfo, &(CFTDReqQryNetDDNLinkInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetDDNLinkInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetDDNLinkInfo, &(CFTDRspQryNetDDNLinkInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetDDNLinkInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnNetDDNLinkInfo, &(CFTDRtnNetDDNLinkInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetPseudMemberLinkInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetPseudMemberLinkInfo, &(CFTDReqQryNetPseudMemberLinkInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetPseudMemberLinkInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetPseudMemberLinkInfo, &(CFTDRspQryNetPseudMemberLinkInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetPseudMemberLinkInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnNetPseudMemberLinkInfo, &(CFTDRtnNetPseudMemberLinkInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryOuterDeviceInfTopicFieldUse[]=
{
		{ FTD_FID_ReqQryOuterDeviceInf, &(CFTDReqQryOuterDeviceInfField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryOuterDeviceInfTopicFieldUse[]=
{
		{ FTD_FID_RspQryOuterDeviceInf, &(CFTDRspQryOuterDeviceInfField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetOuterDeviceInfTopicFieldUse[]=
{
		{ FTD_FID_RtnNetOuterDeviceInf, &(CFTDRtnNetOuterDeviceInfField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetLocalPingResultInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetLocalPingResultInfo, &(CFTDReqQryNetLocalPingResultInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetLocalPingResultInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetLocalPingResultInfo, &(CFTDRspQryNetLocalPingResultInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetLocalPingResultInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnNetLocalPingResultInfo, &(CFTDRtnNetLocalPingResultInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetRomotePingResultInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetRomotePingResultInfo, &(CFTDReqQryNetRomotePingResultInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetRomotePingResultInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetRomotePingResultInfo, &(CFTDRspQryNetRomotePingResultInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetRomotePingResultInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnNetRomotePingResultInfo, &(CFTDRtnNetRomotePingResultInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRtnMonitorTopProcessInfoFieldUse[]=
{
		{ FTD_FID_RtnMonitorTopProcessInfo, &(CFTDRtnMonitorTopProcessInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQrySysInternalTopologyTopicFieldUse[]=
{
		{ FTD_FID_ReqQrySysInternalTopology, &(CFTDReqQrySysInternalTopologyField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQrySysInternalTopologyTopicFieldUse[]=
{
		{ FTD_FID_RspQrySysInternalTopology, &(CFTDRspQrySysInternalTopologyField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnSysInternalTopologyTopicFieldUse[]=
{
		{ FTD_FID_RtnSysInternalTopology, &(CFTDRtnSysInternalTopologyField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryMemberLinkCostTopicFieldUse[]=
{
		{ FTD_FID_ReqQryMemberLinkCost, &(CFTDReqQryMemberLinkCostField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryMemberLinkCostTopicFieldUse[]=
{
		{ FTD_FID_RspQryMemberLinkCost, &(CFTDRspQryMemberLinkCostField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnMemberLinkCostTopicFieldUse[]=
{
		{ FTD_FID_RtnMemberLinkCost, &(CFTDRtnMemberLinkCostField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetPartylinkMonthlyRentTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetPartylinkMonthlyRent, &(CFTDReqQryNetPartylinkMonthlyRentField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetPartylinkMonthlyRentTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetPartylinkMonthlyRent, &(CFTDRspQryNetPartylinkMonthlyRentField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetPartylinkMonthlyRentTopicFieldUse[]=
{
		{ FTD_FID_RtnNetPartylinkMonthlyRent, &(CFTDRtnNetPartylinkMonthlyRentField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDReqQryNetNonPartyLinkInfoTopicFieldUse[]=
{
		{ FTD_FID_ReqQryNetNonPartyLinkInfo, &(CFTDReqQryNetNonPartyLinkInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse FTDRspQryNetNonPartyLinkInfoTopicFieldUse[]=
{
		{ FTD_FID_RspQryNetNonPartyLinkInfo, &(CFTDRspQryNetNonPartyLinkInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FTD_FID_RspInfo, &(CFTDRspInfoField::m_Describe), 1,  1  }
};

TFieldUse FTDRtnNetNonPartyLinkInfoTopicFieldUse[]=
{
		{ FTD_FID_RtnNetNonPartyLinkInfo, &(CFTDRtnNetNonPartyLinkInfoField::m_Describe), 1,  UNLIMITED_FIELD_OCCUR  }
};


TPackageDefine FTDPackageDefines[]=
{
	{ FTD_TID_RspError, 1, FTDRspErrorFieldUse }
		,
	{ FTD_TID_ReqUserLogin, 2, FTDReqUserLoginFieldUse }
		,
	{ FTD_TID_RspUserLogin, 2, FTDRspUserLoginFieldUse }
		,
	{ FTD_TID_ReqUserLogout, 1, FTDReqUserLogoutFieldUse }
		,
	{ FTD_TID_RspUserLogout, 2, FTDRspUserLogoutFieldUse }
		,
	{ FTD_TID_ReqOrderInsert, 1, FTDReqOrderInsertFieldUse }
		,
	{ FTD_TID_RspOrderInsert, 2, FTDRspOrderInsertFieldUse }
		,
	{ FTD_TID_ReqOrderAction, 1, FTDReqOrderActionFieldUse }
		,
	{ FTD_TID_RspOrderAction, 2, FTDRspOrderActionFieldUse }
		,
	{ FTD_TID_ReqQuoteInsert, 1, FTDReqQuoteInsertFieldUse }
		,
	{ FTD_TID_RspQuoteInsert, 2, FTDRspQuoteInsertFieldUse }
		,
	{ FTD_TID_ReqQuoteAction, 1, FTDReqQuoteActionFieldUse }
		,
	{ FTD_TID_RspQuoteAction, 2, FTDRspQuoteActionFieldUse }
		,
	{ FTD_TID_ReqOTCOrderInsert, 1, FTDReqOTCOrderInsertFieldUse }
		,
	{ FTD_TID_RspOTCOrderInsert, 2, FTDRspOTCOrderInsertFieldUse }
		,
	{ FTD_TID_ReqUserPasswordUpdate, 1, FTDReqUserPasswordUpdateFieldUse }
		,
	{ FTD_TID_RspUserPasswordUpdate, 2, FTDRspUserPasswordUpdateFieldUse }
		,
	{ FTD_TID_ReqExecOrderInsert, 1, FTDReqExecOrderInsertFieldUse }
		,
	{ FTD_TID_RspExecOrderInsert, 2, FTDRspExecOrderInsertFieldUse }
		,
	{ FTD_TID_ReqExecOrderAction, 1, FTDReqExecOrderActionFieldUse }
		,
	{ FTD_TID_RspExecOrderAction, 2, FTDRspExecOrderActionFieldUse }
		,
	{ FTD_TID_ReqAdminOrderInsert, 1, FTDReqAdminOrderInsertFieldUse }
		,
	{ FTD_TID_RspAdminOrderInsert, 2, FTDRspAdminOrderInsertFieldUse }
		,
	{ FTD_TID_ReqCombOrderInsert, 1, FTDReqCombOrderInsertFieldUse }
		,
	{ FTD_TID_RspCombOrderInsert, 2, FTDRspCombOrderInsertFieldUse }
		,
	{ FTD_TID_ReqSubscribeTopic, 1, FTDReqSubscribeTopicFieldUse }
		,
	{ FTD_TID_RspSubscribeTopic, 2, FTDRspSubscribeTopicFieldUse }
		,
	{ FTD_TID_ReqBulletin, 1, FTDReqBulletinFieldUse }
		,
	{ FTD_TID_RspBulletin, 2, FTDRspBulletinFieldUse }
		,
	{ FTD_TID_ReqInformation, 1, FTDReqInformationFieldUse }
		,
	{ FTD_TID_RspInformation, 2, FTDRspInformationFieldUse }
		,
	{ FTD_TID_ReqInstrumentStatusUpdate, 1, FTDReqInstrumentStatusUpdateFieldUse }
		,
	{ FTD_TID_RspInstrumentStatusUpdate, 2, FTDRspInstrumentStatusUpdateFieldUse }
		,
	{ FTD_TID_ReqForceUserExit, 1, FTDReqForceUserExitFieldUse }
		,
	{ FTD_TID_RspForceUserExit, 2, FTDRspForceUserExitFieldUse }
		,
	{ FTD_TID_ReqForceUserLogout, 1, FTDReqForceUserLogoutFieldUse }
		,
	{ FTD_TID_RspForceUserLogout, 2, FTDRspForceUserLogoutFieldUse }
		,
	{ FTD_TID_ReqExchangeDataSyncStatusUpdate, 1, FTDReqExchangeDataSyncStatusUpdateFieldUse }
		,
	{ FTD_TID_RspExchangeDataSyncStatusUpdate, 2, FTDRspExchangeDataSyncStatusUpdateFieldUse }
		,
	{ FTD_TID_ReqSGDataSyncStatusUpdate, 1, FTDReqSGDataSyncStatusUpdateFieldUse }
		,
	{ FTD_TID_RspSGDataSyncStatusUpdate, 2, FTDRspSGDataSyncStatusUpdateFieldUse }
		,
	{ FTD_TID_ReqQryPartAccount, 1, FTDReqQryPartAccountFieldUse }
		,
	{ FTD_TID_RspQryPartAccount, 2, FTDRspQryPartAccountFieldUse }
		,
	{ FTD_TID_ReqQryOrder, 1, FTDReqQryOrderFieldUse }
		,
	{ FTD_TID_RspQryOrder, 2, FTDRspQryOrderFieldUse }
		,
	{ FTD_TID_ReqQryQuote, 1, FTDReqQryQuoteFieldUse }
		,
	{ FTD_TID_RspQryQuote, 2, FTDRspQryQuoteFieldUse }
		,
	{ FTD_TID_ReqQryTrade, 1, FTDReqQryTradeFieldUse }
		,
	{ FTD_TID_RspQryTrade, 2, FTDRspQryTradeFieldUse }
		,
	{ FTD_TID_ReqQryClient, 1, FTDReqQryClientFieldUse }
		,
	{ FTD_TID_RspQryClient, 2, FTDRspQryClientFieldUse }
		,
	{ FTD_TID_ReqQryPartPosition, 1, FTDReqQryPartPositionFieldUse }
		,
	{ FTD_TID_RspQryPartPosition, 2, FTDRspQryPartPositionFieldUse }
		,
	{ FTD_TID_ReqQryClientPosition, 1, FTDReqQryClientPositionFieldUse }
		,
	{ FTD_TID_RspQryClientPosition, 2, FTDRspQryClientPositionFieldUse }
		,
	{ FTD_TID_ReqQryInstrument, 1, FTDReqQryInstrumentFieldUse }
		,
	{ FTD_TID_RspQryInstrument, 2, FTDRspQryInstrumentFieldUse }
		,
	{ FTD_TID_ReqQryInstrumentStatus, 1, FTDReqQryInstrumentStatusFieldUse }
		,
	{ FTD_TID_RspQryInstrumentStatus, 2, FTDRspQryInstrumentStatusFieldUse }
		,
	{ FTD_TID_ReqQrySGDataSyncStatus, 1, FTDReqQrySGDataSyncStatusFieldUse }
		,
	{ FTD_TID_RspQrySGDataSyncStatus, 2, FTDRspQrySGDataSyncStatusFieldUse }
		,
	{ FTD_TID_ReqQryHedgeVolume, 1, FTDReqQryHedgeVolumeFieldUse }
		,
	{ FTD_TID_RspQryHedgeVolume, 2, FTDRspQryHedgeVolumeFieldUse }
		,
	{ FTD_TID_ReqQryCreditLimit, 1, FTDReqQryCreditLimitFieldUse }
		,
	{ FTD_TID_RspQryCreditLimit, 2, FTDRspQryCreditLimitFieldUse }
		,
	{ FTD_TID_ReqQryCombOrder, 1, FTDReqQryCombOrderFieldUse }
		,
	{ FTD_TID_RspQryCombOrder, 2, FTDRspQryCombOrderFieldUse }
		,
	{ FTD_TID_ReqQryExecOrder, 1, FTDReqQryExecOrderFieldUse }
		,
	{ FTD_TID_RspQryExecOrder, 2, FTDRspQryExecOrderFieldUse }
		,
	{ FTD_TID_ReqQryMarketData, 1, FTDReqQryMarketDataFieldUse }
		,
	{ FTD_TID_RspQryMarketData, 2, FTDRspQryMarketDataFieldUse }
		,
	{ FTD_TID_ReqQryBulletin, 1, FTDReqQryBulletinFieldUse }
		,
	{ FTD_TID_RspQryBulletin, 2, FTDRspQryBulletinFieldUse }
		,
	{ FTD_TID_ReqQryTopic, 1, FTDReqQryTopicFieldUse }
		,
	{ FTD_TID_RspQryTopic, 2, FTDRspQryTopicFieldUse }
		,
	{ FTD_TID_ReqQryUserSession, 1, FTDReqQryUserSessionFieldUse }
		,
	{ FTD_TID_RspQryUserSession, 2, FTDRspQryUserSessionFieldUse }
		,
	{ FTD_TID_ReqQryUser, 1, FTDReqQryUserFieldUse }
		,
	{ FTD_TID_RspQryUser, 2, FTDRspQryUserFieldUse }
		,
	{ FTD_TID_ReqQryParticipant, 1, FTDReqQryParticipantFieldUse }
		,
	{ FTD_TID_RspQryParticipant, 2, FTDRspQryParticipantFieldUse }
		,
	{ FTD_TID_ReqQryMBLMarketData, 1, FTDReqQryMBLMarketDataFieldUse }
		,
	{ FTD_TID_RspQryMBLMarketData, 2, FTDRspQryMBLMarketDataFieldUse }
		,
	{ FTD_TID_ReqQryInformation, 1, FTDReqQryInformationFieldUse }
		,
	{ FTD_TID_RspQryInformation, 2, FTDRspQryInformationFieldUse }
		,
	{ FTD_TID_RtnTrade, 1, FTDRtnTradeFieldUse }
		,
	{ FTD_TID_RtnOrder, 1, FTDRtnOrderFieldUse }
		,
	{ FTD_TID_RtnExecOrder, 1, FTDRtnExecOrderFieldUse }
		,
	{ FTD_TID_RtnQuote, 1, FTDRtnQuoteFieldUse }
		,
	{ FTD_TID_RtnCombOrder, 1, FTDRtnCombOrderFieldUse }
		,
	{ FTD_TID_RtnInstrumentStatus, 1, FTDRtnInstrumentStatusFieldUse }
		,
	{ FTD_TID_RtnInsInstrument, 1, FTDRtnInsInstrumentFieldUse }
		,
	{ FTD_TID_RtnDelInstrument, 1, FTDRtnDelInstrumentFieldUse }
		,
	{ FTD_TID_RtnInsCombinationLeg, 1, FTDRtnInsCombinationLegFieldUse }
		,
	{ FTD_TID_RtnDelCombinationLeg, 1, FTDRtnDelCombinationLegFieldUse }
		,
	{ FTD_TID_RtnAliasDefine, 1, FTDRtnAliasDefineFieldUse }
		,
	{ FTD_TID_RtnFlowMessageCancel, 1, FTDRtnFlowMessageCancelFieldUse }
		,
	{ FTD_TID_RtnBulletin, 1, FTDRtnBulletinFieldUse }
		,
	{ FTD_TID_RtnMarketData, 1, FTDRtnMarketDataFieldUse }
		,
	{ FTD_TID_RtnDepthMarketData, 1, FTDRtnDepthMarketDataFieldUse }
		,
	{ FTD_TID_IntlRtnDissemination, 1, FTDIntlRtnDisseminationFieldUse }
		,
	{ FTD_TID_IntlRtnDepthMarketData, 9, FTDIntlRtnDepthMarketDataFieldUse }
		,
	{ FTD_TID_RtnAdminOrder, 1, FTDRtnAdminOrderFieldUse }
		,
	{ FTD_TID_ErrRtnOrderInsert, 2, FTDErrRtnOrderInsertFieldUse }
		,
	{ FTD_TID_ErrRtnOrderAction, 2, FTDErrRtnOrderActionFieldUse }
		,
	{ FTD_TID_ErrRtnQuoteInsert, 2, FTDErrRtnQuoteInsertFieldUse }
		,
	{ FTD_TID_ErrRtnQuoteAction, 2, FTDErrRtnQuoteActionFieldUse }
		,
	{ FTD_TID_ErrRtnExecOrderInsert, 2, FTDErrRtnExecOrderInsertFieldUse }
		,
	{ FTD_TID_ErrRtnExecOrderAction, 2, FTDErrRtnExecOrderActionFieldUse }
		,
	{ FTD_TID_ErrAdminOrderInsert, 2, FTDErrAdminOrderInsertFieldUse }
		,
	{ FTD_TID_ErrRtnCombOrderInsert, 2, FTDErrRtnCombOrderInsertFieldUse }
		,
	{ FTD_TID_ReqQryClientPositionV1, 1, FTDReqQryClientPositionV1FieldUse }
		,
	{ FTD_TID_ReqQryExchangeRate, 1, FTDReqQryExchangeRateFieldUse }
		,
	{ FTD_TID_RspQryExchangeRate, 2, FTDRspQryExchangeRateFieldUse }
		,
	{ FTD_TID_IntlLoopMeasureData, 2, FTDIntlLoopMeasureDataFieldUse }
		,
	{ FTD_TID_ReqQryTopCpuInfoTopic, 1, FTDReqQryTopCpuInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryTopCpuInfoTopic, 2, FTDRspQryTopCpuInfoTopicFieldUse }
		,
	{ FTD_TID_RtnTopCpuInfoTopic, 1, FTDRtnTopCpuInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQryTopMemInfoTopic, 1, FTDReqQryTopMemInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryTopMemInfoTopic, 2, FTDRspQryTopMemInfoTopicFieldUse }
		,
	{ FTD_TID_RtnTopMemInfoTopic, 1, FTDRtnTopMemInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQryTopProcessInfoTopic, 1, FTDReqQryTopProcessInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryTopProcessInfoTopic, 2, FTDRspQryTopProcessInfoTopicFieldUse }
		,
	{ FTD_TID_RtnTopProcessInfoTopic, 1, FTDRtnTopProcessInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQryFileSystemInfoTopic, 1, FTDReqQryFileSystemInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryFileSystemInfoTopic, 2, FTDRspQryFileSystemInfoTopicFieldUse }
		,
	{ FTD_TID_RtnFileSystemInfoTopic, 1, FTDRtnFileSystemInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetworkInfoTopic, 1, FTDReqQryNetworkInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryNetworkInfoTopic, 2, FTDRspQryNetworkInfoTopicFieldUse }
		,
	{ FTD_TID_RtnNetworkInfoTopic, 1, FTDRtnNetworkInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQryHostEnvTopic, 1, FTDReqQryHostEnvTopicFieldUse }
		,
	{ FTD_TID_ReqQryClientLoginTopic, 1, FTDReqQryClientLoginTopicFieldUse }
		,
	{ FTD_TID_RspQryClientLoginTopic, 2, FTDRspQryClientLoginTopicFieldUse }
		,
	{ FTD_TID_ReqQryMonitorObjectTopic, 1, FTDReqQryMonitorObjectTopicFieldUse }
		,
	{ FTD_TID_RspQryMonitorObjectTopic, 2, FTDRspQryMonitorObjectTopicFieldUse }
		,
	{ FTD_TID_RtnMonitorObjectTopic, 1, FTDRtnMonitorObjectTopicFieldUse }
		,
	{ FTD_TID_ReqQryObjectRationalTopic, 1, FTDReqQryObjectRationalTopicFieldUse }
		,
	{ FTD_TID_RspQryObjectRationalTopic, 2, FTDRspQryObjectRationalTopicFieldUse }
		,
	{ FTD_TID_RtnObjectRationalTopic, 1, FTDRtnObjectRationalTopicFieldUse }
		,
	{ FTD_TID_ReqQrySyslogInfoTopic, 1, FTDReqQrySyslogInfoTopicFieldUse }
		,
	{ FTD_TID_RspQrySyslogInfoTopic, 2, FTDRspQrySyslogInfoTopicFieldUse }
		,
	{ FTD_TID_RtnSyslogInfoTopic, 1, FTDRtnSyslogInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQrySubscriberTopic, 1, FTDReqQrySubscriberTopicFieldUse }
		,
	{ FTD_TID_RspQrySubscriberTopic, 2, FTDRspQrySubscriberTopicFieldUse }
		,
	{ FTD_TID_ReqQryOidRelationTopic, 1, FTDReqQryOidRelationTopicFieldUse }
		,
	{ FTD_TID_RspQryOidRelationTopic, 2, FTDRspQryOidRelationTopicFieldUse }
		,
	{ FTD_TID_RtnOidRelationTopic, 1, FTDRtnOidRelationTopicFieldUse }
		,
	{ FTD_TID_ReqQryUserInfoTopic, 1, FTDReqQryUserInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryUserInfoTopic, 2, FTDRspQryUserInfoTopicFieldUse }
		,
	{ FTD_TID_RtnUserInfoTopic, 1, FTDRtnUserInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQryOnlineUserInfoTopic, 1, FTDReqQryOnlineUserInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryOnlineUserInfoTopic, 2, FTDRspQryOnlineUserInfoTopicFieldUse }
		,
	{ FTD_TID_RtnOnlineUserInfoTopic, 1, FTDRtnOnlineUserInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQryWarningEventTopic, 1, FTDReqQryWarningEventTopicFieldUse }
		,
	{ FTD_TID_RspQryWarningEventTopic, 2, FTDRspQryWarningEventTopicFieldUse }
		,
	{ FTD_TID_RtnWarningEventTopic, 1, FTDRtnWarningEventTopicFieldUse }
		,
	{ FTD_TID_ReqQryCPUUsageTopic, 1, FTDReqQryCPUUsageTopicFieldUse }
		,
	{ FTD_TID_RspQryCPUUsageTopic, 2, FTDRspQryCPUUsageTopicFieldUse }
		,
	{ FTD_TID_RtnCPUUsageTopic, 1, FTDRtnCPUUsageTopicFieldUse }
		,
	{ FTD_TID_ReqQryMemoryUsageTopic, 1, FTDReqQryMemoryUsageTopicFieldUse }
		,
	{ FTD_TID_RspQryMemoryUsageTopic, 2, FTDRspQryMemoryUsageTopicFieldUse }
		,
	{ FTD_TID_RtnMemoryUsageTopic, 1, FTDRtnMemoryUsageTopicFieldUse }
		,
	{ FTD_TID_ReqQryDiskUsageTopic, 1, FTDReqQryDiskUsageTopicFieldUse }
		,
	{ FTD_TID_RspQryDiskUsageTopic, 2, FTDRspQryDiskUsageTopicFieldUse }
		,
	{ FTD_TID_RtnDiskUsageTopic, 1, FTDRtnDiskUsageTopicFieldUse }
		,
	{ FTD_TID_ReqQryObjectAttrTopic, 1, FTDReqQryObjectAttrTopicFieldUse }
		,
	{ FTD_TID_RspQryObjectAttrTopic, 2, FTDRspQryObjectAttrTopicFieldUse }
		,
	{ FTD_TID_RtnObjectAttrTopic, 1, FTDRtnObjectAttrTopicFieldUse }
		,
	{ FTD_TID_ReqQryKeyFileInfoTopic, 1, FTDReqQryKeyFileInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQryHostMonitorCfgTopic, 1, FTDReqQryHostMonitorCfgTopicFieldUse }
		,
	{ FTD_TID_ReqQryAppMonitorCfgTopic, 1, FTDReqQryAppMonitorCfgTopicFieldUse }
		,
	{ FTD_TID_ReqQryHostConfigTopic, 1, FTDReqQryHostConfigTopicFieldUse }
		,
	{ FTD_TID_ReqQryInvalidateOrderTopic, 1, FTDReqQryInvalidateOrderTopicFieldUse }
		,
	{ FTD_TID_RspQryInvalidateOrderTopic, 2, FTDRspQryInvalidateOrderTopicFieldUse }
		,
	{ FTD_TID_RtnInvalidateOrderTopic, 1, FTDRtnInvalidateOrderTopicFieldUse }
		,
	{ FTD_TID_ReqQryOrderStatusTopic, 1, FTDReqQryOrderStatusTopicFieldUse }
		,
	{ FTD_TID_RspQryOrderStatusTopic, 2, FTDRspQryOrderStatusTopicFieldUse }
		,
	{ FTD_TID_RtnOrderStatusTopic, 1, FTDRtnOrderStatusTopicFieldUse }
		,
	{ FTD_TID_ReqQryBargainOrderTopic, 1, FTDReqQryBargainOrderTopicFieldUse }
		,
	{ FTD_TID_RspQryBargainOrderTopic, 2, FTDRspQryBargainOrderTopicFieldUse }
		,
	{ FTD_TID_RtnBargainOrderTopic, 1, FTDRtnBargainOrderTopicFieldUse }
		,
	{ FTD_TID_ReqQryInstPropertyTopic, 1, FTDReqQryInstPropertyTopicFieldUse }
		,
	{ FTD_TID_RspQryInstPropertyTopic, 2, FTDRspQryInstPropertyTopicFieldUse }
		,
	{ FTD_TID_RtnInstPropertyTopic, 1, FTDRtnInstPropertyTopicFieldUse }
		,
	{ FTD_TID_ReqQryMarginRateTopic, 1, FTDReqQryMarginRateTopicFieldUse }
		,
	{ FTD_TID_RspQryMarginRateTopic, 2, FTDRspQryMarginRateTopicFieldUse }
		,
	{ FTD_TID_RtnMarginRateTopic, 1, FTDRtnMarginRateTopicFieldUse }
		,
	{ FTD_TID_ReqQryPriceLimitTopic, 1, FTDReqQryPriceLimitTopicFieldUse }
		,
	{ FTD_TID_RspQryPriceLimitTopic, 2, FTDRspQryPriceLimitTopicFieldUse }
		,
	{ FTD_TID_RtnPriceLimitTopic, 1, FTDRtnPriceLimitTopicFieldUse }
		,
	{ FTD_TID_ReqQryPartPosiLimitTopic, 1, FTDReqQryPartPosiLimitTopicFieldUse }
		,
	{ FTD_TID_RspQryPartPosiLimitTopic, 2, FTDRspQryPartPosiLimitTopicFieldUse }
		,
	{ FTD_TID_RtnPartPosiLimitTopic, 1, FTDRtnPartPosiLimitTopicFieldUse }
		,
	{ FTD_TID_ReqQryClientPosiLimitTopic, 1, FTDReqQryClientPosiLimitTopicFieldUse }
		,
	{ FTD_TID_RspQryClientPosiLimitTopic, 2, FTDRspQryClientPosiLimitTopicFieldUse }
		,
	{ FTD_TID_RtnClientPosiLimitTopic, 1, FTDRtnClientPosiLimitTopicFieldUse }
		,
	{ FTD_TID_ReqQrySpecialPosiLimitTopic, 1, FTDReqQrySpecialPosiLimitTopicFieldUse }
		,
	{ FTD_TID_RspQrySpecialPosiLimitTopic, 2, FTDRspQrySpecialPosiLimitTopicFieldUse }
		,
	{ FTD_TID_RtnSpecialPosiLimitTopic, 1, FTDRtnSpecialPosiLimitTopicFieldUse }
		,
	{ FTD_TID_ReqQryTransactionChgTopic, 1, FTDReqQryTransactionChgTopicFieldUse }
		,
	{ FTD_TID_RspQryTransactionChgTopic, 2, FTDRspQryTransactionChgTopicFieldUse }
		,
	{ FTD_TID_RtnTransactionChgTopic, 1, FTDRtnTransactionChgTopicFieldUse }
		,
	{ FTD_TID_ReqQryClientChgTopic, 1, FTDReqQryClientChgTopicFieldUse }
		,
	{ FTD_TID_RspQryClientChgTopic, 2, FTDRspQryClientChgTopicFieldUse }
		,
	{ FTD_TID_RtnClientChgTopic, 1, FTDRtnClientChgTopicFieldUse }
		,
	{ FTD_TID_ReqQryPartClientChgTopic, 1, FTDReqQryPartClientChgTopicFieldUse }
		,
	{ FTD_TID_RspQryPartClientChgTopic, 2, FTDRspQryPartClientChgTopicFieldUse }
		,
	{ FTD_TID_RtnPartClientChgTopic, 1, FTDRtnPartClientChgTopicFieldUse }
		,
	{ FTD_TID_ReqQryPosiLimitChgTopic, 1, FTDReqQryPosiLimitChgTopicFieldUse }
		,
	{ FTD_TID_RspQryPosiLimitChgTopic, 2, FTDRspQryPosiLimitChgTopicFieldUse }
		,
	{ FTD_TID_RtnPosiLimitChgTopic, 1, FTDRtnPosiLimitChgTopicFieldUse }
		,
	{ FTD_TID_ReqQryHedgeDetailChgTopic, 1, FTDReqQryHedgeDetailChgTopicFieldUse }
		,
	{ FTD_TID_RspQryHedgeDetailChgTopic, 2, FTDRspQryHedgeDetailChgTopicFieldUse }
		,
	{ FTD_TID_RtnHedgeDetailChgTopic, 1, FTDRtnHedgeDetailChgTopicFieldUse }
		,
	{ FTD_TID_ReqQryParticipantChgTopic, 1, FTDReqQryParticipantChgTopicFieldUse }
		,
	{ FTD_TID_RspQryParticipantChgTopic, 2, FTDRspQryParticipantChgTopicFieldUse }
		,
	{ FTD_TID_RtnParticipantChgTopic, 1, FTDRtnParticipantChgTopicFieldUse }
		,
	{ FTD_TID_ReqQryMarginRateChgTopic, 1, FTDReqQryMarginRateChgTopicFieldUse }
		,
	{ FTD_TID_RspQryMarginRateChgTopic, 2, FTDRspQryMarginRateChgTopicFieldUse }
		,
	{ FTD_TID_RtnMarginRateChgTopic, 1, FTDRtnMarginRateChgTopicFieldUse }
		,
	{ FTD_TID_ReqQryUserIpChgTopic, 1, FTDReqQryUserIpChgTopicFieldUse }
		,
	{ FTD_TID_RspQryUserIpChgTopic, 2, FTDRspQryUserIpChgTopicFieldUse }
		,
	{ FTD_TID_RtnUserIpChgTopic, 1, FTDRtnUserIpChgTopicFieldUse }
		,
	{ FTD_TID_ReqQryClientPosiLimitChgTopic, 1, FTDReqQryClientPosiLimitChgTopicFieldUse }
		,
	{ FTD_TID_RspQryClientPosiLimitChgTopic, 2, FTDRspQryClientPosiLimitChgTopicFieldUse }
		,
	{ FTD_TID_RtnClientPosiLimitChgTopic, 1, FTDRtnClientPosiLimitChgTopicFieldUse }
		,
	{ FTD_TID_ReqQrySpecPosiLimitChgTopic, 1, FTDReqQrySpecPosiLimitChgTopicFieldUse }
		,
	{ FTD_TID_RspQrySpecPosiLimitChgTopic, 2, FTDRspQrySpecPosiLimitChgTopicFieldUse }
		,
	{ FTD_TID_RtnSpecPosiLimitChgTopic, 1, FTDRtnSpecPosiLimitChgTopicFieldUse }
		,
	{ FTD_TID_ReqQryHistoryObjectAttrTopic, 1, FTDReqQryHistoryObjectAttrTopicFieldUse }
		,
	{ FTD_TID_RspQryHistoryObjectAttrTopic, 2, FTDRspQryHistoryObjectAttrTopicFieldUse }
		,
	{ FTD_TID_RtnHistoryObjectAttrTopic, 1, FTDRtnHistoryObjectAttrTopicFieldUse }
		,
	{ FTD_TID_ReqQryFrontInfoTopic, 1, FTDReqQryFrontInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryFrontInfoTopic, 2, FTDRspQryFrontInfoTopicFieldUse }
		,
	{ FTD_TID_RtnFrontInfoTopic, 1, FTDRtnFrontInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQrySysUserLoginTopic, 1, FTDReqQrySysUserLoginTopicFieldUse }
		,
	{ FTD_TID_RspQrySysUserLoginTopic, 2, FTDRspQrySysUserLoginTopicFieldUse }
		,
	{ FTD_TID_ReqQrySysUserLogoutTopic, 1, FTDReqQrySysUserLogoutTopicFieldUse }
		,
	{ FTD_TID_RspQrySysUserLogoutTopic, 2, FTDRspQrySysUserLogoutTopicFieldUse }
		,
	{ FTD_TID_ReqQrySysUserPasswordUpdateTopic, 1, FTDReqQrySysUserPasswordUpdateTopicFieldUse }
		,
	{ FTD_TID_RspQrySysUserPasswordUpdateTopic, 2, FTDRspQrySysUserPasswordUpdateTopicFieldUse }
		,
	{ FTD_TID_ReqQrySysUserRegisterTopic, 1, FTDReqQrySysUserRegisterTopicFieldUse }
		,
	{ FTD_TID_RspQrySysUserRegisterTopic, 2, FTDRspQrySysUserRegisterTopicFieldUse }
		,
	{ FTD_TID_ReqQrySysUserDeleteTopic, 1, FTDReqQrySysUserDeleteTopicFieldUse }
		,
	{ FTD_TID_RspQrySysUserDeleteTopic, 2, FTDRspQrySysUserDeleteTopicFieldUse }
		,
	{ FTD_TID_RspQryParticipantInitTopic, 2, FTDRspQryParticipantInitTopicFieldUse }
		,
	{ FTD_TID_RtnParticipantInitTopic, 1, FTDRtnParticipantInitTopicFieldUse }
		,
	{ FTD_TID_RspQryUserInitTopic, 2, FTDRspQryUserInitTopicFieldUse }
		,
	{ FTD_TID_RtnUserInitTopic, 1, FTDRtnUserInitTopicFieldUse }
		,
	{ FTD_TID_RspQryClientInitTopic, 2, FTDRspQryClientInitTopicFieldUse }
		,
	{ FTD_TID_RtnClientInitTopic, 1, FTDRtnClientInitTopicFieldUse }
		,
	{ FTD_TID_ReqQryTradeLogTopic, 1, FTDReqQryTradeLogTopicFieldUse }
		,
	{ FTD_TID_RspQryTradeLogTopic, 2, FTDRspQryTradeLogTopicFieldUse }
		,
	{ FTD_TID_RtnTradeLogTopic, 1, FTDRtnTradeLogTopicFieldUse }
		,
	{ FTD_TID_ReqQryWarningEventUpdateTopic, 1, FTDReqQryWarningEventUpdateTopicFieldUse }
		,
	{ FTD_TID_ReqQryTradeUserLoginInfoTopic, 1, FTDReqQryTradeUserLoginInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryTradeUserLoginInfoTopic, 2, FTDRspQryTradeUserLoginInfoTopicFieldUse }
		,
	{ FTD_TID_RtnTradeUserLoginInfoTopic, 1, FTDRtnTradeUserLoginInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQryPartTradeTopic, 1, FTDReqQryPartTradeTopicFieldUse }
		,
	{ FTD_TID_RspQryPartTradeTopic, 2, FTDRspQryPartTradeTopicFieldUse }
		,
	{ FTD_TID_ReqQryTradepeakTopic, 1, FTDReqQryTradepeakTopicFieldUse }
		,
	{ FTD_TID_RspQryTradepeakTopic, 2, FTDRspQryTradepeakTopicFieldUse }
		,
	{ FTD_TID_RtnUpdateSysConfigTopic, 1, FTDRtnUpdateSysConfigTopicFieldUse }
		,
	{ FTD_TID_RtnSysUser, 1, FTDRtnSysUserFieldUse }
		,
	{ FTD_TID_RtnPriceLimitChgTopic, 1, FTDRtnPriceLimitChgTopicFieldUse }
		,
	{ FTD_TID_ReqQryParticipantInitTopic, 1, FTDReqQryParticipantInitTopicFieldUse }
		,
	{ FTD_TID_ReqQryUserInitTopic, 1, FTDReqQryUserInitTopicFieldUse }
		,
	{ FTD_TID_ReqQryHistoryCpuInfoTopic, 1, FTDReqQryHistoryCpuInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryHistoryCpuInfoTopic, 2, FTDRspQryHistoryCpuInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQryHistoryMemInfoTopic, 1, FTDReqQryHistoryMemInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryHistoryMemInfoTopic, 2, FTDRspQryHistoryMemInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQryHistoryNetworkInfoTopic, 1, FTDReqQryHistoryNetworkInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryHistoryNetworkInfoTopic, 2, FTDRspQryHistoryNetworkInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryHostConfig, 1, FTDRspQryHostConfigFieldUse }
		,
	{ FTD_TID_ReqQryMonitorOnlineUser, 1, FTDReqQryMonitorOnlineUserFieldUse }
		,
	{ FTD_TID_RspQryMonitorOnlineUser, 2, FTDRspQryMonitorOnlineUserFieldUse }
		,
	{ FTD_TID_ReqQryFrontStat, 1, FTDReqQryFrontStatFieldUse }
		,
	{ FTD_TID_RspQryFrontStat, 2, FTDRspQryFrontStatFieldUse }
		,
	{ FTD_TID_RtnSysTimeSyncTopic, 1, FTDRtnSysTimeSyncTopicFieldUse }
		,
	{ FTD_TID_RtnDataCenterChgTopic, 1, FTDRtnDataCenterChgTopicFieldUse }
		,
	{ FTD_TID_ReqQryHistoryTradePeakTopic, 1, FTDReqQryHistoryTradePeakTopicFieldUse }
		,
	{ FTD_TID_RspQryHistoryTradePeakTopic, 2, FTDRspQryHistoryTradePeakTopicFieldUse }
		,
	{ FTD_TID_RtnHistoryTradePeakTopic, 1, FTDRtnHistoryTradePeakTopicFieldUse }
		,
	{ FTD_TID_ReqQrySyslogEventTopic, 1, FTDReqQrySyslogEventTopicFieldUse }
		,
	{ FTD_TID_RspQrySyslogEventTopic, 2, FTDRspQrySyslogEventTopicFieldUse }
		,
	{ FTD_TID_RtnSyslogEventTopic, 1, FTDRtnSyslogEventTopicFieldUse }
		,
	{ FTD_TID_ReqQrySyslogEventSubcriberTopic, 1, FTDReqQrySyslogEventSubcriberTopicFieldUse }
		,
	{ FTD_TID_ReqQryTradeDayChangeTopic, 1, FTDReqQryTradeDayChangeTopicFieldUse }
		,
	{ FTD_TID_RspQryTradeDayChangeTopic, 2, FTDRspQryTradeDayChangeTopicFieldUse }
		,
	{ FTD_TID_ReqQryTomcatInfoTopic, 1, FTDReqQryTomcatInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryWebAppInfoTopic, 2, FTDRspQryWebAppInfoTopicFieldUse }
		,
	{ FTD_TID_RtnWebAppInfoTopic, 1, FTDRtnWebAppInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryServletInfoTopic, 2, FTDRspQryServletInfoTopicFieldUse }
		,
	{ FTD_TID_RtnServletInfoTopic, 1, FTDRtnServletInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryFileInfoTopic, 2, FTDRspQryFileInfoTopicFieldUse }
		,
	{ FTD_TID_RtnFileInfoTopic, 1, FTDRtnFileInfoTopicFieldUse }
		,
	{ FTD_TID_RspQrySessionInfoTopic, 2, FTDRspQrySessionInfoTopicFieldUse }
		,
	{ FTD_TID_RtnSessionInfoTopic, 1, FTDRtnSessionInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryJDBCInfoTopic, 2, FTDRspQryJDBCInfoTopicFieldUse }
		,
	{ FTD_TID_RtnJDBCInfoTopic, 1, FTDRtnJDBCInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryThreadInfoTopic, 2, FTDRspQryThreadInfoTopicFieldUse }
		,
	{ FTD_TID_RtnThreadInfoTopic, 1, FTDRtnThreadInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQryVMInfoTopic, 1, FTDReqQryVMInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryVMInfoTopic, 2, FTDRspQryVMInfoTopicFieldUse }
		,
	{ FTD_TID_RtnVMInfoTopic, 1, FTDRtnVMInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQryPropertyInfoTopic, 1, FTDReqQryPropertyInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryPropertyInfoTopic, 2, FTDRspQryPropertyInfoTopicFieldUse }
		,
	{ FTD_TID_RtnPropertyInfoTopic, 1, FTDRtnPropertyInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQryMemPoolInfoTopic, 1, FTDReqQryMemPoolInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryMemPoolInfoTopic, 2, FTDRspQryMemPoolInfoTopicFieldUse }
		,
	{ FTD_TID_RtnMemPoolInfoTopic, 1, FTDRtnMemPoolInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQryFileContentInfoTopic, 1, FTDReqQryFileContentInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryFileContentInfoTopic, 2, FTDRspQryFileContentInfoTopicFieldUse }
		,
	{ FTD_TID_RtnFileContentInfoTopic, 1, FTDRtnFileContentInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQryConnectionInfoTopic, 1, FTDReqQryConnectionInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryConnectionInfoTopic, 2, FTDRspQryConnectionInfoTopicFieldUse }
		,
	{ FTD_TID_RtnConnectionInfoTopic, 1, FTDRtnConnectionInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQryConnectorInfoTopic, 1, FTDReqQryConnectorInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryConnectorInfoTopic, 2, FTDRspQryConnectorInfoTopicFieldUse }
		,
	{ FTD_TID_RtnConnectorInfoTopic, 1, FTDRtnConnectorInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQryDBQueryTopic, 1, FTDReqQryDBQueryTopicFieldUse }
		,
	{ FTD_TID_RspQryDBQueryTopic, 2, FTDRspQryDBQueryTopicFieldUse }
		,
	{ FTD_TID_RtnDBQueryTopic, 1, FTDRtnDBQueryTopicFieldUse }
		,
	{ FTD_TID_RspQryGeneralFieldTopic, 2, FTDRspQryGeneralFieldTopicFieldUse }
		,
	{ FTD_TID_RtnGeneralFieldTopic, 1, FTDRtnGeneralFieldTopicFieldUse }
		,
	{ FTD_TID_ReqQryGetFileTopic, 1, FTDReqQryGetFileTopicFieldUse }
		,
	{ FTD_TID_RspQryGetFileTopic, 2, FTDRspQryGetFileTopicFieldUse }
		,
	{ FTD_TID_ReqQrySyslogEventUpdateTopic, 1, FTDReqQrySyslogEventUpdateTopicFieldUse }
		,
	{ FTD_TID_ReqQryWarningQueryTopic, 1, FTDReqQryWarningQueryTopicFieldUse }
		,
	{ FTD_TID_RspQryWarningQueryTopic, 2, FTDRspQryWarningQueryTopicFieldUse }
		,
	{ FTD_TID_RtnWarningQueryTopic, 1, FTDRtnWarningQueryTopicFieldUse }
		,
	{ FTD_TID_ReqQryWebVisitTopic, 1, FTDReqQryWebVisitTopicFieldUse }
		,
	{ FTD_TID_RtnHostConfig, 1, FTDRtnHostConfigFieldUse }
		,
	{ FTD_TID_ReqQryWarningActiveChange, 1, FTDReqQryWarningActiveChangeFieldUse }
		,
	{ FTD_TID_RspQryWarningActiveChange, 1, FTDRspQryWarningActiveChangeFieldUse }
		,
	{ FTD_TID_RtnWarningActiveChange, 1, FTDRtnWarningActiveChangeFieldUse }
		,
	{ FTD_TID_ReqQryGeneralOperateTopic, 1, FTDReqQryGeneralOperateTopicFieldUse }
		,
	{ FTD_TID_RspQryGeneralOperateTopic, 2, FTDRspQryGeneralOperateTopicFieldUse }
		,
	{ FTD_TID_RtnGeneralOperateTopic, 1, FTDRtnGeneralOperateTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetDeviceLinkedTopic, 1, FTDReqQryNetDeviceLinkedTopicFieldUse }
		,
	{ FTD_TID_RspQryNetDeviceLinkedTopic, 2, FTDRspQryNetDeviceLinkedTopicFieldUse }
		,
	{ FTD_TID_RtnNetDeviceLinkedTopic, 1, FTDRtnNetDeviceLinkedTopicFieldUse }
		,
	{ FTD_TID_ReqQryTradeUserLoginStatTopic, 1, FTDReqQryTradeUserLoginStatTopicFieldUse }
		,
	{ FTD_TID_RspQryTradeUserLoginStatTopic, 2, FTDRspQryTradeUserLoginStatTopicFieldUse }
		,
	{ FTD_TID_ReqQryTradeFrontOrderRttStatTopic, 1, FTDReqQryTradeFrontOrderRttStatTopicFieldUse }
		,
	{ FTD_TID_RspQryTradeFrontOrderRttStatTopic, 2, FTDRspQryTradeFrontOrderRttStatTopicFieldUse }
		,
	{ FTD_TID_RtnTradeFrontOrderRttStatTopic, 1, FTDRtnTradeFrontOrderRttStatTopicFieldUse }
		,
	{ FTD_TID_ReqQryParticTradeOrderStatesTopic, 1, FTDReqQryParticTradeOrderStatesTopicFieldUse }
		,
	{ FTD_TID_RspQryParticTradeOrderStatesTopic, 2, FTDRspQryParticTradeOrderStatesTopicFieldUse }
		,
	{ FTD_TID_RtnParticTradeOrderStatesTopic, 1, FTDRtnParticTradeOrderStatesTopicFieldUse }
		,
	{ FTD_TID_ReqQryRouterInfoTopic, 1, FTDReqQryRouterInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryRouterInfoTopic, 2, FTDRspQryRouterInfoTopicFieldUse }
		,
	{ FTD_TID_RtnRouterInfoTopic, 1, FTDRtnRouterInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQryDiskIOTopic, 1, FTDReqQryDiskIOTopicFieldUse }
		,
	{ FTD_TID_RspQryDiskIOTopic, 2, FTDRspQryDiskIOTopicFieldUse }
		,
	{ FTD_TID_RtnDiskIOTopic, 1, FTDRtnDiskIOTopicFieldUse }
		,
	{ FTD_TID_ReqQryStatInfoTopic, 1, FTDReqQryStatInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryStatInfoTopic, 2, FTDRspQryStatInfoTopicFieldUse }
		,
	{ FTD_TID_RtnStatInfoTopic, 1, FTDRtnStatInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQryTradeOrderRttCutLineTopic, 1, FTDReqQryTradeOrderRttCutLineTopicFieldUse }
		,
	{ FTD_TID_RspQryTradeOrderRttCutLineTopic, 2, FTDRspQryTradeOrderRttCutLineTopicFieldUse }
		,
	{ FTD_TID_RtnTradeOrderRttCutLineTopic, 1, FTDRtnTradeOrderRttCutLineTopicFieldUse }
		,
	{ FTD_TID_ReqQryClientInfoTopic, 1, FTDReqQryClientInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryClientInfoTopic, 2, FTDRspQryClientInfoTopicFieldUse }
		,
	{ FTD_TID_RtnClientInfoTopic, 1, FTDRtnClientInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQryEventDescriptionTopic, 1, FTDReqQryEventDescriptionTopicFieldUse }
		,
	{ FTD_TID_RspQryEventDescriptionTopic, 2, FTDRspQryEventDescriptionTopicFieldUse }
		,
	{ FTD_TID_RtnEventDescriptionTopic, 1, FTDRtnEventDescriptionTopicFieldUse }
		,
	{ FTD_TID_ReqQryFrontUniqueIDTopic, 1, FTDReqQryFrontUniqueIDTopicFieldUse }
		,
	{ FTD_TID_RspQryFrontUniqueIDTopic, 2, FTDRspQryFrontUniqueIDTopicFieldUse }
		,
	{ FTD_TID_RtnFrontUniqueIDTopic, 1, FTDRtnFrontUniqueIDTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetPartyLinkAddrChangeTopic, 1, FTDReqQryNetPartyLinkAddrChangeTopicFieldUse }
		,
	{ FTD_TID_RspQryNetPartyLinkAddrChangeTopic, 2, FTDRspQryNetPartyLinkAddrChangeTopicFieldUse }
		,
	{ FTD_TID_RtnNetPartyLinkAddrChangeTopic, 1, FTDRtnNetPartyLinkAddrChangeTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetDelPartyLinkInfoTopic, 1, FTDReqQryNetDelPartyLinkInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryNetDelPartyLinkInfoTopic, 2, FTDRspQryNetDelPartyLinkInfoTopicFieldUse }
		,
	{ FTD_TID_RtnNetDelPartyLinkInfoTopic, 1, FTDRtnNetDelPartyLinkInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQryPerformanceTopTopic, 1, FTDReqQryPerformanceTopTopicFieldUse }
		,
	{ FTD_TID_RspQryPerformanceTopTopic, 2, FTDRspQryPerformanceTopTopicFieldUse }
		,
	{ FTD_TID_RtnPerformanceTopTopic, 1, FTDRtnPerformanceTopTopicFieldUse }
		,
	{ FTD_TID_ReqQryInstrumentStatusTopic, 1, FTDReqQryInstrumentStatusTopicFieldUse }
		,
	{ FTD_TID_RspQryInstrumentStatusTopic, 2, FTDRspQryInstrumentStatusTopicFieldUse }
		,
	{ FTD_TID_RtnInstrumentStatusTopic, 1, FTDRtnInstrumentStatusTopicFieldUse }
		,
	{ FTD_TID_ReqQryCurrTradingSegmentAttrTopic, 1, FTDReqQryCurrTradingSegmentAttrTopicFieldUse }
		,
	{ FTD_TID_RspQryCurrTradingSegmentAttrTopic, 2, FTDRspQryCurrTradingSegmentAttrTopicFieldUse }
		,
	{ FTD_TID_RtnCurrTradingSegmentAttrTopic, 1, FTDRtnCurrTradingSegmentAttrTopicFieldUse }
		,
	{ FTD_TID_ReqQryRealTimeNetObjectAttrTopic, 1, FTDReqQryRealTimeNetObjectAttrTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetAreaTopic, 1, FTDReqQryNetAreaTopicFieldUse }
		,
	{ FTD_TID_RspQryNetAreaTopic, 2, FTDRspQryNetAreaTopicFieldUse }
		,
	{ FTD_TID_RtnNetAreaTopic, 1, FTDRtnNetAreaTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetSubAreaTopic, 1, FTDReqQryNetSubAreaTopicFieldUse }
		,
	{ FTD_TID_RspQryNetSubAreaTopic, 2, FTDRspQryNetSubAreaTopicFieldUse }
		,
	{ FTD_TID_RtnNetSubAreaTopic, 1, FTDRtnNetSubAreaTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetSubAreaIPTopic, 1, FTDReqQryNetSubAreaIPTopicFieldUse }
		,
	{ FTD_TID_RspQryNetSubAreaIPTopic, 2, FTDRspQryNetSubAreaIPTopicFieldUse }
		,
	{ FTD_TID_RtnNetSubAreaIPTopic, 1, FTDRtnNetSubAreaIPTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetDeviceDetectTopic, 1, FTDReqQryNetDeviceDetectTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetDeviceRequestTopic, 1, FTDReqQryNetDeviceRequestTopicFieldUse }
		,
	{ FTD_TID_RspQryNetDeviceTopic, 2, FTDRspQryNetDeviceTopicFieldUse }
		,
	{ FTD_TID_RtnNetDeviceTopic, 1, FTDRtnNetDeviceTopicFieldUse }
		,
	{ FTD_TID_RspQryNetDeviceDetectTopic, 2, FTDRspQryNetDeviceDetectTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetBuildingTopic, 1, FTDReqQryNetBuildingTopicFieldUse }
		,
	{ FTD_TID_RspQryNetBuildingTopic, 2, FTDRspQryNetBuildingTopicFieldUse }
		,
	{ FTD_TID_RtnNetBuildingTopic, 1, FTDRtnNetBuildingTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetRoomTopic, 1, FTDReqQryNetRoomTopicFieldUse }
		,
	{ FTD_TID_RspQryNetRoomTopic, 2, FTDRspQryNetRoomTopicFieldUse }
		,
	{ FTD_TID_RtnNetRoomTopic, 1, FTDRtnNetRoomTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetCabinetsTopic, 1, FTDReqQryNetCabinetsTopicFieldUse }
		,
	{ FTD_TID_RspQryNetCabinetsTopic, 2, FTDRspQryNetCabinetsTopicFieldUse }
		,
	{ FTD_TID_RtnNetCabinetsTopic, 1, FTDRtnNetCabinetsTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetOIDTopic, 1, FTDReqQryNetOIDTopicFieldUse }
		,
	{ FTD_TID_RspQryNetOIDTopic, 2, FTDRspQryNetOIDTopicFieldUse }
		,
	{ FTD_TID_RtnNetOIDTopic, 1, FTDRtnNetOIDTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetTimePolicyTopic, 1, FTDReqQryNetTimePolicyTopicFieldUse }
		,
	{ FTD_TID_RspQryNetTimePolicyTopic, 2, FTDRspQryNetTimePolicyTopicFieldUse }
		,
	{ FTD_TID_RtnNetTimePolicyTopic, 1, FTDRtnNetTimePolicyTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetGatherTaskTopic, 1, FTDReqQryNetGatherTaskTopicFieldUse }
		,
	{ FTD_TID_RspQryNetGatherTaskTopic, 2, FTDRspQryNetGatherTaskTopicFieldUse }
		,
	{ FTD_TID_RtnNetGatherTaskTopic, 1, FTDRtnNetGatherTaskTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetDeviceChgTopic, 1, FTDReqQryNetDeviceChgTopicFieldUse }
		,
	{ FTD_TID_RspQryNetDeviceChgTopic, 2, FTDRspQryNetDeviceChgTopicFieldUse }
		,
	{ FTD_TID_RtnNetDeviceChgTopic, 1, FTDRtnNetDeviceChgTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetDeviceTypeTopic, 1, FTDReqQryNetDeviceTypeTopicFieldUse }
		,
	{ FTD_TID_RspQryNetDeviceTypeTopic, 2, FTDRspQryNetDeviceTypeTopicFieldUse }
		,
	{ FTD_TID_RtnNetDeviceTypeTopic, 1, FTDRtnNetDeviceTypeTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetDeviceCategoryTopic, 1, FTDReqQryNetDeviceCategoryTopicFieldUse }
		,
	{ FTD_TID_RspQryNetDeviceCategoryTopic, 2, FTDRspQryNetDeviceCategoryTopicFieldUse }
		,
	{ FTD_TID_RtnNetDeviceCategoryTopic, 1, FTDRtnNetDeviceCategoryTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetManufactoryTopic, 1, FTDReqQryNetManufactoryTopicFieldUse }
		,
	{ FTD_TID_RspQryNetManufactoryTopic, 2, FTDRspQryNetManufactoryTopicFieldUse }
		,
	{ FTD_TID_RtnNetManufactoryTopic, 1, FTDRtnNetManufactoryTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetCommunityTopic, 1, FTDReqQryNetCommunityTopicFieldUse }
		,
	{ FTD_TID_RspQryNetCommunityTopic, 2, FTDRspQryNetCommunityTopicFieldUse }
		,
	{ FTD_TID_RtnNetCommunityTopic, 1, FTDRtnNetCommunityTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetPortTypeTopic, 1, FTDReqQryNetPortTypeTopicFieldUse }
		,
	{ FTD_TID_RspQryNetPortTypeTopic, 2, FTDRspQryNetPortTypeTopicFieldUse }
		,
	{ FTD_TID_RtnNetPortTypeTopic, 1, FTDRtnNetPortTypeTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetPartAccessSpotTopic, 1, FTDReqQryNetPartAccessSpotTopicFieldUse }
		,
	{ FTD_TID_RspQryNetPartAccessSpotTopic, 2, FTDRspQryNetPartAccessSpotTopicFieldUse }
		,
	{ FTD_TID_RtnNetPartAccessSpotTopic, 1, FTDRtnNetPartAccessSpotTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetInterfaceTopic, 1, FTDReqQryNetInterfaceTopicFieldUse }
		,
	{ FTD_TID_RspQryNetInterfaceTopic, 2, FTDRspQryNetInterfaceTopicFieldUse }
		,
	{ FTD_TID_RtnNetInterfaceTopic, 1, FTDRtnNetInterfaceTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetGeneralOIDTopic, 1, FTDReqQryNetGeneralOIDTopicFieldUse }
		,
	{ FTD_TID_RspQryNetGeneralOIDTopic, 2, FTDRspQryNetGeneralOIDTopicFieldUse }
		,
	{ FTD_TID_RtnNetGeneralOIDTopic, 1, FTDRtnNetGeneralOIDTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetMonitorTypeTopic, 1, FTDReqQryNetMonitorTypeTopicFieldUse }
		,
	{ FTD_TID_RspQryNetMonitorTypeTopic, 2, FTDRspQryNetMonitorTypeTopicFieldUse }
		,
	{ FTD_TID_RtnNetMonitorTypeTopic, 1, FTDRtnNetMonitorTypeTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetMonitorAttrScopeTopic, 1, FTDReqQryNetMonitorAttrScopeTopicFieldUse }
		,
	{ FTD_TID_RspQryNetMonitorAttrScopeTopic, 2, FTDRspQryNetMonitorAttrScopeTopicFieldUse }
		,
	{ FTD_TID_RtnNetMonitorAttrScopeTopic, 1, FTDRtnNetMonitorAttrScopeTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetMonitorAttrTypeTopic, 1, FTDReqQryNetMonitorAttrTypeTopicFieldUse }
		,
	{ FTD_TID_RspQryNetMonitorAttrTypeTopic, 2, FTDRspQryNetMonitorAttrTypeTopicFieldUse }
		,
	{ FTD_TID_RtnNetMonitorAttrTypeTopic, 1, FTDRtnNetMonitorAttrTypeTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetMonitorObjectAttrTopic, 1, FTDReqQryNetMonitorObjectAttrTopicFieldUse }
		,
	{ FTD_TID_RspQryNetMonitorObjectAttrTopic, 2, FTDRspQryNetMonitorObjectAttrTopicFieldUse }
		,
	{ FTD_TID_RtnNetMonitorObjectAttrTopic, 1, FTDRtnNetMonitorObjectAttrTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetFuncAreaTopic, 1, FTDReqQryNetFuncAreaTopicFieldUse }
		,
	{ FTD_TID_RspQryNetFuncAreaTopic, 2, FTDRspQryNetFuncAreaTopicFieldUse }
		,
	{ FTD_TID_RtnNetFuncAreaTopic, 1, FTDRtnNetFuncAreaTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetMonitorCommandTypeTopic, 1, FTDReqQryNetMonitorCommandTypeTopicFieldUse }
		,
	{ FTD_TID_RspQryNetMonitorCommandTypeTopic, 2, FTDRspQryNetMonitorCommandTypeTopicFieldUse }
		,
	{ FTD_TID_RtnNetMonitorCommandTypeTopic, 1, FTDRtnNetMonitorCommandTypeTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetMonitorActionGroupTopic, 1, FTDReqQryNetMonitorActionGroupTopicFieldUse }
		,
	{ FTD_TID_RspQryNetMonitorActionGroupTopic, 2, FTDRspQryNetMonitorActionGroupTopicFieldUse }
		,
	{ FTD_TID_RtnNetMonitorActionGroupTopic, 1, FTDRtnNetMonitorActionGroupTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetMonitorDeviceGroupTopic, 1, FTDReqQryNetMonitorDeviceGroupTopicFieldUse }
		,
	{ FTD_TID_RspQryNetMonitorDeviceGroupTopic, 2, FTDRspQryNetMonitorDeviceGroupTopicFieldUse }
		,
	{ FTD_TID_RtnNetMonitorDeviceGroupTopic, 1, FTDRtnNetMonitorDeviceGroupTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetMonitorTaskInfoTopic, 1, FTDReqQryNetMonitorTaskInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryNetMonitorTaskInfoTopic, 2, FTDRspQryNetMonitorTaskInfoTopicFieldUse }
		,
	{ FTD_TID_RtnNetMonitorTaskInfoTopic, 1, FTDRtnNetMonitorTaskInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetMonitorTaskResultTopic, 1, FTDReqQryNetMonitorTaskResultTopicFieldUse }
		,
	{ FTD_TID_RspQryNetMonitorTaskResultTopic, 2, FTDRspQryNetMonitorTaskResultTopicFieldUse }
		,
	{ FTD_TID_RtnNetMonitorTaskResultTopic, 1, FTDRtnNetMonitorTaskResultTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetMonitorTaskObjectSetTopic, 1, FTDReqQryNetMonitorTaskObjectSetTopicFieldUse }
		,
	{ FTD_TID_RspQryNetMonitorTaskObjectSetTopic, 2, FTDRspQryNetMonitorTaskObjectSetTopicFieldUse }
		,
	{ FTD_TID_RtnNetMonitorTaskObjectSetTopic, 1, FTDRtnNetMonitorTaskObjectSetTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetPartyLinkInfoTopic, 1, FTDReqQryNetPartyLinkInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryNetPartyLinkInfoTopic, 2, FTDRspQryNetPartyLinkInfoTopicFieldUse }
		,
	{ FTD_TID_RtnNetPartyLinkInfoTopic, 1, FTDRtnNetPartyLinkInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetMonitorActionAttrTopic, 1, FTDReqQryNetMonitorActionAttrTopicFieldUse }
		,
	{ FTD_TID_RspQryNetMonitorActionAttrTopic, 2, FTDRspQryNetMonitorActionAttrTopicFieldUse }
		,
	{ FTD_TID_RtnNetMonitorActionAttrTopic, 1, FTDRtnNetMonitorActionAttrTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetModuleTopic, 1, FTDReqQryNetModuleTopicFieldUse }
		,
	{ FTD_TID_RspQryNetModuleTopic, 2, FTDRspQryNetModuleTopicFieldUse }
		,
	{ FTD_TID_RtnNetModuleTopic, 1, FTDRtnNetModuleTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetEventExprTopic, 1, FTDReqQryNetEventExprTopicFieldUse }
		,
	{ FTD_TID_RspQryNetEventExprTopic, 2, FTDRspQryNetEventExprTopicFieldUse }
		,
	{ FTD_TID_RtnNetEventExprTopic, 1, FTDRtnNetEventExprTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetEventTypeTopic, 1, FTDReqQryNetEventTypeTopicFieldUse }
		,
	{ FTD_TID_RspQryNetEventTypeTopic, 2, FTDRspQryNetEventTypeTopicFieldUse }
		,
	{ FTD_TID_RtnNetEventTypeTopic, 1, FTDRtnNetEventTypeTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetSubEventTypeTopic, 1, FTDReqQryNetSubEventTypeTopicFieldUse }
		,
	{ FTD_TID_RspQryNetSubEventTypeTopic, 2, FTDRspQryNetSubEventTypeTopicFieldUse }
		,
	{ FTD_TID_RtnNetSubEventTypeTopic, 1, FTDRtnNetSubEventTypeTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetEventLevelTopic, 1, FTDReqQryNetEventLevelTopicFieldUse }
		,
	{ FTD_TID_RspQryNetEventLevelTopic, 2, FTDRspQryNetEventLevelTopicFieldUse }
		,
	{ FTD_TID_RtnNetEventLevelTopic, 1, FTDRtnNetEventLevelTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetMonitorTaskStatusResultTopic, 1, FTDReqQryNetMonitorTaskStatusResultTopicFieldUse }
		,
	{ FTD_TID_RspQryNetMonitorTaskStatusResultTopic, 2, FTDRspQryNetMonitorTaskStatusResultTopicFieldUse }
		,
	{ FTD_TID_RtnNetMonitorTaskStatusResultTopic, 1, FTDRtnNetMonitorTaskStatusResultTopicFieldUse }
		,
	{ FTD_TID_ReqConfigLoginTopic, 1, FTDReqConfigLoginTopicFieldUse }
		,
	{ FTD_TID_RspConfigLoginTopic, 1, FTDRspConfigLoginTopicFieldUse }
		,
	{ FTD_TID_RspServerTypeTopic, 1, FTDRspServerTypeTopicFieldUse }
		,
	{ FTD_TID_ReqSysServerExitTopic, 1, FTDReqSysServerExitTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetCfgFileTopic, 1, FTDReqQryNetCfgFileTopicFieldUse }
		,
	{ FTD_TID_RspQryNetCfgFileTopic, 2, FTDRspQryNetCfgFileTopicFieldUse }
		,
	{ FTD_TID_RtnNetCfgFileTopic, 1, FTDRtnNetCfgFileTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetMonitorDeviceTaskTopic, 1, FTDReqQryNetMonitorDeviceTaskTopicFieldUse }
		,
	{ FTD_TID_RspQryNetMonitorDeviceTaskTopic, 2, FTDRspQryNetMonitorDeviceTaskTopicFieldUse }
		,
	{ FTD_TID_RtnNetMonitorDeviceTaskTopic, 1, FTDRtnNetMonitorDeviceTaskTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetMonitorTaskInstAttrsTopic, 1, FTDReqQryNetMonitorTaskInstAttrsTopicFieldUse }
		,
	{ FTD_TID_RspQryNetMonitorTaskInstAttrsTopic, 2, FTDRspQryNetMonitorTaskInstAttrsTopicFieldUse }
		,
	{ FTD_TID_RtnNetMonitorTaskInstAttrsTopic, 1, FTDRtnNetMonitorTaskInstAttrsTopicFieldUse }
		,
	{ FTD_TID_ReqQryFileGeneralOperTopic, 1, FTDReqQryFileGeneralOperTopicFieldUse }
		,
	{ FTD_TID_RspQryFileGeneralOperTopic, 2, FTDRspQryFileGeneralOperTopicFieldUse }
		,
	{ FTD_TID_RtnFileGeneralOperTopic, 1, FTDRtnFileGeneralOperTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetBaseLineTopic, 1, FTDReqQryNetBaseLineTopicFieldUse }
		,
	{ FTD_TID_RspQryNetBaseLineTopic, 2, FTDRspQryNetBaseLineTopicFieldUse }
		,
	{ FTD_TID_RtnNetBaseLineTopic, 1, FTDRtnNetBaseLineTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetBaseLineTaskTopic, 1, FTDReqQryNetBaseLineTaskTopicFieldUse }
		,
	{ FTD_TID_RspQryNetBaseLineTaskTopic, 2, FTDRspQryNetBaseLineTaskTopicFieldUse }
		,
	{ FTD_TID_RtnNetBaseLineTaskTopic, 1, FTDRtnNetBaseLineTaskTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetBaseLineResultTopic, 1, FTDReqQryNetBaseLineResultTopicFieldUse }
		,
	{ FTD_TID_RspQryNetBaseLineResultTopic, 2, FTDRspQryNetBaseLineResultTopicFieldUse }
		,
	{ FTD_TID_RtnNetBaseLineResultTopic, 1, FTDRtnNetBaseLineResultTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetPartyLinkStatusInfoTopic, 1, FTDReqQryNetPartyLinkStatusInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryNetPartyLinkStatusInfoTopic, 2, FTDRspQryNetPartyLinkStatusInfoTopicFieldUse }
		,
	{ FTD_TID_RtnNetPartyLinkStatusInfoTopic, 1, FTDRtnNetPartyLinkStatusInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetMemberSDHLineInfoTopic, 1, FTDReqQryNetMemberSDHLineInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryNetMemberSDHLineInfoTopic, 2, FTDRspQryNetMemberSDHLineInfoTopicFieldUse }
		,
	{ FTD_TID_RtnNetMemberSDHLineInfoTopic, 1, FTDRtnNetMemberSDHLineInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetDDNLinkInfoTopic, 1, FTDReqQryNetDDNLinkInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryNetDDNLinkInfoTopic, 2, FTDRspQryNetDDNLinkInfoTopicFieldUse }
		,
	{ FTD_TID_RtnNetDDNLinkInfoTopic, 1, FTDRtnNetDDNLinkInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetPseudMemberLinkInfoTopic, 1, FTDReqQryNetPseudMemberLinkInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryNetPseudMemberLinkInfoTopic, 2, FTDRspQryNetPseudMemberLinkInfoTopicFieldUse }
		,
	{ FTD_TID_RtnNetPseudMemberLinkInfoTopic, 1, FTDRtnNetPseudMemberLinkInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQryOuterDeviceInfTopic, 1, FTDReqQryOuterDeviceInfTopicFieldUse }
		,
	{ FTD_TID_RspQryOuterDeviceInfTopic, 2, FTDRspQryOuterDeviceInfTopicFieldUse }
		,
	{ FTD_TID_RtnNetOuterDeviceInfTopic, 1, FTDRtnNetOuterDeviceInfTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetLocalPingResultInfoTopic, 1, FTDReqQryNetLocalPingResultInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryNetLocalPingResultInfoTopic, 2, FTDRspQryNetLocalPingResultInfoTopicFieldUse }
		,
	{ FTD_TID_RtnNetLocalPingResultInfoTopic, 1, FTDRtnNetLocalPingResultInfoTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetRomotePingResultInfoTopic, 1, FTDReqQryNetRomotePingResultInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryNetRomotePingResultInfoTopic, 2, FTDRspQryNetRomotePingResultInfoTopicFieldUse }
		,
	{ FTD_TID_RtnNetRomotePingResultInfoTopic, 1, FTDRtnNetRomotePingResultInfoTopicFieldUse }
		,
	{ FTD_TID_RtnMonitorTopProcessInfo, 1, FTDRtnMonitorTopProcessInfoFieldUse }
		,
	{ FTD_TID_ReqQrySysInternalTopologyTopic, 1, FTDReqQrySysInternalTopologyTopicFieldUse }
		,
	{ FTD_TID_RspQrySysInternalTopologyTopic, 2, FTDRspQrySysInternalTopologyTopicFieldUse }
		,
	{ FTD_TID_RtnSysInternalTopologyTopic, 1, FTDRtnSysInternalTopologyTopicFieldUse }
		,
	{ FTD_TID_ReqQryMemberLinkCostTopic, 1, FTDReqQryMemberLinkCostTopicFieldUse }
		,
	{ FTD_TID_RspQryMemberLinkCostTopic, 2, FTDRspQryMemberLinkCostTopicFieldUse }
		,
	{ FTD_TID_RtnMemberLinkCostTopic, 1, FTDRtnMemberLinkCostTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetPartylinkMonthlyRentTopic, 1, FTDReqQryNetPartylinkMonthlyRentTopicFieldUse }
		,
	{ FTD_TID_RspQryNetPartylinkMonthlyRentTopic, 2, FTDRspQryNetPartylinkMonthlyRentTopicFieldUse }
		,
	{ FTD_TID_RtnNetPartylinkMonthlyRentTopic, 1, FTDRtnNetPartylinkMonthlyRentTopicFieldUse }
		,
	{ FTD_TID_ReqQryNetNonPartyLinkInfoTopic, 1, FTDReqQryNetNonPartyLinkInfoTopicFieldUse }
		,
	{ FTD_TID_RspQryNetNonPartyLinkInfoTopic, 2, FTDRspQryNetNonPartyLinkInfoTopicFieldUse }
		,
	{ FTD_TID_RtnNetNonPartyLinkInfoTopic, 1, FTDRtnNetNonPartyLinkInfoTopicFieldUse }
};



class CFTDCPackageDefineMap: public CHashMap<DWORD, TPackageDefine *, HashInt>
{
public:
	CFTDCPackageDefineMap(TPackageDefine *pFTDCPackageDefines, int nDefineCount)
	{
		for(int i=0; i<nDefineCount; i++)
		{
			Insert(pFTDCPackageDefines->tid, pFTDCPackageDefines);
			pFTDCPackageDefines++;
		}
	}
};

CFTDCPackageDefineMap g_FTDCPackageDefineMap(FTDPackageDefines, sizeof(FTDPackageDefines)/ sizeof(TPackageDefine));

void FTDC_DEBUG_BODY(DWORD tid, CFieldSet *pPackage, CLogger *pLogger)
{
	pLogger->output("\tFTDC PACKAGE CONTENT START\n");					
	TPackageDefine **pFind = g_FTDCPackageDefineMap.Find(tid);	
	if(pFind == NULL)													
	{																	
		pLogger->output("\tCan't find package define [0x%08x]\n", tid);				
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
	pLogger->output("\tFTDC PACKAGE CONTENT END\n");						
}
