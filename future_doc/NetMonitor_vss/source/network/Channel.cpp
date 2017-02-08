// Channel.cpp: implementation of the CChannel class.
//
// 2006.10.11	赵鸿昊	为支持SSL，增加方法 GetRemoteCommonName 
// 20110901 赵鸿昊 NT-0150 SLOG记录头中增加微秒字段，以提高计时精度
///20120726 江鹏   对于不安全函数进行了对应安全版本的封装：localtime、inet_ntoa
//////////////////////////////////////////////////////////////////////

#include "public.h"
#include "Channel.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChannel::CChannel(TChannelType type, int id)
{
	m_nType=type;
	m_nID=id;
	m_bConnected=true;
	m_fpLog = NULL;
	strcpy(m_RemoteName, "");
}

CChannel::~CChannel()
{
}

int CChannel::Read(int number, char *buffer)
{
	int readNumber;
	if (!m_bConnected)
	{
		WriteLog(CLRT_DISCONNECTED_READ, 0, NULL);
		return -1;
	}
	readNumber=ReadImp(number,buffer);
	if (readNumber >= 0)
	{
		WriteLog(CLRT_READ, readNumber, buffer);
	}
	else
	{
		WriteLog(CLRT_READ_ERROR, 0, NULL);
	}
	return readNumber;
}

int CChannel::Write(int number, char *buffer)
{
	int writeNumber;
	if (!m_bConnected)
	{
		WriteLog(CLRT_DISCONNECTED_WRITE, 0, NULL);
		return -1;
	}
	writeNumber=WriteImp(number,buffer);
	if (writeNumber >= 0)
	{
		WriteLog(CLRT_WRITE, writeNumber, buffer);
	}
	else
	{
		WriteLog(CLRT_WRITE_ERROR, 0, NULL);
	}
	return writeNumber;
}

bool CChannel::Available(void)
{
	if (!m_bConnected)
		return 0;
	return AvailableImp();
}

bool CChannel::Disconnect()
{
	if (!m_bConnected)
		return 0;
	m_bConnected=DisconnectImp();
	WriteLog(CLRT_DISCONNECT, 0, NULL);
	return m_bConnected;
}

bool CChannel::CheckConnection()
{
	if (!m_bConnected)
	{
		return false;
	}
	m_bConnected=CheckConnectionImp();
	return m_bConnected;
}

int CChannel::GetSelectId(void)
{
	return m_nID;
}

char *CChannel::GetRemoteName(void)
{
	return m_RemoteName;
}

char *CChannel::GetRemoteCommonName(void)
{
	return NULL;
}

void CChannel::SetLogFile(FILE *fp)
{
	m_fpLog = fp;
	char *pszRemoteName = GetRemoteName();
	WriteLog(CLRT_CONNECTED, strlen(pszRemoteName)+1, pszRemoteName);
}

void CChannel::WriteLog(WORD wType, WORD wDataLength, const char *pData)
{
	if (m_fpLog != NULL)
	{
		TChannelLogHeader header;
		header.dwId = (DWORD)GetId();
		header.wType = wType;
		GetPreciseTime(header.dwTime, header.dwUsec);
		if (wDataLength > 0)
		{
			header.wLength = wDataLength;
		}
		else
		{
			header.wLength = 0;
		}
		header.ChangeEndian();
		fwrite(&header, sizeof(header), 1, m_fpLog);
		if (wDataLength > 0)
		{
			fwrite(pData, 1, wDataLength, m_fpLog);
		}
		fflush(m_fpLog);
	}
}
