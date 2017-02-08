// SubscribeStub.h: interface for the CSubscribeStub class.
//
// 20070905 �Ժ�� ������UnSubscribe����
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SUBSCRIBESTUB_H__CE014FB6_D01E_4127_B9BA_FFFFB746E6F1__INCLUDED_)
#define AFX_SUBSCRIBESTUB_H__CE014FB6_D01E_4127_B9BA_FFFFB746E6F1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FibSubscribeApi.h"
#include "XTPPubSession.h"

class CSubscribeStub : public CFibSubscribeApi  
{
public:
	CSubscribeStub(CReactor *pReactor, DWORD nNodeID, char *pszAddress);
	
	/** ��ȡ���ӿڹ����������ַ
	*@return ���ӿڹ����������ַ
	*/
	virtual const char *GetAddress();

	/*����һ������
	* @param pSubscriber ������
	* @param dwSubscriberID �����ߴ���
	*/
	virtual void Subscribe(CSubscriber *pSubscriber, DWORD dwSubscriberID);

	/*����һ������
	* @param pSubscriber ������
	*/
	virtual void UnSubscribe(CSubscriber *pSubscriber);

	/**����������Ķ����ߵ�CPN
	* @param nCommPhaseNo Ҫ���õ���CPN
	*/
	virtual void SetSubCommPhaseNo(WORD nCommPhaseNo);

	/**ɾ�����ӿ�
	*/
	virtual void Release();

protected:
	virtual ~CSubscribeStub();

private:
	CXTPPubSession *m_pSession;
	char m_szAddress[100];
};

#endif // !defined(AFX_SUBSCRIBESTUB_H__CE014FB6_D01E_4127_B9BA_FFFFB746E6F1__INCLUDED_)
