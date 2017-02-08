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
		/// 时区时间偏移量(秒)
		int m_nTimeZoneSec;

		/// 线程ID号
		int m_nThreadID;

		/// 指向网络设备数组的首指针
		const CTelnetDevice *m_pDevices;

		/// 网络设备个数
		int m_nDeviceNum;

		/// Tetnet 连接实体
		CTelnetClient m_oTelnetClient;

		/// 文本对比实体
		CFileDiff m_oFileDiff;

		///对象指标值队列
		TemplateMutexCatch<CFTDRtnObjectAttrField>	m_listObjectAttr;

		///告警事件队列
		TemplateMutexCatch<CFTDRtnWarningEventField> m_listWarningEvent;

		///日志事件队列
		TemplateMutexCatch<CFTDRtnSyslogEventField> m_listSyslogEvent;

		///当前日期
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

		/**虚函数，子类可做一些实例化工作
	* @return true:创建成功 false:创建失败
	*/
		virtual bool InitInstance(void);

		/**虚函数，子类清楚实例
	*/
		virtual void ExitInstance(void);

		/**线程开始运行，纯虚函数，子类必须继承实现
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
