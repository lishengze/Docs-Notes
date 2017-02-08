/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CFrontServer.cpp
///@brief	定义了front连接处理的类
///@history
///20110112	周建军		创建该文件
#include "CFrontServer.h"
#include "databaseData.h"
#include "CSynconfig.h"
#include "GeneralOperation.h"
#include "SessionProxy.h"
#include <FTDDataWrapper.h>
#include <CommonFTDMsg.h>
#include <SQLAPI.h>
#include "FTDDataHelper.h"
#include "CTimePolicy.h"
#include "ConfigInfo.h"
#include <UFCopy.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <StringUtil.h>
#include <PrjCommon.h>
using namespace std;

extern CMemoryDB *pMemoryDB;

map<string, int> g_idMaker;
map<int, taskStatus> g_taskStatus;

extern char g_SysVersion[200];
extern CFileLogger	*g_recvPkgLogger;			// 数据包输出到文件
extern CBufferLogger *g_bufferLogger;
extern const char *g_FileServPath;
extern const char *g_FileXMLPath;

CXMLDoc *pUpdateDoc = NULL;

int	g_EventIDIndex=0;
int g_EventTimeIndex=-1;

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
int CreatMultiDir(char *pszDir)
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

string &replace_all_distinct(
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

CFrontServer::CFrontServer(CReactor *pReactor) :
	CSessionFactory(pReactor, 10)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	pUpdateDoc = new CXMLDoc();

	string	strXMLName = g_FileXMLPath;
	strXMLName += "updatefile.xml";
	if (access(strXMLName.data(), 0) != 0)
	{
		FILE *fp;
		fp = fopen(strXMLName.data(), "wb");
		fclose(fp);

		pUpdateDoc->read((char *)(strXMLName.data()));

		CXMLNode *pXMLRootNode = new CXMLNode();
		pUpdateDoc->setVersion("1.0");
		pUpdateDoc->setEncoding("GB2312");
		pXMLRootNode->setNodeType(XMLTag);
		pXMLRootNode->setName("UpdateFile");
		pUpdateDoc->setRootNode(pXMLRootNode);

		CXMLNode *pXMLNode = new CXMLNode();
		pXMLNode->setName("NodeList");
		pXMLNode->setNodeType(XMLTag);
		pXMLRootNode->addNode(pXMLNode);

		pUpdateDoc->write((char *)(strXMLName.data()));
	}
	else
	{
		pUpdateDoc->read((char *)(strXMLName.data()));
	}

	m_dbHandler.SetOperateMaster("CFrontServer", m_pReactor);
}

CFrontServer::~CFrontServer(void)
{
}

bool CFrontServer::Init(void)
{
	LOG_INFO("CFrontServer connect DB:\t");
	m_dbHandler.Open(
			ConfigInfo::Instance().DBIp(),
			ConfigInfo::Instance().DBPort(),
			ConfigInfo::Instance().DBName(),
			ConfigInfo::Instance().DBUser(),
			ConfigInfo::Instance().DBPwd());

	m_nDeviceTaskPrimID = 0;
	return true;
}

void CFrontServer::NotifyAllSession(CFTDCPackage *pkg)
{
	assert(pkg);

	ScopeLock<CMutex> lock(m_lock);

	list<CFTDCSession *>::iterator	it;
	for (it = m_sessions.begin(); it != m_sessions.end(); it++)
	{
		(*it)->SendRequestPackage(pkg);
		pkg->Pop(FTDCHLEN);
	}

	LogPkg(pkg, g_bufferLogger, g_traceLog);
}

CSession *CFrontServer::CreateSession(CChannel *pChannel, DWORD dwMark)
{
	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	pSession->RegisterPackageHandler(this);

	/// Added by Henchi, 20120309
	pSession->SetCompressMethod(CRPCM_ZERO);	//设置压缩算法
	return pSession;
}

void CFrontServer::OnSessionConnected(CSession *pSession)
{
	CSessionFactory::OnSessionConnected(pSession);

	LOG_INFO(
		"%s CFrontServer::OnSessionConnected: %0x Connected, CommonName [%s] RemoteName [%s] ==\n",
		CurrentTime(),
		(CFTDCSession *)pSession,
		pSession->GetChannel()->GetRemoteCommonName(),
		pSession->GetChannel()->GetRemoteName());

	ScopeLock<CMutex> lock(m_lock);
	AddSession((CFTDCSession *)pSession);
}

void CFrontServer::OnSessionDisconnected(CSession *pSession, int nReason)	// 子类重载处理连接断开事件
{
	CSessionFactory::OnSessionDisconnected(pSession, nReason);	// 子类调用父类处理连接断开事件
	LOG_INFO(
		"%s CFrontServer::OnSessionDisconnected: %0x Connected, CommonName [%s] RemoteName [%s] ==\n",
		CurrentTime(),
		(CFTDCSession *)pSession,
		pSession->GetChannel()->GetRemoteCommonName(),
		pSession->GetChannel()->GetRemoteName());

	ScopeLock<CMutex> lock(m_lock);
	DeleteSession((CFTDCSession *)pSession);
}

int CFrontServer::HandlePackage(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PACKAGE_OUTPUT
	LogPkg(pFTDCPackage, g_bufferLogger, g_recvPkgLogger);
#endif
	switch (pFTDCPackage->GetTID())
	{
		case FTD_TID_ReqUserLogin:
			OnReqUserLogin(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryGeneralOperateTopic:
			OnReqQryGeneralOperateTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetTimePolicyTopic:
			OnReqQryNetTimePolicyTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetDeviceChgTopic:
			OnReqQryNetDeviceChgTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetDeviceDetectTopic:
			OnReqQryNetDeviceDetectTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetDeviceRequestTopic:
			OnReqQryNetDeviceRequestTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetInterfaceTopic:
			OnReqQryNetInterfaceTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetModuleTopic:
			OnReqQryNetModuleTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetDeviceLinkedTopic:
			OnReqQryNetDeviceLinkedTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetGatherTaskTopic:
			OnReqQryNetGatherTaskTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetMonitorDeviceGroupTopic:
			OnReqQryNetMonitorDeviceGroupTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetMonitorTaskInfoTopic:
			OnReqQryNetMonitorTaskInfoTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqSysServerExitTopic:
			OnSysServerExitTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetMonitorTaskStatusResultTopic:
			OnReqQryNetMonitorTaskStatusResultTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetMonitorAttrScopeTopic:
			OnReqQryNetMonitorAttrScopeTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryFileGeneralOperTopic:
			OnReqQryFileGeneralOperTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQrySysUserLoginTopic:
			OnReqQrySysUserLoginTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryGetFileTopic:
			OnReqQryGetFileTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetBaseLineTopic:
			OnReqQryNetBaseLineTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetMonitorDeviceTaskTopic:
			OnReqQryNetMonitorDeviceTaskTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryEventDescriptionTopic:
			OnReqQryEventDescriptionTopic(pFTDCPackage, pSession);
			break;
		default:
			break;
	}

	return 0;
}

void CFrontServer::OnReqQryGetFileTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryGetFileField	qryfield;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)
	{
		return;
	}

	string	strFile = g_FileXMLPath;
	strFile += qryfield.FileName.getValue();

	int offset = qryfield.Offset;
	long fsize = 0;
	struct_stat s_buf;
	if (STAT(strFile.data(), &s_buf) >= 0)
	{
		fsize = s_buf.st_size;
	}

	m_pkgSend.PreparePackage(
			FTD_TID_RspQryGetFileTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());

	CFTDRspQryGetFileField	tfield;
	strcpy((char *)(tfield.FileName.getValue()), "");
	tfield.Length.setValue(fsize);
	FTDC_ADD_FIELD(&m_pkgSend, &tfield);
	pSession->SendRequestPackage(&m_pkgSend);

	FILE *pf = fopen(strFile.data(), "rb");
	if (pf)
	{
		fseek(pf, offset, SEEK_SET);
		while (true)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryGetFileTopic,
					FTDC_CHAIN_CONTINUE,
					FTD_VERSION);
			m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());

			CFTDRspQryGetFileField	tfield;
			int len = fread(
					(void *)(tfield.Comment.getValue()),
					1,
					sizeof(tfield.Comment) - 1,
					pf);
			if (SEEK_END == ftell(pf) || len <= 0)
			{
				m_pkgSend.SetChain(FTDC_CHAIN_LAST);
			}

			tfield.Length.setValue(len);
			tfield.Offset.setValue(offset);
			offset += len;
			FTDC_ADD_FIELD(&m_pkgSend, &tfield);
			pSession->SendRequestPackage(&m_pkgSend);
			if (SEEK_END == ftell(pf) || len <= 0)
			{
				break;
			}
		}

		fclose(pf);
	}
}

void CFrontServer::OnReqQrySysUserLoginTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQrySysUserLoginField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)
	{
		return;
	}

	string	str = qryfield.VersionID.getValue();
	string	strVer = g_SysVersion;
	if (str < strVer)
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RspQrySysUserLoginTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());

		CFTDRspQrySysUserLoginField tfield;
		memset(&tfield, 0, sizeof(tfield));
		tfield.VersionFlag = -1;
		tfield.UserID = qryfield.UserID;
		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		pSession->SendRequestPackage(&m_pkgSend);
		return;
	}
	else
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RspQrySysUserLoginTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());

		CFTDRspQrySysUserLoginField tfield;
		memset(&tfield, 0, sizeof(tfield));
		tfield.UserID = qryfield.UserID;
		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		pSession->SendRequestPackage(&m_pkgSend);
		return;
	}
}

void CFrontServer::OnReqUserLogin(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqUserLoginField fieldLogin;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldLogin);

	LOG_INFO(
		"CFrontServer::OnReqUserLogin:user=%s password=%s \n",
		(const char *)fieldLogin.UserID,
		(const char *)fieldLogin.Password);

	CCommonFTDRsp::Instance()->SendSuccRsp(
			pSession,
			&m_pkgSend,
			pFTDCPackage,
			FTD_TID_RspUserLogin);
}

void CFrontServer::OnReqQryGeneralOperateTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryGeneralOperateField reqField;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &reqField) <= 0)
	{
		return;
	}

	General_Oper_Data operData;
	operData.reqPkg = pFTDCPackage;
	operData.rspPkg = &m_pkgSend;
	operData.frontSession = pSession;
	operData.frontServer = this;
	operData.dbOper = &m_dbHandler;

	DoGeneralOperation(reqField, &operData);
}

void CFrontServer::OnReqQryNetTimePolicyTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryNetTimePolicyField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)
	{
		return;
	}

	if (qryfield.OperationType == OT_QUERY)
	{
		ITERATE_MEMORYDB_BYALL_BEGIN(NetTimePolicy)
		{
			SEND_QRYRSP_BY_MEMORYDB_RECORD(
				NetTimePolicy,
				pSession,
				pFTDCPackage,
				&m_pkgSend,
				pField,
				qryfield.OperationType);
		}

		ITERATE_MEMORYDB_BYALL_END(NetTimePolicy) CCommonFTDRsp::Instance()
			->SendSuccRsp(
				pSession,
				&m_pkgSend,
				pFTDCPackage,
				FTD_TID_RspQryNetTimePolicyTopic);

		return;
	}

	bool dbResult = false;

	if (qryfield.OperationType == OT_ADD)
	{
		qryfield.ID = g_idMaker["SysNetTimePolicy"]++;

		INSERT_OBJ_TO_DB(NetTimePolicy, qryfield, m_dbHandler, dbResult);
		if (dbResult)
		{
			INSERT_RECORD_INTO_MEMORYDB(NetTimePolicy, qryfield);
		}
	}
	else if (qryfield.OperationType == OT_DELETE)
	{
		bool hasRecord;
		FIND_RECORD_BYKEY_FROM_MEMORYDB(
			NetTimePolicy,
			qryfield,
			ID,
			hasRecord,
			record);
		if (hasRecord)
		{
			DELETE_OBJ_FROM_DB(
				NetTimePolicy,
				qryfield,
				"ID",
				m_dbHandler,
				dbResult);
			if (dbResult)
			{
				DELETE_RECORD_BYKEY_FROM_MEMORYDB(NetTimePolicy, record);
			}
		}
	}
	else if (qryfield.OperationType == OT_UPDATE)
	{
		bool hasRecord;
		FIND_RECORD_BYKEY_FROM_MEMORYDB(
			NetTimePolicy,
			qryfield,
			ID,
			hasRecord,
			record);
		if (hasRecord)
		{
			UPDATE_OBJ_TO_DB(
				NetTimePolicy,
				qryfield,
				"ID",
				m_dbHandler,
				dbResult);
			if (dbResult)
			{
				UPDATAE_RECORD_FROM_MEMORYDB(NetTimePolicy, record, qryfield);
			}
		}
	}
	else
	{
		return;
	}

	// dbResult为真，表明操作数据成功，反之为false
	if (dbResult)
	{
		CCommonFTDRsp::Instance()->SendSuccRsp(
				pSession,
				&m_pkgSend,
				pFTDCPackage,
				FTD_TID_RspQryNetTimePolicyTopic);

		BUILD_LAST_PKG_BY_FIELD(
			RTN,
			NetTimePolicy,
			pFTDCPackage,
			&m_pkgSend,
			qryfield);
		SessionProxy::Instance().NotifySnmp(&m_pkgSend);
		SessionProxy::Instance().NotifySync(&m_pkgSend);
		NotifyAllSession(&m_pkgSend);
	}
	else
	{
		CCommonFTDRsp::Instance()->SendLastErroRsp(
				pSession,
				&m_pkgSend,
				pFTDCPackage,
				FTD_TID_RspQryNetTimePolicyTopic);
	}
}

// Need to refactor
void CFrontServer::OnReqQryNetDeviceChgTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryNetDeviceChgField qryfield;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)
	{
		return;
	}

	bool dbResult = false;

	CWriteableSysNetDevice	mdbfield;
	{
		CSysNetDevice *pfield = pMemoryDB->m_SysNetDeviceFactory->findByOne(
				qryfield.DeviceID);
		if (!pfield)
		{
			return;
		}

		/*string str =pfield->ObjectID.getValue();

        string tmp =qryfield.NewObjectID.getValue();
        tmp +=".";		

		if(pfield->FuctionArea =="")
		{
			str.insert(str.find("." , str.find(".") +1) +1, tmp);
		}
		else
		{
			int index =str.find("." ,str.find(".") +1);
			int index1 =str.find("." ,index +1);
			str.replace(index +1 ,index1 -index ,tmp);
		}*/
		CopySysNetDeviceEntity(&mdbfield, pfield);
		mdbfield.FuctionArea = qryfield.NewObjectID;

		UPDATE_OBJ_TO_DB(NetDevice, mdbfield, "ID", m_dbHandler, dbResult);
		if (dbResult)
		{
			pMemoryDB->m_SysNetDeviceFactory->update(pfield, &mdbfield);
		}
	}

	///转发snmpmanager
	/*BUILD_LAST_PKG_BY_FIELD(RTN, NetDeviceChg, pFTDCPackage, &m_pkgSend, qryfield);
    SessionProxy::Instance().NotifySnmp(&m_pkgSend);*/
	//SessionProxy::Instance().NotifySync(&m_pkgSend);
	// TODO There is no hanlder for NetDeviceChg of SyncServer
	
		///同步到所有前置
	{
		m_pkgSend.PrepareResponse(
				pFTDCPackage,
				FTD_TID_RtnNetDeviceChgTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);

		CFTDRtnNetDeviceChgField tfield;
		CopySysNetDeviceChgEntity(&tfield, &qryfield);
		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		NotifyAllSession(&m_pkgSend);
	}

	/*///处理gathertask
	{
		string strOld =qryfield.OldObjectID.getValue();
		string strNew =qryfield.NewObjectID.getValue();

		CSysNetGatherTask *sfield =pMemoryDB->m_SysNetGatherTaskFactory->startFindByAll();
		while(sfield)
		{
			string str =sfield->ObjectID.getValue();
			CWriteableSysNetGatherTask mdbfield;
			if(str.find(strOld) !=string::npos)
			{
				CopySysNetGatherTaskEntity(&mdbfield,sfield);
				str.replace(str.find(strOld) ,strOld.length() ,strNew);
				mdbfield.ObjectID =str.data();
				pMemoryDB->m_SysNetGatherTaskFactory->remove(sfield);
				pMemoryDB->m_SysNetGatherTaskFactory->add(&mdbfield);

				UPDATE_OBJ_TO_DB(NetGatherTask, mdbfield, "ID", m_dbHandler, dbResult); 

				m_pkgSend.PrepareResponse(pFTDCPackage, FTD_TID_RtnNetGatherTaskTopic,FTDC_CHAIN_CONTINUE, FTD_VERSION);
				CFTDRtnNetGatherTaskField tfield;
				CopySysNetGatherTaskEntity(&tfield ,&mdbfield);
				tfield.OperationType =4;
				FTDC_ADD_FIELD(&m_pkgSend, &tfield);
				SessionProxy::Instance().NotifySnmp(&m_pkgSend);
                SessionProxy::Instance().NotifySync(&m_pkgSend);  
			}
			sfield =pMemoryDB->m_SysNetGatherTaskFactory->findNextByAll();
		}
		pMemoryDB->m_SysNetGatherTaskFactory->endFindByAll();
	}

	///处理interface内存表   TODO nofity sync
    ITERATE_MEMORYDB_BYKEY_BEGIN(NetInterface, DeviceID, qryfield, DeviceID)
	{
		CWriteableSysNetInterface mdbfield;
		CopySysNetInterfaceEntity(&mdbfield,pField);
		mdbfield.DeviceObjectID =qryfield.NewObjectID;
		pMemoryDB->m_SysNetInterfaceFactory->remove(pField);
		pMemoryDB->m_SysNetInterfaceFactory->add(&mdbfield);

        UPDATE_OBJ_TO_DB(NetInterface, mdbfield, "ID", m_dbHandler, dbResult); 
	}
	ITERATE_MEMORYDB_BYKEY_END(NetInterface, DeviceID)
	
	///处理模块内存表
	ITERATE_MEMORYDB_BYKEY_BEGIN(NetModule, DeviceID, qryfield, DeviceID)
	{
		CWriteableSysNetModule mdbfield;
		CopySysNetModuleEntity(&mdbfield,pField);
		mdbfield.DeviceObjectID =qryfield.NewObjectID;
		pMemoryDB->m_SysNetModuleFactory->remove(pField);
		pMemoryDB->m_SysNetModuleFactory->add(&mdbfield);

		UPDATE_OBJ_TO_DB(NetModule, mdbfield, "ID", m_dbHandler, dbResult); 
	}
	ITERATE_MEMORYDB_BYKEY_END(NetModule, DeviceID)

	///处理DeviceLinked内存表
    ITERATE_MEMORYDB_BYKEY_BEGIN(NetDeviceLinked, NetObjectID, qryfield, OldObjectID)
	{
		CWriteableSysNetDeviceLinked mdbfield;
		CopySysNetDeviceLinkedEntity(&mdbfield,pField);
		mdbfield.NetObjectID =qryfield.NewObjectID;
		pMemoryDB->m_SysNetDeviceLinkedFactory->remove(pField);
		pMemoryDB->m_SysNetDeviceLinkedFactory->add(&mdbfield);

        UPDATE_OBJ_TO_DB(NetDeviceLinked, mdbfield, "ID", m_dbHandler, dbResult); 
	}
	ITERATE_MEMORYDB_BYKEY_END(NetDeviceLinked, NetObjectID)

    ITERATE_MEMORYDB_BYKEY_BEGIN(NetDeviceLinked, LinkNetObjectID, qryfield, OldObjectID)
    {
        CWriteableSysNetDeviceLinked mdbfield;
        CopySysNetDeviceLinkedEntity(&mdbfield,pField);
        mdbfield.LinkNetObjectID =qryfield.NewObjectID;
        pMemoryDB->m_SysNetDeviceLinkedFactory->remove(pField);
        pMemoryDB->m_SysNetDeviceLinkedFactory->add(&mdbfield);

        UPDATE_OBJ_TO_DB_WITH_COMPOBJ(NetDeviceLinked, mdbfield, "NetObjectID",
            NetDeviceChg, qryfield, "OldObjectID", m_dbHandler, dbResult);
    }
    ITERATE_MEMORYDB_BYKEY_END(NetDeviceLinked, LinkNetObjectID)*/
}

void CFrontServer::OnReqQryNetDeviceDetectTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryNetDeviceDetectField	qryfield;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)
	{
		return;
	}

	// 目前CFTDReqQryNetDeviceDetectField中SysNetAreaID是一个dummy值，
	// 因此首先要根据SysNetSubAreaID在SysSubArea中查找SysNetAreaID，
	// 再根据SysNetAreaID在SysNetArea中查找EName
	CSysNetSubArea	*subNet = pMemoryDB->m_SysNetSubAreaFactory->findByOne(
			qryfield.SysNetSubAreaID);
	if (!subNet)
	{
		return;
	}

	CSysNetArea *pField = pMemoryDB->m_SysNetAreaFactory->findByOne(
			subNet->SysNetAreaID);
	if (!pField)
	{
		return;
	}

	char dataCenter = CDeployConfig::TransCenterFlag(pField->EName);
	if (dataCenter == DC_UnKnow)
	{
		return;
	}

	BUILD_LAST_PKG_BY_FIELD(
		REQ,
		NetDeviceDetect,
		pFTDCPackage,
		&m_pkgSend,
		qryfield);
	SessionProxy::Instance().RequestSnmp(
			pFTDCPackage,
			pSession,
			&m_pkgSend,
			dataCenter);
}

void CFrontServer::OnReqQryNetDeviceRequestTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryNetDeviceRequestField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)
	{
		return;
	}

	///按ipcode查询
	if (qryfield.IPDECODE > 0)
	{
		ITERATE_MEMORYDB_BYKEY_BEGIN(NetDevice, IPDECODE, qryfield, IPDECODE)
		{
			SEND_QRYRSP_BY_MEMORYDB_RECORD(
				NetDevice,
				pSession,
				pFTDCPackage,
				&m_pkgSend,
				pField,
				qryfield.OperationType);
		}

		ITERATE_MEMORYDB_BYKEY_END(NetDevice, IPDECODE)
	}

	///按subareaID和职能区域查询
	else if (qryfield.SysNetSubAreaID > 0)
	{
		ITERATE_MEMORYDB_BYKEY_BEGIN(
			NetDevice,
			SubAreaID,
			qryfield,
			SysNetSubAreaID)
		{
			if (pField->FuctionArea == qryfield.FuctionArea
			||	qryfield.FuctionArea == "")
			{
				SEND_QRYRSP_BY_MEMORYDB_RECORD(
					NetDevice,
					pSession,
					pFTDCPackage,
					&m_pkgSend,
					pField,
					qryfield.OperationType);
			}
		}

		ITERATE_MEMORYDB_BYKEY_END(NetDevice, SubAreaID)
	}

	///都为空，发全部
	else
	{
		ITERATE_MEMORYDB_BYALL_BEGIN(NetDevice)
		{
			SEND_QRYRSP_BY_MEMORYDB_RECORD(
				NetDevice,
				pSession,
				pFTDCPackage,
				&m_pkgSend,
				pField,
				qryfield.OperationType);
		}

		ITERATE_MEMORYDB_BYALL_END(NetDevice)
	}

	CCommonFTDRsp::Instance()->SendSuccRsp(
			pSession,
			&m_pkgSend,
			pFTDCPackage,
			FTD_TID_RspQryNetDeviceTopic);
}

void CFrontServer::OnReqQryNetInterfaceTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryNetInterfaceField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)
	{
		return;
	}

	CFTDRspQryNetInterfaceField field;

	if (qryfield.DeviceID > 0)
	{
		ITERATE_MEMORYDB_BYKEY_BEGIN(NetInterface, DeviceID, qryfield, DeviceID)
		{
			SEND_QRYRSP_BY_MEMORYDB_RECORD(
				NetInterface,
				pSession,
				pFTDCPackage,
				&m_pkgSend,
				pField,
				qryfield.OperationType);
		}

		ITERATE_MEMORYDB_BYKEY_END(NetInterface, DeviceID)
	}
	else
	{
		ITERATE_MEMORYDB_BYALL_BEGIN(NetInterface)
		{
			SEND_QRYRSP_BY_MEMORYDB_RECORD(
				NetInterface,
				pSession,
				pFTDCPackage,
				&m_pkgSend,
				pField,
				qryfield.OperationType);
		}

		ITERATE_MEMORYDB_BYALL_END(NetInterface)
	}

	CCommonFTDRsp::Instance()->SendSuccRsp(
			pSession,
			&m_pkgSend,
			pFTDCPackage,
			FTD_TID_RspQryNetInterfaceTopic);
}

void CFrontServer::OnReqQryNetModuleTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryNetModuleField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)
	{
		return;
	}

	CFTDRspQryNetModuleField field;

	if (qryfield.DeviceID > 0)
	{
		ITERATE_MEMORYDB_BYKEY_BEGIN(NetModule, DeviceID, qryfield, DeviceID)
		{
			SEND_QRYRSP_BY_MEMORYDB_RECORD(
				NetModule,
				pSession,
				pFTDCPackage,
				&m_pkgSend,
				pField,
				qryfield.OperationType);
		}

		ITERATE_MEMORYDB_BYKEY_END(NetModule, DeviceID)
	}
	else
	{
		ITERATE_MEMORYDB_BYALL_BEGIN(NetModule)
		{
			SEND_QRYRSP_BY_MEMORYDB_RECORD(
				NetModule,
				pSession,
				pFTDCPackage,
				&m_pkgSend,
				pField,
				qryfield.OperationType);
		}

		ITERATE_MEMORYDB_BYALL_END(NetModule)
	}

	CCommonFTDRsp::Instance()->SendSuccRsp(
			pSession,
			&m_pkgSend,
			pFTDCPackage,
			FTD_TID_RspQryNetModuleTopic);
}

void CFrontServer::OnReqQryNetDeviceLinkedTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryNetDeviceLinkedField	qryfield;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)
	{
		return;
	}

	if (qryfield.ObjectID != "")
	{
		ITERATE_MEMORYDB_BYKEY_BEGIN(
			NetDeviceLinked,
			NetObjectID,
			qryfield,
			ObjectID)
		{
			SEND_QRYRSP_BY_MEMORYDB_RECORD(
				NetDeviceLinked,
				pSession,
				pFTDCPackage,
				&m_pkgSend,
				pField,
				qryfield.OperationType);
		}

		ITERATE_MEMORYDB_BYKEY_END(
			NetDeviceLinked,
			NetObjectID) ITERATE_MEMORYDB_BYKEY_BEGIN(
				NetDeviceLinked,
				LinkNetObjectID,
				qryfield,
				ObjectID)
		{
			SEND_QRYRSP_BY_MEMORYDB_RECORD(
				NetDeviceLinked,
				pSession,
				pFTDCPackage,
				&m_pkgSend,
				pField,
				qryfield.OperationType);
		}

		ITERATE_MEMORYDB_BYKEY_END(NetDeviceLinked, LinkNetObjectID)
	}
	else
	{
		///按ipcode查
		if (qryfield.IPDECODE > 0)
		{
			ITERATE_MEMORYDB_BYKEY_BEGIN(
				NetDevice,
				IPDECODE,
				qryfield,
				IPDECODE)
			{
				CSysNetDevice *pDevicefield = pField;

				ITERATE_MEMORYDB_BYKEY_BEGIN(
					NetDeviceLinked,
					NetObjectID,
					*pDevicefield,
					ObjectID)
				{
					SEND_QRYRSP_BY_MEMORYDB_RECORD(
						NetDeviceLinked,
						pSession,
						pFTDCPackage,
						&m_pkgSend,
						pField,
						qryfield.OperationType);
				}

				ITERATE_MEMORYDB_BYKEY_END(
					NetDeviceLinked,
					NetObjectID) ITERATE_MEMORYDB_BYKEY_BEGIN(
						NetDeviceLinked,
						LinkNetObjectID,
						*pDevicefield,
						ObjectID)
				{
					SEND_QRYRSP_BY_MEMORYDB_RECORD(
						NetDeviceLinked,
						pSession,
						pFTDCPackage,
						&m_pkgSend,
						pField,
						qryfield.OperationType);
				}

				ITERATE_MEMORYDB_BYKEY_END(NetDeviceLinked, LinkNetObjectID)
			}

			ITERATE_MEMORYDB_BYKEY_END(NetDevice, IPDECODE)
		}

		///按subarea查询
		else if (qryfield.SysNetSubAreaID > 0)
		{
			ITERATE_MEMORYDB_BYKEY_BEGIN(
				NetDevice,
				SubAreaID,
				qryfield,
				SysNetSubAreaID)
			{
				CSysNetDevice *pDevicefield = pField;

				if (pDevicefield->FuctionArea == qryfield.FuctionArea)
				{
					ITERATE_MEMORYDB_BYKEY_BEGIN(
						NetDeviceLinked,
						NetObjectID,
						*pDevicefield,
						ObjectID)
					{
						SEND_QRYRSP_BY_MEMORYDB_RECORD(
							NetDeviceLinked,
							pSession,
							pFTDCPackage,
							&m_pkgSend,
							pField,
							qryfield.OperationType);
					}

					ITERATE_MEMORYDB_BYKEY_END(
						NetDeviceLinked,
						NetObjectID) ITERATE_MEMORYDB_BYKEY_BEGIN(
							NetDeviceLinked,
							LinkNetObjectID,
							*pDevicefield,
							ObjectID)
					{
						SEND_QRYRSP_BY_MEMORYDB_RECORD(
							NetDeviceLinked,
							pSession,
							pFTDCPackage,
							&m_pkgSend,
							pField,
							qryfield.OperationType);
					}

					ITERATE_MEMORYDB_BYKEY_END(NetDeviceLinked, LinkNetObjectID)
				}
			}

			ITERATE_MEMORYDB_BYKEY_END(NetDevice, SubAreaID)
		}

		///都为空查全部
		else
		{
			ITERATE_MEMORYDB_BYALL_BEGIN(NetDeviceLinked)
			{
				SEND_QRYRSP_BY_MEMORYDB_RECORD(
					NetDeviceLinked,
					pSession,
					pFTDCPackage,
					&m_pkgSend,
					pField,
					qryfield.OperationType);
			}

			ITERATE_MEMORYDB_BYALL_END(NetDeviceLinked)
		}
	}

	CCommonFTDRsp::Instance()->SendSuccRsp(
			pSession,
			&m_pkgSend,
			pFTDCPackage,
			FTD_TID_RspQryNetDeviceLinkedTopic);
}

void CFrontServer::OnReqQryNetGatherTaskTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryNetGatherTaskField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)
	{
		return;
	}

	if (qryfield.OperationType == OT_QUERY)
	{
		if (qryfield.ID > 0)
		{
			CSysNetGatherTask *pField = pMemoryDB->m_SysNetGatherTaskFactory->
				findByOne(qryfield.ID);
			if (pField)
			{
				SEND_QRYRSP_BY_MEMORYDB_RECORD(
					NetGatherTask,
					pSession,
					pFTDCPackage,
					&m_pkgSend,
					pField,
					qryfield.OperationType);
			}
		}
		else if (qryfield.ObjectID != "")
		{
			ITERATE_MEMORYDB_BYKEY_BEGIN(
				NetGatherTask,
				NetObjectID,
				qryfield,
				ObjectID)
			{
				SEND_QRYRSP_BY_MEMORYDB_RECORD(
					NetGatherTask,
					pSession,
					pFTDCPackage,
					&m_pkgSend,
					pField,
					qryfield.OperationType);
			}

			ITERATE_MEMORYDB_BYKEY_END(NetGatherTask, NetObjectID)
		}
		else
		{
			ITERATE_MEMORYDB_BYALL_BEGIN(NetGatherTask)
			{
				SEND_QRYRSP_BY_MEMORYDB_RECORD(
					NetGatherTask,
					pSession,
					pFTDCPackage,
					&m_pkgSend,
					pField,
					qryfield.OperationType);
			}

			ITERATE_MEMORYDB_BYALL_END(NetGatherTask)
		}

		CCommonFTDRsp::Instance()->SendSuccRsp(
				pSession,
				&m_pkgSend,
				pFTDCPackage,
				FTD_TID_RspQryNetGatherTaskTopic);

		return;
	}

	bool dbResult = false;

	if (qryfield.OperationType == OT_ADD)
	{
		qryfield.ID = g_idMaker["SysNetGatherTask"]++;

		INSERT_OBJ_TO_DB(NetGatherTask, qryfield, m_dbHandler, dbResult);
		if (dbResult)
		{
			INSERT_RECORD_INTO_MEMORYDB(NetGatherTask, qryfield);
			SEND_RSP_BY_MEMORYDB_RECORD(
				NetGatherTask,
				pSession,
				pFTDCPackage,
				&m_pkgSend,
				&qryfield,
				qryfield.OperationType);
		}
	}
	else if (qryfield.OperationType == OT_DELETE)
	{
		if (qryfield.ID > 0)
		{
			bool hasRecord;
			FIND_RECORD_BYKEY_FROM_MEMORYDB(
				NetGatherTask,
				qryfield,
				ID,
				hasRecord,
				record);
			if (hasRecord)
			{
				DELETE_OBJ_FROM_DB(
					NetGatherTask,
					qryfield,
					"ID",
					m_dbHandler,
					dbResult);
				if (dbResult)
				{
					DELETE_RECORD_BYKEY_FROM_MEMORYDB(NetGatherTask, record);
				}
			}
		}
		else if (qryfield.ID == 0)
		{
			// 由ObjectID与AttrType共同确定一条记录
			ITERATE_MEMORYDB_BYKEY_BEGIN(
				NetGatherTask,
				NetObjectID,
				qryfield,
				ObjectID)
			{
				if (pField->AttrType == qryfield.AttrType)
				{
					qryfield.ID = pField->ID;
					DELETE_OBJ_FROM_DB(
						NetGatherTask,
						qryfield,
						"ID",
						m_dbHandler,
						dbResult);
					if (dbResult)
					{
						DELETE_RECORD_BYKEY_FROM_MEMORYDB(
							NetGatherTask,
							pField);
					}
				}
			}

			ITERATE_MEMORYDB_BYKEY_END(NetGatherTask, NetObjectID)
		}
		else
		{
			dbResult = m_dbHandler.DeleteRecord(FTD_TABLE(NetGatherTask));
			if (dbResult)
			{
				pMemoryDB->m_SysNetGatherTaskFactory->clearAll();
			}
		}
	}
	else if (qryfield.OperationType == OT_UPDATE)
	{
		if (qryfield.ID > 0)
		{
			bool hasRecord;
			FIND_RECORD_BYKEY_FROM_MEMORYDB(
				NetGatherTask,
				qryfield,
				ID,
				hasRecord,
				record);
			if (hasRecord)
			{
				UPDATE_OBJ_TO_DB(
					NetGatherTask,
					qryfield,
					"ID",
					m_dbHandler,
					dbResult);
				if (dbResult)
				{
					UPDATAE_RECORD_FROM_MEMORYDB(
						NetGatherTask,
						record,
						qryfield);
				}
			}
		}
		else if (qryfield.ID == 0)
		{
			// 由ObjectID与AttrType共同确定一条记录
			ITERATE_MEMORYDB_BYKEY_BEGIN(
				NetGatherTask,
				NetObjectID,
				qryfield,
				ObjectID)
			{
				if (pField->AttrType == qryfield.AttrType)
				{
					qryfield.ID = pField->ID;
					UPDATE_OBJ_TO_DB(
						NetGatherTask,
						qryfield,
						"ID",
						m_dbHandler,
						dbResult);
					if (dbResult)
					{
						UPDATAE_RECORD_FROM_MEMORYDB(
							NetGatherTask,
							pField,
							qryfield);
					}
				}
			}

			ITERATE_MEMORYDB_BYKEY_END(NetGatherTask, NetObjectID)
		}
	}

	if (dbResult)
	{
		CCommonFTDRsp::Instance()->SendSuccRsp(
				pSession,
				&m_pkgSend,
				pFTDCPackage,
				FTD_TID_RspQryNetGatherTaskTopic);

		BUILD_LAST_PKG_BY_FIELD(
			RTN,
			NetGatherTask,
			pFTDCPackage,
			&m_pkgSend,
			qryfield);
		SessionProxy::Instance().NotifySnmp(&m_pkgSend);
		SessionProxy::Instance().NotifySync(&m_pkgSend);
		NotifyAllSession(&m_pkgSend);
	}
	else
	{
		CCommonFTDRsp::Instance()->SendLastErroRsp(
				pSession,
				&m_pkgSend,
				pFTDCPackage,
				FTD_TID_RspQryNetGatherTaskTopic,
				"Handle DB Error!");
	}
}

typedef struct
{
	CFTDReqQryNetMonitorDeviceGroupField *reqField;
	CFTDCPackage *reqPkg;
	CFTDCPackage *rspPkg;
	CFTDCSession *session;
} SearchNetDevByGroup;

static void SearchNetDeviceByDeviceGrop(SACommand &records, void *data)
{
	assert(data);

	SearchNetDevByGroup *pdata = (SearchNetDevByGroup *)data;

	CFTDRspQryNetMonitorTaskObjectSetField	rsp;
	rsp.Device_ID = records.Field("ID").asLong();

	AddRspWithField<CFTDRspQryNetMonitorTaskObjectSetField>
		(
			pdata->rspPkg, &rsp, pdata->session, pdata->reqPkg,
				FTD_TID_RspQryNetMonitorTaskObjectSetTopic
		);
}

string searchIDFromSysNetDevice(string condition)
{
	string rtn = "select ID, ObjectID from t_SysNetDevice t";

	if (!condition.empty())
	{
		rtn += " where ";
		rtn += condition;
	}

	return rtn;
}

typedef struct
{
	int groupID;
	CFTDCPackage *reqPkg;
	CFTDCPackage *rspPkg;
} updateTaskObjectSet_T;

static void updateTaskObjectSet(SACommand &records, void *data)
{
	assert(data);

	updateTaskObjectSet_T *pData = (updateTaskObjectSet_T *)data;

	CWriteableSysNetMonitorTaskObjectSet mdbfield;

	mdbfield.DeviceGroup_ID = pData->groupID;
	mdbfield.Device_ID = records.Field("ID").asLong();
	mdbfield.DataCenter = GetCenterFromOID(
			(const char *)records.Field("ObjectID").asString());

	pMemoryDB->m_SysNetMonitorTaskObjectSetFactory->add(&mdbfield);

	// notify snmp
	FTD_RTN(NetMonitorTaskObjectSet) rtnField;
	COPY_FTD_ENTITY(NetMonitorTaskObjectSet, &rtnField, &mdbfield);
	rtnField.OperationType = OT_ADD;

	pData->rspPkg->PrepareResponse(
			pData->reqPkg,
			FTD_RTN_ID(NetMonitorTaskObjectSet),
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	FTDC_ADD_FIELD(pData->rspPkg, &rtnField);
	SessionProxy::Instance().NotifySnmp(pData->rspPkg);
}

void CFrontServer::OnReqQryNetMonitorDeviceGroupTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryNetMonitorDeviceGroupField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)
	{
		return;
	}

	switch (qryfield.OperationType)
	{
		case OT_QUERY:
			{
				if (qryfield.ID > 0)
				{
					// 客户请求按特定条件分组的设备，用内存数据库查询
					ITERATE_MEMORYDB_BYKEY_BEGIN(
						NetMonitorTaskObjectSet,
						DeviceGroup_ID,
						qryfield,
						ID)
					{
						SEND_QRYRSP_BY_MEMORYDB_RECORD(
							NetMonitorTaskObjectSet,
							pSession,
							pFTDCPackage,
							&m_pkgSend,
							pField,
							qryfield.OperationType);
					}

					ITERATE_MEMORYDB_BYKEY_END(
						NetMonitorTaskObjectSet,
						DeviceGroup_ID)
				}
				else
				{
					string conditionSql;

					// 客户端发起测试请求，进行数据库查询操作		
					if (!qryfield.Condition.isNull())
					{
						conditionSql = searchIDFromSysNetDevice(
								qryfield.Condition.getValue());
					}
					else
					{
						return;
					}

					SearchNetDevByGroup data;
					data.reqField = &qryfield;
					data.reqPkg = pFTDCPackage;
					data.rspPkg = &m_pkgSend;
					data.session = pSession;

					m_pkgSend.PrepareResponse(
							pFTDCPackage,
							FTD_TID_RspQryNetMonitorTaskObjectSetTopic,
							FTDC_CHAIN_CONTINUE,
							FTD_VERSION);
					m_dbHandler.SearchRecord(
							conditionSql,
							SearchNetDeviceByDeviceGrop,
							&data);
					LogPkg(&m_pkgSend, g_bufferLogger, g_traceLog);
					pSession->SendRequestPackage(&m_pkgSend);
				}

				CCommonFTDRsp::Instance()->SendSuccRsp(
						pSession,
						&m_pkgSend,
						pFTDCPackage,
						FTD_TID_RspQryNetMonitorTaskObjectSetTopic);
			}

			break;
		case OT_ADD:
			{
				qryfield.ID = g_idMaker["SysNetMonitorDeviceGroup"]++;

				bool result;
				INSERT_OBJ_TO_DB(
					NetMonitorDeviceGroup,
					qryfield,
					m_dbHandler,
					result);
				if (!result)
				{
					CCommonFTDRsp::Instance()->SendLastErroRsp(
							pSession,
							&m_pkgSend,
							pFTDCPackage,
							FTD_TID_RspQryNetMonitorDeviceGroupTopic,
							"Insert record failed");
					break;
				}

				CWriteableSysNetMonitorDeviceGroup memfield;
				CopySysNetMonitorDeviceGroupEntity(&memfield, &qryfield);
				pMemoryDB->m_SysNetMonitorDeviceGroupFactory->add(&memfield);

				SEND_RSP_BY_MEMORYDB_RECORD(
					NetMonitorDeviceGroup,
					pSession,
					pFTDCPackage,
					&m_pkgSend,
					&qryfield,
					OT_ADD);
				CCommonFTDRsp::Instance()->SendSuccRsp(
						pSession,
						&m_pkgSend,
						pFTDCPackage,
						FTD_TID_RspQryNetMonitorDeviceGroupTopic);

				// notify rtn NetMonitorDeviceGroup
				BUILD_LAST_PKG_BY_FIELD(
					RTN,
					NetMonitorDeviceGroup,
					pFTDCPackage,
					&m_pkgSend,
					qryfield);
				SessionProxy::Instance().NotifySnmp(&m_pkgSend);
				SessionProxy::Instance().NotifyEventCounter(&m_pkgSend);
				SessionProxy::Instance().NotifySync(&m_pkgSend);
				SessionProxy::Instance().NotifyFront(&m_pkgSend);

				// update taskObjectSet of MDB
				string conditionSql = searchIDFromSysNetDevice(
						qryfield.Condition.getValue());

				updateTaskObjectSet_T data;
				data.groupID = qryfield.ID;
				data.reqPkg = pFTDCPackage;
				data.rspPkg = &m_pkgSend;
				m_dbHandler.SearchRecord(conditionSql, updateTaskObjectSet, &data);
			}

			break;
		case OT_DELETE:
			{
				bool result;
				DELETE_OBJ_FROM_DB(
					NetMonitorDeviceGroup,
					qryfield,
					"ID",
					m_dbHandler,
					result);
				if (!result)
				{
					CCommonFTDRsp::Instance()->SendLastErroRsp(
							pSession,
							&m_pkgSend,
							pFTDCPackage,
							FTD_TID_RspQryNetMonitorDeviceGroupTopic,
							"Delete record failed");
					break;
				}

				CSysNetMonitorDeviceGroup *deletedOne = pMemoryDB->
					m_SysNetMonitorDeviceGroupFactory->findByOne(qryfield.ID);
				if (!deletedOne)
				{
					LOG_WARNING(
						"Delete a NetMonitorDeviceGroup record from DB, but can't find record in memory DB!\n");
					return;
				}

				pMemoryDB->m_SysNetMonitorDeviceGroupFactory->remove(deletedOne);

				SEND_RSP_BY_MEMORYDB_RECORD(
					NetMonitorDeviceGroup,
					pSession,
					pFTDCPackage,
					&m_pkgSend,
					&qryfield,
					OT_DELETE);
				CCommonFTDRsp::Instance()->SendSuccRsp(
						pSession,
						&m_pkgSend,
						pFTDCPackage,
						FTD_TID_RspQryNetMonitorDeviceGroupTopic);

				// notify rtn NetMonitorDeviceGroup
				BUILD_LAST_PKG_BY_FIELD(
					RTN,
					NetMonitorDeviceGroup,
					pFTDCPackage,
					&m_pkgSend,
					qryfield);
				SessionProxy::Instance().NotifySnmp(&m_pkgSend);
				SessionProxy::Instance().NotifyEventCounter(&m_pkgSend);
				SessionProxy::Instance().NotifySync(&m_pkgSend);
				SessionProxy::Instance().NotifyFront(&m_pkgSend);

				// delete from memory DB
				ITERATE_MEMORYDB_BYKEY_BEGIN(
					NetMonitorTaskObjectSet,
					DeviceGroup_ID,
					qryfield,
					ID)
				{
					pMemoryDB->m_SysNetMonitorTaskObjectSetFactory->remove(pField);

					// notify snmp
					FTD_RTN(NetMonitorTaskObjectSet) rtnField;
					COPY_FTD_ENTITY(NetMonitorTaskObjectSet, &rtnField, pField);
					rtnField.OperationType = OT_DELETE;

					m_pkgSend.PrepareResponse(
							pFTDCPackage,
							FTD_RTN_ID(NetMonitorTaskObjectSet),
							FTDC_CHAIN_LAST,
							FTD_VERSION);
					FTDC_ADD_FIELD(&m_pkgSend, &rtnField);
					SessionProxy::Instance().NotifySnmp(&m_pkgSend);
				}

				ITERATE_MEMORYDB_BYKEY_END(NetMonitorTaskObjectSet, DeviceGroup_ID)
			}

			break;
		case OT_UPDATE:
			{
				CSysNetMonitorDeviceGroup *pField = pMemoryDB->
					m_SysNetMonitorDeviceGroupFactory->findByOne(qryfield.ID);
				if (!pField)
				{
					LOG_WARNING(
						"Can't find SysNetMonitorDeviceGroup record(ID %d), So update failed!\n");
					return;
				}

				bool result;
				UPDATE_OBJ_TO_DB(
					NetMonitorDeviceGroup,
					qryfield,
					"ID",
					m_dbHandler,
					result);
				if (!result)
				{
					CCommonFTDRsp::Instance()->SendLastErroRsp(
							pSession,
							&m_pkgSend,
							pFTDCPackage,
							FTD_TID_RspQryNetMonitorDeviceGroupTopic,
							"Update record failed");
					break;
				}

				CFTDSysNetMonitorDeviceGroupField oldData;
				CopySysNetMonitorDeviceGroupEntity(&oldData, pField);

				// update memory DB
				CWriteableSysNetMonitorDeviceGroup memfield;
				CopySysNetMonitorDeviceGroupEntity(&memfield, &qryfield);
				pMemoryDB->m_SysNetMonitorDeviceGroupFactory->update(
						pField,
						&memfield);

				SEND_RSP_BY_MEMORYDB_RECORD(
					NetMonitorDeviceGroup,
					pSession,
					pFTDCPackage,
					&m_pkgSend,
					&qryfield,
					OT_UPDATE);
				CCommonFTDRsp::Instance()->SendSuccRsp(
						pSession,
						&m_pkgSend,
						pFTDCPackage,
						FTD_TID_RspQryNetMonitorDeviceGroupTopic);

				// notify rtn NetMonitorDeviceGroup
				BUILD_LAST_PKG_BY_FIELD(
					RTN,
					NetMonitorDeviceGroup,
					pFTDCPackage,
					&m_pkgSend,
					qryfield);
				SessionProxy::Instance().NotifySnmp(&m_pkgSend);
				SessionProxy::Instance().NotifyEventCounter(&m_pkgSend);
				SessionProxy::Instance().NotifySync(&m_pkgSend);
				SessionProxy::Instance().NotifyFront(&m_pkgSend);

				// check Condition modification
				if (oldData.Condition != qryfield.Condition)
				{
					// delete from memory DB
					ITERATE_MEMORYDB_BYKEY_BEGIN(
						NetMonitorTaskObjectSet,
						DeviceGroup_ID,
						qryfield,
						ID)
					{
						pMemoryDB->m_SysNetMonitorTaskObjectSetFactory->remove(
								pField);

						// notify snmp
						FTD_RTN(NetMonitorTaskObjectSet) rtnField;
						COPY_FTD_ENTITY(NetMonitorTaskObjectSet, &rtnField, pField);
						rtnField.OperationType = OT_DELETE;

						m_pkgSend.PrepareResponse(
								pFTDCPackage,
								FTD_RTN_ID(NetMonitorTaskObjectSet),
								FTDC_CHAIN_LAST,
								FTD_VERSION);
						FTDC_ADD_FIELD(&m_pkgSend, &rtnField);
						SessionProxy::Instance().NotifySnmp(&m_pkgSend);
					}

					ITERATE_MEMORYDB_BYKEY_END(
						NetMonitorTaskObjectSet,
						DeviceGroup_ID)
					// update taskObjectSet of MDB
					string conditionSql = searchIDFromSysNetDevice(
							qryfield.Condition.getValue());

					updateTaskObjectSet_T data;
					data.groupID = qryfield.ID;
					data.reqPkg = pFTDCPackage;
					data.rspPkg = &m_pkgSend;
					m_dbHandler.SearchRecord(
							conditionSql,
							updateTaskObjectSet,
							&data);
				}
			}

			break;
		default:
			//log
			break;
	}
}

void CFrontServer::OnReqQryNetMonitorTaskInfoTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryNetMonitorTaskInfoField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)
	{
		return;
	}

	///查
	if (qryfield.OperationType == 10)
	{
		CFTDRspQryNetMonitorTaskInfoField field;

		ITERATE_MEMORYDB_BYALL_BEGIN(NetMonitorTaskInfo)
		{
			///判断是否当日任务：
			CSysNetTimePolicy *pTimePolicyfield = pMemoryDB->
				m_SysNetTimePolicyFactory->findByOne(pField->TimePolicy_ID);
			if (pTimePolicyfield)
			{
				string Policy = pTimePolicyfield->PolicyString.getValue();
				CTimePolicy TimePolicy = CTimePolicy(Policy);
				CDateTime DateTime;
				DateTime.OpenDrift();

				string PolicyToday = TimePolicy.GetPolicyByDate(
						DateTime.GetDateStr(time(NULL)));

				//if (PolicyToday != "")
				{
					CWriteableSysNetMonitorTaskInfo obj;
					CopySysNetMonitorTaskInfoEntity(&obj, pField);

					map<int, taskStatus>::iterator	it = g_taskStatus.find(
							obj.ID);
					if (it != g_taskStatus.end())
					{
						obj.TaskStatus = it->second.status;
						obj.OutputPolicy_ID = it->second.delay;
					}

					SEND_QRYRSP_BY_MEMORYDB_RECORD(
						NetMonitorTaskInfo,
						pSession,
						pFTDCPackage,
						&m_pkgSend,
						&obj,
						qryfield.OperationType);
				}
			}
		}

		ITERATE_MEMORYDB_BYALL_END(NetMonitorTaskInfo) CCommonFTDRsp::Instance()
			->SendSuccRsp(
				pSession,
				&m_pkgSend,
				pFTDCPackage,
				FTD_TID_RspQryNetMonitorTaskInfoTopic);
	}

	if (qryfield.OperationType == 11)
	{
		BUILD_LAST_PKG_BY_FIELD(
			REQ,
			NetMonitorTaskInfo,
			pFTDCPackage,
			&m_pkgSend,
			qryfield);
		SessionProxy::Instance().NotifySnmp(&m_pkgSend);
	}
}

extern CSynconfig *synconfig;

void CFrontServer::OnSysServerExitTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqSysServerExitField field;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	if (!strcmp(field.Authorization, "william"))
	{
		synconfig->Stop();
	}
}

typedef struct
{
	vector<CFTDRspQryNetMonitorTaskStatusResultField> task_status_results;
	bool findRecord;
} Search_TaskStatus_CallBack_Data_T;

static void handleNetMonitorTaskStatusResult(SACommand &records, void *data)
{
	CFTDRspQryNetMonitorTaskStatusResultField field;
	CFtdData obj(
				&field,
				&CFTDRspQryNetMonitorTaskStatusResultField::m_Describe);
	obj.FromDBRecord(records);

	Search_TaskStatus_CallBack_Data_T *cb_data =
		(Search_TaskStatus_CallBack_Data_T *)data;
	cb_data->task_status_results.push_back(field);

	cb_data->findRecord = true;
}

void CFrontServer::OnReqQryNetMonitorTaskStatusResultTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryNetMonitorTaskStatusResultField field;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	if (field.OperationType == 10)
	{
		CDateType NowDate;
		time_t timep;
		time(&timep);

		struct tm tm_time;
		LocalTime(&timep, &tm_time);
		sprintf(
			(char *)(NowDate.getValue()),
			"%d%02d%02d",
			tm_time.tm_year + 1900,
			tm_time.tm_mon + 1,
			tm_time.tm_mday);

		// 查询任务执行次数
		if (field.MonDate == NowDate)
		{
			// 查询当日任务执行次数
			map<int, taskStatus>::iterator	it = g_taskStatus.begin();
			for (; it != g_taskStatus.end(); it++)
			{
				m_pkgSend.PrepareResponse(
						pFTDCPackage,
						FTD_TID_RspQryNetMonitorTaskStatusResultTopic,
						FTDC_CHAIN_CONTINUE,
						FTD_VERSION);

				CFTDRspQryNetMonitorTaskStatusResultField tfield;
				tfield.Task_ID = it->first;
				tfield.OperateTime = it->second.times;
				tfield.OperationType = field.OperationType;
				FTDC_ADD_FIELD(&m_pkgSend, &tfield);
				LogPkg(&m_pkgSend, g_bufferLogger, g_traceLog);

				pSession->SendRequestPackage(&m_pkgSend);
			}
		}
		else
		{
			// 查询历史任务执行次数
			SACommand cmd;

			//客户端的约定，查历史时间段的请求接口为：MonDate为开始日期，MonTime为结束日期
			if (field.Task_ID == 0)
			{
				cmd.setCommandText(
						"select * from t_SysNetMonitorTaskResult where MonDate>= :1 and MonDate <= :2");
				cmd << field.MonDate << field.MonTime;
			}
			else
			{
				cmd.setCommandText(
						"select * from t_SysNetMonitorTaskResult where Task_ID= :1 and MonDate>= :2 and MonDate <= :3");
				cmd <<
					(long)field.Task_ID.getValue() <<
					field.MonDate <<
					field.MonTime;
			}

			Search_TaskStatus_CallBack_Data_T data;
			data.findRecord = false;

			m_dbHandler.SearchRecord(
					cmd,
					handleNetMonitorTaskStatusResult,
					&data);

			if (data.task_status_results.size() == 0)
			{
				CCommonFTDRsp::Instance()->SendLastErroRsp(
						pSession,
						&m_pkgSend,
						pFTDCPackage,
						FTD_TID_RspQryNetMonitorTaskStatusResultTopic,
						"can't find data");
				return;
			}

			m_pkgSend.PrepareResponse(
					pFTDCPackage,
					FTD_TID_RspQryNetMonitorTaskStatusResultTopic,
					FTDC_CHAIN_CONTINUE,
					FTD_VERSION);
			for (int i = 0; i < data.task_status_results.size(); i++)
			{
				CFTDRspQryNetMonitorTaskStatusResultField rspField = data.
					task_status_results[i];
				AddRspWithField(
					&m_pkgSend,
					&rspField,
					pSession,
					pFTDCPackage,
					FTD_TID_RspQryNetMonitorTaskStatusResultTopic);
			}

			pSession->SendRequestPackage(&m_pkgSend);
		}
	}
	else if (field.OperationType == 11)
	{
		// 查询历史任务执行状态
		SACommand cmd;

		//客户端的约定，查历史时间段的请求接口为：MonDate为开始日期，MonTime为结束日期
		if (field.Task_ID == 0)
		{
			cmd.setCommandText(
					"select * from t_SysNetMonitorTaskResult where MonDate>= :1 and MonDate <= :2");
			cmd << field.MonDate << field.MonTime;
		}
		else
		{
			cmd.setCommandText(
					"select * from t_SysNetMonitorTaskResult where Task_ID= :1 and MonDate>= :2 and MonDate <= :3");
			cmd <<
				(long)field.Task_ID.getValue() <<
				field.MonDate <<
				field.MonTime;
		}

		Search_TaskStatus_CallBack_Data_T data;
		data.findRecord = false;

		m_dbHandler.SearchRecord(cmd, handleNetMonitorTaskStatusResult, &data);

		if (data.task_status_results.size() == 0)
		{
			CCommonFTDRsp::Instance()->SendLastErroRsp(
					pSession,
					&m_pkgSend,
					pFTDCPackage,
					FTD_TID_RspQryNetMonitorTaskStatusResultTopic,
					"can't find data");
			return;
		}

		m_pkgSend.PrepareResponse(
				pFTDCPackage,
				FTD_TID_RspQryNetMonitorTaskStatusResultTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		for (int i = 0; i < data.task_status_results.size(); i++)
		{
			CFTDRspQryNetMonitorTaskStatusResultField rspField = data.
				task_status_results[i];
			if (rspField.Flag != 21
			&&	(field.Task_ID == 0 || rspField.Task_ID == field.Task_ID))
			{
				AddRspWithField(
					&m_pkgSend,
					&rspField,
					pSession,
					pFTDCPackage,
					FTD_TID_RspQryNetMonitorTaskStatusResultTopic);
			}
		}

		pSession->SendRequestPackage(&m_pkgSend);
	}

	CCommonFTDRsp::Instance()->SendSuccRsp(
			pSession,
			&m_pkgSend,
			pFTDCPackage,
			FTD_TID_RspQryNetMonitorTaskStatusResultTopic);
}

void CFrontServer::OnReqQryNetMonitorAttrScopeTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryNetMonitorAttrScopeField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)
	{
		return;
	}

	CFTDRspQryNetMonitorAttrScopeField pField;
	ITERATE_MEMORYDB_BYALL_BEGIN(NetMonitorAttrScope)
	{
		SEND_QRYRSP_BY_MEMORYDB_RECORD(
			NetMonitorAttrScope,
			pSession,
			pFTDCPackage,
			&m_pkgSend,
			pField,
			qryfield.OperationType);
	}

	ITERATE_MEMORYDB_BYALL_END(NetMonitorAttrScope) CCommonFTDRsp::Instance()
		->SendSuccRsp(
			pSession,
			&m_pkgSend,
			pFTDCPackage,
			FTD_TID_RspQryNetMonitorAttrScopeTopic);
}

void CFrontServer::OnReqQryFileGeneralOperTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	SessionProxy::Instance().NotifySync(pFTDCPackage);

	CFTDReqQryFileGeneralOperField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)
	{
		return;
	}

	if (qryfield.OperationType == -1)
	{
		CFTDRspQryFileGeneralOperField tfield;
		memset(&tfield, 0, sizeof(tfield));

		CXMLDoc *pDoc = new CXMLDoc();
		string strFileName = g_FileServPath;
		string strXMLName = g_FileXMLPath;
		strXMLName += "updatefile.xml";
		pDoc->read((char *)(strXMLName.data()));

		CXMLNode *pRootNode = pDoc->getRootNode();
		if (pRootNode)
		{
			CXMLNodeList *pNodeList = pRootNode->getNodeList();
			if (pNodeList)
			{
				CXMLNodeList::iterator	it = pNodeList->begin();
				for (; it != pNodeList->end(); it++)
				{
					string strName = (*it)->getName();
					CXMLNodeList *pChildList = (*it)->getNodeList();
					if (pChildList)
					{
						CXMLNodeList::iterator	itList = pChildList->begin();
						for (; itList != pChildList->end(); itList++)
						{
							memset(&tfield, 0, sizeof(tfield));
							tfield.OperationType = -1;
							tfield.MonDate = (*itList)->findProperty("date");
							tfield.MonTime = (*itList)->findProperty("time");
							tfield.UserName = (*itList)->findProperty(
									"username");
							tfield.FileName = strName.data();
							tfield.OperType = atoi(
									(*itList)->findProperty("opertype"));
							tfield.SubVersion = atoi(
									(*itList)->findProperty("subver"));
							m_pkgSend.PreparePackage(
									FTD_TID_RspQryFileGeneralOperTopic,
									FTDC_CHAIN_CONTINUE,
									FTD_VERSION);
							m_pkgSend.SetRequestId(
									pFTDCPackage->GetRequestId());
							FTDC_ADD_FIELD(&m_pkgSend, &tfield);
							pSession->SendRequestPackage(&m_pkgSend);
						}
					}
				}
			}
		}

		m_pkgSend.PreparePackage(
				FTD_TID_RspQryFileGeneralOperTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());
		memset(&tfield, 0, sizeof(tfield));
		tfield.OperationType = -1;
		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		pSession->SendRequestPackage(&m_pkgSend);
	}

	///初始化升级请求应答
	else if (qryfield.OperationType == 10 || qryfield.OperationType == 1)
	{
		string strFileName = g_FileServPath;
		strFileName += qryfield.FileName.getValue();

		int offset = 0;
		string strFile = strFileName;
		strFile = replace_all_distinct(strFile, (string) "--", (string) "/");

		/*long fsize=0;
		struct_stat s_buf;
		if( STAT(  strFile.data(), &s_buf )>=0 )
			fsize = s_buf.st_size;*/
		/*m_pkgSend.PreparePackage(FTD_TID_RspQryFileGeneralOperTopic, FTDC_CHAIN_CONTINUE, FTD_VERSION);
		m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());
		CFTDRspQryGetFileField tfield;
		strcpy((char *)(tfield.FileName.getValue()) ,"");
		tfield.Length.setValue(fsize);
		FTDC_ADD_FIELD(&m_pkgSend,&tfield);
		pSession->SendRequestPackage(&m_pkgSend);*/
		char buffer[10];
		sprintf(buffer, "%d", qryfield.SubVersion.getValue());

		FILE *pf;
		if (qryfield.SubVersion == 0)
		{
			pf = fopen(strFile.data(), "rb");
		}
		else
		{
			strFile += "update/";
			strFile += buffer;
			pf = fopen(strFile.data(), "rb");
		}

		if (pf)
		{
			fseek(pf, offset, SEEK_SET);
			while (true)
			{
				m_pkgSend.PreparePackage(
						FTD_TID_RspQryFileGeneralOperTopic,
						FTDC_CHAIN_CONTINUE,
						FTD_VERSION);
				m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());

				CFTDRspQryFileGeneralOperField tfield;
				memset(&tfield, 0, sizeof(tfield));

				int len = fread(
						(void *)(tfield.FileContent.getValue()),
						1,
						sizeof(tfield.FileContent) - 1,
						pf);
				if (SEEK_END == ftell(pf) || len <= 0)
				{
					m_pkgSend.SetChain(FTDC_CHAIN_LAST);
				}

				tfield.Length.setValue(len);
				tfield.Offset.setValue(offset);
				tfield.FileName = qryfield.FileName;
				offset += len;
				tfield.OperationType = qryfield.OperationType;
				FTDC_ADD_FIELD(&m_pkgSend, &tfield);
				pSession->SendRequestPackage(&m_pkgSend);
				if (SEEK_END == ftell(pf) || len <= 0)
				{
					break;
				}
			}

			fclose(pf);
		}
	}

	///请求变更
	else if (qryfield.OperationType == 3)
	{
		string strFileName = g_FileServPath;
		strFileName += qryfield.FileName.getValue();
		replace_all_distinct(strFileName, (string) "--", (string) "/");

		int iLen = strlen(strFileName.data());
		for (int i = 0; i < iLen; i++)
		{
			if (strFileName[i] == '/')
			{
				strFileName[i] = '\0';

				int iRet = access(strFileName.data(), 0);
				if (iRet != 0)
				{
					m_pkgSend.PreparePackage(
							FTD_TID_RspQryFileGeneralOperTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
					m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());

					CFTDRspQryFileGeneralOperField tfield;
					memset(&tfield, 0, sizeof(tfield));
					tfield.OperationType = qryfield.OperationType;
					tfield.FileName = qryfield.FileName;
					tfield.OperResult = 0;
					tfield.Comments = "申请更新失败，该文件不存在！";
					FTDC_ADD_FIELD(&m_pkgSend, &tfield);
					pSession->SendRequestPackage(&m_pkgSend);
					return;
				}

				strFileName[i] = '/';
			}
		}

		string strName = qryfield.FileName.getValue();
		replace_all_distinct(strName, (string) "--", (string) "/");
		if (access(strFileName.data(), 0) != 0)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryFileGeneralOperTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());

			CFTDRspQryFileGeneralOperField tfield;
			memset(&tfield, 0, sizeof(tfield));
			tfield.OperationType = qryfield.OperationType;
			tfield.FileName = qryfield.FileName;
			tfield.OperResult = 0;
			tfield.Comments = "申请更新失败，该文件不存在！";
			FTDC_ADD_FIELD(&m_pkgSend, &tfield);
			pSession->SendRequestPackage(&m_pkgSend);
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
		time_t timep;
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
					string strName = (*it)->getName();
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

		string strXMLName = g_FileXMLPath;
		strXMLName += "updatefile.xml";
		pUpdateDoc->write((char *)(strXMLName.data()));
		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		NotifyAllSession(&m_pkgSend);

		///返回请求变更成功
		m_pkgSend.PreparePackage(
				FTD_TID_RspQryFileGeneralOperTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());

		CFTDRspQryFileGeneralOperField thefield;
		memset(&thefield, 0, sizeof(thefield));
		CopyRspQryFileGeneralOperEntity(&thefield, &tfield);
		thefield.OperationType = qryfield.OperationType;
		thefield.FileName = qryfield.FileName;
		thefield.OperResult = 1;
		thefield.SubVersion = qryfield.SubVersion;
		FTDC_ADD_FIELD(&m_pkgSend, &thefield);
		pSession->SendRequestPackage(&m_pkgSend);
	}

	///提交更新
	else if (qryfield.OperationType == 30)
	{
		string strFileName = g_FileServPath;
		strFileName += qryfield.FileName.getValue();
		replace_all_distinct(strFileName, (string) "--", (string) "/");

		char ch[10];
		sprintf(ch, "%d", qryfield.SubVersion.getValue());
		strFileName += "update/";
		strFileName += ch;

		///初建新版本文件
		if (qryfield.OperType == 1)
		{
			CreatMultiDir((char *)(strFileName.data()));

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

					string strXMLName = g_FileXMLPath;
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
			time_t timep;
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
			FTDC_ADD_FIELD(&m_pkgSend, &tfield);
			NotifyAllSession(&m_pkgSend);
		}
	}

	///增加文件
	else if (qryfield.OperationType == 20)
	{
		string strFileName = g_FileServPath;
		strFileName += qryfield.FileName.getValue();
		replace_all_distinct(strFileName, (string) "--", (string) "/");
		if (qryfield.OperType == 1)
		{
			if (access(strFileName.data(), 0) == 0)
			{
				m_pkgSend.PreparePackage(
						FTD_TID_RspQryFileGeneralOperTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());

				CFTDRspQryFileGeneralOperField tfield;
				memset(&tfield, 0, sizeof(tfield));
				tfield.OperationType = qryfield.OperationType;
				tfield.FileName = qryfield.FileName;
				tfield.OperResult = 0;
				tfield.Comments = "添加失败，该文件已存在！";
				FTDC_ADD_FIELD(&m_pkgSend, &tfield);
				pSession->SendRequestPackage(&m_pkgSend);
			}
			else
			{
				strAddFileName = qryfield.FileName;
				CreatMultiDir((char *)(strFileName.data()));

				FILE *fp;
				fp = fopen(strFileName.data(), "wb");
				fwrite(qryfield.FileContent, 1, qryfield.Length, fp);
				fclose(fp);

				m_pkgSend.PreparePackage(
						FTD_TID_RspQryFileGeneralOperTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());

				CFTDRspQryFileGeneralOperField tfield;
				memset(&tfield, 0, sizeof(tfield));
				tfield.OperationType = qryfield.OperationType;
				tfield.FileName = qryfield.FileName;
				tfield.OperResult = 1;
				FTDC_ADD_FIELD(&m_pkgSend, &tfield);
				pSession->SendRequestPackage(&m_pkgSend);
			}
		}
		else if (qryfield.OperType == 0 || qryfield.OperType == 10)
		{
			string strTmp = qryfield.FileName.getValue();
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
					time_t timep;
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

					FTDC_ADD_FIELD(&m_pkgSend, &tfield);
					NotifyAllSession(&m_pkgSend);

					string strXMLName = g_FileXMLPath;
					strXMLName += "updatefile.xml";
					pUpdateDoc->write((char *)(strXMLName.data()));
				}
			}
		}
	}
}

void CFrontServer::OnReqQryNetBaseLineTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryNetBaseLineField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)
	{
		return;
	}

	// 为了复用OperationType为OT_ADD而加
	static int s_base_line_id = -1;

	if (qryfield.OperationType == OT_QUERY)
	{
		if (qryfield.ID == 0)
		{
			// 查所有信息，但不带data数据域，减小网络通信流量。
			ITERATE_MEMORYDB_BYALL_BEGIN(NetBaseLine)
			{
				FTD_RSP(NetBaseLine) rspField;
				COPY_FTD_ENTITY(NetBaseLine, &rspField, pField);
				rspField.data = "";		// 去除掉data
				rspField.OperationType = OT_ADD;
				SEND_RSP(
					NetBaseLine,
					pSession,
					pFTDCPackage,
					&m_pkgSend,
					rspField);
			}

			ITERATE_MEMORYDB_BYALL_END(NetBaseLine)
		}
		else
		{
			ITERATE_MEMORYDB_BYKEY_BEGIN(NetBaseLine, ID, qryfield, ID)
			{
				SEND_QRYRSP_BY_MEMORYDB_RECORD(
					NetBaseLine,
					pSession,
					pFTDCPackage,
					&m_pkgSend,
					pField,
					qryfield.OperationType);
			}

			ITERATE_MEMORYDB_BYKEY_END(NetBaseLine, ID)
		}

		CCommonFTDRsp::Instance()->SendSuccRsp(
				pSession,
				&m_pkgSend,
				pFTDCPackage,
				FTD_TID_RspQryNetBaseLineTopic);

		return;
	}

	bool dbResult = false;

	if (qryfield.OperationType == OT_ADD)
	{
		static std::map<string, std::vector<CFTDReqQryNetBaseLineField> >
			pkgBuf;

		if (qryfield.Flag.getValue() == 0)
		{
			// 有后续包，放入缓冲区
			pkgBuf[qryfield.Name.getValue()].push_back(qryfield);
			return;
		}

		int baseLineID;
		if (s_base_line_id == -1)
		{
			baseLineID = g_idMaker["SysNetBaseLine"]++;
		}
		else
		{
			// 此时的s_base_line_id是OT_UPDATE时设置的，在OT_ADD结束时，要重置为-1
			baseLineID = s_base_line_id;
		}

		if (qryfield.Flag.getValue() == 1)
		{
			// 为终止包，从缓冲区中取出前面的包，依次写入数据库
			pkgBuf[qryfield.Name.getValue()].push_back(qryfield);

			qryfield.ID = baseLineID;

			std::vector<CFTDReqQryNetBaseLineField> &pkgs = pkgBuf[qryfield.
				Name.getValue()];
			for (int i = 0, size = pkgs.size(); i < size; i++)
			{
				pkgs[i].ID = baseLineID;
				INSERT_OBJ_TO_DB(NetBaseLine, pkgs[i], m_dbHandler, dbResult);
				if (dbResult)
				{
					INSERT_RECORD_INTO_MEMORYDB(NetBaseLine, pkgs[i]);

					// 通知后台服务
					BUILD_LAST_PKG_BY_FIELD(
						RTN,
						NetBaseLine,
						pFTDCPackage,
						&m_pkgSend,
						pkgs[i]);
					SessionProxy::Instance().NotifyEventCounter(&m_pkgSend);
					SessionProxy::Instance().NotifySync(&m_pkgSend);
				}
				else
				{
					// log
					LOG_ERROR(
						"Insert NetBaseLine failed! recored may be uncomplete!");
					break;
				}

				//TODO：中间发生插入错误，要将不完整的记录回滚
			}

			// 清除缓存的包
			pkgBuf.erase(qryfield.Name.getValue());
		}
		else if (qryfield.Flag.getValue() == 2)
		{
			// 单独包，直接写入数据库
			qryfield.ID = baseLineID;
			INSERT_OBJ_TO_DB(NetBaseLine, qryfield, m_dbHandler, dbResult);
			if (dbResult)
			{
				INSERT_RECORD_INTO_MEMORYDB(NetBaseLine, qryfield);

				// 通知后台服务
				BUILD_LAST_PKG_BY_FIELD(
					RTN,
					NetBaseLine,
					pFTDCPackage,
					&m_pkgSend,
					qryfield);
				SessionProxy::Instance().NotifyEventCounter(&m_pkgSend);
				SessionProxy::Instance().NotifySync(&m_pkgSend);
			}
		}
		else
		{
			// 非法类型
			return;
		}

		// 重置
		s_base_line_id = -1;

		// 发送RSP
		CFTDRspQryNetBaseLineField rspfield;
		CopyRspQryNetBaseLineEntity(&rspfield, &qryfield);
		rspfield.data = "";				//清空data，减少网络流量
		SEND_RSP(NetBaseLine, pSession, pFTDCPackage, &m_pkgSend, rspfield);
		NotifyAllSession(&m_pkgSend);
	}
	else if (qryfield.OperationType == OT_DELETE)
	{
		if (qryfield.ID == 0)
		{
			//TODO
		}
		else
		{
			DELETE_OBJ_FROM_DB(
				NetBaseLine,
				qryfield,
				"ID",
				m_dbHandler,
				dbResult);
			ITERATE_MEMORYDB_BYKEY_BEGIN(NetBaseLine, ID, qryfield, ID)
			{
				if (dbResult)
				{
					DELETE_RECORD_BYKEY_FROM_MEMORYDB(NetBaseLine, pField);
				}
			}

			ITERATE_MEMORYDB_BYKEY_END(NetBaseLine, ID)
		}

		qryfield.data = "";				//清空data，减少网络流量

		// 发送RSP
		CFTDRspQryNetBaseLineField rspfield;
		CopyRspQryNetBaseLineEntity(&rspfield, &qryfield);
		SEND_RSP(NetBaseLine, pSession, pFTDCPackage, &m_pkgSend, rspfield);

		// 通知各个服务端
		BUILD_LAST_PKG_BY_FIELD(
			RTN,
			NetBaseLine,
			pFTDCPackage,
			&m_pkgSend,
			qryfield);
		SessionProxy::Instance().NotifyEventCounter(&m_pkgSend);
		SessionProxy::Instance().NotifySync(&m_pkgSend);
		NotifyAllSession(&m_pkgSend);
	}
	else if (qryfield.OperationType == OT_UPDATE)
	{
		static std::map<string, std::vector<CFTDReqQryNetBaseLineField> >
			pkgBuf;
		if (qryfield.Flag.getValue() == 0)
		{
			// 有后续包，放入缓冲区
			pkgBuf[qryfield.Name.getValue()].push_back(qryfield);

			return;
		}

		s_base_line_id = qryfield.ID;

		if (qryfield.Flag.getValue() == 1)
		{
			// 为终止包，从缓冲区中取出前面的包，依次写入数据库
			pkgBuf[qryfield.Name.getValue()].push_back(qryfield);

			CFTDReqQryNetBaseLineField dummyQryField;
			dummyQryField.OperationType = OT_DELETE;
			dummyQryField.ID = s_base_line_id;

			m_pkgSend.PreparePackage(
					pFTDCPackage->GetTID(),
					pFTDCPackage->GetChain(),
					pFTDCPackage->GetVersion());
			FTDC_ADD_FIELD(&m_pkgSend, &dummyQryField);
			OnReqQryNetBaseLineTopic(&m_pkgSend, pSession);

			std::vector<CFTDReqQryNetBaseLineField> &pkgs = pkgBuf[qryfield.
				Name.getValue()];

			for (int i = 0, size = pkgs.size(); i < size; i++)
			{
				int baseLineID = s_base_line_id;
				CopyReqQryNetBaseLineEntity(&dummyQryField, &(pkgs[i]));
				dummyQryField.OperationType = OT_ADD;

				m_pkgSend.PreparePackage(
						pFTDCPackage->GetTID(),
						pFTDCPackage->GetChain(),
						pFTDCPackage->GetVersion());
				FTDC_ADD_FIELD(&m_pkgSend, &dummyQryField);
				OnReqQryNetBaseLineTopic(&m_pkgSend, pSession);

				// OT_ADD的操作中会重置s_base_line_id为-1，因此此处要将其设置为正确值
				s_base_line_id = baseLineID;
			}

			// 重置
			s_base_line_id = -1;

			// 清除缓存的包
			pkgBuf.erase(qryfield.Name.getValue());
		}
		else if (qryfield.Flag.getValue() == 2)
		{
			// 单独包
			CFTDReqQryNetBaseLineField dummyQryField;
			dummyQryField.OperationType = OT_DELETE;
			dummyQryField.ID = s_base_line_id;

			m_pkgSend.PreparePackage(
					pFTDCPackage->GetTID(),
					pFTDCPackage->GetChain(),
					pFTDCPackage->GetVersion());
			FTDC_ADD_FIELD(&m_pkgSend, &dummyQryField);
			OnReqQryNetBaseLineTopic(&m_pkgSend, pSession);

			CopyReqQryNetBaseLineEntity(&dummyQryField, &qryfield);
			dummyQryField.OperationType = OT_ADD;

			m_pkgSend.PreparePackage(
					pFTDCPackage->GetTID(),
					pFTDCPackage->GetChain(),
					pFTDCPackage->GetVersion());
			FTDC_ADD_FIELD(&m_pkgSend, &dummyQryField);
			OnReqQryNetBaseLineTopic(&m_pkgSend, pSession);
		}
		else
		{
			// 非法类型
			return;
		}

		qryfield.data = "";				//清空data，减少网络流量

		// 发送RSP
		CFTDRspQryNetBaseLineField rspfield;
		CopyRspQryNetBaseLineEntity(&rspfield, &qryfield);
		SEND_RSP(NetBaseLine, pSession, pFTDCPackage, &m_pkgSend, rspfield);

		//// 通知各个服务端
		//BUILD_LAST_PKG_BY_FIELD(RTN, NetBaseLine, pFTDCPackage, &m_pkgSend, qryfield);
		//SessionProxy::Instance().NotifyEventCounter(&m_pkgSend);
		//SessionProxy::Instance().NotifySync(&m_pkgSend);
		NotifyAllSession(&m_pkgSend);
	}

	if (dbResult)
	{
		CCommonFTDRsp::Instance()->SendSuccRsp(
				pSession,
				&m_pkgSend,
				pFTDCPackage,
				FTD_TID_RspQryNetBaseLineTopic);
	}
	else
	{
		CCommonFTDRsp::Instance()->SendLastErroRsp(
				pSession,
				&m_pkgSend,
				pFTDCPackage,
				FTD_TID_RspQryNetBaseLineTopic);
	}
}

void handleNetMonitorDeviceTask(SACommand &records, void *data)
{
	CFTDSysNetMonitorDeviceTaskField field;
	CFtdData obj(&field, &CFTDSysNetMonitorDeviceTaskField::m_Describe);
	obj.FromDBRecord(records);

	int *id = (int *)data;
	*id = field.ID.getValue();
}

bool CFrontServer::AddDeviceTaskItem2DB(
	CFTDCPackage *pFTDCPackage,
	CFTDReqQryNetMonitorDeviceTaskField &qryfield,
	int nTaskFlitID)
{
	static std::map<string, std::vector<CFTDReqQryNetMonitorDeviceTaskField> >
		pkgBuf;

	if (qryfield.Flag.getValue() == 0)
	{
		// 有后续包，放入缓冲区
		pkgBuf[qryfield.ObjectID.getValue()].push_back(qryfield);
		return true;
	}

	int taskID;
	if (nTaskFlitID == -1)
	{
		pkgBuf.clear();
		return false;
	}
	else
	{
		// 此时的s_task_id是OT_UPDATE时设置的，在OT_ADD结束时，要重置为-1
		taskID = nTaskFlitID;
	}

	bool dbResult = false;
	if (qryfield.Flag.getValue() == 1)
	{
		// 为终止包，从缓冲区中取出前面的包，依次写入数据库
		pkgBuf[qryfield.ObjectID.getValue()].push_back(qryfield);

		qryfield.ID = taskID;

		std::vector<CFTDReqQryNetMonitorDeviceTaskField> &pkgs = pkgBuf[
			qryfield.ObjectID.getValue()];
		for (int i = 0, size = pkgs.size(); i < size; i++)
		{
			pkgs[i].ID = taskID;

			CFTDSysNetMonitorDeviceTask2Field tmpField4DB;
			CopySysNetMonitorDeviceTaskEntity(&tmpField4DB, &pkgs[i]);
			tmpField4DB.SecondID = i + 1;
			{
				CFtdData wrappedObj(
							&tmpField4DB,
							&CFTDSysNetMonitorDeviceTask2Field::m_Describe);
				dbResult = m_dbHandler.InsertRecord(
						"t_SysNetMonitorDeviceTask",
						&wrappedObj);
			}

			//INSERT_OBJ_TO_DB(NetMonitorDeviceTask,tmpField4DB, m_dbHandler, dbResult);
			if (dbResult)
			{
				{
					CWriteableSysNetMonitorDeviceTask r;
					CopySysNetMonitorDeviceTask2Entity(&r, &tmpField4DB);
					pMemoryDB->m_SysNetMonitorDeviceTaskFactory->add(&r);
				}

				//INSERT_RECORD_INTO_MEMORYDB(NetMonitorDeviceTask, tmpField4DB);
				// 通知后台服务
				pkgs[i].OperationType = OT_ADD;
				BUILD_LAST_PKG_BY_FIELD(
					RTN,
					NetMonitorDeviceTask,
					pFTDCPackage,
					&m_pkgSend,
					pkgs[i]);
				SessionProxy::Instance().NotifyEventCounter(&m_pkgSend);
				SessionProxy::Instance().NotifySnmp(&m_pkgSend);
				SessionProxy::Instance().NotifySync(&m_pkgSend);
			}
			else
			{
				// log
				LOG_ERROR(
					"Insert NetMonitorDeviceTask failed! recored may be uncomplete!");
				break;
			}

			//TODO：中间发生插入错误，要将不完整的记录回滚
		}
	}
	else if (qryfield.Flag.getValue() == 2)
	{
		// 单独包，直接写入数据库
		qryfield.ID = taskID;

		CFTDSysNetMonitorDeviceTask2Field tmpField4DB;
		CopySysNetMonitorDeviceTaskEntity(&tmpField4DB, &qryfield);
		tmpField4DB.SecondID = 1;
		{
			CFtdData wrappedObj(
						&tmpField4DB,
						&CFTDSysNetMonitorDeviceTask2Field::m_Describe);
			dbResult = m_dbHandler.InsertRecord(
					"t_SysNetMonitorDeviceTask",
					&wrappedObj);
		}

		//INSERT_OBJ_TO_DB(NetMonitorDeviceTask, tmpField4DB, m_dbHandler, dbResult);
		if (dbResult)
		{
			{
				CWriteableSysNetMonitorDeviceTask r;
				CopySysNetMonitorDeviceTask2Entity(&r, &tmpField4DB);
				pMemoryDB->m_SysNetMonitorDeviceTaskFactory->add(&r);
			}

			//INSERT_RECORD_INTO_MEMORYDB(NetMonitorDeviceTask, tmpField4DB);
			// 通知后台服务
			qryfield.OperationType = OT_ADD;

			BUILD_LAST_PKG_BY_FIELD(
				RTN,
				NetMonitorDeviceTask,
				pFTDCPackage,
				&m_pkgSend,
				qryfield);
			SessionProxy::Instance().NotifyEventCounter(&m_pkgSend);
			SessionProxy::Instance().NotifySnmp(&m_pkgSend);
			SessionProxy::Instance().NotifySync(&m_pkgSend);
		}
	}
	else
	{
		// 非法类型
	}

	// 清除缓存的包
	pkgBuf.erase(qryfield.ObjectID.getValue());

	return dbResult;
}

bool CFrontServer::RemoveDeviceTaskItem4DB(
	CFTDCPackage *pFTDCPackage,
	CFTDReqQryNetMonitorDeviceTaskField &qryfield,
	int nTaskFlitID)
{
	bool dbResult = false;
	if (nTaskFlitID == 0)
	{
		//TODO
		return true;
	}
	else
	{
		qryfield.ID = nTaskFlitID;
		DELETE_OBJ_FROM_DB(
			NetMonitorDeviceTask,
			qryfield,
			"ID",
			m_dbHandler,
			dbResult);
		ITERATE_MEMORYDB_BYKEY_BEGIN(NetMonitorDeviceTask, ID, qryfield, ID)
		{
			if (dbResult)
			{
				DELETE_RECORD_BYKEY_FROM_MEMORYDB(NetMonitorDeviceTask, pField);
			}
		}

		ITERATE_MEMORYDB_BYKEY_END(NetMonitorDeviceTask, ID) if (dbResult)
		{
			// 通知后台服务
			qryfield.OperationType = OT_DELETE;
			BUILD_LAST_PKG_BY_FIELD(
				RTN,
				NetMonitorDeviceTask,
				pFTDCPackage,
				&m_pkgSend,
				qryfield);
			SessionProxy::Instance().NotifyEventCounter(&m_pkgSend);
			SessionProxy::Instance().NotifySnmp(&m_pkgSend);
			SessionProxy::Instance().NotifySync(&m_pkgSend);
			NotifyAllSession(&m_pkgSend);
		}
	}

	return dbResult;
}

void CFrontServer::OnReqQryNetMonitorDeviceTaskTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryNetMonitorDeviceTaskField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)
	{
		return;
	}

	// 为了复用OperationType为OT_ADD而加
	int s_task_id = -1;

	if (qryfield.OperationType == OT_QUERY)
	{
		if (qryfield.ID == 0)
		{
			// 查所有信息。
			ITERATE_MEMORYDB_BYALL_BEGIN(NetMonitorDeviceTask)
			{
				FTD_RSP(NetMonitorDeviceTask) rspField;
				COPY_FTD_ENTITY(NetMonitorDeviceTask, &rspField, pField);
				rspField.OperationType = OT_ADD;
				SEND_RSP(
					NetMonitorDeviceTask,
					pSession,
					pFTDCPackage,
					&m_pkgSend,
					rspField);
			}

			ITERATE_MEMORYDB_BYALL_END(NetMonitorDeviceTask)
		}
		else
		{
			ITERATE_MEMORYDB_BYKEY_BEGIN(NetMonitorDeviceTask, ID, qryfield, ID)
			{
				SEND_QRYRSP_BY_MEMORYDB_RECORD(
					NetMonitorDeviceTask,
					pSession,
					pFTDCPackage,
					&m_pkgSend,
					pField,
					qryfield.OperationType);
			}

			ITERATE_MEMORYDB_BYKEY_END(NetMonitorDeviceTask, ID)
		}

		CCommonFTDRsp::Instance()->SendSuccRsp(
				pSession,
				&m_pkgSend,
				pFTDCPackage,
				FTD_TID_RspQryNetMonitorDeviceTaskTopic);

		return;
	}

	bool dbResult = false;

	if (qryfield.OperationType == OT_ADD)
	{
		static std::map
			<
				string, std::vector<CFTDReqQryNetMonitorDeviceTaskField>
			>  pkgBuf;

		if (qryfield.Flag.getValue() == 0)
		{
			// 有后续包，放入缓冲区
			pkgBuf[qryfield.ObjectID.getValue()].push_back(qryfield);
			return;
		}

		int taskID = g_idMaker["SysNetMonitorDeviceTask"]++;

		if (qryfield.Flag.getValue() == 1)
		{
			// 为终止包，从缓冲区中取出前面的包，依次写入数据库
			pkgBuf[qryfield.ObjectID.getValue()].push_back(qryfield);

			qryfield.ID = taskID;

			std::vector<CFTDReqQryNetMonitorDeviceTaskField> &pkgs = pkgBuf[
				qryfield.ObjectID.getValue()];
			for (int i = 0, size = pkgs.size(); i < size; i++)
			{
				pkgs[i].ID = taskID;

				CFTDSysNetMonitorDeviceTask2Field tmpField4DB;
				CopySysNetMonitorDeviceTaskEntity(&tmpField4DB, &pkgs[i]);
				tmpField4DB.SecondID = i + 1;

				//INSERT_OBJ_TO_DB(NetMonitorDeviceTask, tmpField4DB, m_dbHandler, dbResult);
				{
					CFtdData wrappedObj(
								&tmpField4DB,
								&CFTDSysNetMonitorDeviceTask2Field::m_Describe);
					dbResult = m_dbHandler.InsertRecord(
							"t_SysNetMonitorDeviceTask",
							&wrappedObj);
				}

				if (dbResult)
				{
					{
						CWriteableSysNetMonitorDeviceTask r;
						CopySysNetMonitorDeviceTask2Entity(&r, &tmpField4DB);
						pMemoryDB->m_SysNetMonitorDeviceTaskFactory->add(&r);
					}

					//INSERT_RECORD_INTO_MEMORYDB(NetMonitorDeviceTask, tmpField4DB);
					// 通知后台服务
					BUILD_LAST_PKG_BY_FIELD(
						RTN,
						NetMonitorDeviceTask,
						pFTDCPackage,
						&m_pkgSend,
						pkgs[i]);
					SessionProxy::Instance().NotifyEventCounter(&m_pkgSend);
					SessionProxy::Instance().NotifySnmp(&m_pkgSend);
					SessionProxy::Instance().NotifySync(&m_pkgSend);
				}
				else
				{
					// log
					LOG_ERROR(
						"Insert NetMonitorDeviceTask failed! recored may be uncomplete!");
					break;
				}

				//TODO：中间发生插入错误，要将不完整的记录回滚
			}

			// 清除缓存的包
			pkgBuf.erase(qryfield.ObjectID.getValue());
		}
		else if (qryfield.Flag.getValue() == 2)
		{
			// 单独包，直接写入数据库
			qryfield.ID = taskID;

			CFTDSysNetMonitorDeviceTask2Field tmpField4DB;
			CopySysNetMonitorDeviceTaskEntity(&tmpField4DB, &qryfield);
			tmpField4DB.SecondID = 1;
			{
				CFtdData wrappedObj(
							&tmpField4DB,
							&CFTDSysNetMonitorDeviceTask2Field::m_Describe);
				dbResult = m_dbHandler.InsertRecord(
						"t_SysNetMonitorDeviceTask",
						&wrappedObj);
			}

			//INSERT_OBJ_TO_DB(NetMonitorDeviceTask, tmpField4DB, m_dbHandler, dbResult);
			if (dbResult)
			{
				{
					CWriteableSysNetMonitorDeviceTask r;
					CopySysNetMonitorDeviceTask2Entity(&r, &tmpField4DB);
					pMemoryDB->m_SysNetMonitorDeviceTaskFactory->add(&r);
				}

				//INSERT_RECORD_INTO_MEMORYDB(NetMonitorDeviceTask, tmpField4DB);
				// 通知后台服务
				BUILD_LAST_PKG_BY_FIELD(
					RTN,
					NetMonitorDeviceTask,
					pFTDCPackage,
					&m_pkgSend,
					qryfield);
				SessionProxy::Instance().NotifyEventCounter(&m_pkgSend);
				SessionProxy::Instance().NotifySnmp(&m_pkgSend);
				SessionProxy::Instance().NotifySync(&m_pkgSend);
			}
		}
		else
		{
			// 非法类型
			return;
		}

		// 重置
		s_task_id = -1;

		// 发送RSP
		CFTDRspQryNetMonitorDeviceTaskField rspfield;
		CopyRspQryNetMonitorDeviceTaskEntity(&rspfield, &qryfield);
		rspfield.DefParamChain = "";	//清空DefParamChain，减少网络流量
		SEND_RSP(
			NetMonitorDeviceTask,
			pSession,
			pFTDCPackage,
			&m_pkgSend,
			rspfield);
		NotifyAllSession(&m_pkgSend);
	}
	else if (qryfield.OperationType == OT_DELETE)
	{
		if (qryfield.ID == 0)
		{
			//TODO
		}
		else
		{
			DELETE_OBJ_FROM_DB(
				NetMonitorDeviceTask,
				qryfield,
				"ID",
				m_dbHandler,
				dbResult);
			ITERATE_MEMORYDB_BYKEY_BEGIN(NetMonitorDeviceTask, ID, qryfield, ID)
			{
				if (dbResult)
				{
					DELETE_RECORD_BYKEY_FROM_MEMORYDB(
						NetMonitorDeviceTask,
						pField);
				}
			}

			ITERATE_MEMORYDB_BYKEY_END(NetMonitorDeviceTask, ID)
		}

		qryfield.DefParamChain = "";	//清空DefParamChain，减少网络流量

		// 发送RSP
		CFTDRspQryNetMonitorDeviceTaskField rspfield;
		CopyRspQryNetMonitorDeviceTaskEntity(&rspfield, &qryfield);
		SEND_RSP(
			NetMonitorDeviceTask,
			pSession,
			pFTDCPackage,
			&m_pkgSend,
			rspfield);

		// 通知各个服务端
		BUILD_LAST_PKG_BY_FIELD(
			RTN,
			NetMonitorDeviceTask,
			pFTDCPackage,
			&m_pkgSend,
			qryfield);
		SessionProxy::Instance().NotifyEventCounter(&m_pkgSend);
		SessionProxy::Instance().NotifySnmp(&m_pkgSend);
		SessionProxy::Instance().NotifySync(&m_pkgSend);
		NotifyAllSession(&m_pkgSend);
	}
	else if (qryfield.OperationType == OT_UPDATE)
	{
		static std::map
			<
				string, std::vector<CFTDReqQryNetMonitorDeviceTaskField>
			>  pkgBuf;
		if (qryfield.Flag.getValue() == 0)
		{
			// 有后续包，放入缓冲区
			pkgBuf[qryfield.ObjectID.getValue()].push_back(qryfield);

			return;
		}

		s_task_id = qryfield.ID;

		bool dbTmpRst = false;
		if (qryfield.Flag.getValue() == 1)
		{
			// 为终止包，从缓冲区中取出前面的包，依次写入数据库
			pkgBuf[qryfield.ObjectID.getValue()].push_back(qryfield);

			//先删除数据，然后添加id相同数据
			dbTmpRst = RemoveDeviceTaskItem4DB(
					pFTDCPackage,
					qryfield,
					s_task_id);

			std::vector<CFTDReqQryNetMonitorDeviceTaskField> &pkgs = pkgBuf[
				qryfield.ObjectID.getValue()];

			for (int i = 0, size = pkgs.size(); i < size && dbTmpRst; i++)
			{
				dbTmpRst = AddDeviceTaskItem2DB(
						pFTDCPackage,
						pkgs[i],
						s_task_id);
			}

			// 重置
			s_task_id = -1;

			// 清除缓存的包
			pkgBuf.erase(qryfield.ObjectID.getValue());
		}
		else if (qryfield.Flag.getValue() == 2)
		{
			// 单独包
			dbTmpRst = RemoveDeviceTaskItem4DB(
					pFTDCPackage,
					qryfield,
					s_task_id);
			if (dbTmpRst)
			{
				dbTmpRst = AddDeviceTaskItem2DB(
						pFTDCPackage,
						qryfield,
						s_task_id);
			}
		}
		else
		{
			// 非法类型
			return;
		}

		qryfield.DefParamChain = "";	//清空DefParamChain，减少网络流量
		if (dbTmpRst)
		{
			// 发送RSP
			CFTDRspQryNetMonitorDeviceTaskField rspfield;
			CopyRspQryNetMonitorDeviceTaskEntity(&rspfield, &qryfield);
			SEND_RSP(
				NetMonitorDeviceTask,
				pSession,
				pFTDCPackage,
				&m_pkgSend,
				rspfield);

			//// 通知各个服务端
			//NotifyAllSession(&m_pkgSend);
		}

		dbResult = dbTmpRst;
	}
	else if (qryfield.OperationType.getValue() == 5)
	{
		static std::map
			<
				string, std::vector<CFTDReqQryNetMonitorDeviceTaskField>
			>  pkgBuf;
		if (qryfield.Flag.getValue() == 0)
		{
			// 有后续包，放入缓冲区
			pkgBuf[qryfield.ObjectID.getValue()].push_back(qryfield);

			return;
		}

		pkgBuf[qryfield.ObjectID.getValue()].push_back(qryfield);

		// 客户端不知是Update还是Add操作，由后台判断
		// search db to identify whether a new record or not
		SACommand cmd;
		cmd.setCommandText(
				"select * from t_SysNetMonitorDeviceTask where ObjectID= :1 and InstructAlias= :2");
		cmd <<
			qryfield.ObjectID.getValue() <<
			qryfield.InstructAlias.getValue();

		int id = -1;
		m_dbHandler.SearchRecord(cmd, handleNetMonitorDeviceTask, &id);

		bool dbTmpRst = true;
		if (id == -1)
		{
			std::vector<CFTDReqQryNetMonitorDeviceTaskField> &pkgs = pkgBuf[
				qryfield.ObjectID.getValue()];

			id = g_idMaker["SysNetMonitorDeviceTask"]++;

			for (int i = 0, size = pkgs.size(); i < size && dbTmpRst; i++)
			{
				dbTmpRst = AddDeviceTaskItem2DB(pFTDCPackage, pkgs[i], id);
			}

			qryfield.OperationType = OT_ADD;
			qryfield.ID = id;
		}
		else
		{
			// update record
			dbTmpRst = RemoveDeviceTaskItem4DB(pFTDCPackage, qryfield, id);

			std::vector<CFTDReqQryNetMonitorDeviceTaskField> &pkgs = pkgBuf[
				qryfield.ObjectID.getValue()];

			for (int i = 0, size = pkgs.size(); i < size && dbTmpRst; i++)
			{
				dbTmpRst = AddDeviceTaskItem2DB(pFTDCPackage, pkgs[i], id);
			}

			qryfield.OperationType = OT_UPDATE;
		}

		qryfield.DefParamChain = "";	//清空DefParamChain，减少网络流量
				//// 通知各个服务端
		if (dbTmpRst)
		{
			// 发送RSP
			CFTDRspQryNetMonitorDeviceTaskField rspfield;
			CopyRspQryNetMonitorDeviceTaskEntity(&rspfield, &qryfield);
			SEND_RSP(
				NetMonitorDeviceTask,
				pSession,
				pFTDCPackage,
				&m_pkgSend,
				rspfield);

			//NotifyAllSession(&m_pkgSend);
		}

		pkgBuf.clear();
		dbResult = dbTmpRst;
	}

	if (dbResult)
	{
		CCommonFTDRsp::Instance()->SendSuccRsp(
				pSession,
				&m_pkgSend,
				pFTDCPackage,
				FTD_TID_RspQryNetMonitorDeviceTaskTopic);
	}
	else
	{
		CCommonFTDRsp::Instance()->SendLastErroRsp(
				pSession,
				&m_pkgSend,
				pFTDCPackage,
				FTD_TID_RspQryNetMonitorDeviceTaskTopic);
	}
}

typedef struct
{
	CFTDReqQryEventDescriptionField *reqField;
	CFTDCPackage *reqPkg;
	CFTDCPackage *rspPkg;
	CFTDCSession *session;
} QueryEventDes;

static void QueryEventDescription(SACommand &records, void *data)
{
	assert(data);

	QueryEventDes *pdata = (QueryEventDes *)data;

	CFTDRspQryEventDescriptionField	rsp;
	//rsp.EventDesID = records.Field("EventDesID").asString().TrimRight();
	//str.TrimRight(" ");
	//string str_return_value = str;
	//int nReadValue=0;
	//for (int nIndex=0; nIndex!=str_return_value.size(); ++nIndex)
	//{
	//	nReadValue = nReadValue*10 + str_return_value.at(nIndex)-48;
	//}
	//char ch_value[5]={'\0'};
	//char*p = (char*)&nReadValue;
	//ch_value[0] = *p;
	//ch_value[1] = *(p+1);
	//ch_value[2] = *(p+2);
	//ch_value[3] = *(p+3);

	// 填充索引并将索引返回到客户端
	rsp.EventDesID = records.Field("EventDesID").asString();
	rsp.UserName = records.Field("UserName").asString();
	rsp.MonDate = records.Field("MonDate").asString();
	rsp.MonTime = records.Field("MonTime").asString();
	rsp.EventDes = records.Field("EventDes").asString();
	
	FTD_RSP(EventDescription) rspField;
	COPY_FTD_RSP_ENTITY(EventDescription, &rspField, &rsp);
	SEND_RSP(
		EventDescription,
		pdata->session,
		pdata->reqPkg,
		pdata->rspPkg,
		rspField);

	//AddRspWithField<CFTDRspQryEventDescriptionField>
	//(
	//	pdata->rspPkg, &rsp, pdata->session, pdata->reqPkg,
	//	FTD_TID_RspQryNetMonitorTaskObjectSetTopic
	//);
}

time_t stringTOtime_t(char * szTime)
{
	struct tm tm1;
	time_t time1;
	int i=sscanf(szTime,"%d%d%d%d%d%d%d%d" ,     
		&(tm1.tm_year), 
		&(tm1.tm_mon), 
		&(tm1.tm_mday),
		&(tm1.tm_hour),
		&(tm1.tm_min),
		&(tm1.tm_sec));
	//cout<<"i= "<<i<<endl;

	tm1.tm_year -= 1900;
	tm1.tm_mon --;
	tm1.tm_isdst=-1;

	time1 = mktime(&tm1);
	//cout<<"time= "<<time1<<endl;
	return time1;

}

void CFrontServer::OnReqQryEventDescriptionTopic( CFTDCPackage *pFTDCPackage, CFTDCSession *pSession )
{
	CFTDReqQryEventDescriptionField field;
	memset(&field, 0, sizeof(CFTDReqQryEventDescriptionField));
	
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field)<0)
	{
		return;
	}

	// 添加记录
	if (field.EventDesID=="")
	{
		if (field.MonDate=="" || field.MonTime=="")
		{
			return;
		}
		string str_event_date(field.MonDate);
		string str_event_time(field.MonTime);
		if (str_event_date.size()!=8 || str_event_time.size()!=8)	return;
		
		str_event_date = str_event_date.substr(0,4)+" "+str_event_date.substr(4,2)+" "+str_event_date.substr(6,2)+" ";
		int find_count = 0;
		while( 1 )
		{
			int nPos = str_event_time.find_first_of( ':' );
			if ( nPos != string::npos )
			{
				++find_count;
				str_event_time = str_event_time.substr( 0 , nPos )+ " " + str_event_time.substr( nPos + 1 , -1 );
			}
			else
				break;
		}
		if (find_count!=2)	return;
		
		string str_origin_date_time("2010 1 1 0 0 0");
		string str_event_date_time(str_event_date+str_event_time);
		char ch_origin_date_time[100],ch_event_date_time[100];
		strcpy(ch_origin_date_time,str_origin_date_time.c_str());
		strcpy(ch_event_date_time,str_event_date_time.c_str());
		time_t time1,time2;
		time1=stringTOtime_t(ch_origin_date_time);
		time2=stringTOtime_t(ch_event_date_time);
		double diff_min=difftime(time2,time1)/(60*6);	// 没隔6分钟产生一个种子
		if (g_EventTimeIndex!=(int)diff_min)
		{
			g_EventTimeIndex = diff_min;
			g_EventIDIndex = 0;
		}
		else
		{
			g_EventIDIndex++;
		}
		int nEventLibID = g_EventTimeIndex*1000+g_EventIDIndex;
		
		string str_event_id;
		while(nEventLibID)
		{
			char ch_value = nEventLibID%10+48;
			str_event_id = ch_value + str_event_id;
			nEventLibID = nEventLibID/10;
		}
		field.EventDesID = str_event_id.c_str();
		
		//char ch_value[5]={'\0'};
		//char*p = (char*)&nEventLibID;
		//ch_value[0] = *p;
		//ch_value[1] = *(p+1);
		//ch_value[2] = *(p+2);
		//ch_value[3] = *(p+3);

		// 填充索引并将索引返回到客户端
		//field.EventDesID = ch_value;
		FTD_RSP(EventDescription) rspField;
		COPY_FTD_RSP_ENTITY(EventDescription, &rspField, &field);
		SEND_RSP(
			EventDescription,
			pSession,
			pFTDCPackage,
			&m_pkgSend,
			rspField);
			
		//int nReadValue(0);
		//memcpy(&nReadValue, field.EventDesID, sizeof(int));
			
		// 重置EventDesID并将其存入数据库
		//string str_event_id;
		//while(nEventLibID)
		//{
		//	char ch_value = nEventLibID%10+48;
		//	str_event_id = ch_value + str_event_id;
		//	nEventLibID = nEventLibID/10;
		//}
		//field.EventDesID = str_event_id.c_str();
		bool dbResult = false;
		{
			CFtdData wrappedObj(
				&field,
				&CFTDReqQryEventDescriptionField::m_Describe);
			dbResult = m_dbHandler.InsertRecord("t_SysEventDescrip", &wrappedObj);
		}
		// 成功入库将数据传回front
		//if (dbResult)
		{
			// 通知到其他所有的front
			//NotifyAllSession(&m_pkgSend);
			//m_pkgSend.PreparePackage(
			//			FTD_TID_RspQryEventDescriptionTopic,
			//			FTDC_CHAIN_LAST,
			//			FTD_VERSION);
			//pSession->SendRequestPackage(&m_pkgSend);
		}
		//else
		{
			// log
			LOG_ERROR(
				"Insert NetMonitorDeviceTask failed! recored may be uncomplete!");
		}
	}
	else	// 查询记录
	{	
		//int nReadValue(0);
		//memcpy(&nReadValue, field.EventDesID, sizeof(int));
		
		//string str_qry_event_id;
		//while(nReadValue)
		//{
		//	char ch_value = nReadValue%10+48;
		//	str_qry_event_id = ch_value + str_qry_event_id;
		//	nReadValue = nReadValue/10;
		//}
		string str_field(field.EventDesID);
		for (int nIndex=0; nIndex!=str_field.size(); ++nIndex)
		{
			if (str_field.at(nIndex)==' ') continue;
			if (str_field.at(nIndex)<'0' || str_field.at(nIndex)>'9')
			{
				return;
			}
		}
		char buffer[1024]={'\0'};
		sprintf(buffer,"select * from t_SysEventDescrip where EventDesID = %s ", field.EventDesID.getValue());
		string conditionSql(buffer);

		QueryEventDes data;
		data.reqField = &field;
		data.reqPkg = pFTDCPackage;
		data.rspPkg = &m_pkgSend;
		data.session = pSession;

		m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryEventDescriptionTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);
		m_dbHandler.SearchRecord(
			conditionSql,
			QueryEventDescription,
			&data);
		LogPkg(&m_pkgSend, g_bufferLogger, g_traceLog);
		m_pkgSend.PreparePackage(
				FTD_TID_RspQryEventDescriptionTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		pSession->SendRequestPackage(&m_pkgSend);
	}
}
