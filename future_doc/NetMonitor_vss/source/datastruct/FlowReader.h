// FlowReader.h: interface for the CFlowReader class.
//
// 2007.7.5	�Ժ��	������GetNext�����������е�����ȡ��ָ���Ļ�������
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FLOWREADER_H__B9DB0445_E13B_4192_83B6_DBBD0528CB9A__INCLUDED_)
#define AFX_FLOWREADER_H__B9DB0445_E13B_4192_83B6_DBBD0528CB9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ReadOnlyFlow.h"
#include "Package.h"

/**CFlowReader���������Ķ�ȡ�ĵ�����
*/
class CFlowReader  
{
public:
	//SetIDʱ�õļ������λ�õı�ʶ��������fseek���õ�SEEK_XXX��
	enum SeekFlag{
		FROM_HEAD,
		FROM_HERE,
		FROM_END
	};
public:
	/**���캯��
	*/
	CFlowReader();

	/**��������
	*/
	virtual ~CFlowReader();

	/**�ҽӵ�һ������
	*@param	pFlow	Ҫ��ȡ��CReadOnlyFlow
	*@param	startId	��ʼ��ȡ�ı�ţ������ſ��Դ���ĿǰpFlow�е������
	*/
	int AttachFlow(CReadOnlyFlow *pFlow, int nStartId);

	/**ж�¹ҽӵ�����
	*@return pFlow	ԭ���ҽӵ���
	*/
	CReadOnlyFlow *DetachFlow();

	/**������һ��Ҫ��ȡ�ı��
	* @param	id	��һ��Ҫ��ȡ�ı�ţ������ſ��Դ���ĿǰpFlow�е������
	* @param	from	��ŵļ��㷽����������
	*		FROM_HEAD	��ͷ����
	*		FROM_HERE	�ӵ�ǰλ�ü���
	*		FROM_END	��β����
	*/
	inline void SetId(int id, SeekFlag from = FROM_HEAD);
	
	/**��CReadOnlyFlow���Ƿ��ж����ɶ�
	* @return	true ��ʾ���У�false ��ʾû��
	*/
	inline bool Available(void);

	/**��ȡ��CReadOnlyFlow���Ѿ��еĶ������
	* @return	�������
	*/
	inline int GetCount(void);

	/**��ȡ��reader��������subject
	* @return	���ظ�Reader��������Subject
	*/
	inline CReadOnlyFlow *GetFlow(void);
		
	/**��ȡ��һ��Ҫ��ȡ�ı��
	* @return  ��һ��Ҫ���Ķ���ı��
	*/
	inline int GetId(void);

	/*���ҽӵ����е���һ����ȡ��ָ���Ļ�������
	*@param	id	�������
	*@param pObject ��ȡ����Ļ�����
	*@param length ��������С
	*@return ȡ������ĳ���
	*/
	int GetNext(void *pObject, int length);

	/*���ҽӵ����е���һ����ȡ��ָ���İ�������
	*@param pPackage ���ڴ���ȡ�����ݵİ�����
	*@return true ��ȡ�ɹ���false ��ȡʧ��
	*@remark ���������㹻�Ŀռ�
	*/
	bool GetNext(CPackage *pPackage);
	
	/**��ȡͨѶ�׶α��
	*@return ͨѶ�׶α��
	*/
	inline WORD GetCommPhaseNo();
protected:
	CReadOnlyFlow *m_pFlow;					/**< �洢���������� */
	WORD m_nCommPhaseNo;			/**< ��ǰͨѶ�׶���� */
	int m_nNextId;					/**< ��һ��Ҫ���Ķ���ı�� */
};

inline bool CFlowReader::Available(void)
{
	return GetCount()>m_nNextId;
}


inline int CFlowReader::GetCount(void)
{
	return m_pFlow->GetCount();
}
	
inline int CFlowReader::GetId(void)
{
	return m_nNextId;
}
	
inline CReadOnlyFlow *CFlowReader::GetFlow()
{
	return m_pFlow;
}

inline void CFlowReader::SetId(int id, SeekFlag from)
{
	if (from==FROM_HEAD)
		m_nNextId=id;
	else if (from==FROM_HERE)
		m_nNextId+=id;
	else if (from==FROM_END)
		m_nNextId=m_pFlow->GetCount()+id;
	else
		RAISE_DESIGN_ERROR("Invalid from parameter while calling setId of CFlowReader");
}

inline WORD CFlowReader::GetCommPhaseNo()
{
	return m_nCommPhaseNo;
}

#endif // !defined(AFX_FLOWREADER_H__B9DB0445_E13B_4192_83B6_DBBD0528CB9A__INCLUDED_)
