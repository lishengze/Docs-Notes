/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CSlogConnection.h
///@brief	定义了数据包过滤的类
///@auther	赵鸿昊
///@history
#ifndef REF_CSLOGCONNECTION_H
#define REF_CSLOGCONNECTION_H

#include "public.h"
#include "FTDCSession.h"
#include "OFPSession.h"
#include "FtdPackageDesc.h"
#include "FTDCPackage.h"
#include "CSVParser.h"
#include "Storage.h"
#include "OfpData.h"
#include "FtdPackageDesc.h"
#include "CDate.h"

#include "CDumpSession.h"

class CSlogChannel :
	public CChannel
{
	/* */
	public:
		CSlogChannel(int nID, CCacheList *pCacheList) :
		CChannel(CT_STREAM, nID)
		{
			assert(pCacheList);
			m_pCacheList = pCacheList;
		}

	/* */
	protected:
		virtual int ReadImp(int number, char *buffer)
		{
			assert(buffer);

			char *pData = (char *)m_pCacheList->GetData(number);
			if (pData == NULL)
			{
				return 0;
			}

			memcpy(buffer, pData, number);
			m_pCacheList->PopFront(number);

			return number;
		}

		virtual int WriteImp(int number, char *buffer)
		{
			return -1;
		}

		virtual bool AvailableImp(void)
		{
			return 0;
		}

		virtual bool DisconnectImp(void)
		{
			return false;
		}

		virtual bool CheckConnectionImp(void)
		{
			return true;
		}

	/* */
	private:
		CCacheList	*m_pCacheList;
};

class CSlogConnection
{
	/* */
	public:
		CSlogConnection(
		int nID,
		const char	*pszIPAddress,
		int nFrontID,
		int nFileID,
		char cVersion) :
		m_cacheRead(64 * 1024),
		m_cacheWrite(64 * 1024)
		{
			m_nID = nID;
			m_nFrontID = nFrontID;
			m_nFileID = nFileID;
			m_cVersion = cVersion;
			m_strIPAddress = pszIPAddress;
			m_pReadSession = NULL;
			m_pWriteSession = NULL;
		}

		virtual~CSlogConnection(void)
		{
			delete m_pReadSession;
			delete m_pWriteSession;
		}

		bool CreateSession(CReactor *pReactor, const char *pszSessionType)
		{
			if (strstr(pszSessionType, "ftd"))
			{
				m_pReadSession = new CFtdcDumpSession(
						pReactor,
						new CSlogChannel(m_nID, &m_cacheRead),
						m_nFrontID,
						m_nFileID,
						m_strIPAddress,
						"[READ]");
				m_pWriteSession = new CFtdcDumpSession(
						pReactor,
						new CSlogChannel(m_nID, &m_cacheWrite),
						m_nFrontID,
						m_nFileID,
						m_strIPAddress,
						"[WRITE]");
			}
			else if (strstr(pszSessionType, "ofp"))
			{
				m_pReadSession = new COfpDumpSession(
						pReactor,
						new CSlogChannel(m_nID, &m_cacheRead),
						m_nFrontID,
						m_nFileID,
						m_strIPAddress,
						m_cVersion,
						"[READ]");
				m_pWriteSession = new COfpDumpSession(
						pReactor,
						new CSlogChannel(m_nID, &m_cacheWrite),
						m_nFrontID,
						m_nFileID,
						m_strIPAddress,
						m_cVersion,
						"[WRITE]");
			}
			else
			{
				return false;
			}

			// 不再由m_IOlist驱动，由CSlogReactor::GetSlogConnection直接驱动
			//		pReactor->RegisterIO(m_pReadSession);
			//		pReactor->RegisterIO(m_pWriteSession);
			return true;
		}

		void OnConnected(const char *pszTime);

		void OnChannelRead(
				const char	*pszTime,
				const char	*pData,
				const int nDataLen);

		void OnChannelWrite(
				const char	*pszTime,
				const char	*pData,
				const int nDataLen);

		void OnReadError(const char *pszTime)
		{
			Output("READ_ERROR", pszTime);
		}

		void OnWriteError(const char *pszTime)
		{
			Output("WRIT_EERROR", pszTime);
		}

		void OnDisconnected(const char *pszTime)
		{
			Output("DISCONNECT", pszTime);
		}

		void OnDisconnectedRead(const char *pszTime)
		{
			Output("DISCONNECTED_READ", pszTime);
		}

		void OnDisconnectedWrite(const char *pszTime)
		{
			Output("DISCONNECTED_WRITE", pszTime);
		}

		void OnDupSocketID(const char *pszTime)
		{
			Output("DUP_SOCKET_ID", pszTime);
		}

		void Output(const char *pszEventStr, const char *pszTime);

		const char *GetIPAddress(void)
		{
			return m_strIPAddress.c_str();
		}

	/* */
	protected:
		string	m_strIPAddress;
		int m_nID;
		int m_nFrontID;
		int m_nFileID;
		char m_cVersion;
		CCacheList	m_cacheRead;
		CCacheList	m_cacheWrite;
		CSession *m_pReadSession;
		CSession *m_pWriteSession;
};
#endif // end REF_CSLOGCONNECTION_H
