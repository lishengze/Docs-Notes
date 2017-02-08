// UdpChannel.h: interface for the CUdpChannel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UDPCHANNEL_H__6DE6311B_C987_4246_A61D_53ADA1F3D619__INCLUDED_)
#define AFX_UDPCHANNEL_H__6DE6311B_C987_4246_A61D_53ADA1F3D619__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Channel.h"

struct sockaddr_in;

class CUdpChannel : public CChannel
{
public:
	CUdpChannel(int id, char *pTargetAddress, WORD wTargetPort);
	virtual ~CUdpChannel();

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

private:
	sockaddr_in *m_pTargetAddr; //��������ַ�ṹ
};

#endif // !defined(AFX_UDPCHANNEL_H__6DE6311B_C987_4246_A61D_53ADA1F3D619__INCLUDED_)
