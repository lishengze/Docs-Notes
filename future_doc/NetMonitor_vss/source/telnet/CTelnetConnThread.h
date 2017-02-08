#include "systools.h"
#include "FtdPackageDesc.h"
#include "CTelnetClient.h"
#include "CFileDiff.h"

#define MAX_DEVICE_NUM	200
#define MAX_THREAD_NUM	10

#ifdef WIN32
#define TMP_DIRNAME "D:\\tmp"
#else
#define TMP_DIRNAME "/tmp"
#endif
#define DEFAULT_TIMESEP "00:00:00-23:59:00.20"

class CTelnetConnThread :
	public CThread
{
	/* */
	private:
		/// ʱ��ʱ��ƫ����(��)
		int m_nTimeZoneSec;

		/// �߳�ID��
		int m_nThreadID;

		/// ָ�������豸�������ָ��
		const CTelnetDevice *m_pDevices;

		/// �����豸����
		int m_nDeviceNum;

		/// Tetnet ����ʵ��
		CTelnetClient m_oTelnetClient;

		/// �ı��Ա�ʵ��
		CFileDiff m_oFileDiff;

		///����ָ��ֵ����
		TemplateMutexCatch<CFTDRtnObjectAttrField>	m_listObjectAttr;

		///�澯�¼�����
		TemplateMutexCatch<CFTDRtnWarningEventField> m_listWarningEvent;

		///��־�¼�����
		TemplateMutexCatch<CFTDRtnSyslogEventField> m_listSyslogEvent;

		///��ǰ����
		char m_date[10];
		char m_time[10];

	/* */
	public:
		CTelnetConnThread(int nThreadID, const CTelnetDevice *pDevices)
		{
			m_nThreadID = nThreadID;
			m_pDevices = pDevices;
			m_nDeviceNum = nThreadID;
			m_nTimeZoneSec = getTimeZoneOffset();
		}

		~CTelnetConnThread(void)
		{
		}

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

		bool getObjectAttr(CFTDRtnObjectAttrField &objectAttr)
		{
			return m_listObjectAttr.get(objectAttr);
		}

		bool getWarningEvent(CFTDRtnWarningEventField &warningEvent)
		{
			return m_listWarningEvent.get(warningEvent);
		}

		bool getSyslogEvent(CFTDRtnSyslogEventField &syslogEvent)
		{
			return m_listSyslogEvent.get(syslogEvent);
		}

	/* */
	private:
		void CheckVersion(CObjectIDName &object, string ip);
};
