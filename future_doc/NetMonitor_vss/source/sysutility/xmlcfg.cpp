/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	xmlcfg.cpp
///@brief	实现了读取XML配置文件共用的类和函数
///@history
///20080630	晏鹤春	创建该文件
///20090219	晏鹤春	SystemConfig.xml文件结构改变，主机配置项按系统域划分，解析方法作相应调整
/////////////////////////////////////////////////////////////////////////
#include "xmlcfg.h"

/// 获取Location串中的IP信息，如：从tcp://172.1.128.111:18800中取出172.1.128.111
/// 缓冲区长度由调用者保证
void getAddrByLocation(char *pAddress, char *pszLocation)
{
	char *p;

	char *q;
	p = strrchr(pszLocation, '/');
	q = strrchr(pszLocation, ':');
	if (p != NULL && q != NULL && q > p)
	{
		memcpy(pAddress, p + 1, q - p - 1);
	}
}

CXMLConfig::CXMLConfig(char *pszPathName)
{
	if (!pszPathName
	||	strlen(pszPathName) <= 0
	||	strlen(pszPathName) >=
			(MAX_FILENAME_LEN - strlen(XML_FILE_SYSTEM) - 1))
	{
		strcpy(m_szPathName, XML_DEFAULT_PATHNAME);
	}
	else
	{
		strcpy(m_szPathName, pszPathName);
		if (m_szPathName[strlen(m_szPathName) - 1] != '/')
		{
			sprintf(m_szPathName, "%s/", m_szPathName);
		}
	}

	sprintf(m_szSystemConfig, "%s", m_szPathName);
	strcat(m_szSystemConfig, XML_FILE_SYSTEM);
	sprintf(m_szDeployConfig, "%s", m_szPathName);
	strcat(m_szDeployConfig, XML_FILE_DEPLOY);

	LoadSystemConfig();
	LoadDeployConfig();
}

CXMLConfig::~CXMLConfig(void)
{
	if (m_pSystemCfgDoc)
	{
		delete m_pSystemCfgDoc;
		m_pSystemCfgDoc = NULL;
	}

	if (m_pDeployCfgDoc)
	{
		delete m_pDeployCfgDoc;
		m_pDeployCfgDoc = NULL;
	}
}

void CXMLConfig::LoadSystemConfig(void)
{
	m_pSystemCfgDoc = new CXMLDoc();
	try
	{
		m_pSystemCfgDoc->read(m_szSystemConfig);
		m_pSystemCfgRoot = m_pSystemCfgDoc->getRootNode();
	}

	catch(CParseError * e)
	{
		delete e;
		delete m_pSystemCfgDoc;
		m_pSystemCfgDoc = NULL;
		printf("XML: File %s explain failed!\n", m_szSystemConfig);
		fflush(stdout);
	}
}

void CXMLConfig::LoadDeployConfig(void)
{
	m_pDeployCfgDoc = new CXMLDoc();
	try
	{
		m_pDeployCfgDoc->read(m_szDeployConfig);
		m_pDeployCfgRoot = m_pDeployCfgDoc->getRootNode();
	}

	catch(CParseError * e)
	{
		delete e;
		delete m_pDeployCfgDoc;
		m_pDeployCfgDoc = NULL;
		printf("XML: File %s explain failed!\n", m_szDeployConfig);
		fflush(stdout);
	}
}

bool CXMLConfig::GetNodeProperty(
	CXMLNode *pNode,
	const char	*pszProperty,
	string	&sObject)
{
	if (pNode != NULL && pszProperty != NULL)
	{
		if (pNode->validNode(XMLTag, NULL, (char *)pszProperty, NULL))
		{
			sObject = pNode->findProperty((char *)pszProperty);
			return true;
		}
	}

	sObject = "";
	return false;
}

CXMLNode *CXMLConfig::GetServicesNode(void)
{
	if (!m_pDeployCfgRoot)
	{
		return NULL;
	}
	else
	{
		return m_pDeployCfgRoot->findNode(XMLTag, XML_TAG_SERVICES, NULL, NULL);
	}
}

CXMLNode *CXMLConfig::GetServiceNode(char *pszNodeTag)
{
	CXMLNode *pServicesNode = GetServicesNode();
	if (!pszNodeTag || !pServicesNode)
	{
		return NULL;
	}
	else
	{
		return pServicesNode->findNode(XMLTag, pszNodeTag, NULL, NULL);
	}
}

bool CXMLConfig::GetFrontMap(map<int, string> &frontMap)
{
	CXMLNode *pFrontNode = GetServiceNode(XML_TAG_SERVICES_FRONT);
	if (!pFrontNode)
	{
		return false;
	}

	getIntStringMap(frontMap, XML_PROP_ITEM, XML_PROP_ADDR, pFrontNode);
	return frontMap.size() ? true : false;
}

bool CXMLConfig::GetSnmpManagerMap(map<int, string> &managerMap)
{
	CXMLNode *pManagerNode = GetServiceNode(XML_TAG_SERVICES_SNMPMANAGER);
	if (!pManagerNode)
	{
		return false;
	}

	getIntStringMap(managerMap, XML_PROP_ITEM, XML_PROP_ADDR, pManagerNode);
	return managerMap.size() ? true : false;
}

bool CXMLConfig::GetFrontLocation(char *pszLocation, int iFrontID)
{
	if (!pszLocation || !iFrontID)
	{
		return false;
	}

	map<int, string> frontMap;
	map<int, string>::iterator	mapIt;
	if (GetFrontMap(frontMap))
	{
		mapIt = frontMap.find(iFrontID);
		if (mapIt != frontMap.end() && mapIt->second.size() < MAX_SRVNAME_LEN)
		{
			strcpy(pszLocation, mapIt->second.c_str());
			return true;
		}
	}

	return false;
}

bool CXMLConfig::GetServiceLocation(char *pszLocation, char *pszService)
{
	return GetServiceLocation(pszLocation, pszService, NULL, NULL);
}

bool CXMLConfig::GetServiceLocation(
	char *pszLocation,
	char *pszService,
	char *pszProp,
	char *pszValue)
{
	if (!pszLocation || !pszService)
	{
		return false;
	}

	CXMLNode *pServiceNode = GetServiceNode(pszService);
	if (!pServiceNode)
	{
		return false;
	}

	CXMLNode *pDstNode = pServiceNode->findNode(
			XMLTag,
			XML_TAG_SERVICE,
			pszProp,
			pszValue);
	if (!pDstNode
	||	strlen(pDstNode->findProperty(XML_PROP_ADDR)) > MAX_SRVNAME_LEN)
	{
		return false;
	}
	else
	{
		strcpy(pszLocation, pDstNode->findProperty(XML_PROP_ADDR));
		return true;
	}
}

bool CXMLConfig::GetEventCounterListener(
	char *pszAgentLocation,
	char *pszFrontLocation,
	char *pszProbeLocation)
{
	bool bRtn1;

	bool bRtn2;
	bRtn1 = GetServiceLocation(
			pszAgentLocation,
			XML_TAG_SERVICES_EVENTCOUNTER,
			XML_PROP_TYPE,
			XML_VAL_SERVICE_AGENT);
	bRtn2 = GetServiceLocation(
			pszFrontLocation,
			XML_TAG_SERVICES_EVENTCOUNTER,
			XML_PROP_TYPE,
			XML_VAL_SERVICE_FRONT);
	GetServiceLocation(
		pszProbeLocation,
		XML_TAG_SERVICES_EVENTCOUNTER,
		XML_PROP_TYPE,
		XML_VAL_SERVICE_PROBE);
	return (bRtn1 || bRtn2);
}

bool CXMLConfig::GetQueryLocation(char *pszLocation)
{
	return GetServiceLocation(pszLocation, XML_TAG_SERVICES_QUERY, NULL, NULL);
}

bool CXMLConfig::GetFibProxyLocation(list<string> &listLocations)
{
	listLocations.clear();

	CXMLNode *pServiceNode = GetServiceNode(XML_TAG_SERVICES_FIBPROXY);
	if (!pServiceNode)
	{
		return false;
	}

	CXMLNodeList *pNodeList = pServiceNode->getNodeList();
	CXMLNode *pNodeCur = NULL;
	for (int i = 0; i < pNodeList->size(); i++)
	{
		pNodeCur = (*pNodeList)[i];
		if (pNodeCur->findProperty(XML_PROP_ADDR))
		{
			listLocations.push_back(pNodeCur->findProperty(XML_PROP_ADDR));
		}
	}

	return listLocations.size() ? true : false;
}

bool CXMLConfig::GetFibClientLocation(char *pszLocation)
{
	return GetServiceLocation(
			pszLocation,
			XML_TAG_SERVICES_FIBCLIENT,
			XML_PROP_TYPE,
			XML_VAL_SERVICE_FRONT);
}

bool CXMLConfig::GetFibEventLocation(char *pszLocation)
{
	return GetServiceLocation(
			pszLocation,
			XML_TAG_SERVICES_FIBCLIENT,
			XML_PROP_TYPE,
			XML_VAL_SERVICE_EVENTCOUNTER);
}

void CXMLConfig::DropAgentProbeCfgList(list<CProbeConfig *> &probeList)
{
	list<CProbeConfig *>::iterator	iter;

	for (iter = probeList.begin(); iter != probeList.end(); iter++)
	{
		delete(*iter);
	}

	probeList.clear();
}

bool CXMLConfig::GetProbeConfigList(list<CProbeConfig *> &probeList)
{
	if (!m_pSystemCfgRoot)
	{
		return false;
	}

	CXMLNode *pProbeConfigNode = m_pSystemCfgRoot->findNode(
			XMLTag,
			XML_TAG_PROBECFG,
			NULL,
			NULL);
	if (!pProbeConfigNode)
	{
		return false;
	}

	CXMLNode *pCommonNode;

	CXMLNode *pSysCfgNode;

	CXMLNode *pProbeNode = NULL;
	pCommonNode = pProbeConfigNode->findNode(
			XMLTag,
			XML_TAG_COMMON,
			NULL,
			NULL);

	CXMLNodeList *pNodeList = pProbeConfigNode->getNodeList();
	for (int i = 0; pNodeList && i < pNodeList->size(); i++)
	{
		pSysCfgNode = (*pNodeList)[i];
		if (pSysCfgNode->validNode(
				XMLTag,
			XML_TAG_SYSTEM,
			XML_PROP_NAME,
			NULL)
	&&	strlen(pSysCfgNode->findProperty(XML_PROP_NAME)))
		{
			CXMLNodeList *pProbeNodeList = pSysCfgNode->getNodeList();
			for (int j = 0; pProbeNodeList && j < pProbeNodeList->size(); j++)
			{
				pProbeNode = (*pProbeNodeList)[j];
				if (pProbeNode->validNode(
						XMLTag,
					XML_TAG_PROBE,
					XML_PROP_NAME,
					NULL))
				{
					CProbeConfig *pProbeCfg = new CProbeConfig(
							pProbeNode,
							pSysCfgNode,
							pCommonNode);
					probeList.push_back(pProbeCfg);
				}
			}
		}
	}

	return probeList.size() ? true : false;
}

bool CXMLConfig::GetBNSList(list<CBNSInfo> &listInfo)
{
	if (!m_pSystemCfgRoot)
	{
		return NULL;
	}

	CXMLNode *pBNSConfigNode = m_pSystemCfgRoot->findNode(
			XMLTag,
			XML_TAG_BNSS,
			NULL,
			NULL);
	if (pBNSConfigNode == NULL)
	{
		return false;
	}

	CXMLNodeList *pNodeList = pBNSConfigNode->getNodeList();
	for (int i = 0; pNodeList && i < pNodeList->size(); i++)
	{
		CXMLNode *pBNSCfgNode = (*pNodeList)[i];
		if (pBNSCfgNode->validNode(XMLTag, NULL, XML_PROP_IP, NULL)
		&&	pBNSCfgNode->validNode(XMLTag, NULL, XML_PROP_PORT, NULL))
		{
			CBNSInfo info;
			GetNodeProperty(pBNSCfgNode, XML_PROP_IP, info.m_sServerIP);

			string	sPort;
			GetNodeProperty(pBNSCfgNode, XML_PROP_PORT, sPort);
			info.m_nPort = atoi(sPort.c_str());
			listInfo.push_back(info);
		}
	}

	return listInfo.size() > 0 ? true : false;
}

bool CXMLConfig::GetDBConnectStringList(list<CDBConnectString> &listInfo)
{
	if (!m_pSystemCfgRoot)
	{
		return NULL;
	}

	CXMLNode *pConfigNode = m_pSystemCfgRoot->findNode(
			XMLTag,
			XML_TAG_DATABASES,
			NULL,
			NULL);
	if (pConfigNode == NULL)
	{
		return false;
	}

	CXMLNodeList *pNodeList = pConfigNode->getNodeList();
	for (int i = 0; pNodeList && i < pNodeList->size(); i++)
	{
		CXMLNode *pCfgChildNode = (*pNodeList)[i];
		if (pCfgChildNode->validNode(XMLTag, NULL, XML_PROP_ALIAS, NULL)
		&&	pCfgChildNode->validNode(XMLTag, NULL, XML_PROP_ENV, NULL)
		&&	pCfgChildNode->validNode(XMLTag, NULL, XML_PROP_DBNAME, NULL)
		&&	pCfgChildNode->validNode(
				XMLTag,
			NULL,
			XML_PROP_RACNAME,
			NULL)
	&&	pCfgChildNode->validNode(
				XMLTag,
			NULL,
			XML_PROP_SERVICENAME,
			NULL))
		{
			CDBConnectString info;
			if (pCfgChildNode->validNode(XMLTag, NULL, XML_PROP_SYSTEM, NULL))
				GetNodeProperty(pCfgChildNode, XML_PROP_SYSTEM, info.m_sSystemName);
			if (pCfgChildNode->validNode(XMLTag, NULL, XML_PROP_DATACENTER, NULL))
				GetNodeProperty(pCfgChildNode, XML_PROP_DATACENTER, info.m_sCenterName);

			GetNodeProperty(pCfgChildNode, XML_PROP_ALIAS, info.m_sAlias);
			GetNodeProperty(pCfgChildNode, XML_PROP_ENV, info.m_sEnvironment);
			GetNodeProperty(pCfgChildNode, XML_PROP_DBNAME, info.m_sDBName);
			GetNodeProperty(pCfgChildNode, XML_PROP_USER, info.m_sUserName);
			GetNodeProperty(
				pCfgChildNode,
				XML_PROP_RACNAME,
				info.m_sRacServiceName);
			GetNodeProperty(
				pCfgChildNode,
				XML_PROP_SERVICENAME,
				info.m_sServiceName);
			GetNodeProperty(pCfgChildNode, XML_PROP_PSWD, info.m_sPassword);
			GetNodeProperty(
				pCfgChildNode,
				XML_PROP_TREEVIEW,
				info.m_sTreeViewFlag);
			GetNodeProperty(pCfgChildNode, XML_PROP_IP, info.m_sIpAddr);

			string	sPort;
			GetNodeProperty(pCfgChildNode, XML_PROP_PORT, sPort);
			info.m_nPort = atoi(sPort.c_str());
			listInfo.push_back(info);
		}
	}

	return listInfo.size() > 0 ? true : false;
}

CXMLNodeList *CXMLConfig::GetAgentsCfgNodeList(void)
{
	if (!m_pSystemCfgRoot)
	{
		return NULL;
	}

	CXMLNode *pAgentsConfigNode = m_pSystemCfgRoot->findNode(
			XMLTag,
			XML_TAG_AGENTS,
			NULL,
			NULL);
	return pAgentsConfigNode == NULL ? NULL : pAgentsConfigNode->getNodeList();
}

CXMLNode *CXMLConfig::GetAgentCfgNodeByName(char *pszAgentName)
{
	if (pszAgentName == NULL | strlen(pszAgentName) <= 0)
	{
		return false;
	}

	char szTmpName[64];

	// Added by Henchi, 20120320
	// AgentName 支持多对象名拼接以共用配置子节点列表，形如:"|1|2|3|"
	sprintf(szTmpName, "|%s|", pszAgentName);

	CXMLNodeList *pNodeList = GetAgentsCfgNodeList();
	for (int i = 0; pNodeList && i < pNodeList->size(); i++)
	{
		CXMLNode *pAgentCfgNode = (*pNodeList)[i];
		char *p = pAgentCfgNode->findProperty(XML_PROP_NAME);
		if (p != NULL
		&&	(strcmp(p, pszAgentName) == 0 || strstr(p, szTmpName) != NULL))
		{
			return pAgentCfgNode;
		}
	}

	return NULL;
}

bool CXMLConfig::GetAgentConnListByName(
	char *pszAgentName,
	list<CServerInfo> &listInfo)
{
	CXMLNode *pAgentCfgNode = GetAgentCfgNodeByName(pszAgentName);
	if (pAgentCfgNode != NULL)
	{
		CXMLNodeList *pChildNodeList = pAgentCfgNode->getNodeList();
		for (int i = 0; pChildNodeList && i < pChildNodeList->size(); i++)
		{
			CXMLNode *pChildNode = (*pChildNodeList)[i];
			if (pChildNode->validNode(XMLTag, NULL, XML_PROP_NAME, NULL)
			&&	pChildNode->validNode(XMLTag, NULL, XML_PROP_TYPE, NULL))
			{
				CServerInfo info;
				info.m_sName = pChildNode->findProperty(XML_PROP_NAME);
				info.m_sType = pChildNode->findProperty(XML_PROP_TYPE);
				if (strcmp(info.m_sType.c_str(), (char *)"sysagent") == 0)
				{
					info.m_sLocation = GetAgentLocationByName(
							(char *)info.m_sName.c_str());
				}
				else
				{
					CProbeConfig *Probe = GetProbeConfigN(
							(char *)info.m_sName.c_str());

					info.m_sLocation = Probe == NULL ? "" : Probe->GetLocation();
				}

				listInfo.push_back(info);
			}
		}
	}

	return listInfo.size() > 0 ? true : false;
}

char *CXMLConfig::GetAgentLocationByName(char *pszAgentName)
{
	static char szLocation[32];
	CXMLNode *pAgentCfgNode = GetAgentCfgNodeByName(pszAgentName);
	if (pAgentCfgNode != NULL
	&&	pAgentCfgNode->findProperty(XML_PROP_ADDR) != NULL)
	{
		strncpy(szLocation, pAgentCfgNode->findProperty(XML_PROP_ADDR), 31);
	}
	else
	{
		memset(szLocation, 0x00, 32);
	}

	return szLocation;
}

///Modify by Henchi 20090219, HostDataCenterMap由<DA-002, PuDian>改为<DA-002, NGES.PuDian>
bool CXMLConfig::GetHostDataCenterMap(map<string, string> &HostDataCenterMap)
{
	if (!m_pSystemCfgRoot)
	{
		return false;
	}

	CXMLNode *pProbeConfigNode = m_pSystemCfgRoot->findNode(
			XMLTag,
			XML_TAG_PROBECFG,
			NULL,
			NULL);
	if (!pProbeConfigNode)
	{
		return false;
	}

	CXMLNode *pCommonNode;

	CXMLNode *pSysCfgNode;

	CXMLNode *pProbeNode = NULL;
	pCommonNode = pProbeConfigNode->findNode(
			XMLTag,
			XML_TAG_COMMON,
			NULL,
			NULL);

	CXMLNodeList *pNodeList = pProbeConfigNode->getNodeList();
	for (int i = 0; pNodeList && i < pNodeList->size(); i++)
	{
		pSysCfgNode = (*pNodeList)[i];
		if (pSysCfgNode->validNode(
				XMLTag,
			XML_TAG_SYSTEM,
			XML_PROP_NAME,
			NULL)
	&&	strlen(pSysCfgNode->findProperty(XML_PROP_NAME)))
		{
			CXMLNodeList *pProbeNodeList = pSysCfgNode->getNodeList();
			for (int j = 0; pProbeNodeList && j < pProbeNodeList->size(); j++)
			{
				pProbeNode = (*pProbeNodeList)[j];
				if (pProbeNode->validNode(
						XMLTag,
					XML_TAG_PROBE,
					XML_PROP_NAME,
					NULL)
			&&	pProbeNode->findProperty(XML_PROP_DATACENTER)
				&&	strlen(
						pProbeNode->findProperty(XML_PROP_DATACENTER)) < MAX_SRVNAME_LEN
				&&	strlen(
						pProbeNode->findProperty(XML_PROP_NAME)) < MAX_SRVNAME_LEN)
				{
					char szTmp[MAX_SRVNAME_LEN];
					sprintf(
						szTmp,
						"%s.%s",
						pSysCfgNode->findProperty(XML_PROP_NAME),
						pProbeNode->findProperty(XML_PROP_DATACENTER));
					HostDataCenterMap[pProbeNode->findProperty(
							XML_PROP_HOSTNAME)] = szTmp;
				}
			}
		}
	}

	return HostDataCenterMap.size() ? true : false;
}

void CXMLConfig::DropLocationProbeMap(map<string, CProbeConfig *> &probeMap)
{
	map<string, CProbeConfig *>::iterator iter;

	for (iter = probeMap.begin(); iter != probeMap.end(); iter++)
	{
		delete iter->second;
	}

	probeMap.clear();
}

bool CXMLConfig::GetAttrTypeMap(map<string, int> &attrtypeMap)
{
	if (!m_pSystemCfgRoot)
	{
		return false;
	}

	CXMLNode *pAttrConfigNode = m_pSystemCfgRoot->findNode(
			XMLTag,
			XML_TAG_ATTRDEFINE,
			NULL,
			NULL);
	if (!pAttrConfigNode)
	{
		return false;
	}

	CXMLNodeList *pNodeList = pAttrConfigNode->getNodeList();
	for (int i = 0; i < pNodeList->size(); i++)
	{
		CXMLNode *pNodeCur = (*pNodeList)[i];
		if (pNodeCur->findProperty(XML_PROP_NAME)
		&&	strlen(pNodeCur->findProperty(XML_PROP_NAME))
		&&	pNodeCur->findProperty(XML_PROP_VALUETYPE)
		&&	strlen(pNodeCur->findProperty(XML_PROP_VALUETYPE)))
		{
			if (strcmp(
					pNodeCur->findProperty(XML_PROP_VALUETYPE),
				STRING_ATTR_DESC) == 0)
			{
				attrtypeMap[pNodeCur->findProperty(
						XML_PROP_NAME)] = STRING_ATTR;
			}
			else if (strcmp(
						 pNodeCur->findProperty(XML_PROP_VALUETYPE),
					 INT_ATTR_DESC) == 0)
			{
				attrtypeMap[pNodeCur->findProperty(XML_PROP_NAME)] = INT_ATTR;
			}
			else if (strcmp(
						 pNodeCur->findProperty(XML_PROP_VALUETYPE),
					 FLOAT_ATTR_DESC) == 0)
			{
				attrtypeMap[pNodeCur->findProperty(XML_PROP_NAME)] = FLOAT_ATTR;
			}
			else if (strcmp(
						 pNodeCur->findProperty(XML_PROP_VALUETYPE),
					 PERCENT_ATTR_DESC) == 0)
			{
				attrtypeMap[pNodeCur->findProperty(
						XML_PROP_NAME)] = PERCENT_ATTR;
			}
		}
	}

	return attrtypeMap.size() ? true : false;
}

bool CXMLConfig::GetAttrIntervalMap(map<string, int> &attrintervalMap)
{
	if (!m_pSystemCfgRoot)
	{
		return false;
	}

	XMLNodeType NodeType = XMLTag;
	CXMLNode *pAttrConfigNode = m_pSystemCfgRoot->findNode(
			NodeType,
			XML_TAG_ATTRDEFINE,
			NULL,
			NULL);
	if (!pAttrConfigNode)
	{
		return false;
	}

	CXMLNodeList *pNodeList = pAttrConfigNode->getNodeList();
	for (int i = 0; i < pNodeList->size(); i++)
	{
		CXMLNode *pNodeCur = (*pNodeList)[i];
		if (pNodeCur->findProperty(XML_PROP_NAME)
		&&	strlen(pNodeCur->findProperty(XML_PROP_NAME))
		&&	pNodeCur->findProperty(XML_PROP_INTERVAL)
		&&	strlen(pNodeCur->findProperty(XML_PROP_INTERVAL)))
		{
			attrintervalMap[pNodeCur->findProperty(XML_PROP_NAME)] = atoi(
					pNodeCur->findProperty(XML_PROP_INTERVAL));
		}
	}

	return attrintervalMap.size() ? true : false;
}

bool CXMLConfig::GetAttrAppMap(map<string, list<string> > &attrappMap)
{
	if (!m_pSystemCfgRoot)
	{
		return false;
	}

	CXMLNode *pAttrConfigNode = m_pSystemCfgRoot->findNode(
			XMLTag,
			XML_TAG_ATTRDEFINE,
			NULL,
			NULL);
	if (!pAttrConfigNode)
	{
		return false;
	}

	CXMLNodeList *pNodeList = pAttrConfigNode->getNodeList();
	for (int i = 0; i < pNodeList->size(); i++)
	{
		CXMLNode *pNodeCur = (*pNodeList)[i];	// <Attr name="MemoryDatabase" valueType="int" />
		if (pNodeCur->findProperty(XML_PROP_NAME)
		&&	strlen(pNodeCur->findProperty(XML_PROP_NAME)))
		{
			list<string> appList;
			CXMLNodeList *pChildNodeList = pNodeCur->getNodeList();
			for (int j = 0; pChildNodeList && j < pChildNodeList->size(); j++)
			{
				CXMLNode *pChildNodeCur = (*pChildNodeList)[j];
				char szTmp[64] = "";
				if (pChildNodeCur->findProperty(XML_PROP_NAME)
				&&	strlen(pChildNodeCur->findProperty(XML_PROP_NAME)))
				{
					sprintf(
						szTmp,
						"%s.%s",
						DATACENTERAPP,
						pChildNodeCur->findProperty(XML_PROP_NAME));
					appList.push_back(szTmp);
				}
			}

			attrappMap[pNodeCur->findProperty(XML_PROP_NAME)] = appList;
		}
	}

	return attrappMap.size() ? true : false;
}

bool CXMLConfig::GetAppList(
	int *piCenterID,
	string	&strCenterName,
	list<string> &appList,
	const char	*pszDataCenter,
	const char	*pszAppName)
{
	if (!m_pSystemCfgRoot || !pszDataCenter || !pszAppName)
	{
		return false;
	}

	CXMLNode *pDataCertersNode = m_pSystemCfgRoot->findNode(
			XMLTag,
			XML_TAG_DATACENTERS,
			NULL,
			NULL);
	if (!pDataCertersNode)
	{
		return false;
	}

	CXMLNode *pDataCerterNode = pDataCertersNode->findNode(
			XMLTag,
			XML_TAG_DATACENTER,
			XML_PROP_NAME,
			(char *)pszDataCenter);
	if (!pDataCerterNode)
	{
		return false;
	}

	if (pDataCerterNode->findProperty(XML_PROP_ID))
	{
		*piCenterID = atoi(pDataCerterNode->findProperty(XML_PROP_ID));
	}
	else
	{
		*piCenterID = 0;
	}

	if (pDataCerterNode->findProperty(XML_PROP_SYSNAME)
	&&	strlen(pDataCerterNode->findProperty(XML_PROP_SYSNAME)))
	{
		strCenterName = pDataCerterNode->findProperty(XML_PROP_SYSNAME);
	}
	else
	{
		strCenterName = "";
	}

	CXMLNodeList *pNodeList = pDataCerterNode->getNodeList();

	for (int i = 0; i < pNodeList->size(); i++)
	{
		CXMLNode *pNodeCur = (*pNodeList)[i];
		char *p = NULL;
		if (pNodeCur->findProperty(XML_PROP_NAME)
		&&	strcmp(pNodeCur->findProperty(XML_PROP_NAME), pszAppName) == 0)
		{
			p = pNodeCur->findProperty(XML_PROP_ITEM);
			if (p && strlen(p))
			{
				appList.push_back(p);
			}
		}
	}

	return appList.size() ? true : false;
}

///Modify by Henchi 20090219
CXMLConfig::CProbeConfig * CXMLConfig::GetProbeConfig
	(char *pszProp, char *pszValue)
{
	if (!pszProp || !pszValue || !m_pSystemCfgRoot)
	{
		return NULL;
	}

	CXMLNode *pProbeConfigNode = m_pSystemCfgRoot->findNode
		(XMLTag, XML_TAG_PROBECFG, NULL, NULL);
	if (!pProbeConfigNode)
	{
		return NULL;
	}

	CXMLNode *pCommonNode, *pSysCfgNode, *pProbeNode = NULL;
	pCommonNode = pProbeConfigNode->findNode(XMLTag, XML_TAG_COMMON, NULL, NULL);
	CXMLNodeList *pNodeList = pProbeConfigNode->getNodeList();
	for (int i = 0; pNodeList && i < pNodeList->size(); i++)
	{
		pSysCfgNode = (*pNodeList)[i];
		if (pSysCfgNode->validNode
				(XMLTag, XML_TAG_SYSTEM, XML_PROP_NAME, NULL)
		&&	strlen(pSysCfgNode->findProperty(XML_PROP_NAME)))
		{
			if ((
					pProbeNode = pSysCfgNode->findNode
					(XMLTag, XML_TAG_PROBE, pszProp, pszValue)
		))
			{
				break;
			}
		}
	}

	if (pProbeNode)
	{
		return new CProbeConfig(pProbeNode, pSysCfgNode, pCommonNode);
	}

	return NULL;
}

CXMLConfig::CProbeConfig * CXMLConfig::GetProbeConfigN (char *pszProbeName)
{
	return GetProbeConfig(XML_PROP_NAME, pszProbeName);
}

CXMLConfig::CProbeConfig * CXMLConfig::GetProbeConfigL (char *pszLocation)
{
	return GetProbeConfig(XML_PROP_ADDR, pszLocation);
}

///end
bool CXMLConfig::GetQueryDBInfo(CDBConnectString &DatabaseInfo)
{
	if (!m_pDeployCfgRoot)
	{
		return false;
	}

	CXMLNode *pDatabasesNode = m_pDeployCfgRoot->findNode(
			XMLTag,
			XML_TAG_DATABASES,
			NULL,
			NULL);
	if (!pDatabasesNode)
	{
		return false;
	}

	CXMLNode *pDBNode = pDatabasesNode->findNode(
			XMLTag,
			XML_TAG_DATABASE,
			XML_PROP_NAME,
			XML_VAL_SERVICE_QUERY);
	if (!pDBNode)
	{
		return false;
	}

	DatabaseInfo.m_sAlias = pDBNode->findProperty(XML_PROP_DBNAME);
	DatabaseInfo.m_sIpAddr = pDBNode->findProperty(XML_PROP_IP);
	DatabaseInfo.m_nPort = atoi(pDBNode->findProperty(XML_PROP_PORT));
	DatabaseInfo.m_sUserName = pDBNode->findProperty(XML_PROP_USER);
	DatabaseInfo.m_sPassword = pDBNode->findProperty(XML_PROP_PSWD);

	return true;
}

CXMLConfig::CProbeConfig::CProbeConfig(
	CXMLNode *pHostNode,
	CXMLNode *pSystemNode,
	CXMLNode *pCommonNode)
{
	if (!pHostNode || !pSystemNode)
	{
		return;
	}

	if (pCommonNode)
	{
		loadMaps(pCommonNode);
	}

	CXMLNode *pInterCfgNode = pSystemNode->findNode(
			XMLTag,
			XML_TAG_COMMON,
			NULL,
			NULL);
	if (pInterCfgNode)
	{
		loadMaps(pInterCfgNode);
	}

	m_pProbeNode = pHostNode;
	getPropValue(m_szSystem, XML_PROP_NAME, MAX_SRVNAME_LEN, pSystemNode);
	getPropValue(m_szSystemAlias, XML_PROP_ALIAS, MAX_SRVNAME_LEN, pSystemNode);

	// mod by Henchi, 20130508
	// 尝试获取系统环境名和角色名
	getPropValue(m_szHostName, XML_PROP_ENV, MAX_SRVNAME_LEN, pSystemNode);
	getPropValue(m_szHostAlias, XML_PROP_ROLE, MAX_SRVNAME_LEN, pSystemNode);
	if (strlen(m_szHostName) > 0 && 
		MAX_SRVNAME_LEN > strlen(m_szSystemAlias) + 
			strlen(m_szHostName) + strlen(m_szHostAlias)
		)
	{
		if (strlen(m_szHostAlias) > 0 )
		{
			sprintf(m_szHostName, "%s:%s", m_szHostName, m_szHostAlias);
		}
		sprintf(m_szSystemAlias, "%s(%s)", m_szSystemAlias, m_szHostName);
	}

	getPropValue(m_szProbeName, XML_PROP_NAME, MAX_SRVNAME_LEN, pHostNode);
	getPropValue(m_szLocation, XML_PROP_ADDR, MAX_SRVNAME_LEN, pHostNode);
	getPropValue(m_szHostName, XML_PROP_HOSTNAME, MAX_SRVNAME_LEN, pHostNode);
	getPropValue(m_szHostAlias, XML_PROP_ALIAS, MAX_SRVNAME_LEN, pHostNode);
	getPropValue(
		m_szDataCenter,
		XML_PROP_DATACENTER,
		MAX_SRVNAME_LEN,
		pHostNode);
	getPropValue(
		m_szTreeViewFlag,
		XML_PROP_TREEVIEW,
		MAX_SRVNAME_LEN,
		pHostNode);
	memset(m_szAddress, 0x00, sizeof(m_szAddress));
	getAddrByLocation(m_szAddress, m_szLocation);

	loadMaps(pHostNode);
}

void CXMLConfig::CProbeConfig::getPropValue(
	char *pszValue,
	char *pszProp,
	const int iMaxLen,
	CXMLNode *pNode)
{
	if (!pszValue || !pszProp || !iMaxLen || !pNode)	// 指针不合法
	{
		return;
	}

	char *pTemp = pNode->findProperty(pszProp);
	if (pTemp && (strlen(pTemp) < iMaxLen))				// 找到属性值且长度合法
	{
		strcpy(pszValue, pTemp);
	}
	else
	{
		*pszValue = 0x00;						// 否则标识为空字串
	}
}

void CXMLConfig::getIntStringMap(
	map<int, string> &dstMap,
	char *pszKeyProp,
	char *pszValueProp,
	CXMLNode *pNode)
{
	if (!pszKeyProp || !pszValueProp || !pNode) // 指针不合法
	{
		return;
	}

	CXMLNodeList *pNodeList = pNode->getNodeList();
	if (pNodeList)
	{
		CXMLNodeList::iterator	listIt;
		for (listIt = pNodeList->begin(); listIt != pNodeList->end(); listIt++)
		{
			if ((*listIt)->findProperty(pszKeyProp)
			&&	(*listIt)->findProperty(pszValueProp))
			{
				dstMap[atoi((*listIt)->findProperty(pszKeyProp))] = (*listIt)->findProperty(pszValueProp);
			}
		}
	}
}

void CXMLConfig::getStringMap(
	map<string, string> &dstMap,
	char *pszKeyProp,
	char *pszValueProp,
	CXMLNode *pNode)
{
	if (!pszKeyProp || !pszValueProp || !pNode) // 指针不合法
	{
		return;
	}

	CXMLNodeList *pNodeList = pNode->getNodeList();
	if (pNodeList)
	{
		CXMLNodeList::iterator	listIt;
		for (listIt = pNodeList->begin(); listIt != pNodeList->end(); listIt++)
		{
			if ((*listIt)->findProperty(pszKeyProp)
			&&	(*listIt)->findProperty(pszValueProp))
			{
				dstMap[(*listIt)->findProperty(pszKeyProp)] = (*listIt)->findProperty(pszValueProp);
			}
		}
	}
}

void CXMLConfig::getStringMap(
	map<string, string> &dstMap,
	char *pszKeyProp1,
	char *pszKeyProp2,
	char *pszValueProp,
	CXMLNode *pNode)
{
	if (!pszKeyProp1 || !pszKeyProp2 || !pszValueProp || !pNode)	// 指针不合法
	{
		return;
	}

	CXMLNodeList *pNodeList = pNode->getNodeList();
	if (pNodeList)
	{
		CXMLNodeList::iterator	listIt;
		char szTmp[MAX_SRVNAME_LEN] = "";
		for (listIt = pNodeList->begin(); listIt != pNodeList->end(); listIt++)
		{
			if (!(*listIt)->findProperty(pszKeyProp1))
			{
				continue;	// 未找到首要关键字，则检索下一记录
			}

			if ((*listIt)->findProperty(pszKeyProp2)
			&&	atoi((*listIt)->findProperty(pszKeyProp2)) > 0)
			{
				sprintf(
					szTmp,
					"%s.%d",
					(*listIt)->findProperty(pszKeyProp1),
					atoi((*listIt)->findProperty(pszKeyProp2)));
			}
			else
			{
				sprintf(szTmp, "%s", (*listIt)->findProperty(pszKeyProp1));
			}

			if ((*listIt)->findProperty(pszValueProp))
			{
				dstMap[szTmp] = (*listIt)->findProperty(pszValueProp);
			}
		}
	}
}

void CXMLConfig::NodeGetStringMap(
	map<string, string> &mapString,
	char *pszTagName,
	char *pszKeyPropName,
	char *pszValuePropName,
	CXMLNode *pNode)
{
	if (!pNode)
	{
		return;
	}

	CXMLNode *pCfgNode = pNode->findNode(XMLTag, pszTagName, NULL, NULL);
	if (pCfgNode)
	{
		getStringMap(mapString, pszKeyPropName, pszValuePropName, pCfgNode);
	}
}

void CXMLConfig::NodeGetStringMap(
	map<string, string> &mapString,
	char *pszTagName,
	char *pszKeyProp1,
	char *pszKeyProp2,
	char *pszValuePropName,
	CXMLNode *pNode)
{
	if (!pNode)
	{
		return;
	}

	CXMLNode *pCfgNode = pNode->findNode(XMLTag, pszTagName, NULL, NULL);
	if (pCfgNode)
	{
		getStringMap(
			mapString,
			pszKeyProp1,
			pszKeyProp2,
			pszValuePropName,
			pCfgNode);
	}
}

void CXMLConfig::NodeGetDBStringMap(
	map<string, CDBConnectString> &mapDBConnect,
	char *pszTagName,
	char *pszKeyProp,
	char *pszPropName,
	char *pszPropIP,
	char *pszPropUser,
	char *pszPropPswd,
	char *pszIntPort,
	CXMLNode *pNode)
{
	if (!pNode)
	{
		return;
	}

	CXMLNode *pCfgNode = pNode->findNode(XMLTag, pszTagName, NULL, NULL);
	if (pCfgNode)
	{
		CXMLNodeList *pNodeList = pCfgNode->getNodeList();
		for (int i = 0; i < pNodeList->size(); i++)
		{
			CXMLNode *pNodeCur = (*pNodeList)[i];
			CDBConnectString DBInfo;
			string	strName;
			if (pNodeCur->findProperty(XML_PROP_NAME))
			{
				if (pszKeyProp != NULL)
				{
					GetNodeProperty(pNodeCur, pszKeyProp, strName);
				}

				if (pszPropName != NULL)
				{
					GetNodeProperty(pNodeCur, pszPropName, DBInfo.m_sAlias);
				}

				if (pszPropIP != NULL)
				{
					GetNodeProperty(pNodeCur, pszPropIP, DBInfo.m_sIpAddr);
				}

				if (pszPropUser != NULL)
				{
					GetNodeProperty(pNodeCur, pszPropUser, DBInfo.m_sUserName);
				}

				if (pszPropPswd != NULL)
				{
					GetNodeProperty(pNodeCur, pszPropPswd, DBInfo.m_sPassword);
				}

				DBInfo.m_nPort = (pszIntPort == NULL) ? 0 : atoi(
						pNodeCur->findProperty(pszIntPort));
				mapDBConnect[strName] = DBInfo;
			}
		}
	}
}

void CXMLConfig::NodeGetDBStringMapS(
	map<string, CDBConnectString> &mapDBConnect,
	char *pszTagName,
	char *pszKeyProp,
	char *pszPropName,
	char *pszPropIP,
	char *pszPropUser,
	char *pszPropPswd,
	char *pszPropEnv,
	CXMLNode *pNode)
{
	if (!pNode)
	{
		return;
	}

	CXMLNode *pCfgNode = pNode->findNode(XMLTag, pszTagName, NULL, NULL);
	if (pCfgNode)
	{
		CXMLNodeList *pNodeList = pCfgNode->getNodeList();
		for (int i = 0; i < pNodeList->size(); i++)
		{
			CXMLNode *pNodeCur = (*pNodeList)[i];
			CDBConnectString DBInfo;
			string	strName;
			if (pNodeCur->findProperty(XML_PROP_NAME))
			{
				if (pszKeyProp != NULL)
				{
					GetNodeProperty(pNodeCur, pszKeyProp, strName);
				}

				if (pszPropName != NULL)
				{
					GetNodeProperty(pNodeCur, pszPropName, DBInfo.m_sAlias);
				}

				if (pszPropIP != NULL)
				{
					GetNodeProperty(pNodeCur, pszPropIP, DBInfo.m_sIpAddr);
				}

				if (pszPropUser != NULL)
				{
					GetNodeProperty(pNodeCur, pszPropUser, DBInfo.m_sUserName);
				}

				if (pszPropPswd != NULL)
				{
					GetNodeProperty(pNodeCur, pszPropPswd, DBInfo.m_sPassword);
				}

				if (pszPropEnv != NULL)
				{
					GetNodeProperty(
						pNodeCur,
						pszPropEnv,
						DBInfo.m_sEnvironment);
				}

				mapDBConnect[strName] = DBInfo;
			}
		}
	}
}

void CXMLConfig::CProbeConfig::loadMaps(CXMLNode *pHostNode)
{
	CXMLNode *pNode = NULL;

	CXMLConfig::NodeGetStringMap(
			m_timerMap,
			XML_TAG_TIMERS,
			XML_PROP_NAME,
			XML_PROP_SEPS,
			pHostNode);
	CXMLConfig::NodeGetStringMap(
			m_configMap,
			XML_TAG_CONFIGFILES,
			XML_PROP_NAME,
			XML_PROP_PATH,
			pHostNode);
	CXMLConfig::NodeGetStringMap(
			m_applogMap,
			XML_TAG_APPSYSLOGS,
			XML_PROP_NAME,
			XML_PROP_ITEM,
			XML_PROP_PATH,
			pHostNode);
	CXMLConfig::NodeGetStringMap(
			m_apppathMap,
			XML_TAG_APPSYSLOGS,
			XML_PROP_NAME,
			XML_PROP_ITEM,
			XML_PROP_ROOT,
			pHostNode);
	CXMLConfig::NodeGetStringMap(
			m_syslogMap,
			XML_TAG_SYSTEMLOG,
			XML_PROP_NAME,
			XML_PROP_PATH,
			pHostNode);
	CXMLConfig::NodeGetStringMap(
			m_keyfileMap,
			XML_TAG_KEYFILE,
			XML_PROP_NAME,
			XML_PROP_PATH,
			pHostNode);

	/// Added by Henchi, 20130509
	/// @@@ 临时性关闭非"TRADE"系统的Slog信息,以约束数据流量
	
	/// Mod by Henchi, 20150911
	/// 放开非“TRADE”系统的Slog
	//if (strcmp(m_szSystem, "TRADE") == 0)
	{
		CXMLConfig::NodeGetStringMap(
			m_sessionMap,
			XML_TAG_SESSIONLOG,
			XML_PROP_NAME,
			XML_PROP_PATH,
			pHostNode);
	}
	CXMLConfig::NodeGetStringMap(
			m_dfmtMap,
			XML_TAG_DFMTLOG,
			XML_PROP_NAME,
			XML_PROP_PATH,
			pHostNode);
	CXMLConfig::NodeGetStringMap(
			m_dbmappingMap,
			XML_TAG_DBMAPPING,
			XML_PROP_NAME,
			XML_PROP_DATABASE,
			pHostNode);

	CXMLConfig::NodeGetDBStringMap(
			m_tomcatMap,
			XML_TAG_TOMCATS,
			XML_PROP_NAME,
			XML_PROP_NAME,
			XML_PROP_IP,
			XML_PROP_SYSNAME,
			XML_PROP_DATACENTER,
			XML_PROP_PORT,
			pHostNode);
	CXMLConfig::NodeGetDBStringMap(
			m_filecodeMap,
			XML_TAG_WEBSITES,
			XML_PROP_NAME,
			XML_PROP_NAME,
			XML_PROP_SEPS,
			XML_PROP_PATH,
			NULL,
			NULL,
			pHostNode);
	CXMLConfig::NodeGetDBStringMap(
			m_websitecodeMap,
			XML_TAG_WEBSITECODE,
			XML_PROP_NAME,
			XML_PROP_NAME,
			XML_PROP_SEPS,
			XML_PROP_URL,
			XML_PROP_CODE,
			NULL,
			pHostNode);
	CXMLConfig::NodeGetDBStringMap(
			m_accesslogMap,
			XML_TAG_ACCESSLOG,
			XML_PROP_NAME,
			XML_PROP_NAME,
			XML_PROP_PATH,
			XML_PROP_SEPS,
			XML_PROP_INTERVAL,
			NULL,
			pHostNode);
	CXMLConfig::NodeGetDBStringMap(
			m_sanMap,
			XML_TAG_SANS,
			XML_PROP_NAME,
			XML_PROP_NAME,
			XML_PROP_SEPS,
			XML_PROP_PATH,
			NULL,
			NULL,
			pHostNode);
	CXMLConfig::NodeGetDBStringMap(
			m_saneventMap,
			XML_TAG_SANEVENTSERVER,
			XML_PROP_NAME,
			XML_PROP_NAME,
			XML_PROP_SEPS,
			XML_PROP_PATH,
			NULL,
			NULL,
			pHostNode);
	CXMLConfig::NodeGetDBStringMapS(
			m_AppSPMap,
			XML_TAG_APPSPS,
			XML_PROP_NAME,
			XML_PROP_DATABASE,
			XML_PROP_SEPS,
			XML_PROP_NAME,
			XML_PROP_TYPE,
			XML_PROP_SYSNAME,
			pHostNode);
	CXMLConfig::NodeGetDBStringMapS(
			m_NodeSPMap,
			XML_TAG_NODESPS,
			XML_PROP_NAME,
			XML_PROP_DATABASE,
			XML_PROP_SEPS,
			XML_PROP_NAME,
			XML_PROP_TYPE,
			XML_PROP_SYSNAME,
			pHostNode);
	CXMLConfig::NodeGetDBStringMapS(
			m_DBSPMap,
			XML_TAG_DBSPS,
			XML_PROP_NAME,
			XML_PROP_DATABASE,
			XML_PROP_SEPS,
			XML_PROP_NAME,
			XML_PROP_TYPE,
			XML_PROP_SYSNAME,
			pHostNode);
	CXMLConfig::NodeGetDBStringMapS(
			m_dblogMap,
			XML_TAG_DBLOGS,
			XML_PROP_NAME,
			XML_PROP_DATABASE,
			XML_PROP_SEPS,
			XML_PROP_NAME,
			NULL,
			XML_PROP_SYSNAME,
			pHostNode);

	pNode = pHostNode->findNode(XMLTag, XML_TAG_ATTRS, NULL, NULL); // 加载数据库监控指标配置
	if (pNode)
	{
		CXMLNodeList *pNodeList = pNode->getNodeList();
		for (int i = 0; i < pNodeList->size(); i++)
		{
			string	strName;
			string	strSystem;
			string	strTimer;
			list<CTableDBRelation>	tableinfoList;
			CXMLNodeList *pChildNodeList = NULL;
			CXMLNode *pNodeCur = (*pNodeList)[i];
			if (pNodeCur && pNodeCur->findProperty(XML_PROP_NAME))
			{
				pChildNodeList = pNodeCur->getNodeList();
			}
			else
			{
				continue;
			}

			strName = pNodeCur->findProperty(XML_PROP_NAME);
			if (pNodeCur->findProperty(XML_PROP_SYSNAME))
			{
				strSystem = pNodeCur->findProperty(XML_PROP_SYSNAME);
			}
			else
			{
				strSystem = "";
			}

			if (pNodeCur->findProperty(XML_PROP_SEPS))
			{
				strTimer = pNodeCur->findProperty(XML_PROP_SEPS);
			}
			else
			{
				strTimer = "";
			}

			for (int j = 0; pChildNodeList && j < pChildNodeList->size(); j++)
			{
				CXMLNode *pChildNodeCur = (*pChildNodeList)[j];
				CTableDBRelation TableInfo;

				if (pChildNodeCur->findProperty(XML_PROP_NAME))
				{
					TableInfo.m_sTableName = pChildNodeCur->findProperty(
							XML_PROP_NAME);
				}

				if (pChildNodeCur->findProperty(XML_PROP_DATABASE))
				{
					TableInfo.m_sDbName = pChildNodeCur->findProperty(
							XML_PROP_DATABASE);
				}

				tableinfoList.push_back(TableInfo);
			}

			if (strSystem.length() > 0 && strName.length() > 0)
			{
				char szName[64 + 1];
				sprintf(szName, "%s:%s", strSystem.c_str(), strName.c_str());
				strName = szName;
			}

			m_attrMap[strName] = tableinfoList;						// 监控指标名与数据库表单的映射
			m_attrtimerMap[strName] = strTimer;						// 监控指标名与其采样定时器配置的映射
		}
	}
}

bool CXMLConfig::CProbeConfig::SetDBConnectString(
	const char	*pszAlias,
	CDBConnectString *pDBConnect,
	CXMLNode *pProbeNode)
{
	bool bFlag = true;
	char szPort[8] = "";
	if (!pszAlias || !pDBConnect || !pProbeNode)
	{
		return false;
	}

	CXMLNode *pDatabasesNode = pProbeNode->findNode(
			XMLTag,
			XML_TAG_DATABASES,
			NULL,
			NULL);
	if (!pDatabasesNode)
	{
		return false;
	}

	CXMLNode *pDatabase = pDatabasesNode->findNode(
			XMLTag,
			XML_TAG_DATABASE,
			XML_PROP_NAME,
			(char *)pszAlias);
	if (!pDatabasesNode)
	{
		return false;
	}

	bFlag &= pDatabase->setProperty(
			XML_PROP_DBNAME,
			(char *)((*pDBConnect).m_sAlias.c_str()));
	bFlag &= pDatabase->setProperty(
			XML_PROP_IP,
			(char *)((*pDBConnect).m_sIpAddr.c_str()));
	sprintf(szPort, "%d", (*pDBConnect).m_nPort);
	bFlag &= pDatabase->setProperty(XML_PROP_PORT, szPort);
	bFlag &= pDatabase->setProperty(
			XML_PROP_USER,
			(char *)((*pDBConnect).m_sUserName.c_str()));
	bFlag &= pDatabase->setProperty(
			XML_PROP_PSWD,
			(char *)((*pDBConnect).m_sPassword.c_str()));
	return bFlag;
}

CXMLConfig::CProbeConfig::~CProbeConfig(void)
{
}
