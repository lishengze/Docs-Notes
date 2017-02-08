// TcpClient.h: interface for the CTcpClient class .
//
// 2006.10.11	�Ժ��	Ϊ֧��SSL�����ӷ���CreateChannel 
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TCPCLIENT_H__FE5CED65_6EC3_11D7_BB64_444553540000__INCLUDED_)
#define AFX_TCPCLIENT_H__FE5CED65_6EC3_11D7_BB64_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Client.h"
/**CTcpClient��һ������TCP������ͻ���
*/
class  CTcpClient : public CClientBase
{
public:
	/**���캯������ɳ�ʼ��
	*/
	CTcpClient();
	
	/**��������
	*/
	virtual ~CTcpClient();

	/**����TCP������ʵ�ֺ���
	* @param pName ��������������Ϣ
	* @return ��NULL �ɹ����ѽ�����Channel
	* @return NULL ʧ��
	*/
	virtual CChannel *Connect(CServiceName *pName);
	
protected:
	virtual CChannel *CreateChannel(int id);
};


#endif // !defined(AFX_TCPCLIENT_H__FE5CED65_6EC3_11D7_BB64_444553540000__INCLUDED_)
