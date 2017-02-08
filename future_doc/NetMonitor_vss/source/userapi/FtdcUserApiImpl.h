/////////////////////////////////////////////////////////////////////////
///@system ��һ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file FtdcUserApiImpl.h
///@brief �����˿ͻ��˽ӿ�ʵ��
///@history 
///20060106	�Ժ��		�������ļ�
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

	///�û��˳�����
	virtual int ReqUserLogout(CShfeFtdcReqUserLogoutField *pReqUserLogout, int nRequestID);

	///����¼������
	virtual int ReqOrderInsert(CShfeFtdcInputOrderField *pInputOrder, int nRequestID);

	///������������
	virtual int ReqOrderAction(CShfeFtdcOrderActionField *pOrderAction, int nRequestID);

	///����¼������
	virtual int ReqQuoteInsert(CShfeFtdcInputQuoteField *pInputQuote, int nRequestID);

	///���۲�������
	virtual int ReqQuoteAction(CShfeFtdcQuoteActionField *pQuoteAction, int nRequestID);

	///OTC����¼������
	virtual int ReqOTCOrderInsert(CShfeFtdcOTCOrderField *pOTCOrder, int nRequestID);

	///�û������޸�����
	virtual int ReqUserPasswordUpdate(CShfeFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID);

	///ִ������¼������
	virtual int ReqExecOrderInsert(CShfeFtdcInputExecOrderField *pInputExecOrder, int nRequestID);

	///ִ�������������
	virtual int ReqExecOrderAction(CShfeFtdcExecOrderActionField *pExecOrderAction, int nRequestID);

	///������¼������
	virtual int ReqAdminOrderInsert(CShfeFtdcInputAdminOrderField *pInputAdminOrder, int nRequestID);

	///�Ǳ���ϱ���¼������
	virtual int ReqCombOrderInsert(CShfeFtdcInputCombOrderField *pInputCombOrder, int nRequestID);

	///������������
	virtual int ReqSubscribeTopic(CShfeFtdcDisseminationField *pDissemination, int nRequestID);

	///��������������
	virtual int ReqBulletin(CShfeFtdcBulletinField *pBulletin, int nRequestID);

	///��������Ϣ����
	virtual int ReqInformation(CShfeFtdcInformationField *pInformation, int nRequestID);

	///��Լ����״̬�ı�����
	virtual int ReqInstrumentStatusUpdate(CShfeFtdcInstrumentStatusField *pInstrumentStatus, int nRequestID);

	///ǿ���û��˳�����
	virtual int ReqForceUserExit(CShfeFtdcForceUserExitField *pForceUserExit, int nRequestID);

	///�û��Ựɾ������
	virtual int ReqForceUserLogout(CShfeFtdcForceUserExitField *pForceUserExit, int nRequestID);

	///����������ͬ��״̬�ı�����
	virtual int ReqExchangeDataSyncStatusUpdate(CShfeFtdcExchangeDataSyncStatusField *pExchangeDataSyncStatus, int nRequestID);

	///����������ͬ��״̬�ı�����
	virtual int ReqSGDataSyncStatusUpdate(CShfeFtdcSGDataSyncStatusField *pSGDataSyncStatus, int nRequestID);

	///��Ա�ʽ��ѯ����
	virtual int ReqQryPartAccount(CShfeFtdcQryPartAccountField *pQryPartAccount, int nRequestID);

	///������ѯ����
	virtual int ReqQryOrder(CShfeFtdcQryOrderField *pQryOrder, int nRequestID);

	///���۲�ѯ����
	virtual int ReqQryQuote(CShfeFtdcQryQuoteField *pQryQuote, int nRequestID);

	///�ɽ�����ѯ����
	virtual int ReqQryTrade(CShfeFtdcQryTradeField *pQryTrade, int nRequestID);

	///��Ա�ͻ���ѯ����
	virtual int ReqQryClient(CShfeFtdcQryClientField *pQryClient, int nRequestID);

	///��Ա�ֲֲ�ѯ����
	virtual int ReqQryPartPosition(CShfeFtdcQryPartPositionField *pQryPartPosition, int nRequestID);

	///�ͻ��ֲֲ�ѯ����
	virtual int ReqQryClientPosition(CShfeFtdcQryClientPositionField *pQryClientPosition, int nRequestID);

	///��Լ��ѯ����
	virtual int ReqQryInstrument(CShfeFtdcQryInstrumentField *pQryInstrument, int nRequestID);

	///��Լ����״̬��ѯ����
	virtual int ReqQryInstrumentStatus(CShfeFtdcQryInstrumentStatusField *pQryInstrumentStatus, int nRequestID);

	///������״̬��ѯ����
	virtual int ReqQrySGDataSyncStatus(CShfeFtdcQrySGDataSyncStatusField *pQrySGDataSyncStatus, int nRequestID);

	///��ֵ��Ȳ�ѯ
	virtual int ReqQryHedgeVolume(CShfeFtdcQryHedgeVolumeField *pQryHedgeVolume, int nRequestID);

	///�����޶��ѯ����
	virtual int ReqQryCreditLimit(CShfeFtdcQryCreditLimitField *pQryCreditLimit, int nRequestID);

	///�Ǳ���ϱ�����ѯ����
	virtual int ReqQryCombOrder(CShfeFtdcQryCombOrderField *pQryCombOrder, int nRequestID);

	///ִ�������ѯ����
	virtual int ReqQryExecOrder(CShfeFtdcQryExecOrderField *pQryExecOrder, int nRequestID);

	///��ͨ�����ѯ����
	virtual int ReqQryMarketData(CShfeFtdcQryMarketDataField *pQryMarketData, int nRequestID);

	///�����������ѯ����
	virtual int ReqQryBulletin(CShfeFtdcQryBulletinField *pQryBulletin, int nRequestID);

	///�����ѯ����
	virtual int ReqQryTopic(CShfeFtdcDisseminationField *pDissemination, int nRequestID);

	///�û����߲�ѯ����
	virtual int ReqQryUserSession(CShfeFtdcQryUserSessionField *pQryUserSession, int nRequestID);

	///�û���ѯ����
	virtual int ReqQryUser(CShfeFtdcQryUserField *pQryUser, int nRequestID);

	///��Ա��ѯ����
	virtual int ReqQryParticipant(CShfeFtdcQryParticipantField *pQryParticipant, int nRequestID);

	///��Լ��λ��ѯ
	virtual int ReqQryMBLMarketData(CShfeFtdcQryMBLMarketDataField *pQryMBLMarketData, int nRequestID);

	///��Ϣ��ѯ
	virtual int ReqQryInformation(CShfeFtdcQryInformationField *pQryInformation, int nRequestID);

	///�ͻ��ֲֲ�ѯ����
	virtual int ReqQryClientPositionV1(CShfeFtdcQryClientPositionV1Field *pQryClientPositionV1, int nRequestID);

	///���ʲ�ѯ����
	virtual int ReqQryExchangeRate(CShfeFtdcQryExchangeRateField *pQryExchangeRate, int nRequestID);
private:
	///����Ӧ��
	void OnRspError(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�û���¼Ӧ��
	void OnRspUserLogin(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�û��˳�Ӧ��
	void OnRspUserLogout(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����¼��Ӧ��
	void OnRspOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��������Ӧ��
	void OnRspOrderAction(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����¼��Ӧ��
	void OnRspQuoteInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���۲���Ӧ��
	void OnRspQuoteAction(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///OTC����¼��Ӧ��
	void OnRspOTCOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�û������޸�Ӧ��
	void OnRspUserPasswordUpdate(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ִ������¼��Ӧ��
	void OnRspExecOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ִ���������Ӧ��
	void OnRspExecOrderAction(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������¼��Ӧ��
	void OnRspAdminOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�Ǳ���ϱ���¼��Ӧ��
	void OnRspCombOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��������Ӧ��
	void OnRspSubscribeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��������������Ӧ��
	void OnRspBulletin(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������������ϢӦ��
	void OnRspInformation(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Լ����״̬�ı�Ӧ��
	void OnRspInstrumentStatusUpdate(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ǿ���û��˳�Ӧ��
	void OnRspForceUserExit(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�û��Ựɾ��Ӧ��
	void OnRspForceUserLogout(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����������ͬ��״̬�ı�Ӧ��
	void OnRspExchangeDataSyncStatusUpdate(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����������ͬ��״̬�ı�Ӧ��
	void OnRspSGDataSyncStatusUpdate(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա�ʽ��ѯӦ��
	void OnRspQryPartAccount(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������ѯӦ��
	void OnRspQryOrder(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���۲�ѯӦ��
	void OnRspQryQuote(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ɽ�����ѯӦ��
	void OnRspQryTrade(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա�ͻ���ѯӦ��
	void OnRspQryClient(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա�ֲֲ�ѯӦ��
	void OnRspQryPartPosition(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ͻ��ֲֲ�ѯӦ��
	void OnRspQryClientPosition(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Լ��ѯӦ��
	void OnRspQryInstrument(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Լ����״̬��ѯӦ��
	void OnRspQryInstrumentStatus(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������״̬��ѯӦ��
	void OnRspQrySGDataSyncStatus(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ֵ���Ӧ��
	void OnRspQryHedgeVolume(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����޶��ѯӦ��
	void OnRspQryCreditLimit(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�Ǳ���ϱ�����ѯӦ��
	void OnRspQryCombOrder(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ִ�������ѯӦ��
	void OnRspQryExecOrder(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ͨ�����ѯӦ��
	void OnRspQryMarketData(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����������ѯ����Ӧ��
	void OnRspQryBulletin(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����ѯӦ��
	void OnRspQryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�û����߲�ѯӦ��
	void OnRspQryUserSession(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�û���ѯӦ��
	void OnRspQryUser(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա��ѯӦ��
	void OnRspQryParticipant(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Լ��λ��ѯӦ��
	void OnRspQryMBLMarketData(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ϣ��ѯӦ��
	void OnRspQryInformation(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ɽ��ر�
	void OnRtnTrade(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����ر�
	void OnRtnOrder(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ִ������ر�
	void OnRtnExecOrder(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���ۻر�
	void OnRtnQuote(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�Ǳ���ϱ����ر�
	void OnRtnCombOrder(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Լ����״̬֪ͨ
	void OnRtnInstrumentStatus(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���Ӻ�Լ֪ͨ
	void OnRtnInsInstrument(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ɾ����Լ֪ͨ
	void OnRtnDelInstrument(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���Ӻ�Լ����֪ͨ
	void OnRtnInsCombinationLeg(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ɾ����Լ����֪ͨ
	void OnRtnDelCombinationLeg(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��������֪ͨ
	void OnRtnAliasDefine(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����������֪ͨ
	void OnRtnFlowMessageCancel(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����֪ͨ
	void OnRtnBulletin(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ͨ����֪ͨ
	void OnRtnMarketData(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�������֪ͨ
	void OnRtnDepthMarketData(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������֪ͨ
	void OnRtnAdminOrder(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����¼�����ر�
	void OnErrRtnOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������������ر�
	void OnErrRtnOrderAction(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����¼�����ر�
	void OnErrRtnQuoteInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���۲�������ر�
	void OnErrRtnQuoteAction(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ִ������¼�����ر�
	void OnErrRtnExecOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ִ�������������ر�
	void OnErrRtnExecOrderAction(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�Ǳ���ϱ���¼�����ر�
	void OnErrRtnCombOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���ʲ�ѯӦ��
	void OnRspQryExchangeRate(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
};

#endif
