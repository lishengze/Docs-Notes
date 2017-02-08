// myClient.h: interface for the IssClient class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSQLCLIENT_H__11EAA72A_EFF5_4944_8B1F_44973D30EF73__INCLUDED_)
#define AFX_MYSQLCLIENT_H__11EAA72A_EFF5_4944_8B1F_44973D30EF73__INCLUDED_

#include "ISAClient.h"

class ImyClient : public ISAClient  
{
public:
	ImyClient();
	virtual ~ImyClient();

	virtual ISAConnection *QueryConnectionInterface(
		SAConnection *pSAConnection);
};


#endif // !defined(AFX_MYSQLCLIENT_H__11EAA72A_EFF5_4944_8B1F_44973D30EF73__INCLUDED_)
