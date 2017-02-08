///////////////////////////////////////////////////////////////////////////////////////
//slogparser.cpp
//
//20071226 赵鸿昊	增加使用-a参数，输出OFP报单的请求/应答时间
//20080109 赵鸿昊	1.增加-e参数，指定错误输出文件
//					2.修改-a参数，可以指定输出RTT不合要求的报单请求/应答
//					3.报单请求应答匹配改为四个字段，增加了LocalID序号和会话号，以避免
//					  LocalID重复及基于会员的MBack
//					4.修改Reactor读操作的驱动模式，不再遍历IOList，改由CSlogConnection
//					  直接驱动，速度可以提高几十倍
//20080110 赵鸿昊	1.增加对FTD协议的支持
//					2.RTT分析支持-f模式
#include "slogparser.h"
#include "systools.h"
#include "Semaphore.h"

CSemaphore g_semThread;
extern char g_szDateBuffer[10]; 

extern char g_mFlowPath[200];
extern bool g_bAnalysisRTT;
extern char g_szTimeBuffer[10];
extern map<string, int> g_mapSlogFileName;
extern CStringIdMap g_mStringIdMap;

extern CPackageFilter g_PackageFilter;

///=== 20110907 by zhou.jj
extern int	g_newSlogFlag[COUNT_NEW_SLOG_FLAG];

/// 20110907 by zhou.jj
extern CDataCenterManage *g_pDataCenterManage;		// 数据中心管理器
//////////////////////////////////////////////////////////////////////////
//add by feng.q
//key frontid
//value file status, 整合文件指针和m_cWrongFlag
//   1. no file, 2, file open error  3. 正常， 4. 异常（m_cWrongFlag被置1） 5. 文件头不匹配
map<int, int> m_mapSlogFileReadStatus;
#define USE_FRONT_MAP 0
//////////////////////////////////////////////////////////////////////////
CSlogDescript::CSlogDescript(void)
{
	m_fpSlog = NULL;
	m_strSlogFileName = "";
	m_strDesiredIpAddress = "all";
	memset(&m_header, 0, sizeof(m_header));
	m_nReadLen = 0;
	m_bFollow = DEFAULT_FOLLOW;
	FPOS_SET(m_fposLog, 0);
	m_tLastTime = 0;
	m_nFrontID = 0;
	m_nFileID = 0;
	m_cVersion = 0;
	m_cWrongFlag = 0;
	newFileFlag = 0;
}

///构造函数
///@param	pszSlogFileName	SLog文件名字
///@param	nSlogFileNameId	文件名的唯一ID编号
CSlogDescript::CSlogDescript(
	const char	*pszSlogFileName,
	const int nSlogFileNameId)
{
	m_fpSlog = NULL;
	m_strSlogFileName = g_mFlowPath;
	m_strSlogFileName.append(pszSlogFileName);
	m_strDesiredIpAddress = "all";
	memset(&m_header, 0, sizeof(m_header));
	m_nReadLen = 0;
	m_bFollow = DEFAULT_FOLLOW;
	FPOS_SET(m_fposLog, 0);
	m_tLastTime = 0;
	
	// 考虑到双交易系统情况，对FrontID重新做个映射

	if (USE_FRONT_MAP)
	{	
		string str_file_name(pszSlogFileName);
		int nFrontID = getIDFrontMap(str_file_name);
		if (-1!=nFrontID)
		{
			m_nFrontID = nFrontID;
		}
		else
		{
			m_nFrontID = atoi(pszSlogFileName); 
		}
	}
	else
	{
		m_nFrontID = atoi(pszSlogFileName); 
	}
	
	m_nFileID = nSlogFileNameId;	///
	char *p = (char *)strstr(pszSlogFileName, "ofp");
	if (p == NULL)
	{
		m_cVersion = 0;
	}
	else
	{
		p = p + 3;
		if (*p == '2')
		{
			m_cVersion = 2;
		}
		else
		{
			m_cVersion = 1;
		}
	}

	m_cVersion = 0;
	m_cWrongFlag = 0;

	///=== 20110907 by zhou.jj
	newFileFlag = 0;
	p = (char *)pszSlogFileName;
	while (p != NULL && (!isdigit(*p)))
	{
		p++;
	}

	if (p != NULL)
	{
		newFileFlag = g_newSlogFlag[atoi(p)];
	}

	/// 20110907 by zhou.jj
}

///构造函数
///@param	nDataCenterId	Slog文件归属数据中心ID编号
///@param	pszSlogFileName	SLog文件名字
///@param	nSlogFileNameId	文件名的唯一ID编号
CSlogDescript::CSlogDescript(
	const int nDataCenterId,
	const char	*pszSlogFileName,
	const int nSlogFileNameId)
{
	newFileFlag = 0;
	m_fpSlog = NULL;
	m_strSlogFileName = g_mFlowPath;
	m_strSlogFileName.append(pszSlogFileName);
	m_strDesiredIpAddress = "all";
	memset(&m_header, 0, sizeof(m_header));
	m_nReadLen = 0;
	m_bFollow = DEFAULT_FOLLOW;
	FPOS_SET(m_fposLog, 0);
	m_tLastTime = 0;
	m_nFrontID = atoi(pszSlogFileName) + nDataCenterId * 32;
	m_nFileID = nSlogFileNameId;	///
	char *p = (char *)strstr(pszSlogFileName, "ofp");
	if (p == NULL)
	{
		m_cVersion = 0;
	}
	else
	{
		p = p + 3;
		if (*p == '2')
		{
			m_cVersion = 2;
		}
		else
		{
			m_cVersion = 1;
		}
	}

	m_cVersion = 0;
	m_cWrongFlag = 0;
}

///构造函数
///@param	nDataCenterId	Slog文件归属数据中心ID编号
///@param	pszSlogFileName	SLog文件名字
///@param	nSlogFileNameId	文件名的唯一ID编号
///@param	pszDesiredIpAddress	过滤的ip地址
CSlogDescript::CSlogDescript(
	const int nDataCenterId,
	const char	*pszSlogFileName,
	const int nSlogFileNameId,
	const char	*pszDesiredIpAddress)
{
	newFileFlag = 0;
	m_fpSlog = NULL;
	m_strSlogFileName = g_mFlowPath;
	m_strSlogFileName.append(pszSlogFileName);
	m_strDesiredIpAddress = pszSlogFileName;
	memset(&m_header, 0, sizeof(m_header));
	m_nReadLen = 0;
	m_bFollow = DEFAULT_FOLLOW;
	FPOS_SET(m_fposLog, 0);
	m_tLastTime = 0;
	m_nFrontID = atoi(pszSlogFileName) + nDataCenterId * 32;
	m_nFileID = nSlogFileNameId;	///
	char *p = (char *)strstr(pszSlogFileName, "ofp");
	if (p == NULL)
	{
		m_cVersion = 0;
	}
	else
	{
		p = p + 3;
		if (*p == '2')
		{
			m_cVersion = 2;
		}
		else
		{
			m_cVersion = 1;
		}
	}

	m_cVersion = 0;
	m_cWrongFlag = 0;
}

///构造函数
///@param	nDataCenterId	Slog文件归属数据中心ID编号
///@param	pszSlogFileName	SLog文件名字
///@param	nSlogFileNameId	文件名的唯一ID编号
///@param	pszDesiredIpAddress	过滤的ip地址
///@param	bFollow	持续读取文件标记
CSlogDescript::CSlogDescript(
	const int nDataCenterId,
	const char	*pszSlogFileName,
	const int nSlogFileNameId,
	const char	*pszDesiredIpAddress,
	bool bFollow)
{
	newFileFlag = 0;
	m_fpSlog = NULL;
	m_strSlogFileName = g_mFlowPath;
	m_strSlogFileName.append(pszSlogFileName);
	m_strDesiredIpAddress = pszDesiredIpAddress;
	memset(&m_header, 0, sizeof(m_header));
	m_nReadLen = 0;
	m_bFollow = bFollow;
	FPOS_SET(m_fposLog, 0);
	m_tLastTime = 0;
	m_nFrontID = atoi(pszSlogFileName) + nDataCenterId * 32;
	m_nFileID = nSlogFileNameId;	///
	char *p = (char *)strstr(pszSlogFileName, "ofp");
	if (p == NULL)
	{
		m_cVersion = 0;
	}
	else
	{
		p = p + 3;
		if (*p == '2')
		{
			m_cVersion = 2;
		}
		else
		{
			m_cVersion = 1;
		}
	}

	m_cVersion = 0;
	m_cWrongFlag = 0;
}


int CSlogDescript::getIDFrontMap(string str_slog_file_name)
{
	int result_value(-1);
	// 首先获取映射字符串
	int find_sign_count(0);
	while(1)
	{
		string::size_type find_pos(str_slog_file_name.find('.'));
		if (string::npos!=find_pos)
		{
			if (++find_sign_count<3)
			{
				str_slog_file_name = str_slog_file_name.substr(find_pos+1);
			}
			else
				break;
		}
		else
			break;
	}
	string::size_type find_tail(str_slog_file_name.find('_'));
	if (string::npos!=find_tail)
	{
		str_slog_file_name = str_slog_file_name.substr(0, find_tail);
	}
	string::size_type find_front_index(str_slog_file_name.find_last_of('.'));
	if (string::npos!=find_front_index)
	{
		string str_sub_string(str_slog_file_name.substr(find_front_index+1));
		string::size_type find_front_pos(str_sub_string.find("front"));
		if (find_front_pos!=string::npos)
		{
			str_slog_file_name = str_slog_file_name.substr(0, find_front_index+1);
			str_slog_file_name += "front." + str_sub_string.substr(find_front_pos+5);
		}
	}
	string::size_type find_insert_app(str_slog_file_name.find("front"));
	if (string::npos!=find_insert_app)
	{
		str_slog_file_name = str_slog_file_name.substr(0,find_insert_app)+"app."+str_slog_file_name.substr(find_insert_app);
	}
	
	map<int, string>& mapFrontID = g_pDataCenterManage->getFrontUniqueID();
	for (map<int, string>::iterator iterFrontID=mapFrontID.begin(); iterFrontID!=mapFrontID.end(); ++iterFrontID)
	{
		if (iterFrontID->second==str_slog_file_name)
		{
			result_value = iterFrontID->first;
			break;
		}
	}
	
	return result_value;
}
CSlogReactor::~CSlogReactor(void)
{
	Clear();
}

void CSlogReactor::GetSlogFileStatus(int nFrontID, char *pLogBuf)
{
	map<string, CSlogDescript>::iterator m_Iter;

	for (m_Iter = m_mapSlogDescript.begin();
		 m_Iter != m_mapSlogDescript.end();
		 m_Iter++)
	{
		if (m_Iter->second.m_nFrontID == nFrontID
		&&	m_Iter->second.m_fpSlog
		&&	pLogBuf)
		{
			QWORD mFposLong = FPOS_GET(m_Iter->second.m_fposLog);
			time_t lTime = m_Iter->second.m_tLastTime;
			struct tm tm_time;
			LocalTime(&lTime, &tm_time);
			char currtime[16];
			strftime(
				currtime,
				sizeof(currtime),
				"%H:%M:%S",
				&tm_time);

			sprintf(
				pLogBuf,
				"pos:%lld, last:%s, flag:%d",
				mFposLong,
				currtime,
				m_Iter->second.m_cWrongFlag);
		}
	}
}

CSlogConnection *CSlogReactor::CreateSlogConnection(
	int nID,
	const char	*pszIPAddress,
	int nFrontID,
	int nFileID,
	char cVersion)
{
	if (m_mapIt->second.m_strDesiredIpAddress.compare("all") == 0
	||	m_mapIt->second.m_strDesiredIpAddress.compare(pszIPAddress) == 0)
	{
		CSlogConnection *pSlogConnection = new CSlogConnection(
				nID,
				pszIPAddress,
				nFrontID,
				nFileID,
				cVersion);
		if (!pSlogConnection->CreateSession(
				this,
			m_mapIt->second.m_strSlogFileName.c_str()))
		{
			delete pSlogConnection;
			return NULL;
		}

		m_mapIt->second.m_mapSlogConnection.Insert(nID, pSlogConnection);
		return pSlogConnection;
	}

	return NULL;
}

CSlogConnection *CSlogReactor::GetSlogConnection(int nID)
{
	CSlogConnection **pFind = m_mapIt->second.m_mapSlogConnection.Find(nID);
	return (pFind == NULL) ? NULL : *pFind;
}

bool CSlogReactor::DelSlogConnection(int nID)
{
	CSlogConnection **pFind = m_mapIt->second.m_mapSlogConnection.Find(nID);
	if (pFind == NULL)
	{
		return false;
	}

	delete *pFind;
	m_mapIt->second.m_mapSlogConnection.Erase(nID);
	return true;
}

bool CSlogReactor::ReadOne(void)
{
	if (m_mapIt->second.m_cWrongFlag != 0)
	{
		return false;
	}

	int n = 0;
	INT64 mFposLong = FPOS_GET(m_mapIt->second.m_fposLog);

	// add by zhou.jj on 20090615 预防文件中途被截断尾部，等待该文件写了一段时间后继续在读
	if (fsetpos(m_mapIt->second.m_fpSlog, &(m_mapIt->second.m_fposLog)) != 0)
	{
		printf(
			"Fatal Error in fsetpos file [%s],  in file size[%d]\n",
			m_mapIt->second.m_strSlogFileName.c_str(),
			mFposLong);
		return false;
	}

	static int	new_channel_log_header_len = sizeof(TNewChannelLogHeader);
	static int	channel_log_header_len = sizeof(TChannelLogHeader);

	//////////////////////////////////////////////////////////////////////////
	//change by feng.q, 如果一次没有读完logheader，则返回false，并不修改文件读取指针
	if (m_mapIt->second.newFileFlag)
	{
		if (m_mapIt->second.m_nReadLen < sizeof(TNewChannelLogHeader))
		{
			n = fread(
					((char *) &(m_mapIt->second.m_header)) + m_mapIt->second.m_nReadLen,
					1,
					sizeof(TNewChannelLogHeader) - m_mapIt->second.m_nReadLen,
					m_mapIt->second.m_fpSlog);

			FPOS_SET(m_mapIt->second.m_fposLog, mFposLong + n);
			m_mapIt->second.m_nReadLen += n;
			if (m_mapIt->second.m_nReadLen >= sizeof(TNewChannelLogHeader))
			{
				m_mapIt->second.m_header.ChangeEndian();
			}
		}
	}
	else
	{
		if (m_mapIt->second.m_nReadLen < sizeof(TChannelLogHeader))
		{
			n = fread(
					((char *) &(m_mapIt->second.m_header)) + m_mapIt->second.m_nReadLen,
					1,
					sizeof(TChannelLogHeader) - m_mapIt->second.m_nReadLen,
					m_mapIt->second.m_fpSlog);
			FPOS_SET(m_mapIt->second.m_fposLog, mFposLong + n);
			m_mapIt->second.m_nReadLen += n;
			if (m_mapIt->second.m_nReadLen >= sizeof(TChannelLogHeader))
			{
				m_mapIt->second.m_header.ChangeEndian();
			}
		}
	}

	if (m_mapIt->second.m_header.wLength >= MAX_SLOG_REC_LEN)
	{
		m_mapIt->second.m_cWrongFlag = 1;
		printf(
			"Fatal Error in read file [%s], TChannelLogHeader.wLength [%d] exceed max value in file size[%d]\n",
			m_mapIt->second.m_strSlogFileName.c_str(),
			m_mapIt->second.m_header.wLength,
			mFposLong);

		//////////////////////////////////////////////////////////////////////////
		//feng.q
		m_mapSlogFileReadStatus[m_mapIt->second.m_nFrontID] = 4;

		//////////////////////////////////////////////////////////////////////////
		return false;
	}

	if (m_mapIt->second.newFileFlag)
	{
		if (m_mapIt->second.m_nReadLen < sizeof(TNewChannelLogHeader))
		{
			//////////////////////////////////////////////////////////////////////////
			//feng.q
			m_mapSlogFileReadStatus[m_mapIt->second.m_nFrontID] = 5;

			//////////////////////////////////////////////////////////////////////////
			return false;
		}
	}
	else
	{
		if (m_mapIt->second.m_nReadLen < sizeof(TChannelLogHeader))
		{
			//////////////////////////////////////////////////////////////////////////
			//feng.q
			m_mapSlogFileReadStatus[m_mapIt->second.m_nFrontID] = 5;

			//////////////////////////////////////////////////////////////////////////
			return false;
		}
	}

	mFposLong = FPOS_GET(m_mapIt->second.m_fposLog);

	// add by zhou.jj on 20090615 预防文件中途被截断尾部，等待该文件写了一段时间后继续在读
	if (fsetpos(m_mapIt->second.m_fpSlog, &(m_mapIt->second.m_fposLog)) != 0)
	{
		printf(
			"Fatal Error in fsetpos file [%s],  in file size[%d]\n",
			m_mapIt->second.m_strSlogFileName.c_str(),
			mFposLong);
		return false;
	}

	if (m_mapIt->second.m_header.wLength > 0)
	{
		if (m_mapIt->second.newFileFlag)
		{
			int n = fread(
					m_mapIt->second.m_buffer +
						m_mapIt->second.m_nReadLen -
						sizeof(TNewChannelLogHeader),
					1,
					m_mapIt->second.m_header.wLength -
						m_mapIt->second.m_nReadLen +
						sizeof(TNewChannelLogHeader),
					m_mapIt->second.m_fpSlog);
			FPOS_SET(m_mapIt->second.m_fposLog, mFposLong + n);
			m_mapIt->second.m_nReadLen += n;
			if (m_mapIt->second.m_nReadLen != m_mapIt->second.m_header.
					wLength +
			sizeof(TNewChannelLogHeader))
			{
				return false;
			}
		}
		else
		{
			int n = fread(
					m_mapIt->second.m_buffer +
						m_mapIt->second.m_nReadLen -
						sizeof(TChannelLogHeader),
					1,
					m_mapIt->second.m_header.wLength -
						m_mapIt->second.m_nReadLen +
						sizeof(TChannelLogHeader),
					m_mapIt->second.m_fpSlog);
			FPOS_SET(m_mapIt->second.m_fposLog, mFposLong + n);
			m_mapIt->second.m_nReadLen += n;
			if (m_mapIt->second.m_nReadLen != m_mapIt->second.m_header.
					wLength +
			sizeof(TChannelLogHeader))
			{
				return false;
			}
		}
	}

	m_mapIt->second.m_nReadLen = 0;

	time_t	tCurrTime = m_mapIt->second.m_header.dwTime;
	struct tm tm_time;
	LocalTime(&tCurrTime, &tm_time);

	g_semThread.Lock();
	strftime(
		g_szTimeBuffer,
		sizeof(g_szTimeBuffer),
		"%H:%M:%S",
		&tm_time);
	sprintf(g_szDateBuffer,"%04d%02d%02d",tm_time.tm_year + 1900,
		tm_time.tm_mon + 1,tm_time.tm_mday);
	g_semThread.UnLock();

	if (m_mapIt->second.m_tLastTime != tCurrTime)
	{
#if 0
		printf(
			"File %s current log time : %s\n",
			m_mapIt->first.c_str(),
			g_szTimeBuffer);
		if (strcmp(g_szTimeBuffer, "15:13:27") == 0)
		{
			printf("one file end, break;\n");
		}

#endif
		m_mapIt->second.m_tLastTime = tCurrTime;
	}

	m_mapIt->second.m_header.dwId = (m_mapIt->second.m_nFrontID << 16) + m_mapIt->second.m_header.dwId;

	CSlogConnection *pSlogConnection = NULL;
	if (m_mapIt->second.m_header.wType == CLRT_CONNECTED)
	{
		pSlogConnection = GetSlogConnection(m_mapIt->second.m_header.dwId);
		if (pSlogConnection != NULL)
		{
			pSlogConnection->OnDupSocketID(g_szTimeBuffer);
			DelSlogConnection(m_mapIt->second.m_header.dwId);
		}

		pSlogConnection = CreateSlogConnection(
				m_mapIt->second.m_header.dwId,
				m_mapIt->second.m_buffer,
				m_mapIt->second.m_nFrontID,
				m_mapIt->second.m_nFileID,
				m_mapIt->second.m_cVersion);
	}
	else
	{
		pSlogConnection = GetSlogConnection(m_mapIt->second.m_header.dwId);
	}

	if (pSlogConnection == NULL)
	{
		return true;
	}

	switch (m_mapIt->second.m_header.wType)
	{
		case CLRT_CONNECTED:
			pSlogConnection->OnConnected(g_szTimeBuffer);
			break;
		case CLRT_READ:
			pSlogConnection->OnChannelRead(
					g_szTimeBuffer,
					m_mapIt->second.m_buffer,
					m_mapIt->second.m_header.wLength);
			break;
		case CLRT_WRITE:
			pSlogConnection->OnChannelWrite(
					g_szTimeBuffer,
					m_mapIt->second.m_buffer,
					m_mapIt->second.m_header.wLength);
			break;
		case CLRT_DISCONNECT:
			pSlogConnection->OnDisconnected(g_szTimeBuffer);
			DelSlogConnection(m_mapIt->second.m_header.dwId);
			break;
		case CLRT_READ_ERROR:
			pSlogConnection->OnReadError(g_szTimeBuffer);
			break;
		case CLRT_WRITE_ERROR:
			pSlogConnection->OnWriteError(g_szTimeBuffer);
			break;
		case CLRT_DISCONNECTED_READ:
			pSlogConnection->OnDisconnectedRead(g_szTimeBuffer);
			break;
		case CLRT_DISCONNECTED_WRITE:
			pSlogConnection->OnDisconnectedWrite(g_szTimeBuffer);
			break;
		default:
			printf("header type error :[%d]\n", m_mapIt->second.m_header.wType);
			return false;
	}

	return true;
}

void CSlogReactor::DispatchIOs(void)
{
	DWORD dwSelectTimeOut = 10000;

	for (map<string, int>::iterator it = g_mapSlogFileName.begin();
		 it != g_mapSlogFileName.end();
		 it++)
	{
		m_mapIt = m_mapSlogDescript.find((it->first));
		if (m_mapIt == m_mapSlogDescript.end())
		{
			m_mapSlogDescript[it->first] = CSlogDescript(
					it->first.c_str(),
					g_mStringIdMap.getStringId(it->first.c_str()));
			m_mapIt = m_mapSlogDescript.find((it->first));
		}

		if (m_mapIt->second.m_fpSlog == NULL)
		{
			m_mapIt->second.m_fpSlog = fopen(
					m_mapIt->second.m_strSlogFileName.c_str(),
					"rb");
			if (m_mapIt->second.m_fpSlog == NULL)
			{
				printf(
					"open file [%s] error[%d]\n",
					m_mapIt->second.m_strSlogFileName.c_str(),
					errno);

				//////////////////////////////////////////////////////////////////////////
				//feng.q
				m_mapSlogFileReadStatus[m_mapIt->second.m_nFrontID] = 1;

				//////////////////////////////////////////////////////////////////////////
				continue;
			}

			if (fsetpos(
					m_mapIt->second.m_fpSlog,
				&(m_mapIt->second.m_fposLog)) != 0)
			{
				printf(
					"fsetpos file [%s] error[%d]\n",
					m_mapIt->second.m_strSlogFileName.c_str(),
					errno);
				m_mapIt->second.m_fpSlog = NULL;
				fclose(m_mapIt->second.m_fpSlog);
				continue;
			}
		}

		if (!ReadOne())
		{
			if (m_mapIt->second.m_bFollow || m_mapIt->second.m_cWrongFlag)
			{
				continue;
			}
			else
			{
				printf("end of input file\n");
				Stop();
			}
		}
		else
		{
			dwSelectTimeOut = 0;
		}
	}

	fd_set	readfds;

	fd_set	writefds;
	int MaxID = 0;
	PrepareIds(readfds, writefds, MaxID);

	int has_io = 0;
	if (MaxID == 0)
	{
		SleepMs(dwSelectTimeOut / 1000);
	}
	else
	{
		MaxID++;

		struct timeval	timeout;
		timeout.tv_sec = dwSelectTimeOut / 1000000;
		timeout.tv_usec = dwSelectTimeOut % 1000000;
		has_io = select(MaxID, &readfds, &writefds, NULL, &timeout);
	}

	SyncTime();

	if (has_io >= 0)
	{
		DispatchIO(readfds, writefds, MaxID);
	}

	return;
}

void CSlogReactor::PrepareIds(fd_set &readfds, fd_set &writefds, int &MaxID)
{
	FD_ZERO(&readfds);
	FD_ZERO(&writefds);

	if (m_bIOListHasNull)
	{
		m_IOList.remove(NULL);
		m_bIOListHasNull = false;
	}

	for (CEventHandlerList::iterator itor = m_IOList.begin();
		 itor != m_IOList.end();
		 itor++)
	{
		if (*itor == NULL)
		{
			continue;
		}

		int nReadID;

		int nWriteID;
		(*itor)->GetIds(&nReadID, &nWriteID);

		if (nReadID > 0)
		{
			FD_SET(nReadID, &readfds);
			if (MaxID < nReadID)
			{
				MaxID = nReadID;
			}
		}

		if (nWriteID > 0)
		{
			FD_SET(nWriteID, &writefds);
			if (MaxID < nWriteID)
			{
				MaxID = nWriteID;
			}
		}
	}
}

void CSlogReactor::DispatchIO(fd_set &readfds, fd_set &writefds, int &MaxID)
{
	for (CEventHandlerList::iterator itor = m_IOList.begin();
		 itor != m_IOList.end();
		 itor++)
	{
		if (*itor == NULL)
		{
			continue;
		}

		int nReadID;

		int nWriteID;
		(*itor)->GetIds(&nReadID, &nWriteID);

		if (nReadID < 0 || (nReadID > 0 && FD_ISSET(nReadID, &readfds)))
		{
			(*itor)->HandleInput();
		}

		if (*itor == NULL)
		{
			continue;
		}

		if (nWriteID < 0 || (nWriteID > 0 && FD_ISSET(nWriteID, &writefds)))
		{
			(*itor)->HandleOutput();
		}
	}
}
