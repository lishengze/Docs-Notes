/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CMsgGenerator.h
///@brief	������������Ϣ�ļ��Ĺ�����
///@history
///20111214	�̺״�	�������ļ�
///20111223	�̺״�	������Ϣ���м����ʱ����ԵĴ���
#ifndef REF_CMSGGENERATOR_H
#define REF_CMSGGENERATOR_H

#include "public.h"
#include "systools.h"
#include "FtdPackageDesc.h"
#include "CTimePolicy.h"

#define FLAG_MSG_LINE	"<br/>"

//// CMsgNMEvent �������ڱ��������豸�¼��������Ϣ��
class CMsgNMEvent
{
	/* */
	public:
		CMsgNMEvent(void);
		CMsgNMEvent(
			CFTDRtnWarningEventField &EventField,
			string	&Device,
			string	&Party,
			int Times);
		~ CMsgNMEvent(void);

		CFTDRtnWarningEventField m_EventField;
		string	m_strDevice;
		string	m_strParty;
		int m_iTimes;
};

typedef TemplateMutexCatch<CMsgNMEvent> CMsgNMEventList;

//// CMsgGenerator �������������¼���Ϣ�Ĺ����߳���
class CMsgGenerator :
	public CThread
{
	/* */
	public:
		CMsgGenerator(void);
		CMsgGenerator(char *pszPath, char *pszMsgPolicy, char *pszSystemID);
		~ CMsgGenerator(void);

		/**�麯�����������һЩʵ��������
	* @return true:�����ɹ� false:����ʧ��
	*/
		virtual bool InitInstance(void);

		/**�麯�����������ʵ��
	*/
		virtual void ExitInstance(void);

		/**�߳̿�ʼ���У����麯�����������̳�ʵ��
	*/
		virtual void Run(void);

		/// ��������豸�¼���Ϣ������
		int AddNetDeviceEventMsg(
				CFTDRtnWarningEventField &EventField,
				string	&Device,
				string	&Party,
				int Times);

		/// ���������豸�¼���Ϣ
		int GenNetDeviceEventMsg(void);

		void Init(char *pszPath, char *pszMsgPolicy, char *pszSystemID);

	/* */
	private:
		/// ��ָ������д�뵽ָ���ļ���
		int WriteMsg(char *pszFile, char *pszMsg);

		/// ˢ���ڴ��еĵ�ǰ����ʱ��ֵ
		void RefreshDateTime(void);

		/// ��ȡĬ����Ϣ�ļ���(��·��)
		char *GenMsgFileName(void);

		/// ��ȡ�����豸�¼���Ϣ������
		char *GenNetDeviceEventContent(
				CFTDRtnWarningEventField &EventField,
				string	&Device,
				string	&Party,
				int Times);

	/* */
	private:
		string	m_strPath;						// ��Ϣ�ļ��ı���·��
		string	m_strSystemID;					// ��Ϣר�ü��ϵͳID��ʶ
		CDateTime m_DateTime;					// ���ڱ��浱ǰʱ��
		CTimePolicy m_TimePolicy;				// ���ڱ�����Ϣ��Ϣ��ؿ��Ƶ�ʱ�����
		CMsgNMEventList m_lEvents;				// ���ڱ����¼���Ϣ�Ļ������
			/// Key:�¼���EventNum	Value:�¼����һ�����ʱ��ʱ���
		map<int, time_t> m_mapEventDumpTime;	// ���ڱ����¼����һ����ص�ʱ���
		int m_iMaxRetry;						// ��Ϣ����������Դ���
		int m_iRetrySpan;						// ��Ϣ�ط����(����)
};
#endif
