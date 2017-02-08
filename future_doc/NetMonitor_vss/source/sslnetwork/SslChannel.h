// SslChannel.h: interface for the CSslChannel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SSLCHANNEL_H__DB087329_E818_4519_8E44_E96B24B95F17__INCLUDED_)
#define AFX_SSLCHANNEL_H__DB087329_E818_4519_8E44_E96B24B95F17__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcpChannel.h"

#include "openssl/rsa.h"      
#include "openssl/crypto.h"
#include "openssl/x509.h"
#include "openssl/pem.h"
#include "openssl/ssl.h"
#include "openssl/err.h"
#include "openssl/rand.h"

class CSslChannel : public CTcpChannel  
{
public:
	CSslChannel(SSL* pSSL, const char *pszCommonName, int id);
	virtual ~CSslChannel();

protected:
	/**����SSL�Ķ�ȡʵ�ֺ���
	* @param number	buffer�������ĳ���
	* @param buffer	��Ż�����
	* @return >0 ʵ�ʶ�ȡ�ó���
	* @return 0  ��ȡʱ���жϷ���
	* @return -1 ����Ͽ�
	*/
	virtual int ReadImp(int number, char *buffer);


	/**����SSL��д��ʵ�ֺ���
	* @param number	׼�����͵ĳ���
	* @param buffer	��Ż�����
	* @return >0 ʵ�ʷ��͵ó���
	* @return 0  ��ȡʱ���жϷ���
	* @return -1 ����ʧ��
	*/
	virtual int WriteImp(int number, char *buffer);
	
	/**��ȡ�Է��ı�ʶ
	* @return	�Է��ı�ʶ
	* @remark   ����NULL��ʾδ֪
	*/
	virtual char *GetRemoteCommonName(void);
private:
	SSL * m_pSSL;
	char *m_pszCommonName;
};

#endif // !defined(AFX_SSLCHANNEL_H__DB087329_E818_4519_8E44_E96B24B95F17__INCLUDED_)
