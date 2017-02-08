/////////////////////////////////////////////////////////////////////////
///@system OraclePass
///@company 上海期货信息技术有限公司
///@file OraclePass.h
///@brief定义了CAppContext类，用于存储应用的全局信息。
///@history 
///20070702 严少辉		创建该文件
/////////////////////////////////////////////////////////////////////////
#ifndef ORACLEPASS_H
#define ORACLEPASS_H

#include "CConfig.h"
#include "CFileLogger.h"
#include "CCrypto.h"

/////////////////////////////////////////////////////////////////////////
///CAppContext定义了OraclePass应用程序的上下文，主要用于存储如下信息：
/// TripleDes使用的口令；
/// OraclePass的ini文件信息；
/// 文件日志类；
/// TripleDes加密接口；
/// 应用程序名，即argv[0]。
///@author	严少辉
///@version	1.0,20070722
/////////////////////////////////////////////////////////////////////////
class CAppContext {
public:
	///构造函数
	CAppContext() : m_pConfig(NULL), m_pLogger(NULL) {
		m_szPassword[0] = 0;
		m_szAppName[0] = 0;
	}
	///析构函数
	virtual ~CAppContext() {
	}
public:
	///设置应用程序名称。
	void SetApp(char *szAppName) {
		strcpy(m_szAppName, szAppName);
	}
	///获取应用程序名称。
	char *GetAppName(void) {
		return m_szAppName;
	}
	///设置ini配置文件
	void SetConfig(CConfig *pConfig) {
		m_pConfig = pConfig;
	}
	///获取ini配置文件
	CConfig *GetConfig(void) {
		return m_pConfig;
	}
	///设置文件日志
	void SetLogger(CFileLogger *pLogger) {
		m_pLogger = pLogger;
	}
	///获取文件日志
	CFileLogger *GetLogger(void) {
		return m_pLogger;
	}
	///设置加密接口
	void SetCrypto(IEncryptAlgorithm *pCrypto) {
		m_pCrypto = pCrypto;
	}
	///获取加密接口
	IEncryptAlgorithm *GetCrypto(void) {
		return m_pCrypto;
	}
	///设置解密接口所使用的口令
	void SetPassword(char *szPassword) {
		strcpy(m_szPassword, szPassword);
	}
	///获取解密接口所使用的口令
	char *GetPassword(void) {
		return m_szPassword;
	}

private:
	///ini配置文件信息
	CConfig *m_pConfig;
	///文件日志信息
	CFileLogger *m_pLogger;
	///加密接口
	IEncryptAlgorithm *m_pCrypto;

	///加密接口所使用的口令
	char m_szPassword[256];
	///应用程序名称，即argv[0]
	char m_szAppName[256];
};

/////////////////////////////////////////////////////////////////////////
///CRequestInfo定义了请求OraclePass服务器所需的信息。
///@author	严少辉
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
	///服务器地址
	char szServerIP[512];
	///服务器端口
	int nPort;
	///环境
	char szEnv[128];
	///数据库名称
	char szDBName[128];
	///数据库用户名
	char szDBUser[128];
	int nSecret;
};
#endif
