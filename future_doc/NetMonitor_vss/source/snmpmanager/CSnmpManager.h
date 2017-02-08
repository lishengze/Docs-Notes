/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	CSnmpManager.h
///@brief	定义了SnmpManager使用的类
///@history
///20100920	周建军		创建该文件
#ifndef REF_CSNMPMANAGER_H
#define REF_CSNMPMANAGER_H

#include "public.h"
#include "CachedFlow.h"
#include "CachedFileFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include "CAsyncGetThread.h"
#include "CSynConnector.h"
#include "CTaskManager.h"
#include "CConnTaskThread.h"

/////////////////////////////////////////////////////////////////////////
///CProbeTimmer定义了管理器定时器类
///@author	周建军
///@version	1.0,20100920
/////////////////////////////////////////////////////////////////////////
class CManagerTimmer :
	public CEventHandler
{
	/* */
	public:
		///构造函数
		CManagerTimmer(CReactor *pReactor);

		/** 设置定时器函数
	* @param	nIDEvent	定时器产生的事件ID
	* @param	nElapse	定时器的时间间隔，单位ms	
	*/
		void SetTimer(int nIDEvent, int nElapse)
		{
			m_nEventId = nIDEvent;
			CEventHandler::SetTimer(nIDEvent, nElapse);
		}

		/** 定时器处理函数
	* @param	nIDEvent	该定时器的ID
	*/
		virtual void OnTimer(int nIDEvent);

		/** 取事件ID函数
	* @param	pFTDCPackage	收到的FTD数据包地址
	* @param	pSession	该数据包所属的会话ID
	* @return	返回事件的ID
	*/
		int GetEventId(void)
		{
			return m_nEventId;
		}

		/************************************************************************/
		/* 设置线程数组地址及线程个数函数                                       */

		/************************************************************************/
		void setThreadPoint(CAyncGetThread **pThread, int nThreadNum)
		{
			m_nThreadNum = nThreadNum;
			m_pThread = pThread;
		}

		void setConnTaskPoint(CConnTaskThread **pThread, int nThreadNum)
		{
			m_nConnTaskThreadNum = nThreadNum;
			m_pConnTaskThread = pThread;
		}

		void setFlowPoint(CCachedFileFlow **pFlowArray)
		{
			m_pFlowArray = pFlowArray;
			m_pCurrFlow = m_pFlowArray[0];
			m_nFlowPosition = 0;
			m_nLastChangeTime = time((time_t *)NULL);
		}

		void setSessionMapPoint(
		CHashMap<DWORD, CSession *, HashInt> *pSessionMap)
		{
			m_pSessionMap = pSessionMap;
		}

		void setCSynConnectorPoint(CSynConnector *pThread)
		{
			m_pcSyn = pThread;
		}

		void setTaskManagerThreadPoint(CTaskManagerThread *pThread)
		{
			m_pTaskManagerThread = pThread;
		}

	/* */
	private:
		///所有当前Server的session
		CHashMap<DWORD, CSession *, HashInt> *m_pSessionMap;

		///定时器使用的数据包缓冲区
		CFTDCPackage m_pkgSend;

		///保存定时器的事件ID
		int m_nEventId;

		///线程数组指针
		CAyncGetThread	**m_pThread;

		///线程启动个数
		int m_nThreadNum;

		///CConnTaskThread指针数组
		CConnTaskThread **m_pConnTaskThread;

		///CConnTaskThread启动个数
		int m_nConnTaskThreadNum;

		///流数组指针
		CCachedFileFlow **m_pFlowArray;

		///当前正在写的流编号
		CCachedFileFlow *m_pCurrFlow;

		///上次切换流的时间
		time_t	m_nLastChangeTime;

		///synconnector连接实例指针
		CSynConnector *m_pcSyn;

		///TaskManagerThread指针
		CTaskManagerThread	*m_pTaskManagerThread;

		//// 取cdp线程指针
		//CGetDeviceInfoThread *m_pcdpThread;
			///上次切换到的流指针在数组中的位置
		int m_nFlowPosition;
};

/////////////////////////////////////////////////////////////////////////
///CSnmpManagerServer定义了snmp管理器连接请求处理的类
///@author	周建军
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CSnmpManagerServer :
	public CSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///构造函数
			///@param	pReactor
			///@param	nThreadNum	启动线程个数
			///@param	pMibPath	mib文件路径
			///@param	pFlowPath	流文件存储路径
			///@param	nStartId	进程启动编号
			///@param	pLocation	连接串
		CSnmpManagerServer(
			CReactor *pconfReactor,
			int nThreadNum,
			const char	*pMibPath,
			const char	*pFlowPath,
			int nStartId,
			const char	*pLocation);
		~CSnmpManagerServer(void)
		{
			delete[] m_pThread;
			delete[] m_pConnTaskThread;
			delete m_pTaskManagerThread;
		}

		/** FTD请求响应处理函数
	* @param	pFTDCPackage	收到的FTD数据包地址
	* @param	pSession	该数据包所属的会话ID	
	*/
		virtual int HandlePackage(
						CFTDCPackage *pFTDCPackage,
						CFTDCSession *pSession);

		/** 会话建立连接处理函数
	* @param	pChannel	建立连接的通道指针
	* @param	bIsListener	是否是监听者标志,true表示监听者,false表示请求连接端	
	*/
		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		///连接成功时调用的处理函数
			///@param	pSession	连接成功的会话指针
		virtual void OnSessionConnected(CSession *pSession);

	/* */
	protected:
		/** 会话连接断开处理函数
	* @param	pSession	断开会话的ID
	* @param	nReason	断开的原因
	*/
		virtual void OnSessionDisconnected(CSession *pSession, int nReason);

	/* */
	public:
		///用户登录应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		///注册服务端口函数
			///@param	pSynConfigLocation	接受snmp连接的synconfig服务监听端口
		void RegisterSynConnecter(const char *pSynConfigLocation)
		{
			m_cSynConnector.RegisterConnecter(pSynConfigLocation);
		}

		///启动所有服务端口函数
		void StartAll(void)
		{
			Start();
			m_cSynConnector.Start();
		}

		void LoadDataFile(const char *filename = NULL);

		CSynConnector &GetConnectorObject(void)
		{
			return m_cSynConnector;
		}

	/* */
	private:
		///synconnector连接实例
		CSynConnector m_cSynConnector;

		///主机信息发送数据包缓冲区
		CFTDCPackage m_pkgSend;

		///定时器
		CManagerTimmer	m_timer;

		///启动的snmp采集线程数
		int m_nThreadNum;

		///启动的Telnet采集线程数
		int m_nTelnetThreadNum;

		///启动的线程指针
		CAyncGetThread	*m_pThread[MAX_THREAD_NUM];

		///启动的ConnTaskThread指针
		CConnTaskThread *m_pConnTaskThread[MAX_THREAD_NUM];

		///任务管理线程指针
		CTaskManagerThread	*m_pTaskManagerThread;

		///挂接到接收数据方的流
		CCachedFileFlow *m_pFlowArray[MAX_EVENTFLOWNUM];

		//取cpd线程
		//CGetDeviceInfoThread *m_pcdpThread;
		
			///进程启动编号
		int m_nStartId;

		///通信连接串
		char *m_pLocation;
};
#endif //REF_SNMPMANAGER_H
