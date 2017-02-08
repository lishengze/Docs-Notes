/////////////////////////////////////////////////////////////////////////
///@system 新一代交易所系统
///@company 上海期货信息技术有限公司
///@file FtdcUserApiImpl.cpp
///@brief 实现了客户端接口
///@history 
///20060106	赵鸿昊		创建该文件
// 20110624 江鹏        NT-0139 加快响应时间
// 20120726 江鹏        对于不安全函数进行了对应安全版本的封装：localtime
// 20120807 孙尧宇      NT-0170 对流控和日志进行完善
/////////////////////////////////////////////////////////////////////////

#include "public.h"
#include "FtdcUserApiImpl.h"
CFtdcUserApiImpl::CFtdcUserApiImpl(const char *pszFlowPath, const char *pszUserApiType, CSelectReactor *pReactor)
:CFtdcUserApiImplBase(pszFlowPath, pszUserApiType, pReactor)
{
}

///用户退出请求
int CFtdcUserApiImpl::ReqUserLogout(CShfeFtdcReqUserLogoutField *pReqUserLogout, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqUserLogout, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqUserLogoutField ReqUserLogoutField;
	memcpy(&ReqUserLogoutField, pReqUserLogout, sizeof(CFTDReqUserLogoutField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqUserLogoutField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqUserLogout,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pReqUserLogout, &CFTDReqUserLogoutField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///报单录入请求
int CFtdcUserApiImpl::ReqOrderInsert(CShfeFtdcInputOrderField *pInputOrder, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqOrderInsert, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDInputOrderField InputOrderField;
	memcpy(&InputOrderField, pInputOrder, sizeof(CFTDInputOrderField));
	FTDC_ADD_FIELD(&m_reqPackage, &InputOrderField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqOrderInsert,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pInputOrder, &CFTDInputOrderField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///报单操作请求
int CFtdcUserApiImpl::ReqOrderAction(CShfeFtdcOrderActionField *pOrderAction, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqOrderAction, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDOrderActionField OrderActionField;
	memcpy(&OrderActionField, pOrderAction, sizeof(CFTDOrderActionField));
	FTDC_ADD_FIELD(&m_reqPackage, &OrderActionField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqOrderAction,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pOrderAction, &CFTDOrderActionField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///报价录入请求
int CFtdcUserApiImpl::ReqQuoteInsert(CShfeFtdcInputQuoteField *pInputQuote, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQuoteInsert, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDInputQuoteField InputQuoteField;
	memcpy(&InputQuoteField, pInputQuote, sizeof(CFTDInputQuoteField));
	FTDC_ADD_FIELD(&m_reqPackage, &InputQuoteField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqQuoteInsert,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pInputQuote, &CFTDInputQuoteField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///报价操作请求
int CFtdcUserApiImpl::ReqQuoteAction(CShfeFtdcQuoteActionField *pQuoteAction, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQuoteAction, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQuoteActionField QuoteActionField;
	memcpy(&QuoteActionField, pQuoteAction, sizeof(CFTDQuoteActionField));
	FTDC_ADD_FIELD(&m_reqPackage, &QuoteActionField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqQuoteAction,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pQuoteAction, &CFTDQuoteActionField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///OTC报单录入请求
int CFtdcUserApiImpl::ReqOTCOrderInsert(CShfeFtdcOTCOrderField *pOTCOrder, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqOTCOrderInsert, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDOTCOrderField OTCOrderField;
	memcpy(&OTCOrderField, pOTCOrder, sizeof(CFTDOTCOrderField));
	FTDC_ADD_FIELD(&m_reqPackage, &OTCOrderField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqOTCOrderInsert,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pOTCOrder, &CFTDOTCOrderField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///用户密码修改请求
int CFtdcUserApiImpl::ReqUserPasswordUpdate(CShfeFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqUserPasswordUpdate, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDUserPasswordUpdateField UserPasswordUpdateField;
	memcpy(&UserPasswordUpdateField, pUserPasswordUpdate, sizeof(CFTDUserPasswordUpdateField));
	FTDC_ADD_FIELD(&m_reqPackage, &UserPasswordUpdateField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqUserPasswordUpdate,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pUserPasswordUpdate, &CFTDUserPasswordUpdateField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///执行宣告录入请求
int CFtdcUserApiImpl::ReqExecOrderInsert(CShfeFtdcInputExecOrderField *pInputExecOrder, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqExecOrderInsert, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDInputExecOrderField InputExecOrderField;
	memcpy(&InputExecOrderField, pInputExecOrder, sizeof(CFTDInputExecOrderField));
	FTDC_ADD_FIELD(&m_reqPackage, &InputExecOrderField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqExecOrderInsert,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pInputExecOrder, &CFTDInputExecOrderField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///执行宣告操作请求
int CFtdcUserApiImpl::ReqExecOrderAction(CShfeFtdcExecOrderActionField *pExecOrderAction, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqExecOrderAction, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDExecOrderActionField ExecOrderActionField;
	memcpy(&ExecOrderActionField, pExecOrderAction, sizeof(CFTDExecOrderActionField));
	FTDC_ADD_FIELD(&m_reqPackage, &ExecOrderActionField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqExecOrderAction,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pExecOrderAction, &CFTDExecOrderActionField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///管理报单录入请求
int CFtdcUserApiImpl::ReqAdminOrderInsert(CShfeFtdcInputAdminOrderField *pInputAdminOrder, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqAdminOrderInsert, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDInputAdminOrderField InputAdminOrderField;
	memcpy(&InputAdminOrderField, pInputAdminOrder, sizeof(CFTDInputAdminOrderField));
	FTDC_ADD_FIELD(&m_reqPackage, &InputAdminOrderField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqAdminOrderInsert,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pInputAdminOrder, &CFTDInputAdminOrderField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///非标组合报单录入请求
int CFtdcUserApiImpl::ReqCombOrderInsert(CShfeFtdcInputCombOrderField *pInputCombOrder, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqCombOrderInsert, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDInputCombOrderField InputCombOrderField;
	memcpy(&InputCombOrderField, pInputCombOrder, sizeof(CFTDInputCombOrderField));
	FTDC_ADD_FIELD(&m_reqPackage, &InputCombOrderField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqCombOrderInsert,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pInputCombOrder, &CFTDInputCombOrderField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///订阅主题请求
int CFtdcUserApiImpl::ReqSubscribeTopic(CShfeFtdcDisseminationField *pDissemination, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqSubscribeTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDDisseminationField DisseminationField;
	memcpy(&DisseminationField, pDissemination, sizeof(CFTDDisseminationField));
	FTDC_ADD_FIELD(&m_reqPackage, &DisseminationField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqSubscribeTopic,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pDissemination, &CFTDDisseminationField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///交易所公告请求
int CFtdcUserApiImpl::ReqBulletin(CShfeFtdcBulletinField *pBulletin, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqBulletin, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDBulletinField BulletinField;
	memcpy(&BulletinField, pBulletin, sizeof(CFTDBulletinField));
	FTDC_ADD_FIELD(&m_reqPackage, &BulletinField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqBulletin,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pBulletin, &CFTDBulletinField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///交易所信息请求
int CFtdcUserApiImpl::ReqInformation(CShfeFtdcInformationField *pInformation, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqInformation, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDInformationField InformationField;
	memcpy(&InformationField, pInformation, sizeof(CFTDInformationField));
	FTDC_ADD_FIELD(&m_reqPackage, &InformationField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqInformation,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pInformation, &CFTDInformationField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///合约交易状态改变请求
int CFtdcUserApiImpl::ReqInstrumentStatusUpdate(CShfeFtdcInstrumentStatusField *pInstrumentStatus, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqInstrumentStatusUpdate, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDInstrumentStatusField InstrumentStatusField;
	memcpy(&InstrumentStatusField, pInstrumentStatus, sizeof(CFTDInstrumentStatusField));
	FTDC_ADD_FIELD(&m_reqPackage, &InstrumentStatusField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqInstrumentStatusUpdate,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pInstrumentStatus, &CFTDInstrumentStatusField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///强制用户退出请求
int CFtdcUserApiImpl::ReqForceUserExit(CShfeFtdcForceUserExitField *pForceUserExit, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqForceUserExit, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDForceUserExitField ForceUserExitField;
	memcpy(&ForceUserExitField, pForceUserExit, sizeof(CFTDForceUserExitField));
	FTDC_ADD_FIELD(&m_reqPackage, &ForceUserExitField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqForceUserExit,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pForceUserExit, &CFTDForceUserExitField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///用户会话删除请求
int CFtdcUserApiImpl::ReqForceUserLogout(CShfeFtdcForceUserExitField *pForceUserExit, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqForceUserLogout, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDForceUserExitField ForceUserExitField;
	memcpy(&ForceUserExitField, pForceUserExit, sizeof(CFTDForceUserExitField));
	FTDC_ADD_FIELD(&m_reqPackage, &ForceUserExitField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqForceUserLogout,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pForceUserExit, &CFTDForceUserExitField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///交易所数据同步状态改变请求
int CFtdcUserApiImpl::ReqExchangeDataSyncStatusUpdate(CShfeFtdcExchangeDataSyncStatusField *pExchangeDataSyncStatus, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqExchangeDataSyncStatusUpdate, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDExchangeDataSyncStatusField ExchangeDataSyncStatusField;
	memcpy(&ExchangeDataSyncStatusField, pExchangeDataSyncStatus, sizeof(CFTDExchangeDataSyncStatusField));
	FTDC_ADD_FIELD(&m_reqPackage, &ExchangeDataSyncStatusField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqExchangeDataSyncStatusUpdate,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pExchangeDataSyncStatus, &CFTDExchangeDataSyncStatusField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///结算组数据同步状态改变请求
int CFtdcUserApiImpl::ReqSGDataSyncStatusUpdate(CShfeFtdcSGDataSyncStatusField *pSGDataSyncStatus, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqSGDataSyncStatusUpdate, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDSGDataSyncStatusField SGDataSyncStatusField;
	memcpy(&SGDataSyncStatusField, pSGDataSyncStatus, sizeof(CFTDSGDataSyncStatusField));
	FTDC_ADD_FIELD(&m_reqPackage, &SGDataSyncStatusField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqSGDataSyncStatusUpdate,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pSGDataSyncStatus, &CFTDSGDataSyncStatusField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///会员资金查询请求
int CFtdcUserApiImpl::ReqQryPartAccount(CShfeFtdcQryPartAccountField *pQryPartAccount, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryPartAccount, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryPartAccountField QryPartAccountField;
	memcpy(&QryPartAccountField, pQryPartAccount, sizeof(CFTDQryPartAccountField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryPartAccountField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///报单查询请求
int CFtdcUserApiImpl::ReqQryOrder(CShfeFtdcQryOrderField *pQryOrder, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryOrder, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryOrderField QryOrderField;
	memcpy(&QryOrderField, pQryOrder, sizeof(CFTDQryOrderField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryOrderField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///报价查询请求
int CFtdcUserApiImpl::ReqQryQuote(CShfeFtdcQryQuoteField *pQryQuote, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryQuote, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryQuoteField QryQuoteField;
	memcpy(&QryQuoteField, pQryQuote, sizeof(CFTDQryQuoteField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryQuoteField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///成交单查询请求
int CFtdcUserApiImpl::ReqQryTrade(CShfeFtdcQryTradeField *pQryTrade, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryTrade, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryTradeField QryTradeField;
	memcpy(&QryTradeField, pQryTrade, sizeof(CFTDQryTradeField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryTradeField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///会员客户查询请求
int CFtdcUserApiImpl::ReqQryClient(CShfeFtdcQryClientField *pQryClient, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryClient, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryClientField QryClientField;
	memcpy(&QryClientField, pQryClient, sizeof(CFTDQryClientField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryClientField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///会员持仓查询请求
int CFtdcUserApiImpl::ReqQryPartPosition(CShfeFtdcQryPartPositionField *pQryPartPosition, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryPartPosition, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryPartPositionField QryPartPositionField;
	memcpy(&QryPartPositionField, pQryPartPosition, sizeof(CFTDQryPartPositionField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryPartPositionField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///客户持仓查询请求
int CFtdcUserApiImpl::ReqQryClientPosition(CShfeFtdcQryClientPositionField *pQryClientPosition, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryClientPosition, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryClientPositionField QryClientPositionField;
	memcpy(&QryClientPositionField, pQryClientPosition, sizeof(CFTDQryClientPositionField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryClientPositionField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///合约查询请求
int CFtdcUserApiImpl::ReqQryInstrument(CShfeFtdcQryInstrumentField *pQryInstrument, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryInstrument, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryInstrumentField QryInstrumentField;
	memcpy(&QryInstrumentField, pQryInstrument, sizeof(CFTDQryInstrumentField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryInstrumentField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///合约交易状态查询请求
int CFtdcUserApiImpl::ReqQryInstrumentStatus(CShfeFtdcQryInstrumentStatusField *pQryInstrumentStatus, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryInstrumentStatus, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryInstrumentStatusField QryInstrumentStatusField;
	memcpy(&QryInstrumentStatusField, pQryInstrumentStatus, sizeof(CFTDQryInstrumentStatusField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryInstrumentStatusField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///结算组状态查询请求
int CFtdcUserApiImpl::ReqQrySGDataSyncStatus(CShfeFtdcQrySGDataSyncStatusField *pQrySGDataSyncStatus, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQrySGDataSyncStatus, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQrySGDataSyncStatusField QrySGDataSyncStatusField;
	memcpy(&QrySGDataSyncStatusField, pQrySGDataSyncStatus, sizeof(CFTDQrySGDataSyncStatusField));
	FTDC_ADD_FIELD(&m_reqPackage, &QrySGDataSyncStatusField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///保值额度查询
int CFtdcUserApiImpl::ReqQryHedgeVolume(CShfeFtdcQryHedgeVolumeField *pQryHedgeVolume, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryHedgeVolume, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryHedgeVolumeField QryHedgeVolumeField;
	memcpy(&QryHedgeVolumeField, pQryHedgeVolume, sizeof(CFTDQryHedgeVolumeField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryHedgeVolumeField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///信用限额查询请求
int CFtdcUserApiImpl::ReqQryCreditLimit(CShfeFtdcQryCreditLimitField *pQryCreditLimit, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryCreditLimit, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryCreditLimitField QryCreditLimitField;
	memcpy(&QryCreditLimitField, pQryCreditLimit, sizeof(CFTDQryCreditLimitField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryCreditLimitField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///非标组合报单查询请求
int CFtdcUserApiImpl::ReqQryCombOrder(CShfeFtdcQryCombOrderField *pQryCombOrder, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryCombOrder, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryCombOrderField QryCombOrderField;
	memcpy(&QryCombOrderField, pQryCombOrder, sizeof(CFTDQryCombOrderField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryCombOrderField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///执行宣告查询请求
int CFtdcUserApiImpl::ReqQryExecOrder(CShfeFtdcQryExecOrderField *pQryExecOrder, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryExecOrder, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryExecOrderField QryExecOrderField;
	memcpy(&QryExecOrderField, pQryExecOrder, sizeof(CFTDQryExecOrderField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryExecOrderField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///普通行情查询请求
int CFtdcUserApiImpl::ReqQryMarketData(CShfeFtdcQryMarketDataField *pQryMarketData, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMarketData, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryMarketDataField QryMarketDataField;
	memcpy(&QryMarketDataField, pQryMarketData, sizeof(CFTDQryMarketDataField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryMarketDataField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///交易所公告查询请求
int CFtdcUserApiImpl::ReqQryBulletin(CShfeFtdcQryBulletinField *pQryBulletin, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryBulletin, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryBulletinField QryBulletinField;
	memcpy(&QryBulletinField, pQryBulletin, sizeof(CFTDQryBulletinField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryBulletinField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///主题查询请求
int CFtdcUserApiImpl::ReqQryTopic(CShfeFtdcDisseminationField *pDissemination, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDDisseminationField DisseminationField;
	memcpy(&DisseminationField, pDissemination, sizeof(CFTDDisseminationField));
	FTDC_ADD_FIELD(&m_reqPackage, &DisseminationField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///用户在线查询请求
int CFtdcUserApiImpl::ReqQryUserSession(CShfeFtdcQryUserSessionField *pQryUserSession, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryUserSession, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryUserSessionField QryUserSessionField;
	memcpy(&QryUserSessionField, pQryUserSession, sizeof(CFTDQryUserSessionField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryUserSessionField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///用户查询请求
int CFtdcUserApiImpl::ReqQryUser(CShfeFtdcQryUserField *pQryUser, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryUser, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryUserField QryUserField;
	memcpy(&QryUserField, pQryUser, sizeof(CFTDQryUserField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryUserField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///会员查询请求
int CFtdcUserApiImpl::ReqQryParticipant(CShfeFtdcQryParticipantField *pQryParticipant, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryParticipant, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryParticipantField QryParticipantField;
	memcpy(&QryParticipantField, pQryParticipant, sizeof(CFTDQryParticipantField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryParticipantField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///合约价位查询
int CFtdcUserApiImpl::ReqQryMBLMarketData(CShfeFtdcQryMBLMarketDataField *pQryMBLMarketData, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMBLMarketData, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryMBLMarketDataField QryMBLMarketDataField;
	memcpy(&QryMBLMarketDataField, pQryMBLMarketData, sizeof(CFTDQryMBLMarketDataField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryMBLMarketDataField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///信息查询
int CFtdcUserApiImpl::ReqQryInformation(CShfeFtdcQryInformationField *pQryInformation, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryInformation, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryInformationField QryInformationField;
	memcpy(&QryInformationField, pQryInformation, sizeof(CFTDQryInformationField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryInformationField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///客户持仓查询请求
int CFtdcUserApiImpl::ReqQryClientPositionV1(CShfeFtdcQryClientPositionV1Field *pQryClientPositionV1, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryClientPositionV1, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryClientPositionV1Field QryClientPositionV1Field;
	memcpy(&QryClientPositionV1Field, pQryClientPositionV1, sizeof(CFTDQryClientPositionV1Field));
	FTDC_ADD_FIELD(&m_reqPackage, &QryClientPositionV1Field);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///汇率查询请求
int CFtdcUserApiImpl::ReqQryExchangeRate(CShfeFtdcQryExchangeRateField *pQryExchangeRate, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryExchangeRate, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryExchangeRateField QryExchangeRateField;
	memcpy(&QryExchangeRateField, pQryExchangeRate, sizeof(CFTDQryExchangeRateField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryExchangeRateField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}

void CFtdcUserApiImpl::HandleResponse(CFTDCPackage *pMessage, WORD nSequenceSeries)
{

	switch(pMessage->GetTID()) {
	///错误应答
	case FTD_TID_RspError:
		OnRspError(pMessage, nSequenceSeries);
		break;
	///用户登录应答
	case FTD_TID_RspUserLogin:
		OnRspUserLogin(pMessage, nSequenceSeries);
		break;
	///用户退出应答
	case FTD_TID_RspUserLogout:
		OnRspUserLogout(pMessage, nSequenceSeries);
		break;
	///报单录入应答
	case FTD_TID_RspOrderInsert:
		OnRspOrderInsert(pMessage, nSequenceSeries);
		break;
	///报单操作应答
	case FTD_TID_RspOrderAction:
		OnRspOrderAction(pMessage, nSequenceSeries);
		break;
	///报价录入应答
	case FTD_TID_RspQuoteInsert:
		OnRspQuoteInsert(pMessage, nSequenceSeries);
		break;
	///报价操作应答
	case FTD_TID_RspQuoteAction:
		OnRspQuoteAction(pMessage, nSequenceSeries);
		break;
	///OTC报单录入应答
	case FTD_TID_RspOTCOrderInsert:
		OnRspOTCOrderInsert(pMessage, nSequenceSeries);
		break;
	///用户密码修改应答
	case FTD_TID_RspUserPasswordUpdate:
		OnRspUserPasswordUpdate(pMessage, nSequenceSeries);
		break;
	///执行宣告录入应答
	case FTD_TID_RspExecOrderInsert:
		OnRspExecOrderInsert(pMessage, nSequenceSeries);
		break;
	///执行宣告操作应答
	case FTD_TID_RspExecOrderAction:
		OnRspExecOrderAction(pMessage, nSequenceSeries);
		break;
	///管理报单录入应答
	case FTD_TID_RspAdminOrderInsert:
		OnRspAdminOrderInsert(pMessage, nSequenceSeries);
		break;
	///非标组合报单录入应答
	case FTD_TID_RspCombOrderInsert:
		OnRspCombOrderInsert(pMessage, nSequenceSeries);
		break;
	///订阅主题应答
	case FTD_TID_RspSubscribeTopic:
		OnRspSubscribeTopic(pMessage, nSequenceSeries);
		break;
	///交易所公告请求应答
	case FTD_TID_RspBulletin:
		OnRspBulletin(pMessage, nSequenceSeries);
		break;
	///交易所公告信息应答
	case FTD_TID_RspInformation:
		OnRspInformation(pMessage, nSequenceSeries);
		break;
	///合约交易状态改变应答
	case FTD_TID_RspInstrumentStatusUpdate:
		OnRspInstrumentStatusUpdate(pMessage, nSequenceSeries);
		break;
	///强制用户退出应答
	case FTD_TID_RspForceUserExit:
		OnRspForceUserExit(pMessage, nSequenceSeries);
		break;
	///用户会话删除应答
	case FTD_TID_RspForceUserLogout:
		OnRspForceUserLogout(pMessage, nSequenceSeries);
		break;
	///交易所数据同步状态改变应答
	case FTD_TID_RspExchangeDataSyncStatusUpdate:
		OnRspExchangeDataSyncStatusUpdate(pMessage, nSequenceSeries);
		break;
	///结算组数据同步状态改变应答
	case FTD_TID_RspSGDataSyncStatusUpdate:
		OnRspSGDataSyncStatusUpdate(pMessage, nSequenceSeries);
		break;
	///会员资金查询应答
	case FTD_TID_RspQryPartAccount:
		OnRspQryPartAccount(pMessage, nSequenceSeries);
		break;
	///报单查询应答
	case FTD_TID_RspQryOrder:
		OnRspQryOrder(pMessage, nSequenceSeries);
		break;
	///报价查询应答
	case FTD_TID_RspQryQuote:
		OnRspQryQuote(pMessage, nSequenceSeries);
		break;
	///成交单查询应答
	case FTD_TID_RspQryTrade:
		OnRspQryTrade(pMessage, nSequenceSeries);
		break;
	///会员客户查询应答
	case FTD_TID_RspQryClient:
		OnRspQryClient(pMessage, nSequenceSeries);
		break;
	///会员持仓查询应答
	case FTD_TID_RspQryPartPosition:
		OnRspQryPartPosition(pMessage, nSequenceSeries);
		break;
	///客户持仓查询应答
	case FTD_TID_RspQryClientPosition:
		OnRspQryClientPosition(pMessage, nSequenceSeries);
		break;
	///合约查询应答
	case FTD_TID_RspQryInstrument:
		OnRspQryInstrument(pMessage, nSequenceSeries);
		break;
	///合约交易状态查询应答
	case FTD_TID_RspQryInstrumentStatus:
		OnRspQryInstrumentStatus(pMessage, nSequenceSeries);
		break;
	///结算组状态查询应答
	case FTD_TID_RspQrySGDataSyncStatus:
		OnRspQrySGDataSyncStatus(pMessage, nSequenceSeries);
		break;
	///保值额度应答
	case FTD_TID_RspQryHedgeVolume:
		OnRspQryHedgeVolume(pMessage, nSequenceSeries);
		break;
	///信用限额查询应答
	case FTD_TID_RspQryCreditLimit:
		OnRspQryCreditLimit(pMessage, nSequenceSeries);
		break;
	///非标组合报单查询应答
	case FTD_TID_RspQryCombOrder:
		OnRspQryCombOrder(pMessage, nSequenceSeries);
		break;
	///执行宣告查询应答
	case FTD_TID_RspQryExecOrder:
		OnRspQryExecOrder(pMessage, nSequenceSeries);
		break;
	///普通行情查询应答
	case FTD_TID_RspQryMarketData:
		OnRspQryMarketData(pMessage, nSequenceSeries);
		break;
	///交易所公告查询请求应答
	case FTD_TID_RspQryBulletin:
		OnRspQryBulletin(pMessage, nSequenceSeries);
		break;
	///主题查询应答
	case FTD_TID_RspQryTopic:
		OnRspQryTopic(pMessage, nSequenceSeries);
		break;
	///用户在线查询应答
	case FTD_TID_RspQryUserSession:
		OnRspQryUserSession(pMessage, nSequenceSeries);
		break;
	///用户查询应答
	case FTD_TID_RspQryUser:
		OnRspQryUser(pMessage, nSequenceSeries);
		break;
	///会员查询应答
	case FTD_TID_RspQryParticipant:
		OnRspQryParticipant(pMessage, nSequenceSeries);
		break;
	///合约价位查询应答
	case FTD_TID_RspQryMBLMarketData:
		OnRspQryMBLMarketData(pMessage, nSequenceSeries);
		break;
	///信息查询应答
	case FTD_TID_RspQryInformation:
		OnRspQryInformation(pMessage, nSequenceSeries);
		break;
	///成交回报
	case FTD_TID_RtnTrade:
		OnRtnTrade(pMessage, nSequenceSeries);
		break;
	///报单回报
	case FTD_TID_RtnOrder:
		OnRtnOrder(pMessage, nSequenceSeries);
		break;
	///执行宣告回报
	case FTD_TID_RtnExecOrder:
		OnRtnExecOrder(pMessage, nSequenceSeries);
		break;
	///报价回报
	case FTD_TID_RtnQuote:
		OnRtnQuote(pMessage, nSequenceSeries);
		break;
	///非标组合报单回报
	case FTD_TID_RtnCombOrder:
		OnRtnCombOrder(pMessage, nSequenceSeries);
		break;
	///合约交易状态通知
	case FTD_TID_RtnInstrumentStatus:
		OnRtnInstrumentStatus(pMessage, nSequenceSeries);
		break;
	///增加合约通知
	case FTD_TID_RtnInsInstrument:
		OnRtnInsInstrument(pMessage, nSequenceSeries);
		break;
	///删除合约通知
	case FTD_TID_RtnDelInstrument:
		OnRtnDelInstrument(pMessage, nSequenceSeries);
		break;
	///增加合约单腿通知
	case FTD_TID_RtnInsCombinationLeg:
		OnRtnInsCombinationLeg(pMessage, nSequenceSeries);
		break;
	///删除合约单腿通知
	case FTD_TID_RtnDelCombinationLeg:
		OnRtnDelCombinationLeg(pMessage, nSequenceSeries);
		break;
	///别名定义通知
	case FTD_TID_RtnAliasDefine:
		OnRtnAliasDefine(pMessage, nSequenceSeries);
		break;
	///数据流回退通知
	case FTD_TID_RtnFlowMessageCancel:
		OnRtnFlowMessageCancel(pMessage, nSequenceSeries);
		break;
	///公告通知
	case FTD_TID_RtnBulletin:
		OnRtnBulletin(pMessage, nSequenceSeries);
		break;
	///普通行情通知
	case FTD_TID_RtnMarketData:
		OnRtnMarketData(pMessage, nSequenceSeries);
		break;
	///深度行情通知
	case FTD_TID_RtnDepthMarketData:
		OnRtnDepthMarketData(pMessage, nSequenceSeries);
		break;
	///内部分发信息通知
	case FTD_TID_IntlRtnDissemination:
		OnIntlRtnDissemination(pMessage, nSequenceSeries);
		break;
	///内部深度行情通知
	case FTD_TID_IntlRtnDepthMarketData:
		OnIntlRtnDepthMarketData(pMessage, nSequenceSeries);
		break;
	///管理报单通知
	case FTD_TID_RtnAdminOrder:
		OnRtnAdminOrder(pMessage, nSequenceSeries);
		break;
	///报单录入错误回报
	case FTD_TID_ErrRtnOrderInsert:
		OnErrRtnOrderInsert(pMessage, nSequenceSeries);
		break;
	///报单操作错误回报
	case FTD_TID_ErrRtnOrderAction:
		OnErrRtnOrderAction(pMessage, nSequenceSeries);
		break;
	///报价录入错误回报
	case FTD_TID_ErrRtnQuoteInsert:
		OnErrRtnQuoteInsert(pMessage, nSequenceSeries);
		break;
	///报价操作错误回报
	case FTD_TID_ErrRtnQuoteAction:
		OnErrRtnQuoteAction(pMessage, nSequenceSeries);
		break;
	///执行宣告录入错误回报
	case FTD_TID_ErrRtnExecOrderInsert:
		OnErrRtnExecOrderInsert(pMessage, nSequenceSeries);
		break;
	///执行宣告操作错误回报
	case FTD_TID_ErrRtnExecOrderAction:
		OnErrRtnExecOrderAction(pMessage, nSequenceSeries);
		break;
	///非标组合报单录入错误回报
	case FTD_TID_ErrRtnCombOrderInsert:
		OnErrRtnCombOrderInsert(pMessage, nSequenceSeries);
		break;
	///汇率查询应答
	case FTD_TID_RspQryExchangeRate:
		OnRspQryExchangeRate(pMessage, nSequenceSeries);
		break;
	default:
		break;
	}
}

CShfeFtdcUserApi *CShfeFtdcUserApi::CreateFtdcUserApi(const char *pszFlowPath,
													const char *pszUserApiType)
{
	return new CFtdcUserApiImpl(pszFlowPath, pszUserApiType, new CSelectReactor(true));
}

const char *CShfeFtdcUserApi::GetVersion(int &nMajorVersion, int &nMinorVersion)
{
		nMajorVersion = atoi(MAJOR_VERSION);
		nMinorVersion = atoi(MINOR_VERSION);
		return "SHFE User Api V"MAJOR_VERSION"."MINOR_VERSION" Build "__DATE__" "__TIME__" "SUFFIX_STR;
}


///错误应答
void CFtdcUserApiImpl::OnRspError(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnRspError(pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///用户登录应答
void CFtdcUserApiImpl::OnRspUserLogin(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CUserSubscriberMap::iterator it;
	CFTDUserCommFluxControlField UserCommFluxControlField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &UserCommFluxControlField) > 0)
	{
		CShfeFtdcUserCommFluxControlField *pUserCommFluxControlField = (CShfeFtdcUserCommFluxControlField *)&UserCommFluxControlField;
		if(pUserCommFluxControlField!=NULL)
		{
			CFtdcUserSubscriber *pFtdcUserSubscriber=NULL;
			for(it=m_mapSubscriber.begin();it!=m_mapSubscriber.end();it++)
			{
				pFtdcUserSubscriber=(CFtdcUserSubscriber *)it->second;
				if(pUserCommFluxControlField->MaxTradeCommFlux>0&&pFtdcUserSubscriber->GetSequenceSeries()==TSS_DIALOG)
				{
					pFtdcUserSubscriber->SetTradeMaxCommFlux(pUserCommFluxControlField->MaxTradeCommFlux);
				}
				if(pUserCommFluxControlField->MaxTradeOnWayCommFlux>0&&pFtdcUserSubscriber->GetSequenceSeries()==TSS_DIALOG)
				{
					pFtdcUserSubscriber->SetTradeMaxOnWayCommFlux(pUserCommFluxControlField->MaxTradeOnWayCommFlux);
				}
				if(pUserCommFluxControlField->MaxQueryCommFlux>0&&pFtdcUserSubscriber->GetSequenceSeries()==TSS_QUERY)
				{
					pFtdcUserSubscriber->SetQueryMaxCommFlux(pUserCommFluxControlField->MaxQueryCommFlux);
				}
				if(pUserCommFluxControlField->MaxQueryOnWayCommFlux>0&&pFtdcUserSubscriber->GetSequenceSeries()==TSS_QUERY)
				{
					pFtdcUserSubscriber->SetQueryMaxOnWayCommFlux(pUserCommFluxControlField->MaxQueryOnWayCommFlux);
				}
			}
		}
	}
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspUserLoginField RspUserLogin;
	CShfeFtdcRspUserLoginField *pRspUserLogin = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspUserLoginField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspUserLogin);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspUserLogin = (CShfeFtdcRspUserLoginField *)&RspUserLogin;
			m_pSpi->OnRspUserLogin(pRspUserLogin, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspUserLogin == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspUserLogin(pRspUserLogin, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///用户退出应答
void CFtdcUserApiImpl::OnRspUserLogout(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspUserLogoutField RspUserLogout;
	CShfeFtdcRspUserLogoutField *pRspUserLogout = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspUserLogoutField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspUserLogout);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspUserLogout = (CShfeFtdcRspUserLogoutField *)&RspUserLogout;
			m_pSpi->OnRspUserLogout(pRspUserLogout, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspUserLogout == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspUserLogout(pRspUserLogout, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///报单录入应答
void CFtdcUserApiImpl::OnRspOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDInputOrderField InputOrder;
	CShfeFtdcInputOrderField *pInputOrder = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInputOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&InputOrder);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pInputOrder = (CShfeFtdcInputOrderField *)&InputOrder;
			m_pSpi->OnRspOrderInsert(pInputOrder, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspOrderInsert,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&InputOrder, &CFTDInputOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pInputOrder == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspOrderInsert(pInputOrder, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///报单操作应答
void CFtdcUserApiImpl::OnRspOrderAction(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDOrderActionField OrderAction;
	CShfeFtdcOrderActionField *pOrderAction = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDOrderActionField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&OrderAction);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pOrderAction = (CShfeFtdcOrderActionField *)&OrderAction;
			m_pSpi->OnRspOrderAction(pOrderAction, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspOrderAction,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&OrderAction, &CFTDOrderActionField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pOrderAction == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspOrderAction(pOrderAction, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///报价录入应答
void CFtdcUserApiImpl::OnRspQuoteInsert(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDInputQuoteField InputQuote;
	CShfeFtdcInputQuoteField *pInputQuote = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInputQuoteField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&InputQuote);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pInputQuote = (CShfeFtdcInputQuoteField *)&InputQuote;
			m_pSpi->OnRspQuoteInsert(pInputQuote, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQuoteInsert,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&InputQuote, &CFTDInputQuoteField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pInputQuote == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQuoteInsert(pInputQuote, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///报价操作应答
void CFtdcUserApiImpl::OnRspQuoteAction(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDQuoteActionField QuoteAction;
	CShfeFtdcQuoteActionField *pQuoteAction = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDQuoteActionField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&QuoteAction);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pQuoteAction = (CShfeFtdcQuoteActionField *)&QuoteAction;
			m_pSpi->OnRspQuoteAction(pQuoteAction, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQuoteAction,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&QuoteAction, &CFTDQuoteActionField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pQuoteAction == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQuoteAction(pQuoteAction, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///OTC报单录入应答
void CFtdcUserApiImpl::OnRspOTCOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDOTCOrderField OTCOrder;
	CShfeFtdcOTCOrderField *pOTCOrder = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDOTCOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&OTCOrder);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pOTCOrder = (CShfeFtdcOTCOrderField *)&OTCOrder;
			m_pSpi->OnRspOTCOrderInsert(pOTCOrder, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspOTCOrderInsert,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&OTCOrder, &CFTDOTCOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pOTCOrder == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspOTCOrderInsert(pOTCOrder, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///用户密码修改应答
void CFtdcUserApiImpl::OnRspUserPasswordUpdate(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDUserPasswordUpdateField UserPasswordUpdate;
	CShfeFtdcUserPasswordUpdateField *pUserPasswordUpdate = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDUserPasswordUpdateField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&UserPasswordUpdate);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pUserPasswordUpdate = (CShfeFtdcUserPasswordUpdateField *)&UserPasswordUpdate;
			m_pSpi->OnRspUserPasswordUpdate(pUserPasswordUpdate, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspUserPasswordUpdate,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&UserPasswordUpdate, &CFTDUserPasswordUpdateField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pUserPasswordUpdate == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspUserPasswordUpdate(pUserPasswordUpdate, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///执行宣告录入应答
void CFtdcUserApiImpl::OnRspExecOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDInputExecOrderField InputExecOrder;
	CShfeFtdcInputExecOrderField *pInputExecOrder = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInputExecOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&InputExecOrder);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pInputExecOrder = (CShfeFtdcInputExecOrderField *)&InputExecOrder;
			m_pSpi->OnRspExecOrderInsert(pInputExecOrder, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspExecOrderInsert,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&InputExecOrder, &CFTDInputExecOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pInputExecOrder == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspExecOrderInsert(pInputExecOrder, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///执行宣告操作应答
void CFtdcUserApiImpl::OnRspExecOrderAction(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDExecOrderActionField ExecOrderAction;
	CShfeFtdcExecOrderActionField *pExecOrderAction = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDExecOrderActionField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&ExecOrderAction);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pExecOrderAction = (CShfeFtdcExecOrderActionField *)&ExecOrderAction;
			m_pSpi->OnRspExecOrderAction(pExecOrderAction, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspExecOrderAction,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&ExecOrderAction, &CFTDExecOrderActionField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pExecOrderAction == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspExecOrderAction(pExecOrderAction, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///管理报单录入应答
void CFtdcUserApiImpl::OnRspAdminOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDInputAdminOrderField InputAdminOrder;
	CShfeFtdcInputAdminOrderField *pInputAdminOrder = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInputAdminOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&InputAdminOrder);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pInputAdminOrder = (CShfeFtdcInputAdminOrderField *)&InputAdminOrder;
			m_pSpi->OnRspAdminOrderInsert(pInputAdminOrder, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspAdminOrderInsert,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&InputAdminOrder, &CFTDInputAdminOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pInputAdminOrder == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspAdminOrderInsert(pInputAdminOrder, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///非标组合报单录入应答
void CFtdcUserApiImpl::OnRspCombOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDInputCombOrderField InputCombOrder;
	CShfeFtdcInputCombOrderField *pInputCombOrder = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInputCombOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&InputCombOrder);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pInputCombOrder = (CShfeFtdcInputCombOrderField *)&InputCombOrder;
			m_pSpi->OnRspCombOrderInsert(pInputCombOrder, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspCombOrderInsert,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&InputCombOrder, &CFTDInputCombOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pInputCombOrder == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspCombOrderInsert(pInputCombOrder, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///订阅主题应答
void CFtdcUserApiImpl::OnRspSubscribeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDDisseminationField Dissemination;
	CShfeFtdcDisseminationField *pDissemination = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDDisseminationField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Dissemination);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pDissemination = (CShfeFtdcDisseminationField *)&Dissemination;
			m_pSpi->OnRspSubscribeTopic(pDissemination, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspSubscribeTopic,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&Dissemination, &CFTDDisseminationField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pDissemination == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspSubscribeTopic(pDissemination, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///交易所公告请求应答
void CFtdcUserApiImpl::OnRspBulletin(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDBulletinField Bulletin;
	CShfeFtdcBulletinField *pBulletin = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDBulletinField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Bulletin);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pBulletin = (CShfeFtdcBulletinField *)&Bulletin;
			m_pSpi->OnRspBulletin(pBulletin, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspBulletin,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&Bulletin, &CFTDBulletinField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pBulletin == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspBulletin(pBulletin, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///交易所公告信息应答
void CFtdcUserApiImpl::OnRspInformation(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDInformationField Information;
	CShfeFtdcInformationField *pInformation = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInformationField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Information);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pInformation = (CShfeFtdcInformationField *)&Information;
			m_pSpi->OnRspInformation(pInformation, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspInformation,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&Information, &CFTDInformationField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pInformation == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspInformation(pInformation, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///合约交易状态改变应答
void CFtdcUserApiImpl::OnRspInstrumentStatusUpdate(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDInstrumentStatusField InstrumentStatus;
	CShfeFtdcInstrumentStatusField *pInstrumentStatus = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInstrumentStatusField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&InstrumentStatus);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pInstrumentStatus = (CShfeFtdcInstrumentStatusField *)&InstrumentStatus;
			m_pSpi->OnRspInstrumentStatusUpdate(pInstrumentStatus, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspInstrumentStatusUpdate,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&InstrumentStatus, &CFTDInstrumentStatusField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pInstrumentStatus == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspInstrumentStatusUpdate(pInstrumentStatus, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///强制用户退出应答
void CFtdcUserApiImpl::OnRspForceUserExit(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDForceUserExitField ForceUserExit;
	CShfeFtdcForceUserExitField *pForceUserExit = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDForceUserExitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&ForceUserExit);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pForceUserExit = (CShfeFtdcForceUserExitField *)&ForceUserExit;
			m_pSpi->OnRspForceUserExit(pForceUserExit, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspForceUserExit,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&ForceUserExit, &CFTDForceUserExitField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pForceUserExit == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspForceUserExit(pForceUserExit, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///用户会话删除应答
void CFtdcUserApiImpl::OnRspForceUserLogout(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDForceUserExitField ForceUserExit;
	CShfeFtdcForceUserExitField *pForceUserExit = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDForceUserExitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&ForceUserExit);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pForceUserExit = (CShfeFtdcForceUserExitField *)&ForceUserExit;
			m_pSpi->OnRspForceUserLogout(pForceUserExit, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspForceUserLogout,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&ForceUserExit, &CFTDForceUserExitField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pForceUserExit == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspForceUserLogout(pForceUserExit, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///交易所数据同步状态改变应答
void CFtdcUserApiImpl::OnRspExchangeDataSyncStatusUpdate(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDExchangeDataSyncStatusField ExchangeDataSyncStatus;
	CShfeFtdcExchangeDataSyncStatusField *pExchangeDataSyncStatus = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDExchangeDataSyncStatusField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&ExchangeDataSyncStatus);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pExchangeDataSyncStatus = (CShfeFtdcExchangeDataSyncStatusField *)&ExchangeDataSyncStatus;
			m_pSpi->OnRspExchangeDataSyncStatusUpdate(pExchangeDataSyncStatus, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspExchangeDataSyncStatusUpdate,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&ExchangeDataSyncStatus, &CFTDExchangeDataSyncStatusField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pExchangeDataSyncStatus == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspExchangeDataSyncStatusUpdate(pExchangeDataSyncStatus, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///结算组数据同步状态改变应答
void CFtdcUserApiImpl::OnRspSGDataSyncStatusUpdate(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDSGDataSyncStatusField SGDataSyncStatus;
	CShfeFtdcSGDataSyncStatusField *pSGDataSyncStatus = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDSGDataSyncStatusField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&SGDataSyncStatus);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pSGDataSyncStatus = (CShfeFtdcSGDataSyncStatusField *)&SGDataSyncStatus;
			m_pSpi->OnRspSGDataSyncStatusUpdate(pSGDataSyncStatus, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspSGDataSyncStatusUpdate,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&SGDataSyncStatus, &CFTDSGDataSyncStatusField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pSGDataSyncStatus == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspSGDataSyncStatusUpdate(pSGDataSyncStatus, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员资金查询应答
void CFtdcUserApiImpl::OnRspQryPartAccount(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspPartAccountField RspPartAccount;
	CShfeFtdcRspPartAccountField *pRspPartAccount = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspPartAccountField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspPartAccount);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspPartAccount = (CShfeFtdcRspPartAccountField *)&RspPartAccount;
			m_pSpi->OnRspQryPartAccount(pRspPartAccount, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryPartAccount,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&RspPartAccount, &CFTDRspPartAccountField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pRspPartAccount == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryPartAccount(pRspPartAccount, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///报单查询应答
void CFtdcUserApiImpl::OnRspQryOrder(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDOrderField Order;
	CShfeFtdcOrderField *pOrder = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Order);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pOrder = (CShfeFtdcOrderField *)&Order;
			m_pSpi->OnRspQryOrder(pOrder, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryOrder,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&Order, &CFTDOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pOrder == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryOrder(pOrder, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///报价查询应答
void CFtdcUserApiImpl::OnRspQryQuote(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDQuoteField Quote;
	CShfeFtdcQuoteField *pQuote = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDQuoteField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Quote);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pQuote = (CShfeFtdcQuoteField *)&Quote;
			m_pSpi->OnRspQryQuote(pQuote, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryQuote,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&Quote, &CFTDQuoteField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pQuote == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryQuote(pQuote, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///成交单查询应答
void CFtdcUserApiImpl::OnRspQryTrade(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDTradeField Trade;
	CShfeFtdcTradeField *pTrade = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDTradeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Trade);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pTrade = (CShfeFtdcTradeField *)&Trade;
			m_pSpi->OnRspQryTrade(pTrade, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryTrade,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&Trade, &CFTDTradeField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pTrade == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryTrade(pTrade, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员客户查询应答
void CFtdcUserApiImpl::OnRspQryClient(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspClientField RspClient;
	CShfeFtdcRspClientField *pRspClient = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspClientField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspClient);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspClient = (CShfeFtdcRspClientField *)&RspClient;
			m_pSpi->OnRspQryClient(pRspClient, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryClient,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&RspClient, &CFTDRspClientField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pRspClient == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryClient(pRspClient, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员持仓查询应答
void CFtdcUserApiImpl::OnRspQryPartPosition(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspPartPositionField RspPartPosition;
	CShfeFtdcRspPartPositionField *pRspPartPosition = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspPartPositionField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspPartPosition);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspPartPosition = (CShfeFtdcRspPartPositionField *)&RspPartPosition;
			m_pSpi->OnRspQryPartPosition(pRspPartPosition, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryPartPosition,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&RspPartPosition, &CFTDRspPartPositionField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pRspPartPosition == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryPartPosition(pRspPartPosition, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///客户持仓查询应答
void CFtdcUserApiImpl::OnRspQryClientPosition(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspClientPositionField RspClientPosition;
	CShfeFtdcRspClientPositionField *pRspClientPosition = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspClientPositionField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspClientPosition);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspClientPosition = (CShfeFtdcRspClientPositionField *)&RspClientPosition;
			m_pSpi->OnRspQryClientPosition(pRspClientPosition, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryClientPosition,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&RspClientPosition, &CFTDRspClientPositionField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pRspClientPosition == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryClientPosition(pRspClientPosition, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///合约查询应答
void CFtdcUserApiImpl::OnRspQryInstrument(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspInstrumentField RspInstrument;
	CShfeFtdcRspInstrumentField *pRspInstrument = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspInstrumentField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspInstrument);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspInstrument = (CShfeFtdcRspInstrumentField *)&RspInstrument;
			m_pSpi->OnRspQryInstrument(pRspInstrument, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryInstrument,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&RspInstrument, &CFTDRspInstrumentField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pRspInstrument == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryInstrument(pRspInstrument, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///合约交易状态查询应答
void CFtdcUserApiImpl::OnRspQryInstrumentStatus(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDInstrumentStatusField InstrumentStatus;
	CShfeFtdcInstrumentStatusField *pInstrumentStatus = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInstrumentStatusField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&InstrumentStatus);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pInstrumentStatus = (CShfeFtdcInstrumentStatusField *)&InstrumentStatus;
			m_pSpi->OnRspQryInstrumentStatus(pInstrumentStatus, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryInstrumentStatus,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&InstrumentStatus, &CFTDInstrumentStatusField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pInstrumentStatus == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryInstrumentStatus(pInstrumentStatus, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///结算组状态查询应答
void CFtdcUserApiImpl::OnRspQrySGDataSyncStatus(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDSGDataSyncStatusField SGDataSyncStatus;
	CShfeFtdcSGDataSyncStatusField *pSGDataSyncStatus = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDSGDataSyncStatusField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&SGDataSyncStatus);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pSGDataSyncStatus = (CShfeFtdcSGDataSyncStatusField *)&SGDataSyncStatus;
			m_pSpi->OnRspQrySGDataSyncStatus(pSGDataSyncStatus, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQrySGDataSyncStatus,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&SGDataSyncStatus, &CFTDSGDataSyncStatusField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pSGDataSyncStatus == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQrySGDataSyncStatus(pSGDataSyncStatus, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///保值额度应答
void CFtdcUserApiImpl::OnRspQryHedgeVolume(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDHedgeVolumeField HedgeVolume;
	CShfeFtdcHedgeVolumeField *pHedgeVolume = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDHedgeVolumeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&HedgeVolume);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pHedgeVolume = (CShfeFtdcHedgeVolumeField *)&HedgeVolume;
			m_pSpi->OnRspQryHedgeVolume(pHedgeVolume, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryHedgeVolume,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&HedgeVolume, &CFTDHedgeVolumeField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pHedgeVolume == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryHedgeVolume(pHedgeVolume, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///信用限额查询应答
void CFtdcUserApiImpl::OnRspQryCreditLimit(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDCreditLimitField CreditLimit;
	CShfeFtdcCreditLimitField *pCreditLimit = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDCreditLimitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&CreditLimit);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pCreditLimit = (CShfeFtdcCreditLimitField *)&CreditLimit;
			m_pSpi->OnRspQryCreditLimit(pCreditLimit, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryCreditLimit,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&CreditLimit, &CFTDCreditLimitField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pCreditLimit == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryCreditLimit(pCreditLimit, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///非标组合报单查询应答
void CFtdcUserApiImpl::OnRspQryCombOrder(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDCombOrderField CombOrder;
	CShfeFtdcCombOrderField *pCombOrder = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDCombOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&CombOrder);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pCombOrder = (CShfeFtdcCombOrderField *)&CombOrder;
			m_pSpi->OnRspQryCombOrder(pCombOrder, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryCombOrder,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&CombOrder, &CFTDCombOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pCombOrder == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryCombOrder(pCombOrder, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///执行宣告查询应答
void CFtdcUserApiImpl::OnRspQryExecOrder(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDExecOrderField ExecOrder;
	CShfeFtdcExecOrderField *pExecOrder = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDExecOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&ExecOrder);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pExecOrder = (CShfeFtdcExecOrderField *)&ExecOrder;
			m_pSpi->OnRspQryExecOrder(pExecOrder, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryExecOrder,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&ExecOrder, &CFTDExecOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pExecOrder == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryExecOrder(pExecOrder, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///普通行情查询应答
void CFtdcUserApiImpl::OnRspQryMarketData(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDMarketDataField MarketData;
	CShfeFtdcMarketDataField *pMarketData = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDMarketDataField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&MarketData);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pMarketData = (CShfeFtdcMarketDataField *)&MarketData;
			m_pSpi->OnRspQryMarketData(pMarketData, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryMarketData,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&MarketData, &CFTDMarketDataField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pMarketData == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMarketData(pMarketData, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///交易所公告查询请求应答
void CFtdcUserApiImpl::OnRspQryBulletin(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDBulletinField Bulletin;
	CShfeFtdcBulletinField *pBulletin = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDBulletinField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Bulletin);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pBulletin = (CShfeFtdcBulletinField *)&Bulletin;
			m_pSpi->OnRspQryBulletin(pBulletin, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryBulletin,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&Bulletin, &CFTDBulletinField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pBulletin == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryBulletin(pBulletin, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///主题查询应答
void CFtdcUserApiImpl::OnRspQryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDDisseminationField Dissemination;
	CShfeFtdcDisseminationField *pDissemination = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDDisseminationField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Dissemination);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pDissemination = (CShfeFtdcDisseminationField *)&Dissemination;
			m_pSpi->OnRspQryTopic(pDissemination, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryTopic,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&Dissemination, &CFTDDisseminationField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pDissemination == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryTopic(pDissemination, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///用户在线查询应答
void CFtdcUserApiImpl::OnRspQryUserSession(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDUserSessionField UserSession;
	CShfeFtdcUserSessionField *pUserSession = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDUserSessionField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&UserSession);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pUserSession = (CShfeFtdcUserSessionField *)&UserSession;
			m_pSpi->OnRspQryUserSession(pUserSession, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryUserSession,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&UserSession, &CFTDUserSessionField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pUserSession == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryUserSession(pUserSession, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///用户查询应答
void CFtdcUserApiImpl::OnRspQryUser(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDUserField User;
	CShfeFtdcUserField *pUser = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDUserField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&User);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pUser = (CShfeFtdcUserField *)&User;
			m_pSpi->OnRspQryUser(pUser, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryUser,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&User, &CFTDUserField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pUser == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryUser(pUser, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员查询应答
void CFtdcUserApiImpl::OnRspQryParticipant(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDParticipantField Participant;
	CShfeFtdcParticipantField *pParticipant = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDParticipantField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Participant);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pParticipant = (CShfeFtdcParticipantField *)&Participant;
			m_pSpi->OnRspQryParticipant(pParticipant, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryParticipant,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&Participant, &CFTDParticipantField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pParticipant == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryParticipant(pParticipant, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///合约价位查询应答
void CFtdcUserApiImpl::OnRspQryMBLMarketData(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDMBLMarketDataField MBLMarketData;
	CShfeFtdcMBLMarketDataField *pMBLMarketData = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDMBLMarketDataField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&MBLMarketData);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pMBLMarketData = (CShfeFtdcMBLMarketDataField *)&MBLMarketData;
			m_pSpi->OnRspQryMBLMarketData(pMBLMarketData, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryMBLMarketData,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&MBLMarketData, &CFTDMBLMarketDataField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pMBLMarketData == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMBLMarketData(pMBLMarketData, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///信息查询应答
void CFtdcUserApiImpl::OnRspQryInformation(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDInformationField Information;
	CShfeFtdcInformationField *pInformation = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInformationField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Information);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pInformation = (CShfeFtdcInformationField *)&Information;
			m_pSpi->OnRspQryInformation(pInformation, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryInformation,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&Information, &CFTDInformationField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pInformation == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryInformation(pInformation, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///成交回报
void CFtdcUserApiImpl::OnRtnTrade(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDTradeField Trade;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDTradeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Trade);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnTrade,", szTimeBuffer);
			FIELD_TO_STRING((char *)&Trade, &CFTDTradeField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnTrade((CShfeFtdcTradeField *)&Trade);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///报单回报
void CFtdcUserApiImpl::OnRtnOrder(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDOrderField Order;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Order);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnOrder,", szTimeBuffer);
			FIELD_TO_STRING((char *)&Order, &CFTDOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnOrder((CShfeFtdcOrderField *)&Order);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///执行宣告回报
void CFtdcUserApiImpl::OnRtnExecOrder(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDExecOrderField ExecOrder;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDExecOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&ExecOrder);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnExecOrder,", szTimeBuffer);
			FIELD_TO_STRING((char *)&ExecOrder, &CFTDExecOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnExecOrder((CShfeFtdcExecOrderField *)&ExecOrder);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///报价回报
void CFtdcUserApiImpl::OnRtnQuote(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDQuoteField Quote;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDQuoteField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Quote);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnQuote,", szTimeBuffer);
			FIELD_TO_STRING((char *)&Quote, &CFTDQuoteField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnQuote((CShfeFtdcQuoteField *)&Quote);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///非标组合报单回报
void CFtdcUserApiImpl::OnRtnCombOrder(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDCombOrderField CombOrder;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDCombOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&CombOrder);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnCombOrder,", szTimeBuffer);
			FIELD_TO_STRING((char *)&CombOrder, &CFTDCombOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnCombOrder((CShfeFtdcCombOrderField *)&CombOrder);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///合约交易状态通知
void CFtdcUserApiImpl::OnRtnInstrumentStatus(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDInstrumentStatusField InstrumentStatus;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInstrumentStatusField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&InstrumentStatus);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnInstrumentStatus,", szTimeBuffer);
			FIELD_TO_STRING((char *)&InstrumentStatus, &CFTDInstrumentStatusField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnInstrumentStatus((CShfeFtdcInstrumentStatusField *)&InstrumentStatus);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///增加合约通知
void CFtdcUserApiImpl::OnRtnInsInstrument(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDInstrumentField Instrument;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInstrumentField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Instrument);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnInsInstrument,", szTimeBuffer);
			FIELD_TO_STRING((char *)&Instrument, &CFTDInstrumentField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnInsInstrument((CShfeFtdcInstrumentField *)&Instrument);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///删除合约通知
void CFtdcUserApiImpl::OnRtnDelInstrument(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDInstrumentField Instrument;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInstrumentField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Instrument);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnDelInstrument,", szTimeBuffer);
			FIELD_TO_STRING((char *)&Instrument, &CFTDInstrumentField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnDelInstrument((CShfeFtdcInstrumentField *)&Instrument);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///增加合约单腿通知
void CFtdcUserApiImpl::OnRtnInsCombinationLeg(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDCombinationLegField CombinationLeg;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDCombinationLegField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&CombinationLeg);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnInsCombinationLeg,", szTimeBuffer);
			FIELD_TO_STRING((char *)&CombinationLeg, &CFTDCombinationLegField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnInsCombinationLeg((CShfeFtdcCombinationLegField *)&CombinationLeg);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///删除合约单腿通知
void CFtdcUserApiImpl::OnRtnDelCombinationLeg(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDCombinationLegField CombinationLeg;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDCombinationLegField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&CombinationLeg);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnDelCombinationLeg,", szTimeBuffer);
			FIELD_TO_STRING((char *)&CombinationLeg, &CFTDCombinationLegField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnDelCombinationLeg((CShfeFtdcCombinationLegField *)&CombinationLeg);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///别名定义通知
void CFtdcUserApiImpl::OnRtnAliasDefine(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDAliasDefineField AliasDefine;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDAliasDefineField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&AliasDefine);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnAliasDefine,", szTimeBuffer);
			FIELD_TO_STRING((char *)&AliasDefine, &CFTDAliasDefineField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnAliasDefine((CShfeFtdcAliasDefineField *)&AliasDefine);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///数据流回退通知
void CFtdcUserApiImpl::OnRtnFlowMessageCancel(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDFlowMessageCancelField FlowMessageCancel;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDFlowMessageCancelField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&FlowMessageCancel);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnFlowMessageCancel,", szTimeBuffer);
			FIELD_TO_STRING((char *)&FlowMessageCancel, &CFTDFlowMessageCancelField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnFlowMessageCancel((CShfeFtdcFlowMessageCancelField *)&FlowMessageCancel);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///公告通知
void CFtdcUserApiImpl::OnRtnBulletin(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDBulletinField Bulletin;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDBulletinField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Bulletin);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnBulletin,", szTimeBuffer);
			FIELD_TO_STRING((char *)&Bulletin, &CFTDBulletinField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnBulletin((CShfeFtdcBulletinField *)&Bulletin);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///普通行情通知
void CFtdcUserApiImpl::OnRtnMarketData(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDMarketDataField MarketData;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDMarketDataField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&MarketData);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMarketData,", szTimeBuffer);
			FIELD_TO_STRING((char *)&MarketData, &CFTDMarketDataField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMarketData((CShfeFtdcMarketDataField *)&MarketData);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///深度行情通知
void CFtdcUserApiImpl::OnRtnDepthMarketData(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDDepthMarketDataField DepthMarketData;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDDepthMarketDataField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&DepthMarketData);
		CFtdcUserApiImplBase::OnRtnDepthMarketData(&DepthMarketData, nSequenceSeries);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnDepthMarketData,", szTimeBuffer);
			FIELD_TO_STRING((char *)&DepthMarketData, &CFTDDepthMarketDataField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnDepthMarketData((CShfeFtdcDepthMarketDataField *)&DepthMarketData);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///管理报单通知
void CFtdcUserApiImpl::OnRtnAdminOrder(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDAdminOrderField AdminOrder;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDAdminOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&AdminOrder);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnAdminOrder,", szTimeBuffer);
			FIELD_TO_STRING((char *)&AdminOrder, &CFTDAdminOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnAdminOrder((CShfeFtdcAdminOrderField *)&AdminOrder);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///报单录入错误回报
void CFtdcUserApiImpl::OnErrRtnOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDInputOrderField InputOrder;
	CShfeFtdcInputOrderField *pInputOrder = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInputOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&InputOrder);
		itor.Next();
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnErrRtnOrderInsert,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&InputOrder, &CFTDInputOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pInputOrder = (CShfeFtdcInputOrderField *)&InputOrder;
			m_pSpi->OnErrRtnOrderInsert(pInputOrder, pRspInfoField);
		}
	}
	
	if (pInputOrder == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnErrRtnOrderInsert(pInputOrder, pRspInfoField);
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///报单操作错误回报
void CFtdcUserApiImpl::OnErrRtnOrderAction(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDOrderActionField OrderAction;
	CShfeFtdcOrderActionField *pOrderAction = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDOrderActionField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&OrderAction);
		itor.Next();
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnErrRtnOrderAction,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&OrderAction, &CFTDOrderActionField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pOrderAction = (CShfeFtdcOrderActionField *)&OrderAction;
			m_pSpi->OnErrRtnOrderAction(pOrderAction, pRspInfoField);
		}
	}
	
	if (pOrderAction == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnErrRtnOrderAction(pOrderAction, pRspInfoField);
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///报价录入错误回报
void CFtdcUserApiImpl::OnErrRtnQuoteInsert(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDInputQuoteField InputQuote;
	CShfeFtdcInputQuoteField *pInputQuote = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInputQuoteField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&InputQuote);
		itor.Next();
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnErrRtnQuoteInsert,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&InputQuote, &CFTDInputQuoteField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pInputQuote = (CShfeFtdcInputQuoteField *)&InputQuote;
			m_pSpi->OnErrRtnQuoteInsert(pInputQuote, pRspInfoField);
		}
	}
	
	if (pInputQuote == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnErrRtnQuoteInsert(pInputQuote, pRspInfoField);
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///报价操作错误回报
void CFtdcUserApiImpl::OnErrRtnQuoteAction(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDQuoteActionField QuoteAction;
	CShfeFtdcQuoteActionField *pQuoteAction = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDQuoteActionField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&QuoteAction);
		itor.Next();
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnErrRtnQuoteAction,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&QuoteAction, &CFTDQuoteActionField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pQuoteAction = (CShfeFtdcQuoteActionField *)&QuoteAction;
			m_pSpi->OnErrRtnQuoteAction(pQuoteAction, pRspInfoField);
		}
	}
	
	if (pQuoteAction == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnErrRtnQuoteAction(pQuoteAction, pRspInfoField);
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///执行宣告录入错误回报
void CFtdcUserApiImpl::OnErrRtnExecOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDInputExecOrderField InputExecOrder;
	CShfeFtdcInputExecOrderField *pInputExecOrder = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInputExecOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&InputExecOrder);
		itor.Next();
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnErrRtnExecOrderInsert,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&InputExecOrder, &CFTDInputExecOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pInputExecOrder = (CShfeFtdcInputExecOrderField *)&InputExecOrder;
			m_pSpi->OnErrRtnExecOrderInsert(pInputExecOrder, pRspInfoField);
		}
	}
	
	if (pInputExecOrder == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnErrRtnExecOrderInsert(pInputExecOrder, pRspInfoField);
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///执行宣告操作错误回报
void CFtdcUserApiImpl::OnErrRtnExecOrderAction(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDExecOrderActionField ExecOrderAction;
	CShfeFtdcExecOrderActionField *pExecOrderAction = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDExecOrderActionField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&ExecOrderAction);
		itor.Next();
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnErrRtnExecOrderAction,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&ExecOrderAction, &CFTDExecOrderActionField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pExecOrderAction = (CShfeFtdcExecOrderActionField *)&ExecOrderAction;
			m_pSpi->OnErrRtnExecOrderAction(pExecOrderAction, pRspInfoField);
		}
	}
	
	if (pExecOrderAction == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnErrRtnExecOrderAction(pExecOrderAction, pRspInfoField);
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///非标组合报单录入错误回报
void CFtdcUserApiImpl::OnErrRtnCombOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDInputCombOrderField InputCombOrder;
	CShfeFtdcInputCombOrderField *pInputCombOrder = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInputCombOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&InputCombOrder);
		itor.Next();
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnErrRtnCombOrderInsert,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&InputCombOrder, &CFTDInputCombOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pInputCombOrder = (CShfeFtdcInputCombOrderField *)&InputCombOrder;
			m_pSpi->OnErrRtnCombOrderInsert(pInputCombOrder, pRspInfoField);
		}
	}
	
	if (pInputCombOrder == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnErrRtnCombOrderInsert(pInputCombOrder, pRspInfoField);
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///汇率查询应答
void CFtdcUserApiImpl::OnRspQryExchangeRate(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspExchangeRateField RspExchangeRate;
	CShfeFtdcRspExchangeRateField *pRspExchangeRate = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspExchangeRateField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspExchangeRate);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspExchangeRate = (CShfeFtdcRspExchangeRateField *)&RspExchangeRate;
			m_pSpi->OnRspQryExchangeRate(pRspExchangeRate, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryExchangeRate,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&RspExchangeRate, &CFTDRspExchangeRateField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pRspExchangeRate == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryExchangeRate(pRspExchangeRate, pRspInfoField, pMessage->GetRequestId(), true);
	}
}


