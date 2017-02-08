// IndexPackageFlow.h: interface for the CIndexPackageFlow class.
//
// 20070905 �Ժ�� ������GetPackageIndex����
///20120319 ����   NT-0139 �ӿ���Ӧʱ�䣺������֪ͨ�ӿ�
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INDEXPACKAGEFLOW_H__C65A6874_466C_4F86_A80A_D1E16F00FFC7__INCLUDED_)
#define AFX_INDEXPACKAGEFLOW_H__C65A6874_466C_4F86_A80A_D1E16F00FFC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ReadOnlyFlow.h"

class CIndexPackageFlow : public CReadOnlyFlow  
{
public:
	CIndexPackageFlow();
	virtual ~CIndexPackageFlow();

	/**��ȡ�����Ѿ��еİ�����
	*@return ������
	*/
	virtual int GetCount(void);
	
	virtual void AttachUnderFlow(CReadOnlyFlow *pFlow);

	virtual CReadOnlyFlow *DeatchUnderFlow();

	/**����β���İ��ص�
	*@param nCount �����İ��ĸ���
	*@return true �����ɹ��� false ����ʧ��
	*/
	virtual bool Truncate(int nCount); 

	/**����������һ������
	*@param nIndex �������²����е����
	*@return ���������е���ţ�С��0��ʾ����ʧ��
	*/
	virtual int Append(int nIndex);
	
	/**��ȡָ����ŵĶ���
	*@param	id	�������
	*@param pObject ��ȡ����Ļ�����
	*@param length ��������С
	*@return ȡ������ĳ���
	*/
 	virtual int Get(int id, void *pObject, int length);
	
	/**
	 * ֪ͨ
	 */
	virtual void Notify();

	virtual WORD GetCommPhaseNo();
	
	virtual void SetCommPhaseNo(WORD nCommPhaseNo);

	/**��ȡָ����ŵĶ������²����е����
	*@param	id	�������
	*@return ȡ����������²����е����
	*/
	int GetPackageIndex(int id);
protected:
	typedef vector<DWORD> CPackageIndex;
	CPackageIndex m_PackageIndex;
	CReadOnlyFlow *m_pUnderFlow; 
	DWORD m_nCommPhaseNo;
};

#endif // !defined(AFX_INDEXPACKAGEFLOW_H__C65A6874_466C_4F86_A80A_D1E16F00FFC7__INCLUDED_)
