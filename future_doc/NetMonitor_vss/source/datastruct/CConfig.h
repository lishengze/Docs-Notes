/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CConfig.h
///@brief��������CConfig��CConfigItem
///@history 
///20020214	���ض�		�������ļ�
// 20070828 �Ժ��		CConfig�޸�Ϊ�̳�CParameterMap
/////////////////////////////////////////////////////////////////////////

#ifndef CCONFIG_H
#define CCONFIG_H

#include "platform.h"
#include "CBaseObject.h"

/////////////////////////////////////////////////////////////////////////
///CConfigItem��һ���ڲ�ʹ���ֻ࣬��CConfigʹ�ã����ڴ洢ĳһ������������ݡ�һ��
///��������ָ�������ļ��е�����xxx=xxx��һ��
///@author	���ض�
///@version	1.0,20020214
/////////////////////////////////////////////////////////////////////////
class CConfigItem: public CBaseObject
{
public:
	///���캯�������ڴ���һ��������
	///@param	name	�����������˲���������ΪNULL
	///@param	value	������ֵ���˲�������ΪNULL����ʾ��ֵΪ��
	///˵�����������������������ַ��������з��ڷ��غ󲻱ر����ռ�
	CConfigItem(char *name, char *value);
	
	///��������
	virtual ~CConfigItem(void);
	
	virtual int isA(char *objectType);
	virtual char *getType(void);
	virtual void output(CLogger *pLogger,int indent=0);
	
	///��ȡ����
	///@return	�������������
	char *getName(void);
	
	///��ȡֵ
	///@return	���������ֵ�������������ʱΪNULL���򷵻�""
	char *getValue(void);
	
	///��������
	///@����	name	����
	void setName(char *name);
	
	///����ֵ
	///@����	value	ֵ
	void setValue(char *value);
private:
	///���ڴ洢�������������
	char *name;
	
	///���ڴ洢���������ֵ
	char *value;
};

/////////////////////////////////////////////////////////////////////////
///CConfig��һ��ֻ���������ļ���������������ļ���һ������Windows��INI�ļ��Ľṹ
///ȫ����xxx=xxx����ʽ������ʹ��#��ʾע�ͣ������п���
///@author	���ض�
///@version	1.0,20020214
/////////////////////////////////////////////////////////////////////////
class CConfig: public CBaseObject, public CParameterMap
{
public:
	///���캯�������ڶ�ȡָ���������ļ��������ڲ�������CConfigItem��һ��
	///CCollection
	///@param	configFilename	Ҫ��ȡ�������ļ���
	///@exception	CRuntimeError	����������£���������쳣
	///			<ol>
	///			<li>�޷��򿪴��ļ���������Ϣ:can not open config file
	///			<li>�ڴ治����������Ϣ:insufficient memory space
	///			<li>�����ļ����󣬴�����Ϣ:error in config file
	///			</ol>
	CConfig(const char *configFilename);
	
	///���������������ͷ�items���ڴ�
	virtual ~CConfig(void);
	
	virtual int isA(char *objectType);
	virtual char *getType(void);
	virtual void output(CLogger *pLogger,int indent=0);

	///��ȡָ�������������ļ��ж�Ӧ��ֵ
	///@param	name	����������
	///@param	pStartId	ָ����ʼ�ı�ţ����ΪNULL�����ʾ��ͷ��ʼ��
	///			���򽫴�ָ����+1��ʼ�����ҷ����ҵ��ı��+1�������Ϊ0��
	///			���ʾ��ͷ��ʼ���Ժ󷴸�ʹ�ô˺���������ȡ�����е�ͬ������
	///@return	���������ֵ������ж����ֻ���ص�һ����û�У��򷵻�""
	virtual char *getConfig(char *name, int *pStartId=NULL);
private:

	///���ڴ洢����������ļ��ϣ���Ԫ������ΪCConfigItem
	vector<CConfigItem *> items;
};

///��ǰ��������Ϣ
extern CConfig *currentConfig;

#endif
