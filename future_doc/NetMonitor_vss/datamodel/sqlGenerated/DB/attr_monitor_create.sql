--******************************
--�����ݿ�д��¼��־��
--******************************
create table t_DbWriteLog
(
	TradingDay char(8) not null
	,Count number(10) 
	,constraint pk_DbWriteLog primary key (TradingDay)
);

comment on table t_DbWriteLog is '�ݿ�д��¼��־';
	comment on column t_DbWriteLog.TradingDay is '����';
	comment on column t_DbWriteLog.Count is '��д��¼';


--******************************
--������ʷ״̬��Ϣ���
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

comment on table t_SysHistoryObjectAttr is '��ʷ״̬��Ϣ��';
	comment on column t_SysHistoryObjectAttr.MonDate is '�ɼ�������';
	comment on column t_SysHistoryObjectAttr.BeginTime is '�����ڿ�ʼʱ��';
	comment on column t_SysHistoryObjectAttr.EndTime is '�����ڽ���ʱ��';
	comment on column t_SysHistoryObjectAttr.ObjectID is '���������';
	comment on column t_SysHistoryObjectAttr.AttrType is '���ָ������';
	comment on column t_SysHistoryObjectAttr.ValueType is '���ָ���ֵ����';
	comment on column t_SysHistoryObjectAttr.FirstValue is '�������յ���һ��ֵ';
	comment on column t_SysHistoryObjectAttr.EndValue is '�������յ����һ��ֵ';
	comment on column t_SysHistoryObjectAttr.AvgValue is '������ƽ��ֵ';
	comment on column t_SysHistoryObjectAttr.MinValue is '�������յ���Сֵ';
	comment on column t_SysHistoryObjectAttr.MaxValue is '�������յ����ֵ';
	comment on column t_SysHistoryObjectAttr.ValueCount is '�������յ�ָ�����';


--******************************
--����ǰ����Ӧ��Ϣ���
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

comment on table t_SysFrontInfo is 'ǰ����Ӧ��Ϣ��';
	comment on column t_SysFrontInfo.MonDate is '����';
	comment on column t_SysFrontInfo.MonTime is '�����ڿ�ʼʱ��';
	comment on column t_SysFrontInfo.FrontId is 'ǰ�û���';
	comment on column t_SysFrontInfo.RspCondition is 'ǰ����Ӧʱ������';
	comment on column t_SysFrontInfo.ReqCount is '������';
	comment on column t_SysFrontInfo.ReqRate is '��ռ�ܱ�������';


--******************************
--�����澯�¼���Ϣ���
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

comment on table t_SysWarningEvent is '�澯�¼���Ϣ��';
	comment on column t_SysWarningEvent.MonDate is '�ɼ�������';
	comment on column t_SysWarningEvent.MonTime is '�ɼ���ʱ��';
	comment on column t_SysWarningEvent.OccurDate is '�¼���������';
	comment on column t_SysWarningEvent.OccurTime is '�¼�����ʱ��';
	comment on column t_SysWarningEvent.EvendID is '�¼�ID';
	comment on column t_SysWarningEvent.ObjectID is '�����¼��Ķ���IDָ��';
	comment on column t_SysWarningEvent.IPAddress is 'IP��ַ';
	comment on column t_SysWarningEvent.EventName is '�¼���';
	comment on column t_SysWarningEvent.EventNum is '�¼���ǩ';
	comment on column t_SysWarningEvent.EventType is '�¼�����';
	comment on column t_SysWarningEvent.EventDes is '�¼�����';
	comment on column t_SysWarningEvent.ProcessFlag is '������';
	comment on column t_SysWarningEvent.WarningLevel is '���漶��';
	comment on column t_SysWarningEvent.EventDealDes is '�¼���������';
	comment on column t_SysWarningEvent.FullEventName is '�¼�ȫ��';


--******************************
--�����û���Ϣ���
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

comment on table t_SysRegisterUserInfo is '�û���Ϣ��';
	comment on column t_SysRegisterUserInfo.UserID is '�û�����';
	comment on column t_SysRegisterUserInfo.UserName is '�û�����';
	comment on column t_SysRegisterUserInfo.UserInfo is '�û���Ϣ';
	comment on column t_SysRegisterUserInfo.Password is '����';
	comment on column t_SysRegisterUserInfo.Privilege is '�û�Ȩ��';
	comment on column t_SysRegisterUserInfo.EMail is '�û������ʼ�';
	comment on column t_SysRegisterUserInfo.EMailFlag is '�û������ʼ����ձ��';
	comment on column t_SysRegisterUserInfo.HomePhone is '�û��̶��绰';
	comment on column t_SysRegisterUserInfo.HomePhoneFlag is '�û��̶��绰���ձ��';
	comment on column t_SysRegisterUserInfo.MobilePhone is '�û��ֻ�';
	comment on column t_SysRegisterUserInfo.MobilePhoneFlag is '�û��ֻ����ձ��';


--******************************
--����Cpu��Ϣ���
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

comment on table t_RspQryTopCpuInfo is 'Cpu��Ϣ��';
	comment on column t_RspQryTopCpuInfo.HostName is '��������';
	comment on column t_RspQryTopCpuInfo.MonDate is '�ɼ�������';
	comment on column t_RspQryTopCpuInfo.MonTime is '�ɼ���ʱ��';
	comment on column t_RspQryTopCpuInfo.CPU is 'CPU�ı��';
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
--����Mem��Ϣ���
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

comment on table t_RspQryTopMemInfo is 'Mem��Ϣ��';
	comment on column t_RspQryTopMemInfo.HostName is '��������';
	comment on column t_RspQryTopMemInfo.MonDate is '�ɼ�������';
	comment on column t_RspQryTopMemInfo.MonTime is '�ɼ���ʱ��';
	comment on column t_RspQryTopMemInfo.TOTALREAL is 'Total Real Memory';
	comment on column t_RspQryTopMemInfo.ACTIVEREAL is 'Active Real Memory';
	comment on column t_RspQryTopMemInfo.TOTALVIRTUAL is 'Total Virtual Memory';
	comment on column t_RspQryTopMemInfo.ACTIVEVIRTUAL is 'Active Virtual Memory';
	comment on column t_RspQryTopMemInfo.FREE is 'Free Memory';


--******************************
--����Network��Ϣ���
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

comment on table t_RspQryNetworkInfo is 'Network��Ϣ��';
	comment on column t_RspQryNetworkInfo.HostName is '��������';
	comment on column t_RspQryNetworkInfo.MonDate is '�ɼ�������';
	comment on column t_RspQryNetworkInfo.MonTime is '�ɼ���ʱ��';
	comment on column t_RspQryNetworkInfo.LANNAME is '������';
	comment on column t_RspQryNetworkInfo.LANSTATUS is '������up��down״̬';
	comment on column t_RspQryNetworkInfo.IPADDRESS is '������ip��ַ';
	comment on column t_RspQryNetworkInfo.RECVBYTES is '�������յ�����';
	comment on column t_RspQryNetworkInfo.RECVPACKETS is '�������յ����ݰ�';
	comment on column t_RspQryNetworkInfo.RECVERRORPACKETS is '�������ն˴������ݰ�';
	comment on column t_RspQryNetworkInfo.RECVDROPPACKETS is '�������ն˶�ʧ���ݰ�';
	comment on column t_RspQryNetworkInfo.SENDBYTES is '�������͵�����';
	comment on column t_RspQryNetworkInfo.SENDPACKETS is '�������͵����ݰ�';
	comment on column t_RspQryNetworkInfo.SENDERRORPACKETS is '�������Ͷ˴������ݰ�';
	comment on column t_RspQryNetworkInfo.SENDDROPPACKETS is '�������Ͷ˶�ʧ���ݰ�';


--******************************
--������ʷ��ֵ��Ϣ���
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

comment on table t_SysHistoryTradePeak is '��ʷ��ֵ��Ϣ��';
	comment on column t_SysHistoryTradePeak.ObjectID is '��ض���';
	comment on column t_SysHistoryTradePeak.MonDate is '�����������';
	comment on column t_SysHistoryTradePeak.MonTime is '�������ʱ��';
	comment on column t_SysHistoryTradePeak.AttrType is '���ָ��';
	comment on column t_SysHistoryTradePeak.AttrValue is '�������ֵ';
	comment on column t_SysHistoryTradePeak.RltAttrType is '���ָ��';
	comment on column t_SysHistoryTradePeak.RltAttrValue is '���ָ�굱ʱ��ֵ';
	comment on column t_SysHistoryTradePeak.MaxMonDate is '���ֵ������';
	comment on column t_SysHistoryTradePeak.MaxMonTime is '���ֵ��ʱ��';
	comment on column t_SysHistoryTradePeak.MaxAttrValue is 'ָ����ʷ���ֵ';
	comment on column t_SysHistoryTradePeak.MaxRltAttrValue is '���ָ�굱ʱ��ֵ';
	comment on column t_SysHistoryTradePeak.OldMonDate is '����ֵ������';
	comment on column t_SysHistoryTradePeak.OldMonTime is '����ֵ��ʱ��';
	comment on column t_SysHistoryTradePeak.OldAttrValue is '���ָ��Ĵ���ֵ';
	comment on column t_SysHistoryTradePeak.OldRltAttrValue is '���ָ�굱ʱ��ֵ';


--******************************
--���������豸��
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

comment on table t_SysNetDevice is '�����豸';
	comment on column t_SysNetDevice.ID is 'ID';
	comment on column t_SysNetDevice.ObjectID is '��ض���';
	comment on column t_SysNetDevice.MonitorType_ID is '��ض�������';
	comment on column t_SysNetDevice.SysNetSubAreaID is 'SysNetSubAreaID';
	comment on column t_SysNetDevice.CATEGORY_ID is '����ID  ';
	comment on column t_SysNetDevice.FuctionArea is '��Ϊ���ֵ�ְ������  ';
	comment on column t_SysNetDevice.IPADDR is 'IP��ַ  ';
	comment on column t_SysNetDevice.IPDECODE is 'IP��    ';
	comment on column t_SysNetDevice.NAME is '�豸���� ';
	comment on column t_SysNetDevice.PORTNUMBER is '             ';
	comment on column t_SysNetDevice.CONFIGFILE is '          ';
	comment on column t_SysNetDevice.RCOMMUNITY is '��ͬ����  ';
	comment on column t_SysNetDevice.SNMPVERSION is 'snmp�汾     ';
	comment on column t_SysNetDevice.RAMSIZE is 'ramsize(B)   ';
	comment on column t_SysNetDevice.FLASHSIZE is 'falshsize(B) ';
	comment on column t_SysNetDevice.NVRAMSIZE is 'nvramsize(B) ';
	comment on column t_SysNetDevice.CABINET_ID is '��������';
	comment on column t_SysNetDevice.ROOM_ID is '';
	comment on column t_SysNetDevice.IOSVERSION_ID is '����汾';
	comment on column t_SysNetDevice.DESCRIPTION is 'ϵͳ����';
	comment on column t_SysNetDevice.USERNAME is '��¼�û���';
	comment on column t_SysNetDevice.PASSWD is '��¼����';
	comment on column t_SysNetDevice.ENPASSWD is 'enable����';
	comment on column t_SysNetDevice.MANUFACTORY_ID is '��������';
	comment on column t_SysNetDevice.CFGSAVETYPE is '���ñ���Э��';
	comment on column t_SysNetDevice.DEVICETYPE is '�豸�ͺ�';
	comment on column t_SysNetDevice.SENDSMS is '�Ƿ���Ÿ澯';
	comment on column t_SysNetDevice.ISSNMP is '�Ƿ��Զ�snmp̽��';
	comment on column t_SysNetDevice.SLOTNUM is '��λ��';
	comment on column t_SysNetDevice.ISPING is '�Ƿ��Զ�ping';
	comment on column t_SysNetDevice.IFNUM is '�˿�����';
	comment on column t_SysNetDevice.APPLICATION_ID is 'Ѳ�����';


--******************************
--���������豸���ӹ�ϵ��
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

comment on table t_SysNetDeviceLinked is '�����豸���ӹ�ϵ';
	comment on column t_SysNetDeviceLinked.ID is 'ID';
	comment on column t_SysNetDeviceLinked.NetDeviceID is '�豸ID';
	comment on column t_SysNetDeviceLinked.NetPortID is '�豸�˿�ID';
	comment on column t_SysNetDeviceLinked.NetObjectID is '��ض���';
	comment on column t_SysNetDeviceLinked.NetPortType is '��ض���˿�����';
	comment on column t_SysNetDeviceLinked.LinkNetDeviceID is '�����豸ID';
	comment on column t_SysNetDeviceLinked.LinkNetPortID is '�����豸�˿�ID';
	comment on column t_SysNetDeviceLinked.LinkNetObjectID is '���Ӷ���';
	comment on column t_SysNetDeviceLinked.LinkNetPortType is '���Ӷ���˿�����';
	comment on column t_SysNetDeviceLinked.LinkSource is '������Դ';


--******************************
--��������������ֱ�
--******************************
create table t_SysNetArea
(
	ID number(10) not null
	,CName varchar2(64) 
	,EName varchar2(64) 
	,constraint pk_SysNetArea primary key (ID)
);

comment on table t_SysNetArea is '�����������';
	comment on column t_SysNetArea.ID is 'ID';
	comment on column t_SysNetArea.CName is '����������';
	comment on column t_SysNetArea.EName is '����Ӣ����';


--******************************
--��������������
--******************************
create table t_SysNetSubArea
(
	ID number(10) not null
	,SysNetAreaID number(10) 
	,CName varchar2(64) 
	,EName varchar2(64) 
	,constraint pk_SysNetSubArea primary key (ID)
);

comment on table t_SysNetSubArea is '��������';
	comment on column t_SysNetSubArea.ID is 'ID';
	comment on column t_SysNetSubArea.SysNetAreaID is 'SysNetArea';
	comment on column t_SysNetSubArea.CName is '����������';
	comment on column t_SysNetSubArea.EName is '����Ӣ����';


--******************************
--������������IP��
--******************************
create table t_SysNetSubAreaIP
(
	ID number(10) not null
	,SysNetSubAreaID number(10) 
	,IP char(15) 
	,Mask char(15) 
	,constraint pk_SysNetSubAreaIP primary key (ID)
);

comment on table t_SysNetSubAreaIP is '��������IP';
	comment on column t_SysNetSubAreaIP.ID is 'ID';
	comment on column t_SysNetSubAreaIP.SysNetSubAreaID is 'SysNetSubAreaID';
	comment on column t_SysNetSubAreaIP.IP is 'ip��ַ';
	comment on column t_SysNetSubAreaIP.Mask is '����';


--******************************
--������¥��
--******************************
create table t_SysNetBuilding
(
	ID number(10) not null
	,CName varchar2(64) 
	,EName varchar2(64) 
	,constraint pk_SysNetBuilding primary key (ID)
);

comment on table t_SysNetBuilding is '��¥';
	comment on column t_SysNetBuilding.ID is 'ID';
	comment on column t_SysNetBuilding.CName is '����������';
	comment on column t_SysNetBuilding.EName is '����Ӣ����';


--******************************
--����������
--******************************
create table t_SysNetRoom
(
	ID number(10) not null
	,SysNetBuildingID number(10) 
	,CName varchar2(64) 
	,EName varchar2(64) 
	,constraint pk_SysNetRoom primary key (ID)
);

comment on table t_SysNetRoom is '����';
	comment on column t_SysNetRoom.ID is 'ID';
	comment on column t_SysNetRoom.SysNetBuildingID is '��¥';
	comment on column t_SysNetRoom.CName is '����������';
	comment on column t_SysNetRoom.EName is '����Ӣ����';


--******************************
--���������
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

comment on table t_SysNetCabinets is '����';
	comment on column t_SysNetCabinets.ID is 'ID';
	comment on column t_SysNetCabinets.SysNetRoomID is 'SysNetRoomID';
	comment on column t_SysNetCabinets.SysNetBuildingID is 'SysNetBuildingID';
	comment on column t_SysNetCabinets.CName is '����������';
	comment on column t_SysNetCabinets.EName is '����Ӣ����';
	comment on column t_SysNetCabinets.CabinetsType is '��������';


--******************************
--���������豸���ͱ�
--******************************
create table t_SysNetDeviceType
(
	ID number(10) not null
	,Manufactory varchar2(64) 
	,DeviceType varchar2(64) 
	,constraint pk_SysNetDeviceType primary key (ID)
);

comment on table t_SysNetDeviceType is '�����豸����';
	comment on column t_SysNetDeviceType.ID is 'ID';
	comment on column t_SysNetDeviceType.Manufactory is '��������';
	comment on column t_SysNetDeviceType.DeviceType is '�豸�ͺ�';


--******************************
--����OID��
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
	comment on column t_SysNetOID.Manufactory is '��������';
	comment on column t_SysNetOID.DeviceType is '�豸�ͺ�';
	comment on column t_SysNetOID.CName is 'OID������';
	comment on column t_SysNetOID.EName is 'OIDӢ����';
	comment on column t_SysNetOID.OID is 'OID';
	comment on column t_SysNetOID.Unit is '��λ';
	comment on column t_SysNetOID.isTheTable is '�Ƿ������־';


--******************************
--����ʱ����Ա�
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

comment on table t_SysNetTimePolicy is 'ʱ�����';
	comment on column t_SysNetTimePolicy.ID is 'ID';
	comment on column t_SysNetTimePolicy.CName is 'ʱ�����������';
	comment on column t_SysNetTimePolicy.EName is 'ʱ�����Ӣ����';
	comment on column t_SysNetTimePolicy.PolicyType is '��������';
	comment on column t_SysNetTimePolicy.PolicyString is '���������ô�';
	comment on column t_SysNetTimePolicy.TradingDay is '����������';
	comment on column t_SysNetTimePolicy.Description is '����������';
	comment on column t_SysNetTimePolicy.Operation is '��������';


--******************************
--�����ɼ������
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

comment on table t_SysNetGatherTask is '�ɼ�����';
	comment on column t_SysNetGatherTask.ID is 'ID';
	comment on column t_SysNetGatherTask.ObjectID is '�����ض���ID';
	comment on column t_SysNetGatherTask.AttrType is '������ָ������';
	comment on column t_SysNetGatherTask.PolicyTypeID is 'ʱ�����ID';
	comment on column t_SysNetGatherTask.DataType is '��������';
	comment on column t_SysNetGatherTask.TypeFlag is '���ͱ�ʶ';


--******************************
--���������豸����
--******************************
create table t_SysNetDeviceCategory
(
	ID number(10) not null
	,CName varchar2(64) 
	,EName varchar2(64) 
	,constraint pk_SysNetDeviceCategory primary key (ID)
);

comment on table t_SysNetDeviceCategory is '�����豸���';
	comment on column t_SysNetDeviceCategory.ID is 'ID';
	comment on column t_SysNetDeviceCategory.CName is '���������';
	comment on column t_SysNetDeviceCategory.EName is '���Ӣ����';


--******************************
--�����豸���̱�
--******************************
create table t_SysNetManufactory
(
	ID number(10) not null
	,CName varchar2(64) 
	,EName varchar2(64) 
	,constraint pk_SysNetManufactory primary key (ID)
);

comment on table t_SysNetManufactory is '�豸����';
	comment on column t_SysNetManufactory.ID is 'ID';
	comment on column t_SysNetManufactory.CName is '����������';
	comment on column t_SysNetManufactory.EName is '����Ӣ����';


--******************************
--�����豸��ͬ���
--******************************
create table t_SysNetCommunity
(
	ID number(10) not null
	,IPADDR char(15) 
	,COMMUNITY varchar2(64) 
	,constraint pk_SysNetCommunity primary key (ID)
);

comment on table t_SysNetCommunity is '�豸��ͬ��';
	comment on column t_SysNetCommunity.ID is 'ID';
	comment on column t_SysNetCommunity.IPADDR is 'IP��ַ';
	comment on column t_SysNetCommunity.COMMUNITY is '��ͬ����';


--******************************
--�����˿����ͱ�
--******************************
create table t_SysNetPortType
(
	ID number(10) not null
	,CName varchar2(64) 
	,EName varchar2(64) 
	,Description varchar2(64) 
	,constraint pk_SysNetPortType primary key (ID)
);

comment on table t_SysNetPortType is '�˿�����';
	comment on column t_SysNetPortType.ID is 'ID';
	comment on column t_SysNetPortType.CName is '������';
	comment on column t_SysNetPortType.EName is 'Ӣ����';
	comment on column t_SysNetPortType.Description is '����';


--******************************
--�����˿ڱ�
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

comment on table t_SysNetInterface is '�˿�';
	comment on column t_SysNetInterface.ID is 'ID';
	comment on column t_SysNetInterface.ObjectID is '��ض���';
	comment on column t_SysNetInterface.MonitorType_ID is '��ض�������';
	comment on column t_SysNetInterface.IfType is '�˿�����';
	comment on column t_SysNetInterface.EName is '�˿���';
	comment on column t_SysNetInterface.IpAddress is 'IP��ַ';
	comment on column t_SysNetInterface.IpMask is '����';
	comment on column t_SysNetInterface.IfStatus is '�˿�״̬';
	comment on column t_SysNetInterface.MAC is '�����ַ';
	comment on column t_SysNetInterface.DeviceID is '�����豸ID';
	comment on column t_SysNetInterface.DeviceObjectID is '�����豸ObjectID';
	comment on column t_SysNetInterface.DeviceIndex is '�����豸�˿�����';
	comment on column t_SysNetInterface.isPolling is '�Ƿ���ѯ';
	comment on column t_SysNetInterface.Description is '����';


--******************************
--����ͨ��OID��
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

comment on table t_SysNetGeneralOID is 'ͨ��OID';
	comment on column t_SysNetGeneralOID.ID is 'ID';
	comment on column t_SysNetGeneralOID.CName is 'OID������';
	comment on column t_SysNetGeneralOID.EName is 'OIDӢ����';
	comment on column t_SysNetGeneralOID.OID is 'OID';
	comment on column t_SysNetGeneralOID.Unit is '��λ';
	comment on column t_SysNetGeneralOID.isTheTable is '�Ƿ������־';


--******************************
--������ض�������
--******************************
create table t_SysNetMonitorType
(
	ID number(10) not null
	,CName varchar2(64) 
	,EName varchar2(64) 
	,constraint pk_SysNetMonitorType primary key (ID)
);

comment on table t_SysNetMonitorType is '��ض������';
	comment on column t_SysNetMonitorType.ID is 'ID';
	comment on column t_SysNetMonitorType.CName is 'OID������';
	comment on column t_SysNetMonitorType.EName is 'OIDӢ����';


--******************************
--����ָ��ͳ���
--******************************
create table t_SysNetMonitorAttrScope
(
	ID number(10) not null
	,CName varchar2(256) 
	,EName varchar2(256) 
	,Comments varchar2(256) 
	,constraint pk_SysNetMonitorAttrScope primary key (ID)
);

comment on table t_SysNetMonitorAttrScope is 'ָ��ͳ��';
	comment on column t_SysNetMonitorAttrScope.ID is 'ID';
	comment on column t_SysNetMonitorAttrScope.CName is 'ָ��������';
	comment on column t_SysNetMonitorAttrScope.EName is 'ָ��Ӣ����';
	comment on column t_SysNetMonitorAttrScope.Comments is 'ע��';


--******************************
--�������ָ����
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

comment on table t_SysNetMonitorAttrType is '���ָ���';
	comment on column t_SysNetMonitorAttrType.ID is 'ID';
	comment on column t_SysNetMonitorAttrType.MANUFACTORY_ID is '��������';
	comment on column t_SysNetMonitorAttrType.MonitorType_ID is '�豸���';
	comment on column t_SysNetMonitorAttrType.AttrType_ID is '������ָ��ID';
	comment on column t_SysNetMonitorAttrType.MANUFACTORY is '��������';
	comment on column t_SysNetMonitorAttrType.MonitorType is '�豸���';
	comment on column t_SysNetMonitorAttrType.AttrType is '������ָ��';


--******************************
--����ְ������
--******************************
create table t_SysNetFuncArea
(
	ID number(10) not null
	,SysNetSubAreaID number(10) 
	,CName varchar2(64) 
	,EName varchar2(64) 
	,constraint pk_SysNetFuncArea primary key (ID)
);

comment on table t_SysNetFuncArea is 'ְ����';
	comment on column t_SysNetFuncArea.ID is 'ID';
	comment on column t_SysNetFuncArea.SysNetSubAreaID is 'SysNetSubAreaID';
	comment on column t_SysNetFuncArea.CName is '����������';
	comment on column t_SysNetFuncArea.EName is '����Ӣ����';


--******************************
--�������ָ����
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

comment on table t_SysNetMonitorCommandType is '���ָ���';
	comment on column t_SysNetMonitorCommandType.ID is 'ID';
	comment on column t_SysNetMonitorCommandType.Manufactory_ID is '��������ID';
	comment on column t_SysNetMonitorCommandType.MonitorType_ID is '�豸���ID';
	comment on column t_SysNetMonitorCommandType.DeviceModle_ID is '�豸�ͺ�ID';
	comment on column t_SysNetMonitorCommandType.ActionGroup_ID is '������ID';
	comment on column t_SysNetMonitorCommandType.Manufactory is '��������';
	comment on column t_SysNetMonitorCommandType.MonitorType is '�豸���';
	comment on column t_SysNetMonitorCommandType.DeviceModle is '�豸�ͺ�';
	comment on column t_SysNetMonitorCommandType.ActionGroup is '������';
	comment on column t_SysNetMonitorCommandType.Command is 'ָ����';


--******************************
--������������
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

comment on table t_SysNetMonitorActionGroup is '�������';
	comment on column t_SysNetMonitorActionGroup.ID is 'ID';
	comment on column t_SysNetMonitorActionGroup.CName is '������������';
	comment on column t_SysNetMonitorActionGroup.EName is '������Ӣ����';
	comment on column t_SysNetMonitorActionGroup.ActionType is '����������';
	comment on column t_SysNetMonitorActionGroup.Comments is 'ע��';


--******************************
--�����豸��������
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

comment on table t_SysNetMonitorDeviceGroup is '�豸�������';
	comment on column t_SysNetMonitorDeviceGroup.ID is 'ID';
	comment on column t_SysNetMonitorDeviceGroup.CName is '�豸������������';
	comment on column t_SysNetMonitorDeviceGroup.EName is '�豸������Ӣ����';
	comment on column t_SysNetMonitorDeviceGroup.Condition is '�豸��������';
	comment on column t_SysNetMonitorDeviceGroup.Comments is 'ע��';


--******************************
--����������Ϣ���
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

comment on table t_SysNetMonitorTaskInfo is '������Ϣ��';
	comment on column t_SysNetMonitorTaskInfo.ID is 'ID';
	comment on column t_SysNetMonitorTaskInfo.CName is '����������';
	comment on column t_SysNetMonitorTaskInfo.EName is '����Ӣ����';
	comment on column t_SysNetMonitorTaskInfo.DeviceGroup_ID is '�豸������ID';
	comment on column t_SysNetMonitorTaskInfo.ManagerGroup_ID is '������Ա������ID';
	comment on column t_SysNetMonitorTaskInfo.TimePolicy_ID is '����ʱ�����ID';
	comment on column t_SysNetMonitorTaskInfo.TaskPriority_ID is '�������ȼ�ID';
	comment on column t_SysNetMonitorTaskInfo.OutputPolicy_ID is '����������ID';
	comment on column t_SysNetMonitorTaskInfo.ActionGroup_ID is '��������ID';
	comment on column t_SysNetMonitorTaskInfo.EventExprStr is '������ʽID���ϴ�';
	comment on column t_SysNetMonitorTaskInfo.DeviceGroup is '�豸������';
	comment on column t_SysNetMonitorTaskInfo.ManagerGroup is '������Ա������';
	comment on column t_SysNetMonitorTaskInfo.TimePolicy is '����ʱ�����';
	comment on column t_SysNetMonitorTaskInfo.TaskPriority is '�������ȼ�';
	comment on column t_SysNetMonitorTaskInfo.OutputPolicy is '����������';
	comment on column t_SysNetMonitorTaskInfo.ActionGroup is '��������';
	comment on column t_SysNetMonitorTaskInfo.ValidFlag is '������Ч�Ա�ʶ';
	comment on column t_SysNetMonitorTaskInfo.TaskStatus is '����״̬��ʶ';
	comment on column t_SysNetMonitorTaskInfo.Comments is '��������';


--******************************
--������Ա��·��Ϣ���
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

comment on table t_SysNetPartyLinkInfo is '��Ա��·��Ϣ��';
	comment on column t_SysNetPartyLinkInfo.ID is 'ID';
	comment on column t_SysNetPartyLinkInfo.MEMBER_NO is '��Ա��';
	comment on column t_SysNetPartyLinkInfo.MEMBER_NAME is '��Ա����';
	comment on column t_SysNetPartyLinkInfo.REMOTE_ADDR is '��Ա����ص�';
	comment on column t_SysNetPartyLinkInfo.LOCAL_ADDR is '�����������';
	comment on column t_SysNetPartyLinkInfo.ADDRESS is '��ַ';
	comment on column t_SysNetPartyLinkInfo.LINE_STATUS is '��·״̬';
	comment on column t_SysNetPartyLinkInfo.CONTACT is '��ϵ��';
	comment on column t_SysNetPartyLinkInfo.TELEPHONE is '��ϵ�绰';
	comment on column t_SysNetPartyLinkInfo.MOBILEPHONE is '�ֻ���';
	comment on column t_SysNetPartyLinkInfo.EMAIL is 'EMAIL';
	comment on column t_SysNetPartyLinkInfo.FAX is '����';
	comment on column t_SysNetPartyLinkInfo.PROVINCE is '����ʡ��';
	comment on column t_SysNetPartyLinkInfo.DDN_NO is '��·���';
	comment on column t_SysNetPartyLinkInfo.IN_MODE is '���뷽ʽ';
	comment on column t_SysNetPartyLinkInfo.IP_WAN is '����IP����';
	comment on column t_SysNetPartyLinkInfo.IP_LAN is '����IP����';
	comment on column t_SysNetPartyLinkInfo.IPADDR is '·��������IP';
	comment on column t_SysNetPartyLinkInfo.Interface is '·�����˿ں�';
	comment on column t_SysNetPartyLinkInfo.INTERFACE_DATE is '�ӿڿ�ͨ����';
	comment on column t_SysNetPartyLinkInfo.SOFTWARE is '�������';
	comment on column t_SysNetPartyLinkInfo.FEE_TYPE is '��������';
	comment on column t_SysNetPartyLinkInfo.SERVICEPROVIDER is '��Ӫ��';
	comment on column t_SysNetPartyLinkInfo.IF_ZIYING is '�Ƿ���Ӫ';
	comment on column t_SysNetPartyLinkInfo.IF_TUOGUAN is '�Ƿ��й�';
	comment on column t_SysNetPartyLinkInfo.HASOTHER is '����������·';
	comment on column t_SysNetPartyLinkInfo.SEAT_NO is 'ϯλ��';
	comment on column t_SysNetPartyLinkInfo.PRO is '��ע';


--******************************
--������Ա��·��Ϣ���
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

comment on table t_SysNetDelPartyLinkInfo is '��Ա��·��Ϣ��';
	comment on column t_SysNetDelPartyLinkInfo.ID is 'ID';
	comment on column t_SysNetDelPartyLinkInfo.MEMBER_NO is '��Ա��';
	comment on column t_SysNetDelPartyLinkInfo.MEMBER_NAME is '��Ա����';
	comment on column t_SysNetDelPartyLinkInfo.REMOTE_ADDR is '��Ա����ص�';
	comment on column t_SysNetDelPartyLinkInfo.LOCAL_ADDR is '�����������';
	comment on column t_SysNetDelPartyLinkInfo.ADDRESS is '��ַ';
	comment on column t_SysNetDelPartyLinkInfo.LINE_STATUS is '��·״̬';
	comment on column t_SysNetDelPartyLinkInfo.CONTACT is '��ϵ��';
	comment on column t_SysNetDelPartyLinkInfo.TELEPHONE is '��ϵ�绰';
	comment on column t_SysNetDelPartyLinkInfo.MOBILEPHONE is '�ֻ���';
	comment on column t_SysNetDelPartyLinkInfo.EMAIL is 'EMAIL';
	comment on column t_SysNetDelPartyLinkInfo.FAX is '����';
	comment on column t_SysNetDelPartyLinkInfo.PROVINCE is '����ʡ��';
	comment on column t_SysNetDelPartyLinkInfo.DDN_NO is '��·���';
	comment on column t_SysNetDelPartyLinkInfo.IN_MODE is '���뷽ʽ';
	comment on column t_SysNetDelPartyLinkInfo.IP_WAN is '����IP����';
	comment on column t_SysNetDelPartyLinkInfo.IP_LAN is '����IP����';
	comment on column t_SysNetDelPartyLinkInfo.IPADDR is '·��������IP';
	comment on column t_SysNetDelPartyLinkInfo.Interface is '·�����˿ں�';
	comment on column t_SysNetDelPartyLinkInfo.INTERFACE_DATE is '�ӿڿ�ͨ����';
	comment on column t_SysNetDelPartyLinkInfo.SOFTWARE is '�������';
	comment on column t_SysNetDelPartyLinkInfo.FEE_TYPE is '��������';
	comment on column t_SysNetDelPartyLinkInfo.SERVICEPROVIDER is '��Ӫ��';
	comment on column t_SysNetDelPartyLinkInfo.IF_ZIYING is '�Ƿ���Ӫ';
	comment on column t_SysNetDelPartyLinkInfo.IF_TUOGUAN is '�Ƿ��й�';
	comment on column t_SysNetDelPartyLinkInfo.HASOTHER is '����������·';
	comment on column t_SysNetDelPartyLinkInfo.SEAT_NO is 'ϯλ��';
	comment on column t_SysNetDelPartyLinkInfo.PRO is '��ע';


--******************************
--������Ա��·��Ϣ���
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

comment on table t_SysNetPartyLinkAddrChange is '��Ա��·��Ϣ��';
	comment on column t_SysNetPartyLinkAddrChange.ID is 'ID';
	comment on column t_SysNetPartyLinkAddrChange.RelationID is 'ID';
	comment on column t_SysNetPartyLinkAddrChange.OLDADDRESS is '���ǰ��ַ';
	comment on column t_SysNetPartyLinkAddrChange.NEWADDRESS is '������ַ';
	comment on column t_SysNetPartyLinkAddrChange.OPERATOR is '������';
	comment on column t_SysNetPartyLinkAddrChange.MonDate is '�޸�����';
	comment on column t_SysNetPartyLinkAddrChange.MonTime is '�޸�ʱ��';


--******************************
--������ض���ָ����ձ��
--******************************
create table t_SysNetMonitorActionAttr
(
	ID number(10) not null
	,ActionGroup_ID number(10) 
	,MonitorAttr_ID number(10) 
	,MonitorAttrName varchar2(256) 
	,constraint pk_SysNetMonitorActionAttr primary key (ID)
);

comment on table t_SysNetMonitorActionAttr is '��ض���ָ����ձ�';
	comment on column t_SysNetMonitorActionAttr.ID is 'ID';
	comment on column t_SysNetMonitorActionAttr.ActionGroup_ID is '������ID';
	comment on column t_SysNetMonitorActionAttr.MonitorAttr_ID is '��ض���ID';
	comment on column t_SysNetMonitorActionAttr.MonitorAttrName is 'ָ��Ӣ����';


--******************************
--����ģ���
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

comment on table t_SysNetModule is 'ģ��';
	comment on column t_SysNetModule.ID is 'ID';
	comment on column t_SysNetModule.ObjectID is '�����ض���ID';
	comment on column t_SysNetModule.MonitorType_ID is '��ض�������';
	comment on column t_SysNetModule.DeviceID is '�����豸ID';
	comment on column t_SysNetModule.DeviceObjectID is '�����豸ObjectID';
	comment on column t_SysNetModule.Name is '����';
	comment on column t_SysNetModule.Description is '����';
	comment on column t_SysNetModule.ModuleIndex is 'ģ������';
	comment on column t_SysNetModule.EntPhyIndex is '��������';


--******************************
--�����澯���ʽ��Ϣ���
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

comment on table t_SysNetEventExpr is '�澯���ʽ��Ϣ��';
	comment on column t_SysNetEventExpr.ID is 'ID';
	comment on column t_SysNetEventExpr.CNAME is '�����¼���';
	comment on column t_SysNetEventExpr.ENAME is 'Ӣ���¼���';
	comment on column t_SysNetEventExpr.WarningLEVEL is '�¼�����';
	comment on column t_SysNetEventExpr.EventTypeID is '�¼�����';
	comment on column t_SysNetEventExpr.SubEventTypeID is '�¼�������';
	comment on column t_SysNetEventExpr.GIVEUPTIME is '�澯���ʱ��';
	comment on column t_SysNetEventExpr.CONTROL is '���ƶ�����';
	comment on column t_SysNetEventExpr.EXPR is '���ʽ������';
	comment on column t_SysNetEventExpr.BRIEF is '�¼�����';
	comment on column t_SysNetEventExpr.DISCRIPTION is '�¼�������';
	comment on column t_SysNetEventExpr.MSGGROUP_ID is '��Ϣ��ID';
	comment on column t_SysNetEventExpr.ADMINGROUP_ID is '����Ա��ID';


--******************************
--�����¼����ͱ�
--******************************
create table t_SysNetEventType
(
	ID number(10) not null
	,CName varchar2(64) 
	,EName varchar2(64) 
	,constraint pk_SysNetEventType primary key (ID)
);

comment on table t_SysNetEventType is '�¼�����';
	comment on column t_SysNetEventType.ID is 'ID';
	comment on column t_SysNetEventType.CName is '�¼�����������';
	comment on column t_SysNetEventType.EName is '�¼�����Ӣ����';


--******************************
--�����¼������ͱ�
--******************************
create table t_SysNetSubEventType
(
	ID number(10) not null
	,CName varchar2(64) 
	,EName varchar2(64) 
	,constraint pk_SysNetSubEventType primary key (ID)
);

comment on table t_SysNetSubEventType is '�¼�������';
	comment on column t_SysNetSubEventType.ID is 'ID';
	comment on column t_SysNetSubEventType.CName is '�¼�������������';
	comment on column t_SysNetSubEventType.EName is '�¼�������Ӣ����';


--******************************
--�����¼������
--******************************
create table t_SysNetEventLevel
(
	ID number(10) not null
	,CName varchar2(64) 
	,EName varchar2(64) 
	,DISCRIPTION varchar2(256) 
	,constraint pk_SysNetEventLevel primary key (ID)
);

comment on table t_SysNetEventLevel is '�¼�����';
	comment on column t_SysNetEventLevel.ID is 'ID';
	comment on column t_SysNetEventLevel.CName is '�¼�����������';
	comment on column t_SysNetEventLevel.EName is '�¼�����Ӣ����';
	comment on column t_SysNetEventLevel.DISCRIPTION is '�¼�����������';


--******************************
--��������������������
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

comment on table t_SysNetMonitorDeviceTask is '���������������';
	comment on column t_SysNetMonitorDeviceTask.ID is 'ID';
	comment on column t_SysNetMonitorDeviceTask.ObjectID is '�����ض���ID';
	comment on column t_SysNetMonitorDeviceTask.IPAddress is 'IP��ַ';
	comment on column t_SysNetMonitorDeviceTask.Manufactory_ID is '�����豸����ID';
	comment on column t_SysNetMonitorDeviceTask.InstructChain is 'ָ��';
	comment on column t_SysNetMonitorDeviceTask.InstructAlias is 'ָ�����';
	comment on column t_SysNetMonitorDeviceTask.InstructArgs is 'ָ�������';
	comment on column t_SysNetMonitorDeviceTask.DefParamChain is 'ָ�귧ֵ��';
	comment on column t_SysNetMonitorDeviceTask.Flag is '������־';
	comment on column t_SysNetMonitorDeviceTask.SecondID is 'PrimID';


--******************************
--��������ָ��ָ�꼯���
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

comment on table t_SysNetMonitorTaskInstAttrs is '����ָ��ָ�꼯��';
	comment on column t_SysNetMonitorTaskInstAttrs.ID is 'ID';
	comment on column t_SysNetMonitorTaskInstAttrs.Manufactory_ID is '�����豸����ID';
	comment on column t_SysNetMonitorTaskInstAttrs.InstructAlias is 'ָ�����';
	comment on column t_SysNetMonitorTaskInstAttrs.DEVICETYPE is '�豸�ͺ�';
	comment on column t_SysNetMonitorTaskInstAttrs.AttrsChain is 'ָ�괮';
	comment on column t_SysNetMonitorTaskInstAttrs.DefRegularChain is 'ָ�����';
	comment on column t_SysNetMonitorTaskInstAttrs.DefParamChain is 'ָ�귧ֵ��';


--******************************
--�������������
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

comment on table t_SysNetMonitorTaskResult is '��������';
	comment on column t_SysNetMonitorTaskResult.ObjectID is '�����ض���ID';
	comment on column t_SysNetMonitorTaskResult.Task_ID is '����ID';
	comment on column t_SysNetMonitorTaskResult.OperateTime is 'ִ�д���';
	comment on column t_SysNetMonitorTaskResult.MonDate is '�ɼ�������';
	comment on column t_SysNetMonitorTaskResult.MonTime is '�ɼ���ʱ��';
	comment on column t_SysNetMonitorTaskResult.InstructChain is 'ָ�';
	comment on column t_SysNetMonitorTaskResult.ResultChain is '�����';
	comment on column t_SysNetMonitorTaskResult.Flag is '����ִ�б�ʶ';


--******************************
--�������߱��
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

comment on table t_SysNetBaseLine is '���߱�';
	comment on column t_SysNetBaseLine.ID is 'ID';
	comment on column t_SysNetBaseLine.MANUFACTORY_ID is '��������';
	comment on column t_SysNetBaseLine.Name is '������';
	comment on column t_SysNetBaseLine.SerialUsed is '�豸�ͺ�';
	comment on column t_SysNetBaseLine.data is '�ļ�����';
	comment on column t_SysNetBaseLine.memo is '��ע';
	comment on column t_SysNetBaseLine.Flag is '������־';


--******************************
--��������������
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

comment on table t_SysNetBaseLineTask is '���������';
	comment on column t_SysNetBaseLineTask.ID is 'ID';
	comment on column t_SysNetBaseLineTask.Name is '����������';
	comment on column t_SysNetBaseLineTask.BaseLineIDList is '����ID�б�';
	comment on column t_SysNetBaseLineTask.DeviceIDList is '�豸ID�б�';
	comment on column t_SysNetBaseLineTask.GenDate is '��������';
	comment on column t_SysNetBaseLineTask.GenTime is '����ʱ��';
	comment on column t_SysNetBaseLineTask.GenUser is '������';
	comment on column t_SysNetBaseLineTask.memo is '��ע';


--******************************
--�������߽�����
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

comment on table t_SysNetBaseLineResult is '���߽����';
	comment on column t_SysNetBaseLineResult.ID is 'ID';
	comment on column t_SysNetBaseLineResult.BaseLineName is '��������';
	comment on column t_SysNetBaseLineResult.DeviceObjID is '�豸ObjID';
	comment on column t_SysNetBaseLineResult.DeviceIP is '�豸IP';
	comment on column t_SysNetBaseLineResult.Result is '���߽��';
	comment on column t_SysNetBaseLineResult.GenDate is '��������';
	comment on column t_SysNetBaseLineResult.GenTime is '����ʱ��';
	comment on column t_SysNetBaseLineResult.GenUser is '������';
	comment on column t_SysNetBaseLineResult.Flag is '������־';


--******************************
--������Ա��·״̬��Ϣ���
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

comment on table t_SysNetPartyLinkStatusInfo is '��Ա��·״̬��Ϣ��';
	comment on column t_SysNetPartyLinkStatusInfo.MonDate is '�ɼ�������';
	comment on column t_SysNetPartyLinkStatusInfo.MonTime is '�ɼ���ʱ��';
	comment on column t_SysNetPartyLinkStatusInfo.SEAT_NO is 'ϯλ��';
	comment on column t_SysNetPartyLinkStatusInfo.IPADDR is '·��������IP';
	comment on column t_SysNetPartyLinkStatusInfo.Interface is '·�����˿ں�';
	comment on column t_SysNetPartyLinkStatusInfo.status is '��·״̬';


--******************************
--������ԱSDH��·��ϸ���
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

comment on table t_SysNetMemberSDHLineInfo is '��ԱSDH��·��ϸ��';
	comment on column t_SysNetMemberSDHLineInfo.ID is 'ID';
	comment on column t_SysNetMemberSDHLineInfo.SeqNo is '���к�';
	comment on column t_SysNetMemberSDHLineInfo.MemContractNo is '��ͬ��';
	comment on column t_SysNetMemberSDHLineInfo.ApplyPerson is '������';
	comment on column t_SysNetMemberSDHLineInfo.MonthlyRental is '�������';
	comment on column t_SysNetMemberSDHLineInfo.MemberNo is '��Ա��';
	comment on column t_SysNetMemberSDHLineInfo.ParticipantName is '��Ա����';
	comment on column t_SysNetMemberSDHLineInfo.ClientManager is '�ͻ�����';
	comment on column t_SysNetMemberSDHLineInfo.Bandwidth is '����';
	comment on column t_SysNetMemberSDHLineInfo.InterfaceType is '�ӿ���';
	comment on column t_SysNetMemberSDHLineInfo.RemoteCircuit is '��;��·����';
	comment on column t_SysNetMemberSDHLineInfo.LocalCircuit is '���ص�·����';
	comment on column t_SysNetMemberSDHLineInfo.Remark is '��ע';
	comment on column t_SysNetMemberSDHLineInfo.EndALineAddress is 'A�˽����ַ';
	comment on column t_SysNetMemberSDHLineInfo.EndAContact is 'A����ϵ��';
	comment on column t_SysNetMemberSDHLineInfo.EndZLineAddress is 'Z�˽����ַ';
	comment on column t_SysNetMemberSDHLineInfo.ContactName is '��ϵ��';
	comment on column t_SysNetMemberSDHLineInfo.TELEPHONE is '��ϵ�绰';
	comment on column t_SysNetMemberSDHLineInfo.MOBILEPHONE is '�ֻ���';
	comment on column t_SysNetMemberSDHLineInfo.IPADDR is '·��������IP';
	comment on column t_SysNetMemberSDHLineInfo.Interface is '·�����˿ں�';
	comment on column t_SysNetMemberSDHLineInfo.PROVINCE is '����ʡ��';
	comment on column t_SysNetMemberSDHLineInfo.StartPortID is '��ʼ�豸�˿�';
	comment on column t_SysNetMemberSDHLineInfo.StartJump is '��ʼ�豸���Ӷ�';
	comment on column t_SysNetMemberSDHLineInfo.LINE_STATUS is '��·״̬';
	comment on column t_SysNetMemberSDHLineInfo.DataCenterID is '�������Ĵ���';


--******************************
--����DDN��·��Ϣ���
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

comment on table t_SysNetDDNLinkInfo is 'DDN��·��Ϣ��';
	comment on column t_SysNetDDNLinkInfo.ID is 'ID';
	comment on column t_SysNetDDNLinkInfo.ClientName is '�ͻ�����';
	comment on column t_SysNetDDNLinkInfo.DDN_NO is '��·���';
	comment on column t_SysNetDDNLinkInfo.BusinessUnit is 'ҵ��Ԫ';
	comment on column t_SysNetDDNLinkInfo.Bandwidth is '����';
	comment on column t_SysNetDDNLinkInfo.EndAAddress is '�׶˵�ַ';
	comment on column t_SysNetDDNLinkInfo.EndAContactName is '�׶���ϵ��';
	comment on column t_SysNetDDNLinkInfo.EndZAddress is '�Ҷ˵�ַ';
	comment on column t_SysNetDDNLinkInfo.EndZContactName is '�Ҷ���ϵ��';


--******************************
--�����ǻ�Ա��·ʹ����Ϣ��
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

comment on table t_SysNetPseudMemberLinkInfo is '�ǻ�Ա��·ʹ����Ϣ';
	comment on column t_SysNetPseudMemberLinkInfo.ID is 'ID';
	comment on column t_SysNetPseudMemberLinkInfo.SeqNo is '���к�';
	comment on column t_SysNetPseudMemberLinkInfo.MemContractNo is '��ͬ��';
	comment on column t_SysNetPseudMemberLinkInfo.LineUsage is '��·��;';
	comment on column t_SysNetPseudMemberLinkInfo.LocalCircuit is '���ص�·����';
	comment on column t_SysNetPseudMemberLinkInfo.RemoteCircuit is '��;��·����';
	comment on column t_SysNetPseudMemberLinkInfo.BusinessUnit is 'ҵ��';
	comment on column t_SysNetPseudMemberLinkInfo.Bandwidth is '����';
	comment on column t_SysNetPseudMemberLinkInfo.ApplyPerson is '������';
	comment on column t_SysNetPseudMemberLinkInfo.MonthlyRental is '�������';
	comment on column t_SysNetPseudMemberLinkInfo.EndAAddress is '�׶˵�ַ';
	comment on column t_SysNetPseudMemberLinkInfo.EndAContactName is '�׶���ϵ��';
	comment on column t_SysNetPseudMemberLinkInfo.EndZAddress is '�Ҷ˵�ַ';
	comment on column t_SysNetPseudMemberLinkInfo.EndZContactName is '�Ҷ���ϵ��';
	comment on column t_SysNetPseudMemberLinkInfo.Telephone is '�Ҷ˵绰����';
	comment on column t_SysNetPseudMemberLinkInfo.LineInfo is '��·��Ϣ';
	comment on column t_SysNetPseudMemberLinkInfo.IPADDR is '·��������IP';


--******************************
--����Զ���豸��Ϣ��
--******************************
create table t_SysNetOuterDeviceInfo
(
	ID number(10) not null
	,IPADDR char(15) 
	,NAME varchar2(128) 
	,memo varchar2(256) 
);

comment on table t_SysNetOuterDeviceInfo is 'Զ���豸��Ϣ';
	comment on column t_SysNetOuterDeviceInfo.ID is 'ID';
	comment on column t_SysNetOuterDeviceInfo.IPADDR is 'IP��ַ  ';
	comment on column t_SysNetOuterDeviceInfo.NAME is '�豸���� ';
	comment on column t_SysNetOuterDeviceInfo.memo is '��ע';


--******************************
--��������ping�����
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

comment on table t_SysLocalPingResultInfo is '����ping���';
	comment on column t_SysLocalPingResultInfo.ID is 'ID';
	comment on column t_SysLocalPingResultInfo.SouIPADDR is 'ԴIP��ַ  ';
	comment on column t_SysLocalPingResultInfo.SouNAME is 'Դ�豸���� ';
	comment on column t_SysLocalPingResultInfo.TarIPADDR is 'Ŀ��IP��ַ  ';
	comment on column t_SysLocalPingResultInfo.TarNAME is 'Ŀ���豸���� ';
	comment on column t_SysLocalPingResultInfo.PDateSta is '��������';
	comment on column t_SysLocalPingResultInfo.PTimeSta is 'ʱ���';
	comment on column t_SysLocalPingResultInfo.ConnRate is '��ͨ��';


--******************************
--����Զ��ping�����
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

comment on table t_SysRomotePingResultInfo is 'Զ��ping���';
	comment on column t_SysRomotePingResultInfo.ID is 'ID';
	comment on column t_SysRomotePingResultInfo.SouIPADDR is 'ԴIP��ַ  ';
	comment on column t_SysRomotePingResultInfo.SouNAME is 'Դ�豸���� ';
	comment on column t_SysRomotePingResultInfo.TarIPADDR is 'Ŀ��IP��ַ  ';
	comment on column t_SysRomotePingResultInfo.TarNAME is 'Ŀ���豸���� ';
	comment on column t_SysRomotePingResultInfo.PDateSta is '��������';
	comment on column t_SysRomotePingResultInfo.PTimeSta is 'ʱ���';
	comment on column t_SysRomotePingResultInfo.ConnRate is '��ͨ��';
	comment on column t_SysRomotePingResultInfo.TimeDlyMin is '��Сʱ��';
	comment on column t_SysRomotePingResultInfo.TimeDlyMax is '���ʱ��';
	comment on column t_SysRomotePingResultInfo.TimeDlyAvg is 'ƽ��ʱ��';


--******************************
--��������ϵͳǰ�ñ�����Ӧ��Ϣ��
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

comment on table t_SysTradeFrontOrderRttStat is '����ϵͳǰ�ñ�����Ӧ��Ϣ';
	comment on column t_SysTradeFrontOrderRttStat.MonDate is '��������';
	comment on column t_SysTradeFrontOrderRttStat.MonTime is '����ʱ��';
	comment on column t_SysTradeFrontOrderRttStat.ObjectID is 'ǰ�ö���';
	comment on column t_SysTradeFrontOrderRttStat.OrderCount is '������';
	comment on column t_SysTradeFrontOrderRttStat.OrderRttSum is '������Ӧʱ���';
	comment on column t_SysTradeFrontOrderRttStat.OrderMaxRtt is '��󱨵���Ӧʱ��';
	comment on column t_SysTradeFrontOrderRttStat.OrderMinRtt is '��С������Ӧʱ��';
	comment on column t_SysTradeFrontOrderRttStat.OrderRttSqu is '1������Ӧʱ�����';
	comment on column t_SysTradeFrontOrderRttStat.OrderRttCutDistrib is '1������Ӧʱ��ֲ�';


--******************************
--��������ϵͳǰ�ñ����ֲ������
--******************************
create table t_SysTradeOrderRttCutLine
(
	MonDate char(8) 
	,MonTime char(8) 
	,UserName varchar2(64) 
	,OrderRttCutLine varchar2(128) 
	,OrderRttWidth number(10) 
);

comment on table t_SysTradeOrderRttCutLine is '����ϵͳǰ�ñ����ֲ�����';
	comment on column t_SysTradeOrderRttCutLine.MonDate is '������Ч����';
	comment on column t_SysTradeOrderRttCutLine.MonTime is '�����޸�ʱ��';
	comment on column t_SysTradeOrderRttCutLine.UserName is '�޸��û�����';
	comment on column t_SysTradeOrderRttCutLine.OrderRttCutLine is '��Ӧʱ��ֲ�';
	comment on column t_SysTradeOrderRttCutLine.OrderRttWidth is 'ͳ�ƿ�����';


--******************************
--������Աϯλ����״̬��
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

comment on table t_SysParticTradeOrderStates is '��Աϯλ����״̬';
	comment on column t_SysParticTradeOrderStates.ParticipantID is '��Ա����';
	comment on column t_SysParticTradeOrderStates.UserID is '�����û�����';
	comment on column t_SysParticTradeOrderStates.MonDate is '����ͳ������';
	comment on column t_SysParticTradeOrderStates.MonTime is '����ͳ��ʱ��';
	comment on column t_SysParticTradeOrderStates.StaticWidth is 'ͳ��ʱ��(sec)';
	comment on column t_SysParticTradeOrderStates.FrontID is 'ǰ��ID';
	comment on column t_SysParticTradeOrderStates.OrderCount is '������';
	comment on column t_SysParticTradeOrderStates.CancleCount is '������';
	comment on column t_SysParticTradeOrderStates.QueryCount is '��ѯ��';
	comment on column t_SysParticTradeOrderStates.TradeCount is '�ɽ���';
	comment on column t_SysParticTradeOrderStates.TradeMoney is '�ɽ����';
	comment on column t_SysParticTradeOrderStates.OrderCntMax is '��󱨵���';
	comment on column t_SysParticTradeOrderStates.CancleCntMax is '��󳷵���';
	comment on column t_SysParticTradeOrderStates.QueryCntMax is '����ѯ��';
	comment on column t_SysParticTradeOrderStates.TradeCntMax is '���ɽ���';
	comment on column t_SysParticTradeOrderStates.TradeMoneyMax is '���ɽ����';


--******************************
--����ϵͳ·����Ϣ��
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

comment on table t_RouterInfo is 'ϵͳ·����Ϣ';
	comment on column t_RouterInfo.HostName is '��������';
	comment on column t_RouterInfo.MonDate is '�ɼ�������';
	comment on column t_RouterInfo.MonTime is '�ɼ���ʱ��';
	comment on column t_RouterInfo.Dev is '�豸�ӿ���';
	comment on column t_RouterInfo.Destination is 'Ŀ������ip��ַ';
	comment on column t_RouterInfo.Gateway is '����ip��ַ';
	comment on column t_RouterInfo.Mask is '����ip��ַ';
	comment on column t_RouterInfo.Flag is '����״̬';
	comment on column t_RouterInfo.RefCnt is '��������';
	comment on column t_RouterInfo.Use is 'ʹ�ü���';
	comment on column t_RouterInfo.Metric is 'metricֵ';
	comment on column t_RouterInfo.Mtu is 'mtuֵ';
	comment on column t_RouterInfo.Win is 'winֵ';
	comment on column t_RouterInfo.Rtt is 'rttֵ';


--******************************
--��������I/O��Ϣ��
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

comment on table t_DiskIO is '����I/O��Ϣ';
	comment on column t_DiskIO.HostName is '��������';
	comment on column t_DiskIO.MonDate is '�ɼ�������';
	comment on column t_DiskIO.MonTime is '�ɼ���ʱ��';
	comment on column t_DiskIO.PartName is '������';
	comment on column t_DiskIO.ReadMerges is 'ÿ��ReadMerge��';
	comment on column t_DiskIO.WriteMerges is 'ÿ��WriteMerge��';
	comment on column t_DiskIO.ReadIOs is 'ÿ��ReadIO��';
	comment on column t_DiskIO.WriteIOs is 'ÿ��WriteIO��';
	comment on column t_DiskIO.ReadKBs is 'ÿ��Read�ֽ���';
	comment on column t_DiskIO.WriteKBs is 'ÿ��Write�ֽ���';
	comment on column t_DiskIO.SizeVal is 'Sizeֵ';
	comment on column t_DiskIO.QueueVal is 'Queueֵ';
	comment on column t_DiskIO.Svc_t is 'Svc_tֵ';
	comment on column t_DiskIO.Busy is '��æ�ٷ���';


--******************************
--����ϵͳ״̬��Ϣ��
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

comment on table t_StatInfo is 'ϵͳ״̬��Ϣ';
	comment on column t_StatInfo.HostName is '��������';
	comment on column t_StatInfo.MonDate is '�ɼ�������';
	comment on column t_StatInfo.MonTime is '�ɼ���ʱ��';
	comment on column t_StatInfo.ProcRun is '��Ծ������';
	comment on column t_StatInfo.ProcBlk is '����������';
	comment on column t_StatInfo.SwapIn is 'ÿ���ɴ��̽���Swap��ҳ����';
	comment on column t_StatInfo.SwapOut is 'ÿ����Swap������̵�ҳ����';
	comment on column t_StatInfo.BlockIn is 'ÿ��ӿ��豸�����Block��';
	comment on column t_StatInfo.BlockOut is 'ÿ������豸д���Block��';
	comment on column t_StatInfo.Inter is 'ÿ���豸�жδ���';
	comment on column t_StatInfo.Context is 'ÿ���������л�����';
	comment on column t_StatInfo.CPUUser is '�û�̬CPU�ٷ���';
	comment on column t_StatInfo.CPUSys is 'ϵͳ̬CPU�ٷ���';
	comment on column t_StatInfo.CPUIdle is '����̬CPU�ٷ���';
	comment on column t_StatInfo.CPUIOWait is 'IO�ȴ�̬CPU�ٷ���';
	comment on column t_StatInfo.CPUSteal is '��ȡ̬CPU�ٷ���';


--******************************
--����������Ϣ��
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

comment on table t_TopProcessInfo is '������Ϣ';
	comment on column t_TopProcessInfo.HostName is '��������';
	comment on column t_TopProcessInfo.MonDate is '�ɼ�������';
	comment on column t_TopProcessInfo.MonTime is '�ɼ���ʱ��';
	comment on column t_TopProcessInfo.CPU is '��������';
	comment on column t_TopProcessInfo.TTY is '�ն���';
	comment on column t_TopProcessInfo.PID is '���̺�';
	comment on column t_TopProcessInfo.USERNAME is '�û���';
	comment on column t_TopProcessInfo.PRI is '��������ȼ�';
	comment on column t_TopProcessInfo.NI is '�����niceֵ';
	comment on column t_TopProcessInfo.SSIZE is '����Ĵ�����������ټ���ջ�ռ�Ĵ�С';
	comment on column t_TopProcessInfo.RES is '����ʹ�õ������ڴ��������';
	comment on column t_TopProcessInfo.STATE is '�����״̬';
	comment on column t_TopProcessInfo.STIME is '������ʼʱʹ�õ���CPUʱ��';
	comment on column t_TopProcessInfo.pWCPU is '���̵�CPU������Ȩ�ذٷֱ�';
	comment on column t_TopProcessInfo.pCPU is '���̵�ԭʼ��CPU�����ʰٷֱ�';
	comment on column t_TopProcessInfo.COMMAND is '�������̵�������';


--******************************
--�����¼�������Ϣ��
--******************************
create table t_SysEventDescrip
(
	EventDesID char(12) 
	,UserName varchar2(64) 
	,MonDate char(8) 
	,MonTime char(8) 
	,EventDes varchar2(400) 
);

comment on table t_SysEventDescrip is '�¼�������Ϣ';
	comment on column t_SysEventDescrip.EventDesID is '����ID��';
	comment on column t_SysEventDescrip.UserName is '�¼�������';
	comment on column t_SysEventDescrip.MonDate is '�¼���������';
	comment on column t_SysEventDescrip.MonTime is '�¼�����ʱ��';
	comment on column t_SysEventDescrip.EventDes is '��������';


--******************************
--������Ա��·���ñ��
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

comment on table t_SysMemberLinkCost is '��Ա��·���ñ�';
	comment on column t_SysMemberLinkCost.ID is 'ID';
	comment on column t_SysMemberLinkCost.ParticipantName is '��Ա����';
	comment on column t_SysMemberLinkCost.DDN_NO is '��·���';
	comment on column t_SysMemberLinkCost.ServiceProvider is '��Ӫ��';
	comment on column t_SysMemberLinkCost.Pay_Date is '��������';
	comment on column t_SysMemberLinkCost.B_Pay_Date is '������ʼ����';
	comment on column t_SysMemberLinkCost.D_Pay_Date is '������ֹ����';
	comment on column t_SysMemberLinkCost.Charge is '���';
	comment on column t_SysMemberLinkCost.Fee_Type is '��������';
	comment on column t_SysMemberLinkCost.Pro is '��ע';


--******************************
--������Ա��·������
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

comment on table t_SysNetPartylinkMonthlyRent is '��Ա��·�����';
	comment on column t_SysNetPartylinkMonthlyRent.ID is 'ID';
	comment on column t_SysNetPartylinkMonthlyRent.LineName is '��·����';
	comment on column t_SysNetPartylinkMonthlyRent.DDN_NO is '��·���';
	comment on column t_SysNetPartylinkMonthlyRent.ServiceProvider is '��Ӫ��';
	comment on column t_SysNetPartylinkMonthlyRent.MonthlyRental is '�������';
	comment on column t_SysNetPartylinkMonthlyRent.Remark is '��ע';


--******************************
--�����ǻ�Ա��·��Ϣ���
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

comment on table t_SysNetNonPartyLinkInfo is '�ǻ�Ա��·��Ϣ��';
	comment on column t_SysNetNonPartyLinkInfo.ID is 'ID';
	comment on column t_SysNetNonPartyLinkInfo.MEMBER_NO is '��Ա��';
	comment on column t_SysNetNonPartyLinkInfo.MEMBER_NAME is '��Ա����';
	comment on column t_SysNetNonPartyLinkInfo.REMOTE_ADDR is '��Ա����ص�';
	comment on column t_SysNetNonPartyLinkInfo.LOCAL_ADDR is '�����������';
	comment on column t_SysNetNonPartyLinkInfo.ADDRESS is '��ַ';
	comment on column t_SysNetNonPartyLinkInfo.LINE_STATUS is '��·״̬';
	comment on column t_SysNetNonPartyLinkInfo.CONTACT is '��ϵ��';
	comment on column t_SysNetNonPartyLinkInfo.TELEPHONE is '��ϵ�绰';
	comment on column t_SysNetNonPartyLinkInfo.MOBILEPHONE is '�ֻ���';
	comment on column t_SysNetNonPartyLinkInfo.EMAIL is 'EMAIL';
	comment on column t_SysNetNonPartyLinkInfo.FAX is '����';
	comment on column t_SysNetNonPartyLinkInfo.PROVINCE is '����ʡ��';
	comment on column t_SysNetNonPartyLinkInfo.DDN_NO is '��·���';
	comment on column t_SysNetNonPartyLinkInfo.IN_MODE is '���뷽ʽ';
	comment on column t_SysNetNonPartyLinkInfo.IP_WAN is '����IP����';
	comment on column t_SysNetNonPartyLinkInfo.IP_LAN is '����IP����';
	comment on column t_SysNetNonPartyLinkInfo.IPADDR is '·��������IP';
	comment on column t_SysNetNonPartyLinkInfo.Interface is '·�����˿ں�';
	comment on column t_SysNetNonPartyLinkInfo.INTERFACE_DATE is '�ӿڿ�ͨ����';
	comment on column t_SysNetNonPartyLinkInfo.SOFTWARE is '�������';
	comment on column t_SysNetNonPartyLinkInfo.FEE_TYPE is '��������';
	comment on column t_SysNetNonPartyLinkInfo.SERVICEPROVIDER is '��Ӫ��';
	comment on column t_SysNetNonPartyLinkInfo.IF_ZIYING is '�Ƿ���Ӫ';
	comment on column t_SysNetNonPartyLinkInfo.IF_TUOGUAN is '�Ƿ��й�';
	comment on column t_SysNetNonPartyLinkInfo.HASOTHER is '����������·';
	comment on column t_SysNetNonPartyLinkInfo.SEAT_NO is 'ϯλ��';
	comment on column t_SysNetNonPartyLinkInfo.PRO is '��ע';


