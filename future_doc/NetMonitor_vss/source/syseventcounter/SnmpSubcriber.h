/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	SnmpSubcriber.h
///@brief	定义了事件计算服务器订阅snmpmanager的类
///@history
///20100910	周建军		创建该文件
#ifndef REF_SNMPSUBCRIBER_H
#define REF_SNMPSUBCRIBER_H

#include "public.h"
#include "CachedFlow.h"
#include "CachedFileFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include "databaseData.h"

class CEventCounterServer;
class CSnmpSubscriber :
	public CFTDCSubscriber
{
	/* */
	public:
		///构造函数	
			///@param	nFlowSeq	流编号
			///@param	nManagerId	管理端启动编号
		CSnmpSubscriber(
			int nFLowSeq,
			int nManagerId,
			CEventCounterServer *pEventCounterServer);

		///析构函数
		~ CSnmpSubscriber(void);

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

		///重新将流数据导入内存数据库
		void ReLoad(void);

		///将现有内存数据库与本流相关内容清空
		void UnLoad(void);

	/* */
	public:
		void SetSession(CFTDCSession *pSession)
		{
			m_pSession = pSession;
		}

	/* */
	public:
		///保存数据包的流地址
		CCachedFileFlow *m_pFlow;

		///保存CounterServer对象指针
		CEventCounterServer *m_pEventCounterServer;

		///发送数据包使用的缓冲区
		CFTDCPackage m_pkgSend;

		///流编号
		int m_nFlowSeq;

		///管理端启动编号
		int m_nManagerId;

		///本订阅者所属的会话
		CFTDCSession *m_pSession;
};

class CResultSubscriber :
	public CFTDCSubscriber
{
	/* */
	public:

		///构造函数	
		CResultSubscriber(void)
		{
			m_pFlow = new CCachedFileFlow(
					"fibResultFlow",
					"./flow/",
					true,
					100,
					32 * 1024);
			m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
		}

		///析构函数
		~CResultSubscriber(void)
		{
			delete m_pFlow;
		}

		///设置通讯阶段号函数
			///@param	wCommPhaseNo	需要设置的通信阶段号
		virtual void SetCommPhaseNo(WORD wCommPhaseNo)
		{
		}

		///获取流序列号函数
			///@return	返回流的当前序列号
		virtual WORD GetSequenceSeries(void)	//流编号
		{
			return 1000;
		}

		///获取收到流中包含的包总数函数
			///@return	返回当前订阅收到的包总数
		virtual DWORD GetReceivedCount(void)	//收到的包个数
		{
			return m_pFlow->GetCount();
		}

		///订阅收到的包处理函数,是发布/订阅模型收到的数据包
			///@param	pMessage	订阅者收到的包地址
		virtual void HandleMessage(CFTDCPackage *pMessage)
		{
			printf(
				"\CResultSubscriber::HandlePackage:receive package %0x\n",
				pMessage->GetTID());
		}

	/* */
	private:
	/* */
	public:
		///保存数据包的流地址
		CCachedFileFlow *m_pFlow;

		///发送数据包使用的缓冲区
		CFTDCPackage m_pkgSend;
};
#endif
