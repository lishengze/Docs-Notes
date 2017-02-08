/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	CRegexConfig.h
///@brief	定义了管理正则表达式配置信息的类
///@history
///20110927	魏诚 创建该文件
#ifndef REF_CREGEXCONFIG_H
#define REF_CREGEXCONFIG_H

#include <string>
#include <vector>
#include <map>

using namespace std;

//提取到行数据的一列数据
class AttrNodeInfo
{
	/* */
	public:
		string	key;
		string	value;
};

//正则表达式结点类
class CRegexNode
{
	/* */
	public:
		string	condition;				//过滤条件		
		bool isloop;					//是否循环执行本条件
		bool ismatchsingle;				//是否单行匹配
		bool ignorecase;				//是否忽略大小写
		string	notmatchattrname;		//匹配失败产生的指标名称, 为空表示不产生
		vector<string>	attrnamelist;	//生成的指标名称
};

//正则表达式配置管理类
class CRegexConfigManager
{
	/* */
	public:
		static CRegexConfigManager	*Instance(void);	//实例化，单例模式
		CRegexConfigManager(void) :
		m_sFileName(""),
		m_tLastLoadTime(0)
		{
		}

		int LoadConfig(std::string filename);			//加载配置
		int ReloadConfig(void); //重新加载配置
		void DumpConfig(void);

		//从结果中正则提取指标值
		vector<vector<AttrNodeInfo> > ParseCommandResult(
										string	command,
										string	result,
										bool addquote = true,
										string command2=string());

		//判断给定的内容是否满足正则条件, 0表示成功，其他失败
		int RegexSearch(string regexstr, string inputstr);

	/* */
	public:
		map<string, vector<CRegexNode> > m_mRegexList;

	/* */
	private:
		std::string m_sFileName;	//配置文件名
		time_t	m_tLastLoadTime;	//上次加载时间
};
#endif
