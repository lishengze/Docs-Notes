/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CStatusSubscriber.h
///@brief	�����˶����¼�������Ϣ����
///@history
///20080510	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
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
#include "SQLAPI.h"
#include <DBOperator.h>

#include "slogparser.h"

//����
class CStatusSubscriber;
class CDirectlySlogDecode;

/////////////////////////////////////////////////////////////////////////
///CObjectAttrKey������ObjectID��AttrID��Ϊmap�ؼ��ֵ���
///@author	�ܽ���
///@version	1.0,20080710
/////////////////////////////////////////////////////////////////////////
class CObjectAttrKey
{
	/* */
	public:

		///���캯��
		CObjectAttrKey(void)
		{
			m_nObjectID = "";
			m_nAttrID = "";
		}

		///���캯��
			///@param	m_nObjectID	����ID
			///@param	m_nAttrID	ָ��ID
		CObjectAttrKey(string nObjectID, string nAttrID)
		{
			m_nObjectID = nObjectID;
			m_nAttrID = nAttrID;
		}

		///�������캯��
		CObjectAttrKey(const CObjectAttrKey &ob)
		{
			m_nObjectID = ob.m_nObjectID;
			m_nAttrID = ob.m_nAttrID;
		}

		///����=�����
		void operator=(const CObjectAttrKey &ob)
		{
			m_nObjectID = ob.m_nObjectID;
			m_nAttrID = ob.m_nAttrID;
		}

		///����>�����
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

		///����>�����
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

		///����==�����
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
		///����ID
		string	m_nObjectID;

		///ָ��ID
		string	m_nAttrID;
};

class CTimeValue
{
	/* */
	public:
		///�ϴη��͵�ʱ��
		time_t	m_nSendTime;

		///ָ������к�
		int m_nOrderId;

		///�澯������
		string	m_msgSubjectId;

		///������������Ϣ
		string	m_warningInfo;

	/* */
	public:

		///���캯��
		CTimeValue(void)
		{
			m_nSendTime = 0;
			m_nOrderId = 0;
			m_msgSubjectId = "";
			m_warningInfo = "";
		}

		///���캯��
			///@param	nSendTime	����д�澯ʱ��
			///@param	nOrderId	�澯
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

		///�������캯��
		CTimeValue(const CTimeValue &ob)
		{
			m_nSendTime = ob.m_nSendTime;
			m_nOrderId = ob.m_nOrderId;
			m_msgSubjectId = ob.m_msgSubjectId;
			m_warningInfo = ob.m_warningInfo;
		}

		///���ء�=�������
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

		//ͳ��ʱ���� ��λ����
		int nTimeWidth;

		//�����ʱ��㣬 ���ڸ�ʱ��İ�������
		string	strLastDate;
		string	strLastTime;

		//��Ҫ�����ݿ�������һ������
		bool bNedInsrtARec;

		//�Ѿ����˵��ظ�����
		bool bSafe;

		//�������ʱ��ͳ������
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
		///���캯��	
		CStatusSubscriberSkeleton(
			CStatusSubscriber *pParantHandler,
			int nFlowSeq);

		///��������
		~ CStatusSubscriberSkeleton(void);

		///����ͨѶ�׶κź���
			///@param	wCommPhaseNo	��Ҫ���õ�ͨ�Ž׶κ�
		virtual void SetCommPhaseNo(WORD wCommPhaseNo);

		///��ȡ�����кź���
			///@return	�������ĵ�ǰ���к�
		virtual WORD GetSequenceSeries(void);	//�����
		
			///��ȡ�յ����а����İ���������
			///@return	���ص�ǰ�����յ��İ�����
		virtual DWORD GetReceivedCount(void);	//�յ��İ�����
		
			///�����յ��İ�������,�Ƿ���/����ģ���յ������ݰ�
			///@param	pMessage	�������յ��İ���ַ
		virtual void HandleMessage(CFTDCPackage *pMessage);

		int m_nSeries;

		///��Ӧ���ļ�
		CCachedFileFlow *m_pFlow;
		CStatusSubscriber *m_pStatusSubHandler;
};

class CWriteDBThread : public CThread
{
	/* */
	private:

		/// �߳�ID��
		int m_nThreadID;

		CStatusSubscriber *pStatusSub;

	/* */
	public:
		CWriteDBThread(int nThreadID)
		{
			m_nThreadID = nThreadID;
		}

		CWriteDBThread(void)
		{
		}

		~CWriteDBThread(void)
		{
		}

		/**�麯�����������һЩʵ��������
	* @return true:�����ɹ� false:����ʧ��
	*/
		virtual bool InitInstance(void);

		/**�麯�����������ʵ��
	*/
		virtual void ExitInstance(void);

		/**�߳̿�ʼ���У����麯�����������̳�ʵ��
	*/
		virtual void Run(void);

		void setSubscriber(CStatusSubscriber *statusSub)
		{
			pStatusSub = statusSub;
		}

};

class CStatusSubscriber :
	public CFTDCSubscriber
{
	/* */
	public:
		///���캯��	
		CStatusSubscriber(void);

		///��������
		~ CStatusSubscriber(void);

		///����ͨѶ�׶κź���
			///@param	wCommPhaseNo	��Ҫ���õ�ͨ�Ž׶κ�
		virtual void SetCommPhaseNo(WORD wCommPhaseNo);

		///��ȡ�����кź���
			///@return	�������ĵ�ǰ���к�
		virtual WORD GetSequenceSeries(void);	//�����
		
			///��ȡ�յ����а����İ���������
			///@return	���ص�ǰ�����յ��İ�����
		virtual DWORD GetReceivedCount(void);	//�յ��İ�����
		
			///�����յ��İ�������,�Ƿ���/����ģ���յ������ݰ�
			///@param	pMessage	�������յ��İ���ַ
		virtual void HandleMessage(CFTDCPackage *pMessage);

		///�������������
		bool Truncate(int nFlowSeq)
		{
			// 		if (nFlowSeq != m_nFlowSeq)
			// 		{
			// 			printf("Ҫ���������� %d �뱾�����ߵ������ %d ����ͬ \n", nFlowSeq, m_nFlowSeq);
			// 			fflush(stdout);
			// 			return false;
			// 		}
			return m_pSubEnd[nFlowSeq]->m_pFlow->Truncate(0);
		}

	/* */
	private:
		///ϵͳ��־������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnSyslogInfoTopic(CFTDCPackage *pFTDCPackage);

#if 0
		///���Ķ���״ָ̬�괦����
		    ///@param	pFTDCPackage	�������յ��İ���ַ
		void OnRtnNetObjectAttrTopic(CFTDCPackage *pFTDCPackage);
#endif

		///���ĸ澯�¼���Ϣ������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnWarningEventTopic(CFTDCPackage *pFTDCPackage);

		///����ҵ�����״̬������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnHistoryObjectAttrTopic(CFTDCPackage *pFTDCPackage);

		///��ֵ״̬������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnHistoryTradePeakTopic(CFTDCPackage *pFTDCPackage);

		//2008.09.19 add by wu.yb
			///Cpuʹ�����
		void OnRtnTopCpuInfoTopic(CFTDCPackage *pFTDCPackage);

		///�ڴ�ʹ�����
		void OnRtnTopMemInfoTopic(CFTDCPackage *pFTDCPackage);

		///����ʹ�����
		void OnRtnNetworkInfoTopic(CFTDCPackage *pFTDCPackage);

		// Added by Henchi, 20091228
			///DBQuery��Ϣ��
		void OnRtnDBQueryTopic(CFTDCPackage *pFTDCPackage);

		///Ѳ������Ϣ
		void OnRtnNetMonitorTaskResultTopic(CFTDCPackage *pFTDCPackage);

		///��Ա״̬�仯���
		void OnRtnNetPartyLinkStatusInfoTopic(CFTDCPackage *pFTDCPackage);

		///���߽�����
		void OnRtnNetBaseLineResultTopic(CFTDCPackage *pFTDCPackage);

		///����ping���
		void OnRtnNetLocalPingResultTopic(CFTDCPackage *pFTDCPackage);

		///Զ��ping���
		void OnRtnNetRomotePingResultTopic(CFTDCPackage *pFTDCPackage);

		///��Ա����ͳ��
		void OnRtnParticTradeOrderStatesTopic(CFTDCPackage *pFTDCPackage);

		///����io
		void OnRtnDiskIOTopic(CFTDCPackage *pFTDCPackage);

		///ϵͳ·��
		void OnRtnRouteInfoTopic(CFTDCPackage *pFTDCPackage);

		///ϵͳ״̬
		void OnRtnStatInfoTopic(CFTDCPackage *pFTDCPackage);

		///������Ϣ
		void OnRtnTopProcessInfoTopic(CFTDCPackage *pFTDCPackage);

		bool IsExcludedObject(char *objectID);

		// Added by Henchi, 20100120
			///���˶���ָ��ͳ����Ϣ
		void FiltrateRtnHistoryObjectAttr(
				CFTDRtnHistoryObjectAttrField &fieldInfo);

		void AddEventCount(CFTDRtnWarningEventField &fieldInfo);

	/* */
	public:
		///��鵱ǰʱ���Ƿ�Ӧ������ָ��
		void CheckObjectAttrOutput(time_t gTime);

		///����Ƿ���Ҫ�������ݼ�����
		void CheckEventCount(time_t gTime);

		///���½������ݵ����ڴ����ݿ�
		void ReLoad(int nFlowSeq);

		void InitDBParam(
				const char	*pStrDate,
				const char	*pStrUser,
				const char	*pStrCutLine);

		void UpdateParticTrade2DbByTimer(void);

		//��Ҫ���ݿ����ӣ��޸�ȫ������
		void InitTradeOrderCutLine(void);

		bool InsertNewCutLine2DB(
				const char	*pStrDate,
				const char	*pStrUser,
				const char	*pStrCutLine);

	/* */
	private:
		///20080717 add by wu.yb
		SAConnection *m_sqlConnect;

		CMutex m_sqlMutex;

		///�Զ��������ݿ���
		bool m_bTryConnectDbFlag;

		///��ǰʱ��������Ƿ���Ҫд�����ݿ��ǣ����true��ʾ��Ҫд�룬false��ʾ����Ҫд��
		bool m_bSepsDbFlag;

		/// Added by Henchi, 20100120
		CJudgeRun m_resetRun;
		CMutex	m_lockObjectAttr;
		map<string, CFTDRtnHistoryObjectAttrField>	m_mapHistoryObjectAttr;

		//key: ParticipantID_UserID
		map<string, CLatestOrderOfParticipation> m_mapPatMemOrderCnt;

		bool connectDB(void);

		/// the database server connection status
			/// ����ʹ�õ�SQLAPI�汾û������������µİ汾��
		bool isAlive(SAConnection *conn);

		void InsertRtnWarningEventTopic(
				const CFTDRtnWarningEventField	&fieldInfo);
		void InsertRtnHistoryObjectAttrTopic(
				const CFTDRtnHistoryObjectAttrField &fieldInfo);
		string	getConnectStr(
					const string &ip,
					const string &port,
					const string &dbName);

		//2008.09.19 add by wu.yb
		void InsertRtnTopCpuInfoTopic(const CFTDRtnTopCpuInfoField &fieldInfo);
		void InsertRtnTopMemInfoTopic(const CFTDRtnTopMemInfoField &fieldInfo);
		void InsertRtnNetworkInfoTopic(
				const CFTDRtnNetworkInfoField &fieldInfo);

		// Added by Henchi, 20091229
		void InsertRtnDBQueryAccessLog(const CFTDRtnDBQueryField &fieldInfo);

		//20081217 add by zhou.jj
			///��ȡ���ݿ��ֵ��Ϣ���¼����
		void GetTradePeakFromDB(void);
		bool mbPeakFlag;	///�����ݿ����Ƿ��Ѿ���ȡ����ʷ��ֵ��Ϣ��true��ʾ�Ѿ���ȡ����falseΪ��

		//Added by Lee 2014.11.10
		///����ָ��HistoryObjectAttr����
		TemplateMutexCatch<CFTDRtnHistoryObjectAttrField> m_listHisObjectAttr;


	/* */
	public:

		///��ȡObjectAttr����
		bool getObjectAttr(CFTDRtnHistoryObjectAttrField &objectAttr)
		{
			return m_listHisObjectAttr.get(objectAttr);
		}
		//��ȡ����ָ��
		SAConnection *getSAConnection()
		{
			return  m_sqlConnect;
		}

		CMutex& getSqlLock()
		{
			return m_sqlMutex;
		}
		///�ж����ݿ��Ƿ����ӳɺ���
		bool IsConnectDB( )
		{
			return connectDB();
		}

		///�����Զ��������ݿ��Ǻ���
			///@param	bTryConnectFlag	������ǣ����true��ʾҪ�������ݿ⣬false��ʾ��ʱ���������ݿ�
			///@param	bSepsDbFlag	��ǰʱ���Ƿ���Ҫ������д�����ݿ�
		void SetTryConnectDbFlag(bool bTryConnectFlag, bool bSepsDbFlag = false)
		{
			m_bTryConnectDbFlag = bTryConnectFlag;
			m_bSepsDbFlag = bSepsDbFlag;
		}

		///�������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;

		///�������ݰ�������ַ
		//	CCachedFileFlow *m_pFws[MAX_EVENTFLOWNUM];
		CStatusSubscriberSkeleton *m_pSubEnd[MAX_EVENTFLOWNUM + 1];

		///��ǰ���ļ�
		//	CCachedFileFlow *m_pFlow;
			///�������ı��

	//	int  m_nFlowSeq;
	private:
		SyncDBOperator	m_hander;

		CWriteDBThread m_writeDBTh;

		int m_nLocID;
		int m_nRemID;

		//friend class CWriteDBThread; //��ʱ������Ԫ
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

		///�������ݵ�ָ���ļ�����
			///@param	fileName	�ļ���
			///@param	fileContent	�ļ�����ָ��
			///@param	length	�ļ����ݳ���
			///@return	����д�ļ������true�ɹ���falseʧ��
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
				printf("�ļ� %s ����fseek ���� \n", fileName);
			}

			if (fwrite(mBuffer, mLength, 1, fp) != 1)
			{
				printf("Write File %s Failed, exit\n", fileName);
				exit(0);
			}

#ifdef WIN32
			if (chsize(fileno(fp), endSize) != 0)
			{
				printf("�ļ� %s ����chsize ���� \n", fileName);
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
		///��ʼ���ļ�������
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
		//add by feng.q, ��¼�ļ���Чĩβ
		//key: file name
		//value:
		map<string, CFileValidContent>	m_mapFileValidEnd;
};

class CPeakKey
{
	/* */
	public:
		///Ӧ�ö���������PuDian.app.tkernel.1
		string	m_sObject;

		///������ֵ��ָ�����ƣ���HandleOrderInsert
		string	m_sAttr;

		///������ֵָ������ָ��������HandleOrderInsertError
		string	m_sRltAttr;

	/* */
	public:

		///���캯��
			///@param	pObject	��ض�����
			///@param	pAttr	ָ������
			///@param	pRltAttr	���ָ������
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

		///����<�����
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

		///����==�����
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

		///�������
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
		//key: slog�ļ�����
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
