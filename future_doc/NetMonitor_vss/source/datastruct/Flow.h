// Flow.h: interface for the CFlow class .
//
// 20110624 ����	NT-0139 �ӿ���Ӧʱ��
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FLOW_H__D2F86CC2_6DC5_11D7_BB64_82A63033BA6B__INCLUDED_)
#define AFX_FLOW_H__D2F86CC2_6DC5_11D7_BB64_82A63033BA6B__INCLUDED_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ReadOnlyFlow.h"

// ֪ͨ�ӿ�
class INotify
{
protected:
	INotify() {};

public:
	virtual ~INotify() {};

public:
	virtual void Notify() = 0;
};

/**CFlow��һ�ֶ�������������
* ����ֻ�ܴ�β����ӣ����԰���Ŷ�����
*/
class  CFlow : public CReadOnlyFlow
{
public:
	/**���캯��
	* @param nSubjectID ������Ӧ������
	*/
	CFlow();

	/**��������
	*/
	virtual ~CFlow();
		
	/**��������ͨѶ�׶����
	*@param nCommPhaseNo Ҫ���õ�����ͨѶ�׶����
	*/
	virtual void SetCommPhaseNo(WORD nCommPhaseNo) = 0;

	/**����β���Ķ���ص�
	*@param nCount �����Ķ���ĸ���
	*@return true �����ɹ��� false ����ʧ��
	*/
	virtual bool Truncate(int nCount) = 0; 

	/**����������һ������
	*@param	pObject Ҫ���ӵĶ���
	*@param length �������ݵĳ���
	*@return ���������е���ţ�С��0��ʾ����ʧ��
	*/
	virtual int Append(void *pObject, int length) = 0;

	/**��ȡָ��������ȵ�ָ��
	*@return	ָ��������ȵ�ָ��
	*/
	virtual const int *GetCountPtr(void) = 0;

	/**
	 * ����֪ͨ������
	 */
	virtual void SetNotifyHandler(INotify* pNotifyHandler);

	/**
	 * ֪ͨ
	 */
	virtual void Notify();

	/**
	 * ����֪ͨģʽ
	 */
	virtual void SetAutoNotify(bool bAutoNotify);

protected:
	// ֪ͨ������
	vector<INotify*>* m_NotifyHandlers;

	// �Ƿ��Զ�֪ͨ
	bool m_bAutoNotify;
};

#endif // !defined(AFX_FLOW_H__D2F86CC2_6DC5_11D7_BB64_82A63033BA6B__INCLUDED_)
