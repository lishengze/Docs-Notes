/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	CAsyncGetDevices.h
///@brief	定义了CAsyncGetDevices使用的类
///@history
///20100920	周建军		创建该文件
#ifndef REF_CASUNCGETDEVICES_H
#define REF_CASUNCGETDEVICES_H

#include "platform.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include "net_snmp.h"
#include "CSnmpWrapper.h"
#include "CTimePolicy.h"

#include <string>
#include <list>
#include <map>
#include <iostream>
using namespace std;

#define SNMPSYSNAMEOID	"1.3.6.1.2.1.1.5.0"
enum EVENT_TYPE
{
	INTERFACE_EVENT_TYPE= 1,	//"端口"
	FLUX_EVENT_TYPE,			//"流量"
	NETDEV_EVENT_TYPE,			//"网络设备"
	DEVLINK_EVENT_TYPE,			//"设备连通"
	ROUTE_EVENT_TYPE,			//"路由"
	PERMAN_EVENT_TYPE,			//"性能"
	SAFETY_EVENT_TYPE,			//"安全"
	OTHERS_EVENT_TYPE,			//"其它"
};

enum MON_TASK_STATUS
{
	PREPARE_STATUS		= 0,	//"任务就绪"
	NORMAL_STATUS,				//"任务正常"
	UNWORK_STATUS,				//"任务无效"
	OTHERS_STATUS,				//"其它"
};

enum MON_TASK_TYPE
{
	DURING_TASK			= 0,	//周期采集指标任务
	LOOP_TASK,					//巡检中指标任务
	ONCE_TASK,					//一天执行一次的任务
};

//Oid类
class CVarOid
{
	/* */
	public:

		///析构函数
		~CVarOid(void)
		{
			if (m_pTimePolicy != NULL)
			{
				delete m_pTimePolicy;
				m_pTimePolicy = NULL;
			}
		}

		///构造函数
		CVarOid(void)
		{
			m_sOidName = "";
			memset((char *)m_sOoid, 0, MAX_OID_LEN);
			m_nOidLen = 0;
			m_pTimePolicy = NULL;
			m_sAttendValue = "";
			type = 0;
			exestate = 0;
			m_oidmeans = 0;
		}

		CVarOid(const CVarOid &ob)
		{
			m_sOidName = ob.m_sOidName;
			memcpy((char *)m_sOoid, (char *)ob.m_sOoid, MAX_OID_LEN);
			m_nOidLen = ob.m_nOidLen;
			m_sAttendValue = ob.m_sAttendValue;
			type = ob.type;
			exestate = ob.exestate;
			m_oidmeans = ob.m_oidmeans;
			if (ob.m_pTimePolicy == NULL)
			{
				m_pTimePolicy = NULL;
			}
			else
			{
				m_pTimePolicy = new CTimePolicy(*(ob.m_pTimePolicy));
			}
		}

		///构造函数
			///@param	pOidName	OID名
		CVarOid(
		const char	*pOidName,
		const char	*pPolicy,
		int ntype,
		const char	*pAttendValue)
		{
			m_sOidName = pOidName;
			m_sAttendValue = pAttendValue;
			memset((char *)m_sOoid, 0, MAX_OID_LEN);
			m_nOidLen = sizeof(m_sOoid) / sizeof(m_sOoid[0]);
			exestate = 0;
			m_oidmeans = 0;
			if (pPolicy != NULL)
			{
				m_pTimePolicy = new CTimePolicy(pPolicy);
				type = ntype;
			}
			else
			{
				m_pTimePolicy = NULL;
				type = LOOP_TASK;
			}
		}

		CVarOid &operator=(const CVarOid &ob)
		{
			if (this == &ob)
			{
				return *this;
			}

			m_sOidName = ob.m_sOidName;
			m_sAttendValue = ob.m_sAttendValue;
			type = ob.type;
			exestate = ob.exestate;
			m_oidmeans = ob.m_oidmeans;
			memcpy((char *)m_sOoid, (char *)ob.m_sOoid, MAX_OID_LEN);
			m_nOidLen = ob.m_nOidLen;

			if (m_pTimePolicy)
			{
				delete m_pTimePolicy;
			}

			if (ob.m_pTimePolicy == NULL)
			{
				m_pTimePolicy = NULL;
			}
			else
			{
				m_pTimePolicy = new CTimePolicy(*(ob.m_pTimePolicy));
			}

			return *this;
		}

		///Oid分析函数
			///@return	true表示分析成功，false为失败
		bool snmpParseOid(void)
		{
			m_nOidLen = sizeof(m_sOoid) / sizeof(m_sOoid[0]);
			if (!CSnmpWrapper::parse_oid(
					m_sOidName.c_str(),
				(oid *)m_sOoid,
				(size_t &)m_nOidLen))
			{
				snmp_perror("read_objid");
				return false;
			}

			return true;
		}

		bool changeTimepolicy(const char *pPolicy)
		{
			if (pPolicy != NULL && m_pTimePolicy != NULL)
			{
				m_pTimePolicy->Init();
				m_pTimePolicy->AddPolicyStr(pPolicy);
				return true;
			}

			return false;
		}

		bool updateExeState(int state)
		{
			if (state >= 0)
			{
				exestate = state;
				return true;
			}

			return false;
		}

		void setoidmeans( int oidmeans )
		{
			m_oidmeans = oidmeans;
		}

	/* */
	public:
		///执行本次snmp查询的时间策略
		CTimePolicy *m_pTimePolicy;

		///snmp请求的OID
		string	m_sOidName;

		///该OID可能需要附加的字段,如设备的端口名称
		string	m_sAttendValue;

		///分析之后的ID
		oid m_sOoid[MAX_OID_LEN];

		///分析之后的ID长度
		u_int m_nOidLen;

		///标识采集指标的类型,0:常见周期性采集指标,1:标识通过巡检途径发过来的采集指标，
			///时间策略无效，且执行完之后指标变成无效（非周期性指标）,100:表示发过来后即可执行,往后每天执行一次（执行时刻有策略制定）
		int type;

		//exestate有三种取值:0,1,2，分别代表：就绪，正常，无效，当varoid第一次执行之前处于“就绪”，执行之后变成“正常”或者“无效”
		//通常结合上述type，综合判断是否执行。
		int exestate;

	private:
		//oid采集方式,1表示bulk获取该oid，0表示其它，默认为0
		int m_oidmeans;
};

enum CompAttrVarType
{
	Operator,	// 操作符
	Variate,	// 普通变量
	VariateLast,	// 变量的前一个值
	VariateTime		// 时间变量
};

//设备类
class CMonDevice
{
	/* */
	public:

		///析构函数
		~CMonDevice(void)
		{
			if (m_pSnmpWrapper)
			{
				delete m_pSnmpWrapper;
				m_pSnmpWrapper = NULL;
			}
		}

		///构造函数
		CMonDevice(void)
		{
			m_sHostName = "";
			m_sDevName = "";
			m_sCommunity = "";
			m_bActiveFlag = false;
			CSnmpWrapper::parse_oid(
					(const char *)SNMPSYSNAMEOID,
					(oid *)m_sSysNameOoid,
					(size_t &)m_nSysNameOidLen);
			m_pListObjectAttr = NULL;
			m_pListWarningEvent = NULL;
			m_pListSyslogEvent = NULL;
			m_pListUpdateConfig = NULL;
			m_pDate = NULL;
			m_pTime = NULL;

			m_pSnmpWrapper = NULL;
		}

		CMonDevice(const CMonDevice &ob)
		{
			m_sHostName = ob.m_sHostName;
			m_sDevName = ob.m_sDevName;
			m_sCommunity = ob.m_sCommunity;
			m_mapOid = ob.m_mapOid;
			m_bActiveFlag = ob.m_bActiveFlag;
			CSnmpWrapper::parse_oid(
					(const char *)SNMPSYSNAMEOID,
					(oid *)m_sSysNameOoid,
					(size_t &)m_nSysNameOidLen);
			m_pListObjectAttr = ob.m_pListObjectAttr;
			m_pListWarningEvent = ob.m_pListWarningEvent;
			m_pListSyslogEvent = ob.m_pListSyslogEvent;
			m_pListUpdateConfig = ob.m_pListUpdateConfig;
			m_pDate = ob.m_pDate;
			m_pTime = ob.m_pTime;

			if (NULL == ob.m_pSnmpWrapper)
			{
				m_pSnmpWrapper = NULL;
			}
			else
			{
				m_pSnmpWrapper = new CSnmpWrapper(
						ob.m_pSnmpWrapper->get_community(),
						ob.m_pSnmpWrapper->get_peer_name());
			}
		}

		///构造函数
			///设备的IP地址
			///设备的snmp通信关键字
		CMonDevice(
		const char	*pHostName,
		const char	*pDevName,
		const char	*pCommunity)
		{
			m_sHostName = pHostName;
			m_sDevName = pDevName;
			m_sCommunity = pCommunity;
			m_bActiveFlag = false;
			CSnmpWrapper::parse_oid(
					(const char *)SNMPSYSNAMEOID,
					(oid *)m_sSysNameOoid,
					(size_t &)m_nSysNameOidLen);
			m_pListObjectAttr = NULL;
			m_pListWarningEvent = NULL;
			m_pListSyslogEvent = NULL;
			m_pListUpdateConfig = NULL;
			m_pDate = NULL;
			m_pTime = NULL;
			m_mapOid.clear();

			m_pSnmpWrapper = NULL;
		}

		CMonDevice &operator=(const CMonDevice &ob)
		{
			if (this == &ob)
			{
				return *this;
			}

			m_sHostName = ob.m_sHostName;
			m_sDevName = ob.m_sDevName;
			m_sCommunity = ob.m_sCommunity;
			m_mapOid = ob.m_mapOid;
			m_bActiveFlag = ob.m_bActiveFlag;
			CSnmpWrapper::parse_oid(
					(const char *)SNMPSYSNAMEOID,
					(oid *)m_sSysNameOoid,
					(size_t &)m_nSysNameOidLen);
			m_pListObjectAttr = ob.m_pListObjectAttr;
			m_pListWarningEvent = ob.m_pListWarningEvent;
			m_pListSyslogEvent = ob.m_pListSyslogEvent;
			m_pListUpdateConfig = ob.m_pListUpdateConfig;
			m_pDate = ob.m_pDate;
			m_pTime = ob.m_pTime;

			if (m_pSnmpWrapper)
			{
				delete m_pSnmpWrapper;
			}

			if (NULL == ob.m_pSnmpWrapper)
			{
				m_pSnmpWrapper = NULL;
			}
			else
			{
				m_pSnmpWrapper = new CSnmpWrapper(
						ob.m_pSnmpWrapper->get_community(),
						ob.m_pSnmpWrapper->get_peer_name());
			}

			return *this;
		}

		///增加Oid监控请求ID函数
			///@param	pOidName	Oid名称
			///@return	true增加成功，false增加失败
		bool addOid(
		const char	*pOidName,
		const char	*pAttrType,
		const char	*pSeps,
		int type,
		const char	*pAttendValue,
		int oidmeans = 0)
		{
			m_mapOidAttr[pOidName] = pAttrType;

			CVarOid tmpOid(pOidName, pSeps, type, pAttendValue);
			tmpOid.setoidmeans( oidmeans );
			if (tmpOid.snmpParseOid())
			{
				m_mapOid[pOidName] = tmpOid;
			}
			else
			{
				return false;
			}

			return true;
		}

		///打开snmp连接并发送第一个请求函数
		bool openSnmpSession(int nNow);

		///更新主机名函数
		void updateHostName(const char *buffer);

		///设置保存数据的队列地址
		void setListsAddr(
		TemplateMutexCatch<CFTDRtnObjectAttrField>	*pListObjectAttr,
		TemplateMutexCatch<CFTDRtnWarningEventField> *pListWarningEvent,
		TemplateMutexCatch<CFTDRtnSyslogEventField> *pListSyslogEvent,
		TemplateMutexCatch<CFTDRtnUpdateSysConfigField> *
			pListUpdateConfig,
		TemplateMutexCatch<CFTDRtnObjectAttrField>	*pListConObjectAttr)
		{
			m_pListObjectAttr = pListObjectAttr;
			m_pListWarningEvent = pListWarningEvent;
			m_pListSyslogEvent = pListSyslogEvent;
			m_pListUpdateConfig = pListUpdateConfig;
			m_pListConObjectAttr = pListConObjectAttr;
		}

		///设置设备所属的中心名称
		void setCenterName(const char *pCenterName)
		{
			m_sCenterName = pCenterName;
		}

		///设置设备所属的子网名称
		void setSubNetName(const char *pSubNetName)
		{
			m_sSubNetName = pSubNetName;
		}

		///设置日期时间指针
		void setDateTime(char *pDate, char *pTime)
		{
			m_pDate = pDate;
			m_pTime = pTime;
		}

		///设置设备的objectID
		void setObjectID(const char *pObjID)
		{
			m_sObjID = pObjID;
		}

		void process_snmp_result(void);
		void process_snmp_result_new(void);
		double	analyze_mem_result(const char *oidname, DATAMAP *dp);
		double computerAttrPerS(string oidvalue, CFTDRtnObjectAttrField &fieldInfo);
		bool set_next_oid(void);

	/* */
	public:
		///设备所属中心名称
		string	m_sCenterName;

		///设备所属中心的子网名称，如生产、办公、OA等
		string	m_sSubNetName;

		///设备名称
		string	m_sHostName;

		///设备ip地址
		string	m_sDevName;

		///通信关键字
		string	m_sCommunity;

		///活跃标记
		bool m_bActiveFlag;

		string	m_sObjID;

		///snmp会话指针
		CSnmpWrapper *m_pSnmpWrapper;

		///保存一个设备的OID对应的Attr信息
			///@key	OidName名称，如1.3.6.1.2.1.1.1.0
			///@value	保持该OidName对应的属性名称，如sysDescr
		map<string, string> m_mapOidAttr;

		///保存一个设备需要获取的所有oid信息
			///@key		OidName名称，如1.3.6.1.2.1.1.1.0
			///@value	该设备的所有OID
		map<string, CVarOid> m_mapOid;

		///保存已经发送到的迭代器位置
		map<string, CVarOid>::iterator	m_mapIt;

		///当前执行时间
		int m_nNow;

		///主机名ID分析之后的OID
		oid m_sSysNameOoid[MAX_OID_LEN];

		///主机名ID分析之后的ID长度
		u_int m_nSysNameOidLen;

	/* */
	private:
		///对象指标值队列
		TemplateMutexCatch<CFTDRtnObjectAttrField>	*m_pListConObjectAttr;

		///对象指标值队列
		TemplateMutexCatch<CFTDRtnObjectAttrField>	*m_pListObjectAttr;

		///告警事件队列
		TemplateMutexCatch<CFTDRtnWarningEventField> *m_pListWarningEvent;

		///日志事件队列
		TemplateMutexCatch<CFTDRtnSyslogEventField> *m_pListSyslogEvent;

		///配置变更队列
		TemplateMutexCatch<CFTDRtnUpdateSysConfigField> *m_pListUpdateConfig;

		///指向一组监控设备的采样日期
		char *m_pDate;

		///指向一组监控设备的采样时间
		char *m_pTime;

		//某些oid指标对应的最近的Field对象
		map<string, CFTDRtnObjectAttrField> m_mapLastField;

	/* */
	public:
		///是否已产生过日志事件或告警事件标记
			///@key	指标类型
			///@value	该指标在读取值的过程中出错产生日志事件或告警事件标记,1日志事件,2告警事件,0未产生
		map<string, int> m_mapEventFlag;

	private:
		struct DeviceCompAttr	// 保存设备的某一个复合指标信息
		{
			/* some define */
			static const double NULLValue;	// 表示错误值或空值，DBL_MAX(max double)


			DeviceCompAttr() :m_CurrTime(0), m_LastTime(0){}
			struct CompAttrVariate		// 复合指标中的一个条目：变量或操作符
			{
				CompAttrVariate();	// 使用ErrorValue表示初始空值
				bool setVariate(string _varName);	// 设置该变量

				CompAttrVarType m_type;	// 该条目类型，是变量还是操作符
				string m_VarName;	// 如果是变量，初始化为OID的ENAME，后续会被更新为对应的OID字符串；如果是操作符，该字段为具体的操作符
				double m_CurrValue;	// 变量值，统一使用double
				double m_LastValue;	// 前一值，用于公式中出现的LASTVALUE
			};

			/* Members */
			vector<CompAttrVariate> m_CompAttrFormular;	// 具体公式

			time_t m_CurrTime;	// 本次更新的时间，用于计算时间差，使用本地系统时间
			time_t m_LastTime;	// 前一次更新的时间，用于计算时间差，使用本地系统时间
			
			/* Functions */
			double Calculate();	// 根据变量值和公式，得到计算结果，若计算时发生错误，返回"ErrorValue"
		private:
			static char OperatorsPriority(char currOper, char lastOper);	// 返回两个操作符的优先级
			static double OperatorCalculate(double _v1, char _oper, double _v2);	// 计算：变量1、操作符、变量2
		};

		typedef vector<DeviceCompAttr::CompAttrVariate> AttrFormular;
		// 复合指标集合，初始化自snmpmanager.xml文件，所有CMonDevice共享
		// key: 指标名称，该名称是xml文件中定义的名称，可能与后台返回的指标名称不一样
		// value: 计算该指标使用的公式信息，不同厂商可能使用不同的公式，因此为multimap
		static multimap<string, AttrFormular > m_gCompoundAttrFormulars;

	public:
		// 初始化复合指标定义
		static void InitCompoundAttrs(char* _fileName);

		// 更新复合指标定义中所需的OID信息
		static void UpdateCompoundAttrOid(const char* _oidEName, const char* _oidString);
	
	private:
		// 保存当前正在计算的复合指标，计算完成后重置数据，供下次计算使用
		// key: 指标名称，必须与数据库中的指标名称一致
		// value: 计算该指标信息
		map<string, DeviceCompAttr> m_CompoundAttrs;

		// 增加一个复合指标信息，若该设备不支持此类复合指标，则返回false
		// _Data中会包含叶子OID节点的名称，如memoryPoolUsed，因此检查是需要该信息
		// 成功返回指向该复制指标信息的迭代器，否则返回end()
		map<string, DeviceCompAttr>::iterator AddCompoundAttr(const char* _AttrName, DATAMAP &_Data);

		// 更新复合指标中的数据
		// 若该复合指标中的所有变量值均被赋值，则返回ture
		// 否则返回false（值不足或是发生错误）
		// _iterCompAttrInfo：指向待更新的复合指标信息
		bool UpdataCompoundValues(map<string, DeviceCompAttr>::iterator _iterCompAttrInfo, 
									DATAMAP &_Data, time_t _NowTime_t);

		// 计算复合指标
		// _AttrName: 指标名称
		// _OidName: OID名称
		// _Data: 通过SNMP获取的数据集
		// 返回值：计算正确则返回实际的数据，double类型；中间过程发生错误，则返回max double
		double CalculateCompoundAttr(const char* _AttrName, DATAMAP &_Data, const char* _MonDate, const char* _MonTime);

};

///一组监控设备异步读取信息类
class CAsyncGetDevices
{
	/* */
	public:

		///析构函数
		~CAsyncGetDevices(void)
		{
			SOCK_CLEANUP;
		}

		///构造函数
			///@param	pMibsPath	mib库文件目录名
		CAsyncGetDevices(const int nThreadId, const char *pMibsPath)
		{
			m_nThreadId = nThreadId;
			m_pMibsPath = (char *)pMibsPath;
			initSnmp();
		}

		///增加被管设备OID函数
			///@param	pDevIp	被管设备的IP地址
			///@param	pCommunity	snmp通信关键字
			///@param	pOidName	Oid名称
			///@param	pAttrType	Oid对应的属性名称
			///@param	pSeps	采样频率,如 "08:00:00-12:00:00.60,12:00:00-23:00:00.5"
			///@return	true增加并解析Oid成功，false表示解析失败，不会把oid增加到oid请求表
		bool addMonDevice(
		const char	*pHostName,
		const char	*pDevIp,
		const char	*pCommunity,
		const char	*subnetName,
		const char	*centerName,
		const char	*pOidName,
		const char	*pAttrType,
		const char	*pSeps,
		const char	*pObjID,
		const char	*pAttendValue)
		{
			if (pHostName == NULL || pDevIp == NULL || pCommunity == NULL)
			{
				return false;
			}

			m_mapDevicelock.Lock();

			//printf("get the m_mapDevicelock lock in function [%s].\n",__FUNCTION__ );
			map<string, CMonDevice>::iterator mapDevIt = m_mapDevices.find(
					pDevIp);
			if (mapDevIt == m_mapDevices.end())
			{
				m_mapDevices[pDevIp] = CMonDevice(
						pHostName,
						pDevIp,
						pCommunity);
				mapDevIt = m_mapDevices.find(pDevIp);
				mapDevIt->second.setListsAddr(
						&m_listObjectAttr,
						&m_listWarningEvent,
						&m_listSyslogEvent,
						&m_listUpdateConfig,
						&m_listConObjectAttr);
				mapDevIt->second.setSubNetName(subnetName);
				mapDevIt->second.setCenterName(centerName);
				mapDevIt->second.setObjectID(pObjID);
				mapDevIt->second.setDateTime(m_date, m_time);
			}

			mapDevIt->second.addOid(
					pOidName,
					pAttrType,
					pSeps,
					0,
					pAttendValue);
			m_mapDevicelock.UnLock();

			//printf("free the m_mapDevicelock lock in function [%s].\n",__FUNCTION__ );
			return true;
		}

		///增加被管设备OID函数
			///@param	phost		被管设备指针
			///@param	pNetName	设备所在网络名
			///@param	pCenterName	设备所在中心民
			///@param   pOidName    oid取值
			///@param	pAttrType	Oid对应的属性名称
			///@param	policy		采样策略对象
			///@param	pAttendValue 附加字段
			///@return	true增加并解析Oid成功，false表示解析失败，不会把oid增加到oid请求表
		bool addMonDevice(
		const CFTDSysNetDeviceField *phost,
		const char	*pOidName,
		const char	*pAttrType,
		const char	*pPolicySeps,
		int taskType,
		const char	*pAttendValue,
		int oidmeans)
		{
			if (phost == NULL)
			{
				return false;
			}

			m_mapDevicelock.Lock();

			//printf("get the m_mapDevicelock lock in function [%s].\n",__FUNCTION__ );
			map<string, CMonDevice>::iterator mapDevIt = m_mapDevices.find(
					phost->IPADDR.getValue());
			if (mapDevIt == m_mapDevices.end())
			{
				//增加监控设备对象
				m_mapDevices[phost->IPADDR.getValue()] = CMonDevice(
						phost->NAME.getValue(),
						phost->IPADDR.getValue(),
						phost->RCOMMUNITY.getValue());
				mapDevIt = m_mapDevices.find(phost->IPADDR.getValue());
				mapDevIt->second.setListsAddr(
						&m_listObjectAttr,
						&m_listWarningEvent,
						&m_listSyslogEvent,
						&m_listUpdateConfig,
						&m_listConObjectAttr);
				mapDevIt->second.setObjectID(phost->ObjectID.getValue());
				mapDevIt->second.setDateTime(m_date, m_time);
			}

			//编辑监控设备对象的监控指标
			if (pPolicySeps != NULL)
			{
				std::map<string, CVarOid>::iterator it_var = mapDevIt->second.
					m_mapOid.find(pOidName);
				if (it_var != mapDevIt->second.m_mapOid.end())
				{
					//修改监控指标的采集频率
					it_var->second.changeTimepolicy(pPolicySeps);
				}
				else
				{
					//增加监控指标
					mapDevIt->second.addOid(
							pOidName,
							pAttrType,
							pPolicySeps,
							taskType,
							pAttendValue,
							oidmeans);
				}
			}
			else
			{
				//增加特殊的（第一次执行，往后每天执行一次）监控指标
				mapDevIt->second.addOid(
						pOidName,
						pAttrType,
						NULL,
						0,
						pAttendValue,
						oidmeans);
			}

			m_mapDevicelock.UnLock();

			//printf("free the m_mapDevicelock lock in function [%s].\n",__FUNCTION__ );
			return true;
		}

		bool addMonDeviceNew(
		const char	*pDevIp,
		const char	*pCommunity,
		const char	*pObjectID,
		const char	*pOidName,
		const char	*pAttrType,
		const char	*pPolicySeps,
		int taskType,
		const char *pAttendValue)
		{
			if (pObjectID == NULL || pDevIp == NULL || pCommunity == NULL)
			{
				printf(
					"add monitor device fail, ip=[%s] community=[%s] objectid=[%s].\n ",
					pDevIp,
					pCommunity,
					pObjectID);
				return false;
			}

			m_mapDevicelock.Lock();

			//printf("get the m_mapDevicelock lock in function [%s].\n",__FUNCTION__ );
			map<string, CMonDevice>::iterator mapDevIt = m_mapDevices.find(
					pDevIp);
			if (mapDevIt == m_mapDevices.end())
			{
				string name = pObjectID;
				name = name.substr(name.find_last_of('.') + 1);

				//name = string(pObjectID).find_last_of('.');
				//增加监控设备对象
				m_mapDevices[pDevIp] = CMonDevice(
						name.c_str(),
						pDevIp,
						pCommunity);
				mapDevIt = m_mapDevices.find(pDevIp);
				mapDevIt->second.setListsAddr(
						&m_listObjectAttr,
						&m_listWarningEvent,
						&m_listSyslogEvent,
						&m_listUpdateConfig,
						&m_listConObjectAttr);
				mapDevIt->second.setObjectID(pObjectID);
				mapDevIt->second.setDateTime(m_date, m_time);
			}

			//编辑监控设备对象的监控指标
			if (pPolicySeps != NULL)
			{
				std::map<string, CVarOid>::iterator it_var = mapDevIt->second.
					m_mapOid.find(pOidName);
				if (it_var != mapDevIt->second.m_mapOid.end())
				{
					//修改监控指标的采集频率
					it_var->second.changeTimepolicy(pPolicySeps);
				}
				else
				{
					//增加监控指标
					mapDevIt->second.addOid(
							pOidName,
							pAttrType,
							pPolicySeps,
							taskType,
							pAttendValue);
				}
			}
			else
			{
				//增加特殊的（第一次执行，往后每天执行一次）监控指标
				mapDevIt->second.addOid(
						pOidName,
						pAttrType,
						NULL,
						0,
						pAttendValue);
			}

			m_mapDevicelock.UnLock();

			//printf("free the m_mapDevicelock lock in function [%s].\n",__FUNCTION__ );
			return true;
		}

		///删除指定的被管设备
			///@param	pDevIp	被管设备的IP地址
		bool removeMonDeviceTask(const char *pDevIp, const char *pOidName)
		{
			bool res = false;
			m_mapDevicelock.Lock();

			//printf("get the m_mapDevicelock lock in function [%s].\n",__FUNCTION__ );
			map<string, CMonDevice>::iterator mapDevIt = m_mapDevices.find(
					pDevIp);
			if (mapDevIt != m_mapDevices.end())
			{
				if (mapDevIt->second.m_mapOid.find(
						pOidName) != mapDevIt->second.m_mapOid.end())
				{
					mapDevIt->second.m_mapOid[pOidName].updateExeState(
							UNWORK_STATUS); //varoid标志置为无效
				}

				res = true;
			}

			m_mapDevicelock.UnLock();

			//printf("free the m_mapDevicelock lock in function [%s].\n",__FUNCTION__ );
			return res;
		}

		///清除所有监控设备
		bool clearMonDevice(void)
		{
			m_mapDevicelock.Lock();
			printf(
				"get the m_mapDevicelock lock in function [%s].\n",
				__FUNCTION__);
			m_mapDevices.clear();
			m_mapDevicelock.UnLock();
			printf(
				"free the m_mapDevicelock lock in function [%s].\n",
				__FUNCTION__);
			return true;
		}

		///初始化snmp库函数
		void initSnmp(void);

		///启动对所有被管设备发送第一次snmpget请求
		bool startAllHost(int nNow);

		///异步发送snmpget、接收应答处理函数
		bool run(int nNow);

		//////generate the attr & event data for test
		void genDataField(list<pair<int, string> > &data);
		void genOneDateField(pair<int, string> &data);

	/* */
	public:
		///保存所有被管设备
			///@key	设备IP地址
			///@value	被管设备OID等信息
		map<string, CMonDevice> m_mapDevices;

		//操作设备map读写锁
		CMutex m_mapDevicelock;

		///对象指标值队列,发给配置服务的采集信息
		TemplateMutexCatch<CFTDRtnObjectAttrField> m_listConObjectAttr;

		///对象指标值队列
		TemplateMutexCatch<CFTDRtnObjectAttrField> m_listObjectAttr;

		///告警事件队列
		TemplateMutexCatch<CFTDRtnWarningEventField> m_listWarningEvent;

		///日志事件队列
		TemplateMutexCatch<CFTDRtnSyslogEventField> m_listSyslogEvent;

		///配置变更队列
		TemplateMutexCatch<CFTDRtnUpdateSysConfigField> m_listUpdateConfig;

		///当前日期
		char m_date[10];
		char m_time[10];

	///当前时间
	protected:
	/* */
	private:
		// 所属线程ID编号
		int m_nThreadId;

		///mib库文件目录名指针
		char *m_pMibsPath;
};
#endif //END REF_CASUNCGETDEVICES_H
