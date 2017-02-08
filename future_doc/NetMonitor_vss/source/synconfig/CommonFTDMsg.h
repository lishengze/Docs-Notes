/////////////////////////////////////////////////////////////////////////
///@system 网络监控系统
///@company 上海期货信息技术有限公司
///@file CommonFTDMsg.h
///@brief 定义了一些通用的FTD消息
///@history
///20110531	李志伟   创建该文件
/////////////////////////////////////////////////////////////////////////
#ifndef __COMMON_FTDMSG_H
#define __COMMON_FTDMSG_H

#include <PrjCommon.h>
#include <FtdData.h>
#include <FTDCPackage.h>
#include <FTDCSession.h>

class CCommonFTDRsp
{
	/* */
	public:
		~CCommonFTDRsp(void)
		{
		}

		static CCommonFTDRsp  *Instance(void);

		/**发送带CFTDRspInfoField，标志成功的package，并且该pkg是会话的最后一个响应包。
    * @param session 发送package的会话
    * @param rsp 要发送的package
    * @param req 当前package所响应的请求
    * @param pkgID 当前package的ID
    * @param msg 当前package的ID
    */
		void SendSuccRsp(
				CFTDCSession *session,
				CFTDCPackage *rsp,
				CFTDCPackage *req,
				DWORD pkgID,
				const char	*msg = NULL);

		/**发送带CFTDRspInfoField，标志失败的package，该pkg不是会话的最后一个响应包。
    * @param session 发送package的会话
    * @param rsp 要发送的package
    * @param req 当前package所响应的请求
    * @param pkgID 当前package的ID
    * @param msg 当前package的ID
    */
		void SendContinueErroRsp(
				CFTDCSession *session,
				CFTDCPackage *rsp,
				CFTDCPackage *req,
				DWORD pkgID,
				const char	*msg = NULL);

		/**发送带CFTDRspInfoField，标志失败的package，并且该pkg是会话的最后一个响应包。
    * @param session 发送package的会话
    * @param rsp 要发送的package
    * @param req 当前package所响应的请求
    * @param pkgID 当前package的ID
    * @param msg 当前package的ID
    */
		void SendLastErroRsp(
				CFTDCSession *session,
				CFTDCPackage *rsp,
				CFTDCPackage *req,
				DWORD pkgID,
				const char	*msg = NULL);

	/* */
	private:

		///构造函数
		CCommonFTDRsp(void)
		{
			initDefaultInfo();
		}

		///初始化默认数据
		void initDefaultInfo(void);

		void SendErroRsp(
				CFTDCSession *session,
				CFTDCPackage *rsp,
				CFTDCPackage *req,
				DWORD pkgID,
				BYTE chain,
				const char	*msg);

	/* */
	private:
		///CCommonFTDRsp单件对象
		static CCommonFTDRsp m_obj;
};
#endif //__COMMON_FTDMSG_H
