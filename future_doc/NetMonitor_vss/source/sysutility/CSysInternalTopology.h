/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CSysInternalTopology.h
///@brief	�����˼��ϵͳ�ڲ�������ģ��֮�����ӹ�ϵ����
///@history
///20140113	����		�������ļ�
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

// ���˽ڵ㣬������ڵ����Ϣ
class CSysInternalNode
{
public:
	string GetNodeID() { return m_NodeID; }
	string GetNodeName() { return m_NodeName; }
	string GetNodeAlias() { return m_NodeAlias; }
	// ��ȡ�ڵ����Ϣ
	string GetNodeInfo();

	void SetNodeInfo(CSysInternalNode* _node);
	void SetNodeID(const char* _sysName, int _sysId);
	void SetNodeID(const char* _nodeId) { m_NodeID = _nodeId; }
	void SetNodeName(string _name) { m_NodeName = _name; }
	void SetNodeAlias(string _alias) { m_NodeAlias = _alias; }

	void Print();

private:
	string m_NodeID;		// �ڵ��ID����sysprobe-1
	string m_NodeName;		// �ڵ������
	string m_NodeAlias;		// �ڵ�ı���
};

// ������·�������νڵ�ָ�롢IP��ַ�Ͷ˿����
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

	CSysInternalLinkState m_LinkState;	// ��·״̬�����߻�����
	time_t m_Time;	// ʱ�䣬����·״̬ΪON����ʾ����ʱ�䣻����·״̬ΪOFF����ʾ�Ͽ�ʱ��

	int m_iSessionID;	// ��·��Ӧ��SessionID����ΪԶ����·����ֵΪ0

	// ����·����Ϣ��֯��string
	string GetLinkInfo();
	// ����·��״̬��Ϣ��֯��string
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
	// �������ڱ�����Ϣ�ĻỰ���ϴ���·��
	void SetSendSessionON(CSession* _session) { m_SendSession = (CFTDCSession*)_session; }
	// �������ڱ�����Ϣ�ĻỰ���ϴ���·��Ϊ�Ͽ�
	void SetSendSessionOFF() { m_SendSession = NULL; }

	// ���ر��ؽڵ��ָ��
	CSysInternalNode* RootNode() { return &m_RootNode; }

	// ���ر��ؽڵ�����
	string RootNodeID() { return m_RootNode.GetNodeID(); }
	// ���ر��ؽڵ���Ϣ��Name+Alias
	string GetRootNodeInfo() { return m_RootNode.GetNodeInfo(); }

	// ���ñ��ؽڵ������
	void SetRootName(string _name) { m_RootNode.SetNodeName(_name); }
	// ���ñ��ؽڵ�ı���
	void SetRootAlias(string _alias) { m_RootNode.SetNodeAlias(_alias); }

	// ���������Ϣ
	void TopologyShow();

public:
	// ���ڴ�����յ���������
	// ͨ�����������ڵ㽨������֮���߼��ϵ��ϲ�ڵ�����²�ڵ㷢��������
	// �ڵ����յ������ĺ󣬻Ὣ���ش洢�����м�����Ϣ����
	void OnReqQrySysInternalTopologyTopic(
		CFTDCPackage *pFTDCPackage, 
		CFTDCSession *pSession);

	// ���ڴ�����յ�����Ӧ����
	// ͨ�����ڵ�����²�ڵ㷢��������
	// Ȼ���²�ڵ�Ὣ�䱣������м�����Ϣͨ����Ӧ���Ļ��ͻ���
	void OnRspQrySysInternalTopologyTopic(
		CFTDCPackage *pFTDCPackage, 
		CFTDCSession *pSession);

	// ���ڴ�����յ���ͨ�汨��
	// ͨ���²�ڵ�ļ�����ϵ�����ı�ʱ�������ϲ�ڵ㷢��ͨ��
	void OnRtnSysInternalTopologyTopic(
		CFTDCPackage *pFTDCPackage, 
		CFTDCSession *pSession);

	// ֱ���ĻỰ�����������²�ڵ�ļ�����Ϣ
	void OnSessionConnected(CSession *pSession);

	// ֱ���ĻỰ�Ͽ���ɾ��һ��ֱ���ڵ�
	// _pSession: ���ոýڵ���Ϣ��Session�����ڻ�ȡ����·��Ϣ��
	void OnSessionDisconnected(CSession* _pSession);

private:
	// ����һ��ֱ���ڵ���Ϣ
		// _pSession: ���ոýڵ���Ϣ��Session�����ڻ�ȡ����·��Ϣ��
		// _DirectNode: ֱ���Ľڵ�ָ��
	void AddDirectNode(
		CSession* _pSession, 
		CSysInternalNode* _directNode);
	
	// ����һ��Զ�˽ڵ���Ϣ
		// _node: Զ�˽ڵ�ָ��
	void UpdateRemoteNode(CSysInternalNode* _node);

	// ����Զ����·����Ϣ
		// _node1: ��·node1��ID
		// _node2: ��·node2��ID
		// _linkInfo: ��·����Ϣ
		// _linkState: ��·��״̬
	void UpdateRemoteLink(
		const char* _node1, 
		const char* _node2, 
		const char* _linkInfo, 
		const char* _linkState);

	// ͨ���ϴ���·���ͽڵ�ĸ�����Ϣ
	void ReportNodeInfo(CSysInternalNode* _node);

	// ͨ���ϴ���·������·�ĸ�����Ϣ
	void ReportLinkInfo(CSysInternalLink* _link);


	// ����һ���ڵ����Ϣ
	// _DirectNode: �ڵ�ָ��
	// �����½ڵ�����е�����
	// ����ֵ���½ڵ��ڶ����е�ָ��
	CSysInternalNode* AddNode(CSysInternalNode* _node);

	// ����һ����·��Ϣ
	// ������������·���˽ڵ����·���������·״̬
	// �������ڣ�������µ���·
	void UpdateLinks(CSysInternalLink* _pLink);

	// ͨ��socket��ȡ���ӵı���TCP��Ϣ
	// _socketID: IN ����socket
	// _nPort: IN & OUT �����ӵı���TCP�˿�
	// _strIp: IN & OUT �����ӵı���IP��ַ
	// ����ֵ: �ɹ�true��ʧ��false
	bool GetLocalTcpLinkInfo(int _socketID, int &_nPort, string &_strIp);

	// ����Session��ȡ���ӵĶԶ�TCP��Ϣ
	bool GetRemoteTcpLinkInfo(int _socketID, int &_nPort, string &_strIp);
	
private:
	// ���ڱ����ϴ���Ϣ�ĻỰ
	CFTDCSession* m_SendSession;

	///�������ݰ�������
	CFTDCPackage m_pkgSend;

	// ����������ӹ�ϵ�ĸ��ڵ�
	// �����ڵ�����
	CSysInternalNode m_RootNode;

	// ��֪�����нڵ���Ϣ
	map<string, CSysInternalNode*> m_mapNodes;

	// ����������ӹ�ϵ
	vector<CSysInternalLink*> m_TopologyLinks;
};

#endif	// REF_SYSINTERNALTOPOLOGY_H