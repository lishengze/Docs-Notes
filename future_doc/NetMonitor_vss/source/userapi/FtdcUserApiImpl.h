/////////////////////////////////////////////////////////////////////////
///@system 新一代交易所系统
///@company 上海期货信息技术有限公司
///@file FtdcUserApiImpl.h
///@brief 定义了客户端接口实现
///@history 
///20060106	赵鸿昊		创建该文件
/////////////////////////////////////////////////////////////////////////

#if !defined(_FTDCUSERAPIIMPL_H)
#define _FTDCUSERAPIIMPL_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FtdcUserApiImplBase.h"

class CFtdcUserApiImpl : public CFtdcUserApiImplBase
{
public:	
	CFtdcUserApiImpl(const char *pszFlowPath, const char *pszUserApiType, CSelectReactor *pReactor);
	virtual void HandleResponse(CFTDCPackage *pMessage, WORD nSequenceSeries);

	///用户退出请求
	virtual int ReqUserLogout(CShfeFtdcReqUserLogoutField *pReqUserLogout, int nRequestID);

	///报单录入请求
	virtual int ReqOrderInsert(CShfeFtdcInputOrderField *pInputOrder, int nRequestID);

	///报单操作请求
	virtual int ReqOrderAction(CShfeFtdcOrderActionField *pOrderAction, int nRequestID);

	///报价录入请求
	virtual int ReqQuoteInsert(CShfeFtdcInputQuoteField *pInputQuote, int nRequestID);

	///报价操作请求
	virtual int ReqQuoteAction(CShfeFtdcQuoteActionField *pQuoteAction, int nRequestID);

	///OTC报单录入请求
	virtual int ReqOTCOrderInsert(CShfeFtdcOTCOrderField *pOTCOrder, int nRequestID);

	///用户密码修改请求
	virtual int ReqUserPasswordUpdate(CShfeFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID);

	///执行宣告录入请求
	virtual int ReqExecOrderInsert(CShfeFtdcInputExecOrderField *pInputExecOrder, int nRequestID);

	///执行宣告操作请求
	virtual int ReqExecOrderAction(CShfeFtdcExecOrderActionField *pExecOrderAction, int nRequestID);

	///管理报单录入请求
	virtual int ReqAdminOrderInsert(CShfeFtdcInputAdminOrderField *pInputAdminOrder, int nRequestID);

	///非标组合报单录入请求
	virtual int ReqCombOrderInsert(CShfeFtdcInputCombOrderField *pInputCombOrder, int nRequestID);

	///订阅主题请求
	virtual int ReqSubscribeTopic(CShfeFtdcDisseminationField *pDissemination, int nRequestID);

	///交易所公告请求
	virtual int ReqBulletin(CShfeFtdcBulletinField *pBulletin, int nRequestID);

	///交易所信息请求
	virtual int ReqInformation(CShfeFtdcInformationField *pInformation, int nRequestID);

	///合约交易状态改变请求
	virtual int ReqInstrumentStatusUpdate(CShfeFtdcInstrumentStatusField *pInstrumentStatus, int nRequestID);

	///强制用户退出请求
	virtual int ReqForceUserExit(CShfeFtdcForceUserExitField *pForceUserExit, int nRequestID);

	///用户会话删除请求
	virtual int ReqForceUserLogout(CShfeFtdcForceUserExitField *pForceUserExit, int nRequestID);

	///交易所数据同步状态改变请求
	virtual int ReqExchangeDataSyncStatusUpdate(CShfeFtdcExchangeDataSyncStatusField *pExchangeDataSyncStatus, int nRequestID);

	///结算组数据同步状态改变请求
	virtual int ReqSGDataSyncStatusUpdate(CShfeFtdcSGDataSyncStatusField *pSGDataSyncStatus, int nRequestID);

	///会员资金查询请求
	virtual int ReqQryPartAccount(CShfeFtdcQryPartAccountField *pQryPartAccount, int nRequestID);

	///报单查询请求
	virtual int ReqQryOrder(CShfeFtdcQryOrderField *pQryOrder, int nRequestID);

	///报价查询请求
	virtual int ReqQryQuote(CShfeFtdcQryQuoteField *pQryQuote, int nRequestID);

	///成交单查询请求
	virtual int ReqQryTrade(CShfeFtdcQryTradeField *pQryTrade, int nRequestID);

	///会员客户查询请求
	virtual int ReqQryClient(CShfeFtdcQryClientField *pQryClient, int nRequestID);

	///会员持仓查询请求
	virtual int ReqQryPartPosition(CShfeFtdcQryPartPositionField *pQryPartPosition, int nRequestID);

	///客户持仓查询请求
	virtual int ReqQryClientPosition(CShfeFtdcQryClientPositionField *pQryClientPosition, int nRequestID);

	///合约查询请求
	virtual int ReqQryInstrument(CShfeFtdcQryInstrumentField *pQryInstrument, int nRequestID);

	///合约交易状态查询请求
	virtual int ReqQryInstrumentStatus(CShfeFtdcQryInstrumentStatusField *pQryInstrumentStatus, int nRequestID);

	///结算组状态查询请求
	virtual int ReqQrySGDataSyncStatus(CShfeFtdcQrySGDataSyncStatusField *pQrySGDataSyncStatus, int nRequestID);

	///保值额度查询
	virtual int ReqQryHedgeVolume(CShfeFtdcQryHedgeVolumeField *pQryHedgeVolume, int nRequestID);

	///信用限额查询请求
	virtual int ReqQryCreditLimit(CShfeFtdcQryCreditLimitField *pQryCreditLimit, int nRequestID);

	///非标组合报单查询请求
	virtual int ReqQryCombOrder(CShfeFtdcQryCombOrderField *pQryCombOrder, int nRequestID);

	///执行宣告查询请求
	virtual int ReqQryExecOrder(CShfeFtdcQryExecOrderField *pQryExecOrder, int nRequestID);

	///普通行情查询请求
	virtual int ReqQryMarketData(CShfeFtdcQryMarketDataField *pQryMarketData, int nRequestID);

	///交易所公告查询请求
	virtual int ReqQryBulletin(CShfeFtdcQryBulletinField *pQryBulletin, int nRequestID);

	///主题查询请求
	virtual int ReqQryTopic(CShfeFtdcDisseminationField *pDissemination, int nRequestID);

	///用户在线查询请求
	virtual int ReqQryUserSession(CShfeFtdcQryUserSessionField *pQryUserSession, int nRequestID);

	///用户查询请求
	virtual int ReqQryUser(CShfeFtdcQryUserField *pQryUser, int nRequestID);

	///会员查询请求
	virtual int ReqQryParticipant(CShfeFtdcQryParticipantField *pQryParticipant, int nRequestID);

	///合约价位查询
	virtual int ReqQryMBLMarketData(CShfeFtdcQryMBLMarketDataField *pQryMBLMarketData, int nRequestID);

	///信息查询
	virtual int ReqQryInformation(CShfeFtdcQryInformationField *pQryInformation, int nRequestID);

	///客户持仓查询请求
	virtual int ReqQryClientPositionV1(CShfeFtdcQryClientPositionV1Field *pQryClientPositionV1, int nRequestID);

	///汇率查询请求
	virtual int ReqQryExchangeRate(CShfeFtdcQryExchangeRateField *pQryExchangeRate, int nRequestID);
private:
	///错误应答
	void OnRspError(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///用户登录应答
	void OnRspUserLogin(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///用户退出应答
	void OnRspUserLogout(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报单录入应答
	void OnRspOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报单操作应答
	void OnRspOrderAction(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报价录入应答
	void OnRspQuoteInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报价操作应答
	void OnRspQuoteAction(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///OTC报单录入应答
	void OnRspOTCOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///用户密码修改应答
	void OnRspUserPasswordUpdate(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///执行宣告录入应答
	void OnRspExecOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///执行宣告操作应答
	void OnRspExecOrderAction(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///管理报单录入应答
	void OnRspAdminOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///非标组合报单录入应答
	void OnRspCombOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///订阅主题应答
	void OnRspSubscribeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易所公告请求应答
	void OnRspBulletin(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易所公告信息应答
	void OnRspInformation(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///合约交易状态改变应答
	void OnRspInstrumentStatusUpdate(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///强制用户退出应答
	void OnRspForceUserExit(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///用户会话删除应答
	void OnRspForceUserLogout(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易所数据同步状态改变应答
	void OnRspExchangeDataSyncStatusUpdate(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///结算组数据同步状态改变应答
	void OnRspSGDataSyncStatusUpdate(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员资金查询应答
	void OnRspQryPartAccount(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报单查询应答
	void OnRspQryOrder(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报价查询应答
	void OnRspQryQuote(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///成交单查询应答
	void OnRspQryTrade(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员客户查询应答
	void OnRspQryClient(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员持仓查询应答
	void OnRspQryPartPosition(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///客户持仓查询应答
	void OnRspQryClientPosition(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///合约查询应答
	void OnRspQryInstrument(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///合约交易状态查询应答
	void OnRspQryInstrumentStatus(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///结算组状态查询应答
	void OnRspQrySGDataSyncStatus(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///保值额度应答
	void OnRspQryHedgeVolume(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///信用限额查询应答
	void OnRspQryCreditLimit(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///非标组合报单查询应答
	void OnRspQryCombOrder(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///执行宣告查询应答
	void OnRspQryExecOrder(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///普通行情查询应答
	void OnRspQryMarketData(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易所公告查询请求应答
	void OnRspQryBulletin(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主题查询应答
	void OnRspQryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///用户在线查询应答
	void OnRspQryUserSession(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///用户查询应答
	void OnRspQryUser(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员查询应答
	void OnRspQryParticipant(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///合约价位查询应答
	void OnRspQryMBLMarketData(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///信息查询应答
	void OnRspQryInformation(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///成交回报
	void OnRtnTrade(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报单回报
	void OnRtnOrder(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///执行宣告回报
	void OnRtnExecOrder(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报价回报
	void OnRtnQuote(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///非标组合报单回报
	void OnRtnCombOrder(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///合约交易状态通知
	void OnRtnInstrumentStatus(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///增加合约通知
	void OnRtnInsInstrument(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///删除合约通知
	void OnRtnDelInstrument(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///增加合约单腿通知
	void OnRtnInsCombinationLeg(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///删除合约单腿通知
	void OnRtnDelCombinationLeg(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///别名定义通知
	void OnRtnAliasDefine(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///数据流回退通知
	void OnRtnFlowMessageCancel(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///公告通知
	void OnRtnBulletin(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///普通行情通知
	void OnRtnMarketData(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///深度行情通知
	void OnRtnDepthMarketData(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///管理报单通知
	void OnRtnAdminOrder(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报单录入错误回报
	void OnErrRtnOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报单操作错误回报
	void OnErrRtnOrderAction(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报价录入错误回报
	void OnErrRtnQuoteInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报价操作错误回报
	void OnErrRtnQuoteAction(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///执行宣告录入错误回报
	void OnErrRtnExecOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///执行宣告操作错误回报
	void OnErrRtnExecOrderAction(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///非标组合报单录入错误回报
	void OnErrRtnCombOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///汇率查询应答
	void OnRspQryExchangeRate(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
};

#endif
