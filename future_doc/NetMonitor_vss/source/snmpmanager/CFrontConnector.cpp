/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CFrontConnector.cpp
///@brief	ʵ�������Ӽ��ǰ��ͨ����Ϣ����
///@history
///20110116	LSC		�������ļ�
#include "CFrontConnector.h"
#include "ping_common.h"

CFrontConnector::CFrontConnector(CReactor *pReactor) :
	CSessionFactory(pReactor, 1)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	m_Flag = false;
}

CSession *CFrontConnector::CreateSession(CChannel *pChannel, DWORD dwMark)
{
	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	pSession->RegisterPackageHandler(this);
	return pSession;
}

void CFrontConnector::OnSessionConnected(CSession *pSession)
{
	CSessionFactory::OnSessionConnected(pSession);

	time_t	timep;
	time(&timep);
	printf(
		"\t %s CSynConnector::OnSessionConnected: %0x \n",
		ctime(&timep),
		pSession);
	fflush(stdout);
	m_Flag = true;
}

void CFrontConnector::OnSessionDisconnected(CSession *pSession, int nReason)	// �������ش������ӶϿ��¼�
{
	CSessionFactory::OnSessionDisconnected(pSession, nReason);	// ������ø��ദ�����ӶϿ��¼�
	time_t	timep;
	time(&timep);
	printf(
		"\t %s CSynConnector::OnSessionDisconnected: %0x \n",
		ctime(&timep),
		pSession);
	fflush(stdout);
	m_Flag = false;
}

int CFrontConnector::HandlePackage(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	printf(
		"\tCFlowConnector::HandlePackage:receive package %0x\n",
		pFTDCPackage->GetTID());
	fflush(stdout);
	switch (pFTDCPackage->GetTID())
	{
		case FTD_TID_ReqUserLogin:
			break;
		default:
			break;
	}

	return 0;
}

void CFrontConnector::OnRspUserLogin(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqUserLoginField fieldLogin;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldLogin);

	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);
	printf(
		"\t CSynConnector::OnRspUserLogin:user=%s password=%s ",
		(const char *)fieldLogin.UserID,
		(const char *)fieldLogin.Password);

	CFTDRspInfoField fieldRspInfo;
	fieldRspInfo.ErrorMsg = "�ɹ�";
	fieldRspInfo.ErrorID = 0;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldRspInfo);
	printf(
		" reponse msg %s ID %d\n",
		(const char *)fieldRspInfo.ErrorMsg,
		(const int)fieldRspInfo.ErrorID);
}
