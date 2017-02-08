/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CStatusSubscriber.h
///@brief	定义了订阅事件处理消息的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
#ifndef REF_CSTATUSSUBSCRIBER_H
#define REF_CSTATUSSUBSCRIBER_H

#include "public.h"
#include "CachedFlow.h"
#include "CachedFileFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"

#include "slogparser.h"

//声明
class CStatusSubscriber;
class CDirectlySlogDecode;

/////////////////////////////////////////////////////////////////////////
///CObjectAttrKey定义了ObjectID和AttrID作为map关键字的类
///@author	周建军
///@version	1.0,20080710
/////////////////////////////////////////////////////////////////////////
class CObjectAttrKey
{
	/* */
	public:

		///构造函数
		CObjectAttrKey(void)
		{
			m_nObjectID = "";
			m_nAttrID = "";
		}

		///构造函数
			///@param	m_nObjectID	对象ID
			///@param	m_nAttrID	指标ID
		CObjectAttrKey(string nObjectID, string nAttrID)
		{
			m_nObjectID = nObjectID;
			m_nAttrID = nAttrID;
		}

		///拷贝构造函数
		CObjectAttrKey(const CObjectAttrKey &ob)
		{
			m_nObjectID = ob.m_nObjectID;
			m_nAttrID = ob.m_nAttrID;
		}

		///重载=运算符
		void operator=(const CObjectAttrKey &ob)
		{
			m_nObjectID = ob.m_nObjectID;
			m_nAttrID = ob.m_nAttrID;
		}

		///重载>运算符
		friend bool operator>(
		const CObjectAttrKey &ob1,
		const CObjectAttrKey &ob2)
		{
			if (ob1.m_nObjectID > ob2.m_nObjectID)
			{
				return true;
			}
			else if (ob1.m_nObjectID == ob2.m_nObjectID)
			{
				if (ob1.m_nAttrID > ob2.m_nAttrID)
				{
					return true;
				}
			}

			return false;
		}

		///重载>运算符
		friend bool operator < (const CObjectAttrKey &ob1, const CObjectAttrKey &ob2)
		{
			if (ob1.m_nObjectID < ob2.m_nObjectID)
			{
				return true;
			}
			else if (ob1.m_nObjectID == ob2.m_nObjectID)
			{
				if (ob1.m_nAttrID < ob2.m_nAttrID)
				{
					return true;
				}
			}

			return false;
		}

		///重载==运算符
		friend bool operator==(
		const CObjectAttrKey &ob1,
		const CObjectAttrKey &ob2)
		{
			if (ob1.m_nObjectID == ob2.m_nObjectID
			&&	ob1.m_nAttrID == ob2.m_nAttrID)
			{
				return true;
			}

			return false;
		}

	/* */
	public:
		///对象ID
		string	m_nObjectID;

		///指标ID
		string	m_nAttrID;
};

class CTimeValue
{
	/* */
	public:
		///上次发送的时间
		time_t	m_nSendTime;

		///指标的序列号
		int m_nOrderId;

		///告警的主题
		string	m_msgSubjectId;

		///报警的描述信息
		string	m_warningInfo;

	/* */
	public:

		///构造函数
		CTimeValue(void)
		{
			m_nSendTime = 0;
			m_nOrderId = 0;
			m_msgSubjectId = "";
			m_warningInfo = "";
		}

		///构造函数
			///@param	nSendTime	最新写告警时间
			///@param	nOrderId	告警
		CTimeValue(
		time_t	nSendTime,
		int nOrderId,
		const char	*msgSubjectId,
		const char	*warningInfo)
		{
			m_nOrderId = nOrderId;
			m_nSendTime = nSendTime;
			m_msgSubjectId = msgSubjectId;
			m_warningInfo = warningInfo;
		}

		///拷贝构造函数
		CTimeValue(const CTimeValue &ob)
		{
			m_nSendTime = ob.m_nSendTime;
			m_nOrderId = ob.m_nOrderId;
			m_msgSubjectId = ob.m_msgSubjectId;
			m_warningInfo = ob.m_warningInfo;
		}

		///重载“=”运算符
		void operator=(const CTimeValue &ob)
		{
			m_nSendTime = ob.m_nSendTime;
			m_nOrderId = ob.m_nOrderId;
			m_msgSubjectId = ob.m_msgSubjectId;
			m_warningInfo = ob.m_warningInfo;
		}
};

class CLatestOrderOfParticipation
{
	/* */
	public:
		string	GetTimeLine(string strCurTime);

		void AppendAnewRecord(CFTDRtnParticTradeOrderStatesField *pRtn);

		string	strPart;
		string	strUser;

		//统计时长， 单位是秒
		int nTimeWidth;

		//最近的时间点， 早于该时间的包丢弃掉
		string	strLastDate;
		string	strLastTime;

		//需要往数据库中新增一条数据
		bool bNedInsrtARec;

		//已经过滤掉重复数据
		bool bSafe;

		//存放所有时间统计数据
		//key:date:time
		map<string, CFTDRtnParticTradeOrderStatesField> mp_sField;

		set<string> setShdInsert;
		set<string> setSdUpdate;
};

class CStatusSubscriberSkeleton :
	public CFTDCSubscriber
{
	/* */
	public:
		///构造函数	
		CStatusSubscriberSkeleton(
			CStatusSubscriber *pParantHandler,
			int nFlowSeq);

		///析构函数
		~ CStatusSubscriberSkeleton(void);

		///设置通讯阶段号函数
			///@param	wCommPhaseNo	需要设置的通信阶段号
		virtual void SetCommPhaseNo(WORD wCommPhaseNo);

		///获取流序列号函数
			///@return	返回流的当前序列号
		virtual WORD GetSequenceSeries(void);	//流编号
		
			///获取收到流中包含的包总数函数
			///@return	返回当前订阅收到的包总数
		virtual DWORD GetReceivedCount(void);	//收到的包个数
		
			///订阅收到的包处理函数,是发布/订阅模型收到的数据包
			///@param	pMessage	订阅者收到的包地址
		virtual void HandleMessage(CFTDCPackage *pMessage);

		int m_nSeries;

		///对应流文件
		CCachedFileFlow *m_pFlow;
		CStatusSubscriber *m_pStatusSubHandler;
};

class CStatusSubscriber :
	public CFTDCSubscriber
{
	/* */
	public:
		///构造函数	
		CStatusSubscriber(void);

		///析构函数
		~ CStatusSubscriber(void);

		///初始化cutline
		void InitTradeOrderCutLine(void);

		///设置通讯阶段号函数
			///@param	wCommPhaseNo	需要设置的通信阶段号
		virtual void SetCommPhaseNo(WORD wCommPhaseNo);

		///获取流序列号函数
			///@return	返回流的当前序列号
		virtual WORD GetSequenceSeries(void);	//流编号
		
			///获取收到流中包含的包总数函数
			///@return	返回当前订阅收到的包总数
		virtual DWORD GetReceivedCount(void);	//收到的包个数
		
			///订阅收到的包处理函数,是发布/订阅模型收到的数据包
			///@param	pMessage	订阅者收到的包地址
		virtual void HandleMessage(CFTDCPackage *pMessage);

		///清除流容器函数
		bool Truncate(int nFlowSeq)
		{
			// 		if (nFlowSeq != m_nFlowSeq)
			// 		{
			// 			printf("要清除的流编号 %d 与本订阅者的流编号 %d 不相同 \n", nFlowSeq, m_nFlowSeq);
			// 			fflush(stdout);
			// 			return false;
			// 		}
			return m_pSubEnd[nFlowSeq]->m_pFlow->Truncate(0);
		}

	/* */
	private:
		///系统日志处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnSyslogInfoTopic(CFTDCPackage *pFTDCPackage);

#if 0
		///订阅对象状态指标处理函数
		    ///@param	pFTDCPackage	订阅者收到的包地址
		void OnRtnNetObjectAttrTopic(CFTDCPackage *pFTDCPackage);
#endif

	/* */
	public:

		///重新将流数据导入内存数据库
		void ReLoad(int nFlowSeq);

		void InitFlow( );

		void UpdateParticTrade2DbByTimer(void);

	/* */
	private:
		/// Added by Henchi, 20100120
		CJudgeRun m_resetRun;
		CMutex	m_lockObjectAttr;

	/* */
	public:

		///发送数据包使用的缓冲区
		CFTDCPackage m_pkgSend;

		///保存数据包的流地址
		//	CCachedFileFlow *m_pFws[MAX_EVENTFLOWNUM];
		CStatusSubscriberSkeleton *m_pSubEnd[MAX_EVENTFLOWNUM + 1];

		///当前流文件
		//	CCachedFileFlow *m_pFlow;
			///订阅流的编号

	//	int  m_nFlowSeq;
};

class CFileValidContent
{
	/* */
	public:
		CFileValidContent(void) :
		nValidEnd(0)
		{
		};

		QWORD nValidEnd;

		void AddNewFileContent(QWORD nContentEnd, int nContentSize);

		//key: start of block
		//value: size of block
		map<QWORD, QWORD> mapValidContent;
};

class CFileOperation
{
	/* */
	public:
		CFileOperation(void)
		{
			mLength = 0;
		}

		~CFileOperation(void)
		{
			for (m_it = m_mapHandler.begin();
				 m_it != m_mapHandler.end();
				 m_it++)
			{
				if (m_it->second != NULL)
				{
					fclose(m_it->second);
				}
			}
		}

		///附加内容到指定文件函数
			///@param	fileName	文件名
			///@param	fileContent	文件内容指针
			///@param	length	文件内容长度
			///@return	返回写文件结果，true成功，false失败
		bool addFileContent(
		const char	*fileName,
		const char	*fileContent,
		const int length)
		{
			memcpy(mBuffer + mLength, fileContent, length);
			mLength = mLength + length;
			return true;
		}

		bool WriteToFile(const char *fileName, const long endSize)
		{
			FILE *fp;

			m_it = m_mapHandler.find(string(fileName));
			if (m_it == m_mapHandler.end())
			{
				fp = initFileHandle(fileName);
				m_mapHandler[string(fileName)] = fp;
			}
			else
			{
				fp = m_it->second;
			}

			if (fseek(fp, endSize - mLength, SEEK_SET) != 0)
			{
				printf("文件 %s 调用fseek 出错！ \n", fileName);
			}

			if (fwrite(mBuffer, mLength, 1, fp) != 1)
			{
				printf("Write File %s Failed, exit\n", fileName);
				exit(0);
			}

#ifdef WIN32
			if (chsize(fileno(fp), endSize) != 0)
			{
				printf("文件 %s 调用chsize 出错！ \n", fileName);
			}

#else
			ftruncate(fileno(fp), endSize);
#endif
			m_mapFileValidEnd[fileName].AddNewFileContent(endSize, mLength);
			mLength = 0;

			fflush(fp);

			return true;
		}

	/* */
	protected:
		///初始化文件描述符
		FILE *initFileHandle(const char *fileName);

	/* */
	private:
		map<string, FILE *> m_mapHandler;
		map<string, FILE *>::iterator m_it;
		char mBuffer[6000];
		int mLength;

	/* */
	public:
		//////////////////////////////////////////////////////////////////////////
		//add by feng.q, 记录文件有效末尾
		//key: file name
		//value:
		map<string, CFileValidContent>	m_mapFileValidEnd;
};

class CPeakKey
{
	/* */
	public:
		///应用对象名，如PuDian.app.tkernel.1
		string	m_sObject;

		///监控最大值的指标名称，如HandleOrderInsert
		string	m_sAttr;

		///监控最大值指标的相关指标名，如HandleOrderInsertError
		string	m_sRltAttr;

	/* */
	public:

		///构造函数
			///@param	pObject	监控对象名
			///@param	pAttr	指标名称
			///@param	pRltAttr	相关指标名称
		CPeakKey(char *pObject, char *pAttr, char *pRltAttr)
		{
			m_sObject = pObject;
			m_sAttr = pAttr;
			m_sRltAttr = pRltAttr;
		}

		CPeakKey(const CPeakKey &ob)
		{
			m_sObject = ob.m_sObject;
			m_sAttr = ob.m_sAttr;
			m_sRltAttr = ob.m_sRltAttr;
		}

		void operator=(const CPeakKey &ob)
		{
			m_sObject = ob.m_sObject;
			m_sAttr = ob.m_sAttr;
			m_sRltAttr = ob.m_sRltAttr;
		}

		///重载<运算符
		friend bool operator < (const CPeakKey &ob1, const CPeakKey &ob2)
		{
			if (ob1.m_sObject < ob2.m_sObject)
			{
				return true;
			}
			else if (ob1.m_sObject == ob2.m_sObject)
			{
				if (ob1.m_sAttr < ob2.m_sAttr)
				{
					return true;
				}
				else if (ob1.m_sAttr == ob2.m_sAttr)
				{
					if (ob1.m_sRltAttr < ob2.m_sRltAttr)
					{
						return true;
					}
				}
			}

			return false;
		}

		///重载==运算符
		friend bool operator==(const CPeakKey &ob1, const CPeakKey &ob2)
		{
			if ((ob1.m_sObject == ob2.m_sObject)
			&&	(ob1.m_sAttr == ob2.m_sAttr)
			&&	(ob1.m_sRltAttr == ob2.m_sRltAttr))
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		///重载输出
		//friend ostream& operator << (ostream& output, CPeakKey& ob)
		//{
		//	output<<" m_sObject: "<<ob.m_sObject
		//		<<" m_sAttr: "<<ob.m_sAttr
		//		<<" m_sRtlAttr: "<<ob.m_sRltAttr;
		//	return output;
		//}
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
			m_pStatRun = new CJudgeRun(pszSeps);
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

			char *p = strtok(szBuf, ", ");
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

		bool NeedOutput(const int timeSec)
		{
			return m_pStatRun->needExcute(timeSec);
		}

		string	m_sAttrTeamName;
		string	m_sComment;
		map<string, long> m_SubjectMap;
		list<CAttrItem *> m_AttrList;
		CJudgeRun *m_pStatRun;
};

class CDirectlySlogDecode
{
	/* */
	public:
		~ CDirectlySlogDecode(void);

		void Clear(void)
		{
			map<string, CSlogDescript>::iterator m_Iter;
			for (m_Iter = m_mapSlogDescript.begin();
				 m_Iter != m_mapSlogDescript.end();
				 m_Iter++)
			{
				CSlogConnectionMap::iterator itor = m_Iter->second.
					m_mapSlogConnection.Begin();
				while (!itor.IsEnd())
				{
					delete(*itor);
					itor++;
				}

				m_Iter->second.m_mapSlogConnection.Clear();

				if (m_Iter->second.m_fpSlog != NULL)
				{
					fclose(m_Iter->second.m_fpSlog);
					m_Iter->second.m_fpSlog = NULL;
				}
			}

			m_mapSlogDescript.clear();
		}

		CSlogConnection *CreateSlogConnection(CSlogDescript &sDescrip);
		CSlogConnection *GetSlogConnection(CSlogDescript &sDescrip);
		bool DelSlogConnection(CSlogDescript &sDescrip);

		void RecNewSlogPackeg(const char *fileName, const QWORD endSize);

		void ReadOnePackeg(CSlogDescript &sDescrip, const QWORD endSize);

		bool HandleOnePackeg(CSlogDescript &sDescrip);

		void GetSlogFileStatus(int nFrontID, char *pLogBuf);

	/* */
	private:
		//key: slog文件名称
		map<string, CSlogDescript>	m_mapSlogDescript;
};

//bool Compare(const CFTDRspQryHistoryTradePeakField &l,const CFTDRspQryHistoryTradePeakField &r);
//
//struct testCom {
//	bool operator () (CFTDRspQryHistoryTradePeakField &l, CFTDRspQryHistoryTradePeakField &r)
//	{
//		return true;
//	}
//};
#endif // REF_CSTATUSSUBSCRIBER_H
