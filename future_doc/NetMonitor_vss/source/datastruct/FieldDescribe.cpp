// FieldDescribe.cpp: implementation of the CFieldDescribe class.
//
///20110519 ����        NT-0132�����������ƣ����Ӷ�64λ����֧��
///20111207 ����        NT-0160 �ױ����׿�ƽ��֣���ǿ�˶�������չ�ֶε�֧��
//////////////////////////////////////////////////////////////////////

#include "public.h"
#include "FieldDescribe.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFieldDescribe::CFieldDescribe(WORD FieldID, int nStructSize, const char *pszFieldName, const char *pszComment, describeFunc func)
{
	m_FieldID = FieldID;
	strcpy(m_szFieldName, pszFieldName);
	strcpy(m_szComment, pszComment);
	m_nStructSize = nStructSize;
	m_nStreamSize = 0;
	m_nTotalMember = 0;
	func();
}

CFieldDescribe::~CFieldDescribe()
{

}

void ChangeEndianCopy2(char *pTarget, char *pSource)
{
	pTarget[1] = pSource[0];
	pTarget[0] = pSource[1];
}

void ChangeEndianCopy4(char *pTarget, char *pSource)
{
	pTarget[3] = pSource[0];
	pTarget[2] = pSource[1];
	pTarget[1] = pSource[2];
	pTarget[0] = pSource[3];
}

void ChangeEndianCopy8(char *pTarget, char *pSource)
{
	pTarget[7] = pSource[0];
	pTarget[6] = pSource[1];
	pTarget[5] = pSource[2];
	pTarget[4] = pSource[3];
	pTarget[3] = pSource[4];
	pTarget[2] = pSource[5];
	pTarget[1] = pSource[6];
	pTarget[0] = pSource[7];
}

/**������ת��Ϊ�ֽ���
* @param pStruct Ҫת���Ķ���
* @param pStream ת�������ֽ���
* @remark �ֽ����еĳ�Ա�����Ǹ�λ��ǰ
*/
void CFieldDescribe::StructToStream(char *pStruct,char *pStream)
{
	for(int i=0;i<m_nTotalMember;i++){
		TMemberDesc *p=&m_MemberDesc[i];
#ifndef _BIG_ENDIAN_						//��λ��ǰ
		switch(p->nType){
		case FT_WORD:						//short
			ChangeEndianCopy2(pStream+p->nStreamOffset, pStruct+p->nStructOffset);
			break;
		case FT_DWORD:						//long
		case FT_REAL4:
			ChangeEndianCopy4(pStream+p->nStreamOffset, pStruct+p->nStructOffset);
			break;
		case FT_QWORD:						//long long
		case FT_REAL8:						//double
			ChangeEndianCopy8(pStream+p->nStreamOffset, pStruct+p->nStructOffset);
			break;
		case FT_BYTE:
			memset(pStream+p->nStreamOffset,0,p->nSize);
			memcpy(pStream+p->nStreamOffset,pStruct+p->nStructOffset,p->nSize);
			break;
		}
#else										//��λ��ǰ
		memset(pStream+p->nStreamOffset,0,p->nSize);
		memcpy(pStream+p->nStreamOffset,pStruct+p->nStructOffset,p->nSize);
#endif
	}
}

/**���ֽ���ת��Ϊ����
* @param pStruct ת���ĳ�����
* @param pStream Ҫת�����ֽ���
* @param nLength �ֽ����ĳ���
* @remark �ֽ����еĳ�Ա���������Ǹ�λ��ǰ
*/
void CFieldDescribe::StreamToStruct(char *pStruct,char *pStream, int nLength)
{
	for(int i=0;i<m_nTotalMember;i++){
		TMemberDesc *p=&m_MemberDesc[i];

		// ��ֹԴ�ֽ���Խ��
		if (p->nStreamOffset + p->nSize > nLength)
		{
			// ���δ�����Ľṹ�ֶ�
			memset(pStruct + p->nStructOffset, 0, m_nStructSize - p->nStructOffset); 

			// ����δ�����Ľṹ�ֶ�
			break;
		}

#ifndef _BIG_ENDIAN_						//��λ��ǰ
		switch(p->nType){
		case FT_WORD:						//short
			ChangeEndianCopy2(pStruct+p->nStructOffset, pStream+p->nStreamOffset);
			break;
		case FT_DWORD:						//long
		case FT_REAL4:
			ChangeEndianCopy4(pStruct+p->nStructOffset, pStream+p->nStreamOffset);
			break;
		case FT_QWORD:						//long long
		case FT_REAL8:						//double
			ChangeEndianCopy8(pStruct+p->nStructOffset, pStream+p->nStreamOffset);
			break;
		case FT_BYTE:
			memcpy(pStruct+p->nStructOffset,pStream+p->nStreamOffset,p->nSize);
			break;
		}
#else										//��λ��ǰ
		memcpy(pStruct+p->nStructOffset,pStream+p->nStreamOffset,p->nSize);
#endif
	}
}


