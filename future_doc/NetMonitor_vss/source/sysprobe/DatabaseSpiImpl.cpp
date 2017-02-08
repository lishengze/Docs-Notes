/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	DatabaseSpiImpl.cpp
///@brief	ʵ�������ݿ��ȡ̽�����
///@history
///20080508	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
///20091217	�ܽ���		���ݿ�DBConnectLost�¼���������IP��ַ
///20100204	�ܽ���		����ҵ��ϵͳ����SP֮����ϵͳ���û���ֲ�����
///						����Ĵ������öϿ������ݿ����������������ݿ�
/////////////////////////////////////////////////////////////////////////
#include "DatabaseSpiImpl.h"
#include "SyslogSpiImpl.h"
#include "CEventReport.h"

extern char g_pHostName[32];						// ������������
extern char g_pDataCenterName[32];					// ���������������ƣ���TRADE.PuDian
extern char g_pCenterName[32];						// ���洿�����������ƣ���PuDian��ZhangJ
extern int	g_nTimeZoneSec;							// ��������ʱ��
///@key	ҵ��ϵͳID���
///@value	ҵ��ϵͳ����
extern map<string, string>	g_mapSysID;

CDatabaseSpiImpl::CDatabaseSpiImpl(void)
{
	// Added by zhou.jj 20090518
	m_nInterval = 600;								///�澯��ʱ������Ĭ��Ϊ10����
	m_nEventId = 1;
	m_nEventNum = 1;
}

CDatabaseSpiImpl::~CDatabaseSpiImpl(void)
{
	///�ͷŻ�������ݿ���Դ
	for (map < string, SAConnection * >::iterator it = m_dbConnections.begin()
			 ;
	 it != m_dbConnections.end();
		 ++it)
	{
		//it->second->~SAConnection();
		delete it->second;
	}

	m_dbConnections.clear();
}

void CDatabaseSpiImpl::GetDatabaseSpi(time_t nNowTimeSec)
{
	///ÿ�ν������ݿ�ɼ����ڣ�����������ӵ�IsActive��� by zhou.jj 20100407
	m_connActive.clear();

	///======����ɼ������͹����Ĳɼ�������Ϣ���ɼ����ñ����Ϣ
	m_cmdLock.Lock();

	list<CFTDRspQryHostConfigField>::iterator cfgIt;
	for (cfgIt = m_configList.begin(); cfgIt != m_configList.end(); ++cfgIt)
	{
		if (strcmp(cfgIt->CfgType.getValue(), HOSTCFG_REQTYPE_DATABASE) == 0)
		{
			CDBConnectString DBInfo;
			char *p;
			char szTmp[200] = "";
			strcpy(szTmp, cfgIt->CfgLocation.getValue());

			// Mod by Henchi, 20100322 ������ݿ�����Ϣ��
			DBInfo.m_sServiceName = strtok(szTmp, " ");
			p = strtok(NULL, " ");
			if (p)
			{
				DBInfo.m_sRacServiceName = p;
			}
			else
			{
				printf(
					"��������ݿ�������Ϣ [%s]\n",
					cfgIt->CfgLocation.getValue());
				continue;
			}

			p = strtok(NULL, " ");
			if (p)
			{
				DBInfo.m_sIpAddr = p;
			}
			else
			{
				printf(
					"��������ݿ�������Ϣ [%s]\n",
					cfgIt->CfgLocation.getValue());
				continue;
			}

			p = strtok(NULL, " ");
			if (p)
			{
				DBInfo.m_nPort = atoi(p);
			}
			else
			{
				printf(
					"��������ݿ�������Ϣ [%s]\n",
					cfgIt->CfgLocation.getValue());
				continue;
			}

			DBInfo.m_sUserName = cfgIt->CfgHostName.getValue();
			DBInfo.m_sPassword = cfgIt->CfgAttend.getValue();
			DBInfo.m_sDBName = cfgIt->CfgName.getValue();

			string	str = cfgIt->CfgName.getValue();
			UpdateDatabaseInfoMap(str, DBInfo);
		}
		else if (strcmp(cfgIt->CfgType.getValue(), HOSTCFG_REQTYPE_SP) == 0)
		{
			UpdateSPInfoMap(
				cfgIt->CfgName.getValue(),
				cfgIt->CfgLocation.getValue(),
				cfgIt->CfgHostName.getValue(),
				cfgIt->CfgAttend.getValue());
		}
		else if (strcmp(cfgIt->CfgType.getValue(), HOSTCFG_REQTYPE_DBLOG) == 0)
		{
			UpdateDBLogMap(
				cfgIt->CfgName.getValue(),
				cfgIt->CfgLocation.getValue(),
				cfgIt->CfgHostName.getValue(),
				cfgIt->CfgAttend.getValue());
		}
		else if (strcmp(cfgIt->CfgType.getValue(), HOSTCFG_REQTYPE_DBATTR) == 0)
		{
			UpdateDBAttrMap(
				cfgIt->CfgName.getValue(),
				cfgIt->CfgLocation.getValue(),
				cfgIt->CfgHostName.getValue(),
				cfgIt->CfgAttend.getValue());
		}
	}

	m_configList.clear();

	list<CSPQuery>::iterator qryIt;
	for (qryIt = m_spQueryList.begin(); qryIt != m_spQueryList.end(); ++qryIt)
	{
		CDBQueryField reqQuery;
		reqQuery.m_attrType = qryIt->attrType.c_str();
		reqQuery.m_objectID = qryIt->objectId.c_str();
		reqQuery.m_reqFlag = false;
		reqQuery.m_requestID = qryIt->requestId;
		reqQuery.m_session = (CFTDCSession *) (qryIt->session);
		m_reqDbQuery.push_back(reqQuery);
	}

	m_spQueryList.clear();
	m_cmdLock.UnLock();

	///++++++����ɼ������͹����Ĳɼ�������Ϣ���ɼ����ñ����Ϣ
	struct tm tm_time;
	LocalTime(&nNowTimeSec, &tm_time);
	strftime(m_mTime, 10, "%H:%M:%S", &tm_time);
	strftime(m_mDate, 10, "%Y%m%d", &tm_time);
	m_ObjAttrInfo.MonTime = m_mTime;
	m_ObjAttrInfo.MonDate = m_mDate;

	time_t	nTimeZone = nNowTimeSec - g_nTimeZoneSec;
	char tmp[64];

	///Ӧ��ͻ���SP���ò�ѯ����
	list<CDBQueryField>::iterator listIt = m_reqDbQuery.begin();
	for (; listIt != m_reqDbQuery.end(); ++listIt)
	{
		if (!listIt->m_reqFlag)
		{
			getReqSP(*listIt);
			listIt->m_reqFlag = true;
		}
	}

	///�洢���̵��� map<string, CDataBaseAttr>	m_SPmap;	//������Ҫ�ɼ���SP��Ϣ
	map<string, CDataBaseAttr>::iterator sepIt = m_SPmap.begin();
	for (; sepIt != m_SPmap.end(); ++sepIt)
	{
		if (!(sepIt->second.needExcute(nTimeZone)))
		{
			continue;
		}

		SAConnection *pConn = getConnectionObj(
				sepIt->second.sDNSName,
				sepIt->second.sReturnType);
		if (NULL == pConn)
		{
			continue;
		}

		getSP(pConn, sepIt->first, sepIt->second);	//sepIt->second.sInstanceName, sepIt->second.sReturnType, sepIt->second.sDNSName);
	}

	///���ݿ���־����� map<string, CDataBaseAttr>	m_DBLogmap;	//������Ҫ�ɼ������ݿ���־����Ϣ
	sepIt = m_DBLogmap.begin();
	for (; sepIt != m_DBLogmap.end(); ++sepIt)
	{
		if (!(sepIt->second.needExcute(nTimeZone)))
		{
			continue;
		}

		SAConnection *pConn = getConnectionObj(
				sepIt->second.sDNSName,
				sepIt->second.sReturnType);
		if (NULL == pConn)
		{
			continue;
		}

		getDBLog(pConn, sepIt->first, sepIt->second);
	}

	///��ȡָ���Ӧ�ı�����ݿ���Ϣ  map<string, CDataBaseAttr>	m_DBAttrSepsMap
	map<string, listTDB>::iterator	msgIt = m_DBAttrMap.begin();
	sepIt = m_DBAttrSepsMap.begin();
	for (;
		 msgIt != m_DBAttrMap.end(), sepIt != m_DBAttrSepsMap.end();
		 ++msgIt, ++sepIt)
	{
		if (!(sepIt->second.needExcute(nTimeZone)))
		{
			continue;
		}

		//---------------------ȡTotalVolume------------------------//
		if (isXProp(msgIt->first.c_str(), "DBTotalVolume"))
		{
			int volume = 0;
			for (listTDB::iterator tblIt = msgIt->second.begin();
				 tblIt != msgIt->second.end();
				 ++tblIt)
			{
				CTableDBRelation *tblDB = &(*tblIt);

				///ȡ���ݿ�Ĳ���
				SAConnection *pConn = NULL;
				pConn = getConnectionObj(tblDB->m_sDbName, "");
				if (NULL == pConn)
				{
					continue;
				}

				volume += getVolume(pConn, tblDB->m_sTableName.c_str());
			}

			sprintf(tmp, "%d", volume);
			sendData(msgIt->first.c_str(), tmp, INT_ATTR);
		}

		//---------------------ȡTotalAmount------------------------//
		else if (isXProp(msgIt->first.c_str(), "DBTotalAmount"))
		{
			double	amount = 0;
			bool haveComp = false;					// ��ʾ���Ƿ�ȷʵ������;
			for (listTDB::iterator tblIt = msgIt->second.begin();
				 tblIt != msgIt->second.end();
				 ++tblIt)
			{
				CTableDBRelation *tblDB = &(*tblIt);
				SAConnection *pConn = NULL;
				pConn = getConnectionObj(tblDB->m_sDbName, "");
				if (NULL == pConn)
				{
					continue;
				}

				amount += getAmount(pConn);
				haveComp = true;
			}

			if (haveComp)
			{
				sprintf(tmp, "%f", amount);
				sendData(msgIt->first.c_str(), tmp, FLOAT_ATTR);
			}
		}

		//---------------------ȡ���ݿ��ļ�¼��------------------------//
		// Caution:�ò��ֱ������������Ա��Ƚ��������жϣ��ٽ�����ͨ��ߴ�ļ���
		else
		{
			long recordNum = 0;
			for (listTDB::iterator tblIt = msgIt->second.begin();
				 tblIt != msgIt->second.end();
				 ++tblIt)
			{
				CTableDBRelation *tblDB = &(*tblIt);

				///ȡ���ݿ�Ĳ���
				SAConnection *pConn = NULL;
				pConn = getConnectionObj(tblDB->m_sDbName, "");
				if (NULL == pConn)
				{
					continue;
				}

				recordNum += getRecordNum(pConn, tblDB->m_sTableName);
			}

			sprintf(tmp, "%d", recordNum);
			sendData(msgIt->first.c_str(), tmp, INT_ATTR);
		}
	}	/// ��������ָ��ļ���

	return;
}

SAConnection *CDatabaseSpiImpl::getConnectionObj(
	const string &dbName,
	const string &returnType)
{
	SAConnection *pConn = NULL;

	///�鿴�Ƿ��Ѿ������Ӿ��
	map<string, SAConnection *>::iterator dbCacheIt;
	dbCacheIt = m_dbConnections.find(dbName);
	if (dbCacheIt != m_dbConnections.end())
	{
		pConn = dbCacheIt->second;
		if (m_DatabaseInfoMap[dbName].m_bReConnectFlag) // ���ݿ������Ӧ�������Ѿ��������Ҫ�����������ݿ�
		{
			delete dbCacheIt->second;
			m_dbConnections.erase(dbCacheIt);
			pConn = NULL;
		}
		else if (isAlive(pConn))						// �жϵ�ǰ������������Ծ
		{
			// ����RAC�����
			if ((returnType.compare(DATACENTERDB) == 0)
			&&	(!m_DatabaseInfoMap[dbName].m_bUpdateRACDB))
			{
				CFTDRtnUpdateSysConfigField fieldInfo;
				fieldInfo.UpdateType = UPDATESYSCONFIG_HOSTIDAPPID;
				sprintf(
					(char *)fieldInfo.OldValue.getValue(),
					"%s.%s.%s",
					g_pDataCenterName,
					DATACENTERHOST,
					g_pHostName);
				sprintf(
					(char *)fieldInfo.NewValue.getValue(),
					"%s%s%s",
					g_pDataCenterName,
					DOTDATACENTERDBDOT,
					m_DatabaseInfoMap[dbName].m_sRacServiceName.c_str());
				m_ObjectIdDBNameMap[fieldInfo.NewValue.getValue()] = dbName;
				m_ObjectIdDBNameMap.erase(fieldInfo.OldValue.getValue());

				m_dataLock.Lock();
				m_updateConfigInfo.push_back(fieldInfo);
				m_dataLock.UnLock();

				m_DatabaseInfoMap[dbName].m_bUpdateRACDB = true;
			}

			// Added by Henchi, 20100324  ������ݿ��ӽڵ�����������Ķ�Ӧ��ϵ
			else if ((returnType.compare(DATACENTERDBNODE) == 0)
				 &&	 (!m_DatabaseInfoMap[dbName].m_bUpdateNodeDB))
			{
				CFTDRtnUpdateSysConfigField fieldInfo;
				fieldInfo.UpdateType = UPDATESYSCONFIG_HOSTIDAPPID;
				sprintf(
					(char *)fieldInfo.OldValue.getValue(),
					"%s.%s.%s",
					g_pDataCenterName,
					DATACENTERHOST,
					g_pHostName);

				// �ڵ���������硰DATABASE.PuDian.db.BDB.BDB1��
				sprintf(
					(char *)fieldInfo.NewValue.getValue(),
					"%s%s%s.%s",
					g_pDataCenterName,
					DOTDATACENTERDBDOT,
					m_DatabaseInfoMap[dbName].m_sRacServiceName.c_str(),
					m_DatabaseInfoMap[dbName].m_sServiceName.c_str());
				m_ObjectIdDBNameMap[fieldInfo.NewValue.getValue()] = dbName;
				m_ObjectIdDBNameMap.erase(fieldInfo.OldValue.getValue());

				m_dataLock.Lock();
				m_updateConfigInfo.push_back(fieldInfo);
				m_dataLock.UnLock();

				m_DatabaseInfoMap[dbName].m_bUpdateNodeDB = true;
			}
			else if ((returnType.compare(DATACENTERAPP) == 0)
				 &&	 (!m_DatabaseInfoMap[dbName].m_bUpdateAppSP))
			{
				CFTDRtnUpdateSysConfigField fieldInfo;
				fieldInfo.UpdateType = UPDATESYSCONFIG_HOSTIDAPPID;
				sprintf(
					(char *)fieldInfo.OldValue.getValue(),
					"%s.%s.%s",
					g_pDataCenterName,
					DATACENTERHOST,
					g_pHostName);

				char tmp[64];
				strcpy(tmp, g_pDataCenterName);

				char *p = strchr(tmp, '.');
				if (p != NULL)
				{
					*p = '\0';
				}

				strcat(tmp, APP_SUFFIX_SP);
				sprintf(
					(char *)fieldInfo.NewValue.getValue(),
					"%s%s%s",
					g_pDataCenterName,
					DOTDATACENTERAPPDOT,
					tmp);
				m_ObjectIdDBNameMap[fieldInfo.NewValue.getValue()] = dbName;
				m_ObjectIdDBNameMap.erase(fieldInfo.OldValue.getValue());

				m_dataLock.Lock();
				m_updateConfigInfo.push_back(fieldInfo);
				m_dataLock.UnLock();

				m_DatabaseInfoMap[dbName].m_bUpdateAppSP = true;
			}

			return pConn;
		}
		else
		{					// ��ǰ���Ӳ���������Ծ������ִ������Ĳ�����������һ������
			//dbCacheIt->second->~SAConnection();
			delete dbCacheIt->second;
			m_dbConnections.erase(dbCacheIt);
			pConn = NULL;
		}
	}

	/// cache��û����ȷ�ģ�������ʹ�õ��������ӣ������µ�����
	map<string, CDBConnectString>::iterator confIt;
	if ((confIt = m_DatabaseInfoMap.find(dbName)) == m_DatabaseInfoMap.end())
	{
		// û�ж�Ӧ�����ݿ��������
		printf("���ݿ� �������� �� �����ò��Ǻ�\n");
		printf("���ݿ����[%s]û�ж�Ӧ�ķ��ʲ�������\n", dbName.c_str());

		/// Mod by Henchi, 20110325
				/// ȡ������ȱʧ�����ݿ����Ӹ澯
#if 0
		char mObject[256];
		sprintf(
			mObject,
			"%s.%s.%s",
			g_pDataCenterName,
			DATACENTERHOST,
			g_pHostName);

		string	sEventDes = dbName;
		sEventDes.append(" ����û�ж�Ӧ�ķ��ʲ�������");
		GenerateProbeEvent(
			EVENT_DBCONNECT_ERROR,
			mObject,
			(char *)sEventDes.c_str(),
			(char *)dbName.c_str());
#endif
		fflush(stdout);
		return pConn;
	}

	CDBConnectString &dbParam = confIt->second;

	//2008.10.29 ��ΪOraclePass���Է��ض��IP��ַ����Ҫ��IP���зֽ�
	char multiIP[256];
	strcpy(multiIP, dbParam.m_sIpAddr.c_str());

	char *p;
	for (p = strtok(multiIP, ","); p != NULL; p = strtok(NULL, ","))
	{
		//pConn = connectDB(dbParam.m_sIpAddr,dbParam.m_nPort,dbParam.m_sServiceName,dbParam.m_sUserName,dbParam.m_sPassword);
		
				/// 20100621 by zhou.jj
		string	dbServiceName;
		if (dbParam.m_sRacServiceName != dbParam.m_sServiceName)
		{
			dbServiceName = dbParam.m_sRacServiceName;
			dbServiceName.append("/");
		}

		dbServiceName.append(dbParam.m_sServiceName);
		pConn = connectDB(
				string(p),
				dbParam.m_nPort,
				dbServiceName,
				dbParam.m_sUserName,
				dbParam.m_sPassword);

		/// 20100621 by zhou.jj
		//pConn = connectDB(string(p),dbParam.m_nPort,dbParam.m_sServiceName,dbParam.m_sUserName,dbParam.m_sPassword);
		if (pConn != NULL)
		{
			if ((returnType.compare(DATACENTERDB) == 0)
			&&	(!m_DatabaseInfoMap[dbName].m_bUpdateRACDB))
			{
				CFTDRtnUpdateSysConfigField fieldInfo;
				fieldInfo.UpdateType = UPDATESYSCONFIG_HOSTIDAPPID;
				sprintf(
					(char *)fieldInfo.OldValue.getValue(),
					"%s.%s.%s",
					g_pDataCenterName,
					DATACENTERHOST,
					g_pHostName);
				sprintf(
					(char *)fieldInfo.NewValue.getValue(),
					"%s%s%s",
					g_pDataCenterName,
					DOTDATACENTERDBDOT,
					m_DatabaseInfoMap[dbName].m_sRacServiceName.c_str());
				m_ObjectIdDBNameMap[fieldInfo.NewValue.getValue()] = dbName;
				m_ObjectIdDBNameMap.erase(fieldInfo.OldValue.getValue());

				m_dataLock.Lock();
				m_updateConfigInfo.push_back(fieldInfo);
				m_dataLock.UnLock();

				m_DatabaseInfoMap[dbName].m_bUpdateRACDB = true;
			}
			else if ((returnType.compare(DATACENTERAPP) == 0)
				 &&	 (!m_DatabaseInfoMap[dbName].m_bUpdateAppSP))
			{
				CFTDRtnUpdateSysConfigField fieldInfo;
				fieldInfo.UpdateType = UPDATESYSCONFIG_HOSTIDAPPID;
				sprintf(
					(char *)fieldInfo.OldValue.getValue(),
					"%s.%s.%s",
					g_pDataCenterName,
					DATACENTERHOST,
					g_pHostName);

				char tmp[64];
				strcpy(tmp, g_pDataCenterName);

				char *p = strchr(tmp, '.');
				if (p != NULL)
				{
					*p = '\0';
				}

				strcat(tmp, APP_SUFFIX_SP);
				sprintf(
					(char *)fieldInfo.NewValue.getValue(),
					"%s%s%s",
					g_pDataCenterName,
					DOTDATACENTERAPPDOT,
					tmp);
				m_ObjectIdDBNameMap[fieldInfo.NewValue.getValue()] = dbName;
				m_ObjectIdDBNameMap.erase(fieldInfo.OldValue.getValue());

				m_dataLock.Lock();
				m_updateConfigInfo.push_back(fieldInfo);
				m_dataLock.UnLock();

				m_DatabaseInfoMap[dbName].m_bUpdateAppSP = true;
			}

			m_DatabaseInfoMap[dbName].m_bReConnectFlag = false;
			m_dbConnections.insert(make_pair(dbName, pConn));
			return pConn;
		}
		else
		{
			//20080918 add by wu.yb
			printf("Connect Database Fail!\n");
			printf(
				"%s,%d,%s,%s,%s\n",
				p,
				dbParam.m_nPort,
				dbParam.m_sServiceName.c_str(),
				dbParam.m_sUserName.c_str(),
				dbParam.m_sPassword.c_str());
			fflush(stdout);
		}
	}

	/// �������Ϊ�գ��������ݿ�����ʧ�ܸ澯������͸澯�¼�
	if (pConn == NULL)
	{
		char mObject[256];
		sprintf(
			mObject,
			"%s.%s.%s",
			g_pDataCenterName,
			DATACENTERHOST,
			g_pHostName);

		string	sEventDes = dbParam.m_sDBName;
		sEventDes.append(" ");
		sEventDes.append(dbParam.m_sServiceName);
		sEventDes.append(" ");
		sEventDes.append(dbParam.m_sIpAddr);
		GenerateProbeEvent(
			EVENT_DBCONNECT_ERROR,
			mObject,
			(char *)sEventDes.c_str(),
			(char *)dbParam.m_sDBName.c_str());
	}

	return pConn;
}

long CDatabaseSpiImpl::getRecordNum(SAConnection *conn, const string &tableName)
{
	int size = 0;
	string	cmdText = getCmdText(tableName);

	try
	{
		SACommand cmd(conn, cmdText.c_str());
		cmd.Execute();
		while (cmd.FetchNext())
		{
			size = cmd.Field(1).asLong();
		}
	}
	catch(SAException & ex)
	{
		printf(
			"%s %s In catch DatabaseSpiImpl getRecordNum() [%s] %s\n",
			m_mDate,
			m_mTime,
			cmdText.c_str(),
			(const char *)ex.ErrText());
		fflush(stdout);
	}

	return size;
}

string CDatabaseSpiImpl::getCmdText(const string &tableName) const
{
	static string sql = "select count(1) from ";
	string	cmdText = sql;
	cmdText += " " + tableName;
	return cmdText;
}

string CDatabaseSpiImpl::getConnectStr(
	const string &ip,
	int port,
	const string &dbName) const
{
	char tmp[10];
	sprintf(tmp, "%d", port);

	string	str = ip + ":";
	str.append(tmp);
	str.append("/" + dbName);
	return str;

	//return ip + ":" + port +"/" + dbName;
}

SAConnection *CDatabaseSpiImpl::connectDB(
	const string &strIp,
	int iPort,
	const string &strDbName,
	const string &strUser,
	const string &strPwd)
{
	SAConnection *conn = new SAConnection;
	try
	{
		conn->Connect(
				getConnectStr(strIp, iPort, strDbName).c_str(),
				strUser.c_str(),
				strPwd.c_str(),
				SA_Oracle_Client);
	}
	catch(SAException & ex)
	{
		printf(
			"%s %s In catch DatabaseSpiImpl connectDB() %s\n",
			m_mDate,
			m_mTime,
			(const char *)ex.ErrText());
		printf(
			"Database Parameters:  %s user=%s  Pwd=%s \n",
			getConnectStr(strIp, iPort, strDbName).c_str(),
			strUser.c_str(),
			strPwd.c_str());
		fflush(stdout);
		try
		{
			conn->Rollback();
		}
		catch(SAException & x)
		{
			printf(
				"%s %s In catch DatabaseSpiImpl connectDB() %s\n",
				m_mDate,
				m_mTime,
				(const char *)x.ErrText());
			fflush(stdout);
		}

		delete conn;
		conn = NULL;
	}

	return conn;
}

void CDatabaseSpiImpl::sendData(
	const char	*attrName,
	const char	*attrValue,
	int valueType)
{
	char *p;

	char szTmp[64] = "";
	strcpy(szTmp, attrName);
	sprintf(m_mObjectId, "%s.app.%s", g_pDataCenterName, strtok(szTmp, "."));
	p = strtok(NULL, ".");
	m_ObjAttrInfo.ObjectID = m_mObjectId;
	m_ObjAttrInfo.AttrType = p ? p : "";
	m_ObjAttrInfo.AttrValue = attrValue;
	m_ObjAttrInfo.ValueType = valueType;

	m_dataLock.Lock();
	m_attrInfo.push_back(m_ObjAttrInfo);
	m_dataLock.UnLock();
}

int CDatabaseSpiImpl::getVolume(SAConnection *conn, const string &tableName)
{
	int size = 0;
	string	cmdText = "select sum(Volume) from ";
	cmdText += tableName;
	try
	{
		SACommand cmd(conn, cmdText.c_str());
		cmd.Execute();
		while (cmd.FetchNext())
		{
			size = cmd.Field(1).asLong();
		}
	}
	catch(SAException & ex)
	{
		printf(
			"%s %s In catch DatabaseSpiImpl getVolume() [%s] %s\n",
			m_mDate,
			m_mTime,
			cmdText.c_str(),
			(const char *)ex.ErrText());
		fflush(stdout);
	}

	return size;
}

double CDatabaseSpiImpl::getAmount(SAConnection *conn)
{
	double	totalAmount = 0;
	try
	{
		string	recStr = "select sum(a.Volume*a.Price*b.VolumeMultiple) from currsgoperation.t_trade a , sync.t_Instrument b where a.InstrumentId = b.InstrumentId";

		SACommand cmd(conn, recStr.c_str());
		cmd.Execute();
		while (cmd.FetchNext())
		{
			totalAmount = cmd.Field(1).asDouble();
		}
	}
	catch(SAException & ex)
	{
		printf(
			"%s %s In catch DatabaseSpiImpl getAmount() %s\n",
			m_mDate,
			m_mTime,
			(const char *)ex.ErrText());
		fflush(stdout);
	}

	return totalAmount;
}

bool CDatabaseSpiImpl::isXProp(const char *orignal, const char *propKey) const
{
	const char	*p = strrchr(orignal, '.');
	if (NULL == p)
	{
		p = orignal;
	}
	else
	{
		++p;
	}

#ifdef WINDOWS
	return (stricmp(p, propKey) == 0);
#else
	return (strcasecmp(p, propKey) == 0);
#endif
}

bool CDatabaseSpiImpl::isAlive(SAConnection *conn)
{
	if (m_connActive[conn]) ///������ӱ��Ϊtrue��ֱ�ӷ���true
	{
		return true;
	}

	try
	{
		/// ֱ��ʹ��commit �Լ� show user������ȷ
				/// 20090624 change by zhou.jj, rename user_tables to dual;
		string	recStr = "select distinct 1 from dual";
		SACommand cmd(conn, recStr.c_str());
		cmd.Execute();
		while (cmd.FetchNext())
		{
		}

		m_connActive[conn] = true;
	}
	catch(SAException & ex)
	{
		m_connActive[conn] = false;
		printf(
			"%s %s In catch DatabaseSpiImpl isAlive() %s\n",
			m_mDate,
			m_mTime,
			(const char *)ex.ErrText());
		fflush(stdout);
#if 0
		char mObject[256];
		sprintf(
			mObject,
			"%s.%s.%s",
			g_pDataCenterName,
			DATACENTERHOST,
			g_pHostName);

		string	sEventDes = "";
		map<string, SAConnection *>::const_iterator it = m_dbConnections.begin();
		for (; it != m_dbConnections.end(); ++it)
		{
			if (it->second == conn)
			{
				sEventDes.append(m_DatabaseInfoMap[it->first].m_sIpAddr);
			}
		}

		sEventDes.append((const char *)ex.ErrText());

		//GenerateProbeEvent(EVENT_DBCONNECT_ERROR, mObject, (char *)sEventDes.c_str());
				/// �������ݿ�����ʧ�ܸ澯������͸澯�¼�
#endif
		return false;
	}

	return true;
}

void CDatabaseSpiImpl::GenerateProbeEvent(
	char *pEventName,
	char *pObjectName,
	char *pEventDes,
	char *pDBName)
{
	time_t	timep = time((time_t *)NULL);
	string	sDBEvent = pDBName;
	sDBEvent.append(pEventName);
	if ((int)timep < (m_mapEventDesc[sDBEvent] + m_nInterval))
	{
		return;
	}

	m_mapEventDesc[sDBEvent] = timep;

	CFTDRtnWarningEventField fieldInfo;
	memset(&fieldInfo, 0, sizeof(fieldInfo));

	fieldInfo.MonDate = m_mDate;
	fieldInfo.MonTime = m_mTime;
	fieldInfo.EventName = pEventName;
	fieldInfo.ObjectID = pObjectName;
	fieldInfo.EvendID = m_nEventId++;
	fieldInfo.EventNum = m_nEventNum;
	fieldInfo.ProcessFlag = "N";
	fieldInfo.EventDes = pEventDes;
	fieldInfo.OccurDate = fieldInfo.MonDate.getValue();
	fieldInfo.OccurTime = fieldInfo.MonTime.getValue();

	if ((strstr(pEventDes, "6508") != NULL)
	||	(strstr(pEventDes, "8103") != NULL))
	{
		CFTDRtnSyslogEventField *pLogEvent = (CFTDRtnSyslogEventField *)
			(&fieldInfo);
		pLogEvent->ProcessFlag = "L";
		m_dataLock.Lock();
		m_syslogInfo.push_back(*pLogEvent);
		m_dataLock.UnLock();
	}
	else
	{
		m_dataLock.Lock();
		m_eventInfo.push_back(fieldInfo);
		m_dataLock.UnLock();
	}
}

void CDatabaseSpiImpl::UpdateConfig(CFTDRspQryHostConfigField *hostConfig)
{
	m_cmdLock.Lock();
	m_configList.push_back(*hostConfig);
	m_cmdLock.UnLock();
	return;
}

void CDatabaseSpiImpl::UpdateSPQuery(
	const char	*pObjectId,
	const char	*pAttrType,
	const DWORD dRequestId,
	const CFTDCSession	*pSession)
{
	m_cmdLock.Lock();
	m_spQueryList.push_back(
			CSPQuery(pObjectId, pAttrType, dRequestId, pSession));
	m_cmdLock.UnLock();
	return;
}

bool CDatabaseSpiImpl::getReqSP(CDBQueryField &cDBQueryField)
{
	SAConnection *conn = NULL;
	try
	{
		/* ����������Ĵ��룬������������ĵ���ͬ���ݿ�ʵ����ͬ����ѯ����
		char *pInstance = strrchr((char *)cDBQueryField.m_objectID.c_str(), '.');
		if (pInstance!=NULL) {
			pInstance ++ ;
			map<string, CDBConnectString>::iterator confIt;
			for (confIt=m_DatabaseInfoMap.begin(); confIt != m_DatabaseInfoMap.end(); ++confIt)
			{
				if ( 0 == confIt->second.m_sRacServiceName.compare(pInstance) )
				{
					conn = getConnectionObj(confIt->first, "");
					break;
				}
			}
		*/
		map<string, string>::iterator dbIt = m_ObjectIdDBNameMap.find(
				cDBQueryField.m_objectID);
		if (dbIt != m_ObjectIdDBNameMap.end())
		{
			conn = getConnectionObj(dbIt->second, "");
			if (NULL == conn)
			{
				// ����
				cDBQueryField.m_rtnCode = -1;
				cDBQueryField.m_rtnMsg = "û���ҵ���ʵ����ӦBNS";
				return false;
			}
		}
		else
		{
			// ����
			cDBQueryField.m_rtnCode = -1;
			cDBQueryField.m_rtnMsg = "�����ObectID����ȷ";
			return false;
		}

		CFTDRspQryDBQueryField	rspQuery;
		rspQuery.ObjectID = cDBQueryField.m_objectID.c_str();
		rspQuery.AttrType = cDBQueryField.m_attrType.c_str();
		rspQuery.MonDate = m_mDate;
		rspQuery.MonTime = m_mTime;

		SACommand cmd(conn, cDBQueryField.m_attrType.c_str());
		cmd.Execute();
		if (cmd.Param("RETCODE").asLong() != 0)		//���ؽ������ȷ
		{
			// ����
			cDBQueryField.m_rtnCode = -1;
			cDBQueryField.m_rtnMsg = "��ѯ���ؽ��Ϊ��0ֵ";
			return false;
		}

		int i;
		char buffer[3000];
		char colbuf[3000];
		char *p;
		char *q;

		SACommand *pRefCursor = cmd.Param("MONCURSOR");
		for (i = 1; i <= pRefCursor->FieldCount(); i++)
		{
			if (i == 1)
			{
				strcpy(colbuf, (const char *)pRefCursor->Field(i).Name());
			}
			else
			{
				sprintf(
					colbuf,
					"%s%s%s",
					colbuf,
					DBSEPARATORSTRING,
					(const char *)pRefCursor->Field(i).Name());
			}
		}

		strcat(colbuf, DBSEPARATORRECORD);
		q = p = (char *)rspQuery.DBQueryResult.getValue();
		strcpy(p, colbuf);
		p = p + strlen(colbuf);

		while (pRefCursor->FetchNext())
		{
			for (i = 1; i <= pRefCursor->FieldCount(); i++)
			{
				SAString sa = pRefCursor->Field(i).asString();
				sa.TrimRight();
				if (i == 1)
				{
					strcpy(buffer, (const char *)sa);
				}
				else
				{
					sprintf(
						buffer,
						"%s%s%s",
						buffer,
						DBSEPARATORSTRING,
						(const char *)sa);
				}
			}

			strcat(buffer, DBSEPARATORRECORD);
			if ((p + strlen(buffer) - q) >= 3500)	//��ǰ���ݰ��Ѿ��������ݣ��ȷŵ����У�Ȼ�����¿�ʼ���
			{
				m_dataLock.Lock();
				cDBQueryField.m_dbQuery.push_back(rspQuery);
				m_dataLock.UnLock();

				p = q;
				strcpy(p, colbuf);
				p = p + strlen(colbuf);
				strcpy(p, buffer);
				p = p + strlen(buffer);
			}
			else
			{
				strcpy(p, buffer);
				p = p + strlen(buffer);
			}
		}

		m_dataLock.Lock();
		cDBQueryField.m_dbQuery.push_back(rspQuery);
		m_dataLock.UnLock();
	}
	catch(SAException & e)
	{
		printf(
			"In catch DatabaseSpiImpl run getRepSP() sql:%s Time %s %s err:%s\n",
			cDBQueryField.m_attrType.c_str(),
			m_mDate,
			m_mTime,
			(const char *)e.ErrText());
		fflush(stdout);
		cDBQueryField.m_rtnCode = -1;
		cDBQueryField.m_rtnMsg = (const char *)e.ErrText();

		/// �������ݿ�����ʧ�ܸ澯������͸澯�¼�
		return false;
	}

	cDBQueryField.m_rtnCode = 0;
	cDBQueryField.m_rtnMsg = "��ȷ";
	return true;
}

bool CDatabaseSpiImpl::getSP(
	SAConnection *conn,
	const string &spName,
	CDataBaseAttr &dataBaseAttr)
{
	try
	{
		map<string, CDBConnectString>::iterator confIt;
		if ((confIt = m_DatabaseInfoMap.find(dataBaseAttr.sDNSName)) == m_DatabaseInfoMap.end())
		{
			// û�ж�Ӧ�����ݿ��������
			printf("���ݿ� �������� �� �����ò��Ǻ�\n");
			printf(
				"���ݿ����[%s]û�ж�Ӧ�ķ��ʲ�������\n",
				dataBaseAttr.sDNSName.c_str());
			fflush(stdout);
			return false;
		}

		if (dataBaseAttr.sReturnType == string(DATACENTERDB))
		{
			sprintf(
				(char *)m_ObjAttrInfo.ObjectID.getValue(),
				"%s%s%s",
				g_pDataCenterName,
				DOTDATACENTERDBDOT,
				confIt->second.m_sRacServiceName.c_str());
		}

		// Added by Henchi, 20100324
		else if (dataBaseAttr.sReturnType == string(DATACENTERDBNODE))
		{
			sprintf(
				(char *)m_ObjAttrInfo.ObjectID.getValue(),
				"%s%s%s.%s",
				g_pDataCenterName,
				DOTDATACENTERDBDOT,
				confIt->second.m_sRacServiceName.c_str(),
				confIt->second.m_sServiceName.c_str());
		}
		else
		{
			char tmp[64];
			strcpy(tmp, g_pDataCenterName);

			char *p = strchr(tmp, '.');
			if (p != NULL)
			{
				*p = '\0';
			}

			strcat(tmp, APP_SUFFIX_SP);
			sprintf(
				(char *)m_ObjAttrInfo.ObjectID.getValue(),
				"%s%s%s",
				g_pDataCenterName,
				DOTDATACENTERAPPDOT,
				tmp);
		}

		m_ObjAttrInfo.ValueType = UNKNOWN_ATTR;

		SACommand cmd(conn, spName.c_str());
		cmd.Execute();
		if (cmd.Param("RETCODE").asLong() != 0)		//���ؽ������ȷ
		{
			printf(
				"In DatabaseSpiImpl excuteSP() sql:%s Time %s %s err:%s\n",
				spName.c_str(),
				m_mDate,
				m_mTime,
				(const char *)cmd.Param("RETMSG").asString());;
			printf(
				"In DatabaseSpiImpl excuteSP() sql, ����ORA-06508 ����, ȡ��һ��ָ��Ͽ�����\n");
			fflush(stdout);

			string	sDesc = spName;
			sDesc.append(" ");
			sDesc.append((const char *)cmd.Param("RETMSG").asString());
			GenerateProbeEvent(
				EVENT_DBEXESP_ERROR,
				(char *)m_ObjAttrInfo.ObjectID.getValue(),
				(char *)sDesc.c_str(),
				"");

			///20100204	�ܽ���,oracle����ֵΪ���󲻴��ڣ��п����Ǹ���SPʱ����ϵͳȥ���ö������������ʱ�������ݿ�
			if (sDesc.find("-06508") != string::npos)
			{
				for (map < string, SAConnection * >::iterator connIter =
						 m_dbConnections.begin();
				 connIter != m_dbConnections.end();)
				{
					if (connIter->second == conn)
					{
						///Mod by Henchi, 20100208
						// ����Linux�����쳣
						//connIter = m_dbConnections.erase(connIter);
						m_dbConnections.erase(connIter++);
					}
					else
					{
						connIter++;
					}
				}

				delete conn;
			}

			return false;
		}

		if (strcmp(dataBaseAttr.sInstanceName.c_str(), SPRETURNNOCURSOR) == 0)		///���ز����α�ļ򵥴洢���̣��ô洢�����ĸ����� OBJECTNAME,OBJECTVAL,RETCODE,RETMSG
		{
			m_ObjAttrInfo.AttrType = (const char *)cmd.Param(
					"OBJECTNAME").asString();
			m_ObjAttrInfo.AttrType.trimRight();

			char *p = strchr((char *)m_ObjAttrInfo.AttrType.getValue(), ' ');
			while (p != NULL)
			{
				*p = '_';
				p++;
				p = strchr(p, ' ');
			}

			p = strchr((char *)m_ObjAttrInfo.AttrType.getValue(), '.');
			while (p != NULL)
			{
				*p = '_';
				p++;
				p = strchr(p, '.');
			}

			m_ObjAttrInfo.AttrValue = (const char *)cmd.Param(
					"OBJECTVAL").asString();
			m_ObjAttrInfo.AttrValue.trimRight();
			if (m_ObjAttrInfo.AttrValue.isNull())
			{
				m_ObjAttrInfo.AttrValue = "NULL";
				m_ObjAttrInfo.ValueType = STRING_ATTR;
			}

			m_dataLock.Lock();
			m_attrInfo.push_back(m_ObjAttrInfo);
			m_dataLock.UnLock();
		}
		else if (strcmp(dataBaseAttr.sInstanceName.c_str(), SPRETURNCURSOR) == 0)	///���غ��α�ļ򵥴洢���̣��ô洢������������ REFCURSOR,RETCODE,RETMSG
		{
			SACommand *pRefCursor = cmd.Param("MONCURSOR");
			while (pRefCursor->FetchNext())
			{
				//m_ObjAttrInfo.AttrType= (const char *)cmd.Param("OBJECTNAME").asString();
				//m_ObjAttrInfo.AttrValue = (const char *)cmd.Param("OBJECTVAL").asString();
				m_ObjAttrInfo.AttrType = (const char *)pRefCursor->Field(
						1).asString();
				m_ObjAttrInfo.AttrType.trimRight();

				char *p = strchr(
						(char *)m_ObjAttrInfo.AttrType.getValue(),
						' ');
				while (p != NULL)
				{
					*p = '_';
					p++;
					p = strchr(p, ' ');
				}

				p = strchr((char *)m_ObjAttrInfo.AttrType.getValue(), '.');
				while (p != NULL)
				{
					*p = '_';
					p++;
					p = strchr(p, '.');
				}

				m_ObjAttrInfo.AttrValue = (const char *)pRefCursor->Field(
						2).asString();
				m_ObjAttrInfo.AttrValue.trimRight();
				if (m_ObjAttrInfo.AttrValue.isNull())
				{
					m_ObjAttrInfo.AttrValue = "NULL";
					m_ObjAttrInfo.ValueType = STRING_ATTR;
				}
				else
				{
					m_ObjAttrInfo.ValueType = UNKNOWN_ATTR;
				}

				m_dataLock.Lock();
				m_attrInfo.push_back(m_ObjAttrInfo);
				m_dataLock.UnLock();
			}
		}
		else if (strcmp(
					 dataBaseAttr.sInstanceName.c_str(),
				 SPRETURNMULTICOL) == 0)					///�����α꺬�ж����,���ڲ������
		{
			int i;
			char buffer[3000];
			char colbuf[3000];
			CFTDRtnDBQueryField fieldQuery;
			fieldQuery.MonDate = m_mDate;
			fieldQuery.MonTime = m_mTime;

			char *q;

			char *p = strrchr((char *)spName.c_str(), '.'); // q��ʼ��ַ��p��ǰ��ʼд��ַ
			if (NULL != p)
			{
				p++;
				fieldQuery.AttrType = p;
			}
			else
			{
				fieldQuery.AttrType = spName.c_str();
			}

			fieldQuery.ObjectID = m_ObjAttrInfo.ObjectID;

			SACommand *pRefCursor = cmd.Param("MONCURSOR");
			for (i = 1; i <= pRefCursor->FieldCount(); i++)
			{
				if (i == 1)
				{
					strcpy(colbuf, (const char *)pRefCursor->Field(i).Name());
				}
				else
				{
					sprintf(
						colbuf,
						"%s%s%s",
						colbuf,
						DBSEPARATORSTRING,
						(const char *)pRefCursor->Field(i).Name());
				}
			}

			strcat(colbuf, DBSEPARATORRECORD);
			q = p = (char *)fieldQuery.DBQueryResult.getValue();
			strcpy(p, colbuf);
			p = p + strlen(colbuf);

			while (pRefCursor->FetchNext())
			{
				for (i = 1; i <= pRefCursor->FieldCount(); i++)
				{
					SAString sa = pRefCursor->Field(i).asString();
					sa.TrimRight();
					if (i == 1)
					{
						strcpy(buffer, (const char *)sa);
					}
					else
					{
						sprintf(
							buffer,
							"%s%s%s",
							buffer,
							DBSEPARATORSTRING,
							(const char *)sa);
					}
				}

				strcat(buffer, DBSEPARATORRECORD);
				if ((p + strlen(buffer) - q) >= 3500)		//��ǰ���ݰ��Ѿ��������ݣ��ȷŵ����У�Ȼ�����¿�ʼ���
				{
					m_dataLock.Lock();
					m_dbqueryInfo.push_back(fieldQuery);
					m_dataLock.UnLock();

					p = q;
					strcpy(p, colbuf);
					p = p + strlen(colbuf);
					strcpy(p, buffer);
					p = p + strlen(buffer);
				}
				else
				{
					strcpy(p, buffer);
					p = p + strlen(buffer);
				}
			}

			m_dataLock.Lock();
			m_dbqueryInfo.push_back(fieldQuery);
			m_dataLock.UnLock();
		}
	}
	catch(SAException & ex)
	{
		printf(
			"In catch DatabaseSpiImpl excuteSP() sql:%s Time %s %s err:%s\n",
			spName.c_str(),
			m_mDate,
			m_mTime,
			(const char *)ex.ErrText());
		printf(
			"In catch DatabaseSpiImpl excuteSP() sql, ����ORA-06508 ����, ȡ��һ��ָ��Ͽ�����\n");
		fflush(stdout);

		string	sDesc = spName;
		sDesc.append(" ");
		sDesc.append((const char *)ex.ErrText());

		/// �������ݿ�����ʧ�ܸ澯������͸澯�¼�
		GenerateProbeEvent(
			EVENT_DBEXESP_ERROR,
			(char *)m_ObjAttrInfo.ObjectID.getValue(),
			(char *)sDesc.c_str(),
			"");

		///20100204	�ܽ���,oracle����ֵΪ���󲻴��ڣ��п����Ǹ���SPʱ����ϵͳȥ���ö������������ʱ�������ݿ�
		if (sDesc.find("-06508") != string::npos)
		{
			for (map < string, SAConnection * >::iterator connIter =
					 m_dbConnections.begin();
			 connIter != m_dbConnections.end();)
			{
				if (connIter->second == conn)
				{
					///Mod by Henchi, 20100208
					// ����Linux�����쳣
					//connIter = m_dbConnections.erase(connIter);
					m_dbConnections.erase(connIter++);
				}
				else
				{
					connIter++;
				}
			}

			delete conn;
		}

		return false;
	}

	return true;
}

#include <iostream>

bool CDatabaseSpiImpl::getDBLog(
	SAConnection *conn,
	const string &tableName,
	CDataBaseAttr &dataBaseAttr)
{
	try
	{
		SACommand cmd;
		cmd.setConnection(conn);

		// by zhou.jj ���ñ�����ʽ����, 20100628
		char sqlBuffer[512];
		if (dataBaseAttr.m_nLogId == 0)
		{
			sprintf(
				sqlBuffer,
				"select logid,opdate,optime,spname,objectname,objectval,systemid from %s where opdate >=:1 and optime >= :2 order by logid",
				tableName.c_str());
			cmd.setCommandText(sqlBuffer);
			cmd <<
				dataBaseAttr.m_sOpDate.c_str() <<
				dataBaseAttr.m_sOpTime.c_str();
		}
		else
		{
			sprintf(
				sqlBuffer,
				"select logid,opdate,optime,spname,objectname,objectval,systemid from %s where logid >=:1 order by logid",
				tableName.c_str());
			cmd.setCommandText(sqlBuffer);
			cmd << (long)dataBaseAttr.m_nLogId;
		}

		/*
	char sqlBuffer[512];
		if (dataBaseAttr.m_nLogId == 0)
		{
			sprintf(sqlBuffer, "select logid,opdate,optime,spname,objectname,objectval,systemid from %s where opdate >='%s' and optime >= '%s' order by logid",
				tableName.c_str(),dataBaseAttr.m_sOpDate.c_str(), dataBaseAttr.m_sOpTime.c_str());
		} else {
			sprintf(sqlBuffer, "select logid,opdate,optime,spname,objectname,objectval,systemid from %s where logid > %d order by logid",
				tableName.c_str(),dataBaseAttr.m_nLogId);
		}
//		printf("[%s]\n",sqlBuffer);
		cmd.setCommandText(sqlBuffer);
*/
		cmd.Execute();
		while (cmd.FetchNext())
		{
			/*
			cout<<"== "<<cmd.Field(1).asNumeric()<<" ## ";
			cout<<"=="<<(const char *)cmd.Field(2).asString()<<" ## ";
			cout<<"=="<<(const char *)cmd.Field(3).asString()<<" ## ";
			cout<<"=="<<(const char *)cmd.Field(4).asString()<<" ## ";
			cout<<"=="<<(const char *)cmd.Field(5).asString()<<" ## ";
			cout<<"=="<<(const char *)cmd.Field(6).asString()<<" ## "<<endl;
*/
			dataBaseAttr.m_nLogId = cmd.Field(1).asNumeric();
			dataBaseAttr.m_sOpDate = (const char *)cmd.Field(2).asString();
			dataBaseAttr.m_sOpTime = (const char *)cmd.Field(3).asString();

			SAString saSPName = cmd.Field(4).asString();
			saSPName.TrimRight();

			SAString saObject = cmd.Field(5).asString();
			saObject.TrimRight();

			SAString saVal = cmd.Field(6).asString();
			saVal.TrimRight();

			SAString saSysId = cmd.Field(7).asString();
			saSysId.TrimLeft();
			saSysId.TrimRight();

			if (0 == strcmp((const char *)saObject, "event"))
			{
				CFTDRtnSyslogEventField logEvent;
				memset(&logEvent, 0, sizeof(logEvent));

				int eventLevel = 5;

				logEvent.MonDate = (const char *)cmd.Field(2).asString();
				logEvent.MonTime = (const char *)cmd.Field(3).asString();
				sprintf(
					(char *)logEvent.ObjectID.getValue(),
					"%s.%s%s%s%s",
					g_mapSysID[(const char *)saSysId].c_str(),
					g_pCenterName,
					DOTDATACENTERAPPDOT,
					g_mapSysID[(const char *)saSysId].c_str(),
					APP_SUFFIX_DBLOG);
				logEvent.OccurDate = logEvent.MonDate.getValue();
				logEvent.OccurTime = logEvent.MonTime.getValue();
				strcpy(sqlBuffer, (const char *)saVal);
				logEvent.ProcessFlag = "L";

				char *pLogValue = strchr(sqlBuffer, ' ');
				if (pLogValue == NULL)
				{
					logEvent.EventName = sqlBuffer;
					logEvent.WarningLevel = "info";
					logEvent.EventDes = "";

					m_dataLock.Lock();
					m_syslogInfo.push_back(logEvent);
					m_dataLock.UnLock();

					//FTDC_ADD_FIELD(&m_pkgSend, &m_eventField);
					//SEND_PKG;
				}
				else
				{
					*pLogValue = '\0';
					logEvent.EventName = sqlBuffer;
					pLogValue++;

					char *pId = pLogValue;
					while (*pId == ' ')
					{
						pId++;
					}

					if (isdigit(*pId)
					&&	(*(pId + 1) == ' ' || *(pId + 1) == '\0'))	//���¼������¼������ֶ�
					{
						eventLevel = *pId - '0';
						pId = pId + 2;
					}

					if (eventLevel == 5)
					{
						logEvent.WarningLevel = "info";
					}
					else if (eventLevel == 4)
					{
						logEvent.WarningLevel = "Warning";
					}
					else if (eventLevel == 3)
					{
						logEvent.WarningLevel = "Error";
					}
					else if (eventLevel == 2 || eventLevel == 1)
					{
						logEvent.WarningLevel = "Fatal";
					}
					else if (eventLevel == 6)
					{
						logEvent.WarningLevel = "debug";
					}
					else
					{
						logEvent.WarningLevel = "unknown";
					}

					///pId��ʼ��������ֵ���¼������ֶ�
					/*
					�ں��ֱ����У�һ�������������ֽ���ɣ����ֱ�������ֱ��ǣ���һ�ֽڱ��롾0xb0 ~ 0xf7���ڶ����ֽڱ��롾0xa1 ~ oxfe��,
					�����жϺ��ִ������£�
					if(s[i]>=(char)0xb0 && s[i]<=(char)0xf7 && s[i+1]>=(char)0xa1 && s[i+1]<=(char)0xfe)
					*/
					while (strlen(pId) > (sizeof(CTypeDescriptionType) - 1))
					{
						logEvent.EventDes = pId;
						logEvent.ProcessFlag = "C";
						if (eventLevel < 5)
						{
							logEvent.ProcessFlag = "N";
						}

						pId = pId + sizeof(CTypeDescriptionType) - 1;
						if ((unsigned char)pId[0] >= 0xa1
						&&	(unsigned char)pId[0] <= 0xfe)
						{
							pId--;

							char *pStr = (char *)logEvent.EventDes.getValue();
							pStr[strlen(pStr) - 1] = '\0';
						}

						m_dataLock.Lock();
						m_syslogInfo.push_back(logEvent);
						m_dataLock.UnLock();

						//FTDC_ADD_FIELD(&m_pkgSend, &m_eventField);
					}

					logEvent.EventDes = pId;
					logEvent.ProcessFlag = "L";
					if (eventLevel < 5)
					{
						logEvent.ProcessFlag = "N";
					}

					m_dataLock.Lock();
					m_syslogInfo.push_back(logEvent);
					m_dataLock.UnLock();

					//FTDC_ADD_FIELD(&m_pkgSend, &m_eventField);
					//SEND_PKG;
				}
			}
			else
			{
				m_ObjAttrInfo.MonDate = (const char *)cmd.Field(2).asString();
				m_ObjAttrInfo.MonTime = (const char *)cmd.Field(3).asString();
				sprintf(
					(char *)m_ObjAttrInfo.ObjectID.getValue(),
					"%s.%s%s%s%s",
					g_mapSysID[(const char *)saSysId].c_str(),
					g_pCenterName,
					DOTDATACENTERAPPDOT,
					g_mapSysID[(const char *)saSysId].c_str(),
					APP_SUFFIX_DBLOG);
				m_ObjAttrInfo.AttrType = (const char *)saObject;
				m_ObjAttrInfo.AttrValue = (const char *)saVal;
				m_ObjAttrInfo.ValueType = UNKNOWN_ATTR;

				m_dataLock.Lock();
				m_attrInfo.push_back(m_ObjAttrInfo);
				m_dataLock.UnLock();
			}
		}

		return true;
	}

	catch(SAException & ex)
	{
		printf(
			"In catch DatabaseSpiImpl getDBLog() tableName:%s Time %s %s err:%s\n",
			tableName.c_str(),
			m_mDate,
			m_mTime,
			(const char *)ex.ErrText());
		fflush(stdout);

		map<string, CDBConnectString>::iterator confIt;
		if ((confIt = m_DatabaseInfoMap.find(dataBaseAttr.sDNSName)) == m_DatabaseInfoMap.end())
		{
			sprintf(
				(char *)m_ObjAttrInfo.ObjectID.getValue(),
				"%s%s%s",
				g_pDataCenterName,
				DOTDATACENTERDBDOT,
				(char *)tableName.c_str());
		}

		sprintf(
			(char *)m_ObjAttrInfo.ObjectID.getValue(),
			"%s%s%s",
			g_pDataCenterName,
			DOTDATACENTERDBDOT,
			confIt->second.m_sRacServiceName.c_str());
		GenerateProbeEvent(
			EVENT_DBGETLOG_ERROR,
			(char *)m_ObjAttrInfo.ObjectID.getValue(),
			(char *)tableName.c_str(),
			"");

		/// �������ݿ�����ʧ�ܸ澯������͸澯�¼�
		return false;
	}
}

void CDatabaseSpiImpl::UpdateDatabaseInfoMap(
	string	&sConfigName,
	CDBConnectString &sConnectString)
{
	map<string, CDBConnectString>::iterator it = m_DatabaseInfoMap.find(
			sConfigName);
	if (it != m_DatabaseInfoMap.end())		// �����Ѿ����ڸñ�����Ӧ�����ݿ�����������
	{
		if (sConnectString != it->second)	// ����������Ϣ��BNS���´�������������ͬ�����±������������m_bReConnectFlagΪtrue
		{
			if (it->second.m_sRacServiceName != sConnectString.
					m_sRacServiceName)
			{
				CFTDRtnUpdateSysConfigField fieldInfo;
				fieldInfo.UpdateType = UPDATESYSCONFIG_HOSTNAME;

				// �ڵ���������硰DATABASE.PuDian.db.BDB��
				sprintf(
					(char *)fieldInfo.OldValue.getValue(),
					"%s%s%s",
					g_pDataCenterName,
					DOTDATACENTERDBDOT,
					it->second.m_sRacServiceName.c_str());
				sprintf(
					(char *)fieldInfo.NewValue.getValue(),
					"%s%s%s.%s",
					g_pDataCenterName,
					DOTDATACENTERDBDOT,
					sConnectString.m_sRacServiceName.c_str());

				m_dataLock.Lock();
				m_updateConfigInfo.push_back(fieldInfo);
				m_dataLock.UnLock();

				// �ڵ���������硰DATABASE.PuDian.db.BDB.BDB1��
				sprintf(
					(char *)fieldInfo.OldValue.getValue(),
					"%s%s%s.%s",
					g_pDataCenterName,
					DOTDATACENTERDBDOT,
					it->second.m_sRacServiceName.c_str(),
					it->second.m_sServiceName.c_str());
				sprintf(
					(char *)fieldInfo.NewValue.getValue(),
					"%s%s%s.%s",
					g_pDataCenterName,
					DOTDATACENTERDBDOT,
					sConnectString.m_sRacServiceName.c_str(),
					sConnectString.m_sServiceName.c_str());

				m_dataLock.Lock();
				m_updateConfigInfo.push_back(fieldInfo);
				m_dataLock.UnLock();
			}
			else if (it->second.m_sServiceName != sConnectString.m_sServiceName)
			{
				CFTDRtnUpdateSysConfigField fieldInfo;
				fieldInfo.UpdateType = UPDATESYSCONFIG_HOSTNAME;

				// �ڵ���������硰DATABASE.PuDian.db.BDB.BDB1��
				sprintf(
					(char *)fieldInfo.OldValue.getValue(),
					"%s%s%s.%s",
					g_pDataCenterName,
					DOTDATACENTERDBDOT,
					it->second.m_sRacServiceName.c_str(),
					it->second.m_sServiceName.c_str());
				sprintf(
					(char *)fieldInfo.NewValue.getValue(),
					"%s%s%s.%s",
					g_pDataCenterName,
					DOTDATACENTERDBDOT,
					sConnectString.m_sRacServiceName.c_str(),
					sConnectString.m_sServiceName.c_str());

				m_dataLock.Lock();
				m_updateConfigInfo.push_back(fieldInfo);
				m_dataLock.UnLock();
			}

			it->second = sConnectString;
			it->second.m_bReConnectFlag = true;
		}
	}
	else
	{	// ���ز����ڸñ�����Ӧ�����ݿ����������ֱ�Ӳ���map
		m_DatabaseInfoMap[sConfigName] = sConnectString;
	}

	return;
}

void CDatabaseSpiImpl::UpdateDBAttrMap(
	const char	*pAttrName,
	const char	*pSeps,
	const char	*pDNSName,
	const char	*pTableName)
{
	map<string, listTDB>::iterator	it;
	it = m_DBAttrMap.find(string(pAttrName));
	if (it != m_DBAttrMap.end())	// ���ݿ���ָ���Ѵ���,ֻ��Ҫ���ӿ��
	{
		listTDB::iterator listIt = find(
				it->second.begin(),
				it->second.end(),
				CTableDBRelation(pTableName, pDNSName));
		if (listIt == it->second.end())
		{
			it->second.push_back(CTableDBRelation(pTableName, pDNSName));
		}
	}
	else
	{
		listTDB tableinfoList;
		tableinfoList.push_back(CTableDBRelation(pTableName, pDNSName));
		m_DBAttrMap[pAttrName] = tableinfoList;
		m_DBAttrSepsMap[pAttrName] = CDataBaseAttr("", "", pSeps);
	}

	return;
}

void CDatabaseSpiImpl::UpdateSPInfoMap(
	const char	*pSPName,
	const char	*pSeps,
	const char	*pDNSName,
	const char	*pSPType)
{
	m_SPmap[pSPName] = CDataBaseAttr(pDNSName, pSPType, pSeps);
	return;
}

void CDatabaseSpiImpl::UpdateDBLogMap(
	const char	*pTableName,
	const char	*pSeps,
	const char	*pDNSName,
	const char	*pPosition)
{
	m_DBLogmap[pTableName] = CDataBaseAttr(pDNSName, "", pSeps);
	return;
}
