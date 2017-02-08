// TcpNetworkFactory.h: interface for the CTcpNetworkFactory class.
//
// 2006.10.11	�Ժ��	������TCP_NETWORK_NAME����CPP�У�
//						��ֹ��ΰ���������ظ����� 
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TCPNETWORKFACTORY_H__9C863AA5_2C99_445B_B6FD_C1459913BB4F__INCLUDED_)
#define AFX_TCPNETWORKFACTORY_H__9C863AA5_2C99_445B_B6FD_C1459913BB4F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "NetworkFactory.h"

class CTcpNetworkFactory : public CNetworkFactory  
{
public:
	CTcpNetworkFactory();
	virtual ~CTcpNetworkFactory();

	/**����һ��TCP�������ˡ����Service Name��ƥ����������������೧��������
	* @param pName	��������
	* @return  �õ��ķ�������
	*/
	virtual CServerBase *CreateServer(CServiceName *pName);
	
	/**����һ��TCP�ͻ��ˡ����Service Name��ƥ����������������೧��������
	* @param	pName	Ҫ���ӵķ�������
	* @return   �õ��Ŀͻ���
	*/
	virtual CClientBase *CreateClient(CServiceName *pName);

private:
	static CTcpNetworkFactory m_instance;
};

#endif // !defined(AFX_TCPNETWORKFACTORY_H__9C863AA5_2C99_445B_B6FD_C1459913BB4F__INCLUDED_)
