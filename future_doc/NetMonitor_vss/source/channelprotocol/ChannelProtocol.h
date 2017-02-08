// ChannelProtocol.h: interface for the CChannelProtocol class .
//
// 20080620 �Ժ�� ���Ӽ���Ƿ�д��æ�Ľӿ�IsWriteBusy
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHANNELPROTOCOL_H__0549DC45_A2F7_4322_A176_2EC29CC059FD__INCLUDED_)
#define AFX_CHANNELPROTOCOL_H__0549DC45_A2F7_4322_A176_2EC29CC059FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Protocol.h"
#include "Channel.h"
#include "CacheList.h"
#include "ChannelPackage.h"

#define MSG_CHNLERR_READ		0x1001
#define MSG_CHNLERR_WRITE		0x1002
#define MSG_DRSTROY_ME			0x1003

/**Э��ջ��������ײ�Э�飬����������з��ͺͽ����������ݰ��������ݵ��ϲ�Э��
*/
class  CChannelProtocol : public CProtocol  
{
public:
	/**���캯��
	* @param pReactor ָ�����������ָ��
	* @param pChannel �����Channelָ��
	* @param nPackageMaxSize ���ܻ���������󳤶�
	*/
	CChannelProtocol(CReactor *pReactor,CChannel *pChannel,int nPackageMaxSize);
	
	/**��������
	*/
	virtual ~CChannelProtocol();

	/**�����Ͱ����ӵķ����б�,ͬʱ�������б���δ���͵�����ת����ȥ
	* @param pPackage ��Ҫ���͵İ�ָ��
	*/
	virtual int Push(CPackage *pPackage, CProtocol *pUpper);
	
	/**��ȡChannel��Id��������Ƿ��з�������
	* @param pReadId�� Channel��Id�����ڷ��ء�
	* @param pWriteId  ����Ƿ��з����������У�����Channel��Id�����򣬷���NULL
	*/
	virtual void GetIds(int *pReadId, int *pWriteId);
	
	/**���������ã�����������ȡ���ݰ����������ϲ�Э��
	* @return 0   �ɹ�
	* @return <>0 ʧ��
	*/
	virtual int HandleInput();
	
	/**���������ã����������緢�����ݰ�
	* @return >=0   �ɹ�
	* @return <0    ʧ��
	*/
	virtual int HandleOutput();

	/**����ʱ��������CReactor����
	* @param nIDEvent ��ʱ����ʶ   
	*/
	virtual void OnTimer(int nIDEvent);

	/**���������緢�����ݰ�
	* @return >=0   �ɹ�
	* @return <0    ʧ��
	*/
	int Flush();
	
	/**����Ƿ���Ҫд��������
	* @return true ��Ҫд��������, false û��Ҫд��������
	*/
	bool IsWriteBusy();
protected:
	CChannel *m_pChannel;		/**< ָ��Channel��ָ�� */
	CCacheList m_CacheList;		/**< ���ͻ������� */
	CChannelPackage m_ChannelPackage; /**< ����Э��Ķ�ӦPackage */
};

#endif // !defined(AFX_CHANNELPROTOCOL_H__0549DC45_A2F7_4322_A176_2EC29CC059FD__INCLUDED_)
