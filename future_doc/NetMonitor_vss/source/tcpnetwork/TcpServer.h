// TcpServer.h: interface for the CTcpServer class .
//
// 2006.10.11	�Ժ��	Ϊ֧��SSL�����ӷ���CreateChannel 
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TCPSERVER_H__FE5CED67_6EC3_11D7_BB64_444553540000__INCLUDED_)
#define AFX_TCPSERVER_H__FE5CED67_6EC3_11D7_BB64_444553540000__INCLUDED_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Server.h"

/**CTcpServer��һ������TCP�������������
*/
class  CTcpServer : public CServerBase
{
public:
	/**���캯������ָ���ķ��������������������
	* @param  pName	ָ���ķ�������
	*/
	CTcpServer(CServiceName *pName);
	
	/**�����������ͷ�ռ�õ���Դ
	*/
	virtual ~CTcpServer();
	
	/** ����TCP�Ļ�ȡselect�ļ��ŷ���
	* @return selectʱ���ļ���
	*/
	virtual int GetId(void);
protected:
	/**����TCP�ĵȴ��ͻ������ӷ���
	* @param  wait	��ʾ��Ҫ�ȴ������Ӳŷ��أ�0��ʾ���ȴ�
	* @return NULL   ��Channelδ���ɹ�
	* @return ��NULL �µ�Channel
	*/
	virtual CChannel *Accept(int wait);

	virtual CChannel *CreateChannel(int id);
private:
	int m_nID;	/**< �洢���������˵��ļ��� */
};

#endif // !defined(AFX_TCPSERVER_H__FE5CED67_6EC3_11D7_BB64_444553540000__INCLUDED_)
