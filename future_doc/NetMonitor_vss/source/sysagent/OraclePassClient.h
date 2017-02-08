/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	OraclePassClient.h
///@brief	��OraclePass�������������󣬻�ȡ�������������ݿ���������Ҫ�Ĳ���
///@history
///20080825	����		�������ļ�
/////////////////////////////////////////////////////////////////////////
#ifndef _ORACLE_INFO_EXTRACT_H_
#define _ORACLE_INFO_EXTRACT_H_

#include <stdlib.h>
#include <string.h>
#include "xmlcfg.h" // for CDBConnectString
class COraclePassClient
{
	/* */
	public:
		COraclePassClient(void);

		// ����Ҫ��ʽ�� descontructor

	//~COraclePassClient();
	private:
		list<CBNSInfo>	m_lbns;

		string	m_key;

		void DecryptPwd(char *pInput, char *pOutput) const;

	/* */
	public:
		/**��ȡ���ݿ�������Ϣ
	* @param  req	�������  �ṩ����OraclePass�������ı�Ҫ��Ϣ
	*		req.szServerIP  BNS(OraclePass)��������ַ
	*		req.iPort		BNS�������˿�
	*		req.szEnv		������Product, ����; Testing, ����; Develop, ������
	*		req.szDBName	���ݿ���,NGES��ָBDB��SDB,����BDB/SDB/HDB/RDB�ȡ�
	*		req.szDBUser	ָ�����ݿ��û�

	* @param  CDBConnectString ������� ��¼һ�����ݿ��ʺŵ�ip port databaseName username userpassword
	*
	* @return 	0 �ɹ� �����ʾʧ�ܣ�ȡֵ����
	*   ERR_InvalidRequest=1  �����ļ����ò���ȷ���������δ��ȷ��д
	*   ERR_ConnectError=2    �����������������
	*   ERR_AccessDenied=10   �ͻ����޷������ݿ��Ȩ��
	*   ERR_UserNotFound=11   ��Ӧ���û�������
	*   ERR_NoResource=21     ��Դ����
	*   ERR_InvalidCmd=22     ����ķ���ָ��
	*   ERR_ParseError=23     ��������
	*   ERR_Unknown=99        ��������	
	**/
		int GetOracleAccountInfo(
				const CRequestInfo	&req,
				CDBConnectInfo	&dbInfo);

		///����BNS���ӵ�ַ����
			///@param	sServerIP	BNS��������IP��ַ
			///@param	sPort		BNS�������Ķ˿ں�
		void InsertBNSInfo(string sServerIP, int nPort)
		{
			m_lbns.push_back(CBNSInfo(sServerIP, nPort));
		}
};
#endif // end of _ORACLE_INFO_EXTRACT_H_
