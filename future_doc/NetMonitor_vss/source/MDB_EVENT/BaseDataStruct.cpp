/////////////////////////////////////////////////////////////////////////
///@system ִ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file BaseDataStruct.cpp
///@briefʵ�����ڴ����ݿ��õĻ������ݽṹ�࣬�Լ�iterator��trigger�Ļ���
///@history 
///20060128	���ض�		�������ļ�
///20081203	���ض�		Ϊ��NT-0058����Ҫ�������˶���CSVʱ�Զ�ʶ��˫���ŵĹ���
/////////////////////////////////////////////////////////////////////////

#include "BaseDataStruct.h"
#include "databaseFactories.h"

int compare(const char *s1, const char *s2)
{
	int result=strcmp(s1,s2);
	if (result>0)
		return 1;
	else if (result<0)
		return -1;
	return 0;
}

int compare(const int v1,const int v2)
{
	if (v1>v2)
		return 1;
	if (v1<v2)
		return -1;
	return 0;
}

int compare(const QWORD v1,const QWORD v2)
{
	if (v1>v2)
		return 1;
	if (v1<v2)
		return -1;
	return 0;
}

int compare(const double v1,const double v2)
{
	if (v1>v2+SMALL_DOUBLE)
		return 1;
	if (v1<v2-SMALL_DOUBLE)
		return -1;
	return 0;
}

char *getNextToken(char *buffer)
{
	static char *last;
	char *from, *to;
	
	if (buffer==NULL)
	{
		from=last;
		if (from==NULL)
		{
			return NULL;
		}
	}
	else
	{
		from=buffer;
	}
	
	bool hasQuote=false;
	if (*from=='"')
	{
		from++;
		hasQuote=true;
	}
	to=from;
	while ((*to!='\0')&&(*to!=',')&&(*to!='\n'))
	{
		if (hasQuote && (*to=='"'))
		{
			to++;
			break;
		}
		to++;
	}
	if (*to!=',')
	{
		last=NULL;
	}
	else
	{
		last=to+1;
	}
	if (!hasQuote)
	{
		*to='\0';
	}
	else
	{
		*(to-1)='\0';
	}
	return from;
}


void CWriteableMonitorEntity::writeCSVHead(FILE *output)
{
	fprintf(output,"MonitorObject,MonitorItem,MonitorTime,Time,ValueType,AttrValue\n");
}
	
void CWriteableMonitorEntity::init(void)
{
	MonitorObject.clear();
	MonitorItem.clear();
	MonitorTime.clear();
	Time.clear();
	ValueType.clear();
	AttrValue.clear();
}

int CWriteableMonitorEntity::read(FILE *input) 
{
	if (fread(this,1,sizeof(CWriteableMonitorEntity),input)!=sizeof(CWriteableMonitorEntity))
		return 0;
	else
		return 1;
}
	
int CWriteableMonitorEntity::readCSV(FILE *input,vector<char *> *pNames)
{
	char buffer[1025];
	char *token;
	if (fgets(buffer,1024,input)==NULL)
		return 0;
	if (pNames==NULL)
	{
		token=getNextToken(buffer);
		if (token!=NULL)
		{
			MonitorObject=token;
		}
		else
		{
			MonitorObject="";
		}
		token=getNextToken(NULL);
		if (token!=NULL)
		{
			MonitorItem=token;
		}
		else
		{
			MonitorItem="";
		}
		token=getNextToken(NULL);
		if (token!=NULL)
		{
			MonitorTime=token;
		}
		else
		{
			MonitorTime="";
		}
		token=getNextToken(NULL);
		if (token!=NULL)
		{
			Time=token;
		}
		else
		{
			Time="";
		}
		token=getNextToken(NULL);
		if (token!=NULL)
		{
			ValueType=token;
		}
		else
		{
			ValueType="";
		}
		token=getNextToken(NULL);
		if (token!=NULL)
		{
			AttrValue=token;
		}
		else
		{
			AttrValue="";
		}
	}
	else
	{
		init();
		token=getNextToken(buffer);
		int i=0;
		while (token!=NULL)
		{
			char *fieldName;
			fieldName=pNames->at(i);
			if (fieldName==NULL)
			{
				break;
			}
			if (!strcmp(fieldName,"MonitorObject"))
			{
				MonitorObject=token;
			}
			else if (!strcmp(fieldName,"MonitorItem"))
			{
				MonitorItem=token;
			}
			else if (!strcmp(fieldName,"MonitorTime"))
			{
				MonitorTime=token;
			}
			else if (!strcmp(fieldName,"Time"))
			{
				Time=token;
			}
			else if (!strcmp(fieldName,"ValueType"))
			{
				ValueType=token;
			}
			else if (!strcmp(fieldName,"AttrValue"))
			{
				AttrValue=token;
			}
			i++;
			token=getNextToken(NULL);
		}
	}
	return 1;
}
	
int CWriteableMonitorEntity::write(FILE *output) const
{
	if (fwrite(this,1,sizeof(CWriteableMonitorEntity),output)!=sizeof(CWriteableMonitorEntity))
		return 0;
	else
		return 1;
}

int CWriteableMonitorEntity::writeCSV(FILE *output) const
{
	char buffer[1025];
	MonitorObject.getString(buffer);
	fprintf(output,"%s",buffer);
	fprintf(output,",");
	MonitorItem.getString(buffer);
	fprintf(output,"%s",buffer);
	fprintf(output,",");
	MonitorTime.getString(buffer);
	fprintf(output,"%s",buffer);
	fprintf(output,",");
	Time.getString(buffer);
	fprintf(output,"%s",buffer);
	fprintf(output,",");
	ValueType.getString(buffer);
	fprintf(output,"%s",buffer);
	fprintf(output,",");
	AttrValue.getString(buffer);
	fprintf(output,"%s",buffer);
	fprintf(output,"\n");
	return 1;
}
void CWriteableMonitorEntity::dump(FILE *fp,int index) const
{
	char index_buf[20];
	char buf[4000];///���ÿ����Ա���ַ���ֵ	
	if(fp==NULL)
	{
		fp=stdout;
	}
	if (index>=0)
		sprintf(index_buf,"[%d]",index);
	else
		index_buf[0]='\0';
	fprintf(fp, "\tCMonitorEntity%s = {\n", index_buf);
	MonitorObject.getString(buf);
	fprintf(fp,"\t\tMonitorObject = %s    [��ض���]\n",buf);	
	MonitorItem.getString(buf);
	fprintf(fp,"\t\tMonitorItem = %s    [���ָ����]\n",buf);	
	MonitorTime.getString(buf);
	fprintf(fp,"\t\tMonitorTime = %s    [���ʱ��]\n",buf);	
	Time.getString(buf);
	fprintf(fp,"\t\tTime = %s    [ʱ���ַ�����ʽ]\n",buf);	
	ValueType.getString(buf);
	fprintf(fp,"\t\tValueType = %s    [���ָ���ֵ����]\n",buf);	
	AttrValue.getString(buf);
	fprintf(fp,"\t\tAttrValue = %s    [���ָ��ľ���ֵ]\n",buf);	
	fprintf(fp,"\t}\n");
}

void CWriteableMonitorEntity::dumpDiff(FILE *fp, const CWriteableMonitorEntity *pOriginal) const
{
	char buf[4000],bufOriginal[4000];
	if(fp==NULL)
	{
		fp=stdout;
	}
	fprintf(fp, "\tCMonitorEntity = {\n");
	MonitorObject.getString(buf);
	if (compare(MonitorObject.getValue(),pOriginal->MonitorObject.getValue())!=0)
	{
		pOriginal->MonitorObject.getString(bufOriginal);
		fprintf(fp,"\t\tMonitorObject = %s -> %s    [��ض���]\n",bufOriginal,buf);
	}
	else
	{
		fprintf(fp,"\t\tMonitorObject = %s    [��ض���]\n",buf);
	}
	MonitorItem.getString(buf);
	if (compare(MonitorItem.getValue(),pOriginal->MonitorItem.getValue())!=0)
	{
		pOriginal->MonitorItem.getString(bufOriginal);
		fprintf(fp,"\t\tMonitorItem = %s -> %s    [���ָ����]\n",bufOriginal,buf);
	}
	else
	{
		fprintf(fp,"\t\tMonitorItem = %s    [���ָ����]\n",buf);
	}
	MonitorTime.getString(buf);
	if (compare(MonitorTime.getValue(),pOriginal->MonitorTime.getValue())!=0)
	{
		pOriginal->MonitorTime.getString(bufOriginal);
		fprintf(fp,"\t\tMonitorTime = %s -> %s    [���ʱ��]\n",bufOriginal,buf);
	}
	else
	{
		fprintf(fp,"\t\tMonitorTime = %s    [���ʱ��]\n",buf);
	}
	Time.getString(buf);
	if (compare(Time.getValue(),pOriginal->Time.getValue())!=0)
	{
		pOriginal->Time.getString(bufOriginal);
		fprintf(fp,"\t\tTime = %s -> %s    [ʱ���ַ�����ʽ]\n",bufOriginal,buf);
	}
	else
	{
		fprintf(fp,"\t\tTime = %s    [ʱ���ַ�����ʽ]\n",buf);
	}
	ValueType.getString(buf);
	if (compare(ValueType.getValue(),pOriginal->ValueType.getValue())!=0)
	{
		pOriginal->ValueType.getString(bufOriginal);
		fprintf(fp,"\t\tValueType = %s -> %s    [���ָ���ֵ����]\n",bufOriginal,buf);
	}
	else
	{
		fprintf(fp,"\t\tValueType = %s    [���ָ���ֵ����]\n",buf);
	}
	AttrValue.getString(buf);
	if (compare(AttrValue.getValue(),pOriginal->AttrValue.getValue())!=0)
	{
		pOriginal->AttrValue.getString(bufOriginal);
		fprintf(fp,"\t\tAttrValue = %s -> %s    [���ָ��ľ���ֵ]\n",bufOriginal,buf);
	}
	else
	{
		fprintf(fp,"\t\tAttrValue = %s    [���ָ��ľ���ֵ]\n",buf);
	}
	fprintf(fp,"\t}\n");
}

void CWriteableMonitorEntity::dumpInLine(FILE *fp) const
{
	char buf[4000];///���ÿ����Ա���ַ���ֵ	
	if(fp==NULL)
	{
		fp=stdout;
	}
	MonitorObject.getString(buf);
	fprintf(fp,",MonitorObject,%s",buf);	
	MonitorItem.getString(buf);
	fprintf(fp,",MonitorItem,%s",buf);	
	MonitorTime.getString(buf);
	fprintf(fp,",MonitorTime,%s",buf);	
	Time.getString(buf);
	fprintf(fp,",Time,%s",buf);	
	ValueType.getString(buf);
	fprintf(fp,",ValueType,%s",buf);	
	AttrValue.getString(buf);
	fprintf(fp,",AttrValue,%s",buf);	
}

void CWriteableMonitorEntity::dumpString(char *target) const
{
	char *p=target;
	char buf[4000];///���ÿ����Ա���ַ���ֵ	
	MonitorObject.getString(buf);
	sprintf(p,"MonitorObject=%s,",buf);
	p+=strlen(p);
	MonitorItem.getString(buf);
	sprintf(p,"MonitorItem=%s,",buf);
	p+=strlen(p);
	MonitorTime.getString(buf);
	sprintf(p,"MonitorTime=%s,",buf);
	p+=strlen(p);
	Time.getString(buf);
	sprintf(p,"Time=%s,",buf);
	p+=strlen(p);
	ValueType.getString(buf);
	sprintf(p,"ValueType=%s,",buf);
	p+=strlen(p);
	AttrValue.getString(buf);
	sprintf(p,"AttrValue=%s,",buf);
	p+=strlen(p);
	p--;
	*p='\0';
}

void CWriteableMonitorEntity::output(CLogger *pLogger,int indent)
{
	char buf[1024];
	pLogger->output(indent,0,"CMonitorEntity");
	pLogger->output(indent,0,"{");
	MonitorObject.getString(buf);
	pLogger->output(indent+1,0,"MonitorObject=%s ��ض���",buf);
	MonitorItem.getString(buf);
	pLogger->output(indent+1,0,"MonitorItem=%s ���ָ����",buf);
	MonitorTime.getString(buf);
	pLogger->output(indent+1,0,"MonitorTime=%s ���ʱ��",buf);
	Time.getString(buf);
	pLogger->output(indent+1,0,"Time=%s ʱ���ַ�����ʽ",buf);
	ValueType.getString(buf);
	pLogger->output(indent+1,0,"ValueType=%s ���ָ���ֵ����",buf);
	AttrValue.getString(buf);
	pLogger->output(indent+1,0,"AttrValue=%s ���ָ��ľ���ֵ",buf);
	pLogger->output(indent,0,"}");
}

CMonitorEntityIterator::~CMonitorEntityIterator(void)
{
}


void CMonitorEntityIterator::dump(FILE *output)
{
	CMonitorEntity *pMonitorEntity;
	
	while ((pMonitorEntity=next())!=NULL)
	{
		pMonitorEntity->dump(output);
	}
}



void CWriteableEventEntity::writeCSVHead(FILE *output)
{
	fprintf(output,"MonitorTime,EventName,MonitorObject,EventDes,ProcessFlag,Time,WarningLevel\n");
}
	
void CWriteableEventEntity::init(void)
{
	MonitorTime.clear();
	EventName.clear();
	MonitorObject.clear();
	EventDes.clear();
	ProcessFlag.clear();
	Time.clear();
	WarningLevel.clear();
}

int CWriteableEventEntity::read(FILE *input) 
{
	if (fread(this,1,sizeof(CWriteableEventEntity),input)!=sizeof(CWriteableEventEntity))
		return 0;
	else
		return 1;
}
	
int CWriteableEventEntity::readCSV(FILE *input,vector<char *> *pNames)
{
	char buffer[1025];
	char *token;
	if (fgets(buffer,1024,input)==NULL)
		return 0;
	if (pNames==NULL)
	{
		token=getNextToken(buffer);
		if (token!=NULL)
		{
			MonitorTime=token;
		}
		else
		{
			MonitorTime="";
		}
		token=getNextToken(NULL);
		if (token!=NULL)
		{
			EventName=token;
		}
		else
		{
			EventName="";
		}
		token=getNextToken(NULL);
		if (token!=NULL)
		{
			MonitorObject=token;
		}
		else
		{
			MonitorObject="";
		}
		token=getNextToken(NULL);
		if (token!=NULL)
		{
			EventDes=token;
		}
		else
		{
			EventDes="";
		}
		token=getNextToken(NULL);
		if (token!=NULL)
		{
			ProcessFlag=token;
		}
		else
		{
			ProcessFlag="";
		}
		token=getNextToken(NULL);
		if (token!=NULL)
		{
			Time=token;
		}
		else
		{
			Time="";
		}
		token=getNextToken(NULL);
		if (token!=NULL)
		{
			WarningLevel=token;
		}
		else
		{
			WarningLevel="";
		}
	}
	else
	{
		init();
		token=getNextToken(buffer);
		int i=0;
		while (token!=NULL)
		{
			char *fieldName;
			fieldName=pNames->at(i);
			if (fieldName==NULL)
			{
				break;
			}
			if (!strcmp(fieldName,"MonitorTime"))
			{
				MonitorTime=token;
			}
			else if (!strcmp(fieldName,"EventName"))
			{
				EventName=token;
			}
			else if (!strcmp(fieldName,"MonitorObject"))
			{
				MonitorObject=token;
			}
			else if (!strcmp(fieldName,"EventDes"))
			{
				EventDes=token;
			}
			else if (!strcmp(fieldName,"ProcessFlag"))
			{
				ProcessFlag=token;
			}
			else if (!strcmp(fieldName,"Time"))
			{
				Time=token;
			}
			else if (!strcmp(fieldName,"WarningLevel"))
			{
				WarningLevel=token;
			}
			i++;
			token=getNextToken(NULL);
		}
	}
	return 1;
}
	
int CWriteableEventEntity::write(FILE *output) const
{
	if (fwrite(this,1,sizeof(CWriteableEventEntity),output)!=sizeof(CWriteableEventEntity))
		return 0;
	else
		return 1;
}

int CWriteableEventEntity::writeCSV(FILE *output) const
{
	char buffer[1025];
	MonitorTime.getString(buffer);
	fprintf(output,"%s",buffer);
	fprintf(output,",");
	EventName.getString(buffer);
	fprintf(output,"%s",buffer);
	fprintf(output,",");
	MonitorObject.getString(buffer);
	fprintf(output,"%s",buffer);
	fprintf(output,",");
	EventDes.getString(buffer);
	fprintf(output,"%s",buffer);
	fprintf(output,",");
	ProcessFlag.getString(buffer);
	fprintf(output,"%s",buffer);
	fprintf(output,",");
	Time.getString(buffer);
	fprintf(output,"%s",buffer);
	fprintf(output,",");
	WarningLevel.getString(buffer);
	fprintf(output,"%s",buffer);
	fprintf(output,"\n");
	return 1;
}
void CWriteableEventEntity::dump(FILE *fp,int index) const
{
	char index_buf[20];
	char buf[4000];///���ÿ����Ա���ַ���ֵ	
	if(fp==NULL)
	{
		fp=stdout;
	}
	if (index>=0)
		sprintf(index_buf,"[%d]",index);
	else
		index_buf[0]='\0';
	fprintf(fp, "\tCEventEntity%s = {\n", index_buf);
	MonitorTime.getString(buf);
	fprintf(fp,"\t\tMonitorTime = %s    [���ʱ��]\n",buf);	
	EventName.getString(buf);
	fprintf(fp,"\t\tEventName = %s    [�¼���]\n",buf);	
	MonitorObject.getString(buf);
	fprintf(fp,"\t\tMonitorObject = %s    [��ض���ID]\n",buf);	
	EventDes.getString(buf);
	fprintf(fp,"\t\tEventDes = %s    [�¼�����]\n",buf);	
	ProcessFlag.getString(buf);
	fprintf(fp,"\t\tProcessFlag = %s    [�¼��������]\n",buf);	
	Time.getString(buf);
	fprintf(fp,"\t\tTime = %s    [ʱ���ַ�����ʽ]\n",buf);	
	WarningLevel.getString(buf);
	fprintf(fp,"\t\tWarningLevel = %s    [��־�¼�����]\n",buf);	
	fprintf(fp,"\t}\n");
}

void CWriteableEventEntity::dumpDiff(FILE *fp, const CWriteableEventEntity *pOriginal) const
{
	char buf[4000],bufOriginal[4000];
	if(fp==NULL)
	{
		fp=stdout;
	}
	fprintf(fp, "\tCEventEntity = {\n");
	MonitorTime.getString(buf);
	if (compare(MonitorTime.getValue(),pOriginal->MonitorTime.getValue())!=0)
	{
		pOriginal->MonitorTime.getString(bufOriginal);
		fprintf(fp,"\t\tMonitorTime = %s -> %s    [���ʱ��]\n",bufOriginal,buf);
	}
	else
	{
		fprintf(fp,"\t\tMonitorTime = %s    [���ʱ��]\n",buf);
	}
	EventName.getString(buf);
	if (compare(EventName.getValue(),pOriginal->EventName.getValue())!=0)
	{
		pOriginal->EventName.getString(bufOriginal);
		fprintf(fp,"\t\tEventName = %s -> %s    [�¼���]\n",bufOriginal,buf);
	}
	else
	{
		fprintf(fp,"\t\tEventName = %s    [�¼���]\n",buf);
	}
	MonitorObject.getString(buf);
	if (compare(MonitorObject.getValue(),pOriginal->MonitorObject.getValue())!=0)
	{
		pOriginal->MonitorObject.getString(bufOriginal);
		fprintf(fp,"\t\tMonitorObject = %s -> %s    [��ض���ID]\n",bufOriginal,buf);
	}
	else
	{
		fprintf(fp,"\t\tMonitorObject = %s    [��ض���ID]\n",buf);
	}
	EventDes.getString(buf);
	if (compare(EventDes.getValue(),pOriginal->EventDes.getValue())!=0)
	{
		pOriginal->EventDes.getString(bufOriginal);
		fprintf(fp,"\t\tEventDes = %s -> %s    [�¼�����]\n",bufOriginal,buf);
	}
	else
	{
		fprintf(fp,"\t\tEventDes = %s    [�¼�����]\n",buf);
	}
	ProcessFlag.getString(buf);
	if (compare(ProcessFlag.getValue(),pOriginal->ProcessFlag.getValue())!=0)
	{
		pOriginal->ProcessFlag.getString(bufOriginal);
		fprintf(fp,"\t\tProcessFlag = %s -> %s    [�¼��������]\n",bufOriginal,buf);
	}
	else
	{
		fprintf(fp,"\t\tProcessFlag = %s    [�¼��������]\n",buf);
	}
	Time.getString(buf);
	if (compare(Time.getValue(),pOriginal->Time.getValue())!=0)
	{
		pOriginal->Time.getString(bufOriginal);
		fprintf(fp,"\t\tTime = %s -> %s    [ʱ���ַ�����ʽ]\n",bufOriginal,buf);
	}
	else
	{
		fprintf(fp,"\t\tTime = %s    [ʱ���ַ�����ʽ]\n",buf);
	}
	WarningLevel.getString(buf);
	if (compare(WarningLevel.getValue(),pOriginal->WarningLevel.getValue())!=0)
	{
		pOriginal->WarningLevel.getString(bufOriginal);
		fprintf(fp,"\t\tWarningLevel = %s -> %s    [��־�¼�����]\n",bufOriginal,buf);
	}
	else
	{
		fprintf(fp,"\t\tWarningLevel = %s    [��־�¼�����]\n",buf);
	}
	fprintf(fp,"\t}\n");
}

void CWriteableEventEntity::dumpInLine(FILE *fp) const
{
	char buf[4000];///���ÿ����Ա���ַ���ֵ	
	if(fp==NULL)
	{
		fp=stdout;
	}
	MonitorTime.getString(buf);
	fprintf(fp,",MonitorTime,%s",buf);	
	EventName.getString(buf);
	fprintf(fp,",EventName,%s",buf);	
	MonitorObject.getString(buf);
	fprintf(fp,",MonitorObject,%s",buf);	
	EventDes.getString(buf);
	fprintf(fp,",EventDes,%s",buf);	
	ProcessFlag.getString(buf);
	fprintf(fp,",ProcessFlag,%s",buf);	
	Time.getString(buf);
	fprintf(fp,",Time,%s",buf);	
	WarningLevel.getString(buf);
	fprintf(fp,",WarningLevel,%s",buf);	
}

void CWriteableEventEntity::dumpString(char *target) const
{
	char *p=target;
	char buf[4000];///���ÿ����Ա���ַ���ֵ	
	MonitorTime.getString(buf);
	sprintf(p,"MonitorTime=%s,",buf);
	p+=strlen(p);
	EventName.getString(buf);
	sprintf(p,"EventName=%s,",buf);
	p+=strlen(p);
	MonitorObject.getString(buf);
	sprintf(p,"MonitorObject=%s,",buf);
	p+=strlen(p);
	EventDes.getString(buf);
	sprintf(p,"EventDes=%s,",buf);
	p+=strlen(p);
	ProcessFlag.getString(buf);
	sprintf(p,"ProcessFlag=%s,",buf);
	p+=strlen(p);
	Time.getString(buf);
	sprintf(p,"Time=%s,",buf);
	p+=strlen(p);
	WarningLevel.getString(buf);
	sprintf(p,"WarningLevel=%s,",buf);
	p+=strlen(p);
	p--;
	*p='\0';
}

void CWriteableEventEntity::output(CLogger *pLogger,int indent)
{
	char buf[1024];
	pLogger->output(indent,0,"CEventEntity");
	pLogger->output(indent,0,"{");
	MonitorTime.getString(buf);
	pLogger->output(indent+1,0,"MonitorTime=%s ���ʱ��",buf);
	EventName.getString(buf);
	pLogger->output(indent+1,0,"EventName=%s �¼���",buf);
	MonitorObject.getString(buf);
	pLogger->output(indent+1,0,"MonitorObject=%s ��ض���ID",buf);
	EventDes.getString(buf);
	pLogger->output(indent+1,0,"EventDes=%s �¼�����",buf);
	ProcessFlag.getString(buf);
	pLogger->output(indent+1,0,"ProcessFlag=%s �¼��������",buf);
	Time.getString(buf);
	pLogger->output(indent+1,0,"Time=%s ʱ���ַ�����ʽ",buf);
	WarningLevel.getString(buf);
	pLogger->output(indent+1,0,"WarningLevel=%s ��־�¼�����",buf);
	pLogger->output(indent,0,"}");
}

CEventEntityIterator::~CEventEntityIterator(void)
{
}


void CEventEntityIterator::dump(FILE *output)
{
	CEventEntity *pEventEntity;
	
	while ((pEventEntity=next())!=NULL)
	{
		pEventEntity->dump(output);
	}
}


