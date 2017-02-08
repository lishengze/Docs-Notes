// FlowSubscriber.h: interface for the CFlowSubscriber class.
//
// 20110901 赵鸿昊 NT-150 CFlowSubscriber::HandleMessage将收到的报文记入流
//                 里时，增加对扩展报文头的处理
//                 该函数中为提高效率，改写了接收到的报文，属于不安全的操作
// 20110914 江鹏   NT-0150 xtp协议增加追溯和度量功能: 增加了对于XTP报文头处理的通用方法，ForcePushHeader和ForcePopHeader
///20120416 江鹏   NT-0139 加快响应时间：xtp协议订阅和发布支持多线程
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FLOWSUBSCRIBER_H__3456D5BD_8E16_40BC_8BD4_E1A82BE75BF3__INCLUDED_)
#define AFX_FLOWSUBSCRIBER_H__3456D5BD_8E16_40BC_8BD4_E1A82BE75BF3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Subscriber.h"
#include "Flow.h"

/**CFlowSubscriber是一种主题的订阅者。它关联着一个流，将收到的
*  消息记入流中。
*/
class CFlowSubscriber : public CSubscriber  
{
public:
	/**构造函数
	*@param pFlow 保存收到的消息的Flow
	*@param nSubscribeSubjectID 要订阅的主题代码
	*/
	CFlowSubscriber(CFlow *pFlow, DWORD nSubscribeSubjectID)
	{
		m_pFlow = pFlow;
		m_nSubjectID = nSubscribeSubjectID;
	}

	/**获取订阅者的通讯阶段编号
	*@return 订阅者的通讯阶段编号
	*/
	virtual WORD GetCommPhaseNo()
	{
		return m_pFlow->GetCommPhaseNo();
	}

	/**设置订阅者的通讯阶段编号，因一个订阅者可能由多个线程驱动、所以此函数必须被锁保护
	*@param  nCommPhaseNo 要设置的订阅者的通讯阶段编号
	*/
	virtual void SetCommPhaseNo(WORD nCommPhaseNo)
	{
		m_Lock.Lock();
		m_pFlow->SetCommPhaseNo(nCommPhaseNo);
		m_Lock.UnLock();
	}

	/**获取订阅的主题代码
	*@return 订阅的主题代码
	*/
	virtual DWORD GetSubjectID()
	{
		return m_nSubjectID;
	}

	/**获取已收到的消息个数
	*@return 已收到的消息个数
	*/
	virtual DWORD GetReceivedCount()
	{
		return m_pFlow->GetCount();
	}

	/**处理收到的一个消息，因一个订阅者可能由多个线程驱动、所以此函数必须被锁保护
	*@param pMessage 收到的一个消息
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
	CFlow *m_pFlow;						/**< 保存收到的消息的Flow */
	DWORD m_nSubjectID;					/**< 要订阅的主题代码 */
};

#endif // !defined(AFX_FLOWSUBSCRIBER_H__3456D5BD_8E16_40BC_8BD4_E1A82BE75BF3__INCLUDED_)
