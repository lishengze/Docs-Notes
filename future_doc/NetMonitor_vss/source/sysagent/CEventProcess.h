///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CEventProcess.h
///@brief	定义了采集代理处理日志中消息的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
#ifndef REF_CEVENTPROCESS_H
#define REF_CEVENTPROCESS_H
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"

/////////////////////////////////////////////////////////////////////////
///CFrontSessionKey定义了前置ID和席位类型ID作为map关键字的类
///@author	周建军
///@version	1.0,20080710
/////////////////////////////////////////////////////////////////////////
class CFrontSessionKey
{
	/* */
	public:
		///前置ID
		int m_nFID;

		///席位类型ID
		int m_nIPID;

	/* */
	public:

		///构造函数
		CFrontSessionKey(void)
		{
			m_nFID = 0;
			m_nIPID = 0;
		}

		///构造函数
			///@param	nFID	前置的ID
			///@param	nIPID	根据IP地址判断出来的席位类型ID
		CFrontSessionKey(int nFID, int nIPID)
		{
			m_nFID = nFID;
			m_nIPID = nIPID;
		}

		///拷贝构造函数
		CFrontSessionKey(const CFrontSessionKey &ob)
		{
			m_nFID = ob.m_nFID;
			m_nIPID = ob.m_nIPID;
		}

		///重载=运算符
		void operator=(const CFrontSessionKey &ob)
		{
			m_nFID = ob.m_nFID;
			m_nIPID = ob.m_nIPID;
		}

		///重载>运算符
		friend bool operator>(
		const CFrontSessionKey	&ob1,
		const CFrontSessionKey	&ob2)
		{
			if (ob1.m_nFID > ob2.m_nFID)
			{
				return true;
			}
			else if (ob1.m_nFID == ob2.m_nFID)
			{
				if (ob1.m_nIPID > ob2.m_nIPID)
				{
					return true;
				}
			}

			return false;
		}

		///重载>运算符
		friend bool operator < (const CFrontSessionKey &ob1, const CFrontSessionKey &ob2)
		{
			if (ob1.m_nFID < ob2.m_nFID)
			{
				return true;
			}
			else if (ob1.m_nFID == ob2.m_nFID)
			{
				if (ob1.m_nIPID < ob2.m_nIPID)
				{
					return true;
				}
			}

			return false;
		}

		///重载==运算符
		friend bool operator==(
		const CFrontSessionKey	&ob1,
		const CFrontSessionKey	&ob2)
		{
			if (ob1.m_nFID == ob2.m_nFID && ob1.m_nIPID == ob2.m_nIPID)
			{
				return true;
			}

			return false;
		}
};

/////////////////////////////////////////////////////////////////////////
///CTkernelIdKey定义了交易核心ID和数据中心名作为map关键字的类
///@author	周建军
///@version	1.0,20080710
/////////////////////////////////////////////////////////////////////////
class CTkernelIdKey
{
	/* */
	public:

		///构造函数
		CTkernelIdKey(void)
		{
			m_nTkernelID = 0;
			m_sDCName = "";
		}

		///构造函数
			///@param	nTkernelID	交易核心ID
			///@param	pDCName	数据中心名
		CTkernelIdKey(int nTkernelID, char *pDCName)
		{
			m_nTkernelID = nTkernelID;
			m_sDCName = pDCName;
		}

		///构造函数
			///@param	nTkernelID	交易核心ID
			///@param	pDCName	数据中心名
		CTkernelIdKey(int nTkernelID, const string &pDCName)
		{
			m_nTkernelID = nTkernelID;
			m_sDCName = pDCName;
		}

		///拷贝构造函数
		CTkernelIdKey(const CTkernelIdKey &ob)
		{
			m_nTkernelID = ob.m_nTkernelID;
			m_sDCName = ob.m_sDCName;
		}

		///重载=运算符
		void operator=(const CTkernelIdKey &ob)
		{
			m_nTkernelID = ob.m_nTkernelID;
			m_sDCName = ob.m_sDCName;
		}

		///重载>运算符
		friend bool operator>(
		const CTkernelIdKey &ob1,
		const CTkernelIdKey &ob2)
		{
			if (ob1.m_nTkernelID > ob2.m_nTkernelID)
			{
				return true;
			}
			else if (ob1.m_nTkernelID == ob2.m_nTkernelID)
			{
				if (ob1.m_sDCName > ob2.m_sDCName)
				{
					return true;
				}
			}

			return false;
		}

		///重载>运算符
		friend bool operator < (const CTkernelIdKey &ob1, const CTkernelIdKey &ob2)
		{
			if (ob1.m_nTkernelID < ob2.m_nTkernelID)
			{
				return true;
			}
			else if (ob1.m_nTkernelID == ob2.m_nTkernelID)
			{
				if (ob1.m_sDCName < ob2.m_sDCName)
				{
					return true;
				}
			}

			return false;
		}

		///重载==运算符
		friend bool operator==(
		const CTkernelIdKey &ob1,
		const CTkernelIdKey &ob2)
		{
			if (ob1.m_nTkernelID == ob2.m_nTkernelID
			&&	ob1.m_sDCName == ob2.m_sDCName)
			{
				return true;
			}

			return false;
		}

	/* */
	public:
		///交易核心的ID编号
		int m_nTkernelID;

		///数据中心的名称
		string	m_sDCName;
};

/////////////////////////////////////////////////////////////////////////
///CLoginSuccessValue定义了为map值的类
///@author	周建军
///@version	1.0,20080710
/////////////////////////////////////////////////////////////////////////
class CLoginSuccessValue
{
	/* */
	public:

		///构造函数
		CLoginSuccessValue(void)
		{
			m_nFrontID = 0;
			m_nSessionID = 0;
			m_nIpTypeID = -1;
		}

		///构造函数
			///@param	nFrontID	前置的ID
			///@param	nSessionID	登录的会话ID
			///@param	nTpTypeID	根据ip地址判断出来的席位类型ID
		CLoginSuccessValue(int nFrontID, int nSessionID, int nIpTypeID)
		{
			m_nFrontID = nFrontID;
			m_nSessionID = nSessionID;
			m_nIpTypeID = nIpTypeID;
		}

		///拷贝构造函数
		CLoginSuccessValue(const CLoginSuccessValue &ob)
		{
			m_nSessionID = ob.m_nSessionID;
			m_nFrontID = ob.m_nFrontID;
			m_nIpTypeID = ob.m_nIpTypeID;
		}

		///重载=运算符
		void operator=(const CLoginSuccessValue &ob)
		{
			m_nSessionID = ob.m_nSessionID;
			m_nFrontID = ob.m_nFrontID;
			m_nIpTypeID = ob.m_nIpTypeID;
		}

		///重载==运算符
		friend bool operator==(
		const CLoginSuccessValue &ob1,
		const CLoginSuccessValue &ob2)
		{
			if (ob1.m_nFrontID == ob2.m_nFrontID
			&&	ob1.m_nSessionID == ob2.m_nSessionID
			&&	ob1.m_nIpTypeID == ob2.m_nIpTypeID)
			{
				return true;
			}

			return false;
		}

	/* */
	public:
		///前置的ID
		int m_nFrontID;

		///登录的ID
		long m_nSessionID;

		///IP类型的ID,如场内、场外
		int m_nIpTypeID;
};

class CIPAnalysis
{
	/* */
	public:
		///构造函数
			///@param	pConfigPath	配置文件路径
		CIPAnalysis(char *pConfigPath);

		///初始化IP对应席位关系函数
			///@comment	调用getIpTypeID之前需先初始化
		bool init(void)
		{
			return true;
		}

		///根据IP地址判断席位类型函数
			///@param	pIpAddr	ip地址，如172.16.30.224
			///@return	返回该ip地址对应的席位类型
		int getIpTypeID(char *pIpAddr);

	/* */
	private:
		map<string, int> m_mapIpType;
};

class CEventProcess
{
	/* */
	public:

		///构造函数
		CEventProcess(void)
		{
			m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
			memset(&m_eventField, 0, sizeof(m_eventField));
		}

		///打印输出函数
		void Print(void);

		///事件周期统计分析函数
		void getPeriodStats(void);

		///统计输出当前mdkernel连接个数函数
		void getMdSessionSize(void);

		///分析事件函数
			///@param	pObjectID	对象ID信息串
			///@param	pMonDate 事件产生日期
			///@param	pMonTime 事件产生时间
			///@param	pEventName	事件名
			///@param	pEventDes	事件的描述信息
		void putEventReport(
			char *pObjectID,
			char *pMonDate,
			char *pMonTime,
			char *pEventName,
			char *pEventDes);

		///登录mdkernel成功事件处理函数
			///@param	pDCName	数据中心的名称
			///@param	pProgram	应用进程名称
			///@param	nTkernelID	交易核心的编号
			///@param	pValue	事件的指针
		void processMdLoginSuccess(
				const char	*pDCName,
				char *pProgram,
				int nTkernelId,
				char *value);

		///退出mdkernel成功事件处理函数
			///@param	pDCName	数据中心的名称
			///@param	pProgram	应用进程名称
			///@param	nTkernelID	交易核心的编号
			///@param	pValue	事件的指针
		void processMdLogOutSuccess(
				const char	*pDCName,
				char *pProgram,
				int nTkernelId,
				char *pValue);

	/* */
	protected:
	/* */
	private:
		///定义事件
		CFTDRtnSyslogEventField m_eventField;

		///用于发送数据包使用的缓冲区
		CFTDCPackage m_pkgSend;
};
#endif //REF_CEVENTPROCESS_H
