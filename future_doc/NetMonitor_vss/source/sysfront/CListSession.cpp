/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CListSession.cpp
///@brief	实现了会话列表类
///@history	
///20080514	周建军		创建该文件
///20080623	周建军		修订注释
/////////////////////////////////////////////////////////////////////////
#include "CListSession.h"
extern int	g_iObjectAttrSize;
CListSessionArray *g_pListSessionArray = NULL;

CListSession::CListSession(void)
{
	m_mSessionList.clear();
}

CListSession::~CListSession(void)
{
	m_mSessionList.clear();
}

void CListSession::AddFlow(CFTDCSession *pFlow)
{
	for (m_mListIt = m_mSessionList.begin();
		 m_mListIt != m_mSessionList.end();
		 ++m_mListIt)
	{
		if (*m_mListIt == pFlow)
		{
			printf(
				"\tpCListSession::AddSession:Session %d 在list中已经存在",
				pFlow);
			fflush(stdout);
			return;
		}
	}

	m_mSessionList.push_back(pFlow);
}

void CListSession::DelFlow(CFTDCSession *pFlow)
{
	for (m_mListIt = m_mSessionList.begin();
		 m_mListIt != m_mSessionList.end();
		 ++m_mListIt)
	{
		if (*m_mListIt == pFlow)
		{
			m_mSessionList.erase(m_mListIt);
			printf(
				"\tpCListSession::DelSession:Session %d 在list中删除\n",
				pFlow);
			fflush(stdout);
			return;
		}
	}

	//printf("\tpCListSession::AddFlow:Session %d 在list中已经不存在\n", pFlow);
}

void CListSession::SendPackage(CFTDCPackage *pFTDCPackage, const char *pHashKey)
{
	int i = 0;
	for (m_mListIt = m_mSessionList.begin();
		 m_mListIt != m_mSessionList.end();
		 ++m_mListIt)
	{
		CFTDCSession *pSession = *m_mListIt;

		//printf("CListSession::SendPackage:包长度 %d 订阅个数 %d ObjectId %s\n",pFTDCPackage->Length(),i, (char *)pHashKey);
		pSession->SendRequestPackage(pFTDCPackage);
		pFTDCPackage->Pop(FTDCHLEN);
		i++;
	}
}

CListSessionArray::CListSessionArray(void)
{
	m_pObjectAttrCountIndex = new CIntMonitorIndex("ObjectAttrCount", 20);
	m_pObjectAttrCountIndex->setValue(0);

	/// 20101209凌晨非实时业务监控系统对象指标数到达30000，前置退出
		/// 为保留足够预备空间，将对象个数从30000调整到100000
	m_mHashSize = 100000;
	m_pList = new CMapSession[m_mHashSize];
}

CListSessionArray::CListSessionArray(int iSize)
{
	m_pObjectAttrCountIndex = new CIntMonitorIndex("ObjectAttrCount", 20);
	m_pObjectAttrCountIndex->setValue(0);

	m_mHashSize = iSize;
	m_pList = new CMapSession[m_mHashSize];
}

CListSessionArray::~CListSessionArray(void)
{
	delete[] m_pList;
}

void CListSessionArray::AddSubcriberObject(CFTDCSession *pFlow, char *pHashKey)
{
	int mHashValue = m_mStringIdMap.getStringId(pHashKey);
	m_pList[mHashValue].AddFlow(pFlow);
	m_pObjectAttrCountIndex->setValue(m_mStringIdMap.getListSize());
}

void CListSessionArray::DelSubcriberObject(CFTDCSession *pFlow, char *pHashKey)
{
	int mHashValue = m_mStringIdMap.getStringId(pHashKey);
	m_pList[mHashValue].DelFlow(pFlow);
}

void CListSessionArray::DelFTDSession(CFTDCSession *pFlow)
{
	for (int i = 0; i < m_mHashSize; i++)
	{
		m_pList[i].DelFlow(pFlow);
	}
}

void CListSessionArray::SendPackage(
	CFTDCPackage *pFTDCPackage,
	const char	*pHashKey)
{
	//int mHashValue = cal_crc((char *)pHashKey, strlen(pHashKey))%m_mHashSize;
	int mHashValue = m_mStringIdMap.getStringId(pHashKey);
	if (mHashValue == m_mHashSize)
	{
		printf("CListSessionArray Size Beyond");
		fflush(stdout);
		exit(1);
	}

	m_pList[mHashValue].SendPackage(pFTDCPackage, pHashKey);
}

void CListSessionArray::SetListSize(int iListSize)
{
	m_mHashSize = iListSize;
}
