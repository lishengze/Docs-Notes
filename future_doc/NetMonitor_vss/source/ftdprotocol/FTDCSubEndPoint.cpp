// FTDCSubEndPoint.cpp: implementation of the CFTDCSubEndPoint class.
//
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "FTDCSubEndPoint.h"
#include "FTDCPackage.h"

const DWORD NAK_TIMEOUT	= 100;			//ÿһ��NAK��NAK_TIMEOUT����󷢳����Ժ�ʱ�ӱ�
const DWORD RECV_HEARTBEAT_TIMEOUT	= 2000;	//����������ʱʱ�䣬��λΪ����

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFTDCSubEndPoint::CFTDCSubEndPoint(CFTDCSubscriber *pSubscriber)
{
	m_pSubscriber = pSubscriber;
}

CFTDCSubEndPoint::~CFTDCSubEndPoint()
{

}

int CFTDCSubEndPoint::HandlePackage(CFTDCPackage *pFTDCPackage)
{
	if (pFTDCPackage->GetFTDCHeader()->SequenceNumber != m_pSubscriber->GetReceivedCount()+1)
	{	
		return -1;
	}

	m_pSubscriber->HandleMessage(pFTDCPackage);
	return 0;
}
