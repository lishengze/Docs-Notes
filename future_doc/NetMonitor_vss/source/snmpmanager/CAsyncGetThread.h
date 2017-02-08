/////////////////////////////////////////////////////////////////////////
///@system	������ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CAyncGetThread.h
///@brief	������CAyncGetThreadʹ�õ���
///@history
///20100920	�ܽ���		�������ļ�
#ifndef REF_CASUNCGETTHREAD_H
#define REF_CASUNCGETTHREAD_H

#include "FtdPackageDesc.h"
#include "systools.h"
#include "CAsyncGetDevices.h"
#include "CGetDeviceInfo.h"

class CDevice
{
	/* */
	public:

		///���캯��
		CDevice(void)
		{
			m_sHostName = "";
			m_sDevIp = "";
			m_sCommunity = "";
			m_sOidName = "";
			m_sAttrType = "";
			m_sSeps = "";
			m_netName = "";
			m_centerName = "";
			m_sAttendValue = "", m_objID = "", m_type = 0;
		}

		///���캯��
			///@param	pDevIp	�����豸��IP��ַ
			///@param	pCommunity	snmpͨ�Źؼ���
			///@param	pOidName	Oid����
			///@param	pSeps	�ɼ�ʱ���
		CDevice(
		const char	*pHostName,
		const char	*pDevIp,
		const char	*pCommunity,
		const char	*pNetName,
		const char	*pCenterName,
		const char	*pOidName,
		const char	*pAttrType,
		const char	*pSeps,
		const char	*pAttendValue,
		const char	*pObjectID)
		{
			m_sHostName = pHostName;
			m_sOidName = pOidName;
			m_sDevIp = pDevIp;
			m_sCommunity = pCommunity;
			m_netName = pNetName;
			m_centerName = pCenterName;
			m_sAttrType = pAttrType;
			m_sSeps = pSeps;
			m_sAttendValue = pAttendValue;
			m_objID = pObjectID;
		}

		//CDevice(const char *pHostName, const char *pDevIp, const char *pCommunity, const char *pOidName,
		//	const char *pAttrType, const char *pSeps, const char *pAttendValue,const char *pObjectID)
		//{
		//	CDevice(pHostName,pDevIp,pCommunity,"","",pOidName,pAttrType,pSeps,pAttendValue);
		//	m_objID = pObjectID;

		//}
			///�������캯��
		CDevice(const CDevice &ob)
		{
			m_sHostName = ob.m_sHostName;
			m_sCommunity = ob.m_sCommunity;
			m_sDevIp = ob.m_sDevIp;
			m_sOidName = ob.m_sOidName;
			m_sAttrType = ob.m_sAttrType;
			m_sSeps = ob.m_sSeps;
			m_netName = ob.m_netName;
			m_centerName = ob.m_centerName;
			m_sAttendValue = ob.m_sAttendValue;
			m_objID = ob.m_objID;
			m_type = ob.m_type;
		}

		///��ֵ
		void operator=(const CDevice &ob)
		{
			m_sHostName = ob.m_sHostName;
			m_sCommunity = ob.m_sCommunity;
			m_sDevIp = ob.m_sDevIp;
			m_sOidName = ob.m_sOidName;
			m_sAttrType = ob.m_sAttrType;
			m_sSeps = ob.m_sSeps;
			m_netName = ob.m_netName;
			m_sAttendValue = ob.m_sAttendValue;
			m_centerName = ob.m_centerName;
			m_objID = ob.m_objID;
			m_type = ob.m_type;
		}

		void setTaskType(int type)
		{
			m_type = type;
		}

		void setObjectID(const char *objid)
		{
			m_objID = string(objid);
		}

	/* */
	public:
		string	m_sHostName;

		///�豸��IP��ַ
		string	m_sDevIp;

		///ͨѶ��
		string	m_sCommunity;

		///OID
		string	m_sOidName;

		///OID��Ӧ������
		string	m_sAttrType;

		///ʱ�����Ƶ��
		string	m_sSeps;

		///objID����ɲ���
		string	m_netName;
		string	m_centerName;

		///OID ��Ҫ���ӵ�ObjectID�Ĳ����ֶ�
		string	m_sAttendValue;

		////objID
		string	m_objID;

		///��������
		int m_type;

	/* */
	protected:
	/* */
	private:
};

class CAyncGetThread :
	public CThread
{
	/* */
	public:

		///���캯��
			///@param	nThreadNum	�������̱߳��
			///@param	pMibsPath	Mib�ļ�����Ŀ¼
		CAyncGetThread(int nThreadNum, const char *pMibsPath) :
		m_cAsyncIns(nThreadNum, pMibsPath)
		{
			m_nThreadNum = nThreadNum;

			m_nTimeZoneSec = getTimeZoneOffset();
			it_data = datas.begin();
		}

		///��������
		~CAyncGetThread(void)
		{
			printf("GetThread id %d run end\n", m_nThreadNum);
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
	public:
		///��������������߳����ɵ����ݷ��ͳ�ȥ
		void GetSpi(void);

		///���ڻ�ȡm_cAsyncInsʵ������
		CAsyncGetDevices *GetAsyncIns(void)
		{
			return &m_cAsyncIns;
		}

		///���ӱ����豸OID���̺߳���
			///@param	pDevIp	�����豸��IP��ַ
			///@param	pCommunity	snmpͨ�Źؼ���
			///@param	pOidName	Oid����
			///@param	pAttrName	Oid��Ӧ��ָ������
			///@param	pSeps	����Ƶ��,�� "08:00:00-12:00:00.60,12:00:00-23:00:00.5"
		void addMonDevice(
		const char	*pHostName,
		const char	*pDevIp,
		const char	*pCommunity,
		const char	*pNetName,
		const char	*pCenterName,
		const char	*pOidName,
		const char	*pAttrType,
		const char	*pSeps,
		const char	*pAttendValue = "")
		{
			m_listDevice.add(
					CDevice(
						pHostName,
						pDevIp,
						pCommunity,
						pNetName,
						pCenterName,
						pOidName,
						pAttrType,
						pSeps,
						pAttendValue,
						NULL));
		}

		///���ӱ����豸OID���̺߳���
			///@param	phost	�����豸ָ��
			///@param	pOidName	Oid����
			///@param	pAttrName	Oid��Ӧ��ָ������
			///@param	pSeps	����Ƶ��,�� "08:00:00-12:00:00.60,12:00:00-23:00:00.5"
			///@param	pAttendValue	ָ�긽��ֵ
		void addMonDevice(
		const CFTDSysNetDeviceField *phost,
		const char	*pOidName,
		const char	*pAttrType,
		const char	*pPolicySeps,
		int taskType,
		const char	*pAttendValue = "",
		int  oidmeans = 0)
		{
			m_cAsyncIns.addMonDevice(
					phost,
					pOidName,
					pAttrType,
					pPolicySeps,
					taskType,
					pAttendValue,
					oidmeans);
		}

		void addMonDeviceNew(
		const char	*pHostName,
		const char	*pDevIp,
		const char	*pCommunity,
		const char	*pObjectID,
		const char	*pOidName,
		const char	*pAttrType,
		const char	*pPolicySeps,
		int taskType,
		const char	*pAttendValue = "")
		{
			CDevice c_dev = CDevice(
					pHostName,
					pDevIp,
					pCommunity,
					"",
					"",
					pOidName,
					pAttrType,
					pPolicySeps,
					pAttendValue,
					pObjectID);
			c_dev.m_type = taskType;
			m_listDevice.add(c_dev);
		}

		///��ȡ�ɼ����ú���
		void getMonDevice(void)
		{
			CDevice cDeviceInfo;
			while (m_listDevice.get(cDeviceInfo))
			{
				m_cAsyncIns.addMonDevice(
						cDeviceInfo.m_sHostName.c_str(),
						cDeviceInfo.m_sDevIp.c_str(),
						cDeviceInfo.m_sCommunity.c_str(),
						cDeviceInfo.m_netName.c_str(),
						cDeviceInfo.m_centerName.c_str(),
						cDeviceInfo.m_sOidName.c_str(),
						cDeviceInfo.m_sAttrType.c_str(),
						cDeviceInfo.m_sSeps.c_str(),
						"",
						cDeviceInfo.m_sAttendValue.c_str());
			}
		}

		void getMonDeviceNew(void)
		{
			CDevice cDeviceInfo;
			while (m_listDevice.get(cDeviceInfo))
			{
				m_cAsyncIns.addMonDeviceNew(
						cDeviceInfo.m_sDevIp.c_str(),
						cDeviceInfo.m_sCommunity.c_str(),
						cDeviceInfo.m_objID.c_str(),
						cDeviceInfo.m_sOidName.c_str(),
						cDeviceInfo.m_sAttrType.c_str(),
						cDeviceInfo.m_sSeps.c_str(),
						cDeviceInfo.m_type,
						cDeviceInfo.m_sAttendValue.c_str());
			}
		}

		///��ȡsnmpget��ObjectAttr����
		bool getConObjectAttr(CFTDRtnObjectAttrField &objectAttr)
		{
			return m_cAsyncIns.m_listConObjectAttr.get(objectAttr);
		}

		///��ȡsnmpget��ObjectAttr����
		bool getObjectAttr(CFTDRtnObjectAttrField &objectAttr)
		{
			return m_cAsyncIns.m_listObjectAttr.get(objectAttr);
		}

		///��ȡsnmpget������WarningEvent����
		bool getWarningEvent(CFTDRtnWarningEventField &warningEvent)
		{
			return m_cAsyncIns.m_listWarningEvent.get(warningEvent);
		}

		///��ȡsnmpget������SyslogEvent����
		bool getSyslogEvent(CFTDRtnSyslogEventField &syslogEvent)
		{
			return m_cAsyncIns.m_listSyslogEvent.get(syslogEvent);
		}

		///��ȡsnmpget������UpdateSysConfig����
		bool getUpdateSysConfig(CFTDRtnUpdateSysConfigField &updateConfig)
		{
			return m_cAsyncIns.m_listUpdateConfig.get(updateConfig);
		}

		///�ж��߳����Ƿ�����豸Ϊip�ļ��ָ��
		bool isMonitorDevTask(const char *ip)
		{
			map<string, CMonDevice>::iterator it = m_cAsyncIns.m_mapDevices.find(
					ip);
			if (it != m_cAsyncIns.m_mapDevices.end())
			{
				return true;
			}

			return false;
		}

		///�������ü�ض���
		void removeMonTask(const char *ip, const char *pOidName)
		{
			if (ip != NULL && strlen(ip) > 1)
			{
				m_cAsyncIns.removeMonDeviceTask(ip, pOidName);
			}
			else
			{
				m_cAsyncIns.clearMonDevice();
			}
		}

	/* */
	private:
		int m_nTimeZoneSec;

		// �̱߳�ţ���0��ʼ
		int m_nThreadNum;

		///�첽ȡ�豸snmp��Ϣʵ��
		CAsyncGetDevices m_cAsyncIns;

		///�����豸OID����
		TemplateMutexCatch<CDevice> m_listDevice;

	/* */
	public:
		///����������ļ��ж��������ݣ�����ģ�����DataField
			///@key	�������
			///@value	������Ϣ
		list<pair<int, string> > datas;
		list<pair<int, string> >::iterator	it_data;
};
#endif
