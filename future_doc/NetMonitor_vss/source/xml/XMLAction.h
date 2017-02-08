/////////////////////////////////////////////////////////////////////////
///@system ִ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file XMLAction.h
///@brief �����˼������õ�XML������
///@history 
///20051231	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef XMLACTION_H
#define XMLACTION_H

#include "CXML.h"
/////////////////////////////////////////////////////////////////////////
///CXMLUpdateAction��һ��XML�����࣬�޸�ָ���Ľڵ�����ַ���
///@author	��ϰƽ
///@version	1.0,20070714
/////////////////////////////////////////////////////////////////////////
class CXMLUpdateAction: public CXMLAction
{
public:
	///���캯��
	CXMLUpdateAction(CXMLNode *pNode);

	int nodeHandler(CXMLNode *pNode);
	int stringHandler(char *string);
private:
	CXMLNode *m_pNode;

};

/////////////////////////////////////////////////////////////////////////
///CXMLDisplayAction��һ��XML�����࣬��ָ���Ľڵ�����ַ���������ļ���
///@author	���ض�
///@version	1.0,20051231
/////////////////////////////////////////////////////////////////////////
class CXMLDisplayAction: public CXMLAction
{
public:
	///���캯��
	///@param	output	ָ��������ļ�
	CXMLDisplayAction(FILE *output=stdout);

	int nodeHandler(CXMLNode *pNode);
	int stringHandler(char *string);
private:
	FILE *m_output;
};

/////////////////////////////////////////////////////////////////////////
///CXMLListAction��һ��XML�����࣬���ҵ��Ľڵ�����ַ����ŵ�һ���б���
///@author	���ض�
///@version	1.0,20051231
/////////////////////////////////////////////////////////////////////////
class CXMLListAction: public CXMLAction
{
public:
	int nodeHandler(CXMLNode *pNode);
	int stringHandler(char *string);
	
	///��ȡ�Ѿ��õ����ַ����б�
	///@return	�Ѿ��õ����ַ����б�
	vector<char *> *getStringList(void);
	
	///��ȡ�Ѿ��õ��Ľڵ��б�
	///@return	�Ѿ��õ��Ľڵ��б�
	CXMLNodeList *getNodeList(void);
	
	///����Ѿ��õ��������б�
	virtual void clearAll(void);
protected:
	vector<char *> stringList;
	CXMLNodeList nodeList;
};

/////////////////////////////////////////////////////////////////////////
///CXMLEqualAction��һ��XML�����࣬�����������ȵ��ַ������߽ڵ�
///@author	���ض�
///@version	1.0,20051231
/////////////////////////////////////////////////////////////////////////
class CXMLEqualCheckerAction: public CXMLListAction
{
public:
	int nodeHandler(CXMLNode *pNode);
	int stringHandler(char *string);

	///�ж������ַ����Ƿ����
	///@param	string1	��һ���ַ���
	///@param	string2	�ڶ����ַ���
	///@return	1��ʾ��ȣ�0��ʾ�����
	virtual int isEqual(char *string1, char *string2);

	///�ж������ڵ��Ƿ����
	///@param	pNode1	��һ���ڵ�
	///@param	pNode2	�ڶ����ڵ�
	///@return	1��ʾ��ȣ�0��ʾ�����
	virtual int isEqual(CXMLNode *pNode1, CXMLNode *pNode2);

	///�ڷ����ظ��ַ���ʱ�Ĵ�����
	///@param	string	�ظ����ַ���
	///@param	originalString	ԭ���Ѿ��е��ַ���
	///@return	ͬstringHandler
	virtual int findDuplication(char *string, char *originalString);

	///�ڷ����ظ��ڵ�ʱ�Ĵ�����
	///@param	pNode	�ظ��Ľڵ�
	///@param	pOriginalNode	ԭ���Ѿ��еĽڵ�
	///@return	ͬnodeHandler
	virtual int findDuplication(CXMLNode *pNode, CXMLNode *pOriginalNode);
};

///��ȡֵ����
///Ⱥ�麯������
///��������
///�ַ����������
///��action�ϲ�Ϊһ��action����
///������������
///������

#endif
