--******************************
--创建据库写记录日志表
--******************************
create table t_DbWriteLog
(
	TradingDay char(8) not null
	,Count number(10) 
	,constraint pk_DbWriteLog primary key (TradingDay)
);

comment on table t_DbWriteLog is '据库写记录日志';
	comment on column t_DbWriteLog.TradingDay is '日期';
	comment on column t_DbWriteLog.Count is '已写记录';


--******************************
--创建历史状态信息表表
--******************************
create table t_SysHistoryObjectAttr
(
	MonDate char(8) not null
	,BeginTime char(8) not null
	,EndTime char(8) 
	,ObjectID varchar2(128) not null
	,AttrType varchar2(256) not null
	,ValueType number(1) 
	,FirstValue number(19,4) 
	,EndValue number(19,4) 
	,AvgValue number(19,4) 
	,MinValue number(19,4) 
	,MaxValue number(19,4) 
	,ValueCount number(10) 
	,constraint pk_SysHistoryObjectAttr primary key (MonDate,BeginTime,ObjectID,AttrType)
);

comment on table t_SysHistoryObjectAttr is '历史状态信息表';
	comment on column t_SysHistoryObjectAttr.MonDate is '采集的日期';
	comment on column t_SysHistoryObjectAttr.BeginTime is '本周期开始时间';
	comment on column t_SysHistoryObjectAttr.EndTime is '本周期结束时间';
	comment on column t_SysHistoryObjectAttr.ObjectID is '定义对象名';
	comment on column t_SysHistoryObjectAttr.AttrType is '监控指标类型';
	comment on column t_SysHistoryObjectAttr.ValueType is '监控指标的值类型';
	comment on column t_SysHistoryObjectAttr.FirstValue is '本周期收到第一个值';
	comment on column t_SysHistoryObjectAttr.EndValue is '本周期收到最后一个值';
	comment on column t_SysHistoryObjectAttr.AvgValue is '本周期平均值';
	comment on column t_SysHistoryObjectAttr.MinValue is '本周期收到最小值';
	comment on column t_SysHistoryObjectAttr.MaxValue is '本周期收到最大值';
	comment on column t_SysHistoryObjectAttr.ValueCount is '本周期收到指标个数';


--******************************
--创建前置响应信息表表
--******************************
create table t_SysFrontInfo
(
	MonDate char(8) not null
	,MonTime char(8) not null
	,FrontId varchar2(64) not null
	,RspCondition number(10) not null
	,ReqCount number(10) 
	,ReqRate number(10,4) 
	,constraint pk_SysFrontInfo primary key (MonDate,MonTime,FrontId,RspCondition)
);

comment on table t_SysFrontInfo is '前置响应信息表';
	comment on column t_SysFrontInfo.MonDate is '日期';
	comment on column t_SysFrontInfo.MonTime is '本周期开始时间';
	comment on column t_SysFrontInfo.FrontId is '前置机名';
	comment on column t_SysFrontInfo.RspCondition is '前置响应时间条件';
	comment on column t_SysFrontInfo.ReqCount is '请求数';
	comment on column t_SysFrontInfo.ReqRate is '所占总笔数比率';


--******************************
--创建告警事件信息表表
--******************************
create table t_SysWarningEvent
(
	MonDate char(8) not null
	,MonTime char(8) not null
	,OccurDate char(8) 
	,OccurTime char(8) 
	,EvendID number(10) not null
	,ObjectID varchar2(256) 
	,IPAddress char(15) 
	,EventName varchar2(64) 
	,EventNum number(10) 
	,EventType number(10) 
	,EventDes varchar2(512) 
	,ProcessFlag varchar2(1) 
	,WarningLevel varchar2(10) 
	,EventDealDes varchar2(64) 
	,FullEventName varchar2(256) 
	,constraint pk_SysWarningEvent primary key (MonDate,MonTime,EvendID)
);

comment on table t_SysWarningEvent is '告警事件信息表';
	comment on column t_SysWarningEvent.MonDate is '采集的日期';
	comment on column t_SysWarningEvent.MonTime is '采集的时间';
	comment on column t_SysWarningEvent.OccurDate is '事件发生日期';
	comment on column t_SysWarningEvent.OccurTime is '事件发生时间';
	comment on column t_SysWarningEvent.EvendID is '事件ID';
	comment on column t_SysWarningEvent.ObjectID is '发生事件的对象ID指标';
	comment on column t_SysWarningEvent.IPAddress is 'IP地址';
	comment on column t_SysWarningEvent.EventName is '事件名';
	comment on column t_SysWarningEvent.EventNum is '事件标签';
	comment on column t_SysWarningEvent.EventType is '事件类型';
	comment on column t_SysWarningEvent.EventDes is '事件描述';
	comment on column t_SysWarningEvent.ProcessFlag is '清除标记';
	comment on column t_SysWarningEvent.WarningLevel is '警告级别';
	comment on column t_SysWarningEvent.EventDealDes is '事件处理描述';
	comment on column t_SysWarningEvent.FullEventName is '事件全名';


--******************************
--创建用户信息表表
--******************************
create table t_SysRegisterUserInfo
(
	UserID char(15) not null
	,UserName char(15) 
	,UserInfo varchar2(99) 
	,Password char(40) 
	,Privilege number(2) 
	,EMail varchar2(50) 
	,EMailFlag number(2) 
	,HomePhone varchar2(30) 
	,HomePhoneFlag number(2) 
	,MobilePhone varchar2(30) 
	,MobilePhoneFlag number(2) 
	,constraint pk_SysRegisterUserInfo primary key (UserID)
);

comment on table t_SysRegisterUserInfo is '用户信息表';
	comment on column t_SysRegisterUserInfo.UserID is '用户代码';
	comment on column t_SysRegisterUserInfo.UserName is '用户姓名';
	comment on column t_SysRegisterUserInfo.UserInfo is '用户信息';
	comment on column t_SysRegisterUserInfo.Password is '密码';
	comment on column t_SysRegisterUserInfo.Privilege is '用户权限';
	comment on column t_SysRegisterUserInfo.EMail is '用户电子邮件';
	comment on column t_SysRegisterUserInfo.EMailFlag is '用户电子邮件接收标记';
	comment on column t_SysRegisterUserInfo.HomePhone is '用户固定电话';
	comment on column t_SysRegisterUserInfo.HomePhoneFlag is '用户固定电话接收标记';
	comment on column t_SysRegisterUserInfo.MobilePhone is '用户手机';
	comment on column t_SysRegisterUserInfo.MobilePhoneFlag is '用户手机接收标记';


--******************************
--创建Cpu信息表表
--******************************
create table t_RspQryTopCpuInfo
(
	HostName varchar2(64) not null
	,MonDate char(8) not null
	,MonTime char(8) not null
	,CPU varchar2(5) not null
	,LOAD number(10,4) 
	,USER_LOAD number(10,4) 
	,NICE number(10,4) 
	,SYS number(10,4) 
	,IDLE number(10,4) 
	,BLOCK number(10,4) 
	,SWAIT number(10,4) 
	,INTR number(10,4) 
	,SSYS number(10,4) 
	,constraint pk_RspQryTopCpuInfo primary key (HostName,MonDate,MonTime,CPU)
);

comment on table t_RspQryTopCpuInfo is 'Cpu信息表';
	comment on column t_RspQryTopCpuInfo.HostName is '主机名称';
	comment on column t_RspQryTopCpuInfo.MonDate is '采集的日期';
	comment on column t_RspQryTopCpuInfo.MonTime is '采集的时间';
	comment on column t_RspQryTopCpuInfo.CPU is 'CPU的编号';
	comment on column t_RspQryTopCpuInfo.LOAD is '';
	comment on column t_RspQryTopCpuInfo.USER_LOAD is '';
	comment on column t_RspQryTopCpuInfo.NICE is '';
	comment on column t_RspQryTopCpuInfo.SYS is '';
	comment on column t_RspQryTopCpuInfo.IDLE is '';
	comment on column t_RspQryTopCpuInfo.BLOCK is '';
	comment on column t_RspQryTopCpuInfo.SWAIT is '';
	comment on column t_RspQryTopCpuInfo.INTR is '';
	comment on column t_RspQryTopCpuInfo.SSYS is '';


--******************************
--创建Mem信息表表
--******************************
create table t_RspQryTopMemInfo
(
	HostName varchar2(64) not null
	,MonDate char(8) not null
	,MonTime char(8) not null
	,TOTALREAL number(10) 
	,ACTIVEREAL number(10) 
	,TOTALVIRTUAL number(10) 
	,ACTIVEVIRTUAL number(10) 
	,FREE number(10) 
	,constraint pk_RspQryTopMemInfo primary key (HostName,MonDate,MonTime)
);

comment on table t_RspQryTopMemInfo is 'Mem信息表';
	comment on column t_RspQryTopMemInfo.HostName is '主机名称';
	comment on column t_RspQryTopMemInfo.MonDate is '采集的日期';
	comment on column t_RspQryTopMemInfo.MonTime is '采集的时间';
	comment on column t_RspQryTopMemInfo.TOTALREAL is 'Total Real Memory';
	comment on column t_RspQryTopMemInfo.ACTIVEREAL is 'Active Real Memory';
	comment on column t_RspQryTopMemInfo.TOTALVIRTUAL is 'Total Virtual Memory';
	comment on column t_RspQryTopMemInfo.ACTIVEVIRTUAL is 'Active Virtual Memory';
	comment on column t_RspQryTopMemInfo.FREE is 'Free Memory';


--******************************
--创建Network信息表表
--******************************
create table t_RspQryNetworkInfo
(
	HostName varchar2(64) not null
	,MonDate char(8) not null
	,MonTime char(8) not null
	,LANNAME varchar2(10) not null
	,LANSTATUS varchar2(5) 
	,IPADDRESS char(15) 
	,RECVBYTES number(20) 
	,RECVPACKETS number(20) 
	,RECVERRORPACKETS number(20) 
	,RECVDROPPACKETS number(20) 
	,SENDBYTES number(20) 
	,SENDPACKETS number(20) 
	,SENDERRORPACKETS number(20) 
	,SENDDROPPACKETS number(20) 
	,constraint pk_RspQryNetworkInfo primary key (HostName,MonDate,MonTime,LANNAME)
);

comment on table t_RspQryNetworkInfo is 'Network信息表';
	comment on column t_RspQryNetworkInfo.HostName is '主机名称';
	comment on column t_RspQryNetworkInfo.MonDate is '采集的日期';
	comment on column t_RspQryNetworkInfo.MonTime is '采集的时间';
	comment on column t_RspQryNetworkInfo.LANNAME is '网卡名';
	comment on column t_RspQryNetworkInfo.LANSTATUS is '网卡的up或down状态';
	comment on column t_RspQryNetworkInfo.IPADDRESS is '网卡的ip地址';
	comment on column t_RspQryNetworkInfo.RECVBYTES is '网卡接收的流量';
	comment on column t_RspQryNetworkInfo.RECVPACKETS is '网卡接收的数据包';
	comment on column t_RspQryNetworkInfo.RECVERRORPACKETS is '网卡接收端错误数据包';
	comment on column t_RspQryNetworkInfo.RECVDROPPACKETS is '网卡接收端丢失数据包';
	comment on column t_RspQryNetworkInfo.SENDBYTES is '网卡发送的流量';
	comment on column t_RspQryNetworkInfo.SENDPACKETS is '网卡发送的数据包';
	comment on column t_RspQryNetworkInfo.SENDERRORPACKETS is '网卡发送端错误数据包';
	comment on column t_RspQryNetworkInfo.SENDDROPPACKETS is '网卡发送端丢失数据包';


--******************************
--创建历史峰值信息表表
--******************************
create table t_SysHistoryTradePeak
(
	ObjectID varchar2(64) not null
	,MonDate char(8) 
	,MonTime char(8) 
	,AttrType varchar2(64) not null
	,AttrValue number(19,3) 
	,RltAttrType varchar2(64) not null
	,RltAttrValue number(19,3) 
	,MaxMonDate char(8) 
	,MaxMonTime char(8) 
	,MaxAttrValue number(19,3) 
	,MaxRltAttrValue number(19,3) 
	,OldMonDate char(8) 
	,OldMonTime char(8) 
	,OldAttrValue number(19,3) 
	,OldRltAttrValue number(19,3) 
	,constraint pk_SysHistoryTradePeak primary key (ObjectID,AttrType,RltAttrType)
);

comment on table t_SysHistoryTradePeak is '历史峰值信息表';
	comment on column t_SysHistoryTradePeak.ObjectID is '监控对象';
	comment on column t_SysHistoryTradePeak.MonDate is '监控最新日期';
	comment on column t_SysHistoryTradePeak.MonTime is '监控最新时间';
	comment on column t_SysHistoryTradePeak.AttrType is '监控指标';
	comment on column t_SysHistoryTradePeak.AttrValue is '监控最新值';
	comment on column t_SysHistoryTradePeak.RltAttrType is '相关指标';
	comment on column t_SysHistoryTradePeak.RltAttrValue is '相关指标当时的值';
	comment on column t_SysHistoryTradePeak.MaxMonDate is '最大值的日期';
	comment on column t_SysHistoryTradePeak.MaxMonTime is '最大值的时间';
	comment on column t_SysHistoryTradePeak.MaxAttrValue is '指标历史最大值';
	comment on column t_SysHistoryTradePeak.MaxRltAttrValue is '相关指标当时的值';
	comment on column t_SysHistoryTradePeak.OldMonDate is '次新值的日期';
	comment on column t_SysHistoryTradePeak.OldMonTime is '次新值的时间';
	comment on column t_SysHistoryTradePeak.OldAttrValue is '监控指标的次新值';
	comment on column t_SysHistoryTradePeak.OldRltAttrValue is '相关指标当时的值';


--******************************
--创建网络设备表
--******************************
create table t_SysNetDevice
(
	ID number(10) not null
	,ObjectID varchar2(128) 
	,MonitorType_ID number(10) 
	,SysNetSubAreaID number(10) 
	,CATEGORY_ID number(10) 
	,FuctionArea varchar2(64) 
	,IPADDR char(15) 
	,IPDECODE number(10) 
	,NAME varchar2(128) 
	,PORTNUMBER number(10) 
	,CONFIGFILE varchar2(64) 
	,RCOMMUNITY varchar2(64) 
	,SNMPVERSION number(10) 
	,RAMSIZE number(10) 
	,FLASHSIZE number(10) 
	,NVRAMSIZE number(10) 
	,CABINET_ID number(10) 
	,ROOM_ID number(10) 
	,IOSVERSION_ID number(10) 
	,DESCRIPTION varchar2(256) 
	,USERNAME varchar2(64) 
	,PASSWD varchar2(256) 
	,ENPASSWD varchar2(256) 
	,MANUFACTORY_ID number(10) 
	,CFGSAVETYPE number(10) 
	,DEVICETYPE varchar2(128) 
	,SENDSMS number(10) 
	,ISSNMP number(10) 
	,SLOTNUM number(10) 
	,ISPING number(10) 
	,IFNUM number(10) 
	,APPLICATION_ID number(10) 
	,constraint pk_SysNetDevice primary key (ID)
);

comment on table t_SysNetDevice is '网络设备';
	comment on column t_SysNetDevice.ID is 'ID';
	comment on column t_SysNetDevice.ObjectID is '监控对象';
	comment on column t_SysNetDevice.MonitorType_ID is '监控对象类型';
	comment on column t_SysNetDevice.SysNetSubAreaID is 'SysNetSubAreaID';
	comment on column t_SysNetDevice.CATEGORY_ID is '分类ID  ';
	comment on column t_SysNetDevice.FuctionArea is '人为划分的职能区域  ';
	comment on column t_SysNetDevice.IPADDR is 'IP地址  ';
	comment on column t_SysNetDevice.IPDECODE is 'IP码    ';
	comment on column t_SysNetDevice.NAME is '设备名称 ';
	comment on column t_SysNetDevice.PORTNUMBER is '             ';
	comment on column t_SysNetDevice.CONFIGFILE is '          ';
	comment on column t_SysNetDevice.RCOMMUNITY is '共同体名  ';
	comment on column t_SysNetDevice.SNMPVERSION is 'snmp版本     ';
	comment on column t_SysNetDevice.RAMSIZE is 'ramsize(B)   ';
	comment on column t_SysNetDevice.FLASHSIZE is 'falshsize(B) ';
	comment on column t_SysNetDevice.NVRAMSIZE is 'nvramsize(B) ';
	comment on column t_SysNetDevice.CABINET_ID is '所属机柜';
	comment on column t_SysNetDevice.ROOM_ID is '';
	comment on column t_SysNetDevice.IOSVERSION_ID is '软件版本';
	comment on column t_SysNetDevice.DESCRIPTION is '系统描述';
	comment on column t_SysNetDevice.USERNAME is '登录用户名';
	comment on column t_SysNetDevice.PASSWD is '登录密码';
	comment on column t_SysNetDevice.ENPASSWD is 'enable密码';
	comment on column t_SysNetDevice.MANUFACTORY_ID is '厂商类型';
	comment on column t_SysNetDevice.CFGSAVETYPE is '配置备份协议';
	comment on column t_SysNetDevice.DEVICETYPE is '设备型号';
	comment on column t_SysNetDevice.SENDSMS is '是否短信告警';
	comment on column t_SysNetDevice.ISSNMP is '是否自动snmp探测';
	comment on column t_SysNetDevice.SLOTNUM is '槽位数';
	comment on column t_SysNetDevice.ISPING is '是否自动ping';
	comment on column t_SysNetDevice.IFNUM is '端口数量';
	comment on column t_SysNetDevice.APPLICATION_ID is '巡检分区';


--******************************
--创建网络设备连接关系表
--******************************
create table t_SysNetDeviceLinked
(
	ID number(10) not null
	,NetDeviceID number(10) 
	,NetPortID number(10) 
	,NetObjectID varchar2(128) 
	,NetPortType varchar2(64) 
	,LinkNetDeviceID number(10) 
	,LinkNetPortID number(10) 
	,LinkNetObjectID varchar2(128) 
	,LinkNetPortType varchar2(64) 
	,LinkSource number(10) 
	,constraint pk_SysNetDeviceLinked primary key (ID)
);

comment on table t_SysNetDeviceLinked is '网络设备连接关系';
	comment on column t_SysNetDeviceLinked.ID is 'ID';
	comment on column t_SysNetDeviceLinked.NetDeviceID is '设备ID';
	comment on column t_SysNetDeviceLinked.NetPortID is '设备端口ID';
	comment on column t_SysNetDeviceLinked.NetObjectID is '监控对象';
	comment on column t_SysNetDeviceLinked.NetPortType is '监控对象端口类型';
	comment on column t_SysNetDeviceLinked.LinkNetDeviceID is '连接设备ID';
	comment on column t_SysNetDeviceLinked.LinkNetPortID is '连接设备端口ID';
	comment on column t_SysNetDeviceLinked.LinkNetObjectID is '连接对象';
	comment on column t_SysNetDeviceLinked.LinkNetPortType is '连接对象端口类型';
	comment on column t_SysNetDeviceLinked.LinkSource is '链接来源';


--******************************
--创建网络大区划分表
--******************************
create table t_SysNetArea
(
	ID number(10) not null
	,CName varchar2(64) 
	,EName varchar2(64) 
	,constraint pk_SysNetArea primary key (ID)
);

comment on table t_SysNetArea is '网络大区划分';
	comment on column t_SysNetArea.ID is 'ID';
	comment on column t_SysNetArea.CName is '区域中文名';
	comment on column t_SysNetArea.EName is '区域英文名';


--******************************
--创建网络子区表
--******************************
create table t_SysNetSubArea
(
	ID number(10) not null
	,SysNetAreaID number(10) 
	,CName varchar2(64) 
	,EName varchar2(64) 
	,constraint pk_SysNetSubArea primary key (ID)
);

comment on table t_SysNetSubArea is '网络子区';
	comment on column t_SysNetSubArea.ID is 'ID';
	comment on column t_SysNetSubArea.SysNetAreaID is 'SysNetArea';
	comment on column t_SysNetSubArea.CName is '区域中文名';
	comment on column t_SysNetSubArea.EName is '区域英文名';


--******************************
--创建网络子区IP表
--******************************
create table t_SysNetSubAreaIP
(
	ID number(10) not null
	,SysNetSubAreaID number(10) 
	,IP char(15) 
	,Mask char(15) 
	,constraint pk_SysNetSubAreaIP primary key (ID)
);

comment on table t_SysNetSubAreaIP is '网络子区IP';
	comment on column t_SysNetSubAreaIP.ID is 'ID';
	comment on column t_SysNetSubAreaIP.SysNetSubAreaID is 'SysNetSubAreaID';
	comment on column t_SysNetSubAreaIP.IP is 'ip地址';
	comment on column t_SysNetSubAreaIP.Mask is '掩码';


--******************************
--创建大楼表
--******************************
create table t_SysNetBuilding
(
	ID number(10) not null
	,CName varchar2(64) 
	,EName varchar2(64) 
	,constraint pk_SysNetBuilding primary key (ID)
);

comment on table t_SysNetBuilding is '大楼';
	comment on column t_SysNetBuilding.ID is 'ID';
	comment on column t_SysNetBuilding.CName is '区域中文名';
	comment on column t_SysNetBuilding.EName is '区域英文名';


--******************************
--创建机房表
--******************************
create table t_SysNetRoom
(
	ID number(10) not null
	,SysNetBuildingID number(10) 
	,CName varchar2(64) 
	,EName varchar2(64) 
	,constraint pk_SysNetRoom primary key (ID)
);

comment on table t_SysNetRoom is '机房';
	comment on column t_SysNetRoom.ID is 'ID';
	comment on column t_SysNetRoom.SysNetBuildingID is '大楼';
	comment on column t_SysNetRoom.CName is '机房中文名';
	comment on column t_SysNetRoom.EName is '机房英文名';


--******************************
--创建机柜表
--******************************
create table t_SysNetCabinets
(
	ID number(10) not null
	,SysNetRoomID number(10) 
	,SysNetBuildingID number(10) 
	,CName varchar2(64) 
	,EName varchar2(64) 
	,CabinetsType varchar2(64) 
	,constraint pk_SysNetCabinets primary key (ID)
);

comment on table t_SysNetCabinets is '机柜';
	comment on column t_SysNetCabinets.ID is 'ID';
	comment on column t_SysNetCabinets.SysNetRoomID is 'SysNetRoomID';
	comment on column t_SysNetCabinets.SysNetBuildingID is 'SysNetBuildingID';
	comment on column t_SysNetCabinets.CName is '机房中文名';
	comment on column t_SysNetCabinets.EName is '机房英文名';
	comment on column t_SysNetCabinets.CabinetsType is '机柜类型';


--******************************
--创建网络设备类型表
--******************************
create table t_SysNetDeviceType
(
	ID number(10) not null
	,Manufactory varchar2(64) 
	,DeviceType varchar2(64) 
	,constraint pk_SysNetDeviceType primary key (ID)
);

comment on table t_SysNetDeviceType is '网络设备类型';
	comment on column t_SysNetDeviceType.ID is 'ID';
	comment on column t_SysNetDeviceType.Manufactory is '生产商名';
	comment on column t_SysNetDeviceType.DeviceType is '设备型号';


--******************************
--创建OID表
--******************************
create table t_SysNetOID
(
	ID number(10) not null
	,Manufactory varchar2(64) 
	,DeviceType varchar2(64) 
	,CName varchar2(64) 
	,EName varchar2(64) 
	,OID varchar2(64) 
	,Unit varchar2(64) 
	,isTheTable number(10) 
	,constraint pk_SysNetOID primary key (ID)
);

comment on table t_SysNetOID is 'OID';
	comment on column t_SysNetOID.ID is 'ID';
	comment on column t_SysNetOID.Manufactory is '生产商名';
	comment on column t_SysNetOID.DeviceType is '设备型号';
	comment on column t_SysNetOID.CName is 'OID中文名';
	comment on column t_SysNetOID.EName is 'OID英文名';
	comment on column t_SysNetOID.OID is 'OID';
	comment on column t_SysNetOID.Unit is '单位';
	comment on column t_SysNetOID.isTheTable is '是否标量标志';


--******************************
--创建时间策略表
--******************************
create table t_SysNetTimePolicy
(
	ID number(10) not null
	,CName varchar2(64) 
	,EName varchar2(64) 
	,PolicyType number(10) 
	,PolicyString varchar2(512) 
	,TradingDay number(10) 
	,Description varchar2(256) 
	,Operation number(10) 
	,constraint pk_SysNetTimePolicy primary key (ID)
);

comment on table t_SysNetTimePolicy is '时间策略';
	comment on column t_SysNetTimePolicy.ID is 'ID';
	comment on column t_SysNetTimePolicy.CName is '时间策略中文名';
	comment on column t_SysNetTimePolicy.EName is '时间策略英文名';
	comment on column t_SysNetTimePolicy.PolicyType is '策略类型';
	comment on column t_SysNetTimePolicy.PolicyString is '策略项配置串';
	comment on column t_SysNetTimePolicy.TradingDay is '交易日限制';
	comment on column t_SysNetTimePolicy.Description is '策略项描述';
	comment on column t_SysNetTimePolicy.Operation is '操作类型';


--******************************
--创建采集任务表
--******************************
create table t_SysNetGatherTask
(
	ID number(10) not null
	,ObjectID varchar2(128) 
	,AttrType varchar2(256) 
	,PolicyTypeID number(10) 
	,DataType number(10) 
	,TypeFlag number(10) 
	,constraint pk_SysNetGatherTask primary key (ID)
);

comment on table t_SysNetGatherTask is '采集任务';
	comment on column t_SysNetGatherTask.ID is 'ID';
	comment on column t_SysNetGatherTask.ObjectID is '网络监控对象ID';
	comment on column t_SysNetGatherTask.AttrType is '网络监控指标类型';
	comment on column t_SysNetGatherTask.PolicyTypeID is '时间策略ID';
	comment on column t_SysNetGatherTask.DataType is '返回类型';
	comment on column t_SysNetGatherTask.TypeFlag is '类型标识';


--******************************
--创建常用设备类别表
--******************************
create table t_SysNetDeviceCategory
(
	ID number(10) not null
	,CName varchar2(64) 
	,EName varchar2(64) 
	,constraint pk_SysNetDeviceCategory primary key (ID)
);

comment on table t_SysNetDeviceCategory is '常用设备类别';
	comment on column t_SysNetDeviceCategory.ID is 'ID';
	comment on column t_SysNetDeviceCategory.CName is '类别中文名';
	comment on column t_SysNetDeviceCategory.EName is '类别英文名';


--******************************
--创建设备厂商表
--******************************
create table t_SysNetManufactory
(
	ID number(10) not null
	,CName varchar2(64) 
	,EName varchar2(64) 
	,constraint pk_SysNetManufactory primary key (ID)
);

comment on table t_SysNetManufactory is '设备厂商';
	comment on column t_SysNetManufactory.ID is 'ID';
	comment on column t_SysNetManufactory.CName is '厂商中文名';
	comment on column t_SysNetManufactory.EName is '厂商英文名';


--******************************
--创建设备共同体表
--******************************
create table t_SysNetCommunity
(
	ID number(10) not null
	,IPADDR char(15) 
	,COMMUNITY varchar2(64) 
	,constraint pk_SysNetCommunity primary key (ID)
);

comment on table t_SysNetCommunity is '设备共同体';
	comment on column t_SysNetCommunity.ID is 'ID';
	comment on column t_SysNetCommunity.IPADDR is 'IP地址';
	comment on column t_SysNetCommunity.COMMUNITY is '共同体名';


--******************************
--创建端口类型表
--******************************
create table t_SysNetPortType
(
	ID number(10) not null
	,CName varchar2(64) 
	,EName varchar2(64) 
	,Description varchar2(64) 
	,constraint pk_SysNetPortType primary key (ID)
);

comment on table t_SysNetPortType is '端口类型';
	comment on column t_SysNetPortType.ID is 'ID';
	comment on column t_SysNetPortType.CName is '中文名';
	comment on column t_SysNetPortType.EName is '英文名';
	comment on column t_SysNetPortType.Description is '描述';


--******************************
--创建端口表
--******************************
create table t_SysNetInterface
(
	ID number(10) not null
	,ObjectID varchar2(128) 
	,MonitorType_ID number(10) 
	,IfType number(10) 
	,EName varchar2(64) 
	,IpAddress char(15) 
	,IpMask char(15) 
	,IfStatus number(10) 
	,MAC varchar2(64) 
	,DeviceID number(10) 
	,DeviceObjectID varchar2(128) 
	,DeviceIndex varchar2(16) 
	,isPolling number(10) 
	,Description varchar2(64) 
	,constraint pk_SysNetInterface primary key (ID)
);

comment on table t_SysNetInterface is '端口';
	comment on column t_SysNetInterface.ID is 'ID';
	comment on column t_SysNetInterface.ObjectID is '监控对象';
	comment on column t_SysNetInterface.MonitorType_ID is '监控对象类型';
	comment on column t_SysNetInterface.IfType is '端口类型';
	comment on column t_SysNetInterface.EName is '端口名';
	comment on column t_SysNetInterface.IpAddress is 'IP地址';
	comment on column t_SysNetInterface.IpMask is '掩码';
	comment on column t_SysNetInterface.IfStatus is '端口状态';
	comment on column t_SysNetInterface.MAC is '物理地址';
	comment on column t_SysNetInterface.DeviceID is '所属设备ID';
	comment on column t_SysNetInterface.DeviceObjectID is '所属设备ObjectID';
	comment on column t_SysNetInterface.DeviceIndex is '所属设备端口索引';
	comment on column t_SysNetInterface.isPolling is '是否轮询';
	comment on column t_SysNetInterface.Description is '描述';


--******************************
--创建通用OID表
--******************************
create table t_SysNetGeneralOID
(
	ID number(10) not null
	,CName varchar2(64) 
	,EName varchar2(64) 
	,OID varchar2(64) 
	,Unit varchar2(64) 
	,isTheTable number(10) 
	,constraint pk_SysNetGeneralOID primary key (ID)
);

comment on table t_SysNetGeneralOID is '通用OID';
	comment on column t_SysNetGeneralOID.ID is 'ID';
	comment on column t_SysNetGeneralOID.CName is 'OID中文名';
	comment on column t_SysNetGeneralOID.EName is 'OID英文名';
	comment on column t_SysNetGeneralOID.OID is 'OID';
	comment on column t_SysNetGeneralOID.Unit is '单位';
	comment on column t_SysNetGeneralOID.isTheTable is '是否标量标志';


--******************************
--创建监控对象类别表
--******************************
create table t_SysNetMonitorType
(
	ID number(10) not null
	,CName varchar2(64) 
	,EName varchar2(64) 
	,constraint pk_SysNetMonitorType primary key (ID)
);

comment on table t_SysNetMonitorType is '监控对象类别';
	comment on column t_SysNetMonitorType.ID is 'ID';
	comment on column t_SysNetMonitorType.CName is 'OID中文名';
	comment on column t_SysNetMonitorType.EName is 'OID英文名';


--******************************
--创建指标统表表
--******************************
create table t_SysNetMonitorAttrScope
(
	ID number(10) not null
	,CName varchar2(256) 
	,EName varchar2(256) 
	,Comments varchar2(256) 
	,constraint pk_SysNetMonitorAttrScope primary key (ID)
);

comment on table t_SysNetMonitorAttrScope is '指标统表';
	comment on column t_SysNetMonitorAttrScope.ID is 'ID';
	comment on column t_SysNetMonitorAttrScope.CName is '指标中文名';
	comment on column t_SysNetMonitorAttrScope.EName is '指标英文名';
	comment on column t_SysNetMonitorAttrScope.Comments is '注释';


--******************************
--创建监控指标表表
--******************************
create table t_SysNetMonitorAttrType
(
	ID number(10) not null
	,MANUFACTORY_ID number(10) 
	,MonitorType_ID number(10) 
	,AttrType_ID number(10) 
	,MANUFACTORY varchar2(64) 
	,MonitorType varchar2(64) 
	,AttrType varchar2(256) 
	,constraint pk_SysNetMonitorAttrType primary key (ID)
);

comment on table t_SysNetMonitorAttrType is '监控指标表';
	comment on column t_SysNetMonitorAttrType.ID is 'ID';
	comment on column t_SysNetMonitorAttrType.MANUFACTORY_ID is '厂商类型';
	comment on column t_SysNetMonitorAttrType.MonitorType_ID is '设备类别';
	comment on column t_SysNetMonitorAttrType.AttrType_ID is '网络监控指标ID';
	comment on column t_SysNetMonitorAttrType.MANUFACTORY is '厂商类型';
	comment on column t_SysNetMonitorAttrType.MonitorType is '设备类别';
	comment on column t_SysNetMonitorAttrType.AttrType is '网络监控指标';


--******************************
--创建职能区表
--******************************
create table t_SysNetFuncArea
(
	ID number(10) not null
	,SysNetSubAreaID number(10) 
	,CName varchar2(64) 
	,EName varchar2(64) 
	,constraint pk_SysNetFuncArea primary key (ID)
);

comment on table t_SysNetFuncArea is '职能区';
	comment on column t_SysNetFuncArea.ID is 'ID';
	comment on column t_SysNetFuncArea.SysNetSubAreaID is 'SysNetSubAreaID';
	comment on column t_SysNetFuncArea.CName is '区域中文名';
	comment on column t_SysNetFuncArea.EName is '区域英文名';


--******************************
--创建监控指令表表
--******************************
create table t_SysNetMonitorCommandType
(
	ID number(10) not null
	,Manufactory_ID number(10) 
	,MonitorType_ID number(10) 
	,DeviceModle_ID number(10) 
	,ActionGroup_ID number(10) 
	,Manufactory varchar2(64) 
	,MonitorType varchar2(64) 
	,DeviceModle varchar2(64) 
	,ActionGroup varchar2(64) 
	,Command varchar2(256) 
	,constraint pk_SysNetMonitorCommandType primary key (ID)
);

comment on table t_SysNetMonitorCommandType is '监控指令表';
	comment on column t_SysNetMonitorCommandType.ID is 'ID';
	comment on column t_SysNetMonitorCommandType.Manufactory_ID is '厂商类型ID';
	comment on column t_SysNetMonitorCommandType.MonitorType_ID is '设备类别ID';
	comment on column t_SysNetMonitorCommandType.DeviceModle_ID is '设备型号ID';
	comment on column t_SysNetMonitorCommandType.ActionGroup_ID is '动作族ID';
	comment on column t_SysNetMonitorCommandType.Manufactory is '厂商类型';
	comment on column t_SysNetMonitorCommandType.MonitorType is '设备类别';
	comment on column t_SysNetMonitorCommandType.DeviceModle is '设备型号';
	comment on column t_SysNetMonitorCommandType.ActionGroup is '动作族';
	comment on column t_SysNetMonitorCommandType.Command is '指令码';


--******************************
--创建动作族表表
--******************************
create table t_SysNetMonitorActionGroup
(
	ID number(10) not null
	,CName varchar2(64) 
	,EName varchar2(64) 
	,ActionType number(10) 
	,Comments varchar2(256) 
	,constraint pk_SysNetMonitorActionGroup primary key (ID)
);

comment on table t_SysNetMonitorActionGroup is '动作族表';
	comment on column t_SysNetMonitorActionGroup.ID is 'ID';
	comment on column t_SysNetMonitorActionGroup.CName is '动作族中文名';
	comment on column t_SysNetMonitorActionGroup.EName is '动作族英文名';
	comment on column t_SysNetMonitorActionGroup.ActionType is '动作类型码';
	comment on column t_SysNetMonitorActionGroup.Comments is '注释';


--******************************
--创建设备对象组表表
--******************************
create table t_SysNetMonitorDeviceGroup
(
	ID number(10) not null
	,CName varchar2(64) 
	,EName varchar2(64) 
	,Condition varchar2(512) 
	,Comments varchar2(256) 
	,constraint pk_SysNetMonitorDeviceGroup primary key (ID)
);

comment on table t_SysNetMonitorDeviceGroup is '设备对象组表';
	comment on column t_SysNetMonitorDeviceGroup.ID is 'ID';
	comment on column t_SysNetMonitorDeviceGroup.CName is '设备对象组中文名';
	comment on column t_SysNetMonitorDeviceGroup.EName is '设备对象组英文名';
	comment on column t_SysNetMonitorDeviceGroup.Condition is '设备过滤条件';
	comment on column t_SysNetMonitorDeviceGroup.Comments is '注释';


--******************************
--创建任务信息表表
--******************************
create table t_SysNetMonitorTaskInfo
(
	ID number(10) not null
	,CName varchar2(64) 
	,EName varchar2(64) 
	,DeviceGroup_ID number(10) 
	,ManagerGroup_ID number(10) 
	,TimePolicy_ID number(10) 
	,TaskPriority_ID number(10) 
	,OutputPolicy_ID number(10) 
	,ActionGroup_ID number(10) 
	,EventExprStr varchar2(1024) 
	,DeviceGroup varchar2(64) 
	,ManagerGroup varchar2(64) 
	,TimePolicy varchar2(64) 
	,TaskPriority varchar2(64) 
	,OutputPolicy varchar2(64) 
	,ActionGroup varchar2(64) 
	,ValidFlag number(10) 
	,TaskStatus number(10) 
	,Comments varchar2(256) 
	,constraint pk_SysNetMonitorTaskInfo primary key (ID)
);

comment on table t_SysNetMonitorTaskInfo is '任务信息表';
	comment on column t_SysNetMonitorTaskInfo.ID is 'ID';
	comment on column t_SysNetMonitorTaskInfo.CName is '任务中文名';
	comment on column t_SysNetMonitorTaskInfo.EName is '任务英文名';
	comment on column t_SysNetMonitorTaskInfo.DeviceGroup_ID is '设备对象组ID';
	comment on column t_SysNetMonitorTaskInfo.ManagerGroup_ID is '管理人员对象组ID';
	comment on column t_SysNetMonitorTaskInfo.TimePolicy_ID is '任务时间策略ID';
	comment on column t_SysNetMonitorTaskInfo.TaskPriority_ID is '任务优先级ID';
	comment on column t_SysNetMonitorTaskInfo.OutputPolicy_ID is '结果输出策略ID';
	comment on column t_SysNetMonitorTaskInfo.ActionGroup_ID is '任务动作族ID';
	comment on column t_SysNetMonitorTaskInfo.EventExprStr is '任务表达式ID联合串';
	comment on column t_SysNetMonitorTaskInfo.DeviceGroup is '设备对象组';
	comment on column t_SysNetMonitorTaskInfo.ManagerGroup is '管理人员对象组';
	comment on column t_SysNetMonitorTaskInfo.TimePolicy is '任务时间策略';
	comment on column t_SysNetMonitorTaskInfo.TaskPriority is '任务优先级';
	comment on column t_SysNetMonitorTaskInfo.OutputPolicy is '结果输出策略';
	comment on column t_SysNetMonitorTaskInfo.ActionGroup is '任务动作族';
	comment on column t_SysNetMonitorTaskInfo.ValidFlag is '任务有效性标识';
	comment on column t_SysNetMonitorTaskInfo.TaskStatus is '任务状态标识';
	comment on column t_SysNetMonitorTaskInfo.Comments is '任务描述';


--******************************
--创建会员链路信息表表
--******************************
create table t_SysNetPartyLinkInfo
(
	ID number(10) not null
	,MEMBER_NO varchar2(32) 
	,MEMBER_NAME varchar2(64) 
	,REMOTE_ADDR varchar2(64) 
	,LOCAL_ADDR varchar2(64) 
	,ADDRESS varchar2(256) 
	,LINE_STATUS varchar2(32) 
	,CONTACT varchar2(32) 
	,TELEPHONE varchar2(64) 
	,MOBILEPHONE varchar2(64) 
	,EMAIL varchar2(64) 
	,FAX varchar2(64) 
	,PROVINCE varchar2(32) 
	,DDN_NO varchar2(64) 
	,IN_MODE varchar2(64) 
	,IP_WAN varchar2(64) 
	,IP_LAN varchar2(64) 
	,IPADDR varchar2(64) 
	,Interface varchar2(64) 
	,INTERFACE_DATE varchar2(32) 
	,SOFTWARE varchar2(32) 
	,FEE_TYPE varchar2(32) 
	,SERVICEPROVIDER varchar2(32) 
	,IF_ZIYING varchar2(32) 
	,IF_TUOGUAN varchar2(32) 
	,HASOTHER varchar2(32) 
	,SEAT_NO varchar2(1024) 
	,PRO varchar2(512) 
	,constraint pk_SysNetPartyLinkInfo primary key (ID)
);

comment on table t_SysNetPartyLinkInfo is '会员链路信息表';
	comment on column t_SysNetPartyLinkInfo.ID is 'ID';
	comment on column t_SysNetPartyLinkInfo.MEMBER_NO is '会员号';
	comment on column t_SysNetPartyLinkInfo.MEMBER_NAME is '会员名称';
	comment on column t_SysNetPartyLinkInfo.REMOTE_ADDR is '会员接入地点';
	comment on column t_SysNetPartyLinkInfo.LOCAL_ADDR is '上期所接入点';
	comment on column t_SysNetPartyLinkInfo.ADDRESS is '地址';
	comment on column t_SysNetPartyLinkInfo.LINE_STATUS is '线路状态';
	comment on column t_SysNetPartyLinkInfo.CONTACT is '联系人';
	comment on column t_SysNetPartyLinkInfo.TELEPHONE is '联系电话';
	comment on column t_SysNetPartyLinkInfo.MOBILEPHONE is '手机号';
	comment on column t_SysNetPartyLinkInfo.EMAIL is 'EMAIL';
	comment on column t_SysNetPartyLinkInfo.FAX is '传真';
	comment on column t_SysNetPartyLinkInfo.PROVINCE is '所属省份';
	comment on column t_SysNetPartyLinkInfo.DDN_NO is '线路编号';
	comment on column t_SysNetPartyLinkInfo.IN_MODE is '接入方式';
	comment on column t_SysNetPartyLinkInfo.IP_WAN is '入网IP广域';
	comment on column t_SysNetPartyLinkInfo.IP_LAN is '入网IP局域';
	comment on column t_SysNetPartyLinkInfo.IPADDR is '路由器网管IP';
	comment on column t_SysNetPartyLinkInfo.Interface is '路由器端口号';
	comment on column t_SysNetPartyLinkInfo.INTERFACE_DATE is '接口开通日期';
	comment on column t_SysNetPartyLinkInfo.SOFTWARE is '所用软件';
	comment on column t_SysNetPartyLinkInfo.FEE_TYPE is '付费类型';
	comment on column t_SysNetPartyLinkInfo.SERVICEPROVIDER is '运营商';
	comment on column t_SysNetPartyLinkInfo.IF_ZIYING is '是否自营';
	comment on column t_SysNetPartyLinkInfo.IF_TUOGUAN is '是否托管';
	comment on column t_SysNetPartyLinkInfo.HASOTHER is '有无他所线路';
	comment on column t_SysNetPartyLinkInfo.SEAT_NO is '席位号';
	comment on column t_SysNetPartyLinkInfo.PRO is '备注';


--******************************
--创建会员链路信息表表
--******************************
create table t_SysNetDelPartyLinkInfo
(
	ID number(10) not null
	,MEMBER_NO varchar2(32) 
	,MEMBER_NAME varchar2(64) 
	,REMOTE_ADDR varchar2(64) 
	,LOCAL_ADDR varchar2(64) 
	,ADDRESS varchar2(256) 
	,LINE_STATUS varchar2(32) 
	,CONTACT varchar2(32) 
	,TELEPHONE varchar2(64) 
	,MOBILEPHONE varchar2(64) 
	,EMAIL varchar2(64) 
	,FAX varchar2(64) 
	,PROVINCE varchar2(32) 
	,DDN_NO varchar2(64) 
	,IN_MODE varchar2(64) 
	,IP_WAN varchar2(64) 
	,IP_LAN varchar2(64) 
	,IPADDR varchar2(64) 
	,Interface varchar2(64) 
	,INTERFACE_DATE varchar2(32) 
	,SOFTWARE varchar2(32) 
	,FEE_TYPE varchar2(32) 
	,SERVICEPROVIDER varchar2(32) 
	,IF_ZIYING varchar2(32) 
	,IF_TUOGUAN varchar2(32) 
	,HASOTHER varchar2(32) 
	,SEAT_NO varchar2(1024) 
	,PRO varchar2(512) 
	,constraint pk_SysNetDelPartyLinkInfo primary key (ID)
);

comment on table t_SysNetDelPartyLinkInfo is '会员链路信息表';
	comment on column t_SysNetDelPartyLinkInfo.ID is 'ID';
	comment on column t_SysNetDelPartyLinkInfo.MEMBER_NO is '会员号';
	comment on column t_SysNetDelPartyLinkInfo.MEMBER_NAME is '会员名称';
	comment on column t_SysNetDelPartyLinkInfo.REMOTE_ADDR is '会员接入地点';
	comment on column t_SysNetDelPartyLinkInfo.LOCAL_ADDR is '上期所接入点';
	comment on column t_SysNetDelPartyLinkInfo.ADDRESS is '地址';
	comment on column t_SysNetDelPartyLinkInfo.LINE_STATUS is '线路状态';
	comment on column t_SysNetDelPartyLinkInfo.CONTACT is '联系人';
	comment on column t_SysNetDelPartyLinkInfo.TELEPHONE is '联系电话';
	comment on column t_SysNetDelPartyLinkInfo.MOBILEPHONE is '手机号';
	comment on column t_SysNetDelPartyLinkInfo.EMAIL is 'EMAIL';
	comment on column t_SysNetDelPartyLinkInfo.FAX is '传真';
	comment on column t_SysNetDelPartyLinkInfo.PROVINCE is '所属省份';
	comment on column t_SysNetDelPartyLinkInfo.DDN_NO is '线路编号';
	comment on column t_SysNetDelPartyLinkInfo.IN_MODE is '接入方式';
	comment on column t_SysNetDelPartyLinkInfo.IP_WAN is '入网IP广域';
	comment on column t_SysNetDelPartyLinkInfo.IP_LAN is '入网IP局域';
	comment on column t_SysNetDelPartyLinkInfo.IPADDR is '路由器网管IP';
	comment on column t_SysNetDelPartyLinkInfo.Interface is '路由器端口号';
	comment on column t_SysNetDelPartyLinkInfo.INTERFACE_DATE is '接口开通日期';
	comment on column t_SysNetDelPartyLinkInfo.SOFTWARE is '所用软件';
	comment on column t_SysNetDelPartyLinkInfo.FEE_TYPE is '付费类型';
	comment on column t_SysNetDelPartyLinkInfo.SERVICEPROVIDER is '运营商';
	comment on column t_SysNetDelPartyLinkInfo.IF_ZIYING is '是否自营';
	comment on column t_SysNetDelPartyLinkInfo.IF_TUOGUAN is '是否托管';
	comment on column t_SysNetDelPartyLinkInfo.HASOTHER is '有无他所线路';
	comment on column t_SysNetDelPartyLinkInfo.SEAT_NO is '席位号';
	comment on column t_SysNetDelPartyLinkInfo.PRO is '备注';


--******************************
--创建会员链路信息表表
--******************************
create table t_SysNetPartyLinkAddrChange
(
	ID number(10) not null
	,RelationID number(10) not null
	,OLDADDRESS varchar2(256) 
	,NEWADDRESS varchar2(256) 
	,OPERATOR varchar2(32) 
	,MonDate char(8) 
	,MonTime char(8) 
	,constraint pk_SysNetPartyLinkAddrChange primary key (ID)
);

comment on table t_SysNetPartyLinkAddrChange is '会员链路信息表';
	comment on column t_SysNetPartyLinkAddrChange.ID is 'ID';
	comment on column t_SysNetPartyLinkAddrChange.RelationID is 'ID';
	comment on column t_SysNetPartyLinkAddrChange.OLDADDRESS is '变更前地址';
	comment on column t_SysNetPartyLinkAddrChange.NEWADDRESS is '变更后地址';
	comment on column t_SysNetPartyLinkAddrChange.OPERATOR is '操作人';
	comment on column t_SysNetPartyLinkAddrChange.MonDate is '修改日期';
	comment on column t_SysNetPartyLinkAddrChange.MonTime is '修改时间';


--******************************
--创建监控动作指标对照表表
--******************************
create table t_SysNetMonitorActionAttr
(
	ID number(10) not null
	,ActionGroup_ID number(10) 
	,MonitorAttr_ID number(10) 
	,MonitorAttrName varchar2(256) 
	,constraint pk_SysNetMonitorActionAttr primary key (ID)
);

comment on table t_SysNetMonitorActionAttr is '监控动作指标对照表';
	comment on column t_SysNetMonitorActionAttr.ID is 'ID';
	comment on column t_SysNetMonitorActionAttr.ActionGroup_ID is '动作族ID';
	comment on column t_SysNetMonitorActionAttr.MonitorAttr_ID is '监控对象ID';
	comment on column t_SysNetMonitorActionAttr.MonitorAttrName is '指标英文名';


--******************************
--创建模块表
--******************************
create table t_SysNetModule
(
	ID number(10) not null
	,ObjectID varchar2(128) 
	,MonitorType_ID number(10) 
	,DeviceID number(10) 
	,DeviceObjectID varchar2(128) 
	,Name varchar2(64) 
	,Description varchar2(128) 
	,ModuleIndex number(10) 
	,EntPhyIndex number(10) 
	,constraint pk_SysNetModule primary key (ID)
);

comment on table t_SysNetModule is '模块';
	comment on column t_SysNetModule.ID is 'ID';
	comment on column t_SysNetModule.ObjectID is '网络监控对象ID';
	comment on column t_SysNetModule.MonitorType_ID is '监控对象类型';
	comment on column t_SysNetModule.DeviceID is '所属设备ID';
	comment on column t_SysNetModule.DeviceObjectID is '所属设备ObjectID';
	comment on column t_SysNetModule.Name is '名字';
	comment on column t_SysNetModule.Description is '描述';
	comment on column t_SysNetModule.ModuleIndex is '模块索引';
	comment on column t_SysNetModule.EntPhyIndex is '物理索引';


--******************************
--创建告警表达式信息表表
--******************************
create table t_SysNetEventExpr
(
	ID number(10) not null
	,CNAME varchar2(128) 
	,ENAME varchar2(128) 
	,WarningLEVEL varchar2(32) 
	,EventTypeID number(10) 
	,SubEventTypeID number(10) 
	,GIVEUPTIME number(10) 
	,CONTROL varchar2(1024) 
	,EXPR varchar2(1024) 
	,BRIEF varchar2(64) 
	,DISCRIPTION varchar2(256) 
	,MSGGROUP_ID number(10) 
	,ADMINGROUP_ID number(10) 
	,constraint pk_SysNetEventExpr primary key (ID)
);

comment on table t_SysNetEventExpr is '告警表达式信息表';
	comment on column t_SysNetEventExpr.ID is 'ID';
	comment on column t_SysNetEventExpr.CNAME is '中文事件名';
	comment on column t_SysNetEventExpr.ENAME is '英文事件名';
	comment on column t_SysNetEventExpr.WarningLEVEL is '事件级别';
	comment on column t_SysNetEventExpr.EventTypeID is '事件类型';
	comment on column t_SysNetEventExpr.SubEventTypeID is '事件子类型';
	comment on column t_SysNetEventExpr.GIVEUPTIME is '告警间隔时间';
	comment on column t_SysNetEventExpr.CONTROL is '控制定义项';
	comment on column t_SysNetEventExpr.EXPR is '表达式定义项';
	comment on column t_SysNetEventExpr.BRIEF is '事件简述';
	comment on column t_SysNetEventExpr.DISCRIPTION is '事件描述项';
	comment on column t_SysNetEventExpr.MSGGROUP_ID is '消息组ID';
	comment on column t_SysNetEventExpr.ADMINGROUP_ID is '管理员组ID';


--******************************
--创建事件类型表
--******************************
create table t_SysNetEventType
(
	ID number(10) not null
	,CName varchar2(64) 
	,EName varchar2(64) 
	,constraint pk_SysNetEventType primary key (ID)
);

comment on table t_SysNetEventType is '事件类型';
	comment on column t_SysNetEventType.ID is 'ID';
	comment on column t_SysNetEventType.CName is '事件类型中文名';
	comment on column t_SysNetEventType.EName is '事件类型英文名';


--******************************
--创建事件子类型表
--******************************
create table t_SysNetSubEventType
(
	ID number(10) not null
	,CName varchar2(64) 
	,EName varchar2(64) 
	,constraint pk_SysNetSubEventType primary key (ID)
);

comment on table t_SysNetSubEventType is '事件子类型';
	comment on column t_SysNetSubEventType.ID is 'ID';
	comment on column t_SysNetSubEventType.CName is '事件子类型中文名';
	comment on column t_SysNetSubEventType.EName is '事件子类型英文名';


--******************************
--创建事件级别表
--******************************
create table t_SysNetEventLevel
(
	ID number(10) not null
	,CName varchar2(64) 
	,EName varchar2(64) 
	,DISCRIPTION varchar2(256) 
	,constraint pk_SysNetEventLevel primary key (ID)
);

comment on table t_SysNetEventLevel is '事件级别';
	comment on column t_SysNetEventLevel.ID is 'ID';
	comment on column t_SysNetEventLevel.CName is '事件级别中文名';
	comment on column t_SysNetEventLevel.EName is '事件级别英文名';
	comment on column t_SysNetEventLevel.DISCRIPTION is '事件级别描述项';


--******************************
--创建任务结果规则分析表表
--******************************
create table t_SysNetMonitorDeviceTask
(
	ID number(10) not null
	,ObjectID varchar2(128) 
	,IPAddress char(15) not null
	,Manufactory_ID number(10) 
	,InstructChain varchar2(256) 
	,InstructAlias varchar2(128) 
	,InstructArgs varchar2(256) 
	,DefParamChain varchar2(2000) 
	,Flag number(10) 
	,SecondID number(10) not null
	,constraint pk_SysNetMonitorDeviceTask primary key (ID,SecondID)
);

comment on table t_SysNetMonitorDeviceTask is '任务结果规则分析表';
	comment on column t_SysNetMonitorDeviceTask.ID is 'ID';
	comment on column t_SysNetMonitorDeviceTask.ObjectID is '网络监控对象ID';
	comment on column t_SysNetMonitorDeviceTask.IPAddress is 'IP地址';
	comment on column t_SysNetMonitorDeviceTask.Manufactory_ID is '网络设备产商ID';
	comment on column t_SysNetMonitorDeviceTask.InstructChain is '指令';
	comment on column t_SysNetMonitorDeviceTask.InstructAlias is '指令别名';
	comment on column t_SysNetMonitorDeviceTask.InstructArgs is '指令参数串';
	comment on column t_SysNetMonitorDeviceTask.DefParamChain is '指标阀值串';
	comment on column t_SysNetMonitorDeviceTask.Flag is '结束标志';
	comment on column t_SysNetMonitorDeviceTask.SecondID is 'PrimID';


--******************************
--创建任务指令指标集表表
--******************************
create table t_SysNetMonitorTaskInstAttrs
(
	ID number(10) not null
	,Manufactory_ID number(10) not null
	,InstructAlias varchar2(128) not null
	,DEVICETYPE varchar2(128) 
	,AttrsChain varchar2(256) 
	,DefRegularChain varchar2(512) 
	,DefParamChain varchar2(2000) 
	,constraint pk_SysNetMonitorTaskInstAttrs primary key (ID,Manufactory_ID,InstructAlias,DEVICETYPE)
);

comment on table t_SysNetMonitorTaskInstAttrs is '任务指令指标集表';
	comment on column t_SysNetMonitorTaskInstAttrs.ID is 'ID';
	comment on column t_SysNetMonitorTaskInstAttrs.Manufactory_ID is '网络设备产商ID';
	comment on column t_SysNetMonitorTaskInstAttrs.InstructAlias is '指令别名';
	comment on column t_SysNetMonitorTaskInstAttrs.DEVICETYPE is '设备型号';
	comment on column t_SysNetMonitorTaskInstAttrs.AttrsChain is '指标串';
	comment on column t_SysNetMonitorTaskInstAttrs.DefRegularChain is '指标规则串';
	comment on column t_SysNetMonitorTaskInstAttrs.DefParamChain is '指标阀值串';


--******************************
--创建任务结果表表
--******************************
create table t_SysNetMonitorTaskResult
(
	ObjectID varchar2(128) 
	,Task_ID number(10) 
	,OperateTime number(10) 
	,MonDate char(8) 
	,MonTime char(8) 
	,InstructChain varchar2(256) 
	,ResultChain varchar2(1024) 
	,Flag number(10) 
);

comment on table t_SysNetMonitorTaskResult is '任务结果表';
	comment on column t_SysNetMonitorTaskResult.ObjectID is '网络监控对象ID';
	comment on column t_SysNetMonitorTaskResult.Task_ID is '任务ID';
	comment on column t_SysNetMonitorTaskResult.OperateTime is '执行次数';
	comment on column t_SysNetMonitorTaskResult.MonDate is '采集的日期';
	comment on column t_SysNetMonitorTaskResult.MonTime is '采集的时间';
	comment on column t_SysNetMonitorTaskResult.InstructChain is '指令串';
	comment on column t_SysNetMonitorTaskResult.ResultChain is '结果串';
	comment on column t_SysNetMonitorTaskResult.Flag is '任务执行标识';


--******************************
--创建基线表表
--******************************
create table t_SysNetBaseLine
(
	ID number(10) not null
	,MANUFACTORY_ID number(10) 
	,Name varchar2(128) 
	,SerialUsed varchar2(128) 
	,data varchar2(2000) 
	,memo varchar2(256) 
	,Flag number(10) 
);

comment on table t_SysNetBaseLine is '基线表';
	comment on column t_SysNetBaseLine.ID is 'ID';
	comment on column t_SysNetBaseLine.MANUFACTORY_ID is '厂商类型';
	comment on column t_SysNetBaseLine.Name is '基线名';
	comment on column t_SysNetBaseLine.SerialUsed is '设备型号';
	comment on column t_SysNetBaseLine.data is '文件内容';
	comment on column t_SysNetBaseLine.memo is '备注';
	comment on column t_SysNetBaseLine.Flag is '结束标志';


--******************************
--创建基线任务表表
--******************************
create table t_SysNetBaseLineTask
(
	ID number(10) not null
	,Name varchar2(128) 
	,BaseLineIDList varchar2(1024) 
	,DeviceIDList varchar2(1024) 
	,GenDate char(8) 
	,GenTime char(8) 
	,GenUser varchar2(20) 
	,memo varchar2(256) 
	,constraint pk_SysNetBaseLineTask primary key (ID)
);

comment on table t_SysNetBaseLineTask is '基线任务表';
	comment on column t_SysNetBaseLineTask.ID is 'ID';
	comment on column t_SysNetBaseLineTask.Name is '基线任务名';
	comment on column t_SysNetBaseLineTask.BaseLineIDList is '基线ID列表';
	comment on column t_SysNetBaseLineTask.DeviceIDList is '设备ID列表';
	comment on column t_SysNetBaseLineTask.GenDate is '生成日期';
	comment on column t_SysNetBaseLineTask.GenTime is '生成时间';
	comment on column t_SysNetBaseLineTask.GenUser is '生成者';
	comment on column t_SysNetBaseLineTask.memo is '备注';


--******************************
--创建基线结果表表
--******************************
create table t_SysNetBaseLineResult
(
	ID number(10) not null
	,BaseLineName varchar2(128) 
	,DeviceObjID varchar2(128) 
	,DeviceIP char(15) 
	,Result varchar2(3000) 
	,GenDate char(8) 
	,GenTime char(8) 
	,GenUser varchar2(20) 
	,Flag number(10) 
);

comment on table t_SysNetBaseLineResult is '基线结果表';
	comment on column t_SysNetBaseLineResult.ID is 'ID';
	comment on column t_SysNetBaseLineResult.BaseLineName is '基线名称';
	comment on column t_SysNetBaseLineResult.DeviceObjID is '设备ObjID';
	comment on column t_SysNetBaseLineResult.DeviceIP is '设备IP';
	comment on column t_SysNetBaseLineResult.Result is '基线结果';
	comment on column t_SysNetBaseLineResult.GenDate is '生成日期';
	comment on column t_SysNetBaseLineResult.GenTime is '生成时间';
	comment on column t_SysNetBaseLineResult.GenUser is '生成者';
	comment on column t_SysNetBaseLineResult.Flag is '结束标志';


--******************************
--创建会员链路状态信息表表
--******************************
create table t_SysNetPartyLinkStatusInfo
(
	MonDate char(8) 
	,MonTime char(8) 
	,SEAT_NO varchar2(32) 
	,IPADDR varchar2(64) 
	,Interface varchar2(64) 
	,status varchar2(64) 
);

comment on table t_SysNetPartyLinkStatusInfo is '会员链路状态信息表';
	comment on column t_SysNetPartyLinkStatusInfo.MonDate is '采集的日期';
	comment on column t_SysNetPartyLinkStatusInfo.MonTime is '采集的时间';
	comment on column t_SysNetPartyLinkStatusInfo.SEAT_NO is '席位号';
	comment on column t_SysNetPartyLinkStatusInfo.IPADDR is '路由器网管IP';
	comment on column t_SysNetPartyLinkStatusInfo.Interface is '路由器端口号';
	comment on column t_SysNetPartyLinkStatusInfo.status is '链路状态';


--******************************
--创建会员SDH线路明细表表
--******************************
create table t_SysNetMemberSDHLineInfo
(
	ID number(10) not null
	,SeqNo number(10) 
	,MemContractNo varchar2(128) 
	,ApplyPerson varchar2(128) 
	,MonthlyRental number(16) 
	,MemberNo char(10) 
	,ParticipantName char(50) 
	,ClientManager varchar2(128) 
	,Bandwidth varchar2(128) 
	,InterfaceType varchar2(128) 
	,RemoteCircuit varchar2(128) 
	,LocalCircuit varchar2(128) 
	,Remark varchar2(128) 
	,EndALineAddress varchar2(512) 
	,EndAContact varchar2(128) 
	,EndZLineAddress varchar2(512) 
	,ContactName varchar2(50) 
	,TELEPHONE varchar2(64) 
	,MOBILEPHONE varchar2(64) 
	,IPADDR varchar2(64) 
	,Interface varchar2(64) 
	,PROVINCE varchar2(32) 
	,StartPortID varchar2(256) 
	,StartJump varchar2(128) 
	,LINE_STATUS varchar2(32) 
	,DataCenterID number(3) 
);

comment on table t_SysNetMemberSDHLineInfo is '会员SDH线路明细表';
	comment on column t_SysNetMemberSDHLineInfo.ID is 'ID';
	comment on column t_SysNetMemberSDHLineInfo.SeqNo is '序列号';
	comment on column t_SysNetMemberSDHLineInfo.MemContractNo is '合同号';
	comment on column t_SysNetMemberSDHLineInfo.ApplyPerson is '申请人';
	comment on column t_SysNetMemberSDHLineInfo.MonthlyRental is '月租费用';
	comment on column t_SysNetMemberSDHLineInfo.MemberNo is '会员号';
	comment on column t_SysNetMemberSDHLineInfo.ParticipantName is '会员名称';
	comment on column t_SysNetMemberSDHLineInfo.ClientManager is '客户经理';
	comment on column t_SysNetMemberSDHLineInfo.Bandwidth is '带宽';
	comment on column t_SysNetMemberSDHLineInfo.InterfaceType is '接口类';
	comment on column t_SysNetMemberSDHLineInfo.RemoteCircuit is '长途电路编码';
	comment on column t_SysNetMemberSDHLineInfo.LocalCircuit is '本地电路编码';
	comment on column t_SysNetMemberSDHLineInfo.Remark is '备注';
	comment on column t_SysNetMemberSDHLineInfo.EndALineAddress is 'A端接入地址';
	comment on column t_SysNetMemberSDHLineInfo.EndAContact is 'A端联系人';
	comment on column t_SysNetMemberSDHLineInfo.EndZLineAddress is 'Z端接入地址';
	comment on column t_SysNetMemberSDHLineInfo.ContactName is '联系人';
	comment on column t_SysNetMemberSDHLineInfo.TELEPHONE is '联系电话';
	comment on column t_SysNetMemberSDHLineInfo.MOBILEPHONE is '手机号';
	comment on column t_SysNetMemberSDHLineInfo.IPADDR is '路由器网管IP';
	comment on column t_SysNetMemberSDHLineInfo.Interface is '路由器端口号';
	comment on column t_SysNetMemberSDHLineInfo.PROVINCE is '所属省份';
	comment on column t_SysNetMemberSDHLineInfo.StartPortID is '起始设备端口';
	comment on column t_SysNetMemberSDHLineInfo.StartJump is '起始设备跳接端';
	comment on column t_SysNetMemberSDHLineInfo.LINE_STATUS is '线路状态';
	comment on column t_SysNetMemberSDHLineInfo.DataCenterID is '数据中心代码';


--******************************
--创建DDN链路信息表表
--******************************
create table t_SysNetDDNLinkInfo
(
	ID number(10) not null
	,ClientName varchar2(80) not null
	,DDN_NO varchar2(64) 
	,BusinessUnit char(20) 
	,Bandwidth varchar2(128) 
	,EndAAddress varchar2(100) 
	,EndAContactName varchar2(50) 
	,EndZAddress varchar2(100) 
	,EndZContactName varchar2(50) 
);

comment on table t_SysNetDDNLinkInfo is 'DDN链路信息表';
	comment on column t_SysNetDDNLinkInfo.ID is 'ID';
	comment on column t_SysNetDDNLinkInfo.ClientName is '客户名称';
	comment on column t_SysNetDDNLinkInfo.DDN_NO is '线路编号';
	comment on column t_SysNetDDNLinkInfo.BusinessUnit is '业务单元';
	comment on column t_SysNetDDNLinkInfo.Bandwidth is '速率';
	comment on column t_SysNetDDNLinkInfo.EndAAddress is '甲端地址';
	comment on column t_SysNetDDNLinkInfo.EndAContactName is '甲端联系人';
	comment on column t_SysNetDDNLinkInfo.EndZAddress is '乙端地址';
	comment on column t_SysNetDDNLinkInfo.EndZContactName is '乙端联系人';


--******************************
--创建非会员线路使用信息表
--******************************
create table t_SysNetPseudMemberLinkInfo
(
	ID number(10) not null
	,SeqNo number(10) 
	,MemContractNo varchar2(128) 
	,LineUsage varchar2(128) 
	,LocalCircuit varchar2(128) 
	,RemoteCircuit varchar2(128) 
	,BusinessUnit char(20) 
	,Bandwidth varchar2(128) 
	,ApplyPerson varchar2(128) 
	,MonthlyRental number(16) 
	,EndAAddress varchar2(100) 
	,EndAContactName varchar2(50) 
	,EndZAddress varchar2(100) 
	,EndZContactName varchar2(50) 
	,Telephone varchar2(30) 
	,LineInfo varchar2(64) 
	,IPADDR varchar2(64) 
);

comment on table t_SysNetPseudMemberLinkInfo is '非会员线路使用信息';
	comment on column t_SysNetPseudMemberLinkInfo.ID is 'ID';
	comment on column t_SysNetPseudMemberLinkInfo.SeqNo is '序列号';
	comment on column t_SysNetPseudMemberLinkInfo.MemContractNo is '合同号';
	comment on column t_SysNetPseudMemberLinkInfo.LineUsage is '线路用途';
	comment on column t_SysNetPseudMemberLinkInfo.LocalCircuit is '本地电路编码';
	comment on column t_SysNetPseudMemberLinkInfo.RemoteCircuit is '长途电路编码';
	comment on column t_SysNetPseudMemberLinkInfo.BusinessUnit is '业务';
	comment on column t_SysNetPseudMemberLinkInfo.Bandwidth is '速率';
	comment on column t_SysNetPseudMemberLinkInfo.ApplyPerson is '申请人';
	comment on column t_SysNetPseudMemberLinkInfo.MonthlyRental is '月租费用';
	comment on column t_SysNetPseudMemberLinkInfo.EndAAddress is '甲端地址';
	comment on column t_SysNetPseudMemberLinkInfo.EndAContactName is '甲端联系人';
	comment on column t_SysNetPseudMemberLinkInfo.EndZAddress is '乙端地址';
	comment on column t_SysNetPseudMemberLinkInfo.EndZContactName is '乙端联系人';
	comment on column t_SysNetPseudMemberLinkInfo.Telephone is '乙端电话号码';
	comment on column t_SysNetPseudMemberLinkInfo.LineInfo is '线路信息';
	comment on column t_SysNetPseudMemberLinkInfo.IPADDR is '路由器网管IP';


--******************************
--创建远端设备信息表
--******************************
create table t_SysNetOuterDeviceInfo
(
	ID number(10) not null
	,IPADDR char(15) 
	,NAME varchar2(128) 
	,memo varchar2(256) 
);

comment on table t_SysNetOuterDeviceInfo is '远端设备信息';
	comment on column t_SysNetOuterDeviceInfo.ID is 'ID';
	comment on column t_SysNetOuterDeviceInfo.IPADDR is 'IP地址  ';
	comment on column t_SysNetOuterDeviceInfo.NAME is '设备名称 ';
	comment on column t_SysNetOuterDeviceInfo.memo is '备注';


--******************************
--创建本地ping结果表
--******************************
create table t_SysLocalPingResultInfo
(
	ID number(10) not null
	,SouIPADDR char(15) 
	,SouNAME varchar2(128) 
	,TarIPADDR char(15) 
	,TarNAME varchar2(128) 
	,PDateSta char(8) 
	,PTimeSta char(8) 
	,ConnRate number(10) 
);

comment on table t_SysLocalPingResultInfo is '本地ping结果';
	comment on column t_SysLocalPingResultInfo.ID is 'ID';
	comment on column t_SysLocalPingResultInfo.SouIPADDR is '源IP地址  ';
	comment on column t_SysLocalPingResultInfo.SouNAME is '源设备名称 ';
	comment on column t_SysLocalPingResultInfo.TarIPADDR is '目的IP地址  ';
	comment on column t_SysLocalPingResultInfo.TarNAME is '目的设备名称 ';
	comment on column t_SysLocalPingResultInfo.PDateSta is '生成日期';
	comment on column t_SysLocalPingResultInfo.PTimeSta is '时间戳';
	comment on column t_SysLocalPingResultInfo.ConnRate is '连通率';


--******************************
--创建远程ping结果表
--******************************
create table t_SysRomotePingResultInfo
(
	ID number(10) not null
	,SouIPADDR char(15) 
	,SouNAME varchar2(128) 
	,TarIPADDR char(15) 
	,TarNAME varchar2(128) 
	,PDateSta char(8) 
	,PTimeSta char(8) 
	,ConnRate number(10) 
	,TimeDlyMin varchar2(128) 
	,TimeDlyMax varchar2(128) 
	,TimeDlyAvg varchar2(128) 
);

comment on table t_SysRomotePingResultInfo is '远程ping结果';
	comment on column t_SysRomotePingResultInfo.ID is 'ID';
	comment on column t_SysRomotePingResultInfo.SouIPADDR is '源IP地址  ';
	comment on column t_SysRomotePingResultInfo.SouNAME is '源设备名称 ';
	comment on column t_SysRomotePingResultInfo.TarIPADDR is '目的IP地址  ';
	comment on column t_SysRomotePingResultInfo.TarNAME is '目的设备名称 ';
	comment on column t_SysRomotePingResultInfo.PDateSta is '生成日期';
	comment on column t_SysRomotePingResultInfo.PTimeSta is '时间戳';
	comment on column t_SysRomotePingResultInfo.ConnRate is '连通率';
	comment on column t_SysRomotePingResultInfo.TimeDlyMin is '最小时延';
	comment on column t_SysRomotePingResultInfo.TimeDlyMax is '最大时延';
	comment on column t_SysRomotePingResultInfo.TimeDlyAvg is '平均时延';


--******************************
--创建交易系统前置报单响应信息表
--******************************
create table t_SysTradeFrontOrderRttStat
(
	MonDate char(8) 
	,MonTime char(8) 
	,ObjectID varchar2(64) 
	,OrderCount number(20) 
	,OrderRttSum number(20) 
	,OrderMaxRtt number(10) 
	,OrderMinRtt number(10) 
	,OrderRttSqu number(10) 
	,OrderRttCutDistrib varchar2(128) 
);

comment on table t_SysTradeFrontOrderRttStat is '交易系统前置报单响应信息';
	comment on column t_SysTradeFrontOrderRttStat.MonDate is '报单日期';
	comment on column t_SysTradeFrontOrderRttStat.MonTime is '报单时间';
	comment on column t_SysTradeFrontOrderRttStat.ObjectID is '前置对象';
	comment on column t_SysTradeFrontOrderRttStat.OrderCount is '报单量';
	comment on column t_SysTradeFrontOrderRttStat.OrderRttSum is '报单响应时间和';
	comment on column t_SysTradeFrontOrderRttStat.OrderMaxRtt is '最大报单响应时间';
	comment on column t_SysTradeFrontOrderRttStat.OrderMinRtt is '最小报单响应时间';
	comment on column t_SysTradeFrontOrderRttStat.OrderRttSqu is '1秒内响应时间均差';
	comment on column t_SysTradeFrontOrderRttStat.OrderRttCutDistrib is '1秒内响应时间分布';


--******************************
--创建交易系统前置报单分布区间表
--******************************
create table t_SysTradeOrderRttCutLine
(
	MonDate char(8) 
	,MonTime char(8) 
	,UserName varchar2(64) 
	,OrderRttCutLine varchar2(128) 
	,OrderRttWidth number(10) 
);

comment on table t_SysTradeOrderRttCutLine is '交易系统前置报单分布区间';
	comment on column t_SysTradeOrderRttCutLine.MonDate is '区间生效日期';
	comment on column t_SysTradeOrderRttCutLine.MonTime is '区间修改时间';
	comment on column t_SysTradeOrderRttCutLine.UserName is '修改用户对象';
	comment on column t_SysTradeOrderRttCutLine.OrderRttCutLine is '响应时间分布';
	comment on column t_SysTradeOrderRttCutLine.OrderRttWidth is '统计颗粒度';


--******************************
--创建会员席位交易状态表
--******************************
create table t_SysParticTradeOrderStates
(
	ParticipantID char(10) not null
	,UserID char(15) not null
	,MonDate char(8) 
	,MonTime char(8) 
	,StaticWidth number(10) 
	,FrontID number(10) 
	,OrderCount number(10) 
	,CancleCount number(10) 
	,QueryCount number(10) 
	,TradeCount number(10) 
	,TradeMoney number(10) 
	,OrderCntMax number(10) 
	,CancleCntMax number(10) 
	,QueryCntMax number(10) 
	,TradeCntMax number(10) 
	,TradeMoneyMax number(10) 
);

comment on table t_SysParticTradeOrderStates is '会员席位交易状态';
	comment on column t_SysParticTradeOrderStates.ParticipantID is '会员代码';
	comment on column t_SysParticTradeOrderStates.UserID is '交易用户代码';
	comment on column t_SysParticTradeOrderStates.MonDate is '报单统计日期';
	comment on column t_SysParticTradeOrderStates.MonTime is '报单统计时间';
	comment on column t_SysParticTradeOrderStates.StaticWidth is '统计时长(sec)';
	comment on column t_SysParticTradeOrderStates.FrontID is '前置ID';
	comment on column t_SysParticTradeOrderStates.OrderCount is '报单数';
	comment on column t_SysParticTradeOrderStates.CancleCount is '撤单数';
	comment on column t_SysParticTradeOrderStates.QueryCount is '查询数';
	comment on column t_SysParticTradeOrderStates.TradeCount is '成交数';
	comment on column t_SysParticTradeOrderStates.TradeMoney is '成交金额';
	comment on column t_SysParticTradeOrderStates.OrderCntMax is '最大报单数';
	comment on column t_SysParticTradeOrderStates.CancleCntMax is '最大撤单数';
	comment on column t_SysParticTradeOrderStates.QueryCntMax is '最大查询数';
	comment on column t_SysParticTradeOrderStates.TradeCntMax is '最大成交数';
	comment on column t_SysParticTradeOrderStates.TradeMoneyMax is '最大成交金额';


--******************************
--创建系统路由信息表
--******************************
create table t_RouterInfo
(
	HostName varchar2(64) 
	,MonDate char(8) 
	,MonTime char(8) 
	,Dev varchar2(20) 
	,Destination char(15) 
	,Gateway char(15) 
	,Mask char(15) 
	,Flag varchar2(5) 
	,RefCnt number(10) 
	,Use number(10) 
	,Metric number(10) 
	,Mtu number(10) 
	,Win number(10) 
	,Rtt number(10) 
);

comment on table t_RouterInfo is '系统路由信息';
	comment on column t_RouterInfo.HostName is '主机名称';
	comment on column t_RouterInfo.MonDate is '采集的日期';
	comment on column t_RouterInfo.MonTime is '采集的时间';
	comment on column t_RouterInfo.Dev is '设备接口名';
	comment on column t_RouterInfo.Destination is '目标网段ip地址';
	comment on column t_RouterInfo.Gateway is '网关ip地址';
	comment on column t_RouterInfo.Mask is '掩码ip地址';
	comment on column t_RouterInfo.Flag is '网络状态';
	comment on column t_RouterInfo.RefCnt is '关联计数';
	comment on column t_RouterInfo.Use is '使用计数';
	comment on column t_RouterInfo.Metric is 'metric值';
	comment on column t_RouterInfo.Mtu is 'mtu值';
	comment on column t_RouterInfo.Win is 'win值';
	comment on column t_RouterInfo.Rtt is 'rtt值';


--******************************
--创建磁盘I/O信息表
--******************************
create table t_DiskIO
(
	HostName varchar2(64) 
	,MonDate char(8) 
	,MonTime char(8) 
	,PartName varchar2(20) 
	,ReadMerges number(12,3) 
	,WriteMerges number(12,3) 
	,ReadIOs number(12,3) 
	,WriteIOs number(12,3) 
	,ReadKBs number(12,3) 
	,WriteKBs number(12,3) 
	,SizeVal number(12,3) 
	,QueueVal number(12,3) 
	,Svc_t number(12,3) 
	,Busy number(10,4) 
);

comment on table t_DiskIO is '磁盘I/O信息';
	comment on column t_DiskIO.HostName is '主机名称';
	comment on column t_DiskIO.MonDate is '采集的日期';
	comment on column t_DiskIO.MonTime is '采集的时间';
	comment on column t_DiskIO.PartName is '分区名';
	comment on column t_DiskIO.ReadMerges is '每秒ReadMerge数';
	comment on column t_DiskIO.WriteMerges is '每秒WriteMerge数';
	comment on column t_DiskIO.ReadIOs is '每秒ReadIO数';
	comment on column t_DiskIO.WriteIOs is '每秒WriteIO数';
	comment on column t_DiskIO.ReadKBs is '每秒Read字节数';
	comment on column t_DiskIO.WriteKBs is '每秒Write字节数';
	comment on column t_DiskIO.SizeVal is 'Size值';
	comment on column t_DiskIO.QueueVal is 'Queue值';
	comment on column t_DiskIO.Svc_t is 'Svc_t值';
	comment on column t_DiskIO.Busy is '繁忙百分率';


--******************************
--创建系统状态信息表
--******************************
create table t_StatInfo
(
	HostName varchar2(64) 
	,MonDate char(8) 
	,MonTime char(8) 
	,ProcRun number(10) 
	,ProcBlk number(10) 
	,SwapIn number(10) 
	,SwapOut number(10) 
	,BlockIn number(10) 
	,BlockOut number(10) 
	,Inter number(10) 
	,Context number(10) 
	,CPUUser number(10,4) 
	,CPUSys number(10,4) 
	,CPUIdle number(10,4) 
	,CPUIOWait number(10,4) 
	,CPUSteal number(10,4) 
);

comment on table t_StatInfo is '系统状态信息';
	comment on column t_StatInfo.HostName is '主机名称';
	comment on column t_StatInfo.MonDate is '采集的日期';
	comment on column t_StatInfo.MonTime is '采集的时间';
	comment on column t_StatInfo.ProcRun is '活跃进程数';
	comment on column t_StatInfo.ProcBlk is '阻塞进程数';
	comment on column t_StatInfo.SwapIn is '每秒由磁盘进入Swap的页面数';
	comment on column t_StatInfo.SwapOut is '每秒由Swap进入磁盘的页面数';
	comment on column t_StatInfo.BlockIn is '每秒从块设备读入的Block数';
	comment on column t_StatInfo.BlockOut is '每秒向块设备写入的Block数';
	comment on column t_StatInfo.Inter is '每秒设备中段次数';
	comment on column t_StatInfo.Context is '每秒上下文切换次数';
	comment on column t_StatInfo.CPUUser is '用户态CPU百分率';
	comment on column t_StatInfo.CPUSys is '系统态CPU百分率';
	comment on column t_StatInfo.CPUIdle is '空闲态CPU百分率';
	comment on column t_StatInfo.CPUIOWait is 'IO等待态CPU百分率';
	comment on column t_StatInfo.CPUSteal is '窃取态CPU百分率';


--******************************
--创建进程信息表
--******************************
create table t_TopProcessInfo
(
	HostName varchar2(64) 
	,MonDate char(8) 
	,MonTime char(8) 
	,CPU varchar2(5) 
	,TTY varchar2(10) 
	,PID number(10) 
	,USERNAME varchar2(10) 
	,PRI number(10) 
	,NI number(10) 
	,SSIZE number(10) 
	,RES number(10) 
	,STATE varchar2(10) 
	,STIME char(8) 
	,pWCPU number(10,4) 
	,pCPU number(10,4) 
	,COMMAND varchar2(20) 
);

comment on table t_TopProcessInfo is '进程信息';
	comment on column t_TopProcessInfo.HostName is '主机名称';
	comment on column t_TopProcessInfo.MonDate is '采集的日期';
	comment on column t_TopProcessInfo.MonTime is '采集的时间';
	comment on column t_TopProcessInfo.CPU is '处理器号';
	comment on column t_TopProcessInfo.TTY is '终端名';
	comment on column t_TopProcessInfo.PID is '进程号';
	comment on column t_TopProcessInfo.USERNAME is '用户名';
	comment on column t_TopProcessInfo.PRI is '任务的优先级';
	comment on column t_TopProcessInfo.NI is '任务的nice值';
	comment on column t_TopProcessInfo.SSIZE is '任务的代码加上数据再加上栈空间的大小';
	comment on column t_TopProcessInfo.RES is '任务使用的物理内存的总数量';
	comment on column t_TopProcessInfo.STATE is '任务的状态';
	comment on column t_TopProcessInfo.STIME is '自任务开始时使用的总CPU时间';
	comment on column t_TopProcessInfo.pWCPU is '进程的CPU利用率权重百分比';
	comment on column t_TopProcessInfo.pCPU is '进程的原始的CPU利用率百分比';
	comment on column t_TopProcessInfo.COMMAND is '启动进程的命令名';


--******************************
--创建事件描述信息表
--******************************
create table t_SysEventDescrip
(
	EventDesID char(12) 
	,UserName varchar2(64) 
	,MonDate char(8) 
	,MonTime char(8) 
	,EventDes varchar2(400) 
);

comment on table t_SysEventDescrip is '事件描述信息';
	comment on column t_SysEventDescrip.EventDesID is '处理ID号';
	comment on column t_SysEventDescrip.UserName is '事件处理人';
	comment on column t_SysEventDescrip.MonDate is '事件处理日期';
	comment on column t_SysEventDescrip.MonTime is '事件处理时间';
	comment on column t_SysEventDescrip.EventDes is '处理描述';


--******************************
--创建会员链路费用表表
--******************************
create table t_SysMemberLinkCost
(
	ID number(10) not null
	,ParticipantName char(50) not null
	,DDN_NO varchar2(64) 
	,ServiceProvider varchar2(32) 
	,Pay_Date varchar2(32) 
	,B_Pay_Date varchar2(32) 
	,D_Pay_Date varchar2(32) 
	,Charge number(10) 
	,Fee_Type varchar2(32) 
	,Pro varchar2(512) 
	,constraint pk_SysMemberLinkCost primary key (ID)
);

comment on table t_SysMemberLinkCost is '会员链路费用表';
	comment on column t_SysMemberLinkCost.ID is 'ID';
	comment on column t_SysMemberLinkCost.ParticipantName is '会员名称';
	comment on column t_SysMemberLinkCost.DDN_NO is '线路编号';
	comment on column t_SysMemberLinkCost.ServiceProvider is '运营商';
	comment on column t_SysMemberLinkCost.Pay_Date is '付款日期';
	comment on column t_SysMemberLinkCost.B_Pay_Date is '账期起始日期';
	comment on column t_SysMemberLinkCost.D_Pay_Date is '账期终止日期';
	comment on column t_SysMemberLinkCost.Charge is '金额';
	comment on column t_SysMemberLinkCost.Fee_Type is '费用类型';
	comment on column t_SysMemberLinkCost.Pro is '备注';


--******************************
--创建会员链路月租表表
--******************************
create table t_SysNetPartylinkMonthlyRent
(
	ID number(10) not null
	,LineName char(50) 
	,DDN_NO varchar2(64) 
	,ServiceProvider varchar2(32) 
	,MonthlyRental number(16) 
	,Remark varchar2(128) 
	,constraint pk_SysNetPartylinkMonthlyRent primary key (ID)
);

comment on table t_SysNetPartylinkMonthlyRent is '会员链路月租表';
	comment on column t_SysNetPartylinkMonthlyRent.ID is 'ID';
	comment on column t_SysNetPartylinkMonthlyRent.LineName is '线路名称';
	comment on column t_SysNetPartylinkMonthlyRent.DDN_NO is '线路编号';
	comment on column t_SysNetPartylinkMonthlyRent.ServiceProvider is '运营商';
	comment on column t_SysNetPartylinkMonthlyRent.MonthlyRental is '月租费用';
	comment on column t_SysNetPartylinkMonthlyRent.Remark is '备注';


--******************************
--创建非会员链路信息表表
--******************************
create table t_SysNetNonPartyLinkInfo
(
	ID number(10) not null
	,MEMBER_NO varchar2(32) 
	,MEMBER_NAME varchar2(64) 
	,REMOTE_ADDR varchar2(64) 
	,LOCAL_ADDR varchar2(64) 
	,ADDRESS varchar2(256) 
	,LINE_STATUS varchar2(32) 
	,CONTACT varchar2(32) 
	,TELEPHONE varchar2(64) 
	,MOBILEPHONE varchar2(64) 
	,EMAIL varchar2(64) 
	,FAX varchar2(64) 
	,PROVINCE varchar2(32) 
	,DDN_NO varchar2(64) 
	,IN_MODE varchar2(64) 
	,IP_WAN varchar2(64) 
	,IP_LAN varchar2(64) 
	,IPADDR varchar2(64) 
	,Interface varchar2(64) 
	,INTERFACE_DATE varchar2(32) 
	,SOFTWARE varchar2(32) 
	,FEE_TYPE varchar2(32) 
	,SERVICEPROVIDER varchar2(32) 
	,IF_ZIYING varchar2(32) 
	,IF_TUOGUAN varchar2(32) 
	,HASOTHER varchar2(32) 
	,SEAT_NO varchar2(1024) 
	,PRO varchar2(512) 
	,constraint pk_SysNetNonPartyLinkInfo primary key (ID)
);

comment on table t_SysNetNonPartyLinkInfo is '非会员链路信息表';
	comment on column t_SysNetNonPartyLinkInfo.ID is 'ID';
	comment on column t_SysNetNonPartyLinkInfo.MEMBER_NO is '会员号';
	comment on column t_SysNetNonPartyLinkInfo.MEMBER_NAME is '会员名称';
	comment on column t_SysNetNonPartyLinkInfo.REMOTE_ADDR is '会员接入地点';
	comment on column t_SysNetNonPartyLinkInfo.LOCAL_ADDR is '上期所接入点';
	comment on column t_SysNetNonPartyLinkInfo.ADDRESS is '地址';
	comment on column t_SysNetNonPartyLinkInfo.LINE_STATUS is '线路状态';
	comment on column t_SysNetNonPartyLinkInfo.CONTACT is '联系人';
	comment on column t_SysNetNonPartyLinkInfo.TELEPHONE is '联系电话';
	comment on column t_SysNetNonPartyLinkInfo.MOBILEPHONE is '手机号';
	comment on column t_SysNetNonPartyLinkInfo.EMAIL is 'EMAIL';
	comment on column t_SysNetNonPartyLinkInfo.FAX is '传真';
	comment on column t_SysNetNonPartyLinkInfo.PROVINCE is '所属省份';
	comment on column t_SysNetNonPartyLinkInfo.DDN_NO is '线路编号';
	comment on column t_SysNetNonPartyLinkInfo.IN_MODE is '接入方式';
	comment on column t_SysNetNonPartyLinkInfo.IP_WAN is '入网IP广域';
	comment on column t_SysNetNonPartyLinkInfo.IP_LAN is '入网IP局域';
	comment on column t_SysNetNonPartyLinkInfo.IPADDR is '路由器网管IP';
	comment on column t_SysNetNonPartyLinkInfo.Interface is '路由器端口号';
	comment on column t_SysNetNonPartyLinkInfo.INTERFACE_DATE is '接口开通日期';
	comment on column t_SysNetNonPartyLinkInfo.SOFTWARE is '所用软件';
	comment on column t_SysNetNonPartyLinkInfo.FEE_TYPE is '付费类型';
	comment on column t_SysNetNonPartyLinkInfo.SERVICEPROVIDER is '运营商';
	comment on column t_SysNetNonPartyLinkInfo.IF_ZIYING is '是否自营';
	comment on column t_SysNetNonPartyLinkInfo.IF_TUOGUAN is '是否托管';
	comment on column t_SysNetNonPartyLinkInfo.HASOTHER is '有无他所线路';
	comment on column t_SysNetNonPartyLinkInfo.SEAT_NO is '席位号';
	comment on column t_SysNetNonPartyLinkInfo.PRO is '备注';


