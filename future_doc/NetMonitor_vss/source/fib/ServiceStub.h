// ServiceStub.h: interface for the CServiceStub class.
//
// 20070822	�Ժ��	���SessionFactory�޸ģ�֧��������ӷ�����
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SERVICESTUB_H__9E755765_B46D_43A9_B128_55048BB2AD89__INCLUDED_)
#define AFX_SERVICESTUB_H__9E755765_B46D_43A9_B128_55048BB2AD89__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "EventHandler.h"
#include "SessionFactory.h"
#include "ServiceSession.h"
#include "FibClientApi.h"

class CServiceStub : public CFibClientApi
{
public:
	CServiceStub(CReactor *pReactor, DWORD nNodeID);
	//-------------------���ýӿں���-------------------------------
	/**��ȡ�ڵ��ʶ
	*/
	virtual DWORD GetNodeID();

	/**ע������/Ӧ��ģʽ��������ַ
	* ����ע������������ַ��API�������������
	* @param nServerID �ṩ����ķ�������ʶ
	* @param pszAddress Ҫ���ӵķ�������ַ����ʽΪ"protocol://address:port"
	* @param pRspHandler Ӧ�������
	*/
	virtual void RegisterServer(DWORD nServerID, char *pszAddress, CResponseHandler *pRspHandler);

	/**�����ӿ�����
	*/
	virtual void Start();
	//-------------------��Ϣ�ӿں���-------------------------------
	/**����һ����Ϣ
	* @return ����������Ϣ
	*/
	virtual CXTPPackage *CreateMessage();
		
	//-------------------����Ӧ��ӿں���-------------------------------
	/**����һ������
	* @param nServiceID ����˿�
	* @param pMessage ������Ϣ
	* @return FIB_RESULT_OK ����ɹ�����
	*         <0 ����ʧ��
	*/
	virtual int Request(DWORD nServerID, CXTPPackage *pMessage);

	/**ɾ�����ӿ�
	*/
	virtual void Release();

protected:
	virtual ~CServiceStub();
	CSessionFactory *GetSessionFactory(DWORD nServerID);
	CServiceSession *GetServerSession(DWORD nServerID);
protected:
	typedef CHashMap<DWORD, CSessionFactory *, HashInt> CServerMap;
	CServerMap m_mapServer;
	DWORD m_nNodeID;
	CReactor *m_pReactor;
};


#endif // !defined(AFX_SERVICESTUB_H__9E755765_B46D_43A9_B128_55048BB2AD89__INCLUDED_)
