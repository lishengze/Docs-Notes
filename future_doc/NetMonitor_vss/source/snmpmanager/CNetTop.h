/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	CNetTop.h
///@brief	定义了一般的网络拓扑类
///@history
///20110505	LSC		创建该文件
/////////////////////////////////////////////////////////////////////////
#pragma once

//#include "manager.hpp"
class CNetTop
{
	/* */
	public:
		CNetTop(void);
		~ CNetTop(void);

		int SearchTopologyRelation(void);

	/* */
	private:
		void cdp_Top_network(void);
		void gen_Top_network(void);
};
