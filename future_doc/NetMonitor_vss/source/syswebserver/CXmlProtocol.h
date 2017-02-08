/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CXmlProtocol.h
///@brief	������XMLЭ����
///@history 
///20080810	�ܽ���		�������ļ�

#ifndef REF_CXMLPROTOCOL_H
#define REF_CXMLPROTOCOL_H

#include "Protocol.h"
#include "CXmlPackage.h"

/**Э��ջ�����ĵڵ�����Э�飬��Ҫ��FTDC���Ĵ���
*/
class  CXmlProtocol : public CProtocol  
{
public:
	/**���캯��
	* @param pReactor ָ�����������ָ��
	* @param pBelow    �²�Э���ָ��
	* @param nActiveId ���²�Э����ԣ�����Э���Э��Id
	*/
	CXmlProtocol(CReactor *pReactor)
		:CProtocol(pReactor, 20, new CXmlPackage(), new CXmlPackage())
	{
	}
	/**��������
	*/
	virtual ~CXmlProtocol() {}

	virtual int Pop(CPackage *pPackage)
	{
		printf("CXmlProtocol::Pop\n");
		return CProtocol::Pop(pPackage);
	}
	
	/**�յ�һ����������ݰ�ʱ����
	* @param pPackage ��������ݰ�
	* @return 0   �ɹ�
	* @return <>0 ʧ��
	*/
	virtual int OnRecvErrorPackage(CPackage *pPackage)
	{
		printf("CXmlProtocol:OnRecvErrorPackage recv one wrong package\n");
		return 0;
	}

};

#endif

