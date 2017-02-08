// PublishStub.h: interface for the CPublishStub class.
//
// 20070905 赵鸿昊 增加了CancelPublish方法
// 20110119 江鹏   NT-0121：front不用重启换号
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PUBLISHSTUB_H__BD24DD44_B6E3_4E21_B423_D800FC93AC9E__INCLUDED_)
#define AFX_PUBLISHSTUB_H__BD24DD44_B6E3_4E21_B423_D800FC93AC9E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FibPublishApi.h"
#include "XTPPubSession.h"
#include "HashMap.h"

class CPublishStub : public CFibPublishApi, public CXTPFlowManager   
{
public:
	CPublishStub(CReactor *pReactor, DWORD nNodeID, char *pszAddress);

	/** 获取本接口关联的网络地址
	*@return 本接口关联的网络地址
	*/
	virtual const char *GetAddress();

	/**创建一个消息
	* @return 创建出的消息
	*/	
	virtual CXTPPackage *CreateMessage();

	//-------------------发布订阅接口-------------------------------
	/**注册消息队列
	* @param pFlow 要注册的消息队列
	* @param nSubjectID 要发布的主题
	*/
	virtual void RegisterFlow(CReadOnlyFlow *pFlow, DWORD nSubjectID);

	/**取消发布主题
	* @param nSubjectID 要取消发布的主题
	*/
	virtual void CancelPublish(DWORD nSubjectID);

	/**根据主题获取一个注册的流
	* @param nSubjectID 主题
	* @return 获取到的流
	*/
	virtual CReadOnlyFlow *GetFlow(DWORD nSubjectID);

	/**删除本接口
	*/
	virtual void Release();

	/**设置参数
	* @param handler 事件处理器
	* @param nClock 发布请求中的时间id
	*/
	virtual void SetParams(CEventHandler* handler, DWORD nClock);

private:
	virtual ~CPublishStub();
	inline DWORD GetNodeID();
private:
	typedef CHashMap<DWORD, CReadOnlyFlow *, HashInt> CFlowMap;
	CFlowMap m_mapFlow;
	CXTPPubSession *m_pSession;
	DWORD m_nNodeID;
	char m_szAddress[100];

	// 事件处理器
	CEventHandler* m_Handler;

	// 发布者的时间id
	DWORD m_nClock;
};

inline DWORD CPublishStub::GetNodeID()
{
	return m_nNodeID;
}

#endif // !defined(AFX_PUBLISHSTUB_H__BD24DD44_B6E3_4E21_B423_D800FC93AC9E__INCLUDED_)
