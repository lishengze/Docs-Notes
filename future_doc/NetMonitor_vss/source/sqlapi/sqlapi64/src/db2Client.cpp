// db2Client.cpp: implementation of the Idb2Client class.
//
//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>

#include <SQLAPI.h>
#include "db2Client.h"

#include <assert.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>	// strtol
 
#include <db2API.h>
#include "samisc.h"
#include "errmsg.h"

//////////////////////////////////////////////////////////////////////
// Idb2Connection Class
//////////////////////////////////////////////////////////////////////

class Idb2Connection : public ISAConnection
{
	enum
	{
		MaxLongAtExecSize = 0x7fffffff+SQL_LEN_DATA_AT_EXEC(0)
	};
	friend class Idb2Cursor;

	db2ConnectionHandles m_handles;

	static void Check(
		SQLRETURN return_code,
		SQLSMALLINT HandleType,
		SQLHANDLE Handle);
	SQLINTEGER LenDataAtExec();
	void issueIsolationLevel(
		SAIsolationLevel_t eIsolationLevel);

	static SADataType_t CnvtNativeToStd(
		int nNativeType,
		SQLUINTEGER ColumnSize,
		int nPrec,
		int nScale);
	static SQLSMALLINT CnvtStdToNative(
		SADataType_t eDataType);
	static SQLSMALLINT CnvtStdToNativeValueType(
		SADataType_t eDataType);

	static void CnvtNumericToInternal(
		const SANumeric &numeric,
		SQL_NUMERIC_STRUCT &Internal);
	static void CnvtInternalToDateTime(
		SADateTime &date_time,
		const TIMESTAMP_STRUCT &Internal);
	static void CnvtDateTimeToInternal(
		const SADateTime &date_time,
		TIMESTAMP_STRUCT &Internal);

protected:
	virtual ~Idb2Connection();

public:
	Idb2Connection(SAConnection *pSAConnection);

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

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Idb2Connection::Idb2Connection(
	SAConnection *pSAConnection) : ISAConnection(pSAConnection)
{
}

Idb2Connection::~Idb2Connection()
{
}

/*virtual */
void Idb2Connection::InitializeClient()
{
	::AddDB2Support();
}

/*virtual */
void Idb2Connection::UnInitializeClient()
{
	::ReleaseDB2Support();
}

SQLINTEGER Idb2Connection::LenDataAtExec()
{
	SQLSMALLINT retlen = 0;
	char szValue[10];
	Check(g_db2API.SQLGetInfo(
		m_handles.m_hdbc, SQL_NEED_LONG_DATA_LEN, szValue, sizeof(szValue), &retlen), SQL_HANDLE_DBC, m_handles.m_hdbc);
	if(retlen > 0 && (*szValue == 'Y' || *szValue == 'y'))
		return SQL_LEN_DATA_AT_EXEC(MaxLongAtExecSize);

	return SQL_DATA_AT_EXEC;
}

/*virtual */
void Idb2Connection::CnvtInternalToDateTime(
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
void Idb2Connection::CnvtInternalToDateTime(
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
void Idb2Connection::CnvtDateTimeToInternal(
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
void Idb2Connection::CnvtInternalToCursor(
	SACommand * /*pCursor*/,
	const void * /*pInternal*/)
{
	assert(false);
}

/*virtual */
long Idb2Connection::GetClientVersion() const
{
	if(g_nDB2DLLVersionLoaded == 0)	// has not been detected
	{
		if(IsConnected())
		{
			char sInfoValue[1024];
			SQLSMALLINT cbInfoValue;
			g_db2API.SQLGetInfo(m_handles.m_hdbc, SQL_DRIVER_VER, sInfoValue, sizeof(sInfoValue), &cbInfoValue);
			sInfoValue[cbInfoValue] = 0;

			char *sPoint;
			short nMajor = (short)strtol(sInfoValue, &sPoint, 10);
			assert(*sPoint == '.');

			sPoint++;
			short nMinor = (short)strtol(sPoint, &sPoint, 10);
			return SA_MAKELONG(nMinor, nMajor);
		}
	}

	return g_nDB2DLLVersionLoaded;
}

/*virtual */
long Idb2Connection::GetServerVersion() const
{
	char sInfoValue[1024];
	SQLSMALLINT cbInfoValue;
	g_db2API.SQLGetInfo(m_handles.m_hdbc, SQL_DBMS_VER, sInfoValue, sizeof(sInfoValue), &cbInfoValue);
	sInfoValue[cbInfoValue] = 0;

	char *sPoint;
	short nMajor = (short)strtol(sInfoValue, &sPoint, 10);
	assert(*sPoint == '.');
	sPoint++;
	short nMinor = (short)strtol(sPoint, &sPoint, 10);
	return SA_MAKELONG(nMinor, nMajor);
}

/*virtual */
SAString Idb2Connection::GetServerVersionString() const
{
	char sInfoValue[1024];
	SQLSMALLINT cbInfoValue;
	g_db2API.SQLGetInfo(m_handles.m_hdbc, SQL_DBMS_NAME, sInfoValue, sizeof(sInfoValue), &cbInfoValue);

	SAString s(sInfoValue, cbInfoValue);
	s += " Release ";

	g_db2API.SQLGetInfo(m_handles.m_hdbc, SQL_DBMS_VER, sInfoValue, sizeof(sInfoValue), &cbInfoValue);
	s += SAString(sInfoValue, cbInfoValue);

	return s;
}

/*static */
void Idb2Connection::Check(
	SQLRETURN return_code,
	SQLSMALLINT HandleType,
	SQLHANDLE Handle)
{
	if(return_code == SQL_SUCCESS)
		return;
	if(return_code == SQL_SUCCESS_WITH_INFO)
		return;

	SQLCHAR Sqlstate[5+1];
	SQLINTEGER NativeError;
	char sMsg[4096] = "";
	SQLSMALLINT TextLength;

	SQLRETURN rc = g_db2API.SQLGetDiagRec(HandleType, Handle, 1, 
		Sqlstate, &NativeError,
		(SQLCHAR *)sMsg, sizeof(sMsg), &TextLength);
	assert(rc == SQL_SUCCESS);
	if(rc != SQL_SUCCESS)
		throw SAException(
			SA_DBMS_API_Error,
			return_code, -1,
			"rc != SQL_SUCCESS");

	throw SAException(
		SA_DBMS_API_Error,
		NativeError, -1,
		"%s", sMsg);
}

/*virtual */
bool Idb2Connection::IsConnected() const
{
	return m_handles.m_hdbc != 0;
}

/*virtual */
void Idb2Connection::Connect(
	const SAString &sDBString,
	const SAString &sUserID,
	const SAString &sPassword)
{
	assert(!m_handles.m_hevn);
	assert(!m_handles.m_hdbc);

	g_db2API.SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &m_handles.m_hevn);
	assert(m_handles.m_hevn);
	try
	{
		Check(g_db2API.SQLSetEnvAttr(m_handles.m_hevn, SQL_ATTR_ODBC_VERSION, SQLPOINTER(SQL_OV_ODBC3), 0), SQL_HANDLE_ENV, m_handles.m_hevn);

		Check(g_db2API.SQLAllocHandle(SQL_HANDLE_DBC, m_handles.m_hevn, &m_handles.m_hdbc), SQL_HANDLE_ENV, m_handles.m_hevn);
		if(sDBString.Find('=') == -1)	// it's not a valid connection string, but it can be DSN name
			Check(g_db2API.SQLConnect(m_handles.m_hdbc, 
				(SQLCHAR *)(const char*)sDBString, SQL_NTS,
				(SQLCHAR *)(const char*)sUserID, SQL_NTS,
				(SQLCHAR *)(const char*)sPassword, SQL_NTS),
				SQL_HANDLE_DBC, m_handles.m_hdbc);
		else
			Check(g_db2API.SQLDriverConnect(
				m_handles.m_hdbc, NULL,
				(SQLCHAR *)(const char*)sDBString, SQL_NTS, NULL, 0, 0, SQL_DRIVER_NOPROMPT),
				SQL_HANDLE_DBC, m_handles.m_hdbc);
	}
	catch(SAException &)
	{
		// clean up
		if(m_handles.m_hdbc)
		{
			g_db2API.SQLFreeHandle(SQL_HANDLE_DBC, m_handles.m_hdbc);
			m_handles.m_hdbc = (SQLHDBC)NULL;
		}
		if(m_handles.m_hevn)
		{
			g_db2API.SQLFreeHandle(SQL_HANDLE_ENV, m_handles.m_hevn);
			m_handles.m_hevn = (SQLHENV)NULL;
		}

		throw;
	}
}

/*virtual */
void Idb2Connection::Disconnect()
{
	assert(m_handles.m_hevn);
	assert(m_handles.m_hdbc);

	Check(g_db2API.SQLDisconnect(m_handles.m_hdbc), SQL_HANDLE_DBC, m_handles.m_hdbc);
	Check(g_db2API.SQLFreeHandle(SQL_HANDLE_DBC, m_handles.m_hdbc), SQL_HANDLE_DBC, m_handles.m_hdbc);
	m_handles.m_hdbc = (SQLHDBC)NULL;
	Check(g_db2API.SQLFreeHandle(SQL_HANDLE_ENV, m_handles.m_hevn), SQL_HANDLE_ENV, m_handles.m_hevn);
	m_handles.m_hevn = (SQLHENV)NULL;
}

/*virtual */
void Idb2Connection::Commit()
{
	Check(g_db2API.SQLEndTran(SQL_HANDLE_DBC, m_handles.m_hdbc, SQL_COMMIT), SQL_HANDLE_DBC, m_handles.m_hdbc);
}

/*virtual */
void Idb2Connection::Rollback()
{
	Check(g_db2API.SQLEndTran(SQL_HANDLE_DBC, m_handles.m_hdbc, SQL_ROLLBACK), SQL_HANDLE_DBC, m_handles.m_hdbc);
}

//////////////////////////////////////////////////////////////////////
// Idb2Client Class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Idb2Client::Idb2Client()
{

}

Idb2Client::~Idb2Client()
{

}

ISAConnection *Idb2Client::QueryConnectionInterface(
	SAConnection *pSAConnection)
{
	return new Idb2Connection(pSAConnection);
}

//////////////////////////////////////////////////////////////////////
// Idb2Cursor Class
//////////////////////////////////////////////////////////////////////

class Idb2Cursor : public ISACursor
{
	db2CommandHandles	m_handles;

	SQLUINTEGER m_cRowsToPrefetch;	// defined in SetSelectBuffers
	SQLUINTEGER m_cRowsObtained;
	SQLUINTEGER m_cRowCurrent;

	SAString CallSubProgramSQL();

	void BindLongs();

	bool m_bResultSetCanBe;

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
	Idb2Cursor(
		Idb2Connection *pIdb2Connection,
		SACommand *pCommand);
	virtual ~Idb2Cursor();

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


Idb2Cursor::Idb2Cursor(
	Idb2Connection *pIdb2Connection,
	SACommand *pCommand) :
	ISACursor(pIdb2Connection, pCommand)
{
	m_bResultSetCanBe = false;
}

/*virtual */
Idb2Cursor::~Idb2Cursor()
{
}

/*virtual */
unsigned int Idb2Cursor::InputBufferSize(
	const SAParam &Param) const
{
	if(!Param.isNull())
	{
		switch(Param.DataType())
		{
		case SA_dtBool:
			return sizeof(unsigned char);	// SQL_C_BIT
		case SA_dtNumeric:
			return sizeof(SQL_NUMERIC_STRUCT);	// SQL_C_NUMERIC
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

/*static */
SADataType_t Idb2Connection::CnvtNativeToStd(
	int dbtype,
	SQLUINTEGER/* ColumnSize*/,
	int prec,
	int scale)
{
	SADataType_t eDataType = SA_dtUnknown;

	switch(dbtype)
	{
	case SQL_CHAR:		// Character string of fixed length
	case SQL_VARCHAR:	// Variable-length character string
		eDataType = SA_dtString;
		break;
	case SQL_BINARY:
	case SQL_VARBINARY:
		eDataType = SA_dtBytes;
		break;
	case SQL_LONGVARCHAR:	// Variable-length character data
		eDataType = SA_dtLongChar;
		break;
	case SQL_LONGVARBINARY: // Variable-length binary data
		eDataType = SA_dtLongBinary;
		break;
	//case SQL_DECIMAL: zbz
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
			eDataType = SA_dtNumeric;
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
	case SQL_DECIMAL:
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
	case SQL_BLOB:
		eDataType = SA_dtBLob;
		break;
	case SQL_CLOB:
	case SQL_DBCLOB:
		eDataType = SA_dtCLob;
		break;
	default:
		assert(false);
	}

	return eDataType;
}

/*static */
SQLSMALLINT Idb2Connection::CnvtStdToNativeValueType(SADataType_t eDataType)
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
	
	return ValueType;
}

/*static */
SQLSMALLINT Idb2Connection::CnvtStdToNative(SADataType_t eDataType)
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
	case SA_dtNumeric:
		dbtype = SQL_NUMERIC;
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
		dbtype = SQL_LONGVARBINARY;
		break;
	case SA_dtLongChar:
		dbtype = SQL_LONGVARCHAR;
		break;
	case SA_dtBLob:
		dbtype = SQL_BLOB;
		break;
	case SA_dtCLob:
		dbtype = SQL_CLOB;
		break;
	default:
		dbtype = 0;
		assert(false);
	}
	
	return dbtype;
}

/*virtual */
bool Idb2Cursor::IsOpened()
{
	return m_handles.m_hstmt != 0;
}

/*virtual */
void Idb2Cursor::Open()
{
	assert(m_handles.m_hstmt == 0);
	Idb2Connection::Check(
		g_db2API.SQLAllocHandle(SQL_HANDLE_STMT, ((Idb2Connection*)m_pISAConnection)->m_handles.m_hdbc, &m_handles.m_hstmt),
		SQL_HANDLE_DBC, ((Idb2Connection*)m_pISAConnection)->m_handles.m_hdbc);
	assert(m_handles.m_hstmt != 0);
}

/*virtual */
void Idb2Cursor::Close()
{
	assert(m_handles.m_hstmt != 0);
	Idb2Connection::Check(g_db2API.SQLFreeHandle(SQL_HANDLE_STMT, m_handles.m_hstmt), SQL_HANDLE_STMT, m_handles.m_hstmt);
	m_handles.m_hstmt = (SQLHSTMT)NULL;
}

/*virtual */
ISACursor *Idb2Connection::NewCursor(SACommand *m_pCommand)
{
	return new Idb2Cursor(this, m_pCommand);
}

/*virtual */
void Idb2Cursor::Prepare(
	const SAString &sStmt,
	SACommandType_t eCmdType,
	int nPlaceHolderCount,
	saPlaceHolder**	ppPlaceHolders)
{
	SAString sStmtDB2;
	int nPos = 0;
	int i;
	switch(eCmdType)
	{
	case SA_CmdSQLStmt:
		// replace bind variables with '?' place holder
		for(i = 0; i < nPlaceHolderCount; i++)
		{
			sStmtDB2 += sStmt.Mid(nPos, ppPlaceHolders[i]->getStart()-nPos);
			sStmtDB2 += "?";
			nPos = ppPlaceHolders[i]->getEnd() + 1;
		}
		// copy tail
		if(nPos < sStmt.GetLength())
			sStmtDB2 += sStmt.Mid(nPos);
		break;
	case SA_CmdStoredProc:
		sStmtDB2 = CallSubProgramSQL();
		break;
	default:
		assert(false);
	}

	// a bit of clean up
	Idb2Connection::Check(g_db2API.SQLFreeStmt(m_handles.m_hstmt, SQL_CLOSE), SQL_HANDLE_STMT, m_handles.m_hstmt);
	Idb2Connection::Check(g_db2API.SQLFreeStmt(m_handles.m_hstmt, SQL_UNBIND), SQL_HANDLE_STMT, m_handles.m_hstmt);
	Idb2Connection::Check(g_db2API.SQLFreeStmt(m_handles.m_hstmt, SQL_RESET_PARAMS), SQL_HANDLE_STMT, m_handles.m_hstmt);

	Idb2Connection::Check(g_db2API.SQLPrepare(
		m_handles.m_hstmt, (SQLTCHAR*)(const char*)sStmtDB2, SQL_NTS), SQL_HANDLE_STMT, m_handles.m_hstmt);
}

SAString Idb2Cursor::CallSubProgramSQL()
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
	if(!sParams.IsEmpty())
	{
		sSQL += "(";
		sSQL += sParams;
		sSQL += ")";
	}

	sSQL += "}";
	return sSQL;
}

void Idb2Cursor::BindLongs()
{
	SQLRETURN retcode;
	SQLPOINTER ValuePtr;

	try
	{
		while((retcode = g_db2API.SQLParamData(m_handles.m_hstmt, &ValuePtr)) == SQL_NEED_DATA)
		{
			SAParam *pParam = (SAParam *)ValuePtr;
			unsigned int nActualWrite;
			SAPieceType_t ePieceType = SA_FirstPiece;
			void *pBuf;
			while((nActualWrite = pParam->InvokeWriter(
				ePieceType,
				Idb2Connection::MaxLongAtExecSize, pBuf)) != 0)
			{
				Idb2Connection::Check(g_db2API.SQLPutData(
					m_handles.m_hstmt, pBuf, nActualWrite), SQL_HANDLE_STMT, m_handles.m_hstmt);

				if(ePieceType == SA_LastPiece)
					break;
			}
		}
	}
	catch(SAException&)
	{
		g_db2API.SQLCancel(m_handles.m_hstmt);
		throw;
	}

	Idb2Connection::Check(retcode, SQL_HANDLE_STMT, m_handles.m_hstmt);
}

/*virtual */
void Idb2Cursor::UnExecute()
{
	m_bResultSetCanBe = false;
}

void Idb2Cursor::Bind(
		int nPlaceHolderCount,
		saPlaceHolder **ppPlaceHolders)
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
		SQLSMALLINT ParameterType = Idb2Connection::CnvtStdToNative(
			eDataType == SA_dtUnknown? SA_dtString : eDataType);
		SQLSMALLINT ValueType = Idb2Connection::CnvtStdToNativeValueType(
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
				*StrLen_or_IndPtr = SQL_NULL_DATA;			// field is null
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
				case SA_dtNumeric:
					assert(*StrLen_or_IndPtr == (SQLINTEGER)sizeof(SQL_NUMERIC_STRUCT));
					Idb2Connection::CnvtNumericToInternal(
						Param.asNumeric(),
						*(SQL_NUMERIC_STRUCT*)ParameterValuePtr);
					break;
				case SA_dtDateTime:
					assert(*StrLen_or_IndPtr == (SQLINTEGER)sizeof(TIMESTAMP_STRUCT));
					Idb2Connection::CnvtDateTimeToInternal(
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
					assert(false);
				}
			}
		}

		if(isLongOrLob(eDataType))
		{
			*StrLen_or_IndPtr = ((Idb2Connection*)m_pISAConnection)->LenDataAtExec();
			Idb2Connection::Check(g_db2API.SQLBindParameter(
				m_handles.m_hstmt,
				(SQLUSMALLINT)(i+1),
				InputOutputType,
				ValueType,
				ParameterType,
				0, // ColumnSize
				0, // DecimalDigits
				&Param,	// ParameterValuePtr - context
				0, // Buffer length
				StrLen_or_IndPtr), SQL_HANDLE_STMT, m_handles.m_hstmt);
		}
		else if(eDataType == SA_dtNumeric)
		{
			SQLSMALLINT Precision;
			SQLSMALLINT Scale;

			switch(InputOutputType)
			{
				case SQL_PARAM_INPUT:
					// use precision and scale of input data
					Precision = (SQLSMALLINT)Param.asNumeric().precision;
					Scale = (SQLSMALLINT)Param.asNumeric().scale;
					break;
				case SQL_PARAM_OUTPUT:
					// set precision and scale for return value
					Precision = (SQLSMALLINT)Param.ParamPrecision();
					Scale = (SQLSMALLINT)Param.ParamScale();
					break;
				case SQL_PARAM_INPUT_OUTPUT:
					if(Param.isNull())
					{
						// Param is INOUT but we do not really bind anything
						// It allows us to optimize precision and scale for return value
						Precision = (SQLSMALLINT)Param.ParamPrecision();
						Scale = (SQLSMALLINT)Param.ParamScale();
					}
					else
					{
						// Param is INOUT but we have to
						// use the scale of input data
						// Precision is set to fit bigger number
						Precision = (SQLSMALLINT)sa_max(Param.asNumeric().precision, Param.ParamPrecision());
						Scale = (SQLSMALLINT)Param.asNumeric().scale;
					}
					break;
				default:
					assert(false);
					Precision = 0;
					Scale = 0;
			}

			Idb2Connection::Check(g_db2API.SQLBindParameter(
				m_handles.m_hstmt,
				(SQLUSMALLINT)(i+1), InputOutputType,
				ValueType,
				ParameterType,
				Precision,	// ColumnSize
				Scale,		// DecimalDigits
				ParameterValuePtr,
				BufferLength,
				StrLen_or_IndPtr), SQL_HANDLE_STMT, m_handles.m_hstmt);

			// for numeric data we have to adjust precision and scale
			// because:
			// precision deaults to some driver specific value
			// scale defaults to 0

			// Get the application row descriptor
			// for the statement handle using SQLGetStmtAttr
			SQLHDESC hdesc;
			Idb2Connection::Check(g_db2API.SQLGetStmtAttr(
				m_handles.m_hstmt,
				SQL_ATTR_APP_PARAM_DESC,
				&hdesc,
				0, NULL), SQL_HANDLE_STMT, m_handles.m_hstmt);

			Idb2Connection::Check(g_db2API.SQLSetDescRec(
				hdesc,
				(SQLSMALLINT)(i+1),
				ValueType, -1, nDataBufSize,
				Precision,
				Scale,
				pValue,
				(SQLINTEGER*)pInd,
				(SQLINTEGER*)pInd), SQL_HANDLE_DESC, hdesc);
		}
		else
			Idb2Connection::Check(g_db2API.SQLBindParameter(
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

/*virtual */
void Idb2Cursor::Execute(
	int nPlaceHolderCount,
	saPlaceHolder **ppPlaceHolders)
{
	if(nPlaceHolderCount)
		Bind(nPlaceHolderCount, ppPlaceHolders);

	SQLRETURN rc;
	Idb2Connection::Check(g_db2API.SQLFreeStmt(m_handles.m_hstmt, SQL_CLOSE), SQL_HANDLE_STMT, m_handles.m_hstmt);
	rc = g_db2API.SQLExecute(m_handles.m_hstmt);

	if(rc != SQL_NEED_DATA)
	{
		if(rc != SQL_NO_DATA)
			Idb2Connection::Check(rc, SQL_HANDLE_STMT, m_handles.m_hstmt);
	}
	else
		BindLongs();

	m_bResultSetCanBe = true;

	// if SP: in DB2 output parametrs are available
	// immediately after execute
	// even if there are result sets from SP
	ConvertOutputParams();	// if any
}

/*virtual */
void Idb2Cursor::Cancel()
{
	Idb2Connection::Check(g_db2API.SQLCancel(
		m_handles.m_hstmt), SQL_HANDLE_STMT, m_handles.m_hstmt);
}

/*virtual */
bool Idb2Cursor::ResultSetExists()
{
	if(!m_bResultSetCanBe)
		return false;

	SQLSMALLINT ColumnCount;
	Idb2Connection::Check(g_db2API.SQLNumResultCols(m_handles.m_hstmt, &ColumnCount), SQL_HANDLE_STMT, m_handles.m_hstmt);
	return ColumnCount > 0;
}

/*virtual */
void Idb2Cursor::DescribeFields(
	DescribeFields_cb_t fn)
{
	SQLSMALLINT ColumnCount;
	Idb2Connection::Check(g_db2API.SQLNumResultCols(m_handles.m_hstmt, &ColumnCount), SQL_HANDLE_STMT, m_handles.m_hstmt);

	for(SQLSMALLINT nField = 1; nField <= ColumnCount; ++nField)
	{
		SQLCHAR sColName[1024];
		SQLSMALLINT nColLen;
		SQLSMALLINT DataType;
		SQLUINTEGER ColumnSize;
		SQLSMALLINT Nullable;
		SQLSMALLINT DecimalDigits;

		Idb2Connection::Check(g_db2API.SQLDescribeCol(
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
			Idb2Connection::CnvtNativeToStd(DataType, ColumnSize, ColumnSize, DecimalDigits),
			(int)DataType,
			ColumnSize,
			ColumnSize,
			DecimalDigits,
			Nullable == SQL_NO_NULLS);
	}
}

/*virtual */
long Idb2Cursor::GetRowsAffected()
{
	assert(m_handles.m_hstmt != 0);

	SQLINTEGER RowCount = -1;

	Idb2Connection::Check(g_db2API.SQLRowCount(m_handles.m_hstmt, &RowCount), SQL_HANDLE_STMT, m_handles.m_hstmt);
	return RowCount;
}

/*virtual */
unsigned int Idb2Cursor::OutputBufferSize(
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
	case SA_dtBLob:
	case SA_dtCLob:
		return 0;
	default:
		break;
	}

	return ISACursor::OutputBufferSize(eDataType, nDataSize);
}

/*virtual */
void Idb2Cursor::SetFieldBuffer(
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

	SQLSMALLINT TargetType = Idb2Connection::CnvtStdToNativeValueType(Field.FieldType());
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
	case SA_dtBLob:
		assert(nBufSize == 0);
		bLong = true;
		break;
	case SA_dtCLob:
		assert(nBufSize == 0);
		bLong = true;
		break;
	default:
		assert(false);	// unknown type
	}

	if(!bLong)
	{
		Idb2Connection::Check(g_db2API.SQLBindCol(
			m_handles.m_hstmt,
			(SQLUSMALLINT)nCol,
			TargetType,
			pValue,
			nBufSize,
			(SQLINTEGER*)pInd), SQL_HANDLE_STMT, m_handles.m_hstmt);

		// for numeric data we have to adjust precision and scale
		// because:
		// precision deaults to some driver specific value
		// scale defaults to 0
		if(Field.FieldType() == SA_dtNumeric)
		{
			// Get the application row descriptor
			// for the statement handle using SQLGetStmtAttr
			SQLHDESC hdesc;
			Idb2Connection::Check(g_db2API.SQLGetStmtAttr(
				m_handles.m_hstmt,
				SQL_ATTR_APP_ROW_DESC,
				&hdesc,
				0, NULL), SQL_HANDLE_STMT, m_handles.m_hstmt);

			Idb2Connection::Check(g_db2API.SQLSetDescRec(
				hdesc,
				(SQLSMALLINT)nCol,
				TargetType,
				-1,
				nBufSize,
				(SQLSMALLINT)Field.FieldPrecision(),
				(SQLSMALLINT)Field.FieldScale(),
				pValue,
				(SQLINTEGER*)pInd,
				(SQLINTEGER*)pInd), SQL_HANDLE_DESC, hdesc);
		}
	}
}

/*virtual */
void Idb2Cursor::SetSelectBuffers()
{
	SAString sOption = m_pCommand->Option(
		"PreFetchRows");
	if(!sOption.IsEmpty())
	{
		int cLongs = FieldCount(4, SA_dtLongBinary, SA_dtLongChar, SA_dtBLob, SA_dtCLob);
		if(cLongs)	// do not use bulk fetch if there are text or image columns
			m_cRowsToPrefetch = 1;
		else
			m_cRowsToPrefetch = atol(sOption);
	}
	else
		m_cRowsToPrefetch = 1;
	m_cRowsObtained = 0;
	m_cRowCurrent = 0;

	// set the SQL_ATTR_ROW_BIND_TYPE statement attribute to use
	// column-wise binding.
	Idb2Connection::Check(
		g_db2API.SQLSetStmtAttr(m_handles.m_hstmt, SQL_ATTR_ROW_BIND_TYPE, SQL_BIND_BY_COLUMN, 0),
		SQL_HANDLE_STMT, m_handles.m_hstmt);
	// Declare the rowset size with the SQL_ATTR_ROW_ARRAY_SIZE
	// statement attribute.
	Idb2Connection::Check(
		g_db2API.SQLSetStmtAttr(m_handles.m_hstmt, SQL_ATTR_ROW_ARRAY_SIZE, SQLPOINTER(m_cRowsToPrefetch), 0),
		SQL_HANDLE_STMT, m_handles.m_hstmt);
	// Set the SQL_ATTR_ROWS_FETCHED_PTR statement attribute
	// to point to m_cRowsObtained
	Idb2Connection::Check(
		g_db2API.SQLSetStmtAttr(m_handles.m_hstmt, SQL_ATTR_ROWS_FETCHED_PTR, &m_cRowsObtained, 0),
		SQL_HANDLE_STMT, m_handles.m_hstmt);

	// use default helpers
	AllocSelectBuffer(sizeof(SQLINTEGER), 0, m_cRowsToPrefetch);
}

/*virtual */
bool Idb2Cursor::IndicatorIsNull(
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
	case SA_dtBLob:
		bLong = true;
		TargetType = SQL_C_BINARY;
		bAddSpaceForNull = false;
		break;
	case SA_dtLongChar:
	case SA_dtCLob:
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
		Idb2Connection::Check(g_db2API.SQLGetData(
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
bool Idb2Cursor::FetchNext()
{
	if(m_cRowCurrent == m_cRowsObtained)
	{
		SQLRETURN rc = g_db2API.SQLFetchScroll(
			m_handles.m_hstmt, SQL_FETCH_NEXT, 0);
		if(rc != SQL_NO_DATA)
			Idb2Connection::Check(rc, SQL_HANDLE_STMT, m_handles.m_hstmt);
		else
		{
			assert(m_cRowsObtained == 0);
			m_cRowsObtained = 0;	// to be sure
		}

		m_cRowCurrent = 0;
	}

	if(m_cRowsObtained)
	{
		// use default helpers
		ConvertSelectBufferToFields(m_cRowCurrent++);
	}
	else
	{
		SQLRETURN rcMoreResults = g_db2API.SQLMoreResults(
			m_handles.m_hstmt);
				
		if(rcMoreResults != SQL_NO_DATA)
			Idb2Connection::Check(rcMoreResults, SQL_HANDLE_STMT, m_handles.m_hstmt);
		else
			m_bResultSetCanBe = false;
	}

	return m_cRowsObtained != 0;
}

/*virtual */
void Idb2Cursor::ReadLongOrLOB(
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
		case SA_dtBLob:
			TargetType = SQL_C_BINARY;
			bAddSpaceForNull = false;
			break;
		case SA_dtLongChar:
		case SA_dtCLob:
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
		rc = g_db2API.SQLGetData(
			m_handles.m_hstmt, (SQLUSMALLINT)Field.Pos(),
			TargetType, Buf, bAddSpaceForNull? 1:0,
			&StrLen_or_IndPtr);
		if(rc != SQL_NO_DATA)
		{
			Idb2Connection::Check(rc, SQL_HANDLE_STMT, m_handles.m_hstmt);
			if(StrLen_or_IndPtr >= 0)
				nLongSize = StrLen_or_IndPtr;
		}
		
		unsigned char* pBuf;
		unsigned int nPortionSize = vr.PrepareReader(
			nLongSize,
			Idb2Connection::MaxLongAtExecSize,
			pBuf,
			fnReader,
			nReaderWantedPieceSize,
			pAddlData,
			bAddSpaceForNull);
		assert(nPortionSize <= Idb2Connection::MaxLongAtExecSize);

		SAPieceType_t ePieceType = SA_FirstPiece;
		unsigned int nTotalRead = 0;
		do
		{
			if(nLongSize)	// known
				nPortionSize = sa_min(nPortionSize, nLongSize - nTotalRead);

			rc = g_db2API.SQLGetData(
				m_handles.m_hstmt, (SQLUSMALLINT)Field.Pos(),
				TargetType, pBuf, nPortionSize + (bAddSpaceForNull? 1:0),
				&StrLen_or_IndPtr);
			assert(nPortionSize || rc == SQL_NO_DATA);

			if(rc != SQL_NO_DATA)
			{
				Idb2Connection::Check(rc, SQL_HANDLE_STMT, m_handles.m_hstmt);
				int NumBytes =
					((StrLen_or_IndPtr > (int)nPortionSize) || (StrLen_or_IndPtr == SQL_NO_TOTAL))? nPortionSize : StrLen_or_IndPtr;
				assert(NumBytes >= 0);
				nTotalRead += NumBytes;
				vr.InvokeReader(ePieceType, pBuf, (unsigned int)NumBytes);
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
void Idb2Cursor::DescribeParamSP()
{
	SAString sText = m_pCommand->CommandText();
	SAString sSchemaName;
	SAString sProcName;

	int n = sText.Find('.');
	sSchemaName = sText.Left(n);
	sProcName = sText.Mid(n+1);

	SACommand cmd(m_pISAConnection->getSAConnection());
	cmd.Open();
	db2CommandHandles *pHandles = (db2CommandHandles *)cmd.NativeHandles();

	Idb2Connection::Check(g_db2API.SQLProcedureColumns(
		pHandles->m_hstmt,
		NULL,
		0,
		sSchemaName.IsEmpty()? (SQLCHAR *)SQL_ALL_SCHEMAS : (SQLCHAR *)(const char*)sSchemaName,
		SQL_NTS,
		(SQLCHAR *)(const char*)sProcName,
		SQL_NTS,
		(SQLCHAR *)"",
		SQL_NTS), SQL_HANDLE_STMT, pHandles->m_hstmt);

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
		SADataType_t eParamType = Idb2Connection::CnvtNativeToStd(nDataType, nColSize, nColSize, nDecDigits);

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
saAPI *Idb2Connection::NativeAPI() const
{
	return &g_db2API;
}

/*virtual */
saConnectionHandles *Idb2Connection::NativeHandles()
{
	return &m_handles;
}

/*virtual */
saCommandHandles *Idb2Cursor::NativeHandles()
{
	return &m_handles;
}

/*virtual */
void Idb2Connection::setIsolationLevel(
	SAIsolationLevel_t eIsolationLevel)
{
	Commit();

	issueIsolationLevel(eIsolationLevel);
}

void Idb2Connection::issueIsolationLevel(
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

	Check(g_db2API.SQLSetConnectAttr(
		m_handles.m_hdbc,
		SQL_ATTR_TXN_ISOLATION,
		SQLPOINTER(isolation), 0), SQL_HANDLE_DBC, m_handles.m_hdbc);
}

/*virtual */
void Idb2Connection::setAutoCommit(
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

	Check(g_db2API.SQLSetConnectAttr(
		m_handles.m_hdbc,
		SQL_ATTR_AUTOCOMMIT,
		SQLPOINTER(nAutoCommit), 0), SQL_HANDLE_DBC, m_handles.m_hdbc);
}

/*virtual */
void Idb2Connection::CnvtInternalToNumeric(
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
	// DB2: 1 if positive, 0 if negative
	// SQLAPI: 1 if positive, 0 if negative
	numeric.sign = pSQL_NUMERIC_STRUCT->sign;
	// copy mantissa
	// DB2: little endian format
	// SQLAPI: little endian format
	memset(numeric.val, 0, sizeof(numeric.val));
	memcpy(
		numeric.val,
		pSQL_NUMERIC_STRUCT->val,
		sa_min(sizeof(numeric.val), sizeof(pSQL_NUMERIC_STRUCT->val)));
}

/*static */
void Idb2Connection::CnvtNumericToInternal(
	const SANumeric &numeric,
	SQL_NUMERIC_STRUCT &Internal)
{
	Internal.precision = numeric.precision;
	Internal.scale = numeric.scale;
	// set sign
	// DB2: 1 if positive, 0 if negative
	// SQLAPI: 1 if positive, 0 if negative
	Internal.sign = numeric.sign;
	// copy mantissa
	// DB2: little endian format
	// SQLAPI: little endian format
	memset(Internal.val, 0, sizeof(Internal.val));
	memcpy(
		Internal.val,
		numeric.val,
		sa_min(sizeof(numeric.val), sizeof(Internal.val)));
}
