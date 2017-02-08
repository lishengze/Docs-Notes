!!include function.tpl!!
!!enter system!!
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

!!travel tables!!
class CWriteable!!@name!!;
!!if !strcmp(@hasTable,"yes")!!
class C!!@name!!Factory;
!!endif!!
!!next!!

!!travel tables!!
!!command resetEntityMap();!!
!!let tableName=@name!!
/////////////////////////////////////////////////////////////////////////
///CWriteable!!@name!!��һ���洢!!@usage!!�Ķ��󣬿���д����
///@author	!!@author!!
///@version	!!@version!!
/////////////////////////////////////////////////////////////////////////
class CWriteable!!@name!!
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
		!!travel fields!!
		if (! !!@name!!.isValid())
			return 0;
		!!next!!
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteable!!@name!! *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	!!travel fields!!
	!!if (!strcmp(@comment,"")==0)!!
	///!!@comment!!
	!!endif!! 
	!!@type!! !!@name!!;
	!!next!!
	!!if valid_name("hashkeys")!!
	!!travel hashkeys!!
	unsigned int Hash!!@name!!;
	
	///����!!@name!!��hashֵ
	void calHash!!@name!!(void)
	{
		!!let hashName=@name!!
		unsigned key=0;
		!!travel self!!
		key=!!@name!!.hash(key);
		!!next!!
		Hash!!@name!!=key;
	}
	
	///������Ҫ���������!!@name!!��hashֵ
	void updateHash!!@name!!(void)
	{
		!!if !strcmp(@stableHashKey,"no")!!
		calHash!!@name!!();
		!!endif!!
	}
	!!next!!
	!!endif!!
	
	///�������е�hashֵ
	void calAllHash(void)
	{
		!!if valid_name("hashkeys")!!
		!!travel hashkeys!!
		calHash!!@name!!();
		!!next!!
		!!endif!!
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
		!!if valid_name("hashkeys")!!
		!!travel hashkeys!!
		updateHash!!@name!!();
		!!next!!
		!!endif!!
	}
	
	!!travel foreigns!!
	///����!!@comment!!��ָ��
	///@param	pFactory	����!!@comment!!��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ���!!@comment!!��ָ��!!if (strcmp(@foreignStrick,"yes"))!!������Ҳ����򷵻�NULL!!endif!!
	!!if (!strcmp(@foreignStrick,"yes"))!!
	///@exception	����Ҳ��������׳�RUNTIME_ERROR
	!!endif!!
	inline const CWriteable!!@factory!! *link!!@name!!(C!!@factory!!Factory *pFactory) const;

	///����!!@comment!!ָ��
	///@param	p!!@factory!!	Ҫ���ӵ��Ķ���
	///@return	�����p!!@factory!!
	const CWriteable!!@factory!! *link!!@name!!(const CWriteable!!@factory!! *p!!@factory!!) const
	{
		void *target=(void *)(&(this->p!!@name!!));
		*((const CWriteable!!@factory!! **)target)=p!!@factory!!;
		return p!!@factory!!;
	}
	
	///��ȡ!!@comment!!��ָ��
	///@return	�ҵ���!!@comment!!��ָ��!!if (strcmp(@foreignStrick,"yes"))!!������Ҳ����򷵻�NULL!!endif!!
	!!if (!strcmp(@foreignStrick,"yes"))!!
	///@exception	����Ҳ��������׳�RUNTIME_ERROR
	!!endif!!
	const CWriteable!!@factory!! *get!!@name!!(void) const
	{
		return p!!@name!!;
	}
	!!next!!

private:
	!!travel foreigns!!
	!!if (!strcmp(@comment,"")==0)!!
	///!!@comment!!
	!!endif!!
	const CWriteable!!@factory!! *p!!@name!!;
	!!next!!
};

typedef const CWriteable!!@name!! C!!@name!!;

!!if !strcmp(@hasTable,"yes")!!
/////////////////////////////////////////////////////////////////////////
///C!!@name!!ActionTrigger�ǲ���!!@usage!!ʱ�Ĵ�����
///@author	!!@author!!
///@version	!!@version!!
/////////////////////////////////////////////////////////////////////////
class C!!@name!!ActionTrigger
{
public:
	///���췽��
	C!!@name!!ActionTrigger(void)
	{
	}
	
	///��������
	virtual ~C!!@name!!ActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(C!!@name!!Factory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	p!!@name!!	Ҫ�����!!@name!!
	virtual void beforeAdd(CWriteable!!@name!! *p!!@name!!)
	{
		return;
	}
	
	///����󴥷�
	///@param	p!!@name!!	�Ѿ������!!@name!!
	virtual void afterAdd(C!!@name!! *p!!@name!!)
	{
		return;
	}

	///����ǰ����	
	///@param	p!!@name!!	��ˢ�µ�C!!@name!!
	///@param	pNew!!@name!!	�µ�ֵ
	virtual void beforeUpdate(C!!@name!! *p!!@name!!, CWriteable!!@name!! *pNew!!@name!!)
	{
		return;
	}
	
	///���º󴥷�
	///@param	p!!@name!!	��ˢ�µ�C!!@name!!
	virtual void afterUpdate(C!!@name!! *p!!@name!!)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	p!!@name!!	Ҫɾ����C!!@name!!
	virtual void beforeRemove(C!!@name!! *p!!@name!!)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	C!!@name!!Factory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///C!!@name!!CommitTrigger��ȷ��!!@usage!!ʱ�Ĵ�����
///@author	!!@author!!
///@version	!!@version!!
/////////////////////////////////////////////////////////////////////////
class C!!@name!!CommitTrigger
{
public:
	///���췽��
	C!!@name!!CommitTrigger(void)
	{
	}
	
	///��������
	virtual ~C!!@name!!CommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(C!!@name!!Factory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	p!!@name!!	�Ѿ������!!@name!!
	virtual void commitAdd(C!!@name!! *p!!@name!!)
	{
		return;
	}

	///���º󴥷�
	///@param	p!!@name!!	��ˢ�µ�C!!@name!!
	///@param	pold!!@name!!	ԭ����ֵ
	virtual void commitUpdate(C!!@name!! *p!!@name!!, CWriteable!!@name!! *pOld!!@name!!)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	p!!@name!!	�Ѿ�ɾ����C!!@name!!
	virtual void commitRemove(CWriteable!!@name!! *p!!@name!!)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	C!!@name!!Factory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///C!!@name!!Iterator��һ����!!@usage!!��ö�����ӿ�
///@author	!!@author!!
///@version	!!@version!!
/////////////////////////////////////////////////////////////////////////
class C!!@name!!Iterator
{
public:
	///���췽��
	C!!@name!!Iterator(void)
	{
	}

	///���췽��
	C!!@name!!Iterator(C!!@name!!Factory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~C!!@name!!Iterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��!!@name!!
	///@return	��һ����������C!!@name!!������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual C!!@name!! *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	C!!@name!!Factory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	p!!@name!! ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteable!!@name!! * p!!@name!!,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	C!!@name!!Factory *m_Factory;	
};

!!endif!!
!!next!!

#include "databaseFactories.h"

!!travel tables!!
!!command resetEntityMap();!!
!!let tableName=@name!!
!!travel foreigns!!
const CWriteable!!@factory!! *CWriteable!!@tableName!!::link!!@name!!(C!!@factory!!Factory *pFactory) const
{
	void *target=(void *)(&p!!@name!!);
	*((const CWriteable!!@factory!! **)target)=pFactory->find!!@method!!(!!@key!!);
	!!if !strcmp(@foreignStrick,"yes")!!
	if (p!!@name!!==NULL)
	{
		RAISE_RUNTIME_ERROR("can not link !!@name!! in !!@tableName!!");
	}
	!!endif!!
	return p!!@name!!;
}

!!next!!
!!next!!
#endif


!!leave!!
