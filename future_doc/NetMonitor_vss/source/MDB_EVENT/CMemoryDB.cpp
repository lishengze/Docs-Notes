/////////////////////////////////////////////////////////////////////////
///@system 执行引擎系统
///@company 上海期货信息技术有限公司
///@file CMemoryDB.cpp
///@brief实现了类CMemoryDB
///@history 
///20050824	王肇东		创建该文件
///20120111 江鹏		NT-0163 kernel命令行增加指定用户密码参数
/////////////////////////////////////////////////////////////////////////

#include "CMemoryDB.h"
#include <map>
#include <string>
using namespace std;

#define MEMORYDB_ID			0
#define MAX_TABLE_COUNT		300				///引导块中每块放置的内存数据库表或者索引的数量

CMemoryDB::CMemoryDB(void)
{
	m_MonitorEntityFactory=NULL;
	m_EventEntityFactory=NULL;
	m_ForceUserPassword.setValue(NULL);
}
	
CMemoryDB::~CMemoryDB(void)
{
	if (m_MonitorEntityFactory!=NULL)
		delete m_MonitorEntityFactory;
	if (m_EventEntityFactory!=NULL)
		delete m_EventEntityFactory;
}
	
int CMemoryDB::isA(char *objectType)
{
	if (!strcmp(objectType,"CMemoryDB"))
		return 1;
	return CBaseObject::isA(objectType);
}

char *CMemoryDB::getType(void)
{
	return "CMemoryDB";
}

void CMemoryDB::output(CLogger *pLogger,int indent)
{
	CHECK_TYPE("CMemoryDB");
	pLogger->output(indent,0,"CMemoryDB:");
	if (m_MonitorEntityFactory!=NULL)
		m_MonitorEntityFactory->output(pLogger,indent+1);
	if (m_EventEntityFactory!=NULL)
		m_EventEntityFactory->output(pLogger,indent+1);
}

int CMemoryDB::init(CConfig *pConfig,IMemoryAllocator *pAllocator,bool reuse)
{
	if(pAllocator == NULL)
	{
		pAllocator = new CNormalMemoryAllocator();
		pAllocator->init(reuse);
	}
	if(!reuse)
	{
		map<string,int> indexMap;
		pMem=new CFixMem(sizeof(TableStruct),MAX_TABLE_COUNT,pAllocator,false,MEMORYDB_ID);
		TableStruct* pStru = NULL;
		
		m_MonitorEntityFactory=new CMonitorEntityFactory(pConfig,pAllocator,&indexMap);
		if (m_MonitorEntityFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"MonitorEntity");
		pStru->reuseID = m_MonitorEntityFactory->getReuseID();
				
		m_EventEntityFactory=new CEventEntityFactory(pConfig,pAllocator,&indexMap);
		if (m_EventEntityFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"EventEntity");
		pStru->reuseID = m_EventEntityFactory->getReuseID();
				
	
		map<string,int>::iterator it = indexMap.begin();
		for(;it!=indexMap.end();it++)
		{
			pStru = (TableStruct *)pMem->alloc();
			strcpy(pStru->tableName,it->first.c_str());
			pStru->reuseID = it->second;
		}
	}
	else
	{
		pMem=new CFixMem(sizeof(TableStruct),MAX_TABLE_COUNT,pAllocator,true,MEMORYDB_ID);
		map<string,int> blockMap;
		TableStruct* pStru = NULL;
		for(int i=0;i<pMem->getCount();i++)
		{
			pStru = (TableStruct *)pMem->getObject(i);
			blockMap.insert(map<string,int>::value_type(pStru->tableName,pStru->reuseID));
		}
		map<string,int>::iterator it;
			
		it = blockMap.find("MonitorEntity");
		if(it == blockMap.end())
			m_MonitorEntityFactory=new CMonitorEntityFactory(pConfig,pAllocator,&blockMap);
		else
			m_MonitorEntityFactory=new CMonitorEntityFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_MonitorEntityFactory==NULL)
			return 0;
				
		it = blockMap.find("EventEntity");
		if(it == blockMap.end())
			m_EventEntityFactory=new CEventEntityFactory(pConfig,pAllocator,&blockMap);
		else
			m_EventEntityFactory=new CEventEntityFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_EventEntityFactory==NULL)
			return 0;
				
	}
	return 1;
}

int CMemoryDB::load(CConfig *pConfig)
{
	return 1;
}

int CMemoryDB::save(CConfig *pConfig)
{
	if (!m_MonitorEntityFactory->writeCSV(pConfig))
		return 0;
	if (!m_EventEntityFactory->writeCSV(pConfig))
		return 0;
	return 1;
}

void CMemoryDB::clear(void)
{
	m_MonitorEntityFactory->clearAll();
	m_EventEntityFactory->clearAll();
	m_ForceUserPassword.clear();
}

void CMemoryDB::linkAll(void)
{
}

