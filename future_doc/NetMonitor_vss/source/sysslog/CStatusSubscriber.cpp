/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CStatusSubscriber.cpp
///@brief	实现了订阅交易流水处理消息的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
#include "CStatusSubscriber.h"
#include <FTDDataHelper.h>
#include <UFCopy.h>
#include <CDeployConfig.h>
#include "SessionProxy.h"

#define FLAG_MSG_LINE	"<br/>"

extern CSemaphore g_semThread;
extern char g_szDateBuffer[10]; 
extern char g_mFlowPath[200];
extern map<string, int> g_mapSlogFileName;

//20080717 add wu.yb
extern string g_strDbIp;
extern string g_strDbPort;
extern string g_strDbName;
extern string g_strDbUser;
extern string g_strDbPwd;

////////////////////////////
extern CFileOperation *g_fileOperation;

//@key	文件的对象ID
//@value	文件已经读取到的位置
map<string, long> g_mapFileReadSize;

///保存数据包的流地址
//modify @20120920
//extern CCachedFileFlow *g_pFlow;
extern map<CPeakKey, CFTDRtnHistoryTradePeakField>	g_mapTradePeak; // 指标历史最大值map
extern char g_mWarningPath[100];				// 告警输出文件路径
extern char g_mSystemNum[20];					// 告警输出的系统号码
extern int	g_nWarningInterval;					// 告警输出的流控时间（秒）
extern int	g_nCommonInterval;					// 通用告警及指标的输出
char g_szCurrDate[10];							// 保存消息落地时的日期
char g_szCurrTime[10];							// 保存消息落地时的时间
extern map<string, long> g_mapAttrValue;		// 历史指标值Map 如:'TRADE.PuDian.app.tkernel:TradeSize' - 25564
extern list<CAttrTeam *> g_listAttrTeam;		// 历史指标组对象list
extern list<string> g_listExcludedSystem;		// 事件消息排除的系统名列表
#ifdef PACKAGE_OUTPUT
extern CLogger	*g_pPackOutput;					// 数据包输出到文件
#endif
CMutex	g_lockMsgFile;							// 消息文件锁
extern map<string, CTimeValue>	mapWarningTime;
CStringIdMap g_mEventIdMap;						// 生成告警ID
map<CObjectAttrKey, CTimeValue> mapObjectWarningTime;
map<string, int> mapEventCount;

//////////////////////////////////////////////////////////////////////////
//fengq 20121115
extern unsigned int g_nOrderTimeWid;

//feng.q 20121130
extern CStringIdMap g_mStringIdMap;
extern map<int, int> m_mapSlogFileReadStatus;

extern bool g_bDecSlogDirect;
extern CDirectlySlogDecode	*g_CSlogDec;
extern char g_szTimeBuffer[10];
extern CSlogReactor *g_pReactor;				// 全局reactor对象指针，只能一次构造

//当前交易日
string	g_strTradeDay;

//分割线开始生效日期，从ini文件初始化，再经过db数据修改，
bool g_bChangeCutLineNextDay;

extern COrderRttAnalysis *g_OrderRttAnalysis;

CStatusSubscriber::CStatusSubscriber(void)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);

	g_bChangeCutLineNextDay = false;

	char buffer[30];
	m_pSubEnd[0] = NULL;
	for (int i = 1; i < MAX_EVENTFLOWNUM + 1; i++)
	{
		//订阅流， 当前流只处理数据
		m_pSubEnd[i] = new CStatusSubscriberSkeleton(this, i);

		//sprintf(buffer, "oracleflow%d",i);
		//m_pFws[i] = new CCachedFileFlow(buffer, g_mFlowPath,true,100,32*1024);
		// 		printf("----- CStatusSubscriber Reload Begin -----\n");
		// 		ReLoad(i);
		// 		printf("-----  CStatusSubscriber Reload End  -----\n");
	}

	// 	sprintf(buffer, "queryFlow%d",m_nFlowSeq-1);
	// 	m_pFlow = new CCachedFileFlow(buffer, g_mFlowPath,true,100,32*1024);
	// 	printf("----- CStatusSubscriber Reload Begin -----\n");
	// 	ReLoad();
	// 	printf("-----  CStatusSubscriber Reload End  -----\n");
	m_resetRun = CJudgeRun("00:00:00-00:01:00.100");
}

CStatusSubscriber::~CStatusSubscriber(void)
{
	for (int i = 0; i < MAX_EVENTFLOWNUM; i++)
	{
		delete m_pSubEnd[i];
	}
}

extern unsigned int g_nRttCutLine[8];
void CStatusSubscriber::InitTradeOrderCutLine(void)
{
	string strLastDate;
	string strCutLine;

	char strToday[16];

	if (g_strTradeDay.length() > 0)
	{
		sprintf(strToday, "%s", g_strTradeDay.data());
	}
	else
	{
		time_t timep;
		time(&timep);

		struct tm tm_time;
		LocalTime(&timep, &tm_time);
		sprintf(
			strToday,
			"%d%02d%02d",
			tm_time.tm_year + 1900,
			tm_time.tm_mon + 1,
			tm_time.tm_mday);
	}

	CFTDRtnTradeOrderRttCutLineField rtnCutLine;
	m_pkgSend.PreparePackage(
			FTD_TID_RtnTradeOrderRttCutLineTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	string strTmpCutLine;
	for (int i = 0;
			i < sizeof(g_nRttCutLine) / sizeof(unsigned int)
		&&	 ((unsigned int) -1 != g_nRttCutLine[i]);
		i++)
	{
		if (strTmpCutLine.length() > 0)
		{
			strTmpCutLine += ",";
		}

		char tmpnum[16];
		sprintf(tmpnum, "%u", g_nRttCutLine[i]);
		strTmpCutLine += tmpnum;
	}

	rtnCutLine.OrderRttCutLine = strTmpCutLine.data();

	//前置只有当天交易数据, 交易日为空
	rtnCutLine.MonDate = "";

	FTDC_ADD_FIELD(&m_pkgSend, &rtnCutLine);

	SessionProxy::Instance().NotifyAllFront(&m_pkgSend);

	printf("has send a notify to fronts at %s\n", strToday);
	fflush(stdout);
}

void CStatusSubscriber::SetCommPhaseNo(WORD wCommPhaseNo)
{
}

WORD CStatusSubscriber::GetSequenceSeries(void) //流编号
{
	return 0;
}

DWORD CStatusSubscriber::GetReceivedCount(void) //收到的包个数
{
	return 0;
}

void CStatusSubscriber::InitFlow()
{
	char buffer[30];
	m_pSubEnd[0] = NULL;
	for (int i = 1; i < MAX_EVENTFLOWNUM + 1; i++)
	{
		//订阅流， 当前流只处理数据
		//m_pSubEnd[i] = new CStatusSubscriberSkeleton(this, i);
		//sprintf(buffer, "oracleflow%d",i);
		//m_pFws[i] = new CCachedFileFlow(buffer, g_mFlowPath,true,100,32*1024);
		printf("----- CStatusSubscriber Reload Begin -----\n");
		ReLoad(i);
		printf("-----  CStatusSubscriber Reload End  -----\n");
	}
}

void CStatusSubscriber::ReLoad(int nFlowSeq)
{
	CFlowReader eventFlowReader;
	eventFlowReader.AttachFlow(m_pSubEnd[nFlowSeq]->m_pFlow, 0);

	CFTDCPackage *pFTDCPackage = new CFTDCPackage;
	pFTDCPackage->ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	for (;;)
	{
		pFTDCPackage->Allocate(FTDC_PACKAGE_MAX_SIZE + FTDCHLEN);
		if (!eventFlowReader.GetNext(pFTDCPackage))
		{
			break;
		}

		switch (pFTDCPackage->GetTID())
		{
			case FTD_TID_RtnSyslogInfoTopic:
				OnRtnSyslogInfoTopic(pFTDCPackage);
				break;
			default:
				break;
		}
	}

	//	connectDB();
}

void CStatusSubscriber::HandleMessage(CFTDCPackage *pFTDCPackage)
{
#ifdef PACKAGE_OUTPUT
	pFTDCPackage->OutputHeader(g_pPackOutput);
	FTDC_DEBUG_BODY(pFTDCPackage->GetTID(), pFTDCPackage, g_pPackOutput);
#endif
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
	printf(
		"\tCStatusSubscriber::HandleMessage 包的TID %x\n",
		pFTDCPackage->GetTID());
#endif
	switch (pFTDCPackage->GetTID())
	{
		case FTD_TID_RtnSyslogInfoTopic:
			OnRtnSyslogInfoTopic(pFTDCPackage);
			break;
		default:
			break;
	}

	int nFlowSeries = pFTDCPackage->GetFTDCHeader()->SequenceSeries;

	if (m_pSubEnd[nFlowSeries])
	{
		pFTDCPackage->Push(FTDCHLEN);
		m_pSubEnd[nFlowSeries]->m_pFlow->Append(
				pFTDCPackage->Address(),
				pFTDCPackage->Length());
	}

	//m_pFlow->Append(pFTDCPackage->Address(), pFTDCPackage->Length());
}

void CStatusSubscriber::OnRtnSyslogInfoTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDSysFileAccessInfoField	fieldAccessInfo;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldAccessInfo))
	{
		if ((long)fieldAccessInfo.FileSize.getValue()
				< g_mapFileReadSize[string(
				fieldAccessInfo.ObjectID.getValue())])
		{
			//////////////////////////////////////////////////////////////////////////
			//change by feng.q 20121204，应对分流情况
			QWORD nEnd = (QWORD) fieldAccessInfo.FileSize.getValue();
			printf(
				"There is a pre block at %lld, when file end is %lld \n",
				nEnd,
				g_mapFileReadSize[string(
						fieldAccessInfo.ObjectID.getValue())]);

			//return;
		}

		g_mapFileReadSize[string(fieldAccessInfo.ObjectID.getValue())] = (long)fieldAccessInfo.FileSize.getValue();
	}

	CFTDRtnSyslogInfoField	fieldSyslogInfo;
	FOREACH_FIELD(pFTDCPackage, CFTDRtnSyslogInfoField, fieldSyslogInfo)
	{
		g_fileOperation->addFileContent(
				fieldSyslogInfo.AttrType.getValue(),
				fieldSyslogInfo.FileContent.getValue(),
				fieldSyslogInfo.ContLen.getValue());
	}

	if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST)
	{
		g_fileOperation->WriteToFile(
				fieldSyslogInfo.AttrType.getValue(),
				fieldAccessInfo.FileSize.getValue());

		//////////////////////////////////////////////////////////////////////////
		//add by feng.q 20121130
		if (g_bDecSlogDirect)
		{
			//g_CSlogDec->RecNewSlogPackeg(fieldSyslogInfo.AttrType.getValue(), fieldAccessInfo.FileSize.getValue());
			QWORD nFileEnd = g_fileOperation->m_mapFileValidEnd[fieldSyslogInfo.
				AttrType.getValue()].nValidEnd;
			g_CSlogDec->RecNewSlogPackeg(
					fieldSyslogInfo.AttrType.getValue(),
					nFileEnd);
		}

		//////////////////////////////////////////////////////////////////////////
	}
}

FILE *CFileOperation::initFileHandle(const char *fileName)
{
	char buffer[200];
	sprintf(buffer, "%s/%s", g_mFlowPath, fileName);

	//////////////////////////////////////////////////////////////////////////
	//change by feng.q 初始化的时候删除已有文件内容
	FILE *fp = NULL;
	fp = fopen(buffer, "wb+");

	//     FILE *fp = fopen(buffer, "a");
	//     if(!fp)
	//     {
	//         printf("告警！！创建或打开文件 %s 失败！\n",buffer);
	//         exit(-1);
	//     }
	//     else
	//     {
	//         fclose(fp);
	//     }
	//
	//     fp = fopen(buffer, "rb+");
	if (!fp)
	{
		printf(
			"CFileOperation::initFileHandle fopen file error %s, exit\n",
			buffer);
		exit(-1);
	}
	else
	{
		//通过关闭文件名缓冲来禁止CSlogReactor里面解析slog
		if (!g_bDecSlogDirect)
		{
			g_mapSlogFileName[string(fileName)] = 1;
		}
	}

	return fp;
}

void CFileValidContent::AddNewFileContent(QWORD nContentEnd, int nContentSize)
{
	if (nContentEnd < nContentSize)
	{
		printf(
			"Error too much, file content over flow file end con:%lld, end:%lld",
			nContentSize,
			nContentEnd);
		return;
	}

	QWORD nConStart = nContentEnd - nContentSize;

	if (mapValidContent.size() == 0)
	{
		mapValidContent[nConStart] = nContentSize - 1;
		return;
	}

	map<QWORD, QWORD>::reverse_iterator m_rIter = mapValidContent.rbegin();

	while (m_rIter != mapValidContent.rend())
	{
		QWORD nBlockStart = m_rIter->first;

		if (nContentEnd <= nBlockStart)
		{
			m_rIter++;
			continue;
		}

		QWORD nKey = 0;

		//可以和前一个合并
		if (m_rIter->second + 1 == nConStart)
		{
			//修改前一个value， 即block size
			m_rIter->second = nContentEnd - 1;
			nKey = m_rIter->first;
		}
		else if (m_rIter->second + 1 < nConStart)
		{
			mapValidContent[nConStart] = nContentEnd - 1;
			nKey = nConStart;
		}
		else
		{
			//error
			printf("Error ! block cross\n");
			printf(
				"the pre block [%lld,%lld], the cur data [%lld, %lld]\n",
				m_rIter->first,
				m_rIter->second,
				nConStart,
				nContentEnd);
			return;
		}

		//检查后一个block
		map<QWORD, QWORD>::iterator m_Iter = mapValidContent.find(
				nContentEnd + 1);
		if (m_Iter != mapValidContent.end())
		{
			//如果能和后一个block合并，则删除后一个block
			mapValidContent[nKey] = m_Iter->second;
			mapValidContent.erase(m_Iter);
		}

		break;
	}

	////任何情况下有效长度都是第一个block
	//modify, 取最后一个的end地址
	nValidEnd = mapValidContent.rbegin()->second;
}

CStatusSubscriberSkeleton::CStatusSubscriberSkeleton(
	CStatusSubscriber *pParantHandler,
	int nFlowSeq) :
	m_nSeries(nFlowSeq),
	m_pStatusSubHandler(pParantHandler)
{
	char buffer[30];

	sprintf(buffer, "slogflow%d", nFlowSeq - 1);
	m_pFlow = new CCachedFileFlow(buffer, g_mFlowPath, true, 100, 32 * 1024);
}

CStatusSubscriberSkeleton::~CStatusSubscriberSkeleton(void)
{
	delete m_pFlow;
}

void CStatusSubscriberSkeleton::SetCommPhaseNo(WORD wCommPhaseNo)
{
}

WORD CStatusSubscriberSkeleton::GetSequenceSeries(void) //流编号
{
	return m_nSeries;
}

DWORD CStatusSubscriberSkeleton::GetReceivedCount(void) //收到的包个数
{
	if (NULL == m_pFlow)
	{
		return 0;
	}

#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
	printf("\t Flow count %d\n", m_pFlow->GetCount());
#endif
	return m_pFlow->GetCount();
}

void CStatusSubscriberSkeleton::HandleMessage(CFTDCPackage *pFTDCPackage)
{
	if (m_pStatusSubHandler)
	{
		m_pStatusSubHandler->HandleMessage(pFTDCPackage);
	}
}

void CLatestOrderOfParticipation::AppendAnewRecord(
	CFTDRtnParticTradeOrderStatesField	*pRtn)
{
	if (NULL == pRtn)
	{
		return;
	}

	//历史数据
	if (strLastDate > pRtn->MonDate.getValue()
	&&	strLastTime > pRtn->MonTime.getValue())
	{
		return;
	}

	string strTimeLine = GetTimeLine(pRtn->MonTime.getValue());

	if (mp_sField.find(strTimeLine) == mp_sField.end())
	{
		CFTDRtnParticTradeOrderStatesField	&sField = mp_sField[strTimeLine];

		memset(&sField, 0, sizeof(sField));

		CopyRtnParticTradeOrderStatesEntity(&sField, pRtn);

		sField.MonTime = strTimeLine.data();
		sField.StaticWidth = nTimeWidth;
		sField.OrderCntMax = pRtn->OrderCount;
		sField.CancleCntMax = pRtn->CancleCount;
		sField.QueryCntMax = pRtn->QueryCount;
		sField.TradeCntMax = pRtn->TradeCount;
		sField.TradeMoneyMax = pRtn->TradeMoney;

		setShdInsert.insert(strTimeLine);
	}
	else
	{
		CFTDRtnParticTradeOrderStatesField	&sField = mp_sField[strTimeLine];
		if (setShdInsert.find(strTimeLine) == setShdInsert.end())
		{
			setSdUpdate.insert(strTimeLine);
		}

		sField.OrderCount += pRtn->OrderCount;
		sField.CancleCount += pRtn->CancleCount;
		sField.QueryCount += pRtn->QueryCount;
		sField.TradeCount += pRtn->TradeCount;
		sField.TradeMoney += pRtn->TradeMoney;

		//更新最大的, 统计数据颗粒度是秒
		if (sField.OrderCntMax < pRtn->OrderCount)
		{
			sField.OrderCntMax = pRtn->OrderCount;
		}

		if (sField.CancleCntMax < pRtn->CancleCount)
		{
			sField.CancleCntMax = pRtn->CancleCount;
		}

		if (sField.QueryCntMax < pRtn->QueryCount)
		{
			sField.QueryCntMax = pRtn->QueryCount;
		}

		if (sField.TradeCntMax < pRtn->TradeCount)
		{
			sField.TradeCntMax = pRtn->TradeCount;
		}

		if (sField.TradeMoneyMax < pRtn->TradeMoney)
		{
			sField.TradeMoneyMax = pRtn->TradeMoney;
		}
	}
}

string CLatestOrderOfParticipation::GetTimeLine(string strCurTime)
{
	CTime stTimeNow(strCurTime.data());

	long lTmNw = stTimeNow.ToLong();

	lTmNw = (lTmNw % nTimeWidth);

	stTimeNow - lTmNw;
	return stTimeNow.ToString();
}


//////////////////////////////////////////////////////////////////////////

//add by feng.q 20121130
void CDirectlySlogDecode::RecNewSlogPackeg(
	const char	*fileName,
	const QWORD endSize)
{
	//初始化文件描述符
	if (m_mapSlogDescript.find(fileName) == m_mapSlogDescript.end())
	{
		m_mapSlogDescript[fileName] = CSlogDescript(
				fileName,
				g_mStringIdMap.getStringId(fileName));
	}

	CSlogDescript &sDescrip = m_mapSlogDescript[fileName];

	if (sDescrip.m_fpSlog == NULL)
	{
		sDescrip.m_fpSlog = fopen(sDescrip.m_strSlogFileName.c_str(), "rb");
		if (sDescrip.m_fpSlog == NULL)
		{
			printf(
				"open file [%s] error[%d]\n",
				sDescrip.m_strSlogFileName.c_str(),
				errno);
			m_mapSlogFileReadStatus[sDescrip.m_nFrontID] = 1;

			return;
		}

		if (fsetpos(sDescrip.m_fpSlog, &(sDescrip.m_fposLog)) != 0)
		{
			printf(
				"fsetpos file [%s] error[%d]\n",
				sDescrip.m_strSlogFileName.c_str(),
				errno);
			sDescrip.m_fpSlog = NULL;
			fclose(sDescrip.m_fpSlog);
			return;
		}
	}

	ReadOnePackeg(sDescrip, endSize);
}

void CDirectlySlogDecode::ReadOnePackeg(
	CSlogDescript &sDescrip,
	const QWORD endSize)
{
	static int new_channel_log_header_len = sizeof(TNewChannelLogHeader);
	static int channel_log_header_len = sizeof(TChannelLogHeader);

	//文件读取有致命错误，不宜继续读取
	if (sDescrip.m_cWrongFlag != 0)
	{
		return;
	}

	QWORD nFileDecEnd = FPOS_GET(sDescrip.m_fposLog);

	//新获得的文件内容
	QWORD nContectAvailable = endSize - nFileDecEnd;

	while (endSize > nFileDecEnd)
	{
		int nReadBytes = 0;

		//packeg header
		if (sDescrip.m_nReadLen != 1)
		{
			if (sDescrip.newFileFlag)
			{
				if (nContectAvailable < new_channel_log_header_len)
				{
					return;
				}
				else
				{
					nReadBytes = fread(
							((char *) &(sDescrip.m_header)),
							1,
							new_channel_log_header_len,
							sDescrip.m_fpSlog);

					if (nReadBytes != new_channel_log_header_len)
					{
						sDescrip.m_cWrongFlag = 1;
						m_mapSlogFileReadStatus[sDescrip.m_nFrontID] = 6;
						return;
					}
				}
			}
			else
			{
				if (nContectAvailable < channel_log_header_len)
				{
					return;
				}
				else
				{
					nReadBytes = fread(
							((char *) &(sDescrip.m_header)),
							1,
							channel_log_header_len,
							sDescrip.m_fpSlog);

					if (nReadBytes != channel_log_header_len)
					{
						sDescrip.m_cWrongFlag = 1;
						m_mapSlogFileReadStatus[sDescrip.m_nFrontID] = 6;
						return;
					}
				}
			}

			sDescrip.m_header.ChangeEndian();

			//标记packeg header已读
			sDescrip.m_nReadLen = 1;
			nFileDecEnd += nReadBytes;
			nContectAvailable -= nReadBytes;
			FPOS_SET(sDescrip.m_fposLog, nFileDecEnd);
		}

		//检查packeg head 合法性
		if (sDescrip.m_header.wLength >= MAX_SLOG_REC_LEN)
		{
			sDescrip.m_cWrongFlag = 1;
			printf(
				"Fatal Error in read file [%s], TChannelLogHeader.wLength [%d] exceed max value in file size[%d]\n",
				sDescrip.m_strSlogFileName.c_str(),
				sDescrip.m_header.wLength,
				nFileDecEnd);

			m_mapSlogFileReadStatus[sDescrip.m_nFrontID] = 4;
			return;
		}

		//packet body
		if (nContectAvailable < sDescrip.m_header.wLength)
		{
			return;
		}

		nReadBytes = fread(
				sDescrip.m_buffer,
				1,
				sDescrip.m_header.wLength,
				sDescrip.m_fpSlog);

		if (nReadBytes != sDescrip.m_header.wLength)
		{
			sDescrip.m_cWrongFlag = 1;
			m_mapSlogFileReadStatus[sDescrip.m_nFrontID] = 6;
			return;
		}

		//标记packet body已读
		sDescrip.m_nReadLen = 0;
		nFileDecEnd += nReadBytes;
		nContectAvailable -= nReadBytes;
		FPOS_SET(sDescrip.m_fposLog, nFileDecEnd);

		//解析packet
		HandleOnePackeg(sDescrip);
	}
}

bool CDirectlySlogDecode::HandleOnePackeg(CSlogDescript &sDescrip)
{
	time_t tCurrTime = sDescrip.m_header.dwTime;
	struct tm tm_time;
	LocalTime(&tCurrTime, &tm_time);
	g_semThread.Lock();
	strftime(
		g_szTimeBuffer,
		sizeof(g_szTimeBuffer),
		"%H:%M:%S",
		&tm_time);
	sprintf(g_szDateBuffer,"%04d%02d%02d",tm_time.tm_year + 1900,
		tm_time.tm_mon + 1,tm_time.tm_mday);
	g_semThread.UnLock();
	if (sDescrip.m_tLastTime != tCurrTime)
	{
		sDescrip.m_tLastTime = tCurrTime;
	}

	sDescrip.m_header.dwId = (sDescrip.m_nFrontID << 16) + sDescrip.m_header.dwId;

	CSlogConnection *pSlogConnection = NULL;

	if (sDescrip.m_header.wType == CLRT_CONNECTED)
	{
		pSlogConnection = GetSlogConnection(sDescrip);
		if (pSlogConnection != NULL)
		{
			pSlogConnection->OnDupSocketID(g_szTimeBuffer);
			DelSlogConnection(sDescrip);
		}

		pSlogConnection = CreateSlogConnection(sDescrip);
	}
	else
	{
		pSlogConnection = GetSlogConnection(sDescrip);
	}

	if (pSlogConnection == NULL)
	{
		return true;
	}

	switch (sDescrip.m_header.wType)
	{
		case CLRT_CONNECTED:
			pSlogConnection->OnConnected(g_szTimeBuffer);
			break;
		case CLRT_READ:
			pSlogConnection->OnChannelRead(
					g_szTimeBuffer,
					sDescrip.m_buffer,
					sDescrip.m_header.wLength);
			break;
		case CLRT_WRITE:
			pSlogConnection->OnChannelWrite(
					g_szTimeBuffer,
					sDescrip.m_buffer,
					sDescrip.m_header.wLength);
			break;
		case CLRT_DISCONNECT:
			pSlogConnection->OnDisconnected(g_szTimeBuffer);
			DelSlogConnection(sDescrip);
			break;
		case CLRT_READ_ERROR:
			pSlogConnection->OnReadError(g_szTimeBuffer);
			break;
		case CLRT_WRITE_ERROR:
			pSlogConnection->OnWriteError(g_szTimeBuffer);
			break;
		case CLRT_DISCONNECTED_READ:
			pSlogConnection->OnDisconnectedRead(g_szTimeBuffer);
			break;
		case CLRT_DISCONNECTED_WRITE:
			pSlogConnection->OnDisconnectedWrite(g_szTimeBuffer);
			break;
		default:
			printf("header type error :[%d]\n", sDescrip.m_header.wType);
			return false;
	}

	return true;
}

CSlogConnection *CDirectlySlogDecode::CreateSlogConnection(
	CSlogDescript &sDescrip)
{
	int nID = sDescrip.m_header.dwId;
	const char	*pszIPAddress = sDescrip.m_buffer;
	int nFrontID = sDescrip.m_nFrontID;
	int nFileID = sDescrip.m_nFileID;
	char cVersion = sDescrip.m_cVersion;

	if (sDescrip.m_strDesiredIpAddress.compare("all") == 0
	||	sDescrip.m_strDesiredIpAddress.compare(pszIPAddress) == 0)
	{
		CSlogConnection *pSlogConnection = new CSlogConnection(
				nID,
				pszIPAddress,
				nFrontID,
				nFileID,
				cVersion);
		if (!pSlogConnection->CreateSession(
				g_pReactor,
			sDescrip.m_strSlogFileName.c_str()))
		{
			delete pSlogConnection;
			return NULL;
		}

		sDescrip.m_mapSlogConnection.Insert(nID, pSlogConnection);
		return pSlogConnection;
	}

	return NULL;
}

CSlogConnection *CDirectlySlogDecode::GetSlogConnection(CSlogDescript &sDescrip)
{
	int nID = sDescrip.m_header.dwId;
	CSlogConnection **pFind = sDescrip.m_mapSlogConnection.Find(nID);
	return (pFind == NULL) ? NULL : *pFind;
}

bool CDirectlySlogDecode::DelSlogConnection(CSlogDescript &sDescrip)
{
	int nID = sDescrip.m_header.dwId;
	CSlogConnection **pFind = sDescrip.m_mapSlogConnection.Find(nID);
	if (pFind == NULL)
	{
		return false;
	}

	delete *pFind;
	sDescrip.m_mapSlogConnection.Erase(nID);
	return true;
}

void CDirectlySlogDecode::GetSlogFileStatus(int nFrontID, char *pLogBuf)
{
	map<string, CSlogDescript>::iterator m_Iter;

	for (m_Iter = m_mapSlogDescript.begin();
		 m_Iter != m_mapSlogDescript.end();
		 m_Iter++)
	{
		if (m_Iter->second.m_nFrontID == nFrontID
		&&	m_Iter->second.m_fpSlog
		&&	pLogBuf)
		{
			QWORD mFposLong = FPOS_GET(m_Iter->second.m_fposLog);
			char currtime[16];
			time_t lTime = m_Iter->second.m_tLastTime;
			struct tm tm_time;
			LocalTime(&lTime, &tm_time);
			strftime(
				currtime,
				sizeof(currtime),
				"%H:%M:%S",
				&tm_time);

			sprintf(
				pLogBuf,
				"pos:%lld, last:%s, flag:%d",
				mFposLong,
				currtime,
				m_Iter->second.m_cWrongFlag);
		}
	}
}
