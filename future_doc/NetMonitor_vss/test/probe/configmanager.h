#ifndef _CONFIG_MANAGER_H_
#define _CONFIG_MANAGER_H_

#include <map>
#include <vector>
#include <string>

#include "systools.h"

using namespace std;

//���ù�����
class CConfigManager
{
	public:
		//ʵ����������ģʽ
		static CConfigManager * Instance();  

		//��������
		void LoadConfig(vector<string>& localIPList);	
	private:
		//����xml,��ȡ���������Ӧ��ָ���б�
		void LoadXmlFile();
		
		//����service.list,��ȡprobe�����Ӧ���б�
		void LoadServiceList(vector<string>& localiplist);
		
	public:
		//ϵͳָ��������,key:ָ����,value:�������
		map<string, int> m_mSysAttrTimers;   

		//Ӧ�òɼ���ָ���б�,key:Ӧ����,value:(key:ָ����,value:������)
		map<string, map<string, int> > m_mAppAttrList;

		//���������еķ����б�,key:������, value:����id�б�
		map<string, vector<int> > m_mServiceList;		
};

#endif

