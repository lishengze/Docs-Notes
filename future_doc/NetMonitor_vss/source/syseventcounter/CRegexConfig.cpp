/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	CRegexConfig.cpp
///@brief	实现了CRegexConfig类
///@history
///20110927 魏诚创建该文件
/////////////////////////////////////////////////////////////////////////
#include "CRegexConfig.h"
#include "CXML.h"
#include <boost/regex.hpp>
#include "PrjCommon.h"

using namespace boost;

CRegexConfigManager *CRegexConfigManager::Instance(void)
{
	static CRegexConfigManager	oRegexConfigManager;
	return &oRegexConfigManager;
}

int CRegexConfigManager::LoadConfig(std::string filename)
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

		CXMLNode *pRegexNode = pCfgRoot->findNode(
				NodeType,
				"regexinfos",
				NULL,
				NULL);
		if (pRegexNode)
		{
			CXMLNodeList *pRegexNodeList = pRegexNode->getNodeList();
			for (int i = 0; i < pRegexNodeList->size(); i++)
			{
				string	command;

				CXMLNode *pNodeCur = (*pRegexNodeList)[i];

				str = pNodeCur->findProperty("command");
				if (!str)
				{
					printf("No command in regexinfo!\n");
					delete pCfgDoc;
					return -1;
				}
				else
				{
					command = str;
				}

				int manufactory_id;

				str = pNodeCur->findProperty("manufactory_id");
				if (!str)
				{
					printf("No manufactory_id!\n");
					delete pCfgDoc;
					return -1;
				}
				else
				{
					manufactory_id = atoi(str);
				}

				vector<CRegexNode>	regexnodelist;

				//conditionnode
				CXMLNodeList *pConditionNodeList = pNodeCur->getNodeList();
				if (pConditionNodeList)
				{
					for (int j = 0; j < pConditionNodeList->size(); ++j)
					{
						CRegexNode	regexnode;

						CXMLNode *pConditionNodeCur = (*pConditionNodeList)[j];

						str = pConditionNodeCur->findProperty("condition");
						if (!str)
						{
							printf("No condition!\n");
							delete pCfgDoc;
							return -1;
						}
						else
						{
							regexnode.condition = str;
						}

						str = pConditionNodeCur->findProperty("isloop");
						if (!str)
						{
							printf("No isloop!\n");
							delete pCfgDoc;
							return -1;
						}
						else
						{
							regexnode.isloop = atoi(str) > 0 ? true : false;
						}

						str = pConditionNodeCur->findProperty("ismatchsingle");
						if (!str)
						{
							printf("No ismatchsingle!\n");
							delete pCfgDoc;
							return -1;
						}
						else
						{
							regexnode.ismatchsingle = atoi(
									str) > 0 ? true : false;
						}

						str = pConditionNodeCur->findProperty("ignorecase");
						if (!str)
						{
							printf("No ignorecase!\n");
							delete pCfgDoc;
							return -1;
						}
						else
						{
							regexnode.ignorecase = atoi(str) > 0 ? true : false;
						}

						str = pConditionNodeCur->findProperty(
								"notmatchattrname");
						if (str && strlen(str) > 0)
						{
							regexnode.notmatchattrname = str;
						}
						else
						{
							regexnode.notmatchattrname = "";
						}

						//attrnode
						CXMLNodeList *pAttrNodeList = pConditionNodeCur->
							getNodeList();
						if (pAttrNodeList)
						{
							vector<string>	attrnamelist;

							for (int k = 0; k < pAttrNodeList->size(); ++k)
							{
								CXMLNode *pAttrNodeCur = (*pAttrNodeList)[k];

								str = pAttrNodeCur->findProperty("attrname");
								if (!str)
								{
									printf("No attrname!\n");
									delete pCfgDoc;
									return -1;
								}
								else
								{
									attrnamelist.push_back(str);
								}
							}

							regexnode.attrnamelist = attrnamelist;
						}

						regexnodelist.push_back(regexnode);
					}
				}
				else
				{
					printf("no mathc section, invalid!\n");
					delete pCfgDoc;
					return -1;
				}

				char commandkey[1024] = { 0 };
				SNPRINTF(
					commandkey,
					1024,
					"%s_%d",
					command.c_str(),
					manufactory_id);

				m_mRegexList[commandkey] = regexnodelist;
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

int CRegexConfigManager::ReloadConfig(void)
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
	map<string, vector<CRegexNode> > infolist_bak = m_mRegexList;

	m_mRegexList.clear();

	if (LoadConfig(m_sFileName) != 0)
	{
		printf("ReloadConfig fail for %s\n", m_sFileName.c_str());

		//Load失败，回滚数据
		m_mRegexList.swap(infolist_bak);
		return -1;
	}
	else
	{
		return 0;
	}
}

void CRegexConfigManager::DumpConfig(void)
{
	printf("regex infos\n");

	map<string, vector<CRegexNode> >::iterator	it = m_mRegexList.begin();
	for (; it != m_mRegexList.end(); ++it)
	{
		printf("command=%s\n", it->first.c_str());

		for (int j = 0; j < it->second.size(); ++j)
		{
			printf(
				"condition=%s, isloop=%d, ismatchsingle=%d, ignorecase=%d, notmatchattrname=%s\n",
				it->second[j].condition.c_str(),
				it->second[j].isloop,
				it->second[j].ismatchsingle,
				it->second[j].ignorecase,
				it->second[j].notmatchattrname.c_str());

			for (int k = 0; k < it->second[j].attrnamelist.size(); ++k)
			{
				printf("attrname=%s ", it->second[j].attrnamelist[k].c_str());
			}

			printf("\n");
		}

		printf("\n");
	}
}

vector<vector<AttrNodeInfo> > CRegexConfigManager::ParseCommandResult(
	string	command,
	string	result,
	bool addquote,
	string command2)
{
	vector<vector<AttrNodeInfo> > attr_value_list;

	map<string, vector<CRegexNode> >::iterator	r_i = m_mRegexList.find(
			command);
	if( r_i == m_mRegexList.end() )
	{
		r_i = m_mRegexList.find(command2);
	}
	if (r_i != m_mRegexList.end())
	{
		for (int i = 0; i < r_i->second.size(); ++i)
		{
			cmatch	what;
			int flag_type = regex_constants::normal;

			if (r_i->second[i].ismatchsingle)
			{
				flag_type |= regex_constants::match_single_line;
			}

			if (r_i->second[i].ignorecase)
			{
				flag_type |= regex::icase;
			}

			vector<AttrNodeInfo> attr_value;

			try
			{
				regex expression(r_i->second[i].condition.c_str(), flag_type);
				if (regex_match(result.c_str(), what, expression))
				{
					for (int m = 1; m < what.size(); m++)
					{
						//printf("what %d value %s, size=%d\n", m, what[m].str().c_str(), what[m].str().size());
						if (r_i->second[i].attrnamelist.size() < m)
						{
							printf(
								"attrname config error for command:%s condition:%s\n",
								command.c_str(),
								r_i->second[i].condition.c_str());
							return attr_value_list;
						}
						else
						{
							if (r_i->second[i].attrnamelist[m - 1].compare(
									"regex_next_input_value") == 0)
							{
								result = what[m].str();
							}
							else
							{
								AttrNodeInfo attr_node;

								attr_node.key = r_i->second[i].attrnamelist[m - 1];

								if (addquote)
								{
									bool isDigit = true;
									for (int k = 0;
										 k < what[m].str().size();
										 ++k)
									{
										if (what[m].str()[k] < '0'
										||	what[m].str()[k] > '9')
										{
											isDigit = false;
											break;
										}
									}

									if (what[m].str().size() == 0)
									{
										isDigit = false;
									}

									if (isDigit)
									{
										attr_node.value = what[m].str();
									}
									else
									{
										//字符串拼接上""
										string	val = "\"";
										val += trim(
												(char *)what[m].str().c_str());
										val += "\"";
										attr_node.value = val;
									}
								}
								else
								{
									attr_node.value = trim(
											(char *)what[m].str().c_str());
								}

								attr_value.push_back(attr_node);
							}
						}
					}

					if (attr_value.size() > 0)
					{
						//排除第一次不提取指标的情况
						attr_value_list.push_back(attr_value);
					}

					if (r_i->second[i].isloop)
					{
						while (result.size() > 0)
						{
							vector<AttrNodeInfo> attr_value;

							cmatch	what2;
							string	inputstr = result;
							try
							{
								if (regex_match(
										inputstr.c_str(),
									what2,
									expression))
								{
									result.clear();

									for (int n = 1; n < what2.size(); n++)
									{
										//printf("what2 %d value2 %s,size=%d\n", n, what2[n].str().c_str(), what2[n].str().size());
										if (r_i->second[i].attrnamelist.size()
												< n)
										{
											printf(
												"attrname config error for command:%s condition:%s\n",
												command.c_str(),
												r_i->second[i].condition.
													c_str());
											return attr_value_list;
										}
										else
										{
											if (r_i->second[i].attrnamelist[
													n - 1].compare(
													"regex_next_input_value") == 0)
											{
												result = what2[n].str();
											}
											else
											{
												AttrNodeInfo attr_node;

												attr_node.key = r_i->second[i].attrnamelist[n - 1];

												if (addquote)
												{
													string	tmp = what2[n].str();

													bool isDigit = true;
													for (int k = 0;
														 k < what2[n].str().size();
													 ++k)
													{
														if (what2[n].str()
																[k] < '0'
														||	what2[n].str()
																[k] > '9')
														{
															isDigit = false;
															break;
														}
													}

													if (what2[n].str().size()
															== 0)
													{
														isDigit = false;
													}

													if (isDigit)
													{
														attr_node.value = what2[n].str();
													}
													else
													{
														//字符串拼接上""
														string	val = "\"";
														val += trim(
																(char *)what2[n].str()
																	.c_str());
														val += "\"";
														attr_node.value = val;
													}
												}
												else
												{
													attr_node.value = trim(
															(char *)what2[n].str()
																.c_str());
												}

												attr_value.push_back(attr_node);
											}
										}
									}
								}
								else
								{
									printf(
										"command:%s not match condition:%s, result:%s\n",
										command.c_str(),
										r_i->second[i].condition.c_str(),
										result.c_str());

									AttrNodeInfo attr_node;

									attr_node.key = r_i->second[i].notmatchattrname;

									if (r_i->second[i].notmatchattrname.size()
											> 0)
									{
										if (addquote)
										{
											attr_node.value = "\"\"";
										}
										else
										{
											attr_node.value = "";
										}

										attr_value.push_back(attr_node);
									}

									break;
								}

								attr_value_list.push_back(attr_value);
							}

							catch(...)
							{
								printf(
									"invalid 222 regexstr:%s in %s\n",
									inputstr.c_str(),
									__FUNCTION__);
							}
						}

						//循环匹配一定出现在最底层的条件中
						return attr_value_list;
					}
				}
				else
				{
					printf(
						"command:%s not match condition:%s, result:%s\n",
						command.c_str(),
						r_i->second[i].condition.c_str(),
						result.c_str());

					if (r_i->second[i].notmatchattrname.size() > 0)
					{
						AttrNodeInfo attr_node;

						attr_node.key = r_i->second[i].notmatchattrname;

						if (addquote)
						{
							attr_node.value = "\"\"";
						}
						else
						{
							attr_node.value = "";
						}

						attr_value.push_back(attr_node);

						attr_value_list.push_back(attr_value);
					}

					//当前条件不匹配，不进行剩余条件的匹配
					return attr_value_list;
				}
			}

			catch(...)
			{
				printf(
					"invalid 111 regexstr:%s in %s\n",
					result.c_str(),
					__FUNCTION__);
			}
		}
	}
	else
	{
		printf(
			"no regex info for cmd:%s in %s\n",
			command.c_str(),
			__FUNCTION__);
	}

	return attr_value_list;
}

int CRegexConfigManager::RegexSearch(string regexstr, string inputstr)
{
	cmatch	what;

	int flag_type = regex_constants::normal;
	flag_type |= regex_constants::match_single_line;

	try
	{
		regex expression(regexstr.c_str(), flag_type);
		if (regex_search(inputstr.c_str(), what, expression))
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}

	catch(...)
	{
		printf("invalid regexstr:%s in %s\n", regexstr.c_str(), __FUNCTION__);
		return 1;
	}
}
