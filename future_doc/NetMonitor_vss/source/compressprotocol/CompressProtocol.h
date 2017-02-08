// CompressProtocol.h: interface for the CCompressProtocol class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPRESSPROTOCOL_H__2F2723AB_21B2_4DE3_BD36_623611717FFB__INCLUDED_)
#define AFX_COMPRESSPROTOCOL_H__2F2723AB_21B2_4DE3_BD36_623611717FFB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Protocol.h"
#include "CompressPackage.h"

struct TCRPCompressMethod
{
	BYTE Method;
	BYTE ActiveID;
};

#define CRPCM_NONE	0x00		//��ѹ��
#define CRPCM_ZERO	0x03		//ֻѹ��0x00���г�ѹ��

class CCompressProtocol : public CProtocol  
{
public:
	CCompressProtocol(CReactor *pReactor);
	virtual ~CCompressProtocol();

	/**����CRP��ͷ�������²�Э��
	* @param pPackage �ϲ��Э���´��İ�
	* @return 0   �ɹ�
	* @return <>0 ʧ��
	*/
	virtual int Push(CPackage *pPackage, CProtocol *pUpper);
	
	/**��������ϲ�Э���ѹ���㷨
	*@param chCompressMethod ѹ���㷨���룬0��ʾ��ѹ��
	*@param chActiveID �ϲ�Э�����
	*/
	void SetCompressMethod(BYTE chActiveID, BYTE chCompressMethod);	

protected:	
	/**�ж��Ƿ�CRP�������ϴ�
	* @param pPackage �²�Э���ϴ��İ�
	* @return 0   �ɹ�
	* @return <>0 ʧ��
	*/
	virtual int Pop(CPackage *pPackage);

	/**ȡ����ϲ�Э���ѹ���㷨
	*@param chActiveID �ϲ�Э�����
	*@return ѹ���㷨����
	*/
	BYTE GetCompressMethod(BYTE chActiveID);

protected:
	typedef vector<TCRPCompressMethod> CCompressMethodArray;
	CCompressMethodArray m_CompressMethods;	/**< �ϲ�Э��ѹ���㷨�� */

	CCompressPackage m_pkgCommpress;
};

#endif // !defined(AFX_COMPRESSPROTOCOL_H__2F2723AB_21B2_4DE3_BD36_623611717FFB__INCLUDED_)
