// OrderingQ.cpp: implementation of the COrderingQ class.
//
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "OrderingQ.h"

struct CDataItem
{
	void *pData;
	int nDataLen;
	bool bDelivered;
};

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

COrderingQ::COrderingQ(int nMaxSlot, int nDataBlockSize)
:m_cacheList(nDataBlockSize)
{
	m_nMaxSlot = nMaxSlot;
	m_pSlot = new CDataItem *[m_nMaxSlot];

	m_nMaxDataItem = 2*m_nMaxSlot;
	m_pDataItem = new CDataItem[m_nMaxDataItem];

	Clear();
}

COrderingQ::~COrderingQ()
{
	delete m_pSlot;
	delete m_pDataItem;
}

void COrderingQ::Clear()
{
	memset(m_pSlot, 0, sizeof(CDataItem *)*m_nMaxSlot);
	memset(m_pDataItem, 0, sizeof(CDataItem)*m_nMaxDataItem);
	m_nSlotHead = 0;
	m_nDataItemHead = 0;
	m_nDataItemTail= 0;
	
	m_nStartIndex = 1;			//��1��ʼ
}

bool COrderingQ::EnQueue(int nIndex, void *pData, int nDataLen)
{
	//����¼������Ų���slot��Χ�ڣ��򷵻�ʧ��
	if (nIndex<m_nStartIndex || nIndex>=m_nStartIndex+m_nMaxSlot)
	{
		return false;
	}

	CDataItem **pSlot = &m_pSlot[(m_nSlotHead+nIndex-m_nStartIndex)%m_nMaxSlot];
	//�����ظ�������
	if (*pSlot != NULL)
	{
		return false;
	}

	//�����ݿ����cacheList,������dataitem
	CDataItem *pDataItem = &m_pDataItem[m_nDataItemTail];
	pDataItem->bDelivered = false;
	pDataItem->pData = m_cacheList.PushBack(pData, nDataLen);
	pDataItem->nDataLen = nDataLen;

	m_nDataItemTail ++;
    if (m_nDataItemTail >= m_nMaxDataItem)
    {
		m_nDataItemTail = 0;
	}
	
	//��dataitem����slot
	*pSlot = pDataItem;

	return true;
}

void COrderingQ::DeQueue()
{
	CDataItem **pSlot = &m_pSlot[m_nSlotHead];
	if (*pSlot != NULL)
	{
		(*pSlot)->bDelivered = true;
		*pSlot = NULL;
	}
	
	m_nSlotHead ++;
    if (m_nSlotHead >= m_nMaxSlot)
    {
		m_nSlotHead = 0;
	}
	
	while (m_nDataItemHead != m_nDataItemTail)
	{
		CDataItem *pDataItem = &m_pDataItem[m_nDataItemHead];
		if (!pDataItem->bDelivered)
		{
			break;
		}
		m_cacheList.PopFront(pDataItem->nDataLen);
		
		m_nDataItemHead++;
		if (m_nDataItemHead >= m_nMaxDataItem)
		{
			m_nDataItemHead = 0;
		}
	}

	m_nStartIndex++;
	
}

void *COrderingQ::QueueFront(int &nDataLen)
{
	CDataItem **pSlot = &m_pSlot[m_nSlotHead];
	if ( *pSlot == NULL)
	{
		return NULL;
	}

	nDataLen = (*pSlot)->nDataLen;
	return (*pSlot)->pData;
}

/*
#if 0
#include "public.h"
#include "OrderingQ.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
	COrderingQ oq(10, 4000);

	char buf[100];

	srand((unsigned)time(NULL));
	for (;;)
	{
		int n = rand()%10000;
		sprintf(buf, "%d", n);
		oq.EnQueue(n, buf, 100);

		if (oq.GetStartIndex() > 3000)
		{
			break;
		}
		int len;
		char *p = (char *)oq.QueueFront(len);
		if (p != NULL)
		{
			printf("package:[%s] [%d]\n", p, oq.GetStartIndex());
			oq.DeQueue();
		}
	}

	return 0;
}
#endif
*/
