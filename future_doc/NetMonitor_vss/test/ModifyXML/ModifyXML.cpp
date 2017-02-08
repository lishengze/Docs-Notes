/////////////////////////////////////////////////////////////////////////
///@system 执行引擎系统
///@company 上海期货信息技术有限公司
///@file CXML.cpp
///@brief实现了XML的测试
///@history 
///20051231	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#include "CXML.h"
#include "XMLAction.h"

#define STRINGLENGTH 8000

void argvChange(char *connectStr,char *sid,char *user,char *passwd)
{
	char *p=connectStr;
	char *t=user;

	for(;*p!=0;p++)
	{
		*t=*p;
		if(*t=='/')
		{
			*t=0;
			t=passwd;
		}
		else if (*t=='@')
		{
			*t=0;
			t=sid;
		}
		else t++;
	}
	*t=0;
}

void stringToXMLNode(char *str,CXMLNode *pNode)
{
	char name[STRINGLENGTH];
	char value[STRINGLENGTH];
	char *p=str;

	if (pNode==NULL)
		return;

	char *t=name;
	bool hasValue=false;
	for(;*p!=0;p++)
	{
		*t=*p;
		
		if(*t=='=')
		{
			*t=0;
			t=value;
			hasValue=true;
		}
		else if(*t=='%')
		{
			*t=*(++p);
		}
		else
			t++;
	}
	*t=0;
	if (hasValue)
	{
		pNode->setProperty(name,value);
	}
	else
	{
		CXMLNode *pSon;
		pSon=new CXMLNode();
		pSon->setNodeType(XMLText);
		pSon->setName(name);
		pNode->addNode(pSon);
	}
}

int main(int argc, char *argv[])
{
	CXMLDoc *pTestDoc;
	CXMLNode *pTestDocRoot;
	CXMLDisplayAction displayAction;

	char sid[STRINGLENGTH];
	char user[STRINGLENGTH];
	char password[STRINGLENGTH];
	char xpath[STRINGLENGTH];
	char tempstr[STRINGLENGTH];
	char filename[STRINGLENGTH];

	CXMLNode node;

	if (argc < 3)
	{
		printf("Usage: %s -s filename xpath DBConnectString\n",argv[0]);
		printf("       %s    filename xpath propertyname=propertyvalue ...\n",argv[0]);
		printf("       %s    filename xpath value ...\n",argv[0]);
		exit(0);
	}
	
	if ( strcmp(argv[1],"-s"))
	{
		for(int i=3;i<argc;i++)
		{
			stringToXMLNode(argv[i],&node);
		}
		strcpy(filename,argv[1]);
		strcpy(xpath,argv[2]);
	}
	else
	{
		argvChange(argv[4],sid,user,password);
		sprintf(tempstr,"connectString=%s",sid);
		stringToXMLNode(tempstr,&node);
		sprintf(tempstr,"password=%s",password);
		stringToXMLNode(tempstr,&node);
		strcpy(filename,argv[2]);
		strcpy(xpath,argv[3]);
	}
	
	try
	{
	
		pTestDoc=new CXMLDoc;
		pTestDoc->read(filename,0,false);
		pTestDocRoot=pTestDoc->getRootNode();

		CXMLUpdateAction updateAction(&node);

		int result=pTestDocRoot->XAction(xpath,&updateAction);

		pTestDoc->write(filename);
		return result;
		
	}
	catch (CParseError *pParseError)
	{
		printf("parse error:\n%s at line %d\n",pParseError->getMsg(),pParseError->getLineNo());
		return -1;
	}
	return 0;
}


