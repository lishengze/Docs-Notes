// SocketInit.cpp: implementation of the CSocketInit class.
//
// 20120409 江鹏   NT-0139 加快响应时间：增加通过广播地址得到网络地址的函数
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "SocketInit.h"

#define INT_TO_ADDR(_addr) \
(_addr & 0xFF), \
(_addr >> 8 & 0xFF), \
(_addr >> 16 & 0xFF), \
(_addr >> 24 & 0xFF)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSocketInit::CSocketInit()
{
#ifdef WIN32
	WSADATA initData;
	initData.wVersion=0;
	initData.wHighVersion=2;
	strcpy(initData.szDescription,"");
	strcpy(initData.szSystemStatus,"");
	initData.iMaxSockets=100;
	initData.lpVendorInfo=0;
	initData.lpVendorInfo="";
	WSAStartup(2,&initData);
	if (WSAStartup(2,&initData)!=0)
		RAISE_RUNTIME_ERROR("Can not init socket");
#endif

}

CSocketInit::~CSocketInit()
{

}

bool GetLocalAddress(int sock, const char* network, char* local)
{
	// 得到子网地址
	char subNetwork[64];
	strcpy(subNetwork, network);

	// 去掉后面的.255以方便比较
	char* subStr = strstr(subNetwork, ".255");

	if (subStr == NULL)
	{
		return false;
	}

	subStr[1] = '\0';

#ifdef WINDOWS
	char hostname[128];
	
	if (gethostname(hostname,128) !=0)
	{
		return false;
	}

	struct hostent* inaddrs = gethostbyname(hostname);

	if (inaddrs == NULL)
	{
		return false;
	}

	int count = inaddrs->h_length / sizeof(in_addr);
	unsigned long addr = 0;
			
	for (int i = 0; i < count; i ++)
	{
		addr = *(unsigned long*) inaddrs->h_addr_list[i];
		sprintf(local, "%d.%d.%d.%d", INT_TO_ADDR(addr));

		// ip前几位与网络相同就退出
		if (strncmp(subNetwork, local, strlen(subNetwork)) == 0)
		{
			return true;
		}
	}
#else
    struct ifconf ifc;
    struct ifreq ifr[64];
	char broad[64];

    ifc.ifc_len = sizeof(ifr);
    ifc.ifc_ifcu.ifcu_buf = (caddr_t)ifr;

    if (ioctl(sock, SIOCGIFCONF, &ifc) != 0)
	{
		return false;
	}

    int ifc_num = ifc.ifc_len / sizeof(struct ifreq);

    for (int i = 0; i < ifc_num; i ++)
    {
        if (ifr[i].ifr_addr.sa_family != AF_INET)
        {
            continue;
        }

		// 得到ip地址
        if (ioctl(sock, SIOCGIFADDR, &ifr[i]) != 0)
		{
			return false;
		}

        int addr = ((struct sockaddr_in *)(&ifr[i].ifr_addr))->sin_addr.s_addr;
		sprintf(local, "%d.%d.%d.%d", INT_TO_ADDR(addr));

		// ip前几位与网络相同就退出
		if (strncmp(subNetwork, local, strlen(subNetwork)) == 0)
		{
/*
			// 绑定物理网卡操作必须是root用户执行才会成功
			int ret = setsockopt(sock, SOL_SOCKET, SO_BINDTODEVICE, (void *) &ifr[i], sizeof(ifr[i]));

			if (ret != 0)
			{
				REPORT_EVENT(LOG_INFO, "SocketInit", "can't set SO_BINDTODEVICE: %s -> %s", network, ifr[i].ifr_name);
				return false;
			}
			else
			{
				return true;
			}
*/
			return true;
		}
	}	
#endif

	return false;
}
