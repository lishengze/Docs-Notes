/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CounterConnector.cpp
///@brief	ʵ���������¼����������������÷�����ͨ����Ϣ����
///@history
///20080510	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
#include "CounterConnector.h"
#include "CStatusSubscriber.h"

//////////////////////////////////////////////////////////////////////////
//modify @ 20120920 feng.q
//extern CStatusSubscriber     *g_pStatusSubcriber;
//extern CCachedFileFlow *g_pFlow;
extern CStatusSubscriber *g_pStatusSubcriber;
extern string g_strTradeDay;
extern bool g_bChangeCutLineNextDay;

//////////////////////////////////////////////////////////////////////////
extern CSlogQuery *g_pSlogQuery;				// Slog��ѯ����ʵ��ָ�룬�л���������Ҫ���¹������
extern CFileOperation *g_fileOperation;			// ��д�ļ������ָ�룬�л���������Ҫ���¹���
extern map<string, long> g_mapFileReadSize;		// ����ÿ���ļ��Ѿ��յ��Ķ�дλ�ã��л���������Ҫ���
extern map<string, int> g_mapSlogFileName;		// ��ǰ���ڷ�����Slog�ļ�map���л�������ʱ��Ҫ���¹���
extern COrderRttAnalysis *g_OrderRttAnalysis;	// ������Ӧ�ٶȷ��������ָ�룬�л���������Ҫ���¹���
extern CSlogReactor *g_pReactor;				// ȫ��reactor����ָ�룬ֻ��һ�ι���
extern CDirectlySlogDecode	*g_CSlogDec;

extern map<int, int> m_mapSlogFileReadStatus;

#ifdef PACKAGE_OUTPUT
extern CLogger	*g_pPackOutput;					// ���ݰ�������ļ�
#endif

//
// ���������������ӵ���ʵ��

//
CCountConnector::CCountConnector(CReactor *pReactor) :
	CAgentSessionFactory(pReactor, 1)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
}

CSession *CCountConnector::CreateSession(CChannel *pChannel, DWORD dwMark)
{
	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	pSession->RegisterPackageHandler(this);
	return pSession;
}

void CCountConnector::OnSessionConnected(CSession *pSession)
{
	CAgentSessionFactory::OnSessionConnected(pSession);
	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);
	printf(
		"\tCountConnector::OnSessionConnected: %s\n",
		pSession->GetChannel()->GetRemoteName());

	m_pkgSend.PreparePackage(
			FTD_TID_ReqUserLogin,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDReqUserLoginField fieldLogin;
	memset(&fieldLogin, 0, sizeof(fieldLogin));
	fieldLogin.UserID = "slog";
	fieldLogin.Password = "slogpd";
	FTDC_ADD_FIELD(&m_pkgSend, &fieldLogin);

	CFTDDisseminationField	fieldDissemination;
	for (int i = 1; i < MAX_EVENTFLOWNUM + 1; i++)
	{
		printf(
			"\t Flow count %d\n",
			i,
			g_pStatusSubcriber->m_pSubEnd[i]->m_pFlow->GetCount());
		fflush(stdout);
		fieldDissemination.SequenceSeries = i;	// GetSequenceSeries();
		fieldDissemination.SequenceNo = g_pStatusSubcriber->m_pSubEnd[i]->m_pFlow->GetCount();	// GetReceivedCount();
		FTDC_ADD_FIELD(&m_pkgSend, &fieldDissemination);
		((CFTDCSession *)pSession)->RegisterSubscriber(
				g_pStatusSubcriber->m_pSubEnd[i]);
	}

	// 	printf("�����ļ� �� %s ������%d \n" , __FILE__, __LINE__);
	// 	printf("\t Flow count %d\n", g_pStatusSubcriber->GetReceivedCount());	
	// 	fieldDissemination.SequenceSeries = g_pStatusSubcriber->GetSequenceSeries();   // GetSequenceSeries();
	// 	fieldDissemination.SequenceNo =     g_pStatusSubcriber->GetReceivedCount();    // GetReceivedCount();
	// 	FTDC_ADD_FIELD(&m_pkgSend, &fieldDissemination);
	((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);

	// 	((CFTDCSession *)pSession)->RegisterSubscriber(g_pStatusSubcriber);
}

void CCountConnector::OnSessionDisconnected(CSession *pSession, int nReason)	// �������ش������ӶϿ��¼�
{
	CSessionFactory::OnSessionDisconnected(pSession, nReason);	// ������ø��ദ�����ӶϿ��¼�
	printf(
		"\tCCountConnector::OnSessionDisconnected: %0x\n",
		(CFTDCSession *)pSession);
}

int CCountConnector::HandlePackage(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PACKAGE_OUTPUT
	pFTDCPackage->OutputHeader(g_pPackOutput);
	FTDC_DEBUG_BODY(pFTDCPackage->GetTID(), pFTDCPackage, g_pPackOutput);
#endif
	switch (pFTDCPackage->GetTID())
	{
		case FTD_TID_RspUserLogin:
			OnRspUserLogin(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryTradeDayChangeTopic:
			OnReqQryTradeDayChange(pFTDCPackage, pSession);
			break;
		default:
			break;
	}

	return 0;
}

void CCountConnector::OnRspUserLogin(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspInfoField fieldRspInfo;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldRspInfo))
	{
		printf(
			"\tCCountConnector::OnRspUserLogin fieldRspInfo.ErrorMsg = %s\n",
			(const char *)fieldRspInfo.ErrorMsg);
	}

	// 	//��Ҫ�л�������
	// 	if (fieldChange.ChangeType == TRUNCATEFLOW
	// 		&& m_strTradeDay != ""
	// 		&& fieldChange.NewDate != m_strTradeDay.data())
	// 	{
	//
	// 	}
	//
	// 	m_strTradeDay = fieldChange.NewDate.getValue();
}

void CCountConnector::OnReqQryTradeDayChange(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryTradeDayChangeField fieldChange;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldChange);

	//....
	if (strcmp(fieldChange.ChangeType.getValue(), TRUNCATEFLOW) == 0)
	{
		//modify by feng.q @20120920
		// ���ö�Ӧ�ñ�ŵ���������0�����¼����������¶�����
		printf("������Ϊ %s ��������\n", (const char *)fieldChange.OldDate);

		int nSeq = atoi((const char *)fieldChange.OldDate);
		nSeq++;
		if (nSeq > MAX_EVENTFLOWNUM)
		{
			return;
		}

		if (g_pStatusSubcriber != NULL
		&&	g_pStatusSubcriber->m_pSubEnd[nSeq] != NULL)
		{
			g_pStatusSubcriber->m_pSubEnd[nSeq]->m_pFlow->Truncate(0);
		}

		// 		if (nSeq!=g_pStatusSubcriber->GetSequenceSeries())
		// 		{
		// 			return;
		// 		}
		// 		if (g_pFlow!=NULL) g_pFlow->Truncate(0);
		m_pkgSend.PreparePackage(
				FTD_TID_ReqUserLogin,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		CFTDReqUserLoginField fieldLogin;
		memset(&fieldLogin, 0, sizeof(fieldLogin));
		fieldLogin.UserID = "slog";
		fieldLogin.Password = "querypd";
		FTDC_ADD_FIELD(&m_pkgSend, &fieldLogin);

		CFTDDisseminationField	fieldDissemination;
		fieldDissemination.SequenceSeries = nSeq;				// GetSequenceSeries();
		fieldDissemination.SequenceNo = g_pStatusSubcriber->m_pSubEnd[nSeq]->m_pFlow->GetCount();	// GetReceivedCount();
		FTDC_ADD_FIELD(&m_pkgSend, &fieldDissemination);
		((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);
		((CFTDCSession *)pSession)->RegisterSubscriber(
				g_pStatusSubcriber->m_pSubEnd[nSeq]);
	}
	else if (strcmp(fieldChange.ChangeType.getValue(), CHANGETRADEDAY) == 0)						// ���������մ���
	{
		//1.��������յ����������¼����������¶�����
		// 		if (g_pFlow!=NULL) g_pFlow->Truncate(0);
		// 		m_pkgSend.PreparePackage(FTD_TID_ReqUserLogin, FTDC_CHAIN_LAST, FTD_VERSION);
		// 		CFTDReqUserLoginField fieldLogin;
		// 		memset(&fieldLogin, 0, sizeof(fieldLogin));
		// 		fieldLogin.UserID = "query";
		// 		fieldLogin.Password = "querypd";
		// 		FTDC_ADD_FIELD(&m_pkgSend, &fieldLogin);
		// 		CFTDDisseminationField fieldDissemination;
		// 		fieldDissemination.SequenceSeries = g_pStatusSubcriber->GetSequenceSeries();   // GetSequenceSeries();
		// 		fieldDissemination.SequenceNo =     g_pStatusSubcriber->GetReceivedCount();    // GetReceivedCount();
		// 		FTDC_ADD_FIELD(&m_pkgSend, &fieldDissemination);
		// 		((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);
		// 		((CFTDCSession *)pSession)->RegisterSubscriber(g_pStatusSubcriber);
		//2.������ص����ɵ�Slog�ļ���ɾ���ļ�
		if (g_strTradeDay != ""
		&&	fieldChange.NewDate != ""
		&&	g_strTradeDay != fieldChange.NewDate.getValue())
		{
			g_mapFileReadSize.clear();
			g_mapSlogFileName.clear();
			if (g_fileOperation != NULL)
			{
				delete g_fileOperation;
				g_fileOperation = new CFileOperation();
			}
			else
			{
				g_fileOperation = new CFileOperation();
			}

			//3.������ص�Slog�Ự��ɾ������Slog��������Ϣ
			if (g_OrderRttAnalysis != NULL)
			{
				delete g_OrderRttAnalysis;
				g_OrderRttAnalysis = new COrderRttAnalysis();	// ��Ӧ�ٶȷ��������ָ��
			}
			else
			{
				g_OrderRttAnalysis = new COrderRttAnalysis();
			}

			m_mapSlogFileReadStatus.clear();

			g_pReactor->Clear();

			g_CSlogDec->Clear();

			//4.������ر����m_mapSlog���ݰ�����
			if (g_pSlogQuery != NULL)
			{
				delete g_pSlogQuery;
			}

			g_pSlogQuery = new CSlogQuery();					// ��ʼ����ѯʵ��ָ��
		}

		g_strTradeDay = fieldChange.NewDate.getValue();

		if (g_bChangeCutLineNextDay && g_pStatusSubcriber)
		{
		//	g_pStatusSubcriber->InitTradeOrderCutLine();
		}
	}
}
