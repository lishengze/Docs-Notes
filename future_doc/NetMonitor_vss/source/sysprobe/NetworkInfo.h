/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	NetworkInfo.h
///@brief	辅助 探针 获取网络信息
///@history
///20080514	武玉波		创建该文件
#ifndef CNETWORKINFO_H_INCLUDED
#define CNETWORKINFO_H_INCLUDED

#ifdef HP_UX
#include "public.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/mib.h>
#include <sys/errno.h>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <memory.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stream.h>
#include <sys/stropts.h>

#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <net/if .h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/dlpi.h>
#include <sys/dlpi_ext.h>
#include <string>
#include <map>
using namespace std;

// typedef struct {
//         char    nm_device[MAX_PHYSADDR_LEN]; /* interface name, e.g. "lo0",  */
//                                              /* "lan0", "lan1", etc.         */
//         u_int          ppa_num;        /* ppa number */
//         u_int          collisions;     /* Number of collisions  */
//         mib_ifEntry    if_entry;       /* MIB 2 Interface entry */
// } nmapi_phystat;
// typedef struct {
//         int     ifIndex;
//         char    ifDescr[64];
//         int     ifType;
//         int     ifMtu;
//         gauge   ifSpeed;
//         mib_physaddr_t  ifPhysAddress;
//         int     ifAdmin;
//         int     ifOper;
//         TimeTicks ifLastChange;
//         counter ifInOctets;
//         counter ifInUcastPkts;
//         counter ifInNUcastPkts;
//         counter ifInDiscards;
//         counter ifInErrors;
//         counter ifInUnknownProtos;
//         counter ifOutOctets;
//         counter ifOutUcastPkts;
//         counter ifOutNUcastPkts;
//         counter ifOutDiscards;
//         counter ifOutErrors;
//         gauge   ifOutQlen;
//         int     ifSpecific;
// } mib_ifEntry;
extern "C" {
	//int get_if_table(nmapi_iftable *, unsigned int *);
	int get_logical_stat(nmapi_logstat *, unsigned int *);
	int get_physical_stat(nmapi_phystat *, unsigned int *);
}

#define AREA_SIZE		400000	/* bytes; big enough for largest possible msg */
#define LONG_AREA_SIZE	(AREA_SIZE / sizeof(u_long))	/* AREA_SIZE / 4 */

#define GOT_CTRL		1			/* message has only a control part */
#define GOT_DATA		2			/* message has only a data part */
#define GOT_BOTH		3			/* message has both control and data parts */

u_long	ctrl_area[LONG_AREA_SIZE];	/* for control messages */
u_long	data_area[LONG_AREA_SIZE];	/* for data messages */

/*
获取网络信息：分两个部分，等同于
/usr/sbin/lanscan
	得到 网络节点的名称和状态 lan0 up  lan1 up....
	GetPPAList
netstat -i
	得到 mtu ip Ipkts Opkts
	GetNetStat
*/
struct NetStat
{
	unsigned long long	inPkts;
	unsigned long long	inOctets;
	unsigned long long	outPkts;
	unsigned long long	outOctets;
	string	status;
	string	ipAddr;
};
struct NetPPAInfo
{
	unsigned int mtu;
	string	state;
};
class CNetworkInfo
{
	/* */
	public:
		CNetworkInfo(void)
		{
			ctrl_buf.maxlen = AREA_SIZE;
			ctrl_buf.len = 0;

			//ctrl_buf.buf    = (char *)ctrl_area;
			data_buf.maxlen = AREA_SIZE;
			data_buf.len = 0;

			//data_buf.buf    = (char *)data_area;
		}

		~CNetworkInfo(void)
		{
			m_LanPPA.clear();
			m_LanStat.clear();
		}

	/* */
	public:

		///对GetNetStat GetPPAList的简单包装，方便外部进行调用
		int GetNetworkInfo(void)
		{
			//m_LanPPA.clear();
			m_LanStat.clear();
			GetPhyStat();

			//GetPPAList();
			//GetNetStat();
		}

		int GetPhyStat(void)
		{
			nmapi_phystat phystat[20];
			unsigned int phystatlen = 20 * sizeof(nmapi_phystat);
			if (get_physical_stat(phystat, &phystatlen) != 0)
			{
				printf(" get_physical_stat  Errno - %d\n", errno);
				fflush(stdout);
				return -1;
			}

			for (int i = 0; i < (phystatlen / sizeof(nmapi_phystat)); i++)
			{
				if (phystat[i].if_entry.ifType != 6)
				{
					continue;
				}

				NetStat mStat;
				mStat.inPkts = phystat[i].if_entry.ifInUcastPkts + phystat[i].if_entry.ifInNUcastPkts;
				mStat.inOctets = phystat[i].if_entry.ifInOctets;
				mStat.outPkts = phystat[i].if_entry.ifOutUcastPkts + phystat[i].if_entry.ifOutNUcastPkts;
				mStat.outOctets = phystat[i].if_entry.ifOutOctets;
				if (phystat[i].if_entry.ifAdmin != 1
				||	phystat[i].if_entry.ifOper != 1)
				{
					mStat.status = "Down";
				}
				else
				{
					mStat.status = "Up";
				}

				m_LanStat.insert(make_pair(phystat[i].nm_device, mStat));

				//			printf("Str: %s -- PPANUM: %d --\n",phystat[i].nm_device,phystat[i].ppa_num);
				//			printf("%d %d %d %d %d\n",phystat[i].if_entry.ifIndex,phystat[i].if_entry.ifType,
				//				phystat[i].if_entry.ifMtu,phystat[i].if_entry.ifAdmin,
				//				phystat[i].if_entry.ifOper);
				//         int     ifIndex;
				//         char    ifDescr[64];
				//         int     ifType;
				//         int     ifMtu;
				//         gauge   ifSpeed;
				//         mib_physaddr_t  ifPhysAddress;
				//         int     ifAdmin;
				//         int     ifOper;
				//         TimeTicks ifLastChange;
				//         counter ifInOctets;
				//         counter ifInUcastPkts;
				//         counter ifInNUcastPkts;
				//         counter ifInDiscards;
				//         counter ifInErrors;
				//         counter ifInUnknownProtos;
				//         counter ifOutOctets;
				//         counter ifOutUcastPkts;
				//         counter ifOutNUcastPkts;
				//         counter ifOutDiscards;
				//         counter ifOutErrors;
				//         gauge   ifOutQlen;
				//         int     ifSpecific;
				//			printf(""
			}
		}

		/******************************************************************************
	Get Ethernet 的流量（Package in|out）
	******************************************************************************/
		int GetNetStat(void)
		{
			nmapi_logstat logstat[20];
			unsigned int logstatlen = 20 * sizeof(nmapi_logstat);

			/// 辅助数据类型，方便提取ip地址为点分格式，可能存在问题，在windows环境下；
			union netaddr_to_dot
			{
				struct
				{
					unsigned char ip1;

					unsigned char ip2;

					unsigned char ip3;

					unsigned char ip4;
				} split_ip;

				unsigned int netaddr;
			};

			if (get_logical_stat(logstat, &logstatlen) != 0)
			{
				printf("Errno - %d\n", errno);
				fflush(stdout);
				return -1;
			}

			for (int i = 0; i < (logstatlen / sizeof(nmapi_logstat)); i++)
			{
				if (strcmp(logstat[i].nm_device, "lo0") == 0)
				{
					continue;
				}

				NetStat netStat;
				netStat.inPkts = logstat[i].in_packets;
				netStat.outPkts = logstat[i].out_packets;

				netaddr_to_dot	*ip = (netaddr_to_dot *) (&logstat[i].netaddr);

				netaddr_to_dot	tempip;
				tempip.netaddr = logstat[i].netaddr;
				printf(
					"%u.%u.%u.%u\n",
					tempip.split_ip.ip1,
					tempip.split_ip.ip2,
					tempip.split_ip.ip3,
					tempip.split_ip.ip4);

				printf("device name=%s\n", logstat[i].nm_device);
				fflush(stdout);

				char ipaddr[20];
				sprintf(
					ipaddr,
					"%u.%u.%u.%u",
					ip->split_ip.ip1,
					ip->split_ip.ip2,
					ip->split_ip.ip3,
					ip->split_ip.ip4);

				netStat.ipAddr = ipaddr;

				//printf("dddd = %s\n",logstat[i].nm_device);
				m_LanStat.insert(make_pair(logstat[i].nm_device, netStat));
			}

			return 0;
		}

		/******************************************************************************
	open the DLPI cloneable device file, get a list of available PPAs,
	and attach to the first PPA; returns a file descriptor for the stream
	******************************************************************************/
		int GetPPAList(void)
		{
			int fd; /* file descriptor */

			//int ppa;/* PPA to attach to */
			ctrl_buf.maxlen = AREA_SIZE;
			ctrl_buf.len = 0;
			ctrl_buf.buf = (char *)ctrl_area;

			data_buf.maxlen = AREA_SIZE;
			data_buf.len = 0;
			data_buf.buf = (char *)data_area;

			dl_hp_ppa_req_t *ppa_req = (dl_hp_ppa_req_t *)ctrl_area;
			dl_hp_ppa_ack_t *ppa_ack = (dl_hp_ppa_ack_t *)ctrl_area;
			dl_hp_ppa_info_t *ppa_info;

			/* open the device file */
			if ((fd = open("/dev/dlpi", O_RDWR)) == -1)
			{
				printf("error: open failed, errno = %d\n", errno);
				return -1;
			}

			/*
		find a PPA to attach to; we assume that the first PPA on the
		remote is on the same media as the first local PPA
		*/
			/* send a PPA_REQ and wait for the PPA_ACK */
			ppa_req->dl_primitive = DL_HP_PPA_REQ;
			put_ctrl(fd, sizeof(dl_hp_ppa_req_t), 0);
			get_msg(fd);
			check_ctrl(DL_HP_PPA_ACK);

			/* make sure we found at least one PPA */
			if (ppa_ack->dl_length == 0)
			{
				printf("error: no PPAs available\n");
				return -1;
			}

			/* examine the PPA */
			ppa_info = (dl_hp_ppa_info_t *) ((u_char *)ctrl_area + ppa_ack->dl_offset);

			dl_hp_ppa_info_t *temp_ppa_info = ppa_info;

			NetPPAInfo	info;
			string	lanName;
			char ppano[8];

			for (int i = 0; i < ppa_ack->dl_count; i++)
			{
				switch (temp_ppa_info->dl_mac_type)
				{
					case DL_CSMACD:
					case DL_ETHER:
						lanName = "lan";
						sprintf(ppano, "%d", temp_ppa_info->dl_ppa);
						lanName += ppano;

						info.mtu = temp_ppa_info->dl_mtu;

						if (temp_ppa_info->dl_hdw_state == 0)
						{
							info.state = "Up";
						}
						else
						{
							info.state = "Down";
						}

						m_LanPPA.insert(make_pair(lanName, info));

						//printf("dl_nmid=%d  dl_phys_addr=%s dl_ppa=%d\n",temp_ppa_info->dl_nmid,temp_ppa_info->dl_phys_addr,temp_ppa_info->dl_ppa);
						//mac_name = "Ethernet";
						printf(
							"dl_nmid=%d	dl_phys_addr=%s	dl_hw_path=%s	dl_name=%s	dl_mtu=%ld	dl_ppa=%d	dl_hdw_state=%d\n",
							temp_ppa_info->dl_nmid,
							temp_ppa_info->dl_phys_addr,
							temp_ppa_info->dl_hw_path,
							temp_ppa_info->dl_name,
							temp_ppa_info->dl_mtu,
							temp_ppa_info->dl_ppa,
							temp_ppa_info->dl_hdw_state);

						//string kk="lan";
						//kk += temp_ppa_info->dl_ppa;
						break;
					case DL_TPR:
						//mac_name = "Token Ring";
						break;
					case DL_FDDI:
						//mac_name = "FDDI";
						break;
					default:
						//printf("error: unknown MAC type in ppa_info\n");
						break;
				}

				temp_ppa_info++;
			}

			close(fd);
			return (0);
		}

	/* */
	private:

		/******************************************************************************
	get the next message from a stream; get_msg() returns one of the
	following defines
	******************************************************************************/
		int get_msg(int fd)
		//int fd;/* file descriptor */
		{
			int flags = 0;	/* 0 ---> get any available message */
			int result = 0; /* return value */

			/*
		zero first byte of control area so the caller can call check_ctrl
		without checking the get_msg return value; if there was only data
		in the message and the user was expecting control or control + data,
		then when he calls check_ctrl it will compare the expected primitive
		zero and print information about the primitive that it got.
		*/
			ctrl_area[0] = 0;

			/* call getmsg and check for an error */
			if (getmsg(fd, &ctrl_buf, &data_buf, &flags) < 0)
			{
				printf("error: getmsg failed, errno = %d\n", errno);
				return -1;
			}

			if (ctrl_buf.len > 0)
			{
				result |= GOT_CTRL;
			}

			if (data_buf.len > 0)
			{
				result |= GOT_DATA;
			}

			return (result);
		}

		/******************************************************************************
	check that control message is the expected message
	******************************************************************************/
		int check_ctrl(int ex_prim)
		//int ex_prim;/* the expected primitive */
		{
			dl_error_ack_t	*err_ack = (dl_error_ack_t *)ctrl_area;

			/* did we get the expected primitive? */
			if (err_ack->dl_primitive != ex_prim)
			{
				/* did we get a control part */
				if (ctrl_buf.len)
				{
					/* yup; is it an ERROR_ACK? */
					if (err_ack->dl_primitive == DL_ERROR_ACK)
					{
						/* yup; format the ERROR_ACK info */
						printf("error: expected primitive 0x%02x, ", ex_prim);
						printf("got DL_ERROR_ACK\n");
						printf(
							" dl_error_primitive = 0x%02x\n",
							err_ack->dl_error_primitive);
						printf(" dl_errno = 0x%02x\n", err_ack->dl_errno);
						printf(" dl_unix_errno = %d\n", err_ack->dl_unix_errno);
						return -1;
					}
					else
					{
						/*
					didn’t get an ERROR_ACK either; print whatever
					primitive we did get
					*/
						printf("error: expected primitive 0x%02x, ", ex_prim);
						printf("got primitive 0x%02x\n", err_ack->dl_primitive);
						return -1;
					}
				}
				else
				{
					/* no control; did we get data? */
					if (data_buf.len)
					{
						/* tell user we only got data */
						printf("error: check_ctrl found only data\n");
						return -1;
					}
					else
					{
						/*
					no message???; well, it was probably an
					interrupted system call
					*/
						printf("error: check_ctrl found no message\n");
						return -1;
					}
				}
			}
		}

		/******************************************************************************
	put a message consisting of only a control part on a stream
	******************************************************************************/
		int put_ctrl(int fd, int length, int pri)
		//int fd;/* file descriptor */
		//int length;/* length of control message */
		//int pri;/* priority of message: either 0 or RS_HIPRI */
		{
			/* set the len field in the strbuf structure */
			ctrl_buf.len = length;

			/* call putmsg and check for an error */
			if (putmsg(fd, &ctrl_buf, 0, pri) < 0)
			{
				printf("error: put_ctrl putmsg failed, errno = %d\n", errno);
				return -1;
			}

			return 0;
		}

	/* */
	public:
		/* these are u_long arrays instead of u_char to insure proper alignment */
		//  2008.08.22 在静态编译的情况下，放置在这里会有问题，需要定义到全局里；
		//  或者在使用CNetworkInfo的时候，把对象定义为全局的
		//u_long ctrl_area[LONG_AREA_SIZE];					/* for control messages */

	//u_long data_area[LONG_AREA_SIZE];					/* for data messages */
	private:
		struct strbuf ctrl_buf;
		struct strbuf data_buf;

	/* */
	public:
		map<string, NetPPAInfo> m_LanPPA;
		map<string, NetStat> m_LanStat;
};
#endif // #ifdef HP_UX
#endif // CNETWORKINFO_H_INCLUDED
