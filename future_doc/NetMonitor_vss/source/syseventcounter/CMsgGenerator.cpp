/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CMsgGenerator.cpp
///@brief	������������Ϣ�ļ��Ĺ�����
///@history
///20111214	�̺״�	�������ļ�
///20131009 �̺״�  �����GM_13100901���澯�¼���Ϣ���Ӻϲ����͹���
#include "CMsgGenerator.h"

CMutex	g_lockMsgFile;				// ��Ϣ�ļ���
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
			/// �ɷ��¼���Ϣ
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

			/// �����ɷ������е��¼���Ϣ
			if (iCount % 1000 == 0)
			{
				ScanMsgDelayList();
				ScanMsgMergeList();			/// ���GM_13100901
				ScanPollingDownList();		// add by cao.ning
			}

		}

		if (m_bAttrFlag)
		{
			/// �������ָ����Ϣ
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

/// ��Я������������������Ϣ�ĸ澯�¼���Ϣ������m_EventList����
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
		iType = 2;	// ��������¼�
	}
	else
	{
		iType = 1;	// ���ҵ���¼�
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
		int iRst = 1;	// Ĭ�϶���״̬ΪOK
		list<string> &objexcList = m_objgrpExcList[mapIt->first];
		list<string> &objincList = m_objgrpIncList[mapIt->first];
		list<string>::iterator	listIt;

		/// ����ȥ���ų�����
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

		/// �ټ����Ƿ�Ϊ�������
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

/// ��Ŀ���¼���Ϣ���г����������ˣ�Ѱ�Ҷ�Ӧ����Ϣ�����
void CMsgGenerator::DispatchEvent(CEventInfo EventInfo)
{
	// �����ã������ע�͵�CPerHourMessage����
	//if (strcmp(EventInfo.m_event.EventName.getValue(), "System_Timer") == 0)
	//{
	//	EventInfo.m_msggrp = "PerH_sub";
	//	EventInfo.m_type = 2;
	//	DispatchMsg(EventInfo);
	//	return ;
	//}

	CFTDRtnWarningEventField &EventField = EventInfo.m_event;
	/// ���˶��������¼���
	RefreshObjectStatus((char *)EventField.ObjectID.getValue(), (char *)EventField.EventName.getValue());
	/// �����¼�����
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
		/// ������ƥ��ɹ��Ļ���Ϊ�¼���Ϣ����MsgGroup��Ϣ����Ϣ,�����Ծ���Ϣ����ƻ����ɷ�
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
				/// �����ɷ��������Ϣ����Ϣ���¼�����
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
				/// ���ڶ����ɺϲ��¼�,Ĭ���������¼��������
				EventInfo.m_objects = EventList.size();
				DumpMsg(EventInfo, MsgGroupInfo);
			}
			else
			{
				/// ����ϲ���ֱ�����
				DumpMsg(EventInfo, MsgGroupInfo);
			}		
		}
	}
	m_MsgMergeList.clear();
}

// ɨ��PollingDown�����е��¼�����ʱ�����㣬��ϲ��¼���д���ļ�
void CMsgGenerator::ScanPollingDownList(void)
{
	// �������ʱ��Ϊ�գ�pollingdown�¼��������ڻ����У���ֱ�ӷ���
	if (m_PollingDownSendTime.empty())
		return;

	// �����ж��Ƿ񵽴﷢��ʱ��
	if (m_DateTime.GetCurrTimeSec() >= m_NextSendTime)
	{
		CEventInfo	EventInfo;
		int MsgCount = 0;
		// ���ڱ���ϲ����¼�Content����
		string PollingDownMsgContent = "";
		// �Ӷ�����ȡ���¼�
		while (m_PollingDownEventList.get(EventInfo))
		{
			// �����¼�����Ϣ�ع�֮�󸽼ӵ��ϲ���Ϣ֮��
			GenPollingDownMsgContent(PollingDownMsgContent, EventInfo);
			++MsgCount;
			// �����ǰ�ϲ����¼������Ѿ��������ƻ��߻���������գ���д���ļ�
			if (MsgCount >= m_PollingDownMaxCount || m_PollingDownEventList.size() == 0)
			{
				string	msgGrpName = EventInfo.m_msggrp;
				map<string, CMsgGroupInfo>::iterator mapIt = m_msggrpInfo.find(msgGrpName);
				if (mapIt != m_msggrpInfo.end())
				{
					CMsgGroupInfo &MsgGroupInfo = mapIt->second;

					// ����MsgID
					UINT64 newMessageID = GenMessageID(EventInfo.m_event.EvendID.getValue(), MsgGroupInfo.m_id);

					char *newMessageContent = new char[PollingDownMsgContent.size() + 1024];
					memset(newMessageContent, 0, PollingDownMsgContent.size() + 1024);

					// ����PollingDown�¼���SubjectId��Level����ͬ��
					sprintf(
						newMessageContent,
						"<Message MessageId=\"%llu\" SubjectId=\"%s\" Level=\"%d\" DumpDate=\"%s\" DumpTime=\"%s\" Content=\"Polling down�¼��б�:%s\" MaxRetry=\"%d\" RetrySpan=\"%d\" SenderId=\"%s\" />\r\n",
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

		// �����´η���ʱ��
		UpdatePollingDownSendTime();
	}
}
///�����¼���Ϣ��Ӧ��Ϣ����ɷ����ƣ������������������Ϣ���
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
		else	// �����ǰ�¼�������ʱ�̲��ǳ��ڶ�Ӧ����Ϣ�鶨����¼�����ʱ�̣�����ж���Ĵ���
		{
			/// Time invalid
			if (MsgGroupInfo.m_type == 0)	// �����Ϣ������Ϊ0��ֻ��Test_sub��NM_subΪ1������ֱ�Ӷ����¼�
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
				// ������Ϣ�����Ϊ0��ʱ�䣬����������е�IP��ַ�Ͷ˿���Ϣ�����������й���
				// �����Ϲ�����������ֱ�Ӷ������¼��������¼����浽�¼�������
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
					// �ӳ����͵���Ϣ������еȴ�ʱ�����ʱ����
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
		// ҵ���¼��ɳ��Ժϲ�
		string sKeyName = GenMergeName((char *)MsgGroupInfo.m_name.c_str(), 
			(char *)EventInfo.m_event.EventName.getValue(), (char *)EventInfo.m_event.ObjectID.getValue());
		SaveMsg(sKeyName, EventInfo);
	}
	else
	{
		string eventDes = EventInfo.m_event.EventDes.getValue();
		// PollingDown�¼�����
		if (eventDes.find("polling") != string::npos && !m_PollingDownSendTime.empty())
			m_PollingDownEventList.add(EventInfo);
		else
			DumpMsg(EventInfo, MsgGroupInfo);
	}
}

void CMsgGenerator::DumpMsg(CEventInfo EventInfo, CMsgGroupInfo &MsgGroupInfo)
{
	// Ĭ������£����ɵ���Ϣ�����ǰ��������͸�ʽ
	char* szMsgContent = GenMsgContent(EventInfo, MsgGroupInfo);

	/// ��Ϣ����
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

	// ����������
	DumpSubjectMsg(szMsgContent, szSubject);

}

// ����������Ϣ���ݺ��û���Ϣ�����ɸ�����Ϣ����
string CMsgGenerator::GenUserMsgContent(const char *szSubjectMsgCon, const CUserInfo &UserInfo)
{
	string strUserMsgContent = szSubjectMsgCon;

	// �޸�ԭ�е���Ϣ���ݣ��������ɰ��������͸�ʽ
	// "<Message MessageId=\"%llu\" SubjectId=\"\" TransferType=\"sms\" User=\"%s\" Receiver=\"%s\" Level=\"%d\" DumpDate=\"%s\" DumpTime=\"%s\" Content=\"%s %s %s[%s] %s %s(�ѷ���%d��)\" MaxRetry=\"%d\" RetrySpan=\"%d\" SenderId=\"%s\" />\r\n"

	// ���¼���MessageId��MessageId�������λ�滻ΪUserID
	char szUserID[4] = {0};
	sprintf(szUserID, "%02d", UserInfo.m_UserID);
	int UserIdPosition = strUserMsgContent.find("SubjectId") - 4;
	strUserMsgContent.replace(UserIdPosition, 2, szUserID);

	char szUserInfo[512] = {0};
	sprintf(szUserInfo,
		"TransferType=\"sms\" User=\"%s\" Receiver=\"%s\" ",
		UserInfo.m_Name.c_str(), UserInfo.m_Mobile.c_str());

	// �Ƴ�SubjectId�ֶ�����
	int SubjectContentPosition = strUserMsgContent.find("SubjectId") + 11;	// 11ΪSubjectId="�ĳ���
	int SubjectContentLength = strUserMsgContent.find("Level") - 2 - SubjectContentPosition;
	if (SubjectContentPosition > 0 && SubjectContentLength > 0)
	{
		// �Ƴ�ԭ�е�SubjectId�ֶ�����
		strUserMsgContent.erase(SubjectContentPosition, SubjectContentLength);

		// ���������Ϣ
		strUserMsgContent = strUserMsgContent.insert(SubjectContentPosition + 2, szUserInfo, strlen(szUserInfo));
	}

	return strUserMsgContent;
}

char *CMsgGenerator::GenMsgContent(
	CEventInfo	EventInfo,
	CMsgGroupInfo &MsgGroupInfo)
{
	/// ��Ϣ�����徲̬������֧�ֵ��߳�ʵ��
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

	/// ��Ϣ����
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

	/// ������
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
	//// ������Ϣ��ʽ����
	switch (MsgGroupInfo.m_format)
	{
	case 1:						
		// ���������¼�
		/// szInfo1:[DeviceName IPAddr]

		if (iLen1 >0 && iLen1 < sizeof(szObject))
		{
			/// ���豸�����������
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

	default:					// ����һ��ҵ���¼�
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
	/// ���GM_13100901
	/// ���ںϲ��¼������Ӷ������˵��
	if (EventInfo.m_objects >1)
		sprintf(szInfo1, "%s�ȹ�%d������", szInfo1, EventInfo.m_objects);

	szInfo2[50] = 0x00;				/// �ض϶�����¼�����
	sprintf(
		szMsgContent,
		"<Message MessageId=\"%llu\" SubjectId=\"%s\" Level=\"%d\" DumpDate=\"%s\" DumpTime=\"%s\" Content=\"%s %s %s[%s] %s %s(�ѷ���%d��)\" MaxRetry=\"%d\" RetrySpan=\"%d\" SenderId=\"%s\" />\r\n",
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
		// ��ָ����ֵ�����ָ�ʽת��Ϊ�����ʽ���磺1234567 => 1,234,567
		char szAttrInfo[16] = {0};		
		sprintf(szAttrInfo, "%ld", m_AttrValue[(*it)->m_AttrID]);
		string strAttrInfo = szAttrInfo;
		for (int i = strAttrInfo.size() - 4;i >= 0;i -= 4)	// �ж��Ƿ���Ҫ��","��Ȼ�����","
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
			seq + s_iCount * 100,	// Ԥ�������λ��UserIDʹ��
			mapIt->first.c_str(),
			m_DateTime.GetDateStr().c_str(),
			m_DateTime.GetTimeStr().c_str(),
			m_DateTime.GetDateStr().c_str(),
			m_DateTime.GetTimeStr().c_str(),
			attrInfo,
			m_strSender.c_str());

		// ����������
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

// �ڷǹ���ʱ����ڣ���������˿��¼��������¼���IP��ַ���˿��¼����¼������¼��������й���
// ����¼������¼���������config�ж���Ĺ�������������¼�ֱ�Ӷ���
// ����ֵ��true����ʾ�¼���Ϣ���Ϲ���������Ӧ��������flase���¼���Ϣ�����Ϲ���������Ӧ������
bool CMsgGenerator::FilterIgnoreIpList(CEventInfo &EventInfo)
{
	// �����ж��¼����Ƿ�ΪLINEPROTO_UPDOWN��LINK_UPDOWN
	string _EventName = EventInfo.m_event.EventName.getValue();
	// ��������������¼�������Ҫ����
	if (_EventName.compare("LINEPROTO_UPDOWN") != 0 && _EventName.compare("LINK_UPDOWN") != 0)
		return false;

	// �ж�IP��ַ
	string _EventIP = EventInfo.m_event.IPAddress.getValue();
	map<string, list<string> >::iterator iter_IP = m_IgnoreIpPortList.find(_EventIP);
	// ����¼�������IP��ַ�����б��У�����Ҫ����
	if (iter_IP == m_IgnoreIpPortList.end())
		return false;

	// �ж��¼������еĹؼ���
	string _EventDes = EventInfo.m_event.EventDes.getValue();
	list<string> &IgnoreAttrList = iter_IP->second;		// ��IP��ַ��Ӧ�Ĺؼ����б�
	// �������еĹ��˹ؼ���
	for (list<string>::iterator iter_IgnoreAttr = IgnoreAttrList.begin();
		iter_IgnoreAttr != IgnoreAttrList.end();
		++iter_IgnoreAttr)
	{
		// �������ؼ������¼������г��֣����ʾ���¼���Ҫ���ˣ�����true
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

			// �����ã������ע�͵�CPerHourMessage����
			// �ж��Ƿ�������PerH_sub��
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
		// ��ʼ������ʱ��
		for (m_NextSendTimeIter = m_PollingDownSendTime.begin();
			m_NextSendTimeIter != m_PollingDownSendTime.end();
			++m_NextSendTimeIter)
		{			
			time_t nextTime = m_DateTime.GetTimeSec(m_DateTime.GetDateStr().c_str(),
				(*m_NextSendTimeIter).first.c_str());
			// �״η���ʱ��Ϊ��������Ϣ�бȵ�ǰʱ���ĵ�һ��ʱ��
			if (nowTime < nextTime)
			{
				m_NextSendTime = nextTime;
				m_SendCount = (*m_NextSendTimeIter).second;
				break;
			}
		}
		// ����б��е�ʱ����ȵ�ǰʱ��С����ʾ����ķ���ʱ��Ϊ�����
		if (m_NextSendTimeIter == m_PollingDownSendTime.end())
		{
			// �״η���ʱ��Ϊ��һ��ʱ��+24Сʱ
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

				// ����PollingDown�¼�����ʱ��
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

			// �����ڷ�����ʱ�Σ�Ӧ�����Ե�IP��ַ�Ͷ˿ڹؼ�����Ϣ
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

		if (m_NextSendTimeIter == m_PollingDownSendTime.end())	// ����
			m_NextSendTimeIter = m_PollingDownSendTime.begin();

		m_NextSendTime = m_DateTime.GetTimeSec(m_DateTime.GetDateStr().c_str(),
			(*m_NextSendTimeIter).first.c_str());

		// �����ǰʱ�仹δ����ڶ��죬���´η���ʱ����Ҫ��24Сʱ
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

	// ����Ŀ�������Ƿ��Ѷ��嶩�Ĺ�ϵ�������򰴸�����Ϣ���ͣ�û�����԰���������
	map <string, list<string> >::iterator iter_SubjectInfo = m_SubjectInfo.m_SubjectInfo.find(pszSubjectId);
	if (iter_SubjectInfo == m_SubjectInfo.m_SubjectInfo.end())
	{
		// �����ⲻ���ڶ��Ĺ�ϵ������������
		WriteMsg(pszMsgFileName, pszMsgContent);
	}
	else
	{
		// �ö���������ڣ������˷�ʽ����

		// ����ö��ķ�ʽ�ǿ���չ�ģ���������һ������������
		// ���ڸ���������Ϣ��MessageID�����ӣ���������Ϊ�˱�֤ID��˳��
		if (m_SubjectInfo.m_SubjectExpand[pszSubjectId])
		{
			WriteMsg(pszMsgFileName, pszMsgContent);
		}

		// ����SubjectId��ȡ�û����б�
		list<string> &UserList = iter_SubjectInfo->second;

		int iSendCount = 0;
		// �Զ��Ĺ�ϵ���е�ÿ���û������ɸ���������Ϣ
		for (list<string>::iterator it_UserName = UserList.begin();it_UserName != UserList.end();++it_UserName)
		{
			string strUserName = *it_UserName;
			// �����û���(username)��ȡ�û���Ϣ(UserInfo)
			if (m_UserInfo.find(strUserName) != m_UserInfo.end())
			{
				CUserInfo &UserInfo = m_UserInfo[strUserName];

				// ����ԭʼ�������������ݺ��û���Ϣ��������Ը��û��ĸ�����Ϣ����
				string szUserMsgContent = GenUserMsgContent(pszMsgContent, UserInfo);

				// д����Ϣ
				WriteMsg(pszMsgFileName, (char *)szUserMsgContent.c_str());

				++iSendCount;
			}
			else
				printf("### Write User Msg Error: Cann't find User Info [%s] under SubjectId [%s]\n",
				strUserName.c_str(), pszSubjectId);
		}

		// ��������ⷽʽ���͵���Ϣ����Ϊ0����ʾû�гɹ�д�����������Ϣ
		// ������ϢΪ����չģʽ������Ҫ����������һ����Ϣ
		if (iSendCount == 0 && !m_SubjectInfo.m_SubjectExpand[pszSubjectId])
		{
			WriteMsg(pszMsgFileName, pszMsgContent);
		}
	}
}

// ����MessageID
UINT64 CMsgGenerator::GenMessageID( int nEventID, int nMsgGroupID )
{
	// ԭʼ��seq���ɷ�ʽ
	//UINT64 uSeq = m_DateTime.GetCurrTimeSec() * 1000000
	//	+ nEventID * 10
	//	+ nMsgGroupID;

	// Ϊ��֤���ֽ�ռ��8λ���������ƽ�������ʱ��ƫ������94608000�룩
	UINT64 uTimeOffset = m_DateTime.GetCurrTimeSec() % (3 * 365 * 24 * 60 * 60);

	// EventID��5λ���ã�0 ~ 99999
	// MsgGroupID��1λ���ã�0 ~ 9
	// Ԥ��2λ��UserID�ã�1 ~ 99
	UINT64 uSeq = uTimeOffset * 100000000 + nEventID * 1000 + nMsgGroupID * 100;

	return uSeq;
}

void CMsgGenerator::GenPollingDownMsgContent( 
	string &strMsgContent, 
	CEventInfo &EventInfo )
{
	char szPollingDownMsg[1024] = {0};

	CFTDRtnWarningEventField &EventField = EventInfo.m_event;

	// ���¼�����EventDes�л�ȡ�ӿ�����
	// �ӿ����Ƴ�����EventDes�йؼ���Interface֮������Interface Serial4/0_1/1/1/2:0, polling state down
	string strInterface;
	string strEventDes = EventField.EventDes.getValue();
	size_t nIfPos = strEventDes.find("Interface");
	if (nIfPos != string::npos)
	{
		strEventDes = strEventDes.substr(nIfPos + strlen("Interface") + 1);
		strInterface = strEventDes.substr(0, strEventDes.find(","));
	}

	// ����¼��а����豸���ƣ���ʹ���豸��������ʹ��ObjectID
	string strDeviceName = EventInfo.m_info1.size() ? EventInfo.m_info1 : EventField.ObjectID.getValue();
	
	sprintf(szPollingDownMsg, "<br/>%s %s [%s %s] [%s] %s",
		EventField.MonDate.getValue(),
		EventField.MonTime.getValue(),
		strDeviceName.c_str(),
		EventField.IPAddress.getValue(),
		EventInfo.m_info2.c_str(),
		strInterface.c_str());

	// ����Pollingdown��Ϣ���ӵ�ȫ����Ϣ֮��
	strMsgContent.append(szPollingDownMsg);
}
