// Reactor.cpp: implementation of the CReactor class.
//
// 20090510 赵鸿昊  NT-0074：新增HandleOtherTask用于派生类处理反复执行的工作
// 20110624 江鹏	NT-0139 加快响应时间
//////////////////////////////////////////////////////////////////////

#include "public.h"
#include "Reactor.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CReactor::CReactor()
{
	m_bIOListHasNull = false;
}

CReactor::~CReactor()
{
}

void CReactor::RegisterIO(CEventHandler *pEventHandler)
{
	m_IOList.push_back(pEventHandler);
}

void CReactor::RemoveIO(CEventHandler *pEventHandler)
{
// 直接删除会导致枚举器失效
// m_IOList.remove(pEventHandler);

	for (CEventHandlerList::iterator i = m_IOList.begin(); i != m_IOList.end(); i++)
	{
		if ((*i) == pEventHandler) 
		{
			(*i) = NULL;
			m_bIOListHasNull = true;
		}
	}
}

bool CReactor::HandleOtherTask()
{
	if (!m_queueEvent.Empty())
	{
		return true;
	}

	if (m_pTimerQueue->CheckExpire(m_nCurrClock))
	{
		return true;
	}

	return false;
}
