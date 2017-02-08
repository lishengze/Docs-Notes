// FTDCSession.h: interface for the CFTDCSession class .
//
// 20110224 江鹏   NT-0125:修正mdkernel在用户logout之后还能收到行情的问题
// 20120425 江鹏   NT-0139 加快响应时间：给ftdc协议增加通知功能
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

/**是一个存放协议栈的容器，是基于IO处理的EventHandler类，一般是由ListenCtrl
*创建，它必须注册到一个Reactor。容器的底部捆绑在一个TcpChannel上，容器内的
*协议只有通过容器的才能得到读写操作 */
class CFTDCSession : public CProtocolCallback, public CXMPSession
{
public:
	/**构造函数，完成协议栈的构造
	* @param pReactor   运行引擎
	* @param pChannel   一个TcpChannel
	*/ 	
	CFTDCSession(CReactor *pReactor,CChannel *pChannel);
	
	/**析构函数，释放可控资源
	*/
	virtual ~CFTDCSession();
	
	/**处理一条消息
	* @param nEventID 消息ID
	* @param dwParam 第一个参数
	* @param pParam 第二个参数
	* @return 处理结果
	*/
	virtual int HandleEvent(int nEventID, DWORD dwParam, void *pParam);

	virtual int HandlePackage(CPackage *pPackage,CProtocol *pProtocol);

	/**处理IO操作的其它操作，由CReactor调用
	* @return 保留 
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

	/**设置针对FTDC的压缩算法
	*@param chCompressMethod 压缩算法代码，0表示不压缩
	*/
	void SetCompressMethod(BYTE chCompressMethod);
	
	/**设置本会话的版本
	*@param	version	版本号
	*/
	void SetVersion(BYTE version);
	
	/**获取本会话的版本
	*@return	本会话的版本
	*/
	BYTE GetVersion(void);

	/**
	 * 查询所有的订阅主题
	 * @param topics 存入订阅的主题
	 */
	void QuerySubscribeTopic(vector<WORD>* topics);	

protected:
	CFTDCProtocol *m_pFTDCProtocol;		/**< FTDC协议对象*/
	CCompressProtocol *m_pCRPProtocol;	/**< CRP协议对象*/
	CFTDCSessionCallback *m_pPackageHandler;
	///-----
	///	王肇东，20060223：增加了对FTD协议的版本设置
	///-----
	BYTE m_version;
};

#endif // !defined(AFX_FTDCSESSION_H__88022E6A_66E9_46E0_B66F_8F73B23CDEFA__INCLUDED_)
