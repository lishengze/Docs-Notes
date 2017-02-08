/////////////////////////////////////////////////////////////////////////
///@system 网络监控系统
///@company 上海期货信息技术有限公司
///@file CDeployConfig.h
///@brief 部署信息解析类，解析部署配置文件，为各服务提供获取配置信息接口
///@history
///20111015	李志伟   创建该文件
/////////////////////////////////////////////////////////////////////////
#ifndef __CDEPLOY_CONFIG_H
#define __CDEPLOY_CONFIG_H

#include <string>
#include <vector>
#include <customDataType.h>
#include <RuntimeError.h>

using namespace std;

class CXMLNode;

class CDeployConfig
{
	/* */
	public:
		CDeployConfig(void)
		{
		}

		~CDeployConfig(void)
		{
		}

#ifdef WIN32
#pragma warning(disable : 4290)
#endif

		/// 解析部署配置文件
		    ///@param	filePath 部署文件的路径
		    ///@return	如果解析成功，返回true，反之返回false。通过调用Error得到错误信息。
		bool Parse (string filePath) throw(CRuntimeError);

		/// 返回错误信息
		    ///@return	如果无错误，返回空串。
		string Error(void)
		{
			return m_error;
		}

		///服务类型：主、从
		enum ServerType
		{
			ST_Master	= 1,
			ST_Slavery,
			ST_Invalid,
		};

		struct ServerAddrInfo
		{
			string	m_addr;						//服务地址
			string	m_id;						//服务端ID
			ServerAddrInfo (const char *a, const char *id)
			:
			m_addr(a),
			m_id(id)
			{
			}
		};

		///服务配置信息
		struct CfgInfoBase
		{
			string	m_id;						// 服务ID
			CDataCenterFlagType m_dc;			// 服务所处的数据中心
			
			        ///获取与其它服务相关的地址
			        ///@param	name	服务的名字，匹配模式为 ^name$
			        /// @return 返回服务的地址。如果找不到匹配服务，返回空串
			string	ServerAddr(string name);

			///获取与其它服务相关的地址
			        ///@param	name	服务的名字，匹配模式为 ^name*
			        /// @return 返回服务的地址信息容器。如果找不到匹配服务，返回空容器
			vector<ServerAddrInfo> ServerAddrArray(string name);
		private:
			friend class CDeployConfig;

			///名字地址对
			struct ConnectionInfo
			{
				string	name;					//服务的名字
				ServerAddrInfo	addrInfo;		//服务的地址信息
				ConnectionInfo (const char *n, const char *a, const char *id)
				:
				name(n),
				addrInfo(a, id)
				{
				}

				ConnectionInfo (const char *n, ServerAddrInfo &info)
				:
				name(n),
				addrInfo(info)
				{
				}
			};

			vector<ConnectionInfo>	m_addrs;	// 服务所依赖的与其它服务相关的地址
		};

		///配置服务的配置信息
		struct SynconfigCfgInfo : public CfgInfoBase
		{
			struct syncfgAttr
			{
				int m_snmpTimeout;				// 用于决定切换SNMP主从连接的超时时间，单位为秒
			};

			ServerType	m_serverType;			// 主从类型
			syncfgAttr	m_attr;
		};

		///snmp服务的配置信息
		struct SnmpCfgInfo : public CfgInfoBase
		{
			ServerType	m_serverType;			// 主从类型
		};

		///前置服务的配置信息
		struct SysfrontCfgInfo : public CfgInfoBase
		{
		};

		///查询服务的配置信息
		struct SysqueryCfgInfo : public CfgInfoBase
		{
		};

				///查询服务的配置信息
		struct SysslogCfgInfo : public CfgInfoBase
		{
		};

		///事件计算服务的配置信息
		struct SysEventCounterCfgInfo : public CfgInfoBase
		{
		};

		///代理服务的配置信息
		struct SysAgentCfgInfo : public CfgInfoBase
		{
		};

		///业务报单流服务的配置信息
		struct FibProxyCfgInfo : public CfgInfoBase
		{
		};
		
		struct FibFensCfgInfo : public CfgInfoBase
		{};

		///业务报单客户服务的配置信息
		struct SysFibClientCfgInfo : public CfgInfoBase
		{
		};

		///数据库的配置信息
		struct DBCfgInfo : public CfgInfoBase
		{
			string	m_dbname;
			string	m_ip;
			string	m_port;
			string	m_username;
			string	m_pwd;
		};

		/// 得到配置服务所需的配置信息。
		    ///@param	id 配置服务的ID
		    ///@return	ID对应配置服务的配置信息。如果找不到信息，抛CRuntimeError异常
		SynconfigCfgInfo GetSynconfigCfgInfo (string id) throw(CRuntimeError);

		/// 得到SNMP服务所需的配置信息
		    ///@param	id SNMP服务的ID
		    ///@return	ID对应SNMP服务的配置信息。如果找不到信息，抛CRuntimeError异常
		SnmpCfgInfo GetSnmpCfgInfo (string id) throw(CRuntimeError);

		/// 得到前置服务所需的配置信息
		    ///@param	id 前置服务的ID
		    ///@return	ID对应前置服务的配置信息。如果找不到信息，抛CRuntimeError异常
		SysfrontCfgInfo GetSysfrontCfgInfo (string id) throw(CRuntimeError);

		/// 得到查询服务所需的配置信息
		    ///@param	id 查询服务的ID
		    ///@return	ID对应查询服务的配置信息。如果找不到信息，抛CRuntimeError异常
		SysqueryCfgInfo GetSysqueryCfgInfo (string id) throw(CRuntimeError);

		/// 得到slog所需的配置信息
			///@param	id slog的ID
			///@return	ID对应slog的配置信息。如果找不到信息，抛CRuntimeError异常
		SysslogCfgInfo GetSysslogCfgInfo(string id) throw(CRuntimeError);

		/// 得到事件计算服务所需的配置信息
		    ///@param	id 事件计算服务的ID
		    ///@return	ID对应事件计算服务的配置信息。如果找不到信息，抛CRuntimeError异常
		SysEventCounterCfgInfo GetSysEventCounterCfgInfo (string id) throw(CRuntimeError);

		/// 得到代理服务所需的配置信息
		    ///@param	id 代理服务的ID
		    ///@return	ID对应代理服务的配置信息。如果找不到信息，抛CRuntimeError异常
		SysAgentCfgInfo GetSysAgentCfgInfo (string id) throw(CRuntimeError);

		/// 得到业务报单服务所需的配置信息
		    ///@param	id 业务报单服务的ID
		    ///@return	ID对应业务报单服务的配置信息。如果找不到信息，抛CRuntimeError异常
		FibProxyCfgInfo GetFibProxyCfgInfoCfgInfo (string id) throw(CRuntimeError);

		/// 得到业务报单客户服务所需的配置信息
		    ///@param	id 业务报单客户服务的ID
		    ///@return	ID对应业务报单客户服务的配置信息。如果找不到信息，抛CRuntimeError异常
		SysFibClientCfgInfo GetSysFibClientCfgInfo (string id) throw(CRuntimeError);

		/// 得到数据库所需的配置信息
		    ///@param	dc 数据库所处的数据中心
		    ///@return	数据库的配置信息。如果找不到信息，抛CRuntimeError异常
		DBCfgInfo GetDBCfgInfo (CDataCenterFlagType dc) throw(CRuntimeError);

		/// 将字符串表示的中心名转换成CDataCenterFlagType类型
		    ///@param	center 数据中心的英文名
		    ///@return	数据中心的内部标识
		static CDataCenterFlagType	TransCenterFlag(const char *center);

		/// 将字符串表示的主从标识转换成ServerType类型
		    ///@param	type 主从标识的英文名
		    ///@return	主从标识
		static ServerType TransServerType(const char *type);

		struct dataCenterInfo
		{
			vector<string>	names;
			CDataCenterFlagType type;
		};

	/* */
	private:
		string	getDeployFile(string filePath);

		void parseDataCenterInfo(CXMLNode *root);
		void parseDataCenterUnit(CXMLNode *unit);

		void parseSynconfigInfo(CXMLNode *root);
		void parseSynconfigCommon(CXMLNode *root);
		void parseSynconfigUnit(CXMLNode *unit);

		void parseSnmpInfo(CXMLNode *root);
		void parseSnmpUnit(CXMLNode *unit);

		void parseFrontInfo(CXMLNode *root);
		void parseFrontUnit(CXMLNode *unit);

		void parseQueryInfo(CXMLNode *root);
		void parseQueryUnit(CXMLNode *unit);
		
		//增加解析函数为slog module，modified by shizhanwei
		void parseSlogInfo(CXMLNode *root);
		void parseSlogUnit(CXMLNode *unit);

		void parseEventInfo(CXMLNode *root);
		void parseEventUnit(CXMLNode *unit);

		void parseAgentInfo(CXMLNode *root);
		void parseAgentUnit(CXMLNode *unit);

		void parseFibProxyInfo(CXMLNode *root);
		void parseFibProxyUnit(CXMLNode *unit);

		void parseFibClientInfo(CXMLNode *root);
		void parseFibClientUnit(CXMLNode *unit);

		void parseDBInfo(CXMLNode *root);
		void parseDBUnit(CXMLNode *unit);

		///解析相关服务的连接信息
		void parseServerAddr(
				CXMLNode *unit,
				const char	**serverNames,
				int len,
				CfgInfoBase &cfgInfo);

		///解析基于依赖关系的服务地址信息
		ServerAddrInfo	parseAddrByDependence(
							const char	*currentServer,
							const char	*dependServer,
							const char	*center,
							const char	*role);
		void parseFibFensUnit(CXMLNode *unit);
		void parseFibFensInfo(CXMLNode *root);
		/* */
	private:
		SynconfigCfgInfo::syncfgAttr m_syncfgAttr;
		vector<SynconfigCfgInfo> m_synconfigs;
		vector<SnmpCfgInfo> m_snmps;
		vector<SysfrontCfgInfo> m_fronts;
		vector<SysqueryCfgInfo> m_querys;
		vector<SysslogCfgInfo> m_slogs;
		vector<SysEventCounterCfgInfo>	m_events;
		vector<SysAgentCfgInfo> m_agents;
		vector<FibProxyCfgInfo> m_fibproxys;
		vector<FibFensCfgInfo>	m_fibFens;
		vector<SysFibClientCfgInfo> m_fibclients;
		vector<DBCfgInfo> m_dbs;

		static vector<dataCenterInfo> m_dcInfos;

		string	m_error;

		CXMLNode *m_root;
};
#endif // __CDEPLOY_CONFIG_H
