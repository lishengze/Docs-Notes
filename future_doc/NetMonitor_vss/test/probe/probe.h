#include "TcpMServer.h"
#include "CProbe.h"
#include "systools.h"

class CProbeServer
{
public:
	CProbeServer(CServiceName *pNameStart, CServiceName *pNameStop):m_startCtrl(pNameStart, 0),m_stopCtrl(pNameStop, 0)
	{
		
	}

	~CProbeServer()
	{

	}

	void Join();

private:
	CTcpMServer m_startCtrl;
	CTcpMServer m_stopCtrl;
};