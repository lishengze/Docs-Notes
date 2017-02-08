// Flow.cpp: implementation of the CFlow class.
//
// 20110624 ����	NT-0139 �ӿ���Ӧʱ��
//////////////////////////////////////////////////////////////////////

#include "public.h"
#include "Flow.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CFlow::CFlow()
{
	m_NotifyHandlers = new vector<INotify*>();
	m_bAutoNotify = true;
}

CFlow::~CFlow()
{
	delete m_NotifyHandlers;
}

/*
int CFlow::AppendPackage(CPackage *pPackage)
{
	return Append(pPackage->Address(), pPackage->Length());
}

int CFlow::GetPackage(int id, CPackage *pPackage)
{
	if(id<0 || id >= GetCount()){	//�±�Խ�磬�޷�ȡ������
		return -1;
	}
	int len = Get(id, pPackage->Address(), pPackage->Length());

	if(len >= 0){
		pPackage->Truncate(len);
		return len;
	}

	return -1;
}

*/

void CFlow::SetNotifyHandler(INotify* pNotifyHandler)
{
	m_NotifyHandlers->push_back(pNotifyHandler);
}

void CFlow::Notify()
{
	for (int i = 0; i < m_NotifyHandlers->size(); i ++)
		m_NotifyHandlers->at(i)->Notify();
}

void CFlow::SetAutoNotify(bool bAutoNotify)
{
	m_bAutoNotify = bAutoNotify;
}
