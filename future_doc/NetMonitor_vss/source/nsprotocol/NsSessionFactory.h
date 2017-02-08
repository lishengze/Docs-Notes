// NsSessionFactory.h: interface for the CNsSessionFactory class.
//
///20080727 �Ժ�� NT-0048 : ���CSessionFactory���޸ģ�ע���ַʱ���ӱ�ǲ�����
///                �����ӳɹ�ʱ�᷵�أ�������ͨ����ͬ��ַ����������
///20080318 ���� NT-0097���ڲ��ṩfront��ַ��ʱ��������ʱ
///					ֱ��ʹ��NameServer��ȡFront����������
///20100512 �Ժ�� NT-0103 �ͻ��˶��ߺ������Ż�����NT-0097��������ʱ�ж��߼�����
///                CSessionFactory
///20110509 ����   NT-0131 UserAPI��������
///20121010 ��Ң�� NT-0131 UserAPI�������ƣ�����fens�����ķ�������ʹ�ó�ʱ��������ʹ��NsSession��ʱDisconnect������ͬʱ��������fens����
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NSSESSIONFACTORY_H__B6E230B2_75D9_4E73_ABBF_2E6DB4EC6FDA__INCLUDED_)
#define AFX_NSSESSIONFACTORY_H__B6E230B2_75D9_4E73_ABBF_2E6DB4EC6FDA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "SessionFactory.h"
#include "NsSession.h"

class CNsSessionFactory : public CSessionFactory, public CNsSessionCallback 
{
public:
	CNsSessionFactory(CReactor *pReactor, int nMaxSession);
	virtual ~CNsSessionFactory();
	void RegisterNameServer(char *location, DWORD dwMark=0);
	virtual int HandlePackage(CNsPackage *pNsPackage, CNsSession *pSession);
	virtual void OnTimer(int nIDEvent);
	virtual int HandleEvent(int nEventID, DWORD dwParam, void *pParam);
	void NsDisconnect(CChannel *pChannel);

protected:
	CConnecterManager *m_pNsConnecterManager;
	CNsSession *m_pNsSession;
	bool m_bInQueryNs;
};

#endif // !defined(AFX_NSSESSIONFACTORY_H__B6E230B2_75D9_4E73_ABBF_2E6DB4EC6FDA__INCLUDED_)
