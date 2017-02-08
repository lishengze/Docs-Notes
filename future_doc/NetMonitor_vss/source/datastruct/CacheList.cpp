// CacheList.cpp: implementation of the CCacheList class.
//
// 2006.10.25 修改CCacheList的析构，防止CCacheNode析构递归调用
// 20110901 赵鸿昊 NT-0150 CCacheNode::PushBack增加对传入数据指针的判断，以支持预留空间
//////////////////////////////////////////////////////////////////////

#include "public.h"
#include "CacheList.h"
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
/**发送链表的结点
* 每个结点可以缓存多个数据块
*/
class  CCacheNode
{
public:
	CCacheNode(int nBufSize)
	{
		m_nBufSize = nBufSize;
		m_pBuffer = new char [m_nBufSize];
		m_nLength = 0;
		m_pData = m_pBuffer;
		m_pNext = NULL;
	}

	~CCacheNode()
	{
		delete m_pBuffer;
	}

	/**取出缓冲区头上的一块数据
	* @param len 输入：希望取出的数据长度；输出：实际取到的长度，不超过输入参数
	* @return 取到的数据。若未取到数据则为空
	*/
	void *GetData(int &len)
	{
		if(m_nLength == 0){
			return NULL;
		}
		len = (m_nLength<len)?m_nLength:len;
		return m_pData;
	}

	/**将缓冲区最前面的数据移丢弃
	* @param len 丢弃数据的长度
	* @return 实际丢弃数据的长度
	*/
	int PopFront(int len)
	{
		if(len >m_nLength) 
			len = m_nLength;

		m_pData += len;
		m_nLength -= len;
		return len;
	}
	
	/**向缓冲区尾部加入一块数据
	* @param pData 加入数据的指针
	* @param nDataLen 加入数据的长度
	* @return 加入缓冲区的地址
	*/
	void *PushBack(void *pData, int nDataLen)
	{
		char *pTarget = m_pData+m_nLength;
		if(pTarget+nDataLen > m_pBuffer+m_nBufSize){
			if (m_nLength == 0) 
			{
				m_pData = m_pBuffer;
				pTarget = m_pData;
			}
			else
			{
				//缓冲区已满
				return NULL;
			}
		}
		if (pData != NULL)
		{
			memcpy(pTarget, pData, nDataLen);
		}
		m_nLength += nDataLen;
		return pTarget;
	}

	void SetNext(CCacheNode *pNext)
	{
		m_pNext = pNext;
	}

	CCacheNode *GetNext()
	{
		return m_pNext;
	}

	int GetLength()
	{
		return m_nLength;
	}
private:
	int m_nBufSize;			/**< 缓冲区长度 */
	char *m_pBuffer;		/**< 缓冲区指针 */
	int m_nLength;			/**< 本结点的数据长度 */
	char *m_pData;			/**< 针向实际的数据块 */
	CCacheNode *m_pNext;	/**< 下一个结点的指针 */
};


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCacheList::CCacheList(int nDataBlockSize)
{
	m_nDataBlockSize = nDataBlockSize;
	m_pCacheHead = new CCacheNode(nDataBlockSize);
	m_pCacheTail = m_pCacheHead;
}

CCacheList::~CCacheList()
{
	CCacheNode *pNode = m_pCacheHead;
	CCacheNode *pNext = NULL;
	while (pNode != NULL)
	{
		pNext = pNode->GetNext();
		delete pNode;
		pNode = pNext;
	}
}

void *CCacheList::PushBack(void *pData,int nDataLen)
{
	void *pTarget = m_pCacheTail->PushBack(pData, nDataLen);
	if(pTarget != NULL)
	{
		return pTarget;
	}

	//最后的结点空间已经用完，分配一个新的结点
	CCacheNode *pNode = new CCacheNode(m_nDataBlockSize);
	m_pCacheTail->SetNext(pNode);
	m_pCacheTail = pNode;

	//直接将数据复制进最后的结点
	pTarget = m_pCacheTail->PushBack(pData, nDataLen);
	return pTarget;
}

int CCacheList::PopFront(int len)
{
	int poplen = m_pCacheHead->PopFront(len);	
	if(m_pCacheHead->GetLength() <= 0)
	{
		CCacheNode *pNext = m_pCacheHead->GetNext();
		if(pNext != NULL)
		{
			m_pCacheHead->SetNext(NULL);
			delete m_pCacheHead;
			m_pCacheHead = pNext;
		}
		else
		{
			m_pCacheTail = m_pCacheHead;
		}
	}
	return poplen;
}

void *CCacheList::GetData(int &nLength)
{
	return (char *)m_pCacheHead->GetData(nLength);
}

bool CCacheList::IsEmpty()
{
	int len = 1;
	return (GetData(len)==NULL);
}

void CCacheList::Clear()
{
	while(m_pCacheHead->GetLength() > 0)
	{
		PopFront(m_pCacheHead->GetLength());
	}
}
