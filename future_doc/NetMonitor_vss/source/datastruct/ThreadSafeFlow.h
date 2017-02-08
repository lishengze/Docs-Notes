// ThreadSafeFlow.h: interface for the CThreadSafeFlow class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_THREADSAFEFLOW_H__334FD8EF_120B_4E5F_9283_F32A40A3E6CF__INCLUDED_)
#define AFX_THREADSAFEFLOW_H__334FD8EF_120B_4E5F_9283_F32A40A3E6CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Flow.h"

/**CThreadSafeFlow��һ���̰߳�ȫ���������Խ�����������������
*/
class CThreadSafeFlow : public CFlow  
{
public:
	CThreadSafeFlow(CFlow *pUnderFlow)
	{
		m_pUnderFlow = pUnderFlow;
		INIT_CRITICAL_VAR(m_criticalVar);
	}
	virtual ~CThreadSafeFlow()
	{
		delete m_pUnderFlow;
		DELETE_CRITICAL_VAR(m_criticalVar)
	}

	/**��ȡ�����Ѿ��еĶ���ĸ���
	*@return ����ĸ���
	*/
	virtual int GetCount(void)
	{
		ENTER_CRITICAL(m_criticalVar);
		int nCount = m_pUnderFlow->GetCount();
		LEAVE_CRITICAL(m_criticalVar);
		return nCount;
	}
	
	/**��ȡ����ͨѶ�׶����
	*@return ����ͨѶ�׶����
	*/
	virtual WORD GetCommPhaseNo()
	{
		ENTER_CRITICAL(m_criticalVar);
		WORD wCommPhaseNo = m_pUnderFlow->GetCommPhaseNo();
		LEAVE_CRITICAL(m_criticalVar);
		return wCommPhaseNo;
	}

	/**��ȡָ����ŵĶ���
	*@param	id	�������
	*@param pObject ��ȡ����Ļ�����
	*@param length ��������С
	*@return ȡ������ĳ���
	*/
 	virtual int Get(int id, void *pObject, int length)
	{
		ENTER_CRITICAL(m_criticalVar);
		int nLength = m_pUnderFlow->Get(id, pObject, length);
		LEAVE_CRITICAL(m_criticalVar);
		return nLength;
	}

	/**��������ͨѶ�׶����
	*@param nCommPhaseNo Ҫ���õ�����ͨѶ�׶����
	*/
	virtual void SetCommPhaseNo(WORD nCommPhaseNo)
	{
		ENTER_CRITICAL(m_criticalVar);
		m_pUnderFlow->SetCommPhaseNo(nCommPhaseNo);
		LEAVE_CRITICAL(m_criticalVar);
	}

	/**����β���Ķ���ص�
	*@param nCount �����Ķ���ĸ���
	*@return true �����ɹ��� false ����ʧ��
	*/
	virtual bool Truncate(int nCount) 
	{
		ENTER_CRITICAL(m_criticalVar);
		bool bResult = m_pUnderFlow->Truncate(nCount);
		LEAVE_CRITICAL(m_criticalVar);
		return bResult;
	}

	/**����������һ������
	*@param	pObject Ҫ���ӵĶ���
	*@param length �������ݵĳ���
	*@return ���������е���ţ�С��0��ʾ����ʧ��
	*/
	virtual int Append(void *pObject, int length)
	{
		ENTER_CRITICAL(m_criticalVar);
		int nId = m_pUnderFlow->Append(pObject, length);
		LEAVE_CRITICAL(m_criticalVar);
		return nId;
	}
private:
	CFlow *m_pUnderFlow;
	CRITICAL_VAR m_criticalVar;
};

#endif // !defined(AFX_THREADSAFEFLOW_H__334FD8EF_120B_4E5F_9283_F32A40A3E6CF__INCLUDED_)
