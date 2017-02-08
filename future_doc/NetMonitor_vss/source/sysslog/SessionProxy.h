/////////////////////////////////////////////////////////////////////////
///@system ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file SessionProxy.h
///@brief �Ự�����࣬Ϊ��CSlogServer���������ṩ����
///@history
///20120316	��־ΰ   �������ļ�
/////////////////////////////////////////////////////////////////////////
#ifndef __SESSION_PROXY_H
#define __SESSION_PROXY_H

#include "CSlogServer.h"
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
		void Init(CSlogServer *frontMgr)
		{
			assert(frontMgr);

			m_frontMgr = frontMgr;
		}

		///֪ͨ���е�ǰ������
		    ///@param	pkg	Ҫ���͵����ݰ�
		void NotifyAllFront(CFTDCPackage *pkg)
		{
			assert(pkg);

			if (m_frontMgr)
			{
				m_frontMgr->NotifyAllSession(pkg);
			}
		}

	/* */
	private:
		SessionProxy(void) :
		m_frontMgr(NULL)
		{
		}

		/// ǰ�÷������ˣ�������������������ڡ�
		CSlogServer *m_frontMgr;

		/// ���������ṩ�̰߳�ȫ�Ա���
		CMutex	m_mutex;

		/// SessionProxy�ĵ�������
		static SessionProxy m_obj;
};
#endif // __SESSION_PROXY_H
