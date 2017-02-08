// OFPPackage.h: interface for the COFPPackage class .
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OFPPACKAGE_H__INCLUDED_)
#define AFX_OFPPACKAGE_H__INCLUDED_

#include "Package.h"
#include "OFPDataType.h"

/* TODO: ����OFP��ActiveID */
#define OFP_ACTIVEID         0

/* ����OFPЭ�鱨�ĳ��� */
#define OFP_PACKAGE_MAX_SIZE 4096

const char OFP_VERSION_1	= 0x01;
const char OFP_VERSION_2	= 0x02;

const char OFP_IS_FIRST		= '1';
const char OFP_NOT_FIRST	= '0';

const char OFP_IS_LAST		= '0';
const char OFP_NOT_LAST		= '1';

extern const char *OFP_COMM_OK;
extern const char *OFP_COMM_ERROR;

const int OFPEXTHLEN = 28; /* Command+Echo */
const int OFPHLEN = 83;

const WORD OFPFT_TRADE		= 1;		//������
const WORD OFPFT_PRIVATE	= 2;		//˽����
const WORD OFPFT_HEARTBEAT	= 3;		//����

/** OFP��ͷ
 */
struct TOFPHeader
{
	COFPCharType Head;					/**< ��ʼ��־���̶�Ϊ0x01 */	
	COFPNullStringType<15> SenderAdd;	/**< PC����0x20������ϵͳ������Ϣʱ��PC��¼�û��� */
	COFPStringType<2> SenderFlowType;
	COFPStringType<4> SenderFlowSeqNo;
	COFPNullStringType<15> ReceiverAdd;	/**< PC�˷���ʱ����û��� */
	COFPStringType<2> ReceiveFlowType;
	COFPStringType<4> ReceiveFlowSeqNo;
	COFPCharType Start;					/**< ��Ϣ��ʼ�� */
	WORD CommandID;						/**< �������ͣ������� */
	COFPCharType IsFirst;				/**< ��Ϣ״̬ ��1����һ�η���, ���� �ǵ�һ�� */
	COFPCharType NotLast;				/**< ��Ϣ�к� ��0������,��1���к����� */
	COFPNumberType<5> Length;			/**< ��Ϣ���ĳ��� + 28 */
	COFPStringType<8> Command;			/**< ������ */
	COFPStringType<20> Echo;			/**< ����״̬ */

	inline void ChangeEndian();
	inline void ToStream(char *pStream);
	inline void FromStream(char *pStream);
};

inline void TOFPHeader::ChangeEndian()
{
	CHANGE_ENDIAN(CommandID);

	DWORD w;
	memcpy(&w, &SenderFlowType, sizeof(WORD));
	CHANGE_ENDIAN(w);
	memcpy(&SenderFlowType, &w, sizeof(WORD));

	memcpy(&w, &ReceiveFlowType, sizeof(WORD));
	CHANGE_ENDIAN(w);
	memcpy(&ReceiveFlowType, &w, sizeof(WORD));

	DWORD dw;
	memcpy(&dw, &SenderFlowSeqNo, sizeof(DWORD));
	CHANGE_ENDIAN(dw);
	memcpy(&SenderFlowSeqNo, &dw, sizeof(DWORD));

	memcpy(&dw, &ReceiveFlowSeqNo, sizeof(DWORD));
	CHANGE_ENDIAN(dw);
	memcpy(&ReceiveFlowSeqNo, &dw, sizeof(DWORD));
}

inline void TOFPHeader::ToStream(char *pStream)
{
	memcpy(pStream, this, OFPHLEN);
	((TOFPHeader *)pStream)->ChangeEndian();
}

inline void TOFPHeader::FromStream(char *pStream)
{
	memcpy(this, pStream, OFPHLEN);
	ChangeEndian();
}


/** ������OFPProtocolЭ�����ʶ���Package */
class  COFPPackage : public CPackage  
{
public:
	/**���캯��
	 */
	COFPPackage();
	
	/**��������
	 */
	virtual ~COFPPackage();
	
	/**��ð����ϲ�Э��ID������·��
	 * @return ���ذ����ϲ�Э��ID
	 */
	virtual DWORD GetActiveID();
	
	/**����Ƿ�OFP���ģ���������OFP��ͷ
	 * @return PROTERR_OFP_BADPACKAGE һ������OFP����
	 * @return >0 ������OFP��
	 * @return 0  ���ֵ�OFP��
	 */
	virtual int ValidPackage();
	
	virtual int MakePackage();

	inline TOFPHeader *GetOFPHeader();

	inline void SetCommandID(WORD wCommandID);

	inline WORD GetCommandID();

	inline const char *GetCommand();

	WORD GetFlowType();

	void SetFlowType(WORD wFlowType);

	int GetFlowSeqNo();

	void SetFlowSeqNo(int  nFlowSeqNo);

	void SetEcho(const char *pszComm, const char *pszEcho);
	
	inline int GetContentLength();

	void PreparePackage(const char chVersion, const WORD wCommandID,
		const char chIsFirst = OFP_IS_FIRST,  const char chNotLast = OFP_IS_LAST);

	char *AddBody(void *pBody, int nBodySize);

	void DebugOutput(CLogger *pLogger);
protected:
	TOFPHeader m_OFPHeader;
};

inline TOFPHeader *COFPPackage::GetOFPHeader()
{
	return &m_OFPHeader;
}

inline void COFPPackage::SetCommandID(WORD wCommandID)
{
	wCommandID = m_OFPHeader.CommandID;
}

inline WORD COFPPackage::GetCommandID()
{
	return m_OFPHeader.CommandID;
}

inline const char *COFPPackage::GetCommand()
{
	return m_OFPHeader.Command.getValue();
}


inline int COFPPackage::GetContentLength()
{
	return (int)m_OFPHeader.Length;
}

inline void COFPPackage::SetEcho(const char *pszComm, const char *pszEcho)
{
	m_OFPHeader.Command = pszComm;
	m_OFPHeader.Echo = pszEcho;
}


#define OFP_ADD_BODY(package, body)							\
	memcpy((package).Push(sizeof(body)), &(body), sizeof(body));
				
#endif // !defined(AFX_OFPPACKAGE_H__INCLUDED_)
