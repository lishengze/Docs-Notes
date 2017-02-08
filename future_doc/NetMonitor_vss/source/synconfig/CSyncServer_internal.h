/////////////////////////////////////////////////////////////////////////
///@system 网络监控系统
///@company 上海期货信息技术有限公司
///@file CSyncServer_internal.h
///@brief 定义了处理同步配置服务的代码，由脚本生产而成，勿直接修改本文件
///@history
///20110928	李志伟		创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef __CSYNC_SERVER_INTERNAL_H
#define __CSYNC_SERVER_INTERNAL_H

#include <FTDDataHelper.h>
#include <PrjCommon.h>

#ifdef PACKAGE_OUTPUT
extern CFileLogger* g_recvPkgLogger;		// 数据包输出到文件
extern CBufferLogger* g_bufferLogger;
#endif


#define HANDLE_RTN_TOPIC(tag) \
    do {\
        if (isMaster()) {\
            LOG_ERROR("Only slavery will get notify info, Check you master and slavery!");\
        }\
        FTD_RTN(tag) field;\
        FOREACH_FIELD(pFTDCPackage, FTD_RTN(tag), field)\
        {\
            bool result = true;\
            switch (field.OperationType)\
            {\
                case 2:\
                {\
                    INSERT_OBJ_TO_DB(tag, field, m_dbHandler, result);\
                    break;\
                }\
                case 3:\
                {\
                    DELETE_OBJ_FROM_DB(tag, field, "ID", m_dbHandler, result);\
                    break;\
                }\
                case 4:\
                {\
                    UPDATE_OBJ_TO_DB(tag, field, "ID", m_dbHandler, result);\
                    break;\
                }\
                default:\
               {\
                    LOG_WARNING("Invalid operation type");\
                    break;\
               }\
            }\
        }\
    } while(0)


#define HANDLE_RTN_TOPIC2(tag, tag2) \
    do {\
        if (isMaster()) {\
            LOG_ERROR("Only slavery will get notify info, Check you master and slavery!");\
        }\
        FTD_RTN(tag) field;\
        FOREACH_FIELD(pFTDCPackage, FTD_RTN(tag), field)\
        {\
            bool result = true;\
            switch (field.OperationType)\
            {\
                case 2:\
                {\
                    INSERT_OBJ_TO_DB(tag2, field, m_dbHandler, result);\
                    break;\
                }\
                case 3:\
                {\
                    DELETE_OBJ_FROM_DB(tag2, field, "ID", m_dbHandler, result);\
                    break;\
                }\
                case 4:\
                {\
                    UPDATE_OBJ_TO_DB(tag2, field, "ID", m_dbHandler, result);\
                    break;\
                }\
                default:\
               {\
                    LOG_WARNING("Invalid operation type");\
                    break;\
               }\
            }\
        }\
    } while(0)


/* 	 Please copy me to declaration of CSyncServer
void OnRtnNetSubAreaIPTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetInterfaceTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnMemberLinkCostTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetEventLevelTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetGatherTaskTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetMonitorAttrTypeTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetDelPartyLinkInfoTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetBaseLineTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetMonitorCommandTypeTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetMonitorDeviceTaskTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetMonitorActionAttrTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetMonitorTypeTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetMonitorActionGroupTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetTimePolicyTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetDeviceTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetOuterDeviceInfTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetGeneralOIDTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetMonitorAttrScopeTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetCommunityTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetSubEventTypeTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetPartyLinkInfoTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetBaseLineTaskTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetMonitorTaskInstAttrsTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetManufactoryTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetDeviceTypeTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetDDNLinkInfoTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetDeviceLinkedTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetMonitorDeviceGroupTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetPartylinkMonthlyRentTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetPseudMemberLinkInfoTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetModuleTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetMemberSDHLineInfoTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetAreaTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetNonPartyLinkInfoTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetPartyLinkAddrChangeTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetEventExprTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetDeviceCategoryTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetSubAreaTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetEventTypeTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetOIDTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetMonitorTaskInfoTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

void OnRtnNetFuncAreaTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);
*/

void CSyncServer::OnRtnNetSubAreaIPTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetSubAreaIP);
}

void CSyncServer::OnRtnNetInterfaceTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetInterface);
}

void CSyncServer::OnRtnMemberLinkCostTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(MemberLinkCost);
}

void CSyncServer::OnRtnNetEventLevelTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetEventLevel);
}

void CSyncServer::OnRtnNetGatherTaskTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetGatherTask);
}

void CSyncServer::OnRtnNetMonitorAttrTypeTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetMonitorAttrType);
}

void CSyncServer::OnRtnNetDelPartyLinkInfoTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetDelPartyLinkInfo);
}

void CSyncServer::OnRtnNetBaseLineTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetBaseLine);
}

void CSyncServer::OnRtnNetMonitorCommandTypeTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetMonitorCommandType);
}

void CSyncServer::OnRtnNetMonitorDeviceTaskTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetMonitorDeviceTask);
}

void CSyncServer::OnRtnNetMonitorActionAttrTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetMonitorActionAttr);
}

void CSyncServer::OnRtnNetMonitorTypeTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetMonitorType);
}

void CSyncServer::OnRtnNetMonitorActionGroupTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetMonitorActionGroup);
}

void CSyncServer::OnRtnNetTimePolicyTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetTimePolicy);
}

void CSyncServer::OnRtnNetDeviceTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetDevice);
}

void CSyncServer::OnRtnNetOuterDeviceInfTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC2(NetOuterDeviceInf,NetOuterDeviceInfo);
}

void CSyncServer::OnRtnNetGeneralOIDTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetGeneralOID);
}

void CSyncServer::OnRtnNetMonitorAttrScopeTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetMonitorAttrScope);
}

void CSyncServer::OnRtnNetCommunityTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetCommunity);
}

void CSyncServer::OnRtnNetSubEventTypeTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetSubEventType);
}

void CSyncServer::OnRtnNetPartyLinkInfoTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetPartyLinkInfo);
}

void CSyncServer::OnRtnNetBaseLineTaskTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetBaseLineTask);
}

void CSyncServer::OnRtnNetMonitorTaskInstAttrsTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetMonitorTaskInstAttrs);
}

void CSyncServer::OnRtnNetManufactoryTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetManufactory);
}

void CSyncServer::OnRtnNetDeviceTypeTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetDeviceType);
}

void CSyncServer::OnRtnNetDDNLinkInfoTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetDDNLinkInfo);
}

void CSyncServer::OnRtnNetDeviceLinkedTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetDeviceLinked);
}

void CSyncServer::OnRtnNetMonitorDeviceGroupTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetMonitorDeviceGroup);
}

void CSyncServer::OnRtnNetPartylinkMonthlyRentTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetPartylinkMonthlyRent);
}

void CSyncServer::OnRtnNetPseudMemberLinkInfoTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetPseudMemberLinkInfo);
}

void CSyncServer::OnRtnNetModuleTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetModule);
}

void CSyncServer::OnRtnNetMemberSDHLineInfoTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetMemberSDHLineInfo);
}

void CSyncServer::OnRtnNetAreaTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetArea);
}

void CSyncServer::OnRtnNetNonPartyLinkInfoTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetNonPartyLinkInfo);
}

void CSyncServer::OnRtnNetPartyLinkAddrChangeTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetPartyLinkAddrChange);
}

void CSyncServer::OnRtnNetEventExprTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetEventExpr);
}

void CSyncServer::OnRtnNetDeviceCategoryTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetDeviceCategory);
}

void CSyncServer::OnRtnNetSubAreaTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetSubArea);
}

void CSyncServer::OnRtnNetEventTypeTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetEventType);
}

void CSyncServer::OnRtnNetOIDTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetOID);
}

void CSyncServer::OnRtnNetMonitorTaskInfoTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetMonitorTaskInfo);
}

void CSyncServer::OnRtnNetFuncAreaTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	HANDLE_RTN_TOPIC(NetFuncArea);
}

int CSyncServer::HandlePackage(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
#ifdef PACKAGE_OUTPUT
    LogPkg(pFTDCPackage, g_bufferLogger, g_recvPkgLogger);
#endif

	switch(pFTDCPackage->GetTID())
	{
		case FTD_TID_RtnNetSubAreaIPTopic:
			OnRtnNetSubAreaIPTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetInterfaceTopic:
			OnRtnNetInterfaceTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnMemberLinkCostTopic:
			OnRtnMemberLinkCostTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetEventLevelTopic:
			OnRtnNetEventLevelTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetGatherTaskTopic:
			OnRtnNetGatherTaskTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetMonitorAttrTypeTopic:
			OnRtnNetMonitorAttrTypeTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetDelPartyLinkInfoTopic:
			OnRtnNetDelPartyLinkInfoTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetBaseLineTopic:
			OnRtnNetBaseLineTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetMonitorCommandTypeTopic:
			OnRtnNetMonitorCommandTypeTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetMonitorDeviceTaskTopic:
			OnRtnNetMonitorDeviceTaskTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetMonitorActionAttrTopic:
			OnRtnNetMonitorActionAttrTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetMonitorTypeTopic:
			OnRtnNetMonitorTypeTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetMonitorActionGroupTopic:
			OnRtnNetMonitorActionGroupTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetTimePolicyTopic:
			OnRtnNetTimePolicyTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetDeviceTopic:
			OnRtnNetDeviceTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetOuterDeviceInfTopic:
			OnRtnNetOuterDeviceInfTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetGeneralOIDTopic:
			OnRtnNetGeneralOIDTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetMonitorAttrScopeTopic:
			OnRtnNetMonitorAttrScopeTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetCommunityTopic:
			OnRtnNetCommunityTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetSubEventTypeTopic:
			OnRtnNetSubEventTypeTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetPartyLinkInfoTopic:
			OnRtnNetPartyLinkInfoTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetBaseLineTaskTopic:
			OnRtnNetBaseLineTaskTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetMonitorTaskInstAttrsTopic:
			OnRtnNetMonitorTaskInstAttrsTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetManufactoryTopic:
			OnRtnNetManufactoryTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetDeviceTypeTopic:
			OnRtnNetDeviceTypeTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetDDNLinkInfoTopic:
			OnRtnNetDDNLinkInfoTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetDeviceLinkedTopic:
			OnRtnNetDeviceLinkedTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetMonitorDeviceGroupTopic:
			OnRtnNetMonitorDeviceGroupTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetPartylinkMonthlyRentTopic:
			OnRtnNetPartylinkMonthlyRentTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetPseudMemberLinkInfoTopic:
			OnRtnNetPseudMemberLinkInfoTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetModuleTopic:
			OnRtnNetModuleTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetMemberSDHLineInfoTopic:
			OnRtnNetMemberSDHLineInfoTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetAreaTopic:
			OnRtnNetAreaTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetNonPartyLinkInfoTopic:
			OnRtnNetNonPartyLinkInfoTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetPartyLinkAddrChangeTopic:
			OnRtnNetPartyLinkAddrChangeTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetEventExprTopic:
			OnRtnNetEventExprTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetDeviceCategoryTopic:
			OnRtnNetDeviceCategoryTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetSubAreaTopic:
			OnRtnNetSubAreaTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetEventTypeTopic:
			OnRtnNetEventTypeTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetOIDTopic:
			OnRtnNetOIDTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetMonitorTaskInfoTopic:
			OnRtnNetMonitorTaskInfoTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetFuncAreaTopic:
			OnRtnNetFuncAreaTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqSubscribeTopic:
			m_flowSync->OnReqFlowSyncTopic(pFTDCPackage, pSession);
			break;
		default:
			break;
	}

	m_flowSync->addToFlow(pFTDCPackage);

    return 0;
}

#endif // __CSYNC_SERVER_INTERNAL_H
