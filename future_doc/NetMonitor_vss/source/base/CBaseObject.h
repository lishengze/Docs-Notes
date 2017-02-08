/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CBaseObject.h
///@brief�������Ķ������CBaseObject���ø���Ӧ�ö���̳�
///@history 
///20020212	���ض�		�������ļ�
///20020214	���ض�		�޸Ĵ��ļ���ʹcheckType�������ļ������к�
// 20070828 �Ժ��		����monitorIndexͷ�ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef CBASEOBJECT_H
#define CBASEOBJECT_H

#include "platform.h"
#include "DesignError.h"
#include "RuntimeError.h"

class CLogger;

/////////////////////////////////////////////////////////////////////////
///CBaseObject������Ӧ�ö���Ļ��ࡣ����ඨ����һ����������Ĳ�����ͬʱ
///��������Ӧ�ļ��ķ�����CBaseObject��һ�������࣬���ܱ�ʵ������
///@author	���ض�
///@version	1.0,20020214
/////////////////////////////////////////////////////////////////////////
class CBaseObject
{
public:
	///���캯��
	///	û��ʵ���ԵĹ���
	CBaseObject(void);

	///��������
	///	û��ʵ���ԵĹ���
	virtual ~CBaseObject(void);

	///�ж�һ������������Ƿ����ָ���Ķ������͡��ú�����һ���麯���������̳�
	///����Ҫ���¶�������������ڼ���������ʱ����ʹobjectType���ϱ������
	///ĳ�������࣬Ҳ��Ϊ����ȷ�ģ���Ϊ��Ϊ�̳��࣬��Ҳ���������һ�֡�
	///@param	objectType	Ҫ����Ƿ���ϵ�������һ�������ַ�����ʽ����
	///			������
	///@return	������Ϸ���1�����򷵻�0
	///	��CBaseObject�ļ̳����У�һ��ʵ�ָú����ķ���������ʾ��
	///	<pre>
	///	if (!strcmp(objectType,"������"))
	///		return 1;
	///	return ����һ::isA(objectType)||�����::isA(objectType);
	///	</pre>
	virtual int isA(char *objectType);

	///������������������Ҫ���ڵ��ԡ��ú�����һ���麯���������̳���
	///��Ҫ���¶���ú�����
	///@param	pLogger	���������
	///@param	indent	������
	virtual void output(CLogger *pLogger,int indent=0)=0;

	///���ر�ʾ���������͵��ַ�����һ����Ǳ�������������ú�����һ���麯����
	///�����̳�����Ҫ���¶���ú�����
	///@return	��ʾ���������͵��ַ���
	virtual char *getType(void);
	
	///��鱾�����Ƿ���ָ���Ķ������ͣ�������򷵻أ����򽫲���һ��CDesignError
	///��������Ҫ������ϵͳ����ʱ����ڴ����
	///@param	objectType	ָ���Ķ�������
	///@param	filename	����ʱָ�����ļ���
	///@param	line		����ʱָ�����к�
	///@exception	CDesignError	��������ʱ�������׳����쳣
	void checkType(char *objectType, char *filename, int line);
private:
};

#include "monitorIndex.h"

///��鱾�����Ƿ����ָ�����ͣ�������򷵻أ����򽫲���һ��CDesignError
///�������ʹ����CBaseObject��һ���̳�����
///@param	type	char*	ָ���Ķ�������
///@exception	CDesignError	��������ʱ�������׳����쳣������λ���ڵ�ǰ�ļ���ǰ��
#define CHECK_TYPE(type) checkType(type,__FILE__,__LINE__)

///�׳�һ��CDesignError�쳣
///@param	msg	char*	ָ���Ĵ�����Ϣ
///@exception	CDesignError	�׳����쳣������λ���ڵ�ǰ�ļ���ǰ��
//#define RAISE_DESIGN_ERROR(msg) {throw new CDesignError(msg,__FILE__,__LINE__);}
#define RAISE_DESIGN_ERROR(msg) {												\
		printf("DesignError:%s in line %d of file %s\n",msg,__LINE__,__FILE__);	\
		fflush(stdout);															\
		char *__pNull = NULL; *__pNull = 0;										\
	}

///�׳�һ��CRuntimeError
///@param	msg	char*	ָ���Ĵ�����Ϣ
///@exception	CRuntimeError	�׳����쳣������λ���ڵ�ǰ�ļ���ǰ��
//#define RAISE_RUNTIME_ERROR(msg) {throw new CRuntimeError(msg,__FILE__,__LINE__);}
#define RAISE_RUNTIME_ERROR(msg) {												\
		printf("RuntimeError:%s in line %d of file %s\n",msg,__LINE__,__FILE__);\
		fflush(stdout);															\
		char *__pNull = NULL; *__pNull = 0;										\
	}

///���м������м���Խ�ߣ����е�����Խ��
extern int runLevel;

#endif
