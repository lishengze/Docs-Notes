

#include "CConfig.h"
#include "CFilelogService.h"
#include "CFPPSubscriber.h"
#include "CFibClient.h"
#include "CFibClient2.h"
#include "FibClientServer.h"
#include "xmlcfg.h"
#include "EventConnect.h"
#include "version.h"
#include <iostream>
#include <CDeployConfig.h>


using namespace std;

extern map<string, list<int> >	g_DataCenterMap;
extern map<CParticipantIDType, list<CUserIDType> >	g_BeijingMap;
extern map<CParticipantIDType, list<CUserIDType> >	g_PudianMap;
extern map<CParticipantIDType, list<CUserIDType> >	g_ZhangjinagMap;

//���ӵ�eventcounter
extern list<CFTDCSession *> sessionList;

//���ӵ�ǰ��
extern list<CFTDCSession *> frontList;
extern map<int, CFTDRspQryFrontStatField> g_FrontStatMap;
extern CCachedFlow	*m_TRFlow;
extern map<CUserIDType, CProtocolInfoType>	g_UserProtocolMap;

extern map<int, map<CProtocolInfoType, int> > g_FrontUserIDMap;
int g_DataCenterFlag;
string	g_mainDataCenter;
string	datacenterPudian;
string	datacenterZhangJ;
string	datacenterBeijing;
string  g_tradetime;
string  g_tradedate;

///���ڰ�IPͳ�Ƶ�¼��
map<string, ipLinkInfo> g_ipLinkInfo;

///��IP�й�ͳ�������Ϣ
map<string, ipLinkInfo> g_ipLinkInfoTuoGuan;

///δ�ڸ���Χ֮�е�ͳ����Ϣ
map<CParticipantIDType, list<userIpInfo> >	theOtherIpInfo;

///δ�ڸ���Χ֮�е�ͳ����Ϣ
map<CParticipantIDType, list<userIpInfo> >	theOtherIpInfoMax;
int theOtherOrderCount = 0;

///���������ļ�����޸�ʱ��
time_t	g_lastChgTime;

//��¼��ǰ������
string	g_strTryDate = "";

CLogger *g_pLoggerOutput = NULL;	// ���ݰ����������ָ��
extern bool UseNetCompressLog;		// ����ѹ����Ϣ�������

// ���յĻ�Աϯλ���ֵ����
MemberSeatData  g_MemberSizeTotal_N;
MemberSeatData  g_UserSessionSizeTotal_N;
MemberSeatData  g_MemberSizeTotal_D;
MemberSeatData  g_UserSessionSizeTotal_D;
// ��ʷ�Ļ�Աϯλ���ֵ����
MemberSeatData  g_HistoryMemberSizeTotal_N;
MemberSeatData  g_HistoryUserSessionSizeTotal_N;
MemberSeatData  g_HistoryMemberSizeTotal_D;
MemberSeatData  g_HistoryUserSessionSizeTotal_D;
//////////////////////////////////////////////////////////////////////////

//fengq
extern map<string, list<string> > g_OrderTraceLife;
extern map<string, CMemberTradeOrderRecTrace> g_PartiTradeOrdPl;

int nTickCnt = 0;

//////////////////////////////////////////////////////////////////////////
const char	*INI_FILE_NAME = "sysfibclient.ini";

//////////////////////////////////////////////////////////////////////////
// ��Ա��·���������������ļ�
// 20150210, modified by cao.ning
const char* g_szMemberLinkAndDataCenterCfg = "datacenter.xml";
// �������ļ��ж�ȡ��Ա��·����������������Ϣ
void loadMemberLinkAndDataCenterCfg();

///������SYSEVENTCOUNTER���ͽ���ϵͳǰ�û���¼����ļ�ʱ����
class CMyTimmer :
	public CEventHandler
{
	/* */
	public:
		CMyTimmer(CReactor *pReactor) :
		CEventHandler(pReactor)
		{
			m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
			SetTimer(1, TIME_FIB2EVENT);
			SetTimer(2, 1000);

			//	SetTimer(3 ,6000);
			//	SetTimer(2, TIME_FIB2FRONT1);
			//	SetTimer(3, TIME_FIB2FRONT2);
		}

		virtual void OnTimer(int nIDEvent)
		{
			///����19800227��������
			char theToday[10];
			{
				time_t	timep;
				time(&timep);

				struct tm tm_time;
				LocalTime(&timep, &tm_time);
				sprintf(
					theToday,
					"%04d%02d%02d",
					tm_time.tm_year + 1900,
					tm_time.tm_mon + 1,
					tm_time.tm_mday);
			}

			///����12:12:12���浱ǰʱ��
			char theTime[10];
			{
				time_t	timep;
				time(&timep);

				struct tm tm_time;
				LocalTime(&timep, &tm_time);
				sprintf(
					theTime,
					"%02d:%02d:%02d",
					tm_time.tm_hour,
					tm_time.tm_min,
					tm_time.tm_sec);
			}

			switch (nIDEvent)
			{
				case 1:
					///����itFrontUserID��������PuDian.app.front.1	OFP_1_0	15��������ʽ
								///��ǰ����ĳЭ���Ӧ��ϯλ��¼��������EventCounter
					{
						map<int, map<CProtocolInfoType, int> >::iterator
							itFrontUserID = g_FrontUserIDMap.begin();
						for (;
							 itFrontUserID != g_FrontUserIDMap.end();
							 itFrontUserID++)
						{
							map<CProtocolInfoType, int>::iterator itProtocol =
								itFrontUserID->second.begin();
							int ftdCount = 0;
							CFTDRtnObjectAttrField	ftdfield;
							bool flag = false;
							for (;
								 itProtocol != itFrontUserID->second.end();
								 itProtocol++)
							{
								m_pkgSend.PreparePackage(
										FTD_TID_RtnObjectAttrTopic,
										FTDC_CHAIN_CONTINUE,
										FTD_VERSION);

								CFTDRtnObjectAttrField	tfield;

								///�����g_DataCenterMap�ĵ�һ��Ԫ�ؼ�pudian��Ӧ��ǰ�����ҵ�g_FrontUserIDMap��ǰ��ID
								string	strTmp = datacenterPudian +
									"." +
									DATACENTERAPP;
								map<string, list<int> >::iterator itMap =
									g_DataCenterMap.find(strTmp);
								if (itMap != g_DataCenterMap.end())
								{
									list<int>::iterator itList = find(
											itMap->second.begin(),
											itMap->second.end(),
											itFrontUserID->first);
									if (itList != itMap->second.end())
									{
										///�ҵ���ObjectIDƴΪPuDian.app.front.(frontid)
										// �ڷ���Э������ָ����Ϣʱ
										// Ϊ����TRADE��TRADE2����ʱ�������º����жϣ���ͬ
										// 20151013��by cao.ning
										sprintf(
											(char *)(tfield.ObjectID.getValue()),
											"%s.%s.%d",
											itFrontUserID->first > 100 ? "TRADE2.PuDian" : "TRADE.PuDian",
											APP_FRONT,
											itFrontUserID->first);
										sprintf(
											(char *)(ftdfield.ObjectID.getValue()),
											"%s.%s.%d",
											datacenterPudian.data(),
											APP_FRONT,
											itFrontUserID->first);
									}
								}

								strTmp = datacenterZhangJ + "." + DATACENTERAPP;
								itMap = g_DataCenterMap.find(strTmp);
								if (itMap != g_DataCenterMap.end())
								{
									list<int>::iterator itList = find(
											itMap->second.begin(),
											itMap->second.end(),
											itFrontUserID->first);
									if (itList != itMap->second.end())
									{
										sprintf(
											(char *)(tfield.ObjectID.getValue()),
											"%s.%s.%d",
											itFrontUserID->first > 100 ? "TRADE2.ZhangJ" : "TRADE.ZhangJ",
											APP_FRONT,
											itFrontUserID->first);
										sprintf(
											(char *)(ftdfield.ObjectID.getValue()),
											"%s.%s.%d",
											datacenterZhangJ.data(),
											APP_FRONT,
											itFrontUserID->first);
									}
								}

								strTmp = datacenterBeijing + "." + DATACENTERAPP;
								itMap = g_DataCenterMap.find(strTmp);
								if (itMap != g_DataCenterMap.end())
								{
									list<int>::iterator itList = find(
											itMap->second.begin(),
											itMap->second.end(),
											itFrontUserID->first);
									if (itList != itMap->second.end())
									{
										sprintf(
											(char *)(tfield.ObjectID.getValue()),
											"%s.%s.%d",
											itFrontUserID->first > 100 ? "TRADE2.BeiJing" : "TRADE.BeiJing",
											APP_FRONT,
											itFrontUserID->first);
										sprintf(
											(char *)(ftdfield.ObjectID.getValue()),
											"%s.%s.%d",
											datacenterBeijing.data(),
											APP_FRONT,
											itFrontUserID->first);
									}
								}

								///������OFP 1.0������AttrTypeת��ΪOFP_1_0��
								tfield.AttrType = itProtocol->first;

								char *p = (char *)tfield.AttrType.getValue();
								while (*p != '\0')
								{
									if (*p == ' ' || *p == '.')
									{
										*p = '_';
									}

									p++;
								}

								///ͳ��ftd����
								string	str = tfield.AttrType.getValue();
								if (str.find(FRONTPROTOCOL) != string::npos)
								{
									ftdCount += itProtocol->second;
									flag = true;
								}

								strcpy((char *)tfield.MonDate.getValue(), theToday);
								strcpy((char *)tfield.MonTime.getValue(), theTime);
								tfield.ValueType = INT_ATTR;
								sprintf(
									(char *)(tfield.AttrValue.getValue()),
									"%d",
									itProtocol->second);
								FTDC_ADD_FIELD(&m_pkgSend, &tfield);
								for (list < CFTDCSession * >::iterator listit =
										 sessionList.begin();
								 listit != sessionList.end();
									 listit++)
								{
									(*listit)->SendRequestPackage(&m_pkgSend);
									m_pkgSend.Pop(FTDCHLEN);
								}
							}

							///����FTD��¼����:
							if (flag)
							{
								m_pkgSend.PreparePackage(
										FTD_TID_RtnObjectAttrTopic,
										FTDC_CHAIN_CONTINUE,
										FTD_VERSION);
								ftdfield.AttrType = ATTRFTDCLIENTCOUNT;
								strcpy(
									(char *)ftdfield.MonDate.getValue(),
									theToday);
								strcpy(
									(char *)ftdfield.MonTime.getValue(),
									theTime);
								ftdfield.ValueType = INT_ATTR;
								sprintf(
									(char *)(ftdfield.AttrValue.getValue()),
									"%d",
									ftdCount);
								if (ftdCount != 0)
								{
									int i = 0;
								}

								FTDC_ADD_FIELD(&m_pkgSend, &ftdfield);
								for (list < CFTDCSession * >::iterator listit =
										 sessionList.begin();
								 listit != sessionList.end();
									 listit++)
								{
									(*listit)->SendRequestPackage(&m_pkgSend);
									m_pkgSend.Pop(FTDCHLEN);
								}
							}
						}

						///�����Ļ�Աϯλ��
						string	strTmp = datacenterPudian + "." + DATACENTERAPP;
						map<string, list<int> >::iterator itDataCenterMap =
							g_DataCenterMap.find(strTmp);
						if (itDataCenterMap != g_DataCenterMap.end())
						{
							///ͨ��g_PudianMapͳ�Ʋ�����PuDian���ӵĻ�Ա��
							{
								m_pkgSend.PreparePackage(
										FTD_TID_RtnObjectAttrTopic,
										FTDC_CHAIN_CONTINUE,
										FTD_VERSION);

								CFTDRtnObjectAttrField	tfield;
								strcpy(
									(char *)tfield.ObjectID.getValue(),
									(itDataCenterMap->first).data());
								strcpy(
									(char *)tfield.AttrType.getValue(),
									APPATTRMEMBERSIZE);
								strcpy((char *)tfield.MonDate.getValue(), theToday);
								strcpy((char *)tfield.MonTime.getValue(), theTime);
								tfield.ValueType = INT_ATTR;

								int count = 0;
								map<CParticipantIDType, list<CUserIDType> >::iterator
									itPudianMap = g_PudianMap.begin();
								for (;
									 itPudianMap != g_PudianMap.end();
									 itPudianMap++)
								{
									count++;
								}

								char value[21];
								sprintf(value, "%d", count);
								strcpy((char *)tfield.AttrValue.getValue(), value);
								FTDC_ADD_FIELD(&m_pkgSend, &tfield);
								for (list < CFTDCSession * >::iterator listit =
										 sessionList.begin();
								 listit != sessionList.end();
									 listit++)
								{
									(*listit)->SendRequestPackage(&m_pkgSend);
									m_pkgSend.Pop(FTDCHLEN);
								}
							}

							///ͨ��g_PudianMapͳ�Ʋ�����PuDian���ӵ�ϯλ����
							{
								m_pkgSend.PreparePackage(
										FTD_TID_RtnObjectAttrTopic,
										FTDC_CHAIN_CONTINUE,
										FTD_VERSION);

								CFTDRtnObjectAttrField	tfield;
								strcpy(
									(char *)tfield.ObjectID.getValue(),
									(itDataCenterMap->first).data());
								strcpy(
									(char *)tfield.AttrType.getValue(),
									APPATTRUSERSESSIONSIZE);
								strcpy((char *)tfield.MonDate.getValue(), theToday);
								strcpy((char *)tfield.MonTime.getValue(), theTime);
								tfield.ValueType = INT_ATTR;

								int count = 0;
								map<CParticipantIDType, list<CUserIDType> >::iterator
									itPudianMap = g_PudianMap.begin();
								for (;
									 itPudianMap != g_PudianMap.end();
									 itPudianMap++)
								{
									list<CUserIDType>::iterator it = itPudianMap->
										second.begin();
									for (; it != itPudianMap->second.end(); it++)
									{
										count++;
									}
								}

								char value[21];
								sprintf(value, "%d", count);
								strcpy((char *)tfield.AttrValue.getValue(), value);
								FTDC_ADD_FIELD(&m_pkgSend, &tfield);
								for (list < CFTDCSession * >::iterator listit =
										 sessionList.begin();
								 listit != sessionList.end();
									 listit++)
								{
									(*listit)->SendRequestPackage(&m_pkgSend);
									m_pkgSend.Pop(FTDCHLEN);
								}
							}
						}

						strTmp = datacenterZhangJ + "." + DATACENTERAPP;
						itDataCenterMap = g_DataCenterMap.find(strTmp);
						if (itDataCenterMap != g_DataCenterMap.end())
						{
							///ͨ��g_ZhangjinagMapͳ�Ʋ�����Zhangj���ӵĻ�Ա��
							{
								m_pkgSend.PreparePackage(
										FTD_TID_RtnObjectAttrTopic,
										FTDC_CHAIN_CONTINUE,
										FTD_VERSION);

								CFTDRtnObjectAttrField	tfield;
								strcpy(
									(char *)tfield.ObjectID.getValue(),
									(itDataCenterMap->first).data());
								strcpy(
									(char *)tfield.AttrType.getValue(),
									APPATTRMEMBERSIZE);
								strcpy((char *)tfield.MonDate.getValue(), theToday);
								strcpy((char *)tfield.MonTime.getValue(), theTime);
								tfield.ValueType = INT_ATTR;

								int count = 0;
								map<CParticipantIDType, list<CUserIDType> >::iterator
									itZhangjinagMap = g_ZhangjinagMap.begin();
								for (;
									 itZhangjinagMap != g_ZhangjinagMap.end();
									 itZhangjinagMap++)
								{
									count++;
								}

								char value[21];
								sprintf(value, "%d", count);
								strcpy((char *)tfield.AttrValue.getValue(), value);
								FTDC_ADD_FIELD(&m_pkgSend, &tfield);
								for (list < CFTDCSession * >::iterator listit =
										 sessionList.begin();
								 listit != sessionList.end();
									 listit++)
								{
									(*listit)->SendRequestPackage(&m_pkgSend);
									m_pkgSend.Pop(FTDCHLEN);
								}
							}

							///ͨ��g_ZhangjinagMapͳ�Ʋ�����Zhangj���ӵ�ϯλ��
							{
								m_pkgSend.PreparePackage(
										FTD_TID_RtnObjectAttrTopic,
										FTDC_CHAIN_CONTINUE,
										FTD_VERSION);

								CFTDRtnObjectAttrField	tfield;
								strcpy(
									(char *)tfield.ObjectID.getValue(),
									(itDataCenterMap->first).data());
								strcpy(
									(char *)tfield.AttrType.getValue(),
									APPATTRUSERSESSIONSIZE);
								strcpy((char *)tfield.MonDate.getValue(), theToday);
								strcpy((char *)tfield.MonTime.getValue(), theTime);
								tfield.ValueType = INT_ATTR;

								int count = 0;
								map<CParticipantIDType, list<CUserIDType> >::iterator
									itZhangjinagMap = g_ZhangjinagMap.begin();
								for (;
									 itZhangjinagMap != g_ZhangjinagMap.end();
									 itZhangjinagMap++)
								{
									list<CUserIDType>::iterator it =
										itZhangjinagMap->second.begin();
									for (;
										 it != itZhangjinagMap->second.end();
										 it++)
									{
										count++;
									}
								}

								char value[21];
								sprintf(value, "%d", count);
								strcpy((char *)tfield.AttrValue.getValue(), value);
								FTDC_ADD_FIELD(&m_pkgSend, &tfield);
								for (list < CFTDCSession * >::iterator listit =
										 sessionList.begin();
								 listit != sessionList.end();
									 listit++)
								{
									(*listit)->SendRequestPackage(&m_pkgSend);
									m_pkgSend.Pop(FTDCHLEN);
								}
							}
						}

						strTmp = datacenterBeijing + "." + DATACENTERAPP;
						itDataCenterMap = g_DataCenterMap.find(strTmp);
						if (itDataCenterMap != g_DataCenterMap.end())
						{
							///ͨ��g_BeijingMapͳ�Ʋ�����Beijing���ӵĻ�Ա��
							{
								m_pkgSend.PreparePackage(
										FTD_TID_RtnObjectAttrTopic,
										FTDC_CHAIN_CONTINUE,
										FTD_VERSION);

								CFTDRtnObjectAttrField	tfield;
								strcpy(
									(char *)tfield.ObjectID.getValue(),
									(itDataCenterMap->first).data());
								strcpy(
									(char *)tfield.AttrType.getValue(),
									APPATTRMEMBERSIZE);
								strcpy((char *)tfield.MonDate.getValue(), theToday);
								strcpy((char *)tfield.MonTime.getValue(), theTime);
								tfield.ValueType = INT_ATTR;

								int count = 0;
								map<CParticipantIDType, list<CUserIDType> >::iterator
									itZhangjinagMap = g_BeijingMap.begin();
								for (;
									 itZhangjinagMap != g_BeijingMap.end();
									 itZhangjinagMap++)
								{
									count++;
								}

								char value[21];
								sprintf(value, "%d", count);
								strcpy((char *)tfield.AttrValue.getValue(), value);
								FTDC_ADD_FIELD(&m_pkgSend, &tfield);
								for (list < CFTDCSession * >::iterator listit =
										 sessionList.begin();
								 listit != sessionList.end();
									 listit++)
								{
									(*listit)->SendRequestPackage(&m_pkgSend);
									m_pkgSend.Pop(FTDCHLEN);
								}
							}

							///ͨ��g_BeijingMapͳ�Ʋ�����beijing���ӵ�ϯλ��
							{
								m_pkgSend.PreparePackage(
										FTD_TID_RtnObjectAttrTopic,
										FTDC_CHAIN_CONTINUE,
										FTD_VERSION);

								CFTDRtnObjectAttrField	tfield;
								strcpy(
									(char *)tfield.ObjectID.getValue(),
									(itDataCenterMap->first).data());
								strcpy(
									(char *)tfield.AttrType.getValue(),
									APPATTRUSERSESSIONSIZE);
								strcpy((char *)tfield.MonDate.getValue(), theToday);
								strcpy((char *)tfield.MonTime.getValue(), theTime);
								tfield.ValueType = INT_ATTR;

								int count = 0;
								map<CParticipantIDType, list<CUserIDType> >::iterator
									itZhangjinagMap = g_BeijingMap.begin();
								for (;
									 itZhangjinagMap != g_BeijingMap.end();
									 itZhangjinagMap++)
								{
									list<CUserIDType>::iterator it =
										itZhangjinagMap->second.begin();
									for (;
										 it != itZhangjinagMap->second.end();
										 it++)
									{
										count++;
									}
								}

								char value[21];
								sprintf(value, "%d", count);
								strcpy((char *)tfield.AttrValue.getValue(), value);
								FTDC_ADD_FIELD(&m_pkgSend, &tfield);
								for (list < CFTDCSession * >::iterator listit =
										 sessionList.begin();
								 listit != sessionList.end();
									 listit++)
								{
									(*listit)->SendRequestPackage(&m_pkgSend);
									m_pkgSend.Pop(FTDCHLEN);
								}
							}
						}

						//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
										///����ip��¼ͳ����Ϣ
						map<string, ipLinkInfo>::iterator it = g_ipLinkInfo.begin();
						for (; it != g_ipLinkInfo.end(); it++)
						{
							///��Ա
							{
								m_pkgSend.PreparePackage(
										FTD_TID_RtnObjectAttrTopic,
										FTDC_CHAIN_CONTINUE,
										FTD_VERSION);

								CFTDRtnObjectAttrField	tfield;
								strcpy(
									(char *)tfield.ObjectID.getValue(),
									(it->first).data());
								strcpy(
									(char *)tfield.AttrType.getValue(),
									APPATTRMEMBERSIZE);
								strcpy((char *)tfield.MonDate.getValue(), theToday);
								strcpy((char *)tfield.MonTime.getValue(), theTime);
								tfield.ValueType = INT_ATTR;

								char value[21];
								sprintf(value, "%d", it->second.linkNumber.size());
								strcpy((char *)tfield.AttrValue.getValue(), value);
								FTDC_ADD_FIELD(&m_pkgSend, &tfield);
								for (list < CFTDCSession * >::iterator listit =
										 sessionList.begin();
								 listit != sessionList.end();
									 listit++)
								{
									(*listit)->SendRequestPackage(&m_pkgSend);
									m_pkgSend.Pop(FTDCHLEN);
								}
							}

							///��ϯ
							{
								m_pkgSend.PreparePackage(
										FTD_TID_RtnObjectAttrTopic,
										FTDC_CHAIN_CONTINUE,
										FTD_VERSION);

								CFTDRtnObjectAttrField	tfield;
								strcpy(
									(char *)tfield.ObjectID.getValue(),
									(it->first).data());
								strcpy(
									(char *)tfield.AttrType.getValue(),
									APPATTRUSERSESSIONSIZE);
								strcpy((char *)tfield.MonDate.getValue(), theToday);
								strcpy((char *)tfield.MonTime.getValue(), theTime);
								tfield.ValueType = INT_ATTR;

								int count = 0;
								map<CParticipantIDType, list<userIpInfo> >::iterator
									itMap = it->second.linkNumber.begin();
								for (;
									 itMap != it->second.linkNumber.end();
									 itMap++)
								{
									count += itMap->second.size();
								}

								char value[21];
								sprintf(value, "%d", count);
								strcpy((char *)tfield.AttrValue.getValue(), value);
								FTDC_ADD_FIELD(&m_pkgSend, &tfield);
								for (list < CFTDCSession * >::iterator listit =
										 sessionList.begin();
								 listit != sessionList.end();
									 listit++)
								{
									(*listit)->SendRequestPackage(&m_pkgSend);
									m_pkgSend.Pop(FTDCHLEN);
								}
							}
						}

						///���ͷ�IP��Χͳ����Ϣ
						{
							it = g_ipLinkInfo.begin();

							string	strOid = it->first;
							strOid = strOid.substr(0, strOid.find_last_of("."));
							strOid += ".0";

							///��Ա
							{
								m_pkgSend.PreparePackage(
										FTD_TID_RtnObjectAttrTopic,
										FTDC_CHAIN_CONTINUE,
										FTD_VERSION);

								CFTDRtnObjectAttrField	tfield;
								strcpy(
									(char *)tfield.ObjectID.getValue(),
									strOid.data());
								strcpy(
									(char *)tfield.AttrType.getValue(),
									APPATTRMEMBERSIZE);
								strcpy((char *)tfield.MonDate.getValue(), theToday);
								strcpy((char *)tfield.MonTime.getValue(), theTime);
								tfield.ValueType = INT_ATTR;

								char value[21];
								sprintf(value, "%d", theOtherIpInfo.size());
								strcpy((char *)tfield.AttrValue.getValue(), value);
								FTDC_ADD_FIELD(&m_pkgSend, &tfield);
								for (list < CFTDCSession * >::iterator listit =
										 sessionList.begin();
								 listit != sessionList.end();
									 listit++)
								{
									(*listit)->SendRequestPackage(&m_pkgSend);
									m_pkgSend.Pop(FTDCHLEN);
								}
							}

							///��ϯ
							{
								m_pkgSend.PreparePackage(
										FTD_TID_RtnObjectAttrTopic,
										FTDC_CHAIN_CONTINUE,
										FTD_VERSION);

								CFTDRtnObjectAttrField	tfield;
								strcpy(
									(char *)tfield.ObjectID.getValue(),
									strOid.data());
								strcpy(
									(char *)tfield.AttrType.getValue(),
									APPATTRUSERSESSIONSIZE);
								strcpy((char *)tfield.MonDate.getValue(), theToday);
								strcpy((char *)tfield.MonTime.getValue(), theTime);
								tfield.ValueType = INT_ATTR;

								int count = 0;
								map<CParticipantIDType, list<userIpInfo> >::iterator
									itMap = theOtherIpInfo.begin();
								for (; itMap != theOtherIpInfo.end(); itMap++)
								{
									count += itMap->second.size();
								}

								char value[21];
								sprintf(value, "%d", count);
								strcpy((char *)tfield.AttrValue.getValue(), value);
								FTDC_ADD_FIELD(&m_pkgSend, &tfield);
								for (list < CFTDCSession * >::iterator listit =
										 sessionList.begin();
								 listit != sessionList.end();
									 listit++)
								{
									(*listit)->SendRequestPackage(&m_pkgSend);
									m_pkgSend.Pop(FTDCHLEN);
								}
							}
						}

						//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
										///�����ܵ�¼ͳ����Ϣ
						{
							int userCount = 0;
							list<CParticipantIDType> partyList;

							//ip��Χ
							map<string, ipLinkInfo>::iterator it = g_ipLinkInfo.
								begin();
							for (; it != g_ipLinkInfo.end(); it++)
							{
								map<CParticipantIDType, list<userIpInfo> >::iterator
									itMap = it->second.linkNumber.begin();
								for (;
									 itMap != it->second.linkNumber.end();
									 itMap++)
								{
									userCount += itMap->second.size();

									list<CParticipantIDType>::iterator	itParty =
										find(
											partyList.begin(),
											partyList.end(),
											itMap->first);
									if (itParty == partyList.end())
									{
										partyList.push_back(itMap->first);
									}
								}
							}

							//��ip��Χ
							map<CParticipantIDType, list<userIpInfo> >::iterator
								itOther = theOtherIpInfo.begin();
							for (; itOther != theOtherIpInfo.end(); itOther++)
							{
								userCount += itOther->second.size();

								list<CParticipantIDType>::iterator	itParty = find(
										partyList.begin(),
										partyList.end(),
										itOther->first);
								if (itParty == partyList.end())
								{
									partyList.push_back(itOther->first);
								}
							}

							///����
							it = g_ipLinkInfo.begin();

							string	strOid = it->first;
							strOid = strOid.substr(0, strOid.find_last_of("."));

							///��Ա
							m_pkgSend.PreparePackage(
									FTD_TID_RtnObjectAttrTopic,
									FTDC_CHAIN_CONTINUE,
									FTD_VERSION);

							CFTDRtnObjectAttrField	tfield;
							memset(&tfield, 0, sizeof(tfield));
							strcpy(
								(char *)tfield.ObjectID.getValue(),
								strOid.data());
							strcpy(
								(char *)tfield.AttrType.getValue(),
								APPATTRMEMBERSIZETOTAL);
							strcpy((char *)tfield.MonDate.getValue(), theToday);
							strcpy((char *)tfield.MonTime.getValue(), theTime);
							tfield.ValueType = INT_ATTR;

							char value[21];
							sprintf(value, "%d", partyList.size());
							strcpy((char *)tfield.AttrValue.getValue(), value);
							FTDC_ADD_FIELD(&m_pkgSend, &tfield);
							for (list < CFTDCSession * >::iterator listit =
									 sessionList.begin();
							 listit != sessionList.end();
								 listit++)
							{
								(*listit)->SendRequestPackage(&m_pkgSend);
								m_pkgSend.Pop(FTDCHLEN);
							}

							///ϯλ
							m_pkgSend.PreparePackage(
									FTD_TID_RtnObjectAttrTopic,
									FTDC_CHAIN_CONTINUE,
									FTD_VERSION);
							memset(&tfield, 0, sizeof(tfield));
							strcpy(
								(char *)tfield.ObjectID.getValue(),
								strOid.data());
							strcpy(
								(char *)tfield.AttrType.getValue(),
								APPATTRUSERSESSIONSIZETOTAL);
							strcpy((char *)tfield.MonDate.getValue(), theToday);
							strcpy((char *)tfield.MonTime.getValue(), theTime);
							tfield.ValueType = INT_ATTR;

							char uservalue[21];
							sprintf(uservalue, "%d", userCount);
							strcpy((char *)tfield.AttrValue.getValue(), uservalue);
							FTDC_ADD_FIELD(&m_pkgSend, &tfield);
							for (list < CFTDCSession * >::iterator listit =
									 sessionList.begin();
							 listit != sessionList.end();
								 listit++)
							{
								(*listit)->SendRequestPackage(&m_pkgSend);
								m_pkgSend.Pop(FTDCHLEN);
							}
						}

						///�����ܵ�¼ͳ����Ϣmax(2max)
						{
							list<CParticipantIDType> partyList;
							list<CUserIDType> userList;

							//ip��Χ
							map<string, ipLinkInfo>::iterator it = g_ipLinkInfo.
								begin();
							for (; it != g_ipLinkInfo.end(); it++)
							{
								map<CParticipantIDType, list<userIpInfo> >::iterator
									itMap = it->second.maxlinkNumber.begin();
								for (;
									 itMap != it->second.maxlinkNumber.end();
									 itMap++)
								{
									//userCount +=itMap->second.size();
									list<userIpInfo>::iterator	itList = itMap->
										second.begin();
									for (; itList != itMap->second.end(); itList++)
									{
										if (find(
												userList.begin(),
											userList.end(),
											itList->id) == userList.end())
										{
											userList.push_back(itList->id);
										}
									}

									list<CParticipantIDType>::iterator	itParty =
										find(
											partyList.begin(),
											partyList.end(),
											itMap->first);
									if (itParty == partyList.end())
									{
										partyList.push_back(itMap->first);
									}
								}
							}

							//��ip��Χ
							map<CParticipantIDType, list<userIpInfo> >::iterator
								itOther = theOtherIpInfoMax.begin();
							for (; itOther != theOtherIpInfoMax.end(); itOther++)
							{
								//userCount +=itOther->second.size();
								list<userIpInfo>::iterator	itList = itOther->
									second.begin();
								for (; itList != itOther->second.end(); itList++)
								{
									if (find(
											userList.begin(),
										userList.end(),
										itList->id) == userList.end())
									{
										userList.push_back(itList->id);
									}
								}

								list<CParticipantIDType>::iterator	itParty = find(
										partyList.begin(),
										partyList.end(),
										itOther->first);
								if (itParty == partyList.end())
								{
									partyList.push_back(itOther->first);
								}
							}

							///����
							it = g_ipLinkInfo.begin();

							string	strOid = it->first;
							strOid = strOid.substr(0, strOid.find_last_of("."));

							///��Ա
							m_pkgSend.PreparePackage(
									FTD_TID_RtnObjectAttrTopic,
									FTDC_CHAIN_CONTINUE,
									FTD_VERSION);

							CFTDRtnObjectAttrField	tfield;
							memset(&tfield, 0, sizeof(tfield));
							strcpy(
								(char *)tfield.ObjectID.getValue(),
								strOid.data());
							strcpy(
								(char *)tfield.AttrType.getValue(),
								APPATTRMAXMEMBERSIZE);
							strcpy((char *)tfield.MonDate.getValue(), theToday);
							strcpy((char *)tfield.MonTime.getValue(), theTime);
							tfield.ValueType = INT_ATTR;

							char value[21];
							sprintf(value, "%d", partyList.size());
							strcpy((char *)tfield.AttrValue.getValue(), value);
							FTDC_ADD_FIELD(&m_pkgSend, &tfield);
							for (list < CFTDCSession * >::iterator listit =
									 sessionList.begin();
							 listit != sessionList.end();
								 listit++)
							{
								(*listit)->SendRequestPackage(&m_pkgSend);
								m_pkgSend.Pop(FTDCHLEN);
							}

							///ϯλ
							m_pkgSend.PreparePackage(
									FTD_TID_RtnObjectAttrTopic,
									FTDC_CHAIN_CONTINUE,
									FTD_VERSION);
							memset(&tfield, 0, sizeof(tfield));
							strcpy(
								(char *)tfield.ObjectID.getValue(),
								strOid.data());
							strcpy(
								(char *)tfield.AttrType.getValue(),
								APPATTRMAXSESSIONSIZE);
							strcpy((char *)tfield.MonDate.getValue(), theToday);
							strcpy((char *)tfield.MonTime.getValue(), theTime);
							tfield.ValueType = INT_ATTR;

							char uservalue[21];
							sprintf(uservalue, "%d", userList.size());
							strcpy((char *)tfield.AttrValue.getValue(), uservalue);
							FTDC_ADD_FIELD(&m_pkgSend, &tfield);
							for (list < CFTDCSession * >::iterator listit =
									 sessionList.begin();
							 listit != sessionList.end();
								 listit++)
							{
								(*listit)->SendRequestPackage(&m_pkgSend);
								m_pkgSend.Pop(FTDCHLEN);
							}

							string strObj="TRADE.PuDian.app.Link";
							string str_trade_date;
							string str_trade_time;
							str_trade_date = g_tradedate=="" ? theToday : g_tradedate;
							str_trade_time = g_tradetime=="" ? theTime : g_tradetime;

							if (str_trade_time >= "06:00:00" && str_trade_time < "18:00:00")
							{
								// 09:00 ~ 09:30 ͳ��ϯλ���ͻ�Ա��
								// 09:30 ֮�󱣴���Ϣ
								if (str_trade_time >= "09:00:00" && str_trade_time <= "09:30:00")
								{
									REPORT_EVENT(0, "MemeberSeat Info: ", "collect max data of daytime!");
									if (partyList.size() > g_MemberSizeTotal_D.i_count)
									{
										g_MemberSizeTotal_D.i_count = partyList.size();
										g_MemberSizeTotal_D.str_date = str_trade_date;
										g_MemberSizeTotal_D.str_time = str_trade_time;
										REPORT_EVENT(0, "MemeberSeat Info: ", "maxer MemberSizeTotal_D:%d", g_MemberSizeTotal_D.i_count);
									}
									if (userList.size() > g_UserSessionSizeTotal_D.i_count)
									{
										g_UserSessionSizeTotal_D.i_count = userList.size();
										g_UserSessionSizeTotal_D.str_date = str_trade_date;
										g_UserSessionSizeTotal_D.str_time = str_trade_time;
										REPORT_EVENT(0, "MemeberSeat Info: ", "maxer UserSessionSizeTotal_D:%d", g_UserSessionSizeTotal_D.i_count);
									}
								}
								else if (str_trade_time > "09:30:00" && str_trade_time < "18:00:00")
								{
									REPORT_EVENT(0, "MemeberSeat Info: ", "prepare save max data of daytime!");
									if (find(m_vecSaveInfo.begin(), m_vecSaveInfo.end(), str_trade_date + "D") == m_vecSaveInfo.end())
									{

										CConfig cfg(INI_FILE_NAME);

										char *pszMemberDataPath = cfg.getConfig("MemberSeatPath");

										CXMLDoc pData;
										string str = pszMemberDataPath;
										str += "/MemberSeat.xml";
										pData.read((char*)(str.data()));

										CXMLNode* pDataRoot = pData.getRootNode();
										CXMLNodeList *pNodeList = pDataRoot->getNodeList();
										bool bDoWrite = false;
										for (int i = 0; i < pNodeList->size(); i++)
										{
											CXMLNode *pNodeCur = (*pNodeList)[i];
											string name = pNodeCur->findProperty("name");
											if (name == "MemberSizeTotal_D" && !g_MemberSizeTotal_D.str_date.empty())
											{
												pNodeCur->setProperty("Date", (char*)(g_MemberSizeTotal_D.str_date.c_str()));
												pNodeCur->setProperty("Time", (char*)(g_MemberSizeTotal_D.str_time.c_str()));
												char value[21];
												sprintf(value, "%d", g_MemberSizeTotal_D.i_count);
												pNodeCur->setProperty("Count", value);
												bDoWrite = true;
											}
											else if (name == "UserSessionSizeTotal_D" && !g_UserSessionSizeTotal_D.str_date.empty())
											{
												pNodeCur->setProperty("Date", (char*)(g_UserSessionSizeTotal_D.str_date.c_str()));
												pNodeCur->setProperty("Time", (char*)(g_UserSessionSizeTotal_D.str_time.c_str()));
												char value[21];
												sprintf(value, "%d", g_UserSessionSizeTotal_D.i_count);
												pNodeCur->setProperty("Count", value);
												bDoWrite = true;
											}
										}
										if (bDoWrite)
										{
											pData.write((char*)(str.data()));
											REPORT_EVENT(0, "MemeberSeat Info: ", "save day maxer data to file!");
											m_vecSaveInfo.push_back(str_trade_date + "D");
											g_MemberSizeTotal_D.i_count = 0;
											g_MemberSizeTotal_D.str_date = "";
											g_MemberSizeTotal_D.str_time = "";

											g_UserSessionSizeTotal_D.i_count = 0;
											g_UserSessionSizeTotal_D.str_date = "";
											g_UserSessionSizeTotal_D.str_time = "";
										}

									}
								}
								// send
								///��Ա
								m_pkgSend.PreparePackage(FTD_TID_RtnObjectAttrTopic, FTDC_CHAIN_CONTINUE, FTD_VERSION);

								CFTDRtnObjectAttrField	tfield;
								memset(&tfield, 0, sizeof(tfield));
								strcpy((char *)tfield.ObjectID.getValue(), strObj.data());
								strcpy((char *)tfield.AttrType.getValue(), "MemberPercent");
								strcpy((char *)tfield.MonDate.getValue(), str_trade_date.data());
								strcpy((char *)tfield.MonTime.getValue(), str_trade_time.data());
								tfield.ValueType = INT_ATTR;


								if (g_HistoryMemberSizeTotal_D.i_count != 0)
								{
									double dbSize = partyList.size();
									double dbCount = g_HistoryMemberSizeTotal_D.i_count;
									int nResult = (int)(dbSize / dbCount * 100);
									char value[21] = { 0 };
									sprintf(value, "%d", nResult);
									strcpy((char *)tfield.AttrValue.getValue(), value);
									FTDC_ADD_FIELD(&m_pkgSend, &tfield);

									for (list < CFTDCSession * >::iterator listit = sessionList.begin();
										listit != sessionList.end();
										listit++)
									{
										(*listit)->SendRequestPackage(&m_pkgSend);
										m_pkgSend.Pop(FTDCHLEN);
									}
								}

								///ϯλ
								m_pkgSend.PreparePackage(FTD_TID_RtnObjectAttrTopic, FTDC_CHAIN_CONTINUE, FTD_VERSION);
								memset(&tfield, 0, sizeof(tfield));
								strcpy((char *)tfield.ObjectID.getValue(), strObj.data());
								strcpy((char *)tfield.AttrType.getValue(), "SeatPercent");
								strcpy((char *)tfield.MonDate.getValue(), str_trade_date.data());
								strcpy((char *)tfield.MonTime.getValue(), str_trade_time.data());
								tfield.ValueType = INT_ATTR;

								if (g_HistoryUserSessionSizeTotal_D.i_count != 0)
								{
									double dbSize = userList.size();
									double dbCount = g_HistoryUserSessionSizeTotal_D.i_count;
									int nResult = (int)(dbSize / dbCount * 100);
									char uservalue[21] = { 0 };
									sprintf(uservalue, "%d", nResult);
									strcpy((char *)tfield.AttrValue.getValue(), uservalue);
									FTDC_ADD_FIELD(&m_pkgSend, &tfield);
									for (list < CFTDCSession * >::iterator listit = sessionList.begin();
										listit != sessionList.end();
										listit++)
									{
										(*listit)->SendRequestPackage(&m_pkgSend);
										m_pkgSend.Pop(FTDCHLEN);
									}
								}

							}
							else // [18:00 ~ 06:00)
							{
								if (str_trade_time >= "21:00:00" && str_trade_time <= "21:30:00")
								{
									REPORT_EVENT(0, "MemeberSeat Info: ", "collect max data of nighttime!");
									if (partyList.size() > g_MemberSizeTotal_N.i_count)
									{
										g_MemberSizeTotal_N.i_count = partyList.size();
										g_MemberSizeTotal_N.str_date = str_trade_date;
										g_MemberSizeTotal_N.str_time = str_trade_time;
										REPORT_EVENT(0, "MemeberSeat Info: ", "maxer MemberSizeTotal_N:%d", g_MemberSizeTotal_N.i_count);
									}
									if (userList.size() > g_UserSessionSizeTotal_N.i_count)
									{
										g_UserSessionSizeTotal_N.i_count = userList.size();
										g_UserSessionSizeTotal_N.str_date = str_trade_date;
										g_UserSessionSizeTotal_N.str_time = str_trade_time;
										REPORT_EVENT(0, "MemeberSeat Info: ", "maxer UserSessionSizeTotal_N:%d", g_UserSessionSizeTotal_N.i_count);
									}
								}
								else if (str_trade_time > "21:30:00" || str_trade_time < "06:00:00")
								{
									REPORT_EVENT(0, "MemeberSeat Info: ", "prepare save max data of nighttime!");
									if (find(m_vecSaveInfo.begin(), m_vecSaveInfo.end(), str_trade_date + "N") == m_vecSaveInfo.end())
									{

										CConfig cfg(INI_FILE_NAME);

										char *pszMemberDataPath = cfg.getConfig("MemberSeatPath");

										CXMLDoc pData;
										string str = pszMemberDataPath;
										str += "/MemberSeat.xml";
										pData.read((char*)(str.data()));

										CXMLNode* pDataRoot = pData.getRootNode();
										CXMLNodeList *pNodeList = pDataRoot->getNodeList();
										bool bDoWrite = false;
										for (int i = 0; i < pNodeList->size(); i++)
										{
											CXMLNode *pNodeCur = (*pNodeList)[i];
											string name = pNodeCur->findProperty("name");
											if (name == "MemberSizeTotal_N" && !g_MemberSizeTotal_N.str_date.empty())
											{
												pNodeCur->setProperty("Date", (char*)(g_MemberSizeTotal_N.str_date.c_str()));
												pNodeCur->setProperty("Time", (char*)(g_MemberSizeTotal_N.str_time.c_str()));
												char value[21];
												sprintf(value, "%d", g_MemberSizeTotal_N.i_count);
												pNodeCur->setProperty("Count", value);
												bDoWrite = true;
											}
											else if (name == "UserSessionSizeTotal_N" && !g_UserSessionSizeTotal_N.str_date.empty())
											{
												pNodeCur->setProperty("Date", (char*)(g_UserSessionSizeTotal_N.str_date.c_str()));
												pNodeCur->setProperty("Time", (char*)(g_UserSessionSizeTotal_N.str_time.c_str()));
												char value[21];
												sprintf(value, "%d", g_UserSessionSizeTotal_N.i_count);
												pNodeCur->setProperty("Count", value);
												bDoWrite = true;
											}
										}
										if (bDoWrite)
										{
											pData.write((char*)(str.data()));
											REPORT_EVENT(0, "MemeberSeat Info: ", "save night maxer data to file!");
											m_vecSaveInfo.push_back(str_trade_date + "N");

											g_MemberSizeTotal_N.i_count = 0;
											g_MemberSizeTotal_N.str_date = "";
											g_MemberSizeTotal_N.str_time = "";

											g_UserSessionSizeTotal_N.i_count = 0;
											g_UserSessionSizeTotal_N.str_date = "";
											g_UserSessionSizeTotal_N.str_time = "";
										}

									}
								}

								///��Ա
								m_pkgSend.PreparePackage(FTD_TID_RtnObjectAttrTopic, FTDC_CHAIN_CONTINUE, FTD_VERSION);

								CFTDRtnObjectAttrField	tfield;
								memset(&tfield, 0, sizeof(tfield));
								strcpy((char *)tfield.ObjectID.getValue(), strObj.data());
								strcpy((char *)tfield.AttrType.getValue(), "MemberPercent");
								strcpy((char *)tfield.MonDate.getValue(), str_trade_date.data());
								strcpy((char *)tfield.MonTime.getValue(), str_trade_time.data());
								tfield.ValueType = INT_ATTR;

								if (g_HistoryMemberSizeTotal_N.i_count != 0)
								{
									double dbSize = partyList.size();
									double dbCount = g_HistoryMemberSizeTotal_N.i_count;
									int nResult = (int)(dbSize / dbCount * 100);
									char value[21] = { 0 };
									sprintf(value, "%d", nResult);
									strcpy((char *)tfield.AttrValue.getValue(), value);
									FTDC_ADD_FIELD(&m_pkgSend, &tfield);
									for (list < CFTDCSession * >::iterator listit = sessionList.begin();
										listit != sessionList.end();
										listit++)
									{
										(*listit)->SendRequestPackage(&m_pkgSend);
										m_pkgSend.Pop(FTDCHLEN);
									}
								}

								///ϯλ
								m_pkgSend.PreparePackage(FTD_TID_RtnObjectAttrTopic, FTDC_CHAIN_CONTINUE, FTD_VERSION);
								memset(&tfield, 0, sizeof(tfield));
								strcpy((char *)tfield.ObjectID.getValue(), strObj.data());
								strcpy((char *)tfield.AttrType.getValue(), "SeatPercent");
								strcpy((char *)tfield.MonDate.getValue(), str_trade_date.data());
								strcpy((char *)tfield.MonTime.getValue(), str_trade_time.data());
								tfield.ValueType = INT_ATTR;


								if (g_HistoryUserSessionSizeTotal_N.i_count != 0)
								{
									double dbSize = userList.size();
									double dbCount = g_HistoryUserSessionSizeTotal_N.i_count;
									int nResult = (int)(dbSize / dbCount * 100);
									char uservalue[21] = { 0 };
									sprintf(uservalue, "%d", nResult);
									strcpy((char *)tfield.AttrValue.getValue(), uservalue);
									FTDC_ADD_FIELD(&m_pkgSend, &tfield);
									for (list < CFTDCSession * >::iterator listit = sessionList.begin();
										listit != sessionList.end();
										listit++)
									{
										(*listit)->SendRequestPackage(&m_pkgSend);
										m_pkgSend.Pop(FTDCHLEN);
									}
								}

							}
#if 0							
							if (str_trade_time>="09:00:00" && str_trade_time<="09:30:00")
							{
								REPORT_EVENT(0, "MemeberSeat Info: ", "collect max data of daytime!");
								if (partyList.size()>g_MemberSizeTotal_D.i_count)
								{
									g_MemberSizeTotal_D.i_count = partyList.size();
									g_MemberSizeTotal_D.str_date = str_trade_date;
									g_MemberSizeTotal_D.str_time = str_trade_time;
									REPORT_EVENT(0, "MemeberSeat Info: ", "maxer MemberSizeTotal_D:%d",g_MemberSizeTotal_D.i_count);
								}
								if (userList.size()>g_UserSessionSizeTotal_D.i_count)
								{
									g_UserSessionSizeTotal_D.i_count = userList.size();
									g_UserSessionSizeTotal_D.str_date = str_trade_date;
									g_UserSessionSizeTotal_D.str_time = str_trade_time;
									REPORT_EVENT(0, "MemeberSeat Info: ", "maxer UserSessionSizeTotal_D:%d",g_UserSessionSizeTotal_D.i_count);
								}
								///��Ա
								m_pkgSend.PreparePackage(
									FTD_TID_RtnObjectAttrTopic,
									FTDC_CHAIN_CONTINUE,
									FTD_VERSION);

								CFTDRtnObjectAttrField	tfield;
								memset(&tfield, 0, sizeof(tfield));
								strcpy(
									(char *)tfield.ObjectID.getValue(),
									strObj.data());
								strcpy(
									(char *)tfield.AttrType.getValue(),
									"MemberPercent");
								strcpy((char *)tfield.MonDate.getValue(), str_trade_date.data());
								strcpy((char *)tfield.MonTime.getValue(), str_trade_time.data());
								tfield.ValueType = INT_ATTR;

								char value[21];
								if (g_HistoryMemberSizeTotal_D.i_count != 0)
								{
									double dbSize = partyList.size();
									double dbCount = g_HistoryMemberSizeTotal_D.i_count;
									int nResult = (int)(dbSize/dbCount*100);
									sprintf(value, "%d", nResult);	
									strcpy((char *)tfield.AttrValue.getValue(), value);
									FTDC_ADD_FIELD(&m_pkgSend, &tfield);
									for (list < CFTDCSession * >::iterator listit =
										sessionList.begin();
										listit != sessionList.end();
									listit++)
									{
										(*listit)->SendRequestPackage(&m_pkgSend);
										m_pkgSend.Pop(FTDCHLEN);
									}								
								}

								///ϯλ
								m_pkgSend.PreparePackage(
									FTD_TID_RtnObjectAttrTopic,
									FTDC_CHAIN_CONTINUE,
									FTD_VERSION);
								memset(&tfield, 0, sizeof(tfield));
								strcpy(
									(char *)tfield.ObjectID.getValue(),
									strObj.data());
								strcpy(
									(char *)tfield.AttrType.getValue(),
									"SeatPercent");
								strcpy((char *)tfield.MonDate.getValue(), str_trade_date.data());
								strcpy((char *)tfield.MonTime.getValue(), str_trade_time.data());
								tfield.ValueType = INT_ATTR;

								char uservalue[21];
								if (g_HistoryUserSessionSizeTotal_D.i_count!=0)
								{
									double dbSize = userList.size();
									double dbCount = g_HistoryUserSessionSizeTotal_D.i_count;
									int nResult = (int)(dbSize/dbCount*100);
									sprintf(uservalue, "%d", nResult);	
									strcpy((char *)tfield.AttrValue.getValue(), uservalue);
									FTDC_ADD_FIELD(&m_pkgSend, &tfield);
									for (list < CFTDCSession * >::iterator listit =
										sessionList.begin();
										listit != sessionList.end();
									listit++)
									{
										(*listit)->SendRequestPackage(&m_pkgSend);
										m_pkgSend.Pop(FTDCHLEN);
									}
								}
							}
							else if (str_trade_time>"09:30:00" && str_trade_time<"21:00:00")
							{
								REPORT_EVENT(0, "MemeberSeat Info: ", "prepare save max data of daytime!");
								if (find(m_vecSaveInfo.begin(), m_vecSaveInfo.end(), str_trade_date+"D")==m_vecSaveInfo.end())
								{
									{
										CConfig cfg(INI_FILE_NAME);

										char *pszMemberDataPath = cfg.getConfig("MemberSeatPath");

										CXMLDoc* pData = new CXMLDoc();
										string str = pszMemberDataPath;
										str += "/MemberSeat.xml";
										pData->read((char*)(str.data()));

										CXMLNode* pDataRoot = pData->getRootNode();
										CXMLNodeList *pNodeList = pDataRoot->getNodeList();
										bool bDoWrite = false;
										for (int i = 0; i < pNodeList->size(); i++)
										{
											CXMLNode *pNodeCur = (*pNodeList)[i];
											string name = pNodeCur->findProperty("name");
											if (name == "MemberSizeTotal_D" && !g_MemberSizeTotal_D.str_date.empty())
											{
												pNodeCur->setProperty("Date", (char*)(g_MemberSizeTotal_D.str_date.c_str()));
												pNodeCur->setProperty("Time", (char*)(g_MemberSizeTotal_D.str_time.c_str()));
												char value[21];
												sprintf(value, "%d", g_MemberSizeTotal_D.i_count);
												pNodeCur->setProperty("Count", value);
												bDoWrite = true;
											}
											else if (name == "UserSessionSizeTotal_D" && !g_UserSessionSizeTotal_D.str_date.empty())
											{
												pNodeCur->setProperty("Date", (char*)(g_UserSessionSizeTotal_D.str_date.c_str()));
												pNodeCur->setProperty("Time", (char*)(g_UserSessionSizeTotal_D.str_time.c_str()));
												char value[21];
												sprintf(value, "%d", g_UserSessionSizeTotal_D.i_count);
												pNodeCur->setProperty("Count", value);
												bDoWrite = true;
											}
										}
										if (bDoWrite)
										{
											pData->write((char*)(str.data()));
											REPORT_EVENT(0, "MemeberSeat Info: ", "save day maxer data to file!");
											m_vecSaveInfo.push_back(str_trade_date+"D");
											g_MemberSizeTotal_D.i_count = 0;
											g_MemberSizeTotal_D.str_date = "";
											g_MemberSizeTotal_D.str_time = "";

											g_UserSessionSizeTotal_D.i_count = 0;
											g_UserSessionSizeTotal_D.str_date = "";
											g_UserSessionSizeTotal_D.str_time = "";
										}	
									}
								}
								///��Ա
								m_pkgSend.PreparePackage(
									FTD_TID_RtnObjectAttrTopic,
									FTDC_CHAIN_CONTINUE,
									FTD_VERSION);

								CFTDRtnObjectAttrField	tfield;
								memset(&tfield, 0, sizeof(tfield));
								strcpy(
									(char *)tfield.ObjectID.getValue(),
									strObj.data());
								strcpy(
									(char *)tfield.AttrType.getValue(),
									"MemberPercent");
								strcpy((char *)tfield.MonDate.getValue(), str_trade_date.data());
								strcpy((char *)tfield.MonTime.getValue(), str_trade_time.data());
								tfield.ValueType = INT_ATTR;

								char value[21];
								if (g_HistoryMemberSizeTotal_D.i_count != 0)
								{
									double dbSize = partyList.size();
									double dbCount = g_HistoryMemberSizeTotal_D.i_count;
									int nResult = (int)(dbSize/dbCount*100);
									sprintf(value, "%d", nResult);	
									strcpy((char *)tfield.AttrValue.getValue(), value);
									FTDC_ADD_FIELD(&m_pkgSend, &tfield);
									for (list < CFTDCSession * >::iterator listit =
										sessionList.begin();
										listit != sessionList.end();
									listit++)
									{
										(*listit)->SendRequestPackage(&m_pkgSend);
										m_pkgSend.Pop(FTDCHLEN);
									}								
								}

								///ϯλ
								m_pkgSend.PreparePackage(
									FTD_TID_RtnObjectAttrTopic,
									FTDC_CHAIN_CONTINUE,
									FTD_VERSION);
								memset(&tfield, 0, sizeof(tfield));
								strcpy(
									(char *)tfield.ObjectID.getValue(),
									strObj.data());
								strcpy(
									(char *)tfield.AttrType.getValue(),
									"SeatPercent");
								strcpy((char *)tfield.MonDate.getValue(), str_trade_date.data());
								strcpy((char *)tfield.MonTime.getValue(), str_trade_time.data());
								tfield.ValueType = INT_ATTR;

								char uservalue[21];
								if (g_HistoryUserSessionSizeTotal_D.i_count!=0)
								{
									double dbSize = userList.size();
									double dbCount = g_HistoryUserSessionSizeTotal_D.i_count;
									int nResult = (int)(dbSize/dbCount*100);
									sprintf(uservalue, "%d", nResult);	
									strcpy((char *)tfield.AttrValue.getValue(), uservalue);
									FTDC_ADD_FIELD(&m_pkgSend, &tfield);
									for (list < CFTDCSession * >::iterator listit =
										sessionList.begin();
										listit != sessionList.end();
									listit++)
									{
										(*listit)->SendRequestPackage(&m_pkgSend);
										m_pkgSend.Pop(FTDCHLEN);
									}
								}
							}
							else if (str_trade_time>="21:00:00" && str_trade_time<="21:30:00")
							{
								REPORT_EVENT(0, "MemeberSeat Info: ", "collect max data of nighttime!");
								if (partyList.size()>g_MemberSizeTotal_N.i_count)
								{
									g_MemberSizeTotal_N.i_count = partyList.size();
									g_MemberSizeTotal_N.str_date = str_trade_date;
									g_MemberSizeTotal_N.str_time = str_trade_time;
									REPORT_EVENT(0, "MemeberSeat Info: ", "maxer MemberSizeTotal_N:%d",g_MemberSizeTotal_N.i_count);
								}
								if (userList.size()>g_UserSessionSizeTotal_N.i_count)
								{
									g_UserSessionSizeTotal_N.i_count = userList.size();
									g_UserSessionSizeTotal_N.str_date = str_trade_date;
									g_UserSessionSizeTotal_N.str_time = str_trade_time;
									REPORT_EVENT(0, "MemeberSeat Info: ", "maxer UserSessionSizeTotal_N:%d",g_UserSessionSizeTotal_N.i_count);
								}
								///��Ա
								m_pkgSend.PreparePackage(
									FTD_TID_RtnObjectAttrTopic,
									FTDC_CHAIN_CONTINUE,
									FTD_VERSION);

								CFTDRtnObjectAttrField	tfield;
								memset(&tfield, 0, sizeof(tfield));
								strcpy(
									(char *)tfield.ObjectID.getValue(),
									strObj.data());
								strcpy(
									(char *)tfield.AttrType.getValue(),
									"MemberPercent");
								strcpy((char *)tfield.MonDate.getValue(), str_trade_date.data());
								strcpy((char *)tfield.MonTime.getValue(), str_trade_time.data());
								tfield.ValueType = INT_ATTR;

								char value[21];
								if (g_HistoryMemberSizeTotal_N.i_count != 0)
								{
									double dbSize = partyList.size();
									double dbCount = g_HistoryMemberSizeTotal_N.i_count;
									int nResult = (int)(dbSize/dbCount*100);
									sprintf(value, "%d", nResult);	
									strcpy((char *)tfield.AttrValue.getValue(), value);
									FTDC_ADD_FIELD(&m_pkgSend, &tfield);
									for (list < CFTDCSession * >::iterator listit =
										sessionList.begin();
										listit != sessionList.end();
									listit++)
									{
										(*listit)->SendRequestPackage(&m_pkgSend);
										m_pkgSend.Pop(FTDCHLEN);
									}								
								}

								///ϯλ
								m_pkgSend.PreparePackage(
									FTD_TID_RtnObjectAttrTopic,
									FTDC_CHAIN_CONTINUE,
									FTD_VERSION);
								memset(&tfield, 0, sizeof(tfield));
								strcpy(
									(char *)tfield.ObjectID.getValue(),
									strObj.data());
								strcpy(
									(char *)tfield.AttrType.getValue(),
									"SeatPercent");
								strcpy((char *)tfield.MonDate.getValue(), str_trade_date.data());
								strcpy((char *)tfield.MonTime.getValue(), str_trade_time.data());
								tfield.ValueType = INT_ATTR;

								char uservalue[21];
								if (g_HistoryUserSessionSizeTotal_N.i_count!=0)
								{
									double dbSize = userList.size();
									double dbCount = g_HistoryUserSessionSizeTotal_N.i_count;
									int nResult = (int)(dbSize/dbCount*100);
									sprintf(uservalue, "%d", nResult);	
									strcpy((char *)tfield.AttrValue.getValue(), uservalue);
									FTDC_ADD_FIELD(&m_pkgSend, &tfield);
									for (list < CFTDCSession * >::iterator listit =
										sessionList.begin();
										listit != sessionList.end();
									listit++)
									{
										(*listit)->SendRequestPackage(&m_pkgSend);
										m_pkgSend.Pop(FTDCHLEN);
									}
								}
							}
							else
							{
								REPORT_EVENT(0, "MemeberSeat Info: ", "prepare save max data of nighttime!");
								if (find(m_vecSaveInfo.begin(), m_vecSaveInfo.end(), str_trade_date+"N")==m_vecSaveInfo.end())
								{
									{
										CConfig cfg(INI_FILE_NAME);

										char *pszMemberDataPath = cfg.getConfig("MemberSeatPath");

										CXMLDoc* pData = new CXMLDoc();
										string str = pszMemberDataPath;
										str += "/MemberSeat.xml";
										pData->read((char*)(str.data()));

										CXMLNode* pDataRoot = pData->getRootNode();
										CXMLNodeList *pNodeList = pDataRoot->getNodeList();
										bool bDoWrite=false;
										for (int i = 0; i < pNodeList->size(); i++)
										{
											CXMLNode *pNodeCur = (*pNodeList)[i];
											string name = pNodeCur->findProperty("name");
											if (name == "MemberSizeTotal_N" && !g_MemberSizeTotal_N.str_date.empty())
											{
												pNodeCur->setProperty("Date", (char*)(g_MemberSizeTotal_N.str_date.c_str()));
												pNodeCur->setProperty("Time", (char*)(g_MemberSizeTotal_N.str_time.c_str()));
												char value[21];
												sprintf(value, "%d", g_MemberSizeTotal_N.i_count);
												pNodeCur->setProperty("Count", value);
												bDoWrite = true;
											}
											else if (name == "UserSessionSizeTotal_N" && !g_UserSessionSizeTotal_N.str_date.empty())
											{
												pNodeCur->setProperty("Date", (char*)(g_UserSessionSizeTotal_N.str_date.c_str()));
												pNodeCur->setProperty("Time", (char*)(g_UserSessionSizeTotal_N.str_time.c_str()));
												char value[21];
												sprintf(value, "%d", g_UserSessionSizeTotal_N.i_count);
												pNodeCur->setProperty("Count", value);
												bDoWrite = true;
											}
										}
										if (bDoWrite)
										{
											pData->write((char*)(str.data()));
											REPORT_EVENT(0, "MemeberSeat Info: ", "save night maxer data to file!");
											m_vecSaveInfo.push_back(str_trade_date+"N");

											g_MemberSizeTotal_N.i_count = 0;
											g_MemberSizeTotal_N.str_date = "";
											g_MemberSizeTotal_N.str_time = "";

											g_UserSessionSizeTotal_N.i_count = 0;
											g_UserSessionSizeTotal_N.str_date = "";
											g_UserSessionSizeTotal_N.str_time = "";
										}
									}		
								}
								///��Ա
								m_pkgSend.PreparePackage(
									FTD_TID_RtnObjectAttrTopic,
									FTDC_CHAIN_CONTINUE,
									FTD_VERSION);

								CFTDRtnObjectAttrField	tfield;
								memset(&tfield, 0, sizeof(tfield));
								strcpy(
									(char *)tfield.ObjectID.getValue(),
									strObj.data());
								strcpy(
									(char *)tfield.AttrType.getValue(),
									"MemberPercent");
								strcpy((char *)tfield.MonDate.getValue(), str_trade_date.data());
								strcpy((char *)tfield.MonTime.getValue(), str_trade_time.data());
								tfield.ValueType = INT_ATTR;

								char value[21];
								if (g_HistoryMemberSizeTotal_N.i_count != 0)
								{
									double dbSize = partyList.size();
									double dbCount = g_HistoryMemberSizeTotal_N.i_count;
									int nResult = (int)(dbSize/dbCount*100);
									sprintf(value, "%d", nResult);	
									strcpy((char *)tfield.AttrValue.getValue(), value);
									FTDC_ADD_FIELD(&m_pkgSend, &tfield);
									for (list < CFTDCSession * >::iterator listit =
										sessionList.begin();
										listit != sessionList.end();
									listit++)
									{
										(*listit)->SendRequestPackage(&m_pkgSend);
										m_pkgSend.Pop(FTDCHLEN);
									}								
								}

								///ϯλ
								m_pkgSend.PreparePackage(
									FTD_TID_RtnObjectAttrTopic,
									FTDC_CHAIN_CONTINUE,
									FTD_VERSION);
								memset(&tfield, 0, sizeof(tfield));
								strcpy(
									(char *)tfield.ObjectID.getValue(),
									strObj.data());
								strcpy(
									(char *)tfield.AttrType.getValue(),
									"SeatPercent");
								strcpy((char *)tfield.MonDate.getValue(), str_trade_date.data());
								strcpy((char *)tfield.MonTime.getValue(), str_trade_time.data());
								tfield.ValueType = INT_ATTR;

								char uservalue[21];
								if (g_HistoryUserSessionSizeTotal_N.i_count!=0)
								{
									double dbSize = userList.size();
									double dbCount = g_HistoryUserSessionSizeTotal_N.i_count;
									int nResult = (int)(dbSize/dbCount*100);
									sprintf(uservalue, "%d", nResult);	
									strcpy((char *)tfield.AttrValue.getValue(), uservalue);
									FTDC_ADD_FIELD(&m_pkgSend, &tfield);
									for (list < CFTDCSession * >::iterator listit =
										sessionList.begin();
										listit != sessionList.end();
									listit++)
									{
										(*listit)->SendRequestPackage(&m_pkgSend);
										m_pkgSend.Pop(FTDCHLEN);
									}
								}
							}
#endif
						}

						///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
										///�����й�ip��¼ͳ����Ϣ
						it = g_ipLinkInfoTuoGuan.begin();
						for (; it != g_ipLinkInfoTuoGuan.end(); it++)
						{
							///��Ա
							{
								string	strOid = it->first;
								strOid = strOid.substr(0, strOid.find_last_of("_"));

								string	strAttr = APPATTRMEMBERSIZETUOGUAN;
								strAttr = strAttr + "_" + it->second.type;

								m_pkgSend.PreparePackage(
										FTD_TID_RtnObjectAttrTopic,
										FTDC_CHAIN_CONTINUE,
										FTD_VERSION);

								CFTDRtnObjectAttrField	tfield;
								strcpy(
									(char *)tfield.ObjectID.getValue(),
									strOid.data());
								strcpy(
									(char *)tfield.AttrType.getValue(),
									strAttr.data());
								strcpy((char *)tfield.MonDate.getValue(), theToday);
								strcpy((char *)tfield.MonTime.getValue(), theTime);
								tfield.ValueType = INT_ATTR;

								char value[21];
								sprintf(value, "%d", it->second.linkNumber.size());
								strcpy((char *)tfield.AttrValue.getValue(), value);
								FTDC_ADD_FIELD(&m_pkgSend, &tfield);
								for (list < CFTDCSession * >::iterator listit =
										 sessionList.begin();
								 listit != sessionList.end();
									 listit++)
								{
									(*listit)->SendRequestPackage(&m_pkgSend);
									m_pkgSend.Pop(FTDCHLEN);
								}
							}

							///��ϯ
							{
								string	strOid = it->first;
								strOid = strOid.substr(0, strOid.find_last_of("_"));

								string	strAttr = APPATTRUSERSESSIONSIZETUOGUAN;
								strAttr = strAttr + "_" + it->second.type;

								m_pkgSend.PreparePackage(
										FTD_TID_RtnObjectAttrTopic,
										FTDC_CHAIN_CONTINUE,
										FTD_VERSION);

								CFTDRtnObjectAttrField	tfield;
								strcpy(
									(char *)tfield.ObjectID.getValue(),
									strOid.data());
								strcpy(
									(char *)tfield.AttrType.getValue(),
									strAttr.data());
								strcpy((char *)tfield.MonDate.getValue(), theToday);
								strcpy((char *)tfield.MonTime.getValue(), theTime);
								tfield.ValueType = INT_ATTR;

								int count = 0;
								map<CParticipantIDType, list<userIpInfo> >::iterator
									itMap = it->second.linkNumber.begin();
								for (;
									 itMap != it->second.linkNumber.end();
									 itMap++)
								{
									count += itMap->second.size();
								}

								char value[21];
								sprintf(value, "%d", count);
								strcpy((char *)tfield.AttrValue.getValue(), value);
								FTDC_ADD_FIELD(&m_pkgSend, &tfield);
								for (list < CFTDCSession * >::iterator listit =
										 sessionList.begin();
								 listit != sessionList.end();
									 listit++)
								{
									(*listit)->SendRequestPackage(&m_pkgSend);
									m_pkgSend.Pop(FTDCHLEN);
								}
							}
						}

						///�����й��ܵ�¼ͳ����Ϣ
						{
							int sfitCount = 0;
							list<CParticipantIDType> sfitList;
							int dfitcCount = 0;
							list<CParticipantIDType> dfitcList;

							//ip��Χ
							map<string, ipLinkInfo>::iterator it =
								g_ipLinkInfoTuoGuan.begin();
							for (; it != g_ipLinkInfoTuoGuan.end(); it++)
							{
								map<CParticipantIDType, list<userIpInfo> >::iterator
									itMap = it->second.linkNumber.begin();
								for (;
									 itMap != it->second.linkNumber.end();
									 itMap++)
								{
									if (it->second.type == "SFIT")
									{
										sfitCount += itMap->second.size();

										list<CParticipantIDType>::iterator
											itParty = find(
													sfitList.begin(),
													sfitList.end(),
													itMap->first);
										if (itParty == sfitList.end())
										{
											sfitList.push_back(itMap->first);
										}
									}
									else if (it->second.type == "DFITC")
									{
										dfitcCount += itMap->second.size();

										list<CParticipantIDType>::iterator
											itParty = find(
													dfitcList.begin(),
													dfitcList.end(),
													itMap->first);
										if (itParty == dfitcList.end())
										{
											dfitcList.push_back(itMap->first);
										}
									}
								}
							}

							///����
							it = g_ipLinkInfoTuoGuan.begin();

							string	strOid = it->first;
							strOid = strOid.substr(0, strOid.find_last_of("_"));
							strOid = strOid.substr(0, strOid.find_last_of("."));

							///sfit��Ա
							m_pkgSend.PreparePackage(
									FTD_TID_RtnObjectAttrTopic,
									FTDC_CHAIN_CONTINUE,
									FTD_VERSION);

							CFTDRtnObjectAttrField	tfield;
							memset(&tfield, 0, sizeof(tfield));
							strcpy(
								(char *)tfield.ObjectID.getValue(),
								strOid.data());

							string	strAttr = APPATTRMEMBERSIZETOTALTUOGUAN;
							strAttr = strAttr + "_" + "SFIT";
							strcpy(
								(char *)tfield.AttrType.getValue(),
								strAttr.data());
							strcpy((char *)tfield.MonDate.getValue(), theToday);
							strcpy((char *)tfield.MonTime.getValue(), theTime);
							tfield.ValueType = INT_ATTR;

							char sfitvalue[21];
							sprintf(sfitvalue, "%d", sfitList.size());
							strcpy((char *)tfield.AttrValue.getValue(), sfitvalue);
							FTDC_ADD_FIELD(&m_pkgSend, &tfield);
							for (list < CFTDCSession * >::iterator listit =
									 sessionList.begin();
							 listit != sessionList.end();
								 listit++)
							{
								(*listit)->SendRequestPackage(&m_pkgSend);
								m_pkgSend.Pop(FTDCHLEN);
							}

							///sfitϯλ
							m_pkgSend.PreparePackage(
									FTD_TID_RtnObjectAttrTopic,
									FTDC_CHAIN_CONTINUE,
									FTD_VERSION);
							memset(&tfield, 0, sizeof(tfield));
							strcpy(
								(char *)tfield.ObjectID.getValue(),
								strOid.data());
							strAttr = APPATTRUSERSESSIONSIZETOTALTUOGUAN;
							strAttr = strAttr + "_" + "SFIT";
							strcpy(
								(char *)tfield.AttrType.getValue(),
								strAttr.data());
							strcpy((char *)tfield.MonDate.getValue(), theToday);
							strcpy((char *)tfield.MonTime.getValue(), theTime);
							tfield.ValueType = INT_ATTR;

							char sfituservalue[21];
							sprintf(sfituservalue, "%d", sfitCount);
							strcpy(
								(char *)tfield.AttrValue.getValue(),
								sfituservalue);
							FTDC_ADD_FIELD(&m_pkgSend, &tfield);
							for (list < CFTDCSession * >::iterator listit =
									 sessionList.begin();
							 listit != sessionList.end();
								 listit++)
							{
								(*listit)->SendRequestPackage(&m_pkgSend);
								m_pkgSend.Pop(FTDCHLEN);
							}

							///dfitc��Ա
							m_pkgSend.PreparePackage(
									FTD_TID_RtnObjectAttrTopic,
									FTDC_CHAIN_CONTINUE,
									FTD_VERSION);
							memset(&tfield, 0, sizeof(tfield));
							strcpy(
								(char *)tfield.ObjectID.getValue(),
								strOid.data());
							strAttr = APPATTRMEMBERSIZETOTALTUOGUAN;
							strAttr = strAttr + "_" + "DFITC";
							strcpy(
								(char *)tfield.AttrType.getValue(),
								strAttr.data());
							strcpy((char *)tfield.MonDate.getValue(), theToday);
							strcpy((char *)tfield.MonTime.getValue(), theTime);
							tfield.ValueType = INT_ATTR;

							char dfitcvalue[21];
							sprintf(dfitcvalue, "%d", dfitcList.size());
							strcpy((char *)tfield.AttrValue.getValue(), dfitcvalue);
							FTDC_ADD_FIELD(&m_pkgSend, &tfield);
							for (list < CFTDCSession * >::iterator listit =
									 sessionList.begin();
							 listit != sessionList.end();
								 listit++)
							{
								(*listit)->SendRequestPackage(&m_pkgSend);
								m_pkgSend.Pop(FTDCHLEN);
							}

							///dfitcϯλ
							m_pkgSend.PreparePackage(
									FTD_TID_RtnObjectAttrTopic,
									FTDC_CHAIN_CONTINUE,
									FTD_VERSION);
							memset(&tfield, 0, sizeof(tfield));
							strcpy(
								(char *)tfield.ObjectID.getValue(),
								strOid.data());
							strAttr = APPATTRUSERSESSIONSIZETOTALTUOGUAN;
							strAttr = strAttr + "_" + "DFITC";
							strcpy(
								(char *)tfield.AttrType.getValue(),
								strAttr.data());
							strcpy((char *)tfield.MonDate.getValue(), theToday);
							strcpy((char *)tfield.MonTime.getValue(), theTime);
							tfield.ValueType = INT_ATTR;

							char dfitcuservalue[21];
							sprintf(dfitcuservalue, "%d", dfitcCount);
							strcpy(
								(char *)tfield.AttrValue.getValue(),
								dfitcuservalue);
							FTDC_ADD_FIELD(&m_pkgSend, &tfield);
							for (list < CFTDCSession * >::iterator listit =
									 sessionList.begin();
							 listit != sessionList.end();
								 listit++)
							{
								(*listit)->SendRequestPackage(&m_pkgSend);
								m_pkgSend.Pop(FTDCHLEN);
							}
						}

						///�����й��ܵ�¼ͳ����Ϣmax(4max)
						{
							list<CParticipantIDType> sfitList;
							list<CParticipantIDType> dfitcList;
							list<CUserIDType> sfitUserList;
							list<CUserIDType> dfitcUserList;

							//ip��Χ
							map<string, ipLinkInfo>::iterator it =
								g_ipLinkInfoTuoGuan.begin();
							for (; it != g_ipLinkInfoTuoGuan.end(); it++)
							{
								map<CParticipantIDType, list<userIpInfo> >::iterator
									itMap = it->second.maxlinkNumber.begin();
								for (;
									 itMap != it->second.maxlinkNumber.end();
									 itMap++)
								{
									if (it->second.type == "SFIT")
									{
										//sfitCount +=itMap->second.size();
										list<userIpInfo>::iterator	itList = itMap->
											second.begin();
										for (;
											 itList != itMap->second.end();
											 itList++)
										{
											if (find(
													sfitUserList.begin(),
												sfitUserList.end(),
												itList->id) == sfitUserList.end())
											{
												sfitUserList.push_back(itList->id);
											}
										}

										list<CParticipantIDType>::iterator
											itParty = find(
													sfitList.begin(),
													sfitList.end(),
													itMap->first);
										if (itParty == sfitList.end())
										{
											sfitList.push_back(itMap->first);
										}
									}
									else if (it->second.type == "DFITC")
									{
										//dfitcCount +=itMap->second.size();
										list<userIpInfo>::iterator	itList = itMap->
											second.begin();
										for (;
											 itList != itMap->second.end();
											 itList++)
										{
											if (find(
													dfitcUserList.begin(),
												dfitcUserList.end(),
												itList->id) == dfitcUserList.end())
											{
												dfitcUserList.push_back(itList->id);
											}
										}

										list<CParticipantIDType>::iterator
											itParty = find(
													dfitcList.begin(),
													dfitcList.end(),
													itMap->first);
										if (itParty == dfitcList.end())
										{
											dfitcList.push_back(itMap->first);
										}
									}
								}
							}

							///����
							it = g_ipLinkInfoTuoGuan.begin();

							string	strOid = it->first;
							strOid = strOid.substr(0, strOid.find_last_of("_"));
							strOid = strOid.substr(0, strOid.find_last_of("."));

							///sfit��Ա
							m_pkgSend.PreparePackage(
									FTD_TID_RtnObjectAttrTopic,
									FTDC_CHAIN_CONTINUE,
									FTD_VERSION);

							CFTDRtnObjectAttrField	tfield;
							memset(&tfield, 0, sizeof(tfield));
							strcpy(
								(char *)tfield.ObjectID.getValue(),
								strOid.data());

							string	strAttr = APPATTRMAXMEMBERSIZETUOGUAN;
							strAttr = strAttr + "_" + "SFIT";
							strcpy(
								(char *)tfield.AttrType.getValue(),
								strAttr.data());
							strcpy((char *)tfield.MonDate.getValue(), theToday);
							strcpy((char *)tfield.MonTime.getValue(), theTime);
							tfield.ValueType = INT_ATTR;

							char sfitvalue[21];
							sprintf(sfitvalue, "%d", sfitList.size());
							strcpy((char *)tfield.AttrValue.getValue(), sfitvalue);
							FTDC_ADD_FIELD(&m_pkgSend, &tfield);
							for (list < CFTDCSession * >::iterator listit =
									 sessionList.begin();
							 listit != sessionList.end();
								 listit++)
							{
								(*listit)->SendRequestPackage(&m_pkgSend);
								m_pkgSend.Pop(FTDCHLEN);
							}

							///sfitϯλ
							m_pkgSend.PreparePackage(
									FTD_TID_RtnObjectAttrTopic,
									FTDC_CHAIN_CONTINUE,
									FTD_VERSION);
							memset(&tfield, 0, sizeof(tfield));
							strcpy(
								(char *)tfield.ObjectID.getValue(),
								strOid.data());
							strAttr = APPATTRMAXSESSIONSIZETUOGUAN;
							strAttr = strAttr + "_" + "SFIT";
							strcpy(
								(char *)tfield.AttrType.getValue(),
								strAttr.data());
							strcpy((char *)tfield.MonDate.getValue(), theToday);
							strcpy((char *)tfield.MonTime.getValue(), theTime);
							tfield.ValueType = INT_ATTR;

							char sfituservalue[21];
							sprintf(sfituservalue, "%d", sfitUserList.size());
							strcpy(
								(char *)tfield.AttrValue.getValue(),
								sfituservalue);
							FTDC_ADD_FIELD(&m_pkgSend, &tfield);
							for (list < CFTDCSession * >::iterator listit =
									 sessionList.begin();
							 listit != sessionList.end();
								 listit++)
							{
								(*listit)->SendRequestPackage(&m_pkgSend);
								m_pkgSend.Pop(FTDCHLEN);
							}

							///dfitc��Ա
							m_pkgSend.PreparePackage(
									FTD_TID_RtnObjectAttrTopic,
									FTDC_CHAIN_CONTINUE,
									FTD_VERSION);
							memset(&tfield, 0, sizeof(tfield));
							strcpy(
								(char *)tfield.ObjectID.getValue(),
								strOid.data());
							strAttr = APPATTRMAXMEMBERSIZETUOGUAN;
							strAttr = strAttr + "_" + "DFITC";
							strcpy(
								(char *)tfield.AttrType.getValue(),
								strAttr.data());
							strcpy((char *)tfield.MonDate.getValue(), theToday);
							strcpy((char *)tfield.MonTime.getValue(), theTime);
							tfield.ValueType = INT_ATTR;

							char dfitcvalue[21];
							sprintf(dfitcvalue, "%d", dfitcList.size());
							strcpy((char *)tfield.AttrValue.getValue(), dfitcvalue);
							FTDC_ADD_FIELD(&m_pkgSend, &tfield);
							for (list < CFTDCSession * >::iterator listit =
									 sessionList.begin();
							 listit != sessionList.end();
								 listit++)
							{
								(*listit)->SendRequestPackage(&m_pkgSend);
								m_pkgSend.Pop(FTDCHLEN);
							}

							///dfitcϯλ
							m_pkgSend.PreparePackage(
									FTD_TID_RtnObjectAttrTopic,
									FTDC_CHAIN_CONTINUE,
									FTD_VERSION);
							memset(&tfield, 0, sizeof(tfield));
							strcpy(
								(char *)tfield.ObjectID.getValue(),
								strOid.data());
							strAttr = APPATTRMAXSESSIONSIZETUOGUAN;
							strAttr = strAttr + "_" + "DFITC";
							strcpy(
								(char *)tfield.AttrType.getValue(),
								strAttr.data());
							strcpy((char *)tfield.MonDate.getValue(), theToday);
							strcpy((char *)tfield.MonTime.getValue(), theTime);
							tfield.ValueType = INT_ATTR;

							char dfitcuservalue[21];
							sprintf(dfitcuservalue, "%d", dfitcUserList.size());
							strcpy(
								(char *)tfield.AttrValue.getValue(),
								dfitcuservalue);
							FTDC_ADD_FIELD(&m_pkgSend, &tfield);
							for (list < CFTDCSession * >::iterator listit =
									 sessionList.begin();
							 listit != sessionList.end();
								 listit++)
							{
								(*listit)->SendRequestPackage(&m_pkgSend);
								m_pkgSend.Pop(FTDCHLEN);
							}
						}
					}

					break;
				case 2:
					///����ʱip��Χ������ͳ��
					{
						map<string, ipLinkInfo>::iterator it = g_ipLinkInfo.begin();
						for (; it != g_ipLinkInfo.end(); it++)
						{
							m_pkgSend.PreparePackage(
									FTD_TID_RtnObjectAttrTopic,
									FTDC_CHAIN_CONTINUE,
									FTD_VERSION);

							CFTDRtnObjectAttrField	tfield;
							strcpy(
								(char *)tfield.ObjectID.getValue(),
								(it->first).data());
							strcpy(
								(char *)tfield.AttrType.getValue(),
								APPATTRORDERSIZE);
							strcpy((char *)tfield.MonDate.getValue(), theToday);
							strcpy((char *)tfield.MonTime.getValue(), theTime);
							tfield.ValueType = INT_ATTR;

							char value[21];
							sprintf(value, "%d", it->second.orderCount);
							strcpy((char *)tfield.AttrValue.getValue(), value);
							FTDC_ADD_FIELD(&m_pkgSend, &tfield);
							for (list < CFTDCSession * >::iterator listit =
									 sessionList.begin();
							 listit != sessionList.end();
								 listit++)
							{
								(*listit)->SendRequestPackage(&m_pkgSend);
								m_pkgSend.Pop(FTDCHLEN);
							}
						}
					}

					///����ʱ�й�ip��Χ������ͳ��,��ʱע��
					{
						/*map<string ,ipLinkInfo>::iterator it =g_ipLinkInfoTuoGuan.begin();
				for( ;it !=g_ipLinkInfoTuoGuan.end() ;it ++)
				{
					m_pkgSend.PreparePackage(FTD_TID_RtnObjectAttrTopic, FTDC_CHAIN_CONTINUE, FTD_VERSION);
					CFTDRtnObjectAttrField tfield;
					strcpy((char *)tfield.ObjectID.getValue() ,(it->first).data());
					strcpy((char *)tfield.AttrType.getValue() ,APPATTRORDERSIZETUOGUAN);
					strcpy((char *)tfield.MonDate.getValue() ,theToday);
					strcpy((char *)tfield.MonTime.getValue() ,theTime);
					tfield.ValueType		=INT_ATTR;
					char value[21];
					sprintf(value,"%d", it->second.orderCount);
					strcpy((char *)tfield.AttrValue.getValue() ,value);
					FTDC_ADD_FIELD(&m_pkgSend, &tfield);
					for(list<CFTDCSession *>::iterator listit =sessionList.begin() ;listit !=sessionList.end() ;listit ++)
					{
						(*listit)->SendRequestPackage(&m_pkgSend);
						m_pkgSend.Pop(FTDCHLEN);
					}
				}*/
					}

					///��ip��Χ����ͳ����Ϣ
					{
						map<string, ipLinkInfo>::iterator it = g_ipLinkInfo.begin();
						string	strOid = it->first;
						strOid = strOid.substr(0, strOid.find_last_of("."));
						strOid += ".0";

						m_pkgSend.PreparePackage(
								FTD_TID_RtnObjectAttrTopic,
								FTDC_CHAIN_CONTINUE,
								FTD_VERSION);

						CFTDRtnObjectAttrField	tfield;
						strcpy((char *)tfield.ObjectID.getValue(), strOid.data());
						strcpy(
							(char *)tfield.AttrType.getValue(),
							APPATTRORDERSIZE);
						strcpy((char *)tfield.MonDate.getValue(), theToday);
						strcpy((char *)tfield.MonTime.getValue(), theTime);
						tfield.ValueType = INT_ATTR;

						char value[21];
						sprintf(value, "%d", theOtherOrderCount);
						strcpy((char *)tfield.AttrValue.getValue(), value);
						FTDC_ADD_FIELD(&m_pkgSend, &tfield);
						for (list < CFTDCSession * >::iterator listit =
								 sessionList.begin();
						 listit != sessionList.end();
							 listit++)
						{
							(*listit)->SendRequestPackage(&m_pkgSend);
							m_pkgSend.Pop(FTDCHLEN);
						}
					}

					//������ͳ�Ƹ��¼������ǰ��
					{
						map<string, CMemberTradeOrderRecTrace>::iterator m_Iter;
						for (m_Iter = g_PartiTradeOrdPl.begin();
							 m_Iter != g_PartiTradeOrdPl.end();
							 m_Iter++)
						{
							CMemberTradeOrderRecTrace &mbTrade = m_Iter->second;

							//mbTrade.strPartiNo = m_Iter->first;
							list<CFTDRtnParticTradeOrderStatesField> lstPktRdy;
							mbTrade.HasPacksNeedSend(lstPktRdy);

							if (lstPktRdy.size() > 0)
							{
								list<CFTDRtnParticTradeOrderStatesField>::iterator
									l_Iter;
								for (l_Iter = lstPktRdy.begin();
									 l_Iter != lstPktRdy.end();
									 l_Iter++)
								{
									CFTDRtnParticTradeOrderStatesField	&
										rtnField = *l_Iter;

									m_pkgSend.PreparePackage(
											FTD_TID_RtnParticTradeOrderStatesTopic,
											FTDC_CHAIN_LAST,
											FTD_VERSION);

									FTDC_ADD_FIELD(&m_pkgSend, &rtnField);

									for (list < CFTDCSession * >::iterator
											 listit = sessionList.begin();
									 listit != sessionList.end();
										 listit++)
									{
										(*listit)->SendRequestPackage(&m_pkgSend);
										m_pkgSend.Pop(FTDCHLEN);
									}

									m_pkgSend.MakePackage();
									m_TRFlow->Append(
											m_pkgSend.Address(),
											m_pkgSend.Length());
								}
							}
						}
					}

					///��ͳ����Ϣ��ǰ��
					{
						map<int, CFTDRspQryFrontStatField>::iterator itFront;
						for (itFront = g_FrontStatMap.begin();
							 itFront != g_FrontStatMap.end();
							 itFront++)
						{
							m_pkgSend.PreparePackage(
									FTD_TID_RspQryFrontStat,
									FTDC_CHAIN_LAST,
									FTD_VERSION);

							CFTDRspQryFrontStatField sfield;
							CopyRspQryFrontStatEntity(
								&sfield,
								&((*itFront).second));
							FTDC_ADD_FIELD(&m_pkgSend, &sfield);
							m_pkgSend.MakePackage();
							m_TRFlow->Append(
									m_pkgSend.Address(),
									m_pkgSend.Length());
						}
					}

					// ����ͬ��ʱ��
					{
						if (g_tradetime!="")
						{
							m_pkgSend.PreparePackage(
								FTD_TID_RtnObjectAttrTopic,
								FTDC_CHAIN_CONTINUE,
								FTD_VERSION);

							CFTDRtnObjectAttrField	tfield;
							strcpy(
								(char *)tfield.ObjectID.getValue(),
								"TRADE.PuDian.tkernel");
							strcpy(
								(char *)tfield.AttrType.getValue(),
								APPATTRCURRENTTIME);
							strcpy((char *)tfield.MonDate.getValue(), theToday);
							strcpy((char *)tfield.MonTime.getValue(), theTime);
							tfield.ValueType = STRING_ATTR;

							strcpy((char *)tfield.AttrValue.getValue(), g_tradetime.c_str());
							FTDC_ADD_FIELD(&m_pkgSend, &tfield);
							for (list < CFTDCSession * >::iterator listit =
								sessionList.begin();
								listit != sessionList.end();
							listit++)
							{
								(*listit)->SendRequestPackage(&m_pkgSend);
								m_pkgSend.Pop(FTDCHLEN);
							}
						}
					}
					break;
				case 3:
					{
						///����Ƿ������������л�
						struct stat statbuf;
						FILE *stream;
						if ((stream = fopen("datacenter.xml", "r+")) == NULL)
						{
							fprintf(stderr, "Cannot   open   output   file.\n ");
							return;
						}

						stat("datacenter.xml", &statbuf);
						fclose(stream);
						if (g_lastChgTime != statbuf.st_ctime)
						{
							///�����˸ı�
							CXMLDoc *pSystemCfgDoc = new CXMLDoc();
							pSystemCfgDoc->read("datacenter.xml");

							CXMLNode *pSystemCfgRoot = pSystemCfgDoc->getRootNode();
							CXMLNodeList *pNodeList = pSystemCfgRoot->getNodeList();
							int iDataCenter = 0;
							for (int i = 0; i < pNodeList->size(); i++)
							{
								CXMLNode *pNodeCur = (*pNodeList)[i];
								string	mainFlag = "Main";
								if (pNodeCur->findProperty("role") == mainFlag)
								{
									iDataCenter = atoi(
											pNodeCur->findProperty("id"));
									g_mainDataCenter = pNodeCur->findProperty(
											"sysname");
								}
							}

							if (iDataCenter != g_DataCenterFlag)
							{
								///�������������л�
								g_DataCenterFlag = iDataCenter;

								///֪ͨǰ�û�����
								{
									m_pkgSend.PreparePackage(
											FTD_TID_RtnDataCenterChgTopic,
											FTDC_CHAIN_LAST,
											FTD_VERSION);

									CFTDRtnDataCenterChgField tfield;
									memset(&tfield, 0, sizeof(tfield));
									strcpy(
										(char *)(tfield.DataCenterID.getValue()),
										g_mainDataCenter.data());
									FTDC_ADD_FIELD(&m_pkgSend, &tfield);
									m_pkgSend.MakePackage();
									m_TRFlow->Append(
											m_pkgSend.Address(),
											m_pkgSend.Length());
								}

								///���
								{
									g_FrontUserIDMap.clear();
									g_FrontStatMap.clear();
									g_UserProtocolMap.clear();
									g_PudianMap.clear();
									g_ZhangjinagMap.clear();
									g_BeijingMap.clear();
								}
							}
						}
					}

					break;
				default:
					break;
			}
		}

	/* */
	private:
		///�������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;

		vector<string>	m_vecSaveInfo;
};

extern CCachedFlow	*m_TRFlow;
CIPAnalysis *pIpAnalysis = NULL;

//char *pszFlowPath;
char pFibProxyLocation[200] = "";
char pFibClientLocation[200] = "";
char pFibEventLocation[200] = "";
char pCounterLocation[200] = "";

vector<string>	list_FibProxyLocation;
vector<string>	list_fensLocation;
int g_startID = 0;
bool g_start_fens = true;

bool globalInit(void)
{
	time_t	timep;
	time(&timep);
	printf("%s sysfibclient Start Running !!!\n", ctime(&timep));

	g_pLoggerOutput = new CBufferLogger();	// SLog������
	return true;
}

// 20150303, modified by cao.ning, �����˼������淶�ı���
int main(int argc, char *argv[])
{
	showVersion(argc, argv);
	g_strTryDate = "";		// NS-1400���ϵͳ7*24����ģʽ�»�Աϯλ��ͳ���쳣
	g_startID = getStartId(argc, argv);		// Mod by henchi, 20090430
	globalInit();
	if (argc>=3 && (strcmp(argv[2], "0") == 0 || strcmp(argv[2], "off") == 0))
	{
		printf("\nFens_mode[OFF]\n");
		g_start_fens = false;
	}
	else	/// Default ON
	{
		printf("\nFens_mode[ON]\n");
		g_start_fens = true;
	}

	g_tradedate = "";
	g_tradetime = "";
	///�������ò���ʼ���Syslog:
	SysReactor	reactor;
	// 20150303, modified by cao.ning, �Ƴ�����ı���
	CConfig cIniConfig(INI_FILE_NAME);
	char *syslogFileName = cIniConfig.getConfig("SyslogPath");
	CMonitorIndex::init(
			CFilelogService::CreateInstance(argc, argv, syslogFileName),
			&cIniConfig);

	char *pszFlowPath = cIniConfig.getConfig("FlowPath");
	char *pszUserID = cIniConfig.getConfig("UserID");
	char *pszPassword = cIniConfig.getConfig("Password");
	char *pszConfigPath = cIniConfig.getConfig("ConfigPath");
	char *pszMemberDataPath = cIniConfig.getConfig("MemberSeatPath");

	// �رձ���ѹ�������Ϣ
	UseNetCompressLog = false;

	loadMemberLinkAndDataCenterCfg();

	// ��ȡϯλ��¼�澯
	LoginWarningCalculate::loadCalculateObjectFromXml(g_szMemberLinkAndDataCenterCfg);

	// ���ȼ���ļ������ԣ���������ڼ���һ���ļ�
	string strMemberData = pszMemberDataPath;
	if (strMemberData=="")
	{
		strMemberData = ".";
	}
	strMemberData += "/MemberSeat.xml";
	FILE *streamOpen;
	if ((streamOpen = fopen(strMemberData.data(), "r+")) == NULL)
	{
		REPORT_EVENT(0, "MemeberSeat Info: ", "No xml file and start create!");
		fprintf(stderr, "Cannot   open   output   file.\n ");

		CXMLNode* pRootNode = new CXMLNode();
		pRootNode->setName("MemberSeatData");
		pRootNode->setNodeType(XMLTag);

		CXMLNode* pLeafNode1 = new CXMLNode();
		pLeafNode1->setName("DataDetail");
		pLeafNode1->setNodeType(XMLTag);
		pLeafNode1->addProperty("name", "MemberSizeTotal_N");
		pLeafNode1->addProperty("Date", "");
		pLeafNode1->addProperty("Time", "");
		pLeafNode1->addProperty("Count", "");		
		pRootNode->addNode(pLeafNode1);

		CXMLNode* pLeafNode2 = new CXMLNode();
		pLeafNode2->setName("DataDetail");
		pLeafNode2->setNodeType(XMLTag);
		pLeafNode2->addProperty("name", "UserSessionSizeTotal_N");
		pLeafNode2->addProperty("Date", "");
		pLeafNode2->addProperty("Time", "");
		pLeafNode2->addProperty("Count", "");	
		pRootNode->addNode(pLeafNode2);

		CXMLNode* pLeafNode3 = new CXMLNode();
		pLeafNode3->setName("DataDetail");
		pLeafNode3->setNodeType(XMLTag);
		pLeafNode3->addProperty("name", "MemberSizeTotal_D");
		pLeafNode3->addProperty("Date", "");
		pLeafNode3->addProperty("Time", "");
		pLeafNode3->addProperty("Count", "");		
		pRootNode->addNode(pLeafNode3);

		CXMLNode* pLeafNode4 = new CXMLNode();
		pLeafNode4->setName("DataDetail");
		pLeafNode4->setNodeType(XMLTag);
		pLeafNode4->addProperty("name", "UserSessionSizeTotal_D");
		pLeafNode4->addProperty("Date", "");
		pLeafNode4->addProperty("Time", "");
		pLeafNode4->addProperty("Count", "");		
		pRootNode->addNode(pLeafNode4);

		CXMLDoc* pNewDoc = new CXMLDoc();
		pNewDoc->setRootNode(pRootNode);
		pNewDoc->write((char*)(strMemberData.data()));
		delete pNewDoc;
	}

	///��ʼ����Աϯλ��ʷ���ֵ����
	try
	{
		 REPORT_EVENT(0, "MemeberSeat Info: ", "start read data in main!");
		 CXMLDoc pMemeberSeatDoc;
		 pMemeberSeatDoc.read((char*)(strMemberData.data()));

		 CXMLNode* pDataRoot = pMemeberSeatDoc.getRootNode();
		 CXMLNodeList *pNodeList = pDataRoot->getNodeList();
		 for (int i = 0; i < pNodeList->size(); i++)
		 {
			 CXMLNode *pNodeCur = (*pNodeList)[i];
			 string name = pNodeCur->findProperty("name");
			 if (name == "MemberSizeTotal_N")
			 {
				g_HistoryMemberSizeTotal_N.str_date = pNodeCur->findProperty("Date");
				g_HistoryMemberSizeTotal_N.str_time = pNodeCur->findProperty("Time");
				g_HistoryMemberSizeTotal_N.i_count  = atoi(pNodeCur->findProperty("Count"));
				REPORT_EVENT(0, "MemeberSeat Info: ", "MemberSizeTotal_N:%d",g_HistoryMemberSizeTotal_N.i_count);
			 }
			 else if (name == "UserSessionSizeTotal_N")
			 {
				g_HistoryUserSessionSizeTotal_N.str_date = pNodeCur->findProperty("Date");
				g_HistoryUserSessionSizeTotal_N.str_time = pNodeCur->findProperty("Time");
				g_HistoryUserSessionSizeTotal_N.i_count  = atoi(pNodeCur->findProperty("Count"));
				REPORT_EVENT(0, "MemeberSeat Info: ", "UserSessionSizeTotal_N:%d",g_HistoryUserSessionSizeTotal_N.i_count);
			 }
			 else if (name == "MemberSizeTotal_D")
			 {
				 g_HistoryMemberSizeTotal_D.str_date = pNodeCur->findProperty("Date");
				 g_HistoryMemberSizeTotal_D.str_time = pNodeCur->findProperty("Time");
				 g_HistoryMemberSizeTotal_D.i_count  = atoi(pNodeCur->findProperty("Count"));
				 REPORT_EVENT(0, "MemeberSeat Info: ", "MemberSizeTotal_D:%d",g_HistoryMemberSizeTotal_D.i_count);
			 }
			 else if (name == "UserSessionSizeTotal_D")
			 {
				 g_HistoryUserSessionSizeTotal_D.str_date = pNodeCur->findProperty("Date");
				 g_HistoryUserSessionSizeTotal_D.str_time = pNodeCur->findProperty("Time");
				 g_HistoryUserSessionSizeTotal_D.i_count  = atoi(pNodeCur->findProperty("Count"));
				 REPORT_EVENT(0, "MemeberSeat Info: ", "UserSessionSizeTotal_D:%d",g_HistoryUserSessionSizeTotal_D.i_count);
			 }
		 }
	}
	catch (CRuntimeError * e)
	{
		printf(
			"Error While load DeployConfig info:\nLINE[%d]:%s\n",
			e->GetLineNo(),
			e->GetMsg());
		REPORT_EVENT(0, "MemeberSeat Info: ", "read data error in main!");
	}

	// 20150303, modified by cao.ning, �ñ���û��ʹ��
	// CXMLConfig	*pXMLCfg = new CXMLConfig(pszConfigPath);
	pIpAnalysis = new CIPAnalysis(pszConfigPath);

	m_TRFlow = new CCachedFileFlow(
			"resultflow",
			pszFlowPath,
			false,
			1000000,
			1000000);

	try
	{
		CDeployConfig DeployConfig;
		DeployConfig.Parse(pszConfigPath);

		char strID[16] = "";
		sprintf(strID, "%d", g_startID);

		CDeployConfig::SysFibClientCfgInfo	cfgInfo = DeployConfig.
			GetSysFibClientCfgInfo(strID);

		string	frontListener = cfgInfo.ServerAddr("sysfront");
		string	eventcounter = cfgInfo.ServerAddr("syseventcounter");
		vector<CDeployConfig::ServerAddrInfo> fibproxys = cfgInfo.
			ServerAddrArray("fibproxy");

		for (vector < CDeployConfig::ServerAddrInfo >::iterator
			it = fibproxys.begin();
			it != fibproxys.end();
			it++)
		{
			list_FibProxyLocation.push_back(it->m_addr);
		}
		
		vector<CDeployConfig::ServerAddrInfo> fens = cfgInfo.ServerAddrArray("fens");
		for (vector<CDeployConfig::ServerAddrInfo>::iterator it=fens.begin(); it!=fens.end(); ++it)
		{
			list_fensLocation.push_back(it->m_addr);
		}

		if (frontListener.empty()
		||	eventcounter.empty()
		||	list_FibProxyLocation.size() == 0)
		{
			printf(
				"Config info is incomplete! Check front address, event counter address and fibproxy address.\n");
			exit(0);
		}

		strcpy(pFibClientLocation, frontListener.c_str());
		strcpy(pCounterLocation, eventcounter.c_str());
	}
	catch(CRuntimeError * e)
	{
		printf(
			"Error While load DeployConfig info:\nLINE[%d]:%s\n",
			e->GetLineNo(),
			e->GetMsg());
		exit(0);
	}
	
	if (!g_start_fens)
	{
		CFibClient	client(&reactor, pszFlowPath, pszUserID, pszPassword);
		int nSubjectPos = 0;
		for (;;)
		{
			char *pszSubject = cIniConfig.getConfig("Subject", &nSubjectPos);
			if (strcmp(pszSubject, "") == 0)
			{
				break;
			}

			client.CreateSubscriber(atoi(pszSubject));
		}

		int nFrontAddressPos = 0;

		vector<string>::iterator itFibProxyLocation;
		for (itFibProxyLocation = list_FibProxyLocation.begin();
			itFibProxyLocation != list_FibProxyLocation.end();
			itFibProxyLocation++)
		{
			client.RegisterConnecter(itFibProxyLocation->c_str());
		}

		//	client.RegisterConnecter(pFibProxyLocation);
		reactor.Create();
		client.Start();

		CFibClientServer myServer(&reactor);
		CEventConnect eventConnect(&reactor);

		client.SetEventConentSever(&eventConnect);
		client.SetFrontServer(&myServer);

		CMyTimmer timer(&reactor);
		myServer.RegisterListener(pFibClientLocation);
		eventConnect.RegisterConnecter(pCounterLocation);
		myServer.Start();
		eventConnect.Start();
		reactor.Join();
	}
	else
	{
		CFibClient2 client2(&reactor, pszFlowPath, pszUserID, pszPassword);
		int nSubjectPos = 0;
		for (;;)
		{
			char *pszSubject = cIniConfig.getConfig("Subject", &nSubjectPos);
			if (strcmp(pszSubject, "") == 0)
			{
				break;
			}
			client2.CreateSubscriber(atoi(pszSubject));
		}

		vector<string>::iterator iterFensLocation;
		for (iterFensLocation=list_fensLocation.begin();
			iterFensLocation!=list_fensLocation.end();
			++iterFensLocation)
		{
			client2.RegisterNameServer(const_cast<char*>(iterFensLocation->c_str()));
			printf("Register NameServer: %s\n", const_cast<char*>(iterFensLocation->c_str()));
		}
		reactor.Create();
		client2.Start();

		CFibClientServer myServer(&reactor);
		CEventConnect eventConnect(&reactor);

		client2.SetEventConentSever(&eventConnect);
		client2.SetFrontServer(&myServer);

		CMyTimmer timer(&reactor);
		myServer.RegisterListener(pFibClientLocation);
		eventConnect.RegisterConnecter(pCounterLocation);
		myServer.Start();
		eventConnect.Start();
		reactor.Join();
	}
	return 0;
}

void loadMemberLinkAndDataCenterCfg()
{
	///����������Ķ�Ӧ��ǰ�ñ�ż����������ı��
	struct stat statbuf;
	if (stat(g_szMemberLinkAndDataCenterCfg, &statbuf) != 0)
	{
		fprintf(stderr, "Can not open file [%s] with errno[%d]%s.\n",
			g_szMemberLinkAndDataCenterCfg,
			errno, strerror(errno));
		exit(-1);
	}
	g_lastChgTime = statbuf.st_ctime;

	try
	{
		CXMLDoc CfgXmlDoc;
		CfgXmlDoc.read(const_cast<char*>(g_szMemberLinkAndDataCenterCfg));
		CXMLNode *pSystemCfgRoot = CfgXmlDoc.getRootNode();
				
		// start load DataCenters Configuration info
		{
			// DataCenters Tag
			CXMLNode* pDataCentersTag = pSystemCfgRoot->findNode(XMLTag, "DataCenters");
			if (pDataCentersTag == NULL) throw "Can not find DataCenters Tag";

			CXMLNodeList *pNodeList = pDataCentersTag->getNodeList();
			if (pNodeList == NULL || pNodeList->empty()) throw "Node list of DataCenters Tag is Null";

			for (CXMLNodeList::iterator itNode = pNodeList->begin();
				itNode != pNodeList->end();
				++itNode)
			{
				CXMLNode* pDataCenterNode = *itNode;

				// get all properties of this node
				char* szDataCenterName = pDataCenterNode->findProperty("name");
				if (szDataCenterName == NULL) throw "Name of DataCenter is Null";
				string strCurrentDataCenter = szDataCenterName;

				char* szRole = pDataCenterNode->findProperty("role");
				if (szRole == NULL) throw "Role of DataCenter is Null";

				char* szId = pDataCenterNode->findProperty("id");
				if (szId == NULL) throw "ID of DataCenter is Null";

				char* szSysname = pDataCenterNode->findProperty("sysname");
				if (szSysname == NULL) throw "Sysname of DataCenter is Null";
				string strDataCenterSysName = szSysname;
				
				// check data center name
				if (strCurrentDataCenter == "PuDian")
				{
					datacenterPudian = szSysname;
				}
				else if (strCurrentDataCenter == "ZhangJ")
				{
					datacenterZhangJ = szSysname;
				}
				else if (strCurrentDataCenter == "BeiJing")
				{
					datacenterBeijing = szSysname;
				}
				else
				{
					fprintf(stderr, "Data Center Name [%s] Error in file [%s]. It should be one of (PuDian, ZhangJ, BeiJing)\n", 
						szDataCenterName, g_szMemberLinkAndDataCenterCfg);
					exit(-1);
				}

				// check role
				if (strcmp(szRole, "Main") == 0)
				{
					g_DataCenterFlag = atoi(szId);
					g_mainDataCenter = szSysname;
				}

				string strDCID = strDataCenterSysName + "." + DATACENTERAPP;
				list<int> DCFrontList;
				// ���ص�ǰ���������µ�App�б�
				CXMLNodeList* pAppNodeList = pDataCenterNode->getNodeList();
				if (pAppNodeList != NULL)
				{
					for (CXMLNodeList::iterator itAppNode = pAppNodeList->begin();
						itAppNode != pAppNodeList->end();
						++itAppNode)
					{
						char* szAppName = (*itAppNode)->findProperty("name");
						if (szAppName != NULL && strcmp(szAppName, "front") == 0)
						{
							char* szAppArgs = (*itAppNode)->findProperty("args");
							if (szAppArgs != NULL)
							{
								DCFrontList.push_back(atoi(szAppArgs));
							}
						}
					}
				}
				g_DataCenterMap[strDCID] = DCFrontList;
			}
		} // end load DataCenters Configuration info
		
		
		// start ��ʼ����Ա��ϯ��¼IP����
		{
			// MemberLinks Tag
			CXMLNode* pMemberLinksTag = pSystemCfgRoot->findNode(XMLTag, "MemberLinks");
			if (pMemberLinksTag == NULL) throw "Can not find MemberLinks Tag";

			CXMLNodeList* pObjectList = pMemberLinksTag->getNodeList();
			if (pObjectList == NULL || pObjectList->empty()) throw "MemberLinks Object is empty";
			for (CXMLNodeList::iterator itObject = pObjectList->begin();
				itObject != pObjectList->end();
				++itObject)
			{
				CXMLNode* pObjectNode = *itObject;
				char* szOid = pObjectNode->findProperty("oid");
				char* szName = pObjectNode->findProperty("name");
				if (szOid != NULL && szName != NULL)
				{
					ipLinkInfo linkInfo;
					linkInfo.orderCount = 0;
					linkInfo.name = szName;
					
					CXMLNodeList* pItemList = pObjectNode->getNodeList();
					if (pItemList == NULL || pItemList->empty())
					{
						fprintf(stderr, "Item list of MemberLinks %s is Null.\n", szName);
						continue;
					}
					for (CXMLNodeList::iterator itItem = pItemList->begin();
						itItem != pItemList->end();
						++itItem)
					{
						char* szLeft = (*itItem)->findProperty("left");
						char* szRight = (*itItem)->findProperty("right");
						if (szLeft != NULL && szRight != NULL)
						{
							linkInfo.ipScope.push_back(make_pair(szLeft, szRight));
						}
					}
					g_ipLinkInfo[szOid] = linkInfo;
				}
			}
		} // end ��ʼ����Ա��ϯ��¼IP����

		
		// start ��ʼ���йܻ�Ա��ϯ��¼IP����
		{
			// TuoGuanMemberLinks Tag
			CXMLNode* pManagedLinksTag = pSystemCfgRoot->findNode(XMLTag, "TuoGuanMemberLinks");
			if (pManagedLinksTag == NULL) throw "Can not find TuoGuanMemberLinks Tag";

			CXMLNodeList* pObjectList = pManagedLinksTag->getNodeList();
			if (pObjectList == NULL || pObjectList->empty()) throw "MemberLinks Object is empty";
			for (CXMLNodeList::iterator itObject = pObjectList->begin();
				itObject != pObjectList->end();
				++itObject)
			{
				CXMLNode* pObjectNode = *itObject;
				char* szOid = pObjectNode->findProperty("oid");
				char* szName = pObjectNode->findProperty("name");
				char* szType = pObjectNode->findProperty("type");
				if (szOid != NULL && szName != NULL && szType != NULL)
				{
					ipLinkInfo linkInfo;
					linkInfo.orderCount = 0;
					linkInfo.name = szName;
					linkInfo.type = szType;

					CXMLNodeList* pItemList = pObjectNode->getNodeList();
					if (pItemList == NULL || pItemList->empty())
					{
						fprintf(stderr, "Item list of MemberLinks %s is Null.\n", szName);
						continue;
					}
					for (CXMLNodeList::iterator itItem = pItemList->begin();
						itItem != pItemList->end();
						++itItem)
					{
						char* szLeft = (*itItem)->findProperty("left");
						char* szRight = (*itItem)->findProperty("right");
						if (szLeft != NULL && szRight != NULL)
						{
							linkInfo.ipScope.push_back(make_pair(szLeft, szRight));
						}
					}
					string strOid = szOid; strOid += "_" + linkInfo.type;
					g_ipLinkInfoTuoGuan[strOid] = linkInfo;
				}
			}
		} // end ��ʼ���йܻ�Ա��ϯ��¼IP����
	}
	catch (CRuntimeError * e)
	{
		printf("Error when load %s info:\nLINE[%d]:%s\n",
			g_szMemberLinkAndDataCenterCfg,
			e->GetLineNo(), 	e->GetMsg());
		exit(-1);
	}
	catch (const char* e)
	{
		printf("%s\n", e);
		exit(-1);
	}

	
}