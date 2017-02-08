/////////////////////////////////////////////////////////////////////////
///@system 执行引擎系统
///@company 上海期货信息技术有限公司
///@file databaseFactories.h
///@brief定义了若干个内存数据库的对象工厂
///@history 
///20060127	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef DATABASEFACTORIES_H
#define DATABASEFACTORIES_H

#include "platform.h"
#include "CBaseObject.h"
#include "CConfig.h"
#include "CAVLTree.h"
#include "CHashIndex.h"
#include "customDataType.h"
#include "CDatabaseDataFactory.h"
#include "CTransaction.h"
#include "BaseDataStruct.h"
#include "CDatabaseResource.h"
#include "Allocator.h"

class CExchangeDataSyncStatusFactory;
class CExchangeDataSyncStatusResource;
class CSGDataSyncStatusFactory;
class CSGDataSyncStatusResource;
class CCurrentTimeFactory;
class CCurrentTimeResource;
class CDataCenterDescFactory;
class CDataCenterDescResource;
class CExchangeFactory;
class CExchangeResource;
class CSettlementGroupFactory;
class CSettlementGroupResource;
class CMarketFactory;
class CMarketResource;
class CMarketProductFactory;
class CMarketProductResource;
class CMarketProductGroupFactory;
class CMarketProductGroupResource;
class CMdPubStatusFactory;
class CMdPubStatusResource;
class CMarketDataTopicFactory;
class CMarketDataTopicResource;
class CPartTopicSubscribeFactory;
class CPartTopicSubscribeResource;
class CParticipantFactory;
class CParticipantResource;
class CUserFactory;
class CUserResource;
class CClientFactory;
class CClientResource;
class CUserIPFactory;
class CUserIPResource;
class CPartClientFactory;
class CPartClientResource;
class CClearingTradingPartFactory;
class CClearingTradingPartResource;
class CAliasDefineFactory;
class CAliasDefineResource;
class CUserFunctionRightFactory;
class CUserFunctionRightResource;
class CAccountFactory;
class CAccountResource;
class CUserCommFluxFactory;
class CUserCommFluxResource;
class CMarketDataLogFactory;
class CMarketDataLogResource;
class CUserSessionFactory;
class CUserSessionResource;
class CMDSessionFactory;
class CMDSessionResource;
class CLoginInfoFactory;
class CLoginInfoResource;
class CDepthMarketDataDetailFactory;
class CDepthMarketDataDetailResource;
class CInstrumentStatusDetailFactory;
class CInstrumentStatusDetailResource;
class CFrontStatusFactory;
class CFrontStatusResource;
class CMaxLocalIDFactory;
class CMaxLocalIDResource;
class CBulletinFactory;
class CBulletinResource;
class CMarketDataModifyFactory;
class CMarketDataModifyResource;
class CDepthMarketDataFactory;
class CDepthMarketDataResource;
class CTopicMarketDataFactory;
class CTopicMarketDataResource;
class CTopicMarketDataVersionFactory;
class CTopicMarketDataVersionResource;
class CInformationFactory;
class CInformationResource;
class COrderCountFactory;
class COrderCountResource;
class CInstrumentFactory;
class CInstrumentResource;
class CCombinationLegFactory;
class CCombinationLegResource;
class CPartRoleAccountFactory;
class CPartRoleAccountResource;
class CPartProductRoleFactory;
class CPartProductRoleResource;
class CPartProductRightFactory;
class CPartProductRightResource;
class CPartInstrumentRightFactory;
class CPartInstrumentRightResource;
class CClientProductRightFactory;
class CClientProductRightResource;
class CClientInstrumentRightFactory;
class CClientInstrumentRightResource;
class CPartClientProductRightFactory;
class CPartClientProductRightResource;
class CPartClientInstrumentRightFactory;
class CPartClientInstrumentRightResource;
class CCurrProductPropertyFactory;
class CCurrProductPropertyResource;
class CCurrInstrumentPropertyFactory;
class CCurrInstrumentPropertyResource;
class CCurrPriceBandingFactory;
class CCurrPriceBandingResource;
class CCurrMarginRateFactory;
class CCurrMarginRateResource;
class CCurrMarginRateDetailFactory;
class CCurrMarginRateDetailResource;
class CCurrPartPosiLimitFactory;
class CCurrPartPosiLimitResource;
class CCurrPartPosiLimitDetailFactory;
class CCurrPartPosiLimitDetailResource;
class CCurrClientPosiLimitFactory;
class CCurrClientPosiLimitResource;
class CCurrClientPosiLimitDetailFactory;
class CCurrClientPosiLimitDetailResource;
class CCurrSpecialPosiLimitFactory;
class CCurrSpecialPosiLimitResource;
class CCurrSpecialPosiLimitDetailFactory;
class CCurrSpecialPosiLimitDetailResource;
class CCurrHedgeRuleFactory;
class CCurrHedgeRuleResource;
class CCurrTradingSegmentAttrFactory;
class CCurrTradingSegmentAttrResource;
class CCurrFuseFactory;
class CCurrFuseResource;
class CTradingAccountFactory;
class CTradingAccountResource;
class CBaseReserveAccountFactory;
class CBaseReserveAccountResource;
class CPartPositionFactory;
class CPartPositionResource;
class CClientPositionFactory;
class CClientPositionResource;
class CHedgeVolumeFactory;
class CHedgeVolumeResource;
class CRemainOrderFactory;
class CRemainOrderResource;
class CMarketDataFactory;
class CMarketDataResource;
class CClearingPartPositionFactory;
class CClearingPartPositionResource;
class CInstrumentStatusFactory;
class CInstrumentStatusResource;
class COrderFactory;
class COrderResource;
class CCombOrderFactory;
class CCombOrderResource;
class COTCOrderFactory;
class COTCOrderResource;
class CImplyOrderFactory;
class CImplyOrderResource;
class CQuoteFactory;
class CQuoteResource;
class CMBLMarketDataFactory;
class CMBLMarketDataResource;
class CTradeFactory;
class CTradeResource;
class CFusePhaseFactory;
class CFusePhaseResource;
class CExecOrderFactory;
class CExecOrderResource;
class CUniPressureFactory;
class CUniPressureResource;
class CBasePriceLimitFactory;
class CBasePriceLimitResource;
class CCreditLimitFactory;
class CCreditLimitResource;
class CHedgeDetailFactory;
class CHedgeDetailResource;
class COrderActionFactory;
class COrderActionResource;
class CQuoteActionFactory;
class CQuoteActionResource;
class CExecOrderActionFactory;
class CExecOrderActionResource;
class CAccountDepositFactory;
class CAccountDepositResource;
class CUpdateAllInstrumentStatusFactory;
class CUpdateAllInstrumentStatusResource;
class CAdminOrderFactory;
class CAdminOrderResource;
class CCommPhaseFactory;
class CCommPhaseResource;
class CCurrHedgeFactory;
class CCurrHedgeResource;
class CCurrInstrumentOptionFactory;
class CCurrInstrumentOptionResource;

/////////////////////////////////////////////////////////////////////////
///CExchangeDataSyncStatusFactory是一个交易所数据同步状态的对象工厂。它包含了一批交易所数据同步状态，
///同时又建立了如下索引，以方便查询：
///	ExchangeIDIndex
///使用本对象工厂，可以完成对交易所数据同步状态的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByExchangeID，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeDataSyncStatusFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CExchangeDataSyncStatusFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxExchangeDataSyncStatus，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CExchangeDataSyncStatusFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CExchangeDataSyncStatusFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的ExchangeDataSyncStatus
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的ExchangeDataSyncStatus，文件名将根据配置文件中的定义ExchangeDataSyncStatusCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的ExchangeDataSyncStatus
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的ExchangeDataSyncStatus，文件名将根据配置文件中的定义ExchangeDataSyncStatusCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CExchangeDataSyncStatusResource;

	///将一个CExchangeDataSyncStatus加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pExchangeDataSyncStatus	要加入的ExchangeDataSyncStatus
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CExchangeDataSyncStatus *add(CWriteableExchangeDataSyncStatus *pExchangeDataSyncStatus, CTransaction *pTransaction=NULL);
	
	///刷新该CExchangeDataSyncStatus的值
	///@param	pExchangeDataSyncStatus	被刷新的CExchangeDataSyncStatus
	///@param	pNewExchangeDataSyncStatus	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CExchangeDataSyncStatus *pExchangeDataSyncStatus, CWriteableExchangeDataSyncStatus *pNewExchangeDataSyncStatus, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pExchangeDataSyncStatus	  需要被刷新或者新增的CExchangeDataSyncStatus,等于NULL表示是需要新增的
	///@param	pNewExchangeDataSyncStatus	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CExchangeDataSyncStatus* addOrUpdate(CExchangeDataSyncStatus *pExchangeDataSyncStatus, CWriteableExchangeDataSyncStatus *pNewExchangeDataSyncStatus, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CExchangeDataSyncStatus，同时删除其索引
	///@param	pExchangeDataSyncStatus	要删除的CExchangeDataSyncStatus
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CExchangeDataSyncStatus *pExchangeDataSyncStatus, CTransaction *pTransaction=NULL);
	
	///获取某个CExchangeDataSyncStatus
	///@param	pExchangeDataSyncStatus	要读取的CExchangeDataSyncStatus
	///@param	pTragetExchangeDataSyncStatus	存放结果的CExchangeDataSyncStatus
	void retrieve(CExchangeDataSyncStatus *pExchangeDataSyncStatus, CWriteableExchangeDataSyncStatus *pTargetExchangeDataSyncStatus);
	
	///获取第一个CExchangeDataSyncStatus
	///@return	得到的第一个CExchangeDataSyncStatus，如果没有，则返回NULL
	CExchangeDataSyncStatus *getFirst(void);
	
	///获取下一个CExchangeDataSyncStatus
	///@return	得到下一个CExchangeDataSyncStatus，如果没有，则返回NULL
	CExchangeDataSyncStatus *getNext(void);
	
	///结束获取CExchangeDataSyncStatus
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CExchangeDataSyncStatusActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CExchangeDataSyncStatusActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CExchangeDataSyncStatusCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CExchangeDataSyncStatusCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///寻找CExchangeDataSyncStatus
	///@param	ExchangeID	交易所代码
	///@return	找到的CExchangeDataSyncStatus，如果找不到，返回NULL
	CExchangeDataSyncStatus *findByExchangeID( const CReadOnlyExchangeIDType&  ExchangeID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CExchangeDataSyncStatus加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pExchangeDataSyncStatus	要加入的ExchangeDataSyncStatus
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CExchangeDataSyncStatus *internalAdd(CWriteableExchangeDataSyncStatus *pExchangeDataSyncStatus, bool bNoTransaction);
	
	
	///刷新该CExchangeDataSyncStatus的键值
	///@param	pExchangeDataSyncStatus	被刷新的CExchangeDataSyncStatus
	///@param	pNewExchangeDataSyncStatus	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CExchangeDataSyncStatus *pExchangeDataSyncStatus, CWriteableExchangeDataSyncStatus *pNewExchangeDataSyncStatus, bool updateIndex,bool bNoTransaction);
	
	///删除一个CExchangeDataSyncStatus，同时删除其索引
	///@param	pExchangeDataSyncStatus	要删除的CExchangeDataSyncStatus
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CExchangeDataSyncStatus *pExchangeDataSyncStatus, bool bNoTransaction);
/*
	///检查某个CExchangeDataSyncStatus是否属于本对象工厂
	///@param	pExchangeDataSyncStatus	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CExchangeDataSyncStatus *pExchangeDataSyncStatus);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ExchangeID的索引
	CAVLTree *pExchangeIDIndex;
	
	
	
	///加入前触发
	///@param	pExchangeDataSyncStatus	要加入的ExchangeDataSyncStatus
	virtual void beforeAdd(CWriteableExchangeDataSyncStatus *pExchangeDataSyncStatus);
	
	///加入后触发
	///@param	pExchangeDataSyncStatus	已经加入的ExchangeDataSyncStatus
	virtual void afterAdd(CExchangeDataSyncStatus *pExchangeDataSyncStatus);

	///更新前触发	
	///@param	pExchangeDataSyncStatus	被刷新的CExchangeDataSyncStatus
	///@param	pNewExchangeDataSyncStatus	新的值
	virtual void beforeUpdate(CExchangeDataSyncStatus *pExchangeDataSyncStatus, CWriteableExchangeDataSyncStatus *pNewExchangeDataSyncStatus);
	
	///更新后触发
	///@param	pExchangeDataSyncStatus	被刷新的CExchangeDataSyncStatus
	virtual void afterUpdate(CExchangeDataSyncStatus *pExchangeDataSyncStatus);
	
	///删除前触发
	///@param	pExchangeDataSyncStatus	要删除的CExchangeDataSyncStatus
	virtual void beforeRemove(CExchangeDataSyncStatus *pExchangeDataSyncStatus);
	
	///确认加入后触发
	///@param	pExchangeDataSyncStatus	已经加入的ExchangeDataSyncStatus
	virtual void commitAdd(CExchangeDataSyncStatus *pExchangeDataSyncStatus);

	///确认更新后触发
	///@param	pExchangeDataSyncStatus	被刷新的CExchangeDataSyncStatus
	///@param	poldExchangeDataSyncStatus	原来的值
	virtual void commitUpdate(CExchangeDataSyncStatus *pExchangeDataSyncStatus, CWriteableExchangeDataSyncStatus *pOldExchangeDataSyncStatus);
	
	///确认删除后触发
	///@param	pExchangeDataSyncStatus	已经删除的CExchangeDataSyncStatus
	virtual void commitRemove(CWriteableExchangeDataSyncStatus *pExchangeDataSyncStatus);

	///所有相关的触发器
	vector<CExchangeDataSyncStatusActionTrigger *> *pActionTriggers;
	vector<CExchangeDataSyncStatusCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableExchangeDataSyncStatus compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSGDataSyncStatusFactory是一个结算组数据同步状态的对象工厂。它包含了一批结算组数据同步状态，
///同时又建立了如下索引，以方便查询：
///	SettlementGroupIDIndex
///使用本对象工厂，可以完成对结算组数据同步状态的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findBySettlementGroupID，唯一找到对象
///		使用startFindStartBySettlementGroupID，findNextStartBySettlementGroupID和endFindStartBySettlementGroupID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSGDataSyncStatusFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSGDataSyncStatus，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSGDataSyncStatusFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSGDataSyncStatusFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SGDataSyncStatus
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SGDataSyncStatus，文件名将根据配置文件中的定义SGDataSyncStatusCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SGDataSyncStatus
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SGDataSyncStatus，文件名将根据配置文件中的定义SGDataSyncStatusCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSGDataSyncStatusResource;

	///将一个CSGDataSyncStatus加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSGDataSyncStatus	要加入的SGDataSyncStatus
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSGDataSyncStatus *add(CWriteableSGDataSyncStatus *pSGDataSyncStatus, CTransaction *pTransaction=NULL);
	
	///刷新该CSGDataSyncStatus的值
	///@param	pSGDataSyncStatus	被刷新的CSGDataSyncStatus
	///@param	pNewSGDataSyncStatus	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSGDataSyncStatus *pSGDataSyncStatus, CWriteableSGDataSyncStatus *pNewSGDataSyncStatus, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSGDataSyncStatus	  需要被刷新或者新增的CSGDataSyncStatus,等于NULL表示是需要新增的
	///@param	pNewSGDataSyncStatus	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSGDataSyncStatus* addOrUpdate(CSGDataSyncStatus *pSGDataSyncStatus, CWriteableSGDataSyncStatus *pNewSGDataSyncStatus, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSGDataSyncStatus，同时删除其索引
	///@param	pSGDataSyncStatus	要删除的CSGDataSyncStatus
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSGDataSyncStatus *pSGDataSyncStatus, CTransaction *pTransaction=NULL);
	
	///获取某个CSGDataSyncStatus
	///@param	pSGDataSyncStatus	要读取的CSGDataSyncStatus
	///@param	pTragetSGDataSyncStatus	存放结果的CSGDataSyncStatus
	void retrieve(CSGDataSyncStatus *pSGDataSyncStatus, CWriteableSGDataSyncStatus *pTargetSGDataSyncStatus);
	
	///获取第一个CSGDataSyncStatus
	///@return	得到的第一个CSGDataSyncStatus，如果没有，则返回NULL
	CSGDataSyncStatus *getFirst(void);
	
	///获取下一个CSGDataSyncStatus
	///@return	得到下一个CSGDataSyncStatus，如果没有，则返回NULL
	CSGDataSyncStatus *getNext(void);
	
	///结束获取CSGDataSyncStatus
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSGDataSyncStatusActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSGDataSyncStatusActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSGDataSyncStatusCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSGDataSyncStatusCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///寻找CSGDataSyncStatus
	///@param	SettlementGroupID	结算组代码
	///@return	找到的CSGDataSyncStatus，如果找不到，返回NULL
	CSGDataSyncStatus *findBySettlementGroupID( const CReadOnlySettlementGroupIDType&  SettlementGroupID);



	friend class CSGDataSyncStatusIteratorStartBySettlementGroupID;

	///开始寻找CSGDataSyncStatus
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CSGDataSyncStatus，如果找不到，返回NULL
	CSGDataSyncStatus *startFindStartBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CSGDataSyncStatus，必须在startFindStartBySettlementGroupID以后，endFindStartBySettlementGroupID之前叫用
	///@return	下一个满足条件CSGDataSyncStatus，如果已经没有一个满足要求了，则返回NULL
	CSGDataSyncStatus *findNextStartBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindStartBySettlementGroupID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSGDataSyncStatus加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSGDataSyncStatus	要加入的SGDataSyncStatus
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSGDataSyncStatus *internalAdd(CWriteableSGDataSyncStatus *pSGDataSyncStatus, bool bNoTransaction);
	
	
	///刷新该CSGDataSyncStatus的键值
	///@param	pSGDataSyncStatus	被刷新的CSGDataSyncStatus
	///@param	pNewSGDataSyncStatus	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSGDataSyncStatus *pSGDataSyncStatus, CWriteableSGDataSyncStatus *pNewSGDataSyncStatus, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSGDataSyncStatus，同时删除其索引
	///@param	pSGDataSyncStatus	要删除的CSGDataSyncStatus
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSGDataSyncStatus *pSGDataSyncStatus, bool bNoTransaction);
/*
	///检查某个CSGDataSyncStatus是否属于本对象工厂
	///@param	pSGDataSyncStatus	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSGDataSyncStatus *pSGDataSyncStatus);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于SettlementGroupID的索引
	CAVLTree *pSettlementGroupIDIndex;
	
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchStartBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchStartBySettlementGroupID;
	
	///加入前触发
	///@param	pSGDataSyncStatus	要加入的SGDataSyncStatus
	virtual void beforeAdd(CWriteableSGDataSyncStatus *pSGDataSyncStatus);
	
	///加入后触发
	///@param	pSGDataSyncStatus	已经加入的SGDataSyncStatus
	virtual void afterAdd(CSGDataSyncStatus *pSGDataSyncStatus);

	///更新前触发	
	///@param	pSGDataSyncStatus	被刷新的CSGDataSyncStatus
	///@param	pNewSGDataSyncStatus	新的值
	virtual void beforeUpdate(CSGDataSyncStatus *pSGDataSyncStatus, CWriteableSGDataSyncStatus *pNewSGDataSyncStatus);
	
	///更新后触发
	///@param	pSGDataSyncStatus	被刷新的CSGDataSyncStatus
	virtual void afterUpdate(CSGDataSyncStatus *pSGDataSyncStatus);
	
	///删除前触发
	///@param	pSGDataSyncStatus	要删除的CSGDataSyncStatus
	virtual void beforeRemove(CSGDataSyncStatus *pSGDataSyncStatus);
	
	///确认加入后触发
	///@param	pSGDataSyncStatus	已经加入的SGDataSyncStatus
	virtual void commitAdd(CSGDataSyncStatus *pSGDataSyncStatus);

	///确认更新后触发
	///@param	pSGDataSyncStatus	被刷新的CSGDataSyncStatus
	///@param	poldSGDataSyncStatus	原来的值
	virtual void commitUpdate(CSGDataSyncStatus *pSGDataSyncStatus, CWriteableSGDataSyncStatus *pOldSGDataSyncStatus);
	
	///确认删除后触发
	///@param	pSGDataSyncStatus	已经删除的CSGDataSyncStatus
	virtual void commitRemove(CWriteableSGDataSyncStatus *pSGDataSyncStatus);

	///所有相关的触发器
	vector<CSGDataSyncStatusActionTrigger *> *pActionTriggers;
	vector<CSGDataSyncStatusCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSGDataSyncStatus compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrentTimeFactory是一个当前时间的对象工厂。它包含了一批当前时间，
///同时又建立了如下索引，以方便查询：
///使用本对象工厂，可以完成对当前时间的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrentTimeFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrentTimeFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxCurrentTime，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrentTimeFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CCurrentTimeFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的CurrentTime
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的CurrentTime，文件名将根据配置文件中的定义CurrentTimeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的CurrentTime
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的CurrentTime，文件名将根据配置文件中的定义CurrentTimeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CCurrentTimeResource;

	///将一个CCurrentTime加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrentTime	要加入的CurrentTime
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrentTime *add(CWriteableCurrentTime *pCurrentTime, CTransaction *pTransaction=NULL);
	
	///刷新该CCurrentTime的值
	///@param	pCurrentTime	被刷新的CCurrentTime
	///@param	pNewCurrentTime	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CCurrentTime *pCurrentTime, CWriteableCurrentTime *pNewCurrentTime, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pCurrentTime	  需要被刷新或者新增的CCurrentTime,等于NULL表示是需要新增的
	///@param	pNewCurrentTime	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CCurrentTime* addOrUpdate(CCurrentTime *pCurrentTime, CWriteableCurrentTime *pNewCurrentTime, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CCurrentTime，同时删除其索引
	///@param	pCurrentTime	要删除的CCurrentTime
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CCurrentTime *pCurrentTime, CTransaction *pTransaction=NULL);
	
	///获取某个CCurrentTime
	///@param	pCurrentTime	要读取的CCurrentTime
	///@param	pTragetCurrentTime	存放结果的CCurrentTime
	void retrieve(CCurrentTime *pCurrentTime, CWriteableCurrentTime *pTargetCurrentTime);
	
	///获取第一个CCurrentTime
	///@return	得到的第一个CCurrentTime，如果没有，则返回NULL
	CCurrentTime *getFirst(void);
	
	///获取下一个CCurrentTime
	///@return	得到下一个CCurrentTime，如果没有，则返回NULL
	CCurrentTime *getNext(void);
	
	///结束获取CCurrentTime
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CCurrentTimeActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CCurrentTimeActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CCurrentTimeCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CCurrentTimeCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CCurrentTime加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrentTime	要加入的CurrentTime
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrentTime *internalAdd(CWriteableCurrentTime *pCurrentTime, bool bNoTransaction);
	
	
	///刷新该CCurrentTime的键值
	///@param	pCurrentTime	被刷新的CCurrentTime
	///@param	pNewCurrentTime	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CCurrentTime *pCurrentTime, CWriteableCurrentTime *pNewCurrentTime, bool updateIndex,bool bNoTransaction);
	
	///删除一个CCurrentTime，同时删除其索引
	///@param	pCurrentTime	要删除的CCurrentTime
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CCurrentTime *pCurrentTime, bool bNoTransaction);
/*
	///检查某个CCurrentTime是否属于本对象工厂
	///@param	pCurrentTime	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CCurrentTime *pCurrentTime);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	
	
	
	///加入前触发
	///@param	pCurrentTime	要加入的CurrentTime
	virtual void beforeAdd(CWriteableCurrentTime *pCurrentTime);
	
	///加入后触发
	///@param	pCurrentTime	已经加入的CurrentTime
	virtual void afterAdd(CCurrentTime *pCurrentTime);

	///更新前触发	
	///@param	pCurrentTime	被刷新的CCurrentTime
	///@param	pNewCurrentTime	新的值
	virtual void beforeUpdate(CCurrentTime *pCurrentTime, CWriteableCurrentTime *pNewCurrentTime);
	
	///更新后触发
	///@param	pCurrentTime	被刷新的CCurrentTime
	virtual void afterUpdate(CCurrentTime *pCurrentTime);
	
	///删除前触发
	///@param	pCurrentTime	要删除的CCurrentTime
	virtual void beforeRemove(CCurrentTime *pCurrentTime);
	
	///确认加入后触发
	///@param	pCurrentTime	已经加入的CurrentTime
	virtual void commitAdd(CCurrentTime *pCurrentTime);

	///确认更新后触发
	///@param	pCurrentTime	被刷新的CCurrentTime
	///@param	poldCurrentTime	原来的值
	virtual void commitUpdate(CCurrentTime *pCurrentTime, CWriteableCurrentTime *pOldCurrentTime);
	
	///确认删除后触发
	///@param	pCurrentTime	已经删除的CCurrentTime
	virtual void commitRemove(CWriteableCurrentTime *pCurrentTime);

	///所有相关的触发器
	vector<CCurrentTimeActionTrigger *> *pActionTriggers;
	vector<CCurrentTimeCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableCurrentTime compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CDataCenterDescFactory是一个数据中心描述的对象工厂。它包含了一批数据中心描述，
///同时又建立了如下索引，以方便查询：
///使用本对象工厂，可以完成对数据中心描述的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDataCenterDescFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CDataCenterDescFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxDataCenterDesc，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CDataCenterDescFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CDataCenterDescFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的DataCenterDesc
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的DataCenterDesc，文件名将根据配置文件中的定义DataCenterDescCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的DataCenterDesc
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的DataCenterDesc，文件名将根据配置文件中的定义DataCenterDescCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CDataCenterDescResource;

	///将一个CDataCenterDesc加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pDataCenterDesc	要加入的DataCenterDesc
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CDataCenterDesc *add(CWriteableDataCenterDesc *pDataCenterDesc, CTransaction *pTransaction=NULL);
	
	///刷新该CDataCenterDesc的值
	///@param	pDataCenterDesc	被刷新的CDataCenterDesc
	///@param	pNewDataCenterDesc	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CDataCenterDesc *pDataCenterDesc, CWriteableDataCenterDesc *pNewDataCenterDesc, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pDataCenterDesc	  需要被刷新或者新增的CDataCenterDesc,等于NULL表示是需要新增的
	///@param	pNewDataCenterDesc	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CDataCenterDesc* addOrUpdate(CDataCenterDesc *pDataCenterDesc, CWriteableDataCenterDesc *pNewDataCenterDesc, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CDataCenterDesc，同时删除其索引
	///@param	pDataCenterDesc	要删除的CDataCenterDesc
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CDataCenterDesc *pDataCenterDesc, CTransaction *pTransaction=NULL);
	
	///获取某个CDataCenterDesc
	///@param	pDataCenterDesc	要读取的CDataCenterDesc
	///@param	pTragetDataCenterDesc	存放结果的CDataCenterDesc
	void retrieve(CDataCenterDesc *pDataCenterDesc, CWriteableDataCenterDesc *pTargetDataCenterDesc);
	
	///获取第一个CDataCenterDesc
	///@return	得到的第一个CDataCenterDesc，如果没有，则返回NULL
	CDataCenterDesc *getFirst(void);
	
	///获取下一个CDataCenterDesc
	///@return	得到下一个CDataCenterDesc，如果没有，则返回NULL
	CDataCenterDesc *getNext(void);
	
	///结束获取CDataCenterDesc
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CDataCenterDescActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CDataCenterDescActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CDataCenterDescCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CDataCenterDescCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CDataCenterDesc加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pDataCenterDesc	要加入的DataCenterDesc
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CDataCenterDesc *internalAdd(CWriteableDataCenterDesc *pDataCenterDesc, bool bNoTransaction);
	
	
	///刷新该CDataCenterDesc的键值
	///@param	pDataCenterDesc	被刷新的CDataCenterDesc
	///@param	pNewDataCenterDesc	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CDataCenterDesc *pDataCenterDesc, CWriteableDataCenterDesc *pNewDataCenterDesc, bool updateIndex,bool bNoTransaction);
	
	///删除一个CDataCenterDesc，同时删除其索引
	///@param	pDataCenterDesc	要删除的CDataCenterDesc
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CDataCenterDesc *pDataCenterDesc, bool bNoTransaction);
/*
	///检查某个CDataCenterDesc是否属于本对象工厂
	///@param	pDataCenterDesc	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CDataCenterDesc *pDataCenterDesc);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	
	
	
	///加入前触发
	///@param	pDataCenterDesc	要加入的DataCenterDesc
	virtual void beforeAdd(CWriteableDataCenterDesc *pDataCenterDesc);
	
	///加入后触发
	///@param	pDataCenterDesc	已经加入的DataCenterDesc
	virtual void afterAdd(CDataCenterDesc *pDataCenterDesc);

	///更新前触发	
	///@param	pDataCenterDesc	被刷新的CDataCenterDesc
	///@param	pNewDataCenterDesc	新的值
	virtual void beforeUpdate(CDataCenterDesc *pDataCenterDesc, CWriteableDataCenterDesc *pNewDataCenterDesc);
	
	///更新后触发
	///@param	pDataCenterDesc	被刷新的CDataCenterDesc
	virtual void afterUpdate(CDataCenterDesc *pDataCenterDesc);
	
	///删除前触发
	///@param	pDataCenterDesc	要删除的CDataCenterDesc
	virtual void beforeRemove(CDataCenterDesc *pDataCenterDesc);
	
	///确认加入后触发
	///@param	pDataCenterDesc	已经加入的DataCenterDesc
	virtual void commitAdd(CDataCenterDesc *pDataCenterDesc);

	///确认更新后触发
	///@param	pDataCenterDesc	被刷新的CDataCenterDesc
	///@param	poldDataCenterDesc	原来的值
	virtual void commitUpdate(CDataCenterDesc *pDataCenterDesc, CWriteableDataCenterDesc *pOldDataCenterDesc);
	
	///确认删除后触发
	///@param	pDataCenterDesc	已经删除的CDataCenterDesc
	virtual void commitRemove(CWriteableDataCenterDesc *pDataCenterDesc);

	///所有相关的触发器
	vector<CDataCenterDescActionTrigger *> *pActionTriggers;
	vector<CDataCenterDescCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableDataCenterDesc compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CExchangeFactory是一个交易所的对象工厂。它包含了一批交易所，
///同时又建立了如下索引，以方便查询：
///使用本对象工厂，可以完成对交易所的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByExchangeID，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CExchangeFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxExchange，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CExchangeFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CExchangeFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的Exchange
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的Exchange，文件名将根据配置文件中的定义ExchangeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的Exchange
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的Exchange，文件名将根据配置文件中的定义ExchangeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CExchangeResource;

	///将一个CExchange加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pExchange	要加入的Exchange
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CExchange *add(CWriteableExchange *pExchange, CTransaction *pTransaction=NULL);
	
	///刷新该CExchange的值
	///@param	pExchange	被刷新的CExchange
	///@param	pNewExchange	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CExchange *pExchange, CWriteableExchange *pNewExchange, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pExchange	  需要被刷新或者新增的CExchange,等于NULL表示是需要新增的
	///@param	pNewExchange	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CExchange* addOrUpdate(CExchange *pExchange, CWriteableExchange *pNewExchange, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CExchange，同时删除其索引
	///@param	pExchange	要删除的CExchange
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CExchange *pExchange, CTransaction *pTransaction=NULL);
	
	///获取某个CExchange
	///@param	pExchange	要读取的CExchange
	///@param	pTragetExchange	存放结果的CExchange
	void retrieve(CExchange *pExchange, CWriteableExchange *pTargetExchange);
	
	///获取第一个CExchange
	///@return	得到的第一个CExchange，如果没有，则返回NULL
	CExchange *getFirst(void);
	
	///获取下一个CExchange
	///@return	得到下一个CExchange，如果没有，则返回NULL
	CExchange *getNext(void);
	
	///结束获取CExchange
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CExchangeActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CExchangeActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CExchangeCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CExchangeCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///寻找CExchange
	///@param	ExchangeID	交易所编号
	///@return	找到的CExchange，如果找不到，返回NULL
	CExchange *findByExchangeID( const CReadOnlyExchangeIDType&  ExchangeID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CExchange加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pExchange	要加入的Exchange
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CExchange *internalAdd(CWriteableExchange *pExchange, bool bNoTransaction);
	
	
	///刷新该CExchange的键值
	///@param	pExchange	被刷新的CExchange
	///@param	pNewExchange	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CExchange *pExchange, CWriteableExchange *pNewExchange, bool updateIndex,bool bNoTransaction);
	
	///删除一个CExchange，同时删除其索引
	///@param	pExchange	要删除的CExchange
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CExchange *pExchange, bool bNoTransaction);
/*
	///检查某个CExchange是否属于本对象工厂
	///@param	pExchange	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CExchange *pExchange);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	
	
	
	///加入前触发
	///@param	pExchange	要加入的Exchange
	virtual void beforeAdd(CWriteableExchange *pExchange);
	
	///加入后触发
	///@param	pExchange	已经加入的Exchange
	virtual void afterAdd(CExchange *pExchange);

	///更新前触发	
	///@param	pExchange	被刷新的CExchange
	///@param	pNewExchange	新的值
	virtual void beforeUpdate(CExchange *pExchange, CWriteableExchange *pNewExchange);
	
	///更新后触发
	///@param	pExchange	被刷新的CExchange
	virtual void afterUpdate(CExchange *pExchange);
	
	///删除前触发
	///@param	pExchange	要删除的CExchange
	virtual void beforeRemove(CExchange *pExchange);
	
	///确认加入后触发
	///@param	pExchange	已经加入的Exchange
	virtual void commitAdd(CExchange *pExchange);

	///确认更新后触发
	///@param	pExchange	被刷新的CExchange
	///@param	poldExchange	原来的值
	virtual void commitUpdate(CExchange *pExchange, CWriteableExchange *pOldExchange);
	
	///确认删除后触发
	///@param	pExchange	已经删除的CExchange
	virtual void commitRemove(CWriteableExchange *pExchange);

	///所有相关的触发器
	vector<CExchangeActionTrigger *> *pActionTriggers;
	vector<CExchangeCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableExchange compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSettlementGroupFactory是一个结算组的对象工厂。它包含了一批结算组，
///同时又建立了如下索引，以方便查询：
///	SettlementGroupIDIndex
///使用本对象工厂，可以完成对结算组的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findBySettlementGroupID，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSettlementGroupFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSettlementGroupFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSettlementGroup，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSettlementGroupFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSettlementGroupFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SettlementGroup
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SettlementGroup，文件名将根据配置文件中的定义SettlementGroupCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SettlementGroup
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SettlementGroup，文件名将根据配置文件中的定义SettlementGroupCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSettlementGroupResource;

	///将一个CSettlementGroup加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSettlementGroup	要加入的SettlementGroup
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSettlementGroup *add(CWriteableSettlementGroup *pSettlementGroup, CTransaction *pTransaction=NULL);
	
	///刷新该CSettlementGroup的值
	///@param	pSettlementGroup	被刷新的CSettlementGroup
	///@param	pNewSettlementGroup	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSettlementGroup *pSettlementGroup, CWriteableSettlementGroup *pNewSettlementGroup, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSettlementGroup	  需要被刷新或者新增的CSettlementGroup,等于NULL表示是需要新增的
	///@param	pNewSettlementGroup	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSettlementGroup* addOrUpdate(CSettlementGroup *pSettlementGroup, CWriteableSettlementGroup *pNewSettlementGroup, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSettlementGroup，同时删除其索引
	///@param	pSettlementGroup	要删除的CSettlementGroup
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSettlementGroup *pSettlementGroup, CTransaction *pTransaction=NULL);
	
	///获取某个CSettlementGroup
	///@param	pSettlementGroup	要读取的CSettlementGroup
	///@param	pTragetSettlementGroup	存放结果的CSettlementGroup
	void retrieve(CSettlementGroup *pSettlementGroup, CWriteableSettlementGroup *pTargetSettlementGroup);
	
	///获取第一个CSettlementGroup
	///@return	得到的第一个CSettlementGroup，如果没有，则返回NULL
	CSettlementGroup *getFirst(void);
	
	///获取下一个CSettlementGroup
	///@return	得到下一个CSettlementGroup，如果没有，则返回NULL
	CSettlementGroup *getNext(void);
	
	///结束获取CSettlementGroup
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSettlementGroupActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSettlementGroupActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSettlementGroupCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSettlementGroupCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///寻找CSettlementGroup
	///@param	SettlementGroupID	结算组编号
	///@return	找到的CSettlementGroup，如果找不到，返回NULL
	CSettlementGroup *findBySettlementGroupID( const CReadOnlySettlementGroupIDType&  SettlementGroupID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSettlementGroup加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSettlementGroup	要加入的SettlementGroup
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSettlementGroup *internalAdd(CWriteableSettlementGroup *pSettlementGroup, bool bNoTransaction);
	
	
	///刷新该CSettlementGroup的键值
	///@param	pSettlementGroup	被刷新的CSettlementGroup
	///@param	pNewSettlementGroup	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSettlementGroup *pSettlementGroup, CWriteableSettlementGroup *pNewSettlementGroup, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSettlementGroup，同时删除其索引
	///@param	pSettlementGroup	要删除的CSettlementGroup
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSettlementGroup *pSettlementGroup, bool bNoTransaction);
/*
	///检查某个CSettlementGroup是否属于本对象工厂
	///@param	pSettlementGroup	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSettlementGroup *pSettlementGroup);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于SettlementGroupID的索引
	CAVLTree *pSettlementGroupIDIndex;
	
	
	
	///加入前触发
	///@param	pSettlementGroup	要加入的SettlementGroup
	virtual void beforeAdd(CWriteableSettlementGroup *pSettlementGroup);
	
	///加入后触发
	///@param	pSettlementGroup	已经加入的SettlementGroup
	virtual void afterAdd(CSettlementGroup *pSettlementGroup);

	///更新前触发	
	///@param	pSettlementGroup	被刷新的CSettlementGroup
	///@param	pNewSettlementGroup	新的值
	virtual void beforeUpdate(CSettlementGroup *pSettlementGroup, CWriteableSettlementGroup *pNewSettlementGroup);
	
	///更新后触发
	///@param	pSettlementGroup	被刷新的CSettlementGroup
	virtual void afterUpdate(CSettlementGroup *pSettlementGroup);
	
	///删除前触发
	///@param	pSettlementGroup	要删除的CSettlementGroup
	virtual void beforeRemove(CSettlementGroup *pSettlementGroup);
	
	///确认加入后触发
	///@param	pSettlementGroup	已经加入的SettlementGroup
	virtual void commitAdd(CSettlementGroup *pSettlementGroup);

	///确认更新后触发
	///@param	pSettlementGroup	被刷新的CSettlementGroup
	///@param	poldSettlementGroup	原来的值
	virtual void commitUpdate(CSettlementGroup *pSettlementGroup, CWriteableSettlementGroup *pOldSettlementGroup);
	
	///确认删除后触发
	///@param	pSettlementGroup	已经删除的CSettlementGroup
	virtual void commitRemove(CWriteableSettlementGroup *pSettlementGroup);

	///所有相关的触发器
	vector<CSettlementGroupActionTrigger *> *pActionTriggers;
	vector<CSettlementGroupCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSettlementGroup compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CMarketFactory是一个市场的对象工厂。它包含了一批市场，
///同时又建立了如下索引，以方便查询：
///	MarketIDIndex
///使用本对象工厂，可以完成对市场的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByMarketID，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CMarketFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxMarket，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CMarketFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CMarketFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的Market
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的Market，文件名将根据配置文件中的定义MarketCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的Market
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的Market，文件名将根据配置文件中的定义MarketCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CMarketResource;

	///将一个CMarket加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pMarket	要加入的Market
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CMarket *add(CWriteableMarket *pMarket, CTransaction *pTransaction=NULL);
	
	///刷新该CMarket的值
	///@param	pMarket	被刷新的CMarket
	///@param	pNewMarket	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CMarket *pMarket, CWriteableMarket *pNewMarket, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pMarket	  需要被刷新或者新增的CMarket,等于NULL表示是需要新增的
	///@param	pNewMarket	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CMarket* addOrUpdate(CMarket *pMarket, CWriteableMarket *pNewMarket, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CMarket，同时删除其索引
	///@param	pMarket	要删除的CMarket
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CMarket *pMarket, CTransaction *pTransaction=NULL);
	
	///获取某个CMarket
	///@param	pMarket	要读取的CMarket
	///@param	pTragetMarket	存放结果的CMarket
	void retrieve(CMarket *pMarket, CWriteableMarket *pTargetMarket);
	
	///获取第一个CMarket
	///@return	得到的第一个CMarket，如果没有，则返回NULL
	CMarket *getFirst(void);
	
	///获取下一个CMarket
	///@return	得到下一个CMarket，如果没有，则返回NULL
	CMarket *getNext(void);
	
	///结束获取CMarket
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CMarketActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CMarketActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CMarketCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CMarketCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///寻找CMarket
	///@param	MarketID	市场编号
	///@return	找到的CMarket，如果找不到，返回NULL
	CMarket *findByMarketID( const CReadOnlyMarketIDType&  MarketID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CMarket加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pMarket	要加入的Market
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CMarket *internalAdd(CWriteableMarket *pMarket, bool bNoTransaction);
	
	
	///刷新该CMarket的键值
	///@param	pMarket	被刷新的CMarket
	///@param	pNewMarket	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CMarket *pMarket, CWriteableMarket *pNewMarket, bool updateIndex,bool bNoTransaction);
	
	///删除一个CMarket，同时删除其索引
	///@param	pMarket	要删除的CMarket
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CMarket *pMarket, bool bNoTransaction);
/*
	///检查某个CMarket是否属于本对象工厂
	///@param	pMarket	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CMarket *pMarket);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于MarketID的索引
	CAVLTree *pMarketIDIndex;
	
	
	
	///加入前触发
	///@param	pMarket	要加入的Market
	virtual void beforeAdd(CWriteableMarket *pMarket);
	
	///加入后触发
	///@param	pMarket	已经加入的Market
	virtual void afterAdd(CMarket *pMarket);

	///更新前触发	
	///@param	pMarket	被刷新的CMarket
	///@param	pNewMarket	新的值
	virtual void beforeUpdate(CMarket *pMarket, CWriteableMarket *pNewMarket);
	
	///更新后触发
	///@param	pMarket	被刷新的CMarket
	virtual void afterUpdate(CMarket *pMarket);
	
	///删除前触发
	///@param	pMarket	要删除的CMarket
	virtual void beforeRemove(CMarket *pMarket);
	
	///确认加入后触发
	///@param	pMarket	已经加入的Market
	virtual void commitAdd(CMarket *pMarket);

	///确认更新后触发
	///@param	pMarket	被刷新的CMarket
	///@param	poldMarket	原来的值
	virtual void commitUpdate(CMarket *pMarket, CWriteableMarket *pOldMarket);
	
	///确认删除后触发
	///@param	pMarket	已经删除的CMarket
	virtual void commitRemove(CWriteableMarket *pMarket);

	///所有相关的触发器
	vector<CMarketActionTrigger *> *pActionTriggers;
	vector<CMarketCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableMarket compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductFactory是一个市场产品关联的对象工厂。它包含了一批市场产品关联，
///同时又建立了如下索引，以方便查询：
///	ProductIDIndex
///使用本对象工厂，可以完成对市场产品关联的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByProductID，findNextByProductID和endFindByProductID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CMarketProductFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxMarketProduct，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CMarketProductFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CMarketProductFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的MarketProduct
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的MarketProduct，文件名将根据配置文件中的定义MarketProductCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的MarketProduct
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的MarketProduct，文件名将根据配置文件中的定义MarketProductCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CMarketProductResource;

	///将一个CMarketProduct加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pMarketProduct	要加入的MarketProduct
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CMarketProduct *add(CWriteableMarketProduct *pMarketProduct, CTransaction *pTransaction=NULL);
	
	///刷新该CMarketProduct的值
	///@param	pMarketProduct	被刷新的CMarketProduct
	///@param	pNewMarketProduct	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CMarketProduct *pMarketProduct, CWriteableMarketProduct *pNewMarketProduct, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pMarketProduct	  需要被刷新或者新增的CMarketProduct,等于NULL表示是需要新增的
	///@param	pNewMarketProduct	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CMarketProduct* addOrUpdate(CMarketProduct *pMarketProduct, CWriteableMarketProduct *pNewMarketProduct, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CMarketProduct，同时删除其索引
	///@param	pMarketProduct	要删除的CMarketProduct
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CMarketProduct *pMarketProduct, CTransaction *pTransaction=NULL);
	
	///获取某个CMarketProduct
	///@param	pMarketProduct	要读取的CMarketProduct
	///@param	pTragetMarketProduct	存放结果的CMarketProduct
	void retrieve(CMarketProduct *pMarketProduct, CWriteableMarketProduct *pTargetMarketProduct);
	
	///获取第一个CMarketProduct
	///@return	得到的第一个CMarketProduct，如果没有，则返回NULL
	CMarketProduct *getFirst(void);
	
	///获取下一个CMarketProduct
	///@return	得到下一个CMarketProduct，如果没有，则返回NULL
	CMarketProduct *getNext(void);
	
	///结束获取CMarketProduct
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CMarketProductActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CMarketProductActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CMarketProductCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CMarketProductCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CMarketProductIteratorByProductID;

	///开始寻找CMarketProduct
	///@param	ProductID	产品代码
	///@return	满足条件的地一个CMarketProduct，如果找不到，返回NULL
	CMarketProduct *startFindByProductID( const CReadOnlyProductIDType& ProductID);

	///寻找下一个符合条件的CMarketProduct，必须在startFindByProductID以后，endFindByProductID之前叫用
	///@return	下一个满足条件CMarketProduct，如果已经没有一个满足要求了，则返回NULL
	CMarketProduct *findNextByProductID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByProductID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CMarketProduct加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pMarketProduct	要加入的MarketProduct
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CMarketProduct *internalAdd(CWriteableMarketProduct *pMarketProduct, bool bNoTransaction);
	
	
	///刷新该CMarketProduct的键值
	///@param	pMarketProduct	被刷新的CMarketProduct
	///@param	pNewMarketProduct	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CMarketProduct *pMarketProduct, CWriteableMarketProduct *pNewMarketProduct, bool updateIndex,bool bNoTransaction);
	
	///删除一个CMarketProduct，同时删除其索引
	///@param	pMarketProduct	要删除的CMarketProduct
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CMarketProduct *pMarketProduct, bool bNoTransaction);
/*
	///检查某个CMarketProduct是否属于本对象工厂
	///@param	pMarketProduct	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CMarketProduct *pMarketProduct);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ProductID的索引
	CAVLTree *pProductIDIndex;
	
	
	///按照ProductID检索时，存储的查询参数
	CProductIDType queryProductIDInSearchByProductID;
	
	///按照ProductID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByProductID;
	
	///加入前触发
	///@param	pMarketProduct	要加入的MarketProduct
	virtual void beforeAdd(CWriteableMarketProduct *pMarketProduct);
	
	///加入后触发
	///@param	pMarketProduct	已经加入的MarketProduct
	virtual void afterAdd(CMarketProduct *pMarketProduct);

	///更新前触发	
	///@param	pMarketProduct	被刷新的CMarketProduct
	///@param	pNewMarketProduct	新的值
	virtual void beforeUpdate(CMarketProduct *pMarketProduct, CWriteableMarketProduct *pNewMarketProduct);
	
	///更新后触发
	///@param	pMarketProduct	被刷新的CMarketProduct
	virtual void afterUpdate(CMarketProduct *pMarketProduct);
	
	///删除前触发
	///@param	pMarketProduct	要删除的CMarketProduct
	virtual void beforeRemove(CMarketProduct *pMarketProduct);
	
	///确认加入后触发
	///@param	pMarketProduct	已经加入的MarketProduct
	virtual void commitAdd(CMarketProduct *pMarketProduct);

	///确认更新后触发
	///@param	pMarketProduct	被刷新的CMarketProduct
	///@param	poldMarketProduct	原来的值
	virtual void commitUpdate(CMarketProduct *pMarketProduct, CWriteableMarketProduct *pOldMarketProduct);
	
	///确认删除后触发
	///@param	pMarketProduct	已经删除的CMarketProduct
	virtual void commitRemove(CWriteableMarketProduct *pMarketProduct);

	///所有相关的触发器
	vector<CMarketProductActionTrigger *> *pActionTriggers;
	vector<CMarketProductCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableMarketProduct compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductGroupFactory是一个市场产品组关联的对象工厂。它包含了一批市场产品组关联，
///同时又建立了如下索引，以方便查询：
///	ProductGroupIDIndex
///使用本对象工厂，可以完成对市场产品组关联的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByProductGroupID，findNextByProductGroupID和endFindByProductGroupID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductGroupFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CMarketProductGroupFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxMarketProductGroup，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CMarketProductGroupFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CMarketProductGroupFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的MarketProductGroup
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的MarketProductGroup，文件名将根据配置文件中的定义MarketProductGroupCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的MarketProductGroup
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的MarketProductGroup，文件名将根据配置文件中的定义MarketProductGroupCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CMarketProductGroupResource;

	///将一个CMarketProductGroup加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pMarketProductGroup	要加入的MarketProductGroup
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CMarketProductGroup *add(CWriteableMarketProductGroup *pMarketProductGroup, CTransaction *pTransaction=NULL);
	
	///刷新该CMarketProductGroup的值
	///@param	pMarketProductGroup	被刷新的CMarketProductGroup
	///@param	pNewMarketProductGroup	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CMarketProductGroup *pMarketProductGroup, CWriteableMarketProductGroup *pNewMarketProductGroup, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pMarketProductGroup	  需要被刷新或者新增的CMarketProductGroup,等于NULL表示是需要新增的
	///@param	pNewMarketProductGroup	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CMarketProductGroup* addOrUpdate(CMarketProductGroup *pMarketProductGroup, CWriteableMarketProductGroup *pNewMarketProductGroup, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CMarketProductGroup，同时删除其索引
	///@param	pMarketProductGroup	要删除的CMarketProductGroup
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CMarketProductGroup *pMarketProductGroup, CTransaction *pTransaction=NULL);
	
	///获取某个CMarketProductGroup
	///@param	pMarketProductGroup	要读取的CMarketProductGroup
	///@param	pTragetMarketProductGroup	存放结果的CMarketProductGroup
	void retrieve(CMarketProductGroup *pMarketProductGroup, CWriteableMarketProductGroup *pTargetMarketProductGroup);
	
	///获取第一个CMarketProductGroup
	///@return	得到的第一个CMarketProductGroup，如果没有，则返回NULL
	CMarketProductGroup *getFirst(void);
	
	///获取下一个CMarketProductGroup
	///@return	得到下一个CMarketProductGroup，如果没有，则返回NULL
	CMarketProductGroup *getNext(void);
	
	///结束获取CMarketProductGroup
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CMarketProductGroupActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CMarketProductGroupActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CMarketProductGroupCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CMarketProductGroupCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CMarketProductGroupIteratorByProductGroupID;

	///开始寻找CMarketProductGroup
	///@param	ProductGroupID	产品组代码
	///@return	满足条件的地一个CMarketProductGroup，如果找不到，返回NULL
	CMarketProductGroup *startFindByProductGroupID( const CReadOnlyProductGroupIDType& ProductGroupID);

	///寻找下一个符合条件的CMarketProductGroup，必须在startFindByProductGroupID以后，endFindByProductGroupID之前叫用
	///@return	下一个满足条件CMarketProductGroup，如果已经没有一个满足要求了，则返回NULL
	CMarketProductGroup *findNextByProductGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByProductGroupID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CMarketProductGroup加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pMarketProductGroup	要加入的MarketProductGroup
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CMarketProductGroup *internalAdd(CWriteableMarketProductGroup *pMarketProductGroup, bool bNoTransaction);
	
	
	///刷新该CMarketProductGroup的键值
	///@param	pMarketProductGroup	被刷新的CMarketProductGroup
	///@param	pNewMarketProductGroup	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CMarketProductGroup *pMarketProductGroup, CWriteableMarketProductGroup *pNewMarketProductGroup, bool updateIndex,bool bNoTransaction);
	
	///删除一个CMarketProductGroup，同时删除其索引
	///@param	pMarketProductGroup	要删除的CMarketProductGroup
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CMarketProductGroup *pMarketProductGroup, bool bNoTransaction);
/*
	///检查某个CMarketProductGroup是否属于本对象工厂
	///@param	pMarketProductGroup	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CMarketProductGroup *pMarketProductGroup);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ProductGroupID的索引
	CAVLTree *pProductGroupIDIndex;
	
	
	///按照ProductGroupID检索时，存储的查询参数
	CProductGroupIDType queryProductGroupIDInSearchByProductGroupID;
	
	///按照ProductGroupID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByProductGroupID;
	
	///加入前触发
	///@param	pMarketProductGroup	要加入的MarketProductGroup
	virtual void beforeAdd(CWriteableMarketProductGroup *pMarketProductGroup);
	
	///加入后触发
	///@param	pMarketProductGroup	已经加入的MarketProductGroup
	virtual void afterAdd(CMarketProductGroup *pMarketProductGroup);

	///更新前触发	
	///@param	pMarketProductGroup	被刷新的CMarketProductGroup
	///@param	pNewMarketProductGroup	新的值
	virtual void beforeUpdate(CMarketProductGroup *pMarketProductGroup, CWriteableMarketProductGroup *pNewMarketProductGroup);
	
	///更新后触发
	///@param	pMarketProductGroup	被刷新的CMarketProductGroup
	virtual void afterUpdate(CMarketProductGroup *pMarketProductGroup);
	
	///删除前触发
	///@param	pMarketProductGroup	要删除的CMarketProductGroup
	virtual void beforeRemove(CMarketProductGroup *pMarketProductGroup);
	
	///确认加入后触发
	///@param	pMarketProductGroup	已经加入的MarketProductGroup
	virtual void commitAdd(CMarketProductGroup *pMarketProductGroup);

	///确认更新后触发
	///@param	pMarketProductGroup	被刷新的CMarketProductGroup
	///@param	poldMarketProductGroup	原来的值
	virtual void commitUpdate(CMarketProductGroup *pMarketProductGroup, CWriteableMarketProductGroup *pOldMarketProductGroup);
	
	///确认删除后触发
	///@param	pMarketProductGroup	已经删除的CMarketProductGroup
	virtual void commitRemove(CWriteableMarketProductGroup *pMarketProductGroup);

	///所有相关的触发器
	vector<CMarketProductGroupActionTrigger *> *pActionTriggers;
	vector<CMarketProductGroupCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableMarketProductGroup compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CMdPubStatusFactory是一个行情发布状态的对象工厂。它包含了一批行情发布状态，
///同时又建立了如下索引，以方便查询：
///	ProductIDInstrumentStatusIndex
///使用本对象工厂，可以完成对行情发布状态的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByProductIDInstrumentStatus，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMdPubStatusFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CMdPubStatusFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxMdPubStatus，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CMdPubStatusFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CMdPubStatusFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的MdPubStatus
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的MdPubStatus，文件名将根据配置文件中的定义MdPubStatusCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的MdPubStatus
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的MdPubStatus，文件名将根据配置文件中的定义MdPubStatusCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CMdPubStatusResource;

	///将一个CMdPubStatus加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pMdPubStatus	要加入的MdPubStatus
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CMdPubStatus *add(CWriteableMdPubStatus *pMdPubStatus, CTransaction *pTransaction=NULL);
	
	///刷新该CMdPubStatus的值
	///@param	pMdPubStatus	被刷新的CMdPubStatus
	///@param	pNewMdPubStatus	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CMdPubStatus *pMdPubStatus, CWriteableMdPubStatus *pNewMdPubStatus, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pMdPubStatus	  需要被刷新或者新增的CMdPubStatus,等于NULL表示是需要新增的
	///@param	pNewMdPubStatus	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CMdPubStatus* addOrUpdate(CMdPubStatus *pMdPubStatus, CWriteableMdPubStatus *pNewMdPubStatus, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CMdPubStatus，同时删除其索引
	///@param	pMdPubStatus	要删除的CMdPubStatus
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CMdPubStatus *pMdPubStatus, CTransaction *pTransaction=NULL);
	
	///获取某个CMdPubStatus
	///@param	pMdPubStatus	要读取的CMdPubStatus
	///@param	pTragetMdPubStatus	存放结果的CMdPubStatus
	void retrieve(CMdPubStatus *pMdPubStatus, CWriteableMdPubStatus *pTargetMdPubStatus);
	
	///获取第一个CMdPubStatus
	///@return	得到的第一个CMdPubStatus，如果没有，则返回NULL
	CMdPubStatus *getFirst(void);
	
	///获取下一个CMdPubStatus
	///@return	得到下一个CMdPubStatus，如果没有，则返回NULL
	CMdPubStatus *getNext(void);
	
	///结束获取CMdPubStatus
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CMdPubStatusActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CMdPubStatusActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CMdPubStatusCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CMdPubStatusCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///寻找CMdPubStatus
	///@param	ProductID	产品代码
	///@param	InstrumentStatus	合约交易状态
	///@return	找到的CMdPubStatus，如果找不到，返回NULL
	CMdPubStatus *findByProductIDInstrumentStatus( const CReadOnlyProductIDType&  ProductID,  const CReadOnlyInstrumentStatusType&  InstrumentStatus);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CMdPubStatus加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pMdPubStatus	要加入的MdPubStatus
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CMdPubStatus *internalAdd(CWriteableMdPubStatus *pMdPubStatus, bool bNoTransaction);
	
	
	///刷新该CMdPubStatus的键值
	///@param	pMdPubStatus	被刷新的CMdPubStatus
	///@param	pNewMdPubStatus	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CMdPubStatus *pMdPubStatus, CWriteableMdPubStatus *pNewMdPubStatus, bool updateIndex,bool bNoTransaction);
	
	///删除一个CMdPubStatus，同时删除其索引
	///@param	pMdPubStatus	要删除的CMdPubStatus
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CMdPubStatus *pMdPubStatus, bool bNoTransaction);
/*
	///检查某个CMdPubStatus是否属于本对象工厂
	///@param	pMdPubStatus	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CMdPubStatus *pMdPubStatus);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ProductID+InstrumentStatus的索引
	CAVLTree *pProductIDInstrumentStatusIndex;
	
	
	
	///加入前触发
	///@param	pMdPubStatus	要加入的MdPubStatus
	virtual void beforeAdd(CWriteableMdPubStatus *pMdPubStatus);
	
	///加入后触发
	///@param	pMdPubStatus	已经加入的MdPubStatus
	virtual void afterAdd(CMdPubStatus *pMdPubStatus);

	///更新前触发	
	///@param	pMdPubStatus	被刷新的CMdPubStatus
	///@param	pNewMdPubStatus	新的值
	virtual void beforeUpdate(CMdPubStatus *pMdPubStatus, CWriteableMdPubStatus *pNewMdPubStatus);
	
	///更新后触发
	///@param	pMdPubStatus	被刷新的CMdPubStatus
	virtual void afterUpdate(CMdPubStatus *pMdPubStatus);
	
	///删除前触发
	///@param	pMdPubStatus	要删除的CMdPubStatus
	virtual void beforeRemove(CMdPubStatus *pMdPubStatus);
	
	///确认加入后触发
	///@param	pMdPubStatus	已经加入的MdPubStatus
	virtual void commitAdd(CMdPubStatus *pMdPubStatus);

	///确认更新后触发
	///@param	pMdPubStatus	被刷新的CMdPubStatus
	///@param	poldMdPubStatus	原来的值
	virtual void commitUpdate(CMdPubStatus *pMdPubStatus, CWriteableMdPubStatus *pOldMdPubStatus);
	
	///确认删除后触发
	///@param	pMdPubStatus	已经删除的CMdPubStatus
	virtual void commitRemove(CWriteableMdPubStatus *pMdPubStatus);

	///所有相关的触发器
	vector<CMdPubStatusActionTrigger *> *pActionTriggers;
	vector<CMdPubStatusCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableMdPubStatus compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataTopicFactory是一个行情主题的对象工厂。它包含了一批行情主题，
///同时又建立了如下索引，以方便查询：
///	TopicIDIndex
///	MarketIDIndex
///使用本对象工厂，可以完成对行情主题的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByTopicID，唯一找到对象
///		使用startFindByMarketID，findNextByMarketID和endFindByMarketID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataTopicFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CMarketDataTopicFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxMarketDataTopic，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CMarketDataTopicFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CMarketDataTopicFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的MarketDataTopic
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的MarketDataTopic，文件名将根据配置文件中的定义MarketDataTopicCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的MarketDataTopic
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的MarketDataTopic，文件名将根据配置文件中的定义MarketDataTopicCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CMarketDataTopicResource;

	///将一个CMarketDataTopic加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pMarketDataTopic	要加入的MarketDataTopic
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CMarketDataTopic *add(CWriteableMarketDataTopic *pMarketDataTopic, CTransaction *pTransaction=NULL);
	
	///刷新该CMarketDataTopic的值
	///@param	pMarketDataTopic	被刷新的CMarketDataTopic
	///@param	pNewMarketDataTopic	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CMarketDataTopic *pMarketDataTopic, CWriteableMarketDataTopic *pNewMarketDataTopic, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pMarketDataTopic	  需要被刷新或者新增的CMarketDataTopic,等于NULL表示是需要新增的
	///@param	pNewMarketDataTopic	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CMarketDataTopic* addOrUpdate(CMarketDataTopic *pMarketDataTopic, CWriteableMarketDataTopic *pNewMarketDataTopic, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CMarketDataTopic，同时删除其索引
	///@param	pMarketDataTopic	要删除的CMarketDataTopic
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CMarketDataTopic *pMarketDataTopic, CTransaction *pTransaction=NULL);
	
	///获取某个CMarketDataTopic
	///@param	pMarketDataTopic	要读取的CMarketDataTopic
	///@param	pTragetMarketDataTopic	存放结果的CMarketDataTopic
	void retrieve(CMarketDataTopic *pMarketDataTopic, CWriteableMarketDataTopic *pTargetMarketDataTopic);
	
	///获取第一个CMarketDataTopic
	///@return	得到的第一个CMarketDataTopic，如果没有，则返回NULL
	CMarketDataTopic *getFirst(void);
	
	///获取下一个CMarketDataTopic
	///@return	得到下一个CMarketDataTopic，如果没有，则返回NULL
	CMarketDataTopic *getNext(void);
	
	///结束获取CMarketDataTopic
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CMarketDataTopicActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CMarketDataTopicActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CMarketDataTopicCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CMarketDataTopicCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///寻找CMarketDataTopic
	///@param	TopicID	行情主题代码
	///@return	找到的CMarketDataTopic，如果找不到，返回NULL
	CMarketDataTopic *findByTopicID( const CReadOnlyTopicIDType&  TopicID);



	friend class CMarketDataTopicIteratorByMarketID;

	///开始寻找CMarketDataTopic
	///@param	MarketID	市场代码
	///@return	满足条件的地一个CMarketDataTopic，如果找不到，返回NULL
	CMarketDataTopic *startFindByMarketID( const CReadOnlyMarketIDType& MarketID);

	///寻找下一个符合条件的CMarketDataTopic，必须在startFindByMarketID以后，endFindByMarketID之前叫用
	///@return	下一个满足条件CMarketDataTopic，如果已经没有一个满足要求了，则返回NULL
	CMarketDataTopic *findNextByMarketID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByMarketID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CMarketDataTopic加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pMarketDataTopic	要加入的MarketDataTopic
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CMarketDataTopic *internalAdd(CWriteableMarketDataTopic *pMarketDataTopic, bool bNoTransaction);
	
	
	///刷新该CMarketDataTopic的键值
	///@param	pMarketDataTopic	被刷新的CMarketDataTopic
	///@param	pNewMarketDataTopic	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CMarketDataTopic *pMarketDataTopic, CWriteableMarketDataTopic *pNewMarketDataTopic, bool updateIndex,bool bNoTransaction);
	
	///删除一个CMarketDataTopic，同时删除其索引
	///@param	pMarketDataTopic	要删除的CMarketDataTopic
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CMarketDataTopic *pMarketDataTopic, bool bNoTransaction);
/*
	///检查某个CMarketDataTopic是否属于本对象工厂
	///@param	pMarketDataTopic	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CMarketDataTopic *pMarketDataTopic);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于TopicID的索引
	CAVLTree *pTopicIDIndex;
	///基于MarketID的索引
	CAVLTree *pMarketIDIndex;
	
	
	///按照MarketID检索时，存储的查询参数
	CMarketIDType queryMarketIDInSearchByMarketID;
	
	///按照MarketID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByMarketID;
	
	///加入前触发
	///@param	pMarketDataTopic	要加入的MarketDataTopic
	virtual void beforeAdd(CWriteableMarketDataTopic *pMarketDataTopic);
	
	///加入后触发
	///@param	pMarketDataTopic	已经加入的MarketDataTopic
	virtual void afterAdd(CMarketDataTopic *pMarketDataTopic);

	///更新前触发	
	///@param	pMarketDataTopic	被刷新的CMarketDataTopic
	///@param	pNewMarketDataTopic	新的值
	virtual void beforeUpdate(CMarketDataTopic *pMarketDataTopic, CWriteableMarketDataTopic *pNewMarketDataTopic);
	
	///更新后触发
	///@param	pMarketDataTopic	被刷新的CMarketDataTopic
	virtual void afterUpdate(CMarketDataTopic *pMarketDataTopic);
	
	///删除前触发
	///@param	pMarketDataTopic	要删除的CMarketDataTopic
	virtual void beforeRemove(CMarketDataTopic *pMarketDataTopic);
	
	///确认加入后触发
	///@param	pMarketDataTopic	已经加入的MarketDataTopic
	virtual void commitAdd(CMarketDataTopic *pMarketDataTopic);

	///确认更新后触发
	///@param	pMarketDataTopic	被刷新的CMarketDataTopic
	///@param	poldMarketDataTopic	原来的值
	virtual void commitUpdate(CMarketDataTopic *pMarketDataTopic, CWriteableMarketDataTopic *pOldMarketDataTopic);
	
	///确认删除后触发
	///@param	pMarketDataTopic	已经删除的CMarketDataTopic
	virtual void commitRemove(CWriteableMarketDataTopic *pMarketDataTopic);

	///所有相关的触发器
	vector<CMarketDataTopicActionTrigger *> *pActionTriggers;
	vector<CMarketDataTopicCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableMarketDataTopic compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CPartTopicSubscribeFactory是一个会员订阅市场的对象工厂。它包含了一批会员订阅市场，
///同时又建立了如下索引，以方便查询：
///	PartIDTopicIDIndex
///使用本对象工厂，可以完成对会员订阅市场的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByPartIDTopicID，唯一找到对象
///		使用startFindByPartID，findNextByPartID和endFindByPartID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartTopicSubscribeFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CPartTopicSubscribeFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxPartTopicSubscribe，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CPartTopicSubscribeFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CPartTopicSubscribeFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的PartTopicSubscribe
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的PartTopicSubscribe，文件名将根据配置文件中的定义PartTopicSubscribeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的PartTopicSubscribe
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的PartTopicSubscribe，文件名将根据配置文件中的定义PartTopicSubscribeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CPartTopicSubscribeResource;

	///将一个CPartTopicSubscribe加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pPartTopicSubscribe	要加入的PartTopicSubscribe
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CPartTopicSubscribe *add(CWriteablePartTopicSubscribe *pPartTopicSubscribe, CTransaction *pTransaction=NULL);
	
	///刷新该CPartTopicSubscribe的值
	///@param	pPartTopicSubscribe	被刷新的CPartTopicSubscribe
	///@param	pNewPartTopicSubscribe	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CPartTopicSubscribe *pPartTopicSubscribe, CWriteablePartTopicSubscribe *pNewPartTopicSubscribe, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pPartTopicSubscribe	  需要被刷新或者新增的CPartTopicSubscribe,等于NULL表示是需要新增的
	///@param	pNewPartTopicSubscribe	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CPartTopicSubscribe* addOrUpdate(CPartTopicSubscribe *pPartTopicSubscribe, CWriteablePartTopicSubscribe *pNewPartTopicSubscribe, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CPartTopicSubscribe，同时删除其索引
	///@param	pPartTopicSubscribe	要删除的CPartTopicSubscribe
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CPartTopicSubscribe *pPartTopicSubscribe, CTransaction *pTransaction=NULL);
	
	///获取某个CPartTopicSubscribe
	///@param	pPartTopicSubscribe	要读取的CPartTopicSubscribe
	///@param	pTragetPartTopicSubscribe	存放结果的CPartTopicSubscribe
	void retrieve(CPartTopicSubscribe *pPartTopicSubscribe, CWriteablePartTopicSubscribe *pTargetPartTopicSubscribe);
	
	///获取第一个CPartTopicSubscribe
	///@return	得到的第一个CPartTopicSubscribe，如果没有，则返回NULL
	CPartTopicSubscribe *getFirst(void);
	
	///获取下一个CPartTopicSubscribe
	///@return	得到下一个CPartTopicSubscribe，如果没有，则返回NULL
	CPartTopicSubscribe *getNext(void);
	
	///结束获取CPartTopicSubscribe
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CPartTopicSubscribeActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CPartTopicSubscribeActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CPartTopicSubscribeCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CPartTopicSubscribeCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///寻找CPartTopicSubscribe
	///@param	ParticipantID	会员代码
	///@param	TopicID	行情主题代码
	///@return	找到的CPartTopicSubscribe，如果找不到，返回NULL
	CPartTopicSubscribe *findByPartIDTopicID( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyTopicIDType&  TopicID);

	///根据主码寻找
	///@param	ParticipantID	会员代码
	///@param	TopicID	行情主题代码
	///@return	找到的CPartTopicSubscribe，如果找不到，返回NULL
	CPartTopicSubscribe *findByPK( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyTopicIDType&  TopicID);
	
	///根据主键寻找CPartTopicSubscribe
	///@param	pPartTopicSubscribe	要找的值
	///@return	找到的CPartTopicSubscribe，如果找不到，返回NULL
	CPartTopicSubscribe *findByPK(CWriteablePartTopicSubscribe *pPartTopicSubscribe);

	///根据主键获取CPartTopicSubscribe
	///@param	pPartTopicSubscribe	要获取的值，同时用于存放返回的结果
	///@return	找到的CPartTopicSubscribe，如果找不到，返回NULL
	bool retrieveByPK(CWriteablePartTopicSubscribe *pPartTopicSubscribe);

	///根据主键增加新的CPartTopicSubscribe
	///@param	pPartTopicSubscribe	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	返回插入的CPartTopicSubscribe，如果插入失败，则返回NULL
	CPartTopicSubscribe *addByPK(CWriteablePartTopicSubscribe *pPartTopicSubscribe, CTransaction *pTransaction=NULL);

	///根据主键更新CPartTopicSubscribe的值
	///@param	pPartTopicSubscribe	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	///@return	true表示成功，false表示失败
	bool updateByPK(CWriteablePartTopicSubscribe *pPartTopicSubscribe, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///根据主键删除CPartTopicSubscribe
	///@param	pPartTopicSubscribe	要删除的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	true表示成功，false表示失败
	bool removeByPK(CWriteablePartTopicSubscribe *pPartTopicSubscribe, CTransaction *pTransaction=NULL);


	friend class CPartTopicSubscribeIteratorByPartID;

	///开始寻找CPartTopicSubscribe
	///@param	ParticipantID	会员代码
	///@return	满足条件的地一个CPartTopicSubscribe，如果找不到，返回NULL
	CPartTopicSubscribe *startFindByPartID( const CReadOnlyParticipantIDType& ParticipantID);

	///寻找下一个符合条件的CPartTopicSubscribe，必须在startFindByPartID以后，endFindByPartID之前叫用
	///@return	下一个满足条件CPartTopicSubscribe，如果已经没有一个满足要求了，则返回NULL
	CPartTopicSubscribe *findNextByPartID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByPartID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CPartTopicSubscribe加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pPartTopicSubscribe	要加入的PartTopicSubscribe
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CPartTopicSubscribe *internalAdd(CWriteablePartTopicSubscribe *pPartTopicSubscribe, bool bNoTransaction);
	
	
	///刷新该CPartTopicSubscribe的键值
	///@param	pPartTopicSubscribe	被刷新的CPartTopicSubscribe
	///@param	pNewPartTopicSubscribe	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CPartTopicSubscribe *pPartTopicSubscribe, CWriteablePartTopicSubscribe *pNewPartTopicSubscribe, bool updateIndex,bool bNoTransaction);
	
	///删除一个CPartTopicSubscribe，同时删除其索引
	///@param	pPartTopicSubscribe	要删除的CPartTopicSubscribe
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CPartTopicSubscribe *pPartTopicSubscribe, bool bNoTransaction);
/*
	///检查某个CPartTopicSubscribe是否属于本对象工厂
	///@param	pPartTopicSubscribe	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CPartTopicSubscribe *pPartTopicSubscribe);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ParticipantID+TopicID的索引
	CAVLTree *pPartIDTopicIDIndex;
	
	
	///按照ParticipantID检索时，存储的查询参数
	CParticipantIDType queryParticipantIDInSearchByPartID;
	
	///按照ParticipantID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByPartID;
	
	///加入前触发
	///@param	pPartTopicSubscribe	要加入的PartTopicSubscribe
	virtual void beforeAdd(CWriteablePartTopicSubscribe *pPartTopicSubscribe);
	
	///加入后触发
	///@param	pPartTopicSubscribe	已经加入的PartTopicSubscribe
	virtual void afterAdd(CPartTopicSubscribe *pPartTopicSubscribe);

	///更新前触发	
	///@param	pPartTopicSubscribe	被刷新的CPartTopicSubscribe
	///@param	pNewPartTopicSubscribe	新的值
	virtual void beforeUpdate(CPartTopicSubscribe *pPartTopicSubscribe, CWriteablePartTopicSubscribe *pNewPartTopicSubscribe);
	
	///更新后触发
	///@param	pPartTopicSubscribe	被刷新的CPartTopicSubscribe
	virtual void afterUpdate(CPartTopicSubscribe *pPartTopicSubscribe);
	
	///删除前触发
	///@param	pPartTopicSubscribe	要删除的CPartTopicSubscribe
	virtual void beforeRemove(CPartTopicSubscribe *pPartTopicSubscribe);
	
	///确认加入后触发
	///@param	pPartTopicSubscribe	已经加入的PartTopicSubscribe
	virtual void commitAdd(CPartTopicSubscribe *pPartTopicSubscribe);

	///确认更新后触发
	///@param	pPartTopicSubscribe	被刷新的CPartTopicSubscribe
	///@param	poldPartTopicSubscribe	原来的值
	virtual void commitUpdate(CPartTopicSubscribe *pPartTopicSubscribe, CWriteablePartTopicSubscribe *pOldPartTopicSubscribe);
	
	///确认删除后触发
	///@param	pPartTopicSubscribe	已经删除的CPartTopicSubscribe
	virtual void commitRemove(CWriteablePartTopicSubscribe *pPartTopicSubscribe);

	///所有相关的触发器
	vector<CPartTopicSubscribeActionTrigger *> *pActionTriggers;
	vector<CPartTopicSubscribeCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteablePartTopicSubscribe compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CParticipantFactory是一个会员的对象工厂。它包含了一批会员，
///同时又建立了如下索引，以方便查询：
///	ParticipantIDIndex
///使用本对象工厂，可以完成对会员的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByParticipantID，唯一找到对象
///		使用startFindStartByParticipantID，findNextStartByParticipantID和endFindStartByParticipantID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CParticipantFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxParticipant，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CParticipantFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CParticipantFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的Participant
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的Participant，文件名将根据配置文件中的定义ParticipantCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的Participant
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的Participant，文件名将根据配置文件中的定义ParticipantCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CParticipantResource;

	///将一个CParticipant加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pParticipant	要加入的Participant
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CParticipant *add(CWriteableParticipant *pParticipant, CTransaction *pTransaction=NULL);
	
	///刷新该CParticipant的值
	///@param	pParticipant	被刷新的CParticipant
	///@param	pNewParticipant	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CParticipant *pParticipant, CWriteableParticipant *pNewParticipant, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pParticipant	  需要被刷新或者新增的CParticipant,等于NULL表示是需要新增的
	///@param	pNewParticipant	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CParticipant* addOrUpdate(CParticipant *pParticipant, CWriteableParticipant *pNewParticipant, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CParticipant，同时删除其索引
	///@param	pParticipant	要删除的CParticipant
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CParticipant *pParticipant, CTransaction *pTransaction=NULL);
	
	///获取某个CParticipant
	///@param	pParticipant	要读取的CParticipant
	///@param	pTragetParticipant	存放结果的CParticipant
	void retrieve(CParticipant *pParticipant, CWriteableParticipant *pTargetParticipant);
	
	///获取第一个CParticipant
	///@return	得到的第一个CParticipant，如果没有，则返回NULL
	CParticipant *getFirst(void);
	
	///获取下一个CParticipant
	///@return	得到下一个CParticipant，如果没有，则返回NULL
	CParticipant *getNext(void);
	
	///结束获取CParticipant
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CParticipantActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CParticipantActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CParticipantCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CParticipantCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///构造所有对应的结算交易会员关系的指针
	///@param	pFactory	构造对应的结算交易会员关系的指针时，寻找的对象工厂
	void linkAllClearingTradingPart(CClearingTradingPartFactory *pFactory);
	
	///寻找CParticipant
	///@param	ParticipantID	会员编号
	///@return	找到的CParticipant，如果找不到，返回NULL
	CParticipant *findByParticipantID( const CReadOnlyParticipantIDType&  ParticipantID);

	///根据主码寻找
	///@param	ParticipantID	会员编号
	///@return	找到的CParticipant，如果找不到，返回NULL
	CParticipant *findByPK( const CReadOnlyParticipantIDType&  ParticipantID);
	
	///根据主键寻找CParticipant
	///@param	pParticipant	要找的值
	///@return	找到的CParticipant，如果找不到，返回NULL
	CParticipant *findByPK(CWriteableParticipant *pParticipant);

	///根据主键获取CParticipant
	///@param	pParticipant	要获取的值，同时用于存放返回的结果
	///@return	找到的CParticipant，如果找不到，返回NULL
	bool retrieveByPK(CWriteableParticipant *pParticipant);

	///根据主键增加新的CParticipant
	///@param	pParticipant	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	返回插入的CParticipant，如果插入失败，则返回NULL
	CParticipant *addByPK(CWriteableParticipant *pParticipant, CTransaction *pTransaction=NULL);

	///根据主键更新CParticipant的值
	///@param	pParticipant	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	///@return	true表示成功，false表示失败
	bool updateByPK(CWriteableParticipant *pParticipant, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///根据主键删除CParticipant
	///@param	pParticipant	要删除的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	true表示成功，false表示失败
	bool removeByPK(CWriteableParticipant *pParticipant, CTransaction *pTransaction=NULL);


	friend class CParticipantIteratorStartByParticipantID;

	///开始寻找CParticipant
	///@param	ParticipantID	会员编号
	///@return	满足条件的地一个CParticipant，如果找不到，返回NULL
	CParticipant *startFindStartByParticipantID( const CReadOnlyParticipantIDType& ParticipantID);

	///寻找下一个符合条件的CParticipant，必须在startFindStartByParticipantID以后，endFindStartByParticipantID之前叫用
	///@return	下一个满足条件CParticipant，如果已经没有一个满足要求了，则返回NULL
	CParticipant *findNextStartByParticipantID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindStartByParticipantID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CParticipant加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pParticipant	要加入的Participant
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CParticipant *internalAdd(CWriteableParticipant *pParticipant, bool bNoTransaction);
	
	
	///刷新该CParticipant的键值
	///@param	pParticipant	被刷新的CParticipant
	///@param	pNewParticipant	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CParticipant *pParticipant, CWriteableParticipant *pNewParticipant, bool updateIndex,bool bNoTransaction);
	
	///删除一个CParticipant，同时删除其索引
	///@param	pParticipant	要删除的CParticipant
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CParticipant *pParticipant, bool bNoTransaction);
/*
	///检查某个CParticipant是否属于本对象工厂
	///@param	pParticipant	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CParticipant *pParticipant);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ParticipantID的索引
	CAVLTree *pParticipantIDIndex;
	
	
	///按照ParticipantID检索时，存储的查询参数
	CParticipantIDType queryParticipantIDInSearchStartByParticipantID;
	
	///按照ParticipantID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchStartByParticipantID;
	
	///加入前触发
	///@param	pParticipant	要加入的Participant
	virtual void beforeAdd(CWriteableParticipant *pParticipant);
	
	///加入后触发
	///@param	pParticipant	已经加入的Participant
	virtual void afterAdd(CParticipant *pParticipant);

	///更新前触发	
	///@param	pParticipant	被刷新的CParticipant
	///@param	pNewParticipant	新的值
	virtual void beforeUpdate(CParticipant *pParticipant, CWriteableParticipant *pNewParticipant);
	
	///更新后触发
	///@param	pParticipant	被刷新的CParticipant
	virtual void afterUpdate(CParticipant *pParticipant);
	
	///删除前触发
	///@param	pParticipant	要删除的CParticipant
	virtual void beforeRemove(CParticipant *pParticipant);
	
	///确认加入后触发
	///@param	pParticipant	已经加入的Participant
	virtual void commitAdd(CParticipant *pParticipant);

	///确认更新后触发
	///@param	pParticipant	被刷新的CParticipant
	///@param	poldParticipant	原来的值
	virtual void commitUpdate(CParticipant *pParticipant, CWriteableParticipant *pOldParticipant);
	
	///确认删除后触发
	///@param	pParticipant	已经删除的CParticipant
	virtual void commitRemove(CWriteableParticipant *pParticipant);

	///所有相关的触发器
	vector<CParticipantActionTrigger *> *pActionTriggers;
	vector<CParticipantCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableParticipant compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CUserFactory是一个用户的对象工厂。它包含了一批用户，
///同时又建立了如下索引，以方便查询：
///	UserIDIndex
///使用本对象工厂，可以完成对用户的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByUserID，唯一找到对象
///		使用startFindStartByUserID，findNextStartByUserID和endFindStartByUserID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CUserFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxUser，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CUserFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CUserFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的User
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的User，文件名将根据配置文件中的定义UserCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的User
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的User，文件名将根据配置文件中的定义UserCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CUserResource;

	///将一个CUser加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pUser	要加入的User
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CUser *add(CWriteableUser *pUser, CTransaction *pTransaction=NULL);
	
	///刷新该CUser的值
	///@param	pUser	被刷新的CUser
	///@param	pNewUser	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CUser *pUser, CWriteableUser *pNewUser, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pUser	  需要被刷新或者新增的CUser,等于NULL表示是需要新增的
	///@param	pNewUser	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CUser* addOrUpdate(CUser *pUser, CWriteableUser *pNewUser, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CUser，同时删除其索引
	///@param	pUser	要删除的CUser
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CUser *pUser, CTransaction *pTransaction=NULL);
	
	///获取某个CUser
	///@param	pUser	要读取的CUser
	///@param	pTragetUser	存放结果的CUser
	void retrieve(CUser *pUser, CWriteableUser *pTargetUser);
	
	///获取第一个CUser
	///@return	得到的第一个CUser，如果没有，则返回NULL
	CUser *getFirst(void);
	
	///获取下一个CUser
	///@return	得到下一个CUser，如果没有，则返回NULL
	CUser *getNext(void);
	
	///结束获取CUser
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CUserActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CUserActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CUserCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CUserCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///寻找CUser
	///@param	UserID	用户编号
	///@return	找到的CUser，如果找不到，返回NULL
	CUser *findByUserID( const CReadOnlyUserIDType&  UserID);

	///根据主码寻找
	///@param	UserID	用户编号
	///@return	找到的CUser，如果找不到，返回NULL
	CUser *findByPK( const CReadOnlyUserIDType&  UserID);
	
	///根据主键寻找CUser
	///@param	pUser	要找的值
	///@return	找到的CUser，如果找不到，返回NULL
	CUser *findByPK(CWriteableUser *pUser);

	///根据主键获取CUser
	///@param	pUser	要获取的值，同时用于存放返回的结果
	///@return	找到的CUser，如果找不到，返回NULL
	bool retrieveByPK(CWriteableUser *pUser);

	///根据主键增加新的CUser
	///@param	pUser	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	返回插入的CUser，如果插入失败，则返回NULL
	CUser *addByPK(CWriteableUser *pUser, CTransaction *pTransaction=NULL);

	///根据主键更新CUser的值
	///@param	pUser	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	///@return	true表示成功，false表示失败
	bool updateByPK(CWriteableUser *pUser, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///根据主键删除CUser
	///@param	pUser	要删除的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	true表示成功，false表示失败
	bool removeByPK(CWriteableUser *pUser, CTransaction *pTransaction=NULL);


	friend class CUserIteratorStartByUserID;

	///开始寻找CUser
	///@param	UserID	用户编号
	///@return	满足条件的地一个CUser，如果找不到，返回NULL
	CUser *startFindStartByUserID( const CReadOnlyUserIDType& UserID);

	///寻找下一个符合条件的CUser，必须在startFindStartByUserID以后，endFindStartByUserID之前叫用
	///@return	下一个满足条件CUser，如果已经没有一个满足要求了，则返回NULL
	CUser *findNextStartByUserID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindStartByUserID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CUser加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pUser	要加入的User
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CUser *internalAdd(CWriteableUser *pUser, bool bNoTransaction);
	
	
	///刷新该CUser的键值
	///@param	pUser	被刷新的CUser
	///@param	pNewUser	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CUser *pUser, CWriteableUser *pNewUser, bool updateIndex,bool bNoTransaction);
	
	///删除一个CUser，同时删除其索引
	///@param	pUser	要删除的CUser
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CUser *pUser, bool bNoTransaction);
/*
	///检查某个CUser是否属于本对象工厂
	///@param	pUser	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CUser *pUser);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于UserID的索引
	CAVLTree *pUserIDIndex;
	
	
	///按照UserID检索时，存储的查询参数
	CUserIDType queryUserIDInSearchStartByUserID;
	
	///按照UserID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchStartByUserID;
	
	///加入前触发
	///@param	pUser	要加入的User
	virtual void beforeAdd(CWriteableUser *pUser);
	
	///加入后触发
	///@param	pUser	已经加入的User
	virtual void afterAdd(CUser *pUser);

	///更新前触发	
	///@param	pUser	被刷新的CUser
	///@param	pNewUser	新的值
	virtual void beforeUpdate(CUser *pUser, CWriteableUser *pNewUser);
	
	///更新后触发
	///@param	pUser	被刷新的CUser
	virtual void afterUpdate(CUser *pUser);
	
	///删除前触发
	///@param	pUser	要删除的CUser
	virtual void beforeRemove(CUser *pUser);
	
	///确认加入后触发
	///@param	pUser	已经加入的User
	virtual void commitAdd(CUser *pUser);

	///确认更新后触发
	///@param	pUser	被刷新的CUser
	///@param	poldUser	原来的值
	virtual void commitUpdate(CUser *pUser, CWriteableUser *pOldUser);
	
	///确认删除后触发
	///@param	pUser	已经删除的CUser
	virtual void commitRemove(CWriteableUser *pUser);

	///所有相关的触发器
	vector<CUserActionTrigger *> *pActionTriggers;
	vector<CUserCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableUser compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CClientFactory是一个客户的对象工厂。它包含了一批客户，
///同时又建立了如下索引，以方便查询：
///使用本对象工厂，可以完成对客户的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByClientID，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CClientFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxClient，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CClientFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CClientFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的Client
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的Client，文件名将根据配置文件中的定义ClientCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的Client
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的Client，文件名将根据配置文件中的定义ClientCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CClientResource;

	///将一个CClient加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pClient	要加入的Client
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CClient *add(CWriteableClient *pClient, CTransaction *pTransaction=NULL);
	
	///刷新该CClient的值
	///@param	pClient	被刷新的CClient
	///@param	pNewClient	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CClient *pClient, CWriteableClient *pNewClient, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pClient	  需要被刷新或者新增的CClient,等于NULL表示是需要新增的
	///@param	pNewClient	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CClient* addOrUpdate(CClient *pClient, CWriteableClient *pNewClient, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CClient，同时删除其索引
	///@param	pClient	要删除的CClient
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CClient *pClient, CTransaction *pTransaction=NULL);
	
	///获取某个CClient
	///@param	pClient	要读取的CClient
	///@param	pTragetClient	存放结果的CClient
	void retrieve(CClient *pClient, CWriteableClient *pTargetClient);
	
	///获取第一个CClient
	///@return	得到的第一个CClient，如果没有，则返回NULL
	CClient *getFirst(void);
	
	///获取下一个CClient
	///@return	得到下一个CClient，如果没有，则返回NULL
	CClient *getNext(void);
	
	///结束获取CClient
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CClientActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CClientActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CClientCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CClientCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///寻找CClient
	///@param	ClientID	客户编号
	///@return	找到的CClient，如果找不到，返回NULL
	CClient *findByClientID( const CReadOnlyClientIDType&  ClientID);

	///根据主码寻找
	///@param	ClientID	客户编号
	///@return	找到的CClient，如果找不到，返回NULL
	CClient *findByPK( const CReadOnlyClientIDType&  ClientID);
	
	///根据主键寻找CClient
	///@param	pClient	要找的值
	///@return	找到的CClient，如果找不到，返回NULL
	CClient *findByPK(CWriteableClient *pClient);

	///根据主键获取CClient
	///@param	pClient	要获取的值，同时用于存放返回的结果
	///@return	找到的CClient，如果找不到，返回NULL
	bool retrieveByPK(CWriteableClient *pClient);

	///根据主键增加新的CClient
	///@param	pClient	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	返回插入的CClient，如果插入失败，则返回NULL
	CClient *addByPK(CWriteableClient *pClient, CTransaction *pTransaction=NULL);

	///根据主键更新CClient的值
	///@param	pClient	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	///@return	true表示成功，false表示失败
	bool updateByPK(CWriteableClient *pClient, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///根据主键删除CClient
	///@param	pClient	要删除的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	true表示成功，false表示失败
	bool removeByPK(CWriteableClient *pClient, CTransaction *pTransaction=NULL);


private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CClient加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pClient	要加入的Client
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CClient *internalAdd(CWriteableClient *pClient, bool bNoTransaction);
	
	
	///刷新该CClient的键值
	///@param	pClient	被刷新的CClient
	///@param	pNewClient	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CClient *pClient, CWriteableClient *pNewClient, bool updateIndex,bool bNoTransaction);
	
	///删除一个CClient，同时删除其索引
	///@param	pClient	要删除的CClient
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CClient *pClient, bool bNoTransaction);
/*
	///检查某个CClient是否属于本对象工厂
	///@param	pClient	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CClient *pClient);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	
	///基于ClientID的hash索引
	CHashIndex *pClientIDHashIndex;
	
	
	///加入前触发
	///@param	pClient	要加入的Client
	virtual void beforeAdd(CWriteableClient *pClient);
	
	///加入后触发
	///@param	pClient	已经加入的Client
	virtual void afterAdd(CClient *pClient);

	///更新前触发	
	///@param	pClient	被刷新的CClient
	///@param	pNewClient	新的值
	virtual void beforeUpdate(CClient *pClient, CWriteableClient *pNewClient);
	
	///更新后触发
	///@param	pClient	被刷新的CClient
	virtual void afterUpdate(CClient *pClient);
	
	///删除前触发
	///@param	pClient	要删除的CClient
	virtual void beforeRemove(CClient *pClient);
	
	///确认加入后触发
	///@param	pClient	已经加入的Client
	virtual void commitAdd(CClient *pClient);

	///确认更新后触发
	///@param	pClient	被刷新的CClient
	///@param	poldClient	原来的值
	virtual void commitUpdate(CClient *pClient, CWriteableClient *pOldClient);
	
	///确认删除后触发
	///@param	pClient	已经删除的CClient
	virtual void commitRemove(CWriteableClient *pClient);

	///所有相关的触发器
	vector<CClientActionTrigger *> *pActionTriggers;
	vector<CClientCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableClient compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CUserIPFactory是一个交易员IP地址的对象工厂。它包含了一批交易员IP地址，
///同时又建立了如下索引，以方便查询：
///	UserIPMaskIndex
///使用本对象工厂，可以完成对交易员IP地址的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByUserID，findNextByUserID和endFindByUserID完成查询操作
///		使用findByUserIPAndMask，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIPFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CUserIPFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxUserIP，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CUserIPFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CUserIPFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的UserIP
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的UserIP，文件名将根据配置文件中的定义UserIPCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的UserIP
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的UserIP，文件名将根据配置文件中的定义UserIPCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CUserIPResource;

	///将一个CUserIP加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pUserIP	要加入的UserIP
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CUserIP *add(CWriteableUserIP *pUserIP, CTransaction *pTransaction=NULL);
	
	///刷新该CUserIP的值
	///@param	pUserIP	被刷新的CUserIP
	///@param	pNewUserIP	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CUserIP *pUserIP, CWriteableUserIP *pNewUserIP, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pUserIP	  需要被刷新或者新增的CUserIP,等于NULL表示是需要新增的
	///@param	pNewUserIP	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CUserIP* addOrUpdate(CUserIP *pUserIP, CWriteableUserIP *pNewUserIP, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CUserIP，同时删除其索引
	///@param	pUserIP	要删除的CUserIP
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CUserIP *pUserIP, CTransaction *pTransaction=NULL);
	
	///获取某个CUserIP
	///@param	pUserIP	要读取的CUserIP
	///@param	pTragetUserIP	存放结果的CUserIP
	void retrieve(CUserIP *pUserIP, CWriteableUserIP *pTargetUserIP);
	
	///获取第一个CUserIP
	///@return	得到的第一个CUserIP，如果没有，则返回NULL
	CUserIP *getFirst(void);
	
	///获取下一个CUserIP
	///@return	得到下一个CUserIP，如果没有，则返回NULL
	CUserIP *getNext(void);
	
	///结束获取CUserIP
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CUserIPActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CUserIPActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CUserIPCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CUserIPCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CUserIPIteratorByUserID;

	///开始寻找CUserIP
	///@param	UserID	用户编号
	///@return	满足条件的地一个CUserIP，如果找不到，返回NULL
	CUserIP *startFindByUserID( const CReadOnlyUserIDType& UserID);

	///寻找下一个符合条件的CUserIP，必须在startFindByUserID以后，endFindByUserID之前叫用
	///@return	下一个满足条件CUserIP，如果已经没有一个满足要求了，则返回NULL
	CUserIP *findNextByUserID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByUserID(void);

	///寻找CUserIP
	///@param	UserID	用户编号
	///@param	IPAddress	IP地址
	///@param	IPMask	IP地址掩码
	///@return	找到的CUserIP，如果找不到，返回NULL
	CUserIP *findByUserIPAndMask( const CReadOnlyUserIDType&  UserID,  const CReadOnlyIPAddressType&  IPAddress,  const CReadOnlyIPAddressType&  IPMask);

	///根据主码寻找
	///@param	UserID	用户编号
	///@param	IPAddress	IP地址
	///@param	IPMask	IP地址掩码
	///@return	找到的CUserIP，如果找不到，返回NULL
	CUserIP *findByPK( const CReadOnlyUserIDType&  UserID,  const CReadOnlyIPAddressType&  IPAddress,  const CReadOnlyIPAddressType&  IPMask);
	
	///根据主键寻找CUserIP
	///@param	pUserIP	要找的值
	///@return	找到的CUserIP，如果找不到，返回NULL
	CUserIP *findByPK(CWriteableUserIP *pUserIP);

	///根据主键获取CUserIP
	///@param	pUserIP	要获取的值，同时用于存放返回的结果
	///@return	找到的CUserIP，如果找不到，返回NULL
	bool retrieveByPK(CWriteableUserIP *pUserIP);

	///根据主键增加新的CUserIP
	///@param	pUserIP	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	返回插入的CUserIP，如果插入失败，则返回NULL
	CUserIP *addByPK(CWriteableUserIP *pUserIP, CTransaction *pTransaction=NULL);

	///根据主键更新CUserIP的值
	///@param	pUserIP	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	///@return	true表示成功，false表示失败
	bool updateByPK(CWriteableUserIP *pUserIP, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///根据主键删除CUserIP
	///@param	pUserIP	要删除的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	true表示成功，false表示失败
	bool removeByPK(CWriteableUserIP *pUserIP, CTransaction *pTransaction=NULL);


private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CUserIP加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pUserIP	要加入的UserIP
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CUserIP *internalAdd(CWriteableUserIP *pUserIP, bool bNoTransaction);
	
	
	///刷新该CUserIP的键值
	///@param	pUserIP	被刷新的CUserIP
	///@param	pNewUserIP	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CUserIP *pUserIP, CWriteableUserIP *pNewUserIP, bool updateIndex,bool bNoTransaction);
	
	///删除一个CUserIP，同时删除其索引
	///@param	pUserIP	要删除的CUserIP
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CUserIP *pUserIP, bool bNoTransaction);
/*
	///检查某个CUserIP是否属于本对象工厂
	///@param	pUserIP	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CUserIP *pUserIP);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于UserID+IPAddress+IPMask的索引
	CAVLTree *pUserIPMaskIndex;
	
	
	///按照UserID检索时，存储的查询参数
	CUserIDType queryUserIDInSearchByUserID;
	
	///按照UserID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByUserID;
	
	///加入前触发
	///@param	pUserIP	要加入的UserIP
	virtual void beforeAdd(CWriteableUserIP *pUserIP);
	
	///加入后触发
	///@param	pUserIP	已经加入的UserIP
	virtual void afterAdd(CUserIP *pUserIP);

	///更新前触发	
	///@param	pUserIP	被刷新的CUserIP
	///@param	pNewUserIP	新的值
	virtual void beforeUpdate(CUserIP *pUserIP, CWriteableUserIP *pNewUserIP);
	
	///更新后触发
	///@param	pUserIP	被刷新的CUserIP
	virtual void afterUpdate(CUserIP *pUserIP);
	
	///删除前触发
	///@param	pUserIP	要删除的CUserIP
	virtual void beforeRemove(CUserIP *pUserIP);
	
	///确认加入后触发
	///@param	pUserIP	已经加入的UserIP
	virtual void commitAdd(CUserIP *pUserIP);

	///确认更新后触发
	///@param	pUserIP	被刷新的CUserIP
	///@param	poldUserIP	原来的值
	virtual void commitUpdate(CUserIP *pUserIP, CWriteableUserIP *pOldUserIP);
	
	///确认删除后触发
	///@param	pUserIP	已经删除的CUserIP
	virtual void commitRemove(CWriteableUserIP *pUserIP);

	///所有相关的触发器
	vector<CUserIPActionTrigger *> *pActionTriggers;
	vector<CUserIPCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableUserIP compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientFactory是一个会员客户关系的对象工厂。它包含了一批会员客户关系，
///同时又建立了如下索引，以方便查询：
///	PartClientIndex
///	ClientIndex
///使用本对象工厂，可以完成对会员客户关系的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByPartClient，唯一找到对象
///		使用startFindStartByParticipant，findNextStartByParticipant和endFindStartByParticipant完成查询操作
///		使用startFindStartByClient，findNextStartByClient和endFindStartByClient完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CPartClientFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxPartClient，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CPartClientFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CPartClientFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的PartClient
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的PartClient，文件名将根据配置文件中的定义PartClientCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的PartClient
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的PartClient，文件名将根据配置文件中的定义PartClientCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CPartClientResource;

	///将一个CPartClient加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pPartClient	要加入的PartClient
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CPartClient *add(CWriteablePartClient *pPartClient, CTransaction *pTransaction=NULL);
	
	///刷新该CPartClient的值
	///@param	pPartClient	被刷新的CPartClient
	///@param	pNewPartClient	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CPartClient *pPartClient, CWriteablePartClient *pNewPartClient, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pPartClient	  需要被刷新或者新增的CPartClient,等于NULL表示是需要新增的
	///@param	pNewPartClient	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CPartClient* addOrUpdate(CPartClient *pPartClient, CWriteablePartClient *pNewPartClient, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CPartClient，同时删除其索引
	///@param	pPartClient	要删除的CPartClient
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CPartClient *pPartClient, CTransaction *pTransaction=NULL);
	
	///获取某个CPartClient
	///@param	pPartClient	要读取的CPartClient
	///@param	pTragetPartClient	存放结果的CPartClient
	void retrieve(CPartClient *pPartClient, CWriteablePartClient *pTargetPartClient);
	
	///获取第一个CPartClient
	///@return	得到的第一个CPartClient，如果没有，则返回NULL
	CPartClient *getFirst(void);
	
	///获取下一个CPartClient
	///@return	得到下一个CPartClient，如果没有，则返回NULL
	CPartClient *getNext(void);
	
	///结束获取CPartClient
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CPartClientActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CPartClientActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CPartClientCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CPartClientCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///构造所有对应的会员的指针
	///@param	pFactory	构造对应的会员的指针时，寻找的对象工厂
	void linkAllParticipant(CParticipantFactory *pFactory);
	
	///构造所有对应的客户的指针
	///@param	pFactory	构造对应的客户的指针时，寻找的对象工厂
	void linkAllClient(CClientFactory *pFactory);
	
	///寻找CPartClient
	///@param	ParticipantID	会员号
	///@param	ClientID	客户号
	///@return	找到的CPartClient，如果找不到，返回NULL
	CPartClient *findByPartClient( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyClientIDType&  ClientID);

	///根据主码寻找
	///@param	ParticipantID	会员号
	///@param	ClientID	客户号
	///@return	找到的CPartClient，如果找不到，返回NULL
	CPartClient *findByPK( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyClientIDType&  ClientID);
	
	///根据主键寻找CPartClient
	///@param	pPartClient	要找的值
	///@return	找到的CPartClient，如果找不到，返回NULL
	CPartClient *findByPK(CWriteablePartClient *pPartClient);

	///根据主键获取CPartClient
	///@param	pPartClient	要获取的值，同时用于存放返回的结果
	///@return	找到的CPartClient，如果找不到，返回NULL
	bool retrieveByPK(CWriteablePartClient *pPartClient);

	///根据主键增加新的CPartClient
	///@param	pPartClient	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	返回插入的CPartClient，如果插入失败，则返回NULL
	CPartClient *addByPK(CWriteablePartClient *pPartClient, CTransaction *pTransaction=NULL);

	///根据主键更新CPartClient的值
	///@param	pPartClient	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	///@return	true表示成功，false表示失败
	bool updateByPK(CWriteablePartClient *pPartClient, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///根据主键删除CPartClient
	///@param	pPartClient	要删除的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	true表示成功，false表示失败
	bool removeByPK(CWriteablePartClient *pPartClient, CTransaction *pTransaction=NULL);


	friend class CPartClientIteratorStartByParticipant;

	///开始寻找CPartClient
	///@param	ParticipantID	会员号
	///@return	满足条件的地一个CPartClient，如果找不到，返回NULL
	CPartClient *startFindStartByParticipant( const CReadOnlyParticipantIDType& ParticipantID);

	///寻找下一个符合条件的CPartClient，必须在startFindStartByParticipant以后，endFindStartByParticipant之前叫用
	///@return	下一个满足条件CPartClient，如果已经没有一个满足要求了，则返回NULL
	CPartClient *findNextStartByParticipant(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindStartByParticipant(void);

	friend class CPartClientIteratorStartByClient;

	///开始寻找CPartClient
	///@param	ClientID	客户号
	///@return	满足条件的地一个CPartClient，如果找不到，返回NULL
	CPartClient *startFindStartByClient( const CReadOnlyClientIDType& ClientID);

	///寻找下一个符合条件的CPartClient，必须在startFindStartByClient以后，endFindStartByClient之前叫用
	///@return	下一个满足条件CPartClient，如果已经没有一个满足要求了，则返回NULL
	CPartClient *findNextStartByClient(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindStartByClient(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CPartClient加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pPartClient	要加入的PartClient
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CPartClient *internalAdd(CWriteablePartClient *pPartClient, bool bNoTransaction);
	
	
	///刷新该CPartClient的键值
	///@param	pPartClient	被刷新的CPartClient
	///@param	pNewPartClient	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CPartClient *pPartClient, CWriteablePartClient *pNewPartClient, bool updateIndex,bool bNoTransaction);
	
	///删除一个CPartClient，同时删除其索引
	///@param	pPartClient	要删除的CPartClient
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CPartClient *pPartClient, bool bNoTransaction);
/*
	///检查某个CPartClient是否属于本对象工厂
	///@param	pPartClient	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CPartClient *pPartClient);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ParticipantID+ClientID的索引
	CAVLTree *pPartClientIndex;
	///基于ClientID的索引
	CAVLTree *pClientIndex;
	
	///基于PartClient的hash索引
	CHashIndex *pPartClientHashIndex;
	
	///按照ParticipantID检索时，存储的查询参数
	CParticipantIDType queryParticipantIDInSearchStartByParticipant;
	
	///按照ParticipantID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchStartByParticipant;
	///按照ClientID检索时，存储的查询参数
	CClientIDType queryClientIDInSearchStartByClient;
	
	///按照ClientID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchStartByClient;
	
	///加入前触发
	///@param	pPartClient	要加入的PartClient
	virtual void beforeAdd(CWriteablePartClient *pPartClient);
	
	///加入后触发
	///@param	pPartClient	已经加入的PartClient
	virtual void afterAdd(CPartClient *pPartClient);

	///更新前触发	
	///@param	pPartClient	被刷新的CPartClient
	///@param	pNewPartClient	新的值
	virtual void beforeUpdate(CPartClient *pPartClient, CWriteablePartClient *pNewPartClient);
	
	///更新后触发
	///@param	pPartClient	被刷新的CPartClient
	virtual void afterUpdate(CPartClient *pPartClient);
	
	///删除前触发
	///@param	pPartClient	要删除的CPartClient
	virtual void beforeRemove(CPartClient *pPartClient);
	
	///确认加入后触发
	///@param	pPartClient	已经加入的PartClient
	virtual void commitAdd(CPartClient *pPartClient);

	///确认更新后触发
	///@param	pPartClient	被刷新的CPartClient
	///@param	poldPartClient	原来的值
	virtual void commitUpdate(CPartClient *pPartClient, CWriteablePartClient *pOldPartClient);
	
	///确认删除后触发
	///@param	pPartClient	已经删除的CPartClient
	virtual void commitRemove(CWriteablePartClient *pPartClient);

	///所有相关的触发器
	vector<CPartClientActionTrigger *> *pActionTriggers;
	vector<CPartClientCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteablePartClient compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CClearingTradingPartFactory是一个结算交易会员关系的对象工厂。它包含了一批结算交易会员关系，
///同时又建立了如下索引，以方便查询：
///使用本对象工厂，可以完成对结算交易会员关系的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByParticipant，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingTradingPartFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CClearingTradingPartFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxClearingTradingPart，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CClearingTradingPartFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CClearingTradingPartFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的ClearingTradingPart
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的ClearingTradingPart，文件名将根据配置文件中的定义ClearingTradingPartCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的ClearingTradingPart
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的ClearingTradingPart，文件名将根据配置文件中的定义ClearingTradingPartCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CClearingTradingPartResource;

	///将一个CClearingTradingPart加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pClearingTradingPart	要加入的ClearingTradingPart
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CClearingTradingPart *add(CWriteableClearingTradingPart *pClearingTradingPart, CTransaction *pTransaction=NULL);
	
	///刷新该CClearingTradingPart的值
	///@param	pClearingTradingPart	被刷新的CClearingTradingPart
	///@param	pNewClearingTradingPart	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CClearingTradingPart *pClearingTradingPart, CWriteableClearingTradingPart *pNewClearingTradingPart, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pClearingTradingPart	  需要被刷新或者新增的CClearingTradingPart,等于NULL表示是需要新增的
	///@param	pNewClearingTradingPart	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CClearingTradingPart* addOrUpdate(CClearingTradingPart *pClearingTradingPart, CWriteableClearingTradingPart *pNewClearingTradingPart, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CClearingTradingPart，同时删除其索引
	///@param	pClearingTradingPart	要删除的CClearingTradingPart
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CClearingTradingPart *pClearingTradingPart, CTransaction *pTransaction=NULL);
	
	///获取某个CClearingTradingPart
	///@param	pClearingTradingPart	要读取的CClearingTradingPart
	///@param	pTragetClearingTradingPart	存放结果的CClearingTradingPart
	void retrieve(CClearingTradingPart *pClearingTradingPart, CWriteableClearingTradingPart *pTargetClearingTradingPart);
	
	///获取第一个CClearingTradingPart
	///@return	得到的第一个CClearingTradingPart，如果没有，则返回NULL
	CClearingTradingPart *getFirst(void);
	
	///获取下一个CClearingTradingPart
	///@return	得到下一个CClearingTradingPart，如果没有，则返回NULL
	CClearingTradingPart *getNext(void);
	
	///结束获取CClearingTradingPart
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CClearingTradingPartActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CClearingTradingPartActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CClearingTradingPartCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CClearingTradingPartCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///寻找CClearingTradingPart
	///@param	ParticipantID	会员号
	///@return	找到的CClearingTradingPart，如果找不到，返回NULL
	CClearingTradingPart *findByParticipant( const CReadOnlyParticipantIDType&  ParticipantID);

	///根据主码寻找
	///@param	ParticipantID	会员号
	///@return	找到的CClearingTradingPart，如果找不到，返回NULL
	CClearingTradingPart *findByPK( const CReadOnlyParticipantIDType&  ParticipantID);
	
	///根据主键寻找CClearingTradingPart
	///@param	pClearingTradingPart	要找的值
	///@return	找到的CClearingTradingPart，如果找不到，返回NULL
	CClearingTradingPart *findByPK(CWriteableClearingTradingPart *pClearingTradingPart);

	///根据主键获取CClearingTradingPart
	///@param	pClearingTradingPart	要获取的值，同时用于存放返回的结果
	///@return	找到的CClearingTradingPart，如果找不到，返回NULL
	bool retrieveByPK(CWriteableClearingTradingPart *pClearingTradingPart);

	///根据主键增加新的CClearingTradingPart
	///@param	pClearingTradingPart	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	返回插入的CClearingTradingPart，如果插入失败，则返回NULL
	CClearingTradingPart *addByPK(CWriteableClearingTradingPart *pClearingTradingPart, CTransaction *pTransaction=NULL);

	///根据主键更新CClearingTradingPart的值
	///@param	pClearingTradingPart	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	///@return	true表示成功，false表示失败
	bool updateByPK(CWriteableClearingTradingPart *pClearingTradingPart, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///根据主键删除CClearingTradingPart
	///@param	pClearingTradingPart	要删除的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	true表示成功，false表示失败
	bool removeByPK(CWriteableClearingTradingPart *pClearingTradingPart, CTransaction *pTransaction=NULL);


private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CClearingTradingPart加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pClearingTradingPart	要加入的ClearingTradingPart
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CClearingTradingPart *internalAdd(CWriteableClearingTradingPart *pClearingTradingPart, bool bNoTransaction);
	
	
	///刷新该CClearingTradingPart的键值
	///@param	pClearingTradingPart	被刷新的CClearingTradingPart
	///@param	pNewClearingTradingPart	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CClearingTradingPart *pClearingTradingPart, CWriteableClearingTradingPart *pNewClearingTradingPart, bool updateIndex,bool bNoTransaction);
	
	///删除一个CClearingTradingPart，同时删除其索引
	///@param	pClearingTradingPart	要删除的CClearingTradingPart
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CClearingTradingPart *pClearingTradingPart, bool bNoTransaction);
/*
	///检查某个CClearingTradingPart是否属于本对象工厂
	///@param	pClearingTradingPart	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CClearingTradingPart *pClearingTradingPart);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	
	///基于ParticipantID的hash索引
	CHashIndex *pParticipantIDHashIndex;
	
	
	///加入前触发
	///@param	pClearingTradingPart	要加入的ClearingTradingPart
	virtual void beforeAdd(CWriteableClearingTradingPart *pClearingTradingPart);
	
	///加入后触发
	///@param	pClearingTradingPart	已经加入的ClearingTradingPart
	virtual void afterAdd(CClearingTradingPart *pClearingTradingPart);

	///更新前触发	
	///@param	pClearingTradingPart	被刷新的CClearingTradingPart
	///@param	pNewClearingTradingPart	新的值
	virtual void beforeUpdate(CClearingTradingPart *pClearingTradingPart, CWriteableClearingTradingPart *pNewClearingTradingPart);
	
	///更新后触发
	///@param	pClearingTradingPart	被刷新的CClearingTradingPart
	virtual void afterUpdate(CClearingTradingPart *pClearingTradingPart);
	
	///删除前触发
	///@param	pClearingTradingPart	要删除的CClearingTradingPart
	virtual void beforeRemove(CClearingTradingPart *pClearingTradingPart);
	
	///确认加入后触发
	///@param	pClearingTradingPart	已经加入的ClearingTradingPart
	virtual void commitAdd(CClearingTradingPart *pClearingTradingPart);

	///确认更新后触发
	///@param	pClearingTradingPart	被刷新的CClearingTradingPart
	///@param	poldClearingTradingPart	原来的值
	virtual void commitUpdate(CClearingTradingPart *pClearingTradingPart, CWriteableClearingTradingPart *pOldClearingTradingPart);
	
	///确认删除后触发
	///@param	pClearingTradingPart	已经删除的CClearingTradingPart
	virtual void commitRemove(CWriteableClearingTradingPart *pClearingTradingPart);

	///所有相关的触发器
	vector<CClearingTradingPartActionTrigger *> *pActionTriggers;
	vector<CClearingTradingPartCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableClearingTradingPart compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CAliasDefineFactory是一个别名定义的对象工厂。它包含了一批别名定义，
///同时又建立了如下索引，以方便查询：
///使用本对象工厂，可以完成对别名定义的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAliasDefineFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CAliasDefineFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxAliasDefine，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CAliasDefineFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CAliasDefineFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的AliasDefine
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的AliasDefine，文件名将根据配置文件中的定义AliasDefineCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的AliasDefine
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的AliasDefine，文件名将根据配置文件中的定义AliasDefineCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CAliasDefineResource;

	///将一个CAliasDefine加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pAliasDefine	要加入的AliasDefine
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CAliasDefine *add(CWriteableAliasDefine *pAliasDefine, CTransaction *pTransaction=NULL);
	
	///刷新该CAliasDefine的值
	///@param	pAliasDefine	被刷新的CAliasDefine
	///@param	pNewAliasDefine	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CAliasDefine *pAliasDefine, CWriteableAliasDefine *pNewAliasDefine, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pAliasDefine	  需要被刷新或者新增的CAliasDefine,等于NULL表示是需要新增的
	///@param	pNewAliasDefine	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CAliasDefine* addOrUpdate(CAliasDefine *pAliasDefine, CWriteableAliasDefine *pNewAliasDefine, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CAliasDefine，同时删除其索引
	///@param	pAliasDefine	要删除的CAliasDefine
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CAliasDefine *pAliasDefine, CTransaction *pTransaction=NULL);
	
	///获取某个CAliasDefine
	///@param	pAliasDefine	要读取的CAliasDefine
	///@param	pTragetAliasDefine	存放结果的CAliasDefine
	void retrieve(CAliasDefine *pAliasDefine, CWriteableAliasDefine *pTargetAliasDefine);
	
	///获取第一个CAliasDefine
	///@return	得到的第一个CAliasDefine，如果没有，则返回NULL
	CAliasDefine *getFirst(void);
	
	///获取下一个CAliasDefine
	///@return	得到下一个CAliasDefine，如果没有，则返回NULL
	CAliasDefine *getNext(void);
	
	///结束获取CAliasDefine
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CAliasDefineActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CAliasDefineActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CAliasDefineCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CAliasDefineCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CAliasDefine加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pAliasDefine	要加入的AliasDefine
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CAliasDefine *internalAdd(CWriteableAliasDefine *pAliasDefine, bool bNoTransaction);
	
	
	///刷新该CAliasDefine的键值
	///@param	pAliasDefine	被刷新的CAliasDefine
	///@param	pNewAliasDefine	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CAliasDefine *pAliasDefine, CWriteableAliasDefine *pNewAliasDefine, bool updateIndex,bool bNoTransaction);
	
	///删除一个CAliasDefine，同时删除其索引
	///@param	pAliasDefine	要删除的CAliasDefine
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CAliasDefine *pAliasDefine, bool bNoTransaction);
/*
	///检查某个CAliasDefine是否属于本对象工厂
	///@param	pAliasDefine	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CAliasDefine *pAliasDefine);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	
	
	
	///加入前触发
	///@param	pAliasDefine	要加入的AliasDefine
	virtual void beforeAdd(CWriteableAliasDefine *pAliasDefine);
	
	///加入后触发
	///@param	pAliasDefine	已经加入的AliasDefine
	virtual void afterAdd(CAliasDefine *pAliasDefine);

	///更新前触发	
	///@param	pAliasDefine	被刷新的CAliasDefine
	///@param	pNewAliasDefine	新的值
	virtual void beforeUpdate(CAliasDefine *pAliasDefine, CWriteableAliasDefine *pNewAliasDefine);
	
	///更新后触发
	///@param	pAliasDefine	被刷新的CAliasDefine
	virtual void afterUpdate(CAliasDefine *pAliasDefine);
	
	///删除前触发
	///@param	pAliasDefine	要删除的CAliasDefine
	virtual void beforeRemove(CAliasDefine *pAliasDefine);
	
	///确认加入后触发
	///@param	pAliasDefine	已经加入的AliasDefine
	virtual void commitAdd(CAliasDefine *pAliasDefine);

	///确认更新后触发
	///@param	pAliasDefine	被刷新的CAliasDefine
	///@param	poldAliasDefine	原来的值
	virtual void commitUpdate(CAliasDefine *pAliasDefine, CWriteableAliasDefine *pOldAliasDefine);
	
	///确认删除后触发
	///@param	pAliasDefine	已经删除的CAliasDefine
	virtual void commitRemove(CWriteableAliasDefine *pAliasDefine);

	///所有相关的触发器
	vector<CAliasDefineActionTrigger *> *pActionTriggers;
	vector<CAliasDefineCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableAliasDefine compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CUserFunctionRightFactory是一个用户功能权限的对象工厂。它包含了一批用户功能权限，
///同时又建立了如下索引，以方便查询：
///使用本对象工厂，可以完成对用户功能权限的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByUserFunction，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRightFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CUserFunctionRightFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxUserFunctionRight，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CUserFunctionRightFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CUserFunctionRightFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的UserFunctionRight
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的UserFunctionRight，文件名将根据配置文件中的定义UserFunctionRightCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的UserFunctionRight
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的UserFunctionRight，文件名将根据配置文件中的定义UserFunctionRightCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CUserFunctionRightResource;

	///将一个CUserFunctionRight加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pUserFunctionRight	要加入的UserFunctionRight
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CUserFunctionRight *add(CWriteableUserFunctionRight *pUserFunctionRight, CTransaction *pTransaction=NULL);
	
	///刷新该CUserFunctionRight的值
	///@param	pUserFunctionRight	被刷新的CUserFunctionRight
	///@param	pNewUserFunctionRight	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CUserFunctionRight *pUserFunctionRight, CWriteableUserFunctionRight *pNewUserFunctionRight, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pUserFunctionRight	  需要被刷新或者新增的CUserFunctionRight,等于NULL表示是需要新增的
	///@param	pNewUserFunctionRight	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CUserFunctionRight* addOrUpdate(CUserFunctionRight *pUserFunctionRight, CWriteableUserFunctionRight *pNewUserFunctionRight, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CUserFunctionRight，同时删除其索引
	///@param	pUserFunctionRight	要删除的CUserFunctionRight
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CUserFunctionRight *pUserFunctionRight, CTransaction *pTransaction=NULL);
	
	///获取某个CUserFunctionRight
	///@param	pUserFunctionRight	要读取的CUserFunctionRight
	///@param	pTragetUserFunctionRight	存放结果的CUserFunctionRight
	void retrieve(CUserFunctionRight *pUserFunctionRight, CWriteableUserFunctionRight *pTargetUserFunctionRight);
	
	///获取第一个CUserFunctionRight
	///@return	得到的第一个CUserFunctionRight，如果没有，则返回NULL
	CUserFunctionRight *getFirst(void);
	
	///获取下一个CUserFunctionRight
	///@return	得到下一个CUserFunctionRight，如果没有，则返回NULL
	CUserFunctionRight *getNext(void);
	
	///结束获取CUserFunctionRight
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CUserFunctionRightActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CUserFunctionRightActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CUserFunctionRightCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CUserFunctionRightCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///寻找CUserFunctionRight
	///@param	UserID	用户编码
	///@param	FunctionCode	功能代码
	///@return	找到的CUserFunctionRight，如果找不到，返回NULL
	CUserFunctionRight *findByUserFunction( const CReadOnlyUserIDType&  UserID,  const CReadOnlyFunctionCodeType&  FunctionCode);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CUserFunctionRight加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pUserFunctionRight	要加入的UserFunctionRight
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CUserFunctionRight *internalAdd(CWriteableUserFunctionRight *pUserFunctionRight, bool bNoTransaction);
	
	
	///刷新该CUserFunctionRight的键值
	///@param	pUserFunctionRight	被刷新的CUserFunctionRight
	///@param	pNewUserFunctionRight	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CUserFunctionRight *pUserFunctionRight, CWriteableUserFunctionRight *pNewUserFunctionRight, bool updateIndex,bool bNoTransaction);
	
	///删除一个CUserFunctionRight，同时删除其索引
	///@param	pUserFunctionRight	要删除的CUserFunctionRight
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CUserFunctionRight *pUserFunctionRight, bool bNoTransaction);
/*
	///检查某个CUserFunctionRight是否属于本对象工厂
	///@param	pUserFunctionRight	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CUserFunctionRight *pUserFunctionRight);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	
	///基于UserFunction的hash索引
	CHashIndex *pUserFunctionHashIndex;
	
	
	///加入前触发
	///@param	pUserFunctionRight	要加入的UserFunctionRight
	virtual void beforeAdd(CWriteableUserFunctionRight *pUserFunctionRight);
	
	///加入后触发
	///@param	pUserFunctionRight	已经加入的UserFunctionRight
	virtual void afterAdd(CUserFunctionRight *pUserFunctionRight);

	///更新前触发	
	///@param	pUserFunctionRight	被刷新的CUserFunctionRight
	///@param	pNewUserFunctionRight	新的值
	virtual void beforeUpdate(CUserFunctionRight *pUserFunctionRight, CWriteableUserFunctionRight *pNewUserFunctionRight);
	
	///更新后触发
	///@param	pUserFunctionRight	被刷新的CUserFunctionRight
	virtual void afterUpdate(CUserFunctionRight *pUserFunctionRight);
	
	///删除前触发
	///@param	pUserFunctionRight	要删除的CUserFunctionRight
	virtual void beforeRemove(CUserFunctionRight *pUserFunctionRight);
	
	///确认加入后触发
	///@param	pUserFunctionRight	已经加入的UserFunctionRight
	virtual void commitAdd(CUserFunctionRight *pUserFunctionRight);

	///确认更新后触发
	///@param	pUserFunctionRight	被刷新的CUserFunctionRight
	///@param	poldUserFunctionRight	原来的值
	virtual void commitUpdate(CUserFunctionRight *pUserFunctionRight, CWriteableUserFunctionRight *pOldUserFunctionRight);
	
	///确认删除后触发
	///@param	pUserFunctionRight	已经删除的CUserFunctionRight
	virtual void commitRemove(CWriteableUserFunctionRight *pUserFunctionRight);

	///所有相关的触发器
	vector<CUserFunctionRightActionTrigger *> *pActionTriggers;
	vector<CUserFunctionRightCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableUserFunctionRight compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CAccountFactory是一个资金账户的对象工厂。它包含了一批资金账户，
///同时又建立了如下索引，以方便查询：
///	AccountIDIndex
///	ParticipantIDIndex
///使用本对象工厂，可以完成对资金账户的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByAccountID，唯一找到对象
///		使用startFindStartByParticipantID，findNextStartByParticipantID和endFindStartByParticipantID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAccountFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CAccountFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxAccount，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CAccountFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CAccountFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的Account
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的Account，文件名将根据配置文件中的定义AccountCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的Account
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的Account，文件名将根据配置文件中的定义AccountCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CAccountResource;

	///将一个CAccount加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pAccount	要加入的Account
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CAccount *add(CWriteableAccount *pAccount, CTransaction *pTransaction=NULL);
	
	///刷新该CAccount的值
	///@param	pAccount	被刷新的CAccount
	///@param	pNewAccount	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CAccount *pAccount, CWriteableAccount *pNewAccount, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pAccount	  需要被刷新或者新增的CAccount,等于NULL表示是需要新增的
	///@param	pNewAccount	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CAccount* addOrUpdate(CAccount *pAccount, CWriteableAccount *pNewAccount, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CAccount，同时删除其索引
	///@param	pAccount	要删除的CAccount
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CAccount *pAccount, CTransaction *pTransaction=NULL);
	
	///获取某个CAccount
	///@param	pAccount	要读取的CAccount
	///@param	pTragetAccount	存放结果的CAccount
	void retrieve(CAccount *pAccount, CWriteableAccount *pTargetAccount);
	
	///获取第一个CAccount
	///@return	得到的第一个CAccount，如果没有，则返回NULL
	CAccount *getFirst(void);
	
	///获取下一个CAccount
	///@return	得到下一个CAccount，如果没有，则返回NULL
	CAccount *getNext(void);
	
	///结束获取CAccount
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CAccountActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CAccountActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CAccountCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CAccountCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///构造所有对应的交易账户的指针
	///@param	pFactory	构造对应的交易账户的指针时，寻找的对象工厂
	void linkAllTradingAccount(CTradingAccountFactory *pFactory);
	
	///寻找CAccount
	///@param	AccountID	资金帐号
	///@return	找到的CAccount，如果找不到，返回NULL
	CAccount *findByAccountID( const CReadOnlyAccountIDType&  AccountID);



	friend class CAccountIteratorStartByParticipantID;

	///开始寻找CAccount
	///@param	ParticipantID	会员编号
	///@return	满足条件的地一个CAccount，如果找不到，返回NULL
	CAccount *startFindStartByParticipantID( const CReadOnlyParticipantIDType& ParticipantID);

	///寻找下一个符合条件的CAccount，必须在startFindStartByParticipantID以后，endFindStartByParticipantID之前叫用
	///@return	下一个满足条件CAccount，如果已经没有一个满足要求了，则返回NULL
	CAccount *findNextStartByParticipantID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindStartByParticipantID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CAccount加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pAccount	要加入的Account
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CAccount *internalAdd(CWriteableAccount *pAccount, bool bNoTransaction);
	
	
	///刷新该CAccount的键值
	///@param	pAccount	被刷新的CAccount
	///@param	pNewAccount	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CAccount *pAccount, CWriteableAccount *pNewAccount, bool updateIndex,bool bNoTransaction);
	
	///删除一个CAccount，同时删除其索引
	///@param	pAccount	要删除的CAccount
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CAccount *pAccount, bool bNoTransaction);
/*
	///检查某个CAccount是否属于本对象工厂
	///@param	pAccount	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CAccount *pAccount);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于AccountID的索引
	CAVLTree *pAccountIDIndex;
	///基于ParticipantID的索引
	CAVLTree *pParticipantIDIndex;
	
	
	///按照ParticipantID检索时，存储的查询参数
	CParticipantIDType queryParticipantIDInSearchStartByParticipantID;
	
	///按照ParticipantID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchStartByParticipantID;
	
	///加入前触发
	///@param	pAccount	要加入的Account
	virtual void beforeAdd(CWriteableAccount *pAccount);
	
	///加入后触发
	///@param	pAccount	已经加入的Account
	virtual void afterAdd(CAccount *pAccount);

	///更新前触发	
	///@param	pAccount	被刷新的CAccount
	///@param	pNewAccount	新的值
	virtual void beforeUpdate(CAccount *pAccount, CWriteableAccount *pNewAccount);
	
	///更新后触发
	///@param	pAccount	被刷新的CAccount
	virtual void afterUpdate(CAccount *pAccount);
	
	///删除前触发
	///@param	pAccount	要删除的CAccount
	virtual void beforeRemove(CAccount *pAccount);
	
	///确认加入后触发
	///@param	pAccount	已经加入的Account
	virtual void commitAdd(CAccount *pAccount);

	///确认更新后触发
	///@param	pAccount	被刷新的CAccount
	///@param	poldAccount	原来的值
	virtual void commitUpdate(CAccount *pAccount, CWriteableAccount *pOldAccount);
	
	///确认删除后触发
	///@param	pAccount	已经删除的CAccount
	virtual void commitRemove(CWriteableAccount *pAccount);

	///所有相关的触发器
	vector<CAccountActionTrigger *> *pActionTriggers;
	vector<CAccountCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableAccount compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CUserCommFluxFactory是一个用户通讯量的对象工厂。它包含了一批用户通讯量，
///同时又建立了如下索引，以方便查询：
///使用本对象工厂，可以完成对用户通讯量的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByUserID，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserCommFluxFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CUserCommFluxFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxUserCommFlux，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CUserCommFluxFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CUserCommFluxFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的UserCommFlux
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的UserCommFlux，文件名将根据配置文件中的定义UserCommFluxCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的UserCommFlux
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的UserCommFlux，文件名将根据配置文件中的定义UserCommFluxCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CUserCommFluxResource;

	///将一个CUserCommFlux加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pUserCommFlux	要加入的UserCommFlux
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CUserCommFlux *add(CWriteableUserCommFlux *pUserCommFlux, CTransaction *pTransaction=NULL);
	
	///刷新该CUserCommFlux的值
	///@param	pUserCommFlux	被刷新的CUserCommFlux
	///@param	pNewUserCommFlux	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CUserCommFlux *pUserCommFlux, CWriteableUserCommFlux *pNewUserCommFlux, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pUserCommFlux	  需要被刷新或者新增的CUserCommFlux,等于NULL表示是需要新增的
	///@param	pNewUserCommFlux	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CUserCommFlux* addOrUpdate(CUserCommFlux *pUserCommFlux, CWriteableUserCommFlux *pNewUserCommFlux, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CUserCommFlux，同时删除其索引
	///@param	pUserCommFlux	要删除的CUserCommFlux
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CUserCommFlux *pUserCommFlux, CTransaction *pTransaction=NULL);
	
	///获取某个CUserCommFlux
	///@param	pUserCommFlux	要读取的CUserCommFlux
	///@param	pTragetUserCommFlux	存放结果的CUserCommFlux
	void retrieve(CUserCommFlux *pUserCommFlux, CWriteableUserCommFlux *pTargetUserCommFlux);
	
	///获取第一个CUserCommFlux
	///@return	得到的第一个CUserCommFlux，如果没有，则返回NULL
	CUserCommFlux *getFirst(void);
	
	///获取下一个CUserCommFlux
	///@return	得到下一个CUserCommFlux，如果没有，则返回NULL
	CUserCommFlux *getNext(void);
	
	///结束获取CUserCommFlux
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CUserCommFluxActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CUserCommFluxActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CUserCommFluxCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CUserCommFluxCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///寻找CUserCommFlux
	///@param	UserID	用户编码
	///@return	找到的CUserCommFlux，如果找不到，返回NULL
	CUserCommFlux *findByUserID( const CReadOnlyUserIDType&  UserID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CUserCommFlux加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pUserCommFlux	要加入的UserCommFlux
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CUserCommFlux *internalAdd(CWriteableUserCommFlux *pUserCommFlux, bool bNoTransaction);
	
	
	///刷新该CUserCommFlux的键值
	///@param	pUserCommFlux	被刷新的CUserCommFlux
	///@param	pNewUserCommFlux	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CUserCommFlux *pUserCommFlux, CWriteableUserCommFlux *pNewUserCommFlux, bool updateIndex,bool bNoTransaction);
	
	///删除一个CUserCommFlux，同时删除其索引
	///@param	pUserCommFlux	要删除的CUserCommFlux
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CUserCommFlux *pUserCommFlux, bool bNoTransaction);
/*
	///检查某个CUserCommFlux是否属于本对象工厂
	///@param	pUserCommFlux	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CUserCommFlux *pUserCommFlux);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	
	///基于UserID的hash索引
	CHashIndex *pUserIDHashIndex;
	
	
	///加入前触发
	///@param	pUserCommFlux	要加入的UserCommFlux
	virtual void beforeAdd(CWriteableUserCommFlux *pUserCommFlux);
	
	///加入后触发
	///@param	pUserCommFlux	已经加入的UserCommFlux
	virtual void afterAdd(CUserCommFlux *pUserCommFlux);

	///更新前触发	
	///@param	pUserCommFlux	被刷新的CUserCommFlux
	///@param	pNewUserCommFlux	新的值
	virtual void beforeUpdate(CUserCommFlux *pUserCommFlux, CWriteableUserCommFlux *pNewUserCommFlux);
	
	///更新后触发
	///@param	pUserCommFlux	被刷新的CUserCommFlux
	virtual void afterUpdate(CUserCommFlux *pUserCommFlux);
	
	///删除前触发
	///@param	pUserCommFlux	要删除的CUserCommFlux
	virtual void beforeRemove(CUserCommFlux *pUserCommFlux);
	
	///确认加入后触发
	///@param	pUserCommFlux	已经加入的UserCommFlux
	virtual void commitAdd(CUserCommFlux *pUserCommFlux);

	///确认更新后触发
	///@param	pUserCommFlux	被刷新的CUserCommFlux
	///@param	poldUserCommFlux	原来的值
	virtual void commitUpdate(CUserCommFlux *pUserCommFlux, CWriteableUserCommFlux *pOldUserCommFlux);
	
	///确认删除后触发
	///@param	pUserCommFlux	已经删除的CUserCommFlux
	virtual void commitRemove(CWriteableUserCommFlux *pUserCommFlux);

	///所有相关的触发器
	vector<CUserCommFluxActionTrigger *> *pActionTriggers;
	vector<CUserCommFluxCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableUserCommFlux compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataLogFactory是一个行情流水的对象工厂。它包含了一批行情流水，
///同时又建立了如下索引，以方便查询：
///	MarketDataLogNoIndex
///使用本对象工厂，可以完成对行情流水的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByMarketDataLogNo，findNextByMarketDataLogNo和endFindByMarketDataLogNo完成查询操作
///		使用findMaxMarketDataLogNo，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLogFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CMarketDataLogFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxMarketDataLog，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CMarketDataLogFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CMarketDataLogFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的MarketDataLog
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的MarketDataLog，文件名将根据配置文件中的定义MarketDataLogCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的MarketDataLog
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的MarketDataLog，文件名将根据配置文件中的定义MarketDataLogCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CMarketDataLogResource;

	///将一个CMarketDataLog加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pMarketDataLog	要加入的MarketDataLog
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CMarketDataLog *add(CWriteableMarketDataLog *pMarketDataLog, CTransaction *pTransaction=NULL);
	
	///刷新该CMarketDataLog的值
	///@param	pMarketDataLog	被刷新的CMarketDataLog
	///@param	pNewMarketDataLog	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CMarketDataLog *pMarketDataLog, CWriteableMarketDataLog *pNewMarketDataLog, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pMarketDataLog	  需要被刷新或者新增的CMarketDataLog,等于NULL表示是需要新增的
	///@param	pNewMarketDataLog	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CMarketDataLog* addOrUpdate(CMarketDataLog *pMarketDataLog, CWriteableMarketDataLog *pNewMarketDataLog, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CMarketDataLog，同时删除其索引
	///@param	pMarketDataLog	要删除的CMarketDataLog
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CMarketDataLog *pMarketDataLog, CTransaction *pTransaction=NULL);
	
	///获取某个CMarketDataLog
	///@param	pMarketDataLog	要读取的CMarketDataLog
	///@param	pTragetMarketDataLog	存放结果的CMarketDataLog
	void retrieve(CMarketDataLog *pMarketDataLog, CWriteableMarketDataLog *pTargetMarketDataLog);
	
	///获取第一个CMarketDataLog
	///@return	得到的第一个CMarketDataLog，如果没有，则返回NULL
	CMarketDataLog *getFirst(void);
	
	///获取下一个CMarketDataLog
	///@return	得到下一个CMarketDataLog，如果没有，则返回NULL
	CMarketDataLog *getNext(void);
	
	///结束获取CMarketDataLog
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CMarketDataLogActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CMarketDataLogActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CMarketDataLogCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CMarketDataLogCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CMarketDataLogIteratorByMarketDataLogNo;

	///开始寻找CMarketDataLog
	///@param	MarketDataLogNo	行情流水编号
	///@return	满足条件的地一个CMarketDataLog，如果找不到，返回NULL
	CMarketDataLog *startFindByMarketDataLogNo( const CReadOnlySequenceNoType& MarketDataLogNo);

	///寻找下一个符合条件的CMarketDataLog，必须在startFindByMarketDataLogNo以后，endFindByMarketDataLogNo之前叫用
	///@return	下一个满足条件CMarketDataLog，如果已经没有一个满足要求了，则返回NULL
	CMarketDataLog *findNextByMarketDataLogNo(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByMarketDataLogNo(void);

	///寻找CMarketDataLog
	///@return	找到的CMarketDataLog，如果找不到，返回NULL
	CMarketDataLog *findMaxMarketDataLogNo();



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CMarketDataLog加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pMarketDataLog	要加入的MarketDataLog
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CMarketDataLog *internalAdd(CWriteableMarketDataLog *pMarketDataLog, bool bNoTransaction);
	
	
	///刷新该CMarketDataLog的键值
	///@param	pMarketDataLog	被刷新的CMarketDataLog
	///@param	pNewMarketDataLog	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CMarketDataLog *pMarketDataLog, CWriteableMarketDataLog *pNewMarketDataLog, bool updateIndex,bool bNoTransaction);
	
	///删除一个CMarketDataLog，同时删除其索引
	///@param	pMarketDataLog	要删除的CMarketDataLog
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CMarketDataLog *pMarketDataLog, bool bNoTransaction);
/*
	///检查某个CMarketDataLog是否属于本对象工厂
	///@param	pMarketDataLog	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CMarketDataLog *pMarketDataLog);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于MarketDataLogNo的索引
	CAVLTree *pMarketDataLogNoIndex;
	
	
	///按照MarketDataLogNo检索时，存储的查询参数
	CSequenceNoType queryMarketDataLogNoInSearchByMarketDataLogNo;
	
	///按照MarketDataLogNo检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByMarketDataLogNo;
	
	///加入前触发
	///@param	pMarketDataLog	要加入的MarketDataLog
	virtual void beforeAdd(CWriteableMarketDataLog *pMarketDataLog);
	
	///加入后触发
	///@param	pMarketDataLog	已经加入的MarketDataLog
	virtual void afterAdd(CMarketDataLog *pMarketDataLog);

	///更新前触发	
	///@param	pMarketDataLog	被刷新的CMarketDataLog
	///@param	pNewMarketDataLog	新的值
	virtual void beforeUpdate(CMarketDataLog *pMarketDataLog, CWriteableMarketDataLog *pNewMarketDataLog);
	
	///更新后触发
	///@param	pMarketDataLog	被刷新的CMarketDataLog
	virtual void afterUpdate(CMarketDataLog *pMarketDataLog);
	
	///删除前触发
	///@param	pMarketDataLog	要删除的CMarketDataLog
	virtual void beforeRemove(CMarketDataLog *pMarketDataLog);
	
	///确认加入后触发
	///@param	pMarketDataLog	已经加入的MarketDataLog
	virtual void commitAdd(CMarketDataLog *pMarketDataLog);

	///确认更新后触发
	///@param	pMarketDataLog	被刷新的CMarketDataLog
	///@param	poldMarketDataLog	原来的值
	virtual void commitUpdate(CMarketDataLog *pMarketDataLog, CWriteableMarketDataLog *pOldMarketDataLog);
	
	///确认删除后触发
	///@param	pMarketDataLog	已经删除的CMarketDataLog
	virtual void commitRemove(CWriteableMarketDataLog *pMarketDataLog);

	///所有相关的触发器
	vector<CMarketDataLogActionTrigger *> *pActionTriggers;
	vector<CMarketDataLogCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableMarketDataLog compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CUserSessionFactory是一个交易员在线会话的对象工厂。它包含了一批交易员在线会话，
///同时又建立了如下索引，以方便查询：
///	SessionIDIndex
///	UserIndex
///使用本对象工厂，可以完成对交易员在线会话的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findBySessionID，唯一找到对象
///		使用startFindByFrontID，findNextByFrontID和endFindByFrontID完成查询操作
///		使用findByUserID，唯一找到对象
///		使用startFindStartByUserID，findNextStartByUserID和endFindStartByUserID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CUserSessionFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxUserSession，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CUserSessionFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CUserSessionFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的UserSession
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的UserSession，文件名将根据配置文件中的定义UserSessionCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的UserSession
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的UserSession，文件名将根据配置文件中的定义UserSessionCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CUserSessionResource;

	///将一个CUserSession加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pUserSession	要加入的UserSession
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CUserSession *add(CWriteableUserSession *pUserSession, CTransaction *pTransaction=NULL);
	
	///刷新该CUserSession的值
	///@param	pUserSession	被刷新的CUserSession
	///@param	pNewUserSession	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CUserSession *pUserSession, CWriteableUserSession *pNewUserSession, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pUserSession	  需要被刷新或者新增的CUserSession,等于NULL表示是需要新增的
	///@param	pNewUserSession	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CUserSession* addOrUpdate(CUserSession *pUserSession, CWriteableUserSession *pNewUserSession, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CUserSession，同时删除其索引
	///@param	pUserSession	要删除的CUserSession
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CUserSession *pUserSession, CTransaction *pTransaction=NULL);
	
	///获取某个CUserSession
	///@param	pUserSession	要读取的CUserSession
	///@param	pTragetUserSession	存放结果的CUserSession
	void retrieve(CUserSession *pUserSession, CWriteableUserSession *pTargetUserSession);
	
	///获取第一个CUserSession
	///@return	得到的第一个CUserSession，如果没有，则返回NULL
	CUserSession *getFirst(void);
	
	///获取下一个CUserSession
	///@return	得到下一个CUserSession，如果没有，则返回NULL
	CUserSession *getNext(void);
	
	///结束获取CUserSession
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CUserSessionActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CUserSessionActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CUserSessionCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CUserSessionCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///构造所有对应的交易员的指针
	///@param	pFactory	构造对应的交易员的指针时，寻找的对象工厂
	void linkAllUser(CUserFactory *pFactory);
	
	///寻找CUserSession
	///@param	SessionID	会话号
	///@param	FrontID	前置编号
	///@return	找到的CUserSession，如果找不到，返回NULL
	CUserSession *findBySessionID( const CReadOnlySessionIDType&  SessionID,  const CReadOnlyFrontIDType&  FrontID);



	friend class CUserSessionIteratorByFrontID;

	///开始寻找CUserSession
	///@param	FrontID	前置编号
	///@return	满足条件的地一个CUserSession，如果找不到，返回NULL
	CUserSession *startFindByFrontID( const CReadOnlyFrontIDType& FrontID);

	///寻找下一个符合条件的CUserSession，必须在startFindByFrontID以后，endFindByFrontID之前叫用
	///@return	下一个满足条件CUserSession，如果已经没有一个满足要求了，则返回NULL
	CUserSession *findNextByFrontID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByFrontID(void);

	///寻找CUserSession
	///@param	UserID	用户号
	///@return	找到的CUserSession，如果找不到，返回NULL
	CUserSession *findByUserID( const CReadOnlyUserIDType&  UserID);



	friend class CUserSessionIteratorStartByUserID;

	///开始寻找CUserSession
	///@param	UserID	用户号
	///@return	满足条件的地一个CUserSession，如果找不到，返回NULL
	CUserSession *startFindStartByUserID( const CReadOnlyUserIDType& UserID);

	///寻找下一个符合条件的CUserSession，必须在startFindStartByUserID以后，endFindStartByUserID之前叫用
	///@return	下一个满足条件CUserSession，如果已经没有一个满足要求了，则返回NULL
	CUserSession *findNextStartByUserID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindStartByUserID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CUserSession加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pUserSession	要加入的UserSession
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CUserSession *internalAdd(CWriteableUserSession *pUserSession, bool bNoTransaction);
	
	
	///刷新该CUserSession的键值
	///@param	pUserSession	被刷新的CUserSession
	///@param	pNewUserSession	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CUserSession *pUserSession, CWriteableUserSession *pNewUserSession, bool updateIndex,bool bNoTransaction);
	
	///删除一个CUserSession，同时删除其索引
	///@param	pUserSession	要删除的CUserSession
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CUserSession *pUserSession, bool bNoTransaction);
/*
	///检查某个CUserSession是否属于本对象工厂
	///@param	pUserSession	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CUserSession *pUserSession);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于FrontID+SessionID的索引
	CAVLTree *pSessionIDIndex;
	///基于UserID的索引
	CAVLTree *pUserIndex;
	
	
	///按照FrontID检索时，存储的查询参数
	CFrontIDType queryFrontIDInSearchByFrontID;
	
	///按照FrontID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByFrontID;
	///按照UserID检索时，存储的查询参数
	CUserIDType queryUserIDInSearchStartByUserID;
	
	///按照UserID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchStartByUserID;
	
	///加入前触发
	///@param	pUserSession	要加入的UserSession
	virtual void beforeAdd(CWriteableUserSession *pUserSession);
	
	///加入后触发
	///@param	pUserSession	已经加入的UserSession
	virtual void afterAdd(CUserSession *pUserSession);

	///更新前触发	
	///@param	pUserSession	被刷新的CUserSession
	///@param	pNewUserSession	新的值
	virtual void beforeUpdate(CUserSession *pUserSession, CWriteableUserSession *pNewUserSession);
	
	///更新后触发
	///@param	pUserSession	被刷新的CUserSession
	virtual void afterUpdate(CUserSession *pUserSession);
	
	///删除前触发
	///@param	pUserSession	要删除的CUserSession
	virtual void beforeRemove(CUserSession *pUserSession);
	
	///确认加入后触发
	///@param	pUserSession	已经加入的UserSession
	virtual void commitAdd(CUserSession *pUserSession);

	///确认更新后触发
	///@param	pUserSession	被刷新的CUserSession
	///@param	poldUserSession	原来的值
	virtual void commitUpdate(CUserSession *pUserSession, CWriteableUserSession *pOldUserSession);
	
	///确认删除后触发
	///@param	pUserSession	已经删除的CUserSession
	virtual void commitRemove(CWriteableUserSession *pUserSession);

	///所有相关的触发器
	vector<CUserSessionActionTrigger *> *pActionTriggers;
	vector<CUserSessionCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableUserSession compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CMDSessionFactory是一个行情订阅者在线会话的对象工厂。它包含了一批行情订阅者在线会话，
///同时又建立了如下索引，以方便查询：
///	SessionIDIndex
///	UserIndex
///使用本对象工厂，可以完成对行情订阅者在线会话的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findBySessionID，唯一找到对象
///		使用findByUserID，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMDSessionFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CMDSessionFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxMDSession，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CMDSessionFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CMDSessionFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的MDSession
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的MDSession，文件名将根据配置文件中的定义MDSessionCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的MDSession
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的MDSession，文件名将根据配置文件中的定义MDSessionCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CMDSessionResource;

	///将一个CMDSession加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pMDSession	要加入的MDSession
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CMDSession *add(CWriteableMDSession *pMDSession, CTransaction *pTransaction=NULL);
	
	///刷新该CMDSession的值
	///@param	pMDSession	被刷新的CMDSession
	///@param	pNewMDSession	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CMDSession *pMDSession, CWriteableMDSession *pNewMDSession, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pMDSession	  需要被刷新或者新增的CMDSession,等于NULL表示是需要新增的
	///@param	pNewMDSession	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CMDSession* addOrUpdate(CMDSession *pMDSession, CWriteableMDSession *pNewMDSession, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CMDSession，同时删除其索引
	///@param	pMDSession	要删除的CMDSession
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CMDSession *pMDSession, CTransaction *pTransaction=NULL);
	
	///获取某个CMDSession
	///@param	pMDSession	要读取的CMDSession
	///@param	pTragetMDSession	存放结果的CMDSession
	void retrieve(CMDSession *pMDSession, CWriteableMDSession *pTargetMDSession);
	
	///获取第一个CMDSession
	///@return	得到的第一个CMDSession，如果没有，则返回NULL
	CMDSession *getFirst(void);
	
	///获取下一个CMDSession
	///@return	得到下一个CMDSession，如果没有，则返回NULL
	CMDSession *getNext(void);
	
	///结束获取CMDSession
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CMDSessionActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CMDSessionActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CMDSessionCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CMDSessionCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///寻找CMDSession
	///@param	SessionID	会话号
	///@param	FrontID	前置编号
	///@return	找到的CMDSession，如果找不到，返回NULL
	CMDSession *findBySessionID( const CReadOnlySessionIDType&  SessionID,  const CReadOnlyFrontIDType&  FrontID);



	///寻找CMDSession
	///@param	UserID	用户号
	///@return	找到的CMDSession，如果找不到，返回NULL
	CMDSession *findByUserID( const CReadOnlyUserIDType&  UserID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CMDSession加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pMDSession	要加入的MDSession
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CMDSession *internalAdd(CWriteableMDSession *pMDSession, bool bNoTransaction);
	
	
	///刷新该CMDSession的键值
	///@param	pMDSession	被刷新的CMDSession
	///@param	pNewMDSession	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CMDSession *pMDSession, CWriteableMDSession *pNewMDSession, bool updateIndex,bool bNoTransaction);
	
	///删除一个CMDSession，同时删除其索引
	///@param	pMDSession	要删除的CMDSession
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CMDSession *pMDSession, bool bNoTransaction);
/*
	///检查某个CMDSession是否属于本对象工厂
	///@param	pMDSession	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CMDSession *pMDSession);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于SessionID+FrontID的索引
	CAVLTree *pSessionIDIndex;
	///基于UserID的索引
	CAVLTree *pUserIndex;
	
	
	
	///加入前触发
	///@param	pMDSession	要加入的MDSession
	virtual void beforeAdd(CWriteableMDSession *pMDSession);
	
	///加入后触发
	///@param	pMDSession	已经加入的MDSession
	virtual void afterAdd(CMDSession *pMDSession);

	///更新前触发	
	///@param	pMDSession	被刷新的CMDSession
	///@param	pNewMDSession	新的值
	virtual void beforeUpdate(CMDSession *pMDSession, CWriteableMDSession *pNewMDSession);
	
	///更新后触发
	///@param	pMDSession	被刷新的CMDSession
	virtual void afterUpdate(CMDSession *pMDSession);
	
	///删除前触发
	///@param	pMDSession	要删除的CMDSession
	virtual void beforeRemove(CMDSession *pMDSession);
	
	///确认加入后触发
	///@param	pMDSession	已经加入的MDSession
	virtual void commitAdd(CMDSession *pMDSession);

	///确认更新后触发
	///@param	pMDSession	被刷新的CMDSession
	///@param	poldMDSession	原来的值
	virtual void commitUpdate(CMDSession *pMDSession, CWriteableMDSession *pOldMDSession);
	
	///确认删除后触发
	///@param	pMDSession	已经删除的CMDSession
	virtual void commitRemove(CWriteableMDSession *pMDSession);

	///所有相关的触发器
	vector<CMDSessionActionTrigger *> *pActionTriggers;
	vector<CMDSessionCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableMDSession compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CLoginInfoFactory是一个用户登陆登出信息的对象工厂。它包含了一批用户登陆登出信息，
///同时又建立了如下索引，以方便查询：
///	PrimaryKeyIndex
///使用本对象工厂，可以完成对用户登陆登出信息的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByPrimaryKey，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CLoginInfoFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CLoginInfoFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxLoginInfo，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CLoginInfoFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CLoginInfoFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的LoginInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的LoginInfo，文件名将根据配置文件中的定义LoginInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的LoginInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的LoginInfo，文件名将根据配置文件中的定义LoginInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CLoginInfoResource;

	///将一个CLoginInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pLoginInfo	要加入的LoginInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CLoginInfo *add(CWriteableLoginInfo *pLoginInfo, CTransaction *pTransaction=NULL);
	
	///刷新该CLoginInfo的值
	///@param	pLoginInfo	被刷新的CLoginInfo
	///@param	pNewLoginInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CLoginInfo *pLoginInfo, CWriteableLoginInfo *pNewLoginInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pLoginInfo	  需要被刷新或者新增的CLoginInfo,等于NULL表示是需要新增的
	///@param	pNewLoginInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CLoginInfo* addOrUpdate(CLoginInfo *pLoginInfo, CWriteableLoginInfo *pNewLoginInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CLoginInfo，同时删除其索引
	///@param	pLoginInfo	要删除的CLoginInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CLoginInfo *pLoginInfo, CTransaction *pTransaction=NULL);
	
	///获取某个CLoginInfo
	///@param	pLoginInfo	要读取的CLoginInfo
	///@param	pTragetLoginInfo	存放结果的CLoginInfo
	void retrieve(CLoginInfo *pLoginInfo, CWriteableLoginInfo *pTargetLoginInfo);
	
	///获取第一个CLoginInfo
	///@return	得到的第一个CLoginInfo，如果没有，则返回NULL
	CLoginInfo *getFirst(void);
	
	///获取下一个CLoginInfo
	///@return	得到下一个CLoginInfo，如果没有，则返回NULL
	CLoginInfo *getNext(void);
	
	///结束获取CLoginInfo
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CLoginInfoActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CLoginInfoActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CLoginInfoCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CLoginInfoCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///寻找CLoginInfo
	///@param	TradingDay	交易日
	///@param	SequenceNo	序号
	///@return	找到的CLoginInfo，如果找不到，返回NULL
	CLoginInfo *findByPrimaryKey( const CReadOnlyDateType&  TradingDay,  const CReadOnlySequenceNoType&  SequenceNo);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CLoginInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pLoginInfo	要加入的LoginInfo
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CLoginInfo *internalAdd(CWriteableLoginInfo *pLoginInfo, bool bNoTransaction);
	
	
	///刷新该CLoginInfo的键值
	///@param	pLoginInfo	被刷新的CLoginInfo
	///@param	pNewLoginInfo	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CLoginInfo *pLoginInfo, CWriteableLoginInfo *pNewLoginInfo, bool updateIndex,bool bNoTransaction);
	
	///删除一个CLoginInfo，同时删除其索引
	///@param	pLoginInfo	要删除的CLoginInfo
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CLoginInfo *pLoginInfo, bool bNoTransaction);
/*
	///检查某个CLoginInfo是否属于本对象工厂
	///@param	pLoginInfo	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CLoginInfo *pLoginInfo);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于TradingDay+SequenceNo的索引
	CAVLTree *pPrimaryKeyIndex;
	
	
	
	///加入前触发
	///@param	pLoginInfo	要加入的LoginInfo
	virtual void beforeAdd(CWriteableLoginInfo *pLoginInfo);
	
	///加入后触发
	///@param	pLoginInfo	已经加入的LoginInfo
	virtual void afterAdd(CLoginInfo *pLoginInfo);

	///更新前触发	
	///@param	pLoginInfo	被刷新的CLoginInfo
	///@param	pNewLoginInfo	新的值
	virtual void beforeUpdate(CLoginInfo *pLoginInfo, CWriteableLoginInfo *pNewLoginInfo);
	
	///更新后触发
	///@param	pLoginInfo	被刷新的CLoginInfo
	virtual void afterUpdate(CLoginInfo *pLoginInfo);
	
	///删除前触发
	///@param	pLoginInfo	要删除的CLoginInfo
	virtual void beforeRemove(CLoginInfo *pLoginInfo);
	
	///确认加入后触发
	///@param	pLoginInfo	已经加入的LoginInfo
	virtual void commitAdd(CLoginInfo *pLoginInfo);

	///确认更新后触发
	///@param	pLoginInfo	被刷新的CLoginInfo
	///@param	poldLoginInfo	原来的值
	virtual void commitUpdate(CLoginInfo *pLoginInfo, CWriteableLoginInfo *pOldLoginInfo);
	
	///确认删除后触发
	///@param	pLoginInfo	已经删除的CLoginInfo
	virtual void commitRemove(CWriteableLoginInfo *pLoginInfo);

	///所有相关的触发器
	vector<CLoginInfoActionTrigger *> *pActionTriggers;
	vector<CLoginInfoCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableLoginInfo compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataDetailFactory是一个深度市场行情明细的对象工厂。它包含了一批深度市场行情明细，
///同时又建立了如下索引，以方便查询：
///	PrimaryKeyIndex
///使用本对象工厂，可以完成对深度市场行情明细的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByPrimaryKey，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataDetailFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CDepthMarketDataDetailFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxDepthMarketDataDetail，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CDepthMarketDataDetailFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CDepthMarketDataDetailFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的DepthMarketDataDetail
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的DepthMarketDataDetail，文件名将根据配置文件中的定义DepthMarketDataDetailCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的DepthMarketDataDetail
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的DepthMarketDataDetail，文件名将根据配置文件中的定义DepthMarketDataDetailCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CDepthMarketDataDetailResource;

	///将一个CDepthMarketDataDetail加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pDepthMarketDataDetail	要加入的DepthMarketDataDetail
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CDepthMarketDataDetail *add(CWriteableDepthMarketDataDetail *pDepthMarketDataDetail, CTransaction *pTransaction=NULL);
	
	///刷新该CDepthMarketDataDetail的值
	///@param	pDepthMarketDataDetail	被刷新的CDepthMarketDataDetail
	///@param	pNewDepthMarketDataDetail	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CDepthMarketDataDetail *pDepthMarketDataDetail, CWriteableDepthMarketDataDetail *pNewDepthMarketDataDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pDepthMarketDataDetail	  需要被刷新或者新增的CDepthMarketDataDetail,等于NULL表示是需要新增的
	///@param	pNewDepthMarketDataDetail	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CDepthMarketDataDetail* addOrUpdate(CDepthMarketDataDetail *pDepthMarketDataDetail, CWriteableDepthMarketDataDetail *pNewDepthMarketDataDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CDepthMarketDataDetail，同时删除其索引
	///@param	pDepthMarketDataDetail	要删除的CDepthMarketDataDetail
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CDepthMarketDataDetail *pDepthMarketDataDetail, CTransaction *pTransaction=NULL);
	
	///获取某个CDepthMarketDataDetail
	///@param	pDepthMarketDataDetail	要读取的CDepthMarketDataDetail
	///@param	pTragetDepthMarketDataDetail	存放结果的CDepthMarketDataDetail
	void retrieve(CDepthMarketDataDetail *pDepthMarketDataDetail, CWriteableDepthMarketDataDetail *pTargetDepthMarketDataDetail);
	
	///获取第一个CDepthMarketDataDetail
	///@return	得到的第一个CDepthMarketDataDetail，如果没有，则返回NULL
	CDepthMarketDataDetail *getFirst(void);
	
	///获取下一个CDepthMarketDataDetail
	///@return	得到下一个CDepthMarketDataDetail，如果没有，则返回NULL
	CDepthMarketDataDetail *getNext(void);
	
	///结束获取CDepthMarketDataDetail
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CDepthMarketDataDetailActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CDepthMarketDataDetailActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CDepthMarketDataDetailCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CDepthMarketDataDetailCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///寻找CDepthMarketDataDetail
	///@param	TradingDay	交易日
	///@param	SettlementGroupID	结算组代码
	///@param	SettlementID	结算编号
	///@param	InstrumentID	合约代码
	///@param	SequenceNo	序号
	///@return	找到的CDepthMarketDataDetail，如果找不到，返回NULL
	CDepthMarketDataDetail *findByPrimaryKey( const CReadOnlyDateType&  TradingDay,  const CReadOnlySettlementGroupIDType&  SettlementGroupID,  const CReadOnlySettlementIDType&  SettlementID,  const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlySequenceNoType&  SequenceNo);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CDepthMarketDataDetail加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pDepthMarketDataDetail	要加入的DepthMarketDataDetail
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CDepthMarketDataDetail *internalAdd(CWriteableDepthMarketDataDetail *pDepthMarketDataDetail, bool bNoTransaction);
	
	
	///刷新该CDepthMarketDataDetail的键值
	///@param	pDepthMarketDataDetail	被刷新的CDepthMarketDataDetail
	///@param	pNewDepthMarketDataDetail	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CDepthMarketDataDetail *pDepthMarketDataDetail, CWriteableDepthMarketDataDetail *pNewDepthMarketDataDetail, bool updateIndex,bool bNoTransaction);
	
	///删除一个CDepthMarketDataDetail，同时删除其索引
	///@param	pDepthMarketDataDetail	要删除的CDepthMarketDataDetail
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CDepthMarketDataDetail *pDepthMarketDataDetail, bool bNoTransaction);
/*
	///检查某个CDepthMarketDataDetail是否属于本对象工厂
	///@param	pDepthMarketDataDetail	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CDepthMarketDataDetail *pDepthMarketDataDetail);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于TradingDay+SettlementGroupID+SettlementID+InstrumentID+SequenceNo的索引
	CAVLTree *pPrimaryKeyIndex;
	
	
	
	///加入前触发
	///@param	pDepthMarketDataDetail	要加入的DepthMarketDataDetail
	virtual void beforeAdd(CWriteableDepthMarketDataDetail *pDepthMarketDataDetail);
	
	///加入后触发
	///@param	pDepthMarketDataDetail	已经加入的DepthMarketDataDetail
	virtual void afterAdd(CDepthMarketDataDetail *pDepthMarketDataDetail);

	///更新前触发	
	///@param	pDepthMarketDataDetail	被刷新的CDepthMarketDataDetail
	///@param	pNewDepthMarketDataDetail	新的值
	virtual void beforeUpdate(CDepthMarketDataDetail *pDepthMarketDataDetail, CWriteableDepthMarketDataDetail *pNewDepthMarketDataDetail);
	
	///更新后触发
	///@param	pDepthMarketDataDetail	被刷新的CDepthMarketDataDetail
	virtual void afterUpdate(CDepthMarketDataDetail *pDepthMarketDataDetail);
	
	///删除前触发
	///@param	pDepthMarketDataDetail	要删除的CDepthMarketDataDetail
	virtual void beforeRemove(CDepthMarketDataDetail *pDepthMarketDataDetail);
	
	///确认加入后触发
	///@param	pDepthMarketDataDetail	已经加入的DepthMarketDataDetail
	virtual void commitAdd(CDepthMarketDataDetail *pDepthMarketDataDetail);

	///确认更新后触发
	///@param	pDepthMarketDataDetail	被刷新的CDepthMarketDataDetail
	///@param	poldDepthMarketDataDetail	原来的值
	virtual void commitUpdate(CDepthMarketDataDetail *pDepthMarketDataDetail, CWriteableDepthMarketDataDetail *pOldDepthMarketDataDetail);
	
	///确认删除后触发
	///@param	pDepthMarketDataDetail	已经删除的CDepthMarketDataDetail
	virtual void commitRemove(CWriteableDepthMarketDataDetail *pDepthMarketDataDetail);

	///所有相关的触发器
	vector<CDepthMarketDataDetailActionTrigger *> *pActionTriggers;
	vector<CDepthMarketDataDetailCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableDepthMarketDataDetail compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusDetailFactory是一个合约交易状态流水的对象工厂。它包含了一批合约交易状态流水，
///同时又建立了如下索引，以方便查询：
///使用本对象工厂，可以完成对合约交易状态流水的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusDetailFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CInstrumentStatusDetailFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxInstrumentStatusDetail，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CInstrumentStatusDetailFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CInstrumentStatusDetailFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的InstrumentStatusDetail
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的InstrumentStatusDetail，文件名将根据配置文件中的定义InstrumentStatusDetailCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的InstrumentStatusDetail
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的InstrumentStatusDetail，文件名将根据配置文件中的定义InstrumentStatusDetailCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CInstrumentStatusDetailResource;

	///将一个CInstrumentStatusDetail加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pInstrumentStatusDetail	要加入的InstrumentStatusDetail
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CInstrumentStatusDetail *add(CWriteableInstrumentStatusDetail *pInstrumentStatusDetail, CTransaction *pTransaction=NULL);
	
	///刷新该CInstrumentStatusDetail的值
	///@param	pInstrumentStatusDetail	被刷新的CInstrumentStatusDetail
	///@param	pNewInstrumentStatusDetail	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CInstrumentStatusDetail *pInstrumentStatusDetail, CWriteableInstrumentStatusDetail *pNewInstrumentStatusDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pInstrumentStatusDetail	  需要被刷新或者新增的CInstrumentStatusDetail,等于NULL表示是需要新增的
	///@param	pNewInstrumentStatusDetail	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CInstrumentStatusDetail* addOrUpdate(CInstrumentStatusDetail *pInstrumentStatusDetail, CWriteableInstrumentStatusDetail *pNewInstrumentStatusDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CInstrumentStatusDetail，同时删除其索引
	///@param	pInstrumentStatusDetail	要删除的CInstrumentStatusDetail
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CInstrumentStatusDetail *pInstrumentStatusDetail, CTransaction *pTransaction=NULL);
	
	///获取某个CInstrumentStatusDetail
	///@param	pInstrumentStatusDetail	要读取的CInstrumentStatusDetail
	///@param	pTragetInstrumentStatusDetail	存放结果的CInstrumentStatusDetail
	void retrieve(CInstrumentStatusDetail *pInstrumentStatusDetail, CWriteableInstrumentStatusDetail *pTargetInstrumentStatusDetail);
	
	///获取第一个CInstrumentStatusDetail
	///@return	得到的第一个CInstrumentStatusDetail，如果没有，则返回NULL
	CInstrumentStatusDetail *getFirst(void);
	
	///获取下一个CInstrumentStatusDetail
	///@return	得到下一个CInstrumentStatusDetail，如果没有，则返回NULL
	CInstrumentStatusDetail *getNext(void);
	
	///结束获取CInstrumentStatusDetail
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CInstrumentStatusDetailActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CInstrumentStatusDetailActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CInstrumentStatusDetailCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CInstrumentStatusDetailCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CInstrumentStatusDetail加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pInstrumentStatusDetail	要加入的InstrumentStatusDetail
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CInstrumentStatusDetail *internalAdd(CWriteableInstrumentStatusDetail *pInstrumentStatusDetail, bool bNoTransaction);
	
	
	///刷新该CInstrumentStatusDetail的键值
	///@param	pInstrumentStatusDetail	被刷新的CInstrumentStatusDetail
	///@param	pNewInstrumentStatusDetail	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CInstrumentStatusDetail *pInstrumentStatusDetail, CWriteableInstrumentStatusDetail *pNewInstrumentStatusDetail, bool updateIndex,bool bNoTransaction);
	
	///删除一个CInstrumentStatusDetail，同时删除其索引
	///@param	pInstrumentStatusDetail	要删除的CInstrumentStatusDetail
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CInstrumentStatusDetail *pInstrumentStatusDetail, bool bNoTransaction);
/*
	///检查某个CInstrumentStatusDetail是否属于本对象工厂
	///@param	pInstrumentStatusDetail	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CInstrumentStatusDetail *pInstrumentStatusDetail);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	
	
	
	///加入前触发
	///@param	pInstrumentStatusDetail	要加入的InstrumentStatusDetail
	virtual void beforeAdd(CWriteableInstrumentStatusDetail *pInstrumentStatusDetail);
	
	///加入后触发
	///@param	pInstrumentStatusDetail	已经加入的InstrumentStatusDetail
	virtual void afterAdd(CInstrumentStatusDetail *pInstrumentStatusDetail);

	///更新前触发	
	///@param	pInstrumentStatusDetail	被刷新的CInstrumentStatusDetail
	///@param	pNewInstrumentStatusDetail	新的值
	virtual void beforeUpdate(CInstrumentStatusDetail *pInstrumentStatusDetail, CWriteableInstrumentStatusDetail *pNewInstrumentStatusDetail);
	
	///更新后触发
	///@param	pInstrumentStatusDetail	被刷新的CInstrumentStatusDetail
	virtual void afterUpdate(CInstrumentStatusDetail *pInstrumentStatusDetail);
	
	///删除前触发
	///@param	pInstrumentStatusDetail	要删除的CInstrumentStatusDetail
	virtual void beforeRemove(CInstrumentStatusDetail *pInstrumentStatusDetail);
	
	///确认加入后触发
	///@param	pInstrumentStatusDetail	已经加入的InstrumentStatusDetail
	virtual void commitAdd(CInstrumentStatusDetail *pInstrumentStatusDetail);

	///确认更新后触发
	///@param	pInstrumentStatusDetail	被刷新的CInstrumentStatusDetail
	///@param	poldInstrumentStatusDetail	原来的值
	virtual void commitUpdate(CInstrumentStatusDetail *pInstrumentStatusDetail, CWriteableInstrumentStatusDetail *pOldInstrumentStatusDetail);
	
	///确认删除后触发
	///@param	pInstrumentStatusDetail	已经删除的CInstrumentStatusDetail
	virtual void commitRemove(CWriteableInstrumentStatusDetail *pInstrumentStatusDetail);

	///所有相关的触发器
	vector<CInstrumentStatusDetailActionTrigger *> *pActionTriggers;
	vector<CInstrumentStatusDetailCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableInstrumentStatusDetail compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CFrontStatusFactory是一个前置状态的对象工厂。它包含了一批前置状态，
///同时又建立了如下索引，以方便查询：
///	FrontIDIndex
///使用本对象工厂，可以完成对前置状态的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByFrontID，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFrontStatusFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CFrontStatusFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxFrontStatus，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CFrontStatusFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CFrontStatusFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的FrontStatus
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的FrontStatus，文件名将根据配置文件中的定义FrontStatusCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的FrontStatus
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的FrontStatus，文件名将根据配置文件中的定义FrontStatusCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CFrontStatusResource;

	///将一个CFrontStatus加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pFrontStatus	要加入的FrontStatus
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CFrontStatus *add(CWriteableFrontStatus *pFrontStatus, CTransaction *pTransaction=NULL);
	
	///刷新该CFrontStatus的值
	///@param	pFrontStatus	被刷新的CFrontStatus
	///@param	pNewFrontStatus	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CFrontStatus *pFrontStatus, CWriteableFrontStatus *pNewFrontStatus, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pFrontStatus	  需要被刷新或者新增的CFrontStatus,等于NULL表示是需要新增的
	///@param	pNewFrontStatus	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CFrontStatus* addOrUpdate(CFrontStatus *pFrontStatus, CWriteableFrontStatus *pNewFrontStatus, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CFrontStatus，同时删除其索引
	///@param	pFrontStatus	要删除的CFrontStatus
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CFrontStatus *pFrontStatus, CTransaction *pTransaction=NULL);
	
	///获取某个CFrontStatus
	///@param	pFrontStatus	要读取的CFrontStatus
	///@param	pTragetFrontStatus	存放结果的CFrontStatus
	void retrieve(CFrontStatus *pFrontStatus, CWriteableFrontStatus *pTargetFrontStatus);
	
	///获取第一个CFrontStatus
	///@return	得到的第一个CFrontStatus，如果没有，则返回NULL
	CFrontStatus *getFirst(void);
	
	///获取下一个CFrontStatus
	///@return	得到下一个CFrontStatus，如果没有，则返回NULL
	CFrontStatus *getNext(void);
	
	///结束获取CFrontStatus
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CFrontStatusActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CFrontStatusActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CFrontStatusCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CFrontStatusCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///寻找CFrontStatus
	///@param	FrontID	前置编号
	///@return	找到的CFrontStatus，如果找不到，返回NULL
	CFrontStatus *findByFrontID( const CReadOnlyFrontIDType&  FrontID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CFrontStatus加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pFrontStatus	要加入的FrontStatus
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CFrontStatus *internalAdd(CWriteableFrontStatus *pFrontStatus, bool bNoTransaction);
	
	
	///刷新该CFrontStatus的键值
	///@param	pFrontStatus	被刷新的CFrontStatus
	///@param	pNewFrontStatus	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CFrontStatus *pFrontStatus, CWriteableFrontStatus *pNewFrontStatus, bool updateIndex,bool bNoTransaction);
	
	///删除一个CFrontStatus，同时删除其索引
	///@param	pFrontStatus	要删除的CFrontStatus
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CFrontStatus *pFrontStatus, bool bNoTransaction);
/*
	///检查某个CFrontStatus是否属于本对象工厂
	///@param	pFrontStatus	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CFrontStatus *pFrontStatus);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于FrontID的索引
	CAVLTree *pFrontIDIndex;
	
	
	
	///加入前触发
	///@param	pFrontStatus	要加入的FrontStatus
	virtual void beforeAdd(CWriteableFrontStatus *pFrontStatus);
	
	///加入后触发
	///@param	pFrontStatus	已经加入的FrontStatus
	virtual void afterAdd(CFrontStatus *pFrontStatus);

	///更新前触发	
	///@param	pFrontStatus	被刷新的CFrontStatus
	///@param	pNewFrontStatus	新的值
	virtual void beforeUpdate(CFrontStatus *pFrontStatus, CWriteableFrontStatus *pNewFrontStatus);
	
	///更新后触发
	///@param	pFrontStatus	被刷新的CFrontStatus
	virtual void afterUpdate(CFrontStatus *pFrontStatus);
	
	///删除前触发
	///@param	pFrontStatus	要删除的CFrontStatus
	virtual void beforeRemove(CFrontStatus *pFrontStatus);
	
	///确认加入后触发
	///@param	pFrontStatus	已经加入的FrontStatus
	virtual void commitAdd(CFrontStatus *pFrontStatus);

	///确认更新后触发
	///@param	pFrontStatus	被刷新的CFrontStatus
	///@param	poldFrontStatus	原来的值
	virtual void commitUpdate(CFrontStatus *pFrontStatus, CWriteableFrontStatus *pOldFrontStatus);
	
	///确认删除后触发
	///@param	pFrontStatus	已经删除的CFrontStatus
	virtual void commitRemove(CWriteableFrontStatus *pFrontStatus);

	///所有相关的触发器
	vector<CFrontStatusActionTrigger *> *pActionTriggers;
	vector<CFrontStatusCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableFrontStatus compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CMaxLocalIDFactory是一个最大本地报单号的对象工厂。它包含了一批最大本地报单号，
///同时又建立了如下索引，以方便查询：
///使用本对象工厂，可以完成对最大本地报单号的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByUserID，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMaxLocalIDFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CMaxLocalIDFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxMaxLocalID，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CMaxLocalIDFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CMaxLocalIDFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的MaxLocalID
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的MaxLocalID，文件名将根据配置文件中的定义MaxLocalIDCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的MaxLocalID
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的MaxLocalID，文件名将根据配置文件中的定义MaxLocalIDCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CMaxLocalIDResource;

	///将一个CMaxLocalID加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pMaxLocalID	要加入的MaxLocalID
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CMaxLocalID *add(CWriteableMaxLocalID *pMaxLocalID, CTransaction *pTransaction=NULL);
	
	///刷新该CMaxLocalID的值
	///@param	pMaxLocalID	被刷新的CMaxLocalID
	///@param	pNewMaxLocalID	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CMaxLocalID *pMaxLocalID, CWriteableMaxLocalID *pNewMaxLocalID, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pMaxLocalID	  需要被刷新或者新增的CMaxLocalID,等于NULL表示是需要新增的
	///@param	pNewMaxLocalID	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CMaxLocalID* addOrUpdate(CMaxLocalID *pMaxLocalID, CWriteableMaxLocalID *pNewMaxLocalID, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CMaxLocalID，同时删除其索引
	///@param	pMaxLocalID	要删除的CMaxLocalID
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CMaxLocalID *pMaxLocalID, CTransaction *pTransaction=NULL);
	
	///获取某个CMaxLocalID
	///@param	pMaxLocalID	要读取的CMaxLocalID
	///@param	pTragetMaxLocalID	存放结果的CMaxLocalID
	void retrieve(CMaxLocalID *pMaxLocalID, CWriteableMaxLocalID *pTargetMaxLocalID);
	
	///获取第一个CMaxLocalID
	///@return	得到的第一个CMaxLocalID，如果没有，则返回NULL
	CMaxLocalID *getFirst(void);
	
	///获取下一个CMaxLocalID
	///@return	得到下一个CMaxLocalID，如果没有，则返回NULL
	CMaxLocalID *getNext(void);
	
	///结束获取CMaxLocalID
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CMaxLocalIDActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CMaxLocalIDActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CMaxLocalIDCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CMaxLocalIDCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///寻找CMaxLocalID
	///@param	UserID	用户编号
	///@return	找到的CMaxLocalID，如果找不到，返回NULL
	CMaxLocalID *findByUserID( const CReadOnlyUserIDType&  UserID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CMaxLocalID加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pMaxLocalID	要加入的MaxLocalID
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CMaxLocalID *internalAdd(CWriteableMaxLocalID *pMaxLocalID, bool bNoTransaction);
	
	
	///刷新该CMaxLocalID的键值
	///@param	pMaxLocalID	被刷新的CMaxLocalID
	///@param	pNewMaxLocalID	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CMaxLocalID *pMaxLocalID, CWriteableMaxLocalID *pNewMaxLocalID, bool updateIndex,bool bNoTransaction);
	
	///删除一个CMaxLocalID，同时删除其索引
	///@param	pMaxLocalID	要删除的CMaxLocalID
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CMaxLocalID *pMaxLocalID, bool bNoTransaction);
/*
	///检查某个CMaxLocalID是否属于本对象工厂
	///@param	pMaxLocalID	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CMaxLocalID *pMaxLocalID);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	
	///基于UserID的hash索引
	CHashIndex *pUserIDHashIndex;
	
	
	///加入前触发
	///@param	pMaxLocalID	要加入的MaxLocalID
	virtual void beforeAdd(CWriteableMaxLocalID *pMaxLocalID);
	
	///加入后触发
	///@param	pMaxLocalID	已经加入的MaxLocalID
	virtual void afterAdd(CMaxLocalID *pMaxLocalID);

	///更新前触发	
	///@param	pMaxLocalID	被刷新的CMaxLocalID
	///@param	pNewMaxLocalID	新的值
	virtual void beforeUpdate(CMaxLocalID *pMaxLocalID, CWriteableMaxLocalID *pNewMaxLocalID);
	
	///更新后触发
	///@param	pMaxLocalID	被刷新的CMaxLocalID
	virtual void afterUpdate(CMaxLocalID *pMaxLocalID);
	
	///删除前触发
	///@param	pMaxLocalID	要删除的CMaxLocalID
	virtual void beforeRemove(CMaxLocalID *pMaxLocalID);
	
	///确认加入后触发
	///@param	pMaxLocalID	已经加入的MaxLocalID
	virtual void commitAdd(CMaxLocalID *pMaxLocalID);

	///确认更新后触发
	///@param	pMaxLocalID	被刷新的CMaxLocalID
	///@param	poldMaxLocalID	原来的值
	virtual void commitUpdate(CMaxLocalID *pMaxLocalID, CWriteableMaxLocalID *pOldMaxLocalID);
	
	///确认删除后触发
	///@param	pMaxLocalID	已经删除的CMaxLocalID
	virtual void commitRemove(CWriteableMaxLocalID *pMaxLocalID);

	///所有相关的触发器
	vector<CMaxLocalIDActionTrigger *> *pActionTriggers;
	vector<CMaxLocalIDCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableMaxLocalID compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CBulletinFactory是一个公告信息的对象工厂。它包含了一批公告信息，
///同时又建立了如下索引，以方便查询：
///	BulletinIDIndex
///使用本对象工厂，可以完成对公告信息的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByBulletinID，唯一找到对象
///		使用startFindStartByBulletinID，findNextStartByBulletinID和endFindStartByBulletinID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBulletinFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CBulletinFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxBulletin，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CBulletinFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CBulletinFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的Bulletin
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的Bulletin，文件名将根据配置文件中的定义BulletinCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的Bulletin
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的Bulletin，文件名将根据配置文件中的定义BulletinCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CBulletinResource;

	///将一个CBulletin加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pBulletin	要加入的Bulletin
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CBulletin *add(CWriteableBulletin *pBulletin, CTransaction *pTransaction=NULL);
	
	///刷新该CBulletin的值
	///@param	pBulletin	被刷新的CBulletin
	///@param	pNewBulletin	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CBulletin *pBulletin, CWriteableBulletin *pNewBulletin, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pBulletin	  需要被刷新或者新增的CBulletin,等于NULL表示是需要新增的
	///@param	pNewBulletin	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CBulletin* addOrUpdate(CBulletin *pBulletin, CWriteableBulletin *pNewBulletin, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CBulletin，同时删除其索引
	///@param	pBulletin	要删除的CBulletin
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CBulletin *pBulletin, CTransaction *pTransaction=NULL);
	
	///获取某个CBulletin
	///@param	pBulletin	要读取的CBulletin
	///@param	pTragetBulletin	存放结果的CBulletin
	void retrieve(CBulletin *pBulletin, CWriteableBulletin *pTargetBulletin);
	
	///获取第一个CBulletin
	///@return	得到的第一个CBulletin，如果没有，则返回NULL
	CBulletin *getFirst(void);
	
	///获取下一个CBulletin
	///@return	得到下一个CBulletin，如果没有，则返回NULL
	CBulletin *getNext(void);
	
	///结束获取CBulletin
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CBulletinActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CBulletinActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CBulletinCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CBulletinCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///寻找CBulletin
	///@param	BulletinID	公告编号
	///@param	TradingDay	公告编号
	///@param	MarketID	公告编号
	///@return	找到的CBulletin，如果找不到，返回NULL
	CBulletin *findByBulletinID( const CReadOnlyBulletinIDType&  BulletinID,  const CReadOnlyDateType&  TradingDay,  const CReadOnlyMarketIDType&  MarketID);



	friend class CBulletinIteratorStartByBulletinID;

	///开始寻找CBulletin
	///@param	BulletinID	公告编号
	///@return	满足条件的地一个CBulletin，如果找不到，返回NULL
	CBulletin *startFindStartByBulletinID( const CReadOnlyBulletinIDType& BulletinID);

	///寻找下一个符合条件的CBulletin，必须在startFindStartByBulletinID以后，endFindStartByBulletinID之前叫用
	///@return	下一个满足条件CBulletin，如果已经没有一个满足要求了，则返回NULL
	CBulletin *findNextStartByBulletinID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindStartByBulletinID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CBulletin加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pBulletin	要加入的Bulletin
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CBulletin *internalAdd(CWriteableBulletin *pBulletin, bool bNoTransaction);
	
	
	///刷新该CBulletin的键值
	///@param	pBulletin	被刷新的CBulletin
	///@param	pNewBulletin	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CBulletin *pBulletin, CWriteableBulletin *pNewBulletin, bool updateIndex,bool bNoTransaction);
	
	///删除一个CBulletin，同时删除其索引
	///@param	pBulletin	要删除的CBulletin
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CBulletin *pBulletin, bool bNoTransaction);
/*
	///检查某个CBulletin是否属于本对象工厂
	///@param	pBulletin	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CBulletin *pBulletin);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于BulletinID+TradingDay+MarketID的索引
	CAVLTree *pBulletinIDIndex;
	
	
	///按照BulletinID检索时，存储的查询参数
	CBulletinIDType queryBulletinIDInSearchStartByBulletinID;
	
	///按照BulletinID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchStartByBulletinID;
	
	///加入前触发
	///@param	pBulletin	要加入的Bulletin
	virtual void beforeAdd(CWriteableBulletin *pBulletin);
	
	///加入后触发
	///@param	pBulletin	已经加入的Bulletin
	virtual void afterAdd(CBulletin *pBulletin);

	///更新前触发	
	///@param	pBulletin	被刷新的CBulletin
	///@param	pNewBulletin	新的值
	virtual void beforeUpdate(CBulletin *pBulletin, CWriteableBulletin *pNewBulletin);
	
	///更新后触发
	///@param	pBulletin	被刷新的CBulletin
	virtual void afterUpdate(CBulletin *pBulletin);
	
	///删除前触发
	///@param	pBulletin	要删除的CBulletin
	virtual void beforeRemove(CBulletin *pBulletin);
	
	///确认加入后触发
	///@param	pBulletin	已经加入的Bulletin
	virtual void commitAdd(CBulletin *pBulletin);

	///确认更新后触发
	///@param	pBulletin	被刷新的CBulletin
	///@param	poldBulletin	原来的值
	virtual void commitUpdate(CBulletin *pBulletin, CWriteableBulletin *pOldBulletin);
	
	///确认删除后触发
	///@param	pBulletin	已经删除的CBulletin
	virtual void commitRemove(CWriteableBulletin *pBulletin);

	///所有相关的触发器
	vector<CBulletinActionTrigger *> *pActionTriggers;
	vector<CBulletinCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableBulletin compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataModifyFactory是一个行情变动的对象工厂。它包含了一批行情变动，
///同时又建立了如下索引，以方便查询：
///	InstrumentIDIndex
///使用本对象工厂，可以完成对行情变动的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByInstrumentID，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataModifyFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CMarketDataModifyFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxMarketDataModify，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CMarketDataModifyFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CMarketDataModifyFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的MarketDataModify
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的MarketDataModify，文件名将根据配置文件中的定义MarketDataModifyCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的MarketDataModify
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的MarketDataModify，文件名将根据配置文件中的定义MarketDataModifyCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CMarketDataModifyResource;

	///将一个CMarketDataModify加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pMarketDataModify	要加入的MarketDataModify
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CMarketDataModify *add(CWriteableMarketDataModify *pMarketDataModify, CTransaction *pTransaction=NULL);
	
	///刷新该CMarketDataModify的值
	///@param	pMarketDataModify	被刷新的CMarketDataModify
	///@param	pNewMarketDataModify	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CMarketDataModify *pMarketDataModify, CWriteableMarketDataModify *pNewMarketDataModify, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pMarketDataModify	  需要被刷新或者新增的CMarketDataModify,等于NULL表示是需要新增的
	///@param	pNewMarketDataModify	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CMarketDataModify* addOrUpdate(CMarketDataModify *pMarketDataModify, CWriteableMarketDataModify *pNewMarketDataModify, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CMarketDataModify，同时删除其索引
	///@param	pMarketDataModify	要删除的CMarketDataModify
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CMarketDataModify *pMarketDataModify, CTransaction *pTransaction=NULL);
	
	///获取某个CMarketDataModify
	///@param	pMarketDataModify	要读取的CMarketDataModify
	///@param	pTragetMarketDataModify	存放结果的CMarketDataModify
	void retrieve(CMarketDataModify *pMarketDataModify, CWriteableMarketDataModify *pTargetMarketDataModify);
	
	///获取第一个CMarketDataModify
	///@return	得到的第一个CMarketDataModify，如果没有，则返回NULL
	CMarketDataModify *getFirst(void);
	
	///获取下一个CMarketDataModify
	///@return	得到下一个CMarketDataModify，如果没有，则返回NULL
	CMarketDataModify *getNext(void);
	
	///结束获取CMarketDataModify
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CMarketDataModifyActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CMarketDataModifyActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CMarketDataModifyCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CMarketDataModifyCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///构造所有对应的深度行情的指针
	///@param	pFactory	构造对应的深度行情的指针时，寻找的对象工厂
	void linkAllDepthMarketData(CDepthMarketDataFactory *pFactory);
	
	friend class CMarketDataModifyIteratorBySettlementGroupID;

	///开始寻找CMarketDataModify
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CMarketDataModify，如果找不到，返回NULL
	CMarketDataModify *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CMarketDataModify，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CMarketDataModify，如果已经没有一个满足要求了，则返回NULL
	CMarketDataModify *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CMarketDataModify
	///@param	InstrumentID	合约代码
	///@return	找到的CMarketDataModify，如果找不到，返回NULL
	CMarketDataModify *findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CMarketDataModify加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pMarketDataModify	要加入的MarketDataModify
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CMarketDataModify *internalAdd(CWriteableMarketDataModify *pMarketDataModify, bool bNoTransaction);
	
	
	///刷新该CMarketDataModify的键值
	///@param	pMarketDataModify	被刷新的CMarketDataModify
	///@param	pNewMarketDataModify	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CMarketDataModify *pMarketDataModify, CWriteableMarketDataModify *pNewMarketDataModify, bool updateIndex,bool bNoTransaction);
	
	///删除一个CMarketDataModify，同时删除其索引
	///@param	pMarketDataModify	要删除的CMarketDataModify
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CMarketDataModify *pMarketDataModify, bool bNoTransaction);
/*
	///检查某个CMarketDataModify是否属于本对象工厂
	///@param	pMarketDataModify	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CMarketDataModify *pMarketDataModify);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于InstrumentID的索引
	CAVLTree *pInstrumentIDIndex;
	
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CMarketDataModify *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pMarketDataModify	要加入的MarketDataModify
	virtual void beforeAdd(CWriteableMarketDataModify *pMarketDataModify);
	
	///加入后触发
	///@param	pMarketDataModify	已经加入的MarketDataModify
	virtual void afterAdd(CMarketDataModify *pMarketDataModify);

	///更新前触发	
	///@param	pMarketDataModify	被刷新的CMarketDataModify
	///@param	pNewMarketDataModify	新的值
	virtual void beforeUpdate(CMarketDataModify *pMarketDataModify, CWriteableMarketDataModify *pNewMarketDataModify);
	
	///更新后触发
	///@param	pMarketDataModify	被刷新的CMarketDataModify
	virtual void afterUpdate(CMarketDataModify *pMarketDataModify);
	
	///删除前触发
	///@param	pMarketDataModify	要删除的CMarketDataModify
	virtual void beforeRemove(CMarketDataModify *pMarketDataModify);
	
	///确认加入后触发
	///@param	pMarketDataModify	已经加入的MarketDataModify
	virtual void commitAdd(CMarketDataModify *pMarketDataModify);

	///确认更新后触发
	///@param	pMarketDataModify	被刷新的CMarketDataModify
	///@param	poldMarketDataModify	原来的值
	virtual void commitUpdate(CMarketDataModify *pMarketDataModify, CWriteableMarketDataModify *pOldMarketDataModify);
	
	///确认删除后触发
	///@param	pMarketDataModify	已经删除的CMarketDataModify
	virtual void commitRemove(CWriteableMarketDataModify *pMarketDataModify);

	///所有相关的触发器
	vector<CMarketDataModifyActionTrigger *> *pActionTriggers;
	vector<CMarketDataModifyCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableMarketDataModify compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataFactory是一个深度行情的对象工厂。它包含了一批深度行情，
///同时又建立了如下索引，以方便查询：
///	InstrumentIDIndex
///使用本对象工厂，可以完成对深度行情的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByInstrumentID，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CDepthMarketDataFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxDepthMarketData，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CDepthMarketDataFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CDepthMarketDataFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的DepthMarketData
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的DepthMarketData，文件名将根据配置文件中的定义DepthMarketDataCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的DepthMarketData
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的DepthMarketData，文件名将根据配置文件中的定义DepthMarketDataCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CDepthMarketDataResource;

	///将一个CDepthMarketData加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pDepthMarketData	要加入的DepthMarketData
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CDepthMarketData *add(CWriteableDepthMarketData *pDepthMarketData, CTransaction *pTransaction=NULL);
	
	///刷新该CDepthMarketData的值
	///@param	pDepthMarketData	被刷新的CDepthMarketData
	///@param	pNewDepthMarketData	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CDepthMarketData *pDepthMarketData, CWriteableDepthMarketData *pNewDepthMarketData, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pDepthMarketData	  需要被刷新或者新增的CDepthMarketData,等于NULL表示是需要新增的
	///@param	pNewDepthMarketData	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CDepthMarketData* addOrUpdate(CDepthMarketData *pDepthMarketData, CWriteableDepthMarketData *pNewDepthMarketData, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CDepthMarketData，同时删除其索引
	///@param	pDepthMarketData	要删除的CDepthMarketData
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CDepthMarketData *pDepthMarketData, CTransaction *pTransaction=NULL);
	
	///获取某个CDepthMarketData
	///@param	pDepthMarketData	要读取的CDepthMarketData
	///@param	pTragetDepthMarketData	存放结果的CDepthMarketData
	void retrieve(CDepthMarketData *pDepthMarketData, CWriteableDepthMarketData *pTargetDepthMarketData);
	
	///获取第一个CDepthMarketData
	///@return	得到的第一个CDepthMarketData，如果没有，则返回NULL
	CDepthMarketData *getFirst(void);
	
	///获取下一个CDepthMarketData
	///@return	得到下一个CDepthMarketData，如果没有，则返回NULL
	CDepthMarketData *getNext(void);
	
	///结束获取CDepthMarketData
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CDepthMarketDataActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CDepthMarketDataActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CDepthMarketDataCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CDepthMarketDataCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///构造所有对应的合约的指针
	///@param	pFactory	构造对应的合约的指针时，寻找的对象工厂
	void linkAllInstrument(CInstrumentFactory *pFactory);
	
	friend class CDepthMarketDataIteratorBySettlementGroupID;

	///开始寻找CDepthMarketData
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CDepthMarketData，如果找不到，返回NULL
	CDepthMarketData *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CDepthMarketData，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CDepthMarketData，如果已经没有一个满足要求了，则返回NULL
	CDepthMarketData *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CDepthMarketData
	///@param	InstrumentID	合约代码
	///@return	找到的CDepthMarketData，如果找不到，返回NULL
	CDepthMarketData *findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CDepthMarketData加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pDepthMarketData	要加入的DepthMarketData
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CDepthMarketData *internalAdd(CWriteableDepthMarketData *pDepthMarketData, bool bNoTransaction);
	
	
	///刷新该CDepthMarketData的键值
	///@param	pDepthMarketData	被刷新的CDepthMarketData
	///@param	pNewDepthMarketData	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CDepthMarketData *pDepthMarketData, CWriteableDepthMarketData *pNewDepthMarketData, bool updateIndex,bool bNoTransaction);
	
	///删除一个CDepthMarketData，同时删除其索引
	///@param	pDepthMarketData	要删除的CDepthMarketData
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CDepthMarketData *pDepthMarketData, bool bNoTransaction);
/*
	///检查某个CDepthMarketData是否属于本对象工厂
	///@param	pDepthMarketData	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CDepthMarketData *pDepthMarketData);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于InstrumentID的索引
	CAVLTree *pInstrumentIDIndex;
	
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CDepthMarketData *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pDepthMarketData	要加入的DepthMarketData
	virtual void beforeAdd(CWriteableDepthMarketData *pDepthMarketData);
	
	///加入后触发
	///@param	pDepthMarketData	已经加入的DepthMarketData
	virtual void afterAdd(CDepthMarketData *pDepthMarketData);

	///更新前触发	
	///@param	pDepthMarketData	被刷新的CDepthMarketData
	///@param	pNewDepthMarketData	新的值
	virtual void beforeUpdate(CDepthMarketData *pDepthMarketData, CWriteableDepthMarketData *pNewDepthMarketData);
	
	///更新后触发
	///@param	pDepthMarketData	被刷新的CDepthMarketData
	virtual void afterUpdate(CDepthMarketData *pDepthMarketData);
	
	///删除前触发
	///@param	pDepthMarketData	要删除的CDepthMarketData
	virtual void beforeRemove(CDepthMarketData *pDepthMarketData);
	
	///确认加入后触发
	///@param	pDepthMarketData	已经加入的DepthMarketData
	virtual void commitAdd(CDepthMarketData *pDepthMarketData);

	///确认更新后触发
	///@param	pDepthMarketData	被刷新的CDepthMarketData
	///@param	poldDepthMarketData	原来的值
	virtual void commitUpdate(CDepthMarketData *pDepthMarketData, CWriteableDepthMarketData *pOldDepthMarketData);
	
	///确认删除后触发
	///@param	pDepthMarketData	已经删除的CDepthMarketData
	virtual void commitRemove(CWriteableDepthMarketData *pDepthMarketData);

	///所有相关的触发器
	vector<CDepthMarketDataActionTrigger *> *pActionTriggers;
	vector<CDepthMarketDataCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableDepthMarketData compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataFactory是一个分主题行情的对象工厂。它包含了一批分主题行情，
///同时又建立了如下索引，以方便查询：
///	TopicAndInstrumentIndex
///	InstrumentIndex
///使用本对象工厂，可以完成对分主题行情的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByTopicAndInstrument，唯一找到对象
///		使用startFindByTopicID，findNextByTopicID和endFindByTopicID完成查询操作
///		使用startFindByInstrumentID，findNextByInstrumentID和endFindByInstrumentID完成查询操作
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CTopicMarketDataFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxTopicMarketData，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CTopicMarketDataFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CTopicMarketDataFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的TopicMarketData
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的TopicMarketData，文件名将根据配置文件中的定义TopicMarketDataCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的TopicMarketData
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的TopicMarketData，文件名将根据配置文件中的定义TopicMarketDataCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CTopicMarketDataResource;

	///将一个CTopicMarketData加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pTopicMarketData	要加入的TopicMarketData
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CTopicMarketData *add(CWriteableTopicMarketData *pTopicMarketData, CTransaction *pTransaction=NULL);
	
	///刷新该CTopicMarketData的值
	///@param	pTopicMarketData	被刷新的CTopicMarketData
	///@param	pNewTopicMarketData	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CTopicMarketData *pTopicMarketData, CWriteableTopicMarketData *pNewTopicMarketData, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pTopicMarketData	  需要被刷新或者新增的CTopicMarketData,等于NULL表示是需要新增的
	///@param	pNewTopicMarketData	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CTopicMarketData* addOrUpdate(CTopicMarketData *pTopicMarketData, CWriteableTopicMarketData *pNewTopicMarketData, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CTopicMarketData，同时删除其索引
	///@param	pTopicMarketData	要删除的CTopicMarketData
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CTopicMarketData *pTopicMarketData, CTransaction *pTransaction=NULL);
	
	///获取某个CTopicMarketData
	///@param	pTopicMarketData	要读取的CTopicMarketData
	///@param	pTragetTopicMarketData	存放结果的CTopicMarketData
	void retrieve(CTopicMarketData *pTopicMarketData, CWriteableTopicMarketData *pTargetTopicMarketData);
	
	///获取第一个CTopicMarketData
	///@return	得到的第一个CTopicMarketData，如果没有，则返回NULL
	CTopicMarketData *getFirst(void);
	
	///获取下一个CTopicMarketData
	///@return	得到下一个CTopicMarketData，如果没有，则返回NULL
	CTopicMarketData *getNext(void);
	
	///结束获取CTopicMarketData
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CTopicMarketDataActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CTopicMarketDataActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CTopicMarketDataCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CTopicMarketDataCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///寻找CTopicMarketData
	///@param	TopicID	主题代码
	///@param	InstrumentID	合约代码
	///@return	找到的CTopicMarketData，如果找不到，返回NULL
	CTopicMarketData *findByTopicAndInstrument( const CReadOnlyTopicIDType&  TopicID,  const CReadOnlyInstrumentIDType&  InstrumentID);



	friend class CTopicMarketDataIteratorByTopicID;

	///开始寻找CTopicMarketData
	///@param	TopicID	主题代码
	///@return	满足条件的地一个CTopicMarketData，如果找不到，返回NULL
	CTopicMarketData *startFindByTopicID( const CReadOnlyTopicIDType& TopicID);

	///寻找下一个符合条件的CTopicMarketData，必须在startFindByTopicID以后，endFindByTopicID之前叫用
	///@return	下一个满足条件CTopicMarketData，如果已经没有一个满足要求了，则返回NULL
	CTopicMarketData *findNextByTopicID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByTopicID(void);

	friend class CTopicMarketDataIteratorByInstrumentID;

	///开始寻找CTopicMarketData
	///@param	InstrumentID	合约代码
	///@return	满足条件的地一个CTopicMarketData，如果找不到，返回NULL
	CTopicMarketData *startFindByInstrumentID( const CReadOnlyInstrumentIDType& InstrumentID);

	///寻找下一个符合条件的CTopicMarketData，必须在startFindByInstrumentID以后，endFindByInstrumentID之前叫用
	///@return	下一个满足条件CTopicMarketData，如果已经没有一个满足要求了，则返回NULL
	CTopicMarketData *findNextByInstrumentID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByInstrumentID(void);

	friend class CTopicMarketDataIteratorBySettlementGroupID;

	///开始寻找CTopicMarketData
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CTopicMarketData，如果找不到，返回NULL
	CTopicMarketData *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CTopicMarketData，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CTopicMarketData，如果已经没有一个满足要求了，则返回NULL
	CTopicMarketData *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CTopicMarketData加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pTopicMarketData	要加入的TopicMarketData
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CTopicMarketData *internalAdd(CWriteableTopicMarketData *pTopicMarketData, bool bNoTransaction);
	
	
	///刷新该CTopicMarketData的键值
	///@param	pTopicMarketData	被刷新的CTopicMarketData
	///@param	pNewTopicMarketData	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CTopicMarketData *pTopicMarketData, CWriteableTopicMarketData *pNewTopicMarketData, bool updateIndex,bool bNoTransaction);
	
	///删除一个CTopicMarketData，同时删除其索引
	///@param	pTopicMarketData	要删除的CTopicMarketData
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CTopicMarketData *pTopicMarketData, bool bNoTransaction);
/*
	///检查某个CTopicMarketData是否属于本对象工厂
	///@param	pTopicMarketData	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CTopicMarketData *pTopicMarketData);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于TopicID+InstrumentID的索引
	CAVLTree *pTopicAndInstrumentIndex;
	///基于InstrumentID的索引
	CAVLTree *pInstrumentIndex;
	
	
	///按照TopicID检索时，存储的查询参数
	CTopicIDType queryTopicIDInSearchByTopicID;
	
	///按照TopicID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByTopicID;
	///按照InstrumentID检索时，存储的查询参数
	CInstrumentIDType queryInstrumentIDInSearchByInstrumentID;
	
	///按照InstrumentID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByInstrumentID;
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CTopicMarketData *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pTopicMarketData	要加入的TopicMarketData
	virtual void beforeAdd(CWriteableTopicMarketData *pTopicMarketData);
	
	///加入后触发
	///@param	pTopicMarketData	已经加入的TopicMarketData
	virtual void afterAdd(CTopicMarketData *pTopicMarketData);

	///更新前触发	
	///@param	pTopicMarketData	被刷新的CTopicMarketData
	///@param	pNewTopicMarketData	新的值
	virtual void beforeUpdate(CTopicMarketData *pTopicMarketData, CWriteableTopicMarketData *pNewTopicMarketData);
	
	///更新后触发
	///@param	pTopicMarketData	被刷新的CTopicMarketData
	virtual void afterUpdate(CTopicMarketData *pTopicMarketData);
	
	///删除前触发
	///@param	pTopicMarketData	要删除的CTopicMarketData
	virtual void beforeRemove(CTopicMarketData *pTopicMarketData);
	
	///确认加入后触发
	///@param	pTopicMarketData	已经加入的TopicMarketData
	virtual void commitAdd(CTopicMarketData *pTopicMarketData);

	///确认更新后触发
	///@param	pTopicMarketData	被刷新的CTopicMarketData
	///@param	poldTopicMarketData	原来的值
	virtual void commitUpdate(CTopicMarketData *pTopicMarketData, CWriteableTopicMarketData *pOldTopicMarketData);
	
	///确认删除后触发
	///@param	pTopicMarketData	已经删除的CTopicMarketData
	virtual void commitRemove(CWriteableTopicMarketData *pTopicMarketData);

	///所有相关的触发器
	vector<CTopicMarketDataActionTrigger *> *pActionTriggers;
	vector<CTopicMarketDataCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableTopicMarketData compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataVersionFactory是一个分主题行情快照的对象工厂。它包含了一批分主题行情快照，
///同时又建立了如下索引，以方便查询：
///	TopicAndVersion
///使用本对象工厂，可以完成对分主题行情快照的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByTopicAndVersion，findNextByTopicAndVersion和endFindByTopicAndVersion完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataVersionFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CTopicMarketDataVersionFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxTopicMarketDataVersion，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CTopicMarketDataVersionFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CTopicMarketDataVersionFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的TopicMarketDataVersion
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的TopicMarketDataVersion，文件名将根据配置文件中的定义TopicMarketDataVersionCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的TopicMarketDataVersion
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的TopicMarketDataVersion，文件名将根据配置文件中的定义TopicMarketDataVersionCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CTopicMarketDataVersionResource;

	///将一个CTopicMarketDataVersion加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pTopicMarketDataVersion	要加入的TopicMarketDataVersion
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CTopicMarketDataVersion *add(CWriteableTopicMarketDataVersion *pTopicMarketDataVersion, CTransaction *pTransaction=NULL);
	
	///刷新该CTopicMarketDataVersion的值
	///@param	pTopicMarketDataVersion	被刷新的CTopicMarketDataVersion
	///@param	pNewTopicMarketDataVersion	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CTopicMarketDataVersion *pTopicMarketDataVersion, CWriteableTopicMarketDataVersion *pNewTopicMarketDataVersion, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pTopicMarketDataVersion	  需要被刷新或者新增的CTopicMarketDataVersion,等于NULL表示是需要新增的
	///@param	pNewTopicMarketDataVersion	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CTopicMarketDataVersion* addOrUpdate(CTopicMarketDataVersion *pTopicMarketDataVersion, CWriteableTopicMarketDataVersion *pNewTopicMarketDataVersion, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CTopicMarketDataVersion，同时删除其索引
	///@param	pTopicMarketDataVersion	要删除的CTopicMarketDataVersion
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CTopicMarketDataVersion *pTopicMarketDataVersion, CTransaction *pTransaction=NULL);
	
	///获取某个CTopicMarketDataVersion
	///@param	pTopicMarketDataVersion	要读取的CTopicMarketDataVersion
	///@param	pTragetTopicMarketDataVersion	存放结果的CTopicMarketDataVersion
	void retrieve(CTopicMarketDataVersion *pTopicMarketDataVersion, CWriteableTopicMarketDataVersion *pTargetTopicMarketDataVersion);
	
	///获取第一个CTopicMarketDataVersion
	///@return	得到的第一个CTopicMarketDataVersion，如果没有，则返回NULL
	CTopicMarketDataVersion *getFirst(void);
	
	///获取下一个CTopicMarketDataVersion
	///@return	得到下一个CTopicMarketDataVersion，如果没有，则返回NULL
	CTopicMarketDataVersion *getNext(void);
	
	///结束获取CTopicMarketDataVersion
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CTopicMarketDataVersionActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CTopicMarketDataVersionActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CTopicMarketDataVersionCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CTopicMarketDataVersionCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CTopicMarketDataVersionIteratorByTopicAndVersion;

	///开始寻找CTopicMarketDataVersion
	///@param	TopicID	主题代码
	///@param	Version	快照版本
	///@return	满足条件的地一个CTopicMarketDataVersion，如果找不到，返回NULL
	CTopicMarketDataVersion *startFindByTopicAndVersion( const CReadOnlyTopicIDType& TopicID,  const CReadOnlySequenceNoType& Version);

	///寻找下一个符合条件的CTopicMarketDataVersion，必须在startFindByTopicAndVersion以后，endFindByTopicAndVersion之前叫用
	///@return	下一个满足条件CTopicMarketDataVersion，如果已经没有一个满足要求了，则返回NULL
	CTopicMarketDataVersion *findNextByTopicAndVersion(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByTopicAndVersion(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CTopicMarketDataVersion加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pTopicMarketDataVersion	要加入的TopicMarketDataVersion
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CTopicMarketDataVersion *internalAdd(CWriteableTopicMarketDataVersion *pTopicMarketDataVersion, bool bNoTransaction);
	
	
	///刷新该CTopicMarketDataVersion的键值
	///@param	pTopicMarketDataVersion	被刷新的CTopicMarketDataVersion
	///@param	pNewTopicMarketDataVersion	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CTopicMarketDataVersion *pTopicMarketDataVersion, CWriteableTopicMarketDataVersion *pNewTopicMarketDataVersion, bool updateIndex,bool bNoTransaction);
	
	///删除一个CTopicMarketDataVersion，同时删除其索引
	///@param	pTopicMarketDataVersion	要删除的CTopicMarketDataVersion
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CTopicMarketDataVersion *pTopicMarketDataVersion, bool bNoTransaction);
/*
	///检查某个CTopicMarketDataVersion是否属于本对象工厂
	///@param	pTopicMarketDataVersion	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CTopicMarketDataVersion *pTopicMarketDataVersion);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于TopicID+Version的索引
	CAVLTree *pTopicAndVersion;
	
	
	///按照TopicID，Version检索时，存储的查询参数
	CTopicIDType queryTopicIDInSearchByTopicAndVersion;
	CSequenceNoType queryVersionInSearchByTopicAndVersion;
	
	///按照TopicID，Version检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByTopicAndVersion;
	
	///加入前触发
	///@param	pTopicMarketDataVersion	要加入的TopicMarketDataVersion
	virtual void beforeAdd(CWriteableTopicMarketDataVersion *pTopicMarketDataVersion);
	
	///加入后触发
	///@param	pTopicMarketDataVersion	已经加入的TopicMarketDataVersion
	virtual void afterAdd(CTopicMarketDataVersion *pTopicMarketDataVersion);

	///更新前触发	
	///@param	pTopicMarketDataVersion	被刷新的CTopicMarketDataVersion
	///@param	pNewTopicMarketDataVersion	新的值
	virtual void beforeUpdate(CTopicMarketDataVersion *pTopicMarketDataVersion, CWriteableTopicMarketDataVersion *pNewTopicMarketDataVersion);
	
	///更新后触发
	///@param	pTopicMarketDataVersion	被刷新的CTopicMarketDataVersion
	virtual void afterUpdate(CTopicMarketDataVersion *pTopicMarketDataVersion);
	
	///删除前触发
	///@param	pTopicMarketDataVersion	要删除的CTopicMarketDataVersion
	virtual void beforeRemove(CTopicMarketDataVersion *pTopicMarketDataVersion);
	
	///确认加入后触发
	///@param	pTopicMarketDataVersion	已经加入的TopicMarketDataVersion
	virtual void commitAdd(CTopicMarketDataVersion *pTopicMarketDataVersion);

	///确认更新后触发
	///@param	pTopicMarketDataVersion	被刷新的CTopicMarketDataVersion
	///@param	poldTopicMarketDataVersion	原来的值
	virtual void commitUpdate(CTopicMarketDataVersion *pTopicMarketDataVersion, CWriteableTopicMarketDataVersion *pOldTopicMarketDataVersion);
	
	///确认删除后触发
	///@param	pTopicMarketDataVersion	已经删除的CTopicMarketDataVersion
	virtual void commitRemove(CWriteableTopicMarketDataVersion *pTopicMarketDataVersion);

	///所有相关的触发器
	vector<CTopicMarketDataVersionActionTrigger *> *pActionTriggers;
	vector<CTopicMarketDataVersionCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableTopicMarketDataVersion compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CInformationFactory是一个信息的对象工厂。它包含了一批信息，
///同时又建立了如下索引，以方便查询：
///	InformationIDIndex
///	InformationIDLastIndex
///使用本对象工厂，可以完成对信息的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByInformationID，findNextByInformationID和endFindByInformationID完成查询操作
///		使用findLastInInformationID，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInformationFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CInformationFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxInformation，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CInformationFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CInformationFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的Information
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的Information，文件名将根据配置文件中的定义InformationCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的Information
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的Information，文件名将根据配置文件中的定义InformationCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CInformationResource;

	///将一个CInformation加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pInformation	要加入的Information
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CInformation *add(CWriteableInformation *pInformation, CTransaction *pTransaction=NULL);
	
	///刷新该CInformation的值
	///@param	pInformation	被刷新的CInformation
	///@param	pNewInformation	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CInformation *pInformation, CWriteableInformation *pNewInformation, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pInformation	  需要被刷新或者新增的CInformation,等于NULL表示是需要新增的
	///@param	pNewInformation	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CInformation* addOrUpdate(CInformation *pInformation, CWriteableInformation *pNewInformation, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CInformation，同时删除其索引
	///@param	pInformation	要删除的CInformation
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CInformation *pInformation, CTransaction *pTransaction=NULL);
	
	///获取某个CInformation
	///@param	pInformation	要读取的CInformation
	///@param	pTragetInformation	存放结果的CInformation
	void retrieve(CInformation *pInformation, CWriteableInformation *pTargetInformation);
	
	///获取第一个CInformation
	///@return	得到的第一个CInformation，如果没有，则返回NULL
	CInformation *getFirst(void);
	
	///获取下一个CInformation
	///@return	得到下一个CInformation，如果没有，则返回NULL
	CInformation *getNext(void);
	
	///结束获取CInformation
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CInformationActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CInformationActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CInformationCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CInformationCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CInformationIteratorByInformationID;

	///开始寻找CInformation
	///@param	InformationID	消息编号
	///@return	满足条件的地一个CInformation，如果找不到，返回NULL
	CInformation *startFindByInformationID( const CReadOnlyInformationIDType& InformationID);

	///寻找下一个符合条件的CInformation，必须在startFindByInformationID以后，endFindByInformationID之前叫用
	///@return	下一个满足条件CInformation，如果已经没有一个满足要求了，则返回NULL
	CInformation *findNextByInformationID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByInformationID(void);

	///寻找CInformation
	///@param	InformationID	消息编号
	///@return	找到的CInformation，如果找不到，返回NULL
	CInformation *findLastInInformationID( const CReadOnlyInformationIDType&  InformationID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CInformation加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pInformation	要加入的Information
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CInformation *internalAdd(CWriteableInformation *pInformation, bool bNoTransaction);
	
	
	///刷新该CInformation的键值
	///@param	pInformation	被刷新的CInformation
	///@param	pNewInformation	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CInformation *pInformation, CWriteableInformation *pNewInformation, bool updateIndex,bool bNoTransaction);
	
	///删除一个CInformation，同时删除其索引
	///@param	pInformation	要删除的CInformation
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CInformation *pInformation, bool bNoTransaction);
/*
	///检查某个CInformation是否属于本对象工厂
	///@param	pInformation	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CInformation *pInformation);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于InformationID+SequenceNo的索引
	CAVLTree *pInformationIDIndex;
	///基于InformationID+SequenceNo的索引
	CAVLTree *pInformationIDLastIndex;
	
	
	///按照InformationID检索时，存储的查询参数
	CInformationIDType queryInformationIDInSearchByInformationID;
	
	///按照InformationID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByInformationID;
	
	///加入前触发
	///@param	pInformation	要加入的Information
	virtual void beforeAdd(CWriteableInformation *pInformation);
	
	///加入后触发
	///@param	pInformation	已经加入的Information
	virtual void afterAdd(CInformation *pInformation);

	///更新前触发	
	///@param	pInformation	被刷新的CInformation
	///@param	pNewInformation	新的值
	virtual void beforeUpdate(CInformation *pInformation, CWriteableInformation *pNewInformation);
	
	///更新后触发
	///@param	pInformation	被刷新的CInformation
	virtual void afterUpdate(CInformation *pInformation);
	
	///删除前触发
	///@param	pInformation	要删除的CInformation
	virtual void beforeRemove(CInformation *pInformation);
	
	///确认加入后触发
	///@param	pInformation	已经加入的Information
	virtual void commitAdd(CInformation *pInformation);

	///确认更新后触发
	///@param	pInformation	被刷新的CInformation
	///@param	poldInformation	原来的值
	virtual void commitUpdate(CInformation *pInformation, CWriteableInformation *pOldInformation);
	
	///确认删除后触发
	///@param	pInformation	已经删除的CInformation
	virtual void commitRemove(CWriteableInformation *pInformation);

	///所有相关的触发器
	vector<CInformationActionTrigger *> *pActionTriggers;
	vector<CInformationCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableInformation compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///COrderCountFactory是一个报单数量的对象工厂。它包含了一批报单数量，
///同时又建立了如下索引，以方便查询：
///使用本对象工厂，可以完成对报单数量的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByParticipantID，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderCountFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	COrderCountFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxOrderCount，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	COrderCountFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~COrderCountFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的OrderCount
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的OrderCount，文件名将根据配置文件中的定义OrderCountCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的OrderCount
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的OrderCount，文件名将根据配置文件中的定义OrderCountCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class COrderCountResource;

	///将一个COrderCount加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pOrderCount	要加入的OrderCount
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	COrderCount *add(CWriteableOrderCount *pOrderCount, CTransaction *pTransaction=NULL);
	
	///刷新该COrderCount的值
	///@param	pOrderCount	被刷新的COrderCount
	///@param	pNewOrderCount	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(COrderCount *pOrderCount, CWriteableOrderCount *pNewOrderCount, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pOrderCount	  需要被刷新或者新增的COrderCount,等于NULL表示是需要新增的
	///@param	pNewOrderCount	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	COrderCount* addOrUpdate(COrderCount *pOrderCount, CWriteableOrderCount *pNewOrderCount, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个COrderCount，同时删除其索引
	///@param	pOrderCount	要删除的COrderCount
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(COrderCount *pOrderCount, CTransaction *pTransaction=NULL);
	
	///获取某个COrderCount
	///@param	pOrderCount	要读取的COrderCount
	///@param	pTragetOrderCount	存放结果的COrderCount
	void retrieve(COrderCount *pOrderCount, CWriteableOrderCount *pTargetOrderCount);
	
	///获取第一个COrderCount
	///@return	得到的第一个COrderCount，如果没有，则返回NULL
	COrderCount *getFirst(void);
	
	///获取下一个COrderCount
	///@return	得到下一个COrderCount，如果没有，则返回NULL
	COrderCount *getNext(void);
	
	///结束获取COrderCount
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(COrderCountActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(COrderCountActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(COrderCountCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(COrderCountCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///寻找COrderCount
	///@param	ParticipantID	会员代码
	///@return	找到的COrderCount，如果找不到，返回NULL
	COrderCount *findByParticipantID( const CReadOnlyParticipantIDType&  ParticipantID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个COrderCount加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pOrderCount	要加入的OrderCount
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	COrderCount *internalAdd(CWriteableOrderCount *pOrderCount, bool bNoTransaction);
	
	
	///刷新该COrderCount的键值
	///@param	pOrderCount	被刷新的COrderCount
	///@param	pNewOrderCount	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(COrderCount *pOrderCount, CWriteableOrderCount *pNewOrderCount, bool updateIndex,bool bNoTransaction);
	
	///删除一个COrderCount，同时删除其索引
	///@param	pOrderCount	要删除的COrderCount
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(COrderCount *pOrderCount, bool bNoTransaction);
/*
	///检查某个COrderCount是否属于本对象工厂
	///@param	pOrderCount	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(COrderCount *pOrderCount);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	
	///基于HashParticipantID的hash索引
	CHashIndex *pHashParticipantIDIndex;
	
	
	///加入前触发
	///@param	pOrderCount	要加入的OrderCount
	virtual void beforeAdd(CWriteableOrderCount *pOrderCount);
	
	///加入后触发
	///@param	pOrderCount	已经加入的OrderCount
	virtual void afterAdd(COrderCount *pOrderCount);

	///更新前触发	
	///@param	pOrderCount	被刷新的COrderCount
	///@param	pNewOrderCount	新的值
	virtual void beforeUpdate(COrderCount *pOrderCount, CWriteableOrderCount *pNewOrderCount);
	
	///更新后触发
	///@param	pOrderCount	被刷新的COrderCount
	virtual void afterUpdate(COrderCount *pOrderCount);
	
	///删除前触发
	///@param	pOrderCount	要删除的COrderCount
	virtual void beforeRemove(COrderCount *pOrderCount);
	
	///确认加入后触发
	///@param	pOrderCount	已经加入的OrderCount
	virtual void commitAdd(COrderCount *pOrderCount);

	///确认更新后触发
	///@param	pOrderCount	被刷新的COrderCount
	///@param	poldOrderCount	原来的值
	virtual void commitUpdate(COrderCount *pOrderCount, CWriteableOrderCount *pOldOrderCount);
	
	///确认删除后触发
	///@param	pOrderCount	已经删除的COrderCount
	virtual void commitRemove(CWriteableOrderCount *pOrderCount);

	///所有相关的触发器
	vector<COrderCountActionTrigger *> *pActionTriggers;
	vector<COrderCountCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableOrderCount compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentFactory是一个合约的对象工厂。它包含了一批合约，
///同时又建立了如下索引，以方便查询：
///	InstrumentIDIndex
///	ProductIDIndex
///	ProductGroupIDIndex
///	ProductGroupIDRevIndex
///使用本对象工厂，可以完成对合约的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByInstrumentID，唯一找到对象
///		使用startFindStartByInstrumentID，findNextStartByInstrumentID和endFindStartByInstrumentID完成查询操作
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用startFindByProductID，findNextByProductID和endFindByProductID完成查询操作
///		使用startFindByProductGroupID，findNextByProductGroupID和endFindByProductGroupID完成查询操作
///		使用startFindByDeliveryMonth，findNextByDeliveryMonth和endFindByDeliveryMonth完成查询操作
///		使用startFindByRevDeliveryMonth，findNextByRevDeliveryMonth和endFindByRevDeliveryMonth完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CInstrumentFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxInstrument，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CInstrumentFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CInstrumentFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的Instrument
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的Instrument，文件名将根据配置文件中的定义InstrumentCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的Instrument
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的Instrument，文件名将根据配置文件中的定义InstrumentCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CInstrumentResource;

	///将一个CInstrument加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pInstrument	要加入的Instrument
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CInstrument *add(CWriteableInstrument *pInstrument, CTransaction *pTransaction=NULL);
	
	///刷新该CInstrument的值
	///@param	pInstrument	被刷新的CInstrument
	///@param	pNewInstrument	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CInstrument *pInstrument, CWriteableInstrument *pNewInstrument, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pInstrument	  需要被刷新或者新增的CInstrument,等于NULL表示是需要新增的
	///@param	pNewInstrument	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CInstrument* addOrUpdate(CInstrument *pInstrument, CWriteableInstrument *pNewInstrument, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CInstrument，同时删除其索引
	///@param	pInstrument	要删除的CInstrument
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CInstrument *pInstrument, CTransaction *pTransaction=NULL);
	
	///获取某个CInstrument
	///@param	pInstrument	要读取的CInstrument
	///@param	pTragetInstrument	存放结果的CInstrument
	void retrieve(CInstrument *pInstrument, CWriteableInstrument *pTargetInstrument);
	
	///获取第一个CInstrument
	///@return	得到的第一个CInstrument，如果没有，则返回NULL
	CInstrument *getFirst(void);
	
	///获取下一个CInstrument
	///@return	得到下一个CInstrument，如果没有，则返回NULL
	CInstrument *getNext(void);
	
	///结束获取CInstrument
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CInstrumentActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CInstrumentActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CInstrumentCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CInstrumentCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///构造所有对应的基础合约的指针
	///@param	pFactory	构造对应的基础合约的指针时，寻找的对象工厂
	void linkAllBaseInstrument(CInstrumentFactory *pFactory);
	
	///构造所有对应的合约属性的指针
	///@param	pFactory	构造对应的合约属性的指针时，寻找的对象工厂
	void linkAllInstrumentProperty(CCurrInstrumentPropertyFactory *pFactory);
	
	///构造所有对应的合约状态的指针
	///@param	pFactory	构造对应的合约状态的指针时，寻找的对象工厂
	void linkAllInstrumentStatus(CInstrumentStatusFactory *pFactory);
	
	///构造所有对应的行情的指针
	///@param	pFactory	构造对应的行情的指针时，寻找的对象工厂
	void linkAllMarketData(CMarketDataFactory *pFactory);
	
	///构造所有对应的套期保值规则的指针
	///@param	pFactory	构造对应的套期保值规则的指针时，寻找的对象工厂
	void linkAllCurrHedgeRule(CCurrHedgeRuleFactory *pFactory);
	
	///构造所有对应的熔断规则的指针
	///@param	pFactory	构造对应的熔断规则的指针时，寻找的对象工厂
	void linkAllCurrFuse(CCurrFuseFactory *pFactory);
	
	///构造所有对应的熔断状态的指针
	///@param	pFactory	构造对应的熔断状态的指针时，寻找的对象工厂
	void linkAllFusePhase(CFusePhaseFactory *pFactory);
	
	///构造所有对应的涨跌停板设置的指针
	///@param	pFactory	构造对应的涨跌停板设置的指针时，寻找的对象工厂
	void linkAllBasePriceLimit(CBasePriceLimitFactory *pFactory);
	
	///构造所有对应的单边市情况的指针
	///@param	pFactory	构造对应的单边市情况的指针时，寻找的对象工厂
	void linkAllUniPressure(CUniPressureFactory *pFactory);
	
	///构造所有对应的结算组同步状态的指针
	///@param	pFactory	构造对应的结算组同步状态的指针时，寻找的对象工厂
	void linkAllSGDataSyncStatus(CSGDataSyncStatusFactory *pFactory);
	
	///寻找CInstrument
	///@param	InstrumentID	合约代码
	///@return	找到的CInstrument，如果找不到，返回NULL
	CInstrument *findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID);



	friend class CInstrumentIteratorStartByInstrumentID;

	///开始寻找CInstrument
	///@param	InstrumentID	合约代码
	///@return	满足条件的地一个CInstrument，如果找不到，返回NULL
	CInstrument *startFindStartByInstrumentID( const CReadOnlyInstrumentIDType& InstrumentID);

	///寻找下一个符合条件的CInstrument，必须在startFindStartByInstrumentID以后，endFindStartByInstrumentID之前叫用
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	CInstrument *findNextStartByInstrumentID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindStartByInstrumentID(void);

	friend class CInstrumentIteratorBySettlementGroupID;

	///开始寻找CInstrument
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CInstrument，如果找不到，返回NULL
	CInstrument *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CInstrument，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	CInstrument *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	friend class CInstrumentIteratorByProductID;

	///开始寻找CInstrument
	///@param	ProductID	产品编号
	///@return	满足条件的地一个CInstrument，如果找不到，返回NULL
	CInstrument *startFindByProductID( const CReadOnlyProductIDType& ProductID);

	///寻找下一个符合条件的CInstrument，必须在startFindByProductID以后，endFindByProductID之前叫用
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	CInstrument *findNextByProductID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByProductID(void);

	friend class CInstrumentIteratorByProductGroupID;

	///开始寻找CInstrument
	///@param	ProductGroupID	产品组编号
	///@return	满足条件的地一个CInstrument，如果找不到，返回NULL
	CInstrument *startFindByProductGroupID( const CReadOnlyProductGroupIDType& ProductGroupID);

	///寻找下一个符合条件的CInstrument，必须在startFindByProductGroupID以后，endFindByProductGroupID之前叫用
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	CInstrument *findNextByProductGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByProductGroupID(void);

	friend class CInstrumentIteratorByDeliveryMonth;

	///开始寻找CInstrument
	///@param	ProductGroupID	产品组编号
	///@param	DeliveryYear	交割年份
	///@param	DeliveryMonth	交割月份
	///@return	满足条件的地一个CInstrument，如果找不到，返回NULL
	CInstrument *startFindByDeliveryMonth( const CReadOnlyProductGroupIDType& ProductGroupID,  const CReadOnlyYearType& DeliveryYear,  const CReadOnlyMonthType& DeliveryMonth);

	///寻找下一个符合条件的CInstrument，必须在startFindByDeliveryMonth以后，endFindByDeliveryMonth之前叫用
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	CInstrument *findNextByDeliveryMonth(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDeliveryMonth(void);

	friend class CInstrumentIteratorByRevDeliveryMonth;

	///开始寻找CInstrument
	///@param	ProductGroupID	产品组编号
	///@param	DeliveryYear	交割年份
	///@param	DeliveryMonth	交割月份
	///@return	满足条件的地一个CInstrument，如果找不到，返回NULL
	CInstrument *startFindByRevDeliveryMonth( const CReadOnlyProductGroupIDType& ProductGroupID,  const CReadOnlyYearType& DeliveryYear,  const CReadOnlyMonthType& DeliveryMonth);

	///寻找下一个符合条件的CInstrument，必须在startFindByRevDeliveryMonth以后，endFindByRevDeliveryMonth之前叫用
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	CInstrument *findNextByRevDeliveryMonth(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByRevDeliveryMonth(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CInstrument加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pInstrument	要加入的Instrument
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CInstrument *internalAdd(CWriteableInstrument *pInstrument, bool bNoTransaction);
	
	
	///刷新该CInstrument的键值
	///@param	pInstrument	被刷新的CInstrument
	///@param	pNewInstrument	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CInstrument *pInstrument, CWriteableInstrument *pNewInstrument, bool updateIndex,bool bNoTransaction);
	
	///删除一个CInstrument，同时删除其索引
	///@param	pInstrument	要删除的CInstrument
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CInstrument *pInstrument, bool bNoTransaction);
/*
	///检查某个CInstrument是否属于本对象工厂
	///@param	pInstrument	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CInstrument *pInstrument);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于InstrumentID的索引
	CAVLTree *pInstrumentIDIndex;
	///基于ProductID的索引
	CAVLTree *pProductIDIndex;
	///基于ProductGroupID+DeliveryYear+DeliveryMonth的索引
	CAVLTree *pProductGroupIDIndex;
	///基于ProductGroupID+DeliveryYear+DeliveryMonth的索引
	CAVLTree *pProductGroupIDRevIndex;
	
	///基于InstrumentID的hash索引
	CHashIndex *pInstrumentIDHashIndex;
	
	///按照InstrumentID检索时，存储的查询参数
	CInstrumentIDType queryInstrumentIDInSearchStartByInstrumentID;
	
	///按照InstrumentID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchStartByInstrumentID;
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CInstrument *pLastFoundInSearchBySettlementGroupID;
	///按照ProductID检索时，存储的查询参数
	CProductIDType queryProductIDInSearchByProductID;
	
	///按照ProductID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByProductID;
	///按照ProductGroupID检索时，存储的查询参数
	CProductGroupIDType queryProductGroupIDInSearchByProductGroupID;
	
	///按照ProductGroupID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByProductGroupID;
	///按照ProductGroupID，DeliveryYear，DeliveryMonth检索时，存储的查询参数
	CProductGroupIDType queryProductGroupIDInSearchByDeliveryMonth;
	CYearType queryDeliveryYearInSearchByDeliveryMonth;
	CMonthType queryDeliveryMonthInSearchByDeliveryMonth;
	
	///按照ProductGroupID，DeliveryYear，DeliveryMonth检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDeliveryMonth;
	///按照ProductGroupID，DeliveryYear，DeliveryMonth检索时，存储的查询参数
	CProductGroupIDType queryProductGroupIDInSearchByRevDeliveryMonth;
	CYearType queryDeliveryYearInSearchByRevDeliveryMonth;
	CMonthType queryDeliveryMonthInSearchByRevDeliveryMonth;
	
	///按照ProductGroupID，DeliveryYear，DeliveryMonth检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByRevDeliveryMonth;
	
	///加入前触发
	///@param	pInstrument	要加入的Instrument
	virtual void beforeAdd(CWriteableInstrument *pInstrument);
	
	///加入后触发
	///@param	pInstrument	已经加入的Instrument
	virtual void afterAdd(CInstrument *pInstrument);

	///更新前触发	
	///@param	pInstrument	被刷新的CInstrument
	///@param	pNewInstrument	新的值
	virtual void beforeUpdate(CInstrument *pInstrument, CWriteableInstrument *pNewInstrument);
	
	///更新后触发
	///@param	pInstrument	被刷新的CInstrument
	virtual void afterUpdate(CInstrument *pInstrument);
	
	///删除前触发
	///@param	pInstrument	要删除的CInstrument
	virtual void beforeRemove(CInstrument *pInstrument);
	
	///确认加入后触发
	///@param	pInstrument	已经加入的Instrument
	virtual void commitAdd(CInstrument *pInstrument);

	///确认更新后触发
	///@param	pInstrument	被刷新的CInstrument
	///@param	poldInstrument	原来的值
	virtual void commitUpdate(CInstrument *pInstrument, CWriteableInstrument *pOldInstrument);
	
	///确认删除后触发
	///@param	pInstrument	已经删除的CInstrument
	virtual void commitRemove(CWriteableInstrument *pInstrument);

	///所有相关的触发器
	vector<CInstrumentActionTrigger *> *pActionTriggers;
	vector<CInstrumentCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableInstrument compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCombinationLegFactory是一个组合合约单腿的对象工厂。它包含了一批组合合约单腿，
///同时又建立了如下索引，以方便查询：
///	CombinationIndex
///	LegIndex
///使用本对象工厂，可以完成对组合合约单腿的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByCombination，findNextByCombination和endFindByCombination完成查询操作
///		使用findByCombinationLegID，唯一找到对象
///		使用startFindByLeg，findNextByLeg和endFindByLeg完成查询操作
///		使用findByCombinationAndLeg，唯一找到对象
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCombinationLegFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxCombinationLeg，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCombinationLegFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CCombinationLegFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的CombinationLeg
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的CombinationLeg，文件名将根据配置文件中的定义CombinationLegCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的CombinationLeg
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的CombinationLeg，文件名将根据配置文件中的定义CombinationLegCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CCombinationLegResource;

	///将一个CCombinationLeg加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCombinationLeg	要加入的CombinationLeg
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCombinationLeg *add(CWriteableCombinationLeg *pCombinationLeg, CTransaction *pTransaction=NULL);
	
	///刷新该CCombinationLeg的值
	///@param	pCombinationLeg	被刷新的CCombinationLeg
	///@param	pNewCombinationLeg	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CCombinationLeg *pCombinationLeg, CWriteableCombinationLeg *pNewCombinationLeg, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pCombinationLeg	  需要被刷新或者新增的CCombinationLeg,等于NULL表示是需要新增的
	///@param	pNewCombinationLeg	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CCombinationLeg* addOrUpdate(CCombinationLeg *pCombinationLeg, CWriteableCombinationLeg *pNewCombinationLeg, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CCombinationLeg，同时删除其索引
	///@param	pCombinationLeg	要删除的CCombinationLeg
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CCombinationLeg *pCombinationLeg, CTransaction *pTransaction=NULL);
	
	///获取某个CCombinationLeg
	///@param	pCombinationLeg	要读取的CCombinationLeg
	///@param	pTragetCombinationLeg	存放结果的CCombinationLeg
	void retrieve(CCombinationLeg *pCombinationLeg, CWriteableCombinationLeg *pTargetCombinationLeg);
	
	///获取第一个CCombinationLeg
	///@return	得到的第一个CCombinationLeg，如果没有，则返回NULL
	CCombinationLeg *getFirst(void);
	
	///获取下一个CCombinationLeg
	///@return	得到下一个CCombinationLeg，如果没有，则返回NULL
	CCombinationLeg *getNext(void);
	
	///结束获取CCombinationLeg
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CCombinationLegActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CCombinationLegActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CCombinationLegCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CCombinationLegCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///构造所有对应的组合合约的指针
	///@param	pFactory	构造对应的组合合约的指针时，寻找的对象工厂
	///@exception	如果找不到，则抛出RUNTIME_ERROR
	void linkAllCombinationInstrument(CInstrumentFactory *pFactory);
	
	///构造所有对应的单腿合约的指针
	///@param	pFactory	构造对应的单腿合约的指针时，寻找的对象工厂
	///@exception	如果找不到，则抛出RUNTIME_ERROR
	void linkAllLegInstrument(CInstrumentFactory *pFactory);
	
	friend class CCombinationLegIteratorByCombination;

	///开始寻找CCombinationLeg
	///@param	CombInstrumentID	组合合约代码
	///@return	满足条件的地一个CCombinationLeg，如果找不到，返回NULL
	CCombinationLeg *startFindByCombination( const CReadOnlyInstrumentIDType& CombInstrumentID);

	///寻找下一个符合条件的CCombinationLeg，必须在startFindByCombination以后，endFindByCombination之前叫用
	///@return	下一个满足条件CCombinationLeg，如果已经没有一个满足要求了，则返回NULL
	CCombinationLeg *findNextByCombination(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByCombination(void);

	///寻找CCombinationLeg
	///@param	CombInstrumentID	组合合约代码
	///@param	LegID	分腿编号
	///@return	找到的CCombinationLeg，如果找不到，返回NULL
	CCombinationLeg *findByCombinationLegID( const CReadOnlyInstrumentIDType&  CombInstrumentID,  const CReadOnlyLegIDType&  LegID);



	friend class CCombinationLegIteratorByLeg;

	///开始寻找CCombinationLeg
	///@param	LegInstrumentID	单腿合约代码
	///@return	满足条件的地一个CCombinationLeg，如果找不到，返回NULL
	CCombinationLeg *startFindByLeg( const CReadOnlyInstrumentIDType& LegInstrumentID);

	///寻找下一个符合条件的CCombinationLeg，必须在startFindByLeg以后，endFindByLeg之前叫用
	///@return	下一个满足条件CCombinationLeg，如果已经没有一个满足要求了，则返回NULL
	CCombinationLeg *findNextByLeg(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByLeg(void);

	///寻找CCombinationLeg
	///@param	CombInstrumentID	组合合约代码
	///@param	LegInstrumentID	单腿合约代码
	///@return	找到的CCombinationLeg，如果找不到，返回NULL
	CCombinationLeg *findByCombinationAndLeg( const CReadOnlyInstrumentIDType&  CombInstrumentID,  const CReadOnlyInstrumentIDType&  LegInstrumentID);



	friend class CCombinationLegIteratorBySettlementGroupID;

	///开始寻找CCombinationLeg
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CCombinationLeg，如果找不到，返回NULL
	CCombinationLeg *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CCombinationLeg，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCombinationLeg，如果已经没有一个满足要求了，则返回NULL
	CCombinationLeg *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CCombinationLeg加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCombinationLeg	要加入的CombinationLeg
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCombinationLeg *internalAdd(CWriteableCombinationLeg *pCombinationLeg, bool bNoTransaction);
	
	
	///刷新该CCombinationLeg的键值
	///@param	pCombinationLeg	被刷新的CCombinationLeg
	///@param	pNewCombinationLeg	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CCombinationLeg *pCombinationLeg, CWriteableCombinationLeg *pNewCombinationLeg, bool updateIndex,bool bNoTransaction);
	
	///删除一个CCombinationLeg，同时删除其索引
	///@param	pCombinationLeg	要删除的CCombinationLeg
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CCombinationLeg *pCombinationLeg, bool bNoTransaction);
/*
	///检查某个CCombinationLeg是否属于本对象工厂
	///@param	pCombinationLeg	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CCombinationLeg *pCombinationLeg);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于CombInstrumentID+LegID的索引
	CAVLTree *pCombinationIndex;
	///基于LegInstrumentID+CombInstrumentID的索引
	CAVLTree *pLegIndex;
	
	
	///按照CombInstrumentID检索时，存储的查询参数
	CInstrumentIDType queryCombInstrumentIDInSearchByCombination;
	
	///按照CombInstrumentID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByCombination;
	///按照LegInstrumentID检索时，存储的查询参数
	CInstrumentIDType queryLegInstrumentIDInSearchByLeg;
	
	///按照LegInstrumentID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByLeg;
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CCombinationLeg *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pCombinationLeg	要加入的CombinationLeg
	virtual void beforeAdd(CWriteableCombinationLeg *pCombinationLeg);
	
	///加入后触发
	///@param	pCombinationLeg	已经加入的CombinationLeg
	virtual void afterAdd(CCombinationLeg *pCombinationLeg);

	///更新前触发	
	///@param	pCombinationLeg	被刷新的CCombinationLeg
	///@param	pNewCombinationLeg	新的值
	virtual void beforeUpdate(CCombinationLeg *pCombinationLeg, CWriteableCombinationLeg *pNewCombinationLeg);
	
	///更新后触发
	///@param	pCombinationLeg	被刷新的CCombinationLeg
	virtual void afterUpdate(CCombinationLeg *pCombinationLeg);
	
	///删除前触发
	///@param	pCombinationLeg	要删除的CCombinationLeg
	virtual void beforeRemove(CCombinationLeg *pCombinationLeg);
	
	///确认加入后触发
	///@param	pCombinationLeg	已经加入的CombinationLeg
	virtual void commitAdd(CCombinationLeg *pCombinationLeg);

	///确认更新后触发
	///@param	pCombinationLeg	被刷新的CCombinationLeg
	///@param	poldCombinationLeg	原来的值
	virtual void commitUpdate(CCombinationLeg *pCombinationLeg, CWriteableCombinationLeg *pOldCombinationLeg);
	
	///确认删除后触发
	///@param	pCombinationLeg	已经删除的CCombinationLeg
	virtual void commitRemove(CWriteableCombinationLeg *pCombinationLeg);

	///所有相关的触发器
	vector<CCombinationLegActionTrigger *> *pActionTriggers;
	vector<CCombinationLegCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableCombinationLeg compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountFactory是一个会员账户关系的对象工厂。它包含了一批会员账户关系，
///同时又建立了如下索引，以方便查询：
///	PartRoleAndSGIndex
///使用本对象工厂，可以完成对会员账户关系的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByPartRoleAndSG，唯一找到对象
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用startFindStartByParticipantID，findNextStartByParticipantID和endFindStartByParticipantID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CPartRoleAccountFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxPartRoleAccount，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CPartRoleAccountFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CPartRoleAccountFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的PartRoleAccount
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的PartRoleAccount，文件名将根据配置文件中的定义PartRoleAccountCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的PartRoleAccount
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的PartRoleAccount，文件名将根据配置文件中的定义PartRoleAccountCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CPartRoleAccountResource;

	///将一个CPartRoleAccount加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pPartRoleAccount	要加入的PartRoleAccount
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CPartRoleAccount *add(CWriteablePartRoleAccount *pPartRoleAccount, CTransaction *pTransaction=NULL);
	
	///刷新该CPartRoleAccount的值
	///@param	pPartRoleAccount	被刷新的CPartRoleAccount
	///@param	pNewPartRoleAccount	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CPartRoleAccount *pPartRoleAccount, CWriteablePartRoleAccount *pNewPartRoleAccount, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pPartRoleAccount	  需要被刷新或者新增的CPartRoleAccount,等于NULL表示是需要新增的
	///@param	pNewPartRoleAccount	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CPartRoleAccount* addOrUpdate(CPartRoleAccount *pPartRoleAccount, CWriteablePartRoleAccount *pNewPartRoleAccount, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CPartRoleAccount，同时删除其索引
	///@param	pPartRoleAccount	要删除的CPartRoleAccount
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CPartRoleAccount *pPartRoleAccount, CTransaction *pTransaction=NULL);
	
	///获取某个CPartRoleAccount
	///@param	pPartRoleAccount	要读取的CPartRoleAccount
	///@param	pTragetPartRoleAccount	存放结果的CPartRoleAccount
	void retrieve(CPartRoleAccount *pPartRoleAccount, CWriteablePartRoleAccount *pTargetPartRoleAccount);
	
	///获取第一个CPartRoleAccount
	///@return	得到的第一个CPartRoleAccount，如果没有，则返回NULL
	CPartRoleAccount *getFirst(void);
	
	///获取下一个CPartRoleAccount
	///@return	得到下一个CPartRoleAccount，如果没有，则返回NULL
	CPartRoleAccount *getNext(void);
	
	///结束获取CPartRoleAccount
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CPartRoleAccountActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CPartRoleAccountActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CPartRoleAccountCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CPartRoleAccountCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///构造所有对应的帐户的指针
	///@param	pFactory	构造对应的帐户的指针时，寻找的对象工厂
	void linkAllTradingAccount(CTradingAccountFactory *pFactory);
	
	///寻找CPartRoleAccount
	///@param	ParticipantID	会员号
	///@param	TradingRole	交易角色
	///@param	SettlementGroupID	结算组代码
	///@return	找到的CPartRoleAccount，如果找不到，返回NULL
	CPartRoleAccount *findByPartRoleAndSG( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyTradingRoleType&  TradingRole,  const CReadOnlySettlementGroupIDType&  SettlementGroupID);



	friend class CPartRoleAccountIteratorBySettlementGroupID;

	///开始寻找CPartRoleAccount
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CPartRoleAccount，如果找不到，返回NULL
	CPartRoleAccount *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CPartRoleAccount，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CPartRoleAccount，如果已经没有一个满足要求了，则返回NULL
	CPartRoleAccount *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	friend class CPartRoleAccountIteratorStartByParticipantID;

	///开始寻找CPartRoleAccount
	///@param	ParticipantID	会员号
	///@return	满足条件的地一个CPartRoleAccount，如果找不到，返回NULL
	CPartRoleAccount *startFindStartByParticipantID( const CReadOnlyParticipantIDType& ParticipantID);

	///寻找下一个符合条件的CPartRoleAccount，必须在startFindStartByParticipantID以后，endFindStartByParticipantID之前叫用
	///@return	下一个满足条件CPartRoleAccount，如果已经没有一个满足要求了，则返回NULL
	CPartRoleAccount *findNextStartByParticipantID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindStartByParticipantID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CPartRoleAccount加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pPartRoleAccount	要加入的PartRoleAccount
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CPartRoleAccount *internalAdd(CWriteablePartRoleAccount *pPartRoleAccount, bool bNoTransaction);
	
	
	///刷新该CPartRoleAccount的键值
	///@param	pPartRoleAccount	被刷新的CPartRoleAccount
	///@param	pNewPartRoleAccount	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CPartRoleAccount *pPartRoleAccount, CWriteablePartRoleAccount *pNewPartRoleAccount, bool updateIndex,bool bNoTransaction);
	
	///删除一个CPartRoleAccount，同时删除其索引
	///@param	pPartRoleAccount	要删除的CPartRoleAccount
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CPartRoleAccount *pPartRoleAccount, bool bNoTransaction);
/*
	///检查某个CPartRoleAccount是否属于本对象工厂
	///@param	pPartRoleAccount	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CPartRoleAccount *pPartRoleAccount);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ParticipantID+TradingRole+SettlementGroupID的索引
	CAVLTree *pPartRoleAndSGIndex;
	
	///基于PartRoleAndSG的hash索引
	CHashIndex *pPartRoleAndSGHashIndex;
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CPartRoleAccount *pLastFoundInSearchBySettlementGroupID;
	///按照ParticipantID检索时，存储的查询参数
	CParticipantIDType queryParticipantIDInSearchStartByParticipantID;
	
	///按照ParticipantID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchStartByParticipantID;
	
	///加入前触发
	///@param	pPartRoleAccount	要加入的PartRoleAccount
	virtual void beforeAdd(CWriteablePartRoleAccount *pPartRoleAccount);
	
	///加入后触发
	///@param	pPartRoleAccount	已经加入的PartRoleAccount
	virtual void afterAdd(CPartRoleAccount *pPartRoleAccount);

	///更新前触发	
	///@param	pPartRoleAccount	被刷新的CPartRoleAccount
	///@param	pNewPartRoleAccount	新的值
	virtual void beforeUpdate(CPartRoleAccount *pPartRoleAccount, CWriteablePartRoleAccount *pNewPartRoleAccount);
	
	///更新后触发
	///@param	pPartRoleAccount	被刷新的CPartRoleAccount
	virtual void afterUpdate(CPartRoleAccount *pPartRoleAccount);
	
	///删除前触发
	///@param	pPartRoleAccount	要删除的CPartRoleAccount
	virtual void beforeRemove(CPartRoleAccount *pPartRoleAccount);
	
	///确认加入后触发
	///@param	pPartRoleAccount	已经加入的PartRoleAccount
	virtual void commitAdd(CPartRoleAccount *pPartRoleAccount);

	///确认更新后触发
	///@param	pPartRoleAccount	被刷新的CPartRoleAccount
	///@param	poldPartRoleAccount	原来的值
	virtual void commitUpdate(CPartRoleAccount *pPartRoleAccount, CWriteablePartRoleAccount *pOldPartRoleAccount);
	
	///确认删除后触发
	///@param	pPartRoleAccount	已经删除的CPartRoleAccount
	virtual void commitRemove(CWriteablePartRoleAccount *pPartRoleAccount);

	///所有相关的触发器
	vector<CPartRoleAccountActionTrigger *> *pActionTriggers;
	vector<CPartRoleAccountCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteablePartRoleAccount compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRoleFactory是一个会员产品角色的对象工厂。它包含了一批会员产品角色，
///同时又建立了如下索引，以方便查询：
///使用本对象工厂，可以完成对会员产品角色的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByParticipantProductRole，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRoleFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CPartProductRoleFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxPartProductRole，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CPartProductRoleFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CPartProductRoleFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的PartProductRole
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的PartProductRole，文件名将根据配置文件中的定义PartProductRoleCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的PartProductRole
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的PartProductRole，文件名将根据配置文件中的定义PartProductRoleCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CPartProductRoleResource;

	///将一个CPartProductRole加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pPartProductRole	要加入的PartProductRole
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CPartProductRole *add(CWriteablePartProductRole *pPartProductRole, CTransaction *pTransaction=NULL);
	
	///刷新该CPartProductRole的值
	///@param	pPartProductRole	被刷新的CPartProductRole
	///@param	pNewPartProductRole	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CPartProductRole *pPartProductRole, CWriteablePartProductRole *pNewPartProductRole, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pPartProductRole	  需要被刷新或者新增的CPartProductRole,等于NULL表示是需要新增的
	///@param	pNewPartProductRole	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CPartProductRole* addOrUpdate(CPartProductRole *pPartProductRole, CWriteablePartProductRole *pNewPartProductRole, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CPartProductRole，同时删除其索引
	///@param	pPartProductRole	要删除的CPartProductRole
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CPartProductRole *pPartProductRole, CTransaction *pTransaction=NULL);
	
	///获取某个CPartProductRole
	///@param	pPartProductRole	要读取的CPartProductRole
	///@param	pTragetPartProductRole	存放结果的CPartProductRole
	void retrieve(CPartProductRole *pPartProductRole, CWriteablePartProductRole *pTargetPartProductRole);
	
	///获取第一个CPartProductRole
	///@return	得到的第一个CPartProductRole，如果没有，则返回NULL
	CPartProductRole *getFirst(void);
	
	///获取下一个CPartProductRole
	///@return	得到下一个CPartProductRole，如果没有，则返回NULL
	CPartProductRole *getNext(void);
	
	///结束获取CPartProductRole
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CPartProductRoleActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CPartProductRoleActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CPartProductRoleCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CPartProductRoleCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CPartProductRoleIteratorBySettlementGroupID;

	///开始寻找CPartProductRole
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CPartProductRole，如果找不到，返回NULL
	CPartProductRole *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CPartProductRole，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CPartProductRole，如果已经没有一个满足要求了，则返回NULL
	CPartProductRole *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CPartProductRole
	///@param	ParticipantID	会员编号
	///@param	ProductID	产品编号
	///@param	TradingRole	交易角色
	///@return	找到的CPartProductRole，如果找不到，返回NULL
	CPartProductRole *findByParticipantProductRole( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyProductIDType&  ProductID,  const CReadOnlyTradingRoleType&  TradingRole);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CPartProductRole加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pPartProductRole	要加入的PartProductRole
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CPartProductRole *internalAdd(CWriteablePartProductRole *pPartProductRole, bool bNoTransaction);
	
	
	///刷新该CPartProductRole的键值
	///@param	pPartProductRole	被刷新的CPartProductRole
	///@param	pNewPartProductRole	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CPartProductRole *pPartProductRole, CWriteablePartProductRole *pNewPartProductRole, bool updateIndex,bool bNoTransaction);
	
	///删除一个CPartProductRole，同时删除其索引
	///@param	pPartProductRole	要删除的CPartProductRole
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CPartProductRole *pPartProductRole, bool bNoTransaction);
/*
	///检查某个CPartProductRole是否属于本对象工厂
	///@param	pPartProductRole	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CPartProductRole *pPartProductRole);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	
	///基于ParticipantProductRole的hash索引
	CHashIndex *pParticipantProductRoleHashIndex;
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CPartProductRole *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pPartProductRole	要加入的PartProductRole
	virtual void beforeAdd(CWriteablePartProductRole *pPartProductRole);
	
	///加入后触发
	///@param	pPartProductRole	已经加入的PartProductRole
	virtual void afterAdd(CPartProductRole *pPartProductRole);

	///更新前触发	
	///@param	pPartProductRole	被刷新的CPartProductRole
	///@param	pNewPartProductRole	新的值
	virtual void beforeUpdate(CPartProductRole *pPartProductRole, CWriteablePartProductRole *pNewPartProductRole);
	
	///更新后触发
	///@param	pPartProductRole	被刷新的CPartProductRole
	virtual void afterUpdate(CPartProductRole *pPartProductRole);
	
	///删除前触发
	///@param	pPartProductRole	要删除的CPartProductRole
	virtual void beforeRemove(CPartProductRole *pPartProductRole);
	
	///确认加入后触发
	///@param	pPartProductRole	已经加入的PartProductRole
	virtual void commitAdd(CPartProductRole *pPartProductRole);

	///确认更新后触发
	///@param	pPartProductRole	被刷新的CPartProductRole
	///@param	poldPartProductRole	原来的值
	virtual void commitUpdate(CPartProductRole *pPartProductRole, CWriteablePartProductRole *pOldPartProductRole);
	
	///确认删除后触发
	///@param	pPartProductRole	已经删除的CPartProductRole
	virtual void commitRemove(CWriteablePartProductRole *pPartProductRole);

	///所有相关的触发器
	vector<CPartProductRoleActionTrigger *> *pActionTriggers;
	vector<CPartProductRoleCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteablePartProductRole compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRightFactory是一个会员产品交易权限的对象工厂。它包含了一批会员产品交易权限，
///同时又建立了如下索引，以方便查询：
///使用本对象工厂，可以完成对会员产品交易权限的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByParticipantAndProduct，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRightFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CPartProductRightFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxPartProductRight，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CPartProductRightFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CPartProductRightFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的PartProductRight
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的PartProductRight，文件名将根据配置文件中的定义PartProductRightCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的PartProductRight
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的PartProductRight，文件名将根据配置文件中的定义PartProductRightCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CPartProductRightResource;

	///将一个CPartProductRight加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pPartProductRight	要加入的PartProductRight
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CPartProductRight *add(CWriteablePartProductRight *pPartProductRight, CTransaction *pTransaction=NULL);
	
	///刷新该CPartProductRight的值
	///@param	pPartProductRight	被刷新的CPartProductRight
	///@param	pNewPartProductRight	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CPartProductRight *pPartProductRight, CWriteablePartProductRight *pNewPartProductRight, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pPartProductRight	  需要被刷新或者新增的CPartProductRight,等于NULL表示是需要新增的
	///@param	pNewPartProductRight	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CPartProductRight* addOrUpdate(CPartProductRight *pPartProductRight, CWriteablePartProductRight *pNewPartProductRight, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CPartProductRight，同时删除其索引
	///@param	pPartProductRight	要删除的CPartProductRight
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CPartProductRight *pPartProductRight, CTransaction *pTransaction=NULL);
	
	///获取某个CPartProductRight
	///@param	pPartProductRight	要读取的CPartProductRight
	///@param	pTragetPartProductRight	存放结果的CPartProductRight
	void retrieve(CPartProductRight *pPartProductRight, CWriteablePartProductRight *pTargetPartProductRight);
	
	///获取第一个CPartProductRight
	///@return	得到的第一个CPartProductRight，如果没有，则返回NULL
	CPartProductRight *getFirst(void);
	
	///获取下一个CPartProductRight
	///@return	得到下一个CPartProductRight，如果没有，则返回NULL
	CPartProductRight *getNext(void);
	
	///结束获取CPartProductRight
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CPartProductRightActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CPartProductRightActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CPartProductRightCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CPartProductRightCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CPartProductRightIteratorBySettlementGroupID;

	///开始寻找CPartProductRight
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CPartProductRight，如果找不到，返回NULL
	CPartProductRight *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CPartProductRight，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CPartProductRight，如果已经没有一个满足要求了，则返回NULL
	CPartProductRight *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CPartProductRight
	///@param	ParticipantID	会员编号
	///@param	ProductID	产品编号
	///@return	找到的CPartProductRight，如果找不到，返回NULL
	CPartProductRight *findByParticipantAndProduct( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyProductIDType&  ProductID);

	///根据主码寻找
	///@param	ParticipantID	会员编号
	///@param	ProductID	产品编号
	///@return	找到的CPartProductRight，如果找不到，返回NULL
	CPartProductRight *findByPK( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyProductIDType&  ProductID);
	
	///根据主键寻找CPartProductRight
	///@param	pPartProductRight	要找的值
	///@return	找到的CPartProductRight，如果找不到，返回NULL
	CPartProductRight *findByPK(CWriteablePartProductRight *pPartProductRight);

	///根据主键获取CPartProductRight
	///@param	pPartProductRight	要获取的值，同时用于存放返回的结果
	///@return	找到的CPartProductRight，如果找不到，返回NULL
	bool retrieveByPK(CWriteablePartProductRight *pPartProductRight);

	///根据主键增加新的CPartProductRight
	///@param	pPartProductRight	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	返回插入的CPartProductRight，如果插入失败，则返回NULL
	CPartProductRight *addByPK(CWriteablePartProductRight *pPartProductRight, CTransaction *pTransaction=NULL);

	///根据主键更新CPartProductRight的值
	///@param	pPartProductRight	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	///@return	true表示成功，false表示失败
	bool updateByPK(CWriteablePartProductRight *pPartProductRight, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///根据主键删除CPartProductRight
	///@param	pPartProductRight	要删除的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	true表示成功，false表示失败
	bool removeByPK(CWriteablePartProductRight *pPartProductRight, CTransaction *pTransaction=NULL);


private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CPartProductRight加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pPartProductRight	要加入的PartProductRight
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CPartProductRight *internalAdd(CWriteablePartProductRight *pPartProductRight, bool bNoTransaction);
	
	
	///刷新该CPartProductRight的键值
	///@param	pPartProductRight	被刷新的CPartProductRight
	///@param	pNewPartProductRight	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CPartProductRight *pPartProductRight, CWriteablePartProductRight *pNewPartProductRight, bool updateIndex,bool bNoTransaction);
	
	///删除一个CPartProductRight，同时删除其索引
	///@param	pPartProductRight	要删除的CPartProductRight
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CPartProductRight *pPartProductRight, bool bNoTransaction);
/*
	///检查某个CPartProductRight是否属于本对象工厂
	///@param	pPartProductRight	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CPartProductRight *pPartProductRight);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	
	///基于ParticipantAndProduct的hash索引
	CHashIndex *pParticipantAndProductHashIndex;
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CPartProductRight *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pPartProductRight	要加入的PartProductRight
	virtual void beforeAdd(CWriteablePartProductRight *pPartProductRight);
	
	///加入后触发
	///@param	pPartProductRight	已经加入的PartProductRight
	virtual void afterAdd(CPartProductRight *pPartProductRight);

	///更新前触发	
	///@param	pPartProductRight	被刷新的CPartProductRight
	///@param	pNewPartProductRight	新的值
	virtual void beforeUpdate(CPartProductRight *pPartProductRight, CWriteablePartProductRight *pNewPartProductRight);
	
	///更新后触发
	///@param	pPartProductRight	被刷新的CPartProductRight
	virtual void afterUpdate(CPartProductRight *pPartProductRight);
	
	///删除前触发
	///@param	pPartProductRight	要删除的CPartProductRight
	virtual void beforeRemove(CPartProductRight *pPartProductRight);
	
	///确认加入后触发
	///@param	pPartProductRight	已经加入的PartProductRight
	virtual void commitAdd(CPartProductRight *pPartProductRight);

	///确认更新后触发
	///@param	pPartProductRight	被刷新的CPartProductRight
	///@param	poldPartProductRight	原来的值
	virtual void commitUpdate(CPartProductRight *pPartProductRight, CWriteablePartProductRight *pOldPartProductRight);
	
	///确认删除后触发
	///@param	pPartProductRight	已经删除的CPartProductRight
	virtual void commitRemove(CWriteablePartProductRight *pPartProductRight);

	///所有相关的触发器
	vector<CPartProductRightActionTrigger *> *pActionTriggers;
	vector<CPartProductRightCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteablePartProductRight compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CPartInstrumentRightFactory是一个会员合约交易权限的对象工厂。它包含了一批会员合约交易权限，
///同时又建立了如下索引，以方便查询：
///使用本对象工厂，可以完成对会员合约交易权限的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByParticipantAndInstrument，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartInstrumentRightFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CPartInstrumentRightFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxPartInstrumentRight，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CPartInstrumentRightFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CPartInstrumentRightFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的PartInstrumentRight
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的PartInstrumentRight，文件名将根据配置文件中的定义PartInstrumentRightCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的PartInstrumentRight
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的PartInstrumentRight，文件名将根据配置文件中的定义PartInstrumentRightCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CPartInstrumentRightResource;

	///将一个CPartInstrumentRight加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pPartInstrumentRight	要加入的PartInstrumentRight
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CPartInstrumentRight *add(CWriteablePartInstrumentRight *pPartInstrumentRight, CTransaction *pTransaction=NULL);
	
	///刷新该CPartInstrumentRight的值
	///@param	pPartInstrumentRight	被刷新的CPartInstrumentRight
	///@param	pNewPartInstrumentRight	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CPartInstrumentRight *pPartInstrumentRight, CWriteablePartInstrumentRight *pNewPartInstrumentRight, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pPartInstrumentRight	  需要被刷新或者新增的CPartInstrumentRight,等于NULL表示是需要新增的
	///@param	pNewPartInstrumentRight	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CPartInstrumentRight* addOrUpdate(CPartInstrumentRight *pPartInstrumentRight, CWriteablePartInstrumentRight *pNewPartInstrumentRight, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CPartInstrumentRight，同时删除其索引
	///@param	pPartInstrumentRight	要删除的CPartInstrumentRight
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CPartInstrumentRight *pPartInstrumentRight, CTransaction *pTransaction=NULL);
	
	///获取某个CPartInstrumentRight
	///@param	pPartInstrumentRight	要读取的CPartInstrumentRight
	///@param	pTragetPartInstrumentRight	存放结果的CPartInstrumentRight
	void retrieve(CPartInstrumentRight *pPartInstrumentRight, CWriteablePartInstrumentRight *pTargetPartInstrumentRight);
	
	///获取第一个CPartInstrumentRight
	///@return	得到的第一个CPartInstrumentRight，如果没有，则返回NULL
	CPartInstrumentRight *getFirst(void);
	
	///获取下一个CPartInstrumentRight
	///@return	得到下一个CPartInstrumentRight，如果没有，则返回NULL
	CPartInstrumentRight *getNext(void);
	
	///结束获取CPartInstrumentRight
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CPartInstrumentRightActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CPartInstrumentRightActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CPartInstrumentRightCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CPartInstrumentRightCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CPartInstrumentRightIteratorBySettlementGroupID;

	///开始寻找CPartInstrumentRight
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CPartInstrumentRight，如果找不到，返回NULL
	CPartInstrumentRight *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CPartInstrumentRight，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CPartInstrumentRight，如果已经没有一个满足要求了，则返回NULL
	CPartInstrumentRight *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CPartInstrumentRight
	///@param	ParticipantID	会员编号
	///@param	InstrumentID	合约代码
	///@return	找到的CPartInstrumentRight，如果找不到，返回NULL
	CPartInstrumentRight *findByParticipantAndInstrument( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyInstrumentIDType&  InstrumentID);

	///根据主码寻找
	///@param	ParticipantID	会员编号
	///@param	InstrumentID	合约代码
	///@return	找到的CPartInstrumentRight，如果找不到，返回NULL
	CPartInstrumentRight *findByPK( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyInstrumentIDType&  InstrumentID);
	
	///根据主键寻找CPartInstrumentRight
	///@param	pPartInstrumentRight	要找的值
	///@return	找到的CPartInstrumentRight，如果找不到，返回NULL
	CPartInstrumentRight *findByPK(CWriteablePartInstrumentRight *pPartInstrumentRight);

	///根据主键获取CPartInstrumentRight
	///@param	pPartInstrumentRight	要获取的值，同时用于存放返回的结果
	///@return	找到的CPartInstrumentRight，如果找不到，返回NULL
	bool retrieveByPK(CWriteablePartInstrumentRight *pPartInstrumentRight);

	///根据主键增加新的CPartInstrumentRight
	///@param	pPartInstrumentRight	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	返回插入的CPartInstrumentRight，如果插入失败，则返回NULL
	CPartInstrumentRight *addByPK(CWriteablePartInstrumentRight *pPartInstrumentRight, CTransaction *pTransaction=NULL);

	///根据主键更新CPartInstrumentRight的值
	///@param	pPartInstrumentRight	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	///@return	true表示成功，false表示失败
	bool updateByPK(CWriteablePartInstrumentRight *pPartInstrumentRight, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///根据主键删除CPartInstrumentRight
	///@param	pPartInstrumentRight	要删除的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	true表示成功，false表示失败
	bool removeByPK(CWriteablePartInstrumentRight *pPartInstrumentRight, CTransaction *pTransaction=NULL);


private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CPartInstrumentRight加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pPartInstrumentRight	要加入的PartInstrumentRight
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CPartInstrumentRight *internalAdd(CWriteablePartInstrumentRight *pPartInstrumentRight, bool bNoTransaction);
	
	
	///刷新该CPartInstrumentRight的键值
	///@param	pPartInstrumentRight	被刷新的CPartInstrumentRight
	///@param	pNewPartInstrumentRight	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CPartInstrumentRight *pPartInstrumentRight, CWriteablePartInstrumentRight *pNewPartInstrumentRight, bool updateIndex,bool bNoTransaction);
	
	///删除一个CPartInstrumentRight，同时删除其索引
	///@param	pPartInstrumentRight	要删除的CPartInstrumentRight
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CPartInstrumentRight *pPartInstrumentRight, bool bNoTransaction);
/*
	///检查某个CPartInstrumentRight是否属于本对象工厂
	///@param	pPartInstrumentRight	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CPartInstrumentRight *pPartInstrumentRight);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	
	///基于ParticipantAndInstrument的hash索引
	CHashIndex *pParticipantAndInstrumentHashIndex;
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CPartInstrumentRight *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pPartInstrumentRight	要加入的PartInstrumentRight
	virtual void beforeAdd(CWriteablePartInstrumentRight *pPartInstrumentRight);
	
	///加入后触发
	///@param	pPartInstrumentRight	已经加入的PartInstrumentRight
	virtual void afterAdd(CPartInstrumentRight *pPartInstrumentRight);

	///更新前触发	
	///@param	pPartInstrumentRight	被刷新的CPartInstrumentRight
	///@param	pNewPartInstrumentRight	新的值
	virtual void beforeUpdate(CPartInstrumentRight *pPartInstrumentRight, CWriteablePartInstrumentRight *pNewPartInstrumentRight);
	
	///更新后触发
	///@param	pPartInstrumentRight	被刷新的CPartInstrumentRight
	virtual void afterUpdate(CPartInstrumentRight *pPartInstrumentRight);
	
	///删除前触发
	///@param	pPartInstrumentRight	要删除的CPartInstrumentRight
	virtual void beforeRemove(CPartInstrumentRight *pPartInstrumentRight);
	
	///确认加入后触发
	///@param	pPartInstrumentRight	已经加入的PartInstrumentRight
	virtual void commitAdd(CPartInstrumentRight *pPartInstrumentRight);

	///确认更新后触发
	///@param	pPartInstrumentRight	被刷新的CPartInstrumentRight
	///@param	poldPartInstrumentRight	原来的值
	virtual void commitUpdate(CPartInstrumentRight *pPartInstrumentRight, CWriteablePartInstrumentRight *pOldPartInstrumentRight);
	
	///确认删除后触发
	///@param	pPartInstrumentRight	已经删除的CPartInstrumentRight
	virtual void commitRemove(CWriteablePartInstrumentRight *pPartInstrumentRight);

	///所有相关的触发器
	vector<CPartInstrumentRightActionTrigger *> *pActionTriggers;
	vector<CPartInstrumentRightCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteablePartInstrumentRight compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CClientProductRightFactory是一个客户产品交易权限的对象工厂。它包含了一批客户产品交易权限，
///同时又建立了如下索引，以方便查询：
///使用本对象工厂，可以完成对客户产品交易权限的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByClientAndProduct，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientProductRightFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CClientProductRightFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxClientProductRight，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CClientProductRightFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CClientProductRightFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的ClientProductRight
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的ClientProductRight，文件名将根据配置文件中的定义ClientProductRightCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的ClientProductRight
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的ClientProductRight，文件名将根据配置文件中的定义ClientProductRightCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CClientProductRightResource;

	///将一个CClientProductRight加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pClientProductRight	要加入的ClientProductRight
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CClientProductRight *add(CWriteableClientProductRight *pClientProductRight, CTransaction *pTransaction=NULL);
	
	///刷新该CClientProductRight的值
	///@param	pClientProductRight	被刷新的CClientProductRight
	///@param	pNewClientProductRight	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CClientProductRight *pClientProductRight, CWriteableClientProductRight *pNewClientProductRight, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pClientProductRight	  需要被刷新或者新增的CClientProductRight,等于NULL表示是需要新增的
	///@param	pNewClientProductRight	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CClientProductRight* addOrUpdate(CClientProductRight *pClientProductRight, CWriteableClientProductRight *pNewClientProductRight, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CClientProductRight，同时删除其索引
	///@param	pClientProductRight	要删除的CClientProductRight
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CClientProductRight *pClientProductRight, CTransaction *pTransaction=NULL);
	
	///获取某个CClientProductRight
	///@param	pClientProductRight	要读取的CClientProductRight
	///@param	pTragetClientProductRight	存放结果的CClientProductRight
	void retrieve(CClientProductRight *pClientProductRight, CWriteableClientProductRight *pTargetClientProductRight);
	
	///获取第一个CClientProductRight
	///@return	得到的第一个CClientProductRight，如果没有，则返回NULL
	CClientProductRight *getFirst(void);
	
	///获取下一个CClientProductRight
	///@return	得到下一个CClientProductRight，如果没有，则返回NULL
	CClientProductRight *getNext(void);
	
	///结束获取CClientProductRight
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CClientProductRightActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CClientProductRightActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CClientProductRightCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CClientProductRightCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CClientProductRightIteratorBySettlementGroupID;

	///开始寻找CClientProductRight
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CClientProductRight，如果找不到，返回NULL
	CClientProductRight *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CClientProductRight，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CClientProductRight，如果已经没有一个满足要求了，则返回NULL
	CClientProductRight *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CClientProductRight
	///@param	ClientID	客户编号
	///@param	ProductID	产品编号
	///@return	找到的CClientProductRight，如果找不到，返回NULL
	CClientProductRight *findByClientAndProduct( const CReadOnlyClientIDType&  ClientID,  const CReadOnlyProductIDType&  ProductID);

	///根据主码寻找
	///@param	ClientID	客户编号
	///@param	ProductID	产品编号
	///@return	找到的CClientProductRight，如果找不到，返回NULL
	CClientProductRight *findByPK( const CReadOnlyClientIDType&  ClientID,  const CReadOnlyProductIDType&  ProductID);
	
	///根据主键寻找CClientProductRight
	///@param	pClientProductRight	要找的值
	///@return	找到的CClientProductRight，如果找不到，返回NULL
	CClientProductRight *findByPK(CWriteableClientProductRight *pClientProductRight);

	///根据主键获取CClientProductRight
	///@param	pClientProductRight	要获取的值，同时用于存放返回的结果
	///@return	找到的CClientProductRight，如果找不到，返回NULL
	bool retrieveByPK(CWriteableClientProductRight *pClientProductRight);

	///根据主键增加新的CClientProductRight
	///@param	pClientProductRight	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	返回插入的CClientProductRight，如果插入失败，则返回NULL
	CClientProductRight *addByPK(CWriteableClientProductRight *pClientProductRight, CTransaction *pTransaction=NULL);

	///根据主键更新CClientProductRight的值
	///@param	pClientProductRight	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	///@return	true表示成功，false表示失败
	bool updateByPK(CWriteableClientProductRight *pClientProductRight, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///根据主键删除CClientProductRight
	///@param	pClientProductRight	要删除的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	true表示成功，false表示失败
	bool removeByPK(CWriteableClientProductRight *pClientProductRight, CTransaction *pTransaction=NULL);


private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CClientProductRight加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pClientProductRight	要加入的ClientProductRight
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CClientProductRight *internalAdd(CWriteableClientProductRight *pClientProductRight, bool bNoTransaction);
	
	
	///刷新该CClientProductRight的键值
	///@param	pClientProductRight	被刷新的CClientProductRight
	///@param	pNewClientProductRight	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CClientProductRight *pClientProductRight, CWriteableClientProductRight *pNewClientProductRight, bool updateIndex,bool bNoTransaction);
	
	///删除一个CClientProductRight，同时删除其索引
	///@param	pClientProductRight	要删除的CClientProductRight
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CClientProductRight *pClientProductRight, bool bNoTransaction);
/*
	///检查某个CClientProductRight是否属于本对象工厂
	///@param	pClientProductRight	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CClientProductRight *pClientProductRight);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	
	///基于ClientAndProduct的hash索引
	CHashIndex *pClientAndProductHashIndex;
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CClientProductRight *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pClientProductRight	要加入的ClientProductRight
	virtual void beforeAdd(CWriteableClientProductRight *pClientProductRight);
	
	///加入后触发
	///@param	pClientProductRight	已经加入的ClientProductRight
	virtual void afterAdd(CClientProductRight *pClientProductRight);

	///更新前触发	
	///@param	pClientProductRight	被刷新的CClientProductRight
	///@param	pNewClientProductRight	新的值
	virtual void beforeUpdate(CClientProductRight *pClientProductRight, CWriteableClientProductRight *pNewClientProductRight);
	
	///更新后触发
	///@param	pClientProductRight	被刷新的CClientProductRight
	virtual void afterUpdate(CClientProductRight *pClientProductRight);
	
	///删除前触发
	///@param	pClientProductRight	要删除的CClientProductRight
	virtual void beforeRemove(CClientProductRight *pClientProductRight);
	
	///确认加入后触发
	///@param	pClientProductRight	已经加入的ClientProductRight
	virtual void commitAdd(CClientProductRight *pClientProductRight);

	///确认更新后触发
	///@param	pClientProductRight	被刷新的CClientProductRight
	///@param	poldClientProductRight	原来的值
	virtual void commitUpdate(CClientProductRight *pClientProductRight, CWriteableClientProductRight *pOldClientProductRight);
	
	///确认删除后触发
	///@param	pClientProductRight	已经删除的CClientProductRight
	virtual void commitRemove(CWriteableClientProductRight *pClientProductRight);

	///所有相关的触发器
	vector<CClientProductRightActionTrigger *> *pActionTriggers;
	vector<CClientProductRightCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableClientProductRight compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CClientInstrumentRightFactory是一个客户合约交易权限的对象工厂。它包含了一批客户合约交易权限，
///同时又建立了如下索引，以方便查询：
///使用本对象工厂，可以完成对客户合约交易权限的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByClientAndInstrument，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientInstrumentRightFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CClientInstrumentRightFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxClientInstrumentRight，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CClientInstrumentRightFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CClientInstrumentRightFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的ClientInstrumentRight
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的ClientInstrumentRight，文件名将根据配置文件中的定义ClientInstrumentRightCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的ClientInstrumentRight
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的ClientInstrumentRight，文件名将根据配置文件中的定义ClientInstrumentRightCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CClientInstrumentRightResource;

	///将一个CClientInstrumentRight加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pClientInstrumentRight	要加入的ClientInstrumentRight
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CClientInstrumentRight *add(CWriteableClientInstrumentRight *pClientInstrumentRight, CTransaction *pTransaction=NULL);
	
	///刷新该CClientInstrumentRight的值
	///@param	pClientInstrumentRight	被刷新的CClientInstrumentRight
	///@param	pNewClientInstrumentRight	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CClientInstrumentRight *pClientInstrumentRight, CWriteableClientInstrumentRight *pNewClientInstrumentRight, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pClientInstrumentRight	  需要被刷新或者新增的CClientInstrumentRight,等于NULL表示是需要新增的
	///@param	pNewClientInstrumentRight	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CClientInstrumentRight* addOrUpdate(CClientInstrumentRight *pClientInstrumentRight, CWriteableClientInstrumentRight *pNewClientInstrumentRight, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CClientInstrumentRight，同时删除其索引
	///@param	pClientInstrumentRight	要删除的CClientInstrumentRight
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CClientInstrumentRight *pClientInstrumentRight, CTransaction *pTransaction=NULL);
	
	///获取某个CClientInstrumentRight
	///@param	pClientInstrumentRight	要读取的CClientInstrumentRight
	///@param	pTragetClientInstrumentRight	存放结果的CClientInstrumentRight
	void retrieve(CClientInstrumentRight *pClientInstrumentRight, CWriteableClientInstrumentRight *pTargetClientInstrumentRight);
	
	///获取第一个CClientInstrumentRight
	///@return	得到的第一个CClientInstrumentRight，如果没有，则返回NULL
	CClientInstrumentRight *getFirst(void);
	
	///获取下一个CClientInstrumentRight
	///@return	得到下一个CClientInstrumentRight，如果没有，则返回NULL
	CClientInstrumentRight *getNext(void);
	
	///结束获取CClientInstrumentRight
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CClientInstrumentRightActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CClientInstrumentRightActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CClientInstrumentRightCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CClientInstrumentRightCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CClientInstrumentRightIteratorBySettlementGroupID;

	///开始寻找CClientInstrumentRight
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CClientInstrumentRight，如果找不到，返回NULL
	CClientInstrumentRight *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CClientInstrumentRight，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CClientInstrumentRight，如果已经没有一个满足要求了，则返回NULL
	CClientInstrumentRight *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CClientInstrumentRight
	///@param	ClientID	客户编号
	///@param	InstrumentID	合约代码
	///@return	找到的CClientInstrumentRight，如果找不到，返回NULL
	CClientInstrumentRight *findByClientAndInstrument( const CReadOnlyClientIDType&  ClientID,  const CReadOnlyInstrumentIDType&  InstrumentID);

	///根据主码寻找
	///@param	ClientID	客户编号
	///@param	InstrumentID	合约代码
	///@return	找到的CClientInstrumentRight，如果找不到，返回NULL
	CClientInstrumentRight *findByPK( const CReadOnlyClientIDType&  ClientID,  const CReadOnlyInstrumentIDType&  InstrumentID);
	
	///根据主键寻找CClientInstrumentRight
	///@param	pClientInstrumentRight	要找的值
	///@return	找到的CClientInstrumentRight，如果找不到，返回NULL
	CClientInstrumentRight *findByPK(CWriteableClientInstrumentRight *pClientInstrumentRight);

	///根据主键获取CClientInstrumentRight
	///@param	pClientInstrumentRight	要获取的值，同时用于存放返回的结果
	///@return	找到的CClientInstrumentRight，如果找不到，返回NULL
	bool retrieveByPK(CWriteableClientInstrumentRight *pClientInstrumentRight);

	///根据主键增加新的CClientInstrumentRight
	///@param	pClientInstrumentRight	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	返回插入的CClientInstrumentRight，如果插入失败，则返回NULL
	CClientInstrumentRight *addByPK(CWriteableClientInstrumentRight *pClientInstrumentRight, CTransaction *pTransaction=NULL);

	///根据主键更新CClientInstrumentRight的值
	///@param	pClientInstrumentRight	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	///@return	true表示成功，false表示失败
	bool updateByPK(CWriteableClientInstrumentRight *pClientInstrumentRight, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///根据主键删除CClientInstrumentRight
	///@param	pClientInstrumentRight	要删除的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	true表示成功，false表示失败
	bool removeByPK(CWriteableClientInstrumentRight *pClientInstrumentRight, CTransaction *pTransaction=NULL);


private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CClientInstrumentRight加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pClientInstrumentRight	要加入的ClientInstrumentRight
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CClientInstrumentRight *internalAdd(CWriteableClientInstrumentRight *pClientInstrumentRight, bool bNoTransaction);
	
	
	///刷新该CClientInstrumentRight的键值
	///@param	pClientInstrumentRight	被刷新的CClientInstrumentRight
	///@param	pNewClientInstrumentRight	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CClientInstrumentRight *pClientInstrumentRight, CWriteableClientInstrumentRight *pNewClientInstrumentRight, bool updateIndex,bool bNoTransaction);
	
	///删除一个CClientInstrumentRight，同时删除其索引
	///@param	pClientInstrumentRight	要删除的CClientInstrumentRight
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CClientInstrumentRight *pClientInstrumentRight, bool bNoTransaction);
/*
	///检查某个CClientInstrumentRight是否属于本对象工厂
	///@param	pClientInstrumentRight	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CClientInstrumentRight *pClientInstrumentRight);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	
	///基于ClientAndInstrument的hash索引
	CHashIndex *pClientAndInstrumentHashIndex;
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CClientInstrumentRight *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pClientInstrumentRight	要加入的ClientInstrumentRight
	virtual void beforeAdd(CWriteableClientInstrumentRight *pClientInstrumentRight);
	
	///加入后触发
	///@param	pClientInstrumentRight	已经加入的ClientInstrumentRight
	virtual void afterAdd(CClientInstrumentRight *pClientInstrumentRight);

	///更新前触发	
	///@param	pClientInstrumentRight	被刷新的CClientInstrumentRight
	///@param	pNewClientInstrumentRight	新的值
	virtual void beforeUpdate(CClientInstrumentRight *pClientInstrumentRight, CWriteableClientInstrumentRight *pNewClientInstrumentRight);
	
	///更新后触发
	///@param	pClientInstrumentRight	被刷新的CClientInstrumentRight
	virtual void afterUpdate(CClientInstrumentRight *pClientInstrumentRight);
	
	///删除前触发
	///@param	pClientInstrumentRight	要删除的CClientInstrumentRight
	virtual void beforeRemove(CClientInstrumentRight *pClientInstrumentRight);
	
	///确认加入后触发
	///@param	pClientInstrumentRight	已经加入的ClientInstrumentRight
	virtual void commitAdd(CClientInstrumentRight *pClientInstrumentRight);

	///确认更新后触发
	///@param	pClientInstrumentRight	被刷新的CClientInstrumentRight
	///@param	poldClientInstrumentRight	原来的值
	virtual void commitUpdate(CClientInstrumentRight *pClientInstrumentRight, CWriteableClientInstrumentRight *pOldClientInstrumentRight);
	
	///确认删除后触发
	///@param	pClientInstrumentRight	已经删除的CClientInstrumentRight
	virtual void commitRemove(CWriteableClientInstrumentRight *pClientInstrumentRight);

	///所有相关的触发器
	vector<CClientInstrumentRightActionTrigger *> *pActionTriggers;
	vector<CClientInstrumentRightCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableClientInstrumentRight compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientProductRightFactory是一个会员客户产品交易权限的对象工厂。它包含了一批会员客户产品交易权限，
///同时又建立了如下索引，以方便查询：
///使用本对象工厂，可以完成对会员客户产品交易权限的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByParticipantAndClientAndProduct，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientProductRightFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CPartClientProductRightFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxPartClientProductRight，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CPartClientProductRightFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CPartClientProductRightFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的PartClientProductRight
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的PartClientProductRight，文件名将根据配置文件中的定义PartClientProductRightCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的PartClientProductRight
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的PartClientProductRight，文件名将根据配置文件中的定义PartClientProductRightCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CPartClientProductRightResource;

	///将一个CPartClientProductRight加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pPartClientProductRight	要加入的PartClientProductRight
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CPartClientProductRight *add(CWriteablePartClientProductRight *pPartClientProductRight, CTransaction *pTransaction=NULL);
	
	///刷新该CPartClientProductRight的值
	///@param	pPartClientProductRight	被刷新的CPartClientProductRight
	///@param	pNewPartClientProductRight	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CPartClientProductRight *pPartClientProductRight, CWriteablePartClientProductRight *pNewPartClientProductRight, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pPartClientProductRight	  需要被刷新或者新增的CPartClientProductRight,等于NULL表示是需要新增的
	///@param	pNewPartClientProductRight	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CPartClientProductRight* addOrUpdate(CPartClientProductRight *pPartClientProductRight, CWriteablePartClientProductRight *pNewPartClientProductRight, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CPartClientProductRight，同时删除其索引
	///@param	pPartClientProductRight	要删除的CPartClientProductRight
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CPartClientProductRight *pPartClientProductRight, CTransaction *pTransaction=NULL);
	
	///获取某个CPartClientProductRight
	///@param	pPartClientProductRight	要读取的CPartClientProductRight
	///@param	pTragetPartClientProductRight	存放结果的CPartClientProductRight
	void retrieve(CPartClientProductRight *pPartClientProductRight, CWriteablePartClientProductRight *pTargetPartClientProductRight);
	
	///获取第一个CPartClientProductRight
	///@return	得到的第一个CPartClientProductRight，如果没有，则返回NULL
	CPartClientProductRight *getFirst(void);
	
	///获取下一个CPartClientProductRight
	///@return	得到下一个CPartClientProductRight，如果没有，则返回NULL
	CPartClientProductRight *getNext(void);
	
	///结束获取CPartClientProductRight
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CPartClientProductRightActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CPartClientProductRightActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CPartClientProductRightCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CPartClientProductRightCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CPartClientProductRightIteratorBySettlementGroupID;

	///开始寻找CPartClientProductRight
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CPartClientProductRight，如果找不到，返回NULL
	CPartClientProductRight *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CPartClientProductRight，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CPartClientProductRight，如果已经没有一个满足要求了，则返回NULL
	CPartClientProductRight *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CPartClientProductRight
	///@param	ParticipantID	会员编号
	///@param	ClientID	客户编号
	///@param	ProductID	产品编号
	///@return	找到的CPartClientProductRight，如果找不到，返回NULL
	CPartClientProductRight *findByParticipantAndClientAndProduct( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyClientIDType&  ClientID,  const CReadOnlyProductIDType&  ProductID);

	///根据主码寻找
	///@param	ParticipantID	会员编号
	///@param	ClientID	客户编号
	///@param	ProductID	产品编号
	///@return	找到的CPartClientProductRight，如果找不到，返回NULL
	CPartClientProductRight *findByPK( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyClientIDType&  ClientID,  const CReadOnlyProductIDType&  ProductID);
	
	///根据主键寻找CPartClientProductRight
	///@param	pPartClientProductRight	要找的值
	///@return	找到的CPartClientProductRight，如果找不到，返回NULL
	CPartClientProductRight *findByPK(CWriteablePartClientProductRight *pPartClientProductRight);

	///根据主键获取CPartClientProductRight
	///@param	pPartClientProductRight	要获取的值，同时用于存放返回的结果
	///@return	找到的CPartClientProductRight，如果找不到，返回NULL
	bool retrieveByPK(CWriteablePartClientProductRight *pPartClientProductRight);

	///根据主键增加新的CPartClientProductRight
	///@param	pPartClientProductRight	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	返回插入的CPartClientProductRight，如果插入失败，则返回NULL
	CPartClientProductRight *addByPK(CWriteablePartClientProductRight *pPartClientProductRight, CTransaction *pTransaction=NULL);

	///根据主键更新CPartClientProductRight的值
	///@param	pPartClientProductRight	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	///@return	true表示成功，false表示失败
	bool updateByPK(CWriteablePartClientProductRight *pPartClientProductRight, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///根据主键删除CPartClientProductRight
	///@param	pPartClientProductRight	要删除的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	true表示成功，false表示失败
	bool removeByPK(CWriteablePartClientProductRight *pPartClientProductRight, CTransaction *pTransaction=NULL);


private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CPartClientProductRight加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pPartClientProductRight	要加入的PartClientProductRight
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CPartClientProductRight *internalAdd(CWriteablePartClientProductRight *pPartClientProductRight, bool bNoTransaction);
	
	
	///刷新该CPartClientProductRight的键值
	///@param	pPartClientProductRight	被刷新的CPartClientProductRight
	///@param	pNewPartClientProductRight	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CPartClientProductRight *pPartClientProductRight, CWriteablePartClientProductRight *pNewPartClientProductRight, bool updateIndex,bool bNoTransaction);
	
	///删除一个CPartClientProductRight，同时删除其索引
	///@param	pPartClientProductRight	要删除的CPartClientProductRight
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CPartClientProductRight *pPartClientProductRight, bool bNoTransaction);
/*
	///检查某个CPartClientProductRight是否属于本对象工厂
	///@param	pPartClientProductRight	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CPartClientProductRight *pPartClientProductRight);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	
	///基于ParticipantAndClientAndProduct的hash索引
	CHashIndex *pParticipantAndClientAndProductHashIndex;
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CPartClientProductRight *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pPartClientProductRight	要加入的PartClientProductRight
	virtual void beforeAdd(CWriteablePartClientProductRight *pPartClientProductRight);
	
	///加入后触发
	///@param	pPartClientProductRight	已经加入的PartClientProductRight
	virtual void afterAdd(CPartClientProductRight *pPartClientProductRight);

	///更新前触发	
	///@param	pPartClientProductRight	被刷新的CPartClientProductRight
	///@param	pNewPartClientProductRight	新的值
	virtual void beforeUpdate(CPartClientProductRight *pPartClientProductRight, CWriteablePartClientProductRight *pNewPartClientProductRight);
	
	///更新后触发
	///@param	pPartClientProductRight	被刷新的CPartClientProductRight
	virtual void afterUpdate(CPartClientProductRight *pPartClientProductRight);
	
	///删除前触发
	///@param	pPartClientProductRight	要删除的CPartClientProductRight
	virtual void beforeRemove(CPartClientProductRight *pPartClientProductRight);
	
	///确认加入后触发
	///@param	pPartClientProductRight	已经加入的PartClientProductRight
	virtual void commitAdd(CPartClientProductRight *pPartClientProductRight);

	///确认更新后触发
	///@param	pPartClientProductRight	被刷新的CPartClientProductRight
	///@param	poldPartClientProductRight	原来的值
	virtual void commitUpdate(CPartClientProductRight *pPartClientProductRight, CWriteablePartClientProductRight *pOldPartClientProductRight);
	
	///确认删除后触发
	///@param	pPartClientProductRight	已经删除的CPartClientProductRight
	virtual void commitRemove(CWriteablePartClientProductRight *pPartClientProductRight);

	///所有相关的触发器
	vector<CPartClientProductRightActionTrigger *> *pActionTriggers;
	vector<CPartClientProductRightCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteablePartClientProductRight compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientInstrumentRightFactory是一个会员客户合约交易权限的对象工厂。它包含了一批会员客户合约交易权限，
///同时又建立了如下索引，以方便查询：
///使用本对象工厂，可以完成对会员客户合约交易权限的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByParticipantAndClientAndInstrument，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientInstrumentRightFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CPartClientInstrumentRightFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxPartClientInstrumentRight，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CPartClientInstrumentRightFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CPartClientInstrumentRightFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的PartClientInstrumentRight
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的PartClientInstrumentRight，文件名将根据配置文件中的定义PartClientInstrumentRightCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的PartClientInstrumentRight
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的PartClientInstrumentRight，文件名将根据配置文件中的定义PartClientInstrumentRightCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CPartClientInstrumentRightResource;

	///将一个CPartClientInstrumentRight加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pPartClientInstrumentRight	要加入的PartClientInstrumentRight
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CPartClientInstrumentRight *add(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight, CTransaction *pTransaction=NULL);
	
	///刷新该CPartClientInstrumentRight的值
	///@param	pPartClientInstrumentRight	被刷新的CPartClientInstrumentRight
	///@param	pNewPartClientInstrumentRight	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CPartClientInstrumentRight *pPartClientInstrumentRight, CWriteablePartClientInstrumentRight *pNewPartClientInstrumentRight, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pPartClientInstrumentRight	  需要被刷新或者新增的CPartClientInstrumentRight,等于NULL表示是需要新增的
	///@param	pNewPartClientInstrumentRight	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CPartClientInstrumentRight* addOrUpdate(CPartClientInstrumentRight *pPartClientInstrumentRight, CWriteablePartClientInstrumentRight *pNewPartClientInstrumentRight, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CPartClientInstrumentRight，同时删除其索引
	///@param	pPartClientInstrumentRight	要删除的CPartClientInstrumentRight
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CPartClientInstrumentRight *pPartClientInstrumentRight, CTransaction *pTransaction=NULL);
	
	///获取某个CPartClientInstrumentRight
	///@param	pPartClientInstrumentRight	要读取的CPartClientInstrumentRight
	///@param	pTragetPartClientInstrumentRight	存放结果的CPartClientInstrumentRight
	void retrieve(CPartClientInstrumentRight *pPartClientInstrumentRight, CWriteablePartClientInstrumentRight *pTargetPartClientInstrumentRight);
	
	///获取第一个CPartClientInstrumentRight
	///@return	得到的第一个CPartClientInstrumentRight，如果没有，则返回NULL
	CPartClientInstrumentRight *getFirst(void);
	
	///获取下一个CPartClientInstrumentRight
	///@return	得到下一个CPartClientInstrumentRight，如果没有，则返回NULL
	CPartClientInstrumentRight *getNext(void);
	
	///结束获取CPartClientInstrumentRight
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CPartClientInstrumentRightActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CPartClientInstrumentRightActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CPartClientInstrumentRightCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CPartClientInstrumentRightCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CPartClientInstrumentRightIteratorBySettlementGroupID;

	///开始寻找CPartClientInstrumentRight
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CPartClientInstrumentRight，如果找不到，返回NULL
	CPartClientInstrumentRight *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CPartClientInstrumentRight，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CPartClientInstrumentRight，如果已经没有一个满足要求了，则返回NULL
	CPartClientInstrumentRight *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CPartClientInstrumentRight
	///@param	ParticipantID	会员编号
	///@param	ClientID	客户编号
	///@param	InstrumentID	合约代码
	///@return	找到的CPartClientInstrumentRight，如果找不到，返回NULL
	CPartClientInstrumentRight *findByParticipantAndClientAndInstrument( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyClientIDType&  ClientID,  const CReadOnlyInstrumentIDType&  InstrumentID);

	///根据主码寻找
	///@param	ParticipantID	会员编号
	///@param	ClientID	客户编号
	///@param	InstrumentID	合约代码
	///@return	找到的CPartClientInstrumentRight，如果找不到，返回NULL
	CPartClientInstrumentRight *findByPK( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyClientIDType&  ClientID,  const CReadOnlyInstrumentIDType&  InstrumentID);
	
	///根据主键寻找CPartClientInstrumentRight
	///@param	pPartClientInstrumentRight	要找的值
	///@return	找到的CPartClientInstrumentRight，如果找不到，返回NULL
	CPartClientInstrumentRight *findByPK(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight);

	///根据主键获取CPartClientInstrumentRight
	///@param	pPartClientInstrumentRight	要获取的值，同时用于存放返回的结果
	///@return	找到的CPartClientInstrumentRight，如果找不到，返回NULL
	bool retrieveByPK(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight);

	///根据主键增加新的CPartClientInstrumentRight
	///@param	pPartClientInstrumentRight	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	返回插入的CPartClientInstrumentRight，如果插入失败，则返回NULL
	CPartClientInstrumentRight *addByPK(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight, CTransaction *pTransaction=NULL);

	///根据主键更新CPartClientInstrumentRight的值
	///@param	pPartClientInstrumentRight	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	///@return	true表示成功，false表示失败
	bool updateByPK(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///根据主键删除CPartClientInstrumentRight
	///@param	pPartClientInstrumentRight	要删除的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	true表示成功，false表示失败
	bool removeByPK(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight, CTransaction *pTransaction=NULL);


private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CPartClientInstrumentRight加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pPartClientInstrumentRight	要加入的PartClientInstrumentRight
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CPartClientInstrumentRight *internalAdd(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight, bool bNoTransaction);
	
	
	///刷新该CPartClientInstrumentRight的键值
	///@param	pPartClientInstrumentRight	被刷新的CPartClientInstrumentRight
	///@param	pNewPartClientInstrumentRight	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CPartClientInstrumentRight *pPartClientInstrumentRight, CWriteablePartClientInstrumentRight *pNewPartClientInstrumentRight, bool updateIndex,bool bNoTransaction);
	
	///删除一个CPartClientInstrumentRight，同时删除其索引
	///@param	pPartClientInstrumentRight	要删除的CPartClientInstrumentRight
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CPartClientInstrumentRight *pPartClientInstrumentRight, bool bNoTransaction);
/*
	///检查某个CPartClientInstrumentRight是否属于本对象工厂
	///@param	pPartClientInstrumentRight	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CPartClientInstrumentRight *pPartClientInstrumentRight);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	
	///基于ParticipantAndClientAndInstrument的hash索引
	CHashIndex *pParticipantAndClientAndInstrumentHashIndex;
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CPartClientInstrumentRight *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pPartClientInstrumentRight	要加入的PartClientInstrumentRight
	virtual void beforeAdd(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight);
	
	///加入后触发
	///@param	pPartClientInstrumentRight	已经加入的PartClientInstrumentRight
	virtual void afterAdd(CPartClientInstrumentRight *pPartClientInstrumentRight);

	///更新前触发	
	///@param	pPartClientInstrumentRight	被刷新的CPartClientInstrumentRight
	///@param	pNewPartClientInstrumentRight	新的值
	virtual void beforeUpdate(CPartClientInstrumentRight *pPartClientInstrumentRight, CWriteablePartClientInstrumentRight *pNewPartClientInstrumentRight);
	
	///更新后触发
	///@param	pPartClientInstrumentRight	被刷新的CPartClientInstrumentRight
	virtual void afterUpdate(CPartClientInstrumentRight *pPartClientInstrumentRight);
	
	///删除前触发
	///@param	pPartClientInstrumentRight	要删除的CPartClientInstrumentRight
	virtual void beforeRemove(CPartClientInstrumentRight *pPartClientInstrumentRight);
	
	///确认加入后触发
	///@param	pPartClientInstrumentRight	已经加入的PartClientInstrumentRight
	virtual void commitAdd(CPartClientInstrumentRight *pPartClientInstrumentRight);

	///确认更新后触发
	///@param	pPartClientInstrumentRight	被刷新的CPartClientInstrumentRight
	///@param	poldPartClientInstrumentRight	原来的值
	virtual void commitUpdate(CPartClientInstrumentRight *pPartClientInstrumentRight, CWriteablePartClientInstrumentRight *pOldPartClientInstrumentRight);
	
	///确认删除后触发
	///@param	pPartClientInstrumentRight	已经删除的CPartClientInstrumentRight
	virtual void commitRemove(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight);

	///所有相关的触发器
	vector<CPartClientInstrumentRightActionTrigger *> *pActionTriggers;
	vector<CPartClientInstrumentRightCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteablePartClientInstrumentRight compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrProductPropertyFactory是一个产品属性的对象工厂。它包含了一批产品属性，
///同时又建立了如下索引，以方便查询：
///	ProductIDIndex
///使用本对象工厂，可以完成对产品属性的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByProductID，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrProductPropertyFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrProductPropertyFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxCurrProductProperty，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrProductPropertyFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CCurrProductPropertyFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的CurrProductProperty
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的CurrProductProperty，文件名将根据配置文件中的定义CurrProductPropertyCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的CurrProductProperty
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的CurrProductProperty，文件名将根据配置文件中的定义CurrProductPropertyCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CCurrProductPropertyResource;

	///将一个CCurrProductProperty加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrProductProperty	要加入的CurrProductProperty
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrProductProperty *add(CWriteableCurrProductProperty *pCurrProductProperty, CTransaction *pTransaction=NULL);
	
	///刷新该CCurrProductProperty的值
	///@param	pCurrProductProperty	被刷新的CCurrProductProperty
	///@param	pNewCurrProductProperty	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CCurrProductProperty *pCurrProductProperty, CWriteableCurrProductProperty *pNewCurrProductProperty, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pCurrProductProperty	  需要被刷新或者新增的CCurrProductProperty,等于NULL表示是需要新增的
	///@param	pNewCurrProductProperty	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CCurrProductProperty* addOrUpdate(CCurrProductProperty *pCurrProductProperty, CWriteableCurrProductProperty *pNewCurrProductProperty, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CCurrProductProperty，同时删除其索引
	///@param	pCurrProductProperty	要删除的CCurrProductProperty
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CCurrProductProperty *pCurrProductProperty, CTransaction *pTransaction=NULL);
	
	///获取某个CCurrProductProperty
	///@param	pCurrProductProperty	要读取的CCurrProductProperty
	///@param	pTragetCurrProductProperty	存放结果的CCurrProductProperty
	void retrieve(CCurrProductProperty *pCurrProductProperty, CWriteableCurrProductProperty *pTargetCurrProductProperty);
	
	///获取第一个CCurrProductProperty
	///@return	得到的第一个CCurrProductProperty，如果没有，则返回NULL
	CCurrProductProperty *getFirst(void);
	
	///获取下一个CCurrProductProperty
	///@return	得到下一个CCurrProductProperty，如果没有，则返回NULL
	CCurrProductProperty *getNext(void);
	
	///结束获取CCurrProductProperty
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CCurrProductPropertyActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CCurrProductPropertyActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CCurrProductPropertyCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CCurrProductPropertyCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CCurrProductPropertyIteratorBySettlementGroupID;

	///开始寻找CCurrProductProperty
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CCurrProductProperty，如果找不到，返回NULL
	CCurrProductProperty *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CCurrProductProperty，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrProductProperty，如果已经没有一个满足要求了，则返回NULL
	CCurrProductProperty *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CCurrProductProperty
	///@param	ProductID	产品编号
	///@return	找到的CCurrProductProperty，如果找不到，返回NULL
	CCurrProductProperty *findByProductID( const CReadOnlyProductIDType&  ProductID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CCurrProductProperty加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrProductProperty	要加入的CurrProductProperty
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrProductProperty *internalAdd(CWriteableCurrProductProperty *pCurrProductProperty, bool bNoTransaction);
	
	
	///刷新该CCurrProductProperty的键值
	///@param	pCurrProductProperty	被刷新的CCurrProductProperty
	///@param	pNewCurrProductProperty	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CCurrProductProperty *pCurrProductProperty, CWriteableCurrProductProperty *pNewCurrProductProperty, bool updateIndex,bool bNoTransaction);
	
	///删除一个CCurrProductProperty，同时删除其索引
	///@param	pCurrProductProperty	要删除的CCurrProductProperty
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CCurrProductProperty *pCurrProductProperty, bool bNoTransaction);
/*
	///检查某个CCurrProductProperty是否属于本对象工厂
	///@param	pCurrProductProperty	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CCurrProductProperty *pCurrProductProperty);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ProductID的索引
	CAVLTree *pProductIDIndex;
	
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CCurrProductProperty *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pCurrProductProperty	要加入的CurrProductProperty
	virtual void beforeAdd(CWriteableCurrProductProperty *pCurrProductProperty);
	
	///加入后触发
	///@param	pCurrProductProperty	已经加入的CurrProductProperty
	virtual void afterAdd(CCurrProductProperty *pCurrProductProperty);

	///更新前触发	
	///@param	pCurrProductProperty	被刷新的CCurrProductProperty
	///@param	pNewCurrProductProperty	新的值
	virtual void beforeUpdate(CCurrProductProperty *pCurrProductProperty, CWriteableCurrProductProperty *pNewCurrProductProperty);
	
	///更新后触发
	///@param	pCurrProductProperty	被刷新的CCurrProductProperty
	virtual void afterUpdate(CCurrProductProperty *pCurrProductProperty);
	
	///删除前触发
	///@param	pCurrProductProperty	要删除的CCurrProductProperty
	virtual void beforeRemove(CCurrProductProperty *pCurrProductProperty);
	
	///确认加入后触发
	///@param	pCurrProductProperty	已经加入的CurrProductProperty
	virtual void commitAdd(CCurrProductProperty *pCurrProductProperty);

	///确认更新后触发
	///@param	pCurrProductProperty	被刷新的CCurrProductProperty
	///@param	poldCurrProductProperty	原来的值
	virtual void commitUpdate(CCurrProductProperty *pCurrProductProperty, CWriteableCurrProductProperty *pOldCurrProductProperty);
	
	///确认删除后触发
	///@param	pCurrProductProperty	已经删除的CCurrProductProperty
	virtual void commitRemove(CWriteableCurrProductProperty *pCurrProductProperty);

	///所有相关的触发器
	vector<CCurrProductPropertyActionTrigger *> *pActionTriggers;
	vector<CCurrProductPropertyCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableCurrProductProperty compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentPropertyFactory是一个合约属性的对象工厂。它包含了一批合约属性，
///同时又建立了如下索引，以方便查询：
///	InstrumentIDIndex
///使用本对象工厂，可以完成对合约属性的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByInstrumentID，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentPropertyFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrInstrumentPropertyFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxCurrInstrumentProperty，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrInstrumentPropertyFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CCurrInstrumentPropertyFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的CurrInstrumentProperty
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的CurrInstrumentProperty，文件名将根据配置文件中的定义CurrInstrumentPropertyCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的CurrInstrumentProperty
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的CurrInstrumentProperty，文件名将根据配置文件中的定义CurrInstrumentPropertyCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CCurrInstrumentPropertyResource;

	///将一个CCurrInstrumentProperty加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrInstrumentProperty	要加入的CurrInstrumentProperty
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrInstrumentProperty *add(CWriteableCurrInstrumentProperty *pCurrInstrumentProperty, CTransaction *pTransaction=NULL);
	
	///刷新该CCurrInstrumentProperty的值
	///@param	pCurrInstrumentProperty	被刷新的CCurrInstrumentProperty
	///@param	pNewCurrInstrumentProperty	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CCurrInstrumentProperty *pCurrInstrumentProperty, CWriteableCurrInstrumentProperty *pNewCurrInstrumentProperty, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pCurrInstrumentProperty	  需要被刷新或者新增的CCurrInstrumentProperty,等于NULL表示是需要新增的
	///@param	pNewCurrInstrumentProperty	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CCurrInstrumentProperty* addOrUpdate(CCurrInstrumentProperty *pCurrInstrumentProperty, CWriteableCurrInstrumentProperty *pNewCurrInstrumentProperty, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CCurrInstrumentProperty，同时删除其索引
	///@param	pCurrInstrumentProperty	要删除的CCurrInstrumentProperty
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CCurrInstrumentProperty *pCurrInstrumentProperty, CTransaction *pTransaction=NULL);
	
	///获取某个CCurrInstrumentProperty
	///@param	pCurrInstrumentProperty	要读取的CCurrInstrumentProperty
	///@param	pTragetCurrInstrumentProperty	存放结果的CCurrInstrumentProperty
	void retrieve(CCurrInstrumentProperty *pCurrInstrumentProperty, CWriteableCurrInstrumentProperty *pTargetCurrInstrumentProperty);
	
	///获取第一个CCurrInstrumentProperty
	///@return	得到的第一个CCurrInstrumentProperty，如果没有，则返回NULL
	CCurrInstrumentProperty *getFirst(void);
	
	///获取下一个CCurrInstrumentProperty
	///@return	得到下一个CCurrInstrumentProperty，如果没有，则返回NULL
	CCurrInstrumentProperty *getNext(void);
	
	///结束获取CCurrInstrumentProperty
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CCurrInstrumentPropertyActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CCurrInstrumentPropertyActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CCurrInstrumentPropertyCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CCurrInstrumentPropertyCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CCurrInstrumentPropertyIteratorBySettlementGroupID;

	///开始寻找CCurrInstrumentProperty
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CCurrInstrumentProperty，如果找不到，返回NULL
	CCurrInstrumentProperty *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CCurrInstrumentProperty，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrInstrumentProperty，如果已经没有一个满足要求了，则返回NULL
	CCurrInstrumentProperty *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CCurrInstrumentProperty
	///@param	InstrumentID	合约代码
	///@return	找到的CCurrInstrumentProperty，如果找不到，返回NULL
	CCurrInstrumentProperty *findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CCurrInstrumentProperty加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrInstrumentProperty	要加入的CurrInstrumentProperty
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrInstrumentProperty *internalAdd(CWriteableCurrInstrumentProperty *pCurrInstrumentProperty, bool bNoTransaction);
	
	
	///刷新该CCurrInstrumentProperty的键值
	///@param	pCurrInstrumentProperty	被刷新的CCurrInstrumentProperty
	///@param	pNewCurrInstrumentProperty	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CCurrInstrumentProperty *pCurrInstrumentProperty, CWriteableCurrInstrumentProperty *pNewCurrInstrumentProperty, bool updateIndex,bool bNoTransaction);
	
	///删除一个CCurrInstrumentProperty，同时删除其索引
	///@param	pCurrInstrumentProperty	要删除的CCurrInstrumentProperty
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CCurrInstrumentProperty *pCurrInstrumentProperty, bool bNoTransaction);
/*
	///检查某个CCurrInstrumentProperty是否属于本对象工厂
	///@param	pCurrInstrumentProperty	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CCurrInstrumentProperty *pCurrInstrumentProperty);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于InstrumentID的索引
	CAVLTree *pInstrumentIDIndex;
	
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CCurrInstrumentProperty *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pCurrInstrumentProperty	要加入的CurrInstrumentProperty
	virtual void beforeAdd(CWriteableCurrInstrumentProperty *pCurrInstrumentProperty);
	
	///加入后触发
	///@param	pCurrInstrumentProperty	已经加入的CurrInstrumentProperty
	virtual void afterAdd(CCurrInstrumentProperty *pCurrInstrumentProperty);

	///更新前触发	
	///@param	pCurrInstrumentProperty	被刷新的CCurrInstrumentProperty
	///@param	pNewCurrInstrumentProperty	新的值
	virtual void beforeUpdate(CCurrInstrumentProperty *pCurrInstrumentProperty, CWriteableCurrInstrumentProperty *pNewCurrInstrumentProperty);
	
	///更新后触发
	///@param	pCurrInstrumentProperty	被刷新的CCurrInstrumentProperty
	virtual void afterUpdate(CCurrInstrumentProperty *pCurrInstrumentProperty);
	
	///删除前触发
	///@param	pCurrInstrumentProperty	要删除的CCurrInstrumentProperty
	virtual void beforeRemove(CCurrInstrumentProperty *pCurrInstrumentProperty);
	
	///确认加入后触发
	///@param	pCurrInstrumentProperty	已经加入的CurrInstrumentProperty
	virtual void commitAdd(CCurrInstrumentProperty *pCurrInstrumentProperty);

	///确认更新后触发
	///@param	pCurrInstrumentProperty	被刷新的CCurrInstrumentProperty
	///@param	poldCurrInstrumentProperty	原来的值
	virtual void commitUpdate(CCurrInstrumentProperty *pCurrInstrumentProperty, CWriteableCurrInstrumentProperty *pOldCurrInstrumentProperty);
	
	///确认删除后触发
	///@param	pCurrInstrumentProperty	已经删除的CCurrInstrumentProperty
	virtual void commitRemove(CWriteableCurrInstrumentProperty *pCurrInstrumentProperty);

	///所有相关的触发器
	vector<CCurrInstrumentPropertyActionTrigger *> *pActionTriggers;
	vector<CCurrInstrumentPropertyCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableCurrInstrumentProperty compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingFactory是一个当前价格绑定的对象工厂。它包含了一批当前价格绑定，
///同时又建立了如下索引，以方便查询：
///	InstrumentAndSegmentIndex
///使用本对象工厂，可以完成对当前价格绑定的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByInstrumentAndSegment，唯一找到对象
///		使用findByInstrumentAndOneSegment，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrPriceBandingFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxCurrPriceBanding，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrPriceBandingFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CCurrPriceBandingFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的CurrPriceBanding
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的CurrPriceBanding，文件名将根据配置文件中的定义CurrPriceBandingCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的CurrPriceBanding
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的CurrPriceBanding，文件名将根据配置文件中的定义CurrPriceBandingCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CCurrPriceBandingResource;

	///将一个CCurrPriceBanding加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrPriceBanding	要加入的CurrPriceBanding
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrPriceBanding *add(CWriteableCurrPriceBanding *pCurrPriceBanding, CTransaction *pTransaction=NULL);
	
	///刷新该CCurrPriceBanding的值
	///@param	pCurrPriceBanding	被刷新的CCurrPriceBanding
	///@param	pNewCurrPriceBanding	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CCurrPriceBanding *pCurrPriceBanding, CWriteableCurrPriceBanding *pNewCurrPriceBanding, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pCurrPriceBanding	  需要被刷新或者新增的CCurrPriceBanding,等于NULL表示是需要新增的
	///@param	pNewCurrPriceBanding	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CCurrPriceBanding* addOrUpdate(CCurrPriceBanding *pCurrPriceBanding, CWriteableCurrPriceBanding *pNewCurrPriceBanding, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CCurrPriceBanding，同时删除其索引
	///@param	pCurrPriceBanding	要删除的CCurrPriceBanding
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CCurrPriceBanding *pCurrPriceBanding, CTransaction *pTransaction=NULL);
	
	///获取某个CCurrPriceBanding
	///@param	pCurrPriceBanding	要读取的CCurrPriceBanding
	///@param	pTragetCurrPriceBanding	存放结果的CCurrPriceBanding
	void retrieve(CCurrPriceBanding *pCurrPriceBanding, CWriteableCurrPriceBanding *pTargetCurrPriceBanding);
	
	///获取第一个CCurrPriceBanding
	///@return	得到的第一个CCurrPriceBanding，如果没有，则返回NULL
	CCurrPriceBanding *getFirst(void);
	
	///获取下一个CCurrPriceBanding
	///@return	得到下一个CCurrPriceBanding，如果没有，则返回NULL
	CCurrPriceBanding *getNext(void);
	
	///结束获取CCurrPriceBanding
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CCurrPriceBandingActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CCurrPriceBandingActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CCurrPriceBandingCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CCurrPriceBandingCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CCurrPriceBandingIteratorBySettlementGroupID;

	///开始寻找CCurrPriceBanding
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CCurrPriceBanding，如果找不到，返回NULL
	CCurrPriceBanding *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CCurrPriceBanding，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrPriceBanding，如果已经没有一个满足要求了，则返回NULL
	CCurrPriceBanding *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CCurrPriceBanding
	///@param	InstrumentID	合约代码
	///@param	TradingSegmentSN	交易阶段编号
	///@return	找到的CCurrPriceBanding，如果找不到，返回NULL
	CCurrPriceBanding *findByInstrumentAndSegment( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyTradingSegmentSNType&  TradingSegmentSN);



	///寻找CCurrPriceBanding
	///@param	InstrumentID	合约代码
	///@param	TradingSegmentSN	交易阶段编号
	///@return	找到的CCurrPriceBanding，如果找不到，返回NULL
	CCurrPriceBanding *findByInstrumentAndOneSegment( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyTradingSegmentSNType&  TradingSegmentSN);

	///根据主码寻找
	///@param	InstrumentID	合约代码
	///@param	TradingSegmentSN	交易阶段编号
	///@return	找到的CCurrPriceBanding，如果找不到，返回NULL
	CCurrPriceBanding *findByPK( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyTradingSegmentSNType&  TradingSegmentSN);
	
	///根据主键寻找CCurrPriceBanding
	///@param	pCurrPriceBanding	要找的值
	///@return	找到的CCurrPriceBanding，如果找不到，返回NULL
	CCurrPriceBanding *findByPK(CWriteableCurrPriceBanding *pCurrPriceBanding);

	///根据主键获取CCurrPriceBanding
	///@param	pCurrPriceBanding	要获取的值，同时用于存放返回的结果
	///@return	找到的CCurrPriceBanding，如果找不到，返回NULL
	bool retrieveByPK(CWriteableCurrPriceBanding *pCurrPriceBanding);

	///根据主键增加新的CCurrPriceBanding
	///@param	pCurrPriceBanding	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	返回插入的CCurrPriceBanding，如果插入失败，则返回NULL
	CCurrPriceBanding *addByPK(CWriteableCurrPriceBanding *pCurrPriceBanding, CTransaction *pTransaction=NULL);

	///根据主键更新CCurrPriceBanding的值
	///@param	pCurrPriceBanding	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	///@return	true表示成功，false表示失败
	bool updateByPK(CWriteableCurrPriceBanding *pCurrPriceBanding, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///根据主键删除CCurrPriceBanding
	///@param	pCurrPriceBanding	要删除的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	true表示成功，false表示失败
	bool removeByPK(CWriteableCurrPriceBanding *pCurrPriceBanding, CTransaction *pTransaction=NULL);


private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CCurrPriceBanding加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrPriceBanding	要加入的CurrPriceBanding
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrPriceBanding *internalAdd(CWriteableCurrPriceBanding *pCurrPriceBanding, bool bNoTransaction);
	
	
	///刷新该CCurrPriceBanding的键值
	///@param	pCurrPriceBanding	被刷新的CCurrPriceBanding
	///@param	pNewCurrPriceBanding	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CCurrPriceBanding *pCurrPriceBanding, CWriteableCurrPriceBanding *pNewCurrPriceBanding, bool updateIndex,bool bNoTransaction);
	
	///删除一个CCurrPriceBanding，同时删除其索引
	///@param	pCurrPriceBanding	要删除的CCurrPriceBanding
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CCurrPriceBanding *pCurrPriceBanding, bool bNoTransaction);
/*
	///检查某个CCurrPriceBanding是否属于本对象工厂
	///@param	pCurrPriceBanding	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CCurrPriceBanding *pCurrPriceBanding);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于InstrumentID+TradingSegmentSN的索引
	CAVLTree *pInstrumentAndSegmentIndex;
	
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CCurrPriceBanding *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pCurrPriceBanding	要加入的CurrPriceBanding
	virtual void beforeAdd(CWriteableCurrPriceBanding *pCurrPriceBanding);
	
	///加入后触发
	///@param	pCurrPriceBanding	已经加入的CurrPriceBanding
	virtual void afterAdd(CCurrPriceBanding *pCurrPriceBanding);

	///更新前触发	
	///@param	pCurrPriceBanding	被刷新的CCurrPriceBanding
	///@param	pNewCurrPriceBanding	新的值
	virtual void beforeUpdate(CCurrPriceBanding *pCurrPriceBanding, CWriteableCurrPriceBanding *pNewCurrPriceBanding);
	
	///更新后触发
	///@param	pCurrPriceBanding	被刷新的CCurrPriceBanding
	virtual void afterUpdate(CCurrPriceBanding *pCurrPriceBanding);
	
	///删除前触发
	///@param	pCurrPriceBanding	要删除的CCurrPriceBanding
	virtual void beforeRemove(CCurrPriceBanding *pCurrPriceBanding);
	
	///确认加入后触发
	///@param	pCurrPriceBanding	已经加入的CurrPriceBanding
	virtual void commitAdd(CCurrPriceBanding *pCurrPriceBanding);

	///确认更新后触发
	///@param	pCurrPriceBanding	被刷新的CCurrPriceBanding
	///@param	poldCurrPriceBanding	原来的值
	virtual void commitUpdate(CCurrPriceBanding *pCurrPriceBanding, CWriteableCurrPriceBanding *pOldCurrPriceBanding);
	
	///确认删除后触发
	///@param	pCurrPriceBanding	已经删除的CCurrPriceBanding
	virtual void commitRemove(CWriteableCurrPriceBanding *pCurrPriceBanding);

	///所有相关的触发器
	vector<CCurrPriceBandingActionTrigger *> *pActionTriggers;
	vector<CCurrPriceBandingCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableCurrPriceBanding compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateFactory是一个当天合约保证金率的对象工厂。它包含了一批当天合约保证金率，
///同时又建立了如下索引，以方便查询：
///使用本对象工厂，可以完成对当天合约保证金率的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByInstrumentAndPart，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrMarginRateFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxCurrMarginRate，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrMarginRateFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CCurrMarginRateFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的CurrMarginRate
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的CurrMarginRate，文件名将根据配置文件中的定义CurrMarginRateCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的CurrMarginRate
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的CurrMarginRate，文件名将根据配置文件中的定义CurrMarginRateCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CCurrMarginRateResource;

	///将一个CCurrMarginRate加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrMarginRate	要加入的CurrMarginRate
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrMarginRate *add(CWriteableCurrMarginRate *pCurrMarginRate, CTransaction *pTransaction=NULL);
	
	///刷新该CCurrMarginRate的值
	///@param	pCurrMarginRate	被刷新的CCurrMarginRate
	///@param	pNewCurrMarginRate	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CCurrMarginRate *pCurrMarginRate, CWriteableCurrMarginRate *pNewCurrMarginRate, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pCurrMarginRate	  需要被刷新或者新增的CCurrMarginRate,等于NULL表示是需要新增的
	///@param	pNewCurrMarginRate	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CCurrMarginRate* addOrUpdate(CCurrMarginRate *pCurrMarginRate, CWriteableCurrMarginRate *pNewCurrMarginRate, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CCurrMarginRate，同时删除其索引
	///@param	pCurrMarginRate	要删除的CCurrMarginRate
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CCurrMarginRate *pCurrMarginRate, CTransaction *pTransaction=NULL);
	
	///获取某个CCurrMarginRate
	///@param	pCurrMarginRate	要读取的CCurrMarginRate
	///@param	pTragetCurrMarginRate	存放结果的CCurrMarginRate
	void retrieve(CCurrMarginRate *pCurrMarginRate, CWriteableCurrMarginRate *pTargetCurrMarginRate);
	
	///获取第一个CCurrMarginRate
	///@return	得到的第一个CCurrMarginRate，如果没有，则返回NULL
	CCurrMarginRate *getFirst(void);
	
	///获取下一个CCurrMarginRate
	///@return	得到下一个CCurrMarginRate，如果没有，则返回NULL
	CCurrMarginRate *getNext(void);
	
	///结束获取CCurrMarginRate
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CCurrMarginRateActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CCurrMarginRateActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CCurrMarginRateCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CCurrMarginRateCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CCurrMarginRateIteratorBySettlementGroupID;

	///开始寻找CCurrMarginRate
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CCurrMarginRate，如果找不到，返回NULL
	CCurrMarginRate *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CCurrMarginRate，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrMarginRate，如果已经没有一个满足要求了，则返回NULL
	CCurrMarginRate *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CCurrMarginRate
	///@param	InstrumentID	合约代码
	///@param	ParticipantID	会员代码
	///@return	找到的CCurrMarginRate，如果找不到，返回NULL
	CCurrMarginRate *findByInstrumentAndPart( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CCurrMarginRate加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrMarginRate	要加入的CurrMarginRate
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrMarginRate *internalAdd(CWriteableCurrMarginRate *pCurrMarginRate, bool bNoTransaction);
	
	
	///刷新该CCurrMarginRate的键值
	///@param	pCurrMarginRate	被刷新的CCurrMarginRate
	///@param	pNewCurrMarginRate	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CCurrMarginRate *pCurrMarginRate, CWriteableCurrMarginRate *pNewCurrMarginRate, bool updateIndex,bool bNoTransaction);
	
	///删除一个CCurrMarginRate，同时删除其索引
	///@param	pCurrMarginRate	要删除的CCurrMarginRate
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CCurrMarginRate *pCurrMarginRate, bool bNoTransaction);
/*
	///检查某个CCurrMarginRate是否属于本对象工厂
	///@param	pCurrMarginRate	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CCurrMarginRate *pCurrMarginRate);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CCurrMarginRate *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pCurrMarginRate	要加入的CurrMarginRate
	virtual void beforeAdd(CWriteableCurrMarginRate *pCurrMarginRate);
	
	///加入后触发
	///@param	pCurrMarginRate	已经加入的CurrMarginRate
	virtual void afterAdd(CCurrMarginRate *pCurrMarginRate);

	///更新前触发	
	///@param	pCurrMarginRate	被刷新的CCurrMarginRate
	///@param	pNewCurrMarginRate	新的值
	virtual void beforeUpdate(CCurrMarginRate *pCurrMarginRate, CWriteableCurrMarginRate *pNewCurrMarginRate);
	
	///更新后触发
	///@param	pCurrMarginRate	被刷新的CCurrMarginRate
	virtual void afterUpdate(CCurrMarginRate *pCurrMarginRate);
	
	///删除前触发
	///@param	pCurrMarginRate	要删除的CCurrMarginRate
	virtual void beforeRemove(CCurrMarginRate *pCurrMarginRate);
	
	///确认加入后触发
	///@param	pCurrMarginRate	已经加入的CurrMarginRate
	virtual void commitAdd(CCurrMarginRate *pCurrMarginRate);

	///确认更新后触发
	///@param	pCurrMarginRate	被刷新的CCurrMarginRate
	///@param	poldCurrMarginRate	原来的值
	virtual void commitUpdate(CCurrMarginRate *pCurrMarginRate, CWriteableCurrMarginRate *pOldCurrMarginRate);
	
	///确认删除后触发
	///@param	pCurrMarginRate	已经删除的CCurrMarginRate
	virtual void commitRemove(CWriteableCurrMarginRate *pCurrMarginRate);

	///所有相关的触发器
	vector<CCurrMarginRateActionTrigger *> *pActionTriggers;
	vector<CCurrMarginRateCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableCurrMarginRate compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDetailFactory是一个当天合约保证金率的详细内容的对象工厂。它包含了一批当天合约保证金率的详细内容，
///同时又建立了如下索引，以方便查询：
///使用本对象工厂，可以完成对当天合约保证金率的详细内容的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByInstrumentAndParticipant，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDetailFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrMarginRateDetailFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxCurrMarginRateDetail，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrMarginRateDetailFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CCurrMarginRateDetailFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的CurrMarginRateDetail
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的CurrMarginRateDetail，文件名将根据配置文件中的定义CurrMarginRateDetailCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的CurrMarginRateDetail
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的CurrMarginRateDetail，文件名将根据配置文件中的定义CurrMarginRateDetailCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CCurrMarginRateDetailResource;

	///将一个CCurrMarginRateDetail加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrMarginRateDetail	要加入的CurrMarginRateDetail
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrMarginRateDetail *add(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail, CTransaction *pTransaction=NULL);
	
	///刷新该CCurrMarginRateDetail的值
	///@param	pCurrMarginRateDetail	被刷新的CCurrMarginRateDetail
	///@param	pNewCurrMarginRateDetail	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CCurrMarginRateDetail *pCurrMarginRateDetail, CWriteableCurrMarginRateDetail *pNewCurrMarginRateDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pCurrMarginRateDetail	  需要被刷新或者新增的CCurrMarginRateDetail,等于NULL表示是需要新增的
	///@param	pNewCurrMarginRateDetail	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CCurrMarginRateDetail* addOrUpdate(CCurrMarginRateDetail *pCurrMarginRateDetail, CWriteableCurrMarginRateDetail *pNewCurrMarginRateDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CCurrMarginRateDetail，同时删除其索引
	///@param	pCurrMarginRateDetail	要删除的CCurrMarginRateDetail
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CCurrMarginRateDetail *pCurrMarginRateDetail, CTransaction *pTransaction=NULL);
	
	///获取某个CCurrMarginRateDetail
	///@param	pCurrMarginRateDetail	要读取的CCurrMarginRateDetail
	///@param	pTragetCurrMarginRateDetail	存放结果的CCurrMarginRateDetail
	void retrieve(CCurrMarginRateDetail *pCurrMarginRateDetail, CWriteableCurrMarginRateDetail *pTargetCurrMarginRateDetail);
	
	///获取第一个CCurrMarginRateDetail
	///@return	得到的第一个CCurrMarginRateDetail，如果没有，则返回NULL
	CCurrMarginRateDetail *getFirst(void);
	
	///获取下一个CCurrMarginRateDetail
	///@return	得到下一个CCurrMarginRateDetail，如果没有，则返回NULL
	CCurrMarginRateDetail *getNext(void);
	
	///结束获取CCurrMarginRateDetail
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CCurrMarginRateDetailActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CCurrMarginRateDetailActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CCurrMarginRateDetailCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CCurrMarginRateDetailCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CCurrMarginRateDetailIteratorBySettlementGroupID;

	///开始寻找CCurrMarginRateDetail
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CCurrMarginRateDetail，如果找不到，返回NULL
	CCurrMarginRateDetail *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CCurrMarginRateDetail，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrMarginRateDetail，如果已经没有一个满足要求了，则返回NULL
	CCurrMarginRateDetail *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CCurrMarginRateDetail
	///@param	InstrumentID	合约代码
	///@param	ParticipantID	会员编号
	///@param	TradingRole	交易角色
	///@param	HedgeFlag	投机套保标志
	///@return	找到的CCurrMarginRateDetail，如果找不到，返回NULL
	CCurrMarginRateDetail *findByInstrumentAndParticipant( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyTradingRoleType&  TradingRole,  const CReadOnlyHedgeFlagType&  HedgeFlag);

	///根据主码寻找
	///@param	InstrumentID	合约代码
	///@param	ParticipantID	会员编号
	///@param	TradingRole	交易角色
	///@param	HedgeFlag	投机套保标志
	///@return	找到的CCurrMarginRateDetail，如果找不到，返回NULL
	CCurrMarginRateDetail *findByPK( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyTradingRoleType&  TradingRole,  const CReadOnlyHedgeFlagType&  HedgeFlag);
	
	///根据主键寻找CCurrMarginRateDetail
	///@param	pCurrMarginRateDetail	要找的值
	///@return	找到的CCurrMarginRateDetail，如果找不到，返回NULL
	CCurrMarginRateDetail *findByPK(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail);

	///根据主键获取CCurrMarginRateDetail
	///@param	pCurrMarginRateDetail	要获取的值，同时用于存放返回的结果
	///@return	找到的CCurrMarginRateDetail，如果找不到，返回NULL
	bool retrieveByPK(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail);

	///根据主键增加新的CCurrMarginRateDetail
	///@param	pCurrMarginRateDetail	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	返回插入的CCurrMarginRateDetail，如果插入失败，则返回NULL
	CCurrMarginRateDetail *addByPK(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail, CTransaction *pTransaction=NULL);

	///根据主键更新CCurrMarginRateDetail的值
	///@param	pCurrMarginRateDetail	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	///@return	true表示成功，false表示失败
	bool updateByPK(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///根据主键删除CCurrMarginRateDetail
	///@param	pCurrMarginRateDetail	要删除的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	true表示成功，false表示失败
	bool removeByPK(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail, CTransaction *pTransaction=NULL);


private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CCurrMarginRateDetail加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrMarginRateDetail	要加入的CurrMarginRateDetail
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrMarginRateDetail *internalAdd(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail, bool bNoTransaction);
	
	
	///刷新该CCurrMarginRateDetail的键值
	///@param	pCurrMarginRateDetail	被刷新的CCurrMarginRateDetail
	///@param	pNewCurrMarginRateDetail	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CCurrMarginRateDetail *pCurrMarginRateDetail, CWriteableCurrMarginRateDetail *pNewCurrMarginRateDetail, bool updateIndex,bool bNoTransaction);
	
	///删除一个CCurrMarginRateDetail，同时删除其索引
	///@param	pCurrMarginRateDetail	要删除的CCurrMarginRateDetail
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CCurrMarginRateDetail *pCurrMarginRateDetail, bool bNoTransaction);
/*
	///检查某个CCurrMarginRateDetail是否属于本对象工厂
	///@param	pCurrMarginRateDetail	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CCurrMarginRateDetail *pCurrMarginRateDetail);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	
	///基于InstrumentAndParticipant的hash索引
	CHashIndex *pInstrumentAndParticipantHashIndex;
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CCurrMarginRateDetail *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pCurrMarginRateDetail	要加入的CurrMarginRateDetail
	virtual void beforeAdd(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail);
	
	///加入后触发
	///@param	pCurrMarginRateDetail	已经加入的CurrMarginRateDetail
	virtual void afterAdd(CCurrMarginRateDetail *pCurrMarginRateDetail);

	///更新前触发	
	///@param	pCurrMarginRateDetail	被刷新的CCurrMarginRateDetail
	///@param	pNewCurrMarginRateDetail	新的值
	virtual void beforeUpdate(CCurrMarginRateDetail *pCurrMarginRateDetail, CWriteableCurrMarginRateDetail *pNewCurrMarginRateDetail);
	
	///更新后触发
	///@param	pCurrMarginRateDetail	被刷新的CCurrMarginRateDetail
	virtual void afterUpdate(CCurrMarginRateDetail *pCurrMarginRateDetail);
	
	///删除前触发
	///@param	pCurrMarginRateDetail	要删除的CCurrMarginRateDetail
	virtual void beforeRemove(CCurrMarginRateDetail *pCurrMarginRateDetail);
	
	///确认加入后触发
	///@param	pCurrMarginRateDetail	已经加入的CurrMarginRateDetail
	virtual void commitAdd(CCurrMarginRateDetail *pCurrMarginRateDetail);

	///确认更新后触发
	///@param	pCurrMarginRateDetail	被刷新的CCurrMarginRateDetail
	///@param	poldCurrMarginRateDetail	原来的值
	virtual void commitUpdate(CCurrMarginRateDetail *pCurrMarginRateDetail, CWriteableCurrMarginRateDetail *pOldCurrMarginRateDetail);
	
	///确认删除后触发
	///@param	pCurrMarginRateDetail	已经删除的CCurrMarginRateDetail
	virtual void commitRemove(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail);

	///所有相关的触发器
	vector<CCurrMarginRateDetailActionTrigger *> *pActionTriggers;
	vector<CCurrMarginRateDetailCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableCurrMarginRateDetail compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitFactory是一个当前会员合约限仓的对象工厂。它包含了一批当前会员合约限仓，
///同时又建立了如下索引，以方便查询：
///使用本对象工厂，可以完成对当前会员合约限仓的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByInstrumentAndPart，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrPartPosiLimitFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxCurrPartPosiLimit，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrPartPosiLimitFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CCurrPartPosiLimitFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的CurrPartPosiLimit
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的CurrPartPosiLimit，文件名将根据配置文件中的定义CurrPartPosiLimitCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的CurrPartPosiLimit
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的CurrPartPosiLimit，文件名将根据配置文件中的定义CurrPartPosiLimitCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CCurrPartPosiLimitResource;

	///将一个CCurrPartPosiLimit加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrPartPosiLimit	要加入的CurrPartPosiLimit
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrPartPosiLimit *add(CWriteableCurrPartPosiLimit *pCurrPartPosiLimit, CTransaction *pTransaction=NULL);
	
	///刷新该CCurrPartPosiLimit的值
	///@param	pCurrPartPosiLimit	被刷新的CCurrPartPosiLimit
	///@param	pNewCurrPartPosiLimit	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CCurrPartPosiLimit *pCurrPartPosiLimit, CWriteableCurrPartPosiLimit *pNewCurrPartPosiLimit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pCurrPartPosiLimit	  需要被刷新或者新增的CCurrPartPosiLimit,等于NULL表示是需要新增的
	///@param	pNewCurrPartPosiLimit	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CCurrPartPosiLimit* addOrUpdate(CCurrPartPosiLimit *pCurrPartPosiLimit, CWriteableCurrPartPosiLimit *pNewCurrPartPosiLimit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CCurrPartPosiLimit，同时删除其索引
	///@param	pCurrPartPosiLimit	要删除的CCurrPartPosiLimit
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CCurrPartPosiLimit *pCurrPartPosiLimit, CTransaction *pTransaction=NULL);
	
	///获取某个CCurrPartPosiLimit
	///@param	pCurrPartPosiLimit	要读取的CCurrPartPosiLimit
	///@param	pTragetCurrPartPosiLimit	存放结果的CCurrPartPosiLimit
	void retrieve(CCurrPartPosiLimit *pCurrPartPosiLimit, CWriteableCurrPartPosiLimit *pTargetCurrPartPosiLimit);
	
	///获取第一个CCurrPartPosiLimit
	///@return	得到的第一个CCurrPartPosiLimit，如果没有，则返回NULL
	CCurrPartPosiLimit *getFirst(void);
	
	///获取下一个CCurrPartPosiLimit
	///@return	得到下一个CCurrPartPosiLimit，如果没有，则返回NULL
	CCurrPartPosiLimit *getNext(void);
	
	///结束获取CCurrPartPosiLimit
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CCurrPartPosiLimitActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CCurrPartPosiLimitActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CCurrPartPosiLimitCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CCurrPartPosiLimitCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CCurrPartPosiLimitIteratorBySettlementGroupID;

	///开始寻找CCurrPartPosiLimit
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CCurrPartPosiLimit，如果找不到，返回NULL
	CCurrPartPosiLimit *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CCurrPartPosiLimit，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrPartPosiLimit，如果已经没有一个满足要求了，则返回NULL
	CCurrPartPosiLimit *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CCurrPartPosiLimit
	///@param	InstrumentID	合约代码
	///@param	ParticipantID	会员代码
	///@return	找到的CCurrPartPosiLimit，如果找不到，返回NULL
	CCurrPartPosiLimit *findByInstrumentAndPart( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CCurrPartPosiLimit加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrPartPosiLimit	要加入的CurrPartPosiLimit
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrPartPosiLimit *internalAdd(CWriteableCurrPartPosiLimit *pCurrPartPosiLimit, bool bNoTransaction);
	
	
	///刷新该CCurrPartPosiLimit的键值
	///@param	pCurrPartPosiLimit	被刷新的CCurrPartPosiLimit
	///@param	pNewCurrPartPosiLimit	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CCurrPartPosiLimit *pCurrPartPosiLimit, CWriteableCurrPartPosiLimit *pNewCurrPartPosiLimit, bool updateIndex,bool bNoTransaction);
	
	///删除一个CCurrPartPosiLimit，同时删除其索引
	///@param	pCurrPartPosiLimit	要删除的CCurrPartPosiLimit
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CCurrPartPosiLimit *pCurrPartPosiLimit, bool bNoTransaction);
/*
	///检查某个CCurrPartPosiLimit是否属于本对象工厂
	///@param	pCurrPartPosiLimit	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CCurrPartPosiLimit *pCurrPartPosiLimit);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CCurrPartPosiLimit *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pCurrPartPosiLimit	要加入的CurrPartPosiLimit
	virtual void beforeAdd(CWriteableCurrPartPosiLimit *pCurrPartPosiLimit);
	
	///加入后触发
	///@param	pCurrPartPosiLimit	已经加入的CurrPartPosiLimit
	virtual void afterAdd(CCurrPartPosiLimit *pCurrPartPosiLimit);

	///更新前触发	
	///@param	pCurrPartPosiLimit	被刷新的CCurrPartPosiLimit
	///@param	pNewCurrPartPosiLimit	新的值
	virtual void beforeUpdate(CCurrPartPosiLimit *pCurrPartPosiLimit, CWriteableCurrPartPosiLimit *pNewCurrPartPosiLimit);
	
	///更新后触发
	///@param	pCurrPartPosiLimit	被刷新的CCurrPartPosiLimit
	virtual void afterUpdate(CCurrPartPosiLimit *pCurrPartPosiLimit);
	
	///删除前触发
	///@param	pCurrPartPosiLimit	要删除的CCurrPartPosiLimit
	virtual void beforeRemove(CCurrPartPosiLimit *pCurrPartPosiLimit);
	
	///确认加入后触发
	///@param	pCurrPartPosiLimit	已经加入的CurrPartPosiLimit
	virtual void commitAdd(CCurrPartPosiLimit *pCurrPartPosiLimit);

	///确认更新后触发
	///@param	pCurrPartPosiLimit	被刷新的CCurrPartPosiLimit
	///@param	poldCurrPartPosiLimit	原来的值
	virtual void commitUpdate(CCurrPartPosiLimit *pCurrPartPosiLimit, CWriteableCurrPartPosiLimit *pOldCurrPartPosiLimit);
	
	///确认删除后触发
	///@param	pCurrPartPosiLimit	已经删除的CCurrPartPosiLimit
	virtual void commitRemove(CWriteableCurrPartPosiLimit *pCurrPartPosiLimit);

	///所有相关的触发器
	vector<CCurrPartPosiLimitActionTrigger *> *pActionTriggers;
	vector<CCurrPartPosiLimitCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableCurrPartPosiLimit compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDetailFactory是一个当前会员合约限仓的详细内容的对象工厂。它包含了一批当前会员合约限仓的详细内容，
///同时又建立了如下索引，以方便查询：
///	InstrumentAndPartIndex
///使用本对象工厂，可以完成对当前会员合约限仓的详细内容的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByInstrumentAndPart，唯一找到对象
///		使用findByInstrumentPartAndStartPosition，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDetailFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrPartPosiLimitDetailFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxCurrPartPosiLimitDetail，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrPartPosiLimitDetailFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CCurrPartPosiLimitDetailFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的CurrPartPosiLimitDetail
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的CurrPartPosiLimitDetail，文件名将根据配置文件中的定义CurrPartPosiLimitDetailCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的CurrPartPosiLimitDetail
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的CurrPartPosiLimitDetail，文件名将根据配置文件中的定义CurrPartPosiLimitDetailCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CCurrPartPosiLimitDetailResource;

	///将一个CCurrPartPosiLimitDetail加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrPartPosiLimitDetail	要加入的CurrPartPosiLimitDetail
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrPartPosiLimitDetail *add(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CTransaction *pTransaction=NULL);
	
	///刷新该CCurrPartPosiLimitDetail的值
	///@param	pCurrPartPosiLimitDetail	被刷新的CCurrPartPosiLimitDetail
	///@param	pNewCurrPartPosiLimitDetail	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CWriteableCurrPartPosiLimitDetail *pNewCurrPartPosiLimitDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pCurrPartPosiLimitDetail	  需要被刷新或者新增的CCurrPartPosiLimitDetail,等于NULL表示是需要新增的
	///@param	pNewCurrPartPosiLimitDetail	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CCurrPartPosiLimitDetail* addOrUpdate(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CWriteableCurrPartPosiLimitDetail *pNewCurrPartPosiLimitDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CCurrPartPosiLimitDetail，同时删除其索引
	///@param	pCurrPartPosiLimitDetail	要删除的CCurrPartPosiLimitDetail
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CTransaction *pTransaction=NULL);
	
	///获取某个CCurrPartPosiLimitDetail
	///@param	pCurrPartPosiLimitDetail	要读取的CCurrPartPosiLimitDetail
	///@param	pTragetCurrPartPosiLimitDetail	存放结果的CCurrPartPosiLimitDetail
	void retrieve(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CWriteableCurrPartPosiLimitDetail *pTargetCurrPartPosiLimitDetail);
	
	///获取第一个CCurrPartPosiLimitDetail
	///@return	得到的第一个CCurrPartPosiLimitDetail，如果没有，则返回NULL
	CCurrPartPosiLimitDetail *getFirst(void);
	
	///获取下一个CCurrPartPosiLimitDetail
	///@return	得到下一个CCurrPartPosiLimitDetail，如果没有，则返回NULL
	CCurrPartPosiLimitDetail *getNext(void);
	
	///结束获取CCurrPartPosiLimitDetail
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CCurrPartPosiLimitDetailActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CCurrPartPosiLimitDetailActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CCurrPartPosiLimitDetailCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CCurrPartPosiLimitDetailCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CCurrPartPosiLimitDetailIteratorBySettlementGroupID;

	///开始寻找CCurrPartPosiLimitDetail
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CCurrPartPosiLimitDetail，如果找不到，返回NULL
	CCurrPartPosiLimitDetail *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CCurrPartPosiLimitDetail，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrPartPosiLimitDetail，如果已经没有一个满足要求了，则返回NULL
	CCurrPartPosiLimitDetail *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CCurrPartPosiLimitDetail
	///@param	InstrumentID	客户编号
	///@param	ParticipantID	会员编号
	///@param	TradingRole	交易角色
	///@param	StartTotalPosition	起始总持仓
	///@return	找到的CCurrPartPosiLimitDetail，如果找不到，返回NULL
	CCurrPartPosiLimitDetail *findByInstrumentAndPart( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyPositionTradingRoleType&  TradingRole,  const CReadOnlyLargeVolumeType&  StartTotalPosition);



	///寻找CCurrPartPosiLimitDetail
	///@param	InstrumentID	客户编号
	///@param	ParticipantID	会员编号
	///@param	TradingRole	交易角色
	///@param	StartTotalPosition	起始总持仓
	///@return	找到的CCurrPartPosiLimitDetail，如果找不到，返回NULL
	CCurrPartPosiLimitDetail *findByInstrumentPartAndStartPosition( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyPositionTradingRoleType&  TradingRole,  const CReadOnlyLargeVolumeType&  StartTotalPosition);

	///根据主码寻找
	///@param	InstrumentID	客户编号
	///@param	ParticipantID	会员编号
	///@param	TradingRole	交易角色
	///@param	StartTotalPosition	起始总持仓
	///@return	找到的CCurrPartPosiLimitDetail，如果找不到，返回NULL
	CCurrPartPosiLimitDetail *findByPK( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyPositionTradingRoleType&  TradingRole,  const CReadOnlyLargeVolumeType&  StartTotalPosition);
	
	///根据主键寻找CCurrPartPosiLimitDetail
	///@param	pCurrPartPosiLimitDetail	要找的值
	///@return	找到的CCurrPartPosiLimitDetail，如果找不到，返回NULL
	CCurrPartPosiLimitDetail *findByPK(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail);

	///根据主键获取CCurrPartPosiLimitDetail
	///@param	pCurrPartPosiLimitDetail	要获取的值，同时用于存放返回的结果
	///@return	找到的CCurrPartPosiLimitDetail，如果找不到，返回NULL
	bool retrieveByPK(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail);

	///根据主键增加新的CCurrPartPosiLimitDetail
	///@param	pCurrPartPosiLimitDetail	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	返回插入的CCurrPartPosiLimitDetail，如果插入失败，则返回NULL
	CCurrPartPosiLimitDetail *addByPK(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CTransaction *pTransaction=NULL);

	///根据主键更新CCurrPartPosiLimitDetail的值
	///@param	pCurrPartPosiLimitDetail	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	///@return	true表示成功，false表示失败
	bool updateByPK(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///根据主键删除CCurrPartPosiLimitDetail
	///@param	pCurrPartPosiLimitDetail	要删除的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	true表示成功，false表示失败
	bool removeByPK(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CTransaction *pTransaction=NULL);


private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CCurrPartPosiLimitDetail加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrPartPosiLimitDetail	要加入的CurrPartPosiLimitDetail
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrPartPosiLimitDetail *internalAdd(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, bool bNoTransaction);
	
	
	///刷新该CCurrPartPosiLimitDetail的键值
	///@param	pCurrPartPosiLimitDetail	被刷新的CCurrPartPosiLimitDetail
	///@param	pNewCurrPartPosiLimitDetail	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CWriteableCurrPartPosiLimitDetail *pNewCurrPartPosiLimitDetail, bool updateIndex,bool bNoTransaction);
	
	///删除一个CCurrPartPosiLimitDetail，同时删除其索引
	///@param	pCurrPartPosiLimitDetail	要删除的CCurrPartPosiLimitDetail
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, bool bNoTransaction);
/*
	///检查某个CCurrPartPosiLimitDetail是否属于本对象工厂
	///@param	pCurrPartPosiLimitDetail	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于InstrumentID+ParticipantID+TradingRole+StartTotalPosition的索引
	CAVLTree *pInstrumentAndPartIndex;
	
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CCurrPartPosiLimitDetail *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pCurrPartPosiLimitDetail	要加入的CurrPartPosiLimitDetail
	virtual void beforeAdd(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail);
	
	///加入后触发
	///@param	pCurrPartPosiLimitDetail	已经加入的CurrPartPosiLimitDetail
	virtual void afterAdd(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail);

	///更新前触发	
	///@param	pCurrPartPosiLimitDetail	被刷新的CCurrPartPosiLimitDetail
	///@param	pNewCurrPartPosiLimitDetail	新的值
	virtual void beforeUpdate(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CWriteableCurrPartPosiLimitDetail *pNewCurrPartPosiLimitDetail);
	
	///更新后触发
	///@param	pCurrPartPosiLimitDetail	被刷新的CCurrPartPosiLimitDetail
	virtual void afterUpdate(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail);
	
	///删除前触发
	///@param	pCurrPartPosiLimitDetail	要删除的CCurrPartPosiLimitDetail
	virtual void beforeRemove(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail);
	
	///确认加入后触发
	///@param	pCurrPartPosiLimitDetail	已经加入的CurrPartPosiLimitDetail
	virtual void commitAdd(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail);

	///确认更新后触发
	///@param	pCurrPartPosiLimitDetail	被刷新的CCurrPartPosiLimitDetail
	///@param	poldCurrPartPosiLimitDetail	原来的值
	virtual void commitUpdate(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CWriteableCurrPartPosiLimitDetail *pOldCurrPartPosiLimitDetail);
	
	///确认删除后触发
	///@param	pCurrPartPosiLimitDetail	已经删除的CCurrPartPosiLimitDetail
	virtual void commitRemove(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail);

	///所有相关的触发器
	vector<CCurrPartPosiLimitDetailActionTrigger *> *pActionTriggers;
	vector<CCurrPartPosiLimitDetailCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableCurrPartPosiLimitDetail compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitFactory是一个当前客户合约限仓的对象工厂。它包含了一批当前客户合约限仓，
///同时又建立了如下索引，以方便查询：
///使用本对象工厂，可以完成对当前客户合约限仓的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrClientPosiLimitFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxCurrClientPosiLimit，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrClientPosiLimitFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CCurrClientPosiLimitFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的CurrClientPosiLimit
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的CurrClientPosiLimit，文件名将根据配置文件中的定义CurrClientPosiLimitCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的CurrClientPosiLimit
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的CurrClientPosiLimit，文件名将根据配置文件中的定义CurrClientPosiLimitCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CCurrClientPosiLimitResource;

	///将一个CCurrClientPosiLimit加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrClientPosiLimit	要加入的CurrClientPosiLimit
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrClientPosiLimit *add(CWriteableCurrClientPosiLimit *pCurrClientPosiLimit, CTransaction *pTransaction=NULL);
	
	///刷新该CCurrClientPosiLimit的值
	///@param	pCurrClientPosiLimit	被刷新的CCurrClientPosiLimit
	///@param	pNewCurrClientPosiLimit	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CCurrClientPosiLimit *pCurrClientPosiLimit, CWriteableCurrClientPosiLimit *pNewCurrClientPosiLimit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pCurrClientPosiLimit	  需要被刷新或者新增的CCurrClientPosiLimit,等于NULL表示是需要新增的
	///@param	pNewCurrClientPosiLimit	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CCurrClientPosiLimit* addOrUpdate(CCurrClientPosiLimit *pCurrClientPosiLimit, CWriteableCurrClientPosiLimit *pNewCurrClientPosiLimit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CCurrClientPosiLimit，同时删除其索引
	///@param	pCurrClientPosiLimit	要删除的CCurrClientPosiLimit
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CCurrClientPosiLimit *pCurrClientPosiLimit, CTransaction *pTransaction=NULL);
	
	///获取某个CCurrClientPosiLimit
	///@param	pCurrClientPosiLimit	要读取的CCurrClientPosiLimit
	///@param	pTragetCurrClientPosiLimit	存放结果的CCurrClientPosiLimit
	void retrieve(CCurrClientPosiLimit *pCurrClientPosiLimit, CWriteableCurrClientPosiLimit *pTargetCurrClientPosiLimit);
	
	///获取第一个CCurrClientPosiLimit
	///@return	得到的第一个CCurrClientPosiLimit，如果没有，则返回NULL
	CCurrClientPosiLimit *getFirst(void);
	
	///获取下一个CCurrClientPosiLimit
	///@return	得到下一个CCurrClientPosiLimit，如果没有，则返回NULL
	CCurrClientPosiLimit *getNext(void);
	
	///结束获取CCurrClientPosiLimit
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CCurrClientPosiLimitActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CCurrClientPosiLimitActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CCurrClientPosiLimitCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CCurrClientPosiLimitCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CCurrClientPosiLimitIteratorBySettlementGroupID;

	///开始寻找CCurrClientPosiLimit
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CCurrClientPosiLimit，如果找不到，返回NULL
	CCurrClientPosiLimit *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CCurrClientPosiLimit，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrClientPosiLimit，如果已经没有一个满足要求了，则返回NULL
	CCurrClientPosiLimit *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CCurrClientPosiLimit加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrClientPosiLimit	要加入的CurrClientPosiLimit
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrClientPosiLimit *internalAdd(CWriteableCurrClientPosiLimit *pCurrClientPosiLimit, bool bNoTransaction);
	
	
	///刷新该CCurrClientPosiLimit的键值
	///@param	pCurrClientPosiLimit	被刷新的CCurrClientPosiLimit
	///@param	pNewCurrClientPosiLimit	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CCurrClientPosiLimit *pCurrClientPosiLimit, CWriteableCurrClientPosiLimit *pNewCurrClientPosiLimit, bool updateIndex,bool bNoTransaction);
	
	///删除一个CCurrClientPosiLimit，同时删除其索引
	///@param	pCurrClientPosiLimit	要删除的CCurrClientPosiLimit
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CCurrClientPosiLimit *pCurrClientPosiLimit, bool bNoTransaction);
/*
	///检查某个CCurrClientPosiLimit是否属于本对象工厂
	///@param	pCurrClientPosiLimit	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CCurrClientPosiLimit *pCurrClientPosiLimit);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CCurrClientPosiLimit *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pCurrClientPosiLimit	要加入的CurrClientPosiLimit
	virtual void beforeAdd(CWriteableCurrClientPosiLimit *pCurrClientPosiLimit);
	
	///加入后触发
	///@param	pCurrClientPosiLimit	已经加入的CurrClientPosiLimit
	virtual void afterAdd(CCurrClientPosiLimit *pCurrClientPosiLimit);

	///更新前触发	
	///@param	pCurrClientPosiLimit	被刷新的CCurrClientPosiLimit
	///@param	pNewCurrClientPosiLimit	新的值
	virtual void beforeUpdate(CCurrClientPosiLimit *pCurrClientPosiLimit, CWriteableCurrClientPosiLimit *pNewCurrClientPosiLimit);
	
	///更新后触发
	///@param	pCurrClientPosiLimit	被刷新的CCurrClientPosiLimit
	virtual void afterUpdate(CCurrClientPosiLimit *pCurrClientPosiLimit);
	
	///删除前触发
	///@param	pCurrClientPosiLimit	要删除的CCurrClientPosiLimit
	virtual void beforeRemove(CCurrClientPosiLimit *pCurrClientPosiLimit);
	
	///确认加入后触发
	///@param	pCurrClientPosiLimit	已经加入的CurrClientPosiLimit
	virtual void commitAdd(CCurrClientPosiLimit *pCurrClientPosiLimit);

	///确认更新后触发
	///@param	pCurrClientPosiLimit	被刷新的CCurrClientPosiLimit
	///@param	poldCurrClientPosiLimit	原来的值
	virtual void commitUpdate(CCurrClientPosiLimit *pCurrClientPosiLimit, CWriteableCurrClientPosiLimit *pOldCurrClientPosiLimit);
	
	///确认删除后触发
	///@param	pCurrClientPosiLimit	已经删除的CCurrClientPosiLimit
	virtual void commitRemove(CWriteableCurrClientPosiLimit *pCurrClientPosiLimit);

	///所有相关的触发器
	vector<CCurrClientPosiLimitActionTrigger *> *pActionTriggers;
	vector<CCurrClientPosiLimitCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableCurrClientPosiLimit compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDetailFactory是一个当前客户合约限仓的详细内容的对象工厂。它包含了一批当前客户合约限仓的详细内容，
///同时又建立了如下索引，以方便查询：
///	InstrumentAndClientTypeIndex
///使用本对象工厂，可以完成对当前客户合约限仓的详细内容的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByInstrumentAndClientType，唯一找到对象
///		使用findByInstrumentClientTypeAndStartPosition，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDetailFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrClientPosiLimitDetailFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxCurrClientPosiLimitDetail，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrClientPosiLimitDetailFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CCurrClientPosiLimitDetailFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的CurrClientPosiLimitDetail
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的CurrClientPosiLimitDetail，文件名将根据配置文件中的定义CurrClientPosiLimitDetailCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的CurrClientPosiLimitDetail
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的CurrClientPosiLimitDetail，文件名将根据配置文件中的定义CurrClientPosiLimitDetailCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CCurrClientPosiLimitDetailResource;

	///将一个CCurrClientPosiLimitDetail加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrClientPosiLimitDetail	要加入的CurrClientPosiLimitDetail
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrClientPosiLimitDetail *add(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CTransaction *pTransaction=NULL);
	
	///刷新该CCurrClientPosiLimitDetail的值
	///@param	pCurrClientPosiLimitDetail	被刷新的CCurrClientPosiLimitDetail
	///@param	pNewCurrClientPosiLimitDetail	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CWriteableCurrClientPosiLimitDetail *pNewCurrClientPosiLimitDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pCurrClientPosiLimitDetail	  需要被刷新或者新增的CCurrClientPosiLimitDetail,等于NULL表示是需要新增的
	///@param	pNewCurrClientPosiLimitDetail	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CCurrClientPosiLimitDetail* addOrUpdate(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CWriteableCurrClientPosiLimitDetail *pNewCurrClientPosiLimitDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CCurrClientPosiLimitDetail，同时删除其索引
	///@param	pCurrClientPosiLimitDetail	要删除的CCurrClientPosiLimitDetail
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CTransaction *pTransaction=NULL);
	
	///获取某个CCurrClientPosiLimitDetail
	///@param	pCurrClientPosiLimitDetail	要读取的CCurrClientPosiLimitDetail
	///@param	pTragetCurrClientPosiLimitDetail	存放结果的CCurrClientPosiLimitDetail
	void retrieve(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CWriteableCurrClientPosiLimitDetail *pTargetCurrClientPosiLimitDetail);
	
	///获取第一个CCurrClientPosiLimitDetail
	///@return	得到的第一个CCurrClientPosiLimitDetail，如果没有，则返回NULL
	CCurrClientPosiLimitDetail *getFirst(void);
	
	///获取下一个CCurrClientPosiLimitDetail
	///@return	得到下一个CCurrClientPosiLimitDetail，如果没有，则返回NULL
	CCurrClientPosiLimitDetail *getNext(void);
	
	///结束获取CCurrClientPosiLimitDetail
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CCurrClientPosiLimitDetailActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CCurrClientPosiLimitDetailActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CCurrClientPosiLimitDetailCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CCurrClientPosiLimitDetailCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CCurrClientPosiLimitDetailIteratorBySettlementGroupID;

	///开始寻找CCurrClientPosiLimitDetail
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CCurrClientPosiLimitDetail，如果找不到，返回NULL
	CCurrClientPosiLimitDetail *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CCurrClientPosiLimitDetail，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrClientPosiLimitDetail，如果已经没有一个满足要求了，则返回NULL
	CCurrClientPosiLimitDetail *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CCurrClientPosiLimitDetail
	///@param	InstrumentID	合约代码
	///@param	ClientType	客户类型
	///@param	StartTotalPosition	起始总持仓
	///@return	找到的CCurrClientPosiLimitDetail，如果找不到，返回NULL
	CCurrClientPosiLimitDetail *findByInstrumentAndClientType( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyClientTypeType&  ClientType,  const CReadOnlyLargeVolumeType&  StartTotalPosition);



	///寻找CCurrClientPosiLimitDetail
	///@param	InstrumentID	合约代码
	///@param	ClientType	客户类型
	///@param	StartTotalPosition	起始总持仓
	///@return	找到的CCurrClientPosiLimitDetail，如果找不到，返回NULL
	CCurrClientPosiLimitDetail *findByInstrumentClientTypeAndStartPosition( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyClientTypeType&  ClientType,  const CReadOnlyLargeVolumeType&  StartTotalPosition);

	///根据主码寻找
	///@param	InstrumentID	合约代码
	///@param	ClientType	客户类型
	///@param	StartTotalPosition	起始总持仓
	///@return	找到的CCurrClientPosiLimitDetail，如果找不到，返回NULL
	CCurrClientPosiLimitDetail *findByPK( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyClientTypeType&  ClientType,  const CReadOnlyLargeVolumeType&  StartTotalPosition);
	
	///根据主键寻找CCurrClientPosiLimitDetail
	///@param	pCurrClientPosiLimitDetail	要找的值
	///@return	找到的CCurrClientPosiLimitDetail，如果找不到，返回NULL
	CCurrClientPosiLimitDetail *findByPK(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail);

	///根据主键获取CCurrClientPosiLimitDetail
	///@param	pCurrClientPosiLimitDetail	要获取的值，同时用于存放返回的结果
	///@return	找到的CCurrClientPosiLimitDetail，如果找不到，返回NULL
	bool retrieveByPK(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail);

	///根据主键增加新的CCurrClientPosiLimitDetail
	///@param	pCurrClientPosiLimitDetail	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	返回插入的CCurrClientPosiLimitDetail，如果插入失败，则返回NULL
	CCurrClientPosiLimitDetail *addByPK(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CTransaction *pTransaction=NULL);

	///根据主键更新CCurrClientPosiLimitDetail的值
	///@param	pCurrClientPosiLimitDetail	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	///@return	true表示成功，false表示失败
	bool updateByPK(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///根据主键删除CCurrClientPosiLimitDetail
	///@param	pCurrClientPosiLimitDetail	要删除的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	true表示成功，false表示失败
	bool removeByPK(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CTransaction *pTransaction=NULL);


private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CCurrClientPosiLimitDetail加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrClientPosiLimitDetail	要加入的CurrClientPosiLimitDetail
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrClientPosiLimitDetail *internalAdd(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, bool bNoTransaction);
	
	
	///刷新该CCurrClientPosiLimitDetail的键值
	///@param	pCurrClientPosiLimitDetail	被刷新的CCurrClientPosiLimitDetail
	///@param	pNewCurrClientPosiLimitDetail	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CWriteableCurrClientPosiLimitDetail *pNewCurrClientPosiLimitDetail, bool updateIndex,bool bNoTransaction);
	
	///删除一个CCurrClientPosiLimitDetail，同时删除其索引
	///@param	pCurrClientPosiLimitDetail	要删除的CCurrClientPosiLimitDetail
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, bool bNoTransaction);
/*
	///检查某个CCurrClientPosiLimitDetail是否属于本对象工厂
	///@param	pCurrClientPosiLimitDetail	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于InstrumentID+ClientType+StartTotalPosition的索引
	CAVLTree *pInstrumentAndClientTypeIndex;
	
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CCurrClientPosiLimitDetail *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pCurrClientPosiLimitDetail	要加入的CurrClientPosiLimitDetail
	virtual void beforeAdd(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail);
	
	///加入后触发
	///@param	pCurrClientPosiLimitDetail	已经加入的CurrClientPosiLimitDetail
	virtual void afterAdd(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail);

	///更新前触发	
	///@param	pCurrClientPosiLimitDetail	被刷新的CCurrClientPosiLimitDetail
	///@param	pNewCurrClientPosiLimitDetail	新的值
	virtual void beforeUpdate(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CWriteableCurrClientPosiLimitDetail *pNewCurrClientPosiLimitDetail);
	
	///更新后触发
	///@param	pCurrClientPosiLimitDetail	被刷新的CCurrClientPosiLimitDetail
	virtual void afterUpdate(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail);
	
	///删除前触发
	///@param	pCurrClientPosiLimitDetail	要删除的CCurrClientPosiLimitDetail
	virtual void beforeRemove(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail);
	
	///确认加入后触发
	///@param	pCurrClientPosiLimitDetail	已经加入的CurrClientPosiLimitDetail
	virtual void commitAdd(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail);

	///确认更新后触发
	///@param	pCurrClientPosiLimitDetail	被刷新的CCurrClientPosiLimitDetail
	///@param	poldCurrClientPosiLimitDetail	原来的值
	virtual void commitUpdate(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CWriteableCurrClientPosiLimitDetail *pOldCurrClientPosiLimitDetail);
	
	///确认删除后触发
	///@param	pCurrClientPosiLimitDetail	已经删除的CCurrClientPosiLimitDetail
	virtual void commitRemove(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail);

	///所有相关的触发器
	vector<CCurrClientPosiLimitDetailActionTrigger *> *pActionTriggers;
	vector<CCurrClientPosiLimitDetailCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableCurrClientPosiLimitDetail compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitFactory是一个当前特殊客户合约限仓的对象工厂。它包含了一批当前特殊客户合约限仓，
///同时又建立了如下索引，以方便查询：
///使用本对象工厂，可以完成对当前特殊客户合约限仓的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrSpecialPosiLimitFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxCurrSpecialPosiLimit，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrSpecialPosiLimitFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CCurrSpecialPosiLimitFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的CurrSpecialPosiLimit
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的CurrSpecialPosiLimit，文件名将根据配置文件中的定义CurrSpecialPosiLimitCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的CurrSpecialPosiLimit
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的CurrSpecialPosiLimit，文件名将根据配置文件中的定义CurrSpecialPosiLimitCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CCurrSpecialPosiLimitResource;

	///将一个CCurrSpecialPosiLimit加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrSpecialPosiLimit	要加入的CurrSpecialPosiLimit
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrSpecialPosiLimit *add(CWriteableCurrSpecialPosiLimit *pCurrSpecialPosiLimit, CTransaction *pTransaction=NULL);
	
	///刷新该CCurrSpecialPosiLimit的值
	///@param	pCurrSpecialPosiLimit	被刷新的CCurrSpecialPosiLimit
	///@param	pNewCurrSpecialPosiLimit	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit, CWriteableCurrSpecialPosiLimit *pNewCurrSpecialPosiLimit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pCurrSpecialPosiLimit	  需要被刷新或者新增的CCurrSpecialPosiLimit,等于NULL表示是需要新增的
	///@param	pNewCurrSpecialPosiLimit	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CCurrSpecialPosiLimit* addOrUpdate(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit, CWriteableCurrSpecialPosiLimit *pNewCurrSpecialPosiLimit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CCurrSpecialPosiLimit，同时删除其索引
	///@param	pCurrSpecialPosiLimit	要删除的CCurrSpecialPosiLimit
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit, CTransaction *pTransaction=NULL);
	
	///获取某个CCurrSpecialPosiLimit
	///@param	pCurrSpecialPosiLimit	要读取的CCurrSpecialPosiLimit
	///@param	pTragetCurrSpecialPosiLimit	存放结果的CCurrSpecialPosiLimit
	void retrieve(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit, CWriteableCurrSpecialPosiLimit *pTargetCurrSpecialPosiLimit);
	
	///获取第一个CCurrSpecialPosiLimit
	///@return	得到的第一个CCurrSpecialPosiLimit，如果没有，则返回NULL
	CCurrSpecialPosiLimit *getFirst(void);
	
	///获取下一个CCurrSpecialPosiLimit
	///@return	得到下一个CCurrSpecialPosiLimit，如果没有，则返回NULL
	CCurrSpecialPosiLimit *getNext(void);
	
	///结束获取CCurrSpecialPosiLimit
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CCurrSpecialPosiLimitActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CCurrSpecialPosiLimitActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CCurrSpecialPosiLimitCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CCurrSpecialPosiLimitCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CCurrSpecialPosiLimitIteratorBySettlementGroupID;

	///开始寻找CCurrSpecialPosiLimit
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CCurrSpecialPosiLimit，如果找不到，返回NULL
	CCurrSpecialPosiLimit *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CCurrSpecialPosiLimit，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrSpecialPosiLimit，如果已经没有一个满足要求了，则返回NULL
	CCurrSpecialPosiLimit *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CCurrSpecialPosiLimit加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrSpecialPosiLimit	要加入的CurrSpecialPosiLimit
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrSpecialPosiLimit *internalAdd(CWriteableCurrSpecialPosiLimit *pCurrSpecialPosiLimit, bool bNoTransaction);
	
	
	///刷新该CCurrSpecialPosiLimit的键值
	///@param	pCurrSpecialPosiLimit	被刷新的CCurrSpecialPosiLimit
	///@param	pNewCurrSpecialPosiLimit	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit, CWriteableCurrSpecialPosiLimit *pNewCurrSpecialPosiLimit, bool updateIndex,bool bNoTransaction);
	
	///删除一个CCurrSpecialPosiLimit，同时删除其索引
	///@param	pCurrSpecialPosiLimit	要删除的CCurrSpecialPosiLimit
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit, bool bNoTransaction);
/*
	///检查某个CCurrSpecialPosiLimit是否属于本对象工厂
	///@param	pCurrSpecialPosiLimit	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CCurrSpecialPosiLimit *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pCurrSpecialPosiLimit	要加入的CurrSpecialPosiLimit
	virtual void beforeAdd(CWriteableCurrSpecialPosiLimit *pCurrSpecialPosiLimit);
	
	///加入后触发
	///@param	pCurrSpecialPosiLimit	已经加入的CurrSpecialPosiLimit
	virtual void afterAdd(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit);

	///更新前触发	
	///@param	pCurrSpecialPosiLimit	被刷新的CCurrSpecialPosiLimit
	///@param	pNewCurrSpecialPosiLimit	新的值
	virtual void beforeUpdate(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit, CWriteableCurrSpecialPosiLimit *pNewCurrSpecialPosiLimit);
	
	///更新后触发
	///@param	pCurrSpecialPosiLimit	被刷新的CCurrSpecialPosiLimit
	virtual void afterUpdate(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit);
	
	///删除前触发
	///@param	pCurrSpecialPosiLimit	要删除的CCurrSpecialPosiLimit
	virtual void beforeRemove(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit);
	
	///确认加入后触发
	///@param	pCurrSpecialPosiLimit	已经加入的CurrSpecialPosiLimit
	virtual void commitAdd(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit);

	///确认更新后触发
	///@param	pCurrSpecialPosiLimit	被刷新的CCurrSpecialPosiLimit
	///@param	poldCurrSpecialPosiLimit	原来的值
	virtual void commitUpdate(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit, CWriteableCurrSpecialPosiLimit *pOldCurrSpecialPosiLimit);
	
	///确认删除后触发
	///@param	pCurrSpecialPosiLimit	已经删除的CCurrSpecialPosiLimit
	virtual void commitRemove(CWriteableCurrSpecialPosiLimit *pCurrSpecialPosiLimit);

	///所有相关的触发器
	vector<CCurrSpecialPosiLimitActionTrigger *> *pActionTriggers;
	vector<CCurrSpecialPosiLimitCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableCurrSpecialPosiLimit compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDetailFactory是一个当前特殊客户合约限仓的详细内容的对象工厂。它包含了一批当前特殊客户合约限仓的详细内容，
///同时又建立了如下索引，以方便查询：
///	InstrumentAndClientIndex
///使用本对象工厂，可以完成对当前特殊客户合约限仓的详细内容的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByInstrumentAndClient，唯一找到对象
///		使用findByInstrumentClientAndStartPosition，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDetailFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrSpecialPosiLimitDetailFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxCurrSpecialPosiLimitDetail，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrSpecialPosiLimitDetailFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CCurrSpecialPosiLimitDetailFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的CurrSpecialPosiLimitDetail
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的CurrSpecialPosiLimitDetail，文件名将根据配置文件中的定义CurrSpecialPosiLimitDetailCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的CurrSpecialPosiLimitDetail
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的CurrSpecialPosiLimitDetail，文件名将根据配置文件中的定义CurrSpecialPosiLimitDetailCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CCurrSpecialPosiLimitDetailResource;

	///将一个CCurrSpecialPosiLimitDetail加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrSpecialPosiLimitDetail	要加入的CurrSpecialPosiLimitDetail
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrSpecialPosiLimitDetail *add(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CTransaction *pTransaction=NULL);
	
	///刷新该CCurrSpecialPosiLimitDetail的值
	///@param	pCurrSpecialPosiLimitDetail	被刷新的CCurrSpecialPosiLimitDetail
	///@param	pNewCurrSpecialPosiLimitDetail	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CWriteableCurrSpecialPosiLimitDetail *pNewCurrSpecialPosiLimitDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pCurrSpecialPosiLimitDetail	  需要被刷新或者新增的CCurrSpecialPosiLimitDetail,等于NULL表示是需要新增的
	///@param	pNewCurrSpecialPosiLimitDetail	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CCurrSpecialPosiLimitDetail* addOrUpdate(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CWriteableCurrSpecialPosiLimitDetail *pNewCurrSpecialPosiLimitDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CCurrSpecialPosiLimitDetail，同时删除其索引
	///@param	pCurrSpecialPosiLimitDetail	要删除的CCurrSpecialPosiLimitDetail
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CTransaction *pTransaction=NULL);
	
	///获取某个CCurrSpecialPosiLimitDetail
	///@param	pCurrSpecialPosiLimitDetail	要读取的CCurrSpecialPosiLimitDetail
	///@param	pTragetCurrSpecialPosiLimitDetail	存放结果的CCurrSpecialPosiLimitDetail
	void retrieve(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CWriteableCurrSpecialPosiLimitDetail *pTargetCurrSpecialPosiLimitDetail);
	
	///获取第一个CCurrSpecialPosiLimitDetail
	///@return	得到的第一个CCurrSpecialPosiLimitDetail，如果没有，则返回NULL
	CCurrSpecialPosiLimitDetail *getFirst(void);
	
	///获取下一个CCurrSpecialPosiLimitDetail
	///@return	得到下一个CCurrSpecialPosiLimitDetail，如果没有，则返回NULL
	CCurrSpecialPosiLimitDetail *getNext(void);
	
	///结束获取CCurrSpecialPosiLimitDetail
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CCurrSpecialPosiLimitDetailActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CCurrSpecialPosiLimitDetailActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CCurrSpecialPosiLimitDetailCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CCurrSpecialPosiLimitDetailCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID;

	///开始寻找CCurrSpecialPosiLimitDetail
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CCurrSpecialPosiLimitDetail，如果找不到，返回NULL
	CCurrSpecialPosiLimitDetail *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CCurrSpecialPosiLimitDetail，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrSpecialPosiLimitDetail，如果已经没有一个满足要求了，则返回NULL
	CCurrSpecialPosiLimitDetail *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CCurrSpecialPosiLimitDetail
	///@param	InstrumentID	合约代码
	///@param	ClientID	客户编号
	///@param	StartTotalPosition	起始总持仓
	///@return	找到的CCurrSpecialPosiLimitDetail，如果找不到，返回NULL
	CCurrSpecialPosiLimitDetail *findByInstrumentAndClient( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyClientIDType&  ClientID,  const CReadOnlyLargeVolumeType&  StartTotalPosition);



	///寻找CCurrSpecialPosiLimitDetail
	///@param	InstrumentID	合约代码
	///@param	ClientID	客户编号
	///@param	StartTotalPosition	起始总持仓
	///@return	找到的CCurrSpecialPosiLimitDetail，如果找不到，返回NULL
	CCurrSpecialPosiLimitDetail *findByInstrumentClientAndStartPosition( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyClientIDType&  ClientID,  const CReadOnlyLargeVolumeType&  StartTotalPosition);

	///根据主码寻找
	///@param	InstrumentID	合约代码
	///@param	ClientID	客户编号
	///@param	StartTotalPosition	起始总持仓
	///@return	找到的CCurrSpecialPosiLimitDetail，如果找不到，返回NULL
	CCurrSpecialPosiLimitDetail *findByPK( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyClientIDType&  ClientID,  const CReadOnlyLargeVolumeType&  StartTotalPosition);
	
	///根据主键寻找CCurrSpecialPosiLimitDetail
	///@param	pCurrSpecialPosiLimitDetail	要找的值
	///@return	找到的CCurrSpecialPosiLimitDetail，如果找不到，返回NULL
	CCurrSpecialPosiLimitDetail *findByPK(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail);

	///根据主键获取CCurrSpecialPosiLimitDetail
	///@param	pCurrSpecialPosiLimitDetail	要获取的值，同时用于存放返回的结果
	///@return	找到的CCurrSpecialPosiLimitDetail，如果找不到，返回NULL
	bool retrieveByPK(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail);

	///根据主键增加新的CCurrSpecialPosiLimitDetail
	///@param	pCurrSpecialPosiLimitDetail	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	返回插入的CCurrSpecialPosiLimitDetail，如果插入失败，则返回NULL
	CCurrSpecialPosiLimitDetail *addByPK(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CTransaction *pTransaction=NULL);

	///根据主键更新CCurrSpecialPosiLimitDetail的值
	///@param	pCurrSpecialPosiLimitDetail	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	///@return	true表示成功，false表示失败
	bool updateByPK(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///根据主键删除CCurrSpecialPosiLimitDetail
	///@param	pCurrSpecialPosiLimitDetail	要删除的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	true表示成功，false表示失败
	bool removeByPK(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CTransaction *pTransaction=NULL);


private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CCurrSpecialPosiLimitDetail加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrSpecialPosiLimitDetail	要加入的CurrSpecialPosiLimitDetail
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrSpecialPosiLimitDetail *internalAdd(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, bool bNoTransaction);
	
	
	///刷新该CCurrSpecialPosiLimitDetail的键值
	///@param	pCurrSpecialPosiLimitDetail	被刷新的CCurrSpecialPosiLimitDetail
	///@param	pNewCurrSpecialPosiLimitDetail	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CWriteableCurrSpecialPosiLimitDetail *pNewCurrSpecialPosiLimitDetail, bool updateIndex,bool bNoTransaction);
	
	///删除一个CCurrSpecialPosiLimitDetail，同时删除其索引
	///@param	pCurrSpecialPosiLimitDetail	要删除的CCurrSpecialPosiLimitDetail
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, bool bNoTransaction);
/*
	///检查某个CCurrSpecialPosiLimitDetail是否属于本对象工厂
	///@param	pCurrSpecialPosiLimitDetail	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于InstrumentID+ClientID+StartTotalPosition的索引
	CAVLTree *pInstrumentAndClientIndex;
	
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CCurrSpecialPosiLimitDetail *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pCurrSpecialPosiLimitDetail	要加入的CurrSpecialPosiLimitDetail
	virtual void beforeAdd(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail);
	
	///加入后触发
	///@param	pCurrSpecialPosiLimitDetail	已经加入的CurrSpecialPosiLimitDetail
	virtual void afterAdd(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail);

	///更新前触发	
	///@param	pCurrSpecialPosiLimitDetail	被刷新的CCurrSpecialPosiLimitDetail
	///@param	pNewCurrSpecialPosiLimitDetail	新的值
	virtual void beforeUpdate(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CWriteableCurrSpecialPosiLimitDetail *pNewCurrSpecialPosiLimitDetail);
	
	///更新后触发
	///@param	pCurrSpecialPosiLimitDetail	被刷新的CCurrSpecialPosiLimitDetail
	virtual void afterUpdate(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail);
	
	///删除前触发
	///@param	pCurrSpecialPosiLimitDetail	要删除的CCurrSpecialPosiLimitDetail
	virtual void beforeRemove(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail);
	
	///确认加入后触发
	///@param	pCurrSpecialPosiLimitDetail	已经加入的CurrSpecialPosiLimitDetail
	virtual void commitAdd(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail);

	///确认更新后触发
	///@param	pCurrSpecialPosiLimitDetail	被刷新的CCurrSpecialPosiLimitDetail
	///@param	poldCurrSpecialPosiLimitDetail	原来的值
	virtual void commitUpdate(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CWriteableCurrSpecialPosiLimitDetail *pOldCurrSpecialPosiLimitDetail);
	
	///确认删除后触发
	///@param	pCurrSpecialPosiLimitDetail	已经删除的CCurrSpecialPosiLimitDetail
	virtual void commitRemove(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail);

	///所有相关的触发器
	vector<CCurrSpecialPosiLimitDetailActionTrigger *> *pActionTriggers;
	vector<CCurrSpecialPosiLimitDetailCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableCurrSpecialPosiLimitDetail compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRuleFactory是一个当前合约套期保值属性的对象工厂。它包含了一批当前合约套期保值属性，
///同时又建立了如下索引，以方便查询：
///	InstrumentIDIndex
///使用本对象工厂，可以完成对当前合约套期保值属性的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByInstrumentID，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRuleFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrHedgeRuleFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxCurrHedgeRule，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrHedgeRuleFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CCurrHedgeRuleFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的CurrHedgeRule
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的CurrHedgeRule，文件名将根据配置文件中的定义CurrHedgeRuleCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的CurrHedgeRule
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的CurrHedgeRule，文件名将根据配置文件中的定义CurrHedgeRuleCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CCurrHedgeRuleResource;

	///将一个CCurrHedgeRule加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrHedgeRule	要加入的CurrHedgeRule
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrHedgeRule *add(CWriteableCurrHedgeRule *pCurrHedgeRule, CTransaction *pTransaction=NULL);
	
	///刷新该CCurrHedgeRule的值
	///@param	pCurrHedgeRule	被刷新的CCurrHedgeRule
	///@param	pNewCurrHedgeRule	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CCurrHedgeRule *pCurrHedgeRule, CWriteableCurrHedgeRule *pNewCurrHedgeRule, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pCurrHedgeRule	  需要被刷新或者新增的CCurrHedgeRule,等于NULL表示是需要新增的
	///@param	pNewCurrHedgeRule	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CCurrHedgeRule* addOrUpdate(CCurrHedgeRule *pCurrHedgeRule, CWriteableCurrHedgeRule *pNewCurrHedgeRule, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CCurrHedgeRule，同时删除其索引
	///@param	pCurrHedgeRule	要删除的CCurrHedgeRule
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CCurrHedgeRule *pCurrHedgeRule, CTransaction *pTransaction=NULL);
	
	///获取某个CCurrHedgeRule
	///@param	pCurrHedgeRule	要读取的CCurrHedgeRule
	///@param	pTragetCurrHedgeRule	存放结果的CCurrHedgeRule
	void retrieve(CCurrHedgeRule *pCurrHedgeRule, CWriteableCurrHedgeRule *pTargetCurrHedgeRule);
	
	///获取第一个CCurrHedgeRule
	///@return	得到的第一个CCurrHedgeRule，如果没有，则返回NULL
	CCurrHedgeRule *getFirst(void);
	
	///获取下一个CCurrHedgeRule
	///@return	得到下一个CCurrHedgeRule，如果没有，则返回NULL
	CCurrHedgeRule *getNext(void);
	
	///结束获取CCurrHedgeRule
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CCurrHedgeRuleActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CCurrHedgeRuleActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CCurrHedgeRuleCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CCurrHedgeRuleCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CCurrHedgeRuleIteratorBySettlementGroupID;

	///开始寻找CCurrHedgeRule
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CCurrHedgeRule，如果找不到，返回NULL
	CCurrHedgeRule *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CCurrHedgeRule，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrHedgeRule，如果已经没有一个满足要求了，则返回NULL
	CCurrHedgeRule *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CCurrHedgeRule
	///@param	InstrumentID	合约代码
	///@return	找到的CCurrHedgeRule，如果找不到，返回NULL
	CCurrHedgeRule *findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CCurrHedgeRule加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrHedgeRule	要加入的CurrHedgeRule
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrHedgeRule *internalAdd(CWriteableCurrHedgeRule *pCurrHedgeRule, bool bNoTransaction);
	
	
	///刷新该CCurrHedgeRule的键值
	///@param	pCurrHedgeRule	被刷新的CCurrHedgeRule
	///@param	pNewCurrHedgeRule	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CCurrHedgeRule *pCurrHedgeRule, CWriteableCurrHedgeRule *pNewCurrHedgeRule, bool updateIndex,bool bNoTransaction);
	
	///删除一个CCurrHedgeRule，同时删除其索引
	///@param	pCurrHedgeRule	要删除的CCurrHedgeRule
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CCurrHedgeRule *pCurrHedgeRule, bool bNoTransaction);
/*
	///检查某个CCurrHedgeRule是否属于本对象工厂
	///@param	pCurrHedgeRule	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CCurrHedgeRule *pCurrHedgeRule);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于InstrumentID的索引
	CAVLTree *pInstrumentIDIndex;
	
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CCurrHedgeRule *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pCurrHedgeRule	要加入的CurrHedgeRule
	virtual void beforeAdd(CWriteableCurrHedgeRule *pCurrHedgeRule);
	
	///加入后触发
	///@param	pCurrHedgeRule	已经加入的CurrHedgeRule
	virtual void afterAdd(CCurrHedgeRule *pCurrHedgeRule);

	///更新前触发	
	///@param	pCurrHedgeRule	被刷新的CCurrHedgeRule
	///@param	pNewCurrHedgeRule	新的值
	virtual void beforeUpdate(CCurrHedgeRule *pCurrHedgeRule, CWriteableCurrHedgeRule *pNewCurrHedgeRule);
	
	///更新后触发
	///@param	pCurrHedgeRule	被刷新的CCurrHedgeRule
	virtual void afterUpdate(CCurrHedgeRule *pCurrHedgeRule);
	
	///删除前触发
	///@param	pCurrHedgeRule	要删除的CCurrHedgeRule
	virtual void beforeRemove(CCurrHedgeRule *pCurrHedgeRule);
	
	///确认加入后触发
	///@param	pCurrHedgeRule	已经加入的CurrHedgeRule
	virtual void commitAdd(CCurrHedgeRule *pCurrHedgeRule);

	///确认更新后触发
	///@param	pCurrHedgeRule	被刷新的CCurrHedgeRule
	///@param	poldCurrHedgeRule	原来的值
	virtual void commitUpdate(CCurrHedgeRule *pCurrHedgeRule, CWriteableCurrHedgeRule *pOldCurrHedgeRule);
	
	///确认删除后触发
	///@param	pCurrHedgeRule	已经删除的CCurrHedgeRule
	virtual void commitRemove(CWriteableCurrHedgeRule *pCurrHedgeRule);

	///所有相关的触发器
	vector<CCurrHedgeRuleActionTrigger *> *pActionTriggers;
	vector<CCurrHedgeRuleCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableCurrHedgeRule compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrFactory是一个当前合约交易阶段属性的对象工厂。它包含了一批当前合约交易阶段属性，
///同时又建立了如下索引，以方便查询：
///	TimeIndex
///	InstrumentIndex
///使用本对象工厂，可以完成对当前合约交易阶段属性的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用startFindByTime，findNextByTime和endFindByTime完成查询操作
///		使用startFindByInstrument，findNextByInstrument和endFindByInstrument完成查询操作
///		使用findByInstrumentAndSegement，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrTradingSegmentAttrFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxCurrTradingSegmentAttr，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrTradingSegmentAttrFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CCurrTradingSegmentAttrFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的CurrTradingSegmentAttr
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的CurrTradingSegmentAttr，文件名将根据配置文件中的定义CurrTradingSegmentAttrCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的CurrTradingSegmentAttr
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的CurrTradingSegmentAttr，文件名将根据配置文件中的定义CurrTradingSegmentAttrCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CCurrTradingSegmentAttrResource;

	///将一个CCurrTradingSegmentAttr加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrTradingSegmentAttr	要加入的CurrTradingSegmentAttr
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrTradingSegmentAttr *add(CWriteableCurrTradingSegmentAttr *pCurrTradingSegmentAttr, CTransaction *pTransaction=NULL);
	
	///刷新该CCurrTradingSegmentAttr的值
	///@param	pCurrTradingSegmentAttr	被刷新的CCurrTradingSegmentAttr
	///@param	pNewCurrTradingSegmentAttr	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr, CWriteableCurrTradingSegmentAttr *pNewCurrTradingSegmentAttr, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pCurrTradingSegmentAttr	  需要被刷新或者新增的CCurrTradingSegmentAttr,等于NULL表示是需要新增的
	///@param	pNewCurrTradingSegmentAttr	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CCurrTradingSegmentAttr* addOrUpdate(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr, CWriteableCurrTradingSegmentAttr *pNewCurrTradingSegmentAttr, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CCurrTradingSegmentAttr，同时删除其索引
	///@param	pCurrTradingSegmentAttr	要删除的CCurrTradingSegmentAttr
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr, CTransaction *pTransaction=NULL);
	
	///获取某个CCurrTradingSegmentAttr
	///@param	pCurrTradingSegmentAttr	要读取的CCurrTradingSegmentAttr
	///@param	pTragetCurrTradingSegmentAttr	存放结果的CCurrTradingSegmentAttr
	void retrieve(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr, CWriteableCurrTradingSegmentAttr *pTargetCurrTradingSegmentAttr);
	
	///获取第一个CCurrTradingSegmentAttr
	///@return	得到的第一个CCurrTradingSegmentAttr，如果没有，则返回NULL
	CCurrTradingSegmentAttr *getFirst(void);
	
	///获取下一个CCurrTradingSegmentAttr
	///@return	得到下一个CCurrTradingSegmentAttr，如果没有，则返回NULL
	CCurrTradingSegmentAttr *getNext(void);
	
	///结束获取CCurrTradingSegmentAttr
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CCurrTradingSegmentAttrActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CCurrTradingSegmentAttrActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CCurrTradingSegmentAttrCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CCurrTradingSegmentAttrCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CCurrTradingSegmentAttrIteratorBySettlementGroupID;

	///开始寻找CCurrTradingSegmentAttr
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CCurrTradingSegmentAttr，如果找不到，返回NULL
	CCurrTradingSegmentAttr *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CCurrTradingSegmentAttr，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrTradingSegmentAttr，如果已经没有一个满足要求了，则返回NULL
	CCurrTradingSegmentAttr *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	friend class CCurrTradingSegmentAttrIteratorByTime;

	///开始寻找CCurrTradingSegmentAttr
	///@param	StartTime	起始时间
	///@return	满足条件的地一个CCurrTradingSegmentAttr，如果找不到，返回NULL
	CCurrTradingSegmentAttr *startFindByTime( const CReadOnlyTimeType& StartTime);

	///寻找下一个符合条件的CCurrTradingSegmentAttr，必须在startFindByTime以后，endFindByTime之前叫用
	///@return	下一个满足条件CCurrTradingSegmentAttr，如果已经没有一个满足要求了，则返回NULL
	CCurrTradingSegmentAttr *findNextByTime(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByTime(void);

	friend class CCurrTradingSegmentAttrIteratorByInstrument;

	///开始寻找CCurrTradingSegmentAttr
	///@param	InstrumentID	合约编号
	///@return	满足条件的地一个CCurrTradingSegmentAttr，如果找不到，返回NULL
	CCurrTradingSegmentAttr *startFindByInstrument( const CReadOnlyInstrumentIDType& InstrumentID);

	///寻找下一个符合条件的CCurrTradingSegmentAttr，必须在startFindByInstrument以后，endFindByInstrument之前叫用
	///@return	下一个满足条件CCurrTradingSegmentAttr，如果已经没有一个满足要求了，则返回NULL
	CCurrTradingSegmentAttr *findNextByInstrument(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByInstrument(void);

	///寻找CCurrTradingSegmentAttr
	///@param	InstrumentID	合约编号
	///@param	TradingSegmentSN	交易阶段编号
	///@return	找到的CCurrTradingSegmentAttr，如果找不到，返回NULL
	CCurrTradingSegmentAttr *findByInstrumentAndSegement( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyTradingSegmentSNType&  TradingSegmentSN);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CCurrTradingSegmentAttr加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrTradingSegmentAttr	要加入的CurrTradingSegmentAttr
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrTradingSegmentAttr *internalAdd(CWriteableCurrTradingSegmentAttr *pCurrTradingSegmentAttr, bool bNoTransaction);
	
	
	///刷新该CCurrTradingSegmentAttr的键值
	///@param	pCurrTradingSegmentAttr	被刷新的CCurrTradingSegmentAttr
	///@param	pNewCurrTradingSegmentAttr	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr, CWriteableCurrTradingSegmentAttr *pNewCurrTradingSegmentAttr, bool updateIndex,bool bNoTransaction);
	
	///删除一个CCurrTradingSegmentAttr，同时删除其索引
	///@param	pCurrTradingSegmentAttr	要删除的CCurrTradingSegmentAttr
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr, bool bNoTransaction);
/*
	///检查某个CCurrTradingSegmentAttr是否属于本对象工厂
	///@param	pCurrTradingSegmentAttr	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于StartTime+TradingSegmentSN的索引
	CAVLTree *pTimeIndex;
	///基于InstrumentID+TradingSegmentSN的索引
	CAVLTree *pInstrumentIndex;
	
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CCurrTradingSegmentAttr *pLastFoundInSearchBySettlementGroupID;
	///按照StartTime检索时，存储的查询参数
	CTimeType queryStartTimeInSearchByTime;
	
	///按照StartTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByTime;
	///按照InstrumentID检索时，存储的查询参数
	CInstrumentIDType queryInstrumentIDInSearchByInstrument;
	
	///按照InstrumentID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByInstrument;
	
	///加入前触发
	///@param	pCurrTradingSegmentAttr	要加入的CurrTradingSegmentAttr
	virtual void beforeAdd(CWriteableCurrTradingSegmentAttr *pCurrTradingSegmentAttr);
	
	///加入后触发
	///@param	pCurrTradingSegmentAttr	已经加入的CurrTradingSegmentAttr
	virtual void afterAdd(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr);

	///更新前触发	
	///@param	pCurrTradingSegmentAttr	被刷新的CCurrTradingSegmentAttr
	///@param	pNewCurrTradingSegmentAttr	新的值
	virtual void beforeUpdate(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr, CWriteableCurrTradingSegmentAttr *pNewCurrTradingSegmentAttr);
	
	///更新后触发
	///@param	pCurrTradingSegmentAttr	被刷新的CCurrTradingSegmentAttr
	virtual void afterUpdate(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr);
	
	///删除前触发
	///@param	pCurrTradingSegmentAttr	要删除的CCurrTradingSegmentAttr
	virtual void beforeRemove(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr);
	
	///确认加入后触发
	///@param	pCurrTradingSegmentAttr	已经加入的CurrTradingSegmentAttr
	virtual void commitAdd(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr);

	///确认更新后触发
	///@param	pCurrTradingSegmentAttr	被刷新的CCurrTradingSegmentAttr
	///@param	poldCurrTradingSegmentAttr	原来的值
	virtual void commitUpdate(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr, CWriteableCurrTradingSegmentAttr *pOldCurrTradingSegmentAttr);
	
	///确认删除后触发
	///@param	pCurrTradingSegmentAttr	已经删除的CCurrTradingSegmentAttr
	virtual void commitRemove(CWriteableCurrTradingSegmentAttr *pCurrTradingSegmentAttr);

	///所有相关的触发器
	vector<CCurrTradingSegmentAttrActionTrigger *> *pActionTriggers;
	vector<CCurrTradingSegmentAttrCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableCurrTradingSegmentAttr compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrFuseFactory是一个当前合约熔断属性的对象工厂。它包含了一批当前合约熔断属性，
///同时又建立了如下索引，以方便查询：
///	InstrumentIDIndex
///使用本对象工厂，可以完成对当前合约熔断属性的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByInstrumentID，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFuseFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrFuseFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxCurrFuse，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrFuseFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CCurrFuseFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的CurrFuse
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的CurrFuse，文件名将根据配置文件中的定义CurrFuseCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的CurrFuse
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的CurrFuse，文件名将根据配置文件中的定义CurrFuseCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CCurrFuseResource;

	///将一个CCurrFuse加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrFuse	要加入的CurrFuse
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrFuse *add(CWriteableCurrFuse *pCurrFuse, CTransaction *pTransaction=NULL);
	
	///刷新该CCurrFuse的值
	///@param	pCurrFuse	被刷新的CCurrFuse
	///@param	pNewCurrFuse	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CCurrFuse *pCurrFuse, CWriteableCurrFuse *pNewCurrFuse, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pCurrFuse	  需要被刷新或者新增的CCurrFuse,等于NULL表示是需要新增的
	///@param	pNewCurrFuse	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CCurrFuse* addOrUpdate(CCurrFuse *pCurrFuse, CWriteableCurrFuse *pNewCurrFuse, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CCurrFuse，同时删除其索引
	///@param	pCurrFuse	要删除的CCurrFuse
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CCurrFuse *pCurrFuse, CTransaction *pTransaction=NULL);
	
	///获取某个CCurrFuse
	///@param	pCurrFuse	要读取的CCurrFuse
	///@param	pTragetCurrFuse	存放结果的CCurrFuse
	void retrieve(CCurrFuse *pCurrFuse, CWriteableCurrFuse *pTargetCurrFuse);
	
	///获取第一个CCurrFuse
	///@return	得到的第一个CCurrFuse，如果没有，则返回NULL
	CCurrFuse *getFirst(void);
	
	///获取下一个CCurrFuse
	///@return	得到下一个CCurrFuse，如果没有，则返回NULL
	CCurrFuse *getNext(void);
	
	///结束获取CCurrFuse
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CCurrFuseActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CCurrFuseActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CCurrFuseCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CCurrFuseCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CCurrFuseIteratorBySettlementGroupID;

	///开始寻找CCurrFuse
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CCurrFuse，如果找不到，返回NULL
	CCurrFuse *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CCurrFuse，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrFuse，如果已经没有一个满足要求了，则返回NULL
	CCurrFuse *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CCurrFuse
	///@param	InstrumentID	合约编号
	///@return	找到的CCurrFuse，如果找不到，返回NULL
	CCurrFuse *findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID);

	///根据主码寻找
	///@param	InstrumentID	合约编号
	///@return	找到的CCurrFuse，如果找不到，返回NULL
	CCurrFuse *findByPK( const CReadOnlyInstrumentIDType&  InstrumentID);
	
	///根据主键寻找CCurrFuse
	///@param	pCurrFuse	要找的值
	///@return	找到的CCurrFuse，如果找不到，返回NULL
	CCurrFuse *findByPK(CWriteableCurrFuse *pCurrFuse);

	///根据主键获取CCurrFuse
	///@param	pCurrFuse	要获取的值，同时用于存放返回的结果
	///@return	找到的CCurrFuse，如果找不到，返回NULL
	bool retrieveByPK(CWriteableCurrFuse *pCurrFuse);

	///根据主键增加新的CCurrFuse
	///@param	pCurrFuse	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	返回插入的CCurrFuse，如果插入失败，则返回NULL
	CCurrFuse *addByPK(CWriteableCurrFuse *pCurrFuse, CTransaction *pTransaction=NULL);

	///根据主键更新CCurrFuse的值
	///@param	pCurrFuse	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	///@return	true表示成功，false表示失败
	bool updateByPK(CWriteableCurrFuse *pCurrFuse, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///根据主键删除CCurrFuse
	///@param	pCurrFuse	要删除的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	true表示成功，false表示失败
	bool removeByPK(CWriteableCurrFuse *pCurrFuse, CTransaction *pTransaction=NULL);


private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CCurrFuse加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrFuse	要加入的CurrFuse
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrFuse *internalAdd(CWriteableCurrFuse *pCurrFuse, bool bNoTransaction);
	
	
	///刷新该CCurrFuse的键值
	///@param	pCurrFuse	被刷新的CCurrFuse
	///@param	pNewCurrFuse	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CCurrFuse *pCurrFuse, CWriteableCurrFuse *pNewCurrFuse, bool updateIndex,bool bNoTransaction);
	
	///删除一个CCurrFuse，同时删除其索引
	///@param	pCurrFuse	要删除的CCurrFuse
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CCurrFuse *pCurrFuse, bool bNoTransaction);
/*
	///检查某个CCurrFuse是否属于本对象工厂
	///@param	pCurrFuse	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CCurrFuse *pCurrFuse);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于InstrumentID的索引
	CAVLTree *pInstrumentIDIndex;
	
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CCurrFuse *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pCurrFuse	要加入的CurrFuse
	virtual void beforeAdd(CWriteableCurrFuse *pCurrFuse);
	
	///加入后触发
	///@param	pCurrFuse	已经加入的CurrFuse
	virtual void afterAdd(CCurrFuse *pCurrFuse);

	///更新前触发	
	///@param	pCurrFuse	被刷新的CCurrFuse
	///@param	pNewCurrFuse	新的值
	virtual void beforeUpdate(CCurrFuse *pCurrFuse, CWriteableCurrFuse *pNewCurrFuse);
	
	///更新后触发
	///@param	pCurrFuse	被刷新的CCurrFuse
	virtual void afterUpdate(CCurrFuse *pCurrFuse);
	
	///删除前触发
	///@param	pCurrFuse	要删除的CCurrFuse
	virtual void beforeRemove(CCurrFuse *pCurrFuse);
	
	///确认加入后触发
	///@param	pCurrFuse	已经加入的CurrFuse
	virtual void commitAdd(CCurrFuse *pCurrFuse);

	///确认更新后触发
	///@param	pCurrFuse	被刷新的CCurrFuse
	///@param	poldCurrFuse	原来的值
	virtual void commitUpdate(CCurrFuse *pCurrFuse, CWriteableCurrFuse *pOldCurrFuse);
	
	///确认删除后触发
	///@param	pCurrFuse	已经删除的CCurrFuse
	virtual void commitRemove(CWriteableCurrFuse *pCurrFuse);

	///所有相关的触发器
	vector<CCurrFuseActionTrigger *> *pActionTriggers;
	vector<CCurrFuseCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableCurrFuse compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CTradingAccountFactory是一个交易账户的对象工厂。它包含了一批交易账户，
///同时又建立了如下索引，以方便查询：
///	AccountIDIndex
///使用本对象工厂，可以完成对交易账户的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByAccountID，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CTradingAccountFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxTradingAccount，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CTradingAccountFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CTradingAccountFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的TradingAccount
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的TradingAccount，文件名将根据配置文件中的定义TradingAccountCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的TradingAccount
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的TradingAccount，文件名将根据配置文件中的定义TradingAccountCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CTradingAccountResource;

	///将一个CTradingAccount加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pTradingAccount	要加入的TradingAccount
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CTradingAccount *add(CWriteableTradingAccount *pTradingAccount, CTransaction *pTransaction=NULL);
	
	///刷新该CTradingAccount的值
	///@param	pTradingAccount	被刷新的CTradingAccount
	///@param	pNewTradingAccount	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CTradingAccount *pTradingAccount, CWriteableTradingAccount *pNewTradingAccount, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pTradingAccount	  需要被刷新或者新增的CTradingAccount,等于NULL表示是需要新增的
	///@param	pNewTradingAccount	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CTradingAccount* addOrUpdate(CTradingAccount *pTradingAccount, CWriteableTradingAccount *pNewTradingAccount, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CTradingAccount，同时删除其索引
	///@param	pTradingAccount	要删除的CTradingAccount
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CTradingAccount *pTradingAccount, CTransaction *pTransaction=NULL);
	
	///获取某个CTradingAccount
	///@param	pTradingAccount	要读取的CTradingAccount
	///@param	pTragetTradingAccount	存放结果的CTradingAccount
	void retrieve(CTradingAccount *pTradingAccount, CWriteableTradingAccount *pTargetTradingAccount);
	
	///获取第一个CTradingAccount
	///@return	得到的第一个CTradingAccount，如果没有，则返回NULL
	CTradingAccount *getFirst(void);
	
	///获取下一个CTradingAccount
	///@return	得到下一个CTradingAccount，如果没有，则返回NULL
	CTradingAccount *getNext(void);
	
	///结束获取CTradingAccount
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CTradingAccountActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CTradingAccountActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CTradingAccountCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CTradingAccountCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///构造所有对应的基本准备金账户的指针
	///@param	pFactory	构造对应的基本准备金账户的指针时，寻找的对象工厂
	void linkAllBaseReserveAccount(CBaseReserveAccountFactory *pFactory);
	
	friend class CTradingAccountIteratorBySettlementGroupID;

	///开始寻找CTradingAccount
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CTradingAccount，如果找不到，返回NULL
	CTradingAccount *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CTradingAccount，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CTradingAccount，如果已经没有一个满足要求了，则返回NULL
	CTradingAccount *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CTradingAccount
	///@param	AccountID	账户代码
	///@return	找到的CTradingAccount，如果找不到，返回NULL
	CTradingAccount *findByAccountID( const CReadOnlyAccountIDType&  AccountID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CTradingAccount加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pTradingAccount	要加入的TradingAccount
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CTradingAccount *internalAdd(CWriteableTradingAccount *pTradingAccount, bool bNoTransaction);
	
	
	///刷新该CTradingAccount的键值
	///@param	pTradingAccount	被刷新的CTradingAccount
	///@param	pNewTradingAccount	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CTradingAccount *pTradingAccount, CWriteableTradingAccount *pNewTradingAccount, bool updateIndex,bool bNoTransaction);
	
	///删除一个CTradingAccount，同时删除其索引
	///@param	pTradingAccount	要删除的CTradingAccount
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CTradingAccount *pTradingAccount, bool bNoTransaction);
/*
	///检查某个CTradingAccount是否属于本对象工厂
	///@param	pTradingAccount	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CTradingAccount *pTradingAccount);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于AccountID的索引
	CAVLTree *pAccountIDIndex;
	
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CTradingAccount *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pTradingAccount	要加入的TradingAccount
	virtual void beforeAdd(CWriteableTradingAccount *pTradingAccount);
	
	///加入后触发
	///@param	pTradingAccount	已经加入的TradingAccount
	virtual void afterAdd(CTradingAccount *pTradingAccount);

	///更新前触发	
	///@param	pTradingAccount	被刷新的CTradingAccount
	///@param	pNewTradingAccount	新的值
	virtual void beforeUpdate(CTradingAccount *pTradingAccount, CWriteableTradingAccount *pNewTradingAccount);
	
	///更新后触发
	///@param	pTradingAccount	被刷新的CTradingAccount
	virtual void afterUpdate(CTradingAccount *pTradingAccount);
	
	///删除前触发
	///@param	pTradingAccount	要删除的CTradingAccount
	virtual void beforeRemove(CTradingAccount *pTradingAccount);
	
	///确认加入后触发
	///@param	pTradingAccount	已经加入的TradingAccount
	virtual void commitAdd(CTradingAccount *pTradingAccount);

	///确认更新后触发
	///@param	pTradingAccount	被刷新的CTradingAccount
	///@param	poldTradingAccount	原来的值
	virtual void commitUpdate(CTradingAccount *pTradingAccount, CWriteableTradingAccount *pOldTradingAccount);
	
	///确认删除后触发
	///@param	pTradingAccount	已经删除的CTradingAccount
	virtual void commitRemove(CWriteableTradingAccount *pTradingAccount);

	///所有相关的触发器
	vector<CTradingAccountActionTrigger *> *pActionTriggers;
	vector<CTradingAccountCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableTradingAccount compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountFactory是一个基本准备金账户的对象工厂。它包含了一批基本准备金账户，
///同时又建立了如下索引，以方便查询：
///	AccountIDIndex
///使用本对象工厂，可以完成对基本准备金账户的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByAccountID，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CBaseReserveAccountFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxBaseReserveAccount，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CBaseReserveAccountFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CBaseReserveAccountFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的BaseReserveAccount
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的BaseReserveAccount，文件名将根据配置文件中的定义BaseReserveAccountCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的BaseReserveAccount
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的BaseReserveAccount，文件名将根据配置文件中的定义BaseReserveAccountCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CBaseReserveAccountResource;

	///将一个CBaseReserveAccount加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pBaseReserveAccount	要加入的BaseReserveAccount
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CBaseReserveAccount *add(CWriteableBaseReserveAccount *pBaseReserveAccount, CTransaction *pTransaction=NULL);
	
	///刷新该CBaseReserveAccount的值
	///@param	pBaseReserveAccount	被刷新的CBaseReserveAccount
	///@param	pNewBaseReserveAccount	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CBaseReserveAccount *pBaseReserveAccount, CWriteableBaseReserveAccount *pNewBaseReserveAccount, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pBaseReserveAccount	  需要被刷新或者新增的CBaseReserveAccount,等于NULL表示是需要新增的
	///@param	pNewBaseReserveAccount	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CBaseReserveAccount* addOrUpdate(CBaseReserveAccount *pBaseReserveAccount, CWriteableBaseReserveAccount *pNewBaseReserveAccount, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CBaseReserveAccount，同时删除其索引
	///@param	pBaseReserveAccount	要删除的CBaseReserveAccount
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CBaseReserveAccount *pBaseReserveAccount, CTransaction *pTransaction=NULL);
	
	///获取某个CBaseReserveAccount
	///@param	pBaseReserveAccount	要读取的CBaseReserveAccount
	///@param	pTragetBaseReserveAccount	存放结果的CBaseReserveAccount
	void retrieve(CBaseReserveAccount *pBaseReserveAccount, CWriteableBaseReserveAccount *pTargetBaseReserveAccount);
	
	///获取第一个CBaseReserveAccount
	///@return	得到的第一个CBaseReserveAccount，如果没有，则返回NULL
	CBaseReserveAccount *getFirst(void);
	
	///获取下一个CBaseReserveAccount
	///@return	得到下一个CBaseReserveAccount，如果没有，则返回NULL
	CBaseReserveAccount *getNext(void);
	
	///结束获取CBaseReserveAccount
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CBaseReserveAccountActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CBaseReserveAccountActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CBaseReserveAccountCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CBaseReserveAccountCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CBaseReserveAccountIteratorBySettlementGroupID;

	///开始寻找CBaseReserveAccount
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CBaseReserveAccount，如果找不到，返回NULL
	CBaseReserveAccount *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CBaseReserveAccount，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CBaseReserveAccount，如果已经没有一个满足要求了，则返回NULL
	CBaseReserveAccount *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CBaseReserveAccount
	///@param	AccountID	账户代码
	///@return	找到的CBaseReserveAccount，如果找不到，返回NULL
	CBaseReserveAccount *findByAccountID( const CReadOnlyAccountIDType&  AccountID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CBaseReserveAccount加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pBaseReserveAccount	要加入的BaseReserveAccount
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CBaseReserveAccount *internalAdd(CWriteableBaseReserveAccount *pBaseReserveAccount, bool bNoTransaction);
	
	
	///刷新该CBaseReserveAccount的键值
	///@param	pBaseReserveAccount	被刷新的CBaseReserveAccount
	///@param	pNewBaseReserveAccount	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CBaseReserveAccount *pBaseReserveAccount, CWriteableBaseReserveAccount *pNewBaseReserveAccount, bool updateIndex,bool bNoTransaction);
	
	///删除一个CBaseReserveAccount，同时删除其索引
	///@param	pBaseReserveAccount	要删除的CBaseReserveAccount
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CBaseReserveAccount *pBaseReserveAccount, bool bNoTransaction);
/*
	///检查某个CBaseReserveAccount是否属于本对象工厂
	///@param	pBaseReserveAccount	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CBaseReserveAccount *pBaseReserveAccount);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于AccountID的索引
	CAVLTree *pAccountIDIndex;
	
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CBaseReserveAccount *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pBaseReserveAccount	要加入的BaseReserveAccount
	virtual void beforeAdd(CWriteableBaseReserveAccount *pBaseReserveAccount);
	
	///加入后触发
	///@param	pBaseReserveAccount	已经加入的BaseReserveAccount
	virtual void afterAdd(CBaseReserveAccount *pBaseReserveAccount);

	///更新前触发	
	///@param	pBaseReserveAccount	被刷新的CBaseReserveAccount
	///@param	pNewBaseReserveAccount	新的值
	virtual void beforeUpdate(CBaseReserveAccount *pBaseReserveAccount, CWriteableBaseReserveAccount *pNewBaseReserveAccount);
	
	///更新后触发
	///@param	pBaseReserveAccount	被刷新的CBaseReserveAccount
	virtual void afterUpdate(CBaseReserveAccount *pBaseReserveAccount);
	
	///删除前触发
	///@param	pBaseReserveAccount	要删除的CBaseReserveAccount
	virtual void beforeRemove(CBaseReserveAccount *pBaseReserveAccount);
	
	///确认加入后触发
	///@param	pBaseReserveAccount	已经加入的BaseReserveAccount
	virtual void commitAdd(CBaseReserveAccount *pBaseReserveAccount);

	///确认更新后触发
	///@param	pBaseReserveAccount	被刷新的CBaseReserveAccount
	///@param	poldBaseReserveAccount	原来的值
	virtual void commitUpdate(CBaseReserveAccount *pBaseReserveAccount, CWriteableBaseReserveAccount *pOldBaseReserveAccount);
	
	///确认删除后触发
	///@param	pBaseReserveAccount	已经删除的CBaseReserveAccount
	virtual void commitRemove(CWriteableBaseReserveAccount *pBaseReserveAccount);

	///所有相关的触发器
	vector<CBaseReserveAccountActionTrigger *> *pActionTriggers;
	vector<CBaseReserveAccountCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableBaseReserveAccount compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CPartPositionFactory是一个会员持仓的对象工厂。它包含了一批会员持仓，
///同时又建立了如下索引，以方便查询：
///	InstrumentIndex
///	PartInstrumentIndex
///使用本对象工厂，可以完成对会员持仓的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByPartAndInstrument，唯一找到对象
///		使用startFindStartByInstrument，findNextStartByInstrument和endFindStartByInstrument完成查询操作
///		使用startFindStartByParticipant，findNextStartByParticipant和endFindStartByParticipant完成查询操作
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CPartPositionFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxPartPosition，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CPartPositionFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CPartPositionFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的PartPosition
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的PartPosition，文件名将根据配置文件中的定义PartPositionCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的PartPosition
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的PartPosition，文件名将根据配置文件中的定义PartPositionCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CPartPositionResource;

	///将一个CPartPosition加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pPartPosition	要加入的PartPosition
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CPartPosition *add(CWriteablePartPosition *pPartPosition, CTransaction *pTransaction=NULL);
	
	///刷新该CPartPosition的值
	///@param	pPartPosition	被刷新的CPartPosition
	///@param	pNewPartPosition	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CPartPosition *pPartPosition, CWriteablePartPosition *pNewPartPosition, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pPartPosition	  需要被刷新或者新增的CPartPosition,等于NULL表示是需要新增的
	///@param	pNewPartPosition	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CPartPosition* addOrUpdate(CPartPosition *pPartPosition, CWriteablePartPosition *pNewPartPosition, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CPartPosition，同时删除其索引
	///@param	pPartPosition	要删除的CPartPosition
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CPartPosition *pPartPosition, CTransaction *pTransaction=NULL);
	
	///获取某个CPartPosition
	///@param	pPartPosition	要读取的CPartPosition
	///@param	pTragetPartPosition	存放结果的CPartPosition
	void retrieve(CPartPosition *pPartPosition, CWriteablePartPosition *pTargetPartPosition);
	
	///获取第一个CPartPosition
	///@return	得到的第一个CPartPosition，如果没有，则返回NULL
	CPartPosition *getFirst(void);
	
	///获取下一个CPartPosition
	///@return	得到下一个CPartPosition，如果没有，则返回NULL
	CPartPosition *getNext(void);
	
	///结束获取CPartPosition
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CPartPositionActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CPartPositionActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CPartPositionCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CPartPositionCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///寻找CPartPosition
	///@param	ParticipantID	会员号
	///@param	InstrumentID	合约号
	///@param	PosiDirection	多空方向
	///@param	HedgeFlag	投保标志
	///@param	TradingRole	交易角色
	///@return	找到的CPartPosition，如果找不到，返回NULL
	CPartPosition *findByPartAndInstrument( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyPosiDirectionType&  PosiDirection,  const CReadOnlyHedgeFlagType&  HedgeFlag,  const CReadOnlyTradingRoleType&  TradingRole);



	friend class CPartPositionIteratorStartByInstrument;

	///开始寻找CPartPosition
	///@param	InstrumentID	合约号
	///@return	满足条件的地一个CPartPosition，如果找不到，返回NULL
	CPartPosition *startFindStartByInstrument( const CReadOnlyInstrumentIDType& InstrumentID);

	///寻找下一个符合条件的CPartPosition，必须在startFindStartByInstrument以后，endFindStartByInstrument之前叫用
	///@return	下一个满足条件CPartPosition，如果已经没有一个满足要求了，则返回NULL
	CPartPosition *findNextStartByInstrument(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindStartByInstrument(void);

	friend class CPartPositionIteratorStartByParticipant;

	///开始寻找CPartPosition
	///@param	ParticipantID	会员号
	///@return	满足条件的地一个CPartPosition，如果找不到，返回NULL
	CPartPosition *startFindStartByParticipant( const CReadOnlyParticipantIDType& ParticipantID);

	///寻找下一个符合条件的CPartPosition，必须在startFindStartByParticipant以后，endFindStartByParticipant之前叫用
	///@return	下一个满足条件CPartPosition，如果已经没有一个满足要求了，则返回NULL
	CPartPosition *findNextStartByParticipant(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindStartByParticipant(void);

	friend class CPartPositionIteratorBySettlementGroupID;

	///开始寻找CPartPosition
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CPartPosition，如果找不到，返回NULL
	CPartPosition *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CPartPosition，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CPartPosition，如果已经没有一个满足要求了，则返回NULL
	CPartPosition *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CPartPosition加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pPartPosition	要加入的PartPosition
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CPartPosition *internalAdd(CWriteablePartPosition *pPartPosition, bool bNoTransaction);
	
	
	///刷新该CPartPosition的键值
	///@param	pPartPosition	被刷新的CPartPosition
	///@param	pNewPartPosition	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CPartPosition *pPartPosition, CWriteablePartPosition *pNewPartPosition, bool updateIndex,bool bNoTransaction);
	
	///删除一个CPartPosition，同时删除其索引
	///@param	pPartPosition	要删除的CPartPosition
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CPartPosition *pPartPosition, bool bNoTransaction);
/*
	///检查某个CPartPosition是否属于本对象工厂
	///@param	pPartPosition	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CPartPosition *pPartPosition);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于InstrumentID+ParticipantID+PosiDirection+HedgeFlag+TradingRole的索引
	CAVLTree *pInstrumentIndex;
	///基于ParticipantID+InstrumentID+PosiDirection+HedgeFlag+TradingRole的索引
	CAVLTree *pPartInstrumentIndex;
	
	///基于PartAndInstrument的hash索引
	CHashIndex *pPartAndInstrumentHashIndex;
	
	///按照InstrumentID检索时，存储的查询参数
	CInstrumentIDType queryInstrumentIDInSearchStartByInstrument;
	
	///按照InstrumentID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchStartByInstrument;
	///按照ParticipantID检索时，存储的查询参数
	CParticipantIDType queryParticipantIDInSearchStartByParticipant;
	
	///按照ParticipantID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchStartByParticipant;
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CPartPosition *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pPartPosition	要加入的PartPosition
	virtual void beforeAdd(CWriteablePartPosition *pPartPosition);
	
	///加入后触发
	///@param	pPartPosition	已经加入的PartPosition
	virtual void afterAdd(CPartPosition *pPartPosition);

	///更新前触发	
	///@param	pPartPosition	被刷新的CPartPosition
	///@param	pNewPartPosition	新的值
	virtual void beforeUpdate(CPartPosition *pPartPosition, CWriteablePartPosition *pNewPartPosition);
	
	///更新后触发
	///@param	pPartPosition	被刷新的CPartPosition
	virtual void afterUpdate(CPartPosition *pPartPosition);
	
	///删除前触发
	///@param	pPartPosition	要删除的CPartPosition
	virtual void beforeRemove(CPartPosition *pPartPosition);
	
	///确认加入后触发
	///@param	pPartPosition	已经加入的PartPosition
	virtual void commitAdd(CPartPosition *pPartPosition);

	///确认更新后触发
	///@param	pPartPosition	被刷新的CPartPosition
	///@param	poldPartPosition	原来的值
	virtual void commitUpdate(CPartPosition *pPartPosition, CWriteablePartPosition *pOldPartPosition);
	
	///确认删除后触发
	///@param	pPartPosition	已经删除的CPartPosition
	virtual void commitRemove(CWriteablePartPosition *pPartPosition);

	///所有相关的触发器
	vector<CPartPositionActionTrigger *> *pActionTriggers;
	vector<CPartPositionCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteablePartPosition compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CClientPositionFactory是一个客户持仓的对象工厂。它包含了一批客户持仓，
///同时又建立了如下索引，以方便查询：
///	PartClientAndInstumentIndex
///	ClientAndInstumentIndex
///	InstumentIndex
///使用本对象工厂，可以完成对客户持仓的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByPartClientAndInstrument，唯一找到对象
///		使用startFindByClientAndInstrument，findNextByClientAndInstrument和endFindByClientAndInstrument完成查询操作
///		使用startFindStartByParticipant，findNextStartByParticipant和endFindStartByParticipant完成查询操作
///		使用startFindStartByClient，findNextStartByClient和endFindStartByClient完成查询操作
///		使用startFindStartByInstrument，findNextStartByInstrument和endFindStartByInstrument完成查询操作
///		使用startFindByInstrumentID，findNextByInstrumentID和endFindByInstrumentID完成查询操作
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CClientPositionFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxClientPosition，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CClientPositionFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CClientPositionFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的ClientPosition
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的ClientPosition，文件名将根据配置文件中的定义ClientPositionCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的ClientPosition
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的ClientPosition，文件名将根据配置文件中的定义ClientPositionCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CClientPositionResource;

	///将一个CClientPosition加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pClientPosition	要加入的ClientPosition
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CClientPosition *add(CWriteableClientPosition *pClientPosition, CTransaction *pTransaction=NULL);
	
	///刷新该CClientPosition的值
	///@param	pClientPosition	被刷新的CClientPosition
	///@param	pNewClientPosition	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CClientPosition *pClientPosition, CWriteableClientPosition *pNewClientPosition, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pClientPosition	  需要被刷新或者新增的CClientPosition,等于NULL表示是需要新增的
	///@param	pNewClientPosition	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CClientPosition* addOrUpdate(CClientPosition *pClientPosition, CWriteableClientPosition *pNewClientPosition, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CClientPosition，同时删除其索引
	///@param	pClientPosition	要删除的CClientPosition
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CClientPosition *pClientPosition, CTransaction *pTransaction=NULL);
	
	///获取某个CClientPosition
	///@param	pClientPosition	要读取的CClientPosition
	///@param	pTragetClientPosition	存放结果的CClientPosition
	void retrieve(CClientPosition *pClientPosition, CWriteableClientPosition *pTargetClientPosition);
	
	///获取第一个CClientPosition
	///@return	得到的第一个CClientPosition，如果没有，则返回NULL
	CClientPosition *getFirst(void);
	
	///获取下一个CClientPosition
	///@return	得到下一个CClientPosition，如果没有，则返回NULL
	CClientPosition *getNext(void);
	
	///结束获取CClientPosition
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CClientPositionActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CClientPositionActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CClientPositionCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CClientPositionCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///构造所有对应的信用额度的指针
	///@param	pFactory	构造对应的信用额度的指针时，寻找的对象工厂
	void linkAllCreditLimit(CCreditLimitFactory *pFactory);
	
	///构造所有对应的会员角色帐号的指针
	///@param	pFactory	构造对应的会员角色帐号的指针时，寻找的对象工厂
	void linkAllPartRoleAccount(CPartRoleAccountFactory *pFactory);
	
	///寻找CClientPosition
	///@param	ParticipantID	会员号
	///@param	ClientID	客户号
	///@param	InstrumentID	合约号
	///@param	PosiDirection	多空方向
	///@param	HedgeFlag	投保标志
	///@return	找到的CClientPosition，如果找不到，返回NULL
	CClientPosition *findByPartClientAndInstrument( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyClientIDType&  ClientID,  const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyPosiDirectionType&  PosiDirection,  const CReadOnlyHedgeFlagType&  HedgeFlag);



	friend class CClientPositionIteratorByClientAndInstrument;

	///开始寻找CClientPosition
	///@param	ClientID	客户号
	///@param	InstrumentID	合约号
	///@param	PosiDirection	多空方向
	///@param	HedgeFlag	投保标志
	///@return	满足条件的地一个CClientPosition，如果找不到，返回NULL
	CClientPosition *startFindByClientAndInstrument( const CReadOnlyClientIDType& ClientID,  const CReadOnlyInstrumentIDType& InstrumentID,  const CReadOnlyPosiDirectionType& PosiDirection,  const CReadOnlyHedgeFlagType& HedgeFlag);

	///寻找下一个符合条件的CClientPosition，必须在startFindByClientAndInstrument以后，endFindByClientAndInstrument之前叫用
	///@return	下一个满足条件CClientPosition，如果已经没有一个满足要求了，则返回NULL
	CClientPosition *findNextByClientAndInstrument(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByClientAndInstrument(void);

	friend class CClientPositionIteratorStartByParticipant;

	///开始寻找CClientPosition
	///@param	ParticipantID	会员号
	///@return	满足条件的地一个CClientPosition，如果找不到，返回NULL
	CClientPosition *startFindStartByParticipant( const CReadOnlyParticipantIDType& ParticipantID);

	///寻找下一个符合条件的CClientPosition，必须在startFindStartByParticipant以后，endFindStartByParticipant之前叫用
	///@return	下一个满足条件CClientPosition，如果已经没有一个满足要求了，则返回NULL
	CClientPosition *findNextStartByParticipant(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindStartByParticipant(void);

	friend class CClientPositionIteratorStartByClient;

	///开始寻找CClientPosition
	///@param	ClientID	客户号
	///@return	满足条件的地一个CClientPosition，如果找不到，返回NULL
	CClientPosition *startFindStartByClient( const CReadOnlyClientIDType& ClientID);

	///寻找下一个符合条件的CClientPosition，必须在startFindStartByClient以后，endFindStartByClient之前叫用
	///@return	下一个满足条件CClientPosition，如果已经没有一个满足要求了，则返回NULL
	CClientPosition *findNextStartByClient(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindStartByClient(void);

	friend class CClientPositionIteratorStartByInstrument;

	///开始寻找CClientPosition
	///@param	InstrumentID	合约号
	///@return	满足条件的地一个CClientPosition，如果找不到，返回NULL
	CClientPosition *startFindStartByInstrument( const CReadOnlyInstrumentIDType& InstrumentID);

	///寻找下一个符合条件的CClientPosition，必须在startFindStartByInstrument以后，endFindStartByInstrument之前叫用
	///@return	下一个满足条件CClientPosition，如果已经没有一个满足要求了，则返回NULL
	CClientPosition *findNextStartByInstrument(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindStartByInstrument(void);

	friend class CClientPositionIteratorByInstrumentID;

	///开始寻找CClientPosition
	///@param	InstrumentID	合约号
	///@return	满足条件的地一个CClientPosition，如果找不到，返回NULL
	CClientPosition *startFindByInstrumentID( const CReadOnlyInstrumentIDType& InstrumentID);

	///寻找下一个符合条件的CClientPosition，必须在startFindByInstrumentID以后，endFindByInstrumentID之前叫用
	///@return	下一个满足条件CClientPosition，如果已经没有一个满足要求了，则返回NULL
	CClientPosition *findNextByInstrumentID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByInstrumentID(void);

	friend class CClientPositionIteratorBySettlementGroupID;

	///开始寻找CClientPosition
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CClientPosition，如果找不到，返回NULL
	CClientPosition *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CClientPosition，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CClientPosition，如果已经没有一个满足要求了，则返回NULL
	CClientPosition *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CClientPosition加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pClientPosition	要加入的ClientPosition
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CClientPosition *internalAdd(CWriteableClientPosition *pClientPosition, bool bNoTransaction);
	
	
	///刷新该CClientPosition的键值
	///@param	pClientPosition	被刷新的CClientPosition
	///@param	pNewClientPosition	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CClientPosition *pClientPosition, CWriteableClientPosition *pNewClientPosition, bool updateIndex,bool bNoTransaction);
	
	///删除一个CClientPosition，同时删除其索引
	///@param	pClientPosition	要删除的CClientPosition
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CClientPosition *pClientPosition, bool bNoTransaction);
/*
	///检查某个CClientPosition是否属于本对象工厂
	///@param	pClientPosition	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CClientPosition *pClientPosition);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ParticipantID+ClientID+InstrumentID+PosiDirection+HedgeFlag的索引
	CAVLTree *pPartClientAndInstumentIndex;
	///基于ClientID+ParticipantID+InstrumentID+PosiDirection+HedgeFlag的索引
	CAVLTree *pClientAndInstumentIndex;
	///基于InstrumentID+ParticipantID+ClientID+PosiDirection+HedgeFlag的索引
	CAVLTree *pInstumentIndex;
	
	///基于ClientAndInstrument的hash索引
	CHashIndex *pClientAndInstrumentHashIndex;
	
	///按照ClientID，InstrumentID，PosiDirection，HedgeFlag检索时，存储的查询参数
	CClientIDType queryClientIDInSearchByClientAndInstrument;
	CInstrumentIDType queryInstrumentIDInSearchByClientAndInstrument;
	CPosiDirectionType queryPosiDirectionInSearchByClientAndInstrument;
	CHedgeFlagType queryHedgeFlagInSearchByClientAndInstrument;
	
	///按照ClientID，InstrumentID，PosiDirection，HedgeFlag检索时，存储最后一次找到的索引节点
	CHashIndexNode *pLastFoundInSearchByClientAndInstrument;
	///按照ParticipantID检索时，存储的查询参数
	CParticipantIDType queryParticipantIDInSearchStartByParticipant;
	
	///按照ParticipantID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchStartByParticipant;
	///按照ClientID检索时，存储的查询参数
	CClientIDType queryClientIDInSearchStartByClient;
	
	///按照ClientID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchStartByClient;
	///按照InstrumentID检索时，存储的查询参数
	CInstrumentIDType queryInstrumentIDInSearchStartByInstrument;
	
	///按照InstrumentID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchStartByInstrument;
	///按照InstrumentID检索时，存储的查询参数
	CInstrumentIDType queryInstrumentIDInSearchByInstrumentID;
	
	///按照InstrumentID检索时，存储最后一次找到的索引节点
	CClientPosition *pLastFoundInSearchByInstrumentID;
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CClientPosition *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pClientPosition	要加入的ClientPosition
	virtual void beforeAdd(CWriteableClientPosition *pClientPosition);
	
	///加入后触发
	///@param	pClientPosition	已经加入的ClientPosition
	virtual void afterAdd(CClientPosition *pClientPosition);

	///更新前触发	
	///@param	pClientPosition	被刷新的CClientPosition
	///@param	pNewClientPosition	新的值
	virtual void beforeUpdate(CClientPosition *pClientPosition, CWriteableClientPosition *pNewClientPosition);
	
	///更新后触发
	///@param	pClientPosition	被刷新的CClientPosition
	virtual void afterUpdate(CClientPosition *pClientPosition);
	
	///删除前触发
	///@param	pClientPosition	要删除的CClientPosition
	virtual void beforeRemove(CClientPosition *pClientPosition);
	
	///确认加入后触发
	///@param	pClientPosition	已经加入的ClientPosition
	virtual void commitAdd(CClientPosition *pClientPosition);

	///确认更新后触发
	///@param	pClientPosition	被刷新的CClientPosition
	///@param	poldClientPosition	原来的值
	virtual void commitUpdate(CClientPosition *pClientPosition, CWriteableClientPosition *pOldClientPosition);
	
	///确认删除后触发
	///@param	pClientPosition	已经删除的CClientPosition
	virtual void commitRemove(CWriteableClientPosition *pClientPosition);

	///所有相关的触发器
	vector<CClientPositionActionTrigger *> *pActionTriggers;
	vector<CClientPositionCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableClientPosition compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CHedgeVolumeFactory是一个保值额度量的对象工厂。它包含了一批保值额度量，
///同时又建立了如下索引，以方便查询：
///	PartClientAndInstrumentIndex
///使用本对象工厂，可以完成对保值额度量的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByInstrumentPartClient，唯一找到对象
///		使用startFindStartByPartClientAndInstrument，findNextStartByPartClientAndInstrument和endFindStartByPartClientAndInstrument完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumeFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CHedgeVolumeFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxHedgeVolume，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CHedgeVolumeFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CHedgeVolumeFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的HedgeVolume
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的HedgeVolume，文件名将根据配置文件中的定义HedgeVolumeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的HedgeVolume
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的HedgeVolume，文件名将根据配置文件中的定义HedgeVolumeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CHedgeVolumeResource;

	///将一个CHedgeVolume加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pHedgeVolume	要加入的HedgeVolume
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CHedgeVolume *add(CWriteableHedgeVolume *pHedgeVolume, CTransaction *pTransaction=NULL);
	
	///刷新该CHedgeVolume的值
	///@param	pHedgeVolume	被刷新的CHedgeVolume
	///@param	pNewHedgeVolume	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CHedgeVolume *pHedgeVolume, CWriteableHedgeVolume *pNewHedgeVolume, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pHedgeVolume	  需要被刷新或者新增的CHedgeVolume,等于NULL表示是需要新增的
	///@param	pNewHedgeVolume	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CHedgeVolume* addOrUpdate(CHedgeVolume *pHedgeVolume, CWriteableHedgeVolume *pNewHedgeVolume, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CHedgeVolume，同时删除其索引
	///@param	pHedgeVolume	要删除的CHedgeVolume
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CHedgeVolume *pHedgeVolume, CTransaction *pTransaction=NULL);
	
	///获取某个CHedgeVolume
	///@param	pHedgeVolume	要读取的CHedgeVolume
	///@param	pTragetHedgeVolume	存放结果的CHedgeVolume
	void retrieve(CHedgeVolume *pHedgeVolume, CWriteableHedgeVolume *pTargetHedgeVolume);
	
	///获取第一个CHedgeVolume
	///@return	得到的第一个CHedgeVolume，如果没有，则返回NULL
	CHedgeVolume *getFirst(void);
	
	///获取下一个CHedgeVolume
	///@return	得到下一个CHedgeVolume，如果没有，则返回NULL
	CHedgeVolume *getNext(void);
	
	///结束获取CHedgeVolume
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CHedgeVolumeActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CHedgeVolumeActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CHedgeVolumeCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CHedgeVolumeCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CHedgeVolumeIteratorBySettlementGroupID;

	///开始寻找CHedgeVolume
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CHedgeVolume，如果找不到，返回NULL
	CHedgeVolume *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CHedgeVolume，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CHedgeVolume，如果已经没有一个满足要求了，则返回NULL
	CHedgeVolume *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CHedgeVolume
	///@param	InstrumentID	合约代码
	///@param	ParticipantID	会员编号
	///@param	ClientID	客户编号
	///@return	找到的CHedgeVolume，如果找不到，返回NULL
	CHedgeVolume *findByInstrumentPartClient( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyClientIDType&  ClientID);



	friend class CHedgeVolumeIteratorStartByPartClientAndInstrument;

	///开始寻找CHedgeVolume
	///@param	ParticipantID	会员编号
	///@param	ClientID	客户编号
	///@param	InstrumentID	合约代码
	///@return	满足条件的地一个CHedgeVolume，如果找不到，返回NULL
	CHedgeVolume *startFindStartByPartClientAndInstrument( const CReadOnlyParticipantIDType& ParticipantID,  const CReadOnlyClientIDType& ClientID,  const CReadOnlyInstrumentIDType& InstrumentID);

	///寻找下一个符合条件的CHedgeVolume，必须在startFindStartByPartClientAndInstrument以后，endFindStartByPartClientAndInstrument之前叫用
	///@return	下一个满足条件CHedgeVolume，如果已经没有一个满足要求了，则返回NULL
	CHedgeVolume *findNextStartByPartClientAndInstrument(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindStartByPartClientAndInstrument(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CHedgeVolume加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pHedgeVolume	要加入的HedgeVolume
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CHedgeVolume *internalAdd(CWriteableHedgeVolume *pHedgeVolume, bool bNoTransaction);
	
	
	///刷新该CHedgeVolume的键值
	///@param	pHedgeVolume	被刷新的CHedgeVolume
	///@param	pNewHedgeVolume	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CHedgeVolume *pHedgeVolume, CWriteableHedgeVolume *pNewHedgeVolume, bool updateIndex,bool bNoTransaction);
	
	///删除一个CHedgeVolume，同时删除其索引
	///@param	pHedgeVolume	要删除的CHedgeVolume
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CHedgeVolume *pHedgeVolume, bool bNoTransaction);
/*
	///检查某个CHedgeVolume是否属于本对象工厂
	///@param	pHedgeVolume	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CHedgeVolume *pHedgeVolume);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ParticipantID+ClientID+InstrumentID的索引
	CAVLTree *pPartClientAndInstrumentIndex;
	
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CHedgeVolume *pLastFoundInSearchBySettlementGroupID;
	///按照ParticipantID，ClientID，InstrumentID检索时，存储的查询参数
	CParticipantIDType queryParticipantIDInSearchStartByPartClientAndInstrument;
	CClientIDType queryClientIDInSearchStartByPartClientAndInstrument;
	CInstrumentIDType queryInstrumentIDInSearchStartByPartClientAndInstrument;
	
	///按照ParticipantID，ClientID，InstrumentID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchStartByPartClientAndInstrument;
	
	///加入前触发
	///@param	pHedgeVolume	要加入的HedgeVolume
	virtual void beforeAdd(CWriteableHedgeVolume *pHedgeVolume);
	
	///加入后触发
	///@param	pHedgeVolume	已经加入的HedgeVolume
	virtual void afterAdd(CHedgeVolume *pHedgeVolume);

	///更新前触发	
	///@param	pHedgeVolume	被刷新的CHedgeVolume
	///@param	pNewHedgeVolume	新的值
	virtual void beforeUpdate(CHedgeVolume *pHedgeVolume, CWriteableHedgeVolume *pNewHedgeVolume);
	
	///更新后触发
	///@param	pHedgeVolume	被刷新的CHedgeVolume
	virtual void afterUpdate(CHedgeVolume *pHedgeVolume);
	
	///删除前触发
	///@param	pHedgeVolume	要删除的CHedgeVolume
	virtual void beforeRemove(CHedgeVolume *pHedgeVolume);
	
	///确认加入后触发
	///@param	pHedgeVolume	已经加入的HedgeVolume
	virtual void commitAdd(CHedgeVolume *pHedgeVolume);

	///确认更新后触发
	///@param	pHedgeVolume	被刷新的CHedgeVolume
	///@param	poldHedgeVolume	原来的值
	virtual void commitUpdate(CHedgeVolume *pHedgeVolume, CWriteableHedgeVolume *pOldHedgeVolume);
	
	///确认删除后触发
	///@param	pHedgeVolume	已经删除的CHedgeVolume
	virtual void commitRemove(CWriteableHedgeVolume *pHedgeVolume);

	///所有相关的触发器
	vector<CHedgeVolumeActionTrigger *> *pActionTriggers;
	vector<CHedgeVolumeCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableHedgeVolume compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CRemainOrderFactory是一个历史报单的对象工厂。它包含了一批历史报单，
///同时又建立了如下索引，以方便查询：
///	InstrumentIDIndex
///使用本对象工厂，可以完成对历史报单的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用startFindByInstrumentID，findNextByInstrumentID和endFindByInstrumentID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CRemainOrderFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxRemainOrder，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CRemainOrderFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CRemainOrderFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的RemainOrder
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的RemainOrder，文件名将根据配置文件中的定义RemainOrderCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的RemainOrder
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的RemainOrder，文件名将根据配置文件中的定义RemainOrderCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CRemainOrderResource;

	///将一个CRemainOrder加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pRemainOrder	要加入的RemainOrder
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CRemainOrder *add(CWriteableRemainOrder *pRemainOrder, CTransaction *pTransaction=NULL);
	
	///刷新该CRemainOrder的值
	///@param	pRemainOrder	被刷新的CRemainOrder
	///@param	pNewRemainOrder	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CRemainOrder *pRemainOrder, CWriteableRemainOrder *pNewRemainOrder, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pRemainOrder	  需要被刷新或者新增的CRemainOrder,等于NULL表示是需要新增的
	///@param	pNewRemainOrder	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CRemainOrder* addOrUpdate(CRemainOrder *pRemainOrder, CWriteableRemainOrder *pNewRemainOrder, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CRemainOrder，同时删除其索引
	///@param	pRemainOrder	要删除的CRemainOrder
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CRemainOrder *pRemainOrder, CTransaction *pTransaction=NULL);
	
	///获取某个CRemainOrder
	///@param	pRemainOrder	要读取的CRemainOrder
	///@param	pTragetRemainOrder	存放结果的CRemainOrder
	void retrieve(CRemainOrder *pRemainOrder, CWriteableRemainOrder *pTargetRemainOrder);
	
	///获取第一个CRemainOrder
	///@return	得到的第一个CRemainOrder，如果没有，则返回NULL
	CRemainOrder *getFirst(void);
	
	///获取下一个CRemainOrder
	///@return	得到下一个CRemainOrder，如果没有，则返回NULL
	CRemainOrder *getNext(void);
	
	///结束获取CRemainOrder
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CRemainOrderActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CRemainOrderActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CRemainOrderCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CRemainOrderCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CRemainOrderIteratorBySettlementGroupID;

	///开始寻找CRemainOrder
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CRemainOrder，如果找不到，返回NULL
	CRemainOrder *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CRemainOrder，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CRemainOrder，如果已经没有一个满足要求了，则返回NULL
	CRemainOrder *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	friend class CRemainOrderIteratorByInstrumentID;

	///开始寻找CRemainOrder
	///@param	InstrumentID	合约编号
	///@return	满足条件的地一个CRemainOrder，如果找不到，返回NULL
	CRemainOrder *startFindByInstrumentID( const CReadOnlyInstrumentIDType& InstrumentID);

	///寻找下一个符合条件的CRemainOrder，必须在startFindByInstrumentID以后，endFindByInstrumentID之前叫用
	///@return	下一个满足条件CRemainOrder，如果已经没有一个满足要求了，则返回NULL
	CRemainOrder *findNextByInstrumentID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByInstrumentID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CRemainOrder加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pRemainOrder	要加入的RemainOrder
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CRemainOrder *internalAdd(CWriteableRemainOrder *pRemainOrder, bool bNoTransaction);
	
	
	///刷新该CRemainOrder的键值
	///@param	pRemainOrder	被刷新的CRemainOrder
	///@param	pNewRemainOrder	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CRemainOrder *pRemainOrder, CWriteableRemainOrder *pNewRemainOrder, bool updateIndex,bool bNoTransaction);
	
	///删除一个CRemainOrder，同时删除其索引
	///@param	pRemainOrder	要删除的CRemainOrder
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CRemainOrder *pRemainOrder, bool bNoTransaction);
/*
	///检查某个CRemainOrder是否属于本对象工厂
	///@param	pRemainOrder	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CRemainOrder *pRemainOrder);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于InstrumentID的索引
	CAVLTree *pInstrumentIDIndex;
	
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CRemainOrder *pLastFoundInSearchBySettlementGroupID;
	///按照InstrumentID检索时，存储的查询参数
	CInstrumentIDType queryInstrumentIDInSearchByInstrumentID;
	
	///按照InstrumentID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByInstrumentID;
	
	///加入前触发
	///@param	pRemainOrder	要加入的RemainOrder
	virtual void beforeAdd(CWriteableRemainOrder *pRemainOrder);
	
	///加入后触发
	///@param	pRemainOrder	已经加入的RemainOrder
	virtual void afterAdd(CRemainOrder *pRemainOrder);

	///更新前触发	
	///@param	pRemainOrder	被刷新的CRemainOrder
	///@param	pNewRemainOrder	新的值
	virtual void beforeUpdate(CRemainOrder *pRemainOrder, CWriteableRemainOrder *pNewRemainOrder);
	
	///更新后触发
	///@param	pRemainOrder	被刷新的CRemainOrder
	virtual void afterUpdate(CRemainOrder *pRemainOrder);
	
	///删除前触发
	///@param	pRemainOrder	要删除的CRemainOrder
	virtual void beforeRemove(CRemainOrder *pRemainOrder);
	
	///确认加入后触发
	///@param	pRemainOrder	已经加入的RemainOrder
	virtual void commitAdd(CRemainOrder *pRemainOrder);

	///确认更新后触发
	///@param	pRemainOrder	被刷新的CRemainOrder
	///@param	poldRemainOrder	原来的值
	virtual void commitUpdate(CRemainOrder *pRemainOrder, CWriteableRemainOrder *pOldRemainOrder);
	
	///确认删除后触发
	///@param	pRemainOrder	已经删除的CRemainOrder
	virtual void commitRemove(CWriteableRemainOrder *pRemainOrder);

	///所有相关的触发器
	vector<CRemainOrderActionTrigger *> *pActionTriggers;
	vector<CRemainOrderCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableRemainOrder compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataFactory是一个行情的对象工厂。它包含了一批行情，
///同时又建立了如下索引，以方便查询：
///	InstrumentIDIndex
///使用本对象工厂，可以完成对行情的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByInstrumentID，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CMarketDataFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxMarketData，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CMarketDataFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CMarketDataFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的MarketData
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的MarketData，文件名将根据配置文件中的定义MarketDataCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的MarketData
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的MarketData，文件名将根据配置文件中的定义MarketDataCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CMarketDataResource;

	///将一个CMarketData加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pMarketData	要加入的MarketData
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CMarketData *add(CWriteableMarketData *pMarketData, CTransaction *pTransaction=NULL);
	
	///刷新该CMarketData的值
	///@param	pMarketData	被刷新的CMarketData
	///@param	pNewMarketData	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CMarketData *pMarketData, CWriteableMarketData *pNewMarketData, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pMarketData	  需要被刷新或者新增的CMarketData,等于NULL表示是需要新增的
	///@param	pNewMarketData	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CMarketData* addOrUpdate(CMarketData *pMarketData, CWriteableMarketData *pNewMarketData, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CMarketData，同时删除其索引
	///@param	pMarketData	要删除的CMarketData
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CMarketData *pMarketData, CTransaction *pTransaction=NULL);
	
	///获取某个CMarketData
	///@param	pMarketData	要读取的CMarketData
	///@param	pTragetMarketData	存放结果的CMarketData
	void retrieve(CMarketData *pMarketData, CWriteableMarketData *pTargetMarketData);
	
	///获取第一个CMarketData
	///@return	得到的第一个CMarketData，如果没有，则返回NULL
	CMarketData *getFirst(void);
	
	///获取下一个CMarketData
	///@return	得到下一个CMarketData，如果没有，则返回NULL
	CMarketData *getNext(void);
	
	///结束获取CMarketData
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CMarketDataActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CMarketDataActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CMarketDataCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CMarketDataCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CMarketDataIteratorBySettlementGroupID;

	///开始寻找CMarketData
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CMarketData，如果找不到，返回NULL
	CMarketData *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CMarketData，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CMarketData，如果已经没有一个满足要求了，则返回NULL
	CMarketData *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CMarketData
	///@param	InstrumentID	合约代码
	///@return	找到的CMarketData，如果找不到，返回NULL
	CMarketData *findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID);

	///根据主码寻找
	///@param	InstrumentID	合约代码
	///@return	找到的CMarketData，如果找不到，返回NULL
	CMarketData *findByPK( const CReadOnlyInstrumentIDType&  InstrumentID);
	
	///根据主键寻找CMarketData
	///@param	pMarketData	要找的值
	///@return	找到的CMarketData，如果找不到，返回NULL
	CMarketData *findByPK(CWriteableMarketData *pMarketData);

	///根据主键获取CMarketData
	///@param	pMarketData	要获取的值，同时用于存放返回的结果
	///@return	找到的CMarketData，如果找不到，返回NULL
	bool retrieveByPK(CWriteableMarketData *pMarketData);

	///根据主键增加新的CMarketData
	///@param	pMarketData	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	返回插入的CMarketData，如果插入失败，则返回NULL
	CMarketData *addByPK(CWriteableMarketData *pMarketData, CTransaction *pTransaction=NULL);

	///根据主键更新CMarketData的值
	///@param	pMarketData	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	///@return	true表示成功，false表示失败
	bool updateByPK(CWriteableMarketData *pMarketData, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///根据主键删除CMarketData
	///@param	pMarketData	要删除的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	true表示成功，false表示失败
	bool removeByPK(CWriteableMarketData *pMarketData, CTransaction *pTransaction=NULL);


private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CMarketData加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pMarketData	要加入的MarketData
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CMarketData *internalAdd(CWriteableMarketData *pMarketData, bool bNoTransaction);
	
	
	///刷新该CMarketData的键值
	///@param	pMarketData	被刷新的CMarketData
	///@param	pNewMarketData	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CMarketData *pMarketData, CWriteableMarketData *pNewMarketData, bool updateIndex,bool bNoTransaction);
	
	///删除一个CMarketData，同时删除其索引
	///@param	pMarketData	要删除的CMarketData
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CMarketData *pMarketData, bool bNoTransaction);
/*
	///检查某个CMarketData是否属于本对象工厂
	///@param	pMarketData	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CMarketData *pMarketData);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于InstrumentID的索引
	CAVLTree *pInstrumentIDIndex;
	
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CMarketData *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pMarketData	要加入的MarketData
	virtual void beforeAdd(CWriteableMarketData *pMarketData);
	
	///加入后触发
	///@param	pMarketData	已经加入的MarketData
	virtual void afterAdd(CMarketData *pMarketData);

	///更新前触发	
	///@param	pMarketData	被刷新的CMarketData
	///@param	pNewMarketData	新的值
	virtual void beforeUpdate(CMarketData *pMarketData, CWriteableMarketData *pNewMarketData);
	
	///更新后触发
	///@param	pMarketData	被刷新的CMarketData
	virtual void afterUpdate(CMarketData *pMarketData);
	
	///删除前触发
	///@param	pMarketData	要删除的CMarketData
	virtual void beforeRemove(CMarketData *pMarketData);
	
	///确认加入后触发
	///@param	pMarketData	已经加入的MarketData
	virtual void commitAdd(CMarketData *pMarketData);

	///确认更新后触发
	///@param	pMarketData	被刷新的CMarketData
	///@param	poldMarketData	原来的值
	virtual void commitUpdate(CMarketData *pMarketData, CWriteableMarketData *pOldMarketData);
	
	///确认删除后触发
	///@param	pMarketData	已经删除的CMarketData
	virtual void commitRemove(CWriteableMarketData *pMarketData);

	///所有相关的触发器
	vector<CMarketDataActionTrigger *> *pActionTriggers;
	vector<CMarketDataCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableMarketData compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CClearingPartPositionFactory是一个结算会员持仓的对象工厂。它包含了一批结算会员持仓，
///同时又建立了如下索引，以方便查询：
///使用本对象工厂，可以完成对结算会员持仓的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByPartAndInstrument，唯一找到对象
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingPartPositionFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CClearingPartPositionFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxClearingPartPosition，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CClearingPartPositionFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CClearingPartPositionFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的ClearingPartPosition
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的ClearingPartPosition，文件名将根据配置文件中的定义ClearingPartPositionCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的ClearingPartPosition
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的ClearingPartPosition，文件名将根据配置文件中的定义ClearingPartPositionCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CClearingPartPositionResource;

	///将一个CClearingPartPosition加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pClearingPartPosition	要加入的ClearingPartPosition
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CClearingPartPosition *add(CWriteableClearingPartPosition *pClearingPartPosition, CTransaction *pTransaction=NULL);
	
	///刷新该CClearingPartPosition的值
	///@param	pClearingPartPosition	被刷新的CClearingPartPosition
	///@param	pNewClearingPartPosition	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CClearingPartPosition *pClearingPartPosition, CWriteableClearingPartPosition *pNewClearingPartPosition, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pClearingPartPosition	  需要被刷新或者新增的CClearingPartPosition,等于NULL表示是需要新增的
	///@param	pNewClearingPartPosition	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CClearingPartPosition* addOrUpdate(CClearingPartPosition *pClearingPartPosition, CWriteableClearingPartPosition *pNewClearingPartPosition, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CClearingPartPosition，同时删除其索引
	///@param	pClearingPartPosition	要删除的CClearingPartPosition
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CClearingPartPosition *pClearingPartPosition, CTransaction *pTransaction=NULL);
	
	///获取某个CClearingPartPosition
	///@param	pClearingPartPosition	要读取的CClearingPartPosition
	///@param	pTragetClearingPartPosition	存放结果的CClearingPartPosition
	void retrieve(CClearingPartPosition *pClearingPartPosition, CWriteableClearingPartPosition *pTargetClearingPartPosition);
	
	///获取第一个CClearingPartPosition
	///@return	得到的第一个CClearingPartPosition，如果没有，则返回NULL
	CClearingPartPosition *getFirst(void);
	
	///获取下一个CClearingPartPosition
	///@return	得到下一个CClearingPartPosition，如果没有，则返回NULL
	CClearingPartPosition *getNext(void);
	
	///结束获取CClearingPartPosition
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CClearingPartPositionActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CClearingPartPositionActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CClearingPartPositionCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CClearingPartPositionCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///寻找CClearingPartPosition
	///@param	ParticipantID	会员号
	///@param	InstrumentID	合约号
	///@param	PosiDirection	多空方向
	///@param	HedgeFlag	投保标志
	///@param	TradingRole	交易角色
	///@return	找到的CClearingPartPosition，如果找不到，返回NULL
	CClearingPartPosition *findByPartAndInstrument( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyPosiDirectionType&  PosiDirection,  const CReadOnlyHedgeFlagType&  HedgeFlag,  const CReadOnlyTradingRoleType&  TradingRole);



	friend class CClearingPartPositionIteratorBySettlementGroupID;

	///开始寻找CClearingPartPosition
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CClearingPartPosition，如果找不到，返回NULL
	CClearingPartPosition *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CClearingPartPosition，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CClearingPartPosition，如果已经没有一个满足要求了，则返回NULL
	CClearingPartPosition *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CClearingPartPosition加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pClearingPartPosition	要加入的ClearingPartPosition
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CClearingPartPosition *internalAdd(CWriteableClearingPartPosition *pClearingPartPosition, bool bNoTransaction);
	
	
	///刷新该CClearingPartPosition的键值
	///@param	pClearingPartPosition	被刷新的CClearingPartPosition
	///@param	pNewClearingPartPosition	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CClearingPartPosition *pClearingPartPosition, CWriteableClearingPartPosition *pNewClearingPartPosition, bool updateIndex,bool bNoTransaction);
	
	///删除一个CClearingPartPosition，同时删除其索引
	///@param	pClearingPartPosition	要删除的CClearingPartPosition
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CClearingPartPosition *pClearingPartPosition, bool bNoTransaction);
/*
	///检查某个CClearingPartPosition是否属于本对象工厂
	///@param	pClearingPartPosition	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CClearingPartPosition *pClearingPartPosition);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	
	///基于PartAndInstrument的hash索引
	CHashIndex *pPartAndInstrumentHashIndex;
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CClearingPartPosition *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pClearingPartPosition	要加入的ClearingPartPosition
	virtual void beforeAdd(CWriteableClearingPartPosition *pClearingPartPosition);
	
	///加入后触发
	///@param	pClearingPartPosition	已经加入的ClearingPartPosition
	virtual void afterAdd(CClearingPartPosition *pClearingPartPosition);

	///更新前触发	
	///@param	pClearingPartPosition	被刷新的CClearingPartPosition
	///@param	pNewClearingPartPosition	新的值
	virtual void beforeUpdate(CClearingPartPosition *pClearingPartPosition, CWriteableClearingPartPosition *pNewClearingPartPosition);
	
	///更新后触发
	///@param	pClearingPartPosition	被刷新的CClearingPartPosition
	virtual void afterUpdate(CClearingPartPosition *pClearingPartPosition);
	
	///删除前触发
	///@param	pClearingPartPosition	要删除的CClearingPartPosition
	virtual void beforeRemove(CClearingPartPosition *pClearingPartPosition);
	
	///确认加入后触发
	///@param	pClearingPartPosition	已经加入的ClearingPartPosition
	virtual void commitAdd(CClearingPartPosition *pClearingPartPosition);

	///确认更新后触发
	///@param	pClearingPartPosition	被刷新的CClearingPartPosition
	///@param	poldClearingPartPosition	原来的值
	virtual void commitUpdate(CClearingPartPosition *pClearingPartPosition, CWriteableClearingPartPosition *pOldClearingPartPosition);
	
	///确认删除后触发
	///@param	pClearingPartPosition	已经删除的CClearingPartPosition
	virtual void commitRemove(CWriteableClearingPartPosition *pClearingPartPosition);

	///所有相关的触发器
	vector<CClearingPartPositionActionTrigger *> *pActionTriggers;
	vector<CClearingPartPositionCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableClearingPartPosition compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusFactory是一个合约状态的对象工厂。它包含了一批合约状态，
///同时又建立了如下索引，以方便查询：
///	InstrumentIDIndex
///使用本对象工厂，可以完成对合约状态的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByInstrumentID，唯一找到对象
///		使用startFindStartByInstrumentID，findNextStartByInstrumentID和endFindStartByInstrumentID完成查询操作
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CInstrumentStatusFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxInstrumentStatus，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CInstrumentStatusFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CInstrumentStatusFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的InstrumentStatus
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的InstrumentStatus，文件名将根据配置文件中的定义InstrumentStatusCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的InstrumentStatus
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的InstrumentStatus，文件名将根据配置文件中的定义InstrumentStatusCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CInstrumentStatusResource;

	///将一个CInstrumentStatus加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pInstrumentStatus	要加入的InstrumentStatus
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CInstrumentStatus *add(CWriteableInstrumentStatus *pInstrumentStatus, CTransaction *pTransaction=NULL);
	
	///刷新该CInstrumentStatus的值
	///@param	pInstrumentStatus	被刷新的CInstrumentStatus
	///@param	pNewInstrumentStatus	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CInstrumentStatus *pInstrumentStatus, CWriteableInstrumentStatus *pNewInstrumentStatus, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pInstrumentStatus	  需要被刷新或者新增的CInstrumentStatus,等于NULL表示是需要新增的
	///@param	pNewInstrumentStatus	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CInstrumentStatus* addOrUpdate(CInstrumentStatus *pInstrumentStatus, CWriteableInstrumentStatus *pNewInstrumentStatus, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CInstrumentStatus，同时删除其索引
	///@param	pInstrumentStatus	要删除的CInstrumentStatus
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CInstrumentStatus *pInstrumentStatus, CTransaction *pTransaction=NULL);
	
	///获取某个CInstrumentStatus
	///@param	pInstrumentStatus	要读取的CInstrumentStatus
	///@param	pTragetInstrumentStatus	存放结果的CInstrumentStatus
	void retrieve(CInstrumentStatus *pInstrumentStatus, CWriteableInstrumentStatus *pTargetInstrumentStatus);
	
	///获取第一个CInstrumentStatus
	///@return	得到的第一个CInstrumentStatus，如果没有，则返回NULL
	CInstrumentStatus *getFirst(void);
	
	///获取下一个CInstrumentStatus
	///@return	得到下一个CInstrumentStatus，如果没有，则返回NULL
	CInstrumentStatus *getNext(void);
	
	///结束获取CInstrumentStatus
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CInstrumentStatusActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CInstrumentStatusActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CInstrumentStatusCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CInstrumentStatusCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///构造所有对应的合约的指针
	///@param	pFactory	构造对应的合约的指针时，寻找的对象工厂
	void linkAllInstrument(CInstrumentFactory *pFactory);
	
	///构造所有对应的价格绑定的指针
	///@param	pFactory	构造对应的价格绑定的指针时，寻找的对象工厂
	void linkAllCurrPriceBanding(CCurrPriceBandingFactory *pFactory);
	
	///构造所有对应的行情发布状态的指针
	///@param	pFactory	构造对应的行情发布状态的指针时，寻找的对象工厂
	void linkAllMdPubStatus(CMdPubStatusFactory *pFactory);
	
	///寻找CInstrumentStatus
	///@param	InstrumentID	合约代码
	///@return	找到的CInstrumentStatus，如果找不到，返回NULL
	CInstrumentStatus *findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID);



	friend class CInstrumentStatusIteratorStartByInstrumentID;

	///开始寻找CInstrumentStatus
	///@param	InstrumentID	合约代码
	///@return	满足条件的地一个CInstrumentStatus，如果找不到，返回NULL
	CInstrumentStatus *startFindStartByInstrumentID( const CReadOnlyInstrumentIDType& InstrumentID);

	///寻找下一个符合条件的CInstrumentStatus，必须在startFindStartByInstrumentID以后，endFindStartByInstrumentID之前叫用
	///@return	下一个满足条件CInstrumentStatus，如果已经没有一个满足要求了，则返回NULL
	CInstrumentStatus *findNextStartByInstrumentID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindStartByInstrumentID(void);

	friend class CInstrumentStatusIteratorBySettlementGroupID;

	///开始寻找CInstrumentStatus
	///@param	SettlementGroupID	结算组编号
	///@return	满足条件的地一个CInstrumentStatus，如果找不到，返回NULL
	CInstrumentStatus *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CInstrumentStatus，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CInstrumentStatus，如果已经没有一个满足要求了，则返回NULL
	CInstrumentStatus *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CInstrumentStatus加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pInstrumentStatus	要加入的InstrumentStatus
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CInstrumentStatus *internalAdd(CWriteableInstrumentStatus *pInstrumentStatus, bool bNoTransaction);
	
	
	///刷新该CInstrumentStatus的键值
	///@param	pInstrumentStatus	被刷新的CInstrumentStatus
	///@param	pNewInstrumentStatus	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CInstrumentStatus *pInstrumentStatus, CWriteableInstrumentStatus *pNewInstrumentStatus, bool updateIndex,bool bNoTransaction);
	
	///删除一个CInstrumentStatus，同时删除其索引
	///@param	pInstrumentStatus	要删除的CInstrumentStatus
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CInstrumentStatus *pInstrumentStatus, bool bNoTransaction);
/*
	///检查某个CInstrumentStatus是否属于本对象工厂
	///@param	pInstrumentStatus	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CInstrumentStatus *pInstrumentStatus);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于InstrumentID的索引
	CAVLTree *pInstrumentIDIndex;
	
	
	///按照InstrumentID检索时，存储的查询参数
	CInstrumentIDType queryInstrumentIDInSearchStartByInstrumentID;
	
	///按照InstrumentID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchStartByInstrumentID;
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CInstrumentStatus *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pInstrumentStatus	要加入的InstrumentStatus
	virtual void beforeAdd(CWriteableInstrumentStatus *pInstrumentStatus);
	
	///加入后触发
	///@param	pInstrumentStatus	已经加入的InstrumentStatus
	virtual void afterAdd(CInstrumentStatus *pInstrumentStatus);

	///更新前触发	
	///@param	pInstrumentStatus	被刷新的CInstrumentStatus
	///@param	pNewInstrumentStatus	新的值
	virtual void beforeUpdate(CInstrumentStatus *pInstrumentStatus, CWriteableInstrumentStatus *pNewInstrumentStatus);
	
	///更新后触发
	///@param	pInstrumentStatus	被刷新的CInstrumentStatus
	virtual void afterUpdate(CInstrumentStatus *pInstrumentStatus);
	
	///删除前触发
	///@param	pInstrumentStatus	要删除的CInstrumentStatus
	virtual void beforeRemove(CInstrumentStatus *pInstrumentStatus);
	
	///确认加入后触发
	///@param	pInstrumentStatus	已经加入的InstrumentStatus
	virtual void commitAdd(CInstrumentStatus *pInstrumentStatus);

	///确认更新后触发
	///@param	pInstrumentStatus	被刷新的CInstrumentStatus
	///@param	poldInstrumentStatus	原来的值
	virtual void commitUpdate(CInstrumentStatus *pInstrumentStatus, CWriteableInstrumentStatus *pOldInstrumentStatus);
	
	///确认删除后触发
	///@param	pInstrumentStatus	已经删除的CInstrumentStatus
	virtual void commitRemove(CWriteableInstrumentStatus *pInstrumentStatus);

	///所有相关的触发器
	vector<CInstrumentStatusActionTrigger *> *pActionTriggers;
	vector<CInstrumentStatusCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableInstrumentStatus compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///COrderFactory是一个报单的对象工厂。它包含了一批报单，
///同时又建立了如下索引，以方便查询：
///	ParticipantIDIndex
///	OrderLocalIDIndex
///	InstrumentIDIndex
///使用本对象工厂，可以完成对报单的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByOrderID，唯一找到对象
///		使用startFindStartByParticipantID，findNextStartByParticipantID和endFindStartByParticipantID完成查询操作
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByOrderLocalID，唯一找到对象
///		使用startFindByUserID，findNextByUserID和endFindByUserID完成查询操作
///		使用startFindByInstrumentID，findNextByInstrumentID和endFindByInstrumentID完成查询操作
///		使用startFindStartByInstrumentID，findNextStartByInstrumentID和endFindStartByInstrumentID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	COrderFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxOrder，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	COrderFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~COrderFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的Order
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的Order，文件名将根据配置文件中的定义OrderCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的Order
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的Order，文件名将根据配置文件中的定义OrderCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class COrderResource;

	///将一个COrder加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pOrder	要加入的Order
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	COrder *add(CWriteableOrder *pOrder, CTransaction *pTransaction=NULL);
	
	///刷新该COrder的值
	///@param	pOrder	被刷新的COrder
	///@param	pNewOrder	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(COrder *pOrder, CWriteableOrder *pNewOrder, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pOrder	  需要被刷新或者新增的COrder,等于NULL表示是需要新增的
	///@param	pNewOrder	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	COrder* addOrUpdate(COrder *pOrder, CWriteableOrder *pNewOrder, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个COrder，同时删除其索引
	///@param	pOrder	要删除的COrder
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(COrder *pOrder, CTransaction *pTransaction=NULL);
	
	///获取某个COrder
	///@param	pOrder	要读取的COrder
	///@param	pTragetOrder	存放结果的COrder
	void retrieve(COrder *pOrder, CWriteableOrder *pTargetOrder);
	
	///获取第一个COrder
	///@return	得到的第一个COrder，如果没有，则返回NULL
	COrder *getFirst(void);
	
	///获取下一个COrder
	///@return	得到下一个COrder，如果没有，则返回NULL
	COrder *getNext(void);
	
	///结束获取COrder
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(COrderActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(COrderActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(COrderCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(COrderCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///构造所有对应的合约的指针
	///@param	pFactory	构造对应的合约的指针时，寻找的对象工厂
	void linkAllInstrument(CInstrumentFactory *pFactory);
	
	///构造所有指定的会员客户的指针
	///@param	pFactory	构造指定的会员客户的指针时，寻找的对象工厂
	void linkAllPartClient(CPartClientFactory *pFactory);
	
	///构造所有对应的客户持仓的指针
	///@param	pFactory	构造对应的客户持仓的指针时，寻找的对象工厂
	void linkAllClientPosition(CClientPositionFactory *pFactory);
	
	///寻找COrder
	///@param	OrderSysID	报单系统编号
	///@return	找到的COrder，如果找不到，返回NULL
	COrder *findByOrderID( const CReadOnlyOrderSysIDType&  OrderSysID);



	friend class COrderIteratorStartByParticipantID;

	///开始寻找COrder
	///@param	ParticipantID	会员号
	///@return	满足条件的地一个COrder，如果找不到，返回NULL
	COrder *startFindStartByParticipantID( const CReadOnlyParticipantIDType& ParticipantID);

	///寻找下一个符合条件的COrder，必须在startFindStartByParticipantID以后，endFindStartByParticipantID之前叫用
	///@return	下一个满足条件COrder，如果已经没有一个满足要求了，则返回NULL
	COrder *findNextStartByParticipantID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindStartByParticipantID(void);

	friend class COrderIteratorBySettlementGroupID;

	///开始寻找COrder
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个COrder，如果找不到，返回NULL
	COrder *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的COrder，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件COrder，如果已经没有一个满足要求了，则返回NULL
	COrder *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找COrder
	///@param	UserID	交易员代码
	///@param	OrderLocalID	报单本地编号
	///@return	找到的COrder，如果找不到，返回NULL
	COrder *findByOrderLocalID( const CReadOnlyUserIDType&  UserID,  const CReadOnlyOrderLocalIDType&  OrderLocalID);



	friend class COrderIteratorByUserID;

	///开始寻找COrder
	///@param	UserID	交易员代码
	///@return	满足条件的地一个COrder，如果找不到，返回NULL
	COrder *startFindByUserID( const CReadOnlyUserIDType& UserID);

	///寻找下一个符合条件的COrder，必须在startFindByUserID以后，endFindByUserID之前叫用
	///@return	下一个满足条件COrder，如果已经没有一个满足要求了，则返回NULL
	COrder *findNextByUserID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByUserID(void);

	friend class COrderIteratorByInstrumentID;

	///开始寻找COrder
	///@param	InstrumentID	合约号
	///@return	满足条件的地一个COrder，如果找不到，返回NULL
	COrder *startFindByInstrumentID( const CReadOnlyInstrumentIDType& InstrumentID);

	///寻找下一个符合条件的COrder，必须在startFindByInstrumentID以后，endFindByInstrumentID之前叫用
	///@return	下一个满足条件COrder，如果已经没有一个满足要求了，则返回NULL
	COrder *findNextByInstrumentID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByInstrumentID(void);

	friend class COrderIteratorStartByInstrumentID;

	///开始寻找COrder
	///@param	InstrumentID	合约号
	///@return	满足条件的地一个COrder，如果找不到，返回NULL
	COrder *startFindStartByInstrumentID( const CReadOnlyInstrumentIDType& InstrumentID);

	///寻找下一个符合条件的COrder，必须在startFindStartByInstrumentID以后，endFindStartByInstrumentID之前叫用
	///@return	下一个满足条件COrder，如果已经没有一个满足要求了，则返回NULL
	COrder *findNextStartByInstrumentID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindStartByInstrumentID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个COrder加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pOrder	要加入的Order
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	COrder *internalAdd(CWriteableOrder *pOrder, bool bNoTransaction);
	
	
	///刷新该COrder的键值
	///@param	pOrder	被刷新的COrder
	///@param	pNewOrder	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(COrder *pOrder, CWriteableOrder *pNewOrder, bool updateIndex,bool bNoTransaction);
	
	///删除一个COrder，同时删除其索引
	///@param	pOrder	要删除的COrder
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(COrder *pOrder, bool bNoTransaction);
/*
	///检查某个COrder是否属于本对象工厂
	///@param	pOrder	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(COrder *pOrder);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ParticipantID的索引
	CAVLTree *pParticipantIDIndex;
	///基于UserID+OrderLocalID的索引
	CAVLTree *pOrderLocalIDIndex;
	///基于InstrumentID的索引
	CAVLTree *pInstrumentIDIndex;
	
	///基于OrderSysID的hash索引
	CHashIndex *pOrderSysIDHashIndex;
	
	///按照ParticipantID检索时，存储的查询参数
	CParticipantIDType queryParticipantIDInSearchStartByParticipantID;
	
	///按照ParticipantID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchStartByParticipantID;
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	COrder *pLastFoundInSearchBySettlementGroupID;
	///按照UserID检索时，存储的查询参数
	CUserIDType queryUserIDInSearchByUserID;
	
	///按照UserID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByUserID;
	///按照InstrumentID检索时，存储的查询参数
	CInstrumentIDType queryInstrumentIDInSearchByInstrumentID;
	
	///按照InstrumentID检索时，存储最后一次找到的索引节点
	COrder *pLastFoundInSearchByInstrumentID;
	///按照InstrumentID检索时，存储的查询参数
	CInstrumentIDType queryInstrumentIDInSearchStartByInstrumentID;
	
	///按照InstrumentID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchStartByInstrumentID;
	
	///加入前触发
	///@param	pOrder	要加入的Order
	virtual void beforeAdd(CWriteableOrder *pOrder);
	
	///加入后触发
	///@param	pOrder	已经加入的Order
	virtual void afterAdd(COrder *pOrder);

	///更新前触发	
	///@param	pOrder	被刷新的COrder
	///@param	pNewOrder	新的值
	virtual void beforeUpdate(COrder *pOrder, CWriteableOrder *pNewOrder);
	
	///更新后触发
	///@param	pOrder	被刷新的COrder
	virtual void afterUpdate(COrder *pOrder);
	
	///删除前触发
	///@param	pOrder	要删除的COrder
	virtual void beforeRemove(COrder *pOrder);
	
	///确认加入后触发
	///@param	pOrder	已经加入的Order
	virtual void commitAdd(COrder *pOrder);

	///确认更新后触发
	///@param	pOrder	被刷新的COrder
	///@param	poldOrder	原来的值
	virtual void commitUpdate(COrder *pOrder, CWriteableOrder *pOldOrder);
	
	///确认删除后触发
	///@param	pOrder	已经删除的COrder
	virtual void commitRemove(CWriteableOrder *pOrder);

	///所有相关的触发器
	vector<COrderActionTrigger *> *pActionTriggers;
	vector<COrderCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableOrder compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCombOrderFactory是一个组合报单的对象工厂。它包含了一批组合报单，
///同时又建立了如下索引，以方便查询：
///	ParticipantIDIndex
///	CombOrderLocalIDIndex
///使用本对象工厂，可以完成对组合报单的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByCombOrderID，唯一找到对象
///		使用startFindStartByParticipantID，findNextStartByParticipantID和endFindStartByParticipantID完成查询操作
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByCombOrderLocalID，唯一找到对象
///		使用startFindByUserID，findNextByUserID和endFindByUserID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCombOrderFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxCombOrder，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCombOrderFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CCombOrderFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的CombOrder
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的CombOrder，文件名将根据配置文件中的定义CombOrderCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的CombOrder
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的CombOrder，文件名将根据配置文件中的定义CombOrderCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CCombOrderResource;

	///将一个CCombOrder加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCombOrder	要加入的CombOrder
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCombOrder *add(CWriteableCombOrder *pCombOrder, CTransaction *pTransaction=NULL);
	
	///刷新该CCombOrder的值
	///@param	pCombOrder	被刷新的CCombOrder
	///@param	pNewCombOrder	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CCombOrder *pCombOrder, CWriteableCombOrder *pNewCombOrder, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pCombOrder	  需要被刷新或者新增的CCombOrder,等于NULL表示是需要新增的
	///@param	pNewCombOrder	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CCombOrder* addOrUpdate(CCombOrder *pCombOrder, CWriteableCombOrder *pNewCombOrder, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CCombOrder，同时删除其索引
	///@param	pCombOrder	要删除的CCombOrder
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CCombOrder *pCombOrder, CTransaction *pTransaction=NULL);
	
	///获取某个CCombOrder
	///@param	pCombOrder	要读取的CCombOrder
	///@param	pTragetCombOrder	存放结果的CCombOrder
	void retrieve(CCombOrder *pCombOrder, CWriteableCombOrder *pTargetCombOrder);
	
	///获取第一个CCombOrder
	///@return	得到的第一个CCombOrder，如果没有，则返回NULL
	CCombOrder *getFirst(void);
	
	///获取下一个CCombOrder
	///@return	得到下一个CCombOrder，如果没有，则返回NULL
	CCombOrder *getNext(void);
	
	///结束获取CCombOrder
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CCombOrderActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CCombOrderActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CCombOrderCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CCombOrderCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///构造所有指定的会员客户的指针
	///@param	pFactory	构造指定的会员客户的指针时，寻找的对象工厂
	void linkAllPartClient(CPartClientFactory *pFactory);
	
	///构造所有对应的合约1的指针
	///@param	pFactory	构造对应的合约1的指针时，寻找的对象工厂
	void linkAllInstrument1(CInstrumentFactory *pFactory);
	
	///构造所有对应的合约2的指针
	///@param	pFactory	构造对应的合约2的指针时，寻找的对象工厂
	void linkAllInstrument2(CInstrumentFactory *pFactory);
	
	///构造所有对应的合约3的指针
	///@param	pFactory	构造对应的合约3的指针时，寻找的对象工厂
	void linkAllInstrument3(CInstrumentFactory *pFactory);
	
	///构造所有对应的合约4的指针
	///@param	pFactory	构造对应的合约4的指针时，寻找的对象工厂
	void linkAllInstrument4(CInstrumentFactory *pFactory);
	
	///寻找CCombOrder
	///@param	CombOrderSysID	组合报单系统编号
	///@return	找到的CCombOrder，如果找不到，返回NULL
	CCombOrder *findByCombOrderID( const CReadOnlyOrderSysIDType&  CombOrderSysID);



	friend class CCombOrderIteratorStartByParticipantID;

	///开始寻找CCombOrder
	///@param	ParticipantID	会员号
	///@return	满足条件的地一个CCombOrder，如果找不到，返回NULL
	CCombOrder *startFindStartByParticipantID( const CReadOnlyParticipantIDType& ParticipantID);

	///寻找下一个符合条件的CCombOrder，必须在startFindStartByParticipantID以后，endFindStartByParticipantID之前叫用
	///@return	下一个满足条件CCombOrder，如果已经没有一个满足要求了，则返回NULL
	CCombOrder *findNextStartByParticipantID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindStartByParticipantID(void);

	friend class CCombOrderIteratorBySettlementGroupID;

	///开始寻找CCombOrder
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CCombOrder，如果找不到，返回NULL
	CCombOrder *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CCombOrder，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCombOrder，如果已经没有一个满足要求了，则返回NULL
	CCombOrder *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CCombOrder
	///@param	UserID	交易员代码
	///@param	CombOrderLocalID	组合报单本地编号
	///@return	找到的CCombOrder，如果找不到，返回NULL
	CCombOrder *findByCombOrderLocalID( const CReadOnlyUserIDType&  UserID,  const CReadOnlyOrderLocalIDType&  CombOrderLocalID);



	friend class CCombOrderIteratorByUserID;

	///开始寻找CCombOrder
	///@param	UserID	交易员代码
	///@return	满足条件的地一个CCombOrder，如果找不到，返回NULL
	CCombOrder *startFindByUserID( const CReadOnlyUserIDType& UserID);

	///寻找下一个符合条件的CCombOrder，必须在startFindByUserID以后，endFindByUserID之前叫用
	///@return	下一个满足条件CCombOrder，如果已经没有一个满足要求了，则返回NULL
	CCombOrder *findNextByUserID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByUserID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CCombOrder加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCombOrder	要加入的CombOrder
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCombOrder *internalAdd(CWriteableCombOrder *pCombOrder, bool bNoTransaction);
	
	
	///刷新该CCombOrder的键值
	///@param	pCombOrder	被刷新的CCombOrder
	///@param	pNewCombOrder	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CCombOrder *pCombOrder, CWriteableCombOrder *pNewCombOrder, bool updateIndex,bool bNoTransaction);
	
	///删除一个CCombOrder，同时删除其索引
	///@param	pCombOrder	要删除的CCombOrder
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CCombOrder *pCombOrder, bool bNoTransaction);
/*
	///检查某个CCombOrder是否属于本对象工厂
	///@param	pCombOrder	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CCombOrder *pCombOrder);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ParticipantID的索引
	CAVLTree *pParticipantIDIndex;
	///基于UserID+CombOrderLocalID的索引
	CAVLTree *pCombOrderLocalIDIndex;
	
	///基于CombOrderSysID的hash索引
	CHashIndex *pCombOrderSysIDHashIndex;
	
	///按照ParticipantID检索时，存储的查询参数
	CParticipantIDType queryParticipantIDInSearchStartByParticipantID;
	
	///按照ParticipantID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchStartByParticipantID;
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CCombOrder *pLastFoundInSearchBySettlementGroupID;
	///按照UserID检索时，存储的查询参数
	CUserIDType queryUserIDInSearchByUserID;
	
	///按照UserID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByUserID;
	
	///加入前触发
	///@param	pCombOrder	要加入的CombOrder
	virtual void beforeAdd(CWriteableCombOrder *pCombOrder);
	
	///加入后触发
	///@param	pCombOrder	已经加入的CombOrder
	virtual void afterAdd(CCombOrder *pCombOrder);

	///更新前触发	
	///@param	pCombOrder	被刷新的CCombOrder
	///@param	pNewCombOrder	新的值
	virtual void beforeUpdate(CCombOrder *pCombOrder, CWriteableCombOrder *pNewCombOrder);
	
	///更新后触发
	///@param	pCombOrder	被刷新的CCombOrder
	virtual void afterUpdate(CCombOrder *pCombOrder);
	
	///删除前触发
	///@param	pCombOrder	要删除的CCombOrder
	virtual void beforeRemove(CCombOrder *pCombOrder);
	
	///确认加入后触发
	///@param	pCombOrder	已经加入的CombOrder
	virtual void commitAdd(CCombOrder *pCombOrder);

	///确认更新后触发
	///@param	pCombOrder	被刷新的CCombOrder
	///@param	poldCombOrder	原来的值
	virtual void commitUpdate(CCombOrder *pCombOrder, CWriteableCombOrder *pOldCombOrder);
	
	///确认删除后触发
	///@param	pCombOrder	已经删除的CCombOrder
	virtual void commitRemove(CWriteableCombOrder *pCombOrder);

	///所有相关的触发器
	vector<CCombOrderActionTrigger *> *pActionTriggers;
	vector<CCombOrderCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableCombOrder compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///COTCOrderFactory是一个OTC报单的对象工厂。它包含了一批OTC报单，
///同时又建立了如下索引，以方便查询：
///	OTCOrderIDIndex
///	OTCOrderLocalIDIndex
///使用本对象工厂，可以完成对OTC报单的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByOTCOrderLocalID，唯一找到对象
///		使用findByOTCOrderID，唯一找到对象
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COTCOrderFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	COTCOrderFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxOTCOrder，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	COTCOrderFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~COTCOrderFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的OTCOrder
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的OTCOrder，文件名将根据配置文件中的定义OTCOrderCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的OTCOrder
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的OTCOrder，文件名将根据配置文件中的定义OTCOrderCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class COTCOrderResource;

	///将一个COTCOrder加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pOTCOrder	要加入的OTCOrder
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	COTCOrder *add(CWriteableOTCOrder *pOTCOrder, CTransaction *pTransaction=NULL);
	
	///刷新该COTCOrder的值
	///@param	pOTCOrder	被刷新的COTCOrder
	///@param	pNewOTCOrder	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(COTCOrder *pOTCOrder, CWriteableOTCOrder *pNewOTCOrder, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pOTCOrder	  需要被刷新或者新增的COTCOrder,等于NULL表示是需要新增的
	///@param	pNewOTCOrder	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	COTCOrder* addOrUpdate(COTCOrder *pOTCOrder, CWriteableOTCOrder *pNewOTCOrder, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个COTCOrder，同时删除其索引
	///@param	pOTCOrder	要删除的COTCOrder
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(COTCOrder *pOTCOrder, CTransaction *pTransaction=NULL);
	
	///获取某个COTCOrder
	///@param	pOTCOrder	要读取的COTCOrder
	///@param	pTragetOTCOrder	存放结果的COTCOrder
	void retrieve(COTCOrder *pOTCOrder, CWriteableOTCOrder *pTargetOTCOrder);
	
	///获取第一个COTCOrder
	///@return	得到的第一个COTCOrder，如果没有，则返回NULL
	COTCOrder *getFirst(void);
	
	///获取下一个COTCOrder
	///@return	得到下一个COTCOrder，如果没有，则返回NULL
	COTCOrder *getNext(void);
	
	///结束获取COTCOrder
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(COTCOrderActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(COTCOrderActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(COTCOrderCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(COTCOrderCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///构造所有对应的合约的指针
	///@param	pFactory	构造对应的合约的指针时，寻找的对象工厂
	void linkAllInstrument(CInstrumentFactory *pFactory);
	
	///寻找COTCOrder
	///@param	UserID	交易员代码
	///@param	OTCOrderLocalID	OTC报单本地编号
	///@return	找到的COTCOrder，如果找不到，返回NULL
	COTCOrder *findByOTCOrderLocalID( const CReadOnlyUserIDType&  UserID,  const CReadOnlyOrderLocalIDType&  OTCOrderLocalID);



	///寻找COTCOrder
	///@param	OTCOrderSysID	OTC报单系统编号
	///@return	找到的COTCOrder，如果找不到，返回NULL
	COTCOrder *findByOTCOrderID( const CReadOnlyOTCOrderSysIDType&  OTCOrderSysID);



	friend class COTCOrderIteratorBySettlementGroupID;

	///开始寻找COTCOrder
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个COTCOrder，如果找不到，返回NULL
	COTCOrder *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的COTCOrder，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件COTCOrder，如果已经没有一个满足要求了，则返回NULL
	COTCOrder *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个COTCOrder加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pOTCOrder	要加入的OTCOrder
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	COTCOrder *internalAdd(CWriteableOTCOrder *pOTCOrder, bool bNoTransaction);
	
	
	///刷新该COTCOrder的键值
	///@param	pOTCOrder	被刷新的COTCOrder
	///@param	pNewOTCOrder	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(COTCOrder *pOTCOrder, CWriteableOTCOrder *pNewOTCOrder, bool updateIndex,bool bNoTransaction);
	
	///删除一个COTCOrder，同时删除其索引
	///@param	pOTCOrder	要删除的COTCOrder
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(COTCOrder *pOTCOrder, bool bNoTransaction);
/*
	///检查某个COTCOrder是否属于本对象工厂
	///@param	pOTCOrder	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(COTCOrder *pOTCOrder);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于OTCOrderSysID的索引
	CAVLTree *pOTCOrderIDIndex;
	///基于UserID+OTCOrderLocalID的索引
	CAVLTree *pOTCOrderLocalIDIndex;
	
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	COTCOrder *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pOTCOrder	要加入的OTCOrder
	virtual void beforeAdd(CWriteableOTCOrder *pOTCOrder);
	
	///加入后触发
	///@param	pOTCOrder	已经加入的OTCOrder
	virtual void afterAdd(COTCOrder *pOTCOrder);

	///更新前触发	
	///@param	pOTCOrder	被刷新的COTCOrder
	///@param	pNewOTCOrder	新的值
	virtual void beforeUpdate(COTCOrder *pOTCOrder, CWriteableOTCOrder *pNewOTCOrder);
	
	///更新后触发
	///@param	pOTCOrder	被刷新的COTCOrder
	virtual void afterUpdate(COTCOrder *pOTCOrder);
	
	///删除前触发
	///@param	pOTCOrder	要删除的COTCOrder
	virtual void beforeRemove(COTCOrder *pOTCOrder);
	
	///确认加入后触发
	///@param	pOTCOrder	已经加入的OTCOrder
	virtual void commitAdd(COTCOrder *pOTCOrder);

	///确认更新后触发
	///@param	pOTCOrder	被刷新的COTCOrder
	///@param	poldOTCOrder	原来的值
	virtual void commitUpdate(COTCOrder *pOTCOrder, CWriteableOTCOrder *pOldOTCOrder);
	
	///确认删除后触发
	///@param	pOTCOrder	已经删除的COTCOrder
	virtual void commitRemove(CWriteableOTCOrder *pOTCOrder);

	///所有相关的触发器
	vector<COTCOrderActionTrigger *> *pActionTriggers;
	vector<COTCOrderCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableOTCOrder compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CImplyOrderFactory是一个隐式报单的对象工厂。它包含了一批隐式报单，
///同时又建立了如下索引，以方便查询：
///	ImplyLegInstrumentIndex
///	ImplyOrderAndAnchorLegIndex
///使用本对象工厂，可以完成对隐式报单的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByImplyLeg，findNextByImplyLeg和endFindByImplyLeg完成查询操作
///		使用startFindByImplyOrderAndAnchorLeg，findNextByImplyOrderAndAnchorLeg和endFindByImplyOrderAndAnchorLeg完成查询操作
///		使用startFindByImplyOrder，findNextByImplyOrder和endFindByImplyOrder完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CImplyOrderFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxImplyOrder，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CImplyOrderFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CImplyOrderFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的ImplyOrder
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的ImplyOrder，文件名将根据配置文件中的定义ImplyOrderCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的ImplyOrder
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的ImplyOrder，文件名将根据配置文件中的定义ImplyOrderCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CImplyOrderResource;

	///将一个CImplyOrder加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pImplyOrder	要加入的ImplyOrder
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CImplyOrder *add(CWriteableImplyOrder *pImplyOrder, CTransaction *pTransaction=NULL);
	
	///刷新该CImplyOrder的值
	///@param	pImplyOrder	被刷新的CImplyOrder
	///@param	pNewImplyOrder	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CImplyOrder *pImplyOrder, CWriteableImplyOrder *pNewImplyOrder, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pImplyOrder	  需要被刷新或者新增的CImplyOrder,等于NULL表示是需要新增的
	///@param	pNewImplyOrder	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CImplyOrder* addOrUpdate(CImplyOrder *pImplyOrder, CWriteableImplyOrder *pNewImplyOrder, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CImplyOrder，同时删除其索引
	///@param	pImplyOrder	要删除的CImplyOrder
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CImplyOrder *pImplyOrder, CTransaction *pTransaction=NULL);
	
	///获取某个CImplyOrder
	///@param	pImplyOrder	要读取的CImplyOrder
	///@param	pTragetImplyOrder	存放结果的CImplyOrder
	void retrieve(CImplyOrder *pImplyOrder, CWriteableImplyOrder *pTargetImplyOrder);
	
	///获取第一个CImplyOrder
	///@return	得到的第一个CImplyOrder，如果没有，则返回NULL
	CImplyOrder *getFirst(void);
	
	///获取下一个CImplyOrder
	///@return	得到下一个CImplyOrder，如果没有，则返回NULL
	CImplyOrder *getNext(void);
	
	///结束获取CImplyOrder
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CImplyOrderActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CImplyOrderActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CImplyOrderCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CImplyOrderCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CImplyOrderIteratorByImplyLeg;

	///开始寻找CImplyOrder
	///@param	CombInstrumentID	组合报单号
	///@param	ImplyLegID	派生报单单腿编号
	///@param	Direction	派生报单买卖方向
	///@return	满足条件的地一个CImplyOrder，如果找不到，返回NULL
	CImplyOrder *startFindByImplyLeg( const CReadOnlyInstrumentIDType& CombInstrumentID,  const CReadOnlyLegIDType& ImplyLegID,  const CReadOnlyDirectionType& Direction);

	///寻找下一个符合条件的CImplyOrder，必须在startFindByImplyLeg以后，endFindByImplyLeg之前叫用
	///@return	下一个满足条件CImplyOrder，如果已经没有一个满足要求了，则返回NULL
	CImplyOrder *findNextByImplyLeg(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByImplyLeg(void);

	friend class CImplyOrderIteratorByImplyOrderAndAnchorLeg;

	///开始寻找CImplyOrder
	///@param	ImplyOrderID	隐含报单号
	///@param	AnchorLegID	锚报单分腿编号
	///@return	满足条件的地一个CImplyOrder，如果找不到，返回NULL
	CImplyOrder *startFindByImplyOrderAndAnchorLeg( const CReadOnlyOrderSysIDType& ImplyOrderID,  const CReadOnlyLegIDType& AnchorLegID);

	///寻找下一个符合条件的CImplyOrder，必须在startFindByImplyOrderAndAnchorLeg以后，endFindByImplyOrderAndAnchorLeg之前叫用
	///@return	下一个满足条件CImplyOrder，如果已经没有一个满足要求了，则返回NULL
	CImplyOrder *findNextByImplyOrderAndAnchorLeg(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByImplyOrderAndAnchorLeg(void);

	friend class CImplyOrderIteratorByImplyOrder;

	///开始寻找CImplyOrder
	///@param	ImplyOrderID	隐含报单号
	///@return	满足条件的地一个CImplyOrder，如果找不到，返回NULL
	CImplyOrder *startFindByImplyOrder( const CReadOnlyOrderSysIDType& ImplyOrderID);

	///寻找下一个符合条件的CImplyOrder，必须在startFindByImplyOrder以后，endFindByImplyOrder之前叫用
	///@return	下一个满足条件CImplyOrder，如果已经没有一个满足要求了，则返回NULL
	CImplyOrder *findNextByImplyOrder(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByImplyOrder(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CImplyOrder加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pImplyOrder	要加入的ImplyOrder
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CImplyOrder *internalAdd(CWriteableImplyOrder *pImplyOrder, bool bNoTransaction);
	
	
	///刷新该CImplyOrder的键值
	///@param	pImplyOrder	被刷新的CImplyOrder
	///@param	pNewImplyOrder	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CImplyOrder *pImplyOrder, CWriteableImplyOrder *pNewImplyOrder, bool updateIndex,bool bNoTransaction);
	
	///删除一个CImplyOrder，同时删除其索引
	///@param	pImplyOrder	要删除的CImplyOrder
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CImplyOrder *pImplyOrder, bool bNoTransaction);
/*
	///检查某个CImplyOrder是否属于本对象工厂
	///@param	pImplyOrder	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CImplyOrder *pImplyOrder);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于CombInstrumentID+ImplyLegID+Direction的索引
	CAVLTree *pImplyLegInstrumentIndex;
	///基于ImplyOrderID+AnchorLegID+Priority的索引
	CAVLTree *pImplyOrderAndAnchorLegIndex;
	
	
	///按照CombInstrumentID，ImplyLegID，Direction检索时，存储的查询参数
	CInstrumentIDType queryCombInstrumentIDInSearchByImplyLeg;
	CLegIDType queryImplyLegIDInSearchByImplyLeg;
	CDirectionType queryDirectionInSearchByImplyLeg;
	
	///按照CombInstrumentID，ImplyLegID，Direction检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByImplyLeg;
	///按照ImplyOrderID，AnchorLegID检索时，存储的查询参数
	COrderSysIDType queryImplyOrderIDInSearchByImplyOrderAndAnchorLeg;
	CLegIDType queryAnchorLegIDInSearchByImplyOrderAndAnchorLeg;
	
	///按照ImplyOrderID，AnchorLegID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByImplyOrderAndAnchorLeg;
	///按照ImplyOrderID检索时，存储的查询参数
	COrderSysIDType queryImplyOrderIDInSearchByImplyOrder;
	
	///按照ImplyOrderID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByImplyOrder;
	
	///加入前触发
	///@param	pImplyOrder	要加入的ImplyOrder
	virtual void beforeAdd(CWriteableImplyOrder *pImplyOrder);
	
	///加入后触发
	///@param	pImplyOrder	已经加入的ImplyOrder
	virtual void afterAdd(CImplyOrder *pImplyOrder);

	///更新前触发	
	///@param	pImplyOrder	被刷新的CImplyOrder
	///@param	pNewImplyOrder	新的值
	virtual void beforeUpdate(CImplyOrder *pImplyOrder, CWriteableImplyOrder *pNewImplyOrder);
	
	///更新后触发
	///@param	pImplyOrder	被刷新的CImplyOrder
	virtual void afterUpdate(CImplyOrder *pImplyOrder);
	
	///删除前触发
	///@param	pImplyOrder	要删除的CImplyOrder
	virtual void beforeRemove(CImplyOrder *pImplyOrder);
	
	///确认加入后触发
	///@param	pImplyOrder	已经加入的ImplyOrder
	virtual void commitAdd(CImplyOrder *pImplyOrder);

	///确认更新后触发
	///@param	pImplyOrder	被刷新的CImplyOrder
	///@param	poldImplyOrder	原来的值
	virtual void commitUpdate(CImplyOrder *pImplyOrder, CWriteableImplyOrder *pOldImplyOrder);
	
	///确认删除后触发
	///@param	pImplyOrder	已经删除的CImplyOrder
	virtual void commitRemove(CWriteableImplyOrder *pImplyOrder);

	///所有相关的触发器
	vector<CImplyOrderActionTrigger *> *pActionTriggers;
	vector<CImplyOrderCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableImplyOrder compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CQuoteFactory是一个报价的对象工厂。它包含了一批报价，
///同时又建立了如下索引，以方便查询：
///	QuoteIDIndex
///	PartClientAndInstrumentIndex
///	QuoteLocalIDIndex
///使用本对象工厂，可以完成对报价的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByQuoteID，唯一找到对象
///		使用findByQuoteLocalID，唯一找到对象
///		使用startFindByUserID，findNextByUserID和endFindByUserID完成查询操作
///		使用findByPartClientAndInstrument，唯一找到对象
///		使用startFindStartByParticipantID，findNextStartByParticipantID和endFindStartByParticipantID完成查询操作
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByAskOrder，唯一找到对象
///		使用findByBidOrder，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CQuoteFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxQuote，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CQuoteFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CQuoteFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的Quote
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的Quote，文件名将根据配置文件中的定义QuoteCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的Quote
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的Quote，文件名将根据配置文件中的定义QuoteCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CQuoteResource;

	///将一个CQuote加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pQuote	要加入的Quote
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CQuote *add(CWriteableQuote *pQuote, CTransaction *pTransaction=NULL);
	
	///刷新该CQuote的值
	///@param	pQuote	被刷新的CQuote
	///@param	pNewQuote	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CQuote *pQuote, CWriteableQuote *pNewQuote, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pQuote	  需要被刷新或者新增的CQuote,等于NULL表示是需要新增的
	///@param	pNewQuote	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CQuote* addOrUpdate(CQuote *pQuote, CWriteableQuote *pNewQuote, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CQuote，同时删除其索引
	///@param	pQuote	要删除的CQuote
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CQuote *pQuote, CTransaction *pTransaction=NULL);
	
	///获取某个CQuote
	///@param	pQuote	要读取的CQuote
	///@param	pTragetQuote	存放结果的CQuote
	void retrieve(CQuote *pQuote, CWriteableQuote *pTargetQuote);
	
	///获取第一个CQuote
	///@return	得到的第一个CQuote，如果没有，则返回NULL
	CQuote *getFirst(void);
	
	///获取下一个CQuote
	///@return	得到下一个CQuote，如果没有，则返回NULL
	CQuote *getNext(void);
	
	///结束获取CQuote
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CQuoteActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CQuoteActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CQuoteCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CQuoteCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///构造所有对应的合约的指针
	///@param	pFactory	构造对应的合约的指针时，寻找的对象工厂
	void linkAllInstrument(CInstrumentFactory *pFactory);
	
	///构造所有指定的会员客户的指针
	///@param	pFactory	构造指定的会员客户的指针时，寻找的对象工厂
	void linkAllPartClient(CPartClientFactory *pFactory);
	
	///寻找CQuote
	///@param	QuoteSysID	报价编号
	///@return	找到的CQuote，如果找不到，返回NULL
	CQuote *findByQuoteID( const CReadOnlyQuoteSysIDType&  QuoteSysID);



	///寻找CQuote
	///@param	UserID	交易员代码
	///@param	QuoteLocalID	报价本地编号
	///@return	找到的CQuote，如果找不到，返回NULL
	CQuote *findByQuoteLocalID( const CReadOnlyUserIDType&  UserID,  const CReadOnlyOrderLocalIDType&  QuoteLocalID);



	friend class CQuoteIteratorByUserID;

	///开始寻找CQuote
	///@param	UserID	用户
	///@return	满足条件的地一个CQuote，如果找不到，返回NULL
	CQuote *startFindByUserID( const CReadOnlyUserIDType& UserID);

	///寻找下一个符合条件的CQuote，必须在startFindByUserID以后，endFindByUserID之前叫用
	///@return	下一个满足条件CQuote，如果已经没有一个满足要求了，则返回NULL
	CQuote *findNextByUserID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByUserID(void);

	///寻找CQuote
	///@param	ParticipantID	会员号
	///@param	ClientID	客户号
	///@param	InstrumentID	合约号
	///@return	找到的CQuote，如果找不到，返回NULL
	CQuote *findByPartClientAndInstrument( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyClientIDType&  ClientID,  const CReadOnlyInstrumentIDType&  InstrumentID);



	friend class CQuoteIteratorStartByParticipantID;

	///开始寻找CQuote
	///@param	ParticipantID	会员号
	///@return	满足条件的地一个CQuote，如果找不到，返回NULL
	CQuote *startFindStartByParticipantID( const CReadOnlyParticipantIDType& ParticipantID);

	///寻找下一个符合条件的CQuote，必须在startFindStartByParticipantID以后，endFindStartByParticipantID之前叫用
	///@return	下一个满足条件CQuote，如果已经没有一个满足要求了，则返回NULL
	CQuote *findNextStartByParticipantID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindStartByParticipantID(void);

	friend class CQuoteIteratorBySettlementGroupID;

	///开始寻找CQuote
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CQuote，如果找不到，返回NULL
	CQuote *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CQuote，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CQuote，如果已经没有一个满足要求了，则返回NULL
	CQuote *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CQuote
	///@param	AskOrderSysID	卖方报单号
	///@return	找到的CQuote，如果找不到，返回NULL
	CQuote *findByAskOrder( const CReadOnlyOrderSysIDType&  AskOrderSysID);



	///寻找CQuote
	///@param	BidOrderSysID	买方报单号
	///@return	找到的CQuote，如果找不到，返回NULL
	CQuote *findByBidOrder( const CReadOnlyOrderSysIDType&  BidOrderSysID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CQuote加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pQuote	要加入的Quote
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CQuote *internalAdd(CWriteableQuote *pQuote, bool bNoTransaction);
	
	
	///刷新该CQuote的键值
	///@param	pQuote	被刷新的CQuote
	///@param	pNewQuote	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CQuote *pQuote, CWriteableQuote *pNewQuote, bool updateIndex,bool bNoTransaction);
	
	///删除一个CQuote，同时删除其索引
	///@param	pQuote	要删除的CQuote
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CQuote *pQuote, bool bNoTransaction);
/*
	///检查某个CQuote是否属于本对象工厂
	///@param	pQuote	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CQuote *pQuote);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于QuoteSysID的索引
	CAVLTree *pQuoteIDIndex;
	///基于ParticipantID+ClientID+InstrumentID+QuoteSysID的索引
	CAVLTree *pPartClientAndInstrumentIndex;
	///基于UserID+QuoteLocalID的索引
	CAVLTree *pQuoteLocalIDIndex;
	
	///基于AskOrderSysIDHashKey的hash索引
	CHashIndex *pAskOrderHashIndex;
	///基于BidOrderSysIDHashKey的hash索引
	CHashIndex *pBidOrderHashIndex;
	
	///按照UserID检索时，存储的查询参数
	CUserIDType queryUserIDInSearchByUserID;
	
	///按照UserID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByUserID;
	///按照ParticipantID检索时，存储的查询参数
	CParticipantIDType queryParticipantIDInSearchStartByParticipantID;
	
	///按照ParticipantID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchStartByParticipantID;
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CQuote *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pQuote	要加入的Quote
	virtual void beforeAdd(CWriteableQuote *pQuote);
	
	///加入后触发
	///@param	pQuote	已经加入的Quote
	virtual void afterAdd(CQuote *pQuote);

	///更新前触发	
	///@param	pQuote	被刷新的CQuote
	///@param	pNewQuote	新的值
	virtual void beforeUpdate(CQuote *pQuote, CWriteableQuote *pNewQuote);
	
	///更新后触发
	///@param	pQuote	被刷新的CQuote
	virtual void afterUpdate(CQuote *pQuote);
	
	///删除前触发
	///@param	pQuote	要删除的CQuote
	virtual void beforeRemove(CQuote *pQuote);
	
	///确认加入后触发
	///@param	pQuote	已经加入的Quote
	virtual void commitAdd(CQuote *pQuote);

	///确认更新后触发
	///@param	pQuote	被刷新的CQuote
	///@param	poldQuote	原来的值
	virtual void commitUpdate(CQuote *pQuote, CWriteableQuote *pOldQuote);
	
	///确认删除后触发
	///@param	pQuote	已经删除的CQuote
	virtual void commitRemove(CWriteableQuote *pQuote);

	///所有相关的触发器
	vector<CQuoteActionTrigger *> *pActionTriggers;
	vector<CQuoteCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableQuote compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataFactory是一个分价表的对象工厂。它包含了一批分价表，
///同时又建立了如下索引，以方便查询：
///	BuyMBLIndex
///	SellMBLIndex
///	QBuyMBLIndex
///	QSellMBLIndex
///使用本对象工厂，可以完成对分价表的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByBuyMBLData，findNextByBuyMBLData和endFindByBuyMBLData完成查询操作
///		使用startFindBySellMBLData，findNextBySellMBLData和endFindBySellMBLData完成查询操作
///		使用startFindStartByBuyMBLData，findNextStartByBuyMBLData和endFindStartByBuyMBLData完成查询操作
///		使用startFindStartBySellMBLData，findNextStartBySellMBLData和endFindStartBySellMBLData完成查询操作
///		使用findByPrice，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CMBLMarketDataFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxMBLMarketData，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CMBLMarketDataFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CMBLMarketDataFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的MBLMarketData
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的MBLMarketData，文件名将根据配置文件中的定义MBLMarketDataCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的MBLMarketData
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的MBLMarketData，文件名将根据配置文件中的定义MBLMarketDataCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CMBLMarketDataResource;

	///将一个CMBLMarketData加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pMBLMarketData	要加入的MBLMarketData
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CMBLMarketData *add(CWriteableMBLMarketData *pMBLMarketData, CTransaction *pTransaction=NULL);
	
	///刷新该CMBLMarketData的值
	///@param	pMBLMarketData	被刷新的CMBLMarketData
	///@param	pNewMBLMarketData	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CMBLMarketData *pMBLMarketData, CWriteableMBLMarketData *pNewMBLMarketData, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pMBLMarketData	  需要被刷新或者新增的CMBLMarketData,等于NULL表示是需要新增的
	///@param	pNewMBLMarketData	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CMBLMarketData* addOrUpdate(CMBLMarketData *pMBLMarketData, CWriteableMBLMarketData *pNewMBLMarketData, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CMBLMarketData，同时删除其索引
	///@param	pMBLMarketData	要删除的CMBLMarketData
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CMBLMarketData *pMBLMarketData, CTransaction *pTransaction=NULL);
	
	///获取某个CMBLMarketData
	///@param	pMBLMarketData	要读取的CMBLMarketData
	///@param	pTragetMBLMarketData	存放结果的CMBLMarketData
	void retrieve(CMBLMarketData *pMBLMarketData, CWriteableMBLMarketData *pTargetMBLMarketData);
	
	///获取第一个CMBLMarketData
	///@return	得到的第一个CMBLMarketData，如果没有，则返回NULL
	CMBLMarketData *getFirst(void);
	
	///获取下一个CMBLMarketData
	///@return	得到下一个CMBLMarketData，如果没有，则返回NULL
	CMBLMarketData *getNext(void);
	
	///结束获取CMBLMarketData
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CMBLMarketDataActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CMBLMarketDataActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CMBLMarketDataCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CMBLMarketDataCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CMBLMarketDataIteratorByBuyMBLData;

	///开始寻找CMBLMarketData
	///@param	InstrumentID	合约代码
	///@return	满足条件的地一个CMBLMarketData，如果找不到，返回NULL
	CMBLMarketData *startFindByBuyMBLData( const CReadOnlyInstrumentIDType& InstrumentID);

	///寻找下一个符合条件的CMBLMarketData，必须在startFindByBuyMBLData以后，endFindByBuyMBLData之前叫用
	///@return	下一个满足条件CMBLMarketData，如果已经没有一个满足要求了，则返回NULL
	CMBLMarketData *findNextByBuyMBLData(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByBuyMBLData(void);

	friend class CMBLMarketDataIteratorBySellMBLData;

	///开始寻找CMBLMarketData
	///@param	InstrumentID	合约代码
	///@return	满足条件的地一个CMBLMarketData，如果找不到，返回NULL
	CMBLMarketData *startFindBySellMBLData( const CReadOnlyInstrumentIDType& InstrumentID);

	///寻找下一个符合条件的CMBLMarketData，必须在startFindBySellMBLData以后，endFindBySellMBLData之前叫用
	///@return	下一个满足条件CMBLMarketData，如果已经没有一个满足要求了，则返回NULL
	CMBLMarketData *findNextBySellMBLData(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySellMBLData(void);

	friend class CMBLMarketDataIteratorStartByBuyMBLData;

	///开始寻找CMBLMarketData
	///@param	InstrumentID	合约代码
	///@return	满足条件的地一个CMBLMarketData，如果找不到，返回NULL
	CMBLMarketData *startFindStartByBuyMBLData( const CReadOnlyInstrumentIDType& InstrumentID);

	///寻找下一个符合条件的CMBLMarketData，必须在startFindStartByBuyMBLData以后，endFindStartByBuyMBLData之前叫用
	///@return	下一个满足条件CMBLMarketData，如果已经没有一个满足要求了，则返回NULL
	CMBLMarketData *findNextStartByBuyMBLData(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindStartByBuyMBLData(void);

	friend class CMBLMarketDataIteratorStartBySellMBLData;

	///开始寻找CMBLMarketData
	///@param	InstrumentID	合约代码
	///@return	满足条件的地一个CMBLMarketData，如果找不到，返回NULL
	CMBLMarketData *startFindStartBySellMBLData( const CReadOnlyInstrumentIDType& InstrumentID);

	///寻找下一个符合条件的CMBLMarketData，必须在startFindStartBySellMBLData以后，endFindStartBySellMBLData之前叫用
	///@return	下一个满足条件CMBLMarketData，如果已经没有一个满足要求了，则返回NULL
	CMBLMarketData *findNextStartBySellMBLData(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindStartBySellMBLData(void);

	///寻找CMBLMarketData
	///@param	InstrumentID	合约代码
	///@param	Direction	买卖方向
	///@param	Price	价格
	///@return	找到的CMBLMarketData，如果找不到，返回NULL
	CMBLMarketData *findByPrice( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyDirectionType&  Direction,  const CReadOnlyPriceType&  Price);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CMBLMarketData加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pMBLMarketData	要加入的MBLMarketData
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CMBLMarketData *internalAdd(CWriteableMBLMarketData *pMBLMarketData, bool bNoTransaction);
	
	
	///刷新该CMBLMarketData的键值
	///@param	pMBLMarketData	被刷新的CMBLMarketData
	///@param	pNewMBLMarketData	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CMBLMarketData *pMBLMarketData, CWriteableMBLMarketData *pNewMBLMarketData, bool updateIndex,bool bNoTransaction);
	
	///删除一个CMBLMarketData，同时删除其索引
	///@param	pMBLMarketData	要删除的CMBLMarketData
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CMBLMarketData *pMBLMarketData, bool bNoTransaction);
/*
	///检查某个CMBLMarketData是否属于本对象工厂
	///@param	pMBLMarketData	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CMBLMarketData *pMBLMarketData);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于InstrumentID+Direction+Price的索引
	CAVLTree *pBuyMBLIndex;
	///基于InstrumentID+Direction+Price的索引
	CAVLTree *pSellMBLIndex;
	///基于Direction+InstrumentID+Price的索引
	CAVLTree *pQBuyMBLIndex;
	///基于Direction+InstrumentID+Price的索引
	CAVLTree *pQSellMBLIndex;
	
	
	///按照InstrumentID检索时，存储的查询参数
	CInstrumentIDType queryInstrumentIDInSearchByBuyMBLData;
	
	///按照InstrumentID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByBuyMBLData;
	///按照InstrumentID检索时，存储的查询参数
	CInstrumentIDType queryInstrumentIDInSearchBySellMBLData;
	
	///按照InstrumentID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBySellMBLData;
	///按照InstrumentID检索时，存储的查询参数
	CInstrumentIDType queryInstrumentIDInSearchStartByBuyMBLData;
	
	///按照InstrumentID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchStartByBuyMBLData;
	///按照InstrumentID检索时，存储的查询参数
	CInstrumentIDType queryInstrumentIDInSearchStartBySellMBLData;
	
	///按照InstrumentID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchStartBySellMBLData;
	
	///加入前触发
	///@param	pMBLMarketData	要加入的MBLMarketData
	virtual void beforeAdd(CWriteableMBLMarketData *pMBLMarketData);
	
	///加入后触发
	///@param	pMBLMarketData	已经加入的MBLMarketData
	virtual void afterAdd(CMBLMarketData *pMBLMarketData);

	///更新前触发	
	///@param	pMBLMarketData	被刷新的CMBLMarketData
	///@param	pNewMBLMarketData	新的值
	virtual void beforeUpdate(CMBLMarketData *pMBLMarketData, CWriteableMBLMarketData *pNewMBLMarketData);
	
	///更新后触发
	///@param	pMBLMarketData	被刷新的CMBLMarketData
	virtual void afterUpdate(CMBLMarketData *pMBLMarketData);
	
	///删除前触发
	///@param	pMBLMarketData	要删除的CMBLMarketData
	virtual void beforeRemove(CMBLMarketData *pMBLMarketData);
	
	///确认加入后触发
	///@param	pMBLMarketData	已经加入的MBLMarketData
	virtual void commitAdd(CMBLMarketData *pMBLMarketData);

	///确认更新后触发
	///@param	pMBLMarketData	被刷新的CMBLMarketData
	///@param	poldMBLMarketData	原来的值
	virtual void commitUpdate(CMBLMarketData *pMBLMarketData, CWriteableMBLMarketData *pOldMBLMarketData);
	
	///确认删除后触发
	///@param	pMBLMarketData	已经删除的CMBLMarketData
	virtual void commitRemove(CWriteableMBLMarketData *pMBLMarketData);

	///所有相关的触发器
	vector<CMBLMarketDataActionTrigger *> *pActionTriggers;
	vector<CMBLMarketDataCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableMBLMarketData compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CTradeFactory是一个成交的对象工厂。它包含了一批成交，
///同时又建立了如下索引，以方便查询：
///	TradeIDIndex
///	PartIDIndex
///	ClientIDIndex
///	InstrumentIDIndex
///使用本对象工厂，可以完成对成交的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindAll，findNextAll和endFindAll完成查询操作
///		使用startFindByTradeID，findNextByTradeID和endFindByTradeID完成查询操作
///		使用startFindStartByPartID，findNextStartByPartID和endFindStartByPartID完成查询操作
///		使用startFindByClientID，findNextByClientID和endFindByClientID完成查询操作
///		使用startFindStartByInstrumentID，findNextStartByInstrumentID和endFindStartByInstrumentID完成查询操作
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CTradeFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxTrade，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CTradeFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CTradeFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的Trade
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的Trade，文件名将根据配置文件中的定义TradeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的Trade
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的Trade，文件名将根据配置文件中的定义TradeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CTradeResource;

	///将一个CTrade加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pTrade	要加入的Trade
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CTrade *add(CWriteableTrade *pTrade, CTransaction *pTransaction=NULL);
	
	///刷新该CTrade的值
	///@param	pTrade	被刷新的CTrade
	///@param	pNewTrade	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CTrade *pTrade, CWriteableTrade *pNewTrade, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pTrade	  需要被刷新或者新增的CTrade,等于NULL表示是需要新增的
	///@param	pNewTrade	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CTrade* addOrUpdate(CTrade *pTrade, CWriteableTrade *pNewTrade, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CTrade，同时删除其索引
	///@param	pTrade	要删除的CTrade
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CTrade *pTrade, CTransaction *pTransaction=NULL);
	
	///获取某个CTrade
	///@param	pTrade	要读取的CTrade
	///@param	pTragetTrade	存放结果的CTrade
	void retrieve(CTrade *pTrade, CWriteableTrade *pTargetTrade);
	
	///获取第一个CTrade
	///@return	得到的第一个CTrade，如果没有，则返回NULL
	CTrade *getFirst(void);
	
	///获取下一个CTrade
	///@return	得到下一个CTrade，如果没有，则返回NULL
	CTrade *getNext(void);
	
	///结束获取CTrade
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CTradeActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CTradeActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CTradeCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CTradeCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///构造所有对应的合约的指针
	///@param	pFactory	构造对应的合约的指针时，寻找的对象工厂
	void linkAllInstrument(CInstrumentFactory *pFactory);
	
	///构造所有指定的会员客户的指针
	///@param	pFactory	构造指定的会员客户的指针时，寻找的对象工厂
	void linkAllPartClient(CPartClientFactory *pFactory);
	
	friend class CTradeIteratorAll;

	///开始寻找CTrade
	///@return	满足条件的地一个CTrade，如果找不到，返回NULL
	CTrade *startFindAll();

	///寻找下一个符合条件的CTrade，必须在startFindAll以后，endFindAll之前叫用
	///@return	下一个满足条件CTrade，如果已经没有一个满足要求了，则返回NULL
	CTrade *findNextAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindAll(void);

	friend class CTradeIteratorByTradeID;

	///开始寻找CTrade
	///@param	TradeID	成交编号
	///@return	满足条件的地一个CTrade，如果找不到，返回NULL
	CTrade *startFindByTradeID( const CReadOnlyTradeIDType& TradeID);

	///寻找下一个符合条件的CTrade，必须在startFindByTradeID以后，endFindByTradeID之前叫用
	///@return	下一个满足条件CTrade，如果已经没有一个满足要求了，则返回NULL
	CTrade *findNextByTradeID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByTradeID(void);

	friend class CTradeIteratorStartByPartID;

	///开始寻找CTrade
	///@param	ParticipantID	会员号
	///@return	满足条件的地一个CTrade，如果找不到，返回NULL
	CTrade *startFindStartByPartID( const CReadOnlyParticipantIDType& ParticipantID);

	///寻找下一个符合条件的CTrade，必须在startFindStartByPartID以后，endFindStartByPartID之前叫用
	///@return	下一个满足条件CTrade，如果已经没有一个满足要求了，则返回NULL
	CTrade *findNextStartByPartID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindStartByPartID(void);

	friend class CTradeIteratorByClientID;

	///开始寻找CTrade
	///@param	ClientID	客户号
	///@return	满足条件的地一个CTrade，如果找不到，返回NULL
	CTrade *startFindByClientID( const CReadOnlyClientIDType& ClientID);

	///寻找下一个符合条件的CTrade，必须在startFindByClientID以后，endFindByClientID之前叫用
	///@return	下一个满足条件CTrade，如果已经没有一个满足要求了，则返回NULL
	CTrade *findNextByClientID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByClientID(void);

	friend class CTradeIteratorStartByInstrumentID;

	///开始寻找CTrade
	///@param	InstrumentID	合约号
	///@return	满足条件的地一个CTrade，如果找不到，返回NULL
	CTrade *startFindStartByInstrumentID( const CReadOnlyInstrumentIDType& InstrumentID);

	///寻找下一个符合条件的CTrade，必须在startFindStartByInstrumentID以后，endFindStartByInstrumentID之前叫用
	///@return	下一个满足条件CTrade，如果已经没有一个满足要求了，则返回NULL
	CTrade *findNextStartByInstrumentID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindStartByInstrumentID(void);

	friend class CTradeIteratorBySettlementGroupID;

	///开始寻找CTrade
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CTrade，如果找不到，返回NULL
	CTrade *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CTrade，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CTrade，如果已经没有一个满足要求了，则返回NULL
	CTrade *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CTrade加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pTrade	要加入的Trade
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CTrade *internalAdd(CWriteableTrade *pTrade, bool bNoTransaction);
	
	
	///刷新该CTrade的键值
	///@param	pTrade	被刷新的CTrade
	///@param	pNewTrade	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CTrade *pTrade, CWriteableTrade *pNewTrade, bool updateIndex,bool bNoTransaction);
	
	///删除一个CTrade，同时删除其索引
	///@param	pTrade	要删除的CTrade
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CTrade *pTrade, bool bNoTransaction);
/*
	///检查某个CTrade是否属于本对象工厂
	///@param	pTrade	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CTrade *pTrade);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于TradeID+ParticipantID+ClientID+InstrumentID的索引
	CAVLTree *pTradeIDIndex;
	///基于ParticipantID+TradeID+ClientID+InstrumentID的索引
	CAVLTree *pPartIDIndex;
	///基于ClientID+TradeID的索引
	CAVLTree *pClientIDIndex;
	///基于InstrumentID+TradeID的索引
	CAVLTree *pInstrumentIDIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchAll;
	///按照TradeID检索时，存储的查询参数
	CTradeIDType queryTradeIDInSearchByTradeID;
	
	///按照TradeID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByTradeID;
	///按照ParticipantID检索时，存储的查询参数
	CParticipantIDType queryParticipantIDInSearchStartByPartID;
	
	///按照ParticipantID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchStartByPartID;
	///按照ClientID检索时，存储的查询参数
	CClientIDType queryClientIDInSearchByClientID;
	
	///按照ClientID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByClientID;
	///按照InstrumentID检索时，存储的查询参数
	CInstrumentIDType queryInstrumentIDInSearchStartByInstrumentID;
	
	///按照InstrumentID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchStartByInstrumentID;
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CTrade *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pTrade	要加入的Trade
	virtual void beforeAdd(CWriteableTrade *pTrade);
	
	///加入后触发
	///@param	pTrade	已经加入的Trade
	virtual void afterAdd(CTrade *pTrade);

	///更新前触发	
	///@param	pTrade	被刷新的CTrade
	///@param	pNewTrade	新的值
	virtual void beforeUpdate(CTrade *pTrade, CWriteableTrade *pNewTrade);
	
	///更新后触发
	///@param	pTrade	被刷新的CTrade
	virtual void afterUpdate(CTrade *pTrade);
	
	///删除前触发
	///@param	pTrade	要删除的CTrade
	virtual void beforeRemove(CTrade *pTrade);
	
	///确认加入后触发
	///@param	pTrade	已经加入的Trade
	virtual void commitAdd(CTrade *pTrade);

	///确认更新后触发
	///@param	pTrade	被刷新的CTrade
	///@param	poldTrade	原来的值
	virtual void commitUpdate(CTrade *pTrade, CWriteableTrade *pOldTrade);
	
	///确认删除后触发
	///@param	pTrade	已经删除的CTrade
	virtual void commitRemove(CWriteableTrade *pTrade);

	///所有相关的触发器
	vector<CTradeActionTrigger *> *pActionTriggers;
	vector<CTradeCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableTrade compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CFusePhaseFactory是一个熔断阶段的对象工厂。它包含了一批熔断阶段，
///同时又建立了如下索引，以方便查询：
///	InstrumentIDIndex
///使用本对象工厂，可以完成对熔断阶段的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByInstrumentID，唯一找到对象
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhaseFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CFusePhaseFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxFusePhase，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CFusePhaseFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CFusePhaseFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的FusePhase
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的FusePhase，文件名将根据配置文件中的定义FusePhaseCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的FusePhase
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的FusePhase，文件名将根据配置文件中的定义FusePhaseCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CFusePhaseResource;

	///将一个CFusePhase加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pFusePhase	要加入的FusePhase
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CFusePhase *add(CWriteableFusePhase *pFusePhase, CTransaction *pTransaction=NULL);
	
	///刷新该CFusePhase的值
	///@param	pFusePhase	被刷新的CFusePhase
	///@param	pNewFusePhase	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CFusePhase *pFusePhase, CWriteableFusePhase *pNewFusePhase, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pFusePhase	  需要被刷新或者新增的CFusePhase,等于NULL表示是需要新增的
	///@param	pNewFusePhase	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CFusePhase* addOrUpdate(CFusePhase *pFusePhase, CWriteableFusePhase *pNewFusePhase, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CFusePhase，同时删除其索引
	///@param	pFusePhase	要删除的CFusePhase
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CFusePhase *pFusePhase, CTransaction *pTransaction=NULL);
	
	///获取某个CFusePhase
	///@param	pFusePhase	要读取的CFusePhase
	///@param	pTragetFusePhase	存放结果的CFusePhase
	void retrieve(CFusePhase *pFusePhase, CWriteableFusePhase *pTargetFusePhase);
	
	///获取第一个CFusePhase
	///@return	得到的第一个CFusePhase，如果没有，则返回NULL
	CFusePhase *getFirst(void);
	
	///获取下一个CFusePhase
	///@return	得到下一个CFusePhase，如果没有，则返回NULL
	CFusePhase *getNext(void);
	
	///结束获取CFusePhase
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CFusePhaseActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CFusePhaseActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CFusePhaseCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CFusePhaseCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///构造所有对应的合约的指针
	///@param	pFactory	构造对应的合约的指针时，寻找的对象工厂
	void linkAllInstrument(CInstrumentFactory *pFactory);
	
	///寻找CFusePhase
	///@param	InstrumentID	合约代码
	///@return	找到的CFusePhase，如果找不到，返回NULL
	CFusePhase *findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID);



	friend class CFusePhaseIteratorBySettlementGroupID;

	///开始寻找CFusePhase
	///@param	SettlementGroupID	结算组编号
	///@return	满足条件的地一个CFusePhase，如果找不到，返回NULL
	CFusePhase *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CFusePhase，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CFusePhase，如果已经没有一个满足要求了，则返回NULL
	CFusePhase *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CFusePhase加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pFusePhase	要加入的FusePhase
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CFusePhase *internalAdd(CWriteableFusePhase *pFusePhase, bool bNoTransaction);
	
	
	///刷新该CFusePhase的键值
	///@param	pFusePhase	被刷新的CFusePhase
	///@param	pNewFusePhase	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CFusePhase *pFusePhase, CWriteableFusePhase *pNewFusePhase, bool updateIndex,bool bNoTransaction);
	
	///删除一个CFusePhase，同时删除其索引
	///@param	pFusePhase	要删除的CFusePhase
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CFusePhase *pFusePhase, bool bNoTransaction);
/*
	///检查某个CFusePhase是否属于本对象工厂
	///@param	pFusePhase	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CFusePhase *pFusePhase);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于InstrumentID的索引
	CAVLTree *pInstrumentIDIndex;
	
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CFusePhase *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pFusePhase	要加入的FusePhase
	virtual void beforeAdd(CWriteableFusePhase *pFusePhase);
	
	///加入后触发
	///@param	pFusePhase	已经加入的FusePhase
	virtual void afterAdd(CFusePhase *pFusePhase);

	///更新前触发	
	///@param	pFusePhase	被刷新的CFusePhase
	///@param	pNewFusePhase	新的值
	virtual void beforeUpdate(CFusePhase *pFusePhase, CWriteableFusePhase *pNewFusePhase);
	
	///更新后触发
	///@param	pFusePhase	被刷新的CFusePhase
	virtual void afterUpdate(CFusePhase *pFusePhase);
	
	///删除前触发
	///@param	pFusePhase	要删除的CFusePhase
	virtual void beforeRemove(CFusePhase *pFusePhase);
	
	///确认加入后触发
	///@param	pFusePhase	已经加入的FusePhase
	virtual void commitAdd(CFusePhase *pFusePhase);

	///确认更新后触发
	///@param	pFusePhase	被刷新的CFusePhase
	///@param	poldFusePhase	原来的值
	virtual void commitUpdate(CFusePhase *pFusePhase, CWriteableFusePhase *pOldFusePhase);
	
	///确认删除后触发
	///@param	pFusePhase	已经删除的CFusePhase
	virtual void commitRemove(CWriteableFusePhase *pFusePhase);

	///所有相关的触发器
	vector<CFusePhaseActionTrigger *> *pActionTriggers;
	vector<CFusePhaseCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableFusePhase compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CExecOrderFactory是一个执行宣告的对象工厂。它包含了一批执行宣告，
///同时又建立了如下索引，以方便查询：
///	ExecOrderIDIndex
///	ParticipantIDIndex
///	ClientAndInstrumentIndex
///	ExecOrderLocalIDIndex
///	InstrumentIDIndex
///使用本对象工厂，可以完成对执行宣告的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByExecOrderID，唯一找到对象
///		使用startFindByParticipantID，findNextByParticipantID和endFindByParticipantID完成查询操作
///		使用startFindByClientID，findNextByClientID和endFindByClientID完成查询操作
///		使用startFindByClientIDAndInstrumentID，findNextByClientIDAndInstrumentID和endFindByClientIDAndInstrumentID完成查询操作
///		使用findByExecOrderLocalID，唯一找到对象
///		使用startFindByUserID，findNextByUserID和endFindByUserID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CExecOrderFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxExecOrder，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CExecOrderFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CExecOrderFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的ExecOrder
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的ExecOrder，文件名将根据配置文件中的定义ExecOrderCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的ExecOrder
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的ExecOrder，文件名将根据配置文件中的定义ExecOrderCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CExecOrderResource;

	///将一个CExecOrder加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pExecOrder	要加入的ExecOrder
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CExecOrder *add(CWriteableExecOrder *pExecOrder, CTransaction *pTransaction=NULL);
	
	///刷新该CExecOrder的值
	///@param	pExecOrder	被刷新的CExecOrder
	///@param	pNewExecOrder	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CExecOrder *pExecOrder, CWriteableExecOrder *pNewExecOrder, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pExecOrder	  需要被刷新或者新增的CExecOrder,等于NULL表示是需要新增的
	///@param	pNewExecOrder	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CExecOrder* addOrUpdate(CExecOrder *pExecOrder, CWriteableExecOrder *pNewExecOrder, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CExecOrder，同时删除其索引
	///@param	pExecOrder	要删除的CExecOrder
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CExecOrder *pExecOrder, CTransaction *pTransaction=NULL);
	
	///获取某个CExecOrder
	///@param	pExecOrder	要读取的CExecOrder
	///@param	pTragetExecOrder	存放结果的CExecOrder
	void retrieve(CExecOrder *pExecOrder, CWriteableExecOrder *pTargetExecOrder);
	
	///获取第一个CExecOrder
	///@return	得到的第一个CExecOrder，如果没有，则返回NULL
	CExecOrder *getFirst(void);
	
	///获取下一个CExecOrder
	///@return	得到下一个CExecOrder，如果没有，则返回NULL
	CExecOrder *getNext(void);
	
	///结束获取CExecOrder
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CExecOrderActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CExecOrderActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CExecOrderCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CExecOrderCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///构造所有指定的会员客户的指针
	///@param	pFactory	构造指定的会员客户的指针时，寻找的对象工厂
	void linkAllPartClient(CPartClientFactory *pFactory);
	
	///构造所有对应的合约的指针
	///@param	pFactory	构造对应的合约的指针时，寻找的对象工厂
	void linkAllInstrument(CInstrumentFactory *pFactory);
	
	friend class CExecOrderIteratorBySettlementGroupID;

	///开始寻找CExecOrder
	///@param	SettlementGroupID	结算组编号
	///@return	满足条件的地一个CExecOrder，如果找不到，返回NULL
	CExecOrder *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CExecOrder，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CExecOrder，如果已经没有一个满足要求了，则返回NULL
	CExecOrder *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CExecOrder
	///@param	ExecOrderSysID	执行宣告系统编号
	///@return	找到的CExecOrder，如果找不到，返回NULL
	CExecOrder *findByExecOrderID( const CReadOnlyExecOrderSysIDType&  ExecOrderSysID);



	friend class CExecOrderIteratorByParticipantID;

	///开始寻找CExecOrder
	///@param	ParticipantID	会员号
	///@return	满足条件的地一个CExecOrder，如果找不到，返回NULL
	CExecOrder *startFindByParticipantID( const CReadOnlyParticipantIDType& ParticipantID);

	///寻找下一个符合条件的CExecOrder，必须在startFindByParticipantID以后，endFindByParticipantID之前叫用
	///@return	下一个满足条件CExecOrder，如果已经没有一个满足要求了，则返回NULL
	CExecOrder *findNextByParticipantID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByParticipantID(void);

	friend class CExecOrderIteratorByClientID;

	///开始寻找CExecOrder
	///@param	ClientID	客户号
	///@return	满足条件的地一个CExecOrder，如果找不到，返回NULL
	CExecOrder *startFindByClientID( const CReadOnlyClientIDType& ClientID);

	///寻找下一个符合条件的CExecOrder，必须在startFindByClientID以后，endFindByClientID之前叫用
	///@return	下一个满足条件CExecOrder，如果已经没有一个满足要求了，则返回NULL
	CExecOrder *findNextByClientID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByClientID(void);

	friend class CExecOrderIteratorByClientIDAndInstrumentID;

	///开始寻找CExecOrder
	///@param	ClientID	客户号
	///@param	InstrumentID	合约号
	///@return	满足条件的地一个CExecOrder，如果找不到，返回NULL
	CExecOrder *startFindByClientIDAndInstrumentID( const CReadOnlyClientIDType& ClientID,  const CReadOnlyInstrumentIDType& InstrumentID);

	///寻找下一个符合条件的CExecOrder，必须在startFindByClientIDAndInstrumentID以后，endFindByClientIDAndInstrumentID之前叫用
	///@return	下一个满足条件CExecOrder，如果已经没有一个满足要求了，则返回NULL
	CExecOrder *findNextByClientIDAndInstrumentID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByClientIDAndInstrumentID(void);

	///寻找CExecOrder
	///@param	UserID	交易员代码
	///@param	ExecOrderLocalID	报单本地编号
	///@return	找到的CExecOrder，如果找不到，返回NULL
	CExecOrder *findByExecOrderLocalID( const CReadOnlyUserIDType&  UserID,  const CReadOnlyOrderLocalIDType&  ExecOrderLocalID);



	friend class CExecOrderIteratorByUserID;

	///开始寻找CExecOrder
	///@param	UserID	交易员代码
	///@return	满足条件的地一个CExecOrder，如果找不到，返回NULL
	CExecOrder *startFindByUserID( const CReadOnlyUserIDType& UserID);

	///寻找下一个符合条件的CExecOrder，必须在startFindByUserID以后，endFindByUserID之前叫用
	///@return	下一个满足条件CExecOrder，如果已经没有一个满足要求了，则返回NULL
	CExecOrder *findNextByUserID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByUserID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CExecOrder加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pExecOrder	要加入的ExecOrder
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CExecOrder *internalAdd(CWriteableExecOrder *pExecOrder, bool bNoTransaction);
	
	
	///刷新该CExecOrder的键值
	///@param	pExecOrder	被刷新的CExecOrder
	///@param	pNewExecOrder	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CExecOrder *pExecOrder, CWriteableExecOrder *pNewExecOrder, bool updateIndex,bool bNoTransaction);
	
	///删除一个CExecOrder，同时删除其索引
	///@param	pExecOrder	要删除的CExecOrder
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CExecOrder *pExecOrder, bool bNoTransaction);
/*
	///检查某个CExecOrder是否属于本对象工厂
	///@param	pExecOrder	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CExecOrder *pExecOrder);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ExecOrderSysID的索引
	CAVLTree *pExecOrderIDIndex;
	///基于ParticipantID的索引
	CAVLTree *pParticipantIDIndex;
	///基于ClientID+InstrumentID的索引
	CAVLTree *pClientAndInstrumentIndex;
	///基于UserID+ExecOrderLocalID的索引
	CAVLTree *pExecOrderLocalIDIndex;
	///基于InstrumentID的索引
	CAVLTree *pInstrumentIDIndex;
	
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CExecOrder *pLastFoundInSearchBySettlementGroupID;
	///按照ParticipantID检索时，存储的查询参数
	CParticipantIDType queryParticipantIDInSearchByParticipantID;
	
	///按照ParticipantID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByParticipantID;
	///按照ClientID检索时，存储的查询参数
	CClientIDType queryClientIDInSearchByClientID;
	
	///按照ClientID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByClientID;
	///按照ClientID，InstrumentID检索时，存储的查询参数
	CClientIDType queryClientIDInSearchByClientIDAndInstrumentID;
	CInstrumentIDType queryInstrumentIDInSearchByClientIDAndInstrumentID;
	
	///按照ClientID，InstrumentID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByClientIDAndInstrumentID;
	///按照UserID检索时，存储的查询参数
	CUserIDType queryUserIDInSearchByUserID;
	
	///按照UserID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByUserID;
	
	///加入前触发
	///@param	pExecOrder	要加入的ExecOrder
	virtual void beforeAdd(CWriteableExecOrder *pExecOrder);
	
	///加入后触发
	///@param	pExecOrder	已经加入的ExecOrder
	virtual void afterAdd(CExecOrder *pExecOrder);

	///更新前触发	
	///@param	pExecOrder	被刷新的CExecOrder
	///@param	pNewExecOrder	新的值
	virtual void beforeUpdate(CExecOrder *pExecOrder, CWriteableExecOrder *pNewExecOrder);
	
	///更新后触发
	///@param	pExecOrder	被刷新的CExecOrder
	virtual void afterUpdate(CExecOrder *pExecOrder);
	
	///删除前触发
	///@param	pExecOrder	要删除的CExecOrder
	virtual void beforeRemove(CExecOrder *pExecOrder);
	
	///确认加入后触发
	///@param	pExecOrder	已经加入的ExecOrder
	virtual void commitAdd(CExecOrder *pExecOrder);

	///确认更新后触发
	///@param	pExecOrder	被刷新的CExecOrder
	///@param	poldExecOrder	原来的值
	virtual void commitUpdate(CExecOrder *pExecOrder, CWriteableExecOrder *pOldExecOrder);
	
	///确认删除后触发
	///@param	pExecOrder	已经删除的CExecOrder
	virtual void commitRemove(CWriteableExecOrder *pExecOrder);

	///所有相关的触发器
	vector<CExecOrderActionTrigger *> *pActionTriggers;
	vector<CExecOrderCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableExecOrder compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CUniPressureFactory是一个单边市情况的对象工厂。它包含了一批单边市情况，
///同时又建立了如下索引，以方便查询：
///	InstrumentIDIndex
///使用本对象工厂，可以完成对单边市情况的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByInstrumentID，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressureFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CUniPressureFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxUniPressure，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CUniPressureFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CUniPressureFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的UniPressure
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的UniPressure，文件名将根据配置文件中的定义UniPressureCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的UniPressure
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的UniPressure，文件名将根据配置文件中的定义UniPressureCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CUniPressureResource;

	///将一个CUniPressure加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pUniPressure	要加入的UniPressure
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CUniPressure *add(CWriteableUniPressure *pUniPressure, CTransaction *pTransaction=NULL);
	
	///刷新该CUniPressure的值
	///@param	pUniPressure	被刷新的CUniPressure
	///@param	pNewUniPressure	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CUniPressure *pUniPressure, CWriteableUniPressure *pNewUniPressure, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pUniPressure	  需要被刷新或者新增的CUniPressure,等于NULL表示是需要新增的
	///@param	pNewUniPressure	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CUniPressure* addOrUpdate(CUniPressure *pUniPressure, CWriteableUniPressure *pNewUniPressure, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CUniPressure，同时删除其索引
	///@param	pUniPressure	要删除的CUniPressure
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CUniPressure *pUniPressure, CTransaction *pTransaction=NULL);
	
	///获取某个CUniPressure
	///@param	pUniPressure	要读取的CUniPressure
	///@param	pTragetUniPressure	存放结果的CUniPressure
	void retrieve(CUniPressure *pUniPressure, CWriteableUniPressure *pTargetUniPressure);
	
	///获取第一个CUniPressure
	///@return	得到的第一个CUniPressure，如果没有，则返回NULL
	CUniPressure *getFirst(void);
	
	///获取下一个CUniPressure
	///@return	得到下一个CUniPressure，如果没有，则返回NULL
	CUniPressure *getNext(void);
	
	///结束获取CUniPressure
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CUniPressureActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CUniPressureActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CUniPressureCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CUniPressureCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CUniPressureIteratorBySettlementGroupID;

	///开始寻找CUniPressure
	///@param	SettlementGroupID	结算组编号
	///@return	满足条件的地一个CUniPressure，如果找不到，返回NULL
	CUniPressure *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CUniPressure，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CUniPressure，如果已经没有一个满足要求了，则返回NULL
	CUniPressure *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CUniPressure
	///@param	InstrumentID	合约代码
	///@return	找到的CUniPressure，如果找不到，返回NULL
	CUniPressure *findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CUniPressure加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pUniPressure	要加入的UniPressure
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CUniPressure *internalAdd(CWriteableUniPressure *pUniPressure, bool bNoTransaction);
	
	
	///刷新该CUniPressure的键值
	///@param	pUniPressure	被刷新的CUniPressure
	///@param	pNewUniPressure	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CUniPressure *pUniPressure, CWriteableUniPressure *pNewUniPressure, bool updateIndex,bool bNoTransaction);
	
	///删除一个CUniPressure，同时删除其索引
	///@param	pUniPressure	要删除的CUniPressure
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CUniPressure *pUniPressure, bool bNoTransaction);
/*
	///检查某个CUniPressure是否属于本对象工厂
	///@param	pUniPressure	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CUniPressure *pUniPressure);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于InstrumentID的索引
	CAVLTree *pInstrumentIDIndex;
	
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CUniPressure *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pUniPressure	要加入的UniPressure
	virtual void beforeAdd(CWriteableUniPressure *pUniPressure);
	
	///加入后触发
	///@param	pUniPressure	已经加入的UniPressure
	virtual void afterAdd(CUniPressure *pUniPressure);

	///更新前触发	
	///@param	pUniPressure	被刷新的CUniPressure
	///@param	pNewUniPressure	新的值
	virtual void beforeUpdate(CUniPressure *pUniPressure, CWriteableUniPressure *pNewUniPressure);
	
	///更新后触发
	///@param	pUniPressure	被刷新的CUniPressure
	virtual void afterUpdate(CUniPressure *pUniPressure);
	
	///删除前触发
	///@param	pUniPressure	要删除的CUniPressure
	virtual void beforeRemove(CUniPressure *pUniPressure);
	
	///确认加入后触发
	///@param	pUniPressure	已经加入的UniPressure
	virtual void commitAdd(CUniPressure *pUniPressure);

	///确认更新后触发
	///@param	pUniPressure	被刷新的CUniPressure
	///@param	poldUniPressure	原来的值
	virtual void commitUpdate(CUniPressure *pUniPressure, CWriteableUniPressure *pOldUniPressure);
	
	///确认删除后触发
	///@param	pUniPressure	已经删除的CUniPressure
	virtual void commitRemove(CWriteableUniPressure *pUniPressure);

	///所有相关的触发器
	vector<CUniPressureActionTrigger *> *pActionTriggers;
	vector<CUniPressureCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableUniPressure compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitFactory是一个涨跌停板设置的对象工厂。它包含了一批涨跌停板设置，
///同时又建立了如下索引，以方便查询：
///	InstrumentIDIndex
///使用本对象工厂，可以完成对涨跌停板设置的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByInstrumentID，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CBasePriceLimitFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxBasePriceLimit，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CBasePriceLimitFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CBasePriceLimitFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的BasePriceLimit
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的BasePriceLimit，文件名将根据配置文件中的定义BasePriceLimitCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的BasePriceLimit
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的BasePriceLimit，文件名将根据配置文件中的定义BasePriceLimitCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CBasePriceLimitResource;

	///将一个CBasePriceLimit加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pBasePriceLimit	要加入的BasePriceLimit
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CBasePriceLimit *add(CWriteableBasePriceLimit *pBasePriceLimit, CTransaction *pTransaction=NULL);
	
	///刷新该CBasePriceLimit的值
	///@param	pBasePriceLimit	被刷新的CBasePriceLimit
	///@param	pNewBasePriceLimit	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CBasePriceLimit *pBasePriceLimit, CWriteableBasePriceLimit *pNewBasePriceLimit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pBasePriceLimit	  需要被刷新或者新增的CBasePriceLimit,等于NULL表示是需要新增的
	///@param	pNewBasePriceLimit	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CBasePriceLimit* addOrUpdate(CBasePriceLimit *pBasePriceLimit, CWriteableBasePriceLimit *pNewBasePriceLimit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CBasePriceLimit，同时删除其索引
	///@param	pBasePriceLimit	要删除的CBasePriceLimit
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CBasePriceLimit *pBasePriceLimit, CTransaction *pTransaction=NULL);
	
	///获取某个CBasePriceLimit
	///@param	pBasePriceLimit	要读取的CBasePriceLimit
	///@param	pTragetBasePriceLimit	存放结果的CBasePriceLimit
	void retrieve(CBasePriceLimit *pBasePriceLimit, CWriteableBasePriceLimit *pTargetBasePriceLimit);
	
	///获取第一个CBasePriceLimit
	///@return	得到的第一个CBasePriceLimit，如果没有，则返回NULL
	CBasePriceLimit *getFirst(void);
	
	///获取下一个CBasePriceLimit
	///@return	得到下一个CBasePriceLimit，如果没有，则返回NULL
	CBasePriceLimit *getNext(void);
	
	///结束获取CBasePriceLimit
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CBasePriceLimitActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CBasePriceLimitActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CBasePriceLimitCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CBasePriceLimitCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CBasePriceLimitIteratorBySettlementGroupID;

	///开始寻找CBasePriceLimit
	///@param	SettlementGroupID	结算组编号
	///@return	满足条件的地一个CBasePriceLimit，如果找不到，返回NULL
	CBasePriceLimit *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CBasePriceLimit，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CBasePriceLimit，如果已经没有一个满足要求了，则返回NULL
	CBasePriceLimit *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CBasePriceLimit
	///@param	InstrumentID	合约代码
	///@return	找到的CBasePriceLimit，如果找不到，返回NULL
	CBasePriceLimit *findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CBasePriceLimit加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pBasePriceLimit	要加入的BasePriceLimit
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CBasePriceLimit *internalAdd(CWriteableBasePriceLimit *pBasePriceLimit, bool bNoTransaction);
	
	
	///刷新该CBasePriceLimit的键值
	///@param	pBasePriceLimit	被刷新的CBasePriceLimit
	///@param	pNewBasePriceLimit	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CBasePriceLimit *pBasePriceLimit, CWriteableBasePriceLimit *pNewBasePriceLimit, bool updateIndex,bool bNoTransaction);
	
	///删除一个CBasePriceLimit，同时删除其索引
	///@param	pBasePriceLimit	要删除的CBasePriceLimit
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CBasePriceLimit *pBasePriceLimit, bool bNoTransaction);
/*
	///检查某个CBasePriceLimit是否属于本对象工厂
	///@param	pBasePriceLimit	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CBasePriceLimit *pBasePriceLimit);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于InstrumentID的索引
	CAVLTree *pInstrumentIDIndex;
	
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CBasePriceLimit *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pBasePriceLimit	要加入的BasePriceLimit
	virtual void beforeAdd(CWriteableBasePriceLimit *pBasePriceLimit);
	
	///加入后触发
	///@param	pBasePriceLimit	已经加入的BasePriceLimit
	virtual void afterAdd(CBasePriceLimit *pBasePriceLimit);

	///更新前触发	
	///@param	pBasePriceLimit	被刷新的CBasePriceLimit
	///@param	pNewBasePriceLimit	新的值
	virtual void beforeUpdate(CBasePriceLimit *pBasePriceLimit, CWriteableBasePriceLimit *pNewBasePriceLimit);
	
	///更新后触发
	///@param	pBasePriceLimit	被刷新的CBasePriceLimit
	virtual void afterUpdate(CBasePriceLimit *pBasePriceLimit);
	
	///删除前触发
	///@param	pBasePriceLimit	要删除的CBasePriceLimit
	virtual void beforeRemove(CBasePriceLimit *pBasePriceLimit);
	
	///确认加入后触发
	///@param	pBasePriceLimit	已经加入的BasePriceLimit
	virtual void commitAdd(CBasePriceLimit *pBasePriceLimit);

	///确认更新后触发
	///@param	pBasePriceLimit	被刷新的CBasePriceLimit
	///@param	poldBasePriceLimit	原来的值
	virtual void commitUpdate(CBasePriceLimit *pBasePriceLimit, CWriteableBasePriceLimit *pOldBasePriceLimit);
	
	///确认删除后触发
	///@param	pBasePriceLimit	已经删除的CBasePriceLimit
	virtual void commitRemove(CWriteableBasePriceLimit *pBasePriceLimit);

	///所有相关的触发器
	vector<CBasePriceLimitActionTrigger *> *pActionTriggers;
	vector<CBasePriceLimitCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableBasePriceLimit compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCreditLimitFactory是一个信用限额的对象工厂。它包含了一批信用限额，
///同时又建立了如下索引，以方便查询：
///	ParticipantIDIndex
///使用本对象工厂，可以完成对信用限额的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByParticipantID，唯一找到对象
///		使用startFindAllByParticipantID，findNextAllByParticipantID和endFindAllByParticipantID完成查询操作
///		使用startFindAllByClearingPartID，findNextAllByClearingPartID和endFindAllByClearingPartID完成查询操作
///		使用startFindAll，findNextAll和endFindAll完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCreditLimitFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxCreditLimit，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCreditLimitFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CCreditLimitFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的CreditLimit
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的CreditLimit，文件名将根据配置文件中的定义CreditLimitCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的CreditLimit
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的CreditLimit，文件名将根据配置文件中的定义CreditLimitCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CCreditLimitResource;

	///将一个CCreditLimit加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCreditLimit	要加入的CreditLimit
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCreditLimit *add(CWriteableCreditLimit *pCreditLimit, CTransaction *pTransaction=NULL);
	
	///刷新该CCreditLimit的值
	///@param	pCreditLimit	被刷新的CCreditLimit
	///@param	pNewCreditLimit	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CCreditLimit *pCreditLimit, CWriteableCreditLimit *pNewCreditLimit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pCreditLimit	  需要被刷新或者新增的CCreditLimit,等于NULL表示是需要新增的
	///@param	pNewCreditLimit	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CCreditLimit* addOrUpdate(CCreditLimit *pCreditLimit, CWriteableCreditLimit *pNewCreditLimit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CCreditLimit，同时删除其索引
	///@param	pCreditLimit	要删除的CCreditLimit
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CCreditLimit *pCreditLimit, CTransaction *pTransaction=NULL);
	
	///获取某个CCreditLimit
	///@param	pCreditLimit	要读取的CCreditLimit
	///@param	pTragetCreditLimit	存放结果的CCreditLimit
	void retrieve(CCreditLimit *pCreditLimit, CWriteableCreditLimit *pTargetCreditLimit);
	
	///获取第一个CCreditLimit
	///@return	得到的第一个CCreditLimit，如果没有，则返回NULL
	CCreditLimit *getFirst(void);
	
	///获取下一个CCreditLimit
	///@return	得到下一个CCreditLimit，如果没有，则返回NULL
	CCreditLimit *getNext(void);
	
	///结束获取CCreditLimit
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CCreditLimitActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CCreditLimitActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CCreditLimitCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CCreditLimitCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CCreditLimitIteratorBySettlementGroupID;

	///开始寻找CCreditLimit
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CCreditLimit，如果找不到，返回NULL
	CCreditLimit *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CCreditLimit，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCreditLimit，如果已经没有一个满足要求了，则返回NULL
	CCreditLimit *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CCreditLimit
	///@param	SettlementGroupID	结算组编号
	///@param	ParticipantID	会员编号
	///@return	找到的CCreditLimit，如果找不到，返回NULL
	CCreditLimit *findByParticipantID( const CReadOnlySettlementGroupIDType&  SettlementGroupID,  const CReadOnlyParticipantIDType&  ParticipantID);



	friend class CCreditLimitIteratorAllByParticipantID;

	///开始寻找CCreditLimit
	///@param	ParticipantID	交易会员编号
	///@return	满足条件的地一个CCreditLimit，如果找不到，返回NULL
	CCreditLimit *startFindAllByParticipantID( const CReadOnlyParticipantIDType& ParticipantID);

	///寻找下一个符合条件的CCreditLimit，必须在startFindAllByParticipantID以后，endFindAllByParticipantID之前叫用
	///@return	下一个满足条件CCreditLimit，如果已经没有一个满足要求了，则返回NULL
	CCreditLimit *findNextAllByParticipantID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindAllByParticipantID(void);

	friend class CCreditLimitIteratorAllByClearingPartID;

	///开始寻找CCreditLimit
	///@param	ClearingPartID	结算会员编号
	///@return	满足条件的地一个CCreditLimit，如果找不到，返回NULL
	CCreditLimit *startFindAllByClearingPartID( const CReadOnlyParticipantIDType& ClearingPartID);

	///寻找下一个符合条件的CCreditLimit，必须在startFindAllByClearingPartID以后，endFindAllByClearingPartID之前叫用
	///@return	下一个满足条件CCreditLimit，如果已经没有一个满足要求了，则返回NULL
	CCreditLimit *findNextAllByClearingPartID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindAllByClearingPartID(void);

	friend class CCreditLimitIteratorAll;

	///开始寻找CCreditLimit
	///@return	满足条件的地一个CCreditLimit，如果找不到，返回NULL
	CCreditLimit *startFindAll();

	///寻找下一个符合条件的CCreditLimit，必须在startFindAll以后，endFindAll之前叫用
	///@return	下一个满足条件CCreditLimit，如果已经没有一个满足要求了，则返回NULL
	CCreditLimit *findNextAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindAll(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CCreditLimit加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCreditLimit	要加入的CreditLimit
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCreditLimit *internalAdd(CWriteableCreditLimit *pCreditLimit, bool bNoTransaction);
	
	
	///刷新该CCreditLimit的键值
	///@param	pCreditLimit	被刷新的CCreditLimit
	///@param	pNewCreditLimit	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CCreditLimit *pCreditLimit, CWriteableCreditLimit *pNewCreditLimit, bool updateIndex,bool bNoTransaction);
	
	///删除一个CCreditLimit，同时删除其索引
	///@param	pCreditLimit	要删除的CCreditLimit
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CCreditLimit *pCreditLimit, bool bNoTransaction);
/*
	///检查某个CCreditLimit是否属于本对象工厂
	///@param	pCreditLimit	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CCreditLimit *pCreditLimit);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ParticipantID+SettlementGroupID的索引
	CAVLTree *pParticipantIDIndex;
	
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CCreditLimit *pLastFoundInSearchBySettlementGroupID;
	///按照ParticipantID检索时，存储的查询参数
	CParticipantIDType queryParticipantIDInSearchAllByParticipantID;
	
	///按照ParticipantID检索时，存储最后一次找到的索引节点
	CCreditLimit *pLastFoundInSearchAllByParticipantID;
	///按照ClearingPartID检索时，存储的查询参数
	CParticipantIDType queryClearingPartIDInSearchAllByClearingPartID;
	
	///按照ClearingPartID检索时，存储最后一次找到的索引节点
	CCreditLimit *pLastFoundInSearchAllByClearingPartID;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CCreditLimit *pLastFoundInSearchAll;
	
	///加入前触发
	///@param	pCreditLimit	要加入的CreditLimit
	virtual void beforeAdd(CWriteableCreditLimit *pCreditLimit);
	
	///加入后触发
	///@param	pCreditLimit	已经加入的CreditLimit
	virtual void afterAdd(CCreditLimit *pCreditLimit);

	///更新前触发	
	///@param	pCreditLimit	被刷新的CCreditLimit
	///@param	pNewCreditLimit	新的值
	virtual void beforeUpdate(CCreditLimit *pCreditLimit, CWriteableCreditLimit *pNewCreditLimit);
	
	///更新后触发
	///@param	pCreditLimit	被刷新的CCreditLimit
	virtual void afterUpdate(CCreditLimit *pCreditLimit);
	
	///删除前触发
	///@param	pCreditLimit	要删除的CCreditLimit
	virtual void beforeRemove(CCreditLimit *pCreditLimit);
	
	///确认加入后触发
	///@param	pCreditLimit	已经加入的CreditLimit
	virtual void commitAdd(CCreditLimit *pCreditLimit);

	///确认更新后触发
	///@param	pCreditLimit	被刷新的CCreditLimit
	///@param	poldCreditLimit	原来的值
	virtual void commitUpdate(CCreditLimit *pCreditLimit, CWriteableCreditLimit *pOldCreditLimit);
	
	///确认删除后触发
	///@param	pCreditLimit	已经删除的CCreditLimit
	virtual void commitRemove(CWriteableCreditLimit *pCreditLimit);

	///所有相关的触发器
	vector<CCreditLimitActionTrigger *> *pActionTriggers;
	vector<CCreditLimitCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableCreditLimit compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentOptionFactory是一个当日期货合约期权属性的对象工厂。它包含了一批当日期货合约期权属性，
///同时又建立了如下索引，以方便查询：
///	InstrumentIDIndex
///使用本对象工厂，可以完成对当日期货合约期权属性的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindBySettlementGroupID，findNextBySettlementGroupID和endFindBySettlementGroupID完成查询操作
///		使用findByInstrumentID，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentOptionFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrInstrumentOptionFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxCurrInstrumentOption，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CCurrInstrumentOptionFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CCurrInstrumentOptionFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的CurrInstrumentOption
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的CurrInstrumentOption，文件名将根据配置文件中的定义CurrInstrumentOptionCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的CurrInstrumentOption
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的CurrInstrumentOption，文件名将根据配置文件中的定义CurrInstrumentOptionCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CCurrInstrumentOptionResource;

	///将一个CCurrInstrumentOption加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrInstrumentOption	要加入的CurrInstrumentOption
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrInstrumentOption *add(CWriteableCurrInstrumentOption *pCurrInstrumentOption, CTransaction *pTransaction=NULL);
	
	///刷新该CCurrInstrumentOption的值
	///@param	pCurrInstrumentOption	被刷新的CCurrInstrumentOption
	///@param	pNewCurrInstrumentOption	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CCurrInstrumentOption *pCurrInstrumentOption, CWriteableCurrInstrumentOption *pNewCurrInstrumentOption, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pCurrInstrumentOption	  需要被刷新或者新增的CCurrInstrumentOption,等于NULL表示是需要新增的
	///@param	pNewCurrInstrumentOption	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CCurrInstrumentOption* addOrUpdate(CCurrInstrumentOption *pCurrInstrumentOption, CWriteableCurrInstrumentOption *pNewCurrInstrumentOption, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CCurrInstrumentOption，同时删除其索引
	///@param	pCurrInstrumentOption	要删除的CCurrInstrumentOption
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CCurrInstrumentOption *pCurrInstrumentOption, CTransaction *pTransaction=NULL);
	
	///获取某个CCurrInstrumentOption
	///@param	pCurrInstrumentOption	要读取的CCurrInstrumentOption
	///@param	pTragetCurrInstrumentOption	存放结果的CCurrInstrumentOption
	void retrieve(CCurrInstrumentOption *pCurrInstrumentOption, CWriteableCurrInstrumentOption *pTargetCurrInstrumentOption);
	
	///获取第一个CCurrInstrumentOption
	///@return	得到的第一个CCurrInstrumentOption，如果没有，则返回NULL
	CCurrInstrumentOption *getFirst(void);
	
	///获取下一个CCurrInstrumentOption
	///@return	得到下一个CCurrInstrumentOption，如果没有，则返回NULL
	CCurrInstrumentOption *getNext(void);
	
	///结束获取CCurrInstrumentOption
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CCurrInstrumentOptionActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CCurrInstrumentOptionActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CCurrInstrumentOptionCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CCurrInstrumentOptionCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CCurrInstrumentOptionIteratorBySettlementGroupID;

	///开始寻找CCurrInstrumentOption
	///@param	SettlementGroupID	结算组代码
	///@return	满足条件的地一个CCurrInstrumentOption，如果找不到，返回NULL
	CCurrInstrumentOption *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///寻找下一个符合条件的CCurrInstrumentOption，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrInstrumentOption，如果已经没有一个满足要求了，则返回NULL
	CCurrInstrumentOption *findNextBySettlementGroupID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySettlementGroupID(void);

	///寻找CCurrInstrumentOption
	///@param	InstrumentID	合约代码
	///@return	找到的CCurrInstrumentOption，如果找不到，返回NULL
	CCurrInstrumentOption *findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CCurrInstrumentOption加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pCurrInstrumentOption	要加入的CurrInstrumentOption
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CCurrInstrumentOption *internalAdd(CWriteableCurrInstrumentOption *pCurrInstrumentOption, bool bNoTransaction);
	
	
	///刷新该CCurrInstrumentOption的键值
	///@param	pCurrInstrumentOption	被刷新的CCurrInstrumentOption
	///@param	pNewCurrInstrumentOption	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CCurrInstrumentOption *pCurrInstrumentOption, CWriteableCurrInstrumentOption *pNewCurrInstrumentOption, bool updateIndex,bool bNoTransaction);
	
	///删除一个CCurrInstrumentOption，同时删除其索引
	///@param	pCurrInstrumentOption	要删除的CCurrInstrumentOption
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CCurrInstrumentOption *pCurrInstrumentOption, bool bNoTransaction);
/*
	///检查某个CCurrInstrumentOption是否属于本对象工厂
	///@param	pCurrInstrumentOption	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CCurrInstrumentOption *pCurrInstrumentOption);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于InstrumentID的索引
	CAVLTree *pInstrumentIDIndex;
	
	
	///按照SettlementGroupID检索时，存储的查询参数
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///按照SettlementGroupID检索时，存储最后一次找到的索引节点
	CCurrInstrumentOption *pLastFoundInSearchBySettlementGroupID;
	
	///加入前触发
	///@param	pCurrInstrumentOption	要加入的CurrInstrumentOption
	virtual void beforeAdd(CWriteableCurrInstrumentOption *pCurrInstrumentOption);
	
	///加入后触发
	///@param	pCurrInstrumentOption	已经加入的CurrInstrumentOption
	virtual void afterAdd(CCurrInstrumentOption *pCurrInstrumentOption);

	///更新前触发	
	///@param	pCurrInstrumentOption	被刷新的CCurrInstrumentOption
	///@param	pNewCurrInstrumentOption	新的值
	virtual void beforeUpdate(CCurrInstrumentOption *pCurrInstrumentOption, CWriteableCurrInstrumentOption *pNewCurrInstrumentOption);
	
	///更新后触发
	///@param	pCurrInstrumentOption	被刷新的CCurrInstrumentOption
	virtual void afterUpdate(CCurrInstrumentOption *pCurrInstrumentOption);
	
	///删除前触发
	///@param	pCurrInstrumentOption	要删除的CCurrInstrumentOption
	virtual void beforeRemove(CCurrInstrumentOption *pCurrInstrumentOption);
	
	///确认加入后触发
	///@param	pCurrInstrumentOption	已经加入的CurrInstrumentOption
	virtual void commitAdd(CCurrInstrumentOption *pCurrInstrumentOption);

	///确认更新后触发
	///@param	pCurrInstrumentOption	被刷新的CCurrInstrumentOption
	///@param	poldCurrInstrumentOption	原来的值
	virtual void commitUpdate(CCurrInstrumentOption *pCurrInstrumentOption, CWriteableCurrInstrumentOption *pOldCurrInstrumentOption);
	
	///确认删除后触发
	///@param	pCurrInstrumentOption	已经删除的CCurrInstrumentOption
	virtual void commitRemove(CWriteableCurrInstrumentOption *pCurrInstrumentOption);

	///所有相关的触发器
	vector<CCurrInstrumentOptionActionTrigger *> *pActionTriggers;
	vector<CCurrInstrumentOptionCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableCurrInstrumentOption compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

#endif
