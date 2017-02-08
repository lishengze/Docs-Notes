/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CErrorEngine.h
///@brief��������CErrorEngine
///@history 
///20050214	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef CERRORENGINE_H
#define CERRORENGINE_H

#include "platform.h"
#include "CBaseObject.h"
#include "DesignError.h"

#define MAX_ERROR_MSG 400

typedef struct
{
	int errorID;
	char *errorMsg;
}	TErrorType;

/////////////////////////////////////////////////////////////////////////
///CErrorEngine��һ������������࣬�ṩ�˴������ͱ���Ļ���
///@author	���ض�
///@version	1.0,20041001
/////////////////////////////////////////////////////////////////////////
class CErrorEngine: public map<int, char *>
{
public:
	///���췽����������������
	CErrorEngine(void);
		
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CErrorEngine(void);
	
	///����һ����������
	///@param	errorID	������
	///@param	errorMsg	������Ϣ
	///@exception	����ô��������Ѿ����ڣ��򱨳�CDesignError
	void registerErrorType(int errorID, char *errorMsg);

	///����һ���������
	///@param	pErrorType	�����������飬���һ����errorIDӦ��Ϊ0
	///@exception	����ô��������Ѿ����ڣ��򱨳�CDesignError
	void registerErrorType(TErrorType pErrorType[]);

	///����һ������
	///@param	errorID	Ҫ����Ĵ�����
	void reportError(const int errorID);
	
	///��ȡһ������Ŷ�Ӧ�Ĵ�����Ϣ
	///@param	errorID	������
	///@return	��Ӧ�Ĵ�����Ϣ
	char *getErrorMsg(const int errorID);

	///��ȡ����Ĵ���ͬʱ�������
	///@param	pLastErrorID	��������Ĵ����ţ�0��ʾû�д���
	///@param	pLastErrorMsg	��������Ĵ�����Ϣ
	virtual void getLastError(int *pLastErrorID=NULL,char **pLastErrorMsg=NULL);

	///��ȡ����Ĵ��󣬵����������
	///@param	pLastErrorID	��������Ĵ����ţ�0��ʾû�д���
	///@param	pLastErrorMsg	��������Ĵ�����Ϣ
	virtual void getLastErrorWithoutClear(int *pLastErrorID=NULL,char **pLastErrorMsg=NULL);
private:
	///����Ĵ�����
	int m_LastErrorID;
	
	///����Ĵ�����Ϣ
	char *m_LastErrorMsg;
};

#endif
