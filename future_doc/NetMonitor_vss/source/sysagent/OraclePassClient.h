/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	OraclePassClient.h
///@brief	向OraclePass服务器发送请求，获取进行真正的数据库连接所需要的参数
///@history
///20080825	武玉波		创建该文件
/////////////////////////////////////////////////////////////////////////
#ifndef _ORACLE_INFO_EXTRACT_H_
#define _ORACLE_INFO_EXTRACT_H_

#include <stdlib.h>
#include <string.h>
#include "xmlcfg.h" // for CDBConnectString
class COraclePassClient
{
	/* */
	public:
		COraclePassClient(void);

		// 不需要显式的 descontructor

	//~COraclePassClient();
	private:
		list<CBNSInfo>	m_lbns;

		string	m_key;

		void DecryptPwd(char *pInput, char *pOutput) const;

	/* */
	public:
		/**获取数据库连接信息
	* @param  req	输入参数  提供访问OraclePass服务器的必要信息
	*		req.szServerIP  BNS(OraclePass)服务器地址
	*		req.iPort		BNS服务器端口
	*		req.szEnv		环境：Product, 生产; Testing, 测试; Develop, 开发。
	*		req.szDBName	数据库名,NGES中指BDB或SDB,比如BDB/SDB/HDB/RDB等。
	*		req.szDBUser	指定数据库用户

	* @param  CDBConnectString 输出参数 记录一个数据库帐号的ip port databaseName username userpassword
	*
	* @return 	0 成功 非零表示失败，取值如下
	*   ERR_InvalidRequest=1  配置文件设置不正确或输入参数未正确填写
	*   ERR_ConnectError=2    连接密码服务器错误
	*   ERR_AccessDenied=10   客户端无访问数据库的权限
	*   ERR_UserNotFound=11   对应的用户不存在
	*   ERR_NoResource=21     资源不足
	*   ERR_InvalidCmd=22     错误的访问指令
	*   ERR_ParseError=23     解析错误
	*   ERR_Unknown=99        其它错误	
	**/
		int GetOracleAccountInfo(
				const CRequestInfo	&req,
				CDBConnectInfo	&dbInfo);

		///增加BNS连接地址函数
			///@param	sServerIP	BNS服务器的IP地址
			///@param	sPort		BNS服务器的端口号
		void InsertBNSInfo(string sServerIP, int nPort)
		{
			m_lbns.push_back(CBNSInfo(sServerIP, nPort));
		}
};
#endif // end of _ORACLE_INFO_EXTRACT_H_
