// EventHandler.h: interface for the CEventHandler class .
//
// 20110624 ����	NT-0139 �ӿ���Ӧʱ��
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EVENTHANDLER_H__D0DAF147_AD16_4C5C_9393_78E357E0A93E__INCLUDED_)
#define AFX_EVENTHANDLER_H__D0DAF147_AD16_4C5C_9393_78E357E0A93E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class  CReactor;
class  CEventHandler;

struct CEvent
{
	CEventHandler *pEventHandler;
	int nEventID;
	DWORD dwParam;
	void *pParam;
	void *pAdd;
};

/**
* CEventHandler��һ������Ŀ������еĶ������Ǹ���Э�顢����������ʱ���ĳ�����ࡣ
* �������¼��ɴ������У�һ��ΪIO��������һ��Ϊ��ʱ������һ��CEventHandler����ֻ��
* ע�ᵽCReactor���ܻ�ú�������ĵ���
*/
class  CEventHandler  
{
public:
	/**���캯��
	* @param pReactor ��ǰ���ж������������ 
	*/
	CEventHandler(CReactor *pReactor);
	
	/**��������
	*/
	virtual ~CEventHandler();
	
	/**����IO�����Ķ���������CReactor����
	* @return ����
	*/
	virtual int HandleInput(){return 0;};
	
	/**����IO������д��������CReactor����
	* @return ���� 
	*/
	virtual int HandleOutput(){return 0;};

	/**����IO������������������CReactor����
	* @return ���� 
	*/
	virtual int HandleOther(){return 0;};

	/**����ʱ��������CReactor����
	* @param nIDEvent ��ʱ����ʶ   
	*/
	virtual void OnTimer(int nIDEvent){};
	
	/*��CEventHandler�������첽�¼�
	* @param nEventID �¼�ID
	* @param dwParam ˫���Ͳ���
	* @param pParam �޷���ָ���Ͳ���
	*/
	bool PostEvent(int nEventID, DWORD dwParam, void *pParam);

	/*��CEventHandler������ͬ���¼�
	* @param nEventID �¼�ID
	* @param dwParam ˫���Ͳ���
	* @param pParam �޷���ָ���Ͳ���
	*/
	int SendEvent(int nEventID, DWORD dwParam, void *pParam);

	/**����һ���¼�
	* @param nEventID �¼�ID
	* @param dwParam ��һ������
	* @param pParam �ڶ�������
	* @return ������
	*/
	virtual int HandleEvent(int nEventID, DWORD dwParam, void *pParam){return 0;};

	/**��ȡ����дsocket����selectʹ��
	* @param pReadId   ������������ض���ʹ�õ�socket��Ϊ0��ʾ����Ҫ��
	* @param pWriteId  �������������д��ʹ�õ�socket��Ϊ0��ʾ����Ҫд 
	*/
	virtual void GetIds(int *pReadId, int *pWriteId){};

protected:
	/**���ö�ʱ��
	* @param nIDEvent ��ʱ����ʶ(����Ϊ0)
	* @param nElapse ��ʱ����(��)
	*/
	void SetTimer(int nIDEvent, int nElapse);

	/**ȡ����ʱ��
	* @param nIDEvent ��ʱ����ʶ(0��ʾȡ���ö�������ж�ʱ��)
	*/
	void KillTimer(int nIDEvent);

protected:
	CReactor *m_pReactor;    /**<��ǰ������������ָ��*/
};

#endif // !defined(AFX_EVENTHANDLER_H__D0DAF147_AD16_4C5C_9393_78E357E0A93E__INCLUDED_)
