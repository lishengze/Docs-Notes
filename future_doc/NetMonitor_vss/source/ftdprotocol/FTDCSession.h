// FTDCSession.h: interface for the CFTDCSession class .
//
// 20110224 ����   NT-0125:����mdkernel���û�logout֮�����յ����������
// 20120425 ����   NT-0139 �ӿ���Ӧʱ�䣺��ftdcЭ������֪ͨ����
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FTDCSESSION_H__88022E6A_66E9_46E0_B66F_8F73B23CDEFA__INCLUDED_)
#define AFX_FTDCSESSION_H__88022E6A_66E9_46E0_B66F_8F73B23CDEFA__INCLUDED_

#include "EventHandler.h"
#include "XMPSession.h"
#include "XMPProtocol.h"
#include "CompressProtocol.h"
#include "FTDCProtocol.h"
#include "FlowReader.h"

class CFTDCSession;

class CFTDCSessionCallback
{
public:
	virtual int HandlePackage(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession) = 0;
};

/**��һ�����Э��ջ���������ǻ���IO�����EventHandler�࣬һ������ListenCtrl
*������������ע�ᵽһ��Reactor�������ĵײ�������һ��TcpChannel�ϣ������ڵ�
*Э��ֻ��ͨ�������Ĳ��ܵõ���д���� */
class CFTDCSession : public CProtocolCallback, public CXMPSession
{
public:
	/**���캯�������Э��ջ�Ĺ���
	* @param pReactor   ��������
	* @param pChannel   һ��TcpChannel
	*/ 	
	CFTDCSession(CReactor *pReactor,CChannel *pChannel);
	
	/**�����������ͷſɿ���Դ
	*/
	virtual ~CFTDCSession();
	
	/**����һ����Ϣ
	* @param nEventID ��ϢID
	* @param dwParam ��һ������
	* @param pParam �ڶ�������
	* @return ������
	*/
	virtual int HandleEvent(int nEventID, DWORD dwParam, void *pParam);

	virtual int HandlePackage(CPackage *pPackage,CProtocol *pProtocol);

	/**����IO������������������CReactor����
	* @return ���� 
	*/
	virtual int HandleOther();
	
	void RegisterPackageHandler(CFTDCSessionCallback *pPackageHandler);

	void Publish(CReadOnlyFlow *pFlow, WORD wSequenceSeries, int nStartId);
	void UnPublish(WORD wSequenceSeries);
	void RegisterSubscriber(CFTDCSubscriber *pSubscriber);
	void UnRegisterSubscriber(CFTDCSubscriber *pSubscriber);
	
	CFTDCPackage *CreatePackage();
	
	void SendRequestPackage(CFTDCPackage *pPackage);
	
	void SetCommPhaseNo(WORD wCommPhaseNo);	

	virtual void Disconnect(int nErrorCode);

	/**�������FTDC��ѹ���㷨
	*@param chCompressMethod ѹ���㷨���룬0��ʾ��ѹ��
	*/
	void SetCompressMethod(BYTE chCompressMethod);
	
	/**���ñ��Ự�İ汾
	*@param	version	�汾��
	*/
	void SetVersion(BYTE version);
	
	/**��ȡ���Ự�İ汾
	*@return	���Ự�İ汾
	*/
	BYTE GetVersion(void);

	/**
	 * ��ѯ���еĶ�������
	 * @param topics ���붩�ĵ�����
	 */
	void QuerySubscribeTopic(vector<WORD>* topics);	

protected:
	CFTDCProtocol *m_pFTDCProtocol;		/**< FTDCЭ�����*/
	CCompressProtocol *m_pCRPProtocol;	/**< CRPЭ�����*/
	CFTDCSessionCallback *m_pPackageHandler;
	///-----
	///	���ض���20060223�������˶�FTDЭ��İ汾����
	///-----
	BYTE m_version;
};

#endif // !defined(AFX_FTDCSESSION_H__88022E6A_66E9_46E0_B66F_8F73B23CDEFA__INCLUDED_)
