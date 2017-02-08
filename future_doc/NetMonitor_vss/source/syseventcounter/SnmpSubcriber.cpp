/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	SnmpSubcriber.cpp
///@brief	实现了事件计算服务器订阅snmpmanager的类
///@history
///20100910	周建军		创建该文件
#include "SnmpSubcriber.h"
#include "EventCounterServer.h"

#ifdef PACKAGE_OUTPUT
extern CLogger	*g_pPackOutput;					// 数据包输出到文件
#endif
extern char g_mFlowPath[200];					//保存流文件存储路径
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

WORD CSnmpSubscriber::GetSequenceSeries(void)	//流编号
{
	return m_nFlowSeq;
}

DWORD CSnmpSubscriber::GetReceivedCount(void)	//收到的包个数
{
	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
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
