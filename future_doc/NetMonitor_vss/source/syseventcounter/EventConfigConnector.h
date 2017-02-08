/////////////////////////////////////////////////////////////////////////
///@system	������ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	EventConfigConnector.h
///@brief	�����˺����÷�����ͨѶ����
///@history
///20110817	κ��		�������ļ�
#ifndef REF_EVENTCONFIGCONNECTOR_H
#define REF_EVENTCONFIGCONNECTOR_H

#include "public.h"
#include "CachedFlow.h"
#include "CachedFileFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "CDate.h"
#include "systools.h"

/////////////////////////////////////////////////////////////////////////
///CObjectAttrKey������ObjectID��AttrID��Ϊmap�ؼ��ֵ���
///@author	�ܽ���
///@version	1.0,20080710
/////////////////////////////////////////////////////////////////////////
class CObjectAttrKey
{
	/* */
	public:

		///���캯��
		
		CObjectAttrKey(void)
		{
			m_nObjectID = "";
			m_nAttrID = "";
			m_sProcessFlag = "";
			m_sEventDes = "";
		}

		///���캯��
			///@param	m_nObjectID	����ID
			///@param	m_nAttrID	ָ��ID
		CObjectAttrKey(string nObjectID, string nAttrID, string sProcessFlag = "", string sEventDes = "")
		{
			m_nObjectID = nObjectID;
			m_nAttrID = nAttrID;
			m_sProcessFlag = sProcessFlag;
			m_sEventDes = sEventDes;
		}

		///�������캯��
		
		CObjectAttrKey(const CObjectAttrKey &ob)
		{
			m_nObjectID = ob.m_nObjectID;
			m_nAttrID = ob.m_nAttrID;
			m_sProcessFlag = ob.m_sProcessFlag;
			m_sEventDes = ob.m_sEventDes;
		}

		///����=�����
		
		void operator=(const CObjectAttrKey &ob)
		{
			m_nObjectID = ob.m_nObjectID;
			m_nAttrID = ob.m_nAttrID;
			m_sProcessFlag = ob.m_sProcessFlag;
			m_sEventDes = ob.m_sEventDes;
		}

		///����>�����
		
		friend bool operator>(
		const CObjectAttrKey &ob1,
		const CObjectAttrKey &ob2)
		{
			if (ob1.m_nObjectID > ob2.m_nObjectID)
			{
				return true;
			}
			else if (ob1.m_nObjectID == ob2.m_nObjectID)
			{
				if (ob1.m_nAttrID > ob2.m_nAttrID)
				{
					return true;
				}
			}

			return false;
		}

		///����>�����
		
		friend bool operator < (const CObjectAttrKey &ob1, const CObjectAttrKey &ob2)
		{
			if (ob1.m_nObjectID < ob2.m_nObjectID)
			{
				return true;
			}
			else if (ob1.m_nObjectID == ob2.m_nObjectID)
			{
				if (ob1.m_nAttrID < ob2.m_nAttrID)
				{
					return true;
				}
			}

			return false;
		}

		///����==�����
		
		friend bool operator==(
		const CObjectAttrKey &ob1,
		const CObjectAttrKey &ob2)
		{
			if (ob1.m_nObjectID == ob2.m_nObjectID
			&&	ob1.m_nAttrID == ob2.m_nAttrID)
			{
				return true;
			}

			return false;
		}

	/* */
	public:
		///����ID
		string	m_nObjectID;

		///ָ��ID
		string	m_nAttrID;

		///������
		string m_sProcessFlag;

		///��������
		string m_sEventDes;
};

class CObjectAttrValue
{
	/* */
	public:

		///���캯��
		CObjectAttrValue(void)
		{
			m_nTime = 0;
			m_nValue = 0;
		}

		///���캯��
			///@param	m_nObjectID	����ID
			///@param	m_nAttrID	ָ��ID
		CObjectAttrValue(int nTime, double nValue)
		{
			m_nTime = nTime;
			m_nValue = nValue;
		}

		///�������캯��
		CObjectAttrValue(const CObjectAttrValue &ob)
		{
			m_nTime = ob.m_nTime;
			m_nValue = ob.m_nValue;
		}

		///����=�����
		void operator=(const CObjectAttrValue &ob)
		{
			m_nTime = ob.m_nTime;
			m_nValue = ob.m_nValue;
		}

	/* */
	public:
		///����ID
		int m_nTime;

		///ָ��ID
		double	m_nValue;
};

//������� ������������ip������
//@int key=id����Ӧʵ����ID������,@CFTDSysNetAreaField value=ʵ��
typedef std::map<int, CFTDSysNetAreaField>	NET_AREA_MAP;
typedef NET_AREA_MAP::iterator	NET_AREA_MAP_ITERATOR;

//@int key=id����Ӧʵ����ID������,@CFTDSysNetSubAreaField value=ʵ��
typedef std::map<int, CFTDSysNetSubAreaField> NET_SUB_AREA_MAP;
typedef NET_SUB_AREA_MAP::iterator	NET_SUB_AREA_MAP_ITERATOR;

//@int key=id����Ӧʵ����ID������,@CFTDSysNetSubAreaIPField value=ʵ��
typedef std::map<int, CFTDSysNetSubAreaIPField> NET_SUB_AREA_IP_MAP;
typedef NET_SUB_AREA_IP_MAP::iterator NET_SUB_AREA_IP_MAP_ITERATOR;

//��ض����������@string  key="Сд��ename",CFTDSysNetMonitorTypeField value=ʵ��
typedef std::map<string, CFTDSysNetMonitorTypeField> MONITOR_TYPE_MAP;
typedef MONITOR_TYPE_MAP::iterator	MONITOR_TYPE_MAP_ITERATOR;

//�����豸ͨ�Źؼ������� @string key=ip��ַ,@string value=�ؼ���
typedef std::map<std::string, std::string>	COMMUNITY_MAP;
typedef COMMUNITY_MAP::iterator COMMUNITY_MAP_ITERATOR;

//�豸�������� @string key=Сд��ename, @CFTDSysNetManufactoryField value=ʵ��
typedef std::map<string, CFTDSysNetManufactoryField> DEV_MANUFACTORY_MAP;
typedef DEV_MANUFACTORY_MAP::iterator DEV_MANUFACTORY_MAP_ITERATOR;

//�豸������� @string key=Сд��ename, @CFTDSysNetDeviceCategoryField value=ʵ��
typedef std::map<string, CFTDSysNetDeviceCategoryField> DEV_TYPE_MAP;
typedef DEV_TYPE_MAP::iterator	DEV_TYPE_MAP_ITERATOR;

//�豸�ͺ����� @int key=id, @CFTDSysNetDeviceTypeField value=ʵ��
typedef std::map<int, CFTDSysNetDeviceTypeField> DEV_SERIAL_MAP;
typedef DEV_SERIAL_MAP::iterator DEV_SERIAL_MAP_ITERATOR;

//key��ʹ�õ����ӷ���
#define CONSYM	"@#$";

//���������·��ĳ���oid�ṹ������Ӧ������
//@string ���serialnameΪ�գ�key=OidEname+CONSYM+ManuEname,
//		  ����key=OidEname+CONSYM+ManuEname+CONSYM+SerialEname
//@CFTDSysNetOIDField value=ʵ��
typedef std::map<string, CFTDSysNetOIDField> CON_OID_CONTAIN_MAP;
typedef CON_OID_CONTAIN_MAP::iterator CON_OID_CONTAIN_MAP_ITERATOR;

//�����豸���� @int key=id,�豸ID������, @CFTDSysNetDeviceField value=CFTDSysNetDeviceFieldʵ��
typedef std::map<int, CFTDSysNetDeviceField> NET_DEVICE_MAP;
typedef NET_DEVICE_MAP::iterator NET_DEVICE_MAP_ITERATOR;

// �����豸object id���� @string key=objectid,�豸��objectid,@int value=id �豸�ı��
typedef std::map<string, int> NET_DEV_OBJID_MAP;
typedef NET_DEV_OBJID_MAP::iterator NET_DEV_OBJID_MAP_ITERATOR;

//����ӿ�����
//@int key = id,�ӿڶ�Ӧ��ID������, @CFTDSysNetInterfaceField value=CFTDSysNetInterfaceFieldʵ��
typedef std::map<int, CFTDSysNetInterfaceField> NET_INTERFACE_MAP;
typedef NET_INTERFACE_MAP::iterator NET_INTERFACE_MAP_ITERATOR;

//�豸ģ������
//@int key = int,ģ��id, @CFTDSysNetInterfaceField value=CFTDSysNetInterfaceFieldʵ��
typedef std::map<int, CFTDSysNetModuleField> NET_MODULE_MAP;
typedef NET_MODULE_MAP::iterator NET_MODULE_MAP_ITERATOR;

//ʱ����Խṹ�������� @int key=id,ʱ����Ե�ID������, @CFTDSysNetTimePolicyField value=CFTDSysNetTimePolicyFieldʵ��
typedef std::map<int, CFTDSysNetTimePolicyField> TIME_POLICY_MAP;
typedef TIME_POLICY_MAP::iterator TIME_POLICY_MAP_ITERATOR;

//�������ṹ��������  @long key=id����������ID������, @MONITOR_TASK value=MONITOR_TASKʵ��

//����id���֣���������ֱ���·���id��ǰ׺"10"��ͷ����Ѳ������ָ�ɣ�id��ǰ׺"11"��ͷ�����ࡣ
struct MONITOR_TASK
{
	int policyID;
	int rtnType;
	string objectid;
	string attritype;
	bool is_dispatch;
};
typedef MONITOR_TASK *PMONITOR_TASK;
typedef std::map<long, MONITOR_TASK> MONITOR_TASK_MAP;
typedef MONITOR_TASK_MAP::iterator	MONITOR_TASK_MAP_ITERATOR;

//Ѳ���������� @int key = id, @CFTDSysNetMonitorTaskInfoField valueʵ��
typedef std::map<int, CFTDSysNetMonitorTaskInfoField> LOOP_ITEM_MAP;
typedef LOOP_ITEM_MAP::iterator LOOP_ITEM_MAP_ITERATOR;

//Ѳ��ָ������ key = id
typedef std::map<int, CFTDSysNetMonitorCommandTypeField> COMMAND_MAP;
typedef COMMAND_MAP::iterator COMMAND_MAP_ITERATOR;

//Ѳ�춯������ key = id
typedef std::map<int, CFTDSysNetMonitorActionGroupField> ACTION_GROUP_MAP;
typedef ACTION_GROUP_MAP::iterator	ACTION_GROUP_MAP_ITERATOR;

//Ѳ���豸���������� key = id
typedef std::map<int, CFTDSysNetMonitorDeviceGroupField> DEVICE_GROUP_MAP;
typedef DEVICE_GROUP_MAP::iterator	DEVICE_GROUP_MAP_ITERATOR;

//���ָ��������key = manu;;;monitor_type
typedef std::map<string, map<string, int> > MONITOR_ATTR_MAP;
typedef MONITOR_ATTR_MAP::iterator	MONITOR_ATTR_MAP_ITERATOR;

//�澯���ʽ����
typedef std::map<int, CFTDRspQryNetEventExprField>	WARNING_EXPRESSION;
typedef WARNING_EXPRESSION::iterator WARNING_EXPRESSION_ITERATOR;

//���ʽ�������豸�б�,first_key:���ʽid, second_key:����objectid
typedef map<int, map<string, int> > EXPR_DEVICE_LIST;
typedef EXPR_DEVICE_LIST::iterator EXPR_DEVICE_LIST_ITERATOR;

typedef list<int> LIST_ID;
typedef LIST_ID::iterator LIST_ID_IT;

//@int key=id���豸����ID��ʶ,@list <int> value=�豸����ID�б�
typedef std::map<int, LIST_ID> MAP_DEVICEGROUPLIST;
typedef MAP_DEVICEGROUPLIST::iterator MAP_DEVICEGROUPLIST_IT;

//@int key=id����Ӧʵ����ID������,@CFTDSysNetDeviceField value=ʵ��
typedef std::map<int, CFTDSysNetDeviceField> MAP_DEVICE;
typedef MAP_DEVICE::iterator MAP_DEVICE_IT;

//key:factoryid_objectid_cmd, value:paramlist(key:seq, value:paramvalue)
//Ѳ������ؽ����������˹���
//��ͬ����ͬ�豸�ɵ������ƹ���
typedef std::map<string, vector<map<int, string> > > MAP_TASK_REGULAR_PARAM;
typedef MAP_TASK_REGULAR_PARAM::iterator MAP_TASK_REGULAR_PARAM_IT;

//key:ip_port
//��Ա��·��Ϣ��
typedef std::map<string, CFTDSysNetPartyLinkInfoField> MAP_PARTYLINK_INFO;
typedef MAP_PARTYLINK_INFO::iterator MAP_PARTYLINK_INFO_IT;

//�������� @int key=����ID������
class BaseLineInfo
{
	/* */
	public:
		string name;	//������
		string data;	//��������
		int flag;		//������Ƿ���0��ʾ��δ���꣬1��ʾ������
};

typedef std::map<int, BaseLineInfo> NET_BASELINE_MAP;
typedef NET_BASELINE_MAP::iterator	NET_BASELINE_MAP_ITERATOR;

//ָ����Ϣ��
class CInstructionInfo
{
	/* */
	public:
		string defaultregular;		//ָ���Ĭ�Ϸ�ֵ����
		vector<string> attrlist;	//ָ���Ӧ��ָ���б�
		vector<map<int, string> > defaultparams;	//����Ĭ�ϵĲ����б�
};

//key:cmdalias_devicetype
//��ͬ���ͬ���̶�Ӧ��ָ����Բ�ͬ
typedef std::map<string, CInstructionInfo>	MAP_INSTR_INFO;
typedef MAP_INSTR_INFO::iterator MAP_INSTRINFO_IT;

class CConfigConnector :
	public CSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///���캯��	
			///@param	pReactor	CReactor����ָ��
		CConfigConnector(CReactor *pReactor);

		///�½��Ựʱ���õĴ�����
			///@param	pChannel	�Ự������ͨ����ַ
			///@param	bIsListener	�Ự�Ƿ��Ǽ�������������
			///@return	���ش������»Ự
		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		///���ӳɹ�ʱ���õĴ�����
			///@param	pSession	���ӳɹ��ĻỰָ��
		virtual void OnSessionConnected(CSession *pSession);

	/* */
	protected:
		/**�Ự���ӶϿ�ʱ�Ĵ�����
	* @param	pSession	�Ͽ������ӻỰָ��
	* @param	nReasion	�Ͽ���ԭ��
	*/
		virtual void OnSessionDisconnected(CSession *pSession, int nReason);

	/* */
	private:
		///����Ӧ���������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
			///@return	�������ݰ��Ĵ�����
		virtual int HandlePackage(
						CFTDCPackage *pFTDCPackage,
						CFTDCSession *pSession);

		///�û���¼Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		///��Ӧ���������ϢӦ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspNetAreaTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnNetAreaTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��Ӧ���������Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��	
		void OnRspNetSubAreaTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnNetSubAreaTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��Ӧ������������ε�ַӦ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspNetSubAreaIPTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnNetSubAreaIPTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��Ӧ�豸������Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspDevManuTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnDevManuTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��Ӧ�豸���Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspDevTypeTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnDevTypeTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��Ӧ�豸�ͺ�Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspDevSerialTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnDevSerialTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��Ӧ�豸ͨ�Źؼ���commӦ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspNetCommTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnNetCommTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��Ӧ�豸��mibӦ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspMIBOIDTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnMIBOIDTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��Ӧͨ�õ�mibӦ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspGenMIBOIDTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnGenMIBOIDTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��Ӧ�����豸Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspNetDeviceTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnNetDeviceTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��Ӧ�豸���Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspChgNetDeviceTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnChgNetDeviceTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��Ӧ�����豸Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspNetInterfaceTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnNetIntefaceTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��Ӧģ����ϢӦ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspNetModuleTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnNetModuleTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��Ӧʱ����Դ�����
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspTimePolicyTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnTimePolicyTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		//�����������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspMonTaskTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnMonTaskTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��Ӧ�豸ͨ�Źؼ���commӦ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspMonitorTypeTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnMonitorTypeTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��Ӧ�豸��������ϸӦ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspQryNetMonitorTaskObjectSetTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnNetMonitorTaskObjectSetTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��Ӧ���ָ��Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspMonitorAttrTypeTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnMonitorAttrTypeTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��Ӧ�澯���ʽӦ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspNetEventExprTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnNetEventExprTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��ӦѲ������Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspLoopItemTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnLoopItemTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��ӦѲ������Ľ�����˹�������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspDeviceTaskTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnDeviceTaskTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��ӦѲ��������б�����
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspTaskCmdAttrListTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnTaskCmdAttrListTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��Ӧ�豸����Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspBaseLineTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnBaseLineTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��Ӧ��Ա��·��ϢӦ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspPartyLinkInfoTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnPartyLinkInfoTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///����ָ���Ӧ���豸id�б�
		void PrepareExprData(void);

		///��ӱ��ʽ��Ӧ���豸�б�
		void AddExprDeviceList(CFTDSysNetMonitorTaskInfoField &field);

		///ɾ�����ʽ��Ӧ���豸�б�
		void DelExprDeviceList(CFTDSysNetMonitorTaskInfoField &field);

		///	///��Ӧ�澯�¼�Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRtnWarningEventTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnReqQryWarningEventUpdate(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnReqQryWarningEventActiveChange(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnSyslogEventTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		//�ͻ��˿��ƶ��ſ���
		void OnReqQryNetRoomTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void AddWarningEvent(CFTDRtnWarningEventField &warningevent)
		{
			m_listWarningEvent.add(warningevent);
		}

		void AddSyslogEvent(CFTDRtnSyslogEventField &syslogevent)
		{
			m_listSyslogEvent.add(syslogevent);
		}

		void AddWarningEventActiveChange(
		CFTDRtnWarningActiveChangeField &warningeventac)
		{
			m_listWarningEventActiveChange.add(warningeventac);
		}

		void AddNetMonitorObjectTree(CFTDRtnNetAreaField &objecttree)
		{
			m_listNetMonitorObjectTree.add(objecttree);
		}

		void AddRtnNetRoom(CFTDRtnNetRoomField &netroom)
		{
			m_listRtnNetRoom.add(netroom);
		}

		void AddPartyLinkStatusInfo(
		CFTDRtnNetPartyLinkStatusInfoField	&statusinfo)
		{
			m_listPartyLinkStatus.add(statusinfo);
		}

		//����ָ��ָ����
		void ParseDeviceTaskResult(
				CFTDSysNetMonitorDeviceTaskField &info,
				string	&result);

	/* */
	public:
		//����ָ���ķָ������ַ�����ֳɶ����Ԫ
		static void splitStringBySeprator(
						string ori,
						string splitstr,
						vector<string> &result);

	/* */
	public:
		bool GetWarningEvent(CFTDRtnWarningEventField &warningevent)
		{
			return m_listWarningEvent.get(warningevent);
		}

		bool GetSyslogEvent(CFTDRtnSyslogEventField &syslogevent)
		{
			return m_listSyslogEvent.get(syslogevent);
		}

		bool GetWarningEventActiveChange(
		CFTDRtnWarningActiveChangeField &warningeventac)
		{
			return m_listWarningEventActiveChange.get(warningeventac);
		}

		bool GetPartyLinkStatusInfo(
		CFTDRtnNetPartyLinkStatusInfoField	&statusinfo)
		{
			return m_listPartyLinkStatus.get(statusinfo);
		}

		bool GetNetMonitorObjectTree(CFTDRtnNetAreaField &objecttree)
		{
			return m_listNetMonitorObjectTree.get(objecttree);
		}

		bool GetRtnNetRoom(CFTDRtnNetRoomField &netroom)
		{
			return m_listRtnNetRoom.get(netroom);
		}

		MAP_TASK_REGULAR_PARAM GetTaskRegularParamList(void)
		{
			return map_TaskRegularParams;
		}

		MAP_INSTR_INFO GetTaskInstrInfo(void)
		{
			return map_InstrInfo;
		}

		int GetDeviceManufacoryIdAndIP(
				string objectid,
				int &manuid,
				string &deviceip,
				string &deviceserial);
		CFTDCSession *GetSession(void)
		{
			return m_pSession;
		}

		void GetDeviceName(string objectid, string &devname);

		int test_task(void);

		NET_DEVICE_MAP &GetDeviceMap(void)
		{
			return m_devs;
		}

		NET_BASELINE_MAP &GetBaseLineMap(void)
		{
			return m_baselines;
		}

		//���ݸ澯�¼���ȡ��Ա��·��
		void GetPartyLinkMemberName(
				CFTDRtnWarningEventField &event,
				string	&membername);

	/* */
	private:
		///�������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;

		//��������Ϣ
		NET_AREA_MAP m_sysNets;
		NET_SUB_AREA_MAP m_sysNetSubs;
		NET_SUB_AREA_IP_MAP m_sysNetSubIPs;

		//CGetDeviceInfoThread *m_pinfoThread;
		//��ض������
		MONITOR_TYPE_MAP m_montypes;

		//�豸������Ϣ����cisco F5��
		DEV_MANUFACTORY_MAP m_devmanus;

		//�豸������Ϣ����·��������������
		DEV_TYPE_MAP m_devtypes;

		//�豸�ͺ���Ϣ����cisco3600��
		DEV_SERIAL_MAP m_devserials;

		//����oid��Ϣ
		CON_OID_CONTAIN_MAP m_oids;

		//�����豸��Ϣ<id,netdev>
		NET_DEVICE_MAP m_devs;

		//�豸ip��Ϣ
		NET_DEV_OBJID_MAP m_dev_objids;

		//�ӿ���Ϣ
		NET_INTERFACE_MAP m_ifs;

		//ģ����Ϣ
		NET_MODULE_MAP m_mods;

		//ʱ�������Ϣ
		TIME_POLICY_MAP m_tpolicys;

		//�������
		MONITOR_TASK_MAP m_montasks;

		//���ָ��
		MONITOR_ATTR_MAP m_attrs;

		//�澯���ʽ
		WARNING_EXPRESSION m_warnexprs;

		//������Ϣ
		NET_BASELINE_MAP m_baselines;

		CFTDCSession *m_pSession;

		///��FIBCONFSERVER���ӳɹ��ı�־λ
		bool m_Flag;

		///���͸�front�ĸ澯�¼�����
		TemplateMutexCatch<CFTDRtnWarningEventField> m_listWarningEvent;

		///���͸�front��syslog����
		TemplateMutexCatch<CFTDRtnSyslogEventField> m_listSyslogEvent;

		///���͸�front�ĸ澯�¼�activechange����
		TemplateMutexCatch<CFTDRtnWarningActiveChangeField>
			m_listWarningEventActiveChange;

		///���͸�front�ĸ澯�����¼�netroom����
		TemplateMutexCatch<CFTDRtnNetRoomField> m_listRtnNetRoom;

		///���͸�front��query����·״̬ͳ�ƶ���
		TemplateMutexCatch<CFTDRtnNetPartyLinkStatusInfoField>
			m_listPartyLinkStatus;

		///���͸�front��������ϵͳ������(�������е�Field)
		TemplateMutexCatch<CFTDRtnNetAreaField> m_listNetMonitorObjectTree;

		//δ��ȫ���豸�����,���ڷְ�����¼�¼�м�����
		//key:task_id, value:devicetask list
		map<int, vector<CFTDSysNetMonitorDeviceTaskField> > m_mapDeviceTask;

	/* */
	public:
		//����comm��Ϣ key=ip,value=comm;
		COMMUNITY_MAP m_comms;

		//Ѳ������
		LOOP_ITEM_MAP m_loopitem;

		//Ѳ��ָ��
		COMMAND_MAP m_commands;

		//Ѳ�춯����
		ACTION_GROUP_MAP m_actions;

		//Ѳ���豸��
		DEVICE_GROUP_MAP m_groupdev;

		//��¼ÿ��̽���req������̽����������� key=reqid, value=CFTDReqQryNetDeviceDetectFieldʵ��
		map<DWORD, CFTDReqQryNetDeviceDetectField> m_detectids;

		///���ʽ�������豸�б�
		EXPR_DEVICE_LIST m_mExprTaskList;

		//ָ���Ӧ���豸�б�
		map<string, map<string, int> > m_attr_devs;

		///�豸��������ϸ
		MAP_DEVICEGROUPLIST map_DeviceGroupList;

		//�������������������
		MAP_TASK_REGULAR_PARAM map_TaskRegularParams;

		//����������ص�ָ���б�
		MAP_INSTR_INFO map_InstrInfo;

		//��Ա��·��Ϣ
		MAP_PARTYLINK_INFO m_partylinkinfo;
};
#endif
