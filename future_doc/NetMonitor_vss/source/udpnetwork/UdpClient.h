// UdpClient.h: interface for the CUdpClient class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UDPCLIENT_H__CFF7736E_8042_42C5_847C_B3A779399B12__INCLUDED_)
#define AFX_UDPCLIENT_H__CFF7736E_8042_42C5_847C_B3A779399B12__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Client.h"
#include "Client.h"

class CUdpClient : public CClientBase 
{
public:
	CUdpClient();
	virtual ~CUdpClient();

	/**����UDP������ʵ�ֺ���
	* @param pName ��������������Ϣ
	* @return ��NULL �ɹ����ѽ�����Channel
	* @return NULL ʧ��
	*/
	virtual CChannel *Connect(CServiceName *pName);

};

#endif // !defined(AFX_UDPCLIENT_H__CFF7736E_8042_42C5_847C_B3A779399B12__INCLUDED_)
