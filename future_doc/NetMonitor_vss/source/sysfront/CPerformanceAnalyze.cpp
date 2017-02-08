/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CPerformanceAnalyze.cpp
///@brief	������ǰ�ý����������ܷ�������
///@history
///20131204	����			�������ļ�

#include "CPerformanceAnalyze.h"

// add by cao.ning �������ܴ������
extern CPerformanceAnalyzer* g_pPerformanceAnalyzer;

/* ObjectAttrValue */
void ObjectAttrValue::add( float _val, time_t _time )
{
	// ��ָֹ��ֵ��������������ɾ����������ʱ�������
	for (vector<ValuePair >::iterator iterValue = m_Values.begin();
		iterValue != m_Values.end(); )
	{
		if (_time - iterValue->m_time >= MAX_ATTR_SAVEDTIME)
		{
			iterValue = m_Values.erase(iterValue);
		}
		else
		{
			break;
		}
	}

	m_Values.push_back(ValuePair(_val, _time));
	// �������Ϣ֮���޸ı��
	m_valid = true;

}

float ObjectAttrValue::GetMax()
{
	float _tmp = 0.0;
	_tmp = m_MaxValue;
	return _tmp;
}

float ObjectAttrValue::GetAvg()
{
	float _tmp = 0.0;
	_tmp = m_AvgValue;
	return _tmp;
}

float ObjectAttrValue::GetMin()
{
	float _tmp = 0.0;
	_tmp = m_MinValue;
	return _tmp;
}

// ���ı����������Ϣ���ж����ݵ���Ч��
void ObjectAttrValue::UpdateValues()
{
	time_t nowTime = time(NULL);

	// ɾ����������ʱ�������
	for (vector<ValuePair >::iterator iterValue = m_Values.begin();
		iterValue != m_Values.end(); )
	{
		if (nowTime - iterValue->m_time >= MAX_ATTR_SAVEDTIME)
		{
			iterValue = m_Values.erase(iterValue);
		}
		else
		{
			break;
		}
	}

	// �������������Ч�������ø�ָ��Ϊ��Ч
	if (m_Values.empty())
	{
		m_valid = false;
		m_MaxValue = 0.0;
		m_AvgValue = 0.0;
		m_MinValue = FLT_MAX;

		return;
	}

	// ����ƽ����������Сֵ
	double dValueSum = 0.0;
	for (vector<ValuePair>::iterator iterValue = m_Values.begin();
		iterValue != m_Values.end();
		++iterValue)
	{
		dValueSum += iterValue->m_value;
		if (iterValue->m_value > m_MaxValue)
			m_MaxValue = iterValue->m_value;

		if (iterValue->m_value < m_MinValue)
			m_MinValue = iterValue->m_value;
	}
	m_AvgValue = dValueSum / m_Values.size();

}


/* DeviceAttrInfo */
DeviceAttrInfo::DeviceAttrInfo()
{
	// ��ʼ��Ϊ��Ч��ֵ
	m_SubAreaID = -1;
}

DeviceAttrInfo::~DeviceAttrInfo()
{
	m_lock.Lock();
	for (map <string, ObjectAttrValue* >::iterator iterAttrValues = m_AttrValues.begin();
		iterAttrValues != m_AttrValues.end();
		++iterAttrValues)
	{
		ObjectAttrValue* p = iterAttrValues->second;
		delete p;
		p = NULL;
	}

	m_AttrValues.clear();
	m_lock.UnLock();
}

bool DeviceAttrInfo::GetMax( const char* _attrType, float &_val )
{
	m_lock.Lock();
	map <string, ObjectAttrValue* >::iterator iterAttr = m_AttrValues.find(_attrType);
	if (iterAttr == m_AttrValues.end())
	{
		m_lock.UnLock();
		return false;
	}
	else
	{
		ObjectAttrValue* pAttrValueList = iterAttr->second;
		if (!pAttrValueList->isValid())
		{
			m_lock.UnLock();
			return false;
		}
		else
		{
			_val = pAttrValueList->GetMax();
			m_lock.UnLock();
		}
		return true;
	}
}

bool DeviceAttrInfo::GetAvg( const char* _attrType, float &_val )
{
	m_lock.Lock();
	map <string, ObjectAttrValue* >::iterator iterAttr = m_AttrValues.find(_attrType);
	if (iterAttr == m_AttrValues.end())
	{
		m_lock.UnLock();
		return false;
	}
	else
	{
		ObjectAttrValue* pAttrValueList = iterAttr->second;
		if (!pAttrValueList->isValid())
		{
			m_lock.UnLock();
			return false;
		}
		else
		{
			_val = pAttrValueList->GetAvg();
			m_lock.UnLock();
		}
		return true;
	}
}

bool DeviceAttrInfo::GetMin( const char* _attrType, float &_val )
{
	m_lock.Lock();
	map <string, ObjectAttrValue* >::iterator iterAttr = m_AttrValues.find(_attrType);
	if (iterAttr == m_AttrValues.end())
	{
		m_lock.UnLock();
		return false;
	}
	else
	{
		ObjectAttrValue* pAttrValueList = iterAttr->second;
		if (!pAttrValueList->isValid())
		{
			m_lock.UnLock();
			return false;
		}
		else
		{
			_val = pAttrValueList->GetMin();
			m_lock.UnLock();
		}
		return true;
	}
}

void DeviceAttrInfo::addAttrValue( string _attrType, float _val, time_t _time )
{
	// �����ж��¼��Ƿ�����Ҫ��
	time_t nowTime = time(NULL);
	if (_time > nowTime || (nowTime - _time) > MAX_ATTR_SAVEDTIME)
		return;

	m_lock.Lock();
	map <string, ObjectAttrValue* >::iterator iterAttr = m_AttrValues.find(_attrType);
	ObjectAttrValue* pAttrValueList = NULL;
	if (iterAttr == m_AttrValues.end())
	{
		ObjectAttrValue *newAttrValue = new ObjectAttrValue();
		m_AttrValues[_attrType] = newAttrValue;

		iterAttr = m_AttrValues.find(_attrType);
	}
	pAttrValueList = iterAttr->second;
	pAttrValueList->add(_val, _time);
	m_lock.UnLock();
}

// ���¸��豸�ĸ�ָ��ֵ��Ϣ
void DeviceAttrInfo::updateAttrValue()
{
	m_lock.Lock();
	for (map <string, ObjectAttrValue* >::iterator iterAttrValue = m_AttrValues.begin();
		iterAttrValue != m_AttrValues.end();
		++iterAttrValue)
	{
		ObjectAttrValue* pAttrValueList = iterAttrValue->second;
		pAttrValueList->UpdateValues();
	}
	m_lock.UnLock();
}

void DeviceAttrInfo::updateAttrValue( const char* _attrType )
{
	m_lock.Lock();
	map <string, ObjectAttrValue* >::iterator iterAttrValue = m_AttrValues.find(_attrType);
	if (iterAttrValue != m_AttrValues.end())
	{
		ObjectAttrValue* pAttrValueList = iterAttrValue->second;
		pAttrValueList->UpdateValues();
	}
	m_lock.UnLock();
}


/* CPerformanceSubscription */
bool CPerformanceSubscription::CompareSubscription( 
	CFTDReqQryPerformanceTopField field )
{
	if (
		strcmp(m_Field.AttrType.getValue(), field.AttrType.getValue()) == 0
		&&
		m_Field.NetArea.getValue() == field.NetArea.getValue()
		&&
		strcmp(m_Field.NetSubArea.getValue(), field.NetSubArea.getValue()) == 0
		&&
		strcmp(m_Field.KeyWord.getValue(), field.KeyWord.getValue()) == 0
		&&
		m_Field.SortType.getValue() == field.SortType.getValue()
		&&
		m_Field.SortValue.getValue() == field.SortValue.getValue()
		)
		return true;
	else
		return false;
}

bool CPerformanceSubscription::CompareSubscription( 
	CFTDRspQryPerformanceTopField field )
{
	if (
		strcmp(m_Field.AttrType.getValue(), field.AttrType.getValue()) == 0
		&&
		m_Field.NetArea.getValue() == field.NetArea.getValue()
		&&
		strcmp(m_Field.NetSubArea.getValue(), field.NetSubArea.getValue()) == 0
		&&
		strcmp(m_Field.KeyWord.getValue(), field.KeyWord.getValue()) == 0
		&&
		m_Field.SortType.getValue() == field.SortType.getValue()
		&&
		m_Field.SortValue.getValue() == field.SortValue.getValue()
		)
		return true;
	else
		return false;
}

void CPerformanceSubscription::AddSubscriptionSession( DWORD _session )
{
	// ��ֹ�����ظ��ĻỰ
	if (find(m_ClientSessions.begin(), m_ClientSessions.end(), _session) == m_ClientSessions.end())
	{
		m_ClientSessions.push_back(_session);
	}
}

void CPerformanceSubscription::DelSubscriptionSession( DWORD _session )
{
	for (vector<DWORD >::iterator iterSession = m_ClientSessions.begin();
		iterSession != m_ClientSessions.end();
		++iterSession)
	{
		if (*iterSession == _session)
		{
			m_ClientSessions.erase(iterSession);
			return;
		}
	}
}

void CPerformanceSubscription::AddDeviceAttrValue( DeviceAttrInfo* pDevice, float _value )
{
	if (m_PerformanceResults.empty())
	{
		m_PerformanceResults.push_back(make_pair(pDevice, _value));
		return;
	}

	// �������ͣ� 1, ����ȡ��С��ǰN����; 2, ����ȡ����ǰN����
	int nSortType = m_Field.SortType.getValue();
	int nTopN = m_Field.TopN.getValue();

	// ������һ�߽�����������
	vector< pair<DeviceAttrInfo*, float> >::iterator iterRes = m_PerformanceResults.begin();
	bool bInsertValue = false;	// ָʾ��ֵ�Ƿ��Ѿ����룬��ֹ�����������ظ�����
	while (iterRes != m_PerformanceResults.end())
	{
		// ��������д��ڸ��豸
		if (iterRes->first == pDevice)
		{
			if (iterRes->second == _value)
			{
				// ���ֵû�з����仯�����ټ���
				return;
			}
			else
			{
				iterRes = m_PerformanceResults.erase(iterRes);
			}
		}
		else
		{
			if (nSortType == 1 && _value < iterRes->second && !bInsertValue)
			{
				iterRes = m_PerformanceResults.insert(iterRes, make_pair(pDevice, _value));
				bInsertValue = true;
			}
			if (nSortType == 2 && _value > iterRes->second && !bInsertValue)
			{
				iterRes = m_PerformanceResults.insert(iterRes, make_pair(pDevice, _value));
				bInsertValue = true;
			}
			++iterRes;
		} // end if
	} // end while

	// ���ֵһֱû��ִ�в��룬�����г����Բ�����Ҫ������뵽���
	if (!bInsertValue && m_PerformanceResults.size() < nTopN * 2)
	{
		// �����������Ľ����Ϊ�˷�ֹ����Χ�ڵ���������ʧЧ��ɾ��
		m_PerformanceResults.push_back(make_pair(pDevice, _value));
	}
	// Ҫ�󱣴�����������ΪTopN��2��
	if (m_PerformanceResults.size() > nTopN * 2)
	{
		m_PerformanceResults.erase(m_PerformanceResults.begin() + nTopN * 2, m_PerformanceResults.end());
	}
}

void CPerformanceSubscription::DelDeviceAttrValue( DeviceAttrInfo* pDevice )
{
	for (vector< pair<DeviceAttrInfo*, float> >::iterator iterDeviceValue = m_PerformanceResults.begin();
		iterDeviceValue != m_PerformanceResults.end();
		++iterDeviceValue)
	{
		if (iterDeviceValue->first == pDevice)
		{
			m_PerformanceResults.erase(iterDeviceValue);
			break;
		}
	}
}

void CPerformanceSubscription::DelDevice( DeviceAttrInfo* pDevice )
{
	// ����ɾ���������е���Ϣ
	DelDeviceAttrValue(pDevice);

	// �Ӹ��ǵ��豸�б���ɾ�����豸
	for (vector<DeviceAttrInfo* >::iterator iterDevice = m_ContainedDevices.begin();
		iterDevice != m_ContainedDevices.end();
		++iterDevice)
	{
		if ((*iterDevice) == pDevice)
		{
			m_ContainedDevices.erase(iterDevice);
			return;
		}
	}
}

void CPerformanceSubscription::PrintSubscription()
{
	printf("@@@ Sub: %s\n", GetSubKey().c_str());
	printf("\tSession: ");
	for (vector<DWORD>::iterator iterSession = m_ClientSessions.begin();
		iterSession != m_ClientSessions.end();
		++iterSession)
	{
		printf("%x ", *iterSession);
	}
	printf("\n\tContainedDevices: ");
	for (vector<DeviceAttrInfo* >::iterator iterDevice = m_ContainedDevices.begin();
		iterDevice != m_ContainedDevices.end();
		++iterDevice)
	{
		printf("[%s] ", (*iterDevice)->m_ObjectID.c_str());
	}
	printf("\n");
}

std::string CPerformanceSubscription::GetSubKey()
{
	char szBuff[256] = {0};
	sprintf(szBuff, "%s.%d.%s.%s.%d.%d.%d", 
		m_Field.AttrType.getValue(),
		m_Field.NetArea.getValue(),
		m_Field.NetSubArea.getValue(),
		m_Field.KeyWord.getValue(),
		m_Field.SortValue.getValue(),
		m_Field.SortType.getValue(),
		m_Field.TopN.getValue());
	
	string s = szBuff;
	return s;
}

void CPerformanceSubscription::PrintSubResults()
{
	if (m_PerformanceResults.empty())
	{
		printf("NULL\n");
		return;
	}

	int nTopN = m_Field.TopN.getValue();
	int nSendIndex = 1;
	for (vector< pair<DeviceAttrInfo*, float> >::iterator iterRes = m_PerformanceResults.begin();
		nSendIndex <= nTopN && iterRes != m_PerformanceResults.end();
		++iterRes, ++nSendIndex)
	{
		DeviceAttrInfo* p = iterRes->first;
		printf(" %d#[%s][%.2f]", nSendIndex, p->m_ObjectID.c_str(), iterRes->second);
	}
	printf("\n");
}



/* CPerformanceAnalyzeThread */
bool CPerformanceAnalyzeThread::InitInstance( void )
{
	return true;
}

void CPerformanceAnalyzeThread::ExitInstance( void )
{
}

void CPerformanceAnalyzeThread::Run( void )
{
	while (1)
	{
		// todo
		// 1 ���������豸��ָ����Ϣ
		// 2 �ж��豸��ָ����Ϣ�Ƿ���Ч
		// 3 ����ÿ�����ĵ�����ֵ
		// 4 ��ĳ�������ݷ����仯��֪ͨ�ͻ���

		// ���¸�ָ��������
		g_pPerformanceAnalyzer->UpdateSubscriptionResult();

		// �Ƴ��ỰΪ�յĶ�����Ϣ
		g_pPerformanceAnalyzer->RemoveInvalidSubscription();

		SLEEP(60 * 1000);	// 1min

	}
}


/* CPerformanceAnalyzer */

void CPerformanceAnalyzer::UpdateNetConfig( CFTDCPackage *pFTDCPackage )
{
	switch (pFTDCPackage->GetTID())
	{
		// ������������
	case FTD_TID_RspQryGeneralOperateTopic:
		{
			CFTDRspQryGeneralOperateField rspField;
			CFTDRtnGeneralOperateField field;	// rsp��rtn����ṹ��һ���ģ�ʹ��rtn����ͳһ����
			CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
				&CFTDRspQryGeneralOperateField::m_Describe);
			while (!itor.IsEnd())
			{
				itor.Retrieve(&rspField);
				memset(&field, 0, sizeof(CFTDRtnGeneralOperateField));
				CopySysGeneralOperateEntity(&field, &rspField);
				UpdateNetArea(field);
				itor.Next();
			}
			break;
		}
		// ������������
	case FTD_TID_RtnGeneralOperateTopic:
		{
			CFTDRtnGeneralOperateField Field;
			CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
				&CFTDRtnGeneralOperateField::m_Describe);
			while (!itor.IsEnd())
			{
				itor.Retrieve(&Field);
				UpdateNetArea(Field);
				itor.Next();
			}
			break;
		}
		// �����豸����
	case FTD_TID_RspQryNetDeviceTopic:
		{
			CFTDRspQryNetDeviceField rspField;
			CFTDRtnNetDeviceField field;	// rsp��rtn����ṹ��һ���ģ�ʹ��rtn����ͳһ����
			CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
				&CFTDRspQryNetDeviceField::m_Describe);
			while (!itor.IsEnd())
			{
				itor.Retrieve(&rspField);
				memset(&field, 0, sizeof(CFTDRtnNetDeviceField));
				CopyRspQryNetDeviceEntity(&field, &rspField);
				UpdateNetDevice(field);
				itor.Next();
			}
			break;
		}
	case FTD_TID_RtnNetDeviceTopic:
		{
			CFTDRtnNetDeviceField field;
			CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
				&CFTDRtnNetDeviceField::m_Describe);
			while (!itor.IsEnd())
			{
				itor.Retrieve(&field);
				UpdateNetDevice(field);
				itor.Next();
			}
			break;
		}
	default:
		break;
	}

}

// ���ñ�����Ϣ������������豸����
void CPerformanceAnalyzer::UpdateNetDevice( const CFTDRtnNetDeviceField &field )
{
	// ��Ҫ��ȡÿ���豸��ObjectID��NetSubAreaID��IP Address
	string szObjectID = field.ObjectID.getValue();
	string szIpAddress = field.IPADDR.getValue();
	int nNetSubAreaID = field.SysNetSubAreaID.getValue();

	switch (field.OperationType)
	{
	case 2:	// ��
	case 4:	// ��
		{
			// ���±��ص��豸��Ϣ
			map<string, DeviceAttrInfo* >::iterator iterDevice = m_ObjectIDtoDeviceMAP.find(szObjectID);
			if (iterDevice != m_ObjectIDtoDeviceMAP.end())
			{
				iterDevice->second->m_IpAddress = szIpAddress;
				iterDevice->second->m_SubAreaID = nNetSubAreaID;
			}
			else
			{
				DeviceAttrInfo* thisDevice = new DeviceAttrInfo();
				thisDevice->m_IpAddress = szIpAddress;
				thisDevice->m_SubAreaID = nNetSubAreaID;
				thisDevice->m_ObjectID = szObjectID;

				// ����ObjectID��Device֮���MAP
				m_ObjectIDtoDeviceMAP[szObjectID] = thisDevice;

				// �������ӵ��豸������Ҫ�������еĶ�����Ϣ
				// �������ж��ģ������豸���ڸö��ĵķ�Χ֮�ڣ�����ö�����Ӹ��豸
				m_SubLock.Lock();printf("SubLock UpdateNetDevice\n");
				for (vector<CPerformanceSubscription* >::iterator iterSub = m_Subscriptions.begin();
					iterSub != m_Subscriptions.end();
					++iterSub)
				{
					if (isDeviceInSubscription(thisDevice, *iterSub))
					{
						// ���豸���ڸö��ĵķ�Χ֮��
						(*iterSub)->m_ContainedDevices.push_back(thisDevice);
					}
				}
				m_SubLock.UnLock();printf("SubUnLock UpdateNetDevice\n");
			}
			break;
		}
	case 3:	// ɾ
		{
			// ɾ���豸��Ϣ
			map<string, DeviceAttrInfo* >::iterator iterDevice = m_ObjectIDtoDeviceMAP.find(szObjectID);
			if (iterDevice != m_ObjectIDtoDeviceMAP.end())
			{
				DeviceAttrInfo* pDevice = iterDevice->second;
				
				// �������ж��ģ�ɾ�������еĸ��豸
				m_SubLock.Lock();printf("SubLock UpdateNetDevice2\n");
				for (vector<CPerformanceSubscription* >::iterator iterSub = m_Subscriptions.begin();
					iterSub != m_Subscriptions.end();
					++iterSub)
				{
					// ɾ���ö����и��豸����Ϣ����������������е�ֵ�͸����豸�е���Ϣ
					(*iterSub)->DelDevice(pDevice);
				}
				m_SubLock.UnLock();printf("SubUnLock UpdateNetDevice2\n");

				// ���豸������ɾ�����豸
				m_ObjectIDtoDeviceMAP.erase(iterDevice);

				// ɾ�����豸����
				delete pDevice;
			}
			break;
		}
	case 1: // ��
	default:
		break;
	}
}

// ���ñ�����Ϣ�������������������
void CPerformanceAnalyzer::UpdateNetArea(const CFTDRtnGeneralOperateField &field)
{
	// ������������������Ϣ
	if (strcmp(field.GeneralOperateTable.getValue(), "SysNetSubArea") == 0)
	{
		string strSubArea = field.GeneralOperateSet.getValue();
		// 1*:*1*:*�칫*:*OA
		// SubAreaID : NetAreaID : SubAreaCName : SubAreaEName
		int nNetSubAreaID, nNetAreaID;
		char szSubAreaEName[128] = {0};
		sscanf(strSubArea.c_str(), "%d*:*%d*:*%*[^*]*:*%s", &nNetSubAreaID, &nNetAreaID, szSubAreaEName);

		m_NetAreaConfig[nNetSubAreaID] = make_pair(nNetAreaID, szSubAreaEName);
	}
	else if (strcmp(field.GeneralOperateTable.getValue(), "SysNetDevice") == 0)
	{
		// �豸��Ϣ��ͨ��NetDevice���ķ��͵ģ���GeneralOperate��Ҳ�����˸ò����������ڷ�ֹ��©
		string strNetDevice = field.GeneralOperateSet.getValue();	
		/*
		* ID : ��ض��� : ��ض������� : SysNetSubAreaID : ����ID : ��Ϊ���ֵ�ְ������ : IP��ַ : IP�� : �豸���� :
		* PORTNUMBER : CONFIGFILE : ��ͬ���� : snmp�汾 : ramsize(B) : falshsize(B) : nvramsize(B) : �������� : 
		* ROOM_ID : ����汾 : ϵͳ���� : ��¼�û��� : ��¼���� : enable���� : �������� : ���ñ���Э�� : �豸�ͺ� :
		* �Ƿ���Ÿ澯 : �Ƿ��Զ�snmp̽�� : ��λ�� : �Ƿ��Զ�ping : �˿����� : Ѳ�����
		* ʾ����
		* 3*:*PuDian.WG.PD-WG3750-C4-4N101*:*21*:*5*:*2*:*access*:*172.1.0.4*:*5*:*PD-WG3750-C4-4N101*:*
		* 0*:**:*thbczh2005*:*0*:*0*:*0*:*0*:*0*:*0*:* 0*:*Cisco IOS Software, C3750 Software ... by prod_rel_team*:* 
		* healthcheck2*:*6hXSmEWasFsfDf+qPNHzrA==@#$*:*6hXSmEWasFsfDf+qPNHzrA==@#$*:*1*:*0*:*3750*:*0*:*0*:*0*:*0*:*58*:*0
		*/

		// ��Ҫ��ȡÿ���豸��ObjectID��NetSubAreaID��IP Address
		char szObjectID[128] = {0}, szIpAddress[32] = {0};
		int nNetSubAreaID;
		sscanf(strNetDevice.c_str(), "%*d*:*%[^*]*:*%*d*:*%d*:*%*d*:*%*[^*]*:*%[^*]*:*%*s",
			szObjectID, &nNetSubAreaID, szIpAddress);

		// ���±��ص��豸��Ϣ
		map<string, DeviceAttrInfo* >::iterator iterDevice = m_ObjectIDtoDeviceMAP.find(szObjectID);
		if (iterDevice != m_ObjectIDtoDeviceMAP.end())
		{
			iterDevice->second->m_IpAddress = szIpAddress;
			iterDevice->second->m_SubAreaID = nNetSubAreaID;
		}
		else
		{
			DeviceAttrInfo* thisDevice = new DeviceAttrInfo();
			thisDevice->m_IpAddress = szIpAddress;
			thisDevice->m_SubAreaID = nNetSubAreaID;
			thisDevice->m_ObjectID = szObjectID;

			// ����ObjectID��Device֮���MAP
			m_ObjectIDtoDeviceMAP[szObjectID] = thisDevice;

			// �������ӵ��豸������Ҫ�������еĶ�����Ϣ
			// �������ж��ģ������豸���ڸö��ĵķ�Χ֮�ڣ�����ö�����Ӹ��豸
			m_SubLock.Lock();printf("SubLock UpdateNetArea\n");
			for (vector<CPerformanceSubscription* >::iterator iterSub = m_Subscriptions.begin();
				iterSub != m_Subscriptions.end();
				++iterSub)
			{
				if (isDeviceInSubscription(thisDevice, *iterSub))
				{
					// ���豸���ڸö��ĵķ�Χ֮��
					(*iterSub)->m_ContainedDevices.push_back(thisDevice);
				}
			}
			m_SubLock.UnLock();printf("SubUnLock UpdateNetArea\n");
		}

	}
	else
		return;
}

// ����һ��ʵʱ���ܷ�������
// QryField: ���������
// nSessionID: �����SessionID
bool CPerformanceAnalyzer::AddSubscription( 
	CFTDReqQryPerformanceTopField QryField, 
	CFTDCSession *pSession )
{
	ThreadCheck();

	CPerformanceSubscription* pSub = NULL;

	m_SubLock.Lock();printf("SubLock AddSubscription\n");
	for (int i = 0; i < m_Subscriptions.size(); ++i)
	{
		CPerformanceSubscription* tmp = m_Subscriptions[i];
		// �ҵ�ͬ���Ķ�����Ϣ����ֻ��Ҫ��Ӷ��ĻỰ
		if (tmp->CompareSubscription(QryField))
		{
			tmp->AddSubscriptionSession(pSession->GetSessionID());
			pSub = tmp;
		}
	}
	m_SubLock.UnLock();printf("SubUnLock AddSubscription\n");

	// ������Ĳ����ڣ��������Ϣ
	if (pSub == NULL)
	{
		// ��Ӷ��İ��������ɾ���Ķ��Ķ���
		pSub = new CPerformanceSubscription();
		CopySysPerformanceTopEntity(&(pSub->m_Field), &QryField);
		pSub->AddSubscriptionSession(pSession->GetSessionID());

		// ���������豸���ж���Щ�豸���ڸö���
		// ���¶��ľ���
		for (map<string, DeviceAttrInfo* >::iterator iterDevice = m_ObjectIDtoDeviceMAP.begin();
			iterDevice != m_ObjectIDtoDeviceMAP.end();
			++iterDevice)
		{
			DeviceAttrInfo* pDevice = iterDevice->second;
			if (isDeviceInSubscription(pDevice, pSub))
			{
				pSub->m_ContainedDevices.push_back(pDevice);
			}
		}

		// ����ö�����û�а����κ��豸���򷵻ش�����Ϣ
		if (pSub->m_ContainedDevices.empty())
		{
			delete pSub;
			return false;
		}
		else
		{
			m_SubLock.Lock();printf("SubLock AddSubscription2\n");
			m_Subscriptions.push_back(pSub);
			m_SubLock.UnLock();printf("SubUnLock AddSubscription2\n");

			printf("@@@ Add Subscription:\n");
			pSub->PrintSubscription();
		}
	}
	return true;
}

// ɾ��һ������
void CPerformanceAnalyzer::DelSubscription( 
	CFTDReqQryPerformanceTopField QryField, 
	CFTDCSession *pSession )
{
	m_SubLock.Lock();printf("SubLock DelSubscription\n");
	for (vector<CPerformanceSubscription* >::iterator iterSub = m_Subscriptions.begin();
		iterSub != m_Subscriptions.end();
		++iterSub)
	{
		if ((*iterSub)->CompareSubscription(QryField))
		{
			printf("@@@ Del Session From Subscription: %s\n", (*iterSub)->GetSubKey().c_str());
			(*iterSub)->DelSubscriptionSession(pSession->GetSessionID());

			if ((*iterSub)->m_ClientSessions.empty())
			{
				printf("@@@ Del Subscription: %s\n", (*iterSub)->GetSubKey().c_str());
				delete (*iterSub);
				m_Subscriptions.erase(iterSub);
			}
			m_SubLock.UnLock();printf("SubUnLock DelSubscription\n");
			return ;
		}
	}
	m_SubLock.UnLock();printf("SubUnLock DelSubscription\n");
}

// �鿴ĳ�豸�Ƿ�����ĳ���ĵķ�Χ֮��
// nDevice���豸ID��nSubID������ID
bool CPerformanceAnalyzer::isDeviceInSubscription( 
	DeviceAttrInfo* pDevice, 
	CPerformanceSubscription* pSub )
{
	// ���豸����������
	int nDeviceNetSubAreaID = pDevice->m_SubAreaID;
	map<int, pair<int, string> >::iterator iterNetArea = m_NetAreaConfig.find(nDeviceNetSubAreaID);
	if (iterNetArea == m_NetAreaConfig.end())
	{
		printf("@@@ Performance Analyze Error! Cann't find NetSubAreaID[%d]\n", nDeviceNetSubAreaID);
		return false;
	}
	else
	{
		// �豸����������ID������EName
		int nDeviceNetID = iterNetArea->second.first;
		string strNetSubAreaEName = iterNetArea->second.second;
		// �豸��ObjectID
		string strDeviceObjectID = pDevice->m_ObjectID;

		// �������Ƶ�����ID������EName
		int nSubNetID = pSub->m_Field.NetArea.getValue();
		string strSubNetSubAreaEName = pSub->m_Field.NetSubArea.getValue();
		// ���ĵ�����KeyWord
		string strKeyWord = pSub->m_Field.KeyWord.getValue();

		if (
			(nDeviceNetID == nSubNetID || nSubNetID == 0)
			&&
			(strNetSubAreaEName.compare(strSubNetSubAreaEName) == 0 || strSubNetSubAreaEName.compare("ALL") == 0)
			&&
			(strKeyWord.empty() || (!strKeyWord.empty() && strDeviceObjectID.find(strKeyWord) != string::npos))
			)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

// ����ָ����Ϣ��ͨ�汨��
void CPerformanceAnalyzer::OnRtnObjectAttrTopic( CFTDCPackage *pRtnFTDCPackage )
{
	ThreadCheck();

	CFTDRtnObjectAttrField field;
	CNamedFieldIterator itor = pRtnFTDCPackage->GetNamedFieldIterator(
		&CFTDRtnObjectAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		string strAttrType = field.AttrType.getValue();
		if (strAttrType.compare("MEMUsage") == 0
			||
			strAttrType.compare("cpmCPUTotal1minRev") == 0
			||
			strAttrType.compare("nsResSessAllocate") == 0)
		{
			string strObjectID = field.ObjectID.getValue();
			map<string, DeviceAttrInfo* >::iterator iterDeviceID = m_ObjectIDtoDeviceMAP.find(strObjectID);
			if (iterDeviceID != m_ObjectIDtoDeviceMAP.end())
			{
				DeviceAttrInfo* pDevice = iterDeviceID->second;

				float fValue = atof(field.AttrValue.getValue());
				time_t tTime = m_Timer.GetTimeSec(field.MonDate.getValue(), field.MonTime.getValue());

				pDevice->addAttrValue(strAttrType, fValue, tTime);

			}
		}

		itor.Next();
	}
}

// ��ĳ���ĵĽ��ͨ��Rtn����ͨ��ͻ���
void CPerformanceAnalyzer::NotifyClients( CPerformanceSubscription* pSub )
{
	if (pSub->m_ClientSessions.empty())
	{
		printf("@@@ Performance Analyze Error! SessionList is Null!\n");
		return;
	}
	if (pSub->m_PerformanceResults.empty())
	{
		printf("@@@ Performance Analyze Error! SortResultList is Null!\n");
		m_pkgSend.PreparePackage(FTD_TID_RtnPerformanceTopTopic, FTDC_CHAIN_LAST, FTD_VERSION);
		CFTDRtnPerformanceTopField rtnField;
		memset(&rtnField, 0, sizeof(CFTDRtnPerformanceTopField));
		CopySysPerformanceTopEntity(&rtnField, &(pSub->m_Field));
		FTDC_ADD_FIELD(&m_pkgSend, &rtnField);
		for (vector<DWORD>::iterator iterSession = pSub->m_ClientSessions.begin();
			iterSession != pSub->m_ClientSessions.end();
			++iterSession)
		{
			if (m_pFrontServer && m_pFrontServer->GetSession(*iterSession))
			{
				((CFTDCSession *)(m_pFrontServer->GetSession(*iterSession)))->SendRequestPackage(&m_pkgSend);
				m_pkgSend.Pop(FTDCHLEN);
			}
		}
		return;
	}

	m_pkgSend.PreparePackage(FTD_TID_RtnPerformanceTopTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	CFTDRtnPerformanceTopField rtnField;
	memset(&rtnField, 0, sizeof(CFTDRtnPerformanceTopField));
	CopySysPerformanceTopEntity(&rtnField, &(pSub->m_Field));

	// ���ڱ���������
	string strSortResult;

	int nTopN = pSub->GetTopNumber();
	int nSendIndex = 1;
	
	for (vector< pair<DeviceAttrInfo*, float> >::iterator iterRes = pSub->m_PerformanceResults.begin();
		iterRes != pSub->m_PerformanceResults.end() && nSendIndex <= nTopN;
		++iterRes, ++nSendIndex)
	{
		DeviceAttrInfo* pDevice = iterRes->first;
		char szBuff[32] = {0};
		sprintf(szBuff, "%d#%s#%.2f;", 
			nSendIndex, pDevice->m_IpAddress.c_str(), iterRes->second);
		
		if (strSortResult.size() + strlen(szBuff) >= 256)	// result�ֶ��256
		{
			rtnField.TopResult = strSortResult.c_str();
			FTDC_ADD_FIELD(&m_pkgSend, &rtnField);

			memset(&rtnField, 0, sizeof(CFTDRtnPerformanceTopField));
			CopySysPerformanceTopEntity(&rtnField, &(pSub->m_Field));
			strSortResult.clear();

			if (m_pkgSend.Length() + sizeof(CFTDRtnPerformanceTopField) > FTDC_PACKAGE_MAX_SIZE)
			{
				m_pkgSend.SetChain(FTDC_CHAIN_CONTINUE);

				// ���ĵ�ÿ���ͻ��˷���rtn
				for (vector<DWORD>::iterator iterSession = pSub->m_ClientSessions.begin();
					iterSession != pSub->m_ClientSessions.end();
					++iterSession)
				{
					//(*iterSession)->SendRequestPackage(&m_pkgSend);
					if (m_pFrontServer && m_pFrontServer->GetSession(*iterSession))
					{
						((CFTDCSession *)(m_pFrontServer->GetSession(*iterSession)))->SendRequestPackage(&m_pkgSend);
						m_pkgSend.Pop(FTDCHLEN);
					}
				}

				m_pkgSend.PreparePackage(FTD_TID_RtnPerformanceTopTopic, FTDC_CHAIN_LAST, FTD_VERSION);
			}
		}
		
		strSortResult.append(szBuff);
	}

	// send last packet
	if (!strSortResult.empty())
	{
		rtnField.TopResult = strSortResult.c_str();
		FTDC_ADD_FIELD(&m_pkgSend, &rtnField);
	}

	m_pkgSend.SetChain(FTDC_CHAIN_LAST);
	// ���ĵ�ÿ���ͻ��˷���rtn
	for (vector<DWORD>::iterator iterSession = pSub->m_ClientSessions.begin();
		iterSession != pSub->m_ClientSessions.end();
		++iterSession)
	{
		//(*iterSession)->SendRequestPackage(&m_pkgSend);
		if (m_pFrontServer && m_pFrontServer->GetSession(*iterSession))
		{
			((CFTDCSession *)(m_pFrontServer->GetSession(*iterSession)))->SendRequestPackage(&m_pkgSend);
			m_pkgSend.Pop(FTDCHLEN);
		}
	}
}

void CPerformanceAnalyzer::RemoveInvalidSubscription()
{
	m_SubLock.Lock();printf("SubLock RemoveInvalidSubscription\n");
	vector<CPerformanceSubscription* >::iterator iterSub = m_Subscriptions.begin();
	while (iterSub != m_Subscriptions.end())
	{
		if ((*iterSub)->m_ClientSessions.empty())
		{
			iterSub = m_Subscriptions.erase(iterSub);
		}
		else
		{
			++iterSub;
		}
	}
	m_SubLock.UnLock();printf("SubUnLock RemoveInvalidSubscription\n");
}

void CPerformanceAnalyzer::UpdateSubscriptionResult()
{
	//  ����ÿ��������Ϣ������ö��ĵ���������ֵ
	m_SubLock.Lock();printf("SubLock UpdateSubscriptionResult\n");
	for (vector<CPerformanceSubscription* >::iterator iterSub = m_Subscriptions.begin();
		iterSub != m_Subscriptions.end();
		++iterSub)
	{
		CPerformanceSubscription* pSub = (*iterSub);
		const char* szAttrType = pSub->GetAttrType();
		vector<DeviceAttrInfo* > &SubDeviceList = pSub->m_ContainedDevices;

		// �����ö��������ǵ������豸���豸ID
		for (vector<DeviceAttrInfo* >::iterator iterDevice = SubDeviceList.begin();
			iterDevice != SubDeviceList.end();
			++iterDevice)
		{
			DeviceAttrInfo* pDevice = (*iterDevice);
			// �����豸���ڸ�ָ�������
			pDevice->updateAttrValue(szAttrType);

			float _fAttrValue = 0.0;
			bool _bGetRes = false;
			// ���ݶ���ֵ�����ͣ���ȡ��Ӧ������
			switch (pSub->GetSortValueType())
			{
			case 0:	// ƽ��ֵ
				_bGetRes = pDevice->GetAvg(szAttrType, _fAttrValue);
				break;
			case 1:	// ��Сֵ
				_bGetRes = pDevice->GetMin(szAttrType, _fAttrValue);
				break;
			case 2:	// ���ֵ
				_bGetRes = pDevice->GetMax(szAttrType, _fAttrValue);
				break;
			default:
				// ������ĵ�ֵ���ʹ�����˵���ö�����Ч��ɾ��
				printf("@@@ Performance Analyze Error! Subscription SortValueType Error! [%d]\n",
					pSub->GetSortValueType());
				break;
			}

			// �����ȡ����Чֵ����ӽ��������ɾ�����豸
			if (!_bGetRes)
			{
				pSub->DelDeviceAttrValue(pDevice);
			}
			else
			{
				pSub->AddDeviceAttrValue(pDevice, _fAttrValue);
			}
		}

		// test print
		printf("@@@ Sub[%s] Result:\n\t", pSub->GetSubKey().c_str());
		pSub->PrintSubResults();

		// ���ö��ĵ�����������֪ͨ���ͻ���
		NotifyClients(pSub);
	}
	m_SubLock.UnLock();printf("SubUnLock UpdateSubscriptionResult\n");
}

void CPerformanceAnalyzer::RemoveClientSession( DWORD dSession )
{
	m_SubLock.Lock();printf("SubLock RemoveClientSession\n");
	for (vector<CPerformanceSubscription* >::iterator iterSub = m_Subscriptions.begin();
		iterSub != m_Subscriptions.end();
		++iterSub)
	{
		(*iterSub)->DelSubscriptionSession(dSession);
	}
	m_SubLock.UnLock();printf("SubUnLock RemoveClientSession\n");
}
