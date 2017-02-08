#include "FileCheck.h"
#include "md5Handler.h"

extern int	g_nTimeZoneSec;						//换算成秒的时差
extern char g_pHostName[32];					// 保存主机名称
extern char g_pDataCenterName[32];				// 保存数据中心名称
extern CManageConSession g_mManageConSession;	// 保存所有连接的地址信息
#define DBSENDPACKAGETO g_mManageConSession.sendFTDCPackage(&m_pkgSend);

#define BUFSIZE			10240

map<string, string> g_mapCheckFile;
map<string, string>::iterator g_mapIt;
map<string, CHtmlTestValue> g_mapCheckHtml;
map<string, CHtmlTestValue>::iterator g_mapCheckIt;

list<CFTDRtnWarningEventField> CFileCheckThread:: s_warningEvent;
list<CFTDRtnSyslogEventField> CFileCheckThread:: s_syslogEvent;
CMutex CFileCheckThread:: s_lockData;

#ifdef LINUX
map<string, CFileCheckValue> g_mapCheckResult;

int CFileCheckThread::fn(const char *file, const struct stat *sb, int flag)
{
	if (FTW_F == flag)	// 仅检查一般文件
	{
		struct stat filestat;
		if (stat(file, &filestat) < 0)
		{				// 读取文件状态失败,不校验该文件返回
			return 0;
		}

		map<string, CFileCheckValue>::iterator	checkIt = g_mapCheckResult.find(
				file);

		if (checkIt == g_mapCheckResult.end())	//第一次遍历到此文件
		{
			char dstFile[512];
			sprintf(
				dstFile,
				"%s%s.MD5",
				g_mapIt->second.c_str(),
				file + g_mapIt->first.length());
			g_mapCheckResult[file] = CFileCheckValue(0, 0, dstFile);
			checkIt = g_mapCheckResult.find(file);
		}

		if (filestat.st_mtime == checkIt->second.st_time
		&&	filestat.st_size == checkIt->second.st_size)
		{	// 该文件自动上次校验后没有发生变化，不需要校验
			// printf("Not Need Check srcFile [%s] st_mtime %d st_size %d\n", file, checkIt->second.st_time, checkIt->second.st_size);
			return 0;
		}

		// printf("Check srcFile [%s] dstFile [%s] time %d size %d\n", file, checkIt->second.md5file.c_str(),checkIt->second.st_time,checkIt->second.st_size);
		int i = GenMD5File(file, checkIt->second.md5file.c_str());

		CFTDRtnWarningEventField fieldInfo;
		memset(&fieldInfo, 0, sizeof(fieldInfo));

		time_t	timep = time((time_t *)NULL);
		struct tm tm_time;
		LocalTime((time_t *) &timep, &tm_time);
		sprintf(
			(char *)fieldInfo.MonTime.getValue(),
			"%02d:%02d:%02d",
			tm_time.tm_hour,
			tm_time.tm_min,
			tm_time.tm_sec);
		sprintf(
			(char *)fieldInfo.MonDate.getValue(),
			"%04d%02d%02d",
			tm_time.tm_year + 1900,
			tm_time.tm_mon + 1,
			tm_time.tm_mday);
		fieldInfo.ProcessFlag = "N";
		sprintf(
			(char *)fieldInfo.ObjectID.getValue(),
			"%s.%s.%s",
			g_pDataCenterName,
			DATACENTERHOST,
			g_pHostName);
		fieldInfo.EvendID = 0;
		fieldInfo.EventNum = 0;
		fieldInfo.EventDes = file + g_mapIt->first.length();
		fieldInfo.OccurDate = fieldInfo.MonDate.getValue();
		fieldInfo.OccurTime = fieldInfo.MonTime.getValue();

		if (i == 0)
		{
			fieldInfo.EventName = EVENT_MD5CHECK_SUCCESS;
			if (checkIt->second.st_time == 0)
			{
				checkIt->second.st_time = filestat.st_mtime;
				checkIt->second.st_size = filestat.st_size;
				checkIt->second.mResult = i;

				//printf("First Success check, Do not Send event.\n");
				return 0;
			}

			CFTDRtnSyslogEventField *pEvent = (CFTDRtnSyslogEventField *)
				(&fieldInfo);
			s_lockData.Lock();
			s_syslogEvent.push_back(*pEvent);
			s_lockData.UnLock();
		}
		else if (i == -1)
		{
			fieldInfo.EventName = EVENT_NOMD5FILE_ERROR;
			s_lockData.Lock();
			s_warningEvent.push_back(fieldInfo);
			s_lockData.UnLock();
		}
		else
		{
			fieldInfo.EventName = EVENT_MD5CHECK_ERROR;
			s_lockData.Lock();
			s_warningEvent.push_back(fieldInfo);
			s_lockData.UnLock();
		}

		//printf("\t%s\n",fieldInfo.ObjectID.getValue());
		//printf("\t%s\n",fieldInfo.EventName.getValue());
		//printf("\t%s\n",fieldInfo.MonDate.getValue());
		//printf("\t%s\n",fieldInfo.MonTime.getValue());
		//printf("\t%s\n",fieldInfo.EventDes.getValue());
		checkIt->second.st_time = filestat.st_mtime;
		checkIt->second.st_size = filestat.st_size;
		checkIt->second.mResult = i;
	}

	return 0;
}

#endif
CFileCheckThread::CFileCheckThread(void)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	m_pJudgeRun = NULL;
	m_pHtmlRun = NULL;
}

CFileCheckThread::~CFileCheckThread(void)
{
	ExitThread();
	if (m_pJudgeRun != NULL)
	{
		delete m_pJudgeRun;
		m_pJudgeRun = NULL;
	}

	if (m_pHtmlRun != NULL)
	{
		delete m_pHtmlRun;
		m_pHtmlRun = NULL;
	}
}

/**虚函数，子类可做一些实例化工作
* @return true:创建成功 false:创建失败
*/
bool CFileCheckThread::InitInstance(void)
{
	return true;
}

/**虚函数，子类清楚实例
*/
void CFileCheckThread::ExitInstance(void)
{
}

/**线程开始运行，纯虚函数，子类必须继承实现
*/
void CFileCheckThread::Run(void)
{
	OSSleep(60);

	while (1)
	{
		time_t	nTimeZone = time((time_t *)NULL);
		nTimeZone = nTimeZone - g_nTimeZoneSec;
		if (NULL != m_pJudgeRun)
		{
			if (m_pJudgeRun->needExcute(nTimeZone))
			{
				m_lockMap.Lock();
				g_mapCheckFile = m_mapCheckFile;
				m_lockMap.UnLock();
				for (g_mapIt = g_mapCheckFile.begin();
					 g_mapIt != g_mapCheckFile.end();
					 g_mapIt++)
				{
#ifdef LINUX
					ftw(g_mapIt->first.c_str(), &fn, 1000);
#endif
					s_lockData.Lock();

					CFTDRtnSyslogEventField logEvent;
					memset(&logEvent, 0, sizeof(logEvent));

					time_t	timep = time((time_t *)NULL);
					struct tm tm_time;
					LocalTime((time_t *) &timep, &tm_time);
					sprintf(
						(char *)logEvent.MonTime.getValue(),
						"%02d:%02d:%02d",
						tm_time.tm_hour,
						tm_time.tm_min,
						tm_time.tm_sec);
					sprintf(
						(char *)logEvent.MonDate.getValue(),
						"%04d%02d%02d",
						tm_time.tm_year + 1900,
						tm_time.tm_mon + 1,
						tm_time.tm_mday);
					sprintf(
						(char *)logEvent.ObjectID.getValue(),
						"%s.%s.%s",
						g_pDataCenterName,
						DATACENTERHOST,
						g_pHostName);
					logEvent.EvendID = 0;
					logEvent.EventNum = 0;
					logEvent.OccurDate = logEvent.MonDate.getValue();
					logEvent.OccurTime = logEvent.MonTime.getValue();
					logEvent.EventDes = g_mapIt->first.c_str();
					logEvent.EventName = EVENT_MD5CHECK_TIME;
					s_syslogEvent.push_back(logEvent);

					s_lockData.UnLock();
				}
			}
		}

		if (NULL != m_pHtmlRun)
		{
			if (m_pHtmlRun->needExcute(nTimeZone))
			{
				m_lockMap.Lock();
				g_mapCheckHtml = m_mapCheckHtml;
				m_lockMap.UnLock();
				for (g_mapCheckIt = g_mapCheckHtml.begin();
					 g_mapCheckIt != g_mapCheckHtml.end();
					 g_mapCheckIt++)
				{
					htmlTestPage(
						g_mapCheckIt->first.c_str(),
						g_mapCheckIt->second.m_sDomain.c_str(),
						g_mapCheckIt->second.m_nPort,
						g_mapCheckIt->second.m_sHtmlUrl.c_str(),
						g_mapCheckIt->second.m_sHtmlValue.c_str());
				}
			}
		}

		OSSleep(1);
	}
}

void CFileCheckThread::GetSpi(void)
{
	TIME_MEASURE_START(__FUNCTION__);
	s_lockData.Lock();

	list<CFTDRtnObjectAttrField>::iterator	attrIt;
	m_pkgSend.PreparePackage(
			FTD_TID_RtnObjectAttrTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	for (attrIt = s_objectAttr.begin(); attrIt != s_objectAttr.end(); ++attrIt)
	{
		if (m_pkgSend.Length() +
			sizeof(CFTDRtnObjectAttrField) >= FTDC_PACKAGE_MAX_SIZE)
		{
			DBSENDPACKAGETO;
			m_pkgSend.PreparePackage(
					FTD_TID_RtnObjectAttrTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
		}

		FTDC_ADD_FIELD(&m_pkgSend, &(*attrIt));
	}

	if (m_pkgSend.Length() > 0)
	{
		DBSENDPACKAGETO;
	}

	s_objectAttr.clear();

	list<CFTDRtnSyslogEventField>::iterator logIt;
	m_pkgSend.PreparePackage(
			FTD_TID_RtnSyslogEventTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	for (logIt = s_syslogEvent.begin(); logIt != s_syslogEvent.end(); ++logIt)
	{
		if (m_pkgSend.Length() +
			sizeof(CFTDRtnSyslogEventField) >= FTDC_PACKAGE_MAX_SIZE)
		{
			DBSENDPACKAGETO;
			m_pkgSend.PreparePackage(
					FTD_TID_RtnSyslogEventTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
		}

		FTDC_ADD_FIELD(&m_pkgSend, &(*logIt));
	}

	if (m_pkgSend.Length() > 0)
	{
		DBSENDPACKAGETO;
	}

	s_syslogEvent.clear();

	list<CFTDRtnWarningEventField>::iterator eventIt;
	m_pkgSend.PreparePackage(
			FTD_TID_RtnWarningEventTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	for (eventIt = s_warningEvent.begin();
		 eventIt != s_warningEvent.end();
		 ++eventIt)
	{
		if (m_pkgSend.Length() +
			sizeof(CFTDRtnWarningEventField) >= FTDC_PACKAGE_MAX_SIZE)
		{
			DBSENDPACKAGETO;
			m_pkgSend.PreparePackage(
					FTD_TID_RtnWarningEventTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
		}

		FTDC_ADD_FIELD(&m_pkgSend, &(*eventIt));
	}

	if (m_pkgSend.Length() > 0)
	{
		DBSENDPACKAGETO;
	}

	s_warningEvent.clear();

	s_lockData.UnLock();

	TIME_MEASURE_END(__FUNCTION__);

	return;
}

int CFileCheckThread::htmlTest(
	const char	*pObjectName,
	const char	*pServerIp,
	int nPort,
	const char	*pServerName,
	const char	*pHtmlUrl,
	const char	*pHtmlValue)
{
	int sSocket;
	sockaddr_in stSvrAddrIn = { 0 };			/* 服务器端地址 */
	char sndBuf[512] = { 0 };
	char rcvBuf[BUFSIZE] = { 0 };
	char tmpBuf[BUFSIZE] = { 0 };
	char *pRcv = rcvBuf;
	int num = 0;
	int nRet = -1;

	/* HTTP 消息构造开始，这是程序的关键之处 */
	sprintf(sndBuf, "GET %s HTTP/1.1\r\nHost: %s\r\n", pHtmlUrl, pServerName);
	strcat(sndBuf, "Connection: Keep-Alive\r\n");
	strcat(sndBuf, "\r\n");

	/* HTTP 消息构造结束 */
	stSvrAddrIn.sin_family = AF_INET;
	stSvrAddrIn.sin_port = htons(nPort);
	stSvrAddrIn.sin_addr.s_addr = inet_addr(pServerIp);

	sSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	/* 连接 */
	nRet = connect(
			sSocket,
			(struct sockaddr *) &stSvrAddrIn,
			sizeof(struct sockaddr));
	if (-1 == nRet)
	{
		CFTDRtnWarningEventField fieldInfo;
		memset(&fieldInfo, 0, sizeof(fieldInfo));

		time_t	timep = time((time_t *)NULL);
		struct tm tm_time;
		LocalTime((time_t *) &timep, &tm_time);
		sprintf(
			(char *)fieldInfo.MonTime.getValue(),
			"%02d:%02d:%02d",
			tm_time.tm_hour,
			tm_time.tm_min,
			tm_time.tm_sec);
		sprintf(
			(char *)fieldInfo.MonDate.getValue(),
			"%04d%02d%02d",
			tm_time.tm_year + 1900,
			tm_time.tm_mon + 1,
			tm_time.tm_mday);
		fieldInfo.ProcessFlag = "N";
		sprintf(
			(char *)fieldInfo.ObjectID.getValue(),
			"%s.%s.%s",
			g_pDataCenterName,
			DATACENTERAPP,
			pObjectName);
		fieldInfo.EvendID = 0;
		fieldInfo.EventNum = 0;
		sprintf(
			(char *)fieldInfo.EventDes.getValue(),
			"无法连接到web服务器[%s]",
			pServerIp);
		fieldInfo.EventName = EVENT_WEBCHECK_ERROR;
		fieldInfo.OccurDate = fieldInfo.MonDate.getValue();
		fieldInfo.OccurTime = fieldInfo.MonTime.getValue();
		s_lockData.Lock();
		s_warningEvent.push_back(fieldInfo);
		s_lockData.UnLock();
#ifdef WIN32
		closesocket(sSocket);
#else
		close(sSocket);
#endif
		return -2;
	}

	/* 发送HTTP请求消息 */
	send(sSocket, (char *)sndBuf, sizeof(sndBuf), 0);

	/* 接收HTTP响应消息 */
	while (1)
	{
		num = recv(sSocket, pRcv, BUFSIZE - (pRcv - rcvBuf), 0);
		pRcv += num;
		if ((0 == num) || (-1 == num))
		{
			break;
		}

#ifdef WIN32
		break;
#endif
	}

#ifdef WIN32
	closesocket(sSocket);
#else
	close(sSocket);
#endif

	/* 打印响应消息 */
#ifdef PRINT_DEBUG
	printf("WebsiteCode check:\nRecv[%s]\n", rcvBuf);
#endif

	/// Added by Henchi, 20120912
	if (strlen(rcvBuf) > 0)
	{
		strncpy(tmpBuf, rcvBuf, strlen(rcvBuf));
		m_iAttrCount = 0;
		m_iSuccessCount = 0;
		m_iFailedCount = 0;

		char *pToken = strtok(tmpBuf, "\r\n");
		while (pToken != NULL)
		{
			Analizer(pObjectName, pToken, pHtmlValue);
			pToken = strtok(NULL, "\r\n");
		}

		if (m_iAttrCount != -1)
		{
			///当http Rtn code 合法时计算各指标事件计数
			if (m_iAttrCount + m_iFailedCount + m_iSuccessCount == 0)
			{
				/// 未采集到任何指标及事件信息，需要告警
				CFTDRtnWarningEventField fieldInfo;
				memset(&fieldInfo, 0, sizeof(fieldInfo));

				time_t	timep = time((time_t *)NULL);
				struct tm tm_time;
				LocalTime((time_t *) &timep, &tm_time);
				sprintf(
					(char *)fieldInfo.MonTime.getValue(),
					"%02d:%02d:%02d",
					tm_time.tm_hour,
					tm_time.tm_min,
					tm_time.tm_sec);
				sprintf(
					(char *)fieldInfo.MonDate.getValue(),
					"%04d%02d%02d",
					tm_time.tm_year + 1900,
					tm_time.tm_mon + 1,
					tm_time.tm_mday);
				fieldInfo.ProcessFlag = "N";
				sprintf(
					(char *)fieldInfo.ObjectID.getValue(),
					"%s.%s.%s",
					g_pDataCenterName,
					DATACENTERAPP,
					pObjectName);
				fieldInfo.EvendID = 0;
				fieldInfo.EventNum = 0;
				fieldInfo.OccurDate = fieldInfo.MonDate.getValue();
				fieldInfo.OccurTime = fieldInfo.MonTime.getValue();
				sprintf(
					(char *)fieldInfo.EventDes.getValue(),
					"校验页面分析失败[%s]",
					rcvBuf);
				fieldInfo.EventName = EVENT_WEBCHECK_ERROR;
				s_lockData.Lock();
				s_warningEvent.push_back(fieldInfo);
				s_lockData.UnLock();
			}
			else
			{
				/// 以日志事件报告此次采样的指标事件计数情况
				CFTDRtnSyslogEventField fieldInfo;
				memset(&fieldInfo, 0, sizeof(fieldInfo));

				time_t	timep = time((time_t *)NULL);
				struct tm tm_time;
				LocalTime((time_t *) &timep, &tm_time);
				sprintf(
					(char *)fieldInfo.MonTime.getValue(),
					"%02d:%02d:%02d",
					tm_time.tm_hour,
					tm_time.tm_min,
					tm_time.tm_sec);
				sprintf(
					(char *)fieldInfo.MonDate.getValue(),
					"%04d%02d%02d",
					tm_time.tm_year + 1900,
					tm_time.tm_mon + 1,
					tm_time.tm_mday);
				fieldInfo.ProcessFlag = "L";
				sprintf(
					(char *)fieldInfo.ObjectID.getValue(),
					"%s.%s.%s",
					g_pDataCenterName,
					DATACENTERAPP,
					pObjectName);
				fieldInfo.EvendID = 0;
				fieldInfo.EventNum = 0;
				fieldInfo.OccurDate = fieldInfo.MonDate.getValue();
				fieldInfo.OccurTime = fieldInfo.MonTime.getValue();
				sprintf(
					(char *)fieldInfo.EventDes.getValue(),
					"校验页面分析计数 Attr[%d] Success[%d] Failed[%d]",
					m_iAttrCount,
					m_iSuccessCount,
					m_iFailedCount);
				fieldInfo.EventName = EVENT_WEBCHECK;
				s_lockData.Lock();
				s_syslogEvent.push_back(fieldInfo);
				s_lockData.UnLock();
				
				/// 以指标形式报告对象状态
				CFTDRtnObjectAttrField	AttrInfo;
				memset(&AttrInfo, 0, sizeof(AttrInfo));
				AttrInfo.MonTime = fieldInfo.MonTime;
				AttrInfo.MonDate = fieldInfo.MonDate;
				sprintf(
					(char *)AttrInfo.ObjectID.getValue(),
					"%s.%s.%s",
					g_pDataCenterName,
					DATACENTERAPP,
					pObjectName);
				AttrInfo.ValueType = INT_ATTR;

				AttrInfo.AttrType = "Active";
				sprintf((char *)AttrInfo.AttrValue.getValue(), "%d", 1);
				s_lockData.Lock();
				s_objectAttr.push_back(AttrInfo);
				s_lockData.UnLock();

				AttrInfo.AttrType = "AttrCount";
				sprintf((char *)AttrInfo.AttrValue.getValue(), "%d", m_iAttrCount);
				s_lockData.Lock();
				s_objectAttr.push_back(AttrInfo);
				s_lockData.UnLock();

				AttrInfo.AttrType = "SuccessCount";
				sprintf((char *)AttrInfo.AttrValue.getValue(), "%d", m_iSuccessCount);
				s_lockData.Lock();
				s_objectAttr.push_back(AttrInfo);
				s_lockData.UnLock();

				AttrInfo.AttrType = "FailedCount";
				sprintf((char *)AttrInfo.AttrValue.getValue(), "%d", m_iFailedCount);
				s_lockData.Lock();
				s_objectAttr.push_back(AttrInfo);
				s_lockData.UnLock();

			}
		}
	}

#if 0
	strncpy(tmpBuf, rcvBuf, strlen(rcvBuf));
	pRcv = strstr(tmpBuf, "Content-Type: text/html");
	if (pRcv != NULL)
	{
		pRcv = strstr(pRcv, "\r\n");
		if (pRcv != NULL)
		{
			pRcv = pRcv + 2;
			while ((*pRcv == '\r' || *pRcv == '\n') && *pRcv != '\0')
			{
				pRcv++;
			}

			char *p = pRcv;
			while (*p != '\r' && *p != '\n' && *p != '\0')
			{
				p++;
			}

			*p = '\0';
		}
	}

	// printf("[%s]\n", pRcv);
	//if ((pRcv!= NULL) && (strcmp(pHtmlValue, pRcv) != 0))
	if ((pRcv != NULL) && (strncmp(pHtmlValue, pRcv, strlen(pHtmlValue)) != 0))
	{
		// Added by Henchi, 20100208
		printf(
			"On CFileCheckThread::htmlTest\nrcvBuf[%s]\npRcv[%s]\n",
			rcvBuf,
			pRcv);
		fflush(stdout);

		CFTDRtnWarningEventField fieldInfo;
		memset(&fieldInfo, 0, sizeof(fieldInfo));

		time_t	timep = time((time_t *)NULL);
		struct tm tm_time;
		LocalTime((time_t *) &timep, &tm_time);
		sprintf(
			(char *)fieldInfo.MonTime.getValue(),
			"%02d:%02d:%02d",
			tm_time.tm_hour,
			tm_time.tm_min,
			tm_time.tm_sec);
		sprintf(
			(char *)fieldInfo.MonDate.getValue(),
			"%04d%02d%02d",
			tm_time.tm_year + 1900,
			tm_time.tm_mon + 1,
			tm_time.tm_mday);
		fieldInfo.ProcessFlag = "N";
		sprintf(
			(char *)fieldInfo.ObjectID.getValue(),
			"%s.%s.%s",
			g_pDataCenterName,
			DATACENTERHOST,
			g_pHostName);
		fieldInfo.EvendID = 0;
		fieldInfo.EventNum = 0;
		fieldInfo.OccurDate = fieldInfo.MonDate.getValue();
		fieldInfo.OccurTime = fieldInfo.MonTime.getValue();

		string	des = "校验结果不同:";
		des.append(pHtmlValue);
		des.append(" VS ");
		des.append(pRcv);
		fieldInfo.EventDes = des.c_str();
		fieldInfo.EventName = EVENT_WEBCHECK_ERROR;
		s_lockData.Lock();
		s_warningEvent.push_back(fieldInfo);
		s_lockData.UnLock();
	}
	else
	{
		CFTDRtnSyslogEventField logEvent;
		memset(&logEvent, 0, sizeof(logEvent));

		time_t	timep = time((time_t *)NULL);
		struct tm tm_time;
		LocalTime((time_t *) &timep, &tm_time);
		sprintf(
			(char *)fieldInfo.MonTime.getValue(),
			"%02d:%02d:%02d",
			tm_time.tm_hour,
			tm_time.tm_min,
			tm_time.tm_sec);
		sprintf(
			(char *)fieldInfo.MonDate.getValue(),
			"%04d%02d%02d",
			tm_time.tm_year + 1900,
			tm_time.tm_mon + 1,
			tm_time.tm_mday);
		sprintf(
			(char *)logEvent.ObjectID.getValue(),
			"%s.%s.%s",
			g_pDataCenterName,
			DATACENTERHOST,
			g_pHostName);
		logEvent.EvendID = 0;
		logEvent.EventNum = 0;
		logEvent.EventDes = pHtmlUrl;
		logEvent.EventName = EVENT_WEBCHECK_TIME;
		logEvent.OccurDate = logEvent.MonDate.getValue();
		logEvent.OccurTime = logEvent.MonTime.getValue();
		s_lockData.Lock();
		s_syslogEvent.push_back(logEvent);
		s_lockData.UnLock();
	}

#endif
	return 0;
}

void CFileCheckThread::Analizer(
	const char	*pObjectName,
	char *pToken,
	const char	*pHtmlValue)
{
	char szHttpCode[8];
	char szHttpStatus[8];
	char szAttrName[64];
	char szResult[64];
	char szMsg[4096];

	if (sscanf(pToken, "HTTP/%*s %s %s %*", szHttpCode, szHttpStatus) == 2)
	{
#ifdef PRINT_DEBUG
		printf("get Http rtn code [%s] [%s]\n", szHttpCode, szHttpStatus);
#endif
		if (atoi(szHttpCode) != 200)
		{
			/// 如果HTTP返回码不为200,则产生告警事件
			CFTDRtnWarningEventField fieldInfo;
			memset(&fieldInfo, 0, sizeof(fieldInfo));

			time_t	timep = time((time_t *)NULL);
			struct tm tm_time;
			LocalTime((time_t *) &timep, &tm_time);
			sprintf(
				(char *)fieldInfo.MonTime.getValue(),
				"%02d:%02d:%02d",
				tm_time.tm_hour,
				tm_time.tm_min,
				tm_time.tm_sec);
			sprintf(
				(char *)fieldInfo.MonDate.getValue(),
				"%04d%02d%02d",
				tm_time.tm_year + 1900,
				tm_time.tm_mon + 1,
				tm_time.tm_mday);
			fieldInfo.ProcessFlag = "N";
			sprintf(
				(char *)fieldInfo.ObjectID.getValue(),
				"%s.%s.%s",
				g_pDataCenterName,
				DATACENTERAPP,
				pObjectName);
			fieldInfo.EvendID = 0;
			fieldInfo.EventNum = 0;
			fieldInfo.OccurDate = fieldInfo.MonDate.getValue();
			fieldInfo.OccurTime = fieldInfo.MonTime.getValue();
			sprintf(
				(char *)fieldInfo.EventDes.getValue(),
				"校验页面返回码异常[%s]",
				pToken);
			fieldInfo.EventName = EVENT_WEBCHECK_ERROR;
			s_lockData.Lock();
			s_warningEvent.push_back(fieldInfo);
			s_lockData.UnLock();

			///Rtn code 异常标记
			m_iAttrCount = -1;
			return;
		}
	}
	else if (strchr(pToken, '=') != NULL)
	{
		szAttrName[0] = 0x00;
		szResult[0] = 0x00;
		szMsg[0] = 0x00;

		int iToken = sscanf(
				pToken,
				"%[a-zA-Z0-9_-]='%[^,'=]',%[^\n]",
				szAttrName,
				szResult,
				szMsg);
		if (iToken >= 2)
		{
#ifdef PRINT_DEBUG
			printf("Analyzer [%s] [%s] [%s]\n", szAttrName, szResult, szMsg);
#endif

			/// 为每一条记录的首个Key=Value键值对发送RtnObjectAttr数据
			CFTDRtnObjectAttrField	fieldInfo;
			memset(&fieldInfo, 0, sizeof(fieldInfo));

			time_t	timep = time((time_t *)NULL);
			struct tm tm_time;
			LocalTime((time_t *) &timep, &tm_time);
			sprintf(
				(char *)fieldInfo.MonTime.getValue(),
				"%02d:%02d:%02d",
				tm_time.tm_hour,
				tm_time.tm_min,
				tm_time.tm_sec);
			sprintf(
				(char *)fieldInfo.MonDate.getValue(),
				"%04d%02d%02d",
				tm_time.tm_year + 1900,
				tm_time.tm_mon + 1,
				tm_time.tm_mday);
			sprintf(
				(char *)fieldInfo.ObjectID.getValue(),
				"%s.%s.%s",
				g_pDataCenterName,
				DATACENTERAPP,
				pObjectName);
			fieldInfo.AttrType = szAttrName;
			fieldInfo.AttrValue = szResult;

			if (isalpha(szResult[0])
			||	strchr(szResult, ':')
			||	strchr(szResult, ' '))
			{
				fieldInfo.ValueType = STRING_ATTR;
			}
			else if (isdigit(szResult[0]))
			{
				if (strchr(szResult, '.'))
				{
					fieldInfo.ValueType = FLOAT_ATTR;
				}
				else
				{
					fieldInfo.ValueType = INT_ATTR;
				}
			}

			s_lockData.Lock();
			s_objectAttr.push_back(fieldInfo);
			s_lockData.UnLock();

			if (strcmp(szResult, pHtmlValue) == 0)
			{
				/// 符合标记则为非法状态
				m_iFailedCount++;

				CFTDRtnWarningEventField fieldInfo;
				memset(&fieldInfo, 0, sizeof(fieldInfo));

				time_t	timep = time((time_t *)NULL);
				struct tm tm_time;
				LocalTime((time_t *) &timep, &tm_time);
				sprintf(
					(char *)fieldInfo.MonTime.getValue(),
					"%02d:%02d:%02d",
					tm_time.tm_hour,
					tm_time.tm_min,
					tm_time.tm_sec);
				sprintf(
					(char *)fieldInfo.MonDate.getValue(),
					"%04d%02d%02d",
					tm_time.tm_year + 1900,
					tm_time.tm_mon + 1,
					tm_time.tm_mday);
				fieldInfo.ProcessFlag = "N";
				sprintf(
					(char *)fieldInfo.ObjectID.getValue(),
					"%s.%s.%s",
					g_pDataCenterName,
					DATACENTERAPP,
					pObjectName);
				fieldInfo.EvendID = 0;
				fieldInfo.EventNum = 0;
				fieldInfo.OccurDate = fieldInfo.MonDate.getValue();
				fieldInfo.OccurTime = fieldInfo.MonTime.getValue();
				fieldInfo.EventDes = pToken;	///直接原文回传
				fieldInfo.EventName = EVENT_WEBCHECK_ERROR;
				s_lockData.Lock();
				s_warningEvent.push_back(fieldInfo);
				s_lockData.UnLock();
			}
			else if (iToken == 2)
			{
				m_iAttrCount++;
			}
			else if (iToken == 3)
			{
				m_iSuccessCount++;
			}
		}
	}
}

void CFileCheckThread::htmlTestPage(
	const char	*pObjectName,
	const char	*pServerName,
	int nPort,
	const char	*pHtmlUrl,
	const char	*pHtmlValue)
{
	struct hostent	*myhost;
	char **pp;
	struct in_addr	addr;

	myhost = gethostbyname(pServerName);
	if (myhost != NULL)
	{
		pp = myhost->h_addr_list;
	}
	else
	{
		*pp = NULL;
	}

	if (*pp == NULL)		//没有解析出域名的ip地址
	{
		CFTDRtnWarningEventField fieldInfo;
		memset(&fieldInfo, 0, sizeof(fieldInfo));

		time_t	timep = time((time_t *)NULL);
		struct tm tm_time;
		LocalTime((time_t *) &timep, &tm_time);
		sprintf(
			(char *)fieldInfo.MonTime.getValue(),
			"%02d:%02d:%02d",
			tm_time.tm_hour,
			tm_time.tm_min,
			tm_time.tm_sec);
		sprintf(
			(char *)fieldInfo.MonDate.getValue(),
			"%04d%02d%02d",
			tm_time.tm_year + 1900,
			tm_time.tm_mon + 1,
			tm_time.tm_mday);
		fieldInfo.ProcessFlag = "N";

		/// Mod by Henchi,20120912
		sprintf(
			(char *)fieldInfo.ObjectID.getValue(),
			"%s.%s.%s",
			g_pDataCenterName,
			DATACENTERAPP,
			pObjectName);
		fieldInfo.EvendID = 0;
		fieldInfo.EventNum = 0;
		sprintf(
			(char *)fieldInfo.EventDes.getValue(),
			"无法根据域名[%s]解析出IP地址",
			pServerName);
		fieldInfo.EventName = EVENT_WEBCHECK_ERROR;
		fieldInfo.OccurDate = fieldInfo.MonDate.getValue();
		fieldInfo.OccurTime = fieldInfo.MonTime.getValue();
		s_lockData.Lock();
		s_warningEvent.push_back(fieldInfo);
		s_lockData.UnLock();
	}

	while (*pp != NULL)
	{
		addr.s_addr = *((unsigned int *) *pp);

		string	ipAddr = inet_ntoa(addr);
		htmlTest(
			pObjectName,
			ipAddr.c_str(),
			nPort,
			pServerName,
			pHtmlUrl,
			pHtmlValue);
		pp++;
	}
}

void CFileCheckThread::UpdateCheckConfig(
	const char	*pCheckPath,
	const char	*pMD5Path,
	const char	*pSeps)
{
	m_lockMap.Lock();
	m_mapCheckFile[pCheckPath] = pMD5Path;
	if (NULL == m_pJudgeRun)
	{
		m_pJudgeRun = new CJudgeRun(pSeps);
	}

	m_lockMap.UnLock();
	return;
}

bool explainUrl(
	const char	*pUrl,
	string	&sDomainName,
	int &nPort,
	string	&sHtmlUrl)
{
	char buffer[65];

	char *p;

	char *q;

	char *r;
	strcpy(buffer, pUrl);
	p = buffer;
	if (strncmp(buffer, "http://", strlen("http://")) == 0
	||	strncmp(buffer, "HTTP://", strlen("http://")) == 0)
	{
		p = buffer + strlen("http://");
	}

	q = strchr(p, '/');
	if (q == NULL)
	{
		return false;
	}

	r = strchr(p, ':');
	if (r == NULL || r > q) //url中没有端口，默认为80端口
	{
		nPort = 80;
		*q = '\0';
		sDomainName = p;
		*q = '/';
		sHtmlUrl = q;
	}
	else
	{
		*r = '\0';
		sDomainName = p;
		r++;
		*q = '\0';
		nPort = atoi(r);
		*q = '/';
		sHtmlUrl = q;
	}

	return true;
}
