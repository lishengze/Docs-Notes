/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CExprAnalysis.h
///@brief	定义了事件计算的类
///@history
///20080610	周建军		创建该文件
///20080623	周建军		修订注释
///20091218	周建军		增加延迟计算告警时间宏定义
#ifndef REF_CEXPRANALYSIS_H
#define REF_CEXPRANALYSIS_H

#include "public.h"
#include "systools.h"
#include "CBaseValue.h"
#include "CXML.h"
#include "FtdPackageDesc.h"
#include "CBaseValue.h"
#include "CBaseContext.h"

//#define  UNKNOWN_ATTR		0				///未知类型的数据类型
//#define	 STRING_ATTR		1				///字符串数据类型
//#define	 INT_ATTR			2				///整数数据类型
//#define	 FLOAT_ATTR			3				///浮点数类型
//#define	 PERCENT_ATTR		4				///百分比数据类型
#define UNKNOWN_VALUE	UNKNOWN_ATTR
#define STRING_VALUE	STRING_ATTR
#define DINT_VALUE		INT_ATTR
#define DOUBLE_VALUE	FLOAT_ATTR
#define PERCENT_VALUE	PERCENT_ATTR
#define INT_VALUE		10
#define LIST_VALUE		11
#define OBJECT_VALUE	12

#define EXPR_DELAYTIME	300 ///告警延迟计算时间
#define outpos			printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);

/////////////////////////////////////////////////////////////////////////
///CValue定义了表达式结果值的类
///@author	周建军
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CValue :
	public CBaseValue
{
	/* */
	protected:
		///保存值类型为整数或标识符对应ID的值
		int m_intValue;

		///保存值类型为浮点数的值
		double	m_fltValue;

		///保存值类型为整数时对应的时间
		int m_intTime;

		///保存值类型为字符串的值
		CRefStringPtr m_stringValue;

		///保存函数参数值列表,函数参数值为整数
		list<int> m_listValue;

	/* */
	public:

		///构造函数
		CValue(void)
		{
			m_intTime = 0;
			m_fltValue = 0.0;
			m_intTime = 0;
			m_bConstant = false;
		}

		///拷贝构造函数
		CValue(const CValue &s)
		{
			m_valueType = s.m_valueType;
			m_intValue = s.m_intValue;
			m_stringValue = s.m_stringValue;
			m_fltValue = s.m_fltValue;
			m_bConstant = s.m_bConstant;
		}

		///析构函数
		virtual~CValue(void)
		{
		}

		///设置整数对象函数,设置对象类型为整数类型对象,值为value
			///@param	value	对象的整数值
			///@return	返回设置结果,true为成功,false为失败
		virtual bool setIntegerConstant(int value)
		{
			m_valueType = INT_VALUE;
			m_intValue = value;
			m_fltValue = (double)value;
			return true;
		}

		///取整数对象的值函数
			///@return	返回整数对象的值
		int getIntValue(void)
		{
			return m_intValue;
		}

		///设置值函数
			///@param	value	设置的值
			///@param	valueType	值的类型
		virtual bool setValue(
		int valueTime,
		const char	*valueString,
		int valueType)
		{
			m_valueType = valueType;
			if (valueType == STRING_VALUE)
			{
				m_stringValue = new CRefString(valueString);
			}
			else if (valueType == DINT_VALUE)
			{
				m_intValue = (int)atoi(valueString);
				m_intTime = valueTime;
				m_fltValue = (double)atof(valueString);
			}
			else if (valueType == FLOAT_ATTR)
			{
				m_intTime = valueTime;
				m_fltValue = (double)atof(valueString);
			}
			else if (valueType == PERCENT_ATTR)
			{
				m_intTime = valueTime;
				m_valueType = DOUBLE_VALUE;
				m_fltValue = (double)atof(valueString);
			}
			else if (valueType == UNKNOWN_VALUE)
			{
				m_valueType = valueType;
				m_intTime = valueTime;
			}
			else
			{
				printf(
					"UnKnown value type %d valueTime %d valueString %s\n",
					valueType,
					valueTime,
					valueString);
			}

			return true;
		}

		///设置字符串对象函数,设置对象类型为字符串类型对象,值为value
			///@param	value	对象的字符串值
			///@return	返回设置结果,true为成功,false为失败
		virtual bool setStringConstant(const CRefStringPtr &value)
		{
			m_valueType = STRING_VALUE;
			m_stringValue = value;
			return true;
		}

		///设置字符串对象函数,设置对象类型为字符串类型对象,值为value
			///@param	value	对象的字符串值
			///@return	返回设置结果,true为成功,false为失败
		bool setStringConstant(const CRefStringPtr &value, int timeValue)
		{
			m_valueType = STRING_VALUE;
			m_stringValue = value;
			m_intTime = timeValue;
			return true;
		}

		///取字符串对象的值函数
			///@return	返回字符串对象的引用
		CRefStringPtr &getStringValue(void)
		{
			return m_stringValue;
		}

		///设置标识符对象函数,设置对象类型为标识符类型对象,值为value
			///@param	value	对象的标识符值
			///@return	返回设置结果,true为成功,false为失败
		virtual bool setIdentifierConstant(const CRefStringPtr &value);

		///设置标识符对象函数,设置对象类型为标识符类型对象,值为value
			///@param	value	标识符值对象的ID
		void setObjectValue(int value)
		{
			m_valueType = OBJECT_VALUE;
			m_intValue = value;
		}

		///取标识符对象ID的函数
			///@return	返回标识符对象的ID
		int getObjectValue(void)
		{
			return m_intValue;
		}

		///设置list对象函数,设置对象类型为list类型对象,值为value
			///@param	value	list值
		void setListValue(int value)
		{
			m_valueType = LIST_VALUE;
			m_listValue.push_back(value);
		}

		///取标识符对象ID的函数
			///@return	返回标识符对象的ID
		list<int> *getListValue(void)
		{
			return &m_listValue;
		}

		///设置整数对象函数,设置对象类型为整数类型对象,值为value
			///@param	value	对象的整数值
			///@param	timeValue	监控指标值对应的时间
			///@return	返回设置结果,true为成功,false为失败
		bool setDIntConstant(int value, int timeValue)
		{
			m_valueType = DINT_VALUE;
			m_intValue = value;
			m_intTime = timeValue;
			m_fltValue = (double)value;
			return true;
		}

		///设置浮点数对象函数,设置对象类型为浮点类型对象,值为value
			///@param	value	对象的浮点值
			///@return	返回设置结果,true为成功,false为失败
		virtual bool setFloatConstant(double value)
		{
			m_valueType = DOUBLE_VALUE;
			m_fltValue = value;
			m_intValue = (int)value;
			return true;
		}

		///设置浮点数对象函数,设置对象类型为浮点类型对象,值为value
			///@param	value	对象的浮点值
			///@param	timeValue	监控指标值对应的时间
			///@return	返回设置结果,true为成功,false为失败
		bool setFltConstant(double value, int timeValue)
		{
			m_valueType = DOUBLE_VALUE;
			m_fltValue = value;
			m_intTime = timeValue;
			m_intValue = (int)value;
			return true;
		}

		///取整数对象的值函数
			///@return	返回整数对象值
		int getDIntValue(void)
		{
			return m_intValue;
		}

		///取浮点对象的值函数
			///@return	返回整数对象值
		double getFltValue(void)
		{
			return m_fltValue;
		}

		///取对象的时间值函数
		///@return	返回整数对象的时间值
		int getDTimeValue(void)
		{
			return m_intTime;
		}

		///对象输出函数
		virtual void display(FILE *output = stdout);
};


/// Mod by Henchi, 20130531
/// 数据格式调整，字段精简
#define RECORDWARNINGINFO_ATTR		char szBuf[4096];		\
	sprintf(szBuf,"[%s] %s:%s Value[%s] MTime[%d] Now[%d] Delay(%d)sec\r\n",	\
		(const char *)pMonitorEntity->Time,													\
		g_mStringIdMap.getString(pMonitorEntity->MonitorObject),	\
		g_mStringIdMap.getString(pMonitorEntity->MonitorItem),		\
		(const char *)pMonitorEntity->AttrValue,									\
		(int)(pMonitorEntity->MonitorTime),												\
		(int)m_now,	(int)m_now - (int)(pMonitorEntity->MonitorTime) 		\
	);	\
	if (std::find(g_warningInfoList.begin(), g_warningInfoList.end(), szBuf) == g_warningInfoList.end())	\
		g_warningInfoList.push_back(szBuf);


#define RECORDWARNINGINFO_NOATTR		char szBuf[4096];		\
	char clockBuffer[20];															  \
	time_t	timeClock = monitorNow;													  \
	struct tm tm_time;										  \
	if (LocalTime(&timeClock, &tm_time) != NULL)															  \
	{																				  \
		sprintf(																	  \
			clockBuffer,															  \
			"%04d%02d%02d %02d:%02d:%02d",											  \
			1900 + tm_time.tm_year,												  \
			1 + tm_time.tm_mon,													  \
			tm_time.tm_mday,														  \
			tm_time.tm_hour,														  \
			tm_time.tm_min,														  \
			tm_time.tm_sec);														  \
	}																				  \
	sprintf(szBuf,"[%s] %s:%s Value[(null)]\r\n",	\
		(const char *)clockBuffer,																\
		g_mStringIdMap.getString(monitorObject),	\
		g_mStringIdMap.getString(monitorItem));	\
	g_bValueExist = false;															  \
	result.setDIntConstant(-1, -1);												\
	if (std::find(g_warningInfoList.begin(), g_warningInfoList.end(), szBuf) == g_warningInfoList.end())	\
		g_warningInfoList.push_back(szBuf);


#define RECORDWARNINGINFO_EVENT		char szBuf[4096];		\
	sprintf(szBuf,"[%s] %s %s[%s][%s] Des[%s] MTime[%d] Now[%d] Delay(%d)sec\r\n",	\
		(const char *)pEventEntity->Time,													\
		g_mStringIdMap.getString(pEventEntity->MonitorObject),	\
		g_mStringIdMap.getString(pEventEntity->EventName),		\
		(const char *)pEventEntity->WarningLevel,							\
		(const char *)pEventEntity->ProcessFlag,							\
		(const char *)pEventEntity->EventDes,									\
		(int)(pEventEntity->MonitorTime),												\
		(int)m_now,	(int)m_now - (int)(pEventEntity->MonitorTime) 		\
	);	\
	if (std::find(g_warningInfoList.begin(), g_warningInfoList.end(), szBuf) == g_warningInfoList.end())	\
		g_warningInfoList.push_back(szBuf);


/////////////////////////////////////////////////////////////////////////
///CContext定义了一个计算上下文的类，使用的模板基于CValue值类
///@author	周建军
///@version	1.0,20080623
/////////////////////////////////////////////////////////////////////////
class CContext :
	public CBaseContext<CValue>
{
	/* */
	private:
		///保存的当前时间关键字的值
		int m_now;

	/* */
	public:
		///构造函数
			///@param	pConfigFile	内存数据库使用的配置文件名
		CContext(char *pConfigFile);

		///析构函数
		~ CContext(void);

		///设置当前时间关键字值函数
			///@param	newNow	新的当前时间值
		void setNow(int newNow);

		///读取当前时间关键字值函数
			///@return	返回当前时间now关键字的整数值
		int getNow(void);

		///更新当前时间关键字值函数
			///@param	newNow	新的当前时间值
		void updateNow(int newNow)
		{
			m_now = newNow;
		}

		///取关键字值函数
			///@param	result	保存关键字取得的结果值
			///@param	keyword	关键字的名称
			///@return	返回结果,为true表示成功,false表示失败
		virtual bool getKeywordValue(CValue &result, const char *keyword);

		///单目运算符计算函数,计算单目运算符的结果值
			///@param	result	用来存放计算结果值
			///@param	value	单目运算符操作对象
			///@param	thisOperator	单目运算符名
			///@return	返回结果,true表示成功,false表示失败
		virtual bool getUniOperatorResult(
						CValue	&result,
						CValue	&value,
						const char	*thisOperator);

		///双目运算符计算函数,计算双目运算符的结果值
			///@param	result	用来存放计算结果值
			///@param	value1	双目运算符操作对象
			///@param	thisOperator	双目运算符名
			///@param	value2	双目运算符操作对象
			///@return	返回结果,true表示成功,false表示失败
		virtual bool getBiOperatorResult(
						CValue	&result,
						CValue	&value1,
						const char	*thisOperator,
						CValue	&value2);

		///计算函数的值，函数使用标识符（注意，也可能是数组等情况）
			///@param	result	放置结果的值
			///@param	identifier	函数的名称标识符
			///@param	funcSeperator	函数参数的分隔符的第一个，一般是'('、'['等情况
			///@param	paraCount	参数的个数
			///@param	paraList	参数清单，
			///@return	返回结果,true表示成功,false表示失败
		virtual bool evalFunction(
						CValue	&result,
						const CRefStringPtr &identifier,
						char funcSeperator,
						int paraCount,
						CValue	**paraList);

		///if函数的实现函数
			///@param	result	放置结果的值
			///@param	paraList	参数清单，
			///@return	返回结果,true表示成功,false表示失败
		bool ifFunc(CValue &result, CValue **paraList);

		///myItoa函数的实现函数,整数变为字符串类型
			///@param	result	放置结果的值
			///@param	paraList	参数清单,
			///		paraList[0]为需要变换的整数,paraList[1]为字符串长度
			///@return	返回结果,true表示成功,false表示失败
		bool myItoa(CValue &result, CValue **paraList);

		///myAtoi函数的实现函数,字符串变换为整数
			///@param	result	放置结果的值
			///@param	paraList	参数清单
			///@return	返回结果,true表示成功,false表示失败
		bool myAtoi(CValue &result, CValue **paraList);

		///myAtof函数的实现函数,字符串变换为浮点数
			///@param	result	放置结果的值
			///@param	paraList	参数清单
			///@return	返回结果,true表示成功,false表示失败
		bool myAtof(CValue &result, CValue **paraList);

		///Ttoi函数的实现函数,字符串时间变换为整数
			///@param	result	放置结果的值
			///@param	paraList	参数清单
			///@return	返回结果,true表示成功,false表示失败
		bool Ttoi(CValue &result, CValue **paraList);

		///Itot函数的实现函数,整数时间变换为字符串
			///@param	result	放置结果的值
			///@param	paraList	参数清单
			///@return	返回结果,true表示成功,false表示失败
		bool Itot(CValue &result, CValue **paraList);

		///nowbetween函数,判断当前时间是否在时间范围内
			///@param	result	保存函数计算结果值
			///@param	paraList	nowbetween函数的参数列表
			///@return	返回结果,为true表示成功,false表示失败
		bool nowbetween(CValue &result, CValue **paraList);

		///valbetween函数,判断当前对象数据是否在值域范围[value1, value2)内(左闭右开)
			///@param	result	保存函数计算结果值
			///@param	paraList	valbetween函数的参数列表
		//object， 目标对象值
		//value1，对比集合域左值
		//value2，对比集合域右值
			///@return	返回结果,为true表示成功,false表示失败
		bool valbetween(CValue &result, CValue **paraList);

		///ObjectIn函数,检查目标关键字是否属于对比集合域
			///@param	result	保存函数计算结果值
			///@param	paraCount	保存参数个数值
			///@param	paraList	ObjectIn函数的参数列表
			///@paraList
		//object， 目标关键字
		//valueList，对比集合域信息列表，不限枚举个数
		//返回值：如果集合域中存在有与object关键字相同值则返回true,否则为false
			///@return	返回结果,为true表示成功,false表示失败
		bool ObjectIn(CValue &result, int paraCount, CValue **paraList);

		///ObjectContain函数,检查目标关键字是否属于对比集合域
			///@param	result	保存函数计算结果值
			///@param	paraCount	保存参数个数值
			///@param	paraList	ObjectContain函数的参数列表
			///@paraList
		//object， 目标关键字
		//valueList，对比集合域信息列表，不限枚举个数
		//返回值：如果集合域中存在有[包含]object关键字的串值则返回true,否则为false
			///@return	返回结果,为true表示成功,false表示失败
		bool ObjectContain(CValue &result, int paraCount, CValue **paraList);

		///getdatediff函数,计算两个日期串之间相差天数
			///@param	result	保存函数计算结果值
			///@param	paraList	getdatediff函数的参数列表
			///@return	返回结果,为true表示成功,false表示失败
		bool getdatediff(CValue &result, CValue **paraList);

		///gettimediff函数,计算两个时间串之间相差秒数
			///@param	result	保存函数计算结果值
			///@param	paraList	gettimediff函数的参数列表
			///@return	返回结果,为true表示成功,false表示失败
		bool gettimediff(CValue &result, CValue **paraList);

		///getTimeSec函数,返回由值对像保存的秒数值
		///@param	result	保存函数计算结果值
		///@param	pTimeValue	保存时间数据的Value结构，可为数值或字串型(支持8或含日期17字节时间格式)
		///@return	返回具体的秒数数据
		int getTimeSec(CValue * pTimeValue);
		
		///getTimeGap函数,计算两个时间（数据或含日期前串也支持）之间相差秒数的绝对值
		///@param	result	保存函数计算结果值
		///@param	paraCount	getTimeGap函数的参数个数
		///@param	paraList	getTimeGap函数的参数列表
		///@return	返回结果,为true表示成功,false表示失败
		bool getTimeGap(CValue &result, CValue **paraList);

		///getperiod函数,取指标的采集时间间隔
			///@param	result	保存函数计算结果值
			///@param	paraList	getperiod函数的参数列表
			///@return	返回结果,为true表示成功,false表示失败
		bool getperiod(CValue &result, CValue **paraList);

		///getStringId函数,取字符串对应的ID值
			///@param	result	保存函数计算结果值
			///@param	paraList	getValue函数的参数列表
			///@return	返回结果,为true表示成功,false表示失败
		bool getStringId(CValue &result, CValue **paraList);

		///getmaincentername函数,取当前主数据中心的名称
			///@param	result	保存函数计算结果值
			///@param	paraList	getperiod函数的参数列表
			///@return	返回结果,为true表示成功,false表示失败
		bool getmaincentername(CValue &result, CValue **paraList);

		///getactiveapp函数,取当前指定类型的活动业务进程的个数
			///@param	result	保存函数计算结果值
			///@param	paraList	getperiod函数的参数列表
			///@return	返回结果,为true表示成功,false表示失败
		bool getactiveapp(CValue &result, CValue **paraList);

		///getSystemName函数,取当前对象所属的业务系统名
			///@param	result	保存函数计算结果值
			///@param	paraList	getSystemName函数的参数列表
			///@return	返回结果,为true表示成功,false表示失败
		bool getSystemName(CValue &result, CValue **paraList);

		///getDomainName函数,取对象ID中指定域部分的字串
			///@param	result	保存函数计算结果值
			///@param	paraList	getDomainName函数的参数列表
			///@return	返回结果,为true表示成功,false表示失败
		bool getDomainName(CValue &result, CValue **paraList);

		///getValue函数,根据监控对象ID,指标ID,时间取监控指标的值
			///@param	result	保存函数计算结果值
			///@param	paraList	getValue函数的参数列表
			///@return	返回结果,为true表示成功,false表示失败
		bool getValue(CValue &result, CValue **paraList);

		///===根据事件内存表计算的函数定义===
			///Summary函数,统计最近一段时间内事件发生次数
			///@param	result	保存函数计算结果值
			///@param	paraList	Summary函数的参数列表
			///@paraList	仅接受一个参数: EventName	事件名
			///@return	返回结果,为true表示成功,false表示失败
		bool Summary(CValue &result, CValue **paraList);

		///ObjectEventSummary函数,统计指定对象最近一段时间内事件发生次数
			///@param	result	保存函数计算结果值
			///@param	paraList	ObjectEventSummary函数的参数列表
			///@paraList	仅接受两个参数: ObjectId对象ID,EventName事件名
			///@return	返回结果,为true表示成功,false表示失败
		bool ObjectEventSummary(CValue &result, CValue **paraList);

		///Exist函数,最近一段时间内是否发生某事件
			///@param	result	保存函数计算结果值
			///@param	paraList	Summary函数的参数列表
			///@paraList	仅接受一个参数: EventName	事件名
			///@return	返回结果,为true表示成功,false表示失败
		bool Exist(CValue &result, CValue **paraList);

		///ObjectEventExist函数,统计指定对象最近一段时间内是否发生某事件
			///@param	result	保存函数计算结果值
			///@param	paraList	ObjectEventSummary函数的参数列表
			///@paraList	仅接受两个参数: ObjectId对象ID,EventName事件名
			///@return	返回结果,为true表示成功,false表示失败
		bool ObjectEventExist(CValue &result, CValue **paraList);

		///IsWorkingDay函数,检查事件当天是否是工作日函数
			///@param	result	保存函数计算结果值，如果是工作日，result为1，否则为0
			///@param	paraList	IsWorkingDay函数的参数列表
			///@return	返回结果,为true表示成功,false表示失败
		bool IsWorkingDay(CValue &result, CValue **paraList);

		///IsDayTradingPeriod函数,判断给定的时刻是否是日盘交易时段
			///@param	result	保存函数计算结果值
			///@param	paraCount	保存参数个数			
			///@param	paraList	getDomainName函数的参数列表
			///@return	返回结果,为true表示成功,false表示失败
		bool IsDayTradingPeriod(CValue &result, int paraCount, CValue **paraList);

		///IsNightTradingPeriod函数,判断给定的时刻是否是夜盘交易时段
			///@param	result	保存函数计算结果值
			///@param	paraCount	保存参数个数			
			///@param	paraList	getDomainName函数的参数列表
			///@return	返回结果,为true表示成功,false表示失败
		bool IsNightTradingPeriod(CValue &result, int paraCount, CValue **paraList);

		///IsTradingPeriod函数,判断给定的时刻是否是交易时段
		///@param	result	保存函数计算结果值
		///@param	paraCount	保存参数个数			
		///@param	paraList	getDomainName函数的参数列表
		///@return	返回结果,为true表示成功,false表示失败
		bool IsTradingPeriod(CValue &result, int paraCount, CValue **paraList);

		///IsTradingDay函数,判断给定的日期是否是交易日
		///@param	result	保存函数计算结果值
		///@param	paraCount	保存参数个数			
		///@param	paraList	getDomainName函数的参数列表
		///@return	返回结果,为true表示成功,false表示失败
		bool IsTradingDay(CValue &result, int paraCount, CValue **paraList);

		///IsContinuousTradingDay函数,判断给定的日期是否是连续交易日
		///@param	result	保存函数计算结果值
		///@param	paraCount	保存参数个数			
		///@param	paraList	getDomainName函数的参数列表
		///@return	返回结果,为true表示成功,false表示失败
		bool IsContinuousTradingDay(CValue &result, int paraCount, CValue **paraList);

		///HasNightTradingPeriod函数,判断给定的日期是否有夜盘
		///@param	result	保存函数计算结果值
		///@param	paraCount	保存参数个数			
		///@param	paraList	getDomainName函数的参数列表
		///@return	返回结果,为true表示成功,false表示失败
		bool HasNightTradingPeriod(CValue &result, int paraCount, CValue **paraList);

		///CheckEventOccur函数,检查事件是否发生函数
			///@param	result	保存函数计算结果值
			///@param	paraList	CheckEventOccur函数的参数列表
			///@paraList	ObjectId对象ID,EventName事件名,Interval事件发生距离现在的最大间隔,KeyType检查的关键字名,KeyValue检查的关键字值
			///@return	返回结果,为true表示成功,false表示失败
		bool CheckEventOccur(CValue &result, CValue **paraList);

		///CheckEventDesc函数,检查发生事件描述中的关键字对应的值是否相同的函数
			///@param	result	保存函数计算结果值
			///@param	paraList	CheckEventOccur函数的参数列表
			///@paraList	ObjectId对象ID,EventName事件名,Interval事件发生距离现在的最大间隔,KeyType检查的关键字名,KeyValue检查的关键字值
		//objectid， 对象ID
		//eventname， 事件名
		//timeval，只检查最近时间间隔内的事件
		//key，事件描述中需要检查的关键字
		//value，事件描述中需要检查关键字的值
		//返回值：如果描述中存在 key='value'，则该函数返回为true
			///@return	返回结果,为true表示成功,false表示失败
		bool CheckEventDesc(CValue &result, CValue **paraList);

		///CheckEventValid函数,检查时段内发生事件描述中的是否存在不符合键值对要求的对象
			///@param	result	保存函数计算结果值
			///@param	paraList	CheckEventOccur函数的参数列表
			///@paraList	ObjectId对象ID,EventName事件名,Interval事件发生距离现在的最大间隔,KeyType检查的关键字名,KeyValue检查的关键字值
		//objectid， 对象ID
		//eventname， 事件名
		//timeval，只检查最近时间间隔内的事件
		//key，事件描述中需要检查的关键字
		//value，事件描述中需要检查关键字的值
		//返回值：如果描述中存在 key!='value'，则该函数返回为false，否则返回true
			///@return	返回结果,为true表示成功,false表示失败
		bool CheckEventValid(CValue &result, CValue **paraList);

		///CheckEventDescExist函数,检查时段内发生事件描述中的是否存在符合键值对要求的对象
			///@param	result	保存函数计算结果值
			///@param	paraList	CheckEventOccur函数的参数列表
			///@paraList	ObjectId对象ID,EventName事件名,Interval事件发生距离现在的最大间隔,KeyType检查的关键字名,KeyValue检查的关键字值
		//objectid， 对象ID
		//eventname， 事件名
		//timeval，只检查最近时间间隔内的事件
		//key，事件描述中需要检查的关键字
		//value，事件描述中需要检查关键字的值
		//返回值：如果描述中存在 key='value'，则该函数返回为true
			///@return	返回结果,为true表示成功,false表示失败
		bool CheckEventDescExist(CValue &result, CValue **paraList);

		//++++++++++ Added by Henchi, 20120620 ++++++++++
		
		///CheckEventDescValue函数，寻找指定时间内是否存在符合条件的事件（基于"AND"运算的事件描述多值校验）
		///@param	result	保存函数计算结果值
		///@param	paraCount	CheckEventDescValue函数的参数个数
		///@param	paraList	CheckEventDescValue函数的参数列表
		///@paraList	ObjectId对象ID,EventName事件名,Interval事件发生距离现在的最大间隔,KeyType检查的关键字名,KeyValue检查的关键字值
		//[1]objectid， 对象ID
		//[2]eventname， 事件名
		//[3]timeval，只检查最近时间间隔内的事件
		//[4]fieldno，指定的域号（以空格分隔的）
		//[5]operator，关系运算符字串（整形比较:eq,ge,le,gt,lt,ne;字串比较:eqs,ges,les,gts,lts,nes）
		//[6]value，指定匹配的值
		//[...]：后三条条件项可多次出现，用于指定多条件校验
		//返回值：true表示找到了,false表示没有找到
			///@return	返回结果,为true表示成功,false表示失败
		bool CheckEventDescValue(
				CValue	&result,
				int paraCount,
				CValue	**paraList);

		///CheckEventDescValueOR函数，寻找指定时间内是否存在符合条件的事件（基于"OR"运算的事件描述多值校验）
		///@param	result	保存函数计算结果值
		///@param	paraCount	CheckEventDescValue函数的参数个数
		///@param	paraList	CheckEventDescValue函数的参数列表
		///@paraList	ObjectId对象ID,EventName事件名,Interval事件发生距离现在的最大间隔,KeyType检查的关键字名,KeyValue检查的关键字值
		//[1]objectid， 对象ID
		//[2]eventname， 事件名
		//[3]timeval，只检查最近时间间隔内的事件
		//[4]fieldno，指定的域号（以空格分隔的）
		//[5]operator，关系运算符字串（整形比较:eq,ge,le,gt,lt,ne;字串比较:eqs,ges,les,gts,lts,nes）
		//[6]value，指定匹配的值
		//[...]：后三条条件项可多次出现，用于指定多条件校验
		//返回值：true表示找到了,false表示没有找到
		///@return	返回结果,为true表示成功,false表示失败
		bool CheckEventDescValueOR(
				CValue	&result,
				int paraCount,
				CValue	**paraList);

		///GetEventTimeByDescValue函数，寻找指定时间内是否存在符合条件的事件（基于"AND"运算的事件描述多值校验）,并返回事件时间(整型)
		///@param	result	保存函数计算结果值
		///@param	paraCount	CheckEventDescValue函数的参数个数
		///@param	paraList	CheckEventDescValue函数的参数列表
		///@paraList	ObjectId对象ID,EventName事件名,Interval事件发生距离现在的最大间隔,KeyType检查的关键字名,KeyValue检查的关键字值
		//[1]objectid， 对象ID
		//[2]eventname， 事件名
		//[3]timeval，只检查最近时间间隔内的事件
		//[4]fieldno，指定的域号（以空格分隔的）
		//[5]operator，关系运算符字串（整形比较:eq,ge,le,gt,lt,ne;字串比较:eqs,ges,les,gts,lts,nes）
		//[6]value，指定匹配的值
		//[...]：后三条条件项可多次出现，用于指定多条件校验
		//返回值：true表示找到了,false表示没有找到
			///@return	返回结果,为true表示成功,false表示失败
		bool GetEventTimeByDescValue(
				CValue	&result,
				int paraCount,
				CValue	**paraList);

		///GetEventTimeByDescValueOR函数，寻找指定时间内是否存在符合条件的事件（基于"OR"运算的事件描述多值校验）,并返回事件时间(整型)
		///@param	result	保存函数计算结果值
		///@param	paraCount	CheckEventDescValue函数的参数个数
		///@param	paraList	CheckEventDescValue函数的参数列表
		///@paraList	ObjectId对象ID,EventName事件名,Interval事件发生距离现在的最大间隔,KeyType检查的关键字名,KeyValue检查的关键字值
		//[1]objectid， 对象ID
		//[2]eventname， 事件名
		//[3]timeval，只检查最近时间间隔内的事件
		//[4]fieldno，指定的域号（以空格分隔的）
		//[5]operator，关系运算符字串（整形比较:eq,ge,le,gt,lt,ne;字串比较:eqs,ges,les,gts,lts,nes）
		//[6]value，指定匹配的值
		//[...]：后三条条件项可多次出现，用于指定多条件校验
		//返回值：true表示找到了,false表示没有找到
		///@return	返回结果,为true表示成功,false表示失败
		bool GetEventTimeByDescValueOR(
				CValue	&result,
				int paraCount,
				CValue	**paraList);

		///getEventDesc函数,获取指定时间内最近一条指定事件的描述，并从中截取目标字段
		///@param	result	保存函数计算结果值
		///@param	paraList	getEventDesc函数的参数列表
		///@paraList	ObjectId对象ID,EventName事件名,Interval事件发生距离现在的最大间隔,KeyType检查的关键字名,KeyValue检查的关键字值
		//objectid， 对象ID
		//eventname， 事件名
		//timeval，只检查最近时间间隔内的事件
		//fieldno，指定的域号（以空格分隔的）
		//返回值：返回目标域的字串信息（由1开始标识域号，0表示全部描述信息）
			///@return	返回结果,为true表示成功,false表示失败
		bool getEventDesc(CValue &result, CValue **paraList);

		//++++++++++ Added End ++++++++++
		
		///+++根据事件内存表计算的函数定义+++
		
		///getItemValue函数,取监控指标的值
		///@param	result	保存函数计算结果值
		///@param	monitorObject	监控对象的ID
		///@param	monitorItem	监控指标的ID
		///@param	monitorTime	监控的时间
		///@return	返回监控指标是否取得成功，true表示成功，false表示失败
		double	getItemValue(
					int monitorObject,
					int monitorItem,
					int monitorTime);

		///getItemValue函数,取监控指标的值
		///@param	result	保存函数计算结果值
		///@param	monitorObject	监控对象的ID
		///@param	monitorItem	监控指标的ID
		///@param	monitorTime	监控的时间
		///@return	返回监控指标是否取得成功，true表示成功，false表示失败
		bool getItemValue(
				CValue	&result,
				int monitorObject,
				int monitorItem,
				int monitorNow);

		///getLastedItemValue函数,取监控指标最新的值(@)
		///@param	result	保存函数计算结果值
		///@param	monitorObject	监控对象的ID
		///@param	monitorItem	监控指标的ID
		///@param	monitorTime	返回监控的时间
		///@return	返回监控指标是否取得成功，true表示成功，false表示失败
		bool getLastedItemValue(
				CValue	&result,
				int monitorObject,
				int monitorItem,
				int monitorNow,
				int &monitorTime);

		///getLastedItemTime函数,取监控指标最新的值对应的时间
		///@param	result	保存函数计算结果值
		///@param	monitorObject	监控对象的ID
		///@param	monitorItem	监控指标的ID
		///@param	monitorTime	返回监控的时间
		///@return	返回监控指标是否取得成功，true表示成功，false表示失败
		bool getLastedItemTime(
				CValue	&result,
				int monitorObject,
				int monitorItem,
				int monitorNow,
				int &monitorTime);

		///getNextItemValue函数,取监控指标上一次的值(#)
			///@param	result	保存函数计算结果值
			///@param	monitorObject	监控对象的ID
			///@param	monitorItem	监控指标的ID
			///@param	monitorTime	返回监控的时间
			///@return	返回监控指标是否取得成功，true表示成功，false表示失败
		bool getNextItemValue(
				CValue	&result,
				int monitorObject,
				int monitorItem,
				int monitorNow,
				int &monitorTime);

		///getNextItemTime函数,取监控指标上一次的值对应的时间
			///@param	result	保存函数计算结果值
			///@param	monitorObject	监控对象的ID
			///@param	monitorItem	监控指标的ID
			///@param	monitorTime	返回监控的时间
			///@return	返回监控指标是否取得成功，true表示成功，false表示失败
		bool getNextItemTime(
				CValue	&result,
				int monitorObject,
				int monitorItem,
				int monitorNow,
				int &monitorTime);

		///getCurrentItemValue函数,取监控指标指定时间以前的值($)
			///@param	result	保存函数计算结果值
			///@param	monitorObject	监控对象的ID
			///@param	monitorItem	监控指标的ID
			///@param	monitorTime	返回监控的时间
			///@return	返回监控指标是否取得成功，true表示成功，false表示失败
		bool getCurrentItemValue(
				CValue	&result,
				int monitorObject,
				int monitorItem,
				int &monitorNow,
				int timeVal);		
};

class CEventNodePaser;

/////////////////////////////////////////////////////////////////////////
///CExprAnalysis定义了解析XML事件定义表达式并计算分析的类
///@author	周建军
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CExprAnalysis
{
	/* */
	public:
		///构造函数
			///@param	pEventCfgFile	定义事件的XML文件名
		CExprAnalysis(char *pEventCfgFile);

		///析构函数
		~ CExprAnalysis(void);

		///增加监控状态值函数
			///@param	monitorObject	监控对象名
			///@param	monitorItem	监控指标名
			///@param	monitorTime	监控指标产生的时间
			///@param	monitorValue	监控指标的值(整数)
		void addMonitorEntity(
				const char	*monitorObject,
				const char	*monitorItem,
				int monitorTime,
				int monitorValue);

		///增加监控状态值函数
			///@param	monitorObject	监控对象名
			///@param	monitorItem	监控指标名
			///@param	monitorTime	监控指标产生的时间
			///@param	monitorValue	监控指标的值(整数)
		void addMonitorEntity(
				int monitorObject,
				int monitorItem,
				int monitorTime,
				int monitorValue);

		///提取指标函数,从表达式中提取出第一个没有指定监控对象的指标
			///@param	attr	提取到的监控指标
			///@param	object	提取到的监控对象
			///@param	expr	表达式的指针
		bool getAttrFromExpr(string &attr, string &object, char *expr);

		///增加监控对象到指标函数,没有指明监控对象的指标需要增加监控对象
			///@param	strExpr	输出的计算公式	
			///@param	objectid	需要增加的对象ID
			///@param	expr	表达式的指针
		bool addObjectIdtoExpr(string &strExpr, string &objectid, char *pExpr);

		///增加表达式函数
		void addExpr(void);

		void exprTest(void);
		void exprRun(void);

		//填充来自数据库的表达式
		bool generateObjectExpr(
				map<int, map<string, int> > &expr_device_list,
				map<string, map<string, int> > &,
				map<int, CFTDRspQryNetEventExprField> &exprs);

		bool isExprAvailable(void)
		{
			return m_bExprAvailable;
		}

		void AddWarningEvent(CFTDRtnWarningEventField &warningevent)
		{
			m_listWarningEvent.add(warningevent);
		}

		bool GetWarningEvent(CFTDRtnWarningEventField &warningevent)
		{
			return m_listWarningEvent.get(warningevent);
		}

	/* */
	private:
		//批量计算表达式
		void RunExprs(list<CEventNodePaser *> &parser_list);

	/* */
	private:
		///XML文档类指针
		CXMLDoc *m_pXMLDoc;

		///XML根节点指针
		CXMLNode *m_pXMLRoot;

		///保存XML文件名指针
		string	m_sXmlFile;

		///表达式是否生成
		bool m_bExprAvailable;

		///发送给config的告警事件队列
		TemplateMutexCatch<CFTDRtnWarningEventField> m_listWarningEvent;

	/* */
	public:
		TemplateMutexMap<string, string> m_mapWarningEventExpr;

		///告警事件对应的的告警明细信息
		TemplateMutexMap<string, string> m_mapWarningInfo;
};

int getTimeFromStr(char *pdate, char *ptime);

string	transformStr(string oristr);
#endif // REF_CEXPRANALYSIS_H
