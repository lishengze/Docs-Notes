// DeployConfig.cpp: implementation of the CDeployConfig class.
//
// 20070828 赵鸿昊 修改异常退出的方式
///20120511 江鹏   NT-0139 加快响应时间：给主题增加了自增标志，此标志默认为1
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "DeployConfig.h"

//////////////////////////////////////////////////////////////////////
CCommConfigIterator::CCommConfigIterator(const int nItemID, CXMLNode *pDeployCommsNode, 
		CXMLNode *pRequiredNode, CXMLNode *pSystemCommsNode,
		const char *pszType, const char *pszCommName)
{
	m_nCurrPosition = -1;
	m_nCurrItem = -1;

	m_nItemID = nItemID;
	m_pDeployCommsNode = pDeployCommsNode;
	m_pRequiredNode = pRequiredNode;
	m_pSystemCommsNode = pSystemCommsNode;
	m_pszType = pszType;
	m_pszCommName = pszCommName;
}

CCommConfigIterator::~CCommConfigIterator()
{
}

const TCommConfigInfo *CCommConfigIterator::Next()
{
	if(m_pDeployCommsNode==NULL || m_pRequiredNode==NULL || m_pSystemCommsNode==NULL)
	{
		return NULL;
	}
	
	for(;;)
	{
		if (m_nCurrItem < 0)
		{
			m_nCurrPosition++;
		}
		CXMLNode *pRequiredNode = m_pRequiredNode->getSon(m_nCurrPosition);
		if (pRequiredNode == NULL)
		{
			break;
		}
		char *pszRequiredCommName = pRequiredNode->findProperty("name");
		CXMLNode *pSystemCommNode = m_pSystemCommsNode->findNode(XMLTag,
			(char *)m_pszCommName,
			"name", pszRequiredCommName);
		if (pSystemCommNode == NULL)
		{
			///错误：需要的Topic或Service未在SystemConfig中定义
			return NULL;
		}
		m_CommConfigInfo.pszType = pSystemCommNode->findProperty("type");
		if (m_CommConfigInfo.pszType == NULL)
		{
			///错误：需要的Topic或Service的Type未在SystemConfig中定义
			return NULL;
		}
		if (m_pszType != NULL)
		{
			if (strcmp(m_CommConfigInfo.pszType, m_pszType) != 0)
			{
				continue;
			}
		}
		CXMLNode *pDeployCommNode = NULL;
		char *pszDeployItem = NULL;
		char *pszRequiredMethod = pRequiredNode->findProperty("method");
		for (;;)
		{
			m_nCurrItem++;
			pszDeployItem = NULL;
			pDeployCommNode = m_pDeployCommsNode->getSon(m_nCurrItem);
			if (pDeployCommNode == NULL)
			{
				m_nCurrItem = -1;
				break;;
			}
			char *pszDeployCommName = pDeployCommNode->findProperty("name");
			if (strcmp(pszRequiredCommName, pszDeployCommName) != 0)
			{
				continue;
			}
			
			pszDeployItem = pDeployCommNode->findProperty("item");
			if (pszDeployItem == NULL)
			{
				m_CommConfigInfo.nItem = 0;
				//未指定item 表示所有item都可用
				break;
			}
			m_CommConfigInfo.nItem = atoi(pszDeployItem);
			if (pszRequiredMethod == NULL)
			{
				//找到了pDeployCommNode
				break;
			}
			if(strcmp(pszRequiredMethod, "item") == 0)
			{
				if ( m_nItemID != 0 && m_CommConfigInfo.nItem != m_nItemID)
				{
					continue;
				}				
			}
			break;
		}
		if(pDeployCommNode == NULL)
		{
			continue;
		}

		// 得到主题号增长标志
		bool bIncFlag = true;
		char *pszIncFlag = pDeployCommNode->findProperty("inc");
			
		if (pszIncFlag != NULL)
		{
			bIncFlag = atoi(pszIncFlag);
		}

		if (strcmp(m_pszCommName, "Topic") == 0)
		{
			char *pszFind = pSystemCommNode->findProperty("id");
			if (pszFind == NULL)
			{
				///错误：未找到主题代码
				return NULL;
			}
			sscanf(pszFind,"%x", &(m_CommConfigInfo.dwSubjectID));
			if (pszDeployItem != NULL && bIncFlag)
			{
				m_CommConfigInfo.dwSubjectID += atoi(pszDeployItem);
			}
		}
		else
		{
				m_CommConfigInfo.dwSubjectID = 0;
		}

		m_CommConfigInfo.pszAddress = pDeployCommNode->findProperty("address");		

		return &m_CommConfigInfo;
	}
	return NULL;
}


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDeployConfig::CDeployConfig(const char *pszConfigPath)
{
	char temp[1000];
	sprintf(temp, "%s%s", pszConfigPath, "SystemConfig.xml");
	m_docSystemConfig.read(temp, 1);
	sprintf(temp, "%s%s", pszConfigPath, "DeployConfig.xml");
	m_docDeployConfig.read(temp, 1);
}

CDeployConfig::~CDeployConfig()
{

}

CCommConfigIterator CDeployConfig::GetSubscribeTopics(const char *pszAppName, 
													  const char *pszType,
													  const int nItemID)
{
	return GetComms("SubTopics", "Topics", "Topic", pszAppName, pszType, nItemID);
}

CCommConfigIterator CDeployConfig::GetPublishTopics(const char *pszAppName,
													const char *pszType,
													const int nItemID)
{
	return GetComms("PubTopics", "Topics", "Topic", pszAppName, pszType, nItemID);
}

CCommConfigIterator CDeployConfig::GetProvideServices(const char *pszAppName,
													  const char *pszType,
													  const int nItemID)
{
	return GetComms("ProServices", "Services", "Service", pszAppName, pszType, nItemID);
}

CCommConfigIterator CDeployConfig::GetUseServices(const char *pszAppName,
												  const char *pszType,
												  const int nItemID)
{
	return GetComms("UseServices", "Services", "Service", pszAppName, pszType, nItemID);
}

CCommConfigIterator CDeployConfig::GetComms(const char *pszTagName, 
		const char *pszCommGroupName, const char *pszCommName,
		const char *pszAppName, const char *pszType, const int nItemID)
{
	CXMLNode *pRequiredNode = NULL;  	
	CXMLNode *pDeployCommsNode = NULL;
	CXMLNode *pSystemCommsNode = NULL;

	CXMLNode *pSystemConfigRoot = m_docSystemConfig.getRootNode();
	if (pSystemConfigRoot == NULL)
	{
		EMERGENCY_EXIT("Can't find root from SystemConfig");
	}

	CXMLNode *pFind = pSystemConfigRoot->findNode(XMLTag, "Systems");
	if (pFind == NULL)
	{
		EMERGENCY_EXIT("Can't find [Systems] from SystemConfig");
	}
	
	pFind = pFind->findNode(XMLTag, "System", "name", (char *)pszAppName);
	if (pFind == NULL)
	{
		EMERGENCY_EXIT("Can't find application from SystemConfig");
	}

	pRequiredNode = pFind->findNode(XMLTag, (char *)pszTagName);

	pSystemCommsNode = pSystemConfigRoot->findNode(XMLTag, (char *)pszCommGroupName);

	CXMLNode *pDeployConfigRoot = m_docDeployConfig.getRootNode();
	if (pDeployConfigRoot == NULL)
	{
		EMERGENCY_EXIT("Can't find root from DeployConfig");
	}
	pDeployCommsNode = pDeployConfigRoot->findNode(XMLTag, (char *)pszCommGroupName);

	return CCommConfigIterator(nItemID, pDeployCommsNode, pRequiredNode, 
		pSystemCommsNode, pszType, pszCommName);
}

const TDBConfigInfo *CDeployConfig::GetDBConfig(const char *pszDBName)
{
	static TDBConfigInfo DBConfigInfo;
	CXMLNode *pDeployConfigRoot = m_docDeployConfig.getRootNode();
	if (pDeployConfigRoot == NULL)
	{
		EMERGENCY_EXIT("Can't find root from DeployConfig");
	}
	CXMLNode *pFind = pDeployConfigRoot->findNode(XMLTag, "Databases");
	if (pFind == NULL)
	{
		EMERGENCY_EXIT("Can't find Databases from DeployConfig");
	}

	pFind = pFind->findNode(XMLTag, "Database", "name", (char *)pszDBName);
	if (pFind == NULL)
	{
		return NULL;
	}
	DBConfigInfo.pszDatabaseName = pFind->findProperty("connectString");
	DBConfigInfo.pszUserName = pFind->findProperty("username");
	DBConfigInfo.pszPassword = pFind->findProperty("password");

	return &DBConfigInfo;
}

void CommConfigInfoOutput(const char *pszConfigName, const TCommConfigInfo *pCommConfigInfo)
{
	REPORT_EVENT(LOG_INFO, "Config", 
		"%s SubjectID=[%x] Item=[%d] Type=[%s] Address=[%s]", pszConfigName,
		pCommConfigInfo->dwSubjectID, pCommConfigInfo->nItem, 
		pCommConfigInfo->pszType, pCommConfigInfo->pszAddress);
}


#if 0

void CommConfigInfoOutput(const TCommConfigInfo *pCommConfigInfo)
{
	printf("%x %d %s %s\n", pCommConfigInfo->dwSubjectID, pCommConfigInfo->nItem,
		pCommConfigInfo->pszType, pCommConfigInfo->pszAddress);
}

int main()
{
	const char *pszAppName = "compositor";
	const int nItemID = 2;

	CDeployConfig DeployConfig("../../config/");

	const TCommConfigInfo *pCommConfigInfo = NULL;
	
	printf("GetSubscribeTopics: %s, %d\n", pszAppName, nItemID);
	CCommConfigIterator i =DeployConfig.GetSubscribeTopics(pszAppName, NULL, nItemID);
	while ((pCommConfigInfo = i.Next()) != NULL)
	{
		CommConfigInfoOutput(pCommConfigInfo);
	}

	printf("GetPublishTopics: %s, %d\n", pszAppName, nItemID);
	i =DeployConfig.GetPublishTopics(pszAppName, NULL, nItemID);
	while ((pCommConfigInfo = i.Next()) != NULL)
	{
		CommConfigInfoOutput(pCommConfigInfo);
	}
	
	printf("GetProvideServices: %s, %d\n", pszAppName, nItemID);
	i =DeployConfig.GetProvideServices(pszAppName, NULL, nItemID);
	while ((pCommConfigInfo = i.Next()) != NULL)
	{
		CommConfigInfoOutput(pCommConfigInfo);
	}
	
	printf("GetUseServices: %s, %d\n", pszAppName, nItemID);
	i =DeployConfig.GetUseServices(pszAppName, NULL, nItemID);
	while ((pCommConfigInfo = i.Next()) != NULL)
	{
		CommConfigInfoOutput(pCommConfigInfo);
	}
	return 0;
}
#endif

