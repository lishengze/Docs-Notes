// XMPProtocol.h: interface for the CXMPProtocol class .
//
// 2007.8.1 �Ժ�� ���Ӷ�������ʱ����
// 20090427 �Ժ�� NT-0071������SetHeartbeatMode����
//                 �������ģʽΪSlave������Է���������ʱʱ��һ��
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XMPPROTOCOL_H__E6E924C0_24C7_45EA_BDF8_BC0B09962ABE__INCLUDED_)
#define AFX_XMPPROTOCOL_H__E6E924C0_24C7_45EA_BDF8_BC0B09962ABE__INCLUDED_

#include "Protocol.h"
#include "XMPPackage.h"

#define MSG_XMPERR_RECVHEARTBEAT		0x2001
#define MSG_XMPERR_SENDHEARTBEAT		0x2002
#define MSG_XMPERR_BADPACKAGE			0x2003

#define MSG_XMPWARNING_RECVHEARTBEAT	0x2101

#define XMPTypeNone				0x00
#define XMPTypeBinary			0x01
#define XMPTypeCompressed		0x02
#define XMPTypeSCP				0x03
#define XMPTypeXTP				0x04

const DWORD XMPHBT_SLAVE_MODE	= 0x00000001;

/**Э��ջ�����ĵڶ���Э�飬��Ҫ������·����
*/
class  CXMPProtocol : public CProtocol  
{
public:
	/**���캯��
	* @param pReactor ָ�����������ָ��
	* @param pBelow �²�Э���ָ��
	*/
	CXMPProtocol(CReactor *pReactor);
	/**��������
	*/
	virtual ~CXMPProtocol();

	/**����XMP��ͷ�������²�Э��
	* @param pPackage �ϲ��Э���´��İ�
	* @return 0   �ɹ�
	* @return <>0 ʧ��
	*/
	virtual int Push(CPackage *pPackage, CProtocol *pUpper);
	
	void EnableHeartbeat(bool bEnable);

	void SetHeartbeatTimeout(DWORD dwReadTimeout);

	void SetHeartbeatMode(DWORD dwHeartbeatMode);
protected:	
	/**��¼��ǰ�յ�����ʱ�䣬�ж��Ƿ�XMP�������ϴ�
	* @param pPackage �²�Э���ϴ��İ�
	* @return 0   �ɹ�
	* @return <>0 ʧ��
	*/
	virtual int Pop(CPackage *pPackage);
		
	/**����ʱ��������CReactor���á�����������ʱ����֪ͨ�ϲ�Э�顣
	* ������д��ʱ�������������ġ�
	* @param nIDEvent ������Ϊ��ʱ��ʱ���ڶ�ʱ������ʱ����ʶ   
	*/
	virtual void OnTimer(int nIDEvent);
		
	/**�����������ģ�����������
	* @return >0   �ɹ�
	* @return <=0  ʧ�� 
	*/
	int SendHeartbeat();

	/**���ɲ���������������ʱ����
	* @return >0   �ɹ�
	* @return <=0  ʧ�� 
	*/
	int SendWriteTimeout(DWORD dwWriteTimeout);

	/**��������������ʱ���ģ����÷���������ʱʱ��
	* @param pPackage ����������ʱ����
	*/
	void SetWriteTimeout(CXMPPackage *pPackage);

	/**�յ�һ����������ݰ�ʱ����
	* @param pPackage ��������ݰ�
	* @return 0   �ɹ�
	* @return <>0 ʧ��
	*/
	virtual int OnRecvErrorPackage(CPackage *pPackage);

protected:
	DWORD m_LastWriteTime;		/**< ��󷢰�ʱ�䡡*/
	DWORD m_LastReadTime;		/**< ����հ�ʱ�䡡*/
	DWORD m_LastWarnTime;		/**< ��󷢳�����ʱ�䡡*/
	bool m_bHeartEnable;		/**< �Ƿ����/�������� */
	DWORD m_dwWriteTimeout;		/**< ����������ʱ���� */
	DWORD m_dwReadTimeout;		/**< ���������ĳ�ʱʱ�� */
	DWORD m_dwWarningTimeout;	/**< ���������ı���ʱ�� */
	DWORD m_dwHeartbeatMode;	/**< ����ʱ��ģʽ*/
};

#endif // !defined(AFX_XMPPROTOCOL_H__E6E924C0_24C7_45EA_BDF8_BC0B09962ABE__INCLUDED_)
