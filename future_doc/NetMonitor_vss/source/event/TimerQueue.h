// TimerQueue.h: interface for the CTimerQueue class.
//
// 20110624 ����   NT-0139 �ӿ���Ӧʱ��
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TIMERQUEUE_H__2CEE8EF5_9969_48A0_83C2_857FDF4D006A__INCLUDED_)
#define AFX_TIMERQUEUE_H__2CEE8EF5_9969_48A0_83C2_857FDF4D006A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "EventHandler.h"

/**CTimerQueue��һ����ʱ���������Ļ��࣬��ʱ���Ĺ������ʹ�ö��ַ�����
*��ѡ���������ȣ���ͬ�Ĺ������벻ͬ����µ�����Ч�ʲ�ͬ��
*������Ҫ�̳б��ӿ�
*/
class CTimerQueue  
{
public:
	/**Ϊ�¼�������ע��һ����ʱ��
	* @param pEventHandler �¼������� 
	* @param nIDEvent ��ʱ���ı�ʾ 
	* @param nElapse ��ʱ����ʱ���� ����
	*/
	virtual void RegisterTimer(CEventHandler *pEventHandler, int nIDEvent, int nElapse) = 0;

	/**ע���¼��������Ķ�ʱ��
	* @param pEventHandler �¼������� 
	* @param nIDEvent ��ʱ���ı�ʾ��=0 ע�����¼����������еĶ�ʱ����
	*        >0 ע�����¼�������ָ����ʶ�Ķ�ʱ��
	*/
	virtual void RemoveTimer(CEventHandler *pEventHandler, int nIDEvent) = 0;

	/**������ʱ���Ƿ���
	*@param nClock ��ǰʱ�䣨����ƣ�
	*/
	virtual void Expire(DWORD nClock) = 0;

	/**����ע��Ķ�ʱ���Ƿ���
	*@param nClock ��ǰʱ�䣨����ƣ�
	*/
	virtual bool CheckExpire(DWORD nClock) = 0;

protected:
	virtual ~CTimerQueue(){};
};

#endif // !defined(AFX_TIMERQUEUE_H__2CEE8EF5_9969_48A0_83C2_857FDF4D006A__INCLUDED_)

