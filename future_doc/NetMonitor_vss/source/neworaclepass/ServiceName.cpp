// ServiceName.cpp: implementation of the CServiceName class.
//
//////////////////////////////////////////////////////////////////////

#include "platform.h"
#include "ServiceName.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CServiceName::CServiceName(char *location)
{
	if ((location==NULL)||(*location=='\0'))
	{
		printf("empty location for service name");
	}
	m_pLocation=new char[strlen(location)+1];
	m_pBuffer = new char[strlen(location)+1];
	strcpy(m_pLocation, location);
	strcpy(m_pBuffer, location);
	char *buffer=m_pBuffer;
	char *startPort="";
	m_pChannel=buffer;
	m_pHost="";
	m_nPort=0;
	m_pServiceName="";
	char *p=strchr(buffer,':');
	if (p==NULL)
	{
		//no semicolon in location, there should be only channel in this location
		return;
	}
	*p='\0';
	p++;
	//check for // after semicolon
	if ((*p!='/')||(*(p+1)!='/'))
		printf("Invalid location");
	p+=2;
	m_pHost=p;
	//loop until the end of hostname
	while ((*p)&&(*p!=':')&&(*p!='/'))
		p++;
	if (*p==':')
	{
		*p='\0';
		p++;
		startPort=p;
		//loop until the end of port
		while ((*p)&&(*p!='/'))
			p++;
	}
	if (*p=='/')
	{
		*p='\0';
		p++;
		m_pServiceName=p;
	}
	m_nPort=atoi(startPort);
}

CServiceName::~CServiceName()
{
	delete m_pLocation;
	delete m_pBuffer;
}

