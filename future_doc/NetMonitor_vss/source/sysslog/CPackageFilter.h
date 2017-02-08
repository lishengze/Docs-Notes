/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CPackageFilter.h
///@brief	定义了数据包过滤的类
///@auther	赵鸿昊
///@history
/// 2014.06.24 史战伟 支持区间跨度时间
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
	///分离时间08：30：00-15：30：00
	bool IsolateTime(const string& timeInterval);

	///移除收尾空字符
	string & Trim(string & source);

	/* */
	private:
		vector<DWORD> m_DesiredTids;
		vector<TimeInterval>	m_vecTimeInteral;
};
#endif // end REF_CPACKAGEFILTER_H
