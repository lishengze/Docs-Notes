// ServiceSkeleton.h: interface for the CServiceSkeleton class.
//
// 20080727 �Ժ�� NT-0048:��չCSessionFactory::CreateSession���������ڴ���
//                 �Ựʱ���ֲ�ͬ������
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SERVICESKELETON_H__7B255FA5_6400_48EE_A24A_A8A0A1C65664__INCLUDED_)
#define AFX_SERVICESKELETON_H__7B255FA5_6400_48EE_A24A_A8A0A1C65664__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FibServerApi.h"
#include "SessionFactory.h"
#include "ServiceSession.h"

class CServiceSkeleton : public CSessionFactory, public CFibServerApi, public CXTPReqCallback
{
public:
	/**���캯��
	* @param pReactor ��Ӧ��
	* @param nServerID  ��������ʶ���ṩ��ͬ�����һ�������ʹ��ͬһ��ServerID
	*/
	CServiceSkeleton(CReactor *pReactor, DWORD nServerID, int nMaxSession);
	
	//-------------------���ýӿں���-------------------------------
	/**��ȡ�ڵ��ʶ
	*/
	virtual DWORD GetServerID();

	/**ע������/Ӧ��ģʽ�������ļ�����ַ
	* @param pszAddress Ҫ�����ĵ�ַ����ʽΪ"protocol://address:port"
	*/
	virtual void RegisterListener(char *pszAddress);

	//-------------------��Ϣ�ӿں���-------------------------------
	/**����һ����Ϣ
	* @return ����������Ϣ
	*/
	virtual CXTPPackage *CreateMessage();
	
	//-------------------����Ӧ��ӿں���-------------------------------
	/**����һ��Ӧ��
	* @param pMessage ������Ϣ
	* @return FIB_RESULT_OK ����ɹ�����
	*         <0 ����ʧ��
	*/
	virtual int Response(CXTPPackage *pMessage, DWORD nSessionID);

	/**ע�����
	* @param pService ����
	*/
	virtual void RegisterService(CService *pService);

	/**ɾ�����ӿ�
	*/
	virtual void Release();

	virtual CSession *CreateSession(CChannel *pChannel, DWORD);

	int HandleRequest(CXTPPackage *pXTPPackage, CXTPSession *pSessin);

	virtual void OnSessionConnected(CSession *pSession);
	virtual void OnSessionDisconnected(CSession *pSession, int nReason);

protected:
	virtual ~CServiceSkeleton();

protected:
	typedef CHashMap<DWORD, CServiceSession *, HashInt> CServiceSessionMap;
	CServiceSessionMap m_mapServiceSession;
	CService* m_pService;
	DWORD m_nServerID;
	CReactor *m_pReactor;
};

#endif // !defined(AFX_SERVICESKELETON_H__7B255FA5_6400_48EE_A24A_A8A0A1C65664__INCLUDED_)
