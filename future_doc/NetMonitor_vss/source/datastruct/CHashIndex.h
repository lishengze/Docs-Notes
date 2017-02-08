/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CHashIndex.h
///@brief	��������CHashIndex
///@history 
///20020611	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef CHASHINDEX_H
#define CHASHINDEX_H

#include "platform.h"
#include "CBaseObject.h"
#include "CFixMem.h"
#include "Allocator.h"

/////////////////////////////////////////////////////////////////////////
///CHashIndexNode��һ��Hash�ڵ����
///@author	���ض�
///@version	1.0,20020611
/////////////////////////////////////////////////////////////////////////
class CHashIndexNode
{
public:
	///���汾�ڵ��а����Ķ���
	const void *pObject;
	///������һ���ڵ�
	CHashIndexNode *next;
};

/////////////////////////////////////////////////////////////////////////
///CHashIndex��һ��Hash�����������������Ƕ�ĳ�����͵����ݽṹ���Լ����ϵ�һ�ֱȽϺ�����
///���ɵ�Hash��
///@author	���ض�
///@version	1.0,20020611
/////////////////////////////////////////////////////////////////////////
class CHashIndex
{
public:
	///���캯��������ռ䣬����һ�ÿյ�Hash����
	///@param	hashKeySize	HashKey�Ĵ�С
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	reuse	˵������洢�Ƿ���Ҫ����
	///@param	reuseID	������ʱ���������õı�ţ���������Ӧ��ʹ��-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CHashIndex(int hashKeySize, IMemoryAllocator *pAllocator,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���������������ͷſռ�
	virtual ~CHashIndex(void);

	///��ʼ���������е�Ͱ���
	void init(void);

	///�ڱ�Hash�����м���һ���µĶ���ڵ�
	///@param	pObject	�µĶ�����׵�ַ
	///@param	hashKey	��Ӧ��Hash��
	///@return	����Hash����������˶���Ľڵ�
	CHashIndexNode *addObject(const void *pObject, unsigned int hashKey)
	{
		int pos=hashKey%m_hashKeySize;
		CHashIndexNode *pNode=(CHashIndexNode *)(pIndexMem->getObject(pos));
		if (pNode->pObject==NULL)
		{
			///��Ͱ�ڻ�û�ж����Ǿͷ��ڵ�һ��λ��
			pNode->pObject=pObject;
			return pNode;
		}
		else
		{
			///��Ͱ���Ѿ��ж����ˣ��Ǿͷ��ڵڶ���λ��
			CHashIndexNode *pNewNode=(CHashIndexNode *)(pIndexMem->alloc());
			pNewNode->pObject=pObject;
			pNewNode->next=pNode->next;
			pNode->next=pNewNode;
			return pNewNode;
		}
	}

	///�ڱ�Hash������ɾ��һ������ڵ�
	///@param	pObject	Ҫɾ���Ķ�����׵�ַ
	///@param	hashKey	��Ӧ��Hash��
	///@return	true��ʾɾ���ɹ���false��ʾɾ��ʧ��
	bool removeObject(const void *pObject, unsigned int hashKey)
	{
		int pos=hashKey%m_hashKeySize;
		CHashIndexNode *pNode=(CHashIndexNode *)(pIndexMem->getObject(pos));
		CHashIndexNode *pNextNode;
		if (pNode->pObject==pObject)
		{
			///Ҫɾ�����ǵ�һ������
			if (pNode->next==NULL)
			{
				///û�еڶ��������ˣ��ǰѵ�һ������ɾ���˼���
				pNode->pObject=NULL;
				return true;
			}
			else
			{
				///���滹�еڶ��������Ǿ���Ҫ����һ����������������ɾ������һ������
				pNextNode=pNode->next;
				pNode->pObject=pNextNode->pObject;
				pNode->next=pNextNode->next;
				pIndexMem->free(pNextNode);
				return true;
			}
		}
		else
		{
			///Ҫɾ���Ĳ��ǵ�һ������
			while ((pNextNode=pNode->next)!=NULL)
			{
				if (pNextNode->pObject==pObject)
				{
					///��һ���ڵ����Ҫɾ���Ķ����Ǿ�ɾ����
					pNode->next=pNextNode->next;
					pIndexMem->free(pNextNode);
					return true;
				}
				///����Ѱ����ȥ
				pNode=pNextNode;
			}
			///û���ҵ����Ǿ�ʧ�ܷ���
			return false;
		}
	}

	///ȫ��ɾ��
	void removeAll(void)
	{
		pIndexMem->freeAll();
		///���ض���20070328
		///���������HashIndex��û�аѳ�ʼ��Ͱ���½�����������
		init();
	}

	///Ѱ�ҵ�һ������ĳ��ֵ�Ľڵ�
	///@param hashKey	��Ӧ��Hash��
	///@return	��һ�����ڴ˼�ֵ�Ľڵ㣬��������ڴ˽ڵ㣬�򷵻�NULL
	CHashIndexNode *searchFirstEqual(unsigned int hashKey)
	{
		int pos=hashKey%m_hashKeySize;
		CHashIndexNode *pNode=(CHashIndexNode *)(pIndexMem->getObject(pos));
		if (pNode->pObject==NULL)
		{
			return NULL;
		}
		else
		{
			return pNode;
		}
	}

	///Ѱ����һ������ĳ��ֵ�Ľڵ�
	///@param	pNode	��Եļ�ֵ
	///@return	��һ�����ڴ˼�ֵ�Ľڵ㣬��������ڴ˽ڵ㣬�򷵻�NULL
	CHashIndexNode *searchNextEqual(CHashIndexNode *pNode)
	{
		return pNode->next;
	}

	///��ȡ���ñ��
	///@param	�����������ñ��
	int getReuseID(void)
	{
		return pIndexMem->GetReuseID();
	}

private:
	///�洢�洢Hash������CFixMem
	CFixMem *pIndexMem;
	
	///HashKey�Ĵ�С
	int m_hashKeySize;
};

#endif
