/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	EventCounterServer.h
///@brief	�������¼���������������ɼ��������Ӵ������
///@history
///20080510	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
#ifndef REF_EVENTCOUNTERSERVER_H
#define REF_EVENTCOUNTERSERVER_H

#include "CStatusAnalysis.h"
#include "CSavePosThread.h"
#include "CMdbThread.h"

#include "EventFrontServer.h"
#include "ProbeServer.h"
#include "SnmpSubcriber.h"
#include "EventConfigConnector.h"
#include "CRegexConfig.h"
#include "CFileDiff.h"

// add by cao.ning
#include "CSysInternalTopology.h"

#include <boost/regex.hpp>

#define MESSAGESENDTOPROBESESSION(listSession, pkgSend)	   \
	(pkgSend).ValidPackage();							   \
	for (list < CFTDCSession * >::iterator listSessionIt = \
			 (listSession).begin();						   \
	 listSessionIt != (listSession).end();				   \
		 listSessionIt++)								   \
	{													   \
		(*listSessionIt)->SendRequestPackage(&(pkgSend));  \
		(pkgSend).Pop(FTDCHLEN);						   \
	}

#define MESSAGESENDTOPROBEDIRECT(listSession, pkgSend)	   \
	for (list < CFTDCSession * >::iterator listSessionIt = \
			 (listSession).begin();						   \
	 listSessionIt != (listSession).end();				   \
		 listSessionIt++)								   \
	{													   \
		(*listSessionIt)->SendRequestPackage(&(pkgSend));  \
		(pkgSend).Pop(FTDCHLEN);						   \
	}
	
typedef map<string, string> T_strmap;

#ifdef WIN32
#define CHANGELINE_FLAG	"\r\n"			// ���з�
#define TMP_DIRNAME "C:\\tmp_event"
#define STRCMP	stricmp
#else
#define CHANGELINE_FLAG	"\n"			// ���з�
#define TMP_DIRNAME "../DevCfgFiles"
#define STRCMP strcasecmp
#endif


inline int TIME_TO_LONG(char *p)
{
	return atoi(p) * 3600 + atoi(p + 3) * 60 + atoi(p + 6);
}

typedef struct
{
	string	filename;
	string	filedate;
	string	filetime;
} ConfigFileInfo;

typedef struct
{
	string	name;
	string	comment;
	string	left;
	string	left_drift;
	string	right;
	string	right_drift;
	int left_time;
	int right_time;
} TradeSectionInfo;

//κ��add, 20120203 ����δ����ĸ澯�¼���
class CWarningEventManager
{
	/* */
	public:
		//����һ��δ����ĸ澯�¼�
		void add_warning_event(CFTDRtnWarningEventField &eventfield);

		//����objid��eventnameģ����ѯ�����ط����������¼��б�
		//����֮���Ӧ���¼��Ѵ�������ɾ��
		vector<CFTDRtnWarningEventField> fuzzy_get_warning_event(
											string	objectid,
											string	eventname,
											bool erasemark);

		//����eventid��ȷ��ѯ�����ط����������¼��б�
		//����֮���Ӧ���¼��Ѵ�������ɾ��
		vector<CFTDRtnWarningEventField> exact_get_warning_event(
											string	objectid,
											string	eventname,
											int eventid,
											bool erasemark);

		//����һ���յ���ԭʼ�¼�
		void add_raw_warning_event(CFTDRtnWarningEventField &eventfield);
		void add_raw_syslog_event(CFTDRtnSyslogEventField &syslogfield);

		void onTimer(void); //������ڵ�raw_syslog_event

		//�ж��Ƿ��ظ�����
		bool is_duplicate_warning_event(CFTDRtnWarningEventField &eventfield);
		bool is_duplicate_syslog_event(CFTDRtnSyslogEventField &syslogfield);

	/* */
	private:
		map<string, map<int, CFTDRtnWarningEventField> > warning_event_list;	//key:objectid;;eventname, value:eventlist
		CMutex	m_lockData; //read/write lock
		map<string, int> raw_warning_event_list;			//key:objectid;;eventname;;date;;time, value:nothing
		map<string, vector<string> > raw_syslog_event_list; //key:objectid;;eventname;;date;;time, value:eventdes_list

		//���ڳ�ʱ��̭,��ֹ�ڴ���������
		queue<string> raw_warning_event_queue;				//key:objectid;;eventname;;date;;time
		queue<string> raw_syslog_event_queue;				//key:objectid;;eventname;;date;;time
};

class CEventCounterServer;

/////////////////////////////////////////////////////////////////////////
///CEventTimmer�������¼�����������������������
///@author	�ܽ���
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CEventTimmer :
	public CEventHandler
{
	/* */
	public:
		///���캯��
		CEventTimmer(
			CReactor *pReactor,
			CEventCounterServer *pEventCounterServer);

		/** ���ö�ʱ������
	* @param	nIDEvent	��ʱ���������¼�ID
	* @param	nElapse	��ʱ����ʱ��������λms	
	*/
		void SetTimer(int nIDEvent, int nElapse)
		{
			m_nEventId = nIDEvent;
			CEventHandler::SetTimer(nIDEvent, nElapse);
		}

		/** ��ʱ��������
	* @param	nIDEvent	�ö�ʱ����ID
	*/
		virtual void OnTimer(int nIDEvent);

	/* */
	private:
		///�л���ʱ����
		int m_nInterval;

		///���ڷ������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;

		///���涨ʱ�����¼�ID
		int m_nEventId;

		///�����ϴ��л�ʱ��
		time_t	m_nLastChangeTime;

		//int m_mTradeDay;
		CEventCounterServer *m_pEventCounterServer;
};

class CFlowManager
{
	/* */
	public:

		///���캯��
			///@param	nStartId	�������������
			///@param	pLocation	�����ߵ�������Ϣ
			///@param	pEventCounterServer	����ָ��
		CFlowManager(
		int nStartId,
		char *pLocation,
		CEventCounterServer *pEventCounterServer)
		{
			m_nStartId = nStartId;
			strcpy(m_location, pLocation);
			for (int i = 0; i < MAX_EVENTFLOWNUM; i++)
			{
				m_pSubcriber[i] = new CSnmpSubscriber(
						i,
						nStartId,
						pEventCounterServer);
			}
		}

		bool check(int nStartId, char *pLocation)
		{
			if ((nStartId != m_nStartId)
			||	(strcmp(m_location, pLocation) != 0))
			{
				return false;
			}
			else
			{
				return true;
			}
		}

	/* */
	public:
		///������ָ������
		CSnmpSubscriber *m_pSubcriber[MAX_EVENTFLOWNUM];

		///�������������
		int m_nStartId;

		///�����ߵ�������Ϣ
		char m_location[64];

	/* */
	protected:
	/* */
	private:
};

// add by cao.ning
// ����ͨ���߳�
// �޸�Ϊʹ��AttrConfig��������Ϣ�������ã������øö���
#if 0
class CPerHourMessage : public CThread
{
	
	public:
		CPerHourMessage(CEventCounterServer *pEventCounterServer);
		~ CPerHourMessage();

		virtual bool InitInstance(void);
	
		virtual void ExitInstance(void);

		virtual void Run(void);
	private:
		// ��ʱ������ڸ�ʽ��Ϊ����
		// input: pNowTime (��ǰʱ��)
		// output: NowTime_str, NowDate_str (��ʽ�����ʱ��)
		void FormateTime(time_t &pNowTime, string &NowTime_str, string &NowDate_str);
	
	private:
		CEventCounterServer* m_pEventCounterServer;

		bool m_bSendMessage;
};
#endif


/////////////////////////////////////////////////////////////////////////
///CEventCounterServer�����˼����ɼ��������ӹ������
///@author	�ܽ���
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CEventCounterServer :
	public CAgentSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///���캯��
			///@param	pReactor	CReactor����ָ��
			///@param	pSaveFile	�����������ļ���
			///@param	pEventCfgPath	�¼������ļ�·��
			///@param	pXmlFileName	xml�����ļ�
			///@param	pFlowPath	���ļ�����·��
		CEventCounterServer(
			CReactor *pReactor,
			char *pSaveFile,
			char *pEventCfgPath,
			char *pXmlFileName,
			char *pFlowPath);

		///�½��Ựʱ���õĴ�����
			///@param	pChannel	�Ự������ͨ����ַ
			///@param	bIsListener	�Ự�Ƿ��Ǽ�������������
			///@return	���ش������»Ự
		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		///���ӳɹ�ʱ���õĴ�����
			///@param	pSession	���ӳɹ��ĻỰָ��
		virtual void OnSessionConnected(CSession *pSession);

		///����Ӧ���������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
			///@return	�������ݰ��Ĵ�����
		virtual int HandlePackage(
						CFTDCPackage *pFTDCPackage,
						CFTDCSession *pSession);

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

	/* */
	protected:
		/**�Ự���ӶϿ�ʱ�Ĵ�����
	* @param	pSession	�Ͽ������ӻỰָ��
	* @param	nReasion	�Ͽ���ԭ��
	*/
		virtual void OnSessionDisconnected(CSession *pSession, int nReason);

	/* */
	private:
		///̽���������ô�����
			///@param	pFTDCPackage	FTDCpackage���ݰ���ַ
			///@param	pSession	���ݰ������ĻỰID
		void OnReqQryHostConfig(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///�û���¼��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		///�û���¼Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		///�û��������봦����
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqOrderInsert(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///�л���������������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryTradeDayChange(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///Ĭ�ϴ�����
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnDefaultProcess(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///�������Դ�����
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRtnObjectAttrTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///���������������
			///@param	pFTDCPackage	FTDCpackage���ݰ���ַ
		void OnRtnUpdateSysConfig(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///�ڴ�����Ӧ������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnTopMemInfoTopic(CFTDCPackage *pFTDCPackage);

		///CPU����Ӧ������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnTopCpuInfoTopic(CFTDCPackage *pFTDCPackage);

		///Network����Ӧ������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnNetworkInfoTopic(CFTDCPackage *pFTDCPackage);

		///ҵ��ϵͳ��־������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnSyslogInfoTopic(CFTDCPackage *pFTDCPackage);

		///Ӧ����־������
			///@param	pFTDCPackage	FTDCpackage���ݰ���ַ
			///@param	pSession	���ݰ������ĻỰID
		void OnRtnSyslogInfoApplog(CFTDCPackage *pFTDCPackage);

		///Slog��־������
			///@param	pFTDCPackage	FTDCpackage���ݰ���ַ
			///@param	pSession	���ݰ������ĻỰID
		void OnRtnSyslogInfoSessionlog(CFTDCPackage *pFTDCPackage);

		///������־������
			///@param	pFTDCPackage	FTDCpackage���ݰ���ַ
			///@param	pSession	���ݰ������ĻỰID
		void OnRtnSyslogInfoSyslog(CFTDCPackage *pFTDCPackage);

		///Web������������־��Ϣ������
			///@param	pFTDCPackage	FTDCpackage���ݰ���ַ
			///@param	pSession	���ݰ������ĻỰID
		void OnRtnDBQueryAccessLog(CFTDCPackage *pFTDCPackage);

		///�ؼ��ļ���־������
			///@param	pFTDCPackage	FTDCpackage���ݰ���ַ
			///@param	pSession	���ݰ������ĻỰID
		void OnRtnSyslogInfoKeyfile(CFTDCPackage *pFTDCPackage);

		///���Ľ���ռ��CPU��Դ��Ϣ������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnCPUUsageTopic(CFTDCPackage *pFTDCPackage);

		///����ҵ�����ռ���ڴ���Դ��Ϣ������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnMemoryUsageTopic(CFTDCPackage *pFTDCPackage);

		///����ҵ�����ռ��Ӳ����Դ��Ϣ������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnDiskUsageTopic(CFTDCPackage *pFTDCPackage);

		///���Ķ������Դ�����
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnObjectAttrTopic(CFTDCPackage *pFTDCPackage);

		///�����������н��������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnNetMonitorTaskResultTopic(CFTDCPackage *pFTDCPackage);

		///��������״̬��Ϣ������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnNetMonitorTaskInfoTopic(CFTDCPackage *pFTDCPackage);

		///����̽�뷢�ͳ����ĸ澯������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnWarningEventTopic(CFTDCPackage *pFTDCPackage);

		///����̽�뷢�ͳ����ĸ澯������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnSyslogEventTopic(CFTDCPackage *pFTDCPackage);

		///����̽�뷢�ͳ����Ķ�̬�д�����
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnDBQueryTopic(CFTDCPackage *pFTDCPackage);

		///���������ļ�����
			///@param	pMessage	�������յ��İ���ַ
		void OnRspQryNetMonitorTaskResultTopic(CFTDCPackage *pFTDCPackage);

		///����������Ϣ
			///@param	pMessage	�յ��İ���ַ
		void OnRtnBaseLineTaskTopic(CFTDCPackage *pFTDCPackage);

		void OnRtnNetLocalPingResultTaskTopic(CFTDCPackage *pFTDCPackage);

		void OnRtnNetRemotePingResultTaskTopic(CFTDCPackage *pFTDCPackage);

		/// �������л�����
		///@param TradingDay	�½����յ�������
		void TradingDayChange(int TradingDay);

		///������״̬����
			///@param	pBuffer	��׼״̬��������ַ
		void ProcessOneStatus(char *pBuffer);

		///��������ļ�
		int LogConfigInfo(
				string	objectid,
				string	buffer,
				int version,
				string	filedate,
				string	filetime);

		///������ص������ļ��б�
		void LoadConfigFileList(void);

		///������������ļ���·��
		void SetOutputPath(const char *path);

		///�����ļ�·��
		void CreatePath(const char *path);

		int ParseShowIPInterfaceResult(
				int taskid,
				vector<AttrNodeInfo> attrlist,
				string	objectid,
				string	deviceip);

		void ClearMemeryDatabase(void);

		//��ȡ�ļ�����
		string	GetFileContent(string &path);

		//�����ļ��ͻ����ļ����бȶ�,���ػ����ļ��бȶԲ�һ�µĲ���
		string	BaseLineComare(string basecontent, string curcontent);

		//�Ƚ������ļ��汾�Ƿ�仯
		int  CheckFileVersion(
			string	objectid,
			string	buffer,
			string	filedate,
			string	filetime);

		///// �õ��������ļ�ͬĿ¼�����һ�������ļ���ȫ·����
		bool GetLastFileName(
			string objectid,
			string filepath,
			string filename,
			string& lastfilename);
		//���ݹؼ����������е�λ�ã�����split�ַ���
		void Split_Data_Column(const string &in, string &out, const string &key);

		//����cisco�豸NUXUS7K�ͺŵ��¶�״̬Ѳ����
		void Combinate_Data_Env_NUXUS( string &in, string &out );

		//����cisco�豸NUXUS7K�ͺŵĵ�Դ״̬Ѳ����
		void Combinate_Data_Power_NUXUS( string &in, string &out );

	/* */
	public:
		///���͸澯�¼�,Э��ģʽ����config����Э��ģʽ����Client
		void SendWarningEvent(CFTDRtnWarningEventField warningevent);

		///�Ӽ�ƥ�䣬�жϸ����������Ƿ���result���Ӽ�
		static int	SubMatchInResult(
						vector<map<int, string> > &subresult,
						string	result);

		///����˼���豸3825�ͺŵĻ������
		static int	ParseEnv_3825(string result, string &newresult);

		///����˼���豸3945�ͺŵĻ������
		static int	ParseEnv_3945(string result, string &newresult);

		///����˼���豸5350�ͺŵĻ������
		static int	ParseEnv_5350(string result, string &newresult);

		///����˼���豸7304�ͺŵĻ������
		static int	ParseEnv_7304(string result, string &newresult);

		///����Juniper�豸SRX�ͺŵĲ����ỰѲ����
		static int	ParseConSessions_SRX(string result);

		///����Juniper�豸SRX�ͺŵ�RE������Ѳ����
		static int	ParseFPC_SRX(string result, string &newresult);

		static int ParsePerfSession_SRX(CFTDRtnNetMonitorTaskResultField &resultField,string result,int manufactory_id,string deviceserial,int& threadhold);

		///����Juniper�豸SRX�ͺŵ�RE������Ѳ����
		static int	ParseREUsage_SRX(string result, string &newresult);

		///�Ӽ�ƥ�䣬�жϸ����������Ƿ���attrlist���Ӽ�
		static int	SubMatchInAttrList(
						vector<map<int, string> > &subresult,
						vector<string>	attrlist,
						vector<vector<AttrNodeInfo> > &valuelist);

		///����ָ��ؽ��
		int RegularParse(
				CFTDRtnNetMonitorTaskResultField &resultField,
				string	&oldresult,
				string	&newresult);

		static int	RegularParseResult(
						CFTDRtnNetMonitorTaskResultField &resultField,
						string	&oldresult,
						string	&newresult,
						int manufactory_id,
						string	deviceip,
						string	deviceserial);

		///����ָ��ؽ��
		int RegularParse(
				CFTDRspQryNetMonitorTaskResultField &resultField,
				string	&oldresult,
				string	&newresult);

		///�ø����ַ����滻�ַ����е�����
		static void ReplayString(
						string	&ori,
						string	&srcContent,
						string	&dstContent,
						string	&result);

		///�����ʽ�еı����滻Ϊ��Ӧ��ֵ
		static string ReplaceAttrByValue(
						vector<AttrNodeInfo> &attr_value,
						string	expr);

		///���ַ�������ȡʱ��ֵ��eg:"1 year, 11 weeks, 3 days, 12 hours, 22 minutes",��ȡ1,11,3,12,22
		static int	getTimeValueFromStr(
						string	&valuestring,
						const char	*typestring);

		//��RateLimiterѲ������ԭʼ�ļ�����ȡdroped�ֶ�
		static int GetDropCounterFromStr(const string &olddata, string &newdata);

		static int GetNexusTemp_3548FromStr(const string &olddata, string &newdata);

		static int GetSrxFpcStatus_SRXFromStr(string olddata, string &newdata);

		static void remove_postfix_forSRX(string& result);

		//��SRX��ʱ���Ѳ����ԭʼ�ļ�����ȡsystem,protocolsʱ���ֶ�
		static int GetSRXUptimeFromStr(const string &olddata, string &newdata);

		///���������ļ�
		void loadXmlConfig(void);

		//�����澯�¼�����
		string	modifyWarningEventLevel(string ip, string orilevel);

		/// ����ʱ�䴮�����Ľ��׽���Ϣ�����ڽ��׽�����Ϊ��
		string	getTradingSection(char *pTime);

		//�����¼���������
		void UpdateWarningCount(CFTDRtnWarningEventField &event);

		//��ȡ�¼���������
		int GetWarningCount(CFTDRtnWarningEventField &event);

		//���»�Ա��·״̬
		void UpdateLinkStatusByWarningEvent(
				CFTDRtnWarningEventField &fieldInfo);
		void UpdateLinkStatusBySyslogEvent(CFTDRtnSyslogEventField &fieldInfo);

		//ϯλ��·״̬����
		void SeatLinkAnalysis(CFTDRtnSyslogEventField &fieldInfo);

		char GenerateMaskValue(int nMaskValue);
		int SplitString(
				const string &strSrc,
				const string &strDelimiter,
				vector<string>	&strArrayRes);
		bool IsBelongIPRange(
				const string &strIPRange,
				const string &strIPAddrSample);

		///������·״̬����������Ϊ�ѻָ�
		int GetPortStatus(LinkStatusInfo &statusinfo);

		///������·״̬����������Ϊδ�ָ�
		int GetPortRealStatus(LinkStatusInfo &statusinfo);

		//�·���Ա��·״̬��Ϣ
		void SendLinkStatus(string objectid, string ipaddr);

		static bool ProcessRunTime(
						vector<map<int, string> > &regularparams,
						vector<vector<AttrNodeInfo> > &attr_value_list);
		static bool ProcessSoftewareStatus(string oldresult);

		static bool ProcessSrxFpcStatus(CFTDRtnNetMonitorTaskResultField &resultField,string result,int manufactory_id,string deviceserial);

		
		static bool ProcessLACPPDUSRPacketStatus(
			vector<vector<AttrNodeInfo> >& attr_value_list,
			map<int, string>& regularparams);

		static bool ProcessF5HAState(
			vector<map<int, string> > &regularparams,
			vector<vector<AttrNodeInfo> > &attr_value_list);

	static int expr_caculate(string real_regular, bool & grouppass);

	static int platform_state_parse(vector<vector<AttrNodeInfo> >& attr_value_list, int i, bool& grouppass, bool& regularpass);

	static void pre_process_attrlist(CFTDRtnNetMonitorTaskResultField &resultField
	, vector<vector<AttrNodeInfo> >& attr_value_list, string & oldresult, int manufactory_id);

	static void process_memory_task(int manufactory_id,vector<vector<AttrNodeInfo> >& attr_value_list,int i,string	&newresult);

	static int parse_other_result(CFTDRtnNetMonitorTaskResultField &resultField
	, int manufactory_id, string deviceip, string deviceserial, string	&oldresult, string	&newresult);

	//���Խ�������صı��ʽ
	bool test_trading(string inputstr);

	/* */
	private:
		///���ڷ������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;

		///���ڷ������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgPbeSend;

		///��ʱ������
		CEventTimmer m_eventTimer;

		///�����������ļ���
		char *m_pSaveFile;

		///����ļ�ض����ַ���
		char m_mObjectId[MAXONESTRINGSIZE];

		///����ĵ�ǰ����
		char m_mDate[MAXONESTRINGSIZE];

		///����ĵ�ǰʱ��
		char m_mTime[MAXONESTRINGSIZE];

		///����ĵ�ǰָ����
		char m_mObjectAttr[MAXONESTRINGSIZE];

		///����ĵ�ǰָ��ֵ
		char m_mValue[MAXONESTRINGSIZE];

		///�����ȡ�������̶߳���
		CSavePosThread	m_threadFiler;

		///��Ҫ���ضϴ��������map
			///@key	����������CPUUsage��OrderSize
			///@value	Ϊ1��ʾ��Ҫ�Ѷ����ָ��ֵ��Ϊ���ĵ�ָ��ֵ
		map<string, int> m_mapApp;

		///������Ҫ����̬�е�״̬��Ϣת�����¼�������Ϣ
			///key	��̬�е�������,��san_cabinet
			///value	map<string, string>����key����KeyType��value����Attend
		map<string, T_strmap> m_mapRtnDBQueryClomn;

		// key: objectId, attrId
		// value: ����ָ���ʱ���
		map<CObjectAttrKey, CObjectAttrValue> m_mapLastItem;

		// ������������ļ���Ŀ¼
		string	m_sFilePath;

		//���������ļ�������
		//key:objectid_date_time, value: filecontent
		map<string, string> m_mapConfigContent;

		//����ִ�н��
		//key:ObjectID_Task_ID_OperateTime_MonDate_MonTime_InstructChain
		map<string, vector<CFTDRtnNetMonitorTaskResultField> >	m_mapTaskResult;

		//�����澯�¼������ip�б�
		map<string, int> m_chgWarnLevelIPList;

		//���潻�׽��б���Ϣ
		vector<TradeSectionInfo> m_TradeSectionsVec;

		//���潻�׽���Ҫͳ�ƵĶ���ָ����Ϣ
		map<CObjectAttrKey, int> m_StatObjectAttrMap;

		//���󰴽��׽ڱ������ֵ���ݵ�map
		map<string, string> m_TradeSectionPeaks;

		//�����ļ���
		string	m_sXMLFileName;

		/// �ı��Ա�ʵ��
		CFileDiff m_oFileDiff;

		// ����ͨ���߳�
		// �����ã������ע�͵�CPerHourMessage����
		//CPerHourMessage m_PerHourMessagethread;

	/* */
	public:
		// key: objectId	����ID���˴�������¼����ID����������������Ӧ��Activeʱ���, ��TRADE.PuDian.app
		// value: ����ָ��Active��ʱ���
		map<string, int> m_center;

		///�ڴ����ݿ�����̶߳���
		CMdbThread	*m_pThreadMdber;

	/* */
	public:
		CProbeServer m_cProbeServer;
		CFrontConnector m_cFrontServer;
		CNodeCacheBuffer *m_pNodeBuffer;		// �������ԵĻ�����
		CNodeCacheBuffer *m_pEventBuffer;		// �����¼��Ļ�����
		CConfigConnector m_cConfigConnector;	//���÷�����������
		unsigned int m_mSyslogEventId;			///�����¼�������ID��ţ��������ظ�
		unsigned int m_mWarningEventId;

		// ������Ϊ̽����Ҫ��ע�Ķ���ָ����
		map<CObjectAttrKey, int> m_mapProbeConfig;

		void RegisterAllConector(
		map<int, string> &mapCon,
		const char	*pConfigLocation)
		{
			for (map<int, string>::iterator itor = mapCon.begin();
				 itor != mapCon.end();
				 itor++)
			{
				RegisterConnecter((char *)itor->second.c_str());

				CFlowManager *pFlowM = new CFlowManager(
						itor->first,
						(char *)itor->second.c_str(),
						this);
				m_mapSnmpFlow[itor->second] = pFlowM;
			}

			//�������÷�����
			m_cConfigConnector.RegisterConnecter(pConfigLocation);
		}

		void RegisterAllListener(
		const char	*pCounterLocation,
		const char	*pFrontLocation,
		const char	*pProbeLocation)
		{
			RegisterListener((char *)pCounterLocation);
			m_cFrontServer.RegisterListener((char *)pFrontLocation);
			m_cProbeServer.RegisterListener((char *)pProbeLocation);
		}

		void StartAll(void)
		{
			Start();
			m_cFrontServer.Start();
			m_cProbeServer.Start();
			m_cConfigConnector.Start();
		}

		void initBuffer(void)
		{
			m_mSyslogEventId = 1;
			m_mWarningEventId = 1;
			m_mOsInterval = 300;
#ifdef DEVELOP_ENV
			m_pNodeBuffer = new CNodeCacheBuffer(
					200000,
					sizeof(CFTDRtnObjectAttrField));
			m_pEventBuffer = new CNodeCacheBuffer(
					100000,
					sizeof(CFTDRtnSyslogEventField));
#else
			m_pNodeBuffer = new CNodeCacheBuffer(
					2000000,
					sizeof(CFTDRtnObjectAttrField));
			m_pEventBuffer = new CNodeCacheBuffer(
					1000000,
					sizeof(CFTDRtnSyslogEventField));
#endif

			/*
		time_t timep;
		struct tm *p;
		time(&timep);
		p = localtime(&timep);
		m_mTradeDay = (1900+p->tm_year)*10000+(1+p->tm_mon)*100+p->tm_mday;
		*/
		}

	/* */
	public:
		int m_mOsInterval;			// ����ϵͳ������ͳ��Ƶ��
		static int	m_mTradeDay;	// ��ǰ�Ľ�����

	/* */
	private:
		map<string, CFlowManager *> m_mapSnmpFlow;
};

class CWarnInfo
{
	/* */
	public:
		CFTDRtnWarningEventField m_warningField;
		CFTDRtnWarningQueryField m_warningInfo;
		CWarnInfo(void)
		{
		}

		CWarnInfo(
		const CFTDRtnWarningEventField	&warningField,
		const CFTDRtnWarningQueryField	&warningInfo)
		{
			m_warningInfo = warningInfo;
			m_warningField = warningField;
		}

		CWarnInfo(const CWarnInfo &ob)
		{
			m_warningInfo = ob.m_warningInfo;
			m_warningField = ob.m_warningField;
		}

		void operator=(const CWarnInfo &ob)
		{
			m_warningInfo = ob.m_warningInfo;
			m_warningField = ob.m_warningField;
		}
};
class CListWarningEventField
{
	/* */
	public:
		CListWarningEventField(void)
		{
			m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
		}

		~ CListWarningEventField(void);

		///���澯�¼�д�뵽���ݶ��к���
			///@param	warningEvent	�澯�¼�����
			///@return	true��ʾ�ɹ���false��ʾʧ��
		bool WriteValue(
		CFTDRtnWarningEventField &warningEvent,
		CFTDRtnWarningQueryField &warningInfo)
		{
			m_lockData.Lock();
			m_listEvent.push_back(CWarnInfo(warningEvent, warningInfo));
			m_lockData.UnLock();
			return true;
		}

		///�����ݶ��ж����¼�д�뵽ǰ�õ����Ͳ�ѯ��
			///@param	eventcounter	�¼�����ȫ��ָ��
		void ReadValue(CEventCounterServer * &eventcounter);

	/* */
	protected:
	/* */
	private:
		// �澯�¼��������
		list<CWarnInfo> m_listEvent;

		// �����������ڱ��� ���ݶ���
		CMutex	m_lockData;

		///���ڷ������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;
};

/************************************************************************
* �����¼ͳ�ơ��澯����
************************************************************************/
// ʹ��string��������ID
typedef std::string MdLoginRecordID;

/////////////////////////////////////////////////////////////////////////
/// MdLoginRecord�����������¼ͳ����Ϣ
/// �ö��������ͳ�Ƶ�½��Ϣ������ĸ澯����������������
/// @author	����
/// @version	1.0,20150520
/////////////////////////////////////////////////////////////////////////
class MdLoginRecord
{
public:
	enum MdLoginState	// �����¼��״̬������
	{
		AllState,		// ʵ����û�д�״̬����Ϊ��ʾ����״̬�ĺϼ�
		Success,
		Failure
	};
public:
	// ��ͳ���б��л�ȡһ����¼����������Ӷ�Ӧ�ļ�¼�����ض���
	static MdLoginRecord* fetchRecord(const MdLoginRecordID& _id);
	// ��ͳ���б���ɾ��һ����¼
	static void removeRecord(const MdLoginRecordID& _id);
	// �������м�¼
	static void resetAllRecords();

public:
	// ��ȡID
	const MdLoginRecordID& getRecordID() const { return m_RecordID; }

	// ��½����+1
	void record(time_t _time, MdLoginState _state, const char* _mdkernelID)
	{ m_LoginRecords.push_back(LoginInfo(_time, _state, _mdkernelID)); }

	// �����_endMomentʱ����ǰ_timeLength����ָ��״̬�ĵ�¼����
	// Ĭ��ֵAllState��ʾ����״̬
	int loginCount(time_t _endMoment = 0, int _timeLength = 0, MdLoginState _state = AllState) const;
	// ��ȡ����ָ��״̬�ĵ�¼��ϸ
	// _endMoment��¼����ֹʱ�̣�_timeLength��ǰ�����ʱ�䳤��
	// _outputLen��������ǰN�����ݣ���������ַ�������
	// _stateָ��״̬
	string loginDetail(time_t _endMoment = 0, int _timeLength = 0, int _outputLen = 2, MdLoginState _state = AllState) const;

	// ��ȡ��¼״̬������ϸ�����ɹ���¼������ʧ�ܵ�¼����
	// Interval=%d, IntSucc=%d, IntFail=%d, IntAll=%d, TotalSucc=%d, TotalFail=%d, TotalAll=%d
	string loginCountDetail(time_t _endMoment = 0, int _timeLength = 0);
	
	// ���ü�¼
	void resetRecord() { m_LoginRecords.clear(); }

private:
	MdLoginRecord(const MdLoginRecordID& _RecordID)
		: m_RecordID(_RecordID) { }

	~MdLoginRecord() {}

	// �������������ͳ����Ϣ
	static map<MdLoginRecordID, MdLoginRecord*> m_AllRecords;

	/* LoginRecordID */
	MdLoginRecordID m_RecordID;

	/* ��¼������ĵ�¼��Ϣ����¼״̬������ʱ��͵�¼��Mdkernel ID */
	struct LoginInfo
	{
		LoginInfo(time_t _time, MdLoginState _state, const string& _mdkernelID)
			: LoginTime(_time), LoginState(_state), MdkernelID(_mdkernelID) { }
		time_t LoginTime;
		MdLoginState LoginState;
		string MdkernelID;
	};
	vector<LoginInfo> m_LoginRecords;
};

/////////////////////////////////////////////////////////////////////////
///MdLoginWarningCalculate�����������¼�澯���㹦��
///@author	����
///@version	1.0,20150513
/////////////////////////////////////////////////////////////////////////
class MdLoginWarningCalculate
{
public:
	/* �������ļ��ж�ȡ������� */
	static bool loadCalculateObjectFromXml(const char* _fileName);

	/* �ַ�����ʽʱ��ת��Ϊtime_t����������ʱ����-1 */
	static inline time_t convertToTime(const CDateType& _date, const CTimeType& _time)
	{
		struct tm sTM;
		sscanf(_date.getValue(), "%4d%2d%2d",
			&sTM.tm_year, &sTM.tm_mon, &sTM.tm_mday);
		sscanf(_time.getValue(), "%2d:%2d:%2d",
			&sTM.tm_hour, &sTM.tm_min, &sTM.tm_sec);
		sTM.tm_year -= 1900;
		sTM.tm_mon--;
		sTM.tm_isdst = -1;
		return mktime(&sTM);
	}

private:
	MdLoginWarningCalculate(
		const char* _EventName,
		int _Interval,
		int _Threshold,
		int _WarningGap,
		MdLoginRecord::MdLoginState _TargetState)
		: m_EventName(_EventName), m_Interval(_Interval),
		m_Threshold(_Threshold), m_WarningGap(_WarningGap),
		m_TargetState(_TargetState)
	{
	}
	~MdLoginWarningCalculate() {}

public:
	/* ����һ�������¼��Ϣ */
	static void HandleMdLogin(
		const CDateType& _loginDate,				// �����¼������
		const CTimeType& _loginTime,				// �����¼��ʱ��
		MdLoginRecord::MdLoginState _loginState,	// �����¼��״̬
		const char* _mdkernelID,					// ���鱾�ε�¼��mdkernel��ObjectID
		MdLoginRecordID _recordID);					// ����ID

	/* �������и澯���������м�״̬ */
	static void reset()
	{
		for (vector<MdLoginWarningCalculate*>::iterator
			itObject = m_AllCalculate.begin();
			itObject != m_AllCalculate.end();
		++itObject)
		{
			(*itObject)->clearMdStateState();
		}
	}

private:
	// ����ǰ�澯�����µ�����ϯλ�м�״̬
	void clearMdStateState() { m_AllRecordState.clear(); }

	// ����һ����¼��_BasisTimeΪ�ü�¼�Ļ�׼ʱ�̣�_LocalTimeΪ����ʱ��
	void HandleRecord(MdLoginRecord* _Record, time_t _BasisTime, time_t _LocalTime);

private:
	/* �澯���� */
	string m_EventName;

	/* ͳ������ */
	int m_Interval;

	/* �澯��ֵ */
	int m_Threshold;

	/* �ø澯�Ƿ���Ե�Login״̬ */
	MdLoginRecord::MdLoginState m_TargetState;

	/* �澯��� */
	int m_WarningGap;

	/* ��Ըø澯������󣬱���ÿ����¼���м�״̬ */
	struct RecordState
	{
		RecordState() : LastWarningTime(0) {}
		time_t LastWarningTime;	// ���û���һ�η��͸ø澯��ʱ��
	};
	map<MdLoginRecordID, RecordState> m_AllRecordState;

	/* ��ȡ�ض���¼���м�״̬���������� */
	RecordState& getRecordState(const MdLoginRecordID& _RecordID);

	/* �������еļ������ */
	static vector<MdLoginWarningCalculate*> m_AllCalculate;

	/* ������ڷ������ݵİ� */
	static CFTDCPackage m_pkgSend;
	/* ������������� */
	static CFTDRtnSyslogEventField m_SyslogEventField;
};

#endif // REF_EVENTCOUNTERSERVER_H
