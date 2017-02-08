// ChannelPackage.cpp: implementation of the CChannelPackage class.
//
//////////////////////////////////////////////////////////////////////

#include "public.h"
#include "ChannelPackage.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChannelPackage::CChannelPackage(int nPackageMaxSize)
{
	ConstructAllocate(nPackageMaxSize, 0);
}

CChannelPackage::~CChannelPackage()
{

}

DWORD CChannelPackage::GetActiveID()
{
	//ActiveID 永远是0
	return 0;
}

int CChannelPackage::ValidPackage()
{
	//总是完整的数据包
	return Length();
}

int CChannelPackage::ReadFromChannel(CChannel *pChannel)
{
	int nReadLen = 0;
	if (pChannel->GetType() == CT_STREAM)
	{
		int n=m_pHead-m_pPackageBuffer->Data();
		memmove(m_pPackageBuffer->Data(),m_pHead,Length());
		m_pHead-=n;
		m_pTail-=n;

		int nCount=m_pPackageBuffer->Length()-Length();
		nReadLen=pChannel->Read(nCount,m_pTail);
		if(nReadLen>0){
			m_pTail+=nReadLen;
		}
	}
	else
	{
		m_pTail = m_pHead = m_pPackageBuffer->Data();
		
		nReadLen = pChannel->Read(m_pPackageBuffer->Length(), m_pTail);
		if(nReadLen>0){
			m_pTail+=nReadLen;
		}
	}
	
	return nReadLen;
}
