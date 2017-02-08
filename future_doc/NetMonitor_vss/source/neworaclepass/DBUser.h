/////////////////////////////////////////////////////////////////////////
///@system OraclePass
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file DBUser.h
///@brief������CDBUser�࣬���ڶ�ȡOraclePass��������Ŀ����ļ��ͷ��ش�����
///@history 
///20070702 ���ٻ�		�������ļ�
///20071011 wangxiping ��serviceName��16����128�ֽ�,����֧��Authentication�ķ�����
///20071121 wangxiping �������ݿ������������
/////////////////////////////////////////////////////////////////////////

#ifndef CDBUSER_H
#define CDBUSER_H

#include "platform.h"
#include "CLogger.h"
#include "CCrypto.h"
#include "OraclePass.h"

const int IP_USER_MAX=1024;		// AccessControl.txt�������������������
const int DB_USER_MAX=256;		// OracleUserList.des�����������û�����
const int DB_INTERFACE_MAX=128;	// OracleInterface.txt����������ӿ�����

/////////////////////////////////////////////////////////////////////////
///CIPRange�Ƕ������������OraclePass�Ŀͻ��˵�IP��ַ��Χ��
///��AccessControl.txt�л�ȡ���ļ���ʽΪ��
/// start0-end0.start1-end1.start2-end2.start3-end3 nFlag //comment ����
/// ip0.ip1.*.* nFlag //comment
///������ʽ���Ի��á�
///nFlagΪ��0, ������ʣ�1����ֹ���ʡ�
///@author	���ٻ�
///@version	1.0,20070722
/////////////////////////////////////////////////////////////////////////
class CIPRange {
public:
	//ip��ַ�������ʼֵ
	int nStart[4];
	//ip��ַ����Ľ���ֵ
	int nEnd[4];
	//�Ƿ�������ʣ�0, Allow; 1, Deny;
	int nFlag;			
};

/////////////////////////////////////////////////////////////////////////
///CClientErrorRsp�����˷��ظ��ͻ��˵Ĵ�������ԭ��
/////////////////////////////////////////////////////////////////////////
class CClientErrorRsp {
public:
	//������룬������ֵ��1-9���ͻ��˶��壻10-19��DBUser�ඨ�壻20-29������˶��塣
	int nReason;
	//����ԭ��
	char *szReason;
};

/////////////////////////////////////////////////////////////////////////
///CDBInterface������һ��Oracle�ӿڣ���OracleInterface.txt�ļ���ã������������ݣ�
/// ����(15�ֽ�) ���ݿ�����(15�ֽ�) ���ݿ�ServiceName(15�ֽ�) TNS�����˿� RAC��ַ��
///@author	���ٻ�
///@version	1.0,20070722
/////////////////////////////////////////////////////////////////////////
class CDBInterface {
public:
	//������Product, ����; Testing, ����; Develop, ������
	char szEnvironment[16];
	//��װ���ݿ����ƣ�����BDB/SDB/HDB/RDB�ȡ�
	char szDatabaseName[16];
	//���ݿ�ServiceName��
	//20071011 wangxiping ��serviceName��16����128�ֽ�,����֧��Authentication�ķ�����
	char szServiceName[128];
	//���ݿ�TNS�����˿ڡ�
	int nPort;
	//���ݿ�RAC�ĵ�ַ�б������
	int nCount;
	//���ݿ�RAC��IP��ַ��
	char szAddress[16][16];
	//���ݿ�RAC�Ļ�����
	char szHost[16][128];
};


/////////////////////////////////////////////////////////////////////////
///CDBUserItem������һ��Oracle�û�������������Ϣ��
///@author	���ٻ�
///@version	1.0,20070722
/////////////////////////////////////////////////////////////////////////
class CDBUserItem {
public:
	//������Product, ����; Testing, ����; Develop, ������
	char szEnvironment[16];
	//��װ���ݿ����ƣ�����BDB/SDB/HDB/RDB�ȡ�
	char szDatabaseName[16];
	//���ݿ��û�����
	char szUserName[32];
	//���ݿ��û����롣
	char szPassword[256];
	//���ݿ��û�����(���ܣ�Base64�����ʽ)��
	char szEncryptPassword[256];
	//��Ӧ��CDBInterface����
	CDBInterface *pInterface;
};

/////////////////////////////////////////////////////////////////////////
///CDBUser������Oracle���ݿ⡢�ӿں��û���Ϣ��
///�ṩ�˽ӿڴ������ļ��ж�ȡ���ݿ���Ϣ�ͷ��ʿ�����Ϣ��
///�ṩ�˽ӿڷ�������������ݿ���û���Ϣ��
///�ṩ�˽ӿڶ�Oracle�û��ļ��Ŀ�����м��ܻ��߽��ܴ���
///@author	���ٻ�
///@version	1.0,20070722
/////////////////////////////////////////////////////////////////////////
class CDBUser {
public:
	///���캯�������ڴ������ݿ�ӿڶ���
	///@param	pContext	OraclePassӦ�õ������ģ��˲���������ΪNULL
	CDBUser(CAppContext *pContext);

	///��������
	~CDBUser(void);

public:
	///���������ļ���ȡAccessControl.txt/OracleInterface.txt/OracleUserList.des
	///�����ļ��е���Ϣ����Ӧ���ݼ�¼��OralcePass.log��־�ļ��С�
	///@return	0	�ɹ�
	///@return	1	��ȡAccessControl.txt�ļ�ʧ��
	///@return	2	��ȡOracleInterface.txt�ļ�ʧ��
	///@return	3	��ȡOracleUserList.des�ļ�ʧ��
	int LoadFile(void);

	///����OracleUserList.txt�ļ�����OracleUserList.des�ļ���
	///����ʹ��TripleDes�㷨���ܺ���Base64��ʽ�����š�
	///@return	0	�ɹ�
	///@return	1	��ȡOracleUserList.txt�ļ�ʧ��
	///@return	2	д��OracleUserList.des�ļ�ʧ��
	int EncryptFile(void);

	///����OracleUserList.des�ļ�����OracleUserList.txt�ļ���
	///����ʹ��TripleDes�㷨���ܺ���Base64��ʽ�����š�
	///@return	0	�ɹ�
	///@return	1	��ȡOracleUserList.des�ļ�ʧ��
	///@return	2	д��OracleUserList.txt�ļ�ʧ��
	int DecryptFile(void);

	///���ݻ��������ݿ����ơ��û�����IP��ַ��ȡOracle����·���Ϳ���
	///����·���Ϳ���(����)�����szRsp�С��ɹ��ĸ�ʽ���£�
	/// [ 0 Env DBName User Password ServiceName Port IPAddresses ]
	///ʧ�ܵĸ�ʽ���£�
	/// [ NonZero Reason ]
	///@return	0	�ɹ�
	///@return	10	UserNotFound
	///@return	11	AccessDenied
	int GetRsp(const char *szEnv, const char *szDBName, const char *szUserName, char *szRsp, unsigned int ip);

	///����ʧ�ܵ�Oracle����·���Ϳ��
	///@param nReason	ʧ�ܴ���
	///@param szRsp		���ʧ��ԭ��
	///@return ʧ��ԭ��
	int GetRsp(int nReason, char *szRsp);

public:
	///���ú��������ַ���ת��Ϊ��д��
	static void UpperCase(char *szDest);
	///���ú��������ַ���ת��ΪСд��
	static void LowerCase(char *szDest);
	///���ú�����ת���ļ����е�'/'��
	/// ����Windows����'/'תΪ'\';
	/// ����Unix����'\'תΪ'/'��
	static void TransferDir(char *szDest, const char *szSrc);

private:
	///Oracle�û�������
    CDBUserItem m_dbUser[DB_USER_MAX];
	///Oracle�û�������ʹ������
	int m_nUserCount;
	///Oracle�ӿ�����
	CDBInterface m_dbInterface[DB_INTERFACE_MAX];
	///Oracle�ӿ�����ʹ������
	int m_nInterfaceCount;

	///���ʿ��������б�
	CIPRange m_ipAllow[IP_USER_MAX];
	///�����б��С
	int m_nIPAllow;
	///���ʿ��ƽ�ֹ�б�
	CIPRange m_ipDeny[IP_USER_MAX];
	///��ֹ�б��С
	int m_nIPDeny;

	///OracleUserFile.des·��
	char m_szOracleUserFileDes[2048];
	///OracleUserFile.txt·��
	char m_szOracleUserFileTxt[2048];
	///OracleInterface.txt·��
	char m_szOracleInterfaceFile[2048];
	///AccessControl.txt·��
	char m_szAccessControlFile[2048];

	///OraclePassӦ�ó��������ģ����ڴ��ȫ�ֱ���
	CAppContext *m_pContext;
};

class CClientRsp {
public:
	int nReason;
	char *szReason;
};
#endif