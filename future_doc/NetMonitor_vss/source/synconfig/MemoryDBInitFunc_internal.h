/////////////////////////////////////////////////////////////////////////
///@system 网络监控系统
///@company 上海期货信息技术有限公司
///@file MemoryDBInitFunc_internal.h
///@brief 定义了初始化内存数据库的函数，由脚本生产而成，勿直接修改本文件
///@history
///20110620	李志伟		创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef __MEMORY_DB_INIT_FUNC_INTERNAL_H
#define __MEMORY_DB_INIT_FUNC_INTERNAL_H

#include <SQLAPI.h>
#include <CMemoryDB.h>

#define FUNC_NAME(tag) InitMem##tag


void FUNC_NAME(SysNetSubAreaIP)(SACommand & records, void * data);

void FUNC_NAME(SysNetInterface)(SACommand & records, void * data);

void FUNC_NAME(SysMemberLinkCost)(SACommand & records, void * data);

void FUNC_NAME(SysNetEventLevel)(SACommand & records, void * data);

void FUNC_NAME(SysNetGatherTask)(SACommand & records, void * data);

void FUNC_NAME(SysNetMonitorAttrType)(SACommand & records, void * data);

void FUNC_NAME(SysNetDelPartyLinkInfo)(SACommand & records, void * data);

void FUNC_NAME(SysNetBaseLine)(SACommand & records, void * data);

void FUNC_NAME(SysNetMonitorCommandType)(SACommand & records, void * data);

void FUNC_NAME(SysNetMonitorDeviceTask)(SACommand & records, void * data);

void FUNC_NAME(SysNetMonitorActionAttr)(SACommand & records, void * data);

void FUNC_NAME(SysNetMonitorType)(SACommand & records, void * data);

void FUNC_NAME(SysNetMonitorActionGroup)(SACommand & records, void * data);

void FUNC_NAME(SysNetTimePolicy)(SACommand & records, void * data);

void FUNC_NAME(SysNetDevice)(SACommand & records, void * data);

void FUNC_NAME(SysNetOuterDeviceInfo)(SACommand & records, void * data);

void FUNC_NAME(SysNetGeneralOID)(SACommand & records, void * data);

void FUNC_NAME(SysNetMonitorAttrScope)(SACommand & records, void * data);

void FUNC_NAME(SysNetCommunity)(SACommand & records, void * data);

void FUNC_NAME(SysNetSubEventType)(SACommand & records, void * data);

void FUNC_NAME(SysNetPartyLinkInfo)(SACommand & records, void * data);

void FUNC_NAME(SysNetBaseLineTask)(SACommand & records, void * data);

void FUNC_NAME(SysNetMonitorTaskInstAttrs)(SACommand & records, void * data);

void FUNC_NAME(SysNetManufactory)(SACommand & records, void * data);

void FUNC_NAME(SysNetDeviceType)(SACommand & records, void * data);

void FUNC_NAME(SysNetDDNLinkInfo)(SACommand & records, void * data);

void FUNC_NAME(SysNetDeviceLinked)(SACommand & records, void * data);

void FUNC_NAME(SysNetMonitorDeviceGroup)(SACommand & records, void * data);

void FUNC_NAME(SysNetPartylinkMonthlyRent)(SACommand & records, void * data);

void FUNC_NAME(SysNetPseudMemberLinkInfo)(SACommand & records, void * data);

void FUNC_NAME(SysNetModule)(SACommand & records, void * data);

void FUNC_NAME(SysNetMemberSDHLineInfo)(SACommand & records, void * data);

void FUNC_NAME(SysNetArea)(SACommand & records, void * data);

void FUNC_NAME(SysNetNonPartyLinkInfo)(SACommand & records, void * data);

void FUNC_NAME(SysNetPartyLinkAddrChange)(SACommand & records, void * data);

void FUNC_NAME(SysNetEventExpr)(SACommand & records, void * data);

void FUNC_NAME(SysNetDeviceCategory)(SACommand & records, void * data);

void FUNC_NAME(SysNetSubArea)(SACommand & records, void * data);

void FUNC_NAME(SysNetEventType)(SACommand & records, void * data);

void FUNC_NAME(SysNetOID)(SACommand & records, void * data);

void FUNC_NAME(SysNetMonitorTaskInfo)(SACommand & records, void * data);

void FUNC_NAME(SysNetFuncArea)(SACommand & records, void * data);


// 定义初始化内存数据库的回调结构
typedef struct {
    const char * table;
    DBOperator::searchHander_t initCB;
    DBOperator::searchHander_t setIDCB;
} memoryInitData_t;


extern map<string, int> g_idMaker;

extern CMemoryDB *pMemoryDB;

// 初始化内存数据库中表的起始索引值
void InitIDMaker(SACommand & records, void * data)
{
    assert(data);

    //TODO modify table
    static int prefix = 2; // strlen("t_");

    int id = records.Field(1).asLong() +1;
    const char * table = (const char *)data + prefix;
    g_idMaker[table] = id;
}

#define MEM_DB_INIT_ITEM(tag) {"t_"#tag, FUNC_NAME(tag), InitIDMaker}

static memoryInitData_t memInitData[] = {
	MEM_DB_INIT_ITEM(SysNetSubAreaIP),
	MEM_DB_INIT_ITEM(SysNetInterface),
	MEM_DB_INIT_ITEM(SysMemberLinkCost),
	MEM_DB_INIT_ITEM(SysNetEventLevel),
	MEM_DB_INIT_ITEM(SysNetGatherTask),
	MEM_DB_INIT_ITEM(SysNetMonitorAttrType),
	MEM_DB_INIT_ITEM(SysNetDelPartyLinkInfo),
	MEM_DB_INIT_ITEM(SysNetBaseLine),
	MEM_DB_INIT_ITEM(SysNetMonitorCommandType),
	MEM_DB_INIT_ITEM(SysNetMonitorDeviceTask),
	MEM_DB_INIT_ITEM(SysNetMonitorActionAttr),
	MEM_DB_INIT_ITEM(SysNetMonitorType),
	MEM_DB_INIT_ITEM(SysNetMonitorActionGroup),
	MEM_DB_INIT_ITEM(SysNetTimePolicy),
	MEM_DB_INIT_ITEM(SysNetDevice),
	MEM_DB_INIT_ITEM(SysNetOuterDeviceInfo),
	MEM_DB_INIT_ITEM(SysNetGeneralOID),
	MEM_DB_INIT_ITEM(SysNetMonitorAttrScope),
	MEM_DB_INIT_ITEM(SysNetCommunity),
	MEM_DB_INIT_ITEM(SysNetSubEventType),
	MEM_DB_INIT_ITEM(SysNetPartyLinkInfo),
	MEM_DB_INIT_ITEM(SysNetBaseLineTask),
	MEM_DB_INIT_ITEM(SysNetMonitorTaskInstAttrs),
	MEM_DB_INIT_ITEM(SysNetManufactory),
	MEM_DB_INIT_ITEM(SysNetDeviceType),
	MEM_DB_INIT_ITEM(SysNetDDNLinkInfo),
	MEM_DB_INIT_ITEM(SysNetDeviceLinked),
	MEM_DB_INIT_ITEM(SysNetMonitorDeviceGroup),
	MEM_DB_INIT_ITEM(SysNetPartylinkMonthlyRent),
	MEM_DB_INIT_ITEM(SysNetPseudMemberLinkInfo),
	MEM_DB_INIT_ITEM(SysNetModule),
	MEM_DB_INIT_ITEM(SysNetMemberSDHLineInfo),
	MEM_DB_INIT_ITEM(SysNetArea),
	MEM_DB_INIT_ITEM(SysNetNonPartyLinkInfo),
	MEM_DB_INIT_ITEM(SysNetPartyLinkAddrChange),
	MEM_DB_INIT_ITEM(SysNetEventExpr),
	MEM_DB_INIT_ITEM(SysNetDeviceCategory),
	MEM_DB_INIT_ITEM(SysNetSubArea),
	MEM_DB_INIT_ITEM(SysNetEventType),
	MEM_DB_INIT_ITEM(SysNetOID),
	MEM_DB_INIT_ITEM(SysNetMonitorTaskInfo),
	MEM_DB_INIT_ITEM(SysNetFuncArea),
};

void FUNC_NAME(SysNetManufactory)(SACommand & records, void * data)
{
	CWriteableSysNetManufactory mdbfield;

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.CName = records.Field("CName").asString();
	mdbfield.CName.trim();

	mdbfield.EName = records.Field("EName").asString();
	mdbfield.EName.trim();

	pMemoryDB->m_SysNetManufactoryFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetEventLevel)(SACommand & records, void * data)
{
	CWriteableSysNetEventLevel mdbfield;

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.CName = records.Field("CName").asString();
	mdbfield.CName.trim();

	mdbfield.DISCRIPTION = records.Field("DISCRIPTION").asString();
	mdbfield.DISCRIPTION.trim();

	mdbfield.EName = records.Field("EName").asString();
	mdbfield.EName.trim();

	pMemoryDB->m_SysNetEventLevelFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetGatherTask)(SACommand & records, void * data)
{
	CWriteableSysNetGatherTask mdbfield;

	mdbfield.TypeFlag = records.Field("TypeFlag").asLong();

	mdbfield.PolicyTypeID = records.Field("PolicyTypeID").asLong();

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.AttrType = records.Field("AttrType").asString();
	mdbfield.AttrType.trim();

	mdbfield.ObjectID = records.Field("ObjectID").asString();
	mdbfield.ObjectID.trim();

	mdbfield.DataType = records.Field("DataType").asLong();

	pMemoryDB->m_SysNetGatherTaskFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetEventExpr)(SACommand & records, void * data)
{
	CWriteableSysNetEventExpr mdbfield;

	mdbfield.WarningLEVEL = records.Field("WarningLEVEL").asString();
	mdbfield.WarningLEVEL.trim();

	mdbfield.EXPR = records.Field("EXPR").asString();
	mdbfield.EXPR.trim();

	mdbfield.SubEventTypeID = records.Field("SubEventTypeID").asLong();

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.DISCRIPTION = records.Field("DISCRIPTION").asString();
	mdbfield.DISCRIPTION.trim();

	mdbfield.CONTROL = records.Field("CONTROL").asString();
	mdbfield.CONTROL.trim();

	mdbfield.BRIEF = records.Field("BRIEF").asString();
	mdbfield.BRIEF.trim();

	mdbfield.MSGGROUP_ID = records.Field("MSGGROUP_ID").asLong();

	mdbfield.ADMINGROUP_ID = records.Field("ADMINGROUP_ID").asLong();

	mdbfield.ENAME = records.Field("ENAME").asString();
	mdbfield.ENAME.trim();

	mdbfield.EventTypeID = records.Field("EventTypeID").asLong();

	mdbfield.CNAME = records.Field("CNAME").asString();
	mdbfield.CNAME.trim();

	mdbfield.GIVEUPTIME = records.Field("GIVEUPTIME").asLong();

	pMemoryDB->m_SysNetEventExprFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetDelPartyLinkInfo)(SACommand & records, void * data)
{
	CWriteableSysNetDelPartyLinkInfo mdbfield;

	mdbfield.MOBILEPHONE = records.Field("MOBILEPHONE").asString();
	mdbfield.MOBILEPHONE.trim();

	mdbfield.IPADDR = records.Field("IPADDR").asString();
	mdbfield.IPADDR.trim();

	mdbfield.MEMBER_NO = records.Field("MEMBER_NO").asString();
	mdbfield.MEMBER_NO.trim();

	mdbfield.HASOTHER = records.Field("HASOTHER").asString();
	mdbfield.HASOTHER.trim();

	mdbfield.IF_ZIYING = records.Field("IF_ZIYING").asString();
	mdbfield.IF_ZIYING.trim();

	mdbfield.REMOTE_ADDR = records.Field("REMOTE_ADDR").asString();
	mdbfield.REMOTE_ADDR.trim();

	mdbfield.DDN_NO = records.Field("DDN_NO").asString();
	mdbfield.DDN_NO.trim();

	mdbfield.IP_LAN = records.Field("IP_LAN").asString();
	mdbfield.IP_LAN.trim();

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.SEAT_NO = records.Field("SEAT_NO").asString();
	mdbfield.SEAT_NO.trim();

	mdbfield.IN_MODE = records.Field("IN_MODE").asString();
	mdbfield.IN_MODE.trim();

	mdbfield.Interface = records.Field("Interface").asString();
	mdbfield.Interface.trim();

	mdbfield.TELEPHONE = records.Field("TELEPHONE").asString();
	mdbfield.TELEPHONE.trim();

	mdbfield.SERVICEPROVIDER = records.Field("SERVICEPROVIDER").asString();
	mdbfield.SERVICEPROVIDER.trim();

	mdbfield.FEE_TYPE = records.Field("FEE_TYPE").asString();
	mdbfield.FEE_TYPE.trim();

	mdbfield.SOFTWARE = records.Field("SOFTWARE").asString();
	mdbfield.SOFTWARE.trim();

	mdbfield.PROVINCE = records.Field("PROVINCE").asString();
	mdbfield.PROVINCE.trim();

	mdbfield.PRO = records.Field("PRO").asString();
	mdbfield.PRO.trim();

	mdbfield.ADDRESS = records.Field("ADDRESS").asString();
	mdbfield.ADDRESS.trim();

	mdbfield.FAX = records.Field("FAX").asString();
	mdbfield.FAX.trim();

	mdbfield.INTERFACE_DATE = records.Field("INTERFACE_DATE").asString();
	mdbfield.INTERFACE_DATE.trim();

	mdbfield.LOCAL_ADDR = records.Field("LOCAL_ADDR").asString();
	mdbfield.LOCAL_ADDR.trim();

	mdbfield.CONTACT = records.Field("CONTACT").asString();
	mdbfield.CONTACT.trim();

	mdbfield.MEMBER_NAME = records.Field("MEMBER_NAME").asString();
	mdbfield.MEMBER_NAME.trim();

	mdbfield.IF_TUOGUAN = records.Field("IF_TUOGUAN").asString();
	mdbfield.IF_TUOGUAN.trim();

	mdbfield.EMAIL = records.Field("EMAIL").asString();
	mdbfield.EMAIL.trim();

	mdbfield.IP_WAN = records.Field("IP_WAN").asString();
	mdbfield.IP_WAN.trim();

	mdbfield.LINE_STATUS = records.Field("LINE_STATUS").asString();
	mdbfield.LINE_STATUS.trim();

	pMemoryDB->m_SysNetDelPartyLinkInfoFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetDevice)(SACommand & records, void * data)
{
	CWriteableSysNetDevice mdbfield;

	mdbfield.APPLICATION_ID = records.Field("APPLICATION_ID").asLong();

	mdbfield.IPADDR = records.Field("IPADDR").asString();
	mdbfield.IPADDR.trim();

	mdbfield.RCOMMUNITY = records.Field("RCOMMUNITY").asString();
	mdbfield.RCOMMUNITY.trim();

	mdbfield.FuctionArea = records.Field("FuctionArea").asString();
	mdbfield.FuctionArea.trim();

	mdbfield.ObjectID = records.Field("ObjectID").asString();
	mdbfield.ObjectID.trim();

	mdbfield.IFNUM = records.Field("IFNUM").asLong();

	mdbfield.CFGSAVETYPE = records.Field("CFGSAVETYPE").asLong();

	mdbfield.MANUFACTORY_ID = records.Field("MANUFACTORY_ID").asLong();

	mdbfield.DESCRIPTION = records.Field("DESCRIPTION").asString();
	mdbfield.DESCRIPTION.trim();

	mdbfield.RAMSIZE = records.Field("RAMSIZE").asLong();

	mdbfield.SysNetSubAreaID = records.Field("SysNetSubAreaID").asLong();

	mdbfield.ISSNMP = records.Field("ISSNMP").asLong();

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.SLOTNUM = records.Field("SLOTNUM").asLong();

	mdbfield.SENDSMS = records.Field("SENDSMS").asLong();

	mdbfield.ROOM_ID = records.Field("ROOM_ID").asLong();

	mdbfield.ISPING = records.Field("ISPING").asLong();

	mdbfield.PASSWD = records.Field("PASSWD").asString();
	mdbfield.PASSWD.trim();

	mdbfield.ENPASSWD = records.Field("ENPASSWD").asString();
	mdbfield.ENPASSWD.trim();

	mdbfield.PORTNUMBER = records.Field("PORTNUMBER").asLong();

	mdbfield.MonitorType_ID = records.Field("MonitorType_ID").asLong();

	mdbfield.IOSVERSION_ID = records.Field("IOSVERSION_ID").asLong();

	mdbfield.CABINET_ID = records.Field("CABINET_ID").asLong();

	mdbfield.IPDECODE = records.Field("IPDECODE").asLong();

	mdbfield.CATEGORY_ID = records.Field("CATEGORY_ID").asLong();

	mdbfield.DEVICETYPE = records.Field("DEVICETYPE").asString();
	mdbfield.DEVICETYPE.trim();

	mdbfield.FLASHSIZE = records.Field("FLASHSIZE").asLong();

	mdbfield.CONFIGFILE = records.Field("CONFIGFILE").asString();
	mdbfield.CONFIGFILE.trim();

	mdbfield.NVRAMSIZE = records.Field("NVRAMSIZE").asLong();

	mdbfield.NAME = records.Field("NAME").asString();
	mdbfield.NAME.trim();

	mdbfield.SNMPVERSION = records.Field("SNMPVERSION").asLong();

	mdbfield.USERNAME = records.Field("USERNAME").asString();
	mdbfield.USERNAME.trim();

	pMemoryDB->m_SysNetDeviceFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetMonitorAttrScope)(SACommand & records, void * data)
{
	CWriteableSysNetMonitorAttrScope mdbfield;

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.CName = records.Field("CName").asString();
	mdbfield.CName.trim();

	mdbfield.Comments = records.Field("Comments").asString();
	mdbfield.Comments.trim();

	mdbfield.EName = records.Field("EName").asString();
	mdbfield.EName.trim();

	pMemoryDB->m_SysNetMonitorAttrScopeFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetSubEventType)(SACommand & records, void * data)
{
	CWriteableSysNetSubEventType mdbfield;

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.CName = records.Field("CName").asString();
	mdbfield.CName.trim();

	mdbfield.EName = records.Field("EName").asString();
	mdbfield.EName.trim();

	pMemoryDB->m_SysNetSubEventTypeFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetPartyLinkInfo)(SACommand & records, void * data)
{
	CWriteableSysNetPartyLinkInfo mdbfield;

	mdbfield.MOBILEPHONE = records.Field("MOBILEPHONE").asString();
	mdbfield.MOBILEPHONE.trim();

	mdbfield.IPADDR = records.Field("IPADDR").asString();
	mdbfield.IPADDR.trim();

	mdbfield.MEMBER_NO = records.Field("MEMBER_NO").asString();
	mdbfield.MEMBER_NO.trim();

	mdbfield.HASOTHER = records.Field("HASOTHER").asString();
	mdbfield.HASOTHER.trim();

	mdbfield.IF_ZIYING = records.Field("IF_ZIYING").asString();
	mdbfield.IF_ZIYING.trim();

	mdbfield.REMOTE_ADDR = records.Field("REMOTE_ADDR").asString();
	mdbfield.REMOTE_ADDR.trim();

	mdbfield.DDN_NO = records.Field("DDN_NO").asString();
	mdbfield.DDN_NO.trim();

	mdbfield.IP_LAN = records.Field("IP_LAN").asString();
	mdbfield.IP_LAN.trim();

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.SEAT_NO = records.Field("SEAT_NO").asString();
	mdbfield.SEAT_NO.trim();

	mdbfield.IN_MODE = records.Field("IN_MODE").asString();
	mdbfield.IN_MODE.trim();

	SAString str = records.Field("Interface").asString();
	str.TrimRight();
	str.TrimLeft();
	str.Replace(".", "_");
	mdbfield.Interface = (const char*)str;

	mdbfield.TELEPHONE = records.Field("TELEPHONE").asString();
	mdbfield.TELEPHONE.trim();

	mdbfield.SERVICEPROVIDER = records.Field("SERVICEPROVIDER").asString();
	mdbfield.SERVICEPROVIDER.trim();

	mdbfield.FEE_TYPE = records.Field("FEE_TYPE").asString();
	mdbfield.FEE_TYPE.trim();

	mdbfield.SOFTWARE = records.Field("SOFTWARE").asString();
	mdbfield.SOFTWARE.trim();

	mdbfield.PROVINCE = records.Field("PROVINCE").asString();
	mdbfield.PROVINCE.trim();

	mdbfield.PRO = records.Field("PRO").asString();
	mdbfield.PRO.trim();

	mdbfield.ADDRESS = records.Field("ADDRESS").asString();
	mdbfield.ADDRESS.trim();

	mdbfield.FAX = records.Field("FAX").asString();
	mdbfield.FAX.trim();

	mdbfield.INTERFACE_DATE = records.Field("INTERFACE_DATE").asString();
	mdbfield.INTERFACE_DATE.trim();

	mdbfield.LOCAL_ADDR = records.Field("LOCAL_ADDR").asString();
	mdbfield.LOCAL_ADDR.trim();

	mdbfield.CONTACT = records.Field("CONTACT").asString();
	mdbfield.CONTACT.trim();

	mdbfield.MEMBER_NAME = records.Field("MEMBER_NAME").asString();
	mdbfield.MEMBER_NAME.trim();

	mdbfield.IF_TUOGUAN = records.Field("IF_TUOGUAN").asString();
	mdbfield.IF_TUOGUAN.trim();

	mdbfield.EMAIL = records.Field("EMAIL").asString();
	mdbfield.EMAIL.trim();

	mdbfield.IP_WAN = records.Field("IP_WAN").asString();
	mdbfield.IP_WAN.trim();

	mdbfield.LINE_STATUS = records.Field("LINE_STATUS").asString();
	mdbfield.LINE_STATUS.trim();

	pMemoryDB->m_SysNetPartyLinkInfoFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetPartyLinkAddrChange)(SACommand & records, void * data)
{
	CWriteableSysNetPartyLinkAddrChange mdbfield;

	mdbfield.NEWADDRESS = records.Field("NEWADDRESS").asString();
	mdbfield.NEWADDRESS.trim();

	mdbfield.OLDADDRESS = records.Field("OLDADDRESS").asString();
	mdbfield.OLDADDRESS.trim();

	mdbfield.MonTime = records.Field("MonTime").asString();
	mdbfield.MonTime.trim();

	mdbfield.RelationID = records.Field("RelationID").asLong();

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.OPERATOR = records.Field("OPERATOR").asString();
	mdbfield.OPERATOR.trim();

	mdbfield.MonDate = records.Field("MonDate").asString();
	mdbfield.MonDate.trim();

	pMemoryDB->m_SysNetPartyLinkAddrChangeFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetFuncArea)(SACommand & records, void * data)
{
	CWriteableSysNetFuncArea mdbfield;

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.CName = records.Field("CName").asString();
	mdbfield.CName.trim();

	mdbfield.SysNetSubAreaID = records.Field("SysNetSubAreaID").asLong();

	mdbfield.EName = records.Field("EName").asString();
	mdbfield.EName.trim();

	pMemoryDB->m_SysNetFuncAreaFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetArea)(SACommand & records, void * data)
{
	CWriteableSysNetArea mdbfield;

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.CName = records.Field("CName").asString();
	mdbfield.CName.trim();

	mdbfield.EName = records.Field("EName").asString();
	mdbfield.EName.trim();

	pMemoryDB->m_SysNetAreaFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetInterface)(SACommand & records, void * data)
{
	CWriteableSysNetInterface mdbfield;

	mdbfield.IfStatus = records.Field("IfStatus").asLong();

	mdbfield.IpMask = records.Field("IpMask").asString();
	mdbfield.IpMask.trim();

	mdbfield.EName = records.Field("EName").asString();
	mdbfield.EName.trim();

	mdbfield.MonitorType_ID = records.Field("MonitorType_ID").asLong();

	mdbfield.isPolling = records.Field("isPolling").asLong();

	mdbfield.MAC = records.Field("MAC").asString();
	mdbfield.MAC.trim();

	mdbfield.DeviceID = records.Field("DeviceID").asLong();

	mdbfield.Description = records.Field("Description").asString();
	mdbfield.Description.trim();

	mdbfield.IfType = records.Field("IfType").asLong();

	mdbfield.ObjectID = records.Field("ObjectID").asString();
	mdbfield.ObjectID.trim();

	mdbfield.IpAddress = records.Field("IpAddress").asString();
	mdbfield.IpAddress.trim();

	mdbfield.DeviceObjectID = records.Field("DeviceObjectID").asString();
	mdbfield.DeviceObjectID.trim();

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.DeviceIndex = records.Field("DeviceIndex").asString();
	mdbfield.DeviceIndex.trim();

	pMemoryDB->m_SysNetInterfaceFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetOID)(SACommand & records, void * data)
{
	CWriteableSysNetOID mdbfield;

	mdbfield.isTheTable = records.Field("isTheTable").asLong();

	mdbfield.OID = records.Field("OID").asString();
	mdbfield.OID.trim();

	mdbfield.Unit = records.Field("Unit").asString();
	mdbfield.Unit.trim();

	mdbfield.EName = records.Field("EName").asString();
	mdbfield.EName.trim();

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.CName = records.Field("CName").asString();
	mdbfield.CName.trim();

	mdbfield.Manufactory = records.Field("Manufactory").asString();
	mdbfield.Manufactory.trim();

	mdbfield.DeviceType = records.Field("DeviceType").asString();
	mdbfield.DeviceType.trim();

	pMemoryDB->m_SysNetOIDFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysMemberLinkCost)(SACommand & records, void * data)
{
	CWriteableSysMemberLinkCost mdbfield;

	mdbfield.Pay_Date = records.Field("Pay_Date").asString();
	mdbfield.Pay_Date.trim();

	mdbfield.Charge = records.Field("Charge").asLong();

	mdbfield.Pro = records.Field("Pro").asString();
	mdbfield.Pro.trim();

	mdbfield.ParticipantName = records.Field("ParticipantName").asString();
	mdbfield.ParticipantName.trim();

	mdbfield.D_Pay_Date = records.Field("D_Pay_Date").asString();
	mdbfield.D_Pay_Date.trim();

	mdbfield.DDN_NO = records.Field("DDN_NO").asString();
	mdbfield.DDN_NO.trim();

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.Fee_Type = records.Field("Fee_Type").asString();
	mdbfield.Fee_Type.trim();

	mdbfield.ServiceProvider = records.Field("ServiceProvider").asString();
	mdbfield.ServiceProvider.trim();

	mdbfield.B_Pay_Date = records.Field("B_Pay_Date").asString();
	mdbfield.B_Pay_Date.trim();

	pMemoryDB->m_SysMemberLinkCostFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetDeviceLinked)(SACommand & records, void * data)
{
	CWriteableSysNetDeviceLinked mdbfield;

	mdbfield.LinkNetDeviceID = records.Field("LinkNetDeviceID").asLong();

	mdbfield.LinkNetPortType = records.Field("LinkNetPortType").asString();
	mdbfield.LinkNetPortType.trim();

	mdbfield.NetPortID = records.Field("NetPortID").asLong();

	mdbfield.LinkNetPortID = records.Field("LinkNetPortID").asLong();

	mdbfield.LinkNetObjectID = records.Field("LinkNetObjectID").asString();
	mdbfield.LinkNetObjectID.trim();

	mdbfield.NetObjectID = records.Field("NetObjectID").asString();
	mdbfield.NetObjectID.trim();

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.LinkSource = records.Field("LinkSource").asLong();

	mdbfield.NetDeviceID = records.Field("NetDeviceID").asLong();

	mdbfield.NetPortType = records.Field("NetPortType").asString();
	mdbfield.NetPortType.trim();

	pMemoryDB->m_SysNetDeviceLinkedFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetMonitorCommandType)(SACommand & records, void * data)
{
	CWriteableSysNetMonitorCommandType mdbfield;

	mdbfield.Manufactory_ID = records.Field("Manufactory_ID").asLong();

	mdbfield.ActionGroup = records.Field("ActionGroup").asString();
	mdbfield.ActionGroup.trim();

	mdbfield.MonitorType_ID = records.Field("MonitorType_ID").asLong();

	mdbfield.DeviceModle_ID = records.Field("DeviceModle_ID").asLong();

	mdbfield.Command = records.Field("Command").asString();
	mdbfield.Command.trim();

	mdbfield.ActionGroup_ID = records.Field("ActionGroup_ID").asLong();

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.DeviceModle = records.Field("DeviceModle").asString();
	mdbfield.DeviceModle.trim();

	mdbfield.Manufactory = records.Field("Manufactory").asString();
	mdbfield.Manufactory.trim();

	mdbfield.MonitorType = records.Field("MonitorType").asString();
	mdbfield.MonitorType.trim();

	pMemoryDB->m_SysNetMonitorCommandTypeFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetMonitorDeviceTask)(SACommand & records, void * data)
{
	CWriteableSysNetMonitorDeviceTask mdbfield;

	mdbfield.SecondID = records.Field("SecondID").asLong();

	mdbfield.Manufactory_ID = records.Field("Manufactory_ID").asLong();

	mdbfield.InstructChain = records.Field("InstructChain").asString();
	mdbfield.InstructChain.trim();

	mdbfield.IPAddress = records.Field("IPAddress").asString();
	mdbfield.IPAddress.trim();

	mdbfield.DefParamChain = records.Field("DefParamChain").asString();
	mdbfield.DefParamChain.trim();

	mdbfield.InstructAlias = records.Field("InstructAlias").asString();
	mdbfield.InstructAlias.trim();

	mdbfield.InstructArgs = records.Field("InstructArgs").asString();
	mdbfield.InstructArgs.trim();

	mdbfield.Flag = records.Field("Flag").asLong();

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.ObjectID = records.Field("ObjectID").asString();
	mdbfield.ObjectID.trim();

	pMemoryDB->m_SysNetMonitorDeviceTaskFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetMonitorActionAttr)(SACommand & records, void * data)
{
	CWriteableSysNetMonitorActionAttr mdbfield;

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.MonitorAttrName = records.Field("MonitorAttrName").asString();
	mdbfield.MonitorAttrName.trim();

	mdbfield.MonitorAttr_ID = records.Field("MonitorAttr_ID").asLong();

	mdbfield.ActionGroup_ID = records.Field("ActionGroup_ID").asLong();

	pMemoryDB->m_SysNetMonitorActionAttrFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetMonitorActionGroup)(SACommand & records, void * data)
{
	CWriteableSysNetMonitorActionGroup mdbfield;

	mdbfield.EName = records.Field("EName").asString();
	mdbfield.EName.trim();

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.ActionType = records.Field("ActionType").asLong();

	mdbfield.CName = records.Field("CName").asString();
	mdbfield.CName.trim();

	mdbfield.Comments = records.Field("Comments").asString();
	mdbfield.Comments.trim();

	pMemoryDB->m_SysNetMonitorActionGroupFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetTimePolicy)(SACommand & records, void * data)
{
	CWriteableSysNetTimePolicy mdbfield;

	mdbfield.Operation = records.Field("Operation").asLong();

	mdbfield.PolicyString = records.Field("PolicyString").asString();
	mdbfield.PolicyString.trim();

	mdbfield.Description = records.Field("Description").asString();
	mdbfield.Description.trim();

	mdbfield.EName = records.Field("EName").asString();
	mdbfield.EName.trim();

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.PolicyType = records.Field("PolicyType").asLong();

	mdbfield.TradingDay = records.Field("TradingDay").asLong();

	mdbfield.CName = records.Field("CName").asString();
	mdbfield.CName.trim();

	pMemoryDB->m_SysNetTimePolicyFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetOuterDeviceInfo)(SACommand & records, void * data)
{
	CWriteableSysNetOuterDeviceInfo mdbfield;

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.IPADDR = records.Field("IPADDR").asString();
	mdbfield.IPADDR.trim();

	mdbfield.NAME = records.Field("NAME").asString();
	mdbfield.NAME.trim();

	mdbfield.memo = records.Field("memo").asString();
	mdbfield.memo.trim();

	pMemoryDB->m_SysNetOuterDeviceInfoFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetDDNLinkInfo)(SACommand & records, void * data)
{
	CWriteableSysNetDDNLinkInfo mdbfield;

	mdbfield.BusinessUnit = records.Field("BusinessUnit").asString();
	mdbfield.BusinessUnit.trim();

	mdbfield.EndZContactName = records.Field("EndZContactName").asString();
	mdbfield.EndZContactName.trim();

	mdbfield.Bandwidth = records.Field("Bandwidth").asString();
	mdbfield.Bandwidth.trim();

	mdbfield.EndAAddress = records.Field("EndAAddress").asString();
	mdbfield.EndAAddress.trim();

	mdbfield.ClientName = records.Field("ClientName").asString();
	mdbfield.ClientName.trim();

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.DDN_NO = records.Field("DDN_NO").asString();
	mdbfield.DDN_NO.trim();

	mdbfield.EndAContactName = records.Field("EndAContactName").asString();
	mdbfield.EndAContactName.trim();

	mdbfield.EndZAddress = records.Field("EndZAddress").asString();
	mdbfield.EndZAddress.trim();

	pMemoryDB->m_SysNetDDNLinkInfoFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetGeneralOID)(SACommand & records, void * data)
{
	CWriteableSysNetGeneralOID mdbfield;

	mdbfield.OID = records.Field("OID").asString();
	mdbfield.OID.trim();

	mdbfield.EName = records.Field("EName").asString();
	mdbfield.EName.trim();

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.CName = records.Field("CName").asString();
	mdbfield.CName.trim();

	mdbfield.isTheTable = records.Field("isTheTable").asLong();

	mdbfield.Unit = records.Field("Unit").asString();
	mdbfield.Unit.trim();

	pMemoryDB->m_SysNetGeneralOIDFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetMemberSDHLineInfo)(SACommand & records, void * data)
{
	CWriteableSysNetMemberSDHLineInfo mdbfield;

	mdbfield.LocalCircuit = records.Field("LocalCircuit").asString();
	mdbfield.LocalCircuit.trim();

	mdbfield.IPADDR = records.Field("IPADDR").asString();
	mdbfield.IPADDR.trim();

	mdbfield.RemoteCircuit = records.Field("RemoteCircuit").asString();
	mdbfield.RemoteCircuit.trim();

	mdbfield.ParticipantName = records.Field("ParticipantName").asString();
	mdbfield.ParticipantName.trim();

	mdbfield.EndAContact = records.Field("EndAContact").asString();
	mdbfield.EndAContact.trim();

	mdbfield.ApplyPerson = records.Field("ApplyPerson").asString();
	mdbfield.ApplyPerson.trim();

	mdbfield.Bandwidth = records.Field("Bandwidth").asString();
	mdbfield.Bandwidth.trim();

	mdbfield.ContactName = records.Field("ContactName").asString();
	mdbfield.ContactName.trim();

	mdbfield.InterfaceType = records.Field("InterfaceType").asString();
	mdbfield.InterfaceType.trim();

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.MemContractNo = records.Field("MemContractNo").asString();
	mdbfield.MemContractNo.trim();

	mdbfield.TELEPHONE = records.Field("TELEPHONE").asString();
	mdbfield.TELEPHONE.trim();

	mdbfield.StartPortID = records.Field("StartPortID").asString();
	mdbfield.StartPortID.trim();

	mdbfield.EndALineAddress = records.Field("EndALineAddress").asString();
	mdbfield.EndALineAddress.trim();

	mdbfield.PROVINCE = records.Field("PROVINCE").asString();
	mdbfield.PROVINCE.trim();

	mdbfield.ClientManager = records.Field("ClientManager").asString();
	mdbfield.ClientManager.trim();

	mdbfield.Remark = records.Field("Remark").asString();
	mdbfield.Remark.trim();

	mdbfield.SeqNo = records.Field("SeqNo").asLong();

	mdbfield.DataCenterID = records.Field("DataCenterID").asLong();

	mdbfield.StartJump = records.Field("StartJump").asString();
	mdbfield.StartJump.trim();

	mdbfield.Interface = records.Field("Interface").asString();
	mdbfield.Interface.trim();

	mdbfield.MemberNo = records.Field("MemberNo").asString();
	mdbfield.MemberNo.trim();

	mdbfield.MOBILEPHONE = records.Field("MOBILEPHONE").asString();
	mdbfield.MOBILEPHONE.trim();

	mdbfield.MonthlyRental = records.Field("MonthlyRental").asLong();

	mdbfield.EndZLineAddress = records.Field("EndZLineAddress").asString();
	mdbfield.EndZLineAddress.trim();

	mdbfield.LINE_STATUS = records.Field("LINE_STATUS").asString();
	mdbfield.LINE_STATUS.trim();

	pMemoryDB->m_SysNetMemberSDHLineInfoFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetBaseLineTask)(SACommand & records, void * data)
{
	CWriteableSysNetBaseLineTask mdbfield;

	mdbfield.BaseLineIDList = records.Field("BaseLineIDList").asString();
	mdbfield.BaseLineIDList.trim();

	mdbfield.memo = records.Field("memo").asString();
	mdbfield.memo.trim();

	mdbfield.Name = records.Field("Name").asString();
	mdbfield.Name.trim();

	mdbfield.DeviceIDList = records.Field("DeviceIDList").asString();
	mdbfield.DeviceIDList.trim();

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.GenDate = records.Field("GenDate").asString();
	mdbfield.GenDate.trim();

	mdbfield.GenUser = records.Field("GenUser").asString();
	mdbfield.GenUser.trim();

	mdbfield.GenTime = records.Field("GenTime").asString();
	mdbfield.GenTime.trim();

	pMemoryDB->m_SysNetBaseLineTaskFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetBaseLine)(SACommand & records, void * data)
{
	CWriteableSysNetBaseLine mdbfield;

	mdbfield.SerialUsed = records.Field("SerialUsed").asString();
	mdbfield.SerialUsed.trim();

	mdbfield.Name = records.Field("Name").asString();
	mdbfield.Name.trim();

	mdbfield.Flag = records.Field("Flag").asLong();

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.MANUFACTORY_ID = records.Field("MANUFACTORY_ID").asLong();

	mdbfield.data = records.Field("data").asString();
	mdbfield.data.trim();

	mdbfield.memo = records.Field("memo").asString();
	mdbfield.memo.trim();

	pMemoryDB->m_SysNetBaseLineFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetMonitorAttrType)(SACommand & records, void * data)
{
	CWriteableSysNetMonitorAttrType mdbfield;

	mdbfield.MANUFACTORY = records.Field("MANUFACTORY").asString();
	mdbfield.MANUFACTORY.trim();

	mdbfield.AttrType_ID = records.Field("AttrType_ID").asLong();

	mdbfield.MonitorType = records.Field("MonitorType").asString();
	mdbfield.MonitorType.trim();

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.AttrType = records.Field("AttrType").asString();
	mdbfield.AttrType.trim();

	mdbfield.MANUFACTORY_ID = records.Field("MANUFACTORY_ID").asLong();

	mdbfield.MonitorType_ID = records.Field("MonitorType_ID").asLong();

	pMemoryDB->m_SysNetMonitorAttrTypeFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetEventType)(SACommand & records, void * data)
{
	CWriteableSysNetEventType mdbfield;

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.CName = records.Field("CName").asString();
	mdbfield.CName.trim();

	mdbfield.EName = records.Field("EName").asString();
	mdbfield.EName.trim();

	pMemoryDB->m_SysNetEventTypeFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetModule)(SACommand & records, void * data)
{
	CWriteableSysNetModule mdbfield;

	mdbfield.Description = records.Field("Description").asString();
	mdbfield.Description.trim();

	mdbfield.DeviceObjectID = records.Field("DeviceObjectID").asString();
	mdbfield.DeviceObjectID.trim();

	mdbfield.MonitorType_ID = records.Field("MonitorType_ID").asLong();

	mdbfield.DeviceID = records.Field("DeviceID").asLong();

	mdbfield.EntPhyIndex = records.Field("EntPhyIndex").asLong();

	mdbfield.Name = records.Field("Name").asString();
	mdbfield.Name.trim();

	mdbfield.ModuleIndex = records.Field("ModuleIndex").asLong();

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.ObjectID = records.Field("ObjectID").asString();
	mdbfield.ObjectID.trim();

	pMemoryDB->m_SysNetModuleFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetMonitorTaskInfo)(SACommand & records, void * data)
{
	CWriteableSysNetMonitorTaskInfo mdbfield;

	mdbfield.DeviceGroup = records.Field("DeviceGroup").asString();
	mdbfield.DeviceGroup.trim();

	mdbfield.EName = records.Field("EName").asString();
	mdbfield.EName.trim();

	mdbfield.ManagerGroup_ID = records.Field("ManagerGroup_ID").asLong();

	mdbfield.Comments = records.Field("Comments").asString();
	mdbfield.Comments.trim();

	mdbfield.ActionGroup_ID = records.Field("ActionGroup_ID").asLong();

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.TaskPriority = records.Field("TaskPriority").asString();
	mdbfield.TaskPriority.trim();

	mdbfield.EventExprStr = records.Field("EventExprStr").asString();
	mdbfield.EventExprStr.trim();

	mdbfield.ManagerGroup = records.Field("ManagerGroup").asString();
	mdbfield.ManagerGroup.trim();

	mdbfield.TaskPriority_ID = records.Field("TaskPriority_ID").asLong();

	mdbfield.ActionGroup = records.Field("ActionGroup").asString();
	mdbfield.ActionGroup.trim();

	mdbfield.TaskStatus = records.Field("TaskStatus").asLong();

	mdbfield.ValidFlag = records.Field("ValidFlag").asLong();

	mdbfield.DeviceGroup_ID = records.Field("DeviceGroup_ID").asLong();

	mdbfield.TimePolicy = records.Field("TimePolicy").asString();
	mdbfield.TimePolicy.trim();

	mdbfield.TimePolicy_ID = records.Field("TimePolicy_ID").asLong();

	mdbfield.CName = records.Field("CName").asString();
	mdbfield.CName.trim();

	mdbfield.OutputPolicy_ID = records.Field("OutputPolicy_ID").asLong();

	mdbfield.OutputPolicy = records.Field("OutputPolicy").asString();
	mdbfield.OutputPolicy.trim();

	pMemoryDB->m_SysNetMonitorTaskInfoFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetMonitorDeviceGroup)(SACommand & records, void * data)
{
	CWriteableSysNetMonitorDeviceGroup mdbfield;

	mdbfield.EName = records.Field("EName").asString();
	mdbfield.EName.trim();

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.CName = records.Field("CName").asString();
	mdbfield.CName.trim();

	mdbfield.Condition = records.Field("Condition").asString();
	mdbfield.Condition.trim();

	mdbfield.Comments = records.Field("Comments").asString();
	mdbfield.Comments.trim();

	pMemoryDB->m_SysNetMonitorDeviceGroupFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetMonitorTaskInstAttrs)(SACommand & records, void * data)
{
	CWriteableSysNetMonitorTaskInstAttrs mdbfield;

	mdbfield.DefParamChain = records.Field("DefParamChain").asString();
	mdbfield.DefParamChain.trim();

	mdbfield.DEVICETYPE = records.Field("DEVICETYPE").asString();
	mdbfield.DEVICETYPE.trim();

	mdbfield.Manufactory_ID = records.Field("Manufactory_ID").asLong();

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.DefRegularChain = records.Field("DefRegularChain").asString();
	mdbfield.DefRegularChain.trim();

	mdbfield.InstructAlias = records.Field("InstructAlias").asString();
	mdbfield.InstructAlias.trim();

	mdbfield.AttrsChain = records.Field("AttrsChain").asString();
	mdbfield.AttrsChain.trim();

	pMemoryDB->m_SysNetMonitorTaskInstAttrsFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetMonitorType)(SACommand & records, void * data)
{
	CWriteableSysNetMonitorType mdbfield;

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.CName = records.Field("CName").asString();
	mdbfield.CName.trim();

	mdbfield.EName = records.Field("EName").asString();
	mdbfield.EName.trim();

	pMemoryDB->m_SysNetMonitorTypeFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetPseudMemberLinkInfo)(SACommand & records, void * data)
{
	CWriteableSysNetPseudMemberLinkInfo mdbfield;

	mdbfield.LocalCircuit = records.Field("LocalCircuit").asString();
	mdbfield.LocalCircuit.trim();

	mdbfield.IPADDR = records.Field("IPADDR").asString();
	mdbfield.IPADDR.trim();

	mdbfield.EndZContactName = records.Field("EndZContactName").asString();
	mdbfield.EndZContactName.trim();

	mdbfield.ApplyPerson = records.Field("ApplyPerson").asString();
	mdbfield.ApplyPerson.trim();

	mdbfield.LineUsage = records.Field("LineUsage").asString();
	mdbfield.LineUsage.trim();

	mdbfield.EndAAddress = records.Field("EndAAddress").asString();
	mdbfield.EndAAddress.trim();

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.MemContractNo = records.Field("MemContractNo").asString();
	mdbfield.MemContractNo.trim();

	mdbfield.BusinessUnit = records.Field("BusinessUnit").asString();
	mdbfield.BusinessUnit.trim();

	mdbfield.SeqNo = records.Field("SeqNo").asLong();

	mdbfield.EndAContactName = records.Field("EndAContactName").asString();
	mdbfield.EndAContactName.trim();

	mdbfield.RemoteCircuit = records.Field("RemoteCircuit").asString();
	mdbfield.RemoteCircuit.trim();

	mdbfield.LineInfo = records.Field("LineInfo").asString();
	mdbfield.LineInfo.trim();

	mdbfield.Telephone = records.Field("Telephone").asString();
	mdbfield.Telephone.trim();

	mdbfield.MonthlyRental = records.Field("MonthlyRental").asLong();

	mdbfield.Bandwidth = records.Field("Bandwidth").asString();
	mdbfield.Bandwidth.trim();

	mdbfield.EndZAddress = records.Field("EndZAddress").asString();
	mdbfield.EndZAddress.trim();

	pMemoryDB->m_SysNetPseudMemberLinkInfoFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetPartylinkMonthlyRent)(SACommand & records, void * data)
{
	CWriteableSysNetPartylinkMonthlyRent mdbfield;

	mdbfield.DDN_NO = records.Field("DDN_NO").asString();
	mdbfield.DDN_NO.trim();

	mdbfield.Remark = records.Field("Remark").asString();
	mdbfield.Remark.trim();

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.MonthlyRental = records.Field("MonthlyRental").asLong();

	mdbfield.LineName = records.Field("LineName").asString();
	mdbfield.LineName.trim();

	mdbfield.ServiceProvider = records.Field("ServiceProvider").asString();
	mdbfield.ServiceProvider.trim();

	pMemoryDB->m_SysNetPartylinkMonthlyRentFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetCommunity)(SACommand & records, void * data)
{
	CWriteableSysNetCommunity mdbfield;

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.IPADDR = records.Field("IPADDR").asString();
	mdbfield.IPADDR.trim();

	mdbfield.COMMUNITY = records.Field("COMMUNITY").asString();
	mdbfield.COMMUNITY.trim();

	pMemoryDB->m_SysNetCommunityFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetDeviceCategory)(SACommand & records, void * data)
{
	CWriteableSysNetDeviceCategory mdbfield;

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.CName = records.Field("CName").asString();
	mdbfield.CName.trim();

	mdbfield.EName = records.Field("EName").asString();
	mdbfield.EName.trim();

	pMemoryDB->m_SysNetDeviceCategoryFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetDeviceType)(SACommand & records, void * data)
{
	CWriteableSysNetDeviceType mdbfield;

	mdbfield.Manufactory = records.Field("Manufactory").asString();
	mdbfield.Manufactory.trim();

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.DeviceType = records.Field("DeviceType").asString();
	mdbfield.DeviceType.trim();

	pMemoryDB->m_SysNetDeviceTypeFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetNonPartyLinkInfo)(SACommand & records, void * data)
{
	CWriteableSysNetNonPartyLinkInfo mdbfield;

	mdbfield.MOBILEPHONE = records.Field("MOBILEPHONE").asString();
	mdbfield.MOBILEPHONE.trim();

	mdbfield.IPADDR = records.Field("IPADDR").asString();
	mdbfield.IPADDR.trim();

	mdbfield.MEMBER_NO = records.Field("MEMBER_NO").asString();
	mdbfield.MEMBER_NO.trim();

	mdbfield.HASOTHER = records.Field("HASOTHER").asString();
	mdbfield.HASOTHER.trim();

	mdbfield.IF_ZIYING = records.Field("IF_ZIYING").asString();
	mdbfield.IF_ZIYING.trim();

	mdbfield.REMOTE_ADDR = records.Field("REMOTE_ADDR").asString();
	mdbfield.REMOTE_ADDR.trim();

	mdbfield.DDN_NO = records.Field("DDN_NO").asString();
	mdbfield.DDN_NO.trim();

	mdbfield.IP_LAN = records.Field("IP_LAN").asString();
	mdbfield.IP_LAN.trim();

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.SEAT_NO = records.Field("SEAT_NO").asString();
	mdbfield.SEAT_NO.trim();

	mdbfield.IN_MODE = records.Field("IN_MODE").asString();
	mdbfield.IN_MODE.trim();

	mdbfield.Interface = records.Field("Interface").asString();
	mdbfield.Interface.trim();

	mdbfield.TELEPHONE = records.Field("TELEPHONE").asString();
	mdbfield.TELEPHONE.trim();

	mdbfield.SERVICEPROVIDER = records.Field("SERVICEPROVIDER").asString();
	mdbfield.SERVICEPROVIDER.trim();

	mdbfield.FEE_TYPE = records.Field("FEE_TYPE").asString();
	mdbfield.FEE_TYPE.trim();

	mdbfield.SOFTWARE = records.Field("SOFTWARE").asString();
	mdbfield.SOFTWARE.trim();

	mdbfield.PROVINCE = records.Field("PROVINCE").asString();
	mdbfield.PROVINCE.trim();

	mdbfield.PRO = records.Field("PRO").asString();
	mdbfield.PRO.trim();

	mdbfield.ADDRESS = records.Field("ADDRESS").asString();
	mdbfield.ADDRESS.trim();

	mdbfield.FAX = records.Field("FAX").asString();
	mdbfield.FAX.trim();

	mdbfield.INTERFACE_DATE = records.Field("INTERFACE_DATE").asString();
	mdbfield.INTERFACE_DATE.trim();

	mdbfield.LOCAL_ADDR = records.Field("LOCAL_ADDR").asString();
	mdbfield.LOCAL_ADDR.trim();

	mdbfield.CONTACT = records.Field("CONTACT").asString();
	mdbfield.CONTACT.trim();

	mdbfield.MEMBER_NAME = records.Field("MEMBER_NAME").asString();
	mdbfield.MEMBER_NAME.trim();

	mdbfield.IF_TUOGUAN = records.Field("IF_TUOGUAN").asString();
	mdbfield.IF_TUOGUAN.trim();

	mdbfield.EMAIL = records.Field("EMAIL").asString();
	mdbfield.EMAIL.trim();

	mdbfield.IP_WAN = records.Field("IP_WAN").asString();
	mdbfield.IP_WAN.trim();

	mdbfield.LINE_STATUS = records.Field("LINE_STATUS").asString();
	mdbfield.LINE_STATUS.trim();

	pMemoryDB->m_SysNetNonPartyLinkInfoFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetSubAreaIP)(SACommand & records, void * data)
{
	CWriteableSysNetSubAreaIP mdbfield;

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.Mask = records.Field("Mask").asString();
	mdbfield.Mask.trim();

	mdbfield.SysNetSubAreaID = records.Field("SysNetSubAreaID").asLong();

	mdbfield.IP = records.Field("IP").asString();
	mdbfield.IP.trim();

	pMemoryDB->m_SysNetSubAreaIPFactory->add(&mdbfield, NULL);
}

void FUNC_NAME(SysNetSubArea)(SACommand & records, void * data)
{
	CWriteableSysNetSubArea mdbfield;

	mdbfield.ID = records.Field("ID").asLong();

	mdbfield.CName = records.Field("CName").asString();
	mdbfield.CName.trim();

	mdbfield.EName = records.Field("EName").asString();
	mdbfield.EName.trim();

	mdbfield.SysNetAreaID = records.Field("SysNetAreaID").asLong();

	pMemoryDB->m_SysNetSubAreaFactory->add(&mdbfield, NULL);
}

#endif // __MEMORY_DB_INIT_FUNC_INTERNAL_H
