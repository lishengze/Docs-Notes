// ChannelPackage.h: interface for the CChannelPackage class .
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHANNELPACKAGE_H__00F274CE_45A3_4A38_B141_80AFB60B6D1D__INCLUDED_)
#define AFX_CHANNELPACKAGE_H__00F274CE_45A3_4A38_B141_80AFB60B6D1D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Package.h"
#include "Channel.h"

/**�����Channel��ȡ��ԭʼ��Package
*/
class  CChannelPackage : public CPackage  
{
public:
	/**���캯��
	* @param nPackageMaxSize���������ݻ���������, Ӧ����Э��ջ�ܴ��������ĳ���
	*/ 
	CChannelPackage(int nPackageMaxSize);
	
	/**��������
	*/
	virtual ~CChannelPackage();
	
	/**��Channel�ж�ȡ����
	* @param pChannel ָ��Channelָ��
	* @return ��Channel�ж��������ݳ���
	*/ 
	int ReadFromChannel(CChannel *pChannel);
	
	/**ͨѶ���ϴ�ʱ���ϲ�Э��ı�ţ�������з��ص���XMPProtocolЭ����
	* @return �ϲ�Э��ı�� ˵��(����������0����Ϊ�ϲ�Э��ֻ��XMPProtocol��
	* �ұ��Ϊ0)
	*/
	virtual DWORD GetActiveID();
	
	/** �����������Ƿ񹹳�һ�������İ���˵��(���ڶ�ӦЭ��δ�����������
	* �������Ƿ������������ݰ�)
	* @return 1 ��һ�������İ� 
	* @return 0 ���ݰ�������
	* @return -1 ���ݰ��д���
	*/
	virtual int ValidPackage();
};

#endif // !defined(AFX_CHANNELPACKAGE_H__00F274CE_45A3_4A38_B141_80AFB60B6D1D__INCLUDED_)
