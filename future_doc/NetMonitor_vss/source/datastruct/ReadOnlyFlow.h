// ReadOnlyFlow.h: interface for the CReadOnlyFlow class.
//
///20120319 ����   NT-0139 �ӿ���Ӧʱ�䣺������֪ͨ�ӿ�
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_READONLYFLOW_H__9BFF4BE3_1853_4B6A_90DE_4DB34A222AF1__INCLUDED_)
#define AFX_READONLYFLOW_H__9BFF4BE3_1853_4B6A_90DE_4DB34A222AF1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/**CReadOnlyFlow��һ�ֶ�������������,���еĶ�����԰���Ŷ�����
* CReadOnlyFlowֻ����Ĳ����ӿڣ���Ҫ��������ʵ�־���ķ���
*/
class CReadOnlyFlow  
{
public:
	CReadOnlyFlow();
	virtual ~CReadOnlyFlow();

	/**��ȡ�����Ѿ��еĶ���ĸ���
	*@return ����ĸ���
	*/
	virtual int GetCount(void) = 0;
	
	/**��ȡ����ͨѶ�׶����
	*@return ����ͨѶ�׶����
	*/
	virtual WORD GetCommPhaseNo() = 0;

	/**��ȡָ����ŵĶ���
	*@param	id	�������
	*@param pObject ��ȡ����Ļ�����
	*@param length ��������С
	*@return ȡ������ĳ���
	*/
 	virtual int Get(int id, void *pObject, int length) = 0;

	/**
	 * ֪ͨ
	 */
	virtual void Notify() = 0;
};

#endif // !defined(AFX_READONLYFLOW_H__9BFF4BE3_1853_4B6A_90DE_4DB34A222AF1__INCLUDED_)
