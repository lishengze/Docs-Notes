/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CEventReport.h
///@brief	������̽��澯�������
///@history
///20090106	�ܽ���		�½��ļ�
#ifndef REF_CEVENTREPORT_H
#define REF_CEVENTREPORT_H

#include "public.h"
#include "CachedFileFlow.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"

/////////////////////////////////////////////////////////////////////////
///CEventReport �������ɷ��澯�¼�����
///@author	�ܽ���
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CEventReport
{
	/* */
	public:
		///���캯��
		CEventReport(void);

		///�����澯�¼�����������͵����е�����
			///@param	pEventName	�澯�¼���
			///@param	pObjectName	�澯������
		void GenerateProbeEvent(char *pEventName, char *pObjectName);

	/* */
	protected:
	/* */
	private:
		///���ڷ������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;

		///����澯����ʱ���map
			///key	�澯�¼�����
			///value	�澯���������ʱ��
		map<string, int> m_mapEventDesc;

		///�澯������ʱ����
		int m_nInterval;

		///�澯�¼����кţ�����
		int m_nEventId;

		///�澯�¼�����ţ���ͬ�������ͬ�澯ÿ�ξ���ͬ
		int m_nEventNum;
};
#endif // !defined(REF_CEVENTREPORT_H)
