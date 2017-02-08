/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	SnmpSubcriber.cpp
///@brief	ʵ�����¼��������������snmpmanager����
///@history
///20100910	�ܽ���		�������ļ�
#include "SnmpSubcriber.h"
#include "EventCounterServer.h"

#ifdef PACKAGE_OUTPUT
extern CLogger	*g_pPackOutput;					// ���ݰ�������ļ�
#endif
extern char g_mFlowPath[200];					//�������ļ��洢·��
CSnmpSubscriber::CSnmpSubscriber(
	int nFLowSeq,
	int nManagerId,
	CEventCounterServer *pEventCounterServer)
{
	m_nFlowSeq = nFLowSeq + 1;
	m_nManagerId = nManagerId;

	char buffer[32];
	sprintf(buffer, "snmp_%d_%d", nManagerId, m_nFlowSeq);

	//m_pFlow = new CCachedFileFlow("fibResultFlow",g_mFlowPath,true,100,32*1024);
	m_pFlow = new CCachedFileFlow(buffer, g_mFlowPath, true, 100, 32 * 1024);
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	m_pSession = NULL;
	m_pEventCounterServer = pEventCounterServer;
}

CSnmpSubscriber::~CSnmpSubscriber(void)
{
	delete m_pFlow;
}

void CSnmpSubscriber::SetCommPhaseNo(WORD wCommPhaseNo)
{
}

WORD CSnmpSubscriber::GetSequenceSeries(void)	//�����
{
	return m_nFlowSeq;
}

DWORD CSnmpSubscriber::GetReceivedCount(void)	//�յ��İ�����
{
	//printf("�����ļ� �� %s ������%d \n" , __FILE__, __LINE__);
	return m_pFlow->GetCount();
}

void CSnmpSubscriber::HandleMessage(CFTDCPackage *pFTDCPackage)
{
	//printf("\t CSnmpSubscriber::HandleMessage: %0x\n", m_pSession);
	//#ifdef PACKAGE_OUTPUT
	//	pFTDCPackage->OutputHeader(g_pPackOutput);
	//	FTDC_DEBUG_BODY(pFTDCPackage->GetTID(), pFTDCPackage, g_pPackOutput);
	//#endif
	m_pEventCounterServer->HandlePackage(pFTDCPackage, m_pSession);

	pFTDCPackage->Push(FTDCHLEN);
	m_pFlow->Append(pFTDCPackage->Address(), pFTDCPackage->Length());
}
