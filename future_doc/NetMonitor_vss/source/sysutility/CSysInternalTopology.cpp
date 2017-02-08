/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CSysInternalTopology.h
///@brief	定义了监控系统内部各功能模块之间连接关系的类
///@history
///20140113	曹宁		创建该文件

#include "CSysInternalTopology.h"

// 将节点的信息组织后返回
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

// 将链路的信息组织成string
std::string CSysInternalLink::GetLinkInfo()
{
	// ip1:port1-ip2:port2
	char linkInfo[128] = {0};
	sprintf(linkInfo, "%s:%d-%s:%d",
		m_Ip1.c_str(), m_Port1,	m_Ip2.c_str(), m_Port2);

	return linkInfo;
}

// 将链路的状态信息组织成string
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

// 用于处理接收到的请求报文
// 会将本地存储的所有级联信息回送
void CSysInternalTopology::OnReqQrySysInternalTopologyTopic( 
	CFTDCPackage *pFTDCPackage, 
	CFTDCSession *pSession )
{
	m_pkgSend.PreparePackage(FTD_TID_RspQrySysInternalTopologyTopic, FTDC_CHAIN_LAST, FTD_VERSION);

	// 首先发送本地节点信息
	CFTDRspQrySysInternalTopologyField localNodeField;
	memset(&localNodeField, 0, sizeof(CFTDRspQrySysInternalTopologyField));

	// 本地节点上对于上层节点而言是直连节点
	localNodeField.InfoType = "DNode";
	// DNode表示直连节点，RNode表示远端节点
	localNodeField.Node1_ID = RootNodeID().c_str();
	localNodeField.Node1_Info = GetRootNodeInfo().c_str();

	FTDC_ADD_FIELD(&m_pkgSend, &localNodeField);

	// 没有远端节点则返回，则已有信息发送后返回
	if (m_mapNodes.empty())
	{
		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		pSession->SendRequestPackage(&m_pkgSend);
		return;
	}

	// 然后发送本地已知的节点信息
	for (map<string, CSysInternalNode*>::iterator itNode = m_mapNodes.begin();
		itNode != m_mapNodes.end();
		++itNode)
	{
		CFTDRspQrySysInternalTopologyField remoteNodeField;
		memset(&remoteNodeField, 0, sizeof(CFTDRspQrySysInternalTopologyField));

		// 对于上方节点来说，本地节点的已知节点为远端节点
		remoteNodeField.InfoType = "RNode";
		// DNode表示直连节点，RNode表示远端节点
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

	// 最后发送本地保存的链路信息
	for (vector<CSysInternalLink*>::iterator itLink = m_TopologyLinks.begin();
		itLink != m_TopologyLinks.end();
		++itLink)
	{
		CFTDRspQrySysInternalTopologyField linkField;
		memset(&linkField, 0, sizeof(CFTDRspQrySysInternalTopologyField));

		linkField.InfoType = "Link";
		// DNode表示直连节点，RNode表示远端节点
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

		// 如果是直连节点
		if (strcmp(topologyField.InfoType.getValue(), "DNode") == 0)
		{
			// 生成新节点
			CSysInternalNode* pNewNode = new CSysInternalNode();
			pNewNode->SetNodeID(topologyField.Node1_ID.getValue());
			char szNodeName[128] = {0}, szNodeAlias[128] = {0};
			sscanf(topologyField.Node1_Info.getValue(), "%[^#]#%[^#]", szNodeName, szNodeAlias);
			pNewNode->SetNodeName(szNodeName);
			pNewNode->SetNodeAlias(szNodeAlias);

			// 收到直连节点的报文，因此状态为ON。更新直连节点信息
			// 更新后需将新节点信息向上传送，UpdateDirectNode内部实现
			AddDirectNode(pSession, pNewNode);

		}
		else if (strcmp(topologyField.InfoType.getValue(), "RNode") == 0)	// 如果是远端节点
		{
			// 生成新节点
			CSysInternalNode* pNewNode = new CSysInternalNode();
			pNewNode->SetNodeID(topologyField.Node1_ID.getValue());
			char szNodeName[128] = {0}, szNodeAlias[128] = {0};
			sscanf(topologyField.Node1_Info.getValue(), "%[^#]#%[^#]", szNodeName, szNodeAlias);
			pNewNode->SetNodeName(szNodeName);
			pNewNode->SetNodeAlias(szNodeAlias);

			// 更新远端节点的信息
			UpdateRemoteNode(pNewNode);
		}
		// 如果是链路信息，则为下级Agent中保存的信息
		else if (strcmp(topologyField.InfoType.getValue(), "Link") == 0)
		{
			// 根据报文中的链路信息，更新远端链路状态
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

	// 通告报文中只会包含远端节点或者链路信息
	if (strcmp(sysInternalField.InfoType.getValue(), "RNode") == 0)	// 如果是远端节点
	{
		// 生成新节点
		CSysInternalNode* pNewNode = new CSysInternalNode();
		pNewNode->SetNodeID(sysInternalField.Node1_ID.getValue());
		char szNodeName[128] = {0}, szNodeAlias[128] = {0};
		sscanf(sysInternalField.Node1_Info.getValue(), "%[^#]#%[^#]", szNodeName, szNodeAlias);
		pNewNode->SetNodeName(szNodeName);
		pNewNode->SetNodeAlias(szNodeAlias);

		// 更新远端节点的信息
		UpdateRemoteNode(pNewNode);
	}
	// 如果是链路信息，则为下级Agent中保存的信息
	else if (strcmp(sysInternalField.InfoType.getValue(), "Link") == 0)
	{
		// 根据报文中的链路信息，更新远端链路状态
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

	//获取local ip and port
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

	//获取remote ip and port
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
	// 遍历链路信息，查看待插入链路的两端节点是否已经存在
	for (vector<CSysInternalLink* >::iterator itLink = m_TopologyLinks.begin();
		itLink != m_TopologyLinks.end();
		++itLink)
	{
		// 找到两端节点，则更新链路信息
		if ((*itLink)->m_Node1 == _pLink->m_Node1 && (*itLink)->m_Node2 == _pLink->m_Node2)
		{
			bool bChange = false;
			// 如果链路信息发生改变
			if ((*itLink)->GetLinkInfo() != _pLink->GetLinkInfo())
			{
				(*itLink)->m_Ip1 = _pLink->m_Ip1;
				(*itLink)->m_Ip2 = _pLink->m_Ip2;
				(*itLink)->m_Port1 = _pLink->m_Port1;
				(*itLink)->m_Port2 = _pLink->m_Port2;
				bChange = true;
			}

			// 如果链路状态发生改变，要记录改变时间
			if ((*itLink)->m_LinkState != _pLink->m_LinkState)
			{
				(*itLink)->m_LinkState = _pLink->m_LinkState;
				(*itLink)->m_Time = time(NULL);
				bChange = true;
			}

			(*itLink)->m_iSessionID = _pLink->m_iSessionID;

			// 如果链路信息发生改变，则需要向上提交改变信息
			if (bChange)
			{
				ReportLinkInfo(_pLink);
			}
			// 在更新了已有链路后，需要将该链路对象删除
			delete _pLink;
			return;
		}
	}

	// 没找到两端节点，且链路状态为ON，则插入链路
	if (_pLink->m_LinkState == ON)
	{
		_pLink->m_Time = time(NULL);
		m_TopologyLinks.push_back(_pLink);
		ReportLinkInfo(_pLink);
	}

}

// 增加一个直连节点信息
void CSysInternalTopology::AddDirectNode( 
	CSession* _pSession, 
	CSysInternalNode* _directNode )
{
	// 首先更新节点队列信息
	// 节点指针更新为队列中的节点
	_directNode = AddNode(_directNode);

	// 对于直连的节点，还需要更新本地与该节点直连的链路信息
	// 根据Session，获取本链路的信息
	int nLocalPort = 0, nRemotePort = 0;
	string strLocalIp, strRemoteIp;
	GetLocalTcpLinkInfo(_pSession->GetChannel()->GetId(), nLocalPort, strLocalIp);
	GetRemoteTcpLinkInfo(_pSession->GetChannel()->GetId(), nRemotePort, strRemoteIp);

	// 然后生成一条本地与直连节点的链路信息
	CSysInternalLink* pNewLink = new CSysInternalLink();
	pNewLink->m_Node1 = RootNode();	// Node1为本地
	pNewLink->m_Ip1 = strLocalIp;
	pNewLink->m_Port1 = nLocalPort;

	pNewLink->m_Node2 = _directNode;	// Node2为对端
	pNewLink->m_Ip2 = strRemoteIp;
	pNewLink->m_Port2 = nRemotePort;

	pNewLink->m_LinkState = ON;

	pNewLink->m_iSessionID = _pSession->GetSessionID();

	// 将该链路添加到链路队列中
	UpdateLinks(pNewLink);
}

// 直连会话建立
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


// 删除一个直连节点
void CSysInternalTopology::OnSessionDisconnected( CSession* _pSession )
{
	// 根据Session得到链路
	for (vector<CSysInternalLink*>::iterator itLink = m_TopologyLinks.begin();
		itLink != m_TopologyLinks.end();
		++itLink)
	{
		if ((*itLink)->m_iSessionID == _pSession->GetSessionID())
		{
			// 更改链路状态为OFF
			(*itLink)->m_LinkState = OFF;
			// 重置sessionID
			(*itLink)->m_iSessionID = 0;
			// 上报链路更新
			ReportLinkInfo(*itLink);
			// 删除队列中的链路
			//m_TopologyLinks.erase(itLink);
#if 0
			// 获取到对端节点
			CSysInternalNode* _node = (*itLink)->m_Node2;
			// 将所有与对端节点连接的链路设置为OFF
			for (vector<CSysInternalLink*>::iterator itLink2 = m_TopologyLinks.begin();
				itLink2 != m_TopologyLinks.end();
				++itLink2)
			{
				if (itLink2 == itLink)	// 防止重复发送链路更新信息
					continue;

				if ((*itLink2)->m_Node1 == _node || (*itLink2)->m_Node2 == _node)
				{
					// 更改链路状态为OFF
					(*itLink2)->m_LinkState = OFF;
					// 重置sessionID
					(*itLink2)->m_iSessionID = 0;
					// 上报链路更新
					ReportLinkInfo(*itLink);
				}
			}
#endif
			TopologyShow();
			return;
		}
	}
}

// 更新节点的信息
CSysInternalNode* CSysInternalTopology::AddNode( CSysInternalNode* _node )
{
	// 新发现一个节点或者节点信息改变
	map<string, CSysInternalNode*>::iterator itNode = 
		m_mapNodes.find(_node->GetNodeID());
	if ( itNode != m_mapNodes.end())
	{
		// 如果节点存在，则更新节点信息
		itNode->second->SetNodeInfo(_node);
		// 删除额外的节点信息
		delete _node;
		// 指向队列中的节点
		_node = itNode->second;
	}
	else
		m_mapNodes[_node->GetNodeID()] = _node;

	// 向上报告节点的变化
	ReportNodeInfo(_node);

	return _node;
}

// 更新远端链路的信息
void CSysInternalTopology::UpdateRemoteLink( 
	const char* _node1,			// nodeID，例如 sysprobe-1
	const char* _node2, 
	const char* _linkInfo,		// 链路信息，ip1:port1-ip2:port2
	const char* _linkState )	// 链路状态，state,time	
{
	// 解析链路信息
	char szIp1[32] = {0}, szIp2[32] = {0};
	int nPort1 = 0, nPort2 = 0, nState = 0;
	long long nTime = 0;

	sscanf(_linkInfo, "%[^:]:%d-%[^:]:%d", szIp1, &nPort1, szIp2, &nPort2);
	sscanf(_linkState, "%d,%lld", &nState, &nTime);

	map<string, CSysInternalNode*>::iterator itNode1 = m_mapNodes.find(_node1);
	map<string, CSysInternalNode*>::iterator itNode2 = m_mapNodes.find(_node2);

	// 若节点不存在，则生成一个节点
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
	tmpLink->m_iSessionID = 0;	// 远端链路，sessionID = 0

	UpdateLinks(tmpLink);
}

void CSysInternalTopology::ReportNodeInfo( CSysInternalNode* _node )
{
	if (m_SendSession == NULL)
		return;

	m_pkgSend.PreparePackage(FTD_TID_RtnSysInternalTopologyTopic, FTDC_CHAIN_LAST, FTD_VERSION);

	CFTDRtnSysInternalTopologyField reportNodeField;
	memset(&reportNodeField, 0, sizeof(CFTDRtnSysInternalTopologyField));

	// 对于上层节点而言，本地更新的节点是远端节点
	reportNodeField.InfoType = "RNode";
	// DNode表示直连节点，RNode表示远端节点
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
	// 输出本节点信息
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



