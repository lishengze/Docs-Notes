/////////////////////////////////////////////////////////////////////////
///@system ִ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file BaseDataStruct.h
///@brief�������ڴ����ݿ��õĻ������ݽṹ�࣬�Լ�iterator��trigger�Ļ���
///@history 
///20060128	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef BASEDATASTRUCT_H
#define BASEDATASTRUCT_H

#include "platform.h"
#include "CBaseObject.h"
#include "customDataType.h"
#include "CTransaction.h"

///�жϽ���Ƿ���������
extern bool satisfy(int value,int type);

///�ַ����ȽϺ���
///@param	s1	�ַ���1
///@param	s2	�ַ���2
///@return	1��ʾ���ڣ�0��ʾ���ڣ�-1��ʾС��
int compare(const char *s1, const char *s2);

///�����ȽϺ���
///@param	v1	����1
///@param	v2	����2
///@return	1��ʾ���ڣ�0��ʾ���ڣ�-1��ʾС��
int compare(const int v1,const int v2);

///64λ�޷��������ȽϺ���
///@param	v1	����1
///@param	v2	����2
///@return	1��ʾ���ڣ�0��ʾ���ڣ�-1��ʾС��
int compare(const QWORD v1,const QWORD v2);

///�������ȽϺ���
///@param	v1	������1
///@param	v2	������2
///@return	1��ʾ���ڣ�0��ʾ���ڣ�-1��ʾС��
int compare(const double v1,const double v2);

///��buffer�л�ȡ��һ��token�������token���Զ��Ż��߻��зָ���
///��ʹ��ʱ����һ��Ӧ������ָ����buffer���Ժ�Ӧ����������NULL��
///������������ȡ�����е�token�����������ı�buffer�е����ݣ�����
///���������Լ��������ݡ����������������⣬��һ��ȡtoken�����н�
///��ǰ����ʼ�µ�һ��ȡtoken���У���Ӱ��ǰ��һ���Ľ�����������
///strtok����������
///@param	buffer	Ҫȡtoken��buffer��NULL��ʾ���ϴ�ȡ��buffer��ȡ��һ��
///@return	�õ���token
char *getNextToken(char *buffer);

class CWriteableMonitorEntity;
class CMonitorEntityFactory;
class CWriteableEventEntity;
class CEventEntityFactory;

/////////////////////////////////////////////////////////////////////////
///CWriteableMonitorEntity��һ���洢���ʵ��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableMonitorEntity
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! MonitorObject.isValid())
			return 0;
		if (! MonitorItem.isValid())
			return 0;
		if (! MonitorTime.isValid())
			return 0;
		if (! Time.isValid())
			return 0;
		if (! ValueType.isValid())
			return 0;
		if (! AttrValue.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableMonitorEntity *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��ض���
	CMonitorObjectType MonitorObject;
	///���ָ����
	CMonitorItemType MonitorItem;
	///���ʱ��
	CMonitorTimeType MonitorTime;
	///ʱ���ַ�����ʽ
	CTimeType Time;
	///���ָ���ֵ����
	CValueTypeType ValueType;
	///���ָ��ľ���ֵ
	CAttrValueType AttrValue;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableMonitorEntity CMonitorEntity;

/////////////////////////////////////////////////////////////////////////
///CMonitorEntityActionTrigger�ǲ������ʵ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMonitorEntityActionTrigger
{
public:
	///���췽��
	CMonitorEntityActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CMonitorEntityActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CMonitorEntityFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pMonitorEntity	Ҫ�����MonitorEntity
	virtual void beforeAdd(CWriteableMonitorEntity *pMonitorEntity)
	{
		return;
	}
	
	///����󴥷�
	///@param	pMonitorEntity	�Ѿ������MonitorEntity
	virtual void afterAdd(CMonitorEntity *pMonitorEntity)
	{
		return;
	}

	///����ǰ����	
	///@param	pMonitorEntity	��ˢ�µ�CMonitorEntity
	///@param	pNewMonitorEntity	�µ�ֵ
	virtual void beforeUpdate(CMonitorEntity *pMonitorEntity, CWriteableMonitorEntity *pNewMonitorEntity)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pMonitorEntity	��ˢ�µ�CMonitorEntity
	virtual void afterUpdate(CMonitorEntity *pMonitorEntity)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pMonitorEntity	Ҫɾ����CMonitorEntity
	virtual void beforeRemove(CMonitorEntity *pMonitorEntity)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CMonitorEntityFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMonitorEntityCommitTrigger��ȷ�ϼ��ʵ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMonitorEntityCommitTrigger
{
public:
	///���췽��
	CMonitorEntityCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CMonitorEntityCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CMonitorEntityFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pMonitorEntity	�Ѿ������MonitorEntity
	virtual void commitAdd(CMonitorEntity *pMonitorEntity)
	{
		return;
	}

	///���º󴥷�
	///@param	pMonitorEntity	��ˢ�µ�CMonitorEntity
	///@param	poldMonitorEntity	ԭ����ֵ
	virtual void commitUpdate(CMonitorEntity *pMonitorEntity, CWriteableMonitorEntity *pOldMonitorEntity)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pMonitorEntity	�Ѿ�ɾ����CMonitorEntity
	virtual void commitRemove(CWriteableMonitorEntity *pMonitorEntity)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CMonitorEntityFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMonitorEntityIterator��һ���Լ��ʵ���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMonitorEntityIterator
{
public:
	///���췽��
	CMonitorEntityIterator(void)
	{
	}

	///���췽��
	CMonitorEntityIterator(CMonitorEntityFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMonitorEntityIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��MonitorEntity
	///@return	��һ����������CMonitorEntity������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMonitorEntity *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CMonitorEntityFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMonitorEntity ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMonitorEntity * pMonitorEntity,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CMonitorEntityFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableEventEntity��һ���洢�¼�ʵ��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableEventEntity
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! MonitorTime.isValid())
			return 0;
		if (! EventName.isValid())
			return 0;
		if (! MonitorObject.isValid())
			return 0;
		if (! EventDes.isValid())
			return 0;
		if (! ProcessFlag.isValid())
			return 0;
		if (! Time.isValid())
			return 0;
		if (! WarningLevel.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableEventEntity *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���ʱ��
	CMonitorTimeType MonitorTime;
	///�¼���
	CMonitorItemType EventName;
	///��ض���ID
	CMonitorObjectType MonitorObject;
	///�¼�����
	CTypeDescriptionType EventDes;
	///�¼��������
	CTypeProcessFlagType ProcessFlag;
	///ʱ���ַ�����ʽ
	CTimeType Time;
	///��־�¼�����
	CTypeWarningLevelType WarningLevel;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableEventEntity CEventEntity;

/////////////////////////////////////////////////////////////////////////
///CEventEntityActionTrigger�ǲ����¼�ʵ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CEventEntityActionTrigger
{
public:
	///���췽��
	CEventEntityActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CEventEntityActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CEventEntityFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pEventEntity	Ҫ�����EventEntity
	virtual void beforeAdd(CWriteableEventEntity *pEventEntity)
	{
		return;
	}
	
	///����󴥷�
	///@param	pEventEntity	�Ѿ������EventEntity
	virtual void afterAdd(CEventEntity *pEventEntity)
	{
		return;
	}

	///����ǰ����	
	///@param	pEventEntity	��ˢ�µ�CEventEntity
	///@param	pNewEventEntity	�µ�ֵ
	virtual void beforeUpdate(CEventEntity *pEventEntity, CWriteableEventEntity *pNewEventEntity)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pEventEntity	��ˢ�µ�CEventEntity
	virtual void afterUpdate(CEventEntity *pEventEntity)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pEventEntity	Ҫɾ����CEventEntity
	virtual void beforeRemove(CEventEntity *pEventEntity)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CEventEntityFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CEventEntityCommitTrigger��ȷ���¼�ʵ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CEventEntityCommitTrigger
{
public:
	///���췽��
	CEventEntityCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CEventEntityCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CEventEntityFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pEventEntity	�Ѿ������EventEntity
	virtual void commitAdd(CEventEntity *pEventEntity)
	{
		return;
	}

	///���º󴥷�
	///@param	pEventEntity	��ˢ�µ�CEventEntity
	///@param	poldEventEntity	ԭ����ֵ
	virtual void commitUpdate(CEventEntity *pEventEntity, CWriteableEventEntity *pOldEventEntity)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pEventEntity	�Ѿ�ɾ����CEventEntity
	virtual void commitRemove(CWriteableEventEntity *pEventEntity)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CEventEntityFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CEventEntityIterator��һ�����¼�ʵ���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CEventEntityIterator
{
public:
	///���췽��
	CEventEntityIterator(void)
	{
	}

	///���췽��
	CEventEntityIterator(CEventEntityFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CEventEntityIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��EventEntity
	///@return	��һ����������CEventEntity������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CEventEntity *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CEventEntityFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pEventEntity ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableEventEntity * pEventEntity,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CEventEntityFactory *m_Factory;	
};


#include "databaseFactories.h"

#endif


