/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CPackageFilter.h
///@brief	���������ݰ����˵���
///@auther	�Ժ��
///@history
/// 2014.06.24 ʷսΰ ֧��������ʱ��
#ifndef REF_CPACKAGEFILTER_H
#define REF_CPACKAGEFILTER_H

#include "public.h"
#include "systools.h"

typedef struct{
	string startTime;
	string endTime;
}TimeInterval;
class CPackageFilter
{
	/* */
	public:
		CPackageFilter(void)
		{
		};
		~CPackageFilter(void)
		{
		};
		void AddDesiredTid(DWORD dwTid)
		{
			m_DesiredTids.push_back(dwTid);
		}
		
		bool ResolveTimeIntervals(const char* timeInterval);

		bool CheckTid(DWORD dwTid)
		{
			if (m_DesiredTids.size() == 0
			||	find(
					m_DesiredTids.begin(),
				m_DesiredTids.end(),
				dwTid) != m_DesiredTids.end())
			{
				return true;
			}

			return false;
		}

		bool CheckTime(void);
		bool CheckEventOutput(void);

private:
	///����ʱ��08��30��00-15��30��00
	bool IsolateTime(const string& timeInterval);

	///�Ƴ���β���ַ�
	string & Trim(string & source);

	/* */
	private:
		vector<DWORD> m_DesiredTids;
		vector<TimeInterval>	m_vecTimeInteral;
};
#endif // end REF_CPACKAGEFILTER_H
