/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CCalendar.h
///@brief	��������ά����ϵͳ���õ�����������
///@history
///20120628	�̺״�	�������ļ�
#include "stdlib.h"
#include "string.h"
/*
    CCalendar �����ʹ������:

	// �����������ݶ��󲢳�ʼ��
	CCalendar calendar;

  // ������ڹ���
	calendar.addDateDefine(1, "00;00;00;");
	calendar.addDateDefine(2, "06,08,10;00;05;");
	calendar.addDateDefine(3, "07,08,09;02,05;08;");
	calendar.addDateDefine(4, "07,08,09;02,05;14;");

	// ��ȡָ�����ڵ�������ID�б�
	list<int> & List = calendar.getDateTypeList(2012, 8, 15);

	// ��ȡָ�����ڵĸ�����Ϣ�ṹ
	CHybirdDate & HDate = calendar.getHybirdDate(2012,7,4);
	
	// ���Թ��������պ���
	stDate rDate = calendar.getTDayRelative(HDate.m_SolarDate, -5);
	
	// ���������ṹ�Ĵ�ӡ
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


�����������Ͷ��崮��˵����
1. �������Ͷ��崮�����������[�·���;����;����������;]��ÿ���ּ���';'���зָ�;
2. �·���ȡֵ��Χ[0~12]��0��ʾÿ�£�1��ʾ1�¡���12��ʾ12�£�ѡ������·�ʱ��ֵ��','�ָ�����[1,3,5];
3. �������ڱ�ʾ��N����ȡֵ��Χ[0~31,99]��0��ʾÿ����1��ʾ�׸�����31��ʾ��31����99��ʾ���һ����ѡ�����ʱͬ����','�ָ���
4. �������������ڱ�ʶ���ڵ����ͣ��ɷ�Ϊ����Ȼ�ա������ա��ǽ����յȣ�ȡֵ��Χ[0~24]������������£�
	DT_NORMAL = 0, 	      ///00:��Ȼ��
	DT_MONDAY,            ///01:��һ
	DT_TUESDAY,           ///02:�ܶ�
	DT_WEDNESDAY,         ///03:����
	DT_THURSDAY,          ///04:����
	DT_FRIDAY,            ///05:����
	DT_SATURDAY,          ///06:����
	DT_SUNDAY,            ///07:����
	DT_CLOSE,             ///08:�ǽ�����
	DT_TRADE,             ///09:������
	DT_ADJUSTDAY,         ///10:��Ȼ�˳ֲ���0��
	DT_DELIVERY1,         ///11:��һ������
	DT_DELIVERY2,         ///12:�ڶ�������
	DT_DELIVERY3,         ///13:����������
	DT_DELIVERY4,         ///14:���Ľ�����
	DT_DELIVERY5,         ///15:���彻����
	DT_DELIVERY,          ///16:������
	DT_NOCONTINUOUS,      ///17:��������������
	DT_NONIGHTTRADE,      ///18:�������ղ���ҹ��
	DT_HOLIDAY,           ///19:����������
	DT_HOLIDAYH,          ///20:������������
	DT_HOLIDAYT,          ///21:����ĩ������
	DT_BEFOREHOLIDAY,     ///22:����ǰ������
	DT_AFTERHOLIDAY       ///23:����������

����:
	00;00;00									��ʾÿ��ÿ����Ȼ��(��ÿ��)
	06,08,10;00;05;						        ��ʾ�·�6��8��10��ÿһ������
    07,08,09;02,05;08;				            ��ʾ�·�7��8��9�ĵ�2�͵�5���ǽ�����
*/

#ifndef REF_CCALENDAR_H
#define REF_CCALENDAR_H
#include "map"
#include "list"
#include "vector"
#include "string"

using namespace std;

#define LEAP_YEAR(y)		!(y % (y%100 ? 4 : 400))		// �������ʽ��Ϊ����ʱ����1������Ϊ0
#define VAL(h)				(h<'a'?(h-'0'):(h-'a'+10))		// ʮ�������ַ�ת����

#define CALENDAR_YEAR_START		1800
#define CALENDAR_YEAR_END			2100
#define CALENDAR_YEAR_TERMS		1900

class CCalendar;

#define GET_DT_MASK(y)		 (int)pow( 2.0, (y-1) )			// ��ȡ����������Ӧ������

enum DATE_TYPE {
	DT_NORMAL = 0, 	      ///00:��Ȼ��
	DT_MONDAY,            ///01:��һ
	DT_TUESDAY,           ///02:�ܶ�
	DT_WEDNESDAY,         ///03:����
	DT_THURSDAY,          ///04:����
	DT_FRIDAY,            ///05:����
	DT_SATURDAY,          ///06:����
	DT_SUNDAY,            ///07:����
	DT_CLOSE,             ///08:�ǽ�����
	DT_TRADE,             ///09:������
	DT_ADJUSTDAY,         ///10:��Ȼ�˳ֲ���0��
	DT_DELIVERY1,         ///11:��һ������
	DT_DELIVERY2,         ///12:�ڶ�������
	DT_DELIVERY3,         ///13:����������
	DT_DELIVERY4,         ///14:���Ľ�����
	DT_DELIVERY5,         ///15:���彻����
	DT_DELIVERY,          ///16:������
	DT_NOCONTINUOUS,      ///17:��������������
	DT_NONIGHTTRADE,      ///18:�������ղ���ҹ��
	DT_HOLIDAY,           ///19:����������
	DT_HOLIDAYH,          ///20:������������
	DT_HOLIDAYT,          ///21:����ĩ������
	DT_BEFOREHOLIDAY,     ///22:����ǰ������
	DT_AFTERHOLIDAY       ///23:����������
};

enum DATE_TYPE_MASK {
	DTM_NORMAL = 0,              ///��Ȼ�� MASK 0x00
	DTM_MONDAY = 1,              ///��һ
	DTM_TUESDAY = 2,             ///�ܶ�
	DTM_WEDNESDAY = 4,           ///����
	DTM_THURSDAY = 8,            ///����
	DTM_FRIDAY = 16,             ///����
	DTM_SATURDAY = 32,           ///����
	DTM_SUNDAY = 64,             ///����
	DTM_CLOSE = 128,             ///�ǽ�����
	DTM_TRADE = 256,             ///������
	DTM_ADJUSTDAY = 512,         ///��Ȼ�˳ֲ���0��
	DTM_DELIVERY1 = 1024,        ///��һ������
	DTM_DELIVERY2 = 2048,        ///�ڶ�������
	DTM_DELIVERY3 = 4096,        ///����������
	DTM_DELIVERY4 = 8192,        ///���Ľ�����
	DTM_DELIVERY5 = 16384,       ///���彻����
	DTM_DELIVERY = 32768,        ///������
	DTM_NOCONTINUOUS = 65536,    ///��������������
	DTM_NONIGHTTRADE = 131072,   ///�������ղ���ҹ��
	DTM_HOLIDAY = 262144,        ///����������
	DTM_HOLIDAYH = 524288,       ///������������
	DTM_HOLIDAYT = 1048576,      ///����ĩ������
	DTM_BEFOREHOLIDAY = 2097152, ///������������ǰ������
	DTM_AFTERHOLIDAY =  4194304  ///�����������պ�����  
};

/// stDate Ϊ������Ϣ����Ԫ�ṹ
class stDate
{
public:
	short Year;		/// ��
	short Month;	/// ��
	short Day;		/// ��

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
		if (pDate != NULL && strlen(pDate) == 8) //��Ҫ���� "YYYYMMDD"
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

/// stLunarYear Ϊũ�������¼��·�ƫ����Ϣ�ṹ��
struct stLunarYear
{
	char LeapMonth;			/// �����·��룬0Ϊ������
	char Offset[13];		/// Offset[i]�б���ũ��i�³�һ��Ӧ����i�µ����ںţ�
	/// ͬʱ����Offset[i]�����λΪ1�������£�0��ʾС��
};

///CBasicInstrumentType �ඨ���˻�����Լ���ͼ����� 
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

	//���ر���������Ӧ��Ŀ������·��µľ��������б���������������YYYYMMDD��ʾ
	///@param	iDateType	Ŀ������������
	///@return	�����жϽ����trueΪ����Ŀ��Ҫ��;falseΪ������Ŀ��Ҫ��
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

///CHybirdDate�ඨ����������ʹ�õĻ��������Ϣ��
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


	//���ö������������
	///@param	iDateType	Ŀ������������
	void setDateType(DATE_TYPE_MASK iDateType)
	{
		m_DateType |= iDateType;
	}


	//У��������������
	///@param	iDateType	Ŀ������������
	///@return	�����жϽ����trueΪ����Ŀ��Ҫ��;falseΪ������Ŀ��Ҫ��
	bool isDateType(int iDateType)
	{
		return (m_DateType & iDateType) == iDateType;
	}

public:
	/// ����������
	stDate m_SolarDate;
	/// ũ��������
	stDate m_LunarDate;
	/// ����Weekday��[0-6]
	short m_Weekday;
	/// ��ʱ������
	short m_Term;
	/// ����ũ��������
	short m_LunarFestival;
	/// ���չ���������
	short m_SolarFestival;
	/// �������������
	short m_SpecialFestival;
	/// �����������ͱ�ʶ
	int m_DateType;
};

///CCalendar�ඨ���˹�����ũ�����켰ת���ķ���
class CCalendar
{
public:
	CCalendar() 
	{
		// Del by Henchi, 20140226
		// ȡ��������ʱ���Զ���ʼ��
		// ������ִ��AddHoliday���ٵ���Init
		//Init();		/// ������ʱ�Զ���ɳ�ʼ��
		m_InitFlag = false;
	}

	~CCalendar() {}

	/// ��ʼ������
	void Init();

	//[ũ���㷨] ũ�����ڡ���������
	///@param	Date	Ŀ��ũ��������
	///@return	���ض�Ӧ����������
	stDate getSolar(stDate Date);

	//[�����㷨] �������ڡ�ũ������
	///@param	Date	Ŀ�깫��������
	///@return	���ض�Ӧũ��������
	stDate getLunar(stDate Date);

	//[�����㷨] �ж������Ƿ�Ϊ������
	///@param	Date	��Ҫ���жϵ�����
	///@return	�����жϽ����trueΪ������;falseΪ�ǽ�����
	bool isTradingDay(stDate Date);

	//YYYYMMDD
	bool isTradingDay(string datestr);

	//YYYYMMDD
	bool isTradingDay(const char *pDate);

	//YYYY,MM,DD
	bool isTradingDay(short year, short month, short day);

	//[�����㷨] �ж������Ƿ�Ϊ����������
	///@param	Date	��Ҫ���жϵ�����
	///@return	�����жϽ����trueΪ����������;falseΪ����������
	bool isHoliday(stDate Date);

	//YYYYMMDD
	bool isHoliday(string datestr);

	//YYYYMMDD
	bool isHoliday(const char *pDate);

	//YYYY,MM,DD
	bool isHoliday(short year, short month, short day);

	//[�����㷨] �ж������Ƿ�Ϊ����������
	///@param	Date	��Ҫ���жϵ�����
	///@return	�����жϽ����trueΪ����������;falseΪ������
	bool isContinuousDay(stDate Date);

	//[�����㷨] �ж����ڵ�ǰһ���Ƿ�Ϊ����������
	///@param	Date	��Ҫ���жϵ�����
	///@return	�����жϽ����trueΪ��;falseΪ��
	bool AfterContinuousDay(stDate Date);

	//[�����㷨] �ж������Ƿ�Ϊ�����������գ����������ҹ�̣�
	///@param	Date	��Ҫ���жϵ�����
	///@return	�����жϽ����trueΪ������������;falseΪ������
	bool isNoContinuousDay(stDate Date);

	//[�����㷨] �ж������Ƿ�Ϊ����ҹ�̽����գ��ý�������ҹ�̲��֣�
	///@param	Date	��Ҫ���жϵ�����
	///@return	�����жϽ����trueΪ������������;falseΪ������
	bool isNoNightTradingDay(stDate Date);

	//[�����㷨] �ж������Ƿ�ΪƷ�ֽ�����
	///@param	Date	��Ҫ���жϵ�����
	///@return	�����жϽ����0Ϊ�ǽ����գ�1Ϊ��1�����ա���5Ϊ��5������
	short isDeliveryDay(stDate Date);

	//[�����㷨] �ж������Ƿ�Ϊ��Ȼ�˳ֲ���0��
	///@param	Date	��Ҫ���жϵ�����
	///@return	�����жϽ����trueΪ��Ȼ�˳ֲ���0��;falseΪ����Ȼ�˳ֲ���0��
	bool isAdjustDay(stDate Date);

	//[�����㷨] �ж������Ƿ�Ϊ˫����
	///@param	Date	��Ҫ���жϵ�����
	///@return	�����жϽ����trueΪ˫����;falseΪ��˫����
	bool isWeekEnd(stDate Date);

	//[�����㷨] �ж����ںϷ���
	///@param	Date	��Ҫ���жϵ�����
	///@return	�����жϽ����1Ϊ�Ϸ���0Ϊ�·��쳣��-1Ϊ����쳣��-2Ϊ�����쳣
	short isSolar(stDate Date);

	//[ũ���㷨] �ж����ںϷ���
	///@param	Date	��Ҫ���жϵ�����
	///@return	�����жϽ����1Ϊ�Ϸ���0Ϊ�·��쳣��-1Ϊ����쳣��-2Ϊ�����쳣
	short isLunar(stDate Date);

	//[�����㷨] �ж����������Ƿ�ΪĿ������
	///@param	Date	��Ҫ���жϵ�����
	///@return	�����жϽ����trueΪƥ��;falseΪ��ƥ��
	bool checkDateType(stDate Date, DATE_TYPE_MASK iDateType);

	//[�����㷨] ��ȡ�������ڵ�Weekday
	///@param	Date	��Ҫ���жϵ�����
	///@return	������ӦWeekdayֵ��[0��6]0Ϊ�����գ�1Ϊ����1
	short getWeekday(stDate Date);

	//[�����㷨] ��ȡ�������ڵ�Weekday
	///@param	Date	��Ҫ���жϵ�����
	///@param	Flag	����ֵ���ͱ�ʶ[0]����(Ĭ��);[1]Ӣ��(ȫ��д);[2]Ӣ�ģ�����ĸ��д��
	///@return	������ӦWeekdayֵ
	const char * getWeekdaySign(stDate Date, short Flag = 0);

	//[�����㷨] ��ȡ�������ڵ�����ֵ
	///@param	Date	��Ҫ���жϵ�����
	///@param	Flag	����ֵ���ͱ�ʶ[0]����(Ĭ��);[1]����
	///@return	������Ӧ����ֵ
	const char * getDaySign(stDate Date, short Flag = 0);

	//[�����㷨] ��ȡ�������ڵ�����ֵ
	///@param	Date	��Ҫ���жϵ�����
	///@param	Flag	����ֵ���ͱ�ʶ[0]����(Ĭ��);[1]Ӣ��(ȫ��д);[2]Ӣ�ģ�����ĸ��д��
	///@return	������Ӧ����ֵ
	const char * getMonthSign(stDate Date, short Flag = 0);

	//[ũ���㷨] ��ȡ��֧����������Ϣ
	///@param	Date	��Ҫ���жϵ�����
	///@return	���ض�Ӧ�����ֵ
	const char * getTianGan(stDate Date);

	//[ũ���㷨] ��ȡ��֧����ĵ�֧��Ϣ
	///@param	Date	��Ҫ���жϵ�����
	///@return	���ض�Ӧ�ĵ�ֵ֧
	const char * getDiZhi(stDate Date);

	//[ũ���㷨] ��ȡũ����Ф��Ϣ
	///@param	Date	��Ҫ���жϵ�����
	///@return	���ض�Ӧ����Фֵ
	const char * getZodiacSymbols(stDate Date);

	//����������Ϣ�õ���Ӧ����������
	///@param	Year	����������Ϣ
	///@param	Month	����������Ϣ
	///@return	���ظ��·������ṹ����
	vector<CHybirdDate> & getCalendar(short Year, short Month);

	//����������Ϣ�õ���Ӧ����������
	///@param	YM	����������Ϣ,��201208
	///@return	���ظ��·������ṹ����
	vector<CHybirdDate> & getCalendar(int YM);

	//����������Ϣ�õ���Ӧ����������
	///@param	SolarDate	����������Ϣ
	///@return	���ظ��·������ṹ�и�����Ϣ�����ö���
	vector<CHybirdDate>::iterator getCalendarDay(stDate SolarDate);

	//������������Ϣ�õ���Ӧ�Ļ�����ڶ���
	///@param	Year	������������Ϣ
	///@param	Month	������������Ϣ
	///@param	Day	������������Ϣ
	///@return	���ظ��·������ṹ����
	CHybirdDate & getHybirdDate(short Year, short Month, short Day);

	//�������������Ϣ�õ���Ӧ����������
	///@param	Year	����������Ϣ
	///@param	Month	���ƫ�Ƶ�����
	void showCalendar(short Year, short Month);

	//���������������Ӧ����������
	///@param	Year	����������Ϣ
	void showHybirdDate(CHybirdDate Date);

	//[�����㷨] �������ƫ������ȡ������������Ϣ
	///@param	Date	����������Ϣ
	///@param	Offset	���ƫ�ƵĽ���������
	///@return	���ظý����յ����ڽṹ����
	stDate getTDayRelative(stDate Date, long Offset);

	//[�����㷨] ����������Ϣ��ȡ�׸�������
	///@param	Y	�����
	///@param	M	�·���
	///@return	���ظý����յ����ڽṹ����
	stDate getFirstTDay(short Y, short M);

	//[�����㷨] ����������Ϣ��ȡĩ��������
	///@param	Y	�����
	///@param	M	�·���
	///@return	���ظý����յ����ڽṹ����
	stDate getLastTDay(short Y, short M);

	//[�����㷨] ����������Ϣ��ȡ���н�����
	///@param	Y	�����
	///@param	M	�·���
	///@return	���ظý����յ����ڽṹ����
	stDate getMiddleTDay(short Y, short M);

	//�������������һ���µ������ඨ����
	///@param	iID	��������ID
	///@param	pDefine	�����ඨ��������
	void addDateDefine(int iID, char *pDefine);

	//�������������һ������������
	///@param	pDate	�����ַ���YYYYMMDD
	void AddHoliday(const char *pDate);

	//������������Ϣ�õ���Ӧ����������ID�б�
	///@param	Year	������������Ϣ
	///@param	Month	������������Ϣ
	///@param	Day	������������Ϣ
	///@return ���ض�Ӧ����������ID�б�����
	list <int> & getDateTypeList(short Year, short Month, short Day);

private:
	//[�����㷨] �����x���൱��m��f��
	///@param	m	Ŀ���·���
	///@param	x	�����x��
	///@return	��������ֵ��ASCII�ַ���
	char Conv(short m,short x);

	//��ʼ��stLunarYear�ṹ����
	void InitLunarYear(void);

	//��ʼ����ʮ�Ľ������ڱ�
	void InitSolarTerms(void);
	
	//��ʼ��������Ϣ��
	void InitFestivals(void);

	//��ʼ��ũ��������Ϣ��
	void InitLunarFestivals(void);

	//��ʼ������������Ϣ��
	void InitSolarFestivals(void);

	//��ʼ�����������Ϣ��
	void InitSpecialFestivals(void);

	//��ʼ����������Ϣ�б�
	void InitHoliday(void);

	//��ʼ�������ṹ
	void InitCalendar(void);

	//��ʼ�����������ṹ
	void InitWorkCalendar(void);

	//��ʼ�����������ṹ�е�������
	void InitWorkCalendarList(int YM);

	//��ʼ����Լ��Ϣ
	void InitInstrument(void);

	//��ʼ����Լ������Ϣ
	void InitInstrumentType(void);

	//��ʼ����Լ���������Ϣ
	void InitInstrumentDate(void);

	//�������ڶ�����Ϣ���������ҵ���Ӧ����ƫ��
	///@param	Vec	�������������Vec����
	///@param	iNum	�������
	///@param	iDateType	������������
	///@return	���ظ����ڵ�ƫ����,-1��ʾû���ҵ�
	int findDay(vector<CHybirdDate> & Vec, int iNum, int iDateType);

	//[�����㷨] ��Ԫ����������
	///@param	Date	���빫��������
	///@return	���ظ����ڵĹ�Ԫƫ����
	long DayOffset(stDate Date);

	//[�����㷨] �ɹ�Ԫ����������ֵ�����Ӧ������Ϣ
	///@param	Date	����������Ϣ
	///@return	���ظ����ڵ����ڽṹ����
	stDate getDayByOffset(long Offset);

	//[�����㷨] ���������Լ����Ӧ������Ϣ[Y��M�µ�N����X]
	///@param	Y	�����
	///@param	M	�·���
	///@param	N	��N��
	///@param	X	��X
	///@return	���ظ����ڵ����ڽṹ����
	stDate getDayBySpecial(short Y, short M, short N, short X);

	//[�����㷨] �������ƫ������ȡ����������Ϣ
	///@param	Date	����������Ϣ
	///@param	Offset	���ƫ�Ƶ�����
	///@return	���ظ����ڵ����ڽṹ����
	stDate getDayRelative(stDate Date, long Offset);

	//[ũ���㷨] �������ƫ������ȡ����������Ϣ
	///@param	Date	ũ��������Ϣ
	///@param	Offset	���ƫ�Ƶ�����
	///@return	���ظ����ڵ����ڽṹ����
	stDate getDayRelativeL(stDate Date, long Offset);

	//[ũ���㷨] �����й���Ԫ�귨
	///@param	Date	����ũ��������
	///@return	���ظ�����Ӧ���й���Ԫ�귨
	short getChineseEra(short Year, short Flag);

	//ˢ���ض��·ݵ��������ݣ�д�뽻���ա����������յ���Ϣ
	///@param	vec_Calendar	����������Ϣ��Vector����
	void RefreshMonthCalendar(vector<CHybirdDate> & vec_Calendar);

	//ˢ���ض��յ��������ݣ�д������Ƿ��Ƿ�Ϊ�����յ���Ϣ
	///@param	vec_Calendar	����������Ϣ��Vector����
	///@param	vetIt	ָ��������Ϣ��Vector��ĳһ�յĵ�����
	void checkDeliveryDay(vector<CHybirdDate> & vec_Calendar, vector<CHybirdDate>::iterator vecIt);

	//ˢ���ض��յ��������ݣ�д������Ƿ�Ϊ���������յ���Ϣ
	///@param	vec_Calendar	����������Ϣ��Vector����
	///@param	vetIt	ָ��������Ϣ��Vector��ĳһ�յĵ�����
	void checkHolidayDay(vector<CHybirdDate> & vec_Calendar, vector<CHybirdDate>::iterator vecIt);

	//ˢ���ض��յ��������ݣ�д������Ƿ�Ϊ��Ȼ�˳ֲ���0�յ���Ϣ
	///@param	vec_Calendar	����������Ϣ��Vector����
	///@param	vetIt	ָ��������Ϣ��Vector��ĳһ�յĵ�����
	void checkAdjustDay(vector<CHybirdDate> & vec_Calendar, vector<CHybirdDate>::iterator vecIt);

	//���������������Ӧ��ϵ��map(1900->2100)
	//@key	int	�����յ����룬�磺20120612
	//@value	short	����������������ֵ[0~23]
	map<int, short> m_mapSolarTerms;

	//����������ũ�����ն�Ӧ��ϵ��map(1800->2100)
	//@key	int	�����յ����룬�磺20120612
	//@value	short	���������
	map<int, short> m_mapLunarFestival;

	//���������빫�����ն�Ӧ��Ӧ��ϵ��map(1800->2100)
	//@key	int	�����յ����룬�磺20120612
	//@value	short	���������
	map<int, short> m_mapSolarFestival;

	//����������������ն�Ӧ��Ӧ��ϵ��map(1800->2100)
	//@key	int	�����յ����룬�磺20120612
	//@value	short	���������
	map<int, short> m_mapSpecialFestival;

	//���潻�������յ�list
	list<int> m_listHoliday;

	//�����ֵ��list
	list<int> m_listEmpty;

	//���������Լ��Ϣ���list
	list<CBasicInstrumentType> m_listInstrument;

	//��������������ڶ�Ӧ��ԼID�����map
	map<int, list<string> > m_mapInstrumentLTD;

	//������Ȼ�˳ֲ���0�ն�Ӧ��ԼID�����map
	map<int, list<string> > m_mapInstrumentAD;

	//�����׸����������ڶ�Ӧ��ԼID�����map
	map<int, list<string> > m_mapInstrumentDD1;

	//�����2���������ڶ�Ӧ��ԼID�����map
	map<int, list<string> > m_mapInstrumentDD2;

	//�����3���������ڶ�Ӧ��ԼID�����map
	map<int, list<string> > m_mapInstrumentDD3;

	//�����4���������ڶ�Ӧ��ԼID�����map
	map<int, list<string> > m_mapInstrumentDD4;

	//�����5���������ڶ�Ӧ��ԼID�����map
	map<int, list<string> > m_mapInstrumentDD5;

	//����������Ϣ�����ݽṹ��
	//@key	int	����ֵ�����룬�磺201206
	//@value	vector<CHybirdDate>	�����е��¸���������Ϣ��vector
	map<int, vector<CHybirdDate> > m_mapCalendar;

	//���湤��������Ϣ�����ݽṹ��
	//@key	int	����ֵ�����룬�磺201206
	//@value	vector< list <int> > �����е��¸����Ӧ�����ڲ���ID
	map<int, vector< list <int> > > m_mapWorkCalendar;

	/// ��ʼ����������ʱ�Ĺ���������
	stDate m_InitDate;
	
	/// ��ʼ����ƣ����ڱ����ظ��Ķ�γ�ʼ��
	bool m_InitFlag;
};

#endif
