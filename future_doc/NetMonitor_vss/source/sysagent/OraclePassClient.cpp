/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	OraclePassClient.cpp
///@brief	向OraclePass服务器发送请求，获取进行真正的数据库连接所需要的参数
///@history
///20080825	武玉波		创建该文件
///20100329 周建军		修改，设置多个BNS地址
/////////////////////////////////////////////////////////////////////////
#include "OraclePassClient.h"
#include "CCrypto.h"	// for CTripleDesEncryptAlgorithm
#ifdef WIN32
#define CLOSESOCKET(id) closesocket((id));
#else
#define CLOSESOCKET(id) close((id));
#endif
COraclePassClient::COraclePassClient(void) :
	m_key("shfe^oracle^password")
{
}

void COraclePassClient::DecryptPwd(char *pInput, char *pOutput) const
{
	IEncryptAlgorithm *pCrypto = NULL;

	///解码查询获取的密码
	pCrypto = new CTripleDesEncryptAlgorithm(m_key.c_str());
	pCrypto->Decrypt(pInput, pOutput);
	delete pCrypto;
}

/**获取数据库连接信息
* @param  req	输入参数  提供访问OraclePass服务器的必要信息
*		req.szServerIP  BNS(OraclePass)服务器地址
*		req.iPort		BNS服务器端口
*		req.szEnv		环境：Product, 生产; Testing, 测试; Develop, 开发。
*		req.szDBName	数据库名,NGES中指BDB或SDB,比如BDB/SDB/HDB/RDB等。
*		req.szDBUser	指定数据库用户

* @param  CDBConnectString 输出参数 记录一个数据库帐号的ip port databaseName username userpassword
*
* @return 	0 成功 非零表示失败，取值如下
*   ERR_InvalidRequest=1  配置文件设置不正确或输入参数未正确填写
*   ERR_ConnectError=2    连接密码服务器错误
*   ERR_AccessDenied=10   客户端无访问数据库的权限
*   ERR_UserNotFound=11   对应的用户不存在
*   ERR_NoResource=21     资源不足
*   ERR_InvalidCmd=22     错误的访问指令
*   ERR_ParseError=23     解析错误
*   ERR_Unknown=99        其它错误	
**/
int COraclePassClient::GetOracleAccountInfo(
	const CRequestInfo	&req,
	CDBConnectInfo	&dbInfo)
{
	enum
	{
		ERR_InvalidRequest	= 1,
		ERR_ConnectError	= 2,
		ERR_AccessDenied	= 10,
		ERR_UserNotFound	= 11,
		ERR_NoResource		= 21,
		ERR_InvalidCmd		= 22,
		ERR_ParseError		= 23,
		ERR_Unknown			= 99
	};
	char szSend[128];
	char szRecv[1024];

	if (req.szEnv.empty())
	{
		return ERR_InvalidRequest;
	}

	///格式化查询信息，遵从下面的格式
	sprintf(
		szSend,
		"[ get %s %s %s ]",
		req.szEnv.c_str(),
		req.szDBName.c_str(),
		req.szDBUser.c_str());

	int nRet = 0;

	for (int i = 0; i < m_lbns.size(); i++)
	{
		/// 设置一个哨兵，用于后面判断是否收到信息
		szRecv[0] = 0;

		int id = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (id < 0)
		{
			printf(
				"COraclePassClient::GetOracleAccountInfo: Can create socket\n");
			fflush(stdout);
			return ERR_ConnectError;
		}

		//2008.10.28 change by wu.yb, Linux 下访问了不存在的机器超时时间长，使用不路由的方式，则能很快的返回
		//如果不路由，则需要路由的时候就工作不正确了；
		//int on=1;
		//setsockopt(id, SOL_SOCKET, SO_DONTROUTE, (char *)&on, sizeof(on));
		CBNSInfo bsnNode = *m_lbns.begin();

		struct sockaddr_in	dest;
		memset(&dest, 0, sizeof(struct sockaddr_in));
		dest.sin_family = AF_INET;
		dest.sin_port = htons(bsnNode.m_nPort);
		dest.sin_addr.s_addr = inet_addr(bsnNode.m_sServerIP.c_str());

		/* try to connect it */
		int ret = ::connect(id, (struct sockaddr *) &dest, sizeof(dest));

		/* has connected, then return it */
		if (ret != 0)
		{
			printf(
				"COraclePassClient::GetOracleAccountInfo Can not connect to server\n");
			fflush(stdout);
			CLOSESOCKET(id);
			m_lbns.pop_front();
			m_lbns.push_back(bsnNode);
			continue;
		}

		int nSend = ::send(id, szSend, strlen(szSend), 0);
		if (nSend <= 0)
		{
			printf(
				"COraclePassClient::GetOracleAccountInfo Can not send to server [%s:%d]\n",
				bsnNode.m_sServerIP.c_str(),
				bsnNode.m_nPort);
			fflush(stdout);
			CLOSESOCKET(id);
			m_lbns.pop_front();
			m_lbns.push_back(bsnNode);
			continue;
		}

		int nCount = ::recv(id, szRecv, sizeof(szRecv), 0);
		if (nCount <= 0)
		{
			printf(
				"Can not recv from server [%s:%d]\n",
				bsnNode.m_sServerIP.c_str(),
				bsnNode.m_nPort);
			CLOSESOCKET(id);
			m_lbns.pop_front();
			m_lbns.push_back(bsnNode);
			continue;
		}
		else
		{
			CLOSESOCKET(id);
		}

		szRecv[nCount] = 0;

		// 如果已经收到信息，就不再进行后续IP的分析
		// 否则对后续的IP继续进行处理
		if (0 != szRecv[0])
		{
			break;
		}
	}

	if (szRecv[0] == 0)
	{
		printf(
			"[ 1 NetworkFailure, 所有的BNS服务器均不能获得正确的配置信息 ]\n");
		fflush(stdout);
		nRet = ERR_ConnectError;
		return nRet;
	}

	//---------------接收OraclePass服务器返回的数据库配置信息------------------------------//
	int nPort;
	char szEnv[128];
	char szDBName[128];
	char szUserName[128];
	char szService[128];
	char szAddress[512];

	char szEncryptPassword[128];
	char szPassword[128];

	sscanf(
		szRecv,
		"%s %d %s %s %s %s %s %d %s",
		szSend,
		&nRet,
		szEnv,
		szDBName,
		szUserName,
		szEncryptPassword,
		szService,
		&nPort,
		szAddress);

	if (nRet != 0)
	{
		printf("Error: %s\n", szRecv);
		fflush(stdout);
		return nRet;
	}

	//---------------对接收到的数据进行修正------------------------------//
	//在返回的数据中会有ip地址跟着主机名称的情况， 进行调整，这里只需要ip地址
	//该部分代码来源于wang.xp的COraclePassClient
	char *pAddressBegin;
	char *p = NULL;

	// 2008.10.29 返回的串会是xxxxx ip ip ip @name name name这样的形式
	pAddressBegin = strstr(szRecv, szAddress);
	p = strstr(pAddressBegin, "@");
	if (p != NULL)
	{
		*p = 0;
	}

	strtok(pAddressBegin, "]");

	// 对多个IP进行分解，把他们组织成IP,IP的形式
	// seperator=[ ,'|"]
	string	tempIp;
	for (p = strtok(pAddressBegin, ", \"|'[]");
		 p != NULL;
		 p = strtok(NULL, ", \"|'[]"))
	{
		if (!tempIp.empty())
		{
			tempIp += ",";
		}

		tempIp += p;
	}

	//---------------对接收到的Password密文进行解密操作------------------------------//
	memset(szPassword, 0, sizeof(szPassword));
	DecryptPwd(szEncryptPassword, szPassword);

	// Added by Henchi, 20101213
	//---------------对接收到的ServiceName进行分析------------------------------//
	// 若ServiceName为TBDB/TBDB1形式,则TBDB为RacName,TBDB1为InstanceName
	if ((p = strchr(szService, '/')) > 0)
	{
		*p = 0x00;
		dbInfo.m_sRacName = szService;
		dbInfo.m_sInstanceName = p + 1;
	}
	else
	{
		//dbInfo.m_sRacName = szService;						// RacName 是否需要统一变化? 暂时仍保留原配置项
		dbInfo.m_sInstanceName = szService;
	}

	// Added end
	dbInfo.m_sServerIP = tempIp;
	dbInfo.m_nServerPort = nPort;
	dbInfo.m_sUserName = szUserName;
	dbInfo.m_sPassword = szPassword;

	return 0;
}
