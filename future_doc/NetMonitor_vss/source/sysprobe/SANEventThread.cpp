#include "SANEventThread.h"

#define BUFSIZE 1024

extern int	g_nTimeZoneSec;

SANEventInfo::SANEventInfo(void)
{
	Reset();
}

SANEventInfo::~SANEventInfo(void)
{
}

void SANEventInfo::Reset(void)
{
	m_strInfoType = "";
	m_strInfoTag = "";
	m_strEventTime = "";
	m_strReportTime = "";
	m_strExpirationTime = "";
	m_strServer = "";
	m_strController = "";
	m_strStorageSystem = "";
	m_strDeviceType = "";
	m_strBreif = "";
	m_strRuleSeverity = "";
	m_strReportNode = "";
	m_strDescription = "";
}

SANEventLog::SANEventLog(void)
{
}

SANEventLog::~SANEventLog(void)
{
}

bool SANEventLog::LoadFile(string strFileName)
{
	char szLine[4096];
	int iSize;
	FILE *pFile = fopen(strFileName.c_str(), "r");
	if (NULL != pFile)
	{
		memset(szLine, 0x00, sizeof(szLine));
		while ((fgets(szLine, sizeof(szLine) - 1, pFile)) != NULL)
		{
			m_strLines.push_back((string) szLine);
		}

		fclose(pFile);
		return m_strLines.size() > 0 ? true : false;
	}
	else
	{
		return false;
	}
}

list<string> &SANEventLog::GetLinesList(void)
{
	return m_strLines;
}

SANEventLogAnalyzer::SANEventLogAnalyzer(string strFileName)
{
	m_bWaitValue = false;
	m_iTagKey = 0;
	m_EventInfo.Reset();
	if (m_EventLog.LoadFile(strFileName))
	{
		Analyze();
	}
}

SANEventLogAnalyzer::~SANEventLogAnalyzer(void)
{
}

void SANEventLogAnalyzer::Analyze(void)
{
	list<string> &listLines = (list<string> &) m_EventLog.GetLinesList();
	list<string>::iterator	listIt = listLines.begin();
	for (int iCount = 0; listIt != listLines.end(); listIt++, iCount++)
	{
		AnalyzeLine(*listIt);
	}

	if (m_EventInfo.m_strInfoTag.length() != 0)
	{
		m_listSANEventInfo.push_back(m_EventInfo);
		m_EventInfo.Reset();
	}
}

void SANEventLogAnalyzer::AnalyzeLine(string &LineInfo)
{
	if (!HaveKey(LineInfo) && m_bWaitValue == true)
	{
		// Is Value
		switch (m_iTagKey)
		{
			case KEYNUM_DEVICE_TYPE:
				m_EventInfo.m_strDeviceType.append(LineInfo);
				break;
			case KEYNUM_BREIF:
				m_EventInfo.m_strBreif.append(LineInfo);
				break;
			case KEYNUM_SEVERITY:
				m_EventInfo.m_strRuleSeverity.append(LineInfo);
				break;
			case KEYNUM_REPORT_NODE:
				m_EventInfo.m_strReportNode.append(LineInfo);
				break;
			case KEYNUM_DESCRIPTION:
				m_EventInfo.m_strDescription.append(LineInfo);
				break;
		}
	}
}

bool SANEventLogAnalyzer::HaveKey(string &LineInfo)
{
	const char	*pStr = LineInfo.c_str();
	if (IsBlank(LineInfo))
	{
		m_bWaitValue = false;
		return false;
	}

	if (strncmp(pStr, KEYWORD_INFOTYPE_PRO, strlen(KEYWORD_INFOTYPE_PRO)) == 0)
	{
		// Get New event
		m_bWaitValue = false;
		if (m_EventInfo.m_strInfoTag.length() != 0)
		{
			m_listSANEventInfo.push_back(m_EventInfo);
		}

		m_EventInfo.Reset();
		m_EventInfo.m_strInfoType = TAG_INFOTYPE_PRO;
		m_EventInfo.m_strInfoTag =
			(
				pStr +
				strlen(KEYWORD_INFOTYPE_PRO) +
				1
			) == NULL ? "" : (pStr + strlen(KEYWORD_INFOTYPE_PRO) + 1);
	}
	else if (strncmp(
				 pStr,
			 KEYWORD_INFOTYPE_INF,
			 strlen(KEYWORD_INFOTYPE_INF)) == 0)
	{
		m_bWaitValue = false;
		if (m_EventInfo.m_strInfoTag.length() != 0)
		{
			m_listSANEventInfo.push_back(m_EventInfo);
		}

		m_EventInfo.Reset();
		m_EventInfo.m_strInfoType = TAG_INFOTYPE_INF;
		m_EventInfo.m_strInfoTag =
			(
				pStr +
				strlen(KEYWORD_INFOTYPE_INF) +
				1
			) == NULL ? "" : (pStr + strlen(KEYWORD_INFOTYPE_INF) + 1);
	}
	else if (strncmp(pStr, KEYWORD_EVENTTIME, strlen(KEYWORD_EVENTTIME)) == 0)
	{
		m_bWaitValue = false;
		m_EventInfo.m_strEventTime =
			(
				pStr +
				strlen(KEYWORD_EVENTTIME) +
				1
			) == NULL ? "" : (pStr + strlen(KEYWORD_EVENTTIME) + 1);
	}
	else if (strncmp(pStr, KEYWORD_REPORTTIME, strlen(KEYWORD_REPORTTIME)) == 0)
	{
		m_bWaitValue = false;
		m_EventInfo.m_strReportTime =
			(
				pStr +
				strlen(KEYWORD_REPORTTIME) +
				1
			) == NULL ? "" : (pStr + strlen(KEYWORD_REPORTTIME) + 1);
	}
	else if (strncmp(pStr, KEYWORD_EXPTIME, strlen(KEYWORD_EXPTIME)) == 0)
	{
		m_bWaitValue = false;
		m_EventInfo.m_strExpirationTime =
			(
				pStr +
				strlen(KEYWORD_EXPTIME) +
				1
			) == NULL ? "" : (pStr + strlen(KEYWORD_EXPTIME) + 1);
	}
	else if (strncmp(pStr, KEYWORD_STORAGE_SRV, strlen(KEYWORD_STORAGE_SRV)) == 0)
	{
		m_bWaitValue = false;
		m_EventInfo.m_strServer =
			(
				pStr +
				strlen(KEYWORD_STORAGE_SRV) +
				1
			) == NULL ? "" : (pStr + strlen(KEYWORD_STORAGE_SRV) + 1);
	}
	else if (strncmp(pStr, KEYWORD_CONTROLLER, strlen(KEYWORD_CONTROLLER)) == 0)
	{
		m_bWaitValue = false;
		m_EventInfo.m_strController =
			(
				pStr +
				strlen(KEYWORD_CONTROLLER) +
				1
			) == NULL ? "" : (pStr + strlen(KEYWORD_CONTROLLER) + 1);
	}
	else if (strncmp(pStr, KEYWORD_DEVICE_TYPE, strlen(KEYWORD_DEVICE_TYPE)) == 0)
	{
		m_bWaitValue = true;
		m_iTagKey = KEYNUM_DEVICE_TYPE;
	}
	else if (strncmp(pStr, KEYWORD_BREIF, strlen(KEYWORD_BREIF)) == 0)
	{
		m_bWaitValue = true;
		m_iTagKey = KEYNUM_BREIF;
	}
	else if (strncmp(pStr, KEYWORD_SEVERITY, strlen(KEYWORD_SEVERITY)) == 0)
	{
		m_bWaitValue = true;
		m_iTagKey = KEYNUM_SEVERITY;
	}
	else if (strncmp(pStr, KEYWORD_REPORT_NODE, strlen(KEYWORD_REPORT_NODE)) == 0)
	{
		m_bWaitValue = true;
		m_iTagKey = KEYNUM_REPORT_NODE;
	}
	else if (strncmp(pStr, KEYWORD_DESCRIPTION, strlen(KEYWORD_DESCRIPTION)) == 0)
	{
		m_bWaitValue = true;
		m_iTagKey = KEYNUM_DESCRIPTION;
	}
	else if (strncmp(pStr, KEYWORD_STORAGE_SYS, strlen(KEYWORD_STORAGE_SYS)) == 0)
	{
		m_bWaitValue = false;
		m_EventInfo.m_strStorageSystem =
			(
				pStr +
				strlen(KEYWORD_STORAGE_SYS) +
				1
			) == NULL ? "" : (pStr + strlen(KEYWORD_STORAGE_SYS) + 1);
	}
	else
	{
		return false;
	}

	return true;
}

bool SANEventLogAnalyzer::IsBlank(string &LineInfo)
{
	for (const char *pStr = LineInfo.c_str(); *pStr != 0x00; pStr++)
	{
		if (*pStr != ' ' && *pStr != '\r' && *pStr != '\n')
		{
			return false;
		}
	}

	return true;
}

CSANEventThread::CSANEventThread(
	const char	*pSANEventServerName,
	const char	*pPath,
	const char	*pSeps)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);

	m_lockData.Lock();

	m_strSANEventServer = pSANEventServerName;
	m_strPath = pPath;
	m_strSeps = pSeps;
	m_pJudgeRun = new CJudgeRun(pSeps);

	m_lockData.UnLock();
}

CSANEventThread::~CSANEventThread(void)
{
	m_lockData.Lock();
	if (m_pJudgeRun != NULL)
	{
		delete m_pJudgeRun;
		m_pJudgeRun = NULL;
	}

	m_lockData.UnLock();
	ExitThread();
}

/**虚函数，子类可做一些实例化工作
* @return true:创建成功 false:创建失败
*/
bool CSANEventThread::InitInstance(void)
{
	return true;
}

/**虚函数，子类清楚实例
*/
void CSANEventThread::ExitInstance(void)
{
}

/**线程开始运行，纯虚函数，子类必须继承实现
*/
void CSANEventThread::Run(void)
{
	//OSSleep(60);
	printf("CSANEventThread begin Run()\n");
	while (1)
	{
		if (NULL != m_pJudgeRun)
		{
			//printf("Need JdugeRun\n");
			time_t	timep;
			time(&timep);
			timep = timep - g_nTimeZoneSec;
			m_lockData.Lock();

			bool bFlag = m_pJudgeRun->needExcute(timep);
			m_lockData.UnLock();
			if (bFlag)
			{
#ifdef WINDOWS
				m_lockData.Lock();

				string	strCmd = GenCmdline(m_pJudgeRun->GetInterval());
				m_lockData.UnLock();
				SANEventCapture(strCmd.c_str());
#endif
			}
		}

		OSSleep(1);
	}
}

string CSANEventThread::GenCmdline(int nInterval)
{
	return "c:\\setenv.bat";
}

void CSANEventThread::GetSpi(void)
{
}

void CSANEventThread::Reset(
	const char	*pSANEventServerName,
	const char	*pPath,
	const char	*pSeps)
{
	m_lockData.Lock();
	if (strcmp(m_strSANEventServer.c_str(), pSANEventServerName) != 0)
	{
		m_strSANEventServer = pSANEventServerName;
	}

	if (strcmp(m_strSANEventServer.c_str(), pSANEventServerName) != 0)
	{
		m_strPath = pPath;
	}

	if (strcmp(m_strSANEventServer.c_str(), pSANEventServerName) != 0)
	{
		if (m_pJudgeRun != NULL)
		{
			delete m_pJudgeRun;
		}

		m_pJudgeRun = new CJudgeRun(pSeps);
	}

	m_lockData.UnLock();
}

#ifdef WINDOWS
BOOL CSANEventThread::CreateChildProcess(const char *pCommand)
{
	PROCESS_INFORMATION piProcInfo;
	STARTUPINFO siStartInfo;
	BOOL bFuncRetn = FALSE;

	// Set up members of the PROCESS_INFORMATION structure.
	ZeroMemory(&piProcInfo, sizeof(PROCESS_INFORMATION));

	// Set up members of the STARTUPINFO structure.
	ZeroMemory(&siStartInfo, sizeof(STARTUPINFO));
	siStartInfo.cb = sizeof(STARTUPINFO);
	siStartInfo.hStdError = hChildStdoutWr;
	siStartInfo.hStdOutput = hChildStdoutWr;
	siStartInfo.hStdInput = hChildStdinRd;
	siStartInfo.dwFlags |= STARTF_USESTDHANDLES;

	// Create the child process.
	bFuncRetn = CreateProcess(
			NULL,
			TEXT((char *)pCommand), // command line
			NULL,					// process security attributes
			NULL,					// primary thread security attributes
			TRUE,					// handles are inherited
			0,						// creation flags
			NULL,					// use parent's environment
			NULL,					// use parent's current directory
			&siStartInfo,			// STARTUPINFO pointer
			&piProcInfo);			// receives PROCESS_INFORMATION
	if (bFuncRetn == 0)
	{
		ErrorExit(TEXT("CreateProcess failed"), pCommand);
	}
	else
	{
		CloseHandle(piProcInfo.hProcess);
		CloseHandle(piProcInfo.hThread);
	}

	::WaitForSingleObject(piProcInfo.hProcess, INFINITE);
	return bFuncRetn;
}

VOID CSANEventThread::ReadFromPipe(const char *pCommand)
{
	DWORD dwRead;

	DWORD dwWritten;
	CHAR chBuf[BUFSIZE];

	// Close the write end of the pipe before reading from the
	// read end of the pipe.
	if (!CloseHandle(hChildStdoutWr))
	{
		ErrorExit(TEXT("CloseHandle failed"), pCommand);
	}

	// Read output from the child process, and write to parent's STDOUT.
	m_strReuslt.clear();
	for (;;)
	{
		if (!ReadFile(hChildStdoutRdDup, chBuf, BUFSIZE, &dwRead, NULL)
		||	dwRead == 0)
		{
			break;
		}

		m_strReuslt.append(chBuf, dwRead);

		//if (! WriteFile(hStdout, chBuf, dwRead, &dwWritten, NULL))
		//	break;
	}
}

VOID CSANEventThread::ErrorExit(LPTSTR lpszMessage, const char *pCommand)
{
	m_strReuslt.clear();
	fprintf(stderr, "命令：[%s] 错误消息：[%s]\n", pCommand, lpszMessage);

	//ExitProcess(0);
}

VOID CSANEventThread::SANEventCapture(const char *pCommand)
{
	m_strReuslt.clear();

	SECURITY_ATTRIBUTES saAttr;
	BOOL fSuccess;

	// Set the bInheritHandle flag so pipe handles are inherited.
	saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
	saAttr.bInheritHandle = TRUE;
	saAttr.lpSecurityDescriptor = NULL;

	// Get the handle to the current STDOUT.
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	// Create a pipe for the child process's STDOUT.
	if (!CreatePipe(&hChildStdoutRd, &hChildStdoutWr, &saAttr, 0))
	{
		ErrorExit(TEXT("Stdout pipe creation failed\n"), pCommand);
	}

	// Create noninheritable read handle and close the inheritable read
	// handle.
	fSuccess = DuplicateHandle(
			GetCurrentProcess(),
			hChildStdoutRd,
			GetCurrentProcess(),
			&hChildStdoutRdDup,
			0,
			FALSE,
			DUPLICATE_SAME_ACCESS);
	if (!fSuccess)
	{
		ErrorExit(TEXT("DuplicateHandle failed"), pCommand);
	}

	CloseHandle(hChildStdoutRd);

	// Create a pipe for the child process's STDIN.
	if (!CreatePipe(&hChildStdinRd, &hChildStdinWr, &saAttr, 0))
	{
		ErrorExit(TEXT("Stdin pipe creation failed\n"), pCommand);
	}

	// Duplicate the write handle to the pipe so it is not inherited.
	fSuccess = DuplicateHandle(
			GetCurrentProcess(),
			hChildStdinWr,
			GetCurrentProcess(),
			&hChildStdinWrDup,
			0,
			FALSE,					// not inherited
			DUPLICATE_SAME_ACCESS);
	if (!fSuccess)
	{
		ErrorExit(TEXT("DuplicateHandle failed"), pCommand);
	}

	CloseHandle(hChildStdinWr);

	// Now create the child process.
	fSuccess = CreateChildProcess(pCommand);
	if (!fSuccess)
	{
		ErrorExit(TEXT("Create process failed"), pCommand);
	}

	// Read from pipe that is the standard output for child process.
	ReadFromPipe(pCommand);

	return;
}

#endif
