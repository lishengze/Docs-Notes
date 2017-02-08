/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CEventReport.h
///@brief	ʵ����̽��澯�������
///@history	
///20090106	�ܽ���		�½��ļ�
/////////////////////////////////////////////////////////////////////////
#include "CEventReport.h"
#include "SyslogSpiImpl.h"
extern CManageConSession g_mManageConSession;	// �����������ӵĵ�ַ��Ϣ
#define ENSENDPACKAGETO g_mManageConSession.sendFTDCPackage(&m_pkgSend);

CEventReport::CEventReport(void)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	m_nInterval = 900;	///�澯��ʱ������Ĭ��Ϊ10����
	m_nEventId = 1;
	m_nEventNum = 1;
}

void CEventReport::GenerateProbeEvent(char *pEventName, char *pObjectName)
{
	time_t	timep = time((time_t *)NULL);
	if ((int)timep < (m_mapEventDesc[string(pEventName)] + m_nInterval))
	{
		return;
	}

	m_mapEventDesc[string(pEventName)] = timep;

	CFTDRtnWarningEventField fieldInfo;
	memset(&fieldInfo, 0, sizeof(fieldInfo));

	struct tm tm_time;
	LocalTime((time_t *) &timep, &tm_time);
	sprintf(
		(char *)fieldInfo.MonTime.getValue(),
		"%02d:%02d:%02d",
		tm_time.tm_hour,
		tm_time.tm_min,
		tm_time.tm_sec);
	sprintf(
		(char *)fieldInfo.MonDate.getValue(),
		"%04d%02d%02d",
		tm_time.tm_year + 1900,
		tm_time.tm_mon + 1,
		tm_time.tm_mday);

	fieldInfo.EventName = pEventName;
	fieldInfo.ObjectID = pObjectName;
	fieldInfo.EvendID = m_nEventId++;
	fieldInfo.EventNum = m_nEventNum;
	fieldInfo.ProcessFlag = "N";
	fieldInfo.OccurDate = fieldInfo.MonDate.getValue();
	fieldInfo.OccurTime = fieldInfo.MonTime.getValue();

	m_pkgSend.PreparePackage(
			FTD_TID_RtnWarningEventTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);
	ENSENDPACKAGETO;
}
