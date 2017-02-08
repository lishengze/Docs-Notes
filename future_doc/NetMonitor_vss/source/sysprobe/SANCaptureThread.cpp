#include "SANCaptureThread.h"

extern int	g_nTimeZoneSec;						//换算成秒的时差
extern char g_pHostName[32];					// 保存主机名称
extern char g_pDataCenterName[32];				// 保存数据中心名称
extern CManageConSession g_mManageConSession;	// 保存所有连接的地址信息
#define DBSENDPACKAGETO g_mManageConSession.sendFTDCPackage(&m_pkgSend);

/**虚函数，子类可做一些实例化工作
* @return true:创建成功 false:创建失败
*/
bool CSANCaptureThread::InitInstance(void)
{
	return true;
}

/**虚函数，子类清楚实例
*/
void CSANCaptureThread::ExitInstance(void)
{
}

/**线程开始运行，纯虚函数，子类必须继承实现
*/
void CSANCaptureThread::Run(void)
{
	//OSSleep(60);
	printf("CSANCaptureThread begin Run()\n");
	while (1)
	{
		if (NULL != m_pJudgeRun)
		{
#ifdef WINDOWS
			//printf("Need JdugeRun\n");
			time_t	timep;
			time(&timep);

			struct tm tm_time;
			LocalTime(&timep, &tm_time);
			sprintf(
				(char *)m_fieldQuery.MonDate.getValue(),
				"%04d%02d%02d",
				tm_time.tm_year + 1900,
				tm_time.tm_mon + 1,
				tm_time.tm_mday);
			sprintf(
				(char *)m_fieldQuery.MonTime.getValue(),
				"%02d:%02d:%02d",
				tm_time.tm_hour,
				tm_time.tm_min,
				tm_time.tm_sec);
			timep = timep - g_nTimeZoneSec;
			if (m_pJudgeRun->needExcute(timep))
			{
				//printf("begin bianli map\n");
				m_strReuslt.clear();
				m_lockData.Lock();

				map<string, string> mCommand = m_mapCommand;
				m_lockData.UnLock();
				for (map<string, string>::iterator it = mCommand.begin();
					 it != mCommand.end();
					 it++)
				{
					sprintf(
						(char *)m_fieldQuery.ObjectID.getValue(),
						"%s.%s.%s",
						g_pDataCenterName,
						DATACENTERSAN,
						it->second.c_str());
#if 1
					printf("Begin SANCapture %d\n", timep);
					fflush(stdout);
					SANCapture(it->first.c_str());
#else
					///测试代码，从文件读取内容分析
					char buf[4096];
					int size;
					FILE *fp = fopen("./ztmp_eva.log", "r");
					if (NULL != fp)
					{
						while ((size = fread(buf, 1, 4095, fp)) > 0)
						{
							m_strReuslt.append(buf, size);
						}

						fclose(fp);
					}

#endif
					m_lockData.Lock();
					AnalysisStr();
					m_lockData.UnLock();
				}
			}

#endif
		}

		OSSleep(1);
	}
}

void CSANCaptureThread::GetSpi(void)
{
	TIME_MEASURE_START(__FUNCTION__);
	if (m_lockData.TryLock())
	{
#ifdef WINDOWS
		SendDataFromList(list_cabinet, SAN_cabinet);
		SendDataFromList(list_storagecell, SAN_storagecell);
		SendDataFromList(list_controller, SAN_controller);
		SendDataFromList(list_disk, SAN_disk);
		SendDataFromList(list_virtualdisk, SAN_virtualdisk);
		SendDataFromList(list_virtualdiskfolder, SAN_virtualdiskfolder);
		SendDataFromList(
			list_virtualdiskfamilyfolder,
			SAN_virtualdiskfamilyfolder);
		SendDataFromList(list_host, SAN_host);
		SendDataFromList(list_presentedunit, SAN_presentedunit);
		SendDataFromList(list_powersupply, SAN_powersupply);
		SendDataFromList(list_diskshelf, SAN_diskshelf);
#endif
		m_lockData.UnLock();
	}

	TIME_MEASURE_END(__FUNCTION__);
	return;
}

#ifdef WINDOWS
void CSANCaptureThread::SendDataFromList(
	list < map < string,
	string >> &lsob,
	char *pAttr)
{
	map<string, int> mapName;		///用于保存出现的所有列名称
	list < map
		<
			string, string >> ::iterator listIt; for (listIt = lsob.begin();
													  listIt != lsob.end();
													  ++listIt)
			{
				map<string, string>::iterator mit; for (mit = (*listIt).begin();
														mit != (*listIt).end();
														++mit)
				{
					mapName[mit->first] = 1;
				}
			}

			if (mapName.size() == 0)
			{
				return;
			}

			m_fieldQuery.AttrType = pAttr; ///拼接所有的列名称到一个字符串
			string
				sColName = ""; map<string, int>::iterator colIt; for (colIt = mapName.begin();
																	  colIt != mapName.end();
																	  ++colIt)
			{
				if (sColName.length() == 0)
				{
					sColName = colIt->first;
				}
				else
				{
					sColName.append(DBSEPARATORSTRING); sColName.append(colIt->first);
				}
			}

			sColName.append(
					DBSEPARATORRECORD); ///拼接一个记录的值到一个字符串，并把字符串放入字符串列表
			list
				<string
				> recordList; for (listIt = lsob.begin();
								   listIt != lsob.end();
								   ++listIt)
			{
				string sRecordValue = ""; for (colIt = mapName.begin();
											   colIt != mapName.end();
											   ++colIt)
				{
					if (sRecordValue.length() == 0)
					{
						sRecordValue = (*listIt)[colIt->first];
					}
					else
					{
						sRecordValue.append(DBSEPARATORSTRING); sRecordValue.append(
								(*listIt)[colIt->first]);
					}
				}

				sRecordValue.append(DBSEPARATORRECORD); recordList.push_back(
						sRecordValue);
			}

			///将列名sColName和值列表recordList填充到数据包并发送出去
			string pkgValue = ""; m_fieldQuery.DBQueryResult.clear(); for (list<string>::iterator rdIt = recordList.begin();
															 rdIt != recordList.end();
															 rdIt++)
			{
				if ((pkgValue.length() + (*rdIt).length())
			> 3500)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnDBQueryTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			m_fieldQuery.DBQueryResult = pkgValue.c_str();
			FTDC_ADD_FIELD(&m_pkgSend, &m_fieldQuery);
			DBSENDPACKAGETO;
			m_fieldQuery.DBQueryResult.clear();
			pkgValue = "";
		}

		if (pkgValue.length() == 0)
		{
			pkgValue = sColName;
		}

		pkgValue.append(*rdIt);
	}

	if (pkgValue.length() > 0)
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RtnDBQueryTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		m_fieldQuery.DBQueryResult = pkgValue.c_str();
		FTDC_ADD_FIELD(&m_pkgSend, &m_fieldQuery);
		DBSENDPACKAGETO;
	}

	lsob.clear();
}

VOID CSANCaptureThread::AnalysisStr(void)
{
	char *q;

	char *p = (char *)m_strReuslt.c_str();
	while (NULL != p)
	{
		p = strstr(p, "<object>");
		if (NULL == p)
		{
			break;
		}

		q = strstr(p, "</object>");
		if (NULL != q)
		{
			AnalysisXml(p, q - p + strlen("</object>"));
		}

		p = q + strlen("</object>");
	}
}

VOID CSANCaptureThread::AnalysisXml(char *pStart, int nLength)
{
	if (nLength <= 0)
	{
		return;
	}

	char *strBuf = (char *)malloc(nLength + 1);
	memset(strBuf, 0, nLength + 1);
	memcpy(strBuf, pStart, nLength);

	//printf("本次分析的串内容\n%s\n", strBuf);
	char *p = strstr(strBuf, "<objecttype>");
	if (NULL != p)
	{
		p = p + strlen("<objecttype>");

		char *q = strchr(p, '<');
		string obType;
		obType.assign(p, q - p);
		if (0 == obType.compare("cabinet"))
		{
			xml_cabinet(strBuf);
		}
		else if (0 == obType.compare("storagecell"))
		{
			xml_storagecell(strBuf);
		}
		else if (0 == obType.compare("controller"))
		{
			xml_controller(strBuf);
		}
		else if (0 == obType.compare("disk"))
		{
			xml_disk(strBuf);
		}
		else if (0 == obType.compare("diskshelf"))
		{
			xml_diskshelf(strBuf);
		}
		else if (0 == obType.compare("virtualdisk"))
		{
			xml_virtualdisk(strBuf);
		}
		else if (0 == obType.compare("virtualdiskfolder"))
		{
			xml_virtualdiskfolder(strBuf);
		}
		else if (0 == obType.compare("virtualdiskfamilyfolder"))
		{
			xml_virtualdiskfamilyfolder(strBuf);
		}
		else if (0 == obType.compare("hostfolder"))
		{
			xml_hostfolder(strBuf);
		}
		else if (0 == obType.compare("diskgrouprootfolder"))
		{
			xml_diskgrouprootfolder(strBuf);
		}
		else if (0 == obType.compare("diskgroupfolder"))
		{
			xml_diskgroupfolder(strBuf);
		}
		else if (0 == obType.compare("drmgroupfolder"))
		{
			xml_drmgroupfolder(strBuf);
		}
		else if (0 == obType.compare("hardwarerootfolder"))
		{
			xml_hardwarerootfolder(strBuf);
		}
		else if (0 == obType.compare("host"))
		{
			xml_host(strBuf);
		}
		else if (0 == obType.compare("presentedunit"))
		{
			xml_presentedunit(strBuf);
		}
	}

	free(strBuf);
}

void CSANCaptureThread::xml_cabinet(char *pBuffer)
{
	map<string, string> ob;
	getStrValue(pBuffer, "<objectname>", "objectname", ob);
	getStrValue(pBuffer, "<objecttype>", "objecttype", ob);
	getStrValue(pBuffer, "<operationalstate>", "operationalstate", ob);
	getStrValue(
		pBuffer,
		"<operationalstatedetail>",
		"operationalstatedetail",
		ob);
	getStrValue(pBuffer, "<nbcontrollershelves>", "nbcontrollershelves", ob);
	getStrValue(pBuffer, "<nbdiskshelves>", "nbdiskshelves", ob);
	getStrValue(pBuffer, "<nbdisks>", "nbdisks", ob);
	list_cabinet.push_back(ob);
}

void CSANCaptureThread::xml_storagecell(char *pBuffer)
{
	map<string, string> ob;
	getStrValue(pBuffer, "<objectname>", "objectname", ob);
	getStrValue(pBuffer, "<objecttype>", "objecttype", ob);
	getStrValue(
		pBuffer,
		"<storagesystemcontrollermemory>",
		"storagesystemcontrollermemory",
		ob);
	getStrValue(
		pBuffer,
		"<storagesystemcontrollercachememory>",
		"storagesystemcontrollercachememory",
		ob);
	getStrValue(pBuffer, "<operationalstate>", "operationalstate", ob);
	getStrValue(
		pBuffer,
		"<operationalstatedetail>",
		"operationalstatedetail",
		ob);
	getStrValue(pBuffer, "<systemtype>", "systemtype", ob);
	getStrValue(pBuffer, "<totalstoragespace>", "totalstoragespace", ob);
	getStrValue(pBuffer, "<usedstoragespace>", "usedstoragespace", ob);
	getStrValue(
		pBuffer,
		"<availablestoragespace>",
		"availablestoragespace",
		ob);
	getStrValue(pBuffer, "<basiclicensed>", "basiclicensed", ob);
	getStrValue(pBuffer, "<drmlicensed>", "drmlicensed", ob);
	getStrValue(pBuffer, "<snaplicensed>", "snaplicensed", ob);
	list_storagecell.push_back(ob);
}

void CSANCaptureThread::xml_controller(char *pBuffer)
{
	map<string, string> ob;
	getStrValue(pBuffer, "<objectname>", "objectname", ob);
	getStrValue(pBuffer, "<objecttype>", "objecttype", ob);
	getStrValue(pBuffer, "<controllername>", "controllername", ob);
	getStrValue(pBuffer, "<operationalstate>", "operationalstate", ob);
	getStrValue(
		pBuffer,
		"<operationalstatedetail>",
		"operationalstatedetail",
		ob);
	getStrValue(pBuffer, "<datablocksize>", "datablocksize", ob);
	getStrValue(pBuffer, "<scellparticipation>", "scellparticipation", ob);
	getStrValue(pBuffer, "<nsccondition>", "nsccondition", ob);
	getStrValue(pBuffer, "<controllermainmemory>", "controllermainmemory", ob);
	getStrValue(
		pBuffer,
		"<controllertemperaturestatus>",
		"controllertemperaturestatus",
		ob);
	getStrValue(pBuffer, "<shelfnumber>", "shelfnumber", ob);
	getMultiCodeStrValue(
		pBuffer,
		"<hostport>",
		"</hostport>",
		"<portname>",
		"<operationalstate>",
		ob);
	getMultiCodeStrValue(
		pBuffer,
		"<deviceport>",
		"</deviceport>",
		"<portname>",
		"<operationalstate>",
		ob);
	getMultiCodeStrValue(
		pBuffer,
		"<fan>",
		"</fan>",
		"<fanname>",
		"<status>",
		ob);
	getMultiCodeStrValue(
		pBuffer,
		"<source>",
		"</source>",
		"<type>",
		"<state>",
		ob);
	getMultiCodeStrValue(
		pBuffer,
		"<module>",
		"</module>",
		"<name>",
		"<operationalstate>",
		ob);
	list_controller.push_back(ob);
}

void CSANCaptureThread::xml_disk(char *pBuffer)
{
	map<string, string> ob;
	getStrValue(pBuffer, "<objectname>", "objectname", ob);
	getStrValue(pBuffer, "<objecttype>", "objecttype", ob);
	getStrValue(pBuffer, "<diskname>", "diskname", ob);
	getStrValue(pBuffer, "<operationalstate>", "operationalstate", ob);
	getStrValue(
		pBuffer,
		"<operationalstatedetail>",
		"operationalstatedetail",
		ob);
	getStrValue(pBuffer, "<diskdrivetype>", "diskdrivetype", ob);
	getStrValue(pBuffer, "<failurepredicted>", "failurepredicted", ob);
	getStrValue(pBuffer, "<diskgroupname>", "diskgroupname", ob);
	getStrValue(pBuffer, "<diskbaynumber>", "diskbaynumber", ob);
	getStrValue(pBuffer, "<shelfnumber>", "shelfnumber", ob);

	// Added by Henchi, 20100303
	getMultiCodeStrValue(
		pBuffer,
		"<loop>",
		"</loop>",
		"<loopname>",
		"<loopstate>",
		ob);
	list_disk.push_back(ob);
}

void CSANCaptureThread::xml_diskshelf(char *pBuffer)
{
	map<string, string> ob;
	map<string, string> powersupply;

	// Added by Henchi, 20100303
		/// 取diskshelf信息，包含diskshelf状态及led状态
	getStrValue(pBuffer, "<objectname>", "objectname", ob);
	getStrValue(pBuffer, "<objecttype>", "objecttype", ob);
	getMultiPropStrValue(
		pBuffer,
		"<led>",
		"</led>",
		"ledstate",
		"<operationalstate>",
		ob);
	getStrValue(pBuffer, "<diskshelfname>", "diskshelfname", ob);
	getStrValue(pBuffer, "<operationalstate>", "operationalstate", ob);
	getStrValue(pBuffer, "<shelfnumber>", "shelfnumber", ob);
	getMultiCodeStrValue(
		pBuffer,
		"<powersupply>",
		"</powersupply>",
		"<name>",
		"<operationalstate>",
		ob);
	getMultiCodeStrValue(
		pBuffer,
		"<port>",
		"</port>",
		"<name>",
		"<operationalstate>",
		ob);
	getMultiCodeStrValue(
		pBuffer,
		"<module>",
		"</module>",
		"<name>",
		"<operationalstate>",
		ob);
	getMultiCodeStrValue(
		pBuffer,
		"<fan>",
		"</fan>",
		"<name>",
		"<operationalstate>",
		ob);
	list_diskshelf.push_back(ob);

	// Mod by Henchi, 20100303
		/// powersupply信息保持独立
	getStrValue(pBuffer, "<shelfnumber>", "shelfnumber", powersupply);

	char *p = strstr(pBuffer, "<powersupply>");
	while (NULL != p)
	{
		xml_powersupply(p, powersupply);
		p = strstr(p + strlen("<powersupply>"), "<powersupply>");
		list_powersupply.push_back(powersupply);
	}

	//#if 0
	//	map<string, string> ob;
	//	list_diskshelf.push_back(ob);
	//#endif
}

void CSANCaptureThread::xml_powersupply(char *pBuffer, map<string, string> &ob)
{
	getStrValue(pBuffer, "<name>", "name", ob);
	getStrValue(pBuffer, "<operationalstate>", "operationalstate", ob);
	getStrValue(pBuffer, "<outputlink>", "outputlink", ob);
	getStrValue(pBuffer, "<inputlink>", "inputlink", ob);
	getStrValue(pBuffer, "<state>", "state", ob);
}

void CSANCaptureThread::xml_virtualdisk(char *pBuffer)
{
	map<string, string> ob;
	getStrValue(pBuffer, "<objectname>", "objectname", ob);
	getStrValue(pBuffer, "<objecttype>", "objecttype", ob);
	getStrValue(pBuffer, "<partitionname>", "partitionname", ob);
	getStrValue(pBuffer, "<creationdatetime>", "creationdatetime", ob);
	getStrValue(pBuffer, "<familyname>", "familyname", ob);
	getStrValue(pBuffer, "<operationalstate>", "operationalstate", ob);
	getStrValue(
		pBuffer,
		"<operationalstatedetail>",
		"operationalstatedetail",
		ob);
	getStrValue(pBuffer, "<allocatedcapacity>", "allocatedcapacity", ob);
	getStrValue(
		pBuffer,
		"<allocatedcapacityblocks>",
		"allocatedcapacityblocks",
		ob);
	getStrValue(pBuffer, "<virtualdisktype>", "virtualdisktype", ob);
	getStrValue(pBuffer, "<requestedcapacity>", "requestedcapacity", ob);
	getStrValue(
		pBuffer,
		"<requestedcapacityblocks>",
		"requestedcapacityblocks",
		ob);
	getStrValue(pBuffer, "<redundancy>", "redundancy", ob);
	getStrValue(pBuffer, "<diskgroupname>", "diskgroupname", ob);
	getStrValue(pBuffer, "<hostaccess>", "hostaccess", ob);
	getStrValue(pBuffer, "<preferredpath>", "preferredpath", ob);
	getMultiStrValue(pBuffer, "<hostname>", "hostname", ob);
	list_virtualdisk.push_back(ob);
}

void CSANCaptureThread::xml_virtualdiskfolder(char *pBuffer)
{
	map<string, string> ob;
	getStrValue(pBuffer, "<objectname>", "objectname", ob);
	getStrValue(pBuffer, "<objecttype>", "objecttype", ob);
	getStrValue(pBuffer, "<operationalstate>", "operationalstate", ob);
	getStrValue(
		pBuffer,
		"<operationalstatedetail>",
		"operationalstatedetail",
		ob);
	list_virtualdiskfolder.push_back(ob);
}

void CSANCaptureThread::xml_virtualdiskfamilyfolder(char *pBuffer)
{
	map<string, string> ob;
	getStrValue(pBuffer, "<objectname>", "objectname", ob);
	getStrValue(pBuffer, "<objecttype>", "objecttype", ob);
	getStrValue(pBuffer, "<familyname>", "familyname", ob);
	getStrValue(pBuffer, "<operationalstate>", "operationalstate", ob);
	getStrValue(
		pBuffer,
		"<operationalstatedetail>",
		"operationalstatedetail",
		ob);
	getStrValue(pBuffer, "<puexist>", "puexist", ob);
	getStrValue(pBuffer, "<sharingrel>", "sharingrel", ob);
	list_virtualdiskfamilyfolder.push_back(ob);
}

void CSANCaptureThread::xml_hostfolder(char *pBuffer)
{
#if 0
	map<string, string> ob;
	list_hostfolder.push_back(ob);
#endif
}

void CSANCaptureThread::xml_diskgrouprootfolder(char *pBuffer)
{
#if 0
	map<string, string> ob;
	list_diskgrouprootfolder.push_back(ob);
#endif
}

void CSANCaptureThread::xml_diskgroupfolder(char *pBuffer)
{
#if 0
	map<string, string> ob;
	list_diskgroupfolder.push_back(ob);
#endif
}

void CSANCaptureThread::xml_drmgroupfolder(char *pBuffer)
{
#if 0
	map<string, string> ob;
	list_drmgroupfolder.push_back(ob);
#endif
}

void CSANCaptureThread::xml_hardwarerootfolder(char *pBuffer)
{
#if 0
	map<string, string> ob;
	list_hardwarerootfolder.push_back(ob);
#endif
}

void CSANCaptureThread::xml_host(char *pBuffer)
{
	map<string, string> ob;
	getStrValue(pBuffer, "<objectname>", "objectname", ob);
	getStrValue(pBuffer, "<objecttype>", "objecttype", ob);
	getStrValue(pBuffer, "<hostname>", "hostname", ob);
	getStrValue(pBuffer, "<hosttype>", "hosttype", ob);
	getStrValue(pBuffer, "<ipaddress>", "ipaddress", ob);
	getStrValue(pBuffer, "<operationalstate>", "operationalstate", ob);
	getStrValue(
		pBuffer,
		"<operationalstatedetail>",
		"operationalstatedetail",
		ob);
	getStrValue(pBuffer, "<osmode>", "osmode", ob);
	getMultiStrValue(pBuffer, "<virtualdiskname>", "virtualdiskname", ob);
	list_host.push_back(ob);
}

void CSANCaptureThread::xml_presentedunit(char *pBuffer)
{
#if 0
	map<string, string> ob;
	list_presentedunit.push_back(ob);
#endif
}

BOOL CSANCaptureThread::CreateChildProcess(const char *pCommand)
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

VOID CSANCaptureThread::ReadFromPipe(const char *pCommand)
{
	DWORD dwRead, dwWritten;
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

VOID CSANCaptureThread::ErrorExit(LPTSTR lpszMessage, const char *pCommand)
{
	m_strReuslt.clear();
	fprintf(stderr, "命令：[%s] 错误消息：[%s]\n", pCommand, lpszMessage);

	//ExitProcess(0);
}

VOID CSANCaptureThread::SANCapture(const char *pCommand)
{
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
