/////////////////////////////////////////////////////////////////////////
///@system	������ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CGetDeviceInfo.h
///@brief	������CGetDeviceInfoʹ�õ���
///@history
///20100920	�ܽ���		�������ļ�
#ifndef REF_CSYNCONNECTOR_H
#define REF_CSYNCONNECTOR_H

#include "public.h"
#include "CachedFlow.h"
#include "CachedFileFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "CDate.h"
#include "systools.h"
#include "CGetDeviceInfo.h"
#include "CAsyncGetThread.h"
#include "CTaskManager.h"

//�ڲ��궨��
#ifndef uint32
#define uint32	unsigned long
#endif
#define PINGIPNUMPERTHREAD		20
#define MAX_DETECT_THREAD_NUM	255

#define CHK_RSP_PKG															 \
		(x, field, datamap)													 \
			CNamedFieldIterator	 itor = pFTDCPackage->GetNamedFieldIterator( \
					&(CFTDRspQry##x##Field::m_Describe));					 \
	while (!itor.IsEnd())													 \
	{																		 \
		itor.Retrieve(&field);												 \
		CFTDSys##x##Field fielddata;										 \
		CopySys##x##Entity(&fielddata, &field);								 \
		datamap[fielddata.ID.getValue()] = fielddata;						 \
		itor.Next();														 \
	}

#define SYNCONN_PKGSEND(Topic, field)								   \
	m_pkgSend.PreparePackage(										   \
			Topic,													   \
			FTDC_CHAIN_LAST,										   \
			FTD_VERSION);											   \
	if (m_pkgSend.Length() + sizeof(field) > FTDC_PACKAGE_MAX_SIZE)	   \
	{																   \
		m_pkgSend.SetChain(FTDC_CHAIN_CONTINUE);					   \
		if (m_pSession != NULL)										   \
		{															   \
			m_pSession->SendRequestPackage(&m_pkgSend);				   \
		}															   \
																\
		m_pkgSend.PreparePackage(Topic, FTDC_CHAIN_LAST, FTD_VERSION); \
	}																   \
																	\
	FTDC_ADD_FIELD(&m_pkgSend, &field);								   \
	if (m_pSession != NULL)											   \
	{																   \
		m_pSession->SendRequestPackage(&m_pkgSend);					   \
	}

#define RTN_QRY_DEL_FIELD_DATA(field, val, key, datamap, datamapiterator) \
	switch (field.OperationType.getValue())								  \
	{																	  \
		case 1:															  \
			break;														  \
		case 3:															  \
			if (field.ID.getValue() == -1)								  \
			{															  \
				datamap.clear();										  \
			}															  \
			else														  \
			{															  \
				datamapiterator = datamap.find(key);					  \
				if (datamapiterator != datamap.end())					  \
				{														  \
					datamap.erase(datamapiterator);						  \
				}														  \
			}															  \
															   \
			break;														  \
	}																	  \
																	   \
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

//�豸ͨ��oid���� @string key=oid����, @ value=oid����
typedef std::map<string, SInfoOID>	GEN_OID_MAP;
typedef GEN_OID_MAP::iterator GEN_OID_MAP_ITERATOR;

//key��ʹ�õ����ӷ���
#define CONSYM	"@#$$";

//���������·��ĳ���oid�ṹ������Ӧ������
//@string ���serialnameΪ�գ�key=OidEname+CONSYM+ManuEname,
//		  ����key=OidEname+CONSYM+ManuEname+CONSYM+SerialEname
//@CFTDSysNetOIDField value=ʵ��
typedef std::map<string, CFTDSysNetOIDField> CON_OID_CONTAIN_MAP;
typedef CON_OID_CONTAIN_MAP::iterator CON_OID_CONTAIN_MAP_ITERATOR;

//�����豸���� @int key=id,�豸ID������, @CFTDSysNetDeviceField value=CFTDSysNetDeviceFieldʵ��
typedef std::map<int, CFTDSysNetDeviceField> NET_DEVICE_MAP;
typedef NET_DEVICE_MAP::iterator NET_DEVICE_MAP_ITERATOR;

// �����豸ip��ַ���� @string key=ip,�豸��ip��ַ,@int value=id �豸�ı��
typedef std::map<string, int> NET_IP_MAP;
typedef NET_IP_MAP::iterator NET_IP_MAP_ITERATOR;

//����ӿ�����
//@int key = id,�ӿڶ�Ӧ��ID������(ȫ��), @CFTDSysNetInterfaceField value=CFTDSysNetInterfaceFieldʵ��
//���Խӿڶ�Ӧ��objectIDΪkey����Ҫ�ǿ��ǵ��豸��ojbectID�仯���½ӿ��������ݵı仯
typedef std::map<int, CFTDSysNetInterfaceField> NET_INTERFACE_MAP;
typedef NET_INTERFACE_MAP::iterator NET_INTERFACE_MAP_ITERATOR;

//�豸ģ������
//@int key = int,ģ��id, @CFTDSysNetInterfaceField value=CFTDSysNetInterfaceFieldʵ��
typedef std::map<int, CFTDSysNetModuleField> NET_MODULE_MAP;
typedef NET_MODULE_MAP::iterator NET_MODULE_MAP_ITERATOR;

//ʱ����Խṹ�������� @int key=id,ʱ����Ե�ID������, @CFTDSysNetTimePolicyField value=CFTDSysNetTimePolicyFieldʵ��
typedef std::map<int, CFTDSysNetTimePolicyField> TIME_POLICY_MAP;
typedef TIME_POLICY_MAP::iterator TIME_POLICY_MAP_ITERATOR;

//����id���֣���������ֱ���·���id��ǰ׺"10"��ͷ����Ѳ������ָ�ɣ�id��ǰ׺"11"��ͷ�����ࡣ
//����������� key=id, value=pair<CFTDSysNetGatherTaskField,int>ʵ��,int��ʶ����״̬��0,1,2�ֱ������������ɷ�����Ч
typedef std::map<int, pair<CFTDSysNetGatherTaskField, int> > MONITOR_TASK_MAP;
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

//�ӿ���Ԫmap������key=pair<int, string>����int��ʾ�ӿ������豸��id��string��ʾ�ӿ�����
//value=�ӿ������豸�Ľӿ����� �磺< <1,GigabitEthernet0/12>, 10112>������������NET_INTERFACE_MAP
//���������豸objectid�ĸı䣬�����µĽӿڵ�objectid�ı仯
typedef std::map<pair<int, string> , string> TRIP_INTERFACE_MAP;

//��Ա��·��Ϣ��
//key = id; value = CFTDSysNetPartyLinkInfoFieldʵ��
//key = ip; value = list<id>
typedef std::map<int, CFTDSysNetPartyLinkInfoField> PartyLink_MAP;	//
typedef PartyLink_MAP::iterator PartyLink_MAP_ITERATOR;
typedef std::map<string, list<int> > IP_PartyLink_MAP;
typedef IP_PartyLink_MAP::iterator	IP_PartyLink_MAP_ITERATOR;

class CDetectWorkThread;
class CSynConnector :
	public CSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///���캯��	
			///@param	pReactor	CReactor����ָ��
		CSynConnector(CReactor *pReactor);

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

		///�������������ɫ��Ӧ����
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspServiceRole(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

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

		///��Ӧ�����豸�ӿ�Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspNetInterfaceTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnNetIntefaceTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��Ӧ�����豸ģ��Ӧ������
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

		///��ӦѲ������Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqLoopItemTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRspLoopItemTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnLoopItemTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��Ӧ����ִ�д���Ӧ������
		void OnRspTaskRunTimeTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��Ӧָ��Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspCommandTypeTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnCommandTypeTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��Ӧ������Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspActionGroupTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnActionGroupTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��Ӧ�豸������Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspDeviceGroupTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnDeviceGroupTopic(
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

		///��Ӧ����̽������Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryNetDeviceDetectTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��Ӧ����ָ��Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspActionAttrTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnActionAttrTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��Ӧ�豸����Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspDevTaskTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnDevTaskTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��Ӧָ����ϢӦ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspInstrTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnInstrTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��Ӧ��Ա��·��ϢӦ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspPartLinkTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnPartLinkTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		//
		void OnRspPartLinkInfoStatus(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *Session);

		///���߱ȶ�����Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspBaseLineTaskTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnBaseLineTaskTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		//��������������Ϣ
		void SendRequestNetAreaQry(void);
		void SendRequestNetSubAreaQry(void);
		void SendRequestNetSubAreaIPQry(void);

		//�����豸������Ϣ
		void SendRequestDevManuQry(void);

		//�����豸�ͺ���Ϣ
		void SendRequestDevSerialQry(void);

		//�����豸������Ϣ
		void SendRequestDevTypeQry(void);

		//���������豸��comm��Ϣ
		void SendRequestNetCommQry(void);

		//�����豸mib��Ϣ
		void SendRequestMIBOIDQry(void);

		//��ѯ����ӿ�
		void RequestQry(DWORD msgID);

	/* */
	public:
		//��������״̬
		void SendTaskStatus(int task_id, int task_status, int delay_gap);

		//����������ִ�д���
		void SendTaskRunTimes(int task_id, int runtimes);

	/* */
	public:
		///���������������ƻ�ȡ��������id
			///@param   net			������������
			///return   int			��������id
		int GetNetSubAreaIDByNetArea(int centerid, const char *net);
		int GetNetSubAreaIPIDByNetSubArea(
				int netid,
				const char *ip,
				const char *mask);

		int GetDevManuIDByManuName(const char *name);
		int GetDevTypeIDByTypeName(const char *name);
		int GetMonitorTypeIDByName(const char *name);

		///����̽����ָ��
		void DispatchMonTask(void);

		///����Ѳ������
		void DispatchLoopTask(void);

		///����̽����Ӧ����
			///@param	reqid	�����Ӧ��id
			///@param	type	���ص���Ϣ���
			///@param	value	���ص���Ϣ��Я����value
		void RspQryNetDeviceDetectTopic(
				DWORD reqid,
				int type = 0,
				int value = 0);

		///���������ķ���CFTDRtnObjectAttrField��Ϣ
			///@param	field		�ֶ�����
		void SendCFTDRtnObjectAttrField(CFTDRtnObjectAttrField &field);

		///���������ķ�������cdp��Ϣ
			///@param	hosts		����cdp��Ϣ�������豸��
		void SendCDPInfo(std::vector<SInfoHost> &hosts);

		///���������ķ������豸��Ϣ
			///@param	hosts		�����豸��
		void SendHostInfo(std::vector<SInfoHost> &hosts, DWORD req);

		///���������ķ��ͽӿ���Ϣ
			///@param	hosts		�����豸��
		void SendInterfaceInfo(std::vector<SInfoHost> &hosts);

		///���������ķ���ģ����Ϣ
			///@param	hosts		�����豸��
		void SendModuleInfo(std::vector<SInfoHost> &hosts);

		//����FTDC_CHAIN_LAST��Ϣ
		void Send_FTDC_CHAIN_LAST_Msg(DWORD msg)
		{
			m_pkgSend.PreparePackage(msg, FTDC_CHAIN_LAST, FTD_VERSION);
			if (m_pSession != NULL)
			{
				m_pSession->SendRequestPackage(&m_pkgSend);
			}
		}

		///����objid��ȡ�豸����
			///@param	objid		�豸��objectid
		CFTDSysNetDeviceField *GetDeviceByObjID(const char *objid);

		///����objid��ȡ�ӿڶ���
			///@param	objid		�豸��objectid
		CFTDSysNetInterfaceField *GetInterfaceByObjID(const char *objid);

		///����objid��ȡ�ӿڶ���
			///@param	objid		�豸��objectid
		CFTDSysNetModuleField *GetModuleByObjID(const char *objid);

		///������������id��ȡ������������
			///@param   net			������������
			///@param   center		������������
		void GetNetAreaInfoByNetSubAreaID(int id, string &net, string &center);

		///�����豸ip��ַ��ȡ�豸����
			///@param   ip			�豸ip��ַ
			///@param   id_type		�豸����id	
			///@param   id_manu		�豸����id
		void GetNetDeviceInfoIDByIP(
		const char	*ip,
		int &id_type,
		int &id_manu,
		string	&objID,
		string* strDeviceType = NULL)
		{
			//��ü���ipȡֵ�ĺϷ���
			if (m_dev_ips.find(ip) != m_dev_ips.end()
			&&	m_devs.find(m_dev_ips[ip]) != m_devs.end())
			{
				id_type = m_devs[m_dev_ips[ip]].CATEGORY_ID.getValue();
				id_manu = m_devs[m_dev_ips[ip]].MANUFACTORY_ID.getValue();
				objID = m_devs[m_dev_ips[ip]].ObjectID.getValue();
				if (strDeviceType) *strDeviceType = m_devs[m_dev_ips[ip]].DEVICETYPE.getValue();
			}
			else
			{
				id_type = 0;
				id_manu = 0;
				objID = "";
				printf(
					"warning: there is no validity ip[%s] information.\n",
					ip);
			}
		}

		//���ݴ�������ȡ������Ӧ��ID��
		int GetNetAreaIDByName(const char *center)
		{
			for (NET_AREA_MAP_ITERATOR it = m_sysNets.begin();
				 it != m_sysNets.end();
				 it++)
			{
				if (strcasecmp(center, it->second.EName.getValue()) == 0)
				{
					return it->first;
				}
			}

			return -1;
		}

		//����id��ȡ��������
		void GetManuNameByID(int id, string &manu)
		{
			for (DEV_MANUFACTORY_MAP_ITERATOR it = m_devmanus.begin();
				 it != m_devmanus.end();
				 it++)
			{
				if (id == it->second.ID.getValue())
				{
					manu = it->first;
					break;
				}
			}
		}

		//����ip��ȡ�豸����
		const char *GetDevNameByIP(const char *ip)
		{
			if (ip == NULL)
			{
				return NULL;
			}

			NET_IP_MAP_ITERATOR it;
			if ((it = m_dev_ips.find(ip)) != m_dev_ips.end())
			{
				if (m_devs.find(it->second) != m_devs.end())
				{
					return m_devs[it->second].NAME.getValue();
				}
			}

			return NULL;
		}

		/************************************************************************/
		/* ���Ӽ��ָ������                                      */

		/************************************************************************/
		void AddMonTask(
		int id,
		char *attr,
		char *devobjID,
		int policyID,
		int rtnType = 0)
		{
			CFTDSysNetGatherTaskField task;

			task.AttrType = attr;
			task.ObjectID = devobjID;
			task.PolicyTypeID = policyID;
			task.DataType = rtnType;

			m_montasks[id] = make_pair(task, true);
		}

		/************************************************************************/
		/* ���������ɷ���־                                       */

		/************************************************************************/
		bool SetMonTaskFlag(int id, bool flag)
		{
			if (0 == id)
			{
				for (MONITOR_TASK_MAP_ITERATOR it = m_montasks.begin();
					 it != m_montasks.end();
					 it++)
				{
					it->second.second = true;
				}

				return true;
			}

			if (m_montasks.find(id) != m_montasks.end())
			{
				m_montasks[id].second = flag;
				return true;
			}

			return false;
		}

		/************************************************************************/
		/* �����߳������ַ���̸߳�������                                       */

		/************************************************************************/
		void setThreadPoint(CAyncGetThread **pThread, int nThreadNum)
		{
			m_nThreadNum = nThreadNum;
			m_pThread = pThread;
		}

		/************************************************************************/
		/* �����豸�����䵽�߳�id��-1��ʾû�б����䵽�߳�                        */

		/************************************************************************/
		int getDisTaskThreadIDByIP(const char *ip)
		{
			if (m_nThreadNum == 0 || m_pThread == NULL)
			{
				return -1;
			}

			for (int i = 0; i < m_nThreadNum; i++)
			{
				if (m_pThread[i]->isMonitorDevTask(ip))
				{
					return i;
				}
			}

			return -1;
		}

		/************************************************************************/
		/* ��ȡsynConnectorʵ���ľ��                                       */

		/************************************************************************/
		static CSynConnector *GetInstancePoint(void)
		{
			if (pInstance == NULL)
			{
				printf(
					"Warnning: the instance of CSynConnector doesn't initilize yet!\n");
			}

			return pInstance;
		}

		void SetInstancePoint(CSynConnector *inst)
		{
			if (inst != NULL)
			{
				pInstance = inst;
			}
			else
			{
				printf(
					"warning: set instance point fail because of the point is NULL .\n");
			}
		}

		NET_DEVICE_MAP &GetDevMap(void)
		{
			return m_devs;
		}

		NET_IP_MAP GetDeviceIP(void)
		{
			return m_dev_ips;
		}

		void GetDeviceIPList(list<string> &ip_list)
		{
		}

		const char * GetOIDValue( const char * oidname, int manuID)
		{
			ASSERT( oidname != NULL );
			string key = oidname;
			if( m_IDmanu.find( manuID )!= m_IDmanu.end())
			{
				key += CONSYM;
				key.append( m_IDmanu[manuID]);
			}
			if( m_oids.find( key ) != m_oids.end() )
			{
				return m_oids[key].OID.getValue();
			}
			else
			{
				return NULL;
			}
		}

		void GetIfsName(string ipaddress, string ifs_index, string& name)
		{
			if( m_dev_ips.find( ipaddress )!= m_dev_ips.end() )
			{
				pair<int,string> key(m_dev_ips[ipaddress],ifs_index);
				if( m_dev_ifs.find( key ) != m_dev_ifs.end() )
				{
					int ifs_key = m_dev_ifs[ key ];
					if( m_ifs.find( ifs_key ) != m_ifs.end() )
					{
						name = m_ifs[ ifs_key ].EName.getValue();
					}
				}
			}
		}

		void SetTaskManagerThread( CTaskManagerThread	* pManager )
		{
			m_pTaskManagerThread = pManager;
		}

		//�ж�ip��ַ�Ƿ��ڵ�ǰ̽�ⷶΧ
		bool IsBingTetect(const char *ip)
		{
			if (m_curdetrang[0] == '\0' || ip == NULL)
			{
				return false;
			}

			char first_ip[20] = "\0";
			int num = 0;
			if (strchr(m_curdetrang, '/') != NULL)
			{
				sscanf(m_curdetrang, "%[^/]/%d", first_ip, &num);

				unsigned long u_first_ip = htonl(inet_addr(first_ip));
				unsigned long u_ip = htonl(inet_addr(ip));
				if (u_ip >= u_first_ip && u_ip < u_first_ip + num)
				{
					return true;
				}
			}

			return false;
		}

	/* */
	private:
		void RunTask(CSnmpTaskInfo task);

	/* */
	private:
		static CSynConnector *pInstance;

		///�������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;

		//��������Ϣ
		NET_AREA_MAP m_sysNets;
		NET_SUB_AREA_MAP m_sysNetSubs;
		NET_SUB_AREA_IP_MAP m_sysNetSubIPs;

		//��ض������
		MONITOR_TYPE_MAP m_montypes;

		//�豸������Ϣ����cisco F5��
		DEV_MANUFACTORY_MAP m_devmanus;
		map<int,string>     m_IDmanu;

		//�豸������Ϣ����·��������������
		DEV_TYPE_MAP m_devtypes;

		//�豸�ͺ���Ϣ����cisco3600��
		DEV_SERIAL_MAP m_devserials;

		//�����豸��Ϣ<id,netdev>
		NET_DEVICE_MAP m_devs;

		//�豸ip��Ϣ
		NET_IP_MAP m_dev_ips;

		//�ӿ���Ϣ
		NET_INTERFACE_MAP m_ifs;

		// < pair<deviceID, ifs_index>, ifs_ID
		map< pair<int,string>,int >  m_dev_ifs;

		//ģ����Ϣ
		NET_MODULE_MAP m_mods;

		//TRIP_INTERFACE_MAP m_ifstrip;

		//ʱ�������Ϣ
		TIME_POLICY_MAP m_tpolicys;

		//�������
		MONITOR_TASK_MAP m_montasks;

		CFTDCSession *m_pSession;

		///��FIBCONFSERVER���ӳɹ��ı�־λ
		bool m_Flag;

		///��ȡ������Ϣ�ı�־λ
		bool m_hashconfig;

		///��ʶ����̽��Ľ���
		bool m_detecting;

		///�߳�����ָ��
		CAyncGetThread **m_pThread;

		///�߳���������
		int m_nThreadNum;

		///��ǰ����������̱߳��
		int m_nCurentDisThreadID;

		CTaskManagerThread	*m_pTaskManagerThread;

	/* */
	public:
		//����comm��Ϣ key=ip,value=comm;
		COMMUNITY_MAP m_comms;

		//�豸ͨ��oid
		GEN_OID_MAP m_genoids;

		//����oid��Ϣ
		CON_OID_CONTAIN_MAP m_oids;

		//Ѳ������
		LOOP_ITEM_MAP m_loopitem;

		//Ѳ��ָ��
		COMMAND_MAP m_commands;

		//Ѳ�춯����
		ACTION_GROUP_MAP m_actions;

		//Ѳ���豸��
		DEVICE_GROUP_MAP m_groupdev;

		//��Ա������·��Ϣ
		PartyLink_MAP m_partylinks;
		IP_PartyLink_MAP m_devpartylinks;

		//��¼ÿ��̽���req������̽����������� key=reqid, value=CFTDReqQryNetDeviceDetectFieldʵ��
		map<DWORD, CFTDReqQryNetDeviceDetectField> m_detectids;
		TemplateMutexCatch<DWORD> m_listreq;

		//̽���������߳�
		CDetectWorkThread *m_pdetthread;

		//��ǰ̽�ⷶΧ ��ʽ " ��ʼip��ַ/mask" ��"172.1.128.1/32"
		char m_curdetrang[32];
};

// Detect�豸�Ĺ����߳�
class CDetectWorkThread :
	public CThread
{
	/* */
	public:

		///���캯��
		CDetectWorkThread(CSynConnector *pSys, DWORD reqid = 0)
		{
			m_pSys = pSys;
			m_pinfoThread = new CGetDeviceInfoThread();
		}

		///��������
		~CDetectWorkThread(void)
		{
			if (m_pinfoThread != NULL)
			{
				delete m_pinfoThread;
				m_pinfoThread = NULL;
			}

			ExitThread();
		}

		/**�麯�����������һЩʵ��������
	* @return true:�����ɹ� false:����ʧ��
	*/
		virtual bool InitInstance(void);

		/**�麯�����������ʵ��
	*/
		virtual void ExitInstance(void);

		/**�߳̿�ʼ���У����麯�����������̳�ʵ��
	*/
		virtual void Run(void);

	/* */
	private:
		///���߳�ʵ��̽���豸
		void MultiThreadDoDetect(DWORD reqid);

		void DoSnmpDevice(list<string> &iplist, DWORD reqid);

	/* */
	public:
		CSynConnector *m_pSys;
		CGetDeviceInfoThread *m_pinfoThread;

	/* */
	private:
		CMutex m_detLock;
};

class CWorkThread :
	public CThread
{
	/* */
	public:

		///���캯��
		CWorkThread(int threadID = 0)
		{
			m_threadID = threadID;
			m_pinfoThread = new CGetDeviceInfoThread();
		}

		///��������
		~CWorkThread(void)
		{
			if (m_pinfoThread != NULL)
			{
				delete m_pinfoThread;
				m_pinfoThread = NULL;
			}

			ExitThread();
		}

		/**�麯�����������һЩʵ��������
	* @return true:�����ɹ� false:����ʧ��
	*/
		virtual bool InitInstance(void);

		/**�麯�����������ʵ��
	*/
		virtual void ExitInstance(void);

		/**�߳̿�ʼ���У����麯�����������̳�ʵ��
	*/
		virtual void Run(void);

		void setParas(
		uint32 start,
		int ipnums,
		CSynConnector *pSys = NULL,
		DWORD reqid = 0)
		{
			m_start = start;
			m_ipnums = ipnums;
			m_reqid = reqid;
			m_pSys = pSys;
		}

	/* */
	private:
		///pingָ�����ε��豸, ������ip+maskȷ��
			///@param   hosts   ������,pingͨ��ip��ַ��
		void PingDevice(
				const char	*ip,
				const char	*mask,
				list<string> &hosts,
				int bound = 0);

		///pingָ�����ε��豸,������ip��ʼ��ַ+ip����ȷ��
		void PingDevice(void);

		///ͨ��snmp�ɼ��豸�����豸�������Ϣ
			///@param	iplist	�豸��ip��ַ��
			///@param	mask	�豸�����ڵ����绮���� ������.����������"PuDian.OA"
			///@param   hosts   ������,�豸��
		void DoSnmpDevice(void);

	/* */
	public:
		CSynConnector *m_pSys;
		CGetDeviceInfoThread *m_pinfoThread;
		std::list<string> m_iplist;

		//ִ��̽�������id��
		DWORD m_reqid;

		//̽����ʼip����ip��ַ����
		uint32 m_start;
		int m_ipnums;

		//̽������б�ʶ�̵߳�id����ͬ��ϵͳ������߳�id
		int m_threadID;
};

class CCheckConnThread :
	public CThread
{
	/* */
	public:
		CCheckConnThread(void)
		{
		}

		~CCheckConnThread(void)
		{
			ExitThread();
		}

		/**�麯�����������һЩʵ��������
	* @return true:�����ɹ� false:����ʧ��
	*/
		virtual bool InitInstance(void);

		/**�麯�����������ʵ��
	*/
		virtual void ExitInstance(void);

		/**�߳̿�ʼ���У����麯�����������̳�ʵ��
	*/
		virtual void Run(void);
};
#endif
