/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	DatabaseSpiImpl.h
///@brief	���������ݿ��ȡ̽�����
///@history
///20080510	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
///20090515 ����		�Ѷ����ݿ�ķ�������һ���̣߳������н�������ȥ�����к�ͨѶ�йصĳ�Ա�Ͳ���
///20100204	�ܽ���		����ע��˵��m_DatabaseInfoMap��m_dbConnections����;
#ifndef REF_DATABASESPIIMPL_H
#define REF_DATABASESPIIMPL_H

#include "public.h"
#include "CachedFileFlow.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"

#include "SQLAPI.h"

class CSPQuery
{
	/* */
	public:
		~CSPQuery(void)
		{
		}

		CSPQuery(void)
		{
			objectId = "";
			attrType = "";
			requestId = 0;
			session = NULL;
		}

		CSPQuery(
		const char	*pObjectId,
		const char	*pAttrType,
		DWORD nRequestId,
		const CFTDCSession	*pSession)
		{
			objectId = pObjectId;
			attrType = pAttrType;
			requestId = nRequestId;
			session = (CFTDCSession *)pSession;
		}

		CSPQuery(const CSPQuery &ob)
		{
			objectId = ob.objectId;
			attrType = ob.attrType;
			requestId = ob.requestId;
			session = ob.session;
		}

		void operator=(const CSPQuery &ob)
		{
			objectId = ob.objectId;
			attrType = ob.attrType;
			requestId = ob.requestId;
			session = ob.session;
		}

	/* */
	public:
		string	objectId;
		string	attrType;
		DWORD requestId;
		CFTDCSession *session;
};

/////////////////////////////////////////////////////////////////////////
///CDataBaseAttr������ʱ��δ�����
///@author	�ܽ���
///@version	1.0,20090625
/////////////////////////////////////////////////////////////////////////
class CDataBaseAttr
{
	/* */
	public:

		///ȱʡ���캯��
		CDataBaseAttr(void)
		{
			sDNSName = "";
			sInstanceName = "";
			sReturnType = "";
			m_nLastRunSec = 0;
			m_nLogId = 0;
			m_sOpTime = "00:00:00";

			time_t	timep;
			time(&timep);

			struct tm tm_time;
			LocalTime(&timep, &tm_time);
			char tmp[9];
			sprintf(
				tmp,
				"%04d%02d%02d",
				tm_time.tm_year + 1900,
				tm_time.tm_mon + 1,
				tm_time.tm_mday);
			m_sOpDate = tmp;
		}

		///���캯��
			///@param	pDNSName	���ݿ����
			///@param	pInstanceName	���ݿ�ʵ������洢��������
			///@param	pSeps	�ò�����Ӧ������ʱ���
		CDataBaseAttr(
		const char	*pDNSName,
		const char	*pInstanceName,
		const char	*pSeps)
		{
			char *p = strchr((char *)pInstanceName, ':');
			if (p != NULL)
			{
				*p = '\0';
				p++;
			}
			else
			{
				p = DATACENTERDB;
			}

			sDNSName = pDNSName;
			sInstanceName = pInstanceName;
			sReturnType = p;
			m_nLastRunSec = 0;
			m_nLogId = 0;
			m_sOpTime = "00:00:00";
			p = (char *)pSeps;
			while (p != NULL)
			{
				if (isValid(p))
				{
					m_vSep.push_back(CSeps(p));
				}

				p = strchr(p, ',');
				if (p != NULL)
				{
					p++;
				}
			}

			time_t	timep;
			time(&timep);

			struct tm *pGm = localtime(&timep);
			char tmp[9];
			sprintf(
				tmp,
				"%04d%02d%02d",
				pGm->tm_year + 1900,
				pGm->tm_mon + 1,
				pGm->tm_mday);
			m_sOpDate = tmp;
		}

		///�������캯��
		CDataBaseAttr(const CDataBaseAttr &ob)
		{
			sDNSName = ob.sDNSName;
			sInstanceName = ob.sInstanceName;
			sReturnType = ob.sReturnType;
			m_nLastRunSec = ob.m_nLastRunSec;
			m_vSep.clear();
			for (unsigned int i = 0; i < ob.m_vSep.size(); i++)
			{
				m_vSep.push_back(ob.m_vSep[i]);
			}

			if (m_sOpDate == "")
			{
				m_sOpDate = ob.m_sOpDate;
				m_sOpTime = ob.m_sOpTime;
				m_nLogId = ob.m_nLogId;
			}
		}

		CDataBaseAttr &operator=(const CDataBaseAttr &ob)
		{
			sDNSName = ob.sDNSName;
			sInstanceName = ob.sInstanceName;
			sReturnType = ob.sReturnType;
			m_nLastRunSec = ob.m_nLastRunSec;
			m_vSep.clear();
			for (unsigned int i = 0; i < ob.m_vSep.size(); i++)
			{
				m_vSep.push_back(ob.m_vSep[i]);
			}

			if (m_sOpDate == "")
			{
				m_sOpDate = ob.m_sOpDate;
				m_sOpTime = ob.m_sOpTime;
				m_nLogId = ob.m_nLogId;
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
				&&	*(p + 17) == '.'
				);
		}

		///�ж��Ƿ���Ҫȡ��ָ��
			///@param	nNowSec	��ϵͳ��ȡ�õ��������Ѿ�������ʱ�
			///@return	true��Ҫִ��,false����Ҫִ��
		bool needExcute(const int nNowSec)
		{
			if (nNowSec < m_nLastRunSec)
			{
				return false;
			}
			else
			{
				int nTemp = nNowSec % 86400;
				for (unsigned int i = 0; i < m_vSep.size(); i++)
				{
					if (nTemp < m_vSep[i].m_nStart)
					{
						m_nLastRunSec = nNowSec - nTemp + m_vSep[i].m_nStart;
						return false;
					}
					else if (nTemp >= m_vSep[i].m_nStart
						 &&	 nTemp < m_vSep[i].m_nEnd)	// ȡ��ʱ��εĲ���Ƶ��
					{
						m_nLastRunSec = nNowSec -
							(
								nNowSec %
								m_vSep[i].m_nInterval
							) +
									m_vSep[i].m_nInterval;
						return true;
					}
				}

				if (m_vSep.size() == 0)
				{
					m_nLastRunSec = nNowSec + 86400;
					return false;
				}
				else
				{
					m_nLastRunSec = nNowSec -
						nTemp +
						86400 +
						m_vSep[0].m_nStart;
					return false;
				}
			}
		}

	/* */
	protected:
	/* */
	public:
		///���ݿ����
		string	sDNSName;

		///�������ݿ��SP��������,CURSOR,NOCURSOR..
		string	sInstanceName;

		///SP���ص������б������ݿ��໹��Ӧ����db,app
		string	sReturnType;

		///����ʱ������
		vector<CSeps> m_vSep;

		///�ϴβ������ݿ�ʱ��,�ӵ�����㿪ʼ������
		int m_nLastRunSec;

		///�ϴζ�ȡ�������ݿ���־��Logid��ֵ
		unsigned long m_nLogId;

		///�ϴζ�ȡ�������ݿ���־��OpDate��ֵ
		string	m_sOpDate;

		///�ϴζ�ȡ�������ݿ���־��OpTime��ֵ
		string	m_sOpTime;
};

class CDBQueryField
{
	/* */
	public:
		///��ѯ����ID
		string	m_objectID;

		///��ѯ��SP����
		string	m_attrType;

		///�����RequestID
		DWORD m_requestID;

		///�����FTD�Ự
		CFTDCSession *m_session;

		///�������Ƿ�����ɱ��
		bool m_reqFlag;

		///������Ľ������ֵ
		int m_rtnCode;

		///������Ľ���ַ���Ӧ��
		string	m_rtnMsg;

		///�����ѯ��õĽ��
		list<CFTDRspQryDBQueryField> m_dbQuery;
};

/////////////////////////////////////////////////////////////////////////
///CDatabaseSpiImpl���������ݿ��ָ��ɼ���
///@author	�ܽ���
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CDatabaseSpiImpl
{
	/* */
	public:
		CDatabaseSpiImpl(void);
		~ CDatabaseSpiImpl(void);

	/* */
	public:
		///���ݿ���ɼ�����
			///@param	nNowTimeSec	��ǰ��ʱ�䣬δ����ʱ������
			///@return	
		void GetDatabaseSpi(time_t nNowTimeSec);

		///���ڸ������ݿ�����map������
			///@param	sConfigName	���ݿ����ñ���
			///@param	sConnectString	���ݿ������õ���Ϣ
		void UpdateDatabaseInfoMap(
				string	&sConfigName,
				CDBConnectString &sConnectString);

		///���ڸ���ָ��ɼ�map������������������ͳ�Ʊ��С
			///@param	pAttrName	���ݿ�ָ������
			///@param	pSeps	ָ�����ʱ���Ƶ��
			///@param	pDNSName	���ݿ�ı���
			///@param	pTableName	���ݿ�ı�����
		void UpdateDBAttrMap(
				const char	*pAttrName,
				const char	*pSeps,
				const char	*pDNSName,
				const char	*pTableName);

		///���ڸ������ݿ���ô洢���̶���
			///@param	pSPName	SP����
			///@param	pSeps	��ȡSP��ʱ�估Ƶ����Ϣ
			///@param	pDNSName	���ݿ������Ϣ
			///@param	pSPType	SP�ķ���ֵ����
		void UpdateSPInfoMap(
				const char	*pSPName,
				const char	*pSeps,
				const char	*pDNSName,
				const char	*pSPType);

		///���ڸ������ݿ��ȡ��־�����
			///@param	pTableName	��־������
			///@param	pSeps	��ȡ��־���ʱ�估Ƶ����Ϣ
			///@param	pDNSName	���ݿ������Ϣ
			///@param	pPosition	���ݿ���ȡ��ƫ������Ϣ
		void UpdateDBLogMap(
				const char	*pTableName,
				const char	*pSeps,
				const char	*pDNSName,
				const char	*pPosition);

		///���ڸ������ݿ���ʱ��ѯ���������
			///@param	pObjectId	�������ݿ�����ID
			///@param	pAttrType	�������ݿ��ѯ��SP����
			///@param	dRequestId	�����RequestId���
			///@param	pSession	������������ftd Session
		void UpdateSPQuery(
				const char	*pObjectId,
				const char	*pAttrType,
				const DWORD dRequestId,
				const CFTDCSession	*pSession);

		void UpdateConfig(CFTDRspQryHostConfigField *hostConfig);

	///20080717 add by wu.yb
	private:
		///�������ݿ⺯��������������ŵģ��Ͳ��ٽ�������
			///@param	strIp	���ݿ��������IP��ַ
			///@param	port	���ݿ�������Ķ˿ں�
			///@param	strDbName	���ݿ�ʵ����
			///@param	strUser	���ݿ��û���
			///@param	strPwd	���ݿ��û���Ӧ������
			///@return	�������ݿ��SAConnection����ָ��
		SAConnection *connectDB(
						const string &strIp,
						int port,
						const string &strDbName,
						const string &strUser,
						const string &strPwd);

		///the database server connection status
			///����ʹ�õ�SQLAPI�汾û������������µİ汾��
			///�ж����ݿ��Ƿ���Ļ�Ծ����
			///@param	conn	���ݿ�����ָ��
			///@return	true��ʾ���ӻ�Ծ��false��ʾ���Ӳ�����
		bool isAlive(SAConnection *conn);

		///��ȡ������ļ�¼������
			///@param	conn	���ݿ�����ָ��
			///@param	tableName	���ݿ������
			///@return	���ظñ��С������¼����
		long getRecordNum(SAConnection *conn, const string &tableName);

		string	getCmdText(const string &tableName) const;
		string	getConnectStr(
					const string &ip,
					int port,
					const string &dbName) const;

		//2008.10.15 add and change by wu.yb
		//��Ϊ��Ҫ�����µ�ָ�ꣻ ������Щָ�겻�����ݿ��ߴ���������ʽ��
		//����OrderSize  TradeSize �Ǽ����ĳߴ磬����ԭ���ķ�ʽ��ʹ��select count(1) from table�����ĳߴ磬
		//�� TotalVolume ָ��ȴ��Ҫʹ�� select sum(Volume) from  table���м���
		//TotalAmount select a.Volume * a.Price * b.VolumeMultiple from currsgoperation.t_trade a , sync.t_Instrument b
		// ���������������������GetSpi���е�����
		// 1 ������صĲ��ֶ���������
		// 2 �� tableSize TotalVolume TotalAmount ��3��ָ��ֱ��岻ͬ�ĺ���
		int getVolume(SAConnection *conn, const string &tableName);
		double	getAmount(SAConnection *conn);

		///ִ�д洢���̺���	20090624 add by zhou.jj
			///@param	conn	���ݿ�����ָ��
			///@param	spName	�洢��������
			///@param	dataBaseAttr	�洢���̶�Ӧ�����ݿ������ʱ�Ρ��洢��������
			///@return	
		bool getSP(
				SAConnection *conn,
				const string &spName,
				CDataBaseAttr &dataBaseAttr);

		///ִ�����ݿ���ʱ�����������
			///@param	cDBQueryField	���ݿ���ʱ�������
			///@return	
		bool getReqSP(CDBQueryField &cDBQueryField);

		///ִ��ȡ���ݿ���־��
			///@param	conn	���ݿ�����ָ��
			///@param	tableName	���ݿ���־������
			///@param	dataBaseAttr	���ݿ���־����Ϣ
			///@return	
		bool getDBLog(
				SAConnection *conn,
				const string &tableName,
				CDataBaseAttr &dataBaseAttr);

		///����ָ������
		// @param attrName ָ�������
		// @param attrValue ָ�����ֵ
		// @param valueType
		void sendData(
				const char	*attrName,
				const char	*attrValue,
				int valueType);

		///�������ݿ�����Ӳ��������������ӣ�ͬʱ�����Ӷ�����л���
			///@param	dbName ��Ҫ���ҵ����ݿ�ı���
			///@param	returnType	ʹ�ø����ݿ����ӵ�Ӧ����sp���ͻ���db����,�������������ݿ��ص��õ�sp����ҵ��ϵͳȡָ���sp
			///@return �������ݿ�����ָ�룬NULL ����ȡ�����ݿ����Ӷ���
		SAConnection *getConnectionObj(
						const string &dbName,
						const string &returnType);

		/// �ж�һ�����Ե�����ַ���(��[.]���зָ�)�Ƿ��ض����ַ���
		//orignal="xxx.yyy.[DbTotalVolume|DbTotalAmount]
		// ���õ��Ǵ�Сд�����еķ�ʽ
		bool isXProp(const char *orignal, const char *propKey) const;

		///�����澯�¼�����������͵����е�����
			///@param	pEventName	�澯�¼���
			///@param	pObjectName	�澯������
			///@param	pEventDes	�澯������Ϣ
			///@param	pDBName		�澯���������ݿ����
		void GenerateProbeEvent(
				char *pEventName,
				char *pObjectName,
				char *pEventDes,
				char *pDBName);

	/* */
	private:
		// Added by Henchi 20080721
			///���浱�������
		char m_mDate[10];

		///����ĵ�ǰ�ɼ�ʱ��
		char m_mTime[10];

		///����Ĳɼ�����ID
		char m_mObjectId[64];

		///�ɼ�����������Ϣ��FTD��
		CFTDRtnObjectAttrField	m_ObjAttrInfo;

		///�澯������ʱ����
		int m_nInterval;

		///�澯�¼����кţ�����
		int m_nEventId;

		///�澯�¼�����ţ���ͬ�������ͬ�澯ÿ�ξ���ͬ
		int m_nEventNum;

		///@key	�澯�¼�����
			///@value	�澯���������ʱ��
		map<string, int> m_mapEventDesc;

		///@key	���ݿ����
			///@value	���ݿ������Ӧ��������Ϣ
		map<string, CDBConnectString> m_DatabaseInfoMap;	// ���ݿ�������Ϣ
		
			///@key	���ݿ��ObjectID
			///@value	���ݿ����
		map<string, string> m_ObjectIdDBNameMap;			//�������ݿ�Ķ���ID����Ӧ������Ϣ
		
			///���ڻ��������ͬ�����ݿ������

		//QQQQ ��Ҫ���Ǹ�ֵ������
			///�������ָ����д洢�����⸳ֵ�����Ĳ�������
			///@key	���ݿ����
			///@value	�øñ������������ݿ�����ָ��, ���mapͬm_DatabaseInfoMapһͬʹ��
		map<string, SAConnection *> m_dbConnections;

		///���ڻ��������ͬ�����ݿ�������Ƿ�������Ծ��һ��spi��������ֻ��������ִ��SQLһ��
			///@key	�øñ������������ݿ�����ָ��,
			///@value	�����Ƿ�������Ծ
		map<SAConnection *, bool> m_connActive;

		///@key	���ָ������,��tinit.DBSeriesLen
			///@value	���ָ����Ҫ�ɼ��ı��������ݿ�����ṹ�б�
		map<string, listTDB> m_DBAttrMap;					// ���ݿ���ָ����Ϣ
			///@key	���ָ������,��tinit.DBSeriesLen
			///@value	���ָ���Ӧ��ʱ�Σ���ʱ���ݿ������Ч
		map<string, CDataBaseAttr>	m_DBAttrSepsMap;		// ���ݿ���ָ����Ϣ
		
			///@key	�洢������,��dbmonitorpkg.getinstancenameproc
			///@value	�洢���̶�Ӧ�����ݿ������ʱ�Ρ��洢��������
		map<string, CDataBaseAttr>	m_SPmap;				//������Ҫ�ɼ���SP��Ϣ
		
			///@key	���ݿ���־������,��monitor.t_syslog
			///@value	��־���Ӧ�����ݿ������ʱ��
		map<string, CDataBaseAttr>	m_DBLogmap;				//������Ҫ�ɼ������ݿ���־����Ϣ

	/* */
	public:
		//20090515 By Solomon Wu
		deque<CFTDRtnObjectAttrField> m_attrInfo;
		deque<CFTDRtnWarningEventField> m_eventInfo;
		deque<CFTDRtnSyslogEventField>	m_syslogInfo;
		deque<CFTDRtnDBQueryField>	m_dbqueryInfo;

		///���浱ǰ����δ����ĺ��Ѿ�����Ĳ�ѯ����
		list<CDBQueryField> m_reqDbQuery;

		///���浱ǰ����δ���͵Ķ���ID����ID�����Ϣ
		list<CFTDRtnUpdateSysConfigField> m_updateConfigInfo;

		CMutex	m_dataLock;
		CMutex	m_cmdLock;
		list<CFTDRspQryHostConfigField> m_configList;
		list<CSPQuery>	m_spQueryList;
};
#endif // !defined(REF_DATABASESPIIMPL_H)
