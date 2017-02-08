// DeployConfig.h: interface for the CDeployConfig class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEPLOYCONFIG_H__56A4888D_6FFE_44AA_B39F_0E49F19F72EA__INCLUDED_)
#define AFX_DEPLOYCONFIG_H__56A4888D_6FFE_44AA_B39F_0E49F19F72EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CXML.h"

struct TCommConfigInfo
{
	DWORD dwSubjectID;
	int nItem;
	char *pszType;
	char *pszAddress;
};

class CCommConfigIterator
{
public:
	CCommConfigIterator(const int nItemID, CXMLNode *pDeployCommsNode, 
		CXMLNode *pRequiredNode, CXMLNode *pSystemCommsNode,  
		const char *pszType, const char *pszCommName);
	~CCommConfigIterator();

	const TCommConfigInfo *Next();

private:
	int m_nItemID;
	CXMLNode *m_pDeployCommsNode;
	CXMLNode *m_pRequiredNode; 
	CXMLNode *m_pSystemCommsNode;
	CXMLNode *m_pTransPortNode;
	const char *m_pszType;
	const char *m_pszCommName;

	int m_nCurrPosition;
	int m_nCurrItem;

	TCommConfigInfo m_CommConfigInfo;
};

struct TDBConfigInfo
{
	char *pszDatabaseName;
	char *pszUserName;
	char *pszPassword;
};

class CDeployConfig  
{
public:
	CDeployConfig(const char *pszConfigPath);
	virtual ~CDeployConfig();
	
	CCommConfigIterator GetSubscribeTopics(const char *pszAppName, 
		const char *pszType = NULL, const int nItemID = 0);
	CCommConfigIterator GetPublishTopics(const char *pszAppName,
		const char *pszType = NULL, const int nItemID = 0);
	CCommConfigIterator GetProvideServices(const char *pszAppName,
		const char *pszType = NULL, const int nItemID = 0);
	CCommConfigIterator GetUseServices(const char *pszAppName,
		const char *pszType = NULL, const int nItemID = 0);

	const TDBConfigInfo *GetDBConfig(const char *pszDBName);
private:
	CCommConfigIterator GetComms(const char *pszTagName, 
		const char *pszCommGroupName, const char *pszCommName,
		const char *pszAppName, const char *pszType, const int nItemID);

private:
	CXMLDoc m_docSystemConfig;
	CXMLDoc m_docDeployConfig;
};

void CommConfigInfoOutput(const char *pszConfigName, const TCommConfigInfo *pCommConfigInfo);

#endif // !defined(AFX_DEPLOYCONFIG_H__56A4888D_6FFE_44AA_B39F_0E49F19F72EA__INCLUDED_)
