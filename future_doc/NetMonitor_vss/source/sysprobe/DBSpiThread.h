#pragma once
#include "public.h"
#include "Thread.h"
#include "DatabaseSpiImpl.h"
#include "SyslogSpiImpl.h"

class CDBSpiThread :
	public CThread
{
	/* */
	public:
		CDBSpiThread(void);
		~ CDBSpiThread(void);

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

#if 0
		///用于更新数据库连接map对象函数
			///@param	sConfigName	数据库的别名
			///@param	sConnectString	数据库的地址连接信息
		void UpdateDatabaseInfoMap(
				string	sConfigName,
				CDBConnectString sConnectString);

		///用于更新指标采集map对象函数，本函数用来统计表大小
			///@param	pAttrName	数据库指标名称
			///@param	pSeps	指标采样时间段频率
			///@param	pDNSName	数据库的别名
			///@param	pTableName	数据库的表名称
		void UpdateDBAttrMap(
				const char	*pAttrName,
				const char	*pSeps,
				const char	*pDNSName,
				const char	*pTableName);

		///用于更新数据库调用存储过程对象函数
			///@param	pSPName	SP名称
			///@param	pSeps	读取SP的时间及频率信息
			///@param	pDNSName	数据库别名信息
			///@param	pSPType	SP的返回值类型
		void UpdateSPInfoMap(
				const char	*pSPName,
				const char	*pSeps,
				const char	*pDNSName,
				const char	*pSPType);

		///用于更新数据库读取日志表对象函数
			///@param	pTableName	日志表名称
			///@param	pSeps	读取日志表的时间及频率信息
			///@param	pDNSName	数据库别名信息
			///@param	pPosition	数据库表已经读取到的偏移量信息
		void UpdateDBLogMap(
				const char	*pTableName,
				const char	*pSeps,
				const char	*pDNSName,
				const char	*pPosition);
#endif

		///用于更新数据库临时查询请求对象函数
			///@param	pObjectId	请求数据库对象的ID
			///@param	pAttrType	请求数据库查询的SP名称
			///@param	dRequestId	请求的RequestId编号
			///@param	pSession	该请求所属的ftd Session
		void UpdateSPQuery(
				const char	*pObjectId,
				const char	*pAttrType,
				const DWORD dRequestId,
				const CFTDCSession	*pSession);
		void UpdateConfig(CFTDRspQryHostConfigField *hostConfig);

	/* */
	private:
		// 控制是否退出
		bool m_bExit;

		// 控制是否进行工作， 不工作的时候休眠
		int m_iWork;

		///FTD数据包发送缓冲区
		CFTDCPackage m_pkgSend;

		///数据库取指标spi
		CDatabaseSpiImpl *pDatabaseSpi;
};
