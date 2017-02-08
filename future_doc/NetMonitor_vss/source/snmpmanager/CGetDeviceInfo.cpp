/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	CGetDeviceInfo.cpp
///@brief	实现了CGetDeviceInfo使用的类
///@history
///20101020	周建军		创建该文件
#include "CGetDeviceInfo.h"
#include "CSynConnector.h"

#define SNMPSYSNAMEOID		"1.3.6.1.2.1.1.5.0"
#define SNMPSYSDESCR		"1.3.6.1.2.1.1.1.0"
#define SNMPIFNUMBER		"1.3.6.1.2.1.2.1.0"
#define SNMPIPFORWARDING	"1.3.6.1.2.1.4.1.0"
#define SNMPSYSSERVICES		"1.3.6.1.2.1.1.7.0"
#define SNMPSYSTEMDATE		"1.3.6.1.2.1.25.1.2.0"
#define SNMPMACPORTNUM		"1.3.6.1.2.1.17.4.4.1.1.1"	//1.3.6.1.2.1.17.1.4.1.1.(1...),1.3.6.1.2.1.17.1.1.0
#define SNMPOBJECTID		"1.3.6.1.2.1.1.2.0"
#define SNMPIFDESCR			"1.3.6.1.2.1.2.2.1.2"

extern char *strlwr(char *str, int length);
extern char g_mDevDomain[];

//@key	  IP地址
//@value	拼接完成的主机名ID，如Pudian.OA.router
TemplateMutexMap<string, string> g_mapIpHostId;

//@Key	IP地址拼接端口索引，如127.0.0.1:100101
//@Value	接口名，如Etheret0/1
TemplateMutexMap<string, string> g_mapIFName;

bool g_bThreadActiveFlag = false;

/* a list of general variables to query for*/
struct SInfoOID g_InfoOids[] =
{
	{ SNMPSYSDESCR },
	{ SNMPSYSNAMEOID },

	//{ SNMPIFNUMBER },
	{ SNMPIPFORWARDING },
	{ SNMPSYSSERVICES },
	{ SNMPOBJECTID },

	//objectid
	//{ SNMPIFDESCR }, //ifdescr
	{ SNMPSYSTEMDATE },

	//host special, system date
	{ SNMPMACPORTNUM },

	//switch special, port number	
	{ NULL }
};

//????
//补充端口信息??
//active_hosts在asynch_response中减少，在asynchronous中增加

//int g_active_hosts=0;	 /* hosts that we have not completed */
int getdigitalpos(const char *str)
{
	char *p = (char *)str;
	while (*p != '\0')
	{
		if ((*p > '0' && *p < '9'))
		{
			return p - str;
		}
		else
		{
			p++;
		}
	}

	return -1;
}

bool CGetDeviceInfoThread::InitInstance(void)
{
	return true;
}

void CGetDeviceInfoThread::ExitInstance(void)
{
}

char *CGetDeviceInfoThread::FormatMonitorObjectName(char *name)
{
	if (NULL == name)
	{
		return NULL;
	}

	char *p = name;
	while (*p == ' ')
	{
		p++;
	}

	p = trim(p);

	char *q = NULL;
	while ((q = strstr(p, g_mDevDomain)) != NULL)
	{
		int len = strlen(g_mDevDomain);
		if (q == p)						//头部域名
		{
			p += (len + 1);
		}
		else if (*(q + len) == '\0')	//尾部域名
		{
			*(q - 1) = '\0';			// 顺便去掉尾部域名的连接符号.
		}
		else
		{
			*q = '\0';   //若是中间，设为结束符
		}
	}

	while ((q = strchr(p, '.')) != NULL)
	{
		*q = '_';
	}

	while ((q = strchr(p, ' ')) != NULL)
	{
		*q = '_';
	}

	return p;
}

void CGetDeviceInfoThread::GetDecDeviceInfo(SInfoHost *pHosts, int nArraySize)
{
	if (pHosts == NULL)
	{
		printf(
			"warning:GetDecDeviceInfo fail because of the NULL point,pHosts=%d \n",
			pHosts);
		return;
	}

	SInfoHost *hp;
	int i;

	CSynConnector *pSyn = CSynConnector::GetInstancePoint();
	if (pSyn == NULL)
	{
		printf(
			"warning:GetDecDeviceInfo fail because of the NULL point,pSyn=%d \n",
			pSyn);
		return;
	}

	for (hp = pHosts, i = 0; hp && i < nArraySize; hp++, i++)
	{
		if (hp->isablesnmp)
		{
			for (map<string, SInfoOID>::iterator it_oid = pSyn->m_genoids.
					 begin();
			 it_oid != pSyn->m_genoids.end();
				 it_oid++)
			{
				if (it_oid->second.is_table)
				{
					WALK_RESULT res;
					if (SNMP_ERROR_SUCCESS != hp->mSnmpWrapper->
							send_sync_walk_request(it_oid->second.Name, res))	//
					{
						printf(
							"snmp async send failed ip=[%s],oid=[%s]\n",
							hp->name,
							it_oid->second.Name);
					}
					else
					{
						//do res
						hp->moidsValues[it_oid->first] = res;
					}
				}
				else
				{
					string	val;
					int valtype;
					if (SNMP_ERROR_SUCCESS != hp->mSnmpWrapper->
							send_sync_get_request(
							it_oid->second.Name,
						val,
						valtype))
					{
						printf(
							"snmp async send failed ip=[%s],oid=[%s]\n",
							hp->name,
							it_oid->second.Name);
					}
					else
					{
						map<string, string> res;
						res[it_oid->second.Name] = val;
						hp->moidsValues[it_oid->first] = res;
					}
				}
			}
		}
	}

	for (hp = pHosts, i = 0; hp && i < nArraySize; hp++, i++)
	{
		if (hp->isablesnmp && hp->moidsValues.size() > 0)
		{
			for (map < string, map<string, string> >::iterator it_values =
					 hp->moidsValues.begin();
			 it_values != hp->moidsValues.end();
				 it_values++)
			{
				if (it_values->first.compare("1.3.6.1.2.1.1.2.0") == 0)			//型号
				{
					char *p =
						(char *)it_values->second["1.3.6.1.2.1.1.2.0"].c_str();

					if (strcasestr(p, "cisco"))
					{
						hp->manustr = "Cisco";

						p += strlen("cisco");
						if (strlen(p) >= 4)
						{
							hp->serial.assign(p, 4);
						}

						hp->sysType = "router";
					}
					else if (strcasestr(p, "catalyst"))
					{
						hp->manustr = "Cisco";

						p += strlen("catalyst");
						if (strlen(p) >= 4)
						{
							hp->serial.assign(p, 4);
						}

						hp->sysType = "switch";
					}
					else if (strcasestr(p, "enterprises."))
					{
						p += strlen("enterprises.");

						char *pNumEnd = strcat(p, ".");
						if (pNumEnd)
						{
							std::string manufacture_str;
							manufacture_str.assign(p, pNumEnd - p);

							int manufacture_seq = atoi(manufacture_str.c_str());
							switch (manufacture_seq)
							{
								case 9:
									{
										hp->manustr = "Cisco";
										break;
									}

								case 3224:
									{
										hp->manustr = "Juniper";
										break;
									}

								case 3375:
									{
										hp->manustr = "F5";
										break;
									}

								case 2011:
									{
										hp->manustr = "Huawei";
										break;
									}

								default:
									break;
							}
						}
					}
				}
				else if (it_values->first.compare("1.3.6.1.2.1.2.2.1.2"))		// 端口数
				{
					//int count = 1;
					//char buff[10];

					//for (CDPWALK_RESULT_ITERATOR it_ifs = it_values->second.
					//		 begin();
					// it_ifs != it_values->second.end();
					//	 it_ifs++)
					//{
					//	string	key = it_ifs->first;

					//	//	printf( "++++++++++++++++++key = [%s] \n",key.c_str());
					//	string	newkey = key.substr(key.rfind(".") + 1);

					//	//	printf( "++++++++++++++++++newkey = [%s] \n",newkey.c_str());
					//	hp->mifDescr[newkey] = it_values->second[key];

					//	//	printf("============name [%s]\n", interfacemap[key].c_str());
					//	if (strcasestr(
					//			it_values->second[key].c_str(),
					//		"Vlan") == NULL)
					//	{
					//		string	ipport = hp->name;
					//		ipport.append(":");
					//		sprintf(buff, "%d", count);
					//		ipport.append(buff);

					//		//		printf("&&&&&&&&&&&&&&& g_mapIFName[%s]=[%s]\n",ipport.c_str(),interfacemap[key].c_str());
					//		count++;
					//		g_mapIFName.add(ipport, it_values->second[key]);
					//	}
					//}
				}
			}
		}
	}
}

void CGetDeviceInfoThread::DoAttemptSnmp(SInfoHost *pHosts, int nArraySize)
{
	SInfoHost *hp;
	int i = 0;

	m_active_hosts = 0;

	//发送一条数据	
	for (hp = pHosts, i = 0; hp && i < nArraySize; hp++, i++)
	{
		if (NULL == hp->mSnmpWrapper)
		{
			hp->mSnmpWrapper = new CSnmpWrapper(hp->community, hp->name);
		}

		if (!hp->mSnmpWrapper->is_opened() && !hp->mSnmpWrapper->open_session())
		{
			continue;
		}

		////设置oid
		//hp->current_oid = g_InfoOids;
		//判断节点host是否通过snmp协议访问
		string	res;
		int restype;
		if (SNMP_ERROR_SUCCESS == hp->mSnmpWrapper->send_sync_get_request(
				SNMPSYSNAMEOID,
			res,
			restype))					//
		{
			hp->SysName = FormatMonitorObjectName((char *)(res.c_str()));
			++m_active_hosts;
			m_dev_count++;
			printf(
				"$$$$$$$$$$$$$$$$$$$$$$m_active_hosts=%d in thread ID = [%d].\n",
				m_active_hosts,
				thread_id);
			hp->isablesnmp = true;
		}
	}
}

void CGetDeviceInfoThread::GetDeviceBaseInfo(SInfoHost *pHosts, int nArraySize)
{
	SInfoHost *hp;
	int i = 0;

	//发送一条数据	
	for (hp = pHosts, i = 0; hp != NULL && i < nArraySize; hp++, i++)
	{
		if (!hp->isablesnmp)
		{
			continue;
		}

		if (NULL == hp->mSnmpWrapper)
		{
			hp->mSnmpWrapper = new CSnmpWrapper(hp->community, hp->name);
		}

		if (!hp->mSnmpWrapper->is_opened() && !hp->mSnmpWrapper->open_session())
		{
			continue;
		}

		//设置oid
		hp->current_oid = g_InfoOids;

		string	oid = hp->current_oid->Name;
		if (SNMP_ERROR_SUCCESS != hp->mSnmpWrapper->send_async_walk_request(
				oid.c_str()))			//
		{
			printf(
				"snmp async walk failed ip=[%s],oid=[%s]\n",
				hp->name,
				hp->current_oid->Name);
			m_active_hosts--;
		}
	}

	while (m_active_hosts > 0)
	{
		ProcessDeviceBaseInfoResult(pHosts, nArraySize);
	}
}

void CGetDeviceInfoThread::ProcessDeviceBaseInfoResult(
	SInfoHost *pHosts,
	int nArraySize)
{
	SInfoHost *hp;
	int i = 0;

	for (hp = pHosts, i = 0; hp != NULL && i < nArraySize; hp++, i++)
	{
		if (!hp->isablesnmp)
		{
			continue;
		}

		if (!hp->mSnmpWrapper->is_opened())
		{
			continue;
		}

		//接收一次
		hp->mSnmpWrapper->recv_async_response();

		//还没任何结果
		if (hp->mSnmpWrapper->is_walk_map_empty()
		&&	hp->mSnmpWrapper->is_timeout_event_empty()
		&&	hp->mSnmpWrapper->is_error_event_empty())
		{
			continue;
		}

		if (!hp->mSnmpWrapper->is_walk_map_empty())
		{
			//process data event
			std::string key;
			DATAMAP datamap;

			if (hp->mSnmpWrapper->pop_one_walk_data(key, datamap) != 0)
			{
#ifdef PACKAGE_OUTPUT
				printf(
					"walkdatamap not empty but pop nothing in %s\n",
					__FUNCTION__);
#endif
			}
			else
			{
				int index = 0;
				for (DATAMAPITERATOR it = datamap.begin();
					 it != datamap.end();
					 ++it)
				{
					ParseAsyncResult(hp, it->first, it->second, index++);
				}
			}
		}
		else if (!hp->mSnmpWrapper->is_timeout_event_empty())
		{
			//process timeout event
			std::string timeoutkey;
			time_t	happentime;
			if (hp->mSnmpWrapper->pop_timeout_event(
					timeoutkey,
				happentime) != 0)
			{
#ifdef PACKAGE_OUTPUT
				printf(
					"walktimeoutmap not empty but pop nothing in %s\n",
					__FUNCTION__);
#endif
			}
			else
			{
#ifdef PACKAGE_OUTPUT
				printf(
					"walkdatamap timeout in %s for oid:%s\n",
					__FUNCTION__,
					timeoutkey.c_str());
#endif
			}
		}
		else
		{
			//process error event
			std::string errorkey;
			std::string errormsg;
			if (hp->mSnmpWrapper->pop_error_event(errorkey, errormsg) != 0)
			{
#ifdef PACKAGE_OUTPUT
				printf(
					"walkerrormap not empty but pop nothing in %s\n",
					__FUNCTION__);
#endif
			}
			else
			{
#ifdef PACKAGE_OUTPUT
				printf(
					"walkdatamap error in %s for oid:%s, msg:%s\n",
					__FUNCTION__,
					errorkey.c_str(),
					errormsg.c_str());
#endif
			}
		}

		//发送下一条数据
		hp->current_oid++;				/* send next WALK (if any) */

		//下面的程序跟asynchronous中处理相同
		if (hp->current_oid->Name)
		{
			if (SNMP_ERROR_SUCCESS == hp->mSnmpWrapper->
					send_async_walk_request(hp->current_oid->Name))
			{
				continue;
			}
		}

		hp->mSnmpWrapper->close_session();
		--m_active_hosts;
		printf("************************m_active_hosts=%d\n", m_active_hosts);
	}
}

void CGetDeviceInfoThread::ParseAsyncResult(
	SInfoHost *pHost,
	string	key,
	SNMPRESULTDATA	data,
	int index)
{
	if (pHost == NULL)
	{
		printf("&&&&&&&&&&&&&&& warning: host pointer  is NULL \n");
		return;
	}

	if (key.compare(SNMPSYSDESCR) == 0) //主机描述
	{
		char *buffer = (char *)data.datavalue.c_str();
		char *p = NULL;

		//desc
		pHost->sysDescr = buffer;

		//manufacture
		if (pHost->manustr.length() == 0)
		{
			p = strchr(buffer, ' ');
			if (p)
			{
				pHost->manustr.assign(buffer, p - buffer);
			}
		}

		//product serial
		p = strcasestr(buffer, "Software");
		if (p)
		{
			p += strlen("Software");

			char *pSecondSoftware = strcasestr(p, "Software");
			if (pSecondSoftware)
			{
				pSecondSoftware += strlen("Software");

				p = strchr(pSecondSoftware, '(');
				if (p)
				{
					p++;

					char *pSerialEnd = strchr(p, '-');
					if (pSerialEnd)
					{
						pHost->serial.assign(p + 1, pSerialEnd - p - 1);
					}
				}
			}
		}
	}
	else if (key.compare(SNMPSYSNAMEOID) == 0)						//主机名
	{
		pHost->SysName = FormatMonitorObjectName(
				(char *)data.datavalue.c_str());

		char buffer[1024] = { 0 };
		sprintf(
			buffer,
			"%s.%s.%s",
			pHost->cenName.c_str(),
			pHost->netName.c_str(),
			pHost->SysName.c_str());
#ifdef PACKAGE_OUTPUT
		printf("&&&&&&&&&&&&&&& g_mapIpHostId[%s]=[%s]\n", pHost->name, buffer);
#endif
		g_mapIpHostId.add(pHost->name, buffer);
	}

	//else if( key.compare(SNMPIFNUMBER) == 0 ) //接口数
	//{
	//	pHost->ifNum = atoi( data.datavalue.c_str() );
	//}
	else if (key.compare(SNMPIPFORWARDING) == 0)					//ipforwarding
	{
		pHost->ipforwarding = atoi(data.datavalue.c_str());

		if (pHost->sysType.length() == 0 && pHost->sysServices != -1)
		{
			if (pHost->ipforwarding == 0x01)
			{
				pHost->sysType = "router";
			}
			else if (pHost->ipforwarding == 0x02)
			{
				if (pHost->sysServices & 0x02)
				{
					pHost->sysType = "switch";						//第二层功能
				}
				else
				{
					pHost->sysType = "firewall";
				}
			}
		}
	}
	else if (key.compare(SNMPSYSSERVICES) == 0)						//sysServices
	{
		pHost->sysServices = atoi(data.datavalue.c_str());

		if (pHost->sysType.length() == 0 && pHost->ipforwarding != -1)
		{
			if (pHost->ipforwarding == 0x01)
			{
				pHost->sysType = "router";
			}
			else if (pHost->ipforwarding == 0x02)
			{
				if (pHost->sysServices & 0x02)
				{
					pHost->sysType = "switch";						//第二层功能
				}
				else
				{
					pHost->sysType = "firewall";
				}
			}
		}
	}
	else if (key.compare(SNMPSYSTEMDATE) == 0)						//host special
	{
		pHost->sysType = "pc";
	}
	else if (key.compare(SNMPMACPORTNUM) == 0)						//switch special
	{
		pHost->sysType = "switch";
	}
	else if (key.compare(SNMPOBJECTID) == 0)						//manufactory id
	{
		char *p = NULL;
		char *q = NULL;

		if ((
				(
				p = strcasestr(
				(char *)data.datavalue.c_str(),
			"CISCO-PRODUCTS-MIB::")
	) != NULL
		))
		{
			p += strlen("CISCO-PRODUCTS-MIB::");
			if ((q = strcasestr(p, "cisco")) != NULL)
			{
				q += strlen("cisco");
				pHost->sysType = "router";
				pHost->serial = q;
			}
			else if ((q = strcasestr(p, "catalyst")) != NULL)
			{
				q += strlen("catalyst");
				pHost->sysType = "switch";
				pHost->serial.assign(p, 4);
			}
		}
		else if ((
					 (
					 p = strcasestr(
					 (char *)data.datavalue.c_str(),
				 "enterprises.")
		 ) != NULL
			 )
			 ||	 ((q = strcasestr((char *)data.datavalue.c_str(), "3.6.1.4.1.")) != NULL))
		{
			if (p != NULL)
			{
				p += strlen("enterprises.");
			}
			else if (q != NULL)
			{
				p = q;
				p += strlen("3.6.1.4.1.");
			}

			char *pNumEnd = strstr(p, ".");
			if (pNumEnd)
			{
				std::string manufacture_str;
				manufacture_str.assign(p, pNumEnd - p);

				int manufacture_seq = atoi(manufacture_str.c_str());
				switch (manufacture_seq)
				{
					case 9:
						{
							pHost->manustr = "Cisco";
							break;
						}

					case 3224:
						{
							pHost->manustr = "Juniper";
							break;
						}

					case 3375:
						{
							pHost->manustr = "F5";
							break;
						}

					case 2011:
						{
							pHost->manustr = "Huawei";
							break;
						}

					case 26543:
						{
							pHost->manustr = "Blade";
							break;
						}

					default:
						break;
				}
			}
		}

		printf(
			"###ip=[%s],value=[%s],manu=[%s] .\n",
			pHost->name,
			data.datavalue.c_str(),
			pHost->manustr.c_str());
	}
	else if (key.compare(0, strlen(SNMPIFDESCR), SNMPIFDESCR) == 0)
	{
		////printf( "++++++++++++++++++key = [%s] \n",key.c_str());
		//string	newkey = key.substr(key.rfind(".") + 1);

		////printf( "++++++++++++++++++newkey = [%s] \n",newkey.c_str());
		//char *p = strcasestr(data.datavalue.c_str(), "Vlan");
		//if (p != NULL)
		//{
		//	char *ori = p;
		//	while ((p = strchr(p, ' ')) != NULL)
		//	{
		//		*p = '_';
		//	}

		//	pHost->mifDescr[newkey] = trim(ori);
		//}
		//else
		//{
		//	pHost->mifDescr[newkey] = data.datavalue;

		//	string	ipport = pHost->name;
		//	ipport.append(":");

		//	char buff[50] = { 0 };
		//	sprintf(buff, "%d", index);
		//	ipport.append(buff);

		//	//		printf("&&&&&&&&&&&&&&& g_mapIFName[%s]=[%s]\n",ipport.c_str(),interfacemap[key].c_str());
		//	g_mapIFName.add(ipport, data.datavalue);
		//}

		////	printf("============name [%s]\n", interfacemap[key].c_str());
	}
}

void CGetDeviceInfoThread::GetDeviceCdps(void)
{
	for (vector<SInfoHost>::iterator it = m_hosts.begin();
		 it != m_hosts.end();
		 it++)
	{
		if (!it->SysName.empty()
		&&	strcasecmp(it->manustr.c_str(), "cisco") == 0)
		{
			/*@key: cdp本地端口索引号; @value: cdp远端连接设备名*/
			CDPWALK_RESULT	deviceidmap;

			/*@key: 端口索引号;  @value: cdp远端连接设备端口名*/
			CDPWALK_RESULT	deviceportmap;

			/*@key: 设备端口索引号 ;@value: 设备端口名称*/
			CDPWALK_RESULT	interfacemap;

			if (NULL == it->mSnmpWrapper
			||	(
					!it->mSnmpWrapper->is_opened()
			&&	!it->mSnmpWrapper->open_session()
			))
			{
				continue;
			}

			if (SNMP_ERROR_SUCCESS != it->mSnmpWrapper->
					send_sync_walk_request(
					"1.3.6.1.4.1.9.9.23.1.2.1.1.6",
				deviceidmap))
			{
				it->mSnmpWrapper->close_session();
				continue;
			}

			it->mSnmpWrapper->send_sync_walk_request(
					"1.3.6.1.4.1.9.9.23.1.2.1.1.7",
					deviceportmap);
			it->mSnmpWrapper->close_session();

			//生成只有最后两截的remotemap，去掉oid中前面的部分
			CDPWALK_RESULT	remoteportmap;
			CDPWALK_RESULT_ITERATOR it_cdpdev_port;

			for (it_cdpdev_port = deviceportmap.begin();
				 it_cdpdev_port != deviceportmap.end();
				 ++it_cdpdev_port)
			{
				std::string newportkey;

				size_t	found1 = it_cdpdev_port->first.rfind(".");
				if (found1 != std::string::npos)
				{
					size_t	found2 = it_cdpdev_port->first.rfind(
							".",
							found1 - 1);
					if (found2 != std::string::npos)
					{
						newportkey = it_cdpdev_port->first.substr(found2 + 1);
					}
				}

				//去下面接口名称匹配
				//char ifsname[16]="\0";
				//sscanf( it_cdpdev_port->second.c_str(), "%2s", ifsname );
				//sscanf( it_cdpdev_port->second.c_str(),"%*[a-zA-Z]%s", ifsname+2 );
				remoteportmap[newportkey] = FormatMonitorObjectName(
						(char *)(it_cdpdev_port->second.c_str()));	//ifsname;
			}

			printf(
				"host %s has %d device ids!\n",
				it->name,
				deviceidmap.size());

			CDPWALK_RESULT_ITERATOR it_cdpdev;
			for (it_cdpdev = deviceidmap.begin();
				 it_cdpdev != deviceidmap.end();
				 it_cdpdev++)
			{
				//char *p =(char *)it_cdpdev->second.c_str();
				//char *q = strstr( p, g_mDevDomain);
				//if( q != NULL )
				//{
				//	int len = strlen( g_mDevDomain );
				//	if( q == p ) //头部域名
				//	{
				//		p += ( len + 1 );
				//	}
				//	else if( *( q + len ) == '\0') //尾部域名
				//	{
				//		*(q-1) = '\0';
				//	}
				//}
				//while( *p== ' ')
				//{
				//	p++;
				//}
				//while ((p=strchr(p, '.')) != NULL)
				//{
				//	*p = '_';
				//}
				string	localport;

				//char *p =(char *)it_cdpdev->second.c_str();
				string	remoteport;
				std::string localportkey;
				std::string remoteportkey;

				size_t	found1 = it_cdpdev->first.rfind(".");
				if (found1 != std::string::npos)
				{
					size_t	found2 = it_cdpdev->first.rfind(".", found1 - 1);
					if (found2 != std::string::npos)
					{
						localportkey = it_cdpdev->first.substr(
								found2 + 1,
								found1 - found2 - 1);
						remoteportkey = it_cdpdev->first.substr(found2 + 1);
					}
				}

				localport = it->mifDescr[localportkey].first;
				remoteport = remoteportmap[remoteportkey];

				char *remotedev = FormatMonitorObjectName(
						(char *)(it_cdpdev->second.c_str()));

				printf(
					"Sysname [%s] localport [%s] remotename [%s] remoteport [%s]\n",
					it->SysName.c_str(),
					localport.c_str(),
					remotedev,
					remoteport.c_str());

				it->mListCdpValue.push_back(
						CCdpValue(it->SysName, localport, remotedev, remoteport));
			}
		}
	}
}

void CGetDeviceInfoThread::GetDeviceModuleInfo(void)
{
	string	mod_root_oid = "1.3.6.1.4.1.9.5.1.3.1.1";
	string	entPhy_root_oid = "1.3.6.1.2.1.47.1.1.1.1";
	int mod[] = { 1, 27, 2, 13, 5, 7 };
	char oid_buff[64] = { 0 };

	for (vector<SInfoHost>::iterator it = m_hosts.begin();
		 it != m_hosts.end();
		 it++)
	{
		if (strcasecmp(it->manustr.c_str(), "cisco") == 0)
		{
			if (NULL == it->mSnmpWrapper
			||	(
					!it->mSnmpWrapper->is_opened()
			&&	!it->mSnmpWrapper->open_session()
			))
			{
				continue;
			}

			/*@key: oid值; @value: oid变量的值*/
			CDPWALK_RESULT	mods_map;

			sprintf(oid_buff, "%s.%d", mod_root_oid.c_str(), mod[0]);
			if (SNMP_ERROR_SUCCESS != it->mSnmpWrapper->
					send_sync_walk_request(oid_buff, mods_map))
			{
				it->mSnmpWrapper->close_session();
				continue;
			}

			int length = strlen(oid_buff);
			if (mods_map.size() > 0)
			{
				int count = 0;
				for (CDPWALK_RESULT_ITERATOR it_res = mods_map.begin();
					 it_res != mods_map.end();
					 it_res++)
				{
					if (length >= it_res->first.length())			//walk结果中有误
					{
						printf(
							"warning:snmp walk's result length less than the root's length.\n");
						continue;
					}

					count++;

					//提取key
					string	offset = it_res->first.substr(length + 1);

					ModuleValue val;

					val.modIndex = atoi(it_res->second.c_str());
					val.modEntPhyIndex = count * 1000 + 1;

					sprintf(
						oid_buff,
						"%s.%d.%s",
						mod_root_oid.c_str(),
						mod[1],
						offset.c_str());

					string	res = "";
					int restype;
					if (SNMP_ERROR_SUCCESS == it->mSnmpWrapper->
							send_sync_get_request(oid_buff, res, restype))
					{
						if (res.length() > 0)
						{
							val.modEntPhyIndex = atoi(res.c_str());
						}
					}

					memset(oid_buff, 0, 64);
					sprintf(
						oid_buff,
						"%s.%d.%d",
						entPhy_root_oid.c_str(),
						mod[2],
						val.modEntPhyIndex);
					res = "";
					if (SNMP_ERROR_SUCCESS == it->mSnmpWrapper->
							send_sync_get_request(oid_buff, res, restype))
					{
						if (res.length() > 0)
						{
							val.modEntPhyDescr = res;
						}
					}

					memset(oid_buff, 0, 64);
					sprintf(
						oid_buff,
						"%s.%d.%d",
						entPhy_root_oid.c_str(),
						mod[3],
						val.modEntPhyIndex);
					res = "";
					if (SNMP_ERROR_SUCCESS == it->mSnmpWrapper->
							send_sync_get_request(oid_buff, res, restype))
					{
						if (res.length() > 0)
						{
							val.modentPhyModelName = res;

							//同设备的模块名有相同现象，拼接“：modIndex”以示区别.
							val.modentPhyModelName.append(":");
							val.modentPhyModelName.append(
									it_res->second.c_str());
						}
					}

					it->m_ModValues[offset] = val;
				}
			}	// end if( mods_map.size() > 0 )
			else
			{
				//用于类似于4503型号的设备
				int base_index = 1000;
				for (int i = 1; i <= 10; i++)
				{
					base_index = i * 1000;
					memset(oid_buff, 0, 64);

					string	value = "";
					int valuetype;
					sprintf(
						oid_buff,
						"%s.%d.%d",
						entPhy_root_oid.c_str(),
						mod[4],
						base_index);
					if (SNMP_ERROR_SUCCESS != it->mSnmpWrapper->
							send_sync_get_request(
							oid_buff,
						value,
						valuetype)
				&&	(value == ""))
					{
						continue;
					}

					if (atoi(value.c_str()) == 9)	//判断是模块的必要条件
					{
						memset(oid_buff, 0, 64);
						sprintf(
							oid_buff,
							"%s.%d.%d",
							entPhy_root_oid.c_str(),
							mod[5],
							base_index);			//取模块号（槽位号）
						value = "";
						if (SNMP_ERROR_SUCCESS != it->mSnmpWrapper->
								send_sync_get_request(
								oid_buff,
							value,
							valuetype))
						{
							continue;
						}

						if (value != "")
						{
							ModuleValue val;

							val.modEntPhyIndex = base_index;

							if (value.find("slot") != std::string::npos)
							{
								val.modIndex = value.at(
											value.find("slot") + 5) -
									'0';
							}

							memset(oid_buff, 0, 64);
							sprintf(
								oid_buff,
								"%s.%d.%d",
								entPhy_root_oid.c_str(),
								mod[2],
								base_index);
							value = "";
							it->mSnmpWrapper->send_sync_get_request(
									oid_buff,
									value,
									valuetype);
							val.modEntPhyDescr = value;

							sprintf(
								oid_buff,
								"%s.%d.%d",
								entPhy_root_oid.c_str(),
								mod[3],
								base_index);
							value = "";
							it->mSnmpWrapper->send_sync_get_request(
									oid_buff,
									value,
									valuetype);

							//val.modentPhyModelName = value;
							//同设备的模块名有相同现象，拼接“：modIndex”以示区别
							char name_buff[32] = { 0 };
							sprintf(
								name_buff,
								"%s:%d",
								value.c_str(),
								val.modIndex);
							val.modentPhyModelName = name_buff;

							memset(oid_buff, 0, 64);
							sprintf(oid_buff, "%d", base_index);
							it->m_ModValues[oid_buff] = val;
						}
					}	// end if (atoi( value.c_str() ) == 9)
				}		// end for
			}			// end else
		}				// end if ( strcasecmp( it->manustr.c_str(), "cisco") == 0 )
	}					// end for
}

void CGetDeviceInfoThread::GetDeviceModule(void)
{
	string	mod_root_oid = "1.3.6.1.4.1.9.5.1.3.1.1";
	string	entPhy_root_oid = "1.3.6.1.2.1.47.1.1.1.1";
	int mod[] = { 2, 9, 10, 11, 13, 5, 7, 8 };								//顺序不能变
	for (vector<SInfoHost>::iterator it = m_hosts.begin();
		 it != m_hosts.end();
		 it++)
	{
		if (strcasecmp(it->manustr.c_str(), "cisco") == 0)					//strcasecmp()
		{
			if (NULL == it->mSnmpWrapper
			||	(
					!it->mSnmpWrapper->is_opened()
			&&	!it->mSnmpWrapper->open_session()
			))
			{
				continue;
			}

			/*@key: oid值; @value: oid变量的值*/
			CDPWALK_RESULT	mods_map;

			if (SNMP_ERROR_SUCCESS != it->mSnmpWrapper->
					send_sync_walk_request(mod_root_oid.c_str(), mods_map))
			{
				it->mSnmpWrapper->close_session();
				continue;
			}

			//用于类似于4503型号的设备
			if (mods_map.size() == 0)
			{
				int base_index = 1000;
				for (int i = 1; i <= 10; i++)
				{
					base_index = i * 1000;

					char buff[64] = { 0 };
					string	value;
					int valuetype;
					sprintf(
						buff,
						"%s.%d.%d",
						entPhy_root_oid.c_str(),
						mod[5],
						base_index);
					if (SNMP_ERROR_SUCCESS != it->mSnmpWrapper->
							send_sync_get_request(buff, value, valuetype))
					{
						continue;
					}

					if (atoi(value.c_str()) == 9)							//代表模块的必要条件
					{
						sprintf(
							buff,
							"%s.%d.%d",
							entPhy_root_oid.c_str(),
							mod[6],
							base_index);									//取模块号（槽位号）
						value = "";
						it->mSnmpWrapper->send_sync_get_request(
								buff,
								value,
								valuetype);

						if (value != "")
						{
							ModuleValue val;

							if (value.find("slot") != std::string::npos)
							{
								val.modIndex = value.at(
											value.find("slot") + 5) -
									'0';
							}

							//val.modIndex = atoi( value.c_str() );
							sprintf(
								buff,
								"%s.%d.%d",
								entPhy_root_oid.c_str(),
								mod[0],
								base_index);
							value = "";
							it->mSnmpWrapper->send_sync_get_request(
									buff,
									value,
									valuetype);
							val.modEntPhyDescr = value;

							sprintf(
								buff,
								"%s.%d.%d",
								entPhy_root_oid.c_str(),
								mod[1],
								base_index);
							value = "";
							it->mSnmpWrapper->send_sync_get_request(
									buff,
									value,
									valuetype);
							val.modEntPhyFwRev = value;

							sprintf(
								buff,
								"%s.%d.%d",
								entPhy_root_oid.c_str(),
								mod[2],
								base_index);
							value = "";
							it->mSnmpWrapper->send_sync_get_request(
									buff,
									value,
									valuetype);
							val.modEntPhySwRev = value;

							sprintf(
								buff,
								"%s.%d.%d",
								entPhy_root_oid.c_str(),
								mod[3],
								base_index);
							value = "";
							it->mSnmpWrapper->send_sync_get_request(
									buff,
									value,
									valuetype);
							val.modEntPhySerialNum = value;

							sprintf(
								buff,
								"%s.%d.%d",
								entPhy_root_oid.c_str(),
								mod[4],
								base_index);
							value = "";
							it->mSnmpWrapper->send_sync_get_request(
									buff,
									value,
									valuetype);
							val.modentPhyModelName = value;

							sprintf(
								buff,
								"%s.%d.%d",
								entPhy_root_oid.c_str(),
								mod[7],
								base_index);
							value = "";
							it->mSnmpWrapper->send_sync_get_request(
									buff,
									value,
									valuetype);
							val.modHwVersion = value;

							memset(buff, 0, 64);
							sprintf(buff, "%d", base_index);
							it->m_ModValues[buff] = val;
						}
					}
				}
			}
			else
			{
				for (CDPWALK_RESULT_ITERATOR it_res = mods_map.begin();
					 it_res != mods_map.end();
					 it_res++)
				{
					if (mod_root_oid.length() >= it_res->first.length())
					{
						printf(
							"warning:snmp walk's result length less than the root's length.\n");
						continue;
					}

					//缩减key值
					string	key = it_res->first.substr(
							mod_root_oid.length() + 1);
					int type;
					char offset[16] = { 0 };
					sscanf(key.c_str(), "%d.%s", &type, offset);
					if (type == 1)
					{
						ModuleValue val;
						val.modIndex = atoi(it_res->second.c_str());
						it->m_ModValues[offset] = val;
					}
					else
					{
						switch (type)
						{
							case 10:
								if (it->m_ModValues.find(
										offset) != it->m_ModValues.end())
								{
									it->m_ModValues[offset].modState = atoi(
											it_res->second.c_str());
								}

								break;
							case 14:
								if (it->m_ModValues.find(
										offset) != it->m_ModValues.end())
								{
									it->m_ModValues[offset].modNumPorts = atoi(
											it_res->second.c_str());
								}

								break;
							case 18:
								if (it->m_ModValues.find(
										offset) != it->m_ModValues.end())
								{
									it->m_ModValues[offset].modHwVersion = it_res->second;
								}

								break;
							case 21:
								if (it->m_ModValues.find(
										offset) != it->m_ModValues.end())
								{
									it->m_ModValues[offset].modStandbyState = atoi(
											it_res->second.c_str());
								}

								break;
							case 27:
								if (it->m_ModValues.find(
										offset) != it->m_ModValues.end())
								{
									it->m_ModValues[offset].modEntPhyIndex = atoi(
											it_res->second.c_str());
								}

								break;
						}
					}
				}

				//
				for (map<string, ModuleValue>::iterator it_mod = it->
						 m_ModValues.begin();
				 it_mod != it->m_ModValues.end();
					 it_mod++)
				{
					char oid_name[64] = { 0 };
					int entPhyIndex = 0;
					string	result;
					int resulttype;

					if (it_mod->second.modEntPhyIndex > 0)
					{
						entPhyIndex = it_mod->second.modEntPhyIndex;
					}
					else
					{
						entPhyIndex = 1000 * (it_mod->second.modIndex) + 1; //当模块的modEntPhyIndex取不到时,以模块号的1000倍开始标号（经验）
					}

					//for( int i = 0; i < 5; i++ )
					//{
					sprintf(
						oid_name,
						"%s.%d.%d",
						entPhy_root_oid.c_str(),
						mod[0],
						entPhyIndex);
					it->mSnmpWrapper->send_sync_get_request(
							oid_name,
							result,
							resulttype);
					it_mod->second.modEntPhyDescr = result;

					sprintf(
						oid_name,
						"%s.%d.%d",
						entPhy_root_oid.c_str(),
						mod[1],
						entPhyIndex);
					result = "";
					it->mSnmpWrapper->send_sync_get_request(
							oid_name,
							result,
							resulttype);
					it_mod->second.modEntPhyFwRev = result;

					sprintf(
						oid_name,
						"%s.%d.%d",
						entPhy_root_oid.c_str(),
						mod[2],
						entPhyIndex);
					result = "";
					it->mSnmpWrapper->send_sync_get_request(
							oid_name,
							result,
							resulttype);
					it_mod->second.modEntPhySwRev = result;

					sprintf(
						oid_name,
						"%s.%d.%d",
						entPhy_root_oid.c_str(),
						mod[3],
						entPhyIndex);
					result = "";
					it->mSnmpWrapper->send_sync_get_request(
							oid_name,
							result,
							resulttype);
					it_mod->second.modEntPhySerialNum = result;

					sprintf(
						oid_name,
						"%s.%d.%d",
						entPhy_root_oid.c_str(),
						mod[4],
						entPhyIndex);
					result = "";
					it->mSnmpWrapper->send_sync_get_request(
							oid_name,
							result,
							resulttype);
					it_mod->second.modentPhyModelName = result;

					//}
				}
			}

			it->mSnmpWrapper->close_session();
		}
	}
}

void CGetDeviceInfoThread::GetDeviceInterface(void)
{
	string	ifname_oid = "1.3.6.1.2.1.2.2.1.2";			//"1.3.6.1.2.1.31.1.1.1.1" 前者对应接口描述信息，一般为作为接口名（全称，如"GigabitEthernet0/1"），各厂商基本可以统一。
	string  ifs_alias = "1.3.6.1.2.1.31.1.1.1.18";//接口别名oid
	//后者对应接口名（cisco厂商为简称，如"Gi0/1",其它产商为全称"GigabitEthernet0/1"），而且有部分设备取不到。
	CSynConnector *pSyn = CSynConnector::GetInstancePoint();

	for (vector<SInfoHost>::iterator it = m_hosts.begin();
		 it != m_hosts.end();
		 it++)
	{
		if (it->SysName.empty())
		{
			continue;
		}

		if (NULL == it->mSnmpWrapper
		||	(
				!it->mSnmpWrapper->is_opened()
		&&	!it->mSnmpWrapper->open_session()
		))
		{
			continue;
		}

		if (pSyn != NULL)
		{
			string	key = "ifDescr";
			key += CONSYM;
			key.append(
					strlwr((char *)(it->manustr.c_str()), it->manustr.length()));

			CON_OID_CONTAIN_MAP_ITERATOR it_oid = pSyn->m_oids.find(key);
			if (it_oid != pSyn->m_oids.end())
			{
				ifname_oid = it_oid->second.OID.getValue();
			}
			else
			{
				printf(
					"warning:default interface information from generic oid,such as cisco.\n");
			}
		}
		else
		{
			printf(
				"warning:default interface information from generic oid,such as cisco.\n");
		}

		//接口名称描述集合 <IF-MIB::ifIndex.index, name>
		CDPWALK_RESULT	ifnamemap;
		map<string, string> ifsname_tmp;

		if (SNMP_ERROR_SUCCESS != it->mSnmpWrapper->send_sync_walk_request(
				ifname_oid.c_str(),
			ifnamemap))
		{
			it->mSnmpWrapper->close_session();
			continue;
		}

		for (CDPWALK_RESULT_ITERATOR it_if = ifnamemap.begin();
			 it_if != ifnamemap.end();
			 it_if++)
		{
			string	key = it_if->first;
			string	newkey = key.substr(key.rfind(".") + 1);

			//printf( "++++++++++++++++++newkey = [%s] \n",newkey.c_str());
			//it->mifDescr[newkey] = FormatMonitorObjectName(
			//		(char *)(it_if->second.c_str()));
			ifsname_tmp[newkey] = FormatMonitorObjectName(
						(char *)(it_if->second.c_str()));

			if (strcasestr(ifsname_tmp[newkey].c_str(), "Vl") == NULL)
			{
				string	ipport = it->name;
				ipport.append(":");
				ipport.append(newkey.c_str());

				//		printf("&&&&&&&&&&&&&&& g_mapIFName[%s]=[%s]\n",ipport.c_str(),interfacemap[key].c_str());
				//g_mapIFName.add(ipport, it->mifDescr[newkey]);
				g_mapIFName.add(ipport, ifsname_tmp[newkey]);
			}
		}

		it->ifNum = ifnamemap.size();
		
		if( strcasecmp(it->manustr.c_str(), "Cisco") == 0 ) //只针对cisco设备
		{
			ifnamemap.clear();
			if (SNMP_ERROR_SUCCESS != it->mSnmpWrapper->send_sync_walk_request(
				ifs_alias.c_str(),
				ifnamemap))
			{
				it->mSnmpWrapper->close_session();
				for( map<string,string>::iterator it_name = ifsname_tmp.begin(); it_name != ifsname_tmp.end(); it_name++ )
				{
					it->mifDescr[it_name->first]= make_pair( it_name->second, "");
				}
				continue;
			}

			for (CDPWALK_RESULT_ITERATOR it_if = ifnamemap.begin();
				it_if != ifnamemap.end();
				it_if++)
			{
				string	key = it_if->first;
				string	newkey = key.substr(key.rfind(".") + 1);

				//it->mifDescr[newkey] = FormatMonitorObjectName(
				//	(char *)(it_if->second.c_str()));
				//不会存在ifsname_tmp[newkey]找不到的情况
				it->mifDescr[newkey] = make_pair( ifsname_tmp[newkey], FormatMonitorObjectName((char *)(it_if->second.c_str())) );

			}
		}
		else
		{
			for( map<string,string>::iterator it_name = ifsname_tmp.begin(); it_name != ifsname_tmp.end(); it_name++ )
			{
				it->mifDescr[it_name->first]= make_pair( it_name->second, "");
			}
		}
	}
}

void CGetDeviceInfoThread::GetDeviceVtpInfo(void)
{
	//string vtp_bv_oid = "1.3.6.1.4.1.9.9.46.1.1";	//vtp版本基本信息oid
	string	vtp_bs_oid = "1.3.6.1.4.1.9.9.46.1.2.1.1";	//vtp状态基本信息oid
	for (vector<SInfoHost>::iterator it = m_hosts.begin();
		 it != m_hosts.end();
		 it++)
	{
		if (!it->SysName.empty()
		&&	strcasecmp(it->manustr.c_str(), "cisco") == 0)
		{
			/*@key: vtp信息的索引; @value: vtp指标值*/
			CDPWALK_RESULT	vtpmap;
			VtpValue val;

			if (NULL == it->mSnmpWrapper
			||	(
					!it->mSnmpWrapper->is_opened()
			&&	!it->mSnmpWrapper->open_session()
			))
			{
				printf(
					"device ip=[%s] name=[%s] snmpwrapper session open fail.\n",
					it->name,
					it->SysName.c_str());
				continue;
			}

			string	res;
			int restype;
			if (SNMP_ERROR_SUCCESS != it->mSnmpWrapper->
					send_sync_get_request(
					"1.3.6.1.4.1.9.9.46.1.1.1.0",
				res,
				restype))
			{
				it->mSnmpWrapper->close_session();
				continue;
			}

			val.vtpVersion = atoi(res.c_str());
			res = "";
			if (SNMP_ERROR_SUCCESS != it->mSnmpWrapper->
					send_sync_get_request(
					"1.3.6.1.4.1.9.9.46.1.1.2.0",
				res,
				restype))
			{
				it->mSnmpWrapper->close_session();
				continue;
			}

			val.vtpMaxVlanStorage = atoi(res.c_str());
			if (SNMP_ERROR_SUCCESS != it->mSnmpWrapper->
					send_sync_walk_request(vtp_bs_oid.c_str(), vtpmap))
			{
				it->mSnmpWrapper->close_session();
				continue;
			}

			for (CDPWALK_RESULT_ITERATOR it_vtp = vtpmap.begin();
				 it_vtp != vtpmap.end();
				 it_vtp++)
			{
				int index = 0;
				size_t	found1 = it_vtp->first.rfind(".");
				if (found1 != std::string::npos)
				{
					size_t	found2 = it_vtp->first.rfind(".", found1 - 1);
					if (found2 != std::string::npos)
					{
						index = atoi(
								(
									it_vtp->first.substr(
											found2 + 1,
											found1 - found2 - 1)
								).c_str());
						switch (index)
						{
							case 2:
								val.manageDName = it_vtp->second;
								break;
							case 3:
								val.manageDLocalMode = atoi(it_vtp->second.c_str());
								break;
							case 4:
								val.manageDConfigRevNumber = atoi(
										it_vtp->second.c_str());
								break;
							case 5:
								val.manageDLastUpdater = it_vtp->second;
								break;
							case 6:
								val.manageDLastChange = it_vtp->second;
								break;
							case 10:
								val.manageDPruningState = atoi(
										it_vtp->second.c_str());
								break;
							case 11:
								val.manageDVersionInUse = atoi(
										it_vtp->second.c_str());
								break;
							default:
								break;
						}
					}	// end if find2
				}		// end if find1
			}			// end for vtmap

			it->mListVtpValue.push_back(val);
		}				// end if(!it->SysName.empty()
	}					// end for( vector<SInfoHost>::iterator it = m_hosts.begin()
}

void CGetDeviceInfoThread::GetDeviceTrunkInfo(void)
{
	string	trunk_oid = "1.3.6.1.4.1.9.9.46.1.6.1.1";	//cisco trunk信息对应的root oid
	int id[] = { 3, 5, 13, 14 };
	char oid_buff[64] = { 0 };

	for (vector<SInfoHost>::iterator it = m_hosts.begin();
		 it != m_hosts.end();
		 it++)
	{
		if (NULL == it->mSnmpWrapper
		||	(
				!it->mSnmpWrapper->is_opened()
		&&	!it->mSnmpWrapper->open_session()
		))
		{
			continue;
		}

		/*@key: oid值; @value: oid变量的值*/
		CDPWALK_RESULT	value_map;

		sprintf(oid_buff, "%s.%d", trunk_oid.c_str(), id[0]);
		if (SNMP_ERROR_SUCCESS != it->mSnmpWrapper->send_sync_walk_request(
				oid_buff,
			value_map))
		{
			continue;
		}

		for (CDPWALK_RESULT_ITERATOR it_trunk = value_map.begin();
			 it_trunk != value_map.end();
			 it_trunk++)
		{
			TrunkValue	val;
			int restype;

			val.trunkPortEncapsulationType = atoi(it_trunk->second.c_str());

			size_t	pos = it_trunk->first.rfind(".");
			if (pos != string::npos)
			{
				int key;
				key = atoi((it_trunk->first.substr(pos + 1)).c_str());

				string	res = "";
				memset(oid_buff, 0, 64);
				sprintf(oid_buff, "%s.%d.%d", trunk_oid.c_str(), id[1], key);
				it->mSnmpWrapper->send_sync_get_request(oid_buff, res, restype);
				val.trunkPortNativeVlan = atoi(res.c_str());

				res = "";
				memset(oid_buff, 0, 64);
				sprintf(oid_buff, "%s.%d.%d", trunk_oid.c_str(), id[2], key);
				it->mSnmpWrapper->send_sync_get_request(oid_buff, res, restype);
				val.trunkPortDynamicState = atoi(res.c_str());

				res = "";
				memset(oid_buff, 0, 64);
				sprintf(oid_buff, "%s.%d.%d", trunk_oid.c_str(), id[3], key);
				it->mSnmpWrapper->send_sync_get_request(oid_buff, res, restype);
				val.trunkPortDynamicStatus = atoi(res.c_str());

				it->mTrunkMap[key] = val;
			}
		}
	}
}

void CGetDeviceInfoThread::GetDeviceHsrpInfo(void)
{
	string	hsrp_oid = "1.3.6.1.4.1.9.9.106.1.2.1.1";	//cisco hsrp信息对应的root oid
	int id[] = { 1, 3, 11, 13, 14, 15 };
	char oid_buff[64] = { 0 };
}

void CGetDeviceInfoThread::GetDeviceRouteInfo(void)
{
}

void CGetDeviceInfoThread::GetDeviceStpInfo(void)
{
}

void CGetDeviceInfoThread::Run(void)
{
	//判断设备snmp是否可用
	printf(
		"thread id = [%d]: do attemptSnmp range with %s, hostnum=%d.\n",
		thread_id,
		m_hosts.begin()->name,
		m_hosts.size());
	DoAttemptSnmp(&(*m_hosts.begin()), m_hosts.size());

	//通过snmp查询设备基本信息，主机名，描述，设备端口数
	printf(
		"thread id = [%d]: get device base infomation range with %s, hostnum=%d.\n",
		thread_id,
		m_hosts.begin()->name,
		m_hosts.size());
	GetDeviceBaseInfo(&(*m_hosts.begin()), m_hosts.size());

	//获取探测请求的设备信息
	//GetDecDeviceInfo( &(*m_hosts.begin()), m_hosts.size() );
	//获取设备的接口信息
	printf(
		"thread id = [%d]: get device interface infomation  range with %s, hostnum=%d.\n",
		thread_id,
		m_hosts.begin()->name,
		m_hosts.size());
	GetDeviceInterface();

	//获取设备模块信息
	printf(
		"thread id = [%d]: get device module infomation  range with %s, hostnum=%d.\n",
		thread_id,
		m_hosts.begin()->name,
		m_hosts.size());

	//GetDeviceModule();
	GetDeviceModuleInfo();

	//获取每个设备host的cdplist
	printf(
		"thread id = [%d]: get device cdp infomation  range with %s, hostnum=%d.\n",
		thread_id,
		m_hosts.begin()->name,
		m_hosts.size());
	GetDeviceCdps();

	g_bThreadActiveFlag = true;
	return;
}
