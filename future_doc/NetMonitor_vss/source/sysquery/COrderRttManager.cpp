/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	COrderRttManager.cpp
///@brief	定义了数据包过滤的类
///@auther	赵鸿昊
///@history
#include "COrderRttManager.h"
#include "slogparser.h"
#include "CStatusSubscriber.h"

extern char g_szTimeBuffer[10];

//#define PRINT_DEBUG
//20080715 add wu.yb
extern string g_strDbIp;
extern string g_strDbPort;
extern string g_strDbName;
extern string g_strDbUser;
extern string g_strDbPwd;

////////////////////////////

//////////////////////////////////////////////////////////////////////////
//2012.10.23 feng.q
extern unsigned int g_nRttCutLine[8];
extern map<int, int> m_mapSlogFileReadStatus;
extern CSlogReactor *g_pReactor;	// 全局reactor对象指针，只能一次构造
extern bool g_bDecSlogDirect;
extern CDirectlySlogDecode	*g_CSlogDec;

//////////////////////////////////////////////////////////////////////////
extern int	g_nStartParaWrtDB;

void COrderRttAnalysis::OnOFPPackage(
	COFPPackage *pOFPPackage,
	int nSessionID,
	int nFrontID,
	char cVersion)
{
	if (GetOFPVary(pOFPPackage->GetCommand()) == OFP_VARY_OrderInsertRequest)
	{
		COFPOrderInsertRequestField *pReqOrderInsert =
			(COFPOrderInsertRequestField *)pOFPPackage->Address();
		HandleOrderReq(
			pReqOrderInsert->Userid.getValue(),
			pReqOrderInsert->Lorderid.getValue(),
			nSessionID,
			nFrontID,
			cVersion);
	}
	else if (pOFPPackage->GetCommandID() == OFP_VARY_OrderInsertResponse)
	{
		//OFP V1
		COFPOrderInsertResponseField *pRspOrderInsert =
			(COFPOrderInsertResponseField *)pOFPPackage->Address();
		HandleOrderRsp(
			pRspOrderInsert->Userid.getValue(),
			pRspOrderInsert->Lorderid.getValue(),
			nSessionID,
			nFrontID,
			cVersion);
	}
	else if (pOFPPackage->GetCommandID() == OFP_VARY_MBackOrder)
	{
		//OFP V2
		COFPMBackOrderField *pBackOrder =
			(COFPMBackOrderField *)pOFPPackage->Address();
		WORD cmd = 0;
		memcpy(&cmd, &pBackOrder->cmd, 2);
		CHANGE_ENDIAN(cmd);
		if (cmd == OFP_VARY_OrderInsertResponse)
		{
			HandleOrderRsp(
				pBackOrder->Userid.getValue(),
				pBackOrder->Lorderid.getValue(),
				nSessionID,
				nFrontID,
				cVersion);
		}
	}
}

void COrderRttAnalysis::OnFTDCPackage(
	CFTDCPackage *pPackage,
	int nSessionID,
	int nFrontID,
	char cVersion)
{
	switch (pPackage->GetTID())
	{
		case FTD_TID_RspOrderInsert:
			{
				CFTDRTTMeasureField fieldRTTMeasure;
				if (FTDC_GET_SINGLE_FIELD(pPackage, &fieldRTTMeasure) > 0)
				{
					//g_pLoggerOutput->output(LL_DEBUG, "\tRTT=%d\n",fieldRTTMeasure.RTT.getValue());
					int rtt = fieldRTTMeasure.RTT.getValue();

					//printf("\t  frontID=%d version=%d RTT=%d\n", nFrontID, (int)cVersion,  rtt);
					//if (rtt<1)
					//{
					//	rtt = 1 ;
					//} else if (rtt>4)
					//{
					//	rtt = 4;
					//}
					if (rtt <= 300)
					{
						m_mapRttPacketNum[CRttStatsKey(
								nFrontID,
								cVersion)].m_lPacketNum[0]++;
					}
					else if (rtt <= 500)
					{
						m_mapRttPacketNum[CRttStatsKey(
								nFrontID,
								cVersion)].m_lPacketNum[1]++;
					}
					else if (rtt <= 1000)
					{
						m_mapRttPacketNum[CRttStatsKey(
								nFrontID,
								cVersion)].m_lPacketNum[2]++;
					}
					else if (rtt <= 10000)
					{
						m_mapRttPacketNum[CRttStatsKey(
								nFrontID,
								cVersion)].m_lPacketNum[3]++;
					}
					else
					{
						m_mapRttPacketNum[CRttStatsKey(
								nFrontID,
								cVersion)].m_lPacketNum[4]++;
					}

					//////////////////////////////////////////////////////////////////////////
					//2012.10.23 feng.q 添加更详细的rtt统计
					m_mapRttStaticsFront[nFrontID].addOneOrder(rtt, g_szTimeBuffer);

					//////////////////////////////////////////////////////////////////////////
				}
				else
				{
					m_mapRttPacketNum[CRttStatsKey(
							nFrontID,
							cVersion)].m_lPacketNum[4]++;
				}
			}

			break;

	#if 0
		case FTD_TID_ReqOrderInsert:
			{
				CFTDInputOrderField fieldInputOrder;
				if (FTDC_GET_SINGLE_FIELD(pPackage, &fieldInputOrder) <= 0)
				{
					// 				g_pLoggerError->output(LL_DEBUG,
					// 					"ReqOrderInsert missing CFTDInputOrderField[%s][%d]\n",
					// 					g_szTimeBuffer, nSessionID);
				}
				else
				{
					HandleOrderReq(
						fieldInputOrder.UserID,
						fieldInputOrder.OrderLocalID,
						nSessionID,
						nFrontID,
						cVersion);
				}
			}

			break;
		case FTD_TID_RspOrderInsert:
			{
				CFTDInputOrderField fieldInputOrder;
				if (FTDC_GET_SINGLE_FIELD(pPackage, &fieldInputOrder) <= 0)
				{
					// 				g_pLoggerError->output(LL_DEBUG,
					// 					"RspOrderInsert missing CFTDInputOrderField[%s][%d]\n",
					// 					g_szTimeBuffer, nSessionID);
				}
				else
				{
					HandleOrderRsp(
						fieldInputOrder.UserID,
						fieldInputOrder.OrderLocalID,
						nSessionID,
						nFrontID,
						cVersion);
				}
			}

			break;
	#endif
		default:
			break;
	}
}

void COrderRttAnalysis::HandleOrderReq(
	const CUserIDType &UserID,
	const COrderLocalIDType &OrderLocalID,
	int nSessionID,
	int nFrontID,
	char cVersion)
{
	map<COrderRttKey, CIntList>::iterator it = m_mapOrderRtt.find(
			COrderRttKey(UserID, OrderLocalID, nSessionID, nFrontID, cVersion));
	if (it == m_mapOrderRtt.end())
	{
		CIntList mList;
		mList.push_back(CTime::TimeToLong(g_szTimeBuffer));
		m_mapOrderRtt[COrderRttKey(
				UserID,
				OrderLocalID,
				nSessionID,
				nFrontID,
				cVersion)] = mList;
	}
	else
	{
		it->second.push_back(CTime::TimeToLong(g_szTimeBuffer));
	}
}

#ifdef PRINT_DEBUG
int g_nRttPacketNum = 0;
int g_nMttPacketNum = 0;
#endif

//zhoujj slogAnalysis test
//int g_nRttPacketNum=0;

//int g_rttA[5]={0,0,0,0,0};
void COrderRttAnalysis::HandleOrderRsp(
	const CUserIDType &UserID,
	const COrderLocalIDType &OrderLocalID,
	int nSessionID,
	int nFrontID,
	char cVersion)
{
	map<COrderRttKey, CIntList>::iterator it = m_mapOrderRtt.find(
			COrderRttKey(UserID, OrderLocalID, nSessionID, nFrontID, cVersion));
	if (it == m_mapOrderRtt.end())
	{
#ifdef PRINT_DEBUG
		g_nMttPacketNum++;
		if (g_nMttPacketNum % 1000 == 0)
		{
			printf(
				"COrderRttAnalysis::HandleOrderRsp: [%d] Missing order request [%s][%s][%s]\n",
				g_nMttPacketNum,
				UserID.getValue(),
				OrderLocalID.getValue(),
				g_szTimeBuffer);
		}

#endif
	}
	else
	{
		//CIntList::iterator lit = it->second.front();
		int rtt = CTime::TimeToLong(g_szTimeBuffer) - it->second.front();
		if (rtt < 1)
		{
			rtt = 1;
		}
		else if (rtt > 4)
		{
			rtt = 4;
		}

		m_mapRttPacketNum[CRttStatsKey(nFrontID, cVersion)].m_lPacketNum[rtt]++;

		// zhoujj slogAnalysis test
		//g_rttA[rtt] ++ ;
		//g_nRttPacketNum ++ ;
		//if (g_nRttPacketNum % 10000 == 0)
		//{
		//	printf("%d %d %d %d %d\n",(int)time((time_t *)NULL), g_rttA[1], g_rttA[2], g_rttA[3], g_rttA[4]);
		//}
#ifdef PRINT_DEBUG
		printf(
			"Rsp : %d\n",
			m_mapRttPacketNum[CRttStatsKey(
					nFrontID,
					cVersion)].m_lPacketNum[rtt]);
		g_nRttPacketNum++;
		if (g_nRttPacketNum > 8000)
		{
			printf("g_nRttPacketNum:: %d \n", g_nRttPacketNum);
			for (map<int, CRttPacketStats>::iterator tit = m_mapRttPacketNum.
					 begin();
			 tit != m_mapRttPacketNum.end();
				 tit++)
			{
				printf("front %d ", tit->first);
				for (int i = 0; i <= 4; i++)
				{
					printf(
						"m_lPacketNum[%d] %d ",
						i,
						tit->second.m_lPacketNum[i]);
				}

				printf("\n");
			}
		}

#endif
		it->second.pop_front();
		if (it->second.size() == 0)
		{
			m_mapOrderRtt.erase(it);
		}

#ifdef PRINT_DEBUG
		printf(
			"request[%s][%s][%s] rtt [%d]\n",
			UserID.getValue(),
			OrderLocalID.getValue(),
			g_szTimeBuffer,
			rtt);
#endif
	}
}

void COrderRttAnalysis::putRttAnalysisToDB(void)
{
	for (map<CRttStatsKey, CRttPacketStats>::iterator rttIt =
			 m_mapRttPacketNum.begin();
	 rttIt != m_mapRttPacketNum.end();)
	{
		rttIt->second.m_lPacketNum[0] = 0;
		++rttIt;
	}

	for (map<COrderRttKey, CIntList>::iterator orderIt = m_mapOrderRtt.begin()
			 ;
	 orderIt != m_mapOrderRtt.end();)
	{
		if (orderIt->second.size() == 0)
		{
			m_mapOrderRtt.erase(orderIt++);
		}
		else
		{
			m_mapRttPacketNum[CRttStatsKey(
					orderIt->first.FrontID,
					orderIt->first.Version)].m_lPacketNum[0]++;
			++orderIt;
		}
	}

	///需要写入到数据库表  ZHOUJIANJUN
		///20080716 add by wu.yb
	static char dateBuf[9] = { 0 };
	static char timeBuf[9] = { 0 };

	time_t	timep = time(NULL);
	struct tm tm_time;
	LocalTime(&timep, &tm_time);
	sprintf(
		dateBuf,
		"%02d%02d%02d",
		tm_time.tm_year + 1900,
		tm_time.tm_mon + 1,
		tm_time.tm_mday);
	sprintf(timeBuf, "%02d:%02d:%02d", tm_time.tm_hour, tm_time.tm_min, tm_time.tm_sec);

	INT64 total;

	//float reqRate[5];
	char tmp[20];
	for (map<CRttStatsKey, CRttPacketStats>::iterator it = m_mapRttPacketNum.
			 begin();
	 it != m_mapRttPacketNum.end();
		 ++it)
	{
		total = it->second.m_lPacketNum[0] +
			it->second.m_lPacketNum[1] +
			it->second.m_lPacketNum[2] +
			it->second.m_lPacketNum[3] +
			it->second.m_lPacketNum[4];
		for (int i = 0; i < 5; i++)
		{
			sprintf(
				tmp,
				"%.2f",
				1.0 * it->second.m_lPacketNum[i] / total * 100);

			//reqRate[i]=atof(tmp);
			InsertDBSysFrontInfo(
				dateBuf,
				timeBuf,
				it->first.FrontID,
				i,
				it->second.m_lPacketNum[i],
				atof(tmp));
		}
	}
}

// 写入到表 t_SysFrontInfo
void COrderRttAnalysis::InsertDBSysFrontInfo(
	const char	*date,
	const char	*time,
	int frontId,
	int reqCond,
	INT64 reqCount,
	double	reqRate)
{
	printf(
		"运行文件 COrderRttAnalysis::InsertDBSysFrontInfo： %s 行数：%d \n",
		__FILE__,
		__LINE__);
	if (0 == g_nStartParaWrtDB)
	{
		try
		{
			connectDB();

			SACommand cmd(
						&m_sqlConnect,
						"insert into t_SysFrontInfo \
				(MonDate,MonTime,FrontId,RspCondition,ReqCount,ReqRate) values \
				(:MonDate,:MonTime,:FrontId,:RspCondition,:ReqCount,:ReqRate) ");

			cmd.Param("MonDate").setAsString() = date;
			cmd.Param("MonTime").setAsString() = time;

			char tmpFrontId[65];
			sprintf(tmpFrontId, "%d", frontId);

			//itoa(frontId,tmpFrontId,10);
			cmd.Param("FrontId").setAsString() = tmpFrontId;

			cmd.Param("RspCondition").setAsShort() = reqCond;
			cmd.Param("ReqCount").setAsLong() = reqCount;
			cmd.Param("ReqRate").setAsDouble() = reqRate;

			cmd.Execute();
			m_sqlConnect.Commit();
		}
		catch(SAException & ex)
		{
			print_errmsg(
				__FILE__,
				__FUNCTION__,
				__LINE__,
				(const char *)ex.ErrText());
		}
	}
}

///连接数据库，如果是连接着的，就不再进行连接，数据库类型仅仅支持Oracle
void COrderRttAnalysis::connectDB(void)
{
	//QQQQ
	//try {
	if (m_sqlConnect.isConnected())
	{
		return;
	}

	//}catch(SAException &ex) {}
	try
	{
		//m_con.Disconnect();
		m_sqlConnect.Rollback();
	}
	catch(SAException & ex)
	{
		print_errmsg(
			__FILE__,
			__FUNCTION__,
			__LINE__,
			(const char *)ex.ErrText());
	}
	catch(...)
	{
	}

	try
	{
		m_sqlConnect.Connect(
				getConnectStr(g_strDbIp, g_strDbPort, g_strDbName).c_str(),
				g_strDbUser.c_str(),
				g_strDbPwd.c_str(),
				SA_Oracle_Client);
	}
	catch(SAException & ex)
	{
		print_errmsg(
			__FILE__,
			__FUNCTION__,
			__LINE__,
			(const char *)ex.ErrText());
		try
		{
			m_sqlConnect.Rollback();
		}
		catch(SAException & ex)
		{
			print_errmsg(
				__FILE__,
				__FUNCTION__,
				__LINE__,
				(const char *)ex.ErrText());
		}
	}
}

string COrderRttAnalysis::getConnectStr(
	const string &ip,
	const string &port,
	const string &dbName) const
{
	return ip + ":" + port + "/" + dbName;
}

CRttInSec4Front &COrderRttAnalysis::GetOrderRttStatic(int nFront)
{
	return m_mapRttStaticsFront[nFront];
}

map<int, CRttInSec4Front> &COrderRttAnalysis::GetOrderRttMap(void)
{
	return m_mapRttStaticsFront;
}

bool COrderRttAnalysis::CheckRtnIsReady(map<int, CRttReadyMap> &mapRttForRtn)
{
	bool bResult = false;
	map<int, CRttInSec4Front>::iterator m_Iter;

	for (m_Iter = m_mapRttStaticsFront.begin();
		 m_Iter != m_mapRttStaticsFront.end();
		 m_Iter++)
	{
		//先检查预备队列
		if (m_Iter->second.mapReady4Rtn.size() > 0)
		{
			mapRttForRtn[m_Iter->first].mapRttInSec = m_Iter->second.mapReady4Rtn;
			m_Iter->second.mapReady4Rtn.clear();

			bResult = true;
		}

		//该前置没报单
		//因为“数据不需要及时性”
		if (m_Iter->second.nTict == -1)
		{
			continue;
		}
		else if (m_Iter->second.nTict > 30
			 &&	 m_Iter->second.strLastmine >= "15:00:00")	//只针对15：00：00的数据
		{
			string	strSecond = m_Iter->second.strLastmine;

			//mapRttForRtn[m_Iter->first].mapRttInSec.insert(make_pair(strSecond, &m_Iter->second.mapRttStatis[strSecond]));
			mapRttForRtn[m_Iter->first].mapRttInSec[strSecond] = &m_Iter->second.mapRttStatis[strSecond];
			m_Iter->second.nTict = -1;
			bResult = true;

			printf(
				"the front %d s last second %s has ready for rtn",
				m_Iter->first,
				strSecond.data());
		}
		else
		{
			m_Iter->second.nTict++;
		}
	}

	return bResult;
}

int COrderRttAnalysis::GetOrderRttSum(int nFrontID, char *pcErrMsg)
{
	int nCount = 0;
	int nFrontCnt = 0;
	int nFrnTmp = 0;

	string	strLastSec;
	map<int, CRttInSec4Front>::iterator m_Iter;
	for (m_Iter = m_mapRttStaticsFront.begin();
		 m_Iter != m_mapRttStaticsFront.end();
		 m_Iter++)
	{
		nFrnTmp = m_Iter->second.allStatic.nCount;

		nCount += nFrnTmp;
		if (nFrontID == m_Iter->first)
		{
			nFrontCnt = nFrnTmp;
			strLastSec = m_Iter->second.strLastmine;
		}
	}

	if (pcErrMsg)
	{
		char sSLogFileStatu[64];
		memset(sSLogFileStatu, 0, sizeof(sSLogFileStatu));

		if (g_bDecSlogDirect)
		{
			g_CSlogDec->GetSlogFileStatus(nFrontID, sSLogFileStatu);
		}
		else
		{
			g_pReactor->GetSlogFileStatus(nFrontID, sSLogFileStatu);
		}

		//打印总个数， 对应前置文件读取状态
		int nTmp = -1;
		if (m_mapSlogFileReadStatus.find(
				nFrontID) != m_mapSlogFileReadStatus.end())
		{
			nTmp = m_mapSlogFileReadStatus[nFrontID];
		}

		sprintf(
			pcErrMsg,
			"s:%d, fr:%d,%s, er:%d",
			nCount,
			nFrontID,
			sSLogFileStatu,
			nTmp);

		// 		if (m_mapSlogFileReadStatus.find(nFrontID) == m_mapSlogFileReadStatus.end())
		// 		{
		// 			sprintf(pcErrMsg, "s:%d, fr:%d,noflow.%s", nCount, nFrontID, sSLogFileStatu);
		// 		}
		// 		else
		// 		{
		// 			switch (m_mapSlogFileReadStatus[nFrontID])
		// 			{
		// 			case 1:
		// 				sTmp = "noflow";
		// 				break;
		// 			case 2:
		// 				sTmp = "f op er";
		// 				break;
		// 			case 3:
		// 				sTmp = "f op er";
		// 				break;
		// 			case 4:
		// 				sTmp = "read error";
		// 				break;
		// 			case 5:
		// 				sTmp = "he n match";
		// 				break;
		// 			case 6:
		// 				sTmp = "fre les";
		// 			default:
		// 				sTmp = "unfound er";
		// 				break;
		// 			}
		// 			sprintf(pcErrMsg, "sum:%d, %d, last sec:%s", nCount, m_mapSlogFileReadStatus[nFrontID], sSLogFileStatu);
		//		}
	}

	return nCount;
}

void CRttInSec4Front::addOneOrder(int nRtt, string sec)
{
	if (mapRttStatis.find(sec) == mapRttStatis.end())
	{
		//重置计数器
		nTict = 0;
		if (strLastmine != "")
		{
			mapReady4Rtn[strLastmine] = &mapRttStatis[strLastmine];
		}
	}

	strLastmine = sec;

	CRttInSecond &rtt = mapRttStatis[sec];

	//更新这一刻统计
	if (rtt.nMinRtt > nRtt || 0 == rtt.nMinRtt)
	{
		rtt.nMinRtt = nRtt;
	}

	if (rtt.nMaxRtt < nRtt)
	{
		rtt.nMaxRtt = nRtt;
	}

	rtt.nCount++;
	rtt.nRttSum += nRtt;

	//更新总统计
	if (allStatic.nMinRtt > nRtt || 0 == allStatic.nMinRtt)
	{
		allStatic.nMinRtt = nRtt;
	}

	if (allStatic.nMaxRtt < nRtt)
	{
		allStatic.nMaxRtt = nRtt;
	}

	allStatic.nCount++;
	allStatic.nRttSum += nRtt;

	//统计分布， 右闭区间 e.g. (0-500us]
	int i = 0;
	while (nRtt > g_nRttCutLine[i] && i < 7)
	{
		i++;
	}

	rtt.nDistribution[i]++;
	allStatic.nDistribution[i]++;
}
