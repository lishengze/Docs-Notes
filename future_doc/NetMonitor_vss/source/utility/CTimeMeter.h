/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CTimeMeter.h
///@brief��������CTimeMeter
///@history 
///20050209	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef CTIMEMETER_H
#define CTIMEMETER_H

#include "platform.h"
#include "CBaseObject.h"

enum
{
	TIME_METER_ALL=0,
	TIME_VALID_ORDER,
	TIME_SAVE_ORDER,
	TIME_MAKE_TRADE,
	TIME_ADD,
	TIME_UPDATE,
	TIME_DELETE,
	TIME_RETRIEVE,
	TIME_GET,
	TIME_QUERY,
	TIME_UPDATE_TRANSACTION_DATA,
	TIME_RETRIEVE_TRANSACTION_DATA,
	TIME_GET_TRANSACTION_DATA,
	TIME_UPDATE_COPY,
	TIME_UPDATE_INDEX,
	TIME_UPDATE_TRIGGER,
	TIME_UPDATE_RESOURCE,
	TIME_UPDATE_NO_TRANSACTION,
	MAX_TIME_METER
};

/////////////////////////////////////////////////////////////////////////
///CTimeMeter��һ������࣬�����ں��뷶Χ�ϼ����ù���ʱ�䡣Ŀǰ��ʵ�ֲ���
///֧�ֿ���
///@author	���ض�
///@version	1.0,20050209
/////////////////////////////////////////////////////////////////////////
class CTimeMeter: public CBaseObject
{
public:
	///���캯��
	///@����	name	��������
	///@����	allowStart	�Ƿ�����ʼ
	CTimeMeter(char *name,int allowStart=1);
	
	///��������
	virtual ~CTimeMeter(void);
	
	virtual int isA(char *objectType);
	virtual char *getType(void);
	virtual void output(CLogger *pLogger,int indent=0);

	///��ʼ����
	///@exception	CDesignError ����Ѿ���ʼ���У����ɳ��쳣
	void start(void);
	
	///��������
	///@exception	CDesignError ���û�п�ʼ���У����ɳ��쳣
	void stop(void);
	
	///@����	allowStart	�Ƿ�����ʼ
	void allow(int allowStart);
	
	///���ر�����¼��ʱ��ֵ���Ժ���Ϊ��λ
	///@return	������¼��ʱ��ֵ
	int getTime(void);
	
	
	///���ر�������õĴ���
	///@return	������¼�Ľ��ô���
	int getCallCount(void);
	
	///�������Ľ�������output��
	///@param	output	����������ļ�
	void display(FILE *output);

	///��ȡ����������
	///@return	���ر���������
	char *getName(void);
private:
	///����������
	char *m_name;
	
	///������¼����ʱ��ֵ
	int m_time;
	
	///������Ƿ���������
	int m_isStarted;
	
	///�ϴο�ʼ���е�ʱ��
	long m_lastStartTime;
	
	///�Ƿ�����ʼ
	int m_allowStart;
	
	///�����õĴ���
	int m_callCount;
};

extern CTimeMeter *timeMeters[MAX_TIME_METER];
/*
#define METER_START(i)	{ timeMeters[i]->start();}
#define METER_END(i)	{ timeMeters[i]->stop(); }
*/
#define METER_START(i)
#define METER_END(i)

#endif
