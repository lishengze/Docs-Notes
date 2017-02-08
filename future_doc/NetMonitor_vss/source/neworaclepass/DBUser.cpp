/////////////////////////////////////////////////////////////////////////
///@system OraclePass
///@company 上海期货信息技术有限公司
///@file DBUser.c
///@brief实现了CDBUser类，用于读取OraclePass程序所需的控制文件和返回处理结果
///@history 
///20070702 严少辉		创建该文件
/////////////////////////////////////////////////////////////////////////
#include "DBUser.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

CClientErrorRsp rsp[] = {
	{99, "Unknown"},
	{10, "AccessDenied"},
	{11, "UserNotFound"},
	{21, "NoResource"},
	{22, "InvalidCmd"},
	{23, "ParseError"}
};

CDBUser::CDBUser(CAppContext *pContext)
{
	m_nInterfaceCount = 0;
	m_nUserCount = 0;
	m_nIPAllow = 0;
	m_nIPDeny = 0;
	m_pContext = pContext;
}

CDBUser::~CDBUser(void)
{
}

void CDBUser::TransferDir(char *szDest, const char *szSrc)
{
	strcpy(szDest, szSrc);
#ifdef WINDOWS
	char *p;
	p = strchr(szDest, '/');
	while (p!=NULL) {
		*p = '\\';
		p = strchr(szDest, '/');
	}
#else
	char *p;
	p = strchr(szDest, '\\');
	while (p!=NULL) {
		*p = '/';
		p = strchr(szDest, '\\');
	}
#endif
}

void CDBUser::UpperCase(char *szDest)
{
	char *p=szDest;
	while (*p) {
		*p = toupper(*p);
		p++;
	}
}

void CDBUser::LowerCase(char *szDest)
{
	char *p=szDest;
	while (*p) {
		*p = tolower(*p);
		p++;
	}
}

int CDBUser::LoadFile(void)
{
	m_nInterfaceCount = 0;
	m_nUserCount = 0;
	m_nIPAllow = 0;
	m_nIPDeny = 0;

	m_pContext->GetLogger()->output("Loading access control file...\n");
	FILE *fpAccess = NULL;
	TransferDir(m_szAccessControlFile, 
		m_pContext->GetConfig()->getConfig("AccessControlFile"));
	fpAccess = fopen(m_szAccessControlFile, "r");
	if (fpAccess==NULL)
		return 1;
	char szBuffer[1024], szIP0[52], szIP1[52];
	char *pIP[4];
	int nRet, nFlag, i, j;
	CIPRange *pRange;
	for (i=0; i<IP_USER_MAX; i++) {
		m_ipAllow[i].nFlag = 2;
		m_ipDeny[i].nFlag = 2;
	}
	while (m_nIPAllow+m_nIPDeny < IP_USER_MAX) {
		memset(szBuffer, 0, sizeof(szBuffer));
		if (fgets(szBuffer, sizeof(szBuffer), fpAccess)==NULL) {
			break;
		}
		nRet = sscanf(szBuffer, "%s %d", szIP0, &nFlag);
		if (szIP0[0]=='#') {
			continue;
		}
		if (nRet<2) {
			continue;
		}

		if (nFlag==0) {
			pRange = m_ipAllow + m_nIPAllow;
		}
		else if (nFlag==1) {
			pRange = m_ipDeny + m_nIPDeny;
		}
		else {
			// 0, allow; 1, deny;
			continue;
		}
		strcpy(szIP1, szIP0);
		for (i=0; i<4; i++) {
			if (i==0) {
				pIP[i] = strtok(szIP1, ".");
			}
			else {
				pIP[i] = strtok(NULL, ".");
			}
			if (pIP[i]==NULL) {
				break;
			}
		}
		if (i<4) {
			//地址不完整
			continue;
		}
		for (i=0; i<4; i++) {
			if (pIP[i][0]=='*') {
				pRange->nStart[i] = 0;
				pRange->nEnd[i] = 255;
				continue;
			}
			char *p=strtok(pIP[i], "-");
			pRange->nStart[i] = atoi(p);
			char *q=strtok(NULL, "-");
			if (q==NULL) {
				pRange->nEnd[i] = pRange->nStart[i];
			}
			else {
				pRange->nEnd[i] = atoi(q);
			}
			if (pRange->nStart[i]<=0 ||
				pRange->nEnd[i]>255) {
				continue;
			}
			if (pRange->nStart[i]>pRange->nEnd[i]) {
				continue;
			}
		}
		if (nFlag==0) {
			m_nIPAllow ++;
		}
		else {
			m_nIPDeny ++;
		}
	}
	m_pContext->GetLogger()->output(0,
		"    %d allow item(s), %d deny item(s).\n", 
		m_nIPAllow, m_nIPDeny);
	fclose(fpAccess);

	m_pContext->GetLogger()->output("Loading Oracle users and interfaces files...\n");
	FILE *fpInterface = NULL;
	TransferDir(m_szOracleInterfaceFile,
		m_pContext->GetConfig()->getConfig("OracleInterfaceFile"));
	fpInterface = fopen(m_szOracleInterfaceFile, "r");
	if (fpInterface==NULL)
		return 2;
	memset((void *)m_dbInterface, 0, sizeof(CDBInterface)*DB_INTERFACE_MAX);
	memset((void *)m_dbUser, 0, sizeof(CDBUserItem)*DB_USER_MAX);

	char szEnv[128], szDBName[128],
		 szService[128], szAddress[512], *pAddress;
	char *pHost;
	int nPort;
	while (m_nInterfaceCount<DB_INTERFACE_MAX) {
		memset(szBuffer, 0, sizeof(szBuffer));
		if (fgets(szBuffer, sizeof(szBuffer), fpInterface)==NULL) {
			break;
		}
		nRet = sscanf(szBuffer, "%s%s%s%d%s",
			          szEnv, szDBName, szService,
					  &nPort, szAddress);
		if (szEnv[0]=='#') {
			continue;
		}
		if (nRet<5) {
			continue;
		}
		szEnv[15] = 0, UpperCase(szEnv);
		szDBName[15] = 0, UpperCase(szDBName);
		szService[127] = 0;
		pAddress = strstr(szBuffer, szAddress);
		pHost = strstr(pAddress,"@");
		if (pHost!=NULL)
		{
			*pHost=0;
			pHost++;
		}
				
		for (i=0; i<m_nInterfaceCount; i++) {
			if (strcmp(m_dbInterface[i].szEnvironment, szEnv)==0 &&
				strcmp(m_dbInterface[i].szDatabaseName, szDBName)==0) {
				break;
			}
		}
		if (i==m_nInterfaceCount) {
			m_nInterfaceCount++;
		}
		strcpy(m_dbInterface[i].szEnvironment, szEnv);
		strcpy(m_dbInterface[i].szDatabaseName, szDBName);
		strcpy(m_dbInterface[i].szServiceName, szService);
		m_dbInterface[i].nPort = nPort;
		
		m_dbInterface[i].nCount = 1;
		pAddress=strtok(pAddress, ",; :\t\r\n");

		if (pAddress!=NULL)
		{
			strncpy(m_dbInterface[i].szAddress[0], pAddress,15);
		}
		else
		{
			szAddress[15] = 0;
			strcpy(m_dbInterface[i].szAddress[0], szAddress);
		}
				
		for (j=1; j<16; j++) {
			pAddress = strtok(NULL, ",; :\t\r\n");
			if (pAddress==NULL) {
				break;
			}
			m_dbInterface[i].nCount++;
			strncpy(m_dbInterface[i].szAddress[j], pAddress,15);
		}
		
		pHost=strtok(pHost, ",; :\t\r\n");
		if (pHost!=NULL)
		{
			strncpy(m_dbInterface[i].szHost[0], pHost,127);
		}
		else
		{
			m_dbInterface[i].szHost[0][0]=0;
		}
				
		for (j=1; j<m_dbInterface[i].nCount; j++) {
			pHost = strtok(NULL, ",; :\t\r\n");
			if (pHost==NULL) {
				break;
			}
			strncpy(m_dbInterface[i].szHost[j], pHost,127);
		}

	}
	fclose(fpInterface);
	m_pContext->GetLogger()->output(0,
		"    %d Oracle interface(s).\n", m_nInterfaceCount);

	FILE *fpUser = NULL;
	TransferDir(m_szOracleUserFileDes,
		m_pContext->GetConfig()->getConfig("OracleUserFileDes"));
	fpUser = fopen(m_szOracleUserFileDes, "r");
	if (fpUser==NULL) {
		return 3;
	}
	char szUserName[48], szPassword[256];
	int nInterfaceIndex;
	while (m_nUserCount<DB_USER_MAX) {
		memset(szBuffer, 0, sizeof(szBuffer));
		if (fgets(szBuffer, sizeof(szBuffer), fpUser)==NULL) {
			break;
		}
		nRet = sscanf(szBuffer, "%s%s%s%s",
			          szEnv, szDBName,
					  szUserName, szPassword);
		if (szEnv[0]=='#') {
			continue;
		}
		if (nRet<4) {
			continue;
		}
		szEnv[15] = 0, UpperCase(szEnv);
		szDBName[15] = 0, UpperCase(szDBName);
		szUserName[31] = 0, UpperCase(szUserName);
		szPassword[40] = 0;

		// find out the relative interface
		for (i=0; i<m_nInterfaceCount; i++) {
			if (strcmp(m_dbInterface[i].szEnvironment, szEnv)==0 &&
				strcmp(m_dbInterface[i].szDatabaseName, szDBName)==0) {
				break;
			}
		}
		if (i==m_nInterfaceCount) {
			// can't find out interface, throw out.
			continue;
		}
		else {
			nInterfaceIndex = i;
		}

		for (i=0; i<m_nUserCount; i++) {
			if (strcmp(m_dbUser[i].szEnvironment, szEnv)==0 &&
				strcmp(m_dbUser[i].szDatabaseName, szDBName)==0 &&
				strcmp(m_dbUser[i].szUserName, szUserName)==0) {
				break;
			}
		}
		if (i==m_nUserCount) {
			m_nUserCount++;
		}
		strcpy(m_dbUser[i].szEnvironment, szEnv);
		strcpy(m_dbUser[i].szDatabaseName, szDBName);
		strcpy(m_dbUser[i].szUserName, szUserName);
		m_dbUser[i].szPassword[0] = 0;
		strcpy(m_dbUser[i].szEncryptPassword, szPassword);
		m_dbUser[i].pInterface = m_dbInterface+nInterfaceIndex;
	}
	fclose(fpUser);
	m_pContext->GetLogger()->output(0,
		"    %d Oracle user(s).\n", m_nUserCount);
	return 0;
}

int CDBUser::GetRsp(int nReason, char *szRsp) {
	int nSize=sizeof(rsp)/sizeof(rsp[0]);
	int i;
	for (i=1; i<nSize; i++) {
		if (rsp[i].nReason==nReason) {
			break;
		}
	}
	if (i==nSize) {
		i=0;
	}
	sprintf(szRsp, "[ %d %s ]", rsp[i].nReason, rsp[i].szReason);
	return rsp[i].nReason;
}


int CDBUser::GetRsp(const char *szEnv, const char *szDBName, 
					const char *szUserName, char *szRsp, unsigned int ip)
{
	int n=0, i, j, nFound;
	unsigned char *pInt = (unsigned char *)&ip;
	for (i=0; i<m_nIPDeny; i++) {
		nFound = 0;
		for (j=0; j<4; j++) {
			n = (unsigned int)*(pInt+j);
			if (n>=m_ipDeny[i].nStart[j] &&
				n<=m_ipDeny[i].nEnd[j]) {
				nFound ++;
			}
			else {
				break;
			}
		}
		if (nFound==4) {
			return GetRsp(10, szRsp);	//AccessDenied
		}
	}
	for (i=0; i<m_nIPAllow; i++) {
		nFound = 0;
		for (j=0; j<4; j++) {
			n = (unsigned int)*(pInt+j);
			if (n>=m_ipAllow[i].nStart[j] &&
				n<=m_ipAllow[i].nEnd[j]) {
				nFound ++;
			}
			else {
				break;
			}
		}
		if (nFound==4) {
			break;
		}
	}
	if (nFound!=4) {
		return GetRsp(10, szRsp);	//AccessDenied
	}

	CDBUserItem *p=m_dbUser;
	for (i=0; i<m_nUserCount; i++) {
		if (strcmp(p[i].szEnvironment, szEnv)==0 &&
			strcmp(p[i].szDatabaseName, szDBName)==0 &&
			strcmp(p[i].szUserName, szUserName)==0) {
			break;
		}
	}
	if (i==m_nUserCount) {
		return GetRsp(11, szRsp);	//UserNotFound

	}

	CDBInterface *m=p[i].pInterface;
	sprintf(szRsp, "[ 0 %s %s %s %s %s %d ",
		    szEnv, szDBName, szUserName, 
			p[i].szEncryptPassword, m->szServiceName, m->nPort);
	for (i=0; i<m->nCount; i++) {
		strcat(szRsp, m->szAddress[i]);
		strcat(szRsp, " ");
	}
	strcat(szRsp, "@");
	for (i=0; i<m->nCount; i++) {
		strcat(szRsp, m->szHost[i]);
		strcat(szRsp, " ");
	}
	strcat(szRsp, "]");

	return 0;
}

int CDBUser::EncryptFile(void)
{
	TransferDir(m_szOracleUserFileDes,
		m_pContext->GetConfig()->getConfig("OracleUserFileDes"));
	TransferDir(m_szOracleUserFileTxt,
		m_pContext->GetConfig()->getConfig("OracleUserFileTxt"));
	printf("  Input txt file=%s, output encrypted file=%s\n", 
		m_szOracleUserFileTxt, m_szOracleUserFileDes);

	FILE *fpUserEncrypt = NULL;
	fpUserEncrypt = fopen(m_szOracleUserFileTxt, "r");
	if (fpUserEncrypt==NULL) {
		return 1;
	}
	FILE *fpUser = NULL;
	fpUser = fopen(m_szOracleUserFileDes, "w");
	if (fpUser==NULL) {
		fclose(fpUserEncrypt);
		return 2;
	}

	char szBuffer[1024], szEnv[128], szDBName[128];
	char szUserName[48], szPassword[256];
	int nRet, i;
	while (m_nUserCount<DB_USER_MAX) {
		memset(szBuffer, 0, sizeof(szBuffer));
		if (fgets(szBuffer, sizeof(szBuffer), fpUserEncrypt)==NULL) {
			break;
		}
		nRet = sscanf(szBuffer, "%s%s%s%s",
			          szEnv, szDBName,
					  szUserName, szPassword);
		if (szEnv[0]=='#') {
			fputs(szBuffer, fpUser);
			continue;
		}
		if (nRet<4) {
			fputs(szBuffer, fpUser);
			continue;
		}
		szEnv[15] = 0, UpperCase(szEnv);
		szDBName[15] = 0, UpperCase(szDBName);
		szUserName[31] = 0, UpperCase(szUserName);
		szPassword[40] = 0;

		for (i=0; i<m_nUserCount; i++) {
			if (strcmp(m_dbUser[i].szEnvironment, szEnv)==0 &&
				strcmp(m_dbUser[i].szDatabaseName, szDBName)==0 &&
				strcmp(m_dbUser[i].szUserName, szUserName)==0) {
				break;
			}
		}
		if (i==m_nUserCount) {
			m_nUserCount++;
		}
		strcpy(m_dbUser[i].szEnvironment, szEnv);
		strcpy(m_dbUser[i].szDatabaseName, szDBName);
		strcpy(m_dbUser[i].szUserName, szUserName);
		strcpy(m_dbUser[i].szPassword, szPassword);
		m_pContext->GetCrypto()->Encrypt(szPassword, m_dbUser[i].szEncryptPassword);
		printf("    [ %s %s %s %s]\n",
			szEnv, szDBName, szUserName, m_dbUser[i].szEncryptPassword);
		sprintf(szBuffer, " %s %s %s %s\n",
			szEnv, szDBName, szUserName, m_dbUser[i].szEncryptPassword);
		fputs(szBuffer, fpUser);
	}
	fclose(fpUserEncrypt);
	fclose(fpUser);
	printf("  %d Oracle user(s).\n", m_nUserCount);

	return 0;
}

int CDBUser::DecryptFile(void)
{
	TransferDir(m_szOracleUserFileDes,
		m_pContext->GetConfig()->getConfig("OracleUserFileDes"));
	TransferDir(m_szOracleUserFileTxt,
		m_pContext->GetConfig()->getConfig("OracleUserFileTxt"));
	printf("  Input encrypted file=%s, output decrypted file=%s\n", 
		m_szOracleUserFileDes, m_szOracleUserFileTxt);

	FILE *fpUserEncrypt = NULL;
	fpUserEncrypt = fopen(m_szOracleUserFileDes, "r");
	if (fpUserEncrypt==NULL) {
		return 1;
	}
	FILE *fpUser = NULL;
	fpUser = fopen(m_szOracleUserFileTxt, "w");
	if (fpUser==NULL) {
		fclose(fpUserEncrypt);
		return 2;
	}

	char szBuffer[1024], szEnv[128], szDBName[128];
	char szUserName[48], szPassword[256];
	int nRet, i;
	while (m_nUserCount<DB_USER_MAX) {
		memset(szBuffer, 0, sizeof(szBuffer));
		if (fgets(szBuffer, sizeof(szBuffer), fpUserEncrypt)==NULL) {
			break;
		}
		nRet = sscanf(szBuffer, "%s%s%s%s",
			          szEnv, szDBName,
					  szUserName, szPassword);
		if (szEnv[0]=='#') {
			fputs(szBuffer, fpUser);
			continue;
		}
		if (nRet<4) {
			fputs(szBuffer, fpUser);
			continue;
		}
		szEnv[15] = 0, UpperCase(szEnv);
		szDBName[15] = 0, UpperCase(szDBName);
		szUserName[31] = 0, UpperCase(szUserName);
		szPassword[40] = 0;

		for (i=0; i<m_nUserCount; i++) {
			if (strcmp(m_dbUser[i].szEnvironment, szEnv)==0 &&
				strcmp(m_dbUser[i].szDatabaseName, szDBName)==0 &&
				strcmp(m_dbUser[i].szUserName, szUserName)==0) {
				break;
			}
		}
		if (i==m_nUserCount) {
			m_nUserCount++;
		}
		strcpy(m_dbUser[i].szEnvironment, szEnv);
		strcpy(m_dbUser[i].szDatabaseName, szDBName);
		strcpy(m_dbUser[i].szUserName, szUserName);
		strcpy(m_dbUser[i].szEncryptPassword, szPassword);
		m_pContext->GetCrypto()->Decrypt(szPassword, m_dbUser[i].szPassword);
		printf("    [ %s %s %s %s]\n",
			szEnv, szDBName, szUserName, m_dbUser[i].szPassword);
		sprintf(szBuffer, " %s %s %s %s\n",
			szEnv, szDBName, szUserName, m_dbUser[i].szPassword);
		fputs(szBuffer, fpUser);
	}
	fclose(fpUserEncrypt);
	fclose(fpUser);
	printf("  %d Oracle user(s).\n", m_nUserCount);

	return 0;
}
