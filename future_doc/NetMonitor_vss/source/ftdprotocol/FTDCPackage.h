// FTDCPackage.h: interface for the CFTDCPackage class .
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FTDCPACKAGE_H__266F38F0_E245_4E93_89AB_65BC7D438E18__INCLUDED_)
#define AFX_FTDCPACKAGE_H__266F38F0_E245_4E93_89AB_65BC7D438E18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "FieldSet.h"
#include "Package.h"

#define FTDC_PACKAGE_MAX_SIZE	4000

const BYTE FTDC_CHAIN_CONTINUE	= 'C';		//���������м�FTDC���ġ�
const BYTE FTDC_CHAIN_LAST		= 'L';		//�����������һ��FTDC���ġ�

/**FTDC����ͷ�ṹ
*/
struct	TFTDCHeader
{
	BYTE	Version;			/**< �汾��	1	�������޷���������Ŀǰ�汾Ϊ1*/
	BYTE	Chain;				/**< ������	1	ASCII���ַ���*/
	WORD	SequenceSeries;		/**< ��������	2	�������޷��Ŷ�������*/
	DWORD	TransactionId;		/**<��TID��	FTD��Ϣ��������	4	�������޷���������*/
	DWORD	SequenceNumber;		/**<��SeqNo��	���к�	4	�������޷���������*/
	WORD	FieldCount;			/**< ����������	2	�������޷��Ŷ�������*/
	WORD	FTDCContentLength;	/**< FTDC��Ϣ���ĳ���	2	�������޷��Ŷ����������ֽ�Ϊ��λ��*/
	DWORD	RequestId;			/**< ������(�ɷ���������ά����Ӧ���л����)  4 �������޷���������*/
	
	inline void Init();
	inline void ChangeEndian();
	inline void ToStream(char *pStream);
	inline void FromStream(char *pStream);
};

inline void TFTDCHeader::Init()
{
	memset(this, 0 ,sizeof(TFTDCHeader));
}

inline void TFTDCHeader::ChangeEndian()
{
	CHANGE_ENDIAN(SequenceSeries);
	CHANGE_ENDIAN(TransactionId);
	CHANGE_ENDIAN(SequenceNumber);
	CHANGE_ENDIAN(FieldCount);
	CHANGE_ENDIAN(FTDCContentLength);
	CHANGE_ENDIAN(RequestId);
}

inline void TFTDCHeader::ToStream(char *pStream)
{
	memcpy(pStream, this, sizeof(TFTDCHeader));
	((TFTDCHeader *)pStream)->ChangeEndian();
}

inline void TFTDCHeader::FromStream(char *pStream)
{
	memcpy(this, pStream, sizeof(TFTDCHeader));
	ChangeEndian();
}

const int  FTDCHLEN	= sizeof(TFTDCHeader);

/**������FTDCProtocolЭ�����ʶ���Package
*/
class  CFTDCPackage : public CFieldSet
{
public:
	/**���캯������ʼ����Ա������
	*/
	CFTDCPackage();
		
	/**��������
	*/
	virtual ~CFTDCPackage();
	
	/**��ð����ϲ�Э��ID������·��
	* @return ���ذ����ϲ�Э��ID
	*/
	virtual DWORD GetActiveID();
	
	/**������XMP��ͷ������Ƿ�FTDC���ģ�������ÿ�����ƫ����
	* @return PROTERR_FTDC_BADPACKAGAE һ������FTDC����
	* @return >0 ������FTDC��
	*/
	virtual int ValidPackage();
	
	virtual int MakePackage();

	inline TFTDCHeader *GetFTDCHeader();
		
	inline DWORD GetTID();

	inline void SetChain(BYTE chain);

	inline BYTE GetChain();
	
	inline void SetRequestId(DWORD requestId);

	inline DWORD GetRequestId();
	
	inline BYTE GetVersion();
	
	void PreparePackage(DWORD tid, BYTE chain, BYTE version);

	void PrepareResponse(CFTDCPackage *pRequest, DWORD tid, BYTE chain, BYTE version);

	void OutputHeader(CLogger *pLogger);

	/**����һ��FTDC����������ռ䡣�ռ��СΪ�����ռ䣫FTDC����ļ�����
	* @param nReserve package�����ռ��С
	* @retrun ��������FTDC��
	*/
	static CFTDCPackage *CreatePackage(int nHeaderReserve);

protected:
	TFTDCHeader m_FTDCHeader;	  /**< FTDC��ͷ*/
};

inline TFTDCHeader *CFTDCPackage::GetFTDCHeader()
{ 
	return &m_FTDCHeader;
}

inline DWORD CFTDCPackage::GetTID()
{
	return m_FTDCHeader.TransactionId;
}

inline void CFTDCPackage::SetChain(BYTE chain)
{
	m_FTDCHeader.Chain = chain;
}

inline BYTE CFTDCPackage::GetChain()
{
	return m_FTDCHeader.Chain;
}

inline void CFTDCPackage::SetRequestId(DWORD requestId)
{
	m_FTDCHeader.RequestId =requestId;
}

inline DWORD CFTDCPackage::GetRequestId()
{
	return m_FTDCHeader.RequestId;
}

inline BYTE CFTDCPackage::GetVersion()
{
	return m_FTDCHeader.Version;
}

#define FTDC_GET_SINGLE_FIELD(pPackage, pField)	((pPackage)->GetSingleField(&((pField)->m_Describe), (pField)))
#define FTDC_ADD_FIELD(pPackage, pField) ((pPackage)->AddField(&((pField)->m_Describe), (pField)))

#ifndef DEBUG_NOT_LOG
#define FTDC_HEADER_DEBUG(pPackage)											\
	{ if (UseNetPackageLog) (pPackage)->OutputHeader(CLogger::GetInstance()); }
#define FTDC_PACKAGE_DEBUG(pPackage)										\
{																			\
	if (UseNetPackageLog)													\
	{																		\
		(pPackage)->OutputHeader(CLogger::GetInstance());						\
		FTDC_DEBUG_BODY((pPackage)->GetTID(), pPackage, CLogger::GetInstance());\
	}																		\
}
#else
#define FTDC_HEADER_DEBUG(pPackage)
#define FTDC_PACKAGE_DEBUG(pPackage)
#endif

#endif // !defined(AFX_FTDCPACKAGE_H__266F38F0_E245_4E93_89AB_65BC7D438E18__INCLUDED_)
