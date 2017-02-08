/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CSlogConnection.cpp
///@brief	定义了数据包过滤的类
///@auther	赵鸿昊
///@history
#include "CSlogConnection.h"
#include "CPackageFilter.h"

extern CPackageFilter g_PackageFilter;

void CSlogConnection::OnConnected(const char *pszTime)
{
	if (g_PackageFilter.CheckEventOutput())
	{
		// 		g_pLoggerOutput->output(LL_DEBUG, "\n[%s]:[%s][%08X][%s]\n",
		// 			"CONNECTED", pszTime, m_nID, m_strIPAddress.c_str());
	}
}

void CSlogConnection::OnChannelRead(
	const char	*pszTime,
	const char	*pData,
	const int nDataLen)
{
	if (g_PackageFilter.CheckEventOutput())
	{
		// 		g_pLoggerOutput->output(LL_DEBUG, "\n[%s]:[%s][%08X][%d][%s]\n",
		// 			"READ", pszTime, m_nID, nDataLen, m_strIPAddress.c_str());
	}

	m_cacheRead.PushBack((void *)pData, nDataLen);
	m_pReadSession->HandleInput();
}

void CSlogConnection::OnChannelWrite(
	const char	*pszTime,
	const char	*pData,
	const int nDataLen)
{
	if (g_PackageFilter.CheckEventOutput())
	{
		// 		g_pLoggerOutput->output(LL_DEBUG, "\n[%s]:[%s][%08X][%d][%s]\n",
		// 			"WRITE", pszTime, m_nID, nDataLen, m_strIPAddress.c_str());
	}

	m_cacheWrite.PushBack((void *)pData, nDataLen);
	m_pWriteSession->HandleInput();
}

void CSlogConnection::Output(const char *pszEventStr, const char *pszTime)
{
	if (g_PackageFilter.CheckEventOutput())
	{
		// 		g_pLoggerOutput->output(LL_DEBUG, "\n[%s]:[%s][%08X][%s]\n",
		// 			pszEventStr, pszTime, m_nID, m_strIPAddress.c_str());
	}
}
