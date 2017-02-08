/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CPerformanceAnalyze.cpp
///@brief	定义了前置进行网络性能分析的类
///@history
///20131204	曹宁			创建该文件

#include "CPerformanceAnalyze.h"

// add by cao.ning 网络性能处理对象
extern CPerformanceAnalyzer* g_pPerformanceAnalyzer;

/* ObjectAttrValue */
void ObjectAttrValue::add( float _val, time_t _time )
{
	// 防止指标值队列无限增长，删除超出限制时间的数据
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
	// 添加了信息之后，修改标记
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

// 跟心保存的数据信息，判断数据的有效性
void ObjectAttrValue::UpdateValues()
{
	time_t nowTime = time(NULL);

	// 删除超出限制时间的数据
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

	// 如果所有数据无效，则设置该指标为无效
	if (m_Values.empty())
	{
		m_valid = false;
		m_MaxValue = 0.0;
		m_AvgValue = 0.0;
		m_MinValue = FLT_MAX;

		return;
	}

	// 更新平均、最大和最小值
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
	// 初始化为无效的值
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
	// 首先判断事件是否满足要求
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

// 更新该设备的各指标值信息
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
	// 防止插入重复的会话
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

	// 排序类型： 1, 升序（取最小的前N个）; 2, 降序（取最大的前N个）
	int nSortType = m_Field.SortType.getValue();
	int nTopN = m_Field.TopN.getValue();

	// 仅遍历一边进行重新排序
	vector< pair<DeviceAttrInfo*, float> >::iterator iterRes = m_PerformanceResults.begin();
	bool bInsertValue = false;	// 指示该值是否已经插入，防止遍历过程中重复插入
	while (iterRes != m_PerformanceResults.end())
	{
		// 如果队列中存在该设备
		if (iterRes->first == pDevice)
		{
			if (iterRes->second == _value)
			{
				// 如果值没有发生变化，则不再继续
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

	// 如果值一直没有执行插入，若队列长度仍不满足要求，则插入到最后
	if (!bInsertValue && m_PerformanceResults.size() < nTopN * 2)
	{
		// 保存两倍长的结果是为了防止排序范围内的数据由于失效被删除
		m_PerformanceResults.push_back(make_pair(pDevice, _value));
	}
	// 要求保存的数据量最多为TopN的2倍
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
	// 首先删除排序结果中的信息
	DelDeviceAttrValue(pDevice);

	// 从覆盖的设备列表中删除该设备
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
		// 1 处理所有设备的指标信息
		// 2 判断设备的指标信息是否有效
		// 3 计算每个订阅的排序值
		// 4 若某订阅内容发生变化，通知客户端

		// 更新各指标排序结果
		g_pPerformanceAnalyzer->UpdateSubscriptionResult();

		// 移除会话为空的订阅信息
		g_pPerformanceAnalyzer->RemoveInvalidSubscription();

		SLEEP(60 * 1000);	// 1min

	}
}


/* CPerformanceAnalyzer */

void CPerformanceAnalyzer::UpdateNetConfig( CFTDCPackage *pFTDCPackage )
{
	switch (pFTDCPackage->GetTID())
	{
		// 网络区域配置
	case FTD_TID_RspQryGeneralOperateTopic:
		{
			CFTDRspQryGeneralOperateField rspField;
			CFTDRtnGeneralOperateField field;	// rsp与rtn的域结构是一样的，使用rtn报文统一操作
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
		// 网络区域配置
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
		// 网络设备配置
	case FTD_TID_RspQryNetDeviceTopic:
		{
			CFTDRspQryNetDeviceField rspField;
			CFTDRtnNetDeviceField field;	// rsp与rtn的域结构是一样的，使用rtn报文统一操作
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

// 利用报文信息，更新网络的设备配置
void CPerformanceAnalyzer::UpdateNetDevice( const CFTDRtnNetDeviceField &field )
{
	// 需要获取每个设备的ObjectID，NetSubAreaID，IP Address
	string szObjectID = field.ObjectID.getValue();
	string szIpAddress = field.IPADDR.getValue();
	int nNetSubAreaID = field.SysNetSubAreaID.getValue();

	switch (field.OperationType)
	{
	case 2:	// 增
	case 4:	// 改
		{
			// 更新本地的设备信息
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

				// 增加ObjectID和Device之间的MAP
				m_ObjectIDtoDeviceMAP[szObjectID] = thisDevice;

				// 对于增加的设备，还需要更新所有的订阅信息
				// 遍历所有订阅，若该设备处于该订阅的范围之内，则向该订阅添加该设备
				m_SubLock.Lock();printf("SubLock UpdateNetDevice\n");
				for (vector<CPerformanceSubscription* >::iterator iterSub = m_Subscriptions.begin();
					iterSub != m_Subscriptions.end();
					++iterSub)
				{
					if (isDeviceInSubscription(thisDevice, *iterSub))
					{
						// 该设备属于该订阅的范围之内
						(*iterSub)->m_ContainedDevices.push_back(thisDevice);
					}
				}
				m_SubLock.UnLock();printf("SubUnLock UpdateNetDevice\n");
			}
			break;
		}
	case 3:	// 删
		{
			// 删除设备信息
			map<string, DeviceAttrInfo* >::iterator iterDevice = m_ObjectIDtoDeviceMAP.find(szObjectID);
			if (iterDevice != m_ObjectIDtoDeviceMAP.end())
			{
				DeviceAttrInfo* pDevice = iterDevice->second;
				
				// 遍历所有订阅，删除订阅中的该设备
				m_SubLock.Lock();printf("SubLock UpdateNetDevice2\n");
				for (vector<CPerformanceSubscription* >::iterator iterSub = m_Subscriptions.begin();
					iterSub != m_Subscriptions.end();
					++iterSub)
				{
					// 删除该订阅中该设备的信息，包括：排序队列中的值和覆盖设备中的信息
					(*iterSub)->DelDevice(pDevice);
				}
				m_SubLock.UnLock();printf("SubUnLock UpdateNetDevice2\n");

				// 从设备队列中删除该设备
				m_ObjectIDtoDeviceMAP.erase(iterDevice);

				// 删除该设备对象
				delete pDevice;
			}
			break;
		}
	case 1: // 查
	default:
		break;
	}
}

// 利用报文信息，更新网络的区域配置
void CPerformanceAnalyzer::UpdateNetArea(const CFTDRtnGeneralOperateField &field)
{
	// 更新网络区域配置信息
	if (strcmp(field.GeneralOperateTable.getValue(), "SysNetSubArea") == 0)
	{
		string strSubArea = field.GeneralOperateSet.getValue();
		// 1*:*1*:*办公*:*OA
		// SubAreaID : NetAreaID : SubAreaCName : SubAreaEName
		int nNetSubAreaID, nNetAreaID;
		char szSubAreaEName[128] = {0};
		sscanf(strSubArea.c_str(), "%d*:*%d*:*%*[^*]*:*%s", &nNetSubAreaID, &nNetAreaID, szSubAreaEName);

		m_NetAreaConfig[nNetSubAreaID] = make_pair(nNetAreaID, szSubAreaEName);
	}
	else if (strcmp(field.GeneralOperateTable.getValue(), "SysNetDevice") == 0)
	{
		// 设备信息是通过NetDevice报文发送的，但GeneralOperate中也定义了该操作。仅用于防止遗漏
		string strNetDevice = field.GeneralOperateSet.getValue();	
		/*
		* ID : 监控对象 : 监控对象类型 : SysNetSubAreaID : 分类ID : 人为划分的职能区域 : IP地址 : IP码 : 设备名称 :
		* PORTNUMBER : CONFIGFILE : 共同体名 : snmp版本 : ramsize(B) : falshsize(B) : nvramsize(B) : 所属机柜 : 
		* ROOM_ID : 软件版本 : 系统描述 : 登录用户名 : 登录密码 : enable密码 : 厂商类型 : 配置备份协议 : 设备型号 :
		* 是否短信告警 : 是否自动snmp探测 : 槽位数 : 是否自动ping : 端口数量 : 巡检分区
		* 示例：
		* 3*:*PuDian.WG.PD-WG3750-C4-4N101*:*21*:*5*:*2*:*access*:*172.1.0.4*:*5*:*PD-WG3750-C4-4N101*:*
		* 0*:**:*thbczh2005*:*0*:*0*:*0*:*0*:*0*:*0*:* 0*:*Cisco IOS Software, C3750 Software ... by prod_rel_team*:* 
		* healthcheck2*:*6hXSmEWasFsfDf+qPNHzrA==@#$*:*6hXSmEWasFsfDf+qPNHzrA==@#$*:*1*:*0*:*3750*:*0*:*0*:*0*:*0*:*58*:*0
		*/

		// 需要获取每个设备的ObjectID，NetSubAreaID，IP Address
		char szObjectID[128] = {0}, szIpAddress[32] = {0};
		int nNetSubAreaID;
		sscanf(strNetDevice.c_str(), "%*d*:*%[^*]*:*%*d*:*%d*:*%*d*:*%*[^*]*:*%[^*]*:*%*s",
			szObjectID, &nNetSubAreaID, szIpAddress);

		// 更新本地的设备信息
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

			// 增加ObjectID和Device之间的MAP
			m_ObjectIDtoDeviceMAP[szObjectID] = thisDevice;

			// 对于增加的设备，还需要更新所有的订阅信息
			// 遍历所有订阅，若该设备处于该订阅的范围之内，则向该订阅添加该设备
			m_SubLock.Lock();printf("SubLock UpdateNetArea\n");
			for (vector<CPerformanceSubscription* >::iterator iterSub = m_Subscriptions.begin();
				iterSub != m_Subscriptions.end();
				++iterSub)
			{
				if (isDeviceInSubscription(thisDevice, *iterSub))
				{
					// 该设备属于该订阅的范围之内
					(*iterSub)->m_ContainedDevices.push_back(thisDevice);
				}
			}
			m_SubLock.UnLock();printf("SubUnLock UpdateNetArea\n");
		}

	}
	else
		return;
}

// 增加一个实时性能分析订阅
// QryField: 请求的内容
// nSessionID: 请求的SessionID
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
		// 找到同样的订阅信息，则只需要添加订阅会话
		if (tmp->CompareSubscription(QryField))
		{
			tmp->AddSubscriptionSession(pSession->GetSessionID());
			pSub = tmp;
		}
	}
	m_SubLock.UnLock();printf("SubUnLock AddSubscription\n");

	// 如果订阅不存在，则添加信息
	if (pSub == NULL)
	{
		// 添加订阅包括了生成具体的订阅对象
		pSub = new CPerformanceSubscription();
		CopySysPerformanceTopEntity(&(pSub->m_Field), &QryField);
		pSub->AddSubscriptionSession(pSession->GetSessionID());

		// 遍历所有设备，判断哪些设备属于该订阅
		// 更新订阅矩阵
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

		// 如果该订阅中没有包含任何设备，则返回错误信息
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

// 删除一个订阅
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

// 查看某设备是否属于某订阅的范围之内
// nDevice：设备ID；nSubID：订阅ID
bool CPerformanceAnalyzer::isDeviceInSubscription( 
	DeviceAttrInfo* pDevice, 
	CPerformanceSubscription* pSub )
{
	// 该设备从属的子网
	int nDeviceNetSubAreaID = pDevice->m_SubAreaID;
	map<int, pair<int, string> >::iterator iterNetArea = m_NetAreaConfig.find(nDeviceNetSubAreaID);
	if (iterNetArea == m_NetAreaConfig.end())
	{
		printf("@@@ Performance Analyze Error! Cann't find NetSubAreaID[%d]\n", nDeviceNetSubAreaID);
		return false;
	}
	else
	{
		// 设备从属的网络ID和子网EName
		int nDeviceNetID = iterNetArea->second.first;
		string strNetSubAreaEName = iterNetArea->second.second;
		// 设备的ObjectID
		string strDeviceObjectID = pDevice->m_ObjectID;

		// 订阅限制的网络ID和子网EName
		int nSubNetID = pSub->m_Field.NetArea.getValue();
		string strSubNetSubAreaEName = pSub->m_Field.NetSubArea.getValue();
		// 订阅的请求KeyWord
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

// 处理指标信息的通告报文
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

// 将某订阅的结果通过Rtn报文通告客户端
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

	// 用于保存排序结果
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
		
		if (strSortResult.size() + strlen(szBuff) >= 256)	// result字段最长256
		{
			rtnField.TopResult = strSortResult.c_str();
			FTDC_ADD_FIELD(&m_pkgSend, &rtnField);

			memset(&rtnField, 0, sizeof(CFTDRtnPerformanceTopField));
			CopySysPerformanceTopEntity(&rtnField, &(pSub->m_Field));
			strSortResult.clear();

			if (m_pkgSend.Length() + sizeof(CFTDRtnPerformanceTopField) > FTDC_PACKAGE_MAX_SIZE)
			{
				m_pkgSend.SetChain(FTDC_CHAIN_CONTINUE);

				// 向订阅的每个客户端发送rtn
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
	// 向订阅的每个客户端发送rtn
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
	//  遍历每个订阅信息，计算该订阅的最新排序值
	m_SubLock.Lock();printf("SubLock UpdateSubscriptionResult\n");
	for (vector<CPerformanceSubscription* >::iterator iterSub = m_Subscriptions.begin();
		iterSub != m_Subscriptions.end();
		++iterSub)
	{
		CPerformanceSubscription* pSub = (*iterSub);
		const char* szAttrType = pSub->GetAttrType();
		vector<DeviceAttrInfo* > &SubDeviceList = pSub->m_ContainedDevices;

		// 遍历该订阅所覆盖的所有设备的设备ID
		for (vector<DeviceAttrInfo* >::iterator iterDevice = SubDeviceList.begin();
			iterDevice != SubDeviceList.end();
			++iterDevice)
		{
			DeviceAttrInfo* pDevice = (*iterDevice);
			// 更新设备对于该指标的数据
			pDevice->updateAttrValue(szAttrType);

			float _fAttrValue = 0.0;
			bool _bGetRes = false;
			// 根据订阅值的类型，获取对应的数据
			switch (pSub->GetSortValueType())
			{
			case 0:	// 平均值
				_bGetRes = pDevice->GetAvg(szAttrType, _fAttrValue);
				break;
			case 1:	// 最小值
				_bGetRes = pDevice->GetMin(szAttrType, _fAttrValue);
				break;
			case 2:	// 最大值
				_bGetRes = pDevice->GetMax(szAttrType, _fAttrValue);
				break;
			default:
				// 如果订阅的值类型错误，则说明该订阅无效，删除
				printf("@@@ Performance Analyze Error! Subscription SortValueType Error! [%d]\n",
					pSub->GetSortValueType());
				break;
			}

			// 如果获取到无效值，则从结果队列中删除该设备
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

		// 将该订阅的最新排序结果通知给客户端
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
