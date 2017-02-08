// Protocol.h: interface for the CProtocol class .
//
// 20080620 �Ժ�� NT_0037֧��SA��CProtocol֧�ְ󶨶���²�Э��
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROTOCOL_H__A624208D_B81A_463B_BC44_D35D7B0EAC6C__INCLUDED_)
#define AFX_PROTOCOL_H__A624208D_B81A_463B_BC44_D35D7B0EAC6C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Package.h"
#include "Reactor.h"

#define PNOTIFY_NOHEARTBEAT		0x1001			//��������ʱ
#define PNOTIFY_ERRHEARTBEAT	0x1002			//��������ʧ��

class CProtocol;

class CProtocolCallback
{
public:
	virtual int HandlePackage(CPackage *pPackage, CProtocol *pProtocol) = 0;
};

/**CProtocol��һ�����������Э���࣬ÿ��Э���ʵ�ֶ���Ҫ�̳�����
* һ��CProtocol�������ע��һ���²�Э��Ͷ���ϲ�Э�顣
* ͨ��Pop()���������ݰ��Ĵ��ݵ��ϲ�Э�飬ͨ��Push()���������ݰ����ݵ��²�Э�顣
*/
class  CProtocol : public CProtocolCallback, public CEventHandler
{
public:
	/**���캯��
	* @param pReactor ָ�����������ָ��
	* @param nHdrReserveLen ����Э��İ�ͷ����
	* @param pDemuxPackage ����Э���ϴ�ʹ�õİ�
	* @param pSendPackage ����Э���´�ʹ�õİ�
	*/
	CProtocol(CReactor *pReactor, int nHdrReserveLen, 
		CPackage *pDemuxPackage, CPackage *pSendPackage);
		
	/**��������
	*/
	virtual ~CProtocol();
	
	/**ע���²�Э��
	*@param pLower �²�Э��
	*@param nActiveID ���²�Э����ԣ�����Э��ı��
	*/
	virtual void AttachLower(CProtocol *pLower, DWORD nActiveID);
	
	/**ȡ���²�Э��
	*@param pLower �²�Э��
	*@param nActiveID ���²�Э����ԣ�����Э��ı��
	*/
	virtual void DetachLower(CProtocol *pLower);
	
	/**ע���������
	* @param pErrorHandler ��������
	* @remark ���ִ���ʱ��֪ͨ�ô����������д���
	*/
	inline void RegisterErrorHandler(CEventHandler *pErrorHandler);

	/**ע�����ݰ�������
	*@param pUpperHandler ���ݰ�������
	*@remark ����ַ����ݰ�ʱ���Ҳ������ʵ��ϲ�Э�飬�����ݰ�����
	*@remark ע������ݰ�������������ͨ��������Э��ջ�����ϲ㡣
	*/
	inline void RegisterUpperHandler(CProtocolCallback *pUpperHandler);

	/**�����ݰ��ӱ���Э�鴫�ݵ��²�Э��
	* @param pPackage ����Э��İ�
	* @return 0   �ɹ�
	* @return <>0 ʧ��
	*/
	virtual int Send(CPackage *pPackage, CProtocol *pUpper = NULL);
	
	/**��Э��ջ�У��ӵײ㵽����Э������а�ͷ�������ȵĺ�
	* @return �ӵײ㵽����Э������а�ͷ�������ȵĺ�
	*/
	inline int GetHdrReserveLen();

	/**�񵽱�Э������Э����
	*@return ��Э������Э����
	*@remark Э����������²�Э����Եģ�ֻ��ע�����²�Э�飬��������������
	*/
	inline DWORD GetActiveID();

	/**���²�Э���XTPControl�������ã��ڱ���Э��ʵ�ְ���
	* ��顢����ͼ����ϴ����ϲ�Э�顣
	* @param pPackage �²�Э�鴫���İ�ָ��
	* @param pProtocol �²�Э��
	* @return 0   �ɹ�
	* @return <>0 ʧ��
	*/		
	virtual int HandlePackage(CPackage *pPackage, CProtocol *pProtocol);
		
protected:
	
	/**ע���ϲ�Э��
	* @param pUpper �ϲ�Э���Э��ָ��
	*/
	void AddUpper(CProtocol *pUpper);

	/**����Э���ţ������ϲ�Э��
	* @return �ϲ�Э���ָ��
	*/
	inline CProtocol *GetUpper(DWORD nActiveID);
	
	/**����Э���ţ����ϲ�Э��ȡ��ע��
	* @param ActiveID �ϲ�Э���Э��ID
	* @return �ϲ�Э���ָ��
	*/
	CProtocol *RemoveUpper(DWORD nActiveID);
	
	/**�����ݰ��ַ��������ʵ��ϲ�Э��
	* @param pPackage ��Ҫ�ַ������ݰ�
	* @return 0   �ɹ�
	* @return <>0 ʧ��
	*/
	virtual int Pop(CPackage *pPackage);
	
	/**�յ�һ����������ݰ�ʱ����
	* @param pPackage ��������ݰ�
	* @return 0   �ɹ�
	* @return <>0 ʧ��
	*/
	virtual int OnRecvErrorPackage(CPackage *pPackage);
	
	/*֪ͨ��������
	* @param message ��ϢID
	* @param dwParam ˫���Ͳ���
	* @param pParam �޷���ָ���Ͳ���
	*/
	inline void NotifyError( int message, DWORD dwParam, void *pParam);

	/**�ϲ�Э�齫�����͵�����Э��
	*@param pPackage Ҫ���͵��ϲ�Э��İ�
	*@param pUpper �ϲ�Э��
	* @return 0   �ɹ�
	* @return <>0 ʧ��
	*/
	virtual int Push(CPackage *pPackage, CProtocol *pUpper);

	/**Ϊ���²�Э�鴫�Ͷ���װ���ݰ�
	*@param pPackage Ҫ��װ�����ݰ�
	*@param pUpper �ϲ�Э��
	* @return 0   �ɹ�
	* @return <>0 ʧ��
	*/
	virtual int MakePackage(CPackage *pPackage, CProtocol *pUpper);
protected:
	CPackage *m_pDemuxPackage;	/**< ��·�ֽ�ʱʹ�õ���ʱ������ֹ�ƻ��²㴫�����İ� */
	CPackage *m_pSendPackage;	/**< �´�ʹ�õ���ʱ��*/
	typedef vector<CProtocol *> CProtocolArray;
	CProtocolArray m_lowers;	/**< �²�Э��*/
	CProtocol *m_pUpper;		/**< �ϲ�Э��*/
	CProtocol *m_pBrother;		/**< ͬ��Э��*/
	int m_nHdrReserveLen;		/**< ��Э��ջ�У��ӵײ㵽����Э������а�ͷ���ȵĺ�*/
	DWORD m_nActiveID;			/**< ��Э������²�Э���е�Э����*/
	CProtocolCallback *m_pUpperHandler;	/**< ���ݰ������� */
protected:
	CEventHandler *m_pErrorHandler;
};

inline int CProtocol::GetHdrReserveLen()
{
	return m_nHdrReserveLen;
}


inline void CProtocol::RegisterErrorHandler(CEventHandler *pErrorHandler)
{
	m_pErrorHandler = pErrorHandler;
}

inline void CProtocol::RegisterUpperHandler(CProtocolCallback *pUpperHandler)
{
	m_pUpperHandler = pUpperHandler;
}

inline void CProtocol::NotifyError( int message, DWORD dwParam, void *pParam)
{
	if(m_pErrorHandler != NULL){
		m_pErrorHandler->SendEvent(message, dwParam, pParam);
	}
}

inline DWORD CProtocol::GetActiveID()
{
	return m_nActiveID;
}

inline CProtocol *CProtocol::GetUpper(DWORD nActiveID)
{
	CProtocol *pCurr = m_pUpper;
	while (pCurr != NULL)
	{
		if (pCurr->GetActiveID() == nActiveID)
		{
			break;
		}
		pCurr = pCurr->m_pBrother;
	}
	return pCurr;
}

#endif // !defined(AFX_PROTOCOL_H__A624208D_B81A_463B_BC44_D35D7B0EAC6C__INCLUDED_)
