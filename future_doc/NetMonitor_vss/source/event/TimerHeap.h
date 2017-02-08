// TimerHeap.h: interface for the CTimerHeap class.
//
// 20110624 ����   NT-0139 �ӿ���Ӧʱ��
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TIMERHEAP_H__39AB0CDC_DE05_4AEE_B0E0_D1EB47C4F25C__INCLUDED_)
#define AFX_TIMERHEAP_H__39AB0CDC_DE05_4AEE_B0E0_D1EB47C4F25C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TimerQueue.h"

struct CTimerHeapNode
{
	CEventHandler *pTimer;	/**<��ʱ�������ĵ�ָ��*/
	int nIDEvent;			/**<��ʱ�������ı�ʾ*/
	int nElapse	;			/**<��ʱʱ����*/
	DWORD nExpire;			/**<����ʱ��*/
};

struct CCompareTimerHeapNode : public binary_function<CTimerHeapNode, CTimerHeapNode, bool>
{
    bool operator()(const CTimerHeapNode& x, const CTimerHeapNode& y) const
	{
		return y.nExpire < x.nExpire;
	}
};

/**CTimerHeap�����öѣ�Heap��ʵ�ֵ�һ����ʱ��������
*/
class CTimerHeap : public CTimerQueue, public priority_queue<CTimerHeapNode, vector<CTimerHeapNode>, CCompareTimerHeapNode>  
{
public:
	CTimerHeap(DWORD nClock);
	virtual ~CTimerHeap();

	/**ע��һ����ʱ������ж���
	* @param pEventHandler ��ʱ����ָ�� 
	* @param nIDEvent ��ʱ���ı�ʾ 
	* @param nElapse ��ʱ����ʱ���� ����
	*/
	virtual void RegisterTimer(CEventHandler *pEventHandler, int nIDEvent, int nElapse);

	/**�Ӷ�ʱ����������ȥһ����ʱ������
	* @param pEventHandler ��ʱ�������ָ�� 
	* @param nIDEvent ��ʱ����CReatctor�ı�ʾ��=0 ��ȥ�ö�ʱ������ע��
	*        >0 ��ȥ�ö�ʱ��ָ��ע��
	*/
	virtual void RemoveTimer(CEventHandler *pEventHandler, int nIDEvent);

	/**����ע��Ķ�ʱ���Ƿ���
	*@param nClock ��ǰʱ�䣨����ƣ�
	*/
	virtual void Expire(DWORD nClock);

	/**����ע��Ķ�ʱ���Ƿ���
	*@param nClock ��ǰʱ�䣨����ƣ�
	*/
	virtual bool CheckExpire(DWORD nClock);

private:
	/**ͬ��ʱ��
	*@param nClock ��ǰʱ�䣨����ƣ�
	*@remark ��Ҫ����ʱ�������DWORD�����ֻ���ò���50�죩
	*/
	void SyncTime(DWORD nClock);
private:
	DWORD m_nClock;
	DWORD m_nClockAlter;
};

#endif // !defined(AFX_TIMERHEAP_H__39AB0CDC_DE05_4AEE_B0E0_D1EB47C4F25C__INCLUDED_)
