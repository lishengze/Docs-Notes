// OFPPackage.h: interface for the COFPPackage class .
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OFPPACKAGE_H__INCLUDED_)
#define AFX_OFPPACKAGE_H__INCLUDED_

#include "Package.h"
#include "OFPDataType.h"

/* TODO: 设置OFP的ActiveID */
#define OFP_ACTIVEID         0

/* 最大的OFP协议报文长度 */
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

const WORD OFPFT_TRADE		= 1;		//交易流
const WORD OFPFT_PRIVATE	= 2;		//私有流
const WORD OFPFT_HEARTBEAT	= 3;		//心跳

/** OFP报头
 */
struct TOFPHeader
{
	COFPCharType Head;					/**< 开始标志，固定为0x01 */	
	COFPNullStringType<15> SenderAdd;	/**< PC端填0x20，交易系统返回信息时填PC登录用户名 */
	COFPStringType<2> SenderFlowType;
	COFPStringType<4> SenderFlowSeqNo;
	COFPNullStringType<15> ReceiverAdd;	/**< PC端发送时填本地用户名 */
	COFPStringType<2> ReceiveFlowType;
	COFPStringType<4> ReceiveFlowSeqNo;
	COFPCharType Start;					/**< 信息开始符 */
	WORD CommandID;						/**< 命令类型，二进制 */
	COFPCharType IsFirst;				/**< 信息状态 ‘1’第一次发送, 其他 非第一次 */
	COFPCharType NotLast;				/**< 信息行号 ‘0’结束,‘1’有后续行 */
	COFPNumberType<5> Length;			/**< 信息正文长度 + 28 */
	COFPStringType<8> Command;			/**< 命令字 */
	COFPStringType<20> Echo;			/**< 处理状态 */

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


/** 定义了OFPProtocol协议层所识别的Package */
class  COFPPackage : public CPackage  
{
public:
	/**构造函数
	 */
	COFPPackage();
	
	/**析构函数
	 */
	virtual ~COFPPackage();
	
	/**获得包的上层协议ID，用来路由
	 * @return 返回包的上层协议ID
	 */
	virtual DWORD GetActiveID();
	
	/**检查是否OFP报文，并解析出OFP报头
	 * @return PROTERR_OFP_BADPACKAGE 一个坏的OFP包文
	 * @return >0 完整的OFP包
	 * @return 0  部分的OFP包
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
