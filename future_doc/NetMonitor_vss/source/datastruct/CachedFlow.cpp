// CachedFlow.cpp: implementation of the CCachedFlow class.
//
// 20070828 �Ժ�� �޸��쳣�˳��ķ�ʽ
// 20090310 �Ժ�� ����DeatchUnderFlow����������ȡ����ҽӵ���(NT-0069)
// 20100421 ����   NT-0098���޸�CCachedFlow��GetCountPtr�����������ڲ����ļ����������Ҳ��������ʹ��
// 20110624 ����   NT-0139 �ӿ���Ӧʱ��
// 20110901 �Ժ�� NT-0150 ����CCachedFlow::GetData��������֧���޸Ļ�����������
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "CachedFlow.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCachedFlow::CCachedFlow(bool bSyncFlag, int nMaxObjects, int nDataBlockSize)
:m_CacheList(nDataBlockSize)
{
	m_nMaxObjects = nMaxObjects;
	m_nDataBlockSize = nDataBlockSize;
	m_pUnderFlow = NULL;
	m_bSyncFlag = bSyncFlag;
	m_nCommPhaseNo = 0;
	Clear();
}

CCachedFlow::~CCachedFlow()
{
	delete m_pUnderFlow;
	m_pUnderFlow = NULL;
}

void CCachedFlow::Clear()
{
	m_nFirstID = 0;
	m_NodeQueue.clear();
	m_CacheList.Clear();	
}

int CCachedFlow::AttachUnderFlow(CFlow *pFlow)
{
	m_pUnderFlow = pFlow;

	m_nCommPhaseNo = pFlow->GetCommPhaseNo();

	//��ջ���
	Clear();
	
	//���²����Ķ������뻺��
	char *buf = new char[m_nDataBlockSize];
	for(int i=0; i<m_pUnderFlow->GetCount(); i++){
		int len = m_pUnderFlow->Get(i, buf, m_nDataBlockSize);
		Append(buf, len);
	}
	delete buf;

	return 0;
}
	
CFlow *CCachedFlow::DeatchUnderFlow()
{
	CFlow *pFlow = m_pUnderFlow;
	m_pUnderFlow = NULL;
	return pFlow;
}
	
int CCachedFlow::GetCount(void)
{
	return m_NodeQueue.size();
}

const int *CCachedFlow::GetCountPtr(void)
{
	if (m_pUnderFlow == NULL)
	{
		return m_NodeQueue.GetCountPtr();
	}

	return m_pUnderFlow->GetCountPtr();
}

int CCachedFlow::Append(void *pObject, int length)
{
	int nCount = m_NodeQueue.size();
	if( m_nMaxObjects>0 && nCount-m_nFirstID>=m_nMaxObjects){
		if(m_pUnderFlow != NULL && 
			m_pUnderFlow->GetCount()<m_nFirstID){
			//��ʱ���뻺��ᵼ��ĳ������Ȳ��ڻ����У�Ҳ�����²����У�
			//���,��������·���-1,��ʾAppendʧ��
			return -1;
		}
		PopFront();
	}
	TCachedFlowNode node;
	node.address = m_CacheList.PushBack(pObject, length);
	node.size = length;
	m_NodeQueue.push_back(node);
	if (m_bSyncFlag) 
	{
		SyncUnderFlow(nCount);
	}

	// �����Զ�֪ͨʱ������
	if (m_bAutoNotify)
	{
		// ֪ͨ
		CFlow::Notify();
	}

	return nCount;
}
	
int CCachedFlow::Get(int id, void *pObject, int length)
{
	if(id >= m_nFirstID){			//Ҫ�ҵĶ����ڻ�����
		TCachedFlowNode node = m_NodeQueue[id];
		if(node.size > length){		//��ȡ����Ļ�����̫С
			EMERGENCY_EXIT("Insufficient buffer length while reading CFlow");
		}
		memcpy(pObject, node.address, node.size);
		return node.size;
	}
	else if (m_pUnderFlow != NULL)
	{
		return m_pUnderFlow->Get(id, pObject, length);
	}
	return -1;
}

int CCachedFlow::GetUnderCount()
{
	if(m_pUnderFlow == NULL){
		return -1;
	}
	return m_pUnderFlow->GetCount();
}

int CCachedFlow::SyncUnderFlow(int id)
{
	int undercount = GetUnderCount();
	if(id != undercount){
		return -1;
	}

	if(GetCount() == undercount){
		return -1;
	}

	TCachedFlowNode node = m_NodeQueue[undercount];
	m_pUnderFlow->Append(node.address, node.size);	
	return 0;
}


WORD CCachedFlow::GetCommPhaseNo()
{
	return m_nCommPhaseNo;
}
	
void CCachedFlow::SetCommPhaseNo(WORD nCommPhaseNo)
{
	if (m_nCommPhaseNo != nCommPhaseNo)
	{
		Clear();
		m_nCommPhaseNo = nCommPhaseNo;
	}
	if (m_pUnderFlow != NULL)
	{
		m_pUnderFlow->SetCommPhaseNo(nCommPhaseNo);
	}
}

bool CCachedFlow::Truncate(int nCount)
{
	if (m_pUnderFlow != NULL)
	{
		// 20100506 �Ժ���޸�ԭǰ���߼�����
		if(!m_pUnderFlow->Truncate(nCount))
		{
			return false;
		}
		AttachUnderFlow(m_pUnderFlow);
	}
	return true;
}

bool CCachedFlow::PopFront()
{
	if (m_nFirstID >= GetCount())
	{
		return false;
	}
	m_CacheList.PopFront( m_NodeQueue[m_nFirstID].size );
	m_NodeQueue[m_nFirstID].address = NULL;
	m_nFirstID++;
	return true;
}

void *CCachedFlow::GetData(int id, int *pDataLen)
{
	if(id < m_nFirstID || id>=GetCount())
	{
		return NULL;
	}
	TCachedFlowNode node = m_NodeQueue[id];
	if (pDataLen != NULL)
	{
		*pDataLen = node.size;
	}
	return node.address; 
}
