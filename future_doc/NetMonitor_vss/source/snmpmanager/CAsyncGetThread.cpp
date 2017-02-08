/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	CAyncGetThread.cpp
///@brief	实现了CAyncGetThread使用的类
///@history
///20100920	周建军		创建该文件
#include "CAsyncGetThread.h"

/**虚函数，子类可做一些实例化工作
* @return true:创建成功 false:创建失败
*/
bool CAyncGetThread::InitInstance(void)
{
	return true;
}

/**虚函数，子类清楚实例
*/
void CAyncGetThread::ExitInstance(void)
{
}

/**线程开始运行，纯虚函数，子类必须继承实现
*/
void CAyncGetThread::Run(void)
{
	while (1)
	{
		time_t	timep;
		time(&timep);
#ifdef PACKAGE_OUTPUT
		//printf("\t start %s ", ctime(&timep));
		//printf("start m_nThreadNum %d\n", m_nThreadNum);
#endif

		// 循环开始则先处理队列中的增加设备监控OID
		//getMonDevice();
		//getMonDeviceNew();
		m_cAsyncIns.startAllHost((int)(timep));
		m_cAsyncIns.run((int)(timep));

		//m_cAsyncIns.genDataField( datas );
#ifdef PACKAGE_OUTPUT
		time(&timep);

		//printf("\t end   %s ", ctime(&timep));
		//printf("end   m_nThreadNum %d\n\n\n", m_nThreadNum);
#endif
		SLEEP(2 * 1000);
	}
}

void CAyncGetThread::GetSpi(void)
{
	return;
}
