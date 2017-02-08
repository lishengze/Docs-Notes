/////////////////////////////////////////////////////////////////////////
///@system 网络监控系统
///@company 上海期货信息技术有限公司
///@file GeneralOperationTables_internal.h
///@brief 定义了生产通用操作的代码，由脚本生产而成，勿直接修改本文件
///@history
///20110701	李志伟		创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef __GENERAL_OPERATION_TABLES_INTERNAL_H
#define __GENERAL_OPERATION_TABLES_INTERNAL_H


#include "FTDDataHelper.h"


// define ftd obj copier
DEFINE_FTD_OBJ_COPIER(NetSubAreaIP)
DEFINE_FTD_OBJ_COPIER(NetInterface)
DEFINE_FTD_OBJ_COPIER(MemberLinkCost)
DEFINE_FTD_OBJ_COPIER(NetEventLevel)
DEFINE_FTD_OBJ_COPIER(NetGatherTask)
DEFINE_FTD_OBJ_COPIER(NetMonitorAttrType)
DEFINE_FTD_OBJ_COPIER(NetDelPartyLinkInfo)
DEFINE_FTD_OBJ_COPIER(NetMonitorCommandType)
DEFINE_FTD_OBJ_COPIER(NetMonitorDeviceTask)
DEFINE_FTD_OBJ_COPIER(NetMonitorActionAttr)
DEFINE_FTD_OBJ_COPIER(NetMonitorType)
DEFINE_FTD_OBJ_COPIER(NetMonitorActionGroup)
DEFINE_FTD_OBJ_COPIER(NetTimePolicy)
DEFINE_FTD_OBJ_COPIER(NetDevice)
DEFINE_FTD_OBJ_COPIER(NetMonitorAttrScope)
DEFINE_FTD_OBJ_COPIER(NetCommunity)
DEFINE_FTD_OBJ_COPIER(NetSubEventType)
DEFINE_FTD_OBJ_COPIER(NetPartyLinkInfo)
DEFINE_FTD_OBJ_COPIER(NetBaseLineTask)
DEFINE_FTD_OBJ_COPIER(NetMonitorTaskInstAttrs)
DEFINE_FTD_OBJ_COPIER(NetEventExpr)
DEFINE_FTD_OBJ_COPIER(NetDeviceType)
DEFINE_FTD_OBJ_COPIER(NetDDNLinkInfo)
DEFINE_FTD_OBJ_COPIER(NetDeviceLinked)
DEFINE_FTD_OBJ_COPIER(NetDeviceCategory)
DEFINE_FTD_OBJ_COPIER(NetPartylinkMonthlyRent)
DEFINE_FTD_OBJ_COPIER(NetPseudMemberLinkInfo)
DEFINE_FTD_OBJ_COPIER(NetModule)
DEFINE_FTD_OBJ_COPIER(NetManufactory)
DEFINE_FTD_OBJ_COPIER(NetMemberSDHLineInfo)
DEFINE_FTD_OBJ_COPIER(NetNonPartyLinkInfo)
DEFINE_FTD_OBJ_COPIER(NetPartyLinkAddrChange)
DEFINE_FTD_OBJ_COPIER(NetEventType)
DEFINE_FTD_OBJ_COPIER(NetOID)
DEFINE_FTD_OBJ_COPIER(NetSubArea)
DEFINE_FTD_OBJ_COPIER(NetFuncArea)
DEFINE_FTD_OBJ_COPIER(NetMonitorDeviceGroup)
DEFINE_FTD_OBJ_COPIER(NetMonitorTaskInfo)
DEFINE_FTD_OBJ_COPIER(NetArea)
typedef void (* FTD_OBJ_COPIER_W2F_T(NetOuterDeviceInfo))(FTD_FIELD(NetOuterDeviceInfo)*pTarget,  FTD_WRITABLE(NetOuterDeviceInfo) * pSource); \
static void FTD_OBJ_COPIER_W2F(NetOuterDeviceInfo)(FTD_FIELD(NetOuterDeviceInfo)*pTarget,  FTD_WRITABLE(NetOuterDeviceInfo) * pSource) 
{ COPY_FTD_ENTITY(NetOuterDeviceInfo, pTarget, pSource); }

typedef void (* FTD_OBJ_COPIER_F2W_T(NetOuterDeviceInfo))(FTD_WRITABLE(NetOuterDeviceInfo)*pTarget,  FTD_FIELD(NetOuterDeviceInfo) * pSource); \
static void FTD_OBJ_COPIER_F2W(NetOuterDeviceInfo)(FTD_WRITABLE(NetOuterDeviceInfo)*pTarget,  FTD_FIELD(NetOuterDeviceInfo) * pSource) 
{ COPY_FTD_ENTITY(NetOuterDeviceInfo, pTarget, pSource); }

typedef void (* FTD_OBJ_COPIER_F2RTN_T(NetOuterDeviceInfo))(FTD_RTN(NetOuterDeviceInf)*pTarget,  FTD_FIELD(NetOuterDeviceInfo) * pSource); \
static void FTD_OBJ_COPIER_F2RTN(NetOuterDeviceInfo)(FTD_RTN(NetOuterDeviceInf)*pTarget,  FTD_FIELD(NetOuterDeviceInfo) * pSource) 
{ COPY_FTD_ENTITY(NetOuterDeviceInfo, pTarget, pSource); }

typedef void (* FTD_OBJ_COPIER_RSP2RTN_T(NetOuterDeviceInfo))(FTD_RTN(NetOuterDeviceInf)*pTarget,  FTD_RSP(OuterDeviceInf) * pSource); \
static void FTD_OBJ_COPIER_RSP2RTN(NetOuterDeviceInfo)(FTD_RTN(NetOuterDeviceInf)*pTarget,  FTD_RSP(OuterDeviceInf) * pSource) 
{ COPY_FTD_ENTITY(NetOuterDeviceInfo, pTarget, pSource); }




#define DO_OPERATION(table, reqField, handle, operData, defaultHandler)\
do {\
	if(table == "SysNetSubAreaIP") {\
		handle(NetSubAreaIP, reqField, operData, NetSubAreaIP);\
		break;\
	}\
	if(table == "SysNetInterface") {\
		handle(NetInterface, reqField, operData, NetInterface);\
		break;\
	}\
	if(table == "SysMemberLinkCost") {\
		handle(MemberLinkCost, reqField, operData, MemberLinkCost);\
		break;\
	}\
	if(table == "SysNetEventLevel") {\
		handle(NetEventLevel, reqField, operData, NetEventLevel);\
		break;\
	}\
	if(table == "SysNetGatherTask") {\
		handle(NetGatherTask, reqField, operData, NetGatherTask);\
		break;\
	}\
	if(table == "SysNetMonitorAttrType") {\
		handle(NetMonitorAttrType, reqField, operData, NetMonitorAttrType);\
		break;\
	}\
	if(table == "SysNetDelPartyLinkInfo") {\
		handle(NetDelPartyLinkInfo, reqField, operData, NetDelPartyLinkInfo);\
		break;\
	}\
	if(table == "SysNetMonitorCommandType") {\
		handle(NetMonitorCommandType, reqField, operData, NetMonitorCommandType);\
		break;\
	}\
	if(table == "SysNetMonitorDeviceTask") {\
		handle(NetMonitorDeviceTask, reqField, operData, NetMonitorDeviceTask);\
		break;\
	}\
	if(table == "SysNetMonitorActionAttr") {\
		handle(NetMonitorActionAttr, reqField, operData, NetMonitorActionAttr);\
		break;\
	}\
	if(table == "SysNetMonitorType") {\
		handle(NetMonitorType, reqField, operData, NetMonitorType);\
		break;\
	}\
	if(table == "SysNetMonitorActionGroup") {\
		handle(NetMonitorActionGroup, reqField, operData, NetMonitorActionGroup);\
		break;\
	}\
	if(table == "SysNetTimePolicy") {\
		handle(NetTimePolicy, reqField, operData, NetTimePolicy);\
		break;\
	}\
	if(table == "SysNetDevice") {\
		handle(NetDevice, reqField, operData, NetDevice);\
		break;\
	}\
	if(table == "SysNetMonitorAttrScope") {\
		handle(NetMonitorAttrScope, reqField, operData, NetMonitorAttrScope);\
		break;\
	}\
	if(table == "SysNetCommunity") {\
		handle(NetCommunity, reqField, operData, NetCommunity);\
		break;\
	}\
	if(table == "SysNetSubEventType") {\
		handle(NetSubEventType, reqField, operData, NetSubEventType);\
		break;\
	}\
	if(table == "SysNetPartyLinkInfo") {\
		handle(NetPartyLinkInfo, reqField, operData, NetPartyLinkInfo);\
		break;\
	}\
	if(table == "SysNetBaseLineTask") {\
		handle(NetBaseLineTask, reqField, operData, NetBaseLineTask);\
		break;\
	}\
	if(table == "SysNetMonitorTaskInstAttrs") {\
		handle(NetMonitorTaskInstAttrs, reqField, operData, NetMonitorTaskInstAttrs);\
		break;\
	}\
	if(table == "SysNetEventExpr") {\
		handle(NetEventExpr, reqField, operData, NetEventExpr);\
		break;\
	}\
	if(table == "SysNetDeviceType") {\
		handle(NetDeviceType, reqField, operData, NetDeviceType);\
		break;\
	}\
	if(table == "SysNetDDNLinkInfo") {\
		handle(NetDDNLinkInfo, reqField, operData, NetDDNLinkInfo);\
		break;\
	}\
	if(table == "SysNetDeviceLinked") {\
		handle(NetDeviceLinked, reqField, operData, NetDeviceLinked);\
		break;\
	}\
	if(table == "SysNetDeviceCategory") {\
		handle(NetDeviceCategory, reqField, operData, NetDeviceCategory);\
		break;\
	}\
	if(table == "SysNetPartylinkMonthlyRent") {\
		handle(NetPartylinkMonthlyRent, reqField, operData, NetPartylinkMonthlyRent);\
		break;\
	}\
	if(table == "SysNetPseudMemberLinkInfo") {\
		handle(NetPseudMemberLinkInfo, reqField, operData, NetPseudMemberLinkInfo);\
		break;\
	}\
	if(table == "SysNetModule") {\
		handle(NetModule, reqField, operData, NetModule);\
		break;\
	}\
	if(table == "SysNetManufactory") {\
		handle(NetManufactory, reqField, operData, NetManufactory);\
		break;\
	}\
	if(table == "SysNetMemberSDHLineInfo") {\
		handle(NetMemberSDHLineInfo, reqField, operData, NetMemberSDHLineInfo);\
		break;\
	}\
	if(table == "SysNetNonPartyLinkInfo") {\
		handle(NetNonPartyLinkInfo, reqField, operData, NetNonPartyLinkInfo);\
		break;\
	}\
	if(table == "SysNetPartyLinkAddrChange") {\
		handle(NetPartyLinkAddrChange, reqField, operData, NetPartyLinkAddrChange);\
		break;\
	}\
	if(table == "SysNetEventType") {\
		handle(NetEventType, reqField, operData, NetEventType);\
		break;\
	}\
	if(table == "SysNetOID") {\
		handle(NetOID, reqField, operData, NetOID);\
		break;\
	}\
	if(table == "SysNetSubArea") {\
		handle(NetSubArea, reqField, operData, NetSubArea);\
		break;\
	}\
	if(table == "SysNetFuncArea") {\
		handle(NetFuncArea, reqField, operData, NetFuncArea);\
		break;\
	}\
	if(table == "SysNetMonitorDeviceGroup") {\
		handle(NetMonitorDeviceGroup, reqField, operData, NetMonitorDeviceGroup);\
		break;\
	}\
	if(table == "SysNetMonitorTaskInfo") {\
		handle(NetMonitorTaskInfo, reqField, operData, NetMonitorTaskInfo);\
		break;\
	}\
	if(table == "SysNetArea") {\
		handle(NetArea, reqField, operData, NetArea);\
		break;\
	}\
	if(table == "SysNetOuterDeviceInfo") {\
		handle(NetOuterDeviceInfo, reqField, operData, NetOuterDeviceInf);\
		break;\
	}\
	defaultHandler(operData);\
} while(0)

#endif // __GENERAL_OPERATION_TABLES_INTERNAL_H
