/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CStatusSubscriber.cpp
///@brief	实现了订阅交易流水处理消息的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
#include "CStatusSubscriber.h"
#include "FrontServer.h"
#include "CPerformanceAnalyze.h"
#include <iostream>
using namespace std;

extern list<EventSubInfo> g_EventSubList;

extern CListSessionArray *g_pListSessionArray;
extern list<CFTDCSession *> g_mListAllSession;
extern CDataCenterManage *g_pDataCenterManage;

extern char g_mFlowPath[200];
extern map<int, int> g_SubcriberMap;
extern int	g_FrontRange;

//key:targetip
extern map<string, CFTDRtnNetLocalPingResultInfoField>	g_localpingresult;

//key:sourceip_targetip
extern map<string, CFTDRtnNetRomotePingResultInfoField> g_remotepingresult;

#ifdef PACKAGE_OUTPUT
extern CLogger	*g_pClnPackOutput;				// 数据包输出到文件
extern CLogger	*g_pQryPackOutput;
extern CLogger	*g_pEntPackOutput;
extern CLogger	*g_pFibPackOutput;
#endif
extern CTimeType theTime;
extern CDateType theDate;

extern map<int, map<int, CFTDRspQryNetMonitorTaskStatusResultField> >
	g_taskOperTimes;

///网络设备连接
extern map<CTypeObjectIDType, list<CTypeObjectIDType> > g_NetLinkMap;

// add by cao.ning 网络性能处理对象
extern CPerformanceAnalyzer* g_pPerformanceAnalyzer;

CStatusSubscriber::CStatusSubscriber(int nFlowSeq)
{
	m_nFlowSeq = nFlowSeq;

	char buffer[30];
	sprintf(buffer, "eventStatusFlow%d", m_nFlowSeq - 1);
	m_pFlow = new CCachedFileFlow(buffer, g_mFlowPath, true, 100, 32 * 1024);
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 1024);
	m_reload = false;
	printf("----- CStatusSubscriber Reload Begin -----\n");
	fflush(stdout);
	ReLoad();
	printf("-----  CStatusSubscriber Reload End  -----\n");
	fflush(stdout);
}

CStatusSubscriber::~CStatusSubscriber(void)
{
	delete m_pFlow;
}

void CStatusSubscriber::SetCommPhaseNo(WORD wCommPhaseNo)
{
}

WORD CStatusSubscriber::GetSequenceSeries(void) //流编号
{
	return m_nFlowSeq;
}

DWORD CStatusSubscriber::GetReceivedCount(void) //收到的包个数
{
	////printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	//	printf("\t Flow %d count %d\n", m_nFlowSeq, m_pFlow->GetCount());
	return m_pFlow->GetCount();
}

void CStatusSubscriber::HandleMessage(CFTDCPackage *pFTDCPackage)
{
	//	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	//	printf("\tCStatusSubscriber::HandleMessage\n");
#ifdef PACKAGE_OUTPUT
	pFTDCPackage->OutputHeader(g_pEntPackOutput);
	FTDC_DEBUG_BODY(pFTDCPackage->GetTID(), pFTDCPackage, g_pEntPackOutput);
#endif
	switch (pFTDCPackage->GetTID())
	{
		case FTD_TID_RtnObjectAttrTopic:
			OnRtnObjectAttrTopic(pFTDCPackage);

			// 收到一个指标通告，更新性能分析中的数据
			if (g_pPerformanceAnalyzer)
			{
				g_pPerformanceAnalyzer->OnRtnObjectAttrTopic(pFTDCPackage);
			}
			
			break;

		//case FTD_TID_RtnNetObjectAttrTopic:				OnRtnNetObjectAttrTopic(pFTDCPackage);break;
		case FTD_TID_RtnSyslogInfoTopic:
			OnRtnSyslogInfoTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnUserInfoTopic:
			OnRtnUserInfoTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnOnlineUserInfoTopic:
			OnRtnOnlineUserInfoTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnWarningEventTopic:
			OnRtnWarningEventTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnTopCpuInfoTopic:
			OnRtnTopCpuInfoTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnTopMemInfoTopic:
			OnRtnTopMemInfoTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnTopProcessInfoTopic:
			OnRtnTopProcessInfoTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnFileSystemInfoTopic:
			OnRtnFileSystemInfoTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnNetworkInfoTopic:
			OnRtnNetworkInfoTopic(pFTDCPackage);
			break;
		case FTD_TID_RspQryHostEnvTopic:
			OnRspQryHostEnvTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnUpdateSysConfigTopic:
			OnRtnUpdateSysConfigTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnSyslogEventTopic:
			OnRtnSyslogEventTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnWebAppInfoTopic:
			OnRtnWebAppInfoTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnMemPoolInfoTopic:
			OnRtnMemPoolInfoTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnConnectorInfoTopic:
			OnRtnConnectorInfoTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnDBQueryTopic:
			OnRtnDbQueryTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnWarningQueryTopic:
			OnRtnWarningQueryTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnNetDeviceLinkedTopic:
			OnRtnNetDeviceLinkTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnNetMonitorTaskResultTopic:
			OnRtnNetMonitorTaskResultTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnNetPartyLinkStatusInfoTopic:
			OnRtnNetPartyLinkStatusInfoTopic(pFTDCPackage);
			break;

		//Added by Henchi, 20100610
		case FTD_TID_RtnWarningActiveChange:
			OnRtnWarningActiveChange(pFTDCPackage);
			break;
		case FTD_TID_RtnNetAreaTopic:
			OnRtnNetAreaTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnNetLocalPingResultInfoTopic:
			OnRtnLocalPingResultTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnNetRomotePingResultInfoTopic:
			OnRtnRemotePingResultTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnNetRoomTopic:
			{
				CFTDRtnNetRoomField tfield;
				memset(&tfield, 0, sizeof(tfield));

				//广播给所有客户端
				if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &tfield) > 0)
				{
					m_pkgSend.PreparePackage(
							FTD_TID_RtnNetRoomTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
					FTDC_ADD_FIELD(&m_pkgSend, &tfield);

					list<CFTDCSession *>::iterator	c_it;
					for (c_it = g_mListAllSession.begin();
						 c_it != g_mListAllSession.end();
						 c_it++)
					{
						(*c_it)->SendRequestPackage(&m_pkgSend);
						m_pkgSend.Pop(FTDCHLEN);
					}
				}
			}

			break;
		case FTD_TID_RtnDiskIOTopic:
			OnRtnDiskIOInfoTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnRouterInfoTopic:
			OnRtnRouteInfoTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnStatInfoTopic:
			OnRtnStatInfoTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnTradeUserLoginInfoTopic:
			OnRtnTradeUserLoginInfo(pFTDCPackage);
			break;
		default:
			break;
	}

	pFTDCPackage->Push(FTDCHLEN);
	m_pFlow->Append(pFTDCPackage->Address(), pFTDCPackage->Length());
}

void CStatusSubscriber::OnRtnTradeUserLoginInfo(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnTradeUserLoginInfoField	fieldInfo;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
		&CFTDRtnTradeUserLoginInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);

		CWriteableSysTradeUserLoginInfo mdbfield;
		CopySysTradeUserLoginInfoEntity(&mdbfield, &fieldInfo);
		pMemoryDB->m_SysTradeUserLoginInfoFactory->add(&mdbfield);

		///清理:
		//CSysMdbNetPartyLinkStatusInfo	*oldField = pMemoryDB->
		//	m_SysTradeUserLoginInfoFactory->sta(
		//	theDate,
		//	theTime);
		//while (oldField)
		//{
		//	CSysMdbNetPartyLinkStatusInfo	*tmpField = pMemoryDB->
		//		m_SysTradeUserLoginInfoFactory->findNextByTime();
		//	pMemoryDB->m_SysTradeUserLoginInfoFactory->remove(oldField);
		//	oldField = tmpField;
		//}

		//pMemoryDB->m_SysTradeUserLoginInfoFactory->endFindByTime();

		if (!m_reload)
		{
			m_pkgSend.PreparePackage(
				FTD_TID_RtnTradeUserLoginInfoTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);

			list<CFTDCSession *>::iterator	it;
			for (it = g_mListAllSession.begin();
				it != g_mListAllSession.end();
				it++)
			{
				(*it)->SendRequestPackage(&m_pkgSend);
				m_pkgSend.Pop(FTDCHLEN);
			}
		}

		itor.Next();
	}
}

//Added by Henchi, 20100610
void CStatusSubscriber::OnRtnWarningActiveChange(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnWarningActiveChangeField field;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnWarningActiveChangeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		// 切换当前内存中对象告警状态
		g_pDataCenterManage->UpDateObjectIdStatus(
				(char *)field.ObjectID.getValue(),
				(int)field.WarningActive);

		// Rtn包转发到各客户端系统
		if (!m_reload)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnWarningActiveChange,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &field);

			list<CFTDCSession *>::iterator	it;
			for (it = g_mListAllSession.begin();
				 it != g_mListAllSession.end();
				 it++)
			{
				(*it)->SendRequestPackage(&m_pkgSend);
				m_pkgSend.Pop(FTDCHLEN);
			}
		}

		itor.Next();
	}
}

//Added end
void CStatusSubscriber::OnRtnLocalPingResultTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnNetLocalPingResultInfoField	fieldInfo;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnNetLocalPingResultInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);

		g_localpingresult[fieldInfo.TarIPADDR.getValue()] = fieldInfo;

		if (!m_reload)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnNetLocalPingResultInfoTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);

			list<CFTDCSession *>::iterator	it;
			for (it = g_mListAllSession.begin();
				 it != g_mListAllSession.end();
				 it++)
			{
				(*it)->SendRequestPackage(&m_pkgSend);
				m_pkgSend.Pop(FTDCHLEN);
			}
		}

		itor.Next();
	}
}

void CStatusSubscriber::OnRtnRemotePingResultTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnNetRomotePingResultInfoField fieldInfo;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnNetRomotePingResultInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);

		string	keystr = fieldInfo.SouIPADDR.getValue();
		keystr += fieldInfo.TarIPADDR.getValue();

		g_remotepingresult[keystr] = fieldInfo;

		if (!m_reload)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnNetRomotePingResultInfoTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);

			list<CFTDCSession *>::iterator	it;
			for (it = g_mListAllSession.begin();
				 it != g_mListAllSession.end();
				 it++)
			{
				(*it)->SendRequestPackage(&m_pkgSend);
				m_pkgSend.Pop(FTDCHLEN);
			}
		}

		itor.Next();
	}
}

void CStatusSubscriber::OnRtnTopCpuInfoTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnTopCpuInfoField	fieldCPUInfo;
	list<int> iList;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnTopCpuInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldCPUInfo);
#ifdef PRINT_DEBUG
		printf(
			"++++CPU:%s,%s,%s,%f,%f,%f,%f,%f,%f,%f,%f,%f\n",
			(const char *)fieldCPUInfo.MonTime,
			(const char *)fieldCPUInfo.HostName,
			(const char *)fieldCPUInfo.CPU,
			(const double)fieldCPUInfo.LOAD,
			(const double)fieldCPUInfo.USER,
			(const double)fieldCPUInfo.NICE,
			(const double)fieldCPUInfo.SYS,
			(const double)fieldCPUInfo.IDLE,
			(const double)fieldCPUInfo.BLOCK,
			(const double)fieldCPUInfo.SWAIT,
			(const double)fieldCPUInfo.INTR,
			(const double)fieldCPUInfo.SSYS);
#endif

		CWriteableSysMdbTopCpuInfo	mdbfield;
		mdbfield.HostName = g_StringIdMap.getStringId(
				fieldCPUInfo.HostName.getValue());
		mdbfield.CPU = fieldCPUInfo.CPU;
		mdbfield.LOAD = fieldCPUInfo.LOAD;
		mdbfield.USER = fieldCPUInfo.USER;
		mdbfield.NICE = fieldCPUInfo.NICE;
		mdbfield.SYS = fieldCPUInfo.SYS;
		mdbfield.IDLE = fieldCPUInfo.IDLE;
		mdbfield.BLOCK = fieldCPUInfo.BLOCK;
		mdbfield.SWAIT = fieldCPUInfo.SWAIT;
		mdbfield.INTR = fieldCPUInfo.INTR;
		mdbfield.SSYS = fieldCPUInfo.SSYS;
		mdbfield.MonDate = fieldCPUInfo.MonDate;
		mdbfield.MonTime = fieldCPUInfo.MonTime;
		if (find(iList.begin(), iList.end(), mdbfield.HostName) == iList.end())
		{
			CSysMdbTopCpuInfo *oldfield = pMemoryDB->m_SysMdbTopCpuInfoFactory->
				startFindByDataDelete(mdbfield.HostName, theDate, theTime);
			while (oldfield)
			//if(oldfield)
			{
				CSysMdbTopCpuInfo *tmpfield = pMemoryDB->
					m_SysMdbTopCpuInfoFactory->findNextByDataDelete();
				pMemoryDB->m_SysMdbTopCpuInfoFactory->remove(oldfield);
				oldfield = tmpfield;
			}

			pMemoryDB->m_SysMdbTopCpuInfoFactory->endFindByDataDelete();
			iList.push_back(mdbfield.HostName);

			map<int, int>::iterator it = g_SubcriberMap.find(
					(int)(mdbfield.HostName));
			if (it == g_SubcriberMap.end())
			{
				g_SubcriberMap[(int)(mdbfield.HostName)] = 2;
			}
		}

		pMemoryDB->m_SysMdbTopCpuInfoFactory->add(&mdbfield, NULL);

		if (!m_reload)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnTopCpuInfoTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &fieldCPUInfo);
			g_pListSessionArray->SendPackage(
					&m_pkgSend,
					fieldCPUInfo.HostName.getValue());
		}

		itor.Next();
	}
}

void CStatusSubscriber::OnRtnFileSystemInfoTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnFileSystemInfoField	fieldDFInfo;
	list<int> iList;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnFileSystemInfoField::m_Describe);

	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldDFInfo);
#ifdef PRINT_DEBUG
		printf("FILESYSTEM:%s\t", (const char *)fieldDFInfo.FILESYSTEM);
		printf("DISKTOTAL :%ld Mb\t", (const long)fieldDFInfo.SIZE);
		printf("DISKUSED  :%ld Mb\t", (const long)fieldDFInfo.USED);
		printf("DISKFREE  :%ld Mb\t", (const long)fieldDFInfo.AVAIL);
		printf("DISKUSAGE :%2.4f %%\t", (const float)fieldDFInfo.pUSERD);
		printf("NODETOTAL :%ld\t", (const long)fieldDFInfo.ISIZE);
		printf("NODEUSED  :%ld\t", (const long)fieldDFInfo.IUSED);
		printf("NODEFREE  :%ld\t", (const long)fieldDFInfo.IFREE);
		printf("NODEUSAGE :%2.4f %%\t", (const float)fieldDFInfo.pIUSED);
		printf("MOUNTON   :%s\n", (const char *)fieldDFInfo.MountedOn);
#endif

		CWriteableSysMdbFileSystemInfo	mdbfield;
		mdbfield.HostName = g_StringIdMap.getStringId(
				fieldDFInfo.HostName.getValue());
		mdbfield.MonTime = fieldDFInfo.MonTime;
		mdbfield.MonDate = fieldDFInfo.MonDate;
		mdbfield.FILESYSTEM = fieldDFInfo.FILESYSTEM;
		mdbfield.SIZE = fieldDFInfo.SIZE;
		mdbfield.USED = fieldDFInfo.USED;
		mdbfield.AVAIL = fieldDFInfo.AVAIL;
		mdbfield.pUSERD = fieldDFInfo.pUSERD;
		mdbfield.ISIZE = fieldDFInfo.ISIZE;
		mdbfield.IUSED = fieldDFInfo.IUSED;
		mdbfield.IFREE = fieldDFInfo.IFREE;
		mdbfield.pIUSED = fieldDFInfo.pIUSED;
		mdbfield.MountedOn = fieldDFInfo.MountedOn;

		if (find(iList.begin(), iList.end(), mdbfield.HostName) == iList.end())
		{
			///先找到最后一条的时间
			CSysMdbFileSystemInfo *oldfield = pMemoryDB->
				m_SysMdbFileSystemInfoFactory->startFindByDsc(
						mdbfield.HostName);

			///如果不相等，即来的是新时间的数据，则删除原来的
			if (oldfield)
			{
				if (mdbfield.MonDate != oldfield->MonDate
				||	mdbfield.MonTime != oldfield->MonTime)
				{
					while (oldfield)
					//if(oldfield)
					{
						CSysMdbFileSystemInfo *tmpfield = pMemoryDB->
							m_SysMdbFileSystemInfoFactory->findNextByDsc();
						pMemoryDB->m_SysMdbFileSystemInfoFactory->remove(
								oldfield);
						oldfield = tmpfield;
					}
				}
			}

			pMemoryDB->m_SysMdbFileSystemInfoFactory->endFindByDsc();
			iList.push_back(mdbfield.HostName);

			map<int, int>::iterator it = g_SubcriberMap.find(
					(int)(mdbfield.HostName));
			if (it == g_SubcriberMap.end())
			{
				g_SubcriberMap[(int)(mdbfield.HostName)] = 5;
			}
		}

		pMemoryDB->m_SysMdbFileSystemInfoFactory->add(&mdbfield, NULL);

		if (!m_reload)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnFileSystemInfoTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &fieldDFInfo);
			g_pListSessionArray->SendPackage(
					&m_pkgSend,
					fieldDFInfo.HostName.getValue());
		}

		itor.Next();
	}
}

///只保留某主机下面最新时间的进程信息:
void CStatusSubscriber::OnRtnTopProcessInfoTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnTopProcessInfoField	fieldPSInfo;
	list<int> iList;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnTopProcessInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldPSInfo);
#ifdef PRINT_DEBUG
		printf(
			"%s,%s,%d,%s,%d,%d,%d,%d,%s,%s,%f,%f,%s\n",
			(const char *)fieldPSInfo.CPU,
			(const char *)fieldPSInfo.TTY,
			(const int)fieldPSInfo.PID,
			(const char *)fieldPSInfo.USERNAME,
			(const int)fieldPSInfo.PRI,
			(const int)fieldPSInfo.NI,
			(const int)fieldPSInfo.SIZE,
			(const int)fieldPSInfo.RES,
			(const char *)fieldPSInfo.STATE,
			(const char *)fieldPSInfo.TIME,
			(const float)fieldPSInfo.pWCPU,
			(const float)fieldPSInfo.pCPU,
			(const char *)fieldPSInfo.COMMAND);
#endif

		CWriteableSysMdbTopProcessInfo	mdbfield;
		mdbfield.HostName = g_StringIdMap.getStringId(
				fieldPSInfo.HostName.getValue());
		mdbfield.MonTime = fieldPSInfo.MonTime;
		mdbfield.MonDate = fieldPSInfo.MonDate;
		mdbfield.CPU = fieldPSInfo.CPU;
		mdbfield.TTY = fieldPSInfo.TTY;
		mdbfield.PID = fieldPSInfo.PID;
		mdbfield.USERNAME = fieldPSInfo.USERNAME;
		mdbfield.PRI = fieldPSInfo.PRI;
		mdbfield.NI = fieldPSInfo.NI;
		mdbfield.SIZE = fieldPSInfo.SIZE;
		mdbfield.RES = fieldPSInfo.RES;
		mdbfield.STATE = fieldPSInfo.STATE;
		mdbfield.TIME = fieldPSInfo.TIME;
		mdbfield.pWCPU = fieldPSInfo.pWCPU;
		mdbfield.pCPU = fieldPSInfo.pCPU;
		mdbfield.COMMAND = fieldPSInfo.COMMAND;

		//		pMemoryDB->m_SysMdbTopProcessInfoFactory->add(&mdbfield,NULL);
		if (find(iList.begin(), iList.end(), mdbfield.HostName) == iList.end())
		{
			/*		
			///先找到最后一条的时间
			CSysMdbTopProcessInfo *oldfield =pMemoryDB->m_SysMdbTopProcessInfoFactory->startFindByDsc(mdbfield.HostName);
			///如果不相等，即来的是新时间的数据，则删除原来的
			if(oldfield)
			{
				if(!(mdbfield.MonDate ==oldfield->MonDate && mdbfield.MonTime ==oldfield->MonTime))
				{
					while(oldfield)
					//if(oldfield)
					{
						CSysMdbTopProcessInfo *tmpfield =pMemoryDB->m_SysMdbTopProcessInfoFactory->findNextByDsc();
						//不删除较早时间的数据
						//pMemoryDB->m_SysMdbTopProcessInfoFactory->remove(oldfield);
						oldfield =tmpfield;
					}
				}
			}
			pMemoryDB->m_SysMdbTopProcessInfoFactory->endFindByDsc();
*/
			iList.push_back(mdbfield.HostName);

			map<int, int>::iterator it = g_SubcriberMap.find(
					(int)(mdbfield.HostName));
			if (it == g_SubcriberMap.end())
			{
				g_SubcriberMap[(int)(mdbfield.HostName)] = 4;
			}
		}

		pMemoryDB->m_SysMdbTopProcessInfoFactory->add(&mdbfield, NULL);

		if (!m_reload)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnTopProcessInfoTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &fieldPSInfo);
			g_pListSessionArray->SendPackage(
					&m_pkgSend,
					fieldPSInfo.HostName.getValue());
		}

		itor.Next();
	}
}

void CStatusSubscriber::OnRtnTopMemInfoTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnTopMemInfoField	field;
	list<int> iList;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnTopMemInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CWriteableSysMdbTopMemInfo	mdbfield;
		mdbfield.HostName = g_StringIdMap.getStringId(
				field.HostName.getValue());
		mdbfield.ACTIVEREAL = field.ACTIVEREAL;
		mdbfield.ACTIVEVIRTUAL = field.ACTIVEVIRTUAL;
		mdbfield.FREE = field.FREE;
		mdbfield.MonDate = field.MonDate;
		mdbfield.MonTime = field.MonTime;
		mdbfield.TOTALREAL = field.TOTALREAL;
		mdbfield.TOTALVIRTUAL = field.TOTALVIRTUAL;
		if (find(iList.begin(), iList.end(), mdbfield.HostName) == iList.end())
		{
			CSysMdbTopMemInfo *oldfield = pMemoryDB->m_SysMdbTopMemInfoFactory->
				startFindByDataDelete(mdbfield.HostName, theDate, theTime);
			while (oldfield)
			//if(oldfield)
			{
				CSysMdbTopMemInfo *tmpfield = pMemoryDB->
					m_SysMdbTopMemInfoFactory->findNextByDataDelete();
				pMemoryDB->m_SysMdbTopMemInfoFactory->remove(oldfield);
				oldfield = tmpfield;
			}

			pMemoryDB->m_SysMdbTopMemInfoFactory->endFindByDataDelete();
			iList.push_back(mdbfield.HostName);

			map<int, int>::iterator it = g_SubcriberMap.find(
					(int)(mdbfield.HostName));
			if (it == g_SubcriberMap.end())
			{
				g_SubcriberMap[(int)(mdbfield.HostName)] = 3;
			}
		}

		pMemoryDB->m_SysMdbTopMemInfoFactory->add(&mdbfield, NULL);

		if (!m_reload)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnTopMemInfoTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &field);
			g_pListSessionArray->SendPackage(
					&m_pkgSend,
					field.HostName.getValue());
		}

		itor.Next();
	}
}

void CStatusSubscriber::OnRtnDiskIOInfoTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnDiskIOField	field;
	list<int> iList;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnDiskIOField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CWriteableSysMdbDiskIO	mdbfield;
		mdbfield.HostName = field.HostName.getValue();
		mdbfield.SubcriberID = g_StringIdMap.getStringId(
				field.HostName.getValue());
		mdbfield.MonDate = field.MonDate;
		mdbfield.MonTime = field.MonTime;
		mdbfield.PartName = field.PartName;
		mdbfield.ReadMerges = field.ReadMerges;
		mdbfield.WriteMerges = field.WriteMerges;
		mdbfield.ReadIOs = field.ReadIOs;
		mdbfield.WriteIOs = field.WriteIOs;
		mdbfield.ReadKBs = field.ReadKBs;
		mdbfield.WriteKBs = field.WriteKBs;
		mdbfield.SizeVal = field.SizeVal;
		mdbfield.QueueVal = field.QueueVal;
		mdbfield.Svc_t = field.Svc_t;
		mdbfield.Busy = field.Busy;
		if (find(
				iList.begin(),
			iList.end(),
			mdbfield.SubcriberID) == iList.end())
		{
			CSysMdbDiskIO *oldfield = pMemoryDB->m_SysMdbDiskIOFactory->
				startFindByDataDelete(mdbfield.SubcriberID, theDate, theTime);
			while (oldfield)
			//if(oldfield)
			{
				CSysMdbDiskIO *tmpfield = pMemoryDB->m_SysMdbDiskIOFactory->
					findNextByDataDelete();
				pMemoryDB->m_SysMdbDiskIOFactory->remove(oldfield);
				oldfield = tmpfield;
			}

			pMemoryDB->m_SysMdbDiskIOFactory->endFindByDataDelete();
			iList.push_back(mdbfield.SubcriberID);

			map<int, int>::iterator it = g_SubcriberMap.find(
					(int)(mdbfield.SubcriberID));
			if (it == g_SubcriberMap.end())
			{
				g_SubcriberMap[(int)(mdbfield.SubcriberID)] = 11;
			}
		}

		pMemoryDB->m_SysMdbDiskIOFactory->add(&mdbfield, NULL);

		if (!m_reload)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnDiskIOTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &field);
			g_pListSessionArray->SendPackage(
					&m_pkgSend,
					field.HostName.getValue());
		}

		itor.Next();
	}
}

void CStatusSubscriber::OnRtnRouteInfoTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnRouterInfoField	field;
	list<int> iList;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnRouterInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CWriteableSysMdbRouterInfo	mdbfield;

		mdbfield.HostName = field.HostName;
		mdbfield.SubcriberID = g_StringIdMap.getStringId(
				field.HostName.getValue());
		mdbfield.Dev = field.Dev;
		mdbfield.Destination = field.Destination;
		mdbfield.MonDate = field.MonDate;
		mdbfield.MonTime = field.MonTime;
		mdbfield.Gateway = field.Gateway;
		mdbfield.Mask = field.Mask;
		mdbfield.Flag = field.Flag;
		mdbfield.RefCnt = field.RefCnt;
		mdbfield.Use = field.Use;
		mdbfield.Metric = field.Metric;
		mdbfield.Mtu = field.Mtu;
		mdbfield.Win = field.Win;
		mdbfield.Rtt = field.Rtt;

		if (find(
				iList.begin(),
			iList.end(),
			mdbfield.SubcriberID) == iList.end())
		{
			CSysMdbRouterInfo *oldfield = pMemoryDB->m_SysMdbRouterInfoFactory->
				startFindByDataDelete(mdbfield.SubcriberID, theDate, theTime);
			while (oldfield)
			//if(oldfield)
			{
				CSysMdbRouterInfo *tmpfield = pMemoryDB->
					m_SysMdbRouterInfoFactory->findNextByDataDelete();
				pMemoryDB->m_SysMdbRouterInfoFactory->remove(oldfield);
				oldfield = tmpfield;
			}

			pMemoryDB->m_SysMdbRouterInfoFactory->endFindByDataDelete();
			iList.push_back(mdbfield.SubcriberID);

			map<int, int>::iterator it = g_SubcriberMap.find(
					(int)(mdbfield.SubcriberID));
			if (it == g_SubcriberMap.end())
			{
				g_SubcriberMap[(int)(mdbfield.SubcriberID)] = 12;
			}
		}

		pMemoryDB->m_SysMdbRouterInfoFactory->add(&mdbfield, NULL);

		if (!m_reload)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnRouterInfoTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &field);
			g_pListSessionArray->SendPackage(
					&m_pkgSend,
					field.HostName.getValue());
		}

		itor.Next();
	}
}

void CStatusSubscriber::OnRtnStatInfoTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnStatInfoField field;
	list<int> iList;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnStatInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CWriteableSysMdbStatInfo mdbfield;

		mdbfield.HostName = field.HostName;
		mdbfield.SubcriberID = g_StringIdMap.getStringId(
				field.HostName.getValue());
		mdbfield.MonDate = field.MonDate;
		mdbfield.MonTime = field.MonTime;
		mdbfield.ProcRun = field.ProcRun;
		mdbfield.ProcBlk = field.ProcBlk;
		mdbfield.SwapIn = field.SwapIn;
		mdbfield.SwapOut = field.SwapOut;
		mdbfield.BlockIn = field.BlockIn;
		mdbfield.BlockOut = field.BlockOut;
		mdbfield.Inter = field.Inter;
		mdbfield.Context = field.Context;
		mdbfield.CPUUser = field.CPUUser;
		mdbfield.CPUSys = field.CPUSys;
		mdbfield.CPUIdle = field.CPUIdle;
		mdbfield.CPUIOWait = field.CPUIOWait;
		mdbfield.CPUSteal = field.CPUSteal;

		if (find(
				iList.begin(),
			iList.end(),
			mdbfield.SubcriberID) == iList.end())
		{
			CSysMdbStatInfo *oldfield = pMemoryDB->m_SysMdbStatInfoFactory->
				startFindByDataDelete(mdbfield.SubcriberID, theDate, theTime);
			while (oldfield)
			//if(oldfield)
			{
				CSysMdbStatInfo *tmpfield = pMemoryDB->m_SysMdbStatInfoFactory->
					findNextByDataDelete();
				pMemoryDB->m_SysMdbStatInfoFactory->remove(oldfield);
				oldfield = tmpfield;
			}

			pMemoryDB->m_SysMdbStatInfoFactory->endFindByDataDelete();
			iList.push_back(mdbfield.SubcriberID);

			map<int, int>::iterator it = g_SubcriberMap.find(
					(int)(mdbfield.SubcriberID));
			if (it == g_SubcriberMap.end())
			{
				g_SubcriberMap[(int)(mdbfield.SubcriberID)] = 13;
			}
		}

		pMemoryDB->m_SysMdbStatInfoFactory->add(&mdbfield, NULL);

		if (!m_reload)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnStatInfoTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &field);
			g_pListSessionArray->SendPackage(
					&m_pkgSend,
					field.HostName.getValue());
		}

		itor.Next();
	}
}

void CStatusSubscriber::ReLoad(void)
{
	m_reload = true;

	CFlowReader eventFlowReader;
	eventFlowReader.AttachFlow(m_pFlow, 0);

	CFTDCPackage *pFTDCPackage = new CFTDCPackage;
	pFTDCPackage->ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	for (;;)
	{
		pFTDCPackage->Allocate(FTDC_PACKAGE_MAX_SIZE + FTDCHLEN);
		if (!eventFlowReader.GetNext(pFTDCPackage))
		{
			break;
		}

		switch (pFTDCPackage->GetTID())
		{
			case FTD_TID_RtnObjectAttrTopic:
				OnRtnObjectAttrTopic(pFTDCPackage);
				break;
			case FTD_TID_RtnSyslogInfoTopic:
				OnRtnSyslogInfoTopic(pFTDCPackage);
				break;
			case FTD_TID_RtnUserInfoTopic:
				OnRtnUserInfoTopic(pFTDCPackage);
				break;
			case FTD_TID_RtnOnlineUserInfoTopic:
				OnRtnOnlineUserInfoTopic(pFTDCPackage);
				break;
			case FTD_TID_RtnWarningEventTopic:
				OnRtnWarningEventTopic(pFTDCPackage);
				break;
			case FTD_TID_RtnTopCpuInfoTopic:
				OnRtnTopCpuInfoTopic(pFTDCPackage);
				break;
			case FTD_TID_RtnTopMemInfoTopic:
				OnRtnTopMemInfoTopic(pFTDCPackage);
				break;
			case FTD_TID_RtnTopProcessInfoTopic:
				OnRtnTopProcessInfoTopic(pFTDCPackage);
				break;
			case FTD_TID_RtnFileSystemInfoTopic:
				OnRtnFileSystemInfoTopic(pFTDCPackage);
				break;
			case FTD_TID_RtnNetworkInfoTopic:
				OnRtnNetworkInfoTopic(pFTDCPackage);
				break;
			case FTD_TID_RspQryHostEnvTopic:
				OnRspQryHostEnvTopic(pFTDCPackage);
				break;
			case FTD_TID_RtnUpdateSysConfigTopic:
				OnRtnUpdateSysConfigTopic(pFTDCPackage);
				break;
			case FTD_TID_RtnSyslogEventTopic:
				OnRtnSyslogEventTopic(pFTDCPackage);
				break;
			case FTD_TID_RtnWebAppInfoTopic:
				OnRtnWebAppInfoTopic(pFTDCPackage);
				break;
			case FTD_TID_RtnMemPoolInfoTopic:
				OnRtnMemPoolInfoTopic(pFTDCPackage);
				break;
			case FTD_TID_RtnConnectorInfoTopic:
				OnRtnConnectorInfoTopic(pFTDCPackage);
				break;
			case FTD_TID_RtnDBQueryTopic:
				OnRtnDbQueryTopic(pFTDCPackage);
				break;
			case FTD_TID_RtnNetMonitorTaskResultTopic:
				OnRtnNetMonitorTaskResultTopic(pFTDCPackage);
				break;
			case FTD_TID_RtnDiskIOTopic:
				OnRtnDiskIOInfoTopic(pFTDCPackage);
				break;
			case FTD_TID_RtnRouterInfoTopic:
				OnRtnRouteInfoTopic(pFTDCPackage);
				break;
			case FTD_TID_RtnStatInfoTopic:
				OnRtnStatInfoTopic(pFTDCPackage);
				break;
		}
	}

	m_reload = false;
}

void CStatusSubscriber::OnRspQryHostEnvTopic(CFTDCPackage *pFTDCPackage)
{
	int iCount = 0;

	CFTDRspQryHostEnvCommonField fieldCommonInfo;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRspQryHostEnvCommonField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldCommonInfo);
#ifdef PRINT_DEBUG
		printf(
			"HostModel :%s\nMainMemory:%ld\nProcessors:%ld\nOsMode    :%ld\n",
			(const char *)fieldCommonInfo.HostModel,
			(const long)fieldCommonInfo.MainMemory,
			(const long)fieldCommonInfo.Processors,
			(const long)fieldCommonInfo.OsMode);
#endif
		ADDENVPACKAGETOMDB(Common) itor.Next();
		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())
		{
			break;
		}
	}

	iCount = 0;

	CFTDRspQryHostEnvLanField fieldLanInfo;
	itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRspQryHostEnvLanField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldLanInfo);
#ifdef PRINT_DEBUG
		printf(
			"Lan Hardwares(%02d):  %s    %s\n",
			iCount++,
			(const char *)fieldLanInfo.LanHardwareID,
			(const char *)fieldLanInfo.LanHardwareValue);
#endif
		ADDENVPACKAGETOMDB(Lan) itor.Next();
		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())
		{
			break;
		}
	}

	iCount = 0;

	CFTDRspQryHostEnvStorageField fieldStorageInfo;
	itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRspQryHostEnvStorageField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldStorageInfo);
#ifdef PRINT_DEBUG
		printf(
			"Storage Devices(%02d):  %-30s%-15s%s\n",
			iCount++,
			(const char *)fieldStorageInfo.StorageDev,
			(const char *)fieldStorageInfo.HWPath,
			(const char *)fieldStorageInfo.Interface);
#endif
		ADDENVPACKAGETOMDB(Storage) itor.Next();
		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())
		{
			break;
		}
	}

	iCount = 0;

	CFTDRspQryHostEnvIOField fieldIOInfo;
	itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRspQryHostEnvIOField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldIOInfo);
#ifdef PRINT_DEBUG
		printf(
			"I/O Interfaces(%02d):  %-10s%-10s%-15s%s\n",
			iCount++,
			(const char *)fieldIOInfo.IoClass,
			(const char *)fieldIOInfo.H_WPath,
			(const char *)fieldIOInfo.IoDriver,
			(const char *)fieldIOInfo.IoDescription);
#endif
		ADDENVPACKAGETOMDB(IO) itor.Next();
		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())
		{
			break;
		}
	}

	iCount = 0;

	CFTDRspQryHostEnvFSField fieldFSInfo;
	itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRspQryHostEnvFSField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldFSInfo);
#ifdef PRINT_DEBUG
		printf(
			"File Systems(%02d):  %-30s%-15s%-10ld%s\n",
			iCount++,
			(const char *)fieldFSInfo.LVMDeviceFile,
			(const char *)fieldFSInfo.MountPoint,
			(const long)fieldFSInfo.FSsize,
			(const char *)fieldFSInfo.FSType);
#endif
		ADDENVPACKAGETOMDB(FS) itor.Next();
		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())
		{
			break;
		}
	}

	iCount = 0;

	CFTDRspQryHostEnvSwapField	fieldSwapInfo;
	itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRspQryHostEnvSwapField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldSwapInfo);
#ifdef PRINT_DEBUG
		printf(
			"Swap Partitions(%02d):  %-10s%-10ld%-10ld%s\n",
			iCount++,
			(const char *)fieldSwapInfo.type,
			(const long)fieldSwapInfo.size,
			(const long)fieldSwapInfo.priority,
			(const char *)fieldSwapInfo.location);
#endif
		ADDENVPACKAGETOMDB(Swap) itor.Next();
		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())
		{
			break;
		}
	}

	CFTDRspQryHostEnvLanCfgField fieldLanCfgInfo;
	itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRspQryHostEnvLanCfgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldLanCfgInfo);
#ifdef PRINT_DEBUG
		printf(
			"\nLanName   :%s\nIP-Address:%s\nSubnetMask:%s\n",
			(const char *)fieldLanCfgInfo.LanName,
			(const char *)fieldLanCfgInfo.IpAddress,
			(const char *)fieldLanCfgInfo.IpMask);
#endif
		ADDENVPACKAGETOMDB(LanCfg) itor.Next();
		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())
		{
			break;
		}
	}
}

CTypeObjectIDType g_Oid;
bool b = false;
void CStatusSubscriber::OnRtnSyslogInfoTopic(CFTDCPackage *pFTDCPackage)
{
	static int	iLen = 0;

	static int	iPkg = 0;

	static int	iField = 0;
	iPkg++;

	CFTDRtnSyslogInfoField	fieldSyslogInfo;
	list<int> iList;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnSyslogInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldSyslogInfo);
#ifdef PRINT_DEBUG
		if (strcmp((fieldSyslogInfo.AttrType).getValue(), "tkernel") == 0)
		{
			iField++;
			iLen = iLen + fieldSyslogInfo.ContLen;

			printf(
				"\n+++++Syslog:%s  \nType:%s  Pkg:%d  Field:%d Len:%d  Total:%d\nContent:%s\n",
				(const char *)fieldSyslogInfo.ObjectID,
				(const char *)fieldSyslogInfo.AttrType,
				iPkg,
				iField,
				(const int)fieldSyslogInfo.ContLen,
				iLen,
				(const char *)fieldSyslogInfo.FileContent);
		}

#endif

		CWriteableSysMdbSyslogInfo	mdbfield;
		mdbfield.ObjectID = g_StringIdMap.getStringId(
				fieldSyslogInfo.ObjectID.getValue());
		mdbfield.AttrType = g_StringIdMap.getStringId(
				fieldSyslogInfo.AttrType.getValue());
		mdbfield.ContLen = fieldSyslogInfo.ContLen;
		mdbfield.FileContent = fieldSyslogInfo.FileContent;
		mdbfield.MonDate = fieldSyslogInfo.MonDate;
		mdbfield.MonTime = fieldSyslogInfo.MonTime;

		if (find(iList.begin(), iList.end(), mdbfield.ObjectID) == iList.end())
		{
			CSysMdbSyslogInfo *oldfield = pMemoryDB->m_SysMdbSyslogInfoFactory->
				startFindByDataDelete(
					mdbfield.ObjectID,
					mdbfield.AttrType,
					theDate,
					theTime);
			while (oldfield)
			//if(oldfield)
			{
				CSysMdbSyslogInfo *tmpfield = pMemoryDB->
					m_SysMdbSyslogInfoFactory->findNextByDataDelete();
				pMemoryDB->m_SysMdbSyslogInfoFactory->remove(oldfield);
				oldfield = tmpfield;
			}

			pMemoryDB->m_SysMdbSyslogInfoFactory->endFindByDataDelete();
			iList.push_back(mdbfield.ObjectID);
		}

		pMemoryDB->m_SysMdbSyslogInfoFactory->add(&mdbfield, NULL);

		if (!m_reload)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnSyslogInfoTopic,
					FTDC_CHAIN_CONTINUE,
					FTD_VERSION);

			string	str = fieldSyslogInfo.ObjectID.getValue();
			str += ".";
			str += fieldSyslogInfo.AttrType.getValue();
			FTDC_ADD_FIELD(&m_pkgSend, &fieldSyslogInfo);
			g_pListSessionArray->SendPackage(&m_pkgSend, str.data());
		}

		itor.Next();
	}
}

void CStatusSubscriber::OnRtnNetworkInfoTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnNetworkInfoField fieldNetworkInfo;
	list<int> iList;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnNetworkInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldNetworkInfo);

		CWriteableSysMdbNetworkInfo mdbfield;
		string	strHostName = fieldNetworkInfo.HostName.getValue();

		//		strHostName =strHostName +"." +fieldNetworkInfo.LANNAME.getValue();
		mdbfield.SubcriberID = g_StringIdMap.getStringId(strHostName.data());
		mdbfield.HostName = g_StringIdMap.getStringId(
				fieldNetworkInfo.HostName.getValue());
		mdbfield.MonTime = fieldNetworkInfo.MonTime;
		mdbfield.MonDate = fieldNetworkInfo.MonDate;
		mdbfield.LANNAME = fieldNetworkInfo.LANNAME;
		mdbfield.LANSTATUS = fieldNetworkInfo.LANSTATUS;
		mdbfield.IPADDRESS = fieldNetworkInfo.IPADDRESS;
		mdbfield.SENDPACKETS = fieldNetworkInfo.SENDPACKETS;
		mdbfield.SENDBYTES = fieldNetworkInfo.SENDBYTES;
		mdbfield.SENDDROPPACKETS = fieldNetworkInfo.SENDDROPPACKETS;
		mdbfield.SENDERRORPACKETS = fieldNetworkInfo.SENDERRORPACKETS;
		mdbfield.RECVPACKETS = fieldNetworkInfo.RECVPACKETS;
		mdbfield.RECVBYTES = fieldNetworkInfo.RECVBYTES;
		mdbfield.RECVDROPPACKETS = fieldNetworkInfo.RECVDROPPACKETS;
		mdbfield.RECVERRORPACKETS = fieldNetworkInfo.RECVERRORPACKETS;

		if (find(
				iList.begin(),
			iList.end(),
			mdbfield.SubcriberID) == iList.end())
		{
			CSysMdbNetworkInfo	*oldfield = pMemoryDB->
				m_SysMdbNetworkInfoFactory->startFindByDataDelete(
						mdbfield.SubcriberID,
						theDate,
						theTime);
			while (oldfield)
			//if(oldfield)
			{
				CSysMdbNetworkInfo	*tmpfield = pMemoryDB->
					m_SysMdbNetworkInfoFactory->findNextByDataDelete();
				pMemoryDB->m_SysMdbNetworkInfoFactory->remove(oldfield);
				oldfield = tmpfield;
			}

			pMemoryDB->m_SysMdbNetworkInfoFactory->endFindByDataDelete();
			iList.push_back(mdbfield.SubcriberID);

			map<int, int>::iterator it = g_SubcriberMap.find(
					(int)(mdbfield.SubcriberID));
			if (it == g_SubcriberMap.end())
			{
				g_SubcriberMap[(int)(mdbfield.SubcriberID)] = 6;
			}
		}

		pMemoryDB->m_SysMdbNetworkInfoFactory->add(&mdbfield, NULL);

		if (!m_reload)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnNetworkInfoTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &fieldNetworkInfo);
			g_pListSessionArray->SendPackage(
					&m_pkgSend,
					fieldNetworkInfo.HostName.getValue());
		}

		itor.Next();
	}
}

void CStatusSubscriber::OnRtnWebAppInfoTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnWebAppInfoField	sfield;
	list<int> iList;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnWebAppInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);

		CWriteableSysMdbWebAppInfo	mdbfield;
		string	obj = sfield.ObjectID.getValue();
		mdbfield.ObjectID = g_StringIdMap.getStringId(obj.data());
		mdbfield.MonTime = sfield.MonTime;
		mdbfield.MonDate = sfield.MonDate;
		mdbfield.AppName = sfield.AppName;
		mdbfield.Status = sfield.Status;
		mdbfield.Desc = sfield.Desc;
		mdbfield.StartTime = sfield.StartTime;
		mdbfield.ServletNum = sfield.ServletNum;
		mdbfield.ProcessTime = sfield.ProcessTime;
		mdbfield.RequestNum = sfield.RequestNum;
		mdbfield.ErrorNum = sfield.ErrorNum;
		mdbfield.SessionSize = sfield.SessionSize;
		mdbfield.TimeOut = sfield.TimeOut;
		mdbfield.JDBCUsage = sfield.JDBCUsage;
		mdbfield.JSPNum = sfield.JSPNum;
		if (find(iList.begin(), iList.end(), mdbfield.ObjectID) == iList.end())
		{
			CSysMdbWebAppInfo *oldfield = pMemoryDB->m_SysMdbWebAppInfoFactory->
				startFindByDataDelete(mdbfield.ObjectID, theDate, theTime);
			while (oldfield)
			//if(oldfield)
			{
				CSysMdbWebAppInfo *tmpfield = pMemoryDB->
					m_SysMdbWebAppInfoFactory->findNextByDataDelete();
				pMemoryDB->m_SysMdbWebAppInfoFactory->remove(oldfield);
				oldfield = tmpfield;
			}

			pMemoryDB->m_SysMdbWebAppInfoFactory->endFindByDataDelete();
			iList.push_back(mdbfield.ObjectID);

			map<int, int>::iterator it = g_SubcriberMap.find(
					(int)(mdbfield.ObjectID));
			if (it == g_SubcriberMap.end())
			{
				g_SubcriberMap[(int)(mdbfield.ObjectID)] = 7;
			}
		}

		pMemoryDB->m_SysMdbWebAppInfoFactory->add(&mdbfield, NULL);

		if (!m_reload)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnWebAppInfoTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &sfield);
			g_pListSessionArray->SendPackage(
					&m_pkgSend,
					sfield.ObjectID.getValue());
		}

		itor.Next();
	}
}

void CStatusSubscriber::OnRtnMemPoolInfoTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnMemPoolInfoField sfield;
	list<int> iList;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnMemPoolInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);

		CWriteableSysMdbMemPoolInfo mdbfield;
		string	obj = sfield.ObjectID.getValue();
		mdbfield.ObjectID = g_StringIdMap.getStringId(obj.data());
		mdbfield.MonTime = sfield.MonTime;
		mdbfield.MonDate = sfield.MonDate;
		mdbfield.PoolName = sfield.PoolName;
		mdbfield.Usage = sfield.Usage;
		mdbfield.committedbytes = sfield.committedbytes;
		mdbfield.initbytes = sfield.initbytes;
		mdbfield.maxbytes = sfield.maxbytes;
		mdbfield.usedbytes = sfield.usedbytes;
		mdbfield.Type = sfield.Type;

		if (find(iList.begin(), iList.end(), mdbfield.ObjectID) == iList.end())
		{
			CSysMdbMemPoolInfo	*oldfield = pMemoryDB->
				m_SysMdbMemPoolInfoFactory->startFindByDataDelete(
						mdbfield.ObjectID,
						theDate,
						theTime);
			while (oldfield)
			//if(oldfield)
			{
				CSysMdbMemPoolInfo	*tmpfield = pMemoryDB->
					m_SysMdbMemPoolInfoFactory->findNextByDataDelete();
				pMemoryDB->m_SysMdbMemPoolInfoFactory->remove(oldfield);
				oldfield = tmpfield;
			}

			pMemoryDB->m_SysMdbMemPoolInfoFactory->endFindByDataDelete();
			iList.push_back(mdbfield.ObjectID);

			map<int, int>::iterator it = g_SubcriberMap.find(
					(int)(mdbfield.ObjectID));
			if (it == g_SubcriberMap.end())
			{
				g_SubcriberMap[(int)(mdbfield.ObjectID)] = 8;
			}
		}

		pMemoryDB->m_SysMdbMemPoolInfoFactory->add(&mdbfield, NULL);

		if (!m_reload)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnMemPoolInfoTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &sfield);
			g_pListSessionArray->SendPackage(
					&m_pkgSend,
					sfield.ObjectID.getValue());
		}

		itor.Next();
	}
}

void CStatusSubscriber::OnRtnConnectorInfoTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnConnectorInfoField sfield;
	list<int> iList;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnConnectorInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);

		CWriteableSysMdbConnectorInfo mdbfield;
		string	obj = sfield.ObjectID.getValue();
		mdbfield.ObjectID = g_StringIdMap.getStringId(obj.data());
		mdbfield.MonTime = sfield.MonTime;
		mdbfield.MonDate = sfield.MonDate;
		mdbfield.Name = sfield.Name;
		mdbfield.ThreadsCount = sfield.ThreadsCount;
		mdbfield.BusyThreadsCount = sfield.BusyThreadsCount;
		mdbfield.MaxThreads = sfield.MaxThreads;
		mdbfield.MaxSpareThreads = sfield.MaxSpareThreads;
		mdbfield.MinSpareThreads = sfield.MinSpareThreads;
		mdbfield.MaxTime = sfield.MaxTime;
		mdbfield.MaxProcTime = sfield.MaxProcTime;
		mdbfield.RequestCount = sfield.RequestCount;
		mdbfield.ErrorCount = sfield.ErrorCount;
		mdbfield.BytesReceived = sfield.BytesReceived;
		mdbfield.BytesSent = sfield.BytesSent;
		if (find(iList.begin(), iList.end(), mdbfield.ObjectID) == iList.end())
		{
			CSysMdbConnectorInfo *oldfield = pMemoryDB->
				m_SysMdbConnectorInfoFactory->startFindByDataDelete(
						mdbfield.ObjectID,
						theDate,
						theTime);
			while (oldfield)
			//if(oldfield)
			{
				CSysMdbConnectorInfo *tmpfield = pMemoryDB->
					m_SysMdbConnectorInfoFactory->findNextByDataDelete();
				pMemoryDB->m_SysMdbConnectorInfoFactory->remove(oldfield);
				oldfield = tmpfield;
			}

			pMemoryDB->m_SysMdbConnectorInfoFactory->endFindByDataDelete();
			iList.push_back(mdbfield.ObjectID);

			map<int, int>::iterator it = g_SubcriberMap.find(
					(int)(mdbfield.ObjectID));
			if (it == g_SubcriberMap.end())
			{
				g_SubcriberMap[(int)(mdbfield.ObjectID)] = 9;
			}
		}

		pMemoryDB->m_SysMdbConnectorInfoFactory->add(&mdbfield, NULL);

		if (!m_reload)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnConnectorInfoTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &sfield);
			g_pListSessionArray->SendPackage(
					&m_pkgSend,
					sfield.ObjectID.getValue());
		}

		itor.Next();
	}
}

void CStatusSubscriber::OnRtnSyslogEventTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnSyslogEventField sfield;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnSyslogEventField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);

		CWriteableSyslogEvent mdbfield;
		CopySysWarningEventEntity(&mdbfield, &sfield);
		pMemoryDB->m_SyslogEventFactory->add(&mdbfield, NULL);

		///清理:
		CSyslogEvent *oldField = pMemoryDB->m_SyslogEventFactory->
			startFindByTime(theDate, theTime);
		while (oldField)
		{
			CSyslogEvent *tmpField = pMemoryDB->m_SyslogEventFactory->
				findNextByTime();
			if (oldField->ObjectID == sfield.ObjectID)
			{
				pMemoryDB->m_SyslogEventFactory->remove(oldField);
			}

			oldField = tmpField;
		}

		pMemoryDB->m_SyslogEventFactory->endFindByTime();

		if (!m_reload)
		{
			list<EventSubInfo>::iterator it = g_EventSubList.begin();
			for (; it != g_EventSubList.end(); it++)
			{
				if ((
						sfield.ObjectID == (*it).ObjectID
				||	(*it).ObjectID == ""
				)
				&&	(
						sfield.EventName == (*it).EventName
				||	(*it).EventName == ""
				)
				&&	(
						sfield.ProcessFlag == (*it).ProcessFlag
				||	(*it).ProcessFlag == ""
				)
				&&	(
						sfield.WarningLevel == (*it).WarningLevel
				||	(*it).WarningLevel == ""
				))
				{
					list<CFTDCSession *> &theList = (*it).Receiver;
					list<CFTDCSession *>::iterator	itList = theList.begin();
					for (; itList != theList.end(); itList++)
					{
						m_pkgSend.PreparePackage(
								FTD_TID_RtnSyslogEventTopic,
								FTDC_CHAIN_CONTINUE,
								FTD_VERSION);
						FTDC_ADD_FIELD(&m_pkgSend, &sfield);
						(*itList)->SendRequestPackage(&m_pkgSend);
					}
				}
			}
		}

		if (!m_reload)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnSyslogEventTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &sfield);

			list<CFTDCSession *>::iterator	it;
			for (it = g_mListAllSession.begin();
				 it != g_mListAllSession.end();
				 it++)
			{
				(*it)->SendRequestPackage(&m_pkgSend);
				m_pkgSend.Pop(FTDCHLEN);
			}
		}

		itor.Next();
	}
}

void CStatusSubscriber::OnRtnWarningQueryTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnWarningQueryField fieldInfo;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnWarningQueryField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);

		CWriteableSysWarningQuery mdbfield;
		CopySysWarningQueryEntity(&mdbfield, &fieldInfo);
		pMemoryDB->m_SysWarningQueryFactory->add(&mdbfield);

		///清理:
		CSysWarningQuery *oldField = pMemoryDB->m_SysWarningQueryFactory->
			startFindByTime(theDate, theTime);
		while (oldField)
		{
			CSysWarningQuery *tmpField = pMemoryDB->m_SysWarningQueryFactory->
				findNextByTime();
			pMemoryDB->m_SysWarningQueryFactory->remove(oldField);
			oldField = tmpField;
		}

		pMemoryDB->m_SysWarningQueryFactory->endFindByTime();

		itor.Next();
	}
}

void CStatusSubscriber::OnRtnNetDeviceLinkTopic(CFTDCPackage *pFTDCPackage)
{
	/*CFTDRtnNetDeviceLinkField	  fieldInfo;

	CNamedFieldIterator itor= pFTDCPackage->GetNamedFieldIterator(&CFTDRtnNetDeviceLinkField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);

		map<CTypeObjectIDType ,list<CTypeObjectIDType> >::iterator itMap =g_NetLinkMap.find(fieldInfo.ObjectID);
		if(itMap ==g_NetLinkMap.end())
		{
			list<CTypeObjectIDType> theList;
			theList.push_back(fieldInfo.LinkID);
			g_NetLinkMap[fieldInfo.ObjectID] =theList;
		}
		else
		{
			list<CTypeObjectIDType>::iterator itList =find(itMap->second.begin() ,itMap->second.end() ,fieldInfo.LinkID);
			if(itList ==itMap->second.end())
				itMap->second.push_back(fieldInfo.LinkID);
		}

		if(!m_reload)
		{
			m_pkgSend.PreparePackage(FTD_TID_RtnNetDeviceLinkTopic, FTDC_CHAIN_LAST, FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);
			g_pListSessionArray->SendPackage(&m_pkgSend, fieldInfo.ObjectID.getValue());
		}

		itor.Next();
	}*/
}

void CStatusSubscriber::OnRtnNetMonitorTaskResultTopic(
	CFTDCPackage *pFTDCPackage)
{
	CFTDRtnNetMonitorTaskResultField fieldInfo;
	CDateType dDate;
	time_t	timep;
	time(&timep);
	timep -= 24 * 3600;

	struct tm tm_time;
	LocalTime(&timep, &tm_time);
	sprintf(
		(char *)(dDate.getValue()),
		"%d%02d%02d",
		tm_time.tm_year + 1900,
		tm_time.tm_mon + 1,
		tm_time.tm_mday);

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnNetMonitorTaskResultField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);

		CWriteableSysNetMonitorTaskResult mdbfield;
		CopySysNetMonitorTaskResultEntity(&mdbfield, &fieldInfo);
		pMemoryDB->m_SysNetMonitorTaskResultFactory->add(&mdbfield);

		map<int, map<int, CFTDRspQryNetMonitorTaskStatusResultField> >::iterator
			it = g_taskOperTimes.find(fieldInfo.Task_ID);
		if (it != g_taskOperTimes.end())
		{
			map<int, CFTDRspQryNetMonitorTaskStatusResultField>::iterator
				itTimes = it->second.find(fieldInfo.OperateTime);
			if (itTimes == it->second.end())
			{
				if (fieldInfo.MonTime != "" && fieldInfo.MonDate != "")
				{
					CFTDRspQryNetMonitorTaskStatusResultField theField;
					memset(&theField, 0, sizeof(theField));
					theField.MonDate = fieldInfo.MonDate;
					theField.MonTime = fieldInfo.MonTime;
					theField.Task_ID = fieldInfo.Task_ID;
					theField.OperateTime = fieldInfo.OperateTime;
					it->second[theField.OperateTime] = theField;
				}
			}
		}
		else
		{
			if (fieldInfo.MonTime != "" && fieldInfo.MonDate != "")
			{
				CFTDRspQryNetMonitorTaskStatusResultField theField;
				memset(&theField, 0, sizeof(theField));
				theField.MonDate = fieldInfo.MonDate;
				theField.MonTime = fieldInfo.MonTime;
				theField.Task_ID = fieldInfo.Task_ID;
				theField.OperateTime = fieldInfo.OperateTime;

				map<int, CFTDRspQryNetMonitorTaskStatusResultField> theMap;
				theMap[theField.OperateTime] = theField;
				g_taskOperTimes[fieldInfo.Task_ID] = theMap;
			}
		}

		///清理:
		CSysNetMonitorTaskResult *oldField = pMemoryDB->
			m_SysNetMonitorTaskResultFactory->startFindByDataDelete(
					dDate,
					fieldInfo.Task_ID,
					fieldInfo.ObjectID);
		while (oldField)
		{
			CSysNetMonitorTaskResult *tmpField = pMemoryDB->
				m_SysNetMonitorTaskResultFactory->findNextByDataDelete();
			pMemoryDB->m_SysNetMonitorTaskResultFactory->remove(oldField);
			oldField = tmpField;
		}

		pMemoryDB->m_SysNetMonitorTaskResultFactory->endFindByDataDelete();

		itor.Next();
	}
}
