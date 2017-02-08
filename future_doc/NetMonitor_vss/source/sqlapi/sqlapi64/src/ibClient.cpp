// ibClient.cpp: implementation of the IibClient class.
//
//////////////////////////////////////////////////////////////////////

#include <SQLAPI.h>
#include "ibClient.h"

#include <malloc.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include <ibAPI.h>

#include "samisc.h"
#include "errmsg.h"

//////////////////////////////////////////////////////////////////////
// IibConnection Class
//////////////////////////////////////////////////////////////////////

class IibConnection : public ISAConnection  
{
	friend class IibCursor;

	ibConnectionHandles m_handles;

	ISC_STATUS		m_StatusVector[20];		// Error status vector
	char			*m_DPB_buffer;			// Address of the DPB
	short			m_DPB_buffer_length;	// Number of bytes in the database parameter buffer (DPB)
	char			m_TPB_buffer[1024];		// Address of the TPB
	short			m_TPB_buffer_length;	// Number of bytes in the transaction parameter buffer (TPB)

	static void Check(
		const ISC_STATUS &,
		ISC_STATUS* pSV);
	static SAString FormatIdentifierValue(
		unsigned short nSQLDialect,
		const SAString &sValue);

	enum {MaxBlobPiece = (unsigned int)0xFFFF};

	static void ExtractServerVersionCallback(long *pnVersion, char *sStr);
	static void ExtractServerVersionStringCallback(SAString *psVersion, char *sStr);

	// transaction management helpers
	void StartTransaction();
	void ConstructTPB(
		SAIsolationLevel_t eIsolationLevel,
		SAAutoCommit_t eAutoCommit);
	void CommitTransaction();
	void CommitRetaining();
	void RollbackTransaction();

protected:
	virtual ~IibConnection();

public:
	IibConnection(SAConnection *pSAConnection);

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
		const ISC_QUAD &Internal);
	static void CnvtDateTimeToInternal(
		const SADateTime &date_time,
		ISC_QUAD &Internal);

	virtual void CnvtInternalToCursor(
		SACommand *pCursor,
		const void *pInternal);
};

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IibConnection::IibConnection(
	SAConnection *pSAConnection) : ISAConnection(pSAConnection)
{
	m_DPB_buffer	= NULL;
	m_DPB_buffer_length = 0;

	m_TPB_buffer_length = 0;
}

IibConnection::~IibConnection()
{
	if(m_DPB_buffer)
		::free(m_DPB_buffer);
}

/*virtual */
void IibConnection::InitializeClient()
{
	::AddIB5Support();
}

/*virtual */
void IibConnection::UnInitializeClient()
{
	::ReleaseIB5Support();
}

/*virtual */
void IibConnection::CnvtInternalToDateTime(
	SADateTime &date_time,
	const void *pInternal,
	int nInternalSize)
{
	assert(nInternalSize == sizeof(ISC_QUAD));
	if(nInternalSize != sizeof(ISC_QUAD))
		return;
	CnvtInternalToDateTime(date_time, *(const ISC_QUAD*)pInternal);
}

/*static */
void IibConnection::CnvtInternalToDateTime(
	SADateTime &date_time,
	const ISC_QUAD &Internal)
{
	struct tm &_tm = (struct tm&)date_time;

	g_ibAPI.isc_decode_date((ISC_QUAD*)&Internal, (void*)&_tm);

	// no milli, micro or nano seconds in Interbase now
	date_time.Fraction() = 0;
}

/*static */
void IibConnection::CnvtDateTimeToInternal(
	const SADateTime &hire_time,
	ISC_QUAD &time)
{
	g_ibAPI.isc_encode_date((void*)&hire_time, &time);
	// no milli, micro or nano seconds now
}

/*virtual */
void IibConnection::CnvtInternalToCursor(
	SACommand * /*pCursor*/,
	const void * /*pInternal*/)
{
	assert(false);
}

/*virtual */
long IibConnection::GetClientVersion() const
{
	return g_nIB5DLLVersionLoaded;
}

/*static */
void IibConnection::ExtractServerVersionCallback(
	long *pnVersion, char *sStr)
{
	char *p = strstr(sStr, "(access method)");
	if(p)
		*pnVersion = SAExtractVersionFromString(p);
}

/*static */
void IibConnection::ExtractServerVersionStringCallback(
	SAString *psVersion, char *sStr)
{
	char *p = strstr(sStr, "(access method)");
	if(p)
		*psVersion = sStr;
}

/*virtual */
long IibConnection::GetServerVersion() const
{
    long nVersion = 0;

    g_ibAPI.isc_version(
		(isc_db_handle*)&m_handles.m_db_handle,
		(isc_callback)ExtractServerVersionCallback,
		&nVersion);

	return nVersion;
}

/*virtual */
SAString IibConnection::GetServerVersionString() const
{
	SAString sVersion;

    g_ibAPI.isc_version(
		(isc_db_handle*)&m_handles.m_db_handle,
		(isc_callback)ExtractServerVersionStringCallback,
		&sVersion);

	return sVersion;
}

/*static */
void IibConnection::Check(
	const ISC_STATUS &error_code,
	ISC_STATUS *pSV)
{
	SAString sErr;

	if(error_code)
	{
		char sMsg[512];
		long nLen;
		ISC_STATUS *pvector; /* Pointer to pointer to status vector. */

		// walk through error vector and constract error string
		pvector = pSV; /* (Re)set to start of status vector. */
		while((nLen = g_ibAPI.isc_interprete(sMsg, &pvector)) != 0) /* More messages? */
		{
			if(!sErr.IsEmpty())
				sErr += "\n";
			sErr += SAString(sMsg, nLen);
		}

		throw SAException(
			SA_DBMS_API_Error,
			error_code, -1,
			sErr);
	}
}

/*virtual */
bool IibConnection::IsConnected() const
{
	return m_handles.m_db_handle != NULL;
}

/*virtual */
void IibConnection::Connect(
	const SAString &sDBString,
	const SAString &sUserID,
	const SAString &sPassword)
{
	assert(m_handles.m_db_handle == NULL);
	assert(m_handles.m_tr_handle == NULL);
	assert(m_DPB_buffer == NULL);
	assert(m_DPB_buffer_length == 0);

	// Construct the database parameter buffer.
	m_DPB_buffer = (char*)::malloc(1024);
	char *dpb = m_DPB_buffer;
	const char *p;
	*dpb++ = isc_dpb_version1;
	*dpb++ = isc_dpb_user_name;
	*dpb++ = (char)sUserID.GetLength();
	for(p = sUserID; *p;)
		*dpb++ = *p++;
	*dpb++ = isc_dpb_password;
	*dpb++ = (char)sPassword.GetLength();
	for(p = sPassword; *p;)
		*dpb++ = *p++;
	// additional entries to DPB that can be specified
	typedef
	struct
	{
		const char *sKey;
		char cValue;
	} DPB_Stuff_t;
	// string values
	DPB_Stuff_t DPB_Strings[] =
	{
		{"isc_dpb_lc_ctype", isc_dpb_lc_ctype},
		{"isc_dpb_sql_role_name", isc_dpb_sql_role_name}
	};
	unsigned int i;
	for(i = 0; i < sizeof(DPB_Strings)/sizeof(DPB_Stuff_t); ++i)
	{
		SAString sOption = m_pSAConnection->Option(DPB_Strings[i].sKey);
		if(sOption.IsEmpty())
			continue;

		*dpb++ = DPB_Strings[i].cValue;
		*dpb++ = (char)sOption.GetLength();
		for(p = sOption; *p;)
			*dpb++ = *p++;
	}
	// 1-byte values
	DPB_Stuff_t DPB_Byte_1[] =
	{
		{"isc_dpb_num_buffers", isc_dpb_num_buffers}
	};
	for(i = 0; i < sizeof(DPB_Byte_1)/sizeof(DPB_Stuff_t); ++i)
	{
		SAString sOption = m_pSAConnection->Option(DPB_Byte_1[i].sKey);
		if(sOption.IsEmpty())
			continue;

		*dpb++ = DPB_Byte_1[i].cValue;
		*dpb++ = (char)1;
		*dpb++ = (char)atoi(sOption);
	}

	m_DPB_buffer_length = (short)(dpb - m_DPB_buffer);

	try
	{
		// attach
		Check(g_ibAPI.isc_attach_database(
			m_StatusVector, 0, (char*)(const char*)sDBString, &m_handles.m_db_handle,
			m_DPB_buffer_length, m_DPB_buffer), m_StatusVector);

		// do not call Construct TPB
		// start transaction with default isolation level and autocommit option
		StartTransaction();
	}
	catch(...)
	{
		// clean up
		if(m_handles.m_db_handle)
		{
			g_ibAPI.isc_detach_database(
				m_StatusVector, &m_handles.m_db_handle);
			assert(m_handles.m_db_handle == NULL);
			m_handles.m_db_handle = NULL;
		}
		if(m_DPB_buffer)
		{
			free(m_DPB_buffer);
			m_DPB_buffer = NULL;
		}
		m_DPB_buffer_length = 0;

		throw;
	}
}

/*virtual */
void IibConnection::Disconnect()
{
	assert(m_handles.m_db_handle);
	assert(m_handles.m_tr_handle);

	// first we should close transaction
	CommitTransaction();	// commit and close the transaction
	assert(m_handles.m_tr_handle == NULL);

	// then we can detach
	Check(g_ibAPI.isc_detach_database(
		m_StatusVector, &m_handles.m_db_handle), m_StatusVector);
	assert(m_handles.m_db_handle == NULL);


	assert(m_DPB_buffer);
	assert(m_DPB_buffer_length);
	if(m_DPB_buffer)
		::free(m_DPB_buffer);
	m_DPB_buffer = NULL;
	m_DPB_buffer_length = 0;
}

/*virtual */
void IibConnection::Commit()
{
	// always keep transaction open
	assert(m_handles.m_tr_handle != NULL);

	// use isc_commit_retaining() only if user explicitly asks for it
	SAString sCommitRetaining = m_pSAConnection->Option(_SA("CommitRetaining"));
	if(sCommitRetaining.CompareNoCase(_SA("true")) == 0)
		CommitRetaining();		// commit but leave the transaction open
	else
	{
		CommitTransaction();	// commit and close the transaction
		StartTransaction();		// reopen
	}

	// always keep transaction open
	assert(m_handles.m_tr_handle != NULL);
}

/*virtual */
void IibConnection::Rollback()
{
	// always keep transaction open
	assert(m_handles.m_tr_handle != NULL);

	RollbackTransaction();	// rollback and close the transaction
	StartTransaction();		// reopen

	// always keep transaction open
	assert(m_handles.m_tr_handle != NULL);
}

void IibConnection::StartTransaction()
{
	assert(m_handles.m_tr_handle == NULL);

	Check(g_ibAPI.isc_start_transaction(
		m_StatusVector,
		&m_handles.m_tr_handle,
		1, &m_handles.m_db_handle,
		m_TPB_buffer_length, m_TPB_buffer), m_StatusVector);

	assert(m_handles.m_tr_handle != NULL);
}

//////////////////////////////////////////////////////////////////////
// IibClient Class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IibClient::IibClient()
{

}

IibClient::~IibClient()
{

}

ISAConnection *IibClient::QueryConnectionInterface(
	SAConnection *pSAConnection)
{
	return new IibConnection(pSAConnection);
}

//////////////////////////////////////////////////////////////////////
// IibCursor Class
//////////////////////////////////////////////////////////////////////

class IibCursor : public ISACursor
{
	ibCommandHandles	m_handles;

	ISC_STATUS		m_StatusVector[20];		// Error status vector
	XSQLDA			*m_pInXSQLDA;
	XSQLDA			*m_pOutXSQLDA;

	bool m_bResultSet;
	ISC_LONG readStmtType();
	void closeResultSet();


	XSQLDA *AllocXSQLDA(short nVars);
	void DestroyXSQLDA(XSQLDA *&pXSQLDA);

	void BindBlob(ISC_QUAD &BlobID, SAParam &Param);

	virtual SADataType_t CnvtNativeToStd(
		int nNativeType,
		int nNativeSubType,
		int nSize,
		int nPrec,
		int nScale) const;

	unsigned short SQLDialect() const;

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

	virtual void ReadLongOrLOB(
		ValueType_t eValueType,
		SAValueRead &vr,
		void *pValue,
		unsigned int nFieldBufSize,
		saLongOrLobReader_t fnReader,
		unsigned int nReaderWantedPieceSize,
		void *pAddlData);

public:
	IibCursor(
		IibConnection *pIibConnection,
		SACommand *pCommand);
	virtual ~IibCursor();

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

	virtual void DescribeParamSP();

	virtual saCommandHandles *NativeHandles();

	void OnTransactionClosed(void * /*pAddlData*/);
};


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IibCursor::IibCursor(
	IibConnection *pIibConnection,
	SACommand *pCommand) :
	ISACursor(pIibConnection, pCommand)
{
	m_pInXSQLDA = NULL;
	m_pOutXSQLDA = NULL;

	m_bResultSet = false;
}

/*virtual */
IibCursor::~IibCursor()
{
	DestroyXSQLDA(m_pInXSQLDA);
	DestroyXSQLDA(m_pOutXSQLDA);
}

/*virtual */
void IibCursor::ReadLongOrLOB(
	ValueType_t /*eValueType*/,
	SAValueRead &vr,
	void *pValue,
	unsigned int nBufSize,
	saLongOrLobReader_t fnReader,
	unsigned int nReaderWantedPieceSize,
	void *pAddlData)
{
	assert(nBufSize == sizeof(ISC_QUAD));
	if(nBufSize != sizeof(ISC_QUAD))
		return;
	ISC_QUAD *pBlobID = (ISC_QUAD*)pValue;

	isc_blob_handle blob_handle = NULL;   // set handle to NULL before using it
	IibConnection::Check(g_ibAPI.isc_open_blob(
        m_StatusVector,
		&((IibConnection*)m_pISAConnection)->m_handles.m_db_handle,
		&((IibConnection*)m_pISAConnection)->m_handles.m_tr_handle,
        &blob_handle,   // set by this function to refer to the blob
        pBlobID), m_StatusVector);      // Blob ID put into out_sqlda by isc_fetch()

	try
	{
		// get blob size
		char blob_items[] = {isc_info_blob_total_length};
		char blob_info[100];
		IibConnection::Check(g_ibAPI.isc_blob_info(
			m_StatusVector,
			&blob_handle,
			sizeof(blob_items), blob_items,
			sizeof(blob_info), blob_info), m_StatusVector);
		int i = 0;
		unsigned long nBlobSize = 0;	// unknown
		while(blob_info[i] != isc_info_end)
		{
			char item = blob_info[i];
			++i;
			ISC_LONG item_length = g_ibAPI.isc_vax_integer(&blob_info[i], 2); i += 2;
			if(item == isc_info_blob_total_length)
			{
				nBlobSize = g_ibAPI.isc_vax_integer(&blob_info[i], (short)item_length);
				break;
			}
			i += item_length;
		}

		// InterBase can return pieces of smaller size than asked
		// (even if it is not end-of-file),
		// so we might need buffering
		SABufferConverter BufferConverter;
		ISADataConverter *pIConverter = &BufferConverter;
		unsigned int nCnvtBlobSizeMax = nBlobSize;

		// Read and process nReaderWantedPieceSize bytes at a time.
		unsigned char* pBuf;
		unsigned int nPieceSize = vr.PrepareReader(
			nCnvtBlobSizeMax,
			IibConnection::MaxBlobPiece,
			pBuf,
			fnReader,
			nReaderWantedPieceSize,
			pAddlData);
		assert(nPieceSize <= IibConnection::MaxBlobPiece);
		unsigned int nCnvtPieceSize = nPieceSize;

		// read all the BLOB data by calling isc_get_segment() repeatedly
		// to get each BLOB segment and its length
		SAPieceType_t ePieceType = SA_FirstPiece;
		unsigned long nTotalRead = 0;
		unsigned long nTotalPassedToReader = 0;
		do
		{
			if(nBlobSize)	// known
				nPieceSize = sa_min(nPieceSize, nBlobSize - nTotalRead);

			unsigned short actual_seg_length;
			ISC_STATUS status = g_ibAPI.isc_get_segment(
				m_StatusVector,
				&blob_handle,
				&actual_seg_length,	// length of segment read
				(unsigned short)nPieceSize,			// length of segment buffer
				(char*)pBuf);				// segment buffer

			if(status != 0 && m_StatusVector[1] != isc_segment && m_StatusVector[1] != isc_segstr_eof)
				IibConnection::Check(status, m_StatusVector);

			assert(!(m_StatusVector[1] == isc_segstr_eof) || (actual_seg_length == 0));
			nTotalRead += actual_seg_length;

			if(nBlobSize)	// known
			{
				assert(nTotalRead <= nBlobSize);
				if(nTotalRead == nBlobSize)
				{
					if(ePieceType == SA_NextPiece)
						ePieceType = SA_LastPiece;
					else    // the whole BLob has been read in one piece
					{
						assert(ePieceType == SA_FirstPiece);
						ePieceType = SA_OnePiece;
					}
				}
			}
			else
			{
				if(m_StatusVector[1] == isc_segstr_eof)
				{
					if(ePieceType == SA_NextPiece)
						ePieceType = SA_LastPiece;
					else    // the whole Long has been read in one piece
					{
						assert(ePieceType == SA_FirstPiece);
						ePieceType = SA_OnePiece;
					}
				}
			}

			pIConverter->PutStream(pBuf, actual_seg_length, ePieceType);
			unsigned int nCnvtSize;
			SAPieceType_t eCnvtPieceType;
			// smart while: initialize nCnvtPieceSize before calling pIConverter->GetStream
			while(nCnvtPieceSize = (nCnvtBlobSizeMax? // known
				sa_min(nCnvtPieceSize, nCnvtBlobSizeMax - nTotalPassedToReader) : nCnvtPieceSize),
				pIConverter->GetStream(pBuf, nCnvtPieceSize, nCnvtSize, eCnvtPieceType))
			{
				vr.InvokeReader(eCnvtPieceType, pBuf, nCnvtSize);
				nTotalPassedToReader += nCnvtSize;
			}

			if(ePieceType == SA_FirstPiece)
				ePieceType = SA_NextPiece;
		}
		while(ePieceType != SA_OnePiece && ePieceType != SA_LastPiece);
		assert(pIConverter->IsEmpty());
	}
	catch(SAException &)	// try to clean-up
	{
		g_ibAPI.isc_close_blob(m_StatusVector, &blob_handle);
		throw;
	}

	// close the Blob
	IibConnection::Check(g_ibAPI.isc_close_blob(
		m_StatusVector, &blob_handle), m_StatusVector);
}

/*virtual */
unsigned int IibCursor::InputBufferSize(
	const SAParam &Param) const
{
	if(!Param.isNull())
	{
		switch(Param.DataType())
		{
		case SA_dtBool:
			// there is no "native" boolean type in InterBase,
			// so treat boolean as SQL_SHORT in InterBase
			return sizeof(short);
		case SA_dtDateTime:
			return sizeof(ISC_TIMESTAMP);
		case SA_dtLongBinary:
		case SA_dtLongChar:
		case SA_dtBLob:
		case SA_dtCLob:
			return sizeof(ISC_QUAD);
		default:
			break;
		}
	}
	
	return ISACursor::InputBufferSize(Param);
}

XSQLDA *IibCursor::AllocXSQLDA(short nVars)
{
	int nSize = XSQLDA_LENGTH(nVars);
	XSQLDA *pXSQLDA = (XSQLDA *)malloc(nSize);
	memset(pXSQLDA, 0, nSize);
	pXSQLDA->version = SQLDA_VERSION1;
	pXSQLDA->sqln = nVars;
	pXSQLDA->sqld = nVars;

	return pXSQLDA;
}

void IibCursor::DestroyXSQLDA(XSQLDA *&pXSQLDA)
{
	if(pXSQLDA == NULL)
		return;

	free(pXSQLDA);
	pXSQLDA = NULL;
}

/*virtual */
bool IibCursor::IsOpened()
{
	return m_handles.m_stmt_handle != NULL;
}

/*virtual */
void IibCursor::Open()
{
	assert(m_handles.m_stmt_handle == NULL);

	IibConnection::Check(g_ibAPI.isc_dsql_allocate_statement(
		m_StatusVector,
		&((IibConnection*)m_pISAConnection)->m_handles.m_db_handle,
		&m_handles.m_stmt_handle), m_StatusVector);
	assert(m_handles.m_stmt_handle != NULL);
}

/*virtual */
void IibCursor::Close()
{
	assert(m_handles.m_stmt_handle != NULL);
	IibConnection::Check(g_ibAPI.isc_dsql_free_statement(
		m_StatusVector,
		&m_handles.m_stmt_handle,
		DSQL_drop), m_StatusVector);
	assert(m_handles.m_stmt_handle == NULL);
}

/*virtual */
ISACursor *IibConnection::NewCursor(SACommand *m_pCommand)
{
	return new IibCursor(this, m_pCommand);
}

/*virtual */
void IibCursor::Prepare(
	const SAString &sCmd,
	SACommandType_t eCmdType,
	int nPlaceHolderCount,
	saPlaceHolder **ppPlaceHolders)
{
	// replace bind variables with '?' place holder
	SAString sStmtIB;
	int nPos = 0;
	int i;

	// these counts can be overiden in case of a stored proc
	short nInputParamCount = 0;
	short nOutputParamCount = 0;

	switch(eCmdType)
	{
	case SA_CmdSQLStmt:
		for(i = 0; i < nPlaceHolderCount; ++i)
		{
			sStmtIB += sCmd.Mid(nPos, ppPlaceHolders[i]->getStart()-nPos);
			sStmtIB += "?";
			nPos = ppPlaceHolders[i]->getEnd() + 1;
		}
		// copy tail
		if(nPos < sCmd.GetLength())
			sStmtIB += sCmd.Mid(nPos);
		break;
	case SA_CmdStoredProc:
		sStmtIB = "Execute Procedure ";
		sStmtIB += sCmd;
		for(i = 0; i < m_pCommand->ParamCount(); ++i)
		{
			SAParam &Param = m_pCommand->ParamByIndex(i);
			if(Param.ParamDirType() == SA_ParamInput
				|| Param.ParamDirType() == SA_ParamInputOutput)
			{
				if(++nInputParamCount > 1)
					sStmtIB += " ,?";
				else
					sStmtIB += " ?";
			}

			if(Param.ParamDirType() == SA_ParamOutput
				|| Param.ParamDirType() == SA_ParamInputOutput)
				++nOutputParamCount;
		}

		break;
	default:
		assert(false);
	}

	DestroyXSQLDA(m_pOutXSQLDA);
	if(nOutputParamCount)
		m_pOutXSQLDA = AllocXSQLDA(nOutputParamCount);

	IibConnection::Check(g_ibAPI.isc_dsql_prepare(
		m_StatusVector,
		&((IibConnection*)m_pISAConnection)->m_handles.m_tr_handle,
		&m_handles.m_stmt_handle,
		0,
		(char*)(const char*)sStmtIB,
		SQLDialect(), m_pOutXSQLDA), m_StatusVector);
}

/*virtual */
void IibCursor::UnExecute()
{
	if(m_bResultSet)
		closeResultSet();
}

void IibCursor::BindBlob(ISC_QUAD &BlobID, SAParam &Param)
{
	BlobID.gds_quad_high = 0;
	BlobID.gds_quad_low = 0;

	isc_blob_handle blob_handle = NULL;	// set handle to NULL before using it
	IibConnection::Check(g_ibAPI.isc_create_blob(
		m_StatusVector,
		&((IibConnection*)m_pISAConnection)->m_handles.m_db_handle,
		&((IibConnection*)m_pISAConnection)->m_handles.m_tr_handle,
		&blob_handle, &BlobID), m_StatusVector);

	unsigned int nActualWrite;
	SAPieceType_t ePieceType = SA_FirstPiece;
	void *pBuf;
	while((nActualWrite = Param.InvokeWriter(
		ePieceType,
		IibConnection::MaxBlobPiece, pBuf)) != 0)
	{
		IibConnection::Check(g_ibAPI.isc_put_segment(
			m_StatusVector, &blob_handle,
			(unsigned short)nActualWrite, (char*)pBuf), m_StatusVector);

		if(ePieceType == SA_LastPiece)
			break;
	}

	// Close the Blob
	IibConnection::Check(g_ibAPI.isc_close_blob(
		m_StatusVector,
		&blob_handle), m_StatusVector);
	assert(blob_handle == NULL);
}

void IibCursor::Bind(
		int nPlaceHolderCount,
		saPlaceHolder**	ppPlaceHolders)
{
	// we should bind for every place holder ('?') associated with input or input/output param
	short nInputCount = ParamDirCount(
		nPlaceHolderCount, ppPlaceHolders, 1, SA_ParamInput);
	short nOutputCount = ParamDirCount(
		nPlaceHolderCount, ppPlaceHolders, 1, SA_ParamOutput);
	assert(nInputCount + nOutputCount == nPlaceHolderCount);
	if(nInputCount + nOutputCount != nPlaceHolderCount)
		return;

	AllocBindBuffer(nPlaceHolderCount, ppPlaceHolders, sizeof(short), sizeof(short));
	void *pBuf = m_pParamBuffer;

	DestroyXSQLDA(m_pInXSQLDA);
	m_pInXSQLDA = AllocXSQLDA(nInputCount);
	assert(!nOutputCount || (nOutputCount == m_pOutXSQLDA->sqld));
	assert(!nOutputCount || (nOutputCount == m_pOutXSQLDA->sqln));

	int nInput = 0;
	int nOutput = 0;
	for(int i = 0; i < nPlaceHolderCount; ++i)
	{
		SAParam &Param = *ppPlaceHolders[i]->getParam();
		
		void *pNull;
		void *pSize;
		unsigned int nDataBufSize;
		void *pValue;
		IncParamBuffer(pBuf, pNull, pSize, nDataBufSize, pValue);
		
		if(Param.ParamDirType() == SA_ParamInput)
		{
			short &sqltype = m_pInXSQLDA->sqlvar[nInput].sqltype;
			short &sqlsubtype = m_pInXSQLDA->sqlvar[nInput].sqlsubtype;
			short *&sqlind = m_pInXSQLDA->sqlvar[nInput].sqlind;
			short &sqllen = m_pInXSQLDA->sqlvar[nInput].sqllen;
			char *&sqldata = m_pInXSQLDA->sqlvar[nInput].sqldata;
			
			assert(sqlind == NULL);
			assert(sqldata == NULL);
			sqldata = (char*)pValue;
			sqllen = (short)nDataBufSize;
			
			if(Param.isNull())
			{
				sqlind = (short*)pNull;
				sqltype = SQL_TEXT+1;	// some type should be set
				assert(sqllen == 0);
				*sqlind = -1;
			}
			else
			{
				switch(Param.DataType())
				{
				case SA_dtUnknown:
					throw SAException(SA_Library_Error, -1, -1, IDS_UNKNOWN_PARAMETER_TYPE, (const char*)Param.Name());
				case SA_dtBool:
					// there is no "native" boolean type in InterBase,
					// so treat boolean as SQL_SHORT in InterBase
					sqltype = SQL_SHORT;
					assert(sqllen == sizeof(short));
					*(short*)sqldata = (short)Param.asBool();
					break;
				case SA_dtShort:
					sqltype = SQL_SHORT;
					assert(sqllen == sizeof(short));
					*(short*)sqldata = Param.asShort();
					break;
				case SA_dtLong:
					sqltype = SQL_LONG;
					assert(sqllen == sizeof(long));
					*(long*)sqldata = Param.asLong();
					break;
				case SA_dtDouble:
					sqltype = SQL_DOUBLE;
					assert(sqllen == sizeof(double));
					*(double*)sqldata = Param.asDouble();
					break;
				case SA_dtDateTime:
					sqltype = SQL_DATE;
					assert(sqllen == sizeof(ISC_QUAD));
					IibConnection::CnvtDateTimeToInternal(
						Param.asDateTime(), *(ISC_QUAD*)sqldata);
					break;
				case SA_dtString:
					sqltype = SQL_TEXT;
					assert(sqllen == Param.asString().GetLength());
					memcpy(sqldata, (const char*)Param.asString(), sqllen);
					break;
				case SA_dtBytes:
					sqltype = SQL_TEXT;
					assert(sqllen == Param.asBytes().GetLength());
					memcpy(sqldata, (const char*)Param.asBytes(), sqllen);
					break;
				case SA_dtLongBinary:
				case SA_dtBLob:
					sqltype = SQL_BLOB;
					sqlsubtype = 0;	// binary
					assert(sqllen == sizeof(ISC_QUAD));
					BindBlob(*(ISC_QUAD*)sqldata, Param);
					break;
				case SA_dtLongChar:
				case SA_dtCLob:
					sqltype = SQL_BLOB;
					sqlsubtype = 1;	// text
					assert(sqllen == sizeof(ISC_QUAD));
					BindBlob(*(ISC_QUAD*)sqldata, Param);
					break;
				default:
					assert(false);
				}
			}
			
			++nInput;
		}
		else
		{
			assert(Param.ParamDirType() == SA_ParamOutput);
			
			short &sqltype = m_pOutXSQLDA->sqlvar[nOutput].sqltype;
			short *&sqlind = m_pOutXSQLDA->sqlvar[nOutput].sqlind;
			short &sqllen = m_pOutXSQLDA->sqlvar[nOutput].sqllen;
			char *&sqldata = m_pOutXSQLDA->sqlvar[nOutput].sqldata;
			
			assert(sqlind == NULL);
			assert(sqldata == NULL);
			
			assert((sqltype & 1) != 0);
			sqlind = (short*)pNull;
			if((sqltype & ~1) == SQL_VARYING)
				sqldata = (char*)pSize;
			else
				sqldata = (char*)pValue;
			
			if((sqltype & ~1) == SQL_FLOAT)
			{
				assert(sqllen == sizeof(float));
				// coerce to double
				sqltype &= (~SQL_FLOAT);
				sqltype |= SQL_DOUBLE;
				sqllen = sizeof(double);
			}
			assert(sqllen == Param.ParamSize());
			
			++nOutput;
		}
	}
}

/*virtual */
void IibCursor::Execute(
	int nPlaceHolderCount,
	saPlaceHolder **ppPlaceHolders)
{
	if(nPlaceHolderCount)
		Bind(nPlaceHolderCount, ppPlaceHolders);

	XSQLDA *pOutXSQLDA =
		m_pCommand->CommandType() == SA_CmdStoredProc? m_pOutXSQLDA : NULL;

	IibConnection::Check(g_ibAPI.isc_dsql_execute2(
		m_StatusVector,
		&((IibConnection*)m_pISAConnection)->m_handles.m_tr_handle,
		&m_handles.m_stmt_handle,
		1,
		m_pInXSQLDA,
		pOutXSQLDA), m_StatusVector);

	m_bResultSet = ResultSetExists();
	if(readStmtType() == isc_info_sql_stmt_exec_procedure && m_pOutXSQLDA)
		ConvertOutputParams();
}

/*virtual */
void IibCursor::Cancel()
{
}

ISC_LONG IibCursor::readStmtType()
{
	char type_item[1];
	char res_buffer[8];
	ISC_LONG nLength;

	type_item[0] = isc_info_sql_stmt_type;
	IibConnection::Check(g_ibAPI.isc_dsql_sql_info(
		m_StatusVector,
		&m_handles.m_stmt_handle,
		sizeof(type_item)/sizeof(char), type_item,
		sizeof(res_buffer)/sizeof(char), res_buffer), m_StatusVector);
	if(res_buffer[0] == isc_info_sql_stmt_type)
	{
		nLength = g_ibAPI.isc_vax_integer(&res_buffer[1], 2);
		return g_ibAPI.isc_vax_integer(&res_buffer[3], (short)nLength);
	}

	return 0;
}

void IibCursor::closeResultSet()
{
	assert(m_bResultSet);
	IibConnection::Check(g_ibAPI.isc_dsql_free_statement(
		m_StatusVector,
		&m_handles.m_stmt_handle,
		DSQL_close), m_StatusVector);
	m_bResultSet = false;

	DestroyXSQLDA(m_pOutXSQLDA);
}

/*virtual */
bool IibCursor::ResultSetExists()
{
	switch(readStmtType())
	{
	case isc_info_sql_stmt_select:
	case isc_info_sql_stmt_select_for_upd:
		return true;
	case isc_info_sql_stmt_insert:
		return false;
	case isc_info_sql_stmt_update:
		return false;
	case isc_info_sql_stmt_delete:
		return false;
	case isc_info_sql_stmt_ddl:
		return false;
	case isc_info_sql_stmt_get_segment:
	case isc_info_sql_stmt_put_segment:
	case isc_info_sql_stmt_exec_procedure:
	case isc_info_sql_stmt_start_trans:
	case isc_info_sql_stmt_commit:
	case isc_info_sql_stmt_rollback:
	case isc_info_sql_stmt_set_generator:
		return false;
	}

	return false;
}

/*virtual */
SADataType_t IibCursor::CnvtNativeToStd(
	int nNativeType,
	int nNativeSubType,
	int/* nSize*/,
	int/* nPrec*/,
	int/* nScale*/) const
{
	switch(nNativeType & ~1)
	{
	case SQL_ARRAY:
		return SA_dtBLob;
	case SQL_BLOB:
		if(nNativeSubType == 1)
			return SA_dtCLob;
		else
			return SA_dtBLob;
	case SQL_TEXT:
		return SA_dtString;
	case SQL_SHORT:
		return SA_dtShort;
	case SQL_LONG:
		return SA_dtLong;
	case SQL_FLOAT:
		return SA_dtDouble;
	case SQL_DOUBLE:
		return SA_dtDouble;
	case SQL_VARYING:
		return SA_dtString;

	case SQL_TYPE_DATE:
		return SA_dtDateTime;
	case SQL_TYPE_TIME:
		return SA_dtDateTime;
	case SQL_TIMESTAMP:
		return SA_dtDateTime;

	default:
		assert(false);	// unknown type
	}

	return SA_dtUnknown;
}

/*virtual */
void IibCursor::DescribeFields(
	DescribeFields_cb_t fn)
{
	short cFields = 1;
	DestroyXSQLDA(m_pOutXSQLDA);
	m_pOutXSQLDA = AllocXSQLDA(cFields);
	IibConnection::Check(g_ibAPI.isc_dsql_describe(
		m_StatusVector,
		&m_handles.m_stmt_handle, 1, m_pOutXSQLDA), m_StatusVector);

	if(m_pOutXSQLDA->sqld > m_pOutXSQLDA->sqln)
	{
		cFields = m_pOutXSQLDA->sqld;
		DestroyXSQLDA(m_pOutXSQLDA);
		m_pOutXSQLDA = AllocXSQLDA(cFields);
		
		IibConnection::Check(g_ibAPI.isc_dsql_describe(
			m_StatusVector,
			&m_handles.m_stmt_handle, 1, m_pOutXSQLDA), m_StatusVector);
		assert(m_pOutXSQLDA->sqld == cFields);
	}

	for(int iField = 0; iField < cFields; ++iField)
	{
		XSQLVAR &var = m_pOutXSQLDA->sqlvar[iField];

		int nFieldPrecision;

		switch(var.sqltype & ~1)
		{
		case SQL_ARRAY:
			nFieldPrecision = 0;
			break;
		case SQL_BLOB:
			nFieldPrecision = 0;
			break;
		case SQL_TEXT:
			nFieldPrecision = var.sqllen;
			break;
		case SQL_SHORT:
			if(var.sqlscale != 0)	// coerce to double
			{
				var.sqltype &= (~SQL_SHORT);
				var.sqltype |= SQL_DOUBLE;
				var.sqllen = sizeof(double);

				nFieldPrecision = 15;
			}
			else
				nFieldPrecision = 5;
			break;
		case SQL_LONG:
			if(var.sqlscale != 0)	// coerce to double
			{
				var.sqltype &= (~SQL_LONG);
				var.sqltype |= SQL_DOUBLE;
				var.sqllen = sizeof(double);

				nFieldPrecision = 15;
			}
			else
				nFieldPrecision = 10;
			break;
		case SQL_INT64:
			// coerce to double
			var.sqltype &= (~SQL_INT64);
			var.sqltype |= SQL_DOUBLE;
			var.sqllen = sizeof(double);

			nFieldPrecision = 15;
			break;
		case SQL_FLOAT:
			// coerce to double
			var.sqltype &= (~SQL_FLOAT);
			var.sqltype |= SQL_DOUBLE;
			var.sqllen = sizeof(double);

			nFieldPrecision = 15;
			break;
		case SQL_DOUBLE:
			nFieldPrecision = 15;
			break;
		case SQL_VARYING:
			nFieldPrecision = var.sqllen;
			break;
		case SQL_TYPE_DATE:
			// coerce to TIMESTAMP
			var.sqltype &= (~SQL_TYPE_DATE);
			var.sqltype |= SQL_TIMESTAMP;
			var.sqllen = sizeof(ISC_TIMESTAMP);

			nFieldPrecision = var.sqllen;
			break;
		case SQL_TYPE_TIME:
			// coerce to TIMESTAMP
			var.sqltype &= (~SQL_TYPE_DATE);
			var.sqltype |= SQL_TIMESTAMP;
			var.sqllen = sizeof(ISC_TIMESTAMP);

			nFieldPrecision = var.sqllen;
			break;
		case SQL_TIMESTAMP:
			nFieldPrecision = var.sqllen;
			break;

		case SQL_D_FLOAT:
		case SQL_QUAD:
		default:
			nFieldPrecision = 0;
			assert(false);	// unknown type
		}

		(m_pCommand->*fn)(
			SAString(var.aliasname, var.aliasname_length),
			CnvtNativeToStd(var.sqltype, var.sqlsubtype, var.sqllen, nFieldPrecision, var.sqlscale),
			(int)var.sqltype,
			var.sqllen,
			var.sqlscale,
			nFieldPrecision,
			!(var.sqltype & 1));
	}
}

/*
bool IibCursor::DescribeField(
	unsigned int nField,	// 1-based
	SAString &sName,
	SADataType_t &eFieldType,
	int &nNativeType,
	int &nFieldSize,
	int &nFieldPrecision,
	int &nFieldScale,
	bool &bFieldRequired)
{
	assert(nField == 1 || m_pOutXSQLDA != NULL);
	if(nField == 1)
	{
		short nFields = 1;
		DestroyXSQLDA(m_pOutXSQLDA);
		m_pOutXSQLDA = AllocXSQLDA(nFields);
		IibConnection::Check(g_ibAPI.isc_dsql_describe(
			m_StatusVector,
			&m_handles.m_stmt_handle, 1, m_pOutXSQLDA), m_StatusVector);

		if(m_pOutXSQLDA->sqld > m_pOutXSQLDA->sqln)
		{
			nFields = m_pOutXSQLDA->sqld;
			DestroyXSQLDA(m_pOutXSQLDA);
			m_pOutXSQLDA = AllocXSQLDA(nFields);
			
			IibConnection::Check(g_ibAPI.isc_dsql_describe(
				m_StatusVector,
				&m_handles.m_stmt_handle, 1, m_pOutXSQLDA), m_StatusVector);
			assert(m_pOutXSQLDA->sqld == nFields);
		}
	}

	if((unsigned int)m_pOutXSQLDA->sqld < nField)
		return false;

	XSQLVAR &var = m_pOutXSQLDA->sqlvar[nField-1];
	sName = SAString(var.aliasname, var.aliasname_length);
	switch(var.sqltype & ~1)
	{
	case SQL_ARRAY:
		nFieldPrecision = 0;
		break;
	case SQL_BLOB:
		nFieldPrecision = 0;
		break;
	case SQL_TEXT:
		nFieldPrecision = var.sqllen;
		break;
	case SQL_SHORT:
		if(var.sqlscale != 0)	// coerce to double
		{
			var.sqltype &= (~SQL_SHORT);
			var.sqltype |= SQL_DOUBLE;
			var.sqllen = sizeof(double);

			nFieldPrecision = 15;
		}
		else
			nFieldPrecision = 5;
		break;
	case SQL_LONG:
		if(var.sqlscale != 0)	// coerce to double
		{
			var.sqltype &= (~SQL_LONG);
			var.sqltype |= SQL_DOUBLE;
			var.sqllen = sizeof(double);

			nFieldPrecision = 15;
		}
		else
			nFieldPrecision = 10;
		break;
	case SQL_INT64:
		// coerce to double
		var.sqltype &= (~SQL_INT64);
		var.sqltype |= SQL_DOUBLE;
		var.sqllen = sizeof(double);

		nFieldPrecision = 15;
		break;
	case SQL_FLOAT:
		// coerce to double
		var.sqltype &= (~SQL_FLOAT);
		var.sqltype |= SQL_DOUBLE;
		var.sqllen = sizeof(double);

		nFieldPrecision = 15;
		break;
	case SQL_DOUBLE:
		nFieldPrecision = 15;
		break;
	case SQL_VARYING:
		nFieldPrecision = var.sqllen;
		break;
	case SQL_TYPE_DATE:
		// coerce to TIMESTAMP
		var.sqltype &= (~SQL_TYPE_DATE);
		var.sqltype |= SQL_TIMESTAMP;
		var.sqllen = sizeof(ISC_TIMESTAMP);

		nFieldPrecision = var.sqllen;
		break;
	case SQL_TYPE_TIME:
		// coerce to TIMESTAMP
		var.sqltype &= (~SQL_TYPE_DATE);
		var.sqltype |= SQL_TIMESTAMP;
		var.sqllen = sizeof(ISC_TIMESTAMP);

		nFieldPrecision = var.sqllen;
		break;
	case SQL_TIMESTAMP:
		nFieldPrecision = var.sqllen;
		break;

	case SQL_D_FLOAT:
	case SQL_QUAD:
	default:
		assert(false);	// unknown type
	}

	eFieldType = CnvtNativeToStd(
		var.sqltype, var.sqlsubtype, var.sqllen, nFieldPrecision, var.sqlscale);
	nNativeType = (int)var.sqltype;
	nFieldSize = var.sqllen;
	nFieldScale = var.sqlscale;
	bFieldRequired = !(var.sqltype & 1);

	return true;
}
*/
/*virtual */
long IibCursor::GetRowsAffected()
{
	char type_item[1];
	char res_buffer[1048];

	type_item[0] = isc_info_sql_records;
	IibConnection::Check(g_ibAPI.isc_dsql_sql_info(
		m_StatusVector,
		&m_handles.m_stmt_handle,
		sizeof(type_item)/sizeof(char), type_item,
		sizeof(res_buffer)/sizeof(char), res_buffer), m_StatusVector);
	if(res_buffer[0] == isc_info_sql_records)
	{
		switch(readStmtType())
		{
		case isc_info_sql_stmt_update:
			return g_ibAPI.isc_vax_integer(&res_buffer[6], 2);
		case isc_info_sql_stmt_delete:
			return g_ibAPI.isc_vax_integer(&res_buffer[13], 2);
		case isc_info_sql_stmt_insert:
			return g_ibAPI.isc_vax_integer(&res_buffer[27], 2);
		}
	}

	return -1;
}

/*virtual */
unsigned int IibCursor::OutputBufferSize(
	SADataType_t eDataType,
	unsigned int nDataSize) const
{
	switch(eDataType)
	{
		case SA_dtDateTime:
			return sizeof(ISC_TIMESTAMP);
		case SA_dtBLob:
		case SA_dtCLob:
			return sizeof(ISC_QUAD);
		default:
			break;
	}

	return ISACursor::OutputBufferSize(eDataType, nDataSize);
}


/*virtual */
void IibCursor::SetFieldBuffer(
	int nCol,	// 1-based
	void *pInd,
	unsigned int nIndSize,
	void * /*pSize*/,
	unsigned int nSizeSize,
	void *pValue,
	unsigned int nValueSize)
{
	assert(m_pOutXSQLDA != NULL);	// SetSelectBuffers should always be called after DescribeFields
	assert(nIndSize == sizeof(short));
	if(nIndSize != sizeof(short))
		return;
	assert(nSizeSize == sizeof(short));
	if(nSizeSize != sizeof(short))
		return;

	short &sqltype = m_pOutXSQLDA->sqlvar[nCol-1].sqltype;
	short *&sqlind = m_pOutXSQLDA->sqlvar[nCol-1].sqlind;
	short &sqllen = m_pOutXSQLDA->sqlvar[nCol-1].sqllen;
	char *&sqldata = m_pOutXSQLDA->sqlvar[nCol-1].sqldata;

	assert((unsigned int)sqllen == nValueSize);
	if((unsigned int)sqllen != nValueSize)
		return;

	assert(sqlind == NULL);
	assert(sqldata == NULL);

	if(!m_pCommand->Field(nCol).isFieldRequired())
	{
		assert((sqltype & 1) != 0);
		sqlind = (short*)pInd;
	}
	else
		assert((sqltype & 1) == 0);

	if((sqltype & ~1) == SQL_VARYING)
	{
		// short is reserverd for size returning 
		// just before the actual string
		sqldata = (char*)pValue - sizeof(short);
	}
	else
		sqldata = (char*)pValue;
}

/*virtual */
bool IibCursor::IndicatorIsNull(
	int nPos,	// 1-based
	SAValueRead &/*vr*/,
	ValueType_t/* eValueType*/,
	void * /*pInd*/,
	unsigned int nIndSize,
	void * /*pSize*/,
	unsigned int nSizeSize,
	unsigned int &nRealSize,
	int/* nBulkReadingBufPos*/) const
{
	assert(m_pOutXSQLDA != NULL);	// should always be called after DescribeFields
	assert(nIndSize == sizeof(short));
	if(nIndSize != sizeof(short))
		return true;
	assert(nSizeSize == sizeof(short));
	if(nSizeSize != sizeof(short))
		return true;

	XSQLVAR &var = m_pOutXSQLDA->sqlvar[nPos-1];
	// no indicator, field can not be NULL, or it is not null
	if(var.sqlind == NULL || *var.sqlind != -1)	
	{
		if((var.sqltype & ~1) == SQL_VARYING)
		{
			// short is reserverd for size returning 
			// just before the actual string
			nRealSize = *(short*)var.sqldata;
		}
		else
			nRealSize = var.sqllen;

		return false;
	}

	return true;
}

/*virtual */
void IibCursor::SetSelectBuffers()
{
	// use default helpers
	AllocSelectBuffer(sizeof(short), sizeof(short));
}

/*virtual */
bool IibCursor::FetchNext()
{
	ISC_STATUS Status;
	Status = g_ibAPI.isc_dsql_fetch(
		m_StatusVector,
		&m_handles.m_stmt_handle,
		1, m_pOutXSQLDA);
	if(Status != 100)
	{
		IibConnection::Check(Status, m_StatusVector);

		// use default helpers
		ConvertSelectBufferToFields(0);
	}

	return Status != 100;
}

/*static */
SAString IibConnection::FormatIdentifierValue(
	unsigned short nSQLDialect,
	const SAString &sValue)
{
	if(nSQLDialect == 1)
	{
		SAString sTemp = sValue;
		sTemp.TrimLeft();
		sTemp.TrimRight();

		return sTemp;
	}

	return sValue;
}

/*virtual */
void IibCursor::DescribeParamSP()
{
	SAString sProcName = m_pCommand->CommandText();
	SAString sStmtIB = "Execute Procedure ";
	sStmtIB += sProcName;
	
	// read sp parameters from system tables
	SAString sSQL =
		"SELECT RDB$PARAMETER_NAME,  RDB$PARAMETER_TYPE "
		"FROM RDB$PROCEDURE_PARAMETERS "
		"WHERE UPPER(RDB$PROCEDURE_NAME) = UPPER('";
	sSQL += IibConnection::FormatIdentifierValue(SQLDialect(), sProcName);
	sSQL += "') ORDER BY RDB$PARAMETER_NUMBER";
	
	SACommand cmd(m_pISAConnection->getSAConnection(), sSQL);
	cmd.Execute();
	int nTotal = 0;
	int nInput = 0;
	while(cmd.FetchNext())
	{
		SAString sName = cmd["RDB$PARAMETER_NAME"].asString();
		sName.TrimRight(" ");
		SAParamDirType_t eDirType = cmd["RDB$PARAMETER_TYPE"].asShort() == 0? SA_ParamInput : SA_ParamOutput;
		if(eDirType == SA_ParamInput)	// input
		{
			if(++nInput > 1)
				sStmtIB += " ,?";
			else
				sStmtIB += " ?";
		}
		else
		{
		}
		
		++nTotal;
		m_pCommand->CreateParam(sName, SA_dtUnknown, -1, 0, -1, -1, eDirType);
	}
	
	// query and set output parameters datatypes, native datatypes and sizes
	if(nTotal)
	{
		int nOutput = 0;
		cmd.setCommandText(sStmtIB);
		cmd.Prepare();
		for(int i = 0; i < nTotal; ++i)
		{
			SAParam &Param = m_pCommand->ParamByIndex(i);
			if(Param.ParamDirType() != SA_ParamOutput)
				continue;
			
			++nOutput;
			Param.setParamType(cmd.Field(nOutput).FieldType());
			Param.setParamNativeType(cmd.Field(nOutput).FieldNativeType());
			Param.setParamSize(cmd.Field(nOutput).FieldSize());
		}
		cmd.Close();
	}
}

/*virtual */
saAPI *IibConnection::NativeAPI() const
{
	return &g_ibAPI;
}

/*virtual */
saConnectionHandles *IibConnection::NativeHandles()
{
	return &m_handles;
}

/*virtual */
saCommandHandles *IibCursor::NativeHandles()
{
	return &m_handles;
}

void IibConnection::ConstructTPB(
	SAIsolationLevel_t eIsolationLevel,
	SAAutoCommit_t eAutoCommit)
{
	// Construct the transaction parameter buffer
	char *tpb = m_TPB_buffer;
	*tpb++ = isc_tpb_version3;
	*tpb++ = isc_tpb_write;
	switch(eIsolationLevel)
	{
	case SA_LevelUnknown:
		// use default values
		break;
	case SA_ReadUncommitted:
		*tpb++ = isc_tpb_read_committed;
		*tpb++ = isc_tpb_rec_version;
		break;
	case SA_ReadCommitted:
		*tpb++ = isc_tpb_read_committed;
		*tpb++ = isc_tpb_no_rec_version;
		break;
	case SA_RepeatableRead:
		*tpb++ = isc_tpb_consistency;
		break;
	case SA_Serializable:
		*tpb++ = isc_tpb_concurrency;
		break;
	default:
		assert(false);
	}
	*tpb++ = isc_tpb_wait;
	if(eAutoCommit == SA_AutoCommitOn)
		*tpb++ = isc_tpb_autocommit;

	m_TPB_buffer_length = (short)(tpb - m_TPB_buffer);
}

/*virtual */
void IibConnection::setIsolationLevel(
	SAIsolationLevel_t eIsolationLevel)
{
	// adjust isolation level and start new transaction
	ConstructTPB(
		eIsolationLevel,
		m_pSAConnection->AutoCommit());

	// for new settings to take affect we should start new transaction
	CommitTransaction();	// commit and close the transaction
	StartTransaction();		// reopen
}

/*virtual */
void IibConnection::setAutoCommit(
	SAAutoCommit_t eAutoCommit)
{
	ConstructTPB(
		m_pSAConnection->IsolationLevel(),
		eAutoCommit);

	// for new settings to take affect we should start new transaction
	CommitTransaction();	// commit and close the transaction
	StartTransaction();		// reopen
}

unsigned short IibCursor::SQLDialect() const
{
	SAString s = m_pCommand->Option("SQLDialect");
	if(s.IsEmpty())
		return 3;	// defaults to SQL dialect 3
	
	return (unsigned short)atoi((const char*)s);
}

static void TransactionClosed(ISACursor *pCursor, void *pAddlData)
{
	((IibCursor*)pCursor)->OnTransactionClosed(pAddlData);
}

void IibCursor::OnTransactionClosed(void * /*pAddlData*/)
{
	m_bResultSet = false;
}

void IibConnection::CommitTransaction()
{
	assert(m_handles.m_tr_handle != NULL);
	Check(g_ibAPI.isc_commit_transaction(
		m_StatusVector, &m_handles.m_tr_handle), m_StatusVector);
	assert(m_handles.m_tr_handle == NULL);

	EnumCursors(TransactionClosed, NULL);
}

void IibConnection::CommitRetaining()
{
	assert(m_handles.m_tr_handle != NULL);
	Check(g_ibAPI.isc_commit_retaining(
		m_StatusVector, &m_handles.m_tr_handle), m_StatusVector);
	assert(m_handles.m_tr_handle != NULL);
}

void IibConnection::RollbackTransaction()
{
	assert(m_handles.m_tr_handle != NULL);
	Check(g_ibAPI.isc_rollback_transaction(
		m_StatusVector, &m_handles.m_tr_handle), m_StatusVector);
	assert(m_handles.m_tr_handle == NULL);

	EnumCursors(TransactionClosed, NULL);
}

/*virtual */
void IibConnection::CnvtInternalToNumeric(
	SANumeric &/*numeric*/,
	const void * /*pInternal*/,
	int/* nInternalSize*/)
{
	assert(false);
}
