#include "CSysLogReader.h"
#include "PrjCommon.h"
#include "CProbe.h"
#include "configmanager.h"

#define  READFILEINTERVAL   60
#define  SIZE_BUF			4096

extern int g_nWorkFlag;	
extern STORE_DATA_MAP g_mAppAttrInfo;
extern CMutex g_mWorkFlagMutex;

CMutex g_mSyslogMutex;

CSysLogRecord::CSysLogRecord()
{
	time_t timer; 
	time(&timer); 
	tm* t_tm = localtime(&timer); 

 	char year[10] = {0};
	sprintf(year, "%d", t_tm->tm_year+1900);

	strYear = year;
	bValidFlag = false;

	m_mapMonthStr["Jan"] = "01";
	m_mapMonthStr["Feb"] = "02";
	m_mapMonthStr["Mar"] = "03";
	m_mapMonthStr["Apr"] = "04";
	m_mapMonthStr["May"] = "05";
	m_mapMonthStr["Jun"] = "06";
	m_mapMonthStr["Jul"] = "07";
	m_mapMonthStr["Aug"] = "08";
	m_mapMonthStr["Sep"] = "09";
	m_mapMonthStr["Oct"] = "10";
	m_mapMonthStr["Nov"] = "11";
	m_mapMonthStr["Dec"] = "12";	
}

CSysLogRecord::CSysLogRecord(char szYear)
{
	strYear = szYear;
	bValidFlag = false;

	m_mapMonthStr["Jan"] = "01";
	m_mapMonthStr["Feb"] = "02";
	m_mapMonthStr["Mar"] = "03";
	m_mapMonthStr["Apr"] = "04";
	m_mapMonthStr["May"] = "05";
	m_mapMonthStr["Jun"] = "06";
	m_mapMonthStr["Jul"] = "07";
	m_mapMonthStr["Aug"] = "08";
	m_mapMonthStr["Sep"] = "09";
	m_mapMonthStr["Oct"] = "10";
	m_mapMonthStr["Nov"] = "11";
	m_mapMonthStr["Dec"] = "12";	
}

CSysLogRecord::~CSysLogRecord()
{
}

void CSysLogRecord::Reset()
{
	bValidFlag = true;
}

string CSysLogRecord::GetDateString(char *pszMonth, char *pszDay)
{
	/// Mod by Henchi, 20111208
	/// 修正日期码为个位数时可能出现的异常
	string Day = strlen(pszDay) == 1 ? string("0") + string(pszDay) : pszDay;
	string Date = strYear + string(m_mapMonthStr[pszMonth]) + Day;
	return Date;
}

bool CSysLogRecord::IsValidRec(string record)
{
	///Mar 30 00:00:50 hostname appname appnum[xxxx]: AttrName AttrValue
	char *pRec = (char *)record.data();
	if (pRec[3] == ' ' && pRec[6] == ' ' && pRec[9] == ':' && pRec[12] == ':' && pRec[15] == ' ')
	{
		return true;
	}
	else
	{
		bValidFlag = false;
		return false;
	}
}

bool CSysLogRecord::LoadRec(string record)
{
	//Mar 30 00:00:50 hostname appname appnum[xxxx]: AttrName AttrValue
	if (IsValidRec(record))
	{
		char szMonth[16], szDay[16], szTime[16], szHostname[64];
		char szAppName[100], szAppNum[16], szAttrName[100], szAttrValue[4096]; 
		
		int iRtn = sscanf(record.c_str(), "%[A-Za-z] %[0-9] %[0-9:] %s %s %s %s %[^\n]\n",
				szMonth, szDay, szTime, szHostname, szAppName, szAppNum, szAttrName, szAttrValue);
		
		if (iRtn == 8)
		{
			//指标值不能包含空格
			if(strstr(szAttrValue, " "))
			{
				//关闭日志event导致的错误输出
				if(strAttrName.compare("event") != 0)
				{
					printf("Get Invalid AttrValue record:[%s]\n", record.c_str());
				}
				
				bValidFlag = false;
				return false;
			}
			
			if (strlen(szTime) == 7 && szTime[1] == ':')
			{
				sprintf(szTime, "0%s", szTime);
			}
			else
			{
				strTime = szTime;
			}

			strDate = GetDateString(szMonth, szDay);			
			strHost = szHostname;
			strAttrName = szAttrName;
			strAttrValue = szAttrValue;
			strAppName = szAppName;
			
			int appnum = atoi(szAppNum);
			char numstr[100];
			SNPRINTF(numstr, sizeof(numstr), "%d", appnum);
			strAppNum = numstr;
			
			bValidFlag = true;
			return true;
		}
	}

	printf("Get Invalid record:[%s]\n", record.c_str());
	bValidFlag = false;
	return false;
}

CSysLogReader::CSysLogReader()
{
	m_strFilePath = "";
	m_lReadPos  = 0;
	m_pFile = NULL;
	m_iValidFlag = READFILEINTERVAL;
	m_tModify = 0;
	m_tLastLoadTime = 0;
}

CSysLogReader::CSysLogReader(string strFilePath)
{
	m_strFilePath = strFilePath;
	m_lReadPos  = 0;
	m_pFile = NULL;
	m_iValidFlag = READFILEINTERVAL;
	m_tModify = 0;
	m_iReadTime = 0;
}

CSysLogReader::CSysLogReader(string strFilePath, long lReads)
{
	m_strFilePath = strFilePath;
	m_lReadPos  = lReads;
	m_pFile = NULL;
	m_iValidFlag = READFILEINTERVAL;
	m_tModify = 0;
	m_iReadTime = 0;
}

CSysLogReader::CSysLogReader(string strFilePath, long lReads, int iReadTime)
{
	m_strFilePath = strFilePath;
	m_lReadPos  = lReads;
	m_pFile = NULL;
	m_iValidFlag = READFILEINTERVAL;
	m_tModify = 0;
	m_iReadTime = iReadTime;
}

CSysLogReader::~CSysLogReader()
{

}

bool CSysLogReader::InitInstance()
{
	return true;
}

void CSysLogReader::ExitInstance()
{

}

void CSysLogReader::Run()
{
	while (1)
	{
		g_mWorkFlagMutex.Lock();	
		
		if(g_nWorkFlag == 1)
		{
			//当WorkFlag变为1时检索当前时刻位置开始持续读取
			KeepReadFile();
		}
		else if(g_nWorkFlag > 1)
		{
			//当WorkFlag为2时重置日志读取状态
			if(m_pFile)		
			{
				SAFE_FCLOSE(m_pFile);
			}
			
			m_iValidFlag = READFILEINTERVAL; 
			m_lReadPos = 0 ;
			m_tModify = 0;
			m_tLastLoadTime = 0;
		}

		g_mWorkFlagMutex.UnLock();

#ifdef WIN32
		SLEEP(1000);
#else
		sleep(1);
#endif
	}
}

bool CSysLogReader::OpenFile()
{
	if (m_strFilePath.length() == 0)
	{
		return false;
	}
	else
	{
		if((m_pFile = fopen(m_strFilePath.c_str(),"r")) == NULL)
		{
			printf("open file %s fail!\n", m_strFilePath.c_str());
			m_bReadFlag = false;
			m_iValidFlag = 0;
			return false;
		}

		/// 检索读取位置


		/// 从当前时间开始分析
		time_t tNow;
		time(&tNow);
		
		char szDatetime[100];
		strftime(szDatetime, sizeof(szDatetime), "%b %d %H:%M:%S", (const tm *)localtime(&tNow));

		//DateStringToLong用到共享变量同时读写，需要互斥
		g_mSyslogMutex.Lock();
		int iToday = CFileRecordFinder::DateStringToLong(szDatetime);
		g_mSyslogMutex.UnLock();
		
		m_iReadTime = m_iReadTime >= iToday ? m_iReadTime : iToday;
		CFileRecordFinder finder(m_pFile);
		finder.init();
		
		m_tModify = finder.m_modtime;

		if ( m_lReadPos > 0 && m_lReadPos == finder.m_size && m_iReadTime == finder.m_lLast)
		{
			/// 文件已经读取到当前最末位置,且已发送过主机ID与业务对象ID的关系
			m_iReadTime = finder.m_modtime;
			return true;
		}
		off_t nPos = finder.Search(m_iReadTime);
		m_lReadPos = nPos < 0 ? 0 : nPos;

		if(fseek(m_pFile, m_lReadPos, SEEK_SET) < 0)
		{
			printf("FileName %s lseek error\n",m_strFilePath.c_str());
			fflush(stdout);	
			SAFE_FCLOSE(m_pFile);
			m_pFile = NULL;
			m_iValidFlag = READFILEINTERVAL;
			return false;
		}
		return true;
	}
}

void CSysLogReader::KeepReadFile()
{
	struct stat filestat;

	if(m_pFile==NULL)
	{
		m_iValidFlag++;	
		if (m_iValidFlag >= READFILEINTERVAL)
		{
			if (!OpenFile())
				return;
		}
		else
			return;
	}
	
	int iRtn = stat(m_strFilePath.c_str(),&filestat);

	if(iRtn < 0) ///stat文件失败，意味着该文件在打开过程中被删除，返回
	{
		printf("\tFileName %s stat error\n",m_strFilePath.c_str());
		fflush(stdout);
		SAFE_FCLOSE(m_pFile);
		m_iValidFlag = READFILEINTERVAL; ///stat失败后，下一次就立即尝试文件是否存在
		m_lReadPos = 0 ;
		return;
	} 
	else if (filestat.st_size <= m_lReadPos)
	{
		if (m_tModify < filestat.st_mtime) // 该文件可能被删除过内容，重新打开
		{
			SAFE_FCLOSE(m_pFile);
			m_lReadPos = 0 ;
			return;
		}
	} 
	else if(filestat.st_size > m_lReadPos)
	{
		if (fseek(m_pFile, m_lReadPos,SEEK_SET) < 0)
		{
			printf("FileName %s lseek error\n",m_strFilePath.c_str());
			fflush(stdout);	
			SAFE_FCLOSE(m_pFile);
			m_iValidFlag = READFILEINTERVAL;
			return;
		}

		m_tModify = filestat.st_mtime;

		int iLines = 0;
		char szBuf[SIZE_BUF];

		time_t starttime= time(NULL);

		CSysLogRecord Rec;
		memset(szBuf, 0x00, sizeof(szBuf));
		while ((fgets(szBuf, sizeof(szBuf)-1, m_pFile))!=NULL)
		{
			iLines++;

			if (Rec.LoadRec(string(szBuf)))
			{
				g_mWorkFlagMutex.Lock();	
				
				if(g_nWorkFlag == 1)
				{
					//保存应用的指标信息
					SaveAppAttrInfo(Rec);
				}

				g_mWorkFlagMutex.UnLock();		
			}
			
			memset(szBuf, 0x00, sizeof(szBuf));
		}

		m_lReadPos = ftell(m_pFile);
		
#ifdef PRINT_DEBUG		
		int timeused = (int)(time(NULL) - starttime);
		if(timeused)
		{		
			printf("lines:%d, time used %ds, timerate=%f ms per line, linerate=%f line per s\n", iLines, timeused, 1000*(float)timeused/iLines, (float)iLines/timeused);
		}
		printf("file parse over\n");
#endif
		m_bReadFlag = false;
	} 
	else
	{
		m_bReadFlag = false;
	}
}

void CSysLogReader::SaveAppAttrInfo(CSysLogRecord& Rec)
{
	map<string, map<string, int> >::iterator a_it = CConfigManager::Instance()->m_mAppAttrList.find(Rec.strAppName);
	if(a_it == CConfigManager::Instance()->m_mAppAttrList.end())
	{
		printf("impossible, no app:%s found from appattrlist\n", Rec.strAppName.c_str());
		return;
	}

	map<string, int>::iterator aa_it = a_it->second.find(Rec.strAttrName);
	if(aa_it == a_it->second.end())
	{
		//没有配置该指标,不采集
#ifdef PRINT_DEBUG
		printf("Attr:%s not configured in probe.xml\n", Rec.strAttrName.c_str());
#endif		
		return;
	}
	
	char szDatetime[100] = {0};
	SNPRINTF(szDatetime, sizeof(szDatetime), "%s", Rec.strTime.c_str());
	
	char keystr[1024] = {0};
	SNPRINTF(keystr, sizeof(keystr), "app.%s.%s.%s", Rec.strAppName.c_str(), Rec.strAppNum.c_str(), Rec.strAttrName.c_str());

	STORE_DATA_ITERATOR s_it = g_mAppAttrInfo.find(keystr);
	if(s_it == g_mAppAttrInfo.end())
	{
		map<string, string> attrmap;
		attrmap[szDatetime] = Rec.strAttrValue;

		g_mAppAttrInfo[keystr] = attrmap;
	}
	else
	{
		s_it->second[szDatetime] = Rec.strAttrValue;
	}
}

