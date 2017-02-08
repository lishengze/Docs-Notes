// FibSubscribeApi.h: interface for the CFibSubscribeApi class.
//
// 20070905 �Ժ�� ������UnSubscribe����
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FIBSUBSCRIBEAPI_H__0A7C37A1_9D5D_45CE_8AB2_F37DD0CDDF47__INCLUDED_)
#define AFX_FIBSUBSCRIBEAPI_H__0A7C37A1_9D5D_45CE_8AB2_F37DD0CDDF47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Reactor.h"
#include "Subscriber.h"

class CFibSubscribeApi  
{
public:
	/** ��ȡ���ӿڹ����������ַ
	*@return ���ӿڹ����������ַ
	*/
	virtual const char *GetAddress() = 0;

	/*����һ������
	* @param pSubscriber ������
	* @param dwSubscriberID �����ߴ���
	*/
	virtual void Subscribe(CSubscriber *pSubscriber, DWORD dwSubscriberID) = 0;

	/*����һ������
	* @param pSubscriber ������
	*/
	virtual void UnSubscribe(CSubscriber *pSubscriber) = 0;

	/**����������Ķ����ߵ�CPN
	* @param nCommPhaseNo Ҫ���õ���CPN
	*/
	virtual void SetSubCommPhaseNo(WORD nCommPhaseNo) = 0;

	/**ɾ�����ӿ�
	*/
	virtual void Release() = 0;

	/**�����ӿ�
	* @param pReactor ������Ӧ��
	* @param nNodeID  �ڵ��ʶ
	* @return �������Ľӿ�
	*/
	static CFibSubscribeApi *CreateSubscribeApi(CReactor *pReactor, DWORD nNodeID, char *pszAddress);

protected:
	virtual ~CFibSubscribeApi(){};
};

#endif // !defined(AFX_FIBSUBSCRIBEAPI_H__0A7C37A1_9D5D_45CE_8AB2_F37DD0CDDF47__INCLUDED_)
