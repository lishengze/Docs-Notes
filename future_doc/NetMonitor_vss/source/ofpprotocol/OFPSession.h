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
	/**处理一条消息
	* @param nEventID 消息ID
	* @param dwParam 第一个参数
	* @param pParam 第二个参数
	* @return 处理结果
	*/
	virtual int HandleEvent(int nEventID, DWORD dwParam, void *pParam);

	/**获取读、写socket，供select使用
	* @param pReadId   输出参数，返回读所使用的socket，为0表示不需要读
	* @param pWriteId  输出参数，返回写所使用的socket，为0表示不需要写
	* @remark 在这里将发布的主题的数据包传递到最下层协议
	*/
	virtual void GetIds(int *pReadId, int *pWriteId);
	void RegisterPackageHandler(COFPSessionCallback *pPackageHandler);
	void SendRequestPackage(COFPPackage *pPackage);
	int HandlePackage(CPackage *pPackage,CProtocol *pProtocol);
	void Publish(CReadOnlyFlow *pFlow, WORD nSequenceSeries, int nStartId);
	void UnPublish(WORD nSequenceSeries);

	/**断开网络连接
	* @param ErrorCode  断路的原因
	*/
	virtual void Disconnect(int nErrorCode);
protected:
	COFPProtocol *m_pOFPProtocol;	/**< 容器内的第二层协议(从下部开始)*/
	COFPSessionCallback *m_pPackageHandler;
};

#endif // !defined(AFX_OFPSESSION_H__INCLUDED_)
