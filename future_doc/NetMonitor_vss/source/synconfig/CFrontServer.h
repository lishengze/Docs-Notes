/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	CFrontServer.h
///@brief	定义了监听前置连接处理的类
///@history
///20110112	周建军		创建该文件
#ifndef REF_FRONTSERVER_H
#define REF_FRONTSERVER_H

#include "public.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include <FTDDataWrapper.h>
#include <DBOperator.h>
#include <vector>
#include <PrjCommon.h>

struct taskStatus
{
	int times;	//任务执行次数
	int status; // 任务执行状态 -1表示已经结束的任务
	int delay;
};

/////////////////////////////////////////////////////////////////////////
///CManagerServer定义了接受SNMP管理端连接处理的类
///@author	周建军
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CFrontServer :
	public CSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///构造函数	
			///@param	pReactor	CReactor对象指针
		CFrontServer(CReactor *pReactor);

		~ CFrontServer(void);

		bool Init(void);

		///通知所有的前置连接
		    ///@param	pkg	要发送的数据包
		void NotifyAllSession(CFTDCPackage *pkg);

	/* */
	private:
		///新建会话时调用的处理函数
		    ///@param	pChannel	会话所属的通道地址
		    ///@param	bIsListener	会话是否是监听服务器类型
		    ///@return	返回创建的新会话
		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		///连接成功时调用的处理函数
		    ///@param	pSession	连接成功的会话指针
		virtual void OnSessionConnected(CSession *pSession);

		/**会话连接断开时的处理函数
	* @param	pSession	断开的连接会话指针
	* @param	nReasion	断开的原因
	*/
		virtual void OnSessionDisconnected(CSession *pSession, int nReason);

		///请求应答包处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
			///@return	返回数据包的处理结果
		virtual int HandlePackage(
						CFTDCPackage *pFTDCPackage,
						CFTDCSession *pSession);

		///用户登录请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		///通用操作请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryGeneralOperateTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///时间策略请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryNetTimePolicyTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///设备改变请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryNetDeviceChgTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///设备探测请求处理函数
		    ///@param	pFTDCPackage	需要处理的FTDC包地址
		    ///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryNetDeviceDetectTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///网络设备查询请求处理函数
		    ///@param	pFTDCPackage	需要处理的FTDC包地址
		    ///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryNetDeviceRequestTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///网络设备端口查询请求处理函数
		    ///@param	pFTDCPackage	需要处理的FTDC包地址
		    ///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryNetInterfaceTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///网络设备模块查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryNetModuleTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///网络设备连接关系查询请求处理函数
		    ///@param	pFTDCPackage	需要处理的FTDC包地址
		    ///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryNetDeviceLinkedTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///采集任务请求处理函数
		    ///@param	pFTDCPackage	需要处理的FTDC包地址
		    ///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryNetGatherTaskTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///设备对象组请求处理函数
		    ///@param	pFTDCPackage	需要处理的FTDC包地址
		    ///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryNetMonitorDeviceGroupTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///采集任务请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryNetMonitorTaskInfoTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///退出服务处理函数
		    ///@param	pFTDCPackage	需要处理的FTDC包地址
		    ///@param	pSession	数据包所属的FTD会话指针
		void OnSysServerExitTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///采集任务状态请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryNetMonitorTaskStatusResultTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///指标统表请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryNetMonitorAttrScopeTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnReqQryFileGeneralOperTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnReqQrySysUserLoginTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnReqQryGetFileTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///基线处理函数
		    ///@param	pFTDCPackage	需要处理的FTDC包地址
		    ///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryNetBaseLineTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnReqQryNetMonitorDeviceTaskTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		bool AddDeviceTaskItem2DB(
				CFTDCPackage *pFTDCPackage,
				CFTDReqQryNetMonitorDeviceTaskField &qryfield,
				int nTaskFlitID);

		bool RemoveDeviceTaskItem4DB(
				CFTDCPackage *pFTDCPackage,
				CFTDReqQryNetMonitorDeviceTaskField &qryfield,
				int nTaskFlitID);

		///新增连接
		    ///@param	session	新的Session连接
		bool AddSession(CFTDCSession *session)
		{
			assert(session);

			m_sessions.push_back(session);
			return true;
		}

		///删除连接
		    ///@param	session	失效Session连接
		bool DeleteSession(CFTDCSession *session)
		{
			assert(session);

			list<CFTDCSession *>::iterator	it = find(
					m_sessions.begin(),
					m_sessions.end(),
					session);
			if (it != m_sessions.end())
			{
				m_sessions.erase(it);
			}

			return true;
		}
		void OnReqQryEventDescriptionTopic( CFTDCPackage *pFTDCPackage, CFTDCSession *pSession );
	/* */
	private:
		///发送数据包使用的缓冲区
		CFTDCPackage m_pkgSend;

		///数据库handler
		SyncDBOperator	m_dbHandler;

		///多个前置连接的管理器
		list<CFTDCSession *> m_sessions;

		// 多线程访问m_sessions时的互斥锁
		CMutex	m_lock;

		string	strAddFileName;

		int m_nDeviceTaskPrimID;
};
#endif // REF_FRONTSERVER_H
