/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CDatabaseResource.h
///@brief��������CDatabaseResource
///@history 
///20060126	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef CDATABASERESOURCE_H
#define CDATABASERESOURCE_H

#include "platform.h"
#include "CBaseObject.h"
#include "CResource.h"

#define CREATE_ACTION 1
#define DELETE_ACTION 2
#define UPDATE_ACTION 4
#define NONE_ACTION 0

/////////////////////////////////////////////////////////////////////////
///CDatabaseResource��һ��˵�������ݿ���ʹ�õ�����
///@author	���ض�
///@version	1.0,20060126
/////////////////////////////////////////////////////////////////////////
class CDatabaseResource: public CResource
{
public:
	///���췽��
	CDatabaseResource(void)
	{
	}

	///���췽��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ
	CDatabaseResource(int type,bool updateIndex);

	///��ȡ����Դ������
	///@return	CREATE_ACTION��DELTE_ACTION��UPDATE_ACTION����NONE_ACTION
	int getResourceType(void)
	{
		return m_type;
	}

	///����һ����Դ�ϲ�
	///@param	pResource	Ҫ�ϲ�����һ����Դ
	///@return	RESOURCE_MERGE_OK��ʾ�ϲ��ɹ���
	///			RESOURCE_MERGE_FAIL_THIS��ʾ�����ϲ�ʧ�ܣ����ǻ����Գ���������
	///			RESOURCE_MERGE_FAIL_ALL��ʾ�ϲ�ȫ��ʧ�ܣ�������Ҳ���ó�����
	virtual int merge(CResource *pResource);
protected:
	///�����Դ����
	///���ڲ�ͬ���͵���Դ����Ҫָ����ͬ�����ã�getRef�ķ���ֵ����
	///����				����ʱ
	///CREATE_ACTION	�����Ķ���
	///UPDATE_ACTION	�޸ĵĶ���
	///DELETE_ACTION	ɾ���Ķ���
	///NONE_ACTION		NULL
	int m_type;

	///�Ƿ���Ҫ��������
	bool m_updateIndex;
};

#endif
