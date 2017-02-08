// TcpChannel.h: interface for the CTcpChannel class .
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TCPCHANNEL_H__FE5CED66_6EC3_11D7_BB64_444553540000__INCLUDED_)
#define AFX_TCPCHANNEL_H__FE5CED66_6EC3_11D7_BB64_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Channel.h"

/**CTcpChannel��һ������TCP���������Ӷ���
*/
class  CTcpChannel : public CChannel
{
public:
	/**���캯����ʹ��ָ����socket�������˶���
	* @param id	ָ����socket
	*/
	CTcpChannel(int id);
	
	/**��������
	*/
	virtual ~CTcpChannel(void);
	
	/**��ȡ�Է��ĵ�ַ��������IP��ַ��
	* @return	�Է��ĵ�ַ
	*/
	virtual char *GetRemoteName(void);
protected:

	/**����TCP�Ķ�ȡʵ�ֺ���
	* @param number	buffer�������ĳ���
	* @param buffer	��Ż�����
	* @return >0 ʵ�ʶ�ȡ�ó���
	* @return 0  ��ȡʱ���жϷ���
	* @return -1 ����Ͽ�
	*/
	virtual int ReadImp(int number, char *buffer);


	/**����TCP��д��ʵ�ֺ���
	* @param number	׼�����͵ĳ���
	* @param buffer	��Ż�����
	* @return >0 ʵ�ʷ��͵ó���
	* @return 0  ��ȡʱ���жϷ���
	* @return -1 ����ʧ��
	*/
	virtual int WriteImp(int number, char *buffer);

	
	/**����TCP���жϿɶ���ʵ�ֺ���
	* @return true  �ɶ�
	* @return false ���ɶ�
	*/
	virtual bool AvailableImp(void);
	
	/**����TCP�ĶϿ�����ʵ�ֺ���
	* @return true  �Ͽ��ɹ�
	* @return false �Ͽ�ʧ��
	*/
	virtual bool DisconnectImp(void);
	
	/**����TCP�ļ��������ʵ�ֺ���
	* @return true  ��������
	* @return false ���ӶϿ�
	*/
	virtual bool CheckConnectionImp(void);

protected:
	DWORD m_dwInAddr;
};

#endif // !defined(AFX_TCPCHANNEL_H__FE5CED66_6EC3_11D7_BB64_444553540000__INCLUDED_)
