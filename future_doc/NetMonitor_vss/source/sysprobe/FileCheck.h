#pragma once
#include "public.h"
#include "Thread.h"
#include "DatabaseSpiImpl.h"
#include "SyslogSpiImpl.h"

///分析URL函数
///@param	pUrl	URL地址,如http://www.shfe.com.cn:80/testweblogic.jsp
///@param	sDomainName	保存分析出来的域名:www.shfe.com.cn
///@param	nPort	保存分析出来的域名端口号:80
///@param	sHtmlUrl	保存分析出来的url:testweblogic.jsp
bool explainUrl(
		const char	*pUrl,
		string	&sDomainName,
		int &nPort,
		string	&sHtmlUrl);

#ifdef LINUX
#include <ftw.h>
class CFileCheckValue
{
	/* */
	public:
		~CFileCheckValue(void)
		{
		}

		CFileCheckValue(void)
		{
			st_size = 0;
			st_time = 0;
			mResult = 0;
			md5file = "";
		}

		CFileCheckValue(off_t size, time_t mtime, const char *file)
		{
			st_size = size;
			st_time = mtime;
			md5file = file;
			mResult = 0;
		}

		CFileCheckValue(const CFileCheckValue &ob)
		{
			st_size = ob.st_size;
			st_time = ob.st_time;
			md5file = ob.md5file;
			mResult = ob.mResult;
		}

		void operator=(const CFileCheckValue &ob)
		{
			st_size = ob.st_size;
			st_time = ob.st_time;
			md5file = ob.md5file;
			mResult = ob.mResult;
		}

	/* */
	public:
		off_t st_size;
		time_t	st_time;
		int mResult;
		string	md5file;
};
#endif
class CHtmlTestValue
{
	/* */
	public:
		CHtmlTestValue(void)
		{
			m_sDomain = "";
			m_nPort = 80;
			m_sHtmlUrl = "";
			m_sHtmlValue = "";
		}

		///构造函数
			///@param	nPort	端口号
			///@param	sHtmlUrl	测试网页的Url
			///@param	pHtmlValue	测试网页的值
		CHtmlTestValue(
		string	&sDomain,
		int nPort,
		string	&sHtmlUrl,
		const char	*pHtmlValue)
		{
			m_sDomain = sDomain;
			m_nPort = nPort;
			m_sHtmlUrl = sHtmlUrl;
			m_sHtmlValue = pHtmlValue;
		}

		CHtmlTestValue(const CHtmlTestValue &ob)
		{
			m_sDomain = ob.m_sDomain;
			m_nPort = ob.m_nPort;
			m_sHtmlUrl = ob.m_sHtmlUrl;
			m_sHtmlValue = ob.m_sHtmlValue;
		}

		void operator=(const CHtmlTestValue &ob)
		{
			m_sDomain = ob.m_sDomain;
			m_nPort = ob.m_nPort;
			m_sHtmlUrl = ob.m_sHtmlUrl;
			m_sHtmlValue = ob.m_sHtmlValue;
		}

		~CHtmlTestValue(void)
		{
		}

	/* */
	public:
		///web服务器测试网页域名地址
		string	m_sDomain;

		///web服务器端口号
		int m_nPort;

		///web服务器的测试Url
		string	m_sHtmlUrl;

		///web服务器测试网页的值
		string	m_sHtmlValue;
};

class CFileCheckThread :
	public CThread
{
	/* */
	public:
		CFileCheckThread(void);
		~ CFileCheckThread(void);

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

	/* */
	public:
		// 用于让主程序把线程生成的数据发送出去
		void GetSpi(void);

		///用于更新校验检查对象函数
			///@param	pCheckPath	请求校验的源文件路径
			///@param	pMD5Path	请求校验的md5密码文件路径
			///@param	pSeps	校验时间段及频率
		void UpdateCheckConfig(
				const char	*pCheckPath,
				const char	*pMD5Path,
				const char	*pSeps);

		///用于更新网页校验检查对象函数
			///@param	sDomainName	域名
			///@param	nPort	端口
			///@param	sHtmlUrl	测试的url
			///@param	pHtmlValue	网页的值
			///@param	pSeps	校验时间段及频率
		void UpdateCheckHtml(
		string	sObjectName,
		string	&sDomainName,
		int nPort,
		string	&sHtmlUrl,
		const char	*pHtmlValue,
		const char	*pSeps)
		{
			m_lockMap.Lock();
			m_mapCheckHtml[sObjectName] = CHtmlTestValue(
					sDomainName,
					nPort,
					sHtmlUrl,
					pHtmlValue);
			if (NULL == m_pHtmlRun)
			{
				m_pHtmlRun = new CJudgeRun(pSeps);
			}

			m_lockMap.UnLock();
		}

	/* */
	private:
		///用于检查web服务器测试网页是否工作正常函数
			///@param	pObjectName	web服务器对象名称,如："apache.1"
			///@param	pServerIp	web服务器ip地址
			///@param	nPort		web服务器的端口号
			///@param	pServerName	web服务器域名
			///@param	pHtmlUrl	web服务器的Url
			///@param	pHtmlValue	web服务器校验的目标值
		int htmlTest(
				const char	*pObjectName,
				const char	*pServerIp,
				int nPort,
				const char	*pServerName,
				const char	*pHtmlUrl,
				const char	*pHtmlValue);
		void htmlTestPage(
				const char	*pObjectName,
				const char	*pServerName,
				int nPort,
				const char	*pHtmlUrl,
				const char	*pHtmlValue);

		///用于分析Token串中包含指标或事件信息的方法
			///@param	pObjectName	web服务器对象名称,如："apache.1"
			///@param	pToken	校验页面返回的信息字串
			///@param	pHtmlValue	web服务器校验的目标值
		void Analizer(
				const char	*pObjectName,
				char *pToken,
				const char	*pHtmlValue);

#ifdef LINUX
		static int	fn(const char *file, const struct stat *sb, int flag);
#endif

	/* */
	private:
		// 数据锁，用于保护校验map
		CMutex	m_lockMap;

		///FTD数据包发送缓冲区
		CFTDCPackage m_pkgSend;

		///@key	校验的源文件路径
			///@value	校验的密码文件路径
		map<string, string> m_mapCheckFile;

		///@key	网页的域名
			///@value	网页校验的值
		map<string, CHtmlTestValue> m_mapCheckHtml;

		CJudgeRun *m_pJudgeRun;
		CJudgeRun *m_pHtmlRun;

		/// 单次校验的计数器
		int m_iAttrCount;		/// 指标对象计数器
		int m_iSuccessCount;	/// 成功对象计数器
		int m_iFailedCount;		/// 失败对象计数器
		
			///数据锁，用于保护数据队列
		static CMutex s_lockData;

		//对象指标队列
		list<CFTDRtnObjectAttrField> s_objectAttr;

		///告警事件队列
		static list<CFTDRtnWarningEventField> s_warningEvent;

		///日志事件队列
		static list<CFTDRtnSyslogEventField> s_syslogEvent;
};
