/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	systools.cpp
///@brief	实现了交易监控系统共用的类和函数
///@history
///20080514	周建军		创建该文件
///20080623	周建军		修订注释
///20090219	晏鹤春		XMLInit方法中构造对象关系时加入业务系统级信息
/////////////////////////////////////////////////////////////////////////
#include "systools.h"

static int	crctab[256] =
{
	0x00000000,
	0x77073096,
	0xee0e612c,
	0x990951ba,
	0x076dc419,
	0x706af48f,
	0xe963a535,
	0x9e6495a3,
	0x0edb8832,
	0x79dcb8a4,
	0xe0d5e91e,
	0x97d2d988,
	0x09b64c2b,
	0x7eb17cbd,
	0xe7b82d07,
	0x90bf1d91,
	0x1db71064,
	0x6ab020f2,
	0xf3b97148,
	0x84be41de,
	0x1adad47d,
	0x6ddde4eb,
	0xf4d4b551,
	0x83d385c7,
	0x136c9856,
	0x646ba8c0,
	0xfd62f97a,
	0x8a65c9ec,
	0x14015c4f,
	0x63066cd9,
	0xfa0f3d63,
	0x8d080df5,
	0x3b6e20c8,
	0x4c69105e,
	0xd56041e4,
	0xa2677172,
	0x3c03e4d1,
	0x4b04d447,
	0xd20d85fd,
	0xa50ab56b,
	0x35b5a8fa,
	0x42b2986c,
	0xdbbbc9d6,
	0xacbcf940,
	0x32d86ce3,
	0x45df5c75,
	0xdcd60dcf,
	0xabd13d59,
	0x26d930ac,
	0x51de003a,
	0xc8d75180,
	0xbfd06116,
	0x21b4f4b5,
	0x56b3c423,
	0xcfba9599,
	0xb8bda50f,
	0x2802b89e,
	0x5f058808,
	0xc60cd9b2,
	0xb10be924,
	0x2f6f7c87,
	0x58684c11,
	0xc1611dab,
	0xb6662d3d,
	0x76dc4190,
	0x01db7106,
	0x98d220bc,
	0xefd5102a,
	0x71b18589,
	0x06b6b51f,
	0x9fbfe4a5,
	0xe8b8d433,
	0x7807c9a2,
	0x0f00f934,
	0x9609a88e,
	0xe10e9818,
	0x7f6a0dbb,
	0x086d3d2d,
	0x91646c97,
	0xe6635c01,
	0x6b6b51f4,
	0x1c6c6162,
	0x856530d8,
	0xf262004e,
	0x6c0695ed,
	0x1b01a57b,
	0x8208f4c1,
	0xf50fc457,
	0x65b0d9c6,
	0x12b7e950,
	0x8bbeb8ea,
	0xfcb9887c,
	0x62dd1ddf,
	0x15da2d49,
	0x8cd37cf3,
	0xfbd44c65,
	0x4db26158,
	0x3ab551ce,
	0xa3bc0074,
	0xd4bb30e2,
	0x4adfa541,
	0x3dd895d7,
	0xa4d1c46d,
	0xd3d6f4fb,
	0x4369e96a,
	0x346ed9fc,
	0xad678846,
	0xda60b8d0,
	0x44042d73,
	0x33031de5,
	0xaa0a4c5f,
	0xdd0d7cc9,
	0x5005713c,
	0x270241aa,
	0xbe0b1010,
	0xc90c2086,
	0x5768b525,
	0x206f85b3,
	0xb966d409,
	0xce61e49f,
	0x5edef90e,
	0x29d9c998,
	0xb0d09822,
	0xc7d7a8b4,
	0x59b33d17,
	0x2eb40d81,
	0xb7bd5c3b,
	0xc0ba6cad,
	0xedb88320,
	0x9abfb3b6,
	0x03b6e20c,
	0x74b1d29a,
	0xead54739,
	0x9dd277af,
	0x04db2615,
	0x73dc1683,
	0xe3630b12,
	0x94643b84,
	0x0d6d6a3e,
	0x7a6a5aa8,
	0xe40ecf0b,
	0x9309ff9d,
	0x0a00ae27,
	0x7d079eb1,
	0xf00f9344,
	0x8708a3d2,
	0x1e01f268,
	0x6906c2fe,
	0xf762575d,
	0x806567cb,
	0x196c3671,
	0x6e6b06e7,
	0xfed41b76,
	0x89d32be0,
	0x10da7a5a,
	0x67dd4acc,
	0xf9b9df6f,
	0x8ebeeff9,
	0x17b7be43,
	0x60b08ed5,
	0xd6d6a3e8,
	0xa1d1937e,
	0x38d8c2c4,
	0x4fdff252,
	0xd1bb67f1,
	0xa6bc5767,
	0x3fb506dd,
	0x48b2364b,
	0xd80d2bda,
	0xaf0a1b4c,
	0x36034af6,
	0x41047a60,
	0xdf60efc3,
	0xa867df55,
	0x316e8eef,
	0x4669be79,
	0xcb61b38c,
	0xbc66831a,
	0x256fd2a0,
	0x5268e236,
	0xcc0c7795,
	0xbb0b4703,
	0x220216b9,
	0x5505262f,
	0xc5ba3bbe,
	0xb2bd0b28,
	0x2bb45a92,
	0x5cb36a04,
	0xc2d7ffa7,
	0xb5d0cf31,
	0x2cd99e8b,
	0x5bdeae1d,
	0x9b64c2b0,
	0xec63f226,
	0x756aa39c,
	0x026d930a,
	0x9c0906a9,
	0xeb0e363f,
	0x72076785,
	0x05005713,
	0x95bf4a82,
	0xe2b87a14,
	0x7bb12bae,
	0x0cb61b38,
	0x92d28e9b,
	0xe5d5be0d,
	0x7cdcefb7,
	0x0bdbdf21,
	0x86d3d2d4,
	0xf1d4e242,
	0x68ddb3f8,
	0x1fda836e,
	0x81be16cd,
	0xf6b9265b,
	0x6fb077e1,
	0x18b74777,
	0x88085ae6,
	0xff0f6a70,
	0x66063bca,
	0x11010b5c,
	0x8f659eff,
	0xf862ae69,
	0x616bffd3,
	0x166ccf45,
	0xa00ae278,
	0xd70dd2ee,
	0x4e048354,
	0x3903b3c2,
	0xa7672661,
	0xd06016f7,
	0x4969474d,
	0x3e6e77db,
	0xaed16a4a,
	0xd9d65adc,
	0x40df0b66,
	0x37d83bf0,
	0xa9bcae53,
	0xdebb9ec5,
	0x47b2cf7f,
	0x30b5ffe9,
	0xbdbdf21c,
	0xcabac28a,
	0x53b39330,
	0x24b4a3a6,
	0xbad03605,
	0xcdd70693,
	0x54de5729,
	0x23d967bf,
	0xb3667a2e,
	0xc4614ab8,
	0x5d681b02,
	0x2a6f2b94,
	0xb40bbe37,
	0xc30c8ea1,
	0x5a05df1b,
	0x2d02ef8d
};

static int g_FrontAllocateID = 0;
unsigned int cal_crc(char *ptr, int len)
{
	unsigned int crc = 0;

	unsigned int stlen = (unsigned int)len;
	unsigned char da;
	unsigned char *p = (unsigned char *)ptr;

	while (stlen-- != 0)
	{
		da = (unsigned char)(crc / 256);	/* 以8位二进制数的形式暂存CRC的高8位 */
		crc <<= 8;					/* 左移8位，相当于CRC的低8位乘以  */
		crc ^= crctab[da ^ *p];		/* 高8位和当前字节相加后再查表求CRC ，再加上以前的CRC */
		p++;
	}

	return (crc);
}

CDataCenterManage::CDataCenterManage(void)
{
}

CDataCenterManage::~CDataCenterManage(void)
{
	map<string, list<string> *>::iterator it;

	for (it = m_mapAppAttr.begin(); it != m_mapAppAttr.end(); it++)
	{
		delete it->second;
	}
}

list<string> *CDataCenterManage::getAttrFromApp(string &appName)
{
	map<string, list<string> *>::iterator it = m_mapAppAttr.find(appName);
	if (it == m_mapAppAttr.end())	//进程名不存在
	{
		return NULL;
	}
	else	//存在进程名,返回list指针
	{
		return it->second;
	}
}

list<string> *CDataCenterManage::getAttrFromAppId(string &appName)
{
	map<string, list<string> *>::iterator it = m_mapAppAttr.find(
			m_mapAppIdType[appName]);
	if (it == m_mapAppAttr.end())	//进程名不存在
	{
		return NULL;
	}
	else	//存在进程名,返回list指针
	{
		return it->second;
	}
}

///getAttrFromAppId用法如下:
#if 0
list<string> *pList;
pList = CDataCenterManage.getAttrFromAppId(string("PuDian.app.tkernel.1"));
if (pList != NULL)
{
	for (list<string>::iterator it = pList->begin(); it != pList->end(); it++)
	{
		printf("getAttrFromAppId %s\n", it->c_str());
	}
}

#endif

///输出函数,打印map中所有进程和属性关系信息
void CDataCenterManage::print(void)
{
	map<string, int>::iterator	typeIt;
	for (typeIt = m_mapAttrType.begin();
		 typeIt != m_mapAttrType.end();
		 typeIt++)
	{
		printf("\t Attr:%s: type %d\n", typeIt->first.c_str(), typeIt->second);
	}

	return;

	map<string, list<string> *>::iterator it;

	for (it = m_mapAppAttr.begin(); it != m_mapAppAttr.end(); it++)
	{
		list<string> *pList = it->second;
		list<string>::iterator	listIt = pList->begin();
		for (listIt = pList->begin(); listIt != pList->end(); listIt++)
		{
			printf("\t APP:%s ATTR:%s \n", it->first.c_str(), listIt->c_str());
		}
	}
}

void CDataCenterManage::addAppIdType(string &appId, string &appType)
{
	map<string, string>::iterator it;
	it = m_mapAppIdType.find(appId);
	if (it != m_mapAppIdType.end())
	{
		m_mapAppIdType[appId] = appType;
	}
	else
	{
		m_mapAppIdType[appId] = appType;
	}
}

void CDataCenterManage::addAppIdType(char *appId, char *appType)
{
	map<string, string>::iterator it;
	it = m_mapAppIdType.find(string(appId));
	if (it != m_mapAppIdType.end())
	{
		m_mapAppIdType[string(appId)] = string(appType);
	}
	else
	{
		m_mapAppIdType[string(appId)] = string(appType);
	}
}

void CDataCenterManage::addAppAttr(string &appName, string &attrName)
{
	list<string> *p = NULL;
	map<string, list<string> *>::iterator it;
	it = m_mapAppAttr.find(appName);
	if (it != m_mapAppAttr.end())	// 应用类进程已存在,只需要增加指标
	{
		it->second->push_back(attrName);
	}
	else
	{
		p = new list<string>;
		p->push_back(attrName);
		m_mapAppAttr.insert(pair < string, list<string> * > (appName, p));
	}
}

void CDataCenterManage::addAppAttr(char *appName, char *attrName)
{
	list<string> *p = NULL;
	map<string, list<string> *>::iterator it;
	it = m_mapAppAttr.find(string(appName));
	if (it != m_mapAppAttr.end())	// 应用类进程已存在,只需要增加指标
	{
		it->second->push_back(string(attrName));
	}
	else
	{
		p = new list<string>;
		p->push_back(string(attrName));
		m_mapAppAttr.insert(
				pair < string,
				list<string> * > (string(appName), p));
	}
}

// Added by Henchi
void CDataCenterManage::addAppIdHost(string &appId, string &Host)
{
	map<string, string>::iterator it;
	it = m_mapAppIdHost.find(appId);
	if (it != m_mapAppIdHost.end())
	{
		m_mapAppIdHost[appId] = Host;
	}
	else
	{
		m_mapAppIdHost[appId] = Host;
	}
}

void CDataCenterManage::addAppIdHost(char *appId, char *Host)
{
	map<string, string>::iterator it;
	it = m_mapAppIdHost.find(string(appId));
	if (it != m_mapAppIdHost.end())
	{
		m_mapAppIdHost[string(appId)] = string(Host);
	}
	else
	{
		m_mapAppIdHost[string(appId)] = string(Host);
	}
}

void CDataCenterManage::addAppIdName(string &appId, string &appName)
{
	map<string, CObjectIdStatus>::iterator	it;
	it = m_mapAppIdName.find(appId);
	if (it == m_mapAppIdName.end())
	{
		m_mapAppIdName[appId] = CObjectIdStatus(appId, appName);
	}
	else
	{
		m_mapAppIdName[appId].m_sObjectName = appName;
	}
}

void CDataCenterManage::updateCurAppIDStatus(
	string	&appId,
	string	&appName,
	int status)
{
	map<string, CObjectIdStatus>::iterator	it;
	it = m_mapAppIdName.find(appId);
	if (it == m_mapAppIdName.end())
	{
		m_mapAppIdName[appId] = CObjectIdStatus(appId, appName);
		it = m_mapAppIdName.find(appId);
	}

	it->second.m_sObjectName = appName;
	it->second.m_iEventFlag = status;
}

void CDataCenterManage::addAppIdName(char *appId, char *appName)
{
	map<string, CObjectIdStatus>::iterator	it;
	it = m_mapAppIdName.find(string(appId));
	if (it == m_mapAppIdName.end())
	{
		m_mapAppIdName[string(appId)] = CObjectIdStatus(appId, appName);
	}
	else
	{
		m_mapAppIdName[string(appId)].m_sObjectName = string(appName);
	}
}

void CDataCenterManage::addObjectIDAddress(char *objId, char *addr)
{
	if (m_mapObjectIDAddress.find(string(objId)) == m_mapObjectIDAddress.end())
	{
		printf("Add Object-IPAddress [%s] [%s]\n", objId, addr);
		m_mapObjectIDAddress[string(objId)] = string(addr);
	}
}

string CDataCenterManage::getAddressByObjectID(char *objId)
{
	return m_mapObjectIDAddress.find(string(objId)) == m_mapObjectIDAddress.end() ? "" : m_mapObjectIDAddress[string(objId)];
}

void CDataCenterManage::UpDateObjectIdStatus(char *appId, int status)
{
	/// Mod by Henchi, 20120523
		/// 配合客户端“取消告警事件”功能变更，对象节点仅存在3种事件状态：
		/// EVENT_FLAG_GREEN (0) 表示由其往下所有节点均正常告警;
		/// EVENT_FLAG_RED   (2) 表示由其往下所有节点均关闭告警;
		/// EVENT_FLAG_GRAY  (3) 表示其下部分节点关闭告警,部分正常告警;
		
		/// 收到的status仅两种状态：0 表示恢复告警；1 表示取消告警
		/// 某节点恢复告警，由其往下所有结点标识为0 (EVENT_FLAG_GREEN)
		/// 某节点取消告警，由其往下所有结点标识为2 (EVENT_FLAG_RED)
	//int iMyStatus  = status == EVENT_FLAG_GREEN ? EVENT_FLAG_GREEN : EVENT_FLAG_BLUE;
	int iMyStatus = status == EVENT_FLAG_GREEN ? EVENT_FLAG_GREEN :
		EVENT_FLAG_RED;
	int iSonStatus = status == EVENT_FLAG_GREEN ? EVENT_FLAG_GREEN :
		EVENT_FLAG_RED;

	map<string, CObjectIdStatus>::iterator	it;
	it = m_mapAppIdName.find(string(appId));

	if (it != m_mapAppIdName.end())
	{
		if (it->second.m_iEventFlag == iMyStatus)
		{
			/// No change, still do task
			printf(
				"--- Warning: ObjectID[%s] warning status [%d] have no change\n",
				appId,
				iMyStatus);

			// return;
		}

		/// 更新本节点状态		
		it->second.m_iEventFlag = iMyStatus;
		printf(
			"--- Notice: ObjectID[%s] set warning status [%d]\n",
			appId,
			iMyStatus);

		/// 更新子节点状态		
		char szAppId[256] = "";
		sprintf(szAppId, "%s.", appId);
		for (it++; it != m_mapAppIdName.end(); it++)
		{
			if (strncmp(
					szAppId,
				it->second.m_sObjectId.c_str(),
				strlen(szAppId)) == 0)
			{
				//仍为子节点,继续遍历以变更子对象状态
				it->second.m_iEventFlag = iSonStatus;
				printf(
					"--- Notice: ObjectID[%s] set warning status [%d]\n",
					it->second.m_sObjectId.c_str(),
					iSonStatus);
			}
			else
			{
				//已非子节点,结束遍历
				break;
			}
		}

		/// 更新父节点状态
		string	strObject = appId;
		while ((strObject = GetParentObjectId((char *)strObject.c_str())) != "")
		{
			ReFreshObjectIdStatus((char *)strObject.c_str());
		}
	}
	else if (strcmp(appId, "RootSystem") == 0
		 ||	 strcmp(appId, "SYSTEM") == 0
		 ||	 strcmp(appId, "ROOT") == 0)
	{
		/// 所有节点对象统一变更告警状态
		printf(
			"--- Notice: ObjectID[%s] set warning status [%d]\n",
			appId,
			iMyStatus);
		for (it = m_mapAppIdName.begin(); it != m_mapAppIdName.end(); it++)
		{
			/// 更新节点状态		
			it->second.m_iEventFlag = iMyStatus;
			printf(
				"--- Notice: ObjectID[%s] set warning status [%d]\n",
				it->second.m_sObjectId.c_str(),
				iMyStatus);
		}
	}
	else
	{
		printf(
			"--- Error: Receive unknow ObjectID[%s] in Func [%s]\n",
			appId,
			__FUNCTION__);
	}
}

string CDataCenterManage::GetParentObjectId(char *appId)
{
	char *p = strrchr(appId, '.');
	if (p == NULL)
	{
		printf("--- Notice: ObjectID[%s] ParentID[]\n", appId);
		return "";
	}
	else
	{
		string	Parent = string((const char *)appId, (p - appId));
		printf(
			"--- Notice: ObjectID[%s] ParentID[%s]\n",
			appId,
			Parent.c_str());
		return Parent;
	}
}

void CDataCenterManage::ReFreshObjectIdStatus(char *appId)
{
	/// 通过遍历直接子节点的方式来更新本节点事件状态
	if (appId != NULL && strlen(appId) > 0)
	{
		int iGray = 0;
		int iRed = 0;
		int iBlue = 0;
		int iGreen = 0;

		string	strObject = appId;
		string	strChild = strObject + ".";
		map<string, CObjectIdStatus>::iterator	itObj = m_mapAppIdName.find(
				strObject);
		if (itObj == m_mapAppIdName.end())
		{
			return;
		}

		map<string, CObjectIdStatus>::iterator	it = itObj;

		// Mod by Henchi, 20110525
		for (it++; it != m_mapAppIdName.end(); it++)
		{
			if (strncmp(
					strChild.c_str(),
				it->second.m_sObjectId.c_str(),
				strChild.length()) == 0)
			{
				//仍为子节点,继续遍历以变更子对象状态
				if (it->second.m_sObjectId.find(
						'.',
					strChild.length()) == string::npos)
				{
					// 为直接子节点
					if (it->second.m_iEventFlag == EVENT_FLAG_GRAY)
					{
						iGray++;
						break;
					}
					else if (it->second.m_iEventFlag == EVENT_FLAG_RED)
					{
						iRed++;
					}
					else if (it->second.m_iEventFlag == EVENT_FLAG_BLUE)
					{
						iBlue++;
					}
					else if (it->second.m_iEventFlag == EVENT_FLAG_GREEN)
					{
						iGreen++;
					}
				}
			}
			else
			{
				//已非子节点,结束遍历
				break;
			}
		}

		/// Mod by Henchi, 20120523
		//if (iGray > 0 || iBlue > 0)
		if (iGray > 0 || (iGreen > 0 && iRed > 0))
		{
			itObj->second.m_iEventFlag = EVENT_FLAG_GRAY;
			printf(
				"--- Notice: ObjectID[%s] set warning status [%d]\n",
				appId,
				EVENT_FLAG_GRAY);
		}
		else if (iGreen > 0 && iRed == 0)
		{
			itObj->second.m_iEventFlag = EVENT_FLAG_GREEN;
			printf(
				"--- Notice: ObjectID[%s] set warning status [%d]\n",
				appId,
				EVENT_FLAG_GREEN);
		}
		else if (iRed > 0 && iGreen == 0)
		{
			itObj->second.m_iEventFlag = EVENT_FLAG_RED;
			printf(
				"--- Notice: ObjectID[%s] set warning status [%d]\n",
				appId,
				EVENT_FLAG_RED);
		}
		else
		{
			/// iGray == 0 && iRed == 0 && iGreen ==0
			//itObj->second.m_iEventFlag = EVENT_FLAG_GRAY;
			printf(
				"--- Error: ObjectID[%s] have no child, keep warning status [%d]\n",
				appId,
				itObj->second.m_iEventFlag);
		}
	}
}

bool CDataCenterManage::IsObjectEventOff(char *appId)
{
	map<string, CObjectIdStatus>::iterator	it;
	it = m_mapAppIdName.find(string(appId));
	if (it != m_mapAppIdName.end())
	{
		if (it->second.m_iEventFlag != EVENT_FLAG_GREEN
		&&	it->second.m_iEventFlag != EVENT_FLAG_GRAY)
		{
			return true;
		}
	}

	/// 没有找到该对象的话，也认为该对象事件未被关闭
	return false;
}

void CDataCenterManage::UpDateAppIdName(char *appId, char *oldAppId)
{
	map<string, CObjectIdStatus>::iterator	it;
	it = m_mapAppIdName.find(string(oldAppId));
	if (it != m_mapAppIdName.end())
	{
		string	appName;
		char *p = strrchr(appId, '.');
		if (p != NULL)
		{
			p++;
			appName = p;
		}
		else
		{
			appName = it->second.m_sObjectName;
		}

		m_mapAppIdName.erase(it);
		m_mapAppIdName[string(appId)] = CObjectIdStatus(appId, appName);
	}
	else
	{
		it = m_mapAppIdName.find(string(appId));
		if (it != m_mapAppIdName.end())
		{
			return;
		}

		char *p = strrchr(appId, '.');
		p++;
		m_mapAppIdName[string(appId)] = CObjectIdStatus(appId, p);
	}
}

// Added End
bool CDataCenterManage::judgeAttrOfApp(string &appName, string &attrName)
{
	map<string, list<string> *>::iterator it;
	it = m_mapAppAttr.find(appName);
	if (it != m_mapAppAttr.end())
	{
		list<string> *pList = it->second;
		list<string>::iterator	listIt = pList->begin();
		for (listIt = pList->begin(); listIt != pList->end(); listIt++)
		{
			if (*listIt == attrName)
			{
				return true;
			}
		}

		return false;
	}

	return false;
}

bool CDataCenterManage::getAppIdFromAttr(
	list<string> &appList,
	string	&attrName)
{
	map<string, string>::iterator it;
	for (it = m_mapAppIdType.begin(); it != m_mapAppIdType.end(); it++)
	{
		if (judgeAttrOfApp(it->second, attrName))
		{
			appList.push_back(it->first);
		}
	}

	return true;
}

int CDataCenterManage::getAttrType(char *pAttr)
{
	map<string, int>::iterator	it;
	it = m_mapAttrType.find(string(pAttr));
	if (it != m_mapAttrType.end())
	{
		return it->second;
	}

	return -1;
}

int CDataCenterManage::getAttrInterval(const char *pAttr)
{
	map<string, int>::iterator	it;
	it = m_mapAttrInterval.find(string(pAttr));
	if (it != m_mapAttrInterval.end())
	{
		return it->second;
	}

	return -1;
}

int CDataCenterManage::getAttrType(const char *pAttr, const char *pValue)
{
	map<string, int>::iterator	it;
	it = m_mapAttrType.find(string(pAttr));
	if (it != m_mapAttrType.end())
	{
		return it->second;
	}

	///增加根据pvalue判断值类型字段
	char *p = (char *)pValue;
	if (*p == '\0')
	{
		return -1;
	}

	while (*p != '\0')
	{
		if ((*p >= '0' && *p <= '9') || (*p == '.') || (*p == '-'))
		{
			p++;
		}
		else
		{
			m_mapAttrType[pAttr] = STRING_ATTR;
			return STRING_ATTR;
		}
	}

	m_mapAttrType[pAttr] = FLOAT_ATTR;
	return FLOAT_ATTR;
}

void CDataCenterManage::UpdateAppAttr(char *newHostName, char *oldHostName)
{
	char szOldKeyfile[64];

	char szNewKeyfile[64];

	char szOldSyslog[64];

	char szNewSyslog[64];

	if (!newHostName || !oldHostName)
	{
		return;
	}

	sprintf(szOldKeyfile, "%s.%s", oldHostName, HOSTATTRKEYFILE);
	sprintf(szNewKeyfile, "%s.%s", newHostName, HOSTATTRKEYFILE);
	sprintf(szOldSyslog, "%s.%s", oldHostName, HOSTATTRSYSLOG);
	sprintf(szNewSyslog, "%s.%s", newHostName, HOSTATTRSYSLOG);

	map<string, list<string> *>::iterator it;
	it = m_mapAppAttr.find(szOldKeyfile);
	if (it != m_mapAppAttr.end())
	{
		m_mapAppAttr[szNewKeyfile] = m_mapAppAttr[szOldKeyfile];
		addAppIdType(szNewKeyfile, szNewKeyfile);
	}

	it = m_mapAppAttr.find(szOldSyslog);
	if (it != m_mapAppAttr.end())
	{
		m_mapAppAttr[szNewSyslog] = m_mapAppAttr[szOldSyslog];
		addAppIdType(szNewSyslog, szNewSyslog);
	}
}

void CDataCenterManage::XMLInit(char *pszCfgPath)
{
	///Modify by Henchi 20090219 , 对象ID中加入业务系统级信息，如NGES.
	char szHostName[MAXOBJECTNAMELEN] = "";				// 主机名，如：AC-01
	char szHostId[MAXOBJECTNAMELEN] = "";				// 主机标识，如：NGES.PuDian.os.AC-01
	char szSystem[MAXOBJECTNAMELEN] = "";				// 系统对象名，如：NGES
	char szSysDataCenter[MAXOBJECTNAMELEN] = "";		// 系统数据中心对象名，如：NGES.PuDian
	char szDataCenter[MAXOBJECTNAMELEN] = "";			// 数据中心名，如：PuDian
	char szObjectId[MAXOBJECTNAMELEN] = "";				// 对象标识，如：NGES.PuDian.app.tkernel.1
	char szAppName[MAXOBJECTNAMELEN] = "";				// 应用类型名，如：tkernel
	char szAppId[MAXOBJECTNAMELEN] = "";				// 应用类型标识，如：app.tkernel
	char szTmp[MAXOBJECTNAMELEN] = "";
	char *pszTemp = NULL;
	char *p = NULL;

	CXMLConfig	*pXMLCfg = new CXMLConfig(pszCfgPath);
	if (pXMLCfg)
	{
		map<string, int> attrtypeMap;
		if (pXMLCfg->GetAttrTypeMap(attrtypeMap))
		{
			map<string, int>::iterator	mapIt;
			for (mapIt = attrtypeMap.begin();
				 mapIt != attrtypeMap.end();
				 mapIt++)
			{
				m_mapAttrType[mapIt->first] = mapIt->second;
#ifdef PRINT_DEBUG
				printf(
					"    %-12s --- %d\n",
					mapIt->first.c_str(),
					mapIt->second);
#endif
			}
		}

		if (pXMLCfg->GetAttrIntervalMap(m_mapAttrInterval))
		{
#ifdef PRINT_DEBUG
			map<string, int>::iterator	mapIt;
			for (mapIt = m_mapAttrInterval.begin();
				 mapIt != m_mapAttrInterval.end();
				 mapIt++)
			{
				printf(
					"Attr:%-12s   Interval:%d\n",
					mapIt->first.c_str(),
					mapIt->second);
			}

#endif
		}

		map<string, list<string> >	attrappMap;
		if (pXMLCfg->GetAttrAppMap(attrappMap))
		{
			map<string, list<string> >::iterator mapIt;
			for (mapIt = attrappMap.begin(); mapIt != attrappMap.end(); mapIt++)
			{
				list<string>::iterator	listIt;
				for (listIt = (mapIt->second).begin();
					 listIt != (mapIt->second).end();
					 listIt++)
				{
					addAppAttr(
						(char *)((*listIt).c_str()),
						(char *)((mapIt->first).c_str()));
#ifdef PRINT_DEBUG
					printf(
						"    %-12s --- %s\n",
						(*listIt).c_str(),
						mapIt->first.c_str());
#endif
				}
			}
		}
		
		// 加载数据库对象信息
		list<CDBConnectString>	listDBConnectInfo;
		if (pXMLCfg->GetDBConnectStringList(listDBConnectInfo))
		{
			for (
				list<CDBConnectString>::iterator listIt = listDBConnectInfo.begin();
				listIt != listDBConnectInfo.end();
				listIt++)
			{
				if 
				(
					(strlen(listIt->m_sSystemName.c_str()) == 0)
					||
					(strlen(listIt->m_sCenterName.c_str()) == 0)
					||
					(
						strlen(listIt->m_sSystemName.c_str()) +
						strlen(listIt->m_sCenterName.c_str()) +
						strlen(DATACENTERDB) +
						strlen(listIt->m_sRacServiceName.c_str())
						>= MAXOBJECTNAMELEN - 1
					)
				)
				{
					// Invalid objectid
					continue;
				}
	
				sprintf(
					szObjectId,
					"%s.%s.%s",
					listIt->m_sSystemName.c_str(),
					listIt->m_sCenterName.c_str(),
					DATACENTERDB);
				addAppIdName(szObjectId, DATACENTERDB);

				strcpy(szTmp, listIt->m_sRacServiceName.c_str());	// DB name
				sprintf(
					szObjectId,
					"%s.%s.%s.%s",
					listIt->m_sSystemName.c_str(),
					listIt->m_sCenterName.c_str(),
					DATACENTERDB,
					szTmp);
				addAppIdName(szObjectId, szTmp);

				sprintf(
					szTmp,
					"%s.%s",
					DATACENTERAPP,
					DATACENTERDB);	// app.db
				addAppIdType(szObjectId, szTmp);
	
				// 增加数据库ID与IP地址的映射，例：DATABASE.PuDian.db.TBDB
				addObjectIDAddress(
					szObjectId,
					(char *)listIt->m_sIpAddr.c_str());
		
				strcpy(szTmp, listIt->m_sServiceName.c_str());	// Node name
				sprintf(szObjectId, "%s.%s", szObjectId, szTmp);

				// 增加数据库节点ID与IP地址的映射，例：DATABASE.PuDian.db.TBDB.TBDB1
				addObjectIDAddress(
					szObjectId,
					(char *)listIt->m_sIpAddr.c_str());

				// 当节点不需要显示于TreeView时，不添加节点级信息
				if (strcmp(
						listIt->m_sTreeViewFlag.c_str(),
					"false") == 0)
				{
					continue;
				}

				addAppIdName(szObjectId, szTmp);
				sprintf(
					szTmp,
					"%s.%s",
					DATACENTERAPP,
					DATACENTERDBNODE);	// app.dbnode
				addAppIdType(szObjectId, szTmp);
	
			}
		}


		list<CXMLConfig::CProbeConfig *> probeList;
		if (pXMLCfg->GetProbeConfigList(probeList))
		{
			list<CXMLConfig::CProbeConfig *>::iterator	listIt;
			for (listIt = probeList.begin();
				 listIt != probeList.end();
				 listIt++)
			{
				CXMLConfig::CProbeConfig * pProbeCfg = (*listIt);
				if (pProbeCfg)
				{
					pszTemp = pProbeCfg->GetHostName(); // 获取主机名
					if (!pszTemp || !strlen(pszTemp))
					{
						continue;
					}
					else
					{
						strcpy(szHostName, pszTemp);
					}

					pszTemp = pProbeCfg->GetSystem();	// 获取主机所在系统名
					if (!pszTemp || !strlen(pszTemp))
					{
						continue;
					}
					else
					{
						strcpy(szSystem, pszTemp);
					}

					pszTemp = pProbeCfg->GetSystemAlias();					// 获取主机所在系统中文名
					if (strlen(pszTemp) > 0)
					{
						sprintf(szTmp, "%s_[%s]", szSystem, pszTemp);
						addAppIdName(szSystem, szTmp);
					}

					pszTemp = pProbeCfg->GetDataCenter();					// 获取主机所在数据中心名
					if (!pszTemp || !strlen(pszTemp))
					{
						continue;
					}
					else
					{
						strcpy(szDataCenter, pszTemp);
					}

					sprintf(szSysDataCenter, "%s.%s", szSystem, szDataCenter);
					addAppIdName(szSysDataCenter, szDataCenter);

					sprintf(
						szObjectId,
						"%s.%s.%s",
						szSystem,
						szDataCenter,
						DATACENTERHOST);
					addAppIdName(szObjectId, DATACENTERHOST);

					sprintf(
						szObjectId,
						"%s.%s.%s",
						szSystem,
						szDataCenter,
						DATACENTERAPP);
					addAppIdName(szObjectId, DATACENTERAPP);

					pszTemp = pProbeCfg->GetTreeViewFlag();					// 获取主机TreeView显示标识
					if (!pszTemp || strcmp(pszTemp, "false") != 0)
					{
						// 建立该主机的TreeView标签项, Modified by Henchi, 20091228
						sprintf(
							szHostId,
							"%s.%s.%s.%s",
							szSystem,
							szDataCenter,
							DATACENTERHOST,
							szHostName);
						/// Mod by Henchi, 20130507
						///pszTemp = pProbeCfg->GetHostAlias();				// 获取主机别名
						pszTemp = pProbeCfg->GetAddress();					// 获取主机IP地址
						if (strlen(pszTemp) > 0)
						{
							sprintf(szTmp, "%s(%s)", szHostName, pszTemp);
							addAppIdName(szHostId, szTmp);
						}
						else
						{
							addAppIdName(szHostId, szHostName);
						}

						// 增加主机ID与IP地址的映射
						addObjectIDAddress(szHostId, pProbeCfg->GetAddress());

						m_mapHostDataCenter[szHostName] = szSysDataCenter;	// 建立主机名与数据中心名映射关系
#ifdef PRINT_DEBUG
						printf(
							"运行文件 ： %s 行数：%d \n",
							__FILE__,
							__LINE__);
						printf(
							"HostName:%s\tSysDataCenter:%s\n",
							szHostName,
							szSysDataCenter);
#endif

						// Mod by Henchi, 20091027
						// 当主机配置项为TreeView="false"时，其下的业务进程配置项也不在TreeView中生效，用于隐藏JProbe的进程配置项
						map<string, string> &AppPathMap = pProbeCfg->
							GetAppPathMap();			// 获取业务应用及其所在分区映射图
						map<string, string>::iterator appMapIt;
						if (AppPathMap.size())
						{
							for (appMapIt = AppPathMap.begin();
								 appMapIt != AppPathMap.end();
								 appMapIt++)
							{
								if ((
										strlen(szSystem) +
									strlen(szDataCenter) +
									strlen(DATACENTERAPP) +
									strlen(appMapIt->first.c_str())
								) >= MAXOBJECTNAMELEN - 1)
								{
									continue;
								}

								if (strcmp(
										appMapIt->first.c_str(),
									"console") == 0)
								{
									sprintf(
										szObjectId,
										"%s.%s.%s",
										szSystem,
										szDataCenter,
										APP_CONSOLE);	// TRADE.PuDian.app.console
									addAppIdName(szObjectId, "控制台");
									addAppIdType(szObjectId, APP_CONSOLE);		// app.console
								}
								else
								{
									strcpy(szTmp, appMapIt->first.c_str());
									strcpy(szAppName, strtok(szTmp, "."));
									p = strtok(NULL, ".");

									if (p)
									{
										sprintf(
											szObjectId,
											"%s.%s.%s.%s",
											szSystem,
											szDataCenter,
											DATACENTERAPP,
											szAppName);
										addAppIdName(szObjectId, szAppName);
										
										/// Mod by Henchi, 20130507
										/// 避免对象ASCII排序不对齐现象
										//sprintf(szTmp, "%s%s", szTmp, p);
										sprintf(szTmp, "%s%02d", szTmp, atoi(p));
									}

									sprintf(
										szObjectId,
										"%s.%s.%s.%s",
										szSystem,
										szDataCenter,
										DATACENTERAPP,
										appMapIt->first.c_str());
									addAppIdName(szObjectId, szTmp);

									sprintf(
										szObjectId,
										"%s.%s.%s.%s",
										szSystem,
										szDataCenter,
										DATACENTERAPP,
										appMapIt->first.c_str());
									sprintf(
										szAppId,
										"%s.%s",
										DATACENTERAPP,
										szAppName);
									addAppIdType(szObjectId, szAppId);
									if (strcmp(szAppId,"app.front")==0)
									{
										//m_mapFrontAllocateID.insert(make_pair(++g_FrontAllocateID, szObjectId));
										addFrontUniqueID(szObjectId);
									}
									addAppIdHost(szObjectId, szHostId);
								}

								// 增加应用ID与IP地址的映射
								addObjectIDAddress(
									szObjectId,
									pProbeCfg->GetAddress());
							}
						}
					}

					map<string, CDBConnectString> &TomcatMap = pProbeCfg->
						GetTomcatMap();
					map<string, CDBConnectString>::iterator tomcatMapIt;
					if (TomcatMap.size())
					{
						sprintf(
							szObjectId,
							"%s.%s.%s",
							szSystem,
							szDataCenter,
							DATACENTERTOMCAT);
						addAppIdName(szObjectId, DATACENTERTOMCAT);

						for (tomcatMapIt = TomcatMap.begin();
							 tomcatMapIt != TomcatMap.end();
							 tomcatMapIt++)
						{
							if ((
									strlen(szSystem) +
								strlen(szDataCenter) +
								strlen(DATACENTERTOMCAT) +
								strlen(tomcatMapIt->first.c_str())
							) >= MAXOBJECTNAMELEN - 1)
							{
								continue;
							}

							strcpy(szTmp, tomcatMapIt->first.c_str());

							// Modify by Henchi, 20090828
							// TreeView 中的对象ID应以实际配置项为准
							sprintf(
								szObjectId,
								"%s.%s.%s.%s",
								tomcatMapIt->second.m_sUserName.c_str(),
								tomcatMapIt->second.m_sPassword.c_str(),
								DATACENTERTOMCAT,
								szTmp);
							addAppIdName(szObjectId, szTmp);

							// 增加应用ID与IP地址的映射
							addObjectIDAddress(
								szObjectId,
								pProbeCfg->GetAddress());

							sprintf(
								szObjectId,
								"%s.%s.%s.%s.%s",
								tomcatMapIt->second.m_sUserName.c_str(),
								tomcatMapIt->second.m_sPassword.c_str(),
								DATACENTERTOMCAT,
								szTmp,
								TOMCATATTROVERVIEW);

							//addAppIdName(szObjectId, TOMCATATTROVERVIEW);
							addAppIdType(szObjectId, "app.tomcat");
						}
					}

					map<string, CDBConnectString> &ApacheMap = pProbeCfg->
						GetAccessLogMap();
					map<string, CDBConnectString>::iterator ApacheMapIt;
					if (ApacheMap.size())
					{
						sprintf(
							szObjectId,
							"%s.%s.%s",
							szSystem,
							szDataCenter,
							DATACENTERAPACHE);
						addAppIdName(szObjectId, DATACENTERAPACHE);

						for (ApacheMapIt = ApacheMap.begin();
							 ApacheMapIt != ApacheMap.end();
							 ApacheMapIt++)
						{
							if ((
									strlen(szSystem) +
								strlen(szDataCenter) +
								strlen(DATACENTERAPACHE) +
								strlen(ApacheMapIt->first.c_str())
							) >= MAXOBJECTNAMELEN - 1)
							{
								continue;
							}

							sprintf(
								szObjectId,
								"%s.%s.%s.%s",
								szSystem,
								szDataCenter,
								DATACENTERAPACHE,
								ApacheMapIt->first.c_str());
							addAppIdName(
								(char *)szObjectId,
								(char *)ApacheMapIt->first.c_str());

							// 增加应用ID与IP地址的映射
							addObjectIDAddress(
								szObjectId,
								pProbeCfg->GetAddress());

							//sprintf(szObjectId, "%s.%s", szObjectId, ATTROVERVIEW);
							//addAppIdType(szObjectId, "app.apache");
						}
					}

					map<string, CDBConnectString> &WebsiteCodeMap = pProbeCfg->
						GetWebsiteCodeMap();
					map<string, CDBConnectString>::iterator WebsiteCodeMapIt;
					if (WebsiteCodeMap.size())
					{
						sprintf(
							szObjectId,
							"%s.%s.%s",
							szSystem,
							szDataCenter,
							DATACENTERAPP);
						addAppIdName(szObjectId, DATACENTERAPP);
						for (WebsiteCodeMapIt = WebsiteCodeMap.begin();
							 WebsiteCodeMapIt != WebsiteCodeMap.end();
							 WebsiteCodeMapIt++)
						{
							strcpy(szTmp, WebsiteCodeMapIt->first.c_str());
							strcpy(szAppName, strtok(szTmp, "."));
							p = strtok(NULL, ".");

							if (p)
							{
								sprintf(
									szObjectId,
									"%s.%s.%s.%s",
									szSystem,
									szDataCenter,
									DATACENTERAPP,
									szAppName);
								addAppIdName(szObjectId, szAppName);
								sprintf(szTmp, "%s%s", szTmp, p);
							}

							sprintf(
								szObjectId,
								"%s.%s.%s.%s",
								szSystem,
								szDataCenter,
								DATACENTERAPP,
								WebsiteCodeMapIt->first.c_str());

							addAppIdName(szObjectId, szTmp);
							sprintf(
								szObjectId,
								"%s.%s.%s.%s",
								szSystem,
								szDataCenter,
								DATACENTERAPP,
								WebsiteCodeMapIt->first.c_str());
							sprintf(szAppId, "%s.%s", DATACENTERAPP, szAppName);
							addAppIdType(szObjectId, szAppId);

							addAppIdHost(szObjectId, szHostId);

							// 增加应用ID与IP地址的映射
							addObjectIDAddress(
								szObjectId,
								pProbeCfg->GetAddress());
						}
					}

					if (pProbeCfg->GetAppSPMap().size())
					{
						sprintf(szAppName, "%s%s", szSystem, APP_SUFFIX_SP);	// TRADE_sp
						sprintf(
							szObjectId,
							"%s.%s.%s.%s",
							szSystem,
							szDataCenter,
							DATACENTERAPP,
							szAppName); // TRADE.PuDian.app.TRADE_sp
						addAppIdName(szObjectId, "存储过程");

						sprintf(szAppId, "%s.%s", DATACENTERAPP, szAppName);	// app.TRADE_sp
						addAppIdType(szObjectId, szAppId);

						// 增加应用ID与IP地址的映射
						addObjectIDAddress(szObjectId, pProbeCfg->GetAddress());
					}

					if (pProbeCfg->GetDBLogMap().size())
					{
						sprintf(szAppName, "%s%s", szSystem, APP_SUFFIX_DBLOG); // TRADE_dblog
						sprintf(
							szObjectId,
							"%s.%s.%s.%s",
							szSystem,
							szDataCenter,
							DATACENTERAPP,
							szAppName); // TRADE.PuDian.app.TRADE_dblog
						addAppIdName(szObjectId, "数据库日志");

						sprintf(szAppId, "%s.%s", DATACENTERAPP, szAppName);	// app.TRADE_dblog
						addAppIdType(szObjectId, szAppId);

						// 增加应用ID与IP地址的映射
						addObjectIDAddress(szObjectId, pProbeCfg->GetAddress());
					}

					// Mod by Henchi, 20100330

					if ((
							strlen(szSystem) + strlen(szDataCenter) + strlen(
							DATACENTERHOST) + strlen(szHostName) + strlen(
							HOSTATTRSYSLOG)
				) >= MAXOBJECTNAMELEN - 1)
					{
						continue;
					}
					else
					{
						sprintf(
							szObjectId,
							"%s.%s.%s.%s.%s",
							szSystem,
							szDataCenter,
							DATACENTERHOST,
							szHostName,
							HOSTATTRSYSLOG);
						addAppIdType(szObjectId, szObjectId);
					}

					map<string, string> &SysLogMap = pProbeCfg->GetSysLogMap(); // 获取系统日志文件信息
					map<string, string>::iterator syslogMapIt;
					if (SysLogMap.size())
					{
						for (syslogMapIt = SysLogMap.begin();
							 syslogMapIt != SysLogMap.end();
							 syslogMapIt++)
						{
							addAppAttr(
								szObjectId,
								(char *)(syslogMapIt->first.c_str()));			// 系统日志文件名
#ifdef PRINT_DEBUG
							printf(
								"    %-12s --- %s\n",
								szObjectId,
								syslogMapIt->first.c_str());
#endif
						}
					}

					sprintf(
						szObjectId,
						"%s.%s.%s.%s.%s",
						szSystem,
						szDataCenter,
						DATACENTERHOST,
						szHostName,
						HOSTATTRKEYFILE);
					addAppIdType(szObjectId, szObjectId);

					map<string, string> &KeyFileMap = pProbeCfg->GetKeyFileMap();

					// 获取关键文件信息
					map<string, string>::iterator keyfileMapIt;
					if (KeyFileMap.size())
					{
						for (keyfileMapIt = KeyFileMap.begin();
							 keyfileMapIt != KeyFileMap.end();
							 keyfileMapIt++)
						{
							addAppAttr(
								szObjectId,
								(char *)(keyfileMapIt->first.c_str()));			// 关键文件名
#ifdef PRINT_DEBUG
							printf(
								"    %-12s --- %s\n",
								szObjectId,
								keyfileMapIt->first.c_str());
#endif
						}
					}
				}
			}

			pXMLCfg->DropAgentProbeCfgList(probeList);
		}

		delete pXMLCfg;
		pXMLCfg = NULL;
	}
}

void CDataCenterManage::addFrontUniqueID(char* szObjectID)
{
	//m_mapFrontAllocateID.insert(make_pair(++g_FrontAllocateID, szObjectID));
	string str_object_id(szObjectID);
	int base_value(0);
	if (str_object_id.find("TRADE.")!=string::npos)
	{
		base_value = 0;
	}
	else
	{
		base_value = 100;
	}
	string::size_type nPos = str_object_id.find_last_of('.');
	if (nPos!=string::npos)
	{
		string strSubNumbe = str_object_id.substr(nPos+1);
		int convert_value(0);
		for (int index=0; index!=strSubNumbe.size(); ++index)
		{
			convert_value = convert_value*10+strSubNumbe.at(index)-48;
		}
		convert_value += base_value;
		
		map<int, string>::iterator iter_find_index(m_mapFrontAllocateID.find(convert_value));
		if (iter_find_index==m_mapFrontAllocateID.end())
		{
			m_mapFrontAllocateID.insert(make_pair(convert_value, szObjectID));
		}
		else
		{
			int loop_index(0);
			while (++loop_index<200)
			{
				if (m_mapFrontAllocateID.find(convert_value+loop_index)==m_mapFrontAllocateID.end())
				{
					m_mapFrontAllocateID.insert(make_pair(convert_value+loop_index, szObjectID));
				}
			}
		}
	}
}