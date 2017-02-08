/////////////////////////////////////////////////////////////////////////
///@system 执行引擎系统
///@company 上海期货信息技术有限公司
///@file CMemoryDB.h
///@brief定义了类CMemoryDB
///@history 
///20050824	王肇东		创建该文件
///20120111 江鹏		NT-0163 kernel命令行增加指定用户密码参数
/////////////////////////////////////////////////////////////////////////

#ifndef CMEMORYDB_H
#define CMEMORYDB_H

#include "CBaseObject.h"
#include "CConfig.h"
#include "BaseDataStruct.h"
#include "databaseFactories.h"
#include "databaseIterators.h"

struct TableStruct
{
	char tableName[100];
	int  reuseID;
};
/////////////////////////////////////////////////////////////////////////
///CMemoryDB是一个内存数据库类，包含了所有定义的表信息
///@author	王肇东
///@version	1.0,20050824
/////////////////////////////////////////////////////////////////////////
class CMemoryDB : public CBaseObject
{
public:
	///构造方法，创建内存数据库
	CMemoryDB(void);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CMemoryDB(void);
	
	virtual int isA(char *objectType);
	virtual char *getType(void);
	virtual void output(CLogger *pLogger,int indent=0);

	///进行初始化工作
	///@param	pConfig	初始化时使用的配置信息
	///@return	1表示成功，0表示失败
	virtual int init(CConfig *pConfig,IMemoryAllocator *pAllocator=NULL,bool reuse=false);
	
	///进行数据载入工作
	///@param	pConfig	载入数据时使用的配置信息
	///@return	1表示成功，0表示失败
	virtual int load(CConfig *pConfig);

	///进行数据存储工作
	///@param	pConfig	保存数据时使用的配置信息
	///@return	1表示成功，0表示失败
	virtual int save(CConfig *pConfig);
	
	///清空所有的数据
	///@return	1表示成功，0表示失败
	virtual void clear(void);
	
	///完成所有外键的连接
	virtual void linkAll(void);
	
	
	
	///无效报单表
	CSysInvalidateOrderFactory *m_SysInvalidateOrderFactory;
	
	///报单状态表
	CSysOrderStatusFactory *m_SysOrderStatusFactory;
	
	///报单成交表
	CSysBargainOrderFactory *m_SysBargainOrderFactory;
	
	///合约基本属性表
	CSysInstPropertyFactory *m_SysInstPropertyFactory;
	
	///合约保证金率表
	CSysMarginRateFactory *m_SysMarginRateFactory;
	
	///合约涨跌停板表
	CSysPriceLimitFactory *m_SysPriceLimitFactory;
	
	///会员限仓表
	CSysPartPosiLimitFactory *m_SysPartPosiLimitFactory;
	
	///客户限仓表
	CSysClientPosiLimitFactory *m_SysClientPosiLimitFactory;
	
	///特殊客户限仓表
	CSysSpecialPosiLimitFactory *m_SysSpecialPosiLimitFactory;
	
	///账户出入金查询表
	CSysTransactionChgFactory *m_SysTransactionChgFactory;
	
	///客户数据变动查询表
	CSysClientChgFactory *m_SysClientChgFactory;
	
	///会员客户对照变动查询表
	CSysPartClientChgFactory *m_SysPartClientChgFactory;
	
	///限仓数据变动查询表
	CSysPosiLimitChgFactory *m_SysPosiLimitChgFactory;
	
	///限仓数据变动查询表
	CSysClientPosiLimitChgFactory *m_SysClientPosiLimitChgFactory;
	
	///限仓数据变动查询表
	CSysSpecPosiLimitChgFactory *m_SysSpecPosiLimitChgFactory;
	
	///保值额度变动查询表
	CSysHedgeDetailChgFactory *m_SysHedgeDetailChgFactory;
	
	///会员变动查询表
	CSysParticipantChgFactory *m_SysParticipantChgFactory;
	
	///保证金率变动查询表
	CSysMarginRateChgFactory *m_SysMarginRateChgFactory;
	
	///IP地址变动查询表
	CSysUserIpChgFactory *m_SysUserIpChgFactory;
	
	///会员交易信息表
	CSysPartTradeFactory *m_SysPartTradeFactory;
	
	///对象状态指标表
	CSysMdbObjectAttrFactory *m_SysMdbObjectAttrFactory;
	
	///日志文件内容传输信息表
	CSysMdbSyslogInfoFactory *m_SysMdbSyslogInfoFactory;
	
	///用户信息表
	CSysUserInfoFactory *m_SysUserInfoFactory;
	
	///在线用户信息查询应答表
	CSysOnlineUserInfoFactory *m_SysOnlineUserInfoFactory;
	
	///告警事件查询应答表
	CSysWarningEventFactory *m_SysWarningEventFactory;
	
	///告警明细应答表
	CSysWarningQueryFactory *m_SysWarningQueryFactory;
	
	///日志事件查询应答表
	CSyslogEventFactory *m_SyslogEventFactory;
	
	///事件描述查询表
	CSysEventDescripFactory *m_SysEventDescripFactory;
	
	///主机环境信息表
	CRspQryHostEnvCommonFactory *m_RspQryHostEnvCommonFactory;
	
	///主机环境Lan信息表
	CRspQryHostEnvLanFactory *m_RspQryHostEnvLanFactory;
	
	///主机环境存储设备信息表
	CRspQryHostEnvStorageFactory *m_RspQryHostEnvStorageFactory;
	
	///主机环境IO设备信息表
	CRspQryHostEnvIOFactory *m_RspQryHostEnvIOFactory;
	
	///主机环境文件系统信息表
	CRspQryHostEnvFSFactory *m_RspQryHostEnvFSFactory;
	
	///主机环境交换分区信息表
	CRspQryHostEnvSwapFactory *m_RspQryHostEnvSwapFactory;
	
	///主机环境网卡配置信息表
	CRspQryHostEnvLanCfgFactory *m_RspQryHostEnvLanCfgFactory;
	
	///CPU资源使用信息表
	CSysMdbTopCpuInfoFactory *m_SysMdbTopCpuInfoFactory;
	
	///内存资源使用信息表
	CSysMdbTopMemInfoFactory *m_SysMdbTopMemInfoFactory;
	
	///进程信息表
	CSysMdbTopProcessInfoFactory *m_SysMdbTopProcessInfoFactory;
	
	///文件系统信息表
	CSysMdbFileSystemInfoFactory *m_SysMdbFileSystemInfoFactory;
	
	///网络使用信息表
	CSysMdbNetworkInfoFactory *m_SysMdbNetworkInfoFactory;
	
	///会员表
	CSysParticipantInitFactory *m_SysParticipantInitFactory;
	
	///交易用户表
	CSysUserInitFactory *m_SysUserInitFactory;
	
	///客户表
	CSysClientInitFactory *m_SysClientInitFactory;
	
	///交易系统登录信息表
	CSysTradeUserLoginInfoFactory *m_SysTradeUserLoginInfoFactory;
	
	///Web应用信息表
	CSysMdbWebAppInfoFactory *m_SysMdbWebAppInfoFactory;
	
	///系统内存池信息表
	CSysMdbMemPoolInfoFactory *m_SysMdbMemPoolInfoFactory;
	
	///连接器信息表
	CSysMdbConnectorInfoFactory *m_SysMdbConnectorInfoFactory;
	
	///数据库查询应答表
	CSysMdbDBQueryFactory *m_SysMdbDBQueryFactory;
	
	///网络大区划分表
	CSysNetAreaFactory *m_SysNetAreaFactory;
	
	///网络子区表
	CSysNetSubAreaFactory *m_SysNetSubAreaFactory;
	
	///网络子区IP表
	CSysNetSubAreaIPFactory *m_SysNetSubAreaIPFactory;
	
	///职能区表
	CSysNetFuncAreaFactory *m_SysNetFuncAreaFactory;
	
	///网络设备表
	CSysNetDeviceFactory *m_SysNetDeviceFactory;
	
	///网络设备连接关系表
	CSysNetDeviceLinkedFactory *m_SysNetDeviceLinkedFactory;
	
	///OID表
	CSysNetOIDFactory *m_SysNetOIDFactory;
	
	///网络设备类型表
	CSysNetDeviceTypeFactory *m_SysNetDeviceTypeFactory;
	
	///时间策略表
	CSysNetTimePolicyFactory *m_SysNetTimePolicyFactory;
	
	///采集任务表
	CSysNetGatherTaskFactory *m_SysNetGatherTaskFactory;
	
	///常用设备类别表
	CSysNetDeviceCategoryFactory *m_SysNetDeviceCategoryFactory;
	
	///设备厂商表
	CSysNetManufactoryFactory *m_SysNetManufactoryFactory;
	
	///设备共同体表
	CSysNetCommunityFactory *m_SysNetCommunityFactory;
	
	///端口类型表
	CSysNetPortTypeFactory *m_SysNetPortTypeFactory;
	
	///端口表
	CSysNetInterfaceFactory *m_SysNetInterfaceFactory;
	
	///通用OID表
	CSysNetGeneralOIDFactory *m_SysNetGeneralOIDFactory;
	
	///监控对象类别表
	CSysNetMonitorTypeFactory *m_SysNetMonitorTypeFactory;
	
	///指标统表表
	CSysNetMonitorAttrScopeFactory *m_SysNetMonitorAttrScopeFactory;
	
	///监控指标表表
	CSysNetMonitorAttrTypeFactory *m_SysNetMonitorAttrTypeFactory;
	
	///监控指令表表
	CSysNetMonitorCommandTypeFactory *m_SysNetMonitorCommandTypeFactory;
	
	///动作族表表
	CSysNetMonitorActionGroupFactory *m_SysNetMonitorActionGroupFactory;
	
	///设备对象组表表
	CSysNetMonitorDeviceGroupFactory *m_SysNetMonitorDeviceGroupFactory;
	
	///任务信息表表
	CSysNetMonitorTaskInfoFactory *m_SysNetMonitorTaskInfoFactory;
	
	///任务对象集表
	CSysNetMonitorTaskObjectSetFactory *m_SysNetMonitorTaskObjectSetFactory;
	
	///任务结果表表
	CSysNetMonitorTaskResultFactory *m_SysNetMonitorTaskResultFactory;
	
	///会员链路信息表表
	CSysNetPartyLinkInfoFactory *m_SysNetPartyLinkInfoFactory;
	
	///会员链路信息表表
	CSysNetDelPartyLinkInfoFactory *m_SysNetDelPartyLinkInfoFactory;
	
	///会员链路信息表表
	CSysNetPartyLinkAddrChangeFactory *m_SysNetPartyLinkAddrChangeFactory;
	
	///监控动作指标对照表表
	CSysNetMonitorActionAttrFactory *m_SysNetMonitorActionAttrFactory;
	
	///模块表
	CSysNetModuleFactory *m_SysNetModuleFactory;
	
	///告警表达式信息表表
	CSysNetEventExprFactory *m_SysNetEventExprFactory;
	
	///事件类型表
	CSysNetEventTypeFactory *m_SysNetEventTypeFactory;
	
	///事件子类型表
	CSysNetSubEventTypeFactory *m_SysNetSubEventTypeFactory;
	
	///事件级别表
	CSysNetEventLevelFactory *m_SysNetEventLevelFactory;
	
	///任务结果规则分析表表
	CSysNetMonitorDeviceTaskFactory *m_SysNetMonitorDeviceTaskFactory;
	
	///任务指令指标集表表
	CSysNetMonitorTaskInstAttrsFactory *m_SysNetMonitorTaskInstAttrsFactory;
	
	///基线表表
	CSysNetBaseLineFactory *m_SysNetBaseLineFactory;
	
	///基线任务表表
	CSysNetBaseLineTaskFactory *m_SysNetBaseLineTaskFactory;
	
	///会员链路状态信息表表
	CSysMdbNetPartyLinkStatusInfoFactory *m_SysMdbNetPartyLinkStatusInfoFactory;
	
	///会员SDH线路明细表表
	CSysNetMemberSDHLineInfoFactory *m_SysNetMemberSDHLineInfoFactory;
	
	///DDN链路信息表表
	CSysNetDDNLinkInfoFactory *m_SysNetDDNLinkInfoFactory;
	
	///非会员线路使用信息表
	CSysNetPseudMemberLinkInfoFactory *m_SysNetPseudMemberLinkInfoFactory;
	
	///远端设备信息表
	CSysNetOuterDeviceInfoFactory *m_SysNetOuterDeviceInfoFactory;
	
	///本地ping结果表
	CSysLocalPingResultInfoFactory *m_SysLocalPingResultInfoFactory;
	
	///远程ping结果表
	CSysRomotePingResultInfoFactory *m_SysRomotePingResultInfoFactory;
	
	///会员席位交易状态表
	CSysParticTradeOrderStatesFactory *m_SysParticTradeOrderStatesFactory;
	
	///系统路由信息表
	CSysMdbRouterInfoFactory *m_SysMdbRouterInfoFactory;
	
	///磁盘I/O信息表
	CSysMdbDiskIOFactory *m_SysMdbDiskIOFactory;
	
	///系统状态信息表
	CSysMdbStatInfoFactory *m_SysMdbStatInfoFactory;
	
	///交易系统前置报单响应信息表
	CSysMdbTradeFrontOrderRttStatFactory *m_SysMdbTradeFrontOrderRttStatFactory;
	
	///合约状态切换表
	CSysInstrumentStatusFactory *m_SysInstrumentStatusFactory;
	
	///合约交易节信息表
	CSysCurrTradingSegmentAttrFactory *m_SysCurrTradingSegmentAttrFactory;
	
	///会员链路费用表表
	CSysMemberLinkCostFactory *m_SysMemberLinkCostFactory;
	
	///会员链路月租表表
	CSysNetPartylinkMonthlyRentFactory *m_SysNetPartylinkMonthlyRentFactory;
	
	///会员链路月租表表
	CSysNetNonPartyLinkInfoFactory *m_SysNetNonPartyLinkInfoFactory;
	
	///由kernel强制指定的用户密码
	CPasswordType m_ForceUserPassword;
	
private:
	CFixMem *pMem;		///用来存放表的信息
};

#endif
