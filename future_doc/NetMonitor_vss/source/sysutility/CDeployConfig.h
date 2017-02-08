/////////////////////////////////////////////////////////////////////////
///@system ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CDeployConfig.h
///@brief ������Ϣ�����࣬�������������ļ���Ϊ�������ṩ��ȡ������Ϣ�ӿ�
///@history
///20111015	��־ΰ   �������ļ�
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

		/// �������������ļ�
		    ///@param	filePath �����ļ���·��
		    ///@return	��������ɹ�������true����֮����false��ͨ������Error�õ�������Ϣ��
		bool Parse (string filePath) throw(CRuntimeError);

		/// ���ش�����Ϣ
		    ///@return	����޴��󣬷��ؿմ���
		string Error(void)
		{
			return m_error;
		}

		///�������ͣ�������
		enum ServerType
		{
			ST_Master	= 1,
			ST_Slavery,
			ST_Invalid,
		};

		struct ServerAddrInfo
		{
			string	m_addr;						//�����ַ
			string	m_id;						//�����ID
			ServerAddrInfo (const char *a, const char *id)
			:
			m_addr(a),
			m_id(id)
			{
			}
		};

		///����������Ϣ
		struct CfgInfoBase
		{
			string	m_id;						// ����ID
			CDataCenterFlagType m_dc;			// ������������������
			
			        ///��ȡ������������صĵ�ַ
			        ///@param	name	��������֣�ƥ��ģʽΪ ^name$
			        /// @return ���ط���ĵ�ַ������Ҳ���ƥ����񣬷��ؿմ�
			string	ServerAddr(string name);

			///��ȡ������������صĵ�ַ
			        ///@param	name	��������֣�ƥ��ģʽΪ ^name*
			        /// @return ���ط���ĵ�ַ��Ϣ����������Ҳ���ƥ����񣬷��ؿ�����
			vector<ServerAddrInfo> ServerAddrArray(string name);
		private:
			friend class CDeployConfig;

			///���ֵ�ַ��
			struct ConnectionInfo
			{
				string	name;					//���������
				ServerAddrInfo	addrInfo;		//����ĵ�ַ��Ϣ
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

			vector<ConnectionInfo>	m_addrs;	// ������������������������صĵ�ַ
		};

		///���÷����������Ϣ
		struct SynconfigCfgInfo : public CfgInfoBase
		{
			struct syncfgAttr
			{
				int m_snmpTimeout;				// ���ھ����л�SNMP�������ӵĳ�ʱʱ�䣬��λΪ��
			};

			ServerType	m_serverType;			// ��������
			syncfgAttr	m_attr;
		};

		///snmp�����������Ϣ
		struct SnmpCfgInfo : public CfgInfoBase
		{
			ServerType	m_serverType;			// ��������
		};

		///ǰ�÷����������Ϣ
		struct SysfrontCfgInfo : public CfgInfoBase
		{
		};

		///��ѯ�����������Ϣ
		struct SysqueryCfgInfo : public CfgInfoBase
		{
		};

				///��ѯ�����������Ϣ
		struct SysslogCfgInfo : public CfgInfoBase
		{
		};

		///�¼���������������Ϣ
		struct SysEventCounterCfgInfo : public CfgInfoBase
		{
		};

		///��������������Ϣ
		struct SysAgentCfgInfo : public CfgInfoBase
		{
		};

		///ҵ�񱨵��������������Ϣ
		struct FibProxyCfgInfo : public CfgInfoBase
		{
		};
		
		struct FibFensCfgInfo : public CfgInfoBase
		{};

		///ҵ�񱨵��ͻ������������Ϣ
		struct SysFibClientCfgInfo : public CfgInfoBase
		{
		};

		///���ݿ��������Ϣ
		struct DBCfgInfo : public CfgInfoBase
		{
			string	m_dbname;
			string	m_ip;
			string	m_port;
			string	m_username;
			string	m_pwd;
		};

		/// �õ����÷��������������Ϣ��
		    ///@param	id ���÷����ID
		    ///@return	ID��Ӧ���÷����������Ϣ������Ҳ�����Ϣ����CRuntimeError�쳣
		SynconfigCfgInfo GetSynconfigCfgInfo (string id) throw(CRuntimeError);

		/// �õ�SNMP���������������Ϣ
		    ///@param	id SNMP�����ID
		    ///@return	ID��ӦSNMP�����������Ϣ������Ҳ�����Ϣ����CRuntimeError�쳣
		SnmpCfgInfo GetSnmpCfgInfo (string id) throw(CRuntimeError);

		/// �õ�ǰ�÷��������������Ϣ
		    ///@param	id ǰ�÷����ID
		    ///@return	ID��Ӧǰ�÷����������Ϣ������Ҳ�����Ϣ����CRuntimeError�쳣
		SysfrontCfgInfo GetSysfrontCfgInfo (string id) throw(CRuntimeError);

		/// �õ���ѯ���������������Ϣ
		    ///@param	id ��ѯ�����ID
		    ///@return	ID��Ӧ��ѯ�����������Ϣ������Ҳ�����Ϣ����CRuntimeError�쳣
		SysqueryCfgInfo GetSysqueryCfgInfo (string id) throw(CRuntimeError);

		/// �õ�slog�����������Ϣ
			///@param	id slog��ID
			///@return	ID��Ӧslog��������Ϣ������Ҳ�����Ϣ����CRuntimeError�쳣
		SysslogCfgInfo GetSysslogCfgInfo(string id) throw(CRuntimeError);

		/// �õ��¼�������������������Ϣ
		    ///@param	id �¼���������ID
		    ///@return	ID��Ӧ�¼���������������Ϣ������Ҳ�����Ϣ����CRuntimeError�쳣
		SysEventCounterCfgInfo GetSysEventCounterCfgInfo (string id) throw(CRuntimeError);

		/// �õ�������������������Ϣ
		    ///@param	id ��������ID
		    ///@return	ID��Ӧ��������������Ϣ������Ҳ�����Ϣ����CRuntimeError�쳣
		SysAgentCfgInfo GetSysAgentCfgInfo (string id) throw(CRuntimeError);

		/// �õ�ҵ�񱨵����������������Ϣ
		    ///@param	id ҵ�񱨵������ID
		    ///@return	ID��Ӧҵ�񱨵������������Ϣ������Ҳ�����Ϣ����CRuntimeError�쳣
		FibProxyCfgInfo GetFibProxyCfgInfoCfgInfo (string id) throw(CRuntimeError);

		/// �õ�ҵ�񱨵��ͻ����������������Ϣ
		    ///@param	id ҵ�񱨵��ͻ������ID
		    ///@return	ID��Ӧҵ�񱨵��ͻ������������Ϣ������Ҳ�����Ϣ����CRuntimeError�쳣
		SysFibClientCfgInfo GetSysFibClientCfgInfo (string id) throw(CRuntimeError);

		/// �õ����ݿ������������Ϣ
		    ///@param	dc ���ݿ���������������
		    ///@return	���ݿ��������Ϣ������Ҳ�����Ϣ����CRuntimeError�쳣
		DBCfgInfo GetDBCfgInfo (CDataCenterFlagType dc) throw(CRuntimeError);

		/// ���ַ�����ʾ��������ת����CDataCenterFlagType����
		    ///@param	center �������ĵ�Ӣ����
		    ///@return	�������ĵ��ڲ���ʶ
		static CDataCenterFlagType	TransCenterFlag(const char *center);

		/// ���ַ�����ʾ�����ӱ�ʶת����ServerType����
		    ///@param	type ���ӱ�ʶ��Ӣ����
		    ///@return	���ӱ�ʶ
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
		
		//���ӽ�������Ϊslog module��modified by shizhanwei
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

		///������ط����������Ϣ
		void parseServerAddr(
				CXMLNode *unit,
				const char	**serverNames,
				int len,
				CfgInfoBase &cfgInfo);

		///��������������ϵ�ķ����ַ��Ϣ
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
