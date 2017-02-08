/////////////////////////////////////////////////////////////////////////
///@system 网络监控系统
///@company 上海期货信息技术有限公司
///@file StringUtil.h
///@brief 提供了操作字符串的一些便利方法
///@history
///20110531	李志伟   创建该文件
/////////////////////////////////////////////////////////////////////////
#ifndef _STRING_UTIL_H
#define _STRING_UTIL_H

#include <platform.h>

/**将src按照delim指示符分隔成段，分段的数量为delim+1，如果在src中没有指定分隔符，将src放入返回的数组中。
* @param src 需要被分隔的字符串
* @param delim  分隔符字符串
* @param attrArray 返回的小串数组
* @return 成功设置返回true。如果src为空或者delim为空；返回false
*/
bool SplitStr(const string src, const string delim, vector<string> &attrArray);

/**从src中根据指定字符串，获取字串
* @param src 需要被分隔的字符串，
* @param begin  起始的指定字符串
* @param end 终止的指定字符串
* @return 返回的字串
*/
string	GetSubStr(const string &src, const string &begin, const string &end);

/**判断字符串是不是合法的数字字符串
* @param number 字符串，
* @return 如果字符串的内容有除atoi的可转换形式以外的内容（空格、+、-、数字），返回false，反之返回true
*/
bool isdigit(const char *number);

/**判断字符串是不是合法的浮点数字符串
* @param number 字符串，
* @return 如果字符串的内容有除atof的可转换形式以外的内容
*（空格、+、-、数字、小数点、D、d、E、e），返回false，反之返回true
*/
bool isfloat(const char *number);

/**比较两个字符串，与字符的大小写无关
* @param str1 要比较的字符串1
* @param str2 要比较的字符串2
* @return 如果字符串的内容相等，返回0；如果str1的内容字符大于str2，返回1；反之返回-1
*/
int compareStringNoCase(const char *str1, const char *str2);
#endif // _STRING_UTIL_H
