// FibPubApiManager.h: interface for the CFibPubApiManager class.
//
// 20110119 ����   NT-0121��front������������
///20120416 ����   NT-0139 �ӿ���Ӧʱ�䣺xtpЭ�鶩�ĺͷ���֧�ֶ��߳�
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FIBPUBAPIMANAGER_H__31E0B14D_F679_4359_B470_1AC132227416__INCLUDED_)
#define AFX_FIBPUBAPIMANAGER_H__31E0B14D_F679_4359_B470_1AC132227416__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FibPublishApi.h"
#include "SelectReactor.h"

class CFibPubApiManager  
{
public:
	CFibPubApiManager(CReactor *pReactor, DWORD nNodeID);
	CFibPubApiManager(CReactorManager *pReactorManager, DWORD nNodeID);
	virtual ~CFibPubApiManager();
	CFibPublishApi *GetFibPublishApi(char *pszAddress);

	/**���ò���
	* ���÷���������
	* �������������ڷ���ǰ���������߰Ѷ����ߵ�ǰ���յ����ݸ���������
	* @param handler �¼�������
	* @param nClock ���������е�ʱ��id
	*/
	virtual void SetParams(CEventHandler* handler, DWORD nClock);

private:
	CReactor *m_pReactor;
	CReactorManager *m_pReactorManager;
	DWORD m_nNodeID;
	typedef map<const char *, CFibPublishApi *, ltstr> CFibPublishApiMap;
	CFibPublishApiMap m_mapFibPublishApi;

	// �¼�������
	CEventHandler* m_Handler;

	// �����ߵ�ʱ��id
	DWORD m_nClock;
};

#endif // !defined(AFX_FIBPUBAPIMANAGER_H__31E0B14D_F679_4359_B470_1AC132227416__INCLUDED_)
