/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CSynConnector.cpp
///@brief	实现了连接配置管理服务器通信消息的类
///@history
///20110112	周建军		创建该文件
#include "CSynConnector.h"
#include "FrontServer.h"
#include "CPerformanceAnalyze.h"

extern list<CFTDCSession *> g_mListAllSession;
extern map<string, CFTDRspQryEventDescriptionField> g_EventDealDsec;

// add by cao.ning 网络性能处理对象
extern CPerformanceAnalyzer* g_pPerformanceAnalyzer;

#ifdef PACKAGE_OUTPUT
extern CLogger	*g_pConPackOutput;	// 数据包输出到文件
#endif
#define MACRSP2FRONT(x)																							\
	{																											\
		int nRid = pFTDCPackage->GetRequestId();																\
		map<int, TRID>::iterator it = m_pFrontServer->m_vRid.find(nRid);										\
		if (it != m_pFrontServer->m_vRid.end())																	\
		{																										\
			TRID rid = it->second;																				\
			m_pkgSend.PreparePackage(																			\
					FTD_TID_RspQry##x##Topic,																	\
					FTDC_CHAIN_LAST,																			\
					FTD_VERSION);																				\
			m_pkgSend.SetChain(pFTDCPackage->GetChain());														\
			m_pkgSend.SetRequestId(rid.RequestId);																\
			CFTDRspInfoField rspInfoField;																		\
			if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &rspInfoField) > 0)											\
			{																									\
				FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);														\
			}																									\
																									 \
			CFTDRspQry##x##Field  sfield;																		\
			CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(										\
					&CFTDRspQry##x##Field::m_Describe);															\
			while (!itor.IsEnd())																				\
			{																									\
				itor.Retrieve(&sfield);																			\
				CFTDRspQry##x##Field tfield;																	\
				memset(&tfield, 0, sizeof(tfield));																\
				CopyRspQry##x##Entity(&tfield, &sfield);														\
				FTDC_ADD_FIELD(&m_pkgSend, &tfield);															\
				itor.Next();																					\
				if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())								\
				{																								\
					break;																						\
				}																								\
			}																									\
																									 \
			if (m_pFrontServer->GetSession(rid.SessionID))														\
			{																									\
				((CFTDCSession *) (m_pFrontServer->GetSession(rid.SessionID)))->SendRequestPackage(&m_pkgSend); \
			}																									\
																									 \
			if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST)													\
			{																									\
				m_pFrontServer->m_vRid.erase(it);																\
			}																									\
		}																										\
	}

#define MACRTN2FRONT(x)													\
	{																	\
		CFTDRtn##x##Field fieldInfo;									\
		CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator( \
				&CFTDRtn##x##Field::m_Describe);						\
		while (!itor.IsEnd())											\
		{																\
			itor.Retrieve(&fieldInfo);									\
			m_pkgSend.PreparePackage(									\
					FTD_TID_Rtn##x##Topic,								\
					FTDC_CHAIN_LAST,									\
					FTD_VERSION);										\
			FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);						\
			list<CFTDCSession *>::iterator	it;							\
			for (it = g_mListAllSession.begin();						\
				 it != g_mListAllSession.end();							\
				 it++)													\
			{															\
				(*it)->SendRequestPackage(&m_pkgSend);					\
				m_pkgSend.Pop(FTDCHLEN);								\
			}															\
															 \
			itor.Next();												\
		}																\
	}

CSynConnector::CSynConnector(CReactor * pReactor)
	:
	CSessionFactory(pReactor, 1)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	m_Flag = false;
	m_pSynSession = NULL;
}

CSession *CSynConnector::CreateSession(CChannel *pChannel, DWORD dwMark)
{
	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	pSession->RegisterPackageHandler(this);
	return pSession;
}

void CSynConnector::OnSessionConnected(CSession *pSession)
{
	CSessionFactory::OnSessionConnected(pSession);

	time_t	timep;
	time(&timep);
	printf(
		"\t %s CSynConnector::OnSessionConnected: %0x \n",
		ctime(&timep),
		pSession);
	fflush(stdout);
	m_Flag = true;
	m_pSynSession = (CFTDCSession *)pSession;

	// 测试和配置管理服务的连通性及数据包处理 20110112
	m_pkgSend.PreparePackage(
			FTD_TID_ReqUserLogin,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDReqUserLoginField fieldLogin;
	memset(&fieldLogin, 0, sizeof(fieldLogin));
	fieldLogin.UserID = "sysfront";
	fieldLogin.Password = "sysfront";
	FTDC_ADD_FIELD(&m_pkgSend, &fieldLogin);
	((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);

	// 20110112
	/*CFTDReqQryNetDeviceLinkField field;
	field.IP ="172.16.80.0";
	field.Mask ="255.255.255.0";
	m_pkgSend.PreparePackage(FTD_TID_ReqQryNetDeviceLinkTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	FTDC_ADD_FIELD(&m_pkgSend, &field);
	((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);*/
}

void CSynConnector::OnSessionDisconnected(CSession *pSession, int nReason)	// 子类重载处理连接断开事件
{
	CSessionFactory::OnSessionDisconnected(pSession, nReason);	// 子类调用父类处理连接断开事件
	time_t	timep;
	time(&timep);
	printf(
		"\t %s CSynConnector::OnSessionDisconnected: %0x \n",
		ctime(&timep),
		pSession);
	fflush(stdout);
	m_Flag = false;
	m_pSynSession = NULL;
}

int CSynConnector::HandlePackage(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PACKAGE_OUTPUT
	printf("\tCFrontServer::receive package TID %x\n", pFTDCPackage->GetTID());
	pFTDCPackage->OutputHeader(g_pConPackOutput);
	FTDC_DEBUG_BODY(pFTDCPackage->GetTID(), pFTDCPackage, g_pConPackOutput);
#endif

	//printf("\tCFlowConnector::HandlePackage:receive package %0x\n",pFTDCPackage->GetTID());
	//fflush(stdout);
	switch (pFTDCPackage->GetTID())
	{
		case FTD_TID_RspUserLogin:
			OnRspUserLogin(pFTDCPackage, pSession);
			break;

		///rsp
		case FTD_TID_RspQryGeneralOperateTopic:
			MACRSP2FRONT(GeneralOperate);
			// 更新网络信息
			if (g_pPerformanceAnalyzer)
			{
				g_pPerformanceAnalyzer->UpdateNetConfig(pFTDCPackage);
			}
			break;
		case FTD_TID_RspQryNetDeviceLinkedTopic:
			MACRSP2FRONT(NetDeviceLinked);
			break;
		case FTD_TID_RspQryNetDeviceTopic:
			MACRSP2FRONT(NetDevice);
			// 更新设备信息
			if (g_pPerformanceAnalyzer)
			{
				g_pPerformanceAnalyzer->UpdateNetConfig(pFTDCPackage);
			}
			break;
		case FTD_TID_RspQryNetDeviceDetectTopic:
			MACRSP2FRONT(NetDeviceDetect);
			break;
		case FTD_TID_RspQryNetDeviceChgTopic:
			MACRSP2FRONT(NetDeviceChg);
			break;
		case FTD_TID_RspQryNetTimePolicyTopic:
			MACRSP2FRONT(NetTimePolicy);
			break;
		case FTD_TID_RspQryNetGatherTaskTopic:
			MACRSP2FRONT(NetGatherTask);
			break;
		case FTD_TID_RspQryNetInterfaceTopic:
			MACRSP2FRONT(NetInterface);
			break;
		case FTD_TID_RspQryNetModuleTopic:
			MACRSP2FRONT(NetModule);
			break;
		case FTD_TID_RspQryNetMonitorTaskObjectSetTopic:
			MACRSP2FRONT(NetMonitorTaskObjectSet);
			break;
		case FTD_TID_RspQryNetMonitorDeviceGroupTopic:
			{
				int nRid = pFTDCPackage->GetRequestId();
				map<int, TRID>::iterator it = m_pFrontServer->m_vRid.find(nRid);
				if (it != m_pFrontServer->m_vRid.end())
				{
					TRID rid = it->second;
					m_pkgSend.PreparePackage(
							FTD_TID_RspQryNetMonitorDeviceGroupTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
					m_pkgSend.SetChain(pFTDCPackage->GetChain());
					m_pkgSend.SetRequestId(rid.RequestId);

					CFTDRspInfoField rspInfoField;
					if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &rspInfoField) > 0)
					{
						FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
					}

					CFTDRspQryNetMonitorDeviceGroupField sfield;
					CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
							&CFTDRspQryNetMonitorDeviceGroupField::m_Describe);
					while (!itor.IsEnd())
					{
						itor.Retrieve(&sfield);

						CFTDRspQryNetMonitorDeviceGroupField tfield;
						CopyRspQryNetMonitorDeviceGroupEntity(&tfield, &sfield);
						FTDC_ADD_FIELD(&m_pkgSend, &tfield);
						itor.Next();
						if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST
						&&	itor.IsEnd())
						{
							break;
						}
					}

					CSession* pCSession = m_pFrontServer->GetSession(rid.SessionID);
					if (pCSession)
					{
						((CFTDCSession *)pCSession)->SendRequestPackage(&m_pkgSend);
					}


					if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST)
					{
						m_pFrontServer->m_vRid.erase(it);
					}
				}
			}

			break;
		case FTD_TID_RspQryNetMonitorTaskInfoTopic:
			MACRSP2FRONT(NetMonitorTaskInfo);
			break;
		case FTD_TID_RspQryNetMonitorAttrScopeTopic:
			MACRSP2FRONT(NetMonitorAttrScope);
			break;
		case FTD_TID_RspQryNetMonitorDeviceTaskTopic:
			MACRSP2FRONT(NetMonitorDeviceTask);
			break;
		case FTD_TID_RspQryFileGeneralOperTopic:
			//MACRSP2FRONT(FileGeneralOper);
			{
				int nRid = pFTDCPackage->GetRequestId();
				map<int, TRID>::iterator it = m_pFrontServer->m_vRid.find(nRid);
				if (it != m_pFrontServer->m_vRid.end())
				{
					TRID rid = it->second;
					m_pkgSend.PreparePackage(
							FTD_TID_RspQryFileGeneralOperTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
					m_pkgSend.SetChain(pFTDCPackage->GetChain());
					m_pkgSend.SetRequestId(rid.RequestId);

					CFTDRspInfoField rspInfoField;
					if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &rspInfoField) > 0)
					{
						FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
					}

					CFTDRspQryFileGeneralOperField	sfield;
					CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
							&CFTDRspQryFileGeneralOperField::m_Describe);
					while (!itor.IsEnd())
					{
						itor.Retrieve(&sfield);

						CFTDRspQryFileGeneralOperField	tfield;
						memset(&tfield, 0, sizeof(tfield));
						CopyRspQryFileGeneralOperEntity(&tfield, &sfield);
						memcpy(
							(void *)(tfield.FileContent.getValue()),
							(void *)(sfield.FileContent.getValue()),
							sizeof(sfield.FileContent));
						FTDC_ADD_FIELD(&m_pkgSend, &tfield);
						itor.Next();
						if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST
						&&	itor.IsEnd())
						{
							break;
						}
					}

					CSession* pCSession = m_pFrontServer->GetSession(rid.SessionID);
					if (pCSession)
					{
						((CFTDCSession *)pCSession)->SendRequestPackage(&m_pkgSend);
					}
					
					if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST)
					{
						m_pFrontServer->m_vRid.erase(it);
					}
				}
			}

			break;
		case FTD_TID_RspQryGetFileTopic:
			//MACRSP2FRONT(GetFile);
			{
				int nRid = pFTDCPackage->GetRequestId();
				map<int, TRID>::iterator it = m_pFrontServer->m_vRid.find(nRid);
				if (it != m_pFrontServer->m_vRid.end())
				{
					TRID rid = it->second;
					m_pkgSend.PreparePackage(
							FTD_TID_RspQryGetFileTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
					m_pkgSend.SetChain(pFTDCPackage->GetChain());
					m_pkgSend.SetRequestId(rid.RequestId);

					CFTDRspInfoField rspInfoField;
					if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &rspInfoField) > 0)
					{
						FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
					}

					CFTDRspQryGetFileField	sfield;
					CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
							&CFTDRspQryGetFileField::m_Describe);
					while (!itor.IsEnd())
					{
						itor.Retrieve(&sfield);

						CFTDRspQryGetFileField	tfield;
						memset(&tfield, 0, sizeof(tfield));
						CopyRspQryGetFileEntity(&tfield, &sfield);
						memcpy(
							(void *)(tfield.Comment.getValue()),
							(void *)(sfield.Comment.getValue()),
							sizeof(sfield.Comment));

						//strcpy(tfield.Comment ,sfield.Comment);
						FTDC_ADD_FIELD(&m_pkgSend, &tfield);
						itor.Next();
						if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST
						&&	itor.IsEnd())
						{
							break;
						}
					}

					CSession* pCSession = m_pFrontServer->GetSession(rid.SessionID);
					if (pCSession)
					{
						((CFTDCSession *)pCSession)->SendRequestPackage(&m_pkgSend);
					}

					if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST)
					{
						m_pFrontServer->m_vRid.erase(it);
					}
				}
			}

			break;

		///rtn
		case FTD_TID_RtnNetTimePolicyTopic:
			MACRTN2FRONT(NetTimePolicy);
			break;
		case FTD_TID_RtnNetGatherTaskTopic:
			MACRTN2FRONT(NetGatherTask);
			break;
		case FTD_TID_RtnNetDeviceChgTopic:
			MACRTN2FRONT(NetDeviceChg);
			break;
		case FTD_TID_RtnNetDeviceTopic:
			MACRTN2FRONT(NetDevice);
			// 获取设备信息
			if (g_pPerformanceAnalyzer)
			{
				g_pPerformanceAnalyzer->UpdateNetConfig(pFTDCPackage);
			}
			break;
		case FTD_TID_RtnNetDeviceLinkedTopic:
			MACRTN2FRONT(NetDeviceLinked);
			break;
		case FTD_TID_RtnNetInterfaceTopic:
			MACRTN2FRONT(NetInterface);
			break;
		case FTD_TID_RtnNetModuleTopic:
			MACRTN2FRONT(NetModule);
			break;
		case FTD_TID_RtnFileGeneralOperTopic:
			{
				CFTDRtnFileGeneralOperField fieldInfo;
				CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
						&CFTDRtnFileGeneralOperField::m_Describe);
				while (!itor.IsEnd())
				{
					itor.Retrieve(&fieldInfo);
					m_pkgSend.PreparePackage(
							FTD_TID_RtnFileGeneralOperTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
					FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);

					list<CFTDCSession *>::iterator	it;
					for (it = g_mListAllSession.begin();
						 it != g_mListAllSession.end();
						 it++)
					{
						(*it)->SendRequestPackage(&m_pkgSend);
						m_pkgSend.Pop(FTDCHLEN);
					}

					itor.Next();
				}
			}

			break;
		case FTD_TID_RtnGeneralOperateTopic:
			MACRTN2FRONT(GeneralOperate);
			// 获取网络信息
			if (g_pPerformanceAnalyzer)
			{
				g_pPerformanceAnalyzer->UpdateNetConfig(pFTDCPackage);
			}
			break;
		case FTD_TID_RtnNetMonitorTaskInfoTopic:
			MACRTN2FRONT(NetMonitorTaskInfo);
			break;
		case FTD_TID_RspQryNetMonitorTaskStatusResultTopic:
			MACRSP2FRONT(NetMonitorTaskStatusResult);
			break;
		case FTD_TID_RspQryNetBaseLineTopic:
			MACRSP2FRONT(NetBaseLine);
			break;
		case FTD_TID_RtnNetBaseLineTopic:
			MACRTN2FRONT(NetBaseLine);
			break;
		case FTD_TID_RtnNetMonitorDeviceGroupTopic:
			MACRTN2FRONT(NetMonitorDeviceGroup);
			break;
		case FTD_TID_RspQrySysUserLoginTopic:
			{
				int nRid = pFTDCPackage->GetRequestId();
				map<int, TRID>::iterator it = m_pFrontServer->m_vRid.find(nRid);
				if (it != m_pFrontServer->m_vRid.end())
				{
					TRID rid = it->second;
					m_pkgSend.PreparePackage(
							FTD_TID_RspQrySysUserLoginTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
					m_pkgSend.SetChain(pFTDCPackage->GetChain());
					m_pkgSend.SetRequestId(rid.RequestId);

					CFTDRspInfoField rspInfoField;
					if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &rspInfoField) > 0)
					{
						FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
					}

					CFTDRspQrySysUserLoginField sfield;
					CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
							&CFTDRspQrySysUserLoginField::m_Describe);
					while (!itor.IsEnd())
					{
						itor.Retrieve(&sfield);

						CFTDRspQrySysUserLoginField tfield;
						CopyRspQrySysUserLoginEntity(&tfield, &sfield);
						FTDC_ADD_FIELD(&m_pkgSend, &tfield);
						itor.Next();
						if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST
						&&	itor.IsEnd())
						{
							break;
						}
					}

					CSession* pCSession = m_pFrontServer->GetSession(rid.SessionID);
					if (pCSession)
					{
						if (sfield.VersionFlag == -1)
						{
							((CFTDCSession *)pCSession)->SendRequestPackage(&m_pkgSend);

						}
						else
						{
							m_pFrontServer->OnSysUserLoginTopic(
								sfield.UserID,
								rid.RequestId,
								(CFTDCSession *)pCSession);
						}
					}

					if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST)
					{
						m_pFrontServer->m_vRid.erase(it);
					}
				}
			}

			break;
		case FTD_TID_RspQryEventDescriptionTopic:

		{
			int nRid = pFTDCPackage->GetRequestId();																
			map<int, TRID>::iterator it = m_pFrontServer->m_vRid.find(nRid);										
			if (it != m_pFrontServer->m_vRid.end())																	
			{																										
				TRID rid = it->second;																				
				m_pkgSend.PreparePackage(																			
						FTD_TID_RspQryEventDescriptionTopic,														
						FTDC_CHAIN_CONTINUE,																			
						FTD_VERSION);																				
				m_pkgSend.SetChain(pFTDCPackage->GetChain());														
				m_pkgSend.SetRequestId(rid.RequestId);																
// 				CFTDRspInfoField rspInfoField;																		
// 				if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &rspInfoField) > 0)											
// 				{																									
// 					FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);														
// 				}																									
																										 
				CFTDRspQryEventDescriptionField  sfield;															
				CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(										
						&CFTDRspQryEventDescriptionField::m_Describe);												
				while (!itor.IsEnd())																				
				{																									
					itor.Retrieve(&sfield);												
					FTDC_ADD_FIELD(&m_pkgSend, &sfield);															
					itor.Next();		

					//缓存数据
					g_EventDealDsec[sfield.EventDesID.getValue()] = sfield;
					
					if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())								
					{																								
						break;																						
					}																								
				}																									

				CSession* pCSession = m_pFrontServer->GetSession(rid.SessionID);
				if (pCSession)
				{

					((CFTDCSession *)pCSession)->SendRequestPackage(&m_pkgSend);

					m_pkgSend.PreparePackage(
						FTD_TID_RspQryEventDescriptionTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
					m_pkgSend.SetChain(pFTDCPackage->GetChain());
					m_pkgSend.SetRequestId(rid.RequestId);

					((CFTDCSession *)pCSession)->SendRequestPackage(&m_pkgSend);

				}

				if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST)													
				{																									
					m_pFrontServer->m_vRid.erase(it);																
				}	
			}	
		}
		break;

		default:
			break;
	}

	return 0;
}

void CSynConnector::OnRspUserLogin(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqUserLoginField fieldLogin;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldLogin);

	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
	printf(
		"\t CSynConnector::OnRspUserLogin:user=%s password=%s ",
		(const char *)fieldLogin.UserID,
		(const char *)fieldLogin.Password);

	CFTDRspInfoField fieldRspInfo;
	fieldRspInfo.ErrorMsg = "成功";
	fieldRspInfo.ErrorID = 0;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldRspInfo);
	printf(
		" reponse msg %s ID %d\n",
		(const char *)fieldRspInfo.ErrorMsg,
		(const int)fieldRspInfo.ErrorID);
}
