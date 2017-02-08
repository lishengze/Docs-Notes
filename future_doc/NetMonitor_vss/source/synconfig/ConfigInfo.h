/////////////////////////////////////////////////////////////////////////
///@system ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file ConfigInfo.h
///@brief ������Ϣ��
///@history
///20110727	��־ΰ   �������ļ�
/////////////////////////////////////////////////////////////////////////
#ifndef __CONFIG_INFO_H
#define __CONFIG_INFO_H

#include <string>
#include <CDeployConfig.h>
#include <PrjCommon.h>

using namespace std;

class ConfigInfo
{
	/* */
	public:

		/// ConfigInfo��ʵ����ConfigInfoΪ����ģʽ��
		static ConfigInfo &Instance(void)
		{
			return m_obj;
		}

		///��������	
		~ConfigInfo(void)
		{
		}

		///�����ʶ��ʼ��������
		    ///@param	id	�����ʶ
		void InitSynconfigID(string id)
		{
			m_id = id;
		}

		///��ַ��Ϣ��ʼ���������ṩ�������������ӵĵ�ַ��
		    ///@param	frontListener	��ǰ�÷������ӵĵ�ַ
		    ///@param	snmpListener	��SNMP�������ӵĵ�ַ
		    ///@param	eventListener	���¼��������ӵĵ�ַ
		    ///@param	configListener	�ʹ����÷������ӵĵ�ַ
		void InitListenServer(
		string	frontListener,
		string	snmpListener,
		string	eventListener,
		string	configListener)
		{
			m_frontListener = frontListener;
			m_snmpListener = snmpListener;
			m_eventListener = eventListener;
			m_configListener = configListener;
		}

		///���ݿ���Ϣ��ʼ������
		    ///@param	ip	���ݿ��IP
		    ///@param	port	���ݿ�Ķ˿�
		    ///@param	dbName	��ռ�����
		    ///@param	user	�û���
		    ///@param	pwd	����
		void InitDBInfo(
		string	&ip,
		string	&port,
		string	&dbName,
		string	&user,
		string	&pwd)
		{
			m_ip = ip;
			m_port = port;
			m_dbName = dbName;
			m_user = user;
			m_pwd = pwd;
		}

		typedef CDeployConfig::ServerType ServerType;

		void InitServerType(ServerType type)
		{
			assert(type != CDeployConfig::ST_Invalid);
			m_serverType = type;
		}

		///�ṩ����ID
		string synconfigID(void) const
		{
			return m_id;
		}

		///�ṩǰ�÷������ӵĵ�ַ��Ϣ
		string frontListener(void) const
		{
			return m_frontListener;
		}

		///�ṩSNMP�������ӵĵ�ַ��Ϣ
		string snmpListener(void) const
		{
			return m_snmpListener;
		}

		///�ṩ�¼��������ӵĵ�ַ��Ϣ
		string eventListener(void) const
		{
			return m_eventListener;
		}

		///�ṩ�����÷������ӵĵ�ַ��Ϣ
		string configListener(void) const
		{
			return m_configListener;
		}

		///���ݿ�IP
		string DBIp(void) const
		{
			return m_ip;
		}

		///���ݿ�˿�
		string DBPort(void) const
		{
			return m_port;
		}

		///��ռ�
		string DBName(void) const
		{
			return m_dbName;
		}

		///�û���
		string DBUser(void) const
		{
			return m_user;
		}

		///����
		string DBPwd(void) const
		{
			return m_pwd;
		}

		/// �Ƿ�Ϊ�����÷���
		bool isMaster(void) const
		{
			assert(m_serverType != CDeployConfig::ST_Invalid);

			return CDeployConfig::ST_Master == m_serverType;
		}

		void InitParsedDeployCfg(const CDeployConfig &cfg)
		{
			m_deploycfg = cfg;
		}

		typedef CDeployConfig::SnmpCfgInfo	SnmpCfgInfo;
		SnmpCfgInfo GetSnmpCfgInfo(string id)
		{
			try
			{
				return m_deploycfg.GetSnmpCfgInfo(id);
			}
			catch (CRuntimeError *)
			{
				return SnmpCfgInfo();
			}
		}

		int GetSnmpTimeout(void)
		{
			return m_deploycfg.GetSynconfigCfgInfo(
					synconfigID()).m_attr.m_snmpTimeout;
		}

	/* */
	private:

		///���캯��
		ConfigInfo(void)
		{
		}

		// �����ʶ
		string	m_id;

		// ������������Ϣ
		string	m_frontListener;
		string	m_snmpListener;
		string	m_eventListener;
		string	m_configListener;

		// ���ݿ������Ϣ
		string	m_ip;
		string	m_port;
		string	m_dbName;
		string	m_user;
		string	m_pwd;

		ServerType	m_serverType;

		CDeployConfig m_deploycfg;

		///ConfigInfo��������
		static ConfigInfo m_obj;
};
#endif // __CONFIG_INFO_H
