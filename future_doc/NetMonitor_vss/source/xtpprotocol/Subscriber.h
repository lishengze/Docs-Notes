///20120416 ����   NT-0139 �ӿ���Ӧʱ�䣺xtpЭ�鶩�ĺͷ���֧�ֶ��߳�
#ifndef __SUBSCRIBER_H_
#define __SUBSCRIBER_H_

#include "XTPPackage.h"
#include "Mutex.h"

/** �����߽ӿڣ���Ҫ���ĵ�Ӧ�ü̳и��ࡣһ��������ֻ�ܶ���һ�����⡣
* �����߱���ָ��ͨѶ�׶���š��ѽ�����Ϣ���������ڿɿ�����
* ��ָ���������Ϣ�ִ�ʱ������������������HandleMessage�������û���
* �����ظ÷���������Ϣ���д���
*/
class CSubscriber
{
public:
	CSubscriber()
	{
	}

	/**��ȡ�����ߵ�ͨѶ�׶α��
	*@return �����ߵ�ͨѶ�׶α��
	*/
	virtual WORD GetCommPhaseNo() = 0;
	
	/**���ö����ߵ�ͨѶ�׶α�ţ���һ�������߿����ɶ���߳����������Դ˺������뱻������
	*@param  nCommPhaseNo Ҫ���õĶ����ߵ�ͨѶ�׶α��
	*/
	virtual void SetCommPhaseNo(WORD nCommPhaseNo) = 0;

	/**��ȡ���ĵ��������
	*@return ���ĵ��������
	*/
	virtual DWORD GetSubjectID() = 0;

	/**��ȡ���յ�����Ϣ����
	*@return ���յ�����Ϣ����
	*/
	virtual DWORD GetReceivedCount() = 0;

	/**�����յ���һ����Ϣ����һ�������߿����ɶ���߳����������Դ˺������뱻������
	*@param pMessage �յ���һ����Ϣ
	*/
	virtual void HandleMessage(CXTPPackage *pMessage) = 0;

	/**�Ƿ���ͨѶ�׶α�ŵ�һ����
	*@return true ��飬false �����
	*@remark �����ͨѶ�׶α�ŵ�һ���ԣ����յ�����Ϣ��ͨѶ�׶α���붩����
	*@remark ��ͨѶ�׶α�Ų�һ��ʱ������Ϣ����������
	*@remark �������ͨѶ�׶α�ŵ�һ���ԣ����յ�����Ϣ��ͨѶ�׶α���붩����
	*@remark ��ͨѶ�׶α�Ų�һ��ʱ����Ϣ�Ա��ύ���Ҷ����ߵ�SetCommPhaseNo����
	*@remark �ᱻ���á�
	*/
	virtual bool CheckCommPhaseNo()
	{
		return false;
	}

protected:
	// ��������HandleMessage����
	CMutex m_Lock;
};

#endif

