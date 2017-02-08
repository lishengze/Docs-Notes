/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CSysInternalTopology.h
///@brief	定义了监控系统内部各功能模块之间连接关系的类
///@history
///20140113	曹宁		创建该文件
#ifndef REF_SYSINTERNALTOPOLOGY_H
#define REF_SYSINTERNALTOPOLOGY_H

#include "public.h"
#include "FtdPackageDesc.h"
#include "FTDCSession.h"
#include "FTDCPackage.h"

enum CSysInternalLinkState
{
	ON = 0,
	OFF
};

// 拓扑节点，仅保存节点的信息
class CSysInternalNode
{
public:
	string GetNodeID() { return m_NodeID; }
	string GetNodeName() { return m_NodeName; }
	string GetNodeAlias() { return m_NodeAlias; }
	// 获取节点的信息
	string GetNodeInfo();

	void SetNodeInfo(CSysInternalNode* _node);
	void SetNodeID(const char* _sysName, int _sysId);
	void SetNodeID(const char* _nodeId) { m_NodeID = _nodeId; }
	void SetNodeName(string _name) { m_NodeName = _name; }
	void SetNodeAlias(string _alias) { m_NodeAlias = _alias; }

	void Print();

private:
	string m_NodeID;		// 节点的ID，如sysprobe-1
	string m_NodeName;		// 节点的名称
	string m_NodeAlias;		// 节点的别名
};

// 拓扑链路，由两段节点指针、IP地址和端口组成
class CSysInternalLink
{
public:
	CSysInternalLink();
public:
	CSysInternalNode* m_Node1;
	string m_Ip1;
	int m_Port1;

	CSysInternalNode* m_Node2;
	string m_Ip2;
	int m_Port2;

	CSysInternalLinkState m_LinkState;	// 链路状态，在线或离线
	time_t m_Time;	// 时间，若链路状态为ON，表示连接时间；若链路状态为OFF，表示断开时间

	int m_iSessionID;	// 链路对应的SessionID，若为远端链路，该值为0

	// 将链路的信息组织成string
	string GetLinkInfo();
	// 将链路的状态信息组织成string
	string GetLinkStateInfo();

	void Print();

	string LinkPrintString();
};

class CSysInternalTopology
{
public:
	CSysInternalTopology(const char* _sysName, int _sysId);
	~CSysInternalTopology();

public:
	// 设置用于报告信息的会话（上传链路）
	void SetSendSessionON(CSession* _session) { m_SendSession = (CFTDCSession*)_session; }
	// 设置用于报告信息的会话（上传链路）为断开
	void SetSendSessionOFF() { m_SendSession = NULL; }

	// 返回本地节点的指针
	CSysInternalNode* RootNode() { return &m_RootNode; }

	// 返回本地节点名称
	string RootNodeID() { return m_RootNode.GetNodeID(); }
	// 返回本地节点信息，Name+Alias
	string GetRootNodeInfo() { return m_RootNode.GetNodeInfo(); }

	// 设置本地节点的名称
	void SetRootName(string _name) { m_RootNode.SetNodeName(_name); }
	// 设置本地节点的别名
	void SetRootAlias(string _alias) { m_RootNode.SetNodeAlias(_alias); }

	// 输出连接信息
	void TopologyShow();

public:
	// 用于处理接收到的请求报文
	// 通常连接两个节点建立连接之后，逻辑上的上层节点回向下层节点发送请求报文
	// 节点在收到请求报文后，会将本地存储的所有级联信息回送
	void OnReqQrySysInternalTopologyTopic(
		CFTDCPackage *pFTDCPackage, 
		CFTDCSession *pSession);

	// 用于处理接收到的响应报文
	// 通常本节点会向下层节点发送请求报文
	// 然后下层节点会将其保存的所有级联信息通过响应报文回送回来
	void OnRspQrySysInternalTopologyTopic(
		CFTDCPackage *pFTDCPackage, 
		CFTDCSession *pSession);

	// 用于处理接收到的通告报文
	// 通常下层节点的级联关系发生改变时，会向上层节点发送通告
	void OnRtnSysInternalTopologyTopic(
		CFTDCPackage *pFTDCPackage, 
		CFTDCSession *pSession);

	// 直连的会话建立，请求下层节点的级联信息
	void OnSessionConnected(CSession *pSession);

	// 直连的会话断开，删除一个直连节点
	// _pSession: 接收该节点信息的Session（用于获取该链路信息）
	void OnSessionDisconnected(CSession* _pSession);

private:
	// 增加一个直连节点信息
		// _pSession: 接收该节点信息的Session（用于获取该链路信息）
		// _DirectNode: 直连的节点指针
	void AddDirectNode(
		CSession* _pSession, 
		CSysInternalNode* _directNode);
	
	// 更新一个远端节点信息
		// _node: 远端节点指针
	void UpdateRemoteNode(CSysInternalNode* _node);

	// 更新远端链路的信息
		// _node1: 链路node1的ID
		// _node2: 链路node2的ID
		// _linkInfo: 链路的信息
		// _linkState: 链路的状态
	void UpdateRemoteLink(
		const char* _node1, 
		const char* _node2, 
		const char* _linkInfo, 
		const char* _linkState);

	// 通过上传链路发送节点的更新信息
	void ReportNodeInfo(CSysInternalNode* _node);

	// 通过上传链路发送链路的更新信息
	void ReportLinkInfo(CSysInternalLink* _link);


	// 增加一个节点的信息
	// _DirectNode: 节点指针
	// 仅更新节点队列中的数据
	// 返回值，新节点在队列中的指针
	CSysInternalNode* AddNode(CSysInternalNode* _node);

	// 更新一个链路信息
	// 若存在连接链路两端节点的链路，则更新链路状态
	// 若不存在，则插入新的链路
	void UpdateLinks(CSysInternalLink* _pLink);

	// 通过socket获取连接的本地TCP信息
	// _socketID: IN 连接socket
	// _nPort: IN & OUT 本链接的本地TCP端口
	// _strIp: IN & OUT 本链接的本地IP地址
	// 返回值: 成功true；失败false
	bool GetLocalTcpLinkInfo(int _socketID, int &_nPort, string &_strIp);

	// 根据Session获取连接的对端TCP信息
	bool GetRemoteTcpLinkInfo(int _socketID, int &_nPort, string &_strIp);
	
private:
	// 用于保存上传信息的会话
	CFTDCSession* m_SendSession;

	///发送数据包缓冲区
	CFTDCPackage m_pkgSend;

	// 所保存的链接关系的根节点
	// 即本节点自身
	CSysInternalNode m_RootNode;

	// 已知的所有节点信息
	map<string, CSysInternalNode*> m_mapNodes;

	// 所保存的链接关系
	vector<CSysInternalLink*> m_TopologyLinks;
};

#endif	// REF_SYSINTERNALTOPOLOGY_H