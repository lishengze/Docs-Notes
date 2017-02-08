/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	CSnmpWrapper.h
///@brief	定义了CSnmp相关操作的会话对象
///@history
///20110511	魏诚 创建该文件
///20140717 LSC	增加对GetBulk异步请求处理
#ifndef REF_CSNMPWRAPPER_H
#define REF_CSNMPWRAPPER_H

#include <map>
#include <string>
#include <list>
#include "net_snmp.h"
#include "COidInfo.h"
#include "systools.h"

#define MON_REPEATERS  0
#define MAX_REPETITIONS 5

///snmpwrapper类相关错误码
enum SNMP_RET_CODE
{
	SNMP_ERROR_SUCCESS				= 0,	//成功
	SNMP_ERROR_SESSION_NOT_OPENED,			//session没有open
	SNMP_ERROR_OID_NAME_INVALID,			//OID名字不正确
	SNMP_ERROR_SEND_FAIL,					//发送失败
	SNMP_ERROR_RESPONSE_STATUS_ERROR,		//响应的状态不正确
	SNMP_ERROR_RESPONSE_TIMEOUT,			//响应超时
	SNMP_ERROR_RESPONSE_ERROR,				//响应错误
	SNMP_ERROR_PARSE_OID_FAIL,				//OID解析失败
	SNMP_ERROR_OPEN_FAIL,					//Open Session失败
	SNMP_ERROR_LOW_VERSION					//版本太低
};


///CDPWALK返回结果容器
typedef std::map<std::string, std::string>	CDPWALK_RESULT;

///CDPWALK返回结果迭代器
typedef CDPWALK_RESULT::iterator CDPWALK_RESULT_ITERATOR;

//snmp返回的数据格式
typedef struct
{
	int datatype;			//数据类型
	std::string datavalue;	//数据值
} SNMPRESULTDATA;

//异步响应数据的容器
typedef std::map<std::string, SNMPRESULTDATA> DATAMAP;

//异步响应数据的迭代器
typedef DATAMAP::iterator DATAMAPITERATOR;

//异步响应数据的const迭代器
typedef DATAMAP::const_iterator DATAMAPCONSTITERATOR;

///异步WALK返回结果容器
typedef std::map<COidInfo, DATAMAP> ASYNCWALK_RESULT;

///异步WALK返回结果迭代器
typedef ASYNCWALK_RESULT::iterator	ASYNCWALK_RESULT_ITERATOR;

class CSnmpWrapper
{
	/* */
	public:

		///构造函数
		CSnmpWrapper(void) :
		m_pSnmpSession(NULL),
		m_lSnmpVersion(SNMP_VERSION_2c),
		m_sCommunity("community"),
		m_sPeerName("localhost"),
		m_iReqnum(0)
		{
		}

		CSnmpWrapper(
			const std::string snmpcommunity ,
			const std::string peername ,
			const long snmpversion = SNMP_VERSION_2c);

		//CSnmpWrapper(const CSnmpWrapper &ob)
		//{
		//	m_sCommunity = ob.m_sCommunity;
		//	m_sPeerName = ob.m_sPeerName;
		//	m_lSnmpVersion = ob.m_lSnmpVersion;

		//	if (NULL == ob.m_pSnmpSession)
		//	{
		//		m_pSnmpSession = NULL;
		//	}
		//	else
		//	{
		//	}
		//}
		/////重载“=”运算符
		//CSnmpWrapper &operator=(const CSnmpWrapper &ob)
		//{
		//	if (this == &ob)
		//	{
		//		return *this;
		//	}

		//	m_sCommunity = ob.m_sCommunity;
		//	m_sPeerName = ob.m_sPeerName;
		//	m_lSnmpVersion = ob.m_lSnmpVersion;

		//	if ( NULL != m_pSnmpSession )
		//	{
		//		delete m_pSnmpSession;
		//		m_pSnmpSession = NULL;
		//	}
		//	return *this;
		//}


		///析构函数，退出的时候自动close session
		~ CSnmpWrapper(void);

		///初始化函数,返回true表示成功，false失败
		bool open_session(long timeout = SNMP_DEFAULT_TIMEOUT);

		///关闭session
		void close_session(void);

		bool is_opened(void)
		{
			return (m_pSnmpSession != NULL);
		}

		///发送同步get请求
			///@param	name		操作的oid名称
			///@param	result		get请求的返回结果
		int send_sync_get_request(
				const char *name,
				std::string & result,
				int &resultype);

		///@param	oidvalue	操作的oid值
			///@param	oidlen		oid值的长度
			///@param	result		get请求的返回结果
		int send_sync_get_request(
				const oid * oidvalue,
				size_t oidlen,
				std::string & result,
				int &resulttype);

		///发送异步get请求
			///@param	name		操作的oid名称
		int send_async_get_request(const char *name);

		///@param	oidvalue	操作的oid值
			///@param	oidlen		oid值的长度
		int send_async_get_request(const oid *oidvalue, size_t oidlen);

		///发送同步walk请求
			///@param	rootname	操作的根节点的oid名称
			///@param	walk_result	walk请求的返回结果
			///@param    atparam端口index，用于参数存在多个端口的情况
		int send_sync_walk_request(
				const char	*rootname,
				CDPWALK_RESULT	&walk_result,
				int atparam = 1);

		///@param	rootvalue	操作的根节点的oid值
			///@param	rootvaluelen根节点oid值的长度
			///@param	walk_result	walk请求的返回结果
			///@param    atparam端口index，用于参数存在多个端口的情况	
		int send_sync_walk_request(
				const oid *rootvalue,
				size_t rootvaluelen,
				CDPWALK_RESULT &walk_result,
				int atparam = 1);

		///发送异步walk请求
			///@param	rootname	操作的根节点的oid名称
		int send_async_walk_request(const char *rootname, int means=0);

		///发送异步walk请求
			///@param	rootvalue	操作的根节点的oid值
			///@param	rootvaluelen根节点oid值的长度
		int send_async_walk_request(const oid *rootvalue, size_t rootvaluelen, int means=0);

		///发送同步set请求
			///@param	value		操作的oid值
			///@param	valuelen	oid值长度
		int send_sync_set_request(const oid *value, size_t valuelen);

		///发送异步set请求
			///@param	value		操作的oid值
			///@param	valuelen	oid值的长度
		int send_async_set_request(const oid *value, size_t valuelen);

		///异步接收响应，异步请求时必须由应用方主动调用
			///@param	utime		接收数据的超时时间
		void recv_async_response(void);

		///判断数据容器是否为空
		bool is_data_map_empty(void)
		{
			return (m_Datamap.size() == 0);
		}

		///获取一条异步数据,并从原容器删除，返回0表示成功，1表示没有数据
		int pop_one_data(std::string & key, SNMPRESULTDATA & value);

		///获取一条异步数据，并保留在原容器中，返回0表示成功，1表示没有数据
		int get_one_data(std::string & key, SNMPRESULTDATA & value);

		///获取所有异步数据，并将原容器清空
		void pop_all_data(DATAMAP &dm);

		///获取所有异步数据，并保留在原容器中
		void get_all_data(DATAMAP &dm);

		///清除数据容器
		void clear_all_data(void)
		{
			m_Datamap.clear();
		}

		///判断错误事件容器是否为空
		bool is_error_event_empty(void)
		{
			return (m_ErrorEvent.size() == 0);
		}

		///读取一条错误事件并从原容器删除
			///返回0表示成功，否则无数据可返回
		int pop_error_event(std::string & key, std::string & errormsg);

		///读取指定key对应的错误事件并从原容器删除
			///返回0表示成功，否则无数据可返回
		int pop_error_event_by_key(std::string key, std::string & errormsg);

		///清除错误事件容器
		void clear_error_event(void)
		{
			m_ErrorEvent.clear();
		}

		///判断超时事件容器是否为空
		bool is_timeout_event_empty(void)
		{
			return (m_TimeoutEvent.size() == 0);
		}

		///读取一条超时事件并从原容器删除
			///返回0表示成功，否则无数据可返回
		int pop_timeout_event(std::string & key, time_t & happentime);

		///读取指定key对应的超时事件并从原容器删除
			///返回0表示成功，否则无数据可返回
		int pop_timeout_event_by_key(std::string key, time_t &happentime);

		///清除超时事件容器
		void clear_timeout_event(void)
		{
			m_TimeoutEvent.clear();
		}

		///判断walk容器是否为空
		bool is_walk_map_empty(void);

		///获取一条异步walk数据,并从原容器删除，返回0表示成功，1表示没有数据
		int pop_one_walk_data(std::string & key, DATAMAP & value);

		///获取一条异步walk数据，并保留在原容器中，返回0表示成功，1表示没有数据
		int get_one_walk_data(std::string & key, DATAMAP & value);

		///获取rootoid对应的异步walk数据,并从原容器删除，返回0表示成功，1表示没有数据
		int pop_walk_data_by_key(std::string key, DATAMAP &value);

		///获取rootoid对应的异步walk数据，并保留在原容器中，返回0表示成功，1表示没有数据
		int get_walk_data_by_key(std::string key, DATAMAP &value);

		///清除walk数据容器
		void clear_all_walk_data(void)
		{
			m_AsyncWalkMark.clear();
			m_AsyncWalkResult.clear();
		}

		std::string get_community(void)
		{
			return m_sCommunity;
		}

		std::string get_peer_name(void)
		{
			return m_sPeerName;
		}

		//根据传入的字符串解析oid
		static bool parse_oid(
						const char	*oidname,
						oid *oidvalue,
						size_t	&oidlen);

	/* */
	private:
		///同步请求函数，返回0表示成功，其他失败
			///@param	reqtype		请求类型，支持SNMP_MSG_GET、SNMP_MSG_GETNEXT和SNMP_MSG_SET
			///@param	value		操作的oid值
			///@param	valuelen	oid值的长度
			///@param	status		执行状态
			///@param	response	返回的pdu	
		int send_sync_request(
				int reqtype,
				const oid *value,
				size_t valuelen,
				int &status,
				netsnmp_pdu * &response);

		///异步请求函数，返回0表示成功，其他失败
			///@param	reqtype		请求类型，支持SNMP_MSG_GET、SNMP_MSG_GETNEXT和SNMP_MSG_SET
			///@param	value		操作的oid值
			///@param	valuelen	oid值的长度
			///@param	reqid		请求的唯一标识id
		int send_async_request(
				int reqtype,
				const oid *value,
				size_t valuelen,
				long &reqid,
				int max_repetitions = MAX_REPETITIONS,
				int non_repeaters = MON_REPEATERS
				);

		///发送同步get next请求
			///@param	cur_name	当前操作的oid名称
			///@param	endoid		结束遍历条件的OID信息
			///@param	next_name	遍历的下一个oid值
			///@param	nextnamelen	遍历的下一个oid值的长度
			///@param	result		get next请求的返回结果
		int send_sync_get_next_request(
				const char	*cur_name,
				const COidInfo	&endoid,
				oid *next_name,
				size_t	&nextnamelen,
				DATAMAP &result);

		///@param	cur_oid		操作的oid值
			///@param	curoidlen	oid值的长度
			///@param	endoid		结束遍历条件的OID信息
			///@param	next_name	遍历的下一个oid值
			///@param	nextnamelen	遍历的下一个oid值的长度
			///@param	result		get next请求的返回结果
		int send_sync_get_next_request(
				const oid *cur_oid,
				size_t curoidlen,
				const COidInfo &endoid,
				oid *next_name,
				size_t &nextnamelen,
				DATAMAP &result);

		///发送异步get next请求
			///@param	name		操作的oid名称
			///@param	reqid		请求的唯一标识id
		int send_async_get_next_request(const char *name, long &reqid);

		///@param	oidvalue	操作的oid值
			///@param	oidlen		oid值长度
			///@param	reqid		请求的唯一标识id
		int send_async_get_next_request(
				const oid *oidvalue,
				size_t oidlen,
				long &reqid);

		///发送异步get bulk请求
			///@param	name		操作的oid名称
			///@param	reqid		请求的唯一标识id
		int send_async_get_one_bulk_request(const char *name, long &reqid);

		///@param	oidvalue	操作的oid值
			///@param	oidlen		oid值长度
			///@param	reqid		请求的唯一标识id
		int send_async_get_one_bulk_request(
				const oid *oidvalue,
				size_t oidlen,
				long &reqid);

		///默认的异步回调处理函数
			///@param operation,  操作类型
			///@param sp          该响应对应的snmp_session
			///@param reqid       pdu的请求id，0 代表 TRAP
			///@param pdu         返回的pdu对象
			///@param magic       请求的对象指针
		static int	snmp_async_processor(
						int operation,
						struct snmp_session *sp,
						int reqid,
						struct snmp_pdu *pdu,
						void *magic);

		///解析get请求返回结果
			///@param status	  执行状态
			///@param pdu		  返回的pdu
			///@param result	  返回的数据
		int parse_get_result(
				int status,
				const oid * oidvalue,
				size_t oidlen,
				struct snmp_pdu * pdu,
				std::string & result,
				int &resulttype);

		///解析返回的pdu数据
		void save_variable(
				int &valtype,
				char *buffer,
				int &buflen,
				const netsnmp_variable_list *var);

		///解析get next请求返回结果
			///@param status	  执行状态
			///@param response    返回的pdu
			///@param end_oid	  结束遍历时的oid信息
			///@param next_value  下一个要访问的oid的值
			///@param nextvaluelen下一个要访问的oid的长度
			///@param result	  返回的数据
		int parse_get_next_result(
				int status,
				netsnmp_pdu *response,
				const COidInfo &end_oid,
				oid *next_value,
				size_t &nextvaluelen,
				DATAMAP &result,
				int nums = 0);

		///添加一条异步数据
		void push_one_data(std::string key, int valuetype, std::string value);

		//添加一组异步数据
		void push_group_data(const DATAMAP dm);

	/* */
	private:
		///snmp会话指针
		void *m_pSnmpSession;

		///采用的snmp版本号,默认为SNMP_VERSION_2c
		long m_lSnmpVersion;

		///请求的community,默认为community
		std::string m_sCommunity;

		///访问的agent地址,默认为localhost
		std::string m_sPeerName;

		///请求超时时间
		int m_iTimeout;

		///异步请求中未收到响应的个数
		int m_iReqnum;

		///存放异步操作的返回结果
		DATAMAP m_Datamap;

		//异步walk是否完成记录表
		std::map<COidInfo, bool> m_AsyncWalkMark;

		//异步walk结果集
		ASYNCWALK_RESULT m_AsyncWalkResult;

		///存放walk结束条件的oid，支持同时发起多次请求
		ENDOIDMAP m_mEndOidMap;

		///snmp接收超时的事件，记录超时发生的时间
		std::map<std::string, time_t> m_TimeoutEvent;

		///snmp接收错误的事件，记录错误的原因
		std::map<std::string, std::string> m_ErrorEvent;

		//bulk请求取数个数 key=reqid,value=numbers
		TemplateMutexMap<long,int> m_BulkNum;
};
#endif
