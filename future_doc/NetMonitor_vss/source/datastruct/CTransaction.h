/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CTransaction.h
///@brief��������CTransaction
///@history 
///20020301	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef CTRANSACTION_H
#define CTRANSACTION_H

#include "platform.h"
#include "CResource.h"
#include "MemoryStack.h"

class CTransaction;

//////////////////////////////////////////////////////////////////////////
///CTransactionSavePoint����һ�������еı���㡣ʹ���������㣬����ʵ��
///����Ĳ��ֻع�
///@author	���ض�
///@version	1.0,20060126
//////////////////////////////////////////////////////////////////////////
class CTransactionSavePoint:public CResource
{
public:
	CTransactionSavePoint(void)
	{
		ref=NULL;
	}
/*
	///���캯��
	///@param	pTransaction	Ҫ����savepoint��transaction
	CTransactionSavePoint(CTransaction *pTransaction);
*/
	~CTransactionSavePoint(void);

	///����ύ
	virtual void commit(void)
	{
	}

	///��ɹ���
	virtual void rollback(void)
	{
	}

	///����һ����Դ�ϲ�
	///@param	pResource	Ҫ�ϲ�����һ����Դ
	///@return	RESOURCE_MERGE_OK��ʾ�ϲ��ɹ���
	///			RESOURCE_MERGE_FAIL_THIS��ʾ�����ϲ�ʧ�ܣ����ǻ����Գ���������
	///			RESOURCE_MERGE_FAIL_ALL��ʾ�ϲ�ȫ��ʧ�ܣ�������Ҳ���ó�����
	virtual int merge(CResource *pResource)
	{
		return RESOURCE_MERGE_FAIL_ALL;
	}
	
	///���빹�캯��
	///@param	pTransaction	Ҫ����savepoint��transaction
	static CTransactionSavePoint* alloc(CTransaction *pTransaction);
	
	///�ͷź���
	virtual void free(void);

	///�Ƿ������Դ��Ŀǰֻ��savepoint�ǿ�����Դ
	///@return	true��ʾ�ǣ�false��ʾ��
	virtual bool isControl(void)
	{
		return true;
	}
private:
	CTransaction *m_Transaction;
	static CMemoryStack<CTransactionSavePoint> resourceList;
};


/////////////////////////////////////////////////////////////////////////
///CTransaction��һ�����񣬿��Թҽ�һ����Դ�����ͬ���ύ�����
///CTransaction�̳���CResource������ʵ�ֲ���Ե����������һ��CTransaction
///�е�һ��CResource����Ҳ��һ��CTransaction
///@author	���ض�
///@version	1.0,20020301
/////////////////////////////////////////////////////////////////////////
class CTransaction : public CResource, protected vector<CResource *>
{
public:
	friend class CTransactionSavePoint;

	//���췽��
	CTransaction(void);

	///��������
	virtual ~CTransaction(void);
	
	///�ڱ������м���һ����Դ��ע�⣬Ҫ�������Դ�������ⲿ������
	///������CTransaction����ɾ��
	///@param	pResource	��Ҫ�������Դ
	void addResource(CResource *pResource)
	{
		if (mergeBack(size(),pResource,false))
		{
			///�ϲ��ɹ����ǾͲ��ü���
			pResource->free();
		}
		else
		{
			///�ϲ����ɹ����Ǿ�Ҫ����
			push_back(pResource);
		}
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///����һ����Դ�ϲ�
	///@param	pResource	Ҫ�ϲ�����һ����Դ
	///@return	RESOURCE_MERGE_OK��ʾ�ϲ��ɹ���
	///			RESOURCE_MERGE_FAIL_THIS��ʾ�����ϲ�ʧ�ܣ����ǻ����Գ���������
	///			RESOURCE_MERGE_FAIL_ALL��ʾ�ϲ�ȫ��ʧ�ܣ�������Ҳ���ó�����
	virtual int merge(CResource *pResource)
	{
		return RESOURCE_MERGE_FAIL_THIS;
	}

	///�ع���ָ����λ�ã����û��ָ������λ�ã����൱��ȫ��rollback��
	///������㽫��������������ʹ��
	///@param	pSavePoint	Ҫ�ع����ı����
	virtual void rollbackToSavePoint(CTransactionSavePoint *pSavePoint);

private:
	///�����ع��㣬��ҪҪ����ı����������ⲿ������
	///������CTransaction����ɾ��
	///@param	pSavePoint	Ҫ�����ı����
	virtual void setSavePoint(CTransactionSavePoint *pSavePoint);

	///������ǰ�����Դ�ϲ�
	///@param	pos	ָ����Ժϲ������һ����Դ���һ����Դ���±�
	///@param	pResource	Ҫ���ϲ�����Դ
	///@param	forceMerge	�Ƿ�ǿ�ƺϲ���true��ʾ��ʹ����Դ��ʾȫ��ʧ�ܣ�Ҳ��Ҫ�������Ժϲ�
	///@return	true��ʾ�Ѿ����ϲ��ˣ�false��ʾû�б��ϲ�
	bool mergeBack(int pos,CResource *pResource,bool forceMerge)
	{
		for (pos--;pos>=0;pos--)
		{
			if (at(pos)->getRef()==NULL)
			{
				if (!forceMerge)
				{
					return false;
				}
				else
				{
					continue;
				}
			}
			if (at(pos)->getRef()!=pResource->getRef())
			{
				continue;
			}
			switch (at(pos)->merge(pResource))
			{
			case RESOURCE_MERGE_OK:
				///�ϲ��ɹ�
				return true;
			case RESOURCE_MERGE_FAIL_THIS:
				///���û�кϲ��ɹ���Ӧ��������һ��
				break;
			case RESOURCE_MERGE_FAIL_ALL:
				///ȫ��ʧ��
				if (!forceMerge)
				{
					//����������
					return false;
				}
				break;
			}
		}
		return false;
	}

	///�Ѿ������ı��������
	int m_SavePointCount;
};

#endif
