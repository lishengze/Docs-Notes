// FTDCProtocl.h: interface for the CFTDCProtocl class .
//
// 20110224 ����   NT-0125:����mdkernel���û�logout֮�����յ����������
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FTDCPROTOCOL_H__C5C04921_6D0B_11D7_BB64_444553540000__INCLUDED_)
#define AFX_FTDCPROTOCOL_H__C5C04921_6D0B_11D7_BB64_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "Protocol.h"
#include "FTDCPackage.h"
#include "HashMap.h"
#include "FTDCPubEndPoint.h"
#include "FTDCSubEndPoint.h"

#define MSG_FTDCERR_BADPACKAGE		0xA001

/**Э��ջ�����ĵڵ�����Э�飬��Ҫ��FTDC���Ĵ���
*/
class  CFTDCProtocol : public CProtocol  
{
public:
	/**���캯��
	* @param pReactor ָ�����������ָ��
	* @param pBelow    �²�Э���ָ��
	* @param nActiveId ���²�Э����ԣ�����Э���Э��Id
	*/
	CFTDCProtocol(CReactor *pReactor);
	
	/**��������
	*/
	virtual ~CFTDCProtocol();

	virtual int Pop(CPackage *pPackage);
	
	/**��������ı��ķ��ͳ�ȥ
	*/
	void PublishSend();

	/**�յ�һ����������ݰ�ʱ����
	* @param pPackage ��������ݰ�
	* @return 0   �ɹ�
	* @return <>0 ʧ��
	*/
	virtual int OnRecvErrorPackage(CPackage *pPackage);

	void Publish(CReadOnlyFlow *pFlow, WORD nSequenceSeries, int nStartId);
	void UnPublish(WORD nSequenceSeries);
	void RegisterSubscriber(CFTDCSubscriber *pSubscriber);
	void UnRegisterSubscriber(CFTDCSubscriber *pSubscriber);
	void SetCommPhaseNo(WORD wCommPhaseNo);

	void Clear();

	/**
	 * ��ѯ���еĶ�������
	 * @param topics ���붩�ĵ�����
	 */
	void QuerySubscribeTopic(vector<WORD>* topics);	
	
private:
	CFTDCSubEndPoint *GetSubEndPoint(WORD nSequenceSeries);
	CFTDCPubEndPoint *GetPubEndPoint(WORD nSequenceSeries);

private:
	typedef CHashMap<WORD, CFTDCSubEndPoint *, HashInt> CSubEndPointMap;
	CSubEndPointMap m_mapSubEndPoint;

	typedef CHashMap<WORD, CFTDCPubEndPoint *, HashInt> CPubEndPointMap;
	CPubEndPointMap m_mapPubEndPoint;
};

#endif // !defined(AFX_FTDCPROTOCOL_H__C5C04921_6D0B_11D7_BB64_444553540000__INCLUDED_)
