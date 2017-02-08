#include "public.h"
#include "Flow.h"
#include "FileFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "CXmlSession.h"
#include "CXML.h"
#include "version.h"

#define	 STRING_ATTR		1				///�ַ�����������
#define	 INT_ATTR			2				///������������
#define	 FLOAT_ATTR			3				///����������
#define	 PERCENT_ATTR		4				///�ٷֱ���������
#define	 STRING_ATTR_DESC	"string"		///�ַ���������������
#define	 INT_ATTR_DESC		"int"			///����������������
#define	 FLOAT_ATTR_DESC	"float"			///��������������
#define	 PERCENT_ATTR_DESC	"percent"		///�ٷֱ�������������

list<CXmlSession *>     g_mListAllSession;
list<string>			g_mListObject;
list<string>			g_mListService;
list<string>			g_mListConnect;
map<int, string>		g_mDataType;
list<string>			g_mListDisplayNum;
map<string, string>		g_mDisplayObjectNum; ///flash�ڶ��������ʾ�������

char	*INI_FILE_NAME = "syswebserver.xml";
string g_username;
string g_password;
CXmlPackage g_pkgSend;

#define XMLTOFILEDEBUG
#ifdef XMLTOFILEDEBUG
FILE *debugFp=NULL;
#endif

#undef XMLTOFILEDEBUG

void SendXmlBuffer(char *pXmlBuff)
{
#ifdef XMLTOFILEDEBUG
	if (debugFp==NULL)
	{
		debugFp = fopen("xml.txt","w");
	}
	fwrite(pXmlBuff,strlen(pXmlBuff),1,debugFp);
	fwrite("\r\n",2,1,debugFp);
	fflush(debugFp);
#endif
	g_pkgSend.PreparePackage();
	g_pkgSend.AddField(pXmlBuff, strlen(pXmlBuff)+1);

	list<CXmlSession *>::iterator it;
	for (it=g_mListAllSession.begin(); it!=g_mListAllSession.end(); it++)
	{
		(*it)->SendRequestPackage(&g_pkgSend);
	}
}

class CMyServer: public CSessionFactory, public CXmlSessionCallback
{
public:
	CMyServer(CReactor *pReactor)
		:CSessionFactory(pReactor, 100)
	{
		m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	}
	virtual int HandlePackage(CXmlPackage *pXmlPackage, CXmlSession *pSession)
	{
		printf("receive package\n");
		char buffer[512];

		CXmlIterator itor=pXmlPackage->GetNamedFieldIterator();
		while (!itor.IsEnd())
		{
			itor.Retrieve(buffer);
			printf("itor get string [%s]\n",buffer);
			itor.Next();
		}
		memset(buffer, 0, 512);
		strcpy(buffer, "<?xml version=\"1.0\"?><cross-domain-policy><allow-access-from domain=\"*\" to-ports=\"*\" /></cross-domain-policy>");

		m_pkgSend.PreparePackage();
		m_pkgSend.AddField(buffer, strlen(buffer)+1);
		pSession->SendRequestPackage(&m_pkgSend);
		return 0;
	}
	virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark)
	{
		CXmlSession *pSession = new CXmlSession(m_pReactor, pChannel);
		pSession->RegisterPackageHandler(this);
		return pSession;
	}
	///���ӳɹ�ʱ���õĴ�����
	///@param	pSession	���ӳɹ��ĻỰָ��
	virtual void OnSessionConnected(CSession *pSession)
	{
		printf("CMyServer OnSessionConnected %x\n",pSession);
		CXmlSession *pxmlSession = (CXmlSession *)pSession;
		char buffer[512];
		memset(buffer, 0, 512);
		strcpy(buffer, "<?xml version=\"1.0\"?><cross-domain-policy><allow-access-from domain=\"*\" to-ports=\"*\" /></cross-domain-policy>");
		m_pkgSend.PreparePackage();
		m_pkgSend.AddField(buffer, strlen(buffer)+1);
		pxmlSession->SendRequestPackage(&m_pkgSend);
		for (list<string>::iterator it=g_mListDisplayNum.begin();it!=g_mListDisplayNum.end();it++)
		{
			g_pkgSend.PreparePackage();
			g_pkgSend.AddField((char *)(it->c_str()), strlen(it->c_str())+1);
			pxmlSession->SendRequestPackage(&g_pkgSend);
		}
		g_mListAllSession.push_back((CXmlSession *)pSession);
	}
	/**�Ự���ӶϿ�ʱ�Ĵ�����
	* @param	pSession	�Ͽ������ӻỰָ��
	* @param	nReasion	�Ͽ���ԭ��
	*/
	virtual void OnSessionDisconnected(CSession *pSession, int nReason)
	{
		printf("CMyServer OnSessionDisconnected %x reason %d\n",pSession,nReason);
		g_mListAllSession.remove((CXmlSession *)pSession);
	}
private:
	CXmlPackage m_pkgSend;
};

class CFtdConnector: public CSessionFactory, public CFTDCSessionCallback
{
public:
	CFtdConnector(CReactor *pReactor)
		:CSessionFactory(pReactor, 10)
	{
		m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
		memset(m_buffer, 0, FTDC_PACKAGE_MAX_SIZE);
	}

	///�Ự����ʱ���õĴ�����
	///@param	pChannel	�����»Ự��ͨ��ָ��
	///@param	bIsListener	�Ự�Ƿ��Ǽ��������������ı��
	///@return	�������ɵ��»Ựָ��
	virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark)
	{
		CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
		pSession->RegisterPackageHandler(this);
		return pSession;
	}

	///�Ự���ӳɹ�ʱ���õĴ�����
	///@param	pSession	���ӵĻỰָ��
	virtual void OnSessionConnected(CSession *pSession)
	{
		CSessionFactory::OnSessionConnected(pSession);

		m_pkgSend.PreparePackage(FTD_TID_ReqQrySysUserLoginTopic, FTDC_CHAIN_LAST, FTD_VERSION);
		CFTDReqQrySysUserLoginField fieldLogin;
		memset(&fieldLogin, 0, sizeof(fieldLogin));
		fieldLogin.UserID = g_username.c_str();
		fieldLogin.Password = g_password.c_str();
		FTDC_ADD_FIELD(&m_pkgSend, &fieldLogin);
		((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);

		printf("\t\tCCounterConnector::OnSessionConnected SessionConnected %0x\n", (CFTDCSession *)pSession);
		printf("\t\t UserName [%s] Password [%s]\n",g_username.c_str(),g_password.c_str());
	}
protected:
	/**�Ự���ӶϿ�ʱ���õĴ�����
	* @param	pSession	�Ự���ӵ�ָ��
	* @param	nReasion	�Ự�Ͽ���ԭ��
	*/
	virtual void OnSessionDisconnected(CSession *pSession, int nReason)
	{
		CSessionFactory::OnSessionDisconnected(pSession, nReason);             // ������ø��ദ�����ӶϿ��¼�
		printf("\t\tCCounterConnector::OnSessionDisconnected  %0x \n", (CFTDCSession *)pSession);
	}

	virtual int HandlePackage(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
	{
		switch(pFTDCPackage->GetTID())
		{
		case FTD_TID_RtnObjectAttrTopic:
			OnRtnObjectAttrTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnWarningEventTopic:
			OnRtnWarningEventTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQrySysUserLoginTopic:
			OnRspUserLogin(pFTDCPackage, pSession);
			break;
		default:
			break;
		}
		return 0;
	}
	///���ĸ澯�¼���Ϣ������
	///@param	pMessage	�������յ��İ���ַ
	void OnRtnWarningEventTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

	///����ҵ�����״̬������
	///@param	pMessage	�������յ��İ���ַ
	void OnRtnObjectAttrTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

	void OnRspUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

private:
	CFTDCPackage m_pkgSend;
	char m_buffer[FTDC_PACKAGE_MAX_SIZE];
};

void CFtdConnector::OnRtnWarningEventTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	CFTDRtnWarningEventField fieldInfo;
	CNamedFieldIterator itor= pFTDCPackage->GetNamedFieldIterator(&CFTDRtnWarningEventField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);
		sprintf(m_buffer,"<Package type=\"Warning\" >\
<event objectid=\"%s\" \
EventName=\"%s\" \
WarningLevel=\"%s\" \
time=\"%s\" \
ProcessFlag=\"%s\" \
Description=\"%s\" EventID=\"%d\" /></Package>",
			fieldInfo.ObjectID.getValue(),
			fieldInfo.EventName.getValue(),
			fieldInfo.WarningLevel.getValue(),
			fieldInfo.Time.getValue(),
			fieldInfo.ProcessFlag.getValue(),
			fieldInfo.EventDes.getValue(),
			(const int)fieldInfo.EvendID);

		SendXmlBuffer(m_buffer);

#ifdef PRINT_DEBUG
		printf("++++xml :[%s]\n",m_buffer);
#endif
		itor.Next();
		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
		{
			break;
		}
	}
}

void CFtdConnector::OnRtnObjectAttrTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	CFTDRtnObjectAttrField fieldInfo;
	CNamedFieldIterator itor= pFTDCPackage->GetNamedFieldIterator(&CFTDRtnObjectAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);
		sprintf(m_buffer,"<Package type=\"ObjectAttr\" >\
<object objectid=\"%s\" AttrType=\"%s\" \
time=\"%s\" ValueType=\"%s\" Value=\"%s\" />\
</Package>",
			fieldInfo.ObjectID.getValue(),fieldInfo.AttrType.getValue(),
			fieldInfo.MonTime.getValue(), g_mDataType[(const int)fieldInfo.ValueType].c_str(),
			fieldInfo.AttrValue.getValue());

		SendXmlBuffer(m_buffer);

#ifdef PRINT_DEBUG
		printf("++++xml :[%s]\n",m_buffer);
#endif
		itor.Next();
		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
		{
			break;
		}
	}
}
void CFtdConnector::OnRspUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	CFTDRspQrySysUserLoginField rspUserLogin;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &rspUserLogin))
	{
		CFTDReqQrySubscriberField fieldInfo;
		memset(&fieldInfo, 0, sizeof(fieldInfo));
		list<string>::iterator it;
		for (it=g_mListObject.begin(); it!=g_mListObject.end(); it++)
		{
			m_pkgSend.PreparePackage(FTD_TID_ReqQrySubscriberTopic, FTDC_CHAIN_LAST, FTD_VERSION);
			fieldInfo.KeepAlive=1;
			fieldInfo.ObjectID=(char *)(it->c_str());
			fieldInfo.ObjectNum=1;
			FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);
			pSession->SendRequestPackage(&m_pkgSend);
		}
		return ;
	}
	CFTDRspInfoField rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &rspInfoField)) {
		printf("\t CEventCounterServer:: �û���¼ʧ�� ������ʾ��[%s]\n", (const char *)rspInfoField.ErrorMsg);
		printf("\t Flash ��������¼ǰ��ʧ�ܣ��˳��� \n");
		exit(0);
	}
}
void global_init()
{
	g_mDataType[STRING_ATTR] = string(STRING_ATTR_DESC);
	g_mDataType[INT_ATTR] = string(INT_ATTR_DESC);
	g_mDataType[FLOAT_ATTR] = string(FLOAT_ATTR_DESC);
	g_mDataType[PERCENT_ATTR] = string(PERCENT_ATTR_DESC);

	g_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);

	CXMLDoc  *pXMLDoc;
	CXMLNode *pXMLRoot;
	pXMLDoc = new CXMLDoc();
	try {
		pXMLDoc->read(INI_FILE_NAME);
		pXMLRoot = pXMLDoc->getRootNode();
		XMLNodeType NodeType = XMLTag;
		CXMLNode *webNode;
		CXMLNodeList *pNodeList;
		CXMLNode *pNode;
		CXMLNode *pNodeCur;
		int i;

		webNode = pXMLRoot->findNode(NodeType, "sysweb", NULL, NULL);
		pNodeList = webNode->getNodeList();
		pNode = (*pNodeList)[0];
		for (i = 0; i < pNodeList->size(); i++)
		{
			pNodeCur = (*pNodeList)[i];
			g_mListService.push_back(string(pNodeCur->findProperty("address")));
			//printf("\t%s \n",pNodeCur->findProperty("address"));
		}

		webNode = pXMLRoot->findNode(NodeType, "sysfront", NULL, NULL);
		pNodeList = webNode->getNodeList();
		pNode = (*pNodeList)[0];
		for (i = 0; i < pNodeList->size(); i++)
		{
			pNodeCur = (*pNodeList)[i];
			g_mListConnect.push_back(string(pNodeCur->findProperty("address")));
			//printf("\t%s \n",pNodeCur->findProperty("address"));
		}

		webNode = pXMLRoot->findNode(NodeType, "objects", NULL, NULL);
		pNodeList = webNode->getNodeList();
		pNode = (*pNodeList)[0];
		for (i = 0; i < pNodeList->size(); i++)
		{
			pNodeCur = (*pNodeList)[i];
			g_mListObject.push_back(string(pNodeCur->findProperty("value")));
			printf("\t%s \n",pNodeCur->findProperty("value"));
		}

		webNode = pXMLRoot->findNode(NodeType, "login", NULL, NULL);
		g_username = string(webNode->findProperty("username"));
		g_password = string(webNode->findProperty("password"));

		char tBuffer[512];
		webNode = pXMLRoot->findNode(NodeType, "displays", NULL, NULL);
		pNodeList = webNode->getNodeList();
		pNode = (*pNodeList)[0];
		for (i = 0; i < pNodeList->size(); i++)
		{
			pNodeCur = (*pNodeList)[i];
			sprintf(tBuffer,"<Package type=\"display\" >\
<object objectid=\"%s\" Value=\"%s\" /> </Package>",
			pNodeCur->findProperty("name"),pNodeCur->findProperty("value"));

			g_mListDisplayNum.push_back(string(tBuffer));
		}

	} catch(CParseError* e) {
		delete e;
		delete pXMLDoc;
		pXMLDoc = NULL;
		printf("\t syswebserver XML File %s explain failed\n", INI_FILE_NAME);
		printf("\t Program syswebser exit, �����ļ� �� %s ������%d \n" , __FILE__, __LINE__);
		exit(0);
	}
}

int main(int argc, char *argv[])
{
	showVersion(argc, argv);
	if (argc != 2 || (atoi(argv[1])) <= 0)
	{
		printf("\nUsage:%s [������ʶ]\n\n", argv[0]);
		exit(0);
	}
	global_init();

	CSelectReactor reactor;
	CMyServer myServer(&reactor);
	CFtdConnector myConnector(&reactor);

	list<string>::iterator it;
// 	for (it=g_mListDisplayNum.begin();it!=g_mListDisplayNum.end();it++)
// 	{
// 		printf("[%s]\n",it->c_str());
// 	}
//	myServer.RegisterListener((char *)"tcp://127.0.0.1:843");
	for (it=g_mListService.begin();it!=g_mListService.end();it++)
	{
		myServer.RegisterListener((char *)(it->c_str()));
	}
	for (it=g_mListConnect.begin();it!=g_mListConnect.end();it++)
	{
		myConnector.RegisterConnecter((char *)(it->c_str()));
	}

	reactor.Create();
	myServer.Start();
	myConnector.Start();
	reactor.Join();

	return 0;
}
