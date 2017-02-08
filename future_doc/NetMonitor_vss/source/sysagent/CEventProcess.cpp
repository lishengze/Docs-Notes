///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CEventProcess.cpp
///@brief	实现了采集代理处理日志中消息的类
///@history
///20080715	周建军		修订注释
#include "systools.h"
#include "CEventProcess.h"
#include "CachedFileFlow.h"

extern CFTDCSession *g_pCounterFtdSession;	// FTD下传请求到事件分析的唯一会话
///@key	主机名称
///@value	该主机上的进程对应编号
map<string, int> g_mHostIdRlt;				// 保存主机名与应用ID的映射关系
#define DUP_AND_SEND_PKG	m_pkgSend.DupPackage((CPackage *)pFTDCPackage); \
	memcpy(																	\
		(char *)m_pkgSend.GetFTDCHeader(),									\
		pFTDCPackage->GetFTDCHeader(),										\
		sizeof(TFTDCHeader));												\
	if (g_pCounterFtdSession != NULL)										\
	{																		\
		g_pCounterFtdSession->SendRequestPackage(&m_pkgSend);				\
	}																		\
	else																	\
	{																		\
		printf("DUP_AND_SEND_PKG Wrong !\n");								\
	}

#define SEND_PKG			if (g_pCounterFtdSession != NULL) \
	{														  \
		g_pCounterFtdSession->SendRequestPackage(&m_pkgSend); \
	}														  \
	else													  \
	{														  \
		printf("DUP_AND_SEND_PKG Wrong !\n");				  \
	}

extern char g_mTradeDay[9];
CStringIdMap g_mStringIDMap;

CIPAnalysis::CIPAnalysis(char *pConfigPath)
{
	int i;
	char path[100];
	sprintf(path, "%s/%s", pConfigPath, "SystemConfig.xml");

	CXMLDoc *pXMLDoc;
	CXMLNode *pXMLRoot;
	pXMLDoc = new CXMLDoc();
	pXMLDoc->read(path);
	pXMLRoot = pXMLDoc->getRootNode();

	XMLNodeType NodeType = XMLTag;
	CXMLNode *pNode = pXMLRoot->findNode(
			NodeType,
			"SessionIpConfig",
			NULL,
			NULL);
	if (pNode == NULL)
	{
		printf("Can not find <SessionIpConfig> in file %s\n", path);
		fflush(stdout);
		exit(0);
	}

	CXMLNodeList *pNodeList = pNode->getNodeList();

	for (i = 0; i < pNodeList->size(); i++)
	{
		CXMLNode *pNodeAttr = (*pNodeList)[i];
#ifdef PRINT_DEBUG
		printf("%s\n", pNodeAttr->findProperty("name"));
#endif

		int m = g_mStringIDMap.getStringId(pNodeAttr->findProperty("name"));
		CXMLNodeList *pNodeIpList = pNodeAttr->getNodeList();
		for (int j = 0; j < pNodeIpList->size(); j++)
		{
			CXMLNode *pNodeIp = (*pNodeIpList)[j];
#ifdef PRINT_DEBUG
			printf("ip %s\n", pNodeIp->findProperty("value"));
#endif
			m_mapIpType[string(pNodeIp->findProperty("value"))] = m;
		}
	}

	pNode = pXMLRoot->findNode(NodeType, "HostIdRlts", NULL, NULL);
	if (pNode == NULL)
	{
		printf(
			"Notify : Can not find <HostIdRlts> in file %s, configfile maybe wrong!! \n",
			path);
		fflush(stdout);
	}
	else
	{
		CXMLNodeList *pNodeList = pNode->getNodeList();
		for (i = 0; i < pNodeList->size(); i++)
		{
			CXMLNode *pNodeAttr = (*pNodeList)[i];
			g_mHostIdRlt[string(pNodeAttr->findProperty("Host"))] = atoi(
					pNodeAttr->findProperty("item"));
		}
	}

#ifdef PRINT_DEBUG
	for (map<string, int>::iterator it = m_mapIpType.begin();
		 it != m_mapIpType.end();
		 it++)
	{
		printf(
			"attr:%s(%d) ip %s\n",
			g_mStringIDMap.getString(it->second),
			it->second,
			it->first.c_str());
	}

	// 	i = g_mStringIDMap.getStringId(APPATTRLANSESSIONSIZE);
	// 	m_mapIpType[string("172.16.")] = i;
	// 	i = g_mStringIDMap.getStringId(APPATTRWANSESSIONSIZE);
	// 	m_mapIpType[string("10.")] = i;
	// 	m_mapIpType[string("192.168.")] = i;
#endif
	delete pXMLDoc;
}

int CIPAnalysis::getIpTypeID(char *pIpAddr)
{
	for (map<string, int>::iterator it = m_mapIpType.begin();
		 it != m_mapIpType.end();
		 it++)
	{
		if (memcmp(pIpAddr, it->first.c_str(), it->first.size()) == 0)
		{
			return it->second;
		}
	}

	return 0;
}

void CEventProcess::putEventReport(
	char *pObjectID,
	char *pMonDate,
	char *pMonTime,
	char *pEventName,
	char *pEventDes)
{
	//MdLogin 5 Success 172.16.1.68 zou.wenjun,front=1,session=-1751449598,message=正确
	//MdLogout 5 Success 172.16.1.68 zou.wenjun,front=1,session=-,message=
	int eventLevel = 5;

	/// 形成标准事件向后派发，如果事件的值过长则分包派发
	m_pkgSend.PreparePackage(
			FTD_TID_RtnSyslogEventTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_eventField.ObjectID = pObjectID;
	m_eventField.ProcessFlag = "L";
	m_eventField.MonDate = pMonDate;
	m_eventField.MonTime = pMonTime;
	m_eventField.OccurDate = pMonDate;
	m_eventField.OccurTime = pMonTime;
	m_eventField.EventName = pEventName;

	if (pEventDes == NULL)
	{
		m_eventField.WarningLevel = "info";
		FTDC_ADD_FIELD(&m_pkgSend, &m_eventField);
		SEND_PKG;
	}
	else
	{
		char *pId = pEventDes;
		char *pDes = pEventDes;
		while (pId != NULL && *pId == ' ')
		{
			pId++;
		}

		if (isdigit(*pId) && (*(pId + 1) == ' ' || *(pId + 1) == '\0')) //该事件含有事件级别字段
		{
			eventLevel = *pId - '0';
			pDes = pId + 2;
		}

		while (pDes != NULL && *pDes == ' ')
		{
			pDes++;
		}

		if (eventLevel == 5)
		{
			m_eventField.WarningLevel = "info";
		}
		else if (eventLevel == 4)
		{
			m_eventField.WarningLevel = "Warning";
		}
		else if (eventLevel == 3)
		{
			m_eventField.WarningLevel = "Error";
		}
		else if (eventLevel == 2 || eventLevel == 1)
		{
			m_eventField.WarningLevel = "Fatal";
		}
		else if (eventLevel == 6)
		{
			m_eventField.WarningLevel = "debug";
		}
		else
		{
			m_eventField.WarningLevel = "unknown";
		}

		///如果eventname为Session并且其后的描述出现disconnected，则构造出一个disconnected事件
		bool bRepeatFlag = false;
		if (strcmp(m_eventField.EventName.getValue(), "Session") == 0)
		{
			if (strstr(pDes, "disconnected") != NULL)
			{
				bRepeatFlag = true;
			}
		}

		///pDes开始到结束赋值给事件描述字段
		/*
			在汉字编码中，一个汉字有两个字节组成，汉字编码区间分别是：第一字节编码【0xb0 ~ 0xf7】第二个字节编码【0xa1 ~ oxfe】,
			所以判断汉字代码如下：
			if(s[i]>=(char)0xb0 && s[i]<=(char)0xf7 && s[i+1]>=(char)0xa1 && s[i+1]<=(char)0xfe)
		*/
		while (strlen(pDes) > (sizeof(CTypeDescriptionType) - 1))
		{
			m_eventField.EventDes = pDes;
			m_eventField.ProcessFlag = "C";
			pDes = pDes + sizeof(CTypeDescriptionType) - 1;
			if ((unsigned char)pDes[0] >= 0xa1 && (unsigned char)pDes[0] <= 0xfe)
			{
				pDes--;

				char *pStr = (char *)m_eventField.EventDes.getValue();
				pStr[strlen(pStr) - 1] = '\0';
			}

			FTDC_ADD_FIELD(&m_pkgSend, &m_eventField);
			if (bRepeatFlag)
			{
				string	tmpEventName = m_eventField.EventName.getValue();
				m_eventField.EventName = "disconnected";
				FTDC_ADD_FIELD(&m_pkgSend, &m_eventField);
				m_eventField.EventName = tmpEventName.c_str();
			}
		}

		m_eventField.EventDes = pDes;
		m_eventField.ProcessFlag = "L";
		FTDC_ADD_FIELD(&m_pkgSend, &m_eventField);
		if (bRepeatFlag)
		{
			m_eventField.EventName = "disconnected";
			FTDC_ADD_FIELD(&m_pkgSend, &m_eventField);
		}

		SEND_PKG;
	}

	return;
}

map<string, CLoginSuccessValue> g_mapMdSession;

//nFrontID[pID], nSessionID[nTkernelId], nIpTypeID[pDCName]
void CEventProcess::processMdLoginSuccess(
	const char	*pDCName,
	char *pProgram,
	int nTkernelId,
	char *pValue)
{
	if (pDCName == NULL || pProgram == NULL || pValue == NULL) return;
	//5 Success 172.16.1.68 zou.wenjun,front=1,session=-1751449598,message=正确
	char *pID;

	//5 Success 172.16.1.68 zou.wenjun,front=1,session=-1751449598,message=正确
	char *pResult;

	//5 Success 172.16.1.68 zou.wenjun,front=1,session=-1751449598,message=正确
	char *pIP;

	//5 Success 172.16.1.68 zou.wenjun,front=1,session=-1751449598,message=正确
	char *pUser;
	pID = pValue;
	while (*pID == ' ')
	{
		pID++;
	}

	pResult = strchr(pID, ' ');
	if (pResult == NULL)
	{
		return;
	}

	*pResult = '\0';
	pResult++;

	pIP = strchr(pResult, ' ');
	if (pIP == NULL)
	{
		return;
	}

	*pIP = '\0';
	pIP++;

	if (strcmp(pResult, "Success") != 0)
	{
		return;
	}

	pUser = strchr(pIP, ' ');
	if (pUser == NULL)
	{
		return;
	}

	*pUser = '\0';
	pUser++;

	char *p = strchr(pUser, ',');
	if (p == NULL)
	{
		return;
	}

	*p = '\0';
	g_mapMdSession[string(pUser)] = CLoginSuccessValue(
			atoi(pID),
			nTkernelId,
			g_mStringIDMap.getStringId(pDCName));
}

void CEventProcess::processMdLogOutSuccess(
	const char	*pDCName,
	char *pProgram,
	int nTkernelId,
	char *pValue)
{
	if (pDCName == NULL || pProgram == NULL || pValue == NULL) return;
	//5 Success 172.16.1.68 zou.wenjun,front=1,session=-,message=
	char *pID;

	//5 Success 172.16.1.68 zou.wenjun,front=1,session=-,message=
	char *pResult;

	//5 Success 172.16.1.68 zou.wenjun,front=1,session=-,message=
	char *pIP;

	//5 Success 172.16.1.68 zou.wenjun,front=1,session=-,message=
	char *pUser;
	pID = pValue;
	while (*pID == ' ')
	{
		pID++;
	}

	pResult = strchr(pID, ' ');
	if (pResult == NULL)
	{
		return;
	}

	*pResult = '\0';
	pResult++;

	pIP = strchr(pResult, ' ');
	if (pIP == NULL)
	{
		return;
	}

	*pIP = '\0';
	pIP++;

	if (strcmp(pResult, "Success") != 0)
	{
		return;
	}

	pUser = strchr(pIP, ' ');
	if (pUser == NULL)
	{
		return;
	}

	*pUser = '\0';
	pUser++;

	char *p = strchr(pUser, ',');
	if (p == NULL)
	{
		return;
	}

	*p = '\0';

	map<string, CLoginSuccessValue>::iterator it = g_mapMdSession.find(
			string(pUser));
	if (it != g_mapMdSession.end())
	{
		g_mapMdSession.erase(it);
	}
}

void CEventProcess::getMdSessionSize(void)
{
	char mTime[10];
	time_t	timep;
	time(&timep);

	struct tm tm_time;
	LocalTime(&timep, &tm_time);
	sprintf(mTime, "%02d:%02d:%02d", tm_time.tm_hour, tm_time.tm_min, tm_time.tm_sec);

	map<CTkernelIdKey, int> mapMdStats; //
	map<string, CLoginSuccessValue>::const_iterator it = g_mapMdSession.begin();
	while (it != g_mapMdSession.end())
	{
		mapMdStats[CTkernelIdKey(
				it->second.m_nSessionID,
				g_mStringIDMap.getString(it->second.m_nIpTypeID))]++;
		it++;
	}

	m_pkgSend.PreparePackage(
			FTD_TID_RtnObjectAttrTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDRtnObjectAttrField	fieldInfo;
	fieldInfo.MonDate = g_mTradeDay;
	fieldInfo.MonTime = mTime;
	fieldInfo.ValueType = INT_ATTR;
	fieldInfo.AttrType = APPATTRMDSESSIONSIZE;
	for (map<CTkernelIdKey, int>::iterator rstit = mapMdStats.begin();
		 rstit != mapMdStats.end();
		 rstit++)
	{
		sprintf(
			(char *)fieldInfo.ObjectID.getValue(),
			"%s.%s.%s.%d",
			rstit->first.m_sDCName.c_str(),
			"app",
			"mdkernel",
			rstit->first.m_nTkernelID);
		sprintf((char *)fieldInfo.AttrValue.getValue(), "%d", rstit->second);
		FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);
	}

	if (m_pkgSend.Length() >= sizeof(CFTDRtnObjectAttrField))
	{
		SEND_PKG;
	}
}

void CEventProcess::getPeriodStats(void)
{
	getMdSessionSize();
}
