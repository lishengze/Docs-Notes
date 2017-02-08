// DeployConfig.cpp: implementation of the CDeployConfig class.
//
// 20070828 �Ժ�� �޸��쳣�˳��ķ�ʽ
///20120511 ����   NT-0139 �ӿ���Ӧʱ�䣺������������������־���˱�־Ĭ��Ϊ1
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
			///������Ҫ��Topic��Serviceδ��SystemConfig�ж���
			return NULL;
		}
		m_CommConfigInfo.pszType = pSystemCommNode->findProperty("type");
		if (m_CommConfigInfo.pszType == NULL)
		{
			///������Ҫ��Topic��Service��Typeδ��SystemConfig�ж���
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
				//δָ��item ��ʾ����item������
				break;
			}
			m_CommConfigInfo.nItem = atoi(pszDeployItem);
			if (pszRequiredMethod == NULL)
			{
				//�ҵ���pDeployCommNode
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

		// �õ������������־
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
				///����δ�ҵ��������
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

