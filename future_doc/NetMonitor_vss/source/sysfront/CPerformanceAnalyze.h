/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CPerformanceAnalyze.h
///@brief	定义了前置进行网络性能分析的类
///@history
///20131204	曹宁			创建该文件

#ifndef REF_PERFORMANCEANALYZE_H
#define REF_PERFORMANCEANALYZE_H

#include "public.h"
#include "systools.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "CTimePolicy.h"
#include "UFEntityCopy.h"
#include "FrontServer.h"

// 对于每个指标，保存的最大时间
// 当前定义为保存最近15分钟内的数据
#define MAX_ATTR_SAVEDTIME 15 * 60

// 在查找订阅ID时，若没有订阅返回-1
#define NONESubscription -1

// 对于PerformanceTop报文中携带的操作类型定义
#define PA_HISTORY 0			// 查询历史数据，从数据库中获取
#define PA_ADD_REALTIME_SUB 1	// 查询实时数据，从本地缓冲中获取
#define PA_DEL_REALTIME_SUB 2	// 删除一个实时性能订阅请求

// 订阅指标与比特位之间的关系
// 当前仅订阅3个指标，使用char型足够
// 后续若指标类型增加，可以用int型
#define ATTR_NONE 0x0		// 二进制:0000
#define ATTR_MEMUSAGE 0x1		// 二进制:0001
#define ATTR_CPUUSAGE 0x2		// 二进制:0010
#define ATTR_ResSessAll 0x4		// 二进制:0100

typedef struct ValuePair
{
	ValuePair(float _val, time_t _time)
	{
		m_value = _val;
		m_time = _time;
	}
	float m_value;
	time_t m_time;
} ValuePair;
// 指标值结构，用于保存一段时间内接收到的所有指标信息
// 同时保存在这段时间内的最大值，平均值和最小值
// 该对象是与指标类型无关的
class ObjectAttrValue
{
public:
	ObjectAttrValue()
	{
		m_valid = false;
		m_MaxValue = 0.0;
		m_AvgValue = 0.0;
		m_MinValue = FLT_MAX;
	}
public:
	bool isValid() { return m_valid; }

	// 向指标值队列中添加数据
	void add(float _val, time_t _time);
	// 更新队列中的数据
	void UpdateValues();

	float GetMax();
	float GetAvg();
	float GetMin();
private:
	bool m_valid;
	float m_MaxValue;		// MaxValue
	float m_AvgValue;		// AvgValue
	float m_MinValue;		// MinValue
	vector<ValuePair > m_Values;	// 指标值队列
};

// 保存一个设备信息和指标信息
class DeviceAttrInfo
{
public:
	DeviceAttrInfo();
	~DeviceAttrInfo();
public:
	void addAttrValue(string _attrType, float _val, time_t _time);

	// 更新该设备的各指标值信息
	// 某指标的平均值、最小值和最大值，均为上次更新时刻的值
	void updateAttrValue();

	// 更新该设备的指定的指标值信息
	void updateAttrValue(const char* _attrType);

	// 获取指标名称为_attrType的最大值
	// 若找到，返回值为true，_val中保存对应的值
	// 否则返回false
	bool GetMax(const char* _attrType, float &_val);
	bool GetAvg(const char* _attrType, float &_val);
	bool GetMin(const char* _attrType, float &_val);
public:
	int m_SubAreaID;	// 设备所属的子网ID
	string m_ObjectID;	// ObjectID
	string m_IpAddress;	// 设备的IP地址

	// 设备指标值队列锁
	CMutex m_lock;
	// 保存各指标的具体值
	// key：指标名称
	// value：该指标对应的数据
	map <string, ObjectAttrValue* > m_AttrValues;
};

// 性能订阅
// 每一个对象代表了一个具体的网络性能订阅信息
class CPerformanceSubscription
{
public:
	CPerformanceSubscription()
	{
		memset(&m_Field, 0, sizeof(CFTDReqQryPerformanceTopField));
	}
	~CPerformanceSubscription()
	{
		m_ClientSessions.clear();
		
		// 只删除指针，不能执行delete，否则会造成其他订阅中的设备信息失效
		m_ContainedDevices.clear();

		m_PerformanceResults.clear();
	}
public:
	// 获取该订阅的指标名称
	const char* GetAttrType() { return m_Field.AttrType.getValue(); }

	int GetSortValueType() { return m_Field.SortValue.getValue(); }
	int GetTopNumber() { return m_Field.TopN.getValue(); }

	// 为该订阅添加一个会话
	void AddSubscriptionSession(DWORD _session);
	// 为该订阅删除一个会话
	void DelSubscriptionSession(DWORD _session);

	bool CompareSubscription(CFTDReqQryPerformanceTopField field);
	bool CompareSubscription(CFTDRspQryPerformanceTopField field);

	// 向排序队列中添加信息
	void AddDeviceAttrValue(DeviceAttrInfo* pDevice, float _value);
	// 从排序队列中删除某个设备的指标信息
	void DelDeviceAttrValue(DeviceAttrInfo* pDevice);
	// 从该订阅中删除设备信息和排序结果中的该设备信息
	void DelDevice(DeviceAttrInfo* pDevice);

	// 输出
	void PrintSubscription();

	// 根据订阅的条件生成一个标识字符串
	string GetSubKey();

	void PrintSubResults();
public:
	// 保存订阅的具体信息
	CFTDReqQryPerformanceTopField m_Field;
	
	// 订阅了该指标的客户端SessionID
	vector<DWORD > m_ClientSessions;

	// 该订阅所覆盖的所有设备的设备ID
	vector<DeviceAttrInfo* > m_ContainedDevices;

	// 该订阅的当前排序结果，按照订阅指定的排序方式排序
	// pair< device, value >
	vector< pair<DeviceAttrInfo*, float> > m_PerformanceResults;
};

/************************************************************************
* 用于性能分析的线程
* 该线程的作用是维护设备指标信息、判断超时设备、维护每个订阅的性能结果
************************************************************************/
class CPerformanceAnalyzeThread : public CThread
{
public:
	CPerformanceAnalyzeThread()
	{
		m_Subscriptions = NULL;
	}
	~CPerformanceAnalyzeThread()
	{

	}
public:
	/**虚函数，子类可做一些实例化工作
	* @return true:创建成功 false:创建失败
	*/
		virtual bool InitInstance(void);	//todo

	/**虚函数，子类清楚实例
	*/
		virtual void ExitInstance(void);	//todo

		/**线程开始运行，纯虚函数，子类必须继承实现
	*/
		virtual void Run(void);				//todo

public:
	void SetSubscriptionList(vector<CPerformanceSubscription* >* p) { m_Subscriptions = p; }

private:
	/* 指向CPerformanceAnalyzer中的成员变量 */
	vector<CPerformanceSubscription* >* m_Subscriptions;
};

// 网络性能分析管理类
class CPerformanceAnalyzer
{
public:
	CPerformanceAnalyzer()
	{
		m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
		m_AnalyzeThread = NULL;
	}
	~CPerformanceAnalyzer()
	{
	}

	void SetFrontServer(CFrontServer *pFrontServer)
	{
		m_pFrontServer = pFrontServer;
	} 

private:
	// 利用报文信息，更新网络的区域配置
	void UpdateNetArea(const CFTDRtnGeneralOperateField &field);
	// 利用报文信息，更新网络的设备配置
	void UpdateNetDevice(const CFTDRtnNetDeviceField &field);

public:

	// 启动数据分析线程
	void ThreadCheck()
	{
		if (!m_AnalyzeThread)
		{
			m_AnalyzeThread = new CPerformanceAnalyzeThread();
			m_AnalyzeThread->SetSubscriptionList(&m_Subscriptions);
			m_AnalyzeThread->Create();
			printf("Performance Analyze Thread Start!\n");
		}
	}

	// 处理网络配置相关报文，用于更新网络和设备配置信息
	void UpdateNetConfig(CFTDCPackage *pFTDCPackage);

	// 处理指标信息的通告报文
	void OnRtnObjectAttrTopic(CFTDCPackage *pRtnFTDCPackage);

	// 更新各指标的排序结果
	void UpdateSubscriptionResult();

	// 增加一个实时性能分析订阅
	// QryField: 请求的内容
	// nSessionID: 请求的SessionID
	bool AddSubscription(CFTDReqQryPerformanceTopField QryField, CFTDCSession *pSession);

	// 删除一个订阅
	void DelSubscription(CFTDReqQryPerformanceTopField QryField, CFTDCSession *pSession);

	// 当客户端断开连接时，删除会话
	void RemoveClientSession(DWORD dSession);

	// 查看某设备是否属于某订阅的范围之内
	// nDevice：设备ID；nSubID：订阅ID
	bool isDeviceInSubscription(DeviceAttrInfo* pDevice, CPerformanceSubscription* pSub);

	// 将某订阅的结果通过Rtn报文通告客户端
	void NotifyClients(CPerformanceSubscription* pSub);

	// 遍历所有订阅信息，若某订阅的会话列表为空，则删除订阅
	void RemoveInvalidSubscription();

private:
	///发送数据包使用的缓冲区
	CFTDCPackage m_pkgSend;

	///前置机对客户端的SESSION
	CFrontServer *m_pFrontServer;

	// 用于管理的线程
	CPerformanceAnalyzeThread* m_AnalyzeThread;

	// 保存时间信息
	CDateTime m_Timer;

	// 订阅信息在多个线程中被访问，需要互斥访问
	CMutex m_SubLock;
	// 保存当前所有的订阅
	vector<CPerformanceSubscription* > m_Subscriptions;

	// 保存设备的ObjectID与设备信息之间的MAP
	// 结构化的网络设备信息
	// 每一个设备信息中维护了定义时间内的所有指标值
	map<string, DeviceAttrInfo* > m_ObjectIDtoDeviceMAP;
	
	// 保存当前网络内的网络划分配置
	// key: NetSubAreaID，子网ID，如：9
	// value: <网络ID, 子网英文名>，如<1, YW1>
	map<int, pair<int, string> > m_NetAreaConfig;
};

#endif	// REF_PERFORMANCEANALYZE_H END