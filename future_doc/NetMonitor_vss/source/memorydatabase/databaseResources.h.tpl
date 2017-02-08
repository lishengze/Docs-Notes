!!include function.tpl!!
!!enter system!!
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

!!travel tables!!
!!if !strcmp(@hasTable,"yes")!!
!!command resetEntityMap();!!
!!travel fields!!
!!command addEntity(@name,@type)!!
!!next!!
/////////////////////////////////////////////////////////////////////////
///C!!@name!!Resource��һ��˵����C!!@name!!Factory��ʹ����������ԭ����Դ
///@author	!!@author!!
///@version	!!@version!!
/////////////////////////////////////////////////////////////////////////
class C!!@name!!Resource : public CDatabaseResource
{
public:
	///���췽��
	C!!@name!!Resource(void);
!!++!!
	///���췽��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�C!!@name!!Factory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	C!!@name!!Resource(int type, C!!@name!!Factory *pFactory, C!!@name!! *pObject, CWriteable!!@name!! *pWriteableObject, bool updateIndex=true);
!!--!!
	virtual ~C!!@name!!Resource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�C!!@name!!Factory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, C!!@name!!Factory *pFactory, C!!@name!! *pObject, CWriteable!!@name!! *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�C!!@name!!Factory
	///@return	��C!!@name!!Factory
	C!!@name!!Factory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�C!!@name!!Factory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static C!!@name!!Resource *alloc(int type, C!!@name!!Factory *pFactory, C!!@name!! *pObject, CWriteable!!@name!! *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	C!!@name!!Factory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteable!!@name!! writeableObject;
	
	static CMemoryStack<C!!@name!!Resource> resourceList;
};

!!endif!!
!!next!!
#endif
!!leave!!
