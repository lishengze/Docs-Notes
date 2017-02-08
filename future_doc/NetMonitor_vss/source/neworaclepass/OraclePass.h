/////////////////////////////////////////////////////////////////////////
///@system OraclePass
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file OraclePass.h
///@brief������CAppContext�࣬���ڴ洢Ӧ�õ�ȫ����Ϣ��
///@history 
///20070702 ���ٻ�		�������ļ�
/////////////////////////////////////////////////////////////////////////
#ifndef ORACLEPASS_H
#define ORACLEPASS_H

#include "CConfig.h"
#include "CFileLogger.h"
#include "CCrypto.h"

/////////////////////////////////////////////////////////////////////////
///CAppContext������OraclePassӦ�ó���������ģ���Ҫ���ڴ洢������Ϣ��
/// TripleDesʹ�õĿ��
/// OraclePass��ini�ļ���Ϣ��
/// �ļ���־�ࣻ
/// TripleDes���ܽӿڣ�
/// Ӧ�ó���������argv[0]��
///@author	���ٻ�
///@version	1.0,20070722
/////////////////////////////////////////////////////////////////////////
class CAppContext {
public:
	///���캯��
	CAppContext() : m_pConfig(NULL), m_pLogger(NULL) {
		m_szPassword[0] = 0;
		m_szAppName[0] = 0;
	}
	///��������
	virtual ~CAppContext() {
	}
public:
	///����Ӧ�ó������ơ�
	void SetApp(char *szAppName) {
		strcpy(m_szAppName, szAppName);
	}
	///��ȡӦ�ó������ơ�
	char *GetAppName(void) {
		return m_szAppName;
	}
	///����ini�����ļ�
	void SetConfig(CConfig *pConfig) {
		m_pConfig = pConfig;
	}
	///��ȡini�����ļ�
	CConfig *GetConfig(void) {
		return m_pConfig;
	}
	///�����ļ���־
	void SetLogger(CFileLogger *pLogger) {
		m_pLogger = pLogger;
	}
	///��ȡ�ļ���־
	CFileLogger *GetLogger(void) {
		return m_pLogger;
	}
	///���ü��ܽӿ�
	void SetCrypto(IEncryptAlgorithm *pCrypto) {
		m_pCrypto = pCrypto;
	}
	///��ȡ���ܽӿ�
	IEncryptAlgorithm *GetCrypto(void) {
		return m_pCrypto;
	}
	///���ý��ܽӿ���ʹ�õĿ���
	void SetPassword(char *szPassword) {
		strcpy(m_szPassword, szPassword);
	}
	///��ȡ���ܽӿ���ʹ�õĿ���
	char *GetPassword(void) {
		return m_szPassword;
	}

private:
	///ini�����ļ���Ϣ
	CConfig *m_pConfig;
	///�ļ���־��Ϣ
	CFileLogger *m_pLogger;
	///���ܽӿ�
	IEncryptAlgorithm *m_pCrypto;

	///���ܽӿ���ʹ�õĿ���
	char m_szPassword[256];
	///Ӧ�ó������ƣ���argv[0]
	char m_szAppName[256];
};

/////////////////////////////////////////////////////////////////////////
///CRequestInfo����������OraclePass�������������Ϣ��
///@author	���ٻ�
///@version	1.0,20070702
/////////////////////////////////////////////////////////////////////////
class CRequestInfo {
public:
	CRequestInfo() {
		szServerIP[0] = 0;
		nPort = 0;
		szEnv[0] = 0;
		szDBName[0] = 0;
		szDBUser[0] = 0;
		nSecret = 0;
	};
public:
	///��������ַ
	char szServerIP[512];
	///�������˿�
	int nPort;
	///����
	char szEnv[128];
	///���ݿ�����
	char szDBName[128];
	///���ݿ��û���
	char szDBUser[128];
	int nSecret;
};
#endif
