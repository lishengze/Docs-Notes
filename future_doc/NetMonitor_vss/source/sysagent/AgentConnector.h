/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	AgentConnector.h
///@brief	定义了采集代理连接探针并处理探针消息的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
#ifndef REF_AGENTCONNECTOR_H
#define REF_AGENTCONNECTOR_H

#include "public.h"
#include "CachedFlow.h"
#include "CachedFileFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include "CEventProcess.h"
#include "CSysInternalTopology.h"
#include <map>
#include <string>
#define MAXPROBECONFIGNUM	50


using namespace std;

/////////////////////////////////////////////////////////////////////////
///CHostConfig定义了主机所属的数据中心类
///@author	周建军
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CHostConfig
{
	/* */
	public:
		///保存的数据中心名
		string	m_mDataCenter;

		///保存的数据中心需要分析的日志文件名
		map<string, bool> m_mMapLogType;

	/* */
	public:

		///构造函数
		CHostConfig(void)
		{
			m_mDataCenter = "";
		}

		///构造函数
			///@param	mDataCenter	数据中心名
		CHostConfig(const string &mDataCenter)
		{
			m_mDataCenter = mDataCenter;
		}

		///构造函数
			///@param	mDataCenter	数据中心名
		CHostConfig(const char *mDataCenter)
		{
			m_mDataCenter = mDataCenter;
		}

		///拷贝构造函数
			///@param	ob	数据中心对象名
		CHostConfig(const CHostConfig &ob)
		{
			m_mDataCenter = ob.m_mDataCenter;
		}

		///析构函数
		~CHostConfig(void)
		{
		}

		///重载赋值运算符
			///@param	ob	数据中心对象名
		void operator=(const CHostConfig &ob)
		{
			m_mDataCenter = ob.m_mDataCenter;
		}
};

/////////////////////////////////////////////////////////////////////////
///CAgentSessionFactory定义了采集代理探针会话连接类
///@author	周建军
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CAgentSessionFactory :
	public CSessionFactory
{
	/* */
	public:

		///构造函数
		CAgentSessionFactory(CReactor *pReactor, int nMaxSession) :
		CSessionFactory(pReactor, nMaxSession)
		{
		}

		///注册连接函数
			///@param	location	连接的地址
		void RegisterConnecter(char *location)
		{
			CSessionFactory::RegisterConnecter(location);
			memset(m_location, 0, MAXLOCATIONLEN);
			strcpy(m_location, location);
		}

		///取连接地址函数
			///@return	返回连接地址的指针
		char *GetLocationName(void)
		{
			return m_location;
		}

	/* */
	private:
		///保存注册的连接地址
		char m_location[MAXLOCATIONLEN];
};

/////////////////////////////////////////////////////////////////////////
///CAgentConnector定义了采集代理的探针连接处理类
///@author	周建军
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CAgentConnector :
	public CAgentSessionFactory,
	public CFTDCSessionCallback,
	public CFTDCSubscriber
{
	/* */
	public:
		///构造函数
			///@param	pReactor	CReactor对象指针
			///@param	pSaveFile	保存索引位置的文件名
			///@param	location	连接的地址
			///@param	bProbeFlag	连接的类型,true:probe,false:agent
			///@param	pLinkName	链接的别名,ZJ-Agent06
			///@param	pLinkLocation	链接的IP地址,tcp://172.18.38.61:18806
			///@param	pEventProcess	事件处理类指针，该对象需预先构造
		CAgentConnector(
			CReactor *pReactor,
			bool bProbeFlag,
			int mConnectId,
			char *pLinkName,
			char *pLinkLocation,
			CEventProcess *pEventProcess);

		///建立连接处理函数
			///@param	pChannel	连接通道的指针
			///@param	bIsListener	是否为监听者的连接
			///@return	返回建立的会话ID
		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		///会话连接时的处理函数
			///@param	pSession	连接会话指针
		virtual void OnSessionConnected(CSession *pSession);

		/**会话连接断开时的处理函数
	* @param	pSession	断开的连接会话指针
	* @param	nReasion	断开的原因
	*/
		virtual void OnSessionDisconnected(CSession *pSession, int nReason);

		///设置通讯阶段号函数
			///@param	wCommPhaseNo	需要设置的通信阶段号
		virtual void SetCommPhaseNo(WORD wCommPhaseNo);

		///获取流序列号函数
			///@return	返回流的当前序列号
		virtual WORD GetSequenceSeries(void);

		///获取流中包含的包总数函数
			///@return	返回当前订阅收到的包总数
		virtual DWORD GetReceivedCount(void);	//收到的包个数
		
			///订阅收到的包处理函数,是发布/订阅模型收到的数据包
			///@param	pMessage	订阅者收到的包地址
		virtual void HandleMessage(CFTDCPackage *pMessage);

		///取探针连接标志
		bool GetProbeFlag(void)
		{
			return m_bProbeFlag;
		}

		///判断该日志事件内容对象是否允许接收处理
		bool ValidEvent(const char *pEventObject)
		{
			if (pEventObject != NULL && strlen(pEventObject) > 20)
			{
				if (m_EventCount.find(pEventObject) != m_EventCount.end())
				{
					/// 限制为10次以内
					return m_EventCount[pEventObject]++ < 10;
				}
				else
				{
					m_EventCount[pEventObject] = 1;
				}
				return true;
			}
			return false;
		}
	/* */
	private:
		///FTD请求应答收到的包处理函数,是请求应答模型中会话连接收到的数据包
			///@param	pFTDCPackage	FTDCpackage数据包地址
			///@param	pSession	数据包所属的会话ID
			///@return	返回处理的结果
		virtual int HandlePackage(
						CFTDCPackage *pFTDCPackage,
						CFTDCSession *pSession);

		///探针请求配置处理函数
			///@param	pFTDCPackage	FTDCpackage数据包地址
			///@param	pSession	数据包所属的会话ID
		void OnReqQryHostConfig(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///用户登录应答处理函数
			///@param	pFTDCPackage	FTDCpackage数据包地址
			///@param	pSession	数据包所属的会话ID
		void OnRspUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		///用户退出请求处理函数
			///@param	pFTDCPackage	FTDCpackage数据包地址
			///@param	pSession	数据包所属的会话ID
		void OnReqUserLogout(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///系统日志处理函数
			///@param	pFTDCPackage	FTDCpackage数据包地址
			///@param	pSession	数据包所属的会话ID
		void OnRtnSyslogInfoTopic(CFTDCPackage *pFTDCPackage);

		///应用日志处理函数
			///@param	pFTDCPackage	FTDCpackage数据包地址
			///@param	pDataCenter	数据包所属的数据中心
		void OnRtnSyslogInfoApplog(
				CFTDCPackage *pFTDCPackage,
				char *pDataCenter);

		///主机日志处理函数
			///@param	pFTDCPackage	FTDCpackage数据包地址
			///@param	pDataCenter	数据包所属的数据中心
		void OnRtnSyslogInfoSyslog(
				CFTDCPackage *pFTDCPackage,
				char *pDataCenter);

		///关键文件日志处理函数
			///@param	pFTDCPackage	FTDCpackage数据包地址
			///@param	pDataCenter	数据包所属的数据中心
		void OnRtnSyslogInfoKeyfile(
				CFTDCPackage *pFTDCPackage,
				char *pDataCenter);

		///二进制日志处理函数
			///@param	pFTDCPackage	FTDCpackage数据包地址
			///@param	pDataCenter	数据包所属的数据中心
		void OnRtnSyslogInfoSlog(CFTDCPackage *pFTDCPackage, char *pDataCenter);

		///主机名变更处理函数
			///@param	pFTDCPackage	FTDCpackage数据包地址
		void OnRtnUpdateSysConfig(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		/**处理用户登录请求函数
	* @param	pFTDCPackage	需要处理的FTDC数据包地址
	* @param	pSession	数据包所属的FTD会话指针
	*/
		void OnReqUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		///处理探针发送出来的告警处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnWarningEventTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

	/* */
	public:
		///此链接的别名，如 "ZJ-Agent06"
		string	m_sLinkName;

		///此链接的连接串，如 "tcp://172.18.38.61:18806"
		string	m_sLinkLocation;

	/* */
	private:
		//连接探针标记 true:probe,false:agent
		bool m_bProbeFlag;

		///保存ConnectID
		int m_mConnectId;

		///保存已收到的数据包个数
		long m_mPacketRecvNum;

		///数据包发送使用的缓冲区
		CFTDCPackage m_pkgSend;

		///分析使用的日志信息域
		CFTDRtnSyslogInfoField	m_mSyslogInfo;

		///供分析使用的日志内容缓冲区
		char m_mContentBuf[MAXONECONTENTLEN];

		///供事件分析使用对象指针
		CEventProcess *m_pEventProcess;

		///用于缓存日志事件条目计数的信息
		map <string, int> m_EventCount;
};

class CFileDescript
{
	/* */
	public:
		///版本号
		string	m_location;

		///前置的ID
		string	m_appname;

	/* */
	public:

		///构造函数
		CFileDescript(void)
		{
			m_location = "";
			m_appname = "";
		}

		///构造函数
			///@param	location	地址信息
			///@param	appname 应用名
		CFileDescript(string location, string appname)
		{
			m_location = location;
			m_appname = appname;
		}

		///拷贝构造函数
		CFileDescript(const CFileDescript &ob)
		{
			m_location = ob.m_location;
			m_appname = ob.m_appname;
		}

		///重载=运算符
		void operator=(const CFileDescript &ob)
		{
			m_location = ob.m_location;
			m_appname = ob.m_appname;
		}

		///重载>运算符
		bool operator>(const CFileDescript &ob2) const
		{
			if (this->m_location > ob2.m_location)
			{
				return true;
			}
			else if (this->m_location == ob2.m_location)
			{
				if (this->m_appname > ob2.m_appname)
				{
					return true;
				}
			}

			return false;
		}

		///重载<运算符
		bool operator < (const CFileDescript &ob2)const
		{
			if (this->m_location < ob2.m_location)
			{
				return true;
			}
			else if (this->m_location == ob2.m_location)
			{
				if (this->m_appname < ob2.m_appname)
				{
					return true;
				}
			}

			return false;
		}

		///重载==运算符
		friend bool operator==(
		const CFileDescript &ob1,
		const CFileDescript &ob2)
		{
			if ((ob1.m_location == ob2.m_location)
			&&	(ob1.m_appname == ob2.m_appname))
			{
				return true;
			}

			return false;
		}
};

class CFileInfo
{
	/* */
	public:
		///偏移量
		string	m_pos;

		///最后读取时间
		string	m_time;

	/* */
	public:

		///构造函数
		CFileInfo(void)
		{
			m_pos = "";
			m_time = "";
		}

		///构造函数
			///@param	location	偏移量
			///@param	stime 时间
		CFileInfo(string pos, string stime)
		{
			m_pos = pos;
			m_time = stime;
		}

		///拷贝构造函数
		CFileInfo(const CFileInfo &ob)
		{
			m_pos = ob.m_pos;
			m_time = ob.m_time;
		}

		///重载=运算符
		void operator=(const CFileInfo &ob)
		{
			m_pos = ob.m_pos;
			m_time = ob.m_time;
		}

		///重载>运算符
		bool operator>(const CFileInfo &ob2) const
		{
			if (this->m_pos > ob2.m_pos)
			{
				return true;
			}
			else if (this->m_pos == ob2.m_pos)
			{
				if (this->m_time > ob2.m_time)
				{
					return true;
				}
			}

			return false;
		}

		///重载<运算符
		bool operator < (const CFileInfo &ob2)const
		{
			if (this->m_pos < ob2.m_pos)
			{
				return true;
			}
			else if (this->m_pos == ob2.m_pos)
			{
				if (this->m_time < ob2.m_time)
				{
					return true;
				}
			}

			return false;
		}

		///重载==运算符
		friend bool operator==(const CFileInfo &ob1, const CFileInfo &ob2)
		{
			if ((ob1.m_pos == ob2.m_pos) && (ob1.m_time == ob2.m_time))
			{
				return true;
			}

			return false;
		}
};
#endif // REF_AGENTCONNECTOR_H END
