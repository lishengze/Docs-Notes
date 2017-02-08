// NetworkFactory.h: interface for the CNetworkFactory class .
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NETWORKFACTORY_H__FE5CED64_6EC3_11D7_BB64_444553540000__INCLUDED_)
#define AFX_NETWORKFACTORY_H__FE5CED64_6EC3_11D7_BB64_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Channel.h"
#include "Client.h"
#include "Server.h"
#include "ServiceName.h"

/**CNetworkFactory�������������Ķ��󹤳���������Щ����������������߲���Ҫ��
*ʽ�ص����κ��������Ĺ��캯����ֻ��Ҫ����һ��CNetworkFactory��Ȼ������������
*���������������������
*/
class  CNetworkFactory
{
public:
	CNetworkFactory();
	virtual ~CNetworkFactory();

	static CNetworkFactory *GetInstance();

	/**����һ���������ˡ�������ֻ�����ε��������е�ÿ���೧�������������ˡ�
	* ����Ĵ�������Ҫ����������ͨ������ʵ��
	* @param pName	��������
	* @return  �õ��ķ�������
	*/
	virtual CServerBase *CreateServer(CServiceName *pName);
	
	/**ͨ�������ͻ��ˣ�����һ�����ӡ�
	* @param	pName	Ҫ���ӵķ�������
	* @return       �õ�����������
	*/
	virtual CChannel *CreateChannel(CServiceName *pName);

protected:
	/**����һ���ͻ��ˡ�������ֻ�����ε��������е�ÿ���೧�������������ˡ�
	* ����Ĵ�������Ҫ����������ͨ������ʵ��
	* @param	pName	Ҫ���ӵķ�������
	* @return   �õ��Ŀͻ���
	*/
	virtual CClientBase *CreateClient(CServiceName *pName);

	void RegisterFactory();

private:
	static CNetworkFactory *m_pInstance;
	
	CNetworkFactory *m_pNext;
};

#endif // !defined(AFX_NETWORKFACTORY_H__FE5CED64_6EC3_11D7_BB64_444553540000__INCLUDED_)
