/////////////////////////////////////////////////////////////////////////
///@system 新一代交易所系统
///@company 上海期货信息技术有限公司
///@file FtdcSysUserApiImpl.h
///@brief 定义了客户端接口实现
///@history 
///20060106	赵鸿昊		创建该文件
///20061012	赵鸿昊		增加对SSL身份校验的支持
///20070216	章捷			添加tradeapi流控的预定义值。
/////////////////////////////////////////////////////////////////////////

#if !defined(_FTDCSYSUSERAPIIMPLBASE_H)
#define _FTDCSYSUSERAPIIMPLBASE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Flow.h"
#include "Mutex.h"
#include "FtdcSysUserApi.h"
#include "SessionFactory.h"
#include "SelectReactor.h"
#include "FTDCSubscriber.h"
#include "FtdPackageDesc.h"
#include "FTDCSession.h"
#include "Storage.h"


class CFtdcSysUserApiImplBase;

class CFtdcUserSubscriber : public CFTDCSubscriber
{
public:
	CFtdcUserSubscriber(CFtdcSysUserApiImplBase *pUserApiImplBase,
		CFlow *pFlow, WORD wSequenceSeries);
	virtual ~CFtdcUserSubscriber();
	virtual void SetCommPhaseNo(WORD wCommPhaseNo);
	virtual WORD GetSequenceSeries();
	virtual DWORD GetReceivedCount();
	virtual void HandleMessage(CFTDCPackage *pMessage);
	TE_RESUME_TYPE GetResumeType();
	void SetResumeType(TE_RESUME_TYPE nResumeType);
	void MoveTo(int nOffset);

	void CleanControl(void);

	int AddOneToFlow(void);

private:
	CFlow *m_pFlow;
	WORD m_wSequenceSeries;
	CFtdcSysUserApiImplBase *m_pUserApiImplBase;
	TE_RESUME_TYPE m_nResumeType;

	// flow control by zhangjie
	unsigned int m_nMaxUnfinished;
	unsigned int m_nMaxPerSecond;
	unsigned int m_nTimeoutForQueryFlow;

	list<time_t> m_nUnfinished;
	unsigned int m_nCntPerSecond;
	time_t m_lastTime;
};

class CMarketDataFlowManager
{
public:
	CMarketDataFlowManager(const char *pszFlowPath);
	~CMarketDataFlowManager();
	CFlow *GetFlow(DWORD nTopicID);
	bool RegisterTopic(DWORD nTopicID);
private:
	typedef CHashMap<DWORD, CFlow *, HashInt> CFlowMap;
	CFlowMap m_mapFlow;
	string m_strFlowPath;
};

struct CTopicDepthMarketDataField : public CFTDDepthMarketDataField
{
	WORD SequenceSeries;
};

class CTopicDepthMarketDataStorage :public CStorage<CTopicDepthMarketDataField>
{
public:
	DEFINE_INDEX_FUNC_2(0, WORD, SequenceSeries, const char *, InstrumentID);
	CTopicDepthMarketDataStorage()
	{
		CREATE_INDEX_2(SequenceSeries, InstrumentID);
	}
};

class CFtdcSysUserApiImplBase : public CShfeFtdcSysUserApi, public CSessionFactory, public CFTDCSessionCallback
{
public:
	CFtdcSysUserApiImplBase(const char *pszFlowPath, CSelectReactor *pReactor);
	
	~CFtdcSysUserApiImplBase();

	virtual void Init();
	
	virtual int Join();
	
	virtual void Release();

	virtual const char *GetTradingDay();
	
	virtual void RegisterFront(char *pszFrontAddress);
	
	virtual void RegisterSpi(CShfeFtdcSysUserSpi *pSpi);
	
	//virtual int RegisterCertificateFile(const char *pszCertFileName, const char *pszKeyFileName, 
	//	const char *pszCaFileName, const char *pszKeyFilePassword);
		
	virtual void SubscribeMarketDataTopic(int nTopicID, TE_RESUME_TYPE nResume);

	virtual void SubscribePartAccount(void);

	virtual void SubscribePrivateTopic(TE_RESUME_TYPE nResumeType);
	
	virtual void SubscribePublicTopic(TE_RESUME_TYPE nResumeType);
	
	virtual int ReqUserLogin(CShfeFtdcReqUserLoginField *pReqUserLoginField, int nRequestID);
	
	virtual void HandleResponse(CFTDCPackage *pMessage, WORD wSequenceSeries) = 0;

	virtual int HandlePackage(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);
protected:
	virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);
	virtual void OnSessionConnected(CSession *pSession);
	virtual void OnSessionDisconnected(CSession *pSession, int nReason);
	virtual void OnSessionWarning(CSession *pSession, int nReason, int nParam);	

	int RequestToDialogFlow();
	int RequestToQueryFlow();
	int RequestDirectly();
	
	void OnIntlRtnDepthMarketData(CFTDCPackage *pMessage, WORD wSequenceSeries);
	void OnIntlRtnDissemination(CFTDCPackage *pMessage, WORD wSequenceSeries);

	void OnRtnDepthMarketData(CFTDDepthMarketDataField *pMarketData, WORD wSequenceSeries);
private:
	void CreateDialogFlow();
	void RemoveDialogFlow();
	void CreateQueryFlow();
	void RemoveQueryFlow();
	void CreateSubscriber(int nTopicID, CFlow *pFlow, TE_RESUME_TYPE nResumeType);
protected:
	CShfeFtdcSysUserSpi *m_pSpi;
	CFTDCPackage m_reqPackage;
	CMutex m_mutexAction;


private:
	CSelectReactor *m_pReactor;
	CFlow *m_pDialogReqFlow;
	CFlow *m_pDialogRspFlow;
	CFlow *m_pQueryReqFlow;
	CFlow *m_pQueryRspFlow;
	CFlow *m_pPrivateFlow;
	CFlow *m_pPublicFlow;
	CFlow *m_pTradingDayFlow;

	typedef map<WORD, CFtdcUserSubscriber *> CUserSubscriberMap;
	CUserSubscriberMap m_mapSubscriber;
	CDateType m_TradingDay;
	CMarketDataFlowManager *m_pMarketDataFlowManager;
	DWORD m_nSessionID;
	string m_strFlowPath;

	CTopicDepthMarketDataStorage m_storageTopicDepthMarketData;
};

#endif
