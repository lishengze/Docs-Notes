/////////////////////////////////////////////////////////////////////////
///@system OraclePass
///@company 上海期货信息技术有限公司
///@file DBUser.h
///@brief定义了CDBUser类，用于读取OraclePass程序所需的控制文件和返回处理结果
///@history 
///20070702 严少辉		创建该文件
///20071011 wangxiping 将serviceName由16增至128字节,用于支持Authentication的服务名
///20071121 wangxiping 增加数据库服务器机器名
/////////////////////////////////////////////////////////////////////////

#ifndef CDBUSER_H
#define CDBUSER_H

#include "platform.h"
#include "CLogger.h"
#include "CCrypto.h"
#include "OraclePass.h"

const int IP_USER_MAX=1024;		// AccessControl.txt所允许的最大控制项数量
const int DB_USER_MAX=256;		// OracleUserList.des所允许的最大用户数量
const int DB_INTERFACE_MAX=128;	// OracleInterface.txt所允许的最大接口数量

/////////////////////////////////////////////////////////////////////////
///CIPRange是定义所允许访问OraclePass的客户端的IP地址范围。
///从AccessControl.txt中获取，文件格式为：
/// start0-end0.start1-end1.start2-end2.start3-end3 nFlag //comment 或者
/// ip0.ip1.*.* nFlag //comment
///上述格式可以混用。
///nFlag为：0, 允许访问；1，禁止访问。
///@author	严少辉
///@version	1.0,20070722
/////////////////////////////////////////////////////////////////////////
class CIPRange {
public:
	//ip地址允许的起始值
	int nStart[4];
	//ip地址允许的结束值
	int nEnd[4];
	//是否允许访问：0, Allow; 1, Deny;
	int nFlag;			
};

/////////////////////////////////////////////////////////////////////////
///CClientErrorRsp定义了返回给客户端的错误代码和原因。
/////////////////////////////////////////////////////////////////////////
class CClientErrorRsp {
public:
	//错误代码，非零数值。1-9，客户端定义；10-19，DBUser类定义；20-29，网络端定义。
	int nReason;
	//错误原因
	char *szReason;
};

/////////////////////////////////////////////////////////////////////////
///CDBInterface定义了一个Oracle接口，从OracleInterface.txt文件获得，包括以下内容：
/// 环境(15字节) 数据库名称(15字节) 数据库ServiceName(15字节) TNS监听端口 RAC地址表
///@author	严少辉
///@version	1.0,20070722
/////////////////////////////////////////////////////////////////////////
class CDBInterface {
public:
	//环境：Product, 生产; Testing, 测试; Develop, 开发。
	char szEnvironment[16];
	//安装数据库名称，比如BDB/SDB/HDB/RDB等。
	char szDatabaseName[16];
	//数据库ServiceName。
	//20071011 wangxiping 将serviceName由16增至128字节,用于支持Authentication的服务名
	char szServiceName[128];
	//数据库TNS监听端口。
	int nPort;
	//数据库RAC的地址列表个数。
	int nCount;
	//数据库RAC的IP地址。
	char szAddress[16][16];
	//数据库RAC的机器名
	char szHost[16][128];
};


/////////////////////////////////////////////////////////////////////////
///CDBUserItem定义了一个Oracle用户名及其口令等信息。
///@author	严少辉
///@version	1.0,20070722
/////////////////////////////////////////////////////////////////////////
class CDBUserItem {
public:
	//环境：Product, 生产; Testing, 测试; Develop, 开发。
	char szEnvironment[16];
	//安装数据库名称，比如BDB/SDB/HDB/RDB等。
	char szDatabaseName[16];
	//数据库用户名。
	char szUserName[32];
	//数据库用户密码。
	char szPassword[256];
	//数据库用户密码(加密，Base64编码格式)。
	char szEncryptPassword[256];
	//对应的CDBInterface对象
	CDBInterface *pInterface;
};

/////////////////////////////////////////////////////////////////////////
///CDBUser定义了Oracle数据库、接口和用户信息。
///提供了接口从配置文件中读取数据库信息和访问控制信息。
///提供了接口返回所请求的数据库和用户信息。
///提供了接口对Oracle用户文件的口令进行加密或者解密处理。
///@author	严少辉
///@version	1.0,20070722
/////////////////////////////////////////////////////////////////////////
class CDBUser {
public:
	///构造函数，用于创建数据库接口对象
	///@param	pContext	OraclePass应用的上下文，此参数不可以为NULL
	CDBUser(CAppContext *pContext);

	///析构函数
	~CDBUser(void);

public:
	///根据配置文件读取AccessControl.txt/OracleInterface.txt/OracleUserList.des
	///三个文件中的信息。相应内容纪录进OralcePass.log日志文件中。
	///@return	0	成功
	///@return	1	读取AccessControl.txt文件失败
	///@return	2	读取OracleInterface.txt文件失败
	///@return	3	读取OracleUserList.des文件失败
	int LoadFile(void);

	///根据OracleUserList.txt文件生成OracleUserList.des文件，
	///口令使用TripleDes算法加密后以Base64方式编码存放。
	///@return	0	成功
	///@return	1	读取OracleUserList.txt文件失败
	///@return	2	写入OracleUserList.des文件失败
	int EncryptFile(void);

	///根据OracleUserList.des文件生成OracleUserList.txt文件，
	///口令使用TripleDes算法加密后以Base64方式编码存放。
	///@return	0	成功
	///@return	1	读取OracleUserList.des文件失败
	///@return	2	写入OracleUserList.txt文件失败
	int DecryptFile(void);

	///根据环境、数据库名称、用户名和IP地址获取Oracle访问路径和口令
	///访问路径和口令(加密)存放在szRsp中。成功的格式如下：
	/// [ 0 Env DBName User Password ServiceName Port IPAddresses ]
	///失败的格式如下：
	/// [ NonZero Reason ]
	///@return	0	成功
	///@return	10	UserNotFound
	///@return	11	AccessDenied
	int GetRsp(const char *szEnv, const char *szDBName, const char *szUserName, char *szRsp, unsigned int ip);

	///返回失败的Oracle访问路径和口令。
	///@param nReason	失败代码
	///@param szRsp		存放失败原因
	///@return 失败原因
	int GetRsp(int nReason, char *szRsp);

public:
	///公用函数，将字符串转换为大写。
	static void UpperCase(char *szDest);
	///公用函数，将字符串转换为小写。
	static void LowerCase(char *szDest);
	///公用函数，转换文件名中的'/'。
	/// 对于Windows，将'/'转为'\';
	/// 对于Unix，将'\'转为'/'。
	static void TransferDir(char *szDest, const char *szSrc);

private:
	///Oracle用户名数组
    CDBUserItem m_dbUser[DB_USER_MAX];
	///Oracle用户名数组使用数量
	int m_nUserCount;
	///Oracle接口数组
	CDBInterface m_dbInterface[DB_INTERFACE_MAX];
	///Oracle接口数组使用数量
	int m_nInterfaceCount;

	///访问控制允许列表
	CIPRange m_ipAllow[IP_USER_MAX];
	///允许列表大小
	int m_nIPAllow;
	///访问控制禁止列表
	CIPRange m_ipDeny[IP_USER_MAX];
	///禁止列表大小
	int m_nIPDeny;

	///OracleUserFile.des路径
	char m_szOracleUserFileDes[2048];
	///OracleUserFile.txt路径
	char m_szOracleUserFileTxt[2048];
	///OracleInterface.txt路径
	char m_szOracleInterfaceFile[2048];
	///AccessControl.txt路径
	char m_szAccessControlFile[2048];

	///OraclePass应用程序上下文，用于存放全局变量
	CAppContext *m_pContext;
};

class CClientRsp {
public:
	int nReason;
	char *szReason;
};
#endif