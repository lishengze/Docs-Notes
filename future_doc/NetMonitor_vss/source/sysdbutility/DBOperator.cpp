#include "DBOperator.h"
#include "monitorIndex.h"
#include <FieldDescribe.h>
#include <ScopedLock.h>


CIntMonitorIndex* SyncDBOperator::m_pDBAccessIndex = new CIntMonitorIndex("DBConnectCounter", 10);
SyncDBOperator::~SyncDBOperator(void)
{
	if (m_pDBAccessIndex)
	{
		delete m_pDBAccessIndex;
		m_pDBAccessIndex = NULL;
	}
	Close();
}

bool SyncDBOperator::Open(
	const string &ip,
	const string &port,
	const string &dbName,
	const string &user,
	const string &pwd)
{
	m_dbinfo.Init(ip, port, dbName, user, pwd);

	return connectDB();
}

void SyncDBOperator::Close(void)
{
	try
	{
		if (m_sqlConnect.isConnected())
		{
			m_sqlConnect.Disconnect();

			REPORT_EVENT(5, "DBDisconnect", "Operator='%s',Param='%s'", m_operate_master.c_str(),m_dbinfo.Uri().c_str());
			// 连接状态为断开
			if (m_bInConnect)
			{
				m_pDBAccessIndex->incValue(-1);
				m_bInConnect = false;			
			}
		}
	}

	catch(SAException & ex)
	{
		handleError();
		LOG_ERROR("Disconnect DB failed: (%s)\n", (const char *)ex.ErrText());
	}
}

bool SyncDBOperator::InsertRecord(
	const char	*table,
	const CFtdData	*obj,
	bool bLogout)
{
	assert(table && obj);

	bool rtn = true;

	string	sql = m_sql.InsertCmd(table, obj);
	try
	{
		if (bLogout)
		{
			LOG_INFO("SQL(%s) \n", sql.c_str());
		}

		prepare();

		m_cmd.setCommandText(sql.c_str());

		obj->ToDBRecord(m_cmd);

		m_cmd.Execute();
	}

	catch(SAException & ex)
	{
		handleError();
		LOG_ERROR(
			"sql (%s) raise exception: (%s)\n",
			sql.c_str(),
			(const char *)ex.ErrText());
		REPORT_EVENT(5, "DBInsertFail", "Operator='%s',Param='%s',Info='%s'", m_operate_master.c_str(),m_dbinfo.Uri().c_str(),(const char *)ex.ErrText());
		rtn = false;
	}

	return rtn;
}

bool SyncDBOperator::DeleteRecord(
	const char	*table,
	const CFtdData	*obj,
	const char	*objAttr)
{
	assert(table);

	if (obj && !objAttr || !obj && objAttr)
	{
		assert(false && "obj and objAttr should all contains value");
		return false;
	}

	ColumnArray cmpValues;
	if (obj && objAttr)
	{
		cmpValues.push_back(Column(obj, objAttr));
	}

	return DeleteRecord(table, cmpValues, cmpValues);
}

bool SyncDBOperator::DeleteRecord(
	const char	*table,
	const ColumnArray &recordValues,
	const ColumnArray &cmpValues)
{
	assert(table);

	bool rtn = true;

	string	sql = m_sql.DeleteCmd(table, recordValues);
	try
	{
		LOG_INFO("SQL(%s) \n", sql.c_str());

		prepare();

		m_cmd.setCommandText(sql.c_str());

		setConditionValue(recordValues, cmpValues);

		m_cmd.Execute();
	}

	catch(SAException & ex)
	{
		handleError();
		LOG_ERROR(
			"sql (%s) raise exception: (%s)\n",
			sql.c_str(),
			(const char *)ex.ErrText());
		REPORT_EVENT(5, "DBDeleteFail", "Operator='%s',Param='%s',Info='%s'", m_operate_master.c_str(),m_dbinfo.Uri().c_str(),(const char *)ex.ErrText());		
		rtn = false;
	}

	return rtn;
}

bool SyncDBOperator::UpdateRecord(
	const char	*table,
	const CFtdData	*obj,
	const char	*objAttr)
{
	assert(table && obj && objAttr);

	ColumnArray cmpValues;
	cmpValues.push_back(Column(obj, objAttr));

	return UpdateRecord(table, cmpValues, cmpValues);
}

bool SyncDBOperator::UpdateRecord(
	const char	*table,
	const ColumnArray &recordValues,
	const ColumnArray &cmpValues)
{
	assert(table && recordValues.size());

	bool rtn = true;

	string	sql = m_sql.UpdateCmd(table, recordValues);
	try
	{
		LOG_INFO("SQL(%s) \n", sql.c_str());

		prepare();

		const CFtdData	*obj = recordValues[0].obj;

		m_cmd.setCommandText(sql.c_str());

		obj->ToDBRecord(m_cmd);

		setConditionValue(recordValues, cmpValues);

		m_cmd.Execute();
	}

	catch(SAException & ex)
	{
		handleError();
		LOG_ERROR(
			"sql (%s) raise exception: (%s)\n",
			sql.c_str(),
			(const char *)ex.ErrText());
		REPORT_EVENT(5, "DBUpdateFail", "Operator='%s',Param='%s',Info='%s'", m_operate_master.c_str(),m_dbinfo.Uri().c_str(),(const char *)ex.ErrText());
		rtn = false;
	}

	return rtn;
}

bool SyncDBOperator::SearchRecord(
	const string &sql,
	searchHander_t	cb,
	void *cbData)
{
	if (sql.empty() || !cb)
	{
		return false;
	}

	bool rtn = true;

	try
	{
		LOG_INFO("SQL(%s) \n", sql.c_str());

		m_cmd.setCommandText(sql.c_str());

		searchRecordInternal(m_cmd, cb, cbData);
	}

	catch(SAException & ex)
	{
		handleError();
		LOG_ERROR(
			"sql (%s) raise exception: (%s)\n",
			sql.c_str(),
			(const char *)ex.ErrText());
		REPORT_EVENT(5, "DBSearchFail", "Operator='%s',Param='%s',Info='%s'", m_operate_master.c_str(),m_dbinfo.Uri().c_str(),(const char *)ex.ErrText());
		rtn = false;
	}

	return rtn;
}

bool SyncDBOperator::SearchRecord(
	SACommand &cmd,
	searchHander_t	cb,
	void *cbData)
{
	if (!cb)
	{
		return false;
	}

	bool rtn = true;
	try
	{
		cmd.setConnection(&m_sqlConnect);

		searchRecordInternal(cmd, cb, cbData);
	}

	catch(SAException & ex)
	{
		handleError();
		LOG_ERROR(
			"SearchRecord raise exception: (%s)\n",
			(const char *)ex.ErrText());
		REPORT_EVENT(5, "DBSearchFail", "Operator='%s',Param='%s',Info='%s'", m_operate_master.c_str(),m_dbinfo.Uri().c_str(),(const char *)ex.ErrText());
		rtn = false;
	}

	return rtn;
}

bool SyncDBOperator::searchRecordInternal(
	SACommand &cmd,
	searchHander_t	cb,
	void *cbData)
{
	bool rtn = true;
	try
	{
		prepare();

		static SAString sBulkSize("100");
		cmd.setOption("PreFetchRows") = sBulkSize;

		cmd.Execute();

		while (cmd.FetchNext())
		{
			assert(cb);
			cb(cmd, cbData);
		}
	}

	catch(SAException & ex)
	{
		handleError();
		LOG_ERROR(
			"SearchRecord raise exception: (%s)\n",
			(const char *)ex.ErrText());
		REPORT_EVENT(5, "DBSearchFail", "Operator='%s',Param='%s',Info='%s'", m_operate_master.c_str(),m_dbinfo.Uri().c_str(),(const char *)ex.ErrText());

		rtn = false;
	}

	return rtn;
}

//bool SyncDBOperator::SearchRecord(const string& sql, const ColumnArray& conditions,
//                                  searchHander_t cb, void * cbData)
//{
//    if (sql.empty())
//        return false;
//
//    bool rtn = true;
//
//    try {
//        prepare();
//
//        m_cmd.setCommandText(sql.c_str());
//
//        setConditionValue(conditions);
//
//        m_cmd.Execute();
//    }
//    catch (SAException& ex) {
//        handleError();
//        LOG_ERROR("sql (%s) raise exception: (%s)\n", sql.c_str(), (const char*)ex.ErrText());
//        rtn = false;
//    }
//
//    return rtn;
//}
//
//bool SyncDBOperator::SearchRecord(const string& sql, const ColumnArray& recordValues, const ColumnArray& conditions,
//                                  searchHander_t cb, void * cbData)
//{
//    if (sql.empty())
//        return false;
//
//    bool rtn = true;
//
//    try {
//        prepare();
//
//        m_cmd.setCommandText(sql.c_str());
//
//        setConditionValue(recordValues, conditions);
//
//        m_cmd.Execute();
//    }
//    catch (SAException& ex) {
//        handleError();
//        LOG_ERROR("sql (%s) raise exception: (%s)\n", sql.c_str(), (const char*)ex.ErrText());
//
//        rtn = false;
//    }
//
//    return rtn;

//}
bool SyncDBOperator::connectDB(void)
{
	bool rtn = true;

	try
	{
		m_sqlConnect.Connect(
				m_dbinfo.Uri().c_str(),
				m_dbinfo.User().c_str(),
				m_dbinfo.Pwd().c_str(),
				SA_Oracle_Client);

		m_cmd.setConnection(&m_sqlConnect);

		m_sqlConnect.setAutoCommit(SA_AutoCommitOn);

		LOG_INFO(
			"Connect DB string: uri(%s) user(%s) pwd(%s)\n",
			m_dbinfo.Uri().c_str(),
			m_dbinfo.User().c_str(),
			m_dbinfo.Pwd().c_str());

		// 连接成功后
		REPORT_EVENT(5, "DBConnect", "Operator='%s',Param='%s'", m_operate_master.c_str(),m_dbinfo.Uri().c_str());
		m_bInConnect = true;
		// 连接状态为正常
		m_pDBAccessIndex->incValue();
	}

	catch(SAException & ex)
	{
		handleError();
		LOG_ERROR("connectDB failed: %s\n", (const char *)ex.ErrText());

		// 连接失败后给予事件
		REPORT_EVENT(5, "DBConnectFail", "Operator:'%s',Param:'%s'", m_operate_master.c_str(),m_dbinfo.Uri().c_str());

		rtn = false;
	}

	return rtn;
}

bool SyncDBOperator::isAlive(void)
{
	if (!m_sqlConnect.isConnected())
	{
		// 连接异常发生时
		REPORT_EVENT(5, "DBConnectLost", "Operator='%s',Param='%s' ", m_operate_master.c_str(),m_dbinfo.Uri().c_str());
		// 连接状态为断开
		if (m_bInConnect)
		{
			m_pDBAccessIndex->incValue(-1);
			m_bInConnect = false;			
		}
		return false;
	}

	try
	{
		// 太耗时，注销掉。占单次数据库操作时间的4/5
		//SACommand cmd(&m_sqlConnect, "select distinct 1 from user_tables");
		//cmd.Execute();
	}

	catch(SAException & ex)
	{
		handleError();

		time_t	now;
		char tmpTime[10];
		struct tm tm_time;
		time(&now);
		LocalTime(&now, &tm_time);
		strftime(tmpTime, 10, "%H:%M:%S", &tm_time);

		LOG_ERROR(
			"%s :Error arise when select test data from DB : %s\n",
			tmpTime,
			(const char *)ex.ErrText());
		return false;
	}

	return true;
}

void SyncDBOperator::handleError(void)
{
	try
	{
		m_sqlConnect.Rollback();
	}

	catch(SAException & x)
	{
		printf("Rollback failed: %s\n", (const char *)x.ErrText());
	}
}

void SyncDBOperator::setConditionValue(const ColumnArray &conditions)
{
	for (ColumnArray::const_iterator it = conditions.begin();
		 it != conditions.end();
		 it++)
	{
		const CFtdData	*obj = it->obj;
		const char	*name = it->attrName.c_str();

		CFieldDescribe	*objDescr = obj->Descr();
		int n = objDescr->GetMemberCount();
		for (int i = 0; i < n; i++)
		{
			if (strcmp(objDescr->GetMemberDesc(i)->szName, name) == 0)
			{
				char *pMem = (char *)obj->Obj() +
					objDescr->GetMemberDesc(i)->nStructOffset;

				switch (objDescr->GetMemberDesc(i)->nType)
				{
					case FT_BYTE:
						{
							int size = objDescr->GetMemberDesc(i)->nSize;
							if (size == 1)
							{
								char buf[2];
								buf[0] = *pMem;
								buf[1] = '\0';
								m_cmd << buf;
							}
							else
							{
								m_cmd << (const char *)pMem;
							}

							break;
						}

					case FT_WORD:
						{
							m_cmd << (short)(*(WORD *)pMem);
							break;
						}

					case FT_DWORD:
						{
							m_cmd << (long)(*(DWORD *)pMem);
							break;
						}

					case FT_REAL4:
						{
							// 目前的sqlapi库中并无 SACommand &operator << (float Value) 符号，故最终转成double处理
							m_cmd << (double)(*(float *)pMem);
							break;
						}

					case FT_REAL8:
						{
							m_cmd << *((double *)pMem);
							break;
						}

					default:
						assert(false && "Invaild data type!");
						break;
				}
			}
		}
	}
}

void SyncDBOperator::setConditionValue(
	const ColumnArray &recordValues,
	const ColumnArray &conditions)
{
	assert(recordValues.size() == conditions.size());

	int n = recordValues.size();
	for (int i = 0; i < n; i++)
	{
		const char	*objAttr = recordValues[i].attrName.c_str();

		const CFtdData	*obj = conditions[i].obj;
		const char	*name = conditions[i].attrName.c_str();

		CFieldDescribe	*objDescr = obj->Descr();

		int m = objDescr->GetMemberCount();
		for (int j = 0; j < m; j++)
		{
			if (strcmp(objDescr->GetMemberDesc(j)->szName, name) == 0)
			{
				char *pMem = (char *)obj->Obj() +
					objDescr->GetMemberDesc(j)->nStructOffset;

				// TODO check whether the type is equal
				switch (objDescr->GetMemberDesc(j)->nType)
				{
					case FT_BYTE:
						{
							int size = objDescr->GetMemberDesc(j)->nSize;
							if (size == 1)
							{
								m_cmd.Param(objAttr).setAsString() = *pMem;
							}
							else
							{
								m_cmd.Param(objAttr).setAsString() = (const char *)pMem;
							}

							break;
						}

					case FT_WORD:
						{
							m_cmd.Param(objAttr).setAsShort() = *((WORD *)pMem);
							break;
						}

					case FT_DWORD:
						{
							m_cmd.Param(objAttr).setAsLong() = *((DWORD *)pMem);
							break;
						}

					case FT_REAL4:
						{
							m_cmd.Param(objAttr).setAsDouble() = *((float *)pMem);
							break;
						}

					case FT_REAL8:
						{
							m_cmd.Param(objAttr).setAsDouble() = *((double *)pMem);
							break;
						}

					default:
						assert(false && "Invaild data type!");
				}
			}
		}
	}
}

bool SyncDBOperator::CheckDBConnect()
{
	try
	{
		// 太耗时，注销掉。占单次数据库操作时间的4/5
		SACommand cmd(&m_sqlConnect, "select * from dual");
		cmd.Execute();
	}

	catch(SAException & ex)
	{
		handleError();

		time_t	now;
		char tmpTime[10];
		struct tm tm_time;
		time(&now);
		LocalTime(&now, &tm_time);
		strftime(tmpTime, 10, "%H:%M:%S", &tm_time);

		LOG_ERROR(
			"%s :Error arise when select test data from DB : %s\n",
			tmpTime,
			(const char *)ex.ErrText());
		REPORT_EVENT(5, "DBTimerConnectLost", "Operator='%s',Param='%s',Info='%s'", m_operate_master.c_str(), m_dbinfo.Uri().c_str(),(const char *)ex.ErrText());
		if (m_bInConnect)
		{
			m_pDBAccessIndex->incValue(-1);
			m_bInConnect = false;
		}
		return false;
	}
}

////
// AsyncDBOperator
////

//ThreadPool AsyncDBOperator::m_threadPool(4);  // ThreadPool初始化时可能会有死锁问题，待改进
AsyncDBOperator::AsyncDBOperator(int maxTask) :
	m_index(0),
	m_maxTask(maxTask)
{
	assert(m_maxTask > 0);

	for (int i = 0; i < m_maxTask; i++)
	{
		m_tasks.push_back(new AsyncTask());
	}
}

AsyncDBOperator::~AsyncDBOperator(void)
{
	//m_threadPool.StopAndCleanAll();
	for (TaskContainer::iterator it = m_tasks.begin();
		 it != m_tasks.end();
		 it++)
	{
		delete *it;
	}

	m_tasks.clear();
}

bool AsyncDBOperator::Open(
	const string &ip,
	const string &port,
	const string &dbName,
	const string &user,
	const string &pwd)
{
	AsyncTask *task = getTask();

	ScopeLock<CMutex> lock(task->m_mutex);

	task->m_openData.ip = ip;
	task->m_openData.port = port;
	task->m_openData.dbname = dbName;
	task->m_openData.user = user;
	task->m_openData.pwd = pwd;
	task->m_operType = OT_OPEN;

	//m_threadPool.RunWithoutThrow(*task);
	return true;
}

void AsyncDBOperator::Close(void)
{
	AsyncTask *task = getTask();

	ScopeLock<CMutex> lock(task->m_mutex);

	task->m_operType = OT_CLOSE;

	//m_threadPool.RunWithoutThrow(*task);
}

bool AsyncDBOperator::InsertRecord(
	const char	*table,
	const CFtdData	*obj,
	bool bLogout)
{
	AsyncTask *task = getTask();

	ScopeLock<CMutex> lock(task->m_mutex);

	task->m_insertData.sql = table;
	task->m_insertData.obj = (CFtdData *)obj;
	task->m_operType = OT_INSERT;

	//m_threadPool.RunWithoutThrow(*task);
	return true;
}

bool AsyncDBOperator::DeleteRecord(
	const char	*table,
	const CFtdData	*obj,
	const char	*objAttr)
{
	AsyncTask *task = getTask();

	ScopeLock<CMutex> lock(task->m_mutex);

	task->m_deleteData.sql = table;
	task->m_deleteData.obj = (CFtdData *)obj;
	task->m_deleteData.objAttr = objAttr ? objAttr : "";
	task->m_operType = OT_DELETE;

	//m_threadPool.RunWithoutThrow(*task);
	return true;
}

bool AsyncDBOperator::DeleteRecord(
	const char	*table,
	const ColumnArray &recordValues,
	const ColumnArray &cmpValues)
{
	return false;
}

bool AsyncDBOperator::UpdateRecord(
	const char	*table,
	const CFtdData	*obj,
	const char	*objAttr)
{
	AsyncTask *task = getTask();

	ScopeLock<CMutex> lock(task->m_mutex);

	task->m_updateData.sql = table;
	task->m_updateData.obj = (CFtdData *)obj;
	task->m_updateData.objAttr = objAttr ? objAttr : "";
	task->m_operType = OT_UPDATE;

	//m_threadPool.RunWithoutThrow(*task);
	return true;
}

bool AsyncDBOperator::UpdateRecord(
	const char	*table,
	const ColumnArray &recordValues,
	const ColumnArray &cmpValues)
{
	return false;
}

bool AsyncDBOperator::SearchRecord(
	const string &sql,
	searchHander_t	cb,
	void *cbData)
{
	AsyncTask *task = getTask();

	ScopeLock<CMutex> lock(task->m_mutex);

	task->m_searchData.sql = sql;
	task->m_searchData.cb = cb;
	task->m_searchData.cbData = cbData;

	task->m_operType = OT_SEARCH;

	//m_threadPool.RunWithoutThrow(*task);
	return true;
}

bool AsyncDBOperator::SearchRecord(
	SACommand &cmd,
	searchHander_t	cb,
	void *cbData)
{
	return false;
}

AsyncDBOperator::AsyncTask * AsyncDBOperator::getTask()
{
	m_index = (++m_index) % m_maxTask;
	return m_tasks[m_index];
}

////

// AsyncTasks
////
void AsyncDBOperator::AsyncTask::Run(void)
{
	ScopeLock<CMutex> lock(m_mutex);

	switch (m_operType)
	{
		case OT_OPEN:
			m_oper.Open(
					m_openData.ip,
					m_openData.port,
					m_openData.dbname,
					m_openData.user,
					m_openData.pwd);
			m_openData.clear();
			break;
		case OT_CLOSE:
			m_oper.Close();
			break;
		case OT_INSERT:
			m_oper.InsertRecord(m_insertData.sql.c_str(), m_insertData.obj);
			m_insertData.clear();
			break;
		case OT_DELETE:
			m_oper.DeleteRecord(
					m_deleteData.sql.c_str(),
					m_deleteData.obj,
					m_deleteData.objAttr.c_str());
			m_deleteData.clear();
			break;
		case OT_UPDATE:
			m_oper.UpdateRecord(
					m_updateData.sql.c_str(),
					m_updateData.obj,
					m_updateData.objAttr.c_str());
			m_updateData.clear();
			break;
		case OT_SEARCH:
			m_oper.SearchRecord(
					m_searchData.sql,
					m_searchData.cb,
					m_searchData.cbData);
			m_searchData.clear();
			break;
		default:
			assert(false && "You should be there, check type");
	}

	return;
}

////

// SqlGenerator
////
static string wrapName(const char *name)
{
	string	wrapped;
	wrapped += "\"";
	wrapped += name;
	wrapped += "\"";

	return wrapped;
}

static string wrapParam(const char *name)
{
	string	wrapped;
	wrapped += ":";
	wrapped += name;

	return wrapped;
}

string SqlGenerator::generateKey(const char *table, const ColumnArray &attrs)
{
	assert(table);

	string	key = table;

	for (ColumnArray::const_iterator it = attrs.begin();
		 it != attrs.end();
		 it++)
	{
		key += it->attrName;
	}

	return key;
}

string SqlGenerator::InsertCmd(const char *table, const CFtdData *obj)
{
	string	m_cmd = "";

	if (!table || !obj)
	{
		return m_cmd;
	}

	ColumnArray dummy;

	string	key = generateKey(table, dummy);

	SQLSet_Iterator it = m_insertSql.find(key);

	if (it != m_insertSql.end())
	{
		return it->second;
	}
	else
	{
		CFieldDescribe	*fieldDes = obj->Descr();
		int n = fieldDes->GetMemberCount();
		if (n == 0)
		{
			return m_cmd;
		}

		m_cmd += "insert into ";
		m_cmd += table;
		m_cmd += " (";

		// 括号与属性名之间不要加空格！如果加空格，使用sqlapi处理时，有时会出现阻塞在Execute的情况。
		int i;
		for (i = 0; i < n - 1; i++)
		{
			m_cmd += fieldDes->GetMemberDesc(i)->szName;
			m_cmd += " , ";
		}

		m_cmd += fieldDes->GetMemberDesc(i)->szName;
		m_cmd += ") values (";

		for (i = 0; i < n - 1; i++)
		{
			m_cmd += wrapParam(fieldDes->GetMemberDesc(i)->szName);
			m_cmd += " , ";
		}

		m_cmd += wrapParam(fieldDes->GetMemberDesc(i)->szName);
		m_cmd += ")";

		// 缓存生成的SQL语句
		m_insertSql.insert(SQLSet_value(key, m_cmd));
	}

	return m_cmd;
}

//string SqlGenerator::DeleteCmd(const char * table, const char * attr)
//{
//    ColumnArray attrs;
//    if (attr)
//        attrs.push_back(Column(NULL, attr));
//
//    return DeleteCmd(table, attrs);

//}
string SqlGenerator::DeleteCmd(const char *table, const ColumnArray &attrs)
{
	string	m_cmd = "";

	if (!table)
	{
		return m_cmd;
	}

	string	key = generateKey(table, attrs);
	SQLSet_Iterator it = m_deleteSql.find(key);

	if (it != m_deleteSql.end())
	{
		return it->second;
	}
	else
	{
		m_cmd = "delete from ";
		m_cmd += table;

		for (int i = 0, n = attrs.size(); i < n; i++)
		{
			if (i == 0)
			{
				m_cmd += " where ";
			}

			m_cmd += attrs[i].attrName.c_str();
			m_cmd += "=";
			m_cmd += wrapParam(attrs[i].attrName.c_str());

			if (i != n - 1)
			{
				m_cmd += " and ";
			}
		}

		// 缓存生成的SQL语句
		m_deleteSql.insert(SQLSet_value(key, m_cmd));
	}

	return m_cmd;
}

string SqlGenerator::UpdateCmd(
	const char	*table,
	const CFtdData	*obj,
	const char	*attr)
{
	string	m_cmd = "";

	if (!table || !attr || !obj)
	{
		return m_cmd;
	}

	ColumnArray array;
	array.push_back(Column(obj, attr));

	return UpdateCmd(table, array);
}

string SqlGenerator::UpdateCmd(const char *table, const ColumnArray &attrs)
{
	string	m_cmd = "";

	if (!table || !attrs.size())
	{
		return m_cmd;
	}

	string	key = generateKey(table, attrs);
	SQLSet_Iterator it = m_updateSql.find(key);

	if (it != m_updateSql.end())
	{
		return it->second;
	}
	else
	{
		const CFtdData	*obj = attrs[0].obj;
		CFieldDescribe	*fieldDes = obj->Descr();
		int n = fieldDes->GetMemberCount();
		if (n == 0)
		{
			return m_cmd;
		}

		bool validAttr = false;

		m_cmd += "update ";
		m_cmd += table;
		m_cmd += " set ";

		for (int i = 0; i < n; i++)
		{
			const char	*name = fieldDes->GetMemberDesc(i)->szName;

			m_cmd += name;
			m_cmd += "=";
			m_cmd += wrapParam(name);

			if (i != n - 1)
			{
				m_cmd += " , ";
			}
		}

		for (int j = 0, n = attrs.size(); j < n; j++)
		{
			if (j == 0)
			{
				m_cmd += " where ";
			}

			m_cmd += attrs[j].attrName;
			m_cmd += "=";
			m_cmd += wrapParam(attrs[j].attrName.c_str());

			if (j != n - 1)
			{
				m_cmd += " and ";
			}
		}

		// 缓存生成的SQL语句
		m_updateSql.insert(SQLSet_value(key, m_cmd));
	}

	return m_cmd;
}

string SqlGenerator::SearchAllCmd(const char *table)
{
	string	m_cmd = "";

	if (!table)
	{
		return m_cmd;
	}

	m_cmd += "select * from ";
	m_cmd += table;

	return m_cmd;
}

string SqlGenerator::SearchMaxCmd(const char *table, const char *attr)
{
	string	m_cmd = "";

	if (!table || !attr)
	{
		return m_cmd;
	}

	m_cmd += "select NVL(max(";
	m_cmd += attr;
	m_cmd += "), 0) from ";
	m_cmd += table;

	return m_cmd;
}
