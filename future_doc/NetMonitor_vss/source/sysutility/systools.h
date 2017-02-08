/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	systools.h
///@brief	�����˽��׼��ϵͳ���õ���ͺ���
///@history
///20080510	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
#ifndef REF_SYSTOOLS_H
#define REF_SYSTOOLS_H

#include "public.h"
#include "utility.h"
#include "RefString.h"
#include "xmlcfg.h"
#include "SelectReactor.h"
#include "EventHandler.h"

#ifdef LINUX
#include <unistd.h>
#include <sys/syscall.h>
#endif
#ifdef ___DEBUG
#define PRINTF	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__)
#else
#define PRINTF
#endif
#ifdef WIN32
#define PATH_SEP	'\\'
#elif defined HP_UX || defined LINUX
#define PATH_SEP	'/'
#endif
inline void print_errmsg(
	const char	*pFile,
	const char	*pFunc,
	int iLine,
	const char *pMsg)
{
	char *p = (char *)strrchr(pFile, PATH_SEP);
	p = p == NULL ? (char *)pFile : p + 1;
	printf("%s:%s(%d) ERR[%s]\n", p, pFunc, iLine, pMsg);
	fflush(stdout);
}

#ifdef WIN32
#define INT64	LONGLONG
#define UINT64	ULONGLONG
#elif defined HP_UX
#define INT64	long long
#define UINT64	unsigned long long
#else
#define INT64	long
#define UINT64	unsigned long
#endif
#if !defined(PRINT_DEBUG)
#define PRINT_DEBUG
#endif
#if !defined(PACKAGE_OUTPUT)
#define PACKAGE_OUTPUT
#endif
#if !defined(REAL_HOSTNAME)
#define REAL_HOSTNAME
#endif
#undef REAL_HOSTNAME
#undef PRINT_DEBUG

//#undef PACKAGE_OUTPUT
#define SAFE_FCLOSE(x) \
	if (x != NULL)	   \
	{				   \
		fclose(x);	   \
		(x) = NULL;	   \
	}

#define ERR_SUCCESS				0				// �ɹ�
#define ERR_REACHMAXRECORDNUM	3				// ��ѯ���ؼ�¼���������
#define ERR_EXCEPTREQ			10				// ��ѯ���쳣���޷�����ֱ�ӷ����쳣

//2008.09.10 ad by wu.yb
#define DBMSG_SUC_SUCCESS			ERR_SUCCESS // �������ݿ�ɹ�������ǲ�ѯ��ʾ�м�¼
#define DBMSG_SUC_NORECORD			2			// ��ѯ���ݿ�ɹ�����û�м�¼
#define DBMSG_ERR_EXCEPTION			1			// ��ѯ���ݿⷢ���쳣
#define DBMSG_ERR_REACHMAXRECORDNUM ERR_REACHMAXRECORDNUM					// ��ѯ���ݿ⣬���صļ�¼̫�࣬�ﵽ����
#define DBMSG_SUC_RECORDEXISTS		4										// ��ʾ��¼����

//2009.01.06 add by zhou.jj
#define EVENT_DBCONNECT_ERROR	"DBConnectLost"								//���ݿ�û������
#define EVENT_DBEXESP_ERROR		"DBExeSPWrong"								//���ݿ����SP����
#define EVENT_DBGETLOG_ERROR	"DBGetLogWrong"								//���ݿ��ȡ��־��ʱ����
#define EVENT_NOMD5FILE_ERROR	"NotExistMd5File"							//�ļ���У�����ļ����ܴ�
#define EVENT_MD5CHECK_TIME		"MD5CheckTime"								//���һ��MD5У���¼�
#define EVENT_MD5CHECK_ERROR	"MD5CheckWrong"								//�ļ�У������鲻һ��
#define EVENT_MD5CHECK_SUCCESS	"MD5CheckSuccess"							//�ļ�У�������һ��
#define EVENT_WEBCHECK_ERROR	"WebCheckWrong"								//������ҳ������
#define EVENT_WEBCHECK			"WebCheck"									//���һ�β�����ҳУ���¼�

//2010.09.20 add by zhou.jj
#define EVENT_SNMP_GET_ERROR	"SnmpGetWrong"								//snmpget�������
	
	///20101102 Added by Henchi
#define EVENT_CHKVER_NOCHG		"CfgNoChange"
#define EVENT_CHKVER_CHANGE		"CfgChanged"
#define EVENT_BACKUP_SUCCEED	"BackupSucc"
#define EVENT_BACKUP_FAILED		"BackupFailed"

#define PORT_TELNET				23
#define PORT_SSH				22

//2008.11.29 ����״̬���� by zhou.jj
#define LANSTATUSUP							"Up"							// ������������״̬
#define LANSTATUSDOWN						"Down"							// �����ǹ���״̬
	
	///20080911�������ǰ��Ӧ�������Ϣ
#define ERR_DATEWRONG						101								//����ʷ������Ϊ����
#define ERR_OIDWRONG						102								//OBJECTID����
#define ERR_TIMEWRONG						103								//��ѯ��ʼʱ����ڽ���ʱ��
#define ERR_QRYACCWRONG						104								//��ѯ����������ʧ��
#define ERR_USERWRONG						105								//��¼�û�������
#define ERR_PSWWRONG						106								//��¼�������
#define ERR_PROBEUNCONNECT					107								//��̽�������Ѿ��Ͽ�
#define ERR_COUNTERUNCONNECT				108								//���¼����������Ѿ��Ͽ�
#define MAXQRYRETURNNUM						10000							// ������ѯ�����ؼ�¼�������
#define MAXTIMELEN							10								// ʱ�����󳤶�
#define MAXOBJECTNAMELEN					256								// �����ļ�·������󳤶�
#define MAXLOCATIONLEN						30								// ��������������󳤶�
#define MAXONEAREASIZE						50								// �ļ�һ����д�����󳤶�
#define MAXONECONTENTLEN					800								// �����ļ����ݵ�һ������󳤶�
#define MAXCONTENTFIELDNUM					3								// �����ļ�����ʱ��һ��������������
#define FLOWSEQUENCEDAEMON					1								// ��̨���������
#define FLOWPRIVATE							2								// ��ǰ̨˽�������
#define MAXONESTRINGSIZE					100								// ��־һ���ո�ֿ�������󳤶�
	
	///�˴��궨����������SAN��������״̬����
#define SAN_cabinet							"san_cabinet"
#define SAN_storagecell						"san_storagecell"
#define SAN_controller						"san_controller"
#define SAN_disk							"san_disk"
#define SAN_virtualdisk						"san_virtualdisk"
#define SAN_virtualdiskfolder				"san_virtualdiskfolder"
#define SAN_virtualdiskfamilyfolder			"san_virtualdiskfamilyfolder"
#define SAN_host							"san_host"
#define SAN_presentedunit					"san_presentedunit"
#define SAN_diskshelf						"san_diskshelf"					//delete
#define SAN_hostfolder						"san_hostfolder"				//delete
#define SAN_diskgrouprootfolder				"san_diskgrouprootfolder"		//delete
#define SAN_diskgroupfolder					"san_diskgroupfolder"			//delete
#define SAN_drmgroupfolder					"san_drmgroupfolder"			//delete
#define SAN_hardwarerootfolder				"san_hardwarerootfolder"		//delete
#define SAN_powersupply						"san_powersupply"				// power supply
	
	///�˴��궨���������������ļ��еĴ洢���̷���ֵ�����ֶ�(type)����
#define SPRETURNCURSOR						"CURSOR"						// ���α귵�ؽ�������α�������У�Ϊ������������ֵ��ʽ
#define SPRETURNNOCURSOR					"NOCURSOR"						// ������һ�н����û���α귵��
#define SPRETURNMULTICOL					"MULTICOL"						// ���α귵�ؽ�������α꺬�ж����
	
	///�˴��궨����������CFTDReqQryTradeDayChangeField�������л�����ChangeType�ֶεĺ���
#define TRUNCATEFLOW						"TruncateFlow"					// ���ָ����ŵ�������
#define CHANGETRADEDAY						"ChangeTradeDay"				// �������л�
	
	///�˴��궨����������CFTDReqQryUpdateSysConfigField����UpdateType�ֶεĺ���
#define UPDATESYSCONFIG_HOSTIDAPPID			"UP_IDRELATION"					// ����ID��ҵ��IDӳ���ϵ���͸���
#define UPDATESYSCONFIG_HOSTNAME			"UPXML_HOSTNAME"				// ����xml��ip��Ӧ��̽����������Ϣ
#define APPATTRMEMBERSIZETUOGUAN			"MemberSize_TG"					// �йܻ�Ա��
#define APPATTRUSERSESSIONSIZETUOGUAN		"UserSessionSize_TG"			// �й��û��Ự���С
#define APPATTRMEMBERSIZETOTALTUOGUAN		"MemberSizeTotal_TG"			//�й��ܻ�Ա��
#define APPATTRUSERSESSIONSIZETOTALTUOGUAN	"UserSessionSizeTotal_TG"		//�й���ϯλ��
#define APPATTRORDERSIZETUOGUAN				"OrderSize_TG"					// �йܱ�����
#define APPATTRTRADESIZETUOGUAN				"TradeSize_TG"					// �йܳɽ���
#define APPATTRIPSCOPENAMETUOGUAN			"ipScopeName_TG"				// �й�ip��Χ��Ӧ����������
#define APPATTRMAXMEMBERSIZE				"MaxMemberSizeTotal"			//����Ա��
#define APPATTRMAXSESSIONSIZE				"MaxUserSessionSizeTotal"		//�����ϯ��
#define APPATTRMAXMEMBERSIZETUOGUAN			"MaxMemberSizeTotal_TG"			//����йܻ�Ա��
#define APPATTRMAXSESSIONSIZETUOGUAN		"MaxUserSessionSizeTotal_TG"	//����й���ϯ��
#define APPATTRMEMORYDATABASE				"MemoryDatabase"				// �ڴ����ݿ�ʹ�õĿռ�
#define APPATTRMEMORYDATABASEUSAGE			"MemoryDatabaseUsage"			// �ڴ����ݿ�ʹ�ÿռ����
#define APPATTRMDBBLOCK						"MDBBlock"						// �ڴ����ݿ�ֿ���
#define APPATTRMDBBLOCKUSAGE				"MDBBlockUsage"					// �ڴ����ݿ�ֿ�������
#define APPATTRORDERSIZE					"OrderSize"						// �������С
#define APPATTRTRADESIZE					"TradeSize"						// �ɽ����С
#define APPATTRCLIENTSIZE					"ClientSize"					// �ͻ����С
#define APPATTRPARTCLIENTSIZE				"PartClientSize"				// ��Ա�ͻ����С
#define APPATTRCLIENTPOSITIONSIZE			"ClientPositionSize"			// �ͻ��ֱֲ��С
#define APPATTRUSERSESSIONSIZE				"UserSessionSize"				// �û��Ự���С
#define APPATTRTOTALVOLUME					"TotalVolume"					// �ɽ�����
#define APPATTRTOTALAMOUNT					"TotalAmount"					// �ɽ����
#define APPATTRHANDLEINPUTTOTAL				"HandleInputTotal"				// ���������������
#define APPATTRHANDLEINPUT					"HandleInput"					// ���δ������������
#define APPATTRHANDLEORDERINSERTTOTAL		"HandleOrderInsertTotal"		// ����ı�������������
#define APPATTRHANDLEORDERINSERT			"HandleOrderInsert"				// ���δ���ı�����������
#define APPATTRHANDLEORDERACTIONTOTAL		"HandleOrderActionTotal"		// ����ı�������������
#define APPATTRHANDLEORDERACTION			"HandleOrderAction"				// ���δ���ı�����������
#define APPATTRHANDLEORDERINSERTERRORTOTAL	"HandleOrderInsertErrorTotal"	// ����ı�������������
#define APPATTRHANDLEORDERINSERTERROR		"HandleOrderInsertError"		//  ���δ���ı�����������
#define APPATTRHANDLEORDERACTIONERRORTOTAL	"HandleOrderActionErrorTotal"	// ����ı�������������
#define APPATTRHANDLEORDERACTIONERROR		"HandleOrderActionError"		// ���δ���ı�����������
#define APPATTRHANDLELOGINTOTAL				"HandleLoginTotal"				// ����ĵ�¼������
#define APPATTRHANDLELOGIN					"HandleLogin"					// ���δ���ĵ�¼����
#define APPATTRHANDLELOGINERRORTOTAL		"HandleLoginErrorTotal"			// ����ĵ�¼ʧ��������
#define APPATTRHANDLELOGINERROR				"HandleLoginError"				// ���δ���ĵ�¼ʧ������
#define APPATTRHANDLEFTDREQUESTTOTAL		"HandleFTDRequestTotal"			// �����FTD����������
#define APPATTRHANDLEFTDREQUEST				"HandleFTDRequest"				// ���δ����FTD��������
#define APPATTRHANDLEFTDQUERYTOTAL			"HandleFTDQueryTotal"			// �����FTD��ѯ������
#define APPATTRHANDLEFTDQUERY				"HandleFTDQuery"				// ���δ����FTD��ѯ����
#define APPATTRHANDLEFTDERRORTOTAL			"HandleFTDErrorTotal"			// �����FTD����������
#define APPATTRHANDLEFTDERROR				"HandleFTDError"				//  ���δ����FTD��������
#define APPATTRHANDLEOFPREQUESTTOTAL		"HandleOFPRequestTotal"			// �����OFP����������
#define APPATTRHANDLEOFPREQUEST				"HandleOFPRequest"				// ���δ����OFP��������
#define APPATTRHANDLEOFP2REQUESTTOTAL		"HandleOFP2RequestTotal"		//  �����OFP2����������
#define APPATTRHANDLEOFP2REQUEST			"HandleOFP2Request"				// ���δ����OFP2��������
#define APPATTRCOMPLOGLEN					"complogLen"					// �Ŷӻ���������
#define APPATTRTSERIESLEN					"tseriesLen"					// ���������������
#define APPATTRTRESULTLEN					"tresultLen"					// ���׽����������
#define APPATTRTINITLEN						"tinitLen"						// ��ʼ����������
#define APPATTRDBMTLEN						"dbmtLen"						// DBMT��������
#define APPATTRDFMTLEN						"dfmtLen"						// DFMT��������
#define APPATTRFRONTLEN						"frontLen"						// ǰ�õ�������
#define APPATTROFPMARKETDATASENTTOTAL		"OFPMarketDataSentTotal"		// ������ǰ�÷�������������
#define APPATTROFPMARKETDATASENT			"OFPMarketDataSent"				// ����������ǰ�÷�����������
#define APPATTRTMDBCOUNTTOTAL				"TMDBCountTotal"				// TMDB��������
#define APPATTRTMDBCOUNT					"TMDBCount"						// ����TMDB������
#define APPATTRCURRENTTIME					"CurrentTime"					// ��ǰҵ��ʱ��
#define APPATTRISACTIVE						"IsActive"						// �Ƿ��Ծ
#define APPATTRVERSION						"Version"						// ��ǰ�汾
#define APPATTRCOMPOSITORSTATE				"CompositorState"				// �Ŷӻ���ǰ״̬
#define APPATTRTIMESYNCTOTAL				"TimeSyncTotal"					// �������������ĸ���
#define APPATTRCPUUSAGE						"CPUUsage"						// ҵ�����CPUʹ����
#define APPATTRMEMORYUSAGE					"MemoryUsage"					// ҵ�����MEMORYʹ����
#define APPATTRDISKUSAGE					"DiskUsage"						// ҵ����������ļ�ϵͳʹ����
#define APPATTRINODEUSAGE					"INodeUsage"					// ҵ����������ļ�ϵͳINodeʹ����
#define APPATTRCENTERINFO					"Info"			// ��������ָ�����֮���������Ϣ��ʾ���ԣ��������������

// ��CPUUsage֮�������CPUUsageInfoָ�ֵ꣬Ϊ���ĸ������������������CPUUsage
#define APPATTRLANSESSIONSIZE		"LanSessionSize"		// ����ϯλ��
#define APPATTRWANSESSIONSIZE		"WanSessionSize"		// Զ��ϯλ��
#define APPATTRMEMBERSIZE			"MemberSize"			// ��Ա��
#define APPATTRACTIVE				"Active"				// ������ҵ����̻״̬����
#define APPATTRIPSCOPENAME			"ipScopeName"			// ip��Χ��Ӧ����������
#define APPATTRMEMBERSIZETOTAL		"MemberSizeTotal"		//�ܻ�Ա��
#define APPATTRUSERSESSIONSIZETOTAL "UserSessionSizeTotal"	//��ϯλ��
#define APPATTRMDSESSIONSIZE		"MdSessionSize"			// mdkernel�����Ӹ���
#define APPATTRTHREADS				"Threads"				// �������������߳���
#define EVENT_FLAG_GREEN			0						// �¼�״̬Ϊ����
#define EVENT_FLAG_BLUE				1						// �¼�״̬Ϊ�ر�
#define EVENT_FLAG_RED				2						// �¼�״̬Ϊ�����ر�
#define EVENT_FLAG_GRAY				3						// �¼�״̬Ϊ�ӽڵ㺬�ر�
#define APP_ARB						"app.arb"
#define APP_COMPOSITOT				"app.compositor"
#define APP_FRONT					"app.front"
#define APP_MDKERNEL				"app.mdkernel"
#define APP_OFPMD					"app.ofpmd"
#define APP_QKERNEL					"app.qkernel"
#define APP_TKERNEL					"app.tkernel"
#define APP_TINIT					"app.tinit"
#define APP_TMDB					"app.tmdb"
#define APP_DBMT					"app.dbmt"
#define APP_FIBGATE					"app.fibgate"
#define APP_MD2KERNEL				"app.md2kernel"
#define APP_CONSOLE					"app.console"

#define APP_SUFFIX_SP				"_sp"
#define APP_SUFFIX_DBLOG			"_dblog"

#define XML_EVENT_NAME				"name"
#define XML_EVENT_TYPE				"type"
#define XML_EVENT_FULLNAME			"FullName"
#define XML_EVENT_LEVEL				"level"
#define XML_EVENT_GIVEUPTIME		"GiveupTime"
#define XML_EVENT_INTERVAL			"Interval"
#define XML_EVENT_CONTROL			"Control"
#define XML_EVENT_EXPR				"Expr"
#define XML_EVENT_OBJECTID			"ObjectId"
#define XML_EVENT_OBJECTATTR		"ObjectAttr"
#define XML_EVENT_COMMENT			"Comment"

#define HOSTCFG_REQTYPE_HOST		"Host"
#define HOSTCFG_REQTYPE_TOMCAT		"Tomcat"
#define HOSTCFG_REQTYPE_SP			"SP"
#define HOSTCFG_REQTYPE_SAN			"SAN"
#define HOSTCFG_REQTYPE_SANEVENT	"SANEvent"
#define HOSTCFG_REQTYPE_DBLOG		"DBLog"
#define HOSTCFG_REQTYPE_TIMER		"Timer"
#define HOSTCFG_REQTYPE_CFGFILE		"CfgFile"
#define HOSTCFG_REQTYPE_APPROOT		"AppRoot"
#define HOSTCFG_REQTYPE_APPSYSLOG	"AppSyslog"
#define HOSTCFG_REQTYPE_SYSTEMLOG	"SystemLog"
#define HOSTCFG_REQTYPE_KEYFILE		"KeyFile"
#define HOSTCFG_REQTYPE_DFMTLOG		"DfmtLog"
#define HOSTCFG_REQTYPE_WEBSITE		"Website"
#define HOSTCFG_REQTYPE_WEBSITECODE "WebsiteCode"
#define HOSTCFG_REQTYPE_ACCESSLOG	"AccessLog"
#define HOSTCFG_REQTYPE_SESSIONLOG	"SessionLog"
#define HOSTCFG_REQTYPE_DATABASE	"Database"
#define HOSTCFG_REQTYPE_DBATTR		"Attr"

#define TIME_MEASURE_START(name)	time_t name##TimeStart = time(NULL)
#define TIME_MEASURE_END(name)													  \
	time_t name##TimeEnd = time(NULL);											  \
	if (name##TimeEnd >= name##TimeStart + 2)									  \
	{																			  \
		printf(																	  \
			"Warning: File [%s] Line [%d]\n         Name [%s] Time [%d] secs.\n", \
			__FILE__,															  \
			__LINE__,															  \
			name,																  \
			name##TimeEnd - name##TimeStart);									  \
	}																			  \
																			   \
///У�鲢��ȡ�����������ʶ
///@param	argc	����argc
///@param	argv	����argv
///@return	���س����������ʶ,��������ʶ���Ϸ������ֱ���˳�
inline int getStartId(int argc, char **argv)
{
	if (argc < 2 || (atoi(argv[1])) <= 0)
	{
		printf("\nUsage:%s [������ʶ]\n\n", argv[0]);
		fflush(stdout);
		exit(0);
	}

	return atoi(argv[1]);
}

///����ɢ��ֵ����,�����ַ���������ֵ
///@param	pStrbuff	�����ַ����ĵ�ַ
///@param	len	����ĳ���
///@return	�����ַ������������ɢ��ֵ
unsigned int cal_crc(char *pStrbuff, int len);

typedef struct __SHashObject
{
	char mMonitorAttr[64];
	unsigned int mHashValue;
} SHashObject;

//Added by Henchi, 20100609
class CObjectIdStatus
{
	/* */
	public:
		CObjectIdStatus(void)
		{
			m_sObjectId = "";
			m_sObjectName = "";
			m_iEventFlag = EVENT_FLAG_GREEN;
		}

		CObjectIdStatus(string ObjectId, string ObjectName)
		{
			m_sObjectId = ObjectId;
			m_sObjectName = ObjectName;
			m_iEventFlag = EVENT_FLAG_GREEN;
		}

		CObjectIdStatus(const char *pObjectId, const char *pObjectName)
		{
			m_sObjectId = pObjectId;
			m_sObjectName = pObjectName;
			m_iEventFlag = EVENT_FLAG_GREEN;
		}

		///����ID,��:TRADE.PuDian.app.tkernel.1
		string	m_sObjectId;

		///������,��:tkernel.1
		string	m_sObjectName;

		///�����¼�״̬��ʶ: 0��ʾ�����¼�;1��ʾ�ر��¼�;2��ʾ�����ر��¼�
		int m_iEventFlag;
};

//////////////////////////////////////////////////////////////////////////
///CDataCenterManage�������������Ķ��������
///@auther	�ܽ���
///@version	1.0,20080510
//////////////////////////////////////////////////////////////////////////
class CDataCenterManage
{
	/* */
	public:
		///���캯��
		CDataCenterManage(void);

		///��������
		~ CDataCenterManage(void);

		///��ȡ���������б���,���ñ�����֮ǰ��Ҫ����XMLInit����
			///@param	appName	������������,��app.tkernel
			///@return	���ؽ��������б�
		list<string> *getAttrFromApp(string &appName);

		///��ȡ���������б���,���ñ�����֮ǰ��Ҫ����XMLInit����
			///@param	appName	ID����,��PuDian.app.tkernel.1
			///@return	���ؽ��������б�
		list<string> *getAttrFromAppId(string &appName);

		// Added by Henchi
			///��ȡӦ��ID��Ӧ������ӳ��ͼ,���ñ�����֮ǰ��Ҫ����XMLInit����
			///@return	����Ӧ��ID��Ӧ������ӳ��ͼ
		map<string, string> &getAppIdTypeMap(void)
		{
			return m_mapAppIdType;
		};

		///��ȡӦ��ID��������ϵӳ��ͼ,���ñ�����֮ǰ��Ҫ����XMLInit����
			///@return	����Ӧ��ID��������ϵӳ��ͼ
		map<string, string> &getAppIdHostMap(void)
		{
			return m_mapAppIdHost;
		};

		///��ȡӦ��ID��Ӧ����ӳ��ͼ,���ñ�����֮ǰ��Ҫ����XMLInit����
			///@return	����Ӧ��ID��Ӧ����ӳ��ͼ
		map<string, CObjectIdStatus> &getAppIdNameMap(void)
		{
			return m_mapAppIdName;
		};

		///��ȡ����������������ӳ��ͼ,���ñ�����֮ǰ��Ҫ����XMLInit����
			///@return	����Ӧ��ID��Ӧ����ӳ��ͼ
		map<string, string> &getHostDataCenterMap(void)
		{
			return m_mapHostDataCenter;
		};

		///��ȡ����ID�������IP��Ӧ��ϵmap,���ñ�����֮ǰ��Ҫ����XMLInit����
			///@return	���ض���ID�������IP��Ӧ��ϵmap
		map<string, string> &getObjectIDAddressMap(void)
		{
			return m_mapObjectIDAddress;
		};
		
		map<int, string>& getFrontUniqueID()
		{
			return m_mapFrontAllocateID;
		}

		// Added End
		
			///�ж������Ƿ��Ǹý��̵ĺ���
			///@param	appName	������,��app.tkernel
			///@param	attrName	������,��MemoryDatabase
			///@return	�����жϽ��,true��ʾ�ý��̾߱���ָ��,false��ʾ���߱�
		bool judgeAttrOfApp(string &appName, string &attrName);

		///ȡ�߱����Ե����м�ض���ID�ĺ���
			///@param	appList	�������м�ض���ID���б�
			///@param	attrName	��ص�ָ������
			///@return	����ֵ,true��ʾ�ɹ�,false��ʾʧ��
		bool getAppIdFromAttr(list<string> &appList, string &attrName);

		///ȡ���ָ���ֵ����
			///@param	pAttr	ָ������
			///@return	����ָ���ֵ����
		int getAttrType(char *pAttr);

		///ȡ���ָ��ļ������
			///@param	pAttr	ָ������
			///@return	����ָ���ֵ����
		int getAttrInterval(const char *pAttr);

		///ȡ���ָ���ֵ����,���ָ�����Ʋ����ھ͸���pValue���ж�
			///@param	pAttr	ָ������
			///@param	pValue	ָ���ֵ
			///@return	����ָ���ֵ����
		int getAttrType(const char *pAttr, const char *pValue);

		///�������,��ӡmap�����н��̺����Թ�ϵ��Ϣ
		void print(void);

	/* */
	public:
		///���ӽ������Թ�ϵ����
			///@param	appName	Ӧ�ý�����,��app.tkernel(TotalAmount),PuDian.os.KF4660.keyfile(check.txt)
			///@param	attrName	Ӧ�ý��̵�����
		void addAppAttr(string &appName, string &attrName);

		///���ӽ������Թ�ϵ����
			///@param	appName	Ӧ�ý�����,app.tkernel(TotalAmount),PuDian.os.KF4660.keyfile(check.txt)
			///@param	attrName	Ӧ�ý��̵�����
		void addAppAttr(char *appName, char *attrName);

		///����Ӧ��ID������ӳ���ϵ����
			///@param	appId	Ӧ�ü���ID,��PuDian.app.tkernel.1
			///@param	appType	������ҵ������,��app.tkernel
		void addAppIdType(string &appId, string &appType);

		///����Ӧ��ID������ӳ���ϵ����
			///@param	appId	Ӧ�ü���ID,��PuDian.app.tkernel.1
			///@param	appType	������ҵ������,��app.tkernel
		void addAppIdType(char *appId, char *appType);

		// Added by Henchi
			///����Ӧ��ID������ӳ���ϵ����
			///@param	appId	Ӧ�ü���ID,��PuDian.app.tkernel.1
			///@param	Host	Ӧ�ý���������������PuDian.os.AC-01
		void addAppIdHost(string &appId, string &Host);

		///����Ӧ��ID������ӳ���ϵ����
			///@param	appId	Ӧ�ü���ID,��PuDian.app.tkernel.1
			///@param	Host	Ӧ�ý���������������PuDian.os.AC-01
		void addAppIdHost(char *appId, char *Host);

		///����Ӧ��ID��Ӧ����ӳ���ϵ����
			///@param	appId	Ӧ�ü���ID,��PuDian.app.tkernel.1
			///@param	appName	Ӧ�ý�����
		void addAppIdName(string &appId, string &appName);

		///����Ӧ��ID�ĵ�ǰ״̬���������ӽڵ�
		void updateCurAppIDStatus(string &appId, string &appName, int status);

		///����Ӧ��ID��Ӧ����ӳ���ϵ����
			///@param	appId	Ӧ�ü���ID,��PuDian.app.tkernel.1
			///@param	appName	Ӧ�ý�����
		void addAppIdName(char *appId, char *appName);

		///���Ӷ���ID�������IP��Ӧ��ϵ����
			///@param	objId	����ID, ��TRADE.PuDian.app.tkernel.1
			///@param	addr	���������IP��ַ���� 192.168.77.31
		void addObjectIDAddress(char *objId, char *addr);

		///���Ӷ���ID�������IP��Ӧ��ϵ����
			///@param	objId	����ID, ��TRADE.PuDian.app.tkernel.1
			///@return	���ط�����IP��ַ���� 192.168.77.31
		string	getAddressByObjectID(char *objId);

		///����Ӧ��ID��Ӧ����ӳ���ϵ����
			///@param	appId	Ӧ�ü���ID,��PuDian.app.tkernel.1
			///@param	oldAppId	��Ҫɾ����ԭAppId
		void UpDateAppIdName(char *appId, char *oldAppId);

		///����Ӧ��ID��Ӧ����ӳ���ϵ����
			///@param	appId	Ӧ�ü���ID,��PuDian.app.tkernel.1
			///@param	status	�¼�״̬���: 0Ϊ�����¼�;1Ϊ�ر��¼�
		void UpDateObjectIdStatus(char *appId, int status);

		///��ѯ����ID��ǰ�Ƿ��ѱ���ʶ�ر���澯�¼�
			///@param	appId	Ӧ�ü���ID,��PuDian.app.tkernel.1
			///@return	����ֵ,true��ʾ�ɹ�,false��ʾʧ��
		bool IsObjectEventOff(char *appId);

		///��ȡ��������Ӧ���ڵ�����ID
			///@param	appId	Ӧ�ü���ID,��PuDian.app.tkernel.1
			///@return	����ֵ,������ID��,�����ڸ�����ʱ���ء���
		string	GetParentObjectId(char *appId);

		///ͨ������ֱ���ӽڵ�ĸ澯״̬�����±��ڵ�澯״̬
			///@param	appId	Ӧ�ü���ID,��PuDian.app.tkernel.1
		void ReFreshObjectIdStatus(char *appId);

		///��XML�ļ���ȡ���������ʼ������
		void XMLInit(char *pszCfgPath);

		///���������ؼ��ļ���ϵͳ��־��ϵ��
		void UpdateAppAttr(char *newHostName, char *oldHostName);
		void addFrontUniqueID(char* szObjectID);
	// Added End
	protected:
		///����Ӧ�ý������Թ�ϵmap
			///@param	key	����Ӧ�ý�������,app.tkernel
			///@param	value	�������ӵ�е�����ָ���б�
		map<string, list<string> *> m_mapAppAttr;

		///����Ӧ��ID�����͹�ϵmap
			///@param	key	����Ӧ�õ�ID,��PuDian.app.tkernel.1
			///@param	value	����Ӧ������,��app.tkernel
		map<string, string> m_mapAppIdType;

		///����Ӧ��ID��������ϵmap
			///@param	key	����Ӧ�õ�ID,��PuDian.app.tkernel.1
			///@param	value	����Ӧ�����е�������,��PuDian.os.AC-01
		map<string, string> m_mapAppIdHost;

		///����Ӧ��ID��Ӧ�����ֹ�ϵmap
			///@param	key	����Ӧ�õ�ID,��PuDian.app.tkernel.1,PuDian.os.AC-01
			///@param	value	����Ӧ��ID״̬�ṹ
		map<string, CObjectIdStatus> m_mapAppIdName;

		///������ָ�������͵Ķ�Ӧ��ϵmap
			///@param	key	�����ص�����, ��TotalVolume,��ʾ�ɽ�����
			///@param	value	����������ֵ������, ��INT_ATTR, ��ʾ��ָ��Ϊ����
		map<string, int> m_mapAttrType;

		///������ָ������������(��)�Ķ�Ӧ��ϵmap
			///@param	key	�����ص�����, ��TotalVolume,��ʾ�ɽ�����
			///@param	value	������ָ�����ݲ��������ڣ���λΪ��
		map<string, int> m_mapAttrInterval;

		///�������������������Ķ�Ӧ��ϵmap;
			///@param	key	����������, ��AC-01
			///@param	value	���������������֣��� PuDian
		map<string, string> m_mapHostDataCenter;

		///�������ID�������IP��Ӧ��ϵmap;
			///@param	key	����ID, ��TRADE.PuDian.app.tkernel.1
			///@param	value	���������IP��ַ���� 192.168.77.31
		map<string, string> m_mapObjectIDAddress;
		
		map<int, string>	m_mapFrontAllocateID;
};

/////////////////////////////////////////////////////////////////////////
///CReadWriteFile�����˱���ؼ��ֺ�ֵ����
///@author	�ܽ���
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
typedef struct
{
	string	m_key;			//�ؼ�����
	string	m_pos;			//�ؼ��ֶ�Ӧ��ƫ����
	string	m_time;			//ƫ������Ӧ��ʱ��
} SWriteFilePos;

#define MAX_SAVEKEYNUM	512
#define MAX_KEYSIZE		60
typedef struct
{
	char mkey[MAX_KEYSIZE]; //�ؼ���
	unsigned long npos;		//ƫ����
	int ntime;				//ʱ���
} SPosition;

class CReadWriteFile
{
	/* */
	private:
		///������ļ�������
		FILE *m_mFd;

		///����Ķ�ȡλ�õ��ļ���
		char *m_pSaveFile;

		///���浽�ļ��Ĺؼ���
		char *m_pKey;

		///�ؼ��ֶ�Ӧ��ֵ
		long m_mKeyPosition;

		///�ؼ��ֺ�ֵ����������
		char *m_mSaveBuff;

		///�ؼ��ֺ�ֵ�ĳ���
		int m_mLength;

		///�ؼ��ֵĸ���
		int m_nKeyNum;

		///�������ڴ��е��׵�ַ
		char *m_pBuffer;

		///�ؼ��֡�λ��
			///@key	�ؼ��ֵ�ֵ
			///@value	�ؼ��ֶ�Ӧ��m_pBuffer��λ��
		map<string, int> m_mKeyId;

	/* */
	public:

		///���캯��
			///@param	pSaveFile	�洢���ļ���
			///@param	keyLength	����ؼ��ֺ�ֵ�ĳ���
		CReadWriteFile(char *pSaveFile, int keyLength)
		{
			m_mLength = keyLength;
			m_mSaveBuff = (char *)malloc(m_mLength + 1);
			m_pSaveFile = pSaveFile;
			if ((m_mFd = fopen(m_pSaveFile, "r")) == NULL)	// ֻ����ʽ���ļ����ж��ļ��Ƿ���ڣ�����������ȴ����ļ�
			{
				if ((m_mFd = fopen(m_pSaveFile, "a")) == NULL)
				{	// �����ļ�ʧ�ܣ��˳�
					exit(0);
				}
				else
				{
					SAFE_FCLOSE(m_mFd);
				}
			}
			else
			{		// �ļ����ڣ��ȹر��ļ���Ȼ�����´��ļ�
				SAFE_FCLOSE(m_mFd);
			}

			m_mFd = fopen(m_pSaveFile, "rb+");
			if (m_mFd == NULL)
			{
				exit(0);
			}

			m_mKeyPosition = 0;
			if (fseek(m_mFd, 0, SEEK_SET) != 0)
			{
				exit(0);
			}

			m_pBuffer = (char *)malloc(sizeof(SPosition) * MAX_SAVEKEYNUM);
			memset(m_pBuffer, 0, sizeof(SPosition) * MAX_SAVEKEYNUM);
			m_nKeyNum = fread(
					m_pBuffer,
					sizeof(SPosition),
					MAX_SAVEKEYNUM,
					m_mFd);

			SPosition *pSpos = (SPosition *)m_pBuffer;
			for (int i = 0; i < m_nKeyNum && i < MAX_SAVEKEYNUM; i++)
			{
				m_mKeyId[string(pSpos[i].mkey)] = i;
			}
		}

		///��������,�˳�ʱ�ر��ļ�������
		~CReadWriteFile(void)
		{
			if (m_mFd)
			{
				SAFE_FCLOSE(m_mFd);
			}

			if (m_mSaveBuff)
			{
				free(m_mSaveBuff);
				m_mSaveBuff = NULL;
			}

			if (m_pBuffer)
			{
				free(m_pBuffer);
				m_pBuffer = NULL;
			}
		}

		///ȡֵ����,���ļ��ж�ȡָ��̽���Ӧ������ֵ
			///@param	pKey	ָ���Ĺؼ�����
			///@param	mPosList	������������������ֵ�б�
			///@return	true�ɹ���falseʧ��
		bool ReadKeyValue(char *pKey, list<SWriteFilePos> &mPosList)
		{
			char *pValuePos;
			char str[30];
			SWriteFilePos sPos;
			SPosition *pSpos = (SPosition *)m_pBuffer;
			for (int i = 0; i < m_nKeyNum && i < MAX_SAVEKEYNUM; i++)
			{
				if ((pValuePos = strstr(pSpos[i].mkey, pKey)) != NULL
				&&	pSpos[i].mkey[strlen(pKey)] == ',')
				{
					sPos.m_key = pSpos[i].mkey + strlen(pKey) + 1;
					sprintf(str, "%lu", pSpos[i].npos);
					sPos.m_pos = str;
					sprintf(str, "%lu", pSpos[i].ntime);
					sPos.m_time = str;
					mPosList.push_back(sPos);
				}
			}

			return true;
#if 0
			size_t	mPos;
			SWriteFilePos sPos;
			memset(m_mSaveBuff, 0, m_mLength + 1);
			if (fseek(m_mFd, 0, SEEK_SET) < 0)
			{
				exit(1);
			}

			while ((mPos = fread(m_mSaveBuff, 1, m_mLength, m_mFd)) == m_mLength)
			{
				if ((pValuePos = strstr(m_mSaveBuff, pKey)) != NULL
				&&	m_mSaveBuff[strlen(pKey)] == ',')
				{
					pValuePos = pValuePos + strlen(pKey) + 1;

					char *p = strchr(pValuePos, '=');
					if (p == NULL)
					{
						continue;
					}

					*p = '\0';
					sPos.m_key = pValuePos;

					pValuePos = p + 1;
					p = strchr(pValuePos, ',');
					if (p == NULL)
					{
						continue;
					}

					*p = '\0';
					p++;
					sPos.m_pos = pValuePos;
					sPos.m_time = p;

					mPosList.push_back(sPos);
				}
			}

			return true;
#endif
		}

		///����ƫ�������ļ�����
			///@return	true��ʾ���³ɹ�,false��ʾʧ��
		bool FlushToFile(void)
		{
			if (fseek(m_mFd, 0, SEEK_SET) < 0)
			{
				exit(1);
			}

			if (m_nKeyNum <= 0)
			{
				return true;
			}

			int iTest = fwrite(
					m_pBuffer,
					1,
					m_nKeyNum * sizeof(SPosition),
					m_mFd);
			if (iTest <= 0)
			{
				exit(1);
			}

			if (fflush(m_mFd) != 0)
			{
				exit(1);
			}

			return true;
		}

		///����ֵ����,����m_pKey�ؼ��ֶ�Ӧ��ֵ���ļ���
			///@param	pKey	�ؼ����ַ���
			///@param	mNum	�ؼ��ֶ�Ӧ��ֵ
			///@param	mTime	�ؼ��ֶ�Ӧֵ��ʱ��ֵ
			///@return	true��ʾ���³ɹ�,false��ʾʧ��
		bool WriteKeyValue(char *pKey, long mNum, int mTime)
		{
			SPosition *pSpos = (SPosition *)m_pBuffer;
			map<string, int>::iterator	it = m_mKeyId.find(string(pKey));
			if (it == m_mKeyId.end())
			{
				m_mKeyId[string(pKey)] = m_nKeyNum;
				strcpy(pSpos[m_nKeyNum].mkey, pKey);
				pSpos[m_nKeyNum].npos = mNum;
				pSpos[m_nKeyNum].ntime = mTime;
				m_nKeyNum++;
				if (m_nKeyNum >= MAX_SAVEKEYNUM)
				{
					printf(
						"���棺��������ļ�����λ���������������λ������������\n");
					fflush(stdout);
					return false;
				}
			}
			else
			{
				if (it->second >= MAX_SAVEKEYNUM)
				{
					return false;
				}

				pSpos[it->second].npos = mNum;
				pSpos[it->second].ntime = mTime;
			}

			return true;
#if 0
			char *pValuePos;
			size_t	mPos;

			if (fseek(m_mFd, 0, SEEK_SET) < 0)
			{
				exit(1);
			}

			m_mKeyPosition = 0;
			while ((mPos = fread(m_mSaveBuff, 1, m_mLength, m_mFd)) == m_mLength)
			{
				if ((pValuePos = strstr(m_mSaveBuff, pKey)) != NULL
				&&	m_mSaveBuff[strlen(pKey)] == '=')
				{
					break;
				}

				m_mKeyPosition = m_mKeyPosition + mPos;
			}

			memset(m_mSaveBuff, 0, m_mLength + 1);
#ifdef WIN32
			_snprintf(m_mSaveBuff, m_mLength, "%s=%ld,%d", pKey, mNum, mTime);
#else
			snprintf(m_mSaveBuff, m_mLength, "%s=%ld,%d", pKey, mNum, mTime);
#endif
			if (fseek(m_mFd, m_mKeyPosition, SEEK_SET) < 0)
			{
				exit(1);
			}

			int iTest = fwrite(m_mSaveBuff, 1, m_mLength, m_mFd);

			//printf("+++++++++ iTest %d +++++++++ m_pKey %s nMum %ld \n",iTest,m_pKey, mNum);
			if (iTest <= 0)
			{
				exit(1);
			}

			if (fflush(m_mFd) != 0)
			{
				exit(1);
			}

			return true;
#endif
		}
};

/////////////////////////////////////////////////////////////////////////
///CReadWriteFile�������ַ�����IDӳ���ϵ����
///@author	���ض�
///@version	1.0,20080510
///@history
///20080623	�ܽ���		���ӷ���,�޶�ע��
/////////////////////////////////////////////////////////////////////////
class CStringIdMap
{
	/* */
	private:
		///�����ַ�����IDӳ���ϵ��map����
		map<string, int> m_stringMap;

		///�����ַ������õ�verctor����
		vector<CRefStringPtr> m_stringList;

		///ȡ�ַ���ID����,�����ַ�����Ӧ��ID
			///@param	s	��Ҫ���ҵ��ַ�����ַ
			///@return	���ظ��ַ�����Ӧ��ID,����ַ��������ھͷ���-1
		int findStringId(const char *s)
		{
			map<string, int>::iterator	it;
			it = m_stringMap.find(s);
			if (it == m_stringMap.end())
			{
				return -1;
			}
			else
			{
				return it->second;
			}
		}

		///����ַ�������,���ַ�����ӵ�map��vector������
			///@param	s	��Ҫ��ӵ��ַ�������
			///@return	���ظ��ַ�����Ӧ��ID
		int addStringId(const CRefStringPtr &s)
		{
			int result = m_stringList.size();
			m_stringList.push_back(s);
			m_stringMap.insert(pair<string, int> (s->getValue(), result));
			return result;
		}

	/* */
	public:

		///ȡ��ǰ�ڴ�����ע��Ķ���ID����ֵ
			///@return ���ص�ǰ��ע��Ķ���ID����ֵ
		int getMapSize(void)
		{
			return m_stringMap.size();
		}

		///ȡ��ǰ�ڴ�����ע��Ķ���ID����ֵ
			///@return ���ص�ǰ��ע��Ķ���ID����ֵ
		int getListSize(void)
		{
			return m_stringList.size();
		}

		///ȡ�ַ���ID����,�����ַ�����Ӧ��ID,������ַ��������ھ�����
			///@param	s	��Ҫ���ҵ��ַ�����ַ
			///@return	���ظ��ַ�����Ӧ��ID
		int getStringId(const char *s)
		{
			int result;
			if ((result = findStringId(s)) != -1)
			{
				return result;
			}

			return addStringId(s);
		}

		///ȡ�ַ���ID����,�����ַ�����Ӧ��ID,������ַ��������ھ�����
			///@param	s	��Ҫ���ҵ��ַ�������
			///@return	���ظ��ַ�����Ӧ��ID
		int getStringId(const CRefStringPtr &s)
		{
			int result;
			if ((result = findStringId(s)) != -1)
			{
				return result;
			}

			return addStringId(s);
		}

		///����IDȡ�ַ�������,����ָ��ID���ַ���
			///@param	id	��Ҫ���ҵ��ַ���ID
			///@return	���ظ��ַ����ĵ�ַ
		const char *getString(int id)
		{
			if (id < 0 || id >= (int)m_stringList.size())
			{
				return NULL;
			}

			vector<CRefStringPtr>::iterator it;
			it = m_stringList.begin() + id;
			return *it;
		}

		/**�����ַ���ID�����ִ�ID����,�ú��������ַ����еĵ�һ��ð�ŷָ�������ַ���
	* ,���Ҹ��ַ������������ִ���ID
	* @param	objectId	����ð��ǰ���ִ�ID
	* @param	itemId	����ð�ź���ִ�ID
	* @param	s	���ҵ��ַ���ָ��
	* @return	�����ַ�����Ӧ��ID,������ַ����в�����ð�žͷ���-1
	*/
		int getStringSubId(int &objectId, int &itemId, const char *s)
		{
			if (s == NULL)
			{
				return -1;
			}

			int result;
			if ((result = findStringId(s)) == -1)
			{
				result = addStringId(s);
			}

			char temp[1024 + 1];
			memset(temp, 0, 1024);
			strncpy(temp, s, strlen(s) < 1024 ? strlen(s) : 1024);

			char *p = strchr(temp, ':');
			if (p == NULL)
			{
				return -1;
			}

			*p = '\0';
			p++;
			objectId = getStringId(temp);
			itemId = getStringId(p);
			return result;
		}

		/**�����ַ���ID�����ִ�ID����,�ú��������ַ����еĵ�һ��ð�ŷָ�������ַ���
	* ,���Ҹ��ַ������������ִ���ID
	* @param	objectId	����ð��ǰ���ִ�ID
	* @param	itemId	����ð�ź���ִ�ID
	* @param	s	���ҵ��ַ�������
	* @return	�����ַ�����Ӧ��ID,������ַ����в�����ð�žͷ���-1
	*/
		int getStringSubId(int &objectId, int &itemId, const CRefStringPtr &s)
		{
			int result;
			if ((result = findStringId(s)) == -1)
			{
				result = addStringId(s);
			}

			char temp[1024 + 1];
			memset(temp, 0, 1024);
			strncpy(temp, s, strlen(s) < 1024 ? strlen(s) : 1024);

			char *p = strchr(temp, ':');
			if (p == NULL)
			{
				return -1;
			}

			*p = '\0';
			p++;
			objectId = getStringId(temp);
			itemId = getStringId(p);
			return result;
		}

		/**�����ַ���ID�����ִ�ID����,�ú��������ַ����е����һ��.�ָ�������ַ���
	* ,���Ҹ��ַ������������ִ���ID
	* @param	objectId	����.ǰ���ִ�ID
	* @param	itemId	����.����ִ�ID
	* @param	s	���ҵ��ַ���ָ��
	* @return	�����ַ�����Ӧ��ID,������ַ����в�����.�ͷ���-1
	*/
		int getStringSubIdRFromDot(int &objectId, int &itemId, const char *s)
		{
			int result = findStringId(s);
			if ((result = findStringId(s)) == -1)
			{
				result = addStringId(s);
			}

			char temp[1024 + 1];
			memset(temp, 0, 1024);
			strncpy(temp, s, strlen(s) < 1024 ? strlen(s) : 1024);

			char *p = strrchr(temp, '.');
			if (p == NULL)
			{
				return -1;
			}

			*p = '\0';
			p++;
			objectId = getStringId(temp);
			itemId = getStringId(p);
			return result;
		}

		///��ӡ�������,��ӡ��ǰmap�б���������ַ���ӳ���ϵ
		void print(void)
		{
			map<string, int>::iterator	it;
			it = m_stringMap.begin();
			while (it != m_stringMap.end())
			{
				printf("%s %d\n", it->first.c_str(), it->second);
				it++;
			}
		}
};

///������ʱ��ȡ�ַ���ʱ�亯��
///@param	nTime	����ʱ�����
///@return	�����ַ���ʱ�䣬��ʽ HH24:MM:SS
inline char *getStrFromTime(int nTime)
{
	static char buffer[9];
	time_t	timep = nTime;
	struct tm tm_time;
	LocalTime(&timep, &tm_time);
	sprintf(buffer, "%02d:%02d:%02d", tm_time.tm_hour, tm_time.tm_min, tm_time.tm_sec);
	return buffer;
}

///������ʱ��ȡ�ַ������ں���
///@param	nTime	����ʱ�����
///@return	�����ַ���ʱ�䣬��ʽ YYYYMMDD
inline char *getStrFromDate(int nTime)
{
	static char buffer[9];
	time_t	timep = nTime;
	struct tm tm_time;
	LocalTime(&timep, &tm_time);
	sprintf(
		buffer,
		"%04d%02d%02d",
		1900 + tm_time.tm_year,
		1 + tm_time.tm_mon,
		tm_time.tm_mday);
	return buffer;
}

///������ʱ��ȡ�ַ������ں���
///@param	pOutDate	��������ڣ���ʽYYYYMMDD
///@param	nYear		������꣬����
///@param	nMonth		������·ݣ�������1-12
///@param	pDay		��������ڣ�����
inline void getDateFromMonDay(char *pOutDate, int nYear, int nMonth, int nDay)
{
	if (nMonth < 1 || nMonth > 12)
	{
		printf("������·� %d\n", nMonth);
		fflush(stdout);
	}

	if (nDay < 1 || nDay > 31)
	{
		printf("��������� %d\n", nDay);
		fflush(stdout);
	}

	sprintf(pOutDate, "%04d%02d%02d", nYear / 10000, nMonth, nDay);
}

//���ڲ��������־
class CBufferLogger :
	public CLogger
{
	/* */
	public:
#define MAX_OUTPUTPACKAGESIZE	10000
		CBufferLogger(void)
		{
			reset();
		}

		~CBufferLogger(void)
		{
			m_pBufferEnd = m_pBufferCurr = NULL;
		}

		void reset(void)
		{
			m_pBufferCurr = m_buf;
			m_pBufferEnd = m_buf + MAX_OUTPUTPACKAGESIZE;
			memset(m_buf, 0, MAX_OUTPUTPACKAGESIZE + 1);
		}

		const char *getValue(int &nPackLen)
		{
			nPackLen = m_pBufferCurr - m_buf;
			return m_buf;
		}

		virtual void output(int level, char *format, ...)
		{
			int capacity = m_pBufferEnd - m_pBufferCurr;
			assert(capacity >= 0 && capacity <= MAX_OUTPUTPACKAGESIZE);
			if (!capacity)
			{
				return;
			}

			int len;

			va_list v;
			va_start(v, format);
			len = vsnprintf(m_pBufferCurr, capacity, format, v);
			va_end(v);

			/// Added by Henchi, 20121017
		/// ��len��ǳ����쳣�������ø�ֵΪ�����,��������쳣
			if (len > capacity)
			{
				printf(
					"CBufferLogger::output(): length error, cap[%d] len[%d] pos[%d] Info[%s]\n",
					capacity,
					len,
					m_pBufferCurr - m_buf,
					m_pBufferCurr);
				len = capacity;
				m_buf[MAX_OUTPUTPACKAGESIZE] = 0x00;
			}

			m_pBufferCurr += len;
		}

	/* */
	private:
		char m_buf[MAX_OUTPUTPACKAGESIZE + 1];

		char *m_pBufferCurr;
		char *m_pBufferEnd;
};

class CFileLogger :
	public CLogger
{
	/* */
	public:
		CFileLogger(int level = LL_DEBUG)
		{
			m_fpLogFile = NULL;
			m_level = level;
			INIT_CRITICAL_VAR(m_varCritical);
		}

		~CFileLogger(void)
		{
			DELETE_CRITICAL_VAR(m_varCritical);
			if (m_fpLogFile != NULL)
			{
				SAFE_FCLOSE(m_fpLogFile);
			}
		}

		bool Open(const char *pszFileName)
		{
			ENTER_CRITICAL(m_varCritical);

			//�÷���ֻ�������һ�Σ��ö�������֤
			assert(m_fpLogFile == NULL);

			m_fpLogFile = fopen(pszFileName, "wb");

			LEAVE_CRITICAL(m_varCritical);

			return m_fpLogFile ? true : false;
		}

		/*
    void outputLevelHeader(int level)
    {
        if (level > m_level)
            return;

        ENTER_CRITICAL(m_varCritical); 

        switch (level)
        {
        case LL_EMERG:
            fprintf(m_fpLogFile, "EMERG:\n");
            break;
        case LL_ALERT:
            fprintf(m_fpLogFile, "ALERT:\n");
            break;
        case LL_CRIT:
            fprintf(m_fpLogFile, "CRIT:\n");
            break;
        case LL_ERR:
            fprintf(m_fpLogFile, "ERROR:\n");
            break;
        case LL_WARNING:
            fprintf(m_fpLogFile, "WARNING:\n");
            break;
        case LL_NOTICE:
            fprintf(m_fpLogFile, "NOTICE:\n");
            break;
        case LL_INFO:
            fprintf(m_fpLogFile, "INFO:\n");
            break;
        case LL_DEBUG:
            fprintf(m_fpLogFile, "DEBUG:\n");
            break;
        default:
            assert("Invalid level\n");
        }  

        LEAVE_CRITICAL(m_varCritical);
    }
*/
		virtual void output(int level, char *format, ...)
		{
			if (level > m_level)
			{
				return;
			}

			ENTER_CRITICAL(m_varCritical);

			va_list v;
			va_start(v, format);
			vfprintf(m_fpLogFile, format, v);
			va_end(v);

			fflush(m_fpLogFile);
			LEAVE_CRITICAL(m_varCritical);
		}

	/* */
	private:
		//void outputPrefix(int level)
		//{
		//    switch (level)
		//    {
		//    case LL_EMERG:
		//        fprintf(m_fpLogFile, "EMERG:\n");
		//        break;
		//    case LL_ALERT:
		//        fprintf(m_fpLogFile, "ALERT:\n");
		//        break;
		//    case LL_CRIT:
		//        fprintf(m_fpLogFile, "CRIT:\n");
		//        break;
		//    case LL_ERR:
		//        fprintf(m_fpLogFile, "ERROR:\n");
		//        break;
		//    case LL_WARNING:
		//        fprintf(m_fpLogFile, "WARNING:\n");
		//        break;
		//    case LL_NOTICE:
		//        fprintf(m_fpLogFile, "NOTICE:\n");
		//        break;
		//    case LL_INFO:
		//        fprintf(m_fpLogFile, "INFO:\n");
		//        break;
		//    case LL_DEBUG:
		//        fprintf(m_fpLogFile, "DEBUG:\n");
		//        break;
		//    default:
		//        assert("Invalid level\n");
		//    }
		//}
		FILE *m_fpLogFile;
		int m_level;	// ��־��¼�ļ���
		CRITICAL_VAR m_varCritical;
};

#include "FTDCSession.h"

///����ID������session������
class CObjectIdSession
{
	/* */
	public:
		CObjectIdSession(void)
		{
		}

		~CObjectIdSession(void)
		{
		}

		///���Ӷ���ID����FTD��session��Ϣ
			///@param	objectId	����ID��
			///@param	pSession	�ö�������Ӧ��session
		void addObjectIdSession(const char *objectId, CFTDCSession *pSession)
		{
			//if (m_mapObjectIdSession[objectId] != NULL)
			//{
			//	printf("objectId : %s session %x has exist! \n", objectId, pSession);
			//	fflush(stdout);	
			//}
			m_mapObjectIdSession[objectId] = pSession;
		}

		///ȡ����ID���ڵĻỰ
			///@param	objectId	����ID��
			///@return	���ض�������session
		CFTDCSession *getObjectIdSession(const char *objectId)
		{
			return m_mapObjectIdSession[objectId];
		}

		///ɾ����session�����ж���ID
			///@param	pSession	��Ҫɾ����FTD��session
		void delSession(CFTDCSession *pSession)
		{
			map<string, CFTDCSession *>::iterator iter;
			for (iter = m_mapObjectIdSession.begin();
				 iter != m_mapObjectIdSession.end();)
			{
				if (iter->second == pSession)
				{
					m_mapObjectIdSession.erase(iter++);
				}
				else
				{
					++iter;
				}
			}
		}

	/* */
	protected:
	/* */
	private:
		map<string, CFTDCSession *> m_mapObjectIdSession;
};

typedef struct
{
	DWORD SessionID;
	DWORD RequestId;
	int ConnectId;
} TRID;
class CTRID
{
	/* */
	public:
		DWORD SessionID;	///���յ�����ĻỰID
		DWORD RequestId;	///���յ����������ID
		int ConnectId;		///FTD���ӵ�ID������ȱʡ�����

	/* */
	public:
		CTRID(void)
		{
			SessionID = 0;
			RequestId = 0;
			ConnectId = 0;
		}

		CTRID(DWORD mSessionID, DWORD mRequestID, int mConnectID)
		{
			SessionID = mSessionID;
			RequestId = mRequestID;
			ConnectId = mConnectID;
		}

		CTRID(const CTRID &ob)
		{
			SessionID = ob.SessionID;
			RequestId = ob.RequestId;
			ConnectId = ob.ConnectId;
		}

		void operator=(const CTRID &ob)
		{
			SessionID = ob.SessionID;
			RequestId = ob.RequestId;
			ConnectId = ob.ConnectId;
		}
};
class CManageReqIDSession
{
	/* */
	private:
		vector<CTRID> m_vFid;	///��ǰ���е�SessionID������������Ч�ĺ�ʧЧ��
		list<int> m_lPosition;	///vector�������Ѿ�ʧЧ��λ���б�

	/* */
	public:

		///�������з��������SessionID��RequestID
			///@param	mSessionID	���յ�����ĻỰID
			///@param	mRequestID	���յ����������ID
			///@param	mConnectID	FTD���ӵ�ID������ȱʡ�����
			///@return	��������ת�����µ�RequestID
		int putRequestId(DWORD mSessionID, DWORD mRequestID, int mConnectID)
		{
			m_vFid.push_back(CTRID(mSessionID, mRequestID, mConnectID));
			return m_vFid.size();
		}

		/*
	int putRequestId(DWORD mSessionID, DWORD mRequestID, int mConnectID)
	{
	if (m_lPosition.size()==0)
	{
	m_vFid.push_back(CTRID(mSessionID,mRequestID,mConnectID));
	return (m_vFid.size()-1);
	}else{
	int pos = m_lPosition.front();
	m_lPosition.pop_front();
	m_vFid[pos]=CTRID(mSessionID,mRequestID,mConnectID);
	return pos;
	}
	}
	*/

		///����Ӧ����RequestID�һص��������SessionID��RequestID��ConnectID
			///@param	mCTRID	���ض�Ӧ�����ֵ
			///@param	mRequestID	���յ����������ID
			///@param	bChain	Ӧ����Ľ������
			///@return	���سɹ���ʧ��
		bool getRequestId(CTRID &mTRID, DWORD mRequestID, BYTE bChain)
		{
			if (mRequestID > m_vFid.size())
			{
				return false;
			}

			mTRID = m_vFid[mRequestID - 1];
			return true;
		}

		/*
	bool getRequestId(CTRID & mTRID, DWORD mRequestID, BYTE bChain)
	{
	if (mRequestID >= m_vFid.size())
	{
	return false;
	}
	mTRID=m_vFid[mRequestID];
	if (FTDC_CHAIN_LAST == bChain)
	{
	m_lPosition.push_back(mRequestID);
	}
	return true;
	}
	*/
};

/////////////////////////////////////////////////////////////////////////
///CSeps������ʱ��μ���Ӧ�������ڹ�����
///@author	�ܽ���
///@version	1.0,20090625
/////////////////////////////////////////////////////////////////////////
class CSeps
{
	/* */
	public:

		///���캯��
			///@param	pStr	�ַ�����ʽ��ʱ����,08:00:00-12:00:00.120
		CSeps(const char *pStr)
		{
			char *p = (char *)pStr;
			m_nStart = atoi(p) * 3600 + atoi(p + 3) * 60 + atoi(p + 6);
			p = strchr(p, '-');
			if (p == NULL)
			{
				m_nStart = m_nEnd = m_nInterval = 0;
				printf("���õ�ʱ�����ַ�������ȷ : [%s]\n", pStr);
				fflush(stdout);
			}
			else
			{
				p++;
				m_nEnd = atoi(p) * 3600 + atoi(p + 3) * 60 + atoi(p + 6);
				if (*(p + 8) != '.' && *(p + 8) != '/')
				{
					printf("���õ�ʱ������Ƶ�ʸ�ʽ����ȷ ; [%s]\n", pStr);
					fflush(stdout);
				}

				m_nInterval = atoi(p + 9);
			}
		}

		CSeps(void)
		{
			m_nStart = 0;
			m_nEnd = 0;
			m_nInterval = 0;
		}

		CSeps(const CSeps &ob)
		{
			m_nStart = ob.m_nStart;
			m_nEnd = ob.m_nEnd;
			m_nInterval = ob.m_nInterval;
		}

	/* */
	public:
		int m_nStart;
		int m_nEnd;
		int m_nInterval;
};

/////////////////////////////////////////////////////////////////////////
///CJudgeRun�������жϵ�ǰʱ���Ƿ������ָ��ʱ���Ƶ��������
///@author	�ܽ���
///@version	1.0,20101025
/////////////////////////////////////////////////////////////////////////
class CJudgeRun
{
	/* */
	public:
		CJudgeRun(void)
		{
			m_nLastRunSec = 0;
			m_nInterval = 0;
		}

		CJudgeRun(const char *pSeps)
		{
			m_nLastRunSec = 0;
			m_nInterval = 0;

			char *p = (char *)pSeps;
			while (p != NULL)
			{
				if (isValid(p))
				{
					m_vSep.push_back(CSeps(p));
				}

				p = strchr(p, ',');
				if (p != NULL)
				{
					p++;
				}
			}
		}

		///�������캯��
		CJudgeRun(const CJudgeRun &ob)
		{
			m_nLastRunSec = ob.m_nLastRunSec;
			m_nInterval = ob.m_nInterval;
			m_vSep.clear();
			for (unsigned int i = 0; i < ob.m_vSep.size(); i++)
			{
				m_vSep.push_back(ob.m_vSep[i]);
			}
		}

		CJudgeRun &operator=(const CJudgeRun &ob)
		{
			m_nLastRunSec = ob.m_nLastRunSec;
			m_nInterval = ob.m_nInterval;
			m_vSep.clear();
			for (unsigned int i = 0; i < ob.m_vSep.size(); i++)
			{
				m_vSep.push_back(ob.m_vSep[i]);
			}

			return *this;
		}

		///�ж��ַ����Ƿ����ʱ���Ƶ�ʶ����ʽ
		bool isValid(char *p)
		{
			return
				(
					*(p + 2) == ':'
				&&	*(p + 5) == ':'
				&&	*(p + 8) == '-'
				&&	*(p + 11) == ':'
				&&	*(p + 14) == ':'
				&&	*(p + 17) == '.'
				);
		}

		///�ж��Ƿ���Ҫȡ��ָ��
			///@param	nNowSec	��ϵͳ��ȡ�õ��������Ѿ�������ʱ�
			///@return	true��Ҫִ��,false����Ҫִ��
		bool needExcute(const int nNowSec)
		{
			if (nNowSec < m_nLastRunSec)
			{
				return false;
			}
			else
			{
				int nTemp = nNowSec % 86400;
				for (unsigned int i = 0; i < m_vSep.size(); i++)
				{
					if (nTemp < m_vSep[i].m_nStart)
					{
						m_nLastRunSec = nNowSec - nTemp + m_vSep[i].m_nStart;
						return false;
					}
					else if (nTemp >= m_vSep[i].m_nStart
						 &&	 nTemp < m_vSep[i].m_nEnd)	// ȡ��ʱ��εĲ���Ƶ��
					{
						m_nLastRunSec = nNowSec -
							(
								nNowSec %
								m_vSep[i].m_nInterval
							) +
									m_vSep[i].m_nInterval;
						m_nInterval = m_vSep[i].m_nInterval;
						return true;
					}
				}

				if (m_vSep.size() == 0)
				{
					m_nLastRunSec = nNowSec + 86400;
					return false;
				}
				else
				{
					m_nLastRunSec = nNowSec -
						nTemp +
						86400 +
						m_vSep[0].m_nStart;
					return false;
				}
			}
		}

		int GetInterval(void)
		{
			return m_nInterval;
		}

	/* */
	private:
		///����ʱ������
		vector<CSeps> m_vSep;

		///�ϴβ������ݿ�ʱ��,�ӵ�����㿪ʼ������
		int m_nLastRunSec;

		///����ǰ��ִ��,��Ӧ��ʱ����ֵ
		int m_nInterval;
};

/////////////////////////////////////////////////////////////////////////
///TemplateMutexCatch�������̰߳�ȫ���б�����࣬
///�����װ���̰߳�ȫ���б�֧�����Ӻͻ�ȡ��ȡ�б��С
///@author	�ܽ���
///@version	1.0,20101025
/////////////////////////////////////////////////////////////////////////
template<class T>
class TemplateMutexCatch
{
	/* */
	public:
		TemplateMutexCatch(void)
		{
		}

		~TemplateMutexCatch(void)
		{
		}

		void add(const T &x)
		{
			m_lock.Lock();
			m_listCache.push_front(x);
			m_lock.UnLock();
		}

		bool get(T &x)
		{
			m_lock.Lock();
			if (m_listCache.size() == 0)
			{
				m_listCache.resize(0);
				m_lock.UnLock();
				return false;
			}
			else
			{
				x = m_listCache.back();
				m_listCache.pop_back();
				m_lock.UnLock();
				return true;
			}
		}

		int size(void)
		{
			int listSize = 0;
			m_lock.Lock();
			listSize = m_listCache.size();
			m_lock.UnLock();
			return listSize;
		}

		void clear(void)
		{
			m_lock.Lock();
			m_listCache.clear();
			m_lock.UnLock();
		}

	/* */
	private:
		CMutex	m_lock;
		list<T> m_listCache;
};

/////////////////////////////////////////////////////////////////////////
///TemplateMutexMap�������̰߳�ȫ��map�࣬
///@author    �ܽ���
///@version   1.0,20101025
/////////////////////////////////////////////////////////////////////////
template<class K, class V>
class TemplateMutexMap
{
	/* */
	public:
		TemplateMutexMap(void)
		{
		}

		~TemplateMutexMap(void)
		{
		}

		void add(const K &k, const V &v)
		{
			m_lock.Lock();
			m_mapCache[k] = v;
			m_lock.UnLock();
		}

		bool get(K &k, V &v)
		{
			m_lock.Lock();

			typename map<K, V>::iterator it = m_mapCache.find(k);
			if (it != m_mapCache.end())
			{
				v = m_mapCache[k];
				m_lock.UnLock();
				return true;
			}
			else
			{
				m_lock.UnLock();
				return false;
			}
		}

		//κ��add, 20110815��ɾ��map�е�Ԫ��
		bool del(const K &k)
		{
			m_lock.Lock();

			typename map<K, V>::iterator it = m_mapCache.find(k);
			if (it != m_mapCache.end())
			{
				m_mapCache.erase(it);
				m_lock.UnLock();
				return true;
			}
			else
			{
				m_lock.UnLock();
				return false;
			}
		}

		//κ��add,20110815���޸�map�е�Ԫ��
		bool modify(const K &k, const V &v)
		{
			m_lock.Lock();

			typename map<K, V>::iterator it = m_mapCache.find(k);
			if (it != m_mapCache.end())
			{
				it->second = v;
				m_lock.UnLock();
				return true;
			}
			else
			{
				m_lock.UnLock();
				return false;
			}
		}

		int size(void)
		{
			int listSize = 0;
			m_lock.Lock();
			listSize = m_mapCache.size();
			m_lock.UnLock();
			return listSize;
		}

	/* */
	private:
		CMutex	m_lock;
		map<K, V> m_mapCache;
};

///����Syslog����ļ�ʱ��
class SysReactor :
	public CSelectReactor,
	public CEventHandler
{
	/* */
	public:
		SysReactor(void) :
		CEventHandler(this)
		{
			SetTimer(5, 1000);
		}

		virtual void OnTimer(int nIDEvent)
		{
			if (nIDEvent == 5)
			{
				CMonitorIndex::handleOne();
			}
		}
};
#endif //REF_SYSTOOLS_H
