/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CounterConnector.h
///@brief	定义了采集代理连接并处理探针消息的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
#ifndef REF_COUNTECONNECTOR_H
#define REF_COUNTECONNECTOR_H

#include "AgentConnector.h"

/////////////////////////////////////////////////////////////////////////
///CCounterTimmer定义了采集代理定期器处理的类
///@author	周建军
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CCounterTimmer :
	public CEventHandler
{
	/* */
	public:
		///构造函数
			///@param	pReactor	CReactor对象指针
		CCounterTimmer(CReactor *pReactor, CEventProcess *pEventProcess);

		///定时器处理函数
			///@param	nIDEvent	事件的ID号
		virtual void OnTimer(int nIDEvent);

	/* */
	private:
		///用于发送数据包的缓冲区
		CFTDCPackage m_pkgSend;

		///供事件分析使用对象指针
		CEventProcess *m_pEventProcess;
};

/////////////////////////////////////////////////////////////////////////
///CCounterConnector定义了采集代理面向事件计算会话连接类
///@author	周建军
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CCounterConnector :
	public CAgentSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///构造函数
			///@param	pReactor	CReactor对象指针
			///@param	pEventProcess	事件处理对象指针，该对象必须先创建
		CCounterConnector(CReactor *pReactor, CEventProcess *pEventProcess);

		///会话创建时调用的处理函数
			///@param	pChannel	产生新会话的通道指针
			///@param	bIsListener	会话是否是监听服务器产生的标记
			///@return	返回生成的新会话指针
		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		///会话连接成功时调用的处理函数
			///@param	pSession	连接的会话指针
		virtual void OnSessionConnected(CSession *pSession);

	/* */
	protected:
		/**会话连接断开时调用的处理函数
	* @param	pSession	会话连接的指针
	* @param	nReasion	会话断开的原因
	*/
		virtual void OnSessionDisconnected(CSession *pSession, int nReason);

	/* */
	private:
		/**FTDC数据包处理函数
	* @param	pFTDCPackage	需要处理的FTDC数据包地址
	* @param	pSession	数据包所属的FTD会话指针
	* @return	返回的处理结果
	*/
		virtual int HandlePackage(
						CFTDCPackage *pFTDCPackage,
						CFTDCSession *pSession);

		///应答探针请求配置处理函数
			///@param	pFTDCPackage	FTDCpackage数据包地址
			///@param	pSession	数据包所属的会话ID
		void OnRspQryHostConfig(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///用户退出请求处理函数
			///@param	pFTDCPackage	FTDCpackage数据包地址
			///@param	pSession	数据包所属的会话ID
		void OnReqUserLogout(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///切换交易日请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryTradeDayChange(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

	/* */
	private:
		///保存的定时器对象
		CCounterTimmer	m_myTimer;

		///用于发送消息的缓冲区
		CFTDCPackage m_pkgSend;
};
#endif // REF_COUNTECONNECTOR_H END
