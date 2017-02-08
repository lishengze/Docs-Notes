// Reactor.h: interface for the CReactor class .
//
// 20090510 �Ժ��  NT-0074������HandleOtherTask���������ദ����ִ�еĹ���
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_REACTOR_H__F8FA2D5C_B2CD_42BA_A3D1_FBF99F03C1F0__INCLUDED_)
#define AFX_REACTOR_H__F8FA2D5C_B2CD_42BA_A3D1_FBF99F03C1F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "EventDispatcher.h"

/**CReactor�ǽ�����һ�������̻߳����ϵ��������棬��ͨ��select����
*�����ָ����¼�������Ҫ��ʱ���������Ѿ�ע���CEventHandler������
*��Ҫ������Run()������IO��CEventHandler������������һ��list�У�
*���ڶ�ʱ����CEventHandler������������һ�������С�
*/
class  CReactor :public CEventDispatcher 
{
public:
	/**���캯��
	*/
	CReactor();
	
	/**��������
	*/
	virtual ~CReactor();
	
	/**ע��һ��IO������ж���
	* @param pEventHandler �����ж����ָ�� 
	*/
	virtual void RegisterIO(CEventHandler *pEventHandler);
	
	/**�Ӷ���list����ȥһ��IO������ж���
	* @param pEventHandler �����ж����ָ�� 
	*/
	virtual void RemoveIO(CEventHandler *pEventHandler);
	
protected:
	/**������������������ɼ̳����������ѵ�һЩ��Ҫ����ִ�еĹ���
	* @return true ��������û��ȫ�����
	* @return false ��������ȫ�����
	*/
	virtual bool HandleOtherTask();
	
protected:
	typedef list<CEventHandler *> CEventHandlerList; /**< �������¼��������б� */
	CEventHandlerList m_IOList;	/**< ���IO�¼����������б�*/

	bool m_bIOListHasNull;          /**< IO�¼��������б�����ݱ�־*/

};

#endif // !defined(AFX_REACTOR_H__F8FA2D5C_B2CD_42BA_A3D1_FBF99F03C1F0__INCLUDED_)
