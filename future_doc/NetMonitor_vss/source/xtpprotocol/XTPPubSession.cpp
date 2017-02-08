// XTPPubSession.cpp: implementation of the CXTPPubSession class.
//
// 20080620 �Ժ�� CProtocol�����Զ�ɾ���ϲ�Э�飬m_pControlProtocolҪ
//                 ����ɾ��
// 20110119 ����   NT-0121��front������������
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "XTPPubSession.h"
#include "SCPPackageDesc.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CXTPPubSession::CXTPPubSession(CReactor *pReactor, CChannel *pChannel,
							   CXTPFlowManager *pFlowManager)
:CXTPSession(pReactor, pChannel)
{
	m_pFlowManager = pFlowManager;
 	m_pControlProtocol = new CSCPProtocol(pReactor);
	m_pControlProtocol->AttachLower(m_pXMPProtocol, XMPTypeSCP);
	m_controlPackage.ConstructAllocate(SCP_PACKAGE_MAX_SIZE, m_pControlProtocol->GetHdrReserveLen());
	m_pControlProtocol->RegisterUpperHandler(this);
	m_pXMPProtocol->EnableHeartbeat(false);

	m_IsInit = false;
	m_Handler = NULL;
	m_nNodeID = 0;
	m_nClock = 0;
}

CXTPPubSession::~CXTPPubSession()
{
	delete m_pControlProtocol;
}

int CXTPPubSession::HandlePackage(CPackage *pPackage, CProtocol *pProtocol)
{
	if (m_pControlProtocol == pProtocol)
	{
		CSCPPackage *pSCPPackage = (CSCPPackage *)pPackage;
//		DEBUG_LOG1("STID = %04x\n", pSCPPackage->GetTid());
		switch(pSCPPackage->GetTid()) 
		{
		case STID_SUBSCRIBE:
			OnSubscribeReq(pSCPPackage);
			break;
		case STID_UN_SUBSCRIBE:
			OnUnSubscribeReq(pSCPPackage);
			break;
		case STID_PUBLISH:
			OnHeartBeat(pSCPPackage);
			break;
		case STID_ACK:
			OnAck(pSCPPackage);
			break;
		case STID_PUBLISH_REQ:
			OnPublishReq(pSCPPackage);
			break;
		case STID_PUBLISH_RSP:
			OnPublishRsp(pSCPPackage);
			break;
		default:
			break;
		}

		return 0;
	}
	
	return CXTPSession::HandlePackage(pPackage, pProtocol);
}

void CXTPPubSession::OnSubscribeReq(CSCPPackage *pPackage)
{
	CSCPSubscribeField subscribeField;
	CNamedFieldIterator i = pPackage->GetNamedFieldIterator(&subscribeField.m_Describe);

	while (!i.IsEnd()) 
	{
		i.Retrieve(&subscribeField);

		if (m_pFlowManager == NULL)
		{
			break;
		}

		// �鿴�Ƿ��Ƿ��͸��Լ�������
		CReadOnlyFlow* pFlow = m_pFlowManager->GetFlow(subscribeField.SubjectID);
		
		if (pFlow != NULL) 
		{
			if (m_Handler != NULL && !m_IsInit)
			{
				// ���ͷ�������
				SendPublishReq(subscribeField.SubjectID, subscribeField.CommPhaseNo);

				// ��־
				REPORT_EVENT(LOG_INFO, "XTPPubSession", "SendPublishReq: SubjectID[%x] SubscriberID[%x]", (const DWORD) subscribeField.SubjectID, (const DWORD) subscribeField.SubscriberID);
			}
			else
			{
				// ��������
				NET_STATUS_LOG3("publish : reqCommPase[%d] SubscriberID[%x] startid[%d]\n", 
					(const WORD)subscribeField.CommPhaseNo,
					(const WORD)subscribeField.SubscriberID,
					(const int)subscribeField.StartID);
				Publish(pFlow, subscribeField.SubjectID, subscribeField.CommPhaseNo, 
					subscribeField.SubscriberID, subscribeField.StartID);		
			}
		}

		i.Next();
	}
}

void CXTPPubSession::OnUnSubscribeReq(CSCPPackage *pPackage)
{
	CSCPSubscribeField subscribeField;
	CNamedFieldIterator i = pPackage->GetNamedFieldIterator(&subscribeField.m_Describe);

	while (!i.IsEnd()) 
	{
		i.Retrieve(&subscribeField);

		UnPublish(subscribeField.SubjectID);

		i.Next();
	}	
}

void CXTPPubSession::OnHeartBeat(CSCPPackage *pPackage)
{
	CSCPPublishField publishField;
	CNamedFieldIterator i = pPackage->GetNamedFieldIterator(&publishField.m_Describe);

	while (!i.IsEnd()) 
	{
		i.Retrieve(&publishField);

		CXTPSession::OnHeartBeat(publishField.SubjectID, publishField.CommPhaseNo, publishField.SeqNo);

		i.Next();
	}
}

void CXTPPubSession::OnAck(CSCPPackage *pPackage)
{
	CSCPSubscribeField subscribeField;
	CNamedFieldIterator i = pPackage->GetNamedFieldIterator(&subscribeField.m_Describe);

	while (!i.IsEnd()) 
	{
		i.Retrieve(&subscribeField);

		CXTPSession::OnAck(subscribeField.SubscriberID, subscribeField.SubjectID, 
			subscribeField.StartID, subscribeField.CommPhaseNo);

		i.Next();
	}
}

void CXTPPubSession::OnPublishReq(CSCPPackage *pPackage)
{
	CSCPPublishReqField publishReqField;
	CNamedFieldIterator i = pPackage->GetNamedFieldIterator(&publishReqField.m_Describe);

	if (!i.IsEnd()) 
	{
		i.Retrieve(&publishReqField);

		// �õ�������
		map<DWORD, CSubscriber*>::iterator it = m_SubscriberMap.find(publishReqField.SubjectID);

		if (it != m_SubscriberMap.end())
		{
			// �õ�������
			CSubscriber* subscriber = it->second;

			// ���ɻ�Ӧ
			SendPublishRsp(publishReqField.NodeID, publishReqField.Clock, publishReqField.SubjectID, subscriber->GetCommPhaseNo(), subscriber->GetReceivedCount());
		
			// ��־
			REPORT_EVENT(LOG_INFO, "XTPPubSession", "SendPublishRsp: NodeID[%x] SubjectID[%x] SeqNo[%d]", (const DWORD) publishReqField.NodeID, (const DWORD) publishReqField.SubjectID, subscriber->GetReceivedCount());
		}
	}
}

void CXTPPubSession::OnPublishRsp(CSCPPackage *pPackage)
{
	CSCPPublishRspField publishRspField;
	CNamedFieldIterator i = pPackage->GetNamedFieldIterator(&publishRspField.m_Describe);

	if (!i.IsEnd()) 
	{
		i.Retrieve(&publishRspField);

		// ֻ�����Լ�Ӧ�ô������Ϣ
		if (m_nNodeID == publishRspField.NodeID && m_nClock == publishRspField.Clock)
		{
			if (m_Handler != NULL)
			{
				// ������Ϣ
				m_Handler->SendEvent(STID_PUBLISH_RSP, 0, &publishRspField);

				// ���ñ�־
				m_IsInit = true;

				// ��־
				REPORT_EVENT(LOG_INFO, "XTPPubSession", "OnPublishRsp: NodeID[%x] SubjectID[%x] SeqNo[%d]", (const DWORD) publishRspField.NodeID, (const DWORD) publishRspField.SubjectID, (const DWORD) publishRspField.SeqNo);
			}
		}
	}
}

void CXTPPubSession::RegisterSubscriber(CSubscriber *pSubscriber, DWORD dwSubscriberID)
{
	if (m_SubscriberMap.find(pSubscriber->GetSubjectID()) == m_SubscriberMap.end())
		m_SubscriberMap.insert(pair<DWORD, CSubscriber*>(pSubscriber->GetSubjectID(), pSubscriber));

	CXTPSession::RegisterSubscriber(pSubscriber, dwSubscriberID);
	SendSubscribeReq(pSubscriber->GetSubjectID(),
		pSubscriber->GetCommPhaseNo(),
		dwSubscriberID,
		pSubscriber->GetReceivedCount());
}

void CXTPPubSession::UnRegisterSubscriber( CSubscriber *pSubscriber)
{
	CXTPSession::UnRegisterSubscriber(pSubscriber);
	SendUnSubscribeReq(pSubscriber->GetSubjectID());

	if (m_SubscriberMap.find(pSubscriber->GetSubjectID()) != m_SubscriberMap.end())
		m_SubscriberMap.erase(pSubscriber->GetSubjectID());
}


CSCPPackage *CXTPPubSession::PrepareControlPackage(WORD stid)
{
	m_controlPackage.AllocateMax();
	m_controlPackage.Truncate(0);
	m_controlPackage.SetTid(stid);
	return &m_controlPackage;
}

void CXTPPubSession::SendControlPackage(CSCPPackage *pPackage)
{
	m_pControlProtocol->Send(pPackage);
}

void CXTPPubSession::SendSubscribeReq(DWORD nSubjectID, WORD nCommPhaseNo, DWORD dwSubscriberID, DWORD nStartID)
{
//	DEBUG_LOG3("SendSubscribeReq SubjectID:[%x], CommPhaseNo[%d], StartID:[%d]\n",
//		nSubjectID, nCommPhaseNo, nStartID);

	CSCPSubscribeField subscribeField;
	subscribeField.SubjectID = nSubjectID;
	subscribeField.StartID = nStartID;
	subscribeField.CommPhaseNo = nCommPhaseNo;
	subscribeField.SubscriberID = dwSubscriberID;

	CSCPPackage *pPackage = PrepareControlPackage(STID_SUBSCRIBE);
	SCP_ADD_FIELD(pPackage, &subscribeField);

	SendControlPackage(pPackage);

}

void CXTPPubSession::SendUnSubscribeReq(DWORD nSubjectID)
{
	CSCPSubscribeField subscribeField;
	subscribeField.SubjectID = nSubjectID;
	subscribeField.StartID = 0;

	CSCPPackage *pPackage = PrepareControlPackage(STID_UN_SUBSCRIBE);
	SCP_ADD_FIELD(pPackage, &subscribeField);

	SendControlPackage(pPackage);

}

void CXTPPubSession::SendNak(DWORD nSubjectID, WORD nCommPhaseNo, DWORD dwSubscriberID, DWORD nSeqNo)
{
	SendSubscribeReq(nSubjectID, nCommPhaseNo, dwSubscriberID, nSeqNo);
}

void CXTPPubSession::SendAck(DWORD nSubjectID, WORD nCommPhaseNo, DWORD dwSubscriberID, DWORD nSeqNo)
{
	CSCPSubscribeField subscribeField;
	subscribeField.SubjectID = nSubjectID;
	subscribeField.StartID = nSeqNo;
	subscribeField.CommPhaseNo = nCommPhaseNo;
	subscribeField.SubscriberID = dwSubscriberID;

	CSCPPackage *pPackage = PrepareControlPackage(STID_ACK);
	SCP_ADD_FIELD(pPackage, &subscribeField);

	SendControlPackage(pPackage);

}

void CXTPPubSession::SendHeartBeat(DWORD nSubjectID, WORD nCommPhaseNo, DWORD nSeqNo)
{
	CSCPPublishField publishField;
	publishField.CommPhaseNo = nCommPhaseNo;
	publishField.SubjectID = nSubjectID;
	publishField.SeqNo = nSeqNo;

	CSCPPackage *pPackage = PrepareControlPackage(STID_PUBLISH);
	SCP_ADD_FIELD(pPackage, &publishField);

	SendControlPackage(pPackage);
}

void CXTPPubSession::SendPublishReq(DWORD nSubjectID, WORD nCommPhaseNo)
{
	CSCPPublishReqField publishReqField;

	publishReqField.NodeID = m_nNodeID;
	publishReqField.Clock = m_nClock;
	publishReqField.SubjectID = nSubjectID;
	publishReqField.CommPhaseNo = nCommPhaseNo;

	CSCPPackage *pPackage = PrepareControlPackage(STID_PUBLISH_REQ);
	SCP_ADD_FIELD(pPackage, &publishReqField);

	SendControlPackage(pPackage);
}

void CXTPPubSession::SendPublishRsp(DWORD nNodeID, DWORD nClock, DWORD nSubjectID, WORD nCommPhaseNo, DWORD nSeqNo)
{
	CSCPPublishRspField publishRspField;

	publishRspField.NodeID = nNodeID;
	publishRspField.Clock = nClock;
	publishRspField.SubjectID = nSubjectID;
	publishRspField.CommPhaseNo = nCommPhaseNo;
	publishRspField.SeqNo = nSeqNo;

	CSCPPackage *pPackage = PrepareControlPackage(STID_PUBLISH_RSP);
	SCP_ADD_FIELD(pPackage, &publishRspField);

	SendControlPackage(pPackage);
}

void CXTPPubSession::SetParams(CEventHandler* handler, DWORD nNodeID, DWORD nClock)
{
	m_Handler = handler;
	m_nNodeID = nNodeID;
	m_nClock = nClock;
}
