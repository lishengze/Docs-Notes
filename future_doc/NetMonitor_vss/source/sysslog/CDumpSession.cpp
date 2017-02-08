/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CDumpSession.cpp
///@brief	���������ݰ����˵���
///@auther	�Ժ��
///@history
#include "CDumpSession.h"
#include "COrderRttManager.h"
#include "CPackageFilter.h"
#include "SessionProxy.h"

extern COrderRttAnalysis *g_OrderRttAnalysis;
extern CSlogQuery *g_pSlogQuery;						// Slog��ѯ����ʵ��ָ��
extern CLogger	*g_pLoggerOutput;
extern CPackageFilter g_PackageFilter;

extern bool g_bAnalysisRTT;
extern char g_szTimeBuffer[10];
extern CStringIdMap g_mStringIdMap;

extern unsigned long long g_nMallocSize;

CQWordMonitorIndex* CSlogQuery::m_pSlogMallocLengthMonitor = new CQWordMonitorIndex("SlogMallocLength", 5);

COfpDumpSession::COfpDumpSession(CReactor *pReactor, CChannel *pChannel) :
	COFPSession(pReactor, pChannel, OFP_VERSION_1)
{
	m_pOFPProtocol->RegisterUpperHandler(this);
	m_nSessionID = (pChannel->GetId() << 10) | CTime::TimeToLong(g_szTimeBuffer);
	m_nSlogId = pChannel->GetId() >> 16;
	printf(
		"1COfpDumpSession::COfpDumpSession pChannel::GetId %d %d\n",
		m_nSlogId,
		m_nSessionID);
}

COfpDumpSession::COfpDumpSession(
	CReactor *pReactor,
	CChannel *pChannel,
	int nFrontId,
	int nFileId,
	string	&sIpAddr,
	char cVersion,
	char *pRWFlag) :
	COFPSession(pReactor, pChannel, cVersion)
{
	m_pOFPProtocol->RegisterUpperHandler(this);
	m_nSessionID = (pChannel->GetId() << 10) | CTime::TimeToLong(g_szTimeBuffer);
	m_nSlogId = pChannel->GetId();
	m_nFrontId = nFrontId;
	m_nFileId = nFileId;
	m_sIpAddr = sIpAddr;
	m_sRWFlag = pRWFlag;

	char *p = (char *)strstr(g_mStringIdMap.getString(m_nFileId), "ofp");
	if (p == NULL)
	{
		m_cVersion = 1;
	}
	else
	{
		p = p + 3;
		if (*p == '2')
		{
			m_cVersion = 2;
		}
		else
		{
			m_cVersion = 1;
		}
	}

#ifdef PRINT_DEBUG
	printf(
		"2COfpDumpSession::COfpDumpSession pChannel::GetId %d %d nFrontId %d nFileId %d\n",
		m_nSlogId,
		m_nSessionID,
		m_nFrontId,
		m_nFileId);
#endif
}

int COfpDumpSession::HandlePackage(CPackage *pPackage, CProtocol *pProtocol)
{
	if (pProtocol == m_pOFPProtocol)
	{
		//		printf("OFP package received\n");
		COFPPackage *pOFPPackage = (COFPPackage *)pPackage;

		if (pOFPPackage->GetCommandID()
				== OFP_VARY_QryInstrumentPriceResponse
		||	pOFPPackage->GetCommandID()
				== OFP_VARY_QryInstrumentPriceRequest)	// zhou.jj 20090918 �����ѯ���������ݰ�
		{
			return 0;
		}

		if (pOFPPackage->GetCommandID() == OFP_VARY_LoginRequest)		// login request
		{
			COFPLoginRequestField *p =
				(COFPLoginRequestField *)pOFPPackage->Address();
			m_sUserId = (const char *)p->Userid;
			m_sMemberId = m_sUserId;
			m_sMemberId[4] = '\0';
#ifdef PRINT_DEBUG
			printf(
				"\t loginname [%s] MemberID [%s]\n",
				m_sUserId.c_str(),
				m_sMemberId.c_str());
#endif
		}
		else if (pOFPPackage->GetCommandID() == OFP_VARY_LoginResponse) // login response
		{
			COFPLoginResponseField	*p =
				(COFPLoginResponseField *)pOFPPackage->Address();
			m_sUserId = (const char *)p->Userid;
			m_sMemberId = m_sUserId;
			m_sMemberId[4] = '\0';
#ifdef PRINT_DEBUG
			printf(
				"\t loginname [%s] MemberID [%s]\n",
				m_sUserId.c_str(),
				m_sMemberId.c_str());
#endif
		}

		if (g_PackageFilter.CheckTid(pOFPPackage->GetCommandID())
		&&	g_PackageFilter.CheckTime())
		{
			if (g_bAnalysisRTT)
			{
				g_OrderRttAnalysis->OnOFPPackage(
						pOFPPackage,
						GetSessionID(),
						m_nFrontId,
						m_cVersion);
			}

			int nPackLen = 0;
			((CBufferLogger *)g_pLoggerOutput)->reset();
			pOFPPackage->DebugOutput(g_pLoggerOutput);

			char *p = (char *)((CBufferLogger *)g_pLoggerOutput)->getValue(
					nPackLen);
			g_pSlogQuery->savePackage(
					g_szTimeBuffer,
					m_sIpAddr,
					m_sMemberId,
					m_sUserId,
					m_nFrontId,
					m_nSlogId,
					m_sRWFlag,
					p,
					nPackLen);
#ifdef PRINT_DEBUG
			printf("[%s]\n", p);
			printf("Session ID [%0x] IP: [%s]\n", this, m_sIpAddr.c_str());
			g_pSlogQuery->print();
#endif
		}
	}
	else
	{
		printf("error package received\n");
	}

	return 0;
}

CFtdcDumpSession::CFtdcDumpSession(CReactor *pReactor, CChannel *pChannel) :
	CFTDCSession(pReactor, pChannel)
{
	m_pXMPProtocol->EnableHeartbeat(false);

	m_pXMPProtocol->RegisterUpperHandler(this);
	m_pCRPProtocol->RegisterUpperHandler(this);

	SetCompressMethod(CRPCM_ZERO);	//����ѹ���㷨
	m_nSessionID = (pChannel->GetId() << 10) | CTime::TimeToLong(g_szTimeBuffer);
	m_nSlogId = pChannel->GetId();

	printf(
		"1CFtdDumpSession::CFtdDumpSession pChannel::GetId %d %d\n",
		m_nSlogId,
		m_nSessionID);
}

CFtdcDumpSession::CFtdcDumpSession(
	CReactor *pReactor,
	CChannel *pChannel,
	int nFrontId,
	int nFileId,
	string	&sIpAddr,
	char *pRWFlag) :
	CFTDCSession(pReactor, pChannel)
{
	m_pXMPProtocol->EnableHeartbeat(false);

	m_pXMPProtocol->RegisterUpperHandler(this);
	m_pCRPProtocol->RegisterUpperHandler(this);

	SetCompressMethod(CRPCM_ZERO);	//����ѹ���㷨
	m_nSessionID = (pChannel->GetId() << 10) | CTime::TimeToLong(g_szTimeBuffer);
	m_nSlogId = pChannel->GetId() >> 16;
	m_nFrontId = nFrontId;
	m_nFileId = nFileId;
	m_sIpAddr = sIpAddr;
	m_cVersion = 0;
	m_sRWFlag = pRWFlag;

#ifdef PRINT_DEBUG
	printf(
		"2CFtdcDumpSession::CFtdcDumpSession pChannel::GetId %d %d nFrontId %d nFileId %d\n",
		m_nSlogId,
		m_nSessionID,
		m_nFrontId,
		m_nFileId);
#endif
}

int CFtdcDumpSession::HandlePackage(CPackage *pPackage, CProtocol *pProtocol)
{
	if (pProtocol == m_pXMPProtocol)
	{
	}
	else if (pProtocol == m_pCRPProtocol)
	{
	}
	else if (pProtocol == m_pFTDCProtocol)
	{
		CFTDCPackage *pFTDCPackage = (CFTDCPackage *)pPackage;

		if (pFTDCPackage->GetTID() == FTD_TID_ReqQryMBLMarketData
		||	pFTDCPackage->GetTID() == FTD_TID_RspQryMBLMarketData)	// zhou.jj 20090918 �����ѯ���������ݰ�
		{
			return 0;
		}

		if (pFTDCPackage->GetTID() == FTD_TID_ReqUserLogin)
		{
			CFTDReqUserLoginField fieldInfo;
			if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldInfo))
			{
				m_sUserId = (const char *)fieldInfo.UserID;
				m_sMemberId = m_sUserId;
				//m_sMemberId[4] = '\0';
				m_sMemberId = m_sUserId.size()>4 ? m_sUserId.substr(0,4) : m_sUserId;
			}
		}
		else if (pFTDCPackage->GetTID() == FTD_TID_RspUserLogin)
		{
			CFTDRspUserLoginField fieldInfo;
			if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldInfo))
			{
				m_sUserId = (const char *)fieldInfo.UserID;
				m_sMemberId = m_sUserId;
				//m_sMemberId[4] = '\0';
				m_sMemberId = m_sUserId.size()>4 ? m_sUserId.substr(0,4) : m_sUserId;
			}
		}

		if (g_PackageFilter.CheckTid(pFTDCPackage->GetTID())
		&&	g_PackageFilter.CheckTime())
		{
			if (g_bAnalysisRTT)
			{
				g_OrderRttAnalysis->OnFTDCPackage(
						pFTDCPackage,
						GetSessionID(),
						m_nFrontId,
						m_cVersion);
			}

			((CBufferLogger *)g_pLoggerOutput)->reset();
			pFTDCPackage->OutputHeader(g_pLoggerOutput);
			FTDC_DEBUG_BODY(
				pFTDCPackage->GetTID(),
				pFTDCPackage,
				g_pLoggerOutput);

			int nPackLen = 0;
			char *pkgBuf = (char *)((CBufferLogger *)g_pLoggerOutput)->getValue(
					nPackLen);
#ifdef PRINT_DEBUG
			printf("p=[%s]\n", p);
			if (nPackLen > 3800)
			{
				printf("one packbuff len %d\n", nPackLen);
				printf("p=[%s]\n", p);
				for (int i = 0; i < nPackLen; i++)
				{
					printf("%d [%d]", i, *(p + i));
				}

				printf("\n");
			}

#endif
			g_pSlogQuery->savePackage(
					g_szTimeBuffer,
					m_sIpAddr,
					m_sMemberId,
					m_sUserId,
					m_nFrontId,
					m_nSlogId,
					m_sRWFlag,
					pkgBuf,
					nPackLen);
		}
	}
	else
	{
		printf("error package received\n");
	}

	return 0;
}


bool CSlogQuery::checkMemory(int nLength)
{
	m_nMallocSize += nLength;
	if (m_nMallocSize > g_nMallocSize)
	{
		eraseFrontElements();
		return true;
	}
	else
		return false;

}

//ֱ��ɾ��map�е�ǰ10%��Ԫ��
void CSlogQuery::eraseFrontElements()
{
	unsigned int i = 0;
	unsigned int Value = m_mapSlog.size()*0.1;
	SLOGSOURCEMAP::iterator itMap = m_mapSlog.begin();
	printf("The number of savepackage is beyond limits, we delete the map from\n");
	while (i < Value)
	{
		m_nMallocSize -= strlen(itMap->second) - 1;
		free(itMap->second);
		m_mapSlog.erase(itMap++);
		i++;
	}
}

void CSlogQuery::savePackage(
	char *pTime,
	string	&sIpAddr,
	string	&sMemberId,
	string	&sUserId,
	int frontID,
	int sessionID,
	string	&sRWFlag,
	char *pValue,
	int nLength)
{
	size_t nSize = sRWFlag.size() + 1;
	bool bOverFlow = checkMemory(nLength + nSize);
	char *pkgBuf = (char *)malloc(nLength + nSize);

	m_pSlogMallocLengthMonitor->incValue(nLength + nSize);

	if (pkgBuf == NULL)
	{
		printf("\n\nSystem have no memory, exit!\n\n");
		exit(-1);
	}

	strcpy(pkgBuf, sRWFlag.c_str());
	strcat(pkgBuf, pValue);

	CSlogSouceKey pkgInfo(
					pTime,
					sIpAddr,
					sMemberId,
					sUserId,
					frontID,
					sessionID);

	CSlogSouceShortKey shortPktInfo(pkgInfo);

	m_mapSlog.insert(make_pair(shortPktInfo, pkgBuf));

	// ������Ӧǰ�õ�����Ļ����
	map<int, Front_latest_PKG>::iterator it = m_front_last_pkg.find(frontID);
	if (it != m_front_last_pkg.end())
	{
		it->second.insert(pkgInfo, pkgBuf);
	}
	else
	{
		m_front_last_pkg.insert(
				make_pair(frontID, Front_latest_PKG(pkgInfo, pkgBuf)));
	}

	notifyFrontByNewSlogPkg(frontID, pkgInfo, pkgBuf);
}

void CSlogQuery::notifyFrontByNewSlogPkg(
	int frondID,
	const CSlogSouceKey &pkgInfo,
	const char	*pkg)
{
	TradeLogCodec slogCodec;
	slogCodec.Encode(pkgInfo, pkg);

	// ����ĳ������ԭ�����һ���������ó�FTDC_CHAIN_LAST��ErrorID�洢Ҫ��ѯ��ǰ�ú�
	CFTDRspInfoField rspInfoField;
	vector<CFTDRspQryTradeLogField> s = slogCodec.OutPutEncodedSlog();
	for (size_t i = 0, size = s.size(); i < size; i++)
	{
		m_pkgSend.PreparePackage(
			FTD_TID_RspQryTradeLogTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);

		FTDC_ADD_FIELD(&m_pkgSend, &s[i]);

		rspInfoField.ErrorID = frondID;
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);

		SessionProxy::Instance().NotifyAllFront(&m_pkgSend);
	}
}

void CSlogQuery::querySlog(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	CFTDReqQryTradeLogField reqField;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &reqField) == 0)
	{
		m_pkgSend.PrepareResponse(
				pFTDCPackage,
				FTD_TID_RspQryTradeLogTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		CFTDRspInfoField fieldRspInfo;
		fieldRspInfo.ErrorMsg = "û��ȡ����ѯ����";
		fieldRspInfo.ErrorID = -1;
		FTDC_ADD_FIELD(&m_pkgSend, &fieldRspInfo);
		pSession->SendRequestPackage(&m_pkgSend);

		return;
	}

	int bIpFlag = (const int)reqField.IPFlag;
	int bMember = (const int)reqField.PartFlag;
	int bUserId = (const int)reqField.UserIDFlag;
	int bFrontID = (const int)reqField.FrontFlag;
	int bSessionID = (const int)reqField.SessionFlag;

	string	mIpAddr = (const char *)reqField.IPAddress;
	string	mTime = (const char *)reqField.EndTime;
	string	msMember = (const char *)reqField.StartParticipant;
	string	meMember = (const char *)reqField.EndParticipant;
	string	msUserId = (const char *)reqField.StartUser;
	string	meUserId = (const char *)reqField.EndUser;
	string	mfrontId = (const char *)reqField.FrontID;
	string	msSessionId = (const char *)reqField.StartSessionID;
	string	meSessionId = (const char *)reqField.EndSessionID;

	CSlogSouceKey mQuery;
	mQuery.m_sTime = (const char *)reqField.StartTime;				// ��ʼʱ��
	if (bIpFlag)	// IP��ַ
	{
		mQuery.m_sIpAddr = "";
	}
	else
	{
		mQuery.m_sIpAddr = "";
	}

	if (bMember)	// ��ʼ��Ա��
	{
		mQuery.m_sMemberId = "";
	}
	else
	{
		mQuery.m_sMemberId = "";
	}

	if (bUserId)	// ��ʼϯλ��
	{
		mQuery.m_sUserId = "";
	}
	else
	{
		mQuery.m_sUserId = "";
	}

	mQuery.m_frontID = "";
	mQuery.m_sessionID = "";

	CSlogSouceShortKey queryShortKey(mQuery);

	SLOGSOURCEMAP::iterator it = m_mapSlog.lower_bound(queryShortKey);

#ifdef PRINT_DEBUG
	int pack_num = 0;
#endif
	TradeLogCodec slogCodec;

	int mPackSend = 0;
	while (it != m_mapSlog.end())
	{
		if (mPackSend >= MAXQRYRETURNNUM)
		{
			m_pkgSend.PrepareResponse(
					pFTDCPackage,
					FTD_TID_RspQryTradeLogTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);

			CFTDRspInfoField rspInfoField;
			rspInfoField.ErrorID = -1;
			rspInfoField.ErrorMsg = "���ؼ�¼�Ѵ�������";
			FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
			pSession->SendRequestPackage(&m_pkgSend);
			return;
		}

		CSlogSouceKey _slogSourceKey = (it->first).getSourceKey();

		/// Mod by Henchi, 20120504
				/// �ַ����ȽϸĻ�ԭstrcmp��ʽ���������ؽ���������쳣��BUG��
		if (_slogSourceKey.m_sTime > mTime)
		{
			break;
		}
		else if (bIpFlag
			&& ((0 != strcmp(_slogSourceKey.m_sIpAddr.c_str(), mIpAddr.c_str()))))
		{
			it++;
			continue;
		}
		else if (bMember
			 &&	 (
			 (strcmp(_slogSourceKey.m_sMemberId.c_str(), msMember.c_str()) < 0)
			 || (strcmp(_slogSourceKey.m_sMemberId.c_str(), meMember.c_str()) > 0)
			 ))
		{
			it++;
			continue;
		}
		else if (bUserId
			 &&	 (
			 (strcmp(_slogSourceKey.m_sUserId.c_str(), msUserId.c_str()) < 0)
			 || (strcmp(_slogSourceKey.m_sUserId.c_str(), meUserId.c_str()) > 0)
			 ))
		{
			it++;
			continue;
		}
		else if (bFrontID
			&& (0 != strcmp(_slogSourceKey.m_frontID.c_str(), mfrontId.c_str())))
		{
			it++;
			continue;
		}
		else if (bSessionID
			&& (
			(strcmp(_slogSourceKey.m_sessionID.c_str(), msSessionId.c_str()) < 0)
			|| (strcmp(_slogSourceKey.m_sessionID.c_str(), meSessionId.c_str()) > 0)
			))
		{
			it++;
			continue;
		}

#ifdef PRINT_DEBUG
		if (bIpFlag)
		{
			printf("IP [%s] (%s)\n", it->first.m_sIpAddr.c_str(), it->second);
		}

		if (bMember)
		{
			printf(
				"Member [%s] (%s)\n",
				it->first.m_sMemberId.c_str(),
				it->second);
		}

		if (bUserId)
		{
			printf(
				"UserId [%s] (%s)\n",
				it->first.m_sUserId.c_str(),
				it->second);
		}

		pack_num++;
#endif

		const char	*slogData = (const char *)(it->second);
		slogCodec.Encode(_slogSourceKey, slogData);

		static int	send_counter = 0;

		send_counter++;
		if (send_counter % 10 == 0)
		{
			send_counter = 0;

			vector<CFTDRspQryTradeLogField> fields = slogCodec.OutPutEncodedSlog();

			for (size_t i = 0, size = fields.size(); i < size; i++)
			{
				m_pkgSend.PrepareResponse(
						pFTDCPackage,
						FTD_TID_RspQryTradeLogTopic,
						FTDC_CHAIN_CONTINUE,
						FTD_VERSION);
				FTDC_ADD_FIELD(&m_pkgSend, &(fields[i]));
				pSession->SendRequestPackage(&m_pkgSend);
			}

			slogCodec.Clean();
		}

		mPackSend++;
		it++;
	}

	vector<CFTDRspQryTradeLogField> fields = slogCodec.OutPutEncodedSlog();
	for (size_t i = 0, size = fields.size(); i < size; i++)
	{
		m_pkgSend.PrepareResponse(
				pFTDCPackage,
				FTD_TID_RspQryTradeLogTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &(fields[i]));
		pSession->SendRequestPackage(&m_pkgSend);
	}

#ifdef PRINT_DEBUG
	printf("\n\n\t Send packet num %d\n", pack_num);
#endif

	CFTDRspInfoField rspInfoField;
	rspInfoField.ErrorID = 0;
	rspInfoField.ErrorMsg = "query end";

	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryTradeLogTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);

	return;
}

void CSlogQuery::queryLatestSlog(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	// ����ĳ��ԭ����ʱ������CFTDReqQryNetDeviceLinked��ΪqueryLatestSlog�Ĳ�ѯ����
	// ����SysNetSubAreaIDΪ frontID��IPDECODEΪ��������ݰ���Ŀ
	// ͬ������ĳ��ԭ���ڷ���RspQryTradeLogTopicʱ����CFTDRspInfoField�е�ErrorID�洢frontID�ţ����ͻ������֡�
	CFTDReqQryNetDeviceLinkedField	reqField;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &reqField) == 0)
	{
		m_pkgSend.PrepareResponse(
				pFTDCPackage,
				FTD_TID_RspQryTradeLogTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);

		CFTDRspInfoField fieldRspInfo;
		fieldRspInfo.ErrorMsg = "û��ȡ����ѯ����";
		fieldRspInfo.ErrorID = -1;
		FTDC_ADD_FIELD(&m_pkgSend, &fieldRspInfo);
		pSession->SendRequestPackage(&m_pkgSend);

		return;
	}

	int frontID = reqField.SysNetSubAreaID;
	int pkgNum = reqField.IPDECODE;

	if (pkgNum <= 0)
	{
		// LOG
		return;
	}

	map<int, Front_latest_PKG>::iterator it = m_front_last_pkg.find(frontID);
	if (it == m_front_last_pkg.end())
	{
		m_pkgSend.PrepareResponse(
				pFTDCPackage,
				FTD_TID_RspQryTradeLogTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);

		CFTDRspInfoField fieldRspInfo;

		char buf[16];
		sprintf(buf, "%d", frontID);

		string	error = "û�и�ǰ�õı��ļ�¼ ";
		error += buf;

		fieldRspInfo.ErrorMsg = error.c_str();
		fieldRspInfo.ErrorID = frontID;
		FTDC_ADD_FIELD(&m_pkgSend, &fieldRspInfo);
		pSession->SendRequestPackage(&m_pkgSend);

		return;
	}

	TradeLogCodec slogCodec;
	list<FrontPKG>	last_pkgs = it->second.latest_PKG;
	int count = 0;
	for (list<FrontPKG>::iterator it = last_pkgs.begin();
		 it != last_pkgs.end();
		 it++)
	{
		if (count >= pkgNum)
		{
			break;
		}

		slogCodec.Encode(it->pkg_info, it->pkg_content);
		count++;
	}

	CFTDRspInfoField rspInfoField;
	vector<CFTDRspQryTradeLogField> fields = slogCodec.OutPutEncodedSlog();
	for (size_t i = 0, size = fields.size(); i < size; i++)
	{
		m_pkgSend.PrepareResponse(
				pFTDCPackage,
				FTD_TID_RspQryTradeLogTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);

		FTDC_ADD_FIELD(&m_pkgSend, &(fields[i]));

		rspInfoField.ErrorID = frontID;
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);

		pSession->SendRequestPackage(&m_pkgSend);
	}
}

int bKeepFlag = 0;
char sField[3];
char sTime[9];
char sIp[16];
char sMember[11];
char sUser[16];
char sLen[5];
char sBuffer[8000];
void CSlogQuery::analysisSlog(CFTDRspQryTradeLogField *pField)
{
	char *pStart;

	char *pCurrent;
	pStart = (char *)pField->TradeLogStr.getValue();
	pCurrent = pStart + 2;

	if (bKeepFlag)	///�������ݰ�����������һ�����ݰ����ݵĳ���
	{
		int len = atoi(sLen);
		memcpy(sLen, pCurrent + (9 + 16 + 11 + 16), 4);
		sLen[4] = '\0';
		memcpy(sBuffer + len, pCurrent + (9 + 16 + 11 + 16 + 4), atoi(sLen));
		sBuffer[len + atoi(sLen)] = '\0';
	}
	else
	{
		memcpy(sField, pStart, 2);
		sField[2] = '\0';

		int nFieldNum = atoi(sField);
		bKeepFlag = pField->bFlag;
		for (int i = 0; i < nFieldNum; i++)
		{
			memcpy(sTime, pCurrent, 9);
			pCurrent += 9;
			sTime[9 - 1] = '\0';
			memcpy(sIp, pCurrent, 16);
			pCurrent += 16;
			sIp[16 - 1] = '\0';
			memcpy(sMember, pCurrent, 11);
			pCurrent += 11;
			sMember[11 - 1] = '\0';
			memcpy(sUser, pCurrent, 16);
			pCurrent += 16;
			sUser[16 - 1] = '\0';
			memcpy(sLen, pCurrent, 4);
			pCurrent += 4;
			sLen[4] = '\0';
			memcpy(sBuffer, pCurrent, atoi(sLen));
			pCurrent += atoi(sLen);
			sBuffer[atoi(sLen)] = '\0';
			i++;
			if ((pCurrent - pStart) >= 3900)
			{
				break;
			}
		}
	}
}
