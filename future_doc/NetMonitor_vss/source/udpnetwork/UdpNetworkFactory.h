// UdpNetworkFactory.h: interface for the CUdpNetworkFactory class.
//
// 2006.10.11	�Ժ��	������UDP_NETWORK_NAME����CPP�У�
//						��ֹ��ΰ���������ظ����� 
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UDPNETWORKFACTORY_H__4EB0F1E7_5C35_43B0_B0B2_8160B72651D0__INCLUDED_)
#define AFX_UDPNETWORKFACTORY_H__4EB0F1E7_5C35_43B0_B0B2_8160B72651D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "NetworkFactory.h"

class CUdpNetworkFactory : public CNetworkFactory  
{
public:
	CUdpNetworkFactory();
	virtual ~CUdpNetworkFactory();
	
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
	static CUdpNetworkFactory m_instance;
};

#endif // !defined(AFX_UDPNETWORKFACTORY_H__4EB0F1E7_5C35_43B0_B0B2_8160B72651D0__INCLUDED_)
