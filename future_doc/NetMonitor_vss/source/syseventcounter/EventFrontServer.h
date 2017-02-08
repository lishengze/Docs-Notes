/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	EventFrontServer.h
///@brief	�������¼��������������ǰ�����Ӵ������
///@history
///20080510	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
#ifndef REF_EVENTFRONTSERVER_H
#define REF_EVENTFRONTSERVER_H

#include "public.h"
#include "CachedFlow.h"
#include "CachedFileFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "CDate.h"
#include "systools.h"
#include "EventConfigConnector.h"

#if !defined(DEVELOP_ENV)
#define DEVELOP_ENV
#endif

//#undef DEVELOP_ENV
class CNodeCacheBuffer
{
	/* */
	public:

		///���캯��
			///@param	nMaxNodeNum	�������ܱ�������ڵ����
			///@param	nNodeSize	�����ڵ����󳤶�
		CNodeCacheBuffer(int nMaxNodeNum, int nNodeSize)
		{
			m_pHeadNode = NULL;
			m_nNodeSize = nNodeSize + 2;
			m_nMaxNodeNum = nMaxNodeNum;
			m_nWriteNum = -1;
			m_nReadNum = -1;
			m_pHeadNode = (char *)malloc(m_nMaxNodeNum * m_nNodeSize);
			if (NULL == m_pHeadNode)
			{
				printf("CNodeCacheBuffer:: malloc failed\n");
				fflush(stdout);
				exit(0);
			}

			memset(m_pHeadNode, 0, m_nMaxNodeNum * m_nNodeSize);
			m_nWriteTotal = 0;
			m_nReadTotal = 0;
		}

		~CNodeCacheBuffer(void)
		{
			free(m_pHeadNode);
		}

		///��������д���ݺ���
			///@param	pStrValue	��Ҫ���뻺������ֵ��ַ
			///@param	length	����ĳ���
			///@return	�ɹ�����true������false
		bool writeNode(void *pStrValue, int length)
		{
			if (length <= 0)
			{
				return true;
			}

			int tempWriteNum = m_nWriteNum + 1;
			if (tempWriteNum >= m_nMaxNodeNum)
			{
				tempWriteNum = 0;
			}

			char *pNode = m_pHeadNode + tempWriteNum * m_nNodeSize;
			short *iNodeLen = (short *)pNode;
			if (*iNodeLen != 0)
			{
				printf(
					"Reach Buffer Limit, need to extend %d %d\n",
					(int)(time((time_t *)NULL)),
					*iNodeLen);
				fflush(stdout);
				return false;
			}

#if 0
			if (*iNodeLen != 0)
			{
				printf("Reach Buffer Limit, need to extend\n");
				return false;
			}

#endif
			memcpy(pNode + 2, pStrValue, length);
			*iNodeLen = length;
			m_nWriteNum = tempWriteNum;
			m_nWriteTotal++;
			return true;
		}

		bool writeNode(void *pStrValue)
		{
			while (!writeNode(pStrValue, m_nNodeSize - 2))
			{
#ifdef WINDOWS
				Sleep(20);
#else
				usleep(20 * 1000);
#endif
			}

			return true;
		}

		///�ӻ����������ݺ���
			///@param	pStrValue	����ȡ����ֵ
			///@param	length	ȡ����ֵ����
			///@return	�ɹ�����true������false
		bool readNode(void *pStrValue, int &length)
		{
			int tempReadNum = m_nReadNum + 1;
			if (tempReadNum >= m_nMaxNodeNum)
			{
				tempReadNum = 0;
			}

			char *pNode = m_pHeadNode + tempReadNum * m_nNodeSize;
			short *iNodeLen = (short *)pNode;
			if (*iNodeLen == 0)
			{
				return false;
			}

			length = *iNodeLen;
			memcpy(pStrValue, pNode + 2, length);
			*iNodeLen = 0;
			m_nReadNum = tempReadNum;
			m_nReadTotal++;
			return true;
		}

		void report(void)
		{
			printf("Write %d Read %d\n", m_nWriteTotal, m_nReadTotal);
			fflush(stdout);
		}

	/* */
	protected:
	/* */
	private:
		///�������ݵ��׵�ַ
		char *m_pHeadNode;

		///һ������С��2���ֽڱ�ʾ��Ч���ݳ���+�̶����ݿ��С��
		int m_nNodeSize;

		///���ڵ���
		int m_nMaxNodeNum;

		///��ǰ�Ѿ�д��Ľڵ���
		int m_nWriteNum;

		///��ǰ�Ѿ���ȡ�Ľڵ���
		int m_nReadNum;

		int m_nWriteTotal;
		int m_nReadTotal;
};

//��·״̬��Ϣ
class LinkStatusInfo
{
	/* */
	public:
		LinkStatusInfo(void) :
		m_nPortLinkStatus(0),
		m_nPortProtoStatus(0)
		,
		m_nPortLinkStatusReal(0),
		m_nPortProtoStatusReal(0),
		linktype(0)
		{
		}

		int m_nPortLinkStatus;		//�˿ڵ�����״̬
		int m_nPortProtoStatus;		//Э�������״̬
		int m_nPortLinkStatusReal;	//�˿ڵ�ʵ��״̬
		int m_nPortProtoStatusReal; //Э���ʵ��״̬
		int linktype;				//��ͨ��·:0, ��Ա��·:1
};

/////////////////////////////////////////////////////////////////////////
///CAgentSessionFactory�����˲ɼ��������ӵ���
///@author	�ܽ���
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CAgentSessionFactory :
	public CSessionFactory
{
	/* */
	public:

		///���캯��
			///@param	pReactor	CReactor����ָ��
			///@param	nMaxSession	������Ӹ���
		CAgentSessionFactory(CReactor *pReactor, int nMaxSession) :
		CSessionFactory(pReactor, nMaxSession)
		{
		}

		///ע������������
			///@param	location	���ӵ�ͨ�ŵ�ַ
		void RegisterConnecter(char *location)
		{
			CSessionFactory::RegisterConnecter(location);
			memset(m_location, 0, MAXLOCATIONLEN);
			strcpy(m_location, location);
		}

		///ȡ���ӵ�ַ����
			///@return	�������ӵ�ַ�ַ���
		char *GetLocationName(void)
		{
			return m_location;
		}

	/* */
	private:
		///�������ӵ�ַ�ַ���
		char m_location[MAXLOCATIONLEN];
};

class CEventAttrKey
{
	/* */
	public:

		///���캯��
		CEventAttrKey(void)
		{
			m_sObjectID = "";
			m_sEventName = "";
		}

		///���캯��
			///@param	pObjectID	����ID
			///@param	pEventName	�¼���
		CEventAttrKey(const char *pObjectID, const char *pEventName)
		{
			m_sObjectID = pObjectID;
			m_sEventName = pEventName;
		}

		///�������캯��
		CEventAttrKey(const CEventAttrKey &ob)
		{
			m_sObjectID = ob.m_sObjectID;
			m_sEventName = ob.m_sEventName;
		}

		///����=�����
		void operator=(const CEventAttrKey &ob)
		{
			m_sObjectID = ob.m_sObjectID;
			m_sEventName = ob.m_sEventName;
		}

		///����>�����
		friend bool operator>(
		const CEventAttrKey &ob1,
		const CEventAttrKey &ob2)
		{
			if (ob1.m_sObjectID > ob2.m_sObjectID)
			{
				return true;
			}
			else if (ob1.m_sObjectID == ob2.m_sObjectID)
			{
				if (ob1.m_sEventName > ob2.m_sEventName)
				{
					return true;
				}
			}

			return false;
		}

		///����>�����
		friend bool operator < (const CEventAttrKey &ob1, const CEventAttrKey &ob2)
		{
			if (ob1.m_sObjectID < ob2.m_sObjectID)
			{
				return true;
			}
			else if (ob1.m_sObjectID == ob2.m_sObjectID)
			{
				if (ob1.m_sEventName < ob2.m_sEventName)
				{
					return true;
				}
			}

			return false;
		}

		///����==�����
		friend bool operator==(
		const CEventAttrKey &ob1,
		const CEventAttrKey &ob2)
		{
			if (ob1.m_sObjectID == ob2.m_sObjectID
			&&	ob1.m_sEventName == ob2.m_sEventName)
			{
				return true;
			}

			return false;
		}

	/* */
	public:
		///����ID
		string	m_sObjectID;

		///�¼�����
		string	m_sEventName;
};

/////////////////////////////////////////////////////////////////////////
///CFrontConnector�����˽���ǰ�����Ӵ������
///@author	�ܽ���
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CFrontConnector :
	public CAgentSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///���캯��	
			///@param	pReactor	CReactor����ָ��
		CFrontConnector(
			CReactor *pReactor,
			unsigned int *pSyslogEventId,
			char *pFlowPath);

		///�½��Ựʱ���õĴ�����
			///@param	pChannel	�Ự������ͨ����ַ
			///@param	bIsListener	�Ự�Ƿ��Ǽ�������������
			///@return	���ش������»Ự
		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		///���ӳɹ�ʱ���õĴ�����
			///@param	pSession	���ӳɹ��ĻỰָ��
		virtual void OnSessionConnected(CSession *pSession);

		/** �������ݰ�����
	* @param	pFTDPackage	�������ݰ��ĵ�ַ
	*/
		void SendPackageAllSession(CFTDCPackage *pFTDCPackage)
		{
			CHashMap<DWORD, CSession *, HashInt>::iterator	itor = m_mapSession.
				Begin();
			while (!itor.IsEnd())
			{
				((CFTDCSession *) (*itor))->SendRequestPackage(pFTDCPackage);
				pFTDCPackage->Pop(FTDCHLEN);
				itor++;
			}
		}

		//�澯�¼����/��ȡ�ӿ�
		void AddWarningEvent(CFTDReqQryWarningEventUpdateField &warningevent)
		{
			m_listWarningEvent.add(warningevent);
		}

		bool GetWarningEvent(CFTDReqQryWarningEventUpdateField &warningevent)
		{
			return m_listWarningEvent.get(warningevent);
		}

		//�澯״̬�ı��¼����/��ȡ�ӿ�
		void AddWarningEventActiveChange(
		CFTDReqQryWarningActiveChangeField	&warningeventac)
		{
			m_listWarningEventActiveChange.add(warningeventac);
		}

		bool GetWarningEventActiveChange(
		CFTDReqQryWarningActiveChangeField	&warningeventac)
		{
			return m_listWarningEventActiveChange.get(warningeventac);
		}

		//�澯�����¼�
		void AddReqNetRoom(CFTDReqQryNetRoomField &netroom)
		{
			m_listReqNetRoom.add(netroom);
		}

		bool GetReqNetRoom(CFTDReqQryNetRoomField &netroom)
		{
			return m_listReqNetRoom.get(netroom);
		}

	/* */
	protected:
		/**�Ự���ӶϿ�ʱ�Ĵ�����
	* @param	pSession	�Ͽ������ӻỰָ��
	* @param	nReasion	�Ͽ���ԭ��
	*/
		virtual void OnSessionDisconnected(CSession *pSession, int nReason);

	/* */
	private:
		///����Ӧ���������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
			///@return	�������ݰ��Ĵ�����
		virtual int HandlePackage(
						CFTDCPackage *pFTDCPackage,
						CFTDCSession *pSession);

		///�û���¼Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		///�澯������Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryWarningEventUpdate(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///����澯�������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryWarningActiveChange(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///�û���¼��Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		///�û�����������Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqOrderInsert(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��־�¼���Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQrySyslogEventUpdateTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///�����ļ��б���Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryNetCfgFileTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///�����ļ���Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryGetFileTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///����ָ���ȡ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqNetMonitorTaskResultTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		//�澯���ſ���
		void OnReqQryNetRoomTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///������������ļ���·��
		void SetOutputPath(const char *path);

		///�����ļ�����
		void SendFileContent(
				string	&filePath,
				string	&filename,
				DWORD requestId,
				CFTDCSession *pSession,
				bool sendLastFlag = true);

		void PublishFlow(CFTDCPackage *pFTDCPackage
			             , CFTDCSession *pSession
			             , CCachedFileFlow** cacheFileFlowArray);
	/* */
	public:
		///for test
		static void OnReqQryGetFileTopic(void);

	/* */
	private:
		///�������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;
		unsigned int *m_pSyslogEventId;

		// ������������ļ���Ŀ¼
		string	m_sFilePath;

		///���͸�config�ĸ澯�¼�����
		TemplateMutexCatch<CFTDReqQryWarningEventUpdateField>
			m_listWarningEvent;

		///���͸�config�ĸ澯״̬�ı��¼�����
		TemplateMutexCatch<CFTDReqQryWarningActiveChangeField>
			m_listWarningEventActiveChange;

		///���͸�config�ĸ澯���ض���
		TemplateMutexCatch<CFTDReqQryNetRoomField>	m_listReqNetRoom;

	/* */
	public:
		///������Ҫ���������ĸ澯�¼�����ID by zhou.jj 20100609
		list<string> m_cDropEventIdList;	//�������¼�ID�б�
		CCachedFileFlow *m_pCurrFrontFlow;
		CCachedFileFlow *m_pCurrOracleFlow;
		CCachedFileFlow *m_pCurrSlogFlow;

		CCachedFileFlow *m_pFrontFlowArray[MAX_EVENTFLOWNUM];
		CCachedFileFlow *m_pOracleFlowArray[MAX_EVENTFLOWNUM];
		CCachedFileFlow *m_pSlogFlowArray[MAX_EVENTFLOWNUM];

		///�ϴ��л�������ָ���������е�λ��
		int m_nFlowPosition;

		///���浱ǰ���е�ObjectID��������session��Ϣ
		CObjectIdSession m_mObjectIdSession;

		///�¼���������������ǰ�õĲ�ѯ���������RID�б�
		CManageReqIDSession m_mFrontToEventReq;

		//����ִ�н��
		//key:ObjectID_Task_ID_OperateTime_MonDate_MonTime_InstructChain
		map<string, vector<CFTDReqQryNetMonitorTaskResultField> >
			m_mapTaskResult;
};

class CEventProcess
{
	/* */
	public:
		CEventProcess(void)
		{
			m_mEventSeries = 1;
		}

		///�¼���������ѯ����
			///@param	pObjectID	������
			///@param	pEventName	�¼���
			///@param	nEventSeries	�����¼��Ķ���ı�ţ����ͻ���ͳ�Ʒ���ʹ�ã�ͬһ����ͬһ�¼���η����¼�����ͬ
		bool getEventDesc(
				const char	*pObjectId,
				const char	*pEventName,
				int &nEventSeries);

	/* */
	private:
		map<CEventAttrKey, int> m_mapEventDesc;
		int m_mEventSeries; // �¼�����ı�ţ��������ظ����ͻ���ͳ�Ʒ���ʹ��
};

class CListHistoryTradePeakField
{
	/* */
	public:
		CListHistoryTradePeakField(void)
		{
			m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
		}

		~CListHistoryTradePeakField(void)
		{
		}

		///����ֵ����д�뵽���ݶ��к���
			///@param	warningEvent	�澯�¼�����
			///@return	true��ʾ�ɹ���false��ʾʧ��
		bool WriteValue(CFTDRtnHistoryTradePeakField &tradePeak)
		{
			m_lockData.Lock();
			m_listEvent.push_back(tradePeak);
			m_lockData.UnLock();
			return true;
		}

		///�����ݶ��ж����¼�д�뵽ǰ�õ����Ͳ�ѯ��
			///@param	frontFlow	ǰ�ö��ĵ�������
			///@param	oracleFlow	��ѯ���������ĵ�������
		void ReadValue(CCachedFileFlow *frontFlow, CCachedFileFlow *queryFlow)
		{
			if (m_lockData.TryLock())
			{
				list<CFTDRtnHistoryTradePeakField>::iterator it = m_listEvent.
					begin();
				for (it; it != m_listEvent.end(); ++it)
				{
					m_pkgSend.PreparePackage(
							FTD_TID_RtnHistoryTradePeakTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
					FTDC_ADD_FIELD(&m_pkgSend, &(*it));
					m_pkgSend.MakePackage();
					queryFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
				}

				m_listEvent.clear();
				m_listEvent.resize(0);
				m_lockData.UnLock();
			}
		}

	/* */
	protected:
	/* */
	private:
		// �澯�¼��������
		list<CFTDRtnHistoryTradePeakField>	m_listEvent;

		// �����������ڱ��� ���ݶ���
		CMutex	m_lockData;

		///���ڷ������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;
};

class CListHistoryObjectAttrField
{
	/* */
	public:
		CListHistoryObjectAttrField(void)
		{
			m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
		}

		~CListHistoryObjectAttrField(void)
		{
		}

		///��K������д�뵽���ݶ��к���
			///@param	warningEvent	�澯�¼�����
			///@return	true��ʾ�ɹ���false��ʾʧ��
		bool WriteValue(CFTDRtnHistoryObjectAttrField &historyObject)
		{
			m_lockData.Lock();
			m_listEvent.push_back(historyObject);
			m_lockData.UnLock();
			return true;
		}

		///�����ݶ��ж����¼�д�뵽ǰ�õ����Ͳ�ѯ��
			///@param	frontFlow	ǰ�ö��ĵ�������
			///@param	oracleFlow	��ѯ���������ĵ�������
		void ReadValue(CCachedFileFlow *frontFlow, CCachedFileFlow *queryFlow)
		{
			if (m_lockData.TryLock())
			{
				list<CFTDRtnHistoryObjectAttrField>::iterator it = m_listEvent.
					begin();
				for (it; it != m_listEvent.end(); ++it)
				{
					m_pkgSend.PreparePackage(
							FTD_TID_RtnHistoryObjectAttrTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
					FTDC_ADD_FIELD(&m_pkgSend, &(*it));
					m_pkgSend.MakePackage();
					queryFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
				}

				m_listEvent.clear();
				m_listEvent.resize(0);
				m_lockData.UnLock();
			}
		}

	/* */
	protected:
	/* */
	private:
		// �澯�¼��������
		list<CFTDRtnHistoryObjectAttrField> m_listEvent;

		// �����������ڱ��� ���ݶ���
		CMutex	m_lockData;

		///���ڷ������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;
};
#endif // REF_EVENTFRONTSERVER_H
