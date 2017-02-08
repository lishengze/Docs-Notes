// OFPProtocol.h: interface for the COFPProtocol class .
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OFPPROTOCOL_H__INCLUDED_)
#define AFX_OFPPROTOCOL_H__INCLUDED_

#include "Protocol.h"
#include "OFPPackage.h"
#include "OFPPubEndPoint.h"
#include "HashMap.h"

#define MSG_OFPERR_RECVHEARTBEAT		0xA001
#define MSG_OFPERR_SENDHEARTBEAT		0xA002
#define MSG_OFPERR_BADPACKAGE			0xA003

/**协议栈容器的第二层协议，兼容旧系统
*/
class  COFPProtocol : public CProtocol  
{
public:
	/**构造函数
	* @param pReactor 指向运行引擎的指针
	* @param pBelow 下层协议的指针
	*/
	COFPProtocol(CReactor *pReactor, char chVersion);
	/**析构函数
	*/
	virtual ~COFPProtocol();

	/**加入OFP报头并传至下层协议
	* @param pPackage 上层层协议下传的包
	* @return 0   成功
	* @return <>0 失败
	*/
	virtual int Push(CPackage *pPackage, CProtocol *pUpper);
	
	/**将各主题的报文发送出去
	*/
	void PublishSend();
	
	void Publish(CReadOnlyFlow *pFlow, WORD nSequenceSeries, int nStartId);
	void UnPublish(WORD nSequenceSeries);
protected:	
	/**纪录当前收到包的时间，判断是否OFP包，并上传
	* @param pPackage 下层协议上传的包
	* @return 0   成功
	* @return <>0 失败
	*/
	virtual int Pop(CPackage *pPackage);
		
	/**处理定时操作，由CReactor调用。检查如果读超时，则通知上层协议。
	* 检查如果写超时，则发送心跳报文。
	* @param nIDEvent 当自身为定时器时，在定时器链表定时器标识   
	*/
	virtual void OnTimer(int nIDEvent);
		
	/**生成心跳报文，并发送心跳
	* @return >0   成功
	* @return <=0  失败 
	*/
	int SendHeartBeat();

	/**收到一个错误的数据包时调用
	* @param pPackage 错误的数据包
	* @return 0   成功
	* @return <>0 失败
	*/
	virtual int OnRecvErrorPackage(CPackage *pPackage);

	COFPPubEndPoint *GetPubEndPoint(WORD nSequenceSeries);

protected:
	time_t m_LastWriteTime;		/**< 最后发包时间　*/
	time_t m_LastReadTime;		/**< 最后收包时间　*/
	CReactor *m_pReactor;
	char m_chVersion;
	
	typedef CHashMap<WORD, COFPPubEndPoint *, HashInt> CPubEndPointMap;
	CPubEndPointMap m_mapPubEndPoint;

	COFPPackage m_pkgHeartbeat;
};

#endif // !defined(AFX_OFPPROTOCOL_H__INCLUDED_)
