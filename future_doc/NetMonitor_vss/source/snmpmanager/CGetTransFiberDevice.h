/////////////////////////////////////////////////////////////////////////
///@system	������ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CGetTransFiberDevice.h
///@brief	������CGetTransFiberDeviceʹ�õ���
///@history
///20130318	LSC		�������ļ�
#ifndef REF_CGETTRANSFIBERDEVICE_H
#define REF_CGETTRANSFIBERDEVICE_H

#include "platform.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include "net_snmp.h"
#include "CSnmpWrapper.h"
#include "CTaskManager.h"

#include <string>
#include <list>
#include <map>
#include <iostream>
using namespace std;

enum POWER_TYPE
{
	POWER_TYPE_MASTER, //�Ǹɹ⹦��
	POWER_TYPE_SLAVE, //�ͻ���⹦��
};

struct Power_Value
{
	string p_name;
	pair<string,int> p_value;

	Power_Value()
	{
		p_name = "";
		p_value.first = "";
		p_value.second = 0;
	}
};
#define IFSINERROR_Value Power_Value 


#ifdef WIN32
#define CSV_DIR		"C:\\tmp\\csv\\"
#else
#define CSV_DIR		"/var/log/trans_log/"
#endif

#define CSV_NULL_LINE_NUMBER	7

///WALK���ؽ������
typedef CDPWALK_RESULT	WALK_RESULT;

///CDPWALK���ؽ��������
typedef WALK_RESULT::iterator WALK_RESULT_ITERATOR;


/// CSnmpTaskInfo ������SNMPָ��������Ϣ��
class CTransFiberTaskInfo
{
	/* */
public:
	int TaskID;
	int RunTimes;
	string TaskDate;
	string TaskTime;
	string ObjectID;
	string IPAddress;
	string Community;
	string AttrName;
	string Oid_value;
	int DevManuID;
	int TaskStatus; //����״̬
};

class CTransFibertConfig
{
public:
	string ip;
	string locate;
	string rang_m;
	string rang_s;
	list<string>  in_list[3]; //��¼�˿������ţ�in_list[0]��ʾ�Ǹɣ�������ʾ���ӿͻ���Ķ˿�
	list<string>	  in_Number[3]; //��ʾ�����˿�������ţ�һһ��Ӧ
};


class CGetTransFiberDevice:public CThread
{
	/* */
	public:

		///���캯��
		CGetTransFiberDevice()
		{
			m_csv_filename="";
		}

		///��������
		~CGetTransFiberDevice(void)
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

		void AddCTransFiberTaskInfo(
			int TaskID,
			int Times,
			string MonDate,
			string MonTime,
			CFTDSysNetDeviceField DeviceInfo,
			string AttrName,
			int TaskStatus);

	void test_ProcessHuaweiDevicePower(string ipaddress,int type,vector<list<Power_Value> >& datas)
	{
		ProcessHuaweiDevicePower( ipaddress, type, datas );
	}
	void test_FormatedataAccordingPro(list<Power_Value>& datas, string& lastresult)
	{
		FormatedataAccordingPro( datas, lastresult);
	}
	bool test_CheckRange(const string& range, const string& a)
	{
		return CheckRange( range,a );
	}

	void test_ProcessCiscoDeviceIfInErrors(CSnmpWrapper *wrap,vector<list<IFSINERROR_Value> >& datas,string& lastresult);

	private:

		//��csv�ļ���������
		void GetCSVLine(vector<string> &csv_data,const char *filename); 

		bool GetLastCSVFileName(string &lastFileName);

		void CheckCSVFileName(string newName,string &currName);

		void GetCSVData(int row, int key_col, int data_col, string& key_data, string & value_data);

		void ProcessHuaweiDevicePower(string ipaddress,int type,vector<list<Power_Value> >& datas);

		void ProcessCiscoDeviceTPPower(CSnmpWrapper *wrap,vector<list<Power_Value> >& datas);
		void ProcessCiscoDeviceOPPower(CSnmpWrapper *wrap,vector<list<Power_Value> >& datas);

		void ProcessCiscoDeviceIfInErrors(CSnmpWrapper *wrap,vector<list<IFSINERROR_Value> >& datas);

		void FormatedataAccordingPro( list<Power_Value>& datas, string& lastresult);

		//range :-20~-7
		bool CheckRange(const string& range, const string& a); 

		//ִ��task
		int DoTask(CTransFiberTaskInfo task);

		int DoTaskNew(CTransFiberTaskInfo task);

	/* */
	private:
		//keyΪIP��ַ��valueΪsnmpȡ��ʵ��
		map<string,CSnmpWrapper> snmp_map;

		TemplateMutexCatch<CTransFiberTaskInfo> task_list;

	/* */
	public:
		vector<string> m_csv_data;
		string m_csv_filename;


};
#endif
