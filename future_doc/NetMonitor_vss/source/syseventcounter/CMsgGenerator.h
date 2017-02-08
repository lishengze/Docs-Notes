/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CMsgGenerator.h
///@brief	������������Ϣ�ļ��Ĺ�����
///@history
///20111214	�̺״�	�������ļ�
///20111223	�̺״�	������Ϣ���м����ʱ����ԵĴ���
///20121112	�̺״�	�ع���Ϣ�߳��࣬���������¼���ҵ���¼�
///20131009 �̺״�  �����GM_13100901���澯�¼���Ϣ���Ӻϲ����͹���
#ifndef REF_CMSGGENERATOR_H
#define REF_CMSGGENERATOR_H

#include "public.h"
#include "systools.h"
#include "FtdPackageDesc.h"
#include "CTimePolicy.h"
#include "map"
#include "list"
#include "string"

using namespace std;

#define FLAG_MSG_LINE	"<br/>"

class CNewJudgeRun
{
	/* */
	public:
		CNewJudgeRun(void)
		{
			m_nNextRunSec = 0;
			m_nInterval = 0;
		}

		CNewJudgeRun(const char *pSeps)
		{
			m_nNextRunSec = 0;
			m_nInterval = 0;

			char szTime[1024] = "";
			char szDayStr[32] = "";
			char szTimeStr[512] = "";
			strcpy(szTime, pSeps);

			char *pToken = strtok(szTime, ";");
			while (pToken != NULL)
			{
				if (sscanf(pToken, "%[^.].%[^;]", szDayStr, szTimeStr) == 2)
				{
					// Get Days info
					map<int, int> mapDays;
					char *pCurrPos = szDayStr;
					int iDayL;
					int iDayR;
					while (*pCurrPos != 0x00)
					{
						if (isdigit(*pCurrPos))
						{
							iDayL = atoi(pCurrPos) % 7;
							mapDays[iDayL] = 1;
						}
						else if ((*pCurrPos) == '-')
						{
							iDayR = atoi(++pCurrPos);
							for (int i = iDayL; i <= iDayR; i++)
							{
								mapDays[i % 7] = 1;
							}
						}

						pCurrPos++;
					}

					// Get Times Info
					char *pTimeStr = strtok(szTimeStr, ",");;
					while (pTimeStr != NULL)
					{
						map<int, int>::iterator mapIt;
						for (mapIt = mapDays.begin();
							 mapIt != mapDays.end();
							 mapIt++)
						{
							map<int, vector<CSeps> >::iterator	m_SepsIt =
								m_Seps.find(mapIt->first);
							if (m_SepsIt != m_Seps.end())
							{
								m_SepsIt->second.push_back(CSeps(pTimeStr));
							}
							else
							{
								vector<CSeps> vecSeps;
								vecSeps.push_back(CSeps(pTimeStr));
								m_Seps[mapIt->first] = vecSeps;
							}
						}

						pTimeStr = strtok(NULL, ",");
					}
				}

				pToken = strtok(NULL, ";");
			}
		}

		///�������캯��
		CNewJudgeRun(const CNewJudgeRun &ob)
		{
			m_nNextRunSec = ob.m_nNextRunSec;
			m_nInterval = ob.m_nInterval;
			m_Seps.clear();

			map<int, vector<CSeps> >::const_iterator SepsIt;
			for (SepsIt = (ob.m_Seps).begin();
				 SepsIt != (ob.m_Seps).end();
				 SepsIt++)
			{
				m_Seps[SepsIt->first] = SepsIt->second;
			}
		}

		CNewJudgeRun &operator=(const CNewJudgeRun &ob)
		{
			m_nNextRunSec = ob.m_nNextRunSec;
			m_nInterval = ob.m_nInterval;
			m_Seps.clear();

			map<int, vector<CSeps> >::const_iterator SepsIt;
			for (SepsIt = (ob.m_Seps).begin();
				 SepsIt != (ob.m_Seps).end();
				 SepsIt++)
			{
				m_Seps[SepsIt->first] = SepsIt->second;
			}

			return *this;
		}

		///�ж��ַ����Ƿ����ʱ���Ƶ�ʶ����ʽ
		bool isValid(char *p)
		{
			return
				(
					*(p + 2) == ':'
				&&	*(p + 5) == ':'
				&&	*(p + 8) == '-'
				&&	*(p + 11) == ':'
				&&	*(p + 14) == ':'
				&&	(*(p + 17) == '.' || *(p + 17) == '/')
				);
		}

		///�ж��Ƿ���Ҫȡ��ָ��
			///@param	nNowSec	��ϵͳ��ȡ�õ��������Ѿ�������ʱ�
			///@return	true��Ҫִ��,false����Ҫִ��
		bool needExcute(time_t Timestamp, int WeekDay)
		{
			int DaySecs = Timestamp % 86400;
			int NextSecs = m_nNextRunSec % 86400;

			if (Timestamp >= m_nNextRunSec)
			{
				map<int, vector<CSeps> >::iterator	SepsIt = m_Seps.find(
						WeekDay % 7);

				if (SepsIt == m_Seps.end() || SepsIt->second.size() == 0)
				{
					/// ���ղ�������
					m_nNextRunSec = Timestamp - DaySecs + 86400;
					return false;
				}
				else
				{
					vector<CSeps> &vecSep = SepsIt->second;
					for (unsigned int i = 0; i < vecSep.size(); i++)
					{
						if (DaySecs >= vecSep[i].m_nStart
						&&	DaySecs <= vecSep[i].m_nEnd)	// ȡ��ʱ��εĲ���Ƶ��
						{
							time_t	tNext = Timestamp -
								(
									Timestamp %
									vecSep[i].m_nInterval
								) +
										vecSep[i].m_nInterval;
							time_t	tEnd = Timestamp -
								DaySecs +
								vecSep[i].m_nEnd;
							m_nNextRunSec = tNext <= tEnd ? tNext : (tEnd + 1);
							m_nInterval = vecSep[i].m_nInterval;
							return true;
						}
					}
				}
			}

			return false;
		}

		int GetInterval(void)
		{
			return m_nInterval;
		}

	/* */
	private:
		///����ʱ������
		map<int, vector<CSeps> > m_Seps;

		///��һ�β���ʱ��,�ӵ�����㿪ʼ������
		int m_nNextRunSec;

		///����ǰ��ִ��,��Ӧ��ʱ����ֵ
		int m_nInterval;
};

class CUserInfo
{
	/* */
	public:
		CUserInfo()
		{
		}

		CUserInfo(int nUserID, char *pszName, char *pszCName, char *pMobile)
		{
			m_UserID = nUserID;
			m_Name = pszName;
			m_CName = pszCName;
			m_Mobile = pMobile;
		}

		~ CUserInfo(void)
		{
		}

		int m_UserID;
		string	m_Name;
		string	m_CName;
		string	m_Mobile;
};

class CSubjectInfo
{
public:
	CSubjectInfo()
	{
	}

	~ CSubjectInfo(void)
	{
		m_SubjectInfo.clear();
	}

	void Add(char *pszSubject, char *pszUser)
	{
		if (m_SubjectInfo.find((string)pszSubject) == m_SubjectInfo.end())
		{
			list <string> List;
			List.push_back((string)pszUser);
			m_SubjectInfo[(string)pszSubject] = List;
		}
		else
		{
			list<string> & List = m_SubjectInfo[(string)pszSubject];
			if (find(List.begin(), List.end(), (string)pszUser) == List.end())
			{
				List.push_back((string)pszUser);
			}
		}
	}

	// key: SubjectID  value: user name list
	map <string, list<string> > m_SubjectInfo;

	// key: SubjectID value: true/false �ö������Ƿ�����չģʽ
	map <string, bool> m_SubjectExpand;
};

class CAttrItem
{
	/* */
	public:
		CAttrItem(char *pszID, char *pszName, char *pComment)
		{
			m_AttrID = pszID;
			m_AttrName = pszName;
			m_Comment = pComment;
		}

		~ CAttrItem(void);

		string	m_AttrID;
		string	m_AttrName;
		string	m_Comment;
};

class CAttrTeam
{
	/* */
	public:
		CAttrTeam(char *pszName, char *pszComment, char *pszSeps)
		{
			m_sAttrTeamName = pszName;
			m_sComment = pszComment;
			m_pStatRun = new CNewJudgeRun(pszSeps);
		}

		~CAttrTeam(void)
		{
			if (NULL != m_pStatRun)
			{
				delete m_pStatRun;
			}

			for (list < CAttrItem * >::iterator it = m_AttrList.begin();
				 it != m_AttrList.end();
				 it++)
			{
				delete (void *)(*it);
			}

			m_AttrList.clear();
		}

		void LoadSubject(char *pszSubject)
		{
			char szBuf[1024];
			strncpy(szBuf, pszSubject, 1023);

			char *p = strtok(szBuf, ",; ");
			while (p != NULL)
			{
				m_SubjectMap[p] = 0x00;
				p = strtok(NULL, ", ");
			}
		}

		void AddAttrItem(CAttrItem *pItem)
		{
			m_AttrList.push_back(pItem);
		}

		bool NeedOutput(time_t TimeStamp, int WeekDay)
		{
			return m_pStatRun->needExcute(TimeStamp, WeekDay);
		}

		string	m_sAttrTeamName;
		string	m_sComment;
		map<string, long> m_SubjectMap;
		list<CAttrItem *> m_AttrList;
		CNewJudgeRun *m_pStatRun;
};

class CFilterInfo
{
	/* */
	public:
		CFilterInfo(void)
		{
		}

		CFilterInfo(string name, string group, string level, int timeout)
		{
			m_name = name;
			m_group = group;
			m_level = level;
			m_timeout = timeout;
		}

		~CFilterInfo(void)
		{
		}

		string m_name;
		string	m_group;
		string	m_level;
		int m_timeout;
};

class CMsgGroupInfo
{
	/* */
	public:
		CMsgGroupInfo(void)
		{
		}

		CMsgGroupInfo(
		string	name,
		string	subject,
		string	time,
		int type,
		int sendgap,
		int format,
		int level,
		int id)
		{
			m_name = name;
			m_subject = subject;
			m_time = time;
			m_type = type;
			m_sendgap = sendgap;
			m_format = format;
			m_level = level;
			m_id = id;
		}

		~CMsgGroupInfo(void)
		{
		}

		string m_name;
		string	m_subject;
		string	m_time;
		int m_type;
		int m_sendgap;
		int m_format;
		int m_level;
		int m_id;
};

class CEventInfo
{
	/* */
	public:
		CEventInfo(void)
		{
		}

		CEventInfo(
		CFTDRtnWarningEventField event,
		int count,
		int type,
		string	&info1,
		string	&info2,
		string	&msggrp)
		{
			m_event = event;
			m_count = count;
			m_objects = 1;
			m_type = type;
			m_info1 = info1;
			m_info2 = info2;
			m_msggrp = msggrp;
		}

		CEventInfo(
		CFTDRtnWarningEventField event,
		int count,
		int type,
		char *info1,
		char *info2,
		char *msggrp)
		{
			m_event = event;
			m_count = count;
			m_objects = 1;
			m_type = type;
			m_info1 = info1;
			m_info2 = info2;
			m_msggrp = msggrp;
		}

		~CEventInfo(void)
		{
		}

		CEventInfo(const CEventInfo &ob)
		{
			m_event = ob.m_event;
			m_count = ob.m_count;
			m_objects = ob.m_objects;
			m_type = ob.m_type;
			m_info1 = ob.m_info1;
			m_info2 = ob.m_info2;
			m_msggrp = ob.m_msggrp;
		}

		CEventInfo &operator=(const CEventInfo &ob)
		{
			m_event = ob.m_event;
			m_count = ob.m_count;
			m_objects = ob.m_objects;
			m_type = ob.m_type;
			m_info1 = ob.m_info1;
			m_info2 = ob.m_info2;
			m_msggrp = ob.m_msggrp;
			return *this;
		}

		CFTDRtnWarningEventField m_event;
		int m_count;
		int m_type;		/// �¼����ͱ�ʶ�������ڱ�Ʋ�������
		int m_objects;	/// �¼������Ķ��������ͨ��Ϊ1�����ںϲ��¼�����1
		string	m_info1;
		string	m_info2;
		string	m_msggrp;
};

//// CMsgGenerator �������������¼���Ϣ�Ĺ����߳���
class CMsgGenerator :
	public CThread
{
	/* */
	public:
		CMsgGenerator(void);				//todo
		~ CMsgGenerator(void);				//todo

		/**�麯�����������һЩʵ��������
	* @return true:�����ɹ� false:����ʧ��
	*/
		virtual bool InitInstance(void);	//todo

		/**�麯�����������ʵ��
	*/
		virtual void ExitInstance(void);	//todo

		/**�߳̿�ʼ���У����麯�����������̳�ʵ��
	*/
		virtual void Run(void);				//todo
		
			/// ͨ��XML�����ļ����ػ���������Ϣ
		void Init(char *pszCfgPath);		//todo
		void setEventFlag(bool bFlag)
		{
			m_bEventFlag = bFlag;
		}

		void setAttrFlag(bool bFlag)
		{
			printf(
				"Notify: setAttrFlag [%s]\n",
				bFlag == true ? "TRUE" : "FALSE");
			m_bAttrFlag = bFlag;
		}

		void setNetworkEventFlag(bool bFlag)
		{
			printf(
				"Notify: setNetworkEventFlag [%s]\n",
				bFlag == true ? "TRUE" : "FALSE");
			m_bNetworkEventFlag = bFlag;
		}

		void setBusinessEventFlag(bool bFlag)
		{
			printf(
				"Notify: setBusinessEventFlag [%s]\n",
				bFlag == true ? "TRUE" : "FALSE");
			m_bBusinessEventFlag = bFlag;
		}

		bool getEventFlag(void)
		{
			return m_bEventFlag;
		}

		bool getAttrFlag(void)
		{
			return m_bAttrFlag;
		}

		bool getNetworkEventFlag(void)
		{
			return m_bNetworkEventFlag;
		}

		bool getBusinessEventFlag(void)
		{
			return m_bBusinessEventFlag;
		}

		void AddEvent(
				CFTDRtnWarningEventField &EventField,
				int iCount,
				char *info1,
				char *info2);
		void AddObjectAttr(CFTDRtnHistoryObjectAttrField &fieldInfo);

		// ����ʱ��ͨ���Ƿ�����
		// �����ã������ע�͵�CPerHourMessage����
		//bool EnablePerHourMsg() { return m_bPerHourMsgEnable; }

	/* */
	private:
		/// ͨ��XML�����ļ����ػ���������Ϣ
		void XMLInit(char *pszCfgPath);

		/// ˢ���ڴ��еĵ�ǰ����ʱ��ֵ
		void RefreshDateTime(void);
		void LoadUserConfig(CXMLNode *pNode);
		void LoadSubjectConfig(CXMLNode *pNode);
		void LoadEventConfig(CXMLNode *pEventNode);
		void LoadAttrConfig(CXMLNode *pAttrNode);
		void LoadObjectGroups(CXMLNode *pNode);
		void LoadLevelGroups(CXMLNode *pNode);
		void LoadMsgGroups(CXMLNode *pNode);
		void LoadFilters(CXMLNode *pNode);

		void LoadPollingDownConfig(CXMLNode *pNode);


		// add by cao.ning ��ȡ���ڷ�����ʱ�κ���<IP��ַ, �˿ڹؼ���>����������Ϣ
		void LoadIgnoreIpPortConfig(CXMLNode *pNode);
		// add by cao.ning �ڷǹ���ʱ����ڣ���������˿��¼��������¼���IP��ַ���˿��¼����¼������¼��������й���
		// ����¼������¼���������config�ж���Ĺ�������������¼�ֱ�Ӷ���
		// ����ֵ��true����ʾ�¼���Ϣ���Ϲ���������Ӧ��������flase���¼���Ϣ�����Ϲ���������Ӧ������
		bool FilterIgnoreIpList(CEventInfo &EventInfo);

		void RefreshObjectStatus(char *pObjectId, char *pEventName);
		void RefreshLevelStatus(char *pLevel);
		time_t	GetTimePassed(char *pDate, char *pTime);
		void DispatchEvent(CEventInfo EventInfo);
		void DispatchMsg(CEventInfo EventInfo);
		bool FilterMatch(CFilterInfo &filterInfo, time_t TimePassed);
		bool ShouldWork(CMsgGroupInfo &MsgGroupInfo);
		bool MatchDay(char *pDayStr, int iWeekday);
		bool MatchTime(char *pTimeStr, const char *pTime);
		void GenMsg(CEventInfo EventInfo, CMsgGroupInfo &MsgGroupInfo);
		void DumpMsg(CEventInfo EventInfo, CMsgGroupInfo &MsgGroupInfo);
		void ScanMsgDelayList(void);
		void ScanMsgMergeList(void);
		char *GenMsgFileName(void);
		char *GenMsgContent(CEventInfo EventInfo, CMsgGroupInfo &MsgGroupInfo);
		char * CMsgGenerator::GenMergeName(char *pMsgGroup, char *pEventName, char *pObjectID);
		string GenUserMsgContent(const char *szSubjectMsgCon, const CUserInfo &UserInfo);
		void CheckObjectAttr(void);
		void WriteObjectAttr(CAttrTeam *pItem);
		void SaveMsg(string sKeyName, CEventInfo EventInfo);

		int WriteMsg(char *pszFile, char *pszMsg);

		// add by cao.ning ���ɰ�����ģʽ�������Ϣ
		void DumpSubjectMsg(char* pszMsgContent, const char *pszSubjectId);

		// add by cao,ning ����MessageID
		UINT64 GenMessageID(int nEventID, int nMsgGroupID);
		
		// add by cao.ning ɨ��PollingDown�����е��¼�����ʱ�����㣬��ϲ��¼���д���ļ�
		void ScanPollingDownList(void);
		void UpdatePollingDownSendTime();
		// �ع�PollingDown�¼���Ϣ���ع�����Ϣ���ḽ�ӵ�strMsgContent֮��
		void GenPollingDownMsgContent(string &strMsgContent, CEventInfo	&EventInfo);

	/* */
	private:
		string	m_strPath;				// ��Ϣ�ļ��ı���·��
		string	m_strSender;			// ������ID
		int m_iMaxRetry;				// ��Ϣʧ�����Դ���
		int m_iRetrySpan;				// ʧ���ط��������
		int m_iEventMerge;				// �¼�������ϲ�������
		bool m_bEventFlag;				// �¼���Ϣ��ؿ���
		bool m_bAttrFlag;				// ָ����Ϣ��ؿ���
		bool m_bNetworkEventFlag;		// �����¼���Ϣ����
		bool m_bBusinessEventFlag;		// ҵ���¼���Ϣ����
		CDateTime m_DateTime;			// ���ڱ��浱ǰʱ��
		CSubjectInfo m_SubjectInfo;		// ���ڱ������ⶩ������Ϣ
		map<string, CUserInfo> m_UserInfo; // ���ڱ����û���ϵ��ʽ��Ϣ
		map<string, int> m_objgrpMap;	/// �����������ӳ���
		map<string, list<string> >	m_objgrpExcList;	/// ���������Ķ����ų��б�
		map<string, list<string> >	m_objgrpIncList;	/// ���������Ķ���ذ��б�
		map<string, int> m_lvlgrpMap;					/// ���漶������ӳ���
		map<string, list<string> >	m_lvlgrpExcList;	/// ���漶����Ķ����ų��б�
		map<string, list<string> >	m_lvlgrpIncList;	/// ���漶����Ķ���ذ��б�
		map<string, CFilterInfo> m_filterInfo;			/// ��������Ϣ��
		map<string, list<string> >	m_filterMsgMap;		/// ��������Ӧ��Ϣ��ӳ��
		map<string, CMsgGroupInfo>	m_msggrpInfo;		/// ��Ϣ����Ϣ��
		map<string, time_t> m_msgtimeMap;				/// ������Ϣ�������ʱ���ӳ���
		TemplateMutexCatch<CEventInfo>	m_EventList;	/// �¼��б�
		map<string, list<CEventInfo> >	m_MsgDelayList;		/// ���ӳٷ��͵���Ϣ�б�
		map<string, list<CEventInfo> >  m_MsgMergeList;	/// ���ϲ����͵���Ϣ�б�,�����GM_13100901
		map<string, long> m_AttrValue;					// ��ʷָ��ֵMap ��:'TRADE.PuDian.app.tkernel:TradeSize' - 25564
		list<CAttrTeam *> m_AttrTeamList;				// ָ�����б�

		// add by cao.ning
		// // �����ã������ע�͵�CPerHourMessage����
		//bool m_bPerHourMsgEnable;
		
		// add by cao.ning
		bool m_IgnoreIpEnable;			// �Ƿ��ڷ�����ʱ�κ���<IP��ַ, �˿ڹؼ���>�б��е���Ϣ��
		map<string, list<string> > m_IgnoreIpPortList;		// <IP��ַ, �˿ڹؼ���>�б�
		
		// add by cao.ning
		// PollingDown
		// pair<������ʼʱ�䣬���ʹ���>	����̶�Ϊ10����
		vector<pair<string, int> > m_PollingDownSendTime;		// �˿�PollingDown�¼��ķ���ʱ����Ϣ
		vector<pair<string, int> >::iterator m_NextSendTimeIter;
		time_t m_NextSendTime;
		int m_SendCount;
		int m_PollingDownMaxCount;		// �˿�PollingDown�¼���Ϸ��ͣ�����������ϵ��������
		TemplateMutexCatch<CEventInfo> m_PollingDownEventList;	// ���ڻ���ȴ����͵�PollingDown�¼�
};
#endif
