/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	CSnmpWrapper.cpp
///@brief	实现了CSnmpWrapper类
///@history
///20110512	魏诚		创建该文件
#include "platform.h"
#include "Mutex.h"
#include "CSnmpWrapper.h"
#include <exception>

#define UNKNOWN_ATTR	0	///未知类型的数据类型
#define STRING_ATTR		1	///字符串数据类型
#define INT_ATTR		2	///整数数据类型
#define FLOAT_ATTR		3	///浮点数类型
CMutex	g_cbLock;

CSnmpWrapper::CSnmpWrapper(
	const std::string snmpcommunity,
	const std::string peername,
	const long	snmpversion)
{
	m_pSnmpSession = NULL;

	m_lSnmpVersion = snmpversion;
	m_sCommunity = snmpcommunity;
	m_sPeerName = peername;
	m_iReqnum = 0;
}

CSnmpWrapper::~CSnmpWrapper(void)
{
	if (m_pSnmpSession)
	{
		close_session();
		m_pSnmpSession = NULL;
	}
}

///初始化函数,返回true表示成功，false失败
bool CSnmpWrapper::open_session(long timeout)
{
	//已经打开了
	if (m_pSnmpSession)
	{
		return true;
	}

	SOCK_STARTUP;

	struct snmp_session sess;
	snmp_sess_init(&sess);	///初始化session /* initialize session */

	//设置session的各变量
	sess.version = m_lSnmpVersion;
	sess.peername = (char *)m_sPeerName.c_str();
	sess.community = (u_char *)m_sCommunity.c_str();
	sess.community_len = strlen((char *)sess.community);
	sess.callback = &snmp_async_processor;
	sess.callback_magic = this;
	sess.timeout = timeout;

	m_iTimeout = timeout;

	if (!m_pSnmpSession)
	{
		if (!(m_pSnmpSession = snmp_sess_open(&sess)))
		{
			snmp_perror("open_async_session");
			return false;
		}
	}

	init_snmp("snmpapp");

	return true;
}

///关闭函数
void CSnmpWrapper::close_session(void)
{
	//已经关闭了
	if (m_pSnmpSession)
	{
		snmp_sess_close(m_pSnmpSession);
		m_pSnmpSession = NULL;
	}

	clear_all_data();
	clear_timeout_event();
	clear_error_event();

	SOCK_CLEANUP;
}

///同步请求函数，返回0表示成功，其他失败
///@param	reqtype	请求类型，支持SNMP_MSG_GET、SNMP_MSG_GETNEXT和SNMP_MSG_SET
///@param	name	操作的oid名称
///@param	namelen	oid名称的长度
///@param	status	  执行结果
///@param	response  返回的pdu	
int CSnmpWrapper::send_sync_request(
	int reqtype,
	const oid *name,
	size_t	namelen,
	int &status,
	netsnmp_pdu * &response)
{
	if (!is_opened())
	{
		snmp_perror("Session not opend!");
		return SNMP_ERROR_SESSION_NOT_OPENED;
	}

	if (!name)
	{
		snmp_perror("OID Name NULL!");
		return SNMP_ERROR_OID_NAME_INVALID;
	}

	struct snmp_pdu *request;

	//创建pdu
	request = snmp_pdu_create(reqtype);
	snmp_add_null_var(request, name, namelen);

	//执行发送并接收
	status = snmp_sess_synch_response(m_pSnmpSession, request, &response);

	return SNMP_ERROR_SUCCESS;
}

///异步请求函数，返回0表示成功，其他失败
///@param	reqtype		请求类型，支持SNMP_MSG_GET、SNMP_MSG_GETNEXT和SNMP_MSG_SET
///@param	value		操作的oid值
///@param	valuelen	oid值的长度
///@param	reqid		请求的唯一标识id
int CSnmpWrapper::send_async_request(
	int reqtype,
	const oid *name,
	size_t	namelen,
	long &reqid,
	int max_repetitions,
	int non_repeaters)
{
	if (!is_opened())
	{
		snmp_perror("Session not opend!");
		return SNMP_ERROR_SESSION_NOT_OPENED;
	}

	if (!name)
	{
		snmp_perror("OID Name NULL!");
		return SNMP_ERROR_OID_NAME_INVALID;
	}

	struct snmp_pdu *req;

	//创建pdu
	req = snmp_pdu_create(reqtype);
	if( SNMP_MSG_GETBULK == reqtype )  //目前getbulk仅支持带1个oid值
	{
		if( m_lSnmpVersion != SNMP_VERSION_1 )
		{
			req->non_repeaters = non_repeaters;
			req->max_repetitions = max_repetitions;
			m_BulkNum.add( req->reqid, req->max_repetitions);
		}
		else
		{
			snmp_perror("snmp_version fail!");
			snmp_free_pdu(req);
			return SNMP_ERROR_LOW_VERSION;
		}
	}
	snmp_add_null_var(req, name, namelen);

	//用异步方式发送包，不处理，等后面专门处理
	if (snmp_sess_send(m_pSnmpSession, req))
	{
		//更新请求个数
		m_iReqnum++;

		//记录请求id
		reqid = req->reqid;

		return SNMP_ERROR_SUCCESS;
	}

	snmp_perror("snmp_send fail!");
	snmp_free_pdu(req);

	return SNMP_ERROR_SEND_FAIL;
}

///默认的异步回调处理函数
///@param operation,  操作类型
///@param sp          该响应对应的snmp_session
///@param reqid       pdu的请求id，0 代表 TRAP
///@param pdu         返回的pdu对象
///@param magic       请求的对象指针
int CSnmpWrapper::snmp_async_processor(
	int operation,
	struct snmp_session *sp,
	int reqid,
	struct snmp_pdu *pdu,
	void *magic)
{
	CSnmpWrapper *snmpwrapper = (CSnmpWrapper *)magic;
	if (!snmpwrapper)
	{
		//todu:plus log
		printf("snmpwrapper NULL\n");
		return -1;
	}

	oid next_name[MAX_OID_LEN];
	size_t	nextnamelen = 0;
	int status;

	if (operation == NETSNMP_CALLBACK_OP_RECEIVED_MESSAGE)
	{
		status = STAT_SUCCESS;
	}
	else
	{
		status = STAT_TIMEOUT;
	}

	ENDOIDITERATOR	e_i = snmpwrapper->m_mEndOidMap.find(pdu->reqid);
	if (e_i == snmpwrapper->m_mEndOidMap.end())
	{
#ifdef PACKAGE_OUTPUT
		printf("reqid:%d not found!\n", pdu->reqid);
#endif
		return -1;
	}

	//更新异步请求个数
	--snmpwrapper->m_iReqnum;

	COidInfo end_oid;
	end_oid = e_i->second;

	snmpwrapper->m_mEndOidMap.erase(e_i);

	std::map<COidInfo, bool>::iterator	o_i = snmpwrapper->m_AsyncWalkMark.find(
			end_oid);

	int nums = 0;
	DATAMAP result;

	if( snmpwrapper->m_BulkNum.get((long &)reqid , nums ) )
	{
		snmpwrapper->m_BulkNum.del( (long &)reqid );
	}

	int returncode = snmpwrapper->parse_get_next_result(
			status,
			pdu,
			end_oid,
			(oid *)next_name,
			nextnamelen,
			result,
			nums);

	if (SNMP_ERROR_SUCCESS == returncode)
	{
		//walk的返回结果
		if (o_i != snmpwrapper->m_AsyncWalkMark.end())
		{
			if (result.size() > 0)
			{
				ASYNCWALK_RESULT_ITERATOR a_i = snmpwrapper->m_AsyncWalkResult.
					find(end_oid);
				if (a_i == snmpwrapper->m_AsyncWalkResult.end())
				{
					snmpwrapper->m_AsyncWalkResult[end_oid] = result;
				}
				else
				{
					for (DATAMAPITERATOR d_i = result.begin();
						 d_i != result.end();
						 ++d_i)
					{
						snmpwrapper->m_AsyncWalkResult[end_oid][d_i->first] = d_i->second;
					}
				}
			}
		}
		else
		{
			//get的返回结果
			snmpwrapper->push_group_data(result);
		}
	}

	if (nextnamelen > 0)
	{
		snmpwrapper->send_async_get_next_request(
				next_name,
				nextnamelen,
				(long &)reqid);

		snmpwrapper->m_mEndOidMap[(long)reqid] = end_oid;
	}
	else
	{
		//walk结束
		std::map<COidInfo, bool>::iterator	a_i = snmpwrapper->m_AsyncWalkMark.
			find(end_oid);
		if (a_i != snmpwrapper->m_AsyncWalkMark.end())
		{
			//get类型参数调用walk方法，还原操作
			if (snmpwrapper->m_AsyncWalkResult.size() == 0)
			{
				char idffer[MAX_OID_LEN * 2] = { 0 };
				for (size_t i = 0; i < end_oid.oidlen; ++i)
				{
					snprintf(
						idffer + strlen(idffer),
						MAX_OID_LEN * 2 - strlen(idffer),
						"%d.",
						end_oid.oidvalue[i]);
				}

				idffer[strlen(idffer) - 1] = '\0';

				string res;
				int restype;
				if (SNMP_ERROR_SUCCESS == snmpwrapper->send_sync_get_request(
						end_oid.oidvalue,
					end_oid.oidlen,
					res,
					restype))
				{
					if (res.length() > 0)
					{
						DATAMAP datamap;
						SNMPRESULTDATA resultdata;

						resultdata.datatype = restype;
						resultdata.datavalue = res;

						datamap[idffer] = resultdata;

						snmpwrapper->m_AsyncWalkResult[end_oid] = datamap;
						snmpwrapper->m_AsyncWalkMark[end_oid] = true;
					}
					else
					{
						snmpwrapper->m_ErrorEvent[idffer] = "no result for this oid";
						snmpwrapper->m_AsyncWalkMark.erase(a_i);
					}
				}
				else
				{
					snmpwrapper->m_ErrorEvent[idffer] = "no result for this oid";
					snmpwrapper->m_AsyncWalkMark.erase(a_i);
				}
			}
			else
			{
				snmpwrapper->m_AsyncWalkMark[end_oid] = true;
			}
		}
	}

	return 0;
}

///发送同步get请求
///@param	name	操作的oid名称
///@param	namelen	oid名称的长度
///@param	result	get请求的返回结果
int CSnmpWrapper::send_sync_get_request(
	const char	*name,
	std::string &result,
	int &resulttype)
{
	std::string newname = name;

	oid oidvalue[MAX_OID_LEN] = { 0 };
	size_t oidlen;

	if (!parse_oid(newname.c_str(), oidvalue, oidlen))
	{
		return SNMP_ERROR_PARSE_OID_FAIL;
	}

	return send_sync_get_request(
			(const oid *)oidvalue,
			oidlen,
			result,
			resulttype);
}

///@param	oidvalue	操作的oid值
///@param	oidlen		oid值的长度
///@param	result		get请求的返回结果
int CSnmpWrapper::send_sync_get_request(
	const oid *name,
	size_t namelen,
	std::string &result,
	int &resulttype)
{
	int status;				//执行结果
	netsnmp_pdu *response;	//返回的pdu
	int ret = send_sync_request(SNMP_MSG_GET, name, namelen, status, response);
	if (SNMP_ERROR_SUCCESS != ret)
	{
		return ret;
	}

	//处理返回结果
	int returncode = parse_get_result(
			status,
			name,
			namelen,
			response,
			result,
			resulttype);
	if (response)
	{
		snmp_free_pdu(response);
	}

	return returncode;
}

///发送异步get请求
///@param	name		操作的oid名称
int CSnmpWrapper::send_async_get_request(const char *name)
{
	oid oidvalue[MAX_OID_LEN] = { 0 };
	size_t oidlen;

	std::string newname = name;
	if (!parse_oid(newname.c_str(), oidvalue, oidlen))
	{
		return SNMP_ERROR_PARSE_OID_FAIL;
	}

	return send_async_get_request(oidvalue, oidlen);
}

///发送异步get请求
///@param	name	操作的oid名称
///@param	namelen	oid名称的长度
int CSnmpWrapper::send_async_get_request(const oid *name, size_t namelen)
{
	COidInfo endoid;
	endoid.assign(name, namelen);

	long reqid;

	int ret = send_async_request(SNMP_MSG_GET, name, namelen, reqid);
	if (SNMP_ERROR_SUCCESS == ret)
	{
		m_mEndOidMap[reqid] = endoid;
	}

	return ret;
}

///发送同步get next请求
///@param	cur_name	当前操作的oid名称
///@param	endoid		结束遍历条件的OID信息
///@param	next_name	遍历的下一个oid值
///@param	nextnamelen	遍历的下一个oid值的长度
///@param	result		get next请求的返回结果
int CSnmpWrapper::send_sync_get_next_request(
	const char	*name,
	const COidInfo	&endoid,
	oid *next_name,
	size_t	&nextnamelen,
	DATAMAP &result)
{
	oid oidvalue[MAX_OID_LEN] = { 0 };
	size_t oidlen;

	std::string newname = name;
	if (!parse_oid(newname.c_str(), oidvalue, oidlen))
	{
		return SNMP_ERROR_PARSE_OID_FAIL;
	}

	return send_sync_get_next_request(
			oidvalue,
			oidlen,
			endoid,
			next_name,
			nextnamelen,
			result);
}

///@param	cur_oid		操作的oid值
///@param	curoidlen	oid值的长度
///@param	endoid		结束遍历条件的OID信息
///@param	next_name	遍历的下一个oid值
///@param	nextnamelen	遍历的下一个oid值的长度
///@param	result		get next请求的返回结果
int CSnmpWrapper::send_sync_get_next_request(
	const oid *cur_name,
	size_t curnamelen,
	const COidInfo &endoid,
	oid *next_name,
	size_t &nextnamelen,
	DATAMAP &result)
{
	int status;				//执行结果
	netsnmp_pdu *response;	//返回的pdu
	int ret = send_sync_request(
			SNMP_MSG_GETNEXT,
			cur_name,
			curnamelen,
			status,
			response);
	if (ret)
	{
		return ret;
	}

	int returncode = parse_get_next_result(
			status,
			response,
			endoid,
			next_name,
			nextnamelen,
			result);

	if (response)
	{
		snmp_free_pdu(response);
	}

	return returncode;
}

///发送异步get next请求
///@param	name		操作的oid名称
///@param	reqid		请求的唯一标识id
int CSnmpWrapper::send_async_get_next_request(const char *name, long &reqid)
{
	oid oidvalue[MAX_OID_LEN] = { 0 };
	size_t oidlen;

	std::string newname = name;
	if (!parse_oid(newname.c_str(), oidvalue, oidlen))
	{
		return SNMP_ERROR_PARSE_OID_FAIL;
	}

	return send_async_request(SNMP_MSG_GETNEXT, oidvalue, oidlen, reqid);
}

///@param	oidvalue	操作的oid值
///@param	oidlen		oid值长度
///@param	reqid		请求的唯一标识id
int CSnmpWrapper::send_async_get_next_request(
	const oid *name,
	size_t namelen,
	long &reqid)
{
	return send_async_request(SNMP_MSG_GETNEXT, name, namelen, reqid);
}

///发送异步get bulk请求，仅限1个oid
///@param	name		操作的oid名称
///@param	reqid		请求的唯一标识id
int CSnmpWrapper::send_async_get_one_bulk_request(const char *name, long &reqid)
{
	oid oidvalue[MAX_OID_LEN] = { 0 };
	size_t oidlen;

	std::string newname = name;
	if (!parse_oid(newname.c_str(), oidvalue, oidlen))
	{
		return SNMP_ERROR_PARSE_OID_FAIL;
	}

	return send_async_request(SNMP_MSG_GETBULK, oidvalue, oidlen, reqid);
}

///@param	oidvalue	操作的oid值
///@param	oidlen		oid值长度
///@param	reqid		请求的唯一标识id
int CSnmpWrapper::send_async_get_one_bulk_request(
	const oid *name,
	size_t namelen,
	long &reqid)
{
	return send_async_request(SNMP_MSG_GETBULK, name, namelen, reqid);
}


///发送同步walk请求
///@param	rootname	操作的oid名称
///@param	rootnamelen	oid名称的长度
///@param	walk_result	walk请求的返回结果
int CSnmpWrapper::send_sync_walk_request(
	const char	*rootname,
	CDPWALK_RESULT	&walk_result,
	int atparam)
{
	oid root[MAX_OID_LEN];
	size_t rootlen = MAX_OID_LEN;
	oid cur_name[MAX_OID_LEN];
	size_t curnamelen;
	oid next_name[MAX_OID_LEN];
	size_t nextnamelen;

	std::string newname = rootname;

	// get the initial object and subtree
	if (parse_oid(newname.c_str(), root, rootlen) == NULL)
	{
		snmp_perror(rootname);
		return SNMP_ERROR_PARSE_OID_FAIL;
	}

	COidInfo endoid;
	endoid.assign(root, rootlen);

	memcpy((char *)cur_name, (char *)root, rootlen * sizeof(oid));
	curnamelen = rootlen;

	//指定端口的walk
	if (atparam != 1)
	{
		std::string oricomm = m_sCommunity;

		char buffer[100] = { 0 };
		sprintf(buffer, "@%d", atparam);
		m_sCommunity += buffer;

		close_session();
		if (!open_session(m_iTimeout))
		{
			return SNMP_ERROR_OPEN_FAIL;
		}

		m_sCommunity = oricomm; //还原community
	}

	while (curnamelen > 0)
	{
		DATAMAP get_result;
		int ret = send_sync_get_next_request(
				cur_name,
				curnamelen,
				endoid,
				(oid *)next_name,
				nextnamelen,
				get_result);

		//记录中间结果,兼容标量和向量
		if (SNMP_ERROR_SUCCESS == ret && get_result.size() > 0)
		{
			DATAMAPITERATOR g_i = get_result.begin();
			for (; g_i != get_result.end(); ++g_i)
			{
				walk_result[g_i->first] = g_i->second.datavalue;
			}
		}
		else
		{
			string res;
			int restype;
			if (SNMP_ERROR_SUCCESS == send_sync_get_request(
					cur_name,
				curnamelen,
				res,
				restype))
			{
				if (res.length() > 0)
				{
					char oidname[MAX_OID_LEN * 2] = { 0 };
					for (size_t i = 0; i < curnamelen; ++i)
					{
						snprintf(
							oidname + strlen(oidname),
							MAX_OID_LEN * 2 - strlen(oidname),
							"%d.",
							cur_name[i]);
					}

					oidname[strlen(oidname) - 1] = '\0';

					walk_result[oidname] = res;
				}
			}
		}

		//get下一个oid
		if (nextnamelen > 0)
		{
			memmove(cur_name, next_name, nextnamelen * sizeof(oid));
			curnamelen = nextnamelen;
		}
		else
		{
			curnamelen = 0;
		}
	}

	if (atparam != 1)
	{
		close_session();
		if (!open_session(m_iTimeout))
		{
			return SNMP_ERROR_OPEN_FAIL;
		}
	}

	return SNMP_ERROR_SUCCESS;
}

///发送同步walk请求
///@param	rootname	操作的根节点的oid名称
///@param	walk_result	walk请求的返回结果
///@param    atparam端口index，用于参数存在多个端口的情况
int CSnmpWrapper::send_sync_walk_request(
	const oid *rootvalue,
	size_t rootvaluelen,
	CDPWALK_RESULT &walk_result,
	int atparam)
{
	oid cur_name[MAX_OID_LEN];
	size_t curnamelen;
	oid next_name[MAX_OID_LEN];
	size_t nextnamelen;

	COidInfo endoid;
	endoid.assign(rootvalue, rootvaluelen);

	memcpy((char *)cur_name, (char *)rootvalue, rootvaluelen * sizeof(oid));
	curnamelen = rootvaluelen;

	//指定端口的walk
	if (atparam != 1)
	{
		std::string oricomm = m_sCommunity;

		char buffer[100] = { 0 };
		sprintf(buffer, "@%d", atparam);
		m_sCommunity += buffer;

		close_session();
		if (!open_session(m_iTimeout))
		{
			return SNMP_ERROR_OPEN_FAIL;
		}

		m_sCommunity = oricomm; //还原community
	}

	while (curnamelen > 0)
	{
		DATAMAP get_result;
		int ret = send_sync_get_next_request(
				cur_name,
				curnamelen,
				endoid,
				(oid *)next_name,
				nextnamelen,
				get_result);

		//记录中间结果
		if (SNMP_ERROR_SUCCESS == ret)
		{
			DATAMAPITERATOR g_i = get_result.begin();
			for (; g_i != get_result.end(); ++g_i)
			{
				walk_result[g_i->first] = g_i->second.datavalue;
			}
		}

		//get下一个oid
		if (nextnamelen > 0)
		{
			memmove(cur_name, next_name, nextnamelen * sizeof(oid));
			curnamelen = nextnamelen;
		}
		else
		{
			curnamelen = 0;
		}
	}

	if (atparam != 1)
	{
		close_session();
		if (!open_session(m_iTimeout))
		{
			return SNMP_ERROR_OPEN_FAIL;
		}
	}

	return SNMP_ERROR_SUCCESS;
}

///发送异步walk请求
///@param	rootname	操作的根节点的oid名称
int CSnmpWrapper::send_async_walk_request(const char *name, int means)
{
	oid oidvalue[MAX_OID_LEN] = { 0 };
	size_t oidlen;

	if (!parse_oid(name, oidvalue, oidlen))
	{
		return SNMP_ERROR_PARSE_OID_FAIL;
	}

	COidInfo endoid;
	endoid.assign(oidvalue, oidlen);

	long reqid;
	int ret = -1;

	if( means == 1 )
	{
		ret = send_async_get_one_bulk_request(oidvalue, oidlen, reqid);
	}
	else
	{
		ret = send_async_get_next_request(oidvalue, oidlen, reqid);
	}

	if (SNMP_ERROR_SUCCESS == ret)
	{
		m_mEndOidMap[reqid] = endoid;
		m_AsyncWalkMark[endoid] = false;
	}

	return ret;
}

///发送异步walk请求
///@param	name	操作的oid名称
///@param	namelen	oid名称的长度
int CSnmpWrapper::send_async_walk_request(
	const oid *rootname,
	size_t rootnamelen,
	int means)
{
	COidInfo endoid;
	endoid.assign(rootname, rootnamelen);

	long reqid;
	int ret = -1;

	if( means == 1 )
	{
		ret = send_async_get_one_bulk_request(rootname, rootnamelen, reqid);
	}
	else
	{
		ret = send_async_get_next_request(rootname, rootnamelen, reqid);
	}
	if (SNMP_ERROR_SUCCESS == ret)
	{
		m_mEndOidMap[reqid] = endoid;
		m_AsyncWalkMark[endoid] = false;
	}

	return ret;
}

///发送同步set请求
///@param	name	操作的oid名称
///@param	namelen	oid名称的长度
int CSnmpWrapper::send_sync_set_request(const oid *name, size_t namelen)
{
	return 0;
}

///发送异步set请求
///@param	name	操作的oid名称
///@param	namelen	oid名称的长度
int CSnmpWrapper::send_async_set_request(const oid *name, size_t namelen)
{
	return 0;
}

///异步接收响应
void CSnmpWrapper::recv_async_response(void)
{
	int fds = 0, block = 1;
	fd_set fdset;
	struct timeval timeout;

	//只要有活跃的就一直处理
	while (m_iReqnum > 0)
	{
		fds = 0;
		block = 1;
		FD_ZERO(&fdset);	//把fd_set清零

		//设置select需要的信息
		//printf("ThreadId %d session %x %s\n", m_nThreadId, itDev->second.m_pSnmpSession, itDev->second.m_sDevName.c_str());
		g_cbLock.Lock();
		snmp_sess_select_info(m_pSnmpSession, &fds, &fdset, &timeout, &block);
		fds = select(fds, &fdset, NULL, NULL, block ? NULL : &timeout);

		if (fds < 0)
		{
#ifdef PACKAGE_OUTPUT
			printf("\nselect failed\n");
#endif
			perror("select failed");
			m_iReqnum = 0;
			g_cbLock.UnLock();
			break;
		}

		//g_cbLock.Lock();
		try
		{
			//fds返回的是等待处理的io数目
			if (fds)
			{
				snmp_sess_read(m_pSnmpSession, &fdset); //到这里就会调用callback
			}
			else
			{
				snmp_sess_timeout(m_pSnmpSession);
			}
		}

		catch(...)
		{
			printf("throw out the exception.\n");
		}

		g_cbLock.UnLock();
	}
}

///解析get请求返回结果
///@param status	  执行状态
///@param pdu		  返回的pdu
///@param result	  返回的数据
int CSnmpWrapper::parse_get_result(
	int status,
	const oid *oidvalue,
	size_t oidlen,
	struct snmp_pdu *response,
	std::string &result,
	int &resulttype)
{
	char buffer[1024] = { 0 };
	int bufflen = 1024;
	struct variable_list *vp;
	int ix;

	int returncode = SNMP_ERROR_SUCCESS;

	if (oidvalue == NULL || response == NULL)
	{
		return SNMP_ERROR_RESPONSE_ERROR;
	}

	switch (status)
	{
		case STAT_SUCCESS:
			{
				vp = response->variables;

				if (response->errstat == SNMP_ERR_NOERROR)
				{
					save_variable(resulttype, buffer, bufflen, vp);
				}
				else
				{
					for (ix = 1;
						 vp && ix != response->errindex;
						 vp = vp->next_variable, ix++)
					{
					}

					if (vp)
					{
						snprint_objid(
							buffer,
							sizeof(buffer),
							vp->name,
							vp->name_length);
					}
					else
					{
						strcpy(buffer, "(none)");
						fprintf(
							stdout,
							"%s: %s: %s\n",
							m_sPeerName.c_str(),
							buffer,
							snmp_errstring(response->errstat));
					}
				}

				//记录返回结果
				returncode = SNMP_ERROR_SUCCESS;
				result.assign(buffer, bufflen);
				break;
			}

		case STAT_TIMEOUT:
			{
				time_t now = time(NULL);

				char oidname[MAX_OID_LEN * 2] = { 0 };
				for (size_t i = 0; i < oidlen; ++i)
				{
					snprintf(
						oidname + strlen(oidname),
						MAX_OID_LEN * 2 - strlen(oidname),
						"%d.",
						oidvalue[i]);
				}

				oidname[strlen(oidname) - 1] = '\0';

				m_TimeoutEvent[oidname] = now;
	#ifdef PACKAGE_OUTPUT
				fprintf(stdout, "%s: Timeout\n", m_sPeerName.c_str());
	#endif
				returncode = SNMP_ERROR_RESPONSE_TIMEOUT;
				break;
			}

		case STAT_ERROR:
			{
				char *errstr;
				int liberr, syserr;

				snmp_sess_error(m_pSnmpSession, &liberr, &syserr, &errstr);

				char oidname[MAX_OID_LEN * 2] = { 0 };
				for (size_t i = 0; i < oidlen; ++i)
				{
					snprintf(
						oidname + strlen(oidname),
						MAX_OID_LEN * 2 - strlen(oidname),
						"%d.",
						oidvalue[i]);
				}

				oidname[strlen(oidname) - 1] = '\0';

				m_ErrorEvent[oidname] = errstr;

				free(errstr);

				returncode = SNMP_ERROR_RESPONSE_ERROR;
				break;
			}

		default:
			break;
	}

	return returncode;
}

///解析get next请求返回结果
///@param status	  执行状态
///@param response    返回的pdu
///@param end_oid	  结束遍历时的oid信息
///@param next_value  下一个要访问的oid的值
///@param nextvaluelen下一个要访问的oid的长度
///@param result	  返回的数据
int CSnmpWrapper::parse_get_next_result(
	int status,
	netsnmp_pdu *response,
	const COidInfo &endoid,
	oid *next_name,
	size_t &nextnamelen,
	DATAMAP &result,
	int nums)
{
	netsnmp_variable_list *vars;
	bool stop_parse = false;	//是否已经遍历完成
	int returncode = SNMP_ERROR_SUCCESS;

	//处理返回结果
	if (status == STAT_SUCCESS)
	{
		if (response->errstat == SNMP_ERR_NOERROR)
		{
			// check resulting variables
			for (vars = response->variables; vars; vars = vars->next_variable)
			{
				print_variable(vars->name, vars->name_length, vars);
				if ((vars->name_length < endoid.oidlen)
				||	( memcmp( endoid.oidvalue,
					vars->name,
					endoid.oidlen * sizeof(oid)) != 0) )
				{
					// not part of this subtree
					if( nums <= 0 )
					{
						stop_parse = true;
						continue;
					}
					else
					{
						nums--;
					}
				}

				//print_variable(vars->name, vars->name_length, vars);
				char idffer[MAX_OID_LEN * 2] = { 0 };
				for (size_t i = 0; i < vars->name_length; ++i)
				{
					snprintf(
						idffer + strlen(idffer),
						MAX_OID_LEN * 2 - strlen(idffer),
						"%d.",
						vars->name[i]);
				}

				idffer[strlen(idffer) - 1] = '\0';

				int valtype;
				char valffer[1024];
				int vallen = 1024;

				save_variable(valtype, valffer, vallen, vars);

				//记录返回结果
				SNMPRESULTDATA data;
				data.datatype = valtype;
				data.datavalue.assign(valffer, vallen);

				result[idffer] = data;

				if ((vars->type != SNMP_ENDOFMIBVIEW)
				&&	(vars->type != SNMP_NOSUCHOBJECT)
				&&	(vars->type != SNMP_NOSUCHINSTANCE))
				{
					//oid没变或者超过范围，结束遍历
					if (snmp_oid_compare(
							endoid.oidvalue,
						endoid.oidlen,
						vars->name,
						vars->name_length) >= 0)
					{
						//printf("get next end loop\n");
						stop_parse = true;
					}
					else
					{
						memmove(
							(char *)next_name,
							(char *)vars->name,
							vars->name_length * sizeof(oid));
						nextnamelen = vars->name_length;
					}
				}
				else
				{
					// an exception value, so stop
					stop_parse = true;
				}
			}

			returncode = SNMP_ERROR_SUCCESS;
		}
		else
		{
			// error in response, print it
			stop_parse = true;

			if (response->errstat == SNMP_ERR_NOSUCHNAME)
			{
#ifdef PACKAGE_OUTPUT
				printf("End of MIB\n");
#endif
			}
			else
			{
#ifdef PACKAGE_OUTPUT
				fprintf(
					stderr,
					"Error in packet.\nReason: %s\n",
					snmp_errstring(response->errstat));
#endif
				if (response->errindex != 0)
				{
#ifdef PACKAGE_OUTPUT
					fprintf(stderr, "Failed object: ");
#endif

					int count;
					for (count = 1, vars = response->variables;
						 vars && count != response->errindex;
						 vars = vars->next_variable, count++)
					{
					}

#ifdef PACKAGE_OUTPUT
					if (vars)
					{
						fprint_objid(stderr, vars->name, vars->name_length);
					}

					fprintf(stderr, "\n");
#endif
				}
			}

			returncode = SNMP_ERROR_RESPONSE_ERROR;
		}
	}
	else if (status == STAT_TIMEOUT)
	{
		time_t now = time(NULL);

		char oidname[MAX_OID_LEN * 2] = { 0 };
		for (size_t i = 0; i < endoid.oidlen; ++i)
		{
			snprintf(
				oidname + strlen(oidname),
				MAX_OID_LEN * 2 - strlen(oidname),
				"%d.",
				endoid.oidvalue[i]);
		}

		oidname[strlen(oidname) - 1] = '\0';

		m_TimeoutEvent[oidname] = now;

#ifdef PACKAGE_OUTPUT
		fprintf(stderr, "Timeout: No Response from %s\n", m_sPeerName.c_str());
#endif
		stop_parse = true;
		returncode = SNMP_ERROR_RESPONSE_TIMEOUT;
	}
	else
	{	/* status == STAT_ERROR */
		char *errstr;
		int liberr, syserr;

		//考虑异步情况
		snmp_sess_error(m_pSnmpSession, &liberr, &syserr, &errstr);

		char oidname[MAX_OID_LEN * 2] = { 0 };
		for (size_t i = 0; i < endoid.oidlen; ++i)
		{
			snprintf(
				oidname + strlen(oidname),
				MAX_OID_LEN * 2 - strlen(oidname),
				"%d.",
				endoid.oidvalue[i]);
		}

		oidname[strlen(oidname) - 1] = '\0';

		m_ErrorEvent[oidname] = errstr;

		free(errstr);

		stop_parse = true;
		returncode = SNMP_ERROR_RESPONSE_ERROR;
	}

	if (stop_parse)
	{
		nextnamelen = 0;
	}

	return returncode;
}

///解析返回的pdu数据
void CSnmpWrapper::save_variable(
	int &valtype,
	char *buffer,
	int &buflen,
	const netsnmp_variable_list *vp)
{
	if (!buffer || !vp)
	{
		return;
	}

	memset(buffer, 0, buflen);

	valtype = vp->type;

	switch (vp->type)
	{
		case ASN_INTEGER:
			{
				snprintf(buffer, buflen, "%ld", *vp->val.integer);
				buflen = strlen(buffer);
			}

			valtype = INT_ATTR;
			break;
		case ASN_BIT_STR:
			{
				memcpy(buffer, vp->val.bitstring, MIN(buflen - 1, vp->val_len));
				buflen = vp->val_len;
			}

			valtype = STRING_ATTR;
			break;
		case ASN_OPAQUE:
		case ASN_OCTET_STR:
			{
				memcpy(buffer, vp->val.string, MIN(buflen - 1, vp->val_len));
				buflen = vp->val_len;
			}

			valtype = STRING_ATTR;
			break;
		case ASN_OBJECT_ID:
			{
				snprint_objid(
					buffer,
					buflen,
					vp->val.objid,
					vp->val_len / sizeof(oid));
				buflen = strlen(buffer);
			}

			valtype = STRING_ATTR;
			break;
		case ASN_TIMETICKS:
		case ASN_GAUGE:
		case ASN_COUNTER:
		case ASN_UINTEGER:
			{
				snprintf(buffer, buflen, "%lu", *(u_long *)vp->val.integer);
				buflen = strlen(buffer);
			}

			valtype = INT_ATTR;
			break;
	#ifdef NETSNMP_WITH_OPAQUE_SPECIAL_TYPES
		case ASN_OPAQUE_I64:
			{
				printI64(buffer, vp->val.counter64);
				buflen = strlen(buffer);
			}

			valtype = INT_ATTR;
			break;

			//sprint_realloc_counter64(buf, buf_len, out_len, allow_realloc, var, NULL, NULL, NULL);
		case ASN_OPAQUE_U64:
		case ASN_OPAQUE_COUNTER64:
	#endif \
		\
		/* NETSNMP_WITH_OPAQUE_SPECIAL_TYPES */
		case ASN_COUNTER64:
			{
				printU64(buffer, vp->val.counter64);
				buflen = strlen(buffer);
			}

			valtype = INT_ATTR;
			break;
		case ASN_IPADDRESS:
			{
				u_char	*ip = vp->val.string;
				if (ip)
				{
					snprintf(
						buffer,
						buflen,
						"%d.%d.%d.%d",
						ip[0],
						ip[1],
						ip[2],
						ip[3]);
				}
				else
				{
					buffer[0] = '\0';
				}

				buflen = strlen(buffer);
			}

			valtype = STRING_ATTR;
			break;
	#ifdef NETSNMP_WITH_OPAQUE_SPECIAL_TYPES
		case ASN_OPAQUE_FLOAT:
			{
				snprintf(buffer, buflen, "%f", *vp->val.floatVal);
				buflen = strlen(buffer);
			}

			valtype = FLOAT_ATTR;
			break;

			//sprint_realloc_float(buf, buf_len, out_len, allow_realloc, var, NULL, NULL, NULL);
		case ASN_OPAQUE_DOUBLE:
			{
				snprintf(buffer, buflen, "%f", *vp->val.doubleVal);
				buflen = strlen(buffer);
			}

			valtype = FLOAT_ATTR;
			break;	//sprint_realloc_double(buf, buf_len, out_len, allow_realloc, var, NULL, NULL, NULL);
	#endif \
		\
		/* NETSNMP_WITH_OPAQUE_SPECIAL_TYPES */
		case ASN_NULL:
			{
				strcpy(buffer, "NULL");
				buflen = strlen(buffer);
			}

			valtype = STRING_ATTR;
			break;
		default:
			buflen = 0;
			break;
	}
}

///添加一条数据
void CSnmpWrapper::push_one_data(
	std::string key,
	int valuetype,
	std::string value)
{
	SNMPRESULTDATA data;

	data.datatype = valuetype;
	data.datavalue = value;

	m_Datamap[key] = data;
}

///添加一组数据
void CSnmpWrapper::push_group_data(const DATAMAP dm)
{
	DATAMAPCONSTITERATOR it = dm.begin();
	for (; it != dm.end(); ++it)
	{
		m_Datamap[it->first] = it->second;
	}
}

///获取一条数据,并从原容器删除，返回0表示成功，1表示没有数据
int CSnmpWrapper::pop_one_data(std::string &key, SNMPRESULTDATA &value)
{
	DATAMAPITERATOR it = m_Datamap.begin();
	if (it != m_Datamap.end())
	{
		key = it->first;
		value = it->second;

		m_Datamap.erase(it);

		return 0;
	}
	else
	{
		return 1;
	}
}

///获取一条数据，并保留在原容器中，返回0表示成功，1表示没有数据
int CSnmpWrapper::get_one_data(std::string &key, SNMPRESULTDATA &value)
{
	DATAMAPITERATOR it = m_Datamap.begin();
	if (it != m_Datamap.end())
	{
		key = it->first;
		value = it->second;

		return 0;
	}
	else
	{
		return 1;
	}
}

///获取所有数据，并将原容器清空
void CSnmpWrapper::pop_all_data(DATAMAP &dm)
{
	dm = m_Datamap;
	m_Datamap.clear();
}

///获取所有数据，并保留在原容器中
void CSnmpWrapper::get_all_data(DATAMAP &dm)
{
	dm = m_Datamap;
}

///读取一条错误事件，并从原容器删除
int CSnmpWrapper::pop_error_event(std::string &key, std::string &errormsg)
{
	if (m_ErrorEvent.size() == 0)
	{
		return -1;
	}
	else
	{
		std::map<std::string, std::string>::iterator it = m_ErrorEvent.begin();

		key = it->first;
		errormsg = it->second;
		m_ErrorEvent.erase(it);
		return 0;
	}
}

int CSnmpWrapper::pop_error_event_by_key(std::string key, std::string &errormsg)
{
	if (m_ErrorEvent.size() == 0)
	{
		return -1;
	}
	else
	{
		std::map<std::string, std::string>::iterator it = m_ErrorEvent.find(
				key);
		if (it != m_ErrorEvent.end())
		{
			errormsg = it->second;
			m_ErrorEvent.erase(it);
			return 0;
		}
		else
		{
			return -1;
		}
	}
}

///读取一条超时事件，并从原容器删除
int CSnmpWrapper::pop_timeout_event(std::string &key, time_t &happentime)
{
	if (m_TimeoutEvent.size() == 0)
	{
		return -1;
	}
	else
	{
		std::map<std::string, time_t>::iterator it = m_TimeoutEvent.begin();
		key = it->first;
		happentime = it->second;
		m_TimeoutEvent.erase(it);
		return 0;
	}
}

int CSnmpWrapper::pop_timeout_event_by_key(std::string key, time_t &happentime)
{
	if (m_TimeoutEvent.size() == 0)
	{
		return -1;
	}
	else
	{
		std::map<std::string, time_t>::iterator it = m_TimeoutEvent.find(key);
		if (it != m_TimeoutEvent.end())
		{
			happentime = it->second;
			m_TimeoutEvent.erase(it);
			return 0;
		}
		else
		{
			return -1;
		}
	}
}

///判断walk容器是否为空
bool CSnmpWrapper::is_walk_map_empty(void)
{
	if (m_AsyncWalkMark.size() == 0)
	{
		return true;
	}

	for (std::map<COidInfo, bool>::iterator c_i = m_AsyncWalkMark.begin();
		 c_i != m_AsyncWalkMark.end();
		 ++c_i)
	{
		if (c_i->second == true)
		{
			return false;
		}
	}

	return true;
}

///获取一条异步walk数据,并从原容器删除，返回0表示成功，1表示没有数据
int CSnmpWrapper::pop_one_walk_data(std::string &key, DATAMAP &value)
{
	ASYNCWALK_RESULT_ITERATOR it = m_AsyncWalkResult.begin();
	std::map<COidInfo, bool>::iterator	c_i;

	while (it != m_AsyncWalkResult.end())
	{
		c_i = m_AsyncWalkMark.find(it->first);
		if (c_i == m_AsyncWalkMark.end())
		{
#ifdef PACKAGE_OUTPUT
			printf("no record in AsyncWalkMark in pop_one_walk_data!\n");
#endif
			m_AsyncWalkResult.erase(it);
		}
		else
		{
			//walk结束了
			if (true == c_i->second)
			{
				char oidname[MAX_OID_LEN * 2] = { 0 };
				for (size_t i = 0; i < it->first.oidlen; ++i)
				{
					snprintf(
						oidname + strlen(oidname),
						MAX_OID_LEN * 2 - strlen(oidname),
						"%d.",
						it->first.oidvalue[i]);
				}

				oidname[strlen(oidname) - 1] = '\0';

				key = oidname;
				value = it->second;
				m_AsyncWalkResult.erase(it);
				m_AsyncWalkMark.erase(c_i);
				return 0;
			}

			++it;
		}
	}

	return 1;
}

///获取一条异步walk数据，并保留在原容器中，返回0表示成功，1表示没有数据
int CSnmpWrapper::get_one_walk_data(std::string &key, DATAMAP &value)
{
	ASYNCWALK_RESULT_ITERATOR it = m_AsyncWalkResult.begin();
	std::map<COidInfo, bool>::iterator	c_i;

	while (it != m_AsyncWalkResult.end())
	{
		c_i = m_AsyncWalkMark.find(it->first);
		if (c_i == m_AsyncWalkMark.end())
		{
#ifdef PACKAGE_OUTPUT
			printf("no record in AsyncWalkMark in get_one_walk_data!\n");
#endif
			m_AsyncWalkResult.erase(it);
		}
		else
		{
			//walk结束了
			if (true == c_i->second)
			{
				char oidname[MAX_OID_LEN * 2] = { 0 };
				for (size_t i = 0; i < it->first.oidlen; ++i)
				{
					snprintf(
						oidname + strlen(oidname),
						MAX_OID_LEN * 2 - strlen(oidname),
						"%d.",
						it->first.oidvalue[i]);
				}

				oidname[strlen(oidname) - 1] = '\0';

				key = oidname;
				value = it->second;
				return 0;
			}

			++it;
		}
	}

	return 1;
}

///获取rootkey对应的异步walk数据,并从原容器删除，返回0表示成功，1表示没有数据
int CSnmpWrapper::pop_walk_data_by_key(std::string key, DATAMAP &value)
{
	oid oidvalue[MAX_OID_LEN];
	size_t oidlen;

	if (!parse_oid(key.c_str(), oidvalue, oidlen))
	{
		snmp_perror(key.c_str());
		return 1;
	}

	COidInfo oidinfo;
	oidinfo.assign(oidvalue, oidlen);

	std::map<COidInfo, bool>::iterator	c_i = m_AsyncWalkMark.find(oidinfo);
	if (c_i == m_AsyncWalkMark.end())
	{
		return 1;
	}

	ASYNCWALK_RESULT_ITERATOR it = m_AsyncWalkResult.find(oidinfo);
	if (it == m_AsyncWalkResult.end())
	{
#ifdef PACKAGE_OUTPUT
		printf("no record in AsyncWalkMark in pop_walk_data_by_key!\n");
#endif
		m_AsyncWalkMark.erase(c_i);
		return 1;
	}

	if (false == c_i->second)
	{
		return 1;
	}

	value = it->second;

	m_AsyncWalkResult.erase(it);
	m_AsyncWalkMark.erase(c_i);

	return 0;
}

///获取rootkey对应的异步walk数据，并保留在原容器中，返回0表示成功，1表示没有数据
int CSnmpWrapper::get_walk_data_by_key(std::string key, DATAMAP &value)
{
	oid oidvalue[MAX_OID_LEN];
	size_t oidlen;

	if (!parse_oid(key.c_str(), oidvalue, oidlen))
	{
		return 1;
	}

	COidInfo oidinfo;
	oidinfo.assign(oidvalue, oidlen);

	std::map<COidInfo, bool>::iterator	c_i = m_AsyncWalkMark.find(oidinfo);
	if (c_i == m_AsyncWalkMark.end())
	{
		return 1;
	}

	ASYNCWALK_RESULT_ITERATOR it = m_AsyncWalkResult.find(oidinfo);
	if (it == m_AsyncWalkResult.end())
	{
#ifdef PACKAGE_OUTPUT
		printf("no record in AsyncWalkMark in pop_walk_data_by_key!\n");
#endif
		m_AsyncWalkMark.erase(c_i);
		return 1;
	}

	if (false == c_i->second)
	{
		return 1;
	}

	value = it->second;

	return 0;
}

bool CSnmpWrapper::parse_oid(const char *oidname, oid *oidvalue, size_t &oidlen)
{
	oidlen = 0;

	if (!oidname || !oidvalue)
	{
		printf("pointer NULL in CSnmpWrapper::parse_oid\n");
		return false;
	}

	string str = oidname;
	char *p = strtok((char *)str.c_str(), ".\r\n");
	while (p)
	{
		oidvalue[oidlen++] = atoi(p);
		p = strtok(NULL, ".\r\n");

		if (oidlen >= MAX_OID_LEN)
		{
			oidlen = 0;
			return false;
		}
	}

	return true;
}
