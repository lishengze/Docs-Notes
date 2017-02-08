// SCPPackage.cpp: implementation of the CSCPPackage class.
//
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "SCPPackage.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSCPPackage::CSCPPackage()
{
}

CSCPPackage::~CSCPPackage()
{

}

DWORD CSCPPackage::GetActiveID()
{
	return 0;
}

int CSCPPackage::ValidPackage()
{
	int pklen = Length();
	if(Length()<SCPHLEN)
		return -1;			//��ͷ���Ȳ���
	
	m_header.FromStream(m_pHead);

	if(m_header.ContentLength!=Length()-SCPHLEN)
	{
		return -2;			//���峤�����ͷ����
	}

	Pop(SCPHLEN);

	return m_header.ContentLength+SCPHLEN;
}

int CSCPPackage::MakePackage()
{
	m_header.ContentLength = Length();

	char *buf = Push(SCPHLEN);
	if(buf == NULL)
	{
		RAISE_DESIGN_ERROR("package buffer too small");
	}

	m_header.ToStream(buf);

	return 0;
}

CSCPPackage *CSCPPackage::Clone()
{
	CSCPPackage *pNewPackage = new CSCPPackage();
	*pNewPackage = *this;
	pNewPackage->DupPackageBuffer(this);
	return pNewPackage;
}


