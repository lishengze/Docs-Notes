/////////////////////////////////////////////////////////////////////////
///@system ���׼��ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CFibClient2.h
///@brief	����������fens�Ự���ӿͻ���
///@history
///20130506	��С��		�������ļ�
///20130506	��С��		�޶�ע��
#ifndef SYS_FIBCLIENT2_H
#define SYS_FIBCLIENT2_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "public.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "NsSessionFactory.h"
#include "FTDCSession.h"
#include "FTDCSubscriber.h"
#include "XTPPackage.h"
#include "FibProxyData.h"
#include "FileFlow.h"
#include "CConfig.h"
#include "CachedFileFlow.h"
#include "XtpPackageDesc.h"
#include "FtdPackageDesc.h"
#include "CFPPSubscriber.h"

#include "EventConnect.h"

/////////////////////////////////////////////////////////////////////////
///CFibClient2����������fens�Ự���ӿͻ���
///@author	��С��
///@version	1.0,20130506
/////////////////////////////////////////////////////////////////////////
class CFibClient2 :
	public CNsSessionFactory,
	public CFTDCSessionCallback
{
	/* */
public:

	///���캯��
	///@param	pReactor		������CReactor����
	///@param	pszBaseFlowPath	������Ŀ¼
	///@param	pszUserID		��¼fibproxy�û���
	///@param	pszPassword		��¼fibproxy����
	CFibClient2(
		CReactor *pReactor,
		const char	*pszBaseFlowPath,
		const char	*pszUserID,
		const char	*pszPassword) :
	CNsSessionFactory(pReactor, 1)
	{
		m_bIsLogin = false;
		m_dwSessionID = 0;
		m_dwRequsetID = 0;
		m_strBaseFlowPath = pszBaseFlowPath;
		m_strUserID = pszUserID;
		m_strPassword = pszPassword;
		m_pkgRequest.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 100);
		m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 100);

		////��ʼ����������
		//time_t	timep;
		//time(&timep);
    //
		//struct tm *pGm = localtime(&timep);
		//
		//sprintf((char *)(g_strTryDate.data()),"%d%02d%02d" ,pGm->tm_year+1900 ,pGm->tm_mon+1 ,pGm->tm_mday);
	}

	///�����������⺯��
	///@param	wTopicID		����ID
	///@return	�޷���ֵ
	void CreateSubscriber(WORD wTopicID);

	///�������Ӻ���
	///@param	pChannel		������CChannel����
	///@param	bIsListener		�Ƿ���������
	///@return	�����õ�CSession����ָ��
	virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

	///�����ӽ���ʱ������
	///@param	pSession	���Ӷ�Ӧ��ָ��
	///@return	�޷���ֵ
	virtual void OnSessionConnected(CSession *pSession);

	///�����ӶϿ�ʱ����	
	///@param	pSession	���Ӷ�Ӧ��ָ��
	///@param	nReason		���ӶϿ���ԭ��
	///@return	�޷���ֵ
	virtual void OnSessionDisconnected(CSession *pSession, int nReason);

	///�¼������������˴�Ϊʱ������������������Ӧʱ��
	///@param	nIDEvent	ʱ�Ӽ��
	///@return	�޷���ֵ
	virtual void OnTimer(int nIDEvent);

	///��������
	///@param	pFTDCPackage	���յ���FTD��
	///@param	pSession		�հ�����������
	///@return	���ذ���������Ϣ
	int HandlePackage(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

	void SetEventConentSever(CEventConnect *pEventServer)
	{
		m_pEvtSrv = pEventServer;
	}

	void SetFrontServer(CFibClientServer *pFrontSrv)
	{
		m_pFrontSrv = pFrontSrv;
	}

	/* */
private:
	///ֱ�ӷ�������
	///@return	�޷���ֵ
	int RequestDirectly(void);

	///����������ʱ����
	///@return	�޷���ֵ
	void SetRetryTimer(void);

	///��¼������
	///@return	�޷���ֵ
	void ReqLogin(void);

	///����������
	///@return	�޷���ֵ
	void ReqSubscribe(void);

	///������ˮ����״̬��������
	void ResetSubscriber(void);

	///�����������Ӧ����
	///@param	pFTDCPackage	���յ���FTD��
	///@param	pSession		�հ�����������	
	///@return	�޷���ֵ
	void OnRspError(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

	///�ͻ��˵�¼��Ӧ�����Ӧ����
	///@param	pFTDCPackage	���յ���FTD��
	///@param	pSession		�հ�����������	
	///@return	�޷���ֵ
	void OnRspUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

	///�ͻ��˶�����Ӧ����
	///@param	pFTDCPackage	���յ���FTD��
	///@param	pSession		�հ�����������	
	///@return	�޷���ֵ
	void OnRspSubscribe(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

	/* */
private:
	///����ỰID
	DWORD m_dwSessionID;

	///�Ƿ��ѵ�¼�ı�־λ
	bool m_bIsLogin;

	///һ�γ�ʼ������ʹ�õ�FTD��
	CFTDCPackage m_pkgRequest;

	CFTDCPackage m_pkgSend;

	///Ӧ��ʱ��������ʱ��Ӧ������ID
	DWORD m_dwRequsetID;

	///��ʱ�ٽ�ֵ
	int m_nTimeOut;

	///��������SESSIONID����Ӧ���ɵ�MAP����
	typedef map<WORD, CFPPSubscriber *> CSubscriberMap;

	///��������SESSIONID����Ӧ���ɵ�MAP����
	CSubscriberMap	m_mapSubscriber;

	///������·��
	string	m_strBaseFlowPath;

	///������·��
	string	m_strFlowPath;

	///��¼Fibproxy�û���
	string	m_strUserID;

	///��¼Fibproxy����
	string	m_strPassword;

	CEventConnect *m_pEvtSrv;
	CFibClientServer *m_pFrontSrv;
};
#endif
