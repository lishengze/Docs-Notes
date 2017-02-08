/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	EventConfigConnector.h
///@brief	定义了和配置服务器通讯的类
///@history
///20110817	魏诚		创建该文件
#ifndef REF_EVENTCONFIGCONNECTOR_H
#define REF_EVENTCONFIGCONNECTOR_H

#include "public.h"
#include "CachedFlow.h"
#include "CachedFileFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "CDate.h"
#include "systools.h"

/////////////////////////////////////////////////////////////////////////
///CObjectAttrKey定义了ObjectID和AttrID作为map关键字的类
///@author	周建军
///@version	1.0,20080710
/////////////////////////////////////////////////////////////////////////
class CObjectAttrKey
{
	/* */
	public:

		///构造函数
		
		CObjectAttrKey(void)
		{
			m_nObjectID = "";
			m_nAttrID = "";
			m_sProcessFlag = "";
			m_sEventDes = "";
		}

		///构造函数
			///@param	m_nObjectID	对象ID
			///@param	m_nAttrID	指标ID
		CObjectAttrKey(string nObjectID, string nAttrID, string sProcessFlag = "", string sEventDes = "")
		{
			m_nObjectID = nObjectID;
			m_nAttrID = nAttrID;
			m_sProcessFlag = sProcessFlag;
			m_sEventDes = sEventDes;
		}

		///拷贝构造函数
		
		CObjectAttrKey(const CObjectAttrKey &ob)
		{
			m_nObjectID = ob.m_nObjectID;
			m_nAttrID = ob.m_nAttrID;
			m_sProcessFlag = ob.m_sProcessFlag;
			m_sEventDes = ob.m_sEventDes;
		}

		///重载=运算符
		
		void operator=(const CObjectAttrKey &ob)
		{
			m_nObjectID = ob.m_nObjectID;
			m_nAttrID = ob.m_nAttrID;
			m_sProcessFlag = ob.m_sProcessFlag;
			m_sEventDes = ob.m_sEventDes;
		}

		///重载>运算符
		
		friend bool operator>(
		const CObjectAttrKey &ob1,
		const CObjectAttrKey &ob2)
		{
			if (ob1.m_nObjectID > ob2.m_nObjectID)
			{
				return true;
			}
			else if (ob1.m_nObjectID == ob2.m_nObjectID)
			{
				if (ob1.m_nAttrID > ob2.m_nAttrID)
				{
					return true;
				}
			}

			return false;
		}

		///重载>运算符
		
		friend bool operator < (const CObjectAttrKey &ob1, const CObjectAttrKey &ob2)
		{
			if (ob1.m_nObjectID < ob2.m_nObjectID)
			{
				return true;
			}
			else if (ob1.m_nObjectID == ob2.m_nObjectID)
			{
				if (ob1.m_nAttrID < ob2.m_nAttrID)
				{
					return true;
				}
			}

			return false;
		}

		///重载==运算符
		
		friend bool operator==(
		const CObjectAttrKey &ob1,
		const CObjectAttrKey &ob2)
		{
			if (ob1.m_nObjectID == ob2.m_nObjectID
			&&	ob1.m_nAttrID == ob2.m_nAttrID)
			{
				return true;
			}

			return false;
		}

	/* */
	public:
		///对象ID
		string	m_nObjectID;

		///指标ID
		string	m_nAttrID;

		///处理标记
		string m_sProcessFlag;

		///处理描述
		string m_sEventDes;
};

class CObjectAttrValue
{
	/* */
	public:

		///构造函数
		CObjectAttrValue(void)
		{
			m_nTime = 0;
			m_nValue = 0;
		}

		///构造函数
			///@param	m_nObjectID	对象ID
			///@param	m_nAttrID	指标ID
		CObjectAttrValue(int nTime, double nValue)
		{
			m_nTime = nTime;
			m_nValue = nValue;
		}

		///拷贝构造函数
		CObjectAttrValue(const CObjectAttrValue &ob)
		{
			m_nTime = ob.m_nTime;
			m_nValue = ob.m_nValue;
		}

		///重载=运算符
		void operator=(const CObjectAttrValue &ob)
		{
			m_nTime = ob.m_nTime;
			m_nValue = ob.m_nValue;
		}

	/* */
	public:
		///对象ID
		int m_nTime;

		///指标ID
		double	m_nValue;
};

//网络大区 、子网、子网ip的容器
//@int key=id，对应实例的ID索引号,@CFTDSysNetAreaField value=实例
typedef std::map<int, CFTDSysNetAreaField>	NET_AREA_MAP;
typedef NET_AREA_MAP::iterator	NET_AREA_MAP_ITERATOR;

//@int key=id，对应实例的ID索引号,@CFTDSysNetSubAreaField value=实例
typedef std::map<int, CFTDSysNetSubAreaField> NET_SUB_AREA_MAP;
typedef NET_SUB_AREA_MAP::iterator	NET_SUB_AREA_MAP_ITERATOR;

//@int key=id，对应实例的ID索引号,@CFTDSysNetSubAreaIPField value=实例
typedef std::map<int, CFTDSysNetSubAreaIPField> NET_SUB_AREA_IP_MAP;
typedef NET_SUB_AREA_IP_MAP::iterator NET_SUB_AREA_IP_MAP_ITERATOR;

//监控对象类别容器@string  key="小写的ename",CFTDSysNetMonitorTypeField value=实例
typedef std::map<string, CFTDSysNetMonitorTypeField> MONITOR_TYPE_MAP;
typedef MONITOR_TYPE_MAP::iterator	MONITOR_TYPE_MAP_ITERATOR;

//网络设备通信关键字容器 @string key=ip地址,@string value=关键字
typedef std::map<std::string, std::string>	COMMUNITY_MAP;
typedef COMMUNITY_MAP::iterator COMMUNITY_MAP_ITERATOR;

//设备厂商容器 @string key=小写的ename, @CFTDSysNetManufactoryField value=实例
typedef std::map<string, CFTDSysNetManufactoryField> DEV_MANUFACTORY_MAP;
typedef DEV_MANUFACTORY_MAP::iterator DEV_MANUFACTORY_MAP_ITERATOR;

//设备类别容器 @string key=小写的ename, @CFTDSysNetDeviceCategoryField value=实例
typedef std::map<string, CFTDSysNetDeviceCategoryField> DEV_TYPE_MAP;
typedef DEV_TYPE_MAP::iterator	DEV_TYPE_MAP_ITERATOR;

//设备型号容器 @int key=id, @CFTDSysNetDeviceTypeField value=实例
typedef std::map<int, CFTDSysNetDeviceTypeField> DEV_SERIAL_MAP;
typedef DEV_SERIAL_MAP::iterator DEV_SERIAL_MAP_ITERATOR;

//key中使用的连接符号
#define CONSYM	"@#$";

//配置中心下发的厂商oid结构，及相应的容器
//@string 如果serialname为空，key=OidEname+CONSYM+ManuEname,
//		  否则key=OidEname+CONSYM+ManuEname+CONSYM+SerialEname
//@CFTDSysNetOIDField value=实例
typedef std::map<string, CFTDSysNetOIDField> CON_OID_CONTAIN_MAP;
typedef CON_OID_CONTAIN_MAP::iterator CON_OID_CONTAIN_MAP_ITERATOR;

//网络设备容器 @int key=id,设备ID索引号, @CFTDSysNetDeviceField value=CFTDSysNetDeviceField实例
typedef std::map<int, CFTDSysNetDeviceField> NET_DEVICE_MAP;
typedef NET_DEVICE_MAP::iterator NET_DEVICE_MAP_ITERATOR;

// 网络设备object id容器 @string key=objectid,设备的objectid,@int value=id 设备的编号
typedef std::map<string, int> NET_DEV_OBJID_MAP;
typedef NET_DEV_OBJID_MAP::iterator NET_DEV_OBJID_MAP_ITERATOR;

//网络接口容器
//@int key = id,接口对应的ID索引号, @CFTDSysNetInterfaceField value=CFTDSysNetInterfaceField实例
typedef std::map<int, CFTDSysNetInterfaceField> NET_INTERFACE_MAP;
typedef NET_INTERFACE_MAP::iterator NET_INTERFACE_MAP_ITERATOR;

//设备模块容器
//@int key = int,模块id, @CFTDSysNetInterfaceField value=CFTDSysNetInterfaceField实例
typedef std::map<int, CFTDSysNetModuleField> NET_MODULE_MAP;
typedef NET_MODULE_MAP::iterator NET_MODULE_MAP_ITERATOR;

//时间策略结构及其容器 @int key=id,时间策略的ID索引号, @CFTDSysNetTimePolicyField value=CFTDSysNetTimePolicyField实例
typedef std::map<int, CFTDSysNetTimePolicyField> TIME_POLICY_MAP;
typedef TIME_POLICY_MAP::iterator TIME_POLICY_MAP_ITERATOR;

//监控任务结构及其容器  @long key=id，监控任务的ID索引号, @MONITOR_TASK value=MONITOR_TASK实例

//其中id区分：配置中心直接下发（id以前缀"10"开头）；巡检任务指派（id以前缀"11"开头）两类。
struct MONITOR_TASK
{
	int policyID;
	int rtnType;
	string objectid;
	string attritype;
	bool is_dispatch;
};
typedef MONITOR_TASK *PMONITOR_TASK;
typedef std::map<long, MONITOR_TASK> MONITOR_TASK_MAP;
typedef MONITOR_TASK_MAP::iterator	MONITOR_TASK_MAP_ITERATOR;

//巡检任务容器 @int key = id, @CFTDSysNetMonitorTaskInfoField value实例
typedef std::map<int, CFTDSysNetMonitorTaskInfoField> LOOP_ITEM_MAP;
typedef LOOP_ITEM_MAP::iterator LOOP_ITEM_MAP_ITERATOR;

//巡检指令容器 key = id
typedef std::map<int, CFTDSysNetMonitorCommandTypeField> COMMAND_MAP;
typedef COMMAND_MAP::iterator COMMAND_MAP_ITERATOR;

//巡检动作容器 key = id
typedef std::map<int, CFTDSysNetMonitorActionGroupField> ACTION_GROUP_MAP;
typedef ACTION_GROUP_MAP::iterator	ACTION_GROUP_MAP_ITERATOR;

//巡检设备对象组容器 key = id
typedef std::map<int, CFTDSysNetMonitorDeviceGroupField> DEVICE_GROUP_MAP;
typedef DEVICE_GROUP_MAP::iterator	DEVICE_GROUP_MAP_ITERATOR;

//监控指标容器，key = manu;;;monitor_type
typedef std::map<string, map<string, int> > MONITOR_ATTR_MAP;
typedef MONITOR_ATTR_MAP::iterator	MONITOR_ATTR_MAP_ITERATOR;

//告警表达式容器
typedef std::map<int, CFTDRspQryNetEventExprField>	WARNING_EXPRESSION;
typedef WARNING_EXPRESSION::iterator WARNING_EXPRESSION_ITERATOR;

//表达式关联的设备列表,first_key:表达式id, second_key:任务objectid
typedef map<int, map<string, int> > EXPR_DEVICE_LIST;
typedef EXPR_DEVICE_LIST::iterator EXPR_DEVICE_LIST_ITERATOR;

typedef list<int> LIST_ID;
typedef LIST_ID::iterator LIST_ID_IT;

//@int key=id，设备分组ID标识,@list <int> value=设备对象ID列表
typedef std::map<int, LIST_ID> MAP_DEVICEGROUPLIST;
typedef MAP_DEVICEGROUPLIST::iterator MAP_DEVICEGROUPLIST_IT;

//@int key=id，对应实例的ID索引号,@CFTDSysNetDeviceField value=实例
typedef std::map<int, CFTDSysNetDeviceField> MAP_DEVICE;
typedef MAP_DEVICE::iterator MAP_DEVICE_IT;

//key:factoryid_objectid_cmd, value:paramlist(key:seq, value:paramvalue)
//巡检命令返回结果的正则过滤规则串
//相同任务不同设备可单独定制规则
typedef std::map<string, vector<map<int, string> > > MAP_TASK_REGULAR_PARAM;
typedef MAP_TASK_REGULAR_PARAM::iterator MAP_TASK_REGULAR_PARAM_IT;

//key:ip_port
//会员链路信息表
typedef std::map<string, CFTDSysNetPartyLinkInfoField> MAP_PARTYLINK_INFO;
typedef MAP_PARTYLINK_INFO::iterator MAP_PARTYLINK_INFO_IT;

//基线容器 @int key=基线ID索引号
class BaseLineInfo
{
	/* */
	public:
		string name;	//基线名
		string data;	//基线内容
		int flag;		//完整标记符，0表示还未收完，1表示已收完
};

typedef std::map<int, BaseLineInfo> NET_BASELINE_MAP;
typedef NET_BASELINE_MAP::iterator	NET_BASELINE_MAP_ITERATOR;

//指令信息类
class CInstructionInfo
{
	/* */
	public:
		string defaultregular;		//指令的默认阀值规则
		vector<string> attrlist;	//指令对应的指标列表
		vector<map<int, string> > defaultparams;	//规则默认的参数列表
};

//key:cmdalias_devicetype
//相同命令不同厂商对应的指标可以不同
typedef std::map<string, CInstructionInfo>	MAP_INSTR_INFO;
typedef MAP_INSTR_INFO::iterator MAP_INSTRINFO_IT;

class CConfigConnector :
	public CSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///构造函数	
			///@param	pReactor	CReactor对象指针
		CConfigConnector(CReactor *pReactor);

		///新建会话时调用的处理函数
			///@param	pChannel	会话所属的通道地址
			///@param	bIsListener	会话是否是监听服务器类型
			///@return	返回创建的新会话
		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		///连接成功时调用的处理函数
			///@param	pSession	连接成功的会话指针
		virtual void OnSessionConnected(CSession *pSession);

	/* */
	protected:
		/**会话连接断开时的处理函数
	* @param	pSession	断开的连接会话指针
	* @param	nReasion	断开的原因
	*/
		virtual void OnSessionDisconnected(CSession *pSession, int nReason);

	/* */
	private:
		///请求应答包处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
			///@return	返回数据包的处理结果
		virtual int HandlePackage(
						CFTDCPackage *pFTDCPackage,
						CFTDCSession *pSession);

		///用户登录应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		///响应网络分区信息应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspNetAreaTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnNetAreaTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应子网络分区应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针	
		void OnRspNetSubAreaTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnNetSubAreaTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应子网络分区网段地址应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspNetSubAreaIPTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnNetSubAreaIPTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应设备生产商应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspDevManuTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnDevManuTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应设备类别应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspDevTypeTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnDevTypeTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应设备型号应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspDevSerialTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnDevSerialTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应设备通信关键字comm应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspNetCommTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnNetCommTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应设备的mib应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspMIBOIDTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnMIBOIDTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应通用的mib应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspGenMIBOIDTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnGenMIBOIDTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应网络设备应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspNetDeviceTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnNetDeviceTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应设备变更应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspChgNetDeviceTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnChgNetDeviceTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应网络设备应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspNetInterfaceTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnNetIntefaceTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应模块信息应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspNetModuleTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnNetModuleTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应时间策略处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspTimePolicyTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnTimePolicyTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		//监控任务处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspMonTaskTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnMonTaskTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应设备通信关键字comm应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspMonitorTypeTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnMonitorTypeTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应设备对象组明细应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspQryNetMonitorTaskObjectSetTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnNetMonitorTaskObjectSetTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应监控指标应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspMonitorAttrTypeTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnMonitorAttrTypeTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应告警表达式应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspNetEventExprTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnNetEventExprTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应巡检任务应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspLoopItemTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnLoopItemTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应巡检命令的结果过滤规则处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspDeviceTaskTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnDeviceTaskTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应巡检命令的列表处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspTaskCmdAttrListTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnTaskCmdAttrListTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应设备基线应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspBaseLineTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnBaseLineTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应会员链路信息应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspPartyLinkInfoTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnPartyLinkInfoTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///生成指标对应的设备id列表
		void PrepareExprData(void);

		///添加表达式对应的设备列表
		void AddExprDeviceList(CFTDSysNetMonitorTaskInfoField &field);

		///删除表达式对应的设备列表
		void DelExprDeviceList(CFTDSysNetMonitorTaskInfoField &field);

		///	///响应告警事件应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRtnWarningEventTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnReqQryWarningEventUpdate(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnReqQryWarningEventActiveChange(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnSyslogEventTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		//客户端控制短信开关
		void OnReqQryNetRoomTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void AddWarningEvent(CFTDRtnWarningEventField &warningevent)
		{
			m_listWarningEvent.add(warningevent);
		}

		void AddSyslogEvent(CFTDRtnSyslogEventField &syslogevent)
		{
			m_listSyslogEvent.add(syslogevent);
		}

		void AddWarningEventActiveChange(
		CFTDRtnWarningActiveChangeField &warningeventac)
		{
			m_listWarningEventActiveChange.add(warningeventac);
		}

		void AddNetMonitorObjectTree(CFTDRtnNetAreaField &objecttree)
		{
			m_listNetMonitorObjectTree.add(objecttree);
		}

		void AddRtnNetRoom(CFTDRtnNetRoomField &netroom)
		{
			m_listRtnNetRoom.add(netroom);
		}

		void AddPartyLinkStatusInfo(
		CFTDRtnNetPartyLinkStatusInfoField	&statusinfo)
		{
			m_listPartyLinkStatus.add(statusinfo);
		}

		//分析指令指标结果
		void ParseDeviceTaskResult(
				CFTDSysNetMonitorDeviceTaskField &info,
				string	&result);

	/* */
	public:
		//根据指定的分隔符将字符串拆分成多个单元
		static void splitStringBySeprator(
						string ori,
						string splitstr,
						vector<string> &result);

	/* */
	public:
		bool GetWarningEvent(CFTDRtnWarningEventField &warningevent)
		{
			return m_listWarningEvent.get(warningevent);
		}

		bool GetSyslogEvent(CFTDRtnSyslogEventField &syslogevent)
		{
			return m_listSyslogEvent.get(syslogevent);
		}

		bool GetWarningEventActiveChange(
		CFTDRtnWarningActiveChangeField &warningeventac)
		{
			return m_listWarningEventActiveChange.get(warningeventac);
		}

		bool GetPartyLinkStatusInfo(
		CFTDRtnNetPartyLinkStatusInfoField	&statusinfo)
		{
			return m_listPartyLinkStatus.get(statusinfo);
		}

		bool GetNetMonitorObjectTree(CFTDRtnNetAreaField &objecttree)
		{
			return m_listNetMonitorObjectTree.get(objecttree);
		}

		bool GetRtnNetRoom(CFTDRtnNetRoomField &netroom)
		{
			return m_listRtnNetRoom.get(netroom);
		}

		MAP_TASK_REGULAR_PARAM GetTaskRegularParamList(void)
		{
			return map_TaskRegularParams;
		}

		MAP_INSTR_INFO GetTaskInstrInfo(void)
		{
			return map_InstrInfo;
		}

		int GetDeviceManufacoryIdAndIP(
				string objectid,
				int &manuid,
				string &deviceip,
				string &deviceserial);
		CFTDCSession *GetSession(void)
		{
			return m_pSession;
		}

		void GetDeviceName(string objectid, string &devname);

		int test_task(void);

		NET_DEVICE_MAP &GetDeviceMap(void)
		{
			return m_devs;
		}

		NET_BASELINE_MAP &GetBaseLineMap(void)
		{
			return m_baselines;
		}

		//根据告警事件提取会员链路名
		void GetPartyLinkMemberName(
				CFTDRtnWarningEventField &event,
				string	&membername);

	/* */
	private:
		///发送数据包使用的缓冲区
		CFTDCPackage m_pkgSend;

		//配置类信息
		NET_AREA_MAP m_sysNets;
		NET_SUB_AREA_MAP m_sysNetSubs;
		NET_SUB_AREA_IP_MAP m_sysNetSubIPs;

		//CGetDeviceInfoThread *m_pinfoThread;
		//监控对象类别
		MONITOR_TYPE_MAP m_montypes;

		//设备厂商信息，如cisco F5等
		DEV_MANUFACTORY_MAP m_devmanus;

		//设备类型信息，如路由器、交换机等
		DEV_TYPE_MAP m_devtypes;

		//设备型号信息，如cisco3600等
		DEV_SERIAL_MAP m_devserials;

		//厂商oid信息
		CON_OID_CONTAIN_MAP m_oids;

		//网络设备信息<id,netdev>
		NET_DEVICE_MAP m_devs;

		//设备ip信息
		NET_DEV_OBJID_MAP m_dev_objids;

		//接口信息
		NET_INTERFACE_MAP m_ifs;

		//模块信息
		NET_MODULE_MAP m_mods;

		//时间策略信息
		TIME_POLICY_MAP m_tpolicys;

		//监控任务
		MONITOR_TASK_MAP m_montasks;

		//监控指标
		MONITOR_ATTR_MAP m_attrs;

		//告警表达式
		WARNING_EXPRESSION m_warnexprs;

		//基线信息
		NET_BASELINE_MAP m_baselines;

		CFTDCSession *m_pSession;

		///对FIBCONFSERVER连接成功的标志位
		bool m_Flag;

		///发送给front的告警事件队列
		TemplateMutexCatch<CFTDRtnWarningEventField> m_listWarningEvent;

		///发送给front的syslog队列
		TemplateMutexCatch<CFTDRtnSyslogEventField> m_listSyslogEvent;

		///发送给front的告警事件activechange队列
		TemplateMutexCatch<CFTDRtnWarningActiveChangeField>
			m_listWarningEventActiveChange;

		///发送给front的告警开关事件netroom队列
		TemplateMutexCatch<CFTDRtnNetRoomField> m_listRtnNetRoom;

		///发送给front和query的链路状态统计队列
		TemplateMutexCatch<CFTDRtnNetPartyLinkStatusInfoField>
			m_listPartyLinkStatus;

		///发送给front的网络监控系统对象树(复用已有的Field)
		TemplateMutexCatch<CFTDRtnNetAreaField> m_listNetMonitorObjectTree;

		//未收全的设备任务表,用于分包情况下记录中间数据
		//key:task_id, value:devicetask list
		map<int, vector<CFTDSysNetMonitorDeviceTaskField> > m_mapDeviceTask;

	/* */
	public:
		//特殊comm信息 key=ip,value=comm;
		COMMUNITY_MAP m_comms;

		//巡检任务
		LOOP_ITEM_MAP m_loopitem;

		//巡检指令
		COMMAND_MAP m_commands;

		//巡检动作组
		ACTION_GROUP_MAP m_actions;

		//巡检设备组
		DEVICE_GROUP_MAP m_groupdev;

		//记录每次探测的req与网络探测的请求内容 key=reqid, value=CFTDReqQryNetDeviceDetectField实例
		map<DWORD, CFTDReqQryNetDeviceDetectField> m_detectids;

		///表达式关联的设备列表
		EXPR_DEVICE_LIST m_mExprTaskList;

		//指标对应的设备列表
		map<string, map<string, int> > m_attr_devs;

		///设备对象组明细
		MAP_DEVICEGROUPLIST map_DeviceGroupList;

		//任务命令结果分析规则库
		MAP_TASK_REGULAR_PARAM map_TaskRegularParams;

		//任务命令相关的指标列表
		MAP_INSTR_INFO map_InstrInfo;

		//会员链路信息
		MAP_PARTYLINK_INFO m_partylinkinfo;
};
#endif
