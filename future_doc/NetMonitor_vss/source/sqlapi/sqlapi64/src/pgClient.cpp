// pgClient.cpp
//
//////////////////////////////////////////////////////////////////////

#include <SQLAPI.h>
#include "pgClient.h"

#include <assert.h>
#include <stdlib.h>	// atoi
#include <string.h>	// strlen, memcpy
#include <ctype.h>

#include <pgAPI.h>
#include "pgType.h" // Result of the "cat include/catalog/pg_type.h | grep '#define'"

#include "samisc.h"
#include "errmsg.h"

static void Check(PGresult *res)
{
	int nErr = 0;
	if( !res || !((nErr = g_pgAPI.PQresultStatus(res)) == PGRES_COMMAND_OK
		|| nErr == PGRES_TUPLES_OK) )
	{
		if( res )
			throw SAException(SA_DBMS_API_Error, nErr, -1, "%s", g_pgAPI.PQresultErrorMessage(res));
		else
			throw SAException(SA_DBMS_API_Error, nErr, -1, "%s", "Unknown error occured");
	}
}

extern long g_nPostgreSQLDLLVersionLoaded;

//////////////////////////////////////////////////////////////////////
// IpgConnection Class
//////////////////////////////////////////////////////////////////////

class IpgConnection : public ISAConnection
{
	friend class IpgCursor;

	pgConnectionHandles m_handles;

	enum {MaxBlobPiece = (unsigned int)4096, MaxLongPiece = (unsigned int)0x7FFFFFFF};

	static void CnvtInternalToNumeric(
		SANumeric &numeric,
		const char *sValue);

	static SADataType_t CnvtNativeToStd(
		Oid NativeType,
		int Length,
		int Mod,
		bool bOidAsBlob);
	static void CnvtInternalToDateTime(
		SADateTime &date_time,
		const char *sInternal);
	static int second(const char *sSecond);
	static int minute(const char *sMinute);
	static int hour(const char *sHour);
	static int day(const char *sDay);
	static int month(const char *sMonth);
	static int year(const char *sYear);
	static void CnvtDateTimeToInternal(
		const SADateTime &date_time,
		SAString &sInternal);
	static void ParseInternalTime(const char* sTime, int& nHour, int& nMinute, int& nSecond, int& nNanoSecond, int& nZoneHour);
	static void ParseInternalDate(const char* sDate, int& nYear, int& nMonth, int& nDay);
	static char* byte2string(const void* pByte, int nBufLen);
	static void* string2byte(const char* szInputText, int &nOutBufLen);
	static SAString EscapeString(const char* szString);

protected:
	virtual ~IpgConnection();

public:
	IpgConnection(SAConnection *pSAConnection);

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
SADataType_t IpgConnection::CnvtNativeToStd(
		Oid NativeType,
		int/* Length*/,
		int/* Mod*/,
		bool bOidAsBlob)
{
	SADataType_t eDataType;

	switch(NativeType)
	{
	case BOOLOID: // BOOLEAN|BOOL
		eDataType = SA_dtBool;
		break;

	case BYTEAOID: // BYTEA - variable-length string, binary values escaped
		eDataType = SA_dtLongBinary;
		break;

	case TEXTOID: // TEXT - variable-length string, no limit specified
		eDataType = SA_dtLongChar;
		break;

	case CHAROID: // CHAR - single character
	case BPCHAROID: // BPCHAR - char(length), blank-padded string, fixed storage length
	case NAMEOID: // NAME - 31-character type for storing system identifiers
	case VARCHAROID: // VARCHAR(?) - varchar(length), non-blank-padded string, variable storage length
		eDataType = SA_dtString;
		break;

	case INT8OID: // INT8|BIGINT - ~18 digit integer, 8-byte storage
	case FLOAT4OID: // FLOAT4 - single-precision floating point number, 4-byte storage
	case FLOAT8OID: // FLOAT8 - double-precision floating point number, 8-byte storage 
	case CASHOID: // $d,ddd.cc, money
		eDataType = SA_dtDouble;
		break;

	case NUMERICOID: // NUMERIC(x,y) - numeric(precision, decimal), arbitrary precision number
		eDataType = SA_dtNumeric;
		break;

	case INT2OID: // INT2|SMALLINT - -32 thousand to 32 thousand, 2-byte storage
		eDataType = SA_dtShort;
		break;

	case INT4OID: // INT4|INTEGER - -2 billion to 2 billion integer, 4-byte storage
	case XIDOID: // transaction id
	case CIDOID: // command identifier type, sequence in transaction id
		eDataType = SA_dtLong;
		break;

	case OIDOID: // OID - object identifier(oid), maximum 4 billion
		eDataType = bOidAsBlob? SA_dtBLob:SA_dtLong;
		break;

	case ABSTIMEOID: // ABSTIME - absolute, limited-range date and time (Unix system time)
	case DATEOID: // DATE - ANSI SQL date
	case TIMEOID: // TIME - hh:mm:ss, ANSI SQL time
	case TIMESTAMPOID: // TIMESTAMP - date and time
	case TIMETZOID: // TIME WITH TIMEZONE - hh:mm:ss, ANSI SQL time
		eDataType = SA_dtDateTime;
		break;

	case 705: // Unknown

	case INT2VECTOROID: // array of INDEX_MAX_KEYS int2 integers, used in system tables
	case REGPROCOID: // registered procedure
	case TIDOID: // (Block, offset), physical location of tuple
	case OIDVECTOROID: // array of INDEX_MAX_KEYS oids, used in system tables
	case POINTOID: // geometric point '(x, y)'
	case LSEGOID: // geometric line segment '(pt1,pt2)'
	case PATHOID: // geometric path '(pt1,...)'
	case BOXOID: // geometric box '(lower left,upper right)'
	case POLYGONOID: // geometric polygon '(pt1,...)'
	case LINEOID: // geometric line '(pt1,pt2)'

		// TODO: ???
	case RELTIMEOID: // relative, limited-range time interval (Unix delta time)
	case TINTERVALOID: // (abstime,abstime), time interval
	case INTERVALOID: // @ <number> <units>, time interval

	case CIRCLEOID: // geometric circle '(center,radius)'
	// locale specific
	case INETOID: // IP address/netmask, host address, netmask optional
	case CIDROID: // network IP address/netmask, network address
	case 829: // XX:XX:XX:XX:XX:XX, MAC address
	case ZPBITOID: // BIT(?) - fixed-length bit string
	case VARBITOID: // BIT VARING(?) - variable-length bit string
		eDataType = SA_dtString;
		break;

	default:
		assert(false);
		eDataType = SA_dtString;
	}

	return eDataType;
}

//////////////////////////////////////////////////////////////////////
// IpgConnection Construction/Destruction
//////////////////////////////////////////////////////////////////////

IpgConnection::IpgConnection(
	SAConnection *pSAConnection) : ISAConnection(pSAConnection)
{
}

IpgConnection::~IpgConnection()
{
}

//////////////////////////////////////////////////////////////////////
// ImyClient Class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IpgClient::IpgClient()
{
}

IpgClient::~IpgClient()
{
}

ISAConnection *IpgClient::QueryConnectionInterface(
	SAConnection *pSAConnection)
{
	return new IpgConnection(pSAConnection);
}

//////////////////////////////////////////////////////////////////////
// IpgCursor Class
//////////////////////////////////////////////////////////////////////

class IpgCursor : public ISACursor
{
	pgCommandHandles	m_handles;

	// private handles
	int m_nCurrentTuple;
	int m_nTuplesCount;
	bool m_bResultSetCanBe;

	bool		m_bOpened;

	void ConvertPGTupleToFields(int nTuple);
	void BindBLob(SAParam &Param, SAString &sBoundStmt);
	void BindLongChar(SAParam &Param, SAString &sBoundStmt);
	void BindLongBinary(SAParam &Param, SAString &sBoundStmt);
	void ReadBLOB(
		ValueType_t eValueType,
		SAValueRead &vr,
		void *pValue,
		unsigned int nFieldBufSize,
		saLongOrLobReader_t fnReader,
		unsigned int nReaderWantedPieceSize,
		void *pAddlData);

	void ReadLongBinary(
		ValueType_t eValueType,
		SAValueRead &vr,
		void *pValue,
		unsigned int nFieldBufSize,
		saLongOrLobReader_t fnReader,
		unsigned int nReaderWantedPieceSize,
		void *pAddlData);

	void ReadLongChar(
		ValueType_t eValueType,
		SAValueRead &vr,
		void *pValue,
		unsigned int nFieldBufSize,
		saLongOrLobReader_t fnReader,
		unsigned int nReaderWantedPieceSize,
		void *pAddlData);

public:
	IpgCursor(
		IpgConnection *pImyConnection,
		SACommand *pCommand);
	virtual ~IpgCursor();

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
// IpgCursor Construction/Destruction
//////////////////////////////////////////////////////////////////////

IpgCursor::IpgCursor(
	IpgConnection *pIpgConnection,
	SACommand *pCommand) :
	ISACursor(pIpgConnection, pCommand)
{
	m_bOpened = false;
	m_bResultSetCanBe = false;
	m_nCurrentTuple = 0;
	m_nTuplesCount = 0;
}

/*virtual */
IpgCursor::~IpgCursor()
{
}


//////////////////////////////////////////////////////////////////////
// IpgConnection implementation
//////////////////////////////////////////////////////////////////////

/*virtual */
void IpgConnection::InitializeClient()
{
	::AddPostgreSQLSupport(m_pSAConnection);
}

/*virtual */
void IpgConnection::UnInitializeClient()
{
	::ReleasePostgreSQLSupport();
}

/*virtual */
void IpgConnection::CnvtInternalToDateTime(
	SADateTime &/*date_time*/,
	const void * /*pInternal*/,
	int/*	nInternalSize*/)
{
	assert(false);	// we do not use ISA... convertors
}

/*static */
int IpgConnection::second(const char *sSecond)
{
	char s[3] = "SS";
	strncpy(s, sSecond, 2);

	int nSecond = atoi(s);
	assert(nSecond >= 0 && nSecond <= 59);

	return nSecond;
}

/*static */
int IpgConnection::minute(const char *sMinute)
{
	char s[3] = "MM";
	strncpy(s, sMinute, 2);

	int nMinute = atoi(s);
	assert(nMinute >= 0 && nMinute <= 59);

	return nMinute;
}

/*static */
int IpgConnection::hour(const char *sHour)
{
	char s[3] = "HH";
	strncpy(s, sHour, 2);

	int nHour = atoi(s);
	assert(nHour >= 0 && nHour <= 23);

	return nHour;
}

/*static */
int IpgConnection::day(const char *sDay)
{
	char s[3] = "DD";
	strncpy(s, sDay, 2);

	int nDay = atoi(s);
	assert(nDay >= 0 && nDay <= 31);

	return nDay;
}

/*static */
int IpgConnection::month(const char *sMonth)
{
	char s[3] = "MM";
	strncpy(s, sMonth, 2);

	int nMonth = atoi(s);
	assert(nMonth >= 0 && nMonth <= 12);

	return nMonth;
}

/*static */
int IpgConnection::year(const char *sYear)
{
	char s[5] = "YYYY";
	strncpy(s, sYear, 4);

	int nYear = atoi(s);
	assert(nYear >= 0 && nYear <= 9999);

	return nYear;
}

/*static*/
void IpgConnection::ParseInternalTime(const char* sTime, int& nHour, int& nMinute, int& nSecond, int& nNanoSecond, int& nZoneHour)
{
	// 07:37:16-08, 07:37:16.00 PST, 07:37:16 PST
	assert( sTime[2] == ':' );
	assert( sTime[5] == ':' );
	nHour = hour(sTime);
	nMinute = minute(sTime+3);
	nSecond = second(sTime+6);

	char *sTZ = (char*)(sTime+8);

	if( sTZ[0] == '.' ) // 07:37:16.00
	{
		char s[3] = "SS";
		strncpy(s, sTZ+1, 2);
		nNanoSecond = atoi(s) * 10000000;
		sTZ = sTZ+3;
	}

	if( sTZ[0] == ' ' ) // 07:37:16 PST
	{
		// TODO: PST like timezone
		assert(false);
	}
	else if( sTZ[0] == '-' || sTZ[0] == '+' ) // 07:37:16-08
		nZoneHour = atoi(sTZ);
}

/*static*/
void IpgConnection::ParseInternalDate(const char* sDate, int& nYear, int& nMonth, int& nDay)
{
	// 1997-12-17, 12/17/1997, 17.12.1997
	if( sDate[4] == '-' ) // 1997-12-17
	{
		assert(sDate[7] == '-');
		nYear = year(sDate);
		nMonth = month(sDate+5);
		nDay = day(sDate+8);
	}
	else if( sDate[2] == '/' ) // 12/17/1997
	{
		assert(sDate[5] == '/');
		// TODO: Date format may be MM/DD/YYYY(American) or DD/MM/YYYY(European).
		// Can't detect it correctly in some cases. But...
		if( atoi(sDate) > 12 ) // European
		{
			nDay = day(sDate);
			nMonth = month(sDate+3);
			nYear = year(sDate+6);
		}
		else // American
		{
			nMonth = month(sDate);
			nDay = day(sDate+3);
			nYear = year(sDate+6);
		}
	}
	else if( sDate[2] == '.' ) // 17.12.1997
	{
		assert(sDate[5] == '.');
		nDay = day(sDate);
		nMonth = month(sDate+3);
		nYear = year(sDate+6);
	}
	else
		assert(false);
}

/*static */
void IpgConnection::CnvtInternalToDateTime(
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
	int nNanoSecond = 0;
	int nZoneHour = 0;

	// Available date time formats
	// ISO		1997-12-17 07:37:16-08 
	// SQL		12/17/1997 07:37:16.00 PST 
	// Postgres	Wed Dec 17 07:37:16 1997 PST 
	// German	17.12.1997 07:37:16.00 PST 

	if( ::strlen(sInternal) < 19 ) // date only or time only
	{
		if( strchr(sInternal, ':') ) // time
			ParseInternalTime(sInternal, nHour, nMinute, nSecond, nNanoSecond, nZoneHour);
		else // date
			ParseInternalDate(sInternal, nYear, nMonth, nDay);
	}
	else // datetime
	{
		if( isdigit(sInternal[0]) ) // ISO, SQL or German
		{
			ParseInternalDate(sInternal, nYear, nMonth, nDay);
			assert(strchr( sInternal, ' '));
			ParseInternalTime(sInternal+11, nHour, nMinute, nSecond, nNanoSecond, nZoneHour);
		}
		else // Postgres format
		{
			// TODO:
			assert(false);
		}
	}

	if( nZoneHour != 0 )
	{
	}

	if(nMonth != 0 && nDay != 0 && nHour <=23)	// simple test for validness
		date_time = SADateTime(nYear, nMonth, nDay, nHour, nMinute, nSecond);
	else
		date_time = dt;

	date_time.Fraction() = nNanoSecond;
}

/*static */
void IpgConnection::CnvtDateTimeToInternal(
	const SADateTime &date_time,
	SAString &sInternal)
{
	// Datetime's format is YYYY-MM-DD HH:MM:SS.fraction
	sInternal.Format("%.4d-%.2d-%.2d %.2d:%.2d:%.2d.%.3ld",
		date_time.GetYear(), date_time.GetMonth(), date_time.GetDay(),
		date_time.GetHour(), date_time.GetMinute(), date_time.GetSecond(),
		date_time.Fraction()/1000000);
}

/*virtual */
void IpgConnection::CnvtInternalToCursor(
	SACommand * /*pCursor*/,
	const void * /*pInternal*/)
{
	assert(false);
}

/*virtual */
long IpgConnection::GetClientVersion() const
{
	return g_nPostgreSQLDLLVersionLoaded;
}

/*virtual */
long IpgConnection::GetServerVersion() const
{
	return SAExtractVersionFromString(GetServerVersionString());
}

/*virtual */
SAString IpgConnection::GetServerVersionString() const
{
	SAString sVersion;

	if( IsConnected() )
	{
		PGresult *res = g_pgAPI.PQexec(m_handles.conn, "select version()");
		Check(res);
		sVersion = g_pgAPI.PQgetvalue(res, 0, 0);
	}

	return  sVersion;
}

/*virtual */
bool IpgConnection::IsConnected() const
{
	return m_handles.conn != NULL;
}

/*virtual */
void IpgConnection::Connect(
	const SAString &sDBString,
	const SAString &sUserID,
	const SAString &sPassword)
{
	assert(m_handles.conn == NULL);

	// dbstring as: [server_name][@][dbname]
	// server_name as: hostname[:port], or unix_socket path
	// for connection to server without dbname use 'server_name@'

	SAString sServerName, sDatabase, sHost, sPort;

	int iPos = sDBString.Find('@');
	if(iPos >= 0) // Database is present in connection string
	{
		sServerName = sDBString.Left(iPos);
		sDatabase = sDBString.Mid(iPos+1);
	}
	else
		sDatabase = sDBString;

	iPos = sServerName.Find(':');
	if(iPos > 0) // alternate port number found
	{
		sHost = sServerName.Left(iPos);
		sPort = sServerName.Mid(iPos+1);
	}
	else
		sHost = sServerName;

	m_handles.conn = g_pgAPI.PQsetdbLogin(
		sHost.IsEmpty()? (const char *)NULL : (const char *)sHost,
		sPort.IsEmpty()? (const char *)NULL : (const char *)sPort,
        NULL, NULL,
		sDatabase.IsEmpty()? (const char *)NULL : (const char *)sDatabase,
		sUserID.IsEmpty()? (const char *)NULL : (const char *)sUserID,
		sPassword.IsEmpty()? (const char *)NULL : (const char *)sPassword);

	if( g_pgAPI.PQstatus(m_handles.conn) == CONNECTION_BAD )
		throw SAException(SA_DBMS_API_Error, CONNECTION_BAD, -1, "%s", g_pgAPI.PQerrorMessage(m_handles.conn));
}

/*virtual */
void IpgConnection::Disconnect()
{
	assert(m_handles.conn != NULL);

	g_pgAPI.PQfinish(m_handles.conn);
	m_handles.conn = NULL;
}

/*virtual */
void IpgConnection::Commit()
{
	Check(g_pgAPI.PQexec(m_handles.conn, "COMMIT"));
	// and start new transaction if not in autocommit mode
	if( m_pSAConnection->AutoCommit() == SA_AutoCommitOff )
		Check(g_pgAPI.PQexec(m_handles.conn, "BEGIN"));
}

/*virtual */
void IpgConnection::Rollback()
{
	Check(g_pgAPI.PQexec(m_handles.conn, "ROLLBACK"));
	// and start new transaction if not in autocommit mode
	if( m_pSAConnection->AutoCommit() == SA_AutoCommitOff )
		Check(g_pgAPI.PQexec(m_handles.conn, "BEGIN"));
}

/*virtual */
saAPI *IpgConnection::NativeAPI() const
{
	return 	&g_pgAPI;
}

/*virtual */
saConnectionHandles *IpgConnection::NativeHandles()
{
	return &m_handles;
}

/*virtual */
void IpgConnection::setIsolationLevel(
	SAIsolationLevel_t eIsolationLevel)
{
	SAString sCmd("SET SESSION CHARACTERISTICS AS TRANSACTION ISOLATION LEVEL ");
	
	if( eIsolationLevel == SA_Serializable )
		sCmd += "SERIALIZABLE";
	else
		sCmd += "READ COMMITTED";

	Check(g_pgAPI.PQexec(m_handles.conn, sCmd));
}

/*virtual */
void IpgConnection::setAutoCommit(
	SAAutoCommit_t eAutoCommit)
{
	Check(g_pgAPI.PQexec(m_handles.conn, "COMMIT"));
	if( eAutoCommit == SA_AutoCommitOff )
		Check(g_pgAPI.PQexec(m_handles.conn, "BEGIN"));
}

/*virtual */
ISACursor *IpgConnection::NewCursor(SACommand *m_pCommand)
{
	return new IpgCursor(this, m_pCommand);
}

//////////////////////////////////////////////////////////////////////
// IpgCursor implementation
//////////////////////////////////////////////////////////////////////

/*virtual */
bool IpgCursor::IsOpened()
{
	return m_bOpened;
}

/*virtual */
void IpgCursor::Open()
{
	assert(m_bOpened == false);

	m_bOpened = true;
}

/*virtual */
void IpgCursor::Close()
{
	assert(m_bOpened == true);

	m_bOpened = false;
}

// prepare statement (also convert to native format if needed)
/*virtual */
void IpgCursor::Prepare(
	const SAString &/*sStmt*/,
	SACommandType_t/* eCmdType*/,
	int/* nPlaceHolderCount*/,
	saPlaceHolder ** /*ppPlaceHolders*/)
{
	// no prepare in libpq
	// all is beeing done in Execute()
}

/*virtual */
void IpgCursor::UnExecute()
{
	if(m_handles.res)
	{
		g_pgAPI.PQclear(m_handles.res);
		m_handles.res = NULL;
	}

	m_bResultSetCanBe = false;
}

// executes statement (also binds parameters if needed)
/*virtual */
void IpgCursor::Execute(
	int nPlaceHolderCount,
	saPlaceHolder **ppPlaceHolders)
{
	m_nCurrentTuple = 0;
	m_nTuplesCount = 0;

	SAString sOriginalStmst = m_pCommand->CommandText();
	SAString sBoundStmt;
	// change ':' param markers to bound values
	unsigned int nPos = 0;
	for(int i = 0; i < nPlaceHolderCount; ++i)
	{
		SAParam &Param = *ppPlaceHolders[i]->getParam();

		sBoundStmt += sOriginalStmst.Mid(nPos, ppPlaceHolders[i]->getStart()-nPos);

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
				sBoundValue = Param.asBool() ? "TRUE" : "FALSE";
				break;
			case SA_dtShort:
			case SA_dtLong:
			case SA_dtDouble:
			case SA_dtNumeric:
				sBoundValue = Param.asString();	// use SQLAPI++ converter
				break;
			case SA_dtDateTime:
				IpgConnection::CnvtDateTimeToInternal(
					Param.setAsDateTime(), sTemp);
				sBoundValue = "'";
				sBoundValue += sTemp;
				sBoundValue += "'";
				break;
			case SA_dtBytes:
				{
					sBoundValue = "'";
					SAString sValue = Param.asBytes();
					char* szByteStr = IpgConnection::byte2string((const void*)sValue, sValue.GetBinaryLength() );
					sBoundValue += szByteStr;
					free(szByteStr);
					sBoundValue += "'";
				}
				break;
			case SA_dtString: // Quote ' with '
				sTemp = Param.asString();
				sBoundValue = "'";
				sBoundValue += IpgConnection::EscapeString(sTemp);
				sBoundValue += "'";
				break;
			case SA_dtLongChar:
				BindLongChar(Param, sBoundStmt);
				break;
			case SA_dtLongBinary:
				BindLongBinary(Param, sBoundStmt);
				break;
			case SA_dtBLob:
			case SA_dtCLob:
				BindBLob(Param, sBoundStmt);
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
	if(nPos < strlen(sOriginalStmst))
		sBoundStmt += sOriginalStmst.Mid(nPos);

	pgConnectionHandles *pConH = (pgConnectionHandles *)m_pCommand->Connection()->NativeHandles();

	try
	{
		Check(m_handles.res = g_pgAPI.PQexec(pConH->conn, sBoundStmt));
	}
	catch(SAException &)  // Cleanup
	{
		if(m_handles.res)
		{
			g_pgAPI.PQclear(m_handles.res);
			m_handles.res = NULL;
		}

		throw;
	}


	if( PGRES_TUPLES_OK  == g_pgAPI.PQresultStatus(m_handles.res) )
	{
		m_nTuplesCount = g_pgAPI.PQntuples(m_handles.res);
		m_bResultSetCanBe = true;
	}
	else
		m_bResultSetCanBe = false;
}

void IpgCursor::BindLongChar(SAParam &Param, SAString &sBoundStmt)
{
	sBoundStmt += "'";

	unsigned int nActualWrite;
	SAPieceType_t ePieceType = SA_FirstPiece;
	void *pBuf;
	while( (nActualWrite = Param.InvokeWriter(
		ePieceType, IpgConnection::MaxLongPiece, pBuf)) != 0 )
	{
		SAString sTemp((const char *)pBuf, nActualWrite);
		sBoundStmt += IpgConnection::EscapeString(sTemp);

		if(ePieceType == SA_LastPiece)
			break;
	}

	sBoundStmt += "'";
}

void IpgCursor::BindLongBinary(SAParam &Param, SAString &sBoundStmt)
{
	sBoundStmt += "'";

	unsigned int nActualWrite;
	SAPieceType_t ePieceType = SA_FirstPiece;
	void *pBuf;
	while((nActualWrite = Param.InvokeWriter(
		ePieceType, IpgConnection::MaxLongPiece, pBuf)) != 0)
	{
		char* szByteStr = IpgConnection::byte2string(pBuf, nActualWrite);
		sBoundStmt += szByteStr;
		free(szByteStr);

		if(ePieceType == SA_LastPiece)
			break;
	}

	sBoundStmt += "'";
}

void IpgCursor::BindBLob(SAParam &Param, SAString &sBoundStmt)
{
	unsigned int nActualWrite;
	SAPieceType_t ePieceType = SA_FirstPiece;
	void *pBuf;
	pgConnectionHandles *pConH = (pgConnectionHandles *)m_pCommand->Connection()->NativeHandles();
	SAConnection *pSAConnection = m_pCommand->Connection();

	// Start transaction if not started
	if( pSAConnection->AutoCommit() != SA_AutoCommitOff )
		Check(g_pgAPI.PQexec(pConH->conn, "BEGIN"));

	Oid blobOid = g_pgAPI.lo_creat(pConH->conn, INV_READ|INV_WRITE);
	int fd = g_pgAPI.lo_open(pConH->conn, blobOid, INV_WRITE);

	while((nActualWrite = Param.InvokeWriter(
		ePieceType, IpgConnection::MaxBlobPiece, pBuf)) != 0)
	{
		char *pWriteBuf = (char*)pBuf;
		int nToWrite = nActualWrite;

		do
		{
			int nWritten;

			if( (nWritten = g_pgAPI.lo_write(pConH->conn, fd, pWriteBuf, nToWrite)) < 0 )
			{
				g_pgAPI.lo_close(pConH->conn, fd);
				
				// Rollback transaction, if previos start it
				if( pSAConnection->AutoCommit() != SA_AutoCommitOff )
					g_pgAPI.PQexec(pConH->conn, "ROLLBACK");
				
				throw SAException(SA_Library_Error, -1, -1, "lo_write -> negative number");
			}

			nToWrite -= nWritten;
			pWriteBuf += nWritten;
		}
		while( nToWrite > 0 );

		if(ePieceType == SA_LastPiece)
			break;
	}

	g_pgAPI.lo_close(pConH->conn, fd);

	// End transaction, if previos start it
	if( pSAConnection->AutoCommit() != SA_AutoCommitOff )
		Check(g_pgAPI.PQexec(pConH->conn, "END"));

	SAString sBlobOid; sBlobOid.Format("%d", blobOid);
	sBoundStmt += sBlobOid;
}

/*static*/
SAString IpgConnection::EscapeString(const char* szString)
{
	SAString sReturn(szString);
	sReturn.Replace("\\", "\\\\");
	sReturn.Replace("'", "\\'");
	return sReturn;
}

#define VAL(CH)			((CH) - '0')
#define DIG(VAL)		((VAL) + '0')

/*static*/
char* IpgConnection::byte2string(const void* pByte, int nBufLen)
{
	// Non-printable and '\' characters are inserted as '\nnn' (octal)
	// and ''' as '\''.

	int i, len = 1;
	char *vp = (char*)pByte;

	for( i = nBufLen; i != 0; i--, vp++)
	{
		if( *vp == '\'' )
			len += 2;
		else if( *vp == 0 )
			len += 5;
		else if( isprint((unsigned char) *vp) && *vp != '\\')
			len++;
		else
			len += 4;
	}

	char *result = (char*)malloc(len);

	char *rp = result;
	vp = (char*)pByte;
	
	int val;			/* holds unprintable chars */
	for( i = nBufLen; i != 0; i--, vp++ )
	{
		if(*vp == '\'' )
		{
			*rp++ = '\\';
			*rp++ = *vp;
		}
		else if(*vp == 0 )
		{
			*rp++ = '\\';
			*rp++ = '\\';
			*rp++ = '0';
			*rp++ = '0';
			*rp++ = '0';
		}
		else if( *vp == '\\' )
		{
			*rp++ = '\\';
			*rp++ = '\\';
			*rp++ = '\\';
			*rp++ = '\\';
		}
		else if( isprint((unsigned char) *vp) )
			*rp++ = *vp;
		else
		{
			val = *vp;
			rp[0] = '\\';
			rp[3] = (char)DIG(val & 07);
			val >>= 3;
			rp[2] = (char)DIG(val & 07);
			val >>= 3;
			rp[1] = (char)DIG(val & 03);
			rp += 4;
		}
	}

	*rp = '\0';
	return result;
}

/*static*/
void* IpgConnection::string2byte(const char* szInputText, int &nOutBufLen)
{
	char *tp = (char*)szInputText;

	for( nOutBufLen = 0; *tp != '\0'; nOutBufLen++ )
	{
		if( *tp++ == '\\' )
		{ 
			if( *tp == '\\' )
				tp++;
			else if( !isdigit((unsigned char) *tp++)
				|| !isdigit((unsigned char) *tp++)
				|| !isdigit((unsigned char) *tp++) )
				throw SAException(SA_Library_Error, -1, -1, "Bad input string for type bytea");
		}
	}

	tp = (char*)szInputText;
	void *result = malloc(nOutBufLen);
	char *rp = (char*)result;
	int byte;

	while( *tp != '\0' )
	{
		if (*tp != '\\' || *++tp == '\\')
			*rp++ = *tp++;
		else
		{
			byte = VAL(*tp++);
			byte <<= 3;
			byte += VAL(*tp++);
			byte <<= 3;
			*rp++ = (char)(byte + VAL(*tp++));
		}
	}

	return result;
}

/*virtual */
void IpgCursor::Cancel()
{
	pgConnectionHandles *pConH = (pgConnectionHandles *)m_pCommand->Connection()->NativeHandles();

	if( !g_pgAPI.PQrequestCancel(pConH->conn) )
		throw SAException(SA_DBMS_API_Error, 0, -1, "%s", g_pgAPI.PQerrorMessage(pConH->conn));
}

/*virtual */
bool IpgCursor::ResultSetExists()
{
	if(!m_bResultSetCanBe)
		return false;

	return (g_pgAPI.PQresultStatus(m_handles.res) == PGRES_TUPLES_OK);
}

/*virtual */
void IpgCursor::DescribeFields(
	DescribeFields_cb_t fn)
{
	SAString s = m_pCommand->Option("OidTypeInterpretation");
	bool bOidAsBlob = s.CompareNoCase("LargeObject") == 0;

	int cFields = g_pgAPI.PQnfields(m_handles.res);

	for(int iField = 0; iField < cFields; ++iField)
	{
		Oid NativeType = g_pgAPI.PQftype(m_handles.res, iField);
		int Length = g_pgAPI.PQfsize(m_handles.res, iField);
		int Mod = g_pgAPI.PQfmod(m_handles.res, iField);

		(m_pCommand->*fn)(
			g_pgAPI.PQfname(m_handles.res, iField),
			IpgConnection::CnvtNativeToStd(NativeType, Length, Mod, bOidAsBlob),
			NativeType,
			Length,
			0,
			0,
			false);
	}
}

/*virtual */
void IpgCursor::SetSelectBuffers()
{
	// do nothing
}

/*virtual */
void IpgCursor::SetFieldBuffer(
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

void IpgCursor::ConvertPGTupleToFields(int nTuple)
{
	int cFields = m_pCommand->FieldCount();
	for(int iField = 0; iField < cFields; ++iField)
	{
		SAField &Field = m_pCommand->Field(iField+1);
		SADataType_t eFieldType = Field.FieldType();


		if( g_pgAPI.PQgetisnull(m_handles.res, nTuple, iField) )
		{
			*Field.m_pbNull = true;
			continue;
		}
		*Field.m_pbNull = false;

		char *sValue = g_pgAPI.PQgetvalue(m_handles.res, nTuple, iField);
		int nRealSize = g_pgAPI.PQgetlength(m_handles.res, nTuple, iField);

		if( g_pgAPI.PQbinaryTuples(m_handles.res) )
		{
			Field.m_eDataType = SA_dtBytes;
			*Field.m_pString = SAString((void*)sValue, nRealSize);
			continue;
		}

		switch(eFieldType)
		{
		case SA_dtUnknown:
			throw SAException(SA_Library_Error, -1, -1, IDS_UNKNOWN_DATA_TYPE);
		case SA_dtBool: // Output as 't' or 'f' char
			Field.m_eDataType = SA_dtBool;
			if( sValue[0] == 't' )
				*(bool*)Field.m_pScalar = true;
			else if( sValue[0] == 'f' )
				*(bool*)Field.m_pScalar = false;
			else
				assert(false);
			break;
		case SA_dtShort:
			Field.m_eDataType = SA_dtShort;
			*(short*)Field.m_pScalar = (short)atol(sValue);
			break;
		case SA_dtLong:
			Field.m_eDataType = SA_dtLong;
			*(long*)Field.m_pScalar = atol(sValue);
			break;
		case SA_dtDouble:
			if(Field.FieldNativeType() == CASHOID) // $d,ddd.cc, money
			{
				size_t i, out = 0;
				for(i = 0; i < strlen(sValue); ++i)
				{
					if(sValue[i] == '$' || sValue[i] == ',' || sValue[i] == ')')
						;					/* skip these characters */
					else if(sValue[i] == '(')
						sValue[out++] = '-';
					else
						sValue[out++] = sValue[i];
				}
				sValue[out] = '\0';				
			}
			Field.m_eDataType = SA_dtDouble;
			*(double*)Field.m_pScalar = atof(sValue);
			break;
		case SA_dtNumeric:
			Field.m_eDataType = SA_dtNumeric;
			IpgConnection::CnvtInternalToNumeric(
				*Field.m_pNumeric,
				sValue);
			break;
		case SA_dtDateTime:
			Field.m_eDataType = SA_dtDateTime;
			IpgConnection::CnvtInternalToDateTime(
				*Field.m_pDateTime,
				sValue);
			break;
		case SA_dtString:
			Field.m_eDataType = SA_dtString;
			*Field.m_pString =
				SAString(sValue, nRealSize);
			break;
		case SA_dtBytes:
			{
				Field.m_eDataType = SA_dtBytes;
				int nByteSize = 0;
				void* pBytes = IpgConnection::string2byte(sValue, nByteSize);
				*Field.m_pString = SAString(pBytes, nByteSize);
				free(pBytes);
			}
			break;
		case SA_dtLongBinary:
			Field.m_eDataType = SA_dtLongBinary;
			*(long*)Field.m_pScalar = nTuple; // Pass tuple id
			break;
		case SA_dtLongChar:
			Field.m_eDataType = SA_dtLongChar;
			*(long*)Field.m_pScalar = nTuple; // Pass tuple id
			break;
		case SA_dtBLob:
			Field.m_eDataType = SA_dtBLob;
			*(long*)Field.m_pScalar = atol(sValue); // Pass Oid of the large object (should be LOB!!!) as long
			break;
		case SA_dtCLob:
			Field.m_eDataType = SA_dtCLob;
			*(long*)Field.m_pScalar = atol(sValue); // Pass Oid of the large object (should be LOB!!!) as long
			break;
		default:
			assert(false);	// unknown type
		}

		if(isLongOrLob(eFieldType) )
			ConvertLongOrLOB(ISA_FieldValue, Field, NULL, 0);
	}
}

/*virtual */
bool IpgCursor::FetchNext()
{
	if(m_nCurrentTuple < m_nTuplesCount)
		ConvertPGTupleToFields(m_nCurrentTuple++);
	else
		m_bResultSetCanBe = false;

	return m_bResultSetCanBe;
}

/*virtual */
long IpgCursor::GetRowsAffected()
{
	return (long)atoi(g_pgAPI.PQcmdTuples(m_handles.res));
}

/*virtual */
void IpgCursor::ReadLongOrLOB(
	ValueType_t eValueType,
	SAValueRead &vr,
	void *pValue,
	unsigned int nBufSize,
	saLongOrLobReader_t fnReader,
	unsigned int nReaderWantedPieceSize,
	void *pAddlData)
{
	SADataType_t eDataType;

	switch( eValueType )
	{
	case ISA_FieldValue:
		eDataType = ((SAField&)vr).FieldType();
		break;
	default:
		assert(eValueType == ISA_ParamValue);
		eDataType = ((SAParam&)vr).ParamType();
	}

	switch( eDataType )
	{
	case SA_dtLongBinary:
		ReadLongBinary(eValueType, vr, pValue, nBufSize, fnReader, nReaderWantedPieceSize, pAddlData);
		break;
	case SA_dtLongChar:
		ReadLongChar(eValueType, vr, pValue, nBufSize, fnReader, nReaderWantedPieceSize, pAddlData);
		break;
	case SA_dtBLob:
	case SA_dtCLob:
		ReadBLOB(eValueType, vr, pValue, nBufSize, fnReader, nReaderWantedPieceSize, pAddlData);
		break;
	default:
		assert(false);
	}
}

void IpgCursor::ReadLongBinary(
	ValueType_t/* eValueType*/,
	SAValueRead &vr,
	void * /*pValue*/,
	unsigned int/* nFieldBufSize*/,
	saLongOrLobReader_t fnReader,
	unsigned int nReaderWantedPieceSize,
	void *pAddlData)
{
	int iField = ((SAField &)vr).Pos() - 1;
	int nTuple = *((int*)vr.m_pScalar);

	// get long data and size
	int nRealSize;
	char *pData = (char*)IpgConnection::string2byte(
		g_pgAPI.PQgetvalue(m_handles.res, nTuple, iField), nRealSize);
	unsigned long nLongSize = nRealSize;

	unsigned char* pBuf;
	unsigned int nPieceSize = vr.PrepareReader(
		nLongSize,
		IpgConnection::MaxLongPiece,
		pBuf,
		fnReader,
		nReaderWantedPieceSize,
		pAddlData);
	assert(nPieceSize <= IpgConnection::MaxLongPiece);

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

	free(pData);
}

void IpgCursor::ReadLongChar(
	ValueType_t/* eValueType*/,
	SAValueRead &vr,
	void * /*pValue*/,
	unsigned int/* nFieldBufSize*/,
	saLongOrLobReader_t fnReader,
	unsigned int nReaderWantedPieceSize,
	void *pAddlData)
{
	int iField = ((SAField &)vr).Pos() - 1;
	int nTuple = *((int*)vr.m_pScalar);

	// get long data and size
	const char *pData = g_pgAPI.PQgetvalue(m_handles.res, nTuple, iField);
	unsigned long nLongSize = g_pgAPI.PQgetlength(m_handles.res, nTuple, iField);

	unsigned char* pBuf;
	unsigned int nPieceSize = vr.PrepareReader(
		nLongSize,
		IpgConnection::MaxLongPiece,
		pBuf,
		fnReader,
		nReaderWantedPieceSize,
		pAddlData);
	assert(nPieceSize <= IpgConnection::MaxLongPiece);

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

void IpgCursor::ReadBLOB(
	ValueType_t/* eValueType*/,
	SAValueRead &vr,
	void * /*pValue*/,
	unsigned int/* nFieldBufSize*/,
	saLongOrLobReader_t fnReader,
	unsigned int nReaderWantedPieceSize,
	void *pAddlData)
{
	pgConnectionHandles *pConH = (pgConnectionHandles *)m_pCommand->Connection()->NativeHandles();
	Oid blobOid = *((long*)vr.m_pScalar);
	SAConnection *pSAConnection = m_pCommand->Connection();

	// Start transaction if not started
	if( pSAConnection->AutoCommit() != SA_AutoCommitOff )
		Check(g_pgAPI.PQexec(pConH->conn, "BEGIN"));

	int fd = g_pgAPI.lo_open(pConH->conn, blobOid, INV_READ);
    if( fd < 0 )
		throw SAException(SA_Library_Error, -1, -1, "lo_open -> negative number");

	unsigned int nLongSize = 0;	// no way to determine size before fetch
	unsigned char* pBuf;
	unsigned int nPieceSize = vr.PrepareReader(
		nLongSize,
		IpgConnection::MaxBlobPiece,
		pBuf,
		fnReader,
		nReaderWantedPieceSize,
		pAddlData);

	assert(nPieceSize <= IpgConnection::MaxBlobPiece);

	SAPieceType_t ePieceType = SA_FirstPiece;
	int nReaded;
	
	while( (nReaded = g_pgAPI.lo_read(pConH->conn, fd, (char*)pBuf, nPieceSize)) != 0 )
	{
	    if( nReaded < 0 )
		{
			g_pgAPI.lo_close(pConH->conn, fd);
			
			// Rollback transaction, if previos start it
			if( pSAConnection->AutoCommit() != SA_AutoCommitOff )
				g_pgAPI.PQexec(pConH->conn, "ROLLBACK");

			throw SAException(SA_Library_Error, -1, -1, "lo_read -> negative number");
		}

		if( ePieceType != SA_FirstPiece )
		{
			if( nReaded < (int)nPieceSize )
				ePieceType = SA_LastPiece;
			else
				ePieceType = SA_NextPiece;
		}
		else if( nReaded < (int)nPieceSize )
			ePieceType = SA_OnePiece;

		vr.InvokeReader(ePieceType, pBuf, nReaded);

		if(ePieceType == SA_FirstPiece)
			ePieceType = SA_NextPiece;
	}

	g_pgAPI.lo_close(pConH->conn, fd);

	// End transaction, if previos start it
	if( pSAConnection->AutoCommit() != SA_AutoCommitOff )
		Check(g_pgAPI.PQexec(pConH->conn, "END"));
}

/*virtual */
void IpgCursor::DescribeParamSP()
{
	assert(false);	// no SPs in PostgreSQL
}

/*virtual */
saCommandHandles *IpgCursor::NativeHandles()
{
	return &m_handles;
}

//////////////////////////////////////////////////////////////////////
// PostgreSQL globals
//////////////////////////////////////////////////////////////////////

ISAConnection *newIpgConnection(SAConnection *pSAConnection)
{
	return new IpgConnection(pSAConnection);
}

/*static */
void IpgConnection::CnvtInternalToNumeric(
	SANumeric &numeric,
	const char *sValue)
{
	numeric = sValue;
}

/*virtual */
void IpgConnection::CnvtInternalToNumeric(
	SANumeric &/*numeric*/,
	const void * /*pInternal*/,
	int/* nInternalSize*/)
{
	assert(false);	// we do not use ISA... convertors
}
