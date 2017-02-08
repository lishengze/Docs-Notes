/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CPackageFilter.h
///@brief	定义了数据包过滤的类
///@auther	赵鸿昊
///@history
#ifndef REF_CPACKAGEFILTER_H
#define REF_CPACKAGEFILTER_H

#include "public.h"
#include "systools.h"

class CPackageFilter
{
	/* */
	public:
		CPackageFilter(void)
		{
			m_strEndTime = "23:59:59";
		};
		~CPackageFilter(void)
		{
		};
		void AddDesiredTid(DWORD dwTid)
		{
			m_DesiredTids.push_back(dwTid);
		}

		void SetStartTime(const char *pszStartTime)
		{
			m_strStartTime = pszStartTime;
		}

		void SetEndTime(const char *pszEndTime)
		{
			m_strEndTime = pszEndTime;
		}

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

	/* */
	private:
		vector<DWORD> m_DesiredTids;
		string	m_strStartTime;
		string	m_strEndTime;
};
#endif // end REF_CPACKAGEFILTER_H
