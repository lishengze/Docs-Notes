// FibServerApi.h: interface for the CFibServerApi class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FIBSERVERAPI_H__022BDC62_A62D_46E8_86E7_E725BD80D558__INCLUDED_)
#define AFX_FIBSERVERAPI_H__022BDC62_A62D_46E8_86E7_E725BD80D558__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "XTPPackage.h"
#include "Reactor.h"

class CService
{
public:
	virtual void OnRequest(CXTPPackage *pRequest, DWORD nSessionID) = 0;
	virtual void OnSessionConnected(DWORD nSessionID) = 0;
	virtual void OnSessionDisconnected(DWORD nSessionID) = 0;
};

class CFibServerApi  
{
public:
	//-------------------���ýӿں���-------------------------------
	/**��ȡ�ڵ��ʶ
	*/
	virtual DWORD GetServerID() = 0;

	/**ע������/Ӧ��ģʽ�������ļ�����ַ
	* @param pszAddress Ҫ�����ĵ�ַ����ʽΪ"protocol://address:port"
	*/
	virtual void RegisterListener(char *pszAddress) = 0;

	//-------------------��Ϣ�ӿں���-------------------------------
	/**����һ����Ϣ
	* @return ����������Ϣ
	*/
	virtual CXTPPackage *CreateMessage() = 0;
	
	//-------------------����Ӧ��ӿں���-------------------------------
	/**����һ��Ӧ��
	* @param pMessage ������Ϣ
	* @return FIB_RESULT_OK ����ɹ�����
	*         <0 ����ʧ��
	*/
	virtual int Response(CXTPPackage *pMessage, DWORD nSessionID) = 0;

	/**ע�����
	* @param pService ����
	*/
	virtual void RegisterService(CService *pService) = 0;

	/**ɾ�����ӿ�
	*/
	virtual void Release() = 0;
	
	//-------------------�����ӿں���-------------------------------
	/**�����ӿ�
	* @param pReactor ������Ӧ��
	* @param nServerID  ��������ʶ���ṩ��ͬ�����һ�������ʹ��ͬһ��ServerID
	* @return �������Ľӿ�
	*/
	static CFibServerApi *CreateServerApi(CReactor *pReactor, DWORD nServerID, int nMaxSession);

protected:
	virtual ~CFibServerApi(){};
};

#endif // !defined(AFX_FIBSERVERAPI_H__022BDC62_A62D_46E8_86E7_E725BD80D558__INCLUDED_)
