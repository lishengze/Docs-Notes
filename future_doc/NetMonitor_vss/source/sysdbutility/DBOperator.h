/////////////////////////////////////////////////////////////////////////
///@system 网络监控系统
///@company 上海期货信息技术有限公司
///@file DBOperator.h
///@brief 数据库操作类
///@history
///20110531	李志伟   创建该文件
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

/**DBOperator 数据库操作接口，处理包含与CFtdData对象相关的表的操作，实现增、删、改、查四种操作。
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

		/**打开数据库，建立连接
	* @param ip 数据库的地址
	* @param port 端口号
    * @param dbName 数据库名
    * @param user 用户名
    * @param pwd 密码
    * @return 成功打开返回true, 失败返回false
	*/
		virtual bool Open(
						const string &ip,
						const string &port,
						const string &dbName,
						const string &user,
						const string &pwd) = 0;

		/**关闭数据库。
	*/
		virtual void Close(void) = 0;

		/**插入一条记录，将obj上所有属性的值作为一条记录插入至相应的表中
	* @param sql 插入记录的sql语句，
	* @param obj 数据源
    * @return 成功返回true, sql为空；obj无效；插入失败；返回false
	*/
		virtual bool InsertRecord(
						const char	*table,
						const CFtdData	*obj,
						bool bLogout = true) = 0;

		/** Column是对CFtdData对象上特定属性的抽象，为数据库操作提供。
    * @param obj CFtdData对象
    * @param attrName 属性的名字
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

		/**删除记录，删除的条件是找到与obj的attr属性相同值的记录
	* @param table 删除记录的表名
    * @param obj 数据源，如果其为空，则是删除表中所有记录
    * @param objAttr 数据源的属性，更新条件的一部分，如果其为空，则是删除表中所有记录
    * @return 成功返回true, sql为空；删除失败；返回false
	*/
		virtual bool DeleteRecord(
						const char	*table,
						const CFtdData	*obj = NULL,
						const char	*objAttr = NULL) = 0;

		/**删除记录，删除的条件为记录中recordValues所指定的值与cmpValues相等。
	* @param table 删除记录的表名
    * @param recordValues 删除条件中记录的属性名字。如果recordValues中有多个属性，这些属性的相等关系为 && (且)。
    * @param cmpValues 删除条件中记录属性所要比较的值(只支持相等关系)。
    *                       注意：cmpValues的值与recordValues的值相对应。
    * @return 成功返回true, sql为空；删除失败；返回false
	*/
		virtual bool DeleteRecord(
						const char	*table,
						const ColumnArray &recordValues,
						const ColumnArray &cmpValues) = 0;

		/**用CFtdData对象来更新相应的表，对象的所有属性的值都将更新至数据库
	* @param sql 更新记录的sql语句
	* @param obj 数据源
    * @param objAttr 更新的条件，即记录的objAttr与obj的objAttr值相等的记录将会被更新为obj的值。
    * @return 成功返回true, sql为空；obj为空；objAttr为空；更新失败；返回false
	*/
		virtual bool UpdateRecord(
						const char	*table,
						const CFtdData	*obj,
						const char	*objAttr) = 0;

		/**更新记录，更新的条件为记录中recordValues所指定的值与cmpValues相等。
	* @param table 更新记录的表
    * @param obj 数据源，更新时会将数据源的所有属性都更新至记录。
    * @param recordValues 更新条件中记录的属性名字。如果recordValues中有多个属性，这些属性的相等关系为 && (且)。
    * @param cmpValues 更新条件中记录属性所要比较的值(只支持相等关系)。
    *                       注意：cmpValues的值与recordValues的值相对应。
    * @return 成功返回true, sql为空；更新失败；返回false
	*/
		virtual bool UpdateRecord(
						const char	*table,
						const ColumnArray &recordValues,
						const ColumnArray &cmpValues) = 0;

		/**查找表，找到记录后，对每条记录均调用DBOperatorCallback的HandleSearchResult方法。
    * 此方法主要针对不带比较条件SQL语句，带比较的SQL语句可参考下一个方法
	* @param sql 查找记录的sql语句，其中不带比较参数。
	* @param cb  查找记录的同步回调，在每次查找到结果时，该回调就会被触发
	* @param cbData 查找记录的同步回调所需要的数据，可以为NULL。
    * @return 成功返回true, sql为空；cb为空；查询失败；返回false
	*/
		typedef void (*searchHander_t) (SACommand &records, void *data);
		virtual bool SearchRecord(
						const string &sql,
						searchHander_t cb,
						void *cbData = NULL) = 0;

		/**查找表，找到记录后，对每条记录均调用DBOperatorCallback的HandleSearchResult方法。
    * 此方法针对带比较条件的SQL语句，并且条件值由调用者设置好再传入执行
	* @param cmd 已经设置好sql语句，并且设定好参数值的SACommand
	* @param cb  查找记录的同步回调，在每次查找到结果时，该回调就会被触发
	* @param cbData 查找记录的同步回调所需要的数据，可以为NULL。
    * @return 成功返回true, sql为空；cb为空；查询失败；返回false
	*/
		bool SearchRecord(
				SACommand &cmd,
				searchHander_t cb,
				void *cbData = NULL);

		///** 根据指定的SQL语句来操作数据库。sql语句的条件部分，通过数字来指示。
		//   * 比如 select * from table where AA = :1 order by AA
		//* @param sql 特定的sql语句
		//* @param conditions sql语句中需要填充的条件域，其个数要与sql语句中:number 的个数一致。
		//   * @return 成功返回true, sql为空；操作失败；返回false
		//*/
		//   virtual bool SearchRecord(const string& sql, const ColumnArray& conditions,
		//       searchHander_t cb, void * cbData = NULL) = 0;
		
			///** 根据指定的SQL语句来操作数据库，sql语句的条件部分，通过名字来指示。
		//   * 比如 select * from table where AA = :AA order by AA
		//* @param sql 特定的sql语句
		//* @param recordValues sql语句中:name的名字集合。
		//* @param conditions sql语句中需要填充的条件域，其个数要与sql语句中:name 的个数一致。
		//   * @return 成功返回true, sql为空；操作失败；返回false
		//*/
		//   virtual bool SearchRecord(const string& sql, const ColumnArray& recordValues, const ColumnArray& conditions,

	//       searchHander_t cb, void * cbData = NULL) = 0;
	private:
		DISALLOW_COPY_AND_ASSIGN(DBOperator);
};

/**SqlGenerator是一个SQL语句生成器，可以根据CFtdData对象生成与对象属性相关的SQL语句
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

		/**插入记录的SQL语句
	* @param table 被插入的表
	* @param obj 数据源
    * @return 返回生产的SQL语句，如果table为空；obj为空，或者obj中没有属性，返回空串
	*/
		string	InsertCmd(const char *table, const CFtdData *obj);

		/**删除记录的SQL语句
	* @param table 被插入的表
	* @param attr 表的属性名字，其是删除条件，目前只支持 =，如果其为空，则是删除表中所有记录
    * @return 成功返回SQL语句，如果table为空，返回空串
	*/
		//string DeleteCmd(const char * table, const char * attr = NULL);
		string	DeleteCmd(const char *table, const ColumnArray &attrs);

		/**更新记录的SQL语句
	* @param table 被更新的表
	* @param attr 表的属性名字，其是更新条件，目前只支持 = 
	* @param obj 数据源
    * @return 成功返回SQL语句，如果table为空；obj为空；attr为空；attr不是obj上的属性，返回空串
	*/
		string	UpdateCmd(
					const char	*table,
					const CFtdData	*obj,
					const char	*attr);

		/**更新记录的SQL语句
	* @param table 被更新的表
	* @param attrs 属性集合，其是更新条件，目前只支持 = 
	* @param obj 数据源
    * @return 成功返回SQL语句，如果table为空；obj为空；attrs为空；attrs中有不合法的属性，返回空串
	*/
		string	UpdateCmd(const char *table, const ColumnArray &attrs);

		/**查找表所有记录的SQL语句
	* @param table 被查找的表
    * @return 成功返回SQL语句，如果table为空,返回空串
	*/
		string	SearchAllCmd(const char *table);

		/**查找特定属性的MAX聚集方法的SQL语句
	* @param table 被查找的表
	* @param attr 属性名字
    * @return 成功返回SQL语句，如果table为空; attr为空，返回空串
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

/**SyncDBOperator提供了操作数据库的同步方法。
* 即每一个方法均要等到数据库完成相应操作后才返回
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

		/** 析构函数，如果数据库还打开，会关闭数据库
	*/
		~ SyncDBOperator(void);

		bool Open(
				const string &ip,
				const string &port,
				const string &dbName,
				const string &user,
				const string &pwd);

		/** 如果没有调用Close，SyncDBOperator会在析构函数中关闭数据库 
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
			// 数据库相关信息
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

/**AsyncDBOperator提供了操作数据库的异步方法。
* 即每一个方法会立即返回，其多数据库的操作将会在另一个线程中执行。
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
