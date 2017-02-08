/////////////////////////////////////////////////////////////////////////
// 20110411 ����   NT-0129-����������л�ʱ��ˮ�쳣���������
/////////////////////////////////////////////////////////////////////////

#include "fibplay.h"
#include "version.h" 

int g_iReplayMode = 0;
int g_nTimeZoneSec = 0;

CFibPlayConf::CFibPlayConf()
{
	string m_MarketDay = "";
	string m_Address = "";
	m_Timer = 10;
	string m_Type = "";
	string m_Path = "";
	string m_FlowName = "";
	DWORD m_SubjectID = 0;

	m_Speeds = new vector<TFibPlaySpeed*>();
}

CFibPlayConf::~CFibPlayConf()
{
	int i = 0;

	for (i = 0; i < m_Speeds->size(); i ++)
		delete m_Speeds->at(i);

	m_Speeds->clear();
	delete m_Speeds;
}


//���õ�ַ
void CFibPlayConf::setAddress(const string& strAddr)
{
	m_Address = strAddr;
}

//��������
void CFibPlayConf::setFlowName(const string& strFlowName)
{
	m_FlowName = strFlowName;
}

//����·��
void CFibPlayConf::setPath(const string& strPath)
{
	m_Path = strPath;
}

//�����ٶ�
void CFibPlayConf::setSpeed(TFibPlaySpeed * p_speed)
{
	m_Speeds->push_back(p_speed);
}

//���ö�ʱ��
void CFibPlayConf::setTimer(const int nTimer)
{
	m_Timer = nTimer;
}

//��������id
void CFibPlayConf::setTopicID(const int nID)
{
	m_SubjectID = nID;
}

//���ý�����
void CFibPlayConf::setTradeDate(const string& strTradeDate)
{
	m_MarketDay = strTradeDate;
}

//��������
void CFibPlayConf::setType(const string& strType)
{
	m_Type = strType;
}


CFibPlayFlow::CFibPlayFlow(const char* name)
{
	strcpy(m_Name, name);

	m_IdFile = NULL;
	m_ConFile = NULL;
	m_IdFileLength = 0;
	m_ConFileLength = 0;
	m_OldConFileLength = 0;
	FPOS_SET(m_ConPos, 0);

	m_CommPhaseNo = 0xFFFF;
	m_Count = 0;

	m_Datas = new deque<TData*>();
}

CFibPlayFlow::~CFibPlayFlow()
{
	for (int i = 0; i < m_Datas->size(); i ++)
		delete m_Datas->at(i);

	m_Datas->clear();
	delete m_Datas;

	Close();
}

int CFibPlayFlow::GetCount(void)
{
	return m_Count;
}

WORD CFibPlayFlow::GetCommPhaseNo()
{
	return m_CommPhaseNo;
}

int CFibPlayFlow::Get(int id, void *pObject, int length)
{
	if (id >= m_Datas->size())
		return -1;

	// ȡ��data
	TData* data = m_Datas->at(id);

	// ��������
	memcpy(pObject, data->Object, data->Length);

	return data->Length;
}

// ���ļ�
bool CFibPlayFlow::Open()
{
	// �õ�id�ļ���
	if (m_IdFile == NULL)
	{
		char idFileName[512];
		sprintf(idFileName, "%s.id", m_Name);

		// ��id�ļ�
		m_IdFile = fopen(idFileName, "rb");

		if (m_IdFile == NULL)
			return false;

		// �õ��ļ�����
#ifdef WIN32
		struct _stati64 statbuf;

		if (_fstati64(fileno(m_IdFile), &statbuf) == 0)
			m_IdFileLength = (QWORD) (statbuf.st_size);
#else
		struct stat statbuf;
		
		if (fstat(fileno(m_IdFile), &statbuf) == 0)
			m_IdFileLength = (QWORD) (statbuf.st_size);	
#endif
	}

	// �õ�con�ļ���
	if (m_ConFile == NULL)
	{
		char conFileName[512];
		sprintf(conFileName, "%s.con", m_Name);

		// ��con�ļ�
		m_ConFile = fopen(conFileName, "rb");

		if (m_ConFile == NULL)
			return false;

		// �õ��ļ�����
#ifdef WIN32
		struct _stati64 statbuf;

		if (_fstati64(fileno(m_ConFile), &statbuf) == 0)
			m_ConFileLength = (QWORD) (statbuf.st_size);
#else
		struct stat statbuf;
			
		if (fstat(fileno(m_ConFile), &statbuf) == 0)
			m_ConFileLength = (QWORD) (statbuf.st_size);
#endif
		
		// ����λ��
		fsetpos(m_ConFile, &m_ConPos);
	}

	return true;
}

// �ر��ļ�
void CFibPlayFlow::Close()
{
	if (m_IdFile != NULL)
	{
		fclose(m_IdFile);
		m_IdFile = NULL;
	}

	if (m_ConFile != NULL)
	{
		fclose(m_ConFile);
		m_ConFile = NULL;
	}

	// �����ϵ��ļ�����
	m_OldConFileLength = m_ConFileLength;

	// ��յ�ǰ����
	m_IdFileLength = 0;
	m_ConFileLength = 0;
}

// ����һ������
void CFibPlayFlow::Append()
{
	m_Count ++;
}

// �õ�id�ɶ��ļ�����
QWORD CFibPlayFlow::GetIdCanReadLength()
{
	// �õ���ǰλ��
	fpos_t pos;
	
	if (fgetpos(m_IdFile, &pos) != 0)
		return 0;

	if (m_IdFileLength > FPOS_GET(pos))
		return m_IdFileLength - FPOS_GET(pos);
	else
		return 0;
}

// �õ�con�ɶ��ļ�����
QWORD CFibPlayFlow::GetConCanReadLength()
{
	if (m_ConFileLength > m_OldConFileLength && m_ConFileLength > FPOS_GET(m_ConPos))
		return m_ConFileLength - FPOS_GET(m_ConPos);
	else
		return 0;
}

// ����һ������
bool CFibPlayFlow::ReadNext(CXTPPackage* package)
{
	// �ҿ��ļ���
	if (!Open())
	{
		// �ر��ļ�
		Close();
		
		return false;
	}

	// �ɶ������ݳ���
	QWORD canReadLength = 0;

	// ��ͨѶ���
	if (m_CommPhaseNo == 0xFFFF)
	{
		// ��ǰ�Ƿ���һ��ͷ�ĳ���
		canReadLength = GetIdCanReadLength();

		if (canReadLength < sizeof(WORD))
		{
			// �ر��ļ�
			Close();
			
			return false;
		}

		if (fread(&m_CommPhaseNo, sizeof(m_CommPhaseNo), 1, m_IdFile) != 1)
		{
			// �ر��ļ�
			Close();
			
			return false;
		}

		CHANGE_ENDIAN(m_CommPhaseNo);
	}

	// ��ǰ�Ƿ���һ��ͷ�ĳ���
	canReadLength = GetConCanReadLength();

	if (canReadLength < sizeof(DWORD))
	{
		// �ر��ļ�
		Close();

		return false;
	}

	// ��������
	DWORD flowLen = 0;
	
	if (fread(&flowLen, sizeof(flowLen), 1, m_ConFile) != 1)
	{
		// �ر��ļ�
		Close();
	
		// ����ϵ��ļ�����
		m_OldConFileLength = 0;

		return false;
	}
	
	CHANGE_ENDIAN(flowLen);

	// ��ǰ�Ƿ���һ�����ݵĳ���
	if (canReadLength < sizeof(DWORD) + flowLen)
	{
		// �ر��ļ�
		Close();

		return false;
	}

	// ����TData
	TData* data = new TData();

	data->Length = flowLen;
	data->Object = new char[data->Length];

	// ��������
	if (fread(data->Object, data->Length, 1, m_ConFile) != 1)
	{
		// �ر��ļ�
		Close();
		
		// ����ϵ��ļ�����
		m_OldConFileLength = 0;

		return false;
	}

	// ���浱ǰλ��
	if (fgetpos(m_ConFile, &m_ConPos) != 0)
		return false;

	// ���뵽����
	m_Datas->push_back(data);

	// ����Ϊ��
	memcpy(package->Address(), data->Object, data->Length);
	package->Truncate(data->Length);
	package->ValidPackage();
	
	return true;
}

CFibPlayer::CFibPlayer(CReactor *pReactor, const char* name) : CEventHandler(pReactor)
{
	m_TimeSyncs = new deque<TTimeSyncItem*>(); 

	m_PubApiManager = NULL;
	m_PlayFlow = NULL;
	m_Flow = NULL;
	m_Reader = NULL;
	m_Config = NULL;

	sprintf(m_FlowName, "FlowCount_%s", name);
	m_pFlowCount = new CIntTotalMonitorIndex(m_FlowName, 1);
}

CFibPlayer::~CFibPlayer()
{
	delete m_pFlowCount;

	if (m_PubApiManager != NULL)
		delete m_PubApiManager;

	if (m_PlayFlow != NULL)
		delete m_PlayFlow;

	if (m_Flow != NULL)
		delete m_Flow;

	if (m_Reader != NULL)
		delete m_Reader;

	int i = 0; 
	
	for (i = 0; i < m_TimeSyncs->size(); i ++)
		delete m_TimeSyncs->at(i);

	m_TimeSyncs->clear();
	delete m_TimeSyncs;
}

// ��ʼ��
bool CFibPlayer::Init(CFibPlayConf* config)
{
	// ʱ���ʼ��
	m_CurSpeed = 0;
	m_BeginTime = m_pReactor->GetClock();
	m_CurDataNum = 0;

	// �õ�����
	m_Config = config;

	// Ŀ¼�ָ���
	char pathSplit[2];
	pathSplit[0] = PATH_SPLIT;
	pathSplit[1] = '\0'; 

	// �õ�����
	string flowPath = "";

	if (m_Config->m_MarketDay == "")
	{
		// ������������
		flowPath = m_Config->m_Path + string(pathSplit);
	}
	else
	{
		// ����������
		flowPath = m_Config->m_Path + string(pathSplit) + m_Config->m_MarketDay + string(pathSplit);
	}

	// ����������
	flowPath += m_Config->m_FlowName;

	// ������
	m_PlayFlow = new CFibPlayFlow(flowPath.c_str());
	
	// ��
	m_PkgRead.ConstructAllocate(XTP_PACKAGE_MAX_SIZE, 1000);

	// fib
	m_PubApiManager = new CFibPubApiManager(m_pReactor, 0x7F11);

	// �õ�api
	CFibPublishApi* publishApi = m_PubApiManager->GetFibPublishApi((char*) m_Config->m_Address.c_str());

	// ע����
	publishApi->RegisterFlow(m_PlayFlow, m_Config->m_SubjectID);

	// ����ʱ
	SetTimer(1001, m_Config->m_Timer);

	return true;
}

// ��ʱ����
void CFibPlayer::OnTimer(int nIDEvent)
{
	// �����ݰ�
	ReadData();

	// ��������
	PublishData(g_iReplayMode);

	// ϵͳ���
	CMonitorIndex::handleOne();
}

// �����ݰ�
void CFibPlayer::ReadData()
{
	while (true)
	{
		// ׼�����ݰ�
		m_PkgRead.Allocate(XTP_PACKAGE_MAX_SIZE + XTPHLEN);

		// �����ݰ�
		if (!m_PlayFlow->ReadNext(&m_PkgRead)) 
			break;

		// ����ʱ��������
		TTimeSyncItem* item = new TTimeSyncItem();

		// �鿴��������
		if (m_PkgRead.GetTid() == TID_NtfTimeSync)
		{
			// ʱ��ͬ����
			CCurrentTimeField fieldCurrentTime;
			XTP_GET_SINGLE_FIELD(&m_PkgRead, &fieldCurrentTime);

			item->IsTimeSync = true;
			item->Time = fieldCurrentTime.CurrTime;
			item->Millisec = fieldCurrentTime.CurrMillisec;
			//printf("Get Time:[%s][%d]\n", fieldCurrentTime.CurrTime.getValue(), fieldCurrentTime.CurrMillisec);
		}
		else
		{
			// ������
			item->IsTimeSync = false;
		}

		// ������뵽������
		m_TimeSyncs->push_back(item);
	}
}

// ��������
void CFibPlayer::PublishData(int iCase)
{
	switch(iCase)
	{
	case 0:
		PublishDataWithConfig();
		break;
	case 1:
		PublishDataWithSyncTime();
		break;
	case 2:
		PublishDataWithOrigSpeed();
		break;
	default:
		PublishDataWithConfig();
		break;
	}
}

// ��������
void CFibPlayer::PublishDataWithConfig()
{
	// �ٶ�
	while (m_TimeSyncs->size() > 0)
	{
		// ȡ�����еĵ�һ������
		TTimeSyncItem* item = m_TimeSyncs->at(0);

		if (item->IsTimeSync)
		{
			// ʱ��ͬ����
			// �õ��ٶ�
			m_CurSpeed = GetSpeed(item->Time);
			printf("Curr con time[%s]\n", (char *)item->Time.getValue());

			// �õ���ǰ��ϵͳʱ��
			m_BeginTime = m_pReactor->GetClock();

			// ��ǰ�����ݸ���
			m_CurDataNum = 0;

			// ��ӡ
			// printf("Type:%s Time:%s.%03d Speed:%d Total:%d\n", m_Config->m_Type.c_str(), (const char*) item->Time, item->Millisec, m_CurSpeed, m_PlayFlow->GetCount());			
		}
		else
		{
			// ������
			if (m_CurSpeed == 0)
			{
				// ȫ��
			}
			else
			{
				// ����
				// �õ���ǰ��ϵͳʱ��
				DWORD curTime = m_pReactor->GetClock();

				// �õ�������ݸ���
				int maxDataNum = (curTime - m_BeginTime) * m_CurSpeed / 1000;

				// �Ƿ񳬹��ٶ�
				if (m_CurDataNum > maxDataNum)
					break;
			}
		}

		// ���������뵽����
		m_PlayFlow->Append();					

		// ɾ��item
		delete item;

		// ������
		m_TimeSyncs->pop_front();

		// ���ӵ�ǰ�����ݸ���
		m_CurDataNum ++;

		// ��ش����ݿ��ȡ��Ϣ����
		m_pFlowCount->incValue();
	}
}

inline DWORD TimeString2TimeSec(char *pTimeSec)
{
	return atoi(pTimeSec) * 3600 + atoi(pTimeSec+3) * 60 + atoi(pTimeSec+6);
}

// ��������
void CFibPlayer::PublishDataWithSyncTime()
{
	// �ٶ�
	while (m_TimeSyncs->size() > 0)
	{
		// ȡ�����еĵ�һ������
		TTimeSyncItem* item = m_TimeSyncs->at(0);
		
		// ������ʱ����ʱ��Ҫ�жϣ��Ƿ�������ݵȴ�
		if (item->IsTimeSync)
		{
			// �õ���ǰ����ˮʱ��
			DWORD conTime = TimeString2TimeSec((char *)item->Time.getValue()) * 1000;
			DWORD curTime = ((time(NULL) - g_nTimeZoneSec) % 86400) * 1000;
			printf("Curr con time[%s]\n", (char *)item->Time.getValue());
			// �õ���ǰ��ϵͳʱ��
			if (curTime < conTime)
			{
				break;
			}
		}

		// ���������뵽����
		m_PlayFlow->Append();					

		// ɾ��item
		delete item;

		// ������
		m_TimeSyncs->pop_front();

		// ��ش����ݿ��ȡ��Ϣ����
		m_pFlowCount->incValue();
	}
}

// ��������
void CFibPlayer::PublishDataWithOrigSpeed()
{
	static DWORD TimeDrift = 0;
	// �ٶ�
	while (m_TimeSyncs->size() > 0)
	{
		// ȡ�����еĵ�һ������
		TTimeSyncItem* item = m_TimeSyncs->at(0);

		if (item->IsTimeSync)
		{
			// �õ���ǰ����ˮʱ��
			DWORD conTime = TimeString2TimeSec((char *)item->Time.getValue()) * 1000;
			DWORD curTime = ((time(NULL) - g_nTimeZoneSec) % 86400) * 1000;
			printf("Curr con time[%s]\n", (char *)item->Time.getValue());
			// ȡ����ˮ�طŵ�����ʱ��ƫ����������ʼ��һ��
			if (TimeDrift == 0)
			{				
				TimeDrift = curTime - conTime;
			}
			// �õ���ǰ��ϵͳʱ��
			if (curTime < conTime + TimeDrift)
			{
				break;
			}
		}

		// ���������뵽����
		m_PlayFlow->Append();					

		// ɾ��item
		delete item;

		// ������
		m_TimeSyncs->pop_front();

		// ��ش����ݿ��ȡ��Ϣ����
		m_pFlowCount->incValue();
	}
}

// �õ��ٶ�
int CFibPlayer::GetSpeed(CTimeType Time)
{
	TFibPlaySpeed* item;
	int i = 0;

	for (i = 0; i < m_Config->m_Speeds->size(); i ++)
	{
		item = m_Config->m_Speeds->at(i);

		if (strcmp(Time, item->BeginTime) >= 0 && strcmp(Time, item->EndTime) < 0)
			return item->Speed;
	}

	return 0;
}

// ��ȡ������
bool read_flow_config(char* fileName, string marketDay, vector<CFibPlayConf*>* playConfigs)
{
	// ��ȡ�����ļ�
	CXMLDoc xmlconf;
	xmlconf.read(fileName);

	// ��ȡ���ڵ�
	CXMLNode* p_RootNode=xmlconf.getRootNode();
	
	if (p_RootNode == NULL)
		return false;

	// ��ȡ���ڵ���ӽڵ��б�
	CXMLNodeList* p_NodeList = p_RootNode->getNodeList();
	
	if (p_NodeList == NULL)
		return false;

	CXMLNodeList::iterator it;

	for (it = p_NodeList->begin(); it != p_NodeList->end(); it ++)
	{
		CXMLNode* p_xmlNode = *it;

		// ��������Ϊflow�Ľڵ�
		if (strcmp(p_xmlNode->getName(), "flow") == 0)
		{
			// ����CFibPlayConf ����
			CFibPlayConf* p_playConfig = new CFibPlayConf();
			
			if (p_playConfig == NULL)
				return -1;

			// �õ���ʱ
			char* psztimer = p_xmlNode->findProperty("timer");
			
			if (psztimer == NULL)
				p_playConfig->setTimer(0);
			else
				p_playConfig->setTimer(atoi(psztimer));
			
			// �õ����� 
			char* pszsubject = p_xmlNode->findProperty("subject");
			
			if( NULL == pszsubject )
				p_playConfig->setTopicID(0);
			else
				p_playConfig->setTopicID(atoi(pszsubject));
			
			p_playConfig->setType(string( p_xmlNode->findProperty("type")));
			p_playConfig->setPath(string(p_xmlNode->findProperty("path")));
			p_playConfig->setFlowName( string(p_xmlNode->findProperty("name")));
			p_playConfig->setAddress( string(p_xmlNode->findProperty("address")));
			p_playConfig->setTradeDate(marketDay);

			// ��ȡ�ӽڵ��б�
			CXMLNodeList* p_sonNodeList = p_xmlNode->getNodeList();
			CXMLNodeList::iterator it_son;

			for (it_son = p_sonNodeList->begin(); it_son != p_sonNodeList->end(); it_son ++)
			{
				CXMLNode* p_sonXmlNode = *it_son;

				// ������Ϊspeed �Ľڵ�
				if (strcmp(p_sonXmlNode->getName(), "speed") == 0)
				{
					char* pszvalue=p_sonXmlNode->findProperty("value");
					
					if (pszvalue == NULL)
						continue;
						
					// ����TFibPlaySpeed ����
					TFibPlaySpeed* p_playSpeed = new TFibPlaySpeed();

					// ����TFibPlaySpeed ���������ֵ
					p_playSpeed->setBeginTime(p_sonXmlNode->findProperty("begintime"));
					p_playSpeed->setEndTime(p_sonXmlNode->findProperty("endtime"));
					p_playSpeed->setSpeed(atoi(pszvalue));

					// ����CFibPlayConf ������ٶ�
				 	p_playConfig->setSpeed( p_playSpeed );
				}
			}
			
			// ��CFibPlayConf ������������б���
			playConfigs->push_back(p_playConfig);
		}
	}
	
	return true;
}

// ����
int help_func()
{
	const char HELP[] = "Usage:\n"
		"-v // Display version.\n"
		"-h // Display usage.\n"
		"fibplay id marketday \n";
	
	printf(HELP);
	
	return 0;
}

int main(int argc, char *argv[])
{
	time_t timep;
	time(&timep);
	g_nTimeZoneSec = mktime(gmtime(&timep)) - timep;

	if (argc == 2)
	{
		if (strcmp(argv[1], "-v") == 0)
		{
			// �汾
			printf("%s version: %s\n", argv[0], version);
			return 0;
		}
		else if (strcmp(argv[1], "-h") == 0)
		{
			// ����
			return help_func();
		}
		else
		{
			// ����
		}
	}
	else if (argc == 3)
	{
		// ����
	}
	else
	{
		// ����
		return help_func();
	}
			
	// ��������
	CConfig* config = new CConfig("fibplay.ini");	
	
	// ��ȡ�������ļ�·��
	const char* p_cszFlowConfPath = config->getConfig("FlowConfPath");
	
	if (p_cszFlowConfPath == NULL)
		p_cszFlowConfPath = FLOW_CONF_PATH;
	
	// ����ļ��Ƿ����
	if (access(p_cszFlowConfPath, F_EXISTENCE_MODE) != 0)
	{
		printf("flow config file %s doesn't exist.\n ", p_cszFlowConfPath);
		return -1;
	}
	
	// �õ���־Ŀ¼
	const char* syslogFileName = config->getConfig("SyslogPath");

	// �õ��ط�ģʽ
	g_iReplayMode = atoi(config->getConfig("ReplayMode"));
	
	if (syslogFileName == NULL)
		syslogFileName = FLOW_SYSLOG_PATH;

	// ���ü��ָ��
	CMonitorIndex::init(CFilelogService::CreateInstance(argc, argv, syslogFileName), config);

	// �õ�������
	string marketDay = "";

	if (argc == 3)
		marketDay = string(argv[2]);

	// �õ�����������
	vector<CFibPlayConf*>* playConfigs = new vector<CFibPlayConf*>();
	
	// ��ȡ������
	if (!read_flow_config((char*) p_cszFlowConfPath, marketDay, playConfigs))
	{
		printf("read flow config file error!\n ");
		return -1;
	}
	
	// ����ÿ�������߳�
	int i = 0;
	vector<CSelectReactor*>* reactors = new vector<CSelectReactor*>();
	vector<CFibPlayer*>* fibPlays = new vector<CFibPlayer*>();

	for (i = 0; i < playConfigs->size(); i ++)
	{
		// ��ӡ
		printf("create player for %s\n", playConfigs->at(i)->m_Type.c_str());

		// ʵ�����߳�
		CSelectReactor* reactor = new CSelectReactor();

		// ���ɲ�����
		CFibPlayer* fibPlay = new CFibPlayer(reactor, playConfigs->at(i)->m_Type.c_str());

		// ��ʼ��
		if (!fibPlay->Init(playConfigs->at(i)))
		{
			printf("create player for %s failed!\n", playConfigs->at(i)->m_Type.c_str());
			break;
		}

		// �����߳�
		reactor->Create();

		// ���뵽������
		fibPlays->push_back(fibPlay);
		reactors->push_back(reactor);
	}

	// �ȴ��߳��˳�
	for (i = 0; i < playConfigs->size(); i ++)
		reactors->at(i)->Join();

	// ɾ���߳�
	for (i = 0; i < playConfigs->size(); i ++)
	{
		delete fibPlays->at(i);
		delete reactors->at(i);
	}

	fibPlays->clear();
	delete fibPlays;

	reactors->clear();
	delete reactors;

	// ɾ������
	for (i = 0; i < playConfigs->size(); i ++)
		delete playConfigs->at(i);

	playConfigs->clear();
	delete playConfigs;
	
	// ɾ������
	delete config;

	return 0;
}
