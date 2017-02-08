/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CStatusSubscriber2.cpp
///@brief	实现了订阅交易流水处理消息的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
#include "CStatusSubscriber.h"
#include <iostream>
using namespace std;

extern CDataCenterManage *g_pDataCenterManage;
extern CListSessionArray *g_pListSessionArray;
extern list<CFTDCSession *> g_mListAllSession;
extern map<int, int> g_SubcriberMap;
extern CTypeObjectIDType g_DataCenter;
extern int	g_FrontRange;
extern CTimeType theTime;
extern CDateType theDate;
extern string g_peakBaseOid;
extern map<CNetObjectIDType, CAttrValueType> g_partyLinkStatus;

int getiTime1(CTimeType tTime)
{
	string	sTime = tTime.getValue();
	return ((sTime[0] - '0') * 10 + (sTime[1] - '0')) * 3600 +
		((sTime[3] - '0') * 10 + (sTime[4] - '0')) * 60 +
			((sTime[6] - '0') * 10 + (sTime[7] - '0'));
}

/*
CTimeType getsTime1(int iTime)
{
	int iHour =iTime /3600;
	int iMinute =(iTime %3600) /60;
	int iSecond =(iTime %3600) %60;
	char theTime[10] ="";
	sprintf(theTime,"%02d:%02d:%02d", iHour, iMinute, iSecond);
	string stmp =theTime;
	CTimeType ttmp;
	strcpy((char *)(ttmp.getValue()) ,stmp.data());
	return ttmp;
}

volatile int timehere =0;
*/
int thePeakBase = 0;

void CStatusSubscriber::OnRtnObjectAttrTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnObjectAttrField	fieldInfo;
	list<int> iList;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnObjectAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);

		string	str = fieldInfo.ObjectID.getValue();
		str += ".";
		str += fieldInfo.AttrType.getValue();

		CWriteableSysMdbObjectAttr	mdbfield;
		mdbfield.SubcriberID = g_StringIdMap.getStringId(str.data());
		mdbfield.ObjectID = g_StringIdMap.getStringId(
				fieldInfo.ObjectID.getValue());
		mdbfield.AttrType = g_StringIdMap.getStringId(
				fieldInfo.AttrType.getValue());
		mdbfield.MonDate = fieldInfo.MonDate;
		mdbfield.MonTime = fieldInfo.MonTime;
		mdbfield.ValueType = fieldInfo.ValueType;
		mdbfield.AttrValue = fieldInfo.AttrValue;

		if (find(
				iList.begin(),
			iList.end(),
			mdbfield.SubcriberID) == iList.end())
		{
			CSysMdbObjectAttr *oldfield = pMemoryDB->m_SysMdbObjectAttrFactory->
				startFindByDataDelete(mdbfield.SubcriberID, theDate, theTime);
			while (oldfield)
			//if(oldfield)
			{
				CSysMdbObjectAttr *tmpfield = pMemoryDB->
					m_SysMdbObjectAttrFactory->findNextByDataDelete();
				pMemoryDB->m_SysMdbObjectAttrFactory->remove(oldfield);
				oldfield = tmpfield;
			}

			pMemoryDB->m_SysMdbObjectAttrFactory->endFindByDataDelete();
			iList.push_back(mdbfield.SubcriberID);
		}

		map<int, int>::iterator it = g_SubcriberMap.find(
				(int)(mdbfield.SubcriberID));
		if (it == g_SubcriberMap.end())
		{
			g_SubcriberMap[(int)(mdbfield.SubcriberID)] = 1;
		}

		if (strcmp(fieldInfo.AttrType.getValue(), APPATTRACTIVE) != 0)
		{
			pMemoryDB->m_SysMdbObjectAttrFactory->add(&mdbfield, NULL);
		}

		///找到峰值计算的基线：
		if (!thePeakBase)
		{
			if (str.find(g_peakBaseOid) != string::npos)
			{
				thePeakBase = getiTime1(fieldInfo.MonTime);
			}
		}

#ifdef PRINT_DEBUG
		printf(
			"++++Attr:%s,%s,%s\n",
			(const char *)fieldInfo.ObjectID,
			(const char *)fieldInfo.AttrType,
			(const char *)fieldInfo.AttrValue);
#endif
		if (!m_reload)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnObjectAttrTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);
			g_pListSessionArray->SendPackage(&m_pkgSend, str.data());

			///过滤会员链路状态信息
			if (str.find("interfaceStatus") != string::npos)
			{
				if (fieldInfo.AttrValue != "0")
				{
					g_partyLinkStatus[fieldInfo.ObjectID] = fieldInfo.AttrValue;
				}
			}

			///产生Active指标
			if (str.find("cpmCPUTotalMonIntervalValue") != string::npos
			||	str.find("cpmCPUTotal5minRev") != string::npos
			||	str.find("nsResCpuAvg") != string::npos)
			{
				int index = str.find("cpmCPUTotalMonIntervalValue");
				if (index == string::npos)
				{
					index = str.find("cpmCPUTotal5minRev");
					if (index == string::npos)
					{
						index = str.find("nsResCpuAvg");
					}
				}

				CFTDRtnObjectAttrField	tfield;
				string	oid = str;
				oid.replace(index, str.length() - index, APPATTRISACTIVE);
				tfield.ObjectID = fieldInfo.ObjectID;
				tfield.AttrType = APPATTRISACTIVE;
				tfield.AttrValue = "1";
				tfield.MonDate = fieldInfo.MonDate;
				tfield.MonTime = fieldInfo.MonTime;
				tfield.ValueType = INT_ATTR;

				int subId = g_StringIdMap.getStringId(oid.data());
				map<int, int>::iterator it = g_SubcriberMap.find(subId);
				if (it == g_SubcriberMap.end())
				{
					g_SubcriberMap[subId] = 1;
				}

				CWriteableSysMdbObjectAttr	mdbfield;
				mdbfield.SubcriberID = subId;
				mdbfield.ObjectID = g_StringIdMap.getStringId(
						tfield.ObjectID.getValue());
				mdbfield.AttrType = g_StringIdMap.getStringId(
						tfield.AttrType.getValue());
				mdbfield.MonDate = tfield.MonDate;
				mdbfield.MonTime = tfield.MonTime;
				mdbfield.ValueType = tfield.ValueType;
				mdbfield.AttrValue = tfield.AttrValue;
				pMemoryDB->m_SysMdbObjectAttrFactory->add(&mdbfield, NULL);

				m_pkgSend.PreparePackage(
						FTD_TID_RtnObjectAttrTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				FTDC_ADD_FIELD(&m_pkgSend, &tfield);
				g_pListSessionArray->SendPackage(&m_pkgSend, oid.data());
			}

			///算mem占有率
			if (str.find("memoryPoolUsed") != string::npos)
			{
				string	pairStr = str;
				int index = str.find("memoryPoolUsed");
				pairStr.replace(index, str.length() - index, "memoryPoolFree");

				int gid_Used = g_StringIdMap.getStringId(str.data());
				int gid_Free = g_StringIdMap.getStringId(pairStr.data());
				int iUsed = 0;
				int iFree = 0;

				CSysMdbObjectAttr *pUsed = pMemoryDB->
					m_SysMdbObjectAttrFactory->startFindByDsc(gid_Used);
				if (pUsed)
				{
					iUsed = atoi(pUsed->AttrValue.getValue());
				}

				pMemoryDB->m_SysMdbObjectAttrFactory->endFindByDsc();

				CSysMdbObjectAttr *pFree = pMemoryDB->
					m_SysMdbObjectAttrFactory->startFindByDsc(gid_Free);
				if (pFree)
				{
					iFree = atoi(pFree->AttrValue.getValue());
				}

				pMemoryDB->m_SysMdbObjectAttrFactory->endFindByDsc();

				if (iUsed != 0 && iFree != 0)
				{
					iUsed /= 1024;	///临时处理
					iFree /= 1024;

					double	rate = iUsed * 100.00 / (iUsed + iFree);
					char value[21];
					sprintf(value, "%.2f", rate);

					CFTDRtnObjectAttrField	tfield;
					string	oid = str;
					oid.replace(
							index,
							str.length() - index,
							APPATTRMEMORYUSAGE);

					//strcpy((char *)tfield.ObjectID.getValue() ,oid.data());
					tfield.ObjectID = fieldInfo.ObjectID;
					strcpy(
						(char *)tfield.AttrType.getValue(),
						APPATTRMEMORYUSAGE);
					tfield.MonDate = fieldInfo.MonDate;
					tfield.MonTime = fieldInfo.MonTime;
					tfield.ValueType = PERCENT_ATTR;
					strcpy((char *)tfield.AttrValue.getValue(), value);

					int subId = g_StringIdMap.getStringId(oid.data());
					map<int, int>::iterator it = g_SubcriberMap.find(subId);
					if (it == g_SubcriberMap.end())
					{
						g_SubcriberMap[subId] = 1;
					}

					CWriteableSysMdbObjectAttr	mdbfield;
					mdbfield.SubcriberID = subId;
					mdbfield.ObjectID = g_StringIdMap.getStringId(
							tfield.ObjectID.getValue());
					mdbfield.AttrType = g_StringIdMap.getStringId(
							tfield.AttrType.getValue());
					mdbfield.MonDate = tfield.MonDate;
					mdbfield.MonTime = tfield.MonTime;
					mdbfield.ValueType = tfield.ValueType;
					mdbfield.AttrValue = tfield.AttrValue;
					pMemoryDB->m_SysMdbObjectAttrFactory->add(&mdbfield, NULL);

					m_pkgSend.PreparePackage(
							FTD_TID_RtnObjectAttrTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
					FTDC_ADD_FIELD(&m_pkgSend, &tfield);
					g_pListSessionArray->SendPackage(&m_pkgSend, oid.data());
				}
			}
		}

		itor.Next();
	}
}

void CStatusSubscriber::OnRtnWarningEventTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnWarningEventField fieldInfo;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnWarningEventField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);
#ifdef PRINT_DEBUG
		printf(
			"++++CPU:%s,%s,%s,%s,%s,%s,%d,%d\n",
			(const char *)fieldInfo.ObjectID,
			(const char *)fieldInfo.EventName,
			(const char *)fieldInfo.EventDes,
			(const char *)fieldInfo.WarningLevel,
			(const char *)fieldInfo.MonTime,
			(const char *)fieldInfo.ProcessFlag,
			(const int)fieldInfo.EvendID,
			(const int)fieldInfo.EventNum);
#endif

		CSysWarningEvent *pEvent = pMemoryDB->m_SysWarningEventFactory->
			findByEvendID(fieldInfo.EvendID);
		CWriteableSysWarningEvent mdbfield;
		CopySysWarningEventEntity(&mdbfield, &fieldInfo);
		if (pEvent)
		{
			if (pEvent->ProcessFlag == "N")
			{
				pMemoryDB->m_SysWarningEventFactory->remove(pEvent);
				pMemoryDB->m_SysWarningEventFactory->add(&mdbfield);
			}
			else if (pEvent->ProcessFlag == "=")
			{
				if (fieldInfo.ProcessFlag == "N")
				{
					itor.Next();
					continue;
				}
				else
				{
					pMemoryDB->m_SysWarningEventFactory->remove(pEvent);
					pMemoryDB->m_SysWarningEventFactory->add(&mdbfield);
				}
			}
			else if (pEvent->ProcessFlag == "A" || pEvent->ProcessFlag == "Y")
			{
				if(fieldInfo.ProcessFlag != "=")
				{
					itor.Next();
					continue;
				}
				else
				{
					//已处理事件可以转化成处理中
					pMemoryDB->m_SysWarningEventFactory->remove(pEvent);
					pMemoryDB->m_SysWarningEventFactory->add(&mdbfield);
				}
			}
		}
		else
		{
			pMemoryDB->m_SysWarningEventFactory->add(&mdbfield);
		}

		///清理:
		/*CSysWarningEvent *oldField =pMemoryDB->m_SysWarningEventFactory->startFindByTime(theDate ,theTime);
		while(oldField)
		{
			CSysWarningEvent *tmpField =pMemoryDB->m_SysWarningEventFactory->findNextByTime();
			if(oldField->ObjectID ==fieldInfo.ObjectID)
			{
				if(oldField->ProcessFlag =="N")
				{
					bool rmFlag =false;
					CSysWarningEvent *yField =pMemoryDB->m_SysWarningEventFactory->startFindByEvendIDs(oldField->EvendID);
					while(yField)
					{
						if(yField->ProcessFlag =="Y")
						{
							rmFlag =true;
							break;
						}
						yField =pMemoryDB->m_SysWarningEventFactory->findNextByEvendIDs();
					}
					pMemoryDB->m_SysWarningEventFactory->endFindByEvendIDs();

					if(rmFlag)
					{
						pMemoryDB->m_SysWarningEventFactory->remove(oldField);
						pMemoryDB->m_SysWarningEventFactory->remove(yField);
					}
				}
			}
			oldField =tmpField;
		}
		pMemoryDB->m_SysWarningEventFactory->endFindByTime();*/
		/*if(fieldInfo.WarningLevel !="notify" && fieldInfo.WarningLevel !="warning" && fieldInfo.WarningLevel !="error" && fieldInfo.WarningLevel !="fatal")
		{
			itor.Next();
			continue;
		}*/
		if (!m_reload)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnWarningEventTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);

			list<CFTDCSession *>::iterator	it;
			for (it = g_mListAllSession.begin();
				 it != g_mListAllSession.end();
				 it++)
			{
				(*it)->SendRequestPackage(&m_pkgSend);
				m_pkgSend.Pop(FTDCHLEN);
			}
		}

		itor.Next();
	}
}

void CStatusSubscriber::OnRtnUserInfoTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnUserInfoField fieldUserInfo;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnUserInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldUserInfo);

		CWriteableSysUserInfo mdbfield;
		CopySysUserInfoEntity(&mdbfield, &fieldUserInfo);
		{
			///先找到最后一条的时间
			CSysUserInfo *oldfield = pMemoryDB->m_SysUserInfoFactory->
				startFindByDsc(mdbfield.ObjectID);

			///如果不相等，即来的是新时间的数据，则删除原来的
			if (oldfield)
			{
				if (!
						(
						mdbfield.MonDate == oldfield->MonDate
				&&	mdbfield.MonTime == oldfield->MonTime
				))
				{
					while (oldfield)
					//if(oldfield)
					{
						CSysUserInfo *tmpfield = pMemoryDB->
							m_SysUserInfoFactory->findNextByDsc();
						pMemoryDB->m_SysUserInfoFactory->remove(oldfield);
						oldfield = tmpfield;
					}
				}
			}

			pMemoryDB->m_SysUserInfoFactory->endFindByDsc();
		}

		pMemoryDB->m_SysUserInfoFactory->add(&mdbfield, NULL);
		if (!m_reload)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnUserInfoTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &fieldUserInfo);
			g_pListSessionArray->SendPackage(
					&m_pkgSend,
					fieldUserInfo.ObjectID.getValue());
		}

		itor.Next();
	}
}

void CStatusSubscriber::OnRtnOnlineUserInfoTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnOnlineUserInfoField	fieldOnlineUserInfo;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnOnlineUserInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldOnlineUserInfo);

		CWriteableSysOnlineUserInfo mdbfield;
		CopySysOnlineUserInfoEntity(&mdbfield, &fieldOnlineUserInfo);
		{
			///先找到最后一条的时间
			CSysOnlineUserInfo	*oldfield = pMemoryDB->
				m_SysOnlineUserInfoFactory->startFindByDsc(mdbfield.ObjectID);

			///如果不相等，即来的是新时间的数据，则删除原来的
			if (oldfield)
			{
				if (!
						(
						mdbfield.MonDate == oldfield->MonDate
				&&	mdbfield.MonTime == oldfield->MonTime
				))
				{
					while (oldfield)
					//if(oldfield)
					{
						CSysOnlineUserInfo	*tmpfield = pMemoryDB->
							m_SysOnlineUserInfoFactory->findNextByDsc();
						pMemoryDB->m_SysOnlineUserInfoFactory->remove(oldfield);
						oldfield = tmpfield;
					}
				}
			}

			pMemoryDB->m_SysOnlineUserInfoFactory->endFindByDsc();
		}

		pMemoryDB->m_SysOnlineUserInfoFactory->add(&mdbfield, NULL);
		if (!m_reload)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnOnlineUserInfoTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &fieldOnlineUserInfo);
			g_pListSessionArray->SendPackage(
					&m_pkgSend,
					fieldOnlineUserInfo.ObjectID.getValue());
		}

		itor.Next();
	}
}

// g_pDataCenterManage
void UpdateSysConfig(CFTDRtnUpdateSysConfigField &fieldInfo)
{
	if (strcmp(
			fieldInfo.UpdateType.getValue(),
		UPDATESYSCONFIG_HOSTIDAPPID) == 0)		//业务ID与主机ID影射关系
	{
		g_pDataCenterManage->addAppIdHost(
				(char *)fieldInfo.NewValue.getValue(),
				(char *)fieldInfo.OldValue.getValue());

		// Added by Henchi 080918
		// OldValue:主机ID(如:ZhangJ.os.B-AE03)         NewValue:指标ID(如:ZhangJ.app.front.9)
		char *p = NULL;

		// Added by Henchi 080918
		char *q;
		if ((p = strstr((char *)fieldInfo.NewValue.getValue(), DATACENTERAPP)))
		{
			char szName[32];

			char szType[32];

			// 保存应用ID与类型关系map.Key:PuDian.app.tkernel.1     Val:app.tkernel
			strcpy(szType, p);					// app.tkernel.1
			if ((q = strchr(szType, '.')) && (q = strchr(q + 1, '.')))
			{
				*q = 0x00;
			}

			g_pDataCenterManage->addAppIdType(
					(char *)fieldInfo.NewValue.getValue(),
					szType);
#ifdef PRINT_DEBUG
			printf(
				"AddAppIdType: %s %s\n",
				(char *)fieldInfo.NewValue.getValue(),
				szType);
#endif

			// 保存应用ID对应的名字关系map. Key:PuDian.app.tkernel.1,PuDian.os.AC-01        Val:tkernel1,AC-01
			p += strlen(DATACENTERAPP) + 1;
			strcpy(szName, p);					// tkernel.1
			if ((q = strchr(szName, '.')))
			{
				*q = 0x00;
				strcat(szName, q + 1);
			}

			g_pDataCenterManage->addAppIdName(
					(char *)fieldInfo.NewValue.getValue(),
					szName);
#ifdef PRINT_DEBUG
			printf(
				"AddAppIdName: %s %s\n",
				(char *)fieldInfo.NewValue.getValue(),
				szName);
#endif
		}
	}
	else if (strcmp(
				 fieldInfo.UpdateType.getValue(),
			 UPDATESYSCONFIG_HOSTNAME) == 0)	//主机名变更
	{
		///主机名变更处理：1.更新SystemConfig.xml文件，2.替换前置保存的所有监控对象
		g_pDataCenterManage->UpDateAppIdName(
				(char *)fieldInfo.NewValue.getValue(),
				(char *)fieldInfo.OldValue.getValue());
		g_pDataCenterManage->UpdateAppAttr(
				(char *)fieldInfo.NewValue.getValue(),
				(char *)fieldInfo.OldValue.getValue());
	}
}

void CStatusSubscriber::OnRtnUpdateSysConfigTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnUpdateSysConfigField fieldInfo;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnUpdateSysConfigField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);
		UpdateSysConfig(fieldInfo);

		m_pkgSend.PreparePackage(
				FTD_TID_RtnUpdateSysConfigTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);

		list<CFTDCSession *>::iterator	it;
		for (it = g_mListAllSession.begin();
			 it != g_mListAllSession.end();
			 it++)
		{
			(*it)->SendRequestPackage(&m_pkgSend);
			m_pkgSend.Pop(FTDCHLEN);
		}

		itor.Next();
	}
}

void CStatusSubscriber::OnRtnDbQueryTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnDBQueryField fieldInfo;
	list<int> iList;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnDBQueryField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);

		string	str = fieldInfo.ObjectID.getValue();
		str += ".";
		str += fieldInfo.AttrType.getValue();

		CWriteableSysMdbDBQuery mdbfield;
		mdbfield.SubcriberID = g_StringIdMap.getStringId(str.data());
		mdbfield.ObjectID = g_StringIdMap.getStringId(
				fieldInfo.ObjectID.getValue());
		mdbfield.AttrType = g_StringIdMap.getStringId(
				fieldInfo.AttrType.getValue());
		mdbfield.MonDate = fieldInfo.MonDate;
		mdbfield.MonTime = fieldInfo.MonTime;
		mdbfield.DBQueryResult = fieldInfo.DBQueryResult;

		if (find(
				iList.begin(),
			iList.end(),
			mdbfield.SubcriberID) == iList.end())
		{
			CSysMdbDBQuery	*oldfield = pMemoryDB->m_SysMdbDBQueryFactory->
				startFindByDataDelete(mdbfield.SubcriberID, theDate, theTime);
			while (oldfield)
			//if(oldfield)
			{
				CSysMdbDBQuery	*tmpfield = pMemoryDB->m_SysMdbDBQueryFactory->
					findNextByDataDelete();
				pMemoryDB->m_SysMdbDBQueryFactory->remove(oldfield);
				oldfield = tmpfield;
			}

			pMemoryDB->m_SysMdbDBQueryFactory->endFindByDataDelete();
			iList.push_back(mdbfield.SubcriberID);
		}

		map<int, int>::iterator it = g_SubcriberMap.find(
				(int)(mdbfield.SubcriberID));
		if (it == g_SubcriberMap.end())
		{
			g_SubcriberMap[(int)(mdbfield.SubcriberID)] = 10;
		}

		pMemoryDB->m_SysMdbDBQueryFactory->add(&mdbfield, NULL);

		if (!m_reload)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnDBQueryTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);
			g_pListSessionArray->SendPackage(&m_pkgSend, str.data());
		}

		itor.Next();
	}
}

void CStatusSubscriber::OnRtnNetPartyLinkStatusInfoTopic(
	CFTDCPackage *pFTDCPackage)
{
	/*
	CFTDRtnNetPartyLinkStatusInfoField	  fieldInfo;
	list<int> iList;
	
	CNamedFieldIterator itor= pFTDCPackage->GetNamedFieldIterator(&CFTDRtnNetPartyLinkStatusInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);

		CWriteableSysNetPartyLinkStatusInfo mdbfield;
		CopySysNetPartyLinkStatusInfoEntity(&mdbfield,&fieldInfo);

		mdbfield.SubcriberID= g_StringIdMap.getStringId(fieldInfo.Interface.getValue());

		if(find(iList.begin() ,iList.end() ,mdbfield.SubcriberID) ==iList.end())
		{
			CSysNetPartyLinkStatusInfo *oldfield =pMemoryDB->m_SysNetPartyLinkStatusInfoFactory->startFindByDsc(mdbfield.SubcriberID);
			if(oldfield)
			{
				while(oldfield)
				{
					CSysNetPartyLinkStatusInfo *tmpfield =pMemoryDB->m_SysNetPartyLinkStatusInfoFactory->findNextByDsc();

					if(mdbfield.MonDate ==oldfield->MonDate && mdbfield.MonTime ==oldfield->MonTime)
					{	
						pMemoryDB->m_SysNetPartyLinkStatusInfoFactory->remove(oldfield);
					}

					oldfield =tmpfield;
				}
			}

			pMemoryDB->m_SysNetPartyLinkStatusInfoFactory->endFindByDsc();
			
			iList.push_back(mdbfield.SubcriberID);			
		}
		
		pMemoryDB->m_SysNetPartyLinkStatusInfoFactory->add(&mdbfield,NULL);

		if(!m_reload)
		{
			m_pkgSend.PreparePackage(FTD_TID_RtnNetPartyLinkStatusInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);
			list<CFTDCSession *>::iterator it;
			for(it=g_mListAllSession.begin();it!=g_mListAllSession.end();it++)
			{
				(*it)->SendRequestPackage(&m_pkgSend);
				m_pkgSend.Pop(FTDCHLEN);
			}
		}
		itor.Next();
	}
*/
	CFTDRtnNetPartyLinkStatusInfoField	fieldInfo;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnNetPartyLinkStatusInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);

		CWriteableSysMdbNetPartyLinkStatusInfo mdbfield;
		CopySysNetPartyLinkStatusInfoEntity(&mdbfield, &fieldInfo);
		pMemoryDB->m_SysMdbNetPartyLinkStatusInfoFactory->add(&mdbfield);

		///清理:
		CSysMdbNetPartyLinkStatusInfo	*oldField = pMemoryDB->
			m_SysMdbNetPartyLinkStatusInfoFactory->startFindByTime(
					theDate,
					theTime);
		while (oldField)
		{
			CSysMdbNetPartyLinkStatusInfo	*tmpField = pMemoryDB->
				m_SysMdbNetPartyLinkStatusInfoFactory->findNextByTime();
			pMemoryDB->m_SysMdbNetPartyLinkStatusInfoFactory->remove(oldField);
			oldField = tmpField;
		}

		pMemoryDB->m_SysMdbNetPartyLinkStatusInfoFactory->endFindByTime();

		if (!m_reload)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnNetPartyLinkStatusInfoTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);

			list<CFTDCSession *>::iterator	it;
			for (it = g_mListAllSession.begin();
				 it != g_mListAllSession.end();
				 it++)
			{
				(*it)->SendRequestPackage(&m_pkgSend);
				m_pkgSend.Pop(FTDCHLEN);
			}
		}

		itor.Next();
	}
}

void CStatusSubscriber::OnRtnNetAreaTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnNetAreaField fieldInfo;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnNetAreaField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);

		string	ename = fieldInfo.EName.getValue();
		string	cname = fieldInfo.CName.getValue();

		g_pDataCenterManage->updateCurAppIDStatus(
				ename,
				cname,
				fieldInfo.ID.getValue());

		itor.Next();
	}
}
