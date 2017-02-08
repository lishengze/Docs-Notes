// Server.h: interface for the CServer class .
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SERVER_H__FE5CED62_6EC3_11D7_BB64_444553540000__INCLUDED_)
#define AFX_SERVER_H__FE5CED62_6EC3_11D7_BB64_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ServiceName.h"
#include "Channel.h"

/**CServerʱһ�������δ������ӵ�ͨѶ�������ˡ�ʵ����һ����������
*��ͨѶ�ķ������˻������ܡ���ͬ���͵�����ͨѶ��Ҫ�̳�����࣬��ʵ
*���������ܡ�
*/
class  CServerBase 
{
public:
	/**���캯������ָ���ķ��������������������
	* @param  pName	ָ���ķ�������
	*/
	CServerBase(CServiceName *pName);
	
	/**�����������ͷ�ռ�õ���Դ
	*/
	virtual ~CServerBase();
	
	/**�ȴ�һ���ͻ��˵����ӣ���������ʹ��acceptImpl��������Ĳ���
	* @param  wait	��ʾ��Ҫ�ȴ������Ӳŷ��أ�0��ʾ���ȴ�
	* @return NULL   ��Channelδ���ɹ�
	* @return ��NULL �µ�Channel
	*/
	virtual CChannel *Accept(int wait)=0;
	
	/**��ȡ����Ĵ�����Ϣ
	* @return ��NULL ����Ĵ�����Ϣ
	* @return NULL   ��ʾ����Ĳ�����óɹ�
	*/
	inline char *GetErrorMsg(void);

	/**��ȡ���������˵ķ�������
	* @return	��������
	*/
	inline CServiceName *GetServiceName(void);
	
	/**��ȡ�����������ڽ���selectʱ��ʹ�õ��ļ��š��Ǵ��麯�����̳ж�����Ҫʵ�ִ˷�����
	*���������ʵ��ʹ�õ��ǲ�ѯʽ�ģ���Ӧ������-1
	* @return selectʱ���ļ���
	*/
	virtual int GetId(void)=0;
protected:
	/**������������Ĵ�����Ϣ
	* @param msg	������Ϣ
	*/
	inline void SetErrorMsg(char *pszMsg);
	
private:
	CServiceName *m_pServiceName;   /**< �洢���������˵ķ������� */

	char *m_pszErrorMsg;		/**< �洢��������Ĵ�����Ϣ */
};

inline CServiceName *CServerBase::GetServiceName(void)
{
	return m_pServiceName;
}

inline char *CServerBase::GetErrorMsg(void)
{
	return m_pszErrorMsg;
}

inline void CServerBase::SetErrorMsg(char *pszMsg)
{
	m_pszErrorMsg = pszMsg;
}



#endif // !defined(AFX_SERVER_H__FE5CED62_6EC3_11D7_BB64_444553540000__INCLUDED_)
