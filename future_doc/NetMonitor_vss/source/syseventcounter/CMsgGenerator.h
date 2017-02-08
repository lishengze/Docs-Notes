/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CMsgGenerator.h
///@brief	定义了生成消息文件的工具类
///@history
///20111214	晏鹤春	创建该文件
///20111223	晏鹤春	增加消息队列及落地时间策略的处理
///20121112	晏鹤春	重构消息线程类，区分网络事件与业务事件
///20131009 晏鹤春  变更号GM_13100901，告警事件消息增加合并推送功能
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

		///拷贝构造函数
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

		///判断字符串是否符合时间段频率定义格式
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

		///判断是否需要取该指标
			///@param	nNowSec	从系统中取得的秒数（已经补充了时差）
			///@return	true需要执行,false不需要执行
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
					/// 当日不需运行
					m_nNextRunSec = Timestamp - DaySecs + 86400;
					return false;
				}
				else
				{
					vector<CSeps> &vecSep = SepsIt->second;
					for (unsigned int i = 0; i < vecSep.size(); i++)
					{
						if (DaySecs >= vecSep[i].m_nStart
						&&	DaySecs <= vecSep[i].m_nEnd)	// 取该时间段的采样频率
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
		///操作时段数组
		map<int, vector<CSeps> > m_Seps;

		///下一次操作时间,从当日零点开始的秒数
		int m_nNextRunSec;

		///若当前需执行,对应的时间间隔值
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

	// key: SubjectID value: true/false 该订阅组是否是扩展模式
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
		int m_type;		/// 事件类型标识，可用于标计差异特征
		int m_objects;	/// 事件关联的对象个数，通常为1，对于合并事件大于1
		string	m_info1;
		string	m_info2;
		string	m_msggrp;
};

//// CMsgGenerator 类是用于生成事件消息的工具线程类
class CMsgGenerator :
	public CThread
{
	/* */
	public:
		CMsgGenerator(void);				//todo
		~ CMsgGenerator(void);				//todo

		/**虚函数，子类可做一些实例化工作
	* @return true:创建成功 false:创建失败
	*/
		virtual bool InitInstance(void);	//todo

		/**虚函数，子类清楚实例
	*/
		virtual void ExitInstance(void);	//todo

		/**线程开始运行，纯虚函数，子类必须继承实现
	*/
		virtual void Run(void);				//todo
		
			/// 通过XML配置文件加载基本配置信息
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

		// 整点时间通告是否启用
		// 已弃用，详见被注释的CPerHourMessage定义
		//bool EnablePerHourMsg() { return m_bPerHourMsgEnable; }

	/* */
	private:
		/// 通过XML配置文件加载基本配置信息
		void XMLInit(char *pszCfgPath);

		/// 刷新内存中的当前日期时间值
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


		// add by cao.ning 读取“在非正常时段忽略<IP地址, 端口关键字>”的配置信息
		void LoadIgnoreIpPortConfig(CXMLNode *pNode);
		// add by cao.ning 在非工作时间段内，如果发生端口事件，根据事件的IP地址，端口事件的事件名和事件描述进行过滤
		// 如果事件名和事件描述符合config中定义的过滤条件，则该事件直接丢弃
		// 返回值：true，表示事件信息符合过滤条件，应当丢弃；flase，事件信息不符合过滤条件，应当缓存
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

		// add by cao.ning 生成按主题模式的落地信息
		void DumpSubjectMsg(char* pszMsgContent, const char *pszSubjectId);

		// add by cao,ning 生成MessageID
		UINT64 GenMessageID(int nEventID, int nMsgGroupID);
		
		// add by cao.ning 扫描PollingDown队列中的事件，若时间满足，则合并事件后写入文件
		void ScanPollingDownList(void);
		void UpdatePollingDownSendTime();
		// 重构PollingDown事件消息，重构的消息将会附加到strMsgContent之后
		void GenPollingDownMsgContent(string &strMsgContent, CEventInfo	&EventInfo);

	/* */
	private:
		string	m_strPath;				// 消息文件的保存路径
		string	m_strSender;			// 发送者ID
		int m_iMaxRetry;				// 消息失败重试次数
		int m_iRetrySpan;				// 失败重发间隔秒数
		int m_iEventMerge;				// 事件按对象合并的域级数
		bool m_bEventFlag;				// 事件信息落地开关
		bool m_bAttrFlag;				// 指标信息落地开关
		bool m_bNetworkEventFlag;		// 网络事件消息开关
		bool m_bBusinessEventFlag;		// 业务事件消息开关
		CDateTime m_DateTime;			// 用于保存当前时间
		CSubjectInfo m_SubjectInfo;		// 用于保存主题订阅组信息
		map<string, CUserInfo> m_UserInfo; // 用于保存用户联系方式信息
		map<string, int> m_objgrpMap;	/// 保存对象组结果映射表
		map<string, list<string> >	m_objgrpExcList;	/// 保存对象组的对象排除列表
		map<string, list<string> >	m_objgrpIncList;	/// 保存对象组的对象必包列表
		map<string, int> m_lvlgrpMap;					/// 保存级别组结果映射表
		map<string, list<string> >	m_lvlgrpExcList;	/// 保存级别组的对象排除列表
		map<string, list<string> >	m_lvlgrpIncList;	/// 保存级别组的对象必包列表
		map<string, CFilterInfo> m_filterInfo;			/// 过滤器信息表
		map<string, list<string> >	m_filterMsgMap;		/// 过滤器对应消息组映射
		map<string, CMsgGroupInfo>	m_msggrpInfo;		/// 消息组信息表
		map<string, time_t> m_msgtimeMap;				/// 保存消息与最后发送时间的映射表
		TemplateMutexCatch<CEventInfo>	m_EventList;	/// 事件列表
		map<string, list<CEventInfo> >	m_MsgDelayList;		/// 待延迟发送的消息列表
		map<string, list<CEventInfo> >  m_MsgMergeList;	/// 待合并发送的消息列表,变更号GM_13100901
		map<string, long> m_AttrValue;					// 历史指标值Map 如:'TRADE.PuDian.app.tkernel:TradeSize' - 25564
		list<CAttrTeam *> m_AttrTeamList;				// 指标组列表

		// add by cao.ning
		// // 已弃用，详见被注释的CPerHourMessage定义
		//bool m_bPerHourMsgEnable;
		
		// add by cao.ning
		bool m_IgnoreIpEnable;			// 是否“在非正常时段忽略<IP地址, 端口关键字>列表中的信息”
		map<string, list<string> > m_IgnoreIpPortList;		// <IP地址, 端口关键字>列表
		
		// add by cao.ning
		// PollingDown
		// pair<发送起始时间，发送次数>	间隔固定为10分钟
		vector<pair<string, int> > m_PollingDownSendTime;		// 端口PollingDown事件的发送时间信息
		vector<pair<string, int> >::iterator m_NextSendTimeIter;
		time_t m_NextSendTime;
		int m_SendCount;
		int m_PollingDownMaxCount;		// 端口PollingDown事件组合发送，用于限制组合的最大数量
		TemplateMutexCatch<CEventInfo> m_PollingDownEventList;	// 用于缓存等待发送的PollingDown事件
};
#endif
