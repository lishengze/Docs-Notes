/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CMsgGenerator.h
///@brief	定义了生成消息文件的工具类
///@history
///20111214	晏鹤春	创建该文件
///20111223	晏鹤春	增加消息队列及落地时间策略的处理
#ifndef REF_CMSGGENERATOR_H
#define REF_CMSGGENERATOR_H

#include "public.h"
#include "systools.h"
#include "FtdPackageDesc.h"
#include "CTimePolicy.h"

#define FLAG_MSG_LINE	"<br/>"

//// CMsgNMEvent 类是用于保存网络设备事件的相关信息类
class CMsgNMEvent
{
	/* */
	public:
		CMsgNMEvent(void);
		CMsgNMEvent(
			CFTDRtnWarningEventField &EventField,
			string	&Device,
			string	&Party,
			int Times);
		~ CMsgNMEvent(void);

		CFTDRtnWarningEventField m_EventField;
		string	m_strDevice;
		string	m_strParty;
		int m_iTimes;
};

typedef TemplateMutexCatch<CMsgNMEvent> CMsgNMEventList;

//// CMsgGenerator 类是用于生成事件消息的工具线程类
class CMsgGenerator :
	public CThread
{
	/* */
	public:
		CMsgGenerator(void);
		CMsgGenerator(char *pszPath, char *pszMsgPolicy, char *pszSystemID);
		~ CMsgGenerator(void);

		/**虚函数，子类可做一些实例化工作
	* @return true:创建成功 false:创建失败
	*/
		virtual bool InitInstance(void);

		/**虚函数，子类清楚实例
	*/
		virtual void ExitInstance(void);

		/**线程开始运行，纯虚函数，子类必须继承实现
	*/
		virtual void Run(void);

		/// 添加网络设备事件消息到队列
		int AddNetDeviceEventMsg(
				CFTDRtnWarningEventField &EventField,
				string	&Device,
				string	&Party,
				int Times);

		/// 生成网络设备事件消息
		int GenNetDeviceEventMsg(void);

		void Init(char *pszPath, char *pszMsgPolicy, char *pszSystemID);

	/* */
	private:
		/// 将指定内容写入到指定文件中
		int WriteMsg(char *pszFile, char *pszMsg);

		/// 刷新内存中的当前日期时间值
		void RefreshDateTime(void);

		/// 获取默认消息文件名(带路径)
		char *GenMsgFileName(void);

		/// 获取网络设备事件消息内容体
		char *GenNetDeviceEventContent(
				CFTDRtnWarningEventField &EventField,
				string	&Device,
				string	&Party,
				int Times);

	/* */
	private:
		string	m_strPath;						// 消息文件的保存路径
		string	m_strSystemID;					// 消息专用监控系统ID标识
		CDateTime m_DateTime;					// 用于保存当前时间
		CTimePolicy m_TimePolicy;				// 用于保存消息信息落地控制的时间策略
		CMsgNMEventList m_lEvents;				// 用于保存事件消息的互斥队列
			/// Key:事件的EventNum	Value:事件最近一次落地时的时间戳
		map<int, time_t> m_mapEventDumpTime;	// 用于保存事件最近一次落地的时间戳
		int m_iMaxRetry;						// 消息发送最大重试次数
		int m_iRetrySpan;						// 消息重发间隔(秒数)
};
#endif
