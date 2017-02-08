/////////////////////////////////////////////////////////////////////////
///@system 网络监控系统
///@company 上海期货信息技术有限公司
///@file ConfigInfo.h
///@brief 配置信息类
///@history
///20110727	李志伟   创建该文件
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

		/// ConfigInfo的实例，ConfigInfo为单件模式。
		static ConfigInfo &Instance(void)
		{
			return m_obj;
		}

		///析构函数	
		~ConfigInfo(void)
		{
		}

		///程序标识初始化函数，
		    ///@param	id	程序标识
		void InitSynconfigID(string id)
		{
			m_id = id;
		}

		///地址信息初始化函数，提供给各个服务连接的地址。
		    ///@param	frontListener	给前置服务连接的地址
		    ///@param	snmpListener	和SNMP服务连接的地址
		    ///@param	eventListener	和事件服务连接的地址
		    ///@param	configListener	和从配置服务连接的地址
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

		///数据库信息初始化函数
		    ///@param	ip	数据库的IP
		    ///@param	port	数据库的端口
		    ///@param	dbName	表空间名字
		    ///@param	user	用户名
		    ///@param	pwd	密码
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

		///提供程序ID
		string synconfigID(void) const
		{
			return m_id;
		}

		///提供前置服务连接的地址信息
		string frontListener(void) const
		{
			return m_frontListener;
		}

		///提供SNMP服务连接的地址信息
		string snmpListener(void) const
		{
			return m_snmpListener;
		}

		///提供事件服务连接的地址信息
		string eventListener(void) const
		{
			return m_eventListener;
		}

		///提供从配置服务连接的地址信息
		string configListener(void) const
		{
			return m_configListener;
		}

		///数据库IP
		string DBIp(void) const
		{
			return m_ip;
		}

		///数据库端口
		string DBPort(void) const
		{
			return m_port;
		}

		///表空间
		string DBName(void) const
		{
			return m_dbName;
		}

		///用户名
		string DBUser(void) const
		{
			return m_user;
		}

		///密码
		string DBPwd(void) const
		{
			return m_pwd;
		}

		/// 是否为主配置服务
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

		///构造函数
		ConfigInfo(void)
		{
		}

		// 程序标识
		string	m_id;

		// 监听服务器信息
		string	m_frontListener;
		string	m_snmpListener;
		string	m_eventListener;
		string	m_configListener;

		// 数据库相关信息
		string	m_ip;
		string	m_port;
		string	m_dbName;
		string	m_user;
		string	m_pwd;

		ServerType	m_serverType;

		CDeployConfig m_deploycfg;

		///ConfigInfo单件对象
		static ConfigInfo m_obj;
};
#endif // __CONFIG_INFO_H
