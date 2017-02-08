/////////////////////////////////////////////////////////////////////////
///@system ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file DBOperator.h
///@brief ���ݿ������
///@history
///20110531	��־ΰ   �������ļ�
/////////////////////////////////////////////////////////////////////////
#ifndef __DB_OPERATOR_H
#define __DB_OPERATOR_H

#include <SQLAPI.h>
#include <FTDDataWrapper.h>
#include <PrjCommon.h>
#include <ThreadPool.h>
#include <SyncEvent.h>
#include <vector>
#include <string>
#include <map>

using namespace std;

/**DBOperator ���ݿ�����ӿڣ����������CFtdData������صı�Ĳ�����ʵ������ɾ���ġ������ֲ�����
*/
class DBOperator
{
	/* */
	public:
		DBOperator(void)
		{
		}

		virtual~DBOperator(void)
		{
		}

		/**�����ݿ⣬��������
	* @param ip ���ݿ�ĵ�ַ
	* @param port �˿ں�
    * @param dbName ���ݿ���
    * @param user �û���
    * @param pwd ����
    * @return �ɹ��򿪷���true, ʧ�ܷ���false
	*/
		virtual bool Open(
						const string &ip,
						const string &port,
						const string &dbName,
						const string &user,
						const string &pwd) = 0;

		/**�ر����ݿ⡣
	*/
		virtual void Close(void) = 0;

		/**����һ����¼����obj���������Ե�ֵ��Ϊһ����¼��������Ӧ�ı���
	* @param sql �����¼��sql��䣬
	* @param obj ����Դ
    * @return �ɹ�����true, sqlΪ�գ�obj��Ч������ʧ�ܣ�����false
	*/
		virtual bool InsertRecord(
						const char	*table,
						const CFtdData	*obj,
						bool bLogout = true) = 0;

		/** Column�Ƕ�CFtdData�������ض����Եĳ���Ϊ���ݿ�����ṩ��
    * @param obj CFtdData����
    * @param attrName ���Ե�����
	*/
		struct Column
		{
			const CFtdData	*obj;
			string	attrName;

			Column (const CFtdData *o, const char *n)
			:
			obj(o),
			attrName(n)
			{
				assert(obj);
			}
		};

		typedef std::vector<Column> ColumnArray;

		/**ɾ����¼��ɾ�����������ҵ���obj��attr������ֵͬ�ļ�¼
	* @param table ɾ����¼�ı���
    * @param obj ����Դ�������Ϊ�գ�����ɾ���������м�¼
    * @param objAttr ����Դ�����ԣ�����������һ���֣������Ϊ�գ�����ɾ���������м�¼
    * @return �ɹ�����true, sqlΪ�գ�ɾ��ʧ�ܣ�����false
	*/
		virtual bool DeleteRecord(
						const char	*table,
						const CFtdData	*obj = NULL,
						const char	*objAttr = NULL) = 0;

		/**ɾ����¼��ɾ��������Ϊ��¼��recordValues��ָ����ֵ��cmpValues��ȡ�
	* @param table ɾ����¼�ı���
    * @param recordValues ɾ�������м�¼���������֡����recordValues���ж�����ԣ���Щ���Ե���ȹ�ϵΪ && (��)��
    * @param cmpValues ɾ�������м�¼������Ҫ�Ƚϵ�ֵ(ֻ֧����ȹ�ϵ)��
    *                       ע�⣺cmpValues��ֵ��recordValues��ֵ���Ӧ��
    * @return �ɹ�����true, sqlΪ�գ�ɾ��ʧ�ܣ�����false
	*/
		virtual bool DeleteRecord(
						const char	*table,
						const ColumnArray &recordValues,
						const ColumnArray &cmpValues) = 0;

		/**��CFtdData������������Ӧ�ı�������������Ե�ֵ�������������ݿ�
	* @param sql ���¼�¼��sql���
	* @param obj ����Դ
    * @param objAttr ���µ�����������¼��objAttr��obj��objAttrֵ��ȵļ�¼���ᱻ����Ϊobj��ֵ��
    * @return �ɹ�����true, sqlΪ�գ�objΪ�գ�objAttrΪ�գ�����ʧ�ܣ�����false
	*/
		virtual bool UpdateRecord(
						const char	*table,
						const CFtdData	*obj,
						const char	*objAttr) = 0;

		/**���¼�¼�����µ�����Ϊ��¼��recordValues��ָ����ֵ��cmpValues��ȡ�
	* @param table ���¼�¼�ı�
    * @param obj ����Դ������ʱ�Ὣ����Դ���������Զ���������¼��
    * @param recordValues ���������м�¼���������֡����recordValues���ж�����ԣ���Щ���Ե���ȹ�ϵΪ && (��)��
    * @param cmpValues ���������м�¼������Ҫ�Ƚϵ�ֵ(ֻ֧����ȹ�ϵ)��
    *                       ע�⣺cmpValues��ֵ��recordValues��ֵ���Ӧ��
    * @return �ɹ�����true, sqlΪ�գ�����ʧ�ܣ�����false
	*/
		virtual bool UpdateRecord(
						const char	*table,
						const ColumnArray &recordValues,
						const ColumnArray &cmpValues) = 0;

		/**���ұ��ҵ���¼�󣬶�ÿ����¼������DBOperatorCallback��HandleSearchResult������
    * �˷�����Ҫ��Բ����Ƚ�����SQL��䣬���Ƚϵ�SQL���ɲο���һ������
	* @param sql ���Ҽ�¼��sql��䣬���в����Ƚϲ�����
	* @param cb  ���Ҽ�¼��ͬ���ص�����ÿ�β��ҵ����ʱ���ûص��ͻᱻ����
	* @param cbData ���Ҽ�¼��ͬ���ص�����Ҫ�����ݣ�����ΪNULL��
    * @return �ɹ�����true, sqlΪ�գ�cbΪ�գ���ѯʧ�ܣ�����false
	*/
		typedef void (*searchHander_t) (SACommand &records, void *data);
		virtual bool SearchRecord(
						const string &sql,
						searchHander_t cb,
						void *cbData = NULL) = 0;

		/**���ұ��ҵ���¼�󣬶�ÿ����¼������DBOperatorCallback��HandleSearchResult������
    * �˷�����Դ��Ƚ�������SQL��䣬��������ֵ�ɵ��������ú��ٴ���ִ��
	* @param cmd �Ѿ����ú�sql��䣬�����趨�ò���ֵ��SACommand
	* @param cb  ���Ҽ�¼��ͬ���ص�����ÿ�β��ҵ����ʱ���ûص��ͻᱻ����
	* @param cbData ���Ҽ�¼��ͬ���ص�����Ҫ�����ݣ�����ΪNULL��
    * @return �ɹ�����true, sqlΪ�գ�cbΪ�գ���ѯʧ�ܣ�����false
	*/
		bool SearchRecord(
				SACommand &cmd,
				searchHander_t cb,
				void *cbData = NULL);

		///** ����ָ����SQL������������ݿ⡣sql�����������֣�ͨ��������ָʾ��
		//   * ���� select * from table where AA = :1 order by AA
		//* @param sql �ض���sql���
		//* @param conditions sql�������Ҫ���������������Ҫ��sql�����:number �ĸ���һ�¡�
		//   * @return �ɹ�����true, sqlΪ�գ�����ʧ�ܣ�����false
		//*/
		//   virtual bool SearchRecord(const string& sql, const ColumnArray& conditions,
		//       searchHander_t cb, void * cbData = NULL) = 0;
		
			///** ����ָ����SQL������������ݿ⣬sql�����������֣�ͨ��������ָʾ��
		//   * ���� select * from table where AA = :AA order by AA
		//* @param sql �ض���sql���
		//* @param recordValues sql�����:name�����ּ��ϡ�
		//* @param conditions sql�������Ҫ���������������Ҫ��sql�����:name �ĸ���һ�¡�
		//   * @return �ɹ�����true, sqlΪ�գ�����ʧ�ܣ�����false
		//*/
		//   virtual bool SearchRecord(const string& sql, const ColumnArray& recordValues, const ColumnArray& conditions,

	//       searchHander_t cb, void * cbData = NULL) = 0;
	private:
		DISALLOW_COPY_AND_ASSIGN(DBOperator);
};

/**SqlGenerator��һ��SQL��������������Ը���CFtdData�������������������ص�SQL���
*/
class SqlGenerator
{
	/* */
	public:
		SqlGenerator(void)
		{
		}

		~SqlGenerator(void)
		{
		}

		typedef DBOperator::Column Column;
		typedef DBOperator::ColumnArray ColumnArray;

		/**�����¼��SQL���
	* @param table ������ı�
	* @param obj ����Դ
    * @return ����������SQL��䣬���tableΪ�գ�objΪ�գ�����obj��û�����ԣ����ؿմ�
	*/
		string	InsertCmd(const char *table, const CFtdData *obj);

		/**ɾ����¼��SQL���
	* @param table ������ı�
	* @param attr ����������֣�����ɾ��������Ŀǰֻ֧�� =�������Ϊ�գ�����ɾ���������м�¼
    * @return �ɹ�����SQL��䣬���tableΪ�գ����ؿմ�
	*/
		//string DeleteCmd(const char * table, const char * attr = NULL);
		string	DeleteCmd(const char *table, const ColumnArray &attrs);

		/**���¼�¼��SQL���
	* @param table �����µı�
	* @param attr ����������֣����Ǹ���������Ŀǰֻ֧�� = 
	* @param obj ����Դ
    * @return �ɹ�����SQL��䣬���tableΪ�գ�objΪ�գ�attrΪ�գ�attr����obj�ϵ����ԣ����ؿմ�
	*/
		string	UpdateCmd(
					const char	*table,
					const CFtdData	*obj,
					const char	*attr);

		/**���¼�¼��SQL���
	* @param table �����µı�
	* @param attrs ���Լ��ϣ����Ǹ���������Ŀǰֻ֧�� = 
	* @param obj ����Դ
    * @return �ɹ�����SQL��䣬���tableΪ�գ�objΪ�գ�attrsΪ�գ�attrs���в��Ϸ������ԣ����ؿմ�
	*/
		string	UpdateCmd(const char *table, const ColumnArray &attrs);

		/**���ұ����м�¼��SQL���
	* @param table �����ҵı�
    * @return �ɹ�����SQL��䣬���tableΪ��,���ؿմ�
	*/
		string	SearchAllCmd(const char *table);

		/**�����ض����Ե�MAX�ۼ�������SQL���
	* @param table �����ҵı�
	* @param attr ��������
    * @return �ɹ�����SQL��䣬���tableΪ��; attrΪ�գ����ؿմ�
	*/
		string	SearchMaxCmd(const char *table, const char *attr);

	/* */
	private:
		string	generateKey(const char *table, const ColumnArray &attrs);

	/* */
	private:
		typedef map<string, string> SQLSet;
		typedef SQLSet::const_iterator SQLSet_Iterator;
		typedef pair<string, string> SQLSet_value;

		SQLSet m_insertSql;
		SQLSet m_deleteSql;
		SQLSet m_updateSql;
		SQLSet m_searchSql;
};

/**SyncDBOperator�ṩ�˲������ݿ��ͬ��������
* ��ÿһ��������Ҫ�ȵ����ݿ������Ӧ������ŷ���
*/
class SyncDBOperator :
	public DBOperator
{
	class Timmer : public CEventHandler
	{
	public:
		Timmer(CReactor* pReactor, SyncDBOperator* pOperator)
			:
		CEventHandler(pReactor),
			m_dbOperator(pOperator)
		{
		}

		void SetTimer(int nIDEvent, int nElapse)
		{
			CEventHandler::SetTimer(nIDEvent, nElapse);
		}

		void KillTimer(int nIDEvent)
		{
			CEventHandler::KillTimer(nIDEvent);
		}

	private:
		void OnTimer(int nIDEvent)
		{
			if (m_dbOperator)
			{
				m_dbOperator->CheckDBConnect();
			}
		}

		SyncDBOperator *m_dbOperator;	// a reference, don't delete it
	};

	/* */
	public:
		SyncDBOperator(void)
		{
			m_bInConnect = false;
		}

		/** ����������������ݿ⻹�򿪣���ر����ݿ�
	*/
		~ SyncDBOperator(void);

		bool Open(
				const string &ip,
				const string &port,
				const string &dbName,
				const string &user,
				const string &pwd);

		/** ���û�е���Close��SyncDBOperator�������������йر����ݿ� 
	*/
		void Close(void);

		bool InsertRecord(
				const char	*table,
				const CFtdData	*obj,
				bool bLogout = true);

		bool DeleteRecord(
				const char	*table,
				const CFtdData	*obj = NULL,
				const char	*objAttr = NULL);

		bool DeleteRecord(
				const char	*table,
				const ColumnArray &recordValues,
				const ColumnArray &cmpValues);

		bool UpdateRecord(
				const char	*table,
				const CFtdData	*obj,
				const char	*objAttr);

		bool UpdateRecord(
				const char	*table,
				const ColumnArray &recordValues,
				const ColumnArray &cmpValues);

		bool SearchRecord(
				const string &sql,
				searchHander_t cb,
				void *cbData = NULL);

		bool SearchRecord(
				SACommand &cmd,
				searchHander_t cb,
				void *cbData = NULL);

		//bool SearchRecord(const string& sql, const ColumnArray& conditions, searchHander_t cb, void * cbData = NULL);
		//bool SearchRecord(const string& sql, const ColumnArray& recordValues, const ColumnArray& conditions,

		//    searchHander_t cb, void * cbData = NULL);
		SAConnection &GetConnetionDirt(void)
		{
			return m_sqlConnect;
		}

		void SetOperateMaster(string operate_master, CReactor* pReactor)
		{
			m_operate_master=operate_master;
			if (pReactor)
			{
				m_pTimer = new Timmer(pReactor, this);
				m_pTimer->SetTimer(1, 5*1000);				
			}
		}

		bool CheckDBConnect();
	/* */
	private:
		bool connectDB(void);
		bool isAlive(void);

		void prepare(void);
		bool executeAndCommit(void);

		void handleError(void);

		void setConditionValue(const ColumnArray &conditions);

		void setConditionValue(
				const ColumnArray &recordValues,
				const ColumnArray &conditions);

		bool searchRecordInternal(
				SACommand &cmd,
				searchHander_t cb,
				void *cbData);

		class DBInfo
		{
		public:
			DBInfo()
			{
			}

			~DBInfo()
			{
			}

			void Init(
			const string &ip,
			const string &port,
			const string &dbName,
			const string &user,
			const string &pwd)
			{
				m_ip = ip;
				m_port = port;
				m_dbName = dbName;
				m_user = user;
				m_pwd = pwd;
			}

			string Uri(void) const
			{
				return m_ip + ":" + m_port + "/" + m_dbName;
			}

			string User(void) const
			{
				return m_user;
			}

			string Pwd(void) const
			{
				return m_pwd;
			}

		private:
			// ���ݿ������Ϣ
			string m_ip;
			string m_port;
			string m_dbName;
			string m_user;
			string m_pwd;
		};

	/* */
	private:
		DBInfo m_dbinfo;
		SAConnection m_sqlConnect;
		SACommand m_cmd;
		SqlGenerator m_sql;
		string m_operate_master;
		bool	m_bInConnect;
		static CIntMonitorIndex* m_pDBAccessIndex;
		Timmer* m_pTimer;
};

inline void SyncDBOperator::prepare(void)
{
	if (!isAlive() && !connectDB())
	{
		throw SAException(
				SA_UserGenerated_Error,
				0,
				0,
				"Can't not connect server");
	}

	m_cmd.DestroyParams();
}

/**AsyncDBOperator�ṩ�˲������ݿ���첽������
* ��ÿһ���������������أ�������ݿ�Ĳ�����������һ���߳���ִ�С�
*/
class AsyncDBOperator :
	public DBOperator
{
	/* */
	public:
		AsyncDBOperator(int maxTask = 8);
		~ AsyncDBOperator(void);

		bool Open(
				const string &ip,
				const string &port,
				const string &dbName,
				const string &user,
				const string &pwd);

		void Close(void);

		bool InsertRecord(
				const char	*table,
				const CFtdData	*obj,
				bool bLogout = true);

		bool DeleteRecord(
				const char	*table,
				const CFtdData	*obj = NULL,
				const char	*objAttr = NULL);

		bool DeleteRecord(
				const char	*table,
				const ColumnArray &recordValues,
				const ColumnArray &cmpValues);

		bool UpdateRecord(
				const char	*table,
				const CFtdData	*obj,
				const char	*objAttr);

		bool UpdateRecord(
				const char	*table,
				const ColumnArray &recordValues,
				const ColumnArray &cmpValues);

		bool SearchRecord(
				const string &sql,
				searchHander_t cb,
				void *cbData = NULL);

		bool SearchRecord(
				SACommand &cmd,
				searchHander_t cb,
				void *cbData = NULL);

	/* */
	private:
		enum Oper_type
		{
			OT_OPEN,
			OT_CLOSE,
			OT_INSERT,
			OT_DELETE,
			OT_UPDATE,
			OT_SEARCH
		};

		class AsyncTask : public Runnable
		{
		public:
			AsyncTask()
			{
			}

			~AsyncTask()
			{
			}

			void Run(void);

			struct OpenData
			{
				OpenData()
				{
				}

				void clear(void)
				{
					ip = "";
					port = "";
					dbname = "";
					user = "";
					pwd = "";
				}

				string ip;
				string port;
				string dbname;
				string user;
				string pwd;
			} m_openData;

			struct InsertData
			{
				InsertData()
				{
				}

				void clear(void)
				{
					sql = "";
					obj = NULL;
				}

				string sql;
				CFtdData *obj;
			} m_insertData;

			struct DeleteData
			{
				DeleteData()
				{
				}

				void clear(void)
				{
					sql = "";
					obj = NULL;
					objAttr = "";
				}

				string sql;
				CFtdData *obj;
				string objAttr;
			} m_deleteData;

			struct UpdateData
			{
				UpdateData()
				{
				}

				void clear(void)
				{
					sql = "";
					obj = NULL;
					objAttr = "";
					comparedObj = NULL;
					comparedObjAttr = "";
				}

				string sql; // TODO change to be table
				CFtdData *obj;
				string objAttr;
				CFtdData *comparedObj;
				string comparedObjAttr;
			} m_updateData;

			struct SearchData
			{
				SearchData()
				{
				}

				void clear(void)
				{
					sql = "";
					cb = NULL;
					cbData = NULL;
				}

				string sql;
				searchHander_t cb;
				void *cbData;
			} m_searchData;

			Oper_type m_operType;
			SyncDBOperator m_oper;
			CMutex m_mutex;
		private: DISALLOW_COPY_AND_ASSIGN(AsyncTask);
		};

		AsyncTask *getTask(void);

	/* */
	private:
		typedef std::vector<AsyncTask *> TaskContainer;
		TaskContainer m_tasks;

		int m_index;
		int m_maxTask;

		//static ThreadPool m_threadPool;
};
#endif // __DB_OPERATOR_H
