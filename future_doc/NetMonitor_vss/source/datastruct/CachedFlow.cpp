// CachedFlow.cpp: implementation of the CCachedFlow class.
//
// 20070828 赵鸿昊 修改异常退出的方式
// 20090310 赵鸿昊 增加DeatchUnderFlow方法，可以取消其挂接的流(NT-0069)
// 20100421 江鹏   NT-0098：修改CCachedFlow的GetCountPtr方法、让其在不挂文件流的情况下也可以正常使用
// 20110624 江鹏   NT-0139 加快响应时间
// 20110901 赵鸿昊 NT-0150 增加CCachedFlow::GetData方法，以支持修改缓冲区的内容
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

	//清空缓存
	Clear();
	
	//将下层流的对象载入缓存
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
			//这时加入缓存会导致某个对象既不在缓存中，也不在下层流中，
			//因此,这种情况下返回-1,表示Append失败
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

	// 仅当自动通知时才运行
	if (m_bAutoNotify)
	{
		// 通知
		CFlow::Notify();
	}

	return nCount;
}
	
int CCachedFlow::Get(int id, void *pObject, int length)
{
	if(id >= m_nFirstID){			//要找的对象在缓存内
		TCachedFlowNode node = m_NodeQueue[id];
		if(node.size > length){		//获取对象的缓冲区太小
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
		// 20100506 赵鸿昊修改原前的逻辑错误
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
