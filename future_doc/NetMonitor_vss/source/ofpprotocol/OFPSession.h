// XMPSession.h: interface for the COPFSession class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OFPSESSION_H__INCLUDED_)
#define AFX_OFPSESSION_H__INCLUDED_

#include "Session.h"
#include "OFPProtocol.h"

enum TOFPSequenceSeries
{
	TOSS_DIALOG = 1,
	TOSS_PRIVATE,
	TOSS_HEARTBEAT
};

class COFPSession;

class COFPSessionCallback
{
public:
	virtual int HandlePackage(COFPPackage *pOFPPackage, COFPSession *pSession) = 0;
};

class COFPSession : public CProtocolCallback, public CSession  
{
public:
	COFPSession(CReactor *pReactor, CChannel *pChannel, char chVersion);
	virtual ~COFPSession();
	/**����һ����Ϣ
	* @param nEventID ��ϢID
	* @param dwParam ��һ������
	* @param pParam �ڶ�������
	* @return ������
	*/
	virtual int HandleEvent(int nEventID, DWORD dwParam, void *pParam);

	/**��ȡ����дsocket����selectʹ��
	* @param pReadId   ������������ض���ʹ�õ�socket��Ϊ0��ʾ����Ҫ��
	* @param pWriteId  �������������д��ʹ�õ�socket��Ϊ0��ʾ����Ҫд
	* @remark �����ｫ��������������ݰ����ݵ����²�Э��
	*/
	virtual void GetIds(int *pReadId, int *pWriteId);
	void RegisterPackageHandler(COFPSessionCallback *pPackageHandler);
	void SendRequestPackage(COFPPackage *pPackage);
	int HandlePackage(CPackage *pPackage,CProtocol *pProtocol);
	void Publish(CReadOnlyFlow *pFlow, WORD nSequenceSeries, int nStartId);
	void UnPublish(WORD nSequenceSeries);

	/**�Ͽ���������
	* @param ErrorCode  ��·��ԭ��
	*/
	virtual void Disconnect(int nErrorCode);
protected:
	COFPProtocol *m_pOFPProtocol;	/**< �����ڵĵڶ���Э��(���²���ʼ)*/
	COFPSessionCallback *m_pPackageHandler;
};

#endif // !defined(AFX_OFPSESSION_H__INCLUDED_)
