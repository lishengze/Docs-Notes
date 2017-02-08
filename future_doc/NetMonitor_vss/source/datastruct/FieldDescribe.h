// FieldDescribe.h: interface for the CFieldDescribe class .
//
///20110519 ����        NT-0132�����������ƣ����Ӷ�64λ����֧��
///20111207 ����        NT-0160 �ױ����׿�ƽ��֣���ǿ�˶�������չ�ֶε�֧��
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FIELDDESCRIBE_H__1E41C27A_C6C8_4820_94AF_1581CE41F7C7__INCLUDED_)
#define AFX_FIELDDESCRIBE_H__1E41C27A_C6C8_4820_94AF_1581CE41F7C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UFDataType.h"

#define MAX_MEMB				50
#define MAX_FIELD_NAME_LEN		100

/**ÿ���������͵ı�ʾ��
*/
enum MemberType{
	FT_BYTE = 0,
	FT_WORD = 1,
	FT_DWORD = 2,
	FT_REAL4 = 3,
	FT_REAL8 = 4,
	FT_QWORD = 5
};

/**���Ա���Խṹ
*/
struct TMemberDesc{
	MemberType nType;			/**<��Ա����*/
	int nStructOffset;			/**<��Ա�����е�ƫ����*/
	int nStreamOffset;			/**<��Ա���ֽ����е�ƫ����*/
	int nSize;					/**<��Ա����*/
	char szName[30];			/**<��Ա����*/
};

#define DEF_SETUP_MEMBER(type,id) 	void SetupMember(type &,int offset,char *name,int length){	SetupMember(id,offset,name,length); }
	
/**���������
*/
class  CFieldDescribe  
{
public:
    typedef void (*describeFunc)(); /**< ����һ��ָ�뺯������ */
    	
	/**���캯������ִ�д�����ָ�뺯��
	* @param FieldID ��ID
	* @param nStructSize ���С
	* @param pszFieldName ����
	* @param pszComment ��˵��
	* @param func    ָ��һ��������ָ��
	*/
	CFieldDescribe(WORD FieldID, int nStructSize, const char *pszFieldName, const char *pszComment, describeFunc func);

	/**��������
	*/
	~CFieldDescribe();
public:
	/**�������INT1����Id FT_BYTE�Ķ��ձ�ķ���
	*/	
	DEF_SETUP_MEMBER(CUFBaseCharType,FT_BYTE);
	
	/**�������INT2����Id FT_WORD�Ķ��ձ�ķ���
	*/
	//DEF_SETUP_MEMBER(INT2,FT_WORD);
	
	/**�������INT4����Id FT_DWORD�Ķ��ձ�ķ���
	*/
	DEF_SETUP_MEMBER(CUFBaseIntType,FT_DWORD);
	
	/**�������BYTE����Id FT_BYTE�Ķ��ձ�ķ���
	*/
	//DEF_SETUP_MEMBER(BYTE,FT_BYTE);
	
	/**�������WORD����Id FT_WORD�Ķ��ձ�ķ���
	*/
	DEF_SETUP_MEMBER(CUFBaseWordType,FT_WORD);
	
	/**�������DWORD����Id FT_DWORD�Ķ��ձ�ķ���
	*/
	//DEF_SETUP_MEMBER(DWORD,FT_DWORD);
	
	/**�������REAL4����Id FT_REAL4�Ķ��ձ�ķ���
	*/
	//DEF_SETUP_MEMBER(REAL4,FT_REAL4);
	
	/**�������REAL8����Id FT_REAL8�Ķ��ձ�ķ���
	*/
	DEF_SETUP_MEMBER(CUFBaseFloatType,FT_REAL8);
	
	/**�������BYTEARRAY����Id FT_BYTE�Ķ��ձ�ķ���
	*/
	DEF_SETUP_MEMBER(CUFBaseStringType,FT_BYTE);

	/**�������QWORD����Id FT_QWORD�Ķ��ձ�ķ���
	*/
	DEF_SETUP_MEMBER(CUFBaseQWordType,FT_QWORD);

	/**������ת��Ϊ�ֽ���
	* @param pStruct Ҫת���Ķ���
	* @param pStream ת�������ֽ���
	* @remark �ֽ����еĳ�Ա�����Ǹ�λ��ǰ
	*/
	void StructToStream(char *pStruct,char *pStream);

	/**���ֽ���ת��Ϊ����
	* @param pStruct ת���ĳ�����
	* @param pStream Ҫת�����ֽ���
	* @param nLength �ֽ����ĳ���
	* @remark �ֽ����еĳ�Ա���������Ǹ�λ��ǰ
	*/
	void StreamToStruct(char *pStruct,char *pStream, int nLength);
	
	/**��ȡ���С
	* @return �������С
	*/	
	inline int GetStructSize();
	
	/**��ȡ��ת���ɵ��ֽ�������
	* @return ������ת���ɵ��ֽ�������
	*/	
	inline int GetStreamSize();

	/**���Ա����
	* @return �������Ա����
	*/
	inline int GetMemberCount();
	
	/**��ȡ����ÿ����Ա������
	* @param index ��Ա���������ձ��е�λ��
	* @return ���س�Ա����
	*/
	inline TMemberDesc *GetMemberDesc(int index);

	/**��ȡ�������
	* @return �������
	*/
	inline const char *GetFieldName();
private:

	/**������ͺ�����Id���ձ�
	* @param nType ��Ա����
	* @param nStructOffset ��Ա�����е�ƫ����
	* @param nSize ��Ա����
	* @param szName ��Ա����
	*/
	inline void SetupMember(MemberType nType,int nStructOffset,char *szName,int nSize);
public:
	WORD m_FieldID;			/**<��ID */
	char m_szComment[MAX_FIELD_NAME_LEN];		/**<��ע�� */
	int m_nStructSize;			/**<���С*/
	int m_nStreamSize;			/**<��ת���ɵ��ֽ�������*/
private:
	int m_nTotalMember;			/**<���Ա����*/
	char m_szFieldName[MAX_FIELD_NAME_LEN];
	TMemberDesc m_MemberDesc[MAX_MEMB];	/**<���Ա��������*/

};

inline void CFieldDescribe::SetupMember(MemberType nType,int nStructOffset,
		char *szName,int nSize)
{
	TMemberDesc *p=&m_MemberDesc[m_nTotalMember];
	p->nType=nType;
	p->nStructOffset=nStructOffset;
	p->nStreamOffset=m_nStreamSize;
	p->nSize=nSize;
	strcpy(p->szName,szName);

	m_nStreamSize+=nSize;
	m_nTotalMember++;
}

inline int CFieldDescribe::GetStructSize()
{
	return m_nStructSize;
}

inline int CFieldDescribe::GetStreamSize()
{
	return m_nStreamSize;
}

inline int CFieldDescribe::GetMemberCount()
{
	return m_nTotalMember;
}

inline TMemberDesc * CFieldDescribe::GetMemberDesc(int index)
{
	return &m_MemberDesc[index];
}

inline const char *CFieldDescribe::GetFieldName()
{
	return m_szFieldName;
}

#define TYPE_DESCRIPTOR(members) void DescribeMembers() { members; } static CFieldDescribe m_Describe 

#define TYPE_DESC(member) m_Describe.SetupMember(member,(char *)&member-(char *)this,#member,sizeof(member))

#define REGISTER_FIELD(fid,field, comment)   static void DescribeMemberOf##field() { field f; f.DescribeMembers(); } CFieldDescribe field::m_Describe(fid,sizeof(field),#field,comment,&DescribeMemberOf##field)

#endif // !defined(AFX_FIELDDESCRIBE_H__1E41C27A_C6C8_4820_94AF_1581CE41F7C7__INCLUDED_)
