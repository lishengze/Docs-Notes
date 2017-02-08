// Client.h: interface for the CClient class .
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLIENT_H__FE5CED61_6EC3_11D7_BB64_444553540000__INCLUDED_)
#define AFX_CLIENT_H__FE5CED61_6EC3_11D7_BB64_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Channel.h"
#include "ServiceName.h"

/**CClinetʱһ�������δ������ӵ�ͨѶ�ͻ��ˡ�ʵ����һ������������ͨѶ�Ŀͻ��˻������ܡ�
*��ͬ���͵�����ͨѶ��Ҫ�̳�����࣬��ʵ���������ܡ�
*/
class  CClientBase
{
public:
	/**���캯������ɳ�ʼ��
	*/
	CClientBase();
	
	/**��������
	*/
	virtual ~CClientBase();
	
	/**����ָ���ķ�����������ϣ�ҲӦ���������أ������ڴ˳�ʱ��˯�ߡ���������
	*ʹ��ConnectImpl������������Ӳ���
	* @param   pName	Ҫ���ӵķ�����
	* @return  ��������ϣ��򷵻����������CChannel��������Ӳ��ϣ��򷵻�NULL������Ӳ��ϣ������ʹ��GetErrorEvent��ȡ�������Ϣ
	*/
	virtual CChannel *Connect(CServiceName *pName)=0;
	
	/**��ȡ����Ĵ�����Ϣ
	* @return	����Ĵ�����Ϣ���������Ĳ�����óɹ����򷵻�NULL
	*/
	inline char *GetErrorMsg(void);
protected:

	/**������������Ĵ�����Ϣ
	* @param  msg  ������Ϣ
	*/
	inline void SetErrorMsg(char *msg);
private:
	
	char *m_pErrorMsg;		/**<�洢��������Ĵ�����Ϣ*/
};

inline char *CClientBase::GetErrorMsg(void)
{
	return m_pErrorMsg;
}

inline void CClientBase::SetErrorMsg(char *msg)
{
	m_pErrorMsg=msg;
}

#endif // !defined(AFX_CLIENT_H__FE5CED61_6EC3_11D7_BB64_444553540000__INCLUDED_)
