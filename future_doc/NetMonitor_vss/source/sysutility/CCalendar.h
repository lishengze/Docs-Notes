/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CCalendar.h
///@brief	定义了运维管理系统公用的日历工具类
///@history
///20120628	晏鹤春	创建该文件
#include "stdlib.h"
#include "string.h"
/*
    CCalendar 类对象使用样例:

	// 创建日历数据对象并初始化
	CCalendar calendar;

  // 添加日期规则
	calendar.addDateDefine(1, "00;00;00;");
	calendar.addDateDefine(2, "06,08,10;00;05;");
	calendar.addDateDefine(3, "07,08,09;02,05;08;");
	calendar.addDateDefine(4, "07,08,09;02,05;14;");

	// 获取指定日期的日期类ID列表
	list<int> & List = calendar.getDateTypeList(2012, 8, 15);

	// 获取指定日期的复合信息结构
	CHybirdDate & HDate = calendar.getHybirdDate(2012,7,4);
	
	// 测试关联交易日函数
	stDate rDate = calendar.getTDayRelative(HDate.m_SolarDate, -5);
	
	// 测试日历结构的打印
	for (short Y = 2012; Y <= 2012; Y ++)
	{
		for (short M = 1; M <= 12; M ++)
		{
			calendar.showCalendar(Y, M);
			rDate = calendar.getFirstTDay(Y, M);
			printf("FirstTradingDay  [%d]\n", rDate.toInt());
			rDate = calendar.getMiddleTDay(Y, M);
			printf("MiddleTradingDay [%d]\n", rDate.toInt());
			rDate = calendar.getLastTDay(Y, M);
			printf("LastTradingDay   [%d]\n", rDate.toInt());
		}
	}


关于日期类型定义串的说明：
1. 日期类型定义串分三部分组成[月份码;数码;日期种类码;]，每部分间用';'进行分隔;
2. 月份码取值范围[0~12]，0表示每月，1表示1月……12表示12月，选定多个月份时数值以','分隔，如[1,3,5];
3. 数码用于表示第N个，取值范围[0~31,99]，0表示每个，1表示首个……31表示第31个，99表示最后一个，选定多个时同样以','分隔；
4. 日期种类码用于标识日期的类型，可分为：自然日、交易日、非交易日等，取值范围[0~24]，具体规则如下：
	DT_NORMAL = 0, 	      ///00:自然日
	DT_MONDAY,            ///01:周一
	DT_TUESDAY,           ///02:周二
	DT_WEDNESDAY,         ///03:周三
	DT_THURSDAY,          ///04:周四
	DT_FRIDAY,            ///05:周五
	DT_SATURDAY,          ///06:周六
	DT_SUNDAY,            ///07:周日
	DT_CLOSE,             ///08:非交易日
	DT_TRADE,             ///09:交易日
	DT_ADJUSTDAY,         ///10:自然人持仓清0日
	DT_DELIVERY1,         ///11:第一交割日
	DT_DELIVERY2,         ///12:第二交割日
	DT_DELIVERY3,         ///13:第三交割日
	DT_DELIVERY4,         ///14:第四交割日
	DT_DELIVERY5,         ///15:第五交割日
	DT_DELIVERY,          ///16:交割日
	DT_NOCONTINUOUS,      ///17:当晚无连续交易
	DT_NONIGHTTRADE,      ///18:本交易日不含夜盘
	DT_HOLIDAY,           ///19:国定休市日
	DT_HOLIDAYH,          ///20:国定首休市日
	DT_HOLIDAYT,          ///21:国定末休市日
	DT_BEFOREHOLIDAY,     ///22:国定前交易日
	DT_AFTERHOLIDAY       ///23:国定后交易日

用例:
	00;00;00									表示每月每个自然日(即每天)
	06,08,10;00;05;						        表示月份6、8、10的每一个周五
    07,08,09;02,05;08;				            表示月份7、8、9的第2和第5个非交易日
*/

#ifndef REF_CCALENDAR_H
#define REF_CCALENDAR_H
#include "map"
#include "list"
#include "vector"
#include "string"

using namespace std;

#define LEAP_YEAR(y)		!(y % (y%100 ? 4 : 400))		// 闰年计算式，为闰年时返回1，否则为0
#define VAL(h)				(h<'a'?(h-'0'):(h-'a'+10))		// 十六进行字符转整数

#define CALENDAR_YEAR_START		1800
#define CALENDAR_YEAR_END			2100
#define CALENDAR_YEAR_TERMS		1900

class CCalendar;

#define GET_DT_MASK(y)		 (int)pow( 2.0, (y-1) )			// 获取日期类型相应的掩码

enum DATE_TYPE {
	DT_NORMAL = 0, 	      ///00:自然日
	DT_MONDAY,            ///01:周一
	DT_TUESDAY,           ///02:周二
	DT_WEDNESDAY,         ///03:周三
	DT_THURSDAY,          ///04:周四
	DT_FRIDAY,            ///05:周五
	DT_SATURDAY,          ///06:周六
	DT_SUNDAY,            ///07:周日
	DT_CLOSE,             ///08:非交易日
	DT_TRADE,             ///09:交易日
	DT_ADJUSTDAY,         ///10:自然人持仓清0日
	DT_DELIVERY1,         ///11:第一交割日
	DT_DELIVERY2,         ///12:第二交割日
	DT_DELIVERY3,         ///13:第三交割日
	DT_DELIVERY4,         ///14:第四交割日
	DT_DELIVERY5,         ///15:第五交割日
	DT_DELIVERY,          ///16:交割日
	DT_NOCONTINUOUS,      ///17:当晚无连续交易
	DT_NONIGHTTRADE,      ///18:本交易日不含夜盘
	DT_HOLIDAY,           ///19:国定休市日
	DT_HOLIDAYH,          ///20:国定首休市日
	DT_HOLIDAYT,          ///21:国定末休市日
	DT_BEFOREHOLIDAY,     ///22:国定前交易日
	DT_AFTERHOLIDAY       ///23:国定后交易日
};

enum DATE_TYPE_MASK {
	DTM_NORMAL = 0,              ///自然日 MASK 0x00
	DTM_MONDAY = 1,              ///周一
	DTM_TUESDAY = 2,             ///周二
	DTM_WEDNESDAY = 4,           ///周三
	DTM_THURSDAY = 8,            ///周四
	DTM_FRIDAY = 16,             ///周五
	DTM_SATURDAY = 32,           ///周六
	DTM_SUNDAY = 64,             ///周日
	DTM_CLOSE = 128,             ///非交易日
	DTM_TRADE = 256,             ///交易日
	DTM_ADJUSTDAY = 512,         ///自然人持仓清0日
	DTM_DELIVERY1 = 1024,        ///第一交割日
	DTM_DELIVERY2 = 2048,        ///第二交割日
	DTM_DELIVERY3 = 4096,        ///第三交割日
	DTM_DELIVERY4 = 8192,        ///第四交割日
	DTM_DELIVERY5 = 16384,       ///第五交割日
	DTM_DELIVERY = 32768,        ///交割日
	DTM_NOCONTINUOUS = 65536,    ///当晚无连续交易
	DTM_NONIGHTTRADE = 131072,   ///本交易日不含夜盘
	DTM_HOLIDAY = 262144,        ///国定休市日
	DTM_HOLIDAYH = 524288,       ///国定首休市日
	DTM_HOLIDAYT = 1048576,      ///国定末休市日
	DTM_BEFOREHOLIDAY = 2097152, ///国定首休市日前交易日
	DTM_AFTERHOLIDAY =  4194304  ///国定首休市日后交易日  
};

/// stDate 为日期信息的三元结构
class stDate
{
public:
	short Year;		/// 年
	short Month;	/// 月
	short Day;		/// 日

	stDate()
	{
		Year = CALENDAR_YEAR_TERMS;
		Month = 1;
		Day = 1;
	}

	stDate(short Y, short M, short D)
	{
		Year = Y;
		Month = M;
		Day = D;
	}

	stDate(int YMD)
	{
		Year = YMD/10000;
		Month = (YMD % 10000) / 100;
		Day = YMD % 100;
	}

	stDate(const char *pDate)
	{
		if (pDate != NULL && strlen(pDate) == 8) //需要符合 "YYYYMMDD"
		{
			char szTmp[9];
			strncpy(szTmp, pDate, 8);
			Day = (short)atoi(szTmp + 6);
			*(szTmp +6) = '\0';
			Month = (short)atoi(szTmp + 4);
			*(szTmp +4) = '\0';
			Year = (short)atoi(szTmp); 
		}
		else
		{
			stDate();
		}
	}

	int toInt(void)
	{
		return (Year * 10000 + Month * 100 + Day);
	}

	stDate &operator[](const stDate &Date)
	{
		Year = Date.Year;
		Month = Date.Month;
		Day = Date.Day;
		return *this;
	}

	bool operator <(const stDate &ob) const
	{
		return  ((long)(Year * 10000 + Month * 100 + Day) < (long)(ob.Year *10000 + ob.Month * 100 + ob.Day));
	}

	bool operator ==(const stDate &ob) const
	{
		return Year == ob.Year  && Month == ob.Month && Day == ob.Day;
	}

	bool operator !=(const stDate &ob) const
	{
		return Year != ob.Year || Month != ob.Month || Day != ob.Day;
	}

	bool operator <(const int &ob) const
	{
		return  *this < stDate(ob);
	}

	bool operator ==(const int &ob) const
	{
		return  *this == stDate(ob);
	}

};

/// stLunarYear 为农历年闰月及月份偏移信息结构体
struct stLunarYear
{
	char LeapMonth;			/// 闰月月份码，0为无闰月
	char Offset[13];		/// Offset[i]中保存农历i月初一对应公历i月的日期号，
	/// 同时，若Offset[i]的最高位为1则表面大月，0表示小月
};

///CBasicInstrumentType 类定义了基本合约类型及特征 
class CBasicInstrumentType
{
public:
	CBasicInstrumentType() {}
	CBasicInstrumentType(const char * Type, short LDT, short ADT, short DDT)
	{
		m_TypeName = Type;
		m_LDayType = LDT;
		m_ADayType = ADT;
		m_DDayType = DDT;
	}

	~CBasicInstrumentType() {}
public:
	string m_TypeName;
	short  m_LDayType;
	short  m_ADayType;
	short  m_DDayType;
};

class CDateTypeDefine
{
public:
	CDateTypeDefine()
	{

	}

	~CDateTypeDefine()
	{

	}

	//返回本定义对象对应于目标年度月份下的具体日期列表，其中日期以整形YYYYMMDD表示
	///@param	iDateType	目标日期类型码
	///@return	返回判断结果，true为符合目标要求;false为不符合目标要求
	bool LoadDTD(char *pDefine)
	{
		char szTmp[512];
		if (pDefine != NULL && strlen(pDefine) >0)
		{
			strcpy(szTmp, pDefine);
			char *pMonths = strtok(szTmp, ";");
			char *pNumbers = strtok(NULL, ";");
			char *pDateType = strtok(NULL, ";");
			if (pMonths == NULL || pNumbers == NULL || pDateType == NULL)
				return false;
			
			getTokens(m_Months, pMonths);
			getTokens(m_Numbers, pNumbers);
			m_DateType = atoi(pDateType);
			
			if (m_Months.size() > 0 && m_Numbers.size() >0)
				return true;
		}
		return false;
	}

private:
	void getTokens(list<int> & List, char *pString)
	{
		char szTmp[512];
		char *p = strtok(pString, ",");
		while(p != NULL)
		{
			List.push_back(atoi(p));
			p = strtok(NULL, ",");
		}
	}

public:
	list <int> m_Months;
	list <int> m_Numbers;
	int m_DateType;
};

///CHybirdDate类定义了日历所使用的混合日期信息项
class CHybirdDate
{
public:
	CHybirdDate() 
	{

	}

	CHybirdDate(stDate Solar, stDate Lunar, short Weekday, short Term, short SFestival, short LFestival, short SPFestival, int DateType)
	{
		m_SolarDate = Solar;
		m_LunarDate = Lunar;
		m_Weekday = Weekday;
		m_Term = Term;
		m_SolarFestival = SFestival;
		m_LunarFestival = LFestival;
		m_SpecialFestival = SPFestival;
		m_DateType = DateType;
	}

	~CHybirdDate() 
	{}


	//设置对象的日期类型
	///@param	iDateType	目标日期类型码
	void setDateType(DATE_TYPE_MASK iDateType)
	{
		m_DateType |= iDateType;
	}


	//校验对象的日期类型
	///@param	iDateType	目标日期类型码
	///@return	返回判断结果，true为符合目标要求;false为不符合目标要求
	bool isDateType(int iDateType)
	{
		return (m_DateType & iDateType) == iDateType;
	}

public:
	/// 公历日期项
	stDate m_SolarDate;
	/// 农历日期项
	stDate m_LunarDate;
	/// 当日Weekday码[0-6]
	short m_Weekday;
	/// 当时节气码
	short m_Term;
	/// 当日农历节日码
	short m_LunarFestival;
	/// 当日公历节日码
	short m_SolarFestival;
	/// 当日特殊节日码
	short m_SpecialFestival;
	/// 当日日期类型标识
	int m_DateType;
};

///CCalendar类定义了公历、农历构造及转换的方法
class CCalendar
{
public:
	CCalendar() 
	{
		// Del by Henchi, 20140226
		// 取消对象构造时的自动初始化
		// 调用者执行AddHoliday后再调用Init
		//Init();		/// 对象构造时自动完成初始化
		m_InitFlag = false;
	}

	~CCalendar() {}

	/// 初始化数据
	void Init();

	//[农历算法] 农历日期→公历日期
	///@param	Date	目标农历日期码
	///@return	返回对应公历日期码
	stDate getSolar(stDate Date);

	//[公历算法] 公历日期→农历日期
	///@param	Date	目标公历日期码
	///@return	返回对应农历日期码
	stDate getLunar(stDate Date);

	//[公历算法] 判断日期是否为交易日
	///@param	Date	需要的判断的日期
	///@return	返回判断结果，true为交易日;false为非交易日
	bool isTradingDay(stDate Date);

	//YYYYMMDD
	bool isTradingDay(string datestr);

	//YYYYMMDD
	bool isTradingDay(const char *pDate);

	//YYYY,MM,DD
	bool isTradingDay(short year, short month, short day);

	//[公历算法] 判断日期是否为国定休市日
	///@param	Date	需要的判断的日期
	///@return	返回判断结果，true为国定休市日;false为国定休市日
	bool isHoliday(stDate Date);

	//YYYYMMDD
	bool isHoliday(string datestr);

	//YYYYMMDD
	bool isHoliday(const char *pDate);

	//YYYY,MM,DD
	bool isHoliday(short year, short month, short day);

	//[公历算法] 判断日期是否为连续交易日
	///@param	Date	需要的判断的日期
	///@return	返回判断结果，true为连续交易日;false为其它日
	bool isContinuousDay(stDate Date);

	//[公历算法] 判断日期的前一天是否为连续交易日
	///@param	Date	需要的判断的日期
	///@return	返回判断结果，true为真;false为假
	bool AfterContinuousDay(stDate Date);

	//[公历算法] 判断日期是否为非连续交易日（当日晚间无夜盘）
	///@param	Date	需要的判断的日期
	///@return	返回判断结果，true为非连续交易日;false为其它日
	bool isNoContinuousDay(stDate Date);

	//[公历算法] 判断日期是否为不含夜盘交易日（该交易日无夜盘部分）
	///@param	Date	需要的判断的日期
	///@return	返回判断结果，true为非连续交易日;false为其它日
	bool isNoNightTradingDay(stDate Date);

	//[公历算法] 判断日期是否为品种交割日
	///@param	Date	需要的判断的日期
	///@return	返回判断结果，0为非交割日，1为第1交割日……5为第5交割日
	short isDeliveryDay(stDate Date);

	//[公历算法] 判断日期是否为自然人持仓清0日
	///@param	Date	需要的判断的日期
	///@return	返回判断结果，true为自然人持仓清0日;false为非自然人持仓清0日
	bool isAdjustDay(stDate Date);

	//[公历算法] 判断日期是否为双休日
	///@param	Date	需要的判断的日期
	///@return	返回判断结果，true为双休日;false为非双休日
	bool isWeekEnd(stDate Date);

	//[公历算法] 判断日期合法性
	///@param	Date	需要的判断的日期
	///@return	返回判断结果，1为合法，0为月分异常，-1为年份异常，-2为日期异常
	short isSolar(stDate Date);

	//[农历算法] 判断日期合法性
	///@param	Date	需要的判断的日期
	///@return	返回判断结果，1为合法，0为月分异常，-1为年份异常，-2为日期异常
	short isLunar(stDate Date);

	//[公历算法] 判断日期类型是否为目标类型
	///@param	Date	需要的判断的日期
	///@return	返回判断结果，true为匹配;false为不匹配
	bool checkDateType(stDate Date, DATE_TYPE_MASK iDateType);

	//[公历算法] 获取公历日期的Weekday
	///@param	Date	需要的判断的日期
	///@return	返回相应Weekday值，[0－6]0为星期日，1为星期1
	short getWeekday(stDate Date);

	//[公历算法] 获取公历日期的Weekday
	///@param	Date	需要的判断的日期
	///@param	Flag	返回值类型标识[0]中文(默认);[1]英文(全大写);[2]英文（首字母大写）
	///@return	返回相应Weekday值
	const char * getWeekdaySign(stDate Date, short Flag = 0);

	//[公历算法] 获取公历日期的日码值
	///@param	Date	需要的判断的日期
	///@param	Flag	返回值类型标识[0]中文(默认);[1]数字
	///@return	返回相应日码值
	const char * getDaySign(stDate Date, short Flag = 0);

	//[公历算法] 获取公历日期的月码值
	///@param	Date	需要的判断的日期
	///@param	Flag	返回值类型标识[0]中文(默认);[1]英文(全大写);[2]英文（首字母大写）
	///@return	返回相应月码值
	const char * getMonthSign(stDate Date, short Flag = 0);

	//[农历算法] 获取干支纪年的天干信息
	///@param	Date	需要的判断的日期
	///@return	返回对应的天干值
	const char * getTianGan(stDate Date);

	//[农历算法] 获取干支纪年的地支信息
	///@param	Date	需要的判断的日期
	///@return	返回对应的地支值
	const char * getDiZhi(stDate Date);

	//[农历算法] 获取农历生肖信息
	///@param	Date	需要的判断的日期
	///@return	返回对应的生肖值
	const char * getZodiacSymbols(stDate Date);

	//根据年月信息得到对应的日历数据
	///@param	Year	公历日期信息
	///@param	Month	公历日期信息
	///@return	返回该月份日历结构对象
	vector<CHybirdDate> & getCalendar(short Year, short Month);

	//根据年月信息得到对应的日历数据
	///@param	YM	公历年月信息,如201208
	///@return	返回该月份日历结构对象
	vector<CHybirdDate> & getCalendar(int YM);

	//根据年月信息得到对应的日历数据
	///@param	SolarDate	公历日期信息
	///@return	返回该月份日历结构中该日信息的引用对象
	vector<CHybirdDate>::iterator getCalendarDay(stDate SolarDate);

	//根据年月日信息得到对应的混合日期对象
	///@param	Year	公历日期年信息
	///@param	Month	公历日期月信息
	///@param	Day	公历日期日信息
	///@return	返回该月份日历结构对象
	CHybirdDate & getHybirdDate(short Year, short Month, short Day);

	//输出根据年月信息得到对应的日历数据
	///@param	Year	公历日期信息
	///@param	Month	相对偏移的天数
	void showCalendar(short Year, short Month);

	//输出混合日历对象对应的日历数据
	///@param	Year	公历日期信息
	void showHybirdDate(CHybirdDate Date);

	//[公历算法] 根据相对偏移量获取关联交易日信息
	///@param	Date	公历日期信息
	///@param	Offset	相对偏移的交易日天数
	///@return	返回该交易日的日期结构对象
	stDate getTDayRelative(stDate Date, long Offset);

	//[公历算法] 根据年月信息获取首个交易日
	///@param	Y	年份码
	///@param	M	月份码
	///@return	返回该交易日的日期结构对象
	stDate getFirstTDay(short Y, short M);

	//[公历算法] 根据年月信息获取末个交易日
	///@param	Y	年份码
	///@param	M	月份码
	///@return	返回该交易日的日期结构对象
	stDate getLastTDay(short Y, short M);

	//[公历算法] 根据年月信息获取月中交易日
	///@param	Y	年份码
	///@param	M	月份码
	///@return	返回该交易日的日期结构对象
	stDate getMiddleTDay(short Y, short M);

	//向工作日历中添加一个新的日期类定义项
	///@param	iID	日期类型ID
	///@param	pDefine	日期类定义描述串
	void addDateDefine(int iID, char *pDefine);

	//向工作日历中添加一个国定休市日
	///@param	pDate	日期字符串YYYYMMDD
	void AddHoliday(const char *pDate);

	//根据年月日信息得到对应的日期类型ID列表
	///@param	Year	公历日期年信息
	///@param	Month	公历日期月信息
	///@param	Day	公历日期日信息
	///@return 返回对应的日期类型ID列表引用
	list <int> & getDateTypeList(short Year, short Month, short Day);

private:
	//[公历算法] 当年第x日相当于m月f日
	///@param	m	目标月份码
	///@param	x	当年第x天
	///@return	返回日码值的ASCII字符码
	char Conv(short m,short x);

	//初始化stLunarYear结构数组
	void InitLunarYear(void);

	//初始化二十四节气日期表
	void InitSolarTerms(void);
	
	//初始化节日信息表
	void InitFestivals(void);

	//初始化农历节日信息表
	void InitLunarFestivals(void);

	//初始化公历节日信息表
	void InitSolarFestivals(void);

	//初始化特殊节日信息表
	void InitSpecialFestivals(void);

	//初始化休市日信息列表
	void InitHoliday(void);

	//初始化日历结构
	void InitCalendar(void);

	//初始化工作日历结构
	void InitWorkCalendar(void);

	//初始化工作日历结构中的链表部分
	void InitWorkCalendarList(int YM);

	//初始化合约信息
	void InitInstrument(void);

	//初始化合约类型信息
	void InitInstrumentType(void);

	//初始化合约相关日期信息
	void InitInstrumentDate(void);

	//根据日期定义信息在日历中找到相应日期偏移
	///@param	Vec	输入该月日历的Vec引用
	///@param	iNum	输入序号
	///@param	iDateType	输入日期类型
	///@return	返回该日期的偏移量,-1表示没有找到
	int findDay(vector<CHybirdDate> & Vec, int iNum, int iDateType);

	//[公历算法] 公元以来的天数
	///@param	Date	输入公历日期码
	///@return	返回该日期的公元偏移量
	long DayOffset(stDate Date);

	//[公历算法] 由公元以来的天数值计算对应日期信息
	///@param	Date	公历日期信息
	///@return	返回该日期的日期结构对象
	stDate getDayByOffset(long Offset);

	//[公历算法] 由特殊属性计算对应日期信息[Y年M月第N个周X]
	///@param	Y	年份码
	///@param	M	月份码
	///@param	N	第N个
	///@param	X	周X
	///@return	返回该日期的日期结构对象
	stDate getDayBySpecial(short Y, short M, short N, short X);

	//[公历算法] 根据相对偏移量获取关联日期信息
	///@param	Date	公历日期信息
	///@param	Offset	相对偏移的天数
	///@return	返回该日期的日期结构对象
	stDate getDayRelative(stDate Date, long Offset);

	//[农历算法] 根据相对偏移量获取关联日期信息
	///@param	Date	农历日期信息
	///@param	Offset	相对偏移的天数
	///@return	返回该日期的日期结构对象
	stDate getDayRelativeL(stDate Date, long Offset);

	//[农历算法] 计算中国纪元年法
	///@param	Date	输入农历日期码
	///@return	返回该年相应的中国纪元年法
	short getChineseEra(short Year, short Flag);

	//刷新特定月份的日历数据，写入交割日、国定休市日等信息
	///@param	vec_Calendar	保存月历信息的Vector引用
	void RefreshMonthCalendar(vector<CHybirdDate> & vec_Calendar);

	//刷新特定日的日历数据，写入该日是否是否为交割日等信息
	///@param	vec_Calendar	保存月历信息的Vector引用
	///@param	vetIt	指向月历信息表Vector中某一日的迭代器
	void checkDeliveryDay(vector<CHybirdDate> & vec_Calendar, vector<CHybirdDate>::iterator vecIt);

	//刷新特定日的日历数据，写入该日是否为国定休市日等信息
	///@param	vec_Calendar	保存月历信息的Vector引用
	///@param	vetIt	指向月历信息表Vector中某一日的迭代器
	void checkHolidayDay(vector<CHybirdDate> & vec_Calendar, vector<CHybirdDate>::iterator vecIt);

	//刷新特定日的日历数据，写入该日是否为自然人持仓清0日等信息
	///@param	vec_Calendar	保存月历信息的Vector引用
	///@param	vetIt	指向月历信息表Vector中某一日的迭代器
	void checkAdjustDay(vector<CHybirdDate> & vec_Calendar, vector<CHybirdDate>::iterator vecIt);

	//保存日期与节气对应关系的map(1900->2100)
	//@key	int	年月日的数码，如：20120612
	//@value	short	保存节气序号量的数值[0~23]
	map<int, short> m_mapSolarTerms;

	//保存日期与农历节日对应关系的map(1800->2100)
	//@key	int	年月日的数码，如：20120612
	//@value	short	保存节日码
	map<int, short> m_mapLunarFestival;

	//保存日期与公历节日对应对应关系的map(1800->2100)
	//@key	int	年月日的数码，如：20120612
	//@value	short	保存节日码
	map<int, short> m_mapSolarFestival;

	//保存日期与特殊节日对应对应关系的map(1800->2100)
	//@key	int	年月日的数码，如：20120612
	//@value	short	保存节日码
	map<int, short> m_mapSpecialFestival;

	//保存交易休市日的list
	list<int> m_listHoliday;

	//保存空值的list
	list<int> m_listEmpty;

	//保存基本合约信息项的list
	list<CBasicInstrumentType> m_listInstrument;

	//保存最后交易日日期对应合约ID链表的map
	map<int, list<string> > m_mapInstrumentLTD;

	//保存自然人持仓清0日对应合约ID链表的map
	map<int, list<string> > m_mapInstrumentAD;

	//保存首个交割日日期对应合约ID链表的map
	map<int, list<string> > m_mapInstrumentDD1;

	//保存第2交割日日期对应合约ID链表的map
	map<int, list<string> > m_mapInstrumentDD2;

	//保存第3交割日日期对应合约ID链表的map
	map<int, list<string> > m_mapInstrumentDD3;

	//保存第4交割日日期对应合约ID链表的map
	map<int, list<string> > m_mapInstrumentDD4;

	//保存第5交割日日期对应合约ID链表的map
	map<int, list<string> > m_mapInstrumentDD5;

	//保存日历信息的数据结构项
	//@key	int	年月值的数码，如：201206
	//@value	vector<CHybirdDate>	保存有当月各天日期信息的vector
	map<int, vector<CHybirdDate> > m_mapCalendar;

	//保存工作日历信息的数据结构项
	//@key	int	年月值的数码，如：201206
	//@value	vector< list <int> > 保存有当月各天对应的日期策略ID
	map<int, vector< list <int> > > m_mapWorkCalendar;

	/// 初始化工作日历时的公历日期项
	stDate m_InitDate;
	
	/// 初始化标计，用于避免重复的多次初始化
	bool m_InitFlag;
};

#endif
