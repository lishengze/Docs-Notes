// sybClient.cpp: implementation of the IsybClient class.
//
//////////////////////////////////////////////////////////////////////

#include <SQLAPI.h>
#include "sybClient.h"

#include <assert.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#include <sybAPI.h>
#include "samisc.h"
#include "errmsg.h"

SQLAPI_API SybErrInfo_t *getSybErrInfo(CS_CONTEXT *context)
{
	SybErrInfo_t *pSybErrInfo = NULL;
	// get (allocated) user data where to return error info
	g_sybAPI.cs_config(
		context,
		CS_GET,
		CS_USERDATA,
		&pSybErrInfo,
		sizeof(SybErrInfo_t *),
		NULL);

	assert(pSybErrInfo);
	return pSybErrInfo;
}

CS_RETCODE CS_PUBLIC DefaultClientMsg_cb(
	CS_CONTEXT *context, CS_CONNECTION * /*connection*/, CS_CLIENTMSG *message)
{
	SybErrInfo_t *pSybErrInfo = getSybErrInfo(context);

	if(pSybErrInfo->msgnumber == 0	// only if no error is waiting to be handled yet
		&& message->severity != CS_SV_INFORM)
	{
		pSybErrInfo->msgnumber = message->msgnumber;
		strncpy(pSybErrInfo->msgstring, message->msgstring, message->msgstringlen);
		pSybErrInfo->msgstring[message->msgstringlen] = 0;
		pSybErrInfo->line = -1;
	}

	return CS_SUCCEED;
}

CS_RETCODE CS_PUBLIC DefaultServerMsg_cb(
	CS_CONTEXT *context, CS_CONNECTION * /*connection*/, CS_SERVERMSG *message)
{
	SybErrInfo_t *pSybErrInfo = getSybErrInfo(context);

	if(pSybErrInfo->msgnumber == 0	// only if no error is waiting to be handled yet
		&& message->severity > 10)	
	{
		pSybErrInfo->msgnumber = message->msgnumber;
		strncpy(pSybErrInfo->msgstring, message->text, message->textlen);
		pSybErrInfo->msgstring[message->textlen] = 0;
		pSybErrInfo->line = message->line;
	}

	return CS_SUCCEED;
}

//////////////////////////////////////////////////////////////////////
// IsybConnection Class
//////////////////////////////////////////////////////////////////////

class IsybConnection : public ISAConnection
{
	friend class IsybCursor;
	friend class IsybClient;

	sybConnectionHandles m_handles;

	SAString	m_sServerName;
	SAString	m_sDatabase;

	CS_RETCODE Check(CS_RETCODE rcd) const;
	CS_RETCODE CheckSilent(CS_RETCODE rcd) const;
	SAString ConvertToString(
		CS_INT srctype, CS_VOID	*src, CS_INT srclen);

	enum {MaxLongPiece = (unsigned int)2147483647};

protected:
	virtual ~IsybConnection();

public:
	IsybConnection(SAConnection *pSAConnection);

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
	void CnvtInternalToDateTime(
		SADateTime &date_time,
		const CS_DATETIME &time);
	static void CnvtDateTimeToInternal(
		const SADateTime &date_time,
		SAString &sInternal);
	void CnvtDateTimeToInternal(
		const SADateTime &date_time,
		CS_DATETIME *pInternal);

	virtual void CnvtInternalToCursor(
		SACommand *pCursor,
		const void *pInternal);
};

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IsybConnection::IsybConnection(
	SAConnection *pSAConnection) : ISAConnection(pSAConnection)
{
}

IsybConnection::~IsybConnection()
{
}

/*virtual */
void IsybConnection::InitializeClient()
{
	::AddSybSupport();

	assert(m_handles.m_context == NULL);

	// allocate context
	CS_CONTEXT *context = NULL;

	try
	{
		// try 11.0 behavior
		CS_INT version = CS_VERSION_110;
		CS_RETCODE rc = g_sybAPI.cs_ctx_alloc(version, &context);
		if(rc == CS_FAIL)	// 11.0 behavior not supported?
		{
			// try 10.0 behavior
			version = CS_VERSION_100;
			rc = g_sybAPI.cs_ctx_alloc(version, &context);
		}
		if(rc == CS_MEM_ERROR)
			throw SAException(SA_Library_Error, -1, -1, "cs_ctx_alloc -> CS_MEM_ERROR");
		if(rc == CS_FAIL)
			throw SAException(SA_Library_Error, -1, -1, "cs_ctx_alloc -> CS_FAIL");
		assert(rc == CS_SUCCEED);

		rc = g_sybAPI.ct_init(context, version);
		if(rc == CS_MEM_ERROR)
			throw SAException(SA_Library_Error, -1, -1, "ct_init -> CS_MEM_ERROR");
		if(rc == CS_FAIL)
			throw SAException(SA_Library_Error, -1, -1, "ct_init -> CS_FAIL");
		assert(rc == CS_SUCCEED);

		// set (allocated) user data where to return error info
		SybErrInfo_t *pSybErrInfo = new SybErrInfo_t;
		memset(pSybErrInfo, 0, sizeof(SybErrInfo_t));

		g_sybAPI.cs_config(
			context, 
			CS_SET,
			CS_USERDATA,
			&pSybErrInfo,
			sizeof(SybErrInfo_t *),
			NULL);
		// set context level callbacks
		g_sybAPI.ct_callback(
			context, NULL, CS_SET, CS_CLIENTMSG_CB,
			(CS_VOID *)DefaultClientMsg_cb);
		g_sybAPI.ct_callback(
			context, NULL, CS_SET, CS_SERVERMSG_CB,
			(CS_VOID *)DefaultServerMsg_cb);

		m_handles.m_context = context;
	}
	catch(SAException &)
	{
		// clean up
		if(context)
		{
			CS_RETCODE retcode = g_sybAPI.ct_exit(context, CS_UNUSED);
			assert(retcode == CS_SUCCEED);
			if(retcode != CS_SUCCEED)
				g_sybAPI.ct_exit(context, CS_FORCE_EXIT);

			g_sybAPI.cs_ctx_drop(context);
		}

		throw;
	}
}

/*virtual */
void IsybConnection::UnInitializeClient()
{
	assert(m_handles.m_context != NULL);

	Check(g_sybAPI.ct_exit(m_handles.m_context, CS_UNUSED));

	SybErrInfo_t *pSybErrInfo = NULL;
	// free user data where to return error info
	g_sybAPI.cs_config(
		m_handles.m_context,
		CS_GET,
		CS_USERDATA,
		&pSybErrInfo,
		sizeof(SybErrInfo_t *),
		NULL);
	delete pSybErrInfo;
	g_sybAPI.cs_ctx_drop(m_handles.m_context);
	m_handles.m_context = NULL;

	::ReleaseSybSupport();
}

CS_RETCODE IsybConnection::Check(CS_RETCODE rcd) const
{
	SybErrInfo_t *pSybErrInfo = NULL;
	// get (allocated) user data where to return error info
	g_sybAPI.cs_config(
		m_handles.m_context, 
		CS_GET,
		CS_USERDATA,
		&pSybErrInfo,
		sizeof(SybErrInfo_t *),
		NULL);
	assert(pSybErrInfo);

	// save
	SybErrInfo_t SybErrInfoSave = *pSybErrInfo;

	// clear
	memset(pSybErrInfo, 0, sizeof(SybErrInfo_t));

	if(SybErrInfoSave.msgnumber)
		throw SAException(
			SA_DBMS_API_Error,
			SybErrInfoSave.msgnumber, 
			SybErrInfoSave.line,
			SybErrInfoSave.msgstring);

	return rcd;
}

CS_RETCODE IsybConnection::CheckSilent(CS_RETCODE rcd) const
{
	SybErrInfo_t *pSybErrInfo = NULL;
	// get (allocated) user data where to return error info
	g_sybAPI.cs_config(
		m_handles.m_context, 
		CS_GET,
		CS_USERDATA,
		&pSybErrInfo,
		sizeof(SybErrInfo_t *),
		NULL);
	assert(pSybErrInfo);

	// clear
	memset(pSybErrInfo, 0, sizeof(SybErrInfo_t));

	return rcd;
}

SAString IsybConnection::ConvertToString(
	CS_INT srctype, CS_VOID	*src, CS_INT srclen)
{
	assert(m_handles.m_context != NULL);

	SAString sConverted;
	CS_INT destlen = sa_max(1024, srclen*2);
	CS_VOID *dest = new char[destlen];

	CS_DATAFMT srcfmt, destfmt;

	srcfmt.datatype = srctype;
	srcfmt.format = CS_FMT_UNUSED;
	srcfmt.maxlength = srclen;
	srcfmt.locale = NULL;

	destfmt.datatype = CS_CHAR_TYPE;
	destfmt.format = CS_FMT_UNUSED;
	destfmt.maxlength = destlen;
	destfmt.locale = NULL;

	CS_INT resultlen;
	Check(g_sybAPI.cs_convert(
		m_handles.m_context,
		&srcfmt,
		src,
		&destfmt,
		dest,
		&resultlen));

	sConverted = SAString((const char*)dest, resultlen);
	delete [] (char*)dest;

	return sConverted;
}

/*virtual */
void IsybConnection::CnvtInternalToDateTime(
	SADateTime &date_time,
	const void *pInternal,
	int	nInternalSize)
{
	assert(nInternalSize == sizeof(CS_DATETIME));
	if(nInternalSize != sizeof(CS_DATETIME))
		return;
	CnvtInternalToDateTime(date_time, *(const CS_DATETIME*)pInternal);
}

void IsybConnection::CnvtInternalToDateTime(
	SADateTime &date_time,
	const CS_DATETIME &Internal)
{
	assert(m_handles.m_context != NULL);

	struct tm &_tm = (struct tm&)date_time;

	CS_DATEREC rec;
	Check(g_sybAPI.cs_dt_crack(
		m_handles.m_context,
		CS_DATETIME_TYPE,
		(CS_VOID*)&Internal,
		&rec));

	_tm.tm_hour = rec.datehour;
	_tm.tm_mday = rec.datedmonth;
	_tm.tm_min = rec.dateminute;
	_tm.tm_mon = rec.datemonth;
	_tm.tm_sec = rec.datesecond;
	_tm.tm_year = rec.dateyear-1900;

	// complete structure
	_tm.tm_isdst = -1;
	// convert CS_DATEREC::datedweek 0 - 6 (Sun. - Sat.) 
	// to struct tm::tm_wday 0 - 6 (Sun. - Sat.)
   	_tm.tm_wday = rec.datedweek;
	// convert CS_DATEREC::datedyear 1-366
	// to struct tm::tm_yday 0-365
	_tm.tm_yday = rec.datedyear - 1;

	// convert SyBase milliseconds to SQLAPI++ nanoseconds
	date_time.Fraction() = rec.datemsecond * 1000000;
}

/*static */
void IsybConnection::CnvtDateTimeToInternal(
	const SADateTime &date_time,
	SAString &sInternal)
{
	// format should be 
	//    YYYYMMDD hh:mm:ss:mmm
	// or YYYYMMDD hh:mm:ss.mmm	- we use this currently
	// or YYYYMMDD hh:mm:ss		- and this
	if(date_time.Fraction())
		sInternal.Format("%.4d%.2d%.2d %.2d:%.2d:%.2d.%.3d",
			date_time.GetYear(), date_time.GetMonth(), date_time.GetDay(),
			date_time.GetHour(), date_time.GetMinute(), date_time.GetSecond(),
			(int)((double)date_time.Fraction() / 1.0e6 + 0.5e-6));
	else
		sInternal.Format("%.4d%.2d%.2d %.2d:%.2d:%.2d",
			date_time.GetYear(), date_time.GetMonth(), date_time.GetDay(),
			date_time.GetHour(), date_time.GetMinute(), date_time.GetSecond());
}

void IsybConnection::CnvtDateTimeToInternal(
	const SADateTime &date_time,
	CS_DATETIME *pInternal)
{
	assert(m_handles.m_context != NULL);

	SAString s;
	CnvtDateTimeToInternal(date_time, s);

	CS_DATAFMT srcfmt, destfmt;

	srcfmt.datatype = CS_CHAR_TYPE;
	srcfmt.format = CS_FMT_UNUSED;
	srcfmt.maxlength = s.GetLength();
	srcfmt.locale = NULL;

	destfmt.datatype = CS_DATETIME_TYPE;
	destfmt.format = CS_FMT_UNUSED;
	destfmt.maxlength = sizeof(CS_DATETIME);
	destfmt.locale = NULL;

	CS_INT resultlen;
	Check(g_sybAPI.cs_convert(
		m_handles.m_context,
		&srcfmt,
		(CS_VOID*)(const char*)s,
		&destfmt,
		pInternal,
		&resultlen));
}

/*virtual */
void IsybConnection::CnvtInternalToCursor(
	SACommand * /*pCursor*/,
	const void * /*pInternal*/)
{
	assert(false);
}

/*virtual */
long IsybConnection::GetClientVersion() const
{
	assert(m_handles.m_context != NULL);

	char sVer[1024];
	Check(g_sybAPI.ct_config(m_handles.m_context, CS_GET, CS_VER_STRING,
		sVer, sizeof(sVer), NULL));
	
	return SAExtractVersionFromString(sVer);
}

/*virtual */
long IsybConnection::GetServerVersion() const
{
	return SAExtractVersionFromString(GetServerVersionString());
}

/*virtual */
SAString IsybConnection::GetServerVersionString() const
{
	SACommand cmd(m_pSAConnection);
	
	bool bASA = false;
	try
	{
		// Check if we are on Adaptive Server Anywhere
		cmd.setCommandText("select dbo.xp_msver('FileDescription') || ' ' || dbo.xp_msver('ProductVersion')", SA_CmdSQLStmt);
		cmd.Execute();
		bASA = true;
	}
	catch(SAException &)
	{
	}

	if(!bASA)
	{
		// If we are on Adaptive Server Enterprise
		cmd.setCommandText("dbo.sp_server_info @attribute_id=2", SA_CmdSQLStmt);
		cmd.Execute();
	}

	cmd.FetchNext();
	SAString sVersion = cmd.Field(bASA? 1 : 3).asString();
	cmd.Close();

	return sVersion;
}

/*virtual */
bool IsybConnection::IsConnected() const
{
	return m_handles.m_connection != NULL;
}

/*virtual */
void IsybConnection::Connect(
	const SAString &sDBString,
	const SAString &sUserID,
	const SAString &sPassword)
{
	assert(m_handles.m_context != NULL);
	assert(m_handles.m_connection == NULL);

	CS_CONNECTION *connection = NULL;

	try
	{
		Check(g_sybAPI.ct_con_alloc(m_handles.m_context, &connection));

		Check(g_sybAPI.ct_con_props(
			connection, CS_SET,
			CS_USERNAME, (CS_VOID*)(const char*)sUserID, CS_NULLTERM, NULL));
		Check(g_sybAPI.ct_con_props(
			connection, CS_SET,
			CS_PASSWORD, (CS_VOID*)(const char*)sPassword, CS_NULLTERM, NULL));

		SAString sPacketSize = m_pSAConnection->Option("CS_PACKETSIZE");
		if(!sPacketSize.IsEmpty())
		{
			CS_INT nPacketSize = atoi(sPacketSize);
			Check(g_sybAPI.ct_con_props(
				connection, CS_SET,
				CS_PACKETSIZE, &nPacketSize, CS_UNUSED, NULL));
		}

		SAString sAppName = m_pSAConnection->Option("CS_APPNAME");
		if(!sAppName.IsEmpty())
			Check(g_sybAPI.ct_con_props(
				connection, CS_SET,
				CS_APPNAME, (CS_VOID*)(const char*)sAppName, CS_NULLTERM, NULL));

		SAString sHostName = m_pSAConnection->Option("CS_HOSTNAME");
		if(!sAppName.IsEmpty())
			Check(g_sybAPI.ct_con_props(
				connection, CS_SET,
				CS_HOSTNAME, (CS_VOID*)(const char*)sHostName, CS_NULLTERM, NULL));

		SAString sBulkLogin = m_pSAConnection->Option("CS_BULK_LOGIN");
		if(sBulkLogin.CompareNoCase("CS_TRUE") == 0)
		{
			CS_BOOL bulk_flag = CS_TRUE;
			Check(g_sybAPI.ct_con_props(
				connection, CS_SET,
				CS_BULK_LOGIN, (CS_VOID*)&bulk_flag, CS_UNUSED, NULL));
		}
		else if(sBulkLogin.CompareNoCase("CS_FALSE") == 0)
		{
			CS_BOOL bulk_flag = CS_FALSE;
			Check(g_sybAPI.ct_con_props(
				connection, CS_SET,
				CS_BULK_LOGIN, (CS_VOID*)&bulk_flag, CS_UNUSED, NULL));
		}

		int iPos = sDBString.FindOneOf(":\\@");
		m_sServerName = sDBString.Left(iPos);
		m_sDatabase = sDBString.Mid(iPos+1);

		Check(g_sybAPI.ct_connect(
			connection,
			m_sServerName.IsEmpty()? NULL : (CS_CHAR*)(const char*)m_sServerName,
			m_sServerName.IsEmpty()? 0 : CS_NULLTERM));

		m_handles.m_connection = connection;

		CS_INT nTextSize = 2147483647;
		Check(g_sybAPI.ct_options(
			m_handles.m_connection,
			CS_SET, CS_OPT_TEXTSIZE, &nTextSize, CS_UNUSED, NULL));

		if(!m_sDatabase.IsEmpty())
		{
			SAString sCmd("use ");
			sCmd += m_sDatabase;
			SACommand cmd(getSAConnection(), sCmd, SA_CmdSQLStmt);
			cmd.Execute();
			cmd.Close();
		}

		// start new transaction if needed
		Commit();
	}
	catch(SAException &)
	{
		// clean up
		if(m_handles.m_connection)	// ct_options or use database failed
		{
			CS_RETCODE rcd = CheckSilent(g_sybAPI.ct_close(m_handles.m_connection, CS_UNUSED));
			if(rcd != CS_SUCCEED)
				CheckSilent(g_sybAPI.ct_close(m_handles.m_connection, CS_FORCE_CLOSE));
			m_handles.m_connection = NULL;
		}
		if(connection)
			CheckSilent(g_sybAPI.ct_con_drop(connection));

		throw;
	}
}

/*virtual */
void IsybConnection::Disconnect()
{
	assert(m_handles.m_connection);

	Check(g_sybAPI.ct_close(m_handles.m_connection, CS_UNUSED));
	Check(g_sybAPI.ct_con_drop(m_handles.m_connection));
	m_handles.m_connection	= NULL;

	m_sServerName.Empty();
	m_sDatabase.Empty();
}

/*virtual */
void IsybConnection::Commit()
{
	// commit
	SACommand cmd(
		m_pSAConnection,
		"commit tran", SA_CmdSQLStmt);
	cmd.Execute();

	// and start new transaction if not in autocommit mode
	if(m_pSAConnection->AutoCommit() == SA_AutoCommitOff)
	{
		cmd.setCommandText("begin tran", SA_CmdSQLStmt);
		cmd.Execute();
	}

	cmd.Close();
}

/*virtual */
void IsybConnection::Rollback()
{
	// rollback
	SACommand cmd(
		m_pSAConnection,
		"rollback tran", SA_CmdSQLStmt);
	cmd.Execute();

	// and start new transaction if not in autocommit mode
	if(m_pSAConnection->AutoCommit() == SA_AutoCommitOff)
	{
		cmd.setCommandText("begin tran", SA_CmdSQLStmt);
		cmd.Execute();
	}

	cmd.Close();
}

//////////////////////////////////////////////////////////////////////
// IsybClient Class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IsybClient::IsybClient()
{

}

IsybClient::~IsybClient()
{

}

ISAConnection *IsybClient::QueryConnectionInterface(
	SAConnection *pSAConnection)
{
	return new IsybConnection(pSAConnection);
}

//////////////////////////////////////////////////////////////////////
// IsybCursor Class
//////////////////////////////////////////////////////////////////////

class IsybCursor : public ISACursor
{
	sybCommandHandles	m_handles;

	bool m_bResultsPending;
	void CheckAndCancelPendingResults();
	void CancelPendingResults();
	void ProcessBatchUntilEndOrResultSet();
	CS_INT	m_nRowsAffected;

	int m_cRowsToPrefetch;	// defined in SetSelectBuffers
	CS_INT m_cRowsObtained;
	CS_INT m_cRowCurrent;

	void BindImage(SAParam &Param, SAString *pValue);
	void BindText(SAParam &Param, SAString *pValue);

	void FetchStatusResult();
	void FetchParamResult();

protected:
	virtual unsigned int InputBufferSize(
		const SAParam &Param) const;
	virtual unsigned int OutputBufferSize(
		SADataType_t eDataType,
		unsigned int nDataSize) const;

	virtual SADataType_t CnvtNativeToStd(
		CS_INT nNativeType,
		CS_INT nPrec,
		CS_INT nScale) const;
	virtual int CnvtStdToNative(SADataType_t eDataType) const;

	SADataType_t CnvtNativeTypeFromASESysColumnsToStd(
		int dbtype, int/* dbsubtype*/, int/* dbsize*/, int prec, int scale) const;
	SADataType_t CnvtNativeTypeFromASADomainIDToStd(
		int dbtype, int/* dbsubtype*/, int/* dbsize*/, int prec, int scale) const;

protected:
	void ct_bind_Buffer(	// used for fields and output(return) params
		int nPos,	// 1-based
		void *pInd,
		unsigned int nIndSize,
		void *pSize,
		unsigned int nSizeSize,
		void *pValue,
		unsigned int nValueSize,
		SADataType_t eDataType,
		SAString sName,
		CS_INT count);

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
	IsybCursor(
		IsybConnection *pIsybConnection,
		SACommand *pCommand);
	virtual ~IsybCursor();

	virtual bool IsOpened();
	virtual void Open();
	virtual void Close();

	// prepare statement (also convert to native format if needed)
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

IsybCursor::IsybCursor(
	IsybConnection *pIsybConnection,
	SACommand *pCommand) :
	ISACursor(pIsybConnection, pCommand)
{
	m_bResultsPending = false;
	m_nRowsAffected = -1;
}

/*virtual */
IsybCursor::~IsybCursor()
{
}

/*virtual */
unsigned int IsybCursor::InputBufferSize(
	const SAParam &Param) const
{
	switch(Param.DataType())
	{
	case SA_dtBool:
		return sizeof(CS_BIT);
	case SA_dtDateTime:
		return sizeof(CS_DATETIME);
	case SA_dtLongBinary:
	case SA_dtLongChar:
	case SA_dtBLob:
	case SA_dtCLob:
		return 0;
	default:
		break;
	}
	
	return ISACursor::InputBufferSize(Param);
}

/*virtual */
unsigned int IsybCursor::OutputBufferSize(
	SADataType_t eDataType,
	unsigned int nDataSize) const
{
	switch(eDataType)
	{
	case SA_dtBool:
		return sizeof(CS_BIT);
	case SA_dtNumeric:
		return sizeof(CS_NUMERIC);
	case SA_dtDateTime:
		return sizeof(CS_DATETIME);
	case SA_dtLongBinary:
	case SA_dtLongChar:
		return 0;
	default:
		break;
	}
	
	return ISACursor::OutputBufferSize(eDataType, nDataSize);
}

SADataType_t IsybCursor::CnvtNativeTypeFromASADomainIDToStd(
	int dbtype, int/* dbsubtype*/, int/* dbsize*/, int prec, int scale) const
{
	SADataType_t eDataType = SA_dtUnknown;

	switch(dbtype)
	{
	case 11:	//binary
	case 28:	//varbinary
		eDataType = SA_dtBytes;
		break;
	case 7:		//char
	case 8:		//char
	case 9:		//varchar
		eDataType = SA_dtString;
		break;
	case 1:		//smallint
	case 19:	//tinyint
	case 22:	//unsigned smallint
		eDataType = SA_dtShort;
		break;
	case 24:	//bit
		eDataType = SA_dtBool;
		break;
	case 2:		//integer
	case 21:	//unsigned int
		eDataType = SA_dtLong;
		break;
	case 4:		//float
	case 5:		//double
		eDataType = SA_dtDouble;
		break;
	case 20:	//bigint
	case 23:	//unsigned bigint
		eDataType = SA_dtNumeric;
		break;
	case 3:		//numeric
	case 27:	//decimal
		if(scale <= 0)
		{	// check for exact type
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
	case 6:		//date
	case 13:	// timestamp
	case 14:	//time
		eDataType = SA_dtDateTime;
		break;
	case 12:	// long binary
		eDataType = SA_dtLongBinary;
		break;
	case 10:	//long varchar
		eDataType = SA_dtLongChar;
		break;
	default:
		assert(false);
	}

	return eDataType;
}

SADataType_t IsybCursor::CnvtNativeTypeFromASESysColumnsToStd(
	int dbtype, int/* dbsubtype*/, int/* dbsize*/, int prec, int scale) const
{
	SADataType_t eDataType = SA_dtUnknown;

	switch(dbtype)
	{
	case 0x25:	//SQLVARBINARY
		eDataType = SA_dtBytes;
		break;
	case 0x27:	//SQLVARCHAR
		eDataType = SA_dtString;
		break;
	case 0x2f:	//SQLCHAR:	// char, varchar
		eDataType = SA_dtString;

		break;
	case 0x2d:	//SQLBINARY:	// binary, varbinary
		eDataType = SA_dtBytes;
		break;
	case 0x30:	//SQLINT1:	// tinyint
		eDataType = SA_dtShort;
		break;
	case 0x34:	//SQLINT2:	// smallint
		eDataType = SA_dtShort;
		break;
	case 0x38:	//SQLINT4:	// int
		eDataType = SA_dtLong;
		break;
	case 0x3b:	//SQLFLT4:	// real
		eDataType = SA_dtDouble;
		break;
	case 0x3e:	//SQLFLT8:	// float
		eDataType = SA_dtDouble;
		break;
	case 0x7a:	//SQLMONEY4:	// smallmoney
		eDataType = SA_dtDouble;
		break;
	case 0x3c:	//SQLMONEY:	// money
		eDataType = SA_dtDouble;
		break;
	case 0x37:	// decimal
	case 0x3f:	// numeric
		if(scale <= 0)
		{	// check for exact type
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
	case 0x3a:	//SQLDATETIM4:	// smalldatetime
		eDataType = SA_dtDateTime;
		break;
	case 0x3d:	//SQLDATETIME:	// datetime
		eDataType = SA_dtDateTime;
		break;
	case 0x22:	//SQLIMAGE:	// image
		eDataType = SA_dtLongBinary;
		break;
	case 0x23:	//SQLTEXT:	// text
		eDataType = SA_dtLongChar;
		break;
	case 0x32:	//SQLBIT
		eDataType = SA_dtBool;
		break;
	default:
		assert(false);
	}

	return eDataType;
}

/*virtual */
SADataType_t IsybCursor::CnvtNativeToStd(
	CS_INT dbtype, CS_INT prec, CS_INT scale) const
{
	SADataType_t eDataType = SA_dtUnknown;

	switch(dbtype)
	{
	case CS_CHAR_TYPE:
		eDataType = SA_dtString;
		break;
	case CS_BINARY_TYPE:
		eDataType = SA_dtBytes;
		break;
	case CS_LONGCHAR_TYPE:
		eDataType = SA_dtLongChar;
		break;
	case CS_LONGBINARY_TYPE:
		eDataType = SA_dtLongBinary;
		break;
	case CS_TEXT_TYPE:
		eDataType = SA_dtLongChar;
		break;
	case CS_IMAGE_TYPE:
		eDataType = SA_dtLongBinary;
		break;
	case CS_TINYINT_TYPE:
		eDataType = SA_dtShort;
		break;
	case CS_SMALLINT_TYPE:
		eDataType = SA_dtShort;
		break;
	case CS_INT_TYPE:
		eDataType = SA_dtLong;
		break;
	case CS_REAL_TYPE:
		eDataType = SA_dtDouble;
		break;
	case CS_FLOAT_TYPE:
		eDataType = SA_dtDouble;
		break;
	case CS_BIT_TYPE:
		eDataType = SA_dtBool;
		break;
	case CS_DATETIME_TYPE:
		eDataType = SA_dtDateTime;
		break;
	case CS_DATETIME4_TYPE:
		eDataType = SA_dtDateTime;
		break;
	case CS_MONEY_TYPE:
		eDataType = SA_dtDouble;
		break;
	case CS_MONEY4_TYPE:
		eDataType = SA_dtDouble;
		break;
	case CS_NUMERIC_TYPE:
	case CS_DECIMAL_TYPE:
		if(scale > 0)
			eDataType = SA_dtNumeric;
		else	// check for exact type
		{	
			if(prec < 5)
				eDataType = SA_dtShort;
			else if(prec < 10)
				eDataType = SA_dtLong;
			else
				eDataType = SA_dtNumeric;
		}
		break;
	case CS_VARCHAR_TYPE:
		eDataType = SA_dtString;
		break;
	case CS_VARBINARY_TYPE:
		eDataType = SA_dtBytes;
		break;
	case CS_LONG_TYPE:
		assert(false);
		break;
	case CS_SENSITIVITY_TYPE:
		assert(false);
		break;
	case CS_BOUNDARY_TYPE:
		assert(false);
		break;
	case CS_VOID_TYPE:
		assert(false);
		break;
	case CS_USHORT_TYPE:
		assert(false);
		break;
	default:
		assert(false);
		break;
	}

	return eDataType;
}

/*virtual */
int IsybCursor::CnvtStdToNative(SADataType_t eDataType) const
{
	CS_INT type;

	switch(eDataType)
	{
	case SA_dtUnknown:
		throw SAException(SA_Library_Error, -1, -1, IDS_UNKNOWN_DATA_TYPE);
	case SA_dtBool:
		type = CS_BIT_TYPE;	// single bit type
		break;
	case SA_dtShort:
		type = CS_SMALLINT_TYPE;	// 2-byte integer type
		break;
	case SA_dtLong:
		type = CS_INT_TYPE;	// 4-byte integer type
		break;
	case SA_dtDouble:
		type = CS_FLOAT_TYPE;		// 8-byte float type
		break;
	case SA_dtNumeric:
		type = CS_NUMERIC_TYPE;		// Numeric type
		break;
	case SA_dtDateTime:
		type = CS_DATETIME_TYPE;	// 8-byte datetime type
		break;
	case SA_dtString:
		type = CS_CHAR_TYPE;		// character type
		break;
	case SA_dtBytes:
		type = CS_BINARY_TYPE;		// binary type
		break;
	case SA_dtLongBinary:
	case SA_dtBLob:
		type = CS_IMAGE_TYPE;		// image type
		break;
	case SA_dtLongChar:
	case SA_dtCLob:
		type = CS_TEXT_TYPE;		// text type
		break;
	default:
		type = 0;
		assert(false);
	}

	return type;
}

/*virtual */
bool IsybCursor::IsOpened()
{
	return m_handles.m_command != NULL;
}

/*virtual */
void IsybCursor::Open()
{
	assert(m_handles.m_command == NULL);

	((IsybConnection*)m_pISAConnection)->Check(g_sybAPI.ct_cmd_alloc(
		((IsybConnection*)m_pISAConnection)->m_handles.m_connection,
		&m_handles.m_command));
}

void IsybCursor::CancelPendingResults()
{
	// cancel any results pending
	((IsybConnection*)m_pISAConnection)->Check(g_sybAPI.ct_cancel(
		NULL, m_handles.m_command, CS_CANCEL_ALL));

	m_bResultsPending = false;
}

void IsybCursor::CheckAndCancelPendingResults()
{
	// cancel results pending if any
	if(m_bResultsPending)
		CancelPendingResults();
}

/*virtual */
void IsybCursor::Close()
{
	assert(m_handles.m_command != NULL);

	CancelPendingResults();

	((IsybConnection*)m_pISAConnection)->Check(g_sybAPI.ct_cmd_drop(m_handles.m_command));
	m_handles.m_command = NULL;
}

/*virtual */
ISACursor *IsybConnection::NewCursor(SACommand *m_pCommand)
{
	return new IsybCursor(this, m_pCommand);
}

/*virtual */
void IsybCursor::Prepare(
	const SAString &/*sStmt*/,
	SACommandType_t/* eCmdType*/,
	int/* nPlaceHolderCount*/,
	saPlaceHolder ** /*ppPlaceHolders*/)
{
	// no preparing in OpenClient
	// all is beeing done in Execute()
}

// process command batch or stored proc results
// stop if all commands processed or result set encounted
void IsybCursor::ProcessBatchUntilEndOrResultSet()
{
	bool bParamResult = false;
	bool bStatusResult = false;

	CS_RETCODE rcd;
	CS_INT res_type;
	while((rcd = ((IsybConnection*)m_pISAConnection)->Check(g_sybAPI.ct_results(
		m_handles.m_command, &res_type))) == CS_SUCCEED)
	{
		bool bResultSet = false;
		switch(res_type)
		{
			case CS_CMD_SUCCEED:	// Command returning no rows completed sucessfully
				break;
			case CS_CMD_DONE:		// This means we're done with one result set
				((IsybConnection *)m_pISAConnection)->Check(g_sybAPI.ct_res_info(
					m_handles.m_command,
					CS_ROW_COUNT,
					&m_nRowsAffected, CS_UNUSED, NULL));
				break;
			case CS_CMD_FAIL:		// This means that the server encountered an error while processing our command
				((IsybConnection *)m_pISAConnection)->Check(CS_FAIL);
				break;
			case CS_ROW_RESULT:
				bResultSet = true;
				break;
			case CS_STATUS_RESULT:
				FetchStatusResult();
				bStatusResult = true;				
				break;
			case CS_PARAM_RESULT:
				FetchParamResult();
				bParamResult = true;
				break;
			case CS_COMPUTE_RESULT:
				assert(false);
				break;
			default:
				assert(false);
		}

		if(bResultSet)
		{
			m_bResultsPending = true;
			return;
		}
	}

	// We've finished processing results. Let's check the
	// return value of ct_results() to see if everything
	// went ok.
	switch(rcd)
	{
	case CS_END_RESULTS:	// Everything went fine
		m_bResultsPending = false;
		if(bStatusResult || bParamResult)
			ConvertOutputParams();
		break;
	case CS_FAIL:			// Something went wrong
		((IsybConnection*)m_pISAConnection)->Check(rcd);
		break;
	default:				// We got an unexpected return value
		assert(false);
	}
}

/*virtual */
void IsybCursor::UnExecute()
{
	CheckAndCancelPendingResults();
}

/*virtual */
void IsybCursor::Execute(
	int nPlaceHolderCount,
	saPlaceHolder **ppPlaceHolders)
{
	// some kind of Prepare() first
	if(m_pCommand->CommandType() == SA_CmdStoredProc)
	{
		((IsybConnection*)m_pISAConnection)->Check(g_sybAPI.ct_command(
			m_handles.m_command,
			CS_RPC_CMD,
			(CS_CHAR*)(const char*)m_pCommand->CommandText(),
			CS_NULLTERM,
			CS_NO_RECOMPILE));
	}

	// always bind, even if no parameters
	// because Bind() does ct_command for non SP
	Bind(nPlaceHolderCount, ppPlaceHolders);

	((IsybConnection*)m_pISAConnection)->Check(g_sybAPI.ct_send(
		m_handles.m_command));

	try
	{

		ProcessBatchUntilEndOrResultSet();
	}
	catch(SAException &)	// clean up after ct_send
	{
		// cancel any results pending
		assert(!m_bResultsPending);
		g_sybAPI.ct_cancel(NULL, m_handles.m_command, CS_CANCEL_ALL);
		throw;
	}
}

/*virtual */
void IsybCursor::Cancel()
{
	((IsybConnection*)m_pISAConnection)->Check(g_sybAPI.ct_cancel(
		NULL, m_handles.m_command, CS_CANCEL_ALL));
}

void IsybCursor::BindImage(SAParam &Param, SAString *pValue)
{
	*pValue += "0x";

	unsigned int nActualWrite;
	SAPieceType_t ePieceType = SA_FirstPiece;
	void *pBuf;
	while((nActualWrite = Param.InvokeWriter(
		ePieceType, 0xffff, pBuf)) != 0)
	{
		*pValue += ((IsybConnection*)m_pISAConnection)->ConvertToString(
			CS_IMAGE_TYPE, (CS_VOID*)pBuf, nActualWrite);

		if(ePieceType == SA_LastPiece)
			break;
	}
}

void IsybCursor::BindText(SAParam &Param, SAString *pValue)
{
	*pValue += "'";

	unsigned int nActualWrite;
	SAPieceType_t ePieceType = SA_FirstPiece;
	void *pBuf;
	while((nActualWrite = Param.InvokeWriter(
		ePieceType, 0xffff, pBuf)) != 0)
	{
		SAString sTemp((const char *)pBuf, nActualWrite);
		sTemp.Replace("'", "''");
		*pValue += sTemp;

		if(ePieceType == SA_LastPiece)
			break;
	}

	*pValue += "'";
}

void IsybCursor::Bind(
		int nPlaceHolderCount,
		saPlaceHolder**	ppPlaceHolders)
{
	// always alloc bind buffer, even if we will not use it
	// 'exec SP' to work
	AllocBindBuffer(sizeof(CS_SMALLINT), sizeof(CS_INT));

	SAString sOriginalStmst = m_pCommand->CommandText();

	if(m_pCommand->CommandType() == SA_CmdSQLStmt)
	{
		// we will bind directly to command buffer
		CancelPendingResults();
		SAString sBoundStmt;

		// change ':' param markers to bound values
		unsigned int nPos = 0;
		for(int i = 0; i < nPlaceHolderCount; ++i)
		{
			SAParam &Param = *ppPlaceHolders[i]->getParam();

			sBoundStmt += sOriginalStmst.Mid(nPos, ppPlaceHolders[i]->getStart()-nPos);

			SAString sBoundValue;
			SAString sTemp;
			CS_BIT bitTemp;

			if(Param.isNull())
			{
				sBoundStmt += "NULL";
			}
			else
			{
				switch(Param.DataType())
				{
				case SA_dtUnknown:
					throw SAException(SA_Library_Error, -1, -1, IDS_UNKNOWN_PARAMETER_TYPE, (const char*)Param.Name());
				case SA_dtBool:
					bitTemp = (CS_BIT)Param.setAsBool();
					sBoundValue = ((IsybConnection*)m_pISAConnection)->ConvertToString(
						CS_BIT_TYPE, (CS_VOID*)&bitTemp, sizeof(CS_BIT));
					break;
				case SA_dtShort:
					sBoundValue = ((IsybConnection*)m_pISAConnection)->ConvertToString(
						CS_SMALLINT_TYPE, (CS_VOID*)&Param.setAsShort(), sizeof(short));
					break;
				case SA_dtLong:
					sBoundValue = ((IsybConnection*)m_pISAConnection)->ConvertToString(
						CS_INT_TYPE, (CS_VOID*)&Param.setAsLong(), sizeof(long));
					break;
				case SA_dtDouble:
					sBoundValue = ((IsybConnection*)m_pISAConnection)->ConvertToString(
						CS_FLOAT_TYPE, (CS_VOID*)&Param.setAsDouble(), sizeof(double));
					break;
				case SA_dtDateTime:
					IsybConnection::CnvtDateTimeToInternal(
						Param.setAsDateTime(), sTemp);
					sBoundValue = "'";
					sBoundValue += sTemp;
					sBoundValue += "'";
					break;
				case SA_dtString:
					sTemp = Param.asString();
					sTemp.Replace("'", "''");
					sBoundValue = "'";
					sBoundValue += sTemp;
					sBoundValue += "'";
					break;
				case SA_dtBytes:
					sBoundValue = "0x";
					sBoundValue += ((IsybConnection*)m_pISAConnection)->ConvertToString(
						CS_BINARY_TYPE, (CS_VOID*)(const char*)Param.asBytes(), Param.asBytes().GetLength());
					break;
				case SA_dtLongBinary:
				case SA_dtBLob:
					BindImage(Param, &sBoundStmt);
					break;
				case SA_dtLongChar:
				case SA_dtCLob:
					BindText(Param, &sBoundStmt);
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

		((IsybConnection*)m_pISAConnection)->Check(g_sybAPI.ct_command(
			m_handles.m_command,
			CS_LANG_CMD, (CS_CHAR*)(const char*)sBoundStmt, CS_NULLTERM,
			CS_UNUSED));
	}
	else
	{
		assert(m_pCommand->CommandType() == SA_CmdStoredProc);

		void *pBuf = m_pParamBuffer;

		for(int i = 0; i < m_pCommand->ParamCount(); ++i)
		{
			SAParam &Param = m_pCommand->ParamByIndex(i);

			void *pInd;
			void *pSize;
			unsigned int nDataBufSize;
			void *pValue;
			IncParamBuffer(pBuf, pInd, pSize, nDataBufSize, pValue);

			if(Param.ParamDirType() == SA_ParamReturn)
				continue;

			SAString sName = "@";
			sName += Param.Name();

			SADataType_t eDataType = Param.DataType();
			CS_INT type = (CS_INT)CnvtStdToNative(eDataType);
			CS_SMALLINT &indicator = *(CS_SMALLINT*)pInd;
			CS_INT &datalen = *(CS_INT*)pSize;
			CS_VOID *data;

			if(Param.isNull())
			{
				indicator = -1;
				datalen = CS_UNUSED;
				pValue = NULL;
			}

			if(isInputParam(Param))
			{
				unsigned int nInputBufSize = InputBufferSize(Param);
				assert(nInputBufSize <= nDataBufSize);

				if(!Param.isNull())
				{
					indicator = 0;
					datalen = (CS_INT)nInputBufSize;
					data = (CS_VOID*)pValue;

					switch(eDataType)
					{
						case SA_dtUnknown:
							throw SAException(SA_Library_Error, -1, -1, IDS_UNKNOWN_PARAMETER_TYPE, (const char*)Param.Name());
						case SA_dtBool:
							assert(nInputBufSize == sizeof(CS_BIT));
							*(CS_BIT*)data = (CS_BIT)Param.asBool();
							break;
						case SA_dtShort:
							assert(nInputBufSize == sizeof(short));
							*(short*)data = Param.asShort();
							break;
						case SA_dtLong:
							assert(nInputBufSize == sizeof(long));
							*(long*)data = Param.asLong();
							break;
						case SA_dtDouble:
							assert(nInputBufSize == sizeof(double));
							*(double*)data = Param.asDouble();
							break;
						case SA_dtDateTime:
							assert(nInputBufSize == sizeof(CS_DATETIME));	// Sybase internal date/time representation
							((IsybConnection*)m_pISAConnection)->CnvtDateTimeToInternal(
								Param.asDateTime(),
								(CS_DATETIME*)data);
							break;
						case SA_dtString:
							assert((int)nInputBufSize == Param.asString().GetLength());
							memcpy(data, (const char*)Param.asString(), nInputBufSize);
							break;
						case SA_dtBytes:
							assert((int)nInputBufSize == Param.asBytes().GetLength());
							memcpy(data, (const char*)Param.asBytes(), nInputBufSize);
							break;
						case SA_dtLongBinary:
						case SA_dtBLob:
						case SA_dtLongChar:
						case SA_dtCLob:
							if(Param.m_fnWriter != NULL)	// use internal buffer as temp
							{
								Param.m_pString->Empty();

								unsigned int nActualWrite;
								SAPieceType_t ePieceType = SA_FirstPiece;
								void *pBuf;
								while((nActualWrite = Param.InvokeWriter(
									ePieceType, 0xffff, pBuf)) != 0)
								{
									(*Param.m_pString) += SAString((const char*)pBuf, nActualWrite);

									if(ePieceType == SA_LastPiece)
										break;
								}
							}
							pValue = (void*)(const char*)(*Param.m_pString);
							datalen = (CS_INT)Param.m_pString->GetLength();
							break;
						default:
							assert(false);
					}
				}
			}

			CS_DATAFMT df;
			strcpy(df.name, sName);
			df.namelen = sName.GetLength();
			df.datatype = type;
			df.maxlength = (CS_INT)nDataBufSize;
			df.scale = CS_SRC_VALUE;
			df.precision = CS_SRC_VALUE;
			df.status = isOutputParam(Param)? CS_RETURN : CS_INPUTVALUE;
			df.locale = NULL;
			((IsybConnection*)m_pISAConnection)->Check(g_sybAPI.ct_param(
				m_handles.m_command,
				&df,
				(CS_VOID*)pValue,
				datalen,
				indicator));
		}
	}
}

/*virtual */
bool IsybCursor::ResultSetExists()
{
	return m_bResultsPending;
}

/*virtual */
void IsybCursor::DescribeFields(
	DescribeFields_cb_t fn)
{
	CS_INT nNumData;
	((IsybConnection*)m_pISAConnection)->Check(g_sybAPI.ct_res_info(
		m_handles.m_command,
		CS_NUMDATA,
		&nNumData,
		CS_UNUSED,
		NULL));

	for(CS_INT iField = 1; iField <= nNumData; ++iField)
	{
		CS_DATAFMT df;

		((IsybConnection*)m_pISAConnection)->Check(g_sybAPI.ct_describe(
			m_handles.m_command,
			(CS_INT)iField,
			&df));

		(m_pCommand->*fn)(
			SAString(df.name, df.namelen),
			CnvtNativeToStd(
				df.datatype,
				df.precision,
				df.scale),
			(int)df.datatype,
			df.maxlength,
			df.precision,
			df.scale,
			(df.status & CS_CANBENULL) == 0);
	}
}

/*virtual */
long IsybCursor::GetRowsAffected()
{
	return m_nRowsAffected;
}

void IsybCursor::ct_bind_Buffer(
	int nCol,	// 1-based
	void *pInd,
	unsigned int nIndSize,
	void *pSize,
	unsigned int nSizeSize,
	void *pValue,
	unsigned int nValueSize,
	SADataType_t eDataType,
	SAString sName,
	CS_INT count)
{
	assert(nIndSize == sizeof(CS_SMALLINT));
	if(nIndSize != sizeof(CS_SMALLINT))
		return;
	assert(nSizeSize == sizeof(CS_INT));
	if(nSizeSize != sizeof(CS_INT))
		return;

	CS_DATAFMT datafmt;
	datafmt.datatype = (CS_INT)CnvtStdToNative(eDataType);
	datafmt.count = count;
	datafmt.format = CS_FMT_UNUSED;
	datafmt.maxlength = nValueSize;
	datafmt.scale = CS_SRC_VALUE;
	datafmt.precision = CS_SRC_VALUE;
	datafmt.locale = NULL;

	bool bLong = false;
	switch(eDataType)
	{
		case SA_dtUnknown:
			throw SAException(SA_Library_Error, -1, -1, IDS_UNKNOWN_COLUMN_TYPE, (const char*)sName);
		case SA_dtBool:
			assert(datafmt.maxlength >= (CS_INT)sizeof(CS_BIT));
			break;
		case SA_dtShort:
			assert(datafmt.maxlength >= (CS_INT)sizeof(short));
			break;
		case SA_dtLong:
			assert(datafmt.maxlength >= (CS_INT)sizeof(long));
			break;
		case SA_dtDouble:
			assert(datafmt.maxlength >= (CS_INT)sizeof(double));
			break;
		case SA_dtNumeric:
			assert(datafmt.maxlength >= (CS_INT)sizeof(CS_NUMERIC));
			break;
		case SA_dtDateTime:
			assert(datafmt.maxlength >= (CS_INT)sizeof(CS_DATETIME));
			break;
		case SA_dtString:
			break;
		case SA_dtBytes:
			break;
		case SA_dtLongBinary:
		case SA_dtLongChar:
			bLong = true;
			break;
		default:
			assert(false);	// unknown type
	}
	
	if(!bLong)
	{
		((IsybConnection*)m_pISAConnection)->Check(g_sybAPI.ct_bind(
			m_handles.m_command,
			nCol,
			&datafmt,
			(CS_VOID*)pValue,
			(CS_INT*)pSize,
			(CS_SMALLINT*)pInd));
	}
}

/*virtual */
void IsybCursor::SetFieldBuffer(
	int nCol,	// 1-based
	void *pInd,
	unsigned int nIndSize,
	void *pSize,
	unsigned int nSizeSize,
	void *pValue,
	unsigned int nValueSize)
{
	SAField &Field = m_pCommand->Field(nCol);

	ct_bind_Buffer(
		nCol,
		pInd, nIndSize,
		pSize, nSizeSize,
		pValue, nValueSize,
		Field.FieldType(), Field.Name(),
		m_cRowsToPrefetch);
}

/*virtual */
void IsybCursor::SetSelectBuffers()
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
	
	// use default helpers
	AllocSelectBuffer(sizeof(CS_SMALLINT), sizeof(CS_INT), m_cRowsToPrefetch);
}

/*virtual */
bool IsybCursor::IndicatorIsNull(
	int nPos,	// 1-based, can be field or param pos
	SAValueRead &vr,
	ValueType_t eValueType,
	void *pInd, unsigned int nIndSize,
	void *pSize, unsigned int nSizeSize,
	unsigned int &nRealSize,
	int nBulkReadingBufPos) const
{
	if(!isLongOrLob(vr.DataType()))
		return ISACursor::IndicatorIsNull(
			nPos, vr, eValueType,
			pInd, nIndSize,
			pSize, nSizeSize,
			nRealSize,
			nBulkReadingBufPos);

	char pBuf[1];
	CS_RETCODE rcd = ((IsybConnection*)m_pISAConnection)->Check(g_sybAPI.ct_get_data(
		m_handles.m_command,
		nPos,
		pBuf, 0,
		NULL));
	if(rcd == CS_END_ITEM || rcd == CS_END_DATA)
		return true;

	return false;
}

void IsybCursor::FetchParamResult()
{
	// first bind all output params
	int nOutputs = 0;
	void *pBuf = m_pParamBuffer;
	for(int i = 0; i < m_pCommand->ParamCount(); ++i)
	{
		SAParam &Param = m_pCommand->ParamByIndex(i);

		void *pNull;
		void *pSize;
		unsigned int nDataBufSize;
		void *pValue;
		IncParamBuffer(pBuf, pNull, pSize, nDataBufSize, pValue);

		if(!isOutputParam(Param))
			continue;
		if(Param.ParamDirType() == SA_ParamReturn)
			continue;
		else
		{
			++nOutputs;
		}

		ct_bind_Buffer(
			nOutputs,
			pNull, sizeof(CS_SMALLINT),
			pSize, sizeof(CS_INT),
			pValue, nDataBufSize,
			Param.DataType(), Param.Name(),
			1);
	}

	// then fetch parameter row
	CS_INT nRowsRead;
	CS_RETCODE rcd = ((IsybConnection*)m_pISAConnection)->Check(g_sybAPI.ct_fetch(
		m_handles.m_command,
		CS_UNUSED,
		CS_UNUSED,
		CS_UNUSED,
		&nRowsRead));
	assert(nRowsRead == 1);

	while(rcd != CS_END_DATA)
	{
		rcd = ((IsybConnection*)m_pISAConnection)->Check(g_sybAPI.ct_fetch(
			m_handles.m_command,
			CS_UNUSED,
			CS_UNUSED,
			CS_UNUSED,
			NULL/*&nRowsRead*/));
	}
}

void IsybCursor::FetchStatusResult()
{
	// first bind return status
	void *pBuf = m_pParamBuffer;
	for(int i = 0; i < m_pCommand->ParamCount(); ++i)
	{
		SAParam &Param = m_pCommand->ParamByIndex(i);

		void *pNull;
		void *pSize;
		unsigned int nDataBufSize;
		void *pValue;
		IncParamBuffer(pBuf, pNull, pSize, nDataBufSize, pValue);

		if(Param.ParamDirType() != SA_ParamReturn)
			continue;

		ct_bind_Buffer(
			1,
			pNull, sizeof(CS_SMALLINT),
			pSize, sizeof(CS_INT),
			pValue, nDataBufSize,
			Param.DataType(), Param.Name(),
			1);
	}

	// then fetch return status
	CS_INT nRowsRead;
	CS_RETCODE rcd = ((IsybConnection*)m_pISAConnection)->Check(g_sybAPI.ct_fetch(
		m_handles.m_command,
		CS_UNUSED,
		CS_UNUSED,
		CS_UNUSED,
		&nRowsRead));
	assert(nRowsRead == 1);

	while(rcd != CS_END_DATA)
	{
		rcd = ((IsybConnection*)m_pISAConnection)->Check(g_sybAPI.ct_fetch(
			m_handles.m_command,
			CS_UNUSED,
			CS_UNUSED,
			CS_UNUSED,
			NULL/*&nRowsRead*/));
	}
}

/*virtual */
bool IsybCursor::FetchNext()
{
	assert(m_bResultsPending == true);

	if(m_cRowCurrent == m_cRowsObtained)
	{
		CS_RETCODE rcd = ((IsybConnection*)m_pISAConnection)->Check(g_sybAPI.ct_fetch(
			m_handles.m_command,
			CS_UNUSED,
			CS_UNUSED,
			CS_UNUSED,
			&m_cRowsObtained));
		if(rcd == CS_END_DATA)
			m_cRowsObtained = 0;

		m_cRowCurrent = 0;
	}

	if(m_cRowsObtained)
	{
		// use default helpers
		ConvertSelectBufferToFields(m_cRowCurrent++);
	}
	else
		ProcessBatchUntilEndOrResultSet();

	return m_cRowsObtained != 0;
}

/*virtual */
void IsybCursor::ReadLongOrLOB(
	ValueType_t /* eValueType*/,
	SAValueRead &vr,
	void * /*pValue*/,
	unsigned int/* nBufSize*/,
	saLongOrLobReader_t fnReader,
	unsigned int nReaderWantedPieceSize,
	void *pAddlData)
{
	SAField &Field = (SAField &)vr;

	// get long size
	CS_IODESC iodesc;
	((IsybConnection*)m_pISAConnection)->Check(g_sybAPI.ct_data_info(
		m_handles.m_command,
		CS_GET,
		Field.Pos(),
		&iodesc));

	CS_INT nLongLen = iodesc.total_txtlen;
	assert(nLongLen > 0);	// known

	unsigned char* pBuf;
	unsigned int nPortionSize = vr.PrepareReader(
		nLongLen,
		IsybConnection::MaxLongPiece,
		pBuf,
		fnReader,
		nReaderWantedPieceSize,
		pAddlData);
	assert(nPortionSize <= IsybConnection::MaxLongPiece);

	SAPieceType_t ePieceType = SA_FirstPiece;
	unsigned int nTotalRead = 0;
	do
	{
		nPortionSize =
			sa_min(nPortionSize, nLongLen - nTotalRead);

		CS_INT nActualRead;
		((IsybConnection*)m_pISAConnection)->Check(g_sybAPI.ct_get_data(
			m_handles.m_command,
			Field.Pos(),
			pBuf, nPortionSize,
			&nActualRead));

		nTotalRead += nActualRead;

		if(nTotalRead == (unsigned int)nLongLen)
		{
			if(ePieceType == SA_NextPiece)
				ePieceType = SA_LastPiece;
			else    // the whole BLob was read in one piece
			{
				assert(ePieceType == SA_FirstPiece);
				ePieceType = SA_OnePiece;
			}
		}
		vr.InvokeReader(ePieceType, pBuf, nActualRead);

		if(ePieceType == SA_FirstPiece)
			ePieceType = SA_NextPiece;
	}
	while(nTotalRead < (unsigned int)nLongLen);
	assert((CS_INT)nTotalRead == nLongLen);
}

/*virtual */
void IsybCursor::DescribeParamSP()
{
	SACommand cmd(m_pISAConnection->getSAConnection());

	SAString sProcName = m_pCommand->CommandText();
	SAString sSQL;

	bool bASA = false;
	try
	{
		// Check if we are on Adaptive Server Anywhere
		sSQL.Format(
			"select"
			"  spp.parm_name as name, spp.domain_id as type, spp.width as length, spp.width as prec, spp.scale,"
			"  spp.parm_mode_in || spp.parm_mode_out as parm_mode "
			"from"
			"  sysobjects so,"
			"  sysprocedure sp, sysprocparm spp "
			"where"
			"  so.id = object_id('%s') and so.type = 'P' and"
			"  so.name = sp.proc_name and so.uid = sp.creator and"
			"  spp.proc_id = sp.proc_id and"
			"  spp.parm_type = 0 "
			"order by"
			"  spp.parm_id", (const char*)sProcName);
		cmd.setCommandText(sSQL);
		cmd.Execute();
		bASA = true;
	}
	catch(SAException &)
	{
	}

	if(!bASA)
	{
		// If we are on Adaptive Server Enterprise
		sSQL.Format(
			"select"
			"  sc.name, sc.type, sc.length, sc.prec, sc.scale,"
			"  'YN' as parm_mode "
			"from"
			"  dbo.sysobjects so, dbo.syscolumns sc "
			"where"
			"  so.id = object_id('%s') and so.type = 'P' and"
			"  so.id = sc.id "
			"order by"
			"  sc.colid", (const char*)sProcName);
		cmd.setCommandText(sSQL);
		cmd.Execute();
	}

	while(cmd.FetchNext())
	{
		SAString sName = cmd["name"].asString();
		// if "name" database field is CHAR it could be right padded with spaces
		sName.TrimRight(' ');
		if(sName.Left(1) == "@")
			sName.Delete(0);

		int nParamSize = cmd["length"].asShort();
		short nType = cmd["type"].asShort();
		short nPrec = cmd["prec"].isNull()? (short)0 : cmd["prec"].asShort();
		short nScale = cmd["scale"].isNull()? (short)0 : cmd["scale"].asShort();
		SADataType_t eDataType = bASA?
			CnvtNativeTypeFromASADomainIDToStd(
			nType,
			0, nParamSize,
			nPrec,
			nScale) :
			CnvtNativeTypeFromASESysColumnsToStd(
			nType,
			0,
			nParamSize,	nPrec, nScale);

		SAParamDirType_t eDirType = SA_ParamInput;
		SAString sParmMode = cmd["parm_mode"].asString();
		if(sParmMode == "YN")
			eDirType = SA_ParamInput;
		else if(sParmMode == "YY")
			eDirType = SA_ParamInputOutput;
		else if(sParmMode == "NY")
			eDirType = SA_ParamOutput;
		else
			assert(false);

		m_pCommand->CreateParam(sName,
			eDataType,
			IsybCursor::CnvtStdToNative(eDataType),
			nParamSize, nPrec, nScale,
			eDirType);
	}

	// now check if SA_Param_Return parameter is described
	// if not (currently true for Sybase ASE and ASA) add it manually
	m_pCommand->CreateParam(
		_SA("RETURN_VALUE"),
		SA_dtLong,
		IsybCursor::CnvtStdToNative(SA_dtLong),
		sizeof(long), 0, 0,	// precision and scale as reported by native API
		SA_ParamReturn);
}

/*virtual */
saAPI *IsybConnection::NativeAPI() const
{
	return &g_sybAPI;
}

/*virtual */
saConnectionHandles *IsybConnection::NativeHandles()
{
	return &m_handles;
}

/*virtual */
saCommandHandles *IsybCursor::NativeHandles()
{
	return &m_handles;
}

/*virtual */
void IsybConnection::setIsolationLevel(
	SAIsolationLevel_t eIsolationLevel)
{
//	if(false)
//	{
//		CS_INT level;
//
//		switch(eIsolationLevel)
//		{
//		case SA_ReadUncommitted:
//			level = CS_OPT_LEVEL0;
//			break;
//		case SA_ReadCommitted:
//			level = CS_OPT_LEVEL1;
//			break;
//		case SA_RepeatableRead:
//			level = 2; //CS_OPT_LEVEL2;
//			break;
//		case SA_Serializable:
//			level = CS_OPT_LEVEL3;
//			break;
//		default:
//			assert(false);
//			return;
//		}
//
//		Check(g_sybAPI.ct_options(
//			m_handles.m_connection,
//			CS_SET, CS_OPT_ISOLATION, &level, CS_UNUSED, NULL));
//
//		return;
//	}

	SAString sCmd("set transaction isolation level ");
	SACommand cmd(m_pSAConnection);

	switch(eIsolationLevel)
	{
	case SA_ReadUncommitted:
		sCmd += "0\0read uncommitted";
		break;
	case SA_ReadCommitted:
		sCmd += "1\0read committed";
		break;
	case SA_RepeatableRead:
		sCmd += "2\0repeatable read";
		break;
	case SA_Serializable:
		sCmd += "3\0serializable";
		break;
	default:
		assert(false);
		return;
	}

	cmd.setCommandText(sCmd, SA_CmdSQLStmt);
	cmd.Execute();
	cmd.Close();
}

/*virtual */
void IsybConnection::setAutoCommit(
	SAAutoCommit_t eAutoCommit)
{
	SACommand cmd(m_pSAConnection);
	cmd.setCommandText("commit tran", SA_CmdSQLStmt);
	cmd.Execute();

	if(eAutoCommit == SA_AutoCommitOff)
	{
		cmd.setCommandText("begin tran", SA_CmdSQLStmt);
		cmd.Execute();
	}

	cmd.Close();
}

//////////////////////////////////////////////////////////////////////
// sybExternalConnection Class
//////////////////////////////////////////////////////////////////////

sybExternalConnection::sybExternalConnection(
	SAConnection *pCon,
	CS_CONTEXT *context,
	CS_CONNECTION *connection)
{
	m_bAttached = false;

	m_pCon = pCon;

	m_context = context;
	m_connection = connection;
	m_pExternalUserData = ::malloc(sizeof(void *));
	m_nExternalUserDataAllocated = sizeof(void *);
}

void sybExternalConnection::Attach()
{
	Detach();	// if any

	if(m_pCon->isConnected())
		m_pCon->Disconnect();
	m_pCon->setClient(SA_Sybase_Client);

	sybAPI *psybAPI = (sybAPI *)m_pCon->NativeAPI();
	sybConnectionHandles *psybConnectionHandles = (sybConnectionHandles *)
		m_pCon->NativeHandles();

	CS_RETCODE rc;
	// save original callbacks for "external" handles
	// we will later replace them with SQLAPI++ compatible ones
	rc = psybAPI->ct_callback(
		m_context, NULL, CS_GET, CS_CLIENTMSG_CB,
		&m_ExternalContextClientMsg_cb);
	assert(rc == CS_SUCCEED);
	rc = psybAPI->ct_callback(
		m_context, NULL, CS_GET, CS_SERVERMSG_CB,
		&m_ExternalContextServerMsg_cb);
	assert(rc == CS_SUCCEED);
	rc = psybAPI->ct_callback(
		NULL, m_connection, CS_GET, CS_CLIENTMSG_CB,
		&m_ExternalConnectionClientMsg_cb);
	assert(rc == CS_SUCCEED);
	rc = psybAPI->ct_callback(
		NULL, m_connection, CS_GET, CS_SERVERMSG_CB,
		&m_ExternalConnectionServerMsg_cb);
	assert(rc == CS_SUCCEED);
	// disable original callbacks for "external" context
	rc = psybAPI->ct_callback(
		m_context, NULL, CS_SET, CS_CLIENTMSG_CB,
		NULL);
	assert(rc == CS_SUCCEED);
	rc = psybAPI->ct_callback(
		m_context, NULL, CS_SET, CS_SERVERMSG_CB,
		NULL);
	assert(rc == CS_SUCCEED);

	// save original user data for "external" context handle
	// we will later replace it with SQLAPI++ compatible
	rc = psybAPI->cs_config(
		m_context, CS_GET, CS_USERDATA,
		m_pExternalUserData, m_nExternalUserDataAllocated,
		&m_nExternalUserDataLen);
	if(rc != CS_SUCCEED)
	{
		m_pExternalUserData = ::realloc(m_pExternalUserData, m_nExternalUserDataLen);
		m_nExternalUserDataAllocated = m_nExternalUserDataLen;
		rc = psybAPI->cs_config(
			m_context, CS_GET, CS_USERDATA,
			m_pExternalUserData, m_nExternalUserDataAllocated,
			NULL);
		assert(rc == CS_SUCCEED);
	}

	// get original callback handlers for client and server messages
	// (context level callbacks)
	CS_VOID	*SQLAPIClientMsg_cb = NULL;
	CS_VOID	*SQLAPIServerMsg_cb = NULL;
	rc = psybAPI->ct_callback(
		psybConnectionHandles->m_context, NULL, CS_GET, CS_CLIENTMSG_CB,
		&SQLAPIClientMsg_cb);
	assert(rc == CS_SUCCEED);
	rc = psybAPI->ct_callback(
		psybConnectionHandles->m_context, NULL, CS_GET, CS_SERVERMSG_CB,
		&SQLAPIServerMsg_cb);
	assert(rc == CS_SUCCEED);

	// replace "external" context user data with SQLAPI++ compatible
	SybErrInfo_t *pSybErrInfo = &m_SybErrInfo;
	memset(pSybErrInfo, 0, sizeof(SybErrInfo_t));
	rc = psybAPI->cs_config(
		m_context,
		CS_SET,
		CS_USERDATA,
		&pSybErrInfo,
		sizeof(SybErrInfo_t *),
		NULL);
	assert(rc == CS_SUCCEED);

	// replace "external" callbacks with SQLAPI++ default ones
	rc = psybAPI->ct_callback(
		m_context, NULL, CS_SET, CS_CLIENTMSG_CB,
		SQLAPIClientMsg_cb);
	assert(rc == CS_SUCCEED);
	rc = psybAPI->ct_callback(
		m_context, NULL, CS_SET, CS_SERVERMSG_CB,
		SQLAPIServerMsg_cb);
	assert(rc == CS_SUCCEED);
	rc = psybAPI->ct_callback(
		NULL, m_connection, CS_SET, CS_CLIENTMSG_CB,
		SQLAPIClientMsg_cb);
	assert(rc == CS_SUCCEED);
	rc = psybAPI->ct_callback(
		NULL, m_connection, CS_SET, CS_SERVERMSG_CB,
		SQLAPIServerMsg_cb);
	assert(rc == CS_SUCCEED);

	// save original SAConnection handles
	m_contextSaved = psybConnectionHandles->m_context;
	m_connectionSaved = psybConnectionHandles->m_connection;
	// replace SAConnection handles with "external" ones
	psybConnectionHandles->m_context = m_context;
	psybConnectionHandles->m_connection = m_connection;

	m_bAttached = true;
}

void sybExternalConnection::Detach()
{
	if(!m_bAttached)
		return;

	assert(m_pCon->isConnected());
	sybAPI *psybAPI = (sybAPI *)m_pCon->NativeAPI();
	sybConnectionHandles *psybConnectionHandles = (sybConnectionHandles *)
		m_pCon->NativeHandles();

	// restore original SAConnection handles
	psybConnectionHandles->m_context = m_contextSaved;
	psybConnectionHandles->m_connection = m_connectionSaved;

	CS_RETCODE rc;
	// restore "external" context user data
	if(m_nExternalUserDataLen)
		rc = psybAPI->cs_config(
			m_context,
			CS_SET,
			CS_USERDATA,
			m_pExternalUserData,
			m_nExternalUserDataLen,
			NULL);
	else
		rc = psybAPI->cs_config(
			m_context,
			CS_CLEAR,
			CS_USERDATA,
			NULL,
			CS_UNUSED,
			NULL);
	assert(rc == CS_SUCCEED);
	// restore "external" handles callbacks
	rc = psybAPI->ct_callback(
		m_context, NULL, CS_SET, CS_CLIENTMSG_CB,
		m_ExternalContextClientMsg_cb);
	assert(rc == CS_SUCCEED);
	rc = psybAPI->ct_callback(
		m_context, NULL, CS_SET, CS_SERVERMSG_CB,
		m_ExternalContextServerMsg_cb);
	assert(rc == CS_SUCCEED);
	rc = psybAPI->ct_callback(
		NULL, m_connection, CS_SET, CS_CLIENTMSG_CB,
		m_ExternalConnectionClientMsg_cb);
	assert(rc == CS_SUCCEED);
	rc = psybAPI->ct_callback(
		NULL, m_connection, CS_SET, CS_SERVERMSG_CB,
		m_ExternalConnectionServerMsg_cb);
	assert(rc == CS_SUCCEED);

	m_bAttached = false;
}

sybExternalConnection::~sybExternalConnection()
{
	try
	{
		Detach();
	}
	catch(SAException &)
	{
	}
}

/*virtual */
void IsybConnection::CnvtInternalToNumeric(
	SANumeric &numeric,
	const void *pInternal,
	int nInternalSize)
{
	assert(nInternalSize <= sizeof(CS_NUMERIC));
	CS_NUMERIC *pCS_NUMERIC = (CS_NUMERIC *)pInternal;

	numeric.precision = pCS_NUMERIC->precision;
	numeric.scale = pCS_NUMERIC->scale;
	// Now let us set sign
	// Sybase: first byte from array is sign byte
	// 1 for negative numbers, 0 for positive numbers
	// SQLAPI++: numeric.sign is 1 for positive numbers, 0 for negative numbers
	numeric.sign = (unsigned char)(pCS_NUMERIC->array[0]? 0:1);

	// copy mantissa
	// Sybase: big endian format
	// SQLAPI: little endian format
	memset(numeric.val, 0, sizeof(numeric.val));
	/*
	unsigned int SybaseMantissaSize = nInternalSize - ((unsigned int)&pCS_NUMERIC->array[1] - (unsigned int)pCS_NUMERIC);
	int nBytesToCopy = sa_min(SybaseMantissaSize, sizeof(numeric.val));
	int iLittleEndian = 0;
	while(nBytesToCopy)
		numeric.val[iLittleEndian++] = pCS_NUMERIC->array[1 + --nBytesToCopy]; */
}
