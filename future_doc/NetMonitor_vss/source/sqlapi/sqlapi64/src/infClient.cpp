// infClient.cpp: implementation of the IinfClient class.
//
//////////////////////////////////////////////////////////////////////

#include <SQLAPI.h>
#include "infClient.h"

#include <assert.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>	// strtol
 
#include <infAPI.h>
#include "samisc.h"
#include "errmsg.h"

//////////////////////////////////////////////////////////////////////
// IinfConnection Class
//////////////////////////////////////////////////////////////////////

class IinfConnection : public ISAConnection
{
	enum
	{
		MaxLongAtExecSize = 0x7fffffff+SQL_LEN_DATA_AT_EXEC(0)
	};
	friend class IinfCursor;

	infConnectionHandles m_handles;
	long m_nDriverODBCVer;

	static void Check(
		SQLRETURN return_code,
		SQLSMALLINT HandleType,
		SQLHANDLE Handle);
	SQLINTEGER LenDataAtExec();
	void issueIsolationLevel(
		SAIsolationLevel_t eIsolationLevel);

	void SafeAllocEnv();
	void SafeAllocConnect();
	void SafeFreeEnv();
	void SafeFreeConnect();
	void SafeSetEnvAttr();
	void SafeCommit();
	void SafeRollback();
	void SafeSetConnectOption(
		SQLINTEGER Attribute,
		SQLPOINTER ValuePtr,
		SQLINTEGER StringLength);

protected:
	virtual ~IinfConnection();

public:
	IinfConnection(SAConnection *pSAConnection);

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
	static void CnvtInternalToDateTime(
		SADateTime &date_time,
		const TIMESTAMP_STRUCT &Internal);
	static void CnvtDateTimeToInternal(
		const SADateTime &date_time,
		TIMESTAMP_STRUCT &Internal);

	virtual void CnvtInternalToCursor(
		SACommand *pCursor,
		const void *pInternal);
};

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IinfConnection::IinfConnection(
	SAConnection *pSAConnection) : ISAConnection(pSAConnection)
{
	m_nDriverODBCVer = 0;
}

IinfConnection::~IinfConnection()
{
}

/*virtual */
void IinfConnection::InitializeClient()
{
	::AddInfSupport();
}

/*virtual */
void IinfConnection::UnInitializeClient()
{
	::ReleaseInfSupport();
}

SQLINTEGER IinfConnection::LenDataAtExec()
{
	SQLSMALLINT retlen = 0;
	char szValue[10];
	Check(g_infAPI.SQLGetInfo(
		m_handles.m_hdbc, SQL_NEED_LONG_DATA_LEN, szValue, sizeof(szValue), &retlen), SQL_HANDLE_DBC, m_handles.m_hdbc);
	if(retlen > 0 && (*szValue == 'Y' || *szValue == 'y'))
		return SQL_LEN_DATA_AT_EXEC(MaxLongAtExecSize);

	return SQL_DATA_AT_EXEC;
}

/*virtual */
void IinfConnection::CnvtInternalToDateTime(
	SADateTime &date_time,
	const void *pInternal,
	int nInternalSize)
{
	assert(nInternalSize == sizeof(TIMESTAMP_STRUCT));
	if(nInternalSize != sizeof(TIMESTAMP_STRUCT))
		return;
	CnvtInternalToDateTime(date_time, *(const TIMESTAMP_STRUCT*)pInternal);
}

/*static */
void IinfConnection::CnvtInternalToDateTime(
	SADateTime &date_time,
	const TIMESTAMP_STRUCT &Internal)
{
	date_time = SADateTime(
		Internal.year,
		Internal.month,
		Internal.day,
		Internal.hour,
		Internal.minute,
		Internal.second);

	date_time.Fraction() = Internal.fraction;
}

/*static */
void IinfConnection::CnvtDateTimeToInternal(
	const SADateTime &date_time,
	TIMESTAMP_STRUCT &Internal)
{
	Internal.year = (SQLSMALLINT)(date_time.GetYear());
	Internal.month = (SQLUSMALLINT)(date_time.GetMonth());
	Internal.day = (SQLUSMALLINT)date_time.GetDay();
	Internal.hour = (SQLUSMALLINT)date_time.GetHour();
	Internal.minute = (SQLUSMALLINT)date_time.GetMinute();
	Internal.second = (SQLUSMALLINT)date_time.GetSecond();

	Internal.fraction = date_time.Fraction();
}	

/*virtual */
void IinfConnection::CnvtInternalToCursor(
	SACommand * /*pCursor*/,
	const void * /*pInternal*/)
{
	assert(false);
}

/*virtual */
long IinfConnection::GetClientVersion() const
{
	if(g_nInfDLLVersionLoaded == 0)	// has not been detected
	{
		if(IsConnected())
		{
			char sInfoValue[1024];
			SQLSMALLINT cbInfoValue;
			g_infAPI.SQLGetInfo(m_handles.m_hdbc, SQL_DRIVER_VER, sInfoValue, sizeof(sInfoValue), &cbInfoValue);
			sInfoValue[cbInfoValue] = 0;

			char *sPoint;
			short nMajor = (short)strtol(sInfoValue, &sPoint, 10);
			assert(*sPoint == '.');

			sPoint++;
			short nMinor = (short)strtol(sPoint, &sPoint, 10);
			return SA_MAKELONG(nMinor, nMajor);
		}
	}

	return g_nInfDLLVersionLoaded;
}

/*virtual */
long IinfConnection::GetServerVersion() const
{
	char sInfoValue[1024];
	SQLSMALLINT cbInfoValue;
	g_infAPI.SQLGetInfo(m_handles.m_hdbc, SQL_DBMS_VER, sInfoValue, sizeof(sInfoValue), &cbInfoValue);
	sInfoValue[cbInfoValue] = 0;

	char *sPoint;
	short nMajor = (short)strtol(sInfoValue, &sPoint, 10);
	assert(*sPoint == '.');
	sPoint++;
	short nMinor = (short)strtol(sPoint, &sPoint, 10);
	return nMinor + (nMajor << 16);
}

/*virtual */
SAString IinfConnection::GetServerVersionString() const
{
	char sInfoValue[1024];
	SQLSMALLINT cbInfoValue;
	g_infAPI.SQLGetInfo(m_handles.m_hdbc, SQL_DBMS_NAME, sInfoValue, sizeof(sInfoValue), &cbInfoValue);

	SAString s = SAString(sInfoValue, cbInfoValue);
	s += " Release ";

	g_infAPI.SQLGetInfo(m_handles.m_hdbc, SQL_DBMS_VER, sInfoValue, sizeof(sInfoValue), &cbInfoValue);
	s += SAString(sInfoValue, cbInfoValue);

	return s;
}

/*static */
void IinfConnection::Check(
	SQLRETURN return_code,
	SQLSMALLINT HandleType,
	SQLHANDLE Handle)
{
	if(return_code == SQL_SUCCESS)
		return;
	if(return_code == SQL_SUCCESS_WITH_INFO)
		return;

	SQLCHAR Sqlstate[5+1];
	SQLINTEGER NativeError = 0;
	char sMsg[4096] = "";
	SQLSMALLINT TextLength;

	SQLRETURN rc = 0;
	
	if(g_infAPI.SQLGetDiagRec)
	{
		rc = g_infAPI.SQLGetDiagRec(HandleType, Handle, 1, 
			Sqlstate, &NativeError,
			(SQLCHAR *)sMsg, sizeof(sMsg), &TextLength);
	}
	else
	{
		switch(HandleType)
		{
		case SQL_HANDLE_ENV:
			rc = g_infAPI.SQLError(
				Handle,
				NULL,
				NULL,
				Sqlstate, &NativeError,
				(SQLCHAR *)sMsg, sizeof(sMsg), &TextLength);
			break;
		case SQL_HANDLE_DBC:
			rc = g_infAPI.SQLError(
				NULL,
				Handle,
				NULL,
				Sqlstate, &NativeError,
				(SQLCHAR *)sMsg, sizeof(sMsg), &TextLength);
			break;
		case SQL_HANDLE_STMT:
			rc = g_infAPI.SQLError(
				NULL,
				NULL,
				Handle,
				Sqlstate, &NativeError,
				(SQLCHAR *)sMsg, sizeof(sMsg), &TextLength);
			break;
		default:
			assert(false);
		}
	}

	switch(rc)
	{
	case SQL_INVALID_HANDLE:
		strcpy(sMsg, "SQL_INVALID_HANDLE");
		break;
	case SQL_NO_DATA:
		strcpy(sMsg, "SQL_NO_DATA");
		break;
	}

	throw SAException(
		SA_DBMS_API_Error,
		NativeError, -1,
		"%s", sMsg);
}

/*virtual */
bool IinfConnection::IsConnected() const
{
	return m_handles.m_hdbc != NULL;
}

void IinfConnection::SafeAllocEnv()
{
	if(g_infAPI.SQLAllocHandle)
		g_infAPI.SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &m_handles.m_hevn);
	else
		g_infAPI.SQLAllocEnv(&m_handles.m_hevn);

	assert(m_handles.m_hevn);
}

void IinfConnection::SafeAllocConnect()
{
	if(g_infAPI.SQLAllocHandle)
		Check(g_infAPI.SQLAllocHandle(SQL_HANDLE_DBC, m_handles.m_hevn, &m_handles.m_hdbc), SQL_HANDLE_ENV, m_handles.m_hevn);
	else
		Check(g_infAPI. SQLAllocConnect(m_handles.m_hevn, &m_handles.m_hdbc), SQL_HANDLE_ENV, m_handles.m_hevn);
}

void IinfConnection::SafeFreeEnv()
{
	if(g_infAPI.SQLFreeHandle)
		Check(g_infAPI.SQLFreeHandle(SQL_HANDLE_ENV, m_handles.m_hevn), SQL_HANDLE_ENV, m_handles.m_hevn);
	else
		Check(g_infAPI. SQLFreeEnv(m_handles.m_hevn), SQL_HANDLE_ENV, m_handles.m_hevn);

	m_handles.m_hevn = NULL;
}

void IinfConnection::SafeFreeConnect()
{
	if(g_infAPI.SQLFreeHandle)
		Check(g_infAPI.SQLFreeHandle(SQL_HANDLE_DBC, m_handles.m_hdbc), SQL_HANDLE_DBC, m_handles.m_hdbc);
	else
		Check(g_infAPI.SQLFreeConnect(m_handles.m_hdbc), SQL_HANDLE_DBC, m_handles.m_hdbc);

	m_handles.m_hdbc = NULL;
}

void IinfConnection::SafeSetEnvAttr()
{
	if(g_infAPI.SQLSetEnvAttr)
		Check(g_infAPI.SQLSetEnvAttr(m_handles.m_hevn, SQL_ATTR_ODBC_VERSION, SQLPOINTER(SQL_OV_ODBC3), 0), SQL_HANDLE_ENV, m_handles.m_hevn);
}

/*virtual */
void IinfConnection::Connect(
	const SAString &sDBString,
	const SAString &sUserID,
	const SAString &sPassword)
{
	assert(!m_handles.m_hevn);
	assert(!m_handles.m_hdbc);

	SafeAllocEnv();
	try
	{
		SafeSetEnvAttr();
		SafeAllocConnect();

		if(sDBString.Find('=') == -1)	// it's not a valid connection string, but it can be DSN name
			Check(g_infAPI.SQLConnect(m_handles.m_hdbc, 
				(SQLCHAR *)(const char*)sDBString, SQL_NTS,
				(SQLCHAR *)(const char*)sUserID, SQL_NTS,
				(SQLCHAR *)(const char*)sPassword, SQL_NTS),
				SQL_HANDLE_DBC, m_handles.m_hdbc);
		else
		{
			SAString s = sDBString;
			if(!sUserID.IsEmpty())
			{
				s += ";UID=";
				s += sUserID;
			}
			if(!sPassword.IsEmpty())
			{
				s += ";PWD=";
				s += sPassword;
			}

			Check(g_infAPI.SQLDriverConnect(
				m_handles.m_hdbc, NULL,
				(SQLCHAR *)(const char*)s, SQL_NTS, NULL, 0, 0, SQL_DRIVER_NOPROMPT),
				SQL_HANDLE_DBC, m_handles.m_hdbc);
		}

		char sVer[512];
		SQLSMALLINT StringLength;
		Check(g_infAPI. SQLGetInfo(
			m_handles.m_hdbc,
			SQL_DRIVER_ODBC_VER,
			sVer,
			sizeof(sVer),
			&StringLength), SQL_HANDLE_DBC, m_handles.m_hdbc);
		m_nDriverODBCVer = SAExtractVersionFromString(sVer);
	}
	catch(...)
	{
		// clean up
		if(m_handles.m_hdbc)
		{
			try
			{
				SafeFreeConnect();
			}
			catch(SAException &)
			{
			}
		}
		if(m_handles.m_hevn)
		{
			try
			{
				SafeFreeEnv();
			}
			catch(SAException &)
			{
			}
		}

		throw;
	}
}

/*virtual */
void IinfConnection::Disconnect()
{
	assert(m_handles.m_hevn);
	assert(m_handles.m_hdbc);

	Check(g_infAPI.SQLDisconnect(m_handles.m_hdbc), SQL_HANDLE_DBC, m_handles.m_hdbc);
	SafeFreeConnect();
	SafeFreeEnv();

	m_nDriverODBCVer = 0;
}

void IinfConnection::SafeCommit()
{
	if(g_infAPI.SQLEndTran)
		Check(g_infAPI.SQLEndTran(SQL_HANDLE_DBC, m_handles.m_hdbc, SQL_COMMIT), SQL_HANDLE_DBC, m_handles.m_hdbc);
	else
		Check(g_infAPI. SQLTransact(m_handles.m_hevn, m_handles.m_hdbc, SQL_COMMIT), SQL_HANDLE_DBC, m_handles.m_hdbc);
}

void IinfConnection::SafeRollback()
{
	if(g_infAPI.SQLEndTran)
		Check(g_infAPI.SQLEndTran(SQL_HANDLE_DBC, m_handles.m_hdbc, SQL_ROLLBACK), SQL_HANDLE_DBC, m_handles.m_hdbc);
	else
		Check(g_infAPI. SQLTransact(m_handles.m_hevn, m_handles.m_hdbc, SQL_ROLLBACK), SQL_HANDLE_DBC, m_handles.m_hdbc);
}

/*virtual */
void IinfConnection::Commit()
{
	SafeCommit();
}

/*virtual */
void IinfConnection::Rollback()
{
	SafeRollback();
}

//////////////////////////////////////////////////////////////////////
// IinfClient Class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IinfClient::IinfClient()
{

}

IinfClient::~IinfClient()
{

}

ISAConnection *IinfClient::QueryConnectionInterface(
	SAConnection *pSAConnection)
{
	return new IinfConnection(pSAConnection);
}

//////////////////////////////////////////////////////////////////////
// IinfCursor Class
//////////////////////////////////////////////////////////////////////

class IinfCursor : public ISACursor
{
	infCommandHandles	m_handles;

	SAString CallSubProgramSQL();
	SADataType_t CnvtNativeToStd(
		int nNativeType,
		int nPrec,
		int nScale) const;
	static SQLSMALLINT CnvtStdToNative(SADataType_t eDataType);
	SQLSMALLINT CnvtStdToNativeValueType(SADataType_t eDataType) const;

	void BindLongs();

	void SafeAllocStmt();
	void SafeFreeStmt();

protected:
	virtual unsigned int InputBufferSize(
		const SAParam &Param) const;
	virtual unsigned int OutputBufferSize(
		SADataType_t eDataType,
		unsigned int nDataSize) const;
	virtual void SetFieldBuffer(
		int nCol,	// 1-based

		void *pInd,
		unsigned int nIndSize,
		void *pSize,
		unsigned int nSizeSize,
		void *pValue,
		unsigned int nValueSize);
	virtual bool IndicatorIsNull(
		int nPos,	// 1-based
		SAValueRead &vr,
		ValueType_t eValueType,
		void *pInd, unsigned int nIndSize,
		void *pSize, unsigned int nSizeSize,
		unsigned int &nRealSize,
		int nBulkReadingBufPos) const;

public:
	IinfCursor(
		IinfConnection *pIinfConnection,
		SACommand *pCommand);
	virtual ~IinfCursor();

	virtual bool IsOpened();
	virtual void Open();
	virtual void Close();

	virtual void Prepare(
		const SAString &sStmt,
		SACommandType_t eCmdType,
		int nPlaceHolderCount,
		saPlaceHolder **ppPlaceHolders);
	// binds parameters
	void Bind(
		int nPlaceHolderCount,
		saPlaceHolder **ppPlaceHolders);
	// executes statement
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
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IinfCursor::IinfCursor(
	IinfConnection *pIinfConnection,
	SACommand *pCommand) :
	ISACursor(pIinfConnection, pCommand)
{
}

/*virtual */
IinfCursor::~IinfCursor()
{
}

/*virtual */
unsigned int IinfCursor::InputBufferSize(
	const SAParam &Param) const
{
	if(!Param.isNull())
	{
		switch(Param.DataType())
		{
		case SA_dtBool:
			return sizeof(unsigned char);	// SQL_C_BIT
		case SA_dtDateTime:
			return sizeof(TIMESTAMP_STRUCT);
		case SA_dtLongBinary:
		case SA_dtLongChar:
		case SA_dtBLob:
		case SA_dtCLob:
			return 0;
		default:
			break;
		}
	}
	
	return ISACursor::InputBufferSize(Param);
}

/*virtual */
SADataType_t IinfCursor::CnvtNativeToStd(
	int dbtype,
	int prec,
	int scale) const
{
	SADataType_t eDataType = SA_dtUnknown;

	switch(dbtype)
	{
	case SQL_CHAR:		// Character string of fixed length
	case SQL_VARCHAR:	// Variable-length character string
//	case SQL_WCHAR:		// Unicode character string of fixed length
//	case SQL_WVARCHAR:	// Unicode variable-length character string
		eDataType = SA_dtString;
		break;
	case SQL_BINARY:
	case SQL_VARBINARY:
		eDataType = SA_dtBytes;
		break;
	case SQL_LONGVARCHAR:	// Variable-length character data
#ifdef SQL_WLONGVARCHAR
	case SQL_WLONGVARCHAR:	// Variable-length character data
#endif
		eDataType = SA_dtLongChar;
		break;
	case SQL_LONGVARBINARY: // Variable-length binary data
		eDataType = SA_dtLongBinary;
		break;
	case SQL_DECIMAL:
	case SQL_NUMERIC:
		if(scale <= 0)	// check for exact type
		{
			if(prec < 5)
				eDataType = SA_dtShort;
			else if(prec < 10)
				eDataType = SA_dtLong;
			else
				eDataType = SA_dtNumeric;
		}
		else
			eDataType = SA_dtDouble;
		break;
	case SQL_SMALLINT:
		eDataType = SA_dtShort;
		break;
	case SQL_INTEGER:
		eDataType = SA_dtLong;
		break;
	case SQL_REAL:
		eDataType = SA_dtDouble;
		break;
	case SQL_FLOAT:
		eDataType = SA_dtDouble;
		break;
	case SQL_DOUBLE:
		eDataType = SA_dtDouble;
		break;
	case SQL_BIT:	// Single bit binary data
		eDataType = SA_dtBool;
		break;
	case SQL_TINYINT:
		eDataType = SA_dtShort;
		break;
	case SQL_BIGINT:
		eDataType = SA_dtNumeric;
		break;
	case SQL_TIME:
	case SQL_DATE:		// == SQL_DATETIME
	case SQL_TIMESTAMP:
	case SQL_TYPE_DATE:
	case SQL_TYPE_TIME:
	case SQL_TYPE_TIMESTAMP:
		eDataType = SA_dtDateTime;
		break;
	default:
		assert(false);
	}


	return eDataType;
}

SQLSMALLINT IinfCursor::CnvtStdToNativeValueType(SADataType_t eDataType) const
{
	SQLSMALLINT ValueType;

	switch(eDataType)
	{
	case SA_dtUnknown:
		throw SAException(SA_Library_Error, -1, -1, IDS_UNKNOWN_DATA_TYPE);
	case SA_dtBool:
		ValueType = SQL_C_BIT;
		break;
	case SA_dtShort:
		ValueType = SQL_C_SSHORT;
		break;
	case SA_dtLong:
		ValueType = SQL_C_SLONG;
		break;
	case SA_dtDouble:
		ValueType = SQL_C_DOUBLE;
		break;
	case SA_dtNumeric:
		ValueType = SQL_C_NUMERIC;
		break;
	case SA_dtDateTime:
		ValueType = SQL_C_TYPE_TIMESTAMP;
		break;
	case SA_dtString:
		ValueType = SQL_C_CHAR;
		break;
	case SA_dtBytes:
		ValueType = SQL_C_BINARY;
		break;
	case SA_dtLongBinary:
	case SA_dtBLob:
		ValueType = SQL_C_BINARY;
		break;
	case SA_dtLongChar:
	case SA_dtCLob:
		ValueType = SQL_C_CHAR;
		break;
	default:
		ValueType = 0;
		assert(false);
	}

	if(((IinfConnection*)m_pISAConnection)->m_nDriverODBCVer < 0x00030000)
	{
		switch(eDataType)
		{
			case SA_dtDateTime:
				ValueType = SQL_C_TIMESTAMP;
			default:
				break;
		}
	}

	return ValueType;
}

/*static */
SQLSMALLINT IinfCursor::CnvtStdToNative(SADataType_t eDataType)
{
	SQLSMALLINT dbtype;

	switch(eDataType)
	{
	case SA_dtUnknown:
		throw SAException(SA_Library_Error, -1, -1, IDS_UNKNOWN_DATA_TYPE);
	case SA_dtBool:
		dbtype = SQL_BIT;
		break;
	case SA_dtShort:
		dbtype = SQL_SMALLINT;
		break;
	case SA_dtLong:
		dbtype = SQL_INTEGER;
		break;
	case SA_dtDouble:
		dbtype = SQL_DOUBLE;
		break;
	case SA_dtDateTime:
		dbtype = SQL_TYPE_TIMESTAMP;
		break;
	case SA_dtString:
		dbtype = SQL_VARCHAR;
		break;
	case SA_dtBytes:
		dbtype = SQL_BINARY;
		break;
	case SA_dtLongBinary:
	case SA_dtBLob:
		dbtype = SQL_LONGVARBINARY;
		break;
	case SA_dtLongChar:
	case SA_dtCLob:
		dbtype = SQL_LONGVARCHAR;
		break;
	default:
		dbtype = 0;
		assert(false);
	}
	
	return dbtype;
}

/*virtual */
bool IinfCursor::IsOpened()
{
	return m_handles.m_hstmt != NULL;
}

/*virtual */
void IinfCursor::Open()
{
	SafeAllocStmt();
}

void IinfCursor::SafeAllocStmt()
{
	assert(m_handles.m_hstmt == NULL);
	if(g_infAPI.SQLAllocHandle)
		IinfConnection::Check(g_infAPI.SQLAllocHandle(SQL_HANDLE_STMT, ((IinfConnection*)m_pISAConnection)->m_handles.m_hdbc, &m_handles.m_hstmt),
			SQL_HANDLE_DBC, ((IinfConnection*)m_pISAConnection)->m_handles.m_hdbc);
	else
		IinfConnection::Check(g_infAPI.SQLAllocStmt(((IinfConnection*)m_pISAConnection)->m_handles.m_hdbc, &m_handles.m_hstmt),
			SQL_HANDLE_DBC, ((IinfConnection*)m_pISAConnection)->m_handles.m_hdbc);
	assert(m_handles.m_hstmt != NULL);
}

void IinfCursor::SafeFreeStmt()
{
	if(g_infAPI.SQLFreeHandle)
		IinfConnection::Check(g_infAPI.SQLFreeHandle(SQL_HANDLE_STMT, m_handles.m_hstmt), SQL_HANDLE_STMT, m_handles.m_hstmt);
	else
		IinfConnection::Check(g_infAPI.SQLFreeStmt(m_handles.m_hstmt, SQL_DROP), SQL_HANDLE_STMT, m_handles.m_hstmt);

	m_handles.m_hstmt = NULL;
}

/*virtual */
void IinfCursor::Close()
{
	assert(m_handles.m_hstmt != NULL);

	SafeFreeStmt();
}

/*virtual */
ISACursor *IinfConnection::NewCursor(SACommand *m_pCommand)
{
	return new IinfCursor(this, m_pCommand);
}

/*virtual */
void IinfCursor::Prepare(
	const SAString &sStmt,
	SACommandType_t eCmdType,
	int nPlaceHolderCount,
	saPlaceHolder**	ppPlaceHolders)
{
	SAString sStmtinf;
	int nPos = 0;
	int i;
	switch(eCmdType)
	{
	case SA_CmdSQLStmt:
		// replace bind variables with '?' place holder
		for(i = 0; i < nPlaceHolderCount; i++)
		{
			sStmtinf += sStmt.Mid(nPos, ppPlaceHolders[i]->getStart()-nPos);
			sStmtinf += "?";
			nPos = ppPlaceHolders[i]->getEnd() + 1;
		}
		// copy tail
		if(nPos < sStmt.GetLength())
			sStmtinf += sStmt.Mid(nPos);
		break;
	case SA_CmdStoredProc:
		sStmtinf = CallSubProgramSQL();
		break;
	default:
		assert(false);
	}

	// a bit of clean up
	IinfConnection::Check(g_infAPI.SQLFreeStmt(m_handles.m_hstmt, SQL_CLOSE), SQL_HANDLE_STMT, m_handles.m_hstmt);
	IinfConnection::Check(g_infAPI.SQLFreeStmt(m_handles.m_hstmt, SQL_UNBIND), SQL_HANDLE_STMT, m_handles.m_hstmt);
	IinfConnection::Check(g_infAPI.SQLFreeStmt(m_handles.m_hstmt, SQL_RESET_PARAMS), SQL_HANDLE_STMT, m_handles.m_hstmt);

	IinfConnection::Check(g_infAPI.SQLPrepare(
		m_handles.m_hstmt, (SQLTCHAR*)(const char*)sStmtinf, SQL_NTS), SQL_HANDLE_STMT, m_handles.m_hstmt);
}

SAString IinfCursor::CallSubProgramSQL()
{
	int nParams = m_pCommand->ParamCount();

	SAString sSQL = "{";

	// check for Return parameter
	int i;
	for(i = 0; i < nParams; ++i)
	{
		SAParam &Param = m_pCommand->ParamByIndex(i);
		if(Param.ParamDirType() == SA_ParamReturn)
		{
			sSQL += "?=";
			break;
		}
	}
	sSQL += "call ";
	sSQL += m_pCommand->CommandText();

	// specify parameters
	SAString sParams;
	for(i = 0; i < nParams; ++i)
	{
		SAParam &Param = m_pCommand->ParamByIndex(i);
		if(Param.ParamDirType() == SA_ParamReturn)
			continue;

		if(!sParams.IsEmpty())
			sParams += ", ";
		sParams += "?";
	}
	// Informix specific: unlike other drivers
	// if SP with no parameters is called it should have "()"
	sSQL += "(";
	if(!sParams.IsEmpty())
	{
		sSQL += sParams;
	}
	sSQL += ")";

	sSQL += "}";
	return sSQL;
}

void IinfCursor::BindLongs()
{
	SQLRETURN retcode;
	SQLPOINTER ValuePtr;

	try
	{
		while((retcode = g_infAPI.SQLParamData(m_handles.m_hstmt, &ValuePtr)) == SQL_NEED_DATA)
		{
			SAParam *pParam = (SAParam *)ValuePtr;
			unsigned int nActualWrite;
			SAPieceType_t ePieceType = SA_FirstPiece;
			void *pBuf;
			while((nActualWrite = pParam->InvokeWriter(
				ePieceType,
				IinfConnection::MaxLongAtExecSize, pBuf)) != 0)
			{
				IinfConnection::Check(g_infAPI.SQLPutData(
					m_handles.m_hstmt, pBuf, nActualWrite), SQL_HANDLE_STMT, m_handles.m_hstmt);

				if(ePieceType == SA_LastPiece)
					break;
			}
		}
	}
	catch(SAException&)
	{
		g_infAPI.SQLCancel(m_handles.m_hstmt);
		throw;
	}

	IinfConnection::Check(retcode, SQL_HANDLE_STMT, m_handles.m_hstmt);
}

/*virtual */
void IinfCursor::UnExecute()
{
}

void IinfCursor::Bind(
		int nPlaceHolderCount,
		saPlaceHolder**	ppPlaceHolders)
{
	// we should bind for every place holder ('?')
	AllocBindBuffer(nPlaceHolderCount, ppPlaceHolders,
		sizeof(SQLINTEGER), 0);
	void *pBuf = m_pParamBuffer;

	for(int i = 0; i < nPlaceHolderCount; ++i)
	{
		SAParam &Param = *ppPlaceHolders[i]->getParam();

		void *pInd;
		void *pSize;
		unsigned int nDataBufSize;
		void *pValue;
		IncParamBuffer(pBuf, pInd, pSize, nDataBufSize, pValue);

		SADataType_t eDataType = Param.DataType();
		// SA_dtUnknown can be used to bind NULL
		// but some type should be set in that case as well
		SQLSMALLINT ParameterType = CnvtStdToNative(
			eDataType == SA_dtUnknown? SA_dtString : eDataType);
		SQLSMALLINT ValueType = CnvtStdToNativeValueType(
			eDataType == SA_dtUnknown? SA_dtString : eDataType);

		SQLINTEGER *StrLen_or_IndPtr = (SQLINTEGER *)pInd;
		SQLPOINTER ParameterValuePtr = (SQLPOINTER)pValue;
		SQLINTEGER BufferLength = (SQLINTEGER)nDataBufSize;
		SQLUINTEGER ColumnSize = Param.ParamSize();
		if(!ColumnSize)	// not set explicitly
			ColumnSize = BufferLength;

		SQLSMALLINT InputOutputType;
		switch(Param.ParamDirType())
		{
		case SA_ParamInput:
			InputOutputType = SQL_PARAM_INPUT;
			break;
		case SA_ParamOutput:
			InputOutputType = SQL_PARAM_OUTPUT;
			break;
		case SA_ParamInputOutput:
			InputOutputType = SQL_PARAM_INPUT_OUTPUT;
			break;
		default:
			assert(Param.ParamDirType() == SA_ParamReturn);
			InputOutputType = SQL_PARAM_OUTPUT;
		}

		if(isInputParam(Param))
		{
			if(Param.isNull())
				*StrLen_or_IndPtr = SQL_NULL_DATA;		// field is null
			else
				*StrLen_or_IndPtr = InputBufferSize(Param);	// field is not null

			if(!Param.isNull())
			{
				switch(eDataType)
				{
				case SA_dtUnknown:
					throw SAException(SA_Library_Error, -1, -1, IDS_UNKNOWN_PARAMETER_TYPE, (const char*)Param.Name());
				case SA_dtBool:
					assert(*StrLen_or_IndPtr == (SQLINTEGER)sizeof(unsigned char));
					*(unsigned char*)ParameterValuePtr = (unsigned char)Param.asBool();
					break;
				case SA_dtShort:
					assert(*StrLen_or_IndPtr == (SQLINTEGER)sizeof(short));
					*(short*)ParameterValuePtr = Param.asShort();
					break;
				case SA_dtLong:
					assert(*StrLen_or_IndPtr == (SQLINTEGER)sizeof(long));
					*(long*)ParameterValuePtr = Param.asLong();
					break;
				case SA_dtDouble:
					assert(*StrLen_or_IndPtr == (SQLINTEGER)sizeof(double));
					*(double*)ParameterValuePtr = Param.asDouble();
					break;
				case SA_dtDateTime:
					assert(*StrLen_or_IndPtr == (SQLINTEGER)sizeof(TIMESTAMP_STRUCT));
					IinfConnection::CnvtDateTimeToInternal(
						Param.asDateTime(),
						*(TIMESTAMP_STRUCT*)ParameterValuePtr);
					break;
				case SA_dtString:
					assert(*StrLen_or_IndPtr == Param.asString().GetLength());
					memcpy(ParameterValuePtr, (const char*)Param.asString(), *StrLen_or_IndPtr);
					break;
				case SA_dtBytes:
					assert(*StrLen_or_IndPtr == Param.asBytes().GetLength());
					memcpy(ParameterValuePtr, (const char*)Param.asBytes(), *StrLen_or_IndPtr);
					break;
				case SA_dtLongBinary:
				case SA_dtBLob:
				case SA_dtLongChar:
				case SA_dtCLob:
					assert(*StrLen_or_IndPtr == 0);
					break;
				default:
					ValueType = 0;
					ParameterType = 0;
					assert(false);
				}
			}
		}

		if(isLongOrLob(eDataType))
		{
			*StrLen_or_IndPtr = ((IinfConnection*)m_pISAConnection)->LenDataAtExec();
			IinfConnection::Check(g_infAPI.SQLBindParameter(
				m_handles.m_hstmt,
				(SQLUSMALLINT)(i+1), InputOutputType,
				ValueType,
				ParameterType,
				0, // ColumnSize
				0, // DecimalDigits
				&Param,	// ParameterValuePtr - context
				0, // Buffer length
				StrLen_or_IndPtr), SQL_HANDLE_STMT, m_handles.m_hstmt);
		}
		else
		{
			IinfConnection::Check(g_infAPI.SQLBindParameter(
				m_handles.m_hstmt,
				(SQLUSMALLINT)(i+1), InputOutputType,
				ValueType,
				ParameterType,
				ColumnSize,
				0,	// DecimalDigits
				ParameterValuePtr,
				BufferLength,
				StrLen_or_IndPtr), SQL_HANDLE_STMT, m_handles.m_hstmt);
		}
	}
}

/*virtual */
void IinfCursor::Execute(
	int nPlaceHolderCount,
	saPlaceHolder **ppPlaceHolders)
{
	if(nPlaceHolderCount)
		Bind(nPlaceHolderCount, ppPlaceHolders);

	SQLRETURN rc;
	IinfConnection::Check(g_infAPI.SQLFreeStmt(m_handles.m_hstmt, SQL_CLOSE), SQL_HANDLE_STMT, m_handles.m_hstmt);

	rc = g_infAPI.SQLExecute(m_handles.m_hstmt);

	if(rc != SQL_NEED_DATA)
	{
		if(rc != SQL_NO_DATA)
			IinfConnection::Check(rc, SQL_HANDLE_STMT, m_handles.m_hstmt);
	}
	else
		BindLongs();

	ConvertOutputParams();	// if any
}

/*virtual */
void IinfCursor::Cancel()
{
	IinfConnection::Check(g_infAPI.SQLCancel(
		m_handles.m_hstmt), SQL_HANDLE_STMT, m_handles.m_hstmt);
}

/*virtual */
bool IinfCursor::ResultSetExists()
{
	SQLSMALLINT ColumnCount;
	IinfConnection::Check(g_infAPI.SQLNumResultCols(m_handles.m_hstmt, &ColumnCount), SQL_HANDLE_STMT, m_handles.m_hstmt);
	return ColumnCount > 0;
}

/*virtual */
void IinfCursor::DescribeFields(
	DescribeFields_cb_t fn)
{
	SQLSMALLINT ColumnCount;
	IinfConnection::Check(g_infAPI.SQLNumResultCols(m_handles.m_hstmt, &ColumnCount), SQL_HANDLE_STMT, m_handles.m_hstmt);

	for(SQLSMALLINT nField = 1; nField <= ColumnCount; ++nField)
	{
		SQLCHAR sColName[1024];
		SQLSMALLINT nColLen;
		SQLSMALLINT DataType;
		SQLUINTEGER ColumnSize;
		SQLSMALLINT Nullable;
		SQLSMALLINT DecimalDigits;

		IinfConnection::Check(g_infAPI.SQLDescribeCol(
			m_handles.m_hstmt,
			nField,
			sColName,
			sizeof(sColName),
			&nColLen,
			&DataType,
			&ColumnSize,
			&DecimalDigits,
			&Nullable), SQL_HANDLE_STMT, m_handles.m_hstmt);

		(m_pCommand->*fn)(
			SAString((const char*)sColName, nColLen),
			CnvtNativeToStd(DataType, ColumnSize, DecimalDigits),
			(int)DataType,
			ColumnSize,
			ColumnSize,
			DecimalDigits,
			Nullable == SQL_NO_NULLS);
	}
}

/*virtual */
long IinfCursor::GetRowsAffected()
{
	assert(m_handles.m_hstmt != NULL);

	SQLINTEGER RowCount = -1;

	IinfConnection::Check(g_infAPI.SQLRowCount(m_handles.m_hstmt, &RowCount), SQL_HANDLE_STMT, m_handles.m_hstmt);
	return RowCount;
}

/*virtual */
unsigned int IinfCursor::OutputBufferSize(
	SADataType_t eDataType,
	unsigned int nDataSize) const
{
	switch(eDataType)
	{
	case SA_dtBool:
		return sizeof(unsigned char);	// SQL_C_BIT
	case SA_dtNumeric:
		return sizeof(SQL_NUMERIC_STRUCT);	// SQL_C_NUMERIC
	case SA_dtString:
		return nDataSize+1;	// always allocate space for NULL
	case SA_dtDateTime:
		return sizeof(TIMESTAMP_STRUCT);
	case SA_dtLongBinary:
	case SA_dtLongChar:
		return 0;
	default:
		break;
	}

	return ISACursor::OutputBufferSize(eDataType, nDataSize);
}

/*virtual */
void IinfCursor::SetFieldBuffer(
	int nCol,	// 1-based
	void *pInd,
	unsigned int nIndSize,
	void * /*pSize*/,
	unsigned int/* nSizeSize*/,
	void *pValue,
	unsigned int nBufSize)
{
	assert(nIndSize == sizeof(SQLINTEGER));
	if(nIndSize != sizeof(SQLINTEGER))
		return;

	SAField &Field = m_pCommand->Field(nCol);

	SQLSMALLINT TargetType = CnvtStdToNativeValueType(Field.FieldType());
	bool bLong = false;
	switch(Field.FieldType())
	{
	case SA_dtUnknown:
		throw SAException(SA_Library_Error, -1, -1, IDS_UNKNOWN_COLUMN_TYPE, (const char*)Field.Name());
	case SA_dtBool:
		assert(nBufSize == sizeof(unsigned char));
		break;
	case SA_dtShort:
		assert(nBufSize == sizeof(short));
		break;
	case SA_dtLong:
		assert(nBufSize == sizeof(long));
		break;
	case SA_dtDouble:
		assert(nBufSize == sizeof(double));
		break;
	case SA_dtNumeric:
		assert(nBufSize == sizeof(SQL_NUMERIC_STRUCT));
		break;
	case SA_dtDateTime:
		assert(nBufSize == sizeof(TIMESTAMP_STRUCT));
		break;
	case SA_dtBytes:
		assert(nBufSize == (unsigned int)Field.FieldSize());
		break;
	case SA_dtString:
		assert(nBufSize == (unsigned int)Field.FieldSize()+1);
		break;
	case SA_dtLongBinary:
		assert(nBufSize == 0);
		bLong = true;
		break;
	case SA_dtLongChar:
		assert(nBufSize == 0);
		bLong = true;
		break;
	default:
		TargetType = 0;
		assert(false);	// unknown type
	}

	if(!bLong)
		IinfConnection::Check(g_infAPI.SQLBindCol(
			m_handles.m_hstmt,
			(SQLUSMALLINT)nCol,
			TargetType,
			pValue,
			nBufSize,
			(SQLINTEGER*)pInd), SQL_HANDLE_STMT, m_handles.m_hstmt);
}

/*virtual */
void IinfCursor::SetSelectBuffers()
{
	// use default helpers
	AllocSelectBuffer(sizeof(SQLINTEGER), 0);
}

/*virtual */
bool IinfCursor::IndicatorIsNull(
	int nPos,	// 1-based
	SAValueRead &vr,
	ValueType_t eValueType,
	void *pInd, unsigned int nIndSize,
	void * /*pSize*/, unsigned int/* nSizeSize*/,
	unsigned int &nRealSize,
	int/* nBulkReadingBufPos*/) const
{
	assert(nIndSize == sizeof(SQLINTEGER));
	if(nIndSize != sizeof(SQLINTEGER))
		return true;

	if(*(SQLINTEGER*)pInd >= 0)
		nRealSize = *(SQLINTEGER*)pInd;

	bool bLong = false;
	SQLSMALLINT TargetType = 0;
	SQLINTEGER StrLen_or_IndPtr;
	bool bAddSpaceForNull = false;

	SADataType_t eDataType;
	switch(eValueType)
	{
	case ISA_FieldValue:
		eDataType = ((SAField&)vr).FieldType();
		break;
	default:
		assert(eValueType == ISA_ParamValue);
		eDataType = ((SAParam&)vr).ParamType();
	}
	switch(eDataType)
	{
	case SA_dtLongBinary:
		bLong = true;
		TargetType = SQL_C_BINARY;
		bAddSpaceForNull = false;
		break;
	case SA_dtLongChar:
		bLong = true;
		TargetType = SQL_C_CHAR;
		bAddSpaceForNull = true;
		break;
	default:
		break;
	}

	if(bLong)
	{
		// also try to get long size
		nRealSize = 0;
		char Buf[1];
		IinfConnection::Check(g_infAPI.SQLGetData(
			m_handles.m_hstmt, (SQLUSMALLINT)nPos,
			TargetType, Buf, bAddSpaceForNull? 1:0,
			&StrLen_or_IndPtr), SQL_HANDLE_STMT, m_handles.m_hstmt);
		if(StrLen_or_IndPtr >= 0)
			nRealSize = StrLen_or_IndPtr;

		return StrLen_or_IndPtr == SQL_NULL_DATA;
	}

	return *(SQLINTEGER*)pInd == SQL_NULL_DATA;
}

/*virtual */
bool IinfCursor::FetchNext()
{
	SQLRETURN rc = g_infAPI.SQLFetch(m_handles.m_hstmt);
	if(rc != SQL_NO_DATA)
	{
		IinfConnection::Check(rc, SQL_HANDLE_STMT, m_handles.m_hstmt);

		// use default helpers
		ConvertSelectBufferToFields(0);
	}

	return rc != SQL_NO_DATA;
}

/*virtual */
void IinfCursor::ReadLongOrLOB(
	ValueType_t eValueType,
	SAValueRead &vr,
	void * /*pValue*/,
	unsigned int/* nBufSize*/,
	saLongOrLobReader_t fnReader,
	unsigned int nReaderWantedPieceSize,
	void *pAddlData)
{
	if(eValueType == ISA_FieldValue)
	{
		SAField &Field = (SAField &)vr;

		SQLSMALLINT TargetType;
		SQLINTEGER StrLen_or_IndPtr;
		SQLRETURN rc;
		bool bAddSpaceForNull;

		switch(Field.FieldType())
		{
		case SA_dtLongBinary:
			TargetType = SQL_C_BINARY;
			bAddSpaceForNull = false;
			break;
		case SA_dtLongChar:
			TargetType = SQL_C_CHAR;
			bAddSpaceForNull = true;
			break;
		default:
			TargetType = 0;
			bAddSpaceForNull = false;
			assert(false);
		}

		// try to get long size
		unsigned int nLongSize = 0;
		char Buf[1];
		rc = g_infAPI.SQLGetData(
			m_handles.m_hstmt, (SQLUSMALLINT)Field.Pos(),
			TargetType, Buf, bAddSpaceForNull? 1:0,
			&StrLen_or_IndPtr);
		if(rc != SQL_NO_DATA)
		{
			IinfConnection::Check(rc, SQL_HANDLE_STMT, m_handles.m_hstmt);
			if(StrLen_or_IndPtr >= 0)
				nLongSize = StrLen_or_IndPtr;
		}
		
		unsigned char* pBuf;
		unsigned int nPortionSize = vr.PrepareReader(
			nLongSize,
			IinfConnection::MaxLongAtExecSize,
			pBuf,
			fnReader,
			nReaderWantedPieceSize,
			pAddlData,
			bAddSpaceForNull);
		assert(nPortionSize <= IinfConnection::MaxLongAtExecSize);

		SAPieceType_t ePieceType = SA_FirstPiece;
		unsigned int nTotalRead = 0;
		do
		{
			if(nLongSize)	// known
				nPortionSize = sa_min(nPortionSize, nLongSize - nTotalRead);

			rc = g_infAPI.SQLGetData(
				m_handles.m_hstmt, (SQLUSMALLINT)Field.Pos(),
				TargetType, pBuf, nPortionSize + (bAddSpaceForNull? 1:0),
				&StrLen_or_IndPtr);
			assert(nPortionSize || rc == SQL_NO_DATA);

			if(rc != SQL_NO_DATA)
			{
				IinfConnection::Check(rc, SQL_HANDLE_STMT, m_handles.m_hstmt);
				unsigned int NumBytes =
					((StrLen_or_IndPtr > (int)nPortionSize) || (StrLen_or_IndPtr == SQL_NO_TOTAL))? nPortionSize : StrLen_or_IndPtr;
				nTotalRead += NumBytes;
				vr.InvokeReader(ePieceType, pBuf, NumBytes);
			}
            else
            {
                ePieceType = SA_LastPiece;
                vr.InvokeReader(ePieceType, pBuf, 0);
            }

			if(ePieceType == SA_FirstPiece)
				ePieceType = SA_NextPiece;
		}
		while(rc != SQL_NO_DATA);
	}
	else
	{
		assert(eValueType == ISA_ParamValue);
		assert(false);
	}
}

/*virtual */
void IinfCursor::DescribeParamSP()
{
	SAString sText = m_pCommand->CommandText();
	SAString sSchemaName;
	SAString sProcName;

	int n = sText.Find('.');
	sSchemaName = sText.Left(n);
	sProcName = sText.Mid(n+1);

	SACommand cmd(m_pISAConnection->getSAConnection());
	cmd.Open();
	infCommandHandles *pHandles = (infCommandHandles *)cmd.NativeHandles();

	IinfConnection::Check(g_infAPI.SQLProcedureColumns(
		pHandles->m_hstmt,
		NULL,
		0,
		sSchemaName.IsEmpty()? (SQLCHAR *)SQL_ALL_SCHEMAS : (SQLCHAR *)(const char*)sSchemaName,
		SQL_NTS,
		(SQLCHAR *)(const char*)sProcName,
		SQL_NTS,
		(SQLCHAR *)NULL,
		0), SQL_HANDLE_STMT, pHandles->m_hstmt);

	while(cmd.FetchNext())
	{
//		SAString sCat = cmd.Field(1);		// "PROCEDURE_CAT"
//		SAString sSchem = cmd.Field(2);		// "PROCEDURE_SCHEM"
//		SAString sProc = cmd.Field(3);		// "PROCEDURE_NAME"
		SAString sCol = cmd.Field(4);		// "COLUMN_NAME"
		short nColType = cmd.Field(5);		// "COLUMN_TYPE"
		short nDataType = cmd.Field(6);		// "DATA_TYPE"
//		SAString sType = cmd.Field(7);		// "TYPE_NAME"
		long nColSize = cmd.Field(8).isNull()? 0 : (long)cmd.Field(8);		// "COLUMN_SIZE"
//		long nBufferLength = cmd.Field(9).isNull()? 0 : (long)cmd.Field(9);	// "BUFFER_LENGTH"
		short nDecDigits = cmd.Field(10).isNull()? (short)0 : (short)cmd.Field(10);	// "DECIMAL_DIGITS"
//		short nNumPrecPadix = cmd.Field(11).isNull()? 0 : (short)cmd.Field(11);// "NUM_PREC_RADIX"
//		short nNullable = cmd.Field(12).isNull()? 0 : (short)cmd.Field(12);	// "NULLABLE"

		SAParamDirType_t eDirType;
		switch(nColType)
		{
		case SQL_PARAM_INPUT:
			eDirType = SA_ParamInput;
			break;
		case SQL_PARAM_INPUT_OUTPUT:
			eDirType = SA_ParamInputOutput;
			break;
		case SQL_PARAM_OUTPUT:
			eDirType = SA_ParamOutput;
			break;
		case SQL_RETURN_VALUE:
			eDirType = SA_ParamReturn;
			break;
		case SQL_PARAM_TYPE_UNKNOWN:
		case SQL_RESULT_COL:
			continue;
		default:
			assert(false);
			continue;
		}
		SADataType_t eParamType = CnvtNativeToStd(nDataType, nColSize, nDecDigits);

		SAString sParamName;
		if(sCol.IsEmpty())
		{
			assert(eDirType == SA_ParamOutput);
			eDirType = SA_ParamReturn;
			sParamName = "RETURN_VALUE";
		}
		else
			sParamName = sCol;

		m_pCommand->CreateParam(sParamName, eParamType, nDataType, nColSize, nColSize, nDecDigits, eDirType);
	}
}

/*virtual */
saAPI *IinfConnection::NativeAPI() const
{
	return &g_infAPI;
}

/*virtual */
saConnectionHandles *IinfConnection::NativeHandles()
{
	return &m_handles;
}

/*virtual */
saCommandHandles *IinfCursor::NativeHandles()
{
	return &m_handles;
}

/*virtual */
void IinfConnection::setIsolationLevel(
	SAIsolationLevel_t eIsolationLevel)
{
	Commit();

	issueIsolationLevel(eIsolationLevel);
}

void IinfConnection::SafeSetConnectOption(
	SQLINTEGER Attribute,
	SQLPOINTER ValuePtr,
	SQLINTEGER StringLength)
{
	if(g_infAPI.SQLSetConnectAttr)
		Check(g_infAPI.SQLSetConnectAttr(
			m_handles.m_hdbc,
			Attribute,
			ValuePtr, StringLength), SQL_HANDLE_DBC, m_handles.m_hdbc);
	else{}
		/*Check(g_infAPI.SQLSetConnectOption(
			m_handles.m_hdbc,
			SQLUSMALLINT(Attribute),
			SQLUINTEGER(ValuePtr)), SQL_HANDLE_DBC, m_handles.m_hdbc); */
}

void IinfConnection::issueIsolationLevel(
	SAIsolationLevel_t eIsolationLevel)
{
	long isolation;
	switch(eIsolationLevel)
	{
	case SA_ReadUncommitted:
		isolation = SQL_TXN_READ_UNCOMMITTED;
		break;
	case SA_ReadCommitted:
		isolation = SQL_TXN_READ_COMMITTED;
		break;
	case SA_RepeatableRead:
		isolation = SQL_TXN_REPEATABLE_READ;
		break;
	case SA_Serializable:
		isolation = SQL_TXN_SERIALIZABLE;
		break;
	default:
		assert(false);
		return;
	}

	SafeSetConnectOption(
		SQL_ATTR_TXN_ISOLATION,
		SQLPOINTER(isolation), 0);
}

/*virtual */
void IinfConnection::setAutoCommit(
	SAAutoCommit_t eAutoCommit)
{
	SQLUINTEGER nAutoCommit;
	switch(eAutoCommit)
	{
	case SA_AutoCommitOff:
		nAutoCommit = SQL_AUTOCOMMIT_OFF;
		break;
	case SA_AutoCommitOn:
		nAutoCommit = SQL_AUTOCOMMIT_ON;
		break;
	default:
		assert(false);
		return;
	}

	SafeSetConnectOption(
		SQL_ATTR_AUTOCOMMIT,
		SQLPOINTER(nAutoCommit), 0);
}

/*virtual */
void IinfConnection::CnvtInternalToNumeric(
	SANumeric &numeric,
	const void *pInternal,
	int nInternalSize)
{
	if(nInternalSize != sizeof(SQL_NUMERIC_STRUCT))
	{
		assert(false);
		return;
	}

	SQL_NUMERIC_STRUCT *pSQL_NUMERIC_STRUCT = (SQL_NUMERIC_STRUCT *)pInternal;
	numeric.precision = pSQL_NUMERIC_STRUCT->precision;
	numeric.scale = pSQL_NUMERIC_STRUCT->scale;
	// set sign
	// Informix: 1 if positive, 0 if negative
	// SQLAPI: 1 if positive, 0 if negative
	numeric.sign = pSQL_NUMERIC_STRUCT->sign;
	// copy mantissa
	// Informix: little endian format
	// SQLAPI: little endian format
	memset(numeric.val, 0, sizeof(numeric.val));
	memcpy(
		numeric.val,
		pSQL_NUMERIC_STRUCT->val,
		sa_min(sizeof(numeric.val), sizeof(pSQL_NUMERIC_STRUCT->val)));
}
