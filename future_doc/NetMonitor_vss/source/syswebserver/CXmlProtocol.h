/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CXmlProtocol.h
///@brief	定义了XML协议类
///@history 
///20080810	周建军		创建该文件

#ifndef REF_CXMLPROTOCOL_H
#define REF_CXMLPROTOCOL_H

#include "Protocol.h"
#include "CXmlPackage.h"

/**协议栈容器的第第三层协议，主要对FTDC包的处理
*/
class  CXmlProtocol : public CProtocol  
{
public:
	/**构造函数
	* @param pReactor 指向运行引擎的指针
	* @param pBelow    下层协议的指针
	* @param nActiveId 对下层协议而言，本层协议的协议Id
	*/
	CXmlProtocol(CReactor *pReactor)
		:CProtocol(pReactor, 20, new CXmlPackage(), new CXmlPackage())
	{
	}
	/**析构函数
	*/
	virtual ~CXmlProtocol() {}

	virtual int Pop(CPackage *pPackage)
	{
		printf("CXmlProtocol::Pop\n");
		return CProtocol::Pop(pPackage);
	}
	
	/**收到一个错误的数据包时调用
	* @param pPackage 错误的数据包
	* @return 0   成功
	* @return <>0 失败
	*/
	virtual int OnRecvErrorPackage(CPackage *pPackage)
	{
		printf("CXmlProtocol:OnRecvErrorPackage recv one wrong package\n");
		return 0;
	}

};

#endif

