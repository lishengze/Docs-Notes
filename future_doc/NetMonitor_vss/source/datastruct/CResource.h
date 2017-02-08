/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CResource.h
///@brief��������CResource
///@history 
///20020228	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef CRESOURCE_H
#define CRESOURCE_H

#define RESOURCE_MERGE_OK	1
#define RESOURCE_MERGE_FAIL_THIS 2
#define RESOURCE_MERGE_FAIL_ALL 3

/////////////////////////////////////////////////////////////////////////
///CResource��һ�������࣬����˵��һ������ʹ������������Դ
///@author	���ض�
///@version	1.0,20020228
/////////////////////////////////////////////////////////////////////////
class CResource
{
protected:
	void *ref;
public:
	///��������
	virtual ~CResource(void)
	{
	}
	
	///����ύ
	virtual void commit(void)=0;
	
	///��ɹ���
	virtual void rollback(void)=0;

	///��ȡ����Դ�����ã�����Ψһ��ʶһ����Դ
	///@return	���ڱ�ʶһ����Դ
	const void *getRef(void)
	{
		return ref;
	}
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///����һ����Դ�ϲ�
	///@param	pResource	Ҫ�ϲ�����һ����Դ
	///@return	RESOURCE_MERGE_OK��ʾ�ϲ��ɹ���
	///			RESOURCE_MERGE_FAIL_THIS��ʾ�����ϲ�ʧ�ܣ����ǻ����Գ���������
	///			RESOURCE_MERGE_FAIL_ALL��ʾ�ϲ�ȫ��ʧ�ܣ�������Ҳ���ó�����
	virtual int merge(CResource *pResource)=0;

	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void)
	{
		return 1;
	}

	///�Ƿ������Դ��Ŀǰֻ��savepoint�ǿ�����Դ
	///@return	true��ʾ�ǣ�false��ʾ��
	virtual bool isControl(void)
	{
		return false;
	}
};

#endif
