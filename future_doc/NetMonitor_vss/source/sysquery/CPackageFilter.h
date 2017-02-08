/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CPackageFilter.h
///@brief	���������ݰ����˵���
///@auther	�Ժ��
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
