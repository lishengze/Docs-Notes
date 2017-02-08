// PublishStub.h: interface for the CPublishStub class.
//
// 20070905 �Ժ�� ������CancelPublish����
// 20110119 ����   NT-0121��front������������
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PUBLISHSTUB_H__BD24DD44_B6E3_4E21_B423_D800FC93AC9E__INCLUDED_)
#define AFX_PUBLISHSTUB_H__BD24DD44_B6E3_4E21_B423_D800FC93AC9E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FibPublishApi.h"
#include "XTPPubSession.h"
#include "HashMap.h"

class CPublishStub : public CFibPublishApi, public CXTPFlowManager   
{
public:
	CPublishStub(CReactor *pReactor, DWORD nNodeID, char *pszAddress);

	/** ��ȡ���ӿڹ����������ַ
	*@return ���ӿڹ����������ַ
	*/
	virtual const char *GetAddress();

	/**����һ����Ϣ
	* @return ����������Ϣ
	*/	
	virtual CXTPPackage *CreateMessage();

	//-------------------�������Ľӿ�-------------------------------
	/**ע����Ϣ����
	* @param pFlow Ҫע�����Ϣ����
	* @param nSubjectID Ҫ����������
	*/
	virtual void RegisterFlow(CReadOnlyFlow *pFlow, DWORD nSubjectID);

	/**ȡ����������
	* @param nSubjectID Ҫȡ������������
	*/
	virtual void CancelPublish(DWORD nSubjectID);

	/**���������ȡһ��ע�����
	* @param nSubjectID ����
	* @return ��ȡ������
	*/
	virtual CReadOnlyFlow *GetFlow(DWORD nSubjectID);

	/**ɾ�����ӿ�
	*/
	virtual void Release();

	/**���ò���
	* @param handler �¼�������
	* @param nClock ���������е�ʱ��id
	*/
	virtual void SetParams(CEventHandler* handler, DWORD nClock);

private:
	virtual ~CPublishStub();
	inline DWORD GetNodeID();
private:
	typedef CHashMap<DWORD, CReadOnlyFlow *, HashInt> CFlowMap;
	CFlowMap m_mapFlow;
	CXTPPubSession *m_pSession;
	DWORD m_nNodeID;
	char m_szAddress[100];

	// �¼�������
	CEventHandler* m_Handler;

	// �����ߵ�ʱ��id
	DWORD m_nClock;
};

inline DWORD CPublishStub::GetNodeID()
{
	return m_nNodeID;
}

#endif // !defined(AFX_PUBLISHSTUB_H__BD24DD44_B6E3_4E21_B423_D800FC93AC9E__INCLUDED_)
