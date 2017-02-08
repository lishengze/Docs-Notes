/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	EventFrontServer.h
///@brief	定义了事件计算服务器监听前置连接处理的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
#ifndef REF_EVENTFRONTSERVER_H
#define REF_EVENTFRONTSERVER_H

#include "public.h"
#include "CachedFlow.h"
#include "CachedFileFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "CDate.h"
#include "systools.h"
#include "EventConfigConnector.h"

#if !defined(DEVELOP_ENV)
#define DEVELOP_ENV
#endif

//#undef DEVELOP_ENV
class CNodeCacheBuffer
{
	/* */
	public:

		///构造函数
			///@param	nMaxNodeNum	缓冲区能保存的最大节点个数
			///@param	nNodeSize	单个节点的最大长度
		CNodeCacheBuffer(int nMaxNodeNum, int nNodeSize)
		{
			m_pHeadNode = NULL;
			m_nNodeSize = nNodeSize + 2;
			m_nMaxNodeNum = nMaxNodeNum;
			m_nWriteNum = -1;
			m_nReadNum = -1;
			m_pHeadNode = (char *)malloc(m_nMaxNodeNum * m_nNodeSize);
			if (NULL == m_pHeadNode)
			{
				printf("CNodeCacheBuffer:: malloc failed\n");
				fflush(stdout);
				exit(0);
			}

			memset(m_pHeadNode, 0, m_nMaxNodeNum * m_nNodeSize);
			m_nWriteTotal = 0;
			m_nReadTotal = 0;
		}

		~CNodeCacheBuffer(void)
		{
			free(m_pHeadNode);
		}

		///往缓冲区写内容函数
			///@param	pStrValue	需要放入缓冲区的值地址
			///@param	length	放入的长度
			///@return	成功返回true，否则false
		bool writeNode(void *pStrValue, int length)
		{
			if (length <= 0)
			{
				return true;
			}

			int tempWriteNum = m_nWriteNum + 1;
			if (tempWriteNum >= m_nMaxNodeNum)
			{
				tempWriteNum = 0;
			}

			char *pNode = m_pHeadNode + tempWriteNum * m_nNodeSize;
			short *iNodeLen = (short *)pNode;
			if (*iNodeLen != 0)
			{
				printf(
					"Reach Buffer Limit, need to extend %d %d\n",
					(int)(time((time_t *)NULL)),
					*iNodeLen);
				fflush(stdout);
				return false;
			}

#if 0
			if (*iNodeLen != 0)
			{
				printf("Reach Buffer Limit, need to extend\n");
				return false;
			}

#endif
			memcpy(pNode + 2, pStrValue, length);
			*iNodeLen = length;
			m_nWriteNum = tempWriteNum;
			m_nWriteTotal++;
			return true;
		}

		bool writeNode(void *pStrValue)
		{
			while (!writeNode(pStrValue, m_nNodeSize - 2))
			{
#ifdef WINDOWS
				Sleep(20);
#else
				usleep(20 * 1000);
#endif
			}

			return true;
		}

		///从缓冲区读内容函数
			///@param	pStrValue	保存取出的值
			///@param	length	取出的值长度
			///@return	成功返回true，否则false
		bool readNode(void *pStrValue, int &length)
		{
			int tempReadNum = m_nReadNum + 1;
			if (tempReadNum >= m_nMaxNodeNum)
			{
				tempReadNum = 0;
			}

			char *pNode = m_pHeadNode + tempReadNum * m_nNodeSize;
			short *iNodeLen = (short *)pNode;
			if (*iNodeLen == 0)
			{
				return false;
			}

			length = *iNodeLen;
			memcpy(pStrValue, pNode + 2, length);
			*iNodeLen = 0;
			m_nReadNum = tempReadNum;
			m_nReadTotal++;
			return true;
		}

		void report(void)
		{
			printf("Write %d Read %d\n", m_nWriteTotal, m_nReadTotal);
			fflush(stdout);
		}

	/* */
	protected:
	/* */
	private:
		///保存数据的首地址
		char *m_pHeadNode;

		///一个结点大小（2个字节标示有效数据长度+固定数据块大小）
		int m_nNodeSize;

		///最大节点数
		int m_nMaxNodeNum;

		///当前已经写入的节点编号
		int m_nWriteNum;

		///当前已经读取的节点编号
		int m_nReadNum;

		int m_nWriteTotal;
		int m_nReadTotal;
};

//链路状态信息
class LinkStatusInfo
{
	/* */
	public:
		LinkStatusInfo(void) :
		m_nPortLinkStatus(0),
		m_nPortProtoStatus(0)
		,
		m_nPortLinkStatusReal(0),
		m_nPortProtoStatusReal(0),
		linktype(0)
		{
		}

		int m_nPortLinkStatus;		//端口的虚拟状态
		int m_nPortProtoStatus;		//协议的虚拟状态
		int m_nPortLinkStatusReal;	//端口的实际状态
		int m_nPortProtoStatusReal; //协议的实际状态
		int linktype;				//普通链路:0, 会员链路:1
};

/////////////////////////////////////////////////////////////////////////
///CAgentSessionFactory定义了采集代理连接的类
///@author	周建军
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CAgentSessionFactory :
	public CSessionFactory
{
	/* */
	public:

		///构造函数
			///@param	pReactor	CReactor对象指针
			///@param	nMaxSession	最大连接个数
		CAgentSessionFactory(CReactor *pReactor, int nMaxSession) :
		CSessionFactory(pReactor, nMaxSession)
		{
		}

		///注册连接器函数
			///@param	location	连接的通信地址
		void RegisterConnecter(char *location)
		{
			CSessionFactory::RegisterConnecter(location);
			memset(m_location, 0, MAXLOCATIONLEN);
			strcpy(m_location, location);
		}

		///取连接地址函数
			///@return	返回连接地址字符串
		char *GetLocationName(void)
		{
			return m_location;
		}

	/* */
	private:
		///保存连接地址字符串
		char m_location[MAXLOCATIONLEN];
};

class CEventAttrKey
{
	/* */
	public:

		///构造函数
		CEventAttrKey(void)
		{
			m_sObjectID = "";
			m_sEventName = "";
		}

		///构造函数
			///@param	pObjectID	对象ID
			///@param	pEventName	事件名
		CEventAttrKey(const char *pObjectID, const char *pEventName)
		{
			m_sObjectID = pObjectID;
			m_sEventName = pEventName;
		}

		///拷贝构造函数
		CEventAttrKey(const CEventAttrKey &ob)
		{
			m_sObjectID = ob.m_sObjectID;
			m_sEventName = ob.m_sEventName;
		}

		///重载=运算符
		void operator=(const CEventAttrKey &ob)
		{
			m_sObjectID = ob.m_sObjectID;
			m_sEventName = ob.m_sEventName;
		}

		///重载>运算符
		friend bool operator>(
		const CEventAttrKey &ob1,
		const CEventAttrKey &ob2)
		{
			if (ob1.m_sObjectID > ob2.m_sObjectID)
			{
				return true;
			}
			else if (ob1.m_sObjectID == ob2.m_sObjectID)
			{
				if (ob1.m_sEventName > ob2.m_sEventName)
				{
					return true;
				}
			}

			return false;
		}

		///重载>运算符
		friend bool operator < (const CEventAttrKey &ob1, const CEventAttrKey &ob2)
		{
			if (ob1.m_sObjectID < ob2.m_sObjectID)
			{
				return true;
			}
			else if (ob1.m_sObjectID == ob2.m_sObjectID)
			{
				if (ob1.m_sEventName < ob2.m_sEventName)
				{
					return true;
				}
			}

			return false;
		}

		///重载==运算符
		friend bool operator==(
		const CEventAttrKey &ob1,
		const CEventAttrKey &ob2)
		{
			if (ob1.m_sObjectID == ob2.m_sObjectID
			&&	ob1.m_sEventName == ob2.m_sEventName)
			{
				return true;
			}

			return false;
		}

	/* */
	public:
		///对象ID
		string	m_sObjectID;

		///事件名称
		string	m_sEventName;
};

/////////////////////////////////////////////////////////////////////////
///CFrontConnector定义了接受前置连接处理的类
///@author	周建军
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CFrontConnector :
	public CAgentSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///构造函数	
			///@param	pReactor	CReactor对象指针
		CFrontConnector(
			CReactor *pReactor,
			unsigned int *pSyslogEventId,
			char *pFlowPath);

		///新建会话时调用的处理函数
			///@param	pChannel	会话所属的通道地址
			///@param	bIsListener	会话是否是监听服务器类型
			///@return	返回创建的新会话
		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		///连接成功时调用的处理函数
			///@param	pSession	连接成功的会话指针
		virtual void OnSessionConnected(CSession *pSession);

		/** 发送数据包函数
	* @param	pFTDPackage	发送数据包的地址
	*/
		void SendPackageAllSession(CFTDCPackage *pFTDCPackage)
		{
			CHashMap<DWORD, CSession *, HashInt>::iterator	itor = m_mapSession.
				Begin();
			while (!itor.IsEnd())
			{
				((CFTDCSession *) (*itor))->SendRequestPackage(pFTDCPackage);
				pFTDCPackage->Pop(FTDCHLEN);
				itor++;
			}
		}

		//告警事件添加/读取接口
		void AddWarningEvent(CFTDReqQryWarningEventUpdateField &warningevent)
		{
			m_listWarningEvent.add(warningevent);
		}

		bool GetWarningEvent(CFTDReqQryWarningEventUpdateField &warningevent)
		{
			return m_listWarningEvent.get(warningevent);
		}

		//告警状态改变事件添加/读取接口
		void AddWarningEventActiveChange(
		CFTDReqQryWarningActiveChangeField	&warningeventac)
		{
			m_listWarningEventActiveChange.add(warningeventac);
		}

		bool GetWarningEventActiveChange(
		CFTDReqQryWarningActiveChangeField	&warningeventac)
		{
			return m_listWarningEventActiveChange.get(warningeventac);
		}

		//告警开关事件
		void AddReqNetRoom(CFTDReqQryNetRoomField &netroom)
		{
			m_listReqNetRoom.add(netroom);
		}

		bool GetReqNetRoom(CFTDReqQryNetRoomField &netroom)
		{
			return m_listReqNetRoom.get(netroom);
		}

	/* */
	protected:
		/**会话连接断开时的处理函数
	* @param	pSession	断开的连接会话指针
	* @param	nReasion	断开的原因
	*/
		virtual void OnSessionDisconnected(CSession *pSession, int nReason);

	/* */
	private:
		///请求应答包处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
			///@return	返回数据包的处理结果
		virtual int HandlePackage(
						CFTDCPackage *pFTDCPackage,
						CFTDCSession *pSession);

		///用户登录应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		///告警处理响应处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryWarningEventUpdate(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///对象告警激活处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryWarningActiveChange(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///用户登录响应处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		///用户报单插入响应处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqOrderInsert(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///日志事件响应处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQrySyslogEventUpdateTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///配置文件列表响应处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryNetCfgFileTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///配置文件响应处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryGetFileTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///任务指标抽取处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqNetMonitorTaskResultTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		//告警短信开关
		void OnReqQryNetRoomTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///设置落地配置文件的路径
		void SetOutputPath(const char *path);

		///发送文件内容
		void SendFileContent(
				string	&filePath,
				string	&filename,
				DWORD requestId,
				CFTDCSession *pSession,
				bool sendLastFlag = true);

		void PublishFlow(CFTDCPackage *pFTDCPackage
			             , CFTDCSession *pSession
			             , CCachedFileFlow** cacheFileFlowArray);
	/* */
	public:
		///for test
		static void OnReqQryGetFileTopic(void);

	/* */
	private:
		///发送数据包使用的缓冲区
		CFTDCPackage m_pkgSend;
		unsigned int *m_pSyslogEventId;

		// 保存落地配置文件的目录
		string	m_sFilePath;

		///发送给config的告警事件队列
		TemplateMutexCatch<CFTDReqQryWarningEventUpdateField>
			m_listWarningEvent;

		///发送给config的告警状态改变事件队列
		TemplateMutexCatch<CFTDReqQryWarningActiveChangeField>
			m_listWarningEventActiveChange;

		///发送给config的告警开关队列
		TemplateMutexCatch<CFTDReqQryNetRoomField>	m_listReqNetRoom;

	/* */
	public:
		///保存需要过滤抛弃的告警事件对象ID by zhou.jj 20100609
		list<string> m_cDropEventIdList;	//抛弃的事件ID列表
		CCachedFileFlow *m_pCurrFrontFlow;
		CCachedFileFlow *m_pCurrOracleFlow;
		CCachedFileFlow *m_pCurrSlogFlow;

		CCachedFileFlow *m_pFrontFlowArray[MAX_EVENTFLOWNUM];
		CCachedFileFlow *m_pOracleFlowArray[MAX_EVENTFLOWNUM];
		CCachedFileFlow *m_pSlogFlowArray[MAX_EVENTFLOWNUM];

		///上次切换到的流指针在数组中的位置
		int m_nFlowPosition;

		///保存当前所有的ObjectID及所属的session信息
		CObjectIdSession m_mObjectIdSession;

		///事件分析服务器接收前置的查询请求的整合RID列表
		CManageReqIDSession m_mFrontToEventReq;

		//任务执行结果
		//key:ObjectID_Task_ID_OperateTime_MonDate_MonTime_InstructChain
		map<string, vector<CFTDReqQryNetMonitorTaskResultField> >
			m_mapTaskResult;
};

class CEventProcess
{
	/* */
	public:
		CEventProcess(void)
		{
			m_mEventSeries = 1;
		}

		///事件的描述查询函数
			///@param	pObjectID	对象名
			///@param	pEventName	事件名
			///@param	nEventSeries	返回事件的定义的编号，供客户端统计分析使用，同一主机同一事件多次发生事件均相同
		bool getEventDesc(
				const char	*pObjectId,
				const char	*pEventName,
				int &nEventSeries);

	/* */
	private:
		map<CEventAttrKey, int> m_mapEventDesc;
		int m_mEventSeries; // 事件定义的编号，递增不重复，客户端统计分析使用
};

class CListHistoryTradePeakField
{
	/* */
	public:
		CListHistoryTradePeakField(void)
		{
			m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
		}

		~CListHistoryTradePeakField(void)
		{
		}

		///将峰值数据写入到数据队列函数
			///@param	warningEvent	告警事件对象
			///@return	true表示成功，false表示失败
		bool WriteValue(CFTDRtnHistoryTradePeakField &tradePeak)
		{
			m_lockData.Lock();
			m_listEvent.push_back(tradePeak);
			m_lockData.UnLock();
			return true;
		}

		///从数据队列读出事件写入到前置的流和查询流
			///@param	frontFlow	前置订阅的流名称
			///@param	oracleFlow	查询服务器订阅的流名称
		void ReadValue(CCachedFileFlow *frontFlow, CCachedFileFlow *queryFlow)
		{
			if (m_lockData.TryLock())
			{
				list<CFTDRtnHistoryTradePeakField>::iterator it = m_listEvent.
					begin();
				for (it; it != m_listEvent.end(); ++it)
				{
					m_pkgSend.PreparePackage(
							FTD_TID_RtnHistoryTradePeakTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
					FTDC_ADD_FIELD(&m_pkgSend, &(*it));
					m_pkgSend.MakePackage();
					queryFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
				}

				m_listEvent.clear();
				m_listEvent.resize(0);
				m_lockData.UnLock();
			}
		}

	/* */
	protected:
	/* */
	private:
		// 告警事件保存队列
		list<CFTDRtnHistoryTradePeakField>	m_listEvent;

		// 数据锁，用于保护 数据队列
		CMutex	m_lockData;

		///用于发送数据包使用的缓冲区
		CFTDCPackage m_pkgSend;
};

class CListHistoryObjectAttrField
{
	/* */
	public:
		CListHistoryObjectAttrField(void)
		{
			m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
		}

		~CListHistoryObjectAttrField(void)
		{
		}

		///将K线数据写入到数据队列函数
			///@param	warningEvent	告警事件对象
			///@return	true表示成功，false表示失败
		bool WriteValue(CFTDRtnHistoryObjectAttrField &historyObject)
		{
			m_lockData.Lock();
			m_listEvent.push_back(historyObject);
			m_lockData.UnLock();
			return true;
		}

		///从数据队列读出事件写入到前置的流和查询流
			///@param	frontFlow	前置订阅的流名称
			///@param	oracleFlow	查询服务器订阅的流名称
		void ReadValue(CCachedFileFlow *frontFlow, CCachedFileFlow *queryFlow)
		{
			if (m_lockData.TryLock())
			{
				list<CFTDRtnHistoryObjectAttrField>::iterator it = m_listEvent.
					begin();
				for (it; it != m_listEvent.end(); ++it)
				{
					m_pkgSend.PreparePackage(
							FTD_TID_RtnHistoryObjectAttrTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
					FTDC_ADD_FIELD(&m_pkgSend, &(*it));
					m_pkgSend.MakePackage();
					queryFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
				}

				m_listEvent.clear();
				m_listEvent.resize(0);
				m_lockData.UnLock();
			}
		}

	/* */
	protected:
	/* */
	private:
		// 告警事件保存队列
		list<CFTDRtnHistoryObjectAttrField> m_listEvent;

		// 数据锁，用于保护 数据队列
		CMutex	m_lockData;

		///用于发送数据包使用的缓冲区
		CFTDCPackage m_pkgSend;
};
#endif // REF_EVENTFRONTSERVER_H
