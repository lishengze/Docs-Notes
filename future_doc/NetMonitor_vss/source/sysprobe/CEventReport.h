/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CEventReport.h
///@brief	定义了探针告警输出的类
///@history
///20090106	周建军		新建文件
#ifndef REF_CEVENTREPORT_H
#define REF_CEVENTREPORT_H

#include "public.h"
#include "CachedFileFlow.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"

/////////////////////////////////////////////////////////////////////////
///CEventReport 定义了派发告警事件的类
///@author	周建军
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CEventReport
{
	/* */
	public:
		///构造函数
		CEventReport(void);

		///产生告警事件，并打包发送到所有的连接
			///@param	pEventName	告警事件名
			///@param	pObjectName	告警对象名
		void GenerateProbeEvent(char *pEventName, char *pObjectName);

	/* */
	protected:
	/* */
	private:
		///用于发送数据包使用的缓冲区
		CFTDCPackage m_pkgSend;

		///保存告警发生时间的map
			///key	告警事件名称
			///value	告警最近发生的时间
		map<string, int> m_mapEventDesc;

		///告警产生的时间间隔
		int m_nInterval;

		///告警事件序列号，递增
		int m_nEventId;

		///告警事件名编号，相同对象的相同告警每次均相同
		int m_nEventNum;
};
#endif // !defined(REF_CEVENTREPORT_H)
