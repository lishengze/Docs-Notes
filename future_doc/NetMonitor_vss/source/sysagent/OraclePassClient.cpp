/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	OraclePassClient.cpp
///@brief	��OraclePass�������������󣬻�ȡ�������������ݿ���������Ҫ�Ĳ���
///@history
///20080825	����		�������ļ�
///20100329 �ܽ���		�޸ģ����ö��BNS��ַ
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

	///�����ѯ��ȡ������
	pCrypto = new CTripleDesEncryptAlgorithm(m_key.c_str());
	pCrypto->Decrypt(pInput, pOutput);
	delete pCrypto;
}

/**��ȡ���ݿ�������Ϣ
* @param  req	�������  �ṩ����OraclePass�������ı�Ҫ��Ϣ
*		req.szServerIP  BNS(OraclePass)��������ַ
*		req.iPort		BNS�������˿�
*		req.szEnv		������Product, ����; Testing, ����; Develop, ������
*		req.szDBName	���ݿ���,NGES��ָBDB��SDB,����BDB/SDB/HDB/RDB�ȡ�
*		req.szDBUser	ָ�����ݿ��û�

* @param  CDBConnectString ������� ��¼һ�����ݿ��ʺŵ�ip port databaseName username userpassword
*
* @return 	0 �ɹ� �����ʾʧ�ܣ�ȡֵ����
*   ERR_InvalidRequest=1  �����ļ����ò���ȷ���������δ��ȷ��д
*   ERR_ConnectError=2    �����������������
*   ERR_AccessDenied=10   �ͻ����޷������ݿ��Ȩ��
*   ERR_UserNotFound=11   ��Ӧ���û�������
*   ERR_NoResource=21     ��Դ����
*   ERR_InvalidCmd=22     ����ķ���ָ��
*   ERR_ParseError=23     ��������
*   ERR_Unknown=99        ��������	
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

	///��ʽ����ѯ��Ϣ���������ĸ�ʽ
	sprintf(
		szSend,
		"[ get %s %s %s ]",
		req.szEnv.c_str(),
		req.szDBName.c_str(),
		req.szDBUser.c_str());

	int nRet = 0;

	for (int i = 0; i < m_lbns.size(); i++)
	{
		/// ����һ���ڱ������ں����ж��Ƿ��յ���Ϣ
		szRecv[0] = 0;

		int id = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (id < 0)
		{
			printf(
				"COraclePassClient::GetOracleAccountInfo: Can create socket\n");
			fflush(stdout);
			return ERR_ConnectError;
		}

		//2008.10.28 change by wu.yb, Linux �·����˲����ڵĻ�����ʱʱ�䳤��ʹ�ò�·�ɵķ�ʽ�����ܺܿ�ķ���
		//�����·�ɣ�����Ҫ·�ɵ�ʱ��͹�������ȷ�ˣ�
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

		// ����Ѿ��յ���Ϣ���Ͳ��ٽ��к���IP�ķ���
		// ����Ժ�����IP�������д���
		if (0 != szRecv[0])
		{
			break;
		}
	}

	if (szRecv[0] == 0)
	{
		printf(
			"[ 1 NetworkFailure, ���е�BNS�����������ܻ����ȷ��������Ϣ ]\n");
		fflush(stdout);
		nRet = ERR_ConnectError;
		return nRet;
	}

	//---------------����OraclePass���������ص����ݿ�������Ϣ------------------------------//
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

	//---------------�Խ��յ������ݽ�������------------------------------//
	//�ڷ��ص������л���ip��ַ�����������Ƶ������ ���е���������ֻ��Ҫip��ַ
	//�ò��ִ�����Դ��wang.xp��COraclePassClient
	char *pAddressBegin;
	char *p = NULL;

	// 2008.10.29 ���صĴ�����xxxxx ip ip ip @name name name��������ʽ
	pAddressBegin = strstr(szRecv, szAddress);
	p = strstr(pAddressBegin, "@");
	if (p != NULL)
	{
		*p = 0;
	}

	strtok(pAddressBegin, "]");

	// �Զ��IP���зֽ⣬��������֯��IP,IP����ʽ
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

	//---------------�Խ��յ���Password���Ľ��н��ܲ���------------------------------//
	memset(szPassword, 0, sizeof(szPassword));
	DecryptPwd(szEncryptPassword, szPassword);

	// Added by Henchi, 20101213
	//---------------�Խ��յ���ServiceName���з���------------------------------//
	// ��ServiceNameΪTBDB/TBDB1��ʽ,��TBDBΪRacName,TBDB1ΪInstanceName
	if ((p = strchr(szService, '/')) > 0)
	{
		*p = 0x00;
		dbInfo.m_sRacName = szService;
		dbInfo.m_sInstanceName = p + 1;
	}
	else
	{
		//dbInfo.m_sRacName = szService;						// RacName �Ƿ���Ҫͳһ�仯? ��ʱ�Ա���ԭ������
		dbInfo.m_sInstanceName = szService;
	}

	// Added end
	dbInfo.m_sServerIP = tempIp;
	dbInfo.m_nServerPort = nPort;
	dbInfo.m_sUserName = szUserName;
	dbInfo.m_sPassword = szPassword;

	return 0;
}
