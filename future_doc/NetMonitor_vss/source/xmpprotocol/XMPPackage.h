// XMPPackage.h: interface for the CXMPPackage class .
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XMPPACKAGE_H__6238837B_1BF1_4671_A846_646A4E8DADC7__INCLUDED_)
#define AFX_XMPPACKAGE_H__6238837B_1BF1_4671_A846_646A4E8DADC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Package.h"
#include "FieldDescribe.h"

#define XMP_PACKAGE_MAX_SIZE	4096
#define XMP_EXTHEAD_MAX_SIZE	127

#define XMPTagNone				0x00
#define XMPTagDatetime			0x01
#define XMPTagCompressMethod	0x02
#define XMPTagTransactionId		0x03
#define XMPTagSessionState		0x04
#define XMPTagKeepAlive			0x05
#define XMPTagTradedate			0x06
#define XMPTagHeartbeatTimeOut	0x07

/**XMP��ͷ
*/
struct TXMPHeader
{
	BYTE Type;			/**< ��ʾ�ϲ�Э���Э��ID */	
	BYTE ExtensionLen;	/**< ��չ���ĳ��� */
	WORD Length;		/**< ���峤�� */
	
	inline void Init();
	inline void ChangeEndian();
	inline void ToStream(char *pStream);
	inline void FromStream(char *pStream);
};

inline void TXMPHeader::Init()
{
	memset(this, 0 ,sizeof(TXMPHeader));
}

inline void TXMPHeader::ChangeEndian()
{
	CHANGE_ENDIAN(Length);
}

inline void TXMPHeader::ToStream(char *pStream)
{
	memcpy(pStream, this, sizeof(TXMPHeader));
	((TXMPHeader *)pStream)->ChangeEndian();
}

inline void TXMPHeader::FromStream(char *pStream)
{
	memcpy(this, pStream, sizeof(TXMPHeader));
	ChangeEndian();
}


/**��չXMP��ͷ
*/
struct TXMPExtHeader
{
	BYTE Tag;		/**< ״̬��ʾ��*/
	BYTE TagLen;	/**< ��չ���ĳ��� */
	BYTE Data[XMP_EXTHEAD_MAX_SIZE];	/**< ��չ������ */
	inline void Init();
};

inline void TXMPExtHeader::Init()
{
	memset(this, 0 ,sizeof(TXMPExtHeader));
}

//#pragma pack(4)

const int XMPHLEN = sizeof(TXMPHeader);
const int XMPEXTHLEN = 2;

/**������XMPProtocolЭ�����ʶ���Package
*/
class  CXMPPackage : public CPackage  
{
public:
	/**���캯��
	*/
	CXMPPackage();
	
	/**��������
	*/
	virtual ~CXMPPackage();
	
	/**��ð����ϲ�Э��ID������·��
	* @return ���ذ����ϲ�Э��ID
	*/
	virtual DWORD GetActiveID();
	
	/**����Ƿ�XMP���ģ���������XMP��ͷ
	* @return PROTERR_XMP_BADPACKAGE һ������XMP����
	* @return >0 ������XMP��
	* @return 0  ���ֵ�XMP��
	*/
	virtual int ValidPackage();
	
	/**��װ���ݰ�
	* @return 0 ��װ�ɹ�
	* @return <0 ��װʧ��
	*/
	virtual int MakePackage();

	inline TXMPHeader *GetXMPHeader();
	/**��ð���ĳ��ȣ�����XTP��ͷ
	* @return ����ĳ��ȣ�����XTP��ͷ
	*/
	inline int GetBodyLength();
	
	/**�����չ��ͷ�ĳ���
	* @return ��չ��ͷ�ĳ���
	*/
	inline BYTE GetExtensionLen();
	
	/**�����չ��ͷ�ı�ʾ
	* @return ��չ��ͷ�ı�ʾ
	*/
	inline BYTE GetExtTag();
	
	/**�����չ��ͷ���ݵĳ���
	* @return ��չ��ͷ���ݵĳ���
	*/
	inline BYTE GetExtTagLen();

	/**�����չ��ͷ������
	*@return ��չ��ͷ������
	*/
	inline BYTE *GetExtData();

	/**������չ��ͷ����
	*@param Tag ��չ��ͷ�ı�ʾ
	*@param TagLen ��չ��ͷ���ݵĳ���
	*@param pData ��չ��ͷ������
	*/
	void SetExtHeader(BYTE Tag, BYTE TagLen, BYTE *pData );
protected:
	TXMPHeader m_XMPHeader;		/**< XMP��ͷ */
	TXMPExtHeader m_ExtHeader;	/**< XMP��չ��ͷ */
};

inline TXMPHeader *CXMPPackage::GetXMPHeader()
{
	return &m_XMPHeader;
}

inline int CXMPPackage::GetBodyLength()
{
	return m_XMPHeader.Length;
}

inline BYTE CXMPPackage::GetExtensionLen()
{
	return m_XMPHeader.ExtensionLen;
}

inline BYTE CXMPPackage::GetExtTag()
{
	return m_ExtHeader.Tag;
}

inline BYTE CXMPPackage::GetExtTagLen()
{
	return m_ExtHeader.TagLen;
}

inline BYTE *CXMPPackage::GetExtData()
{
	return m_ExtHeader.Data;
}


#endif // !defined(AFX_XMPPACKAGE_H__6238837B_1BF1_4671_A846_646A4E8DADC7__INCLUDED_)
