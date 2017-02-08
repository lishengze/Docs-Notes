/////////////////////////////////////////////////////////////////////////
///@system	������ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CAsyncGetDevices.cpp
///@brief	ʵ����CAsyncGetDevicesʹ�õ���
///@history
///20100920	�ܽ���		�������ļ�
#include "CAsyncGetDevices.h"
#include "CSynConnector.h"

extern map<string, string>	ip_objId;

char *g_pMEMName[][3] =
{
	{ "memoryPoolUsed", "memoryPoolFree", "memoryPoolTotal" },
	{ "nsResMemAllocate", "nsResMemLeft", "" },
	{ "", "memoryFreeStats", "totalMemoryStats" },
	{ "sysHostMemoryUsed", "", "sysHostMemoryTotal" }
};

//key @string oidvalue, value @string attrname
map<string, string> g_mapoidAttr;

// add by cao.ning. ��̬��Ա������ʼ���������豸�ĸ���ָ��
multimap<string, CMonDevice::AttrFormular> CMonDevice::m_gCompoundAttrFormulars;

/* @return 1 on success, or 0 on failure 
*  Oidת��Ϊ�ַ�������
*/
int OidToStr(
	oid *srcOid,
	unsigned long size,
	char *outString,
	size_t	&how_many_bytes)
{
	outString[0] = 0;

	// verify there is something to copy
	if (size == 0)
	{
		return 0;
	}

	sprintf(outString, "%lu", srcOid[0]);
	for (int index = 1; index < size; index++)
	{
		sprintf(outString + strlen(outString), ".%lu", srcOid[index]);
	}

	how_many_bytes = strlen(outString);
	return 1;
}

char *MemStrReplace(const char *ori)
{
	if (strlen(ori) > 0)
	{
		for (int i = 1; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (strcasecmp(ori, g_pMEMName[i][j]) == 0)
				{
					return g_pMEMName[0][j];
				}
			}
		}
	}

	return NULL;
}
////ָ��YYYYMMDDHH24MISS�͵�ʱ�䣬��ʽ��Ϊtime_t�͵�ʱ��
time_t FormatTime2(char * szTime)
{
        struct tm tm1;
        time_t time1;

		sscanf(szTime, "%4d%2d%2d%2d:%2d:%2d",     
                     &tm1.tm_year, 
                     &tm1.tm_mon, 
                     &tm1.tm_mday, 
                     &tm1.tm_hour, 
                     &tm1.tm_min,
                     &tm1.tm_sec);
               
        tm1.tm_year -= 1900;
          tm1.tm_mon --;

        tm1.tm_isdst=-1;
    
        time1 = mktime(&tm1);
        return time1;
}


void CMonDevice::InitCompoundAttrs(char* _fileName)
{
	CXMLDoc *pCfgDoc = new CXMLDoc();

	try
	{
		pCfgDoc->read(_fileName);

		CXMLNode *pCfgRoot = pCfgDoc->getRootNode();
		if (!pCfgRoot)
		{
			printf("no root node in cfg %s\n", _fileName);
			delete pCfgDoc;
			return;
		}

		//CompoundAttrs info
		CXMLNode *pCompoundAttrsConfig = pCfgRoot->findNode(
			XMLTag,
			"CompoundAttrs",
			NULL,
			NULL);
		if (pCompoundAttrsConfig == NULL)
		{
			printf("Can not find <CompoundAttrs> in file %s. Using old computation method for compound attrs\n", _fileName);
			delete pCfgDoc;
			return;
		}

		CXMLNodeList *pNodeList = pCompoundAttrsConfig->getNodeList();
		if (pNodeList != NULL)
		{
			for (int i = 0; i < pNodeList->size(); i++)
			{
				CXMLNode *pCurrentNode = (*pNodeList)[i];
				string attrName = pCurrentNode->findProperty("name");
				//string attrItems = pCurrentNode->findProperty("items");
				string attrExpress = pCurrentNode->findProperty("express");
				if (attrName.empty() || attrExpress.empty())
				{
					continue;
				}

				AttrFormular _CompAttrFormular;
				// ��ʽ����?
				bool _formularError = false;
				string _tempStr; // ��ʱ��Ź�ʽ�еı���
				for (int i = 0, itemStart = -1; i < attrExpress.size(); ++i)
				{
					if (isalpha(attrExpress[i]) || attrExpress[i] == ':' || attrExpress[i] == '$')
					{
						_tempStr.push_back(attrExpress[i]);	// �����������
					}
					else // ��ǰ�ǲ�����
					{
						if (!_tempStr.empty())	// _tempStr�Ѿ��洢��ǰһ����������
						{
							DeviceCompAttr::CompAttrVariate _attrVar;
							if (!_attrVar.setVariate(_tempStr))
							{
								_formularError = true;
								break;
							}
							_CompAttrFormular.push_back(_attrVar);
						}
						_tempStr = attrExpress[i];
						// push back ������
						DeviceCompAttr::CompAttrVariate _attrVar;
						if (!_attrVar.setVariate(_tempStr))
						{
							_formularError = true;
							break;
						}
						_CompAttrFormular.push_back(_attrVar);
						
						_tempStr.clear();
					}
				}
				if (!_tempStr.empty() && !_formularError)	// push back���ı���������
				{
					DeviceCompAttr::CompAttrVariate _attrVar;
					if (_attrVar.setVariate(_tempStr))
					{
						_CompAttrFormular.push_back(_attrVar);
					}
					else
					{
						_formularError = true;
					}
					
				}
				// ��鹫ʽ�Ƿ���ȷ
				if (!_formularError)
				{
					m_gCompoundAttrFormulars.insert(make_pair(attrName, _CompAttrFormular));
				}

			}
		}
	}
	catch (CParseError * e)
	{
		delete e;
		delete pCfgDoc;
		printf("XML: File %s explain failed!\n", _fileName);
		return;
	}
	delete pCfgDoc;
}


void CMonDevice::UpdateCompoundAttrOid(const char* _oidEName, const char* _oidString)
{
	multimap<string, AttrFormular>::iterator itFormular = m_gCompoundAttrFormulars.begin(),
											 itFormularEnd = m_gCompoundAttrFormulars.end();

	for (; itFormular != itFormularEnd; ++itFormular)
	{
		AttrFormular::iterator	itVariate = itFormular->second.begin(),
								itVariateEnd = itFormular->second.end();
		for (; itVariate != itVariateEnd; ++itVariate)
		{
			if ((itVariate->m_type == Variate || itVariate->m_type == VariateLast)
				&& itVariate->m_VarName.compare(_oidEName) == 0)
			{
				// VarName�ɳ�ʼ��OidEname���ΪOID�ַ���
				itVariate->m_VarName = _oidString;
			}
		}
	}
}

void CMonDevice::updateHostName(const char *pNewHostName)
{
	if (m_sHostName.compare(pNewHostName) != 0)
	{
		///�����豸������������������ͱ��֪ͨ��������Ӧ���¼�
				///......
		m_sHostName = pNewHostName;
	}
}

bool CMonDevice::openSnmpSession(int nNow)
{
	m_bActiveFlag = false;

	if (m_pSnmpWrapper)
	{
		for (m_mapIt = m_mapOid.begin(); m_mapIt != m_mapOid.end(); m_mapIt++)
		{
			if (m_mapIt->second.m_pTimePolicy == NULL)				//Ѳ��ָ��
			{
				if (m_mapIt->second.type == LOOP_TASK
				&&	m_mapIt->second.exestate == PREPARE_STATUS)
				{
					if (SNMP_ERROR_SUCCESS == m_pSnmpWrapper->
							send_async_walk_request(
							m_mapIt->second.m_sOoid,
						m_mapIt->second.m_nOidLen))
					{
						m_mapIt->second.exestate = UNWORK_STATUS;	//��״̬Ϊ��Ч��2
						m_mapIt++;
						return true;
					}

					continue;
				}
			}
			else	//������ָ��
			{
				if ((
						m_mapIt->second.type == ONCE_TASK
				&&	m_mapIt->second.exestate == PREPARE_STATUS
				)
				||	(
						m_mapIt->second.exestate != UNWORK_STATUS
				&&	m_mapIt->second.m_pTimePolicy->ShouldRun(nNow)
				))
				{
					if (SNMP_ERROR_SUCCESS == m_pSnmpWrapper->
							send_async_walk_request(
							m_mapIt->second.m_sOoid,
						m_mapIt->second.m_nOidLen))
					{
						//active_hosts++;//����һ����Ծ��host
						m_bActiveFlag = true;
						if (m_mapIt->second.exestate == PREPARE_STATUS)
						{
							m_mapIt->second.exestate = NORMAL_STATUS;	//��״̬Ϊ������1
						}

						m_nNow = nNow;
						m_mapIt++;
						return true;
					}

					m_mapIt++;
					break;
				}
			}
		}
	}
	else
	{
		m_pSnmpWrapper = new CSnmpWrapper(m_sCommunity, m_sDevName);

		if (!m_pSnmpWrapper->open_session())
		{
			delete m_pSnmpWrapper;
			m_pSnmpWrapper = NULL;
			return false;
		}

		m_mapIt = m_mapOid.begin();

		//string res;
		if (SNMP_ERROR_SUCCESS == m_pSnmpWrapper->send_async_get_request(
				m_sSysNameOoid,
			m_nSysNameOidLen))
		{
			m_bActiveFlag = true;
			m_nNow = nNow;
			return true;
		}
		else
		{
			return false;
		}
	}

	return true;
}

bool CMonDevice::set_next_oid(void)
{
	//������һ������
	for (; m_mapIt != m_mapOid.end(); m_mapIt++)
	{
		//��������
		if (m_mapIt->second.m_pTimePolicy == NULL)
		{
			if (m_mapIt->second.type == LOOP_TASK
			&&	m_mapIt->second.exestate == PREPARE_STATUS)
			{
				if (SNMP_ERROR_SUCCESS == m_pSnmpWrapper->
						send_async_walk_request(
						m_mapIt->second.m_sOoid,
					m_mapIt->second.m_nOidLen))
				{
					m_mapIt->second.exestate = UNWORK_STATUS;			//��״̬Ϊ��Ч��2
					m_mapIt++;
					return true;
				}
				else
				{
					//����ʧ�ܣ��������豸��
					break;
				}
			}
		}
		else
		{
			if ((
					m_mapIt->second.type == ONCE_TASK
			&&	m_mapIt->second.exestate == PREPARE_STATUS
			)
			||	(
					m_mapIt->second.exestate != UNWORK_STATUS
			&&	m_mapIt->second.m_pTimePolicy->ShouldRun(m_nNow)
			))
			{
				if (SNMP_ERROR_SUCCESS == m_pSnmpWrapper->
						send_async_walk_request(
						m_mapIt->second.m_sOoid,
					m_mapIt->second.m_nOidLen))
				{
					if (m_mapIt->second.exestate == PREPARE_STATUS)
					{
						m_mapIt->second.exestate = NORMAL_STATUS;		//��״̬Ϊ������1
					}

					m_mapIt++;
					return true;
				}
				else
				{
					//����ʧ�ܣ��������豸��
					break;
				}
			}
		}
	}	//end for

	return false;
}

double CMonDevice::computerAttrPerS(string oidvalue, CFTDRtnObjectAttrField &fieldInfo)
{
	if( g_mapoidAttr.find( oidvalue ) == g_mapoidAttr.end() )
	{
		//��û�ж��ĸ�ָ�����ͣ��ϸ�������Ӧ�û���Ҫ��鱾�豸�Ƿ������ָ��
		return -1;
	}

	map<string, CFTDRtnObjectAttrField>::iterator it = m_mapLastField.find(oidvalue);
	if( it == m_mapLastField.end() )
	{
		m_mapLastField[oidvalue] = fieldInfo;
		return -1;
	}
	
	char t1_buff[20] = "\0";
	char t0_buff[20] = "\0";
	sprintf(t1_buff,"%s%s",fieldInfo.MonDate.getValue(),fieldInfo.MonTime.getValue());
	sprintf(t0_buff,"%s%s",it->second.MonDate.getValue(),it->second.MonTime.getValue());
	double cost = difftime( FormatTime2(t1_buff), FormatTime2(t0_buff) );

	double newSessionnum = atol(fieldInfo.AttrValue.getValue())-atol(it->second.AttrValue.getValue());
	newSessionnum = newSessionnum/cost;

	if(oidvalue.compare("1.3.6.1.4.1.3375.2.1.1.2.1.3.0")==0
	|| oidvalue.compare("1.3.6.1.4.1.3375.2.1.1.2.1.5.0")==0)  //���������㣬byteת��Ϊbit
	{
		newSessionnum = newSessionnum * 8;
	}

	char buff[20] = "\0";
	sprintf(buff,"%ld",(long)newSessionnum);
	//���������Field��Ϣ
	m_mapLastField[oidvalue] = fieldInfo;

	fieldInfo.AttrType = g_mapoidAttr[oidvalue].c_str();
	fieldInfo.AttrValue = buff;
	m_pListObjectAttr->add(fieldInfo);

	return newSessionnum;
}


double CMonDevice::analyze_mem_result(const char *oidname, DATAMAP *dp)
{
	char buff[256] = "\0";
	float iused = 0;
	float itotal = 0;
	float ifree = 0;
	double	rate = 0.01;
	string	index_str;
	if (!strcmp(oidname, "1.3.6.1.4.1.9.9.48.1.1.1"))				//cisco used(5),free(6)
	{
		for (DATAMAPITERATOR it = dp->begin(); it != dp->end(); ++it)
		{
			memset(buff, 0, 256);
			sprintf(buff, "%s.%s", oidname, "5");
			if (it->first.find(buff) != string::npos)
			{
				index_str = it->first.substr(strlen(buff) + 1);
				iused += atof(it->second.datavalue.c_str()) / 1024;
				memset(buff, 0, 256);
				sprintf(buff, "%s.%s.%s", oidname, "6", index_str.c_str());
				if (dp->find(buff) != dp->end())
				{
					ifree += atof((*dp)[buff].datavalue.c_str()) / 1024;
				}
			}
		}

		itotal = MAX(iused + ifree, 1);
		rate = iused * 100.0 / itotal;
	}
	else if (!strcmp(oidname, "1.3.6.1.4.1.3224.16.2"))				//Juniper used(1),free(2)
	{
		for (DATAMAPITERATOR it = dp->begin(); it != dp->end(); ++it)
		{
			memset(buff, 0, 256);
			sprintf(buff, "%s.%s", oidname, "1");
			if (it->first.find(buff) != string::npos)
			{
				index_str = it->first.substr(strlen(buff) + 1);
				iused += atof(it->second.datavalue.c_str()) / 1024;
				memset(buff, 0, 256);
				sprintf(buff, "%s.%s.%s", oidname, "2", index_str.c_str());
				if (dp->find(buff) != dp->end())
				{
					ifree += atof((*dp)[buff].datavalue.c_str()) / 1024;
				}
			}
		}

		itotal = MAX(iused + ifree, 1);
		rate = iused * 100.0 / itotal;
	}
	else if (!strcmp(oidname, "1.3.6.1.4.1.26543.2.7.1.1.2.12"))	//Blade total(1),free(2)
	{
		for (DATAMAPITERATOR it = dp->begin(); it != dp->end(); ++it)
		{
			memset(buff, 0, 256);
			sprintf(buff, "%s.%s", oidname, "2");
			if (it->first.find(buff) != string::npos)
			{
				index_str = it->first.substr(strlen(buff) + 1);
				ifree += atof(it->second.datavalue.c_str()) / 1024;
				memset(buff, 0, 256);
				sprintf(buff, "%s.%s.%s", oidname, "1", index_str.c_str());
				if (dp->find(buff) != dp->end())
				{
					itotal += atof((*dp)[buff].datavalue.c_str()) / 1024;
				}
			}
		}

		itotal = MAX(itotal, 1);
		rate = (itotal - ifree) * 100.0 / itotal;
	}
	else if (!strcmp(oidname, "1.3.6.1.4.1.3375.2.1.7.1"))			//F5 total(1),used(2) Host MEM
	{
		for (DATAMAPITERATOR it = dp->begin(); it != dp->end(); ++it)
		{
			memset(buff, 0, 256);
			sprintf(buff, "%s.%s", oidname, "2");
			if (it->first.find(buff) != string::npos)
			{
				index_str = it->first.substr(strlen(buff) + 1);
				iused += atof(it->second.datavalue.c_str()) / 1024;
				memset(buff, 0, 256);
				sprintf(buff, "%s.%s.%s", oidname, "1", index_str.c_str());
				if (dp->find(buff) != dp->end())
				{
					itotal += atof((*dp)[buff].datavalue.c_str()) / 1024;
				}
			}
		}

		itotal = MAX(itotal, 1);
		rate = iused * 100.0 / itotal;
	}
	else if (!strcmp(oidname, "1.3.6.1.4.1.3375.2.1.1.2.1"))			//F5 total(44),used(45) TMM MEM
	{
		for (DATAMAPITERATOR it = dp->begin(); it != dp->end(); ++it)
		{
			memset(buff, 0, 256);
			sprintf(buff, "%s.%s", oidname, "45");
			if (it->first.find(buff) != string::npos)
			{
				index_str = it->first.substr(strlen(buff) + 1);
				iused += atof(it->second.datavalue.c_str()) / 1024;
				memset(buff, 0, 256);
				sprintf(buff, "%s.%s.%s", oidname, "44", index_str.c_str());
				if (dp->find(buff) != dp->end())
				{
					itotal += atof((*dp)[buff].datavalue.c_str()) / 1024;
				}
			}
		}

		itotal = MAX(itotal, 1);
		rate = iused * 100.0 / itotal;
	}

	return rate;
}

void CMonDevice::process_snmp_result_new(void)
{
	if (!m_pSnmpWrapper)
	{
#ifdef PACKAGE_OUTPUT
		printf("m_pSnmpWrapper NULL in process_snmp_result\n");
#endif
		m_bActiveFlag = false;
		return;
	}

	//��������
	m_pSnmpWrapper->recv_async_response();

	//��û�κν��
	if (m_pSnmpWrapper->is_data_map_empty()
	&&	m_pSnmpWrapper->is_timeout_event_empty()
	&&	m_pSnmpWrapper->is_error_event_empty())
	{
		return;
	}

	char buffer[1024] = { 0 };
	if (m_sObjID.length() == 0)
	{
		sprintf(
			buffer,
			"%s.%s.%s",
			m_sCenterName.c_str(),
			m_sSubNetName.c_str(),
			m_sHostName.c_str());
	}
	else
	{
		sprintf(buffer, "%s", m_sObjID.c_str());
	}

	//��¼��ʱ�������־
	CFTDRtnSyslogEventField syslogEvent;
	syslogEvent.ObjectID = buffer;
	syslogEvent.MonDate = m_pDate;
	syslogEvent.MonTime = m_pTime;
	syslogEvent.OccurDate = m_pDate;
	syslogEvent.OccurTime = m_pTime;
	syslogEvent.EventName = EVENT_SNMP_GET_ERROR;
	syslogEvent.FullEventName = "SNMP��ȡ��Ϣʧ��";
	syslogEvent.WarningLevel = "Level4";
	syslogEvent.ProcessFlag = "G";
	syslogEvent.IPAddress = m_sDevName.c_str();

	//�з��ؽ��
	if (!m_pSnmpWrapper->is_data_map_empty())
	{
		//������
		std::string oidname = "";
		std::string attry = "";

		//SNMPRESULTDATA data;
		DATAMAP dm;

		if (m_pSnmpWrapper->pop_one_walk_data(oidname, dm) != 0)
		{
#ifdef PACKAGE_OUTPUT
			printf(
				"datamap not empty, but pop nothing in process_snmp_result\n");
#endif
		}
		else
		{
			printf(
				"process device ip [%s], monitor object id [%s] with attribute type [%s].\n",
				m_sDevName.c_str(),
				buffer,
				oidname.c_str());

			map<string, CVarOid>::iterator	it_var = m_mapOid.find(oidname);
			if (it_var != m_mapOid.end())						//����û�ҵ�ʱ,�Զ����key=oidbuf,value=""�Ķ���.
			{
				if (it_var->second.m_sAttendValue.length() > 0) //����Ҫ�����ֶ�
				{	//��Ҫ�����ֶ�
					sprintf(
						buffer + strlen(buffer),
						".%s",
						it_var->second.m_sAttendValue.c_str());
				}
			}

			CFTDRtnObjectAttrField	fieldInfo;
			fieldInfo.ObjectID = buffer;
			fieldInfo.MonDate = m_pDate;
			fieldInfo.MonTime = m_pTime;

			if (strcmp(oidname.c_str(), SNMPSYSNAMEOID))				//���豸��ָ��
			{
				map<string, string>::iterator it = m_mapOidAttr.find(oidname);
				if (it != m_mapOidAttr.end())
				{
					attry = m_mapOidAttr[oidname];
				}
				else
				{
					printf(
						"no attr type with the oidname=[%s]. \n",
						oidname.c_str());

					//������һ������
					set_next_oid();
					return;
				}
				//������豸��ĳЩָ��д���������Ա������豸�����ָ��
				//if( buffer && attry )
				//{
				//	writeAttrField(attry,buffer,dm);
				//}

				DATAMAPITERATOR it_data = dm.begin();

				//data.datatype = it_data->second.datatype;
				fieldInfo.ValueType = it_data->second.datatype;

				if (attry.find("MEMUsage") != string::npos)
				{
					double	rate = analyze_mem_result(oidname.c_str(), &dm);
					double _CAresult = CalculateCompoundAttr(attry.c_str(), dm, 
						fieldInfo.MonDate.getValue(), fieldInfo.MonTime.getValue());
					// ���㷵��С����MEMUSAGEӦΪ�ٷֱ�
					if (_CAresult != CMonDevice::DeviceCompAttr::NULLValue)
					{
						_CAresult *= 100;
					}

					printf("[CalculateCompoundAttr][%s] New[%.4f] Old[%.4f]\n", attry.c_str(),
						_CAresult == CMonDevice::DeviceCompAttr::NULLValue ? -1 : _CAresult, rate);
					if (_CAresult == CMonDevice::DeviceCompAttr::NULLValue)
					{
						printf("\t[CalculateCompoundAttr Error][%s -1][%s]\n", attry.c_str(), m_sObjID.c_str());
					}
					if (rate > 0.01)
					{
						fieldInfo.AttrType = attry.c_str();

						char rate_buff[8] = "\0";
						sprintf(rate_buff, "%.2f", rate);
						fieldInfo.AttrValue = rate_buff;
						fieldInfo.ValueType = FLOAT_ATTR;

						m_pListObjectAttr->add(fieldInfo);
					}
					else
					{
						printf("computer memusage error.\n");
						set_next_oid();
						return;
					}
				}
				else if(attry.find("ScreenCounter") != string::npos)
				{
					int counter = 0;
					fieldInfo.AttrType = attry.c_str();
					for(; it_data != dm.end(); it_data++)
					{
						if( it_data->first.rfind(".2") == it_data->first.length()-2 )
						{
							if( it_data->first.compare("1.3.6.1.4.1.3224.3.2.1.1.2")==0 
							||it_data->first.compare("1.3.6.1.4.1.3224.3.2.1.2.2")==0
							||it_data->first.compare("1.3.6.1.4.1.3224.3.2.1.32.2")==0 )
							{
								continue;
							}
							counter += atoi(it_data->second.datavalue.c_str());
						}
					}
					char datacounter[32] = "\0";
					sprintf(datacounter, "%d", counter);
					fieldInfo.AttrValue = datacounter;
					m_pListObjectAttr->add(fieldInfo);
				}
				else
				{
					if (dm.size() == 1)									//dm.size() == 1������ָ�꣬dm.size()>1������ָ��
					{
						//char *p = NULL;
						////p = MemStrReplace( attry.c_str() );

						fieldInfo.AttrType = attry.c_str();
						fieldInfo.AttrValue = it_data->second.datavalue.c_str();

						m_pListObjectAttr->add(fieldInfo);

						//���뷢��config�Ķ���
						if (it_var != m_mapOid.end()
						&&	it_var->second.type == ONCE_TASK)
						{
							m_pListConObjectAttr->add(fieldInfo);
						}

						//����ָ���ڵ�λʱ���ڵ�����
						if(g_mapoidAttr.find( it_data->first ) != g_mapoidAttr.end())
						{
							double rate = computerAttrPerS(it_data->first, fieldInfo);
							
							double _CAresult = CalculateCompoundAttr(attry.c_str(), dm,
								fieldInfo.MonDate.getValue(), fieldInfo.MonTime.getValue());

							string outputString = "[nsNewSessionPers][DATA] ";
							for (map<string, SNMPRESULTDATA>::iterator itData = dm.begin();
								itData != dm.end(); ++itData)
							{
								char _buff[512] = { 0 };
								sprintf(_buff, "[%s %s] ", itData->first.c_str(), itData->second.datavalue.c_str());
								outputString += _buff;
							}
							printf("[CalculateCompoundAttr] %s\n", outputString.c_str());

							printf("[CalculateCompoundAttr][nsNewSessionPers][%s] New[%.4f] Old[%.4f]\n", attry.c_str(),
								_CAresult == CMonDevice::DeviceCompAttr::NULLValue ? -1 : _CAresult, rate);
							if (_CAresult == CMonDevice::DeviceCompAttr::NULLValue)
							{
								printf("\t[CalculateCompoundAttr Error][nsNewSessionPers][%s -1][%s]\n", attry.c_str(), m_sObjID.c_str());
							}
							
						}
					}
					else if (dm.size() > 1)
					{
						if ((it_data->second.datatype == INT_ATTR)
						&&	(attry.find("memory") != string::npos))		//�ڴ�
						{
							long sum = 0;
							for (; it_data != dm.end(); it_data++)
							{
								sum += atol(it_data->second.datavalue.c_str());
							}

							sum = (sum == 0 ? 1 : sum);

							char buf[16] = "\0";
							sprintf(buf, "%ld", sum);

							//char *pStr = NULL;
							////pStr = MemStrReplace( attry.c_str() );
							fieldInfo.AttrType = attry.c_str();
							fieldInfo.AttrValue = buf;

							m_pListObjectAttr->add(fieldInfo);
						}
						else if ((it_data->second.datatype == INT_ATTR)
							 &&	 (attry.find("CPU") != string::npos))	//cpu
						{
							//char buf[16]="\0";
							//sprintf(buf,"%ld", it_data->second.datavalue.c_str());
							fieldInfo.AttrType = attry.c_str();
							for(; it_data != dm.end(); it_data++)
							{
								fieldInfo.AttrValue = it_data->second.datavalue.c_str();	//����豸ȡ�����б�ĵ�һ��ֵ
								m_pListObjectAttr->add(fieldInfo);
							}

							//string temp_res;
							//for (; it_data != dm.end(); it_data++)                     //��������ֵ by Lee 2014.7.7
							//{
							//	if(temp_res.length() != 0)
							//	{
							//		temp_res.append(";");
							//	}
							//	temp_res += it_data->second.datavalue;
							//}
							//fieldInfo.AttrValue = temp_res.c_str();
							//m_pListObjectAttr->add(fieldInfo);
						}
						else
						{
							for (; it_data != dm.end(); it_data++)  //������ָ�꣬һ�㴦��ʽ
							{
								char attr_buff[32] = { 0 };
								sprintf(
									attr_buff,
									"%s:%s",
									attry.c_str(),
									(
										it_data->first.substr(
												oidname.length() + 1)
									).c_str());

								char *p = NULL;
								while ((p = strchr(attr_buff, '.')) != NULL)
								{
									*p = '_';
								}

								fieldInfo.AttrType = attr_buff;
								fieldInfo.AttrValue = it_data->second.datavalue.c_str();

								m_pListObjectAttr->add(fieldInfo);

								//���뷢��config�Ķ���
								if (it_var != m_mapOid.end()
								&&	it_var->second.type == ONCE_TASK)
								{
									m_pListConObjectAttr->add(fieldInfo);
								}
							}
						}						//end else
					}							// end else if( dm.size() > 1 )
				}								//end else attry.find("MEMUsage")
			}
		}

		//������һ������
		if (set_next_oid())
		{
			return;
		}
	}
	else if (!m_pSnmpWrapper->is_timeout_event_empty())
	{
		//����ʱ�¼�
		std::string key;
		time_t	happentime;
		if (m_pSnmpWrapper->pop_timeout_event(key, happentime) != 0)
		{
#ifdef PACKAGE_OUTPUT
			printf(
				"timeoutevent not empty, but pop nothing in process_snmp_result\n");
#endif
		}

		if (m_mapEventFlag[buffer] == 0)
		{
			m_mapEventFlag[buffer] = 1;
			sprintf(
				buffer,
				"%s Snmp Get Timeout.",
				m_pSnmpWrapper->get_peer_name().c_str());
			syslogEvent.EventDes = buffer;
			m_pListSyslogEvent->add(syslogEvent);
		}
	}
	else if (!m_pSnmpWrapper->is_error_event_empty())
	{
		//��������¼�
		std::string key;
		std::string errstr;
		if (m_pSnmpWrapper->pop_error_event(key, errstr) != 0)
		{
#ifdef PACKAGE_OUTPUT
			printf(
				"errorevent not empty, but pop nothing in process_snmp_result\n");
#endif
		}
		else
		{
			if (m_mapEventFlag[buffer] == 0)
			{
				m_mapEventFlag[buffer] = 1;
				syslogEvent.EventDes = errstr.c_str();
				m_pListSyslogEvent->add(syslogEvent);
			}
		}
	}

	m_bActiveFlag = false;						//*****��Ҫ�ı�ʶ�����ڼ���豸����һ�ֿ�ʼ��
}

void CMonDevice::process_snmp_result(void)
{
	if (!m_pSnmpWrapper)
	{
#ifdef PACKAGE_OUTPUT
		printf("m_pSnmpWrapper NULL in process_snmp_result\n");
#endif
		m_bActiveFlag = false;
		return;
	}

	//��������
	m_pSnmpWrapper->recv_async_response();

	//��û�κν��
	if (m_pSnmpWrapper->is_data_map_empty()
	&&	m_pSnmpWrapper->is_timeout_event_empty()
	&&	m_pSnmpWrapper->is_error_event_empty())
	{
		return;
	}

	char buffer[1024] = { 0 };
	if (m_sObjID.length() == 0)
	{
		sprintf(
			buffer,
			"%s.%s.%s",
			m_sCenterName.c_str(),
			m_sSubNetName.c_str(),
			m_sHostName.c_str());
	}
	else
	{
		sprintf(buffer, "%s", m_sObjID.c_str());
	}

	//��¼��ʱ�������־
	CFTDRtnSyslogEventField syslogEvent;

	syslogEvent.ObjectID = buffer;
	syslogEvent.MonDate = m_pDate;
	syslogEvent.MonTime = m_pTime;
	syslogEvent.OccurDate = m_pDate;
	syslogEvent.OccurTime = m_pTime;
	syslogEvent.EventName = EVENT_SNMP_GET_ERROR;
	syslogEvent.FullEventName = "SNMP��ȡ��Ϣʧ��";
	syslogEvent.WarningLevel = "Level4";
	syslogEvent.ProcessFlag = "G";
	syslogEvent.IPAddress = m_sDevName.c_str();

	//�з��ؽ��
	if (!m_pSnmpWrapper->is_data_map_empty())
	{
		//������
		std::string oidname = "";
		std::string attry = "";

		//SNMPRESULTDATA data;
		DATAMAP dm;

		if (m_pSnmpWrapper->pop_one_walk_data(oidname, dm) != 0)
		{
#ifdef PACKAGE_OUTPUT
			printf(
				"datamap not empty, but pop nothing in process_snmp_result\n");
#endif
		}
		else
		{
			if (strcmp(oidname.c_str(), SNMPSYSNAMEOID))
			{
				printf(
					"process device ip [%s], monitor object id [%s] with attribute type [%s].\n",
					m_sDevName.c_str(),
					buffer,
					oidname.c_str());

				CFTDRtnObjectAttrField	fieldInfo;

				map<string, CVarOid>::iterator	it_var = m_mapOid.find(oidname);
				if (it_var != m_mapOid.end())	//����û�ҵ�ʱ,�Զ����key=oidbuf,value=""�Ķ���.
				{
					if (it_var->second.m_sAttendValue.length() > 0) //����Ҫ�����ֶ�
					{				//��Ҫ�����ֶ�
						sprintf(
							buffer + strlen(buffer),
							".%s",
							it_var->second.m_sAttendValue.c_str());
					}
				}

				map<string, string>::iterator it = m_mapOidAttr.find(oidname);
				if (it != m_mapOidAttr.end())
				{
					attry = m_mapOidAttr[oidname];
				}
				else
				{
					printf(
						"no attr type with the oidname=[%s]. \n",
						oidname.c_str());
					return;
				}

				fieldInfo.ObjectID = buffer;
				fieldInfo.MonDate = m_pDate;
				fieldInfo.MonTime = m_pTime;

				DATAMAPITERATOR it_data = dm.begin();

				//data.datatype = it_data->second.datatype;
				fieldInfo.ValueType = it_data->second.datatype;

				if (dm.size() == 1) //dm.size() == 1������ָ�꣬dm.size()>1������ָ��
				{
					char *p = MemStrReplace(attry.c_str());
					fieldInfo.AttrType = (p != NULL) ? p : attry.c_str();
					fieldInfo.AttrValue = it_data->second.datavalue.c_str();

					m_pListObjectAttr->add(fieldInfo);

					//���뷢��config�Ķ���
					if (it_var != m_mapOid.end()
					&&	it_var->second.type == ONCE_TASK)
					{
						m_pListConObjectAttr->add(fieldInfo);
					}
				}
				else if (dm.size() > 1)
				{
					if ((it_data->second.datatype == INT_ATTR)
					&&	(
							(attry.find("CPU") != string::npos)
					||	(attry.find("memory") != string::npos)
					))
					{
#if 0
						char buf[16] = "\0";
						long max_attr;
						for (; it_data != dm.end(); it_data++)
						{
							max_attr = atol(
									it_data->second.datavalue.c_str()) > max_attr ? atol(
									it_data->second.datavalue.c_str()) : max_attr;
						}

						sprintf(buf, "%ld", max_attr);
#endif

						long sum = 0;
						for (; it_data != dm.end(); it_data++)
						{
							sum += atol(it_data->second.datavalue.c_str());
						}

						sum = sum / dm.size();
						sum = (sum == 0 ? 1 : sum);

						char buf[16] = "\0";
						sprintf(buf, "%ld", sum);

						char *pStr = MemStrReplace(attry.c_str());
						fieldInfo.AttrType = (pStr != NULL) ? pStr : attry.c_str();
						fieldInfo.AttrValue = buf;

						m_pListObjectAttr->add(fieldInfo);

						//���뷢��config�Ķ���
						if (it_var != m_mapOid.end()
						&&	it_var->second.type == ONCE_TASK)
						{
							m_pListConObjectAttr->add(fieldInfo);
						}
					}
					else
					{
						for (; it_data != dm.end(); it_data++)
						{
							char attr_buff[32] = { 0 };
							sprintf(
								attr_buff,
								"%s:%s",
								attry.c_str(),
								(it_data->first.substr(oidname.length() + 1)).c_str());

							char *p = NULL;
							while ((p = strchr(attr_buff, '.')) != NULL)
							{
								*p = '_';
							}

							fieldInfo.AttrType = attr_buff;
							fieldInfo.AttrValue = it_data->second.datavalue.c_str();

							m_pListObjectAttr->add(fieldInfo);

							//���뷢��config�Ķ���
							if (it_var != m_mapOid.end()
							&&	it_var->second.type == ONCE_TASK)
							{
								m_pListConObjectAttr->add(fieldInfo);
							}
						}
					}
				}
			}
		}

		////������һ������
		for (; m_mapIt != m_mapOid.end(); m_mapIt++)
		{
			//��������
			if (m_mapIt->second.m_pTimePolicy == NULL)
			{
				if (m_mapIt->second.type == LOOP_TASK
				&&	m_mapIt->second.exestate == PREPARE_STATUS)
				{
					if (SNMP_ERROR_SUCCESS == m_pSnmpWrapper->
							send_async_walk_request(
							m_mapIt->second.m_sOoid,
						m_mapIt->second.m_nOidLen))
					{
						m_mapIt->second.exestate = UNWORK_STATUS;		//��״̬Ϊ��Ч��2
						m_mapIt++;
						return;
					}
					else
					{
						break;
					}
				}
			}
			else
			{
				if ((
						m_mapIt->second.type == ONCE_TASK
				&&	m_mapIt->second.exestate == PREPARE_STATUS
				)
				||	(
						m_mapIt->second.exestate != UNWORK_STATUS
				&&	m_mapIt->second.m_pTimePolicy->ShouldRun(m_nNow)
				))
				{
					if (SNMP_ERROR_SUCCESS == m_pSnmpWrapper->
							send_async_walk_request(
							m_mapIt->second.m_sOoid,
						m_mapIt->second.m_nOidLen))
					{
						if (m_mapIt->second.exestate == PREPARE_STATUS)
						{
							m_mapIt->second.exestate = NORMAL_STATUS;	//��״̬Ϊ������1
						}

						m_mapIt++;
						return;
					}
					else
					{
						//����ʧ�ܣ�����
						break;
					}
				}
			}
		}	///end for
	}
	else if (!m_pSnmpWrapper->is_timeout_event_empty())
	{
		//����ʱ�¼�
		std::string key;
		time_t	happentime;
		if (m_pSnmpWrapper->pop_timeout_event(key, happentime) != 0)
		{
#ifdef PACKAGE_OUTPUT
			printf(
				"timeoutevent not empty, but pop nothing in process_snmp_result\n");
#endif
		}

		if (m_mapEventFlag[buffer] == 0)
		{
			m_mapEventFlag[buffer] = 1;
			sprintf(
				buffer,
				"%s Snmp Get Timeout.",
				m_pSnmpWrapper->get_peer_name().c_str());
			syslogEvent.EventDes = buffer;
			m_pListSyslogEvent->add(syslogEvent);
		}
	}
	else if (!m_pSnmpWrapper->is_error_event_empty())
	{
		//��������¼�
		std::string key;
		std::string errstr;
		if (m_pSnmpWrapper->pop_error_event(key, errstr) != 0)
		{
#ifdef PACKAGE_OUTPUT
			printf(
				"errorevent not empty, but pop nothing in process_snmp_result\n");
#endif
		}
		else
		{
			if (m_mapEventFlag[buffer] == 0)
			{
				m_mapEventFlag[buffer] = 1;
				syslogEvent.EventDes = errstr.c_str();
				m_pListSyslogEvent->add(syslogEvent);
			}
		}
	}

	m_bActiveFlag = false;
}


// _AttrName��ָ�����ƣ���MEMUsage
// _Data��ͨ��SNMP�ɼ��������ݼ��ϣ������ݼ��а�����ָ����ʹ�õ�����
map<string, CMonDevice::DeviceCompAttr>::iterator
CMonDevice::AddCompoundAttr(const char* _AttrName, DATAMAP &_Data)
{
	multimap<string, AttrFormular>::iterator
		itFormular = m_gCompoundAttrFormulars.begin(),
		itFormularEnd = m_gCompoundAttrFormulars.end();
	
	while (itFormular != itFormularEnd)
	{
		AttrFormular &attrFormular = itFormular->second;		// ��ʽ�еı����б�
		for (vector< DeviceCompAttr::CompAttrVariate >::iterator iterItem = attrFormular.begin();
			iterItem != attrFormular.end();
			++iterItem)
		{
			if (iterItem->m_type == Variate || iterItem->m_type == VariateLast)
			{
				string &oidString = iterItem->m_VarName;
				// �����ݼ��в��Ҷ�Ӧ��OID�����ҵ�����ʾ���豸���ڸø���ָ�����ݣ�����Ӹ���ָ�깫ʽ
				for (DATAMAP::iterator iterData = _Data.begin();
					iterData != _Data.end();
					++iterData)
				{
					// �ҵ���Ӧ��OID
					if (iterData->first.find(oidString) != string::npos)
					{
						goto WhetherFind;	// ֱ������ѭ��
					}
				}
			}
		}
		++itFormular;
	}

WhetherFind:
	// ��û�ҵ�����iterCompAttrFormularָ��end()
	if (itFormular == itFormularEnd)
	{
		return m_CompoundAttrs.end();
	}

	// ���ɸ��豸�ĸ���ָ�������Ϣ
	DeviceCompAttr thisComAttr;
	// ��Ź�ʽ��Ϣ
	thisComAttr.m_CompAttrFormular = itFormular->second;

	m_CompoundAttrs.insert(make_pair(_AttrName, thisComAttr));

	return m_CompoundAttrs.find(_AttrName);
}


bool CMonDevice::UpdataCompoundValues(
	map<string, DeviceCompAttr>::iterator _iterCompAttrInfo,
	DATAMAP &_Data, 
	time_t _NowTime_t)
{
	if (_iterCompAttrInfo == m_CompoundAttrs.end())
	{
		return false;
	}
	// ��¼ʱ��
	_iterCompAttrInfo->second.m_LastTime = _iterCompAttrInfo->second.m_CurrTime;
	_iterCompAttrInfo->second.m_CurrTime = _NowTime_t;
	// �����б�
	vector<DeviceCompAttr::CompAttrVariate> &ItemList = _iterCompAttrInfo->second.m_CompAttrFormular;
	// ���������б����ݱ�����OIDȥ���ݼ��в�����Ӧ������
	for (vector<DeviceCompAttr::CompAttrVariate>::iterator iterItem = ItemList.begin();
		iterItem != ItemList.end();
		++iterItem)
	{
		if (iterItem->m_type == Operator || iterItem->m_type == VariateTime)
		{
			continue;
		}
		// ʹ��currvalue ���� lastvalue
		iterItem->m_LastValue = iterItem->m_CurrValue;
		iterItem->m_CurrValue = DeviceCompAttr::NULLValue;

		// ʹ�û�ȡ�������ݸ���currvalue
		string &itemOID = iterItem->m_VarName;
		double _value = 0.0;
		for (DATAMAP::iterator iterData = _Data.begin();
			iterData != _Data.end();
			++iterData)
		{
			if (iterData->first.find(itemOID) != string::npos
				&&
				(iterData->second.datatype == INT_ATTR
				|| iterData->second.datatype == FLOAT_ATTR
				|| iterData->second.datatype == PERCENT_ATTR))
			{
				_value += atof(iterData->second.datavalue.c_str());
			}
		}
		if (_value != 0.0)
		{
			iterItem->m_CurrValue = _value;
		}
	}

	// ������ɺ��жϵ�ǰ����ָ��ı��������Ƿ��Ѿ�����
	for (vector<DeviceCompAttr::CompAttrVariate>::iterator itItem = ItemList.begin();
		itItem != ItemList.end(); ++itItem)
	{
		if ((itItem->m_type == Variate && itItem->m_CurrValue == DeviceCompAttr::NULLValue)
			|| 
			(itItem->m_type == VariateLast && itItem->m_LastValue == DeviceCompAttr::NULLValue))
		{
			return false;
		}
	}

	// ���б������ѱ���ֵ���򷵻�true
	return true;
}


// _AttrNameָ�����ƣ���MEMUsage��������Ϊ��̨���ص�ָ������
// _OidName,OID�ַ���
// _Data�����ݼ�
double CMonDevice::CalculateCompoundAttr(
	const char* _AttrName, 
	DATAMAP &_Data, 
	const char* _MonDate, 
	const char* _MonTime)
{
	map<string, DeviceCompAttr>::iterator iterCompoundAttrInfo = m_CompoundAttrs.find(_AttrName);
	// ��ǰ�豸û�жԸ�ָ��ĸ�����Ϣ����
	if (iterCompoundAttrInfo == m_CompoundAttrs.end())
	{
		// ������Ӹ�����Ϣ
		iterCompoundAttrInfo = AddCompoundAttr(_AttrName, _Data);
		if (iterCompoundAttrInfo == m_CompoundAttrs.end())
		{
			return DeviceCompAttr::NULLValue;
		}
	}

	char nowTime[32] = { 0 };
	sprintf(nowTime, "%s%s", _MonDate, _MonTime);
	// ���Ӹ���ָ����Ϣ�ɹ��󣬸���ָ��ֵ
	if (!UpdataCompoundValues(iterCompoundAttrInfo, _Data, FormatTime2(nowTime)))
	{
		return DeviceCompAttr::NULLValue;
	}

	// �����б�����ֵ���걸������ݱ��ʽ���м���
	double _compoundValue = iterCompoundAttrInfo->second.Calculate();
	return _compoundValue == DeviceCompAttr::NULLValue ? DeviceCompAttr::NULLValue : _compoundValue;
}

void CAsyncGetDevices::initSnmp(void)
{
	/* Win32: init winsock */
	SOCK_STARTUP;

	// ����mib��Ŀ¼
	netsnmp_set_mib_directory(m_pMibsPath);

	/* initialize library */
	//��ʼ��snmp��
	init_snmp("asynchapp");
}

bool CAsyncGetDevices::startAllHost(int nNow)
{
	time_t	nTime = time((time_t *)NULL);
	struct tm tm_time;
	LocalTime(&nTime, &tm_time);
	strftime(m_time, 10, "%H:%M:%S", &tm_time);
	strftime(m_date, 10, "%Y%m%d", &tm_time);

	map<string, CMonDevice>::iterator itDev;

	CSynConnector *pSyncConnector = CSynConnector::GetInstancePoint();

	m_mapDevicelock.Lock();

	//printf("get the m_mapDevicelock lock in function [%s].\n",__FUNCTION__ );//__func__);
	for (itDev = m_mapDevices.begin(); itDev != m_mapDevices.end(); itDev++)
	{
		if (pSyncConnector != NULL
		&&	pSyncConnector->IsBingTetect(itDev->first.c_str())) //��ǰ����̽�Ȿ�豸
		{
			continue;
		}

		itDev->second.openSnmpSession(nNow);
	}

	m_mapDevicelock.UnLock();

	//printf("free the m_mapDevicelock lock in function [%s].\n",__FUNCTION__ );
	return true;
}

bool CAsyncGetDevices::run(int nNow)
{
	/* loop while any active hosts */
	while (1)
	{
		//ֻҪ�л�Ծ��host��һֱ����
		map<string, CMonDevice>::iterator itDev;
		m_mapDevicelock.Lock();

		//printf("get the m_mapDevicelock lock in function [%s].\n",__FUNCTION__ );
		for (itDev = m_mapDevices.begin(); itDev != m_mapDevices.end(); itDev++)
		{
			if (false == itDev->second.m_bActiveFlag)
			{
				continue;
			}

			if (NULL == itDev->second.m_pSnmpWrapper)
			{
#ifdef PACKAGE_OUTPUT
				printf(
					"m_pSnmpWrapper NULL for device %s\n",
					itDev->first.c_str());
#endif
				itDev->second.m_bActiveFlag = false;
				continue;
			}

			//��������
			//itDev->second.process_snmp_result();	
			itDev->second.process_snmp_result_new();
		}

		for (itDev = m_mapDevices.begin(); itDev != m_mapDevices.end(); itDev++)
		{
			if (itDev->second.m_bActiveFlag)
			{
				break;
			}
		}

		if (itDev == m_mapDevices.end())
		{
#ifdef PACKAGE_OUTPUT
			//			printf("m_bActiveFlag m_nThreadId %d\n",m_nThreadId);
#endif
			m_mapDevicelock.UnLock();
			break;
		}

		m_mapDevicelock.UnLock();

		//printf("free the m_mapDevicelock lock in function [%s].\n",__FUNCTION__ );
	}

#ifdef PACKAGE_OUTPUT
	//printf("m_nThreadId %d\n",m_nThreadId);
#endif

	//loop������ر�����snmp session
	//snmp session ������һֱ���֣����ر�, 20100920
	//for (map<string, CMonDevice>::iterator itDev = m_mapDevices.begin(); itDev != m_mapDevices.end(); itDev++)
	//{
	//	if (itDev->second.m_pSnmpSession != NULL)
	//	{
	//		snmp_sess_close(itDev->second.m_pSnmpSession);
	//		itDev->second.m_pSnmpSession = NULL;
	//	}
	//}
	return true;
}

//Traditional        Single                    Comment
//===========        ==============            =======
//snmp_sess_init     snmp_sess_init            Call before either open
//snmp_open          snmp_sess_open            Single not on Sessions list
//snmp_sess_session         Exposes snmp_session pointer
//snmp_send          snmp_sess_send            Send one APDU
//snmp_async_send    snmp_sess_async_send      Send one APDU with callback
//snmp_select_info   snmp_sess_select_info     Which session(s) have input
//snmp_read          snmp_sess_read            Read APDUs
//snmp_timeout       snmp_sess_timeout         Check for timeout
//snmp_close         snmp_sess_close           Single not on Sessions list
//snmp_synch_response snmp_sess_synch_response  Send/receive one APDU
//snmp_error         snmp_sess_error           Get library,system errno

//

//////generate the attr & event data for test
void CAsyncGetDevices::genOneDateField(std::pair<int, string> &data)
{
	CFTDRtnObjectAttrField netObjectattr;
	CFTDRtnWarningEventField warningEvent;

	char buffer[128];

	//string appstr;
	char flag;
	int type;
	char ip[16], infoname[32],
				infs[32],
				szInfo[128],
				appendStr[32];
	int iRtn;

	memset(ip, 0, 16);
	memset(infoname, 0, 32);
	memset(infs, 0, 32);
	memset(szInfo, 0, 128);
	memset(appendStr, 0, 32);

	switch (data.first)
	{
		//172.1.37.102 ifOperStatus 2 1 GabitEthernet4/4
		case 'A':
			iRtn = sscanf(
					data.second.c_str(),
					"%s %s %d %s %[^\n]\n",
					ip,
					infoname,
					&type,
					szInfo,
					appendStr);

			if (appendStr[0] != 0)
			{
				sprintf(buffer, "%s.%s", ip_objId[ip].c_str(), appendStr);
			}
			else if (szInfo[0] == 0)
			{
				switch (type)
				{
					case 1: //int
						sprintf(szInfo, "%d", rand() % 100);
						break;
					case 2: //string
						sprintf(szInfo, "%s", "example_data");
						break;
					default:
						break;
				}
			}

			netObjectattr.ObjectID = buffer;
			netObjectattr.AttrType = infoname;

			netObjectattr.MonDate = m_date;
			netObjectattr.MonTime = m_time;

			netObjectattr.ValueType = type;
			netObjectattr.AttrValue = szInfo;

			m_listObjectAttr.add(netObjectattr);

			//SLEEP(5*1000);
			break;
		case 'W':
			//172.1.37.101 portdown 1 N GabitEthernet4/8 Interface state change to down
			iRtn = sscanf(
					data.second.c_str(),
					"%s %s %d %c %s %[^\n]\n",
					ip,
					infoname,
					&type,
					&flag,
					infs,
					szInfo);

			//if( infs[0] == 'G')
			//{
			//	appstr = "G";
			//	char *p = strchr(infs, '/');
			//	if( p!=NULL )
			//	{
			//		p--;
			//		appstr.append( p );
			//	}				
			//}
			sprintf(buffer, "%s.%s", ip_objId[ip].c_str(), infs);

			warningEvent.ObjectID = buffer;
			warningEvent.MonDate = m_date;
			warningEvent.MonTime = m_time;

			warningEvent.OccurDate = m_date;
			warningEvent.OccurTime = m_time;

			warningEvent.EventName = infoname;

			warningEvent.EventType = type;
			warningEvent.WarningLevel = "Level4";

			warningEvent.EventDes = szInfo;
			warningEvent.ProcessFlag = flag;

			m_listWarningEvent.add(warningEvent);

			if (data.second.find("up") != string::npos)
			{
				warningEvent.ProcessFlag = "A";
				m_listWarningEvent.add(warningEvent);
			}

			break;
	}
}

//////generate the attr & event data for test
void CAsyncGetDevices::genDataField(list<pair<int, string> > &datas)
{
	CFTDRtnObjectAttrField netObjectattr;
	CFTDRtnWarningEventField warningEvent;
	CFTDRtnSyslogEventField syslogEvent;
	CFTDRtnUpdateSysConfigField updatesysConfig;

	char buffer[128];
	string appstr;

	for (list < pair<int, string> >::iterator it = datas.begin();
		 it != datas.end();
		 it++)
	{
		char flag;
		int type;
		char ip[16], infoname[32],
					infs[32],
					szInfo[128],
					szHostname[32];
		int iRtn;

		switch (it->first)
		{
			//172.1.37.102 ifOperStatus 2 1 GabitEthernet4/4
			case 'A':
				iRtn = sscanf(
						it->second.c_str(),
						"%s %s %d %s %[^\n]\n",
						ip,
						infoname,
						&type,
						szInfo,
						szHostname);

				if (szHostname[0] == 'G')
				{
					appstr = "G";

					char *p = strchr(szHostname, '/');
					if (p != NULL)
					{
						p--;
						appstr.append(p);
					}
				}

				sprintf(buffer, "%s.%s", ip_objId[ip].c_str(), appstr.c_str());

				netObjectattr.ObjectID = buffer;
				netObjectattr.AttrType = infoname;

				netObjectattr.MonDate = m_date;
				netObjectattr.MonTime = m_time;

				netObjectattr.ValueType = type;
				netObjectattr.AttrValue = szInfo;

				m_listObjectAttr.add(netObjectattr);

				//SLEEP(5*1000);
				break;
			case 'W':
				//172.1.37.101 portdown 1 N GabitEthernet4/8 Interface state change to down
				iRtn = sscanf(
						it->second.c_str(),
						"%s %s %d %c %s %[^\n]\n",
						ip,
						infoname,
						&type,
						&flag,
						infs,
						szInfo);

				if (infs[0] == 'G')
				{
					appstr = "G";

					char *p = strchr(infs, '/');
					if (p != NULL)
					{
						p--;
						appstr.append(p);
					}
				}

				sprintf(buffer, "%s.%s", ip_objId[ip].c_str(), appstr.c_str());

				warningEvent.ObjectID = buffer;
				warningEvent.MonDate = m_date;
				warningEvent.MonTime = m_time;

				warningEvent.OccurDate = m_date;
				warningEvent.OccurTime = m_time;

				warningEvent.EventName = infoname;

				warningEvent.EventType = type;
				warningEvent.WarningLevel = "Level4";

				warningEvent.EventDes = szInfo;
				warningEvent.ProcessFlag = flag;

				m_listWarningEvent.add(warningEvent);

				if (it->second.find("up") != string::npos)
				{
					warningEvent.ProcessFlag = "A";
					m_listWarningEvent.add(warningEvent);
				}

				break;
			case 'S':
				syslogEvent.ObjectID = buffer;
				syslogEvent.MonDate = m_date;
				syslogEvent.MonTime = m_time;
				syslogEvent.OccurTime = m_time;
				syslogEvent.EventName = EVENT_SNMP_GET_ERROR;
				syslogEvent.FullEventName = "SNMP��ȡ��Ϣʧ��";
				syslogEvent.WarningLevel = "Level4";
				syslogEvent.ProcessFlag = "G";
				m_listSyslogEvent.add(syslogEvent);
				break;
			case 'U':
				m_listUpdateConfig.add(updatesysConfig);
				break;
		}
	}
}


const double CMonDevice::DeviceCompAttr::NULLValue = DBL_MAX;
// ��ʽ����
double CMonDevice::DeviceCompAttr::Calculate()
{
	stack<double> NumStack;	// ������ջ
	stack<char> OperStack;	// ������ջ

	// ������ʽ
	for (vector<CompAttrVariate>::iterator itFormularItem = m_CompAttrFormular.begin();
		itFormularItem != m_CompAttrFormular.end();
		++itFormularItem)
	{
		if (itFormularItem->m_type == Operator)
		{
			char _currOper = (itFormularItem->m_VarName)[0];	// ��ǰ������
			// ������
			if (OperStack.empty())		// ��ջ��ֱ��push
			{
				OperStack.push(_currOper);
				continue;
			}
			char _lastOper = OperStack.top();
			char _priority = OperatorsPriority(_lastOper, _currOper);
			switch (_priority)
			{
			case '<':	// ջ����������ȼ�С�ڵ�ǰ���������ǰ�������ջ
				OperStack.push(_currOper);
				break;
			case '>':	// ջ����������ȼ����ڵ�ǰ���ȼ���ȡջ����������м���
			{
				if (NumStack.size() < 2) return NULLValue;		// ������ջ��С��2�����޷�����
				double _value2 = NumStack.top(); NumStack.pop();
				double _value1 = NumStack.top(); NumStack.pop();
				double _res = OperatorCalculate(_value1, _lastOper, _value2);
				if (_res == DBL_MAX) return NULLValue;
				NumStack.push(_res);
				OperStack.pop();	// ԭ��������ջ
				--itFormularItem;		// ���˵���ǰ������
				break;
			}
			case '=':	// ��ǰ��)��ջ����(��ֱ�ӳ�ջ
				OperStack.pop();
				break;
			case '0':	// ��ʾ����
				return NULLValue;
			default:
				break;
			}
		}
		else
		{
			switch (itFormularItem->m_type)
			{
			case Variate:	// ��ͨ����
				// ��������ջ
				NumStack.push(itFormularItem->m_CurrValue);
				break;
			case VariateLast:	// ����ǰһֵ
				// ��������ջ
				if (itFormularItem->m_LastValue == NULLValue) return NULLValue;
				NumStack.push(itFormularItem->m_LastValue);
				break;
			case VariateTime:	// ����ʱ���
				if (m_CurrTime == 0 || m_LastTime == 0) return NULLValue;
				NumStack.push(m_CurrTime - m_LastTime);
				break;
			default:
				break;
			}
			
		}
	}

	// ������ɣ�����Ӧ��ֻ��2��������һ��������

	double _returnValue = NULLValue;	// ����ֵ
	if (NumStack.size() == 2 && OperStack.size() == 1)
	{
		double _value2 = NumStack.top(); NumStack.pop();
		double _value1 = NumStack.top();
		_returnValue = OperatorCalculate(_value1, OperStack.top(), _value2);
	}
	return _returnValue;
}


// DeviceCompAttr �����������ȼ�
static char DCA_OperPriority[][6] = {
	//	  "+", "-", "*", "/", "(", ")" {��ǰ}
		{ '>', '>', '<', '<', '<', '>' },	// +
		{ '>', '>', '<', '<', '<', '>' },	// -
		{ '>', '>', '>', '>', '<', '>' },	// *
		{ '>', '>', '>', '>', '<', '>' },	// /
		{ '<', '<', '<', '<', '<', '=' },	// (
		{ '>', '>', '>', '>', '0', '>' } };	// ) {ջ��}
char CMonDevice::DeviceCompAttr::OperatorsPriority(char currOper, char lastOper)
{
	int v1 = -1, v2 = -1;
	switch (lastOper)
	{
	case '+': v1 = 0; break;
	case '-': v1 = 1; break;
	case '*': v1 = 2; break;
	case '/': v1 = 3; break;
	case '(': v1 = 4; break;
	case ')': v1 = 5; break;
	default:
		break;
	}
	switch (currOper)
	{
	case '+': v2 = 0; break;
	case '-': v2 = 1; break;
	case '*': v2 = 2; break;
	case '/': v2 = 3; break;
	case '(': v2 = 4; break;
	case ')': v2 = 5; break;
	default:
		break;
	}
	if (v1 == -1 || v2 == -1)
	{
		return '0';
	}
	else
	{
		return DCA_OperPriority[v2][v1];
	}
}

double CMonDevice::DeviceCompAttr::OperatorCalculate(double _v1, char _oper, double _v2)
{
	switch (_oper)
	{
	case '+': return _v1 + _v2;
	case '-': return _v1 - _v2;
	case '*': return _v1 * _v2;
	case '/': return _v1 / _v2;
	default: return NULLValue;	// error = max double
	}
}

CMonDevice::DeviceCompAttr::CompAttrVariate::CompAttrVariate() 
	: m_VarName(""), m_CurrValue(NULLValue), m_LastValue(NULLValue)
{

}


bool CMonDevice::DeviceCompAttr::CompAttrVariate::setVariate(string _varName)
{
	if (_varName.length() == 1)		// ������
	{
		if (_varName[0] != '+' && _varName[0] != '-' && _varName[0] != '*'
			&& _varName[0] != '/' && _varName[0] != '(' && _varName[0] != ')')
		{
			return false;	// ����������
		}
		m_type = Operator;
		m_VarName = _varName;
		return true;
	}
	// TIME������ֱ�Ӵ洢
	if (_varName == "$TIME")
	{
		m_type = VariateTime;
	}
	else
	{
		if (_varName.find("LASTVALUE") != string::npos)
		{
			m_type = VariateLast;
			m_VarName = _varName.substr(0, _varName.find(":LASTVALUE"));
		}
		else
		{
			m_type = Variate;
			m_VarName = _varName;
		}
	}
	return true;
}
