#ifndef _CDATE_H_
#define _CDATE_H_

/**CDate�Ǳ�ʾ���ڵ���
*  �����ַ�������ʽ�������ڣ����Լ����������ڵļ���
*/
class CDate
{
public :
	/**���캯��
	*@param pszDate �ַ�����ʾ�����ڣ���ʽΪ"YYYYMMDD"
	*/
	CDate(const char *pszDate);

	/**���캯��
	*@param lDate ������ʾ�����ڣ�1980-1-1�����������
	*/
	CDate(DWORD lDate);

	/**��������
	*/
	~CDate();

	/**ȡ������ʾ������
	*@return ������ʾ������
	*/
	DWORD ToLong();

	/**ȡ�ַ�����ʾ������
	*@return �ַ�����ʾ������
	*@remark ������ʹ���˾�̬����
	*/
    const char *ToString();

	/**ȡ������ʾ�����ڼ�
	*@return ������ʾ�����ڼ���1-7��ʾ����һ�������죩
	*/
	int WeekDay();

	/**ȡ������ʾ�����
	*@return ������ʾ����ݣ��ӹ�Ԫ��ʼ��
	*/
	int Year();

	/**ȡ������ʾ���·�
	*@return ������ʾ���·ݣ�1-12��
	*/
	int Month();

	/**ȡ������ʾ�����е�����
	*@return ������ʾ�����е����ڣ�1-31��
	*/
	int Day();

	/**CDate����������������һ��
	*@return ���Ӻ�Ķ���
	*/
	CDate &operator++(int);

	/**CDate�����������ڼ���һ��
	*@return ���ٺ�Ķ���
	*/
	CDate &operator--(int);
	
	/**��ָ������
	*@param i �ӵ�����
	*@return �Ӻ�Ľ��
	*/
	CDate operator+(DWORD i);

	/**��ָ������
	*@param i ��������
	*@return ����Ľ��
	*/
	CDate operator-(DWORD i);
	
	/**CDate����������������ָ������
	*@param i �ӵ�����
	*@return ���Ӻ�Ķ���
	*/
	CDate &operator +=(DWORD i);

	/**CDate�����������ڼ���ָ������
	*@param i ��������
	*@return ���ٺ�Ķ���
	*/
	CDate &operator -=(DWORD i);
	
	/**��ָ������
	*@return �Ӻ�Ľ��(������ʾ��
	*/
	DWORD operator-(CDate &date);

	/**��ָ������
	*@return ����Ľ��(������ʾ��
	*/
	DWORD operator-(const char* pszDate);
	
	/**�жϱ��������������һ�����Ƿ����
	*@param date Ҫ�ȶԵ���һ����
	*@return true ��ȣ�false�����
	*/
	bool operator==(CDate &date);

	/**�жϱ��������������һ�ַ�����ʾ�������Ƿ����
	*@param pszData Ҫ�ȶԵ��ַ�����ʾ����һ����
	*@return true ��ȣ�false�����
	*/
	bool operator==(const char *pszDate);
	
	/**�ж�һ���ַ����Ƿ�Ϸ��ر�ʾ����("YYYYMMDD")
	*@param pszData
	*@return true �Ϸ������ڱ�ʾ��false �Ƿ������ڱ�ʾ
	*/
	static bool IsValid(const char *pszDate);

	/**��һ���ַ���ת��Ϊ������ʾ������
	*@param pszDate Ҫת�����ַ���
	*@return ת������������ʾ������
	*/
	static DWORD DateToLong(const char *pszDate);

	/**��������ʾ������ת��Ϊһ���ַ�����ʾ������
	*@param lDate Ҫת����������ʾ������
	*@return ת�������ַ�����ʾ������
	*@remark ������ʹ���˾�̬����
	*/
	static char *LongToDate(DWORD lDate);
	
	/**�ж�ĳһ���Ƿ�Ϊ����
	*@param nYear ���
	*@return 1 �����Ϊ���꣬0 ����ݲ�������
	*/
	static int IsLeapYear(int nYear);

	/**ȡָ�����������ڼ�
	*@param pszDate ָ��������
	*@return ������ʾ�����ڼ���1-7��ʾ����һ�������죩
	*/
	static int GetWeekDay(const char *pszDate);

	/**ȡָ���·ݵ�����
	*@param nYear ���
	*@param nMonth �·�
	*@return ���·ݵ�����
	*/
	static int GetDays(int nYear,int nMonth);
private:
	string m_strDate;		/**<���ַ�����ʾ������ */
};

/**CTime�Ǳ�ʾ����ʱ�䣨ʱ�̣����࣬��ȷ����
*  ������������ʽ������������������Լ�������ʱ��ļ���
*/
class CTime
{
public :
	/**���캯��
	*@param pszTime ���ַ�����ʾ��ʱ�̣���ʽΪHH24:MM:SS
	*/
	CTime(const char *pszTime);

	/**���캯��
	*@param lTime ��������ʾ��ʱ�̣���������������
	*/
	CTime(DWORD lTime);

	/**��������
	*
	*/
	~CTime();

	/**�жϱ������Ƿ��ʾ��һ���Ϸ���ʱ��
	*@return true �Ϸ���ʱ�̣�false �Ƿ���ʱ��
	*/
	bool IsValid();

	/**ȡ������ʾ��ʱ��
	*@return ������ʾ��ʱ��
	*/
	DWORD ToLong();
	
	/**ȡ���ַ�����ʾ��ʱ��
	*@return �ַ�����ʾ��ʱ��
	*@remark ������ʹ���˾�̬����
	*/
    const char *ToString();

	/**ȡ��ʱ��24Сʱ�Ƶ�Сʱ
	*@return ��ʱ��24Сʱ�Ƶ�Сʱ
	*/
	int Hour();

	/**ȡ��ʱ�̵ķ���
	*@return ��ʱ�̵ķ���
	*/
	int Minute();

	/**ȡ��ʱ�̵�����
	*@return ��ʱ�̵�����
	*/
	int Second();

	/**��ʱ�̼���һ����ʱ��
	*@param lTimeSpan Ҫ���ϵ�ʱ��
	*@return  ��ʱ�̼���һ����ʱ��Ľ��
	*@remark ����24������´�0�㿪ʼ 
	*/
	CTime operator+(const DWORD lTimeSpan);
	
	/**��ʱ�̼�ȥһ����ʱ��
	*@param lTimeSpan Ҫ��ȥ��ʱ��
	*@return ��ʱ�̼�ȥһ����ʱ��Ľ��
	*@remark С��0������¿�ʼ 
	*/
	CTime operator-(const DWORD lTimeSpan);

	/**��������ʱ�����������
	*@param t ������ʱ��
	*@return ����ʱ�����������
	*/
	DWORD operator-(const CTime &t);

	/**�ж�����ʱ���Ƿ����
	*@param t Ҫ�Ƚϵ�ʱ��
	*@return true ����ʱ����ȣ�false ����ʱ�̲����
	*/
	bool operator==(const CTime &t);

	/**�ж�����ʱ���Ƿ����
	*@param t Ҫ�Ƚϵ����ַ�����ʾ��ʱ��
	*@return true ����ʱ����ȣ�false ����ʱ�̲����
	*/
	bool operator==(const char *pszTime);
	
	/**���һ���ַ����Ƿ��ʾ�˺Ϸ���ʱ�̣�������"HH24:MM:SS"��ʽ
	*@param pszTime Ҫ�����ַ���
	*@return true �Ϸ���ʱ�̱�ʾ��false �Ƿ���ʱ�̱�ʾ
	*/
	static bool IsValid(const char *pszTime);
	
	/**���ַ�����ʾ��ʱ��ת��Ϊ������ʾ��ʱ��
	*@param pszTime ���ַ�����ʾ��ʱ�̣���ʽΪHH24:MM:SS
	*@return ��������ʾ��ʱ�̣�INVALID_TIMEΪ�Ƿ���ʱ��
	*/
	static DWORD TimeToLong(const char *pszTime);

	/**��������ʾ��ʱ��ת��Ϊ�ַ�����ʾ��ʱ��
	*@param lTime ��������ʾ��ʱ�̣���������������
	*@return ���ַ�����ʾ��ʱ�̣�NULLΪ�Ƿ���ʱ��
	*/
	static const char *LongToTime(DWORD lTime);

	enum
	{
		INVALID_TIME = 0xffffffff,				//�Ƿ���ʱ��
		MAX_TIME_VALUE = 24*3600		//һ������������
	};
private:
	DWORD  m_lTimeValue;			/**<��������ʾ��ʱ�� */
};

#endif
