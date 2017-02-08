#include "CTrapLogReader.h"

#define READFILEINTERVAL	60
#define SIZE_BUF			4096

CTrapRecord::CTrapRecord(void)
{
	bValidFlag = false;
}

CTrapRecord::~CTrapRecord(void)
{
}

void CTrapRecord::Reset(void)
{
	bValidFlag = true;
}

bool CTrapRecord::IsValidRec(string record)
{
	/// 2011-03-28 19:31:54 <UNKNOWN> {UDP: [172.16.80.201]:63976->[172.16.94.21]]} {TRAP, SNMP v1, community sfit} {SNMPv2-SMI::enterprises.9.9.41.1.2.3.1.2.44590 = STRING: "CDP"	SNMPv2-SMI::enterprises.9.9.41.1.2.3.1.3.44590 = INTEGER: 5	SNMPv2-SMI::enterprises.9.9.41.1.2.3.1.4.44590 = STRING: "NATIVE_VLAN_MISMATCH"	SNMPv2-SMI::enterprises.9.9.41.1.2.3.1.5.44590 = STRING: "Native VLAN mismatch discovered on FastEthernet0/45 (80), with Z-BIZ1-9-5F-1 FastEthernet0/17 (580)."	SNMPv2-SMI::enterprises.9.9.41.1.2.3.1.6.44590 = Timeticks: (267439698) 30 days, 22:53:16.98}
	char *pRec = (char *)record.data();
	if (pRec[4] == '-'
	&&	pRec[7] == '-'
	&&	pRec[10] == ' '
	&&	pRec[13] == ':'
	&&	pRec[16] == ':'
	&&	pRec[19] == ' ')
	{
		return true;
	}
	else
	{
		bValidFlag = false;
		return false;
	}
}

bool CTrapRecord::LoadRec(string record)
{
	/// 2011-03-28 19:31:54 <UNKNOWN> {UDP: [172.16.80.201]:63976->[172.16.94.21]]} {TRAP, SNMP v1, community sfit} {SNMPv2-SMI::enterprises.9.9.41.1.2.3.1.2.44590 = STRING: "CDP"	SNMPv2-SMI::enterprises.9.9.41.1.2.3.1.3.44590 = INTEGER: 5	SNMPv2-SMI::enterprises.9.9.41.1.2.3.1.4.44590 = STRING: "NATIVE_VLAN_MISMATCH"	SNMPv2-SMI::enterprises.9.9.41.1.2.3.1.5.44590 = STRING: "Native VLAN mismatch discovered on FastEthernet0/45 (80), with Z-BIZ1-9-5F-1 FastEthernet0/17 (580)."	SNMPv2-SMI::enterprises.9.9.41.1.2.3.1.6.44590 = Timeticks: (267439698) 30 days, 22:53:16.98}
	if (IsValidRec(record))
	{
		int iYear;

		int iMonth;

		int iDay;

		int iHour;

		int iMinite;

		int iSecond;
		char szDate[16];
		char szTime[16];
		char szHostname[64];
		char szProtocol[16];
		char szSrcIP[32];
		char szSrcPort[16];
		char szDstIP[32];
		char szComm[64];
		char szInfo[4096];

		int iRtn = sscanf(
				record.c_str(),
				"%04d-%02d-%02d %02d:%02d:%02d %s {%[A-Z]: [%[0-9.]]:%[0-9]->[%[0-9.]]]} {%[a-zA-Z0-9, ]} {%[^\n]}\n",
				&iYear,
				&iMonth,
				&iDay,
				&iHour,
				&iMinite,
				&iSecond,
				szHostname,
				szProtocol,
				szSrcIP,
				szSrcPort,
				szDstIP,
				szComm,
				szInfo);
		if (iRtn == 13)
		{
			char szType[64];

			char szSnmpVer[64];

			char szCommunity[64];

			sprintf(szDate, "%04d%02d%02d", iYear, iMonth, iDay);
			sprintf(szTime, "%02d:%02d:%02d", iHour, iMinite, iSecond);
			sscanf(
				szComm,
				"%[a-zA-Z], %[a-zA-Z0-9 ], community %[a-zA-Z0-9-_.]",
				szType,
				szSnmpVer,
				szCommunity);

			strDate = szDate;
			strTime = szTime;
			strHost = szHostname;
			strProtocal = szProtocol;
			strSrcIP = szSrcIP;
			strDstIP = szDstIP;
			strSrcPort = szSrcPort;
			strType = szType;
			strSnmpVer = szSnmpVer;
			strCommunity = szCommunity;
			strVariables = szInfo;
			bValidFlag = true;

			return true;
		}
	}

	printf("Get Invalid record:[%s]\n", record.c_str());
	bValidFlag = false;
	return false;
}

CTrapLogReader::CTrapLogReader(void)
{
	m_strFilePath = "";
	m_lReadPos = 0;
	m_pFile = NULL;
	m_iValidFlag = READFILEINTERVAL;
	m_tModify = 0;
}

CTrapLogReader::CTrapLogReader(string strFilePath)
{
	m_strFilePath = strFilePath;
	m_lReadPos = 0;
	m_pFile = NULL;
	m_iValidFlag = READFILEINTERVAL;
	m_tModify = 0;
}

CTrapLogReader::CTrapLogReader(string strFilePath, long lReads)
{
	m_strFilePath = strFilePath;
	m_lReadPos = lReads;
	m_pFile = NULL;
	m_iValidFlag = READFILEINTERVAL;
	m_tModify = 0;
}

CTrapLogReader::~CTrapLogReader(void)
{
}

bool CTrapLogReader::InitInstance(void)
{
	return true;
}

void CTrapLogReader::ExitInstance(void)
{
}

void CTrapLogReader::Run(void)
{
	while (1)
	{
		KeepReadFile();
#ifdef WIN32
		SLEEP(1);
#else
		sleep(1);
#endif
	}
}

bool CTrapLogReader::OpenFile(void)
{
	if (m_strFilePath.length() == 0)
	{
		return false;
	}
	else
	{
		if ((m_pFile = fopen(m_strFilePath.c_str(), "r")) == NULL)
		{
			m_bReadFlag = false;
			m_iValidFlag = 0;
			return false;
		}

		/// 检索读取位置
		if (fseek(m_pFile, m_lReadPos, SEEK_SET) < 0)
		{
			printf("FileName %s lseek error\n", m_strFilePath.c_str());
			fflush(stdout);
			SAFE_FCLOSE(m_pFile);
			m_pFile = NULL;
			m_iValidFlag = READFILEINTERVAL;
			return false;
		}

		return true;
	}
}

void CTrapLogReader::KeepReadFile(void)
{
	size_t	rsize;
	struct stat filestat;

	if (m_pFile == NULL)
	{
		m_iValidFlag++;
		if (m_iValidFlag >= READFILEINTERVAL)
		{
			if (!OpenFile())
			{
				return;
			}
		}
		else
		{
			return;
		}
	}

	int iRtn = stat(m_strFilePath.c_str(), &filestat);

	if (iRtn < 0)	///stat文件失败，意味着该文件在打开过程中被删除，返回
	{
		printf("\tFileName %s stat error\n", m_strFilePath.c_str());
		fflush(stdout);
		SAFE_FCLOSE(m_pFile);
		m_iValidFlag = READFILEINTERVAL;	///stat失败后，下一次就立即尝试文件是否存在
		m_lReadPos = 0;
		return;
	}
	else if (filestat.st_size <= m_lReadPos)
	{
		if (m_tModify < filestat.st_mtime)	// 该文件可能被删除过内容，重新打开
		{
			SAFE_FCLOSE(m_pFile);
			m_lReadPos = 0;
			return;
		}
	}
	else if (filestat.st_size > m_lReadPos)
	{
		if (fseek(m_pFile, m_lReadPos, SEEK_SET) < 0)
		{
			printf("FileName %s lseek error\n", m_strFilePath.c_str());
			fflush(stdout);
			SAFE_FCLOSE(m_pFile);
			m_iValidFlag = READFILEINTERVAL;
			return;
		}

		m_tModify = filestat.st_mtime;

		int iLines = 0;
		char szBuf[SIZE_BUF];

		CTrapRecord Rec;
		memset(szBuf, 0x00, sizeof(szBuf));
		while ((fgets(szBuf, sizeof(szBuf) - 1, m_pFile)) != NULL)
		{
			printf("[%s]", szBuf);
			iLines++;
			m_lReadPos += strlen(szBuf);
			if (Rec.LoadRec(string(szBuf)))
			{
				m_listRecord.add(Rec);
			}

			memset(szBuf, 0x00, sizeof(szBuf));
		}

		m_bReadFlag = false;
	}
	else
	{
		m_bReadFlag = false;
	}

	printf("Get Here !\n");
}
