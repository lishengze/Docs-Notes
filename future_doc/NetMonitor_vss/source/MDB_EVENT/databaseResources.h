/////////////////////////////////////////////////////////////////////////
///@system ִ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file databaseResources.h
///@brief�����������ڴ�������Դ�����Է�����������
///@history 
///20060127	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef DATABASERESOURCES_H
#define DATABASERESOURCES_H

#include "databaseData.h"
#include "MemoryStack.h"

/////////////////////////////////////////////////////////////////////////
///CMonitorEntityResource��һ��˵����CMonitorEntityFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMonitorEntityResource : public CDatabaseResource
{
public:
	///���췽��
	CMonitorEntityResource(void);
	virtual ~CMonitorEntityResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CMonitorEntityFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CMonitorEntityFactory *pFactory, CMonitorEntity *pObject, CWriteableMonitorEntity *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CMonitorEntityFactory
	///@return	��CMonitorEntityFactory
	CMonitorEntityFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CMonitorEntityFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CMonitorEntityResource *alloc(int type, CMonitorEntityFactory *pFactory, CMonitorEntity *pObject, CWriteableMonitorEntity *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CMonitorEntityFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableMonitorEntity writeableObject;
	
	static CMemoryStack<CMonitorEntityResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CEventEntityResource��һ��˵����CEventEntityFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CEventEntityResource : public CDatabaseResource
{
public:
	///���췽��
	CEventEntityResource(void);
	virtual ~CEventEntityResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CEventEntityFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CEventEntityFactory *pFactory, CEventEntity *pObject, CWriteableEventEntity *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CEventEntityFactory
	///@return	��CEventEntityFactory
	CEventEntityFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CEventEntityFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CEventEntityResource *alloc(int type, CEventEntityFactory *pFactory, CEventEntity *pObject, CWriteableEventEntity *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CEventEntityFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableEventEntity writeableObject;
	
	static CMemoryStack<CEventEntityResource> resourceList;
};

#endif
