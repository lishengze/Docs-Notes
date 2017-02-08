// myClient.cpp
//
//////////////////////////////////////////////////////////////////////

#include <SQLAPI.h>
#include "myClient.h"

#include <assert.h>
#include <stdlib.h>	// atoi
#include <string.h>	// strlen, memcpy

#include <myAPI.h>

#include "samisc.h"
#include "errmsg.h"

static void Check(MYSQL *mysql)
{
	assert(mysql);

	unsigned int nErr = g_myAPI.mysql_errno(mysql);
	if(nErr)
		throw SAException(
			SA_DBMS_API_Error,
			nErr,
			-1,
			"%s", g_myAPI.mysql_error(mysql));
}

//////////////////////////////////////////////////////////////////////
// ImyConnection Class
//////////////////////////////////////////////////////////////////////

class ImyConnection : public ISAConnection
{
	friend class ImyCursor;

	myConnectionHandles m_handles;

	enum {MaxLongPiece = (unsigned int)0x7FFFFFFF};

	static SADataType_t CnvtNativeToStd(
		enum enum_field_types type,
		unsigned int length,
		int &Prec,	// not taken from MySQL, but calculated in this function
		unsigned int decimals,
		unsigned int flags);

	static void CnvtInternalToNumeric(
		SANumeric &numeric,
		const char *sValue);

	static void CnvtInternalToDateTime(
		SADateTime &date_time,
		const char *sInternal);
	static int second(const char *sSecond);
	static int minute(const char *sMinute);
	static int shortHour(const char *sHour);
	static int longHour(const char *sHour);
	static int day(const char *sDay);
	static int month(const char *sMonth);
	static int longYear(const char *sYear);
	static int shortYear(const char *sYear);
	static void CnvtDateTimeToInternal(
		const SADateTime &date_time,
		SAString &sInternal);

protected:
	virtual ~ImyConnection();

public:
	ImyConnection(SAConnection *pSAConnection);

	virtual void InitializeClient();
	virtual void UnInitializeClient();

	virtual long GetClientVersion() const;
	virtual long GetServerVersion() const;
	virtual SAString GetServerVersionString() const;

	virtual bool IsConnected() const;
	virtual void Connect(
		const SAString &sDBString,
		const SAString &sUserID,
		const SAString &sPassword);
	virtual void Disconnect();

	virtual void setIsolationLevel(
		SAIsolationLevel_t eIsolationLevel);
	virtual void setAutoCommit(
		SAAutoCommit_t eAutoCommit);
	virtual void Commit();
	virtual void Rollback();

	virtual saAPI *NativeAPI() const;
	virtual saConnectionHandles *NativeHandles();

	virtual ISACursor *NewCursor(SACommand *m_pCommand);

	virtual void CnvtInternalToNumeric(
		SANumeric &numeric,
		const void *pInternal,
		int nInternalSize);

	virtual void CnvtInternalToDateTime(
		SADateTime &date_time,
		const void *pInternal,
		int nInternalSize);

	virtual void CnvtInternalToCursor(
		SACommand *pCursor,
		const void *pInternal);
};

/*static */
SADataType_t ImyConnection::CnvtNativeToStd(
	enum enum_field_types type,
	unsigned int length,
	int &Prec,	// not taken from MySQL, calculated in this function
	unsigned int decimals,
	unsigned int flags)
{
	SADataType_t eDataType;
	Prec = length;	// can be adjusted

	switch(type)
	{
	case FIELD_TYPE_TINY:	// TINYINT field
		eDataType = SA_dtShort;
		break;
	case FIELD_TYPE_SHORT:	// SMALLINT field
		eDataType = SA_dtShort;
		break;
	case FIELD_TYPE_LONG:	// INTEGER field
		eDataType = SA_dtLong;
		break;
	case FIELD_TYPE_INT24:	// MEDIUMINT field
		eDataType = SA_dtLong;
		break;
	case FIELD_TYPE_LONGLONG:	// BIGINT field
		eDataType = SA_dtNumeric;
		break;
	case FIELD_TYPE_DECIMAL:	// DECIMAL or NUMERIC field
		if(!(flags & UNSIGNED_FLAG))
			--Prec;	// space for '-' sign
		if(decimals == 0)
		{
			// check for exact type
			if(Prec < 5)
				eDataType = SA_dtShort;
			else if(Prec < 10)
				eDataType = SA_dtLong;
			else
				eDataType = SA_dtNumeric;
		}
		else
		{
			--Prec;	// space for '.'
			eDataType = SA_dtNumeric;
		}
		break;
	case FIELD_TYPE_FLOAT:	// FLOAT field
		eDataType = SA_dtDouble;
		break;
	case FIELD_TYPE_DOUBLE:	// DOUBLE or REAL field
		eDataType = SA_dtDouble;
		break;
	case FIELD_TYPE_TIMESTAMP:	// TIMESTAMP field
		eDataType = SA_dtDateTime;
		break;
	case FIELD_TYPE_DATE:	// DATE field
	case FIELD_TYPE_NEWDATE:
		eDataType = SA_dtDateTime;
		break;
	case FIELD_TYPE_TIME:	// TIME field
		eDataType = SA_dtDateTime;
		break;
	case FIELD_TYPE_DATETIME:	// DATETIME field
		eDataType = SA_dtDateTime;
		break;
	case FIELD_TYPE_YEAR:	// YEAR field
		eDataType = SA_dtShort;
		break;
	case FIELD_TYPE_STRING:	// String (CHAR or VARCHAR) field, also SET and ENUM
	case FIELD_TYPE_VAR_STRING:
		if(flags & BINARY_FLAG)
			eDataType = SA_dtBytes;
		else
			eDataType = SA_dtString;
		break;
	case FIELD_TYPE_TINY_BLOB:
	case FIELD_TYPE_MEDIUM_BLOB:
	case FIELD_TYPE_LONG_BLOB:
	case FIELD_TYPE_BLOB:	// BLOB or TEXT field (use max_length to determine the maximum length)
		if(flags & BINARY_FLAG)
			eDataType = SA_dtLongBinary;
		else
			eDataType = SA_dtLongChar;
		break;
	case FIELD_TYPE_SET:	// SET field
		eDataType = SA_dtString;
		break;
	case FIELD_TYPE_ENUM:	// ENUM field
		eDataType = SA_dtString;
		break;
	case FIELD_TYPE_NULL:	// NULL-type field
		eDataType = SA_dtString;
		break;

	default:
		assert(false);
		eDataType = SA_dtString;
	}

	return eDataType;
}

//////////////////////////////////////////////////////////////////////
// ImyConnection Construction/Destruction
//////////////////////////////////////////////////////////////////////

ImyConnection::ImyConnection(
	SAConnection *pSAConnection) : ISAConnection(pSAConnection)
{
}

ImyConnection::~ImyConnection()
{
}

//////////////////////////////////////////////////////////////////////
// ImyClient Class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ImyClient::ImyClient()
{

}

ImyClient::~ImyClient()
{

}

ISAConnection *ImyClient::QueryConnectionInterface(
	SAConnection *pSAConnection)
{
	return new ImyConnection(pSAConnection);
}

//////////////////////////////////////////////////////////////////////
// ImyCursor Class
//////////////////////////////////////////////////////////////////////

class ImyCursor : public ISACursor
{
	myCommandHandles	m_handles;

	// private handles
	MYSQL_ROW m_mysql_row;
	unsigned long *m_lengths;
	bool m_bResultSetCanBe;

	SAString	m_sOriginalStmst;
	bool		m_bOpened;

	void ConvertMySQLRowToFields();
	SAString MySQLEscapeString(const char *sFrom, int nLen);
	SAString MySQLEscapeString(const SAString &sValue);
	void BindBLob(SAParam &Param, SAString &sBoundStmt);
	void BindText(SAParam &Param, SAString &sBoundStmt);

public:
	ImyCursor(
		ImyConnection *pImyConnection,
		SACommand *pCommand);
	virtual ~ImyCursor();

protected:
	virtual bool IsOpened();
	virtual void Open();
	virtual void Close();

	// prepare statement (also convert to native format if needed)
	virtual void Prepare(
		const SAString &sStmt,
		SACommandType_t eCmdType,
		int nPlaceHolderCount,
		saPlaceHolder **ppPlaceHolders);
	// executes statement (also binds parameters if needed)
	virtual void Execute(
		int nPlaceHolderCount,
		saPlaceHolder **ppPlaceHolders);
	// cleans up after execute if needed, so the statement can be reexecuted
	virtual void UnExecute();
	virtual void Cancel();

	virtual bool ResultSetExists();
	virtual void DescribeFields(
		DescribeFields_cb_t fn);
	virtual void SetSelectBuffers();
	virtual void SetFieldBuffer(
		int nCol,	// 1-based
		void *pInd,
		unsigned int nIndSize,
		void *pSize,
		unsigned int nSizeSize,
		void *pValue,
		unsigned int nValueSize);
	virtual bool FetchNext();

	virtual long GetRowsAffected();

	virtual void ReadLongOrLOB(
		ValueType_t eValueType,
		SAValueRead &vr,
		void *pValue,
		unsigned int nFieldBufSize,
		saLongOrLobReader_t fnReader,
		unsigned int nReaderWantedPieceSize,
		void *pAddlData);

	virtual void DescribeParamSP();

	virtual saCommandHandles *NativeHandles();
};

//////////////////////////////////////////////////////////////////////
// ImyCursor Construction/Destruction
//////////////////////////////////////////////////////////////////////

ImyCursor::ImyCursor(
	ImyConnection *pImyConnection,
	SACommand *pCommand) :
	ISACursor(pImyConnection, pCommand)
{
	m_bOpened = false;
	m_bResultSetCanBe = false;
}

/*virtual */
ImyCursor::~ImyCursor()
{
}


//////////////////////////////////////////////////////////////////////
// ImyConnection implementation
//////////////////////////////////////////////////////////////////////

/*virtual */
void ImyConnection::InitializeClient()
{
	::AddMySQLSupport();
}

/*virtual */
void ImyConnection::UnInitializeClient()
{
	::ReleaseMySQLSupport();
}

/*virtual */
void ImyConnection::CnvtInternalToDateTime(
	SADateTime &/*date_time*/,
	const void * /*pInternal*/,
	int/*	nInternalSize*/)
{
	assert(false);	// we do not use ISA... convertors
}

/*static */
int ImyConnection::second(const char *sSecond)
{
	char s[3] = "SS";
	strncpy(s, sSecond, 2);

	int nSecond = atoi(s);
	assert(nSecond >= 0 && nSecond <= 59);

	return nSecond;
}

/*static */
int ImyConnection::minute(const char *sMinute)
{
	char s[3] = "MM";
	strncpy(s, sMinute, 2);

	int nMinute = atoi(s);
	assert(nMinute >= 0 && nMinute <= 59);

	return nMinute;
}

/*static */
int ImyConnection::shortHour(const char *sHour)
{
	char s[3] = "HH";
	strncpy(s, sHour, 2);

	int nHour = atoi(s);
	assert(nHour >= 0 && nHour <= 23);

	return nHour;
}

/*static */
int ImyConnection::longHour(const char *sHour)
{
	char s[4] = "HHH";
	strncpy(s, sHour, 3);

	int nHour = atoi(s);
	assert(nHour >= 0 && nHour <= 999);

	return nHour;
}

/*static */
int ImyConnection::day(const char *sDay)
{
	char s[3] = "DD";
	strncpy(s, sDay, 2);

	int nDay = atoi(s);
	assert(nDay >= 0 && nDay <= 31);

	return nDay;
}

/*static */
int ImyConnection::month(const char *sMonth)
{
	char s[3] = "MM";
	strncpy(s, sMonth, 2);

	int nMonth = atoi(s);
	assert(nMonth >= 0 && nMonth <= 12);

	return nMonth;
}

/*static */
int ImyConnection::longYear(const char *sYear)
{
	char s[5] = "YYYY";
	strncpy(s, sYear, 4);

	int nYear = atoi(s);
	assert(nYear >= 0 && nYear <= 9999);

	return nYear;
}

/*static */
int ImyConnection::shortYear(const char *sYear)
{
	char s[3] = "YY";
	strncpy(s, sYear, 2);

	int nYear = atoi(s);
	assert(nYear >= 0 && nYear <= 99);
	if(nYear <= 69)
		nYear += 2000;
	else
		nYear += 1900;

	return nYear;
}

/*static */
void ImyConnection::CnvtInternalToDateTime(
	SADateTime &date_time,
	const char *sInternal)
{
	// first initialize to default date/time values
	SADateTime dt;
	int nYear = dt.GetYear();
	int nMonth = 1;
	int nDay = 1;
	int nHour = 0;
	int nMinute = 0;
	int nSecond = 0;

	// then try to fill what we can
	int nLen = ::strlen(sInternal);

	// also check if date is invalid
	bool bTimeStamp = strchr(sInternal, '-') == NULL && strchr(sInternal, ':') == NULL;

	if(!bTimeStamp)
	{
		switch(nLen)
		{
		case 19:	//	"YYYY-MM-DD HH:MM:SS", DATETIME
			assert(sInternal[10] == ' ');
			assert(sInternal[13] == ':');
			assert(sInternal[16] == ':');
			nSecond = second(sInternal+17);
			nMinute = minute(sInternal+14);
			nHour = shortHour(sInternal+11);
		case 10:	//	"YYYY-MM-DD", DATE
			assert(sInternal[4] == '-');
			assert(sInternal[7] == '-');
			nDay = day(sInternal+8);
			nMonth = month(sInternal+5);
			nYear = longYear(sInternal);
			break;
		case 8:	//	"HH:MM:SS", TIME
			assert(sInternal[2] == ':');
			assert(sInternal[5] == ':');
			nSecond = second(sInternal+6);
			nMinute = minute(sInternal+3);
			nHour = shortHour(sInternal);
			break;
		case 9:	//	"HHH:MM:SS", TIME
			assert(sInternal[3] == ':');
			assert(sInternal[6] == ':');
			nSecond = second(sInternal+7);
			nMinute = minute(sInternal+4);
			nHour = longHour(sInternal);
			break;
		default:
			assert(false);
		}
	}
	else
	{
		// TIMESTAMP
		switch(nLen)
		{
		case 14:	//	"YYYYMMDDHHMMSS"
			nSecond = second(sInternal+12);
			nMinute = minute(sInternal+10);
			nHour = shortHour(sInternal+8);
		case 8:	//	"YYYYMMDD"
			nDay = day(sInternal+6);
			nMonth = month(sInternal+4);
			nYear = longYear(sInternal);
			break;
		case 12:	//	"YYMMDDHHMMSS";
			nSecond = second(sInternal+10);
		case 10:	//	"YYMMDDHHMM"
			nMinute = minute(sInternal+8);
			nHour = shortHour(sInternal+6);
		case 6:	//	"YYMMDD"
			nDay = day(sInternal+4);
		case 4:	//	"YYMM"
			nMonth = month(sInternal+2);
		case 2:	//	"YY";
			nYear = shortYear(sInternal);
			break;
		default:
			assert(false);
		}
	}

	if(nMonth != 0 && nDay != 0 && nHour <=23)	// simple test for validness
		date_time = SADateTime(nYear, nMonth, nDay, nHour, nMinute, nSecond);
	else
		date_time = dt;

	// no milli, micro or nano seconds in MySQL now
	date_time.Fraction() = 0;
}

/*static */
void ImyConnection::CnvtDateTimeToInternal(
	const SADateTime &date_time,
	SAString &sInternal)
{
	// format should be YYYY-MM-DD HH:MM:SS.fraction
	sInternal.Format("%.4d-%.2d-%.2d %.2d:%.2d:%.2d.%.9ld",
		date_time.GetYear(), date_time.GetMonth(), date_time.GetDay(),
		date_time.GetHour(), date_time.GetMinute(), date_time.GetSecond(),
		date_time.Fraction());
}

/*virtual */
void ImyConnection::CnvtInternalToCursor(
	SACommand * /*pCursor*/,
	const void * /*pInternal*/)
{
	assert(false);
}

/*virtual */
long ImyConnection::GetClientVersion() const
{
	char *sClientVer = g_myAPI.mysql_get_client_info();
	char *sPoint;
	short nMajor = (short)strtol(sClientVer, &sPoint, 10);
	assert(*sPoint == '.');
	sPoint++;
	short nMinor = (short)strtol(sPoint, &sPoint, 10);
	return nMinor + (nMajor << 16);
}

/*virtual */
long ImyConnection::GetServerVersion() const
{
	char *sServerVer = g_myAPI.mysql_get_server_info(m_handles.mysql);
	char *sPoint;
	short nMajor = (short)strtol(sServerVer, &sPoint, 10);
	assert(*sPoint == '.');
	sPoint++;
	short nMinor = (short)strtol(sPoint, &sPoint, 10);
	return nMinor + (nMajor << 16);
}

/*virtual */
SAString ImyConnection::GetServerVersionString() const
{
	return  SAString(g_myAPI.mysql_get_server_info(m_handles.mysql));
}

/*virtual */
bool ImyConnection::IsConnected() const
{
	return m_handles.mysql != NULL;
}

/*virtual */
void ImyConnection::Connect(
	const SAString &sDBString,
	const SAString &sUserID,
	const SAString &sPassword)
{
	assert(m_handles.mysql == NULL);

	// dbstring as: [server_name][@][dbname]
	// server_name as: hostname[:port], or unix_socket path
	// for connection to server without dbname use 'server_name@'

	unsigned int port = 0;
	SAString sServerName, sDatabase, sHost, sUnixSocket;

	int iPos = sDBString.Find('@');
	if(iPos >= 0) // Database is present in connection string
	{
		sServerName = sDBString.Left(iPos);
		sDatabase = sDBString.Mid(iPos+1);
	}
	else
		sDatabase = sDBString;

	iPos = sServerName.Find('/');
	if(iPos > 0) // unix_socket
		sUnixSocket = sServerName;
	else
	{
		iPos = sServerName.Find(':');
		if(iPos > 0) // alternate port number found
		{
			sHost = sServerName.Left(iPos);
			port = atoi(sServerName.Mid(iPos+1));
		}
		else
			sHost = sServerName;
	}

	m_handles.mysql = g_myAPI.mysql_init(NULL);
	if(!m_handles.mysql)
		throw SAException(SA_Library_Error, -1, -1, "mysql_init -> NULL");

	try
	{
		if(g_myAPI.mysql_real_connect2) // version with database name
		{
			if(!g_myAPI.mysql_real_connect2(
				m_handles.mysql,
				sHost.IsEmpty()? (const char *)NULL : (const char *)sHost,
				sUserID.IsEmpty()? (const char *)NULL : (const char *)sUserID,
				sPassword.IsEmpty()? (const char *)NULL : (const char *)sPassword,
				sDatabase.IsEmpty()? (const char *)NULL : (const char *)sDatabase,
				port,
				sUnixSocket.IsEmpty()? (const char*)NULL : (const char *)sUnixSocket,
				0))
				Check(m_handles.mysql);
		}
		else
		{
			if(!g_myAPI.mysql_real_connect1(
				m_handles.mysql,
				sHost.IsEmpty()? (const char *)NULL : (const char *)sHost,
				sUserID.IsEmpty()? (const char *)NULL : (const char *)sUserID,
				sPassword.IsEmpty()? (const char *)NULL : (const char *)sPassword,
				port,
				sUnixSocket.IsEmpty()? (const char *)NULL : (const char *)sUnixSocket,
				0))
				Check(m_handles.mysql);
			if(!sDatabase.IsEmpty() && g_myAPI.mysql_select_db(m_handles.mysql, sDatabase))
				Check(m_handles.mysql);
		}
	}
	catch(SAException &)	// clean up
	{
		if(m_handles.mysql)
		{
			g_myAPI.mysql_close(m_handles.mysql);
			m_handles.mysql = NULL;
		}

		throw;
	}
}

/*virtual */
void ImyConnection::Disconnect()
{
	assert(m_handles.mysql != NULL);

	g_myAPI.mysql_close(m_handles.mysql);
	m_handles.mysql = NULL;
}

/*virtual */
void ImyConnection::Commit()
{
	if(g_myAPI.mysql_query(m_handles.mysql, "COMMIT"))
		Check(m_handles.mysql);
}

/*virtual */
void ImyConnection::Rollback()
{
	if(g_myAPI.mysql_query(m_handles.mysql, "ROLLBACK"))
		Check(m_handles.mysql);
}

/*virtual */
saAPI *ImyConnection::NativeAPI() const
{
	return 	&g_myAPI;
}

/*virtual */
saConnectionHandles *ImyConnection::NativeHandles()
{
	return &m_handles;
}

/*virtual */
void ImyConnection::setIsolationLevel(
	SAIsolationLevel_t eIsolationLevel)
{
	// Setting the SESSION privilege will affect the following and all future transactions.
	switch(eIsolationLevel)
	{
	case SA_ReadUncommitted:
		if(g_myAPI.mysql_query(m_handles.mysql, "SET SESSION TRANSACTION ISOLATION LEVEL READ UNCOMMITTED"))
			Check(m_handles.mysql);
		break;
	case SA_ReadCommitted:
		if(g_myAPI.mysql_query(m_handles.mysql, "SET SESSION TRANSACTION ISOLATION LEVEL READ COMMITTED"))
			Check(m_handles.mysql);
		break;
	case SA_RepeatableRead:
		if(g_myAPI.mysql_query(m_handles.mysql, "SET SESSION TRANSACTION ISOLATION LEVEL REPEATABLE READ"))
			Check(m_handles.mysql);
		break;
	case SA_Serializable:
		if(g_myAPI.mysql_query(m_handles.mysql, "SET SESSION TRANSACTION ISOLATION LEVEL SERIALIZABLE"))
			Check(m_handles.mysql);
		break;
	default:
		assert(false);
		return;
	}
	// start new transaction
	m_pSAConnection->Commit();
}

/*virtual */
void ImyConnection::setAutoCommit(
	SAAutoCommit_t eAutoCommit)
{
	switch(eAutoCommit)
	{
	case SA_AutoCommitOff:
		if(g_myAPI.mysql_query(m_handles.mysql, "SET AUTOCOMMIT=0"))
			Check(m_handles.mysql);
		break;
	case SA_AutoCommitOn:
		if(g_myAPI.mysql_query(m_handles.mysql, "SET AUTOCOMMIT=1"))
			Check(m_handles.mysql);
		break;
	default:
		assert(false);
	}
}

/*virtual */
ISACursor *ImyConnection::NewCursor(SACommand *m_pCommand)
{
	return new ImyCursor(this, m_pCommand);
}

//////////////////////////////////////////////////////////////////////
// ImyCursor implementation
//////////////////////////////////////////////////////////////////////

/*virtual */
bool ImyCursor::IsOpened()
{
	return m_bOpened;
}

/*virtual */
void ImyCursor::Open()
{
	assert(m_bOpened == false);

	m_bOpened = true;
}

/*virtual */
void ImyCursor::Close()
{
	assert(m_bOpened == true);

	m_bOpened = false;
}

// prepare statement (also convert to native format if needed)
/*virtual */
void ImyCursor::Prepare(
	const SAString &sStmt,
	SACommandType_t/* eCmdType*/,
	int/* nPlaceHolderCount*/,
	saPlaceHolder ** /*ppPlaceHolders*/)
{
	// save original statement
	m_sOriginalStmst = sStmt;
}

/*virtual */
void ImyCursor::UnExecute()
{
	if(m_handles.result)
	{
		g_myAPI.mysql_free_result(m_handles.result);
		m_handles.result = NULL;
	}
	m_bResultSetCanBe = false;
}

// executes statement (also binds parameters if needed)
/*virtual */
void ImyCursor::Execute(
	int nPlaceHolderCount,
	saPlaceHolder **ppPlaceHolders)
{
	SAString sBoundStmt;
	// change ':' param markers to bound values
	unsigned int nPos = 0;
	for(int i = 0; i < nPlaceHolderCount; ++i)
	{
		SAParam &Param = *ppPlaceHolders[i]->getParam();

		sBoundStmt += m_sOriginalStmst.Mid(nPos, ppPlaceHolders[i]->getStart()-nPos);

		if(Param.isNull())
		{
			sBoundStmt += "NULL";
		}
		else
		{
			SAString sBoundValue;
			SAString sTemp;
			switch(Param.DataType())
			{
			case SA_dtUnknown:
				throw SAException(SA_Library_Error, -1, -1, IDS_UNKNOWN_PARAMETER_TYPE, (const char*)Param.Name());
			case SA_dtBool:
				sBoundValue = Param.asBool()? "1" : "0";
				break;
			case SA_dtShort:
			case SA_dtLong:
			case SA_dtDouble:
			case SA_dtNumeric:
				sBoundValue = Param.asString();	// use SQLAPI++ converter
				break;
			case SA_dtDateTime:
				ImyConnection::CnvtDateTimeToInternal(
					Param.setAsDateTime(), sTemp);
				sBoundValue = "'";
				sBoundValue += sTemp;
				sBoundValue += "'";
				break;
			case SA_dtString:
				sBoundValue = "'";
				sBoundValue += MySQLEscapeString(Param.asString());
				sBoundValue += "'";
				break;
			case SA_dtBytes:
				sBoundValue = "'";
				sBoundValue += MySQLEscapeString(Param.asBytes());
				sBoundValue += "'";
				break;
			case SA_dtLongBinary:
			case SA_dtBLob:
				BindBLob(Param, sBoundStmt);
				break;
			case SA_dtLongChar:
			case SA_dtCLob:
				BindText(Param, sBoundStmt);
				break;
			default:
				assert(false);
			}

			switch(Param.DataType())
			{
			case SA_dtLongBinary:
			case SA_dtLongChar:
			case SA_dtBLob:
			case SA_dtCLob:
				break;	// was already written
			default:
				sBoundStmt += sBoundValue;
			}
		}
		nPos = ppPlaceHolders[i]->getEnd() + 1;
	}
	// copy tail
	if(nPos < strlen(m_sOriginalStmst))
		sBoundStmt += m_sOriginalStmst.Mid(nPos);

	myConnectionHandles *pConH = (myConnectionHandles *)m_pCommand->Connection()->NativeHandles();
	if(g_myAPI.mysql_real_query(pConH->mysql, sBoundStmt, sBoundStmt.GetLength()))
		Check(pConH->mysql);

	SAString sOption = m_pCommand->Option("HandleResult");
	if(sOption.CompareNoCase("store") == 0)
		m_handles.result = g_myAPI.mysql_store_result(pConH->mysql);
	else
		m_handles.result = g_myAPI.mysql_use_result(pConH->mysql);

	m_bResultSetCanBe = true;
		
	Check(pConH->mysql);
}

SAString ImyCursor::MySQLEscapeString(const char *sFrom, int nLen)
{
	SAString sNew;

	char *p = sNew.GetBuffer(nLen*2);
	unsigned int nNewLen;
	if(g_myAPI.mysql_real_escape_string)
	{
		myConnectionHandles *pConH = (myConnectionHandles *)m_pCommand->Connection()->NativeHandles();
		nNewLen = g_myAPI.mysql_real_escape_string(
			pConH->mysql,
			p,
			sFrom,
			(unsigned int)nLen);
	}
	else
		nNewLen = g_myAPI.mysql_escape_string(
			p,
			sFrom,
			(unsigned int)nLen);
	sNew.ReleaseBuffer((int)nNewLen);

	return sNew;
}

SAString ImyCursor::MySQLEscapeString(const SAString &sValue)
{
	int nLen = sValue.GetLength();
	if(!nLen)
		return sValue;

	return MySQLEscapeString(sValue, nLen);
}

void ImyCursor::BindBLob(SAParam &Param, SAString &sBoundStmt)
{
	sBoundStmt += "'";

	unsigned int nActualWrite;
	SAPieceType_t ePieceType = SA_FirstPiece;
	void *pBuf;
	while((nActualWrite = Param.InvokeWriter(
		ePieceType, ImyConnection::MaxLongPiece, pBuf)) != 0)
	{
		sBoundStmt += MySQLEscapeString((const char *)pBuf, nActualWrite);

		if(ePieceType == SA_LastPiece)
			break;
	}

	sBoundStmt += "'";
}

void ImyCursor::BindText(SAParam &Param, SAString &sBoundStmt)
{
	sBoundStmt += "'";

	unsigned int nActualWrite;
	SAPieceType_t ePieceType = SA_FirstPiece;
	void *pBuf;
	while((nActualWrite = Param.InvokeWriter(
		ePieceType, ImyConnection::MaxLongPiece, pBuf)) != 0)
	{
		sBoundStmt += MySQLEscapeString((const char *)pBuf, nActualWrite);

		if(ePieceType == SA_LastPiece)
			break;
	}

	sBoundStmt += "'";
}

/*virtual */
void ImyCursor::Cancel()
{
	myConnectionHandles *pConH = (myConnectionHandles *)m_pCommand->Connection()->NativeHandles();
	// kill connection
	if(g_myAPI.mysql_kill(pConH->mysql, g_myAPI.mysql_thread_id(pConH->mysql)))
		Check(pConH->mysql);

	// try to restore connection
	g_myAPI.mysql_ping(pConH->mysql);
}

/*virtual */
bool ImyCursor::ResultSetExists()
{
	if(!m_bResultSetCanBe)
		return false;

	return m_handles.result != NULL;
}

/*virtual */
void ImyCursor::DescribeFields(
	DescribeFields_cb_t fn)
{
	myConnectionHandles *pConH = (myConnectionHandles *)m_pCommand->Connection()->NativeHandles();

	unsigned int cFields = 0;
	if(g_myAPI.mysql_field_count)
		cFields = g_myAPI.mysql_field_count(pConH->mysql);
	else
		assert(false);

	MYSQL_FIELD *fields;
	fields = g_myAPI.mysql_fetch_fields(m_handles.result);
	for(unsigned int iField = 0; iField < cFields; ++iField)
	{
		int Prec;	// calculated by ImyConnection::CnvtNativeToStd
		SADataType_t eDataType = ImyConnection::CnvtNativeToStd(
			fields->type,
			fields->length,
			Prec,
			fields->decimals,
			fields->flags);
		(m_pCommand->*fn)(
			fields->name,
			eDataType,
			fields->type,
			fields->length,
			Prec,
			fields->decimals,
			fields->flags & NOT_NULL_FLAG);

		++fields;
	}
}

/*virtual */
void ImyCursor::SetSelectBuffers()
{
	// do nothing
}

/*virtual */
void ImyCursor::SetFieldBuffer(
	int/* nCol*/,	// 1-based
	void * /*pInd*/,
	unsigned int/* nIndSize*/,
	void * /*pSize*/,
	unsigned int/* nSizeSize*/,
	void * /*pValue*/,
	unsigned int/* nValueSize*/)
{
	assert(false);	// we do not use standard allocators
}

void ImyCursor::ConvertMySQLRowToFields()
{
	int cFields = m_pCommand->FieldCount();
	for(int iField = 0; iField < cFields; ++iField)
	{
		SAField &Field = m_pCommand->Field(iField+1);
		SADataType_t eFieldType = Field.FieldType();

		if(m_mysql_row[iField] == NULL)
		{
			*Field.m_pbNull = true;
			continue;
		}
		*Field.m_pbNull = false;

		const char *sValue = m_mysql_row[iField];
		unsigned int nRealSize = m_lengths[iField];

		switch(eFieldType)
		{
		case SA_dtUnknown:
			throw SAException(SA_Library_Error, -1, -1, IDS_UNKNOWN_DATA_TYPE);
		case SA_dtShort:
			Field.m_eDataType = SA_dtShort;
			*(short*)Field.m_pScalar = (short)atol(sValue);
			break;
		case SA_dtLong:
			Field.m_eDataType = SA_dtLong;
			*(long*)Field.m_pScalar = atol(sValue);
			break;
		case SA_dtDouble:
			Field.m_eDataType = SA_dtDouble;
			*(double*)Field.m_pScalar = atof(sValue);
			break;
		case SA_dtNumeric:
			Field.m_eDataType = SA_dtNumeric;
			ImyConnection::CnvtInternalToNumeric(
				*Field.m_pNumeric,
				sValue);
			break;
		case SA_dtDateTime:
			Field.m_eDataType = SA_dtDateTime;
			ImyConnection::CnvtInternalToDateTime(
				*Field.m_pDateTime,
				sValue);
			break;
		case SA_dtString:
			Field.m_eDataType = SA_dtString;
			*Field.m_pString =
				SAString(sValue, nRealSize);
			break;
		case SA_dtBytes:
			Field.m_eDataType = SA_dtBytes;
			*Field.m_pString =
				SAString(sValue, nRealSize);
			break;
		case SA_dtLongBinary:
			Field.m_eDataType = SA_dtLongBinary;
			break;
		case SA_dtLongChar:
			Field.m_eDataType = SA_dtLongChar;
			break;
		case SA_dtBLob:
			Field.m_eDataType = SA_dtBLob;
			break;
		case SA_dtCLob:
			Field.m_eDataType = SA_dtCLob;
			break;
		default:
			assert(false);	// unknown type
		}

		if(isLongOrLob(eFieldType))
			ConvertLongOrLOB(ISA_FieldValue, Field, NULL, 0);
	}
}

/*virtual */
bool ImyCursor::FetchNext()
{
	m_mysql_row = g_myAPI.mysql_fetch_row(m_handles.result);

	if(m_mysql_row)
	{
		m_lengths = g_myAPI.mysql_fetch_lengths(m_handles.result);
		ConvertMySQLRowToFields();
	}
	else
		m_bResultSetCanBe = false;

	return m_mysql_row != NULL;
}

/*virtual */
long ImyCursor::GetRowsAffected()
{
	myConnectionHandles *pConH = (myConnectionHandles *)m_pCommand->Connection()->NativeHandles();

	my_ulonglong cRows = g_myAPI.mysql_affected_rows(pConH->mysql);
	
	return (long)cRows;
}

/*virtual */
void ImyCursor::ReadLongOrLOB(
	ValueType_t/* eValueType*/,
	SAValueRead &vr,
	void * /*pValue*/,
	unsigned int/* nFieldBufSize*/,
	saLongOrLobReader_t fnReader,
	unsigned int nReaderWantedPieceSize,
	void *pAddlData)
{
	int nPos = ((SAField &)vr).Pos();

	// get long data and size
	const char *pData = m_mysql_row[nPos-1];
	unsigned long nLongSize = m_lengths[nPos-1];

	unsigned char* pBuf;
	unsigned int nPieceSize = vr.PrepareReader(
		nLongSize,
		ImyConnection::MaxLongPiece,
		pBuf,
		fnReader,
		nReaderWantedPieceSize,
		pAddlData);
	assert(nPieceSize <= ImyConnection::MaxLongPiece);

	SAPieceType_t ePieceType = SA_FirstPiece;
	unsigned long nTotalRead = 0;
	do
	{
		nPieceSize =
			sa_min(nPieceSize, nLongSize - nTotalRead);

		memcpy(pBuf, pData + nTotalRead, nPieceSize);
		unsigned int actual_read = nPieceSize;

		nTotalRead += actual_read;
		assert(nTotalRead <= nLongSize);

        if(nTotalRead == nLongSize)
        {
            if(ePieceType == SA_NextPiece)
                ePieceType = SA_LastPiece;
            else    // the whole Long was read in one piece
            {
                assert(ePieceType == SA_FirstPiece);
                ePieceType = SA_OnePiece;
            }
        }
		vr.InvokeReader(ePieceType, pBuf, actual_read);

		if(ePieceType == SA_FirstPiece)
			ePieceType = SA_NextPiece;
	}
	while(nTotalRead < nLongSize);
}

/*virtual */
void ImyCursor::DescribeParamSP()
{
	assert(false);	// no SPs in MySQL
}

/*virtual */
saCommandHandles *ImyCursor::NativeHandles()
{
	return &m_handles;
}

//////////////////////////////////////////////////////////////////////
// MySQL globals
//////////////////////////////////////////////////////////////////////

ISAConnection *newImyConnection(SAConnection *pSAConnection)
{
	return new ImyConnection(pSAConnection);
}

/*static */
void ImyConnection::CnvtInternalToNumeric(
	SANumeric &numeric,
	const char *sValue)
{
	numeric = sValue;
}

/*virtual */
void ImyConnection::CnvtInternalToNumeric(
	SANumeric &/*numeric*/,
	const void * /*pInternal*/,
	int/* nInternalSize*/)
{
	assert(false);	// we do not use ISA... convertors
}
