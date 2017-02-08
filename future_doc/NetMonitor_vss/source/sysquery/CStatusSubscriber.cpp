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
#include "ScopedLock.h"

#define FLAG_MSG_LINE	"<br/>"

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

//报单响应分布，切割线
unsigned int g_nRttCutLine[8];

//分割线开始生效日期，从ini文件初始化，再经过db数据修改，
bool g_bChangeCutLineNextDay;

extern COrderRttAnalysis *g_OrderRttAnalysis;

//////////////////////////////////////////////////////////////////////////
extern int	g_nStartParaWrtDB;

void writeMsg(char *pszFile, char *pszBuf)
{
	g_lockMsgFile.Lock();

	FILE *fp = fopen(pszFile, "a");
	if (fp == NULL)
	{
		printf("In function writeMsg: open file %s failed\n", pszFile);
		return;
	}

	fwrite(pszBuf, strlen(pszBuf), 1, fp);
	fflush(fp);
	fclose(fp);
	g_lockMsgFile.UnLock();
}

void writeEventbySubject(
	CFTDRtnWarningEventField warningInfo,
	char *pszEventID,
	char *pszSubject,
	char *pszFilename,
	time_t	now,
	int iterval)
{
	if (mapObjectWarningTime[CObjectAttrKey(
			pszEventID,
		pszSubject)].m_nSendTime <= now -
		iterval)
	{
		mapObjectWarningTime[CObjectAttrKey(
				pszEventID,
				pszSubject)].m_nSendTime = now;

		char szStringID[256];
		char buffer[1024];
		int count = mapEventCount.find(pszEventID) == mapEventCount.end()
			? 1 : mapEventCount[pszEventID];
		sprintf(szStringID, "%s:%s", pszEventID, pszSubject);

		UINT64	seq = now * 1000000 + g_mEventIdMap.getStringId(szStringID);
		sprintf(
			buffer,
			"<Message MessageId=\"%llu\" SubjectId=\"%s\" Level=\"9\" DumpDate=\"%s\" DumpTime=\"%s\" Content=\"%s %s %s[%s] [%s]%s(已发生%d次)\" MaxRetry=\"3\" RetrySpan=\"300\" SenderId=\"%s\" />\r\n",
			seq,
			pszSubject,
			g_szCurrDate,
			g_szCurrTime,
			warningInfo.MonDate.getValue(),
			warningInfo.MonTime.getValue(),
			warningInfo.EventName.getValue(),
			warningInfo.WarningLevel.getValue(),
			warningInfo.ObjectID.getValue(),
			mapWarningTime[warningInfo.EventName.getValue()].m_warningInfo.c_str(),
			count,
			g_mSystemNum);
		writeMsg(pszFilename, buffer);
	}
}

void writeWarningEvent(CFTDRtnWarningEventField warningInfo)
{
	time_t	now = time((time_t *)NULL);
	struct tm tm_time;
	LocalTime(&now, &tm_time);

	///20100127 by zhou.jj 在周末和平时的晚六点后至早七点之间不写告警信息
	if (tm_time.tm_hour > 17 || tm_time.tm_hour < 7 || tm_time.tm_wday == 0 || tm_time.tm_wday == 6)
	{
		return;
	}

	///共用消息部分
	char fileName[128];
	sprintf(
		fileName,
		"%s%04d%02d%02d.im",
		g_mWarningPath,
		(1900 + tm_time.tm_year),
		(1 + tm_time.tm_mon),
		tm_time.tm_mday);
	sprintf(
		g_szCurrDate,
		"%04d%02d%02d",
		(1900 + tm_time.tm_year),
		(1 + tm_time.tm_mon),
		tm_time.tm_mday);
	sprintf(g_szCurrTime, "%02d:%02d:%02d", tm_time.tm_hour, tm_time.tm_min, tm_time.tm_sec);

	char szBuf[256];
	sprintf(
		szBuf,
		"%s:%s",
		(char *)warningInfo.ObjectID.getValue(),
		(char *)warningInfo.EventName.getValue());

	char szSubject[256];

	// Add by Henchi, 20100202
		///获取事件主题信息，以判断其输出间隔
	if (strlen(
			mapWarningTime[warningInfo.EventName.getValue()
			].m_msgSubjectId.c_str()) > 0)
	{
		///事件主题信息非空，是否需发送公共及事件消息
		strncpy(
			szSubject,
			mapWarningTime[warningInfo.EventName.getValue()].m_msgSubjectId.c_str(),
			255);
		writeEventbySubject(
			warningInfo,
			szBuf,
			szSubject,
			fileName,
			now,
			g_nCommonInterval);
	}

	///发送业务系统级事件消息
	strncpy(szSubject, (char *)warningInfo.ObjectID.getValue(), 255);
	strtok(szSubject, ".");
	writeEventbySubject(
		warningInfo,
		szBuf,
		szSubject,
		fileName,
		now,
		g_nWarningInterval);
	return;
}

void writeObjectAttr(CAttrTeam *pItem)
{
	time_t	now = time((time_t *)NULL);
	struct tm tm_time;
	LocalTime(&now, &tm_time);
	char datetime[18];
	sprintf(
		datetime,
		"%04d%02d%02d %02d:%02d:%02d",
		(1900 + tm_time.tm_year),
		(1 + tm_time.tm_mon),
		tm_time.tm_mday,
		tm_time.tm_hour,
		tm_time.tm_min,
		tm_time.tm_sec);
	sprintf(
		g_szCurrDate,
		"%04d%02d%02d",
		(1900 + tm_time.tm_year),
		(1 + tm_time.tm_mon),
		tm_time.tm_mday);
	sprintf(g_szCurrTime, "%02d:%02d:%02d", tm_time.tm_hour, tm_time.tm_min, tm_time.tm_sec);

	char fileName[128];
	sprintf(
		fileName,
		"%s%04d%02d%02d.im",
		g_mWarningPath,
		(1900 + tm_time.tm_year),
		(1 + tm_time.tm_mon),
		tm_time.tm_mday);

	UINT64	seq = now * 1000000 + g_mEventIdMap.getStringId(
			pItem->m_sAttrTeamName.c_str()) * 1000 + mapWarningTime[pItem->m_sAttrTeamName].m_nOrderId;

	char attrInfo[1024] = "";
	list<CAttrItem *> &attrList = pItem->m_AttrList;
	sprintf(attrInfo, "%s%s", pItem->m_sComment.c_str(), FLAG_MSG_LINE);
	for (list < CAttrItem * >::iterator it = attrList.begin();
		 it != attrList.end();
		 it++)
	{
		sprintf(
			attrInfo,
			"%s[%s]%ld%s",
			attrInfo,
			(*it)->m_Comment.c_str(),
			g_mapAttrValue[(*it)->m_AttrID],
			FLAG_MSG_LINE);
	}

	char buffer[1024];
	sprintf(
		buffer,
		"<Message MessageId=\"%llu\" SubjectId=\"%s\" Level=\"9\" DumpDate=\"%s\" DumpTime=\"%s\" Content=\"%s %s\" MaxRetry=\"3\" RetrySpan=\"300\" SenderId=\"%s\" />\r\n",
		seq,
		mapWarningTime[pItem->m_sAttrTeamName].m_msgSubjectId.c_str(),
		g_szCurrDate,
		g_szCurrTime,
		datetime,
		attrInfo,
		g_mSystemNum);

	writeMsg(fileName, buffer);
	return;
}

CStatusSubscriber::CStatusSubscriber(void) :
	m_sqlConnect(NULL)							//,m_pFlow(NULL)
	//,m_nFlowSeq(0)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	mbPeakFlag = false;
	m_bTryConnectDbFlag = true;

	//初始化时间分布切割线
	for (int i = 0; i < 8; i++)
	{
		g_nRttCutLine[i] = (unsigned int) -1;
	}

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
	m_bSepsDbFlag = true;
	m_resetRun = CJudgeRun("00:00:00-00:01:00.100");

	m_nLocID = 0;
	m_nRemID = 0;

	m_hander.SetOperateMaster("CStatusSubscriber",NULL);
	m_hander.Open(g_strDbIp, g_strDbPort, g_strDbName, g_strDbUser, g_strDbPwd);

	//added by Lee 2014.11.11
	//生成writeDB线程变量，设置相应参数，并启动 
	m_writeDBTh = CWriteDBThread();
	m_writeDBTh.setSubscriber(this);
	m_writeDBTh.Create();

}

CStatusSubscriber::~CStatusSubscriber(void)
{
	for (int i = 0; i < MAX_EVENTFLOWNUM; i++)
	{
		delete m_pSubEnd[i];
	}

	delete m_sqlConnect;
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

void CStatusSubscriber::InitDBParam(
	const char	*pStrDate,
	const char	*pStrUser,
	const char	*pStrCutLine)
{
	if (!connectDB())
	{
		return;
	}

	InsertNewCutLine2DB(pStrDate, pStrUser, pStrCutLine);
	try
	{
		ScopeLock<CMutex> scopelock(m_sqlMutex);
		SACommand cmd;
		cmd.setConnection(m_sqlConnect);
		cmd.setCommandText(
				"select rtrim(a.participantid) as pid, rtrim(a.userid) as usid, rtrim(a.mondate) as md, rtrim(a.montime) as mt, a.StaticWidth from t_syspartictradeorderstates a,  \
						   (select participantid,userid, MAX( CAST( CONCAT(mondate, REPLACE(montime, ':', '')) AS NUMBER)) AS TMSTR  \
			from t_syspartictradeorderstates  \
			GROUP BY participantid,userid) b  \
		where CAST( CONCAT(a.mondate, REPLACE(a.montime, ':', '')) AS NUMBER) = b.tmstr and a.participantid = b.participantid and a.userid = b.userid");

		//cmd.setCommandText("select * from t_syspartictradeorderstates");
		cmd.Execute();
		while (cmd.FetchNext())
		{
			string	strP = (const char *)cmd.Field("pid").asString();
			string	strU = (const char *)cmd.Field("usid").asString();
			string	strKey = strP + ":" + strU;

			CLatestOrderOfParticipation &latParOrd = m_mapPatMemOrderCnt[
				strKey];

			latParOrd.strPart = strP;
			latParOrd.strUser = strU;

			latParOrd.strLastDate = cmd.Field("md").asString();
			latParOrd.strLastTime = cmd.Field("mt").asString();

			int nWidth = cmd.Field("StaticWidth").asLong();

			CTime stm(latParOrd.strLastTime.data());
			stm = stm + nWidth;

			latParOrd.strLastTime = stm.ToString();

			latParOrd.bNedInsrtARec = true;
			latParOrd.bSafe = false;
			latParOrd.nTimeWidth = g_nOrderTimeWid;

			//memset(&latParOrd.sField, 0, sizeof(latParOrd.sField));
		}
	}

	catch(SAException & ex)
	{
		print_errmsg(
			__FILE__,
			__FUNCTION__,
			__LINE__,
			(const char *)ex.ErrText());
	}

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

	// 	sprintf(buffer, "queryFlow%d",m_nFlowSeq-1);
	// 	m_pFlow = new CCachedFileFlow(buffer, g_mFlowPath,true,100,32*1024);
	// 	printf("----- CStatusSubscriber Reload Begin -----\n");
	// 	ReLoad();
	// 	printf("-----  CStatusSubscriber Reload End  -----\n");
	// 	m_bSepsDbFlag = true;
	// 	m_resetRun = CJudgeRun("00:00:00-00:01:00.100");
	//
	// 	m_nLocID = 0;
	// 	m_nRemID = 0;
}

void CStatusSubscriber::GetTradePeakFromDB(void)
{
	// 从数据库表 t_SysHistoryTradePeak 取出所有数据,放到g_mapTradePeak, 20081216
	// ......
	if (mbPeakFlag)
	{
		return;
	}

	try
	{
		ScopeLock<CMutex> scopelock(m_sqlMutex);
		CFTDRtnHistoryTradePeakField peakField;
		SACommand cmd;
		cmd.setConnection(m_sqlConnect);
		cmd.setCommandText("select * from t_SysHistoryTradePeak");
		cmd.Execute();
		while (cmd.FetchNext())
		{
			peakField.ObjectID = cmd.Field("ObjectID").asString();
			peakField.AttrType = cmd.Field("AttrType").asString();
			peakField.AttrValue = cmd.Field("AttrValue").asNumeric();
			peakField.MonDate = cmd.Field("MonDate").asString();
			peakField.MonTime = cmd.Field("MonTime").asString();
			peakField.RltAttrType = cmd.Field("RltAttrType").asString();
			peakField.RltAttrValue = cmd.Field("RltAttrValue").asNumeric();
			peakField.MaxAttrValue = cmd.Field("MaxAttrValue").asNumeric();
			peakField.MaxMonDate = cmd.Field("MaxMonDate").asString();
			peakField.MaxMonTime = cmd.Field("MaxMonTime").asString();
			peakField.MaxRltAttrValue = cmd.Field("MaxRltAttrValue").asNumeric();
			peakField.OldAttrValue = cmd.Field("OldAttrValue").asNumeric();
			peakField.OldMonDate = cmd.Field("OldMonDate").asString();
			peakField.OldMonTime = cmd.Field("OldMonTime").asString();
			peakField.OldRltAttrValue = cmd.Field("OldRltAttrValue").asNumeric();

			peakField.ObjectID.trimRight();
			peakField.AttrType.trimRight();
			peakField.MonDate.trimRight();
			peakField.MonTime.trimRight();
			peakField.RltAttrType.trimRight();
			peakField.MaxMonDate.trimRight();
			peakField.MaxMonTime.trimRight();
			peakField.OldMonDate.trimRight();
			peakField.OldMonTime.trimRight();
			g_mapTradePeak[CPeakKey(
					(char *)peakField.ObjectID.getValue(),
					(char *)peakField.AttrType.getValue(),
					(char *)peakField.RltAttrType.getValue())] = peakField;

			//g_mapTradePeak.insert(make_pair(CPeakKey((char *)peakField.ObjectID.getValue(),
			//	(char *)peakField.AttrType.getValue(),(char *)peakField.RltAttrType.getValue()), peakField));
		}

		// 把从数据库取出的数据发送到已经连接的前置
		map<CPeakKey, CFTDRtnHistoryTradePeakField>::iterator mit;
		for (mit = g_mapTradePeak.begin(); mit != g_mapTradePeak.end(); mit++)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnHistoryTradePeakTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &(mit->second));
			SessionProxy::Instance().NotifyAllFront(&m_pkgSend);
		}

		mbPeakFlag = true;
	}
	catch(SAException & ex)
	{
		print_errmsg(
			__FILE__,
			__FUNCTION__,
			__LINE__,
			(const char *)ex.ErrText());
		mbPeakFlag = false;
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
	#if 0
		case FTD_TID_RtnNetObjectAttrTopic:
			OnRtnNetObjectAttrTopic(pFTDCPackage);
			break;
	#endif
		case FTD_TID_RtnWarningEventTopic:
			OnRtnWarningEventTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnHistoryObjectAttrTopic:
			OnRtnHistoryObjectAttrTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnTopCpuInfoTopic:
			OnRtnTopCpuInfoTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnTopMemInfoTopic:
			OnRtnTopMemInfoTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnNetworkInfoTopic:
			OnRtnNetworkInfoTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnHistoryTradePeakTopic:
			OnRtnHistoryTradePeakTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnDBQueryTopic:
			OnRtnDBQueryTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnNetMonitorTaskResultTopic:
			OnRtnNetMonitorTaskResultTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnNetPartyLinkStatusInfoTopic:
			OnRtnNetPartyLinkStatusInfoTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnNetBaseLineResultTopic:
			OnRtnNetBaseLineResultTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnNetLocalPingResultInfoTopic:
			OnRtnNetLocalPingResultTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnNetRomotePingResultInfoTopic:
			OnRtnNetRomotePingResultTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnParticTradeOrderStatesTopic:
			OnRtnParticTradeOrderStatesTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnDiskIOTopic:
			OnRtnDiskIOTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnStatInfoTopic:
			OnRtnStatInfoTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnRouterInfoTopic:
			OnRtnRouteInfoTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnTopProcessInfoTopic:
			OnRtnTopProcessInfoTopic(pFTDCPackage);
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

void CStatusSubscriber::OnRtnDiskIOTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnDiskIOField	fieldInfo;
	FOREACH_FIELD(pFTDCPackage, CFTDRtnDiskIOField, fieldInfo)
	{
		char strTmp[128];
		sprintf(
			strTmp,
			"%s.%s",
			fieldInfo.HostName.getValue(),
			fieldInfo.PartName.getValue());
		fieldInfo.HostName = strTmp;

		bool result;
		CFtdData wrappedObj(&fieldInfo, &CFTDRtnDiskIOField::m_Describe);
		if (0 == g_nStartParaWrtDB)
		{
			result = m_hander.InsertRecord("T_Diskio", &wrappedObj, false);
		}
	}
}

void CStatusSubscriber::OnRtnRouteInfoTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnRouterInfoField	fieldInfo;
	FOREACH_FIELD(pFTDCPackage, CFTDRtnRouterInfoField, fieldInfo)
	{
		bool result;
		CFtdData wrappedObj(&fieldInfo, &CFTDRtnRouterInfoField::m_Describe);
		if (0 == g_nStartParaWrtDB)
		{
			result = m_hander.InsertRecord("T_Routerinfo", &wrappedObj, false);
		}
	}
}

void CStatusSubscriber::OnRtnTopProcessInfoTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnTopProcessInfoField	fieldInfo;
	FOREACH_FIELD(pFTDCPackage, CFTDRtnTopProcessInfoField, fieldInfo)
	{
		bool result;
		CFTDRtnMonitorTopProcessInfoField dbField;

		//需要保证2个数据模型的类型一致
		if (sizeof(dbField) == sizeof(fieldInfo) && 0 == g_nStartParaWrtDB)
		{
			memcpy(&dbField, &fieldInfo, sizeof(dbField));

			CFtdData wrappedObj(
						&dbField,
						&CFTDRtnMonitorTopProcessInfoField::m_Describe);
			result = m_hander.InsertRecord(
					"T_TopProcessInfo",
					&wrappedObj,
					false);
		}
	}
}

void CStatusSubscriber::OnRtnStatInfoTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnStatInfoField fieldInfo;
	FOREACH_FIELD(pFTDCPackage, CFTDRtnStatInfoField, fieldInfo)
	{
		bool result;
		CFtdData wrappedObj(&fieldInfo, &CFTDRtnStatInfoField::m_Describe);
		if (0 == g_nStartParaWrtDB)
		{
			result = m_hander.InsertRecord("T_Statinfo", &wrappedObj, false);
		}
	}
}

void CStatusSubscriber::OnRtnHistoryTradePeakTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnHistoryTradePeakField fieldPeakInfo;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldPeakInfo))
	{
		/// 处理事件计算服务器发送过来的当日指标最大值
		m_pkgSend.PreparePackage(
				FTD_TID_RtnHistoryTradePeakTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		map<CPeakKey, CFTDRtnHistoryTradePeakField>::iterator it =
			g_mapTradePeak.find(
					CPeakKey(
						(char *)fieldPeakInfo.ObjectID.getValue(),
						(char *)fieldPeakInfo.AttrType.getValue(),
						(char *)fieldPeakInfo.RltAttrType.getValue()));
		if (it == g_mapTradePeak.end())			//该指标在历史数据库中不存在最大值
		{
			fieldPeakInfo.MaxAttrValue = fieldPeakInfo.AttrValue;
			fieldPeakInfo.MaxMonDate = fieldPeakInfo.MonDate;
			fieldPeakInfo.MaxMonTime = fieldPeakInfo.MonTime;
			fieldPeakInfo.MaxRltAttrValue = fieldPeakInfo.RltAttrValue;
			fieldPeakInfo.OldAttrValue = fieldPeakInfo.AttrValue;
			fieldPeakInfo.OldMonDate = fieldPeakInfo.MonDate;
			fieldPeakInfo.OldMonTime = fieldPeakInfo.MonTime;
			fieldPeakInfo.OldRltAttrValue = fieldPeakInfo.RltAttrValue;
			g_mapTradePeak.insert(
					make_pair(
						CPeakKey(
								(char *)fieldPeakInfo.ObjectID.getValue(),
								(char *)fieldPeakInfo.AttrType.getValue(),
								(char *)fieldPeakInfo.RltAttrType.getValue()),
						fieldPeakInfo));
			FTDC_ADD_FIELD(&m_pkgSend, &fieldPeakInfo);

			// 把 fieldPeakInfo insert到数据库 20081216
			// ......
			if (0 == g_nStartParaWrtDB)
			{
				try
				{
					if (!connectDB())
					{
						return;
					}
					ScopeLock<CMutex> scopelock(m_sqlMutex);
					SACommand cmd(
								m_sqlConnect,
								"insert into t_SysHistoryTradePeak \
						(ObjectID,MonDate,MonTime,AttrType,AttrValue,RltAttrType,RltAttrValue,MaxMonDate,\
						MaxMonTime,MaxAttrValue,MaxRltAttrValue,OldMonDate,OldMonTime,OldAttrValue,OldRltAttrValue) values \
						(:ObjectID,:MonDate,:MonTime,:AttrType,:AttrValue,:RltAttrType,:RltAttrValue,:MaxMonDate,\
						:MaxMonTime,:MaxAttrValue,:MaxRltAttrValue,:OldMonDate,:OldMonTime,:OldAttrValue,:OldRltAttrValue) ");

					cmd << SAPos("ObjectID") << fieldPeakInfo.ObjectID;
					cmd << SAPos("MonDate") << fieldPeakInfo.MonDate;
					cmd << SAPos("MonTime") << fieldPeakInfo.MonTime;
					cmd << SAPos("AttrType") << fieldPeakInfo.AttrType;
					cmd << SAPos("AttrValue") << fieldPeakInfo.AttrValue;
					cmd << SAPos("RltAttrType") << fieldPeakInfo.RltAttrType;
					cmd << SAPos("RltAttrValue") << fieldPeakInfo.RltAttrValue;
					cmd << SAPos("MaxMonDate") << fieldPeakInfo.MaxMonDate;
					cmd << SAPos("MaxMonTime") << fieldPeakInfo.MaxMonTime;
					cmd << SAPos("MaxAttrValue") << fieldPeakInfo.MaxAttrValue;
					cmd <<
						SAPos("MaxRltAttrValue") <<
						fieldPeakInfo.MaxRltAttrValue;
					cmd << SAPos("OldMonDate") << fieldPeakInfo.OldMonDate;
					cmd << SAPos("OldMonTime") << fieldPeakInfo.OldMonTime;
					cmd << SAPos("OldAttrValue") << fieldPeakInfo.OldAttrValue;
					cmd <<
						SAPos("OldRltAttrValue") <<
						fieldPeakInfo.OldRltAttrValue;
					cmd.Execute();
					m_sqlConnect->Commit();
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
		else
		{	//该指标在数据库中已经存在最大值
			//
			it->second.AttrValue = fieldPeakInfo.AttrValue;
			it->second.MonDate = fieldPeakInfo.MonDate;
			it->second.MonTime = fieldPeakInfo.MonTime;
			it->second.RltAttrValue = fieldPeakInfo.RltAttrValue;
			if (it->second.AttrValue > it->second.MaxAttrValue) // 当日峰值超过历史峰值
			{
				///仅当此时最大值日期非当前日期则将此最大值设为次大值
				if (it->second.MonDate != it->second.MaxMonDate)
				{
					it->second.OldAttrValue = it->second.MaxAttrValue;
					it->second.OldMonDate = it->second.MaxMonDate;
					it->second.OldMonTime = it->second.MaxMonTime;
					it->second.OldRltAttrValue = it->second.MaxRltAttrValue;
				}

				it->second.MaxAttrValue = it->second.AttrValue;
				it->second.MaxMonDate = it->second.MonDate;
				it->second.MaxMonTime = it->second.MonTime;
				it->second.MaxRltAttrValue = it->second.RltAttrValue;

				// 把 it->second update到数据库 20081216
				// ......
				if (0 == g_nStartParaWrtDB)
				{
					try
					{
						if (!connectDB())
						{
							return;
						}
						ScopeLock<CMutex> scopelock(m_sqlMutex);
						SACommand cmd;
						cmd.setConnection(m_sqlConnect);
						cmd.setCommandText(
								"update t_SysHistoryTradePeak set \
							MonDate=:MonDate, MonTime=:MonTime, AttrValue=:AttrValue, RltAttrValue=:RltAttrValue, \
							MaxMonDate=:MaxMonDate, MaxMonTime=:MaxMonTime, MaxAttrValue=:MaxAttrValue, MaxRltAttrValue=:MaxRltAttrValue, \
							OldMonDate=:OldMonDate, OldMonTime=:OldMonTime, OldAttrValue=:OldAttrValue, OldRltAttrValue=:OldRltAttrValue \
							where ObjectID = :ObjectID and AttrType = :AttrType and RltAttrType = :RltAttrType  ");

						cmd << SAPos("ObjectID") << it->second.ObjectID;
						cmd << SAPos("MonDate") << it->second.MonDate;
						cmd << SAPos("MonTime") << it->second.MonTime;
						cmd << SAPos("AttrType") << it->second.AttrType;
						cmd << SAPos("AttrValue") << it->second.AttrValue;
						cmd << SAPos("RltAttrType") << it->second.RltAttrType;
						cmd << SAPos("RltAttrValue") << it->second.RltAttrValue;
						cmd << SAPos("MaxMonDate") << it->second.MaxMonDate;
						cmd << SAPos("MaxMonTime") << it->second.MaxMonTime;
						cmd << SAPos("MaxAttrValue") << it->second.MaxAttrValue;
						cmd <<
							SAPos("MaxRltAttrValue") <<
							it->second.MaxRltAttrValue;
						cmd << SAPos("OldMonDate") << it->second.OldMonDate;
						cmd << SAPos("OldMonTime") << it->second.OldMonTime;
						cmd << SAPos("OldAttrValue") << it->second.OldAttrValue;
						cmd <<
							SAPos("OldRltAttrValue") <<
							it->second.OldRltAttrValue;
						cmd.Execute();
						m_sqlConnect->Commit();
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

			FTDC_ADD_FIELD(&m_pkgSend, &(it->second));
		}

		SessionProxy::Instance().NotifyAllFront(&m_pkgSend);
	}
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

#if 0
void CStatusSubscriber::OnRtnNetObjectAttrTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnNetObjectAttrField fieldInfo;
	FOREACH_FIELD(pFTDCPackage, CFTDRtnNetObjectAttrField, fieldInfo)
	{
		bool result;
		INSERT_OBJ_TO_DB(NetObjectAttr, fieldInfo, m_hander, result);
	}
}

#endif
void CStatusSubscriber::OnRtnWarningEventTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnWarningEventField fieldInfo;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnWarningEventField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);

		// Added by Henchi, 20100203
		if (strcmp(fieldInfo.ProcessFlag.getValue(), "N") == 0
		&&	!IsExcludedObject((char *)fieldInfo.ObjectID.getValue()))
		{
			/// Added by Henchi, 20100120
			AddEventCount(fieldInfo);

			/// 增加写入到文件，提供给消息平台 20090827
			writeWarningEvent(fieldInfo);
		}

		/// 增加写入数据库 ZHOUJIANJUN
				///20080717 add by wu.yb
		InsertRtnWarningEventTopic(fieldInfo);

		itor.Next();
		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())
		{
			break;
		}
	}
}

bool CStatusSubscriber::IsExcludedObject(char *objectID)
{
	for (list<string>::iterator it = g_listExcludedSystem.begin();
		 it != g_listExcludedSystem.end();
		 it++)
	{
		if (strncmp((*it).c_str(), objectID, strlen((*it).c_str())) == 0
		&&	*(objectID + strlen((*it).c_str())) == '.')
		{
			return true;
		}
	}

	return false;
}

void CStatusSubscriber::AddEventCount(CFTDRtnWarningEventField &fieldInfo)
{
	char szBuf[256] = "";
	sprintf(
		szBuf,
		"%s:%s",
		(char *)fieldInfo.ObjectID.getValue(),
		(char *)fieldInfo.EventName.getValue());

	map<string, int>::iterator	mapIt = mapEventCount.find(szBuf);
	if (mapIt == mapEventCount.end())
	{
		mapEventCount[szBuf] = 1;
	}
	else
	{
		(mapIt->second)++;
	}
}

void CStatusSubscriber::OnRtnHistoryObjectAttrTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnHistoryObjectAttrField fieldInfo;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnHistoryObjectAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);

		///增加写入数据库 ZHOUJIANJUN
		//		///20080717 add by wu.yb
		//InsertRtnHistoryObjectAttrTopic(fieldInfo);

		//20141111 add by Lee
		//数据量增大时，直接写入数据库，严重降低服务效率，导致sysquery查询响应时间太慢，影响历史数据的查询
		//暂时先存入list队列，后期批量写入DB 
		m_listHisObjectAttr.add(fieldInfo);

		/// Added by Henchi, 20100120
				///增加特定指标信息过滤处理
		FiltrateRtnHistoryObjectAttr(fieldInfo);
		itor.Next();
		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())
		{
			break;
		}
	}
}

void CStatusSubscriber::OnRtnDBQueryTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnDBQueryField fieldInfo;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnDBQueryField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);

		// Added by Henchi, 20091229
				///目前只有Apache访问统计信息通过RtnDBQuery包往查询服务推送，暂时不作进一步信息校验，直接写入数据库中
		InsertRtnDBQueryAccessLog(fieldInfo);

		itor.Next();
		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())
		{
			break;
		}
	}
}

void CStatusSubscriber::OnRtnNetMonitorTaskResultTopic(
	CFTDCPackage *pFTDCPackage)
{
	CFTDRtnNetMonitorTaskResultField field;
	FOREACH_FIELD(pFTDCPackage, CFTDRtnNetMonitorTaskResultField, field)
	{
		bool result;
		if (0 == g_nStartParaWrtDB)
		{
			INSERT_OBJ_TO_DB(NetMonitorTaskResult, field, m_hander, result);
		}
	}
}

void CStatusSubscriber::OnRtnNetPartyLinkStatusInfoTopic(
	CFTDCPackage *pFTDCPackage)
{
	CFTDRtnNetPartyLinkStatusInfoField	field;
	FOREACH_FIELD(pFTDCPackage, CFTDRtnNetPartyLinkStatusInfoField, field)
	{
		bool result;
		if (0 == g_nStartParaWrtDB)
		{
			INSERT_OBJ_TO_DB(NetPartyLinkStatusInfo, field, m_hander, result);
		}
	}
}

static int	s_base_line_task_result_id;

static void initBaseLineTaskResultID(SACommand &records, void *data)
{
	s_base_line_task_result_id = records.Field(1).asLong() + 1;
}

void CStatusSubscriber::OnRtnNetBaseLineResultTopic(CFTDCPackage *pFTDCPackage)
{
	static bool isInitID = false;
	if (!isInitID)
	{
		string	sql = "select NVL(max(ID), 0) from t_sysnetbaselineresult";

		m_hander.SearchRecord(sql, initBaseLineTaskResultID);

		isInitID = true;
	}

	bool dbResult;

	CFTDRtnNetBaseLineResultField field;
	FOREACH_FIELD(pFTDCPackage, CFTDRtnNetBaseLineResultField, field)
	{
		static std::map<string, std::vector<CFTDRtnNetBaseLineResultField> >
			pkgBuf;
		if (field.Flag.getValue() == 0)
		{
			// 有后续包，放入缓冲区
			pkgBuf[field.BaseLineName.getValue()].push_back(field);

			return;
		}
		else if (field.Flag.getValue() == 1)
		{
			// 为终止包，从缓冲区中取出前面的包，依次写入数据库
			pkgBuf[field.BaseLineName.getValue()].push_back(field);

			//int baseLineResultID = s_base_line_task_result_id++;
			//field.ID = baseLineResultID;
			std::vector<CFTDRtnNetBaseLineResultField>	&pkgs = pkgBuf[field.
				BaseLineName.getValue()];
			for (int i = 0, size = pkgs.size(); i < size; i++)
			{
				//pkgs[i].ID = baseLineResultID;
				if (0 == g_nStartParaWrtDB)
				{
					INSERT_OBJ_TO_DB(
						NetBaseLineResult,
						pkgs[i],
						m_hander,
						dbResult);
				}

				//TODO：中间发生插入错误，要将不完整的记录回滚
			}

			// 清楚缓存的包
			pkgBuf.erase(field.BaseLineName.getValue());
		}
		else if (field.Flag.getValue() == 2)
		{
			// 单独包，直接写入数据库
			//field.ID = s_base_line_task_result_id++;
			if (0 == g_nStartParaWrtDB)
			{
				INSERT_OBJ_TO_DB(NetBaseLineResult, field, m_hander, dbResult);
			}
		}
		else
		{
			// 非法类型
			return;
		}
	}
}

void CStatusSubscriber::OnRtnNetLocalPingResultTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnNetLocalPingResultInfoField fieldInfo;
	FOREACH_FIELD(pFTDCPackage, CFTDRtnNetLocalPingResultInfoField, fieldInfo)
	{
		if (fieldInfo.ConnRate.getValue() == 1)
		{
			continue;
		}

		if (0 == g_nStartParaWrtDB)
		{
			try
			{
				if (!connectDB())
				{
					return;
				}
				ScopeLock<CMutex> scopelock(m_sqlMutex);
				SACommand cmd;
				cmd.setConnection(m_sqlConnect);

				if (0 == m_nLocID)
				{
					//to query
					cmd.setCommandText(
							"select nvl(max(id), 1) as mid from t_SysLocalPingResultInfo");
					cmd.Execute();
					while (cmd.FetchNext())
					{
						m_nLocID = cmd.Field("mid").asLong();
					}

					if (0 == m_nLocID)
					{
						return;
					}
				}

				cmd.setCommandText(
						"insert into t_SysLocalPingResultInfo \
									   (ID, SouIPADDR,SouNAME,TarIPADDR,TarNAME,PDateSta,PTimeSta,ConnRate) values \
									   (:ID,:SouIPADDR,:SouNAME,:TarIPADDR,:TarNAME,:PDateSta,:PTimeSta,:ConnRate) ");

				cmd << SAPos("ID") << (long)++m_nLocID;
				cmd << SAPos("SouIPADDR") << fieldInfo.SouIPADDR;
				cmd << SAPos("SouNAME") << fieldInfo.SouNAME;
				cmd << SAPos("TarIPADDR") << fieldInfo.TarIPADDR;
				cmd << SAPos("TarNAME") << fieldInfo.TarNAME;
				cmd << SAPos("PDateSta") << fieldInfo.PDateSta;
				cmd << SAPos("PTimeSta") << fieldInfo.PTimeSta;
				cmd << SAPos("ConnRate") << (long)fieldInfo.ConnRate;

				cmd.Execute();
				m_sqlConnect->Commit();
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
}

void CStatusSubscriber::OnRtnNetRomotePingResultTopic(
	CFTDCPackage *pFTDCPackage)
{
	CFTDRtnNetRomotePingResultInfoField fieldInfo;
	FOREACH_FIELD(pFTDCPackage, CFTDRtnNetRomotePingResultInfoField, fieldInfo)
	{
		if (0 == g_nStartParaWrtDB)
		{
			try
			{
				if (!connectDB())
				{
					return;
				}
				ScopeLock<CMutex> scopelock(m_sqlMutex);
				SACommand cmd;
				cmd.setConnection(m_sqlConnect);

				if (0 == m_nRemID)
				{
					//to query
					cmd.setCommandText(
							"select nvl(max(id), 1) as mid from t_SysRomotePingResultInfo");
					cmd.Execute();
					while (cmd.FetchNext())
					{
						m_nRemID = cmd.Field("mid").asLong();
					}

					if (0 == m_nRemID)
					{
						return;
					}
				}

				cmd.setCommandText(
						"insert into t_SysRomotePingResultInfo \
								   (ID, SouIPADDR,SouNAME,TarIPADDR,TarNAME,PDateSta,PTimeSta,ConnRate,TimeDlyMin,TimeDlyMax,TimeDlyAvg) values \
								   (:ID,:SouIPADDR,:SouNAME,:TarIPADDR,:TarNAME,:PDateSta,:PTimeSta,:ConnRate, :TimeDlyMin, :TimeDlyMax, :TimeDlyAvg) ");

				cmd << SAPos("ID") << (long)++m_nRemID;
				cmd << SAPos("SouIPADDR") << fieldInfo.SouIPADDR;
				cmd << SAPos("SouNAME") << fieldInfo.SouNAME;
				cmd << SAPos("TarIPADDR") << fieldInfo.TarIPADDR;
				cmd << SAPos("TarNAME") << fieldInfo.TarNAME;
				cmd << SAPos("PDateSta") << fieldInfo.PDateSta;
				cmd << SAPos("PTimeSta") << fieldInfo.PTimeSta;
				cmd << SAPos("ConnRate") << (long)fieldInfo.ConnRate;

				cmd << SAPos("TimeDlyMin") << fieldInfo.TimeDlyMin;
				cmd << SAPos("TimeDlyMax") << fieldInfo.TimeDlyMax;
				cmd << SAPos("TimeDlyAvg") << fieldInfo.TimeDlyAvg;

				cmd.Execute();
				m_sqlConnect->Commit();
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
}

bool bIniiii = false;

void CStatusSubscriber::OnRtnParticTradeOrderStatesTopic(
	CFTDCPackage *pFTDCPackage)
{
	// 	if (!bIniiii)
	// 	{
	// 		InitDBParam();
	// 		bIniiii = true;
	// 	}
	CFTDRtnParticTradeOrderStatesField fieldInfo;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnParticTradeOrderStatesField::m_Describe);

	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);

		string strKey = fieldInfo.ParticipantID.getValue();
		strKey.append(":");
		strKey.append(fieldInfo.UserID.getValue());

		if (m_mapPatMemOrderCnt.find(strKey) == m_mapPatMemOrderCnt.end())
		{
			CLatestOrderOfParticipation &latParOrd = m_mapPatMemOrderCnt[
				strKey];

			latParOrd.strPart = fieldInfo.ParticipantID.getValue();
			latParOrd.strUser = fieldInfo.UserID.getValue();

			latParOrd.strLastDate = fieldInfo.MonDate.getValue();
			latParOrd.strLastTime = fieldInfo.MonTime.getValue();

			latParOrd.bSafe = true;
			latParOrd.bNedInsrtARec = true;
			latParOrd.nTimeWidth = g_nOrderTimeWid;
		}

		CLatestOrderOfParticipation &latParOrd = m_mapPatMemOrderCnt[strKey];

		latParOrd.AppendAnewRecord(&fieldInfo);

		itor.Next();
	}
}

void CStatusSubscriber::FiltrateRtnHistoryObjectAttr(
	CFTDRtnHistoryObjectAttrField &fieldInfo)
{
	char szBuf[256] = "";
	sprintf(
		szBuf,
		"%s:%s",
		(char *)fieldInfo.ObjectID.getValue(),
		(char *)fieldInfo.AttrType.getValue());

	map<string, long>::iterator mapIt = g_mapAttrValue.find(szBuf);
	if (mapIt != g_mapAttrValue.end())
	{
		m_lockObjectAttr.Lock();
		m_mapHistoryObjectAttr[szBuf] = fieldInfo;
		g_mapAttrValue[szBuf] = (long)fieldInfo.EndValue;
		m_lockObjectAttr.UnLock();
	}
}

void CStatusSubscriber::CheckObjectAttrOutput(time_t gTime)
{
	list<CAttrTeam *>::iterator it;
	for (it = g_listAttrTeam.begin(); it != g_listAttrTeam.end(); it++)
	{
		if ((*it)->NeedOutput(gTime))
		{
			m_lockObjectAttr.Lock();
			writeObjectAttr(*it);
			m_lockObjectAttr.UnLock();
		}
	}
}

void CStatusSubscriber::CheckEventCount(time_t gTime)
{
	if (m_resetRun.needExcute(gTime))
	{
		mapEventCount.clear();
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

	//任何情况下有效长度都是第一个block
	nValidEnd = mapValidContent[0];
}

void CStatusSubscriber::InsertRtnHistoryObjectAttrTopic(
	const CFTDRtnHistoryObjectAttrField &fieldInfo)
{
#ifdef PRINT_DEBUG
	printf(
		"运行文件 CStatusSubscriber::InsertRtnHistoryObjectAttrTopic： %s 行数：%d \n",
		__FILE__,
		__LINE__);
#endif
	if (0 == g_nStartParaWrtDB)
	{
		try
		{
			if (!connectDB())
			{
				return;
			}
			ScopeLock<CMutex> scopelock(m_sqlMutex);
			SACommand cmdQuery;
			cmdQuery.setConnection(m_sqlConnect);

			cmdQuery.setCommandText("select * from t_syshistoryobjectattr where mondate=:1 and begintime=:2 and objectid=:3 and attrtype=:4");
			cmdQuery<<fieldInfo.MonDate<<fieldInfo.BeginTime<<fieldInfo.ObjectID<<fieldInfo.AttrType;

			cmdQuery.Execute();

			int cnt = 0;
			while (cmdQuery.FetchNext())
			{
				cnt++;
				break;
			}

			if (cnt>0)
			{
				return;
			}

			SACommand cmd(
						m_sqlConnect,
						"insert into t_SysHistoryObjectAttr \
				(MonDate,BeginTime,EndTime,ObjectID,AttrType,ValueType,FirstValue,EndValue,AvgValue,MinValue,MaxValue,ValueCount) values \
				(:MonDate,:BeginTime,:EndTime,:ObjectID,:AttrType,:ValueType,:FirstValue,:EndValue,:AvgValue,:MinValue,:MaxValue,:ValueCount) ");

			cmd << SAPos("MonDate") << fieldInfo.MonDate;
			cmd << SAPos("BeginTime") << fieldInfo.BeginTime;
			cmd << SAPos("EndTime") << fieldInfo.EndTime;
			cmd << SAPos("ObjectID") << fieldInfo.ObjectID;
			cmd << SAPos("AttrType") << fieldInfo.AttrType;
			cmd << SAPos("ValueType") << (long)fieldInfo.ValueType;

			//cmd.Param("ValueType").setAsLong() = fieldInfo.ValueType;
			cmd << SAPos("FirstValue") << fieldInfo.FirstValue;
			cmd << SAPos("EndValue") << fieldInfo.EndValue;
			cmd << SAPos("AvgValue") << fieldInfo.AvgValue;
			cmd << SAPos("MinValue") << fieldInfo.MinValue;
			cmd << SAPos("MaxValue") << fieldInfo.MaxValue;
			cmd << SAPos("ValueCount") << (long)fieldInfo.ValueCount;

			cmd.Execute();
			m_sqlConnect->Commit();
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

void CStatusSubscriber::InsertRtnWarningEventTopic(
	const CFTDRtnWarningEventField	&fieldInfo)
{
	bool result;

	if (fieldInfo.ProcessFlag == "N")
	{
		if (0 == g_nStartParaWrtDB)
		{
			INSERT_OBJ_TO_DB(WarningEvent, fieldInfo, m_hander, result);
		}
	}
	else
	{
		SqlGenerator sql;

		WRAP_FTD_OBJ(WarningEvent, fieldInfo);

		DBOperator::ColumnArray attrs;

		attrs.push_back(DBOperator::Column(&wrappedObj, "MonTime"));
		attrs.push_back(DBOperator::Column(&wrappedObj, "MonDate"));
		attrs.push_back(DBOperator::Column(&wrappedObj, "EvendID"));

		if (0 == g_nStartParaWrtDB)
		{
			m_hander.UpdateRecord(FTD_TABLE(WarningEvent), attrs, attrs);
		}
	}
}

string CStatusSubscriber::getConnectStr(
	const string &ip,
	const string &port,
	const string &dbName)
{
	return ip + ":" + port + "/" + dbName;
}

///该函数来自 sysprobe->DatabaseSpiImpl.cpp->isAlive()
bool CStatusSubscriber::isAlive(SAConnection *conn)
{
	if (!m_bTryConnectDbFlag)
	{
		return true;
	}

	try
	{
		string recStr = "select distinct 1 from user_tables";

		SACommand cmd(conn, recStr.c_str());
		cmd.Execute();
		while (cmd.FetchNext())
		{
		}

		m_bTryConnectDbFlag = false;
	}
	catch(SAException & ex)
	{
		print_errmsg(
			__FILE__,
			__FUNCTION__,
			__LINE__,
			(const char *)ex.ErrText());

		time_t now;
		char tmpTime[10];
		struct tm tm_time;
		time(&now);
		LocalTime(&now, &tm_time);
		strftime(tmpTime, 10, "%H:%M:%S", &tm_time);
		printf("In CStatusSubscriber::isAlive() %s\n", tmpTime);
		return false;
	}

	return true;
}

///连接数据库，如果是连接着的，就不再进行连接，数据库类型仅仅支持Oracle
bool CStatusSubscriber::connectDB(void)
{
	if (!m_bSepsDbFlag)
	{
		return false;
	}

	if (NULL != m_sqlConnect)
	{
		if (isAlive(m_sqlConnect))
		{
			return true;
		}
		else
		{
			delete m_sqlConnect;
			m_sqlConnect = NULL;
		}
	}

	try
	{
		m_sqlConnect = new SAConnection();
		m_sqlConnect->Connect(
				getConnectStr(g_strDbIp, g_strDbPort, g_strDbName).c_str(),
				g_strDbUser.c_str(),
				g_strDbPwd.c_str(),
				SA_Oracle_Client);
		GetTradePeakFromDB();
		m_bTryConnectDbFlag = false;
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
			m_sqlConnect->Rollback();
		}
		catch(SAException & ex)
		{
			print_errmsg(
				__FILE__,
				__FUNCTION__,
				__LINE__,
				(const char *)ex.ErrText());
		}

		if (NULL != m_sqlConnect)
		{
			delete m_sqlConnect;
			m_sqlConnect = NULL;
		}

		return false;
	}

	return true;
}

//2008.09.19 add by wu.yb
///Cpu使用情况
void CStatusSubscriber::OnRtnTopCpuInfoTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnTopCpuInfoField fieldInfo;
	FOREACH_FIELD(pFTDCPackage, CFTDRtnTopCpuInfoField, fieldInfo)
	{
		if (0 == g_nStartParaWrtDB)
		{
			InsertRtnTopCpuInfoTopic(fieldInfo);
		}
	}
}

///内存使用情况
void CStatusSubscriber::OnRtnTopMemInfoTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnTopMemInfoField fieldInfo;
	FOREACH_FIELD(pFTDCPackage, CFTDRtnTopMemInfoField, fieldInfo)
	{
		if (0 == g_nStartParaWrtDB)
		{
			InsertRtnTopMemInfoTopic(fieldInfo);
		}
	}
}

///网络使用情况
void CStatusSubscriber::OnRtnNetworkInfoTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnNetworkInfoField fieldInfo;
	FOREACH_FIELD(pFTDCPackage, CFTDRtnNetworkInfoField, fieldInfo)
	{
		InsertRtnNetworkInfoTopic(fieldInfo);
	}
}

void CStatusSubscriber::InsertRtnTopCpuInfoTopic(
	const CFTDRtnTopCpuInfoField &fieldInfo)
{
	if (0 == g_nStartParaWrtDB)
	{
		try
		{
			if (!connectDB())
			{
				return;
			}
			ScopeLock<CMutex> scopelock(m_sqlMutex);
			SACommand cmd;
			cmd.setConnection(m_sqlConnect);
			cmd.setCommandText(
					"insert into t_RspQryTopCpuInfo \
				(HostName,MonDate,MonTime,CPU,LOAD,USER_LOAD,NICE,SYS,IDLE,BLOCK,SWAIT,INTR,SSYS) values \
				(:HostName,:MonDate,:MonTime,:CPU,:LOAD,:USER_LOAD,:NICE,:SYS,:IDLE,:BLOCK,:SWAIT,:INTR,:SSYS) ");

			cmd << SAPos("HostName") << fieldInfo.HostName;
			cmd << SAPos("MonDate") << fieldInfo.MonDate;
			cmd << SAPos("MonTime") << fieldInfo.MonTime;
			cmd << SAPos("CPU") << fieldInfo.CPU;
			cmd << SAPos("LOAD") << fieldInfo.LOAD;
			cmd << SAPos("USER_LOAD") << fieldInfo.USER;
			cmd << SAPos("NICE") << fieldInfo.NICE;
			cmd << SAPos("SYS") << fieldInfo.SYS;
			cmd << SAPos("IDLE") << fieldInfo.IDLE;
			cmd << SAPos("BLOCK") << fieldInfo.BLOCK;
			cmd << SAPos("SWAIT") << fieldInfo.SWAIT;
			cmd << SAPos("INTR") << fieldInfo.INTR;
			cmd << SAPos("SSYS") << fieldInfo.SSYS;

			cmd.Execute();
			m_sqlConnect->Commit();
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

void CStatusSubscriber::InsertRtnTopMemInfoTopic(
	const CFTDRtnTopMemInfoField &fieldInfo)
{
	if (0 == g_nStartParaWrtDB)
	{
		try
		{
			if (!connectDB())
			{
				return;
			}
			ScopeLock<CMutex> scopelock(m_sqlMutex);
			SACommand cmd;
			cmd.setConnection(m_sqlConnect);
			cmd.setCommandText(
					"insert into t_RspQryTopMemInfo \
				(HostName,MonDate,MonTime,TOTALREAL,ACTIVEREAL,TOTALVIRTUAL,ACTIVEVIRTUAL,FREE) values \
				(:HostName,:MonDate,:MonTime,:TOTALREAL,:ACTIVEREAL,:TOTALVIRTUAL,:ACTIVEVIRTUAL,:FREE)  ");

			cmd << SAPos("HostName") << fieldInfo.HostName;
			cmd << SAPos("MonDate") << fieldInfo.MonDate;
			cmd << SAPos("MonTime") << fieldInfo.MonTime;
			cmd << SAPos("TOTALREAL") << (long)fieldInfo.TOTALREAL;
			cmd << SAPos("ACTIVEREAL") << (long)fieldInfo.ACTIVEREAL;
			cmd << SAPos("TOTALVIRTUAL") << (long)fieldInfo.TOTALVIRTUAL;
			cmd << SAPos("ACTIVEVIRTUAL") << (long)fieldInfo.ACTIVEVIRTUAL;
			cmd << SAPos("FREE") << (long)fieldInfo.FREE;

			cmd.Execute();
			m_sqlConnect->Commit();
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

void CStatusSubscriber::InsertRtnNetworkInfoTopic(
	const CFTDRtnNetworkInfoField &fieldInfo)
{
	if (0 == g_nStartParaWrtDB)
	{
		try
		{
			if (!connectDB())
			{
				return;
			}
			ScopeLock<CMutex> scopelock(m_sqlMutex);
			SACommand cmd;
			cmd.setConnection(m_sqlConnect);
			cmd.setCommandText(
					"insert into t_RspQryNetworkInfo \
				(HostName,MonDate,MonTime,LANNAME,LANSTATUS,IPADDRESS,SENDPACKETS,SENDBYTES,RECVPACKETS,RECVBYTES,RECVERRORPACKETS, RECVDROPPACKETS, SENDERRORPACKETS,SENDDROPPACKETS) values \
				(:HostName,:MonDate,:MonTime,:LANNAME,:LANSTATUS,:IPADDRESS,:SENDPACKETS,:SENDBYTES,:RECVPACKETS,:RECVBYTES, :RECVERRORPACKETS, :RECVDROPPACKETS, :SENDERRORPACKETS,:SENDDROPPACKETS)");

			//cmd << SAPos("HostName")		<< fieldInfo.HostName;
				
						///2008.09.23 因为查询的时候传递的数据中HostName实际上是HostName+LanName，
						///为了便于查询，这里把HostName和LanName进行拼接之后在入库
			string tempHostName = fieldInfo.HostName.getValue();
			tempHostName += ".";
			tempHostName += fieldInfo.LANNAME.getValue();

			// 			{
			// 				printf("%s\n", tempHostName.data());
			// 				printf("%s\n", fieldInfo.MonDate.getValue());
			// 				printf("%s\n", fieldInfo.MonTime.getValue());
			// 				printf("%s\n", fieldInfo.LANNAME.getValue());
			// 				printf("%s\n", fieldInfo.IPADDRESS.getValue());
			// 				printf("%s\n", fieldInfo.LANSTATUS.getValue());
			//
			// 				printf("%lld, %lld,%lld,%lld,%lld, %lld, %lld, %lld \n", (QWORD)fieldInfo.SENDPACKETS,
			// 					(QWORD)fieldInfo.SENDBYTES,
			// 					(QWORD)fieldInfo.RECVPACKETS,
			// 					(QWORD)fieldInfo.RECVBYTES,
			// 					(QWORD)fieldInfo.RECVERRORPACKETS,
			// 					(QWORD)fieldInfo.RECVDROPPACKETS,
			// 					(QWORD)fieldInfo.SENDERRORPACKETS,
			// 					(QWORD)fieldInfo.SENDDROPPACKETS);
			//
			// 			}
			cmd << SAPos("HostName") << tempHostName.data();
			cmd << SAPos("MonDate") << fieldInfo.MonDate;
			cmd << SAPos("MonTime") << fieldInfo.MonTime;
			cmd << SAPos("LANNAME") << fieldInfo.LANNAME;
			cmd << SAPos("LANSTATUS") << fieldInfo.LANSTATUS;
			cmd << SAPos("IPADDRESS") << fieldInfo.IPADDRESS;

#ifdef WINDOWS
			cmd.Param("SENDPACKETS").setAsNumeric() = (QWORD) fieldInfo.SENDPACKETS;
			cmd.Param("SENDBYTES").setAsNumeric() = (QWORD) fieldInfo.SENDBYTES;
			cmd.Param("RECVPACKETS").setAsNumeric() = (QWORD) fieldInfo.RECVPACKETS;
			cmd.Param("RECVBYTES").setAsNumeric() = (QWORD) fieldInfo.RECVBYTES;
			cmd.Param("RECVERRORPACKETS").setAsNumeric() = (QWORD) fieldInfo.RECVERRORPACKETS;
			cmd.Param("RECVDROPPACKETS").setAsNumeric() = (QWORD) fieldInfo.RECVDROPPACKETS;
			cmd.Param("SENDERRORPACKETS").setAsNumeric() = (QWORD) fieldInfo.SENDERRORPACKETS;
			cmd.Param("SENDDROPPACKETS").setAsNumeric() = (QWORD) fieldInfo.SENDDROPPACKETS;
#else
			cmd << SAPos("SENDPACKETS") << (long)fieldInfo.SENDPACKETS;
			cmd << SAPos("SENDBYTES") << (long)fieldInfo.SENDBYTES;
			cmd << SAPos("RECVPACKETS") << (long)fieldInfo.RECVPACKETS;
			cmd << SAPos("RECVBYTES") << (long)fieldInfo.RECVBYTES;
			cmd <<
				SAPos("RECVERRORPACKETS") <<
				(long)fieldInfo.RECVERRORPACKETS;
			cmd << SAPos("RECVDROPPACKETS") << (long)fieldInfo.RECVDROPPACKETS;
			cmd <<
				SAPos("SENDERRORPACKETS") <<
				(long)fieldInfo.SENDERRORPACKETS;
			cmd << SAPos("SENDDROPPACKETS") << (long)fieldInfo.SENDDROPPACKETS;
#endif

			// 			char strQWordBuf[21];
			// 			fieldInfo.SENDPACKETS.getString(strQWordBuf);
			// 			cmd.Param("SENDPACKETS").setAsNumeric() = strQWordBuf; //(QWORD)fieldInfo.SENDPACKETS;
			// 			printf("%s, %s \n", strQWordBuf, cmd.Param("SENDPACKETS").asNumeric().val);
			// 			
			// 			fieldInfo.SENDBYTES.getString(strQWordBuf);
			// 			cmd.Param("SENDBYTES").setAsNumeric() = strQWordBuf;//(QWORD)fieldInfo.SENDBYTES;
			// 			printf("%s, %s \n", strQWordBuf, cmd.Param("SENDBYTES").asNumeric().val);
			//
			// 			fieldInfo.RECVPACKETS.getString(strQWordBuf);
			// 			cmd.Param("RECVPACKETS").setAsNumeric() = strQWordBuf;//(QWORD)fieldInfo.RECVPACKETS;
			// 			printf("%s, %s \n", strQWordBuf, cmd.Param("RECVPACKETS").asNumeric().val);
			//
			// 			fieldInfo.RECVBYTES.getString(strQWordBuf);
			// 			cmd.Param("RECVBYTES").setAsNumeric() = strQWordBuf;//(QWORD)fieldInfo.RECVBYTES;
			// 			printf("%s, %s \n", strQWordBuf, cmd.Param("RECVBYTES").asNumeric().val);
			// 		
			// 			fieldInfo.RECVERRORPACKETS.getString(strQWordBuf);
			// 			cmd.Param("RECVERRORPACKETS").setAsNumeric() = strQWordBuf;//(QWORD)fieldInfo.RECVERRORPACKETS;
			// 			printf("%s, %s \n", strQWordBuf, cmd.Param("RECVERRORPACKETS").asNumeric().val);
			//
			// 			fieldInfo.RECVDROPPACKETS.getString(strQWordBuf);
			// 			cmd.Param("RECVDROPPACKETS").setAsNumeric() = strQWordBuf;//(QWORD)fieldInfo.RECVDROPPACKETS;
			// 			printf("%s, %s \n", strQWordBuf, cmd.Param("RECVDROPPACKETS").asNumeric().val);
			//
			// 			fieldInfo.SENDERRORPACKETS.getString(strQWordBuf);
			// 			cmd.Param("SENDERRORPACKETS").setAsNumeric() = strQWordBuf;//(QWORD)fieldInfo.SENDERRORPACKETS;
			// 			printf("%s, %s \n", strQWordBuf, cmd.Param("SENDERRORPACKETS").asNumeric().val);
			//
			// 			fieldInfo.SENDDROPPACKETS.getString(strQWordBuf);
			// 			cmd.Param("SENDDROPPACKETS").setAsNumeric() = strQWordBuf;//(QWORD)fieldInfo.SENDDROPPACKETS;
			// 			printf("%s, %s \n", strQWordBuf, cmd.Param("SENDDROPPACKETS").asNumeric().val);
			// 			
			//cmd << SAPos("SENDPACKETS")		<< (long)1;//
			//cmd << SAPos("SENDBYTES")		<< (long)1;//(QWORD)fieldInfo.SENDBYTES;
			//cmd << SAPos("RECVPACKETS")		<< (long)1;//(QWORD)fieldInfo.RECVPACKETS;
			//cmd << SAPos("RECVBYTES")		<< (long)1;//(QWORD)fieldInfo.RECVBYTES;
			cmd.Execute();
			m_sqlConnect->Commit();
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

void CStatusSubscriber::InsertRtnDBQueryAccessLog(
	const CFTDRtnDBQueryField &fieldInfo)
{
	if (0 == g_nStartParaWrtDB)
	{
		try
		{
			if (!connectDB())
			{
				return;
			}
			ScopeLock<CMutex> scopelock(m_sqlMutex);
			SACommand cmd;
			cmd.setConnection(m_sqlConnect);
			cmd.setCommandText(
					"insert into t_AccessLogStatInfo \
							   (ObjectID, AttrType, MonDate, MonTime, DBQueryResult) values \
							   (:ObjectID,:AttrType,:MonDate,:MonTime,:DBQueryResult)  ");
			cmd << SAPos("ObjectID") << fieldInfo.ObjectID;
			cmd << SAPos("AttrType") << fieldInfo.AttrType;
			cmd << SAPos("MonDate") << fieldInfo.MonDate;
			cmd << SAPos("MonTime") << fieldInfo.MonTime;
			cmd << SAPos("DBQueryResult") << fieldInfo.DBQueryResult;
			cmd.Execute();
			m_sqlConnect->Commit();
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

CStatusSubscriberSkeleton::CStatusSubscriberSkeleton(
	CStatusSubscriber *pParantHandler,
	int nFlowSeq) :
	m_nSeries(nFlowSeq),
	m_pStatusSubHandler(pParantHandler)
{
	char buffer[30];

	sprintf(buffer, "oracleflow%d", nFlowSeq - 1);
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

void CStatusSubscriber::UpdateParticTrade2DbByTimer(void)
{
	if (!connectDB())
	{
		return;
	}
	ScopeLock<CMutex> scopelock(m_sqlMutex);
	SACommand cmd;
	cmd.setConnection(m_sqlConnect);

	map<string, CLatestOrderOfParticipation>::iterator	m_Iter;
	for (m_Iter = m_mapPatMemOrderCnt.begin();
		 m_Iter != m_mapPatMemOrderCnt.end();
		 m_Iter++)
	{
		CLatestOrderOfParticipation &latParOrd = m_Iter->second;

		//新增数据
		if (latParOrd.setShdInsert.size() > 0)
		{
			set<string>::iterator s_Iter;
			for (s_Iter = latParOrd.setShdInsert.begin();
				 s_Iter != latParOrd.setShdInsert.end();
				 s_Iter++)
			{
				if (latParOrd.mp_sField.find(
						*s_Iter) == latParOrd.mp_sField.end())
				{
					continue;
				}

				CFTDRtnParticTradeOrderStatesField	&sRtn = latParOrd.
					mp_sField[*s_Iter];

				//insert a new record to db
				if (0 == g_nStartParaWrtDB)
				{
					try
					{
						cmd.setCommandText(
								"insert into t_syspartictradeorderstates \
										   (ParticipantID, UserID,MonDate,MonTime,StaticWidth,FrontID,OrderCount,CancleCount,QueryCount,TradeCount,TradeMoney,  \
										   OrderCntMax, CancleCntMax,QueryCntMax,TradeCntMax,TradeMoneyMax) values \
										   (:ParticipantID,:UserID,:MonDate,:MonTime,:StaticWidth,:FrontID,:OrderCount,:CancleCount, :QueryCount, :TradeCount, :TradeMoney, \
										   :OrderCntMax, :CancleCntMax,:QueryCntMax,:TradeCntMax,:TradeMoneyMax) ");

						cmd << SAPos("ParticipantID") << sRtn.ParticipantID;
						cmd << SAPos("UserID") << sRtn.UserID;
						cmd << SAPos("MonDate") << sRtn.MonDate;
						cmd << SAPos("MonTime") << sRtn.MonTime;
						cmd << SAPos("StaticWidth") << (long)sRtn.StaticWidth;
						cmd << SAPos("FrontID") << (long)sRtn.FrontID;
						cmd << SAPos("OrderCount") << (long)sRtn.OrderCount;
						cmd << SAPos("CancleCount") << (long)sRtn.CancleCount;

						cmd << SAPos("QueryCount") << (long)sRtn.QueryCount;
						cmd << SAPos("TradeCount") << (long)sRtn.TradeCount;
						cmd << SAPos("TradeMoney") << (long)sRtn.TradeMoney;

						cmd << SAPos("OrderCntMax") << (long)sRtn.OrderCntMax;
						cmd << SAPos("CancleCntMax") << (long)sRtn.CancleCntMax;

						cmd << SAPos("QueryCntMax") << (long)sRtn.QueryCntMax;
						cmd << SAPos("TradeCntMax") << (long)sRtn.TradeCntMax;
						cmd <<
							SAPos("TradeMoneyMax") <<
							(long)sRtn.TradeMoneyMax;

						cmd.Execute();
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

			latParOrd.setShdInsert.clear();
		}

		//更新数据
		if (latParOrd.setSdUpdate.size() > 0)
		{
			set<string>::iterator s_Iter;
			for (s_Iter = latParOrd.setSdUpdate.begin();
				 s_Iter != latParOrd.setSdUpdate.end();
				 s_Iter++)
			{
				if (latParOrd.mp_sField.find(
						*s_Iter) == latParOrd.mp_sField.end())
				{
					continue;
				}

				CFTDRtnParticTradeOrderStatesField	&sRtn = latParOrd.
					mp_sField[*s_Iter];

				//更新数据库
				if (0 == g_nStartParaWrtDB)
				{
					try
					{
						cmd.setCommandText(
								"update t_syspartictradeorderstates  \
										   set StaticWidth=:1,OrderCount=:2,CancleCount=:3,QueryCount=:4,TradeCount=:5,TradeMoney=:6, \
										   OrderCntMax=:7, CancleCntMax=:8,QueryCntMax=:9,TradeCntMax=:10,TradeMoneyMax=:11 \
										   where ParticipantID =:12 and UserID=:13 ");

						cmd << (long)sRtn.StaticWidth;
						cmd << (long)sRtn.OrderCount;
						cmd << (long)sRtn.CancleCount;
						cmd << (long)sRtn.QueryCount;
						cmd << (long)sRtn.TradeCount;
						cmd << (long)sRtn.TradeMoney;
						cmd << (long)sRtn.OrderCntMax;
						cmd << (long)sRtn.CancleCntMax;
						cmd << (long)sRtn.QueryCntMax;
						cmd << (long)sRtn.TradeCntMax;
						cmd << (long)sRtn.TradeMoneyMax;

						cmd << sRtn.ParticipantID;
						cmd << sRtn.UserID;

						cmd.Execute();
						m_sqlConnect->Commit();
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
		}

		m_sqlConnect->Commit();
	}
}

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

	//init cutline
	try
	{
		if (!connectDB())
		{
			return;
		}
		ScopeLock<CMutex> scopelock(m_sqlMutex);
		SACommand cmd;
		cmd.setConnection(m_sqlConnect);

		string sql = "select * from T_Systradeorderrttcutline Order By Mondate Desc, Montime Desc ";

		// 		string sql = "Select T.*, nvl(R.Cnt, 0) as cnt  \
		// 					 From T_Systradeorderrttcutline T left join  \
		// 					 (Select mondate, count(rowid) as cnt From T_Systradefrontorderrttstat Group By Mondate) R  \
		// 					 on T.Mondate = R.mondate  \
		// 					 Order By t.Mondate Desc, t.Montime Desc ";
		cmd.setCommandText(sql.data());
		cmd.Execute();

		g_bChangeCutLineNextDay = false;

		//如果数据库中有数据
		while (cmd.FetchNext())
		{
			strLastDate = (const char *)cmd.Field("MonDate").asString();
			strCutLine = (const char *)cmd.Field("OrderRttCutLine").asString();
			printf("has got the cutline from db\n");
			fflush(stdout);

			//如果数据库中最新的是明天
			if (strLastDate > strToday)
			{
				g_bChangeCutLineNextDay = true;
				continue;
			}

			//数据库中的日期较新
			for (int i = 0; i < 8; i++)
			{
				g_nRttCutLine[i] = (unsigned int) -1;
			}

			if (0 == strCutLine.length())
			{
				break;
			}

			const char	*p = strCutLine.data();
			int i = 0;
			while (p != NULL && i < 8)
			{
				g_nRttCutLine[i] = atoi(p);
				p = strchr(p, ',');
				if (p != NULL)
				{
					p++;
					i++;
				}
			}

			break;
		}

		//notify front
		{
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

bool CStatusSubscriber::InsertNewCutLine2DB(
	const char	*pStrDate,
	const char	*pStrUser,
	const char	*pStrCutLine)
{
	string strLatestDayInCutLine;
	string strLatestDayInRttOrder;
	char strToday[16];
	char strRightNow[16];

	int nRttCnt = 0;

	if (pStrDate == NULL || false == CDate::IsValid(pStrDate))
	{
		return false;
	}

	time_t timep;
	time(&timep);

	struct tm tm_time;
	LocalTime(&timep, &tm_time);
	sprintf(
		strRightNow,
		"%02d:%02d:%02d",
		tm_time.tm_hour,
		tm_time.tm_min,
		tm_time.tm_sec);

	//获取当前交易日
	if (g_strTradeDay == "")
	{
		sprintf(
			strToday,
			"%d%02d%02d",
			tm_time.tm_year + 1900,
			tm_time.tm_mon + 1,
			tm_time.tm_mday);
	}
	else
	{
		sprintf(strToday, "%s", g_strTradeDay.data());
	}

	//获得内存中rtt统计个数
	nRttCnt = g_OrderRttAnalysis->GetOrderRttSum(0, NULL);

	try
	{
		if (!connectDB())
		{
			//已经打印错误信息
			return false;
		}
		ScopeLock<CMutex> scopelock(m_sqlMutex);
		SACommand cmd;
		cmd.setConnection(m_sqlConnect);

		string sql = "SELECT MAX(TO_NUMBER (MONDATE)) AS MONDATE FROM T_SYSTRADEORDERRTTCUTLINE";
		cmd.setCommandText(sql.data());
		cmd.Execute();

		//如果数据库中有数据
		while (cmd.FetchNext())
		{
			strLatestDayInCutLine = (const char *)cmd.Field("MonDate").asString();
			printf("has got the cutline from db\n");
			fflush(stdout);
			break;
		}

		if (strLatestDayInCutLine > pStrDate)
		{
			return false;
		}

		sql = "SELECT MAX(TO_NUMBER(MONDATE)) AS MONDATE FROM T_SYSTRADEFRONTORDERRTTSTAT";
		cmd.setCommandText(sql.data());
		cmd.Execute();

		//如果数据库中有数据
		while (cmd.FetchNext())
		{
			strLatestDayInRttOrder = (const char *)cmd.Field("MonDate").asString();
			printf("has got the orderrtt from db\n");
			fflush(stdout);
			break;
		}

		string strInsertDay;

		//异常：要设置的日期先与数据库中已有的统计日期
		if (strLatestDayInRttOrder > pStrDate)
		{
			return false;
		}

		//这一天已经有cutline使用了，只能从第二天生效
		else if (strLatestDayInRttOrder == pStrDate
			 ||	 (0 == strcmp(strToday, pStrDate) && nRttCnt > 0))	//当前交易日已有rtt统计
		{
			//date + 1
			CDate thDay(pStrDate);
			thDay++;
			strInsertDay = thDay.ToString();
		}
		else
		{
			strInsertDay = pStrDate;
		}

		if (strInsertDay == strLatestDayInCutLine)
		{
			//update
			sql = "update T_SYSTRADEORDERRTTCUTLINE set MonTime = :2 , UserName = :3, OrderRttCutLine = :4 where MonDate = :1";
		}
		else if (strInsertDay > strLatestDayInCutLine)
		{
			//insert
			sql = "insert into T_SYSTRADEORDERRTTCUTLINE (MonDate, MonTime, UserName, OrderRttCutLine) values(:1, :2, :3, :4)";
		}
		else
		{
			//error, for debug set breakpoint here
			printf(
				"error, set cutline the insertday = %s, the latest day in db %s\n",
				strInsertDay.data(),
				strLatestDayInCutLine.data());
			return false;
		}

		cmd.setCommandText(sql.data());
		cmd << strInsertDay.data();
		cmd << strRightNow;
		cmd << pStrUser;
		cmd << pStrCutLine;

		cmd.Execute();
		m_sqlConnect->Commit();
	}

	catch(SAException & ex)
	{
		print_errmsg(
			__FILE__,
			__FUNCTION__,
			__LINE__,
			(const char *)ex.ErrText());
	}

	InitTradeOrderCutLine();

	return true;
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
	strftime(
		g_szTimeBuffer,
		sizeof(g_szTimeBuffer),
		"%H:%M:%S",
		&tm_time);

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



bool CWriteDBThread::InitInstance(void)
{
	printf("CWriteDBThread[%d] Started!\n", m_nThreadID);
	return true;
}

void CWriteDBThread::ExitInstance(void)
{
	printf("CWriteDBThread[%d] Ended!\n", m_nThreadID);
}

void CWriteDBThread::Run(void)
{
#ifdef PRINT_DEBUG
	printf(
		"运行文件 CWriteDBThread::Run： %s 行数：%d \n",
		__FILE__,
		__LINE__);
#endif

	CFTDRtnHistoryObjectAttrField fieldInfo;
	int count = 0;

	while (true)
	{
		if (0 == g_nStartParaWrtDB)
		{
			while(pStatusSub->getObjectAttr(fieldInfo))
			{
				try
				{
					if (!pStatusSub->IsConnectDB())
					{
						return;
					}
					ScopeLock<CMutex> scopelock(pStatusSub->getSqlLock());
					SACommand cmd( pStatusSub->getSAConnection(),
								"insert into t_SysHistoryObjectAttr \
						(MonDate,BeginTime,EndTime,ObjectID,AttrType,ValueType,FirstValue,EndValue,AvgValue,MinValue,MaxValue,ValueCount) values \
						(:MonDate,:BeginTime,:EndTime,:ObjectID,:AttrType,:ValueType,:FirstValue,:EndValue,:AvgValue,:MinValue,:MaxValue,:ValueCount) ");

					cmd << SAPos("MonDate") << fieldInfo.MonDate;
					cmd << SAPos("BeginTime") << fieldInfo.BeginTime;
					cmd << SAPos("EndTime") << fieldInfo.EndTime;
					cmd << SAPos("ObjectID") << fieldInfo.ObjectID;
					cmd << SAPos("AttrType") << fieldInfo.AttrType;
					cmd << SAPos("ValueType") << (long)fieldInfo.ValueType;
					cmd << SAPos("FirstValue") << fieldInfo.FirstValue;
					cmd << SAPos("EndValue") << fieldInfo.EndValue;
					cmd << SAPos("AvgValue") << fieldInfo.AvgValue;
					cmd << SAPos("MinValue") << fieldInfo.MinValue;
					cmd << SAPos("MaxValue") << fieldInfo.MaxValue;
					cmd << SAPos("ValueCount") << (long)fieldInfo.ValueCount;

					cmd.Execute();
					count++;
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
			if( count > 0 )
			{
				pStatusSub->getSAConnection()->Commit();
				count = 0;
			}
		}
		OSSleep(1);
	}
}

