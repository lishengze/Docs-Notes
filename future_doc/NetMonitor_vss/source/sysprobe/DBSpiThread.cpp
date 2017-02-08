#include "DBSpiThread.h"

extern CManageConSession g_mManageConSession;	// �����������ӵĵ�ַ��Ϣ
#define DBSENDPACKAGETO g_mManageConSession.sendFTDCPackage(&m_pkgSend);

CDBSpiThread::CDBSpiThread(void) :
	m_bExit(false),
	m_iWork(0)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	pDatabaseSpi = new CDatabaseSpiImpl();
}

CDBSpiThread::~CDBSpiThread(void)
{
	m_bExit = true;
	delete pDatabaseSpi;
	pDatabaseSpi = NULL;
	ExitThread();
}

#if 0
void CDBSpiThread::UpdateDatabaseInfoMap(
	string	sConfigName,
	CDBConnectString sConnectString)
{
	pDatabaseSpi->UpdateDatabaseInfoMap(sConfigName, sConnectString);
	return;
}

void CDBSpiThread::UpdateDBAttrMap(
	const char	*pAttrName,
	const char	*pSeps,
	const char	*pDNSName,
	const char	*pTableName)
{
	pDatabaseSpi->UpdateDBAttrMap(pAttrName, pSeps, pDNSName, pTableName);
	return;
}

void CDBSpiThread::UpdateSPInfoMap(
	const char	*pSPName,
	const char	*pSeps,
	const char	*pDNSName,
	const char	*pSPType)
{
	pDatabaseSpi->UpdateSPInfoMap(pSPName, pSeps, pDNSName, pSPType);
	return;
}

void CDBSpiThread::UpdateDBLogMap(
	const char	*pTableName,
	const char	*pSeps,
	const char	*pDNSName,
	const char	*pPosition)
{
	pDatabaseSpi->UpdateDBLogMap(pTableName, pSeps, pDNSName, pPosition);
	return;
}

#endif
void CDBSpiThread::UpdateSPQuery(
	const char	*pObjectId,
	const char	*pAttrType,
	const DWORD dRequestId,
	const CFTDCSession	*pSession)
{
	pDatabaseSpi->UpdateSPQuery(pObjectId, pAttrType, dRequestId, pSession);
	return;
}

void CDBSpiThread::UpdateConfig(CFTDRspQryHostConfigField *hostConfig)
{
	pDatabaseSpi->UpdateConfig(hostConfig);
	return;
}

/**�麯�����������һЩʵ��������
* @return true:�����ɹ� false:����ʧ��
*/
bool CDBSpiThread::InitInstance(void)
{
	return true;
}

/**�麯�����������ʵ��
*/
void CDBSpiThread::ExitInstance(void)
{
}

/**�߳̿�ʼ���У����麯�����������̳�ʵ��
*/
void CDBSpiThread::Run(void)
{
	OSSleep(60);
	while (!m_bExit)
	{
		// ��ѯ���ݿ⣬ȡ�������Ϣ
		// ������ʹ�����������������ķ�Χ������DatabaseSpiImpl,��ֻ��Ҫ�����ٵĸı�Ϳ����ˣ�
		// ��Ȼ����Ҫ��DatabaseSpiImpl�ڲ����������������� ���ķ�Χ�� ��ż��ʾһ�ηŻصĶ���������һ�������Ĳ�ѯ�������������ͨѶ����
		pDatabaseSpi->GetDatabaseSpi(time((time_t *)NULL));
		OSSleep(1);
	}
}

void CDBSpiThread::GetSpi(void)
{
	TIME_MEASURE_START(__FUNCTION__);
	if (pDatabaseSpi != NULL)
	{
		pDatabaseSpi->m_dataLock.Lock();

		// �õ����� , �������ݷ���
		list<CDBQueryField>::iterator listIt;	// m_reqDbQuery;
		for (listIt = pDatabaseSpi->m_reqDbQuery.begin();
			 listIt != pDatabaseSpi->m_reqDbQuery.end();)
		{
			if (listIt->m_reqFlag)
			{
				// ���͸ýڵ�����ݵ��ͻ���
				CFTDRspInfoField rspInfoField;
				rspInfoField.ErrorID = listIt->m_rtnCode;
				rspInfoField.ErrorMsg = listIt->m_rtnMsg.c_str();

				if (listIt->m_rtnCode == 0)
				{
					list<CFTDRspQryDBQueryField>::iterator	queryIt = listIt->
						m_dbQuery.begin();
					while (queryIt != listIt->m_dbQuery.end())
					{
						m_pkgSend.PreparePackage(
								FTD_TID_RspQryDBQueryTopic,
								FTDC_CHAIN_CONTINUE,
								FTD_VERSION);
						m_pkgSend.SetRequestId(listIt->m_requestID);
						FTDC_ADD_FIELD(&m_pkgSend, &(*queryIt));
						queryIt++;
						if (queryIt == listIt->m_dbQuery.end())
						{
							m_pkgSend.SetChain(FTDC_CHAIN_LAST);
							FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
						}

						g_mManageConSession.sendFTDCPackage(
								&m_pkgSend,
								listIt->m_session);
					}
				}
				else
				{
					m_pkgSend.PreparePackage(
							FTD_TID_RspQryDBQueryTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
					m_pkgSend.SetRequestId(listIt->m_requestID);
					FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
					g_mManageConSession.sendFTDCPackage(
							&m_pkgSend,
							listIt->m_session);
				}

				pDatabaseSpi->m_reqDbQuery.erase(listIt++);
			}
			else
			{
				listIt++;
			}
		}

		deque<CFTDRtnObjectAttrField>::iterator it;
		m_pkgSend.PreparePackage(
				FTD_TID_RtnObjectAttrTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		for (it = pDatabaseSpi->m_attrInfo.begin();
			 it != pDatabaseSpi->m_attrInfo.end();
			 ++it)
		{
			if (m_pkgSend.Length() +
				sizeof(CFTDRtnObjectAttrField) >= FTDC_PACKAGE_MAX_SIZE)
			{
				DBSENDPACKAGETO;
				m_pkgSend.PreparePackage(
						FTD_TID_RtnObjectAttrTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
			}

			FTDC_ADD_FIELD(&m_pkgSend, &(*it));
		}

		if (m_pkgSend.Length() > 0)
		{
			DBSENDPACKAGETO;
		}

		pDatabaseSpi->m_attrInfo.clear();

		deque<CFTDRtnWarningEventField>::iterator eventIt;
		m_pkgSend.PreparePackage(
				FTD_TID_RtnWarningEventTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		for (eventIt = pDatabaseSpi->m_eventInfo.begin();
			 eventIt != pDatabaseSpi->m_eventInfo.end();
			 ++eventIt)
		{
			if (m_pkgSend.Length() +
				sizeof(CFTDRtnWarningEventField) >= FTDC_PACKAGE_MAX_SIZE)
			{
				DBSENDPACKAGETO;
				m_pkgSend.PreparePackage(
						FTD_TID_RtnWarningEventTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
			}

			FTDC_ADD_FIELD(&m_pkgSend, &(*eventIt));
		}

		if (m_pkgSend.Length() > 0)
		{
			DBSENDPACKAGETO;
		}

		pDatabaseSpi->m_eventInfo.clear();

		deque<CFTDRtnSyslogEventField>::iterator syslogIt;
		m_pkgSend.PreparePackage(
				FTD_TID_RtnSyslogEventTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		for (syslogIt = pDatabaseSpi->m_syslogInfo.begin();
			 syslogIt != pDatabaseSpi->m_syslogInfo.end();
			 ++syslogIt)
		{
			if (m_pkgSend.Length() +
				sizeof(CFTDRtnSyslogEventField) >= FTDC_PACKAGE_MAX_SIZE)
			{
				DBSENDPACKAGETO;
				m_pkgSend.PreparePackage(
						FTD_TID_RtnSyslogEventTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
			}

			FTDC_ADD_FIELD(&m_pkgSend, &(*syslogIt));
		}

		if (m_pkgSend.Length() > 0)
		{
			DBSENDPACKAGETO;
		}

		pDatabaseSpi->m_syslogInfo.clear();

		deque<CFTDRtnDBQueryField>::iterator dbqueryIt;
		for (dbqueryIt = pDatabaseSpi->m_dbqueryInfo.begin();
			 dbqueryIt != pDatabaseSpi->m_dbqueryInfo.end();
			 ++dbqueryIt)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnDBQueryTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &(*dbqueryIt));
			DBSENDPACKAGETO;
		}

		pDatabaseSpi->m_dbqueryInfo.clear();

		list<CFTDRtnUpdateSysConfigField>::iterator configIt;
		for (configIt = pDatabaseSpi->m_updateConfigInfo.begin();
			 configIt != pDatabaseSpi->m_updateConfigInfo.end();
			 ++configIt)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnUpdateSysConfigTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &(*configIt));
			DBSENDPACKAGETO;
		}

		pDatabaseSpi->m_updateConfigInfo.clear();

		pDatabaseSpi->m_dataLock.UnLock();
	}

	TIME_MEASURE_END(__FUNCTION__);
	return;
}
