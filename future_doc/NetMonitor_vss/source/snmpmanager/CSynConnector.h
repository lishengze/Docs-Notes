/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	CGetDeviceInfo.h
///@brief	定义了CGetDeviceInfo使用的类
///@history
///20100920	周建军		创建该文件
#ifndef REF_CSYNCONNECTOR_H
#define REF_CSYNCONNECTOR_H

#include "public.h"
#include "CachedFlow.h"
#include "CachedFileFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "CDate.h"
#include "systools.h"
#include "CGetDeviceInfo.h"
#include "CAsyncGetThread.h"
#include "CTaskManager.h"

//内部宏定义
#ifndef uint32
#define uint32	unsigned long
#endif
#define PINGIPNUMPERTHREAD		20
#define MAX_DETECT_THREAD_NUM	255

#define CHK_RSP_PKG															 \
		(x, field, datamap)													 \
			CNamedFieldIterator	 itor = pFTDCPackage->GetNamedFieldIterator( \
					&(CFTDRspQry##x##Field::m_Describe));					 \
	while (!itor.IsEnd())													 \
	{																		 \
		itor.Retrieve(&field);												 \
		CFTDSys##x##Field fielddata;										 \
		CopySys##x##Entity(&fielddata, &field);								 \
		datamap[fielddata.ID.getValue()] = fielddata;						 \
		itor.Next();														 \
	}

#define SYNCONN_PKGSEND(Topic, field)								   \
	m_pkgSend.PreparePackage(										   \
			Topic,													   \
			FTDC_CHAIN_LAST,										   \
			FTD_VERSION);											   \
	if (m_pkgSend.Length() + sizeof(field) > FTDC_PACKAGE_MAX_SIZE)	   \
	{																   \
		m_pkgSend.SetChain(FTDC_CHAIN_CONTINUE);					   \
		if (m_pSession != NULL)										   \
		{															   \
			m_pSession->SendRequestPackage(&m_pkgSend);				   \
		}															   \
																\
		m_pkgSend.PreparePackage(Topic, FTDC_CHAIN_LAST, FTD_VERSION); \
	}																   \
																	\
	FTDC_ADD_FIELD(&m_pkgSend, &field);								   \
	if (m_pSession != NULL)											   \
	{																   \
		m_pSession->SendRequestPackage(&m_pkgSend);					   \
	}

#define RTN_QRY_DEL_FIELD_DATA(field, val, key, datamap, datamapiterator) \
	switch (field.OperationType.getValue())								  \
	{																	  \
		case 1:															  \
			break;														  \
		case 3:															  \
			if (field.ID.getValue() == -1)								  \
			{															  \
				datamap.clear();										  \
			}															  \
			else														  \
			{															  \
				datamapiterator = datamap.find(key);					  \
				if (datamapiterator != datamap.end())					  \
				{														  \
					datamap.erase(datamapiterator);						  \
				}														  \
			}															  \
															   \
			break;														  \
	}																	  \
																	   \
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

//设备通用oid容器 @string key=oid类型, @ value=oid对象
typedef std::map<string, SInfoOID>	GEN_OID_MAP;
typedef GEN_OID_MAP::iterator GEN_OID_MAP_ITERATOR;

//key中使用的连接符号
#define CONSYM	"@#$$";

//配置中心下发的厂商oid结构，及相应的容器
//@string 如果serialname为空，key=OidEname+CONSYM+ManuEname,
//		  否则key=OidEname+CONSYM+ManuEname+CONSYM+SerialEname
//@CFTDSysNetOIDField value=实例
typedef std::map<string, CFTDSysNetOIDField> CON_OID_CONTAIN_MAP;
typedef CON_OID_CONTAIN_MAP::iterator CON_OID_CONTAIN_MAP_ITERATOR;

//网络设备容器 @int key=id,设备ID索引号, @CFTDSysNetDeviceField value=CFTDSysNetDeviceField实例
typedef std::map<int, CFTDSysNetDeviceField> NET_DEVICE_MAP;
typedef NET_DEVICE_MAP::iterator NET_DEVICE_MAP_ITERATOR;

// 网络设备ip地址容器 @string key=ip,设备的ip地址,@int value=id 设备的编号
typedef std::map<string, int> NET_IP_MAP;
typedef NET_IP_MAP::iterator NET_IP_MAP_ITERATOR;

//网络接口容器
//@int key = id,接口对应的ID索引号(全局), @CFTDSysNetInterfaceField value=CFTDSysNetInterfaceField实例
//不以接口对应的objectID为key，主要是考虑到设备的ojbectID变化导致接口容器内容的变化
typedef std::map<int, CFTDSysNetInterfaceField> NET_INTERFACE_MAP;
typedef NET_INTERFACE_MAP::iterator NET_INTERFACE_MAP_ITERATOR;

//设备模块容器
//@int key = int,模块id, @CFTDSysNetInterfaceField value=CFTDSysNetInterfaceField实例
typedef std::map<int, CFTDSysNetModuleField> NET_MODULE_MAP;
typedef NET_MODULE_MAP::iterator NET_MODULE_MAP_ITERATOR;

//时间策略结构及其容器 @int key=id,时间策略的ID索引号, @CFTDSysNetTimePolicyField value=CFTDSysNetTimePolicyField实例
typedef std::map<int, CFTDSysNetTimePolicyField> TIME_POLICY_MAP;
typedef TIME_POLICY_MAP::iterator TIME_POLICY_MAP_ITERATOR;

//其中id区分：配置中心直接下发（id以前缀"10"开头）；巡检任务指派（id以前缀"11"开头）两类。
//监控任务容器 key=id, value=pair<CFTDSysNetGatherTaskField,int>实例,int标识任务状态：0,1,2分别代表就绪，已派发，无效
typedef std::map<int, pair<CFTDSysNetGatherTaskField, int> > MONITOR_TASK_MAP;
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

//接口三元map容器，key=pair<int, string>其中int表示接口所在设备的id，string表示接口名称
//value=接口所在设备的接口索引 如：< <1,GigabitEthernet0/12>, 10112>，此容器代替NET_INTERFACE_MAP
//避免由于设备objectid的改变，而导致的接口的objectid的变化
typedef std::map<pair<int, string> , string> TRIP_INTERFACE_MAP;

//会员链路信息表
//key = id; value = CFTDSysNetPartyLinkInfoField实例
//key = ip; value = list<id>
typedef std::map<int, CFTDSysNetPartyLinkInfoField> PartyLink_MAP;	//
typedef PartyLink_MAP::iterator PartyLink_MAP_ITERATOR;
typedef std::map<string, list<int> > IP_PartyLink_MAP;
typedef IP_PartyLink_MAP::iterator	IP_PartyLink_MAP_ITERATOR;

class CDetectWorkThread;
class CSynConnector :
	public CSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///构造函数	
			///@param	pReactor	CReactor对象指针
		CSynConnector(CReactor *pReactor);

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

		///管理服务主备角色响应函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspServiceRole(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

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

		///响应网络设备接口应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspNetInterfaceTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnNetIntefaceTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应网络设备模块应答处理函数
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

		///响应巡检任务应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqLoopItemTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRspLoopItemTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnLoopItemTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应任务执行次数应答处理函数
		void OnRspTaskRunTimeTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应指令应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspCommandTypeTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnCommandTypeTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应动作组应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspActionGroupTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnActionGroupTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应设备对象组应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspDeviceGroupTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnDeviceGroupTopic(
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

		///响应网络探测请求应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryNetDeviceDetectTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应动作指标应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspActionAttrTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnActionAttrTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应设备任务应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspDevTaskTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnDevTaskTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应指令信息应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspInstrTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnInstrTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///响应会员链路信息应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspPartLinkTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnPartLinkTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		//
		void OnRspPartLinkInfoStatus(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *Session);

		///基线比对任务应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspBaseLineTaskTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnBaseLineTaskTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		//请求网络配置信息
		void SendRequestNetAreaQry(void);
		void SendRequestNetSubAreaQry(void);
		void SendRequestNetSubAreaIPQry(void);

		//请求设备厂商信息
		void SendRequestDevManuQry(void);

		//请求设备型号信息
		void SendRequestDevSerialQry(void);

		//请求设备类型信息
		void SendRequestDevTypeQry(void);

		//请求特殊设备的comm信息
		void SendRequestNetCommQry(void);

		//请求设备mib信息
		void SendRequestMIBOIDQry(void);

		//查询请求接口
		void RequestQry(DWORD msgID);

	/* */
	public:
		//发送任务状态
		void SendTaskStatus(int task_id, int task_status, int delay_gap);

		//发送任务当日执行次数
		void SendTaskRunTimes(int task_id, int runtimes);

	/* */
	public:
		///根据网络子区名称获取网络子区id
			///@param   net			网络子区名称
			///return   int			网络子区id
		int GetNetSubAreaIDByNetArea(int centerid, const char *net);
		int GetNetSubAreaIPIDByNetSubArea(
				int netid,
				const char *ip,
				const char *mask);

		int GetDevManuIDByManuName(const char *name);
		int GetDevTypeIDByTypeName(const char *name);
		int GetMonitorTypeIDByName(const char *name);

		///分派探测监控指标
		void DispatchMonTask(void);

		///分派巡检任务
		void DispatchLoopTask(void);

		///网络探测响应函数
			///@param	reqid	请求对应的id
			///@param	type	返回的消息类别
			///@param	value	返回的消息所携带的value
		void RspQryNetDeviceDetectTopic(
				DWORD reqid,
				int type = 0,
				int value = 0);

		///向配置中心发送CFTDRtnObjectAttrField信息
			///@param	field		字段数据
		void SendCFTDRtnObjectAttrField(CFTDRtnObjectAttrField &field);

		///向配置中心发送网络cdp信息
			///@param	hosts		具有cdp信息的网络设备集
		void SendCDPInfo(std::vector<SInfoHost> &hosts);

		///向配置中心发送网设备信息
			///@param	hosts		网络设备集
		void SendHostInfo(std::vector<SInfoHost> &hosts, DWORD req);

		///向配置中心发送接口信息
			///@param	hosts		网络设备集
		void SendInterfaceInfo(std::vector<SInfoHost> &hosts);

		///向配置中心发送模块信息
			///@param	hosts		网络设备集
		void SendModuleInfo(std::vector<SInfoHost> &hosts);

		//发送FTDC_CHAIN_LAST消息
		void Send_FTDC_CHAIN_LAST_Msg(DWORD msg)
		{
			m_pkgSend.PreparePackage(msg, FTDC_CHAIN_LAST, FTD_VERSION);
			if (m_pSession != NULL)
			{
				m_pSession->SendRequestPackage(&m_pkgSend);
			}
		}

		///根据objid获取设备对象
			///@param	objid		设备的objectid
		CFTDSysNetDeviceField *GetDeviceByObjID(const char *objid);

		///根据objid获取接口对象
			///@param	objid		设备的objectid
		CFTDSysNetInterfaceField *GetInterfaceByObjID(const char *objid);

		///根据objid获取接口对象
			///@param	objid		设备的objectid
		CFTDSysNetModuleField *GetModuleByObjID(const char *objid);

		///根据网络子区id获取网络配置名称
			///@param   net			网络子区名称
			///@param   center		网络中心名称
		void GetNetAreaInfoByNetSubAreaID(int id, string &net, string &center);

		///根据设备ip地址获取设备类型
			///@param   ip			设备ip地址
			///@param   id_type		设备类型id	
			///@param   id_manu		设备厂商id
		void GetNetDeviceInfoIDByIP(
		const char	*ip,
		int &id_type,
		int &id_manu,
		string	&objID,
		string* strDeviceType = NULL)
		{
			//最好检验ip取值的合法性
			if (m_dev_ips.find(ip) != m_dev_ips.end()
			&&	m_devs.find(m_dev_ips[ip]) != m_devs.end())
			{
				id_type = m_devs[m_dev_ips[ip]].CATEGORY_ID.getValue();
				id_manu = m_devs[m_dev_ips[ip]].MANUFACTORY_ID.getValue();
				objID = m_devs[m_dev_ips[ip]].ObjectID.getValue();
				if (strDeviceType) *strDeviceType = m_devs[m_dev_ips[ip]].DEVICETYPE.getValue();
			}
			else
			{
				id_type = 0;
				id_manu = 0;
				objID = "";
				printf(
					"warning: there is no validity ip[%s] information.\n",
					ip);
			}
		}

		//根据大区名获取大区对应的ID号
		int GetNetAreaIDByName(const char *center)
		{
			for (NET_AREA_MAP_ITERATOR it = m_sysNets.begin();
				 it != m_sysNets.end();
				 it++)
			{
				if (strcasecmp(center, it->second.EName.getValue()) == 0)
				{
					return it->first;
				}
			}

			return -1;
		}

		//根据id获取厂商名称
		void GetManuNameByID(int id, string &manu)
		{
			for (DEV_MANUFACTORY_MAP_ITERATOR it = m_devmanus.begin();
				 it != m_devmanus.end();
				 it++)
			{
				if (id == it->second.ID.getValue())
				{
					manu = it->first;
					break;
				}
			}
		}

		//根据ip获取设备名称
		const char *GetDevNameByIP(const char *ip)
		{
			if (ip == NULL)
			{
				return NULL;
			}

			NET_IP_MAP_ITERATOR it;
			if ((it = m_dev_ips.find(ip)) != m_dev_ips.end())
			{
				if (m_devs.find(it->second) != m_devs.end())
				{
					return m_devs[it->second].NAME.getValue();
				}
			}

			return NULL;
		}

		/************************************************************************/
		/* 增加监控指标任务                                      */

		/************************************************************************/
		void AddMonTask(
		int id,
		char *attr,
		char *devobjID,
		int policyID,
		int rtnType = 0)
		{
			CFTDSysNetGatherTaskField task;

			task.AttrType = attr;
			task.ObjectID = devobjID;
			task.PolicyTypeID = policyID;
			task.DataType = rtnType;

			m_montasks[id] = make_pair(task, true);
		}

		/************************************************************************/
		/* 设置任务派发标志                                       */

		/************************************************************************/
		bool SetMonTaskFlag(int id, bool flag)
		{
			if (0 == id)
			{
				for (MONITOR_TASK_MAP_ITERATOR it = m_montasks.begin();
					 it != m_montasks.end();
					 it++)
				{
					it->second.second = true;
				}

				return true;
			}

			if (m_montasks.find(id) != m_montasks.end())
			{
				m_montasks[id].second = flag;
				return true;
			}

			return false;
		}

		/************************************************************************/
		/* 设置线程数组地址及线程个数函数                                       */

		/************************************************************************/
		void setThreadPoint(CAyncGetThread **pThread, int nThreadNum)
		{
			m_nThreadNum = nThreadNum;
			m_pThread = pThread;
		}

		/************************************************************************/
		/* 返回设备被分配到线程id，-1表示没有被分配到线程                        */

		/************************************************************************/
		int getDisTaskThreadIDByIP(const char *ip)
		{
			if (m_nThreadNum == 0 || m_pThread == NULL)
			{
				return -1;
			}

			for (int i = 0; i < m_nThreadNum; i++)
			{
				if (m_pThread[i]->isMonitorDevTask(ip))
				{
					return i;
				}
			}

			return -1;
		}

		/************************************************************************/
		/* 获取synConnector实例的句柄                                       */

		/************************************************************************/
		static CSynConnector *GetInstancePoint(void)
		{
			if (pInstance == NULL)
			{
				printf(
					"Warnning: the instance of CSynConnector doesn't initilize yet!\n");
			}

			return pInstance;
		}

		void SetInstancePoint(CSynConnector *inst)
		{
			if (inst != NULL)
			{
				pInstance = inst;
			}
			else
			{
				printf(
					"warning: set instance point fail because of the point is NULL .\n");
			}
		}

		NET_DEVICE_MAP &GetDevMap(void)
		{
			return m_devs;
		}

		NET_IP_MAP GetDeviceIP(void)
		{
			return m_dev_ips;
		}

		void GetDeviceIPList(list<string> &ip_list)
		{
		}

		const char * GetOIDValue( const char * oidname, int manuID)
		{
			ASSERT( oidname != NULL );
			string key = oidname;
			if( m_IDmanu.find( manuID )!= m_IDmanu.end())
			{
				key += CONSYM;
				key.append( m_IDmanu[manuID]);
			}
			if( m_oids.find( key ) != m_oids.end() )
			{
				return m_oids[key].OID.getValue();
			}
			else
			{
				return NULL;
			}
		}

		void GetIfsName(string ipaddress, string ifs_index, string& name)
		{
			if( m_dev_ips.find( ipaddress )!= m_dev_ips.end() )
			{
				pair<int,string> key(m_dev_ips[ipaddress],ifs_index);
				if( m_dev_ifs.find( key ) != m_dev_ifs.end() )
				{
					int ifs_key = m_dev_ifs[ key ];
					if( m_ifs.find( ifs_key ) != m_ifs.end() )
					{
						name = m_ifs[ ifs_key ].EName.getValue();
					}
				}
			}
		}

		void SetTaskManagerThread( CTaskManagerThread	* pManager )
		{
			m_pTaskManagerThread = pManager;
		}

		//判断ip地址是否在当前探测范围
		bool IsBingTetect(const char *ip)
		{
			if (m_curdetrang[0] == '\0' || ip == NULL)
			{
				return false;
			}

			char first_ip[20] = "\0";
			int num = 0;
			if (strchr(m_curdetrang, '/') != NULL)
			{
				sscanf(m_curdetrang, "%[^/]/%d", first_ip, &num);

				unsigned long u_first_ip = htonl(inet_addr(first_ip));
				unsigned long u_ip = htonl(inet_addr(ip));
				if (u_ip >= u_first_ip && u_ip < u_first_ip + num)
				{
					return true;
				}
			}

			return false;
		}

	/* */
	private:
		void RunTask(CSnmpTaskInfo task);

	/* */
	private:
		static CSynConnector *pInstance;

		///发送数据包使用的缓冲区
		CFTDCPackage m_pkgSend;

		//配置类信息
		NET_AREA_MAP m_sysNets;
		NET_SUB_AREA_MAP m_sysNetSubs;
		NET_SUB_AREA_IP_MAP m_sysNetSubIPs;

		//监控对象类别
		MONITOR_TYPE_MAP m_montypes;

		//设备厂商信息，如cisco F5等
		DEV_MANUFACTORY_MAP m_devmanus;
		map<int,string>     m_IDmanu;

		//设备类型信息，如路由器、交换机等
		DEV_TYPE_MAP m_devtypes;

		//设备型号信息，如cisco3600等
		DEV_SERIAL_MAP m_devserials;

		//网络设备信息<id,netdev>
		NET_DEVICE_MAP m_devs;

		//设备ip信息
		NET_IP_MAP m_dev_ips;

		//接口信息
		NET_INTERFACE_MAP m_ifs;

		// < pair<deviceID, ifs_index>, ifs_ID
		map< pair<int,string>,int >  m_dev_ifs;

		//模块信息
		NET_MODULE_MAP m_mods;

		//TRIP_INTERFACE_MAP m_ifstrip;

		//时间策略信息
		TIME_POLICY_MAP m_tpolicys;

		//监控任务
		MONITOR_TASK_MAP m_montasks;

		CFTDCSession *m_pSession;

		///对FIBCONFSERVER连接成功的标志位
		bool m_Flag;

		///获取配置信息的标志位
		bool m_hashconfig;

		///标识网络探测的进行
		bool m_detecting;

		///线程数组指针
		CAyncGetThread **m_pThread;

		///线程启动个数
		int m_nThreadNum;

		///当前分派任务的线程编号
		int m_nCurentDisThreadID;

		CTaskManagerThread	*m_pTaskManagerThread;

	/* */
	public:
		//特殊comm信息 key=ip,value=comm;
		COMMUNITY_MAP m_comms;

		//设备通用oid
		GEN_OID_MAP m_genoids;

		//厂商oid信息
		CON_OID_CONTAIN_MAP m_oids;

		//巡检任务
		LOOP_ITEM_MAP m_loopitem;

		//巡检指令
		COMMAND_MAP m_commands;

		//巡检动作组
		ACTION_GROUP_MAP m_actions;

		//巡检设备组
		DEVICE_GROUP_MAP m_groupdev;

		//会员接入链路信息
		PartyLink_MAP m_partylinks;
		IP_PartyLink_MAP m_devpartylinks;

		//记录每次探测的req与网络探测的请求内容 key=reqid, value=CFTDReqQryNetDeviceDetectField实例
		map<DWORD, CFTDReqQryNetDeviceDetectField> m_detectids;
		TemplateMutexCatch<DWORD> m_listreq;

		//探测请求处理线程
		CDetectWorkThread *m_pdetthread;

		//当前探测范围 格式 " 起始ip地址/mask" 如"172.1.128.1/32"
		char m_curdetrang[32];
};

// Detect设备的工作线程
class CDetectWorkThread :
	public CThread
{
	/* */
	public:

		///构造函数
		CDetectWorkThread(CSynConnector *pSys, DWORD reqid = 0)
		{
			m_pSys = pSys;
			m_pinfoThread = new CGetDeviceInfoThread();
		}

		///析构函数
		~CDetectWorkThread(void)
		{
			if (m_pinfoThread != NULL)
			{
				delete m_pinfoThread;
				m_pinfoThread = NULL;
			}

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
	private:
		///多线程实现探测设备
		void MultiThreadDoDetect(DWORD reqid);

		void DoSnmpDevice(list<string> &iplist, DWORD reqid);

	/* */
	public:
		CSynConnector *m_pSys;
		CGetDeviceInfoThread *m_pinfoThread;

	/* */
	private:
		CMutex m_detLock;
};

class CWorkThread :
	public CThread
{
	/* */
	public:

		///构造函数
		CWorkThread(int threadID = 0)
		{
			m_threadID = threadID;
			m_pinfoThread = new CGetDeviceInfoThread();
		}

		///析构函数
		~CWorkThread(void)
		{
			if (m_pinfoThread != NULL)
			{
				delete m_pinfoThread;
				m_pinfoThread = NULL;
			}

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

		void setParas(
		uint32 start,
		int ipnums,
		CSynConnector *pSys = NULL,
		DWORD reqid = 0)
		{
			m_start = start;
			m_ipnums = ipnums;
			m_reqid = reqid;
			m_pSys = pSys;
		}

	/* */
	private:
		///ping指定网段的设备, 网络由ip+mask确定
			///@param   hosts   输出结果,ping通的ip地址集
		void PingDevice(
				const char	*ip,
				const char	*mask,
				list<string> &hosts,
				int bound = 0);

		///ping指定网段的设备,网段有ip起始地址+ip个数确定
		void PingDevice(void);

		///通过snmp采集设备集中设备的相关信息
			///@param	iplist	设备的ip地址集
			///@param	mask	设备所属于的网络划分名 “大区.子网”，如"PuDian.OA"
			///@param   hosts   输出结果,设备集
		void DoSnmpDevice(void);

	/* */
	public:
		CSynConnector *m_pSys;
		CGetDeviceInfoThread *m_pinfoThread;
		std::list<string> m_iplist;

		//执行探测请求的id号
		DWORD m_reqid;

		//探测起始ip、及ip地址个数
		uint32 m_start;
		int m_ipnums;

		//探测程序中标识线程的id，不同于系统分配的线程id
		int m_threadID;
};

class CCheckConnThread :
	public CThread
{
	/* */
	public:
		CCheckConnThread(void)
		{
		}

		~CCheckConnThread(void)
		{
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
};
#endif
