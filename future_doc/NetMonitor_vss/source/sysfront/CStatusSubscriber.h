/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CStatusSubscriber.h
///@brief	定义了订阅事件处理消息的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
#ifndef REF_CSTATUSSUBSCRIBER_H
#define REF_CSTATUSSUBSCRIBER_H

#include "public.h"
#include "CachedFlow.h"
#include "CachedFileFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include "CListSession.h"
#include "databaseData.h"
#include "UFCopy.h"

extern CMemoryDB *pMemoryDB;
extern CStringIdMap g_StringIdMap;

class CStatusSubscriber :
	public CFTDCSubscriber
{
	/* */
	public:
		///构造函数	
		CStatusSubscriber(int nFlowSeq);

		///析构函数
		~ CStatusSubscriber(void);

		///设置通讯阶段号函数
			///@param	wCommPhaseNo	需要设置的通信阶段号
		virtual void SetCommPhaseNo(WORD wCommPhaseNo);

		///获取流序列号函数
			///@return	返回流的当前序列号
		virtual WORD GetSequenceSeries(void);	//流编号
		
			///获取收到流中包含的包总数函数
			///@return	返回当前订阅收到的包总数
		virtual DWORD GetReceivedCount(void);	//收到的包个数
		
			///订阅收到的包处理函数,是发布/订阅模型收到的数据包
			///@param	pMessage	订阅者收到的包地址
		virtual void HandleMessage(CFTDCPackage *pMessage);

		///清除流容器函数
		bool Truncate(int nFlowSeq)
		{
			if (nFlowSeq != m_nFlowSeq)
			{
				printf(
					"要清除的流编号 %d 与本订阅者的流编号 %d 不相同 \n",
					nFlowSeq,
					m_nFlowSeq);
				fflush(stdout);
				return false;
			}

			return m_pFlow->Truncate(0);
		}

	/* */
	private:
		///订阅业务进程状态处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnObjectAttrTopic(CFTDCPackage *pFTDCPackage);

		///订阅业务进程状态处理函数
			///@param	pMessage	订阅者收到的包地址
		//void OnRtnNetObjectAttrTopic(CFTDCPackage *pFTDCPackage);
		
			///订阅业务进程状态处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnSyslogInfoTopic(CFTDCPackage *pFTDCPackage);

		///订阅所有用户信息处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnUserInfoTopic(CFTDCPackage *pFTDCPackage);

		///订阅在线用户信息处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnOnlineUserInfoTopic(CFTDCPackage *pFTDCPackage);

		///订阅告警事件信息处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnWarningEventTopic(CFTDCPackage *pFTDCPackage);

		///订阅主机CPU信息处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnTopCpuInfoTopic(CFTDCPackage *pFTDCPackage);

		///订阅Local Ping信息处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnLocalPingResultTopic(CFTDCPackage *pFTDCPackage);

		///订阅Remote Ping信息处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnRemotePingResultTopic(CFTDCPackage *pFTDCPackage);

		///订阅主机内存信息处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnTopMemInfoTopic(CFTDCPackage *pFTDCPackage);

		///订阅主机进程信息处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnTopProcessInfoTopic(CFTDCPackage *pFTDCPackage);

		///订阅主机磁盘IO信息处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnDiskIOInfoTopic(CFTDCPackage *pFTDCPackage);

		///订阅路由信息处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnRouteInfoTopic(CFTDCPackage *pFTDCPackage);

		///订阅系统信息处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnStatInfoTopic(CFTDCPackage *pFTDCPackage);

		///订阅主机文件系统信息处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnFileSystemInfoTopic(CFTDCPackage *pFTDCPackage);

		///订阅网络使用信息处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnNetworkInfoTopic(CFTDCPackage *pFTDCPackage);

		void OnRtnWebAppInfoTopic(CFTDCPackage *pFTDCPackage);
		void OnRtnMemPoolInfoTopic(CFTDCPackage *pFTDCPackage);
		void OnRtnConnectorInfoTopic(CFTDCPackage *pFTDCPackage);
		void OnRtnDbQueryTopic(CFTDCPackage *pFTDCPackage);
		void OnRtnWarningQueryTopic(CFTDCPackage *pFTDCPackage);

		///主机环境信息请求应答处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRspQryHostEnvTopic(CFTDCPackage *pFTDCPackage);

		///配置信息更新请求应答处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnUpdateSysConfigTopic(CFTDCPackage *pFTDCPackage);

		void OnRtnSyslogEventTopic(CFTDCPackage *pFTDCPackage);

		///切换告警有效状态的订阅处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRtnWarningActiveChange(CFTDCPackage *pFTDCPackage);

		///网络设备连接状态处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRtnNetDeviceLinkTopic(CFTDCPackage *pFTDCPackage);

		///网络设备连接状态处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRtnNetMonitorTaskResultTopic(CFTDCPackage *pFTDCPackage);

		void OnRtnNetPartyLinkStatusInfoTopic(CFTDCPackage *pFTDCPackage);

		//响应网络监控对象树信息(复用已有结构)
		void OnRtnNetAreaTopic(CFTDCPackage *pFTDCPackage);

	/* */
	public:
		///重新将流数据导入内存数据库
		void ReLoad(void);
		void OnRtnTradeUserLoginInfo(CFTDCPackage *pFTDCPackage);
		///保存数据包的流地址
		CCachedFileFlow *m_pFlow;

		///发送数据包使用的缓冲区
		CFTDCPackage m_pkgSend;

		///流重启回读标志位
		bool m_reload;

		///订阅流的编号
		int m_nFlowSeq;
};

///用于reload进程对象状态的宏
#define RELOADEVENTPACKAGE(x)												 \
	{																		 \
		CFTDRtn##x##Field fieldInfo;										 \
		CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(		 \
				&CFTDRtn##x##Field::m_Describe);							 \
		while (!itor.IsEnd())												 \
		{																	 \
			itor.Retrieve(&fieldInfo);										 \
			CWriteableSysMdb##x mdbfield;									 \
			mdbfield.ObjectID = g_StringIdMap.getStringId(					 \
					fieldInfo.ObjectID.getValue());							 \
			mdbfield.AttrType = g_StringIdMap.getStringId(					 \
					fieldInfo.AttrType.getValue());							 \
			mdbfield.MonTime = fieldInfo.MonTime;							 \
			mdbfield.ValueType = fieldInfo.ValueType;						 \
			mdbfield.AttrValue = fieldInfo.AttrValue;						 \
			pMemoryDB->m_SysMdb##x##Factory->add(&mdbfield, NULL);			 \
			itor.Next();													 \
			if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd()) \
			{																 \
				break;														 \
			}																 \
		}																	 \
	}

///用于处理主机环境变量RSP信息的宏
#define ADDENVPACKAGETOMDB(x)															   \
	{																					   \
		CWriteableRspQryHostEnv##x	mdbfield;											   \
		CopyRspQryHostEnv##x##Entity(													   \
			&mdbfield,																	   \
			&field##x##Info) pMemoryDB->m_RspQryHostEnv##x##Factory->add(&mdbfield, NULL); \
	}

#endif // REF_CSTATUSSUBSCRIBER_H
