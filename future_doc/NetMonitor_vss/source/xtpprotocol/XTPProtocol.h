// XTPProtocl.h: interface for the CXTPProtocl class .
//
// 20110624 ����   NT-0139 �ӿ���Ӧʱ��
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XTPPROTOCOL_H__C5C04921_6D0B_11D7_BB64_444553540000__INCLUDED_)
#define AFX_XTPPROTOCOL_H__C5C04921_6D0B_11D7_BB64_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "Protocol.h"
#include "XTPPackage.h"
#include "HashMap.h"
#include "XTPPubEndPoint.h"
#include "XTPSubEndPoint.h"

#define MSG_XTPERR_BADPACKAGE		0x3001

/**Э��ջ�����ĵڵ�����Э�飬��Ҫ��XTP���Ĵ���
*/
class  CXTPProtocol : public CProtocol  
{
public:
	/**���캯��
	* @param pReactor ָ�����������ָ��
	* @param pPubHelper    �²�Э���ָ��
	* @param nActiveId ���²�Э����ԣ�����Э���Э��Id
	*/
	CXTPProtocol(CReactor *pReactor, CXTPPubHelper *pPubHelper, CXTPSubHelper *pSubHelper);
	
	/**��������
	*/
	virtual ~CXTPProtocol();

	/**�������͵����ʵ��ϲ�Э��
	* @param pPackage ��Ҫ�ϴ��İ���ָ��
	* @return 0   �ɹ�
	* @return <>0 ʧ��
	*/
	virtual int Pop(CPackage *pPackage);
	
	/**����ʱ��������CReactor����
	* @param nIDEvent ��ʱ���¼���ʶ   
	*/
	virtual void OnTimer(int nIDEvent);

	/**�յ�һ����������ݰ�ʱ����
	* @param pPackage ��������ݰ�
	* @return 0   �ɹ�
	* @return <>0 ʧ��
	*/
	virtual int OnRecvErrorPackage(CPackage *pPackage);

	void OnHeartBeat(DWORD nSubjectID, WORD nCommPhaseNo, int nSeqNo);
	
	void Publish(CReadOnlyFlow *pFlow, DWORD nSubjectID, WORD nCommPhaseNo, 
		DWORD dwSubscriberID, int nStartId);
	void UnPublish(DWORD nSubjectID);
	void RegisterSubscriber(CSubscriber *pSubscriber, DWORD dwSubscriberID);
	void UnRegisterSubscriber(CSubscriber *pSubscriber);
	void OnAck(DWORD dwSubscriberID, DWORD dwSubjectID, 
		int nStartId, WORD wCommPhaseNo);
	void SetSubCommPhaseNo(WORD nCommPhaseNo);

	/**��ȡ����дsocket����selectʹ��
	* @param pReadId   ������������ض���ʹ�õ�socket��Ϊ0��ʾ����Ҫ��
	* @param pWriteId  �������������д��ʹ�õ�socket��Ϊ0��ʾ����Ҫд 
	*/
	virtual void GetIds(int *pReadId, int *pWriteId);

	/**����IO������������������CReactor����
	* @return ���� 
	*/
	virtual int HandleOther();

private:
	CXTPSubEndPoint *GetSubEndPoint(DWORD nSubjectID);
	CXTPPubEndPoint *GetPubEndPoint(DWORD nSubjectID);

private:
	typedef CHashMap<DWORD, CXTPSubEndPoint *, HashInt> CSubEndPointMap;
	CSubEndPointMap m_mapSubEndPoint;

	typedef CHashMap<DWORD, CXTPPubEndPoint *, HashInt> CPubEndPointMap;
	CPubEndPointMap m_mapPubEndPoint;

	CXTPPubHelper *m_pPubHelper;
	CXTPSubHelper *m_pSubHelper;
	
	WORD m_nSubCommPhaseNo;
};

#endif // !defined(AFX_XTPPROTOCOL_H__C5C04921_6D0B_11D7_BB64_444553540000__INCLUDED_)
