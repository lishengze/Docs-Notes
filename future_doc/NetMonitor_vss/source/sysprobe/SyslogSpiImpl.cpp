/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	SyslogSpiImpl.cpp
///@brief	ʵ������־�ļ���ȡ��ص���
///@history
///20080514	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
///20090310	�̺״�		Ϊҵ����־��Ϣ��Ԥ�����ֿռ�,֧�����ҵ��ϵͳ��Ϣ
///20090429	�̺״�		����ҵ����־��Ϣ��ȡ���������е�'.'ת��Ϊ'_'
/////////////////////////////////////////////////////////////////////////
#include "SyslogSpiImpl.h"
#include "FileRecordFinder.h"
#define KEYWORDSIZE 100

extern char *g_pPositionFile;
extern char g_pHostName[32];					// ������������
extern char g_pDataCenterName[32];				// ���������������ƣ���TRADE.PuDian
extern char g_mTradeDay[9];						// ������
extern int	g_mFileSegSize;
extern map<string, int> mapMonth;
extern map<int, string> mapMonthStr;
extern char g_mFlowPath[100];					//�������ļ��洢·��
extern CManageConSession g_mManageConSession;	// �����������ӵĵ�ַ��Ϣ
#define SENDPACKAGETOOLDFLOW	m_pkgSend.MakePackage(); \
	m_pFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());

#define SENDPACKAGETOFLOW		m_mAccessField.FileSize = loginfo.m_mHaveRead; \
	m_mAccessField.FileTime = loginfo.m_mIntTime;							   \
	m_mAccessField.ObjectID = loginfo.m_mPosName.c_str();					   \
	FTDC_ADD_FIELD(&m_pkgSend, &m_mAccessField);							   \
	loginfo.m_mSession->SendRequestPackage(&m_pkgSend);

void CSyslogValue::getFileName(void)
{
	m_mPosName = m_mProbeLocation;
	m_mPosName.append(",");
	m_mPosName.append(m_mFileName);
}

bool CSyslogValue::InitFilelog(void)
{
	if (m_mIntTime > 0)
	{
		return true;
	}

	char month[3];

	char day[3];
	memcpy(month, g_mTradeDay + 4, 2);
	memcpy(day, g_mTradeDay + 6, 2);
	month[2] = '\0';
	day[2] = '\0';
	sprintf(
		m_mStrTime,
		"%s %d 00:00:00",
		mapMonthStr[atoi(month)].c_str(),
		atoi(day));
	m_mIntTime = CFileRecordFinder::DateStringToLong(m_mStrTime);
	return true;
}

bool CSyslogValue::InitBinFilelog(void)
{
	if (m_mIntTime > 0)
	{
		return true;
	}

	m_mIntTime = time((time_t *)NULL);
	m_mIntTime = m_mIntTime - m_mIntTime % 86400;
	return true;
}

CSyslogSpiImpl::CSyslogSpiImpl(
	CCachedFileFlow *pFlow,
	MapConSyslog *pFileNameMap)
{
	m_pFileNameMap = pFileNameMap;
	m_pFlow = pFlow;
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	strcpy(m_mObjectName, "pudian.os.kf4640");
	m_mBuffSize = sizeof(m_mReadBuff);
	memset(m_mReadBuff, 0, m_mBuffSize);
	memset(&m_mLogField, 0, sizeof(m_mLogField));
}

void CSyslogSpiImpl::PrintSyslogMap(void)
{
	MapConSyslog::iterator	map_it;
	for (map_it = m_pFileNameMap->begin();
		 map_it != m_pFileNameMap->end();
		 map_it++)
	{
		printf(
			"key %s %d %s %d %u %u\n",
			map_it->first.m_mPath.c_str(),
			map_it->first.m_mSession,
			map_it->second.m_mName.c_str(),
			map_it->second.m_mFd,
			map_it->second.m_mHaveRead,
			map_it->second.m_mValid);
	}
}

bool CSyslogSpiImpl::DispatchIOsSpi(void)
{
	MapConSyslog::iterator	map_it;
	bool bRdFlag = false;
	for (map_it = m_pFileNameMap->begin();
		 map_it != m_pFileNameMap->end();
		 map_it++)
	{
		map_it->second.m_mSession = map_it->first.m_mSession;
		if (map_it->second.m_mRdFlag && map_it->second.m_mSession != NULL)
		{
			KeepReadFile(
				(string &)map_it->first.m_mPath,
				(CSyslogValue &)map_it->second);
			bRdFlag = bRdFlag || map_it->second.m_mRdFlag;
		}
	}

	return bRdFlag;
}

bool CSyslogSpiImpl::DispatchIOsBinSpi(void)
{
	MapConSyslog::iterator	map_it;
	bool bRdFlag = false;
	for (map_it = m_pFileNameMap->begin();
		 map_it != m_pFileNameMap->end();
		 map_it++)
	{
		map_it->second.m_mSession = map_it->first.m_mSession;
		if (map_it->second.m_mRdFlag && map_it->second.m_mSession != NULL)
		{
			KeepReadBinFile(
				(string &)map_it->first.m_mPath,
				(CSyslogValue &)map_it->second);
			bRdFlag = bRdFlag || map_it->second.m_mRdFlag;
		}
	}

	return bRdFlag;
}

bool CSyslogSpiImpl::GetSpi(void)
{
	TIME_MEASURE_START(__FUNCTION__);

	MapConSyslog::iterator	map_it;
	for (map_it = m_pFileNameMap->begin();
		 map_it != m_pFileNameMap->end();
		 map_it++)
	{
#ifdef PRINT_DEBUG
		printf(
			"key: %s value:%s %s %s %d %u %u\n",
			map_it->first.m_mPath.c_str(),
			map_it->second.m_mName.c_str(),
			map_it->second.m_mFileName.c_str(),
			map_it->second.m_mType.c_str(),
			map_it->second.m_mFd,
			map_it->second.m_mHaveRead,
			map_it->second.m_mValid);
#endif
		map_it->second.m_mSession = map_it->first.m_mSession;
		if (map_it->second.m_mSession != NULL)
		{
			KeepReadFile(
				(string &)map_it->first.m_mPath,
				(CSyslogValue &)map_it->second);
		}
	}

	TIME_MEASURE_END(__FUNCTION__);
	return true;
}

bool CSyslogSpiImpl::GetTotalSpi(void)
{
	TIME_MEASURE_START(__FUNCTION__);

	MapConSyslog::iterator	map_it;
	for (map_it = m_pFileNameMap->begin();
		 map_it != m_pFileNameMap->end();
		 map_it++)
	{
#ifdef PRINT_DEBUG
		printf(
			"key: %s value:%s %s %s %d %u %u\n",
			map_it->first.m_mPath.c_str(),
			map_it->second.m_mName.c_str(),
			map_it->second.m_mFileName.c_str(),
			map_it->second.m_mType.c_str(),
			map_it->second.m_mFd,
			map_it->second.m_mHaveRead,
			map_it->second.m_mValid);
#endif
		map_it->second.m_mSession = map_it->first.m_mSession;
		if (map_it->second.m_mSession != NULL)
		{
			KeepReadTotalFile(
				(string &)map_it->first.m_mPath,
				(CSyslogValue &)map_it->second);
		}
	}

	TIME_MEASURE_END(__FUNCTION__);
	return true;
}

bool CSyslogSpiImpl::GetSizeSpi(void)
{
#ifdef PRINT_DEBUG
	printf("============= GetSizeSpi() =============\n");
#endif
	TIME_MEASURE_START(__FUNCTION__);

	MapConSyslog::iterator	map_it;
	for (map_it = m_pFileNameMap->begin();
		 map_it != m_pFileNameMap->end();
		 map_it++)
	{
#ifdef PRINT_DEBUG
		printf(
			"key: %s value:%s %s %s %d %u %u lines: %ld\n",
			map_it->first.m_mPath.c_str(),
			map_it->second.m_mName.c_str(),
			map_it->second.m_mFileName.c_str(),
			map_it->second.m_mType.c_str(),
			map_it->second.m_mFd,
			map_it->second.m_mHaveRead,
			map_it->second.m_mValid,
			map_it->second.m_mLines);
#endif
		map_it->second.m_mSession = map_it->first.m_mSession;
		if (map_it->second.m_mSession != NULL)
		{
			KeepReadFileSize(
				(string &)map_it->first.m_mPath,
				(CSyslogValue &)map_it->second);
		}
	}

	TIME_MEASURE_END(__FUNCTION__);
	return true;
}

bool CSyslogSpiImpl::GetBinSpi(void)
{
	TIME_MEASURE_START(__FUNCTION__);

	MapConSyslog::iterator	map_it;
	for (map_it = m_pFileNameMap->begin();
		 map_it != m_pFileNameMap->end();
		 map_it++)
	{
#ifdef PRINT_DEBUG
		printf(
			"key: %s value:%s %s %s %d %u %u\n",
			map_it->first.c_str(),
			map_it->second.m_mName.c_str(),
			map_it->second.m_mFileName.c_str(),
			map_it->second.m_mType.c_str(),
			map_it->second.m_mFd,
			map_it->second.m_mHaveRead,
			map_it->second.m_mValid);
#endif
		map_it->second.m_mSession = map_it->first.m_mSession;
		if (map_it->second.m_mSession != NULL)
		{
			KeepReadBinFile(
				(string &)map_it->first,
				(CSyslogValue &)map_it->second);
		}
	}

	TIME_MEASURE_END(__FUNCTION__);
	return true;
}

//#define PRINT_DEBUG
void CSyslogSpiImpl::KeepReadBinFile(string &filename, CSyslogValue &loginfo)
{
	size_t	rsize;
	struct stat filestat;

#ifdef PRINT_DEBUG
	printf(
		"filename %s loginfo.m_mHaveRead %d\n",
		filename.c_str(),
		loginfo.m_mHaveRead);
	printf(
		"filename %s loginfo.m_mFd %ld loginfo.m_mHaveRead %d\n",
		filename.c_str(),
		(long)loginfo.m_mFd,
		loginfo.m_mHaveRead);
#endif
	loginfo.InitBinFilelog();
	if ((stat(filename.c_str(), &filestat) < 0))	///stat�ļ�ʧ�ܣ�����
	{
#ifdef PRINT_DEBUG
		printf(
			"\tFileName %s stat error loginfo.m_mFd %ld loginfo.m_mHaveRead %d\n",
			filename.c_str(),
			(long)loginfo.m_mFd,
			loginfo.m_mHaveRead);
#endif
		loginfo.m_mHaveRead = 0;
		if (loginfo.m_mFd != NULL)					// �ļ���;��ɾ��
		{
			SAFE_FCLOSE(loginfo.m_mFd);

			//loginfo.m_mHaveRead = 0;
			//loginfo.m_mFileName.append("0");
		}

		loginfo.m_mRdFlag = false;
		return;
	}
	else if (filestat.st_mtime <= loginfo.m_mIntTime)
	{			// �ļ�������޸�ʱ��С���Ѿ���ȡʱ��
#ifdef PRINT_DEBUG
		printf(
			"==filename %s loginfo.m_mIntTime %d filestat.st_mtime\n",
			filename.c_str(),
			loginfo.m_mIntTime,
			filestat.st_mtime);
#endif
		return;
	}
	else if (filestat.st_size > loginfo.m_mHaveRead)
	{
		if (loginfo.m_mFd == NULL && loginfo.m_mValid >= READFILEINTERVAL)
		{
			if ((loginfo.m_mFd = fopen(filename.c_str(), "rb")) == NULL)
			{
				loginfo.m_mValid = 0;
				loginfo.m_mRdFlag = false;
				return;
			}
		}
		else if (loginfo.m_mFd == NULL)
		{
			loginfo.m_mValid++;
			loginfo.m_mRdFlag = false;
			return;
		}

		if (fseek(loginfo.m_mFd, loginfo.m_mHaveRead, SEEK_SET) < 0)
		{
			printf("FileName %s lseek error\n", filename.c_str());
			loginfo.m_mRdFlag = false;
			return;
		}

		m_mLogField.ObjectID = loginfo.m_mObjectID.c_str();
		sprintf(
			(char *)m_mLogField.AttrType.getValue(),
			"%s.%s.%s",
			loginfo.m_mFileName.c_str(),
			g_pDataCenterName,
			g_pHostName);

		size_t	fieldSize = 0;
		int fieldNum = 0;
		int sendNum = 0;
		m_pkgSend.PreparePackage(
				FTD_TID_RtnSyslogInfoTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		while ((rsize = fread(m_mReadBuff, 1, m_mBuffSize - 1, loginfo.m_mFd)))
		{
			if (fieldNum == MAXCONTENTFIELDNUM)
			{	///ÿ��FTD��������MAXCONTENTFIELDNUM��m_mLogField��
				SENDPACKAGETOFLOW;
				sendNum++;
#ifdef PRINT_DEBUG
				printf(
					"\n++++++++++++++++Send one fileinfo package,read size %d\n",
					fieldSize);
				printf(
					"\n===== package [%s]\n",
					(char *)(m_mLogField.FileContent.getValue()));
#endif
				if (sendNum >= 600)
				{
					loginfo.m_mRdFlag = true;
					return;
				}

				m_pkgSend.PreparePackage(
						FTD_TID_RtnSyslogInfoTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				fieldNum = 0;
			}

			memcpy(
				(char *)(m_mLogField.FileContent.getValue() + fieldSize),
				m_mReadBuff,
				rsize);
			m_mLogField.ContLen = rsize;
			FTDC_ADD_FIELD(&m_pkgSend, &m_mLogField);
			loginfo.m_mHaveRead = loginfo.m_mHaveRead + rsize;
			fieldNum++;
		}

		loginfo.m_mIntTime = filestat.st_mtime;
		if (fieldNum)
		{
			SENDPACKAGETOFLOW;
		}
	}
	else
	{
		loginfo.m_mRdFlag = false;
	}
}

void CSyslogSpiImpl::KeepReadTotalFile(string &filename, CSyslogValue &loginfo)
{
	size_t	rsize;
	struct stat filestat;

#ifdef PRINT_DEBUG
	printf(
		"===S filename %s loginfo.m_mHaveRead %d\n",
		filename.c_str(),
		loginfo.m_mHaveRead);
#endif

	if (loginfo.m_mFd == NULL && loginfo.m_mValid >= READFILEINTERVAL)
	{
		loginfo.InitFilelog();
		if ((loginfo.m_mFd = fopen(filename.c_str(), "r")) == NULL)
		{
			loginfo.m_mRdFlag = false;
			loginfo.m_mValid = 0;
			return;
		}
	}
	else if (loginfo.m_mFd == NULL)
	{
		loginfo.m_mValid++;
		return;
	}

	if (stat(filename.c_str(), &filestat) < 0)	///stat�ļ�ʧ�ܣ���ζ�Ÿ��ļ��ڴ򿪹����б�ɾ��������
	{
		printf("FileName %s stat error\n", filename.c_str());
		fflush(stdout);
		SAFE_FCLOSE(loginfo.m_mFd);
		loginfo.m_mValid = READFILEINTERVAL;	///statʧ�ܺ���һ�ξ����������ļ��Ƿ����
		loginfo.m_mHaveRead = 0;
		return;
	}
	else if ((loginfo.m_mHaveRead > 0 && loginfo.m_mHaveRead < 1000000) && 
		(filestat.st_size != loginfo.m_mHaveRead || 
		(filestat.st_size == loginfo.m_mHaveRead && max(loginfo.m_mIntTime, loginfo.m_mIntTime) < filestat.st_mtime - 60)
		)
	)
	{
		// ���ļ����ܱ�ɾ�������ݣ����´�
		/// ������С�ļ����ض�
		{
			printf(
				"FileName %s removed [%ld != %ld]||[max(%ld,%ld) < %ld]\n",
				filename.c_str(),
				filestat.st_size,
				loginfo.m_mHaveRead,
				loginfo.m_mTime,
				loginfo.m_mIntTime,
				filestat.st_mtime);
			fflush(stdout);
			SAFE_FCLOSE(loginfo.m_mFd);
			loginfo.m_mHaveRead = 0;
			return;
		}
	}	
	else if (filestat.st_size > loginfo.m_mHaveRead)
	/// ��Ҫ��ȡ�ļ�
	{
		if (fseek(loginfo.m_mFd, loginfo.m_mHaveRead, SEEK_SET) < 0)
		{
			printf("FileName %s lseek error\n", filename.c_str());
			fflush(stdout);
			SAFE_FCLOSE(loginfo.m_mFd);
			loginfo.m_mValid = READFILEINTERVAL;
			return;
		}

		loginfo.m_mTime = filestat.st_mtime;  /// �ļ����������޸�ʱ��
		loginfo.m_mIntTime = filestat.st_mtime;
		
		struct tm tm_time;
		LocalTime(&(filestat.st_mtime), &tm_time);
		strftime((char *)m_mLogField.MonTime.getValue(), 10, "%H:%M:%S", &tm_time);
		strftime((char *)m_mLogField.MonDate.getValue(), 10, "%Y%m%d", &tm_time);

		m_mLogField.ObjectID = loginfo.m_mObjectID.c_str();
		m_mLogField.AttrType = loginfo.m_mFileName.c_str();

		/// �ļ���������䳤��
		size_t	fieldSize = 0;
		
		/// pkg�����������Ϣ��
		int fieldNum = 0;
		
		/// �ѷ���pkg���ĸ���
		int sendNum = 0;
		
		m_pkgSend.PreparePackage(
				FTD_TID_RtnSyslogInfoTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
				
		memset(m_mReadBuff, 0, m_mBuffSize);
		////�����ı�ɨ�����
		while ((fgets(m_mReadBuff, m_mBuffSize - 1, loginfo.m_mFd)) != NULL)
		{
#ifdef PRINT_DEBUG
			printf("[%s]", m_mReadBuff);
#endif
			/// �����ֽ���	
			rsize = strlen(m_mReadBuff);

			if (fieldSize + rsize < sizeof(m_mLogField.FileContent))
			{
				// ���뵱ǰfield����
				strcpy(
				  (char *)(m_mLogField.FileContent.getValue() + fieldSize),
					m_mReadBuff);
				fieldSize += rsize;
			}
			else 
			{
				// ��Ҫ�����µ�field����
				// ȷ�����һ��field������԰�ȫ����pkg
				if (fieldNum >= MAXCONTENTFIELDNUM -1)
				{								
					///ÿ��pkg��������MAXCONTENTFIELDNUM��m_mLogField��
					SENDPACKAGETOFLOW;
					sendNum++;
					
					if (sendNum >= 10000)	// ��������10000�κ�����˴βɼ�
					{
						loginfo.m_mRdFlag = true;
						return;
					}

					m_pkgSend.PreparePackage(
							FTD_TID_RtnSyslogInfoTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
					fieldNum = 0;
				}

				// ��֮ǰ��ǰ���õ�filed������뵱ǰpkg
				m_mLogField.ContLen = fieldSize;
				FTDC_ADD_FIELD(&m_pkgSend, &m_mLogField);
				loginfo.m_mHaveRead = loginfo.m_mHaveRead + fieldSize;
				fieldNum++;

				/// Mod by Henchi, 20130524
				/// �����memcpy���µĻ�����δ����
				//memcpy(
				//	(char *)(m_mLogField.FileContent.getValue() + fieldSize),
				//	m_mReadBuff,
				//	rsize);
				
				// ��ǰ��������ݴ����µ�field��
				strcpy((char *)(m_mLogField.FileContent.getValue()), m_mReadBuff);
				fieldSize = rsize;
			}
			memset(m_mReadBuff, 0, m_mBuffSize);
		}

		loginfo.m_mRdFlag = false;
		if (fieldSize)
		{
			m_mLogField.ContLen = fieldSize;
			char *pEnd = (char *)(m_mLogField.FileContent.getValue()) + fieldSize;
			*pEnd = 0x00;
			FTDC_ADD_FIELD(&m_pkgSend, &m_mLogField);
			loginfo.m_mHaveRead = loginfo.m_mHaveRead + fieldSize;
			fieldNum++;
		}

		if (fieldNum)
		{
			SENDPACKAGETOFLOW;
		}

#ifdef PRINT_DEBUG
		printf(
			"===E filename %s loginfo.m_mHaveRead %d\n",
			filename.c_str(),
			loginfo.m_mHaveRead);
#endif
	}
	else
	{
		loginfo.m_mRdFlag = false;
	}
}

bool CSyslogSpiImpl::OpenReadFile(string &filename, CSyslogValue &loginfo)
{
	loginfo.InitFilelog();
	if ((loginfo.m_mFd = fopen(filename.c_str(), "r")) == NULL)
	{
		loginfo.m_mRdFlag = false;
		loginfo.m_mValid = 0;
		return false;
	}

	/// ������ȡλ��
	CFileRecordFinder finder(loginfo.m_mFd);
	finder.init();
	if (loginfo.m_mHaveRead > 0
	&&	loginfo.m_mHaveRead == finder.m_size
	&&	loginfo.m_mIntTime == finder.m_lLast)
	{
		/// �ļ��Ѿ���ȡ����ǰ��ĩλ��,���ѷ��͹�����ID��ҵ�����ID�Ĺ�ϵ
		loginfo.m_mRdFlag = true;
		loginfo.m_mTime = finder.m_modtime;
		return true;
	}

	time_t	timep;
	time(&timep);
	printf("\n\n%sFile [%s] start search", ctime(&timep), filename.c_str());
	fflush(stdout);
	loginfo.m_mHaveRead = finder.Search((loginfo.m_mIntTime));
	if (loginfo.m_mHaveRead < 0)
	{
		printf("FileName %s read nothing, close!\n", filename.c_str());
		fflush(stdout);
		SAFE_FCLOSE(loginfo.m_mFd);
		loginfo.m_mHaveRead = 0;
		loginfo.m_mRdFlag = false;
		loginfo.m_mValid = 0;
		return false;
	}

	loginfo.m_mRdFlag = true;
	loginfo.m_mTime = finder.m_modtime;

	/// ����ʶ������ID��ҵ�����ID��ϵ��ʶ�������õ�����
	if (loginfo.m_mType == string(HOSTATTRAPPLOG))
	{
		if (fseek(loginfo.m_mFd, finder.m_posFirst, SEEK_SET) < 0)
		{
			printf("FileName %s lseek error\n", filename.c_str());
			fflush(stdout);
			SAFE_FCLOSE(loginfo.m_mFd);
			loginfo.m_mFd = NULL;
			loginfo.m_mValid = READFILEINTERVAL;
			return false;
		}

		while (fgets(m_mReadBuff, m_mBuffSize - 1, loginfo.m_mFd) != NULL)
		{
			/// ��Ҫ�������� Mar 31 08:30:00 AC-01 front 1
			char *pHost;

			/// ��Ҫ�������� Mar 31 08:30:00 AC-01 front 1
			char *pApp;

			/// ��Ҫ�������� Mar 31 08:30:00 AC-01 front 1
			char *pId;

			/// ��Ҫ�������� Mar 31 08:30:00 AC-01 front 1
			char *p;
			p = strchr(m_mReadBuff, ' ');
			if (p == NULL)
			{
				continue;
			}

			while (*p == ' ')
			{
				p++;
			}									//31

			p = strchr(p, ' ');
			if (p == NULL)
			{
				continue;
			}

			while (*p == ' ')
			{
				p++;
			}									//08

			p = strchr(p, ' ');
			if (p == NULL)
			{
				continue;
			}

			while (*p == ' ')
			{
				p++;
			}									//AC

			pHost = p;
			p = strchr(pHost, ' ');
			if (p == NULL)
			{
				continue;
			}

			*p = '\0';
			p++;
			while (*p == ' ')
			{
				p++;
			}									//front

			pApp = p;
			p = strchr(pApp, ' ');
			if (p == NULL)
			{
				continue;
			}

			*p = '\0';
			p++;
			while (*p == ' ')
			{
				p++;
			}									//1

			pId = p;
			p = strchr(pId, '[');
			if (p == NULL)
			{
				continue;
			}

			*p = '\0';

			//��������������Ϣ���������˳�whileѭ��
			CFTDRtnUpdateSysConfigField fieldInfo;
			m_pkgSend.PreparePackage(
					FTD_TID_RtnUpdateSysConfigTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);

			//fieldInfo.UpdateType:����ID��ҵ��IDӳ���ϵ����
			fieldInfo.UpdateType = UPDATESYSCONFIG_HOSTIDAPPID;

			//fieldInfo.OldValue:��������ID
			while ((p = strchr(pHost, '.')))
			{
				*p = '_';						// Mod by Henchi 20090429
			}

			sprintf(
				(char *)fieldInfo.OldValue.getValue(),
				"%s.%s.%s",
				g_pDataCenterName,
				DATACENTERHOST,
				pHost);

			//fieldInfo.NewValue:����ҵ��ID
			//���̵�ҵ��IDδ֪ʱΪ��ֵ���򲻷��ͱ��
			if (atoi(pId) <= 0)
			{
				sprintf(
					(char *)fieldInfo.NewValue.getValue(),
					"%s.%s.%s",
					g_pDataCenterName,
					DATACENTERAPP,
					pApp);
			}
			else if (atoi(pId) > 0)
			{
				sprintf(
					(char *)fieldInfo.NewValue.getValue(),
					"%s.%s.%s.%s",
					g_pDataCenterName,
					DATACENTERAPP,
					pApp,
					pId);
			}

			FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);

			// SENDPACKAGETOFLOW;
			loginfo.m_mSession->SendRequestPackage(&m_pkgSend);
			break;
		}
	}											// END IF

	return true;
}

void CSyslogSpiImpl::KeepReadFile(string &filename, CSyslogValue &loginfo)
{
	size_t	rsize;
	struct stat filestat;

#ifdef PRINT_DEBUG
	printf(
		"Filename %s m_mHaveRead[%d] \n",
		filename.c_str(),
		loginfo.m_mHaveRead);
#endif
	if (loginfo.m_mFd == NULL && loginfo.m_mValid >= READFILEINTERVAL)
	{
		if (!OpenReadFile(filename, loginfo))
		{
			return;
		}
	}
	else if (loginfo.m_mFd == NULL)
	{
		loginfo.m_mValid++;
		return;
	}

	if (stat(filename.c_str(), &filestat) < 0)	///stat�ļ�ʧ�ܣ���ζ�Ÿ��ļ��ڴ򿪹����б�ɾ��������
	{
		printf("FileName %s stat error\n", filename.c_str());
		fflush(stdout);
		SAFE_FCLOSE(loginfo.m_mFd);
		loginfo.m_mValid = READFILEINTERVAL;	///statʧ�ܺ���һ�ξ����������ļ��Ƿ����
		loginfo.m_mHaveRead = 0;
		return;
	}
	else if (filestat.st_size < loginfo.m_mHaveRead || 
		(filestat.st_size == loginfo.m_mHaveRead && max(loginfo.m_mTime,(time_t) loginfo.m_mIntTime) < filestat.st_mtime - 60)
	)
	{
		// ���ļ����ܱ�ɾ�������ݣ����´�
		printf(
			"FileName %s removed [%ld <= %ld] [max(%ld,%ld) < %ld]\n",
			filename.c_str(),
			filestat.st_size,
			loginfo.m_mHaveRead,
			loginfo.m_mTime,
			loginfo.m_mIntTime,
			filestat.st_mtime -60);

		fflush(stdout);
		SAFE_FCLOSE(loginfo.m_mFd);
		loginfo.m_mHaveRead = 0;
		return;
	}
	else if (filestat.st_size > loginfo.m_mHaveRead)
	{
		if (fseek(loginfo.m_mFd, loginfo.m_mHaveRead, SEEK_SET) < 0)
		{
			printf("FileName %s lseek error\n", filename.c_str());
			fflush(stdout);
			SAFE_FCLOSE(loginfo.m_mFd);
			loginfo.m_mValid = READFILEINTERVAL;
			return;
		}

		loginfo.m_mTime = filestat.st_mtime;

		m_mLogField.ObjectID = loginfo.m_mObjectID.c_str();
		m_mLogField.AttrType = loginfo.m_mFileName.c_str();

		size_t	fieldSize = 0;
		int fieldNum = 0;
		int sendNum = 0;
		m_pkgSend.PreparePackage(
				FTD_TID_RtnSyslogInfoTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		memset(m_mReadBuff, 0, m_mBuffSize);
		while ((fgets(m_mReadBuff, m_mBuffSize - 1, loginfo.m_mFd)) != NULL)
		{
#ifdef PRINT_DEBUG
			printf("[%s]", m_mReadBuff);
#endif
			rsize = strlen(m_mReadBuff);
			if (m_mReadBuff[15] == ' ')
			{
				memcpy(loginfo.m_mStrTime, m_mReadBuff, 15);
				loginfo.m_mStrTime[15] = '\0';
			}
			else if (m_mReadBuff[16] == ' ')
			{
				memcpy(loginfo.m_mStrTime, m_mReadBuff, 16);
				loginfo.m_mStrTime[16] = '\0';
			}

			// if(fieldSize+rsize<MAXONECONTENTLEN-100) //Mod by Henchi 20090310, ������ҵ��ϵͳ���������¶���ID����,�ʴ�Ԥ�����ֿռ�
			if (fieldSize + rsize < MAXONECONTENTLEN)	//Mod by zhou.jj 20090605, ����־������Ϊ�ɼ��������,��ɾ��Ԥ���Ĳ��ֿռ�
			{
				memcpy(
					(char *)(m_mLogField.FileContent.getValue() + fieldSize),
					m_mReadBuff,
					rsize);
				fieldSize += rsize;
			}
			else
			{
				if (fieldNum >= MAXCONTENTFIELDNUM -1)
				{	///ÿ��FTD��������MAXCONTENTFIELDNUM��m_mLogField��
					loginfo.m_mIntTime = CFileRecordFinder::DateStringToLong(
							loginfo.m_mStrTime);
					SENDPACKAGETOFLOW;
					sendNum++;
					
					/// Mod by Henchi, 20150327
					/// �ӿ���־�ļ���ȡ���ʣ�Լ 1MB/s
					//if (sendNum >= 2)
					if (sendNum >= 256)
					{
						loginfo.m_mRdFlag = true;
						return;
					}

					m_pkgSend.PreparePackage(
							FTD_TID_RtnSyslogInfoTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
					fieldNum = 0;
				}

				m_mLogField.ContLen = fieldSize;
				FTDC_ADD_FIELD(&m_pkgSend, &m_mLogField);
				loginfo.m_mHaveRead = loginfo.m_mHaveRead + fieldSize;
				fieldNum++;
				fieldSize = 0;
				/// Mod by Henchi, 20130524
				/// �����memcpy���µĻ�����δ����
				//memcpy(
				//	(char *)(m_mLogField.FileContent.getValue() + fieldSize),
				//	m_mReadBuff,
				//	rsize);
				strcpy((char *)(m_mLogField.FileContent.getValue() + fieldSize),
					m_mReadBuff
					);
				fieldSize += rsize;
			}
			memset(m_mReadBuff, 0, m_mBuffSize);
		}

		loginfo.m_mRdFlag = false;
		if (fieldSize)
		{
			m_mLogField.ContLen = fieldSize;
			FTDC_ADD_FIELD(&m_pkgSend, &m_mLogField);
			loginfo.m_mHaveRead = loginfo.m_mHaveRead + fieldSize;
			fieldNum++;
		}

		if (fieldNum)
		{
			loginfo.m_mIntTime = CFileRecordFinder::DateStringToLong(
					loginfo.m_mStrTime);
			SENDPACKAGETOFLOW;
		}
	}
	else
	{
		loginfo.m_mRdFlag = false;
	}
}

void CSyslogSpiImpl::KeepReadFileSize(string &filename, CSyslogValue &loginfo)
{
	size_t	rsize;
	struct stat filestat;

#ifdef PRINT_DEBUG
	printf(
		"filename %s loginfo.m_mHaveRead %d loginfo.m_mLines %ld\n",
		filename.c_str(),
		loginfo.m_mHaveRead,
		loginfo.m_mLines);
#endif
	if (loginfo.m_mFd == NULL)
	{
		if ((loginfo.m_mFd = fopen(filename.c_str(), "r")) == NULL)
		{
			return;
		}

		loginfo.m_mHaveRead = 0;
	}

	if (stat(filename.c_str(), &filestat) < 0)	///stat�ļ�ʧ�ܣ�����
	{
		printf("\tFileName %s stat error\n", filename.c_str());
		return;
	}
	else if (filestat.st_size > loginfo.m_mHaveRead)
	{
		if (fseek(loginfo.m_mFd, loginfo.m_mHaveRead, SEEK_SET) < 0)
		{
			printf("FileName %s lseek error\n", filename.c_str());
			fflush(stdout);
			return;
		}

		m_mLogField.AttrType = loginfo.m_mFileName.c_str();

		while ((fgets(m_mReadBuff, m_mBuffSize - 1, loginfo.m_mFd)) != NULL)
		{
			rsize = strlen(m_mReadBuff);
			if (rsize >= 2)
			{
				loginfo.m_mLines++;
			}

			loginfo.m_mHaveRead = loginfo.m_mHaveRead + rsize;
		}

#ifdef PRINT_DEBUG
		printf(
			"KeepReadFileSize(): file:%s  read:%d  lines:%ld\n",
			filename.c_str(),
			loginfo.m_mHaveRead,
			loginfo.m_mLines);
#endif
	}

	char *p;

	char szTmp[64] = "";
	strcpy(szTmp, loginfo.m_mFileName.c_str());
	p = strstr(szTmp, ".");
	if (p != NULL)
	{
		*p = '\0';
		p++;
	}

	sprintf(m_mObjectId, "%s.%s.%s", g_pDataCenterName, DATACENTERAPP, szTmp);

	time_t	now;
	time(&now);
	struct tm tm_time;
	LocalTime(&now, &tm_time);
	strftime(m_mTime, 10, "%H:%M:%S", &tm_time);
	strftime(m_mDate, 10, "%Y%m%d", &tm_time);

	m_pkgSend.PreparePackage(
			FTD_TID_RtnObjectAttrTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDRtnObjectAttrField	m_ObjAttrInfo;
	m_ObjAttrInfo.ObjectID = m_mObjectId;
	m_ObjAttrInfo.AttrType = p ? p : "";
	m_ObjAttrInfo.MonTime = m_mTime;
	m_ObjAttrInfo.MonDate = m_mDate;
	m_ObjAttrInfo.ValueType = INT_ATTR;
	sprintf(
		(char *)m_ObjAttrInfo.AttrValue.getValue(),
		"%d",
		loginfo.m_mLines / g_mFileSegSize);
#ifdef PRINT_DEBUG
	printf(
		"=====DFMTINFO=====\nID:%s TYPE:%s VAL:%s\n\n",
		(const char *)m_ObjAttrInfo.ObjectID.getValue(),
		(const char *)m_ObjAttrInfo.AttrType.getValue(),
		(const char *)m_ObjAttrInfo.AttrValue.getValue());
#endif
	if (FTDC_ADD_FIELD(&m_pkgSend, &m_ObjAttrInfo) != 0)
	{
		printf("add field wrong\n");
		fflush(stdout);
	}

	SENDPACKAGETOFLOW;
}

CSyslogSpiImpl::~CSyslogSpiImpl(void)
{
	MapConSyslog::iterator	map_it;
	for (map_it = m_pFileNameMap->begin();
		 map_it != m_pFileNameMap->end();
		 map_it++)
	{
		///��Ҫ�ر��ļ�������
		if (map_it->second.m_mFd != NULL)
		{
			SAFE_FCLOSE(map_it->second.m_mFd);
		}
	}
}
