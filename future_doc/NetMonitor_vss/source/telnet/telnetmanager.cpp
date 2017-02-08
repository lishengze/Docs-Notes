#include "public.h"
#include "CTelnetConnThread.h"

int main(int argc, char *argv[])
{
	list<string> CmdList;
	CmdList.push_back("term length 0");
	CmdList.push_back("show running-config");
	CmdList.push_back("quit");

	CTelnetDevice Devices[] =
	{
		CTelnetDevice(
			CObjectIDName("BeiJing", "OA", "app", "Device1"),
			CTelnetConnEntry(
					"172.16.80.201",
					23,
					"sfit",
					"cisco",
					"123456",
					CmdList),
			"/tmp",
			"00:00:00-23:00:00.20"),
		CTelnetDevice(
			CObjectIDName("BeiJing", "OA", "app", "Device2"),
			CTelnetConnEntry(
					"172.16.80.202",
					23,
					"sfit",
					"cisco",
					"123456",
					CmdList),
			"/tmp",
			"00:00:00-23:00:00.20"),
		CTelnetDevice(
			CObjectIDName("BeiJing", "OA", "app", "Device3"),
			CTelnetConnEntry(
					"172.16.80.203",
					23,
					"sfit",
					"cisco",
					"123456",
					CmdList),
			"/tmp",
			"00:00:00-23:00:00.20")
	};

	printf("DeviceNum:%d\n", sizeof(Devices) / sizeof(CTelnetDevice));

	CTelnetConnThread *pThread1 = new CTelnetConnThread(1, Devices, 3);
	CTelnetConnThread *pThread2 = new CTelnetConnThread(2, Devices, 2);

	pThread1->Create();
	pThread2->Create();

#ifdef LINUX
	sleep(5);
	while (CTelnetClient::s_nInstances > 0)
	{
		// Waiting for job down ...
		sleep(60);
	}

#else
	while (1)
	{
	}

#endif
	delete pThread1;
	delete pThread2;
	exit(0);
}
