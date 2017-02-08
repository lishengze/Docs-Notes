/////////////////////////////////////////////////////////////////////////
///@system ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file StringUtil.h
///@brief �ṩ�˲����ַ�����һЩ��������
///@history
///20110531	��־ΰ   �������ļ�
/////////////////////////////////////////////////////////////////////////
#ifndef _STRING_UTIL_H
#define _STRING_UTIL_H

#include <platform.h>

/**��src����delimָʾ���ָ��ɶΣ��ֶε�����Ϊdelim+1�������src��û��ָ���ָ�������src���뷵�ص������С�
* @param src ��Ҫ���ָ����ַ���
* @param delim  �ָ����ַ���
* @param attrArray ���ص�С������
* @return �ɹ����÷���true�����srcΪ�ջ���delimΪ�գ�����false
*/
bool SplitStr(const string src, const string delim, vector<string> &attrArray);

/**��src�и���ָ���ַ�������ȡ�ִ�
* @param src ��Ҫ���ָ����ַ�����
* @param begin  ��ʼ��ָ���ַ���
* @param end ��ֹ��ָ���ַ���
* @return ���ص��ִ�
*/
string	GetSubStr(const string &src, const string &begin, const string &end);

/**�ж��ַ����ǲ��ǺϷ��������ַ���
* @param number �ַ�����
* @return ����ַ����������г�atoi�Ŀ�ת����ʽ��������ݣ��ո�+��-�����֣�������false����֮����true
*/
bool isdigit(const char *number);

/**�ж��ַ����ǲ��ǺϷ��ĸ������ַ���
* @param number �ַ�����
* @return ����ַ����������г�atof�Ŀ�ת����ʽ���������
*���ո�+��-�����֡�С���㡢D��d��E��e��������false����֮����true
*/
bool isfloat(const char *number);

/**�Ƚ������ַ��������ַ��Ĵ�Сд�޹�
* @param str1 Ҫ�Ƚϵ��ַ���1
* @param str2 Ҫ�Ƚϵ��ַ���2
* @return ����ַ�����������ȣ�����0�����str1�������ַ�����str2������1����֮����-1
*/
int compareStringNoCase(const char *str1, const char *str2);
#endif // _STRING_UTIL_H
