!!function!!
#include <set>
using namespace std;

struct ltstr
{
	bool operator()(const char* s1, const char* s2) const
	{
		return strcmp(s1, s2) < 0;
	}
};

typedef set<char *, ltstr> CPackageSet;
CPackageSet g_setUsePackage;

bool InUse(char *name)
{
	return (g_setUsePackage.find(name)!=g_setUsePackage.end());
}

!!endfunction!!
!!enter sysuserapi!!
!!travel self!!	
!!command g_setUsePackage.insert(@name);!!
!!next!!
!!leave!!
/////////////////////////////////////////////////////////////////////////
///@system 新一代交易所系统风险监控系统
///@company 上海期货信息技术有限公司
///@file FtdcSysUserApi.h
///@brief 定义了客户端接口
///@history 
///20070227	zhangjie		创建该文件
/////////////////////////////////////////////////////////////////////////

#if !defined(_FTDCSYSUSERAPI_H)
#define _FTDCSYSUSERAPI_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FtdcSysUserApiStruct.h"

#if defined(ISLIB) && defined(WIN32)
#ifdef LIB_SYSUSER_API_EXPORT
#define SYSUSER_API_EXPORT __declspec(dllexport)
#else
#define SYSUSER_API_EXPORT __declspec(dllimport)
#pragma comment(lib, "sysuserapi.lib")
#endif
#else
#define SYSUSER_API_EXPORT 
#endif

!!enter FTD!!
class CShfeFtdcSysUserSpi
{
public:
	///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
	virtual void OnFrontConnected(){};
	
	///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
	///@param nReason 错误原因
	///        0x1001 网络读失败
	///        0x1002 网络写失败
	///        0x2001 接收心跳超时
	///        0x2002 发送心跳失败
	///        0x2003 收到错误报文
	virtual void OnFrontDisconnected(int nReason){};
		
	///心跳超时警告。当长时间未收到报文时，该方法被调用。
	///@param nTimeLapse 距离上次接收报文的时间
	virtual void OnHeartBeatWarning(int nTimeLapse){};
	
!!travel packages!!
!!if InUse(@name)!!
!!if !strncmp(@name,"Rsp",3)!!

	///!!@comment!!
	virtual void On!!@name!!(!!travel self!!!!if @pumpid!=0!!, !!endif!!CShfeFtdc!!@name!!Field *p!!@name!!!!next!!, int nRequestID, bool bIsLast) {};
!!elseif !strncmp(@name,"Rtn",3)!!

	///!!@comment!!
	virtual void On!!@name!!(!!travel self!!!!if @pumpid!=0!!, !!endif!!CShfeFtdc!!@name!!Field *p!!@name!!!!next!!) {};
!!endif!!
!!endif!!
!!next!!
};

class SYSUSER_API_EXPORT CShfeFtdcSysUserApi
{
public:
	///创建SysUserApi
	///@param pszFlowPath 存贮订阅信息文件的目录，默认为当前目录
	///@return 创建出的UserApi
	static CShfeFtdcSysUserApi *CreateFtdcSysUserApi(const char *pszFlowPath = "");
	
	///删除接口对象本身
	///@remark 不再使用本接口对象时,调用该函数删除接口对象
	virtual void Release() = 0;
	
	///初始化
	///@remark 初始化运行环境,只有调用后,接口才开始工作
	virtual void Init() = 0;
	
	///等待接口线程结束运行
	///@return 线程退出代码
	virtual int Join() = 0;
	
	///获取当前交易日
	///@retrun 获取到的交易日
	///@remark 只有登录成功后,才能得到正确的交易日
	virtual const char *GetTradingDay() = 0;
	
	///注册前置机网络地址
	///@param pszFrontAddress：前置机网络地址。
	///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。 
	///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
	virtual void RegisterFront(char *pszFrontAddress) = 0;
	
	///注册回调接口
	///@param pSpi 派生自回调接口类的实例
	virtual void RegisterSpi(CShfeFtdcSysUserSpi *pSpi) = 0;
	
	///订阅市场行情。
	///@param nTopicID 市场行情主题  
	///@param nResumeType 市场行情重传方式  
	///        TERT_RESTART:从本交易日开始重传
	///        TERT_RESUME:从上次收到的续传
	///        TERT_QUICK:先传送当前行情快照,再传送登录后市场行情的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
	virtual void SubscribeMarketDataTopic(int nTopicID, TE_RESUME_TYPE nResumeType) = 0;
	
	///订阅会员实时资金状况。
	///@remark 该方法要在Init方法前调用。若不调用则不会收到数据。
	virtual void SubscribePartAccount(void) = 0;

	///用户登录请求
	virtual int ReqUserLogin(CShfeFtdcReqUserLoginField *pReqUserLoginField, int nRequestID) = 0;
	
!!travel packages!!
!!if InUse(@name)!!
!!if !strncmp(@name,"Req",3) && strcmp(@name,"ReqUserLogin") && strcmp(@name,"ReqQrySpecialPart") && strcmp(@name,"ReqQrySpecialClient") && strcmp(@name,"ReqQryInstPositionRate") && strcmp(@name, "ReqSimulateStressTest") && strcmp(@name,"ReqMarketStressTest") && strcmp(@name,"ReqQryInstPosiOverLmt")!!

	///!!@comment!!
	virtual int !!@name!!(!!travel self!!!!if @pumpid!=0!!, !!endif!!CShfeFtdc!!@name!!Field *p!!@name!!!!next!!, int nRequestID) = 0;
!!endif!!
!!endif!!
!!next!!


protected:
	~CShfeFtdcSysUserApi(){};
};
!!leave!!  

#endif
