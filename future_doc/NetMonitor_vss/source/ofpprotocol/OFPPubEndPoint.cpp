// OFPPubEndPoint.cpp: implementation of the COFPPubEndPoint class.
//
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "OFPPubEndPoint.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

COFPPubEndPoint::COFPPubEndPoint(CReadOnlyFlow *pFlow, WORD nSequenceSeries, int nStartId,
								 CProtocol *pSendProtocol)
{
	m_pFlow = pFlow;
	m_nSequenceSeries = nSequenceSeries;
	m_pSendProtocol = pSendProtocol;
	m_SendPackage.ConstructAllocate(OFP_PACKAGE_MAX_SIZE, 1000);
	m_flowReader.AttachFlow(pFlow, nStartId);
}

COFPPubEndPoint::~COFPPubEndPoint()
{
}

CPackage *COFPPubEndPoint::GetNextDataPackage()
{
	m_SendPackage.AllocateMax();
	if(m_flowReader.GetNext(&m_SendPackage))
	{
		m_SendPackage.SetFlowType(m_nSequenceSeries);
		return &m_SendPackage;
	}
	return NULL;
}

void COFPPubEndPoint::MoveTo(int nOffset)
{
	if (m_flowReader.GetId() == nOffset)
	{
		return;
	}
	m_flowReader.SetId(nOffset);
}

int COFPPubEndPoint::PublishSend()
{
	int nCount = 0;
	for(; nCount<40; nCount++)
	{
		CPackage *pPackage = GetNextDataPackage();	
		if (pPackage == NULL)
		{
			break;
		}
		if (m_pSendProtocol->Send(pPackage) != 0)
		{
			break;
		}			
	}	
	return nCount;
}

