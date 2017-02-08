/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	CSysLogConfig.cpp
///@brief	实现了CSysLogConfig类
///@history
///20110705 魏诚创建该文件
/////////////////////////////////////////////////////////////////////////
#include "CSysLogConfig.h"
#include "CGetTransFiberDevice.h"
#include "CXML.h"

extern map<string, list<string> > g_mapDeviceCMDS;
extern map<string, CTransFibertConfig> g_mapTransFiberConfig;
extern map<string, list<string> > g_mapDeviceIfs;
extern list<string> g_devlist;
extern list<string> g_srxdevlit;
extern list<string> g_syslogsubwordslist;

CSysLogConfigManager *CSysLogConfigManager::Instance(void)
{
	static CSysLogConfigManager oSysLogConfigManager;
	return &oSysLogConfigManager;
}

int CSysLogConfigManager::LoadConfig(std::string filename)
{
	m_sFileName = filename;

	CXMLDoc *pCfgDoc = new CXMLDoc();

	try
	{
		pCfgDoc->read((char *)filename.c_str());

		CXMLNode *pCfgRoot = pCfgDoc->getRootNode();
		if (!pCfgRoot)
		{
			printf("no root node in cfg %s\n", filename.c_str());
			delete pCfgDoc;
			return -1;
		}

		char *str = NULL;
		XMLNodeType NodeType = XMLTag;

		//TransFiberAttrIfsIndex info
		CXMLNode *pFiberConfig = pCfgRoot->findNode(
			NodeType,
			"TransFiberAttrIfsIndex",
			NULL,
			NULL);
		if (pFiberConfig == NULL)
		{
			printf(
				"Can not find <TransFiberAttrIfsIndex> in file %s\n",
				filename.c_str());
		}
		else
		{
			CXMLNodeList *pNodeList = pFiberConfig->getNodeList();
			if (pNodeList != NULL)
			{
				for (int i = 0; i < pNodeList->size(); i++)
				{
					CXMLNode *pCurrentNode = (*pNodeList)[i];
					str = pCurrentNode->findProperty("IP");
					if (!str)
					{
						printf("No IP!\n");
						continue;
					}
					CTransFibertConfig tf_config;
					tf_config.ip = str;

					str = pCurrentNode->findProperty("Locate");
					if (!str)
					{
						printf("No command for ip:%s!\n", str);
						continue;
					}
					tf_config.locate = str;

					str = pCurrentNode->findProperty("Range_mast");
					if (!str)
					{
						printf("No command for ip:%s!\n", str);
						continue;
					}
					tf_config.rang_m = str;

					str = pCurrentNode->findProperty("Range_slave");
					if (!str)
					{
						printf("No command for ip:%s!\n", str);
						continue;
					}
					tf_config.rang_s = str;

					//onenode
					CXMLNodeList *pOneNodeList = pCurrentNode->getNodeList();
					if (pOneNodeList)
					{
						for (int j = 0; j < pOneNodeList->size(); ++j)
						{

							CXMLNode *pOneNodeCur = (*pOneNodeList)[j];

							str = pOneNodeCur->findProperty("Indexs");
							if (!str)
							{
								printf("No index!\n");
								continue;
							}
							else
							{
								if( strlen(str)>0 )
								{
									char *p = strtok(str, ",");
									if( p!= NULL )
									{
										tf_config.in_list[j].push_back(p);
										while ((p = strtok(NULL, ",")) != NULL)
										{
											tf_config.in_list[j].push_back(p);
										}
									}
								}
								else
								{
									printf("idnexs length=[%d] is null.\n",strlen(str));
								}
							}

							str = pOneNodeCur->findProperty("Number");
							if( !str )
							{
								printf("No Number infor!\n");
								continue;
							}
							else
							{
								char *p = strtok(str, ",");
								if( p!= NULL )
								{
									tf_config.in_Number[j].push_back(p);
									while ((p = strtok(NULL, ",")) != NULL)
									{
										tf_config.in_Number[j].push_back(p);
									}
								}
							}
						}
					}
					g_mapTransFiberConfig[ tf_config.ip ] = tf_config;
				}
			}
		}

		//DeviceNOCommand info
		CXMLNode *pIPCommands = pCfgRoot->findNode(
				NodeType,
				"DeviceNOCommand",
				NULL,
				NULL);
		if (pIPCommands == NULL)
		{
			printf(
				"Can not find <DeviceNOCommand> in file %s\n",
				filename.c_str());
		}
		else
		{
			CXMLNodeList *pNodeList = pIPCommands->getNodeList();
			if (pNodeList != NULL)
			{
				for (int i = 0; i < pNodeList->size(); i++)
				{
					CXMLNode *pCurrentNode = (*pNodeList)[i];
					str = pCurrentNode->findProperty("IP");
					if (!str)
					{
						printf("No IP!\n");
						continue;
					}

					string	cmds = pCurrentNode->findProperty("Commands");
					if (cmds.length() == 0)
					{
						printf("No command for ip:%s!\n", str);
						continue;
					}

					char *p = strtok((char *)cmds.c_str(), ",");
					g_mapDeviceCMDS[str].push_back(p);
					while ((p = strtok(NULL, ",")) != NULL)
					{
						g_mapDeviceCMDS[str].push_back(p);
					}

					//g_mapDeviceCMDS[ str ] = cmds;
				}
			}
		}

		//2013.06.17 by Lee 增加设备端口丢包统计过程中忽略的端口
		//DeviceInterfaceIgnore info
		CXMLNode *pIPIfs = pCfgRoot->findNode(
				NodeType,
				"DeviceInterfaceIgnore",
				NULL,
				NULL);
		if (pIPIfs == NULL)
		{
			printf(
				"Can not find <DeviceInterfaceIgnore> in file %s\n",
				filename.c_str());
		}
		else
		{
			CXMLNodeList *pNodeList = pIPIfs->getNodeList();
			if (pNodeList != NULL)
			{
				for (int i = 0; i < pNodeList->size(); i++)
				{
					CXMLNode *pCurrentNode = (*pNodeList)[i];
					str = pCurrentNode->findProperty("IP");
					if (!str)
					{
						printf("No IP in DeviceInterfaceIgnore segment!\n");
						continue;
					}

					string	cmds = pCurrentNode->findProperty("Interfaces");
					if (cmds.length() == 0)
					{
						printf("No Interfaces for ip:%s!\n", str);
						continue;
					}

					char *p = strtok((char *)cmds.c_str(), ",");
					g_mapDeviceIfs[str].push_back(p);
					while ((p = strtok(NULL, ",")) != NULL)
					{
						g_mapDeviceIfs[str].push_back(p);
					}
				}
			}
		}

		//IPList info
		CXMLNode *pIPListNode = pCfgRoot->findNode(
				NodeType,
				"IPList",
				NULL,
				NULL);
		if (pIPListNode == NULL)
		{
			printf("Can not find <IPList> in file %s\n", filename.c_str());
		}
		else
		{
			CXMLNodeList *pIPNodeList = pIPListNode->getNodeList();
			if (pIPNodeList != NULL)
			{
				for (int i = 0; i < pIPNodeList->size(); ++i)
				{
					CXMLNode *pOneNodeCur = (*pIPNodeList)[i];

					str = pOneNodeCur->findProperty("IP");
					if (!str)
					{
						printf("No IP!\n");
						continue;
					}

					string	level = pOneNodeCur->findProperty("Level");
					if (level.length() == 0)
					{
						printf("No level for ip:%s!\n", str);
						continue;
					}
					int i_level = atoi(level.c_str());
					if( i_level <= 0 )
					{
						//骨干设备集合
						m_devices.push_back(str);
					}
					else
					{
						//生产网设备集合
						m_mapIPS[str] = i_level;
					}
				}
			}
		}

		//companyinfo
		CXMLNode *pCompanyNode = pCfgRoot->findNode(
				NodeType,
				"companyinfo",
				NULL,
				NULL);
		if (pCompanyNode == NULL)
		{
			printf("Can not find <companyinfo> in file %s\n", filename.c_str());
		}
		else
		{
			CXMLNodeList *pCompanyNodeList = pCompanyNode->getNodeList();
			if (pCompanyNodeList != NULL)
			{
				for (int i = 0; i < pCompanyNodeList->size(); ++i)
				{
					CXMLNode *pOneNodeCur = (*pCompanyNodeList)[i];

					int companyname;
					str = pOneNodeCur->findProperty("name");
					if (!str)
					{
						printf("No name!\n");
						delete pCfgDoc;
						return -1;
					}
					else
					{
						companyname = atoi(str);
					}

					str = pOneNodeCur->findProperty("infostart");
					if (!str)
					{
						printf("No infostart!\n");
						delete pCfgDoc;
						return -1;
					}
					else
					{
						m_mInfoStart[companyname] = atoi(str);
					}
				}
			}
		}

		//configinfo
		CXMLNode *pConfigNode = pCfgRoot->findNode(
				NodeType,
				"configinfos",
				NULL,
				NULL);
		if (pConfigNode)
		{
			CXMLNodeList *pConfigNodeList = pConfigNode->getNodeList();
			if (pConfigNodeList)
			{
				for (int i = 0; i < pConfigNodeList->size(); i++)
				{
					CSysLogConfigInfo configinfo;

					//configinfo
					CXMLNode *pNodeCur = (*pConfigNodeList)[i];

					str = pNodeCur->findProperty("devicetype");
					if (!str)
					{
						printf("No devicetype!\n");
						configinfo.m_sDeviceType = "";
					}
					else
					{
						configinfo.m_sDeviceType = str;
					}

					str = pNodeCur->findProperty("companytype");
					if (!str)
					{
						printf("No companytype!\n");
						configinfo.m_sCompanyType = "";
					}
					else
					{
						configinfo.m_sCompanyType = str;
					}

					str = pNodeCur->findProperty("reserve");
					if (!str)
					{
						printf("No reserve!\n");
						configinfo.m_sReserve = "";
					}
					else
					{
						configinfo.m_sReserve = str;
					}

					str = pNodeCur->findProperty("englishname");
					if (!str)
					{
						printf("No englishname!\n");
						configinfo.m_sEventEnName = "";
					}
					else
					{
						configinfo.m_sEventEnName = str;
					}

					str = pNodeCur->findProperty("chinesename");
					if (!str)
					{
						printf("No chinesename!\n");
						configinfo.m_sEventChName = "";
					}
					else
					{
						configinfo.m_sEventChName = str;
					}

					str = pNodeCur->findProperty("opflag");
					if (!str)
					{
						printf("No opflag!\n");
						configinfo.m_sOpFlag = "";
					}
					else
					{
						configinfo.m_sOpFlag = str;
					}

					str = pNodeCur->findProperty("appendcontent");
					if (!str)
					{
						printf("No appendcontent!\n");
					}
					else
					{
						char *p = strtok(str, " \r\n");
						while (p)
						{
							int index = atoi(p);
							index -= 4;
							configinfo.m_vAppendContent.push_back(index);

							p = strtok(NULL, " \r\n");
						}
					}

					str = pNodeCur->findProperty("eventlevel");
					if (!str)
					{
						printf("No eventlevel!\n");
						delete pCfgDoc;
						return -1;
					}
					else
					{
						configinfo.m_sEventLevel = str;
					}

					str = pNodeCur->findProperty("eventtypeid");
					if (!str)
					{
						printf("No eventtypeid!\n");
						delete pCfgDoc;
						return -1;
					}
					else
					{
						configinfo.m_sEventTypeID = str;
					}

					//onenode
					CXMLNodeList *pOneNodeList = pNodeCur->getNodeList();
					if (pOneNodeList)
					{
						for (int j = 0; j < pOneNodeList->size(); ++j)
						{
							CConditionNode	conditionnode;

							CXMLNode *pOneNodeCur = (*pOneNodeList)[j];

							str = pOneNodeCur->findProperty("index");
							if (!str)
							{
								printf("No index!\n");
								conditionnode.index = -1;
							}
							else
							{
								conditionnode.index = atoi(str);
							}

							str = pOneNodeCur->findProperty("value");
							if (!str)
							{
								printf("No value!\n");
								delete pCfgDoc;
								return -1;
							}
							else
							{
								conditionnode.value = str;
							}

							str = pOneNodeCur->findProperty("pattern");
							if (!str)
							{
								printf("No pattern!\n");
								delete pCfgDoc;
								return -1;
							}
							else
							{
								//生成模式匹配串
								std::string pattern;
								for (int k = 0; k < strlen(str); ++k)
								{
									if (str[k] == ' ')
									{
										pattern += "%[0-9]";
										conditionnode.patternlist.push_back(
												pattern);
										pattern.clear();
									}
									else
									{
										pattern.push_back(str[k]);
									}
								}

								//最后一截为非模式部分
								if (!pattern.empty())
								{
									if (conditionnode.patternlist.size() == 0)
									{
										conditionnode.patternlist.push_back(
												pattern);
									}
									else
									{
										//追加到最后一个模式上
										conditionnode.patternlist[conditionnode.patternlist.size() - 1] += pattern;
									}
								}
							}

							configinfo.m_sEventConditionList.push_back(
									conditionnode);
						}
					}
					else
					{
						printf("no mathc section, invalid!\n");
						delete pCfgDoc;
						return -1;
					}

					m_lConfigInfoList.push_back(configinfo);
				}
			}
		}

		// 会员接入设备IP地址列表
		CXMLNode *pMemberAccessNode = pCfgRoot->findNode(
			NodeType,
			"MemberAccessEquipmentIPList",
			NULL,
			NULL);
		if (pMemberAccessNode)
		{
			string strEnable = pMemberAccessNode->findProperty("Enable");
			if (strEnable == "1")
				m_MemberAccessEquipmentFilterEnable = true;

			CXMLNodeList *pMemberAccessNodeList = pMemberAccessNode->getNodeList();
			if (pMemberAccessNodeList)
			{
				for (int i = 0; i < pMemberAccessNodeList->size(); i++)
				{
					// onenode, IP
					CXMLNode *pIPNode = (*pMemberAccessNodeList)[i];
					string strIP = pIPNode->findProperty("IP");

					if (!strIP.empty())
					{
						std::list<std::string>::iterator IPListBegin = m_MemberAccessEquipmentList.begin();
						std::list<std::string>::iterator IPListEnd = m_MemberAccessEquipmentList.end();
						if (find(IPListBegin, IPListEnd, strIP) == IPListEnd)
						{
							m_MemberAccessEquipmentList.push_back(strIP);
						}
					}
				}
			}
		}

		//关联指标配置信息
		CXMLNode *pComAttrNode = pCfgRoot->findNode(
			NodeType,
			"ComplexAttr",
			NULL,
			NULL);
		if ( NULL != pComAttrNode )
		{
			CXMLNodeList *pComAttrNodeList = pComAttrNode->getNodeList();
			if ( NULL != pComAttrNodeList)
			{
				for (int i = 0; i < pComAttrNodeList->size(); i++)
				{
					// onenode,
					CXMLNode *pAttrNode = (*pComAttrNodeList)[i];
					string attrname = pAttrNode->findProperty("name");
					string rel_attrs = pAttrNode->findProperty("relation"); 
					string express = pAttrNode->findProperty("express");

					//ComputerComplexAttr
					/*initAttrRelation(attrname,express,rel_attrs);*/
				}
			}
		}

		//2014.09.01
		//ssh no polling device list
		CXMLNode *pSshnopollNode = pCfgRoot->findNode(
			NodeType,
			"SSHNoPollDevices",
			NULL,
			NULL);
		if ( NULL != pSshnopollNode )
		{
			CXMLNodeList *pSshnopollNodeList = pSshnopollNode->getNodeList();
			if ( NULL != pSshnopollNodeList)
			{
				for (int i = 0; i < pSshnopollNodeList->size(); i++)
				{
					// onenode,
					CXMLNode *pAttrNode = (*pSshnopollNodeList)[i];
					string dev_ip = pAttrNode->findProperty("IP");

					//push the IP into list
					g_devlist.push_back(dev_ip);
				}
			}
		}

		CXMLNode *pSSHKeyBoardInteractiveNode = pCfgRoot->findNode(
			NodeType,
			"SSHKeyBoardInteractive",
			NULL,
			NULL);
		g_srxdevlit.clear();
		if ( NULL != pSSHKeyBoardInteractiveNode )
		{
			CXMLNodeList *pSSHKeyBoardInteractiveNodeList = pSSHKeyBoardInteractiveNode->getNodeList();
			if ( NULL != pSSHKeyBoardInteractiveNodeList)
			{
				for (int i = 0; i < pSSHKeyBoardInteractiveNodeList->size(); i++)
				{
					// onenode,
					CXMLNode *pAttrNode = (*pSSHKeyBoardInteractiveNodeList)[i];
					string dev_ip = pAttrNode->findProperty("IP");

					//push the IP into list
					g_srxdevlit.push_back(dev_ip);
				}
			}
		}

		//2014.11.03
		//key words in syslog no warning.
		CXMLNode *pkeywordsNode = pCfgRoot->findNode(
			NodeType,
			"keysubstring",
			NULL,
			NULL);
		if ( NULL != pkeywordsNode )
		{
			CXMLNodeList *pkeywordsNodeList = pkeywordsNode->getNodeList();
			if ( NULL != pkeywordsNodeList)
			{
				for (int i = 0; i < pkeywordsNodeList->size(); i++)
				{
					// onenode,
					CXMLNode *pAttrNode = (*pkeywordsNodeList)[i];
					string name = pAttrNode->findProperty("substring");
					//push the substring into list
					g_syslogsubwordslist.push_back(name);
				}
			}
		}
	}

	catch(CParseError * e)
	{
		delete e;
		delete pCfgDoc;
		printf("XML: File %s explain failed!\n", filename.c_str());
		return -1;
	}

	delete pCfgDoc;

	struct stat filestat;

	int iRtn = stat(m_sFileName.c_str(), &filestat);

	if (iRtn >= 0)
	{
		m_tLastLoadTime = filestat.st_mtime;
	}

	return 0;
}

int CSysLogConfigManager::ReloadConfig(void)
{
	struct stat filestat;

	int iRtn = stat(m_sFileName.c_str(), &filestat);

	if (iRtn >= 0 && filestat.st_mtime <= m_tLastLoadTime)
	{
		//nothing updated, return;
		printf("cfg file not updated!\n");
		return 0;
	}

	//备份容器数据
	std::vector<CSysLogConfigInfo>	infolist_bak = m_lConfigInfoList;
	std::map<int, int>	infostart_bak = m_mInfoStart;
	std::map<string, int> infoips_bak = m_mapIPS;

	m_lConfigInfoList.clear();
	m_mInfoStart.clear();
	m_mapIPS.clear();

	if (LoadConfig(m_sFileName) != 0)
	{
		printf("ReloadConfig fail for %s\n", m_sFileName.c_str());

		//Load失败，回滚数据
		m_lConfigInfoList.swap(infolist_bak);
		m_mInfoStart.swap(infostart_bak);
		m_mapIPS.swap(infoips_bak);
		return -1;
	}
	else
	{
		return 0;
	}
}

void CSysLogConfigManager::DumpConfig(void)
{
	printf("condition infos\n");
	for (int i = 0; i < m_lConfigInfoList.size(); ++i)
	{
		std::string appendid;
		for (int m = 0; m < m_lConfigInfoList[i].m_vAppendContent.size(); ++m)
		{
			char buf[100];
			sprintf(buf, "%d ", m_lConfigInfoList[i].m_vAppendContent[m]);
			appendid = buf;
		}

		printf(
			"devicetype=%s, companytype=%s, eventlevel=%s, eventtypeid=%s, reserve=%s \
englishname=%s chinesename=%s opflag=%s appendcontent=%s\n",
			m_lConfigInfoList[i].m_sDeviceType.c_str(),
			m_lConfigInfoList[i].m_sCompanyType.c_str(),
			m_lConfigInfoList[i].m_sEventLevel.c_str(),
			m_lConfigInfoList[i].m_sEventTypeID.c_str(),
			m_lConfigInfoList[i].m_sReserve.c_str(),
			m_lConfigInfoList[i].m_sEventEnName.c_str(),
			m_lConfigInfoList[i].m_sEventChName.c_str(),
			m_lConfigInfoList[i].m_sOpFlag.c_str(),
			appendid.c_str());

		for (int j = 0;
			 j < m_lConfigInfoList[i].m_sEventConditionList.size();
			 ++j)
		{
			std::string patternstr;
			for (int k = 0;
				 k < m_lConfigInfoList[i].m_sEventConditionList[j].patternlist.size();
			 ++k)
			{
				patternstr += m_lConfigInfoList[i].m_sEventConditionList[j].patternlist[k];
			}

			printf(
				"index=%d, value=%s, pattern=%s\n",
				m_lConfigInfoList[i].m_sEventConditionList[j].index,
				m_lConfigInfoList[i].m_sEventConditionList[j].value.c_str(),
				patternstr.c_str());
		}

		printf("\n");
	}

	printf("company infos\n");
	for (std::map<int, int>::iterator it = m_mInfoStart.begin();
		 it != m_mInfoStart.end();
		 ++it)
	{
		printf("name=%d, start=%d\n", it->first, it->second);
	}

	printf("iplist infos\n");
	for (std::map<string, int>::iterator it = m_mapIPS.begin();
		 it != m_mapIPS.end();
		 ++it)
	{
		printf("ip=%s, level=%d\n", it->first.c_str(), it->second);
	}
}
