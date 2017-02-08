/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	CTimePolicy.h
///@brief	定义了网络监控系统共用的时间策略类和函数
///@history
///20110210	晏鹤春		创建该文件
///20110525	晏鹤春		修订注释
#ifndef REF_CTIMEPOLICY_H
#define REF_CTIMEPOLICY_H

#include <map>
#include <list>
#include <string>

#include <time.h>

#define SIZE_BUF	256
#define SIZE_BUF_S	32

using namespace std;

// CDateTime 类实现常用时间日期工具方法
class CDateTime
{
	/* */
	public:
		CDateTime(void);
		CDateTime(const CDateTime &ob);
		CDateTime &operator =(const CDateTime &ob);
		bool operator ==(const CDateTime &ob);

		~ CDateTime(void);

		void OpenDrift(void);			// 打开时间偏移（计算时区时差量）
		void CloseDrift(void);			// 关闭时间偏移（不计算时区时差量）
		void FreshTime(void);			// 刷新时间量，默认为当前时刻
		void FreshTime(time_t timesec); // 刷新时间量，默认为当前时刻
		time_t	GetTimeSec(void);
		time_t	GetTimeSec(const char *pDate, const char *pTime);
		time_t	GetTimeDrift(void);
		time_t	GetCurrTimeSec(void);
		struct tm *GetTimeStruct(void);
		struct tm *GetCurrTimeStruct(void);
		string	GetYearStr(time_t timesec);
		string	GetMonthStr(time_t timesec);
		string	GetDayStr(time_t timesec);
		string	GetDayNoStr(time_t timesec);
		string	GetDateStr(time_t timesec);
		string	GetTimeStr(time_t timesec);
		string	GetYearStr(void);
		string	GetMonthStr(void);
		string	GetDayStr(void);
		string	GetDayNoStr(void);
		string	GetDateStr(void);
		string	GetTimeStr(void);
		string	GetYearByDate(string strDate);
		string	GetMonthByDate(string strDate);
		string	GetDayByDate(string strDate);
		string	GetDayNoByDate(string strDate);
		int GetWeekdayNo(time_t timesec);

	/* */
	protected:
		void TimeDrift(time_t &timesec);	// 根据时间偏移量自动调整时间（若偏移开关已打开）
		void FreshTimestamp(time_t timesec);
		void FreshTimeStruct(time_t timesec);

	/* */
	protected:
		time_t	m_Time;			// 保存已偏移的时间秒数
		time_t	m_Drift;		// 因时区导致的时间偏移量
		bool m_bDriftOpen;		// 是否自动计算时间偏移量
		struct tm m_TimeStruct; // 保存已偏移的时间结构		
};

// CSepData 类用于保存单条Sep数据的结构
class CSepData
{
	/* */
	public:
		CSepData(void);
		CSepData(long lStart, long lEnd, long lGap);
		CSepData(const CSepData &ob);

		~ CSepData(void);

		CSepData &operator	=(const CSepData &ob);
		bool operator ==(const CSepData &ob);
		bool IsInRange(time_t timesec);
		bool IsLess(time_t timesec);
		bool IsLarger(time_t timesec);

	/* */
	public:
		long m_lStart;
		long m_lEnd;
		long m_lGap;
};

// CSepsInfo 类用于解析任务时间串(日任务)
class CSepsInfo
{
	/* */
	public:
		///构造函数
		CSepsInfo(void);

		///拷贝构造函数
		CSepsInfo(const CSepsInfo &ob);

		///析构函数
		~ CSepsInfo(void);

		///初始化类成员
		void Init(void);

		///添加某日时间策略串
			///@param	strTimeSeps	时间策略string串
			///@return	true:添加成功; false:添加失败;
		bool Load(string strTimeSeps);

		///判断时间串是否与本对象一致
			///@param	strTimeSeps	时间策略string串
			///@return	true:一致; false:不一致;
		bool Equal(string strTimeSeps);

		///判断本策略对象于指定时间戳是否应生效执行
			///@param	timesec	时间戳
			///@return	true:需要执行; false:不需要执行;
		bool JudgeRun(time_t timesec);

		///打印时间串对象内存数据,仅后台程序可调用
		void ShowSepsInfo(void);

	/* */
	protected:
		///向时段列表添加新的时段划分信息
			///@param	lStart	时段左值
			///@param	lEnd	时段右值
			///@param	lGap	时段间隔值
		void AddSepData(long lStart, long lEnd, long lGap);

		///向临时数据区添加新的时段策略码
			///@param	pszSep	时段策略码
		void AddTimeSep(char *pszSep);

		///根据时间策略串生成拆解合成后的新时间区段
			///@return	true:生成成功; false:生成失败;
		bool Gernerate(void);

		///判断本策略对象于指定时间戳是否应生效执行
			///@param	timesec	时间戳
			///@return	true:需要执行; false:不需要执行;
		bool NewJudge(time_t timesec);

	/* */
	protected:
		///保存任务时间数据
		string	m_strTaskTime;

		///保存任务最近一次运行时间值
		time_t	m_NextRunTime;

		///存放拆分合并后的各时段信息,已有序
		list<CSepData>	m_listSepData;

		///存放历史数据,保存最后一次分析的时段信息
		CSepData m_SepData;

		///存放临时数据,保存时段左值及时间间隔
		map<long, long> m_mapStart;

		///存放临时数据,保存时段右值及时间间隔
		map<long, long> m_mapEnd;
};

// CTimePolicy 类实现时间策略定义项
class CTimePolicy
{
	/* */
	public:
		///构造函数
		CTimePolicy(void);

		///构造函数
		CTimePolicy(string policy);

		///拷贝构造函数
		CTimePolicy(const CTimePolicy &ob);

		///析构函数
		~ CTimePolicy(void);

		///赋值构造函数
		CTimePolicy &operator =(const CTimePolicy &ob);

		///恒等运算符
		bool operator ==(const CTimePolicy &ob);

		///初始化类成员变量
		void Init(void);

		///添加一条时间策略串
			///@param	policy	时间策略string串
			///@return	true:添加成功; false:添加失败;
		bool AddPolicyStr(string policy);

		///判断是否为有效时间策略字串
			///@param	policy	时间策略string串
			///@return	0:非法字串; 1:标准时间策略串; 2:仅包含时段的简略策略串;
		int IsValidPolicy(string policy);

		///判断策略对象在给定时间戳是否需要执行
			///@param	time	目标时间戳
			///@return	true:需要运行; false:不需要运行;
		bool ShouldRun(time_t time);

		///根据日期获取其对应的时段串值
			///@param	strDate	日期string值,如:"20110521"
			///@return	对应的时间串值
		string	GetPolicyByDate(string strDate);

		///根据日期获取其对应的时段串值
			///@param	strMon	月份string值
			///@param	strDay	日份string值
			///@param	strDayNo	工作日string值
			///@return	对应的时间串值
		string	GetPolicyByMonthDay(
					string	strMon,
					string	strDay,
					string	strDayNo);

		///获取最后一次被校验的时间string值
			///@return	对应的时间string码
		string	GetLastestTimeSeps(void);

		///获取本策略对象的工作月份列表
			///@param	listMonth	用于存放工作月份的list对象引用
			///@return	true:获取成功; false:获取失败;
		bool GetWorkMonth(list<string> &listMonth);

		///获取本策略对象指定月份的工作日列表
			///@param	strMonth	指定单个月份码,如:"05"
			///@param	listDay	用于存放工作日的list对象引用
			///@return	true:获取成功; false:获取失败;
		bool GetWorkDay(string strMonth, list<string> &listDay);

		///打印时间策略对象内存数据,仅后台程序可调用
		void ShowPolicyMap(void);

	/* */
	protected:
		bool JoinPolicy(string policy, int type);
		bool IsTimeSeps(char *pStr);
		bool IsValidTimeSep(char *pStr);
		bool IsSepDigits(char *pStr, char cSepChar);
		bool JudgeRunDate(time_t time); // 判断当日是否有任务需要执行
		bool JudgeRunTime(void);		// 判断当时是否需要执行任务，必须后于JudgeRunDate执行
		void JoinDayTimeMaps(
				map<string, string> &mapTarget,
				map<string, string> &mapSource);
		void JoinPolicyMap(string strMonths, map<string, string> &mapDayTimes);
		void GetDayTimesMap(
				string	strDays,
				string	strTimes,
				map<string, string> &mapDayTimes);

	/* */
	public:
		list<string> m_listPolicys;

	/* */
	protected:
		map<string, map<string, string> > m_mapPolicys;
		CDateTime m_DateTime;

		/// 临时数据区，保留最近一次时间判断的缓存，利于减少同日内不同时间的多次重复计算
			/// 发生日切换时，此缓存区自动更新
		string	m_strDateNotRun;	// 保留最后一次校验过的非运行日期
		string	m_strDateRun;		// 保留最后一次校验过的运行日期
		string	m_strTimeSeps;		// 保留最后一次校验过的运行时段值(对应运行日的时间策略)
		CSepsInfo m_SepsInfo;		// 保留最后一次校验运行日的时间策略信息,与m_strTimeSeps相对应
};
#endif
