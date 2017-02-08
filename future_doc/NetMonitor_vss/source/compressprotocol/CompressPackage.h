// CompressPackage.h: interface for the CCompressPackage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPRESSPACKAGE_H__81C278D7_1D6C_40FD_B2E7_E062464ECC11__INCLUDED_)
#define AFX_COMPRESSPACKAGE_H__81C278D7_1D6C_40FD_B2E7_E062464ECC11__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Package.h"

#define CRP_PACKAGE_MAX_SIZE	4096

struct TCRPHeader
{
	BYTE Type;			/**< ��ʾ�ϲ�Э���Э��ID */	
	BYTE Method;		/**< ѹ���㷨���� */
	
	inline void Init();
	inline void ToStream(char *pStream);
	inline void FromStream(char *pStream);
};

inline void TCRPHeader::Init()
{
	memset(this, 0 ,sizeof(TCRPHeader));
}

inline void TCRPHeader::ToStream(char *pStream)
{
	memcpy(pStream, this, sizeof(TCRPHeader));
}

inline void TCRPHeader::FromStream(char *pStream)
{
	memcpy(this, pStream, sizeof(TCRPHeader));
}

const int CRPHLEN = sizeof(TCRPHeader);

class CCompressPackage : public CPackage  
{
public:
	CCompressPackage();
	virtual ~CCompressPackage();
	
	/**���ݰ��ϴ�ʱ���ϲ�Э��ı�ţ��������ʵ�ִ˺���
	* @return �ϲ�Э��ı��
	*/
	virtual DWORD GetActiveID();

	/** �����������Ƿ񹹳�һ�������İ������ж�������ݣ���ص���
	* @return >=0 ��һ�������İ� 
	* @return -1 ���ݰ�������
	* @return <-1 ���ݰ��д���
	*/
	virtual int ValidPackage();

	/**��װ���ݰ�
	* @return 0 ��װ�ɹ�
	* @return <0 ��װʧ��
	*/
	virtual int MakePackage();

	inline BYTE GetCompressMethod();

	inline TCRPHeader *GetCRPHeader();

protected:
	TCRPHeader m_header;		/**< CRP��ͷ */
};

inline BYTE CCompressPackage::GetCompressMethod()
{
	return m_header.Method;
}

inline TCRPHeader *CCompressPackage::GetCRPHeader()
{
	return &m_header;
}

#endif // !defined(AFX_COMPRESSPACKAGE_H__81C278D7_1D6C_40FD_B2E7_E062464ECC11__INCLUDED_)
