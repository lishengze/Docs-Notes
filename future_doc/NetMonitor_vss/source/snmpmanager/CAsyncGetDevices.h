/////////////////////////////////////////////////////////////////////////
///@system	������ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CAsyncGetDevices.h
///@brief	������CAsyncGetDevicesʹ�õ���
///@history
///20100920	�ܽ���		�������ļ�
#ifndef REF_CASUNCGETDEVICES_H
#define REF_CASUNCGETDEVICES_H

#include "platform.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include "net_snmp.h"
#include "CSnmpWrapper.h"
#include "CTimePolicy.h"

#include <string>
#include <list>
#include <map>
#include <iostream>
using namespace std;

#define SNMPSYSNAMEOID	"1.3.6.1.2.1.1.5.0"
enum EVENT_TYPE
{
	INTERFACE_EVENT_TYPE= 1,	//"�˿�"
	FLUX_EVENT_TYPE,			//"����"
	NETDEV_EVENT_TYPE,			//"�����豸"
	DEVLINK_EVENT_TYPE,			//"�豸��ͨ"
	ROUTE_EVENT_TYPE,			//"·��"
	PERMAN_EVENT_TYPE,			//"����"
	SAFETY_EVENT_TYPE,			//"��ȫ"
	OTHERS_EVENT_TYPE,			//"����"
};

enum MON_TASK_STATUS
{
	PREPARE_STATUS		= 0,	//"�������"
	NORMAL_STATUS,				//"��������"
	UNWORK_STATUS,				//"������Ч"
	OTHERS_STATUS,				//"����"
};

enum MON_TASK_TYPE
{
	DURING_TASK			= 0,	//���ڲɼ�ָ������
	LOOP_TASK,					//Ѳ����ָ������
	ONCE_TASK,					//һ��ִ��һ�ε�����
};

//Oid��
class CVarOid
{
	/* */
	public:

		///��������
		~CVarOid(void)
		{
			if (m_pTimePolicy != NULL)
			{
				delete m_pTimePolicy;
				m_pTimePolicy = NULL;
			}
		}

		///���캯��
		CVarOid(void)
		{
			m_sOidName = "";
			memset((char *)m_sOoid, 0, MAX_OID_LEN);
			m_nOidLen = 0;
			m_pTimePolicy = NULL;
			m_sAttendValue = "";
			type = 0;
			exestate = 0;
			m_oidmeans = 0;
		}

		CVarOid(const CVarOid &ob)
		{
			m_sOidName = ob.m_sOidName;
			memcpy((char *)m_sOoid, (char *)ob.m_sOoid, MAX_OID_LEN);
			m_nOidLen = ob.m_nOidLen;
			m_sAttendValue = ob.m_sAttendValue;
			type = ob.type;
			exestate = ob.exestate;
			m_oidmeans = ob.m_oidmeans;
			if (ob.m_pTimePolicy == NULL)
			{
				m_pTimePolicy = NULL;
			}
			else
			{
				m_pTimePolicy = new CTimePolicy(*(ob.m_pTimePolicy));
			}
		}

		///���캯��
			///@param	pOidName	OID��
		CVarOid(
		const char	*pOidName,
		const char	*pPolicy,
		int ntype,
		const char	*pAttendValue)
		{
			m_sOidName = pOidName;
			m_sAttendValue = pAttendValue;
			memset((char *)m_sOoid, 0, MAX_OID_LEN);
			m_nOidLen = sizeof(m_sOoid) / sizeof(m_sOoid[0]);
			exestate = 0;
			m_oidmeans = 0;
			if (pPolicy != NULL)
			{
				m_pTimePolicy = new CTimePolicy(pPolicy);
				type = ntype;
			}
			else
			{
				m_pTimePolicy = NULL;
				type = LOOP_TASK;
			}
		}

		CVarOid &operator=(const CVarOid &ob)
		{
			if (this == &ob)
			{
				return *this;
			}

			m_sOidName = ob.m_sOidName;
			m_sAttendValue = ob.m_sAttendValue;
			type = ob.type;
			exestate = ob.exestate;
			m_oidmeans = ob.m_oidmeans;
			memcpy((char *)m_sOoid, (char *)ob.m_sOoid, MAX_OID_LEN);
			m_nOidLen = ob.m_nOidLen;

			if (m_pTimePolicy)
			{
				delete m_pTimePolicy;
			}

			if (ob.m_pTimePolicy == NULL)
			{
				m_pTimePolicy = NULL;
			}
			else
			{
				m_pTimePolicy = new CTimePolicy(*(ob.m_pTimePolicy));
			}

			return *this;
		}

		///Oid��������
			///@return	true��ʾ�����ɹ���falseΪʧ��
		bool snmpParseOid(void)
		{
			m_nOidLen = sizeof(m_sOoid) / sizeof(m_sOoid[0]);
			if (!CSnmpWrapper::parse_oid(
					m_sOidName.c_str(),
				(oid *)m_sOoid,
				(size_t &)m_nOidLen))
			{
				snmp_perror("read_objid");
				return false;
			}

			return true;
		}

		bool changeTimepolicy(const char *pPolicy)
		{
			if (pPolicy != NULL && m_pTimePolicy != NULL)
			{
				m_pTimePolicy->Init();
				m_pTimePolicy->AddPolicyStr(pPolicy);
				return true;
			}

			return false;
		}

		bool updateExeState(int state)
		{
			if (state >= 0)
			{
				exestate = state;
				return true;
			}

			return false;
		}

		void setoidmeans( int oidmeans )
		{
			m_oidmeans = oidmeans;
		}

	/* */
	public:
		///ִ�б���snmp��ѯ��ʱ�����
		CTimePolicy *m_pTimePolicy;

		///snmp�����OID
		string	m_sOidName;

		///��OID������Ҫ���ӵ��ֶ�,���豸�Ķ˿�����
		string	m_sAttendValue;

		///����֮���ID
		oid m_sOoid[MAX_OID_LEN];

		///����֮���ID����
		u_int m_nOidLen;

		///��ʶ�ɼ�ָ�������,0:���������Բɼ�ָ��,1:��ʶͨ��Ѳ��;���������Ĳɼ�ָ�꣬
			///ʱ�������Ч����ִ����֮��ָ������Ч����������ָ�꣩,100:��ʾ�������󼴿�ִ��,����ÿ��ִ��һ�Σ�ִ��ʱ���в����ƶ���
		int type;

		//exestate������ȡֵ:0,1,2���ֱ������������������Ч����varoid��һ��ִ��֮ǰ���ڡ���������ִ��֮���ɡ����������ߡ���Ч��
		//ͨ���������type���ۺ��ж��Ƿ�ִ�С�
		int exestate;

	private:
		//oid�ɼ���ʽ,1��ʾbulk��ȡ��oid��0��ʾ������Ĭ��Ϊ0
		int m_oidmeans;
};

enum CompAttrVarType
{
	Operator,	// ������
	Variate,	// ��ͨ����
	VariateLast,	// ������ǰһ��ֵ
	VariateTime		// ʱ�����
};

//�豸��
class CMonDevice
{
	/* */
	public:

		///��������
		~CMonDevice(void)
		{
			if (m_pSnmpWrapper)
			{
				delete m_pSnmpWrapper;
				m_pSnmpWrapper = NULL;
			}
		}

		///���캯��
		CMonDevice(void)
		{
			m_sHostName = "";
			m_sDevName = "";
			m_sCommunity = "";
			m_bActiveFlag = false;
			CSnmpWrapper::parse_oid(
					(const char *)SNMPSYSNAMEOID,
					(oid *)m_sSysNameOoid,
					(size_t &)m_nSysNameOidLen);
			m_pListObjectAttr = NULL;
			m_pListWarningEvent = NULL;
			m_pListSyslogEvent = NULL;
			m_pListUpdateConfig = NULL;
			m_pDate = NULL;
			m_pTime = NULL;

			m_pSnmpWrapper = NULL;
		}

		CMonDevice(const CMonDevice &ob)
		{
			m_sHostName = ob.m_sHostName;
			m_sDevName = ob.m_sDevName;
			m_sCommunity = ob.m_sCommunity;
			m_mapOid = ob.m_mapOid;
			m_bActiveFlag = ob.m_bActiveFlag;
			CSnmpWrapper::parse_oid(
					(const char *)SNMPSYSNAMEOID,
					(oid *)m_sSysNameOoid,
					(size_t &)m_nSysNameOidLen);
			m_pListObjectAttr = ob.m_pListObjectAttr;
			m_pListWarningEvent = ob.m_pListWarningEvent;
			m_pListSyslogEvent = ob.m_pListSyslogEvent;
			m_pListUpdateConfig = ob.m_pListUpdateConfig;
			m_pDate = ob.m_pDate;
			m_pTime = ob.m_pTime;

			if (NULL == ob.m_pSnmpWrapper)
			{
				m_pSnmpWrapper = NULL;
			}
			else
			{
				m_pSnmpWrapper = new CSnmpWrapper(
						ob.m_pSnmpWrapper->get_community(),
						ob.m_pSnmpWrapper->get_peer_name());
			}
		}

		///���캯��
			///�豸��IP��ַ
			///�豸��snmpͨ�Źؼ���
		CMonDevice(
		const char	*pHostName,
		const char	*pDevName,
		const char	*pCommunity)
		{
			m_sHostName = pHostName;
			m_sDevName = pDevName;
			m_sCommunity = pCommunity;
			m_bActiveFlag = false;
			CSnmpWrapper::parse_oid(
					(const char *)SNMPSYSNAMEOID,
					(oid *)m_sSysNameOoid,
					(size_t &)m_nSysNameOidLen);
			m_pListObjectAttr = NULL;
			m_pListWarningEvent = NULL;
			m_pListSyslogEvent = NULL;
			m_pListUpdateConfig = NULL;
			m_pDate = NULL;
			m_pTime = NULL;
			m_mapOid.clear();

			m_pSnmpWrapper = NULL;
		}

		CMonDevice &operator=(const CMonDevice &ob)
		{
			if (this == &ob)
			{
				return *this;
			}

			m_sHostName = ob.m_sHostName;
			m_sDevName = ob.m_sDevName;
			m_sCommunity = ob.m_sCommunity;
			m_mapOid = ob.m_mapOid;
			m_bActiveFlag = ob.m_bActiveFlag;
			CSnmpWrapper::parse_oid(
					(const char *)SNMPSYSNAMEOID,
					(oid *)m_sSysNameOoid,
					(size_t &)m_nSysNameOidLen);
			m_pListObjectAttr = ob.m_pListObjectAttr;
			m_pListWarningEvent = ob.m_pListWarningEvent;
			m_pListSyslogEvent = ob.m_pListSyslogEvent;
			m_pListUpdateConfig = ob.m_pListUpdateConfig;
			m_pDate = ob.m_pDate;
			m_pTime = ob.m_pTime;

			if (m_pSnmpWrapper)
			{
				delete m_pSnmpWrapper;
			}

			if (NULL == ob.m_pSnmpWrapper)
			{
				m_pSnmpWrapper = NULL;
			}
			else
			{
				m_pSnmpWrapper = new CSnmpWrapper(
						ob.m_pSnmpWrapper->get_community(),
						ob.m_pSnmpWrapper->get_peer_name());
			}

			return *this;
		}

		///����Oid�������ID����
			///@param	pOidName	Oid����
			///@return	true���ӳɹ���false����ʧ��
		bool addOid(
		const char	*pOidName,
		const char	*pAttrType,
		const char	*pSeps,
		int type,
		const char	*pAttendValue,
		int oidmeans = 0)
		{
			m_mapOidAttr[pOidName] = pAttrType;

			CVarOid tmpOid(pOidName, pSeps, type, pAttendValue);
			tmpOid.setoidmeans( oidmeans );
			if (tmpOid.snmpParseOid())
			{
				m_mapOid[pOidName] = tmpOid;
			}
			else
			{
				return false;
			}

			return true;
		}

		///��snmp���Ӳ����͵�һ��������
		bool openSnmpSession(int nNow);

		///��������������
		void updateHostName(const char *buffer);

		///���ñ������ݵĶ��е�ַ
		void setListsAddr(
		TemplateMutexCatch<CFTDRtnObjectAttrField>	*pListObjectAttr,
		TemplateMutexCatch<CFTDRtnWarningEventField> *pListWarningEvent,
		TemplateMutexCatch<CFTDRtnSyslogEventField> *pListSyslogEvent,
		TemplateMutexCatch<CFTDRtnUpdateSysConfigField> *
			pListUpdateConfig,
		TemplateMutexCatch<CFTDRtnObjectAttrField>	*pListConObjectAttr)
		{
			m_pListObjectAttr = pListObjectAttr;
			m_pListWarningEvent = pListWarningEvent;
			m_pListSyslogEvent = pListSyslogEvent;
			m_pListUpdateConfig = pListUpdateConfig;
			m_pListConObjectAttr = pListConObjectAttr;
		}

		///�����豸��������������
		void setCenterName(const char *pCenterName)
		{
			m_sCenterName = pCenterName;
		}

		///�����豸��������������
		void setSubNetName(const char *pSubNetName)
		{
			m_sSubNetName = pSubNetName;
		}

		///��������ʱ��ָ��
		void setDateTime(char *pDate, char *pTime)
		{
			m_pDate = pDate;
			m_pTime = pTime;
		}

		///�����豸��objectID
		void setObjectID(const char *pObjID)
		{
			m_sObjID = pObjID;
		}

		void process_snmp_result(void);
		void process_snmp_result_new(void);
		double	analyze_mem_result(const char *oidname, DATAMAP *dp);
		double computerAttrPerS(string oidvalue, CFTDRtnObjectAttrField &fieldInfo);
		bool set_next_oid(void);

	/* */
	public:
		///�豸������������
		string	m_sCenterName;

		///�豸�������ĵ��������ƣ����������칫��OA��
		string	m_sSubNetName;

		///�豸����
		string	m_sHostName;

		///�豸ip��ַ
		string	m_sDevName;

		///ͨ�Źؼ���
		string	m_sCommunity;

		///��Ծ���
		bool m_bActiveFlag;

		string	m_sObjID;

		///snmp�Ựָ��
		CSnmpWrapper *m_pSnmpWrapper;

		///����һ���豸��OID��Ӧ��Attr��Ϣ
			///@key	OidName���ƣ���1.3.6.1.2.1.1.1.0
			///@value	���ָ�OidName��Ӧ���������ƣ���sysDescr
		map<string, string> m_mapOidAttr;

		///����һ���豸��Ҫ��ȡ������oid��Ϣ
			///@key		OidName���ƣ���1.3.6.1.2.1.1.1.0
			///@value	���豸������OID
		map<string, CVarOid> m_mapOid;

		///�����Ѿ����͵��ĵ�����λ��
		map<string, CVarOid>::iterator	m_mapIt;

		///��ǰִ��ʱ��
		int m_nNow;

		///������ID����֮���OID
		oid m_sSysNameOoid[MAX_OID_LEN];

		///������ID����֮���ID����
		u_int m_nSysNameOidLen;

	/* */
	private:
		///����ָ��ֵ����
		TemplateMutexCatch<CFTDRtnObjectAttrField>	*m_pListConObjectAttr;

		///����ָ��ֵ����
		TemplateMutexCatch<CFTDRtnObjectAttrField>	*m_pListObjectAttr;

		///�澯�¼�����
		TemplateMutexCatch<CFTDRtnWarningEventField> *m_pListWarningEvent;

		///��־�¼�����
		TemplateMutexCatch<CFTDRtnSyslogEventField> *m_pListSyslogEvent;

		///���ñ������
		TemplateMutexCatch<CFTDRtnUpdateSysConfigField> *m_pListUpdateConfig;

		///ָ��һ�����豸�Ĳ�������
		char *m_pDate;

		///ָ��һ�����豸�Ĳ���ʱ��
		char *m_pTime;

		//ĳЩoidָ���Ӧ�������Field����
		map<string, CFTDRtnObjectAttrField> m_mapLastField;

	/* */
	public:
		///�Ƿ��Ѳ�������־�¼���澯�¼����
			///@key	ָ������
			///@value	��ָ���ڶ�ȡֵ�Ĺ����г��������־�¼���澯�¼����,1��־�¼�,2�澯�¼�,0δ����
		map<string, int> m_mapEventFlag;

	private:
		struct DeviceCompAttr	// �����豸��ĳһ������ָ����Ϣ
		{
			/* some define */
			static const double NULLValue;	// ��ʾ����ֵ���ֵ��DBL_MAX(max double)


			DeviceCompAttr() :m_CurrTime(0), m_LastTime(0){}
			struct CompAttrVariate		// ����ָ���е�һ����Ŀ�������������
			{
				CompAttrVariate();	// ʹ��ErrorValue��ʾ��ʼ��ֵ
				bool setVariate(string _varName);	// ���øñ���

				CompAttrVarType m_type;	// ����Ŀ���ͣ��Ǳ������ǲ�����
				string m_VarName;	// ����Ǳ�������ʼ��ΪOID��ENAME�������ᱻ����Ϊ��Ӧ��OID�ַ���������ǲ����������ֶ�Ϊ����Ĳ�����
				double m_CurrValue;	// ����ֵ��ͳһʹ��double
				double m_LastValue;	// ǰһֵ�����ڹ�ʽ�г��ֵ�LASTVALUE
			};

			/* Members */
			vector<CompAttrVariate> m_CompAttrFormular;	// ���幫ʽ

			time_t m_CurrTime;	// ���θ��µ�ʱ�䣬���ڼ���ʱ��ʹ�ñ���ϵͳʱ��
			time_t m_LastTime;	// ǰһ�θ��µ�ʱ�䣬���ڼ���ʱ��ʹ�ñ���ϵͳʱ��
			
			/* Functions */
			double Calculate();	// ���ݱ���ֵ�͹�ʽ���õ���������������ʱ�������󣬷���"ErrorValue"
		private:
			static char OperatorsPriority(char currOper, char lastOper);	// �������������������ȼ�
			static double OperatorCalculate(double _v1, char _oper, double _v2);	// ���㣺����1��������������2
		};

		typedef vector<DeviceCompAttr::CompAttrVariate> AttrFormular;
		// ����ָ�꼯�ϣ���ʼ����snmpmanager.xml�ļ�������CMonDevice����
		// key: ָ�����ƣ���������xml�ļ��ж�������ƣ��������̨���ص�ָ�����Ʋ�һ��
		// value: �����ָ��ʹ�õĹ�ʽ��Ϣ����ͬ���̿���ʹ�ò�ͬ�Ĺ�ʽ�����Ϊmultimap
		static multimap<string, AttrFormular > m_gCompoundAttrFormulars;

	public:
		// ��ʼ������ָ�궨��
		static void InitCompoundAttrs(char* _fileName);

		// ���¸���ָ�궨���������OID��Ϣ
		static void UpdateCompoundAttrOid(const char* _oidEName, const char* _oidString);
	
	private:
		// ���浱ǰ���ڼ���ĸ���ָ�꣬������ɺ��������ݣ����´μ���ʹ��
		// key: ָ�����ƣ����������ݿ��е�ָ������һ��
		// value: �����ָ����Ϣ
		map<string, DeviceCompAttr> m_CompoundAttrs;

		// ����һ������ָ����Ϣ�������豸��֧�ִ��ิ��ָ�꣬�򷵻�false
		// _Data�л����Ҷ��OID�ڵ�����ƣ���memoryPoolUsed����˼������Ҫ����Ϣ
		// �ɹ�����ָ��ø���ָ����Ϣ�ĵ����������򷵻�end()
		map<string, DeviceCompAttr>::iterator AddCompoundAttr(const char* _AttrName, DATAMAP &_Data);

		// ���¸���ָ���е�����
		// ���ø���ָ���е����б���ֵ������ֵ���򷵻�ture
		// ���򷵻�false��ֵ������Ƿ�������
		// _iterCompAttrInfo��ָ������µĸ���ָ����Ϣ
		bool UpdataCompoundValues(map<string, DeviceCompAttr>::iterator _iterCompAttrInfo, 
									DATAMAP &_Data, time_t _NowTime_t);

		// ���㸴��ָ��
		// _AttrName: ָ������
		// _OidName: OID����
		// _Data: ͨ��SNMP��ȡ�����ݼ�
		// ����ֵ��������ȷ�򷵻�ʵ�ʵ����ݣ�double���ͣ��м���̷��������򷵻�max double
		double CalculateCompoundAttr(const char* _AttrName, DATAMAP &_Data, const char* _MonDate, const char* _MonTime);

};

///һ�����豸�첽��ȡ��Ϣ��
class CAsyncGetDevices
{
	/* */
	public:

		///��������
		~CAsyncGetDevices(void)
		{
			SOCK_CLEANUP;
		}

		///���캯��
			///@param	pMibsPath	mib���ļ�Ŀ¼��
		CAsyncGetDevices(const int nThreadId, const char *pMibsPath)
		{
			m_nThreadId = nThreadId;
			m_pMibsPath = (char *)pMibsPath;
			initSnmp();
		}

		///���ӱ����豸OID����
			///@param	pDevIp	�����豸��IP��ַ
			///@param	pCommunity	snmpͨ�Źؼ���
			///@param	pOidName	Oid����
			///@param	pAttrType	Oid��Ӧ����������
			///@param	pSeps	����Ƶ��,�� "08:00:00-12:00:00.60,12:00:00-23:00:00.5"
			///@return	true���Ӳ�����Oid�ɹ���false��ʾ����ʧ�ܣ������oid���ӵ�oid�����
		bool addMonDevice(
		const char	*pHostName,
		const char	*pDevIp,
		const char	*pCommunity,
		const char	*subnetName,
		const char	*centerName,
		const char	*pOidName,
		const char	*pAttrType,
		const char	*pSeps,
		const char	*pObjID,
		const char	*pAttendValue)
		{
			if (pHostName == NULL || pDevIp == NULL || pCommunity == NULL)
			{
				return false;
			}

			m_mapDevicelock.Lock();

			//printf("get the m_mapDevicelock lock in function [%s].\n",__FUNCTION__ );
			map<string, CMonDevice>::iterator mapDevIt = m_mapDevices.find(
					pDevIp);
			if (mapDevIt == m_mapDevices.end())
			{
				m_mapDevices[pDevIp] = CMonDevice(
						pHostName,
						pDevIp,
						pCommunity);
				mapDevIt = m_mapDevices.find(pDevIp);
				mapDevIt->second.setListsAddr(
						&m_listObjectAttr,
						&m_listWarningEvent,
						&m_listSyslogEvent,
						&m_listUpdateConfig,
						&m_listConObjectAttr);
				mapDevIt->second.setSubNetName(subnetName);
				mapDevIt->second.setCenterName(centerName);
				mapDevIt->second.setObjectID(pObjID);
				mapDevIt->second.setDateTime(m_date, m_time);
			}

			mapDevIt->second.addOid(
					pOidName,
					pAttrType,
					pSeps,
					0,
					pAttendValue);
			m_mapDevicelock.UnLock();

			//printf("free the m_mapDevicelock lock in function [%s].\n",__FUNCTION__ );
			return true;
		}

		///���ӱ����豸OID����
			///@param	phost		�����豸ָ��
			///@param	pNetName	�豸����������
			///@param	pCenterName	�豸����������
			///@param   pOidName    oidȡֵ
			///@param	pAttrType	Oid��Ӧ����������
			///@param	policy		�������Զ���
			///@param	pAttendValue �����ֶ�
			///@return	true���Ӳ�����Oid�ɹ���false��ʾ����ʧ�ܣ������oid���ӵ�oid�����
		bool addMonDevice(
		const CFTDSysNetDeviceField *phost,
		const char	*pOidName,
		const char	*pAttrType,
		const char	*pPolicySeps,
		int taskType,
		const char	*pAttendValue,
		int oidmeans)
		{
			if (phost == NULL)
			{
				return false;
			}

			m_mapDevicelock.Lock();

			//printf("get the m_mapDevicelock lock in function [%s].\n",__FUNCTION__ );
			map<string, CMonDevice>::iterator mapDevIt = m_mapDevices.find(
					phost->IPADDR.getValue());
			if (mapDevIt == m_mapDevices.end())
			{
				//���Ӽ���豸����
				m_mapDevices[phost->IPADDR.getValue()] = CMonDevice(
						phost->NAME.getValue(),
						phost->IPADDR.getValue(),
						phost->RCOMMUNITY.getValue());
				mapDevIt = m_mapDevices.find(phost->IPADDR.getValue());
				mapDevIt->second.setListsAddr(
						&m_listObjectAttr,
						&m_listWarningEvent,
						&m_listSyslogEvent,
						&m_listUpdateConfig,
						&m_listConObjectAttr);
				mapDevIt->second.setObjectID(phost->ObjectID.getValue());
				mapDevIt->second.setDateTime(m_date, m_time);
			}

			//�༭����豸����ļ��ָ��
			if (pPolicySeps != NULL)
			{
				std::map<string, CVarOid>::iterator it_var = mapDevIt->second.
					m_mapOid.find(pOidName);
				if (it_var != mapDevIt->second.m_mapOid.end())
				{
					//�޸ļ��ָ��Ĳɼ�Ƶ��
					it_var->second.changeTimepolicy(pPolicySeps);
				}
				else
				{
					//���Ӽ��ָ��
					mapDevIt->second.addOid(
							pOidName,
							pAttrType,
							pPolicySeps,
							taskType,
							pAttendValue,
							oidmeans);
				}
			}
			else
			{
				//��������ģ���һ��ִ�У�����ÿ��ִ��һ�Σ����ָ��
				mapDevIt->second.addOid(
						pOidName,
						pAttrType,
						NULL,
						0,
						pAttendValue,
						oidmeans);
			}

			m_mapDevicelock.UnLock();

			//printf("free the m_mapDevicelock lock in function [%s].\n",__FUNCTION__ );
			return true;
		}

		bool addMonDeviceNew(
		const char	*pDevIp,
		const char	*pCommunity,
		const char	*pObjectID,
		const char	*pOidName,
		const char	*pAttrType,
		const char	*pPolicySeps,
		int taskType,
		const char *pAttendValue)
		{
			if (pObjectID == NULL || pDevIp == NULL || pCommunity == NULL)
			{
				printf(
					"add monitor device fail, ip=[%s] community=[%s] objectid=[%s].\n ",
					pDevIp,
					pCommunity,
					pObjectID);
				return false;
			}

			m_mapDevicelock.Lock();

			//printf("get the m_mapDevicelock lock in function [%s].\n",__FUNCTION__ );
			map<string, CMonDevice>::iterator mapDevIt = m_mapDevices.find(
					pDevIp);
			if (mapDevIt == m_mapDevices.end())
			{
				string name = pObjectID;
				name = name.substr(name.find_last_of('.') + 1);

				//name = string(pObjectID).find_last_of('.');
				//���Ӽ���豸����
				m_mapDevices[pDevIp] = CMonDevice(
						name.c_str(),
						pDevIp,
						pCommunity);
				mapDevIt = m_mapDevices.find(pDevIp);
				mapDevIt->second.setListsAddr(
						&m_listObjectAttr,
						&m_listWarningEvent,
						&m_listSyslogEvent,
						&m_listUpdateConfig,
						&m_listConObjectAttr);
				mapDevIt->second.setObjectID(pObjectID);
				mapDevIt->second.setDateTime(m_date, m_time);
			}

			//�༭����豸����ļ��ָ��
			if (pPolicySeps != NULL)
			{
				std::map<string, CVarOid>::iterator it_var = mapDevIt->second.
					m_mapOid.find(pOidName);
				if (it_var != mapDevIt->second.m_mapOid.end())
				{
					//�޸ļ��ָ��Ĳɼ�Ƶ��
					it_var->second.changeTimepolicy(pPolicySeps);
				}
				else
				{
					//���Ӽ��ָ��
					mapDevIt->second.addOid(
							pOidName,
							pAttrType,
							pPolicySeps,
							taskType,
							pAttendValue);
				}
			}
			else
			{
				//��������ģ���һ��ִ�У�����ÿ��ִ��һ�Σ����ָ��
				mapDevIt->second.addOid(
						pOidName,
						pAttrType,
						NULL,
						0,
						pAttendValue);
			}

			m_mapDevicelock.UnLock();

			//printf("free the m_mapDevicelock lock in function [%s].\n",__FUNCTION__ );
			return true;
		}

		///ɾ��ָ���ı����豸
			///@param	pDevIp	�����豸��IP��ַ
		bool removeMonDeviceTask(const char *pDevIp, const char *pOidName)
		{
			bool res = false;
			m_mapDevicelock.Lock();

			//printf("get the m_mapDevicelock lock in function [%s].\n",__FUNCTION__ );
			map<string, CMonDevice>::iterator mapDevIt = m_mapDevices.find(
					pDevIp);
			if (mapDevIt != m_mapDevices.end())
			{
				if (mapDevIt->second.m_mapOid.find(
						pOidName) != mapDevIt->second.m_mapOid.end())
				{
					mapDevIt->second.m_mapOid[pOidName].updateExeState(
							UNWORK_STATUS); //varoid��־��Ϊ��Ч
				}

				res = true;
			}

			m_mapDevicelock.UnLock();

			//printf("free the m_mapDevicelock lock in function [%s].\n",__FUNCTION__ );
			return res;
		}

		///������м���豸
		bool clearMonDevice(void)
		{
			m_mapDevicelock.Lock();
			printf(
				"get the m_mapDevicelock lock in function [%s].\n",
				__FUNCTION__);
			m_mapDevices.clear();
			m_mapDevicelock.UnLock();
			printf(
				"free the m_mapDevicelock lock in function [%s].\n",
				__FUNCTION__);
			return true;
		}

		///��ʼ��snmp�⺯��
		void initSnmp(void);

		///���������б����豸���͵�һ��snmpget����
		bool startAllHost(int nNow);

		///�첽����snmpget������Ӧ������
		bool run(int nNow);

		//////generate the attr & event data for test
		void genDataField(list<pair<int, string> > &data);
		void genOneDateField(pair<int, string> &data);

	/* */
	public:
		///�������б����豸
			///@key	�豸IP��ַ
			///@value	�����豸OID����Ϣ
		map<string, CMonDevice> m_mapDevices;

		//�����豸map��д��
		CMutex m_mapDevicelock;

		///����ָ��ֵ����,�������÷���Ĳɼ���Ϣ
		TemplateMutexCatch<CFTDRtnObjectAttrField> m_listConObjectAttr;

		///����ָ��ֵ����
		TemplateMutexCatch<CFTDRtnObjectAttrField> m_listObjectAttr;

		///�澯�¼�����
		TemplateMutexCatch<CFTDRtnWarningEventField> m_listWarningEvent;

		///��־�¼�����
		TemplateMutexCatch<CFTDRtnSyslogEventField> m_listSyslogEvent;

		///���ñ������
		TemplateMutexCatch<CFTDRtnUpdateSysConfigField> m_listUpdateConfig;

		///��ǰ����
		char m_date[10];
		char m_time[10];

	///��ǰʱ��
	protected:
	/* */
	private:
		// �����߳�ID���
		int m_nThreadId;

		///mib���ļ�Ŀ¼��ָ��
		char *m_pMibsPath;
};
#endif //END REF_CASUNCGETDEVICES_H
