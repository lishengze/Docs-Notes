--清空据库写记录日志表
truncate table t_DbWriteLog;

--清空历史状态信息表表
truncate table t_SysHistoryObjectAttr;

--清空前置响应信息表表
truncate table t_SysFrontInfo;

--清空告警事件信息表表
truncate table t_SysWarningEvent;

--清空用户信息表表
truncate table t_SysRegisterUserInfo;

--清空Cpu信息表表
truncate table t_RspQryTopCpuInfo;

--清空Mem信息表表
truncate table t_RspQryTopMemInfo;

--清空Network信息表表
truncate table t_RspQryNetworkInfo;

--清空历史峰值信息表表
truncate table t_SysHistoryTradePeak;

--清空网络设备表
truncate table t_SysNetDevice;

--清空网络设备连接关系表
truncate table t_SysNetDeviceLinked;

--清空网络大区划分表
truncate table t_SysNetArea;

--清空网络子区表
truncate table t_SysNetSubArea;

--清空网络子区IP表
truncate table t_SysNetSubAreaIP;

--清空大楼表
truncate table t_SysNetBuilding;

--清空机房表
truncate table t_SysNetRoom;

--清空机柜表
truncate table t_SysNetCabinets;

--清空网络设备类型表
truncate table t_SysNetDeviceType;

--清空OID表
truncate table t_SysNetOID;

--清空时间策略表
truncate table t_SysNetTimePolicy;

--清空采集任务表
truncate table t_SysNetGatherTask;

--清空常用设备类别表
truncate table t_SysNetDeviceCategory;

--清空设备厂商表
truncate table t_SysNetManufactory;

--清空设备共同体表
truncate table t_SysNetCommunity;

--清空端口类型表
truncate table t_SysNetPortType;

--清空端口表
truncate table t_SysNetInterface;

--清空通用OID表
truncate table t_SysNetGeneralOID;

--清空监控对象类别表
truncate table t_SysNetMonitorType;

--清空指标统表表
truncate table t_SysNetMonitorAttrScope;

--清空监控指标表表
truncate table t_SysNetMonitorAttrType;

--清空职能区表
truncate table t_SysNetFuncArea;

--清空监控指令表表
truncate table t_SysNetMonitorCommandType;

--清空动作族表表
truncate table t_SysNetMonitorActionGroup;

--清空设备对象组表表
truncate table t_SysNetMonitorDeviceGroup;

--清空任务信息表表
truncate table t_SysNetMonitorTaskInfo;

--清空会员链路信息表表
truncate table t_SysNetPartyLinkInfo;

--清空会员链路信息表表
truncate table t_SysNetDelPartyLinkInfo;

--清空会员链路信息表表
truncate table t_SysNetPartyLinkAddrChange;

--清空监控动作指标对照表表
truncate table t_SysNetMonitorActionAttr;

--清空模块表
truncate table t_SysNetModule;

--清空告警表达式信息表表
truncate table t_SysNetEventExpr;

--清空事件类型表
truncate table t_SysNetEventType;

--清空事件子类型表
truncate table t_SysNetSubEventType;

--清空事件级别表
truncate table t_SysNetEventLevel;

--清空任务结果规则分析表表
truncate table t_SysNetMonitorDeviceTask;

--清空任务指令指标集表表
truncate table t_SysNetMonitorTaskInstAttrs;

--清空任务结果表表
truncate table t_SysNetMonitorTaskResult;

--清空基线表表
truncate table t_SysNetBaseLine;

--清空基线任务表表
truncate table t_SysNetBaseLineTask;

--清空基线结果表表
truncate table t_SysNetBaseLineResult;

--清空会员链路状态信息表表
truncate table t_SysNetPartyLinkStatusInfo;

--清空会员SDH线路明细表表
truncate table t_SysNetMemberSDHLineInfo;

--清空DDN链路信息表表
truncate table t_SysNetDDNLinkInfo;

--清空非会员线路使用信息表
truncate table t_SysNetPseudMemberLinkInfo;

--清空远端设备信息表
truncate table t_SysNetOuterDeviceInfo;

--清空本地ping结果表
truncate table t_SysLocalPingResultInfo;

--清空远程ping结果表
truncate table t_SysRomotePingResultInfo;

--清空交易系统前置报单响应信息表
truncate table t_SysTradeFrontOrderRttStat;

--清空交易系统前置报单分布区间表
truncate table t_SysTradeOrderRttCutLine;

--清空会员席位交易状态表
truncate table t_SysParticTradeOrderStates;

--清空系统路由信息表
truncate table t_RouterInfo;

--清空磁盘I/O信息表
truncate table t_DiskIO;

--清空系统状态信息表
truncate table t_StatInfo;

--清空进程信息表
truncate table t_TopProcessInfo;

--清空事件描述信息表
truncate table t_SysEventDescrip;

--清空会员链路费用表表
truncate table t_SysMemberLinkCost;

--清空会员链路月租表表
truncate table t_SysNetPartylinkMonthlyRent;

--清空非会员链路信息表表
truncate table t_SysNetNonPartyLinkInfo;

