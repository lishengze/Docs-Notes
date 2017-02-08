///@file	configmanager.cpp
///@brief	实现了CConfigManager类,管理本系统的配置项
///@history
///20120731 魏诚创建该文件
/////////////////////////////////////////////////////////////////////////

#include "configmanager.h"
#include "PrjCommon.h"

// 应用进程名 - 进程所在分区 映射图
extern map<string, string>	g_mSpcPrcMap;	
extern char g_mAppBasePath[200];
extern const char  *XML_FILE_NAME;
extern char g_mAppListPath[200];

extern char g_mDumpOutput[200];	
extern char g_mLogFileName[200];
extern char g_mAppPathPrefix[200];	//应用工作目录的前缀

CConfigManager * CConfigManager::Instance()
{
	static CConfigManager oConfigManager;
	return &oConfigManager;
}

void CConfigManager::LoadXmlFile()
{
	CXMLDoc xmlConfig;
	try
	{
		xmlConfig.read((char *)XML_FILE_NAME);

		CXMLNode * pRoot = xmlConfig.getRootNode();
		
		CXMLNode * pTimerNode = pRoot->findNode(XMLTag, "Timers", NULL, NULL);
		CXMLNodeList *pTimerList = pTimerNode->getNodeList();

		for (CXMLNodeList::iterator pos = pTimerList->begin(); pos != pTimerList->end(); ++pos) 
		{
			CXMLNode *pNode = *pos;
			
			char *pName = pNode->findProperty("name");
			if(!pName)
			{
				printf("no name in Timers from %s\n", XML_FILE_NAME);
				exit(1);
			}
			
			char *pSeps = pNode->findProperty("seps");
			if (!pSeps)
			{
				printf("no seps in Timers for name:%s from %s\n", pName, XML_FILE_NAME);
				exit(1);
			}
			
			printf("Name [%s]  Seps [%d] in Timers\n", pName, atoi(pSeps));
			m_mSysAttrTimers[pName] = atoi(pSeps);
		}

		CXMLNode * pAttrDefineNode = pRoot->findNode(XMLTag, "AttrDefine", NULL, NULL);
		CXMLNodeList *pAttrList = pAttrDefineNode->getNodeList();

		for (CXMLNodeList::iterator pos = pAttrList->begin(); pos != pAttrList->end(); ++pos) 
		{
			CXMLNode *pNode = *pos;

			//获取指标名
			char *pAttrName = pNode->findProperty("name");
			if(!pAttrName)
			{
				printf("no name in Attr from %s\n", XML_FILE_NAME);
				exit(1);
			}

			CXMLNodeList *pAppList = pNode->getNodeList();
			for (CXMLNodeList::iterator apppos = pAppList->begin(); apppos != pAppList->end(); ++apppos) 
			{
				CXMLNode *pAppNode = *apppos;

				//获取应用名
				char *pAppName = pAppNode->findProperty("name");
				if(!pAppName)
				{
					printf("no name in app from %s\n", XML_FILE_NAME);
					exit(1);
				}
				
				printf("Name [%s]:[%s]  in app\n", pAttrName, pAppName);

				map<string, map<string, int> >::iterator a_it = m_mAppAttrList.find(pAppName);
				if(a_it == m_mAppAttrList.end())
				{
					map<string, int> attrmap;

					attrmap[pAttrName] = 1;
					m_mAppAttrList[pAppName] = attrmap;
				}
				else
				{
					a_it->second[pAttrName] = 1;
				}
			}
		}				
	} 
	catch (CParseError *pParseError)
	{
		printf("\nline=%d, error:%s\n", pParseError->getLineNo(), pParseError->getMsg());
		printf("Failed to read configuration file %s, quit.\n", XML_FILE_NAME);
		exit(-1);
	}
}

void CConfigManager::LoadServiceList(vector<string>& localiplist)
{
	FILE * fp = fopen((char *)g_mAppListPath, "r");
	if(!fp)
	{
		printf("Error: Can not open service file:%s\n", g_mAppListPath);
		return;
	}

	char szBuf[100] = {0};
	while ((fgets(szBuf, sizeof(szBuf)-1, fp))!=NULL)
	{
		int i=strlen(szBuf);          
		if(szBuf[i-1] == '\n')
		{
			szBuf[i-1] = '\0';
		}

		char * p = trim(szBuf);
		if(strlen(p) == 0)
		{
			continue;
		}

		if(p[0] == '#')
		{
			continue;
		}

		char centername[100];
		char appname[100];
		int appnum;
		char ip[100];

		sscanf(p, "%s %s %d %s", centername, appname, &appnum, ip);

		//判断当前配置是否关联本机
		bool bIsLocalIP = false;
		for(int i = 0; i < localiplist.size(); ++i)
		{
			if(localiplist[i].compare(ip) == 0)
			{
				bIsLocalIP = true;
				break;
			}
		}

		if(!bIsLocalIP)
		{
			memset(szBuf, 0x00, sizeof(szBuf));
			continue;
		}
		
		map<string, vector<int> >::iterator s_it = m_mServiceList.find(appname);
		if(s_it == m_mServiceList.end())
		{
			vector<int> idlist;
			idlist.push_back(appnum);

			m_mServiceList[appname] = idlist;
		}
		else
		{
			s_it->second.push_back(appnum);
		}

		//保存到特殊进程容器中
		char procname[100] = {0};
		char proclogpath[1024] = {0};
		
		SNPRINTF(procname, sizeof(procname), "%s%d", appname, appnum);
		SNPRINTF(proclogpath, sizeof(proclogpath), "%s%s%s%d/%s%s"
			, g_mAppBasePath, g_mAppPathPrefix, appname, appnum, g_mDumpOutput, g_mLogFileName);
		
		g_mSpcPrcMap[procname] = proclogpath;			

		memset(szBuf, 0x00, sizeof(szBuf));
	}

	fclose(fp);
}

void CConfigManager::LoadConfig(vector<string>& localIPList)
{
	LoadXmlFile();
	LoadServiceList(localIPList);
}

