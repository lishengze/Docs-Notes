// FlowReader.cpp: implementation of the CFlowReader class.
//
// 2007.7.5	�Ժ��	������GetNext�����������е�����ȡ��ָ���Ļ�������
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "FlowReader.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFlowReader::CFlowReader()
{
	m_pFlow = NULL;
	m_nCommPhaseNo = 0;
	m_nNextId = 0;	
}

CFlowReader::~CFlowReader()
{
	DetachFlow();
}

int CFlowReader::AttachFlow(CReadOnlyFlow *pFlow, int nStartId)
{
	m_pFlow = pFlow;
	m_nCommPhaseNo = pFlow->GetCommPhaseNo();	
	SetId(nStartId);
	return 0;
}

CReadOnlyFlow *CFlowReader::DetachFlow()
{
	CReadOnlyFlow *pFlow = m_pFlow;
	m_pFlow = NULL;
	return pFlow;
}

int CFlowReader::GetNext(void *pObject, int length)
{
	if(m_pFlow == NULL)
	{
		return -1;
	}

	WORD nCommPhaseNo = m_pFlow->GetCommPhaseNo();
	if (nCommPhaseNo != m_nCommPhaseNo)
	{
		SetId(0);
		m_nCommPhaseNo = nCommPhaseNo;
	}
	
	if (m_nNextId >= m_pFlow->GetCount())
	{
		return -1;
	}

	int len = m_pFlow->Get(m_nNextId, pObject, length);

	if(len >= 0)
	{
		SetId(1, FROM_HERE);
	}

	return len;
}

bool CFlowReader::GetNext(CPackage *pPackage)
{

	int len = GetNext(pPackage->Address(), pPackage->Length());

	if(len < 0)
	{
		return false;
	}

	pPackage->Truncate(len);
	pPackage->ValidPackage();

	return true;
}

