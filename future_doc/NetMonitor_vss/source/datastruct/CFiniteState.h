/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CFiniteState.h
///@brief��������CFiniteState
///@history 
///20041219	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef CFINITESTATE_H
#define CFINITESTATE_H

#include "platform.h"
#include "CBaseObject.h"
#include "CLogger.h"

/////////////////////////////////////////////////////////////////////////
///CFiniteState��һ����������״̬�Զ�������
///@author	���ض�
///@version	1.0,20041219
/////////////////////////////////////////////////////////////////////////
class CFiniteState : public CBaseObject
{
public:
	///���췽��
	///@param	totalState	��״̬����״̬���������ܳ���32
	///@param	allowTable	�����״̬�л�����СΪtotalState��ÿ������������λͼ�ķ�ʽ��ʾ�Ƿ�����
	///@param	stateName	����״̬�����ƣ���СΪtotalState
	///@param	initState	��ʼ״̬
	CFiniteState(int totalState, int allowTable[], char *stateName[], int initState=0);

	virtual ~CFiniteState(void);
	virtual int isA(char *objectType);
	virtual char *getType(void);
	virtual void output(CLogger *pLogger,int indent=0);
	
	///�л�״̬
	///@param newState	�µ�״̬
	///@return	1����ʾ�ɹ���0��ʾʧ��	
	int shiftState(int newState);
	
	///��ȡ��ǰ״̬
	///@return	��ǰ״̬
	int getState(void);
protected:
	///״̬�����л�ʱ�Ķ�����һ���ɼ̳���ʵ��
	///@param	oldState	ԭ����״̬
	///@param	newState	�µ�״̬
	virtual void shiftAction(int oldState, int newState);
private:
	///��״̬����
	int m_totalState;
	
	///�����״̬�л���
	int *m_allowTable;
	
	///״̬���Ʊ�
	char **m_stateName;
	
	///��ǰ״̬
	int m_currentState;
};

#endif
