/////////////////////////////////////////////////////////////////////////
///@system	������ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CSynconfig.h
///@brief	���������÷��������
///@history
///20110928	��־ΰ		�������ļ�
#ifndef __CSYNCONFIG_H
#define __CSYNCONFIG_H

#include "CFrontServer.h"
#include "CManagerServer.h"
#include "CEventServer.h"
#include "CSyncServer.h"
#include <PrjCommon.h>
#include <systools.h>
#include "CCrypto.h"

/////////////////////////////////////////////////////////////////////////
///CSynconfig�����÷�������࣬�������÷�����������ڡ�
/////////////////////////////////////////////////////////////////////////
class CSynconfig
{
	/* */
	public:
		CSynconfig(void);

		~CSynconfig(void)
		{
		}

		///��ʼ�����÷���
		    ///@param	argc	�����в�������
		    ///@param	argv	�����в���
		    ///@return	��ʼ���ɹ�Ϊtrue������Ϊfalse
		bool Init(int argc, char *argv[]);

		///�������÷����������ķ������
		    ///@return	�����ɹ�Ϊtrue������Ϊfalse
		bool Start(void);

		///��ֹ���÷����������ķ������
		    ///��Ϊ�첽���ã�����Stop֮����Ҫ��Wait��ȷ�����÷����Ѿ�����ֹ��
		void Stop(void);

		///�ȴ����÷����������ķ��������ֹ
		    ///@return	���÷����е����÷���������ֹΪtrue������Ϊfalse
		bool Wait(void);

	/* */
	private:
		bool feedUpMemoryDB(void);

	/* */
	private:
		CSelectReactor	m_frontReactor;
		CFrontServer m_frontServer;

		CSelectReactor	m_snmpReactor;
		CManagerServer	m_snmpServer;

		CSelectReactor	m_eventReactor;
		CEventServer m_eventServer;

		SysReactor	m_syncReactor;
		CSyncServer m_syncServer;

		SyncDBOperator	m_dbHandler;
};
#endif // __CSYNCONFIG_H
