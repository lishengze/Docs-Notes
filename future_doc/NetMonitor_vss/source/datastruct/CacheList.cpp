// CacheList.cpp: implementation of the CCacheList class.
//
// 2006.10.25 �޸�CCacheList����������ֹCCacheNode�����ݹ����
// 20110901 �Ժ�� NT-0150 CCacheNode::PushBack���ӶԴ�������ָ����жϣ���֧��Ԥ���ռ�
//////////////////////////////////////////////////////////////////////

#include "public.h"
#include "CacheList.h"
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
/**��������Ľ��
* ÿ�������Ի��������ݿ�
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

	/**ȡ��������ͷ�ϵ�һ������
	* @param len ���룺ϣ��ȡ�������ݳ��ȣ������ʵ��ȡ���ĳ��ȣ��������������
	* @return ȡ�������ݡ���δȡ��������Ϊ��
	*/
	void *GetData(int &len)
	{
		if(m_nLength == 0){
			return NULL;
		}
		len = (m_nLength<len)?m_nLength:len;
		return m_pData;
	}

	/**����������ǰ��������ƶ���
	* @param len �������ݵĳ���
	* @return ʵ�ʶ������ݵĳ���
	*/
	int PopFront(int len)
	{
		if(len >m_nLength) 
			len = m_nLength;

		m_pData += len;
		m_nLength -= len;
		return len;
	}
	
	/**�򻺳���β������һ������
	* @param pData �������ݵ�ָ��
	* @param nDataLen �������ݵĳ���
	* @return ���뻺�����ĵ�ַ
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
				//����������
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
	int m_nBufSize;			/**< ���������� */
	char *m_pBuffer;		/**< ������ָ�� */
	int m_nLength;			/**< ���������ݳ��� */
	char *m_pData;			/**< ����ʵ�ʵ����ݿ� */
	CCacheNode *m_pNext;	/**< ��һ������ָ�� */
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

	//���Ľ��ռ��Ѿ����꣬����һ���µĽ��
	CCacheNode *pNode = new CCacheNode(m_nDataBlockSize);
	m_pCacheTail->SetNext(pNode);
	m_pCacheTail = pNode;

	//ֱ�ӽ����ݸ��ƽ����Ľ��
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
