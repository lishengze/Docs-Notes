// SCPPackage.h: interface for the CSCPPackage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCPPACKAGE_H__B7E4ECB1_9DD3_43C2_BB41_D1F4E8101069__INCLUDED_)
#define AFX_SCPPACKAGE_H__B7E4ECB1_9DD3_43C2_BB41_D1F4E8101069__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Package.h"
#include "FieldSet.h"

#define SCP_PACKAGE_MAX_SIZE	4096

/**SCP������ÿ��filed����ͷ
*/
struct TSCPFieldHeader
{
	BYTE FieldID;	/**< ���ʾ�� */
	BYTE Size;	/**< ��ĳ��� */
};

/**SCTP����ͷ�ṹ
*/
struct	TSCPHeader
{
	WORD	ContentLength;		/**< ����ͷ֮�⣬��field���Ⱥ� */
	WORD	Tid;				/**< SCP����id	*/

	inline void ToStream(char *pStream);
	inline void FromStream(char *pStream);
};

inline void TSCPHeader::ToStream(char *pStream)
{
#ifndef _BIG_ENDIAN_						//��λ��ǰ
	((TSCPHeader *)pStream)->ContentLength = ChangeEndian(ContentLength);
	((TSCPHeader *)pStream)->Tid = ChangeEndian(Tid);
#else
	memcpy(pStream, this, sizeof(TSCPHeader));
#endif
}

inline void TSCPHeader::FromStream(char *pStream)
{
#ifndef _BIG_ENDIAN_						//��λ��ǰ
	ContentLength = ChangeEndian(((TSCPHeader *)pStream)->ContentLength);
	Tid = ChangeEndian(((TSCPHeader *)pStream)->Tid);
#else
	memcpy(this, pStream, sizeof(TSCPHeader));
#endif
}

const int SCPHLEN = sizeof(TSCPHeader);

class CSCPPackage : public CFieldSet  
{
public:
	CSCPPackage();
	virtual ~CSCPPackage();
	virtual DWORD GetActiveID();
	virtual int ValidPackage();
	virtual int MakePackage();
	CSCPPackage *Clone();

	inline void SetTid(WORD tid);
	inline WORD GetTid();
protected:
	TSCPHeader m_header;
};

inline void CSCPPackage::SetTid(WORD tid)
{
	m_header.Tid = tid;
}

inline WORD CSCPPackage::GetTid()
{
	return m_header.Tid;
}

#define SCP_GET_SINGLE_FIELD(pPackage, pField)	((pPackage)->GetSingleField(&((pField)->m_Describe), (pField)))
#define SCP_ADD_FIELD(pPackage, pField) ((pPackage)->AddField(&((pField)->m_Describe), (pField)))
#endif // !defined(AFX_SCPPACKAGE_H__B7E4ECB1_9DD3_43C2_BB41_D1F4E8101069__INCLUDED_)
