/////////////////////////////////////////////////////////////////////////
///@system	������ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CNetTop.h
///@brief	������һ�������������
///@history
///20110505	LSC		�������ļ�
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
