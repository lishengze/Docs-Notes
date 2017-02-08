/////////////////////////////////////////////////////////////////////////
///@system ִ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CMemoryDB.h
///@brief��������CMemoryDB
///@history 
///20050824	���ض�		�������ļ�
///20120111 ����		NT-0163 kernel����������ָ���û��������
/////////////////////////////////////////////////////////////////////////

#ifndef CMEMORYDB_H
#define CMEMORYDB_H

#include "CBaseObject.h"
#include "CConfig.h"
#include "BaseDataStruct.h"
#include "databaseFactories.h"
#include "databaseIterators.h"

struct TableStruct
{
	char tableName[100];
	int  reuseID;
};
/////////////////////////////////////////////////////////////////////////
///CMemoryDB��һ���ڴ����ݿ��࣬���������ж���ı���Ϣ
///@author	���ض�
///@version	1.0,20050824
/////////////////////////////////////////////////////////////////////////
class CMemoryDB : public CBaseObject
{
public:
	///���췽���������ڴ����ݿ�
	CMemoryDB(void);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMemoryDB(void);
	
	virtual int isA(char *objectType);
	virtual char *getType(void);
	virtual void output(CLogger *pLogger,int indent=0);

	///���г�ʼ������
	///@param	pConfig	��ʼ��ʱʹ�õ�������Ϣ
	///@return	1��ʾ�ɹ���0��ʾʧ��
	virtual int init(CConfig *pConfig,IMemoryAllocator *pAllocator=NULL,bool reuse=false);
	
	///�����������빤��
	///@param	pConfig	��������ʱʹ�õ�������Ϣ
	///@return	1��ʾ�ɹ���0��ʾʧ��
	virtual int load(CConfig *pConfig);

	///�������ݴ洢����
	///@param	pConfig	��������ʱʹ�õ�������Ϣ
	///@return	1��ʾ�ɹ���0��ʾʧ��
	virtual int save(CConfig *pConfig);
	
	///������е�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	virtual void clear(void);
	
	///����������������
	virtual void linkAll(void);
	
	
	
	///���ʵ���
	CMonitorEntityFactory *m_MonitorEntityFactory;
	
	///�¼�ʵ���
	CEventEntityFactory *m_EventEntityFactory;
	
	///��kernelǿ��ָ�����û�����
	CPasswordType m_ForceUserPassword;
	
private:
	CFixMem *pMem;		///������ű����Ϣ
};

#endif
