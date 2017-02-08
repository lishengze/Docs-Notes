/////////////////////////////////////////////////////////////////////////
///@system	������ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CSnmpWrapper.h
///@brief	������CSnmp��ز����ĻỰ����
///@history
///20110511	κ�� �������ļ�
///20140717 LSC	���Ӷ�GetBulk�첽������
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

///snmpwrapper����ش�����
enum SNMP_RET_CODE
{
	SNMP_ERROR_SUCCESS				= 0,	//�ɹ�
	SNMP_ERROR_SESSION_NOT_OPENED,			//sessionû��open
	SNMP_ERROR_OID_NAME_INVALID,			//OID���ֲ���ȷ
	SNMP_ERROR_SEND_FAIL,					//����ʧ��
	SNMP_ERROR_RESPONSE_STATUS_ERROR,		//��Ӧ��״̬����ȷ
	SNMP_ERROR_RESPONSE_TIMEOUT,			//��Ӧ��ʱ
	SNMP_ERROR_RESPONSE_ERROR,				//��Ӧ����
	SNMP_ERROR_PARSE_OID_FAIL,				//OID����ʧ��
	SNMP_ERROR_OPEN_FAIL,					//Open Sessionʧ��
	SNMP_ERROR_LOW_VERSION					//�汾̫��
};


///CDPWALK���ؽ������
typedef std::map<std::string, std::string>	CDPWALK_RESULT;

///CDPWALK���ؽ��������
typedef CDPWALK_RESULT::iterator CDPWALK_RESULT_ITERATOR;

//snmp���ص����ݸ�ʽ
typedef struct
{
	int datatype;			//��������
	std::string datavalue;	//����ֵ
} SNMPRESULTDATA;

//�첽��Ӧ���ݵ�����
typedef std::map<std::string, SNMPRESULTDATA> DATAMAP;

//�첽��Ӧ���ݵĵ�����
typedef DATAMAP::iterator DATAMAPITERATOR;

//�첽��Ӧ���ݵ�const������
typedef DATAMAP::const_iterator DATAMAPCONSTITERATOR;

///�첽WALK���ؽ������
typedef std::map<COidInfo, DATAMAP> ASYNCWALK_RESULT;

///�첽WALK���ؽ��������
typedef ASYNCWALK_RESULT::iterator	ASYNCWALK_RESULT_ITERATOR;

class CSnmpWrapper
{
	/* */
	public:

		///���캯��
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
		/////���ء�=�������
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


		///�����������˳���ʱ���Զ�close session
		~ CSnmpWrapper(void);

		///��ʼ������,����true��ʾ�ɹ���falseʧ��
		bool open_session(long timeout = SNMP_DEFAULT_TIMEOUT);

		///�ر�session
		void close_session(void);

		bool is_opened(void)
		{
			return (m_pSnmpSession != NULL);
		}

		///����ͬ��get����
			///@param	name		������oid����
			///@param	result		get����ķ��ؽ��
		int send_sync_get_request(
				const char *name,
				std::string & result,
				int &resultype);

		///@param	oidvalue	������oidֵ
			///@param	oidlen		oidֵ�ĳ���
			///@param	result		get����ķ��ؽ��
		int send_sync_get_request(
				const oid * oidvalue,
				size_t oidlen,
				std::string & result,
				int &resulttype);

		///�����첽get����
			///@param	name		������oid����
		int send_async_get_request(const char *name);

		///@param	oidvalue	������oidֵ
			///@param	oidlen		oidֵ�ĳ���
		int send_async_get_request(const oid *oidvalue, size_t oidlen);

		///����ͬ��walk����
			///@param	rootname	�����ĸ��ڵ��oid����
			///@param	walk_result	walk����ķ��ؽ��
			///@param    atparam�˿�index�����ڲ������ڶ���˿ڵ����
		int send_sync_walk_request(
				const char	*rootname,
				CDPWALK_RESULT	&walk_result,
				int atparam = 1);

		///@param	rootvalue	�����ĸ��ڵ��oidֵ
			///@param	rootvaluelen���ڵ�oidֵ�ĳ���
			///@param	walk_result	walk����ķ��ؽ��
			///@param    atparam�˿�index�����ڲ������ڶ���˿ڵ����	
		int send_sync_walk_request(
				const oid *rootvalue,
				size_t rootvaluelen,
				CDPWALK_RESULT &walk_result,
				int atparam = 1);

		///�����첽walk����
			///@param	rootname	�����ĸ��ڵ��oid����
		int send_async_walk_request(const char *rootname, int means=0);

		///�����첽walk����
			///@param	rootvalue	�����ĸ��ڵ��oidֵ
			///@param	rootvaluelen���ڵ�oidֵ�ĳ���
		int send_async_walk_request(const oid *rootvalue, size_t rootvaluelen, int means=0);

		///����ͬ��set����
			///@param	value		������oidֵ
			///@param	valuelen	oidֵ����
		int send_sync_set_request(const oid *value, size_t valuelen);

		///�����첽set����
			///@param	value		������oidֵ
			///@param	valuelen	oidֵ�ĳ���
		int send_async_set_request(const oid *value, size_t valuelen);

		///�첽������Ӧ���첽����ʱ������Ӧ�÷���������
			///@param	utime		�������ݵĳ�ʱʱ��
		void recv_async_response(void);

		///�ж����������Ƿ�Ϊ��
		bool is_data_map_empty(void)
		{
			return (m_Datamap.size() == 0);
		}

		///��ȡһ���첽����,����ԭ����ɾ��������0��ʾ�ɹ���1��ʾû������
		int pop_one_data(std::string & key, SNMPRESULTDATA & value);

		///��ȡһ���첽���ݣ���������ԭ�����У�����0��ʾ�ɹ���1��ʾû������
		int get_one_data(std::string & key, SNMPRESULTDATA & value);

		///��ȡ�����첽���ݣ�����ԭ�������
		void pop_all_data(DATAMAP &dm);

		///��ȡ�����첽���ݣ���������ԭ������
		void get_all_data(DATAMAP &dm);

		///�����������
		void clear_all_data(void)
		{
			m_Datamap.clear();
		}

		///�жϴ����¼������Ƿ�Ϊ��
		bool is_error_event_empty(void)
		{
			return (m_ErrorEvent.size() == 0);
		}

		///��ȡһ�������¼�����ԭ����ɾ��
			///����0��ʾ�ɹ������������ݿɷ���
		int pop_error_event(std::string & key, std::string & errormsg);

		///��ȡָ��key��Ӧ�Ĵ����¼�����ԭ����ɾ��
			///����0��ʾ�ɹ������������ݿɷ���
		int pop_error_event_by_key(std::string key, std::string & errormsg);

		///��������¼�����
		void clear_error_event(void)
		{
			m_ErrorEvent.clear();
		}

		///�жϳ�ʱ�¼������Ƿ�Ϊ��
		bool is_timeout_event_empty(void)
		{
			return (m_TimeoutEvent.size() == 0);
		}

		///��ȡһ����ʱ�¼�����ԭ����ɾ��
			///����0��ʾ�ɹ������������ݿɷ���
		int pop_timeout_event(std::string & key, time_t & happentime);

		///��ȡָ��key��Ӧ�ĳ�ʱ�¼�����ԭ����ɾ��
			///����0��ʾ�ɹ������������ݿɷ���
		int pop_timeout_event_by_key(std::string key, time_t &happentime);

		///�����ʱ�¼�����
		void clear_timeout_event(void)
		{
			m_TimeoutEvent.clear();
		}

		///�ж�walk�����Ƿ�Ϊ��
		bool is_walk_map_empty(void);

		///��ȡһ���첽walk����,����ԭ����ɾ��������0��ʾ�ɹ���1��ʾû������
		int pop_one_walk_data(std::string & key, DATAMAP & value);

		///��ȡһ���첽walk���ݣ���������ԭ�����У�����0��ʾ�ɹ���1��ʾû������
		int get_one_walk_data(std::string & key, DATAMAP & value);

		///��ȡrootoid��Ӧ���첽walk����,����ԭ����ɾ��������0��ʾ�ɹ���1��ʾû������
		int pop_walk_data_by_key(std::string key, DATAMAP &value);

		///��ȡrootoid��Ӧ���첽walk���ݣ���������ԭ�����У�����0��ʾ�ɹ���1��ʾû������
		int get_walk_data_by_key(std::string key, DATAMAP &value);

		///���walk��������
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

		//���ݴ�����ַ�������oid
		static bool parse_oid(
						const char	*oidname,
						oid *oidvalue,
						size_t	&oidlen);

	/* */
	private:
		///ͬ��������������0��ʾ�ɹ�������ʧ��
			///@param	reqtype		�������ͣ�֧��SNMP_MSG_GET��SNMP_MSG_GETNEXT��SNMP_MSG_SET
			///@param	value		������oidֵ
			///@param	valuelen	oidֵ�ĳ���
			///@param	status		ִ��״̬
			///@param	response	���ص�pdu	
		int send_sync_request(
				int reqtype,
				const oid *value,
				size_t valuelen,
				int &status,
				netsnmp_pdu * &response);

		///�첽������������0��ʾ�ɹ�������ʧ��
			///@param	reqtype		�������ͣ�֧��SNMP_MSG_GET��SNMP_MSG_GETNEXT��SNMP_MSG_SET
			///@param	value		������oidֵ
			///@param	valuelen	oidֵ�ĳ���
			///@param	reqid		�����Ψһ��ʶid
		int send_async_request(
				int reqtype,
				const oid *value,
				size_t valuelen,
				long &reqid,
				int max_repetitions = MAX_REPETITIONS,
				int non_repeaters = MON_REPEATERS
				);

		///����ͬ��get next����
			///@param	cur_name	��ǰ������oid����
			///@param	endoid		��������������OID��Ϣ
			///@param	next_name	��������һ��oidֵ
			///@param	nextnamelen	��������һ��oidֵ�ĳ���
			///@param	result		get next����ķ��ؽ��
		int send_sync_get_next_request(
				const char	*cur_name,
				const COidInfo	&endoid,
				oid *next_name,
				size_t	&nextnamelen,
				DATAMAP &result);

		///@param	cur_oid		������oidֵ
			///@param	curoidlen	oidֵ�ĳ���
			///@param	endoid		��������������OID��Ϣ
			///@param	next_name	��������һ��oidֵ
			///@param	nextnamelen	��������һ��oidֵ�ĳ���
			///@param	result		get next����ķ��ؽ��
		int send_sync_get_next_request(
				const oid *cur_oid,
				size_t curoidlen,
				const COidInfo &endoid,
				oid *next_name,
				size_t &nextnamelen,
				DATAMAP &result);

		///�����첽get next����
			///@param	name		������oid����
			///@param	reqid		�����Ψһ��ʶid
		int send_async_get_next_request(const char *name, long &reqid);

		///@param	oidvalue	������oidֵ
			///@param	oidlen		oidֵ����
			///@param	reqid		�����Ψһ��ʶid
		int send_async_get_next_request(
				const oid *oidvalue,
				size_t oidlen,
				long &reqid);

		///�����첽get bulk����
			///@param	name		������oid����
			///@param	reqid		�����Ψһ��ʶid
		int send_async_get_one_bulk_request(const char *name, long &reqid);

		///@param	oidvalue	������oidֵ
			///@param	oidlen		oidֵ����
			///@param	reqid		�����Ψһ��ʶid
		int send_async_get_one_bulk_request(
				const oid *oidvalue,
				size_t oidlen,
				long &reqid);

		///Ĭ�ϵ��첽�ص�������
			///@param operation,  ��������
			///@param sp          ����Ӧ��Ӧ��snmp_session
			///@param reqid       pdu������id��0 ���� TRAP
			///@param pdu         ���ص�pdu����
			///@param magic       ����Ķ���ָ��
		static int	snmp_async_processor(
						int operation,
						struct snmp_session *sp,
						int reqid,
						struct snmp_pdu *pdu,
						void *magic);

		///����get���󷵻ؽ��
			///@param status	  ִ��״̬
			///@param pdu		  ���ص�pdu
			///@param result	  ���ص�����
		int parse_get_result(
				int status,
				const oid * oidvalue,
				size_t oidlen,
				struct snmp_pdu * pdu,
				std::string & result,
				int &resulttype);

		///�������ص�pdu����
		void save_variable(
				int &valtype,
				char *buffer,
				int &buflen,
				const netsnmp_variable_list *var);

		///����get next���󷵻ؽ��
			///@param status	  ִ��״̬
			///@param response    ���ص�pdu
			///@param end_oid	  ��������ʱ��oid��Ϣ
			///@param next_value  ��һ��Ҫ���ʵ�oid��ֵ
			///@param nextvaluelen��һ��Ҫ���ʵ�oid�ĳ���
			///@param result	  ���ص�����
		int parse_get_next_result(
				int status,
				netsnmp_pdu *response,
				const COidInfo &end_oid,
				oid *next_value,
				size_t &nextvaluelen,
				DATAMAP &result,
				int nums = 0);

		///���һ���첽����
		void push_one_data(std::string key, int valuetype, std::string value);

		//���һ���첽����
		void push_group_data(const DATAMAP dm);

	/* */
	private:
		///snmp�Ựָ��
		void *m_pSnmpSession;

		///���õ�snmp�汾��,Ĭ��ΪSNMP_VERSION_2c
		long m_lSnmpVersion;

		///�����community,Ĭ��Ϊcommunity
		std::string m_sCommunity;

		///���ʵ�agent��ַ,Ĭ��Ϊlocalhost
		std::string m_sPeerName;

		///����ʱʱ��
		int m_iTimeout;

		///�첽������δ�յ���Ӧ�ĸ���
		int m_iReqnum;

		///����첽�����ķ��ؽ��
		DATAMAP m_Datamap;

		//�첽walk�Ƿ���ɼ�¼��
		std::map<COidInfo, bool> m_AsyncWalkMark;

		//�첽walk�����
		ASYNCWALK_RESULT m_AsyncWalkResult;

		///���walk����������oid��֧��ͬʱ����������
		ENDOIDMAP m_mEndOidMap;

		///snmp���ճ�ʱ���¼�����¼��ʱ������ʱ��
		std::map<std::string, time_t> m_TimeoutEvent;

		///snmp���մ�����¼�����¼�����ԭ��
		std::map<std::string, std::string> m_ErrorEvent;

		//bulk����ȡ������ key=reqid,value=numbers
		TemplateMutexMap<long,int> m_BulkNum;
};
#endif
