// XTPSession.h: interface for the CXTPSession class .
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XTPSESSION_H__88022E6A_66E9_46E0_B66F_8F73B23CDEFA__INCLUDED_)
#define AFX_XTPSESSION_H__88022E6A_66E9_46E0_B66F_8F73B23CDEFA__INCLUDED_

#include "EventHandler.h"
#include "XMPSession.h"
#include "XMPProtocol.h"
#include "XTPProtocol.h"
#include "FlowReader.h"

class CXTPSession;

class CXTPReqCallback
{
public:
	virtual int HandleRequest(CXTPPackage *pXTPPackage, CXTPSession *pSession) = 0;
};

class CXTPRspCallback
{
public:
	virtual int HandleResponse(CXTPPackage *pXTPPackage, CXTPSession *pSession) = 0;
};

/**��һ�����Э��ջ���������ǻ���IO�����EventHandler�࣬һ������ListenCtrl
*������������ע�ᵽһ��Reactor�������ĵײ�������һ��TcpChannel�ϣ������ڵ�
*Э��ֻ��ͨ�������Ĳ��ܵõ���д���� */
class CXTPSession : public CProtocolCallback, public CXMPSession , public CXTPPubHelper, public CXTPSubHelper 
{
public:
	/**���캯�������Э��ջ�Ĺ���
	* @param pReactor   ��������
	* @param pChannel   һ��TcpChannel
	*/ 	
	CXTPSession(CReactor *pReactor,CChannel *pChannel);
	
	/**�����������ͷſɿ���Դ
	*/
	virtual ~CXTPSession();
	
	/**����һ����Ϣ
	* @param nEventID ��ϢID
	* @param dwParam ��һ������
	* @param pParam �ڶ�������
	* @return ������
	*/
	virtual int HandleEvent(int nEventID, DWORD dwParam, void *pParam);

	virtual int HandlePackage(CPackage *pPackage,CProtocol *pProtocol);

	void RegisterReqHandler(CXTPReqCallback *pReqHandler);
	void RegisterRspHandler(CXTPRspCallback *pRspHandler);

	void Publish(CReadOnlyFlow *pFlow, DWORD nSubjectID, WORD nCommPhaseNo,
		DWORD dwSubscriberID, int nStartId);
	void UnPublish(DWORD nSubjectID);
	void RegisterSubscriber(CSubscriber *pSubscriber, DWORD dwSubscriberID);
	void UnRegisterSubscriber(CSubscriber *pSubscriber);
	CXTPPackage *CreatePackage();
	void SendRequestPackage(CXTPPackage *pPackage);
	void OnHeartBeat(DWORD nSubjectID, WORD nCommPhaseNo, int nSeqNo);
	void OnAck(DWORD dwSubscriberID, DWORD dwSubjectID, 
			int nStartId, WORD wCommPhaseNo);
	void SetSubCommPhaseNo(WORD nCommPhaseNo);
	
protected:
	CXTPProtocol *m_pXTPProtocol;	/**< �����ڵĵ�����Э��(���²���ʼ)*/
	CXTPReqCallback *m_pReqHandler;
	CXTPRspCallback *m_pRspHandler;
};

#endif // !defined(AFX_XTPSESSION_H__88022E6A_66E9_46E0_B66F_8F73B23CDEFA__INCLUDED_)
