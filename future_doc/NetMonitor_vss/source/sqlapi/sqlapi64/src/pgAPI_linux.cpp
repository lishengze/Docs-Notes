// pgAPI.cpp
//
//////////////////////////////////////////////////////////////////////

#include <SQLAPI.h>
#include <pgAPI.h>

#include <assert.h>

#include "samisc.h"
#include "errmsg.h"

#include <dlfcn.h>

static const char *g_sPostgreSQLDLLName = "libpq.so";
static void *g_hPostgreSQLDLL = NULL;
static long g_nPostgreSQLDLLRefs = 0;
long g_nPostgreSQLDLLVersionLoaded = 0;

// API definitions
pgAPI g_pgAPI;

pgAPI::pgAPI()
{
	PQconnectStart = NULL;
	PQconnectPoll = NULL;
	PQconnectdb = NULL;
	PQsetdbLogin = NULL;
	PQfinish = NULL;
	PQconndefaults = NULL;
	PQconninfoFree = NULL;
	PQresetStart = NULL;
	PQresetPoll = NULL;
	PQreset = NULL;
	PQrequestCancel = NULL;
	PQdb = NULL;
	PQuser = NULL;
	PQpass = NULL;
	PQhost = NULL;
	PQport = NULL;
	PQtty = NULL;
	PQoptions = NULL;
	PQstatus = NULL;
	PQerrorMessage = NULL;
	PQsocket = NULL;
	PQbackendPID = NULL;
	PQclientEncoding = NULL;
	PQsetClientEncoding = NULL;
#ifdef USE_SSL
	PQgetssl = NULL;
#endif
	PQtrace = NULL;
	PQuntrace = NULL;
	PQsetNoticeProcessor = NULL;
	PQexec = NULL;
	PQnotifies = NULL;
	PQsendQuery = NULL;
	PQgetResult = NULL;
	PQisBusy = NULL;
	PQconsumeInput = NULL;
	PQgetline = NULL;
	PQputline = NULL;
	PQgetlineAsync = NULL;
	PQputnbytes = NULL;
	PQendcopy = NULL;
	PQsetnonblocking = NULL;
	PQisnonblocking = NULL;
	PQflush = NULL;
	PQfn = NULL;
	PQresultStatus = NULL;
	PQresStatus = NULL;
	PQresultErrorMessage = NULL;
	PQntuples = NULL;
	PQnfields = NULL;
	PQbinaryTuples = NULL;
	PQfname = NULL;
	PQfnumber = NULL;
	PQftype = NULL;
	PQfsize = NULL;
	PQfmod = NULL;
	PQcmdStatus = NULL;
	PQoidStatus = NULL;
	PQoidValue = NULL;
	PQcmdTuples = NULL;
	PQgetvalue = NULL;
	PQgetlength = NULL;
	PQgetisnull = NULL;
	PQclear = NULL;
	PQmakeEmptyPGresult = NULL;
	PQprint = NULL;
	PQdisplayTuples = NULL;
	PQprintTuples = NULL;
	lo_open = NULL;
	lo_close = NULL;
	lo_read = NULL;
	lo_write = NULL;
	lo_lseek = NULL;
	lo_creat = NULL;
	lo_tell = NULL;
	lo_unlink = NULL;
	lo_import = NULL;
	lo_export = NULL;
	PQmblen = NULL;
	PQenv2encoding = NULL;
}

pgConnectionHandles::pgConnectionHandles()
{
	conn = NULL;
}

pgCommandHandles::pgCommandHandles()
{
	res = NULL;
}

static void LoadAPI()
{
	g_pgAPI.PQconnectStart = (PQconnectStart_t)::dlsym(g_hPostgreSQLDLL, "PQconnectStart"); // assert(g_pgAPI.PQconnectStart != NULL);
	g_pgAPI.PQconnectPoll = (PQconnectPoll_t)::dlsym(g_hPostgreSQLDLL, "PQconnectPoll"); // assert(g_pgAPI.PQconnectPoll != NULL);
	g_pgAPI.PQconnectdb = (PQconnectdb_t)::dlsym(g_hPostgreSQLDLL, "PQconnectdb"); assert(g_pgAPI.PQconnectdb != NULL);
	g_pgAPI.PQsetdbLogin = (PQsetdbLogin_t)::dlsym(g_hPostgreSQLDLL, "PQsetdbLogin"); assert(g_pgAPI.PQsetdbLogin != NULL);
	g_pgAPI.PQfinish = (PQfinish_t)::dlsym(g_hPostgreSQLDLL, "PQfinish"); assert(g_pgAPI.PQfinish != NULL);
	g_pgAPI.PQconndefaults = (PQconndefaults_t)::dlsym(g_hPostgreSQLDLL, "PQconndefaults"); assert(g_pgAPI.PQconndefaults != NULL);
	g_pgAPI.PQconninfoFree = (PQconninfoFree_t)::dlsym(g_hPostgreSQLDLL, "PQconninfoFree"); assert(g_pgAPI.PQconninfoFree != NULL);
	g_pgAPI.PQresetStart = (PQresetStart_t)::dlsym(g_hPostgreSQLDLL, "PQresetStart"); // assert(g_pgAPI.PQresetStart != NULL);
	g_pgAPI.PQresetPoll = (PQresetPoll_t)::dlsym(g_hPostgreSQLDLL, "PQresetPoll"); // assert(g_pgAPI.PQresetPoll != NULL);
	g_pgAPI.PQreset = (PQreset_t)::dlsym(g_hPostgreSQLDLL, "PQreset"); assert(g_pgAPI.PQreset != NULL);
	g_pgAPI.PQrequestCancel = (PQrequestCancel_t)::dlsym(g_hPostgreSQLDLL, "PQrequestCancel"); assert(g_pgAPI.PQrequestCancel != NULL);
	g_pgAPI.PQdb = (PQdb_t)::dlsym(g_hPostgreSQLDLL, "PQdb"); assert(g_pgAPI.PQdb != NULL);
	g_pgAPI.PQuser = (PQuser_t)::dlsym(g_hPostgreSQLDLL, "PQuser"); assert(g_pgAPI.PQuser != NULL);
	g_pgAPI.PQpass = (PQpass_t)::dlsym(g_hPostgreSQLDLL, "PQpass"); assert(g_pgAPI.PQpass != NULL);
	g_pgAPI.PQhost = (PQhost_t)::dlsym(g_hPostgreSQLDLL, "PQhost"); assert(g_pgAPI.PQhost != NULL);
	g_pgAPI.PQport = (PQport_t)::dlsym(g_hPostgreSQLDLL, "PQport"); assert(g_pgAPI.PQport != NULL);
	g_pgAPI.PQtty = (PQtty_t)::dlsym(g_hPostgreSQLDLL, "PQtty"); assert(g_pgAPI.PQtty != NULL);
	g_pgAPI.PQoptions = (PQoptions_t)::dlsym(g_hPostgreSQLDLL, "PQoptions"); assert(g_pgAPI.PQoptions != NULL);
	g_pgAPI.PQstatus = (PQstatus_t)::dlsym(g_hPostgreSQLDLL, "PQstatus"); assert(g_pgAPI.PQstatus != NULL);
	g_pgAPI.PQerrorMessage = (PQerrorMessage_t)::dlsym(g_hPostgreSQLDLL, "PQerrorMessage"); assert(g_pgAPI.PQerrorMessage != NULL);
	g_pgAPI.PQsocket = (PQsocket_t)::dlsym(g_hPostgreSQLDLL, "PQsocket"); assert(g_pgAPI.PQsocket != NULL);
	g_pgAPI.PQbackendPID = (PQbackendPID_t)::dlsym(g_hPostgreSQLDLL, "PQbackendPID"); assert(g_pgAPI.PQbackendPID != NULL);
	g_pgAPI.PQclientEncoding = (PQclientEncoding_t)::dlsym(g_hPostgreSQLDLL, "PQclientEncoding"); assert(g_pgAPI.PQclientEncoding != NULL);
	g_pgAPI.PQsetClientEncoding = (PQsetClientEncoding_t)::dlsym(g_hPostgreSQLDLL, "PQsetClientEncoding"); // assert(g_pgAPI.PQsetClientEncoding != NULL);
#ifdef USE_SSL
	g_pgAPI.PQgetssl = (PQgetssl_t)::dlsym(g_hPostgreSQLDLL, "PQgetssl"); assert(g_pgAPI.PQgetssl != NULL);
#endif
	g_pgAPI.PQtrace = (PQtrace_t)::dlsym(g_hPostgreSQLDLL, "PQtrace"); assert(g_pgAPI.PQtrace != NULL);
	g_pgAPI.PQuntrace = (PQuntrace_t)::dlsym(g_hPostgreSQLDLL, "PQuntrace"); assert(g_pgAPI.PQuntrace != NULL);
	g_pgAPI.PQsetNoticeProcessor = (PQsetNoticeProcessor_t)::dlsym(g_hPostgreSQLDLL, "PQsetNoticeProcessor"); assert(g_pgAPI.PQsetNoticeProcessor != NULL);
	g_pgAPI.PQexec = (PQexec_t)::dlsym(g_hPostgreSQLDLL, "PQexec"); assert(g_pgAPI.PQexec != NULL);
	g_pgAPI.PQnotifies = (PQnotifies_t)::dlsym(g_hPostgreSQLDLL, "PQnotifies"); assert(g_pgAPI.PQnotifies != NULL);
	g_pgAPI.PQsendQuery = (PQsendQuery_t)::dlsym(g_hPostgreSQLDLL, "PQsendQuery"); assert(g_pgAPI.PQsendQuery != NULL);
	g_pgAPI.PQgetResult = (PQgetResult_t)::dlsym(g_hPostgreSQLDLL, "PQgetResult"); assert(g_pgAPI.PQgetResult != NULL);
	g_pgAPI.PQisBusy = (PQisBusy_t)::dlsym(g_hPostgreSQLDLL, "PQisBusy"); assert(g_pgAPI.PQisBusy != NULL);
	g_pgAPI.PQconsumeInput = (PQconsumeInput_t)::dlsym(g_hPostgreSQLDLL, "PQconsumeInput"); assert(g_pgAPI.PQconsumeInput != NULL);
	g_pgAPI.PQgetline = (PQgetline_t)::dlsym(g_hPostgreSQLDLL, "PQgetline"); assert(g_pgAPI.PQgetline != NULL);
	g_pgAPI.PQputline = (PQputline_t)::dlsym(g_hPostgreSQLDLL, "PQputline"); assert(g_pgAPI.PQputline != NULL);
	g_pgAPI.PQgetlineAsync = (PQgetlineAsync_t)::dlsym(g_hPostgreSQLDLL, "PQgetlineAsync"); assert(g_pgAPI.PQgetlineAsync != NULL);
	g_pgAPI.PQputnbytes = (PQputnbytes_t)::dlsym(g_hPostgreSQLDLL, "PQputnbytes"); assert(g_pgAPI.PQputnbytes != NULL);
	g_pgAPI.PQendcopy = (PQendcopy_t)::dlsym(g_hPostgreSQLDLL, "PQendcopy"); assert(g_pgAPI.PQendcopy != NULL);
	g_pgAPI.PQsetnonblocking = (PQsetnonblocking_t)::dlsym(g_hPostgreSQLDLL, "PQsetnonblocking"); // assert(g_pgAPI.PQsetnonblocking != NULL);
	g_pgAPI.PQisnonblocking = (PQisnonblocking_t)::dlsym(g_hPostgreSQLDLL, "PQisnonblocking"); // assert(g_pgAPI.PQisnonblocking != NULL);
	g_pgAPI.PQflush = (PQflush_t)::dlsym(g_hPostgreSQLDLL, "PQflush"); // assert(g_pgAPI.PQflush != NULL);
	g_pgAPI.PQfn = (PQfn_t)::dlsym(g_hPostgreSQLDLL, "PQfn"); assert(g_pgAPI.PQfn != NULL);
	g_pgAPI.PQresultStatus = (PQresultStatus_t)::dlsym(g_hPostgreSQLDLL, "PQresultStatus"); assert(g_pgAPI.PQresultStatus != NULL);
	g_pgAPI.PQresStatus = (PQresStatus_t)::dlsym(g_hPostgreSQLDLL, "PQresStatus"); assert(g_pgAPI.PQresStatus != NULL);
	g_pgAPI.PQresultErrorMessage = (PQresultErrorMessage_t)::dlsym(g_hPostgreSQLDLL, "PQresultErrorMessage"); assert(g_pgAPI.PQresultErrorMessage != NULL);
	g_pgAPI.PQntuples = (PQntuples_t)::dlsym(g_hPostgreSQLDLL, "PQntuples"); assert(g_pgAPI.PQntuples != NULL);
	g_pgAPI.PQnfields = (PQnfields_t)::dlsym(g_hPostgreSQLDLL, "PQnfields"); assert(g_pgAPI.PQnfields != NULL);
	g_pgAPI.PQbinaryTuples = (PQbinaryTuples_t)::dlsym(g_hPostgreSQLDLL, "PQbinaryTuples"); assert(g_pgAPI.PQbinaryTuples != NULL);
	g_pgAPI.PQfname = (PQfname_t)::dlsym(g_hPostgreSQLDLL, "PQfname"); assert(g_pgAPI.PQfname != NULL);
	g_pgAPI.PQfnumber = (PQfnumber_t)::dlsym(g_hPostgreSQLDLL, "PQfnumber"); assert(g_pgAPI.PQfnumber != NULL);
	g_pgAPI.PQftype = (PQftype_t)::dlsym(g_hPostgreSQLDLL, "PQftype"); assert(g_pgAPI.PQftype != NULL);
	g_pgAPI.PQfsize = (PQfsize_t)::dlsym(g_hPostgreSQLDLL, "PQfsize"); assert(g_pgAPI.PQfsize != NULL);
	g_pgAPI.PQfmod = (PQfmod_t)::dlsym(g_hPostgreSQLDLL, "PQfmod"); assert(g_pgAPI.PQfmod != NULL);
	g_pgAPI.PQcmdStatus = (PQcmdStatus_t)::dlsym(g_hPostgreSQLDLL, "PQcmdStatus"); assert(g_pgAPI.PQcmdStatus != NULL);
	g_pgAPI.PQoidStatus = (PQoidStatus_t)::dlsym(g_hPostgreSQLDLL, "PQoidStatus"); assert(g_pgAPI.PQoidStatus != NULL);
	g_pgAPI.PQoidValue = (PQoidValue_t)::dlsym(g_hPostgreSQLDLL, "PQoidValue"); assert(g_pgAPI.PQoidValue != NULL);
	g_pgAPI.PQcmdTuples = (PQcmdTuples_t)::dlsym(g_hPostgreSQLDLL, "PQcmdTuples"); assert(g_pgAPI.PQcmdTuples != NULL);
	g_pgAPI.PQgetvalue = (PQgetvalue_t)::dlsym(g_hPostgreSQLDLL, "PQgetvalue"); assert(g_pgAPI.PQgetvalue != NULL);
	g_pgAPI.PQgetlength = (PQgetlength_t)::dlsym(g_hPostgreSQLDLL, "PQgetlength"); assert(g_pgAPI.PQgetlength != NULL);
	g_pgAPI.PQgetisnull = (PQgetisnull_t)::dlsym(g_hPostgreSQLDLL, "PQgetisnull"); assert(g_pgAPI.PQgetisnull != NULL);
	g_pgAPI.PQclear = (PQclear_t)::dlsym(g_hPostgreSQLDLL, "PQclear"); assert(g_pgAPI.PQclear != NULL);
	g_pgAPI.PQmakeEmptyPGresult = (PQmakeEmptyPGresult_t)::dlsym(g_hPostgreSQLDLL, "PQmakeEmptyPGresult"); assert(g_pgAPI.PQmakeEmptyPGresult != NULL);
	g_pgAPI.PQprint = (PQprint_t)::dlsym(g_hPostgreSQLDLL, "PQprint"); assert(g_pgAPI.PQprint != NULL);
	g_pgAPI.PQdisplayTuples = (PQdisplayTuples_t)::dlsym(g_hPostgreSQLDLL, "PQdisplayTuples"); assert(g_pgAPI.PQdisplayTuples != NULL);
	g_pgAPI.PQprintTuples = (PQprintTuples_t)::dlsym(g_hPostgreSQLDLL, "PQprintTuples"); assert(g_pgAPI.PQprintTuples != NULL);
	g_pgAPI.lo_open = (lo_open_t)::dlsym(g_hPostgreSQLDLL, "lo_open"); assert(g_pgAPI.lo_open != NULL);
	g_pgAPI.lo_close = (lo_close_t)::dlsym(g_hPostgreSQLDLL, "lo_close"); assert(g_pgAPI.lo_close != NULL);
	g_pgAPI.lo_read = (lo_read_t)::dlsym(g_hPostgreSQLDLL, "lo_read"); assert(g_pgAPI.lo_read != NULL);
	g_pgAPI.lo_write = (lo_write_t)::dlsym(g_hPostgreSQLDLL, "lo_write"); assert(g_pgAPI.lo_write != NULL);
	g_pgAPI.lo_lseek = (lo_lseek_t)::dlsym(g_hPostgreSQLDLL, "lo_lseek"); assert(g_pgAPI.lo_lseek != NULL);
	g_pgAPI.lo_creat = (lo_creat_t)::dlsym(g_hPostgreSQLDLL, "lo_creat"); assert(g_pgAPI.lo_creat != NULL);
	g_pgAPI.lo_tell = (lo_tell_t)::dlsym(g_hPostgreSQLDLL, "lo_tell"); assert(g_pgAPI.lo_tell != NULL);
	g_pgAPI.lo_unlink = (lo_unlink_t)::dlsym(g_hPostgreSQLDLL, "lo_unlink"); assert(g_pgAPI.lo_unlink != NULL);
	g_pgAPI.lo_import = (lo_import_t)::dlsym(g_hPostgreSQLDLL, "lo_import"); assert(g_pgAPI.lo_import != NULL);
	g_pgAPI.lo_export = (lo_export_t)::dlsym(g_hPostgreSQLDLL, "lo_export"); assert(g_pgAPI.lo_export != NULL);
	g_pgAPI.PQmblen = (PQmblen_t)::dlsym(g_hPostgreSQLDLL, "PQmblen"); assert(g_pgAPI.PQmblen != NULL);
	g_pgAPI.PQenv2encoding = (PQenv2encoding_t)::dlsym(g_hPostgreSQLDLL, "PQenv2encoding"); assert(g_pgAPI.PQenv2encoding != NULL);
}

static void ResetAPI()
{
	g_pgAPI.PQconnectStart = NULL;
	g_pgAPI.PQconnectPoll = NULL;
	g_pgAPI.PQconnectdb = NULL;
	g_pgAPI.PQsetdbLogin = NULL;
	g_pgAPI.PQfinish = NULL;
	g_pgAPI.PQconndefaults = NULL;
	g_pgAPI.PQconninfoFree = NULL;
	g_pgAPI.PQresetStart = NULL;
	g_pgAPI.PQresetPoll = NULL;
	g_pgAPI.PQreset = NULL;
	g_pgAPI.PQrequestCancel = NULL;
	g_pgAPI.PQdb = NULL;
	g_pgAPI.PQuser = NULL;
	g_pgAPI.PQpass = NULL;
	g_pgAPI.PQhost = NULL;
	g_pgAPI.PQport = NULL;
	g_pgAPI.PQtty = NULL;
	g_pgAPI.PQoptions = NULL;
	g_pgAPI.PQstatus = NULL;
	g_pgAPI.PQerrorMessage = NULL;
	g_pgAPI.PQsocket = NULL;
	g_pgAPI.PQbackendPID = NULL;
	g_pgAPI.PQclientEncoding = NULL;
	g_pgAPI.PQsetClientEncoding = NULL;
#ifdef USE_SSL
	g_pgAPI.PQgetssl = NULL;
#endif
	g_pgAPI.PQtrace = NULL;
	g_pgAPI.PQuntrace = NULL;
	g_pgAPI.PQsetNoticeProcessor = NULL;
	g_pgAPI.PQexec = NULL;
	g_pgAPI.PQnotifies = NULL;
	g_pgAPI.PQsendQuery = NULL;
	g_pgAPI.PQgetResult = NULL;
	g_pgAPI.PQisBusy = NULL;
	g_pgAPI.PQconsumeInput = NULL;
	g_pgAPI.PQgetline = NULL;
	g_pgAPI.PQputline = NULL;
	g_pgAPI.PQgetlineAsync = NULL;
	g_pgAPI.PQputnbytes = NULL;
	g_pgAPI.PQendcopy = NULL;
	g_pgAPI.PQsetnonblocking = NULL;
	g_pgAPI.PQisnonblocking = NULL;
	g_pgAPI.PQflush = NULL;
	g_pgAPI.PQfn = NULL;
	g_pgAPI.PQresultStatus = NULL;
	g_pgAPI.PQresStatus = NULL;
	g_pgAPI.PQresultErrorMessage = NULL;
	g_pgAPI.PQntuples = NULL;
	g_pgAPI.PQnfields = NULL;
	g_pgAPI.PQbinaryTuples = NULL;
	g_pgAPI.PQfname = NULL;
	g_pgAPI.PQfnumber = NULL;
	g_pgAPI.PQftype = NULL;
	g_pgAPI.PQfsize = NULL;
	g_pgAPI.PQfmod = NULL;
	g_pgAPI.PQcmdStatus = NULL;
	g_pgAPI.PQoidStatus = NULL;
	g_pgAPI.PQoidValue = NULL;
	g_pgAPI.PQcmdTuples = NULL;
	g_pgAPI.PQgetvalue = NULL;
	g_pgAPI.PQgetlength = NULL;
	g_pgAPI.PQgetisnull = NULL;
	g_pgAPI.PQclear = NULL;
	g_pgAPI.PQmakeEmptyPGresult = NULL;
	g_pgAPI.PQprint = NULL;
	g_pgAPI.PQdisplayTuples = NULL;
	g_pgAPI.PQprintTuples = NULL;
	g_pgAPI.lo_open = NULL;
	g_pgAPI.lo_close = NULL;
	g_pgAPI.lo_read = NULL;
	g_pgAPI.lo_write = NULL;
	g_pgAPI.lo_lseek = NULL;
	g_pgAPI.lo_creat = NULL;
	g_pgAPI.lo_tell = NULL;
	g_pgAPI.lo_unlink = NULL;
	g_pgAPI.lo_import = NULL;
	g_pgAPI.lo_export = NULL;
	g_pgAPI.PQmblen = NULL;
	g_pgAPI.PQenv2encoding = NULL;
}

void AddPostgreSQLSupport(const SAConnection * /*pCon*/)
{
	if(!g_nPostgreSQLDLLRefs)
	{
		void *hDLL = ::dlopen(g_sPostgreSQLDLLName, RTLD_LAZY);

		try
		{
			if(!hDLL)
				throw SAException(SA_Library_Error, -1, -1, IDS_LOAD_LIBRARY_FAILS, ::dlerror(), g_sPostgreSQLDLLName);

			g_hPostgreSQLDLL = hDLL;
			LoadAPI();
		}
		catch(SAException &)
		{
			// clean up
			if(hDLL)
				::dlclose(hDLL);
			throw;
		}
	}

	g_nPostgreSQLDLLRefs++;
}

void ReleasePostgreSQLSupport()
{
	assert(g_nPostgreSQLDLLRefs > 0);
	g_nPostgreSQLDLLRefs--;
	if(!g_nPostgreSQLDLLRefs)
	{
		ResetAPI();

		::dlclose(g_hPostgreSQLDLL);
		g_hPostgreSQLDLL = NULL;
	}
}

