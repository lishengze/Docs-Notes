/////////////////////////////////////////////////////////////////////////
///@system 交易引擎系统
///@company 上海期货信息技术有限公司
///@file CDumpLog.cpp
///@brief实现了类CDumpLog
///@history 
///20041001	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#include "CDumpLog.h"
#include "monitorIndex.h"

///本宏控制是否使用单行方式进行输出
#define SINGLE_LINE

CExchangeDataSyncStatusDumpTrigger::CExchangeDataSyncStatusDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CExchangeDataSyncStatusDumpTrigger::~CExchangeDataSyncStatusDumpTrigger(void)
{
}


void CExchangeDataSyncStatusDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CExchangeDataSyncStatusDumpTrigger");
	pLogger->output(indent,0,"CExchangeDataSyncStatusDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CExchangeDataSyncStatusDumpTrigger::beforeAdd(CWriteableExchangeDataSyncStatus *pExchangeDataSyncStatus)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"ExchangeDataSyncStatus,add");
		pExchangeDataSyncStatus->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add ExchangeDataSyncStatus\n");
		pExchangeDataSyncStatus->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CExchangeDataSyncStatusDumpTrigger::beforeUpdate(CExchangeDataSyncStatus *pExchangeDataSyncStatus, CWriteableExchangeDataSyncStatus *pNewExchangeDataSyncStatus)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"ExchangeDataSyncStatus,upd");
		pNewExchangeDataSyncStatus->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update ExchangeDataSyncStatus\n");
		pNewExchangeDataSyncStatus->dumpDiff(m_output,pExchangeDataSyncStatus);
#endif
		fflush(m_output);
	}
}
	
void CExchangeDataSyncStatusDumpTrigger::beforeRemove(CExchangeDataSyncStatus *pExchangeDataSyncStatus)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"ExchangeDataSyncStatus,del");
		pExchangeDataSyncStatus->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove ExchangeDataSyncStatus\n");
		pExchangeDataSyncStatus->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSGDataSyncStatusDumpTrigger::CSGDataSyncStatusDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSGDataSyncStatusDumpTrigger::~CSGDataSyncStatusDumpTrigger(void)
{
}


void CSGDataSyncStatusDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSGDataSyncStatusDumpTrigger");
	pLogger->output(indent,0,"CSGDataSyncStatusDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSGDataSyncStatusDumpTrigger::beforeAdd(CWriteableSGDataSyncStatus *pSGDataSyncStatus)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SGDataSyncStatus,add");
		pSGDataSyncStatus->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SGDataSyncStatus\n");
		pSGDataSyncStatus->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSGDataSyncStatusDumpTrigger::beforeUpdate(CSGDataSyncStatus *pSGDataSyncStatus, CWriteableSGDataSyncStatus *pNewSGDataSyncStatus)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SGDataSyncStatus,upd");
		pNewSGDataSyncStatus->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SGDataSyncStatus\n");
		pNewSGDataSyncStatus->dumpDiff(m_output,pSGDataSyncStatus);
#endif
		fflush(m_output);
	}
}
	
void CSGDataSyncStatusDumpTrigger::beforeRemove(CSGDataSyncStatus *pSGDataSyncStatus)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SGDataSyncStatus,del");
		pSGDataSyncStatus->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SGDataSyncStatus\n");
		pSGDataSyncStatus->dump(m_output);
#endif
		fflush(m_output);
	}
}

CCurrentTimeDumpTrigger::CCurrentTimeDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CCurrentTimeDumpTrigger::~CCurrentTimeDumpTrigger(void)
{
}


void CCurrentTimeDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CCurrentTimeDumpTrigger");
	pLogger->output(indent,0,"CCurrentTimeDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CCurrentTimeDumpTrigger::beforeAdd(CWriteableCurrentTime *pCurrentTime)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrentTime,add");
		pCurrentTime->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add CurrentTime\n");
		pCurrentTime->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CCurrentTimeDumpTrigger::beforeUpdate(CCurrentTime *pCurrentTime, CWriteableCurrentTime *pNewCurrentTime)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrentTime,upd");
		pNewCurrentTime->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update CurrentTime\n");
		pNewCurrentTime->dumpDiff(m_output,pCurrentTime);
#endif
		fflush(m_output);
	}
}
	
void CCurrentTimeDumpTrigger::beforeRemove(CCurrentTime *pCurrentTime)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrentTime,del");
		pCurrentTime->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove CurrentTime\n");
		pCurrentTime->dump(m_output);
#endif
		fflush(m_output);
	}
}

CDataCenterDescDumpTrigger::CDataCenterDescDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CDataCenterDescDumpTrigger::~CDataCenterDescDumpTrigger(void)
{
}


void CDataCenterDescDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CDataCenterDescDumpTrigger");
	pLogger->output(indent,0,"CDataCenterDescDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CDataCenterDescDumpTrigger::beforeAdd(CWriteableDataCenterDesc *pDataCenterDesc)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"DataCenterDesc,add");
		pDataCenterDesc->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add DataCenterDesc\n");
		pDataCenterDesc->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CDataCenterDescDumpTrigger::beforeUpdate(CDataCenterDesc *pDataCenterDesc, CWriteableDataCenterDesc *pNewDataCenterDesc)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"DataCenterDesc,upd");
		pNewDataCenterDesc->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update DataCenterDesc\n");
		pNewDataCenterDesc->dumpDiff(m_output,pDataCenterDesc);
#endif
		fflush(m_output);
	}
}
	
void CDataCenterDescDumpTrigger::beforeRemove(CDataCenterDesc *pDataCenterDesc)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"DataCenterDesc,del");
		pDataCenterDesc->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove DataCenterDesc\n");
		pDataCenterDesc->dump(m_output);
#endif
		fflush(m_output);
	}
}

CExchangeDumpTrigger::CExchangeDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CExchangeDumpTrigger::~CExchangeDumpTrigger(void)
{
}


void CExchangeDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CExchangeDumpTrigger");
	pLogger->output(indent,0,"CExchangeDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CExchangeDumpTrigger::beforeAdd(CWriteableExchange *pExchange)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Exchange,add");
		pExchange->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add Exchange\n");
		pExchange->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CExchangeDumpTrigger::beforeUpdate(CExchange *pExchange, CWriteableExchange *pNewExchange)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Exchange,upd");
		pNewExchange->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update Exchange\n");
		pNewExchange->dumpDiff(m_output,pExchange);
#endif
		fflush(m_output);
	}
}
	
void CExchangeDumpTrigger::beforeRemove(CExchange *pExchange)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Exchange,del");
		pExchange->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove Exchange\n");
		pExchange->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSettlementGroupDumpTrigger::CSettlementGroupDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSettlementGroupDumpTrigger::~CSettlementGroupDumpTrigger(void)
{
}


void CSettlementGroupDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSettlementGroupDumpTrigger");
	pLogger->output(indent,0,"CSettlementGroupDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSettlementGroupDumpTrigger::beforeAdd(CWriteableSettlementGroup *pSettlementGroup)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SettlementGroup,add");
		pSettlementGroup->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SettlementGroup\n");
		pSettlementGroup->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSettlementGroupDumpTrigger::beforeUpdate(CSettlementGroup *pSettlementGroup, CWriteableSettlementGroup *pNewSettlementGroup)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SettlementGroup,upd");
		pNewSettlementGroup->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SettlementGroup\n");
		pNewSettlementGroup->dumpDiff(m_output,pSettlementGroup);
#endif
		fflush(m_output);
	}
}
	
void CSettlementGroupDumpTrigger::beforeRemove(CSettlementGroup *pSettlementGroup)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SettlementGroup,del");
		pSettlementGroup->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SettlementGroup\n");
		pSettlementGroup->dump(m_output);
#endif
		fflush(m_output);
	}
}

CMarketDumpTrigger::CMarketDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CMarketDumpTrigger::~CMarketDumpTrigger(void)
{
}


void CMarketDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CMarketDumpTrigger");
	pLogger->output(indent,0,"CMarketDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CMarketDumpTrigger::beforeAdd(CWriteableMarket *pMarket)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Market,add");
		pMarket->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add Market\n");
		pMarket->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CMarketDumpTrigger::beforeUpdate(CMarket *pMarket, CWriteableMarket *pNewMarket)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Market,upd");
		pNewMarket->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update Market\n");
		pNewMarket->dumpDiff(m_output,pMarket);
#endif
		fflush(m_output);
	}
}
	
void CMarketDumpTrigger::beforeRemove(CMarket *pMarket)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Market,del");
		pMarket->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove Market\n");
		pMarket->dump(m_output);
#endif
		fflush(m_output);
	}
}

CMarketProductDumpTrigger::CMarketProductDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CMarketProductDumpTrigger::~CMarketProductDumpTrigger(void)
{
}


void CMarketProductDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CMarketProductDumpTrigger");
	pLogger->output(indent,0,"CMarketProductDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CMarketProductDumpTrigger::beforeAdd(CWriteableMarketProduct *pMarketProduct)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MarketProduct,add");
		pMarketProduct->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add MarketProduct\n");
		pMarketProduct->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CMarketProductDumpTrigger::beforeUpdate(CMarketProduct *pMarketProduct, CWriteableMarketProduct *pNewMarketProduct)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MarketProduct,upd");
		pNewMarketProduct->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update MarketProduct\n");
		pNewMarketProduct->dumpDiff(m_output,pMarketProduct);
#endif
		fflush(m_output);
	}
}
	
void CMarketProductDumpTrigger::beforeRemove(CMarketProduct *pMarketProduct)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MarketProduct,del");
		pMarketProduct->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove MarketProduct\n");
		pMarketProduct->dump(m_output);
#endif
		fflush(m_output);
	}
}

CMarketProductGroupDumpTrigger::CMarketProductGroupDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CMarketProductGroupDumpTrigger::~CMarketProductGroupDumpTrigger(void)
{
}


void CMarketProductGroupDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CMarketProductGroupDumpTrigger");
	pLogger->output(indent,0,"CMarketProductGroupDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CMarketProductGroupDumpTrigger::beforeAdd(CWriteableMarketProductGroup *pMarketProductGroup)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MarketProductGroup,add");
		pMarketProductGroup->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add MarketProductGroup\n");
		pMarketProductGroup->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CMarketProductGroupDumpTrigger::beforeUpdate(CMarketProductGroup *pMarketProductGroup, CWriteableMarketProductGroup *pNewMarketProductGroup)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MarketProductGroup,upd");
		pNewMarketProductGroup->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update MarketProductGroup\n");
		pNewMarketProductGroup->dumpDiff(m_output,pMarketProductGroup);
#endif
		fflush(m_output);
	}
}
	
void CMarketProductGroupDumpTrigger::beforeRemove(CMarketProductGroup *pMarketProductGroup)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MarketProductGroup,del");
		pMarketProductGroup->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove MarketProductGroup\n");
		pMarketProductGroup->dump(m_output);
#endif
		fflush(m_output);
	}
}

CMdPubStatusDumpTrigger::CMdPubStatusDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CMdPubStatusDumpTrigger::~CMdPubStatusDumpTrigger(void)
{
}


void CMdPubStatusDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CMdPubStatusDumpTrigger");
	pLogger->output(indent,0,"CMdPubStatusDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CMdPubStatusDumpTrigger::beforeAdd(CWriteableMdPubStatus *pMdPubStatus)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MdPubStatus,add");
		pMdPubStatus->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add MdPubStatus\n");
		pMdPubStatus->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CMdPubStatusDumpTrigger::beforeUpdate(CMdPubStatus *pMdPubStatus, CWriteableMdPubStatus *pNewMdPubStatus)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MdPubStatus,upd");
		pNewMdPubStatus->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update MdPubStatus\n");
		pNewMdPubStatus->dumpDiff(m_output,pMdPubStatus);
#endif
		fflush(m_output);
	}
}
	
void CMdPubStatusDumpTrigger::beforeRemove(CMdPubStatus *pMdPubStatus)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MdPubStatus,del");
		pMdPubStatus->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove MdPubStatus\n");
		pMdPubStatus->dump(m_output);
#endif
		fflush(m_output);
	}
}

CMarketDataTopicDumpTrigger::CMarketDataTopicDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CMarketDataTopicDumpTrigger::~CMarketDataTopicDumpTrigger(void)
{
}


void CMarketDataTopicDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CMarketDataTopicDumpTrigger");
	pLogger->output(indent,0,"CMarketDataTopicDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CMarketDataTopicDumpTrigger::beforeAdd(CWriteableMarketDataTopic *pMarketDataTopic)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MarketDataTopic,add");
		pMarketDataTopic->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add MarketDataTopic\n");
		pMarketDataTopic->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CMarketDataTopicDumpTrigger::beforeUpdate(CMarketDataTopic *pMarketDataTopic, CWriteableMarketDataTopic *pNewMarketDataTopic)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MarketDataTopic,upd");
		pNewMarketDataTopic->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update MarketDataTopic\n");
		pNewMarketDataTopic->dumpDiff(m_output,pMarketDataTopic);
#endif
		fflush(m_output);
	}
}
	
void CMarketDataTopicDumpTrigger::beforeRemove(CMarketDataTopic *pMarketDataTopic)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MarketDataTopic,del");
		pMarketDataTopic->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove MarketDataTopic\n");
		pMarketDataTopic->dump(m_output);
#endif
		fflush(m_output);
	}
}

CPartTopicSubscribeDumpTrigger::CPartTopicSubscribeDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CPartTopicSubscribeDumpTrigger::~CPartTopicSubscribeDumpTrigger(void)
{
}


void CPartTopicSubscribeDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CPartTopicSubscribeDumpTrigger");
	pLogger->output(indent,0,"CPartTopicSubscribeDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CPartTopicSubscribeDumpTrigger::beforeAdd(CWriteablePartTopicSubscribe *pPartTopicSubscribe)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"PartTopicSubscribe,add");
		pPartTopicSubscribe->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add PartTopicSubscribe\n");
		pPartTopicSubscribe->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CPartTopicSubscribeDumpTrigger::beforeUpdate(CPartTopicSubscribe *pPartTopicSubscribe, CWriteablePartTopicSubscribe *pNewPartTopicSubscribe)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"PartTopicSubscribe,upd");
		pNewPartTopicSubscribe->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update PartTopicSubscribe\n");
		pNewPartTopicSubscribe->dumpDiff(m_output,pPartTopicSubscribe);
#endif
		fflush(m_output);
	}
}
	
void CPartTopicSubscribeDumpTrigger::beforeRemove(CPartTopicSubscribe *pPartTopicSubscribe)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"PartTopicSubscribe,del");
		pPartTopicSubscribe->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove PartTopicSubscribe\n");
		pPartTopicSubscribe->dump(m_output);
#endif
		fflush(m_output);
	}
}

CParticipantDumpTrigger::CParticipantDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CParticipantDumpTrigger::~CParticipantDumpTrigger(void)
{
}


void CParticipantDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CParticipantDumpTrigger");
	pLogger->output(indent,0,"CParticipantDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CParticipantDumpTrigger::beforeAdd(CWriteableParticipant *pParticipant)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Participant,add");
		pParticipant->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add Participant\n");
		pParticipant->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CParticipantDumpTrigger::beforeUpdate(CParticipant *pParticipant, CWriteableParticipant *pNewParticipant)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Participant,upd");
		pNewParticipant->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update Participant\n");
		pNewParticipant->dumpDiff(m_output,pParticipant);
#endif
		fflush(m_output);
	}
}
	
void CParticipantDumpTrigger::beforeRemove(CParticipant *pParticipant)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Participant,del");
		pParticipant->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove Participant\n");
		pParticipant->dump(m_output);
#endif
		fflush(m_output);
	}
}

CUserDumpTrigger::CUserDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CUserDumpTrigger::~CUserDumpTrigger(void)
{
}


void CUserDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CUserDumpTrigger");
	pLogger->output(indent,0,"CUserDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CUserDumpTrigger::beforeAdd(CWriteableUser *pUser)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"User,add");
		pUser->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add User\n");
		pUser->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CUserDumpTrigger::beforeUpdate(CUser *pUser, CWriteableUser *pNewUser)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"User,upd");
		pNewUser->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update User\n");
		pNewUser->dumpDiff(m_output,pUser);
#endif
		fflush(m_output);
	}
}
	
void CUserDumpTrigger::beforeRemove(CUser *pUser)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"User,del");
		pUser->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove User\n");
		pUser->dump(m_output);
#endif
		fflush(m_output);
	}
}

CClientDumpTrigger::CClientDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CClientDumpTrigger::~CClientDumpTrigger(void)
{
}


void CClientDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CClientDumpTrigger");
	pLogger->output(indent,0,"CClientDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CClientDumpTrigger::beforeAdd(CWriteableClient *pClient)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Client,add");
		pClient->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add Client\n");
		pClient->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CClientDumpTrigger::beforeUpdate(CClient *pClient, CWriteableClient *pNewClient)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Client,upd");
		pNewClient->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update Client\n");
		pNewClient->dumpDiff(m_output,pClient);
#endif
		fflush(m_output);
	}
}
	
void CClientDumpTrigger::beforeRemove(CClient *pClient)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Client,del");
		pClient->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove Client\n");
		pClient->dump(m_output);
#endif
		fflush(m_output);
	}
}

CUserIPDumpTrigger::CUserIPDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CUserIPDumpTrigger::~CUserIPDumpTrigger(void)
{
}


void CUserIPDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CUserIPDumpTrigger");
	pLogger->output(indent,0,"CUserIPDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CUserIPDumpTrigger::beforeAdd(CWriteableUserIP *pUserIP)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"UserIP,add");
		pUserIP->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add UserIP\n");
		pUserIP->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CUserIPDumpTrigger::beforeUpdate(CUserIP *pUserIP, CWriteableUserIP *pNewUserIP)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"UserIP,upd");
		pNewUserIP->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update UserIP\n");
		pNewUserIP->dumpDiff(m_output,pUserIP);
#endif
		fflush(m_output);
	}
}
	
void CUserIPDumpTrigger::beforeRemove(CUserIP *pUserIP)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"UserIP,del");
		pUserIP->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove UserIP\n");
		pUserIP->dump(m_output);
#endif
		fflush(m_output);
	}
}

CPartClientDumpTrigger::CPartClientDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CPartClientDumpTrigger::~CPartClientDumpTrigger(void)
{
}


void CPartClientDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CPartClientDumpTrigger");
	pLogger->output(indent,0,"CPartClientDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CPartClientDumpTrigger::beforeAdd(CWriteablePartClient *pPartClient)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"PartClient,add");
		pPartClient->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add PartClient\n");
		pPartClient->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CPartClientDumpTrigger::beforeUpdate(CPartClient *pPartClient, CWriteablePartClient *pNewPartClient)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"PartClient,upd");
		pNewPartClient->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update PartClient\n");
		pNewPartClient->dumpDiff(m_output,pPartClient);
#endif
		fflush(m_output);
	}
}
	
void CPartClientDumpTrigger::beforeRemove(CPartClient *pPartClient)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"PartClient,del");
		pPartClient->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove PartClient\n");
		pPartClient->dump(m_output);
#endif
		fflush(m_output);
	}
}

CClearingTradingPartDumpTrigger::CClearingTradingPartDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CClearingTradingPartDumpTrigger::~CClearingTradingPartDumpTrigger(void)
{
}


void CClearingTradingPartDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CClearingTradingPartDumpTrigger");
	pLogger->output(indent,0,"CClearingTradingPartDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CClearingTradingPartDumpTrigger::beforeAdd(CWriteableClearingTradingPart *pClearingTradingPart)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"ClearingTradingPart,add");
		pClearingTradingPart->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add ClearingTradingPart\n");
		pClearingTradingPart->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CClearingTradingPartDumpTrigger::beforeUpdate(CClearingTradingPart *pClearingTradingPart, CWriteableClearingTradingPart *pNewClearingTradingPart)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"ClearingTradingPart,upd");
		pNewClearingTradingPart->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update ClearingTradingPart\n");
		pNewClearingTradingPart->dumpDiff(m_output,pClearingTradingPart);
#endif
		fflush(m_output);
	}
}
	
void CClearingTradingPartDumpTrigger::beforeRemove(CClearingTradingPart *pClearingTradingPart)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"ClearingTradingPart,del");
		pClearingTradingPart->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove ClearingTradingPart\n");
		pClearingTradingPart->dump(m_output);
#endif
		fflush(m_output);
	}
}

CAliasDefineDumpTrigger::CAliasDefineDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CAliasDefineDumpTrigger::~CAliasDefineDumpTrigger(void)
{
}


void CAliasDefineDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CAliasDefineDumpTrigger");
	pLogger->output(indent,0,"CAliasDefineDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CAliasDefineDumpTrigger::beforeAdd(CWriteableAliasDefine *pAliasDefine)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"AliasDefine,add");
		pAliasDefine->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add AliasDefine\n");
		pAliasDefine->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CAliasDefineDumpTrigger::beforeUpdate(CAliasDefine *pAliasDefine, CWriteableAliasDefine *pNewAliasDefine)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"AliasDefine,upd");
		pNewAliasDefine->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update AliasDefine\n");
		pNewAliasDefine->dumpDiff(m_output,pAliasDefine);
#endif
		fflush(m_output);
	}
}
	
void CAliasDefineDumpTrigger::beforeRemove(CAliasDefine *pAliasDefine)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"AliasDefine,del");
		pAliasDefine->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove AliasDefine\n");
		pAliasDefine->dump(m_output);
#endif
		fflush(m_output);
	}
}

CUserFunctionRightDumpTrigger::CUserFunctionRightDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CUserFunctionRightDumpTrigger::~CUserFunctionRightDumpTrigger(void)
{
}


void CUserFunctionRightDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CUserFunctionRightDumpTrigger");
	pLogger->output(indent,0,"CUserFunctionRightDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CUserFunctionRightDumpTrigger::beforeAdd(CWriteableUserFunctionRight *pUserFunctionRight)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"UserFunctionRight,add");
		pUserFunctionRight->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add UserFunctionRight\n");
		pUserFunctionRight->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CUserFunctionRightDumpTrigger::beforeUpdate(CUserFunctionRight *pUserFunctionRight, CWriteableUserFunctionRight *pNewUserFunctionRight)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"UserFunctionRight,upd");
		pNewUserFunctionRight->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update UserFunctionRight\n");
		pNewUserFunctionRight->dumpDiff(m_output,pUserFunctionRight);
#endif
		fflush(m_output);
	}
}
	
void CUserFunctionRightDumpTrigger::beforeRemove(CUserFunctionRight *pUserFunctionRight)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"UserFunctionRight,del");
		pUserFunctionRight->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove UserFunctionRight\n");
		pUserFunctionRight->dump(m_output);
#endif
		fflush(m_output);
	}
}

CAccountDumpTrigger::CAccountDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CAccountDumpTrigger::~CAccountDumpTrigger(void)
{
}


void CAccountDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CAccountDumpTrigger");
	pLogger->output(indent,0,"CAccountDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CAccountDumpTrigger::beforeAdd(CWriteableAccount *pAccount)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Account,add");
		pAccount->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add Account\n");
		pAccount->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CAccountDumpTrigger::beforeUpdate(CAccount *pAccount, CWriteableAccount *pNewAccount)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Account,upd");
		pNewAccount->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update Account\n");
		pNewAccount->dumpDiff(m_output,pAccount);
#endif
		fflush(m_output);
	}
}
	
void CAccountDumpTrigger::beforeRemove(CAccount *pAccount)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Account,del");
		pAccount->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove Account\n");
		pAccount->dump(m_output);
#endif
		fflush(m_output);
	}
}

CUserCommFluxDumpTrigger::CUserCommFluxDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CUserCommFluxDumpTrigger::~CUserCommFluxDumpTrigger(void)
{
}


void CUserCommFluxDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CUserCommFluxDumpTrigger");
	pLogger->output(indent,0,"CUserCommFluxDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CUserCommFluxDumpTrigger::beforeAdd(CWriteableUserCommFlux *pUserCommFlux)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"UserCommFlux,add");
		pUserCommFlux->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add UserCommFlux\n");
		pUserCommFlux->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CUserCommFluxDumpTrigger::beforeUpdate(CUserCommFlux *pUserCommFlux, CWriteableUserCommFlux *pNewUserCommFlux)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"UserCommFlux,upd");
		pNewUserCommFlux->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update UserCommFlux\n");
		pNewUserCommFlux->dumpDiff(m_output,pUserCommFlux);
#endif
		fflush(m_output);
	}
}
	
void CUserCommFluxDumpTrigger::beforeRemove(CUserCommFlux *pUserCommFlux)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"UserCommFlux,del");
		pUserCommFlux->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove UserCommFlux\n");
		pUserCommFlux->dump(m_output);
#endif
		fflush(m_output);
	}
}

CMarketDataLogDumpTrigger::CMarketDataLogDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CMarketDataLogDumpTrigger::~CMarketDataLogDumpTrigger(void)
{
}


void CMarketDataLogDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CMarketDataLogDumpTrigger");
	pLogger->output(indent,0,"CMarketDataLogDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CMarketDataLogDumpTrigger::beforeAdd(CWriteableMarketDataLog *pMarketDataLog)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MarketDataLog,add");
		pMarketDataLog->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add MarketDataLog\n");
		pMarketDataLog->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CMarketDataLogDumpTrigger::beforeUpdate(CMarketDataLog *pMarketDataLog, CWriteableMarketDataLog *pNewMarketDataLog)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MarketDataLog,upd");
		pNewMarketDataLog->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update MarketDataLog\n");
		pNewMarketDataLog->dumpDiff(m_output,pMarketDataLog);
#endif
		fflush(m_output);
	}
}
	
void CMarketDataLogDumpTrigger::beforeRemove(CMarketDataLog *pMarketDataLog)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MarketDataLog,del");
		pMarketDataLog->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove MarketDataLog\n");
		pMarketDataLog->dump(m_output);
#endif
		fflush(m_output);
	}
}

CUserSessionDumpTrigger::CUserSessionDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CUserSessionDumpTrigger::~CUserSessionDumpTrigger(void)
{
}


void CUserSessionDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CUserSessionDumpTrigger");
	pLogger->output(indent,0,"CUserSessionDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CUserSessionDumpTrigger::beforeAdd(CWriteableUserSession *pUserSession)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"UserSession,add");
		pUserSession->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add UserSession\n");
		pUserSession->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CUserSessionDumpTrigger::beforeUpdate(CUserSession *pUserSession, CWriteableUserSession *pNewUserSession)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"UserSession,upd");
		pNewUserSession->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update UserSession\n");
		pNewUserSession->dumpDiff(m_output,pUserSession);
#endif
		fflush(m_output);
	}
}
	
void CUserSessionDumpTrigger::beforeRemove(CUserSession *pUserSession)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"UserSession,del");
		pUserSession->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove UserSession\n");
		pUserSession->dump(m_output);
#endif
		fflush(m_output);
	}
}

CMDSessionDumpTrigger::CMDSessionDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CMDSessionDumpTrigger::~CMDSessionDumpTrigger(void)
{
}


void CMDSessionDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CMDSessionDumpTrigger");
	pLogger->output(indent,0,"CMDSessionDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CMDSessionDumpTrigger::beforeAdd(CWriteableMDSession *pMDSession)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MDSession,add");
		pMDSession->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add MDSession\n");
		pMDSession->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CMDSessionDumpTrigger::beforeUpdate(CMDSession *pMDSession, CWriteableMDSession *pNewMDSession)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MDSession,upd");
		pNewMDSession->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update MDSession\n");
		pNewMDSession->dumpDiff(m_output,pMDSession);
#endif
		fflush(m_output);
	}
}
	
void CMDSessionDumpTrigger::beforeRemove(CMDSession *pMDSession)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MDSession,del");
		pMDSession->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove MDSession\n");
		pMDSession->dump(m_output);
#endif
		fflush(m_output);
	}
}

CLoginInfoDumpTrigger::CLoginInfoDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CLoginInfoDumpTrigger::~CLoginInfoDumpTrigger(void)
{
}


void CLoginInfoDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CLoginInfoDumpTrigger");
	pLogger->output(indent,0,"CLoginInfoDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CLoginInfoDumpTrigger::beforeAdd(CWriteableLoginInfo *pLoginInfo)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"LoginInfo,add");
		pLoginInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add LoginInfo\n");
		pLoginInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CLoginInfoDumpTrigger::beforeUpdate(CLoginInfo *pLoginInfo, CWriteableLoginInfo *pNewLoginInfo)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"LoginInfo,upd");
		pNewLoginInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update LoginInfo\n");
		pNewLoginInfo->dumpDiff(m_output,pLoginInfo);
#endif
		fflush(m_output);
	}
}
	
void CLoginInfoDumpTrigger::beforeRemove(CLoginInfo *pLoginInfo)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"LoginInfo,del");
		pLoginInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove LoginInfo\n");
		pLoginInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}

CDepthMarketDataDetailDumpTrigger::CDepthMarketDataDetailDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CDepthMarketDataDetailDumpTrigger::~CDepthMarketDataDetailDumpTrigger(void)
{
}


void CDepthMarketDataDetailDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CDepthMarketDataDetailDumpTrigger");
	pLogger->output(indent,0,"CDepthMarketDataDetailDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CDepthMarketDataDetailDumpTrigger::beforeAdd(CWriteableDepthMarketDataDetail *pDepthMarketDataDetail)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"DepthMarketDataDetail,add");
		pDepthMarketDataDetail->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add DepthMarketDataDetail\n");
		pDepthMarketDataDetail->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CDepthMarketDataDetailDumpTrigger::beforeUpdate(CDepthMarketDataDetail *pDepthMarketDataDetail, CWriteableDepthMarketDataDetail *pNewDepthMarketDataDetail)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"DepthMarketDataDetail,upd");
		pNewDepthMarketDataDetail->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update DepthMarketDataDetail\n");
		pNewDepthMarketDataDetail->dumpDiff(m_output,pDepthMarketDataDetail);
#endif
		fflush(m_output);
	}
}
	
void CDepthMarketDataDetailDumpTrigger::beforeRemove(CDepthMarketDataDetail *pDepthMarketDataDetail)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"DepthMarketDataDetail,del");
		pDepthMarketDataDetail->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove DepthMarketDataDetail\n");
		pDepthMarketDataDetail->dump(m_output);
#endif
		fflush(m_output);
	}
}

CInstrumentStatusDetailDumpTrigger::CInstrumentStatusDetailDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CInstrumentStatusDetailDumpTrigger::~CInstrumentStatusDetailDumpTrigger(void)
{
}


void CInstrumentStatusDetailDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CInstrumentStatusDetailDumpTrigger");
	pLogger->output(indent,0,"CInstrumentStatusDetailDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CInstrumentStatusDetailDumpTrigger::beforeAdd(CWriteableInstrumentStatusDetail *pInstrumentStatusDetail)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"InstrumentStatusDetail,add");
		pInstrumentStatusDetail->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add InstrumentStatusDetail\n");
		pInstrumentStatusDetail->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CInstrumentStatusDetailDumpTrigger::beforeUpdate(CInstrumentStatusDetail *pInstrumentStatusDetail, CWriteableInstrumentStatusDetail *pNewInstrumentStatusDetail)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"InstrumentStatusDetail,upd");
		pNewInstrumentStatusDetail->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update InstrumentStatusDetail\n");
		pNewInstrumentStatusDetail->dumpDiff(m_output,pInstrumentStatusDetail);
#endif
		fflush(m_output);
	}
}
	
void CInstrumentStatusDetailDumpTrigger::beforeRemove(CInstrumentStatusDetail *pInstrumentStatusDetail)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"InstrumentStatusDetail,del");
		pInstrumentStatusDetail->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove InstrumentStatusDetail\n");
		pInstrumentStatusDetail->dump(m_output);
#endif
		fflush(m_output);
	}
}

CFrontStatusDumpTrigger::CFrontStatusDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CFrontStatusDumpTrigger::~CFrontStatusDumpTrigger(void)
{
}


void CFrontStatusDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CFrontStatusDumpTrigger");
	pLogger->output(indent,0,"CFrontStatusDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CFrontStatusDumpTrigger::beforeAdd(CWriteableFrontStatus *pFrontStatus)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"FrontStatus,add");
		pFrontStatus->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add FrontStatus\n");
		pFrontStatus->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CFrontStatusDumpTrigger::beforeUpdate(CFrontStatus *pFrontStatus, CWriteableFrontStatus *pNewFrontStatus)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"FrontStatus,upd");
		pNewFrontStatus->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update FrontStatus\n");
		pNewFrontStatus->dumpDiff(m_output,pFrontStatus);
#endif
		fflush(m_output);
	}
}
	
void CFrontStatusDumpTrigger::beforeRemove(CFrontStatus *pFrontStatus)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"FrontStatus,del");
		pFrontStatus->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove FrontStatus\n");
		pFrontStatus->dump(m_output);
#endif
		fflush(m_output);
	}
}

CMaxLocalIDDumpTrigger::CMaxLocalIDDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CMaxLocalIDDumpTrigger::~CMaxLocalIDDumpTrigger(void)
{
}


void CMaxLocalIDDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CMaxLocalIDDumpTrigger");
	pLogger->output(indent,0,"CMaxLocalIDDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CMaxLocalIDDumpTrigger::beforeAdd(CWriteableMaxLocalID *pMaxLocalID)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MaxLocalID,add");
		pMaxLocalID->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add MaxLocalID\n");
		pMaxLocalID->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CMaxLocalIDDumpTrigger::beforeUpdate(CMaxLocalID *pMaxLocalID, CWriteableMaxLocalID *pNewMaxLocalID)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MaxLocalID,upd");
		pNewMaxLocalID->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update MaxLocalID\n");
		pNewMaxLocalID->dumpDiff(m_output,pMaxLocalID);
#endif
		fflush(m_output);
	}
}
	
void CMaxLocalIDDumpTrigger::beforeRemove(CMaxLocalID *pMaxLocalID)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MaxLocalID,del");
		pMaxLocalID->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove MaxLocalID\n");
		pMaxLocalID->dump(m_output);
#endif
		fflush(m_output);
	}
}

CBulletinDumpTrigger::CBulletinDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CBulletinDumpTrigger::~CBulletinDumpTrigger(void)
{
}


void CBulletinDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CBulletinDumpTrigger");
	pLogger->output(indent,0,"CBulletinDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CBulletinDumpTrigger::beforeAdd(CWriteableBulletin *pBulletin)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Bulletin,add");
		pBulletin->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add Bulletin\n");
		pBulletin->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CBulletinDumpTrigger::beforeUpdate(CBulletin *pBulletin, CWriteableBulletin *pNewBulletin)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Bulletin,upd");
		pNewBulletin->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update Bulletin\n");
		pNewBulletin->dumpDiff(m_output,pBulletin);
#endif
		fflush(m_output);
	}
}
	
void CBulletinDumpTrigger::beforeRemove(CBulletin *pBulletin)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Bulletin,del");
		pBulletin->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove Bulletin\n");
		pBulletin->dump(m_output);
#endif
		fflush(m_output);
	}
}

CMarketDataModifyDumpTrigger::CMarketDataModifyDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CMarketDataModifyDumpTrigger::~CMarketDataModifyDumpTrigger(void)
{
}


void CMarketDataModifyDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CMarketDataModifyDumpTrigger");
	pLogger->output(indent,0,"CMarketDataModifyDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CMarketDataModifyDumpTrigger::beforeAdd(CWriteableMarketDataModify *pMarketDataModify)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MarketDataModify,add");
		pMarketDataModify->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add MarketDataModify\n");
		pMarketDataModify->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CMarketDataModifyDumpTrigger::beforeUpdate(CMarketDataModify *pMarketDataModify, CWriteableMarketDataModify *pNewMarketDataModify)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MarketDataModify,upd");
		pNewMarketDataModify->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update MarketDataModify\n");
		pNewMarketDataModify->dumpDiff(m_output,pMarketDataModify);
#endif
		fflush(m_output);
	}
}
	
void CMarketDataModifyDumpTrigger::beforeRemove(CMarketDataModify *pMarketDataModify)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MarketDataModify,del");
		pMarketDataModify->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove MarketDataModify\n");
		pMarketDataModify->dump(m_output);
#endif
		fflush(m_output);
	}
}

CDepthMarketDataDumpTrigger::CDepthMarketDataDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CDepthMarketDataDumpTrigger::~CDepthMarketDataDumpTrigger(void)
{
}


void CDepthMarketDataDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CDepthMarketDataDumpTrigger");
	pLogger->output(indent,0,"CDepthMarketDataDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CDepthMarketDataDumpTrigger::beforeAdd(CWriteableDepthMarketData *pDepthMarketData)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"DepthMarketData,add");
		pDepthMarketData->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add DepthMarketData\n");
		pDepthMarketData->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CDepthMarketDataDumpTrigger::beforeUpdate(CDepthMarketData *pDepthMarketData, CWriteableDepthMarketData *pNewDepthMarketData)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"DepthMarketData,upd");
		pNewDepthMarketData->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update DepthMarketData\n");
		pNewDepthMarketData->dumpDiff(m_output,pDepthMarketData);
#endif
		fflush(m_output);
	}
}
	
void CDepthMarketDataDumpTrigger::beforeRemove(CDepthMarketData *pDepthMarketData)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"DepthMarketData,del");
		pDepthMarketData->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove DepthMarketData\n");
		pDepthMarketData->dump(m_output);
#endif
		fflush(m_output);
	}
}

CTopicMarketDataDumpTrigger::CTopicMarketDataDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CTopicMarketDataDumpTrigger::~CTopicMarketDataDumpTrigger(void)
{
}


void CTopicMarketDataDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CTopicMarketDataDumpTrigger");
	pLogger->output(indent,0,"CTopicMarketDataDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CTopicMarketDataDumpTrigger::beforeAdd(CWriteableTopicMarketData *pTopicMarketData)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"TopicMarketData,add");
		pTopicMarketData->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add TopicMarketData\n");
		pTopicMarketData->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CTopicMarketDataDumpTrigger::beforeUpdate(CTopicMarketData *pTopicMarketData, CWriteableTopicMarketData *pNewTopicMarketData)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"TopicMarketData,upd");
		pNewTopicMarketData->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update TopicMarketData\n");
		pNewTopicMarketData->dumpDiff(m_output,pTopicMarketData);
#endif
		fflush(m_output);
	}
}
	
void CTopicMarketDataDumpTrigger::beforeRemove(CTopicMarketData *pTopicMarketData)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"TopicMarketData,del");
		pTopicMarketData->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove TopicMarketData\n");
		pTopicMarketData->dump(m_output);
#endif
		fflush(m_output);
	}
}

CTopicMarketDataVersionDumpTrigger::CTopicMarketDataVersionDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CTopicMarketDataVersionDumpTrigger::~CTopicMarketDataVersionDumpTrigger(void)
{
}


void CTopicMarketDataVersionDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CTopicMarketDataVersionDumpTrigger");
	pLogger->output(indent,0,"CTopicMarketDataVersionDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CTopicMarketDataVersionDumpTrigger::beforeAdd(CWriteableTopicMarketDataVersion *pTopicMarketDataVersion)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"TopicMarketDataVersion,add");
		pTopicMarketDataVersion->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add TopicMarketDataVersion\n");
		pTopicMarketDataVersion->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CTopicMarketDataVersionDumpTrigger::beforeUpdate(CTopicMarketDataVersion *pTopicMarketDataVersion, CWriteableTopicMarketDataVersion *pNewTopicMarketDataVersion)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"TopicMarketDataVersion,upd");
		pNewTopicMarketDataVersion->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update TopicMarketDataVersion\n");
		pNewTopicMarketDataVersion->dumpDiff(m_output,pTopicMarketDataVersion);
#endif
		fflush(m_output);
	}
}
	
void CTopicMarketDataVersionDumpTrigger::beforeRemove(CTopicMarketDataVersion *pTopicMarketDataVersion)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"TopicMarketDataVersion,del");
		pTopicMarketDataVersion->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove TopicMarketDataVersion\n");
		pTopicMarketDataVersion->dump(m_output);
#endif
		fflush(m_output);
	}
}

CInformationDumpTrigger::CInformationDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CInformationDumpTrigger::~CInformationDumpTrigger(void)
{
}


void CInformationDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CInformationDumpTrigger");
	pLogger->output(indent,0,"CInformationDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CInformationDumpTrigger::beforeAdd(CWriteableInformation *pInformation)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Information,add");
		pInformation->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add Information\n");
		pInformation->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CInformationDumpTrigger::beforeUpdate(CInformation *pInformation, CWriteableInformation *pNewInformation)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Information,upd");
		pNewInformation->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update Information\n");
		pNewInformation->dumpDiff(m_output,pInformation);
#endif
		fflush(m_output);
	}
}
	
void CInformationDumpTrigger::beforeRemove(CInformation *pInformation)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Information,del");
		pInformation->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove Information\n");
		pInformation->dump(m_output);
#endif
		fflush(m_output);
	}
}

COrderCountDumpTrigger::COrderCountDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

COrderCountDumpTrigger::~COrderCountDumpTrigger(void)
{
}


void COrderCountDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("COrderCountDumpTrigger");
	pLogger->output(indent,0,"COrderCountDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void COrderCountDumpTrigger::beforeAdd(CWriteableOrderCount *pOrderCount)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"OrderCount,add");
		pOrderCount->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add OrderCount\n");
		pOrderCount->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void COrderCountDumpTrigger::beforeUpdate(COrderCount *pOrderCount, CWriteableOrderCount *pNewOrderCount)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"OrderCount,upd");
		pNewOrderCount->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update OrderCount\n");
		pNewOrderCount->dumpDiff(m_output,pOrderCount);
#endif
		fflush(m_output);
	}
}
	
void COrderCountDumpTrigger::beforeRemove(COrderCount *pOrderCount)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"OrderCount,del");
		pOrderCount->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove OrderCount\n");
		pOrderCount->dump(m_output);
#endif
		fflush(m_output);
	}
}

CInstrumentDumpTrigger::CInstrumentDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CInstrumentDumpTrigger::~CInstrumentDumpTrigger(void)
{
}


void CInstrumentDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CInstrumentDumpTrigger");
	pLogger->output(indent,0,"CInstrumentDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CInstrumentDumpTrigger::beforeAdd(CWriteableInstrument *pInstrument)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Instrument,add");
		pInstrument->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add Instrument\n");
		pInstrument->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CInstrumentDumpTrigger::beforeUpdate(CInstrument *pInstrument, CWriteableInstrument *pNewInstrument)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Instrument,upd");
		pNewInstrument->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update Instrument\n");
		pNewInstrument->dumpDiff(m_output,pInstrument);
#endif
		fflush(m_output);
	}
}
	
void CInstrumentDumpTrigger::beforeRemove(CInstrument *pInstrument)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Instrument,del");
		pInstrument->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove Instrument\n");
		pInstrument->dump(m_output);
#endif
		fflush(m_output);
	}
}

CCombinationLegDumpTrigger::CCombinationLegDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CCombinationLegDumpTrigger::~CCombinationLegDumpTrigger(void)
{
}


void CCombinationLegDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CCombinationLegDumpTrigger");
	pLogger->output(indent,0,"CCombinationLegDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CCombinationLegDumpTrigger::beforeAdd(CWriteableCombinationLeg *pCombinationLeg)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CombinationLeg,add");
		pCombinationLeg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add CombinationLeg\n");
		pCombinationLeg->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CCombinationLegDumpTrigger::beforeUpdate(CCombinationLeg *pCombinationLeg, CWriteableCombinationLeg *pNewCombinationLeg)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CombinationLeg,upd");
		pNewCombinationLeg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update CombinationLeg\n");
		pNewCombinationLeg->dumpDiff(m_output,pCombinationLeg);
#endif
		fflush(m_output);
	}
}
	
void CCombinationLegDumpTrigger::beforeRemove(CCombinationLeg *pCombinationLeg)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CombinationLeg,del");
		pCombinationLeg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove CombinationLeg\n");
		pCombinationLeg->dump(m_output);
#endif
		fflush(m_output);
	}
}

CPartRoleAccountDumpTrigger::CPartRoleAccountDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CPartRoleAccountDumpTrigger::~CPartRoleAccountDumpTrigger(void)
{
}


void CPartRoleAccountDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CPartRoleAccountDumpTrigger");
	pLogger->output(indent,0,"CPartRoleAccountDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CPartRoleAccountDumpTrigger::beforeAdd(CWriteablePartRoleAccount *pPartRoleAccount)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"PartRoleAccount,add");
		pPartRoleAccount->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add PartRoleAccount\n");
		pPartRoleAccount->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CPartRoleAccountDumpTrigger::beforeUpdate(CPartRoleAccount *pPartRoleAccount, CWriteablePartRoleAccount *pNewPartRoleAccount)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"PartRoleAccount,upd");
		pNewPartRoleAccount->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update PartRoleAccount\n");
		pNewPartRoleAccount->dumpDiff(m_output,pPartRoleAccount);
#endif
		fflush(m_output);
	}
}
	
void CPartRoleAccountDumpTrigger::beforeRemove(CPartRoleAccount *pPartRoleAccount)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"PartRoleAccount,del");
		pPartRoleAccount->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove PartRoleAccount\n");
		pPartRoleAccount->dump(m_output);
#endif
		fflush(m_output);
	}
}

CPartProductRoleDumpTrigger::CPartProductRoleDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CPartProductRoleDumpTrigger::~CPartProductRoleDumpTrigger(void)
{
}


void CPartProductRoleDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CPartProductRoleDumpTrigger");
	pLogger->output(indent,0,"CPartProductRoleDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CPartProductRoleDumpTrigger::beforeAdd(CWriteablePartProductRole *pPartProductRole)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"PartProductRole,add");
		pPartProductRole->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add PartProductRole\n");
		pPartProductRole->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CPartProductRoleDumpTrigger::beforeUpdate(CPartProductRole *pPartProductRole, CWriteablePartProductRole *pNewPartProductRole)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"PartProductRole,upd");
		pNewPartProductRole->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update PartProductRole\n");
		pNewPartProductRole->dumpDiff(m_output,pPartProductRole);
#endif
		fflush(m_output);
	}
}
	
void CPartProductRoleDumpTrigger::beforeRemove(CPartProductRole *pPartProductRole)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"PartProductRole,del");
		pPartProductRole->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove PartProductRole\n");
		pPartProductRole->dump(m_output);
#endif
		fflush(m_output);
	}
}

CPartProductRightDumpTrigger::CPartProductRightDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CPartProductRightDumpTrigger::~CPartProductRightDumpTrigger(void)
{
}


void CPartProductRightDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CPartProductRightDumpTrigger");
	pLogger->output(indent,0,"CPartProductRightDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CPartProductRightDumpTrigger::beforeAdd(CWriteablePartProductRight *pPartProductRight)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"PartProductRight,add");
		pPartProductRight->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add PartProductRight\n");
		pPartProductRight->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CPartProductRightDumpTrigger::beforeUpdate(CPartProductRight *pPartProductRight, CWriteablePartProductRight *pNewPartProductRight)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"PartProductRight,upd");
		pNewPartProductRight->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update PartProductRight\n");
		pNewPartProductRight->dumpDiff(m_output,pPartProductRight);
#endif
		fflush(m_output);
	}
}
	
void CPartProductRightDumpTrigger::beforeRemove(CPartProductRight *pPartProductRight)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"PartProductRight,del");
		pPartProductRight->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove PartProductRight\n");
		pPartProductRight->dump(m_output);
#endif
		fflush(m_output);
	}
}

CPartInstrumentRightDumpTrigger::CPartInstrumentRightDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CPartInstrumentRightDumpTrigger::~CPartInstrumentRightDumpTrigger(void)
{
}


void CPartInstrumentRightDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CPartInstrumentRightDumpTrigger");
	pLogger->output(indent,0,"CPartInstrumentRightDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CPartInstrumentRightDumpTrigger::beforeAdd(CWriteablePartInstrumentRight *pPartInstrumentRight)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"PartInstrumentRight,add");
		pPartInstrumentRight->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add PartInstrumentRight\n");
		pPartInstrumentRight->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CPartInstrumentRightDumpTrigger::beforeUpdate(CPartInstrumentRight *pPartInstrumentRight, CWriteablePartInstrumentRight *pNewPartInstrumentRight)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"PartInstrumentRight,upd");
		pNewPartInstrumentRight->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update PartInstrumentRight\n");
		pNewPartInstrumentRight->dumpDiff(m_output,pPartInstrumentRight);
#endif
		fflush(m_output);
	}
}
	
void CPartInstrumentRightDumpTrigger::beforeRemove(CPartInstrumentRight *pPartInstrumentRight)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"PartInstrumentRight,del");
		pPartInstrumentRight->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove PartInstrumentRight\n");
		pPartInstrumentRight->dump(m_output);
#endif
		fflush(m_output);
	}
}

CClientProductRightDumpTrigger::CClientProductRightDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CClientProductRightDumpTrigger::~CClientProductRightDumpTrigger(void)
{
}


void CClientProductRightDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CClientProductRightDumpTrigger");
	pLogger->output(indent,0,"CClientProductRightDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CClientProductRightDumpTrigger::beforeAdd(CWriteableClientProductRight *pClientProductRight)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"ClientProductRight,add");
		pClientProductRight->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add ClientProductRight\n");
		pClientProductRight->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CClientProductRightDumpTrigger::beforeUpdate(CClientProductRight *pClientProductRight, CWriteableClientProductRight *pNewClientProductRight)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"ClientProductRight,upd");
		pNewClientProductRight->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update ClientProductRight\n");
		pNewClientProductRight->dumpDiff(m_output,pClientProductRight);
#endif
		fflush(m_output);
	}
}
	
void CClientProductRightDumpTrigger::beforeRemove(CClientProductRight *pClientProductRight)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"ClientProductRight,del");
		pClientProductRight->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove ClientProductRight\n");
		pClientProductRight->dump(m_output);
#endif
		fflush(m_output);
	}
}

CClientInstrumentRightDumpTrigger::CClientInstrumentRightDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CClientInstrumentRightDumpTrigger::~CClientInstrumentRightDumpTrigger(void)
{
}


void CClientInstrumentRightDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CClientInstrumentRightDumpTrigger");
	pLogger->output(indent,0,"CClientInstrumentRightDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CClientInstrumentRightDumpTrigger::beforeAdd(CWriteableClientInstrumentRight *pClientInstrumentRight)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"ClientInstrumentRight,add");
		pClientInstrumentRight->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add ClientInstrumentRight\n");
		pClientInstrumentRight->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CClientInstrumentRightDumpTrigger::beforeUpdate(CClientInstrumentRight *pClientInstrumentRight, CWriteableClientInstrumentRight *pNewClientInstrumentRight)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"ClientInstrumentRight,upd");
		pNewClientInstrumentRight->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update ClientInstrumentRight\n");
		pNewClientInstrumentRight->dumpDiff(m_output,pClientInstrumentRight);
#endif
		fflush(m_output);
	}
}
	
void CClientInstrumentRightDumpTrigger::beforeRemove(CClientInstrumentRight *pClientInstrumentRight)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"ClientInstrumentRight,del");
		pClientInstrumentRight->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove ClientInstrumentRight\n");
		pClientInstrumentRight->dump(m_output);
#endif
		fflush(m_output);
	}
}

CPartClientProductRightDumpTrigger::CPartClientProductRightDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CPartClientProductRightDumpTrigger::~CPartClientProductRightDumpTrigger(void)
{
}


void CPartClientProductRightDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CPartClientProductRightDumpTrigger");
	pLogger->output(indent,0,"CPartClientProductRightDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CPartClientProductRightDumpTrigger::beforeAdd(CWriteablePartClientProductRight *pPartClientProductRight)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"PartClientProductRight,add");
		pPartClientProductRight->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add PartClientProductRight\n");
		pPartClientProductRight->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CPartClientProductRightDumpTrigger::beforeUpdate(CPartClientProductRight *pPartClientProductRight, CWriteablePartClientProductRight *pNewPartClientProductRight)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"PartClientProductRight,upd");
		pNewPartClientProductRight->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update PartClientProductRight\n");
		pNewPartClientProductRight->dumpDiff(m_output,pPartClientProductRight);
#endif
		fflush(m_output);
	}
}
	
void CPartClientProductRightDumpTrigger::beforeRemove(CPartClientProductRight *pPartClientProductRight)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"PartClientProductRight,del");
		pPartClientProductRight->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove PartClientProductRight\n");
		pPartClientProductRight->dump(m_output);
#endif
		fflush(m_output);
	}
}

CPartClientInstrumentRightDumpTrigger::CPartClientInstrumentRightDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CPartClientInstrumentRightDumpTrigger::~CPartClientInstrumentRightDumpTrigger(void)
{
}


void CPartClientInstrumentRightDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CPartClientInstrumentRightDumpTrigger");
	pLogger->output(indent,0,"CPartClientInstrumentRightDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CPartClientInstrumentRightDumpTrigger::beforeAdd(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"PartClientInstrumentRight,add");
		pPartClientInstrumentRight->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add PartClientInstrumentRight\n");
		pPartClientInstrumentRight->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CPartClientInstrumentRightDumpTrigger::beforeUpdate(CPartClientInstrumentRight *pPartClientInstrumentRight, CWriteablePartClientInstrumentRight *pNewPartClientInstrumentRight)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"PartClientInstrumentRight,upd");
		pNewPartClientInstrumentRight->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update PartClientInstrumentRight\n");
		pNewPartClientInstrumentRight->dumpDiff(m_output,pPartClientInstrumentRight);
#endif
		fflush(m_output);
	}
}
	
void CPartClientInstrumentRightDumpTrigger::beforeRemove(CPartClientInstrumentRight *pPartClientInstrumentRight)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"PartClientInstrumentRight,del");
		pPartClientInstrumentRight->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove PartClientInstrumentRight\n");
		pPartClientInstrumentRight->dump(m_output);
#endif
		fflush(m_output);
	}
}

CCurrProductPropertyDumpTrigger::CCurrProductPropertyDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CCurrProductPropertyDumpTrigger::~CCurrProductPropertyDumpTrigger(void)
{
}


void CCurrProductPropertyDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CCurrProductPropertyDumpTrigger");
	pLogger->output(indent,0,"CCurrProductPropertyDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CCurrProductPropertyDumpTrigger::beforeAdd(CWriteableCurrProductProperty *pCurrProductProperty)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrProductProperty,add");
		pCurrProductProperty->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add CurrProductProperty\n");
		pCurrProductProperty->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CCurrProductPropertyDumpTrigger::beforeUpdate(CCurrProductProperty *pCurrProductProperty, CWriteableCurrProductProperty *pNewCurrProductProperty)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrProductProperty,upd");
		pNewCurrProductProperty->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update CurrProductProperty\n");
		pNewCurrProductProperty->dumpDiff(m_output,pCurrProductProperty);
#endif
		fflush(m_output);
	}
}
	
void CCurrProductPropertyDumpTrigger::beforeRemove(CCurrProductProperty *pCurrProductProperty)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrProductProperty,del");
		pCurrProductProperty->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove CurrProductProperty\n");
		pCurrProductProperty->dump(m_output);
#endif
		fflush(m_output);
	}
}

CCurrInstrumentPropertyDumpTrigger::CCurrInstrumentPropertyDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CCurrInstrumentPropertyDumpTrigger::~CCurrInstrumentPropertyDumpTrigger(void)
{
}


void CCurrInstrumentPropertyDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CCurrInstrumentPropertyDumpTrigger");
	pLogger->output(indent,0,"CCurrInstrumentPropertyDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CCurrInstrumentPropertyDumpTrigger::beforeAdd(CWriteableCurrInstrumentProperty *pCurrInstrumentProperty)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrInstrumentProperty,add");
		pCurrInstrumentProperty->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add CurrInstrumentProperty\n");
		pCurrInstrumentProperty->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CCurrInstrumentPropertyDumpTrigger::beforeUpdate(CCurrInstrumentProperty *pCurrInstrumentProperty, CWriteableCurrInstrumentProperty *pNewCurrInstrumentProperty)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrInstrumentProperty,upd");
		pNewCurrInstrumentProperty->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update CurrInstrumentProperty\n");
		pNewCurrInstrumentProperty->dumpDiff(m_output,pCurrInstrumentProperty);
#endif
		fflush(m_output);
	}
}
	
void CCurrInstrumentPropertyDumpTrigger::beforeRemove(CCurrInstrumentProperty *pCurrInstrumentProperty)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrInstrumentProperty,del");
		pCurrInstrumentProperty->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove CurrInstrumentProperty\n");
		pCurrInstrumentProperty->dump(m_output);
#endif
		fflush(m_output);
	}
}

CCurrPriceBandingDumpTrigger::CCurrPriceBandingDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CCurrPriceBandingDumpTrigger::~CCurrPriceBandingDumpTrigger(void)
{
}


void CCurrPriceBandingDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CCurrPriceBandingDumpTrigger");
	pLogger->output(indent,0,"CCurrPriceBandingDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CCurrPriceBandingDumpTrigger::beforeAdd(CWriteableCurrPriceBanding *pCurrPriceBanding)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrPriceBanding,add");
		pCurrPriceBanding->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add CurrPriceBanding\n");
		pCurrPriceBanding->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CCurrPriceBandingDumpTrigger::beforeUpdate(CCurrPriceBanding *pCurrPriceBanding, CWriteableCurrPriceBanding *pNewCurrPriceBanding)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrPriceBanding,upd");
		pNewCurrPriceBanding->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update CurrPriceBanding\n");
		pNewCurrPriceBanding->dumpDiff(m_output,pCurrPriceBanding);
#endif
		fflush(m_output);
	}
}
	
void CCurrPriceBandingDumpTrigger::beforeRemove(CCurrPriceBanding *pCurrPriceBanding)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrPriceBanding,del");
		pCurrPriceBanding->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove CurrPriceBanding\n");
		pCurrPriceBanding->dump(m_output);
#endif
		fflush(m_output);
	}
}

CCurrMarginRateDumpTrigger::CCurrMarginRateDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CCurrMarginRateDumpTrigger::~CCurrMarginRateDumpTrigger(void)
{
}


void CCurrMarginRateDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CCurrMarginRateDumpTrigger");
	pLogger->output(indent,0,"CCurrMarginRateDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CCurrMarginRateDumpTrigger::beforeAdd(CWriteableCurrMarginRate *pCurrMarginRate)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrMarginRate,add");
		pCurrMarginRate->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add CurrMarginRate\n");
		pCurrMarginRate->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CCurrMarginRateDumpTrigger::beforeUpdate(CCurrMarginRate *pCurrMarginRate, CWriteableCurrMarginRate *pNewCurrMarginRate)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrMarginRate,upd");
		pNewCurrMarginRate->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update CurrMarginRate\n");
		pNewCurrMarginRate->dumpDiff(m_output,pCurrMarginRate);
#endif
		fflush(m_output);
	}
}
	
void CCurrMarginRateDumpTrigger::beforeRemove(CCurrMarginRate *pCurrMarginRate)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrMarginRate,del");
		pCurrMarginRate->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove CurrMarginRate\n");
		pCurrMarginRate->dump(m_output);
#endif
		fflush(m_output);
	}
}

CCurrMarginRateDetailDumpTrigger::CCurrMarginRateDetailDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CCurrMarginRateDetailDumpTrigger::~CCurrMarginRateDetailDumpTrigger(void)
{
}


void CCurrMarginRateDetailDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CCurrMarginRateDetailDumpTrigger");
	pLogger->output(indent,0,"CCurrMarginRateDetailDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CCurrMarginRateDetailDumpTrigger::beforeAdd(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrMarginRateDetail,add");
		pCurrMarginRateDetail->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add CurrMarginRateDetail\n");
		pCurrMarginRateDetail->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CCurrMarginRateDetailDumpTrigger::beforeUpdate(CCurrMarginRateDetail *pCurrMarginRateDetail, CWriteableCurrMarginRateDetail *pNewCurrMarginRateDetail)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrMarginRateDetail,upd");
		pNewCurrMarginRateDetail->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update CurrMarginRateDetail\n");
		pNewCurrMarginRateDetail->dumpDiff(m_output,pCurrMarginRateDetail);
#endif
		fflush(m_output);
	}
}
	
void CCurrMarginRateDetailDumpTrigger::beforeRemove(CCurrMarginRateDetail *pCurrMarginRateDetail)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrMarginRateDetail,del");
		pCurrMarginRateDetail->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove CurrMarginRateDetail\n");
		pCurrMarginRateDetail->dump(m_output);
#endif
		fflush(m_output);
	}
}

CCurrPartPosiLimitDumpTrigger::CCurrPartPosiLimitDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CCurrPartPosiLimitDumpTrigger::~CCurrPartPosiLimitDumpTrigger(void)
{
}


void CCurrPartPosiLimitDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CCurrPartPosiLimitDumpTrigger");
	pLogger->output(indent,0,"CCurrPartPosiLimitDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CCurrPartPosiLimitDumpTrigger::beforeAdd(CWriteableCurrPartPosiLimit *pCurrPartPosiLimit)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrPartPosiLimit,add");
		pCurrPartPosiLimit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add CurrPartPosiLimit\n");
		pCurrPartPosiLimit->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CCurrPartPosiLimitDumpTrigger::beforeUpdate(CCurrPartPosiLimit *pCurrPartPosiLimit, CWriteableCurrPartPosiLimit *pNewCurrPartPosiLimit)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrPartPosiLimit,upd");
		pNewCurrPartPosiLimit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update CurrPartPosiLimit\n");
		pNewCurrPartPosiLimit->dumpDiff(m_output,pCurrPartPosiLimit);
#endif
		fflush(m_output);
	}
}
	
void CCurrPartPosiLimitDumpTrigger::beforeRemove(CCurrPartPosiLimit *pCurrPartPosiLimit)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrPartPosiLimit,del");
		pCurrPartPosiLimit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove CurrPartPosiLimit\n");
		pCurrPartPosiLimit->dump(m_output);
#endif
		fflush(m_output);
	}
}

CCurrPartPosiLimitDetailDumpTrigger::CCurrPartPosiLimitDetailDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CCurrPartPosiLimitDetailDumpTrigger::~CCurrPartPosiLimitDetailDumpTrigger(void)
{
}


void CCurrPartPosiLimitDetailDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CCurrPartPosiLimitDetailDumpTrigger");
	pLogger->output(indent,0,"CCurrPartPosiLimitDetailDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CCurrPartPosiLimitDetailDumpTrigger::beforeAdd(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrPartPosiLimitDetail,add");
		pCurrPartPosiLimitDetail->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add CurrPartPosiLimitDetail\n");
		pCurrPartPosiLimitDetail->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CCurrPartPosiLimitDetailDumpTrigger::beforeUpdate(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CWriteableCurrPartPosiLimitDetail *pNewCurrPartPosiLimitDetail)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrPartPosiLimitDetail,upd");
		pNewCurrPartPosiLimitDetail->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update CurrPartPosiLimitDetail\n");
		pNewCurrPartPosiLimitDetail->dumpDiff(m_output,pCurrPartPosiLimitDetail);
#endif
		fflush(m_output);
	}
}
	
void CCurrPartPosiLimitDetailDumpTrigger::beforeRemove(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrPartPosiLimitDetail,del");
		pCurrPartPosiLimitDetail->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove CurrPartPosiLimitDetail\n");
		pCurrPartPosiLimitDetail->dump(m_output);
#endif
		fflush(m_output);
	}
}

CCurrClientPosiLimitDumpTrigger::CCurrClientPosiLimitDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CCurrClientPosiLimitDumpTrigger::~CCurrClientPosiLimitDumpTrigger(void)
{
}


void CCurrClientPosiLimitDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CCurrClientPosiLimitDumpTrigger");
	pLogger->output(indent,0,"CCurrClientPosiLimitDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CCurrClientPosiLimitDumpTrigger::beforeAdd(CWriteableCurrClientPosiLimit *pCurrClientPosiLimit)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrClientPosiLimit,add");
		pCurrClientPosiLimit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add CurrClientPosiLimit\n");
		pCurrClientPosiLimit->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CCurrClientPosiLimitDumpTrigger::beforeUpdate(CCurrClientPosiLimit *pCurrClientPosiLimit, CWriteableCurrClientPosiLimit *pNewCurrClientPosiLimit)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrClientPosiLimit,upd");
		pNewCurrClientPosiLimit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update CurrClientPosiLimit\n");
		pNewCurrClientPosiLimit->dumpDiff(m_output,pCurrClientPosiLimit);
#endif
		fflush(m_output);
	}
}
	
void CCurrClientPosiLimitDumpTrigger::beforeRemove(CCurrClientPosiLimit *pCurrClientPosiLimit)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrClientPosiLimit,del");
		pCurrClientPosiLimit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove CurrClientPosiLimit\n");
		pCurrClientPosiLimit->dump(m_output);
#endif
		fflush(m_output);
	}
}

CCurrClientPosiLimitDetailDumpTrigger::CCurrClientPosiLimitDetailDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CCurrClientPosiLimitDetailDumpTrigger::~CCurrClientPosiLimitDetailDumpTrigger(void)
{
}


void CCurrClientPosiLimitDetailDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CCurrClientPosiLimitDetailDumpTrigger");
	pLogger->output(indent,0,"CCurrClientPosiLimitDetailDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CCurrClientPosiLimitDetailDumpTrigger::beforeAdd(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrClientPosiLimitDetail,add");
		pCurrClientPosiLimitDetail->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add CurrClientPosiLimitDetail\n");
		pCurrClientPosiLimitDetail->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CCurrClientPosiLimitDetailDumpTrigger::beforeUpdate(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CWriteableCurrClientPosiLimitDetail *pNewCurrClientPosiLimitDetail)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrClientPosiLimitDetail,upd");
		pNewCurrClientPosiLimitDetail->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update CurrClientPosiLimitDetail\n");
		pNewCurrClientPosiLimitDetail->dumpDiff(m_output,pCurrClientPosiLimitDetail);
#endif
		fflush(m_output);
	}
}
	
void CCurrClientPosiLimitDetailDumpTrigger::beforeRemove(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrClientPosiLimitDetail,del");
		pCurrClientPosiLimitDetail->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove CurrClientPosiLimitDetail\n");
		pCurrClientPosiLimitDetail->dump(m_output);
#endif
		fflush(m_output);
	}
}

CCurrSpecialPosiLimitDumpTrigger::CCurrSpecialPosiLimitDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CCurrSpecialPosiLimitDumpTrigger::~CCurrSpecialPosiLimitDumpTrigger(void)
{
}


void CCurrSpecialPosiLimitDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CCurrSpecialPosiLimitDumpTrigger");
	pLogger->output(indent,0,"CCurrSpecialPosiLimitDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CCurrSpecialPosiLimitDumpTrigger::beforeAdd(CWriteableCurrSpecialPosiLimit *pCurrSpecialPosiLimit)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrSpecialPosiLimit,add");
		pCurrSpecialPosiLimit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add CurrSpecialPosiLimit\n");
		pCurrSpecialPosiLimit->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CCurrSpecialPosiLimitDumpTrigger::beforeUpdate(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit, CWriteableCurrSpecialPosiLimit *pNewCurrSpecialPosiLimit)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrSpecialPosiLimit,upd");
		pNewCurrSpecialPosiLimit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update CurrSpecialPosiLimit\n");
		pNewCurrSpecialPosiLimit->dumpDiff(m_output,pCurrSpecialPosiLimit);
#endif
		fflush(m_output);
	}
}
	
void CCurrSpecialPosiLimitDumpTrigger::beforeRemove(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrSpecialPosiLimit,del");
		pCurrSpecialPosiLimit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove CurrSpecialPosiLimit\n");
		pCurrSpecialPosiLimit->dump(m_output);
#endif
		fflush(m_output);
	}
}

CCurrSpecialPosiLimitDetailDumpTrigger::CCurrSpecialPosiLimitDetailDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CCurrSpecialPosiLimitDetailDumpTrigger::~CCurrSpecialPosiLimitDetailDumpTrigger(void)
{
}


void CCurrSpecialPosiLimitDetailDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CCurrSpecialPosiLimitDetailDumpTrigger");
	pLogger->output(indent,0,"CCurrSpecialPosiLimitDetailDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CCurrSpecialPosiLimitDetailDumpTrigger::beforeAdd(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrSpecialPosiLimitDetail,add");
		pCurrSpecialPosiLimitDetail->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add CurrSpecialPosiLimitDetail\n");
		pCurrSpecialPosiLimitDetail->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CCurrSpecialPosiLimitDetailDumpTrigger::beforeUpdate(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CWriteableCurrSpecialPosiLimitDetail *pNewCurrSpecialPosiLimitDetail)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrSpecialPosiLimitDetail,upd");
		pNewCurrSpecialPosiLimitDetail->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update CurrSpecialPosiLimitDetail\n");
		pNewCurrSpecialPosiLimitDetail->dumpDiff(m_output,pCurrSpecialPosiLimitDetail);
#endif
		fflush(m_output);
	}
}
	
void CCurrSpecialPosiLimitDetailDumpTrigger::beforeRemove(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrSpecialPosiLimitDetail,del");
		pCurrSpecialPosiLimitDetail->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove CurrSpecialPosiLimitDetail\n");
		pCurrSpecialPosiLimitDetail->dump(m_output);
#endif
		fflush(m_output);
	}
}

CCurrHedgeRuleDumpTrigger::CCurrHedgeRuleDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CCurrHedgeRuleDumpTrigger::~CCurrHedgeRuleDumpTrigger(void)
{
}


void CCurrHedgeRuleDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CCurrHedgeRuleDumpTrigger");
	pLogger->output(indent,0,"CCurrHedgeRuleDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CCurrHedgeRuleDumpTrigger::beforeAdd(CWriteableCurrHedgeRule *pCurrHedgeRule)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrHedgeRule,add");
		pCurrHedgeRule->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add CurrHedgeRule\n");
		pCurrHedgeRule->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CCurrHedgeRuleDumpTrigger::beforeUpdate(CCurrHedgeRule *pCurrHedgeRule, CWriteableCurrHedgeRule *pNewCurrHedgeRule)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrHedgeRule,upd");
		pNewCurrHedgeRule->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update CurrHedgeRule\n");
		pNewCurrHedgeRule->dumpDiff(m_output,pCurrHedgeRule);
#endif
		fflush(m_output);
	}
}
	
void CCurrHedgeRuleDumpTrigger::beforeRemove(CCurrHedgeRule *pCurrHedgeRule)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrHedgeRule,del");
		pCurrHedgeRule->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove CurrHedgeRule\n");
		pCurrHedgeRule->dump(m_output);
#endif
		fflush(m_output);
	}
}

CCurrTradingSegmentAttrDumpTrigger::CCurrTradingSegmentAttrDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CCurrTradingSegmentAttrDumpTrigger::~CCurrTradingSegmentAttrDumpTrigger(void)
{
}


void CCurrTradingSegmentAttrDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CCurrTradingSegmentAttrDumpTrigger");
	pLogger->output(indent,0,"CCurrTradingSegmentAttrDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CCurrTradingSegmentAttrDumpTrigger::beforeAdd(CWriteableCurrTradingSegmentAttr *pCurrTradingSegmentAttr)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrTradingSegmentAttr,add");
		pCurrTradingSegmentAttr->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add CurrTradingSegmentAttr\n");
		pCurrTradingSegmentAttr->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CCurrTradingSegmentAttrDumpTrigger::beforeUpdate(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr, CWriteableCurrTradingSegmentAttr *pNewCurrTradingSegmentAttr)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrTradingSegmentAttr,upd");
		pNewCurrTradingSegmentAttr->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update CurrTradingSegmentAttr\n");
		pNewCurrTradingSegmentAttr->dumpDiff(m_output,pCurrTradingSegmentAttr);
#endif
		fflush(m_output);
	}
}
	
void CCurrTradingSegmentAttrDumpTrigger::beforeRemove(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrTradingSegmentAttr,del");
		pCurrTradingSegmentAttr->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove CurrTradingSegmentAttr\n");
		pCurrTradingSegmentAttr->dump(m_output);
#endif
		fflush(m_output);
	}
}

CCurrFuseDumpTrigger::CCurrFuseDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CCurrFuseDumpTrigger::~CCurrFuseDumpTrigger(void)
{
}


void CCurrFuseDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CCurrFuseDumpTrigger");
	pLogger->output(indent,0,"CCurrFuseDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CCurrFuseDumpTrigger::beforeAdd(CWriteableCurrFuse *pCurrFuse)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrFuse,add");
		pCurrFuse->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add CurrFuse\n");
		pCurrFuse->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CCurrFuseDumpTrigger::beforeUpdate(CCurrFuse *pCurrFuse, CWriteableCurrFuse *pNewCurrFuse)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrFuse,upd");
		pNewCurrFuse->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update CurrFuse\n");
		pNewCurrFuse->dumpDiff(m_output,pCurrFuse);
#endif
		fflush(m_output);
	}
}
	
void CCurrFuseDumpTrigger::beforeRemove(CCurrFuse *pCurrFuse)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrFuse,del");
		pCurrFuse->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove CurrFuse\n");
		pCurrFuse->dump(m_output);
#endif
		fflush(m_output);
	}
}

CTradingAccountDumpTrigger::CTradingAccountDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CTradingAccountDumpTrigger::~CTradingAccountDumpTrigger(void)
{
}


void CTradingAccountDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CTradingAccountDumpTrigger");
	pLogger->output(indent,0,"CTradingAccountDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CTradingAccountDumpTrigger::beforeAdd(CWriteableTradingAccount *pTradingAccount)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"TradingAccount,add");
		pTradingAccount->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add TradingAccount\n");
		pTradingAccount->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CTradingAccountDumpTrigger::beforeUpdate(CTradingAccount *pTradingAccount, CWriteableTradingAccount *pNewTradingAccount)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"TradingAccount,upd");
		pNewTradingAccount->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update TradingAccount\n");
		pNewTradingAccount->dumpDiff(m_output,pTradingAccount);
#endif
		fflush(m_output);
	}
}
	
void CTradingAccountDumpTrigger::beforeRemove(CTradingAccount *pTradingAccount)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"TradingAccount,del");
		pTradingAccount->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove TradingAccount\n");
		pTradingAccount->dump(m_output);
#endif
		fflush(m_output);
	}
}

CBaseReserveAccountDumpTrigger::CBaseReserveAccountDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CBaseReserveAccountDumpTrigger::~CBaseReserveAccountDumpTrigger(void)
{
}


void CBaseReserveAccountDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CBaseReserveAccountDumpTrigger");
	pLogger->output(indent,0,"CBaseReserveAccountDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CBaseReserveAccountDumpTrigger::beforeAdd(CWriteableBaseReserveAccount *pBaseReserveAccount)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"BaseReserveAccount,add");
		pBaseReserveAccount->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add BaseReserveAccount\n");
		pBaseReserveAccount->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CBaseReserveAccountDumpTrigger::beforeUpdate(CBaseReserveAccount *pBaseReserveAccount, CWriteableBaseReserveAccount *pNewBaseReserveAccount)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"BaseReserveAccount,upd");
		pNewBaseReserveAccount->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update BaseReserveAccount\n");
		pNewBaseReserveAccount->dumpDiff(m_output,pBaseReserveAccount);
#endif
		fflush(m_output);
	}
}
	
void CBaseReserveAccountDumpTrigger::beforeRemove(CBaseReserveAccount *pBaseReserveAccount)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"BaseReserveAccount,del");
		pBaseReserveAccount->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove BaseReserveAccount\n");
		pBaseReserveAccount->dump(m_output);
#endif
		fflush(m_output);
	}
}

CPartPositionDumpTrigger::CPartPositionDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CPartPositionDumpTrigger::~CPartPositionDumpTrigger(void)
{
}


void CPartPositionDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CPartPositionDumpTrigger");
	pLogger->output(indent,0,"CPartPositionDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CPartPositionDumpTrigger::beforeAdd(CWriteablePartPosition *pPartPosition)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"PartPosition,add");
		pPartPosition->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add PartPosition\n");
		pPartPosition->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CPartPositionDumpTrigger::beforeUpdate(CPartPosition *pPartPosition, CWriteablePartPosition *pNewPartPosition)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"PartPosition,upd");
		pNewPartPosition->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update PartPosition\n");
		pNewPartPosition->dumpDiff(m_output,pPartPosition);
#endif
		fflush(m_output);
	}
}
	
void CPartPositionDumpTrigger::beforeRemove(CPartPosition *pPartPosition)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"PartPosition,del");
		pPartPosition->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove PartPosition\n");
		pPartPosition->dump(m_output);
#endif
		fflush(m_output);
	}
}

CClientPositionDumpTrigger::CClientPositionDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CClientPositionDumpTrigger::~CClientPositionDumpTrigger(void)
{
}


void CClientPositionDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CClientPositionDumpTrigger");
	pLogger->output(indent,0,"CClientPositionDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CClientPositionDumpTrigger::beforeAdd(CWriteableClientPosition *pClientPosition)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"ClientPosition,add");
		pClientPosition->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add ClientPosition\n");
		pClientPosition->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CClientPositionDumpTrigger::beforeUpdate(CClientPosition *pClientPosition, CWriteableClientPosition *pNewClientPosition)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"ClientPosition,upd");
		pNewClientPosition->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update ClientPosition\n");
		pNewClientPosition->dumpDiff(m_output,pClientPosition);
#endif
		fflush(m_output);
	}
}
	
void CClientPositionDumpTrigger::beforeRemove(CClientPosition *pClientPosition)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"ClientPosition,del");
		pClientPosition->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove ClientPosition\n");
		pClientPosition->dump(m_output);
#endif
		fflush(m_output);
	}
}

CHedgeVolumeDumpTrigger::CHedgeVolumeDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CHedgeVolumeDumpTrigger::~CHedgeVolumeDumpTrigger(void)
{
}


void CHedgeVolumeDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CHedgeVolumeDumpTrigger");
	pLogger->output(indent,0,"CHedgeVolumeDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CHedgeVolumeDumpTrigger::beforeAdd(CWriteableHedgeVolume *pHedgeVolume)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"HedgeVolume,add");
		pHedgeVolume->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add HedgeVolume\n");
		pHedgeVolume->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CHedgeVolumeDumpTrigger::beforeUpdate(CHedgeVolume *pHedgeVolume, CWriteableHedgeVolume *pNewHedgeVolume)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"HedgeVolume,upd");
		pNewHedgeVolume->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update HedgeVolume\n");
		pNewHedgeVolume->dumpDiff(m_output,pHedgeVolume);
#endif
		fflush(m_output);
	}
}
	
void CHedgeVolumeDumpTrigger::beforeRemove(CHedgeVolume *pHedgeVolume)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"HedgeVolume,del");
		pHedgeVolume->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove HedgeVolume\n");
		pHedgeVolume->dump(m_output);
#endif
		fflush(m_output);
	}
}

CRemainOrderDumpTrigger::CRemainOrderDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CRemainOrderDumpTrigger::~CRemainOrderDumpTrigger(void)
{
}


void CRemainOrderDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CRemainOrderDumpTrigger");
	pLogger->output(indent,0,"CRemainOrderDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CRemainOrderDumpTrigger::beforeAdd(CWriteableRemainOrder *pRemainOrder)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"RemainOrder,add");
		pRemainOrder->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add RemainOrder\n");
		pRemainOrder->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CRemainOrderDumpTrigger::beforeUpdate(CRemainOrder *pRemainOrder, CWriteableRemainOrder *pNewRemainOrder)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"RemainOrder,upd");
		pNewRemainOrder->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update RemainOrder\n");
		pNewRemainOrder->dumpDiff(m_output,pRemainOrder);
#endif
		fflush(m_output);
	}
}
	
void CRemainOrderDumpTrigger::beforeRemove(CRemainOrder *pRemainOrder)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"RemainOrder,del");
		pRemainOrder->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove RemainOrder\n");
		pRemainOrder->dump(m_output);
#endif
		fflush(m_output);
	}
}

CMarketDataDumpTrigger::CMarketDataDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CMarketDataDumpTrigger::~CMarketDataDumpTrigger(void)
{
}


void CMarketDataDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CMarketDataDumpTrigger");
	pLogger->output(indent,0,"CMarketDataDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CMarketDataDumpTrigger::beforeAdd(CWriteableMarketData *pMarketData)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MarketData,add");
		pMarketData->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add MarketData\n");
		pMarketData->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CMarketDataDumpTrigger::beforeUpdate(CMarketData *pMarketData, CWriteableMarketData *pNewMarketData)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MarketData,upd");
		pNewMarketData->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update MarketData\n");
		pNewMarketData->dumpDiff(m_output,pMarketData);
#endif
		fflush(m_output);
	}
}
	
void CMarketDataDumpTrigger::beforeRemove(CMarketData *pMarketData)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MarketData,del");
		pMarketData->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove MarketData\n");
		pMarketData->dump(m_output);
#endif
		fflush(m_output);
	}
}

CClearingPartPositionDumpTrigger::CClearingPartPositionDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CClearingPartPositionDumpTrigger::~CClearingPartPositionDumpTrigger(void)
{
}


void CClearingPartPositionDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CClearingPartPositionDumpTrigger");
	pLogger->output(indent,0,"CClearingPartPositionDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CClearingPartPositionDumpTrigger::beforeAdd(CWriteableClearingPartPosition *pClearingPartPosition)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"ClearingPartPosition,add");
		pClearingPartPosition->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add ClearingPartPosition\n");
		pClearingPartPosition->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CClearingPartPositionDumpTrigger::beforeUpdate(CClearingPartPosition *pClearingPartPosition, CWriteableClearingPartPosition *pNewClearingPartPosition)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"ClearingPartPosition,upd");
		pNewClearingPartPosition->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update ClearingPartPosition\n");
		pNewClearingPartPosition->dumpDiff(m_output,pClearingPartPosition);
#endif
		fflush(m_output);
	}
}
	
void CClearingPartPositionDumpTrigger::beforeRemove(CClearingPartPosition *pClearingPartPosition)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"ClearingPartPosition,del");
		pClearingPartPosition->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove ClearingPartPosition\n");
		pClearingPartPosition->dump(m_output);
#endif
		fflush(m_output);
	}
}

CInstrumentStatusDumpTrigger::CInstrumentStatusDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CInstrumentStatusDumpTrigger::~CInstrumentStatusDumpTrigger(void)
{
}


void CInstrumentStatusDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CInstrumentStatusDumpTrigger");
	pLogger->output(indent,0,"CInstrumentStatusDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CInstrumentStatusDumpTrigger::beforeAdd(CWriteableInstrumentStatus *pInstrumentStatus)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"InstrumentStatus,add");
		pInstrumentStatus->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add InstrumentStatus\n");
		pInstrumentStatus->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CInstrumentStatusDumpTrigger::beforeUpdate(CInstrumentStatus *pInstrumentStatus, CWriteableInstrumentStatus *pNewInstrumentStatus)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"InstrumentStatus,upd");
		pNewInstrumentStatus->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update InstrumentStatus\n");
		pNewInstrumentStatus->dumpDiff(m_output,pInstrumentStatus);
#endif
		fflush(m_output);
	}
}
	
void CInstrumentStatusDumpTrigger::beforeRemove(CInstrumentStatus *pInstrumentStatus)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"InstrumentStatus,del");
		pInstrumentStatus->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove InstrumentStatus\n");
		pInstrumentStatus->dump(m_output);
#endif
		fflush(m_output);
	}
}

COrderDumpTrigger::COrderDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

COrderDumpTrigger::~COrderDumpTrigger(void)
{
}


void COrderDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("COrderDumpTrigger");
	pLogger->output(indent,0,"COrderDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void COrderDumpTrigger::beforeAdd(CWriteableOrder *pOrder)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Order,add");
		pOrder->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add Order\n");
		pOrder->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void COrderDumpTrigger::beforeUpdate(COrder *pOrder, CWriteableOrder *pNewOrder)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Order,upd");
		pNewOrder->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update Order\n");
		pNewOrder->dumpDiff(m_output,pOrder);
#endif
		fflush(m_output);
	}
}
	
void COrderDumpTrigger::beforeRemove(COrder *pOrder)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Order,del");
		pOrder->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove Order\n");
		pOrder->dump(m_output);
#endif
		fflush(m_output);
	}
}

CCombOrderDumpTrigger::CCombOrderDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CCombOrderDumpTrigger::~CCombOrderDumpTrigger(void)
{
}


void CCombOrderDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CCombOrderDumpTrigger");
	pLogger->output(indent,0,"CCombOrderDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CCombOrderDumpTrigger::beforeAdd(CWriteableCombOrder *pCombOrder)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CombOrder,add");
		pCombOrder->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add CombOrder\n");
		pCombOrder->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CCombOrderDumpTrigger::beforeUpdate(CCombOrder *pCombOrder, CWriteableCombOrder *pNewCombOrder)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CombOrder,upd");
		pNewCombOrder->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update CombOrder\n");
		pNewCombOrder->dumpDiff(m_output,pCombOrder);
#endif
		fflush(m_output);
	}
}
	
void CCombOrderDumpTrigger::beforeRemove(CCombOrder *pCombOrder)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CombOrder,del");
		pCombOrder->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove CombOrder\n");
		pCombOrder->dump(m_output);
#endif
		fflush(m_output);
	}
}

COTCOrderDumpTrigger::COTCOrderDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

COTCOrderDumpTrigger::~COTCOrderDumpTrigger(void)
{
}


void COTCOrderDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("COTCOrderDumpTrigger");
	pLogger->output(indent,0,"COTCOrderDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void COTCOrderDumpTrigger::beforeAdd(CWriteableOTCOrder *pOTCOrder)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"OTCOrder,add");
		pOTCOrder->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add OTCOrder\n");
		pOTCOrder->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void COTCOrderDumpTrigger::beforeUpdate(COTCOrder *pOTCOrder, CWriteableOTCOrder *pNewOTCOrder)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"OTCOrder,upd");
		pNewOTCOrder->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update OTCOrder\n");
		pNewOTCOrder->dumpDiff(m_output,pOTCOrder);
#endif
		fflush(m_output);
	}
}
	
void COTCOrderDumpTrigger::beforeRemove(COTCOrder *pOTCOrder)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"OTCOrder,del");
		pOTCOrder->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove OTCOrder\n");
		pOTCOrder->dump(m_output);
#endif
		fflush(m_output);
	}
}

CImplyOrderDumpTrigger::CImplyOrderDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CImplyOrderDumpTrigger::~CImplyOrderDumpTrigger(void)
{
}


void CImplyOrderDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CImplyOrderDumpTrigger");
	pLogger->output(indent,0,"CImplyOrderDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CImplyOrderDumpTrigger::beforeAdd(CWriteableImplyOrder *pImplyOrder)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"ImplyOrder,add");
		pImplyOrder->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add ImplyOrder\n");
		pImplyOrder->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CImplyOrderDumpTrigger::beforeUpdate(CImplyOrder *pImplyOrder, CWriteableImplyOrder *pNewImplyOrder)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"ImplyOrder,upd");
		pNewImplyOrder->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update ImplyOrder\n");
		pNewImplyOrder->dumpDiff(m_output,pImplyOrder);
#endif
		fflush(m_output);
	}
}
	
void CImplyOrderDumpTrigger::beforeRemove(CImplyOrder *pImplyOrder)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"ImplyOrder,del");
		pImplyOrder->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove ImplyOrder\n");
		pImplyOrder->dump(m_output);
#endif
		fflush(m_output);
	}
}

CQuoteDumpTrigger::CQuoteDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CQuoteDumpTrigger::~CQuoteDumpTrigger(void)
{
}


void CQuoteDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CQuoteDumpTrigger");
	pLogger->output(indent,0,"CQuoteDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CQuoteDumpTrigger::beforeAdd(CWriteableQuote *pQuote)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Quote,add");
		pQuote->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add Quote\n");
		pQuote->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CQuoteDumpTrigger::beforeUpdate(CQuote *pQuote, CWriteableQuote *pNewQuote)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Quote,upd");
		pNewQuote->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update Quote\n");
		pNewQuote->dumpDiff(m_output,pQuote);
#endif
		fflush(m_output);
	}
}
	
void CQuoteDumpTrigger::beforeRemove(CQuote *pQuote)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Quote,del");
		pQuote->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove Quote\n");
		pQuote->dump(m_output);
#endif
		fflush(m_output);
	}
}

CMBLMarketDataDumpTrigger::CMBLMarketDataDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CMBLMarketDataDumpTrigger::~CMBLMarketDataDumpTrigger(void)
{
}


void CMBLMarketDataDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CMBLMarketDataDumpTrigger");
	pLogger->output(indent,0,"CMBLMarketDataDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CMBLMarketDataDumpTrigger::beforeAdd(CWriteableMBLMarketData *pMBLMarketData)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MBLMarketData,add");
		pMBLMarketData->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add MBLMarketData\n");
		pMBLMarketData->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CMBLMarketDataDumpTrigger::beforeUpdate(CMBLMarketData *pMBLMarketData, CWriteableMBLMarketData *pNewMBLMarketData)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MBLMarketData,upd");
		pNewMBLMarketData->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update MBLMarketData\n");
		pNewMBLMarketData->dumpDiff(m_output,pMBLMarketData);
#endif
		fflush(m_output);
	}
}
	
void CMBLMarketDataDumpTrigger::beforeRemove(CMBLMarketData *pMBLMarketData)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"MBLMarketData,del");
		pMBLMarketData->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove MBLMarketData\n");
		pMBLMarketData->dump(m_output);
#endif
		fflush(m_output);
	}
}

CTradeDumpTrigger::CTradeDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CTradeDumpTrigger::~CTradeDumpTrigger(void)
{
}


void CTradeDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CTradeDumpTrigger");
	pLogger->output(indent,0,"CTradeDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CTradeDumpTrigger::beforeAdd(CWriteableTrade *pTrade)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Trade,add");
		pTrade->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add Trade\n");
		pTrade->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CTradeDumpTrigger::beforeUpdate(CTrade *pTrade, CWriteableTrade *pNewTrade)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Trade,upd");
		pNewTrade->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update Trade\n");
		pNewTrade->dumpDiff(m_output,pTrade);
#endif
		fflush(m_output);
	}
}
	
void CTradeDumpTrigger::beforeRemove(CTrade *pTrade)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"Trade,del");
		pTrade->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove Trade\n");
		pTrade->dump(m_output);
#endif
		fflush(m_output);
	}
}

CFusePhaseDumpTrigger::CFusePhaseDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CFusePhaseDumpTrigger::~CFusePhaseDumpTrigger(void)
{
}


void CFusePhaseDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CFusePhaseDumpTrigger");
	pLogger->output(indent,0,"CFusePhaseDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CFusePhaseDumpTrigger::beforeAdd(CWriteableFusePhase *pFusePhase)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"FusePhase,add");
		pFusePhase->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add FusePhase\n");
		pFusePhase->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CFusePhaseDumpTrigger::beforeUpdate(CFusePhase *pFusePhase, CWriteableFusePhase *pNewFusePhase)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"FusePhase,upd");
		pNewFusePhase->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update FusePhase\n");
		pNewFusePhase->dumpDiff(m_output,pFusePhase);
#endif
		fflush(m_output);
	}
}
	
void CFusePhaseDumpTrigger::beforeRemove(CFusePhase *pFusePhase)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"FusePhase,del");
		pFusePhase->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove FusePhase\n");
		pFusePhase->dump(m_output);
#endif
		fflush(m_output);
	}
}

CExecOrderDumpTrigger::CExecOrderDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CExecOrderDumpTrigger::~CExecOrderDumpTrigger(void)
{
}


void CExecOrderDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CExecOrderDumpTrigger");
	pLogger->output(indent,0,"CExecOrderDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CExecOrderDumpTrigger::beforeAdd(CWriteableExecOrder *pExecOrder)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"ExecOrder,add");
		pExecOrder->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add ExecOrder\n");
		pExecOrder->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CExecOrderDumpTrigger::beforeUpdate(CExecOrder *pExecOrder, CWriteableExecOrder *pNewExecOrder)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"ExecOrder,upd");
		pNewExecOrder->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update ExecOrder\n");
		pNewExecOrder->dumpDiff(m_output,pExecOrder);
#endif
		fflush(m_output);
	}
}
	
void CExecOrderDumpTrigger::beforeRemove(CExecOrder *pExecOrder)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"ExecOrder,del");
		pExecOrder->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove ExecOrder\n");
		pExecOrder->dump(m_output);
#endif
		fflush(m_output);
	}
}

CUniPressureDumpTrigger::CUniPressureDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CUniPressureDumpTrigger::~CUniPressureDumpTrigger(void)
{
}


void CUniPressureDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CUniPressureDumpTrigger");
	pLogger->output(indent,0,"CUniPressureDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CUniPressureDumpTrigger::beforeAdd(CWriteableUniPressure *pUniPressure)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"UniPressure,add");
		pUniPressure->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add UniPressure\n");
		pUniPressure->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CUniPressureDumpTrigger::beforeUpdate(CUniPressure *pUniPressure, CWriteableUniPressure *pNewUniPressure)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"UniPressure,upd");
		pNewUniPressure->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update UniPressure\n");
		pNewUniPressure->dumpDiff(m_output,pUniPressure);
#endif
		fflush(m_output);
	}
}
	
void CUniPressureDumpTrigger::beforeRemove(CUniPressure *pUniPressure)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"UniPressure,del");
		pUniPressure->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove UniPressure\n");
		pUniPressure->dump(m_output);
#endif
		fflush(m_output);
	}
}

CBasePriceLimitDumpTrigger::CBasePriceLimitDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CBasePriceLimitDumpTrigger::~CBasePriceLimitDumpTrigger(void)
{
}


void CBasePriceLimitDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CBasePriceLimitDumpTrigger");
	pLogger->output(indent,0,"CBasePriceLimitDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CBasePriceLimitDumpTrigger::beforeAdd(CWriteableBasePriceLimit *pBasePriceLimit)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"BasePriceLimit,add");
		pBasePriceLimit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add BasePriceLimit\n");
		pBasePriceLimit->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CBasePriceLimitDumpTrigger::beforeUpdate(CBasePriceLimit *pBasePriceLimit, CWriteableBasePriceLimit *pNewBasePriceLimit)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"BasePriceLimit,upd");
		pNewBasePriceLimit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update BasePriceLimit\n");
		pNewBasePriceLimit->dumpDiff(m_output,pBasePriceLimit);
#endif
		fflush(m_output);
	}
}
	
void CBasePriceLimitDumpTrigger::beforeRemove(CBasePriceLimit *pBasePriceLimit)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"BasePriceLimit,del");
		pBasePriceLimit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove BasePriceLimit\n");
		pBasePriceLimit->dump(m_output);
#endif
		fflush(m_output);
	}
}

CCreditLimitDumpTrigger::CCreditLimitDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CCreditLimitDumpTrigger::~CCreditLimitDumpTrigger(void)
{
}


void CCreditLimitDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CCreditLimitDumpTrigger");
	pLogger->output(indent,0,"CCreditLimitDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CCreditLimitDumpTrigger::beforeAdd(CWriteableCreditLimit *pCreditLimit)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CreditLimit,add");
		pCreditLimit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add CreditLimit\n");
		pCreditLimit->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CCreditLimitDumpTrigger::beforeUpdate(CCreditLimit *pCreditLimit, CWriteableCreditLimit *pNewCreditLimit)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CreditLimit,upd");
		pNewCreditLimit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update CreditLimit\n");
		pNewCreditLimit->dumpDiff(m_output,pCreditLimit);
#endif
		fflush(m_output);
	}
}
	
void CCreditLimitDumpTrigger::beforeRemove(CCreditLimit *pCreditLimit)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CreditLimit,del");
		pCreditLimit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove CreditLimit\n");
		pCreditLimit->dump(m_output);
#endif
		fflush(m_output);
	}
}

CCurrInstrumentOptionDumpTrigger::CCurrInstrumentOptionDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CCurrInstrumentOptionDumpTrigger::~CCurrInstrumentOptionDumpTrigger(void)
{
}


void CCurrInstrumentOptionDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CCurrInstrumentOptionDumpTrigger");
	pLogger->output(indent,0,"CCurrInstrumentOptionDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CCurrInstrumentOptionDumpTrigger::beforeAdd(CWriteableCurrInstrumentOption *pCurrInstrumentOption)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrInstrumentOption,add");
		pCurrInstrumentOption->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add CurrInstrumentOption\n");
		pCurrInstrumentOption->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CCurrInstrumentOptionDumpTrigger::beforeUpdate(CCurrInstrumentOption *pCurrInstrumentOption, CWriteableCurrInstrumentOption *pNewCurrInstrumentOption)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrInstrumentOption,upd");
		pNewCurrInstrumentOption->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update CurrInstrumentOption\n");
		pNewCurrInstrumentOption->dumpDiff(m_output,pCurrInstrumentOption);
#endif
		fflush(m_output);
	}
}
	
void CCurrInstrumentOptionDumpTrigger::beforeRemove(CCurrInstrumentOption *pCurrInstrumentOption)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"CurrInstrumentOption,del");
		pCurrInstrumentOption->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove CurrInstrumentOption\n");
		pCurrInstrumentOption->dump(m_output);
#endif
		fflush(m_output);
	}
}

CDumpLog::CDumpLog(CMemoryDB *pDB, CConfig *pConfig)
{
	char *fileName=pConfig->getConfig("DumpOutput");
	if (*fileName=='\0')
	{
		m_DumpOutput=NULL;
		return;
	}
	if (!strcmp(fileName,"stdout"))
	{
		m_DumpOutput=stdout;
	}
	else if (!strcmp(fileName,"stderr"))
	{
		m_DumpOutput=stderr;
	}
	else
	{
		m_DumpOutput=mfopen(fileName,"wt");
	}
	if (m_DumpOutput==NULL)
	{
		REPORT_EVENT(LOG_INFO,"EnvError","write dump file failed");
		return;
	}
	m_DB=pDB;
	m_Started=0;

	m_ExchangeDataSyncStatusTrigger=new CExchangeDataSyncStatusDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SGDataSyncStatusTrigger=new CSGDataSyncStatusDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_CurrentTimeTrigger=new CCurrentTimeDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_DataCenterDescTrigger=new CDataCenterDescDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_ExchangeTrigger=new CExchangeDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SettlementGroupTrigger=new CSettlementGroupDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_MarketTrigger=new CMarketDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_MarketProductTrigger=new CMarketProductDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_MarketProductGroupTrigger=new CMarketProductGroupDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_MdPubStatusTrigger=new CMdPubStatusDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_MarketDataTopicTrigger=new CMarketDataTopicDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_PartTopicSubscribeTrigger=new CPartTopicSubscribeDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_ParticipantTrigger=new CParticipantDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_UserTrigger=new CUserDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_ClientTrigger=new CClientDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_UserIPTrigger=new CUserIPDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_PartClientTrigger=new CPartClientDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_ClearingTradingPartTrigger=new CClearingTradingPartDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_AliasDefineTrigger=new CAliasDefineDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_UserFunctionRightTrigger=new CUserFunctionRightDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_AccountTrigger=new CAccountDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_UserCommFluxTrigger=new CUserCommFluxDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_MarketDataLogTrigger=new CMarketDataLogDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_UserSessionTrigger=new CUserSessionDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_MDSessionTrigger=new CMDSessionDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_LoginInfoTrigger=new CLoginInfoDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_DepthMarketDataDetailTrigger=new CDepthMarketDataDetailDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_InstrumentStatusDetailTrigger=new CInstrumentStatusDetailDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_FrontStatusTrigger=new CFrontStatusDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_MaxLocalIDTrigger=new CMaxLocalIDDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_BulletinTrigger=new CBulletinDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_MarketDataModifyTrigger=new CMarketDataModifyDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_DepthMarketDataTrigger=new CDepthMarketDataDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_TopicMarketDataTrigger=new CTopicMarketDataDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_TopicMarketDataVersionTrigger=new CTopicMarketDataVersionDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_InformationTrigger=new CInformationDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_OrderCountTrigger=new COrderCountDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_InstrumentTrigger=new CInstrumentDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_CombinationLegTrigger=new CCombinationLegDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_PartRoleAccountTrigger=new CPartRoleAccountDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_PartProductRoleTrigger=new CPartProductRoleDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_PartProductRightTrigger=new CPartProductRightDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_PartInstrumentRightTrigger=new CPartInstrumentRightDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_ClientProductRightTrigger=new CClientProductRightDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_ClientInstrumentRightTrigger=new CClientInstrumentRightDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_PartClientProductRightTrigger=new CPartClientProductRightDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_PartClientInstrumentRightTrigger=new CPartClientInstrumentRightDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_CurrProductPropertyTrigger=new CCurrProductPropertyDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_CurrInstrumentPropertyTrigger=new CCurrInstrumentPropertyDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_CurrPriceBandingTrigger=new CCurrPriceBandingDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_CurrMarginRateTrigger=new CCurrMarginRateDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_CurrMarginRateDetailTrigger=new CCurrMarginRateDetailDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_CurrPartPosiLimitTrigger=new CCurrPartPosiLimitDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_CurrPartPosiLimitDetailTrigger=new CCurrPartPosiLimitDetailDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_CurrClientPosiLimitTrigger=new CCurrClientPosiLimitDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_CurrClientPosiLimitDetailTrigger=new CCurrClientPosiLimitDetailDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_CurrSpecialPosiLimitTrigger=new CCurrSpecialPosiLimitDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_CurrSpecialPosiLimitDetailTrigger=new CCurrSpecialPosiLimitDetailDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_CurrHedgeRuleTrigger=new CCurrHedgeRuleDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_CurrTradingSegmentAttrTrigger=new CCurrTradingSegmentAttrDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_CurrFuseTrigger=new CCurrFuseDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_TradingAccountTrigger=new CTradingAccountDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_BaseReserveAccountTrigger=new CBaseReserveAccountDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_PartPositionTrigger=new CPartPositionDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_ClientPositionTrigger=new CClientPositionDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_HedgeVolumeTrigger=new CHedgeVolumeDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_RemainOrderTrigger=new CRemainOrderDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_MarketDataTrigger=new CMarketDataDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_ClearingPartPositionTrigger=new CClearingPartPositionDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_InstrumentStatusTrigger=new CInstrumentStatusDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_OrderTrigger=new COrderDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_CombOrderTrigger=new CCombOrderDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_OTCOrderTrigger=new COTCOrderDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_ImplyOrderTrigger=new CImplyOrderDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_QuoteTrigger=new CQuoteDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_MBLMarketDataTrigger=new CMBLMarketDataDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_TradeTrigger=new CTradeDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_FusePhaseTrigger=new CFusePhaseDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_ExecOrderTrigger=new CExecOrderDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_UniPressureTrigger=new CUniPressureDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_BasePriceLimitTrigger=new CBasePriceLimitDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_CreditLimitTrigger=new CCreditLimitDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_CurrInstrumentOptionTrigger=new CCurrInstrumentOptionDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
}

CDumpLog::~CDumpLog(void)
{
	stop();
	if (m_DumpOutput==NULL)
	{
		return;
	}
	delete m_ExchangeDataSyncStatusTrigger;
	delete m_SGDataSyncStatusTrigger;
	delete m_CurrentTimeTrigger;
	delete m_DataCenterDescTrigger;
	delete m_ExchangeTrigger;
	delete m_SettlementGroupTrigger;
	delete m_MarketTrigger;
	delete m_MarketProductTrigger;
	delete m_MarketProductGroupTrigger;
	delete m_MdPubStatusTrigger;
	delete m_MarketDataTopicTrigger;
	delete m_PartTopicSubscribeTrigger;
	delete m_ParticipantTrigger;
	delete m_UserTrigger;
	delete m_ClientTrigger;
	delete m_UserIPTrigger;
	delete m_PartClientTrigger;
	delete m_ClearingTradingPartTrigger;
	delete m_AliasDefineTrigger;
	delete m_UserFunctionRightTrigger;
	delete m_AccountTrigger;
	delete m_UserCommFluxTrigger;
	delete m_MarketDataLogTrigger;
	delete m_UserSessionTrigger;
	delete m_MDSessionTrigger;
	delete m_LoginInfoTrigger;
	delete m_DepthMarketDataDetailTrigger;
	delete m_InstrumentStatusDetailTrigger;
	delete m_FrontStatusTrigger;
	delete m_MaxLocalIDTrigger;
	delete m_BulletinTrigger;
	delete m_MarketDataModifyTrigger;
	delete m_DepthMarketDataTrigger;
	delete m_TopicMarketDataTrigger;
	delete m_TopicMarketDataVersionTrigger;
	delete m_InformationTrigger;
	delete m_OrderCountTrigger;
	delete m_InstrumentTrigger;
	delete m_CombinationLegTrigger;
	delete m_PartRoleAccountTrigger;
	delete m_PartProductRoleTrigger;
	delete m_PartProductRightTrigger;
	delete m_PartInstrumentRightTrigger;
	delete m_ClientProductRightTrigger;
	delete m_ClientInstrumentRightTrigger;
	delete m_PartClientProductRightTrigger;
	delete m_PartClientInstrumentRightTrigger;
	delete m_CurrProductPropertyTrigger;
	delete m_CurrInstrumentPropertyTrigger;
	delete m_CurrPriceBandingTrigger;
	delete m_CurrMarginRateTrigger;
	delete m_CurrMarginRateDetailTrigger;
	delete m_CurrPartPosiLimitTrigger;
	delete m_CurrPartPosiLimitDetailTrigger;
	delete m_CurrClientPosiLimitTrigger;
	delete m_CurrClientPosiLimitDetailTrigger;
	delete m_CurrSpecialPosiLimitTrigger;
	delete m_CurrSpecialPosiLimitDetailTrigger;
	delete m_CurrHedgeRuleTrigger;
	delete m_CurrTradingSegmentAttrTrigger;
	delete m_CurrFuseTrigger;
	delete m_TradingAccountTrigger;
	delete m_BaseReserveAccountTrigger;
	delete m_PartPositionTrigger;
	delete m_ClientPositionTrigger;
	delete m_HedgeVolumeTrigger;
	delete m_RemainOrderTrigger;
	delete m_MarketDataTrigger;
	delete m_ClearingPartPositionTrigger;
	delete m_InstrumentStatusTrigger;
	delete m_OrderTrigger;
	delete m_CombOrderTrigger;
	delete m_OTCOrderTrigger;
	delete m_ImplyOrderTrigger;
	delete m_QuoteTrigger;
	delete m_MBLMarketDataTrigger;
	delete m_TradeTrigger;
	delete m_FusePhaseTrigger;
	delete m_ExecOrderTrigger;
	delete m_UniPressureTrigger;
	delete m_BasePriceLimitTrigger;
	delete m_CreditLimitTrigger;
	delete m_CurrInstrumentOptionTrigger;
	if ((m_DumpOutput!=NULL)&&(m_DumpOutput!=stdout)&&(m_DumpOutput!=stderr))
	{
		fclose(m_DumpOutput);
	}
}

int CDumpLog::isStarted(void)
{
	return m_Started;
}

void CDumpLog::start(void)
{
	if (m_Started)
	{
		return;
	}
	if (m_DumpOutput==NULL)
	{
		return;
	}
	m_DB->m_ExchangeDataSyncStatusFactory->addActionTrigger(m_ExchangeDataSyncStatusTrigger);
	m_DB->m_SGDataSyncStatusFactory->addActionTrigger(m_SGDataSyncStatusTrigger);
	m_DB->m_CurrentTimeFactory->addActionTrigger(m_CurrentTimeTrigger);
	m_DB->m_DataCenterDescFactory->addActionTrigger(m_DataCenterDescTrigger);
	m_DB->m_ExchangeFactory->addActionTrigger(m_ExchangeTrigger);
	m_DB->m_SettlementGroupFactory->addActionTrigger(m_SettlementGroupTrigger);
	m_DB->m_MarketFactory->addActionTrigger(m_MarketTrigger);
	m_DB->m_MarketProductFactory->addActionTrigger(m_MarketProductTrigger);
	m_DB->m_MarketProductGroupFactory->addActionTrigger(m_MarketProductGroupTrigger);
	m_DB->m_MdPubStatusFactory->addActionTrigger(m_MdPubStatusTrigger);
	m_DB->m_MarketDataTopicFactory->addActionTrigger(m_MarketDataTopicTrigger);
	m_DB->m_PartTopicSubscribeFactory->addActionTrigger(m_PartTopicSubscribeTrigger);
	m_DB->m_ParticipantFactory->addActionTrigger(m_ParticipantTrigger);
	m_DB->m_UserFactory->addActionTrigger(m_UserTrigger);
	m_DB->m_ClientFactory->addActionTrigger(m_ClientTrigger);
	m_DB->m_UserIPFactory->addActionTrigger(m_UserIPTrigger);
	m_DB->m_PartClientFactory->addActionTrigger(m_PartClientTrigger);
	m_DB->m_ClearingTradingPartFactory->addActionTrigger(m_ClearingTradingPartTrigger);
	m_DB->m_AliasDefineFactory->addActionTrigger(m_AliasDefineTrigger);
	m_DB->m_UserFunctionRightFactory->addActionTrigger(m_UserFunctionRightTrigger);
	m_DB->m_AccountFactory->addActionTrigger(m_AccountTrigger);
	m_DB->m_UserCommFluxFactory->addActionTrigger(m_UserCommFluxTrigger);
	m_DB->m_MarketDataLogFactory->addActionTrigger(m_MarketDataLogTrigger);
	m_DB->m_UserSessionFactory->addActionTrigger(m_UserSessionTrigger);
	m_DB->m_MDSessionFactory->addActionTrigger(m_MDSessionTrigger);
	m_DB->m_LoginInfoFactory->addActionTrigger(m_LoginInfoTrigger);
	m_DB->m_DepthMarketDataDetailFactory->addActionTrigger(m_DepthMarketDataDetailTrigger);
	m_DB->m_InstrumentStatusDetailFactory->addActionTrigger(m_InstrumentStatusDetailTrigger);
	m_DB->m_FrontStatusFactory->addActionTrigger(m_FrontStatusTrigger);
	m_DB->m_MaxLocalIDFactory->addActionTrigger(m_MaxLocalIDTrigger);
	m_DB->m_BulletinFactory->addActionTrigger(m_BulletinTrigger);
	m_DB->m_MarketDataModifyFactory->addActionTrigger(m_MarketDataModifyTrigger);
	m_DB->m_DepthMarketDataFactory->addActionTrigger(m_DepthMarketDataTrigger);
	m_DB->m_TopicMarketDataFactory->addActionTrigger(m_TopicMarketDataTrigger);
	m_DB->m_TopicMarketDataVersionFactory->addActionTrigger(m_TopicMarketDataVersionTrigger);
	m_DB->m_InformationFactory->addActionTrigger(m_InformationTrigger);
	m_DB->m_OrderCountFactory->addActionTrigger(m_OrderCountTrigger);
	m_DB->m_InstrumentFactory->addActionTrigger(m_InstrumentTrigger);
	m_DB->m_CombinationLegFactory->addActionTrigger(m_CombinationLegTrigger);
	m_DB->m_PartRoleAccountFactory->addActionTrigger(m_PartRoleAccountTrigger);
	m_DB->m_PartProductRoleFactory->addActionTrigger(m_PartProductRoleTrigger);
	m_DB->m_PartProductRightFactory->addActionTrigger(m_PartProductRightTrigger);
	m_DB->m_PartInstrumentRightFactory->addActionTrigger(m_PartInstrumentRightTrigger);
	m_DB->m_ClientProductRightFactory->addActionTrigger(m_ClientProductRightTrigger);
	m_DB->m_ClientInstrumentRightFactory->addActionTrigger(m_ClientInstrumentRightTrigger);
	m_DB->m_PartClientProductRightFactory->addActionTrigger(m_PartClientProductRightTrigger);
	m_DB->m_PartClientInstrumentRightFactory->addActionTrigger(m_PartClientInstrumentRightTrigger);
	m_DB->m_CurrProductPropertyFactory->addActionTrigger(m_CurrProductPropertyTrigger);
	m_DB->m_CurrInstrumentPropertyFactory->addActionTrigger(m_CurrInstrumentPropertyTrigger);
	m_DB->m_CurrPriceBandingFactory->addActionTrigger(m_CurrPriceBandingTrigger);
	m_DB->m_CurrMarginRateFactory->addActionTrigger(m_CurrMarginRateTrigger);
	m_DB->m_CurrMarginRateDetailFactory->addActionTrigger(m_CurrMarginRateDetailTrigger);
	m_DB->m_CurrPartPosiLimitFactory->addActionTrigger(m_CurrPartPosiLimitTrigger);
	m_DB->m_CurrPartPosiLimitDetailFactory->addActionTrigger(m_CurrPartPosiLimitDetailTrigger);
	m_DB->m_CurrClientPosiLimitFactory->addActionTrigger(m_CurrClientPosiLimitTrigger);
	m_DB->m_CurrClientPosiLimitDetailFactory->addActionTrigger(m_CurrClientPosiLimitDetailTrigger);
	m_DB->m_CurrSpecialPosiLimitFactory->addActionTrigger(m_CurrSpecialPosiLimitTrigger);
	m_DB->m_CurrSpecialPosiLimitDetailFactory->addActionTrigger(m_CurrSpecialPosiLimitDetailTrigger);
	m_DB->m_CurrHedgeRuleFactory->addActionTrigger(m_CurrHedgeRuleTrigger);
	m_DB->m_CurrTradingSegmentAttrFactory->addActionTrigger(m_CurrTradingSegmentAttrTrigger);
	m_DB->m_CurrFuseFactory->addActionTrigger(m_CurrFuseTrigger);
	m_DB->m_TradingAccountFactory->addActionTrigger(m_TradingAccountTrigger);
	m_DB->m_BaseReserveAccountFactory->addActionTrigger(m_BaseReserveAccountTrigger);
	m_DB->m_PartPositionFactory->addActionTrigger(m_PartPositionTrigger);
	m_DB->m_ClientPositionFactory->addActionTrigger(m_ClientPositionTrigger);
	m_DB->m_HedgeVolumeFactory->addActionTrigger(m_HedgeVolumeTrigger);
	m_DB->m_RemainOrderFactory->addActionTrigger(m_RemainOrderTrigger);
	m_DB->m_MarketDataFactory->addActionTrigger(m_MarketDataTrigger);
	m_DB->m_ClearingPartPositionFactory->addActionTrigger(m_ClearingPartPositionTrigger);
	m_DB->m_InstrumentStatusFactory->addActionTrigger(m_InstrumentStatusTrigger);
	m_DB->m_OrderFactory->addActionTrigger(m_OrderTrigger);
	m_DB->m_CombOrderFactory->addActionTrigger(m_CombOrderTrigger);
	m_DB->m_OTCOrderFactory->addActionTrigger(m_OTCOrderTrigger);
	m_DB->m_ImplyOrderFactory->addActionTrigger(m_ImplyOrderTrigger);
	m_DB->m_QuoteFactory->addActionTrigger(m_QuoteTrigger);
	m_DB->m_MBLMarketDataFactory->addActionTrigger(m_MBLMarketDataTrigger);
	m_DB->m_TradeFactory->addActionTrigger(m_TradeTrigger);
	m_DB->m_FusePhaseFactory->addActionTrigger(m_FusePhaseTrigger);
	m_DB->m_ExecOrderFactory->addActionTrigger(m_ExecOrderTrigger);
	m_DB->m_UniPressureFactory->addActionTrigger(m_UniPressureTrigger);
	m_DB->m_BasePriceLimitFactory->addActionTrigger(m_BasePriceLimitTrigger);
	m_DB->m_CreditLimitFactory->addActionTrigger(m_CreditLimitTrigger);
	m_DB->m_CurrInstrumentOptionFactory->addActionTrigger(m_CurrInstrumentOptionTrigger);
}

void CDumpLog::stop()
{
	if (!m_Started)
	{
		return;
	}
	if (m_DumpOutput==NULL)
	{
		return;
	}
	m_DB->m_ExchangeDataSyncStatusFactory->removeActionTrigger(m_ExchangeDataSyncStatusTrigger);
	m_DB->m_SGDataSyncStatusFactory->removeActionTrigger(m_SGDataSyncStatusTrigger);
	m_DB->m_CurrentTimeFactory->removeActionTrigger(m_CurrentTimeTrigger);
	m_DB->m_DataCenterDescFactory->removeActionTrigger(m_DataCenterDescTrigger);
	m_DB->m_ExchangeFactory->removeActionTrigger(m_ExchangeTrigger);
	m_DB->m_SettlementGroupFactory->removeActionTrigger(m_SettlementGroupTrigger);
	m_DB->m_MarketFactory->removeActionTrigger(m_MarketTrigger);
	m_DB->m_MarketProductFactory->removeActionTrigger(m_MarketProductTrigger);
	m_DB->m_MarketProductGroupFactory->removeActionTrigger(m_MarketProductGroupTrigger);
	m_DB->m_MdPubStatusFactory->removeActionTrigger(m_MdPubStatusTrigger);
	m_DB->m_MarketDataTopicFactory->removeActionTrigger(m_MarketDataTopicTrigger);
	m_DB->m_PartTopicSubscribeFactory->removeActionTrigger(m_PartTopicSubscribeTrigger);
	m_DB->m_ParticipantFactory->removeActionTrigger(m_ParticipantTrigger);
	m_DB->m_UserFactory->removeActionTrigger(m_UserTrigger);
	m_DB->m_ClientFactory->removeActionTrigger(m_ClientTrigger);
	m_DB->m_UserIPFactory->removeActionTrigger(m_UserIPTrigger);
	m_DB->m_PartClientFactory->removeActionTrigger(m_PartClientTrigger);
	m_DB->m_ClearingTradingPartFactory->removeActionTrigger(m_ClearingTradingPartTrigger);
	m_DB->m_AliasDefineFactory->removeActionTrigger(m_AliasDefineTrigger);
	m_DB->m_UserFunctionRightFactory->removeActionTrigger(m_UserFunctionRightTrigger);
	m_DB->m_AccountFactory->removeActionTrigger(m_AccountTrigger);
	m_DB->m_UserCommFluxFactory->removeActionTrigger(m_UserCommFluxTrigger);
	m_DB->m_MarketDataLogFactory->removeActionTrigger(m_MarketDataLogTrigger);
	m_DB->m_UserSessionFactory->removeActionTrigger(m_UserSessionTrigger);
	m_DB->m_MDSessionFactory->removeActionTrigger(m_MDSessionTrigger);
	m_DB->m_LoginInfoFactory->removeActionTrigger(m_LoginInfoTrigger);
	m_DB->m_DepthMarketDataDetailFactory->removeActionTrigger(m_DepthMarketDataDetailTrigger);
	m_DB->m_InstrumentStatusDetailFactory->removeActionTrigger(m_InstrumentStatusDetailTrigger);
	m_DB->m_FrontStatusFactory->removeActionTrigger(m_FrontStatusTrigger);
	m_DB->m_MaxLocalIDFactory->removeActionTrigger(m_MaxLocalIDTrigger);
	m_DB->m_BulletinFactory->removeActionTrigger(m_BulletinTrigger);
	m_DB->m_MarketDataModifyFactory->removeActionTrigger(m_MarketDataModifyTrigger);
	m_DB->m_DepthMarketDataFactory->removeActionTrigger(m_DepthMarketDataTrigger);
	m_DB->m_TopicMarketDataFactory->removeActionTrigger(m_TopicMarketDataTrigger);
	m_DB->m_TopicMarketDataVersionFactory->removeActionTrigger(m_TopicMarketDataVersionTrigger);
	m_DB->m_InformationFactory->removeActionTrigger(m_InformationTrigger);
	m_DB->m_OrderCountFactory->removeActionTrigger(m_OrderCountTrigger);
	m_DB->m_InstrumentFactory->removeActionTrigger(m_InstrumentTrigger);
	m_DB->m_CombinationLegFactory->removeActionTrigger(m_CombinationLegTrigger);
	m_DB->m_PartRoleAccountFactory->removeActionTrigger(m_PartRoleAccountTrigger);
	m_DB->m_PartProductRoleFactory->removeActionTrigger(m_PartProductRoleTrigger);
	m_DB->m_PartProductRightFactory->removeActionTrigger(m_PartProductRightTrigger);
	m_DB->m_PartInstrumentRightFactory->removeActionTrigger(m_PartInstrumentRightTrigger);
	m_DB->m_ClientProductRightFactory->removeActionTrigger(m_ClientProductRightTrigger);
	m_DB->m_ClientInstrumentRightFactory->removeActionTrigger(m_ClientInstrumentRightTrigger);
	m_DB->m_PartClientProductRightFactory->removeActionTrigger(m_PartClientProductRightTrigger);
	m_DB->m_PartClientInstrumentRightFactory->removeActionTrigger(m_PartClientInstrumentRightTrigger);
	m_DB->m_CurrProductPropertyFactory->removeActionTrigger(m_CurrProductPropertyTrigger);
	m_DB->m_CurrInstrumentPropertyFactory->removeActionTrigger(m_CurrInstrumentPropertyTrigger);
	m_DB->m_CurrPriceBandingFactory->removeActionTrigger(m_CurrPriceBandingTrigger);
	m_DB->m_CurrMarginRateFactory->removeActionTrigger(m_CurrMarginRateTrigger);
	m_DB->m_CurrMarginRateDetailFactory->removeActionTrigger(m_CurrMarginRateDetailTrigger);
	m_DB->m_CurrPartPosiLimitFactory->removeActionTrigger(m_CurrPartPosiLimitTrigger);
	m_DB->m_CurrPartPosiLimitDetailFactory->removeActionTrigger(m_CurrPartPosiLimitDetailTrigger);
	m_DB->m_CurrClientPosiLimitFactory->removeActionTrigger(m_CurrClientPosiLimitTrigger);
	m_DB->m_CurrClientPosiLimitDetailFactory->removeActionTrigger(m_CurrClientPosiLimitDetailTrigger);
	m_DB->m_CurrSpecialPosiLimitFactory->removeActionTrigger(m_CurrSpecialPosiLimitTrigger);
	m_DB->m_CurrSpecialPosiLimitDetailFactory->removeActionTrigger(m_CurrSpecialPosiLimitDetailTrigger);
	m_DB->m_CurrHedgeRuleFactory->removeActionTrigger(m_CurrHedgeRuleTrigger);
	m_DB->m_CurrTradingSegmentAttrFactory->removeActionTrigger(m_CurrTradingSegmentAttrTrigger);
	m_DB->m_CurrFuseFactory->removeActionTrigger(m_CurrFuseTrigger);
	m_DB->m_TradingAccountFactory->removeActionTrigger(m_TradingAccountTrigger);
	m_DB->m_BaseReserveAccountFactory->removeActionTrigger(m_BaseReserveAccountTrigger);
	m_DB->m_PartPositionFactory->removeActionTrigger(m_PartPositionTrigger);
	m_DB->m_ClientPositionFactory->removeActionTrigger(m_ClientPositionTrigger);
	m_DB->m_HedgeVolumeFactory->removeActionTrigger(m_HedgeVolumeTrigger);
	m_DB->m_RemainOrderFactory->removeActionTrigger(m_RemainOrderTrigger);
	m_DB->m_MarketDataFactory->removeActionTrigger(m_MarketDataTrigger);
	m_DB->m_ClearingPartPositionFactory->removeActionTrigger(m_ClearingPartPositionTrigger);
	m_DB->m_InstrumentStatusFactory->removeActionTrigger(m_InstrumentStatusTrigger);
	m_DB->m_OrderFactory->removeActionTrigger(m_OrderTrigger);
	m_DB->m_CombOrderFactory->removeActionTrigger(m_CombOrderTrigger);
	m_DB->m_OTCOrderFactory->removeActionTrigger(m_OTCOrderTrigger);
	m_DB->m_ImplyOrderFactory->removeActionTrigger(m_ImplyOrderTrigger);
	m_DB->m_QuoteFactory->removeActionTrigger(m_QuoteTrigger);
	m_DB->m_MBLMarketDataFactory->removeActionTrigger(m_MBLMarketDataTrigger);
	m_DB->m_TradeFactory->removeActionTrigger(m_TradeTrigger);
	m_DB->m_FusePhaseFactory->removeActionTrigger(m_FusePhaseTrigger);
	m_DB->m_ExecOrderFactory->removeActionTrigger(m_ExecOrderTrigger);
	m_DB->m_UniPressureFactory->removeActionTrigger(m_UniPressureTrigger);
	m_DB->m_BasePriceLimitFactory->removeActionTrigger(m_BasePriceLimitTrigger);
	m_DB->m_CreditLimitFactory->removeActionTrigger(m_CreditLimitTrigger);
	m_DB->m_CurrInstrumentOptionFactory->removeActionTrigger(m_CurrInstrumentOptionTrigger);
}

void CDumpLog::dumpMsg(char *format,...)
{
	va_list v;
	
	if (!m_Started)
	{
		return;
	}
	
	va_start(v,format);
	vfprintf(m_DumpOutput,format,v);
	va_end(v);
	fflush(m_DumpOutput);
}

