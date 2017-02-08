/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CResultSubcriber.h
///@brief	定义了订阅交易流水处理消息的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
#ifndef REF_CRESULTSUBSCRIBER_H
#define REF_CRESULTSUBSCRIBER_H

#include "public.h"
#include "CachedFlow.h"
#include "CachedFileFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include "databaseData.h"
#include "UFCopy.h"

extern CMemoryDB *pMemoryDB;
extern CStringIdMap g_StringIdMap;

class CResultSubscriber :
	public CFTDCSubscriber
{
	/* */
	public:
		///构造函数	
		CResultSubscriber(void);

		///析构函数
		~ CResultSubscriber(void);

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
	private:
		///错误报单处理函数
			///@param	pMessage	处理的数据包地址
		//	void OnRtnInvalidateOrderTopic(CFTDCPackage *pMessage);
		
			///报单状态处理函数
			///@param	pMessage	处理的数据包地址
		//	void OnRtnOrderStatusTopic(CFTDCPackage *pMessage);
		
			///成交单处理函数
			///@param	pMessage	处理的数据包地址
		//	void OnRtnBargainOrderTopic(CFTDCPackage *pFTDCPackage);
		
			///合约属性处理函数
			///@param	pFTDCPackage	处理的数据包地址
		void OnRtnInstPropertyTopic(CFTDCPackage *pFTDCPackage);

		///交易用户登录处理函数
			///@param	pFTDCPackage	处理的数据包地址
		void OnRspQryTradeUserLoginInfo(CFTDCPackage *pFTDCPackage);

		///交易用户登出处理函数
			///@param	pFTDCPackage	处理的数据包地址
		void OnRtnTradeUserLoginInfo(CFTDCPackage *pFTDCPackage);

		///会员交易处理函数
			///@param	pFTDCPackage	处理的数据包地址
		void OnRspQryPartTrade(CFTDCPackage *pFTDCPackage);

		///保证金率变动处理函数
			///@param	pFTDCPackage	处理的数据包地址
		void OnRtnMarginRateChgTopic(CFTDCPackage *pFTDCPackage);

		///涨跌停板变动处理函数
			///@param	pFTDCPackage	处理的数据包地址
		void OnRtnPriceLimitChgTopic(CFTDCPackage *pFTDCPackage);

		///会员限仓变动处理函数
			///@param	pFTDCPackage	处理的数据包地址
		void OnRtnPartPosiLimitChgTopic(CFTDCPackage *pFTDCPackage);

		///客户限仓变动处理函数
			///@param	pFTDCPackage	处理的数据包地址
		void OnRtnClientPosiLimitChgTopic(CFTDCPackage *pFTDCPackage);

		///特殊客户限仓变动处理函数
			///@param	pFTDCPackage	处理的数据包地址
		void OnRtnSpecPosiLimitChgTopic(CFTDCPackage *pFTDCPackage);

		void OnRspQryFrontStat(CFTDCPackage *pFTDCPackage);

		void OnRtnDataCenterChgTopic(CFTDCPackage *pFTDCPackage);

		void OnRtnSysTimeSyncTopic(CFTDCPackage *pFTDCPackage);

		void OnRtnParticTradeOrderStatesTopic(CFTDCPackage *pFTDCPackage);
		void OnRtnClientInitTopic(CFTDCPackage *pFTDCPackage);
	/* */
	public:
		///保存数据包的流地址
		CCachedFileFlow *m_pFlow;

		///发送数据包使用的缓冲区
		CFTDCPackage m_pkgSend;

		///重启流回读标志位
		bool m_reload;
};
#endif // REF_CRESULTSUBSCRIBER_H  END
