// FlowSubscriber.h: interface for the CFlowSubscriber class.
//
// 20110901 �Ժ�� NT-150 CFlowSubscriber::HandleMessage���յ��ı��ļ�����
//                 ��ʱ�����Ӷ���չ����ͷ�Ĵ���
//                 �ú�����Ϊ���Ч�ʣ���д�˽��յ��ı��ģ����ڲ���ȫ�Ĳ���
// 20110914 ����   NT-0150 xtpЭ������׷�ݺͶ�������: �����˶���XTP����ͷ�����ͨ�÷�����ForcePushHeader��ForcePopHeader
///20120416 ����   NT-0139 �ӿ���Ӧʱ�䣺xtpЭ�鶩�ĺͷ���֧�ֶ��߳�
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FLOWSUBSCRIBER_H__3456D5BD_8E16_40BC_8BD4_E1A82BE75BF3__INCLUDED_)
#define AFX_FLOWSUBSCRIBER_H__3456D5BD_8E16_40BC_8BD4_E1A82BE75BF3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Subscriber.h"
#include "Flow.h"

/**CFlowSubscriber��һ������Ķ����ߡ���������һ���������յ���
*  ��Ϣ�������С�
*/
class CFlowSubscriber : public CSubscriber  
{
public:
	/**���캯��
	*@param pFlow �����յ�����Ϣ��Flow
	*@param nSubscribeSubjectID Ҫ���ĵ��������
	*/
	CFlowSubscriber(CFlow *pFlow, DWORD nSubscribeSubjectID)
	{
		m_pFlow = pFlow;
		m_nSubjectID = nSubscribeSubjectID;
	}

	/**��ȡ�����ߵ�ͨѶ�׶α��
	*@return �����ߵ�ͨѶ�׶α��
	*/
	virtual WORD GetCommPhaseNo()
	{
		return m_pFlow->GetCommPhaseNo();
	}

	/**���ö����ߵ�ͨѶ�׶α�ţ���һ�������߿����ɶ���߳����������Դ˺������뱻������
	*@param  nCommPhaseNo Ҫ���õĶ����ߵ�ͨѶ�׶α��
	*/
	virtual void SetCommPhaseNo(WORD nCommPhaseNo)
	{
		m_Lock.Lock();
		m_pFlow->SetCommPhaseNo(nCommPhaseNo);
		m_Lock.UnLock();
	}

	/**��ȡ���ĵ��������
	*@return ���ĵ��������
	*/
	virtual DWORD GetSubjectID()
	{
		return m_nSubjectID;
	}

	/**��ȡ���յ�����Ϣ����
	*@return ���յ�����Ϣ����
	*/
	virtual DWORD GetReceivedCount()
	{
		return m_pFlow->GetCount();
	}

	/**�����յ���һ����Ϣ����һ�������߿����ɶ���߳����������Դ˺������뱻������
	*@param pMessage �յ���һ����Ϣ
	*/
	virtual void HandleMessage(CXTPPackage *pMessage)
	{
		m_Lock.Lock();

		if (pMessage->GetXTPHeader()->SequenceNo == m_pFlow->GetCount() + 1)
		{
			pMessage->ForcePushHeader();
			m_pFlow->Append(pMessage->Address(), pMessage->Length());
			pMessage->ForcePopHeader();
		}

		m_Lock.UnLock();
	}

protected:
	CFlow *m_pFlow;						/**< �����յ�����Ϣ��Flow */
	DWORD m_nSubjectID;					/**< Ҫ���ĵ�������� */
};

#endif // !defined(AFX_FLOWSUBSCRIBER_H__3456D5BD_8E16_40BC_8BD4_E1A82BE75BF3__INCLUDED_)
