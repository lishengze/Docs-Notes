/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	CAyncGetThread.h
///@brief	定义了CAyncGetThread使用的类
///@history
///20100920	周建军		创建该文件
#ifndef REF_CASUNCGETTHREAD_H
#define REF_CASUNCGETTHREAD_H

#include "FtdPackageDesc.h"
#include "systools.h"
#include "CAsyncGetDevices.h"
#include "CGetDeviceInfo.h"

class CDevice
{
	/* */
	public:

		///构造函数
		CDevice(void)
		{
			m_sHostName = "";
			m_sDevIp = "";
			m_sCommunity = "";
			m_sOidName = "";
			m_sAttrType = "";
			m_sSeps = "";
			m_netName = "";
			m_centerName = "";
			m_sAttendValue = "", m_objID = "", m_type = 0;
		}

		///构造函数
			///@param	pDevIp	被管设备的IP地址
			///@param	pCommunity	snmp通信关键字
			///@param	pOidName	Oid名称
			///@param	pSeps	采集时间段
		CDevice(
		const char	*pHostName,
		const char	*pDevIp,
		const char	*pCommunity,
		const char	*pNetName,
		const char	*pCenterName,
		const char	*pOidName,
		const char	*pAttrType,
		const char	*pSeps,
		const char	*pAttendValue,
		const char	*pObjectID)
		{
			m_sHostName = pHostName;
			m_sOidName = pOidName;
			m_sDevIp = pDevIp;
			m_sCommunity = pCommunity;
			m_netName = pNetName;
			m_centerName = pCenterName;
			m_sAttrType = pAttrType;
			m_sSeps = pSeps;
			m_sAttendValue = pAttendValue;
			m_objID = pObjectID;
		}

		//CDevice(const char *pHostName, const char *pDevIp, const char *pCommunity, const char *pOidName,
		//	const char *pAttrType, const char *pSeps, const char *pAttendValue,const char *pObjectID)
		//{
		//	CDevice(pHostName,pDevIp,pCommunity,"","",pOidName,pAttrType,pSeps,pAttendValue);
		//	m_objID = pObjectID;

		//}
			///拷贝构造函数
		CDevice(const CDevice &ob)
		{
			m_sHostName = ob.m_sHostName;
			m_sCommunity = ob.m_sCommunity;
			m_sDevIp = ob.m_sDevIp;
			m_sOidName = ob.m_sOidName;
			m_sAttrType = ob.m_sAttrType;
			m_sSeps = ob.m_sSeps;
			m_netName = ob.m_netName;
			m_centerName = ob.m_centerName;
			m_sAttendValue = ob.m_sAttendValue;
			m_objID = ob.m_objID;
			m_type = ob.m_type;
		}

		///赋值
		void operator=(const CDevice &ob)
		{
			m_sHostName = ob.m_sHostName;
			m_sCommunity = ob.m_sCommunity;
			m_sDevIp = ob.m_sDevIp;
			m_sOidName = ob.m_sOidName;
			m_sAttrType = ob.m_sAttrType;
			m_sSeps = ob.m_sSeps;
			m_netName = ob.m_netName;
			m_sAttendValue = ob.m_sAttendValue;
			m_centerName = ob.m_centerName;
			m_objID = ob.m_objID;
			m_type = ob.m_type;
		}

		void setTaskType(int type)
		{
			m_type = type;
		}

		void setObjectID(const char *objid)
		{
			m_objID = string(objid);
		}

	/* */
	public:
		string	m_sHostName;

		///设备的IP地址
		string	m_sDevIp;

		///通讯字
		string	m_sCommunity;

		///OID
		string	m_sOidName;

		///OID对应的类型
		string	m_sAttrType;

		///时间采样频率
		string	m_sSeps;

		///objID的组成部分
		string	m_netName;
		string	m_centerName;

		///OID 需要增加到ObjectID的补充字段
		string	m_sAttendValue;

		////objID
		string	m_objID;

		///任务类型
		int m_type;

	/* */
	protected:
	/* */
	private:
};

class CAyncGetThread :
	public CThread
{
	/* */
	public:

		///构造函数
			///@param	nThreadNum	启动的线程编号
			///@param	pMibsPath	Mib文件所在目录
		CAyncGetThread(int nThreadNum, const char *pMibsPath) :
		m_cAsyncIns(nThreadNum, pMibsPath)
		{
			m_nThreadNum = nThreadNum;

			m_nTimeZoneSec = getTimeZoneOffset();
			it_data = datas.begin();
		}

		///析构函数
		~CAyncGetThread(void)
		{
			printf("GetThread id %d run end\n", m_nThreadNum);
			ExitThread();
		}

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
		///用于让主程序把线程生成的数据发送出去
		void GetSpi(void);

		///用于获取m_cAsyncIns实例对象
		CAsyncGetDevices *GetAsyncIns(void)
		{
			return &m_cAsyncIns;
		}

		///增加被管设备OID到线程函数
			///@param	pDevIp	被管设备的IP地址
			///@param	pCommunity	snmp通信关键字
			///@param	pOidName	Oid名称
			///@param	pAttrName	Oid对应的指标类型
			///@param	pSeps	采样频率,如 "08:00:00-12:00:00.60,12:00:00-23:00:00.5"
		void addMonDevice(
		const char	*pHostName,
		const char	*pDevIp,
		const char	*pCommunity,
		const char	*pNetName,
		const char	*pCenterName,
		const char	*pOidName,
		const char	*pAttrType,
		const char	*pSeps,
		const char	*pAttendValue = "")
		{
			m_listDevice.add(
					CDevice(
						pHostName,
						pDevIp,
						pCommunity,
						pNetName,
						pCenterName,
						pOidName,
						pAttrType,
						pSeps,
						pAttendValue,
						NULL));
		}

		///增加被管设备OID到线程函数
			///@param	phost	被管设备指针
			///@param	pOidName	Oid名称
			///@param	pAttrName	Oid对应的指标类型
			///@param	pSeps	采样频率,如 "08:00:00-12:00:00.60,12:00:00-23:00:00.5"
			///@param	pAttendValue	指标附加值
		void addMonDevice(
		const CFTDSysNetDeviceField *phost,
		const char	*pOidName,
		const char	*pAttrType,
		const char	*pPolicySeps,
		int taskType,
		const char	*pAttendValue = "",
		int  oidmeans = 0)
		{
			m_cAsyncIns.addMonDevice(
					phost,
					pOidName,
					pAttrType,
					pPolicySeps,
					taskType,
					pAttendValue,
					oidmeans);
		}

		void addMonDeviceNew(
		const char	*pHostName,
		const char	*pDevIp,
		const char	*pCommunity,
		const char	*pObjectID,
		const char	*pOidName,
		const char	*pAttrType,
		const char	*pPolicySeps,
		int taskType,
		const char	*pAttendValue = "")
		{
			CDevice c_dev = CDevice(
					pHostName,
					pDevIp,
					pCommunity,
					"",
					"",
					pOidName,
					pAttrType,
					pPolicySeps,
					pAttendValue,
					pObjectID);
			c_dev.m_type = taskType;
			m_listDevice.add(c_dev);
		}

		///读取采集配置函数
		void getMonDevice(void)
		{
			CDevice cDeviceInfo;
			while (m_listDevice.get(cDeviceInfo))
			{
				m_cAsyncIns.addMonDevice(
						cDeviceInfo.m_sHostName.c_str(),
						cDeviceInfo.m_sDevIp.c_str(),
						cDeviceInfo.m_sCommunity.c_str(),
						cDeviceInfo.m_netName.c_str(),
						cDeviceInfo.m_centerName.c_str(),
						cDeviceInfo.m_sOidName.c_str(),
						cDeviceInfo.m_sAttrType.c_str(),
						cDeviceInfo.m_sSeps.c_str(),
						"",
						cDeviceInfo.m_sAttendValue.c_str());
			}
		}

		void getMonDeviceNew(void)
		{
			CDevice cDeviceInfo;
			while (m_listDevice.get(cDeviceInfo))
			{
				m_cAsyncIns.addMonDeviceNew(
						cDeviceInfo.m_sDevIp.c_str(),
						cDeviceInfo.m_sCommunity.c_str(),
						cDeviceInfo.m_objID.c_str(),
						cDeviceInfo.m_sOidName.c_str(),
						cDeviceInfo.m_sAttrType.c_str(),
						cDeviceInfo.m_sSeps.c_str(),
						cDeviceInfo.m_type,
						cDeviceInfo.m_sAttendValue.c_str());
			}
		}

		///读取snmpget的ObjectAttr函数
		bool getConObjectAttr(CFTDRtnObjectAttrField &objectAttr)
		{
			return m_cAsyncIns.m_listConObjectAttr.get(objectAttr);
		}

		///读取snmpget的ObjectAttr函数
		bool getObjectAttr(CFTDRtnObjectAttrField &objectAttr)
		{
			return m_cAsyncIns.m_listObjectAttr.get(objectAttr);
		}

		///读取snmpget产生的WarningEvent函数
		bool getWarningEvent(CFTDRtnWarningEventField &warningEvent)
		{
			return m_cAsyncIns.m_listWarningEvent.get(warningEvent);
		}

		///读取snmpget产生的SyslogEvent函数
		bool getSyslogEvent(CFTDRtnSyslogEventField &syslogEvent)
		{
			return m_cAsyncIns.m_listSyslogEvent.get(syslogEvent);
		}

		///读取snmpget产生的UpdateSysConfig函数
		bool getUpdateSysConfig(CFTDRtnUpdateSysConfigField &updateConfig)
		{
			return m_cAsyncIns.m_listUpdateConfig.get(updateConfig);
		}

		///判断线程中是否加入设备为ip的监控指标
		bool isMonitorDevTask(const char *ip)
		{
			map<string, CMonDevice>::iterator it = m_cAsyncIns.m_mapDevices.find(
					ip);
			if (it != m_cAsyncIns.m_mapDevices.end())
			{
				return true;
			}

			return false;
		}

		///重新设置监控对象
		void removeMonTask(const char *ip, const char *pOidName)
		{
			if (ip != NULL && strlen(ip) > 1)
			{
				m_cAsyncIns.removeMonDeviceTask(ip, pOidName);
			}
			else
			{
				m_cAsyncIns.clearMonDevice();
			}
		}

	/* */
	private:
		int m_nTimeZoneSec;

		// 线程编号，从0开始
		int m_nThreadNum;

		///异步取设备snmp信息实例
		CAsyncGetDevices m_cAsyncIns;

		///被管设备OID队列
		TemplateMutexCatch<CDevice> m_listDevice;

	/* */
	public:
		///保存从配置文件中读到的数据，用于模拟产生DataField
			///@key	数据类别
			///@value	数据信息
		list<pair<int, string> > datas;
		list<pair<int, string> >::iterator	it_data;
};
#endif
