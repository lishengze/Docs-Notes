/////////////////////////////////////////////////////////////////////////
///@system 交易引擎系统
///@company 上海期货信息技术有限公司
///@file CDumpLog.cpp
///@brief实现了类CDumpLog
///@history 
///20041001	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#include "CDumpLog.h"
#include "monitorIndex.h"

///本宏控制是否使用单行方式进行输出
#define SINGLE_LINE

CMonitorEntityDumpTrigger::CMonitorEntityDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CMonitorEntityDumpTrigger::~CMonitorEntityDumpTrigger(void)
{
}


void CMonitorEntityDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CMonitorEntityDumpTrigger");
	pLogger->output(indent,0,"CMonitorEntityDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CMonitorEntityDumpTrigger::beforeAdd(CWriteableMonitorEntity *pMonitorEntity)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MonitorEntity,add");
		pMonitorEntity->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add MonitorEntity\n");
		pMonitorEntity->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CMonitorEntityDumpTrigger::beforeUpdate(CMonitorEntity *pMonitorEntity, CWriteableMonitorEntity *pNewMonitorEntity)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MonitorEntity,upd");
		pNewMonitorEntity->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update MonitorEntity\n");
		pNewMonitorEntity->dumpDiff(m_output,pMonitorEntity);
#endif
		fflush(m_output);
	}
}
	
void CMonitorEntityDumpTrigger::beforeRemove(CMonitorEntity *pMonitorEntity)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MonitorEntity,del");
		pMonitorEntity->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove MonitorEntity\n");
		pMonitorEntity->dump(m_output);
#endif
		fflush(m_output);
	}
}

CEventEntityDumpTrigger::CEventEntityDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CEventEntityDumpTrigger::~CEventEntityDumpTrigger(void)
{
}


void CEventEntityDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CEventEntityDumpTrigger");
	pLogger->output(indent,0,"CEventEntityDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CEventEntityDumpTrigger::beforeAdd(CWriteableEventEntity *pEventEntity)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"EventEntity,add");
		pEventEntity->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add EventEntity\n");
		pEventEntity->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CEventEntityDumpTrigger::beforeUpdate(CEventEntity *pEventEntity, CWriteableEventEntity *pNewEventEntity)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"EventEntity,upd");
		pNewEventEntity->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update EventEntity\n");
		pNewEventEntity->dumpDiff(m_output,pEventEntity);
#endif
		fflush(m_output);
	}
}
	
void CEventEntityDumpTrigger::beforeRemove(CEventEntity *pEventEntity)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"EventEntity,del");
		pEventEntity->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove EventEntity\n");
		pEventEntity->dump(m_output);
#endif
		fflush(m_output);
	}
}

CDumpLog::CDumpLog(CMemoryDB *pDB, CConfig *pConfig)
{
	char *fileName=pConfig->getConfig("DumpOutput");
	if (*fileName=='\0')
	{
		m_DumpOutput=NULL;
		return;
	}
	if (!strcmp(fileName,"stdout"))
	{
		m_DumpOutput=stdout;
	}
	else if (!strcmp(fileName,"stderr"))
	{
		m_DumpOutput=stderr;
	}
	else
	{
		m_DumpOutput=mfopen(fileName,"wt");
	}
	if (m_DumpOutput==NULL)
	{
		REPORT_EVENT(LOG_INFO,"EnvError","write dump file failed");
		return;
	}
	m_DB=pDB;
	m_Started=0;

	m_MonitorEntityTrigger=new CMonitorEntityDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_EventEntityTrigger=new CEventEntityDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
}

CDumpLog::~CDumpLog(void)
{
	stop();
	if (m_DumpOutput==NULL)
	{
		return;
	}
	delete m_MonitorEntityTrigger;
	delete m_EventEntityTrigger;
	if ((m_DumpOutput!=NULL)&&(m_DumpOutput!=stdout)&&(m_DumpOutput!=stderr))
	{
		fclose(m_DumpOutput);
	}
}

int CDumpLog::isStarted(void)
{
	return m_Started;
}

void CDumpLog::start(void)
{
	if (m_Started)
	{
		return;
	}
	if (m_DumpOutput==NULL)
	{
		return;
	}
	m_DB->m_MonitorEntityFactory->addActionTrigger(m_MonitorEntityTrigger);
	m_DB->m_EventEntityFactory->addActionTrigger(m_EventEntityTrigger);
}

void CDumpLog::stop()
{
	if (!m_Started)
	{
		return;
	}
	if (m_DumpOutput==NULL)
	{
		return;
	}
	m_DB->m_MonitorEntityFactory->removeActionTrigger(m_MonitorEntityTrigger);
	m_DB->m_EventEntityFactory->removeActionTrigger(m_EventEntityTrigger);
}

void CDumpLog::dumpMsg(char *format,...)
{
	va_list v;
	
	if (!m_Started)
	{
		return;
	}
	
	va_start(v,format);
	vfprintf(m_DumpOutput,format,v);
	va_end(v);
	fflush(m_DumpOutput);
}

