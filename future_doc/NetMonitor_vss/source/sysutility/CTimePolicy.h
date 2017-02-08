/////////////////////////////////////////////////////////////////////////
///@system	������ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CTimePolicy.h
///@brief	������������ϵͳ���õ�ʱ�������ͺ���
///@history
///20110210	�̺״�		�������ļ�
///20110525	�̺״�		�޶�ע��
#ifndef REF_CTIMEPOLICY_H
#define REF_CTIMEPOLICY_H

#include <map>
#include <list>
#include <string>

#include <time.h>

#define SIZE_BUF	256
#define SIZE_BUF_S	32

using namespace std;

// CDateTime ��ʵ�ֳ���ʱ�����ڹ��߷���
class CDateTime
{
	/* */
	public:
		CDateTime(void);
		CDateTime(const CDateTime &ob);
		CDateTime &operator =(const CDateTime &ob);
		bool operator ==(const CDateTime &ob);

		~ CDateTime(void);

		void OpenDrift(void);			// ��ʱ��ƫ�ƣ�����ʱ��ʱ������
		void CloseDrift(void);			// �ر�ʱ��ƫ�ƣ�������ʱ��ʱ������
		void FreshTime(void);			// ˢ��ʱ������Ĭ��Ϊ��ǰʱ��
		void FreshTime(time_t timesec); // ˢ��ʱ������Ĭ��Ϊ��ǰʱ��
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
		void TimeDrift(time_t &timesec);	// ����ʱ��ƫ�����Զ�����ʱ�䣨��ƫ�ƿ����Ѵ򿪣�
		void FreshTimestamp(time_t timesec);
		void FreshTimeStruct(time_t timesec);

	/* */
	protected:
		time_t	m_Time;			// ������ƫ�Ƶ�ʱ������
		time_t	m_Drift;		// ��ʱ�����µ�ʱ��ƫ����
		bool m_bDriftOpen;		// �Ƿ��Զ�����ʱ��ƫ����
		struct tm m_TimeStruct; // ������ƫ�Ƶ�ʱ��ṹ		
};

// CSepData �����ڱ��浥��Sep���ݵĽṹ
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

// CSepsInfo �����ڽ�������ʱ�䴮(������)
class CSepsInfo
{
	/* */
	public:
		///���캯��
		CSepsInfo(void);

		///�������캯��
		CSepsInfo(const CSepsInfo &ob);

		///��������
		~ CSepsInfo(void);

		///��ʼ�����Ա
		void Init(void);

		///���ĳ��ʱ����Դ�
			///@param	strTimeSeps	ʱ�����string��
			///@return	true:��ӳɹ�; false:���ʧ��;
		bool Load(string strTimeSeps);

		///�ж�ʱ�䴮�Ƿ��뱾����һ��
			///@param	strTimeSeps	ʱ�����string��
			///@return	true:һ��; false:��һ��;
		bool Equal(string strTimeSeps);

		///�жϱ����Զ�����ָ��ʱ����Ƿ�Ӧ��Чִ��
			///@param	timesec	ʱ���
			///@return	true:��Ҫִ��; false:����Ҫִ��;
		bool JudgeRun(time_t timesec);

		///��ӡʱ�䴮�����ڴ�����,����̨����ɵ���
		void ShowSepsInfo(void);

	/* */
	protected:
		///��ʱ���б�����µ�ʱ�λ�����Ϣ
			///@param	lStart	ʱ����ֵ
			///@param	lEnd	ʱ����ֵ
			///@param	lGap	ʱ�μ��ֵ
		void AddSepData(long lStart, long lEnd, long lGap);

		///����ʱ����������µ�ʱ�β�����
			///@param	pszSep	ʱ�β�����
		void AddTimeSep(char *pszSep);

		///����ʱ����Դ����ɲ��ϳɺ����ʱ������
			///@return	true:���ɳɹ�; false:����ʧ��;
		bool Gernerate(void);

		///�жϱ����Զ�����ָ��ʱ����Ƿ�Ӧ��Чִ��
			///@param	timesec	ʱ���
			///@return	true:��Ҫִ��; false:����Ҫִ��;
		bool NewJudge(time_t timesec);

	/* */
	protected:
		///��������ʱ������
		string	m_strTaskTime;

		///�����������һ������ʱ��ֵ
		time_t	m_NextRunTime;

		///��Ų�ֺϲ���ĸ�ʱ����Ϣ,������
		list<CSepData>	m_listSepData;

		///�����ʷ����,�������һ�η�����ʱ����Ϣ
		CSepData m_SepData;

		///�����ʱ����,����ʱ����ֵ��ʱ����
		map<long, long> m_mapStart;

		///�����ʱ����,����ʱ����ֵ��ʱ����
		map<long, long> m_mapEnd;
};

// CTimePolicy ��ʵ��ʱ����Զ�����
class CTimePolicy
{
	/* */
	public:
		///���캯��
		CTimePolicy(void);

		///���캯��
		CTimePolicy(string policy);

		///�������캯��
		CTimePolicy(const CTimePolicy &ob);

		///��������
		~ CTimePolicy(void);

		///��ֵ���캯��
		CTimePolicy &operator =(const CTimePolicy &ob);

		///��������
		bool operator ==(const CTimePolicy &ob);

		///��ʼ�����Ա����
		void Init(void);

		///���һ��ʱ����Դ�
			///@param	policy	ʱ�����string��
			///@return	true:��ӳɹ�; false:���ʧ��;
		bool AddPolicyStr(string policy);

		///�ж��Ƿ�Ϊ��Чʱ������ִ�
			///@param	policy	ʱ�����string��
			///@return	0:�Ƿ��ִ�; 1:��׼ʱ����Դ�; 2:������ʱ�εļ��Բ��Դ�;
		int IsValidPolicy(string policy);

		///�жϲ��Զ����ڸ���ʱ����Ƿ���Ҫִ��
			///@param	time	Ŀ��ʱ���
			///@return	true:��Ҫ����; false:����Ҫ����;
		bool ShouldRun(time_t time);

		///�������ڻ�ȡ���Ӧ��ʱ�δ�ֵ
			///@param	strDate	����stringֵ,��:"20110521"
			///@return	��Ӧ��ʱ�䴮ֵ
		string	GetPolicyByDate(string strDate);

		///�������ڻ�ȡ���Ӧ��ʱ�δ�ֵ
			///@param	strMon	�·�stringֵ
			///@param	strDay	�շ�stringֵ
			///@param	strDayNo	������stringֵ
			///@return	��Ӧ��ʱ�䴮ֵ
		string	GetPolicyByMonthDay(
					string	strMon,
					string	strDay,
					string	strDayNo);

		///��ȡ���һ�α�У���ʱ��stringֵ
			///@return	��Ӧ��ʱ��string��
		string	GetLastestTimeSeps(void);

		///��ȡ�����Զ���Ĺ����·��б�
			///@param	listMonth	���ڴ�Ź����·ݵ�list��������
			///@return	true:��ȡ�ɹ�; false:��ȡʧ��;
		bool GetWorkMonth(list<string> &listMonth);

		///��ȡ�����Զ���ָ���·ݵĹ������б�
			///@param	strMonth	ָ�������·���,��:"05"
			///@param	listDay	���ڴ�Ź����յ�list��������
			///@return	true:��ȡ�ɹ�; false:��ȡʧ��;
		bool GetWorkDay(string strMonth, list<string> &listDay);

		///��ӡʱ����Զ����ڴ�����,����̨����ɵ���
		void ShowPolicyMap(void);

	/* */
	protected:
		bool JoinPolicy(string policy, int type);
		bool IsTimeSeps(char *pStr);
		bool IsValidTimeSep(char *pStr);
		bool IsSepDigits(char *pStr, char cSepChar);
		bool JudgeRunDate(time_t time); // �жϵ����Ƿ���������Ҫִ��
		bool JudgeRunTime(void);		// �жϵ�ʱ�Ƿ���Ҫִ�����񣬱������JudgeRunDateִ��
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

		/// ��ʱ���������������һ��ʱ���жϵĻ��棬���ڼ���ͬ���ڲ�ͬʱ��Ķ���ظ�����
			/// �������л�ʱ���˻������Զ�����
		string	m_strDateNotRun;	// �������һ��У����ķ���������
		string	m_strDateRun;		// �������һ��У�������������
		string	m_strTimeSeps;		// �������һ��У���������ʱ��ֵ(��Ӧ�����յ�ʱ�����)
		CSepsInfo m_SepsInfo;		// �������һ��У�������յ�ʱ�������Ϣ,��m_strTimeSeps���Ӧ
};
#endif
