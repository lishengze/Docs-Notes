// Session.h: interface for the CSession class .
//
// 20080620 �Ժ�� ���Ӽ���Ƿ�д��æ�Ľӿ�IsChannelWriteBusy
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SESSION_H__D0D24001_7352_4285_9A26_A5DAC8C09F03__INCLUDED_)
#define AFX_SESSION_H__D0D24001_7352_4285_9A26_A5DAC8C09F03__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "EventHandler.h"
#include "ChannelProtocol.h"

class CSession;

class CSessionCallback
{
public:
	virtual void OnSessionConnected(CSession *pSession) = 0;
	virtual void OnSessionDisconnected(CSession *pSession, int nReason) = 0;
	virtual void OnSessionWarning(CSession *pSession, int nReason, int nParam) = 0;
};


/**��һ�����Э��ջ�����������������²�Э����CSession��
���಻��ʵ������һ����Ϊ����TCP���ӵ�Э��ջ�Ļ��� */
class  CSession : public CEventHandler  
{
public:
	/**���캯��
	* @param pReactor   ��������
	* @param pChannel   ���²�Э��󶨵�Channel
	* @param MaxPackageSize  �ϲ�Э�������󳤶� 
	*/ 	
	CSession(CReactor *pReactor,CChannel *pChannel,int MaxPackageSize);

	/**��������
	*/
	virtual ~CSession();
	
	inline DWORD GetSessionID();

	/**�������пɶ����ݰ�ʱ������
	* @return 0   �ɹ�
	* @return <>0 ʧ��
	*/
	virtual int HandleInput();
	
	/**��Reactor������Ҫ�����緢�����ݰ�ʱ������
	* @return >=0   �ɹ�
	* @return <0    ʧ��
	*/
	virtual int HandleOutput();
	
	/**����һ����Ϣ
	* @param nEventID ��ϢID
	* @param dwParam ��һ������
	* @param pParam �ڶ�������
	* @return ������
	*/
	virtual int HandleEvent(int nEventID, DWORD dwParam, void *pParam);

	/**ȡ���²�Э��󶨵�Channel
	* @return ���²�Э��󶨵�Channel
	*/
	inline CChannel *GetChannel();

	/**�Ͽ���������
	* @param ErrorCode  ��·��ԭ��
	*/
	virtual void Disconnect(int nErrorCode);

	/**��ȡ����дsocket����selectʹ��
	* @param pReadId   ������������ض���ʹ�õ�socket��Ϊ0��ʾ����Ҫ��
	* @param pWriteId  �������������д��ʹ�õ�socket��Ϊ0��ʾ����Ҫд 
	*/
	virtual void GetIds(int *pReadId, int *pWriteId);

	inline void RegisterSessionCallback(CSessionCallback *pSessionCallback);

	/**����/�ָ�������
	*@param bSuspend true ���������    false�ָ������� 
	*/
	void SuspendRead(bool bSuspend);

	/**��Channel��־�ļ�
	*@param pszPath ��־�ļ�·��
	*@param pszFileName ��־�ļ���
	*@return true �ɹ�
	*@return false ʧ��
	*/
	bool OpenChannelLogFile(const char *pszPath, const char *pszFileName);

	/**�ر�Channel��־�ļ�
	*/
	void CloseChannelLogFile();

	/**���Channel�Ƿ���Ҫд��������
	* @return true ��Ҫд��������, false û��Ҫд��������
	*/
	bool IsChannelWriteBusy();
protected:	
	/**�����·��Ϣ�������ÿ�����������·ʱ���ô˺���
	* @param ErrorCode  ��·��ԭ��
	*/
	virtual void OnChannelLost(int nErrorCode);
protected:
	DWORD m_nSessionID;

	CChannel *m_pChannel;		/**< ���������Channel */
	CChannelProtocol *m_pChannelProtocol;	/**< �����ڵĵײ�Э�� */
	CSessionCallback *m_pSessionCallback;

	bool m_bSuspendRead;
};

inline CChannel *CSession::GetChannel()
{
	return m_pChannel;
}

inline void CSession::RegisterSessionCallback(CSessionCallback *pSessionCallback)
{
	m_pSessionCallback = pSessionCallback;
}

inline DWORD CSession::GetSessionID()
{
	return m_nSessionID;
}

#endif // !defined(AFX_SESSION_H__D0D24001_7352_4285_9A26_A5DAC8C09F03__INCLUDED_)
