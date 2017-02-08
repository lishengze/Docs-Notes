// FieldSet.h: interface for the CFieldSet class.
//
// 20070806 �Ժ�� ����FIELD_TO_STRING��������һ��fieldת����һ���ı����
// 20070827 �Ժ�� ����CFieldIteratorBaseδ����ָ��Խ���飬�޷�Ӧ�������ĵ�����
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FIELDSET_H__83362A2A_0A24_46AE_A788_295CB18F6BF3__INCLUDED_)
#define AFX_FIELDSET_H__83362A2A_0A24_46AE_A788_295CB18F6BF3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FieldDescribe.h"
#include "Package.h"

struct TFieldHeader
{
	WORD FieldID;
	WORD Size;
};

/**�����������
*/
class CFieldIteratorBase
{
public:
	/**���캯��
	* @param pHead �������ݵ�ͷָ��
	* @param pEnd �������ݵ�βָ��
	* @param pFieldDescribe Ҫ���������������
	*/
	CFieldIteratorBase(char *pHead, char *pEnd, CFieldDescribe *pFieldDescribe);

	/**������ָ����һ����
	*/
	void Next();
	
	/**�Ƿ��и������
	* @return true û�и������\n
	* @return false ���и������
	*/
	inline bool IsEnd();

	/**ȡ����ǰ���ͷ
	* @param fieldHeader ȡ���ĵ�ǰ���ͷ
	*/
	inline void RetrieveHeader(TFieldHeader &fieldHeader);
	
private:
	inline void GetHeader();
	inline int DataRemain();
	
protected:
	TFieldHeader m_fieldHeader;
	CFieldDescribe *m_pFieldDescribe;
	char *m_pEnd;
	char *m_pCurr;
	char *m_pData;
};

inline bool CFieldIteratorBase::IsEnd()
{
	return m_pData == NULL;
}

inline int CFieldIteratorBase::DataRemain()
{
	return m_pEnd - m_pCurr;
}

inline void CFieldIteratorBase::RetrieveHeader(TFieldHeader &fieldHeader)
{
	fieldHeader = m_fieldHeader;
}

inline void CFieldIteratorBase::GetHeader()
{
	memcpy(&m_fieldHeader, m_pCurr, sizeof(TFieldHeader));
	CHANGE_ENDIAN(m_fieldHeader.FieldID);
	CHANGE_ENDIAN(m_fieldHeader.Size);
}


/**�����������ĵ�����
*/
class CFieldTypeIterator : public CFieldIteratorBase
{
public:
	/**���캯��
	* @param pHead �������ݵ�ͷָ��
	* @param pEnd �������ݵ�βָ��
	*/
	CFieldTypeIterator(char *pHead, char *pEnd);
	
	/**�ӻ������ж���һ������
	* @param pFieldDescribe Ҫ��ȡ���������
	* @param field ����������
	* @return 0 û�м�¼
	* @return >0  ��ȡ��¼�ĳ���
	*/
	int Retrieve(CFieldDescribe *pFieldDescribe, void *pStruct);
};

/**����ָ����FieldDescribe�õ��ĵ�����
*/
class  CNamedFieldIterator : public CFieldIteratorBase
{
public:
	/**���캯��
	* @param pHead �������ݵ�ͷָ��
	* @param pEnd �������ݵ�βָ��
	* @param pFieldDescribe Ҫ���������������
	*/
	CNamedFieldIterator(char *pHead, char *pEnd, CFieldDescribe *pFieldDescribe);
	
	/**�ӻ������ж���һ������
	* @param field ����������
	* @return 0 û�м�¼
	* @return >0  ��ȡ��¼�ĳ���
	*/
	int Retrieve(void *pStruct);
};

class CFieldSet : public CPackage
{
public:
	CFieldSet();
	virtual ~CFieldSet();

	/**��ȡһ����
	* @param field ����һ���������͵���
	* @return 0 û�м�¼
	* @return >0  ��ȡ��¼�ĳ���
	*/
	int GetSingleField(CFieldDescribe *pFieldDescribe, void *pField);
		
	int AddField(CFieldDescribe *pFieldDescribe, void *pField);
	
	/**����ָ�����������Ϣ����ȡָ����ĵ�����
	* @param field ����������͵��������ָ��
	* @return ָ����ĵ����� 
	*/
	inline CNamedFieldIterator GetNamedFieldIterator(CFieldDescribe *pFieldDescribe);

	/**��ȡ�������ĵ�����
	* @param field ����������͵��������ָ��
	* @return ָ����ĵ����� 
	*/
	inline CFieldTypeIterator GetFieldTypeIterator();
//private:
	/**Ϊĳ���͵������ռ�
	* @param FieldID  ������id
	* @param Size ��ĳ���
	* @return ���ط������ĵ�ַ
	*/
	char * AllocField(WORD wFieldID,WORD wSize);
};

inline CNamedFieldIterator CFieldSet::GetNamedFieldIterator(CFieldDescribe *pFieldDescribe)
{
	return CNamedFieldIterator(m_pHead, m_pTail, pFieldDescribe);
}

inline CFieldTypeIterator CFieldSet::GetFieldTypeIterator()
{
	return CFieldTypeIterator(m_pHead, m_pTail);
}

inline int CFieldSet::AddField(CFieldDescribe *pFieldDescribe, void *pField)
{
	char *buf = AllocField(pFieldDescribe->m_FieldID, pFieldDescribe->m_nStreamSize);
	if(buf == NULL)
	{
		return -1;
	}
	pFieldDescribe->StructToStream((char *)pField, buf);
	return 0;
}

void FIELD_DEBUG(char *pData, CFieldDescribe *pFieldDescribe, CLogger *pLogger);
void FIELD_TO_STRING(char *pData, CFieldDescribe *pFieldDescribe, FILE *fp);
#endif // !defined(AFX_FIELDSET_H__83362A2A_0A24_46AE_A788_295CB18F6BF3__INCLUDED_)
