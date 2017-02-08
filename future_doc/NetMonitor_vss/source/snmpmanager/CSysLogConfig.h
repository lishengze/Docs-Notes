/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	CSyslogConfig.h
///@brief	定义了管理syslog配置信息的类
///@history
///20110705	魏诚 创建该文件
#ifndef REF_CSYSLOGCONFIG_H
#define REF_CSYSLOGCONFIG_H

#include <string>
#include <vector>
#include <map>
#include <list>

//条件结点类
class CConditionNode
{
	/* */
	public:
		int index;			//在记录中出现的索引下标。以空格分隔，从0开始计数，-1表示不指定出现位置
		std::string value;	//要匹配的内容
		std::vector<std::string> patternlist;	//模式匹配
};

//配置信息类
class CSysLogConfigInfo
{
	/* */
	public:
		std::string m_sDeviceType;			//设备类型，router/switch/printer/...
		std::string m_sCompanyType;			//厂商类型，cisco/huawei/blade/...
		std::string m_sReserve;				//保留字段，增强可扩展性
		std::string m_sEventLevel;			//事件级别，1~4
		std::string m_sEventTypeID;			//事件类别，1~8
		std::string m_sEventEnName;			//事件英文名称
		std::string m_sEventChName;			//事件中文名称
		std::string m_sOpFlag;				//操作类别，yes表示生成，no表示取消
		std::vector<int> m_vAppendContent;	//需要拼接到objectid上面的index
		std::string m_sSubType;				//子类型，eg:up,down
		std::vector<CConditionNode> m_sEventConditionList;
};

//配置管理类
class CSysLogConfigManager
{
	/* */
	public:
		static CSysLogConfigManager *Instance(void);	//实例化，单例模式
		CSysLogConfigManager(void) :
		m_sFileName(""),
		m_tLastLoadTime(0),
		m_MemberAccessEquipmentFilterEnable(false)
		{
		}

		int LoadConfig(std::string filename);			//加载配置
		int ReloadConfig(void); //重新加载配置
		void DumpConfig(void);

	/* */
	public:
		std::vector<CSysLogConfigInfo>	m_lConfigInfoList;	//过滤条件容器
		std::map<int, int>	m_mInfoStart;					//厂商日志信息开始位置
		std::map<std::string, int>	m_mapIPS;
		std::list<std::string> m_devices;

		// 会员接入设备的IP地址列表
		std::list<std::string> m_MemberAccessEquipmentList;
		// 是否启用会员接入设备的端口UPDOWN事件的过滤，默认情况下不启用
		bool m_MemberAccessEquipmentFilterEnable;

	/* */
	private:
		std::string m_sFileName;	//配置文件名
		time_t m_tLastLoadTime;		//上次加载时间
};
#endif
