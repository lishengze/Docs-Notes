#ifndef _CONFIG_MANAGER_H_
#define _CONFIG_MANAGER_H_

#include <map>
#include <vector>
#include <string>

#include "systools.h"

using namespace std;

//配置管理器
class CConfigManager
{
	public:
		//实例化，单例模式
		static CConfigManager * Instance();  

		//加载配置
		void LoadConfig(vector<string>& localIPList);	
	private:
		//加载xml,读取采样间隔和应用指标列表
		void LoadXmlFile();
		
		//加载service.list,读取probe负责的应用列表
		void LoadServiceList(vector<string>& localiplist);
		
	public:
		//系统指标采样间隔,key:指标名,value:采样间隔
		map<string, int> m_mSysAttrTimers;   

		//应用采集的指标列表,key:应用名,value:(key:指标名,value:无意义)
		map<string, map<string, int> > m_mAppAttrList;

		//本机上所有的服务列表,key:服务名, value:服务id列表
		map<string, vector<int> > m_mServiceList;		
};

#endif

