///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CEventProcess.h
///@brief	�����˲ɼ���������־����Ϣ����
///@history
///20080510	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
#ifndef REF_CEVENTPROCESS_H
#define REF_CEVENTPROCESS_H
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"

/////////////////////////////////////////////////////////////////////////
///CFrontSessionKey������ǰ��ID��ϯλ����ID��Ϊmap�ؼ��ֵ���
///@author	�ܽ���
///@version	1.0,20080710
/////////////////////////////////////////////////////////////////////////
class CFrontSessionKey
{
	/* */
	public:
		///ǰ��ID
		int m_nFID;

		///ϯλ����ID
		int m_nIPID;

	/* */
	public:

		///���캯��
		CFrontSessionKey(void)
		{
			m_nFID = 0;
			m_nIPID = 0;
		}

		///���캯��
			///@param	nFID	ǰ�õ�ID
			///@param	nIPID	����IP��ַ�жϳ�����ϯλ����ID
		CFrontSessionKey(int nFID, int nIPID)
		{
			m_nFID = nFID;
			m_nIPID = nIPID;
		}

		///�������캯��
		CFrontSessionKey(const CFrontSessionKey &ob)
		{
			m_nFID = ob.m_nFID;
			m_nIPID = ob.m_nIPID;
		}

		///����=�����
		void operator=(const CFrontSessionKey &ob)
		{
			m_nFID = ob.m_nFID;
			m_nIPID = ob.m_nIPID;
		}

		///����>�����
		friend bool operator>(
		const CFrontSessionKey	&ob1,
		const CFrontSessionKey	&ob2)
		{
			if (ob1.m_nFID > ob2.m_nFID)
			{
				return true;
			}
			else if (ob1.m_nFID == ob2.m_nFID)
			{
				if (ob1.m_nIPID > ob2.m_nIPID)
				{
					return true;
				}
			}

			return false;
		}

		///����>�����
		friend bool operator < (const CFrontSessionKey &ob1, const CFrontSessionKey &ob2)
		{
			if (ob1.m_nFID < ob2.m_nFID)
			{
				return true;
			}
			else if (ob1.m_nFID == ob2.m_nFID)
			{
				if (ob1.m_nIPID < ob2.m_nIPID)
				{
					return true;
				}
			}

			return false;
		}

		///����==�����
		friend bool operator==(
		const CFrontSessionKey	&ob1,
		const CFrontSessionKey	&ob2)
		{
			if (ob1.m_nFID == ob2.m_nFID && ob1.m_nIPID == ob2.m_nIPID)
			{
				return true;
			}

			return false;
		}
};

/////////////////////////////////////////////////////////////////////////
///CTkernelIdKey�����˽��׺���ID��������������Ϊmap�ؼ��ֵ���
///@author	�ܽ���
///@version	1.0,20080710
/////////////////////////////////////////////////////////////////////////
class CTkernelIdKey
{
	/* */
	public:

		///���캯��
		CTkernelIdKey(void)
		{
			m_nTkernelID = 0;
			m_sDCName = "";
		}

		///���캯��
			///@param	nTkernelID	���׺���ID
			///@param	pDCName	����������
		CTkernelIdKey(int nTkernelID, char *pDCName)
		{
			m_nTkernelID = nTkernelID;
			m_sDCName = pDCName;
		}

		///���캯��
			///@param	nTkernelID	���׺���ID
			///@param	pDCName	����������
		CTkernelIdKey(int nTkernelID, const string &pDCName)
		{
			m_nTkernelID = nTkernelID;
			m_sDCName = pDCName;
		}

		///�������캯��
		CTkernelIdKey(const CTkernelIdKey &ob)
		{
			m_nTkernelID = ob.m_nTkernelID;
			m_sDCName = ob.m_sDCName;
		}

		///����=�����
		void operator=(const CTkernelIdKey &ob)
		{
			m_nTkernelID = ob.m_nTkernelID;
			m_sDCName = ob.m_sDCName;
		}

		///����>�����
		friend bool operator>(
		const CTkernelIdKey &ob1,
		const CTkernelIdKey &ob2)
		{
			if (ob1.m_nTkernelID > ob2.m_nTkernelID)
			{
				return true;
			}
			else if (ob1.m_nTkernelID == ob2.m_nTkernelID)
			{
				if (ob1.m_sDCName > ob2.m_sDCName)
				{
					return true;
				}
			}

			return false;
		}

		///����>�����
		friend bool operator < (const CTkernelIdKey &ob1, const CTkernelIdKey &ob2)
		{
			if (ob1.m_nTkernelID < ob2.m_nTkernelID)
			{
				return true;
			}
			else if (ob1.m_nTkernelID == ob2.m_nTkernelID)
			{
				if (ob1.m_sDCName < ob2.m_sDCName)
				{
					return true;
				}
			}

			return false;
		}

		///����==�����
		friend bool operator==(
		const CTkernelIdKey &ob1,
		const CTkernelIdKey &ob2)
		{
			if (ob1.m_nTkernelID == ob2.m_nTkernelID
			&&	ob1.m_sDCName == ob2.m_sDCName)
			{
				return true;
			}

			return false;
		}

	/* */
	public:
		///���׺��ĵ�ID���
		int m_nTkernelID;

		///�������ĵ�����
		string	m_sDCName;
};

/////////////////////////////////////////////////////////////////////////
///CLoginSuccessValue������Ϊmapֵ����
///@author	�ܽ���
///@version	1.0,20080710
/////////////////////////////////////////////////////////////////////////
class CLoginSuccessValue
{
	/* */
	public:

		///���캯��
		CLoginSuccessValue(void)
		{
			m_nFrontID = 0;
			m_nSessionID = 0;
			m_nIpTypeID = -1;
		}

		///���캯��
			///@param	nFrontID	ǰ�õ�ID
			///@param	nSessionID	��¼�ĻỰID
			///@param	nTpTypeID	����ip��ַ�жϳ�����ϯλ����ID
		CLoginSuccessValue(int nFrontID, int nSessionID, int nIpTypeID)
		{
			m_nFrontID = nFrontID;
			m_nSessionID = nSessionID;
			m_nIpTypeID = nIpTypeID;
		}

		///�������캯��
		CLoginSuccessValue(const CLoginSuccessValue &ob)
		{
			m_nSessionID = ob.m_nSessionID;
			m_nFrontID = ob.m_nFrontID;
			m_nIpTypeID = ob.m_nIpTypeID;
		}

		///����=�����
		void operator=(const CLoginSuccessValue &ob)
		{
			m_nSessionID = ob.m_nSessionID;
			m_nFrontID = ob.m_nFrontID;
			m_nIpTypeID = ob.m_nIpTypeID;
		}

		///����==�����
		friend bool operator==(
		const CLoginSuccessValue &ob1,
		const CLoginSuccessValue &ob2)
		{
			if (ob1.m_nFrontID == ob2.m_nFrontID
			&&	ob1.m_nSessionID == ob2.m_nSessionID
			&&	ob1.m_nIpTypeID == ob2.m_nIpTypeID)
			{
				return true;
			}

			return false;
		}

	/* */
	public:
		///ǰ�õ�ID
		int m_nFrontID;

		///��¼��ID
		long m_nSessionID;

		///IP���͵�ID,�糡�ڡ�����
		int m_nIpTypeID;
};

class CIPAnalysis
{
	/* */
	public:
		///���캯��
			///@param	pConfigPath	�����ļ�·��
		CIPAnalysis(char *pConfigPath);

		///��ʼ��IP��Ӧϯλ��ϵ����
			///@comment	����getIpTypeID֮ǰ���ȳ�ʼ��
		bool init(void)
		{
			return true;
		}

		///����IP��ַ�ж�ϯλ���ͺ���
			///@param	pIpAddr	ip��ַ����172.16.30.224
			///@return	���ظ�ip��ַ��Ӧ��ϯλ����
		int getIpTypeID(char *pIpAddr);

	/* */
	private:
		map<string, int> m_mapIpType;
};

class CEventProcess
{
	/* */
	public:

		///���캯��
		CEventProcess(void)
		{
			m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
			memset(&m_eventField, 0, sizeof(m_eventField));
		}

		///��ӡ�������
		void Print(void);

		///�¼�����ͳ�Ʒ�������
		void getPeriodStats(void);

		///ͳ�������ǰmdkernel���Ӹ�������
		void getMdSessionSize(void);

		///�����¼�����
			///@param	pObjectID	����ID��Ϣ��
			///@param	pMonDate �¼���������
			///@param	pMonTime �¼�����ʱ��
			///@param	pEventName	�¼���
			///@param	pEventDes	�¼���������Ϣ
		void putEventReport(
			char *pObjectID,
			char *pMonDate,
			char *pMonTime,
			char *pEventName,
			char *pEventDes);

		///��¼mdkernel�ɹ��¼�������
			///@param	pDCName	�������ĵ�����
			///@param	pProgram	Ӧ�ý�������
			///@param	nTkernelID	���׺��ĵı��
			///@param	pValue	�¼���ָ��
		void processMdLoginSuccess(
				const char	*pDCName,
				char *pProgram,
				int nTkernelId,
				char *value);

		///�˳�mdkernel�ɹ��¼�������
			///@param	pDCName	�������ĵ�����
			///@param	pProgram	Ӧ�ý�������
			///@param	nTkernelID	���׺��ĵı��
			///@param	pValue	�¼���ָ��
		void processMdLogOutSuccess(
				const char	*pDCName,
				char *pProgram,
				int nTkernelId,
				char *pValue);

	/* */
	protected:
	/* */
	private:
		///�����¼�
		CFTDRtnSyslogEventField m_eventField;

		///���ڷ������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;
};
#endif //REF_CEVENTPROCESS_H
