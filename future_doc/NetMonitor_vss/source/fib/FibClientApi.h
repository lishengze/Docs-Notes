// FibClientApi.h: interface for the CFibClientApi class.
//
// 20070822	�Ժ��	���SessionFactory�޸ģ�֧��������ӷ�����
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FIBCLIENTAPI_H__16C39C84_4AAF_466A_AD14_7D8C09CC10B6__INCLUDED_)
#define AFX_FIBCLIENTAPI_H__16C39C84_4AAF_466A_AD14_7D8C09CC10B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "XTPPackage.h"
#include "Reactor.h"

class CResponseHandler
{
public:
	virtual void OnResponse(CXTPPackage *pPackage) = 0;
};

class CFibClientApi  
{
public:
	//-------------------���ýӿں���-------------------------------
	/**��ȡ�ڵ��ʶ
	*/
	virtual DWORD GetNodeID() = 0;

	/**ע������/Ӧ��ģʽ��������ַ
	* ����ע������������ַ��API�������������
	* @param nServerID �ṩ����ķ�������ʶ
	* @param pszAddress Ҫ���ӵķ�������ַ����ʽΪ"protocol://address:port"
	* @param pRspHandler Ӧ�������
	*/
	virtual void RegisterServer(DWORD nServerID, char *pszAddress, CResponseHandler *pRspHandler) = 0;

	/**�����ӿ�����
	*/
	virtual void Start() = 0;
	//-------------------��Ϣ�ӿں���-------------------------------
	/**����һ����Ϣ
	* @return ����������Ϣ
	*/
	virtual CXTPPackage *CreateMessage() = 0;
	
	//-------------------����Ӧ��ӿں���-------------------------------
	/**����һ������
	* @param nServiceID ����˿�
	* @param pMessage ������Ϣ
	* @return FIB_RESULT_OK ����ɹ�����
	*         <0 ����ʧ��
	*/
	virtual int Request(DWORD nServerID, CXTPPackage *pMessage) = 0;

	/**ɾ�����ӿ�
	*/
	virtual void Release() = 0;

	//-------------------�����ӿں���-------------------------------
	/**�����ӿ�
	* @param pReactor ������Ӧ��
	* @param nNodeID  �ڵ��ʶ
	* @return �������Ľӿ�
	*/
	static CFibClientApi *CreateClientApi(CReactor *pReactor, DWORD nNodeID);

protected:
	virtual ~CFibClientApi(){};
};

#endif // !defined(AFX_FIBCLIENTAPI_H__16C39C84_4AAF_466A_AD14_7D8C09CC10B6__INCLUDED_)
