/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	FibClientServer.cpp
///@brief	实现了定义了面向前置机会话连接服务类
///@history	
///20080624	郭鹏		创建该文件
///20080624	郭鹏		修订注释
/////////////////////////////////////////////////////////////////////////
#include "FibClientServer.h"
#include "CFPPSubscriber.h"
// 20150303, modified by cao.ning, 没有使用的变量
//extern char *pszFlowPath;
CCachedFlow *m_TRFlow;
list<CFTDCSession *> frontList;

extern string g_strTryDate;

///用于按IP统计登录数
extern map<string, ipLinkInfo>	g_ipLinkInfo;

///用于按托管IP统计登录数
extern map<string, ipLinkInfo>	g_ipLinkInfoTuoGuan;

///未在各范围之列的统计信息
extern map<CParticipantIDType, list<userIpInfo> > theOtherIpInfo;

///最后100个流水报文
extern list<trsInfo> tsList;
extern list<trsInfo> trList;

void CFibClientServer::OnSessionConnected(CSession *pSession)
{
	time_t	timep;
	time(&timep);
	printf(
		"\t %s CFibClientServer::OnSessionConnected: %0x \n",
		ctime(&timep),
		pSession);
	CSessionFactory::OnSessionConnected(pSession);
}

void CFibClientServer::OnSessionDisconnected(CSession *pSession, int nReason)
{
	time_t	timep;
	time(&timep);
	printf(
		"\t %s CFibClientServer::OnSessionDisconnected: %0x \n",
		ctime(&timep),
		pSession);
	CSessionFactory::OnSessionDisconnected(pSession, nReason);

	frontList.remove((CFTDCSession *)pSession);
}

int CFibClientServer::HandlePackage(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	//	printf("\tCFibClientServer::HandlePackage:receive package %0x\n",pFTDCPackage->GetTID());
	switch (pFTDCPackage->GetTID())
	{
		case FTD_TID_ReqUserLogin:
			OnReqUserLogin(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetDeviceLinkedTopic:
			{
				CFTDReqQryNetDeviceLinkedField	qryfield;
				if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)
				{
					return 0;
				}

				if (qryfield.SysNetSubAreaID == 4097)
				{
					int index = 0;
					list<trsInfo> tmpList;
					list<trsInfo>::reverse_iterator rit = trList.rbegin();
					for (; rit != trList.rend(); rit++)
					{
						tmpList.push_front(*rit);
						if (++index == qryfield.IPDECODE)
						{
							break;
						}
					}

					list<trsInfo>::iterator it = tmpList.begin();
					for (; it != tmpList.end(); it++)
					{
						vector<CFTDRspQryTradeLogField>::iterator itVec = it->field.
							begin();
						for (; itVec != it->field.end(); itVec++)
						{
							m_pkgSend.PreparePackage(
									FTD_TID_RspQryTradeLogTopic,
									FTDC_CHAIN_CONTINUE,
									FTD_VERSION);
							m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());

							CFTDRspQryTradeLogField tfield;
							memset(&tfield, 0, sizeof(tfield));
							CopyRspQryTradeLogEntity(
								&tfield,
								&(*itVec)) FTDC_ADD_FIELD(&m_pkgSend, &tfield);

							CFTDRspInfoField rspInfoField;
							memset(&rspInfoField, 0, sizeof(rspInfoField));
							rspInfoField.ErrorID = 4097;
							strcpy(
								(char *)rspInfoField.ErrorMsg.getValue(),
								it->time.data());
							FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
							pSession->SendRequestPackage(&m_pkgSend);
						}
					}
				}
				else
				{
					int index = 0;
					list<trsInfo> tmpList;
					list<trsInfo>::reverse_iterator rit = tsList.rbegin();
					for (; rit != tsList.rend(); rit++)
					{
						tmpList.push_front(*rit);
						if (++index == qryfield.IPDECODE)
						{
							break;
						}
					}

					list<trsInfo>::iterator it = tmpList.begin();
					for (; it != tmpList.end(); it++)
					{
						vector<CFTDRspQryTradeLogField>::iterator itVec = it->field.
							begin();
						for (; itVec != it->field.end(); itVec++)
						{
							m_pkgSend.PreparePackage(
									FTD_TID_RspQryTradeLogTopic,
									FTDC_CHAIN_CONTINUE,
									FTD_VERSION);
							m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());

							CFTDRspQryTradeLogField tfield;
							memset(&tfield, 0, sizeof(tfield));
							CopyRspQryTradeLogEntity(
								&tfield,
								&(*itVec)) FTDC_ADD_FIELD(&m_pkgSend, &tfield);

							CFTDRspInfoField rspInfoField;
							memset(&rspInfoField, 0, sizeof(rspInfoField));
							rspInfoField.ErrorID = 4099;
							strcpy(
								(char *)rspInfoField.ErrorMsg.getValue(),
								it->time.data());
							FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
							pSession->SendRequestPackage(&m_pkgSend);
						}
					}
				}
			}

		case FTD_TID_ReqQryTradeUserLoginStatTopic:
			{
				CFTDReqQryTradeUserLoginStatField qryfield;
				if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)
				{
					return 0;
				}

				string	oid = qryfield.ObjectID.getValue();
				map<string, ipLinkInfo>::iterator it = g_ipLinkInfo.find(oid);
				if (it != g_ipLinkInfo.end())
				{
					map<CParticipantIDType, list<userIpInfo> >::iterator itMap =
						it->second.linkNumber.begin();
					for (; itMap != it->second.linkNumber.end(); itMap++)
					{
						list<userIpInfo>::iterator	itList = itMap->second.begin();
						for (; itList != itMap->second.end(); itList++)
						{
							m_pkgSend.PreparePackage(
									FTD_TID_RspQryTradeUserLoginStatTopic,
									FTDC_CHAIN_CONTINUE,
									FTD_VERSION);
							m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());

							CFTDRspQryTradeUserLoginStatField tfield;
							memset(&tfield, 0, sizeof(tfield));
							tfield.ObjectID = qryfield.ObjectID;
							tfield.ParticipantID = itMap->first;
							tfield.UserID = itList->id;
							tfield.IPAddress = itList->ip;
							FTDC_ADD_FIELD(&m_pkgSend, &tfield);
							pSession->SendRequestPackage(&m_pkgSend);
						}
					}
				}
				else
				{
					map<CParticipantIDType, list<userIpInfo> >::iterator itMap =
						theOtherIpInfo.begin();
					for (; itMap != theOtherIpInfo.end(); itMap++)
					{
						list<userIpInfo>::iterator	itList = itMap->second.begin();
						for (; itList != itMap->second.end(); itList++)
						{
							m_pkgSend.PreparePackage(
									FTD_TID_RspQryTradeUserLoginStatTopic,
									FTDC_CHAIN_CONTINUE,
									FTD_VERSION);
							m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());

							CFTDRspQryTradeUserLoginStatField tfield;
							memset(&tfield, 0, sizeof(tfield));
							tfield.ObjectID = qryfield.ObjectID;
							tfield.ParticipantID = itMap->first;
							tfield.UserID = itList->id;
							tfield.IPAddress = itList->ip;
							FTDC_ADD_FIELD(&m_pkgSend, &tfield);
							pSession->SendRequestPackage(&m_pkgSend);
						}
					}
				}

				///应答是否为托管oid请求
				/*{
					map<string ,ipLinkInfo>::iterator it =g_ipLinkInfoTuoGuan.find(oid);
					if(it !=g_ipLinkInfoTuoGuan.end())
					{
						map<CParticipantIDType ,list<userIpInfo> >::iterator itMap =it->second.linkNumber.begin();
						for( ;itMap !=it->second.linkNumber.end() ;itMap ++)
						{
							list<userIpInfo>::iterator itList =itMap->second.begin();
							for( ;itList !=itMap->second.end() ;itList ++)
							{
								m_pkgSend.PreparePackage(FTD_TID_RspQryTradeUserLoginStatTopic,FTDC_CHAIN_CONTINUE,FTD_VERSION);
								m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());
								CFTDRspQryTradeUserLoginStatField tfield;
								memset(&tfield ,0 ,sizeof(tfield));
								tfield.ObjectID =qryfield.ObjectID;
								tfield.ParticipantID =itMap->first;
								tfield.UserID =itList->id;
								tfield.IPAddress =itList->ip;
								FTDC_ADD_FIELD(&m_pkgSend, &tfield);
								pSession->SendRequestPackage(&m_pkgSend);
							}
						}
					}
				}*/
				m_pkgSend.PreparePackage(
						FTD_TID_RspQryTradeUserLoginStatTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());

				CFTDRspInfoField rspInfoField;
				memset(&rspInfoField, 0, sizeof(rspInfoField));
				rspInfoField.ErrorID = 0;
				FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
				pSession->SendRequestPackage(&m_pkgSend);
			}

			break;
		default:
			break;
	}

	return 0;
}

void CFibClientServer::OnReqUserLogin(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	//printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);

	CFTDReqUserLoginField fieldLogin;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldLogin);
	printf(
		"\tCounterConnector::OnReqUserLogin:user=%s password=%s\n",
		(const char *)fieldLogin.UserID,
		(const char *)fieldLogin.Password);

	CFTDDisseminationField	fieldDissemination;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldDissemination))
	{	//登录请求中含有订阅域
		pSession->Publish(
				m_TRFlow,
				fieldDissemination.SequenceSeries,
				fieldDissemination.SequenceNo);
	}
	else
	{	//登录请求中不含有订阅域
		pSession->Publish(m_TRFlow, 1, 0);
	}

	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspUserLogin,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	FTDC_ADD_FIELD(&m_pkgSend, &fieldLogin);

	CFTDRspInfoField fieldRspInfo;
	fieldRspInfo.ErrorMsg = "成功";
	fieldRspInfo.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &fieldRspInfo);

	/// Added by Henchi, 20140620
	/// 增加交易日通知信息
	CFTDReqQryTradeDayChangeField tfield;
	tfield.ChangeType = TRUNCATEFLOW;
	strcpy((char *)tfield.OldDate.getValue(), g_strTryDate.data());
	strcpy((char *)tfield.NewDate.getValue(), g_strTryDate.data());
	FTDC_ADD_FIELD(&m_pkgSend, &tfield);

	pSession->SendRequestPackage(&m_pkgSend);

	list<CFTDCSession *>::iterator	it = find(
			frontList.begin(),
			frontList.end(),
			pSession);
	if (it == frontList.end())
	{
		frontList.push_back(pSession);
	}
}

void CFibClientServer::NotifyFrontNewTradeDay(
	string	strOldDay,
	string	strNewDay)
{
	m_pkgSend.PreparePackage(
			FTD_TID_ReqQryTradeDayChangeTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDReqQryTradeDayChangeField tfield;
	tfield.ChangeType = TRUNCATEFLOW;
	strcpy((char *)tfield.OldDate.getValue(), strOldDay.data());
	strcpy((char *)tfield.NewDate.getValue(), strNewDay.data());
	FTDC_ADD_FIELD(&m_pkgSend, &tfield);

	list<CFTDCSession *>::iterator	it = frontList.begin();
	for (; it != frontList.end(); it++)
	{
		(*it)->SendRequestPackage(&m_pkgSend);
		m_pkgSend.Pop(FTDCHLEN);
	}
}
