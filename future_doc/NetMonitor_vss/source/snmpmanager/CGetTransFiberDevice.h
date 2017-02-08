/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	CGetTransFiberDevice.h
///@brief	定义了CGetTransFiberDevice使用的类
///@history
///20130318	LSC		创建该文件
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
	POWER_TYPE_MASTER, //骨干光功率
	POWER_TYPE_SLAVE, //客户侧光功率
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

///WALK返回结果容器
typedef CDPWALK_RESULT	WALK_RESULT;

///CDPWALK返回结果迭代器
typedef WALK_RESULT::iterator WALK_RESULT_ITERATOR;


/// CSnmpTaskInfo 定义了SNMP指标任务信息体
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
	int TaskStatus; //任务状态
};

class CTransFibertConfig
{
public:
	string ip;
	string locate;
	string rang_m;
	string rang_s;
	list<string>  in_list[3]; //记录端口索引号，in_list[0]表示骨干，其它表示连接客户侧的端口
	list<string>	  in_Number[3]; //标示上述端口所属编号，一一对应
};


class CGetTransFiberDevice:public CThread
{
	/* */
	public:

		///构造函数
		CGetTransFiberDevice()
		{
			m_csv_filename="";
		}

		///析构函数
		~CGetTransFiberDevice(void)
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

		//从csv文件读行数据
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

		//执行task
		int DoTask(CTransFiberTaskInfo task);

		int DoTaskNew(CTransFiberTaskInfo task);

	/* */
	private:
		//key为IP地址，value为snmp取数实体
		map<string,CSnmpWrapper> snmp_map;

		TemplateMutexCatch<CTransFiberTaskInfo> task_list;

	/* */
	public:
		vector<string> m_csv_data;
		string m_csv_filename;


};
#endif
