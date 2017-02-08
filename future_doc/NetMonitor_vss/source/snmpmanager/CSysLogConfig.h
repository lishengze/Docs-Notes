/////////////////////////////////////////////////////////////////////////
///@system	������ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CSyslogConfig.h
///@brief	�����˹���syslog������Ϣ����
///@history
///20110705	κ�� �������ļ�
#ifndef REF_CSYSLOGCONFIG_H
#define REF_CSYSLOGCONFIG_H

#include <string>
#include <vector>
#include <map>
#include <list>

//���������
class CConditionNode
{
	/* */
	public:
		int index;			//�ڼ�¼�г��ֵ������±ꡣ�Կո�ָ�����0��ʼ������-1��ʾ��ָ������λ��
		std::string value;	//Ҫƥ�������
		std::vector<std::string> patternlist;	//ģʽƥ��
};

//������Ϣ��
class CSysLogConfigInfo
{
	/* */
	public:
		std::string m_sDeviceType;			//�豸���ͣ�router/switch/printer/...
		std::string m_sCompanyType;			//�������ͣ�cisco/huawei/blade/...
		std::string m_sReserve;				//�����ֶΣ���ǿ����չ��
		std::string m_sEventLevel;			//�¼�����1~4
		std::string m_sEventTypeID;			//�¼����1~8
		std::string m_sEventEnName;			//�¼�Ӣ������
		std::string m_sEventChName;			//�¼���������
		std::string m_sOpFlag;				//�������yes��ʾ���ɣ�no��ʾȡ��
		std::vector<int> m_vAppendContent;	//��Ҫƴ�ӵ�objectid�����index
		std::string m_sSubType;				//�����ͣ�eg:up,down
		std::vector<CConditionNode> m_sEventConditionList;
};

//���ù�����
class CSysLogConfigManager
{
	/* */
	public:
		static CSysLogConfigManager *Instance(void);	//ʵ����������ģʽ
		CSysLogConfigManager(void) :
		m_sFileName(""),
		m_tLastLoadTime(0),
		m_MemberAccessEquipmentFilterEnable(false)
		{
		}

		int LoadConfig(std::string filename);			//��������
		int ReloadConfig(void); //���¼�������
		void DumpConfig(void);

	/* */
	public:
		std::vector<CSysLogConfigInfo>	m_lConfigInfoList;	//������������
		std::map<int, int>	m_mInfoStart;					//������־��Ϣ��ʼλ��
		std::map<std::string, int>	m_mapIPS;
		std::list<std::string> m_devices;

		// ��Ա�����豸��IP��ַ�б�
		std::list<std::string> m_MemberAccessEquipmentList;
		// �Ƿ����û�Ա�����豸�Ķ˿�UPDOWN�¼��Ĺ��ˣ�Ĭ������²�����
		bool m_MemberAccessEquipmentFilterEnable;

	/* */
	private:
		std::string m_sFileName;	//�����ļ���
		time_t m_tLastLoadTime;		//�ϴμ���ʱ��
};
#endif
