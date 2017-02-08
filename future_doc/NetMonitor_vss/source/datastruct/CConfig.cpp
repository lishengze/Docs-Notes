/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CConfig.cpp
///@briefʵ������CConfig��CConfigItem
///@history 
///20020214	���ض�		�������ļ�
///20100108 �Ժ��		NT-0094�������ļ���������100Ϊ1024
/////////////////////////////////////////////////////////////////////////

#include "CConfig.h"
#include "CMemory.h"
#include "monitorIndex.h"

CConfig *currentConfig;

CConfig::CConfig(const char *configFilename)
{
	FILE *configFile;

	const int BUF_SIZE = 1024;
	char buffer[BUF_SIZE];

	configFile=mfopen(configFilename,"rt");

	if (configFile==NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"EnvError","can not open config file %s",configFilename);
		return;
	}
	while (fgets(buffer,BUF_SIZE,configFile)!=NULL)
	{
		char *name,*value;
		if (strtok(buffer,"\n\r")==NULL)
			continue;
		if (buffer[0]=='#')
			continue;
		name=strtok(buffer,"\n\r=");
		value=strtok(NULL,"\n\r");
		if (name==NULL)
		{
			REPORT_EVENT(LOG_CRITICAL,"EnvError","error in config file %s",configFilename);
			continue;
		}
		items.push_back(new CConfigItem(name,value));
	}
	fclose(configFile);
}

CConfig::~CConfig(void)
{
	CHECK_TYPE("CConfig");
	for(int i=0; i<items.size(); i++)
	{
		delete items[i];
	}
}

int CConfig::isA(char *objectType)
{
	if (!strcmp(objectType,"CConfig"))
		return 1;
	return CBaseObject::isA(objectType);
}

char *CConfig::getType(void)
{
	return "CConfig";
}


void CConfig::output(CLogger *pLogger,int indent)
{
	CHECK_TYPE("CConfig");
	pLogger->output(indent,0,"CConfig");
	pLogger->output(indent,0,"{");
	for (int i=0;i<items.size();i++)
	{
		items[i]->output(pLogger,indent+1);
	}
	pLogger->output(indent,0,"}");
}


char *CConfig::getConfig(char *name, int *pStartId)
{
	int i;
	char *returnValue="";
	if (pStartId!=NULL)
	{
		i=*pStartId;
	}
	else
	{
		i=0;
	}
	for (;i<items.size();i++)
	{
		CConfigItem *pItem;
		pItem=items[i];
		if (!strcmp(name,pItem->getName()))
		{
			returnValue=pItem->getValue();
			break;
		}
	}
	if (pStartId!=NULL)
	{
		*pStartId=i+1;
	}
	/*
	static char buffer[100];
	sprintf(buffer,"can not get this config:%s",name);
	RAISE_RUNTIME_WARNING(buffer);
	*/
	return returnValue;
}

CConfigItem::CConfigItem(char *name, char *value)
{
	this->name=stringMemory.dup(name);
	if (value!=NULL)
		this->value=stringMemory.dup(value);
	else
		this->value="";
}

CConfigItem::~CConfigItem(void)
{
	CHECK_TYPE("CConfigItem");
}

int CConfigItem::isA(char *objectType)
{
	if (!strcmp(objectType,"CConfigItem"))
		return 1;
	return CBaseObject::isA(objectType);
}

char *CConfigItem::getType(void)
{
	return "CConfigItem";
}

void CConfigItem::output(CLogger *pLogger,int indent)
{
	CHECK_TYPE("CConfigItem");
	pLogger->output(indent,0,"CConfigItem:%s=%s",name,value);
}

char *CConfigItem::getName(void)
{
	return name;
}

char *CConfigItem::getValue(void)
{
	return value;
}

void CConfigItem::setName(char *name)
{
	this->name=name;
}

void CConfigItem::setValue(char *value)
{
	this->value=value;
}
