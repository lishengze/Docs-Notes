/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CSysInternalTopology.h
///@brief	�����˼��ϵͳ�ڲ�������ģ��֮�����ӹ�ϵ����
///@history
///20140113	����		�������ļ�

#include "CSysInternalTopology.h"

// ���ڵ����Ϣ��֯�󷵻�
std::string CSysInternalNode::GetNodeInfo()
{
	char szNodeInfo[128] = {0};
	sprintf(szNodeInfo, "%s#%s", 
		m_NodeName.c_str(),	m_NodeAlias.c_str());

	return szNodeInfo;
}

void CSysInternalNode::SetNodeID( const char* _sysName, int _sysId )
{
	char szNodeID[64] = {0};
	sprintf(szNodeID, "%s-%d", _sysName, _sysId);
	m_NodeID = szNodeID;
}

void CSysInternalNode::SetNodeInfo( CSysInternalNode* _node )
{
	m_NodeName = _node->GetNodeName();
	m_NodeAlias = _node->GetNodeAlias();
}

void CSysInternalNode::Print()
{
	printf("[NodeID]%s [NodeInfo]%s \n",
		m_NodeID.c_str(), GetNodeInfo().c_str());
}

// ����·����Ϣ��֯��string
std::string CSysInternalLink::GetLinkInfo()
{
	// ip1:port1-ip2:port2
	char linkInfo[128] = {0};
	sprintf(linkInfo, "%s:%d-%s:%d",
		m_Ip1.c_str(), m_Port1,	m_Ip2.c_str(), m_Port2);

	return linkInfo;
}

// ����·��״̬��Ϣ��֯��string
std::string CSysInternalLink::GetLinkStateInfo()
{
	// ON:0 OFF:1
	// state,time
	char linkState[64] = {0};
	sprintf(linkState, "%d,%lld",
		m_LinkState, m_Time);

	return linkState;
}

void CSysInternalLink::Print()
{
	char szTime[20] = {0};
	struct tm curTime;
	LocalTime(&m_Time, &curTime);
	strftime(szTime, 20, "%Y%m%d %H:%M:%S", &curTime);

	string _state = (m_LinkState == ON) ? "UP" : "DOWN";
	printf("[%s]%s:%d <-> [%s]%s:%d Link %s at %s\n",
		m_Node1->GetNodeID().c_str(),
		m_Ip1.c_str(),
		m_Port1,
		m_Node2->GetNodeID().c_str(),
		m_Ip2.c_str(),
		m_Port2,
		_state.c_str(),
		szTime);
}

std::string CSysInternalLink::LinkPrintString()
{
	// [node1]<->[node2] UP at %Y%m%d %H:%M:%S
	char linkInfo[128] = {0};

	char szTime[20] = {0};
	struct tm curTime;
	LocalTime(&m_Time, &curTime);
	strftime(szTime, 20, "%Y%m%d %H:%M:%S", &curTime);

	string _state = (m_LinkState == ON) ? "UP" : "DOWN";

	sprintf(linkInfo, "%s <-> %s %s at %s",
		m_Node1->GetNodeID().c_str(),
		m_Node2->GetNodeID().c_str(),
		_state.c_str(),
		szTime);
	
	string strlink = linkInfo;
	return strlink;
}

CSysInternalLink::CSysInternalLink()
{
	m_Node1 = m_Node2 = NULL;
	m_Ip1 = m_Ip2 = "";
	m_Port1 = m_Port2 = m_iSessionID = 0;
	m_LinkState = OFF;
	m_Time = 0;
}

CSysInternalTopology::CSysInternalTopology( const char* _sysName, int _sysId )
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	m_RootNode.SetNodeID(_sysName, _sysId);
	m_SendSession = NULL;
}

CSysInternalTopology::~CSysInternalTopology()
{

}

// ���ڴ�����յ���������
// �Ὣ���ش洢�����м�����Ϣ����
void CSysInternalTopology::OnReqQrySysInternalTopologyTopic( 
	CFTDCPackage *pFTDCPackage, 
	CFTDCSession *pSession )
{
	m_pkgSend.PreparePackage(FTD_TID_RspQrySysInternalTopologyTopic, FTDC_CHAIN_LAST, FTD_VERSION);

	// ���ȷ��ͱ��ؽڵ���Ϣ
	CFTDRspQrySysInternalTopologyField localNodeField;
	memset(&localNodeField, 0, sizeof(CFTDRspQrySysInternalTopologyField));

	// ���ؽڵ��϶����ϲ�ڵ������ֱ���ڵ�
	localNodeField.InfoType = "DNode";
	// DNode��ʾֱ���ڵ㣬RNode��ʾԶ�˽ڵ�
	localNodeField.Node1_ID = RootNodeID().c_str();
	localNodeField.Node1_Info = GetRootNodeInfo().c_str();

	FTDC_ADD_FIELD(&m_pkgSend, &localNodeField);

	// û��Զ�˽ڵ��򷵻أ���������Ϣ���ͺ󷵻�
	if (m_mapNodes.empty())
	{
		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		pSession->SendRequestPackage(&m_pkgSend);
		return;
	}

	// Ȼ���ͱ�����֪�Ľڵ���Ϣ
	for (map<string, CSysInternalNode*>::iterator itNode = m_mapNodes.begin();
		itNode != m_mapNodes.end();
		++itNode)
	{
		CFTDRspQrySysInternalTopologyField remoteNodeField;
		memset(&remoteNodeField, 0, sizeof(CFTDRspQrySysInternalTopologyField));

		// �����Ϸ��ڵ���˵�����ؽڵ����֪�ڵ�ΪԶ�˽ڵ�
		remoteNodeField.InfoType = "RNode";
		// DNode��ʾֱ���ڵ㣬RNode��ʾԶ�˽ڵ�
		remoteNodeField.Node1_ID = itNode->first.c_str();
		remoteNodeField.Node1_Info = itNode->second->GetNodeInfo().c_str();

		if (m_pkgSend.Length() + sizeof(CFTDRspQrySysInternalTopologyField) > FTDC_PACKAGE_MAX_SIZE)
		{
			m_pkgSend.SetChain(FTDC_CHAIN_CONTINUE);
			m_SendSession->SendRequestPackage(&m_pkgSend);

			m_pkgSend.PreparePackage(FTD_TID_RspQrySysInternalTopologyTopic, FTDC_CHAIN_LAST, FTD_VERSION);
		}
		FTDC_ADD_FIELD(&m_pkgSend, &remoteNodeField);
	}

	// ����ͱ��ر������·��Ϣ
	for (vector<CSysInternalLink*>::iterator itLink = m_TopologyLinks.begin();
		itLink != m_TopologyLinks.end();
		++itLink)
	{
		CFTDRspQrySysInternalTopologyField linkField;
		memset(&linkField, 0, sizeof(CFTDRspQrySysInternalTopologyField));

		linkField.InfoType = "Link";
		// DNode��ʾֱ���ڵ㣬RNode��ʾԶ�˽ڵ�
		linkField.Node1_ID = (*itLink)->m_Node1->GetNodeID().c_str();
		linkField.Node1_Info = (*itLink)->m_Node1->GetNodeInfo().c_str();
		linkField.LinkInfo = (*itLink)->GetLinkInfo().c_str();
		linkField.Node2_ID = (*itLink)->m_Node2->GetNodeID().c_str();
		linkField.Node2_Info = (*itLink)->m_Node2->GetNodeInfo().c_str();
		linkField.LinkState = (*itLink)->GetLinkStateInfo().c_str();

		if (m_pkgSend.Length() + sizeof(CFTDRspQrySysInternalTopologyField) > FTDC_PACKAGE_MAX_SIZE)
		{
			m_pkgSend.SetChain(FTDC_CHAIN_CONTINUE);
			m_SendSession->SendRequestPackage(&m_pkgSend);

			m_pkgSend.PreparePackage(FTD_TID_RspQrySysInternalTopologyTopic, FTDC_CHAIN_LAST, FTD_VERSION);
		}
		FTDC_ADD_FIELD(&m_pkgSend, &linkField);
	}
	m_pkgSend.SetChain(FTDC_CHAIN_LAST);
	pSession->SendRequestPackage(&m_pkgSend);
}


void CSysInternalTopology::OnRspQrySysInternalTopologyTopic( 
	CFTDCPackage *pFTDCPackage, 
	CFTDCSession *pSession )
{
	CFTDRspQrySysInternalTopologyField topologyField;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
		&CFTDRspQrySysInternalTopologyField::m_Describe);

	while (!itor.IsEnd())
	{
		itor.Retrieve(&topologyField);

		// �����ֱ���ڵ�
		if (strcmp(topologyField.InfoType.getValue(), "DNode") == 0)
		{
			// �����½ڵ�
			CSysInternalNode* pNewNode = new CSysInternalNode();
			pNewNode->SetNodeID(topologyField.Node1_ID.getValue());
			char szNodeName[128] = {0}, szNodeAlias[128] = {0};
			sscanf(topologyField.Node1_Info.getValue(), "%[^#]#%[^#]", szNodeName, szNodeAlias);
			pNewNode->SetNodeName(szNodeName);
			pNewNode->SetNodeAlias(szNodeAlias);

			// �յ�ֱ���ڵ�ı��ģ����״̬ΪON������ֱ���ڵ���Ϣ
			// ���º��轫�½ڵ���Ϣ���ϴ��ͣ�UpdateDirectNode�ڲ�ʵ��
			AddDirectNode(pSession, pNewNode);

		}
		else if (strcmp(topologyField.InfoType.getValue(), "RNode") == 0)	// �����Զ�˽ڵ�
		{
			// �����½ڵ�
			CSysInternalNode* pNewNode = new CSysInternalNode();
			pNewNode->SetNodeID(topologyField.Node1_ID.getValue());
			char szNodeName[128] = {0}, szNodeAlias[128] = {0};
			sscanf(topologyField.Node1_Info.getValue(), "%[^#]#%[^#]", szNodeName, szNodeAlias);
			pNewNode->SetNodeName(szNodeName);
			pNewNode->SetNodeAlias(szNodeAlias);

			// ����Զ�˽ڵ����Ϣ
			UpdateRemoteNode(pNewNode);
		}
		// �������·��Ϣ����Ϊ�¼�Agent�б������Ϣ
		else if (strcmp(topologyField.InfoType.getValue(), "Link") == 0)
		{
			// ���ݱ����е���·��Ϣ������Զ����·״̬
			UpdateRemoteLink(
				topologyField.Node1_ID.getValue(),
				topologyField.Node2_ID.getValue(),
				topologyField.LinkInfo.getValue(),
				topologyField.LinkState.getValue());
		}
		else
		{
			// Reserved
		}

		itor.Next();
	}

	//TopologyShow();
}

void CSysInternalTopology::OnRtnSysInternalTopologyTopic( 
	CFTDCPackage *pFTDCPackage, 
	CFTDCSession *pSession )
{
	CFTDRtnSysInternalTopologyField sysInternalField;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &sysInternalField);

	// ͨ�汨����ֻ�����Զ�˽ڵ������·��Ϣ
	if (strcmp(sysInternalField.InfoType.getValue(), "RNode") == 0)	// �����Զ�˽ڵ�
	{
		// �����½ڵ�
		CSysInternalNode* pNewNode = new CSysInternalNode();
		pNewNode->SetNodeID(sysInternalField.Node1_ID.getValue());
		char szNodeName[128] = {0}, szNodeAlias[128] = {0};
		sscanf(sysInternalField.Node1_Info.getValue(), "%[^#]#%[^#]", szNodeName, szNodeAlias);
		pNewNode->SetNodeName(szNodeName);
		pNewNode->SetNodeAlias(szNodeAlias);

		// ����Զ�˽ڵ����Ϣ
		UpdateRemoteNode(pNewNode);
	}
	// �������·��Ϣ����Ϊ�¼�Agent�б������Ϣ
	else if (strcmp(sysInternalField.InfoType.getValue(), "Link") == 0)
	{
		// ���ݱ����е���·��Ϣ������Զ����·״̬
		UpdateRemoteLink(
			sysInternalField.Node1_ID.getValue(),
			sysInternalField.Node2_ID.getValue(),
			sysInternalField.LinkInfo.getValue(),
			sysInternalField.LinkState.getValue());
	}
	else
	{
		// Reserved
	}

	TopologyShow();
}


bool CSysInternalTopology::GetLocalTcpLinkInfo( int _socketID, int &_nPort, string &_strIp )
{
	sockaddr addr;
	sockaddr_in* addr_v4;
	int addr_len = sizeof(addr);

	//��ȡlocal ip and port
	memset(&addr, 0, sizeof(addr));
	if (0 == ::getsockname(_socketID, &addr, &addr_len))
	{
		if (addr.sa_family == AF_INET)
		{
			addr_v4 = (sockaddr_in*)&addr;
			_strIp = inet_ntoa(addr_v4->sin_addr);
			_nPort = ntohs(addr_v4->sin_port);
			return true;
		}
	}
	return false;
}

bool CSysInternalTopology::GetRemoteTcpLinkInfo( int _socketID, int &_nPort, string &_strIp )
{
	sockaddr addr;
	sockaddr_in* addr_v4;
	int addr_len = sizeof(addr);

	//��ȡremote ip and port
	memset(&addr, 0, sizeof(addr));
	if (0 == ::getpeername(_socketID, &addr, &addr_len))
	{
		if (addr.sa_family == AF_INET)
		{
			addr_v4 = (sockaddr_in*)&addr;
			_strIp = inet_ntoa(addr_v4->sin_addr);
			_nPort = ntohs(addr_v4->sin_port);
			return true;
		}
	}
	return false;
}

void CSysInternalTopology::UpdateLinks( CSysInternalLink* _pLink )
{
	// ������·��Ϣ���鿴��������·�����˽ڵ��Ƿ��Ѿ�����
	for (vector<CSysInternalLink* >::iterator itLink = m_TopologyLinks.begin();
		itLink != m_TopologyLinks.end();
		++itLink)
	{
		// �ҵ����˽ڵ㣬�������·��Ϣ
		if ((*itLink)->m_Node1 == _pLink->m_Node1 && (*itLink)->m_Node2 == _pLink->m_Node2)
		{
			bool bChange = false;
			// �����·��Ϣ�����ı�
			if ((*itLink)->GetLinkInfo() != _pLink->GetLinkInfo())
			{
				(*itLink)->m_Ip1 = _pLink->m_Ip1;
				(*itLink)->m_Ip2 = _pLink->m_Ip2;
				(*itLink)->m_Port1 = _pLink->m_Port1;
				(*itLink)->m_Port2 = _pLink->m_Port2;
				bChange = true;
			}

			// �����·״̬�����ı䣬Ҫ��¼�ı�ʱ��
			if ((*itLink)->m_LinkState != _pLink->m_LinkState)
			{
				(*itLink)->m_LinkState = _pLink->m_LinkState;
				(*itLink)->m_Time = time(NULL);
				bChange = true;
			}

			(*itLink)->m_iSessionID = _pLink->m_iSessionID;

			// �����·��Ϣ�����ı䣬����Ҫ�����ύ�ı���Ϣ
			if (bChange)
			{
				ReportLinkInfo(_pLink);
			}
			// �ڸ�����������·����Ҫ������·����ɾ��
			delete _pLink;
			return;
		}
	}

	// û�ҵ����˽ڵ㣬����·״̬ΪON���������·
	if (_pLink->m_LinkState == ON)
	{
		_pLink->m_Time = time(NULL);
		m_TopologyLinks.push_back(_pLink);
		ReportLinkInfo(_pLink);
	}

}

// ����һ��ֱ���ڵ���Ϣ
void CSysInternalTopology::AddDirectNode( 
	CSession* _pSession, 
	CSysInternalNode* _directNode )
{
	// ���ȸ��½ڵ������Ϣ
	// �ڵ�ָ�����Ϊ�����еĽڵ�
	_directNode = AddNode(_directNode);

	// ����ֱ���Ľڵ㣬����Ҫ���±�����ýڵ�ֱ������·��Ϣ
	// ����Session����ȡ����·����Ϣ
	int nLocalPort = 0, nRemotePort = 0;
	string strLocalIp, strRemoteIp;
	GetLocalTcpLinkInfo(_pSession->GetChannel()->GetId(), nLocalPort, strLocalIp);
	GetRemoteTcpLinkInfo(_pSession->GetChannel()->GetId(), nRemotePort, strRemoteIp);

	// Ȼ������һ��������ֱ���ڵ����·��Ϣ
	CSysInternalLink* pNewLink = new CSysInternalLink();
	pNewLink->m_Node1 = RootNode();	// Node1Ϊ����
	pNewLink->m_Ip1 = strLocalIp;
	pNewLink->m_Port1 = nLocalPort;

	pNewLink->m_Node2 = _directNode;	// Node2Ϊ�Զ�
	pNewLink->m_Ip2 = strRemoteIp;
	pNewLink->m_Port2 = nRemotePort;

	pNewLink->m_LinkState = ON;

	pNewLink->m_iSessionID = _pSession->GetSessionID();

	// ������·��ӵ���·������
	UpdateLinks(pNewLink);
}

// ֱ���Ự����
void CSysInternalTopology::OnSessionConnected( CSession *pSession )
{
	m_pkgSend.PreparePackage(
		FTD_TID_ReqQrySysInternalTopologyTopic,
		FTDC_CHAIN_LAST,
		FTD_VERSION);
	CFTDReqQrySysInternalTopologyField reqField;
	memset(&reqField, 0, sizeof(CFTDReqQrySysInternalTopologyField));
	FTDC_ADD_FIELD(&m_pkgSend, &reqField);
	((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);
	/*
	printf("\t CSysInternalTopology::OnSessionConnected: CommonName [%s] Send ReqSysInternalTopology\n", 
		pSession->GetChannel()->GetRemoteCommonName());
	fflush(stdout);
	*/
}


// ɾ��һ��ֱ���ڵ�
void CSysInternalTopology::OnSessionDisconnected( CSession* _pSession )
{
	// ����Session�õ���·
	for (vector<CSysInternalLink*>::iterator itLink = m_TopologyLinks.begin();
		itLink != m_TopologyLinks.end();
		++itLink)
	{
		if ((*itLink)->m_iSessionID == _pSession->GetSessionID())
		{
			// ������·״̬ΪOFF
			(*itLink)->m_LinkState = OFF;
			// ����sessionID
			(*itLink)->m_iSessionID = 0;
			// �ϱ���·����
			ReportLinkInfo(*itLink);
			// ɾ�������е���·
			//m_TopologyLinks.erase(itLink);
#if 0
			// ��ȡ���Զ˽ڵ�
			CSysInternalNode* _node = (*itLink)->m_Node2;
			// ��������Զ˽ڵ����ӵ���·����ΪOFF
			for (vector<CSysInternalLink*>::iterator itLink2 = m_TopologyLinks.begin();
				itLink2 != m_TopologyLinks.end();
				++itLink2)
			{
				if (itLink2 == itLink)	// ��ֹ�ظ�������·������Ϣ
					continue;

				if ((*itLink2)->m_Node1 == _node || (*itLink2)->m_Node2 == _node)
				{
					// ������·״̬ΪOFF
					(*itLink2)->m_LinkState = OFF;
					// ����sessionID
					(*itLink2)->m_iSessionID = 0;
					// �ϱ���·����
					ReportLinkInfo(*itLink);
				}
			}
#endif
			TopologyShow();
			return;
		}
	}
}

// ���½ڵ����Ϣ
CSysInternalNode* CSysInternalTopology::AddNode( CSysInternalNode* _node )
{
	// �·���һ���ڵ���߽ڵ���Ϣ�ı�
	map<string, CSysInternalNode*>::iterator itNode = 
		m_mapNodes.find(_node->GetNodeID());
	if ( itNode != m_mapNodes.end())
	{
		// ����ڵ���ڣ�����½ڵ���Ϣ
		itNode->second->SetNodeInfo(_node);
		// ɾ������Ľڵ���Ϣ
		delete _node;
		// ָ������еĽڵ�
		_node = itNode->second;
	}
	else
		m_mapNodes[_node->GetNodeID()] = _node;

	// ���ϱ���ڵ�ı仯
	ReportNodeInfo(_node);

	return _node;
}

// ����Զ����·����Ϣ
void CSysInternalTopology::UpdateRemoteLink( 
	const char* _node1,			// nodeID������ sysprobe-1
	const char* _node2, 
	const char* _linkInfo,		// ��·��Ϣ��ip1:port1-ip2:port2
	const char* _linkState )	// ��·״̬��state,time	
{
	// ������·��Ϣ
	char szIp1[32] = {0}, szIp2[32] = {0};
	int nPort1 = 0, nPort2 = 0, nState = 0;
	long long nTime = 0;

	sscanf(_linkInfo, "%[^:]:%d-%[^:]:%d", szIp1, &nPort1, szIp2, &nPort2);
	sscanf(_linkState, "%d,%lld", &nState, &nTime);

	map<string, CSysInternalNode*>::iterator itNode1 = m_mapNodes.find(_node1);
	map<string, CSysInternalNode*>::iterator itNode2 = m_mapNodes.find(_node2);

	// ���ڵ㲻���ڣ�������һ���ڵ�
	if (itNode1 == m_mapNodes.end())
	{
		CSysInternalNode* tmpNode = new CSysInternalNode();
		tmpNode->SetNodeID(_node1);
		m_mapNodes[_node1] = tmpNode;
		itNode1 = m_mapNodes.find(_node1);
	}
	if (itNode2 == m_mapNodes.end())
	{
		CSysInternalNode* tmpNode = new CSysInternalNode();
		tmpNode->SetNodeID(_node2);
		m_mapNodes[_node2] = tmpNode;
		itNode1 = m_mapNodes.find(_node2);
	}

	CSysInternalLink* tmpLink = new CSysInternalLink();
	tmpLink->m_Node1 = itNode1->second;
	tmpLink->m_Node2 = itNode2->second;
	tmpLink->m_Ip1 = szIp1;
	tmpLink->m_Ip2 = szIp2;
	tmpLink->m_Port1 = nPort1;
	tmpLink->m_Port2 = nPort2;
	tmpLink->m_LinkState = (nState == 0) ? ON : OFF;
	tmpLink->m_Time = nTime;
	tmpLink->m_iSessionID = 0;	// Զ����·��sessionID = 0

	UpdateLinks(tmpLink);
}

void CSysInternalTopology::ReportNodeInfo( CSysInternalNode* _node )
{
	if (m_SendSession == NULL)
		return;

	m_pkgSend.PreparePackage(FTD_TID_RtnSysInternalTopologyTopic, FTDC_CHAIN_LAST, FTD_VERSION);

	CFTDRtnSysInternalTopologyField reportNodeField;
	memset(&reportNodeField, 0, sizeof(CFTDRtnSysInternalTopologyField));

	// �����ϲ�ڵ���ԣ����ظ��µĽڵ���Զ�˽ڵ�
	reportNodeField.InfoType = "RNode";
	// DNode��ʾֱ���ڵ㣬RNode��ʾԶ�˽ڵ�
	reportNodeField.Node1_ID = _node->GetNodeID().c_str();
	reportNodeField.Node1_Info = _node->GetNodeInfo().c_str();

	FTDC_ADD_FIELD(&m_pkgSend, &reportNodeField);
	m_SendSession->SendRequestPackage(&m_pkgSend);
}

void CSysInternalTopology::ReportLinkInfo( CSysInternalLink* _link )
{
	if (m_SendSession == NULL)
		return;

	m_pkgSend.PreparePackage(FTD_TID_RtnSysInternalTopologyTopic, FTDC_CHAIN_LAST, FTD_VERSION);

	CFTDRtnSysInternalTopologyField reportLinkField;
	memset(&reportLinkField, 0, sizeof(CFTDRtnSysInternalTopologyField));

	reportLinkField.InfoType = "Link";
	reportLinkField.Node1_ID = _link->m_Node1->GetNodeID().c_str();
	reportLinkField.Node1_Info = _link->m_Node1->GetNodeInfo().c_str();
	reportLinkField.LinkInfo = _link->GetLinkInfo().c_str();
	reportLinkField.Node2_ID = _link->m_Node2->GetNodeID().c_str();
	reportLinkField.Node2_Info = _link->m_Node2->GetNodeInfo().c_str();
	reportLinkField.LinkState = _link->GetLinkStateInfo().c_str();

	FTDC_ADD_FIELD(&m_pkgSend, &reportLinkField);
	m_SendSession->SendRequestPackage(&m_pkgSend);
}

void CSysInternalTopology::TopologyShow()
{
#if 0
	// ������ڵ���Ϣ
	printf("@@ SysIntermalTopology @@\n");

	printf("\t @@ Local Info: [ID]%s [Info]%s\n", 
		m_RootNode.GetNodeID().c_str(), 
		m_RootNode.GetNodeInfo().c_str());

	printf("\t @@ Nodes Count:[%d]\n\t\t", m_mapNodes.size());
	int _index = 1;
	for (map<string, CSysInternalNode*>::iterator itNode = m_mapNodes.begin();
		itNode != m_mapNodes.end();
		++itNode, ++_index)
	{
		printf("[%d %s] ", 
			_index, 
			itNode->second->GetNodeID().c_str());
	}
	printf("\n");

	printf("\t @@ Links Count:[%d]\n\t\t", m_TopologyLinks.size());
	_index = 1;
	for (vector<CSysInternalLink*>::iterator itLink = m_TopologyLinks.begin();
		itLink != m_TopologyLinks.end();
		++itLink, ++_index)
	{
		printf("[%d %s]", _index, (*itLink)->LinkPrintString().c_str());
	}
	printf("\n");

#endif
}

void CSysInternalTopology::UpdateRemoteNode( CSysInternalNode* _node )
{
	AddNode(_node);
}



