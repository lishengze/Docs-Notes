// myAPI_linux.cpp
//
//////////////////////////////////////////////////////////////////////

#include <SQLAPI.h>
#include <myAPI.h>

#include <assert.h>

#include "samisc.h"
#include "errmsg.h"

#include <dlfcn.h>

static const char *g_sMySQLDLLName = "libmysqlclient.so";
static void *g_hMySQLDLL = NULL;
static long g_nMySQLDLLRefs = 0;

// API definitions
myAPI g_myAPI;

myAPI::myAPI()
{
	mysql_num_rows = NULL;
	mysql_num_fields = NULL;
	mysql_eof = NULL;
	mysql_fetch_field_direct = NULL;
	mysql_fetch_fields = NULL;
	mysql_row_tell = NULL;
	mysql_field_tell = NULL;
	mysql_field_count = NULL;
	mysql_affected_rows = NULL;
	mysql_insert_id = NULL;
	mysql_errno = NULL;
	mysql_error = NULL;
	mysql_info = NULL;
	mysql_thread_id = NULL;
	mysql_character_set_name = NULL;
	mysql_init = NULL;
	mysql_ssl_set = NULL;
	mysql_ssl_cipher = NULL;
	mysql_ssl_clear = NULL;
	mysql_connect = NULL;
	mysql_change_user = NULL;
	mysql_real_connect1 = NULL;
	mysql_real_connect2 = NULL;
	mysql_close = NULL;
	mysql_select_db = NULL;
	mysql_query = NULL;
	mysql_send_query = NULL;
	mysql_read_query_result = NULL;
	mysql_real_query = NULL;
	mysql_create_db = NULL;
	mysql_drop_db = NULL;
	mysql_shutdown = NULL;
	mysql_dump_debug_info = NULL;
	mysql_refresh = NULL;
	mysql_kill = NULL;
	mysql_ping = NULL;
	mysql_stat = NULL;
	mysql_get_server_info = NULL;
	mysql_get_client_info = NULL;
	mysql_get_host_info = NULL;
	mysql_get_proto_info = NULL;
	mysql_list_dbs = NULL;
	mysql_list_tables = NULL;
	mysql_list_fields = NULL;
	mysql_list_processes = NULL;
	mysql_store_result = NULL;
	mysql_use_result = NULL;
	mysql_options = NULL;
	mysql_free_result = NULL;
	mysql_data_seek = NULL;
	mysql_row_seek = NULL;
	mysql_field_seek = NULL;
	mysql_fetch_row = NULL;
	mysql_fetch_lengths = NULL;
	mysql_fetch_field = NULL;
	mysql_escape_string = NULL;
	mysql_real_escape_string = NULL;
	mysql_debug = NULL;
	mysql_odbc_escape_string = NULL;
	myodbc_remove_escape = NULL;
	mysql_thread_safe = NULL;
}

myConnectionHandles::myConnectionHandles()
{
	mysql = NULL;
}

myCommandHandles::myCommandHandles()
{
	result = NULL;
}

static void LoadAPI()
{
	g_myAPI.mysql_num_rows = (mysql_num_rows_t)::dlsym(g_hMySQLDLL, "mysql_num_rows"); assert(g_myAPI.mysql_num_rows != NULL);
	g_myAPI.mysql_num_fields = (mysql_num_fields_t)::dlsym(g_hMySQLDLL, "mysql_num_fields"); assert(g_myAPI.mysql_num_fields != NULL);
	g_myAPI.mysql_eof = (mysql_eof_t)::dlsym(g_hMySQLDLL, "mysql_eof"); assert(g_myAPI.mysql_eof != NULL);
	g_myAPI.mysql_fetch_field_direct = (mysql_fetch_field_direct_t)::dlsym(g_hMySQLDLL, "mysql_fetch_field_direct"); assert(g_myAPI.mysql_fetch_field_direct != NULL);
	g_myAPI.mysql_fetch_fields = (mysql_fetch_fields_t)::dlsym(g_hMySQLDLL, "mysql_fetch_fields"); assert(g_myAPI.mysql_fetch_fields != NULL);
	g_myAPI.mysql_row_tell = (mysql_row_tell_t)::dlsym(g_hMySQLDLL, "mysql_row_tell"); assert(g_myAPI.mysql_row_tell != NULL);
	g_myAPI.mysql_field_tell = (mysql_field_tell_t)::dlsym(g_hMySQLDLL, "mysql_field_tell"); assert(g_myAPI.mysql_field_tell != NULL);
	g_myAPI.mysql_field_count = (mysql_field_count_t)::dlsym(g_hMySQLDLL, "mysql_field_count"); assert(g_myAPI.mysql_field_count != NULL);
	g_myAPI.mysql_affected_rows = (mysql_affected_rows_t)::dlsym(g_hMySQLDLL, "mysql_affected_rows"); assert(g_myAPI.mysql_affected_rows != NULL);
	g_myAPI.mysql_insert_id = (mysql_insert_id_t)::dlsym(g_hMySQLDLL, "mysql_insert_id"); assert(g_myAPI.mysql_insert_id != NULL);
	g_myAPI.mysql_errno = (mysql_errno_t)::dlsym(g_hMySQLDLL, "mysql_errno"); assert(g_myAPI.mysql_errno != NULL);
	g_myAPI.mysql_error = (mysql_error_t)::dlsym(g_hMySQLDLL, "mysql_error"); assert(g_myAPI.mysql_error != NULL);
	g_myAPI.mysql_info = (mysql_info_t)::dlsym(g_hMySQLDLL, "mysql_info"); assert(g_myAPI.mysql_info != NULL);
	g_myAPI.mysql_thread_id = (mysql_thread_id_t)::dlsym(g_hMySQLDLL, "mysql_thread_id"); assert(g_myAPI.mysql_thread_id != NULL);
	g_myAPI.mysql_character_set_name = (mysql_character_set_name_t)::dlsym(g_hMySQLDLL, "mysql_character_set_name"); //assert(g_myAPI.mysql_character_set_name != NULL);
	g_myAPI.mysql_init = (mysql_init_t)::dlsym(g_hMySQLDLL, "mysql_init"); assert(g_myAPI.mysql_init != NULL);
	g_myAPI.mysql_ssl_set = (mysql_ssl_set_t)::dlsym(g_hMySQLDLL, "mysql_ssl_set"); //assert(g_myAPI.mysql_ssl_set != NULL);
	g_myAPI.mysql_ssl_cipher = (mysql_ssl_cipher_t)::dlsym(g_hMySQLDLL, "mysql_ssl_cipher"); //assert(g_myAPI.mysql_ssl_cipher != NULL);
	g_myAPI.mysql_ssl_clear = (mysql_ssl_clear_t)::dlsym(g_hMySQLDLL, "mysql_ssl_clear"); //assert(g_myAPI.mysql_ssl_clear != NULL);
	g_myAPI.mysql_connect = (mysql_connect_t)::dlsym(g_hMySQLDLL, "mysql_connect"); //assert(g_myAPI.mysql_connect != NULL);
	g_myAPI.mysql_change_user = (mysql_change_user_t)::dlsym(g_hMySQLDLL, "mysql_change_user"); //assert(g_myAPI.mysql_change_user != NULL);

	g_myAPI.mysql_get_server_info = (mysql_get_server_info_t)::dlsym(g_hMySQLDLL, "mysql_get_server_info"); assert(g_myAPI.mysql_get_server_info != NULL);
	g_myAPI.mysql_get_client_info = (mysql_get_client_info_t)::dlsym(g_hMySQLDLL, "mysql_get_client_info"); assert(g_myAPI.mysql_get_client_info != NULL);
	g_myAPI.mysql_get_host_info = (mysql_get_host_info_t)::dlsym(g_hMySQLDLL, "mysql_get_host_info"); assert(g_myAPI.mysql_get_host_info != NULL);
	g_myAPI.mysql_get_proto_info = (mysql_get_proto_info_t)::dlsym(g_hMySQLDLL, "mysql_get_proto_info"); assert(g_myAPI.mysql_get_proto_info != NULL);

	long version = SAExtractVersionFromString(g_myAPI.mysql_get_client_info());
	
	if( version < 0x00030016 ) // < 3.22
	{
		g_myAPI.mysql_real_connect1 = (mysql_real_connect1_t)::dlsym(g_hMySQLDLL, "mysql_real_connect"); assert(g_myAPI.mysql_real_connect1 != NULL);
		g_myAPI.mysql_real_connect2 = NULL;
	}
	else
	{
		g_myAPI.mysql_real_connect1 = NULL;
		g_myAPI.mysql_real_connect2 = (mysql_real_connect2_t)::dlsym(g_hMySQLDLL, "mysql_real_connect"); assert(g_myAPI.mysql_real_connect2 != NULL);
	}
	
	g_myAPI.mysql_close = (mysql_close_t)::dlsym(g_hMySQLDLL, "mysql_close"); assert(g_myAPI.mysql_close != NULL);
	g_myAPI.mysql_select_db = (mysql_select_db_t)::dlsym(g_hMySQLDLL, "mysql_select_db"); assert(g_myAPI.mysql_select_db != NULL);
	g_myAPI.mysql_query = (mysql_query_t)::dlsym(g_hMySQLDLL, "mysql_query"); assert(g_myAPI.mysql_query != NULL);
	g_myAPI.mysql_send_query = (mysql_send_query_t)::dlsym(g_hMySQLDLL, "mysql_send_query"); //assert(g_myAPI.mysql_send_query != NULL);
	g_myAPI.mysql_read_query_result = (mysql_read_query_result_t)::dlsym(g_hMySQLDLL, "mysql_read_query_result"); //assert(g_myAPI.mysql_read_query_result != NULL);
	g_myAPI.mysql_real_query = (mysql_real_query_t)::dlsym(g_hMySQLDLL, "mysql_real_query"); assert(g_myAPI.mysql_real_query != NULL);
	g_myAPI.mysql_create_db = (mysql_create_db_t)::dlsym(g_hMySQLDLL, "mysql_create_db"); assert(g_myAPI.mysql_create_db != NULL);
	g_myAPI.mysql_drop_db = (mysql_drop_db_t)::dlsym(g_hMySQLDLL, "mysql_drop_db"); assert(g_myAPI.mysql_drop_db != NULL);
	g_myAPI.mysql_shutdown = (mysql_shutdown_t)::dlsym(g_hMySQLDLL, "mysql_shutdown"); assert(g_myAPI.mysql_shutdown != NULL);
	g_myAPI.mysql_dump_debug_info = (mysql_dump_debug_info_t)::dlsym(g_hMySQLDLL, "mysql_dump_debug_info"); assert(g_myAPI.mysql_dump_debug_info != NULL);
	g_myAPI.mysql_refresh = (mysql_refresh_t)::dlsym(g_hMySQLDLL, "mysql_refresh"); assert(g_myAPI.mysql_refresh != NULL);
	g_myAPI.mysql_kill = (mysql_kill_t)::dlsym(g_hMySQLDLL, "mysql_kill"); assert(g_myAPI.mysql_kill != NULL);
	g_myAPI.mysql_ping = (mysql_ping_t)::dlsym(g_hMySQLDLL, "mysql_ping"); assert(g_myAPI.mysql_ping != NULL);
	g_myAPI.mysql_stat = (mysql_stat_t)::dlsym(g_hMySQLDLL, "mysql_stat"); assert(g_myAPI.mysql_stat != NULL);

	g_myAPI.mysql_list_dbs = (mysql_list_dbs_t)::dlsym(g_hMySQLDLL, "mysql_list_dbs"); assert(g_myAPI.mysql_list_dbs != NULL);
	g_myAPI.mysql_list_tables = (mysql_list_tables_t)::dlsym(g_hMySQLDLL, "mysql_list_tables"); assert(g_myAPI.mysql_list_tables != NULL);
	g_myAPI.mysql_list_fields = (mysql_list_fields_t)::dlsym(g_hMySQLDLL, "mysql_list_fields"); assert(g_myAPI.mysql_list_fields != NULL);
	g_myAPI.mysql_list_processes = (mysql_list_processes_t)::dlsym(g_hMySQLDLL, "mysql_list_processes"); assert(g_myAPI.mysql_list_processes != NULL);
	g_myAPI.mysql_store_result = (mysql_store_result_t)::dlsym(g_hMySQLDLL, "mysql_store_result"); assert(g_myAPI.mysql_store_result != NULL);
	g_myAPI.mysql_use_result = (mysql_use_result_t)::dlsym(g_hMySQLDLL, "mysql_use_result"); assert(g_myAPI.mysql_use_result != NULL);
	g_myAPI.mysql_options = (mysql_options_t)::dlsym(g_hMySQLDLL, "mysql_options"); assert(g_myAPI.mysql_options != NULL);
	g_myAPI.mysql_free_result = (mysql_free_result_t)::dlsym(g_hMySQLDLL, "mysql_free_result"); assert(g_myAPI.mysql_free_result != NULL);
	g_myAPI.mysql_data_seek = (mysql_data_seek_t)::dlsym(g_hMySQLDLL, "mysql_data_seek"); assert(g_myAPI.mysql_data_seek != NULL);
	g_myAPI.mysql_row_seek = (mysql_row_seek_t)::dlsym(g_hMySQLDLL, "mysql_row_seek"); assert(g_myAPI.mysql_row_seek != NULL);
	g_myAPI.mysql_field_seek = (mysql_field_seek_t)::dlsym(g_hMySQLDLL, "mysql_field_seek"); assert(g_myAPI.mysql_field_seek != NULL);
	g_myAPI.mysql_fetch_row = (mysql_fetch_row_t)::dlsym(g_hMySQLDLL, "mysql_fetch_row"); assert(g_myAPI.mysql_fetch_row != NULL);
	g_myAPI.mysql_fetch_lengths = (mysql_fetch_lengths_t)::dlsym(g_hMySQLDLL, "mysql_fetch_lengths"); assert(g_myAPI.mysql_fetch_lengths != NULL);
	g_myAPI.mysql_fetch_field = (mysql_fetch_field_t)::dlsym(g_hMySQLDLL, "mysql_fetch_field"); assert(g_myAPI.mysql_fetch_field != NULL);
	g_myAPI.mysql_escape_string = (mysql_escape_string_t)::dlsym(g_hMySQLDLL, "mysql_escape_string"); assert(g_myAPI.mysql_escape_string != NULL);
	g_myAPI.mysql_real_escape_string = (mysql_real_escape_string_t)::dlsym(g_hMySQLDLL, "mysql_real_escape_string"); //assert(g_myAPI.mysql_real_escape_string != NULL);
	g_myAPI.mysql_debug = (mysql_debug_t)::dlsym(g_hMySQLDLL, "mysql_debug"); assert(g_myAPI.mysql_debug != NULL);
	g_myAPI.mysql_odbc_escape_string = (mysql_odbc_escape_string_t)::dlsym(g_hMySQLDLL, "mysql_odbc_escape_string"); assert(g_myAPI.mysql_odbc_escape_string != NULL);
	g_myAPI.myodbc_remove_escape = (myodbc_remove_escape_t)::dlsym(g_hMySQLDLL, "myodbc_remove_escape"); assert(g_myAPI.myodbc_remove_escape != NULL);
	g_myAPI.mysql_thread_safe = (mysql_thread_safe_t)::dlsym(g_hMySQLDLL, "mysql_thread_safe"); assert(g_myAPI.mysql_thread_safe != NULL);
}

static void ResetAPI()
{
	g_myAPI.mysql_num_rows = NULL;
	g_myAPI.mysql_num_fields = NULL;
	g_myAPI.mysql_eof = NULL;
	g_myAPI.mysql_fetch_field_direct = NULL;
	g_myAPI.mysql_fetch_fields = NULL;
	g_myAPI.mysql_row_tell = NULL;
	g_myAPI.mysql_field_tell = NULL;
	g_myAPI.mysql_field_count = NULL;
	g_myAPI.mysql_affected_rows = NULL;
	g_myAPI.mysql_insert_id = NULL;
	g_myAPI.mysql_errno = NULL;
	g_myAPI.mysql_error = NULL;
	g_myAPI.mysql_info = NULL;
	g_myAPI.mysql_thread_id = NULL;
	g_myAPI.mysql_character_set_name = NULL;
	g_myAPI.mysql_init = NULL;
	g_myAPI.mysql_ssl_set = NULL;
	g_myAPI.mysql_ssl_cipher = NULL;
	g_myAPI.mysql_ssl_clear = NULL;
	g_myAPI.mysql_connect = NULL;
	g_myAPI.mysql_change_user = NULL;
	g_myAPI.mysql_real_connect1 = NULL;
	g_myAPI.mysql_real_connect2 = NULL;
	g_myAPI.mysql_close = NULL;
	g_myAPI.mysql_select_db = NULL;
	g_myAPI.mysql_query = NULL;
	g_myAPI.mysql_send_query = NULL;
	g_myAPI.mysql_read_query_result = NULL;
	g_myAPI.mysql_real_query = NULL;
	g_myAPI.mysql_create_db = NULL;
	g_myAPI.mysql_drop_db = NULL;
	g_myAPI.mysql_shutdown = NULL;
	g_myAPI.mysql_dump_debug_info = NULL;
	g_myAPI.mysql_refresh = NULL;
	g_myAPI.mysql_kill = NULL;
	g_myAPI.mysql_ping = NULL;
	g_myAPI.mysql_stat = NULL;
	g_myAPI.mysql_get_server_info = NULL;
	g_myAPI.mysql_get_client_info = NULL;
	g_myAPI.mysql_get_host_info = NULL;
	g_myAPI.mysql_get_proto_info = NULL;
	g_myAPI.mysql_list_dbs = NULL;
	g_myAPI.mysql_list_tables = NULL;
	g_myAPI.mysql_list_fields = NULL;
	g_myAPI.mysql_list_processes = NULL;
	g_myAPI.mysql_store_result = NULL;
	g_myAPI.mysql_use_result = NULL;
	g_myAPI.mysql_options = NULL;
	g_myAPI.mysql_free_result = NULL;
	g_myAPI.mysql_data_seek = NULL;
	g_myAPI.mysql_row_seek = NULL;
	g_myAPI.mysql_field_seek = NULL;
	g_myAPI.mysql_fetch_row = NULL;
	g_myAPI.mysql_fetch_lengths = NULL;
	g_myAPI.mysql_fetch_field = NULL;
	g_myAPI.mysql_escape_string = NULL;
	g_myAPI.mysql_real_escape_string = NULL;
	g_myAPI.mysql_debug = NULL;
	g_myAPI.mysql_odbc_escape_string = NULL;
	g_myAPI.myodbc_remove_escape = NULL;
	g_myAPI.mysql_thread_safe = NULL;
}

void AddMySQLSupport()
{
	if(!g_nMySQLDLLRefs)
	{
		void *hDLL = ::dlopen(g_sMySQLDLLName, RTLD_LAZY);

		try
		{
			if(!hDLL)
				throw SAException(SA_Library_Error, -1, -1, IDS_LOAD_LIBRARY_FAILS, ::dlerror(), g_sMySQLDLLName);

			g_hMySQLDLL = hDLL;
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

	g_nMySQLDLLRefs++;
}

void ReleaseMySQLSupport()
{
	assert(g_nMySQLDLLRefs > 0);
	g_nMySQLDLLRefs--;
	if(!g_nMySQLDLLRefs)
	{
		ResetAPI();

		::dlclose(g_hMySQLDLL);
		g_hMySQLDLL = NULL;
	}
}

