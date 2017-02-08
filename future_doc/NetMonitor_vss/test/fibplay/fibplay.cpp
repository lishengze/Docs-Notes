/////////////////////////////////////////////////////////////////////////
// 20110411 江鹏   NT-0129-解决三中心切换时流水异常增大的问题
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


//设置地址
void CFibPlayConf::setAddress(const string& strAddr)
{
	m_Address = strAddr;
}

//设置流名
void CFibPlayConf::setFlowName(const string& strFlowName)
{
	m_FlowName = strFlowName;
}

//设置路径
void CFibPlayConf::setPath(const string& strPath)
{
	m_Path = strPath;
}

//设置速度
void CFibPlayConf::setSpeed(TFibPlaySpeed * p_speed)
{
	m_Speeds->push_back(p_speed);
}

//设置定时器
void CFibPlayConf::setTimer(const int nTimer)
{
	m_Timer = nTimer;
}

//设置主题id
void CFibPlayConf::setTopicID(const int nID)
{
	m_SubjectID = nID;
}

//设置交易日
void CFibPlayConf::setTradeDate(const string& strTradeDate)
{
	m_MarketDay = strTradeDate;
}

//设置类型
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

	// 取出data
	TData* data = m_Datas->at(id);

	// 复制数据
	memcpy(pObject, data->Object, data->Length);

	return data->Length;
}

// 打开文件
bool CFibPlayFlow::Open()
{
	// 得到id文件名
	if (m_IdFile == NULL)
	{
		char idFileName[512];
		sprintf(idFileName, "%s.id", m_Name);

		// 打开id文件
		m_IdFile = fopen(idFileName, "rb");

		if (m_IdFile == NULL)
			return false;

		// 得到文件长度
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

	// 得到con文件名
	if (m_ConFile == NULL)
	{
		char conFileName[512];
		sprintf(conFileName, "%s.con", m_Name);

		// 打开con文件
		m_ConFile = fopen(conFileName, "rb");

		if (m_ConFile == NULL)
			return false;

		// 得到文件长度
#ifdef WIN32
		struct _stati64 statbuf;

		if (_fstati64(fileno(m_ConFile), &statbuf) == 0)
			m_ConFileLength = (QWORD) (statbuf.st_size);
#else
		struct stat statbuf;
			
		if (fstat(fileno(m_ConFile), &statbuf) == 0)
			m_ConFileLength = (QWORD) (statbuf.st_size);
#endif
		
		// 设置位置
		fsetpos(m_ConFile, &m_ConPos);
	}

	return true;
}

// 关闭文件
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

	// 保存老的文件长度
	m_OldConFileLength = m_ConFileLength;

	// 清空当前长度
	m_IdFileLength = 0;
	m_ConFileLength = 0;
}

// 增加一个数据
void CFibPlayFlow::Append()
{
	m_Count ++;
}

// 得到id可读文件长度
QWORD CFibPlayFlow::GetIdCanReadLength()
{
	// 得到当前位置
	fpos_t pos;
	
	if (fgetpos(m_IdFile, &pos) != 0)
		return 0;

	if (m_IdFileLength > FPOS_GET(pos))
		return m_IdFileLength - FPOS_GET(pos);
	else
		return 0;
}

// 得到con可读文件长度
QWORD CFibPlayFlow::GetConCanReadLength()
{
	if (m_ConFileLength > m_OldConFileLength && m_ConFileLength > FPOS_GET(m_ConPos))
		return m_ConFileLength - FPOS_GET(m_ConPos);
	else
		return 0;
}

// 读下一个数据
bool CFibPlayFlow::ReadNext(CXTPPackage* package)
{
	// 找开文件名
	if (!Open())
	{
		// 关闭文件
		Close();
		
		return false;
	}

	// 可读的数据长度
	QWORD canReadLength = 0;

	// 读通讯编号
	if (m_CommPhaseNo == 0xFFFF)
	{
		// 当前是否有一个头的长度
		canReadLength = GetIdCanReadLength();

		if (canReadLength < sizeof(WORD))
		{
			// 关闭文件
			Close();
			
			return false;
		}

		if (fread(&m_CommPhaseNo, sizeof(m_CommPhaseNo), 1, m_IdFile) != 1)
		{
			// 关闭文件
			Close();
			
			return false;
		}

		CHANGE_ENDIAN(m_CommPhaseNo);
	}

	// 当前是否有一个头的长度
	canReadLength = GetConCanReadLength();

	if (canReadLength < sizeof(DWORD))
	{
		// 关闭文件
		Close();

		return false;
	}

	// 读流长度
	DWORD flowLen = 0;
	
	if (fread(&flowLen, sizeof(flowLen), 1, m_ConFile) != 1)
	{
		// 关闭文件
		Close();
	
		// 清空老的文件长度
		m_OldConFileLength = 0;

		return false;
	}
	
	CHANGE_ENDIAN(flowLen);

	// 当前是否有一个数据的长度
	if (canReadLength < sizeof(DWORD) + flowLen)
	{
		// 关闭文件
		Close();

		return false;
	}

	// 生成TData
	TData* data = new TData();

	data->Length = flowLen;
	data->Object = new char[data->Length];

	// 读入数据
	if (fread(data->Object, data->Length, 1, m_ConFile) != 1)
	{
		// 关闭文件
		Close();
		
		// 清空老的文件长度
		m_OldConFileLength = 0;

		return false;
	}

	// 保存当前位置
	if (fgetpos(m_ConFile, &m_ConPos) != 0)
		return false;

	// 加入到队列
	m_Datas->push_back(data);

	// 解析为包
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

// 初始化
bool CFibPlayer::Init(CFibPlayConf* config)
{
	// 时间初始化
	m_CurSpeed = 0;
	m_BeginTime = m_pReactor->GetClock();
	m_CurDataNum = 0;

	// 得到配置
	m_Config = config;

	// 目录分隔符
	char pathSplit[2];
	pathSplit[0] = PATH_SPLIT;
	pathSplit[1] = '\0'; 

	// 得到流名
	string flowPath = "";

	if (m_Config->m_MarketDay == "")
	{
		// 不包括交易日
		flowPath = m_Config->m_Path + string(pathSplit);
	}
	else
	{
		// 包括交易日
		flowPath = m_Config->m_Path + string(pathSplit) + m_Config->m_MarketDay + string(pathSplit);
	}

	// 加入流名称
	flowPath += m_Config->m_FlowName;

	// 播放流
	m_PlayFlow = new CFibPlayFlow(flowPath.c_str());
	
	// 包
	m_PkgRead.ConstructAllocate(XTP_PACKAGE_MAX_SIZE, 1000);

	// fib
	m_PubApiManager = new CFibPubApiManager(m_pReactor, 0x7F11);

	// 得到api
	CFibPublishApi* publishApi = m_PubApiManager->GetFibPublishApi((char*) m_Config->m_Address.c_str());

	// 注册流
	publishApi->RegisterFlow(m_PlayFlow, m_Config->m_SubjectID);

	// 处理定时
	SetTimer(1001, m_Config->m_Timer);

	return true;
}

// 定时处理
void CFibPlayer::OnTimer(int nIDEvent)
{
	// 读数据包
	ReadData();

	// 发布数据
	PublishData(g_iReplayMode);

	// 系统监控
	CMonitorIndex::handleOne();
}

// 读数据包
void CFibPlayer::ReadData()
{
	while (true)
	{
		// 准备数据包
		m_PkgRead.Allocate(XTP_PACKAGE_MAX_SIZE + XTPHLEN);

		// 读数据包
		if (!m_PlayFlow->ReadNext(&m_PkgRead)) 
			break;

		// 生成时间索引项
		TTimeSyncItem* item = new TTimeSyncItem();

		// 查看包的类型
		if (m_PkgRead.GetTid() == TID_NtfTimeSync)
		{
			// 时间同步项
			CCurrentTimeField fieldCurrentTime;
			XTP_GET_SINGLE_FIELD(&m_PkgRead, &fieldCurrentTime);

			item->IsTimeSync = true;
			item->Time = fieldCurrentTime.CurrTime;
			item->Millisec = fieldCurrentTime.CurrMillisec;
			//printf("Get Time:[%s][%d]\n", fieldCurrentTime.CurrTime.getValue(), fieldCurrentTime.CurrMillisec);
		}
		else
		{
			// 数据项
			item->IsTimeSync = false;
		}

		// 把项加入到队列中
		m_TimeSyncs->push_back(item);
	}
}

// 发布数据
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

// 发布数据
void CFibPlayer::PublishDataWithConfig()
{
	// 速度
	while (m_TimeSyncs->size() > 0)
	{
		// 取出队列的第一个数据
		TTimeSyncItem* item = m_TimeSyncs->at(0);

		if (item->IsTimeSync)
		{
			// 时间同步项
			// 得到速度
			m_CurSpeed = GetSpeed(item->Time);
			printf("Curr con time[%s]\n", (char *)item->Time.getValue());

			// 得到当前的系统时钟
			m_BeginTime = m_pReactor->GetClock();

			// 当前的数据个数
			m_CurDataNum = 0;

			// 打印
			// printf("Type:%s Time:%s.%03d Speed:%d Total:%d\n", m_Config->m_Type.c_str(), (const char*) item->Time, item->Millisec, m_CurSpeed, m_PlayFlow->GetCount());			
		}
		else
		{
			// 数据项
			if (m_CurSpeed == 0)
			{
				// 全速
			}
			else
			{
				// 定速
				// 得到当前的系统时钟
				DWORD curTime = m_pReactor->GetClock();

				// 得到最大数据个数
				int maxDataNum = (curTime - m_BeginTime) * m_CurSpeed / 1000;

				// 是否超过速度
				if (m_CurDataNum > maxDataNum)
					break;
			}
		}

		// 把索引加入到流中
		m_PlayFlow->Append();					

		// 删除item
		delete item;

		// 出队列
		m_TimeSyncs->pop_front();

		// 增加当前的数据个数
		m_CurDataNum ++;

		// 监控从数据库读取消息个数
		m_pFlowCount->incValue();
	}
}

inline DWORD TimeString2TimeSec(char *pTimeSec)
{
	return atoi(pTimeSec) * 3600 + atoi(pTimeSec+3) * 60 + atoi(pTimeSec+6);
}

// 发布数据
void CFibPlayer::PublishDataWithSyncTime()
{
	// 速度
	while (m_TimeSyncs->size() > 0)
	{
		// 取出队列的第一个数据
		TTimeSyncItem* item = m_TimeSyncs->at(0);
		
		// 仅遇到时间项时需要判断，是否进入自陷等待
		if (item->IsTimeSync)
		{
			// 得到当前的流水时钟
			DWORD conTime = TimeString2TimeSec((char *)item->Time.getValue()) * 1000;
			DWORD curTime = ((time(NULL) - g_nTimeZoneSec) % 86400) * 1000;
			printf("Curr con time[%s]\n", (char *)item->Time.getValue());
			// 得到当前的系统时钟
			if (curTime < conTime)
			{
				break;
			}
		}

		// 把索引加入到流中
		m_PlayFlow->Append();					

		// 删除item
		delete item;

		// 出队列
		m_TimeSyncs->pop_front();

		// 监控从数据库读取消息个数
		m_pFlowCount->incValue();
	}
}

// 发布数据
void CFibPlayer::PublishDataWithOrigSpeed()
{
	static DWORD TimeDrift = 0;
	// 速度
	while (m_TimeSyncs->size() > 0)
	{
		// 取出队列的第一个数据
		TTimeSyncItem* item = m_TimeSyncs->at(0);

		if (item->IsTimeSync)
		{
			// 得到当前的流水时钟
			DWORD conTime = TimeString2TimeSec((char *)item->Time.getValue()) * 1000;
			DWORD curTime = ((time(NULL) - g_nTimeZoneSec) % 86400) * 1000;
			printf("Curr con time[%s]\n", (char *)item->Time.getValue());
			// 取得流水回放的整体时间偏移量，仅初始化一次
			if (TimeDrift == 0)
			{				
				TimeDrift = curTime - conTime;
			}
			// 得到当前的系统时钟
			if (curTime < conTime + TimeDrift)
			{
				break;
			}
		}

		// 把索引加入到流中
		m_PlayFlow->Append();					

		// 删除item
		delete item;

		// 出队列
		m_TimeSyncs->pop_front();

		// 监控从数据库读取消息个数
		m_pFlowCount->incValue();
	}
}

// 得到速度
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

// 读取流配置
bool read_flow_config(char* fileName, string marketDay, vector<CFibPlayConf*>* playConfigs)
{
	// 读取配置文件
	CXMLDoc xmlconf;
	xmlconf.read(fileName);

	// 获取根节点
	CXMLNode* p_RootNode=xmlconf.getRootNode();
	
	if (p_RootNode == NULL)
		return false;

	// 获取根节点的子节点列表
	CXMLNodeList* p_NodeList = p_RootNode->getNodeList();
	
	if (p_NodeList == NULL)
		return false;

	CXMLNodeList::iterator it;

	for (it = p_NodeList->begin(); it != p_NodeList->end(); it ++)
	{
		CXMLNode* p_xmlNode = *it;

		// 查找名字为flow的节点
		if (strcmp(p_xmlNode->getName(), "flow") == 0)
		{
			// 生成CFibPlayConf 对象
			CFibPlayConf* p_playConfig = new CFibPlayConf();
			
			if (p_playConfig == NULL)
				return -1;

			// 得到定时
			char* psztimer = p_xmlNode->findProperty("timer");
			
			if (psztimer == NULL)
				p_playConfig->setTimer(0);
			else
				p_playConfig->setTimer(atoi(psztimer));
			
			// 得到主题 
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

			// 获取子节点列表
			CXMLNodeList* p_sonNodeList = p_xmlNode->getNodeList();
			CXMLNodeList::iterator it_son;

			for (it_son = p_sonNodeList->begin(); it_son != p_sonNodeList->end(); it_son ++)
			{
				CXMLNode* p_sonXmlNode = *it_son;

				// 查找名为speed 的节点
				if (strcmp(p_sonXmlNode->getName(), "speed") == 0)
				{
					char* pszvalue=p_sonXmlNode->findProperty("value");
					
					if (pszvalue == NULL)
						continue;
						
					// 生成TFibPlaySpeed 对象
					TFibPlaySpeed* p_playSpeed = new TFibPlaySpeed();

					// 设置TFibPlaySpeed 对象的属性值
					p_playSpeed->setBeginTime(p_sonXmlNode->findProperty("begintime"));
					p_playSpeed->setEndTime(p_sonXmlNode->findProperty("endtime"));
					p_playSpeed->setSpeed(atoi(pszvalue));

					// 设置CFibPlayConf 对象的速度
				 	p_playConfig->setSpeed( p_playSpeed );
				}
			}
			
			// 将CFibPlayConf 对象加入配置列表中
			playConfigs->push_back(p_playConfig);
		}
	}
	
	return true;
}

// 帮助
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
			// 版本
			printf("%s version: %s\n", argv[0], version);
			return 0;
		}
		else if (strcmp(argv[1], "-h") == 0)
		{
			// 帮助
			return help_func();
		}
		else
		{
			// 正常
		}
	}
	else if (argc == 3)
	{
		// 正常
	}
	else
	{
		// 帮助
		return help_func();
	}
			
	// 读出配置
	CConfig* config = new CConfig("fibplay.ini");	
	
	// 获取流配置文件路径
	const char* p_cszFlowConfPath = config->getConfig("FlowConfPath");
	
	if (p_cszFlowConfPath == NULL)
		p_cszFlowConfPath = FLOW_CONF_PATH;
	
	// 检测文件是否存在
	if (access(p_cszFlowConfPath, F_EXISTENCE_MODE) != 0)
	{
		printf("flow config file %s doesn't exist.\n ", p_cszFlowConfPath);
		return -1;
	}
	
	// 得到日志目录
	const char* syslogFileName = config->getConfig("SyslogPath");

	// 得到回放模式
	g_iReplayMode = atoi(config->getConfig("ReplayMode"));
	
	if (syslogFileName == NULL)
		syslogFileName = FLOW_SYSLOG_PATH;

	// 设置监控指标
	CMonitorIndex::init(CFilelogService::CreateInstance(argc, argv, syslogFileName), config);

	// 得到交易日
	string marketDay = "";

	if (argc == 3)
		marketDay = string(argv[2]);

	// 得到所有流配置
	vector<CFibPlayConf*>* playConfigs = new vector<CFibPlayConf*>();
	
	// 读取流配置
	if (!read_flow_config((char*) p_cszFlowConfPath, marketDay, playConfigs))
	{
		printf("read flow config file error!\n ");
		return -1;
	}
	
	// 生成每个播放线程
	int i = 0;
	vector<CSelectReactor*>* reactors = new vector<CSelectReactor*>();
	vector<CFibPlayer*>* fibPlays = new vector<CFibPlayer*>();

	for (i = 0; i < playConfigs->size(); i ++)
	{
		// 打印
		printf("create player for %s\n", playConfigs->at(i)->m_Type.c_str());

		// 实例化线程
		CSelectReactor* reactor = new CSelectReactor();

		// 生成播放器
		CFibPlayer* fibPlay = new CFibPlayer(reactor, playConfigs->at(i)->m_Type.c_str());

		// 初始化
		if (!fibPlay->Init(playConfigs->at(i)))
		{
			printf("create player for %s failed!\n", playConfigs->at(i)->m_Type.c_str());
			break;
		}

		// 建立线程
		reactor->Create();

		// 加入到数组中
		fibPlays->push_back(fibPlay);
		reactors->push_back(reactor);
	}

	// 等待线程退出
	for (i = 0; i < playConfigs->size(); i ++)
		reactors->at(i)->Join();

	// 删除线程
	for (i = 0; i < playConfigs->size(); i ++)
	{
		delete fibPlays->at(i);
		delete reactors->at(i);
	}

	fibPlays->clear();
	delete fibPlays;

	reactors->clear();
	delete reactors;

	// 删除配置
	for (i = 0; i < playConfigs->size(); i ++)
		delete playConfigs->at(i);

	playConfigs->clear();
	delete playConfigs;
	
	// 删除配置
	delete config;

	return 0;
}
