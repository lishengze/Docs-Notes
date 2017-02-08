/////////////////////////////////////////////////////////////////////////
///@system ����ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CExprException.h
///@brief	��������CExprException
///@history 
///20080322	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef C_EXPR_EXCEPTION_H
#define C_EXPR_EXCEPTION_H

#include "platform.h"

/////////////////////////////////////////////////////////////////////////
///CParseException������һ���﷨������쳣
///@author	���ض�
///@version	1.0,20090322
/////////////////////////////////////////////////////////////////////////
class  CExprException
{
public:
	///���캯�������ڴ������쳣����
	///@param	msg	���쳣�Ĵ�����Ϣ
	///@param	lineNo	����������к�
	///@param	columnNo	����������к�
	CExprException(char *msg, int lineNo, int columnNo);
	
	///���캯�������ڴ������쳣����
	///@param	lineNo	����������к�
	///@param	columnNo	����������к�
	///@param	format	���쳣�Ĵ����ʽ������printf��ʽҪ��
	///@param	...	����printfҪ���ֵ
	CExprException(int lineNo, int columnNo, char *format, ...);

	///��������
	~CExprException(void);
	
	///��ȡ������Ϣ
	///@return	������Ϣ
	char *getMsg(void);
	
	///��ȡ����������к�
	///@return �к�
	int getLineNo(void);

	///��ȡ����������к�
	///@return �к�
	int getColumnNo(void);
	
	///���˴�����Ϣ�������
	///@param	output	Ҫ������ļ�
	void display(FILE *output=stdout);

private:
	///����Ĵ�����Ϣ
	char *m_msg;
	
	///������к�
	int m_lineNo;

	///������к�
	int m_columnNo;
};

#endif
