/////////////////////////////////////////////////////////////////////////
///@system OraclePass
///@company 上海期货信息技术有限公司
///@file OraclePass.cpp
///@brief OraclePass的主文件，实现应用。
///@history 
///20070702 严少辉		创建该文件
///20080221 wang.xiping 增加szPassword变量置空
/////////////////////////////////////////////////////////////////////////
#include "platform.h"

#include "TcpServer.h"
#include "ServiceName.h"
#include "DBUser.h"
#include "GetOpt.h"
#include "OraclePass.h"
#include "SocketInit.h"

#include <stdio.h>

///-t option
int TestFunction(CAppContext *pContext);
///-h option
int HelpFunction(CAppContext *pContext);
///-e option
int EncryptFunction(CAppContext *pContext);
///-d option
int DecryptFunction(CAppContext *pContext);
///-c option
int ClientFunction(CAppContext *pContext, CRequestInfo &request);
///-s option
int ServerFunction(CAppContext *pContext);

int main(int argc, char ** argv)
{
	CAppContext *pContext;
	pContext = new CAppContext;
	pContext->SetApp(argv[0]);
	pContext->SetPassword("shfe^oracle^password");

	CRequestInfo request;
	char *pszParam;
	int c, nQuit, nRet=0;
	while ((c=GetOption(argc, argv, "-htsdec:p:n:b:u:Z", &pszParam))!=0) {
		nQuit = 1;
		switch (c) {
		case 't':
			nRet = TestFunction(pContext);
			break;
		case 'd':
			nRet = DecryptFunction(pContext);
			break;
		case 'e':
			nRet = EncryptFunction(pContext);
			break;
		case 's':
			nRet = ServerFunction(pContext);
			break;
		case 'c':
			//表明客户端连接，允许输入OraclePass服务器地址两个，
			//地址格式：IP1-IP2；或者IP1,IP2.
			if (pszParam==NULL) {
				HelpFunction(pContext);
			}
			else {
				strcpy(request.szServerIP, pszParam);
				nQuit = 0;
			}
			break;
		case 'p':
			//与-c选项同时使用，表明环境
			if (pszParam==NULL) {
				HelpFunction(pContext);
			}
			else {
				request.nPort = atoi(pszParam);
				nQuit = 0;
			}
			break;
		case 'n':
			//与-c选项同时使用，表明环境
			if (pszParam==NULL) {
				HelpFunction(pContext);
			}
			else {
				strcpy(request.szEnv, pszParam);
				request.szEnv[15] = 0;
				nQuit = 0;
			}
			break;
		case 'b':
			//与-c选项同时使用，表明数据库名
			if (pszParam==NULL) {
				HelpFunction(pContext);
			}
			else {
				strcpy(request.szDBName, pszParam);
				request.szDBName[15] = 0;
				nQuit = 0;
			}
			break;
		case 'u':
			//与-c选项同时使用，表明数据库用户名称
			if (pszParam==NULL) {
				HelpFunction(pContext);
			}
			else {
				strcpy(request.szDBUser, pszParam);
				request.szDBUser[127] = 0;
				nQuit = 0;
			}
			break;
		case 'Z':
			//Undocumented
			nQuit = 0;
			request.nSecret ++;
			break;
		case 'h':
			nRet = HelpFunction(pContext);
			break;
		case 1:
		case -1:
		case '?':
		default:
			HelpFunction(pContext);
			nRet = 1;
			break;
		}
		if (nQuit!=0) {
			break;
		}
	}
	if (nQuit!=0) {
		delete pContext;
		return nRet;
	}

	if (request.szServerIP[0]==0 ||
		request.szEnv[0]==0 ||
		request.szDBName[0]==0 ||
		request.szDBUser[0]==0 ||
		request.nPort==0) {
		HelpFunction(pContext);
		return 1;
	}
	nRet = ClientFunction(pContext, request);
	return nRet;
}

/// -c option implementation
int ClientFunction(CAppContext *pContext, CRequestInfo &request)
{
	char szBuffer[512], szSend[128], szRecv[512];
	strcpy(szBuffer, request.szServerIP);

	sprintf(szSend, "[ get %s %s %s ]",
		request.szEnv, request.szDBName, request.szDBUser);

	int nRet=0;
	CSocketInit socketinit;
	char *pChar = strtok(szBuffer, ",-");
	do {
		szRecv[0] = 0;
		int id=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (id<0) {
			perror("Can not create socket");
			continue;
		}

		struct sockaddr_in dest;
		dest.sin_family = AF_INET;
		dest.sin_port = htons(request.nPort);
		dest.sin_addr.s_addr=inet_addr(pChar);

		/* try to connect it */
		int ret=::connect(id,(struct sockaddr  *)&dest,sizeof(dest));

		/* has connected, then return it */
		if (ret!=0) {
			perror("Can not connect to server");
			closesocket(id);
			continue;
		}

		int nSend = ::send(id, szSend, strlen(szSend), 0);
		if (nSend<=0) {
			perror("Can not send to server");
			closesocket(id);
			continue;
		}

		int nCount = ::recv(id, szRecv , sizeof(szRecv), 0);
		if (nCount<=0) {
			perror("Can not recv from server");
			closesocket(id);
			continue;
		}
		szRecv[nCount] = 0;
		closesocket(id);
		break;
	} while ((pChar=strtok(NULL, ",-"))!=NULL);

	if (szRecv[0]==0) {
		printf("[ 1 NetworkFailure ]");
		nRet = 1;
		return nRet;
	}

	int nPort;
	char szEnv[16], szDBName[16], szUserName[16],
		 szService[16], szAddress[512];
	char szEncryptPassword[128], szPassword[128];
	sscanf(szRecv, "%s %d %s %s %s %s %s %d %s",
		szSend, &nRet, szEnv, szDBName, 
		szUserName, szEncryptPassword, 
		szService, &nPort, szAddress);
	if (request.nSecret<2 || nRet!=0) {
		printf("%s", szRecv);
		return nRet;
	}

	IEncryptAlgorithm *pCrypto = new CTripleDesEncryptAlgorithm(pContext->GetPassword());
	memset(szPassword,0,sizeof(szPassword));
	pCrypto->Decrypt(szEncryptPassword, szPassword);
	delete pCrypto;

	sprintf(szSend, "%s/%s@%s:%d/%s",
		szUserName, szPassword, 
		szAddress, nPort, szService);
	printf("%s", szSend);
	return 0;
}

/// -t option implementation
int TestFunction(CAppContext *pContext)
{
	char buffer1[512]="1234567890abcdefghijklmnopqrstuvwxyz";
	char buffer2[512], buffer3[512];
	char *szPassword = "des & triple des testing";

	IEncryptAlgorithm *pCrypto;
	printf("DES Algorithm Test...key=\'%s\'\n", szPassword);
	pCrypto = new CDesEncryptAlgorithm(szPassword);
	printf("  Text   :%s\n", buffer1);
	pCrypto->Encrypt(buffer1, buffer2);
	printf("  Encrypt:%s\n", buffer2);
	pCrypto->Decrypt(buffer2, buffer3);
	printf("  Decrypt:%s\n", buffer3);
	delete pCrypto;

	printf("Triple DES Algorithm Test...key=\'%s\'\n", szPassword);
	pCrypto = new CTripleDesEncryptAlgorithm(szPassword);
	printf("  Text   :%s\n", buffer1);
	pCrypto->Encrypt(buffer1, buffer2);
	printf("  Encrypt:%s\n", buffer2);
	pCrypto->Decrypt(buffer2, buffer3);
	printf("  Decrypt:%s\n", buffer3);
	delete pCrypto;

	return 0;
}

/// -h option implementation
int HelpFunction(CAppContext *pContext)
{
	const char HELP[] = "\t%s Usage:\n"
		"-h // Display usage.\n"
		"-t // Test encryption and descryption function.\n"
		"-d // Descrypt OracleUserFileDes specified in ini file.\n"
		"-e // Encrypt OracleUserFileTxt specified in ini file.\n"
		"-s // Start this program as server.\n"
		"-c ServerIP -p Port -n Environment -b DBName -u DBUser. // Get Oracle password.\n"
		"-c IP1-IP2 -p Port -n Environment -b DBName -u DBUser. // Get Oracle password.\n"
		"-c IP1,IP2 -p Port -n Environment -b DBName -u DBUser. // Get Oracle password.\n";
	printf(HELP, pContext->GetAppName());
	return 0;
}

/// -e option implementation
int EncryptFunction(CAppContext *pContext)
{
	printf("Encrypt Oracle user file...\n");
	printf("Get the application's encrypt/decrypt password:");
	char szPassword[256];
	scanf("%s", szPassword);

	if (strcmp(szPassword, pContext->GetPassword())!=0) {
		printf("Sorry, the password doesn't match with this application, quit.\n");
		return 1;
	}

	CConfig *pConfig = new CConfig("OraclePass.ini");
	pContext->SetConfig(pConfig);

	char szLog[512];
	CDBUser::TransferDir(szLog, pConfig->getConfig("LogFile"));
	FILE *fpLog = fopen(szLog, "a");
	if (fpLog==NULL) {
		return 2;
	}
	CFileLogger *pLogger = new CFileLogger();
	pLogger->AttachFile(fpLog);
	pContext->SetLogger(pLogger);
	IEncryptAlgorithm *pCrypto = new CTripleDesEncryptAlgorithm(pContext->GetPassword());
	pContext->SetCrypto(pCrypto);

	CDBUser *pDBUser = new CDBUser(pContext);
	pDBUser->EncryptFile();

	delete pDBUser;
	delete pCrypto;
	delete pLogger;
	delete pConfig;
	return 0;
}

/// -d option implementation
int DecryptFunction(CAppContext *pContext)
{
	printf("Decrypt Oracle user file...\n");
	printf("Get the application's encrypt/decrypt password:");
	char szPassword[256];
	scanf("%s", szPassword);

	if (strcmp(szPassword, pContext->GetPassword())!=0) {
		printf("Sorry, the password doesn't match with this application, quit.\n");
		return 1;
	}

	CConfig *pConfig = new CConfig("OraclePass.ini");
	pContext->SetConfig(pConfig);

	char szLog[512];
	CDBUser::TransferDir(szLog, pConfig->getConfig("LogFile"));
	FILE *fpLog = fopen(szLog, "a");
	if (fpLog==NULL) {
		return 2;
	}
	CFileLogger *pLogger = new CFileLogger();
	pLogger->AttachFile(fpLog);
	pContext->SetLogger(pLogger);
	IEncryptAlgorithm *pCrypto = new CTripleDesEncryptAlgorithm(pContext->GetPassword());
	pContext->SetCrypto(pCrypto);

	CDBUser *pDBUser = new CDBUser(pContext);
	pDBUser->DecryptFile();

	delete pDBUser;
	delete pCrypto;
	delete pLogger;
	delete pConfig;
	return 0;
}

/// -s option implementation
int ServerFunction(CAppContext *pContext)
{
	CConfig *pConfig = new CConfig("OraclePass.ini");
	pContext->SetConfig(pConfig);

	char szLog[512];
	CDBUser::TransferDir(szLog, pConfig->getConfig("LogFile"));
	FILE *fpLog = fopen(szLog, "a");
	if (fpLog==NULL) {
		return 2;
	}
	CFileLogger *pLogger = new CFileLogger();
	pLogger->AttachFile(fpLog);
	pContext->SetLogger(pLogger);
	pLogger->output("%s is starting...\n", pContext->GetAppName());
	IEncryptAlgorithm *pCrypto = new CTripleDesEncryptAlgorithm(pContext->GetPassword());
	pContext->SetCrypto(pCrypto);

	CDBUser *pDBUser = new CDBUser(pContext);
	if (pDBUser->LoadFile()!=0) {
		return 1;
	}

	char szLocalIP[128] = "tcp://127.0.0.1:";
	CServiceName location1(strcat(szLocalIP, pConfig->getConfig("ListenPort")) );

	strcpy(szLocalIP, "tcp://127.0.0.1:");
	CServiceName location2(strcat(szLocalIP, pConfig->getConfig("ManagePort")) );

	CTcpServer srvListen(&location1, pLogger, 1);
	srvListen.SetDBUser(pDBUser);
	srvListen.SetReloadFile(false);

	CTcpServer srvManage(&location2, pLogger);
	srvManage.SetDBUser(pDBUser);
	srvManage.SetReloadFile(true);

	pLogger->output("%s is started.\n", pContext->GetAppName());

	fd_set active, read;
	int nMaxFD, nRet;
	CChannel *p = srvListen.GetChannel();
	while (1) {
		FD_ZERO(&active);
		FD_SET(srvListen.GetId(), &active);
		FD_SET(srvManage.GetId(), &active);
		nMaxFD = srvListen.GetId();
		if (nMaxFD<srvManage.GetId()) {
			nMaxFD = srvManage.GetId();
		}
		int i;
		for (i=0; i<CHANNEL_MAX; i++) {
			if (p[i].m_nID!=-1) {
				FD_SET(p[i].m_nID, &active);
				if (nMaxFD < p[i].m_nID) {
					nMaxFD = p[i].m_nID;
				}
			}
		}
		nMaxFD++;

		read = active;
		nRet = select(nMaxFD, &read, NULL, NULL, NULL);
		if (nRet<=0) {
#ifdef WINDOWS
			Sleep(30);
#else
			usleep(1000);
#endif
			continue;
		}
		if (FD_ISSET(srvListen.GetId(), &read)) {
			srvListen.Accept(10);
		}
		if (FD_ISSET(srvManage.GetId(), &read)) {
			srvManage.Accept(10);
		}
		time_t tNow=time(NULL);
		for (i=0; i<CHANNEL_MAX; i++) {
			if (p[i].m_nID==-1) {
				continue;
			}
			if (FD_ISSET(p[i].m_nID, &read)) {
				srvListen.ReadChannel(i);
			}
			else {
				if (tNow>p[i].tLogin) {
					srvListen.CloseChannel(i);
				}
			}
		}
	}

	delete pDBUser;
	delete pCrypto;
	delete pLogger;
	delete pConfig;
	return 0;
}
