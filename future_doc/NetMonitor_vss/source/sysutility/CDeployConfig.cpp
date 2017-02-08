/////////////////////////////////////////////////////////////////////////
///@system ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CDeployConfig.cpp
///@brief ������Ϣ�����࣬�������������ļ���Ϊ�������ṩ��ȡ������Ϣ�ӿ�
///@history
///20111015	��־ΰ   �������ļ�
///20140603 ʷսΰ   ���slog module ����
/////////////////////////////////////////////////////////////////////////
#include "CDeployConfig.h"
#include <CXML.h>
#include "StringUtil.h"
#include "PrjCommon.h"

CFileLogger *g_traceLog = NULL; //ϵͳ������־	
static const string DefaultCfgPath = "./";
static const string DeployCfg = "DeployConfig.xml";

// �������ݱ�ָ���˸��������������������������֡�����ÿ����ĵ�һ��Ϊ������������֡�
static const char *synconfigAddrName[] =
{
	"synconfig",
	"sysfront",
	"syseventcounter",
	"snmpmanager",
	"synconfig"
};
static const char *snmpAddrName[] =
{
	"snmpmanager",
	"syseventcounter",
	"synconfig"
};
static const char *frontAddrName[] =
{
	"sysfront",
	"client",
	"syseventcounter",
	"sysquery",
	"synconfig",
	"sysfibclient",
	"sysslog"
};
static const char *queryAddrName[] =
{
	"sysquery",
	"sysfront",
	"syseventcounter"
};
static const char *slogAddrName[] =
{
	"sysslog",
	"sysfront",
	"syseventcounter"
};
static const char *eventAddrName[] =
{
	"syseventcounter",
	"sysfront",
	"sysquery",
	"sysslog",
	"sysfibclient",
	"sysagent",
	"probeserver",
	"synconfig",
	"snmpmanager1",
	"snmpmanager2",
	"snmpmanager3",
	"snmpmanager4",
	"snmpmanager5",
	"snmpmanager6",
	"snmpmanager7",
	"snmpmanager8",
	"snmpmanager9"
};
static const char *agentAddrName[] = { "sysagent", "syseventcounter" };
static const char *fibproxyAddrName[] = { "fibproxy", "sysfibclient" };
static const char *fibfensAddrName[] = {"fens", "sysfibclient"};
static const char *fibclientAddrName[] =
{
	"sysfibclient",
	"sysfront",
	"syseventcounter",
	"fibproxy1",
	"fibproxy2",
	"fibproxy3",
	"fens1",
	"fens2",
	"fens3"
};

struct DataCenterMap
{
	string	name;
	CDataCenterFlagType type;
};

DataCenterMap dcMap[] =
{
	{ "zhangjiang", DC_ZhangJiang },
	{ "beijing", DC_BeiJing },
	{ "pudian", DC_PuDian },
};

vector<CDeployConfig::dataCenterInfo> CDeployConfig:: m_dcInfos;

string CDeployConfig::CfgInfoBase::ServerAddr(string name)
{
	for (vector < CfgInfoBase::ConnectionInfo >::iterator it = m_addrs.begin()
			 ;
	 it != m_addrs.end();
		 it++)
	{
		if (!compareStringNoCase(it->name.c_str(), name.c_str()))
		{
			return it->addrInfo.m_addr;
		}
	}

	return "";
}

vector<CDeployConfig::ServerAddrInfo> CDeployConfig::CfgInfoBase::ServerAddrArray(
	string	name)
{
	vector<ServerAddrInfo>	rtn;

	for (vector < CfgInfoBase::ConnectionInfo >::iterator it = m_addrs.begin()
			 ;
	 it != m_addrs.end();
		 it++)
	{
		if (!strncmp(it->name.c_str(), name.c_str(), name.length()))
		{
			rtn.push_back(it->addrInfo);
		}
	}

	return rtn;
}

bool CDeployConfig::Parse(string filePath)
throw(CRuntimeError)
{
	bool rtn = true;

	string	file = getDeployFile(filePath);

	CXMLDoc doc;
	try
	{
		doc.read((char *)file.c_str());

		CXMLNode *root = doc.getRootNode();
		m_root = root;

		parseDataCenterInfo(root);

		parseSynconfigInfo(root);

		parseSnmpInfo(root);

		parseEventInfo(root);

		parseFrontInfo(root);

		parseQueryInfo(root);

		parseSlogInfo(root);

		parseAgentInfo(root);

		parseFibProxyInfo(root);

		parseFibClientInfo(root);
		
		parseFibFensInfo(root);

		parseDBInfo(root);
	}

	catch(CParseError * e)
	{
		rtn = false;

		char tmp[1024];
		SNPRINTF(
			tmp,
			1024,
			"Parse Deploy config file(%s) failed : LineNumber (%d) -- Message (%s)\n",
			file.c_str(),
			e->getLineNo(),
			e->getMsg());
		m_error = tmp;

		throw new CRuntimeError(tmp, __FILE__, __LINE__);
	}

	return rtn;
}

string CDeployConfig::getDeployFile(string filePath)
{
	string	file;

	if (filePath.empty())
	{
		file += DefaultCfgPath;
	}
	else
	{
		file += filePath;

		// ���ĩβû�� "/"���������
		const char	*s = filePath.c_str();
		if (*(s + filePath.length() - 1) != '/')
		{
			file += "/";
		}
	}

	file += DeployCfg;

	return file;
}

CXMLNode *getNode(
	CXMLNode *parent,
	const char	*tag,
	const char	*propertyName = NULL,
	const char	*propertyValue = NULL)
{
	CXMLNode *child = parent->findNode(
			XMLTag,
			(char *)tag,
			(char *)propertyName,
			(char *)propertyValue);
	if (!child)
	{
		char tmp[64];
		SNPRINTF(
			tmp,
			64,
			"Can't find node: tag(%s),  propertyName(%s), propertyValue(%s)",
			tag,
			propertyName,
			propertyValue);
		throw new CParseError(tmp, 0);
	}

	return child;
}

CDataCenterFlagType transCenterFlag(const char *center)
{
	CDataCenterFlagType dc = CDeployConfig::TransCenterFlag(center);

	if (dc == DC_UnKnow)
	{
		char tmp[64];
		SNPRINTF(tmp, 64, "Invaild data center: %s ", center);
		throw new CParseError(tmp, 0);
	}

	return dc;
}

CDeployConfig::ServerType CDeployConfig::TransServerType (const char *type)
{
	if (!compareStringNoCase(type, "master"))
	{
		return CDeployConfig::ST_Master;
	}
	else if (!compareStringNoCase(type, "slave"))
	{
		return CDeployConfig::ST_Slavery;
	}
	else
	{
		assert(true && "ServerType is invalid");
		return CDeployConfig::ST_Invalid;
	}
}

template<typename T, typename C>
T findDataByRole(C &container, const char *role)
{
	CDeployConfig::ServerType type = CDeployConfig::TransServerType(role);
	for (typename C::iterator it = container.begin();
		 it != container.end();
		 it++)
	{
		if (it->m_serverType == type)
		{
			return *it;
		}
	}

	assert(true && "Invalid role");

	// return dummy data
	return T();
}

template<typename T, typename C>
T findDataByCenter(C &container, const char *center)
{
	CDataCenterFlagType dc = CDeployConfig::TransCenterFlag(center);

	for (typename C::iterator it = container.begin();
		 it != container.end();
		 it++)
	{
		if (it->m_dc == dc)
		{
			return *it;
		}
	}

	assert(true && "Invalid role");

	// return dummy data
	return T();
}

template<typename T, typename C>
T findDataByID (C & container, string & id)
throw(CRuntimeError)
{
	for (typename C::iterator it = container.begin();
		 it != container.end();
		 it++)
	{
		if (it->m_id == id)
		{
			return *it;
		}
	}

	char tmp[64];
	SNPRINTF(tmp, 64, "Can't find data by id(%s) ", id.c_str());

	throw new CRuntimeError(tmp, __FILE__, __LINE__);

	//assert(true && "Invalid ID");
	    //// return dummy data
	//return T();
}

void CDeployConfig::parseServerAddr(
	CXMLNode *unit,
	const char	**serverNames,
	int len,
	CfgInfoBase &cfgInfo)
{
	const char	*currentServer = serverNames[0];

	// ��1��ʼ��λ��0�ǵ�ǰ���������
	for (int i = 1; i < len; i++)
	{
		const char	*name = serverNames[i];
		CXMLNode *node = unit->findNode(
				XMLTag,
				(char *)"Object",
				(char *)"type",
				(char *)name);
		if (!node)
		{
			//string msg = "DeployConfig.xml: Under "; msg += currentServer; msg += "("; msg += cfgInfo.m_id; msg += ")";
			//msg += ", there is no config info of "; msg += name; msg += ". You may need check it!\n";
			//
			//printf("%s", msg.c_str());
			//fflush(stdout);
			continue;
		}

		const char	*addr = node->findProperty("address");
		if (addr)
		{
			// ��ǰ����Ϊ��������Ԥ�������ӵ�ַ
			cfgInfo.m_addrs.push_back(
					CfgInfoBase::ConnectionInfo(
							name,
							addr,
							cfgInfo.m_id.c_str()));
		}
		else
		{
			// ��ǰ��������������������ĵ�ַ
			const char	*center = node->findProperty("center");
			const char	*role = node->findProperty("role");
			ServerAddrInfo	addrInfo = parseAddrByDependence(
					currentServer,
					name,
					center,
					role);
			cfgInfo.m_addrs.push_back(
					CfgInfoBase::ConnectionInfo(name, addrInfo));
		}
	}
}

CXMLNode *findNode(CXMLNode *unit, const char *center, const char *role)
{
	if (!unit)
	{
		return NULL;
	}

	assert(center && role);

	const char	*c = unit->findProperty("center");
	const char	*r = unit->findProperty("role");
	if (c && r && strcmp(c, center) == 0 && strcmp(r, role) == 0)
	{
		return unit;
	}

	return findNode(unit->getBrother(), center, role);
}

CDeployConfig::ServerAddrInfo CDeployConfig::parseAddrByDependence(
	const char	*currentServer,
	const char	*dependServer,
	const char	*center,
	const char	*role)
{
	assert(currentServer && dependServer);

	// ���������ļ���<syseventcounter>�ڵ����� snmpmanager1�Ƚڵ㣬��Ҫ��������������
	// ���������ļ���<sysfibclient>�ڵ����� fibproxy1�Ƚڵ㣬��Ҫ��������������
	if (!strncmp(dependServer, "snmpmanager", strlen("snmpmanager")))
	{
		dependServer = "snmpmanager";
	}
	else if (!strncmp(dependServer, "fibproxy", strlen("fibproxy")))
	{
		dependServer = "fibproxy";
	}
	else if (!strncmp(dependServer, "fens", strlen("fens")))
	{
		dependServer = "fens";
	}

	CXMLNode *services = getNode(m_root, "Services");
	CXMLNode *serve = getNode(services, dependServer);
	CXMLNode *unit;

	assert(center || role);		// center��role����ͬʱΪ��
	const char	*propName1;
	const char	*propValue1;

	if (center && role)
	{
		unit = getNode(serve, "Service", "center", center);
		unit = findNode(unit, center, role);
	}
	else
	{
		if (center)
		{
			propName1 = "center";
			propValue1 = center;
		}
		else
		{
			propName1 = "role";
			propValue1 = role;
		}

		unit = getNode(serve, "Service", propName1, propValue1);
	}

	if (!unit)
	{
		string	msg = "DeployConfig.xml: Under ";
		msg += currentServer;
		msg += " , there is no ";
		msg += dependServer;
		msg += " with center(";
		msg += center;
		msg += "), role(";
		msg += role;
		msg += ")\n";
		printf("%s", msg.c_str());
		getchar();
		fflush(stdout);
		exit(-1);
	}

	CXMLNode *addr = getNode(unit, "Object", "type", currentServer);

	return ServerAddrInfo(
			addr->findProperty("address"),
			unit->findProperty("id"));
}

void CDeployConfig::parseDataCenterInfo(CXMLNode *root)
{
	CXMLNode *datacenters = getNode(root, "Datacenters");

	for (CXMLNode * unit = datacenters->getSon(0);
		 unit != NULL;
		 unit = unit->getBrother())
	{
		parseDataCenterUnit(unit);
	}
}

void CDeployConfig::parseDataCenterUnit(CXMLNode *unit)
{
	const char	*name = unit->getName();

	for (int i = 0, len = ARRAY_LEN(dcMap); i < len; i++)
	{
		if (!compareStringNoCase(name, dcMap[i].name.c_str()))
		{
			dataCenterInfo	info;
			info.type = dcMap[i].type;

			CXMLNode *node = unit->getSon(0);
			while (node)
			{
				info.names.push_back(node->findProperty("name"));
				node = node->getBrother();
			}

			m_dcInfos.push_back(info);
		}
	}
}

void CDeployConfig::parseSynconfigInfo(CXMLNode *root)
{
	CXMLNode *services = getNode(root, "Services");

	CXMLNode *synconfig = getNode(services, "synconfig");

	parseSynconfigCommon(synconfig);

	for (CXMLNode * unit = synconfig->getSon(0);
		 unit != NULL;
		 unit = unit->getBrother())
	{
		parseSynconfigUnit(unit);
	}
}

void CDeployConfig::parseSynconfigCommon(CXMLNode *root)
{
	CXMLNode *attr = getNode(root, "Attribute");

	int a = atoi(getNode(attr, "snmptimeout")->findProperty("timeout"));
	if (a == 0)
	{
		throw new CRuntimeError(
				"snmptimeout should be a number which is greater than 0\n",
				__FILE__,
				__LINE__);
	}

	m_syncfgAttr.m_snmpTimeout = a;
}

void CDeployConfig::parseSynconfigUnit(CXMLNode *unit)
{
	if (!strcmp(unit->getName(), "Service"))
	{
		SynconfigCfgInfo data;

		data.m_id = (unit->findProperty("id"));
		data.m_dc = transCenterFlag(unit->findProperty("center"));
		data.m_serverType = TransServerType(unit->findProperty("role"));
		data.m_attr = m_syncfgAttr;

		parseServerAddr(
			unit,
			synconfigAddrName,
			ARRAY_LEN(synconfigAddrName),
			data);

		m_synconfigs.push_back(data);
	}
}

void CDeployConfig::parseSnmpInfo(CXMLNode *root)
{
	CXMLNode *services = getNode(root, "Services");

	CXMLNode *snmp = getNode(services, "snmpmanager");

	for (CXMLNode * unit = snmp->getSon(0);
		 unit != NULL;
		 unit = unit->getBrother())
	{
		parseSnmpUnit(unit);
	}
}

void CDeployConfig::parseSnmpUnit(CXMLNode *unit)
{
	if (!strcmp(unit->getName(), "Service"))
	{
		SnmpCfgInfo data;

		data.m_id = (unit->findProperty("id"));
		data.m_dc = transCenterFlag(unit->findProperty("center"));
		data.m_serverType = TransServerType(unit->findProperty("role"));

		parseServerAddr(unit, snmpAddrName, ARRAY_LEN(snmpAddrName), data);

		m_snmps.push_back(data);
	}
}

void CDeployConfig::parseFrontInfo(CXMLNode *root)
{
	CXMLNode *services = getNode(root, "Services");

	CXMLNode *front = getNode(services, "sysfront");

	for (CXMLNode * unit = front->getSon(0);
		 unit != NULL;
		 unit = unit->getBrother())
	{
		parseFrontUnit(unit);
	}
}

void CDeployConfig::parseFrontUnit(CXMLNode *unit)
{
	if (!strcmp(unit->getName(), "Service"))
	{
		SysfrontCfgInfo data;

		data.m_id = (unit->findProperty("id"));
		data.m_dc = transCenterFlag(unit->findProperty("center"));

		parseServerAddr(unit, frontAddrName, ARRAY_LEN(frontAddrName), data);

		m_fronts.push_back(data);
	}
}

void CDeployConfig::parseQueryInfo(CXMLNode *root)
{
	CXMLNode *services = getNode(root, "Services");

	CXMLNode *query = getNode(services, "sysquery");

	for (CXMLNode * unit = query->getSon(0);
		 unit != NULL;
		 unit = unit->getBrother())
	{
		parseQueryUnit(unit);
	}
}

void CDeployConfig::parseQueryUnit(CXMLNode *unit)
{
	if (!strcmp(unit->getName(), "Service"))
	{
		SysqueryCfgInfo data;

		data.m_id = (unit->findProperty("id"));
		data.m_dc = transCenterFlag(unit->findProperty("center"));

		parseServerAddr(unit, queryAddrName, ARRAY_LEN(queryAddrName), data);

		m_querys.push_back(data);
	}
}

void CDeployConfig::parseSlogInfo(CXMLNode *root)
{
	CXMLNode *services = getNode(root, "Services");

	CXMLNode *slog = getNode(services, "sysslog");

	for (CXMLNode * unit = slog->getSon(0);
		 unit != NULL;
		 unit = unit->getBrother())
	{
		parseSlogUnit(unit);
	}
}

void CDeployConfig::parseSlogUnit(CXMLNode *unit)
{
	if (!strcmp(unit->getName(), "Service"))
	{
		SysslogCfgInfo data;

		data.m_id = (unit->findProperty("id"));
		data.m_dc = transCenterFlag(unit->findProperty("center"));

		parseServerAddr(unit, slogAddrName, ARRAY_LEN(slogAddrName), data);

		m_slogs.push_back(data);
	}
}

void CDeployConfig::parseEventInfo(CXMLNode *root)
{
	CXMLNode *services = getNode(root, "Services");

	CXMLNode *event = getNode(services, "syseventcounter");

	for (CXMLNode * unit = event->getSon(0);
		 unit != NULL;
		 unit = unit->getBrother())
	{
		parseEventUnit(unit);
	}
}

void CDeployConfig::parseEventUnit(CXMLNode *unit)
{
	if (!strcmp(unit->getName(), "Service"))
	{
		SysEventCounterCfgInfo	data;

		data.m_id = (unit->findProperty("id"));
		data.m_dc = transCenterFlag(unit->findProperty("center"));

		parseServerAddr(unit, eventAddrName, ARRAY_LEN(eventAddrName), data);

		m_events.push_back(data);
	}
}

void CDeployConfig::parseAgentInfo(CXMLNode *root)
{
	CXMLNode *services = getNode(root, "Services");

	CXMLNode *agent = getNode(services, "sysagent");

	for (CXMLNode * unit = agent->getSon(0);
		 unit != NULL;
		 unit = unit->getBrother())
	{
		parseAgentUnit(unit);
	}
}

void CDeployConfig::parseAgentUnit(CXMLNode *unit)
{
	if (!strcmp(unit->getName(), "Service"))
	{
		SysAgentCfgInfo data;

		data.m_id = (unit->findProperty("id"));
		data.m_dc = transCenterFlag(unit->findProperty("center"));

		parseServerAddr(unit, agentAddrName, ARRAY_LEN(agentAddrName), data);

		m_agents.push_back(data);
	}
}

void CDeployConfig::parseFibProxyInfo(CXMLNode *root)
{
	CXMLNode *services = getNode(root, "Services");

	CXMLNode *event = getNode(services, "fibproxy");

	for (CXMLNode * unit = event->getSon(0);
		 unit != NULL;
		 unit = unit->getBrother())
	{
		parseFibProxyUnit(unit);
	}
}

void CDeployConfig::parseFibProxyUnit(CXMLNode *unit)
{
	if (!strcmp(unit->getName(), "Service"))
	{
		FibProxyCfgInfo data;

		data.m_id = (unit->findProperty("id"));
		data.m_dc = transCenterFlag(unit->findProperty("center"));

		parseServerAddr(
			unit,
			fibproxyAddrName,
			ARRAY_LEN(fibproxyAddrName),
			data);

		m_fibproxys.push_back(data);
	}
}

void CDeployConfig::parseFibFensInfo(CXMLNode *root)
{
	CXMLNode *services = getNode(root, "Services");

	CXMLNode *event = getNode(services, "fens");

	for (CXMLNode * unit = event->getSon(0);
		unit != NULL;
		unit = unit->getBrother())
	{
		parseFibProxyUnit(unit);
	}
}

void CDeployConfig::parseFibFensUnit(CXMLNode *unit)
{
	if (!strcmp(unit->getName(), "Service"))
	{
		FibFensCfgInfo data;

		data.m_id = (unit->findProperty("id"));
		data.m_dc = transCenterFlag(unit->findProperty("center"));

		parseServerAddr(
			unit,
			fibfensAddrName,
			ARRAY_LEN(fibfensAddrName),
			data);

		m_fibFens.push_back(data);
	}
}


void CDeployConfig::parseFibClientInfo(CXMLNode *root)
{
	CXMLNode *services = getNode(root, "Services");

	CXMLNode *event = getNode(services, "sysfibclient");

	for (CXMLNode * unit = event->getSon(0);
		 unit != NULL;
		 unit = unit->getBrother())
	{
		parseFibClientUnit(unit);
	}
}

void CDeployConfig::parseFibClientUnit(CXMLNode *unit)
{
	if (!strcmp(unit->getName(), "Service"))
	{
		SysFibClientCfgInfo data;

		data.m_id = (unit->findProperty("id"));
		data.m_dc = transCenterFlag(unit->findProperty("center"));

		parseServerAddr(
			unit,
			fibclientAddrName,
			ARRAY_LEN(fibclientAddrName),
			data);

		m_fibclients.push_back(data);
	}
}

void CDeployConfig::parseDBInfo(CXMLNode *root)
{
	CXMLNode *dbs = getNode(root, "Databases");

	for (CXMLNode * unit = dbs->getSon(0);
		 unit != NULL;
		 unit = unit->getBrother())
	{
		parseDBUnit(unit);
	}
}

void CDeployConfig::parseDBUnit(CXMLNode *unit)
{
	if (!strcmp(unit->getName(), "Database"))
	{
		DBCfgInfo data;

		data.m_id = (unit->findProperty("id"));
		data.m_dc = transCenterFlag(unit->findProperty("center"));

		data.m_dbname = unit->findProperty("dbname");
		data.m_ip = unit->findProperty("ip");
		data.m_port = unit->findProperty("port");
		data.m_username = unit->findProperty("username");
		data.m_pwd = unit->findProperty("password");

		m_dbs.push_back(data);
	}
}

/// �õ����÷��������������Ϣ
///@param	id ���÷����ID
///@return	ID��Ӧ���÷����������Ϣ
CDeployConfig::SynconfigCfgInfo CDeployConfig::GetSynconfigCfgInfo(string id)
throw(CRuntimeError)
{
	return findDataByID < CDeployConfig::SynconfigCfgInfo > (m_synconfigs, id);
}

/// �õ�SNMP���������������Ϣ
///@param	id SNMP�����ID
///@return	ID��ӦSNMP�����������Ϣ
CDeployConfig::SnmpCfgInfo CDeployConfig::GetSnmpCfgInfo(string id)
throw(CRuntimeError)
{
	return findDataByID < CDeployConfig::SnmpCfgInfo > (m_snmps, id);
}

/// �õ�ǰ�÷��������������Ϣ
///@param	id ǰ�÷����ID
///@return	ID��Ӧǰ�÷����������Ϣ
CDeployConfig::SysfrontCfgInfo CDeployConfig::GetSysfrontCfgInfo(string id)
throw(CRuntimeError)
{
	return findDataByID < CDeployConfig::SysfrontCfgInfo > (m_fronts, id);
}

/// �õ���ѯ���������������Ϣ
///@param	id ��ѯ�����ID
///@return	ID��Ӧ��ѯ�����������Ϣ
CDeployConfig::SysqueryCfgInfo CDeployConfig::GetSysqueryCfgInfo(string id)
throw(CRuntimeError)
{
	return findDataByID < CDeployConfig::SysqueryCfgInfo > (m_querys, id);
}

/// �õ���ѯ���������������Ϣ
///@param	id ��ѯ�����ID
///@return	ID��Ӧ��ѯ�����������Ϣ
CDeployConfig::SysslogCfgInfo CDeployConfig::GetSysslogCfgInfo(string id)
throw(CRuntimeError)
{
	return findDataByID < CDeployConfig::SysslogCfgInfo > (m_slogs, id);
}


/// �õ��¼�������������������Ϣ
///@param	id �¼���������ID
///@return	ID��Ӧ�¼���������������Ϣ
CDeployConfig::SysEventCounterCfgInfo CDeployConfig::GetSysEventCounterCfgInfo(
	string	id)
throw(CRuntimeError)
{
	return findDataByID < CDeployConfig::SysEventCounterCfgInfo > (m_events, id);
}

/// �õ�������������������Ϣ
///@param	id ��������ID
///@return	ID��Ӧ��������������Ϣ������Ҳ�����Ϣ����CRuntimeError�쳣
CDeployConfig::SysAgentCfgInfo CDeployConfig::GetSysAgentCfgInfo(string id)
throw(CRuntimeError)
{
	return findDataByID < CDeployConfig::SysAgentCfgInfo > (m_agents, id);
}

/// �õ�ҵ�񱨵����������������Ϣ
///@param	id ҵ�񱨵������ID
///@return	ID��Ӧҵ�񱨵������������Ϣ
CDeployConfig::FibProxyCfgInfo CDeployConfig::GetFibProxyCfgInfoCfgInfo(
	string	id)
throw(CRuntimeError)
{
	return findDataByID < CDeployConfig::FibProxyCfgInfo > (m_fibproxys, id);
}

/// �õ�ҵ�񱨵��ͻ����������������Ϣ
///@param	id ҵ�񱨵��ͻ������ID
///@return	ID��Ӧҵ�񱨵��ͻ������������Ϣ��
CDeployConfig::SysFibClientCfgInfo CDeployConfig::GetSysFibClientCfgInfo(
	string	id)
throw(CRuntimeError)
{
	return findDataByID < CDeployConfig::SysFibClientCfgInfo > (m_fibclients, id);
}

/// �õ����ݿ������������Ϣ
///@param	dc ���ݿ���������������
///@return	���ݿ��������Ϣ
CDeployConfig::DBCfgInfo CDeployConfig::GetDBCfgInfo(CDataCenterFlagType dc)
throw(CRuntimeError)
{
	for (vector<DBCfgInfo>::iterator it = m_dbs.begin();
		 it != m_dbs.end();
		 it++)
	{
		if (it->m_dc == dc)
		{
			return *it;
		}
	}

	char tmp[64];
	SNPRINTF(tmp, 64, "Can't find database by center(%c)", dc.getValue());

	throw new CRuntimeError(tmp, __FILE__, __LINE__);
}

CDataCenterFlagType CDeployConfig::TransCenterFlag(const char *center)
{
	assert(m_dcInfos.size() != 0 && "You should parse DeployConfig first!");

	CDataCenterFlagType rtn = DC_UnKnow;
	bool find = false;
	for (vector<dataCenterInfo>::iterator it = m_dcInfos.begin();
		 it != m_dcInfos.end();
		 it++)
	{
		for (vector<string>::iterator j = it->names.begin();
			 j != it->names.end();
			 j++)
		{
			if (!compareStringNoCase(center, j->c_str()))
			{
				rtn = it->type;
				find = true;
				break;
			}
		}

		if (find)
		{
			break;
		}
	}

	return rtn;
}
