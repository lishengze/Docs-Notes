#include "test.h"



int htmlTest(const char *pServerIp, int nPort, const char *pServerName, const char *pHtmlUrl, const char *pHtmlValue)
{
	int      sSocket;
	sockaddr_in stSvrAddrIn = {0}; /* 服务器端地址 */
	char        sndBuf[512] = {0};
	char        rcvBuf[4096] = {0};
	char        tmpBuf[4096] = {0};
	char       *pRcv         = rcvBuf;
	int         num          = 0;
	int         nRet         = -1;

	/* HTTP 消息构造开始，这是程序的关键之处 */
	sprintf(sndBuf, "GET %s HTTP/1.1\r\nHost: %s\r\n", pHtmlUrl, pServerName);
	strcat(sndBuf, "Connection: Keep-Alive\r\n");
	strcat(sndBuf, "\r\n");
	/* HTTP 消息构造结束 */

	stSvrAddrIn.sin_family      = AF_INET;
	stSvrAddrIn.sin_port        = htons(nPort);
	stSvrAddrIn.sin_addr.s_addr = inet_addr(pServerIp);

	sSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	/* 连接 */
	nRet = connect(sSocket, (struct sockaddr *)&stSvrAddrIn, sizeof(struct sockaddr));
	printf("Connect rtn code [%d]\n", nRet);
	
	if (-1 == nRet)
	{
		printf("Connect Failed!\n");

#ifdef WIN32
		closesocket(sSocket);
#else
		close(sSocket);
#endif
		return -2;
	}

	/* 发送HTTP请求消息 */
	send(sSocket, (char*)sndBuf, sizeof(sndBuf), 0);
	printf("Connect Succeed!\nSnd msg[%s]\n", sndBuf);
	/* 接收HTTP响应消息 */
	while(1)
	{
		num = recv(sSocket, pRcv, 4096-(pRcv-rcvBuf), 0);
		pRcv += num;
		if((0 == num) || (-1 == num)) break;
	}
#ifdef WIN32
	closesocket(sSocket);
#else
	close(sSocket);
#endif
	/* 打印响应消息 */
	printf("Rcv msg[%s]\n", rcvBuf);
	strncpy(tmpBuf, rcvBuf, strlen(rcvBuf));
	pRcv = strstr(tmpBuf, "Content-Type: text/html");
	if (pRcv != NULL)
	{
		pRcv = strstr(pRcv, "\r\n");
		if(pRcv != NULL) {
			pRcv = pRcv + 2;
			while (( *pRcv == '\r' || *pRcv == '\n') && *pRcv != '\0') pRcv ++ ;
			char *p = pRcv;
			while ( *p != '\r' && *p != '\n' && *p != '\0') p++;
			*p = '\0';
		}
	}

	if ((pRcv!= NULL) && (strncmp(pHtmlValue, pRcv, strlen(pHtmlValue)) != 0))
	{
		// Added by Henchi, 20100208
		printf("Rcv msg[%s] not match standard[%s]\n", pRcv, pHtmlValue);
	} else {
		printf("Rcv msg[%s] match standard[%s]\n", pRcv, pHtmlValue);
	}
	return 0;
}
void htmlTestPage(const char * pServerName,int nPort, const char *pHtmlUrl, const char *pHtmlValue)
{
	struct hostent *myhost;
	char ** pp;
	struct in_addr addr;

	myhost = gethostbyname(pServerName);
	if (myhost != NULL)
	{
		pp = myhost->h_addr_list;
		printf("GetHost for [%s] success !\n", pServerName);
	} else {
		*pp = NULL;
		printf("GetHost for [%s] failed !\n", pServerName);
		return ;
	}

	while(*pp!=NULL)
	{
		addr.s_addr = *((unsigned int *)*pp);
		string ipAddr = inet_ntoa(addr);
		printf("GetAddress [%s]\n", ipAddr.c_str());
		htmlTest(ipAddr.c_str(), nPort, pServerName, pHtmlUrl, pHtmlValue);
		pp++;
	}
}

bool explainUrl(const char *pUrl, string & sDomainName, int & nPort, string & sHtmlUrl)
{
	char buffer[65], *p,*q,*r;
	strcpy(buffer, pUrl);
	p = buffer;
	if (strncmp(buffer, "http://", strlen("http://")) == 0 || strncmp(buffer, "HTTP://", strlen("http://")) == 0 )
	{
		p = buffer + strlen("http://");
	}
	q = strchr(p, '/');
	if ( q == NULL )
	{
		return false;
	}
	r = strchr(p, ':');
	if ( r == NULL || r > q ) //url中没有端口，默认为80端口
	{
		nPort = 80;
		*q = '\0';
		sDomainName = p;
		*q = '/';
		sHtmlUrl = q;
	} else {
		*r = '\0';
		sDomainName = p;
		r ++ ;
		*q = '\0';
		nPort = atoi( r );
		*q = '/';
		sHtmlUrl = q;
	}
	return true;
}

void myTest()
{
	string TestString = "http://www.shfe.com.cn/testweblogic.jsp";
	string domainName,testUrl;
	int httpPort;
	if(explainUrl(TestString.c_str(), domainName, httpPort, testUrl)) 
	{
		printf("explainUrl[%s]\nDomain[%s] Port[%d] Url[%s]\n", TestString.c_str(), domainName.c_str(), httpPort, testUrl.c_str());

		htmlTestPage(domainName.c_str(), httpPort, testUrl.c_str(), "SUCCESS");
	}
	else
	{
		printf("explainUrl[%s] Failed\n", TestString.c_str());
	}

}

int main(int agrc, char * argv[])
{
	myTest();
	exit(0);	
}
