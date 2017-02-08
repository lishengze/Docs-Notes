/////////////////////////////////////////////////////////////////////////
///@system 网络监控系统
///@company 上海期货信息技术有限公司
///@file StringUtil.cpp
///@brief 提供了操作字符串的一些便利方法
///@history
///20110531	李志伟   创建该文件
/////////////////////////////////////////////////////////////////////////
#include "StringUtil.h"

bool SplitStr(const string src, const string delim, vector<string> &attrArray)
{
	if (src.empty() || delim.empty())
	{
		return false;
	}

	size_t	delimLen = delim.length();
	size_t	startPos = 0;
	size_t	endPos = 0;

	do
	{
		endPos = src.find(delim, startPos);
		if (string::npos == endPos)
		{
			attrArray.push_back(src.substr(startPos));
			break;
		}

		attrArray.push_back(src.substr(startPos, endPos - startPos));

		startPos = endPos + delimLen;
	} while (1);

	return true;
}

string GetSubStr(const string &src, const string &begin, const string &end)
{
	string	rtn = "";

	size_t	nb = src.find(begin);
	if (nb == string::npos)
	{
		return rtn;
	}

	nb += begin.size();

	size_t	ne = src.find(end, nb);
	if (ne == string::npos)
	{
		return rtn;
	}

	rtn = src.substr(nb, ne - nb);

	return rtn;
}

typedef bool (*check_t) (char c);

bool isdigit_f(char a)
{
	return (isdigit(a) || isspace(a) || a == '+' || a == '-');
}

bool isfloat_f(char a)
{
	return
		(
			isdigit_f(a)
		||	a == '.'
		||	a == 'd'
		||	a == 'D'
		||	a == 'e'
		||	a == 'E'
		);
}

template<typename F>
bool checkString(const char *number, F checker)
{
	if (!number)
	{
		return false;
	}

	bool rtn = true;
	char c;

	while (c = *number++)
	{
		if (!checker(c))
		{
			rtn = false;
			break;
		}
	}

	return rtn;
}

bool isdigit(const char *number)
{
	return checkString<check_t> (number, isdigit_f);
}

bool isfloat(const char *number)
{
	return checkString<check_t> (number, isfloat_f);
}

int compareStringNoCase(const char *str1, const char *str2)
{
	static int	PositiveDiff = 'a' - 'A';
	static int	NegativeDiff = -PositiveDiff;

#define NO_DIFF(diff) \
		(diff == 0 || diff == PositiveDiff || diff == NegativeDiff)

	int rtn = 0;

	// 对空串的比较，两个空串认为是相等的。
	if (!str1 && !str2)
	{
		return 0;
	}
	else if (!str1)
	{
		return -1;
	}
	else if (!str2)
	{
		return 1;
	}

	int diff;
	while (*str1 && *str2)
	{
		int c1 = tolower(*str1);
		int c2 = tolower(*str2);

		diff = c1 - c2;
		if (diff)
		{
			break;
		}

		str1++, str2++;
	}

	if (diff > 0)
	{
		return 1;
	}
	else if (diff < 0)
	{
		return -1;
	}
	else
	{
		if (*str1)
		{
			return 1;
		}
		else if (*str2)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
}
