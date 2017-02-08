/////////////////////////////////////////////////////////////////////////
///@system ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CommonFTDMsg.h
///@brief ������һЩͨ�õ�FTD��Ϣ
///@history
///20110531	��־ΰ   �������ļ�
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

		/**���ʹ�CFTDRspInfoField����־�ɹ���package�����Ҹ�pkg�ǻỰ�����һ����Ӧ����
    * @param session ����package�ĻỰ
    * @param rsp Ҫ���͵�package
    * @param req ��ǰpackage����Ӧ������
    * @param pkgID ��ǰpackage��ID
    * @param msg ��ǰpackage��ID
    */
		void SendSuccRsp(
				CFTDCSession *session,
				CFTDCPackage *rsp,
				CFTDCPackage *req,
				DWORD pkgID,
				const char	*msg = NULL);

		/**���ʹ�CFTDRspInfoField����־ʧ�ܵ�package����pkg���ǻỰ�����һ����Ӧ����
    * @param session ����package�ĻỰ
    * @param rsp Ҫ���͵�package
    * @param req ��ǰpackage����Ӧ������
    * @param pkgID ��ǰpackage��ID
    * @param msg ��ǰpackage��ID
    */
		void SendContinueErroRsp(
				CFTDCSession *session,
				CFTDCPackage *rsp,
				CFTDCPackage *req,
				DWORD pkgID,
				const char	*msg = NULL);

		/**���ʹ�CFTDRspInfoField����־ʧ�ܵ�package�����Ҹ�pkg�ǻỰ�����һ����Ӧ����
    * @param session ����package�ĻỰ
    * @param rsp Ҫ���͵�package
    * @param req ��ǰpackage����Ӧ������
    * @param pkgID ��ǰpackage��ID
    * @param msg ��ǰpackage��ID
    */
		void SendLastErroRsp(
				CFTDCSession *session,
				CFTDCPackage *rsp,
				CFTDCPackage *req,
				DWORD pkgID,
				const char	*msg = NULL);

	/* */
	private:

		///���캯��
		CCommonFTDRsp(void)
		{
			initDefaultInfo();
		}

		///��ʼ��Ĭ������
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
		///CCommonFTDRsp��������
		static CCommonFTDRsp m_obj;
};
#endif //__COMMON_FTDMSG_H
