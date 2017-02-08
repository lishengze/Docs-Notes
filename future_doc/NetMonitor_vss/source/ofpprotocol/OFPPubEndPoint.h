// OFPPubEndPoint.h: interface for the COFPPubEndPoint class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OFPPUBENDPOINT_H__93E840F9_7AEE_406D_A53E_283C938D4713__INCLUDED_)
#define AFX_OFPPUBENDPOINT_H__93E840F9_7AEE_406D_A53E_283C938D4713__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Protocol.h"
#include "FlowReader.h"
#include "OFPPackage.h"

class COFPPubEndPoint 
{
public:
	COFPPubEndPoint(CReadOnlyFlow *pFlow, WORD nSequenceSeries, int nStartId,
								 CProtocol *pSendProtocol);
	virtual ~COFPPubEndPoint();
	void MoveTo(int nOffset);
	int PublishSend();
	inline WORD GetSequenceSeries();
private:
	CPackage *GetNextDataPackage();
private:
	WORD m_nSequenceSeries;
	CReadOnlyFlow *m_pFlow;
	CProtocol *m_pSendProtocol; 
	COFPPackage m_SendPackage;
	CFlowReader m_flowReader;
};

inline WORD COFPPubEndPoint::GetSequenceSeries()
{
	return m_nSequenceSeries;
}

#endif // !defined(AFX_OFPPUBENDPOINT_H__93E840F9_7AEE_406D_A53E_283C938D4713__INCLUDED_)
