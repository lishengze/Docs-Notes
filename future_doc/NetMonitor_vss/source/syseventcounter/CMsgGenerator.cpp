/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CMsgGenerator.cpp
///@brief	定义了生成消息文件的工具类
///@history
///20111214	晏鹤春	创建该文件
///20131009 晏鹤春  变更号GM_13100901，告警事件消息增加合并推送功能
#include "CMsgGenerator.h"

CMutex	g_lockMsgFile;				// 消息文件锁
CMsgGenerator::CMsgGenerator(void)
{
	m_DateTime.OpenDrift();
	m_bEventFlag = true;
	m_bAttrFlag = true;
	m_bBusinessEventFlag = true;
	m_bNetworkEventFlag = true;
	//m_bPerHourMsgEnable = false;
}

CMsgGenerator::~CMsgGenerator(void)
{
}

bool CMsgGenerator::InitInstance(void)
{
	printf("CMsgGenerator thread Started!\n");
	return true;
}

void CMsgGenerator::ExitInstance(void)
{
	printf("CMsgGenerator thread Ended!\n");
}

void CMsgGenerator::Run(void)
{
	CEventInfo	EventInfo;
	int iCount = 0;
	while (1)
	{
		if (m_bEventFlag)
		{
			/// 派发事件信息
			while (m_EventList.get(EventInfo))
			{
				// just for testing
				/*				printf("EventInfo.m_event: \n\tEvendID: %d\n\tObjectID: %s\n\tIPAddress: %s\n\tEventName: %s\n\tEventNum: %d\n\tEventType: %d\n\tEventDes: %s\n\tCNetAttrTypeType: %s\n", 
				EventInfo.m_event.EvendID.getValue(),
				EventInfo.m_event.ObjectID.getValue(),
				EventInfo.m_event.IPAddress.getValue(),
				EventInfo.m_event.EventName.getValue(),
				EventInfo.m_event.EventNum.getValue(),
				EventInfo.m_event.EventType.getValue(),
				EventInfo.m_event.EventDes.getValue(),
				EventInfo.m_event.FullEventName.getValue());*/
				DispatchEvent(EventInfo);
			}

			/// 尝试派发队列中的事件信息
			if (iCount % 1000 == 0)
			{
				ScanMsgDelayList();
				ScanMsgMergeList();			/// 变更GM_13100901
				ScanPollingDownList();		// add by cao.ning
			}

		}

		if (m_bAttrFlag)
		{
			/// 尝试输出指标信息
			if (iCount % 25 == 0)
			{
				CheckObjectAttr();
			}
		}

		++iCount;
		SleepMs(2);
	}
}

void CMsgGenerator::AddObjectAttr(CFTDRtnHistoryObjectAttrField &fieldInfo)
{
	char szBuf[512] = "";
	sprintf(
		szBuf,
		"%s:%s",
		(char *)fieldInfo.ObjectID.getValue(),
		(char *)fieldInfo.AttrType.getValue());

	map<string, long>::iterator mapIt = m_AttrValue.find(szBuf);
	if (mapIt != m_AttrValue.end())
	{
		m_AttrValue[szBuf] = (long)fieldInfo.EndValue;
	}
}

/// 将携带发生次数及补充信息的告警事件信息保存入m_EventList容器
void CMsgGenerator::AddEvent(
	CFTDRtnWarningEventField &EventField,
	int iCount,
	char *info1,
	char *info2)
{
	int iType = 0;
	bool bNetworkEvent = false;
	if (strncmp(
		EventField.ObjectID.getValue(),
		DATACENTERPUDIAN,
		strlen(DATACENTERPUDIAN)) == 0
		||	strncmp(
		EventField.ObjectID.getValue(),
		DATACENTERZHANGJ,
		strlen(DATACENTERZHANGJ)) == 0
		||	strncmp(
		EventField.ObjectID.getValue(),
		DATACENTERBEIJING,
		strlen(DATACENTERBEIJING)) == 0)
	{
		bNetworkEvent = true;
		iType = 2;	// 标计网络事件
	}
	else
	{
		iType = 1;	// 标计业务事件
	}

	if ((bNetworkEvent && m_bNetworkEventFlag)
		|| (!bNetworkEvent && m_bBusinessEventFlag))
	{
		m_EventList.add(CEventInfo(EventField, iCount, iType, info1, info2, ""));
		printf(
			"Event[%s %s %d %s] added into EventList\n",
			(char *)EventField.ObjectID.getValue(),
			(char *)EventField.EventName.getValue(),
			EventField.EvendID.getValue(),
			(char *)EventField.WarningLevel.getValue()
			);
	}
	else
	{
		printf(
			"Event[%s %s %d %s] drop, BusinessFlag [%s] NetworkFlag[%s]\n",
			(char *)EventField.ObjectID.getValue(),
			(char *)EventField.EventName.getValue(),
			EventField.EvendID.getValue(),
			(char *)EventField.WarningLevel.getValue(),
			m_bBusinessEventFlag == true ? "TRUE" : "FALSE",
			m_bNetworkEventFlag == true ? "TRUE" : "FALSE");
	}
}

void CMsgGenerator::RefreshObjectStatus(char *pObjectId, char *pEventName)
{
	map<string, int>::iterator	mapIt;

	for (mapIt = m_objgrpMap.begin(); mapIt != m_objgrpMap.end(); mapIt++)
	{
		int iRst = 1;	// 默认对象状态为OK
		list<string> &objexcList = m_objgrpExcList[mapIt->first];
		list<string> &objincList = m_objgrpIncList[mapIt->first];
		list<string>::iterator	listIt;

		/// 优先去掉排除对象
		if (objexcList.size() > 0 && iRst == 1)
		{
			for (listIt = objexcList.begin();
				listIt != objexcList.end();
				listIt++)
			{
				if (strstr(pObjectId, (*listIt).c_str()) != NULL ||
					strstr(pEventName, (*listIt).c_str()) != NULL )
				{
					iRst = 0;
					break;
				}
			}
		}

		/// 再检索是否为允许对象
		if (objincList.size() > 0 && iRst == 1)
		{
			iRst = 0;
			for (listIt = objincList.begin();
				listIt != objincList.end();
				listIt++)
			{
				if (strstr(pObjectId, (*listIt).c_str()) != NULL ||
					strstr(pEventName, (*listIt).c_str()) != NULL )
				{
					iRst = 1;
					break;
				}
			}
		}

		mapIt->second = iRst;
	}
}

void CMsgGenerator::RefreshLevelStatus(char *pLevel)
{
	map<string, int>::iterator	mapIt;

	for (mapIt = m_lvlgrpMap.begin(); mapIt != m_lvlgrpMap.end(); mapIt++)
	{
		int iRst = 1;
		list<string> &lvlexcList = m_lvlgrpExcList[mapIt->first];
		list<string> &lvlincList = m_lvlgrpIncList[mapIt->first];
		list<string>::iterator	listIt;
		if (lvlexcList.size() > 0 && iRst == 1)
		{
			for (listIt = lvlexcList.begin();
				listIt != lvlexcList.end();
				listIt++)
			{
				if (strncmp(pLevel, (*listIt).c_str(), (*listIt).length()) == 0)
				{
					iRst = 0;
					break;
				}
			}
		}

		if (lvlincList.size() > 0 && iRst == 1)
		{
			iRst = 0;
			for (listIt = lvlincList.begin();
				listIt != lvlincList.end();
				listIt++)
			{
				if (strncmp(pLevel, (*listIt).c_str(), (*listIt).length()) == 0)
				{
					iRst = 1;
					break;
				}
			}
		}

		mapIt->second = iRst;
	}
}

time_t CMsgGenerator::GetTimePassed(char *pDate, char *pTime)
{
	time_t	EventTime = m_DateTime.GetTimeSec(pDate, pTime);
	time_t	CurrTime = m_DateTime.GetCurrTimeSec();
	return CurrTime - EventTime;
}

/// 将目标事件信息进行初步分析过滤，寻找对应的消息组对象
void CMsgGenerator::DispatchEvent(CEventInfo EventInfo)
{
	// 已弃用，详见被注释的CPerHourMessage定义
	//if (strcmp(EventInfo.m_event.EventName.getValue(), "System_Timer") == 0)
	//{
	//	EventInfo.m_msggrp = "PerH_sub";
	//	EventInfo.m_type = 2;
	//	DispatchMsg(EventInfo);
	//	return ;
	//}

	CFTDRtnWarningEventField &EventField = EventInfo.m_event;
	/// 过滤对象名、事件名
	RefreshObjectStatus((char *)EventField.ObjectID.getValue(), (char *)EventField.EventName.getValue());
	/// 过滤事件级别
	RefreshLevelStatus((char *)EventField.WarningLevel.getValue());

	time_t	TimePassed = GetTimePassed(
		(char *)EventField.MonDate.getValue(),
		(char *)EventField.MonTime.getValue());
	bool bFlag = false;

	map<string, CFilterInfo>::iterator	filterInfoIt;
	for (filterInfoIt = m_filterInfo.begin();
		filterInfoIt != m_filterInfo.end();
		filterInfoIt++)
	{
		CFilterInfo &filterInfo = filterInfoIt->second;
		/// 过滤器匹配成功的话，为事件信息增加MsgGroup消息组信息,并尝试经消息组控制机制派发
		if (FilterMatch(filterInfo, TimePassed)
			&&	m_filterMsgMap.find(filterInfo.m_name) != m_filterMsgMap.end())
		{
			// match case
			list<string> &msgGrpList = m_filterMsgMap[filterInfo.m_name];
			list<string>::iterator	listIt;
			for (listIt = msgGrpList.begin();
				listIt != msgGrpList.end();
				listIt++)
			{
				EventInfo.m_msggrp = *listIt;
				/// 尝试派发补充好消息组信息的事件对象
				DispatchMsg(EventInfo);	
				bFlag = true;
			}
		}
	}

	if (bFlag == false)
	{
		printf(
			"Event[%s %s %d %s] no match\n",
			(char *)EventField.ObjectID.getValue(),
			(char *)EventField.EventName.getValue(),
			EventField.EvendID.getValue(),
			(char *)EventField.WarningLevel.getValue());
	}
}

void CMsgGenerator::ScanMsgDelayList(void)
{
	map<string, list<CEventInfo> >::iterator mapIt;
	for (mapIt = m_MsgDelayList.begin(); mapIt != m_MsgDelayList.end(); mapIt++)
	{
		if (mapIt->second.size() > 0)
		{
			map<string, CMsgGroupInfo>::iterator MsgGrpIt = m_msggrpInfo.find(
				mapIt->first);
			if (MsgGrpIt != m_msggrpInfo.end())
			{
				CMsgGroupInfo &MsgGroupInfo = MsgGrpIt->second;
				if (ShouldWork(MsgGroupInfo))
				{
					list<CEventInfo> &msgList = mapIt->second;
					list<CEventInfo>::iterator	listIt;
					for (listIt = msgList.begin();
						listIt != msgList.end();
						listIt++)
					{
						char szMsgKey[64];
						CEventInfo	&EventInfo = *listIt;
						CFTDRtnWarningEventField &EventField = EventInfo.
							m_event;

						sprintf(
							szMsgKey,
							"%s.%d",
							MsgGroupInfo.m_name.c_str(),
							EventField.EventNum.getValue());

						map<string, time_t>::iterator msgtimeIt = m_msgtimeMap.
							find(szMsgKey);

						if (msgtimeIt == m_msgtimeMap.end()
							||	MsgGroupInfo.m_sendgap <= 0
							||	(m_DateTime.GetCurrTimeSec() - msgtimeIt->second) >= MsgGroupInfo.m_sendgap)
						{
							GenMsg(EventInfo, MsgGroupInfo);
							m_msgtimeMap[szMsgKey] = m_DateTime.GetCurrTimeSec();
						}
						else
						{
							// drop
							printf(
								"Event[%s %s %d %s] drop, time gap [%d %d]\n",
								(char *)EventField.ObjectID.getValue(),
								(char *)EventField.EventName.getValue(),
								EventField.EvendID.getValue(),
								(char *)EventField.WarningLevel.getValue(),
								(
								m_DateTime.GetCurrTimeSec() -
								msgtimeIt->second
								),
								MsgGroupInfo.m_sendgap);
						}
					}

					msgList.clear();
				}
			}
		}
	}
}

void CMsgGenerator::ScanMsgMergeList(void)
{
	map<string, list<CEventInfo> >::iterator mapIt;
	for (mapIt = m_MsgMergeList.begin(); mapIt != m_MsgMergeList.end(); mapIt++)
	{
		string sKeyName = mapIt->first;
		list<CEventInfo> & EventList = mapIt->second;
		list<CEventInfo>::iterator listIt = EventList.begin();
		CEventInfo & EventInfo = *listIt;

		map<string, CMsgGroupInfo>::iterator MsgGrpIt = m_msggrpInfo.find(sKeyName.substr(0, sKeyName.find_first_of(":")));

		if (MsgGrpIt != m_msggrpInfo.end())
		{
			CMsgGroupInfo & MsgGroupInfo = MsgGrpIt->second;
			if (EventList.size() > 1)
			{
				/// 存在多条可合并事件,默认以首条事件优先输出
				EventInfo.m_objects = EventList.size();
				DumpMsg(EventInfo, MsgGroupInfo);
			}
			else
			{
				/// 无需合并，直接输出
				DumpMsg(EventInfo, MsgGroupInfo);
			}		
		}
	}
	m_MsgMergeList.clear();
}

// 扫描PollingDown队列中的事件，若时间满足，则合并事件后写入文件
void CMsgGenerator::ScanPollingDownList(void)
{
	// 如果发送时间为空，pollingdown事件不会存放在缓存中，已直接发送
	if (m_PollingDownSendTime.empty())
		return;

	// 首先判断是否到达发送时间
	if (m_DateTime.GetCurrTimeSec() >= m_NextSendTime)
	{
		CEventInfo	EventInfo;
		int MsgCount = 0;
		// 用于保存合并的事件Content部分
		string PollingDownMsgContent = "";
		// 从队列中取出事件
		while (m_PollingDownEventList.get(EventInfo))
		{
			// 将该事件的消息重构之后附加到合并消息之后
			GenPollingDownMsgContent(PollingDownMsgContent, EventInfo);
			++MsgCount;
			// 如果当前合并的事件数量已经超过限制或者缓冲区已清空，则写入文件
			if (MsgCount >= m_PollingDownMaxCount || m_PollingDownEventList.size() == 0)
			{
				string	msgGrpName = EventInfo.m_msggrp;
				map<string, CMsgGroupInfo>::iterator mapIt = m_msggrpInfo.find(msgGrpName);
				if (mapIt != m_msggrpInfo.end())
				{
					CMsgGroupInfo &MsgGroupInfo = mapIt->second;

					// 生成MsgID
					UINT64 newMessageID = GenMessageID(EventInfo.m_event.EvendID.getValue(), MsgGroupInfo.m_id);

					char *newMessageContent = new char[PollingDownMsgContent.size() + 1024];
					memset(newMessageContent, 0, PollingDownMsgContent.size() + 1024);

					// 对于PollingDown事件，SubjectId和Level是相同的
					sprintf(
						newMessageContent,
						"<Message MessageId=\"%llu\" SubjectId=\"%s\" Level=\"%d\" DumpDate=\"%s\" DumpTime=\"%s\" Content=\"Polling down事件列表:%s\" MaxRetry=\"%d\" RetrySpan=\"%d\" SenderId=\"%s\" />\r\n",
						newMessageID,
						MsgGroupInfo.m_subject.c_str(),
						MsgGroupInfo.m_level,
						m_DateTime.GetDateStr().c_str(),
						m_DateTime.GetTimeStr().c_str(),
						PollingDownMsgContent.c_str(),
						m_iMaxRetry,
						m_iRetrySpan,
						m_strSender.c_str());

					DumpSubjectMsg(newMessageContent, MsgGroupInfo.m_subject.c_str());

					PollingDownMsgContent = "";
					MsgCount = 0;
					delete newMessageContent;
				}
			}
		}

		// 计算下次发送时间
		UpdatePollingDownSendTime();
	}
}
///分析事件信息对应消息组的派发机制，如满足条件则进行消息输出
void CMsgGenerator::DispatchMsg(CEventInfo EventInfo)
{
	string	msgGrpName = EventInfo.m_msggrp;
	CFTDRtnWarningEventField EventField = EventInfo.m_event;
	map<string, CMsgGroupInfo>::iterator mapIt = m_msggrpInfo.find(msgGrpName);
	if (mapIt != m_msggrpInfo.end())
	{
		CMsgGroupInfo &MsgGroupInfo = mapIt->second;
		if (ShouldWork(MsgGroupInfo))
		{
			/// Time OK
			char szMsgKey[64];
			sprintf(
				szMsgKey,
				"%s.%d",
				msgGrpName.c_str(),
				EventField.EventNum.getValue());

			map<string, time_t>::iterator mapIt = m_msgtimeMap.find(szMsgKey);

			if (mapIt == m_msgtimeMap.end()
				||	MsgGroupInfo.m_sendgap <= 0
				||	(
				m_DateTime.GetCurrTimeSec() -
				mapIt->second
				) >= MsgGroupInfo.m_sendgap)
			{
				GenMsg(EventInfo, MsgGroupInfo);
				m_msgtimeMap[szMsgKey] = m_DateTime.GetCurrTimeSec();

				// just for testing
				printf(
					"Event[%s %s %d %s] generate message [%s %s]\n",
					(char *)EventField.ObjectID.getValue(),
					(char *)EventField.EventName.getValue(),
					EventField.EvendID.getValue(),
					(char *)EventField.WarningLevel.getValue(),
					(char *)EventField.MonDate.getValue(),
					(char *)EventField.MonTime.getValue());
			}
			else
			{
				// drop
				printf(
					"Event[%s %s %d %s] drop, time gap [%d %d]\n",
					(char *)EventField.ObjectID.getValue(),
					(char *)EventField.EventName.getValue(),
					EventField.EvendID.getValue(),
					(char *)EventField.WarningLevel.getValue(),
					(m_DateTime.GetCurrTimeSec() - mapIt->second),
					MsgGroupInfo.m_sendgap);
			}
		}
		else	// 如果当前事件发生的时刻不是出于对应的消息组定义的事件发送时刻，则进行额外的处理
		{
			/// Time invalid
			if (MsgGroupInfo.m_type == 0)	// 如果消息组的类别为0（只有Test_sub和NM_sub为1），则直接丢该事件
			{
				// drop
				printf(
					"Event[%s %s %d %s] drop, time valid [%s %s]\n",
					(char *)EventField.ObjectID.getValue(),
					(char *)EventField.EventName.getValue(),
					EventField.EvendID.getValue(),
					(char *)EventField.WarningLevel.getValue(),
					(char *)EventField.MonDate.getValue(),
					(char *)EventField.MonTime.getValue());

			}
			else
			{
				// 对于消息组类别不为0的时间，则根据配置中的IP地址和端口信息过滤条件进行过滤
				// 若符合过滤条件，则直接丢弃该事件，否则将事件缓存到事件队列中
				if (FilterIgnoreIpList(EventInfo))
				{
					// drop
					printf(
						"Event[%s %s %d %s] drop, time valid and in IgnoreIpList [%s %s]\n",
						(char *)EventField.ObjectID.getValue(),
						(char *)EventField.EventName.getValue(),
						EventField.EvendID.getValue(),
						(char *)EventField.WarningLevel.getValue(),
						(char *)EventField.MonDate.getValue(),
						(char *)EventField.MonTime.getValue());
				}
				else
				{
					// 延迟推送的消息存入队列等待时间合适时发送
					// queue
					printf(
						"Event[%s %s %d %s] queue, time valid [%s %s]\n",
						(char *)EventField.ObjectID.getValue(),
						(char *)EventField.EventName.getValue(),
						EventField.EvendID.getValue(),
						(char *)EventField.WarningLevel.getValue(),
						(char *)EventField.MonDate.getValue(),
						(char *)EventField.MonTime.getValue());

					map<string, list<CEventInfo> >::iterator msglistIt = m_MsgDelayList.
						find(msgGrpName);

					msglistIt->second.push_back(EventInfo);

				}
			}
		}
		// just for testing
		printf("\tIP: %s EventDes: %s\n",
			EventField.IPAddress.getValue(),
			EventField.EventDes.getValue());
	}
}

char * CMsgGenerator::GenMergeName(char *pMsgGroup, char *pEventName, char *pObjectID)
{
	static char szKeyName[256];
	sprintf(szKeyName, "%s:%s:%s", pMsgGroup, pEventName, pObjectID);
	char *pPos = szKeyName;
	for(int i = 0; i <m_iEventMerge && pPos != NULL; i ++)
	{
		pPos = strchr(pPos +1, '.');
	}
	if (pPos != NULL)
	{
		*pPos = 0x00;
	}

	return szKeyName;
}

void CMsgGenerator::SaveMsg(string sKeyName, CEventInfo EventInfo)
{
	map<string, list<CEventInfo> > ::iterator mapIt = m_MsgMergeList.find(sKeyName);
	if (mapIt != m_MsgMergeList.end())
	{
		mapIt->second.push_back(EventInfo);
	}
	else
	{
		list<CEventInfo> EventList;
		EventList.push_back(EventInfo);
		m_MsgMergeList[sKeyName] = EventList;
	}
}

void CMsgGenerator::GenMsg(CEventInfo EventInfo, CMsgGroupInfo &MsgGroupInfo)
{
	if (EventInfo.m_type == 1 && m_iEventMerge >= 0)
	{
		// 业务事件可尝试合并
		string sKeyName = GenMergeName((char *)MsgGroupInfo.m_name.c_str(), 
			(char *)EventInfo.m_event.EventName.getValue(), (char *)EventInfo.m_event.ObjectID.getValue());
		SaveMsg(sKeyName, EventInfo);
	}
	else
	{
		string eventDes = EventInfo.m_event.EventDes.getValue();
		// PollingDown事件缓存
		if (eventDes.find("polling") != string::npos && !m_PollingDownSendTime.empty())
			m_PollingDownEventList.add(EventInfo);
		else
			DumpMsg(EventInfo, MsgGroupInfo);
	}
}

void CMsgGenerator::DumpMsg(CEventInfo EventInfo, CMsgGroupInfo &MsgGroupInfo)
{
	// 默认情况下，生成的消息内容是按主题推送格式
	char* szMsgContent = GenMsgContent(EventInfo, MsgGroupInfo);

	/// 消息主题
	char szSubject[32];
	if (strcmp(MsgGroupInfo.m_subject.c_str(), "$SYSTEM") == 0)
	{
		memcpy(szSubject, EventInfo.m_event.ObjectID.getValue(), sizeof(szSubject) - 1);
		strtok(szSubject, ".");
	}
	else
	{
		strncpy(szSubject, MsgGroupInfo.m_subject.c_str(), sizeof(szSubject) - 1);
	}

	// 按主题推送
	DumpSubjectMsg(szMsgContent, szSubject);

}

// 根据主题消息内容和用户信息，生成个人消息内容
string CMsgGenerator::GenUserMsgContent(const char *szSubjectMsgCon, const CUserInfo &UserInfo)
{
	string strUserMsgContent = szSubjectMsgCon;

	// 修改原有的消息内容，将其改造成按个人推送格式
	// "<Message MessageId=\"%llu\" SubjectId=\"\" TransferType=\"sms\" User=\"%s\" Receiver=\"%s\" Level=\"%d\" DumpDate=\"%s\" DumpTime=\"%s\" Content=\"%s %s %s[%s] %s %s(已发生%d次)\" MaxRetry=\"%d\" RetrySpan=\"%d\" SenderId=\"%s\" />\r\n"

	// 重新计算MessageId，MessageId的最后两位替换为UserID
	char szUserID[4] = {0};
	sprintf(szUserID, "%02d", UserInfo.m_UserID);
	int UserIdPosition = strUserMsgContent.find("SubjectId") - 4;
	strUserMsgContent.replace(UserIdPosition, 2, szUserID);

	char szUserInfo[512] = {0};
	sprintf(szUserInfo,
		"TransferType=\"sms\" User=\"%s\" Receiver=\"%s\" ",
		UserInfo.m_Name.c_str(), UserInfo.m_Mobile.c_str());

	// 移除SubjectId字段内容
	int SubjectContentPosition = strUserMsgContent.find("SubjectId") + 11;	// 11为SubjectId="的长度
	int SubjectContentLength = strUserMsgContent.find("Level") - 2 - SubjectContentPosition;
	if (SubjectContentPosition > 0 && SubjectContentLength > 0)
	{
		// 移除原有的SubjectId字段内容
		strUserMsgContent.erase(SubjectContentPosition, SubjectContentLength);

		// 插入个人信息
		strUserMsgContent = strUserMsgContent.insert(SubjectContentPosition + 2, szUserInfo, strlen(szUserInfo));
	}

	return strUserMsgContent;
}

char *CMsgGenerator::GenMsgContent(
	CEventInfo	EventInfo,
	CMsgGroupInfo &MsgGroupInfo)
{
	/// 消息内容体静态化，仅支持单线程实例
	static char szMsgContent[1024];
	char szSubject[32];
	char szObject[48];
	char szInfo1[256];
	char szInfo2[256];

	CFTDRtnWarningEventField &EventField = EventInfo.m_event;

	memset(szMsgContent, 0x00, sizeof(szMsgContent));
	memset(szSubject, 0x00, sizeof(szSubject));
	memset(szObject, 0x00, sizeof(szObject));
	memset(szInfo1, 0x00, sizeof(szInfo1));
	memset(szInfo2, 0x00, sizeof(szInfo2));

	int iLen1 = EventInfo.m_info1.length();
	int iLen2 = EventInfo.m_info2.length();
	int iLenIP = strlen(EventField.IPAddress.getValue());
	int iLenOID = strlen(EventField.ObjectID.getValue());

	/// 消息主题
	if (strcmp(MsgGroupInfo.m_subject.c_str(), "$SYSTEM") == 0)
	{
		memcpy(
			szSubject,
			EventField.ObjectID.getValue(),
			sizeof(szSubject) - 1);
		strtok(szSubject, ".");
	}
	else
	{
		strncpy(
			szSubject,
			MsgGroupInfo.m_subject.c_str(),
			sizeof(szSubject) - 1);
	}

	/// 对象名
	if (iLenOID < sizeof(szObject))
	{
		strcpy(szObject, EventField.ObjectID.getValue());
	}
	else
	{
		char *pPos = (char *)EventField.ObjectID.getValue();
		strcpy(szObject, pPos + (iLenOID - sizeof(szObject) +1));
	}

	UINT64 seq = GenMessageID(EventField.EvendID.getValue(), MsgGroupInfo.m_id);

	//// Mod by Henchi, 20121211
	//// 调整消息格式控制
	switch (MsgGroupInfo.m_format)
	{
	case 1:						
		// 用于网络事件
		/// szInfo1:[DeviceName IPAddr]

		if (iLen1 >0 && iLen1 < sizeof(szObject))
		{
			/// 以设备名代替对象名
			strcpy(szObject,  EventInfo.m_info1.c_str());
		}

		if (strlen(EventField.IPAddress.getValue()) > 0
			&&	strlen(EventField.IPAddress.getValue()) < 16)
		{
			sprintf(
				szInfo1,
				"[%s %s]",
				szObject,
				EventField.IPAddress.getValue());
		}
		else
		{
			sprintf(szInfo1, "[%s]", szObject);
		}

		/// szInfo2:[Member]EventDes
		if (EventInfo.m_info2.length() > 0 && EventInfo.m_info2.length() <= 20)
		{
			sprintf(szInfo2, "[%s]", EventInfo.m_info2.c_str());
		}

		strncpy(szInfo2 + strlen(szInfo2), EventField.EventDes.getValue(), 50);
		break;

	case 2:
		strncpy(
			szInfo1,
			EventField.ObjectID.getValue(),
			MIN(sizeof(szInfo1) - 1, strlen(EventField.ObjectID.getValue())));
		strncpy(
			szInfo2,
			EventField.FullEventName.getValue(),
			MIN(
			sizeof(szInfo2) - 1,
			strlen(EventField.FullEventName.getValue())));
		break;

	default:					// 用于一般业务事件
		strncpy(
			szInfo1,
			EventField.ObjectID.getValue(),
			MIN(sizeof(szInfo1) - 1, strlen(EventField.ObjectID.getValue())));
		strncpy(
			szInfo2,
			EventField.EventDes.getValue(),
			MIN(sizeof(szInfo2) - 1, strlen(EventField.EventDes.getValue())));
		break;
	}
	/// 变更GM_13100901
	/// 对于合并事件，增加对象个数说明
	if (EventInfo.m_objects >1)
		sprintf(szInfo1, "%s等共%d个对象", szInfo1, EventInfo.m_objects);

	szInfo2[50] = 0x00;				/// 截断多余的事件描述
	sprintf(
		szMsgContent,
		"<Message MessageId=\"%llu\" SubjectId=\"%s\" Level=\"%d\" DumpDate=\"%s\" DumpTime=\"%s\" Content=\"%s %s %s[%s] %s %s(已发生%d次)\" MaxRetry=\"%d\" RetrySpan=\"%d\" SenderId=\"%s\" />\r\n",
		seq,
		szSubject,
		MsgGroupInfo.m_level,
		m_DateTime.GetDateStr().c_str(),
		m_DateTime.GetTimeStr().c_str(),
		EventField.MonDate.getValue(),
		EventField.MonTime.getValue(),
		EventField.EventName.getValue(),
		EventField.WarningLevel.getValue(),
		szInfo1,
		szInfo2,
		EventInfo.m_count,
		m_iMaxRetry,
		m_iRetrySpan,
		m_strSender.c_str());

	return (char *)szMsgContent;
}

void CMsgGenerator::CheckObjectAttr(void)
{
	list<CAttrTeam *>::iterator it;
	time_t TimeStamp = m_DateTime.GetCurrTimeSec();
	for (it = m_AttrTeamList.begin(); it != m_AttrTeamList.end(); it++)
	{
		if ((*it)->NeedOutput(TimeStamp, m_DateTime.GetWeekdayNo(0)))
		{
			WriteObjectAttr(*it);
		}
	}
}

void CMsgGenerator::WriteObjectAttr(CAttrTeam *pItem)
{
	static int	s_iCount = 0;

	UINT64 seq = GenMessageID(0, 0);

	char attrInfo[1024] = "";
	list<CAttrItem *> &attrList = pItem->m_AttrList;
	sprintf(attrInfo, "%s%s", pItem->m_sComment.c_str(), FLAG_MSG_LINE);
	for (list < CAttrItem * >::iterator it = attrList.begin();
		it != attrList.end();
		it++)
	{
		// 将指标数值由数字格式转换为财务格式，如：1234567 => 1,234,567
		char szAttrInfo[16] = {0};		
		sprintf(szAttrInfo, "%ld", m_AttrValue[(*it)->m_AttrID]);
		string strAttrInfo = szAttrInfo;
		for (int i = strAttrInfo.size() - 4;i >= 0;i -= 4)	// 判断是否需要加","，然后添加","
		{
			strAttrInfo.insert(++i, ",");
		}
		sprintf(
			attrInfo,
			"%s[%s]%s%s",
			attrInfo,
			(*it)->m_Comment.c_str(),
			strAttrInfo.c_str(),
			FLAG_MSG_LINE);
	}

	char buffer[1024];
	map<string, long>::iterator mapIt;
	map<string, long> &subjectMap = pItem->m_SubjectMap;
	for (mapIt = subjectMap.begin(); mapIt != subjectMap.end(); mapIt++)
	{
		s_iCount++;
		sprintf(
			buffer,
			"<Message MessageId=\"%llu\" SubjectId=\"%s\" Level=\"9\" DumpDate=\"%s\" DumpTime=\"%s\" Content=\"%s %s %s\" MaxRetry=\"3\" RetrySpan=\"300\" SenderId=\"%s\" />\r\n",
			seq + s_iCount * 100,	// 预留最后两位供UserID使用
			mapIt->first.c_str(),
			m_DateTime.GetDateStr().c_str(),
			m_DateTime.GetTimeStr().c_str(),
			m_DateTime.GetDateStr().c_str(),
			m_DateTime.GetTimeStr().c_str(),
			attrInfo,
			m_strSender.c_str());

		// 按主题推送
		DumpSubjectMsg(buffer, mapIt->first.c_str());

		//	WriteMsg(GenMsgFileName(), buffer);
	}

	return;
}

bool CMsgGenerator::ShouldWork(CMsgGroupInfo &MsgGroupInfo)
{
	if (MsgGroupInfo.m_time.length() == 0)
	{
		return true;
	}
	else
	{
		int iWeekdayNo = m_DateTime.GetWeekdayNo(0);
		char szTime[1024] = "";
		char szDayStr[32] = "";
		char szTimeStr[512] = "";
		strcpy(szTime, MsgGroupInfo.m_time.c_str());

		char *pToken = strtok(szTime, ";");
		while (pToken != NULL)
		{
			if (sscanf(pToken, "%[^.].%[^;]", szDayStr, szTimeStr) == 2)
			{
				if (MatchDay(szDayStr, iWeekdayNo)
					&&	MatchTime(szTimeStr, m_DateTime.GetTimeStr().c_str()))
				{
					return true;
				}
			}

			pToken = strtok(NULL, ";");
		}
	}

	return false;
}

bool CMsgGenerator::MatchDay(char *pDayStr, int iWeekday)
{
	char *pCurrPos = pDayStr;
	char szDayList[16] = "";
	int iDayL;
	int iDayR;
	while (*pCurrPos != 0x00)
	{
		if (isdigit(*pCurrPos))
		{
			iDayL = atoi(pCurrPos) % 7;
			if (iDayL == iWeekday)
			{
				return true;
			}
		}
		else if ((*pCurrPos) == '-')
		{
			iDayR = atoi(pCurrPos + 1);
			if ((iDayL <= iWeekday && iWeekday <= iDayR)
				||	(iWeekday == 0 && iDayR == 7))
			{
				return true;
			}

			pCurrPos++;
		}

		pCurrPos++;
	}

	return false;
}

bool CMsgGenerator::MatchTime(char *pTimeStr, const char *pTime)
{
	char *pToken = strtok(pTimeStr, ",");
	char szTimeL[10];
	char szTimeR[10];
	while (pToken != NULL)
	{
		if (sscanf(pToken, "%[0-9:]-%[0-9:]", szTimeL, szTimeR) == 2)
		{
			if (strncmp(szTimeL, pTime, strlen(pTime)) <= 0
				&&	strncmp(szTimeR, pTime, strlen(pTime)) >= 0)
			{
				return true;
			}
		}

		pToken = strtok(NULL, ",");
	}

	return false;
}

bool CMsgGenerator::FilterMatch(CFilterInfo &filterInfo, time_t TimePassed)
{
	bool bRtn = false;
	if (filterInfo.m_timeout == 0)
	{
		bRtn = true;
	}
	else
	{
		bRtn = TimePassed <= filterInfo.m_timeout ? true : false;
	}

	bRtn = bRtn
		&&	m_objgrpMap[filterInfo.m_group] == 1
		&&	m_lvlgrpMap[filterInfo.m_level] == 1;
	return bRtn;
}

// 在非工作时间段内，如果发生端口事件，根据事件的IP地址，端口事件的事件名和事件描述进行过滤
// 如果事件名和事件描述符合config中定义的过滤条件，则该事件直接丢弃
// 返回值：true，表示事件信息符合过滤条件，应当丢弃；flase，事件信息不符合过滤条件，应当缓存
bool CMsgGenerator::FilterIgnoreIpList(CEventInfo &EventInfo)
{
	// 首先判断事件名是否为LINEPROTO_UPDOWN或LINK_UPDOWN
	string _EventName = EventInfo.m_event.EventName.getValue();
	// 如果不是这两类事件，则不需要过滤
	if (_EventName.compare("LINEPROTO_UPDOWN") != 0 && _EventName.compare("LINK_UPDOWN") != 0)
		return false;

	// 判断IP地址
	string _EventIP = EventInfo.m_event.IPAddress.getValue();
	map<string, list<string> >::iterator iter_IP = m_IgnoreIpPortList.find(_EventIP);
	// 如果事件发生的IP地址不在列表中，则不需要过滤
	if (iter_IP == m_IgnoreIpPortList.end())
		return false;

	// 判断事件描述中的关键字
	string _EventDes = EventInfo.m_event.EventDes.getValue();
	list<string> &IgnoreAttrList = iter_IP->second;		// 该IP地址对应的关键字列表
	// 遍历所有的过滤关键字
	for (list<string>::iterator iter_IgnoreAttr = IgnoreAttrList.begin();
		iter_IgnoreAttr != IgnoreAttrList.end();
		++iter_IgnoreAttr)
	{
		// 如果任意关键字在事件描述中出现，则表示该事件需要过滤，返回true
		if (strstr(_EventDes.c_str(), (*iter_IgnoreAttr).c_str()) != NULL)
			return true;
	}

	return false;
}

void CMsgGenerator::Init(char *pszCfgPath)
{
	XMLInit(pszCfgPath);
}

void CMsgGenerator::LoadObjectGroups(CXMLNode *pNode)
{
	CXMLNodeList *pNodeList = pNode->getNodeList();
	CXMLNode *pNodeCur = NULL;
	for (int i = 0; i < pNodeList->size(); i++)
	{
		pNodeCur = (*pNodeList)[i];

		char *pName = pNodeCur->findProperty(XML_PROP_NAME);
		if (pName != NULL)
		{
			list<string> incList;
			list<string> excList;

			CXMLNodeList *pChildList = pNodeCur->getNodeList();
			CXMLNode *pChildNodeCur = NULL;
			for (int i = 0; pChildList != NULL && i < pChildList->size(); i++)
			{
				pChildNodeCur = (*pChildList)[i];

				char *pPrefix = pChildNodeCur->findProperty(XML_PROP_PREFIX);
				if (pPrefix != NULL)
				{
					if (*pPrefix == '!')
					{
						excList.push_back(pPrefix + 1);
					}
					else
					{
						incList.push_back(pPrefix);
					}
				}
			}

			m_objgrpMap[pName] = 0;
			m_objgrpIncList[pName] = incList;
			m_objgrpExcList[pName] = excList;
		}
	}
}

void CMsgGenerator::LoadLevelGroups(CXMLNode *pNode)
{
	CXMLNodeList *pNodeList = pNode->getNodeList();
	CXMLNode *pNodeCur = NULL;
	for (int i = 0; i < pNodeList->size(); i++)
	{
		pNodeCur = (*pNodeList)[i];

		char *pName = pNodeCur->findProperty(XML_PROP_NAME);
		if (pName != NULL)
		{
			list<string> incList;
			list<string> excList;

			CXMLNodeList *pChildList = pNodeCur->getNodeList();
			CXMLNode *pChildNodeCur = NULL;
			for (int i = 0; pChildList != NULL && i < pChildList->size(); i++)
			{
				pChildNodeCur = (*pChildList)[i];

				char *plevel = pChildNodeCur->findProperty(XML_PROP_LEVEL);
				if (plevel != NULL)
				{
					if (*plevel == '!')
					{
						excList.push_back(plevel + 1);
					}
					else
					{
						incList.push_back(plevel);
					}
				}
			}

			m_lvlgrpMap[pName] = 0;
			m_lvlgrpIncList[pName] = incList;
			m_lvlgrpExcList[pName] = excList;
		}
	}
}

void CMsgGenerator::LoadMsgGroups(CXMLNode *pNode)
{
	CXMLNodeList *pNodeList = pNode->getNodeList();
	CXMLNode *pNodeCur = NULL;
	list<CEventInfo> eventList;
	for (int i = 0; i < pNodeList->size(); i++)
	{
		pNodeCur = (*pNodeList)[i];

		char *pName = pNodeCur->findProperty(XML_PROP_NAME);
		if (pName != NULL && strlen(pName) > 0)
		{
			char *pSubject = pNodeCur->findProperty(XML_PROP_SUBJECT);
			char *pTime = pNodeCur->findProperty(XML_PROP_TIME);
			int iType = atoi(pNodeCur->findProperty(XML_PROP_TYPE));
			int iGap = atoi(pNodeCur->findProperty(XML_PROP_SENDGAP));
			int iFormat = atoi(pNodeCur->findProperty(XML_PROP_FORMAT));
			int iLevel = atoi(pNodeCur->findProperty(XML_PROP_LEVEL));
			m_msggrpInfo[pName] = CMsgGroupInfo(
				pName,
				pSubject,
				pTime,
				iType,
				iGap,
				iFormat,
				iLevel,
				i + 1);
			m_MsgDelayList[pName] = eventList;

			// 已弃用，详见被注释的CPerHourMessage定义
			// 判断是否启用了PerH_sub组
			//if (strcmp(pName, "PerH_sub") == 0)
			//{
			//	m_bPerHourMsgEnable = true;
			//}
		}
	}
}

void CMsgGenerator::LoadFilters(CXMLNode *pNode)
{
	CXMLNodeList *pNodeList = pNode->getNodeList();
	CXMLNode *pNodeCur = NULL;
	for (int i = 0; i < pNodeList->size(); i++)
	{
		pNodeCur = (*pNodeList)[i];

		char *pName = pNodeCur->findProperty(XML_PROP_NAME);
		if (pName != NULL && strlen(pName) > 0)
		{
			char *pObject = pNodeCur->findProperty(XML_PROP_OBJECT);
			char *pLevel = pNodeCur->findProperty(XML_PROP_LEVEL);
			int iTimeout = atoi(pNodeCur->findProperty(XML_PROP_TIMEOUT));

			list<string> objList;

			CXMLNodeList *pChildList = pNodeCur->getNodeList();
			CXMLNode *pChildNodeCur = NULL;
			for (int i = 0; pChildList != NULL && i < pChildList->size(); i++)
			{
				pChildNodeCur = (*pChildList)[i];

				char *pChildName = pChildNodeCur->findProperty(XML_PROP_NAME);
				if (pChildName != NULL && strlen(pChildName) > 0)
				{
					objList.push_back(pChildName);
				}
			}

			m_filterInfo[pName] = CFilterInfo(pName, pObject, pLevel, iTimeout);
			m_filterMsgMap[pName] = objList;
		}
	}
}

void CMsgGenerator::LoadUserConfig(CXMLNode *pNode)
{
	CXMLNodeList *pNodeList = pNode->getNodeList();
	CXMLNode *pNodeCur = NULL;
	for (int i = 0; i < pNodeList->size(); i++)
	{
		pNodeCur = (*pNodeList)[i];

		char *pName = pNodeCur->findProperty(XML_PROP_NAME);
		char *pCName = pNodeCur->findProperty(XML_PROP_CNAME);
		char *pMobile = pNodeCur->findProperty(XML_PROP_MOBILE);

		if (pName && pCName && pMobile)
		{
			m_UserInfo[pName] = CUserInfo(i + 1, pName, pCName, pMobile);
		}
	}
}

void CMsgGenerator::LoadSubjectConfig(CXMLNode *pNode)
{
	CXMLNodeList *pNodeList = pNode->getNodeList();
	CXMLNode *pNodeCur = NULL;
	for (int i = 0; i < pNodeList->size(); i++)
	{
		pNodeCur = (*pNodeList)[i];

		char *pName = pNodeCur->findProperty(XML_PROP_NAME);
		char *pExtend = pNodeCur->findProperty("extend");
		if (pName != NULL)
		{
			bool isExtend = (pExtend != NULL && strcmp(pExtend, "enable") == 0) ? true : false;
			m_SubjectInfo.m_SubjectExpand[pName] = isExtend;

			CXMLNodeList *pChildList = pNodeCur->getNodeList();
			CXMLNode *pChildNodeCur = NULL;
			for (int i = 0; pChildList != NULL && i < pChildList->size(); i++)
			{
				pChildNodeCur = (*pChildList)[i];

				char *pChildName = pChildNodeCur->findProperty(XML_PROP_NAME);
				if (pChildName != NULL && strlen(pChildName) > 0)
				{
					m_SubjectInfo.Add(pName, pChildName);
				}
			}
		}
	}
}

void CMsgGenerator::LoadEventConfig(CXMLNode *pEventNode)
{
	char *pMerge = pEventNode->findProperty("merge");
	if (pMerge == NULL)
	{
		m_iEventMerge = 3;
	}
	else
	{
		m_iEventMerge = atoi(pMerge);
	}

	CXMLNode *pObjectGroups;

	CXMLNode *pLevelGroups;

	CXMLNode *pMsgGroups;

	CXMLNode *pFilters;
	pObjectGroups = pEventNode->findNode(XMLTag, XML_TAG_OBJGROUPS, NULL, NULL);
	pLevelGroups = pEventNode->findNode(XMLTag, XML_TAG_LVLGROUPS, NULL, NULL);
	pMsgGroups = pEventNode->findNode(XMLTag, XML_TAG_MSGGROUPS, NULL, NULL);
	pFilters = pEventNode->findNode(XMLTag, XML_TAG_FILTERS, NULL, NULL);
	if (pObjectGroups)
	{
		LoadObjectGroups(pObjectGroups);
	}

	if (pLevelGroups)
	{
		LoadLevelGroups(pLevelGroups);
	}

	if (pMsgGroups)
	{
		LoadMsgGroups(pMsgGroups);
	}

	if (pFilters)
	{
		LoadFilters(pFilters);
	}
}

void CMsgGenerator::LoadAttrConfig(CXMLNode *pAttrNode)
{
	CXMLNodeList *pNodeList = pAttrNode->getNodeList();
	if (NULL != pNodeList)
	{
		for (int i = 0; i < (int)pNodeList->size(); i++)
		{
			CXMLNode *pNodeCur = (*pNodeList)[i];
			char *pName = pNodeCur->findProperty(XML_PROP_NAME);
			char *pSeps = pNodeCur->findProperty(XML_PROP_SEPS);
			char *pSubjectId = pNodeCur->findProperty(XML_PROP_SUBJECT);
			char *pComment = pNodeCur->findProperty(XML_PROP_COMMENT);
			if (NULL != pName
				&&	NULL != pSeps
				&&	NULL != pSubjectId
				&&	NULL != pComment)
			{
				CAttrTeam *pAttrTeam = new CAttrTeam(pName, pComment, pSeps);
				pAttrTeam->LoadSubject(pSubjectId);

				CXMLNodeList *pAttrNodeList = pNodeCur->getNodeList();
				if (NULL != pAttrNodeList)
				{
					for (int j = 0; j < (int)pAttrNodeList->size(); j++)
					{
						CXMLNode *pAttrNode = (*pAttrNodeList)[j];
						char *pObjectId = pAttrNode->findProperty(
							XML_PROP_OBJECT);
						char *pAttrType = pAttrNode->findProperty(
							XML_PROP_ATTR);
						char *pAttrComment = pAttrNode->findProperty(
							XML_PROP_COMMENT);
						if (NULL != pObjectId
							&&	NULL != pAttrType
							&&	NULL != pAttrComment)
						{
							char szBuf[512] = "";
							sprintf(szBuf, "%s:%s", pObjectId, pAttrType);
							pAttrTeam->AddAttrItem(
								new CAttrItem(
								szBuf,
								pAttrType,
								pAttrComment));
							m_AttrValue[szBuf] = 0;
						}
					}
				}

				m_AttrTeamList.push_back(pAttrTeam);
			}
		}
	}
}

void CMsgGenerator::LoadIgnoreIpPortConfig(CXMLNode *pNode)
{
	m_IgnoreIpEnable = (pNode->findProperty("Enable") == NULL) ? false : atoi(pNode->findProperty("Enable"));

	CXMLNodeList *pNodeList = pNode->getNodeList();
	CXMLNode *pNodeCur = NULL;
	for (int i = 0; i < pNodeList->size(); i++)
	{
		pNodeCur = (*pNodeList)[i];

		char* pIpAddress = pNodeCur->findProperty("IP");
		char* pIgnoreAttr = pNodeCur->findProperty("IgnoreAttr");
		if (pIgnoreAttr != NULL)
		{
			list<string> IgnoreAttrList;
			char* p = strtok(pIgnoreAttr, ",");
			IgnoreAttrList.push_back(p);
			while ((p = strtok(NULL, ",")) != NULL)
			{
				IgnoreAttrList.push_back(p);
			}

			if (pIpAddress != NULL)
			{
				map<string, list<string> >::iterator IgnoreIpPortList_it = m_IgnoreIpPortList.find(pIpAddress);
				if (IgnoreIpPortList_it == m_IgnoreIpPortList.end())
				{
					m_IgnoreIpPortList[pIpAddress] = IgnoreAttrList;
				}
				else
				{
					IgnoreIpPortList_it->second.merge(IgnoreAttrList);
				}
			}
		}

	}
}

void CMsgGenerator::LoadPollingDownConfig(CXMLNode *pNode)
{
	char* pPollingDownMaxCount = pNode->findProperty("maxcount");
	if (pPollingDownMaxCount != NULL)
		m_PollingDownMaxCount = atoi(pPollingDownMaxCount);
	else
		m_PollingDownMaxCount = 0;

	CXMLNodeList *pNodeList = pNode->getNodeList();
	CXMLNode *pNodeCur = NULL;
	for (int i = 0; i < pNodeList->size(); i++)
	{
		pNodeCur = (*pNodeList)[i];

		char* pStartTime = pNodeCur->findProperty("starttime");
		char* pSendCount = pNodeCur->findProperty("sendcount");
		if (pStartTime != NULL)
		{
			int iSendCount = (pSendCount != NULL) ? (atoi(pSendCount)) : 0;
			m_PollingDownSendTime.push_back(make_pair(pStartTime, iSendCount));
		}
	}

	m_NextSendTime = 0;
	time_t nowTime = m_DateTime.GetCurrTimeSec();
	if (!m_PollingDownSendTime.empty())
	{
		// 初始化发送时间
		for (m_NextSendTimeIter = m_PollingDownSendTime.begin();
			m_NextSendTimeIter != m_PollingDownSendTime.end();
			++m_NextSendTimeIter)
		{			
			time_t nextTime = m_DateTime.GetTimeSec(m_DateTime.GetDateStr().c_str(),
				(*m_NextSendTimeIter).first.c_str());
			// 首次发送时间为，配置信息中比当前时间大的第一个时间
			if (nowTime < nextTime)
			{
				m_NextSendTime = nextTime;
				m_SendCount = (*m_NextSendTimeIter).second;
				break;
			}
		}
		// 如果列表中的时间均比当前时间小，表示定义的发送时间为隔天的
		if (m_NextSendTimeIter == m_PollingDownSendTime.end())
		{
			// 首次发送时间为第一个时间+24小时
			m_NextSendTimeIter = m_PollingDownSendTime.begin();
			m_NextSendTime = 
				m_DateTime.GetTimeSec(m_DateTime.GetDateStr().c_str(),
				(*m_NextSendTimeIter).first.c_str())
				+ 24 * 60 * 60;
			m_SendCount = (*m_NextSendTimeIter).second;
		}
	}


}

void CMsgGenerator::XMLInit(char *pszCfgPath)
{
	CXMLDoc *pXmlFile = new CXMLDoc();
	CXMLNode *pRootNode;
	CXMLNode *pMsgNode;
	CXMLNode *pUserNode;
	CXMLNode *pSubjectNode;
	CXMLNode *pEventNode;
	CXMLNode *pAttrNode;
	try
	{
		pXmlFile->read(pszCfgPath);
		pRootNode = pXmlFile->getRootNode();
		if (pRootNode)
		{
			pMsgNode = pRootNode->findNode(XMLTag, XML_TAG_MESSAGE, NULL, NULL);
			if (pMsgNode)
			{
				char *pPath = pMsgNode->findProperty(XML_PROP_PATH);
				char *pSender = pMsgNode->findProperty(XML_PROP_SENDER);
				if (pPath != NULL && strlen(pPath) > 0)
				{
					if (*(pPath + strlen(pPath) - 1) == '/')
					{
						m_strPath = pPath;
					}
					else
					{
						char szTmp[512];
						sprintf(szTmp, "%s/", pPath);
						m_strPath = szTmp;
					}
				}
				else
				{
					m_strPath = "./";
				}

				if (pSender != NULL && strlen(pSender) > 0)
				{
					m_strSender = pSender;
				}
				else
				{
					m_strSender = "GlobalMonitor";
				}

				m_iMaxRetry = (pMsgNode->findProperty(XML_PROP_MAXRETRY) == NULL) ? 3 : atoi(pMsgNode->findProperty(XML_PROP_MAXRETRY));
				m_iRetrySpan = (pMsgNode->findProperty(XML_PROP_RETRYSPAN) == NULL) ? 300 : atoi(pMsgNode->findProperty(XML_PROP_RETRYSPAN));

				pUserNode = pMsgNode->findNode(
					XMLTag,
					XML_TAG_USERS,
					NULL,
					NULL);
				if (pUserNode)
				{
					LoadUserConfig(pUserNode);
				}

				pSubjectNode = pMsgNode->findNode(
					XMLTag,
					XML_TAG_SUBJECTS,
					NULL,
					NULL);
				if (pSubjectNode)
				{
					LoadSubjectConfig(pSubjectNode);
				}

				pEventNode = pMsgNode->findNode(
					XMLTag,
					XML_TAG_EVENTCFG,
					NULL,
					NULL);
				if (pEventNode)
				{
					LoadEventConfig(pEventNode);
				}

				pAttrNode = pMsgNode->findNode(
					XMLTag,
					XML_TAG_ATTRCFG,
					NULL,
					NULL);
				if (pAttrNode)
				{
					LoadAttrConfig(pAttrNode);
				}

				// 加载PollingDown事件发送时间
				CXMLNode *pPollingDownNode;
				pPollingDownNode = pMsgNode->findNode(
					XMLTag,
					"LinkPollingDownMsg",
					NULL,
					NULL
					);
				if (pPollingDownNode)
				{
					LoadPollingDownConfig(pPollingDownNode);
				}
			}

			// 加载在非正常时段，应当忽略的IP地址和端口关键字信息
			CXMLNode *pIgnoreIpNode;
			pIgnoreIpNode = pRootNode->findNode(XMLTag, "IgnoreIPList", NULL, NULL);
			if (pIgnoreIpNode)
			{
				LoadIgnoreIpPortConfig(pIgnoreIpNode);
			}
		}

		if (pXmlFile)
		{
			delete pXmlFile;
		}
	}

	catch(CParseError * e)
	{
		delete e;
		delete pXmlFile;
		pXmlFile = NULL;
		printf("XML: File %s explain failed!\n", pszCfgPath);
		fflush(stdout);
	}
}

void CMsgGenerator::RefreshDateTime(void)
{
	m_DateTime.FreshTime();
}

char *CMsgGenerator::GenMsgFileName(void)
{
	static char szFileName[512];
	sprintf(
		szFileName,
		"%s%s.im",
		m_strPath.c_str(),
		m_DateTime.GetDateStr().c_str());
	return szFileName;
}

int CMsgGenerator::WriteMsg(char *pszFile, char *pszMsg)
{
	FILE *fp = fopen(pszFile, "a"); // append mode
	if (fp == NULL)
	{
		printf("[ERROR]In function writeMsg: open file %s failed\n", pszFile);
		return 1;
	}

#ifdef PRINT_DEBUG
	printf("Generate Msg:\n%s", pszMsg);
#endif
	fwrite(pszMsg, strlen(pszMsg), 1, fp);
	fflush(fp);
	fclose(fp);

	return 0;
}

void CMsgGenerator::UpdatePollingDownSendTime()
{
	if (m_SendCount <= 0)
	{
		++m_NextSendTimeIter;

		if (m_NextSendTimeIter == m_PollingDownSendTime.end())	// 跨天
			m_NextSendTimeIter = m_PollingDownSendTime.begin();

		m_NextSendTime = m_DateTime.GetTimeSec(m_DateTime.GetDateStr().c_str(),
			(*m_NextSendTimeIter).first.c_str());

		// 如果当前时间还未进入第二天，则下次发送时间需要加24小时
		if (strncmp(m_DateTime.GetTimeStr().c_str(), 
			(*m_NextSendTimeIter).first.c_str(),
			(*m_NextSendTimeIter).first.size()) > 0)
			m_NextSendTime += 24 * 60 * 60;

		m_SendCount = m_NextSendTimeIter->second;
	}
	else
	{
		m_SendCount--;
		m_NextSendTime += (10 * 60);	// 10min
	}

}

void CMsgGenerator::DumpSubjectMsg( char* pszMsgContent, const char *pszSubjectId )
{
	char* pszMsgFileName = GenMsgFileName();

	// 分析目标主题是否已定义订阅关系表，如有则按个人消息推送，没有则仍按主题推送
	map <string, list<string> >::iterator iter_SubjectInfo = m_SubjectInfo.m_SubjectInfo.find(pszSubjectId);
	if (iter_SubjectInfo == m_SubjectInfo.m_SubjectInfo.end())
	{
		// 该主题不存在订阅关系表，则按主题推送
		WriteMsg(pszMsgFileName, pszMsgContent);
	}
	else
	{
		// 该订阅主题存在，按个人方式推送

		// 如果该订阅方式是可扩展的，则先增加一条按主题推送
		// 由于个人推送消息的MessageID会增加，这样做是为了保证ID的顺序
		if (m_SubjectInfo.m_SubjectExpand[pszSubjectId])
		{
			WriteMsg(pszMsgFileName, pszMsgContent);
		}

		// 根据SubjectId获取用户名列表
		list<string> &UserList = iter_SubjectInfo->second;

		int iSendCount = 0;
		// 对订阅关系表中的每个用户，生成个人推送消息
		for (list<string>::iterator it_UserName = UserList.begin();it_UserName != UserList.end();++it_UserName)
		{
			string strUserName = *it_UserName;
			// 根据用户名(username)获取用户信息(UserInfo)
			if (m_UserInfo.find(strUserName) != m_UserInfo.end())
			{
				CUserInfo &UserInfo = m_UserInfo[strUserName];

				// 根据原始的主题推送内容和用户信息，生成针对该用户的个人消息内容
				string szUserMsgContent = GenUserMsgContent(pszMsgContent, UserInfo);

				// 写入信息
				WriteMsg(pszMsgFileName, (char *)szUserMsgContent.c_str());

				++iSendCount;
			}
			else
				printf("### Write User Msg Error: Cann't find User Info [%s] under SubjectId [%s]\n",
				strUserName.c_str(), pszSubjectId);
		}

		// 如果按主题方式发送的消息数量为0，表示没有成功写入任意个人消息
		// 并且消息为非扩展模式，则需要按主题推送一条信息
		if (iSendCount == 0 && !m_SubjectInfo.m_SubjectExpand[pszSubjectId])
		{
			WriteMsg(pszMsgFileName, pszMsgContent);
		}
	}
}

// 计算MessageID
UINT64 CMsgGenerator::GenMessageID( int nEventID, int nMsgGroupID )
{
	// 原始的seq生成方式
	//UINT64 uSeq = m_DateTime.GetCurrTimeSec() * 1000000
	//	+ nEventID * 10
	//	+ nMsgGroupID;

	// 为保证部分仅占用8位，仅计算从平均三年的时间偏移量（94608000秒）
	UINT64 uTimeOffset = m_DateTime.GetCurrTimeSec() % (3 * 365 * 24 * 60 * 60);

	// EventID有5位可用，0 ~ 99999
	// MsgGroupID有1位可用，0 ~ 9
	// 预留2位供UserID用，1 ~ 99
	UINT64 uSeq = uTimeOffset * 100000000 + nEventID * 1000 + nMsgGroupID * 100;

	return uSeq;
}

void CMsgGenerator::GenPollingDownMsgContent( 
	string &strMsgContent, 
	CEventInfo &EventInfo )
{
	char szPollingDownMsg[1024] = {0};

	CFTDRtnWarningEventField &EventField = EventInfo.m_event;

	// 从事件描述EventDes中获取接口名称
	// 接口名称出现在EventDes中关键字Interface之后，形如Interface Serial4/0_1/1/1/2:0, polling state down
	string strInterface;
	string strEventDes = EventField.EventDes.getValue();
	size_t nIfPos = strEventDes.find("Interface");
	if (nIfPos != string::npos)
	{
		strEventDes = strEventDes.substr(nIfPos + strlen("Interface") + 1);
		strInterface = strEventDes.substr(0, strEventDes.find(","));
	}

	// 如果事件中包含设备名称，则使用设备名，否则使用ObjectID
	string strDeviceName = EventInfo.m_info1.size() ? EventInfo.m_info1 : EventField.ObjectID.getValue();
	
	sprintf(szPollingDownMsg, "<br/>%s %s [%s %s] [%s] %s",
		EventField.MonDate.getValue(),
		EventField.MonTime.getValue(),
		strDeviceName.c_str(),
		EventField.IPAddress.getValue(),
		EventInfo.m_info2.c_str(),
		strInterface.c_str());

	// 将该Pollingdown消息附加到全局消息之后
	strMsgContent.append(szPollingDownMsg);
}
