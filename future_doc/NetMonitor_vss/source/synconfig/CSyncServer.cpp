/////////////////////////////////////////////////////////////////////////
///@system 网络监控系统
///@company 上海期货信息技术有限公司
///@file CSyncServer.cpp
///@brief 配置服务同步数据Session
///@history
///20110926	李志伟   实现该文件
/////////////////////////////////////////////////////////////////////////
#include "CSyncServer.h"
#include "UFCopy.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include <PrjCommon.h>
#include <FTDDataHelper.h>
#include <algorithm>
#include "CSyncServer_internal.h"
#include <ScopedLock.h>

#ifdef PACKAGE_OUTPUT
extern CFileLogger	*g_recvPkgLogger;			// 数据包输出到文件
extern CBufferLogger *g_bufferLogger;
#endif
extern const char *g_FileServPath;
extern const char *g_FileXMLPath;
extern CXMLDoc	*pUpdateDoc;

#ifdef _WIN32
#include <direct.h>
#include <io.h>
#elif _LINUX
#include <stdarg.h>
#include <sys/stat.h>
#endif
#ifdef _WIN32
#define ACCESS		_access
#define MKDIR(a)	_mkdir((a))
#else
#define ACCESS		access
#define MKDIR(a)	mkdir((a), 0755)
#endif
int CreatMultiDir1(char *pszDir)
{
	int i = 0;
	int iRet;
	int iLen = strlen(pszDir);

	//在末尾加/
	/*if (pszDir[iLen - 1] != '\\' && pszDir[iLen - 1] != '/')
	{
		pszDir[iLen] = '/';
		pszDir[iLen + 1] = '\0';
	}*/
	// 创建目录
	for (i = 0; i < iLen; i++)
	{
		if (pszDir[i] == '\\' || pszDir[i] == '/')
		{
			pszDir[i] = '\0';

			//如果不存在,创建
			iRet = ACCESS(pszDir, 0);
			if (iRet != 0)
			{
				iRet = MKDIR(pszDir);
				if (iRet != 0)
				{
					return -1;
				}
			}

			//支持linux,将所有\换成/
			pszDir[i] = '/';
		}
	}

	return 0;
}

string &replace_all_distinct1(
	string	&str,
	const string old_value,
	const string new_value)
{
	int index = 0;
	index = str.find(old_value);
	while (index >= 0)
	{
		str.replace(index, old_value.length(), new_value);
		index = str.find(old_value, index + 1);
	}

	return str;
}

CSyncServer::CSyncServer(CReactor *pReactor) :
	CSessionFactory(pReactor, 10),
	m_timmer(NULL),
	m_flowSync(NULL)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	m_dbHandler.SetOperateMaster("CSynServer",NULL);
}

CSyncServer::~CSyncServer(void)
{
	if (!isMaster())
	{
		assert(m_timmer);
		m_timmer->KillTimer(SYNC_TIMMER);
		delete m_timmer;
	}

	assert(m_flowSync);
	delete m_flowSync;
}

bool CSyncServer::Init(void)
{
	bool rtn = false;

	LOG_INFO("CSyncServer connect DB:\t");
	rtn = m_dbHandler.Open(
			ConfigInfo::Instance().DBIp(),
			ConfigInfo::Instance().DBPort(),
			ConfigInfo::Instance().DBName(),
			ConfigInfo::Instance().DBUser(),
			ConfigInfo::Instance().DBPwd());

	m_flowSync = new FlowSync(this);
	rtn = m_flowSync->setupSyncFlow();

	static int	sync_timmer_elapse = 10 * 1000;

	if (!isMaster())
	{
		m_timmer = new Timmer(this->m_pReactor, this);
		m_timmer->SetTimer(SYNC_TIMMER, sync_timmer_elapse);
	}

	return rtn;
}

void CSyncServer::NotifyAllSessions(CFTDCPackage *pkg)
{
	assert(pkg);

	if (!isMaster())
	{
		assert(
			true
			&&	"Only master sync server could notify changed data to slavery");
		LOG_ERROR(
			"Only master sync server could notify changed data to slavery");
		return;
	}

	ScopeLock<CMutex> lock(m_lock);

	for (SessionSet::iterator it = m_sessions.begin();
		 it != m_sessions.end();
		 it++)
	{
		(*it)->SendRequestPackage(pkg);
		pkg->Pop(FTDCHLEN);
	}

	// 在同步流中记录数据包
	m_flowSync->addToFlow(pkg);
}

CSession *CSyncServer::CreateSession(CChannel *pChannel, DWORD dwMark)
{
	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	pSession->RegisterPackageHandler(this);

	/// Added by Henchi, 20120309
	pSession->SetCompressMethod(CRPCM_ZERO);	//设置压缩算法
	return pSession;
}

void CSyncServer::OnSessionConnected(CSession *pSession)
{
	CSessionFactory::OnSessionConnected(pSession);

	LOG_INFO(
		"%s CSyncServer::OnSessionConnected: %0x Connected, CommonName [%s] RemoteName [%s] ==\n",
		CurrentTime(),
		(CFTDCSession *)pSession,
		pSession->GetChannel()->GetRemoteCommonName(),
		pSession->GetChannel()->GetRemoteName());

	ScopeLock<CMutex> lock(m_lock);

	// 保存连接
	m_sessions.push_back((CFTDCSession *)pSession);

	if (!isMaster())
	{
		// 当CFTDCSession被释放时，会自动UnRegisterSubscriber(m_flowSync)
		((CFTDCSession *)pSession)->RegisterSubscriber(m_flowSync);
	}
}

void CSyncServer::OnSessionDisconnected(CSession *pSession, int nReason)	// 子类重载处理连接断开事件
{
	CSessionFactory::OnSessionDisconnected(pSession, nReason);	// 子类调用父类处理连接断开事件
	LOG_INFO(
		"CSyncServer::OnSessionDisconnected: %0x %s",
		(CFTDCSession *)pSession,
		CurrentTime());

	ScopeLock<CMutex> lock(m_lock);

	// 删除失效连接
	SessionSet::iterator it = find(
			m_sessions.begin(),
			m_sessions.end(),
			(CFTDCSession *)pSession);
	if (it != m_sessions.end())
	{
		m_sessions.erase(it);
	}
}

void CSyncServer::syncFlow(void)
{
	CFTDDisseminationField	flowInfo;
	flowInfo.SequenceSeries = m_flowSync->GetSequenceSeries();
	flowInfo.SequenceNo = m_flowSync->GetReceivedCount();

	m_pkgSend.PreparePackage(
			FTD_TID_ReqSubscribeTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	FTDC_ADD_FIELD(&m_pkgSend, &flowInfo);

	// 只有一个与master sync server的session
	assert(m_sessions.size() == 1);

	m_sessions[0]->SendRequestPackage(&m_pkgSend);

	return;
}

void CSyncServer::Timmer::OnTimer(int nIDEvent)
{
	if (nIDEvent == SYNC_TIMMER)
	{
		//m_syncServer->syncFlow();
	}
}

FlowSync::~FlowSync(void)
{
	if (m_flow)
	{
		delete m_flow;
	}
}

bool FlowSync::setupSyncFlow(void)
{
	//m_flow = new CCachedFileFlow("syncFlow", "../flow", true, 1000, 32*1024);
	return true;
}

bool FlowSync::addToFlow(CFTDCPackage *pFTDCPackage)
{
	//pFTDCPackage->Push(FTDCHLEN);
	//m_flow->Append(pFTDCPackage->Address(), pFTDCPackage->Length());
	return true;
}

void FlowSync::OnReqFlowSyncTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDDisseminationField	flowInfo;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &flowInfo))
	{
		pSession->Publish(m_flow, flowInfo.SequenceSeries, flowInfo.SequenceNo);
	}
}

void FlowSync::SetCommPhaseNo(WORD wCommPhaseNo)
{
	// Empty!
}

WORD FlowSync::GetSequenceSeries(void)
{
	static const int sync_flow_id = 0x20;

	return sync_flow_id;
}

DWORD FlowSync::GetReceivedCount(void)
{
	return m_flow->GetCount();
}

void FlowSync::HandleMessage(CFTDCPackage *pFTDCPackage)
{
	LOG_INFO("Slavery Sync Server sync flow info: [begain] \n");

	m_syncServer->HandlePackage(pFTDCPackage, m_syncServer->m_sessions[0]);

	LOG_INFO("Slavery Sync Server sync flow info: [end] \n");
}

void CSyncServer::OnReqQryFileGeneralOperTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryFileGeneralOperField	qryfield;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)
	{
		return;
	}

	if (qryfield.OperationType == -1)
	{
	}

	///初始化升级请求应答
	else if (qryfield.OperationType == 10 || qryfield.OperationType == 1)
	{
	}

	///请求变更
	else if (qryfield.OperationType == 3)
	{
		string	strFileName = g_FileServPath;
		strFileName += qryfield.FileName.getValue();
		replace_all_distinct1(strFileName, (string) "--", (string) "/");

		int iLen = strlen(strFileName.data());
		for (int i = 0; i < iLen; i++)
		{
			if (strFileName[i] == '/')
			{
				strFileName[i] = '\0';

				int iRet = access(strFileName.data(), 0);
				if (iRet != 0)
				{
					return;
				}

				strFileName[i] = '/';
			}
		}

		string	strName = qryfield.FileName.getValue();
		replace_all_distinct1(strName, (string) "--", (string) "/");
		if (access(strFileName.data(), 0) != 0)
		{
			return;
		}

		m_pkgSend.PreparePackage(
				FTD_TID_RtnFileGeneralOperTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);

		CFTDRtnFileGeneralOperField tfield;
		memset(&tfield, 0, sizeof(tfield));
		tfield.OperationType = 31;
		tfield.FileName = qryfield.FileName;

		CDateType NowDate;
		CTimeType NowTime;
		time_t	timep;
		time(&timep);

		struct tm tm_time;
		LocalTime(&timep, &tm_time);
		sprintf(
			(char *)(NowTime.getValue()),
			"%02d:%02d:%02d",
			tm_time.tm_hour,
			tm_time.tm_min,
			tm_time.tm_sec);
		sprintf(
			(char *)(NowDate.getValue()),
			"%d%02d%02d",
			tm_time.tm_year + 1900,
			tm_time.tm_mon + 1,
			tm_time.tm_mday);

		CXMLNode *pRootNode = pUpdateDoc->getRootNode();
		if (pRootNode)
		{
			CXMLNodeList *pNodeList = pRootNode->getNodeList();
			if (pNodeList)
			{
				CXMLNodeList::iterator	it = pNodeList->begin();
				for (; it != pNodeList->end(); it++)
				{
					///遍历变更历史，有就增加新结点及子版本号，并通知
					string	strName = (*it)->getName();
					if (strName == qryfield.FileName.getValue())
					{
						CXMLNodeList *pChildList = (*it)->getNodeList();
						if (pChildList)
						{
							int subVer = atoi(
									pChildList->back()->findProperty("subver"));
							CXMLNode *pXMLNode = new CXMLNode();
							pXMLNode->setName("item");
							pXMLNode->setNodeType(XMLTag);
							pXMLNode->addProperty(
									"date",
									(char *)(NowDate.getValue()));
							tfield.MonDate = NowDate;
							pXMLNode->addProperty(
									"time",
									(char *)(NowTime.getValue()));
							tfield.MonTime = NowTime;
							pXMLNode->addProperty(
									"username",
									(char *)(qryfield.UserName.getValue()));
							tfield.UserName = qryfield.UserName;

							char ch[10];
							sprintf(ch, "%d", 31);
							pXMLNode->addProperty("opertype", ch);

							char buffer[10];
							sprintf(buffer, "%d", subVer);
							pXMLNode->addProperty("subver", buffer);
							tfield.SubVersion = subVer;
							pChildList->push_back(pXMLNode);
							break;
						}
					}
				}

				if (it == pNodeList->end())
				{
					CXMLNode *pXMLNode = new CXMLNode();
					pXMLNode->setName((char *)(qryfield.FileName.getValue()));
					pXMLNode->setNodeType(XMLTag);

					//pNodeList->push_back(pXMLNode);
					CXMLNode *pChildNode = new CXMLNode();
					pChildNode->setName("item");
					pChildNode->setNodeType(XMLTag);
					pChildNode->addProperty(
							"date",
							(char *)(NowDate.getValue()));
					tfield.MonDate = NowDate;
					pChildNode->addProperty(
							"time",
							(char *)(NowTime.getValue()));
					tfield.MonTime = NowTime;
					pChildNode->addProperty(
							"username",
							(char *)(qryfield.UserName.getValue()));
					tfield.UserName = qryfield.UserName;

					char ch[10];
					sprintf(ch, "%d", 31);
					pChildNode->addProperty("opertype", ch);

					char buffer[10];
					sprintf(buffer, "%d", 0);
					pChildNode->addProperty("subver", buffer);
					tfield.SubVersion = 0;
					pXMLNode->addNode(pChildNode);

					pRootNode->addNode(pXMLNode);
				}
			}
		}

		string	strXMLName = g_FileXMLPath;
		strXMLName += "updatefile.xml";
		pUpdateDoc->write((char *)(strXMLName.data()));
	}

	///提交更新
	else if (qryfield.OperationType == 30)
	{
		string	strFileName = g_FileServPath;
		strFileName += qryfield.FileName.getValue();
		replace_all_distinct1(strFileName, (string) "--", (string) "/");

		char ch[10];
		sprintf(ch, "%d", qryfield.SubVersion.getValue());
		strFileName += "update/";
		strFileName += ch;

		///初建新版本文件
		if (qryfield.OperType == 1)
		{
			CreatMultiDir1((char *)(strFileName.data()));

			FILE *fp;
			fp = fopen(strFileName.data(), "wb");
			fwrite(qryfield.FileContent, 1, qryfield.Length, fp);
			fclose(fp);
		}
		else if (qryfield.OperType == 0 || qryfield.OperType == 10)
		{
			FILE *fp;
			fp = fopen(strFileName.data(), "ab");
			fwrite(qryfield.FileContent, 1, qryfield.Length, fp);
			fclose(fp);
		}

		///变更XML并通知
		if (qryfield.OperType == 10)
		{
			CXMLNode *pRootNode = pUpdateDoc->getRootNode();
			CXMLNodeList::iterator	itList = pRootNode->getNodeList()->begin();
			for (; itList != pRootNode->getNodeList()->end(); itList++)
			{
				if (strcmp(
						qryfield.FileName.getValue(),
					(const char *)((*itList)->getName())) == 0)
				//if(qryfield.FileName ==(*itList)->getName())
				{
					char ch[10];
					sprintf(ch, "%d", qryfield.SubVersion.getValue());
					(*itList)->getNodeList()->back()->setProperty(
							"opertype",
							"30");
					(*itList)->getNodeList()->back()->setProperty("subver", ch);

					string	strXMLName = g_FileXMLPath;
					strXMLName += "updatefile.xml";
					pUpdateDoc->write((char *)(strXMLName.data()));
				}
			}

			m_pkgSend.PreparePackage(
					FTD_TID_RtnFileGeneralOperTopic,
					FTDC_CHAIN_CONTINUE,
					FTD_VERSION);

			CFTDRtnFileGeneralOperField tfield;
			memset(&tfield, 0, sizeof(tfield));
			tfield.OperationType = 30;
			tfield.FileName = qryfield.FileName;
			tfield.SubVersion = qryfield.SubVersion;

			CDateType NowDate;
			CTimeType NowTime;
			time_t	timep;
			time(&timep);

			struct tm tm_time;
			LocalTime(&timep, &tm_time);
			sprintf(
				(char *)(NowTime.getValue()),
				"%02d:%02d:%02d",
				tm_time.tm_hour,
				tm_time.tm_min,
				tm_time.tm_sec);
			sprintf(
				(char *)(NowDate.getValue()),
				"%d%02d%02d",
				tm_time.tm_year + 1900,
				tm_time.tm_mon + 1,
				tm_time.tm_mday);
			tfield.MonDate = NowDate;
			tfield.MonTime = NowTime;
		}
	}

	///增加文件
	else if (qryfield.OperationType == 20)
	{
		string	strFileName = g_FileServPath;
		strFileName += qryfield.FileName.getValue();
		replace_all_distinct1(strFileName, (string) "--", (string) "/");
		if (qryfield.OperType == 1)
		{
			if (access(strFileName.data(), 0) == 0)
			{
			}
			else
			{
				strAddFileName = qryfield.FileName;
				CreatMultiDir1((char *)(strFileName.data()));

				FILE *fp;
				fp = fopen(strFileName.data(), "wb");
				fwrite(qryfield.FileContent, 1, qryfield.Length, fp);
				fclose(fp);
			}
		}
		else if (qryfield.OperType == 0 || qryfield.OperType == 10)
		{
			string	strTmp = qryfield.FileName.getValue();
			if (strAddFileName == strTmp)
			{
				FILE *fp;
				fp = fopen(strFileName.data(), "ab");
				fwrite(qryfield.FileContent, 1, qryfield.Length, fp);
				fclose(fp);

				if (qryfield.OperType == 10)
				{
					strAddFileName = "";

					m_pkgSend.PreparePackage(
							FTD_TID_RtnFileGeneralOperTopic,
							FTDC_CHAIN_CONTINUE,
							FTD_VERSION);

					CFTDRtnFileGeneralOperField tfield;
					memset(&tfield, 0, sizeof(tfield));
					tfield.OperationType = 20;
					tfield.FileName = qryfield.FileName;

					CDateType NowDate;
					CTimeType NowTime;
					time_t	timep;
					time(&timep);

					struct tm tm_time;
					LocalTime(&timep, &tm_time);
					sprintf(
						(char *)(NowTime.getValue()),
						"%02d:%02d:%02d",
						tm_time.tm_hour,
						tm_time.tm_min,
						tm_time.tm_sec);
					sprintf(
						(char *)(NowDate.getValue()),
						"%d%02d%02d",
						tm_time.tm_year + 1900,
						tm_time.tm_mon + 1,
						tm_time.tm_mday);

					CXMLNode *pRootNode = pUpdateDoc->getRootNode();
					CXMLNode *pXMLNode = new CXMLNode();
					pXMLNode->setName((char *)(qryfield.FileName.getValue()));
					pXMLNode->setNodeType(XMLTag);
					pRootNode->addNode(pXMLNode);

					//pNodeList->push_back(pXMLNode);
					CXMLNode *pChildNode = new CXMLNode();
					pChildNode->setName("item");
					pChildNode->setNodeType(XMLTag);
					pChildNode->addProperty(
							"date",
							(char *)(NowDate.getValue()));
					tfield.MonDate = NowDate;
					pChildNode->addProperty(
							"time",
							(char *)(NowTime.getValue()));
					tfield.MonTime = NowTime;
					pChildNode->addProperty(
							"username",
							(char *)(qryfield.UserName.getValue()));
					tfield.UserName = qryfield.UserName;

					char ch[10];
					sprintf(ch, "%d", 20);
					pChildNode->addProperty("opertype", ch);

					char buffer[10];
					sprintf(buffer, "%d", 0);
					pChildNode->addProperty("subver", buffer);
					tfield.SubVersion = 0;
					pXMLNode->addNode(pChildNode);

					string	strXMLName = g_FileXMLPath;
					strXMLName += "updatefile.xml";
					pUpdateDoc->write((char *)(strXMLName.data()));
				}
			}
		}
	}
}
