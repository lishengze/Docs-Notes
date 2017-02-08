/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CCalendar.cpp
///@brief	定义了运维管理系统公用的日历工具类
///@history
///20120628	晏鹤春	创建该文件

#include "CCalendar.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "time.h"
#include "utility.h"
// for std::find()
#include <algorithm>

// x 为map<int, list <string> >对象； y 为int对象; z 为char *对象
#define  SAFE_ADD_DATE_LIST(x, y, z)		\
	{															\
		map<int, list <string> >::iterator mapIt_ = x.find(y);	\
		if (mapIt_ == x.end())									\
		{														\
			list <string> listIDs;								\
			listIDs.push_back(string(z));						\
			x[y] = listIDs;										\
		}														\
		else													\
		{														\
			list <string> & listIDs = mapIt_->second;			\
			listIDs.push_back(string(z));						\
		}														\
	}															\

// x 为map<int, list <string> >对象； y 为int对象; z 为char *对象
#define  SHOW_DATE_LIST(x, y, z)			\
	{															\
		map<int, list <string> >::iterator mapIt = x.find(y);	\
		if (mapIt != x.end())									\
		{														\
			list <string> & listIDs = mapIt->second;			\
			list <string>::iterator listIt = listIDs.begin();	\
			printf("%s:", z);									\
			for (; listIt != listIDs.end(); listIt++)			\
			{													\
				printf("%s ", (*listIt).c_str());				\
			}													\
			printf("\n");										\
		}														\
	}															\

/// 日历范围 1800 -> 2100
stDate stDateS(CALENDAR_YEAR_START,1,25);				//  农历1800正月初一(星期六)
stDate stDateE(CALENDAR_YEAR_END+1,1,28);				//  农历2100腊月廿九(未使用)
stLunarYear stLYear[CALENDAR_YEAR_END+1 - CALENDAR_YEAR_START] = {4};		// 初始化300个农历年对象，其中1800年为闰4月

// 公历非闰年的每月天数
unsigned char SMonthDays[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

//农历1800-2100年大月(30天)小月(29天)闰月数据(hex string)
unsigned char LMonthDays[] = 
{
	"adca5aa92bb525bba25bb493b64a5ba9add496ea8a6ed14eea4a6da5b6"
	"545baa4bba45bba82b75a5b654abaa55d526eda4aed495da526daa5655"
	"abb295ba5257aa4b75a95655abaa56ea4a5da92ed965d594adaa56692b"
	"75a5ba64977493b6ca5a69add496da925dd24dda495da9add45a6a4b75"
	"4937692775a5b6545baa2dd526dda49dd495ba525baa5555ab6a937652"
	"57ea4a75a95655abaa55da4a5da92bd925db54abaa56592b75a5ae6497"
	"ec92aed25659abb495da925dd24bba495ba9add4566a4b75492fe9266d"
	"a5aed4566a2db525bba49bb493ba525baa55d5aa6a936ed24eea4a6da9"
	"36d5aaaa55b64a5ba92b75a5ba54abaa55d52a6da5aed495ec926daa56"
	"55abb495ba525bb24b76495769abb455da4a6dc92ee925dda4add4566a"
	"4bb5a5baa4977493b652576a4db5a6da926dd24dda4a5da92dd5aa6a55"
	"b54937692775a5b654abaa55d52a5da5add495ba925daa55d5aa6c95b6"
	"5257724b76c95659abac55da4a5da92dd925bda4abb4555a4b6da5b6649"
	"7f492aed2566a4bb5a5da925dd24bba495ba92bb5aa6a53754937e9266d"
	"a5aed4966a55b52a5ba5abb495ba525baa55d5aa6a95aed256ea4a6ec94"
	"ed9aa6a55b64a5ba92bb945bb64abb455d64a6da5aee416eda26ed25502"
};

//农历1800-2100年111个闰月所形成的110个间距的数据
short LeapMonthGap[22] = 
{ 
	32198,25072,32079,29168,31350,3554,29118,28494,25464,28215,7608,
	27766,3975,30902,28494,21489,28214,7132,27766,3975,25078,28039
};

// 农历生肖信息
const char *ZodiacSymbols[] = 
{"鼠","牛","虎","兔","龙","蛇","马","羊","猴","鸡","狗","猪",0x00};
// 干支纪元 － 天干
const char *TianGan[] = 
{"甲","乙","丙","丁","戊","己","庚","辛","壬","癸",0x00};
// 干支纪元 － 地支
const char *DiZhi[] = 
{"子","丑","寅","卯","辰","巳","午","未","申","酉","戌","亥",0x00};
// 日份码(前缀)
const char *DayPreSign[] = 
{"初","十","廿","卅",0x00};
// 日份码
const char *DaySign[] = 
{"日","一","二","三","四","五","六","七","八","九","十",0x00};
// 日份码(英文－全大写)
const char *DaySignENG[] =
{"SUN","MON","TUE","WED","THU","FRI","SAT",0x00};
// 日份码(英文－首字母大写)
const char *DaySignEng[] =
{"Sun","Mon","Tue","Wed","Thu","Fri","Sat",0x00};
// 月份码
const char *MonthSign[] = 
{"","正","二","三","四","五","六","七","八","九","十","冬","腊",0x00};
// 月份码(英文－全大写)
const char *MonthSignENG[] = 
{"","JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC",0x00};
// 月份码(英文－首字母大写)
const char *MonthSignEng[] = 
{"","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec",0x00};
// 24节气表
const char *SolarTerms[] =
{"小寒","大寒","立春","雨水","惊蛰","春分","清明","谷雨","立夏","小满","芒种","夏至","小暑","大暑","立秋","处暑","白露","秋分","寒霜","霜降","立冬","小雪","大雪","冬至",0x00};

// 农历节日表
const char *LunarFestival [] =
{
	"01 00 除夕",	// 00含特殊处理
	"01 01 春节",
	"01 15 元宵节",
	"05 05 端午节",
	"07 07 七夕节",
//	"07 15 中元节",
	"08 15 中秋节",
	"09 09 重阳节",
	"12 08 腊八节",
	"12 24 小年",
	0x00
};
// 公历节日表
const char *SolarFestival [] =
{
	"01 01 元旦",
	"02 14 情人节",
	"03 08 妇女节",
	"03 12 植树节",
	"04 01 愚人节",
	"05 01 劳动节",
	"05 04 青年节",
//	"05 12 护士节",
	"06 01 儿童节",
	"07 01 建党节",
	"08 01 建军节",
	"09 10 教师节",
	"10 01 国庆节",
	"12 25 圣诞节",
	0x00
};
// 特殊节日表(某月的第几个星期几)
const char *SpecialFestival [] =
{
	"05 2 0 母亲节",
	"06 3 0 父亲节",
	0x00
};

char CCalendar::Conv(short m,short x)	
{
	for(short i=1;i<m;i++)
		x -= SMonthDays[i];
	return char(x);   
}

bool CCalendar::isWeekEnd(stDate Date)
{
	short Weekday = getWeekday(Date);
	return (Weekday == 0 || Weekday == 6);
}

bool CCalendar::isAdjustDay(stDate Date)
{
	return (m_mapInstrumentAD.find(Date.toInt()) != m_mapInstrumentAD.end());
}

short CCalendar::isDeliveryDay(stDate Date)
{
	if (m_mapInstrumentDD1.find(Date.toInt()) != m_mapInstrumentDD1.end())
		return 1;
	else if (m_mapInstrumentDD2.find(Date.toInt()) != m_mapInstrumentDD2.end())
		return 2;
	else if (m_mapInstrumentDD3.find(Date.toInt()) != m_mapInstrumentDD3.end())
		return 3;
	else if (m_mapInstrumentDD4.find(Date.toInt()) != m_mapInstrumentDD4.end())
		return 4;
	else if (m_mapInstrumentDD5.find(Date.toInt()) != m_mapInstrumentDD5.end())
		return 5;
	return 0;
}

short CCalendar::isSolar(stDate Date)
{
	short Y = Date.Year;
	short M = Date.Month;
	short D = Date.Day;
	short R = 1;

	if (Y < CALENDAR_YEAR_START || Y > CALENDAR_YEAR_END)
	{
		R = -1;
	}
	else if (M <1 || M >12)
	{
		R = 0;
	}
	else
	{
		SMonthDays[2] = 28 + LEAP_YEAR( Y );
		if ( D <1 || D >SMonthDays[M])
			R = 0;
	}
	if ( DayOffset(Date) < DayOffset(stDateS))
	{
		R = -1;
	}
	return R;
}

short CCalendar::isLunar(stDate Date)
{
	short Y = Date.Year;
	short M = Date.Month;
	short D = Date.Day;
	short R = 1;

	if (Y < CALENDAR_YEAR_START || Y >CALENDAR_YEAR_END)
	{
		R = -1;
	}
	else if (M <=0 || M >12)
	{
		R = 0;
	}

	stLunarYear *pstLYear = & stLYear[Y - CALENDAR_YEAR_START];
	if ((M < 0 ? (-M == pstLYear->LeapMonth ? 29+(pstLYear->Offset[0] <0) : 0) : 29+(pstLYear->Offset[M] <0)) < D )
		R = 0;

	return R;
}

void CCalendar::InitFestivals(void)
{
	InitSolarFestivals();
	InitLunarFestivals();
	InitSpecialFestivals();
}

void CCalendar::InitLunarFestivals(void)
{
	///构造 1900-2100 年的农历节日
	for (short Y = CALENDAR_YEAR_TERMS; Y <CALENDAR_YEAR_END; Y++)
	{
		for (short i = 0; LunarFestival[i] != '\0'; i ++)
		{
			char *p = (char *)LunarFestival[i];
			if (atoi(p+3) == 0)
			{
				/// 特殊日期
				stDate LunarDate(Y, atoi(p), 1);
				stDate LunarDateL = getDayRelativeL(LunarDate, -1);
				m_mapLunarFestival[LunarDateL.toInt()] = i;
			}
			else
				m_mapLunarFestival[(int)(Y*10000 + atoi(p) * 100 + atoi(p+3))] = i;
		}
	}
}

void CCalendar::InitSolarFestivals(void)
{
	///构造 1900-2100 年的公历节日
	for (short Y = CALENDAR_YEAR_TERMS; Y <CALENDAR_YEAR_END; Y++)
	{
		for (short i = 0; SolarFestival[i] != '\0'; i ++)
		{
			char *p = (char *)SolarFestival[i];
			m_mapSolarFestival[(int)(Y*10000 + atoi(p) * 100 + atoi(p+3))] = i;
		}
	}
}

void CCalendar::InitSpecialFestivals(void)
{
	///构造 1900-2100 年的特殊节日
	for (short Y = CALENDAR_YEAR_TERMS; Y <=CALENDAR_YEAR_END; Y++)
	{
		for (short i = 0; SpecialFestival[i] != '\0'; i ++)
		{
			char *p = (char *)SpecialFestival[i];
			short M = (short) atoi(p);
			short N = (short) atoi(p +3);
			short X = (short) atoi(p +5);
			stDate Date = getDayBySpecial(Y, M, N, X);
			m_mapSpecialFestival[Date.toInt()] = i;
		}
	}
}

void CCalendar::InitHoliday(void)
{
	m_listHoliday.sort();
}

void CCalendar::InitInstrument(void)
{
	InitInstrumentType();
	InitInstrumentDate();
}

void CCalendar::InitInstrumentType(void)
{
	/// 品种属性包括：
	/// [1] 最后交易日类型 1表示月中；2表示月末
	/// [2] 自然人持仓清零 1表示最后交易日当天；2表示最后交易日前3天
	/// [3] 交割日类型 1表示交割日为最后交易日后的连续五个工作日
	m_listInstrument.push_back(CBasicInstrumentType("fu", 2, 1, 1));                        
	m_listInstrument.push_back(CBasicInstrumentType("cu", 1, 1, 1));                        
	m_listInstrument.push_back(CBasicInstrumentType("pb", 1, 1, 1));                        
	m_listInstrument.push_back(CBasicInstrumentType("ru", 1, 1, 1));                        
	m_listInstrument.push_back(CBasicInstrumentType("wr", 1, 2, 1));                        
	m_listInstrument.push_back(CBasicInstrumentType("rb", 1, 2, 1));                        
	m_listInstrument.push_back(CBasicInstrumentType("zn", 1, 1, 1));                        
	m_listInstrument.push_back(CBasicInstrumentType("al", 1, 1, 1));                        
	m_listInstrument.push_back(CBasicInstrumentType("au", 1, 1, 1));
}

void CCalendar::InitInstrumentDate(void)
{
	for (short Y = 2010; Y < 2020; Y ++)
	{
		for (short M = 1; M <= 12; M ++)
		{
			/// 构造品种合约
			list<CBasicInstrumentType>::iterator listIt = m_listInstrument.begin();
			for (; listIt != m_listInstrument.end(); listIt ++)
			{
				CBasicInstrumentType & InstrumentType = *listIt;
				char szTmp[16];
				/// 构造合约ID
				sprintf(szTmp, "%s%02d%02d", InstrumentType.m_TypeName.c_str(), Y%100, M);
				stDate LTDate, ADate, DDate1, DDate2, DDate3, DDate4, DDate5;
				if (InstrumentType.m_LDayType == 1)
				{
					/// 月中的最后交易日
					LTDate = getMiddleTDay(Y, M);
				}
				else 
				{
					/// 月末的最后交易日
					LTDate = getLastTDay(Y, M);
				}

				if (InstrumentType.m_ADayType == 1)
				{
					///自然人持仓清零日为最后交易日当天；2表示最后交易日前3天 
					ADate = LTDate;
				}
				else
				{
					///自然人持仓清零日为最后交易日往前3个交易日
					ADate = getTDayRelative(LTDate, -3);
				}

				if (InstrumentType.m_DDayType == 1)
				{
					DDate1 = getTDayRelative(LTDate, 1);
					DDate2 = getTDayRelative(LTDate, 2);
					DDate3 = getTDayRelative(LTDate, 3);
					DDate4 = getTDayRelative(LTDate, 4);
					DDate5 = getTDayRelative(LTDate, 5);
				}
				SAFE_ADD_DATE_LIST(m_mapInstrumentLTD, LTDate.toInt(), szTmp);
				SAFE_ADD_DATE_LIST(m_mapInstrumentAD,   ADate.toInt(), szTmp);
				SAFE_ADD_DATE_LIST(m_mapInstrumentDD1, DDate1.toInt(), szTmp);
				SAFE_ADD_DATE_LIST(m_mapInstrumentDD2, DDate2.toInt(), szTmp);
				SAFE_ADD_DATE_LIST(m_mapInstrumentDD3, DDate3.toInt(), szTmp);
				SAFE_ADD_DATE_LIST(m_mapInstrumentDD4, DDate4.toInt(), szTmp);
				SAFE_ADD_DATE_LIST(m_mapInstrumentDD5, DDate5.toInt(), szTmp);
			}
		}
	}
}

void CCalendar::InitCalendar(void)
{
	///构造 1900-2100 年的日历结构数据
	for (short Y = CALENDAR_YEAR_TERMS; Y <CALENDAR_YEAR_END; Y++)
	{
		SMonthDays[2] = 28 + LEAP_YEAR(Y);
		for (short M = 1; M <= 12; M ++)
		{
			vector <CHybirdDate> vec_Calender;
			for (short D = 1; D <= SMonthDays[M]; D ++)
			{
				///遍历生成的具体日期
				stDate SolarDate(Y, M, D);
				stDate LunarDate = getLunar(SolarDate);
				int SYMD = SolarDate.toInt();
				int LYMD = LunarDate.toInt();

				short Weekday = getWeekday(SolarDate);
				map <int, short>::iterator mapIt;
				mapIt = m_mapSolarTerms.find(SYMD);
				short Term = (mapIt != m_mapSolarTerms.end()) ? mapIt->second : -1;
				mapIt = m_mapSolarFestival.find(SYMD);
				short SFestival = (mapIt != m_mapSolarFestival.end()) ? mapIt->second : -1;
				mapIt = m_mapLunarFestival.find(LYMD);
				short LFestival = (mapIt != m_mapLunarFestival.end()) ? mapIt->second : -1;
				mapIt = m_mapSpecialFestival.find(SYMD);
				short SPFestival = (mapIt != m_mapSpecialFestival.end()) ? mapIt->second : -1;
				int iDateType = DTM_NORMAL;
				switch (Weekday)
				{
				case 0:
					iDateType |= DTM_SUNDAY;
					break;
				case 1:
					iDateType |= DTM_MONDAY;
					break;
				case 2:
					iDateType |= DTM_TUESDAY;
					break;
				case 3:
					iDateType |= DTM_WEDNESDAY;
					break;
				case 4:
					iDateType |= DTM_THURSDAY;
					break;
				case 5:
					iDateType |= DTM_FRIDAY;
					break;
				case 6:
					iDateType |= DTM_SATURDAY;
					break;
				}
				/// 仅初始化 2000－2030 年的交易日信息
				if (Y > 2000 && Y < 2030)
				{
					if (isHoliday(SolarDate))
					{
						iDateType |= DTM_HOLIDAY;
						iDateType |= DTM_CLOSE;	
					}
					else
					{
						if (isWeekEnd(SolarDate))
							iDateType |= DTM_CLOSE;
						else
							iDateType |= DTM_TRADE;
					}
				}
				vec_Calender.push_back(CHybirdDate(SolarDate, LunarDate, Weekday, Term, SFestival, LFestival, SPFestival, iDateType));
			}
			int YM = Y * 100 + M;
			m_mapCalendar[YM] = vec_Calender;
		}
	}
}

void CCalendar::InitWorkCalendarList(int YM)
{
	vector <CHybirdDate> & Vec = m_mapCalendar[YM];
	vector < list <int> > Vec_Work;
	for (int i = 0; i < Vec.size(); i ++)
	{
		list <int> tmpList;
		Vec_Work.push_back(tmpList);
	}
	m_mapWorkCalendar.insert(make_pair(YM,  Vec_Work));
}

void CCalendar::InitWorkCalendar(void)
{
	m_mapWorkCalendar.clear();
	time_t lTime = time(NULL);
	struct tm sTime;
	LocalTime(&lTime, &sTime);
	m_InitDate.Year = sTime.tm_year + 1900;
	m_InitDate.Month = sTime.tm_mon + 1;
	m_InitDate.Day = sTime.tm_mday;

	int YM, YML, YMR;
	YM  = (sTime.tm_year + 1900) * 100 + (sTime.tm_mon +1);
	YML = (sTime.tm_mon+1 == 1)  ? ((sTime.tm_year + 1900 -1) * 100 + 12) : (sTime.tm_year + 1900) * 100 + (sTime.tm_mon);
	YMR = (sTime.tm_mon+1 == 12) ? ((sTime.tm_year + 1900 +1) * 100 + 1)  : (sTime.tm_year + 1900) * 100 + (sTime.tm_mon +2);
	
	InitWorkCalendarList(YML);
	InitWorkCalendarList(YM);
	InitWorkCalendarList(YMR);
}

void CCalendar::InitSolarTerms(void)
{
	///仅构造 1900-2100年的节气信息
	for (int i =CALENDAR_YEAR_TERMS; i <CALENDAR_YEAR_END; i++)
	{
		for (int j = 0; j <24; j++)
		{
			/// 算法如下：
			/// 把当天和1900年1月0日（星期日）的差称为积日，那么第y年（1900年算第0年）第x 个节气的积日是
			///	F = 365.242 * y + 6.2 + 15.22 * x - 1.9 * sin(0.262 * x)
			/// F 计算得到的误差在0.05左右
			float fDayOffset = 365.242 * (i - CALENDAR_YEAR_TERMS) + 6.2 + 15.22 * j - 1.9 * sin(0.262 * j);
			int iDayOffset = (int)(fDayOffset) - 1;		/// 忽略误差，距离1900年1月1日的积日
			long lOffset = DayOffset(stDate(CALENDAR_YEAR_TERMS,1,1)) + iDayOffset;
			stDate Date = getDayByOffset(lOffset);
			int SYMD = Date.toInt();
			m_mapSolarTerms[SYMD] = j;
		}
	}
}

void CCalendar::InitLunarYear(void)
{    
	short i, r, t;
	short iLeap = stLYear[0].LeapMonth;
	for (r = 1; r <= 110; r ++)
	{
		if (r%5 == 1)
		{
			t =  LeapMonthGap[r/5];
		}
		iLeap += 29 + t%8;
		t >>= 3;
		stLYear[(iLeap -r)/12].LeapMonth = (iLeap - r)%12;
	}
	stLunarYear *pstLYear = & stLYear[0];
	r = pstLYear->LeapMonth;
	for (t=0,i=0; LMonthDays[i] != '\0'; i+=2,t++)
	{
		LMonthDays[t] = 16*VAL(LMonthDays[i]) + VAL(LMonthDays[i+1]); 
	}

	short M;
	short Y = CALENDAR_YEAR_START;
	short D = 25;
	for (M = 1, i = 0; i < 3723; i++, M++)
	{
		if (M >12+!!r)
		{
			M = 1;
			D -= 365 + LEAP_YEAR(Y);
			Y++;
			r = (++pstLYear)->LeapMonth;
		}
		t = LMonthDays[i/8];
		t >>= i%8;
		SMonthDays[2] = 28 + LEAP_YEAR(Y);
		if (r ==0 || M <= r)
		{
			pstLYear->Offset[M] = Conv(M, D);
			if (t %2)
				pstLYear->Offset[M] |= 0x80;
		}
		else if (M >1+r)
		{
			pstLYear->Offset[M-1] = Conv(M-1, D);
			if (t %2)
				pstLYear->Offset[M-1] |= 0x80;
		}
		else
		{
			pstLYear->Offset[0] = Conv(r, D);
			if (t %2)
				pstLYear->Offset[0] |= 0x80;
		}
		D += 29 + t%2;
	}
}

void CCalendar::AddHoliday(const char *pDate)
{
		if (find(m_listHoliday.begin(), m_listHoliday.end(), stDate(pDate).toInt()) == m_listHoliday.end())
		{
			m_listHoliday.push_back(stDate(pDate).toInt());
			m_InitFlag = false; /// 可再次调用初始化	
		}
}

void CCalendar::addDateDefine(int iID, char *pDefine)
{
	CDateTypeDefine DTD;
	if (DTD.LoadDTD(pDefine));
	{
		/// 向工作表中添加每天工作的日期定义项
		list <int> & List_Month = DTD.m_Months;
		list <int> & List_Numbers = DTD.m_Numbers;
		int iDateType = GET_DT_MASK(DTD.m_DateType);
		list <int>::iterator List_Month_It;
		list <int>::iterator List_Numbers_It;

		
		if (find(List_Month.begin(), List_Month.end(), 0) != List_Month.end())
		{
			List_Month.clear();
			for (int i = 1; i <=12; i++)
			{
				List_Month.push_back(i);
			}
		}

		if (find(List_Numbers.begin(), List_Numbers.end(), 0)!= List_Numbers.end())
		{
			List_Numbers.clear();
			for (int i = 1; i <=31; i++)
			{
				List_Numbers.push_back(i);
			}
		}

		/// 遍历月份
		for (List_Month_It = List_Month.begin(); List_Month_It != List_Month.end(); List_Month_It++)
		{
			/// 找到当月日历信息
			int YM = m_InitDate.Year *100 + *(List_Month_It);
			map<int, vector< list<int> > > ::iterator Map_It = m_mapWorkCalendar.find(YM);
			/// 是否需要具化成工作信息
			if (Map_It != m_mapWorkCalendar.end())
			{
				vector<CHybirdDate> & Vec = getCalendar(YM);
				/// 遍历数码
				for (List_Numbers_It = List_Numbers.begin(); List_Numbers_It != List_Numbers.end(); List_Numbers_It++)
				{
					int iNum = *(List_Numbers_It);
					int iPos = findDay(Vec, iNum, iDateType);
					if (iPos < 0)
					{
						/// 找不到，后续同样无法找到
						break;
					}
					else
					{
						/// 找到了目标对象日的位置，更新工作日历表
						vector< list<int> > & Vec_Work = Map_It->second;
						list<int> & List = Vec_Work[iPos];
						List.push_back(iID);
					}
				}
			}
		}
	}
}

int CCalendar::findDay(vector<CHybirdDate> & Vec, int iNum, int iDateType)
{
	vector<CHybirdDate>::iterator Vec_It = Vec.begin();
	int iCount = 0, iPos = -1;
	for (int i = 0; Vec_It != Vec.end(); i++, Vec_It++)
	{
		CHybirdDate & Date = (*Vec_It);
		if (Date.isDateType(iDateType))
		{
			iCount ++;
			iPos = i;
			if (iCount == iNum)
			{
				/// 找到了，返回当前位移
				return iPos;
			}
		}
	}
	if (iNum == 99)
		return iPos;
	return -1;
}

list <int> & CCalendar::getDateTypeList(short Year, short Month, short Day)
{
	int YM = Year * 100 + Month;
	map<int, vector< list<int> > > ::iterator Map_It = m_mapWorkCalendar.find(YM);
	/// 是否包含具化成工作信息
	if (Map_It != m_mapWorkCalendar.end())
	{
		vector< list<int> > & Vec_Work = Map_It->second;
		vector< list<int> >::iterator Veck_Work_It = Vec_Work.begin();
		for (int i = 0; i <Day-1; i++,Veck_Work_It++)
		{
			/// just move
		}
		return (*Veck_Work_It);
	}
	return m_listEmpty;
}

stDate CCalendar::getSolar(stDate Date)
{
	short iM, M;
	iM = Date.Month;
	M = iM;
	if (iM <0)
	{
		M = -iM;
		iM = 0;
	}
	stLunarYear * pstLYear = & stLYear[Date.Year - CALENDAR_YEAR_START];
	stDate date;
	date.Year = Date.Year;
	date.Day = (0x7f & pstLYear->Offset[iM])-1 +Date.Day;
	SMonthDays[2] = 28 + LEAP_YEAR(date.Year);
	while (date.Day > SMonthDays[M])
	{
		date.Day -= SMonthDays[M];
		M = M%12 +1;
		if (M == 1)
			date.Year ++;
	}
	date.Month = M;
	return date;
}

stDate CCalendar::getLunar(stDate Date)
{
	stLunarYear *pstLYear = & stLYear[Date.Year - CALENDAR_YEAR_START];
	SMonthDays[2] = 28 + LEAP_YEAR(Date.Year);
	short M = Date.Month;
	Date.Day -= (pstLYear->Offset[M] & 0x7f) -1;
	while (Date.Day < 1)
	{
		if (M == 0)
			M = pstLYear->LeapMonth;
		else if (M == 1)
		{
			M = 12;
			Date.Year --;
			pstLYear --;
		}
		else if (pstLYear->LeapMonth == M-1)
			M = 0;
		else
			M --;
		Date.Day += 29 + (pstLYear->Offset[M] < 0);
	}
	if (M ==0)
		M = -(pstLYear->LeapMonth);		// 闰月时则将月份标识为负值
	Date.Month = M;
	return Date;
}

long CCalendar::DayOffset(stDate Date)
{
	SMonthDays[2] = 28 + LEAP_YEAR(Date.Year);
	long C, X = Date.Year -1;
	short M;
	for (C = Date.Day, M =1; M <Date.Month; M ++)
		C += SMonthDays[M];
	return 365*X + X/4 - X/100 + X/400 + C;
}

stDate CCalendar::getDayByOffset(long Offset)
{
	short Y = 1, M = 1, D = 1;
	long Days = Offset;

	while (Days > (365 + LEAP_YEAR(Y)))
	{
		Days -= (365 + LEAP_YEAR(Y));
		Y ++;
	}
	SMonthDays[2] = 28 + LEAP_YEAR(Y);
	for (M =1; Days >SMonthDays[M]; M++)
	{
		Days -= SMonthDays[M];
	}
	D = Days;
	return stDate(Y, M, D);
}

/// 内部函数，程序保证其输入有效性，不做多余校验
stDate CCalendar::getDayBySpecial(short Y, short M, short N, short X)
{
	int iCount = 0;
	SMonthDays[2] = 28 + LEAP_YEAR(Y);
	for (short D = 1; D < SMonthDays[M]; D ++)
	{
		stDate Date(Y, M, D);
		if (getWeekday(Date) == X)
		{
			iCount ++;
			if (iCount == N)
				return Date;
		}
	}
	return stDate(Y, M, SMonthDays[M]);
}

stDate CCalendar::getDayRelative(stDate Date, long Offset)
{
	long lOffset = DayOffset(Date);
	lOffset += Offset;
	return lOffset > 0 ? getDayByOffset(lOffset) : Date;
}

stDate CCalendar::getTDayRelative(stDate Date, long Offset)
{
	stDate rDate = Date;
	if (Offset > 0)
	{
		for (long i = 0; i < Offset;)
		{
			rDate = getDayRelative(rDate, 1);
			if (isTradingDay(rDate))
				i++;
		}
	}
	else if (Offset == 0)
	{
		if (!isTradingDay(rDate))
			return getTDayRelative(rDate, 1);
	}
	else
	{
		for (long i = 0; i > Offset;)
		{
			rDate = getDayRelative(rDate, -1);
			if (isTradingDay(rDate))
				i--;
		}
	}
	return rDate;
}

stDate CCalendar::getFirstTDay(short Y, short M)
{
	return getTDayRelative(stDate(Y, M, 1), 0);
}

stDate CCalendar::getMiddleTDay(short Y, short M)
{
	return getTDayRelative(stDate(Y, M, 15), 0);
}

stDate CCalendar::getLastTDay(short Y, short M)
{
	SMonthDays[2] = 28 + LEAP_YEAR(Y);
	stDate Date(Y, M, SMonthDays[M]);
	if (isTradingDay(Date))
	{
		return Date;
	}
	else
	{
		return getTDayRelative(Date, -1);
	}
}

stDate CCalendar::getDayRelativeL(stDate Date, long Offset)
{
	stDate SolarDate = getSolar(Date);
	long lOffset = DayOffset(SolarDate);
	lOffset += Offset;
	stDate SolarDateR = getDayByOffset(lOffset);
	return getLunar(SolarDateR);
}

short CCalendar::getWeekday(stDate Date)
{
	return DayOffset(Date) %7;
}

short CCalendar::getChineseEra(short Year, short Flag)
{
	if (Flag == 0)
		return ((Year - 4)% 60) % 10;
	else
		return ((Year - 4)% 60) % 12;
}

const char * CCalendar::getTianGan(stDate Date)
{
	return TianGan[getChineseEra(Date.Year, 0)];
}

const char * CCalendar::getDiZhi(stDate Date)
{
	return DiZhi[getChineseEra(Date.Year, 1)];
}

const char * CCalendar::getZodiacSymbols(stDate Date)
{
	return ZodiacSymbols[getChineseEra(Date.Year, 1)];
}

const char * CCalendar::getWeekdaySign(stDate Date, short Flag)
{
	if (Flag == 1)
		return DaySignENG[getWeekday(Date)];
	else if (Flag == 2)
		return DaySignEng[getWeekday(Date)];
	else 
		return DaySign[getWeekday(Date)];
}

const char * CCalendar::getDaySign(stDate Date, short Flag)
{
	const char szDay[16] = "";
	memset((void *)szDay, 0x00, sizeof(szDay));
	if (Flag == 1)
	{
		sprintf((char *)szDay, "%d", Date.Day);
	}
	else 
	{
		//strcat((char *)szDay, (char *)DayPreSign[(Date.Day-1)/10]);
		//strcat((char *)szDay, (char *)DaySign[((Date.Day-1)%10+1)]);
		sprintf((char *)szDay, "%s%s", (char *)DayPreSign[(Date.Day-1)/10], (char *)DaySign[((Date.Day-1)%10+1)]);
	}
	return szDay;
}

const char * CCalendar::getMonthSign(stDate Date, short Flag)
{
	const char szMonth[16] = "";
	memset((void *)szMonth, 0x00, sizeof(szMonth));
	if (Flag == 1)
		return MonthSignENG[abs(Date.Month)];
	else if (Flag == 2)
		return MonthSignEng[abs(Date.Month)];
	else 
	{
		if (Date.Month < 0)
		{
			//strcat((char *)szMonth, "闰");		// 闰月时添加文字标识
			//strcat((char *)szMonth, (char *)MonthSign[abs(Date.Month)]);
			sprintf((char *)szMonth, "闰%s", (char *)MonthSign[abs(Date.Month)]);	
			return szMonth;
		}
		else
		{
			return MonthSign[Date.Month];
		}
	}
}

vector<CHybirdDate> & CCalendar::getCalendar(short Year, short Month)
{
	return getCalendar(Year *100 + Month);
}

vector<CHybirdDate> & CCalendar::getCalendar(int YM)
{
	vector <CHybirdDate> & MonthCalendar = m_mapCalendar[YM];
	RefreshMonthCalendar(MonthCalendar);
	return MonthCalendar;
}

vector<CHybirdDate>::iterator CCalendar::getCalendarDay(stDate SolarDate)
{
	int YM = SolarDate.Year * 100 + SolarDate.Month;
	vector <CHybirdDate>::iterator vecIt = m_mapCalendar[YM].begin();
	vecIt += (SolarDate.Day -1);
	return vecIt;
}

CHybirdDate & CCalendar::getHybirdDate(short Year, short Month, short Day)
{
	vector<CHybirdDate> & vet_Calendar = getCalendar(Year, Month);
	return vet_Calendar[(Day-1)];
}

void CCalendar::checkDeliveryDay(vector <CHybirdDate> & vec_Calendar, vector<CHybirdDate>::iterator vecIt)
{
	if ((*vecIt).isDateType(DTM_CLOSE))
		return;

	stDate & SolarDate = (*vecIt).m_SolarDate;
	short DeliveryDay = isDeliveryDay(SolarDate);
	switch (DeliveryDay)
	{
	case 0:
		break;
	case 1:
		(*vecIt).setDateType(DTM_DELIVERY);
		(*vecIt).setDateType(DTM_DELIVERY1);
		break;
	case 2:
		(*vecIt).setDateType(DTM_DELIVERY);
		(*vecIt).setDateType(DTM_DELIVERY2);
		break;
	case 3:
		(*vecIt).setDateType(DTM_DELIVERY);
		(*vecIt).setDateType(DTM_DELIVERY3);
		break;
	case 4:
		(*vecIt).setDateType(DTM_DELIVERY);
		(*vecIt).setDateType(DTM_DELIVERY4);
		break;
	case 5:
		(*vecIt).setDateType(DTM_DELIVERY);
		(*vecIt).setDateType(DTM_DELIVERY5);
		break;
	}
}

void CCalendar::checkAdjustDay(vector <CHybirdDate> & vec_Calendar, vector<CHybirdDate>::iterator vecIt)
{
	if ((*vecIt).isDateType(DTM_CLOSE))
		return;

	stDate & SolarDate = (*vecIt).m_SolarDate;
	if (isAdjustDay(SolarDate))
		(*vecIt).setDateType(DTM_ADJUSTDAY);
}

void CCalendar::checkHolidayDay(vector <CHybirdDate> & vec_Calendar, vector<CHybirdDate>::iterator vecIt)
{
	stDate & SolarDate = (*vecIt).m_SolarDate;
	
	vector<CHybirdDate>::iterator vecItObj;
		
	if ((*vecIt).isDateType(DTM_HOLIDAY))
	{
		/// 当天为国定休市日
		stDate LDate = getTDayRelative(SolarDate, -1);	//前一交易日
		stDate RDate = getTDayRelative(SolarDate, 1);		//后一交易日
		vecItObj = getCalendarDay(LDate);
		(*vecItObj).setDateType(DTM_NOCONTINUOUS);		//设置当日夜间无连续交易
		(*vecItObj).setDateType(DTM_BEFOREHOLIDAY);		//设置当日为假期前一交易日
		vecItObj = getCalendarDay(getDayRelative(LDate, 1));
		(*vecItObj).setDateType(DTM_HOLIDAYH);			//设置当日为休息日首部
		vecItObj = getCalendarDay(RDate);
		(*vecItObj).setDateType(DTM_NONIGHTTRADE);			//设置当日不含夜盘部分
		(*vecItObj).setDateType(DTM_AFTERHOLIDAY);			//设置当日为假期后一交易日
		vecItObj = getCalendarDay(getDayRelative(RDate, -1));
		(*vecItObj).setDateType(DTM_HOLIDAYT);			//设置当日为休息日尾部		
	}
}

void CCalendar::RefreshMonthCalendar(vector <CHybirdDate> & vec_Calendar)
{
	vector<CHybirdDate>::iterator vecIt;
	for (vecIt = vec_Calendar.begin(); vecIt != vec_Calendar.end(); vecIt++)
	{
		/// 是否为国定休市日
		checkHolidayDay(vec_Calendar, vecIt);
		/// 是否为自然人持仓清0日
		checkAdjustDay(vec_Calendar, vecIt);
		/// 是否为交割日
		checkDeliveryDay(vec_Calendar, vecIt);
	}
}

/// 初始化数据
void CCalendar::Init()
{
	/// Added by Henchi, 20140409
	/// 用于避免重复的初始化操作
	if (m_InitFlag == true)
		return ;
		
	InitHoliday();
	InitLunarYear();
	InitSolarTerms();
	InitFestivals();
	InitInstrument();
	InitCalendar();
	InitWorkCalendar();

	time_t datetime;
	datetime = time(NULL);
	struct tm dt;
	LocalTime(&datetime, &dt);
	int Year = (dt).tm_year + 1900;

	/// 刷新今明两年的交易业务信息
	for (int i = 0; i <=1; i++)
	{
		for (int j = 1; j <=12; j++)
		{
			getCalendar(Year + i, j);	
		}		
	}
	
	m_InitFlag = true;
}

//[公历算法] 判断日期是否为交易日
///@param	Date	需要的判断的日期
///@return	返回判断结果，true为交易日;false为非交易日
bool CCalendar::isTradingDay(stDate Date)
{
	static stDate OldDate;
	static bool Result = false;
	/// 避免频繁重复计算同一日期的性能过度损耗
	if (OldDate != Date)
	{
		Result = !isWeekEnd(Date) && !isHoliday(Date);
		OldDate = Date;
	}

	return Result;
}

//YYYYMMDD
bool CCalendar::isTradingDay(string datestr)
{
	return isTradingDay(stDate(datestr.c_str()));
}

//YYYYMMDD
bool CCalendar::isTradingDay(const char * pDate)
{
	return isTradingDay(stDate(pDate));
}

//YYYY,MM,DD
bool CCalendar::isTradingDay(short year, short month, short day)
{
	return isTradingDay(stDate(year, month, day));
}

//[公历算法] 判断日期是否为国定休市日
///@param	Date	需要的判断的日期
///@return	返回判断结果，true为国定休市日;false为国定休市日
bool CCalendar::isHoliday(stDate Date)
{
	return std::find(m_listHoliday.begin(), m_listHoliday.end(), Date.toInt()) != m_listHoliday.end();
}

//YYYYMMDD
bool CCalendar::isHoliday(string datestr)
{
	return isHoliday(stDate(datestr.c_str()));
}

//YYYYMMDD
bool CCalendar::isHoliday(const char *pDate)
{
	return isHoliday(stDate(pDate));
}

//YYYY,MM,DD
bool CCalendar::isHoliday(short year, short month, short day)
{
	return isHoliday(stDate(year, month, day));
}

//[公历算法] 判断日期是否为非连续交易日（当日晚间无夜盘）
///@param	Date	需要的判断的日期
///@return	返回判断结果，true为非连续交易日;false为其它日
bool CCalendar::isContinuousDay(stDate Date)
{
	return isTradingDay(Date) && !isNoContinuousDay(Date);
}

//[公历算法] 判断日期的前一天是否为连续交易日
///@param	Date	需要的判断的日期
///@return	返回判断结果，true为真;false为假
bool CCalendar::AfterContinuousDay(stDate Date)
{
	static stDate OldDate;
	static bool Result = false;
	/// 避免频繁重复计算同一日期的性能过度损耗
	if (OldDate != Date)
	{
		Result = isContinuousDay(getDayRelative(Date, -1));
		OldDate = Date;
	}

	return Result;
}

//[公历算法] 判断日期是否为非连续交易日（当日晚间无夜盘）
///@param	Date	需要的判断的日期
///@return	返回判断结果，true为非连续交易日;false为其它日
bool CCalendar::isNoContinuousDay(stDate Date)
{
	return checkDateType(Date, DTM_NOCONTINUOUS);
}

//[公历算法] 判断日期是否为不含夜盘交易日（该交易日无夜盘部分）
///@param	Date	需要的判断的日期
///@return	返回判断结果，true为非连续交易日;false为其它日
bool CCalendar::isNoNightTradingDay(stDate Date)
{
	return checkDateType(Date, DTM_NONIGHTTRADE);
}

//[公历算法] 判断日期类型是否为目标类型
///@param	Date	需要的判断的日期
///@return	返回判断结果，true为匹配;false为不匹配
bool CCalendar::checkDateType(stDate Date, DATE_TYPE_MASK iDateType)
{
	if (isSolar(Date))
	{
		vector<CHybirdDate>::iterator vecIt = getCalendarDay(Date);	
		return (*vecIt).isDateType(iDateType);
	}
	else
		return false;
}

void CCalendar::showCalendar(short Year, short Month)
{
	vector<CHybirdDate> & vec_Calendar = getCalendar(Year, Month);
	vector<CHybirdDate>::iterator vecIt;
	for (vecIt = vec_Calendar.begin(); vecIt != vec_Calendar.end(); vecIt++)
	{
		showHybirdDate(*vecIt);
	}
}

void CCalendar::showHybirdDate(CHybirdDate Date)
{
	printf("[%04d-%02d-%02d] [%s%s%s年%s%s月%s%s] [星期%s] [%s] %s %s %s %s\n",
		Date.m_SolarDate.Year, Date.m_SolarDate.Month, Date.m_SolarDate.Day, 
		getTianGan(Date.m_LunarDate),
		getDiZhi(Date.m_LunarDate),
		getZodiacSymbols(Date.m_LunarDate),
		Date.m_LunarDate.Month < 0 ? "闰" : "",
		(char *)MonthSign[abs(Date.m_LunarDate.Month)],
		(char *)DayPreSign[(Date.m_LunarDate.Day-1)/10], (char *)DaySign[((Date.m_LunarDate.Day-1)%10+1)],
		DaySign[Date.m_Weekday],
//		Date.isDateType(DTM_TRADE) ? "+": "-",
		Date.isDateType(DTM_TRADE) ? (Date.isDateType(DTM_NOCONTINUOUS) ? "*" : (Date.isDateType(DTM_NONIGHTTRADE) ? "~" : "+" ) ) : (Date.isDateType(DTM_HOLIDAY) ? "/" : "-" ),
		Date.m_Term != -1 ? SolarTerms[Date.m_Term] : "",
		Date.m_SolarFestival != -1 ? SolarFestival[Date.m_SolarFestival] +6: "",
		Date.m_LunarFestival != -1 ? LunarFestival[Date.m_LunarFestival] +6: "",
		Date.m_SpecialFestival != -1 ? SpecialFestival[Date.m_SpecialFestival] +7 : ""
		);

	SHOW_DATE_LIST(m_mapInstrumentAD,   Date.m_SolarDate.toInt(), "    自然人持仓清零");
	SHOW_DATE_LIST(m_mapInstrumentLTD,  Date.m_SolarDate.toInt(), "    最后交易日合约");
	SHOW_DATE_LIST(m_mapInstrumentDD1,  Date.m_SolarDate.toInt(), "    首个交割日合约");
	SHOW_DATE_LIST(m_mapInstrumentDD2,  Date.m_SolarDate.toInt(), "    第二交割日合约");
	SHOW_DATE_LIST(m_mapInstrumentDD3,  Date.m_SolarDate.toInt(), "    第三交割日合约");
	SHOW_DATE_LIST(m_mapInstrumentDD4,  Date.m_SolarDate.toInt(), "    第四交割日合约");
	SHOW_DATE_LIST(m_mapInstrumentDD5,  Date.m_SolarDate.toInt(), "    第五交割日合约");
}

#if 0
int main(int agrc, char *argv[])
{	
	// 创建日历数据对象并初始化
	CCalendar calendar;

	// 添加日期规则
	//calendar.addDateDefine(1, "00;00;00;");
	//calendar.addDateDefine(2, "06,08,10;00;05;");
	//calendar.addDateDefine(3, "07,08,09;02,05;08;");
	//calendar.addDateDefine(4, "07,08,09;02,05;14;");

	// 添加国定休市日
	calendar.AddHoliday("20140101");
	calendar.AddHoliday("20140131");
	calendar.AddHoliday("20140201");
	calendar.AddHoliday("20140202");
	calendar.AddHoliday("20140203");
	calendar.AddHoliday("20140204");
	calendar.AddHoliday("20140205");
	calendar.AddHoliday("20140206");
	calendar.AddHoliday("20140405");
	calendar.AddHoliday("20140406");
	calendar.AddHoliday("20140407");
	calendar.AddHoliday("20140501");
	calendar.AddHoliday("20140502");
	calendar.AddHoliday("20140503");
	calendar.AddHoliday("20140531");
	calendar.AddHoliday("20140601");
	calendar.AddHoliday("20140602");
	calendar.AddHoliday("20140906");
	calendar.AddHoliday("20140907");
	calendar.AddHoliday("20140908");
	calendar.AddHoliday("20141001");
	calendar.AddHoliday("20141002");
	calendar.AddHoliday("20141003");
	calendar.AddHoliday("20141004");
	calendar.AddHoliday("20141005");
	calendar.AddHoliday("20141006");
	calendar.AddHoliday("20141007");
	time_t t_start = time(NULL);
	calendar.Init();
	time_t t_end = time(NULL);
	printf("Init cost [%d] secs\n", t_end - t_start);

	//// 获取指定日期的日期类ID列表
	//list<int> & List = calendar.getDateTypeList(2012, 8, 15);
	//
	//// 获取指定日期的复合信息结构
	//CHybirdDate & HDate = calendar.getHybirdDate(2012,7,4);
	//
	//// 测试关联交易日函数
	//stDate rDate = calendar.getTDayRelative(HDate.m_SolarDate, -5);
	stDate rDate;
	// 测试日历结构的打印
	//for (short Y = 2014; Y <= 2014; Y ++)
	//{
	//	for (short M = 1; M <= 12; M ++)
	//	{
	//		calendar.showCalendar(Y, M);
	//		rDate = calendar.getFirstTDay(Y, M);
	//		printf("FirstTradingDay  [%d]\n", rDate.toInt());
	//		rDate = calendar.getMiddleTDay(Y, M);
	//		printf("MiddleTradingDay [%d]\n", rDate.toInt());
	//		rDate = calendar.getLastTDay(Y, M);
	//		printf("LastTradingDay   [%d]\n", rDate.toInt());
	//	}
	//}

	for (short Y = 2014; Y <= 2014; Y ++)
	{
		for (short M = 1; M <= 12; M ++)
		{
			for (short D = 1; D <=31; D++)
			{
				if (calendar.isHoliday(stDate(Y, M, D)))
					printf("[%04d%02d%02d][/]\n", Y, M, D);
				if (calendar.isNoContinuousDay(stDate(Y, M, D)))
					printf("[%04d%02d%02d][*]\n", Y, M, D);
				if (calendar.isNoNightTradingDay(stDate(Y, M, D)))
					printf("[%04d%02d%02d][~]\n", Y, M, D);
			}
		}
	}

	exit(0);	
}

#endif

