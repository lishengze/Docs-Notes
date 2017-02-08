/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CPerformanceAnalyze.h
///@brief	������ǰ�ý����������ܷ�������
///@history
///20131204	����			�������ļ�

#ifndef REF_PERFORMANCEANALYZE_H
#define REF_PERFORMANCEANALYZE_H

#include "public.h"
#include "systools.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "CTimePolicy.h"
#include "UFEntityCopy.h"
#include "FrontServer.h"

// ����ÿ��ָ�꣬��������ʱ��
// ��ǰ����Ϊ�������15�����ڵ�����
#define MAX_ATTR_SAVEDTIME 15 * 60

// �ڲ��Ҷ���IDʱ����û�ж��ķ���-1
#define NONESubscription -1

// ����PerformanceTop������Я���Ĳ������Ͷ���
#define PA_HISTORY 0			// ��ѯ��ʷ���ݣ������ݿ��л�ȡ
#define PA_ADD_REALTIME_SUB 1	// ��ѯʵʱ���ݣ��ӱ��ػ����л�ȡ
#define PA_DEL_REALTIME_SUB 2	// ɾ��һ��ʵʱ���ܶ�������

// ����ָ�������λ֮��Ĺ�ϵ
// ��ǰ������3��ָ�꣬ʹ��char���㹻
// ������ָ���������ӣ�������int��
#define ATTR_NONE 0x0		// ������:0000
#define ATTR_MEMUSAGE 0x1		// ������:0001
#define ATTR_CPUUSAGE 0x2		// ������:0010
#define ATTR_ResSessAll 0x4		// ������:0100

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
// ָ��ֵ�ṹ�����ڱ���һ��ʱ���ڽ��յ�������ָ����Ϣ
// ͬʱ���������ʱ���ڵ����ֵ��ƽ��ֵ����Сֵ
// �ö�������ָ�������޹ص�
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

	// ��ָ��ֵ�������������
	void add(float _val, time_t _time);
	// ���¶����е�����
	void UpdateValues();

	float GetMax();
	float GetAvg();
	float GetMin();
private:
	bool m_valid;
	float m_MaxValue;		// MaxValue
	float m_AvgValue;		// AvgValue
	float m_MinValue;		// MinValue
	vector<ValuePair > m_Values;	// ָ��ֵ����
};

// ����һ���豸��Ϣ��ָ����Ϣ
class DeviceAttrInfo
{
public:
	DeviceAttrInfo();
	~DeviceAttrInfo();
public:
	void addAttrValue(string _attrType, float _val, time_t _time);

	// ���¸��豸�ĸ�ָ��ֵ��Ϣ
	// ĳָ���ƽ��ֵ����Сֵ�����ֵ����Ϊ�ϴθ���ʱ�̵�ֵ
	void updateAttrValue();

	// ���¸��豸��ָ����ָ��ֵ��Ϣ
	void updateAttrValue(const char* _attrType);

	// ��ȡָ������Ϊ_attrType�����ֵ
	// ���ҵ�������ֵΪtrue��_val�б����Ӧ��ֵ
	// ���򷵻�false
	bool GetMax(const char* _attrType, float &_val);
	bool GetAvg(const char* _attrType, float &_val);
	bool GetMin(const char* _attrType, float &_val);
public:
	int m_SubAreaID;	// �豸����������ID
	string m_ObjectID;	// ObjectID
	string m_IpAddress;	// �豸��IP��ַ

	// �豸ָ��ֵ������
	CMutex m_lock;
	// �����ָ��ľ���ֵ
	// key��ָ������
	// value����ָ���Ӧ������
	map <string, ObjectAttrValue* > m_AttrValues;
};

// ���ܶ���
// ÿһ�����������һ��������������ܶ�����Ϣ
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
		
		// ֻɾ��ָ�룬����ִ��delete�������������������е��豸��ϢʧЧ
		m_ContainedDevices.clear();

		m_PerformanceResults.clear();
	}
public:
	// ��ȡ�ö��ĵ�ָ������
	const char* GetAttrType() { return m_Field.AttrType.getValue(); }

	int GetSortValueType() { return m_Field.SortValue.getValue(); }
	int GetTopNumber() { return m_Field.TopN.getValue(); }

	// Ϊ�ö������һ���Ự
	void AddSubscriptionSession(DWORD _session);
	// Ϊ�ö���ɾ��һ���Ự
	void DelSubscriptionSession(DWORD _session);

	bool CompareSubscription(CFTDReqQryPerformanceTopField field);
	bool CompareSubscription(CFTDRspQryPerformanceTopField field);

	// ����������������Ϣ
	void AddDeviceAttrValue(DeviceAttrInfo* pDevice, float _value);
	// �����������ɾ��ĳ���豸��ָ����Ϣ
	void DelDeviceAttrValue(DeviceAttrInfo* pDevice);
	// �Ӹö�����ɾ���豸��Ϣ���������еĸ��豸��Ϣ
	void DelDevice(DeviceAttrInfo* pDevice);

	// ���
	void PrintSubscription();

	// ���ݶ��ĵ���������һ����ʶ�ַ���
	string GetSubKey();

	void PrintSubResults();
public:
	// ���涩�ĵľ�����Ϣ
	CFTDReqQryPerformanceTopField m_Field;
	
	// �����˸�ָ��Ŀͻ���SessionID
	vector<DWORD > m_ClientSessions;

	// �ö��������ǵ������豸���豸ID
	vector<DeviceAttrInfo* > m_ContainedDevices;

	// �ö��ĵĵ�ǰ�����������ն���ָ��������ʽ����
	// pair< device, value >
	vector< pair<DeviceAttrInfo*, float> > m_PerformanceResults;
};

/************************************************************************
* �������ܷ������߳�
* ���̵߳�������ά���豸ָ����Ϣ���жϳ�ʱ�豸��ά��ÿ�����ĵ����ܽ��
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
	/**�麯�����������һЩʵ��������
	* @return true:�����ɹ� false:����ʧ��
	*/
		virtual bool InitInstance(void);	//todo

	/**�麯�����������ʵ��
	*/
		virtual void ExitInstance(void);	//todo

		/**�߳̿�ʼ���У����麯�����������̳�ʵ��
	*/
		virtual void Run(void);				//todo

public:
	void SetSubscriptionList(vector<CPerformanceSubscription* >* p) { m_Subscriptions = p; }

private:
	/* ָ��CPerformanceAnalyzer�еĳ�Ա���� */
	vector<CPerformanceSubscription* >* m_Subscriptions;
};

// �������ܷ���������
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
	// ���ñ�����Ϣ�������������������
	void UpdateNetArea(const CFTDRtnGeneralOperateField &field);
	// ���ñ�����Ϣ������������豸����
	void UpdateNetDevice(const CFTDRtnNetDeviceField &field);

public:

	// �������ݷ����߳�
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

	// ��������������ر��ģ����ڸ���������豸������Ϣ
	void UpdateNetConfig(CFTDCPackage *pFTDCPackage);

	// ����ָ����Ϣ��ͨ�汨��
	void OnRtnObjectAttrTopic(CFTDCPackage *pRtnFTDCPackage);

	// ���¸�ָ���������
	void UpdateSubscriptionResult();

	// ����һ��ʵʱ���ܷ�������
	// QryField: ���������
	// nSessionID: �����SessionID
	bool AddSubscription(CFTDReqQryPerformanceTopField QryField, CFTDCSession *pSession);

	// ɾ��һ������
	void DelSubscription(CFTDReqQryPerformanceTopField QryField, CFTDCSession *pSession);

	// ���ͻ��˶Ͽ�����ʱ��ɾ���Ự
	void RemoveClientSession(DWORD dSession);

	// �鿴ĳ�豸�Ƿ�����ĳ���ĵķ�Χ֮��
	// nDevice���豸ID��nSubID������ID
	bool isDeviceInSubscription(DeviceAttrInfo* pDevice, CPerformanceSubscription* pSub);

	// ��ĳ���ĵĽ��ͨ��Rtn����ͨ��ͻ���
	void NotifyClients(CPerformanceSubscription* pSub);

	// �������ж�����Ϣ����ĳ���ĵĻỰ�б�Ϊ�գ���ɾ������
	void RemoveInvalidSubscription();

private:
	///�������ݰ�ʹ�õĻ�����
	CFTDCPackage m_pkgSend;

	///ǰ�û��Կͻ��˵�SESSION
	CFrontServer *m_pFrontServer;

	// ���ڹ�����߳�
	CPerformanceAnalyzeThread* m_AnalyzeThread;

	// ����ʱ����Ϣ
	CDateTime m_Timer;

	// ������Ϣ�ڶ���߳��б����ʣ���Ҫ�������
	CMutex m_SubLock;
	// ���浱ǰ���еĶ���
	vector<CPerformanceSubscription* > m_Subscriptions;

	// �����豸��ObjectID���豸��Ϣ֮���MAP
	// �ṹ���������豸��Ϣ
	// ÿһ���豸��Ϣ��ά���˶���ʱ���ڵ�����ָ��ֵ
	map<string, DeviceAttrInfo* > m_ObjectIDtoDeviceMAP;
	
	// ���浱ǰ�����ڵ����绮������
	// key: NetSubAreaID������ID���磺9
	// value: <����ID, ����Ӣ����>����<1, YW1>
	map<int, pair<int, string> > m_NetAreaConfig;
};

#endif	// REF_PERFORMANCEANALYZE_H END