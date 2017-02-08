/////////////////////////////////////////////////////////////////////////
///@system ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file SessionProxy.h
///@brief �Ự�����࣬ΪCFrontServer��CManagerServer�໥���������ṩ����
///@history
///20110728	��־ΰ   �������ļ�
/////////////////////////////////////////////////////////////////////////
#ifndef __SESSION_PROXY_H
#define __SESSION_PROXY_H

#include "CFrontServer.h"
#include "CManagerServer.h"
#include "CEventServer.h"
#include "CSyncServer.h"
#include <ScopedLock.h>
#include <Mutex.h>
#include <systools.h>
#include <list>
#include <PrjCommon.h>

///SessionProxyΪ���Session��ͨ���ṩ����
class SessionProxy
{
	/* */
	public:

		/// SessionProxy��ʵ����SessionProxyΪ����ģʽ��
		static SessionProxy &Instance(void)
		{
			return m_obj;
		}

		///��������	
		~SessionProxy(void)
		{
		}

		///��ʼ���������ṩ�����������ӵĹ���ˣ�������á�
		    ///@param	frontMgr	��ǰ�÷������ӵĹ����
		    ///@param	snmpMgr	��SNMP�������ӵĹ����
		    ///@param	eventMgr	���¼��������ӵĹ����
		    ///@param	syncMgr	��ͬ�����÷������ӵĹ����
		void Init(
		CFrontServer *frontMgr,
		CManagerServer	*snmpMgr,
		CEventServer *eventMgr,
		CSyncServer *syncMgr)
		{
			assert(frontMgr && frontMgr && eventMgr && syncMgr);

			m_frontMgr = frontMgr;
			m_snmpMgr = snmpMgr;
			m_eventMgr = eventMgr;
			m_syncMgr = syncMgr;
		}

		///֪ͨSNMP�����
		    ///@param	reqPkg	Ҫ���͵����ݰ�
		void NotifySnmp(CFTDCPackage *reqPkg)
		{
			assert(reqPkg && m_snmpMgr);
			m_snmpMgr->NotifyAllSessions(reqPkg);
		}

		///ָ֪ͨ�����ĵ�SNMP�����
		    ///@param	reqPkg	Ҫ���͵����ݰ�
		    ///@param	dc �������ı�ʶ
		void NotifySnmp(CFTDCPackage *reqPkg, CDataCenterFlagType dc)
		{
			assert(reqPkg && m_snmpMgr);
			m_snmpMgr->NotifySessions(reqPkg, dc);
		}

		void NotifySnmp(char dataCenter, CFTDCPackage *reqPkg)
		{
			assert(reqPkg && m_snmpMgr);
			m_snmpMgr->NotifySessions(dataCenter, reqPkg);
		}

		///֪ͨ�¼���������
		    ///@param	reqPkg	Ҫ���͵����ݰ�
		void NotifyEventCounter(CFTDCPackage *reqPkg)
		{
			assert(reqPkg && m_eventMgr);
			m_eventMgr->NotifyAllSessions(reqPkg);
		}

		///֪ͨ���е�ǰ������
		    ///@param	pkg	Ҫ���͵����ݰ�
		void NotifyFront(CFTDCPackage *pkg)
		{
			assert(pkg && m_frontMgr);
			m_frontMgr->NotifyAllSession(pkg);
		}

		///֪ͨ���еĴ����÷���
		    ///@param	pkg	Ҫ���͵����ݰ�
		void NotifySync(CFTDCPackage *pkg)
		{
			assert(pkg && m_syncMgr);
			m_syncMgr->NotifyAllSessions(pkg);
		}

		///ǰ�÷�����SNMP����˷������󣬸÷������̰߳�ȫ�ġ�
		    ///@param	reqPkg   ��������ݰ�
		    ///@param	reqSession	���������session
		    ///@param	rspPkg	Ҫ���͵����ݰ�
		    ///@param	datacenter	�������snmpManger��������������
		void RequestSnmp(
				CFTDCPackage *reqPkg,
				CFTDCSession *reqSession,
				CFTDCPackage *rspPkg,
				char datacenter);

		//SNMP�������ǰ�÷�������Ӧ���÷������̰߳�ȫ�ġ�
		    ///@param	reqID	���ݰ���ID
		    ///@param	rspPkg	Ҫ���͵����ݰ�
		    ///@param	lastRsp	�Ƿ������һ����Ӧ����
		void RespondFront(int rspID, CFTDCPackage *rspPkg, bool lastRsp);

	/* */
	private:
		SessionProxy(void) :
		m_index(0)
		{
		}

		/// ǰ�÷������ˣ�������������������ڡ�
		CFrontServer *m_frontMgr;

		/// SNMP�������ˣ�������������������ڡ�
		CManagerServer	*m_snmpMgr;

		/// �¼��������ˣ�������������������ڡ�
		CEventServer *m_eventMgr;

		/// ͬ���������ˣ�������������������ڡ�
		CSyncServer *m_syncMgr;

		/// ���������ṩ�̰߳�ȫ�Ա���
		CMutex	m_mutex;

		/// ����front��snmp֮��ͨ�ŵİ���Ự
		typedef map<DWORD, TRID> SessionPkgSet;
		SessionPkgSet m_vRid;
		DWORD m_index;

		/// SessionProxy�ĵ�������
		static SessionProxy m_obj;
};
#endif // __SESSION_PROXY_H
