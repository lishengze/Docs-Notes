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

class CSysInvalidateOrderFactory;
class CSysInvalidateOrderResource;
class CSysOrderStatusFactory;
class CSysOrderStatusResource;
class CSysBargainOrderFactory;
class CSysBargainOrderResource;
class CSysInstPropertyFactory;
class CSysInstPropertyResource;
class CSysMarginRateFactory;
class CSysMarginRateResource;
class CSysPriceLimitFactory;
class CSysPriceLimitResource;
class CSysPartPosiLimitFactory;
class CSysPartPosiLimitResource;
class CSysClientPosiLimitFactory;
class CSysClientPosiLimitResource;
class CSysSpecialPosiLimitFactory;
class CSysSpecialPosiLimitResource;
class CSysTransactionChgFactory;
class CSysTransactionChgResource;
class CSysClientChgFactory;
class CSysClientChgResource;
class CSysPartClientChgFactory;
class CSysPartClientChgResource;
class CSysPosiLimitChgFactory;
class CSysPosiLimitChgResource;
class CSysClientPosiLimitChgFactory;
class CSysClientPosiLimitChgResource;
class CSysSpecPosiLimitChgFactory;
class CSysSpecPosiLimitChgResource;
class CSysHedgeDetailChgFactory;
class CSysHedgeDetailChgResource;
class CSysParticipantChgFactory;
class CSysParticipantChgResource;
class CSysMarginRateChgFactory;
class CSysMarginRateChgResource;
class CSysUserIpChgFactory;
class CSysUserIpChgResource;
class CSysPartTradeFactory;
class CSysPartTradeResource;
class CSysMdbObjectAttrFactory;
class CSysMdbObjectAttrResource;
class CSysMdbSyslogInfoFactory;
class CSysMdbSyslogInfoResource;
class CSysUserInfoFactory;
class CSysUserInfoResource;
class CSysOnlineUserInfoFactory;
class CSysOnlineUserInfoResource;
class CSysWarningEventFactory;
class CSysWarningEventResource;
class CSysWarningQueryFactory;
class CSysWarningQueryResource;
class CSyslogEventFactory;
class CSyslogEventResource;
class CSysEventDescripFactory;
class CSysEventDescripResource;
class CRspQryHostEnvCommonFactory;
class CRspQryHostEnvCommonResource;
class CRspQryHostEnvLanFactory;
class CRspQryHostEnvLanResource;
class CRspQryHostEnvStorageFactory;
class CRspQryHostEnvStorageResource;
class CRspQryHostEnvIOFactory;
class CRspQryHostEnvIOResource;
class CRspQryHostEnvFSFactory;
class CRspQryHostEnvFSResource;
class CRspQryHostEnvSwapFactory;
class CRspQryHostEnvSwapResource;
class CRspQryHostEnvLanCfgFactory;
class CRspQryHostEnvLanCfgResource;
class CSysMdbTopCpuInfoFactory;
class CSysMdbTopCpuInfoResource;
class CSysMdbTopMemInfoFactory;
class CSysMdbTopMemInfoResource;
class CSysMdbTopProcessInfoFactory;
class CSysMdbTopProcessInfoResource;
class CSysMdbFileSystemInfoFactory;
class CSysMdbFileSystemInfoResource;
class CSysMdbNetworkInfoFactory;
class CSysMdbNetworkInfoResource;
class CSysParticipantInitFactory;
class CSysParticipantInitResource;
class CSysUserInitFactory;
class CSysUserInitResource;
class CSysClientInitFactory;
class CSysClientInitResource;
class CSysTradeUserLoginInfoFactory;
class CSysTradeUserLoginInfoResource;
class CSysMdbWebAppInfoFactory;
class CSysMdbWebAppInfoResource;
class CSysMdbMemPoolInfoFactory;
class CSysMdbMemPoolInfoResource;
class CSysMdbConnectorInfoFactory;
class CSysMdbConnectorInfoResource;
class CSysMdbDBQueryFactory;
class CSysMdbDBQueryResource;
class CSysNetAreaFactory;
class CSysNetAreaResource;
class CSysNetSubAreaFactory;
class CSysNetSubAreaResource;
class CSysNetSubAreaIPFactory;
class CSysNetSubAreaIPResource;
class CSysNetFuncAreaFactory;
class CSysNetFuncAreaResource;
class CSysNetDeviceFactory;
class CSysNetDeviceResource;
class CSysNetDeviceLinkedFactory;
class CSysNetDeviceLinkedResource;
class CSysNetOIDFactory;
class CSysNetOIDResource;
class CSysNetDeviceTypeFactory;
class CSysNetDeviceTypeResource;
class CSysNetTimePolicyFactory;
class CSysNetTimePolicyResource;
class CSysNetGatherTaskFactory;
class CSysNetGatherTaskResource;
class CSysNetDeviceCategoryFactory;
class CSysNetDeviceCategoryResource;
class CSysNetManufactoryFactory;
class CSysNetManufactoryResource;
class CSysNetCommunityFactory;
class CSysNetCommunityResource;
class CSysNetPortTypeFactory;
class CSysNetPortTypeResource;
class CSysNetInterfaceFactory;
class CSysNetInterfaceResource;
class CSysNetGeneralOIDFactory;
class CSysNetGeneralOIDResource;
class CSysNetMonitorTypeFactory;
class CSysNetMonitorTypeResource;
class CSysNetMonitorAttrScopeFactory;
class CSysNetMonitorAttrScopeResource;
class CSysNetMonitorAttrTypeFactory;
class CSysNetMonitorAttrTypeResource;
class CSysNetMonitorCommandTypeFactory;
class CSysNetMonitorCommandTypeResource;
class CSysNetMonitorActionGroupFactory;
class CSysNetMonitorActionGroupResource;
class CSysNetMonitorDeviceGroupFactory;
class CSysNetMonitorDeviceGroupResource;
class CSysNetMonitorTaskInfoFactory;
class CSysNetMonitorTaskInfoResource;
class CSysNetMonitorTaskObjectSetFactory;
class CSysNetMonitorTaskObjectSetResource;
class CSysNetMonitorTaskResultFactory;
class CSysNetMonitorTaskResultResource;
class CSysNetPartyLinkInfoFactory;
class CSysNetPartyLinkInfoResource;
class CSysNetDelPartyLinkInfoFactory;
class CSysNetDelPartyLinkInfoResource;
class CSysNetPartyLinkAddrChangeFactory;
class CSysNetPartyLinkAddrChangeResource;
class CSysNetMonitorActionAttrFactory;
class CSysNetMonitorActionAttrResource;
class CSysNetModuleFactory;
class CSysNetModuleResource;
class CSysNetEventExprFactory;
class CSysNetEventExprResource;
class CSysNetEventTypeFactory;
class CSysNetEventTypeResource;
class CSysNetSubEventTypeFactory;
class CSysNetSubEventTypeResource;
class CSysNetEventLevelFactory;
class CSysNetEventLevelResource;
class CSysNetMonitorDeviceTaskFactory;
class CSysNetMonitorDeviceTaskResource;
class CSysNetMonitorTaskInstAttrsFactory;
class CSysNetMonitorTaskInstAttrsResource;
class CSysNetBaseLineFactory;
class CSysNetBaseLineResource;
class CSysNetBaseLineTaskFactory;
class CSysNetBaseLineTaskResource;
class CSysMdbNetPartyLinkStatusInfoFactory;
class CSysMdbNetPartyLinkStatusInfoResource;
class CSysNetMemberSDHLineInfoFactory;
class CSysNetMemberSDHLineInfoResource;
class CSysNetDDNLinkInfoFactory;
class CSysNetDDNLinkInfoResource;
class CSysNetPseudMemberLinkInfoFactory;
class CSysNetPseudMemberLinkInfoResource;
class CSysNetOuterDeviceInfoFactory;
class CSysNetOuterDeviceInfoResource;
class CSysLocalPingResultInfoFactory;
class CSysLocalPingResultInfoResource;
class CSysRomotePingResultInfoFactory;
class CSysRomotePingResultInfoResource;
class CSysParticTradeOrderStatesFactory;
class CSysParticTradeOrderStatesResource;
class CSysMdbRouterInfoFactory;
class CSysMdbRouterInfoResource;
class CSysMdbDiskIOFactory;
class CSysMdbDiskIOResource;
class CSysMdbStatInfoFactory;
class CSysMdbStatInfoResource;
class CSysMdbTradeFrontOrderRttStatFactory;
class CSysMdbTradeFrontOrderRttStatResource;
class CSysInstrumentStatusFactory;
class CSysInstrumentStatusResource;
class CSysCurrTradingSegmentAttrFactory;
class CSysCurrTradingSegmentAttrResource;
class CSysMemberLinkCostFactory;
class CSysMemberLinkCostResource;
class CSysNetPartylinkMonthlyRentFactory;
class CSysNetPartylinkMonthlyRentResource;
class CSysNetNonPartyLinkInfoFactory;
class CSysNetNonPartyLinkInfoResource;

/////////////////////////////////////////////////////////////////////////
///CSysInvalidateOrderFactory是一个无效报单的对象工厂。它包含了一批无效报单，
///同时又建立了如下索引，以方便查询：
///	SysInsertTimeIndex
///使用本对象工厂，可以完成对无效报单的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByActionTime，findNextByActionTime和endFindByActionTime完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInvalidateOrderFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysInvalidateOrderFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysInvalidateOrder，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysInvalidateOrderFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysInvalidateOrderFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysInvalidateOrder
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysInvalidateOrder，文件名将根据配置文件中的定义SysInvalidateOrderCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysInvalidateOrder
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysInvalidateOrder，文件名将根据配置文件中的定义SysInvalidateOrderCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysInvalidateOrderResource;

	///将一个CSysInvalidateOrder加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysInvalidateOrder	要加入的SysInvalidateOrder
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysInvalidateOrder *add(CWriteableSysInvalidateOrder *pSysInvalidateOrder, CTransaction *pTransaction=NULL);
	
	///刷新该CSysInvalidateOrder的值
	///@param	pSysInvalidateOrder	被刷新的CSysInvalidateOrder
	///@param	pNewSysInvalidateOrder	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysInvalidateOrder *pSysInvalidateOrder, CWriteableSysInvalidateOrder *pNewSysInvalidateOrder, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysInvalidateOrder	  需要被刷新或者新增的CSysInvalidateOrder,等于NULL表示是需要新增的
	///@param	pNewSysInvalidateOrder	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysInvalidateOrder* addOrUpdate(CSysInvalidateOrder *pSysInvalidateOrder, CWriteableSysInvalidateOrder *pNewSysInvalidateOrder, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysInvalidateOrder，同时删除其索引
	///@param	pSysInvalidateOrder	要删除的CSysInvalidateOrder
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysInvalidateOrder *pSysInvalidateOrder, CTransaction *pTransaction=NULL);
	
	///获取某个CSysInvalidateOrder
	///@param	pSysInvalidateOrder	要读取的CSysInvalidateOrder
	///@param	pTragetSysInvalidateOrder	存放结果的CSysInvalidateOrder
	void retrieve(CSysInvalidateOrder *pSysInvalidateOrder, CWriteableSysInvalidateOrder *pTargetSysInvalidateOrder);
	
	///获取第一个CSysInvalidateOrder
	///@return	得到的第一个CSysInvalidateOrder，如果没有，则返回NULL
	CSysInvalidateOrder *getFirst(void);
	
	///获取下一个CSysInvalidateOrder
	///@return	得到下一个CSysInvalidateOrder，如果没有，则返回NULL
	CSysInvalidateOrder *getNext(void);
	
	///结束获取CSysInvalidateOrder
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysInvalidateOrderActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysInvalidateOrderActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysInvalidateOrderCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysInvalidateOrderCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysInvalidateOrderIteratorByActionTime;

	///开始寻找CSysInvalidateOrder
	///@param	ActionTime	
	///@return	满足条件的地一个CSysInvalidateOrder，如果找不到，返回NULL
	CSysInvalidateOrder *startFindByActionTime( const CReadOnlyTimeType& ActionTime);

	///寻找下一个符合条件的CSysInvalidateOrder，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysInvalidateOrder，如果已经没有一个满足要求了，则返回NULL
	CSysInvalidateOrder *findNextByActionTime(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByActionTime(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysInvalidateOrder加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysInvalidateOrder	要加入的SysInvalidateOrder
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysInvalidateOrder *internalAdd(CWriteableSysInvalidateOrder *pSysInvalidateOrder, bool bNoTransaction);
	
	
	///刷新该CSysInvalidateOrder的键值
	///@param	pSysInvalidateOrder	被刷新的CSysInvalidateOrder
	///@param	pNewSysInvalidateOrder	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysInvalidateOrder *pSysInvalidateOrder, CWriteableSysInvalidateOrder *pNewSysInvalidateOrder, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysInvalidateOrder，同时删除其索引
	///@param	pSysInvalidateOrder	要删除的CSysInvalidateOrder
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysInvalidateOrder *pSysInvalidateOrder, bool bNoTransaction);
/*
	///检查某个CSysInvalidateOrder是否属于本对象工厂
	///@param	pSysInvalidateOrder	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysInvalidateOrder *pSysInvalidateOrder);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ActionTime的索引
	CAVLTree *pSysInsertTimeIndex;
	
	
	///按照ActionTime检索时，存储的查询参数
	CTimeType queryActionTimeInSearchByActionTime;
	
	///按照ActionTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByActionTime;
	
	///加入前触发
	///@param	pSysInvalidateOrder	要加入的SysInvalidateOrder
	virtual void beforeAdd(CWriteableSysInvalidateOrder *pSysInvalidateOrder);
	
	///加入后触发
	///@param	pSysInvalidateOrder	已经加入的SysInvalidateOrder
	virtual void afterAdd(CSysInvalidateOrder *pSysInvalidateOrder);

	///更新前触发	
	///@param	pSysInvalidateOrder	被刷新的CSysInvalidateOrder
	///@param	pNewSysInvalidateOrder	新的值
	virtual void beforeUpdate(CSysInvalidateOrder *pSysInvalidateOrder, CWriteableSysInvalidateOrder *pNewSysInvalidateOrder);
	
	///更新后触发
	///@param	pSysInvalidateOrder	被刷新的CSysInvalidateOrder
	virtual void afterUpdate(CSysInvalidateOrder *pSysInvalidateOrder);
	
	///删除前触发
	///@param	pSysInvalidateOrder	要删除的CSysInvalidateOrder
	virtual void beforeRemove(CSysInvalidateOrder *pSysInvalidateOrder);
	
	///确认加入后触发
	///@param	pSysInvalidateOrder	已经加入的SysInvalidateOrder
	virtual void commitAdd(CSysInvalidateOrder *pSysInvalidateOrder);

	///确认更新后触发
	///@param	pSysInvalidateOrder	被刷新的CSysInvalidateOrder
	///@param	poldSysInvalidateOrder	原来的值
	virtual void commitUpdate(CSysInvalidateOrder *pSysInvalidateOrder, CWriteableSysInvalidateOrder *pOldSysInvalidateOrder);
	
	///确认删除后触发
	///@param	pSysInvalidateOrder	已经删除的CSysInvalidateOrder
	virtual void commitRemove(CWriteableSysInvalidateOrder *pSysInvalidateOrder);

	///所有相关的触发器
	vector<CSysInvalidateOrderActionTrigger *> *pActionTriggers;
	vector<CSysInvalidateOrderCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysInvalidateOrder compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysOrderStatusFactory是一个报单状态的对象工厂。它包含了一批报单状态，
///同时又建立了如下索引，以方便查询：
///	SysActionTimeIndex
///使用本对象工厂，可以完成对报单状态的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByActionTime，findNextByActionTime和endFindByActionTime完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOrderStatusFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysOrderStatusFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysOrderStatus，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysOrderStatusFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysOrderStatusFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysOrderStatus
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysOrderStatus，文件名将根据配置文件中的定义SysOrderStatusCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysOrderStatus
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysOrderStatus，文件名将根据配置文件中的定义SysOrderStatusCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysOrderStatusResource;

	///将一个CSysOrderStatus加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysOrderStatus	要加入的SysOrderStatus
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysOrderStatus *add(CWriteableSysOrderStatus *pSysOrderStatus, CTransaction *pTransaction=NULL);
	
	///刷新该CSysOrderStatus的值
	///@param	pSysOrderStatus	被刷新的CSysOrderStatus
	///@param	pNewSysOrderStatus	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysOrderStatus *pSysOrderStatus, CWriteableSysOrderStatus *pNewSysOrderStatus, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysOrderStatus	  需要被刷新或者新增的CSysOrderStatus,等于NULL表示是需要新增的
	///@param	pNewSysOrderStatus	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysOrderStatus* addOrUpdate(CSysOrderStatus *pSysOrderStatus, CWriteableSysOrderStatus *pNewSysOrderStatus, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysOrderStatus，同时删除其索引
	///@param	pSysOrderStatus	要删除的CSysOrderStatus
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysOrderStatus *pSysOrderStatus, CTransaction *pTransaction=NULL);
	
	///获取某个CSysOrderStatus
	///@param	pSysOrderStatus	要读取的CSysOrderStatus
	///@param	pTragetSysOrderStatus	存放结果的CSysOrderStatus
	void retrieve(CSysOrderStatus *pSysOrderStatus, CWriteableSysOrderStatus *pTargetSysOrderStatus);
	
	///获取第一个CSysOrderStatus
	///@return	得到的第一个CSysOrderStatus，如果没有，则返回NULL
	CSysOrderStatus *getFirst(void);
	
	///获取下一个CSysOrderStatus
	///@return	得到下一个CSysOrderStatus，如果没有，则返回NULL
	CSysOrderStatus *getNext(void);
	
	///结束获取CSysOrderStatus
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysOrderStatusActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysOrderStatusActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysOrderStatusCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysOrderStatusCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysOrderStatusIteratorByActionTime;

	///开始寻找CSysOrderStatus
	///@param	ActionTime	
	///@return	满足条件的地一个CSysOrderStatus，如果找不到，返回NULL
	CSysOrderStatus *startFindByActionTime( const CReadOnlyTimeType& ActionTime);

	///寻找下一个符合条件的CSysOrderStatus，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysOrderStatus，如果已经没有一个满足要求了，则返回NULL
	CSysOrderStatus *findNextByActionTime(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByActionTime(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysOrderStatus加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysOrderStatus	要加入的SysOrderStatus
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysOrderStatus *internalAdd(CWriteableSysOrderStatus *pSysOrderStatus, bool bNoTransaction);
	
	
	///刷新该CSysOrderStatus的键值
	///@param	pSysOrderStatus	被刷新的CSysOrderStatus
	///@param	pNewSysOrderStatus	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysOrderStatus *pSysOrderStatus, CWriteableSysOrderStatus *pNewSysOrderStatus, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysOrderStatus，同时删除其索引
	///@param	pSysOrderStatus	要删除的CSysOrderStatus
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysOrderStatus *pSysOrderStatus, bool bNoTransaction);
/*
	///检查某个CSysOrderStatus是否属于本对象工厂
	///@param	pSysOrderStatus	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysOrderStatus *pSysOrderStatus);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ActionTime的索引
	CAVLTree *pSysActionTimeIndex;
	
	
	///按照ActionTime检索时，存储的查询参数
	CTimeType queryActionTimeInSearchByActionTime;
	
	///按照ActionTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByActionTime;
	
	///加入前触发
	///@param	pSysOrderStatus	要加入的SysOrderStatus
	virtual void beforeAdd(CWriteableSysOrderStatus *pSysOrderStatus);
	
	///加入后触发
	///@param	pSysOrderStatus	已经加入的SysOrderStatus
	virtual void afterAdd(CSysOrderStatus *pSysOrderStatus);

	///更新前触发	
	///@param	pSysOrderStatus	被刷新的CSysOrderStatus
	///@param	pNewSysOrderStatus	新的值
	virtual void beforeUpdate(CSysOrderStatus *pSysOrderStatus, CWriteableSysOrderStatus *pNewSysOrderStatus);
	
	///更新后触发
	///@param	pSysOrderStatus	被刷新的CSysOrderStatus
	virtual void afterUpdate(CSysOrderStatus *pSysOrderStatus);
	
	///删除前触发
	///@param	pSysOrderStatus	要删除的CSysOrderStatus
	virtual void beforeRemove(CSysOrderStatus *pSysOrderStatus);
	
	///确认加入后触发
	///@param	pSysOrderStatus	已经加入的SysOrderStatus
	virtual void commitAdd(CSysOrderStatus *pSysOrderStatus);

	///确认更新后触发
	///@param	pSysOrderStatus	被刷新的CSysOrderStatus
	///@param	poldSysOrderStatus	原来的值
	virtual void commitUpdate(CSysOrderStatus *pSysOrderStatus, CWriteableSysOrderStatus *pOldSysOrderStatus);
	
	///确认删除后触发
	///@param	pSysOrderStatus	已经删除的CSysOrderStatus
	virtual void commitRemove(CWriteableSysOrderStatus *pSysOrderStatus);

	///所有相关的触发器
	vector<CSysOrderStatusActionTrigger *> *pActionTriggers;
	vector<CSysOrderStatusCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysOrderStatus compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysBargainOrderFactory是一个报单成交的对象工厂。它包含了一批报单成交，
///同时又建立了如下索引，以方便查询：
///	SysTradeTimeIndex
///使用本对象工厂，可以完成对报单成交的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByActionTime，findNextByActionTime和endFindByActionTime完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysBargainOrderFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysBargainOrderFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysBargainOrder，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysBargainOrderFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysBargainOrderFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysBargainOrder
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysBargainOrder，文件名将根据配置文件中的定义SysBargainOrderCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysBargainOrder
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysBargainOrder，文件名将根据配置文件中的定义SysBargainOrderCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysBargainOrderResource;

	///将一个CSysBargainOrder加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysBargainOrder	要加入的SysBargainOrder
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysBargainOrder *add(CWriteableSysBargainOrder *pSysBargainOrder, CTransaction *pTransaction=NULL);
	
	///刷新该CSysBargainOrder的值
	///@param	pSysBargainOrder	被刷新的CSysBargainOrder
	///@param	pNewSysBargainOrder	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysBargainOrder *pSysBargainOrder, CWriteableSysBargainOrder *pNewSysBargainOrder, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysBargainOrder	  需要被刷新或者新增的CSysBargainOrder,等于NULL表示是需要新增的
	///@param	pNewSysBargainOrder	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysBargainOrder* addOrUpdate(CSysBargainOrder *pSysBargainOrder, CWriteableSysBargainOrder *pNewSysBargainOrder, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysBargainOrder，同时删除其索引
	///@param	pSysBargainOrder	要删除的CSysBargainOrder
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysBargainOrder *pSysBargainOrder, CTransaction *pTransaction=NULL);
	
	///获取某个CSysBargainOrder
	///@param	pSysBargainOrder	要读取的CSysBargainOrder
	///@param	pTragetSysBargainOrder	存放结果的CSysBargainOrder
	void retrieve(CSysBargainOrder *pSysBargainOrder, CWriteableSysBargainOrder *pTargetSysBargainOrder);
	
	///获取第一个CSysBargainOrder
	///@return	得到的第一个CSysBargainOrder，如果没有，则返回NULL
	CSysBargainOrder *getFirst(void);
	
	///获取下一个CSysBargainOrder
	///@return	得到下一个CSysBargainOrder，如果没有，则返回NULL
	CSysBargainOrder *getNext(void);
	
	///结束获取CSysBargainOrder
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysBargainOrderActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysBargainOrderActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysBargainOrderCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysBargainOrderCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysBargainOrderIteratorByActionTime;

	///开始寻找CSysBargainOrder
	///@param	ActionTime	
	///@return	满足条件的地一个CSysBargainOrder，如果找不到，返回NULL
	CSysBargainOrder *startFindByActionTime( const CReadOnlyTimeType& ActionTime);

	///寻找下一个符合条件的CSysBargainOrder，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysBargainOrder，如果已经没有一个满足要求了，则返回NULL
	CSysBargainOrder *findNextByActionTime(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByActionTime(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysBargainOrder加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysBargainOrder	要加入的SysBargainOrder
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysBargainOrder *internalAdd(CWriteableSysBargainOrder *pSysBargainOrder, bool bNoTransaction);
	
	
	///刷新该CSysBargainOrder的键值
	///@param	pSysBargainOrder	被刷新的CSysBargainOrder
	///@param	pNewSysBargainOrder	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysBargainOrder *pSysBargainOrder, CWriteableSysBargainOrder *pNewSysBargainOrder, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysBargainOrder，同时删除其索引
	///@param	pSysBargainOrder	要删除的CSysBargainOrder
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysBargainOrder *pSysBargainOrder, bool bNoTransaction);
/*
	///检查某个CSysBargainOrder是否属于本对象工厂
	///@param	pSysBargainOrder	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysBargainOrder *pSysBargainOrder);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ActionTime的索引
	CAVLTree *pSysTradeTimeIndex;
	
	
	///按照ActionTime检索时，存储的查询参数
	CTimeType queryActionTimeInSearchByActionTime;
	
	///按照ActionTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByActionTime;
	
	///加入前触发
	///@param	pSysBargainOrder	要加入的SysBargainOrder
	virtual void beforeAdd(CWriteableSysBargainOrder *pSysBargainOrder);
	
	///加入后触发
	///@param	pSysBargainOrder	已经加入的SysBargainOrder
	virtual void afterAdd(CSysBargainOrder *pSysBargainOrder);

	///更新前触发	
	///@param	pSysBargainOrder	被刷新的CSysBargainOrder
	///@param	pNewSysBargainOrder	新的值
	virtual void beforeUpdate(CSysBargainOrder *pSysBargainOrder, CWriteableSysBargainOrder *pNewSysBargainOrder);
	
	///更新后触发
	///@param	pSysBargainOrder	被刷新的CSysBargainOrder
	virtual void afterUpdate(CSysBargainOrder *pSysBargainOrder);
	
	///删除前触发
	///@param	pSysBargainOrder	要删除的CSysBargainOrder
	virtual void beforeRemove(CSysBargainOrder *pSysBargainOrder);
	
	///确认加入后触发
	///@param	pSysBargainOrder	已经加入的SysBargainOrder
	virtual void commitAdd(CSysBargainOrder *pSysBargainOrder);

	///确认更新后触发
	///@param	pSysBargainOrder	被刷新的CSysBargainOrder
	///@param	poldSysBargainOrder	原来的值
	virtual void commitUpdate(CSysBargainOrder *pSysBargainOrder, CWriteableSysBargainOrder *pOldSysBargainOrder);
	
	///确认删除后触发
	///@param	pSysBargainOrder	已经删除的CSysBargainOrder
	virtual void commitRemove(CWriteableSysBargainOrder *pSysBargainOrder);

	///所有相关的触发器
	vector<CSysBargainOrderActionTrigger *> *pActionTriggers;
	vector<CSysBargainOrderCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysBargainOrder compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysInstPropertyFactory是一个合约基本属性的对象工厂。它包含了一批合约基本属性，
///同时又建立了如下索引，以方便查询：
///	SysInstrumentIDIndex
///使用本对象工厂，可以完成对合约基本属性的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstPropertyFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysInstPropertyFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysInstProperty，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysInstPropertyFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysInstPropertyFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysInstProperty
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysInstProperty，文件名将根据配置文件中的定义SysInstPropertyCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysInstProperty
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysInstProperty，文件名将根据配置文件中的定义SysInstPropertyCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysInstPropertyResource;

	///将一个CSysInstProperty加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysInstProperty	要加入的SysInstProperty
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysInstProperty *add(CWriteableSysInstProperty *pSysInstProperty, CTransaction *pTransaction=NULL);
	
	///刷新该CSysInstProperty的值
	///@param	pSysInstProperty	被刷新的CSysInstProperty
	///@param	pNewSysInstProperty	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysInstProperty *pSysInstProperty, CWriteableSysInstProperty *pNewSysInstProperty, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysInstProperty	  需要被刷新或者新增的CSysInstProperty,等于NULL表示是需要新增的
	///@param	pNewSysInstProperty	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysInstProperty* addOrUpdate(CSysInstProperty *pSysInstProperty, CWriteableSysInstProperty *pNewSysInstProperty, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysInstProperty，同时删除其索引
	///@param	pSysInstProperty	要删除的CSysInstProperty
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysInstProperty *pSysInstProperty, CTransaction *pTransaction=NULL);
	
	///获取某个CSysInstProperty
	///@param	pSysInstProperty	要读取的CSysInstProperty
	///@param	pTragetSysInstProperty	存放结果的CSysInstProperty
	void retrieve(CSysInstProperty *pSysInstProperty, CWriteableSysInstProperty *pTargetSysInstProperty);
	
	///获取第一个CSysInstProperty
	///@return	得到的第一个CSysInstProperty，如果没有，则返回NULL
	CSysInstProperty *getFirst(void);
	
	///获取下一个CSysInstProperty
	///@return	得到下一个CSysInstProperty，如果没有，则返回NULL
	CSysInstProperty *getNext(void);
	
	///结束获取CSysInstProperty
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysInstPropertyActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysInstPropertyActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysInstPropertyCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysInstPropertyCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysInstPropertyIteratorByAll;

	///开始寻找CSysInstProperty
	///@return	满足条件的地一个CSysInstProperty，如果找不到，返回NULL
	CSysInstProperty *startFindByAll();

	///寻找下一个符合条件的CSysInstProperty，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysInstProperty，如果已经没有一个满足要求了，则返回NULL
	CSysInstProperty *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysInstProperty
	///@param	InstrumentID	
	///@return	找到的CSysInstProperty，如果找不到，返回NULL
	CSysInstProperty *findByOne( const CReadOnlyInstrumentIDType&  InstrumentID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysInstProperty加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysInstProperty	要加入的SysInstProperty
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysInstProperty *internalAdd(CWriteableSysInstProperty *pSysInstProperty, bool bNoTransaction);
	
	
	///刷新该CSysInstProperty的键值
	///@param	pSysInstProperty	被刷新的CSysInstProperty
	///@param	pNewSysInstProperty	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysInstProperty *pSysInstProperty, CWriteableSysInstProperty *pNewSysInstProperty, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysInstProperty，同时删除其索引
	///@param	pSysInstProperty	要删除的CSysInstProperty
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysInstProperty *pSysInstProperty, bool bNoTransaction);
/*
	///检查某个CSysInstProperty是否属于本对象工厂
	///@param	pSysInstProperty	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysInstProperty *pSysInstProperty);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于InstrumentID的索引
	CAVLTree *pSysInstrumentIDIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysInstProperty	要加入的SysInstProperty
	virtual void beforeAdd(CWriteableSysInstProperty *pSysInstProperty);
	
	///加入后触发
	///@param	pSysInstProperty	已经加入的SysInstProperty
	virtual void afterAdd(CSysInstProperty *pSysInstProperty);

	///更新前触发	
	///@param	pSysInstProperty	被刷新的CSysInstProperty
	///@param	pNewSysInstProperty	新的值
	virtual void beforeUpdate(CSysInstProperty *pSysInstProperty, CWriteableSysInstProperty *pNewSysInstProperty);
	
	///更新后触发
	///@param	pSysInstProperty	被刷新的CSysInstProperty
	virtual void afterUpdate(CSysInstProperty *pSysInstProperty);
	
	///删除前触发
	///@param	pSysInstProperty	要删除的CSysInstProperty
	virtual void beforeRemove(CSysInstProperty *pSysInstProperty);
	
	///确认加入后触发
	///@param	pSysInstProperty	已经加入的SysInstProperty
	virtual void commitAdd(CSysInstProperty *pSysInstProperty);

	///确认更新后触发
	///@param	pSysInstProperty	被刷新的CSysInstProperty
	///@param	poldSysInstProperty	原来的值
	virtual void commitUpdate(CSysInstProperty *pSysInstProperty, CWriteableSysInstProperty *pOldSysInstProperty);
	
	///确认删除后触发
	///@param	pSysInstProperty	已经删除的CSysInstProperty
	virtual void commitRemove(CWriteableSysInstProperty *pSysInstProperty);

	///所有相关的触发器
	vector<CSysInstPropertyActionTrigger *> *pActionTriggers;
	vector<CSysInstPropertyCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysInstProperty compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateFactory是一个合约保证金率的对象工厂。它包含了一批合约保证金率，
///同时又建立了如下索引，以方便查询：
///	SysInstrumentIDIndex
///使用本对象工厂，可以完成对合约保证金率的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMarginRateFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysMarginRate，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMarginRateFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysMarginRateFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysMarginRate
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysMarginRate，文件名将根据配置文件中的定义SysMarginRateCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysMarginRate
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysMarginRate，文件名将根据配置文件中的定义SysMarginRateCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysMarginRateResource;

	///将一个CSysMarginRate加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMarginRate	要加入的SysMarginRate
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMarginRate *add(CWriteableSysMarginRate *pSysMarginRate, CTransaction *pTransaction=NULL);
	
	///刷新该CSysMarginRate的值
	///@param	pSysMarginRate	被刷新的CSysMarginRate
	///@param	pNewSysMarginRate	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysMarginRate *pSysMarginRate, CWriteableSysMarginRate *pNewSysMarginRate, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysMarginRate	  需要被刷新或者新增的CSysMarginRate,等于NULL表示是需要新增的
	///@param	pNewSysMarginRate	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysMarginRate* addOrUpdate(CSysMarginRate *pSysMarginRate, CWriteableSysMarginRate *pNewSysMarginRate, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysMarginRate，同时删除其索引
	///@param	pSysMarginRate	要删除的CSysMarginRate
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysMarginRate *pSysMarginRate, CTransaction *pTransaction=NULL);
	
	///获取某个CSysMarginRate
	///@param	pSysMarginRate	要读取的CSysMarginRate
	///@param	pTragetSysMarginRate	存放结果的CSysMarginRate
	void retrieve(CSysMarginRate *pSysMarginRate, CWriteableSysMarginRate *pTargetSysMarginRate);
	
	///获取第一个CSysMarginRate
	///@return	得到的第一个CSysMarginRate，如果没有，则返回NULL
	CSysMarginRate *getFirst(void);
	
	///获取下一个CSysMarginRate
	///@return	得到下一个CSysMarginRate，如果没有，则返回NULL
	CSysMarginRate *getNext(void);
	
	///结束获取CSysMarginRate
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysMarginRateActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysMarginRateActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysMarginRateCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysMarginRateCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysMarginRateIteratorByAll;

	///开始寻找CSysMarginRate
	///@return	满足条件的地一个CSysMarginRate，如果找不到，返回NULL
	CSysMarginRate *startFindByAll();

	///寻找下一个符合条件的CSysMarginRate，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysMarginRate，如果已经没有一个满足要求了，则返回NULL
	CSysMarginRate *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysMarginRate
	///@param	InstrumentID	
	///@param	ParticipantID	
	///@param	TradingRole	
	///@return	找到的CSysMarginRate，如果找不到，返回NULL
	CSysMarginRate *findByOne( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyTradingRoleType&  TradingRole);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysMarginRate加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMarginRate	要加入的SysMarginRate
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMarginRate *internalAdd(CWriteableSysMarginRate *pSysMarginRate, bool bNoTransaction);
	
	
	///刷新该CSysMarginRate的键值
	///@param	pSysMarginRate	被刷新的CSysMarginRate
	///@param	pNewSysMarginRate	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysMarginRate *pSysMarginRate, CWriteableSysMarginRate *pNewSysMarginRate, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysMarginRate，同时删除其索引
	///@param	pSysMarginRate	要删除的CSysMarginRate
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysMarginRate *pSysMarginRate, bool bNoTransaction);
/*
	///检查某个CSysMarginRate是否属于本对象工厂
	///@param	pSysMarginRate	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysMarginRate *pSysMarginRate);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于InstrumentID+ParticipantID+TradingRole的索引
	CAVLTree *pSysInstrumentIDIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysMarginRate	要加入的SysMarginRate
	virtual void beforeAdd(CWriteableSysMarginRate *pSysMarginRate);
	
	///加入后触发
	///@param	pSysMarginRate	已经加入的SysMarginRate
	virtual void afterAdd(CSysMarginRate *pSysMarginRate);

	///更新前触发	
	///@param	pSysMarginRate	被刷新的CSysMarginRate
	///@param	pNewSysMarginRate	新的值
	virtual void beforeUpdate(CSysMarginRate *pSysMarginRate, CWriteableSysMarginRate *pNewSysMarginRate);
	
	///更新后触发
	///@param	pSysMarginRate	被刷新的CSysMarginRate
	virtual void afterUpdate(CSysMarginRate *pSysMarginRate);
	
	///删除前触发
	///@param	pSysMarginRate	要删除的CSysMarginRate
	virtual void beforeRemove(CSysMarginRate *pSysMarginRate);
	
	///确认加入后触发
	///@param	pSysMarginRate	已经加入的SysMarginRate
	virtual void commitAdd(CSysMarginRate *pSysMarginRate);

	///确认更新后触发
	///@param	pSysMarginRate	被刷新的CSysMarginRate
	///@param	poldSysMarginRate	原来的值
	virtual void commitUpdate(CSysMarginRate *pSysMarginRate, CWriteableSysMarginRate *pOldSysMarginRate);
	
	///确认删除后触发
	///@param	pSysMarginRate	已经删除的CSysMarginRate
	virtual void commitRemove(CWriteableSysMarginRate *pSysMarginRate);

	///所有相关的触发器
	vector<CSysMarginRateActionTrigger *> *pActionTriggers;
	vector<CSysMarginRateCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysMarginRate compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysPriceLimitFactory是一个合约涨跌停板的对象工厂。它包含了一批合约涨跌停板，
///同时又建立了如下索引，以方便查询：
///	SysInstrumentIDIndex
///使用本对象工厂，可以完成对合约涨跌停板的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPriceLimitFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysPriceLimitFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysPriceLimit，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysPriceLimitFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysPriceLimitFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysPriceLimit
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysPriceLimit，文件名将根据配置文件中的定义SysPriceLimitCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysPriceLimit
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysPriceLimit，文件名将根据配置文件中的定义SysPriceLimitCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysPriceLimitResource;

	///将一个CSysPriceLimit加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysPriceLimit	要加入的SysPriceLimit
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysPriceLimit *add(CWriteableSysPriceLimit *pSysPriceLimit, CTransaction *pTransaction=NULL);
	
	///刷新该CSysPriceLimit的值
	///@param	pSysPriceLimit	被刷新的CSysPriceLimit
	///@param	pNewSysPriceLimit	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysPriceLimit *pSysPriceLimit, CWriteableSysPriceLimit *pNewSysPriceLimit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysPriceLimit	  需要被刷新或者新增的CSysPriceLimit,等于NULL表示是需要新增的
	///@param	pNewSysPriceLimit	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysPriceLimit* addOrUpdate(CSysPriceLimit *pSysPriceLimit, CWriteableSysPriceLimit *pNewSysPriceLimit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysPriceLimit，同时删除其索引
	///@param	pSysPriceLimit	要删除的CSysPriceLimit
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysPriceLimit *pSysPriceLimit, CTransaction *pTransaction=NULL);
	
	///获取某个CSysPriceLimit
	///@param	pSysPriceLimit	要读取的CSysPriceLimit
	///@param	pTragetSysPriceLimit	存放结果的CSysPriceLimit
	void retrieve(CSysPriceLimit *pSysPriceLimit, CWriteableSysPriceLimit *pTargetSysPriceLimit);
	
	///获取第一个CSysPriceLimit
	///@return	得到的第一个CSysPriceLimit，如果没有，则返回NULL
	CSysPriceLimit *getFirst(void);
	
	///获取下一个CSysPriceLimit
	///@return	得到下一个CSysPriceLimit，如果没有，则返回NULL
	CSysPriceLimit *getNext(void);
	
	///结束获取CSysPriceLimit
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysPriceLimitActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysPriceLimitActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysPriceLimitCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysPriceLimitCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysPriceLimitIteratorByAll;

	///开始寻找CSysPriceLimit
	///@return	满足条件的地一个CSysPriceLimit，如果找不到，返回NULL
	CSysPriceLimit *startFindByAll();

	///寻找下一个符合条件的CSysPriceLimit，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysPriceLimit，如果已经没有一个满足要求了，则返回NULL
	CSysPriceLimit *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysPriceLimit
	///@param	InstrumentID	
	///@return	找到的CSysPriceLimit，如果找不到，返回NULL
	CSysPriceLimit *findByOne( const CReadOnlyInstrumentIDType&  InstrumentID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysPriceLimit加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysPriceLimit	要加入的SysPriceLimit
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysPriceLimit *internalAdd(CWriteableSysPriceLimit *pSysPriceLimit, bool bNoTransaction);
	
	
	///刷新该CSysPriceLimit的键值
	///@param	pSysPriceLimit	被刷新的CSysPriceLimit
	///@param	pNewSysPriceLimit	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysPriceLimit *pSysPriceLimit, CWriteableSysPriceLimit *pNewSysPriceLimit, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysPriceLimit，同时删除其索引
	///@param	pSysPriceLimit	要删除的CSysPriceLimit
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysPriceLimit *pSysPriceLimit, bool bNoTransaction);
/*
	///检查某个CSysPriceLimit是否属于本对象工厂
	///@param	pSysPriceLimit	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysPriceLimit *pSysPriceLimit);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于InstrumentID的索引
	CAVLTree *pSysInstrumentIDIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysPriceLimit	要加入的SysPriceLimit
	virtual void beforeAdd(CWriteableSysPriceLimit *pSysPriceLimit);
	
	///加入后触发
	///@param	pSysPriceLimit	已经加入的SysPriceLimit
	virtual void afterAdd(CSysPriceLimit *pSysPriceLimit);

	///更新前触发	
	///@param	pSysPriceLimit	被刷新的CSysPriceLimit
	///@param	pNewSysPriceLimit	新的值
	virtual void beforeUpdate(CSysPriceLimit *pSysPriceLimit, CWriteableSysPriceLimit *pNewSysPriceLimit);
	
	///更新后触发
	///@param	pSysPriceLimit	被刷新的CSysPriceLimit
	virtual void afterUpdate(CSysPriceLimit *pSysPriceLimit);
	
	///删除前触发
	///@param	pSysPriceLimit	要删除的CSysPriceLimit
	virtual void beforeRemove(CSysPriceLimit *pSysPriceLimit);
	
	///确认加入后触发
	///@param	pSysPriceLimit	已经加入的SysPriceLimit
	virtual void commitAdd(CSysPriceLimit *pSysPriceLimit);

	///确认更新后触发
	///@param	pSysPriceLimit	被刷新的CSysPriceLimit
	///@param	poldSysPriceLimit	原来的值
	virtual void commitUpdate(CSysPriceLimit *pSysPriceLimit, CWriteableSysPriceLimit *pOldSysPriceLimit);
	
	///确认删除后触发
	///@param	pSysPriceLimit	已经删除的CSysPriceLimit
	virtual void commitRemove(CWriteableSysPriceLimit *pSysPriceLimit);

	///所有相关的触发器
	vector<CSysPriceLimitActionTrigger *> *pActionTriggers;
	vector<CSysPriceLimitCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysPriceLimit compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartPosiLimitFactory是一个会员限仓的对象工厂。它包含了一批会员限仓，
///同时又建立了如下索引，以方便查询：
///	SysInstrumentIDIndex
///使用本对象工厂，可以完成对会员限仓的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartPosiLimitFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysPartPosiLimitFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysPartPosiLimit，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysPartPosiLimitFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysPartPosiLimitFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysPartPosiLimit
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysPartPosiLimit，文件名将根据配置文件中的定义SysPartPosiLimitCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysPartPosiLimit
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysPartPosiLimit，文件名将根据配置文件中的定义SysPartPosiLimitCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysPartPosiLimitResource;

	///将一个CSysPartPosiLimit加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysPartPosiLimit	要加入的SysPartPosiLimit
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysPartPosiLimit *add(CWriteableSysPartPosiLimit *pSysPartPosiLimit, CTransaction *pTransaction=NULL);
	
	///刷新该CSysPartPosiLimit的值
	///@param	pSysPartPosiLimit	被刷新的CSysPartPosiLimit
	///@param	pNewSysPartPosiLimit	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysPartPosiLimit *pSysPartPosiLimit, CWriteableSysPartPosiLimit *pNewSysPartPosiLimit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysPartPosiLimit	  需要被刷新或者新增的CSysPartPosiLimit,等于NULL表示是需要新增的
	///@param	pNewSysPartPosiLimit	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysPartPosiLimit* addOrUpdate(CSysPartPosiLimit *pSysPartPosiLimit, CWriteableSysPartPosiLimit *pNewSysPartPosiLimit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysPartPosiLimit，同时删除其索引
	///@param	pSysPartPosiLimit	要删除的CSysPartPosiLimit
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysPartPosiLimit *pSysPartPosiLimit, CTransaction *pTransaction=NULL);
	
	///获取某个CSysPartPosiLimit
	///@param	pSysPartPosiLimit	要读取的CSysPartPosiLimit
	///@param	pTragetSysPartPosiLimit	存放结果的CSysPartPosiLimit
	void retrieve(CSysPartPosiLimit *pSysPartPosiLimit, CWriteableSysPartPosiLimit *pTargetSysPartPosiLimit);
	
	///获取第一个CSysPartPosiLimit
	///@return	得到的第一个CSysPartPosiLimit，如果没有，则返回NULL
	CSysPartPosiLimit *getFirst(void);
	
	///获取下一个CSysPartPosiLimit
	///@return	得到下一个CSysPartPosiLimit，如果没有，则返回NULL
	CSysPartPosiLimit *getNext(void);
	
	///结束获取CSysPartPosiLimit
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysPartPosiLimitActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysPartPosiLimitActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysPartPosiLimitCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysPartPosiLimitCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysPartPosiLimitIteratorByAll;

	///开始寻找CSysPartPosiLimit
	///@return	满足条件的地一个CSysPartPosiLimit，如果找不到，返回NULL
	CSysPartPosiLimit *startFindByAll();

	///寻找下一个符合条件的CSysPartPosiLimit，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysPartPosiLimit，如果已经没有一个满足要求了，则返回NULL
	CSysPartPosiLimit *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysPartPosiLimit
	///@param	InstrumentID	
	///@param	ParticipantID	
	///@return	找到的CSysPartPosiLimit，如果找不到，返回NULL
	CSysPartPosiLimit *findByOne( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysPartPosiLimit加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysPartPosiLimit	要加入的SysPartPosiLimit
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysPartPosiLimit *internalAdd(CWriteableSysPartPosiLimit *pSysPartPosiLimit, bool bNoTransaction);
	
	
	///刷新该CSysPartPosiLimit的键值
	///@param	pSysPartPosiLimit	被刷新的CSysPartPosiLimit
	///@param	pNewSysPartPosiLimit	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysPartPosiLimit *pSysPartPosiLimit, CWriteableSysPartPosiLimit *pNewSysPartPosiLimit, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysPartPosiLimit，同时删除其索引
	///@param	pSysPartPosiLimit	要删除的CSysPartPosiLimit
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysPartPosiLimit *pSysPartPosiLimit, bool bNoTransaction);
/*
	///检查某个CSysPartPosiLimit是否属于本对象工厂
	///@param	pSysPartPosiLimit	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysPartPosiLimit *pSysPartPosiLimit);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于InstrumentID+ParticipantID的索引
	CAVLTree *pSysInstrumentIDIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysPartPosiLimit	要加入的SysPartPosiLimit
	virtual void beforeAdd(CWriteableSysPartPosiLimit *pSysPartPosiLimit);
	
	///加入后触发
	///@param	pSysPartPosiLimit	已经加入的SysPartPosiLimit
	virtual void afterAdd(CSysPartPosiLimit *pSysPartPosiLimit);

	///更新前触发	
	///@param	pSysPartPosiLimit	被刷新的CSysPartPosiLimit
	///@param	pNewSysPartPosiLimit	新的值
	virtual void beforeUpdate(CSysPartPosiLimit *pSysPartPosiLimit, CWriteableSysPartPosiLimit *pNewSysPartPosiLimit);
	
	///更新后触发
	///@param	pSysPartPosiLimit	被刷新的CSysPartPosiLimit
	virtual void afterUpdate(CSysPartPosiLimit *pSysPartPosiLimit);
	
	///删除前触发
	///@param	pSysPartPosiLimit	要删除的CSysPartPosiLimit
	virtual void beforeRemove(CSysPartPosiLimit *pSysPartPosiLimit);
	
	///确认加入后触发
	///@param	pSysPartPosiLimit	已经加入的SysPartPosiLimit
	virtual void commitAdd(CSysPartPosiLimit *pSysPartPosiLimit);

	///确认更新后触发
	///@param	pSysPartPosiLimit	被刷新的CSysPartPosiLimit
	///@param	poldSysPartPosiLimit	原来的值
	virtual void commitUpdate(CSysPartPosiLimit *pSysPartPosiLimit, CWriteableSysPartPosiLimit *pOldSysPartPosiLimit);
	
	///确认删除后触发
	///@param	pSysPartPosiLimit	已经删除的CSysPartPosiLimit
	virtual void commitRemove(CWriteableSysPartPosiLimit *pSysPartPosiLimit);

	///所有相关的触发器
	vector<CSysPartPosiLimitActionTrigger *> *pActionTriggers;
	vector<CSysPartPosiLimitCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysPartPosiLimit compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitFactory是一个客户限仓的对象工厂。它包含了一批客户限仓，
///同时又建立了如下索引，以方便查询：
///	SysInstrumentIDIndex
///使用本对象工厂，可以完成对客户限仓的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysClientPosiLimitFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysClientPosiLimit，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysClientPosiLimitFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysClientPosiLimitFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysClientPosiLimit
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysClientPosiLimit，文件名将根据配置文件中的定义SysClientPosiLimitCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysClientPosiLimit
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysClientPosiLimit，文件名将根据配置文件中的定义SysClientPosiLimitCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysClientPosiLimitResource;

	///将一个CSysClientPosiLimit加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysClientPosiLimit	要加入的SysClientPosiLimit
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysClientPosiLimit *add(CWriteableSysClientPosiLimit *pSysClientPosiLimit, CTransaction *pTransaction=NULL);
	
	///刷新该CSysClientPosiLimit的值
	///@param	pSysClientPosiLimit	被刷新的CSysClientPosiLimit
	///@param	pNewSysClientPosiLimit	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysClientPosiLimit *pSysClientPosiLimit, CWriteableSysClientPosiLimit *pNewSysClientPosiLimit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysClientPosiLimit	  需要被刷新或者新增的CSysClientPosiLimit,等于NULL表示是需要新增的
	///@param	pNewSysClientPosiLimit	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysClientPosiLimit* addOrUpdate(CSysClientPosiLimit *pSysClientPosiLimit, CWriteableSysClientPosiLimit *pNewSysClientPosiLimit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysClientPosiLimit，同时删除其索引
	///@param	pSysClientPosiLimit	要删除的CSysClientPosiLimit
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysClientPosiLimit *pSysClientPosiLimit, CTransaction *pTransaction=NULL);
	
	///获取某个CSysClientPosiLimit
	///@param	pSysClientPosiLimit	要读取的CSysClientPosiLimit
	///@param	pTragetSysClientPosiLimit	存放结果的CSysClientPosiLimit
	void retrieve(CSysClientPosiLimit *pSysClientPosiLimit, CWriteableSysClientPosiLimit *pTargetSysClientPosiLimit);
	
	///获取第一个CSysClientPosiLimit
	///@return	得到的第一个CSysClientPosiLimit，如果没有，则返回NULL
	CSysClientPosiLimit *getFirst(void);
	
	///获取下一个CSysClientPosiLimit
	///@return	得到下一个CSysClientPosiLimit，如果没有，则返回NULL
	CSysClientPosiLimit *getNext(void);
	
	///结束获取CSysClientPosiLimit
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysClientPosiLimitActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysClientPosiLimitActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysClientPosiLimitCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysClientPosiLimitCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysClientPosiLimitIteratorByAll;

	///开始寻找CSysClientPosiLimit
	///@return	满足条件的地一个CSysClientPosiLimit，如果找不到，返回NULL
	CSysClientPosiLimit *startFindByAll();

	///寻找下一个符合条件的CSysClientPosiLimit，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysClientPosiLimit，如果已经没有一个满足要求了，则返回NULL
	CSysClientPosiLimit *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysClientPosiLimit
	///@param	InstrumentID	
	///@param	ClientType	
	///@return	找到的CSysClientPosiLimit，如果找不到，返回NULL
	CSysClientPosiLimit *findByOne( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyClientTypeType&  ClientType);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysClientPosiLimit加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysClientPosiLimit	要加入的SysClientPosiLimit
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysClientPosiLimit *internalAdd(CWriteableSysClientPosiLimit *pSysClientPosiLimit, bool bNoTransaction);
	
	
	///刷新该CSysClientPosiLimit的键值
	///@param	pSysClientPosiLimit	被刷新的CSysClientPosiLimit
	///@param	pNewSysClientPosiLimit	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysClientPosiLimit *pSysClientPosiLimit, CWriteableSysClientPosiLimit *pNewSysClientPosiLimit, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysClientPosiLimit，同时删除其索引
	///@param	pSysClientPosiLimit	要删除的CSysClientPosiLimit
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysClientPosiLimit *pSysClientPosiLimit, bool bNoTransaction);
/*
	///检查某个CSysClientPosiLimit是否属于本对象工厂
	///@param	pSysClientPosiLimit	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysClientPosiLimit *pSysClientPosiLimit);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于InstrumentID+ClientType的索引
	CAVLTree *pSysInstrumentIDIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysClientPosiLimit	要加入的SysClientPosiLimit
	virtual void beforeAdd(CWriteableSysClientPosiLimit *pSysClientPosiLimit);
	
	///加入后触发
	///@param	pSysClientPosiLimit	已经加入的SysClientPosiLimit
	virtual void afterAdd(CSysClientPosiLimit *pSysClientPosiLimit);

	///更新前触发	
	///@param	pSysClientPosiLimit	被刷新的CSysClientPosiLimit
	///@param	pNewSysClientPosiLimit	新的值
	virtual void beforeUpdate(CSysClientPosiLimit *pSysClientPosiLimit, CWriteableSysClientPosiLimit *pNewSysClientPosiLimit);
	
	///更新后触发
	///@param	pSysClientPosiLimit	被刷新的CSysClientPosiLimit
	virtual void afterUpdate(CSysClientPosiLimit *pSysClientPosiLimit);
	
	///删除前触发
	///@param	pSysClientPosiLimit	要删除的CSysClientPosiLimit
	virtual void beforeRemove(CSysClientPosiLimit *pSysClientPosiLimit);
	
	///确认加入后触发
	///@param	pSysClientPosiLimit	已经加入的SysClientPosiLimit
	virtual void commitAdd(CSysClientPosiLimit *pSysClientPosiLimit);

	///确认更新后触发
	///@param	pSysClientPosiLimit	被刷新的CSysClientPosiLimit
	///@param	poldSysClientPosiLimit	原来的值
	virtual void commitUpdate(CSysClientPosiLimit *pSysClientPosiLimit, CWriteableSysClientPosiLimit *pOldSysClientPosiLimit);
	
	///确认删除后触发
	///@param	pSysClientPosiLimit	已经删除的CSysClientPosiLimit
	virtual void commitRemove(CWriteableSysClientPosiLimit *pSysClientPosiLimit);

	///所有相关的触发器
	vector<CSysClientPosiLimitActionTrigger *> *pActionTriggers;
	vector<CSysClientPosiLimitCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysClientPosiLimit compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecialPosiLimitFactory是一个特殊客户限仓的对象工厂。它包含了一批特殊客户限仓，
///同时又建立了如下索引，以方便查询：
///	SysInstrumentIDIndex
///使用本对象工厂，可以完成对特殊客户限仓的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecialPosiLimitFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysSpecialPosiLimitFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysSpecialPosiLimit，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysSpecialPosiLimitFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysSpecialPosiLimitFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysSpecialPosiLimit
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysSpecialPosiLimit，文件名将根据配置文件中的定义SysSpecialPosiLimitCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysSpecialPosiLimit
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysSpecialPosiLimit，文件名将根据配置文件中的定义SysSpecialPosiLimitCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysSpecialPosiLimitResource;

	///将一个CSysSpecialPosiLimit加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysSpecialPosiLimit	要加入的SysSpecialPosiLimit
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysSpecialPosiLimit *add(CWriteableSysSpecialPosiLimit *pSysSpecialPosiLimit, CTransaction *pTransaction=NULL);
	
	///刷新该CSysSpecialPosiLimit的值
	///@param	pSysSpecialPosiLimit	被刷新的CSysSpecialPosiLimit
	///@param	pNewSysSpecialPosiLimit	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysSpecialPosiLimit *pSysSpecialPosiLimit, CWriteableSysSpecialPosiLimit *pNewSysSpecialPosiLimit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysSpecialPosiLimit	  需要被刷新或者新增的CSysSpecialPosiLimit,等于NULL表示是需要新增的
	///@param	pNewSysSpecialPosiLimit	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysSpecialPosiLimit* addOrUpdate(CSysSpecialPosiLimit *pSysSpecialPosiLimit, CWriteableSysSpecialPosiLimit *pNewSysSpecialPosiLimit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysSpecialPosiLimit，同时删除其索引
	///@param	pSysSpecialPosiLimit	要删除的CSysSpecialPosiLimit
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysSpecialPosiLimit *pSysSpecialPosiLimit, CTransaction *pTransaction=NULL);
	
	///获取某个CSysSpecialPosiLimit
	///@param	pSysSpecialPosiLimit	要读取的CSysSpecialPosiLimit
	///@param	pTragetSysSpecialPosiLimit	存放结果的CSysSpecialPosiLimit
	void retrieve(CSysSpecialPosiLimit *pSysSpecialPosiLimit, CWriteableSysSpecialPosiLimit *pTargetSysSpecialPosiLimit);
	
	///获取第一个CSysSpecialPosiLimit
	///@return	得到的第一个CSysSpecialPosiLimit，如果没有，则返回NULL
	CSysSpecialPosiLimit *getFirst(void);
	
	///获取下一个CSysSpecialPosiLimit
	///@return	得到下一个CSysSpecialPosiLimit，如果没有，则返回NULL
	CSysSpecialPosiLimit *getNext(void);
	
	///结束获取CSysSpecialPosiLimit
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysSpecialPosiLimitActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysSpecialPosiLimitActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysSpecialPosiLimitCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysSpecialPosiLimitCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysSpecialPosiLimitIteratorByAll;

	///开始寻找CSysSpecialPosiLimit
	///@return	满足条件的地一个CSysSpecialPosiLimit，如果找不到，返回NULL
	CSysSpecialPosiLimit *startFindByAll();

	///寻找下一个符合条件的CSysSpecialPosiLimit，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysSpecialPosiLimit，如果已经没有一个满足要求了，则返回NULL
	CSysSpecialPosiLimit *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysSpecialPosiLimit
	///@param	InstrumentID	
	///@param	ClientID	
	///@return	找到的CSysSpecialPosiLimit，如果找不到，返回NULL
	CSysSpecialPosiLimit *findByOne( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyClientIDType&  ClientID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysSpecialPosiLimit加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysSpecialPosiLimit	要加入的SysSpecialPosiLimit
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysSpecialPosiLimit *internalAdd(CWriteableSysSpecialPosiLimit *pSysSpecialPosiLimit, bool bNoTransaction);
	
	
	///刷新该CSysSpecialPosiLimit的键值
	///@param	pSysSpecialPosiLimit	被刷新的CSysSpecialPosiLimit
	///@param	pNewSysSpecialPosiLimit	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysSpecialPosiLimit *pSysSpecialPosiLimit, CWriteableSysSpecialPosiLimit *pNewSysSpecialPosiLimit, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysSpecialPosiLimit，同时删除其索引
	///@param	pSysSpecialPosiLimit	要删除的CSysSpecialPosiLimit
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysSpecialPosiLimit *pSysSpecialPosiLimit, bool bNoTransaction);
/*
	///检查某个CSysSpecialPosiLimit是否属于本对象工厂
	///@param	pSysSpecialPosiLimit	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysSpecialPosiLimit *pSysSpecialPosiLimit);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于InstrumentID+ClientID的索引
	CAVLTree *pSysInstrumentIDIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysSpecialPosiLimit	要加入的SysSpecialPosiLimit
	virtual void beforeAdd(CWriteableSysSpecialPosiLimit *pSysSpecialPosiLimit);
	
	///加入后触发
	///@param	pSysSpecialPosiLimit	已经加入的SysSpecialPosiLimit
	virtual void afterAdd(CSysSpecialPosiLimit *pSysSpecialPosiLimit);

	///更新前触发	
	///@param	pSysSpecialPosiLimit	被刷新的CSysSpecialPosiLimit
	///@param	pNewSysSpecialPosiLimit	新的值
	virtual void beforeUpdate(CSysSpecialPosiLimit *pSysSpecialPosiLimit, CWriteableSysSpecialPosiLimit *pNewSysSpecialPosiLimit);
	
	///更新后触发
	///@param	pSysSpecialPosiLimit	被刷新的CSysSpecialPosiLimit
	virtual void afterUpdate(CSysSpecialPosiLimit *pSysSpecialPosiLimit);
	
	///删除前触发
	///@param	pSysSpecialPosiLimit	要删除的CSysSpecialPosiLimit
	virtual void beforeRemove(CSysSpecialPosiLimit *pSysSpecialPosiLimit);
	
	///确认加入后触发
	///@param	pSysSpecialPosiLimit	已经加入的SysSpecialPosiLimit
	virtual void commitAdd(CSysSpecialPosiLimit *pSysSpecialPosiLimit);

	///确认更新后触发
	///@param	pSysSpecialPosiLimit	被刷新的CSysSpecialPosiLimit
	///@param	poldSysSpecialPosiLimit	原来的值
	virtual void commitUpdate(CSysSpecialPosiLimit *pSysSpecialPosiLimit, CWriteableSysSpecialPosiLimit *pOldSysSpecialPosiLimit);
	
	///确认删除后触发
	///@param	pSysSpecialPosiLimit	已经删除的CSysSpecialPosiLimit
	virtual void commitRemove(CWriteableSysSpecialPosiLimit *pSysSpecialPosiLimit);

	///所有相关的触发器
	vector<CSysSpecialPosiLimitActionTrigger *> *pActionTriggers;
	vector<CSysSpecialPosiLimitCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysSpecialPosiLimit compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysTransactionChgFactory是一个账户出入金查询的对象工厂。它包含了一批账户出入金查询，
///同时又建立了如下索引，以方便查询：
///	SysActionTimeIndex
///使用本对象工厂，可以完成对账户出入金查询的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByActionTime，findNextByActionTime和endFindByActionTime完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTransactionChgFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysTransactionChgFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysTransactionChg，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysTransactionChgFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysTransactionChgFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysTransactionChg
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysTransactionChg，文件名将根据配置文件中的定义SysTransactionChgCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysTransactionChg
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysTransactionChg，文件名将根据配置文件中的定义SysTransactionChgCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysTransactionChgResource;

	///将一个CSysTransactionChg加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysTransactionChg	要加入的SysTransactionChg
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysTransactionChg *add(CWriteableSysTransactionChg *pSysTransactionChg, CTransaction *pTransaction=NULL);
	
	///刷新该CSysTransactionChg的值
	///@param	pSysTransactionChg	被刷新的CSysTransactionChg
	///@param	pNewSysTransactionChg	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysTransactionChg *pSysTransactionChg, CWriteableSysTransactionChg *pNewSysTransactionChg, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysTransactionChg	  需要被刷新或者新增的CSysTransactionChg,等于NULL表示是需要新增的
	///@param	pNewSysTransactionChg	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysTransactionChg* addOrUpdate(CSysTransactionChg *pSysTransactionChg, CWriteableSysTransactionChg *pNewSysTransactionChg, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysTransactionChg，同时删除其索引
	///@param	pSysTransactionChg	要删除的CSysTransactionChg
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysTransactionChg *pSysTransactionChg, CTransaction *pTransaction=NULL);
	
	///获取某个CSysTransactionChg
	///@param	pSysTransactionChg	要读取的CSysTransactionChg
	///@param	pTragetSysTransactionChg	存放结果的CSysTransactionChg
	void retrieve(CSysTransactionChg *pSysTransactionChg, CWriteableSysTransactionChg *pTargetSysTransactionChg);
	
	///获取第一个CSysTransactionChg
	///@return	得到的第一个CSysTransactionChg，如果没有，则返回NULL
	CSysTransactionChg *getFirst(void);
	
	///获取下一个CSysTransactionChg
	///@return	得到下一个CSysTransactionChg，如果没有，则返回NULL
	CSysTransactionChg *getNext(void);
	
	///结束获取CSysTransactionChg
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysTransactionChgActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysTransactionChgActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysTransactionChgCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysTransactionChgCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysTransactionChgIteratorByActionTime;

	///开始寻找CSysTransactionChg
	///@param	ActionTime	
	///@return	满足条件的地一个CSysTransactionChg，如果找不到，返回NULL
	CSysTransactionChg *startFindByActionTime( const CReadOnlyTimeType& ActionTime);

	///寻找下一个符合条件的CSysTransactionChg，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysTransactionChg，如果已经没有一个满足要求了，则返回NULL
	CSysTransactionChg *findNextByActionTime(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByActionTime(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysTransactionChg加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysTransactionChg	要加入的SysTransactionChg
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysTransactionChg *internalAdd(CWriteableSysTransactionChg *pSysTransactionChg, bool bNoTransaction);
	
	
	///刷新该CSysTransactionChg的键值
	///@param	pSysTransactionChg	被刷新的CSysTransactionChg
	///@param	pNewSysTransactionChg	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysTransactionChg *pSysTransactionChg, CWriteableSysTransactionChg *pNewSysTransactionChg, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysTransactionChg，同时删除其索引
	///@param	pSysTransactionChg	要删除的CSysTransactionChg
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysTransactionChg *pSysTransactionChg, bool bNoTransaction);
/*
	///检查某个CSysTransactionChg是否属于本对象工厂
	///@param	pSysTransactionChg	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysTransactionChg *pSysTransactionChg);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ActionTime的索引
	CAVLTree *pSysActionTimeIndex;
	
	
	///按照ActionTime检索时，存储的查询参数
	CTimeType queryActionTimeInSearchByActionTime;
	
	///按照ActionTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByActionTime;
	
	///加入前触发
	///@param	pSysTransactionChg	要加入的SysTransactionChg
	virtual void beforeAdd(CWriteableSysTransactionChg *pSysTransactionChg);
	
	///加入后触发
	///@param	pSysTransactionChg	已经加入的SysTransactionChg
	virtual void afterAdd(CSysTransactionChg *pSysTransactionChg);

	///更新前触发	
	///@param	pSysTransactionChg	被刷新的CSysTransactionChg
	///@param	pNewSysTransactionChg	新的值
	virtual void beforeUpdate(CSysTransactionChg *pSysTransactionChg, CWriteableSysTransactionChg *pNewSysTransactionChg);
	
	///更新后触发
	///@param	pSysTransactionChg	被刷新的CSysTransactionChg
	virtual void afterUpdate(CSysTransactionChg *pSysTransactionChg);
	
	///删除前触发
	///@param	pSysTransactionChg	要删除的CSysTransactionChg
	virtual void beforeRemove(CSysTransactionChg *pSysTransactionChg);
	
	///确认加入后触发
	///@param	pSysTransactionChg	已经加入的SysTransactionChg
	virtual void commitAdd(CSysTransactionChg *pSysTransactionChg);

	///确认更新后触发
	///@param	pSysTransactionChg	被刷新的CSysTransactionChg
	///@param	poldSysTransactionChg	原来的值
	virtual void commitUpdate(CSysTransactionChg *pSysTransactionChg, CWriteableSysTransactionChg *pOldSysTransactionChg);
	
	///确认删除后触发
	///@param	pSysTransactionChg	已经删除的CSysTransactionChg
	virtual void commitRemove(CWriteableSysTransactionChg *pSysTransactionChg);

	///所有相关的触发器
	vector<CSysTransactionChgActionTrigger *> *pActionTriggers;
	vector<CSysTransactionChgCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysTransactionChg compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientChgFactory是一个客户数据变动查询的对象工厂。它包含了一批客户数据变动查询，
///同时又建立了如下索引，以方便查询：
///	SysActionTimeIndex
///使用本对象工厂，可以完成对客户数据变动查询的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByActionTime，findNextByActionTime和endFindByActionTime完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientChgFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysClientChgFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysClientChg，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysClientChgFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysClientChgFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysClientChg
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysClientChg，文件名将根据配置文件中的定义SysClientChgCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysClientChg
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysClientChg，文件名将根据配置文件中的定义SysClientChgCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysClientChgResource;

	///将一个CSysClientChg加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysClientChg	要加入的SysClientChg
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysClientChg *add(CWriteableSysClientChg *pSysClientChg, CTransaction *pTransaction=NULL);
	
	///刷新该CSysClientChg的值
	///@param	pSysClientChg	被刷新的CSysClientChg
	///@param	pNewSysClientChg	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysClientChg *pSysClientChg, CWriteableSysClientChg *pNewSysClientChg, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysClientChg	  需要被刷新或者新增的CSysClientChg,等于NULL表示是需要新增的
	///@param	pNewSysClientChg	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysClientChg* addOrUpdate(CSysClientChg *pSysClientChg, CWriteableSysClientChg *pNewSysClientChg, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysClientChg，同时删除其索引
	///@param	pSysClientChg	要删除的CSysClientChg
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysClientChg *pSysClientChg, CTransaction *pTransaction=NULL);
	
	///获取某个CSysClientChg
	///@param	pSysClientChg	要读取的CSysClientChg
	///@param	pTragetSysClientChg	存放结果的CSysClientChg
	void retrieve(CSysClientChg *pSysClientChg, CWriteableSysClientChg *pTargetSysClientChg);
	
	///获取第一个CSysClientChg
	///@return	得到的第一个CSysClientChg，如果没有，则返回NULL
	CSysClientChg *getFirst(void);
	
	///获取下一个CSysClientChg
	///@return	得到下一个CSysClientChg，如果没有，则返回NULL
	CSysClientChg *getNext(void);
	
	///结束获取CSysClientChg
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysClientChgActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysClientChgActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysClientChgCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysClientChgCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysClientChgIteratorByActionTime;

	///开始寻找CSysClientChg
	///@param	ActionTime	
	///@return	满足条件的地一个CSysClientChg，如果找不到，返回NULL
	CSysClientChg *startFindByActionTime( const CReadOnlyTimeType& ActionTime);

	///寻找下一个符合条件的CSysClientChg，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysClientChg，如果已经没有一个满足要求了，则返回NULL
	CSysClientChg *findNextByActionTime(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByActionTime(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysClientChg加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysClientChg	要加入的SysClientChg
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysClientChg *internalAdd(CWriteableSysClientChg *pSysClientChg, bool bNoTransaction);
	
	
	///刷新该CSysClientChg的键值
	///@param	pSysClientChg	被刷新的CSysClientChg
	///@param	pNewSysClientChg	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysClientChg *pSysClientChg, CWriteableSysClientChg *pNewSysClientChg, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysClientChg，同时删除其索引
	///@param	pSysClientChg	要删除的CSysClientChg
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysClientChg *pSysClientChg, bool bNoTransaction);
/*
	///检查某个CSysClientChg是否属于本对象工厂
	///@param	pSysClientChg	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysClientChg *pSysClientChg);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ActionTime的索引
	CAVLTree *pSysActionTimeIndex;
	
	
	///按照ActionTime检索时，存储的查询参数
	CTimeType queryActionTimeInSearchByActionTime;
	
	///按照ActionTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByActionTime;
	
	///加入前触发
	///@param	pSysClientChg	要加入的SysClientChg
	virtual void beforeAdd(CWriteableSysClientChg *pSysClientChg);
	
	///加入后触发
	///@param	pSysClientChg	已经加入的SysClientChg
	virtual void afterAdd(CSysClientChg *pSysClientChg);

	///更新前触发	
	///@param	pSysClientChg	被刷新的CSysClientChg
	///@param	pNewSysClientChg	新的值
	virtual void beforeUpdate(CSysClientChg *pSysClientChg, CWriteableSysClientChg *pNewSysClientChg);
	
	///更新后触发
	///@param	pSysClientChg	被刷新的CSysClientChg
	virtual void afterUpdate(CSysClientChg *pSysClientChg);
	
	///删除前触发
	///@param	pSysClientChg	要删除的CSysClientChg
	virtual void beforeRemove(CSysClientChg *pSysClientChg);
	
	///确认加入后触发
	///@param	pSysClientChg	已经加入的SysClientChg
	virtual void commitAdd(CSysClientChg *pSysClientChg);

	///确认更新后触发
	///@param	pSysClientChg	被刷新的CSysClientChg
	///@param	poldSysClientChg	原来的值
	virtual void commitUpdate(CSysClientChg *pSysClientChg, CWriteableSysClientChg *pOldSysClientChg);
	
	///确认删除后触发
	///@param	pSysClientChg	已经删除的CSysClientChg
	virtual void commitRemove(CWriteableSysClientChg *pSysClientChg);

	///所有相关的触发器
	vector<CSysClientChgActionTrigger *> *pActionTriggers;
	vector<CSysClientChgCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysClientChg compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartClientChgFactory是一个会员客户对照变动查询的对象工厂。它包含了一批会员客户对照变动查询，
///同时又建立了如下索引，以方便查询：
///	SysActionTimeIndex
///使用本对象工厂，可以完成对会员客户对照变动查询的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByActionTime，findNextByActionTime和endFindByActionTime完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartClientChgFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysPartClientChgFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysPartClientChg，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysPartClientChgFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysPartClientChgFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysPartClientChg
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysPartClientChg，文件名将根据配置文件中的定义SysPartClientChgCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysPartClientChg
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysPartClientChg，文件名将根据配置文件中的定义SysPartClientChgCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysPartClientChgResource;

	///将一个CSysPartClientChg加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysPartClientChg	要加入的SysPartClientChg
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysPartClientChg *add(CWriteableSysPartClientChg *pSysPartClientChg, CTransaction *pTransaction=NULL);
	
	///刷新该CSysPartClientChg的值
	///@param	pSysPartClientChg	被刷新的CSysPartClientChg
	///@param	pNewSysPartClientChg	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysPartClientChg *pSysPartClientChg, CWriteableSysPartClientChg *pNewSysPartClientChg, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysPartClientChg	  需要被刷新或者新增的CSysPartClientChg,等于NULL表示是需要新增的
	///@param	pNewSysPartClientChg	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysPartClientChg* addOrUpdate(CSysPartClientChg *pSysPartClientChg, CWriteableSysPartClientChg *pNewSysPartClientChg, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysPartClientChg，同时删除其索引
	///@param	pSysPartClientChg	要删除的CSysPartClientChg
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysPartClientChg *pSysPartClientChg, CTransaction *pTransaction=NULL);
	
	///获取某个CSysPartClientChg
	///@param	pSysPartClientChg	要读取的CSysPartClientChg
	///@param	pTragetSysPartClientChg	存放结果的CSysPartClientChg
	void retrieve(CSysPartClientChg *pSysPartClientChg, CWriteableSysPartClientChg *pTargetSysPartClientChg);
	
	///获取第一个CSysPartClientChg
	///@return	得到的第一个CSysPartClientChg，如果没有，则返回NULL
	CSysPartClientChg *getFirst(void);
	
	///获取下一个CSysPartClientChg
	///@return	得到下一个CSysPartClientChg，如果没有，则返回NULL
	CSysPartClientChg *getNext(void);
	
	///结束获取CSysPartClientChg
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysPartClientChgActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysPartClientChgActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysPartClientChgCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysPartClientChgCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysPartClientChgIteratorByActionTime;

	///开始寻找CSysPartClientChg
	///@param	ActionTime	
	///@return	满足条件的地一个CSysPartClientChg，如果找不到，返回NULL
	CSysPartClientChg *startFindByActionTime( const CReadOnlyTimeType& ActionTime);

	///寻找下一个符合条件的CSysPartClientChg，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysPartClientChg，如果已经没有一个满足要求了，则返回NULL
	CSysPartClientChg *findNextByActionTime(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByActionTime(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysPartClientChg加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysPartClientChg	要加入的SysPartClientChg
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysPartClientChg *internalAdd(CWriteableSysPartClientChg *pSysPartClientChg, bool bNoTransaction);
	
	
	///刷新该CSysPartClientChg的键值
	///@param	pSysPartClientChg	被刷新的CSysPartClientChg
	///@param	pNewSysPartClientChg	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysPartClientChg *pSysPartClientChg, CWriteableSysPartClientChg *pNewSysPartClientChg, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysPartClientChg，同时删除其索引
	///@param	pSysPartClientChg	要删除的CSysPartClientChg
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysPartClientChg *pSysPartClientChg, bool bNoTransaction);
/*
	///检查某个CSysPartClientChg是否属于本对象工厂
	///@param	pSysPartClientChg	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysPartClientChg *pSysPartClientChg);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ActionTime的索引
	CAVLTree *pSysActionTimeIndex;
	
	
	///按照ActionTime检索时，存储的查询参数
	CTimeType queryActionTimeInSearchByActionTime;
	
	///按照ActionTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByActionTime;
	
	///加入前触发
	///@param	pSysPartClientChg	要加入的SysPartClientChg
	virtual void beforeAdd(CWriteableSysPartClientChg *pSysPartClientChg);
	
	///加入后触发
	///@param	pSysPartClientChg	已经加入的SysPartClientChg
	virtual void afterAdd(CSysPartClientChg *pSysPartClientChg);

	///更新前触发	
	///@param	pSysPartClientChg	被刷新的CSysPartClientChg
	///@param	pNewSysPartClientChg	新的值
	virtual void beforeUpdate(CSysPartClientChg *pSysPartClientChg, CWriteableSysPartClientChg *pNewSysPartClientChg);
	
	///更新后触发
	///@param	pSysPartClientChg	被刷新的CSysPartClientChg
	virtual void afterUpdate(CSysPartClientChg *pSysPartClientChg);
	
	///删除前触发
	///@param	pSysPartClientChg	要删除的CSysPartClientChg
	virtual void beforeRemove(CSysPartClientChg *pSysPartClientChg);
	
	///确认加入后触发
	///@param	pSysPartClientChg	已经加入的SysPartClientChg
	virtual void commitAdd(CSysPartClientChg *pSysPartClientChg);

	///确认更新后触发
	///@param	pSysPartClientChg	被刷新的CSysPartClientChg
	///@param	poldSysPartClientChg	原来的值
	virtual void commitUpdate(CSysPartClientChg *pSysPartClientChg, CWriteableSysPartClientChg *pOldSysPartClientChg);
	
	///确认删除后触发
	///@param	pSysPartClientChg	已经删除的CSysPartClientChg
	virtual void commitRemove(CWriteableSysPartClientChg *pSysPartClientChg);

	///所有相关的触发器
	vector<CSysPartClientChgActionTrigger *> *pActionTriggers;
	vector<CSysPartClientChgCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysPartClientChg compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysPosiLimitChgFactory是一个限仓数据变动查询的对象工厂。它包含了一批限仓数据变动查询，
///同时又建立了如下索引，以方便查询：
///	SysActionTimeIndex
///使用本对象工厂，可以完成对限仓数据变动查询的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByActionTime，findNextByActionTime和endFindByActionTime完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPosiLimitChgFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysPosiLimitChgFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysPosiLimitChg，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysPosiLimitChgFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysPosiLimitChgFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysPosiLimitChg
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysPosiLimitChg，文件名将根据配置文件中的定义SysPosiLimitChgCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysPosiLimitChg
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysPosiLimitChg，文件名将根据配置文件中的定义SysPosiLimitChgCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysPosiLimitChgResource;

	///将一个CSysPosiLimitChg加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysPosiLimitChg	要加入的SysPosiLimitChg
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysPosiLimitChg *add(CWriteableSysPosiLimitChg *pSysPosiLimitChg, CTransaction *pTransaction=NULL);
	
	///刷新该CSysPosiLimitChg的值
	///@param	pSysPosiLimitChg	被刷新的CSysPosiLimitChg
	///@param	pNewSysPosiLimitChg	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysPosiLimitChg *pSysPosiLimitChg, CWriteableSysPosiLimitChg *pNewSysPosiLimitChg, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysPosiLimitChg	  需要被刷新或者新增的CSysPosiLimitChg,等于NULL表示是需要新增的
	///@param	pNewSysPosiLimitChg	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysPosiLimitChg* addOrUpdate(CSysPosiLimitChg *pSysPosiLimitChg, CWriteableSysPosiLimitChg *pNewSysPosiLimitChg, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysPosiLimitChg，同时删除其索引
	///@param	pSysPosiLimitChg	要删除的CSysPosiLimitChg
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysPosiLimitChg *pSysPosiLimitChg, CTransaction *pTransaction=NULL);
	
	///获取某个CSysPosiLimitChg
	///@param	pSysPosiLimitChg	要读取的CSysPosiLimitChg
	///@param	pTragetSysPosiLimitChg	存放结果的CSysPosiLimitChg
	void retrieve(CSysPosiLimitChg *pSysPosiLimitChg, CWriteableSysPosiLimitChg *pTargetSysPosiLimitChg);
	
	///获取第一个CSysPosiLimitChg
	///@return	得到的第一个CSysPosiLimitChg，如果没有，则返回NULL
	CSysPosiLimitChg *getFirst(void);
	
	///获取下一个CSysPosiLimitChg
	///@return	得到下一个CSysPosiLimitChg，如果没有，则返回NULL
	CSysPosiLimitChg *getNext(void);
	
	///结束获取CSysPosiLimitChg
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysPosiLimitChgActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysPosiLimitChgActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysPosiLimitChgCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysPosiLimitChgCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysPosiLimitChgIteratorByActionTime;

	///开始寻找CSysPosiLimitChg
	///@param	ActionTime	
	///@return	满足条件的地一个CSysPosiLimitChg，如果找不到，返回NULL
	CSysPosiLimitChg *startFindByActionTime( const CReadOnlyTimeType& ActionTime);

	///寻找下一个符合条件的CSysPosiLimitChg，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysPosiLimitChg，如果已经没有一个满足要求了，则返回NULL
	CSysPosiLimitChg *findNextByActionTime(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByActionTime(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysPosiLimitChg加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysPosiLimitChg	要加入的SysPosiLimitChg
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysPosiLimitChg *internalAdd(CWriteableSysPosiLimitChg *pSysPosiLimitChg, bool bNoTransaction);
	
	
	///刷新该CSysPosiLimitChg的键值
	///@param	pSysPosiLimitChg	被刷新的CSysPosiLimitChg
	///@param	pNewSysPosiLimitChg	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysPosiLimitChg *pSysPosiLimitChg, CWriteableSysPosiLimitChg *pNewSysPosiLimitChg, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysPosiLimitChg，同时删除其索引
	///@param	pSysPosiLimitChg	要删除的CSysPosiLimitChg
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysPosiLimitChg *pSysPosiLimitChg, bool bNoTransaction);
/*
	///检查某个CSysPosiLimitChg是否属于本对象工厂
	///@param	pSysPosiLimitChg	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysPosiLimitChg *pSysPosiLimitChg);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ActionTime的索引
	CAVLTree *pSysActionTimeIndex;
	
	
	///按照ActionTime检索时，存储的查询参数
	CTimeType queryActionTimeInSearchByActionTime;
	
	///按照ActionTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByActionTime;
	
	///加入前触发
	///@param	pSysPosiLimitChg	要加入的SysPosiLimitChg
	virtual void beforeAdd(CWriteableSysPosiLimitChg *pSysPosiLimitChg);
	
	///加入后触发
	///@param	pSysPosiLimitChg	已经加入的SysPosiLimitChg
	virtual void afterAdd(CSysPosiLimitChg *pSysPosiLimitChg);

	///更新前触发	
	///@param	pSysPosiLimitChg	被刷新的CSysPosiLimitChg
	///@param	pNewSysPosiLimitChg	新的值
	virtual void beforeUpdate(CSysPosiLimitChg *pSysPosiLimitChg, CWriteableSysPosiLimitChg *pNewSysPosiLimitChg);
	
	///更新后触发
	///@param	pSysPosiLimitChg	被刷新的CSysPosiLimitChg
	virtual void afterUpdate(CSysPosiLimitChg *pSysPosiLimitChg);
	
	///删除前触发
	///@param	pSysPosiLimitChg	要删除的CSysPosiLimitChg
	virtual void beforeRemove(CSysPosiLimitChg *pSysPosiLimitChg);
	
	///确认加入后触发
	///@param	pSysPosiLimitChg	已经加入的SysPosiLimitChg
	virtual void commitAdd(CSysPosiLimitChg *pSysPosiLimitChg);

	///确认更新后触发
	///@param	pSysPosiLimitChg	被刷新的CSysPosiLimitChg
	///@param	poldSysPosiLimitChg	原来的值
	virtual void commitUpdate(CSysPosiLimitChg *pSysPosiLimitChg, CWriteableSysPosiLimitChg *pOldSysPosiLimitChg);
	
	///确认删除后触发
	///@param	pSysPosiLimitChg	已经删除的CSysPosiLimitChg
	virtual void commitRemove(CWriteableSysPosiLimitChg *pSysPosiLimitChg);

	///所有相关的触发器
	vector<CSysPosiLimitChgActionTrigger *> *pActionTriggers;
	vector<CSysPosiLimitChgCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysPosiLimitChg compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitChgFactory是一个限仓数据变动查询的对象工厂。它包含了一批限仓数据变动查询，
///同时又建立了如下索引，以方便查询：
///	SysActionTimeIndex
///使用本对象工厂，可以完成对限仓数据变动查询的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByActionTime，findNextByActionTime和endFindByActionTime完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitChgFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysClientPosiLimitChgFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysClientPosiLimitChg，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysClientPosiLimitChgFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysClientPosiLimitChgFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysClientPosiLimitChg
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysClientPosiLimitChg，文件名将根据配置文件中的定义SysClientPosiLimitChgCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysClientPosiLimitChg
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysClientPosiLimitChg，文件名将根据配置文件中的定义SysClientPosiLimitChgCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysClientPosiLimitChgResource;

	///将一个CSysClientPosiLimitChg加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysClientPosiLimitChg	要加入的SysClientPosiLimitChg
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysClientPosiLimitChg *add(CWriteableSysClientPosiLimitChg *pSysClientPosiLimitChg, CTransaction *pTransaction=NULL);
	
	///刷新该CSysClientPosiLimitChg的值
	///@param	pSysClientPosiLimitChg	被刷新的CSysClientPosiLimitChg
	///@param	pNewSysClientPosiLimitChg	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysClientPosiLimitChg *pSysClientPosiLimitChg, CWriteableSysClientPosiLimitChg *pNewSysClientPosiLimitChg, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysClientPosiLimitChg	  需要被刷新或者新增的CSysClientPosiLimitChg,等于NULL表示是需要新增的
	///@param	pNewSysClientPosiLimitChg	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysClientPosiLimitChg* addOrUpdate(CSysClientPosiLimitChg *pSysClientPosiLimitChg, CWriteableSysClientPosiLimitChg *pNewSysClientPosiLimitChg, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysClientPosiLimitChg，同时删除其索引
	///@param	pSysClientPosiLimitChg	要删除的CSysClientPosiLimitChg
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysClientPosiLimitChg *pSysClientPosiLimitChg, CTransaction *pTransaction=NULL);
	
	///获取某个CSysClientPosiLimitChg
	///@param	pSysClientPosiLimitChg	要读取的CSysClientPosiLimitChg
	///@param	pTragetSysClientPosiLimitChg	存放结果的CSysClientPosiLimitChg
	void retrieve(CSysClientPosiLimitChg *pSysClientPosiLimitChg, CWriteableSysClientPosiLimitChg *pTargetSysClientPosiLimitChg);
	
	///获取第一个CSysClientPosiLimitChg
	///@return	得到的第一个CSysClientPosiLimitChg，如果没有，则返回NULL
	CSysClientPosiLimitChg *getFirst(void);
	
	///获取下一个CSysClientPosiLimitChg
	///@return	得到下一个CSysClientPosiLimitChg，如果没有，则返回NULL
	CSysClientPosiLimitChg *getNext(void);
	
	///结束获取CSysClientPosiLimitChg
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysClientPosiLimitChgActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysClientPosiLimitChgActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysClientPosiLimitChgCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysClientPosiLimitChgCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysClientPosiLimitChgIteratorByActionTime;

	///开始寻找CSysClientPosiLimitChg
	///@param	ActionTime	
	///@return	满足条件的地一个CSysClientPosiLimitChg，如果找不到，返回NULL
	CSysClientPosiLimitChg *startFindByActionTime( const CReadOnlyTimeType& ActionTime);

	///寻找下一个符合条件的CSysClientPosiLimitChg，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysClientPosiLimitChg，如果已经没有一个满足要求了，则返回NULL
	CSysClientPosiLimitChg *findNextByActionTime(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByActionTime(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysClientPosiLimitChg加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysClientPosiLimitChg	要加入的SysClientPosiLimitChg
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysClientPosiLimitChg *internalAdd(CWriteableSysClientPosiLimitChg *pSysClientPosiLimitChg, bool bNoTransaction);
	
	
	///刷新该CSysClientPosiLimitChg的键值
	///@param	pSysClientPosiLimitChg	被刷新的CSysClientPosiLimitChg
	///@param	pNewSysClientPosiLimitChg	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysClientPosiLimitChg *pSysClientPosiLimitChg, CWriteableSysClientPosiLimitChg *pNewSysClientPosiLimitChg, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysClientPosiLimitChg，同时删除其索引
	///@param	pSysClientPosiLimitChg	要删除的CSysClientPosiLimitChg
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysClientPosiLimitChg *pSysClientPosiLimitChg, bool bNoTransaction);
/*
	///检查某个CSysClientPosiLimitChg是否属于本对象工厂
	///@param	pSysClientPosiLimitChg	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysClientPosiLimitChg *pSysClientPosiLimitChg);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ActionTime的索引
	CAVLTree *pSysActionTimeIndex;
	
	
	///按照ActionTime检索时，存储的查询参数
	CTimeType queryActionTimeInSearchByActionTime;
	
	///按照ActionTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByActionTime;
	
	///加入前触发
	///@param	pSysClientPosiLimitChg	要加入的SysClientPosiLimitChg
	virtual void beforeAdd(CWriteableSysClientPosiLimitChg *pSysClientPosiLimitChg);
	
	///加入后触发
	///@param	pSysClientPosiLimitChg	已经加入的SysClientPosiLimitChg
	virtual void afterAdd(CSysClientPosiLimitChg *pSysClientPosiLimitChg);

	///更新前触发	
	///@param	pSysClientPosiLimitChg	被刷新的CSysClientPosiLimitChg
	///@param	pNewSysClientPosiLimitChg	新的值
	virtual void beforeUpdate(CSysClientPosiLimitChg *pSysClientPosiLimitChg, CWriteableSysClientPosiLimitChg *pNewSysClientPosiLimitChg);
	
	///更新后触发
	///@param	pSysClientPosiLimitChg	被刷新的CSysClientPosiLimitChg
	virtual void afterUpdate(CSysClientPosiLimitChg *pSysClientPosiLimitChg);
	
	///删除前触发
	///@param	pSysClientPosiLimitChg	要删除的CSysClientPosiLimitChg
	virtual void beforeRemove(CSysClientPosiLimitChg *pSysClientPosiLimitChg);
	
	///确认加入后触发
	///@param	pSysClientPosiLimitChg	已经加入的SysClientPosiLimitChg
	virtual void commitAdd(CSysClientPosiLimitChg *pSysClientPosiLimitChg);

	///确认更新后触发
	///@param	pSysClientPosiLimitChg	被刷新的CSysClientPosiLimitChg
	///@param	poldSysClientPosiLimitChg	原来的值
	virtual void commitUpdate(CSysClientPosiLimitChg *pSysClientPosiLimitChg, CWriteableSysClientPosiLimitChg *pOldSysClientPosiLimitChg);
	
	///确认删除后触发
	///@param	pSysClientPosiLimitChg	已经删除的CSysClientPosiLimitChg
	virtual void commitRemove(CWriteableSysClientPosiLimitChg *pSysClientPosiLimitChg);

	///所有相关的触发器
	vector<CSysClientPosiLimitChgActionTrigger *> *pActionTriggers;
	vector<CSysClientPosiLimitChgCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysClientPosiLimitChg compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecPosiLimitChgFactory是一个限仓数据变动查询的对象工厂。它包含了一批限仓数据变动查询，
///同时又建立了如下索引，以方便查询：
///	SysActionTimeIndex
///使用本对象工厂，可以完成对限仓数据变动查询的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByActionTime，findNextByActionTime和endFindByActionTime完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecPosiLimitChgFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysSpecPosiLimitChgFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysSpecPosiLimitChg，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysSpecPosiLimitChgFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysSpecPosiLimitChgFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysSpecPosiLimitChg
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysSpecPosiLimitChg，文件名将根据配置文件中的定义SysSpecPosiLimitChgCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysSpecPosiLimitChg
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysSpecPosiLimitChg，文件名将根据配置文件中的定义SysSpecPosiLimitChgCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysSpecPosiLimitChgResource;

	///将一个CSysSpecPosiLimitChg加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysSpecPosiLimitChg	要加入的SysSpecPosiLimitChg
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysSpecPosiLimitChg *add(CWriteableSysSpecPosiLimitChg *pSysSpecPosiLimitChg, CTransaction *pTransaction=NULL);
	
	///刷新该CSysSpecPosiLimitChg的值
	///@param	pSysSpecPosiLimitChg	被刷新的CSysSpecPosiLimitChg
	///@param	pNewSysSpecPosiLimitChg	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg, CWriteableSysSpecPosiLimitChg *pNewSysSpecPosiLimitChg, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysSpecPosiLimitChg	  需要被刷新或者新增的CSysSpecPosiLimitChg,等于NULL表示是需要新增的
	///@param	pNewSysSpecPosiLimitChg	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysSpecPosiLimitChg* addOrUpdate(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg, CWriteableSysSpecPosiLimitChg *pNewSysSpecPosiLimitChg, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysSpecPosiLimitChg，同时删除其索引
	///@param	pSysSpecPosiLimitChg	要删除的CSysSpecPosiLimitChg
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg, CTransaction *pTransaction=NULL);
	
	///获取某个CSysSpecPosiLimitChg
	///@param	pSysSpecPosiLimitChg	要读取的CSysSpecPosiLimitChg
	///@param	pTragetSysSpecPosiLimitChg	存放结果的CSysSpecPosiLimitChg
	void retrieve(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg, CWriteableSysSpecPosiLimitChg *pTargetSysSpecPosiLimitChg);
	
	///获取第一个CSysSpecPosiLimitChg
	///@return	得到的第一个CSysSpecPosiLimitChg，如果没有，则返回NULL
	CSysSpecPosiLimitChg *getFirst(void);
	
	///获取下一个CSysSpecPosiLimitChg
	///@return	得到下一个CSysSpecPosiLimitChg，如果没有，则返回NULL
	CSysSpecPosiLimitChg *getNext(void);
	
	///结束获取CSysSpecPosiLimitChg
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysSpecPosiLimitChgActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysSpecPosiLimitChgActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysSpecPosiLimitChgCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysSpecPosiLimitChgCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysSpecPosiLimitChgIteratorByActionTime;

	///开始寻找CSysSpecPosiLimitChg
	///@param	ActionTime	
	///@return	满足条件的地一个CSysSpecPosiLimitChg，如果找不到，返回NULL
	CSysSpecPosiLimitChg *startFindByActionTime( const CReadOnlyTimeType& ActionTime);

	///寻找下一个符合条件的CSysSpecPosiLimitChg，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysSpecPosiLimitChg，如果已经没有一个满足要求了，则返回NULL
	CSysSpecPosiLimitChg *findNextByActionTime(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByActionTime(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysSpecPosiLimitChg加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysSpecPosiLimitChg	要加入的SysSpecPosiLimitChg
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysSpecPosiLimitChg *internalAdd(CWriteableSysSpecPosiLimitChg *pSysSpecPosiLimitChg, bool bNoTransaction);
	
	
	///刷新该CSysSpecPosiLimitChg的键值
	///@param	pSysSpecPosiLimitChg	被刷新的CSysSpecPosiLimitChg
	///@param	pNewSysSpecPosiLimitChg	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg, CWriteableSysSpecPosiLimitChg *pNewSysSpecPosiLimitChg, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysSpecPosiLimitChg，同时删除其索引
	///@param	pSysSpecPosiLimitChg	要删除的CSysSpecPosiLimitChg
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg, bool bNoTransaction);
/*
	///检查某个CSysSpecPosiLimitChg是否属于本对象工厂
	///@param	pSysSpecPosiLimitChg	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ActionTime的索引
	CAVLTree *pSysActionTimeIndex;
	
	
	///按照ActionTime检索时，存储的查询参数
	CTimeType queryActionTimeInSearchByActionTime;
	
	///按照ActionTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByActionTime;
	
	///加入前触发
	///@param	pSysSpecPosiLimitChg	要加入的SysSpecPosiLimitChg
	virtual void beforeAdd(CWriteableSysSpecPosiLimitChg *pSysSpecPosiLimitChg);
	
	///加入后触发
	///@param	pSysSpecPosiLimitChg	已经加入的SysSpecPosiLimitChg
	virtual void afterAdd(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg);

	///更新前触发	
	///@param	pSysSpecPosiLimitChg	被刷新的CSysSpecPosiLimitChg
	///@param	pNewSysSpecPosiLimitChg	新的值
	virtual void beforeUpdate(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg, CWriteableSysSpecPosiLimitChg *pNewSysSpecPosiLimitChg);
	
	///更新后触发
	///@param	pSysSpecPosiLimitChg	被刷新的CSysSpecPosiLimitChg
	virtual void afterUpdate(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg);
	
	///删除前触发
	///@param	pSysSpecPosiLimitChg	要删除的CSysSpecPosiLimitChg
	virtual void beforeRemove(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg);
	
	///确认加入后触发
	///@param	pSysSpecPosiLimitChg	已经加入的SysSpecPosiLimitChg
	virtual void commitAdd(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg);

	///确认更新后触发
	///@param	pSysSpecPosiLimitChg	被刷新的CSysSpecPosiLimitChg
	///@param	poldSysSpecPosiLimitChg	原来的值
	virtual void commitUpdate(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg, CWriteableSysSpecPosiLimitChg *pOldSysSpecPosiLimitChg);
	
	///确认删除后触发
	///@param	pSysSpecPosiLimitChg	已经删除的CSysSpecPosiLimitChg
	virtual void commitRemove(CWriteableSysSpecPosiLimitChg *pSysSpecPosiLimitChg);

	///所有相关的触发器
	vector<CSysSpecPosiLimitChgActionTrigger *> *pActionTriggers;
	vector<CSysSpecPosiLimitChgCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysSpecPosiLimitChg compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysHedgeDetailChgFactory是一个保值额度变动查询的对象工厂。它包含了一批保值额度变动查询，
///同时又建立了如下索引，以方便查询：
///	SysActionTimeIndex
///使用本对象工厂，可以完成对保值额度变动查询的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByActionTime，findNextByActionTime和endFindByActionTime完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysHedgeDetailChgFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysHedgeDetailChgFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysHedgeDetailChg，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysHedgeDetailChgFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysHedgeDetailChgFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysHedgeDetailChg
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysHedgeDetailChg，文件名将根据配置文件中的定义SysHedgeDetailChgCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysHedgeDetailChg
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysHedgeDetailChg，文件名将根据配置文件中的定义SysHedgeDetailChgCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysHedgeDetailChgResource;

	///将一个CSysHedgeDetailChg加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysHedgeDetailChg	要加入的SysHedgeDetailChg
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysHedgeDetailChg *add(CWriteableSysHedgeDetailChg *pSysHedgeDetailChg, CTransaction *pTransaction=NULL);
	
	///刷新该CSysHedgeDetailChg的值
	///@param	pSysHedgeDetailChg	被刷新的CSysHedgeDetailChg
	///@param	pNewSysHedgeDetailChg	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysHedgeDetailChg *pSysHedgeDetailChg, CWriteableSysHedgeDetailChg *pNewSysHedgeDetailChg, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysHedgeDetailChg	  需要被刷新或者新增的CSysHedgeDetailChg,等于NULL表示是需要新增的
	///@param	pNewSysHedgeDetailChg	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysHedgeDetailChg* addOrUpdate(CSysHedgeDetailChg *pSysHedgeDetailChg, CWriteableSysHedgeDetailChg *pNewSysHedgeDetailChg, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysHedgeDetailChg，同时删除其索引
	///@param	pSysHedgeDetailChg	要删除的CSysHedgeDetailChg
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysHedgeDetailChg *pSysHedgeDetailChg, CTransaction *pTransaction=NULL);
	
	///获取某个CSysHedgeDetailChg
	///@param	pSysHedgeDetailChg	要读取的CSysHedgeDetailChg
	///@param	pTragetSysHedgeDetailChg	存放结果的CSysHedgeDetailChg
	void retrieve(CSysHedgeDetailChg *pSysHedgeDetailChg, CWriteableSysHedgeDetailChg *pTargetSysHedgeDetailChg);
	
	///获取第一个CSysHedgeDetailChg
	///@return	得到的第一个CSysHedgeDetailChg，如果没有，则返回NULL
	CSysHedgeDetailChg *getFirst(void);
	
	///获取下一个CSysHedgeDetailChg
	///@return	得到下一个CSysHedgeDetailChg，如果没有，则返回NULL
	CSysHedgeDetailChg *getNext(void);
	
	///结束获取CSysHedgeDetailChg
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysHedgeDetailChgActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysHedgeDetailChgActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysHedgeDetailChgCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysHedgeDetailChgCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysHedgeDetailChgIteratorByActionTime;

	///开始寻找CSysHedgeDetailChg
	///@param	ActionTime	
	///@return	满足条件的地一个CSysHedgeDetailChg，如果找不到，返回NULL
	CSysHedgeDetailChg *startFindByActionTime( const CReadOnlyTimeType& ActionTime);

	///寻找下一个符合条件的CSysHedgeDetailChg，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysHedgeDetailChg，如果已经没有一个满足要求了，则返回NULL
	CSysHedgeDetailChg *findNextByActionTime(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByActionTime(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysHedgeDetailChg加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysHedgeDetailChg	要加入的SysHedgeDetailChg
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysHedgeDetailChg *internalAdd(CWriteableSysHedgeDetailChg *pSysHedgeDetailChg, bool bNoTransaction);
	
	
	///刷新该CSysHedgeDetailChg的键值
	///@param	pSysHedgeDetailChg	被刷新的CSysHedgeDetailChg
	///@param	pNewSysHedgeDetailChg	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysHedgeDetailChg *pSysHedgeDetailChg, CWriteableSysHedgeDetailChg *pNewSysHedgeDetailChg, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysHedgeDetailChg，同时删除其索引
	///@param	pSysHedgeDetailChg	要删除的CSysHedgeDetailChg
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysHedgeDetailChg *pSysHedgeDetailChg, bool bNoTransaction);
/*
	///检查某个CSysHedgeDetailChg是否属于本对象工厂
	///@param	pSysHedgeDetailChg	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysHedgeDetailChg *pSysHedgeDetailChg);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ActionTime的索引
	CAVLTree *pSysActionTimeIndex;
	
	
	///按照ActionTime检索时，存储的查询参数
	CTimeType queryActionTimeInSearchByActionTime;
	
	///按照ActionTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByActionTime;
	
	///加入前触发
	///@param	pSysHedgeDetailChg	要加入的SysHedgeDetailChg
	virtual void beforeAdd(CWriteableSysHedgeDetailChg *pSysHedgeDetailChg);
	
	///加入后触发
	///@param	pSysHedgeDetailChg	已经加入的SysHedgeDetailChg
	virtual void afterAdd(CSysHedgeDetailChg *pSysHedgeDetailChg);

	///更新前触发	
	///@param	pSysHedgeDetailChg	被刷新的CSysHedgeDetailChg
	///@param	pNewSysHedgeDetailChg	新的值
	virtual void beforeUpdate(CSysHedgeDetailChg *pSysHedgeDetailChg, CWriteableSysHedgeDetailChg *pNewSysHedgeDetailChg);
	
	///更新后触发
	///@param	pSysHedgeDetailChg	被刷新的CSysHedgeDetailChg
	virtual void afterUpdate(CSysHedgeDetailChg *pSysHedgeDetailChg);
	
	///删除前触发
	///@param	pSysHedgeDetailChg	要删除的CSysHedgeDetailChg
	virtual void beforeRemove(CSysHedgeDetailChg *pSysHedgeDetailChg);
	
	///确认加入后触发
	///@param	pSysHedgeDetailChg	已经加入的SysHedgeDetailChg
	virtual void commitAdd(CSysHedgeDetailChg *pSysHedgeDetailChg);

	///确认更新后触发
	///@param	pSysHedgeDetailChg	被刷新的CSysHedgeDetailChg
	///@param	poldSysHedgeDetailChg	原来的值
	virtual void commitUpdate(CSysHedgeDetailChg *pSysHedgeDetailChg, CWriteableSysHedgeDetailChg *pOldSysHedgeDetailChg);
	
	///确认删除后触发
	///@param	pSysHedgeDetailChg	已经删除的CSysHedgeDetailChg
	virtual void commitRemove(CWriteableSysHedgeDetailChg *pSysHedgeDetailChg);

	///所有相关的触发器
	vector<CSysHedgeDetailChgActionTrigger *> *pActionTriggers;
	vector<CSysHedgeDetailChgCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysHedgeDetailChg compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantChgFactory是一个会员变动查询的对象工厂。它包含了一批会员变动查询，
///同时又建立了如下索引，以方便查询：
///	SysActionTimeIndex
///使用本对象工厂，可以完成对会员变动查询的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByActionTime，findNextByActionTime和endFindByActionTime完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantChgFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysParticipantChgFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysParticipantChg，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysParticipantChgFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysParticipantChgFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysParticipantChg
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysParticipantChg，文件名将根据配置文件中的定义SysParticipantChgCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysParticipantChg
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysParticipantChg，文件名将根据配置文件中的定义SysParticipantChgCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysParticipantChgResource;

	///将一个CSysParticipantChg加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysParticipantChg	要加入的SysParticipantChg
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysParticipantChg *add(CWriteableSysParticipantChg *pSysParticipantChg, CTransaction *pTransaction=NULL);
	
	///刷新该CSysParticipantChg的值
	///@param	pSysParticipantChg	被刷新的CSysParticipantChg
	///@param	pNewSysParticipantChg	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysParticipantChg *pSysParticipantChg, CWriteableSysParticipantChg *pNewSysParticipantChg, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysParticipantChg	  需要被刷新或者新增的CSysParticipantChg,等于NULL表示是需要新增的
	///@param	pNewSysParticipantChg	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysParticipantChg* addOrUpdate(CSysParticipantChg *pSysParticipantChg, CWriteableSysParticipantChg *pNewSysParticipantChg, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysParticipantChg，同时删除其索引
	///@param	pSysParticipantChg	要删除的CSysParticipantChg
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysParticipantChg *pSysParticipantChg, CTransaction *pTransaction=NULL);
	
	///获取某个CSysParticipantChg
	///@param	pSysParticipantChg	要读取的CSysParticipantChg
	///@param	pTragetSysParticipantChg	存放结果的CSysParticipantChg
	void retrieve(CSysParticipantChg *pSysParticipantChg, CWriteableSysParticipantChg *pTargetSysParticipantChg);
	
	///获取第一个CSysParticipantChg
	///@return	得到的第一个CSysParticipantChg，如果没有，则返回NULL
	CSysParticipantChg *getFirst(void);
	
	///获取下一个CSysParticipantChg
	///@return	得到下一个CSysParticipantChg，如果没有，则返回NULL
	CSysParticipantChg *getNext(void);
	
	///结束获取CSysParticipantChg
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysParticipantChgActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysParticipantChgActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysParticipantChgCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysParticipantChgCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysParticipantChgIteratorByActionTime;

	///开始寻找CSysParticipantChg
	///@param	ActionTime	
	///@return	满足条件的地一个CSysParticipantChg，如果找不到，返回NULL
	CSysParticipantChg *startFindByActionTime( const CReadOnlyTimeType& ActionTime);

	///寻找下一个符合条件的CSysParticipantChg，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysParticipantChg，如果已经没有一个满足要求了，则返回NULL
	CSysParticipantChg *findNextByActionTime(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByActionTime(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysParticipantChg加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysParticipantChg	要加入的SysParticipantChg
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysParticipantChg *internalAdd(CWriteableSysParticipantChg *pSysParticipantChg, bool bNoTransaction);
	
	
	///刷新该CSysParticipantChg的键值
	///@param	pSysParticipantChg	被刷新的CSysParticipantChg
	///@param	pNewSysParticipantChg	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysParticipantChg *pSysParticipantChg, CWriteableSysParticipantChg *pNewSysParticipantChg, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysParticipantChg，同时删除其索引
	///@param	pSysParticipantChg	要删除的CSysParticipantChg
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysParticipantChg *pSysParticipantChg, bool bNoTransaction);
/*
	///检查某个CSysParticipantChg是否属于本对象工厂
	///@param	pSysParticipantChg	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysParticipantChg *pSysParticipantChg);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ActionTime的索引
	CAVLTree *pSysActionTimeIndex;
	
	
	///按照ActionTime检索时，存储的查询参数
	CTimeType queryActionTimeInSearchByActionTime;
	
	///按照ActionTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByActionTime;
	
	///加入前触发
	///@param	pSysParticipantChg	要加入的SysParticipantChg
	virtual void beforeAdd(CWriteableSysParticipantChg *pSysParticipantChg);
	
	///加入后触发
	///@param	pSysParticipantChg	已经加入的SysParticipantChg
	virtual void afterAdd(CSysParticipantChg *pSysParticipantChg);

	///更新前触发	
	///@param	pSysParticipantChg	被刷新的CSysParticipantChg
	///@param	pNewSysParticipantChg	新的值
	virtual void beforeUpdate(CSysParticipantChg *pSysParticipantChg, CWriteableSysParticipantChg *pNewSysParticipantChg);
	
	///更新后触发
	///@param	pSysParticipantChg	被刷新的CSysParticipantChg
	virtual void afterUpdate(CSysParticipantChg *pSysParticipantChg);
	
	///删除前触发
	///@param	pSysParticipantChg	要删除的CSysParticipantChg
	virtual void beforeRemove(CSysParticipantChg *pSysParticipantChg);
	
	///确认加入后触发
	///@param	pSysParticipantChg	已经加入的SysParticipantChg
	virtual void commitAdd(CSysParticipantChg *pSysParticipantChg);

	///确认更新后触发
	///@param	pSysParticipantChg	被刷新的CSysParticipantChg
	///@param	poldSysParticipantChg	原来的值
	virtual void commitUpdate(CSysParticipantChg *pSysParticipantChg, CWriteableSysParticipantChg *pOldSysParticipantChg);
	
	///确认删除后触发
	///@param	pSysParticipantChg	已经删除的CSysParticipantChg
	virtual void commitRemove(CWriteableSysParticipantChg *pSysParticipantChg);

	///所有相关的触发器
	vector<CSysParticipantChgActionTrigger *> *pActionTriggers;
	vector<CSysParticipantChgCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysParticipantChg compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateChgFactory是一个保证金率变动查询的对象工厂。它包含了一批保证金率变动查询，
///同时又建立了如下索引，以方便查询：
///	SysActionTimeIndex
///使用本对象工厂，可以完成对保证金率变动查询的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByActionTime，findNextByActionTime和endFindByActionTime完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateChgFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMarginRateChgFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysMarginRateChg，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMarginRateChgFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysMarginRateChgFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysMarginRateChg
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysMarginRateChg，文件名将根据配置文件中的定义SysMarginRateChgCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysMarginRateChg
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysMarginRateChg，文件名将根据配置文件中的定义SysMarginRateChgCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysMarginRateChgResource;

	///将一个CSysMarginRateChg加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMarginRateChg	要加入的SysMarginRateChg
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMarginRateChg *add(CWriteableSysMarginRateChg *pSysMarginRateChg, CTransaction *pTransaction=NULL);
	
	///刷新该CSysMarginRateChg的值
	///@param	pSysMarginRateChg	被刷新的CSysMarginRateChg
	///@param	pNewSysMarginRateChg	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysMarginRateChg *pSysMarginRateChg, CWriteableSysMarginRateChg *pNewSysMarginRateChg, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysMarginRateChg	  需要被刷新或者新增的CSysMarginRateChg,等于NULL表示是需要新增的
	///@param	pNewSysMarginRateChg	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysMarginRateChg* addOrUpdate(CSysMarginRateChg *pSysMarginRateChg, CWriteableSysMarginRateChg *pNewSysMarginRateChg, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysMarginRateChg，同时删除其索引
	///@param	pSysMarginRateChg	要删除的CSysMarginRateChg
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysMarginRateChg *pSysMarginRateChg, CTransaction *pTransaction=NULL);
	
	///获取某个CSysMarginRateChg
	///@param	pSysMarginRateChg	要读取的CSysMarginRateChg
	///@param	pTragetSysMarginRateChg	存放结果的CSysMarginRateChg
	void retrieve(CSysMarginRateChg *pSysMarginRateChg, CWriteableSysMarginRateChg *pTargetSysMarginRateChg);
	
	///获取第一个CSysMarginRateChg
	///@return	得到的第一个CSysMarginRateChg，如果没有，则返回NULL
	CSysMarginRateChg *getFirst(void);
	
	///获取下一个CSysMarginRateChg
	///@return	得到下一个CSysMarginRateChg，如果没有，则返回NULL
	CSysMarginRateChg *getNext(void);
	
	///结束获取CSysMarginRateChg
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysMarginRateChgActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysMarginRateChgActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysMarginRateChgCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysMarginRateChgCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysMarginRateChgIteratorByActionTime;

	///开始寻找CSysMarginRateChg
	///@param	ActionTime	
	///@return	满足条件的地一个CSysMarginRateChg，如果找不到，返回NULL
	CSysMarginRateChg *startFindByActionTime( const CReadOnlyTimeType& ActionTime);

	///寻找下一个符合条件的CSysMarginRateChg，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysMarginRateChg，如果已经没有一个满足要求了，则返回NULL
	CSysMarginRateChg *findNextByActionTime(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByActionTime(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysMarginRateChg加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMarginRateChg	要加入的SysMarginRateChg
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMarginRateChg *internalAdd(CWriteableSysMarginRateChg *pSysMarginRateChg, bool bNoTransaction);
	
	
	///刷新该CSysMarginRateChg的键值
	///@param	pSysMarginRateChg	被刷新的CSysMarginRateChg
	///@param	pNewSysMarginRateChg	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysMarginRateChg *pSysMarginRateChg, CWriteableSysMarginRateChg *pNewSysMarginRateChg, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysMarginRateChg，同时删除其索引
	///@param	pSysMarginRateChg	要删除的CSysMarginRateChg
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysMarginRateChg *pSysMarginRateChg, bool bNoTransaction);
/*
	///检查某个CSysMarginRateChg是否属于本对象工厂
	///@param	pSysMarginRateChg	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysMarginRateChg *pSysMarginRateChg);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ActionTime的索引
	CAVLTree *pSysActionTimeIndex;
	
	
	///按照ActionTime检索时，存储的查询参数
	CTimeType queryActionTimeInSearchByActionTime;
	
	///按照ActionTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByActionTime;
	
	///加入前触发
	///@param	pSysMarginRateChg	要加入的SysMarginRateChg
	virtual void beforeAdd(CWriteableSysMarginRateChg *pSysMarginRateChg);
	
	///加入后触发
	///@param	pSysMarginRateChg	已经加入的SysMarginRateChg
	virtual void afterAdd(CSysMarginRateChg *pSysMarginRateChg);

	///更新前触发	
	///@param	pSysMarginRateChg	被刷新的CSysMarginRateChg
	///@param	pNewSysMarginRateChg	新的值
	virtual void beforeUpdate(CSysMarginRateChg *pSysMarginRateChg, CWriteableSysMarginRateChg *pNewSysMarginRateChg);
	
	///更新后触发
	///@param	pSysMarginRateChg	被刷新的CSysMarginRateChg
	virtual void afterUpdate(CSysMarginRateChg *pSysMarginRateChg);
	
	///删除前触发
	///@param	pSysMarginRateChg	要删除的CSysMarginRateChg
	virtual void beforeRemove(CSysMarginRateChg *pSysMarginRateChg);
	
	///确认加入后触发
	///@param	pSysMarginRateChg	已经加入的SysMarginRateChg
	virtual void commitAdd(CSysMarginRateChg *pSysMarginRateChg);

	///确认更新后触发
	///@param	pSysMarginRateChg	被刷新的CSysMarginRateChg
	///@param	poldSysMarginRateChg	原来的值
	virtual void commitUpdate(CSysMarginRateChg *pSysMarginRateChg, CWriteableSysMarginRateChg *pOldSysMarginRateChg);
	
	///确认删除后触发
	///@param	pSysMarginRateChg	已经删除的CSysMarginRateChg
	virtual void commitRemove(CWriteableSysMarginRateChg *pSysMarginRateChg);

	///所有相关的触发器
	vector<CSysMarginRateChgActionTrigger *> *pActionTriggers;
	vector<CSysMarginRateChgCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysMarginRateChg compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserIpChgFactory是一个IP地址变动查询的对象工厂。它包含了一批IP地址变动查询，
///同时又建立了如下索引，以方便查询：
///	SysActionTimeIndex
///使用本对象工厂，可以完成对IP地址变动查询的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByActionTime，findNextByActionTime和endFindByActionTime完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserIpChgFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysUserIpChgFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysUserIpChg，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysUserIpChgFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysUserIpChgFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysUserIpChg
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysUserIpChg，文件名将根据配置文件中的定义SysUserIpChgCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysUserIpChg
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysUserIpChg，文件名将根据配置文件中的定义SysUserIpChgCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysUserIpChgResource;

	///将一个CSysUserIpChg加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysUserIpChg	要加入的SysUserIpChg
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysUserIpChg *add(CWriteableSysUserIpChg *pSysUserIpChg, CTransaction *pTransaction=NULL);
	
	///刷新该CSysUserIpChg的值
	///@param	pSysUserIpChg	被刷新的CSysUserIpChg
	///@param	pNewSysUserIpChg	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysUserIpChg *pSysUserIpChg, CWriteableSysUserIpChg *pNewSysUserIpChg, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysUserIpChg	  需要被刷新或者新增的CSysUserIpChg,等于NULL表示是需要新增的
	///@param	pNewSysUserIpChg	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysUserIpChg* addOrUpdate(CSysUserIpChg *pSysUserIpChg, CWriteableSysUserIpChg *pNewSysUserIpChg, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysUserIpChg，同时删除其索引
	///@param	pSysUserIpChg	要删除的CSysUserIpChg
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysUserIpChg *pSysUserIpChg, CTransaction *pTransaction=NULL);
	
	///获取某个CSysUserIpChg
	///@param	pSysUserIpChg	要读取的CSysUserIpChg
	///@param	pTragetSysUserIpChg	存放结果的CSysUserIpChg
	void retrieve(CSysUserIpChg *pSysUserIpChg, CWriteableSysUserIpChg *pTargetSysUserIpChg);
	
	///获取第一个CSysUserIpChg
	///@return	得到的第一个CSysUserIpChg，如果没有，则返回NULL
	CSysUserIpChg *getFirst(void);
	
	///获取下一个CSysUserIpChg
	///@return	得到下一个CSysUserIpChg，如果没有，则返回NULL
	CSysUserIpChg *getNext(void);
	
	///结束获取CSysUserIpChg
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysUserIpChgActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysUserIpChgActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysUserIpChgCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysUserIpChgCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysUserIpChgIteratorByActionTime;

	///开始寻找CSysUserIpChg
	///@param	ActionTime	
	///@return	满足条件的地一个CSysUserIpChg，如果找不到，返回NULL
	CSysUserIpChg *startFindByActionTime( const CReadOnlyTimeType& ActionTime);

	///寻找下一个符合条件的CSysUserIpChg，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysUserIpChg，如果已经没有一个满足要求了，则返回NULL
	CSysUserIpChg *findNextByActionTime(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByActionTime(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysUserIpChg加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysUserIpChg	要加入的SysUserIpChg
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysUserIpChg *internalAdd(CWriteableSysUserIpChg *pSysUserIpChg, bool bNoTransaction);
	
	
	///刷新该CSysUserIpChg的键值
	///@param	pSysUserIpChg	被刷新的CSysUserIpChg
	///@param	pNewSysUserIpChg	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysUserIpChg *pSysUserIpChg, CWriteableSysUserIpChg *pNewSysUserIpChg, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysUserIpChg，同时删除其索引
	///@param	pSysUserIpChg	要删除的CSysUserIpChg
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysUserIpChg *pSysUserIpChg, bool bNoTransaction);
/*
	///检查某个CSysUserIpChg是否属于本对象工厂
	///@param	pSysUserIpChg	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysUserIpChg *pSysUserIpChg);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ActionTime的索引
	CAVLTree *pSysActionTimeIndex;
	
	
	///按照ActionTime检索时，存储的查询参数
	CTimeType queryActionTimeInSearchByActionTime;
	
	///按照ActionTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByActionTime;
	
	///加入前触发
	///@param	pSysUserIpChg	要加入的SysUserIpChg
	virtual void beforeAdd(CWriteableSysUserIpChg *pSysUserIpChg);
	
	///加入后触发
	///@param	pSysUserIpChg	已经加入的SysUserIpChg
	virtual void afterAdd(CSysUserIpChg *pSysUserIpChg);

	///更新前触发	
	///@param	pSysUserIpChg	被刷新的CSysUserIpChg
	///@param	pNewSysUserIpChg	新的值
	virtual void beforeUpdate(CSysUserIpChg *pSysUserIpChg, CWriteableSysUserIpChg *pNewSysUserIpChg);
	
	///更新后触发
	///@param	pSysUserIpChg	被刷新的CSysUserIpChg
	virtual void afterUpdate(CSysUserIpChg *pSysUserIpChg);
	
	///删除前触发
	///@param	pSysUserIpChg	要删除的CSysUserIpChg
	virtual void beforeRemove(CSysUserIpChg *pSysUserIpChg);
	
	///确认加入后触发
	///@param	pSysUserIpChg	已经加入的SysUserIpChg
	virtual void commitAdd(CSysUserIpChg *pSysUserIpChg);

	///确认更新后触发
	///@param	pSysUserIpChg	被刷新的CSysUserIpChg
	///@param	poldSysUserIpChg	原来的值
	virtual void commitUpdate(CSysUserIpChg *pSysUserIpChg, CWriteableSysUserIpChg *pOldSysUserIpChg);
	
	///确认删除后触发
	///@param	pSysUserIpChg	已经删除的CSysUserIpChg
	virtual void commitRemove(CWriteableSysUserIpChg *pSysUserIpChg);

	///所有相关的触发器
	vector<CSysUserIpChgActionTrigger *> *pActionTriggers;
	vector<CSysUserIpChgCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysUserIpChg compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartTradeFactory是一个会员交易信息的对象工厂。它包含了一批会员交易信息，
///同时又建立了如下索引，以方便查询：
///	SysPartInstrumentIndex
///使用本对象工厂，可以完成对会员交易信息的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartTradeFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysPartTradeFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysPartTrade，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysPartTradeFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysPartTradeFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysPartTrade
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysPartTrade，文件名将根据配置文件中的定义SysPartTradeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysPartTrade
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysPartTrade，文件名将根据配置文件中的定义SysPartTradeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysPartTradeResource;

	///将一个CSysPartTrade加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysPartTrade	要加入的SysPartTrade
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysPartTrade *add(CWriteableSysPartTrade *pSysPartTrade, CTransaction *pTransaction=NULL);
	
	///刷新该CSysPartTrade的值
	///@param	pSysPartTrade	被刷新的CSysPartTrade
	///@param	pNewSysPartTrade	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysPartTrade *pSysPartTrade, CWriteableSysPartTrade *pNewSysPartTrade, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysPartTrade	  需要被刷新或者新增的CSysPartTrade,等于NULL表示是需要新增的
	///@param	pNewSysPartTrade	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysPartTrade* addOrUpdate(CSysPartTrade *pSysPartTrade, CWriteableSysPartTrade *pNewSysPartTrade, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysPartTrade，同时删除其索引
	///@param	pSysPartTrade	要删除的CSysPartTrade
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysPartTrade *pSysPartTrade, CTransaction *pTransaction=NULL);
	
	///获取某个CSysPartTrade
	///@param	pSysPartTrade	要读取的CSysPartTrade
	///@param	pTragetSysPartTrade	存放结果的CSysPartTrade
	void retrieve(CSysPartTrade *pSysPartTrade, CWriteableSysPartTrade *pTargetSysPartTrade);
	
	///获取第一个CSysPartTrade
	///@return	得到的第一个CSysPartTrade，如果没有，则返回NULL
	CSysPartTrade *getFirst(void);
	
	///获取下一个CSysPartTrade
	///@return	得到下一个CSysPartTrade，如果没有，则返回NULL
	CSysPartTrade *getNext(void);
	
	///结束获取CSysPartTrade
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysPartTradeActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysPartTradeActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysPartTradeCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysPartTradeCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysPartTradeIteratorByAll;

	///开始寻找CSysPartTrade
	///@return	满足条件的地一个CSysPartTrade，如果找不到，返回NULL
	CSysPartTrade *startFindByAll();

	///寻找下一个符合条件的CSysPartTrade，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysPartTrade，如果已经没有一个满足要求了，则返回NULL
	CSysPartTrade *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysPartTrade
	///@param	ParticipantID	
	///@param	InstrumentID	
	///@return	找到的CSysPartTrade，如果找不到，返回NULL
	CSysPartTrade *findByOne( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyInstrumentIDType&  InstrumentID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysPartTrade加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysPartTrade	要加入的SysPartTrade
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysPartTrade *internalAdd(CWriteableSysPartTrade *pSysPartTrade, bool bNoTransaction);
	
	
	///刷新该CSysPartTrade的键值
	///@param	pSysPartTrade	被刷新的CSysPartTrade
	///@param	pNewSysPartTrade	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysPartTrade *pSysPartTrade, CWriteableSysPartTrade *pNewSysPartTrade, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysPartTrade，同时删除其索引
	///@param	pSysPartTrade	要删除的CSysPartTrade
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysPartTrade *pSysPartTrade, bool bNoTransaction);
/*
	///检查某个CSysPartTrade是否属于本对象工厂
	///@param	pSysPartTrade	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysPartTrade *pSysPartTrade);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ParticipantID+InstrumentID的索引
	CAVLTree *pSysPartInstrumentIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysPartTrade	要加入的SysPartTrade
	virtual void beforeAdd(CWriteableSysPartTrade *pSysPartTrade);
	
	///加入后触发
	///@param	pSysPartTrade	已经加入的SysPartTrade
	virtual void afterAdd(CSysPartTrade *pSysPartTrade);

	///更新前触发	
	///@param	pSysPartTrade	被刷新的CSysPartTrade
	///@param	pNewSysPartTrade	新的值
	virtual void beforeUpdate(CSysPartTrade *pSysPartTrade, CWriteableSysPartTrade *pNewSysPartTrade);
	
	///更新后触发
	///@param	pSysPartTrade	被刷新的CSysPartTrade
	virtual void afterUpdate(CSysPartTrade *pSysPartTrade);
	
	///删除前触发
	///@param	pSysPartTrade	要删除的CSysPartTrade
	virtual void beforeRemove(CSysPartTrade *pSysPartTrade);
	
	///确认加入后触发
	///@param	pSysPartTrade	已经加入的SysPartTrade
	virtual void commitAdd(CSysPartTrade *pSysPartTrade);

	///确认更新后触发
	///@param	pSysPartTrade	被刷新的CSysPartTrade
	///@param	poldSysPartTrade	原来的值
	virtual void commitUpdate(CSysPartTrade *pSysPartTrade, CWriteableSysPartTrade *pOldSysPartTrade);
	
	///确认删除后触发
	///@param	pSysPartTrade	已经删除的CSysPartTrade
	virtual void commitRemove(CWriteableSysPartTrade *pSysPartTrade);

	///所有相关的触发器
	vector<CSysPartTradeActionTrigger *> *pActionTriggers;
	vector<CSysPartTradeCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysPartTrade compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrFactory是一个对象状态指标的对象工厂。它包含了一批对象状态指标，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对对象状态指标的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByIDType，findNextByIDType和endFindByIDType完成查询操作
///		使用startFindByDsc，findNextByDsc和endFindByDsc完成查询操作
///		使用findByOne，唯一找到对象
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///		使用startFindByDataDelete，findNextByDataDelete和endFindByDataDelete完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbObjectAttrFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysMdbObjectAttr，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbObjectAttrFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbObjectAttrFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysMdbObjectAttr
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysMdbObjectAttr，文件名将根据配置文件中的定义SysMdbObjectAttrCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysMdbObjectAttr
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysMdbObjectAttr，文件名将根据配置文件中的定义SysMdbObjectAttrCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysMdbObjectAttrResource;

	///将一个CSysMdbObjectAttr加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbObjectAttr	要加入的SysMdbObjectAttr
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbObjectAttr *add(CWriteableSysMdbObjectAttr *pSysMdbObjectAttr, CTransaction *pTransaction=NULL);
	
	///刷新该CSysMdbObjectAttr的值
	///@param	pSysMdbObjectAttr	被刷新的CSysMdbObjectAttr
	///@param	pNewSysMdbObjectAttr	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysMdbObjectAttr *pSysMdbObjectAttr, CWriteableSysMdbObjectAttr *pNewSysMdbObjectAttr, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysMdbObjectAttr	  需要被刷新或者新增的CSysMdbObjectAttr,等于NULL表示是需要新增的
	///@param	pNewSysMdbObjectAttr	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysMdbObjectAttr* addOrUpdate(CSysMdbObjectAttr *pSysMdbObjectAttr, CWriteableSysMdbObjectAttr *pNewSysMdbObjectAttr, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysMdbObjectAttr，同时删除其索引
	///@param	pSysMdbObjectAttr	要删除的CSysMdbObjectAttr
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysMdbObjectAttr *pSysMdbObjectAttr, CTransaction *pTransaction=NULL);
	
	///获取某个CSysMdbObjectAttr
	///@param	pSysMdbObjectAttr	要读取的CSysMdbObjectAttr
	///@param	pTragetSysMdbObjectAttr	存放结果的CSysMdbObjectAttr
	void retrieve(CSysMdbObjectAttr *pSysMdbObjectAttr, CWriteableSysMdbObjectAttr *pTargetSysMdbObjectAttr);
	
	///获取第一个CSysMdbObjectAttr
	///@return	得到的第一个CSysMdbObjectAttr，如果没有，则返回NULL
	CSysMdbObjectAttr *getFirst(void);
	
	///获取下一个CSysMdbObjectAttr
	///@return	得到下一个CSysMdbObjectAttr，如果没有，则返回NULL
	CSysMdbObjectAttr *getNext(void);
	
	///结束获取CSysMdbObjectAttr
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysMdbObjectAttrActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysMdbObjectAttrActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysMdbObjectAttrCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysMdbObjectAttrCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysMdbObjectAttrIteratorByIDType;

	///开始寻找CSysMdbObjectAttr
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	///@return	满足条件的地一个CSysMdbObjectAttr，如果找不到，返回NULL
	CSysMdbObjectAttr *startFindByIDType( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysMdbObjectAttr，必须在startFindByIDType以后，endFindByIDType之前叫用
	///@return	下一个满足条件CSysMdbObjectAttr，如果已经没有一个满足要求了，则返回NULL
	CSysMdbObjectAttr *findNextByIDType(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByIDType(void);

	friend class CSysMdbObjectAttrIteratorByDsc;

	///开始寻找CSysMdbObjectAttr
	///@param	SubcriberID	
	///@return	满足条件的地一个CSysMdbObjectAttr，如果找不到，返回NULL
	CSysMdbObjectAttr *startFindByDsc( const CReadOnlyVolumeType& SubcriberID);

	///寻找下一个符合条件的CSysMdbObjectAttr，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbObjectAttr，如果已经没有一个满足要求了，则返回NULL
	CSysMdbObjectAttr *findNextByDsc(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDsc(void);

	///寻找CSysMdbObjectAttr
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	///@return	找到的CSysMdbObjectAttr，如果找不到，返回NULL
	CSysMdbObjectAttr *findByOne( const CReadOnlyVolumeType&  SubcriberID,  const CReadOnlyDateType&  MonDate,  const CReadOnlyTimeType&  MonTime);



	friend class CSysMdbObjectAttrIteratorBytheAll;

	///开始寻找CSysMdbObjectAttr
	///@return	满足条件的地一个CSysMdbObjectAttr，如果找不到，返回NULL
	CSysMdbObjectAttr *startFindBytheAll();

	///寻找下一个符合条件的CSysMdbObjectAttr，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbObjectAttr，如果已经没有一个满足要求了，则返回NULL
	CSysMdbObjectAttr *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

	friend class CSysMdbObjectAttrIteratorByDataDelete;

	///开始寻找CSysMdbObjectAttr
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	///@return	满足条件的地一个CSysMdbObjectAttr，如果找不到，返回NULL
	CSysMdbObjectAttr *startFindByDataDelete( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysMdbObjectAttr，必须在startFindByDataDelete以后，endFindByDataDelete之前叫用
	///@return	下一个满足条件CSysMdbObjectAttr，如果已经没有一个满足要求了，则返回NULL
	CSysMdbObjectAttr *findNextByDataDelete(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDataDelete(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysMdbObjectAttr加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbObjectAttr	要加入的SysMdbObjectAttr
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbObjectAttr *internalAdd(CWriteableSysMdbObjectAttr *pSysMdbObjectAttr, bool bNoTransaction);
	
	
	///刷新该CSysMdbObjectAttr的键值
	///@param	pSysMdbObjectAttr	被刷新的CSysMdbObjectAttr
	///@param	pNewSysMdbObjectAttr	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysMdbObjectAttr *pSysMdbObjectAttr, CWriteableSysMdbObjectAttr *pNewSysMdbObjectAttr, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysMdbObjectAttr，同时删除其索引
	///@param	pSysMdbObjectAttr	要删除的CSysMdbObjectAttr
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysMdbObjectAttr *pSysMdbObjectAttr, bool bNoTransaction);
/*
	///检查某个CSysMdbObjectAttr是否属于本对象工厂
	///@param	pSysMdbObjectAttr	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysMdbObjectAttr *pSysMdbObjectAttr);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于SubcriberID+MonDate+MonTime的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照SubcriberID，MonDate，MonTime检索时，存储的查询参数
	CVolumeType querySubcriberIDInSearchByIDType;
	CDateType queryMonDateInSearchByIDType;
	CTimeType queryMonTimeInSearchByIDType;
	
	///按照SubcriberID，MonDate，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByIDType;
	///按照SubcriberID检索时，存储的查询参数
	CVolumeType querySubcriberIDInSearchByDsc;
	
	///按照SubcriberID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDsc;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	///按照SubcriberID，MonDate，MonTime检索时，存储的查询参数
	CVolumeType querySubcriberIDInSearchByDataDelete;
	CDateType queryMonDateInSearchByDataDelete;
	CTimeType queryMonTimeInSearchByDataDelete;
	
	///按照SubcriberID，MonDate，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDataDelete;
	
	///加入前触发
	///@param	pSysMdbObjectAttr	要加入的SysMdbObjectAttr
	virtual void beforeAdd(CWriteableSysMdbObjectAttr *pSysMdbObjectAttr);
	
	///加入后触发
	///@param	pSysMdbObjectAttr	已经加入的SysMdbObjectAttr
	virtual void afterAdd(CSysMdbObjectAttr *pSysMdbObjectAttr);

	///更新前触发	
	///@param	pSysMdbObjectAttr	被刷新的CSysMdbObjectAttr
	///@param	pNewSysMdbObjectAttr	新的值
	virtual void beforeUpdate(CSysMdbObjectAttr *pSysMdbObjectAttr, CWriteableSysMdbObjectAttr *pNewSysMdbObjectAttr);
	
	///更新后触发
	///@param	pSysMdbObjectAttr	被刷新的CSysMdbObjectAttr
	virtual void afterUpdate(CSysMdbObjectAttr *pSysMdbObjectAttr);
	
	///删除前触发
	///@param	pSysMdbObjectAttr	要删除的CSysMdbObjectAttr
	virtual void beforeRemove(CSysMdbObjectAttr *pSysMdbObjectAttr);
	
	///确认加入后触发
	///@param	pSysMdbObjectAttr	已经加入的SysMdbObjectAttr
	virtual void commitAdd(CSysMdbObjectAttr *pSysMdbObjectAttr);

	///确认更新后触发
	///@param	pSysMdbObjectAttr	被刷新的CSysMdbObjectAttr
	///@param	poldSysMdbObjectAttr	原来的值
	virtual void commitUpdate(CSysMdbObjectAttr *pSysMdbObjectAttr, CWriteableSysMdbObjectAttr *pOldSysMdbObjectAttr);
	
	///确认删除后触发
	///@param	pSysMdbObjectAttr	已经删除的CSysMdbObjectAttr
	virtual void commitRemove(CWriteableSysMdbObjectAttr *pSysMdbObjectAttr);

	///所有相关的触发器
	vector<CSysMdbObjectAttrActionTrigger *> *pActionTriggers;
	vector<CSysMdbObjectAttrCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysMdbObjectAttr compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoFactory是一个日志文件内容传输信息的对象工厂。它包含了一批日志文件内容传输信息，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///	DecIndex
///使用本对象工厂，可以完成对日志文件内容传输信息的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///		使用startFindByDataDelete，findNextByDataDelete和endFindByDataDelete完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbSyslogInfoFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysMdbSyslogInfo，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbSyslogInfoFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbSyslogInfoFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysMdbSyslogInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysMdbSyslogInfo，文件名将根据配置文件中的定义SysMdbSyslogInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysMdbSyslogInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysMdbSyslogInfo，文件名将根据配置文件中的定义SysMdbSyslogInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysMdbSyslogInfoResource;

	///将一个CSysMdbSyslogInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbSyslogInfo	要加入的SysMdbSyslogInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbSyslogInfo *add(CWriteableSysMdbSyslogInfo *pSysMdbSyslogInfo, CTransaction *pTransaction=NULL);
	
	///刷新该CSysMdbSyslogInfo的值
	///@param	pSysMdbSyslogInfo	被刷新的CSysMdbSyslogInfo
	///@param	pNewSysMdbSyslogInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysMdbSyslogInfo *pSysMdbSyslogInfo, CWriteableSysMdbSyslogInfo *pNewSysMdbSyslogInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysMdbSyslogInfo	  需要被刷新或者新增的CSysMdbSyslogInfo,等于NULL表示是需要新增的
	///@param	pNewSysMdbSyslogInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysMdbSyslogInfo* addOrUpdate(CSysMdbSyslogInfo *pSysMdbSyslogInfo, CWriteableSysMdbSyslogInfo *pNewSysMdbSyslogInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysMdbSyslogInfo，同时删除其索引
	///@param	pSysMdbSyslogInfo	要删除的CSysMdbSyslogInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysMdbSyslogInfo *pSysMdbSyslogInfo, CTransaction *pTransaction=NULL);
	
	///获取某个CSysMdbSyslogInfo
	///@param	pSysMdbSyslogInfo	要读取的CSysMdbSyslogInfo
	///@param	pTragetSysMdbSyslogInfo	存放结果的CSysMdbSyslogInfo
	void retrieve(CSysMdbSyslogInfo *pSysMdbSyslogInfo, CWriteableSysMdbSyslogInfo *pTargetSysMdbSyslogInfo);
	
	///获取第一个CSysMdbSyslogInfo
	///@return	得到的第一个CSysMdbSyslogInfo，如果没有，则返回NULL
	CSysMdbSyslogInfo *getFirst(void);
	
	///获取下一个CSysMdbSyslogInfo
	///@return	得到下一个CSysMdbSyslogInfo，如果没有，则返回NULL
	CSysMdbSyslogInfo *getNext(void);
	
	///结束获取CSysMdbSyslogInfo
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysMdbSyslogInfoActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysMdbSyslogInfoActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysMdbSyslogInfoCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysMdbSyslogInfoCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysMdbSyslogInfoIteratorByAll;

	///开始寻找CSysMdbSyslogInfo
	///@param	ObjectID	
	///@param	AttrType	
	///@return	满足条件的地一个CSysMdbSyslogInfo，如果找不到，返回NULL
	CSysMdbSyslogInfo *startFindByAll( const CReadOnlyVolumeType& ObjectID,  const CReadOnlyVolumeType& AttrType);

	///寻找下一个符合条件的CSysMdbSyslogInfo，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysMdbSyslogInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbSyslogInfo *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	friend class CSysMdbSyslogInfoIteratorBytheAll;

	///开始寻找CSysMdbSyslogInfo
	///@return	满足条件的地一个CSysMdbSyslogInfo，如果找不到，返回NULL
	CSysMdbSyslogInfo *startFindBytheAll();

	///寻找下一个符合条件的CSysMdbSyslogInfo，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbSyslogInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbSyslogInfo *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

	friend class CSysMdbSyslogInfoIteratorByDataDelete;

	///开始寻找CSysMdbSyslogInfo
	///@param	ObjectID	
	///@param	AttrType	
	///@param	MonDate	
	///@param	MonTime	
	///@return	满足条件的地一个CSysMdbSyslogInfo，如果找不到，返回NULL
	CSysMdbSyslogInfo *startFindByDataDelete( const CReadOnlyVolumeType& ObjectID,  const CReadOnlyVolumeType& AttrType,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysMdbSyslogInfo，必须在startFindByDataDelete以后，endFindByDataDelete之前叫用
	///@return	下一个满足条件CSysMdbSyslogInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbSyslogInfo *findNextByDataDelete(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDataDelete(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysMdbSyslogInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbSyslogInfo	要加入的SysMdbSyslogInfo
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbSyslogInfo *internalAdd(CWriteableSysMdbSyslogInfo *pSysMdbSyslogInfo, bool bNoTransaction);
	
	
	///刷新该CSysMdbSyslogInfo的键值
	///@param	pSysMdbSyslogInfo	被刷新的CSysMdbSyslogInfo
	///@param	pNewSysMdbSyslogInfo	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysMdbSyslogInfo *pSysMdbSyslogInfo, CWriteableSysMdbSyslogInfo *pNewSysMdbSyslogInfo, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysMdbSyslogInfo，同时删除其索引
	///@param	pSysMdbSyslogInfo	要删除的CSysMdbSyslogInfo
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysMdbSyslogInfo *pSysMdbSyslogInfo, bool bNoTransaction);
/*
	///检查某个CSysMdbSyslogInfo是否属于本对象工厂
	///@param	pSysMdbSyslogInfo	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysMdbSyslogInfo *pSysMdbSyslogInfo);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ObjectID+AttrType的索引
	CAVLTree *pSysIDTypeIndex;
	///基于ObjectID+AttrType+MonDate+MonTime的索引
	CAVLTree *pDecIndex;
	
	
	///按照ObjectID，AttrType检索时，存储的查询参数
	CVolumeType queryObjectIDInSearchByAll;
	CVolumeType queryAttrTypeInSearchByAll;
	
	///按照ObjectID，AttrType检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	///按照ObjectID，AttrType，MonDate，MonTime检索时，存储的查询参数
	CVolumeType queryObjectIDInSearchByDataDelete;
	CVolumeType queryAttrTypeInSearchByDataDelete;
	CDateType queryMonDateInSearchByDataDelete;
	CTimeType queryMonTimeInSearchByDataDelete;
	
	///按照ObjectID，AttrType，MonDate，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDataDelete;
	
	///加入前触发
	///@param	pSysMdbSyslogInfo	要加入的SysMdbSyslogInfo
	virtual void beforeAdd(CWriteableSysMdbSyslogInfo *pSysMdbSyslogInfo);
	
	///加入后触发
	///@param	pSysMdbSyslogInfo	已经加入的SysMdbSyslogInfo
	virtual void afterAdd(CSysMdbSyslogInfo *pSysMdbSyslogInfo);

	///更新前触发	
	///@param	pSysMdbSyslogInfo	被刷新的CSysMdbSyslogInfo
	///@param	pNewSysMdbSyslogInfo	新的值
	virtual void beforeUpdate(CSysMdbSyslogInfo *pSysMdbSyslogInfo, CWriteableSysMdbSyslogInfo *pNewSysMdbSyslogInfo);
	
	///更新后触发
	///@param	pSysMdbSyslogInfo	被刷新的CSysMdbSyslogInfo
	virtual void afterUpdate(CSysMdbSyslogInfo *pSysMdbSyslogInfo);
	
	///删除前触发
	///@param	pSysMdbSyslogInfo	要删除的CSysMdbSyslogInfo
	virtual void beforeRemove(CSysMdbSyslogInfo *pSysMdbSyslogInfo);
	
	///确认加入后触发
	///@param	pSysMdbSyslogInfo	已经加入的SysMdbSyslogInfo
	virtual void commitAdd(CSysMdbSyslogInfo *pSysMdbSyslogInfo);

	///确认更新后触发
	///@param	pSysMdbSyslogInfo	被刷新的CSysMdbSyslogInfo
	///@param	poldSysMdbSyslogInfo	原来的值
	virtual void commitUpdate(CSysMdbSyslogInfo *pSysMdbSyslogInfo, CWriteableSysMdbSyslogInfo *pOldSysMdbSyslogInfo);
	
	///确认删除后触发
	///@param	pSysMdbSyslogInfo	已经删除的CSysMdbSyslogInfo
	virtual void commitRemove(CWriteableSysMdbSyslogInfo *pSysMdbSyslogInfo);

	///所有相关的触发器
	vector<CSysMdbSyslogInfoActionTrigger *> *pActionTriggers;
	vector<CSysMdbSyslogInfoCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysMdbSyslogInfo compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInfoFactory是一个用户信息的对象工厂。它包含了一批用户信息，
///同时又建立了如下索引，以方便查询：
///	SysHostNameIndex
///	DecIndex
///使用本对象工厂，可以完成对用户信息的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByHostName，findNextByHostName和endFindByHostName完成查询操作
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///		使用startFindByDsc，findNextByDsc和endFindByDsc完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysUserInfoFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysUserInfo，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysUserInfoFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysUserInfoFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysUserInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysUserInfo，文件名将根据配置文件中的定义SysUserInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysUserInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysUserInfo，文件名将根据配置文件中的定义SysUserInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysUserInfoResource;

	///将一个CSysUserInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysUserInfo	要加入的SysUserInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysUserInfo *add(CWriteableSysUserInfo *pSysUserInfo, CTransaction *pTransaction=NULL);
	
	///刷新该CSysUserInfo的值
	///@param	pSysUserInfo	被刷新的CSysUserInfo
	///@param	pNewSysUserInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysUserInfo *pSysUserInfo, CWriteableSysUserInfo *pNewSysUserInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysUserInfo	  需要被刷新或者新增的CSysUserInfo,等于NULL表示是需要新增的
	///@param	pNewSysUserInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysUserInfo* addOrUpdate(CSysUserInfo *pSysUserInfo, CWriteableSysUserInfo *pNewSysUserInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysUserInfo，同时删除其索引
	///@param	pSysUserInfo	要删除的CSysUserInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysUserInfo *pSysUserInfo, CTransaction *pTransaction=NULL);
	
	///获取某个CSysUserInfo
	///@param	pSysUserInfo	要读取的CSysUserInfo
	///@param	pTragetSysUserInfo	存放结果的CSysUserInfo
	void retrieve(CSysUserInfo *pSysUserInfo, CWriteableSysUserInfo *pTargetSysUserInfo);
	
	///获取第一个CSysUserInfo
	///@return	得到的第一个CSysUserInfo，如果没有，则返回NULL
	CSysUserInfo *getFirst(void);
	
	///获取下一个CSysUserInfo
	///@return	得到下一个CSysUserInfo，如果没有，则返回NULL
	CSysUserInfo *getNext(void);
	
	///结束获取CSysUserInfo
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysUserInfoActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysUserInfoActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysUserInfoCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysUserInfoCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysUserInfoIteratorByHostName;

	///开始寻找CSysUserInfo
	///@param	ObjectID	
	///@param	MonTime	
	///@return	满足条件的地一个CSysUserInfo，如果找不到，返回NULL
	CSysUserInfo *startFindByHostName( const CReadOnlyTypeObjectIDType& ObjectID,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysUserInfo，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CSysUserInfo，如果已经没有一个满足要求了，则返回NULL
	CSysUserInfo *findNextByHostName(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByHostName(void);

	friend class CSysUserInfoIteratorBytheAll;

	///开始寻找CSysUserInfo
	///@return	满足条件的地一个CSysUserInfo，如果找不到，返回NULL
	CSysUserInfo *startFindBytheAll();

	///寻找下一个符合条件的CSysUserInfo，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysUserInfo，如果已经没有一个满足要求了，则返回NULL
	CSysUserInfo *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

	friend class CSysUserInfoIteratorByDsc;

	///开始寻找CSysUserInfo
	///@param	ObjectID	
	///@return	满足条件的地一个CSysUserInfo，如果找不到，返回NULL
	CSysUserInfo *startFindByDsc( const CReadOnlyTypeObjectIDType& ObjectID);

	///寻找下一个符合条件的CSysUserInfo，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysUserInfo，如果已经没有一个满足要求了，则返回NULL
	CSysUserInfo *findNextByDsc(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDsc(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysUserInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysUserInfo	要加入的SysUserInfo
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysUserInfo *internalAdd(CWriteableSysUserInfo *pSysUserInfo, bool bNoTransaction);
	
	
	///刷新该CSysUserInfo的键值
	///@param	pSysUserInfo	被刷新的CSysUserInfo
	///@param	pNewSysUserInfo	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysUserInfo *pSysUserInfo, CWriteableSysUserInfo *pNewSysUserInfo, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysUserInfo，同时删除其索引
	///@param	pSysUserInfo	要删除的CSysUserInfo
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysUserInfo *pSysUserInfo, bool bNoTransaction);
/*
	///检查某个CSysUserInfo是否属于本对象工厂
	///@param	pSysUserInfo	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysUserInfo *pSysUserInfo);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ObjectID+MonTime的索引
	CAVLTree *pSysHostNameIndex;
	///基于ObjectID+MonDate+MonTime的索引
	CAVLTree *pDecIndex;
	
	
	///按照ObjectID，MonTime检索时，存储的查询参数
	CTypeObjectIDType queryObjectIDInSearchByHostName;
	CTimeType queryMonTimeInSearchByHostName;
	
	///按照ObjectID，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByHostName;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	///按照ObjectID检索时，存储的查询参数
	CTypeObjectIDType queryObjectIDInSearchByDsc;
	
	///按照ObjectID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDsc;
	
	///加入前触发
	///@param	pSysUserInfo	要加入的SysUserInfo
	virtual void beforeAdd(CWriteableSysUserInfo *pSysUserInfo);
	
	///加入后触发
	///@param	pSysUserInfo	已经加入的SysUserInfo
	virtual void afterAdd(CSysUserInfo *pSysUserInfo);

	///更新前触发	
	///@param	pSysUserInfo	被刷新的CSysUserInfo
	///@param	pNewSysUserInfo	新的值
	virtual void beforeUpdate(CSysUserInfo *pSysUserInfo, CWriteableSysUserInfo *pNewSysUserInfo);
	
	///更新后触发
	///@param	pSysUserInfo	被刷新的CSysUserInfo
	virtual void afterUpdate(CSysUserInfo *pSysUserInfo);
	
	///删除前触发
	///@param	pSysUserInfo	要删除的CSysUserInfo
	virtual void beforeRemove(CSysUserInfo *pSysUserInfo);
	
	///确认加入后触发
	///@param	pSysUserInfo	已经加入的SysUserInfo
	virtual void commitAdd(CSysUserInfo *pSysUserInfo);

	///确认更新后触发
	///@param	pSysUserInfo	被刷新的CSysUserInfo
	///@param	poldSysUserInfo	原来的值
	virtual void commitUpdate(CSysUserInfo *pSysUserInfo, CWriteableSysUserInfo *pOldSysUserInfo);
	
	///确认删除后触发
	///@param	pSysUserInfo	已经删除的CSysUserInfo
	virtual void commitRemove(CWriteableSysUserInfo *pSysUserInfo);

	///所有相关的触发器
	vector<CSysUserInfoActionTrigger *> *pActionTriggers;
	vector<CSysUserInfoCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysUserInfo compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoFactory是一个在线用户信息查询应答的对象工厂。它包含了一批在线用户信息查询应答，
///同时又建立了如下索引，以方便查询：
///	SysHostNameIndex
///	DecIndex
///使用本对象工厂，可以完成对在线用户信息查询应答的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByHostName，findNextByHostName和endFindByHostName完成查询操作
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///		使用startFindByDsc，findNextByDsc和endFindByDsc完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysOnlineUserInfoFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysOnlineUserInfo，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysOnlineUserInfoFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysOnlineUserInfoFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysOnlineUserInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysOnlineUserInfo，文件名将根据配置文件中的定义SysOnlineUserInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysOnlineUserInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysOnlineUserInfo，文件名将根据配置文件中的定义SysOnlineUserInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysOnlineUserInfoResource;

	///将一个CSysOnlineUserInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysOnlineUserInfo	要加入的SysOnlineUserInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysOnlineUserInfo *add(CWriteableSysOnlineUserInfo *pSysOnlineUserInfo, CTransaction *pTransaction=NULL);
	
	///刷新该CSysOnlineUserInfo的值
	///@param	pSysOnlineUserInfo	被刷新的CSysOnlineUserInfo
	///@param	pNewSysOnlineUserInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysOnlineUserInfo *pSysOnlineUserInfo, CWriteableSysOnlineUserInfo *pNewSysOnlineUserInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysOnlineUserInfo	  需要被刷新或者新增的CSysOnlineUserInfo,等于NULL表示是需要新增的
	///@param	pNewSysOnlineUserInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysOnlineUserInfo* addOrUpdate(CSysOnlineUserInfo *pSysOnlineUserInfo, CWriteableSysOnlineUserInfo *pNewSysOnlineUserInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysOnlineUserInfo，同时删除其索引
	///@param	pSysOnlineUserInfo	要删除的CSysOnlineUserInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysOnlineUserInfo *pSysOnlineUserInfo, CTransaction *pTransaction=NULL);
	
	///获取某个CSysOnlineUserInfo
	///@param	pSysOnlineUserInfo	要读取的CSysOnlineUserInfo
	///@param	pTragetSysOnlineUserInfo	存放结果的CSysOnlineUserInfo
	void retrieve(CSysOnlineUserInfo *pSysOnlineUserInfo, CWriteableSysOnlineUserInfo *pTargetSysOnlineUserInfo);
	
	///获取第一个CSysOnlineUserInfo
	///@return	得到的第一个CSysOnlineUserInfo，如果没有，则返回NULL
	CSysOnlineUserInfo *getFirst(void);
	
	///获取下一个CSysOnlineUserInfo
	///@return	得到下一个CSysOnlineUserInfo，如果没有，则返回NULL
	CSysOnlineUserInfo *getNext(void);
	
	///结束获取CSysOnlineUserInfo
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysOnlineUserInfoActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysOnlineUserInfoActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysOnlineUserInfoCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysOnlineUserInfoCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysOnlineUserInfoIteratorByHostName;

	///开始寻找CSysOnlineUserInfo
	///@param	ObjectID	
	///@param	MonTime	
	///@return	满足条件的地一个CSysOnlineUserInfo，如果找不到，返回NULL
	CSysOnlineUserInfo *startFindByHostName( const CReadOnlyTypeObjectIDType& ObjectID,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysOnlineUserInfo，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CSysOnlineUserInfo，如果已经没有一个满足要求了，则返回NULL
	CSysOnlineUserInfo *findNextByHostName(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByHostName(void);

	friend class CSysOnlineUserInfoIteratorBytheAll;

	///开始寻找CSysOnlineUserInfo
	///@return	满足条件的地一个CSysOnlineUserInfo，如果找不到，返回NULL
	CSysOnlineUserInfo *startFindBytheAll();

	///寻找下一个符合条件的CSysOnlineUserInfo，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysOnlineUserInfo，如果已经没有一个满足要求了，则返回NULL
	CSysOnlineUserInfo *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

	friend class CSysOnlineUserInfoIteratorByDsc;

	///开始寻找CSysOnlineUserInfo
	///@param	ObjectID	
	///@return	满足条件的地一个CSysOnlineUserInfo，如果找不到，返回NULL
	CSysOnlineUserInfo *startFindByDsc( const CReadOnlyTypeObjectIDType& ObjectID);

	///寻找下一个符合条件的CSysOnlineUserInfo，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysOnlineUserInfo，如果已经没有一个满足要求了，则返回NULL
	CSysOnlineUserInfo *findNextByDsc(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDsc(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysOnlineUserInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysOnlineUserInfo	要加入的SysOnlineUserInfo
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysOnlineUserInfo *internalAdd(CWriteableSysOnlineUserInfo *pSysOnlineUserInfo, bool bNoTransaction);
	
	
	///刷新该CSysOnlineUserInfo的键值
	///@param	pSysOnlineUserInfo	被刷新的CSysOnlineUserInfo
	///@param	pNewSysOnlineUserInfo	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysOnlineUserInfo *pSysOnlineUserInfo, CWriteableSysOnlineUserInfo *pNewSysOnlineUserInfo, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysOnlineUserInfo，同时删除其索引
	///@param	pSysOnlineUserInfo	要删除的CSysOnlineUserInfo
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysOnlineUserInfo *pSysOnlineUserInfo, bool bNoTransaction);
/*
	///检查某个CSysOnlineUserInfo是否属于本对象工厂
	///@param	pSysOnlineUserInfo	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysOnlineUserInfo *pSysOnlineUserInfo);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ObjectID+MonTime的索引
	CAVLTree *pSysHostNameIndex;
	///基于ObjectID+MonDate+MonTime的索引
	CAVLTree *pDecIndex;
	
	
	///按照ObjectID，MonTime检索时，存储的查询参数
	CTypeObjectIDType queryObjectIDInSearchByHostName;
	CTimeType queryMonTimeInSearchByHostName;
	
	///按照ObjectID，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByHostName;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	///按照ObjectID检索时，存储的查询参数
	CTypeObjectIDType queryObjectIDInSearchByDsc;
	
	///按照ObjectID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDsc;
	
	///加入前触发
	///@param	pSysOnlineUserInfo	要加入的SysOnlineUserInfo
	virtual void beforeAdd(CWriteableSysOnlineUserInfo *pSysOnlineUserInfo);
	
	///加入后触发
	///@param	pSysOnlineUserInfo	已经加入的SysOnlineUserInfo
	virtual void afterAdd(CSysOnlineUserInfo *pSysOnlineUserInfo);

	///更新前触发	
	///@param	pSysOnlineUserInfo	被刷新的CSysOnlineUserInfo
	///@param	pNewSysOnlineUserInfo	新的值
	virtual void beforeUpdate(CSysOnlineUserInfo *pSysOnlineUserInfo, CWriteableSysOnlineUserInfo *pNewSysOnlineUserInfo);
	
	///更新后触发
	///@param	pSysOnlineUserInfo	被刷新的CSysOnlineUserInfo
	virtual void afterUpdate(CSysOnlineUserInfo *pSysOnlineUserInfo);
	
	///删除前触发
	///@param	pSysOnlineUserInfo	要删除的CSysOnlineUserInfo
	virtual void beforeRemove(CSysOnlineUserInfo *pSysOnlineUserInfo);
	
	///确认加入后触发
	///@param	pSysOnlineUserInfo	已经加入的SysOnlineUserInfo
	virtual void commitAdd(CSysOnlineUserInfo *pSysOnlineUserInfo);

	///确认更新后触发
	///@param	pSysOnlineUserInfo	被刷新的CSysOnlineUserInfo
	///@param	poldSysOnlineUserInfo	原来的值
	virtual void commitUpdate(CSysOnlineUserInfo *pSysOnlineUserInfo, CWriteableSysOnlineUserInfo *pOldSysOnlineUserInfo);
	
	///确认删除后触发
	///@param	pSysOnlineUserInfo	已经删除的CSysOnlineUserInfo
	virtual void commitRemove(CWriteableSysOnlineUserInfo *pSysOnlineUserInfo);

	///所有相关的触发器
	vector<CSysOnlineUserInfoActionTrigger *> *pActionTriggers;
	vector<CSysOnlineUserInfoCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysOnlineUserInfo compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningEventFactory是一个告警事件查询应答的对象工厂。它包含了一批告警事件查询应答，
///同时又建立了如下索引，以方便查询：
///	SysHostNameIndex
///	SysEventIdIndex
///使用本对象工厂，可以完成对告警事件查询应答的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByTime，findNextByTime和endFindByTime完成查询操作
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByEvendID，唯一找到对象
///		使用startFindByEvendIDs，findNextByEvendIDs和endFindByEvendIDs完成查询操作
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysWarningEventFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysWarningEvent，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysWarningEventFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysWarningEventFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysWarningEvent
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysWarningEvent，文件名将根据配置文件中的定义SysWarningEventCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysWarningEvent
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysWarningEvent，文件名将根据配置文件中的定义SysWarningEventCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysWarningEventResource;

	///将一个CSysWarningEvent加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysWarningEvent	要加入的SysWarningEvent
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysWarningEvent *add(CWriteableSysWarningEvent *pSysWarningEvent, CTransaction *pTransaction=NULL);
	
	///刷新该CSysWarningEvent的值
	///@param	pSysWarningEvent	被刷新的CSysWarningEvent
	///@param	pNewSysWarningEvent	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysWarningEvent *pSysWarningEvent, CWriteableSysWarningEvent *pNewSysWarningEvent, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysWarningEvent	  需要被刷新或者新增的CSysWarningEvent,等于NULL表示是需要新增的
	///@param	pNewSysWarningEvent	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysWarningEvent* addOrUpdate(CSysWarningEvent *pSysWarningEvent, CWriteableSysWarningEvent *pNewSysWarningEvent, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysWarningEvent，同时删除其索引
	///@param	pSysWarningEvent	要删除的CSysWarningEvent
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysWarningEvent *pSysWarningEvent, CTransaction *pTransaction=NULL);
	
	///获取某个CSysWarningEvent
	///@param	pSysWarningEvent	要读取的CSysWarningEvent
	///@param	pTragetSysWarningEvent	存放结果的CSysWarningEvent
	void retrieve(CSysWarningEvent *pSysWarningEvent, CWriteableSysWarningEvent *pTargetSysWarningEvent);
	
	///获取第一个CSysWarningEvent
	///@return	得到的第一个CSysWarningEvent，如果没有，则返回NULL
	CSysWarningEvent *getFirst(void);
	
	///获取下一个CSysWarningEvent
	///@return	得到下一个CSysWarningEvent，如果没有，则返回NULL
	CSysWarningEvent *getNext(void);
	
	///结束获取CSysWarningEvent
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysWarningEventActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysWarningEventActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysWarningEventCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysWarningEventCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysWarningEventIteratorByTime;

	///开始寻找CSysWarningEvent
	///@param	MonDate	
	///@param	OccurTime	
	///@return	满足条件的地一个CSysWarningEvent，如果找不到，返回NULL
	CSysWarningEvent *startFindByTime( const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& OccurTime);

	///寻找下一个符合条件的CSysWarningEvent，必须在startFindByTime以后，endFindByTime之前叫用
	///@return	下一个满足条件CSysWarningEvent，如果已经没有一个满足要求了，则返回NULL
	CSysWarningEvent *findNextByTime(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByTime(void);

	friend class CSysWarningEventIteratorByAll;

	///开始寻找CSysWarningEvent
	///@return	满足条件的地一个CSysWarningEvent，如果找不到，返回NULL
	CSysWarningEvent *startFindByAll();

	///寻找下一个符合条件的CSysWarningEvent，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysWarningEvent，如果已经没有一个满足要求了，则返回NULL
	CSysWarningEvent *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysWarningEvent
	///@param	EvendID	
	///@return	找到的CSysWarningEvent，如果找不到，返回NULL
	CSysWarningEvent *findByEvendID( const CReadOnlyVolumeType&  EvendID);



	friend class CSysWarningEventIteratorByEvendIDs;

	///开始寻找CSysWarningEvent
	///@param	EvendID	
	///@return	满足条件的地一个CSysWarningEvent，如果找不到，返回NULL
	CSysWarningEvent *startFindByEvendIDs( const CReadOnlyVolumeType& EvendID);

	///寻找下一个符合条件的CSysWarningEvent，必须在startFindByEvendIDs以后，endFindByEvendIDs之前叫用
	///@return	下一个满足条件CSysWarningEvent，如果已经没有一个满足要求了，则返回NULL
	CSysWarningEvent *findNextByEvendIDs(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByEvendIDs(void);

	friend class CSysWarningEventIteratorBytheAll;

	///开始寻找CSysWarningEvent
	///@return	满足条件的地一个CSysWarningEvent，如果找不到，返回NULL
	CSysWarningEvent *startFindBytheAll();

	///寻找下一个符合条件的CSysWarningEvent，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysWarningEvent，如果已经没有一个满足要求了，则返回NULL
	CSysWarningEvent *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysWarningEvent加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysWarningEvent	要加入的SysWarningEvent
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysWarningEvent *internalAdd(CWriteableSysWarningEvent *pSysWarningEvent, bool bNoTransaction);
	
	
	///刷新该CSysWarningEvent的键值
	///@param	pSysWarningEvent	被刷新的CSysWarningEvent
	///@param	pNewSysWarningEvent	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysWarningEvent *pSysWarningEvent, CWriteableSysWarningEvent *pNewSysWarningEvent, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysWarningEvent，同时删除其索引
	///@param	pSysWarningEvent	要删除的CSysWarningEvent
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysWarningEvent *pSysWarningEvent, bool bNoTransaction);
/*
	///检查某个CSysWarningEvent是否属于本对象工厂
	///@param	pSysWarningEvent	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysWarningEvent *pSysWarningEvent);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于MonDate+OccurTime的索引
	CAVLTree *pSysHostNameIndex;
	///基于EvendID的索引
	CAVLTree *pSysEventIdIndex;
	
	
	///按照MonDate，OccurTime检索时，存储的查询参数
	CDateType queryMonDateInSearchByTime;
	CTimeType queryOccurTimeInSearchByTime;
	
	///按照MonDate，OccurTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByTime;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	///按照EvendID检索时，存储的查询参数
	CVolumeType queryEvendIDInSearchByEvendIDs;
	
	///按照EvendID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByEvendIDs;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	
	///加入前触发
	///@param	pSysWarningEvent	要加入的SysWarningEvent
	virtual void beforeAdd(CWriteableSysWarningEvent *pSysWarningEvent);
	
	///加入后触发
	///@param	pSysWarningEvent	已经加入的SysWarningEvent
	virtual void afterAdd(CSysWarningEvent *pSysWarningEvent);

	///更新前触发	
	///@param	pSysWarningEvent	被刷新的CSysWarningEvent
	///@param	pNewSysWarningEvent	新的值
	virtual void beforeUpdate(CSysWarningEvent *pSysWarningEvent, CWriteableSysWarningEvent *pNewSysWarningEvent);
	
	///更新后触发
	///@param	pSysWarningEvent	被刷新的CSysWarningEvent
	virtual void afterUpdate(CSysWarningEvent *pSysWarningEvent);
	
	///删除前触发
	///@param	pSysWarningEvent	要删除的CSysWarningEvent
	virtual void beforeRemove(CSysWarningEvent *pSysWarningEvent);
	
	///确认加入后触发
	///@param	pSysWarningEvent	已经加入的SysWarningEvent
	virtual void commitAdd(CSysWarningEvent *pSysWarningEvent);

	///确认更新后触发
	///@param	pSysWarningEvent	被刷新的CSysWarningEvent
	///@param	poldSysWarningEvent	原来的值
	virtual void commitUpdate(CSysWarningEvent *pSysWarningEvent, CWriteableSysWarningEvent *pOldSysWarningEvent);
	
	///确认删除后触发
	///@param	pSysWarningEvent	已经删除的CSysWarningEvent
	virtual void commitRemove(CWriteableSysWarningEvent *pSysWarningEvent);

	///所有相关的触发器
	vector<CSysWarningEventActionTrigger *> *pActionTriggers;
	vector<CSysWarningEventCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysWarningEvent compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningQueryFactory是一个告警明细应答的对象工厂。它包含了一批告警明细应答，
///同时又建立了如下索引，以方便查询：
///	SysHostNameIndex
///	SysEventIdIndex
///使用本对象工厂，可以完成对告警明细应答的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByTime，findNextByTime和endFindByTime完成查询操作
///		使用findByEvendID，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningQueryFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysWarningQueryFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysWarningQuery，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysWarningQueryFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysWarningQueryFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysWarningQuery
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysWarningQuery，文件名将根据配置文件中的定义SysWarningQueryCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysWarningQuery
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysWarningQuery，文件名将根据配置文件中的定义SysWarningQueryCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysWarningQueryResource;

	///将一个CSysWarningQuery加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysWarningQuery	要加入的SysWarningQuery
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysWarningQuery *add(CWriteableSysWarningQuery *pSysWarningQuery, CTransaction *pTransaction=NULL);
	
	///刷新该CSysWarningQuery的值
	///@param	pSysWarningQuery	被刷新的CSysWarningQuery
	///@param	pNewSysWarningQuery	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysWarningQuery *pSysWarningQuery, CWriteableSysWarningQuery *pNewSysWarningQuery, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysWarningQuery	  需要被刷新或者新增的CSysWarningQuery,等于NULL表示是需要新增的
	///@param	pNewSysWarningQuery	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysWarningQuery* addOrUpdate(CSysWarningQuery *pSysWarningQuery, CWriteableSysWarningQuery *pNewSysWarningQuery, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysWarningQuery，同时删除其索引
	///@param	pSysWarningQuery	要删除的CSysWarningQuery
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysWarningQuery *pSysWarningQuery, CTransaction *pTransaction=NULL);
	
	///获取某个CSysWarningQuery
	///@param	pSysWarningQuery	要读取的CSysWarningQuery
	///@param	pTragetSysWarningQuery	存放结果的CSysWarningQuery
	void retrieve(CSysWarningQuery *pSysWarningQuery, CWriteableSysWarningQuery *pTargetSysWarningQuery);
	
	///获取第一个CSysWarningQuery
	///@return	得到的第一个CSysWarningQuery，如果没有，则返回NULL
	CSysWarningQuery *getFirst(void);
	
	///获取下一个CSysWarningQuery
	///@return	得到下一个CSysWarningQuery，如果没有，则返回NULL
	CSysWarningQuery *getNext(void);
	
	///结束获取CSysWarningQuery
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysWarningQueryActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysWarningQueryActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysWarningQueryCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysWarningQueryCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysWarningQueryIteratorByTime;

	///开始寻找CSysWarningQuery
	///@param	MonDate	
	///@param	MonTime	
	///@return	满足条件的地一个CSysWarningQuery，如果找不到，返回NULL
	CSysWarningQuery *startFindByTime( const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysWarningQuery，必须在startFindByTime以后，endFindByTime之前叫用
	///@return	下一个满足条件CSysWarningQuery，如果已经没有一个满足要求了，则返回NULL
	CSysWarningQuery *findNextByTime(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByTime(void);

	///寻找CSysWarningQuery
	///@param	EvendID	
	///@return	找到的CSysWarningQuery，如果找不到，返回NULL
	CSysWarningQuery *findByEvendID( const CReadOnlyVolumeType&  EvendID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysWarningQuery加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysWarningQuery	要加入的SysWarningQuery
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysWarningQuery *internalAdd(CWriteableSysWarningQuery *pSysWarningQuery, bool bNoTransaction);
	
	
	///刷新该CSysWarningQuery的键值
	///@param	pSysWarningQuery	被刷新的CSysWarningQuery
	///@param	pNewSysWarningQuery	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysWarningQuery *pSysWarningQuery, CWriteableSysWarningQuery *pNewSysWarningQuery, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysWarningQuery，同时删除其索引
	///@param	pSysWarningQuery	要删除的CSysWarningQuery
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysWarningQuery *pSysWarningQuery, bool bNoTransaction);
/*
	///检查某个CSysWarningQuery是否属于本对象工厂
	///@param	pSysWarningQuery	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysWarningQuery *pSysWarningQuery);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于MonDate+MonTime的索引
	CAVLTree *pSysHostNameIndex;
	///基于EvendID的索引
	CAVLTree *pSysEventIdIndex;
	
	
	///按照MonDate，MonTime检索时，存储的查询参数
	CDateType queryMonDateInSearchByTime;
	CTimeType queryMonTimeInSearchByTime;
	
	///按照MonDate，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByTime;
	
	///加入前触发
	///@param	pSysWarningQuery	要加入的SysWarningQuery
	virtual void beforeAdd(CWriteableSysWarningQuery *pSysWarningQuery);
	
	///加入后触发
	///@param	pSysWarningQuery	已经加入的SysWarningQuery
	virtual void afterAdd(CSysWarningQuery *pSysWarningQuery);

	///更新前触发	
	///@param	pSysWarningQuery	被刷新的CSysWarningQuery
	///@param	pNewSysWarningQuery	新的值
	virtual void beforeUpdate(CSysWarningQuery *pSysWarningQuery, CWriteableSysWarningQuery *pNewSysWarningQuery);
	
	///更新后触发
	///@param	pSysWarningQuery	被刷新的CSysWarningQuery
	virtual void afterUpdate(CSysWarningQuery *pSysWarningQuery);
	
	///删除前触发
	///@param	pSysWarningQuery	要删除的CSysWarningQuery
	virtual void beforeRemove(CSysWarningQuery *pSysWarningQuery);
	
	///确认加入后触发
	///@param	pSysWarningQuery	已经加入的SysWarningQuery
	virtual void commitAdd(CSysWarningQuery *pSysWarningQuery);

	///确认更新后触发
	///@param	pSysWarningQuery	被刷新的CSysWarningQuery
	///@param	poldSysWarningQuery	原来的值
	virtual void commitUpdate(CSysWarningQuery *pSysWarningQuery, CWriteableSysWarningQuery *pOldSysWarningQuery);
	
	///确认删除后触发
	///@param	pSysWarningQuery	已经删除的CSysWarningQuery
	virtual void commitRemove(CWriteableSysWarningQuery *pSysWarningQuery);

	///所有相关的触发器
	vector<CSysWarningQueryActionTrigger *> *pActionTriggers;
	vector<CSysWarningQueryCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysWarningQuery compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSyslogEventFactory是一个日志事件查询应答的对象工厂。它包含了一批日志事件查询应答，
///同时又建立了如下索引，以方便查询：
///	SysTimeIndex
///	SysEventIdIndex
///使用本对象工厂，可以完成对日志事件查询应答的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByTime，findNextByTime和endFindByTime完成查询操作
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByEvendID，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSyslogEventFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSyslogEvent，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSyslogEventFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSyslogEventFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SyslogEvent
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SyslogEvent，文件名将根据配置文件中的定义SyslogEventCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SyslogEvent
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SyslogEvent，文件名将根据配置文件中的定义SyslogEventCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSyslogEventResource;

	///将一个CSyslogEvent加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSyslogEvent	要加入的SyslogEvent
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSyslogEvent *add(CWriteableSyslogEvent *pSyslogEvent, CTransaction *pTransaction=NULL);
	
	///刷新该CSyslogEvent的值
	///@param	pSyslogEvent	被刷新的CSyslogEvent
	///@param	pNewSyslogEvent	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSyslogEvent *pSyslogEvent, CWriteableSyslogEvent *pNewSyslogEvent, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSyslogEvent	  需要被刷新或者新增的CSyslogEvent,等于NULL表示是需要新增的
	///@param	pNewSyslogEvent	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSyslogEvent* addOrUpdate(CSyslogEvent *pSyslogEvent, CWriteableSyslogEvent *pNewSyslogEvent, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSyslogEvent，同时删除其索引
	///@param	pSyslogEvent	要删除的CSyslogEvent
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSyslogEvent *pSyslogEvent, CTransaction *pTransaction=NULL);
	
	///获取某个CSyslogEvent
	///@param	pSyslogEvent	要读取的CSyslogEvent
	///@param	pTragetSyslogEvent	存放结果的CSyslogEvent
	void retrieve(CSyslogEvent *pSyslogEvent, CWriteableSyslogEvent *pTargetSyslogEvent);
	
	///获取第一个CSyslogEvent
	///@return	得到的第一个CSyslogEvent，如果没有，则返回NULL
	CSyslogEvent *getFirst(void);
	
	///获取下一个CSyslogEvent
	///@return	得到下一个CSyslogEvent，如果没有，则返回NULL
	CSyslogEvent *getNext(void);
	
	///结束获取CSyslogEvent
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSyslogEventActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSyslogEventActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSyslogEventCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSyslogEventCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSyslogEventIteratorByTime;

	///开始寻找CSyslogEvent
	///@param	MonDate	
	///@param	OccurTime	
	///@return	满足条件的地一个CSyslogEvent，如果找不到，返回NULL
	CSyslogEvent *startFindByTime( const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& OccurTime);

	///寻找下一个符合条件的CSyslogEvent，必须在startFindByTime以后，endFindByTime之前叫用
	///@return	下一个满足条件CSyslogEvent，如果已经没有一个满足要求了，则返回NULL
	CSyslogEvent *findNextByTime(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByTime(void);

	friend class CSyslogEventIteratorBytheAll;

	///开始寻找CSyslogEvent
	///@return	满足条件的地一个CSyslogEvent，如果找不到，返回NULL
	CSyslogEvent *startFindBytheAll();

	///寻找下一个符合条件的CSyslogEvent，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSyslogEvent，如果已经没有一个满足要求了，则返回NULL
	CSyslogEvent *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

	friend class CSyslogEventIteratorByAll;

	///开始寻找CSyslogEvent
	///@return	满足条件的地一个CSyslogEvent，如果找不到，返回NULL
	CSyslogEvent *startFindByAll();

	///寻找下一个符合条件的CSyslogEvent，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSyslogEvent，如果已经没有一个满足要求了，则返回NULL
	CSyslogEvent *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSyslogEvent
	///@param	EvendID	
	///@return	找到的CSyslogEvent，如果找不到，返回NULL
	CSyslogEvent *findByEvendID( const CReadOnlyVolumeType&  EvendID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSyslogEvent加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSyslogEvent	要加入的SyslogEvent
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSyslogEvent *internalAdd(CWriteableSyslogEvent *pSyslogEvent, bool bNoTransaction);
	
	
	///刷新该CSyslogEvent的键值
	///@param	pSyslogEvent	被刷新的CSyslogEvent
	///@param	pNewSyslogEvent	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSyslogEvent *pSyslogEvent, CWriteableSyslogEvent *pNewSyslogEvent, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSyslogEvent，同时删除其索引
	///@param	pSyslogEvent	要删除的CSyslogEvent
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSyslogEvent *pSyslogEvent, bool bNoTransaction);
/*
	///检查某个CSyslogEvent是否属于本对象工厂
	///@param	pSyslogEvent	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSyslogEvent *pSyslogEvent);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于MonDate+OccurTime的索引
	CAVLTree *pSysTimeIndex;
	///基于EvendID的索引
	CAVLTree *pSysEventIdIndex;
	
	
	///按照MonDate，OccurTime检索时，存储的查询参数
	CDateType queryMonDateInSearchByTime;
	CTimeType queryOccurTimeInSearchByTime;
	
	///按照MonDate，OccurTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByTime;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSyslogEvent	要加入的SyslogEvent
	virtual void beforeAdd(CWriteableSyslogEvent *pSyslogEvent);
	
	///加入后触发
	///@param	pSyslogEvent	已经加入的SyslogEvent
	virtual void afterAdd(CSyslogEvent *pSyslogEvent);

	///更新前触发	
	///@param	pSyslogEvent	被刷新的CSyslogEvent
	///@param	pNewSyslogEvent	新的值
	virtual void beforeUpdate(CSyslogEvent *pSyslogEvent, CWriteableSyslogEvent *pNewSyslogEvent);
	
	///更新后触发
	///@param	pSyslogEvent	被刷新的CSyslogEvent
	virtual void afterUpdate(CSyslogEvent *pSyslogEvent);
	
	///删除前触发
	///@param	pSyslogEvent	要删除的CSyslogEvent
	virtual void beforeRemove(CSyslogEvent *pSyslogEvent);
	
	///确认加入后触发
	///@param	pSyslogEvent	已经加入的SyslogEvent
	virtual void commitAdd(CSyslogEvent *pSyslogEvent);

	///确认更新后触发
	///@param	pSyslogEvent	被刷新的CSyslogEvent
	///@param	poldSyslogEvent	原来的值
	virtual void commitUpdate(CSyslogEvent *pSyslogEvent, CWriteableSyslogEvent *pOldSyslogEvent);
	
	///确认删除后触发
	///@param	pSyslogEvent	已经删除的CSyslogEvent
	virtual void commitRemove(CWriteableSyslogEvent *pSyslogEvent);

	///所有相关的触发器
	vector<CSyslogEventActionTrigger *> *pActionTriggers;
	vector<CSyslogEventCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSyslogEvent compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysEventDescripFactory是一个事件描述查询的对象工厂。它包含了一批事件描述查询，
///同时又建立了如下索引，以方便查询：
///	SysTimeIndex
///	SysEventIdIndex
///使用本对象工厂，可以完成对事件描述查询的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByTime，findNextByTime和endFindByTime完成查询操作
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByEvendID，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysEventDescripFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysEventDescrip，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysEventDescripFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysEventDescripFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysEventDescrip
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysEventDescrip，文件名将根据配置文件中的定义SysEventDescripCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysEventDescrip
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysEventDescrip，文件名将根据配置文件中的定义SysEventDescripCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysEventDescripResource;

	///将一个CSysEventDescrip加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysEventDescrip	要加入的SysEventDescrip
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysEventDescrip *add(CWriteableSysEventDescrip *pSysEventDescrip, CTransaction *pTransaction=NULL);
	
	///刷新该CSysEventDescrip的值
	///@param	pSysEventDescrip	被刷新的CSysEventDescrip
	///@param	pNewSysEventDescrip	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysEventDescrip *pSysEventDescrip, CWriteableSysEventDescrip *pNewSysEventDescrip, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysEventDescrip	  需要被刷新或者新增的CSysEventDescrip,等于NULL表示是需要新增的
	///@param	pNewSysEventDescrip	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysEventDescrip* addOrUpdate(CSysEventDescrip *pSysEventDescrip, CWriteableSysEventDescrip *pNewSysEventDescrip, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysEventDescrip，同时删除其索引
	///@param	pSysEventDescrip	要删除的CSysEventDescrip
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysEventDescrip *pSysEventDescrip, CTransaction *pTransaction=NULL);
	
	///获取某个CSysEventDescrip
	///@param	pSysEventDescrip	要读取的CSysEventDescrip
	///@param	pTragetSysEventDescrip	存放结果的CSysEventDescrip
	void retrieve(CSysEventDescrip *pSysEventDescrip, CWriteableSysEventDescrip *pTargetSysEventDescrip);
	
	///获取第一个CSysEventDescrip
	///@return	得到的第一个CSysEventDescrip，如果没有，则返回NULL
	CSysEventDescrip *getFirst(void);
	
	///获取下一个CSysEventDescrip
	///@return	得到下一个CSysEventDescrip，如果没有，则返回NULL
	CSysEventDescrip *getNext(void);
	
	///结束获取CSysEventDescrip
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysEventDescripActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysEventDescripActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysEventDescripCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysEventDescripCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysEventDescripIteratorByTime;

	///开始寻找CSysEventDescrip
	///@param	MonDate	
	///@param	MonTime	
	///@return	满足条件的地一个CSysEventDescrip，如果找不到，返回NULL
	CSysEventDescrip *startFindByTime( const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysEventDescrip，必须在startFindByTime以后，endFindByTime之前叫用
	///@return	下一个满足条件CSysEventDescrip，如果已经没有一个满足要求了，则返回NULL
	CSysEventDescrip *findNextByTime(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByTime(void);

	friend class CSysEventDescripIteratorBytheAll;

	///开始寻找CSysEventDescrip
	///@return	满足条件的地一个CSysEventDescrip，如果找不到，返回NULL
	CSysEventDescrip *startFindBytheAll();

	///寻找下一个符合条件的CSysEventDescrip，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysEventDescrip，如果已经没有一个满足要求了，则返回NULL
	CSysEventDescrip *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

	friend class CSysEventDescripIteratorByAll;

	///开始寻找CSysEventDescrip
	///@return	满足条件的地一个CSysEventDescrip，如果找不到，返回NULL
	CSysEventDescrip *startFindByAll();

	///寻找下一个符合条件的CSysEventDescrip，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysEventDescrip，如果已经没有一个满足要求了，则返回NULL
	CSysEventDescrip *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysEventDescrip
	///@param	EventDesID	
	///@return	找到的CSysEventDescrip，如果找不到，返回NULL
	CSysEventDescrip *findByEvendID( const CReadOnlyEventDesIDType&  EventDesID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysEventDescrip加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysEventDescrip	要加入的SysEventDescrip
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysEventDescrip *internalAdd(CWriteableSysEventDescrip *pSysEventDescrip, bool bNoTransaction);
	
	
	///刷新该CSysEventDescrip的键值
	///@param	pSysEventDescrip	被刷新的CSysEventDescrip
	///@param	pNewSysEventDescrip	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysEventDescrip *pSysEventDescrip, CWriteableSysEventDescrip *pNewSysEventDescrip, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysEventDescrip，同时删除其索引
	///@param	pSysEventDescrip	要删除的CSysEventDescrip
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysEventDescrip *pSysEventDescrip, bool bNoTransaction);
/*
	///检查某个CSysEventDescrip是否属于本对象工厂
	///@param	pSysEventDescrip	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysEventDescrip *pSysEventDescrip);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于MonDate+MonTime的索引
	CAVLTree *pSysTimeIndex;
	///基于EventDesID的索引
	CAVLTree *pSysEventIdIndex;
	
	
	///按照MonDate，MonTime检索时，存储的查询参数
	CDateType queryMonDateInSearchByTime;
	CTimeType queryMonTimeInSearchByTime;
	
	///按照MonDate，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByTime;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysEventDescrip	要加入的SysEventDescrip
	virtual void beforeAdd(CWriteableSysEventDescrip *pSysEventDescrip);
	
	///加入后触发
	///@param	pSysEventDescrip	已经加入的SysEventDescrip
	virtual void afterAdd(CSysEventDescrip *pSysEventDescrip);

	///更新前触发	
	///@param	pSysEventDescrip	被刷新的CSysEventDescrip
	///@param	pNewSysEventDescrip	新的值
	virtual void beforeUpdate(CSysEventDescrip *pSysEventDescrip, CWriteableSysEventDescrip *pNewSysEventDescrip);
	
	///更新后触发
	///@param	pSysEventDescrip	被刷新的CSysEventDescrip
	virtual void afterUpdate(CSysEventDescrip *pSysEventDescrip);
	
	///删除前触发
	///@param	pSysEventDescrip	要删除的CSysEventDescrip
	virtual void beforeRemove(CSysEventDescrip *pSysEventDescrip);
	
	///确认加入后触发
	///@param	pSysEventDescrip	已经加入的SysEventDescrip
	virtual void commitAdd(CSysEventDescrip *pSysEventDescrip);

	///确认更新后触发
	///@param	pSysEventDescrip	被刷新的CSysEventDescrip
	///@param	poldSysEventDescrip	原来的值
	virtual void commitUpdate(CSysEventDescrip *pSysEventDescrip, CWriteableSysEventDescrip *pOldSysEventDescrip);
	
	///确认删除后触发
	///@param	pSysEventDescrip	已经删除的CSysEventDescrip
	virtual void commitRemove(CWriteableSysEventDescrip *pSysEventDescrip);

	///所有相关的触发器
	vector<CSysEventDescripActionTrigger *> *pActionTriggers;
	vector<CSysEventDescripCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysEventDescrip compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvCommonFactory是一个主机环境信息的对象工厂。它包含了一批主机环境信息，
///同时又建立了如下索引，以方便查询：
///	SysHostNameIndex
///使用本对象工厂，可以完成对主机环境信息的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByHostName，findNextByHostName和endFindByHostName完成查询操作
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvCommonFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CRspQryHostEnvCommonFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxRspQryHostEnvCommon，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CRspQryHostEnvCommonFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CRspQryHostEnvCommonFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的RspQryHostEnvCommon
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的RspQryHostEnvCommon，文件名将根据配置文件中的定义RspQryHostEnvCommonCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的RspQryHostEnvCommon
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的RspQryHostEnvCommon，文件名将根据配置文件中的定义RspQryHostEnvCommonCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CRspQryHostEnvCommonResource;

	///将一个CRspQryHostEnvCommon加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pRspQryHostEnvCommon	要加入的RspQryHostEnvCommon
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CRspQryHostEnvCommon *add(CWriteableRspQryHostEnvCommon *pRspQryHostEnvCommon, CTransaction *pTransaction=NULL);
	
	///刷新该CRspQryHostEnvCommon的值
	///@param	pRspQryHostEnvCommon	被刷新的CRspQryHostEnvCommon
	///@param	pNewRspQryHostEnvCommon	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CRspQryHostEnvCommon *pRspQryHostEnvCommon, CWriteableRspQryHostEnvCommon *pNewRspQryHostEnvCommon, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pRspQryHostEnvCommon	  需要被刷新或者新增的CRspQryHostEnvCommon,等于NULL表示是需要新增的
	///@param	pNewRspQryHostEnvCommon	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CRspQryHostEnvCommon* addOrUpdate(CRspQryHostEnvCommon *pRspQryHostEnvCommon, CWriteableRspQryHostEnvCommon *pNewRspQryHostEnvCommon, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CRspQryHostEnvCommon，同时删除其索引
	///@param	pRspQryHostEnvCommon	要删除的CRspQryHostEnvCommon
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CRspQryHostEnvCommon *pRspQryHostEnvCommon, CTransaction *pTransaction=NULL);
	
	///获取某个CRspQryHostEnvCommon
	///@param	pRspQryHostEnvCommon	要读取的CRspQryHostEnvCommon
	///@param	pTragetRspQryHostEnvCommon	存放结果的CRspQryHostEnvCommon
	void retrieve(CRspQryHostEnvCommon *pRspQryHostEnvCommon, CWriteableRspQryHostEnvCommon *pTargetRspQryHostEnvCommon);
	
	///获取第一个CRspQryHostEnvCommon
	///@return	得到的第一个CRspQryHostEnvCommon，如果没有，则返回NULL
	CRspQryHostEnvCommon *getFirst(void);
	
	///获取下一个CRspQryHostEnvCommon
	///@return	得到下一个CRspQryHostEnvCommon，如果没有，则返回NULL
	CRspQryHostEnvCommon *getNext(void);
	
	///结束获取CRspQryHostEnvCommon
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CRspQryHostEnvCommonActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CRspQryHostEnvCommonActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CRspQryHostEnvCommonCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CRspQryHostEnvCommonCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CRspQryHostEnvCommonIteratorByHostName;

	///开始寻找CRspQryHostEnvCommon
	///@param	HostName	
	///@return	满足条件的地一个CRspQryHostEnvCommon，如果找不到，返回NULL
	CRspQryHostEnvCommon *startFindByHostName( const CReadOnlyTypeObjectIDType& HostName);

	///寻找下一个符合条件的CRspQryHostEnvCommon，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CRspQryHostEnvCommon，如果已经没有一个满足要求了，则返回NULL
	CRspQryHostEnvCommon *findNextByHostName(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByHostName(void);

	friend class CRspQryHostEnvCommonIteratorBytheAll;

	///开始寻找CRspQryHostEnvCommon
	///@return	满足条件的地一个CRspQryHostEnvCommon，如果找不到，返回NULL
	CRspQryHostEnvCommon *startFindBytheAll();

	///寻找下一个符合条件的CRspQryHostEnvCommon，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CRspQryHostEnvCommon，如果已经没有一个满足要求了，则返回NULL
	CRspQryHostEnvCommon *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CRspQryHostEnvCommon加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pRspQryHostEnvCommon	要加入的RspQryHostEnvCommon
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CRspQryHostEnvCommon *internalAdd(CWriteableRspQryHostEnvCommon *pRspQryHostEnvCommon, bool bNoTransaction);
	
	
	///刷新该CRspQryHostEnvCommon的键值
	///@param	pRspQryHostEnvCommon	被刷新的CRspQryHostEnvCommon
	///@param	pNewRspQryHostEnvCommon	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CRspQryHostEnvCommon *pRspQryHostEnvCommon, CWriteableRspQryHostEnvCommon *pNewRspQryHostEnvCommon, bool updateIndex,bool bNoTransaction);
	
	///删除一个CRspQryHostEnvCommon，同时删除其索引
	///@param	pRspQryHostEnvCommon	要删除的CRspQryHostEnvCommon
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CRspQryHostEnvCommon *pRspQryHostEnvCommon, bool bNoTransaction);
/*
	///检查某个CRspQryHostEnvCommon是否属于本对象工厂
	///@param	pRspQryHostEnvCommon	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CRspQryHostEnvCommon *pRspQryHostEnvCommon);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于HostName+MonTime的索引
	CAVLTree *pSysHostNameIndex;
	
	
	///按照HostName检索时，存储的查询参数
	CTypeObjectIDType queryHostNameInSearchByHostName;
	
	///按照HostName检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByHostName;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	
	///加入前触发
	///@param	pRspQryHostEnvCommon	要加入的RspQryHostEnvCommon
	virtual void beforeAdd(CWriteableRspQryHostEnvCommon *pRspQryHostEnvCommon);
	
	///加入后触发
	///@param	pRspQryHostEnvCommon	已经加入的RspQryHostEnvCommon
	virtual void afterAdd(CRspQryHostEnvCommon *pRspQryHostEnvCommon);

	///更新前触发	
	///@param	pRspQryHostEnvCommon	被刷新的CRspQryHostEnvCommon
	///@param	pNewRspQryHostEnvCommon	新的值
	virtual void beforeUpdate(CRspQryHostEnvCommon *pRspQryHostEnvCommon, CWriteableRspQryHostEnvCommon *pNewRspQryHostEnvCommon);
	
	///更新后触发
	///@param	pRspQryHostEnvCommon	被刷新的CRspQryHostEnvCommon
	virtual void afterUpdate(CRspQryHostEnvCommon *pRspQryHostEnvCommon);
	
	///删除前触发
	///@param	pRspQryHostEnvCommon	要删除的CRspQryHostEnvCommon
	virtual void beforeRemove(CRspQryHostEnvCommon *pRspQryHostEnvCommon);
	
	///确认加入后触发
	///@param	pRspQryHostEnvCommon	已经加入的RspQryHostEnvCommon
	virtual void commitAdd(CRspQryHostEnvCommon *pRspQryHostEnvCommon);

	///确认更新后触发
	///@param	pRspQryHostEnvCommon	被刷新的CRspQryHostEnvCommon
	///@param	poldRspQryHostEnvCommon	原来的值
	virtual void commitUpdate(CRspQryHostEnvCommon *pRspQryHostEnvCommon, CWriteableRspQryHostEnvCommon *pOldRspQryHostEnvCommon);
	
	///确认删除后触发
	///@param	pRspQryHostEnvCommon	已经删除的CRspQryHostEnvCommon
	virtual void commitRemove(CWriteableRspQryHostEnvCommon *pRspQryHostEnvCommon);

	///所有相关的触发器
	vector<CRspQryHostEnvCommonActionTrigger *> *pActionTriggers;
	vector<CRspQryHostEnvCommonCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableRspQryHostEnvCommon compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanFactory是一个主机环境Lan信息的对象工厂。它包含了一批主机环境Lan信息，
///同时又建立了如下索引，以方便查询：
///	SysHostNameIndex
///使用本对象工厂，可以完成对主机环境Lan信息的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByHostName，findNextByHostName和endFindByHostName完成查询操作
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CRspQryHostEnvLanFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxRspQryHostEnvLan，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CRspQryHostEnvLanFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CRspQryHostEnvLanFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的RspQryHostEnvLan
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的RspQryHostEnvLan，文件名将根据配置文件中的定义RspQryHostEnvLanCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的RspQryHostEnvLan
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的RspQryHostEnvLan，文件名将根据配置文件中的定义RspQryHostEnvLanCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CRspQryHostEnvLanResource;

	///将一个CRspQryHostEnvLan加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pRspQryHostEnvLan	要加入的RspQryHostEnvLan
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CRspQryHostEnvLan *add(CWriteableRspQryHostEnvLan *pRspQryHostEnvLan, CTransaction *pTransaction=NULL);
	
	///刷新该CRspQryHostEnvLan的值
	///@param	pRspQryHostEnvLan	被刷新的CRspQryHostEnvLan
	///@param	pNewRspQryHostEnvLan	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CRspQryHostEnvLan *pRspQryHostEnvLan, CWriteableRspQryHostEnvLan *pNewRspQryHostEnvLan, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pRspQryHostEnvLan	  需要被刷新或者新增的CRspQryHostEnvLan,等于NULL表示是需要新增的
	///@param	pNewRspQryHostEnvLan	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CRspQryHostEnvLan* addOrUpdate(CRspQryHostEnvLan *pRspQryHostEnvLan, CWriteableRspQryHostEnvLan *pNewRspQryHostEnvLan, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CRspQryHostEnvLan，同时删除其索引
	///@param	pRspQryHostEnvLan	要删除的CRspQryHostEnvLan
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CRspQryHostEnvLan *pRspQryHostEnvLan, CTransaction *pTransaction=NULL);
	
	///获取某个CRspQryHostEnvLan
	///@param	pRspQryHostEnvLan	要读取的CRspQryHostEnvLan
	///@param	pTragetRspQryHostEnvLan	存放结果的CRspQryHostEnvLan
	void retrieve(CRspQryHostEnvLan *pRspQryHostEnvLan, CWriteableRspQryHostEnvLan *pTargetRspQryHostEnvLan);
	
	///获取第一个CRspQryHostEnvLan
	///@return	得到的第一个CRspQryHostEnvLan，如果没有，则返回NULL
	CRspQryHostEnvLan *getFirst(void);
	
	///获取下一个CRspQryHostEnvLan
	///@return	得到下一个CRspQryHostEnvLan，如果没有，则返回NULL
	CRspQryHostEnvLan *getNext(void);
	
	///结束获取CRspQryHostEnvLan
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CRspQryHostEnvLanActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CRspQryHostEnvLanActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CRspQryHostEnvLanCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CRspQryHostEnvLanCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CRspQryHostEnvLanIteratorByHostName;

	///开始寻找CRspQryHostEnvLan
	///@param	HostName	
	///@return	满足条件的地一个CRspQryHostEnvLan，如果找不到，返回NULL
	CRspQryHostEnvLan *startFindByHostName( const CReadOnlyTypeObjectIDType& HostName);

	///寻找下一个符合条件的CRspQryHostEnvLan，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CRspQryHostEnvLan，如果已经没有一个满足要求了，则返回NULL
	CRspQryHostEnvLan *findNextByHostName(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByHostName(void);

	friend class CRspQryHostEnvLanIteratorBytheAll;

	///开始寻找CRspQryHostEnvLan
	///@return	满足条件的地一个CRspQryHostEnvLan，如果找不到，返回NULL
	CRspQryHostEnvLan *startFindBytheAll();

	///寻找下一个符合条件的CRspQryHostEnvLan，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CRspQryHostEnvLan，如果已经没有一个满足要求了，则返回NULL
	CRspQryHostEnvLan *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CRspQryHostEnvLan加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pRspQryHostEnvLan	要加入的RspQryHostEnvLan
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CRspQryHostEnvLan *internalAdd(CWriteableRspQryHostEnvLan *pRspQryHostEnvLan, bool bNoTransaction);
	
	
	///刷新该CRspQryHostEnvLan的键值
	///@param	pRspQryHostEnvLan	被刷新的CRspQryHostEnvLan
	///@param	pNewRspQryHostEnvLan	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CRspQryHostEnvLan *pRspQryHostEnvLan, CWriteableRspQryHostEnvLan *pNewRspQryHostEnvLan, bool updateIndex,bool bNoTransaction);
	
	///删除一个CRspQryHostEnvLan，同时删除其索引
	///@param	pRspQryHostEnvLan	要删除的CRspQryHostEnvLan
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CRspQryHostEnvLan *pRspQryHostEnvLan, bool bNoTransaction);
/*
	///检查某个CRspQryHostEnvLan是否属于本对象工厂
	///@param	pRspQryHostEnvLan	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CRspQryHostEnvLan *pRspQryHostEnvLan);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于HostName+MonTime的索引
	CAVLTree *pSysHostNameIndex;
	
	
	///按照HostName检索时，存储的查询参数
	CTypeObjectIDType queryHostNameInSearchByHostName;
	
	///按照HostName检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByHostName;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	
	///加入前触发
	///@param	pRspQryHostEnvLan	要加入的RspQryHostEnvLan
	virtual void beforeAdd(CWriteableRspQryHostEnvLan *pRspQryHostEnvLan);
	
	///加入后触发
	///@param	pRspQryHostEnvLan	已经加入的RspQryHostEnvLan
	virtual void afterAdd(CRspQryHostEnvLan *pRspQryHostEnvLan);

	///更新前触发	
	///@param	pRspQryHostEnvLan	被刷新的CRspQryHostEnvLan
	///@param	pNewRspQryHostEnvLan	新的值
	virtual void beforeUpdate(CRspQryHostEnvLan *pRspQryHostEnvLan, CWriteableRspQryHostEnvLan *pNewRspQryHostEnvLan);
	
	///更新后触发
	///@param	pRspQryHostEnvLan	被刷新的CRspQryHostEnvLan
	virtual void afterUpdate(CRspQryHostEnvLan *pRspQryHostEnvLan);
	
	///删除前触发
	///@param	pRspQryHostEnvLan	要删除的CRspQryHostEnvLan
	virtual void beforeRemove(CRspQryHostEnvLan *pRspQryHostEnvLan);
	
	///确认加入后触发
	///@param	pRspQryHostEnvLan	已经加入的RspQryHostEnvLan
	virtual void commitAdd(CRspQryHostEnvLan *pRspQryHostEnvLan);

	///确认更新后触发
	///@param	pRspQryHostEnvLan	被刷新的CRspQryHostEnvLan
	///@param	poldRspQryHostEnvLan	原来的值
	virtual void commitUpdate(CRspQryHostEnvLan *pRspQryHostEnvLan, CWriteableRspQryHostEnvLan *pOldRspQryHostEnvLan);
	
	///确认删除后触发
	///@param	pRspQryHostEnvLan	已经删除的CRspQryHostEnvLan
	virtual void commitRemove(CWriteableRspQryHostEnvLan *pRspQryHostEnvLan);

	///所有相关的触发器
	vector<CRspQryHostEnvLanActionTrigger *> *pActionTriggers;
	vector<CRspQryHostEnvLanCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableRspQryHostEnvLan compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvStorageFactory是一个主机环境存储设备信息的对象工厂。它包含了一批主机环境存储设备信息，
///同时又建立了如下索引，以方便查询：
///	SysHostNameIndex
///使用本对象工厂，可以完成对主机环境存储设备信息的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByHostName，findNextByHostName和endFindByHostName完成查询操作
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvStorageFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CRspQryHostEnvStorageFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxRspQryHostEnvStorage，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CRspQryHostEnvStorageFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CRspQryHostEnvStorageFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的RspQryHostEnvStorage
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的RspQryHostEnvStorage，文件名将根据配置文件中的定义RspQryHostEnvStorageCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的RspQryHostEnvStorage
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的RspQryHostEnvStorage，文件名将根据配置文件中的定义RspQryHostEnvStorageCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CRspQryHostEnvStorageResource;

	///将一个CRspQryHostEnvStorage加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pRspQryHostEnvStorage	要加入的RspQryHostEnvStorage
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CRspQryHostEnvStorage *add(CWriteableRspQryHostEnvStorage *pRspQryHostEnvStorage, CTransaction *pTransaction=NULL);
	
	///刷新该CRspQryHostEnvStorage的值
	///@param	pRspQryHostEnvStorage	被刷新的CRspQryHostEnvStorage
	///@param	pNewRspQryHostEnvStorage	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CRspQryHostEnvStorage *pRspQryHostEnvStorage, CWriteableRspQryHostEnvStorage *pNewRspQryHostEnvStorage, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pRspQryHostEnvStorage	  需要被刷新或者新增的CRspQryHostEnvStorage,等于NULL表示是需要新增的
	///@param	pNewRspQryHostEnvStorage	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CRspQryHostEnvStorage* addOrUpdate(CRspQryHostEnvStorage *pRspQryHostEnvStorage, CWriteableRspQryHostEnvStorage *pNewRspQryHostEnvStorage, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CRspQryHostEnvStorage，同时删除其索引
	///@param	pRspQryHostEnvStorage	要删除的CRspQryHostEnvStorage
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CRspQryHostEnvStorage *pRspQryHostEnvStorage, CTransaction *pTransaction=NULL);
	
	///获取某个CRspQryHostEnvStorage
	///@param	pRspQryHostEnvStorage	要读取的CRspQryHostEnvStorage
	///@param	pTragetRspQryHostEnvStorage	存放结果的CRspQryHostEnvStorage
	void retrieve(CRspQryHostEnvStorage *pRspQryHostEnvStorage, CWriteableRspQryHostEnvStorage *pTargetRspQryHostEnvStorage);
	
	///获取第一个CRspQryHostEnvStorage
	///@return	得到的第一个CRspQryHostEnvStorage，如果没有，则返回NULL
	CRspQryHostEnvStorage *getFirst(void);
	
	///获取下一个CRspQryHostEnvStorage
	///@return	得到下一个CRspQryHostEnvStorage，如果没有，则返回NULL
	CRspQryHostEnvStorage *getNext(void);
	
	///结束获取CRspQryHostEnvStorage
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CRspQryHostEnvStorageActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CRspQryHostEnvStorageActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CRspQryHostEnvStorageCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CRspQryHostEnvStorageCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CRspQryHostEnvStorageIteratorByHostName;

	///开始寻找CRspQryHostEnvStorage
	///@param	HostName	
	///@return	满足条件的地一个CRspQryHostEnvStorage，如果找不到，返回NULL
	CRspQryHostEnvStorage *startFindByHostName( const CReadOnlyTypeObjectIDType& HostName);

	///寻找下一个符合条件的CRspQryHostEnvStorage，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CRspQryHostEnvStorage，如果已经没有一个满足要求了，则返回NULL
	CRspQryHostEnvStorage *findNextByHostName(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByHostName(void);

	friend class CRspQryHostEnvStorageIteratorBytheAll;

	///开始寻找CRspQryHostEnvStorage
	///@return	满足条件的地一个CRspQryHostEnvStorage，如果找不到，返回NULL
	CRspQryHostEnvStorage *startFindBytheAll();

	///寻找下一个符合条件的CRspQryHostEnvStorage，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CRspQryHostEnvStorage，如果已经没有一个满足要求了，则返回NULL
	CRspQryHostEnvStorage *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CRspQryHostEnvStorage加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pRspQryHostEnvStorage	要加入的RspQryHostEnvStorage
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CRspQryHostEnvStorage *internalAdd(CWriteableRspQryHostEnvStorage *pRspQryHostEnvStorage, bool bNoTransaction);
	
	
	///刷新该CRspQryHostEnvStorage的键值
	///@param	pRspQryHostEnvStorage	被刷新的CRspQryHostEnvStorage
	///@param	pNewRspQryHostEnvStorage	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CRspQryHostEnvStorage *pRspQryHostEnvStorage, CWriteableRspQryHostEnvStorage *pNewRspQryHostEnvStorage, bool updateIndex,bool bNoTransaction);
	
	///删除一个CRspQryHostEnvStorage，同时删除其索引
	///@param	pRspQryHostEnvStorage	要删除的CRspQryHostEnvStorage
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CRspQryHostEnvStorage *pRspQryHostEnvStorage, bool bNoTransaction);
/*
	///检查某个CRspQryHostEnvStorage是否属于本对象工厂
	///@param	pRspQryHostEnvStorage	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CRspQryHostEnvStorage *pRspQryHostEnvStorage);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于HostName+MonTime的索引
	CAVLTree *pSysHostNameIndex;
	
	
	///按照HostName检索时，存储的查询参数
	CTypeObjectIDType queryHostNameInSearchByHostName;
	
	///按照HostName检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByHostName;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	
	///加入前触发
	///@param	pRspQryHostEnvStorage	要加入的RspQryHostEnvStorage
	virtual void beforeAdd(CWriteableRspQryHostEnvStorage *pRspQryHostEnvStorage);
	
	///加入后触发
	///@param	pRspQryHostEnvStorage	已经加入的RspQryHostEnvStorage
	virtual void afterAdd(CRspQryHostEnvStorage *pRspQryHostEnvStorage);

	///更新前触发	
	///@param	pRspQryHostEnvStorage	被刷新的CRspQryHostEnvStorage
	///@param	pNewRspQryHostEnvStorage	新的值
	virtual void beforeUpdate(CRspQryHostEnvStorage *pRspQryHostEnvStorage, CWriteableRspQryHostEnvStorage *pNewRspQryHostEnvStorage);
	
	///更新后触发
	///@param	pRspQryHostEnvStorage	被刷新的CRspQryHostEnvStorage
	virtual void afterUpdate(CRspQryHostEnvStorage *pRspQryHostEnvStorage);
	
	///删除前触发
	///@param	pRspQryHostEnvStorage	要删除的CRspQryHostEnvStorage
	virtual void beforeRemove(CRspQryHostEnvStorage *pRspQryHostEnvStorage);
	
	///确认加入后触发
	///@param	pRspQryHostEnvStorage	已经加入的RspQryHostEnvStorage
	virtual void commitAdd(CRspQryHostEnvStorage *pRspQryHostEnvStorage);

	///确认更新后触发
	///@param	pRspQryHostEnvStorage	被刷新的CRspQryHostEnvStorage
	///@param	poldRspQryHostEnvStorage	原来的值
	virtual void commitUpdate(CRspQryHostEnvStorage *pRspQryHostEnvStorage, CWriteableRspQryHostEnvStorage *pOldRspQryHostEnvStorage);
	
	///确认删除后触发
	///@param	pRspQryHostEnvStorage	已经删除的CRspQryHostEnvStorage
	virtual void commitRemove(CWriteableRspQryHostEnvStorage *pRspQryHostEnvStorage);

	///所有相关的触发器
	vector<CRspQryHostEnvStorageActionTrigger *> *pActionTriggers;
	vector<CRspQryHostEnvStorageCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableRspQryHostEnvStorage compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvIOFactory是一个主机环境IO设备信息的对象工厂。它包含了一批主机环境IO设备信息，
///同时又建立了如下索引，以方便查询：
///	SysHostNameIndex
///使用本对象工厂，可以完成对主机环境IO设备信息的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByHostName，findNextByHostName和endFindByHostName完成查询操作
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvIOFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CRspQryHostEnvIOFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxRspQryHostEnvIO，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CRspQryHostEnvIOFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CRspQryHostEnvIOFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的RspQryHostEnvIO
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的RspQryHostEnvIO，文件名将根据配置文件中的定义RspQryHostEnvIOCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的RspQryHostEnvIO
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的RspQryHostEnvIO，文件名将根据配置文件中的定义RspQryHostEnvIOCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CRspQryHostEnvIOResource;

	///将一个CRspQryHostEnvIO加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pRspQryHostEnvIO	要加入的RspQryHostEnvIO
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CRspQryHostEnvIO *add(CWriteableRspQryHostEnvIO *pRspQryHostEnvIO, CTransaction *pTransaction=NULL);
	
	///刷新该CRspQryHostEnvIO的值
	///@param	pRspQryHostEnvIO	被刷新的CRspQryHostEnvIO
	///@param	pNewRspQryHostEnvIO	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CRspQryHostEnvIO *pRspQryHostEnvIO, CWriteableRspQryHostEnvIO *pNewRspQryHostEnvIO, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pRspQryHostEnvIO	  需要被刷新或者新增的CRspQryHostEnvIO,等于NULL表示是需要新增的
	///@param	pNewRspQryHostEnvIO	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CRspQryHostEnvIO* addOrUpdate(CRspQryHostEnvIO *pRspQryHostEnvIO, CWriteableRspQryHostEnvIO *pNewRspQryHostEnvIO, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CRspQryHostEnvIO，同时删除其索引
	///@param	pRspQryHostEnvIO	要删除的CRspQryHostEnvIO
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CRspQryHostEnvIO *pRspQryHostEnvIO, CTransaction *pTransaction=NULL);
	
	///获取某个CRspQryHostEnvIO
	///@param	pRspQryHostEnvIO	要读取的CRspQryHostEnvIO
	///@param	pTragetRspQryHostEnvIO	存放结果的CRspQryHostEnvIO
	void retrieve(CRspQryHostEnvIO *pRspQryHostEnvIO, CWriteableRspQryHostEnvIO *pTargetRspQryHostEnvIO);
	
	///获取第一个CRspQryHostEnvIO
	///@return	得到的第一个CRspQryHostEnvIO，如果没有，则返回NULL
	CRspQryHostEnvIO *getFirst(void);
	
	///获取下一个CRspQryHostEnvIO
	///@return	得到下一个CRspQryHostEnvIO，如果没有，则返回NULL
	CRspQryHostEnvIO *getNext(void);
	
	///结束获取CRspQryHostEnvIO
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CRspQryHostEnvIOActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CRspQryHostEnvIOActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CRspQryHostEnvIOCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CRspQryHostEnvIOCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CRspQryHostEnvIOIteratorByHostName;

	///开始寻找CRspQryHostEnvIO
	///@param	HostName	
	///@return	满足条件的地一个CRspQryHostEnvIO，如果找不到，返回NULL
	CRspQryHostEnvIO *startFindByHostName( const CReadOnlyTypeObjectIDType& HostName);

	///寻找下一个符合条件的CRspQryHostEnvIO，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CRspQryHostEnvIO，如果已经没有一个满足要求了，则返回NULL
	CRspQryHostEnvIO *findNextByHostName(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByHostName(void);

	friend class CRspQryHostEnvIOIteratorBytheAll;

	///开始寻找CRspQryHostEnvIO
	///@return	满足条件的地一个CRspQryHostEnvIO，如果找不到，返回NULL
	CRspQryHostEnvIO *startFindBytheAll();

	///寻找下一个符合条件的CRspQryHostEnvIO，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CRspQryHostEnvIO，如果已经没有一个满足要求了，则返回NULL
	CRspQryHostEnvIO *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CRspQryHostEnvIO加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pRspQryHostEnvIO	要加入的RspQryHostEnvIO
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CRspQryHostEnvIO *internalAdd(CWriteableRspQryHostEnvIO *pRspQryHostEnvIO, bool bNoTransaction);
	
	
	///刷新该CRspQryHostEnvIO的键值
	///@param	pRspQryHostEnvIO	被刷新的CRspQryHostEnvIO
	///@param	pNewRspQryHostEnvIO	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CRspQryHostEnvIO *pRspQryHostEnvIO, CWriteableRspQryHostEnvIO *pNewRspQryHostEnvIO, bool updateIndex,bool bNoTransaction);
	
	///删除一个CRspQryHostEnvIO，同时删除其索引
	///@param	pRspQryHostEnvIO	要删除的CRspQryHostEnvIO
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CRspQryHostEnvIO *pRspQryHostEnvIO, bool bNoTransaction);
/*
	///检查某个CRspQryHostEnvIO是否属于本对象工厂
	///@param	pRspQryHostEnvIO	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CRspQryHostEnvIO *pRspQryHostEnvIO);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于HostName+MonTime的索引
	CAVLTree *pSysHostNameIndex;
	
	
	///按照HostName检索时，存储的查询参数
	CTypeObjectIDType queryHostNameInSearchByHostName;
	
	///按照HostName检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByHostName;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	
	///加入前触发
	///@param	pRspQryHostEnvIO	要加入的RspQryHostEnvIO
	virtual void beforeAdd(CWriteableRspQryHostEnvIO *pRspQryHostEnvIO);
	
	///加入后触发
	///@param	pRspQryHostEnvIO	已经加入的RspQryHostEnvIO
	virtual void afterAdd(CRspQryHostEnvIO *pRspQryHostEnvIO);

	///更新前触发	
	///@param	pRspQryHostEnvIO	被刷新的CRspQryHostEnvIO
	///@param	pNewRspQryHostEnvIO	新的值
	virtual void beforeUpdate(CRspQryHostEnvIO *pRspQryHostEnvIO, CWriteableRspQryHostEnvIO *pNewRspQryHostEnvIO);
	
	///更新后触发
	///@param	pRspQryHostEnvIO	被刷新的CRspQryHostEnvIO
	virtual void afterUpdate(CRspQryHostEnvIO *pRspQryHostEnvIO);
	
	///删除前触发
	///@param	pRspQryHostEnvIO	要删除的CRspQryHostEnvIO
	virtual void beforeRemove(CRspQryHostEnvIO *pRspQryHostEnvIO);
	
	///确认加入后触发
	///@param	pRspQryHostEnvIO	已经加入的RspQryHostEnvIO
	virtual void commitAdd(CRspQryHostEnvIO *pRspQryHostEnvIO);

	///确认更新后触发
	///@param	pRspQryHostEnvIO	被刷新的CRspQryHostEnvIO
	///@param	poldRspQryHostEnvIO	原来的值
	virtual void commitUpdate(CRspQryHostEnvIO *pRspQryHostEnvIO, CWriteableRspQryHostEnvIO *pOldRspQryHostEnvIO);
	
	///确认删除后触发
	///@param	pRspQryHostEnvIO	已经删除的CRspQryHostEnvIO
	virtual void commitRemove(CWriteableRspQryHostEnvIO *pRspQryHostEnvIO);

	///所有相关的触发器
	vector<CRspQryHostEnvIOActionTrigger *> *pActionTriggers;
	vector<CRspQryHostEnvIOCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableRspQryHostEnvIO compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvFSFactory是一个主机环境文件系统信息的对象工厂。它包含了一批主机环境文件系统信息，
///同时又建立了如下索引，以方便查询：
///	SysHostNameIndex
///使用本对象工厂，可以完成对主机环境文件系统信息的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByHostName，findNextByHostName和endFindByHostName完成查询操作
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvFSFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CRspQryHostEnvFSFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxRspQryHostEnvFS，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CRspQryHostEnvFSFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CRspQryHostEnvFSFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的RspQryHostEnvFS
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的RspQryHostEnvFS，文件名将根据配置文件中的定义RspQryHostEnvFSCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的RspQryHostEnvFS
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的RspQryHostEnvFS，文件名将根据配置文件中的定义RspQryHostEnvFSCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CRspQryHostEnvFSResource;

	///将一个CRspQryHostEnvFS加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pRspQryHostEnvFS	要加入的RspQryHostEnvFS
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CRspQryHostEnvFS *add(CWriteableRspQryHostEnvFS *pRspQryHostEnvFS, CTransaction *pTransaction=NULL);
	
	///刷新该CRspQryHostEnvFS的值
	///@param	pRspQryHostEnvFS	被刷新的CRspQryHostEnvFS
	///@param	pNewRspQryHostEnvFS	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CRspQryHostEnvFS *pRspQryHostEnvFS, CWriteableRspQryHostEnvFS *pNewRspQryHostEnvFS, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pRspQryHostEnvFS	  需要被刷新或者新增的CRspQryHostEnvFS,等于NULL表示是需要新增的
	///@param	pNewRspQryHostEnvFS	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CRspQryHostEnvFS* addOrUpdate(CRspQryHostEnvFS *pRspQryHostEnvFS, CWriteableRspQryHostEnvFS *pNewRspQryHostEnvFS, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CRspQryHostEnvFS，同时删除其索引
	///@param	pRspQryHostEnvFS	要删除的CRspQryHostEnvFS
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CRspQryHostEnvFS *pRspQryHostEnvFS, CTransaction *pTransaction=NULL);
	
	///获取某个CRspQryHostEnvFS
	///@param	pRspQryHostEnvFS	要读取的CRspQryHostEnvFS
	///@param	pTragetRspQryHostEnvFS	存放结果的CRspQryHostEnvFS
	void retrieve(CRspQryHostEnvFS *pRspQryHostEnvFS, CWriteableRspQryHostEnvFS *pTargetRspQryHostEnvFS);
	
	///获取第一个CRspQryHostEnvFS
	///@return	得到的第一个CRspQryHostEnvFS，如果没有，则返回NULL
	CRspQryHostEnvFS *getFirst(void);
	
	///获取下一个CRspQryHostEnvFS
	///@return	得到下一个CRspQryHostEnvFS，如果没有，则返回NULL
	CRspQryHostEnvFS *getNext(void);
	
	///结束获取CRspQryHostEnvFS
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CRspQryHostEnvFSActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CRspQryHostEnvFSActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CRspQryHostEnvFSCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CRspQryHostEnvFSCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CRspQryHostEnvFSIteratorByHostName;

	///开始寻找CRspQryHostEnvFS
	///@param	HostName	
	///@return	满足条件的地一个CRspQryHostEnvFS，如果找不到，返回NULL
	CRspQryHostEnvFS *startFindByHostName( const CReadOnlyTypeObjectIDType& HostName);

	///寻找下一个符合条件的CRspQryHostEnvFS，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CRspQryHostEnvFS，如果已经没有一个满足要求了，则返回NULL
	CRspQryHostEnvFS *findNextByHostName(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByHostName(void);

	friend class CRspQryHostEnvFSIteratorBytheAll;

	///开始寻找CRspQryHostEnvFS
	///@return	满足条件的地一个CRspQryHostEnvFS，如果找不到，返回NULL
	CRspQryHostEnvFS *startFindBytheAll();

	///寻找下一个符合条件的CRspQryHostEnvFS，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CRspQryHostEnvFS，如果已经没有一个满足要求了，则返回NULL
	CRspQryHostEnvFS *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CRspQryHostEnvFS加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pRspQryHostEnvFS	要加入的RspQryHostEnvFS
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CRspQryHostEnvFS *internalAdd(CWriteableRspQryHostEnvFS *pRspQryHostEnvFS, bool bNoTransaction);
	
	
	///刷新该CRspQryHostEnvFS的键值
	///@param	pRspQryHostEnvFS	被刷新的CRspQryHostEnvFS
	///@param	pNewRspQryHostEnvFS	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CRspQryHostEnvFS *pRspQryHostEnvFS, CWriteableRspQryHostEnvFS *pNewRspQryHostEnvFS, bool updateIndex,bool bNoTransaction);
	
	///删除一个CRspQryHostEnvFS，同时删除其索引
	///@param	pRspQryHostEnvFS	要删除的CRspQryHostEnvFS
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CRspQryHostEnvFS *pRspQryHostEnvFS, bool bNoTransaction);
/*
	///检查某个CRspQryHostEnvFS是否属于本对象工厂
	///@param	pRspQryHostEnvFS	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CRspQryHostEnvFS *pRspQryHostEnvFS);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于HostName+MonTime的索引
	CAVLTree *pSysHostNameIndex;
	
	
	///按照HostName检索时，存储的查询参数
	CTypeObjectIDType queryHostNameInSearchByHostName;
	
	///按照HostName检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByHostName;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	
	///加入前触发
	///@param	pRspQryHostEnvFS	要加入的RspQryHostEnvFS
	virtual void beforeAdd(CWriteableRspQryHostEnvFS *pRspQryHostEnvFS);
	
	///加入后触发
	///@param	pRspQryHostEnvFS	已经加入的RspQryHostEnvFS
	virtual void afterAdd(CRspQryHostEnvFS *pRspQryHostEnvFS);

	///更新前触发	
	///@param	pRspQryHostEnvFS	被刷新的CRspQryHostEnvFS
	///@param	pNewRspQryHostEnvFS	新的值
	virtual void beforeUpdate(CRspQryHostEnvFS *pRspQryHostEnvFS, CWriteableRspQryHostEnvFS *pNewRspQryHostEnvFS);
	
	///更新后触发
	///@param	pRspQryHostEnvFS	被刷新的CRspQryHostEnvFS
	virtual void afterUpdate(CRspQryHostEnvFS *pRspQryHostEnvFS);
	
	///删除前触发
	///@param	pRspQryHostEnvFS	要删除的CRspQryHostEnvFS
	virtual void beforeRemove(CRspQryHostEnvFS *pRspQryHostEnvFS);
	
	///确认加入后触发
	///@param	pRspQryHostEnvFS	已经加入的RspQryHostEnvFS
	virtual void commitAdd(CRspQryHostEnvFS *pRspQryHostEnvFS);

	///确认更新后触发
	///@param	pRspQryHostEnvFS	被刷新的CRspQryHostEnvFS
	///@param	poldRspQryHostEnvFS	原来的值
	virtual void commitUpdate(CRspQryHostEnvFS *pRspQryHostEnvFS, CWriteableRspQryHostEnvFS *pOldRspQryHostEnvFS);
	
	///确认删除后触发
	///@param	pRspQryHostEnvFS	已经删除的CRspQryHostEnvFS
	virtual void commitRemove(CWriteableRspQryHostEnvFS *pRspQryHostEnvFS);

	///所有相关的触发器
	vector<CRspQryHostEnvFSActionTrigger *> *pActionTriggers;
	vector<CRspQryHostEnvFSCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableRspQryHostEnvFS compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvSwapFactory是一个主机环境交换分区信息的对象工厂。它包含了一批主机环境交换分区信息，
///同时又建立了如下索引，以方便查询：
///	SysHostNameIndex
///使用本对象工厂，可以完成对主机环境交换分区信息的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByHostName，findNextByHostName和endFindByHostName完成查询操作
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvSwapFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CRspQryHostEnvSwapFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxRspQryHostEnvSwap，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CRspQryHostEnvSwapFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CRspQryHostEnvSwapFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的RspQryHostEnvSwap
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的RspQryHostEnvSwap，文件名将根据配置文件中的定义RspQryHostEnvSwapCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的RspQryHostEnvSwap
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的RspQryHostEnvSwap，文件名将根据配置文件中的定义RspQryHostEnvSwapCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CRspQryHostEnvSwapResource;

	///将一个CRspQryHostEnvSwap加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pRspQryHostEnvSwap	要加入的RspQryHostEnvSwap
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CRspQryHostEnvSwap *add(CWriteableRspQryHostEnvSwap *pRspQryHostEnvSwap, CTransaction *pTransaction=NULL);
	
	///刷新该CRspQryHostEnvSwap的值
	///@param	pRspQryHostEnvSwap	被刷新的CRspQryHostEnvSwap
	///@param	pNewRspQryHostEnvSwap	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CRspQryHostEnvSwap *pRspQryHostEnvSwap, CWriteableRspQryHostEnvSwap *pNewRspQryHostEnvSwap, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pRspQryHostEnvSwap	  需要被刷新或者新增的CRspQryHostEnvSwap,等于NULL表示是需要新增的
	///@param	pNewRspQryHostEnvSwap	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CRspQryHostEnvSwap* addOrUpdate(CRspQryHostEnvSwap *pRspQryHostEnvSwap, CWriteableRspQryHostEnvSwap *pNewRspQryHostEnvSwap, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CRspQryHostEnvSwap，同时删除其索引
	///@param	pRspQryHostEnvSwap	要删除的CRspQryHostEnvSwap
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CRspQryHostEnvSwap *pRspQryHostEnvSwap, CTransaction *pTransaction=NULL);
	
	///获取某个CRspQryHostEnvSwap
	///@param	pRspQryHostEnvSwap	要读取的CRspQryHostEnvSwap
	///@param	pTragetRspQryHostEnvSwap	存放结果的CRspQryHostEnvSwap
	void retrieve(CRspQryHostEnvSwap *pRspQryHostEnvSwap, CWriteableRspQryHostEnvSwap *pTargetRspQryHostEnvSwap);
	
	///获取第一个CRspQryHostEnvSwap
	///@return	得到的第一个CRspQryHostEnvSwap，如果没有，则返回NULL
	CRspQryHostEnvSwap *getFirst(void);
	
	///获取下一个CRspQryHostEnvSwap
	///@return	得到下一个CRspQryHostEnvSwap，如果没有，则返回NULL
	CRspQryHostEnvSwap *getNext(void);
	
	///结束获取CRspQryHostEnvSwap
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CRspQryHostEnvSwapActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CRspQryHostEnvSwapActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CRspQryHostEnvSwapCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CRspQryHostEnvSwapCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CRspQryHostEnvSwapIteratorByHostName;

	///开始寻找CRspQryHostEnvSwap
	///@param	HostName	
	///@return	满足条件的地一个CRspQryHostEnvSwap，如果找不到，返回NULL
	CRspQryHostEnvSwap *startFindByHostName( const CReadOnlyTypeObjectIDType& HostName);

	///寻找下一个符合条件的CRspQryHostEnvSwap，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CRspQryHostEnvSwap，如果已经没有一个满足要求了，则返回NULL
	CRspQryHostEnvSwap *findNextByHostName(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByHostName(void);

	friend class CRspQryHostEnvSwapIteratorBytheAll;

	///开始寻找CRspQryHostEnvSwap
	///@return	满足条件的地一个CRspQryHostEnvSwap，如果找不到，返回NULL
	CRspQryHostEnvSwap *startFindBytheAll();

	///寻找下一个符合条件的CRspQryHostEnvSwap，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CRspQryHostEnvSwap，如果已经没有一个满足要求了，则返回NULL
	CRspQryHostEnvSwap *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CRspQryHostEnvSwap加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pRspQryHostEnvSwap	要加入的RspQryHostEnvSwap
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CRspQryHostEnvSwap *internalAdd(CWriteableRspQryHostEnvSwap *pRspQryHostEnvSwap, bool bNoTransaction);
	
	
	///刷新该CRspQryHostEnvSwap的键值
	///@param	pRspQryHostEnvSwap	被刷新的CRspQryHostEnvSwap
	///@param	pNewRspQryHostEnvSwap	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CRspQryHostEnvSwap *pRspQryHostEnvSwap, CWriteableRspQryHostEnvSwap *pNewRspQryHostEnvSwap, bool updateIndex,bool bNoTransaction);
	
	///删除一个CRspQryHostEnvSwap，同时删除其索引
	///@param	pRspQryHostEnvSwap	要删除的CRspQryHostEnvSwap
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CRspQryHostEnvSwap *pRspQryHostEnvSwap, bool bNoTransaction);
/*
	///检查某个CRspQryHostEnvSwap是否属于本对象工厂
	///@param	pRspQryHostEnvSwap	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CRspQryHostEnvSwap *pRspQryHostEnvSwap);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于HostName+MonTime的索引
	CAVLTree *pSysHostNameIndex;
	
	
	///按照HostName检索时，存储的查询参数
	CTypeObjectIDType queryHostNameInSearchByHostName;
	
	///按照HostName检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByHostName;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	
	///加入前触发
	///@param	pRspQryHostEnvSwap	要加入的RspQryHostEnvSwap
	virtual void beforeAdd(CWriteableRspQryHostEnvSwap *pRspQryHostEnvSwap);
	
	///加入后触发
	///@param	pRspQryHostEnvSwap	已经加入的RspQryHostEnvSwap
	virtual void afterAdd(CRspQryHostEnvSwap *pRspQryHostEnvSwap);

	///更新前触发	
	///@param	pRspQryHostEnvSwap	被刷新的CRspQryHostEnvSwap
	///@param	pNewRspQryHostEnvSwap	新的值
	virtual void beforeUpdate(CRspQryHostEnvSwap *pRspQryHostEnvSwap, CWriteableRspQryHostEnvSwap *pNewRspQryHostEnvSwap);
	
	///更新后触发
	///@param	pRspQryHostEnvSwap	被刷新的CRspQryHostEnvSwap
	virtual void afterUpdate(CRspQryHostEnvSwap *pRspQryHostEnvSwap);
	
	///删除前触发
	///@param	pRspQryHostEnvSwap	要删除的CRspQryHostEnvSwap
	virtual void beforeRemove(CRspQryHostEnvSwap *pRspQryHostEnvSwap);
	
	///确认加入后触发
	///@param	pRspQryHostEnvSwap	已经加入的RspQryHostEnvSwap
	virtual void commitAdd(CRspQryHostEnvSwap *pRspQryHostEnvSwap);

	///确认更新后触发
	///@param	pRspQryHostEnvSwap	被刷新的CRspQryHostEnvSwap
	///@param	poldRspQryHostEnvSwap	原来的值
	virtual void commitUpdate(CRspQryHostEnvSwap *pRspQryHostEnvSwap, CWriteableRspQryHostEnvSwap *pOldRspQryHostEnvSwap);
	
	///确认删除后触发
	///@param	pRspQryHostEnvSwap	已经删除的CRspQryHostEnvSwap
	virtual void commitRemove(CWriteableRspQryHostEnvSwap *pRspQryHostEnvSwap);

	///所有相关的触发器
	vector<CRspQryHostEnvSwapActionTrigger *> *pActionTriggers;
	vector<CRspQryHostEnvSwapCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableRspQryHostEnvSwap compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCfgFactory是一个主机环境网卡配置信息的对象工厂。它包含了一批主机环境网卡配置信息，
///同时又建立了如下索引，以方便查询：
///	SysHostNameIndex
///使用本对象工厂，可以完成对主机环境网卡配置信息的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByHostName，findNextByHostName和endFindByHostName完成查询操作
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCfgFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CRspQryHostEnvLanCfgFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxRspQryHostEnvLanCfg，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CRspQryHostEnvLanCfgFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CRspQryHostEnvLanCfgFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的RspQryHostEnvLanCfg
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的RspQryHostEnvLanCfg，文件名将根据配置文件中的定义RspQryHostEnvLanCfgCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的RspQryHostEnvLanCfg
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的RspQryHostEnvLanCfg，文件名将根据配置文件中的定义RspQryHostEnvLanCfgCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CRspQryHostEnvLanCfgResource;

	///将一个CRspQryHostEnvLanCfg加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pRspQryHostEnvLanCfg	要加入的RspQryHostEnvLanCfg
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CRspQryHostEnvLanCfg *add(CWriteableRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg, CTransaction *pTransaction=NULL);
	
	///刷新该CRspQryHostEnvLanCfg的值
	///@param	pRspQryHostEnvLanCfg	被刷新的CRspQryHostEnvLanCfg
	///@param	pNewRspQryHostEnvLanCfg	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg, CWriteableRspQryHostEnvLanCfg *pNewRspQryHostEnvLanCfg, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pRspQryHostEnvLanCfg	  需要被刷新或者新增的CRspQryHostEnvLanCfg,等于NULL表示是需要新增的
	///@param	pNewRspQryHostEnvLanCfg	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CRspQryHostEnvLanCfg* addOrUpdate(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg, CWriteableRspQryHostEnvLanCfg *pNewRspQryHostEnvLanCfg, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CRspQryHostEnvLanCfg，同时删除其索引
	///@param	pRspQryHostEnvLanCfg	要删除的CRspQryHostEnvLanCfg
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg, CTransaction *pTransaction=NULL);
	
	///获取某个CRspQryHostEnvLanCfg
	///@param	pRspQryHostEnvLanCfg	要读取的CRspQryHostEnvLanCfg
	///@param	pTragetRspQryHostEnvLanCfg	存放结果的CRspQryHostEnvLanCfg
	void retrieve(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg, CWriteableRspQryHostEnvLanCfg *pTargetRspQryHostEnvLanCfg);
	
	///获取第一个CRspQryHostEnvLanCfg
	///@return	得到的第一个CRspQryHostEnvLanCfg，如果没有，则返回NULL
	CRspQryHostEnvLanCfg *getFirst(void);
	
	///获取下一个CRspQryHostEnvLanCfg
	///@return	得到下一个CRspQryHostEnvLanCfg，如果没有，则返回NULL
	CRspQryHostEnvLanCfg *getNext(void);
	
	///结束获取CRspQryHostEnvLanCfg
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CRspQryHostEnvLanCfgActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CRspQryHostEnvLanCfgActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CRspQryHostEnvLanCfgCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CRspQryHostEnvLanCfgCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CRspQryHostEnvLanCfgIteratorByHostName;

	///开始寻找CRspQryHostEnvLanCfg
	///@param	HostName	
	///@return	满足条件的地一个CRspQryHostEnvLanCfg，如果找不到，返回NULL
	CRspQryHostEnvLanCfg *startFindByHostName( const CReadOnlyTypeObjectIDType& HostName);

	///寻找下一个符合条件的CRspQryHostEnvLanCfg，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CRspQryHostEnvLanCfg，如果已经没有一个满足要求了，则返回NULL
	CRspQryHostEnvLanCfg *findNextByHostName(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByHostName(void);

	friend class CRspQryHostEnvLanCfgIteratorBytheAll;

	///开始寻找CRspQryHostEnvLanCfg
	///@return	满足条件的地一个CRspQryHostEnvLanCfg，如果找不到，返回NULL
	CRspQryHostEnvLanCfg *startFindBytheAll();

	///寻找下一个符合条件的CRspQryHostEnvLanCfg，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CRspQryHostEnvLanCfg，如果已经没有一个满足要求了，则返回NULL
	CRspQryHostEnvLanCfg *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CRspQryHostEnvLanCfg加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pRspQryHostEnvLanCfg	要加入的RspQryHostEnvLanCfg
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CRspQryHostEnvLanCfg *internalAdd(CWriteableRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg, bool bNoTransaction);
	
	
	///刷新该CRspQryHostEnvLanCfg的键值
	///@param	pRspQryHostEnvLanCfg	被刷新的CRspQryHostEnvLanCfg
	///@param	pNewRspQryHostEnvLanCfg	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg, CWriteableRspQryHostEnvLanCfg *pNewRspQryHostEnvLanCfg, bool updateIndex,bool bNoTransaction);
	
	///删除一个CRspQryHostEnvLanCfg，同时删除其索引
	///@param	pRspQryHostEnvLanCfg	要删除的CRspQryHostEnvLanCfg
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg, bool bNoTransaction);
/*
	///检查某个CRspQryHostEnvLanCfg是否属于本对象工厂
	///@param	pRspQryHostEnvLanCfg	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于HostName+MonTime的索引
	CAVLTree *pSysHostNameIndex;
	
	
	///按照HostName检索时，存储的查询参数
	CTypeObjectIDType queryHostNameInSearchByHostName;
	
	///按照HostName检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByHostName;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	
	///加入前触发
	///@param	pRspQryHostEnvLanCfg	要加入的RspQryHostEnvLanCfg
	virtual void beforeAdd(CWriteableRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg);
	
	///加入后触发
	///@param	pRspQryHostEnvLanCfg	已经加入的RspQryHostEnvLanCfg
	virtual void afterAdd(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg);

	///更新前触发	
	///@param	pRspQryHostEnvLanCfg	被刷新的CRspQryHostEnvLanCfg
	///@param	pNewRspQryHostEnvLanCfg	新的值
	virtual void beforeUpdate(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg, CWriteableRspQryHostEnvLanCfg *pNewRspQryHostEnvLanCfg);
	
	///更新后触发
	///@param	pRspQryHostEnvLanCfg	被刷新的CRspQryHostEnvLanCfg
	virtual void afterUpdate(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg);
	
	///删除前触发
	///@param	pRspQryHostEnvLanCfg	要删除的CRspQryHostEnvLanCfg
	virtual void beforeRemove(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg);
	
	///确认加入后触发
	///@param	pRspQryHostEnvLanCfg	已经加入的RspQryHostEnvLanCfg
	virtual void commitAdd(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg);

	///确认更新后触发
	///@param	pRspQryHostEnvLanCfg	被刷新的CRspQryHostEnvLanCfg
	///@param	poldRspQryHostEnvLanCfg	原来的值
	virtual void commitUpdate(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg, CWriteableRspQryHostEnvLanCfg *pOldRspQryHostEnvLanCfg);
	
	///确认删除后触发
	///@param	pRspQryHostEnvLanCfg	已经删除的CRspQryHostEnvLanCfg
	virtual void commitRemove(CWriteableRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg);

	///所有相关的触发器
	vector<CRspQryHostEnvLanCfgActionTrigger *> *pActionTriggers;
	vector<CRspQryHostEnvLanCfgCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableRspQryHostEnvLanCfg compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoFactory是一个CPU资源使用信息的对象工厂。它包含了一批CPU资源使用信息，
///同时又建立了如下索引，以方便查询：
///	SysHostNameIndex
///	DecIndex
///使用本对象工厂，可以完成对CPU资源使用信息的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByHostName，findNextByHostName和endFindByHostName完成查询操作
///		使用startFindByDsc，findNextByDsc和endFindByDsc完成查询操作
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///		使用startFindByDataDelete，findNextByDataDelete和endFindByDataDelete完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbTopCpuInfoFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysMdbTopCpuInfo，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbTopCpuInfoFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbTopCpuInfoFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysMdbTopCpuInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysMdbTopCpuInfo，文件名将根据配置文件中的定义SysMdbTopCpuInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysMdbTopCpuInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysMdbTopCpuInfo，文件名将根据配置文件中的定义SysMdbTopCpuInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysMdbTopCpuInfoResource;

	///将一个CSysMdbTopCpuInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbTopCpuInfo	要加入的SysMdbTopCpuInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbTopCpuInfo *add(CWriteableSysMdbTopCpuInfo *pSysMdbTopCpuInfo, CTransaction *pTransaction=NULL);
	
	///刷新该CSysMdbTopCpuInfo的值
	///@param	pSysMdbTopCpuInfo	被刷新的CSysMdbTopCpuInfo
	///@param	pNewSysMdbTopCpuInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo, CWriteableSysMdbTopCpuInfo *pNewSysMdbTopCpuInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysMdbTopCpuInfo	  需要被刷新或者新增的CSysMdbTopCpuInfo,等于NULL表示是需要新增的
	///@param	pNewSysMdbTopCpuInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysMdbTopCpuInfo* addOrUpdate(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo, CWriteableSysMdbTopCpuInfo *pNewSysMdbTopCpuInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysMdbTopCpuInfo，同时删除其索引
	///@param	pSysMdbTopCpuInfo	要删除的CSysMdbTopCpuInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo, CTransaction *pTransaction=NULL);
	
	///获取某个CSysMdbTopCpuInfo
	///@param	pSysMdbTopCpuInfo	要读取的CSysMdbTopCpuInfo
	///@param	pTragetSysMdbTopCpuInfo	存放结果的CSysMdbTopCpuInfo
	void retrieve(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo, CWriteableSysMdbTopCpuInfo *pTargetSysMdbTopCpuInfo);
	
	///获取第一个CSysMdbTopCpuInfo
	///@return	得到的第一个CSysMdbTopCpuInfo，如果没有，则返回NULL
	CSysMdbTopCpuInfo *getFirst(void);
	
	///获取下一个CSysMdbTopCpuInfo
	///@return	得到下一个CSysMdbTopCpuInfo，如果没有，则返回NULL
	CSysMdbTopCpuInfo *getNext(void);
	
	///结束获取CSysMdbTopCpuInfo
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysMdbTopCpuInfoActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysMdbTopCpuInfoActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysMdbTopCpuInfoCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysMdbTopCpuInfoCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysMdbTopCpuInfoIteratorByHostName;

	///开始寻找CSysMdbTopCpuInfo
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	///@return	满足条件的地一个CSysMdbTopCpuInfo，如果找不到，返回NULL
	CSysMdbTopCpuInfo *startFindByHostName( const CReadOnlyVolumeType& HostName,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysMdbTopCpuInfo，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CSysMdbTopCpuInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbTopCpuInfo *findNextByHostName(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByHostName(void);

	friend class CSysMdbTopCpuInfoIteratorByDsc;

	///开始寻找CSysMdbTopCpuInfo
	///@param	HostName	
	///@return	满足条件的地一个CSysMdbTopCpuInfo，如果找不到，返回NULL
	CSysMdbTopCpuInfo *startFindByDsc( const CReadOnlyVolumeType& HostName);

	///寻找下一个符合条件的CSysMdbTopCpuInfo，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbTopCpuInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbTopCpuInfo *findNextByDsc(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDsc(void);

	friend class CSysMdbTopCpuInfoIteratorBytheAll;

	///开始寻找CSysMdbTopCpuInfo
	///@return	满足条件的地一个CSysMdbTopCpuInfo，如果找不到，返回NULL
	CSysMdbTopCpuInfo *startFindBytheAll();

	///寻找下一个符合条件的CSysMdbTopCpuInfo，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbTopCpuInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbTopCpuInfo *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

	friend class CSysMdbTopCpuInfoIteratorByDataDelete;

	///开始寻找CSysMdbTopCpuInfo
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	///@return	满足条件的地一个CSysMdbTopCpuInfo，如果找不到，返回NULL
	CSysMdbTopCpuInfo *startFindByDataDelete( const CReadOnlyVolumeType& HostName,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysMdbTopCpuInfo，必须在startFindByDataDelete以后，endFindByDataDelete之前叫用
	///@return	下一个满足条件CSysMdbTopCpuInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbTopCpuInfo *findNextByDataDelete(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDataDelete(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysMdbTopCpuInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbTopCpuInfo	要加入的SysMdbTopCpuInfo
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbTopCpuInfo *internalAdd(CWriteableSysMdbTopCpuInfo *pSysMdbTopCpuInfo, bool bNoTransaction);
	
	
	///刷新该CSysMdbTopCpuInfo的键值
	///@param	pSysMdbTopCpuInfo	被刷新的CSysMdbTopCpuInfo
	///@param	pNewSysMdbTopCpuInfo	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo, CWriteableSysMdbTopCpuInfo *pNewSysMdbTopCpuInfo, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysMdbTopCpuInfo，同时删除其索引
	///@param	pSysMdbTopCpuInfo	要删除的CSysMdbTopCpuInfo
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo, bool bNoTransaction);
/*
	///检查某个CSysMdbTopCpuInfo是否属于本对象工厂
	///@param	pSysMdbTopCpuInfo	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于HostName+MonDate+MonTime的索引
	CAVLTree *pSysHostNameIndex;
	///基于HostName+MonDate+MonTime的索引
	CAVLTree *pDecIndex;
	
	
	///按照HostName，MonDate，MonTime检索时，存储的查询参数
	CVolumeType queryHostNameInSearchByHostName;
	CDateType queryMonDateInSearchByHostName;
	CTimeType queryMonTimeInSearchByHostName;
	
	///按照HostName，MonDate，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByHostName;
	///按照HostName检索时，存储的查询参数
	CVolumeType queryHostNameInSearchByDsc;
	
	///按照HostName检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDsc;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	///按照HostName，MonDate，MonTime检索时，存储的查询参数
	CVolumeType queryHostNameInSearchByDataDelete;
	CDateType queryMonDateInSearchByDataDelete;
	CTimeType queryMonTimeInSearchByDataDelete;
	
	///按照HostName，MonDate，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDataDelete;
	
	///加入前触发
	///@param	pSysMdbTopCpuInfo	要加入的SysMdbTopCpuInfo
	virtual void beforeAdd(CWriteableSysMdbTopCpuInfo *pSysMdbTopCpuInfo);
	
	///加入后触发
	///@param	pSysMdbTopCpuInfo	已经加入的SysMdbTopCpuInfo
	virtual void afterAdd(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo);

	///更新前触发	
	///@param	pSysMdbTopCpuInfo	被刷新的CSysMdbTopCpuInfo
	///@param	pNewSysMdbTopCpuInfo	新的值
	virtual void beforeUpdate(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo, CWriteableSysMdbTopCpuInfo *pNewSysMdbTopCpuInfo);
	
	///更新后触发
	///@param	pSysMdbTopCpuInfo	被刷新的CSysMdbTopCpuInfo
	virtual void afterUpdate(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo);
	
	///删除前触发
	///@param	pSysMdbTopCpuInfo	要删除的CSysMdbTopCpuInfo
	virtual void beforeRemove(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo);
	
	///确认加入后触发
	///@param	pSysMdbTopCpuInfo	已经加入的SysMdbTopCpuInfo
	virtual void commitAdd(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo);

	///确认更新后触发
	///@param	pSysMdbTopCpuInfo	被刷新的CSysMdbTopCpuInfo
	///@param	poldSysMdbTopCpuInfo	原来的值
	virtual void commitUpdate(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo, CWriteableSysMdbTopCpuInfo *pOldSysMdbTopCpuInfo);
	
	///确认删除后触发
	///@param	pSysMdbTopCpuInfo	已经删除的CSysMdbTopCpuInfo
	virtual void commitRemove(CWriteableSysMdbTopCpuInfo *pSysMdbTopCpuInfo);

	///所有相关的触发器
	vector<CSysMdbTopCpuInfoActionTrigger *> *pActionTriggers;
	vector<CSysMdbTopCpuInfoCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysMdbTopCpuInfo compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoFactory是一个内存资源使用信息的对象工厂。它包含了一批内存资源使用信息，
///同时又建立了如下索引，以方便查询：
///	SysHostNameIndex
///	DecIndex
///使用本对象工厂，可以完成对内存资源使用信息的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByHostName，findNextByHostName和endFindByHostName完成查询操作
///		使用startFindByDsc，findNextByDsc和endFindByDsc完成查询操作
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///		使用startFindByDataDelete，findNextByDataDelete和endFindByDataDelete完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbTopMemInfoFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysMdbTopMemInfo，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbTopMemInfoFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbTopMemInfoFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysMdbTopMemInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysMdbTopMemInfo，文件名将根据配置文件中的定义SysMdbTopMemInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysMdbTopMemInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysMdbTopMemInfo，文件名将根据配置文件中的定义SysMdbTopMemInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysMdbTopMemInfoResource;

	///将一个CSysMdbTopMemInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbTopMemInfo	要加入的SysMdbTopMemInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbTopMemInfo *add(CWriteableSysMdbTopMemInfo *pSysMdbTopMemInfo, CTransaction *pTransaction=NULL);
	
	///刷新该CSysMdbTopMemInfo的值
	///@param	pSysMdbTopMemInfo	被刷新的CSysMdbTopMemInfo
	///@param	pNewSysMdbTopMemInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysMdbTopMemInfo *pSysMdbTopMemInfo, CWriteableSysMdbTopMemInfo *pNewSysMdbTopMemInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysMdbTopMemInfo	  需要被刷新或者新增的CSysMdbTopMemInfo,等于NULL表示是需要新增的
	///@param	pNewSysMdbTopMemInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysMdbTopMemInfo* addOrUpdate(CSysMdbTopMemInfo *pSysMdbTopMemInfo, CWriteableSysMdbTopMemInfo *pNewSysMdbTopMemInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysMdbTopMemInfo，同时删除其索引
	///@param	pSysMdbTopMemInfo	要删除的CSysMdbTopMemInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysMdbTopMemInfo *pSysMdbTopMemInfo, CTransaction *pTransaction=NULL);
	
	///获取某个CSysMdbTopMemInfo
	///@param	pSysMdbTopMemInfo	要读取的CSysMdbTopMemInfo
	///@param	pTragetSysMdbTopMemInfo	存放结果的CSysMdbTopMemInfo
	void retrieve(CSysMdbTopMemInfo *pSysMdbTopMemInfo, CWriteableSysMdbTopMemInfo *pTargetSysMdbTopMemInfo);
	
	///获取第一个CSysMdbTopMemInfo
	///@return	得到的第一个CSysMdbTopMemInfo，如果没有，则返回NULL
	CSysMdbTopMemInfo *getFirst(void);
	
	///获取下一个CSysMdbTopMemInfo
	///@return	得到下一个CSysMdbTopMemInfo，如果没有，则返回NULL
	CSysMdbTopMemInfo *getNext(void);
	
	///结束获取CSysMdbTopMemInfo
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysMdbTopMemInfoActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysMdbTopMemInfoActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysMdbTopMemInfoCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysMdbTopMemInfoCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysMdbTopMemInfoIteratorByHostName;

	///开始寻找CSysMdbTopMemInfo
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	///@return	满足条件的地一个CSysMdbTopMemInfo，如果找不到，返回NULL
	CSysMdbTopMemInfo *startFindByHostName( const CReadOnlyVolumeType& HostName,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysMdbTopMemInfo，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CSysMdbTopMemInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbTopMemInfo *findNextByHostName(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByHostName(void);

	friend class CSysMdbTopMemInfoIteratorByDsc;

	///开始寻找CSysMdbTopMemInfo
	///@param	HostName	
	///@return	满足条件的地一个CSysMdbTopMemInfo，如果找不到，返回NULL
	CSysMdbTopMemInfo *startFindByDsc( const CReadOnlyVolumeType& HostName);

	///寻找下一个符合条件的CSysMdbTopMemInfo，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbTopMemInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbTopMemInfo *findNextByDsc(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDsc(void);

	friend class CSysMdbTopMemInfoIteratorBytheAll;

	///开始寻找CSysMdbTopMemInfo
	///@return	满足条件的地一个CSysMdbTopMemInfo，如果找不到，返回NULL
	CSysMdbTopMemInfo *startFindBytheAll();

	///寻找下一个符合条件的CSysMdbTopMemInfo，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbTopMemInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbTopMemInfo *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

	friend class CSysMdbTopMemInfoIteratorByDataDelete;

	///开始寻找CSysMdbTopMemInfo
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	///@return	满足条件的地一个CSysMdbTopMemInfo，如果找不到，返回NULL
	CSysMdbTopMemInfo *startFindByDataDelete( const CReadOnlyVolumeType& HostName,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysMdbTopMemInfo，必须在startFindByDataDelete以后，endFindByDataDelete之前叫用
	///@return	下一个满足条件CSysMdbTopMemInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbTopMemInfo *findNextByDataDelete(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDataDelete(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysMdbTopMemInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbTopMemInfo	要加入的SysMdbTopMemInfo
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbTopMemInfo *internalAdd(CWriteableSysMdbTopMemInfo *pSysMdbTopMemInfo, bool bNoTransaction);
	
	
	///刷新该CSysMdbTopMemInfo的键值
	///@param	pSysMdbTopMemInfo	被刷新的CSysMdbTopMemInfo
	///@param	pNewSysMdbTopMemInfo	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysMdbTopMemInfo *pSysMdbTopMemInfo, CWriteableSysMdbTopMemInfo *pNewSysMdbTopMemInfo, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysMdbTopMemInfo，同时删除其索引
	///@param	pSysMdbTopMemInfo	要删除的CSysMdbTopMemInfo
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysMdbTopMemInfo *pSysMdbTopMemInfo, bool bNoTransaction);
/*
	///检查某个CSysMdbTopMemInfo是否属于本对象工厂
	///@param	pSysMdbTopMemInfo	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysMdbTopMemInfo *pSysMdbTopMemInfo);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于HostName+MonDate+MonTime的索引
	CAVLTree *pSysHostNameIndex;
	///基于HostName+MonDate+MonTime的索引
	CAVLTree *pDecIndex;
	
	
	///按照HostName，MonDate，MonTime检索时，存储的查询参数
	CVolumeType queryHostNameInSearchByHostName;
	CDateType queryMonDateInSearchByHostName;
	CTimeType queryMonTimeInSearchByHostName;
	
	///按照HostName，MonDate，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByHostName;
	///按照HostName检索时，存储的查询参数
	CVolumeType queryHostNameInSearchByDsc;
	
	///按照HostName检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDsc;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	///按照HostName，MonDate，MonTime检索时，存储的查询参数
	CVolumeType queryHostNameInSearchByDataDelete;
	CDateType queryMonDateInSearchByDataDelete;
	CTimeType queryMonTimeInSearchByDataDelete;
	
	///按照HostName，MonDate，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDataDelete;
	
	///加入前触发
	///@param	pSysMdbTopMemInfo	要加入的SysMdbTopMemInfo
	virtual void beforeAdd(CWriteableSysMdbTopMemInfo *pSysMdbTopMemInfo);
	
	///加入后触发
	///@param	pSysMdbTopMemInfo	已经加入的SysMdbTopMemInfo
	virtual void afterAdd(CSysMdbTopMemInfo *pSysMdbTopMemInfo);

	///更新前触发	
	///@param	pSysMdbTopMemInfo	被刷新的CSysMdbTopMemInfo
	///@param	pNewSysMdbTopMemInfo	新的值
	virtual void beforeUpdate(CSysMdbTopMemInfo *pSysMdbTopMemInfo, CWriteableSysMdbTopMemInfo *pNewSysMdbTopMemInfo);
	
	///更新后触发
	///@param	pSysMdbTopMemInfo	被刷新的CSysMdbTopMemInfo
	virtual void afterUpdate(CSysMdbTopMemInfo *pSysMdbTopMemInfo);
	
	///删除前触发
	///@param	pSysMdbTopMemInfo	要删除的CSysMdbTopMemInfo
	virtual void beforeRemove(CSysMdbTopMemInfo *pSysMdbTopMemInfo);
	
	///确认加入后触发
	///@param	pSysMdbTopMemInfo	已经加入的SysMdbTopMemInfo
	virtual void commitAdd(CSysMdbTopMemInfo *pSysMdbTopMemInfo);

	///确认更新后触发
	///@param	pSysMdbTopMemInfo	被刷新的CSysMdbTopMemInfo
	///@param	poldSysMdbTopMemInfo	原来的值
	virtual void commitUpdate(CSysMdbTopMemInfo *pSysMdbTopMemInfo, CWriteableSysMdbTopMemInfo *pOldSysMdbTopMemInfo);
	
	///确认删除后触发
	///@param	pSysMdbTopMemInfo	已经删除的CSysMdbTopMemInfo
	virtual void commitRemove(CWriteableSysMdbTopMemInfo *pSysMdbTopMemInfo);

	///所有相关的触发器
	vector<CSysMdbTopMemInfoActionTrigger *> *pActionTriggers;
	vector<CSysMdbTopMemInfoCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysMdbTopMemInfo compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoFactory是一个进程信息的对象工厂。它包含了一批进程信息，
///同时又建立了如下索引，以方便查询：
///	SysHostNameIndex
///	DecIndex
///使用本对象工厂，可以完成对进程信息的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByHostName，findNextByHostName和endFindByHostName完成查询操作
///		使用startFindByDsc，findNextByDsc和endFindByDsc完成查询操作
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbTopProcessInfoFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysMdbTopProcessInfo，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbTopProcessInfoFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbTopProcessInfoFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysMdbTopProcessInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysMdbTopProcessInfo，文件名将根据配置文件中的定义SysMdbTopProcessInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysMdbTopProcessInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysMdbTopProcessInfo，文件名将根据配置文件中的定义SysMdbTopProcessInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysMdbTopProcessInfoResource;

	///将一个CSysMdbTopProcessInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbTopProcessInfo	要加入的SysMdbTopProcessInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbTopProcessInfo *add(CWriteableSysMdbTopProcessInfo *pSysMdbTopProcessInfo, CTransaction *pTransaction=NULL);
	
	///刷新该CSysMdbTopProcessInfo的值
	///@param	pSysMdbTopProcessInfo	被刷新的CSysMdbTopProcessInfo
	///@param	pNewSysMdbTopProcessInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo, CWriteableSysMdbTopProcessInfo *pNewSysMdbTopProcessInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysMdbTopProcessInfo	  需要被刷新或者新增的CSysMdbTopProcessInfo,等于NULL表示是需要新增的
	///@param	pNewSysMdbTopProcessInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysMdbTopProcessInfo* addOrUpdate(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo, CWriteableSysMdbTopProcessInfo *pNewSysMdbTopProcessInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysMdbTopProcessInfo，同时删除其索引
	///@param	pSysMdbTopProcessInfo	要删除的CSysMdbTopProcessInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo, CTransaction *pTransaction=NULL);
	
	///获取某个CSysMdbTopProcessInfo
	///@param	pSysMdbTopProcessInfo	要读取的CSysMdbTopProcessInfo
	///@param	pTragetSysMdbTopProcessInfo	存放结果的CSysMdbTopProcessInfo
	void retrieve(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo, CWriteableSysMdbTopProcessInfo *pTargetSysMdbTopProcessInfo);
	
	///获取第一个CSysMdbTopProcessInfo
	///@return	得到的第一个CSysMdbTopProcessInfo，如果没有，则返回NULL
	CSysMdbTopProcessInfo *getFirst(void);
	
	///获取下一个CSysMdbTopProcessInfo
	///@return	得到下一个CSysMdbTopProcessInfo，如果没有，则返回NULL
	CSysMdbTopProcessInfo *getNext(void);
	
	///结束获取CSysMdbTopProcessInfo
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysMdbTopProcessInfoActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysMdbTopProcessInfoActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysMdbTopProcessInfoCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysMdbTopProcessInfoCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysMdbTopProcessInfoIteratorByHostName;

	///开始寻找CSysMdbTopProcessInfo
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	///@return	满足条件的地一个CSysMdbTopProcessInfo，如果找不到，返回NULL
	CSysMdbTopProcessInfo *startFindByHostName( const CReadOnlyVolumeType& HostName,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysMdbTopProcessInfo，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CSysMdbTopProcessInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbTopProcessInfo *findNextByHostName(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByHostName(void);

	friend class CSysMdbTopProcessInfoIteratorByDsc;

	///开始寻找CSysMdbTopProcessInfo
	///@param	HostName	
	///@return	满足条件的地一个CSysMdbTopProcessInfo，如果找不到，返回NULL
	CSysMdbTopProcessInfo *startFindByDsc( const CReadOnlyVolumeType& HostName);

	///寻找下一个符合条件的CSysMdbTopProcessInfo，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbTopProcessInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbTopProcessInfo *findNextByDsc(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDsc(void);

	friend class CSysMdbTopProcessInfoIteratorBytheAll;

	///开始寻找CSysMdbTopProcessInfo
	///@return	满足条件的地一个CSysMdbTopProcessInfo，如果找不到，返回NULL
	CSysMdbTopProcessInfo *startFindBytheAll();

	///寻找下一个符合条件的CSysMdbTopProcessInfo，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbTopProcessInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbTopProcessInfo *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysMdbTopProcessInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbTopProcessInfo	要加入的SysMdbTopProcessInfo
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbTopProcessInfo *internalAdd(CWriteableSysMdbTopProcessInfo *pSysMdbTopProcessInfo, bool bNoTransaction);
	
	
	///刷新该CSysMdbTopProcessInfo的键值
	///@param	pSysMdbTopProcessInfo	被刷新的CSysMdbTopProcessInfo
	///@param	pNewSysMdbTopProcessInfo	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo, CWriteableSysMdbTopProcessInfo *pNewSysMdbTopProcessInfo, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysMdbTopProcessInfo，同时删除其索引
	///@param	pSysMdbTopProcessInfo	要删除的CSysMdbTopProcessInfo
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo, bool bNoTransaction);
/*
	///检查某个CSysMdbTopProcessInfo是否属于本对象工厂
	///@param	pSysMdbTopProcessInfo	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于HostName+MonDate+MonTime的索引
	CAVLTree *pSysHostNameIndex;
	///基于HostName+MonDate+MonTime的索引
	CAVLTree *pDecIndex;
	
	
	///按照HostName，MonDate，MonTime检索时，存储的查询参数
	CVolumeType queryHostNameInSearchByHostName;
	CDateType queryMonDateInSearchByHostName;
	CTimeType queryMonTimeInSearchByHostName;
	
	///按照HostName，MonDate，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByHostName;
	///按照HostName检索时，存储的查询参数
	CVolumeType queryHostNameInSearchByDsc;
	
	///按照HostName检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDsc;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	
	///加入前触发
	///@param	pSysMdbTopProcessInfo	要加入的SysMdbTopProcessInfo
	virtual void beforeAdd(CWriteableSysMdbTopProcessInfo *pSysMdbTopProcessInfo);
	
	///加入后触发
	///@param	pSysMdbTopProcessInfo	已经加入的SysMdbTopProcessInfo
	virtual void afterAdd(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo);

	///更新前触发	
	///@param	pSysMdbTopProcessInfo	被刷新的CSysMdbTopProcessInfo
	///@param	pNewSysMdbTopProcessInfo	新的值
	virtual void beforeUpdate(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo, CWriteableSysMdbTopProcessInfo *pNewSysMdbTopProcessInfo);
	
	///更新后触发
	///@param	pSysMdbTopProcessInfo	被刷新的CSysMdbTopProcessInfo
	virtual void afterUpdate(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo);
	
	///删除前触发
	///@param	pSysMdbTopProcessInfo	要删除的CSysMdbTopProcessInfo
	virtual void beforeRemove(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo);
	
	///确认加入后触发
	///@param	pSysMdbTopProcessInfo	已经加入的SysMdbTopProcessInfo
	virtual void commitAdd(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo);

	///确认更新后触发
	///@param	pSysMdbTopProcessInfo	被刷新的CSysMdbTopProcessInfo
	///@param	poldSysMdbTopProcessInfo	原来的值
	virtual void commitUpdate(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo, CWriteableSysMdbTopProcessInfo *pOldSysMdbTopProcessInfo);
	
	///确认删除后触发
	///@param	pSysMdbTopProcessInfo	已经删除的CSysMdbTopProcessInfo
	virtual void commitRemove(CWriteableSysMdbTopProcessInfo *pSysMdbTopProcessInfo);

	///所有相关的触发器
	vector<CSysMdbTopProcessInfoActionTrigger *> *pActionTriggers;
	vector<CSysMdbTopProcessInfoCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysMdbTopProcessInfo compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoFactory是一个文件系统信息的对象工厂。它包含了一批文件系统信息，
///同时又建立了如下索引，以方便查询：
///	SysHostNameIndex
///	DecIndex
///使用本对象工厂，可以完成对文件系统信息的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByHostName，findNextByHostName和endFindByHostName完成查询操作
///		使用startFindByDsc，findNextByDsc和endFindByDsc完成查询操作
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbFileSystemInfoFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysMdbFileSystemInfo，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbFileSystemInfoFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbFileSystemInfoFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysMdbFileSystemInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysMdbFileSystemInfo，文件名将根据配置文件中的定义SysMdbFileSystemInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysMdbFileSystemInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysMdbFileSystemInfo，文件名将根据配置文件中的定义SysMdbFileSystemInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysMdbFileSystemInfoResource;

	///将一个CSysMdbFileSystemInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbFileSystemInfo	要加入的SysMdbFileSystemInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbFileSystemInfo *add(CWriteableSysMdbFileSystemInfo *pSysMdbFileSystemInfo, CTransaction *pTransaction=NULL);
	
	///刷新该CSysMdbFileSystemInfo的值
	///@param	pSysMdbFileSystemInfo	被刷新的CSysMdbFileSystemInfo
	///@param	pNewSysMdbFileSystemInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo, CWriteableSysMdbFileSystemInfo *pNewSysMdbFileSystemInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysMdbFileSystemInfo	  需要被刷新或者新增的CSysMdbFileSystemInfo,等于NULL表示是需要新增的
	///@param	pNewSysMdbFileSystemInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysMdbFileSystemInfo* addOrUpdate(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo, CWriteableSysMdbFileSystemInfo *pNewSysMdbFileSystemInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysMdbFileSystemInfo，同时删除其索引
	///@param	pSysMdbFileSystemInfo	要删除的CSysMdbFileSystemInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo, CTransaction *pTransaction=NULL);
	
	///获取某个CSysMdbFileSystemInfo
	///@param	pSysMdbFileSystemInfo	要读取的CSysMdbFileSystemInfo
	///@param	pTragetSysMdbFileSystemInfo	存放结果的CSysMdbFileSystemInfo
	void retrieve(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo, CWriteableSysMdbFileSystemInfo *pTargetSysMdbFileSystemInfo);
	
	///获取第一个CSysMdbFileSystemInfo
	///@return	得到的第一个CSysMdbFileSystemInfo，如果没有，则返回NULL
	CSysMdbFileSystemInfo *getFirst(void);
	
	///获取下一个CSysMdbFileSystemInfo
	///@return	得到下一个CSysMdbFileSystemInfo，如果没有，则返回NULL
	CSysMdbFileSystemInfo *getNext(void);
	
	///结束获取CSysMdbFileSystemInfo
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysMdbFileSystemInfoActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysMdbFileSystemInfoActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysMdbFileSystemInfoCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysMdbFileSystemInfoCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysMdbFileSystemInfoIteratorByHostName;

	///开始寻找CSysMdbFileSystemInfo
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	///@return	满足条件的地一个CSysMdbFileSystemInfo，如果找不到，返回NULL
	CSysMdbFileSystemInfo *startFindByHostName( const CReadOnlyVolumeType& HostName,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysMdbFileSystemInfo，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CSysMdbFileSystemInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbFileSystemInfo *findNextByHostName(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByHostName(void);

	friend class CSysMdbFileSystemInfoIteratorByDsc;

	///开始寻找CSysMdbFileSystemInfo
	///@param	HostName	
	///@return	满足条件的地一个CSysMdbFileSystemInfo，如果找不到，返回NULL
	CSysMdbFileSystemInfo *startFindByDsc( const CReadOnlyVolumeType& HostName);

	///寻找下一个符合条件的CSysMdbFileSystemInfo，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbFileSystemInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbFileSystemInfo *findNextByDsc(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDsc(void);

	friend class CSysMdbFileSystemInfoIteratorBytheAll;

	///开始寻找CSysMdbFileSystemInfo
	///@return	满足条件的地一个CSysMdbFileSystemInfo，如果找不到，返回NULL
	CSysMdbFileSystemInfo *startFindBytheAll();

	///寻找下一个符合条件的CSysMdbFileSystemInfo，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbFileSystemInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbFileSystemInfo *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysMdbFileSystemInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbFileSystemInfo	要加入的SysMdbFileSystemInfo
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbFileSystemInfo *internalAdd(CWriteableSysMdbFileSystemInfo *pSysMdbFileSystemInfo, bool bNoTransaction);
	
	
	///刷新该CSysMdbFileSystemInfo的键值
	///@param	pSysMdbFileSystemInfo	被刷新的CSysMdbFileSystemInfo
	///@param	pNewSysMdbFileSystemInfo	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo, CWriteableSysMdbFileSystemInfo *pNewSysMdbFileSystemInfo, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysMdbFileSystemInfo，同时删除其索引
	///@param	pSysMdbFileSystemInfo	要删除的CSysMdbFileSystemInfo
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo, bool bNoTransaction);
/*
	///检查某个CSysMdbFileSystemInfo是否属于本对象工厂
	///@param	pSysMdbFileSystemInfo	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于HostName+MonDate+MonTime的索引
	CAVLTree *pSysHostNameIndex;
	///基于HostName+MonDate+MonTime的索引
	CAVLTree *pDecIndex;
	
	
	///按照HostName，MonDate，MonTime检索时，存储的查询参数
	CVolumeType queryHostNameInSearchByHostName;
	CDateType queryMonDateInSearchByHostName;
	CTimeType queryMonTimeInSearchByHostName;
	
	///按照HostName，MonDate，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByHostName;
	///按照HostName检索时，存储的查询参数
	CVolumeType queryHostNameInSearchByDsc;
	
	///按照HostName检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDsc;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	
	///加入前触发
	///@param	pSysMdbFileSystemInfo	要加入的SysMdbFileSystemInfo
	virtual void beforeAdd(CWriteableSysMdbFileSystemInfo *pSysMdbFileSystemInfo);
	
	///加入后触发
	///@param	pSysMdbFileSystemInfo	已经加入的SysMdbFileSystemInfo
	virtual void afterAdd(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo);

	///更新前触发	
	///@param	pSysMdbFileSystemInfo	被刷新的CSysMdbFileSystemInfo
	///@param	pNewSysMdbFileSystemInfo	新的值
	virtual void beforeUpdate(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo, CWriteableSysMdbFileSystemInfo *pNewSysMdbFileSystemInfo);
	
	///更新后触发
	///@param	pSysMdbFileSystemInfo	被刷新的CSysMdbFileSystemInfo
	virtual void afterUpdate(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo);
	
	///删除前触发
	///@param	pSysMdbFileSystemInfo	要删除的CSysMdbFileSystemInfo
	virtual void beforeRemove(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo);
	
	///确认加入后触发
	///@param	pSysMdbFileSystemInfo	已经加入的SysMdbFileSystemInfo
	virtual void commitAdd(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo);

	///确认更新后触发
	///@param	pSysMdbFileSystemInfo	被刷新的CSysMdbFileSystemInfo
	///@param	poldSysMdbFileSystemInfo	原来的值
	virtual void commitUpdate(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo, CWriteableSysMdbFileSystemInfo *pOldSysMdbFileSystemInfo);
	
	///确认删除后触发
	///@param	pSysMdbFileSystemInfo	已经删除的CSysMdbFileSystemInfo
	virtual void commitRemove(CWriteableSysMdbFileSystemInfo *pSysMdbFileSystemInfo);

	///所有相关的触发器
	vector<CSysMdbFileSystemInfoActionTrigger *> *pActionTriggers;
	vector<CSysMdbFileSystemInfoCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysMdbFileSystemInfo compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoFactory是一个网络使用信息的对象工厂。它包含了一批网络使用信息，
///同时又建立了如下索引，以方便查询：
///	SysHostNameIndex
///	DecIndex
///使用本对象工厂，可以完成对网络使用信息的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByHostName，findNextByHostName和endFindByHostName完成查询操作
///		使用startFindByDsc，findNextByDsc和endFindByDsc完成查询操作
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///		使用startFindByDataDelete，findNextByDataDelete和endFindByDataDelete完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbNetworkInfoFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysMdbNetworkInfo，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbNetworkInfoFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbNetworkInfoFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysMdbNetworkInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysMdbNetworkInfo，文件名将根据配置文件中的定义SysMdbNetworkInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysMdbNetworkInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysMdbNetworkInfo，文件名将根据配置文件中的定义SysMdbNetworkInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysMdbNetworkInfoResource;

	///将一个CSysMdbNetworkInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbNetworkInfo	要加入的SysMdbNetworkInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbNetworkInfo *add(CWriteableSysMdbNetworkInfo *pSysMdbNetworkInfo, CTransaction *pTransaction=NULL);
	
	///刷新该CSysMdbNetworkInfo的值
	///@param	pSysMdbNetworkInfo	被刷新的CSysMdbNetworkInfo
	///@param	pNewSysMdbNetworkInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysMdbNetworkInfo *pSysMdbNetworkInfo, CWriteableSysMdbNetworkInfo *pNewSysMdbNetworkInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysMdbNetworkInfo	  需要被刷新或者新增的CSysMdbNetworkInfo,等于NULL表示是需要新增的
	///@param	pNewSysMdbNetworkInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysMdbNetworkInfo* addOrUpdate(CSysMdbNetworkInfo *pSysMdbNetworkInfo, CWriteableSysMdbNetworkInfo *pNewSysMdbNetworkInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysMdbNetworkInfo，同时删除其索引
	///@param	pSysMdbNetworkInfo	要删除的CSysMdbNetworkInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysMdbNetworkInfo *pSysMdbNetworkInfo, CTransaction *pTransaction=NULL);
	
	///获取某个CSysMdbNetworkInfo
	///@param	pSysMdbNetworkInfo	要读取的CSysMdbNetworkInfo
	///@param	pTragetSysMdbNetworkInfo	存放结果的CSysMdbNetworkInfo
	void retrieve(CSysMdbNetworkInfo *pSysMdbNetworkInfo, CWriteableSysMdbNetworkInfo *pTargetSysMdbNetworkInfo);
	
	///获取第一个CSysMdbNetworkInfo
	///@return	得到的第一个CSysMdbNetworkInfo，如果没有，则返回NULL
	CSysMdbNetworkInfo *getFirst(void);
	
	///获取下一个CSysMdbNetworkInfo
	///@return	得到下一个CSysMdbNetworkInfo，如果没有，则返回NULL
	CSysMdbNetworkInfo *getNext(void);
	
	///结束获取CSysMdbNetworkInfo
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysMdbNetworkInfoActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysMdbNetworkInfoActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysMdbNetworkInfoCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysMdbNetworkInfoCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysMdbNetworkInfoIteratorByHostName;

	///开始寻找CSysMdbNetworkInfo
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	///@return	满足条件的地一个CSysMdbNetworkInfo，如果找不到，返回NULL
	CSysMdbNetworkInfo *startFindByHostName( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysMdbNetworkInfo，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CSysMdbNetworkInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbNetworkInfo *findNextByHostName(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByHostName(void);

	friend class CSysMdbNetworkInfoIteratorByDsc;

	///开始寻找CSysMdbNetworkInfo
	///@param	SubcriberID	
	///@return	满足条件的地一个CSysMdbNetworkInfo，如果找不到，返回NULL
	CSysMdbNetworkInfo *startFindByDsc( const CReadOnlyVolumeType& SubcriberID);

	///寻找下一个符合条件的CSysMdbNetworkInfo，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbNetworkInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbNetworkInfo *findNextByDsc(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDsc(void);

	friend class CSysMdbNetworkInfoIteratorBytheAll;

	///开始寻找CSysMdbNetworkInfo
	///@return	满足条件的地一个CSysMdbNetworkInfo，如果找不到，返回NULL
	CSysMdbNetworkInfo *startFindBytheAll();

	///寻找下一个符合条件的CSysMdbNetworkInfo，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbNetworkInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbNetworkInfo *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

	friend class CSysMdbNetworkInfoIteratorByDataDelete;

	///开始寻找CSysMdbNetworkInfo
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	///@return	满足条件的地一个CSysMdbNetworkInfo，如果找不到，返回NULL
	CSysMdbNetworkInfo *startFindByDataDelete( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysMdbNetworkInfo，必须在startFindByDataDelete以后，endFindByDataDelete之前叫用
	///@return	下一个满足条件CSysMdbNetworkInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbNetworkInfo *findNextByDataDelete(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDataDelete(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysMdbNetworkInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbNetworkInfo	要加入的SysMdbNetworkInfo
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbNetworkInfo *internalAdd(CWriteableSysMdbNetworkInfo *pSysMdbNetworkInfo, bool bNoTransaction);
	
	
	///刷新该CSysMdbNetworkInfo的键值
	///@param	pSysMdbNetworkInfo	被刷新的CSysMdbNetworkInfo
	///@param	pNewSysMdbNetworkInfo	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysMdbNetworkInfo *pSysMdbNetworkInfo, CWriteableSysMdbNetworkInfo *pNewSysMdbNetworkInfo, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysMdbNetworkInfo，同时删除其索引
	///@param	pSysMdbNetworkInfo	要删除的CSysMdbNetworkInfo
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysMdbNetworkInfo *pSysMdbNetworkInfo, bool bNoTransaction);
/*
	///检查某个CSysMdbNetworkInfo是否属于本对象工厂
	///@param	pSysMdbNetworkInfo	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysMdbNetworkInfo *pSysMdbNetworkInfo);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于SubcriberID+MonDate+MonTime的索引
	CAVLTree *pSysHostNameIndex;
	///基于SubcriberID+MonDate+MonTime的索引
	CAVLTree *pDecIndex;
	
	
	///按照SubcriberID，MonDate，MonTime检索时，存储的查询参数
	CVolumeType querySubcriberIDInSearchByHostName;
	CDateType queryMonDateInSearchByHostName;
	CTimeType queryMonTimeInSearchByHostName;
	
	///按照SubcriberID，MonDate，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByHostName;
	///按照SubcriberID检索时，存储的查询参数
	CVolumeType querySubcriberIDInSearchByDsc;
	
	///按照SubcriberID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDsc;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	///按照SubcriberID，MonDate，MonTime检索时，存储的查询参数
	CVolumeType querySubcriberIDInSearchByDataDelete;
	CDateType queryMonDateInSearchByDataDelete;
	CTimeType queryMonTimeInSearchByDataDelete;
	
	///按照SubcriberID，MonDate，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDataDelete;
	
	///加入前触发
	///@param	pSysMdbNetworkInfo	要加入的SysMdbNetworkInfo
	virtual void beforeAdd(CWriteableSysMdbNetworkInfo *pSysMdbNetworkInfo);
	
	///加入后触发
	///@param	pSysMdbNetworkInfo	已经加入的SysMdbNetworkInfo
	virtual void afterAdd(CSysMdbNetworkInfo *pSysMdbNetworkInfo);

	///更新前触发	
	///@param	pSysMdbNetworkInfo	被刷新的CSysMdbNetworkInfo
	///@param	pNewSysMdbNetworkInfo	新的值
	virtual void beforeUpdate(CSysMdbNetworkInfo *pSysMdbNetworkInfo, CWriteableSysMdbNetworkInfo *pNewSysMdbNetworkInfo);
	
	///更新后触发
	///@param	pSysMdbNetworkInfo	被刷新的CSysMdbNetworkInfo
	virtual void afterUpdate(CSysMdbNetworkInfo *pSysMdbNetworkInfo);
	
	///删除前触发
	///@param	pSysMdbNetworkInfo	要删除的CSysMdbNetworkInfo
	virtual void beforeRemove(CSysMdbNetworkInfo *pSysMdbNetworkInfo);
	
	///确认加入后触发
	///@param	pSysMdbNetworkInfo	已经加入的SysMdbNetworkInfo
	virtual void commitAdd(CSysMdbNetworkInfo *pSysMdbNetworkInfo);

	///确认更新后触发
	///@param	pSysMdbNetworkInfo	被刷新的CSysMdbNetworkInfo
	///@param	poldSysMdbNetworkInfo	原来的值
	virtual void commitUpdate(CSysMdbNetworkInfo *pSysMdbNetworkInfo, CWriteableSysMdbNetworkInfo *pOldSysMdbNetworkInfo);
	
	///确认删除后触发
	///@param	pSysMdbNetworkInfo	已经删除的CSysMdbNetworkInfo
	virtual void commitRemove(CWriteableSysMdbNetworkInfo *pSysMdbNetworkInfo);

	///所有相关的触发器
	vector<CSysMdbNetworkInfoActionTrigger *> *pActionTriggers;
	vector<CSysMdbNetworkInfoCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysMdbNetworkInfo compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantInitFactory是一个会员的对象工厂。它包含了一批会员，
///同时又建立了如下索引，以方便查询：
///	SysParticipantIDIndex
///使用本对象工厂，可以完成对会员的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantInitFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysParticipantInitFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysParticipantInit，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysParticipantInitFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysParticipantInitFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysParticipantInit
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysParticipantInit，文件名将根据配置文件中的定义SysParticipantInitCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysParticipantInit
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysParticipantInit，文件名将根据配置文件中的定义SysParticipantInitCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysParticipantInitResource;

	///将一个CSysParticipantInit加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysParticipantInit	要加入的SysParticipantInit
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysParticipantInit *add(CWriteableSysParticipantInit *pSysParticipantInit, CTransaction *pTransaction=NULL);
	
	///刷新该CSysParticipantInit的值
	///@param	pSysParticipantInit	被刷新的CSysParticipantInit
	///@param	pNewSysParticipantInit	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysParticipantInit *pSysParticipantInit, CWriteableSysParticipantInit *pNewSysParticipantInit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysParticipantInit	  需要被刷新或者新增的CSysParticipantInit,等于NULL表示是需要新增的
	///@param	pNewSysParticipantInit	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysParticipantInit* addOrUpdate(CSysParticipantInit *pSysParticipantInit, CWriteableSysParticipantInit *pNewSysParticipantInit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysParticipantInit，同时删除其索引
	///@param	pSysParticipantInit	要删除的CSysParticipantInit
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysParticipantInit *pSysParticipantInit, CTransaction *pTransaction=NULL);
	
	///获取某个CSysParticipantInit
	///@param	pSysParticipantInit	要读取的CSysParticipantInit
	///@param	pTragetSysParticipantInit	存放结果的CSysParticipantInit
	void retrieve(CSysParticipantInit *pSysParticipantInit, CWriteableSysParticipantInit *pTargetSysParticipantInit);
	
	///获取第一个CSysParticipantInit
	///@return	得到的第一个CSysParticipantInit，如果没有，则返回NULL
	CSysParticipantInit *getFirst(void);
	
	///获取下一个CSysParticipantInit
	///@return	得到下一个CSysParticipantInit，如果没有，则返回NULL
	CSysParticipantInit *getNext(void);
	
	///结束获取CSysParticipantInit
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysParticipantInitActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysParticipantInitActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysParticipantInitCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysParticipantInitCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysParticipantInitIteratorByAll;

	///开始寻找CSysParticipantInit
	///@return	满足条件的地一个CSysParticipantInit，如果找不到，返回NULL
	CSysParticipantInit *startFindByAll();

	///寻找下一个符合条件的CSysParticipantInit，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysParticipantInit，如果已经没有一个满足要求了，则返回NULL
	CSysParticipantInit *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysParticipantInit
	///@param	ParticipantID	
	///@return	找到的CSysParticipantInit，如果找不到，返回NULL
	CSysParticipantInit *findByOne( const CReadOnlyParticipantIDType&  ParticipantID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysParticipantInit加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysParticipantInit	要加入的SysParticipantInit
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysParticipantInit *internalAdd(CWriteableSysParticipantInit *pSysParticipantInit, bool bNoTransaction);
	
	
	///刷新该CSysParticipantInit的键值
	///@param	pSysParticipantInit	被刷新的CSysParticipantInit
	///@param	pNewSysParticipantInit	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysParticipantInit *pSysParticipantInit, CWriteableSysParticipantInit *pNewSysParticipantInit, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysParticipantInit，同时删除其索引
	///@param	pSysParticipantInit	要删除的CSysParticipantInit
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysParticipantInit *pSysParticipantInit, bool bNoTransaction);
/*
	///检查某个CSysParticipantInit是否属于本对象工厂
	///@param	pSysParticipantInit	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysParticipantInit *pSysParticipantInit);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ParticipantID的索引
	CAVLTree *pSysParticipantIDIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysParticipantInit	要加入的SysParticipantInit
	virtual void beforeAdd(CWriteableSysParticipantInit *pSysParticipantInit);
	
	///加入后触发
	///@param	pSysParticipantInit	已经加入的SysParticipantInit
	virtual void afterAdd(CSysParticipantInit *pSysParticipantInit);

	///更新前触发	
	///@param	pSysParticipantInit	被刷新的CSysParticipantInit
	///@param	pNewSysParticipantInit	新的值
	virtual void beforeUpdate(CSysParticipantInit *pSysParticipantInit, CWriteableSysParticipantInit *pNewSysParticipantInit);
	
	///更新后触发
	///@param	pSysParticipantInit	被刷新的CSysParticipantInit
	virtual void afterUpdate(CSysParticipantInit *pSysParticipantInit);
	
	///删除前触发
	///@param	pSysParticipantInit	要删除的CSysParticipantInit
	virtual void beforeRemove(CSysParticipantInit *pSysParticipantInit);
	
	///确认加入后触发
	///@param	pSysParticipantInit	已经加入的SysParticipantInit
	virtual void commitAdd(CSysParticipantInit *pSysParticipantInit);

	///确认更新后触发
	///@param	pSysParticipantInit	被刷新的CSysParticipantInit
	///@param	poldSysParticipantInit	原来的值
	virtual void commitUpdate(CSysParticipantInit *pSysParticipantInit, CWriteableSysParticipantInit *pOldSysParticipantInit);
	
	///确认删除后触发
	///@param	pSysParticipantInit	已经删除的CSysParticipantInit
	virtual void commitRemove(CWriteableSysParticipantInit *pSysParticipantInit);

	///所有相关的触发器
	vector<CSysParticipantInitActionTrigger *> *pActionTriggers;
	vector<CSysParticipantInitCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysParticipantInit compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInitFactory是一个交易用户的对象工厂。它包含了一批交易用户，
///同时又建立了如下索引，以方便查询：
///	SysUserIDIndex
///使用本对象工厂，可以完成对交易用户的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInitFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysUserInitFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysUserInit，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysUserInitFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysUserInitFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysUserInit
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysUserInit，文件名将根据配置文件中的定义SysUserInitCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysUserInit
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysUserInit，文件名将根据配置文件中的定义SysUserInitCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysUserInitResource;

	///将一个CSysUserInit加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysUserInit	要加入的SysUserInit
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysUserInit *add(CWriteableSysUserInit *pSysUserInit, CTransaction *pTransaction=NULL);
	
	///刷新该CSysUserInit的值
	///@param	pSysUserInit	被刷新的CSysUserInit
	///@param	pNewSysUserInit	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysUserInit *pSysUserInit, CWriteableSysUserInit *pNewSysUserInit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysUserInit	  需要被刷新或者新增的CSysUserInit,等于NULL表示是需要新增的
	///@param	pNewSysUserInit	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysUserInit* addOrUpdate(CSysUserInit *pSysUserInit, CWriteableSysUserInit *pNewSysUserInit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysUserInit，同时删除其索引
	///@param	pSysUserInit	要删除的CSysUserInit
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysUserInit *pSysUserInit, CTransaction *pTransaction=NULL);
	
	///获取某个CSysUserInit
	///@param	pSysUserInit	要读取的CSysUserInit
	///@param	pTragetSysUserInit	存放结果的CSysUserInit
	void retrieve(CSysUserInit *pSysUserInit, CWriteableSysUserInit *pTargetSysUserInit);
	
	///获取第一个CSysUserInit
	///@return	得到的第一个CSysUserInit，如果没有，则返回NULL
	CSysUserInit *getFirst(void);
	
	///获取下一个CSysUserInit
	///@return	得到下一个CSysUserInit，如果没有，则返回NULL
	CSysUserInit *getNext(void);
	
	///结束获取CSysUserInit
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysUserInitActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysUserInitActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysUserInitCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysUserInitCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysUserInitIteratorByAll;

	///开始寻找CSysUserInit
	///@return	满足条件的地一个CSysUserInit，如果找不到，返回NULL
	CSysUserInit *startFindByAll();

	///寻找下一个符合条件的CSysUserInit，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysUserInit，如果已经没有一个满足要求了，则返回NULL
	CSysUserInit *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysUserInit
	///@param	UserID	
	///@return	找到的CSysUserInit，如果找不到，返回NULL
	CSysUserInit *findByOne( const CReadOnlyUserIDType&  UserID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysUserInit加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysUserInit	要加入的SysUserInit
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysUserInit *internalAdd(CWriteableSysUserInit *pSysUserInit, bool bNoTransaction);
	
	
	///刷新该CSysUserInit的键值
	///@param	pSysUserInit	被刷新的CSysUserInit
	///@param	pNewSysUserInit	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysUserInit *pSysUserInit, CWriteableSysUserInit *pNewSysUserInit, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysUserInit，同时删除其索引
	///@param	pSysUserInit	要删除的CSysUserInit
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysUserInit *pSysUserInit, bool bNoTransaction);
/*
	///检查某个CSysUserInit是否属于本对象工厂
	///@param	pSysUserInit	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysUserInit *pSysUserInit);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于UserID的索引
	CAVLTree *pSysUserIDIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysUserInit	要加入的SysUserInit
	virtual void beforeAdd(CWriteableSysUserInit *pSysUserInit);
	
	///加入后触发
	///@param	pSysUserInit	已经加入的SysUserInit
	virtual void afterAdd(CSysUserInit *pSysUserInit);

	///更新前触发	
	///@param	pSysUserInit	被刷新的CSysUserInit
	///@param	pNewSysUserInit	新的值
	virtual void beforeUpdate(CSysUserInit *pSysUserInit, CWriteableSysUserInit *pNewSysUserInit);
	
	///更新后触发
	///@param	pSysUserInit	被刷新的CSysUserInit
	virtual void afterUpdate(CSysUserInit *pSysUserInit);
	
	///删除前触发
	///@param	pSysUserInit	要删除的CSysUserInit
	virtual void beforeRemove(CSysUserInit *pSysUserInit);
	
	///确认加入后触发
	///@param	pSysUserInit	已经加入的SysUserInit
	virtual void commitAdd(CSysUserInit *pSysUserInit);

	///确认更新后触发
	///@param	pSysUserInit	被刷新的CSysUserInit
	///@param	poldSysUserInit	原来的值
	virtual void commitUpdate(CSysUserInit *pSysUserInit, CWriteableSysUserInit *pOldSysUserInit);
	
	///确认删除后触发
	///@param	pSysUserInit	已经删除的CSysUserInit
	virtual void commitRemove(CWriteableSysUserInit *pSysUserInit);

	///所有相关的触发器
	vector<CSysUserInitActionTrigger *> *pActionTriggers;
	vector<CSysUserInitCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysUserInit compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientInitFactory是一个客户的对象工厂。它包含了一批客户，
///同时又建立了如下索引，以方便查询：
///	SysClientIDIndex
///使用本对象工厂，可以完成对客户的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientInitFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysClientInitFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysClientInit，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysClientInitFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysClientInitFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysClientInit
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysClientInit，文件名将根据配置文件中的定义SysClientInitCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysClientInit
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysClientInit，文件名将根据配置文件中的定义SysClientInitCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysClientInitResource;

	///将一个CSysClientInit加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysClientInit	要加入的SysClientInit
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysClientInit *add(CWriteableSysClientInit *pSysClientInit, CTransaction *pTransaction=NULL);
	
	///刷新该CSysClientInit的值
	///@param	pSysClientInit	被刷新的CSysClientInit
	///@param	pNewSysClientInit	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysClientInit *pSysClientInit, CWriteableSysClientInit *pNewSysClientInit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysClientInit	  需要被刷新或者新增的CSysClientInit,等于NULL表示是需要新增的
	///@param	pNewSysClientInit	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysClientInit* addOrUpdate(CSysClientInit *pSysClientInit, CWriteableSysClientInit *pNewSysClientInit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysClientInit，同时删除其索引
	///@param	pSysClientInit	要删除的CSysClientInit
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysClientInit *pSysClientInit, CTransaction *pTransaction=NULL);
	
	///获取某个CSysClientInit
	///@param	pSysClientInit	要读取的CSysClientInit
	///@param	pTragetSysClientInit	存放结果的CSysClientInit
	void retrieve(CSysClientInit *pSysClientInit, CWriteableSysClientInit *pTargetSysClientInit);
	
	///获取第一个CSysClientInit
	///@return	得到的第一个CSysClientInit，如果没有，则返回NULL
	CSysClientInit *getFirst(void);
	
	///获取下一个CSysClientInit
	///@return	得到下一个CSysClientInit，如果没有，则返回NULL
	CSysClientInit *getNext(void);
	
	///结束获取CSysClientInit
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysClientInitActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysClientInitActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysClientInitCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysClientInitCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysClientInitIteratorByAll;

	///开始寻找CSysClientInit
	///@return	满足条件的地一个CSysClientInit，如果找不到，返回NULL
	CSysClientInit *startFindByAll();

	///寻找下一个符合条件的CSysClientInit，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysClientInit，如果已经没有一个满足要求了，则返回NULL
	CSysClientInit *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysClientInit
	///@param	ClientID	
	///@return	找到的CSysClientInit，如果找不到，返回NULL
	CSysClientInit *findByOne( const CReadOnlyClientIDType&  ClientID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysClientInit加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysClientInit	要加入的SysClientInit
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysClientInit *internalAdd(CWriteableSysClientInit *pSysClientInit, bool bNoTransaction);
	
	
	///刷新该CSysClientInit的键值
	///@param	pSysClientInit	被刷新的CSysClientInit
	///@param	pNewSysClientInit	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysClientInit *pSysClientInit, CWriteableSysClientInit *pNewSysClientInit, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysClientInit，同时删除其索引
	///@param	pSysClientInit	要删除的CSysClientInit
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysClientInit *pSysClientInit, bool bNoTransaction);
/*
	///检查某个CSysClientInit是否属于本对象工厂
	///@param	pSysClientInit	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysClientInit *pSysClientInit);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ClientID的索引
	CAVLTree *pSysClientIDIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysClientInit	要加入的SysClientInit
	virtual void beforeAdd(CWriteableSysClientInit *pSysClientInit);
	
	///加入后触发
	///@param	pSysClientInit	已经加入的SysClientInit
	virtual void afterAdd(CSysClientInit *pSysClientInit);

	///更新前触发	
	///@param	pSysClientInit	被刷新的CSysClientInit
	///@param	pNewSysClientInit	新的值
	virtual void beforeUpdate(CSysClientInit *pSysClientInit, CWriteableSysClientInit *pNewSysClientInit);
	
	///更新后触发
	///@param	pSysClientInit	被刷新的CSysClientInit
	virtual void afterUpdate(CSysClientInit *pSysClientInit);
	
	///删除前触发
	///@param	pSysClientInit	要删除的CSysClientInit
	virtual void beforeRemove(CSysClientInit *pSysClientInit);
	
	///确认加入后触发
	///@param	pSysClientInit	已经加入的SysClientInit
	virtual void commitAdd(CSysClientInit *pSysClientInit);

	///确认更新后触发
	///@param	pSysClientInit	被刷新的CSysClientInit
	///@param	poldSysClientInit	原来的值
	virtual void commitUpdate(CSysClientInit *pSysClientInit, CWriteableSysClientInit *pOldSysClientInit);
	
	///确认删除后触发
	///@param	pSysClientInit	已经删除的CSysClientInit
	virtual void commitRemove(CWriteableSysClientInit *pSysClientInit);

	///所有相关的触发器
	vector<CSysClientInitActionTrigger *> *pActionTriggers;
	vector<CSysClientInitCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysClientInit compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysTradeUserLoginInfoFactory是一个交易系统登录信息的对象工厂。它包含了一批交易系统登录信息，
///同时又建立了如下索引，以方便查询：
///	SysTradeUserLoginInfoIndex
///使用本对象工厂，可以完成对交易系统登录信息的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTradeUserLoginInfoFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysTradeUserLoginInfoFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysTradeUserLoginInfo，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysTradeUserLoginInfoFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysTradeUserLoginInfoFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysTradeUserLoginInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysTradeUserLoginInfo，文件名将根据配置文件中的定义SysTradeUserLoginInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysTradeUserLoginInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysTradeUserLoginInfo，文件名将根据配置文件中的定义SysTradeUserLoginInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysTradeUserLoginInfoResource;

	///将一个CSysTradeUserLoginInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysTradeUserLoginInfo	要加入的SysTradeUserLoginInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysTradeUserLoginInfo *add(CWriteableSysTradeUserLoginInfo *pSysTradeUserLoginInfo, CTransaction *pTransaction=NULL);
	
	///刷新该CSysTradeUserLoginInfo的值
	///@param	pSysTradeUserLoginInfo	被刷新的CSysTradeUserLoginInfo
	///@param	pNewSysTradeUserLoginInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo, CWriteableSysTradeUserLoginInfo *pNewSysTradeUserLoginInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysTradeUserLoginInfo	  需要被刷新或者新增的CSysTradeUserLoginInfo,等于NULL表示是需要新增的
	///@param	pNewSysTradeUserLoginInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysTradeUserLoginInfo* addOrUpdate(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo, CWriteableSysTradeUserLoginInfo *pNewSysTradeUserLoginInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysTradeUserLoginInfo，同时删除其索引
	///@param	pSysTradeUserLoginInfo	要删除的CSysTradeUserLoginInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo, CTransaction *pTransaction=NULL);
	
	///获取某个CSysTradeUserLoginInfo
	///@param	pSysTradeUserLoginInfo	要读取的CSysTradeUserLoginInfo
	///@param	pTragetSysTradeUserLoginInfo	存放结果的CSysTradeUserLoginInfo
	void retrieve(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo, CWriteableSysTradeUserLoginInfo *pTargetSysTradeUserLoginInfo);
	
	///获取第一个CSysTradeUserLoginInfo
	///@return	得到的第一个CSysTradeUserLoginInfo，如果没有，则返回NULL
	CSysTradeUserLoginInfo *getFirst(void);
	
	///获取下一个CSysTradeUserLoginInfo
	///@return	得到下一个CSysTradeUserLoginInfo，如果没有，则返回NULL
	CSysTradeUserLoginInfo *getNext(void);
	
	///结束获取CSysTradeUserLoginInfo
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysTradeUserLoginInfoActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysTradeUserLoginInfoActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysTradeUserLoginInfoCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysTradeUserLoginInfoCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysTradeUserLoginInfoIteratorByAll;

	///开始寻找CSysTradeUserLoginInfo
	///@return	满足条件的地一个CSysTradeUserLoginInfo，如果找不到，返回NULL
	CSysTradeUserLoginInfo *startFindByAll();

	///寻找下一个符合条件的CSysTradeUserLoginInfo，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysTradeUserLoginInfo，如果已经没有一个满足要求了，则返回NULL
	CSysTradeUserLoginInfo *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysTradeUserLoginInfo
	///@param	ParticipantID	
	///@param	UserID	
	///@return	找到的CSysTradeUserLoginInfo，如果找不到，返回NULL
	CSysTradeUserLoginInfo *findByOne( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyUserIDType&  UserID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysTradeUserLoginInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysTradeUserLoginInfo	要加入的SysTradeUserLoginInfo
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysTradeUserLoginInfo *internalAdd(CWriteableSysTradeUserLoginInfo *pSysTradeUserLoginInfo, bool bNoTransaction);
	
	
	///刷新该CSysTradeUserLoginInfo的键值
	///@param	pSysTradeUserLoginInfo	被刷新的CSysTradeUserLoginInfo
	///@param	pNewSysTradeUserLoginInfo	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo, CWriteableSysTradeUserLoginInfo *pNewSysTradeUserLoginInfo, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysTradeUserLoginInfo，同时删除其索引
	///@param	pSysTradeUserLoginInfo	要删除的CSysTradeUserLoginInfo
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo, bool bNoTransaction);
/*
	///检查某个CSysTradeUserLoginInfo是否属于本对象工厂
	///@param	pSysTradeUserLoginInfo	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ParticipantID+UserID的索引
	CAVLTree *pSysTradeUserLoginInfoIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysTradeUserLoginInfo	要加入的SysTradeUserLoginInfo
	virtual void beforeAdd(CWriteableSysTradeUserLoginInfo *pSysTradeUserLoginInfo);
	
	///加入后触发
	///@param	pSysTradeUserLoginInfo	已经加入的SysTradeUserLoginInfo
	virtual void afterAdd(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo);

	///更新前触发	
	///@param	pSysTradeUserLoginInfo	被刷新的CSysTradeUserLoginInfo
	///@param	pNewSysTradeUserLoginInfo	新的值
	virtual void beforeUpdate(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo, CWriteableSysTradeUserLoginInfo *pNewSysTradeUserLoginInfo);
	
	///更新后触发
	///@param	pSysTradeUserLoginInfo	被刷新的CSysTradeUserLoginInfo
	virtual void afterUpdate(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo);
	
	///删除前触发
	///@param	pSysTradeUserLoginInfo	要删除的CSysTradeUserLoginInfo
	virtual void beforeRemove(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo);
	
	///确认加入后触发
	///@param	pSysTradeUserLoginInfo	已经加入的SysTradeUserLoginInfo
	virtual void commitAdd(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo);

	///确认更新后触发
	///@param	pSysTradeUserLoginInfo	被刷新的CSysTradeUserLoginInfo
	///@param	poldSysTradeUserLoginInfo	原来的值
	virtual void commitUpdate(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo, CWriteableSysTradeUserLoginInfo *pOldSysTradeUserLoginInfo);
	
	///确认删除后触发
	///@param	pSysTradeUserLoginInfo	已经删除的CSysTradeUserLoginInfo
	virtual void commitRemove(CWriteableSysTradeUserLoginInfo *pSysTradeUserLoginInfo);

	///所有相关的触发器
	vector<CSysTradeUserLoginInfoActionTrigger *> *pActionTriggers;
	vector<CSysTradeUserLoginInfoCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysTradeUserLoginInfo compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoFactory是一个Web应用信息的对象工厂。它包含了一批Web应用信息，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对Web应用信息的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByIDType，findNextByIDType和endFindByIDType完成查询操作
///		使用startFindByDsc，findNextByDsc和endFindByDsc完成查询操作
///		使用findByOne，唯一找到对象
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///		使用startFindByDataDelete，findNextByDataDelete和endFindByDataDelete完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbWebAppInfoFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysMdbWebAppInfo，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbWebAppInfoFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbWebAppInfoFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysMdbWebAppInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysMdbWebAppInfo，文件名将根据配置文件中的定义SysMdbWebAppInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysMdbWebAppInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysMdbWebAppInfo，文件名将根据配置文件中的定义SysMdbWebAppInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysMdbWebAppInfoResource;

	///将一个CSysMdbWebAppInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbWebAppInfo	要加入的SysMdbWebAppInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbWebAppInfo *add(CWriteableSysMdbWebAppInfo *pSysMdbWebAppInfo, CTransaction *pTransaction=NULL);
	
	///刷新该CSysMdbWebAppInfo的值
	///@param	pSysMdbWebAppInfo	被刷新的CSysMdbWebAppInfo
	///@param	pNewSysMdbWebAppInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysMdbWebAppInfo *pSysMdbWebAppInfo, CWriteableSysMdbWebAppInfo *pNewSysMdbWebAppInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysMdbWebAppInfo	  需要被刷新或者新增的CSysMdbWebAppInfo,等于NULL表示是需要新增的
	///@param	pNewSysMdbWebAppInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysMdbWebAppInfo* addOrUpdate(CSysMdbWebAppInfo *pSysMdbWebAppInfo, CWriteableSysMdbWebAppInfo *pNewSysMdbWebAppInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysMdbWebAppInfo，同时删除其索引
	///@param	pSysMdbWebAppInfo	要删除的CSysMdbWebAppInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysMdbWebAppInfo *pSysMdbWebAppInfo, CTransaction *pTransaction=NULL);
	
	///获取某个CSysMdbWebAppInfo
	///@param	pSysMdbWebAppInfo	要读取的CSysMdbWebAppInfo
	///@param	pTragetSysMdbWebAppInfo	存放结果的CSysMdbWebAppInfo
	void retrieve(CSysMdbWebAppInfo *pSysMdbWebAppInfo, CWriteableSysMdbWebAppInfo *pTargetSysMdbWebAppInfo);
	
	///获取第一个CSysMdbWebAppInfo
	///@return	得到的第一个CSysMdbWebAppInfo，如果没有，则返回NULL
	CSysMdbWebAppInfo *getFirst(void);
	
	///获取下一个CSysMdbWebAppInfo
	///@return	得到下一个CSysMdbWebAppInfo，如果没有，则返回NULL
	CSysMdbWebAppInfo *getNext(void);
	
	///结束获取CSysMdbWebAppInfo
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysMdbWebAppInfoActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysMdbWebAppInfoActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysMdbWebAppInfoCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysMdbWebAppInfoCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysMdbWebAppInfoIteratorByIDType;

	///开始寻找CSysMdbWebAppInfo
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	///@return	满足条件的地一个CSysMdbWebAppInfo，如果找不到，返回NULL
	CSysMdbWebAppInfo *startFindByIDType( const CReadOnlyVolumeType& ObjectID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysMdbWebAppInfo，必须在startFindByIDType以后，endFindByIDType之前叫用
	///@return	下一个满足条件CSysMdbWebAppInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbWebAppInfo *findNextByIDType(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByIDType(void);

	friend class CSysMdbWebAppInfoIteratorByDsc;

	///开始寻找CSysMdbWebAppInfo
	///@param	ObjectID	
	///@return	满足条件的地一个CSysMdbWebAppInfo，如果找不到，返回NULL
	CSysMdbWebAppInfo *startFindByDsc( const CReadOnlyVolumeType& ObjectID);

	///寻找下一个符合条件的CSysMdbWebAppInfo，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbWebAppInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbWebAppInfo *findNextByDsc(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDsc(void);

	///寻找CSysMdbWebAppInfo
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	///@return	找到的CSysMdbWebAppInfo，如果找不到，返回NULL
	CSysMdbWebAppInfo *findByOne( const CReadOnlyVolumeType&  ObjectID,  const CReadOnlyDateType&  MonDate,  const CReadOnlyTimeType&  MonTime);



	friend class CSysMdbWebAppInfoIteratorBytheAll;

	///开始寻找CSysMdbWebAppInfo
	///@return	满足条件的地一个CSysMdbWebAppInfo，如果找不到，返回NULL
	CSysMdbWebAppInfo *startFindBytheAll();

	///寻找下一个符合条件的CSysMdbWebAppInfo，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbWebAppInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbWebAppInfo *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

	friend class CSysMdbWebAppInfoIteratorByDataDelete;

	///开始寻找CSysMdbWebAppInfo
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	///@return	满足条件的地一个CSysMdbWebAppInfo，如果找不到，返回NULL
	CSysMdbWebAppInfo *startFindByDataDelete( const CReadOnlyVolumeType& ObjectID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysMdbWebAppInfo，必须在startFindByDataDelete以后，endFindByDataDelete之前叫用
	///@return	下一个满足条件CSysMdbWebAppInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbWebAppInfo *findNextByDataDelete(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDataDelete(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysMdbWebAppInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbWebAppInfo	要加入的SysMdbWebAppInfo
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbWebAppInfo *internalAdd(CWriteableSysMdbWebAppInfo *pSysMdbWebAppInfo, bool bNoTransaction);
	
	
	///刷新该CSysMdbWebAppInfo的键值
	///@param	pSysMdbWebAppInfo	被刷新的CSysMdbWebAppInfo
	///@param	pNewSysMdbWebAppInfo	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysMdbWebAppInfo *pSysMdbWebAppInfo, CWriteableSysMdbWebAppInfo *pNewSysMdbWebAppInfo, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysMdbWebAppInfo，同时删除其索引
	///@param	pSysMdbWebAppInfo	要删除的CSysMdbWebAppInfo
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysMdbWebAppInfo *pSysMdbWebAppInfo, bool bNoTransaction);
/*
	///检查某个CSysMdbWebAppInfo是否属于本对象工厂
	///@param	pSysMdbWebAppInfo	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysMdbWebAppInfo *pSysMdbWebAppInfo);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ObjectID+MonDate+MonTime的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照ObjectID，MonDate，MonTime检索时，存储的查询参数
	CVolumeType queryObjectIDInSearchByIDType;
	CDateType queryMonDateInSearchByIDType;
	CTimeType queryMonTimeInSearchByIDType;
	
	///按照ObjectID，MonDate，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByIDType;
	///按照ObjectID检索时，存储的查询参数
	CVolumeType queryObjectIDInSearchByDsc;
	
	///按照ObjectID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDsc;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	///按照ObjectID，MonDate，MonTime检索时，存储的查询参数
	CVolumeType queryObjectIDInSearchByDataDelete;
	CDateType queryMonDateInSearchByDataDelete;
	CTimeType queryMonTimeInSearchByDataDelete;
	
	///按照ObjectID，MonDate，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDataDelete;
	
	///加入前触发
	///@param	pSysMdbWebAppInfo	要加入的SysMdbWebAppInfo
	virtual void beforeAdd(CWriteableSysMdbWebAppInfo *pSysMdbWebAppInfo);
	
	///加入后触发
	///@param	pSysMdbWebAppInfo	已经加入的SysMdbWebAppInfo
	virtual void afterAdd(CSysMdbWebAppInfo *pSysMdbWebAppInfo);

	///更新前触发	
	///@param	pSysMdbWebAppInfo	被刷新的CSysMdbWebAppInfo
	///@param	pNewSysMdbWebAppInfo	新的值
	virtual void beforeUpdate(CSysMdbWebAppInfo *pSysMdbWebAppInfo, CWriteableSysMdbWebAppInfo *pNewSysMdbWebAppInfo);
	
	///更新后触发
	///@param	pSysMdbWebAppInfo	被刷新的CSysMdbWebAppInfo
	virtual void afterUpdate(CSysMdbWebAppInfo *pSysMdbWebAppInfo);
	
	///删除前触发
	///@param	pSysMdbWebAppInfo	要删除的CSysMdbWebAppInfo
	virtual void beforeRemove(CSysMdbWebAppInfo *pSysMdbWebAppInfo);
	
	///确认加入后触发
	///@param	pSysMdbWebAppInfo	已经加入的SysMdbWebAppInfo
	virtual void commitAdd(CSysMdbWebAppInfo *pSysMdbWebAppInfo);

	///确认更新后触发
	///@param	pSysMdbWebAppInfo	被刷新的CSysMdbWebAppInfo
	///@param	poldSysMdbWebAppInfo	原来的值
	virtual void commitUpdate(CSysMdbWebAppInfo *pSysMdbWebAppInfo, CWriteableSysMdbWebAppInfo *pOldSysMdbWebAppInfo);
	
	///确认删除后触发
	///@param	pSysMdbWebAppInfo	已经删除的CSysMdbWebAppInfo
	virtual void commitRemove(CWriteableSysMdbWebAppInfo *pSysMdbWebAppInfo);

	///所有相关的触发器
	vector<CSysMdbWebAppInfoActionTrigger *> *pActionTriggers;
	vector<CSysMdbWebAppInfoCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysMdbWebAppInfo compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoFactory是一个系统内存池信息的对象工厂。它包含了一批系统内存池信息，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对系统内存池信息的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByIDType，findNextByIDType和endFindByIDType完成查询操作
///		使用startFindByDsc，findNextByDsc和endFindByDsc完成查询操作
///		使用findByOne，唯一找到对象
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///		使用startFindByDataDelete，findNextByDataDelete和endFindByDataDelete完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbMemPoolInfoFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysMdbMemPoolInfo，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbMemPoolInfoFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbMemPoolInfoFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysMdbMemPoolInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysMdbMemPoolInfo，文件名将根据配置文件中的定义SysMdbMemPoolInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysMdbMemPoolInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysMdbMemPoolInfo，文件名将根据配置文件中的定义SysMdbMemPoolInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysMdbMemPoolInfoResource;

	///将一个CSysMdbMemPoolInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbMemPoolInfo	要加入的SysMdbMemPoolInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbMemPoolInfo *add(CWriteableSysMdbMemPoolInfo *pSysMdbMemPoolInfo, CTransaction *pTransaction=NULL);
	
	///刷新该CSysMdbMemPoolInfo的值
	///@param	pSysMdbMemPoolInfo	被刷新的CSysMdbMemPoolInfo
	///@param	pNewSysMdbMemPoolInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo, CWriteableSysMdbMemPoolInfo *pNewSysMdbMemPoolInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysMdbMemPoolInfo	  需要被刷新或者新增的CSysMdbMemPoolInfo,等于NULL表示是需要新增的
	///@param	pNewSysMdbMemPoolInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysMdbMemPoolInfo* addOrUpdate(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo, CWriteableSysMdbMemPoolInfo *pNewSysMdbMemPoolInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysMdbMemPoolInfo，同时删除其索引
	///@param	pSysMdbMemPoolInfo	要删除的CSysMdbMemPoolInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo, CTransaction *pTransaction=NULL);
	
	///获取某个CSysMdbMemPoolInfo
	///@param	pSysMdbMemPoolInfo	要读取的CSysMdbMemPoolInfo
	///@param	pTragetSysMdbMemPoolInfo	存放结果的CSysMdbMemPoolInfo
	void retrieve(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo, CWriteableSysMdbMemPoolInfo *pTargetSysMdbMemPoolInfo);
	
	///获取第一个CSysMdbMemPoolInfo
	///@return	得到的第一个CSysMdbMemPoolInfo，如果没有，则返回NULL
	CSysMdbMemPoolInfo *getFirst(void);
	
	///获取下一个CSysMdbMemPoolInfo
	///@return	得到下一个CSysMdbMemPoolInfo，如果没有，则返回NULL
	CSysMdbMemPoolInfo *getNext(void);
	
	///结束获取CSysMdbMemPoolInfo
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysMdbMemPoolInfoActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysMdbMemPoolInfoActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysMdbMemPoolInfoCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysMdbMemPoolInfoCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysMdbMemPoolInfoIteratorByIDType;

	///开始寻找CSysMdbMemPoolInfo
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	///@return	满足条件的地一个CSysMdbMemPoolInfo，如果找不到，返回NULL
	CSysMdbMemPoolInfo *startFindByIDType( const CReadOnlyVolumeType& ObjectID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysMdbMemPoolInfo，必须在startFindByIDType以后，endFindByIDType之前叫用
	///@return	下一个满足条件CSysMdbMemPoolInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbMemPoolInfo *findNextByIDType(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByIDType(void);

	friend class CSysMdbMemPoolInfoIteratorByDsc;

	///开始寻找CSysMdbMemPoolInfo
	///@param	ObjectID	
	///@return	满足条件的地一个CSysMdbMemPoolInfo，如果找不到，返回NULL
	CSysMdbMemPoolInfo *startFindByDsc( const CReadOnlyVolumeType& ObjectID);

	///寻找下一个符合条件的CSysMdbMemPoolInfo，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbMemPoolInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbMemPoolInfo *findNextByDsc(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDsc(void);

	///寻找CSysMdbMemPoolInfo
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	///@return	找到的CSysMdbMemPoolInfo，如果找不到，返回NULL
	CSysMdbMemPoolInfo *findByOne( const CReadOnlyVolumeType&  ObjectID,  const CReadOnlyDateType&  MonDate,  const CReadOnlyTimeType&  MonTime);



	friend class CSysMdbMemPoolInfoIteratorBytheAll;

	///开始寻找CSysMdbMemPoolInfo
	///@return	满足条件的地一个CSysMdbMemPoolInfo，如果找不到，返回NULL
	CSysMdbMemPoolInfo *startFindBytheAll();

	///寻找下一个符合条件的CSysMdbMemPoolInfo，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbMemPoolInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbMemPoolInfo *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

	friend class CSysMdbMemPoolInfoIteratorByDataDelete;

	///开始寻找CSysMdbMemPoolInfo
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	///@return	满足条件的地一个CSysMdbMemPoolInfo，如果找不到，返回NULL
	CSysMdbMemPoolInfo *startFindByDataDelete( const CReadOnlyVolumeType& ObjectID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysMdbMemPoolInfo，必须在startFindByDataDelete以后，endFindByDataDelete之前叫用
	///@return	下一个满足条件CSysMdbMemPoolInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbMemPoolInfo *findNextByDataDelete(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDataDelete(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysMdbMemPoolInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbMemPoolInfo	要加入的SysMdbMemPoolInfo
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbMemPoolInfo *internalAdd(CWriteableSysMdbMemPoolInfo *pSysMdbMemPoolInfo, bool bNoTransaction);
	
	
	///刷新该CSysMdbMemPoolInfo的键值
	///@param	pSysMdbMemPoolInfo	被刷新的CSysMdbMemPoolInfo
	///@param	pNewSysMdbMemPoolInfo	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo, CWriteableSysMdbMemPoolInfo *pNewSysMdbMemPoolInfo, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysMdbMemPoolInfo，同时删除其索引
	///@param	pSysMdbMemPoolInfo	要删除的CSysMdbMemPoolInfo
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo, bool bNoTransaction);
/*
	///检查某个CSysMdbMemPoolInfo是否属于本对象工厂
	///@param	pSysMdbMemPoolInfo	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ObjectID+MonDate+MonTime的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照ObjectID，MonDate，MonTime检索时，存储的查询参数
	CVolumeType queryObjectIDInSearchByIDType;
	CDateType queryMonDateInSearchByIDType;
	CTimeType queryMonTimeInSearchByIDType;
	
	///按照ObjectID，MonDate，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByIDType;
	///按照ObjectID检索时，存储的查询参数
	CVolumeType queryObjectIDInSearchByDsc;
	
	///按照ObjectID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDsc;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	///按照ObjectID，MonDate，MonTime检索时，存储的查询参数
	CVolumeType queryObjectIDInSearchByDataDelete;
	CDateType queryMonDateInSearchByDataDelete;
	CTimeType queryMonTimeInSearchByDataDelete;
	
	///按照ObjectID，MonDate，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDataDelete;
	
	///加入前触发
	///@param	pSysMdbMemPoolInfo	要加入的SysMdbMemPoolInfo
	virtual void beforeAdd(CWriteableSysMdbMemPoolInfo *pSysMdbMemPoolInfo);
	
	///加入后触发
	///@param	pSysMdbMemPoolInfo	已经加入的SysMdbMemPoolInfo
	virtual void afterAdd(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo);

	///更新前触发	
	///@param	pSysMdbMemPoolInfo	被刷新的CSysMdbMemPoolInfo
	///@param	pNewSysMdbMemPoolInfo	新的值
	virtual void beforeUpdate(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo, CWriteableSysMdbMemPoolInfo *pNewSysMdbMemPoolInfo);
	
	///更新后触发
	///@param	pSysMdbMemPoolInfo	被刷新的CSysMdbMemPoolInfo
	virtual void afterUpdate(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo);
	
	///删除前触发
	///@param	pSysMdbMemPoolInfo	要删除的CSysMdbMemPoolInfo
	virtual void beforeRemove(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo);
	
	///确认加入后触发
	///@param	pSysMdbMemPoolInfo	已经加入的SysMdbMemPoolInfo
	virtual void commitAdd(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo);

	///确认更新后触发
	///@param	pSysMdbMemPoolInfo	被刷新的CSysMdbMemPoolInfo
	///@param	poldSysMdbMemPoolInfo	原来的值
	virtual void commitUpdate(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo, CWriteableSysMdbMemPoolInfo *pOldSysMdbMemPoolInfo);
	
	///确认删除后触发
	///@param	pSysMdbMemPoolInfo	已经删除的CSysMdbMemPoolInfo
	virtual void commitRemove(CWriteableSysMdbMemPoolInfo *pSysMdbMemPoolInfo);

	///所有相关的触发器
	vector<CSysMdbMemPoolInfoActionTrigger *> *pActionTriggers;
	vector<CSysMdbMemPoolInfoCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysMdbMemPoolInfo compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoFactory是一个连接器信息的对象工厂。它包含了一批连接器信息，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对连接器信息的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByIDType，findNextByIDType和endFindByIDType完成查询操作
///		使用startFindByDsc，findNextByDsc和endFindByDsc完成查询操作
///		使用findByOne，唯一找到对象
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///		使用startFindByDataDelete，findNextByDataDelete和endFindByDataDelete完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbConnectorInfoFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysMdbConnectorInfo，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbConnectorInfoFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbConnectorInfoFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysMdbConnectorInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysMdbConnectorInfo，文件名将根据配置文件中的定义SysMdbConnectorInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysMdbConnectorInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysMdbConnectorInfo，文件名将根据配置文件中的定义SysMdbConnectorInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysMdbConnectorInfoResource;

	///将一个CSysMdbConnectorInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbConnectorInfo	要加入的SysMdbConnectorInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbConnectorInfo *add(CWriteableSysMdbConnectorInfo *pSysMdbConnectorInfo, CTransaction *pTransaction=NULL);
	
	///刷新该CSysMdbConnectorInfo的值
	///@param	pSysMdbConnectorInfo	被刷新的CSysMdbConnectorInfo
	///@param	pNewSysMdbConnectorInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysMdbConnectorInfo *pSysMdbConnectorInfo, CWriteableSysMdbConnectorInfo *pNewSysMdbConnectorInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysMdbConnectorInfo	  需要被刷新或者新增的CSysMdbConnectorInfo,等于NULL表示是需要新增的
	///@param	pNewSysMdbConnectorInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysMdbConnectorInfo* addOrUpdate(CSysMdbConnectorInfo *pSysMdbConnectorInfo, CWriteableSysMdbConnectorInfo *pNewSysMdbConnectorInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysMdbConnectorInfo，同时删除其索引
	///@param	pSysMdbConnectorInfo	要删除的CSysMdbConnectorInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysMdbConnectorInfo *pSysMdbConnectorInfo, CTransaction *pTransaction=NULL);
	
	///获取某个CSysMdbConnectorInfo
	///@param	pSysMdbConnectorInfo	要读取的CSysMdbConnectorInfo
	///@param	pTragetSysMdbConnectorInfo	存放结果的CSysMdbConnectorInfo
	void retrieve(CSysMdbConnectorInfo *pSysMdbConnectorInfo, CWriteableSysMdbConnectorInfo *pTargetSysMdbConnectorInfo);
	
	///获取第一个CSysMdbConnectorInfo
	///@return	得到的第一个CSysMdbConnectorInfo，如果没有，则返回NULL
	CSysMdbConnectorInfo *getFirst(void);
	
	///获取下一个CSysMdbConnectorInfo
	///@return	得到下一个CSysMdbConnectorInfo，如果没有，则返回NULL
	CSysMdbConnectorInfo *getNext(void);
	
	///结束获取CSysMdbConnectorInfo
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysMdbConnectorInfoActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysMdbConnectorInfoActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysMdbConnectorInfoCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysMdbConnectorInfoCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysMdbConnectorInfoIteratorByIDType;

	///开始寻找CSysMdbConnectorInfo
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	///@return	满足条件的地一个CSysMdbConnectorInfo，如果找不到，返回NULL
	CSysMdbConnectorInfo *startFindByIDType( const CReadOnlyVolumeType& ObjectID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysMdbConnectorInfo，必须在startFindByIDType以后，endFindByIDType之前叫用
	///@return	下一个满足条件CSysMdbConnectorInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbConnectorInfo *findNextByIDType(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByIDType(void);

	friend class CSysMdbConnectorInfoIteratorByDsc;

	///开始寻找CSysMdbConnectorInfo
	///@param	ObjectID	
	///@return	满足条件的地一个CSysMdbConnectorInfo，如果找不到，返回NULL
	CSysMdbConnectorInfo *startFindByDsc( const CReadOnlyVolumeType& ObjectID);

	///寻找下一个符合条件的CSysMdbConnectorInfo，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbConnectorInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbConnectorInfo *findNextByDsc(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDsc(void);

	///寻找CSysMdbConnectorInfo
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	///@return	找到的CSysMdbConnectorInfo，如果找不到，返回NULL
	CSysMdbConnectorInfo *findByOne( const CReadOnlyVolumeType&  ObjectID,  const CReadOnlyDateType&  MonDate,  const CReadOnlyTimeType&  MonTime);



	friend class CSysMdbConnectorInfoIteratorBytheAll;

	///开始寻找CSysMdbConnectorInfo
	///@return	满足条件的地一个CSysMdbConnectorInfo，如果找不到，返回NULL
	CSysMdbConnectorInfo *startFindBytheAll();

	///寻找下一个符合条件的CSysMdbConnectorInfo，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbConnectorInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbConnectorInfo *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

	friend class CSysMdbConnectorInfoIteratorByDataDelete;

	///开始寻找CSysMdbConnectorInfo
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	///@return	满足条件的地一个CSysMdbConnectorInfo，如果找不到，返回NULL
	CSysMdbConnectorInfo *startFindByDataDelete( const CReadOnlyVolumeType& ObjectID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysMdbConnectorInfo，必须在startFindByDataDelete以后，endFindByDataDelete之前叫用
	///@return	下一个满足条件CSysMdbConnectorInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbConnectorInfo *findNextByDataDelete(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDataDelete(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysMdbConnectorInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbConnectorInfo	要加入的SysMdbConnectorInfo
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbConnectorInfo *internalAdd(CWriteableSysMdbConnectorInfo *pSysMdbConnectorInfo, bool bNoTransaction);
	
	
	///刷新该CSysMdbConnectorInfo的键值
	///@param	pSysMdbConnectorInfo	被刷新的CSysMdbConnectorInfo
	///@param	pNewSysMdbConnectorInfo	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysMdbConnectorInfo *pSysMdbConnectorInfo, CWriteableSysMdbConnectorInfo *pNewSysMdbConnectorInfo, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysMdbConnectorInfo，同时删除其索引
	///@param	pSysMdbConnectorInfo	要删除的CSysMdbConnectorInfo
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysMdbConnectorInfo *pSysMdbConnectorInfo, bool bNoTransaction);
/*
	///检查某个CSysMdbConnectorInfo是否属于本对象工厂
	///@param	pSysMdbConnectorInfo	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysMdbConnectorInfo *pSysMdbConnectorInfo);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ObjectID+MonDate+MonTime的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照ObjectID，MonDate，MonTime检索时，存储的查询参数
	CVolumeType queryObjectIDInSearchByIDType;
	CDateType queryMonDateInSearchByIDType;
	CTimeType queryMonTimeInSearchByIDType;
	
	///按照ObjectID，MonDate，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByIDType;
	///按照ObjectID检索时，存储的查询参数
	CVolumeType queryObjectIDInSearchByDsc;
	
	///按照ObjectID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDsc;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	///按照ObjectID，MonDate，MonTime检索时，存储的查询参数
	CVolumeType queryObjectIDInSearchByDataDelete;
	CDateType queryMonDateInSearchByDataDelete;
	CTimeType queryMonTimeInSearchByDataDelete;
	
	///按照ObjectID，MonDate，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDataDelete;
	
	///加入前触发
	///@param	pSysMdbConnectorInfo	要加入的SysMdbConnectorInfo
	virtual void beforeAdd(CWriteableSysMdbConnectorInfo *pSysMdbConnectorInfo);
	
	///加入后触发
	///@param	pSysMdbConnectorInfo	已经加入的SysMdbConnectorInfo
	virtual void afterAdd(CSysMdbConnectorInfo *pSysMdbConnectorInfo);

	///更新前触发	
	///@param	pSysMdbConnectorInfo	被刷新的CSysMdbConnectorInfo
	///@param	pNewSysMdbConnectorInfo	新的值
	virtual void beforeUpdate(CSysMdbConnectorInfo *pSysMdbConnectorInfo, CWriteableSysMdbConnectorInfo *pNewSysMdbConnectorInfo);
	
	///更新后触发
	///@param	pSysMdbConnectorInfo	被刷新的CSysMdbConnectorInfo
	virtual void afterUpdate(CSysMdbConnectorInfo *pSysMdbConnectorInfo);
	
	///删除前触发
	///@param	pSysMdbConnectorInfo	要删除的CSysMdbConnectorInfo
	virtual void beforeRemove(CSysMdbConnectorInfo *pSysMdbConnectorInfo);
	
	///确认加入后触发
	///@param	pSysMdbConnectorInfo	已经加入的SysMdbConnectorInfo
	virtual void commitAdd(CSysMdbConnectorInfo *pSysMdbConnectorInfo);

	///确认更新后触发
	///@param	pSysMdbConnectorInfo	被刷新的CSysMdbConnectorInfo
	///@param	poldSysMdbConnectorInfo	原来的值
	virtual void commitUpdate(CSysMdbConnectorInfo *pSysMdbConnectorInfo, CWriteableSysMdbConnectorInfo *pOldSysMdbConnectorInfo);
	
	///确认删除后触发
	///@param	pSysMdbConnectorInfo	已经删除的CSysMdbConnectorInfo
	virtual void commitRemove(CWriteableSysMdbConnectorInfo *pSysMdbConnectorInfo);

	///所有相关的触发器
	vector<CSysMdbConnectorInfoActionTrigger *> *pActionTriggers;
	vector<CSysMdbConnectorInfoCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysMdbConnectorInfo compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryFactory是一个数据库查询应答的对象工厂。它包含了一批数据库查询应答，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对数据库查询应答的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByIDType，findNextByIDType和endFindByIDType完成查询操作
///		使用startFindByDsc，findNextByDsc和endFindByDsc完成查询操作
///		使用findByOne，唯一找到对象
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///		使用startFindByDataDelete，findNextByDataDelete和endFindByDataDelete完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbDBQueryFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysMdbDBQuery，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbDBQueryFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbDBQueryFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysMdbDBQuery
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysMdbDBQuery，文件名将根据配置文件中的定义SysMdbDBQueryCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysMdbDBQuery
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysMdbDBQuery，文件名将根据配置文件中的定义SysMdbDBQueryCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysMdbDBQueryResource;

	///将一个CSysMdbDBQuery加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbDBQuery	要加入的SysMdbDBQuery
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbDBQuery *add(CWriteableSysMdbDBQuery *pSysMdbDBQuery, CTransaction *pTransaction=NULL);
	
	///刷新该CSysMdbDBQuery的值
	///@param	pSysMdbDBQuery	被刷新的CSysMdbDBQuery
	///@param	pNewSysMdbDBQuery	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysMdbDBQuery *pSysMdbDBQuery, CWriteableSysMdbDBQuery *pNewSysMdbDBQuery, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysMdbDBQuery	  需要被刷新或者新增的CSysMdbDBQuery,等于NULL表示是需要新增的
	///@param	pNewSysMdbDBQuery	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysMdbDBQuery* addOrUpdate(CSysMdbDBQuery *pSysMdbDBQuery, CWriteableSysMdbDBQuery *pNewSysMdbDBQuery, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysMdbDBQuery，同时删除其索引
	///@param	pSysMdbDBQuery	要删除的CSysMdbDBQuery
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysMdbDBQuery *pSysMdbDBQuery, CTransaction *pTransaction=NULL);
	
	///获取某个CSysMdbDBQuery
	///@param	pSysMdbDBQuery	要读取的CSysMdbDBQuery
	///@param	pTragetSysMdbDBQuery	存放结果的CSysMdbDBQuery
	void retrieve(CSysMdbDBQuery *pSysMdbDBQuery, CWriteableSysMdbDBQuery *pTargetSysMdbDBQuery);
	
	///获取第一个CSysMdbDBQuery
	///@return	得到的第一个CSysMdbDBQuery，如果没有，则返回NULL
	CSysMdbDBQuery *getFirst(void);
	
	///获取下一个CSysMdbDBQuery
	///@return	得到下一个CSysMdbDBQuery，如果没有，则返回NULL
	CSysMdbDBQuery *getNext(void);
	
	///结束获取CSysMdbDBQuery
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysMdbDBQueryActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysMdbDBQueryActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysMdbDBQueryCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysMdbDBQueryCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysMdbDBQueryIteratorByIDType;

	///开始寻找CSysMdbDBQuery
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	///@return	满足条件的地一个CSysMdbDBQuery，如果找不到，返回NULL
	CSysMdbDBQuery *startFindByIDType( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysMdbDBQuery，必须在startFindByIDType以后，endFindByIDType之前叫用
	///@return	下一个满足条件CSysMdbDBQuery，如果已经没有一个满足要求了，则返回NULL
	CSysMdbDBQuery *findNextByIDType(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByIDType(void);

	friend class CSysMdbDBQueryIteratorByDsc;

	///开始寻找CSysMdbDBQuery
	///@param	SubcriberID	
	///@return	满足条件的地一个CSysMdbDBQuery，如果找不到，返回NULL
	CSysMdbDBQuery *startFindByDsc( const CReadOnlyVolumeType& SubcriberID);

	///寻找下一个符合条件的CSysMdbDBQuery，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbDBQuery，如果已经没有一个满足要求了，则返回NULL
	CSysMdbDBQuery *findNextByDsc(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDsc(void);

	///寻找CSysMdbDBQuery
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	///@return	找到的CSysMdbDBQuery，如果找不到，返回NULL
	CSysMdbDBQuery *findByOne( const CReadOnlyVolumeType&  SubcriberID,  const CReadOnlyDateType&  MonDate,  const CReadOnlyTimeType&  MonTime);



	friend class CSysMdbDBQueryIteratorBytheAll;

	///开始寻找CSysMdbDBQuery
	///@return	满足条件的地一个CSysMdbDBQuery，如果找不到，返回NULL
	CSysMdbDBQuery *startFindBytheAll();

	///寻找下一个符合条件的CSysMdbDBQuery，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbDBQuery，如果已经没有一个满足要求了，则返回NULL
	CSysMdbDBQuery *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

	friend class CSysMdbDBQueryIteratorByDataDelete;

	///开始寻找CSysMdbDBQuery
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	///@return	满足条件的地一个CSysMdbDBQuery，如果找不到，返回NULL
	CSysMdbDBQuery *startFindByDataDelete( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysMdbDBQuery，必须在startFindByDataDelete以后，endFindByDataDelete之前叫用
	///@return	下一个满足条件CSysMdbDBQuery，如果已经没有一个满足要求了，则返回NULL
	CSysMdbDBQuery *findNextByDataDelete(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDataDelete(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysMdbDBQuery加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbDBQuery	要加入的SysMdbDBQuery
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbDBQuery *internalAdd(CWriteableSysMdbDBQuery *pSysMdbDBQuery, bool bNoTransaction);
	
	
	///刷新该CSysMdbDBQuery的键值
	///@param	pSysMdbDBQuery	被刷新的CSysMdbDBQuery
	///@param	pNewSysMdbDBQuery	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysMdbDBQuery *pSysMdbDBQuery, CWriteableSysMdbDBQuery *pNewSysMdbDBQuery, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysMdbDBQuery，同时删除其索引
	///@param	pSysMdbDBQuery	要删除的CSysMdbDBQuery
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysMdbDBQuery *pSysMdbDBQuery, bool bNoTransaction);
/*
	///检查某个CSysMdbDBQuery是否属于本对象工厂
	///@param	pSysMdbDBQuery	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysMdbDBQuery *pSysMdbDBQuery);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于SubcriberID+MonDate+MonTime的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照SubcriberID，MonDate，MonTime检索时，存储的查询参数
	CVolumeType querySubcriberIDInSearchByIDType;
	CDateType queryMonDateInSearchByIDType;
	CTimeType queryMonTimeInSearchByIDType;
	
	///按照SubcriberID，MonDate，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByIDType;
	///按照SubcriberID检索时，存储的查询参数
	CVolumeType querySubcriberIDInSearchByDsc;
	
	///按照SubcriberID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDsc;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	///按照SubcriberID，MonDate，MonTime检索时，存储的查询参数
	CVolumeType querySubcriberIDInSearchByDataDelete;
	CDateType queryMonDateInSearchByDataDelete;
	CTimeType queryMonTimeInSearchByDataDelete;
	
	///按照SubcriberID，MonDate，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDataDelete;
	
	///加入前触发
	///@param	pSysMdbDBQuery	要加入的SysMdbDBQuery
	virtual void beforeAdd(CWriteableSysMdbDBQuery *pSysMdbDBQuery);
	
	///加入后触发
	///@param	pSysMdbDBQuery	已经加入的SysMdbDBQuery
	virtual void afterAdd(CSysMdbDBQuery *pSysMdbDBQuery);

	///更新前触发	
	///@param	pSysMdbDBQuery	被刷新的CSysMdbDBQuery
	///@param	pNewSysMdbDBQuery	新的值
	virtual void beforeUpdate(CSysMdbDBQuery *pSysMdbDBQuery, CWriteableSysMdbDBQuery *pNewSysMdbDBQuery);
	
	///更新后触发
	///@param	pSysMdbDBQuery	被刷新的CSysMdbDBQuery
	virtual void afterUpdate(CSysMdbDBQuery *pSysMdbDBQuery);
	
	///删除前触发
	///@param	pSysMdbDBQuery	要删除的CSysMdbDBQuery
	virtual void beforeRemove(CSysMdbDBQuery *pSysMdbDBQuery);
	
	///确认加入后触发
	///@param	pSysMdbDBQuery	已经加入的SysMdbDBQuery
	virtual void commitAdd(CSysMdbDBQuery *pSysMdbDBQuery);

	///确认更新后触发
	///@param	pSysMdbDBQuery	被刷新的CSysMdbDBQuery
	///@param	poldSysMdbDBQuery	原来的值
	virtual void commitUpdate(CSysMdbDBQuery *pSysMdbDBQuery, CWriteableSysMdbDBQuery *pOldSysMdbDBQuery);
	
	///确认删除后触发
	///@param	pSysMdbDBQuery	已经删除的CSysMdbDBQuery
	virtual void commitRemove(CWriteableSysMdbDBQuery *pSysMdbDBQuery);

	///所有相关的触发器
	vector<CSysMdbDBQueryActionTrigger *> *pActionTriggers;
	vector<CSysMdbDBQueryCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysMdbDBQuery compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetAreaFactory是一个网络大区划分的对象工厂。它包含了一批网络大区划分，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对网络大区划分的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetAreaFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetAreaFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetArea，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetAreaFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetAreaFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetArea
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetArea，文件名将根据配置文件中的定义SysNetAreaCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetArea
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetArea，文件名将根据配置文件中的定义SysNetAreaCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetAreaResource;

	///将一个CSysNetArea加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetArea	要加入的SysNetArea
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetArea *add(CWriteableSysNetArea *pSysNetArea, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetArea的值
	///@param	pSysNetArea	被刷新的CSysNetArea
	///@param	pNewSysNetArea	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetArea *pSysNetArea, CWriteableSysNetArea *pNewSysNetArea, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetArea	  需要被刷新或者新增的CSysNetArea,等于NULL表示是需要新增的
	///@param	pNewSysNetArea	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetArea* addOrUpdate(CSysNetArea *pSysNetArea, CWriteableSysNetArea *pNewSysNetArea, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetArea，同时删除其索引
	///@param	pSysNetArea	要删除的CSysNetArea
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetArea *pSysNetArea, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetArea
	///@param	pSysNetArea	要读取的CSysNetArea
	///@param	pTragetSysNetArea	存放结果的CSysNetArea
	void retrieve(CSysNetArea *pSysNetArea, CWriteableSysNetArea *pTargetSysNetArea);
	
	///获取第一个CSysNetArea
	///@return	得到的第一个CSysNetArea，如果没有，则返回NULL
	CSysNetArea *getFirst(void);
	
	///获取下一个CSysNetArea
	///@return	得到下一个CSysNetArea，如果没有，则返回NULL
	CSysNetArea *getNext(void);
	
	///结束获取CSysNetArea
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetAreaActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetAreaActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetAreaCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetAreaCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetAreaIteratorByAll;

	///开始寻找CSysNetArea
	///@return	满足条件的地一个CSysNetArea，如果找不到，返回NULL
	CSysNetArea *startFindByAll();

	///寻找下一个符合条件的CSysNetArea，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetArea，如果已经没有一个满足要求了，则返回NULL
	CSysNetArea *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetArea
	///@param	ID	
	///@return	找到的CSysNetArea，如果找不到，返回NULL
	CSysNetArea *findByOne( const CReadOnlyVolumeType&  ID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetArea加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetArea	要加入的SysNetArea
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetArea *internalAdd(CWriteableSysNetArea *pSysNetArea, bool bNoTransaction);
	
	
	///刷新该CSysNetArea的键值
	///@param	pSysNetArea	被刷新的CSysNetArea
	///@param	pNewSysNetArea	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetArea *pSysNetArea, CWriteableSysNetArea *pNewSysNetArea, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetArea，同时删除其索引
	///@param	pSysNetArea	要删除的CSysNetArea
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetArea *pSysNetArea, bool bNoTransaction);
/*
	///检查某个CSysNetArea是否属于本对象工厂
	///@param	pSysNetArea	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetArea *pSysNetArea);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetArea	要加入的SysNetArea
	virtual void beforeAdd(CWriteableSysNetArea *pSysNetArea);
	
	///加入后触发
	///@param	pSysNetArea	已经加入的SysNetArea
	virtual void afterAdd(CSysNetArea *pSysNetArea);

	///更新前触发	
	///@param	pSysNetArea	被刷新的CSysNetArea
	///@param	pNewSysNetArea	新的值
	virtual void beforeUpdate(CSysNetArea *pSysNetArea, CWriteableSysNetArea *pNewSysNetArea);
	
	///更新后触发
	///@param	pSysNetArea	被刷新的CSysNetArea
	virtual void afterUpdate(CSysNetArea *pSysNetArea);
	
	///删除前触发
	///@param	pSysNetArea	要删除的CSysNetArea
	virtual void beforeRemove(CSysNetArea *pSysNetArea);
	
	///确认加入后触发
	///@param	pSysNetArea	已经加入的SysNetArea
	virtual void commitAdd(CSysNetArea *pSysNetArea);

	///确认更新后触发
	///@param	pSysNetArea	被刷新的CSysNetArea
	///@param	poldSysNetArea	原来的值
	virtual void commitUpdate(CSysNetArea *pSysNetArea, CWriteableSysNetArea *pOldSysNetArea);
	
	///确认删除后触发
	///@param	pSysNetArea	已经删除的CSysNetArea
	virtual void commitRemove(CWriteableSysNetArea *pSysNetArea);

	///所有相关的触发器
	vector<CSysNetAreaActionTrigger *> *pActionTriggers;
	vector<CSysNetAreaCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetArea compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaFactory是一个网络子区的对象工厂。它包含了一批网络子区，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对网络子区的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetSubAreaFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetSubArea，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetSubAreaFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetSubAreaFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetSubArea
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetSubArea，文件名将根据配置文件中的定义SysNetSubAreaCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetSubArea
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetSubArea，文件名将根据配置文件中的定义SysNetSubAreaCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetSubAreaResource;

	///将一个CSysNetSubArea加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetSubArea	要加入的SysNetSubArea
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetSubArea *add(CWriteableSysNetSubArea *pSysNetSubArea, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetSubArea的值
	///@param	pSysNetSubArea	被刷新的CSysNetSubArea
	///@param	pNewSysNetSubArea	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetSubArea *pSysNetSubArea, CWriteableSysNetSubArea *pNewSysNetSubArea, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetSubArea	  需要被刷新或者新增的CSysNetSubArea,等于NULL表示是需要新增的
	///@param	pNewSysNetSubArea	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetSubArea* addOrUpdate(CSysNetSubArea *pSysNetSubArea, CWriteableSysNetSubArea *pNewSysNetSubArea, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetSubArea，同时删除其索引
	///@param	pSysNetSubArea	要删除的CSysNetSubArea
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetSubArea *pSysNetSubArea, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetSubArea
	///@param	pSysNetSubArea	要读取的CSysNetSubArea
	///@param	pTragetSysNetSubArea	存放结果的CSysNetSubArea
	void retrieve(CSysNetSubArea *pSysNetSubArea, CWriteableSysNetSubArea *pTargetSysNetSubArea);
	
	///获取第一个CSysNetSubArea
	///@return	得到的第一个CSysNetSubArea，如果没有，则返回NULL
	CSysNetSubArea *getFirst(void);
	
	///获取下一个CSysNetSubArea
	///@return	得到下一个CSysNetSubArea，如果没有，则返回NULL
	CSysNetSubArea *getNext(void);
	
	///结束获取CSysNetSubArea
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetSubAreaActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetSubAreaActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetSubAreaCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetSubAreaCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetSubAreaIteratorByAll;

	///开始寻找CSysNetSubArea
	///@return	满足条件的地一个CSysNetSubArea，如果找不到，返回NULL
	CSysNetSubArea *startFindByAll();

	///寻找下一个符合条件的CSysNetSubArea，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetSubArea，如果已经没有一个满足要求了，则返回NULL
	CSysNetSubArea *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetSubArea
	///@param	ID	
	///@return	找到的CSysNetSubArea，如果找不到，返回NULL
	CSysNetSubArea *findByOne( const CReadOnlyVolumeType&  ID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetSubArea加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetSubArea	要加入的SysNetSubArea
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetSubArea *internalAdd(CWriteableSysNetSubArea *pSysNetSubArea, bool bNoTransaction);
	
	
	///刷新该CSysNetSubArea的键值
	///@param	pSysNetSubArea	被刷新的CSysNetSubArea
	///@param	pNewSysNetSubArea	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetSubArea *pSysNetSubArea, CWriteableSysNetSubArea *pNewSysNetSubArea, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetSubArea，同时删除其索引
	///@param	pSysNetSubArea	要删除的CSysNetSubArea
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetSubArea *pSysNetSubArea, bool bNoTransaction);
/*
	///检查某个CSysNetSubArea是否属于本对象工厂
	///@param	pSysNetSubArea	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetSubArea *pSysNetSubArea);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetSubArea	要加入的SysNetSubArea
	virtual void beforeAdd(CWriteableSysNetSubArea *pSysNetSubArea);
	
	///加入后触发
	///@param	pSysNetSubArea	已经加入的SysNetSubArea
	virtual void afterAdd(CSysNetSubArea *pSysNetSubArea);

	///更新前触发	
	///@param	pSysNetSubArea	被刷新的CSysNetSubArea
	///@param	pNewSysNetSubArea	新的值
	virtual void beforeUpdate(CSysNetSubArea *pSysNetSubArea, CWriteableSysNetSubArea *pNewSysNetSubArea);
	
	///更新后触发
	///@param	pSysNetSubArea	被刷新的CSysNetSubArea
	virtual void afterUpdate(CSysNetSubArea *pSysNetSubArea);
	
	///删除前触发
	///@param	pSysNetSubArea	要删除的CSysNetSubArea
	virtual void beforeRemove(CSysNetSubArea *pSysNetSubArea);
	
	///确认加入后触发
	///@param	pSysNetSubArea	已经加入的SysNetSubArea
	virtual void commitAdd(CSysNetSubArea *pSysNetSubArea);

	///确认更新后触发
	///@param	pSysNetSubArea	被刷新的CSysNetSubArea
	///@param	poldSysNetSubArea	原来的值
	virtual void commitUpdate(CSysNetSubArea *pSysNetSubArea, CWriteableSysNetSubArea *pOldSysNetSubArea);
	
	///确认删除后触发
	///@param	pSysNetSubArea	已经删除的CSysNetSubArea
	virtual void commitRemove(CWriteableSysNetSubArea *pSysNetSubArea);

	///所有相关的触发器
	vector<CSysNetSubAreaActionTrigger *> *pActionTriggers;
	vector<CSysNetSubAreaCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetSubArea compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIPFactory是一个网络子区IP的对象工厂。它包含了一批网络子区IP，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对网络子区IP的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIPFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetSubAreaIPFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetSubAreaIP，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetSubAreaIPFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetSubAreaIPFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetSubAreaIP
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetSubAreaIP，文件名将根据配置文件中的定义SysNetSubAreaIPCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetSubAreaIP
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetSubAreaIP，文件名将根据配置文件中的定义SysNetSubAreaIPCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetSubAreaIPResource;

	///将一个CSysNetSubAreaIP加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetSubAreaIP	要加入的SysNetSubAreaIP
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetSubAreaIP *add(CWriteableSysNetSubAreaIP *pSysNetSubAreaIP, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetSubAreaIP的值
	///@param	pSysNetSubAreaIP	被刷新的CSysNetSubAreaIP
	///@param	pNewSysNetSubAreaIP	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetSubAreaIP *pSysNetSubAreaIP, CWriteableSysNetSubAreaIP *pNewSysNetSubAreaIP, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetSubAreaIP	  需要被刷新或者新增的CSysNetSubAreaIP,等于NULL表示是需要新增的
	///@param	pNewSysNetSubAreaIP	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetSubAreaIP* addOrUpdate(CSysNetSubAreaIP *pSysNetSubAreaIP, CWriteableSysNetSubAreaIP *pNewSysNetSubAreaIP, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetSubAreaIP，同时删除其索引
	///@param	pSysNetSubAreaIP	要删除的CSysNetSubAreaIP
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetSubAreaIP *pSysNetSubAreaIP, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetSubAreaIP
	///@param	pSysNetSubAreaIP	要读取的CSysNetSubAreaIP
	///@param	pTragetSysNetSubAreaIP	存放结果的CSysNetSubAreaIP
	void retrieve(CSysNetSubAreaIP *pSysNetSubAreaIP, CWriteableSysNetSubAreaIP *pTargetSysNetSubAreaIP);
	
	///获取第一个CSysNetSubAreaIP
	///@return	得到的第一个CSysNetSubAreaIP，如果没有，则返回NULL
	CSysNetSubAreaIP *getFirst(void);
	
	///获取下一个CSysNetSubAreaIP
	///@return	得到下一个CSysNetSubAreaIP，如果没有，则返回NULL
	CSysNetSubAreaIP *getNext(void);
	
	///结束获取CSysNetSubAreaIP
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetSubAreaIPActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetSubAreaIPActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetSubAreaIPCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetSubAreaIPCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetSubAreaIPIteratorByAll;

	///开始寻找CSysNetSubAreaIP
	///@return	满足条件的地一个CSysNetSubAreaIP，如果找不到，返回NULL
	CSysNetSubAreaIP *startFindByAll();

	///寻找下一个符合条件的CSysNetSubAreaIP，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetSubAreaIP，如果已经没有一个满足要求了，则返回NULL
	CSysNetSubAreaIP *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetSubAreaIP
	///@param	ID	
	///@return	找到的CSysNetSubAreaIP，如果找不到，返回NULL
	CSysNetSubAreaIP *findByOne( const CReadOnlyVolumeType&  ID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetSubAreaIP加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetSubAreaIP	要加入的SysNetSubAreaIP
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetSubAreaIP *internalAdd(CWriteableSysNetSubAreaIP *pSysNetSubAreaIP, bool bNoTransaction);
	
	
	///刷新该CSysNetSubAreaIP的键值
	///@param	pSysNetSubAreaIP	被刷新的CSysNetSubAreaIP
	///@param	pNewSysNetSubAreaIP	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetSubAreaIP *pSysNetSubAreaIP, CWriteableSysNetSubAreaIP *pNewSysNetSubAreaIP, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetSubAreaIP，同时删除其索引
	///@param	pSysNetSubAreaIP	要删除的CSysNetSubAreaIP
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetSubAreaIP *pSysNetSubAreaIP, bool bNoTransaction);
/*
	///检查某个CSysNetSubAreaIP是否属于本对象工厂
	///@param	pSysNetSubAreaIP	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetSubAreaIP *pSysNetSubAreaIP);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetSubAreaIP	要加入的SysNetSubAreaIP
	virtual void beforeAdd(CWriteableSysNetSubAreaIP *pSysNetSubAreaIP);
	
	///加入后触发
	///@param	pSysNetSubAreaIP	已经加入的SysNetSubAreaIP
	virtual void afterAdd(CSysNetSubAreaIP *pSysNetSubAreaIP);

	///更新前触发	
	///@param	pSysNetSubAreaIP	被刷新的CSysNetSubAreaIP
	///@param	pNewSysNetSubAreaIP	新的值
	virtual void beforeUpdate(CSysNetSubAreaIP *pSysNetSubAreaIP, CWriteableSysNetSubAreaIP *pNewSysNetSubAreaIP);
	
	///更新后触发
	///@param	pSysNetSubAreaIP	被刷新的CSysNetSubAreaIP
	virtual void afterUpdate(CSysNetSubAreaIP *pSysNetSubAreaIP);
	
	///删除前触发
	///@param	pSysNetSubAreaIP	要删除的CSysNetSubAreaIP
	virtual void beforeRemove(CSysNetSubAreaIP *pSysNetSubAreaIP);
	
	///确认加入后触发
	///@param	pSysNetSubAreaIP	已经加入的SysNetSubAreaIP
	virtual void commitAdd(CSysNetSubAreaIP *pSysNetSubAreaIP);

	///确认更新后触发
	///@param	pSysNetSubAreaIP	被刷新的CSysNetSubAreaIP
	///@param	poldSysNetSubAreaIP	原来的值
	virtual void commitUpdate(CSysNetSubAreaIP *pSysNetSubAreaIP, CWriteableSysNetSubAreaIP *pOldSysNetSubAreaIP);
	
	///确认删除后触发
	///@param	pSysNetSubAreaIP	已经删除的CSysNetSubAreaIP
	virtual void commitRemove(CWriteableSysNetSubAreaIP *pSysNetSubAreaIP);

	///所有相关的触发器
	vector<CSysNetSubAreaIPActionTrigger *> *pActionTriggers;
	vector<CSysNetSubAreaIPCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetSubAreaIP compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetFuncAreaFactory是一个职能区的对象工厂。它包含了一批职能区，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对职能区的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetFuncAreaFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetFuncAreaFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetFuncArea，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetFuncAreaFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetFuncAreaFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetFuncArea
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetFuncArea，文件名将根据配置文件中的定义SysNetFuncAreaCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetFuncArea
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetFuncArea，文件名将根据配置文件中的定义SysNetFuncAreaCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetFuncAreaResource;

	///将一个CSysNetFuncArea加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetFuncArea	要加入的SysNetFuncArea
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetFuncArea *add(CWriteableSysNetFuncArea *pSysNetFuncArea, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetFuncArea的值
	///@param	pSysNetFuncArea	被刷新的CSysNetFuncArea
	///@param	pNewSysNetFuncArea	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetFuncArea *pSysNetFuncArea, CWriteableSysNetFuncArea *pNewSysNetFuncArea, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetFuncArea	  需要被刷新或者新增的CSysNetFuncArea,等于NULL表示是需要新增的
	///@param	pNewSysNetFuncArea	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetFuncArea* addOrUpdate(CSysNetFuncArea *pSysNetFuncArea, CWriteableSysNetFuncArea *pNewSysNetFuncArea, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetFuncArea，同时删除其索引
	///@param	pSysNetFuncArea	要删除的CSysNetFuncArea
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetFuncArea *pSysNetFuncArea, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetFuncArea
	///@param	pSysNetFuncArea	要读取的CSysNetFuncArea
	///@param	pTragetSysNetFuncArea	存放结果的CSysNetFuncArea
	void retrieve(CSysNetFuncArea *pSysNetFuncArea, CWriteableSysNetFuncArea *pTargetSysNetFuncArea);
	
	///获取第一个CSysNetFuncArea
	///@return	得到的第一个CSysNetFuncArea，如果没有，则返回NULL
	CSysNetFuncArea *getFirst(void);
	
	///获取下一个CSysNetFuncArea
	///@return	得到下一个CSysNetFuncArea，如果没有，则返回NULL
	CSysNetFuncArea *getNext(void);
	
	///结束获取CSysNetFuncArea
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetFuncAreaActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetFuncAreaActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetFuncAreaCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetFuncAreaCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetFuncAreaIteratorByAll;

	///开始寻找CSysNetFuncArea
	///@return	满足条件的地一个CSysNetFuncArea，如果找不到，返回NULL
	CSysNetFuncArea *startFindByAll();

	///寻找下一个符合条件的CSysNetFuncArea，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetFuncArea，如果已经没有一个满足要求了，则返回NULL
	CSysNetFuncArea *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetFuncArea
	///@param	ID	
	///@return	找到的CSysNetFuncArea，如果找不到，返回NULL
	CSysNetFuncArea *findByOne( const CReadOnlyVolumeType&  ID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetFuncArea加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetFuncArea	要加入的SysNetFuncArea
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetFuncArea *internalAdd(CWriteableSysNetFuncArea *pSysNetFuncArea, bool bNoTransaction);
	
	
	///刷新该CSysNetFuncArea的键值
	///@param	pSysNetFuncArea	被刷新的CSysNetFuncArea
	///@param	pNewSysNetFuncArea	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetFuncArea *pSysNetFuncArea, CWriteableSysNetFuncArea *pNewSysNetFuncArea, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetFuncArea，同时删除其索引
	///@param	pSysNetFuncArea	要删除的CSysNetFuncArea
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetFuncArea *pSysNetFuncArea, bool bNoTransaction);
/*
	///检查某个CSysNetFuncArea是否属于本对象工厂
	///@param	pSysNetFuncArea	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetFuncArea *pSysNetFuncArea);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetFuncArea	要加入的SysNetFuncArea
	virtual void beforeAdd(CWriteableSysNetFuncArea *pSysNetFuncArea);
	
	///加入后触发
	///@param	pSysNetFuncArea	已经加入的SysNetFuncArea
	virtual void afterAdd(CSysNetFuncArea *pSysNetFuncArea);

	///更新前触发	
	///@param	pSysNetFuncArea	被刷新的CSysNetFuncArea
	///@param	pNewSysNetFuncArea	新的值
	virtual void beforeUpdate(CSysNetFuncArea *pSysNetFuncArea, CWriteableSysNetFuncArea *pNewSysNetFuncArea);
	
	///更新后触发
	///@param	pSysNetFuncArea	被刷新的CSysNetFuncArea
	virtual void afterUpdate(CSysNetFuncArea *pSysNetFuncArea);
	
	///删除前触发
	///@param	pSysNetFuncArea	要删除的CSysNetFuncArea
	virtual void beforeRemove(CSysNetFuncArea *pSysNetFuncArea);
	
	///确认加入后触发
	///@param	pSysNetFuncArea	已经加入的SysNetFuncArea
	virtual void commitAdd(CSysNetFuncArea *pSysNetFuncArea);

	///确认更新后触发
	///@param	pSysNetFuncArea	被刷新的CSysNetFuncArea
	///@param	poldSysNetFuncArea	原来的值
	virtual void commitUpdate(CSysNetFuncArea *pSysNetFuncArea, CWriteableSysNetFuncArea *pOldSysNetFuncArea);
	
	///确认删除后触发
	///@param	pSysNetFuncArea	已经删除的CSysNetFuncArea
	virtual void commitRemove(CWriteableSysNetFuncArea *pSysNetFuncArea);

	///所有相关的触发器
	vector<CSysNetFuncAreaActionTrigger *> *pActionTriggers;
	vector<CSysNetFuncAreaCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetFuncArea compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceFactory是一个网络设备的对象工厂。它包含了一批网络设备，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///	SysIPDECODETypeIndex
///	SysSubAreaIDTypeIndex
///	SysObjectIDTypeIndex
///使用本对象工厂，可以完成对网络设备的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///		使用startFindByIPDECODE，findNextByIPDECODE和endFindByIPDECODE完成查询操作
///		使用startFindBySubAreaID，findNextBySubAreaID和endFindBySubAreaID完成查询操作
///		使用findByObjectID，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetDeviceFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetDevice，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetDeviceFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetDeviceFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetDevice
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetDevice，文件名将根据配置文件中的定义SysNetDeviceCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetDevice
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetDevice，文件名将根据配置文件中的定义SysNetDeviceCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetDeviceResource;

	///将一个CSysNetDevice加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetDevice	要加入的SysNetDevice
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetDevice *add(CWriteableSysNetDevice *pSysNetDevice, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetDevice的值
	///@param	pSysNetDevice	被刷新的CSysNetDevice
	///@param	pNewSysNetDevice	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetDevice *pSysNetDevice, CWriteableSysNetDevice *pNewSysNetDevice, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetDevice	  需要被刷新或者新增的CSysNetDevice,等于NULL表示是需要新增的
	///@param	pNewSysNetDevice	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetDevice* addOrUpdate(CSysNetDevice *pSysNetDevice, CWriteableSysNetDevice *pNewSysNetDevice, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetDevice，同时删除其索引
	///@param	pSysNetDevice	要删除的CSysNetDevice
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetDevice *pSysNetDevice, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetDevice
	///@param	pSysNetDevice	要读取的CSysNetDevice
	///@param	pTragetSysNetDevice	存放结果的CSysNetDevice
	void retrieve(CSysNetDevice *pSysNetDevice, CWriteableSysNetDevice *pTargetSysNetDevice);
	
	///获取第一个CSysNetDevice
	///@return	得到的第一个CSysNetDevice，如果没有，则返回NULL
	CSysNetDevice *getFirst(void);
	
	///获取下一个CSysNetDevice
	///@return	得到下一个CSysNetDevice，如果没有，则返回NULL
	CSysNetDevice *getNext(void);
	
	///结束获取CSysNetDevice
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetDeviceActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetDeviceActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetDeviceCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetDeviceCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetDeviceIteratorByAll;

	///开始寻找CSysNetDevice
	///@return	满足条件的地一个CSysNetDevice，如果找不到，返回NULL
	CSysNetDevice *startFindByAll();

	///寻找下一个符合条件的CSysNetDevice，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetDevice，如果已经没有一个满足要求了，则返回NULL
	CSysNetDevice *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetDevice
	///@param	ID	
	///@return	找到的CSysNetDevice，如果找不到，返回NULL
	CSysNetDevice *findByOne( const CReadOnlyVolumeType&  ID);



	friend class CSysNetDeviceIteratorByIPDECODE;

	///开始寻找CSysNetDevice
	///@param	IPDECODE	
	///@return	满足条件的地一个CSysNetDevice，如果找不到，返回NULL
	CSysNetDevice *startFindByIPDECODE( const CReadOnlyVolumeType& IPDECODE);

	///寻找下一个符合条件的CSysNetDevice，必须在startFindByIPDECODE以后，endFindByIPDECODE之前叫用
	///@return	下一个满足条件CSysNetDevice，如果已经没有一个满足要求了，则返回NULL
	CSysNetDevice *findNextByIPDECODE(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByIPDECODE(void);

	friend class CSysNetDeviceIteratorBySubAreaID;

	///开始寻找CSysNetDevice
	///@param	SysNetSubAreaID	
	///@return	满足条件的地一个CSysNetDevice，如果找不到，返回NULL
	CSysNetDevice *startFindBySubAreaID( const CReadOnlyVolumeType& SysNetSubAreaID);

	///寻找下一个符合条件的CSysNetDevice，必须在startFindBySubAreaID以后，endFindBySubAreaID之前叫用
	///@return	下一个满足条件CSysNetDevice，如果已经没有一个满足要求了，则返回NULL
	CSysNetDevice *findNextBySubAreaID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBySubAreaID(void);

	///寻找CSysNetDevice
	///@param	ObjectID	
	///@return	找到的CSysNetDevice，如果找不到，返回NULL
	CSysNetDevice *findByObjectID( const CReadOnlyNetObjectIDType&  ObjectID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetDevice加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetDevice	要加入的SysNetDevice
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetDevice *internalAdd(CWriteableSysNetDevice *pSysNetDevice, bool bNoTransaction);
	
	
	///刷新该CSysNetDevice的键值
	///@param	pSysNetDevice	被刷新的CSysNetDevice
	///@param	pNewSysNetDevice	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetDevice *pSysNetDevice, CWriteableSysNetDevice *pNewSysNetDevice, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetDevice，同时删除其索引
	///@param	pSysNetDevice	要删除的CSysNetDevice
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetDevice *pSysNetDevice, bool bNoTransaction);
/*
	///检查某个CSysNetDevice是否属于本对象工厂
	///@param	pSysNetDevice	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetDevice *pSysNetDevice);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	///基于IPDECODE的索引
	CAVLTree *pSysIPDECODETypeIndex;
	///基于SysNetSubAreaID的索引
	CAVLTree *pSysSubAreaIDTypeIndex;
	///基于ObjectID的索引
	CAVLTree *pSysObjectIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	///按照IPDECODE检索时，存储的查询参数
	CVolumeType queryIPDECODEInSearchByIPDECODE;
	
	///按照IPDECODE检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByIPDECODE;
	///按照SysNetSubAreaID检索时，存储的查询参数
	CVolumeType querySysNetSubAreaIDInSearchBySubAreaID;
	
	///按照SysNetSubAreaID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBySubAreaID;
	
	///加入前触发
	///@param	pSysNetDevice	要加入的SysNetDevice
	virtual void beforeAdd(CWriteableSysNetDevice *pSysNetDevice);
	
	///加入后触发
	///@param	pSysNetDevice	已经加入的SysNetDevice
	virtual void afterAdd(CSysNetDevice *pSysNetDevice);

	///更新前触发	
	///@param	pSysNetDevice	被刷新的CSysNetDevice
	///@param	pNewSysNetDevice	新的值
	virtual void beforeUpdate(CSysNetDevice *pSysNetDevice, CWriteableSysNetDevice *pNewSysNetDevice);
	
	///更新后触发
	///@param	pSysNetDevice	被刷新的CSysNetDevice
	virtual void afterUpdate(CSysNetDevice *pSysNetDevice);
	
	///删除前触发
	///@param	pSysNetDevice	要删除的CSysNetDevice
	virtual void beforeRemove(CSysNetDevice *pSysNetDevice);
	
	///确认加入后触发
	///@param	pSysNetDevice	已经加入的SysNetDevice
	virtual void commitAdd(CSysNetDevice *pSysNetDevice);

	///确认更新后触发
	///@param	pSysNetDevice	被刷新的CSysNetDevice
	///@param	poldSysNetDevice	原来的值
	virtual void commitUpdate(CSysNetDevice *pSysNetDevice, CWriteableSysNetDevice *pOldSysNetDevice);
	
	///确认删除后触发
	///@param	pSysNetDevice	已经删除的CSysNetDevice
	virtual void commitRemove(CWriteableSysNetDevice *pSysNetDevice);

	///所有相关的触发器
	vector<CSysNetDeviceActionTrigger *> *pActionTriggers;
	vector<CSysNetDeviceCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetDevice compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedFactory是一个网络设备连接关系的对象工厂。它包含了一批网络设备连接关系，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///	SysNetObjectIDTypeIndex
///	SysLinkObjectIDTypeIndex
///使用本对象工厂，可以完成对网络设备连接关系的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///		使用startFindByNetObjectID，findNextByNetObjectID和endFindByNetObjectID完成查询操作
///		使用startFindByLinkNetObjectID，findNextByLinkNetObjectID和endFindByLinkNetObjectID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetDeviceLinkedFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetDeviceLinked，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetDeviceLinkedFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetDeviceLinkedFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetDeviceLinked
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetDeviceLinked，文件名将根据配置文件中的定义SysNetDeviceLinkedCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetDeviceLinked
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetDeviceLinked，文件名将根据配置文件中的定义SysNetDeviceLinkedCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetDeviceLinkedResource;

	///将一个CSysNetDeviceLinked加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetDeviceLinked	要加入的SysNetDeviceLinked
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetDeviceLinked *add(CWriteableSysNetDeviceLinked *pSysNetDeviceLinked, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetDeviceLinked的值
	///@param	pSysNetDeviceLinked	被刷新的CSysNetDeviceLinked
	///@param	pNewSysNetDeviceLinked	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetDeviceLinked *pSysNetDeviceLinked, CWriteableSysNetDeviceLinked *pNewSysNetDeviceLinked, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetDeviceLinked	  需要被刷新或者新增的CSysNetDeviceLinked,等于NULL表示是需要新增的
	///@param	pNewSysNetDeviceLinked	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetDeviceLinked* addOrUpdate(CSysNetDeviceLinked *pSysNetDeviceLinked, CWriteableSysNetDeviceLinked *pNewSysNetDeviceLinked, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetDeviceLinked，同时删除其索引
	///@param	pSysNetDeviceLinked	要删除的CSysNetDeviceLinked
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetDeviceLinked *pSysNetDeviceLinked, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetDeviceLinked
	///@param	pSysNetDeviceLinked	要读取的CSysNetDeviceLinked
	///@param	pTragetSysNetDeviceLinked	存放结果的CSysNetDeviceLinked
	void retrieve(CSysNetDeviceLinked *pSysNetDeviceLinked, CWriteableSysNetDeviceLinked *pTargetSysNetDeviceLinked);
	
	///获取第一个CSysNetDeviceLinked
	///@return	得到的第一个CSysNetDeviceLinked，如果没有，则返回NULL
	CSysNetDeviceLinked *getFirst(void);
	
	///获取下一个CSysNetDeviceLinked
	///@return	得到下一个CSysNetDeviceLinked，如果没有，则返回NULL
	CSysNetDeviceLinked *getNext(void);
	
	///结束获取CSysNetDeviceLinked
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetDeviceLinkedActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetDeviceLinkedActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetDeviceLinkedCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetDeviceLinkedCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetDeviceLinkedIteratorByAll;

	///开始寻找CSysNetDeviceLinked
	///@return	满足条件的地一个CSysNetDeviceLinked，如果找不到，返回NULL
	CSysNetDeviceLinked *startFindByAll();

	///寻找下一个符合条件的CSysNetDeviceLinked，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetDeviceLinked，如果已经没有一个满足要求了，则返回NULL
	CSysNetDeviceLinked *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetDeviceLinked
	///@param	ID	
	///@return	找到的CSysNetDeviceLinked，如果找不到，返回NULL
	CSysNetDeviceLinked *findByOne( const CReadOnlyVolumeType&  ID);



	friend class CSysNetDeviceLinkedIteratorByNetObjectID;

	///开始寻找CSysNetDeviceLinked
	///@param	NetObjectID	
	///@return	满足条件的地一个CSysNetDeviceLinked，如果找不到，返回NULL
	CSysNetDeviceLinked *startFindByNetObjectID( const CReadOnlyNetObjectIDType& NetObjectID);

	///寻找下一个符合条件的CSysNetDeviceLinked，必须在startFindByNetObjectID以后，endFindByNetObjectID之前叫用
	///@return	下一个满足条件CSysNetDeviceLinked，如果已经没有一个满足要求了，则返回NULL
	CSysNetDeviceLinked *findNextByNetObjectID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByNetObjectID(void);

	friend class CSysNetDeviceLinkedIteratorByLinkNetObjectID;

	///开始寻找CSysNetDeviceLinked
	///@param	LinkNetObjectID	
	///@return	满足条件的地一个CSysNetDeviceLinked，如果找不到，返回NULL
	CSysNetDeviceLinked *startFindByLinkNetObjectID( const CReadOnlyNetObjectIDType& LinkNetObjectID);

	///寻找下一个符合条件的CSysNetDeviceLinked，必须在startFindByLinkNetObjectID以后，endFindByLinkNetObjectID之前叫用
	///@return	下一个满足条件CSysNetDeviceLinked，如果已经没有一个满足要求了，则返回NULL
	CSysNetDeviceLinked *findNextByLinkNetObjectID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByLinkNetObjectID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetDeviceLinked加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetDeviceLinked	要加入的SysNetDeviceLinked
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetDeviceLinked *internalAdd(CWriteableSysNetDeviceLinked *pSysNetDeviceLinked, bool bNoTransaction);
	
	
	///刷新该CSysNetDeviceLinked的键值
	///@param	pSysNetDeviceLinked	被刷新的CSysNetDeviceLinked
	///@param	pNewSysNetDeviceLinked	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetDeviceLinked *pSysNetDeviceLinked, CWriteableSysNetDeviceLinked *pNewSysNetDeviceLinked, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetDeviceLinked，同时删除其索引
	///@param	pSysNetDeviceLinked	要删除的CSysNetDeviceLinked
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetDeviceLinked *pSysNetDeviceLinked, bool bNoTransaction);
/*
	///检查某个CSysNetDeviceLinked是否属于本对象工厂
	///@param	pSysNetDeviceLinked	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetDeviceLinked *pSysNetDeviceLinked);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	///基于NetObjectID的索引
	CAVLTree *pSysNetObjectIDTypeIndex;
	///基于LinkNetObjectID的索引
	CAVLTree *pSysLinkObjectIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	///按照NetObjectID检索时，存储的查询参数
	CNetObjectIDType queryNetObjectIDInSearchByNetObjectID;
	
	///按照NetObjectID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByNetObjectID;
	///按照LinkNetObjectID检索时，存储的查询参数
	CNetObjectIDType queryLinkNetObjectIDInSearchByLinkNetObjectID;
	
	///按照LinkNetObjectID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByLinkNetObjectID;
	
	///加入前触发
	///@param	pSysNetDeviceLinked	要加入的SysNetDeviceLinked
	virtual void beforeAdd(CWriteableSysNetDeviceLinked *pSysNetDeviceLinked);
	
	///加入后触发
	///@param	pSysNetDeviceLinked	已经加入的SysNetDeviceLinked
	virtual void afterAdd(CSysNetDeviceLinked *pSysNetDeviceLinked);

	///更新前触发	
	///@param	pSysNetDeviceLinked	被刷新的CSysNetDeviceLinked
	///@param	pNewSysNetDeviceLinked	新的值
	virtual void beforeUpdate(CSysNetDeviceLinked *pSysNetDeviceLinked, CWriteableSysNetDeviceLinked *pNewSysNetDeviceLinked);
	
	///更新后触发
	///@param	pSysNetDeviceLinked	被刷新的CSysNetDeviceLinked
	virtual void afterUpdate(CSysNetDeviceLinked *pSysNetDeviceLinked);
	
	///删除前触发
	///@param	pSysNetDeviceLinked	要删除的CSysNetDeviceLinked
	virtual void beforeRemove(CSysNetDeviceLinked *pSysNetDeviceLinked);
	
	///确认加入后触发
	///@param	pSysNetDeviceLinked	已经加入的SysNetDeviceLinked
	virtual void commitAdd(CSysNetDeviceLinked *pSysNetDeviceLinked);

	///确认更新后触发
	///@param	pSysNetDeviceLinked	被刷新的CSysNetDeviceLinked
	///@param	poldSysNetDeviceLinked	原来的值
	virtual void commitUpdate(CSysNetDeviceLinked *pSysNetDeviceLinked, CWriteableSysNetDeviceLinked *pOldSysNetDeviceLinked);
	
	///确认删除后触发
	///@param	pSysNetDeviceLinked	已经删除的CSysNetDeviceLinked
	virtual void commitRemove(CWriteableSysNetDeviceLinked *pSysNetDeviceLinked);

	///所有相关的触发器
	vector<CSysNetDeviceLinkedActionTrigger *> *pActionTriggers;
	vector<CSysNetDeviceLinkedCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetDeviceLinked compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOIDFactory是一个OID的对象工厂。它包含了一批OID，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对OID的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOIDFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetOIDFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetOID，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetOIDFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetOIDFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetOID
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetOID，文件名将根据配置文件中的定义SysNetOIDCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetOID
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetOID，文件名将根据配置文件中的定义SysNetOIDCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetOIDResource;

	///将一个CSysNetOID加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetOID	要加入的SysNetOID
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetOID *add(CWriteableSysNetOID *pSysNetOID, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetOID的值
	///@param	pSysNetOID	被刷新的CSysNetOID
	///@param	pNewSysNetOID	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetOID *pSysNetOID, CWriteableSysNetOID *pNewSysNetOID, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetOID	  需要被刷新或者新增的CSysNetOID,等于NULL表示是需要新增的
	///@param	pNewSysNetOID	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetOID* addOrUpdate(CSysNetOID *pSysNetOID, CWriteableSysNetOID *pNewSysNetOID, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetOID，同时删除其索引
	///@param	pSysNetOID	要删除的CSysNetOID
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetOID *pSysNetOID, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetOID
	///@param	pSysNetOID	要读取的CSysNetOID
	///@param	pTragetSysNetOID	存放结果的CSysNetOID
	void retrieve(CSysNetOID *pSysNetOID, CWriteableSysNetOID *pTargetSysNetOID);
	
	///获取第一个CSysNetOID
	///@return	得到的第一个CSysNetOID，如果没有，则返回NULL
	CSysNetOID *getFirst(void);
	
	///获取下一个CSysNetOID
	///@return	得到下一个CSysNetOID，如果没有，则返回NULL
	CSysNetOID *getNext(void);
	
	///结束获取CSysNetOID
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetOIDActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetOIDActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetOIDCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetOIDCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetOIDIteratorByAll;

	///开始寻找CSysNetOID
	///@return	满足条件的地一个CSysNetOID，如果找不到，返回NULL
	CSysNetOID *startFindByAll();

	///寻找下一个符合条件的CSysNetOID，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetOID，如果已经没有一个满足要求了，则返回NULL
	CSysNetOID *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetOID
	///@param	ID	
	///@return	找到的CSysNetOID，如果找不到，返回NULL
	CSysNetOID *findByOne( const CReadOnlyVolumeType&  ID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetOID加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetOID	要加入的SysNetOID
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetOID *internalAdd(CWriteableSysNetOID *pSysNetOID, bool bNoTransaction);
	
	
	///刷新该CSysNetOID的键值
	///@param	pSysNetOID	被刷新的CSysNetOID
	///@param	pNewSysNetOID	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetOID *pSysNetOID, CWriteableSysNetOID *pNewSysNetOID, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetOID，同时删除其索引
	///@param	pSysNetOID	要删除的CSysNetOID
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetOID *pSysNetOID, bool bNoTransaction);
/*
	///检查某个CSysNetOID是否属于本对象工厂
	///@param	pSysNetOID	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetOID *pSysNetOID);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetOID	要加入的SysNetOID
	virtual void beforeAdd(CWriteableSysNetOID *pSysNetOID);
	
	///加入后触发
	///@param	pSysNetOID	已经加入的SysNetOID
	virtual void afterAdd(CSysNetOID *pSysNetOID);

	///更新前触发	
	///@param	pSysNetOID	被刷新的CSysNetOID
	///@param	pNewSysNetOID	新的值
	virtual void beforeUpdate(CSysNetOID *pSysNetOID, CWriteableSysNetOID *pNewSysNetOID);
	
	///更新后触发
	///@param	pSysNetOID	被刷新的CSysNetOID
	virtual void afterUpdate(CSysNetOID *pSysNetOID);
	
	///删除前触发
	///@param	pSysNetOID	要删除的CSysNetOID
	virtual void beforeRemove(CSysNetOID *pSysNetOID);
	
	///确认加入后触发
	///@param	pSysNetOID	已经加入的SysNetOID
	virtual void commitAdd(CSysNetOID *pSysNetOID);

	///确认更新后触发
	///@param	pSysNetOID	被刷新的CSysNetOID
	///@param	poldSysNetOID	原来的值
	virtual void commitUpdate(CSysNetOID *pSysNetOID, CWriteableSysNetOID *pOldSysNetOID);
	
	///确认删除后触发
	///@param	pSysNetOID	已经删除的CSysNetOID
	virtual void commitRemove(CWriteableSysNetOID *pSysNetOID);

	///所有相关的触发器
	vector<CSysNetOIDActionTrigger *> *pActionTriggers;
	vector<CSysNetOIDCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetOID compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceTypeFactory是一个网络设备类型的对象工厂。它包含了一批网络设备类型，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对网络设备类型的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceTypeFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetDeviceTypeFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetDeviceType，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetDeviceTypeFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetDeviceTypeFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetDeviceType
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetDeviceType，文件名将根据配置文件中的定义SysNetDeviceTypeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetDeviceType
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetDeviceType，文件名将根据配置文件中的定义SysNetDeviceTypeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetDeviceTypeResource;

	///将一个CSysNetDeviceType加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetDeviceType	要加入的SysNetDeviceType
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetDeviceType *add(CWriteableSysNetDeviceType *pSysNetDeviceType, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetDeviceType的值
	///@param	pSysNetDeviceType	被刷新的CSysNetDeviceType
	///@param	pNewSysNetDeviceType	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetDeviceType *pSysNetDeviceType, CWriteableSysNetDeviceType *pNewSysNetDeviceType, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetDeviceType	  需要被刷新或者新增的CSysNetDeviceType,等于NULL表示是需要新增的
	///@param	pNewSysNetDeviceType	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetDeviceType* addOrUpdate(CSysNetDeviceType *pSysNetDeviceType, CWriteableSysNetDeviceType *pNewSysNetDeviceType, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetDeviceType，同时删除其索引
	///@param	pSysNetDeviceType	要删除的CSysNetDeviceType
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetDeviceType *pSysNetDeviceType, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetDeviceType
	///@param	pSysNetDeviceType	要读取的CSysNetDeviceType
	///@param	pTragetSysNetDeviceType	存放结果的CSysNetDeviceType
	void retrieve(CSysNetDeviceType *pSysNetDeviceType, CWriteableSysNetDeviceType *pTargetSysNetDeviceType);
	
	///获取第一个CSysNetDeviceType
	///@return	得到的第一个CSysNetDeviceType，如果没有，则返回NULL
	CSysNetDeviceType *getFirst(void);
	
	///获取下一个CSysNetDeviceType
	///@return	得到下一个CSysNetDeviceType，如果没有，则返回NULL
	CSysNetDeviceType *getNext(void);
	
	///结束获取CSysNetDeviceType
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetDeviceTypeActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetDeviceTypeActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetDeviceTypeCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetDeviceTypeCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetDeviceTypeIteratorByAll;

	///开始寻找CSysNetDeviceType
	///@return	满足条件的地一个CSysNetDeviceType，如果找不到，返回NULL
	CSysNetDeviceType *startFindByAll();

	///寻找下一个符合条件的CSysNetDeviceType，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetDeviceType，如果已经没有一个满足要求了，则返回NULL
	CSysNetDeviceType *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetDeviceType
	///@param	ID	
	///@return	找到的CSysNetDeviceType，如果找不到，返回NULL
	CSysNetDeviceType *findByOne( const CReadOnlyVolumeType&  ID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetDeviceType加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetDeviceType	要加入的SysNetDeviceType
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetDeviceType *internalAdd(CWriteableSysNetDeviceType *pSysNetDeviceType, bool bNoTransaction);
	
	
	///刷新该CSysNetDeviceType的键值
	///@param	pSysNetDeviceType	被刷新的CSysNetDeviceType
	///@param	pNewSysNetDeviceType	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetDeviceType *pSysNetDeviceType, CWriteableSysNetDeviceType *pNewSysNetDeviceType, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetDeviceType，同时删除其索引
	///@param	pSysNetDeviceType	要删除的CSysNetDeviceType
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetDeviceType *pSysNetDeviceType, bool bNoTransaction);
/*
	///检查某个CSysNetDeviceType是否属于本对象工厂
	///@param	pSysNetDeviceType	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetDeviceType *pSysNetDeviceType);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetDeviceType	要加入的SysNetDeviceType
	virtual void beforeAdd(CWriteableSysNetDeviceType *pSysNetDeviceType);
	
	///加入后触发
	///@param	pSysNetDeviceType	已经加入的SysNetDeviceType
	virtual void afterAdd(CSysNetDeviceType *pSysNetDeviceType);

	///更新前触发	
	///@param	pSysNetDeviceType	被刷新的CSysNetDeviceType
	///@param	pNewSysNetDeviceType	新的值
	virtual void beforeUpdate(CSysNetDeviceType *pSysNetDeviceType, CWriteableSysNetDeviceType *pNewSysNetDeviceType);
	
	///更新后触发
	///@param	pSysNetDeviceType	被刷新的CSysNetDeviceType
	virtual void afterUpdate(CSysNetDeviceType *pSysNetDeviceType);
	
	///删除前触发
	///@param	pSysNetDeviceType	要删除的CSysNetDeviceType
	virtual void beforeRemove(CSysNetDeviceType *pSysNetDeviceType);
	
	///确认加入后触发
	///@param	pSysNetDeviceType	已经加入的SysNetDeviceType
	virtual void commitAdd(CSysNetDeviceType *pSysNetDeviceType);

	///确认更新后触发
	///@param	pSysNetDeviceType	被刷新的CSysNetDeviceType
	///@param	poldSysNetDeviceType	原来的值
	virtual void commitUpdate(CSysNetDeviceType *pSysNetDeviceType, CWriteableSysNetDeviceType *pOldSysNetDeviceType);
	
	///确认删除后触发
	///@param	pSysNetDeviceType	已经删除的CSysNetDeviceType
	virtual void commitRemove(CWriteableSysNetDeviceType *pSysNetDeviceType);

	///所有相关的触发器
	vector<CSysNetDeviceTypeActionTrigger *> *pActionTriggers;
	vector<CSysNetDeviceTypeCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetDeviceType compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetTimePolicyFactory是一个时间策略的对象工厂。它包含了一批时间策略，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对时间策略的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetTimePolicyFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetTimePolicyFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetTimePolicy，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetTimePolicyFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetTimePolicyFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetTimePolicy
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetTimePolicy，文件名将根据配置文件中的定义SysNetTimePolicyCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetTimePolicy
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetTimePolicy，文件名将根据配置文件中的定义SysNetTimePolicyCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetTimePolicyResource;

	///将一个CSysNetTimePolicy加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetTimePolicy	要加入的SysNetTimePolicy
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetTimePolicy *add(CWriteableSysNetTimePolicy *pSysNetTimePolicy, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetTimePolicy的值
	///@param	pSysNetTimePolicy	被刷新的CSysNetTimePolicy
	///@param	pNewSysNetTimePolicy	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetTimePolicy *pSysNetTimePolicy, CWriteableSysNetTimePolicy *pNewSysNetTimePolicy, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetTimePolicy	  需要被刷新或者新增的CSysNetTimePolicy,等于NULL表示是需要新增的
	///@param	pNewSysNetTimePolicy	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetTimePolicy* addOrUpdate(CSysNetTimePolicy *pSysNetTimePolicy, CWriteableSysNetTimePolicy *pNewSysNetTimePolicy, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetTimePolicy，同时删除其索引
	///@param	pSysNetTimePolicy	要删除的CSysNetTimePolicy
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetTimePolicy *pSysNetTimePolicy, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetTimePolicy
	///@param	pSysNetTimePolicy	要读取的CSysNetTimePolicy
	///@param	pTragetSysNetTimePolicy	存放结果的CSysNetTimePolicy
	void retrieve(CSysNetTimePolicy *pSysNetTimePolicy, CWriteableSysNetTimePolicy *pTargetSysNetTimePolicy);
	
	///获取第一个CSysNetTimePolicy
	///@return	得到的第一个CSysNetTimePolicy，如果没有，则返回NULL
	CSysNetTimePolicy *getFirst(void);
	
	///获取下一个CSysNetTimePolicy
	///@return	得到下一个CSysNetTimePolicy，如果没有，则返回NULL
	CSysNetTimePolicy *getNext(void);
	
	///结束获取CSysNetTimePolicy
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetTimePolicyActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetTimePolicyActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetTimePolicyCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetTimePolicyCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetTimePolicyIteratorByAll;

	///开始寻找CSysNetTimePolicy
	///@return	满足条件的地一个CSysNetTimePolicy，如果找不到，返回NULL
	CSysNetTimePolicy *startFindByAll();

	///寻找下一个符合条件的CSysNetTimePolicy，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetTimePolicy，如果已经没有一个满足要求了，则返回NULL
	CSysNetTimePolicy *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetTimePolicy
	///@param	ID	
	///@return	找到的CSysNetTimePolicy，如果找不到，返回NULL
	CSysNetTimePolicy *findByOne( const CReadOnlyVolumeType&  ID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetTimePolicy加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetTimePolicy	要加入的SysNetTimePolicy
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetTimePolicy *internalAdd(CWriteableSysNetTimePolicy *pSysNetTimePolicy, bool bNoTransaction);
	
	
	///刷新该CSysNetTimePolicy的键值
	///@param	pSysNetTimePolicy	被刷新的CSysNetTimePolicy
	///@param	pNewSysNetTimePolicy	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetTimePolicy *pSysNetTimePolicy, CWriteableSysNetTimePolicy *pNewSysNetTimePolicy, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetTimePolicy，同时删除其索引
	///@param	pSysNetTimePolicy	要删除的CSysNetTimePolicy
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetTimePolicy *pSysNetTimePolicy, bool bNoTransaction);
/*
	///检查某个CSysNetTimePolicy是否属于本对象工厂
	///@param	pSysNetTimePolicy	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetTimePolicy *pSysNetTimePolicy);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetTimePolicy	要加入的SysNetTimePolicy
	virtual void beforeAdd(CWriteableSysNetTimePolicy *pSysNetTimePolicy);
	
	///加入后触发
	///@param	pSysNetTimePolicy	已经加入的SysNetTimePolicy
	virtual void afterAdd(CSysNetTimePolicy *pSysNetTimePolicy);

	///更新前触发	
	///@param	pSysNetTimePolicy	被刷新的CSysNetTimePolicy
	///@param	pNewSysNetTimePolicy	新的值
	virtual void beforeUpdate(CSysNetTimePolicy *pSysNetTimePolicy, CWriteableSysNetTimePolicy *pNewSysNetTimePolicy);
	
	///更新后触发
	///@param	pSysNetTimePolicy	被刷新的CSysNetTimePolicy
	virtual void afterUpdate(CSysNetTimePolicy *pSysNetTimePolicy);
	
	///删除前触发
	///@param	pSysNetTimePolicy	要删除的CSysNetTimePolicy
	virtual void beforeRemove(CSysNetTimePolicy *pSysNetTimePolicy);
	
	///确认加入后触发
	///@param	pSysNetTimePolicy	已经加入的SysNetTimePolicy
	virtual void commitAdd(CSysNetTimePolicy *pSysNetTimePolicy);

	///确认更新后触发
	///@param	pSysNetTimePolicy	被刷新的CSysNetTimePolicy
	///@param	poldSysNetTimePolicy	原来的值
	virtual void commitUpdate(CSysNetTimePolicy *pSysNetTimePolicy, CWriteableSysNetTimePolicy *pOldSysNetTimePolicy);
	
	///确认删除后触发
	///@param	pSysNetTimePolicy	已经删除的CSysNetTimePolicy
	virtual void commitRemove(CWriteableSysNetTimePolicy *pSysNetTimePolicy);

	///所有相关的触发器
	vector<CSysNetTimePolicyActionTrigger *> *pActionTriggers;
	vector<CSysNetTimePolicyCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetTimePolicy compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGatherTaskFactory是一个采集任务的对象工厂。它包含了一批采集任务，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///	SysNetObjectIDTypeIndex
///使用本对象工厂，可以完成对采集任务的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///		使用startFindByNetObjectID，findNextByNetObjectID和endFindByNetObjectID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGatherTaskFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetGatherTaskFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetGatherTask，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetGatherTaskFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetGatherTaskFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetGatherTask
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetGatherTask，文件名将根据配置文件中的定义SysNetGatherTaskCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetGatherTask
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetGatherTask，文件名将根据配置文件中的定义SysNetGatherTaskCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetGatherTaskResource;

	///将一个CSysNetGatherTask加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetGatherTask	要加入的SysNetGatherTask
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetGatherTask *add(CWriteableSysNetGatherTask *pSysNetGatherTask, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetGatherTask的值
	///@param	pSysNetGatherTask	被刷新的CSysNetGatherTask
	///@param	pNewSysNetGatherTask	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetGatherTask *pSysNetGatherTask, CWriteableSysNetGatherTask *pNewSysNetGatherTask, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetGatherTask	  需要被刷新或者新增的CSysNetGatherTask,等于NULL表示是需要新增的
	///@param	pNewSysNetGatherTask	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetGatherTask* addOrUpdate(CSysNetGatherTask *pSysNetGatherTask, CWriteableSysNetGatherTask *pNewSysNetGatherTask, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetGatherTask，同时删除其索引
	///@param	pSysNetGatherTask	要删除的CSysNetGatherTask
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetGatherTask *pSysNetGatherTask, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetGatherTask
	///@param	pSysNetGatherTask	要读取的CSysNetGatherTask
	///@param	pTragetSysNetGatherTask	存放结果的CSysNetGatherTask
	void retrieve(CSysNetGatherTask *pSysNetGatherTask, CWriteableSysNetGatherTask *pTargetSysNetGatherTask);
	
	///获取第一个CSysNetGatherTask
	///@return	得到的第一个CSysNetGatherTask，如果没有，则返回NULL
	CSysNetGatherTask *getFirst(void);
	
	///获取下一个CSysNetGatherTask
	///@return	得到下一个CSysNetGatherTask，如果没有，则返回NULL
	CSysNetGatherTask *getNext(void);
	
	///结束获取CSysNetGatherTask
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetGatherTaskActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetGatherTaskActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetGatherTaskCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetGatherTaskCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetGatherTaskIteratorByAll;

	///开始寻找CSysNetGatherTask
	///@return	满足条件的地一个CSysNetGatherTask，如果找不到，返回NULL
	CSysNetGatherTask *startFindByAll();

	///寻找下一个符合条件的CSysNetGatherTask，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetGatherTask，如果已经没有一个满足要求了，则返回NULL
	CSysNetGatherTask *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetGatherTask
	///@param	ID	
	///@return	找到的CSysNetGatherTask，如果找不到，返回NULL
	CSysNetGatherTask *findByOne( const CReadOnlyVolumeType&  ID);



	friend class CSysNetGatherTaskIteratorByNetObjectID;

	///开始寻找CSysNetGatherTask
	///@param	ObjectID	
	///@return	满足条件的地一个CSysNetGatherTask，如果找不到，返回NULL
	CSysNetGatherTask *startFindByNetObjectID( const CReadOnlyNetObjectIDType& ObjectID);

	///寻找下一个符合条件的CSysNetGatherTask，必须在startFindByNetObjectID以后，endFindByNetObjectID之前叫用
	///@return	下一个满足条件CSysNetGatherTask，如果已经没有一个满足要求了，则返回NULL
	CSysNetGatherTask *findNextByNetObjectID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByNetObjectID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetGatherTask加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetGatherTask	要加入的SysNetGatherTask
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetGatherTask *internalAdd(CWriteableSysNetGatherTask *pSysNetGatherTask, bool bNoTransaction);
	
	
	///刷新该CSysNetGatherTask的键值
	///@param	pSysNetGatherTask	被刷新的CSysNetGatherTask
	///@param	pNewSysNetGatherTask	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetGatherTask *pSysNetGatherTask, CWriteableSysNetGatherTask *pNewSysNetGatherTask, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetGatherTask，同时删除其索引
	///@param	pSysNetGatherTask	要删除的CSysNetGatherTask
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetGatherTask *pSysNetGatherTask, bool bNoTransaction);
/*
	///检查某个CSysNetGatherTask是否属于本对象工厂
	///@param	pSysNetGatherTask	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetGatherTask *pSysNetGatherTask);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	///基于ObjectID的索引
	CAVLTree *pSysNetObjectIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	///按照ObjectID检索时，存储的查询参数
	CNetObjectIDType queryObjectIDInSearchByNetObjectID;
	
	///按照ObjectID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByNetObjectID;
	
	///加入前触发
	///@param	pSysNetGatherTask	要加入的SysNetGatherTask
	virtual void beforeAdd(CWriteableSysNetGatherTask *pSysNetGatherTask);
	
	///加入后触发
	///@param	pSysNetGatherTask	已经加入的SysNetGatherTask
	virtual void afterAdd(CSysNetGatherTask *pSysNetGatherTask);

	///更新前触发	
	///@param	pSysNetGatherTask	被刷新的CSysNetGatherTask
	///@param	pNewSysNetGatherTask	新的值
	virtual void beforeUpdate(CSysNetGatherTask *pSysNetGatherTask, CWriteableSysNetGatherTask *pNewSysNetGatherTask);
	
	///更新后触发
	///@param	pSysNetGatherTask	被刷新的CSysNetGatherTask
	virtual void afterUpdate(CSysNetGatherTask *pSysNetGatherTask);
	
	///删除前触发
	///@param	pSysNetGatherTask	要删除的CSysNetGatherTask
	virtual void beforeRemove(CSysNetGatherTask *pSysNetGatherTask);
	
	///确认加入后触发
	///@param	pSysNetGatherTask	已经加入的SysNetGatherTask
	virtual void commitAdd(CSysNetGatherTask *pSysNetGatherTask);

	///确认更新后触发
	///@param	pSysNetGatherTask	被刷新的CSysNetGatherTask
	///@param	poldSysNetGatherTask	原来的值
	virtual void commitUpdate(CSysNetGatherTask *pSysNetGatherTask, CWriteableSysNetGatherTask *pOldSysNetGatherTask);
	
	///确认删除后触发
	///@param	pSysNetGatherTask	已经删除的CSysNetGatherTask
	virtual void commitRemove(CWriteableSysNetGatherTask *pSysNetGatherTask);

	///所有相关的触发器
	vector<CSysNetGatherTaskActionTrigger *> *pActionTriggers;
	vector<CSysNetGatherTaskCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetGatherTask compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceCategoryFactory是一个常用设备类别的对象工厂。它包含了一批常用设备类别，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对常用设备类别的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceCategoryFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetDeviceCategoryFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetDeviceCategory，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetDeviceCategoryFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetDeviceCategoryFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetDeviceCategory
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetDeviceCategory，文件名将根据配置文件中的定义SysNetDeviceCategoryCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetDeviceCategory
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetDeviceCategory，文件名将根据配置文件中的定义SysNetDeviceCategoryCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetDeviceCategoryResource;

	///将一个CSysNetDeviceCategory加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetDeviceCategory	要加入的SysNetDeviceCategory
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetDeviceCategory *add(CWriteableSysNetDeviceCategory *pSysNetDeviceCategory, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetDeviceCategory的值
	///@param	pSysNetDeviceCategory	被刷新的CSysNetDeviceCategory
	///@param	pNewSysNetDeviceCategory	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetDeviceCategory *pSysNetDeviceCategory, CWriteableSysNetDeviceCategory *pNewSysNetDeviceCategory, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetDeviceCategory	  需要被刷新或者新增的CSysNetDeviceCategory,等于NULL表示是需要新增的
	///@param	pNewSysNetDeviceCategory	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetDeviceCategory* addOrUpdate(CSysNetDeviceCategory *pSysNetDeviceCategory, CWriteableSysNetDeviceCategory *pNewSysNetDeviceCategory, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetDeviceCategory，同时删除其索引
	///@param	pSysNetDeviceCategory	要删除的CSysNetDeviceCategory
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetDeviceCategory *pSysNetDeviceCategory, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetDeviceCategory
	///@param	pSysNetDeviceCategory	要读取的CSysNetDeviceCategory
	///@param	pTragetSysNetDeviceCategory	存放结果的CSysNetDeviceCategory
	void retrieve(CSysNetDeviceCategory *pSysNetDeviceCategory, CWriteableSysNetDeviceCategory *pTargetSysNetDeviceCategory);
	
	///获取第一个CSysNetDeviceCategory
	///@return	得到的第一个CSysNetDeviceCategory，如果没有，则返回NULL
	CSysNetDeviceCategory *getFirst(void);
	
	///获取下一个CSysNetDeviceCategory
	///@return	得到下一个CSysNetDeviceCategory，如果没有，则返回NULL
	CSysNetDeviceCategory *getNext(void);
	
	///结束获取CSysNetDeviceCategory
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetDeviceCategoryActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetDeviceCategoryActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetDeviceCategoryCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetDeviceCategoryCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetDeviceCategoryIteratorByAll;

	///开始寻找CSysNetDeviceCategory
	///@return	满足条件的地一个CSysNetDeviceCategory，如果找不到，返回NULL
	CSysNetDeviceCategory *startFindByAll();

	///寻找下一个符合条件的CSysNetDeviceCategory，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetDeviceCategory，如果已经没有一个满足要求了，则返回NULL
	CSysNetDeviceCategory *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetDeviceCategory
	///@param	ID	
	///@return	找到的CSysNetDeviceCategory，如果找不到，返回NULL
	CSysNetDeviceCategory *findByOne( const CReadOnlyVolumeType&  ID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetDeviceCategory加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetDeviceCategory	要加入的SysNetDeviceCategory
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetDeviceCategory *internalAdd(CWriteableSysNetDeviceCategory *pSysNetDeviceCategory, bool bNoTransaction);
	
	
	///刷新该CSysNetDeviceCategory的键值
	///@param	pSysNetDeviceCategory	被刷新的CSysNetDeviceCategory
	///@param	pNewSysNetDeviceCategory	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetDeviceCategory *pSysNetDeviceCategory, CWriteableSysNetDeviceCategory *pNewSysNetDeviceCategory, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetDeviceCategory，同时删除其索引
	///@param	pSysNetDeviceCategory	要删除的CSysNetDeviceCategory
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetDeviceCategory *pSysNetDeviceCategory, bool bNoTransaction);
/*
	///检查某个CSysNetDeviceCategory是否属于本对象工厂
	///@param	pSysNetDeviceCategory	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetDeviceCategory *pSysNetDeviceCategory);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetDeviceCategory	要加入的SysNetDeviceCategory
	virtual void beforeAdd(CWriteableSysNetDeviceCategory *pSysNetDeviceCategory);
	
	///加入后触发
	///@param	pSysNetDeviceCategory	已经加入的SysNetDeviceCategory
	virtual void afterAdd(CSysNetDeviceCategory *pSysNetDeviceCategory);

	///更新前触发	
	///@param	pSysNetDeviceCategory	被刷新的CSysNetDeviceCategory
	///@param	pNewSysNetDeviceCategory	新的值
	virtual void beforeUpdate(CSysNetDeviceCategory *pSysNetDeviceCategory, CWriteableSysNetDeviceCategory *pNewSysNetDeviceCategory);
	
	///更新后触发
	///@param	pSysNetDeviceCategory	被刷新的CSysNetDeviceCategory
	virtual void afterUpdate(CSysNetDeviceCategory *pSysNetDeviceCategory);
	
	///删除前触发
	///@param	pSysNetDeviceCategory	要删除的CSysNetDeviceCategory
	virtual void beforeRemove(CSysNetDeviceCategory *pSysNetDeviceCategory);
	
	///确认加入后触发
	///@param	pSysNetDeviceCategory	已经加入的SysNetDeviceCategory
	virtual void commitAdd(CSysNetDeviceCategory *pSysNetDeviceCategory);

	///确认更新后触发
	///@param	pSysNetDeviceCategory	被刷新的CSysNetDeviceCategory
	///@param	poldSysNetDeviceCategory	原来的值
	virtual void commitUpdate(CSysNetDeviceCategory *pSysNetDeviceCategory, CWriteableSysNetDeviceCategory *pOldSysNetDeviceCategory);
	
	///确认删除后触发
	///@param	pSysNetDeviceCategory	已经删除的CSysNetDeviceCategory
	virtual void commitRemove(CWriteableSysNetDeviceCategory *pSysNetDeviceCategory);

	///所有相关的触发器
	vector<CSysNetDeviceCategoryActionTrigger *> *pActionTriggers;
	vector<CSysNetDeviceCategoryCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetDeviceCategory compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetManufactoryFactory是一个设备厂商的对象工厂。它包含了一批设备厂商，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对设备厂商的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetManufactoryFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetManufactoryFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetManufactory，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetManufactoryFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetManufactoryFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetManufactory
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetManufactory，文件名将根据配置文件中的定义SysNetManufactoryCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetManufactory
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetManufactory，文件名将根据配置文件中的定义SysNetManufactoryCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetManufactoryResource;

	///将一个CSysNetManufactory加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetManufactory	要加入的SysNetManufactory
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetManufactory *add(CWriteableSysNetManufactory *pSysNetManufactory, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetManufactory的值
	///@param	pSysNetManufactory	被刷新的CSysNetManufactory
	///@param	pNewSysNetManufactory	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetManufactory *pSysNetManufactory, CWriteableSysNetManufactory *pNewSysNetManufactory, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetManufactory	  需要被刷新或者新增的CSysNetManufactory,等于NULL表示是需要新增的
	///@param	pNewSysNetManufactory	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetManufactory* addOrUpdate(CSysNetManufactory *pSysNetManufactory, CWriteableSysNetManufactory *pNewSysNetManufactory, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetManufactory，同时删除其索引
	///@param	pSysNetManufactory	要删除的CSysNetManufactory
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetManufactory *pSysNetManufactory, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetManufactory
	///@param	pSysNetManufactory	要读取的CSysNetManufactory
	///@param	pTragetSysNetManufactory	存放结果的CSysNetManufactory
	void retrieve(CSysNetManufactory *pSysNetManufactory, CWriteableSysNetManufactory *pTargetSysNetManufactory);
	
	///获取第一个CSysNetManufactory
	///@return	得到的第一个CSysNetManufactory，如果没有，则返回NULL
	CSysNetManufactory *getFirst(void);
	
	///获取下一个CSysNetManufactory
	///@return	得到下一个CSysNetManufactory，如果没有，则返回NULL
	CSysNetManufactory *getNext(void);
	
	///结束获取CSysNetManufactory
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetManufactoryActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetManufactoryActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetManufactoryCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetManufactoryCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetManufactoryIteratorByAll;

	///开始寻找CSysNetManufactory
	///@return	满足条件的地一个CSysNetManufactory，如果找不到，返回NULL
	CSysNetManufactory *startFindByAll();

	///寻找下一个符合条件的CSysNetManufactory，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetManufactory，如果已经没有一个满足要求了，则返回NULL
	CSysNetManufactory *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetManufactory
	///@param	ID	
	///@return	找到的CSysNetManufactory，如果找不到，返回NULL
	CSysNetManufactory *findByOne( const CReadOnlyVolumeType&  ID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetManufactory加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetManufactory	要加入的SysNetManufactory
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetManufactory *internalAdd(CWriteableSysNetManufactory *pSysNetManufactory, bool bNoTransaction);
	
	
	///刷新该CSysNetManufactory的键值
	///@param	pSysNetManufactory	被刷新的CSysNetManufactory
	///@param	pNewSysNetManufactory	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetManufactory *pSysNetManufactory, CWriteableSysNetManufactory *pNewSysNetManufactory, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetManufactory，同时删除其索引
	///@param	pSysNetManufactory	要删除的CSysNetManufactory
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetManufactory *pSysNetManufactory, bool bNoTransaction);
/*
	///检查某个CSysNetManufactory是否属于本对象工厂
	///@param	pSysNetManufactory	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetManufactory *pSysNetManufactory);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetManufactory	要加入的SysNetManufactory
	virtual void beforeAdd(CWriteableSysNetManufactory *pSysNetManufactory);
	
	///加入后触发
	///@param	pSysNetManufactory	已经加入的SysNetManufactory
	virtual void afterAdd(CSysNetManufactory *pSysNetManufactory);

	///更新前触发	
	///@param	pSysNetManufactory	被刷新的CSysNetManufactory
	///@param	pNewSysNetManufactory	新的值
	virtual void beforeUpdate(CSysNetManufactory *pSysNetManufactory, CWriteableSysNetManufactory *pNewSysNetManufactory);
	
	///更新后触发
	///@param	pSysNetManufactory	被刷新的CSysNetManufactory
	virtual void afterUpdate(CSysNetManufactory *pSysNetManufactory);
	
	///删除前触发
	///@param	pSysNetManufactory	要删除的CSysNetManufactory
	virtual void beforeRemove(CSysNetManufactory *pSysNetManufactory);
	
	///确认加入后触发
	///@param	pSysNetManufactory	已经加入的SysNetManufactory
	virtual void commitAdd(CSysNetManufactory *pSysNetManufactory);

	///确认更新后触发
	///@param	pSysNetManufactory	被刷新的CSysNetManufactory
	///@param	poldSysNetManufactory	原来的值
	virtual void commitUpdate(CSysNetManufactory *pSysNetManufactory, CWriteableSysNetManufactory *pOldSysNetManufactory);
	
	///确认删除后触发
	///@param	pSysNetManufactory	已经删除的CSysNetManufactory
	virtual void commitRemove(CWriteableSysNetManufactory *pSysNetManufactory);

	///所有相关的触发器
	vector<CSysNetManufactoryActionTrigger *> *pActionTriggers;
	vector<CSysNetManufactoryCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetManufactory compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetCommunityFactory是一个设备共同体的对象工厂。它包含了一批设备共同体，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对设备共同体的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetCommunityFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetCommunityFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetCommunity，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetCommunityFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetCommunityFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetCommunity
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetCommunity，文件名将根据配置文件中的定义SysNetCommunityCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetCommunity
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetCommunity，文件名将根据配置文件中的定义SysNetCommunityCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetCommunityResource;

	///将一个CSysNetCommunity加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetCommunity	要加入的SysNetCommunity
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetCommunity *add(CWriteableSysNetCommunity *pSysNetCommunity, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetCommunity的值
	///@param	pSysNetCommunity	被刷新的CSysNetCommunity
	///@param	pNewSysNetCommunity	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetCommunity *pSysNetCommunity, CWriteableSysNetCommunity *pNewSysNetCommunity, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetCommunity	  需要被刷新或者新增的CSysNetCommunity,等于NULL表示是需要新增的
	///@param	pNewSysNetCommunity	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetCommunity* addOrUpdate(CSysNetCommunity *pSysNetCommunity, CWriteableSysNetCommunity *pNewSysNetCommunity, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetCommunity，同时删除其索引
	///@param	pSysNetCommunity	要删除的CSysNetCommunity
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetCommunity *pSysNetCommunity, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetCommunity
	///@param	pSysNetCommunity	要读取的CSysNetCommunity
	///@param	pTragetSysNetCommunity	存放结果的CSysNetCommunity
	void retrieve(CSysNetCommunity *pSysNetCommunity, CWriteableSysNetCommunity *pTargetSysNetCommunity);
	
	///获取第一个CSysNetCommunity
	///@return	得到的第一个CSysNetCommunity，如果没有，则返回NULL
	CSysNetCommunity *getFirst(void);
	
	///获取下一个CSysNetCommunity
	///@return	得到下一个CSysNetCommunity，如果没有，则返回NULL
	CSysNetCommunity *getNext(void);
	
	///结束获取CSysNetCommunity
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetCommunityActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetCommunityActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetCommunityCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetCommunityCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetCommunityIteratorByAll;

	///开始寻找CSysNetCommunity
	///@return	满足条件的地一个CSysNetCommunity，如果找不到，返回NULL
	CSysNetCommunity *startFindByAll();

	///寻找下一个符合条件的CSysNetCommunity，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetCommunity，如果已经没有一个满足要求了，则返回NULL
	CSysNetCommunity *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetCommunity
	///@param	ID	
	///@return	找到的CSysNetCommunity，如果找不到，返回NULL
	CSysNetCommunity *findByOne( const CReadOnlyVolumeType&  ID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetCommunity加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetCommunity	要加入的SysNetCommunity
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetCommunity *internalAdd(CWriteableSysNetCommunity *pSysNetCommunity, bool bNoTransaction);
	
	
	///刷新该CSysNetCommunity的键值
	///@param	pSysNetCommunity	被刷新的CSysNetCommunity
	///@param	pNewSysNetCommunity	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetCommunity *pSysNetCommunity, CWriteableSysNetCommunity *pNewSysNetCommunity, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetCommunity，同时删除其索引
	///@param	pSysNetCommunity	要删除的CSysNetCommunity
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetCommunity *pSysNetCommunity, bool bNoTransaction);
/*
	///检查某个CSysNetCommunity是否属于本对象工厂
	///@param	pSysNetCommunity	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetCommunity *pSysNetCommunity);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetCommunity	要加入的SysNetCommunity
	virtual void beforeAdd(CWriteableSysNetCommunity *pSysNetCommunity);
	
	///加入后触发
	///@param	pSysNetCommunity	已经加入的SysNetCommunity
	virtual void afterAdd(CSysNetCommunity *pSysNetCommunity);

	///更新前触发	
	///@param	pSysNetCommunity	被刷新的CSysNetCommunity
	///@param	pNewSysNetCommunity	新的值
	virtual void beforeUpdate(CSysNetCommunity *pSysNetCommunity, CWriteableSysNetCommunity *pNewSysNetCommunity);
	
	///更新后触发
	///@param	pSysNetCommunity	被刷新的CSysNetCommunity
	virtual void afterUpdate(CSysNetCommunity *pSysNetCommunity);
	
	///删除前触发
	///@param	pSysNetCommunity	要删除的CSysNetCommunity
	virtual void beforeRemove(CSysNetCommunity *pSysNetCommunity);
	
	///确认加入后触发
	///@param	pSysNetCommunity	已经加入的SysNetCommunity
	virtual void commitAdd(CSysNetCommunity *pSysNetCommunity);

	///确认更新后触发
	///@param	pSysNetCommunity	被刷新的CSysNetCommunity
	///@param	poldSysNetCommunity	原来的值
	virtual void commitUpdate(CSysNetCommunity *pSysNetCommunity, CWriteableSysNetCommunity *pOldSysNetCommunity);
	
	///确认删除后触发
	///@param	pSysNetCommunity	已经删除的CSysNetCommunity
	virtual void commitRemove(CWriteableSysNetCommunity *pSysNetCommunity);

	///所有相关的触发器
	vector<CSysNetCommunityActionTrigger *> *pActionTriggers;
	vector<CSysNetCommunityCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetCommunity compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPortTypeFactory是一个端口类型的对象工厂。它包含了一批端口类型，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对端口类型的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPortTypeFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetPortTypeFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetPortType，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetPortTypeFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetPortTypeFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetPortType
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetPortType，文件名将根据配置文件中的定义SysNetPortTypeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetPortType
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetPortType，文件名将根据配置文件中的定义SysNetPortTypeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetPortTypeResource;

	///将一个CSysNetPortType加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetPortType	要加入的SysNetPortType
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetPortType *add(CWriteableSysNetPortType *pSysNetPortType, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetPortType的值
	///@param	pSysNetPortType	被刷新的CSysNetPortType
	///@param	pNewSysNetPortType	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetPortType *pSysNetPortType, CWriteableSysNetPortType *pNewSysNetPortType, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetPortType	  需要被刷新或者新增的CSysNetPortType,等于NULL表示是需要新增的
	///@param	pNewSysNetPortType	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetPortType* addOrUpdate(CSysNetPortType *pSysNetPortType, CWriteableSysNetPortType *pNewSysNetPortType, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetPortType，同时删除其索引
	///@param	pSysNetPortType	要删除的CSysNetPortType
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetPortType *pSysNetPortType, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetPortType
	///@param	pSysNetPortType	要读取的CSysNetPortType
	///@param	pTragetSysNetPortType	存放结果的CSysNetPortType
	void retrieve(CSysNetPortType *pSysNetPortType, CWriteableSysNetPortType *pTargetSysNetPortType);
	
	///获取第一个CSysNetPortType
	///@return	得到的第一个CSysNetPortType，如果没有，则返回NULL
	CSysNetPortType *getFirst(void);
	
	///获取下一个CSysNetPortType
	///@return	得到下一个CSysNetPortType，如果没有，则返回NULL
	CSysNetPortType *getNext(void);
	
	///结束获取CSysNetPortType
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetPortTypeActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetPortTypeActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetPortTypeCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetPortTypeCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetPortTypeIteratorByAll;

	///开始寻找CSysNetPortType
	///@return	满足条件的地一个CSysNetPortType，如果找不到，返回NULL
	CSysNetPortType *startFindByAll();

	///寻找下一个符合条件的CSysNetPortType，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetPortType，如果已经没有一个满足要求了，则返回NULL
	CSysNetPortType *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetPortType
	///@param	ID	
	///@return	找到的CSysNetPortType，如果找不到，返回NULL
	CSysNetPortType *findByOne( const CReadOnlyVolumeType&  ID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetPortType加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetPortType	要加入的SysNetPortType
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetPortType *internalAdd(CWriteableSysNetPortType *pSysNetPortType, bool bNoTransaction);
	
	
	///刷新该CSysNetPortType的键值
	///@param	pSysNetPortType	被刷新的CSysNetPortType
	///@param	pNewSysNetPortType	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetPortType *pSysNetPortType, CWriteableSysNetPortType *pNewSysNetPortType, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetPortType，同时删除其索引
	///@param	pSysNetPortType	要删除的CSysNetPortType
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetPortType *pSysNetPortType, bool bNoTransaction);
/*
	///检查某个CSysNetPortType是否属于本对象工厂
	///@param	pSysNetPortType	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetPortType *pSysNetPortType);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetPortType	要加入的SysNetPortType
	virtual void beforeAdd(CWriteableSysNetPortType *pSysNetPortType);
	
	///加入后触发
	///@param	pSysNetPortType	已经加入的SysNetPortType
	virtual void afterAdd(CSysNetPortType *pSysNetPortType);

	///更新前触发	
	///@param	pSysNetPortType	被刷新的CSysNetPortType
	///@param	pNewSysNetPortType	新的值
	virtual void beforeUpdate(CSysNetPortType *pSysNetPortType, CWriteableSysNetPortType *pNewSysNetPortType);
	
	///更新后触发
	///@param	pSysNetPortType	被刷新的CSysNetPortType
	virtual void afterUpdate(CSysNetPortType *pSysNetPortType);
	
	///删除前触发
	///@param	pSysNetPortType	要删除的CSysNetPortType
	virtual void beforeRemove(CSysNetPortType *pSysNetPortType);
	
	///确认加入后触发
	///@param	pSysNetPortType	已经加入的SysNetPortType
	virtual void commitAdd(CSysNetPortType *pSysNetPortType);

	///确认更新后触发
	///@param	pSysNetPortType	被刷新的CSysNetPortType
	///@param	poldSysNetPortType	原来的值
	virtual void commitUpdate(CSysNetPortType *pSysNetPortType, CWriteableSysNetPortType *pOldSysNetPortType);
	
	///确认删除后触发
	///@param	pSysNetPortType	已经删除的CSysNetPortType
	virtual void commitRemove(CWriteableSysNetPortType *pSysNetPortType);

	///所有相关的触发器
	vector<CSysNetPortTypeActionTrigger *> *pActionTriggers;
	vector<CSysNetPortTypeCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetPortType compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetInterfaceFactory是一个端口的对象工厂。它包含了一批端口，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///	SysDeviceIDTypeIndex
///	SysObjectIDTypeIndex
///使用本对象工厂，可以完成对端口的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///		使用startFindByDeviceID，findNextByDeviceID和endFindByDeviceID完成查询操作
///		使用findByObjectID，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetInterfaceFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetInterfaceFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetInterface，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetInterfaceFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetInterfaceFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetInterface
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetInterface，文件名将根据配置文件中的定义SysNetInterfaceCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetInterface
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetInterface，文件名将根据配置文件中的定义SysNetInterfaceCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetInterfaceResource;

	///将一个CSysNetInterface加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetInterface	要加入的SysNetInterface
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetInterface *add(CWriteableSysNetInterface *pSysNetInterface, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetInterface的值
	///@param	pSysNetInterface	被刷新的CSysNetInterface
	///@param	pNewSysNetInterface	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetInterface *pSysNetInterface, CWriteableSysNetInterface *pNewSysNetInterface, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetInterface	  需要被刷新或者新增的CSysNetInterface,等于NULL表示是需要新增的
	///@param	pNewSysNetInterface	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetInterface* addOrUpdate(CSysNetInterface *pSysNetInterface, CWriteableSysNetInterface *pNewSysNetInterface, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetInterface，同时删除其索引
	///@param	pSysNetInterface	要删除的CSysNetInterface
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetInterface *pSysNetInterface, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetInterface
	///@param	pSysNetInterface	要读取的CSysNetInterface
	///@param	pTragetSysNetInterface	存放结果的CSysNetInterface
	void retrieve(CSysNetInterface *pSysNetInterface, CWriteableSysNetInterface *pTargetSysNetInterface);
	
	///获取第一个CSysNetInterface
	///@return	得到的第一个CSysNetInterface，如果没有，则返回NULL
	CSysNetInterface *getFirst(void);
	
	///获取下一个CSysNetInterface
	///@return	得到下一个CSysNetInterface，如果没有，则返回NULL
	CSysNetInterface *getNext(void);
	
	///结束获取CSysNetInterface
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetInterfaceActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetInterfaceActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetInterfaceCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetInterfaceCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetInterfaceIteratorByAll;

	///开始寻找CSysNetInterface
	///@return	满足条件的地一个CSysNetInterface，如果找不到，返回NULL
	CSysNetInterface *startFindByAll();

	///寻找下一个符合条件的CSysNetInterface，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetInterface，如果已经没有一个满足要求了，则返回NULL
	CSysNetInterface *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetInterface
	///@param	ID	
	///@return	找到的CSysNetInterface，如果找不到，返回NULL
	CSysNetInterface *findByOne( const CReadOnlyVolumeType&  ID);



	friend class CSysNetInterfaceIteratorByDeviceID;

	///开始寻找CSysNetInterface
	///@param	DeviceID	
	///@return	满足条件的地一个CSysNetInterface，如果找不到，返回NULL
	CSysNetInterface *startFindByDeviceID( const CReadOnlyVolumeType& DeviceID);

	///寻找下一个符合条件的CSysNetInterface，必须在startFindByDeviceID以后，endFindByDeviceID之前叫用
	///@return	下一个满足条件CSysNetInterface，如果已经没有一个满足要求了，则返回NULL
	CSysNetInterface *findNextByDeviceID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDeviceID(void);

	///寻找CSysNetInterface
	///@param	ObjectID	
	///@return	找到的CSysNetInterface，如果找不到，返回NULL
	CSysNetInterface *findByObjectID( const CReadOnlyNetObjectIDType&  ObjectID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetInterface加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetInterface	要加入的SysNetInterface
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetInterface *internalAdd(CWriteableSysNetInterface *pSysNetInterface, bool bNoTransaction);
	
	
	///刷新该CSysNetInterface的键值
	///@param	pSysNetInterface	被刷新的CSysNetInterface
	///@param	pNewSysNetInterface	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetInterface *pSysNetInterface, CWriteableSysNetInterface *pNewSysNetInterface, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetInterface，同时删除其索引
	///@param	pSysNetInterface	要删除的CSysNetInterface
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetInterface *pSysNetInterface, bool bNoTransaction);
/*
	///检查某个CSysNetInterface是否属于本对象工厂
	///@param	pSysNetInterface	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetInterface *pSysNetInterface);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	///基于DeviceID的索引
	CAVLTree *pSysDeviceIDTypeIndex;
	///基于ObjectID的索引
	CAVLTree *pSysObjectIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	///按照DeviceID检索时，存储的查询参数
	CVolumeType queryDeviceIDInSearchByDeviceID;
	
	///按照DeviceID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDeviceID;
	
	///加入前触发
	///@param	pSysNetInterface	要加入的SysNetInterface
	virtual void beforeAdd(CWriteableSysNetInterface *pSysNetInterface);
	
	///加入后触发
	///@param	pSysNetInterface	已经加入的SysNetInterface
	virtual void afterAdd(CSysNetInterface *pSysNetInterface);

	///更新前触发	
	///@param	pSysNetInterface	被刷新的CSysNetInterface
	///@param	pNewSysNetInterface	新的值
	virtual void beforeUpdate(CSysNetInterface *pSysNetInterface, CWriteableSysNetInterface *pNewSysNetInterface);
	
	///更新后触发
	///@param	pSysNetInterface	被刷新的CSysNetInterface
	virtual void afterUpdate(CSysNetInterface *pSysNetInterface);
	
	///删除前触发
	///@param	pSysNetInterface	要删除的CSysNetInterface
	virtual void beforeRemove(CSysNetInterface *pSysNetInterface);
	
	///确认加入后触发
	///@param	pSysNetInterface	已经加入的SysNetInterface
	virtual void commitAdd(CSysNetInterface *pSysNetInterface);

	///确认更新后触发
	///@param	pSysNetInterface	被刷新的CSysNetInterface
	///@param	poldSysNetInterface	原来的值
	virtual void commitUpdate(CSysNetInterface *pSysNetInterface, CWriteableSysNetInterface *pOldSysNetInterface);
	
	///确认删除后触发
	///@param	pSysNetInterface	已经删除的CSysNetInterface
	virtual void commitRemove(CWriteableSysNetInterface *pSysNetInterface);

	///所有相关的触发器
	vector<CSysNetInterfaceActionTrigger *> *pActionTriggers;
	vector<CSysNetInterfaceCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetInterface compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGeneralOIDFactory是一个通用OID的对象工厂。它包含了一批通用OID，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对通用OID的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGeneralOIDFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetGeneralOIDFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetGeneralOID，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetGeneralOIDFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetGeneralOIDFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetGeneralOID
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetGeneralOID，文件名将根据配置文件中的定义SysNetGeneralOIDCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetGeneralOID
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetGeneralOID，文件名将根据配置文件中的定义SysNetGeneralOIDCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetGeneralOIDResource;

	///将一个CSysNetGeneralOID加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetGeneralOID	要加入的SysNetGeneralOID
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetGeneralOID *add(CWriteableSysNetGeneralOID *pSysNetGeneralOID, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetGeneralOID的值
	///@param	pSysNetGeneralOID	被刷新的CSysNetGeneralOID
	///@param	pNewSysNetGeneralOID	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetGeneralOID *pSysNetGeneralOID, CWriteableSysNetGeneralOID *pNewSysNetGeneralOID, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetGeneralOID	  需要被刷新或者新增的CSysNetGeneralOID,等于NULL表示是需要新增的
	///@param	pNewSysNetGeneralOID	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetGeneralOID* addOrUpdate(CSysNetGeneralOID *pSysNetGeneralOID, CWriteableSysNetGeneralOID *pNewSysNetGeneralOID, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetGeneralOID，同时删除其索引
	///@param	pSysNetGeneralOID	要删除的CSysNetGeneralOID
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetGeneralOID *pSysNetGeneralOID, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetGeneralOID
	///@param	pSysNetGeneralOID	要读取的CSysNetGeneralOID
	///@param	pTragetSysNetGeneralOID	存放结果的CSysNetGeneralOID
	void retrieve(CSysNetGeneralOID *pSysNetGeneralOID, CWriteableSysNetGeneralOID *pTargetSysNetGeneralOID);
	
	///获取第一个CSysNetGeneralOID
	///@return	得到的第一个CSysNetGeneralOID，如果没有，则返回NULL
	CSysNetGeneralOID *getFirst(void);
	
	///获取下一个CSysNetGeneralOID
	///@return	得到下一个CSysNetGeneralOID，如果没有，则返回NULL
	CSysNetGeneralOID *getNext(void);
	
	///结束获取CSysNetGeneralOID
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetGeneralOIDActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetGeneralOIDActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetGeneralOIDCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetGeneralOIDCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetGeneralOIDIteratorByAll;

	///开始寻找CSysNetGeneralOID
	///@return	满足条件的地一个CSysNetGeneralOID，如果找不到，返回NULL
	CSysNetGeneralOID *startFindByAll();

	///寻找下一个符合条件的CSysNetGeneralOID，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetGeneralOID，如果已经没有一个满足要求了，则返回NULL
	CSysNetGeneralOID *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetGeneralOID
	///@param	ID	
	///@return	找到的CSysNetGeneralOID，如果找不到，返回NULL
	CSysNetGeneralOID *findByOne( const CReadOnlyVolumeType&  ID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetGeneralOID加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetGeneralOID	要加入的SysNetGeneralOID
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetGeneralOID *internalAdd(CWriteableSysNetGeneralOID *pSysNetGeneralOID, bool bNoTransaction);
	
	
	///刷新该CSysNetGeneralOID的键值
	///@param	pSysNetGeneralOID	被刷新的CSysNetGeneralOID
	///@param	pNewSysNetGeneralOID	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetGeneralOID *pSysNetGeneralOID, CWriteableSysNetGeneralOID *pNewSysNetGeneralOID, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetGeneralOID，同时删除其索引
	///@param	pSysNetGeneralOID	要删除的CSysNetGeneralOID
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetGeneralOID *pSysNetGeneralOID, bool bNoTransaction);
/*
	///检查某个CSysNetGeneralOID是否属于本对象工厂
	///@param	pSysNetGeneralOID	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetGeneralOID *pSysNetGeneralOID);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetGeneralOID	要加入的SysNetGeneralOID
	virtual void beforeAdd(CWriteableSysNetGeneralOID *pSysNetGeneralOID);
	
	///加入后触发
	///@param	pSysNetGeneralOID	已经加入的SysNetGeneralOID
	virtual void afterAdd(CSysNetGeneralOID *pSysNetGeneralOID);

	///更新前触发	
	///@param	pSysNetGeneralOID	被刷新的CSysNetGeneralOID
	///@param	pNewSysNetGeneralOID	新的值
	virtual void beforeUpdate(CSysNetGeneralOID *pSysNetGeneralOID, CWriteableSysNetGeneralOID *pNewSysNetGeneralOID);
	
	///更新后触发
	///@param	pSysNetGeneralOID	被刷新的CSysNetGeneralOID
	virtual void afterUpdate(CSysNetGeneralOID *pSysNetGeneralOID);
	
	///删除前触发
	///@param	pSysNetGeneralOID	要删除的CSysNetGeneralOID
	virtual void beforeRemove(CSysNetGeneralOID *pSysNetGeneralOID);
	
	///确认加入后触发
	///@param	pSysNetGeneralOID	已经加入的SysNetGeneralOID
	virtual void commitAdd(CSysNetGeneralOID *pSysNetGeneralOID);

	///确认更新后触发
	///@param	pSysNetGeneralOID	被刷新的CSysNetGeneralOID
	///@param	poldSysNetGeneralOID	原来的值
	virtual void commitUpdate(CSysNetGeneralOID *pSysNetGeneralOID, CWriteableSysNetGeneralOID *pOldSysNetGeneralOID);
	
	///确认删除后触发
	///@param	pSysNetGeneralOID	已经删除的CSysNetGeneralOID
	virtual void commitRemove(CWriteableSysNetGeneralOID *pSysNetGeneralOID);

	///所有相关的触发器
	vector<CSysNetGeneralOIDActionTrigger *> *pActionTriggers;
	vector<CSysNetGeneralOIDCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetGeneralOID compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTypeFactory是一个监控对象类别的对象工厂。它包含了一批监控对象类别，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对监控对象类别的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTypeFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetMonitorTypeFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetMonitorType，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetMonitorTypeFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorTypeFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetMonitorType
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetMonitorType，文件名将根据配置文件中的定义SysNetMonitorTypeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetMonitorType
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetMonitorType，文件名将根据配置文件中的定义SysNetMonitorTypeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetMonitorTypeResource;

	///将一个CSysNetMonitorType加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetMonitorType	要加入的SysNetMonitorType
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetMonitorType *add(CWriteableSysNetMonitorType *pSysNetMonitorType, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetMonitorType的值
	///@param	pSysNetMonitorType	被刷新的CSysNetMonitorType
	///@param	pNewSysNetMonitorType	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetMonitorType *pSysNetMonitorType, CWriteableSysNetMonitorType *pNewSysNetMonitorType, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetMonitorType	  需要被刷新或者新增的CSysNetMonitorType,等于NULL表示是需要新增的
	///@param	pNewSysNetMonitorType	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetMonitorType* addOrUpdate(CSysNetMonitorType *pSysNetMonitorType, CWriteableSysNetMonitorType *pNewSysNetMonitorType, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetMonitorType，同时删除其索引
	///@param	pSysNetMonitorType	要删除的CSysNetMonitorType
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetMonitorType *pSysNetMonitorType, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetMonitorType
	///@param	pSysNetMonitorType	要读取的CSysNetMonitorType
	///@param	pTragetSysNetMonitorType	存放结果的CSysNetMonitorType
	void retrieve(CSysNetMonitorType *pSysNetMonitorType, CWriteableSysNetMonitorType *pTargetSysNetMonitorType);
	
	///获取第一个CSysNetMonitorType
	///@return	得到的第一个CSysNetMonitorType，如果没有，则返回NULL
	CSysNetMonitorType *getFirst(void);
	
	///获取下一个CSysNetMonitorType
	///@return	得到下一个CSysNetMonitorType，如果没有，则返回NULL
	CSysNetMonitorType *getNext(void);
	
	///结束获取CSysNetMonitorType
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetMonitorTypeActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetMonitorTypeActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetMonitorTypeCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetMonitorTypeCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetMonitorTypeIteratorByAll;

	///开始寻找CSysNetMonitorType
	///@return	满足条件的地一个CSysNetMonitorType，如果找不到，返回NULL
	CSysNetMonitorType *startFindByAll();

	///寻找下一个符合条件的CSysNetMonitorType，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetMonitorType，如果已经没有一个满足要求了，则返回NULL
	CSysNetMonitorType *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetMonitorType
	///@param	ID	
	///@return	找到的CSysNetMonitorType，如果找不到，返回NULL
	CSysNetMonitorType *findByOne( const CReadOnlyVolumeType&  ID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetMonitorType加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetMonitorType	要加入的SysNetMonitorType
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetMonitorType *internalAdd(CWriteableSysNetMonitorType *pSysNetMonitorType, bool bNoTransaction);
	
	
	///刷新该CSysNetMonitorType的键值
	///@param	pSysNetMonitorType	被刷新的CSysNetMonitorType
	///@param	pNewSysNetMonitorType	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetMonitorType *pSysNetMonitorType, CWriteableSysNetMonitorType *pNewSysNetMonitorType, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetMonitorType，同时删除其索引
	///@param	pSysNetMonitorType	要删除的CSysNetMonitorType
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetMonitorType *pSysNetMonitorType, bool bNoTransaction);
/*
	///检查某个CSysNetMonitorType是否属于本对象工厂
	///@param	pSysNetMonitorType	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetMonitorType *pSysNetMonitorType);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetMonitorType	要加入的SysNetMonitorType
	virtual void beforeAdd(CWriteableSysNetMonitorType *pSysNetMonitorType);
	
	///加入后触发
	///@param	pSysNetMonitorType	已经加入的SysNetMonitorType
	virtual void afterAdd(CSysNetMonitorType *pSysNetMonitorType);

	///更新前触发	
	///@param	pSysNetMonitorType	被刷新的CSysNetMonitorType
	///@param	pNewSysNetMonitorType	新的值
	virtual void beforeUpdate(CSysNetMonitorType *pSysNetMonitorType, CWriteableSysNetMonitorType *pNewSysNetMonitorType);
	
	///更新后触发
	///@param	pSysNetMonitorType	被刷新的CSysNetMonitorType
	virtual void afterUpdate(CSysNetMonitorType *pSysNetMonitorType);
	
	///删除前触发
	///@param	pSysNetMonitorType	要删除的CSysNetMonitorType
	virtual void beforeRemove(CSysNetMonitorType *pSysNetMonitorType);
	
	///确认加入后触发
	///@param	pSysNetMonitorType	已经加入的SysNetMonitorType
	virtual void commitAdd(CSysNetMonitorType *pSysNetMonitorType);

	///确认更新后触发
	///@param	pSysNetMonitorType	被刷新的CSysNetMonitorType
	///@param	poldSysNetMonitorType	原来的值
	virtual void commitUpdate(CSysNetMonitorType *pSysNetMonitorType, CWriteableSysNetMonitorType *pOldSysNetMonitorType);
	
	///确认删除后触发
	///@param	pSysNetMonitorType	已经删除的CSysNetMonitorType
	virtual void commitRemove(CWriteableSysNetMonitorType *pSysNetMonitorType);

	///所有相关的触发器
	vector<CSysNetMonitorTypeActionTrigger *> *pActionTriggers;
	vector<CSysNetMonitorTypeCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetMonitorType compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrScopeFactory是一个指标统表的对象工厂。它包含了一批指标统表，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对指标统表的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrScopeFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetMonitorAttrScopeFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetMonitorAttrScope，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetMonitorAttrScopeFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorAttrScopeFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetMonitorAttrScope
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetMonitorAttrScope，文件名将根据配置文件中的定义SysNetMonitorAttrScopeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetMonitorAttrScope
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetMonitorAttrScope，文件名将根据配置文件中的定义SysNetMonitorAttrScopeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetMonitorAttrScopeResource;

	///将一个CSysNetMonitorAttrScope加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetMonitorAttrScope	要加入的SysNetMonitorAttrScope
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetMonitorAttrScope *add(CWriteableSysNetMonitorAttrScope *pSysNetMonitorAttrScope, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetMonitorAttrScope的值
	///@param	pSysNetMonitorAttrScope	被刷新的CSysNetMonitorAttrScope
	///@param	pNewSysNetMonitorAttrScope	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope, CWriteableSysNetMonitorAttrScope *pNewSysNetMonitorAttrScope, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetMonitorAttrScope	  需要被刷新或者新增的CSysNetMonitorAttrScope,等于NULL表示是需要新增的
	///@param	pNewSysNetMonitorAttrScope	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetMonitorAttrScope* addOrUpdate(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope, CWriteableSysNetMonitorAttrScope *pNewSysNetMonitorAttrScope, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetMonitorAttrScope，同时删除其索引
	///@param	pSysNetMonitorAttrScope	要删除的CSysNetMonitorAttrScope
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetMonitorAttrScope
	///@param	pSysNetMonitorAttrScope	要读取的CSysNetMonitorAttrScope
	///@param	pTragetSysNetMonitorAttrScope	存放结果的CSysNetMonitorAttrScope
	void retrieve(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope, CWriteableSysNetMonitorAttrScope *pTargetSysNetMonitorAttrScope);
	
	///获取第一个CSysNetMonitorAttrScope
	///@return	得到的第一个CSysNetMonitorAttrScope，如果没有，则返回NULL
	CSysNetMonitorAttrScope *getFirst(void);
	
	///获取下一个CSysNetMonitorAttrScope
	///@return	得到下一个CSysNetMonitorAttrScope，如果没有，则返回NULL
	CSysNetMonitorAttrScope *getNext(void);
	
	///结束获取CSysNetMonitorAttrScope
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetMonitorAttrScopeActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetMonitorAttrScopeActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetMonitorAttrScopeCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetMonitorAttrScopeCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetMonitorAttrScopeIteratorByAll;

	///开始寻找CSysNetMonitorAttrScope
	///@return	满足条件的地一个CSysNetMonitorAttrScope，如果找不到，返回NULL
	CSysNetMonitorAttrScope *startFindByAll();

	///寻找下一个符合条件的CSysNetMonitorAttrScope，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetMonitorAttrScope，如果已经没有一个满足要求了，则返回NULL
	CSysNetMonitorAttrScope *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetMonitorAttrScope
	///@param	ID	
	///@return	找到的CSysNetMonitorAttrScope，如果找不到，返回NULL
	CSysNetMonitorAttrScope *findByOne( const CReadOnlyVolumeType&  ID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetMonitorAttrScope加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetMonitorAttrScope	要加入的SysNetMonitorAttrScope
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetMonitorAttrScope *internalAdd(CWriteableSysNetMonitorAttrScope *pSysNetMonitorAttrScope, bool bNoTransaction);
	
	
	///刷新该CSysNetMonitorAttrScope的键值
	///@param	pSysNetMonitorAttrScope	被刷新的CSysNetMonitorAttrScope
	///@param	pNewSysNetMonitorAttrScope	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope, CWriteableSysNetMonitorAttrScope *pNewSysNetMonitorAttrScope, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetMonitorAttrScope，同时删除其索引
	///@param	pSysNetMonitorAttrScope	要删除的CSysNetMonitorAttrScope
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope, bool bNoTransaction);
/*
	///检查某个CSysNetMonitorAttrScope是否属于本对象工厂
	///@param	pSysNetMonitorAttrScope	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetMonitorAttrScope	要加入的SysNetMonitorAttrScope
	virtual void beforeAdd(CWriteableSysNetMonitorAttrScope *pSysNetMonitorAttrScope);
	
	///加入后触发
	///@param	pSysNetMonitorAttrScope	已经加入的SysNetMonitorAttrScope
	virtual void afterAdd(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope);

	///更新前触发	
	///@param	pSysNetMonitorAttrScope	被刷新的CSysNetMonitorAttrScope
	///@param	pNewSysNetMonitorAttrScope	新的值
	virtual void beforeUpdate(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope, CWriteableSysNetMonitorAttrScope *pNewSysNetMonitorAttrScope);
	
	///更新后触发
	///@param	pSysNetMonitorAttrScope	被刷新的CSysNetMonitorAttrScope
	virtual void afterUpdate(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope);
	
	///删除前触发
	///@param	pSysNetMonitorAttrScope	要删除的CSysNetMonitorAttrScope
	virtual void beforeRemove(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope);
	
	///确认加入后触发
	///@param	pSysNetMonitorAttrScope	已经加入的SysNetMonitorAttrScope
	virtual void commitAdd(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope);

	///确认更新后触发
	///@param	pSysNetMonitorAttrScope	被刷新的CSysNetMonitorAttrScope
	///@param	poldSysNetMonitorAttrScope	原来的值
	virtual void commitUpdate(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope, CWriteableSysNetMonitorAttrScope *pOldSysNetMonitorAttrScope);
	
	///确认删除后触发
	///@param	pSysNetMonitorAttrScope	已经删除的CSysNetMonitorAttrScope
	virtual void commitRemove(CWriteableSysNetMonitorAttrScope *pSysNetMonitorAttrScope);

	///所有相关的触发器
	vector<CSysNetMonitorAttrScopeActionTrigger *> *pActionTriggers;
	vector<CSysNetMonitorAttrScopeCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetMonitorAttrScope compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrTypeFactory是一个监控指标表的对象工厂。它包含了一批监控指标表，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对监控指标表的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrTypeFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetMonitorAttrTypeFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetMonitorAttrType，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetMonitorAttrTypeFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorAttrTypeFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetMonitorAttrType
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetMonitorAttrType，文件名将根据配置文件中的定义SysNetMonitorAttrTypeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetMonitorAttrType
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetMonitorAttrType，文件名将根据配置文件中的定义SysNetMonitorAttrTypeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetMonitorAttrTypeResource;

	///将一个CSysNetMonitorAttrType加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetMonitorAttrType	要加入的SysNetMonitorAttrType
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetMonitorAttrType *add(CWriteableSysNetMonitorAttrType *pSysNetMonitorAttrType, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetMonitorAttrType的值
	///@param	pSysNetMonitorAttrType	被刷新的CSysNetMonitorAttrType
	///@param	pNewSysNetMonitorAttrType	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetMonitorAttrType *pSysNetMonitorAttrType, CWriteableSysNetMonitorAttrType *pNewSysNetMonitorAttrType, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetMonitorAttrType	  需要被刷新或者新增的CSysNetMonitorAttrType,等于NULL表示是需要新增的
	///@param	pNewSysNetMonitorAttrType	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetMonitorAttrType* addOrUpdate(CSysNetMonitorAttrType *pSysNetMonitorAttrType, CWriteableSysNetMonitorAttrType *pNewSysNetMonitorAttrType, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetMonitorAttrType，同时删除其索引
	///@param	pSysNetMonitorAttrType	要删除的CSysNetMonitorAttrType
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetMonitorAttrType *pSysNetMonitorAttrType, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetMonitorAttrType
	///@param	pSysNetMonitorAttrType	要读取的CSysNetMonitorAttrType
	///@param	pTragetSysNetMonitorAttrType	存放结果的CSysNetMonitorAttrType
	void retrieve(CSysNetMonitorAttrType *pSysNetMonitorAttrType, CWriteableSysNetMonitorAttrType *pTargetSysNetMonitorAttrType);
	
	///获取第一个CSysNetMonitorAttrType
	///@return	得到的第一个CSysNetMonitorAttrType，如果没有，则返回NULL
	CSysNetMonitorAttrType *getFirst(void);
	
	///获取下一个CSysNetMonitorAttrType
	///@return	得到下一个CSysNetMonitorAttrType，如果没有，则返回NULL
	CSysNetMonitorAttrType *getNext(void);
	
	///结束获取CSysNetMonitorAttrType
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetMonitorAttrTypeActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetMonitorAttrTypeActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetMonitorAttrTypeCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetMonitorAttrTypeCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetMonitorAttrTypeIteratorByAll;

	///开始寻找CSysNetMonitorAttrType
	///@return	满足条件的地一个CSysNetMonitorAttrType，如果找不到，返回NULL
	CSysNetMonitorAttrType *startFindByAll();

	///寻找下一个符合条件的CSysNetMonitorAttrType，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetMonitorAttrType，如果已经没有一个满足要求了，则返回NULL
	CSysNetMonitorAttrType *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetMonitorAttrType
	///@param	ID	
	///@return	找到的CSysNetMonitorAttrType，如果找不到，返回NULL
	CSysNetMonitorAttrType *findByOne( const CReadOnlyVolumeType&  ID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetMonitorAttrType加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetMonitorAttrType	要加入的SysNetMonitorAttrType
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetMonitorAttrType *internalAdd(CWriteableSysNetMonitorAttrType *pSysNetMonitorAttrType, bool bNoTransaction);
	
	
	///刷新该CSysNetMonitorAttrType的键值
	///@param	pSysNetMonitorAttrType	被刷新的CSysNetMonitorAttrType
	///@param	pNewSysNetMonitorAttrType	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetMonitorAttrType *pSysNetMonitorAttrType, CWriteableSysNetMonitorAttrType *pNewSysNetMonitorAttrType, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetMonitorAttrType，同时删除其索引
	///@param	pSysNetMonitorAttrType	要删除的CSysNetMonitorAttrType
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetMonitorAttrType *pSysNetMonitorAttrType, bool bNoTransaction);
/*
	///检查某个CSysNetMonitorAttrType是否属于本对象工厂
	///@param	pSysNetMonitorAttrType	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetMonitorAttrType *pSysNetMonitorAttrType);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetMonitorAttrType	要加入的SysNetMonitorAttrType
	virtual void beforeAdd(CWriteableSysNetMonitorAttrType *pSysNetMonitorAttrType);
	
	///加入后触发
	///@param	pSysNetMonitorAttrType	已经加入的SysNetMonitorAttrType
	virtual void afterAdd(CSysNetMonitorAttrType *pSysNetMonitorAttrType);

	///更新前触发	
	///@param	pSysNetMonitorAttrType	被刷新的CSysNetMonitorAttrType
	///@param	pNewSysNetMonitorAttrType	新的值
	virtual void beforeUpdate(CSysNetMonitorAttrType *pSysNetMonitorAttrType, CWriteableSysNetMonitorAttrType *pNewSysNetMonitorAttrType);
	
	///更新后触发
	///@param	pSysNetMonitorAttrType	被刷新的CSysNetMonitorAttrType
	virtual void afterUpdate(CSysNetMonitorAttrType *pSysNetMonitorAttrType);
	
	///删除前触发
	///@param	pSysNetMonitorAttrType	要删除的CSysNetMonitorAttrType
	virtual void beforeRemove(CSysNetMonitorAttrType *pSysNetMonitorAttrType);
	
	///确认加入后触发
	///@param	pSysNetMonitorAttrType	已经加入的SysNetMonitorAttrType
	virtual void commitAdd(CSysNetMonitorAttrType *pSysNetMonitorAttrType);

	///确认更新后触发
	///@param	pSysNetMonitorAttrType	被刷新的CSysNetMonitorAttrType
	///@param	poldSysNetMonitorAttrType	原来的值
	virtual void commitUpdate(CSysNetMonitorAttrType *pSysNetMonitorAttrType, CWriteableSysNetMonitorAttrType *pOldSysNetMonitorAttrType);
	
	///确认删除后触发
	///@param	pSysNetMonitorAttrType	已经删除的CSysNetMonitorAttrType
	virtual void commitRemove(CWriteableSysNetMonitorAttrType *pSysNetMonitorAttrType);

	///所有相关的触发器
	vector<CSysNetMonitorAttrTypeActionTrigger *> *pActionTriggers;
	vector<CSysNetMonitorAttrTypeCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetMonitorAttrType compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorCommandTypeFactory是一个监控指令表的对象工厂。它包含了一批监控指令表，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对监控指令表的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorCommandTypeFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetMonitorCommandTypeFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetMonitorCommandType，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetMonitorCommandTypeFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorCommandTypeFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetMonitorCommandType
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetMonitorCommandType，文件名将根据配置文件中的定义SysNetMonitorCommandTypeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetMonitorCommandType
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetMonitorCommandType，文件名将根据配置文件中的定义SysNetMonitorCommandTypeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetMonitorCommandTypeResource;

	///将一个CSysNetMonitorCommandType加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetMonitorCommandType	要加入的SysNetMonitorCommandType
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetMonitorCommandType *add(CWriteableSysNetMonitorCommandType *pSysNetMonitorCommandType, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetMonitorCommandType的值
	///@param	pSysNetMonitorCommandType	被刷新的CSysNetMonitorCommandType
	///@param	pNewSysNetMonitorCommandType	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetMonitorCommandType *pSysNetMonitorCommandType, CWriteableSysNetMonitorCommandType *pNewSysNetMonitorCommandType, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetMonitorCommandType	  需要被刷新或者新增的CSysNetMonitorCommandType,等于NULL表示是需要新增的
	///@param	pNewSysNetMonitorCommandType	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetMonitorCommandType* addOrUpdate(CSysNetMonitorCommandType *pSysNetMonitorCommandType, CWriteableSysNetMonitorCommandType *pNewSysNetMonitorCommandType, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetMonitorCommandType，同时删除其索引
	///@param	pSysNetMonitorCommandType	要删除的CSysNetMonitorCommandType
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetMonitorCommandType *pSysNetMonitorCommandType, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetMonitorCommandType
	///@param	pSysNetMonitorCommandType	要读取的CSysNetMonitorCommandType
	///@param	pTragetSysNetMonitorCommandType	存放结果的CSysNetMonitorCommandType
	void retrieve(CSysNetMonitorCommandType *pSysNetMonitorCommandType, CWriteableSysNetMonitorCommandType *pTargetSysNetMonitorCommandType);
	
	///获取第一个CSysNetMonitorCommandType
	///@return	得到的第一个CSysNetMonitorCommandType，如果没有，则返回NULL
	CSysNetMonitorCommandType *getFirst(void);
	
	///获取下一个CSysNetMonitorCommandType
	///@return	得到下一个CSysNetMonitorCommandType，如果没有，则返回NULL
	CSysNetMonitorCommandType *getNext(void);
	
	///结束获取CSysNetMonitorCommandType
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetMonitorCommandTypeActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetMonitorCommandTypeActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetMonitorCommandTypeCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetMonitorCommandTypeCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetMonitorCommandTypeIteratorByAll;

	///开始寻找CSysNetMonitorCommandType
	///@return	满足条件的地一个CSysNetMonitorCommandType，如果找不到，返回NULL
	CSysNetMonitorCommandType *startFindByAll();

	///寻找下一个符合条件的CSysNetMonitorCommandType，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetMonitorCommandType，如果已经没有一个满足要求了，则返回NULL
	CSysNetMonitorCommandType *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetMonitorCommandType
	///@param	ID	
	///@return	找到的CSysNetMonitorCommandType，如果找不到，返回NULL
	CSysNetMonitorCommandType *findByOne( const CReadOnlyVolumeType&  ID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetMonitorCommandType加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetMonitorCommandType	要加入的SysNetMonitorCommandType
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetMonitorCommandType *internalAdd(CWriteableSysNetMonitorCommandType *pSysNetMonitorCommandType, bool bNoTransaction);
	
	
	///刷新该CSysNetMonitorCommandType的键值
	///@param	pSysNetMonitorCommandType	被刷新的CSysNetMonitorCommandType
	///@param	pNewSysNetMonitorCommandType	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetMonitorCommandType *pSysNetMonitorCommandType, CWriteableSysNetMonitorCommandType *pNewSysNetMonitorCommandType, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetMonitorCommandType，同时删除其索引
	///@param	pSysNetMonitorCommandType	要删除的CSysNetMonitorCommandType
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetMonitorCommandType *pSysNetMonitorCommandType, bool bNoTransaction);
/*
	///检查某个CSysNetMonitorCommandType是否属于本对象工厂
	///@param	pSysNetMonitorCommandType	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetMonitorCommandType *pSysNetMonitorCommandType);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetMonitorCommandType	要加入的SysNetMonitorCommandType
	virtual void beforeAdd(CWriteableSysNetMonitorCommandType *pSysNetMonitorCommandType);
	
	///加入后触发
	///@param	pSysNetMonitorCommandType	已经加入的SysNetMonitorCommandType
	virtual void afterAdd(CSysNetMonitorCommandType *pSysNetMonitorCommandType);

	///更新前触发	
	///@param	pSysNetMonitorCommandType	被刷新的CSysNetMonitorCommandType
	///@param	pNewSysNetMonitorCommandType	新的值
	virtual void beforeUpdate(CSysNetMonitorCommandType *pSysNetMonitorCommandType, CWriteableSysNetMonitorCommandType *pNewSysNetMonitorCommandType);
	
	///更新后触发
	///@param	pSysNetMonitorCommandType	被刷新的CSysNetMonitorCommandType
	virtual void afterUpdate(CSysNetMonitorCommandType *pSysNetMonitorCommandType);
	
	///删除前触发
	///@param	pSysNetMonitorCommandType	要删除的CSysNetMonitorCommandType
	virtual void beforeRemove(CSysNetMonitorCommandType *pSysNetMonitorCommandType);
	
	///确认加入后触发
	///@param	pSysNetMonitorCommandType	已经加入的SysNetMonitorCommandType
	virtual void commitAdd(CSysNetMonitorCommandType *pSysNetMonitorCommandType);

	///确认更新后触发
	///@param	pSysNetMonitorCommandType	被刷新的CSysNetMonitorCommandType
	///@param	poldSysNetMonitorCommandType	原来的值
	virtual void commitUpdate(CSysNetMonitorCommandType *pSysNetMonitorCommandType, CWriteableSysNetMonitorCommandType *pOldSysNetMonitorCommandType);
	
	///确认删除后触发
	///@param	pSysNetMonitorCommandType	已经删除的CSysNetMonitorCommandType
	virtual void commitRemove(CWriteableSysNetMonitorCommandType *pSysNetMonitorCommandType);

	///所有相关的触发器
	vector<CSysNetMonitorCommandTypeActionTrigger *> *pActionTriggers;
	vector<CSysNetMonitorCommandTypeCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetMonitorCommandType compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionGroupFactory是一个动作族表的对象工厂。它包含了一批动作族表，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对动作族表的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionGroupFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetMonitorActionGroupFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetMonitorActionGroup，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetMonitorActionGroupFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorActionGroupFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetMonitorActionGroup
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetMonitorActionGroup，文件名将根据配置文件中的定义SysNetMonitorActionGroupCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetMonitorActionGroup
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetMonitorActionGroup，文件名将根据配置文件中的定义SysNetMonitorActionGroupCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetMonitorActionGroupResource;

	///将一个CSysNetMonitorActionGroup加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetMonitorActionGroup	要加入的SysNetMonitorActionGroup
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetMonitorActionGroup *add(CWriteableSysNetMonitorActionGroup *pSysNetMonitorActionGroup, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetMonitorActionGroup的值
	///@param	pSysNetMonitorActionGroup	被刷新的CSysNetMonitorActionGroup
	///@param	pNewSysNetMonitorActionGroup	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup, CWriteableSysNetMonitorActionGroup *pNewSysNetMonitorActionGroup, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetMonitorActionGroup	  需要被刷新或者新增的CSysNetMonitorActionGroup,等于NULL表示是需要新增的
	///@param	pNewSysNetMonitorActionGroup	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetMonitorActionGroup* addOrUpdate(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup, CWriteableSysNetMonitorActionGroup *pNewSysNetMonitorActionGroup, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetMonitorActionGroup，同时删除其索引
	///@param	pSysNetMonitorActionGroup	要删除的CSysNetMonitorActionGroup
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetMonitorActionGroup
	///@param	pSysNetMonitorActionGroup	要读取的CSysNetMonitorActionGroup
	///@param	pTragetSysNetMonitorActionGroup	存放结果的CSysNetMonitorActionGroup
	void retrieve(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup, CWriteableSysNetMonitorActionGroup *pTargetSysNetMonitorActionGroup);
	
	///获取第一个CSysNetMonitorActionGroup
	///@return	得到的第一个CSysNetMonitorActionGroup，如果没有，则返回NULL
	CSysNetMonitorActionGroup *getFirst(void);
	
	///获取下一个CSysNetMonitorActionGroup
	///@return	得到下一个CSysNetMonitorActionGroup，如果没有，则返回NULL
	CSysNetMonitorActionGroup *getNext(void);
	
	///结束获取CSysNetMonitorActionGroup
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetMonitorActionGroupActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetMonitorActionGroupActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetMonitorActionGroupCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetMonitorActionGroupCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetMonitorActionGroupIteratorByAll;

	///开始寻找CSysNetMonitorActionGroup
	///@return	满足条件的地一个CSysNetMonitorActionGroup，如果找不到，返回NULL
	CSysNetMonitorActionGroup *startFindByAll();

	///寻找下一个符合条件的CSysNetMonitorActionGroup，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetMonitorActionGroup，如果已经没有一个满足要求了，则返回NULL
	CSysNetMonitorActionGroup *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetMonitorActionGroup
	///@param	ID	
	///@return	找到的CSysNetMonitorActionGroup，如果找不到，返回NULL
	CSysNetMonitorActionGroup *findByOne( const CReadOnlyVolumeType&  ID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetMonitorActionGroup加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetMonitorActionGroup	要加入的SysNetMonitorActionGroup
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetMonitorActionGroup *internalAdd(CWriteableSysNetMonitorActionGroup *pSysNetMonitorActionGroup, bool bNoTransaction);
	
	
	///刷新该CSysNetMonitorActionGroup的键值
	///@param	pSysNetMonitorActionGroup	被刷新的CSysNetMonitorActionGroup
	///@param	pNewSysNetMonitorActionGroup	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup, CWriteableSysNetMonitorActionGroup *pNewSysNetMonitorActionGroup, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetMonitorActionGroup，同时删除其索引
	///@param	pSysNetMonitorActionGroup	要删除的CSysNetMonitorActionGroup
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup, bool bNoTransaction);
/*
	///检查某个CSysNetMonitorActionGroup是否属于本对象工厂
	///@param	pSysNetMonitorActionGroup	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetMonitorActionGroup	要加入的SysNetMonitorActionGroup
	virtual void beforeAdd(CWriteableSysNetMonitorActionGroup *pSysNetMonitorActionGroup);
	
	///加入后触发
	///@param	pSysNetMonitorActionGroup	已经加入的SysNetMonitorActionGroup
	virtual void afterAdd(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup);

	///更新前触发	
	///@param	pSysNetMonitorActionGroup	被刷新的CSysNetMonitorActionGroup
	///@param	pNewSysNetMonitorActionGroup	新的值
	virtual void beforeUpdate(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup, CWriteableSysNetMonitorActionGroup *pNewSysNetMonitorActionGroup);
	
	///更新后触发
	///@param	pSysNetMonitorActionGroup	被刷新的CSysNetMonitorActionGroup
	virtual void afterUpdate(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup);
	
	///删除前触发
	///@param	pSysNetMonitorActionGroup	要删除的CSysNetMonitorActionGroup
	virtual void beforeRemove(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup);
	
	///确认加入后触发
	///@param	pSysNetMonitorActionGroup	已经加入的SysNetMonitorActionGroup
	virtual void commitAdd(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup);

	///确认更新后触发
	///@param	pSysNetMonitorActionGroup	被刷新的CSysNetMonitorActionGroup
	///@param	poldSysNetMonitorActionGroup	原来的值
	virtual void commitUpdate(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup, CWriteableSysNetMonitorActionGroup *pOldSysNetMonitorActionGroup);
	
	///确认删除后触发
	///@param	pSysNetMonitorActionGroup	已经删除的CSysNetMonitorActionGroup
	virtual void commitRemove(CWriteableSysNetMonitorActionGroup *pSysNetMonitorActionGroup);

	///所有相关的触发器
	vector<CSysNetMonitorActionGroupActionTrigger *> *pActionTriggers;
	vector<CSysNetMonitorActionGroupCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetMonitorActionGroup compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceGroupFactory是一个设备对象组表的对象工厂。它包含了一批设备对象组表，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对设备对象组表的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceGroupFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetMonitorDeviceGroupFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetMonitorDeviceGroup，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetMonitorDeviceGroupFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorDeviceGroupFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetMonitorDeviceGroup
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetMonitorDeviceGroup，文件名将根据配置文件中的定义SysNetMonitorDeviceGroupCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetMonitorDeviceGroup
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetMonitorDeviceGroup，文件名将根据配置文件中的定义SysNetMonitorDeviceGroupCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetMonitorDeviceGroupResource;

	///将一个CSysNetMonitorDeviceGroup加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetMonitorDeviceGroup	要加入的SysNetMonitorDeviceGroup
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetMonitorDeviceGroup *add(CWriteableSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetMonitorDeviceGroup的值
	///@param	pSysNetMonitorDeviceGroup	被刷新的CSysNetMonitorDeviceGroup
	///@param	pNewSysNetMonitorDeviceGroup	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup, CWriteableSysNetMonitorDeviceGroup *pNewSysNetMonitorDeviceGroup, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetMonitorDeviceGroup	  需要被刷新或者新增的CSysNetMonitorDeviceGroup,等于NULL表示是需要新增的
	///@param	pNewSysNetMonitorDeviceGroup	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetMonitorDeviceGroup* addOrUpdate(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup, CWriteableSysNetMonitorDeviceGroup *pNewSysNetMonitorDeviceGroup, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetMonitorDeviceGroup，同时删除其索引
	///@param	pSysNetMonitorDeviceGroup	要删除的CSysNetMonitorDeviceGroup
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetMonitorDeviceGroup
	///@param	pSysNetMonitorDeviceGroup	要读取的CSysNetMonitorDeviceGroup
	///@param	pTragetSysNetMonitorDeviceGroup	存放结果的CSysNetMonitorDeviceGroup
	void retrieve(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup, CWriteableSysNetMonitorDeviceGroup *pTargetSysNetMonitorDeviceGroup);
	
	///获取第一个CSysNetMonitorDeviceGroup
	///@return	得到的第一个CSysNetMonitorDeviceGroup，如果没有，则返回NULL
	CSysNetMonitorDeviceGroup *getFirst(void);
	
	///获取下一个CSysNetMonitorDeviceGroup
	///@return	得到下一个CSysNetMonitorDeviceGroup，如果没有，则返回NULL
	CSysNetMonitorDeviceGroup *getNext(void);
	
	///结束获取CSysNetMonitorDeviceGroup
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetMonitorDeviceGroupActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetMonitorDeviceGroupActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetMonitorDeviceGroupCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetMonitorDeviceGroupCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetMonitorDeviceGroupIteratorByAll;

	///开始寻找CSysNetMonitorDeviceGroup
	///@return	满足条件的地一个CSysNetMonitorDeviceGroup，如果找不到，返回NULL
	CSysNetMonitorDeviceGroup *startFindByAll();

	///寻找下一个符合条件的CSysNetMonitorDeviceGroup，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetMonitorDeviceGroup，如果已经没有一个满足要求了，则返回NULL
	CSysNetMonitorDeviceGroup *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetMonitorDeviceGroup
	///@param	ID	
	///@return	找到的CSysNetMonitorDeviceGroup，如果找不到，返回NULL
	CSysNetMonitorDeviceGroup *findByOne( const CReadOnlyVolumeType&  ID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetMonitorDeviceGroup加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetMonitorDeviceGroup	要加入的SysNetMonitorDeviceGroup
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetMonitorDeviceGroup *internalAdd(CWriteableSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup, bool bNoTransaction);
	
	
	///刷新该CSysNetMonitorDeviceGroup的键值
	///@param	pSysNetMonitorDeviceGroup	被刷新的CSysNetMonitorDeviceGroup
	///@param	pNewSysNetMonitorDeviceGroup	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup, CWriteableSysNetMonitorDeviceGroup *pNewSysNetMonitorDeviceGroup, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetMonitorDeviceGroup，同时删除其索引
	///@param	pSysNetMonitorDeviceGroup	要删除的CSysNetMonitorDeviceGroup
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup, bool bNoTransaction);
/*
	///检查某个CSysNetMonitorDeviceGroup是否属于本对象工厂
	///@param	pSysNetMonitorDeviceGroup	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetMonitorDeviceGroup	要加入的SysNetMonitorDeviceGroup
	virtual void beforeAdd(CWriteableSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup);
	
	///加入后触发
	///@param	pSysNetMonitorDeviceGroup	已经加入的SysNetMonitorDeviceGroup
	virtual void afterAdd(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup);

	///更新前触发	
	///@param	pSysNetMonitorDeviceGroup	被刷新的CSysNetMonitorDeviceGroup
	///@param	pNewSysNetMonitorDeviceGroup	新的值
	virtual void beforeUpdate(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup, CWriteableSysNetMonitorDeviceGroup *pNewSysNetMonitorDeviceGroup);
	
	///更新后触发
	///@param	pSysNetMonitorDeviceGroup	被刷新的CSysNetMonitorDeviceGroup
	virtual void afterUpdate(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup);
	
	///删除前触发
	///@param	pSysNetMonitorDeviceGroup	要删除的CSysNetMonitorDeviceGroup
	virtual void beforeRemove(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup);
	
	///确认加入后触发
	///@param	pSysNetMonitorDeviceGroup	已经加入的SysNetMonitorDeviceGroup
	virtual void commitAdd(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup);

	///确认更新后触发
	///@param	pSysNetMonitorDeviceGroup	被刷新的CSysNetMonitorDeviceGroup
	///@param	poldSysNetMonitorDeviceGroup	原来的值
	virtual void commitUpdate(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup, CWriteableSysNetMonitorDeviceGroup *pOldSysNetMonitorDeviceGroup);
	
	///确认删除后触发
	///@param	pSysNetMonitorDeviceGroup	已经删除的CSysNetMonitorDeviceGroup
	virtual void commitRemove(CWriteableSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup);

	///所有相关的触发器
	vector<CSysNetMonitorDeviceGroupActionTrigger *> *pActionTriggers;
	vector<CSysNetMonitorDeviceGroupCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetMonitorDeviceGroup compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInfoFactory是一个任务信息表的对象工厂。它包含了一批任务信息表，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对任务信息表的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInfoFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetMonitorTaskInfoFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetMonitorTaskInfo，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetMonitorTaskInfoFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorTaskInfoFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetMonitorTaskInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetMonitorTaskInfo，文件名将根据配置文件中的定义SysNetMonitorTaskInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetMonitorTaskInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetMonitorTaskInfo，文件名将根据配置文件中的定义SysNetMonitorTaskInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetMonitorTaskInfoResource;

	///将一个CSysNetMonitorTaskInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetMonitorTaskInfo	要加入的SysNetMonitorTaskInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetMonitorTaskInfo *add(CWriteableSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetMonitorTaskInfo的值
	///@param	pSysNetMonitorTaskInfo	被刷新的CSysNetMonitorTaskInfo
	///@param	pNewSysNetMonitorTaskInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo, CWriteableSysNetMonitorTaskInfo *pNewSysNetMonitorTaskInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetMonitorTaskInfo	  需要被刷新或者新增的CSysNetMonitorTaskInfo,等于NULL表示是需要新增的
	///@param	pNewSysNetMonitorTaskInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetMonitorTaskInfo* addOrUpdate(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo, CWriteableSysNetMonitorTaskInfo *pNewSysNetMonitorTaskInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetMonitorTaskInfo，同时删除其索引
	///@param	pSysNetMonitorTaskInfo	要删除的CSysNetMonitorTaskInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetMonitorTaskInfo
	///@param	pSysNetMonitorTaskInfo	要读取的CSysNetMonitorTaskInfo
	///@param	pTragetSysNetMonitorTaskInfo	存放结果的CSysNetMonitorTaskInfo
	void retrieve(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo, CWriteableSysNetMonitorTaskInfo *pTargetSysNetMonitorTaskInfo);
	
	///获取第一个CSysNetMonitorTaskInfo
	///@return	得到的第一个CSysNetMonitorTaskInfo，如果没有，则返回NULL
	CSysNetMonitorTaskInfo *getFirst(void);
	
	///获取下一个CSysNetMonitorTaskInfo
	///@return	得到下一个CSysNetMonitorTaskInfo，如果没有，则返回NULL
	CSysNetMonitorTaskInfo *getNext(void);
	
	///结束获取CSysNetMonitorTaskInfo
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetMonitorTaskInfoActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetMonitorTaskInfoActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetMonitorTaskInfoCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetMonitorTaskInfoCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetMonitorTaskInfoIteratorByAll;

	///开始寻找CSysNetMonitorTaskInfo
	///@return	满足条件的地一个CSysNetMonitorTaskInfo，如果找不到，返回NULL
	CSysNetMonitorTaskInfo *startFindByAll();

	///寻找下一个符合条件的CSysNetMonitorTaskInfo，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetMonitorTaskInfo，如果已经没有一个满足要求了，则返回NULL
	CSysNetMonitorTaskInfo *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetMonitorTaskInfo
	///@param	ID	
	///@return	找到的CSysNetMonitorTaskInfo，如果找不到，返回NULL
	CSysNetMonitorTaskInfo *findByOne( const CReadOnlyVolumeType&  ID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetMonitorTaskInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetMonitorTaskInfo	要加入的SysNetMonitorTaskInfo
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetMonitorTaskInfo *internalAdd(CWriteableSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo, bool bNoTransaction);
	
	
	///刷新该CSysNetMonitorTaskInfo的键值
	///@param	pSysNetMonitorTaskInfo	被刷新的CSysNetMonitorTaskInfo
	///@param	pNewSysNetMonitorTaskInfo	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo, CWriteableSysNetMonitorTaskInfo *pNewSysNetMonitorTaskInfo, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetMonitorTaskInfo，同时删除其索引
	///@param	pSysNetMonitorTaskInfo	要删除的CSysNetMonitorTaskInfo
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo, bool bNoTransaction);
/*
	///检查某个CSysNetMonitorTaskInfo是否属于本对象工厂
	///@param	pSysNetMonitorTaskInfo	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetMonitorTaskInfo	要加入的SysNetMonitorTaskInfo
	virtual void beforeAdd(CWriteableSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo);
	
	///加入后触发
	///@param	pSysNetMonitorTaskInfo	已经加入的SysNetMonitorTaskInfo
	virtual void afterAdd(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo);

	///更新前触发	
	///@param	pSysNetMonitorTaskInfo	被刷新的CSysNetMonitorTaskInfo
	///@param	pNewSysNetMonitorTaskInfo	新的值
	virtual void beforeUpdate(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo, CWriteableSysNetMonitorTaskInfo *pNewSysNetMonitorTaskInfo);
	
	///更新后触发
	///@param	pSysNetMonitorTaskInfo	被刷新的CSysNetMonitorTaskInfo
	virtual void afterUpdate(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo);
	
	///删除前触发
	///@param	pSysNetMonitorTaskInfo	要删除的CSysNetMonitorTaskInfo
	virtual void beforeRemove(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo);
	
	///确认加入后触发
	///@param	pSysNetMonitorTaskInfo	已经加入的SysNetMonitorTaskInfo
	virtual void commitAdd(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo);

	///确认更新后触发
	///@param	pSysNetMonitorTaskInfo	被刷新的CSysNetMonitorTaskInfo
	///@param	poldSysNetMonitorTaskInfo	原来的值
	virtual void commitUpdate(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo, CWriteableSysNetMonitorTaskInfo *pOldSysNetMonitorTaskInfo);
	
	///确认删除后触发
	///@param	pSysNetMonitorTaskInfo	已经删除的CSysNetMonitorTaskInfo
	virtual void commitRemove(CWriteableSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo);

	///所有相关的触发器
	vector<CSysNetMonitorTaskInfoActionTrigger *> *pActionTriggers;
	vector<CSysNetMonitorTaskInfoCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetMonitorTaskInfo compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskObjectSetFactory是一个任务对象集的对象工厂。它包含了一批任务对象集，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对任务对象集的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用startFindByDeviceGroup_ID，findNextByDeviceGroup_ID和endFindByDeviceGroup_ID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskObjectSetFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetMonitorTaskObjectSetFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetMonitorTaskObjectSet，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetMonitorTaskObjectSetFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorTaskObjectSetFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetMonitorTaskObjectSet
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetMonitorTaskObjectSet，文件名将根据配置文件中的定义SysNetMonitorTaskObjectSetCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetMonitorTaskObjectSet
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetMonitorTaskObjectSet，文件名将根据配置文件中的定义SysNetMonitorTaskObjectSetCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetMonitorTaskObjectSetResource;

	///将一个CSysNetMonitorTaskObjectSet加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetMonitorTaskObjectSet	要加入的SysNetMonitorTaskObjectSet
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetMonitorTaskObjectSet *add(CWriteableSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetMonitorTaskObjectSet的值
	///@param	pSysNetMonitorTaskObjectSet	被刷新的CSysNetMonitorTaskObjectSet
	///@param	pNewSysNetMonitorTaskObjectSet	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet, CWriteableSysNetMonitorTaskObjectSet *pNewSysNetMonitorTaskObjectSet, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetMonitorTaskObjectSet	  需要被刷新或者新增的CSysNetMonitorTaskObjectSet,等于NULL表示是需要新增的
	///@param	pNewSysNetMonitorTaskObjectSet	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetMonitorTaskObjectSet* addOrUpdate(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet, CWriteableSysNetMonitorTaskObjectSet *pNewSysNetMonitorTaskObjectSet, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetMonitorTaskObjectSet，同时删除其索引
	///@param	pSysNetMonitorTaskObjectSet	要删除的CSysNetMonitorTaskObjectSet
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetMonitorTaskObjectSet
	///@param	pSysNetMonitorTaskObjectSet	要读取的CSysNetMonitorTaskObjectSet
	///@param	pTragetSysNetMonitorTaskObjectSet	存放结果的CSysNetMonitorTaskObjectSet
	void retrieve(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet, CWriteableSysNetMonitorTaskObjectSet *pTargetSysNetMonitorTaskObjectSet);
	
	///获取第一个CSysNetMonitorTaskObjectSet
	///@return	得到的第一个CSysNetMonitorTaskObjectSet，如果没有，则返回NULL
	CSysNetMonitorTaskObjectSet *getFirst(void);
	
	///获取下一个CSysNetMonitorTaskObjectSet
	///@return	得到下一个CSysNetMonitorTaskObjectSet，如果没有，则返回NULL
	CSysNetMonitorTaskObjectSet *getNext(void);
	
	///结束获取CSysNetMonitorTaskObjectSet
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetMonitorTaskObjectSetActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetMonitorTaskObjectSetActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetMonitorTaskObjectSetCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetMonitorTaskObjectSetCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetMonitorTaskObjectSetIteratorByAll;

	///开始寻找CSysNetMonitorTaskObjectSet
	///@return	满足条件的地一个CSysNetMonitorTaskObjectSet，如果找不到，返回NULL
	CSysNetMonitorTaskObjectSet *startFindByAll();

	///寻找下一个符合条件的CSysNetMonitorTaskObjectSet，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetMonitorTaskObjectSet，如果已经没有一个满足要求了，则返回NULL
	CSysNetMonitorTaskObjectSet *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	friend class CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID;

	///开始寻找CSysNetMonitorTaskObjectSet
	///@param	DeviceGroup_ID	
	///@return	满足条件的地一个CSysNetMonitorTaskObjectSet，如果找不到，返回NULL
	CSysNetMonitorTaskObjectSet *startFindByDeviceGroup_ID( const CReadOnlyVolumeType& DeviceGroup_ID);

	///寻找下一个符合条件的CSysNetMonitorTaskObjectSet，必须在startFindByDeviceGroup_ID以后，endFindByDeviceGroup_ID之前叫用
	///@return	下一个满足条件CSysNetMonitorTaskObjectSet，如果已经没有一个满足要求了，则返回NULL
	CSysNetMonitorTaskObjectSet *findNextByDeviceGroup_ID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDeviceGroup_ID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetMonitorTaskObjectSet加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetMonitorTaskObjectSet	要加入的SysNetMonitorTaskObjectSet
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetMonitorTaskObjectSet *internalAdd(CWriteableSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet, bool bNoTransaction);
	
	
	///刷新该CSysNetMonitorTaskObjectSet的键值
	///@param	pSysNetMonitorTaskObjectSet	被刷新的CSysNetMonitorTaskObjectSet
	///@param	pNewSysNetMonitorTaskObjectSet	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet, CWriteableSysNetMonitorTaskObjectSet *pNewSysNetMonitorTaskObjectSet, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetMonitorTaskObjectSet，同时删除其索引
	///@param	pSysNetMonitorTaskObjectSet	要删除的CSysNetMonitorTaskObjectSet
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet, bool bNoTransaction);
/*
	///检查某个CSysNetMonitorTaskObjectSet是否属于本对象工厂
	///@param	pSysNetMonitorTaskObjectSet	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于DeviceGroup_ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	///按照DeviceGroup_ID检索时，存储的查询参数
	CVolumeType queryDeviceGroup_IDInSearchByDeviceGroup_ID;
	
	///按照DeviceGroup_ID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDeviceGroup_ID;
	
	///加入前触发
	///@param	pSysNetMonitorTaskObjectSet	要加入的SysNetMonitorTaskObjectSet
	virtual void beforeAdd(CWriteableSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet);
	
	///加入后触发
	///@param	pSysNetMonitorTaskObjectSet	已经加入的SysNetMonitorTaskObjectSet
	virtual void afterAdd(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet);

	///更新前触发	
	///@param	pSysNetMonitorTaskObjectSet	被刷新的CSysNetMonitorTaskObjectSet
	///@param	pNewSysNetMonitorTaskObjectSet	新的值
	virtual void beforeUpdate(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet, CWriteableSysNetMonitorTaskObjectSet *pNewSysNetMonitorTaskObjectSet);
	
	///更新后触发
	///@param	pSysNetMonitorTaskObjectSet	被刷新的CSysNetMonitorTaskObjectSet
	virtual void afterUpdate(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet);
	
	///删除前触发
	///@param	pSysNetMonitorTaskObjectSet	要删除的CSysNetMonitorTaskObjectSet
	virtual void beforeRemove(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet);
	
	///确认加入后触发
	///@param	pSysNetMonitorTaskObjectSet	已经加入的SysNetMonitorTaskObjectSet
	virtual void commitAdd(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet);

	///确认更新后触发
	///@param	pSysNetMonitorTaskObjectSet	被刷新的CSysNetMonitorTaskObjectSet
	///@param	poldSysNetMonitorTaskObjectSet	原来的值
	virtual void commitUpdate(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet, CWriteableSysNetMonitorTaskObjectSet *pOldSysNetMonitorTaskObjectSet);
	
	///确认删除后触发
	///@param	pSysNetMonitorTaskObjectSet	已经删除的CSysNetMonitorTaskObjectSet
	virtual void commitRemove(CWriteableSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet);

	///所有相关的触发器
	vector<CSysNetMonitorTaskObjectSetActionTrigger *> *pActionTriggers;
	vector<CSysNetMonitorTaskObjectSetCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetMonitorTaskObjectSet compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultFactory是一个任务结果表的对象工厂。它包含了一批任务结果表，
///同时又建立了如下索引，以方便查询：
///	SysTaskIndex
///使用本对象工厂，可以完成对任务结果表的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用startFindByTask_ID，findNextByTask_ID和endFindByTask_ID完成查询操作
///		使用startFindByOnlyDate，findNextByOnlyDate和endFindByOnlyDate完成查询操作
///		使用startFindByIDTaskTime，findNextByIDTaskTime和endFindByIDTaskTime完成查询操作
///		使用startFindByDataDelete，findNextByDataDelete和endFindByDataDelete完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetMonitorTaskResultFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetMonitorTaskResult，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetMonitorTaskResultFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorTaskResultFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetMonitorTaskResult
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetMonitorTaskResult，文件名将根据配置文件中的定义SysNetMonitorTaskResultCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetMonitorTaskResult
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetMonitorTaskResult，文件名将根据配置文件中的定义SysNetMonitorTaskResultCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetMonitorTaskResultResource;

	///将一个CSysNetMonitorTaskResult加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetMonitorTaskResult	要加入的SysNetMonitorTaskResult
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetMonitorTaskResult *add(CWriteableSysNetMonitorTaskResult *pSysNetMonitorTaskResult, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetMonitorTaskResult的值
	///@param	pSysNetMonitorTaskResult	被刷新的CSysNetMonitorTaskResult
	///@param	pNewSysNetMonitorTaskResult	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult, CWriteableSysNetMonitorTaskResult *pNewSysNetMonitorTaskResult, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetMonitorTaskResult	  需要被刷新或者新增的CSysNetMonitorTaskResult,等于NULL表示是需要新增的
	///@param	pNewSysNetMonitorTaskResult	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetMonitorTaskResult* addOrUpdate(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult, CWriteableSysNetMonitorTaskResult *pNewSysNetMonitorTaskResult, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetMonitorTaskResult，同时删除其索引
	///@param	pSysNetMonitorTaskResult	要删除的CSysNetMonitorTaskResult
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetMonitorTaskResult
	///@param	pSysNetMonitorTaskResult	要读取的CSysNetMonitorTaskResult
	///@param	pTragetSysNetMonitorTaskResult	存放结果的CSysNetMonitorTaskResult
	void retrieve(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult, CWriteableSysNetMonitorTaskResult *pTargetSysNetMonitorTaskResult);
	
	///获取第一个CSysNetMonitorTaskResult
	///@return	得到的第一个CSysNetMonitorTaskResult，如果没有，则返回NULL
	CSysNetMonitorTaskResult *getFirst(void);
	
	///获取下一个CSysNetMonitorTaskResult
	///@return	得到下一个CSysNetMonitorTaskResult，如果没有，则返回NULL
	CSysNetMonitorTaskResult *getNext(void);
	
	///结束获取CSysNetMonitorTaskResult
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetMonitorTaskResultActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetMonitorTaskResultActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetMonitorTaskResultCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetMonitorTaskResultCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetMonitorTaskResultIteratorByAll;

	///开始寻找CSysNetMonitorTaskResult
	///@return	满足条件的地一个CSysNetMonitorTaskResult，如果找不到，返回NULL
	CSysNetMonitorTaskResult *startFindByAll();

	///寻找下一个符合条件的CSysNetMonitorTaskResult，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetMonitorTaskResult，如果已经没有一个满足要求了，则返回NULL
	CSysNetMonitorTaskResult *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	friend class CSysNetMonitorTaskResultIteratorByTask_ID;

	///开始寻找CSysNetMonitorTaskResult
	///@param	MonDate	
	///@param	Task_ID	
	///@return	满足条件的地一个CSysNetMonitorTaskResult，如果找不到，返回NULL
	CSysNetMonitorTaskResult *startFindByTask_ID( const CReadOnlyDateType& MonDate,  const CReadOnlyVolumeType& Task_ID);

	///寻找下一个符合条件的CSysNetMonitorTaskResult，必须在startFindByTask_ID以后，endFindByTask_ID之前叫用
	///@return	下一个满足条件CSysNetMonitorTaskResult，如果已经没有一个满足要求了，则返回NULL
	CSysNetMonitorTaskResult *findNextByTask_ID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByTask_ID(void);

	friend class CSysNetMonitorTaskResultIteratorByOnlyDate;

	///开始寻找CSysNetMonitorTaskResult
	///@param	MonDate	
	///@return	满足条件的地一个CSysNetMonitorTaskResult，如果找不到，返回NULL
	CSysNetMonitorTaskResult *startFindByOnlyDate( const CReadOnlyDateType& MonDate);

	///寻找下一个符合条件的CSysNetMonitorTaskResult，必须在startFindByOnlyDate以后，endFindByOnlyDate之前叫用
	///@return	下一个满足条件CSysNetMonitorTaskResult，如果已经没有一个满足要求了，则返回NULL
	CSysNetMonitorTaskResult *findNextByOnlyDate(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByOnlyDate(void);

	friend class CSysNetMonitorTaskResultIteratorByIDTaskTime;

	///开始寻找CSysNetMonitorTaskResult
	///@param	MonDate	
	///@param	Task_ID	
	///@param	ObjectID	
	///@param	OperateTime	
	///@return	满足条件的地一个CSysNetMonitorTaskResult，如果找不到，返回NULL
	CSysNetMonitorTaskResult *startFindByIDTaskTime( const CReadOnlyDateType& MonDate,  const CReadOnlyVolumeType& Task_ID,  const CReadOnlyNetObjectIDType& ObjectID,  const CReadOnlyVolumeType& OperateTime);

	///寻找下一个符合条件的CSysNetMonitorTaskResult，必须在startFindByIDTaskTime以后，endFindByIDTaskTime之前叫用
	///@return	下一个满足条件CSysNetMonitorTaskResult，如果已经没有一个满足要求了，则返回NULL
	CSysNetMonitorTaskResult *findNextByIDTaskTime(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByIDTaskTime(void);

	friend class CSysNetMonitorTaskResultIteratorByDataDelete;

	///开始寻找CSysNetMonitorTaskResult
	///@param	MonDate	
	///@param	Task_ID	
	///@param	ObjectID	
	///@return	满足条件的地一个CSysNetMonitorTaskResult，如果找不到，返回NULL
	CSysNetMonitorTaskResult *startFindByDataDelete( const CReadOnlyDateType& MonDate,  const CReadOnlyVolumeType& Task_ID,  const CReadOnlyNetObjectIDType& ObjectID);

	///寻找下一个符合条件的CSysNetMonitorTaskResult，必须在startFindByDataDelete以后，endFindByDataDelete之前叫用
	///@return	下一个满足条件CSysNetMonitorTaskResult，如果已经没有一个满足要求了，则返回NULL
	CSysNetMonitorTaskResult *findNextByDataDelete(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDataDelete(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetMonitorTaskResult加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetMonitorTaskResult	要加入的SysNetMonitorTaskResult
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetMonitorTaskResult *internalAdd(CWriteableSysNetMonitorTaskResult *pSysNetMonitorTaskResult, bool bNoTransaction);
	
	
	///刷新该CSysNetMonitorTaskResult的键值
	///@param	pSysNetMonitorTaskResult	被刷新的CSysNetMonitorTaskResult
	///@param	pNewSysNetMonitorTaskResult	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult, CWriteableSysNetMonitorTaskResult *pNewSysNetMonitorTaskResult, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetMonitorTaskResult，同时删除其索引
	///@param	pSysNetMonitorTaskResult	要删除的CSysNetMonitorTaskResult
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult, bool bNoTransaction);
/*
	///检查某个CSysNetMonitorTaskResult是否属于本对象工厂
	///@param	pSysNetMonitorTaskResult	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于MonDate+Task_ID+ObjectID+OperateTime的索引
	CAVLTree *pSysTaskIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	///按照MonDate，Task_ID检索时，存储的查询参数
	CDateType queryMonDateInSearchByTask_ID;
	CVolumeType queryTask_IDInSearchByTask_ID;
	
	///按照MonDate，Task_ID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByTask_ID;
	///按照MonDate检索时，存储的查询参数
	CDateType queryMonDateInSearchByOnlyDate;
	
	///按照MonDate检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByOnlyDate;
	///按照MonDate，Task_ID，ObjectID，OperateTime检索时，存储的查询参数
	CDateType queryMonDateInSearchByIDTaskTime;
	CVolumeType queryTask_IDInSearchByIDTaskTime;
	CNetObjectIDType queryObjectIDInSearchByIDTaskTime;
	CVolumeType queryOperateTimeInSearchByIDTaskTime;
	
	///按照MonDate，Task_ID，ObjectID，OperateTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByIDTaskTime;
	///按照MonDate，Task_ID，ObjectID检索时，存储的查询参数
	CDateType queryMonDateInSearchByDataDelete;
	CVolumeType queryTask_IDInSearchByDataDelete;
	CNetObjectIDType queryObjectIDInSearchByDataDelete;
	
	///按照MonDate，Task_ID，ObjectID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDataDelete;
	
	///加入前触发
	///@param	pSysNetMonitorTaskResult	要加入的SysNetMonitorTaskResult
	virtual void beforeAdd(CWriteableSysNetMonitorTaskResult *pSysNetMonitorTaskResult);
	
	///加入后触发
	///@param	pSysNetMonitorTaskResult	已经加入的SysNetMonitorTaskResult
	virtual void afterAdd(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult);

	///更新前触发	
	///@param	pSysNetMonitorTaskResult	被刷新的CSysNetMonitorTaskResult
	///@param	pNewSysNetMonitorTaskResult	新的值
	virtual void beforeUpdate(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult, CWriteableSysNetMonitorTaskResult *pNewSysNetMonitorTaskResult);
	
	///更新后触发
	///@param	pSysNetMonitorTaskResult	被刷新的CSysNetMonitorTaskResult
	virtual void afterUpdate(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult);
	
	///删除前触发
	///@param	pSysNetMonitorTaskResult	要删除的CSysNetMonitorTaskResult
	virtual void beforeRemove(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult);
	
	///确认加入后触发
	///@param	pSysNetMonitorTaskResult	已经加入的SysNetMonitorTaskResult
	virtual void commitAdd(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult);

	///确认更新后触发
	///@param	pSysNetMonitorTaskResult	被刷新的CSysNetMonitorTaskResult
	///@param	poldSysNetMonitorTaskResult	原来的值
	virtual void commitUpdate(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult, CWriteableSysNetMonitorTaskResult *pOldSysNetMonitorTaskResult);
	
	///确认删除后触发
	///@param	pSysNetMonitorTaskResult	已经删除的CSysNetMonitorTaskResult
	virtual void commitRemove(CWriteableSysNetMonitorTaskResult *pSysNetMonitorTaskResult);

	///所有相关的触发器
	vector<CSysNetMonitorTaskResultActionTrigger *> *pActionTriggers;
	vector<CSysNetMonitorTaskResultCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetMonitorTaskResult compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkInfoFactory是一个会员链路信息表的对象工厂。它包含了一批会员链路信息表，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对会员链路信息表的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkInfoFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetPartyLinkInfoFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetPartyLinkInfo，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetPartyLinkInfoFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetPartyLinkInfoFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetPartyLinkInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetPartyLinkInfo，文件名将根据配置文件中的定义SysNetPartyLinkInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetPartyLinkInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetPartyLinkInfo，文件名将根据配置文件中的定义SysNetPartyLinkInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetPartyLinkInfoResource;

	///将一个CSysNetPartyLinkInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetPartyLinkInfo	要加入的SysNetPartyLinkInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetPartyLinkInfo *add(CWriteableSysNetPartyLinkInfo *pSysNetPartyLinkInfo, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetPartyLinkInfo的值
	///@param	pSysNetPartyLinkInfo	被刷新的CSysNetPartyLinkInfo
	///@param	pNewSysNetPartyLinkInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo, CWriteableSysNetPartyLinkInfo *pNewSysNetPartyLinkInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetPartyLinkInfo	  需要被刷新或者新增的CSysNetPartyLinkInfo,等于NULL表示是需要新增的
	///@param	pNewSysNetPartyLinkInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetPartyLinkInfo* addOrUpdate(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo, CWriteableSysNetPartyLinkInfo *pNewSysNetPartyLinkInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetPartyLinkInfo，同时删除其索引
	///@param	pSysNetPartyLinkInfo	要删除的CSysNetPartyLinkInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetPartyLinkInfo
	///@param	pSysNetPartyLinkInfo	要读取的CSysNetPartyLinkInfo
	///@param	pTragetSysNetPartyLinkInfo	存放结果的CSysNetPartyLinkInfo
	void retrieve(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo, CWriteableSysNetPartyLinkInfo *pTargetSysNetPartyLinkInfo);
	
	///获取第一个CSysNetPartyLinkInfo
	///@return	得到的第一个CSysNetPartyLinkInfo，如果没有，则返回NULL
	CSysNetPartyLinkInfo *getFirst(void);
	
	///获取下一个CSysNetPartyLinkInfo
	///@return	得到下一个CSysNetPartyLinkInfo，如果没有，则返回NULL
	CSysNetPartyLinkInfo *getNext(void);
	
	///结束获取CSysNetPartyLinkInfo
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetPartyLinkInfoActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetPartyLinkInfoActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetPartyLinkInfoCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetPartyLinkInfoCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetPartyLinkInfoIteratorByAll;

	///开始寻找CSysNetPartyLinkInfo
	///@return	满足条件的地一个CSysNetPartyLinkInfo，如果找不到，返回NULL
	CSysNetPartyLinkInfo *startFindByAll();

	///寻找下一个符合条件的CSysNetPartyLinkInfo，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetPartyLinkInfo，如果已经没有一个满足要求了，则返回NULL
	CSysNetPartyLinkInfo *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetPartyLinkInfo
	///@param	ID	
	///@return	找到的CSysNetPartyLinkInfo，如果找不到，返回NULL
	CSysNetPartyLinkInfo *findByOne( const CReadOnlyVolumeType&  ID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetPartyLinkInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetPartyLinkInfo	要加入的SysNetPartyLinkInfo
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetPartyLinkInfo *internalAdd(CWriteableSysNetPartyLinkInfo *pSysNetPartyLinkInfo, bool bNoTransaction);
	
	
	///刷新该CSysNetPartyLinkInfo的键值
	///@param	pSysNetPartyLinkInfo	被刷新的CSysNetPartyLinkInfo
	///@param	pNewSysNetPartyLinkInfo	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo, CWriteableSysNetPartyLinkInfo *pNewSysNetPartyLinkInfo, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetPartyLinkInfo，同时删除其索引
	///@param	pSysNetPartyLinkInfo	要删除的CSysNetPartyLinkInfo
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo, bool bNoTransaction);
/*
	///检查某个CSysNetPartyLinkInfo是否属于本对象工厂
	///@param	pSysNetPartyLinkInfo	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetPartyLinkInfo	要加入的SysNetPartyLinkInfo
	virtual void beforeAdd(CWriteableSysNetPartyLinkInfo *pSysNetPartyLinkInfo);
	
	///加入后触发
	///@param	pSysNetPartyLinkInfo	已经加入的SysNetPartyLinkInfo
	virtual void afterAdd(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo);

	///更新前触发	
	///@param	pSysNetPartyLinkInfo	被刷新的CSysNetPartyLinkInfo
	///@param	pNewSysNetPartyLinkInfo	新的值
	virtual void beforeUpdate(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo, CWriteableSysNetPartyLinkInfo *pNewSysNetPartyLinkInfo);
	
	///更新后触发
	///@param	pSysNetPartyLinkInfo	被刷新的CSysNetPartyLinkInfo
	virtual void afterUpdate(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo);
	
	///删除前触发
	///@param	pSysNetPartyLinkInfo	要删除的CSysNetPartyLinkInfo
	virtual void beforeRemove(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo);
	
	///确认加入后触发
	///@param	pSysNetPartyLinkInfo	已经加入的SysNetPartyLinkInfo
	virtual void commitAdd(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo);

	///确认更新后触发
	///@param	pSysNetPartyLinkInfo	被刷新的CSysNetPartyLinkInfo
	///@param	poldSysNetPartyLinkInfo	原来的值
	virtual void commitUpdate(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo, CWriteableSysNetPartyLinkInfo *pOldSysNetPartyLinkInfo);
	
	///确认删除后触发
	///@param	pSysNetPartyLinkInfo	已经删除的CSysNetPartyLinkInfo
	virtual void commitRemove(CWriteableSysNetPartyLinkInfo *pSysNetPartyLinkInfo);

	///所有相关的触发器
	vector<CSysNetPartyLinkInfoActionTrigger *> *pActionTriggers;
	vector<CSysNetPartyLinkInfoCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetPartyLinkInfo compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDelPartyLinkInfoFactory是一个会员链路信息表的对象工厂。它包含了一批会员链路信息表，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对会员链路信息表的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDelPartyLinkInfoFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetDelPartyLinkInfoFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetDelPartyLinkInfo，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetDelPartyLinkInfoFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetDelPartyLinkInfoFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetDelPartyLinkInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetDelPartyLinkInfo，文件名将根据配置文件中的定义SysNetDelPartyLinkInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetDelPartyLinkInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetDelPartyLinkInfo，文件名将根据配置文件中的定义SysNetDelPartyLinkInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetDelPartyLinkInfoResource;

	///将一个CSysNetDelPartyLinkInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetDelPartyLinkInfo	要加入的SysNetDelPartyLinkInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetDelPartyLinkInfo *add(CWriteableSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetDelPartyLinkInfo的值
	///@param	pSysNetDelPartyLinkInfo	被刷新的CSysNetDelPartyLinkInfo
	///@param	pNewSysNetDelPartyLinkInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo, CWriteableSysNetDelPartyLinkInfo *pNewSysNetDelPartyLinkInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetDelPartyLinkInfo	  需要被刷新或者新增的CSysNetDelPartyLinkInfo,等于NULL表示是需要新增的
	///@param	pNewSysNetDelPartyLinkInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetDelPartyLinkInfo* addOrUpdate(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo, CWriteableSysNetDelPartyLinkInfo *pNewSysNetDelPartyLinkInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetDelPartyLinkInfo，同时删除其索引
	///@param	pSysNetDelPartyLinkInfo	要删除的CSysNetDelPartyLinkInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetDelPartyLinkInfo
	///@param	pSysNetDelPartyLinkInfo	要读取的CSysNetDelPartyLinkInfo
	///@param	pTragetSysNetDelPartyLinkInfo	存放结果的CSysNetDelPartyLinkInfo
	void retrieve(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo, CWriteableSysNetDelPartyLinkInfo *pTargetSysNetDelPartyLinkInfo);
	
	///获取第一个CSysNetDelPartyLinkInfo
	///@return	得到的第一个CSysNetDelPartyLinkInfo，如果没有，则返回NULL
	CSysNetDelPartyLinkInfo *getFirst(void);
	
	///获取下一个CSysNetDelPartyLinkInfo
	///@return	得到下一个CSysNetDelPartyLinkInfo，如果没有，则返回NULL
	CSysNetDelPartyLinkInfo *getNext(void);
	
	///结束获取CSysNetDelPartyLinkInfo
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetDelPartyLinkInfoActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetDelPartyLinkInfoActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetDelPartyLinkInfoCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetDelPartyLinkInfoCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetDelPartyLinkInfoIteratorByAll;

	///开始寻找CSysNetDelPartyLinkInfo
	///@return	满足条件的地一个CSysNetDelPartyLinkInfo，如果找不到，返回NULL
	CSysNetDelPartyLinkInfo *startFindByAll();

	///寻找下一个符合条件的CSysNetDelPartyLinkInfo，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetDelPartyLinkInfo，如果已经没有一个满足要求了，则返回NULL
	CSysNetDelPartyLinkInfo *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetDelPartyLinkInfo
	///@param	ID	
	///@return	找到的CSysNetDelPartyLinkInfo，如果找不到，返回NULL
	CSysNetDelPartyLinkInfo *findByOne( const CReadOnlyVolumeType&  ID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetDelPartyLinkInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetDelPartyLinkInfo	要加入的SysNetDelPartyLinkInfo
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetDelPartyLinkInfo *internalAdd(CWriteableSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo, bool bNoTransaction);
	
	
	///刷新该CSysNetDelPartyLinkInfo的键值
	///@param	pSysNetDelPartyLinkInfo	被刷新的CSysNetDelPartyLinkInfo
	///@param	pNewSysNetDelPartyLinkInfo	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo, CWriteableSysNetDelPartyLinkInfo *pNewSysNetDelPartyLinkInfo, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetDelPartyLinkInfo，同时删除其索引
	///@param	pSysNetDelPartyLinkInfo	要删除的CSysNetDelPartyLinkInfo
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo, bool bNoTransaction);
/*
	///检查某个CSysNetDelPartyLinkInfo是否属于本对象工厂
	///@param	pSysNetDelPartyLinkInfo	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetDelPartyLinkInfo	要加入的SysNetDelPartyLinkInfo
	virtual void beforeAdd(CWriteableSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo);
	
	///加入后触发
	///@param	pSysNetDelPartyLinkInfo	已经加入的SysNetDelPartyLinkInfo
	virtual void afterAdd(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo);

	///更新前触发	
	///@param	pSysNetDelPartyLinkInfo	被刷新的CSysNetDelPartyLinkInfo
	///@param	pNewSysNetDelPartyLinkInfo	新的值
	virtual void beforeUpdate(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo, CWriteableSysNetDelPartyLinkInfo *pNewSysNetDelPartyLinkInfo);
	
	///更新后触发
	///@param	pSysNetDelPartyLinkInfo	被刷新的CSysNetDelPartyLinkInfo
	virtual void afterUpdate(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo);
	
	///删除前触发
	///@param	pSysNetDelPartyLinkInfo	要删除的CSysNetDelPartyLinkInfo
	virtual void beforeRemove(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo);
	
	///确认加入后触发
	///@param	pSysNetDelPartyLinkInfo	已经加入的SysNetDelPartyLinkInfo
	virtual void commitAdd(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo);

	///确认更新后触发
	///@param	pSysNetDelPartyLinkInfo	被刷新的CSysNetDelPartyLinkInfo
	///@param	poldSysNetDelPartyLinkInfo	原来的值
	virtual void commitUpdate(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo, CWriteableSysNetDelPartyLinkInfo *pOldSysNetDelPartyLinkInfo);
	
	///确认删除后触发
	///@param	pSysNetDelPartyLinkInfo	已经删除的CSysNetDelPartyLinkInfo
	virtual void commitRemove(CWriteableSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo);

	///所有相关的触发器
	vector<CSysNetDelPartyLinkInfoActionTrigger *> *pActionTriggers;
	vector<CSysNetDelPartyLinkInfoCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetDelPartyLinkInfo compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkAddrChangeFactory是一个会员链路信息表的对象工厂。它包含了一批会员链路信息表，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对会员链路信息表的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkAddrChangeFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetPartyLinkAddrChangeFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetPartyLinkAddrChange，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetPartyLinkAddrChangeFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetPartyLinkAddrChangeFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetPartyLinkAddrChange
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetPartyLinkAddrChange，文件名将根据配置文件中的定义SysNetPartyLinkAddrChangeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetPartyLinkAddrChange
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetPartyLinkAddrChange，文件名将根据配置文件中的定义SysNetPartyLinkAddrChangeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetPartyLinkAddrChangeResource;

	///将一个CSysNetPartyLinkAddrChange加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetPartyLinkAddrChange	要加入的SysNetPartyLinkAddrChange
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetPartyLinkAddrChange *add(CWriteableSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetPartyLinkAddrChange的值
	///@param	pSysNetPartyLinkAddrChange	被刷新的CSysNetPartyLinkAddrChange
	///@param	pNewSysNetPartyLinkAddrChange	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange, CWriteableSysNetPartyLinkAddrChange *pNewSysNetPartyLinkAddrChange, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetPartyLinkAddrChange	  需要被刷新或者新增的CSysNetPartyLinkAddrChange,等于NULL表示是需要新增的
	///@param	pNewSysNetPartyLinkAddrChange	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetPartyLinkAddrChange* addOrUpdate(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange, CWriteableSysNetPartyLinkAddrChange *pNewSysNetPartyLinkAddrChange, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetPartyLinkAddrChange，同时删除其索引
	///@param	pSysNetPartyLinkAddrChange	要删除的CSysNetPartyLinkAddrChange
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetPartyLinkAddrChange
	///@param	pSysNetPartyLinkAddrChange	要读取的CSysNetPartyLinkAddrChange
	///@param	pTragetSysNetPartyLinkAddrChange	存放结果的CSysNetPartyLinkAddrChange
	void retrieve(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange, CWriteableSysNetPartyLinkAddrChange *pTargetSysNetPartyLinkAddrChange);
	
	///获取第一个CSysNetPartyLinkAddrChange
	///@return	得到的第一个CSysNetPartyLinkAddrChange，如果没有，则返回NULL
	CSysNetPartyLinkAddrChange *getFirst(void);
	
	///获取下一个CSysNetPartyLinkAddrChange
	///@return	得到下一个CSysNetPartyLinkAddrChange，如果没有，则返回NULL
	CSysNetPartyLinkAddrChange *getNext(void);
	
	///结束获取CSysNetPartyLinkAddrChange
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetPartyLinkAddrChangeActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetPartyLinkAddrChangeActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetPartyLinkAddrChangeCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetPartyLinkAddrChangeCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetPartyLinkAddrChangeIteratorByAll;

	///开始寻找CSysNetPartyLinkAddrChange
	///@return	满足条件的地一个CSysNetPartyLinkAddrChange，如果找不到，返回NULL
	CSysNetPartyLinkAddrChange *startFindByAll();

	///寻找下一个符合条件的CSysNetPartyLinkAddrChange，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetPartyLinkAddrChange，如果已经没有一个满足要求了，则返回NULL
	CSysNetPartyLinkAddrChange *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetPartyLinkAddrChange
	///@param	ID	
	///@return	找到的CSysNetPartyLinkAddrChange，如果找不到，返回NULL
	CSysNetPartyLinkAddrChange *findByOne( const CReadOnlyVolumeType&  ID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetPartyLinkAddrChange加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetPartyLinkAddrChange	要加入的SysNetPartyLinkAddrChange
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetPartyLinkAddrChange *internalAdd(CWriteableSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange, bool bNoTransaction);
	
	
	///刷新该CSysNetPartyLinkAddrChange的键值
	///@param	pSysNetPartyLinkAddrChange	被刷新的CSysNetPartyLinkAddrChange
	///@param	pNewSysNetPartyLinkAddrChange	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange, CWriteableSysNetPartyLinkAddrChange *pNewSysNetPartyLinkAddrChange, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetPartyLinkAddrChange，同时删除其索引
	///@param	pSysNetPartyLinkAddrChange	要删除的CSysNetPartyLinkAddrChange
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange, bool bNoTransaction);
/*
	///检查某个CSysNetPartyLinkAddrChange是否属于本对象工厂
	///@param	pSysNetPartyLinkAddrChange	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetPartyLinkAddrChange	要加入的SysNetPartyLinkAddrChange
	virtual void beforeAdd(CWriteableSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange);
	
	///加入后触发
	///@param	pSysNetPartyLinkAddrChange	已经加入的SysNetPartyLinkAddrChange
	virtual void afterAdd(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange);

	///更新前触发	
	///@param	pSysNetPartyLinkAddrChange	被刷新的CSysNetPartyLinkAddrChange
	///@param	pNewSysNetPartyLinkAddrChange	新的值
	virtual void beforeUpdate(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange, CWriteableSysNetPartyLinkAddrChange *pNewSysNetPartyLinkAddrChange);
	
	///更新后触发
	///@param	pSysNetPartyLinkAddrChange	被刷新的CSysNetPartyLinkAddrChange
	virtual void afterUpdate(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange);
	
	///删除前触发
	///@param	pSysNetPartyLinkAddrChange	要删除的CSysNetPartyLinkAddrChange
	virtual void beforeRemove(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange);
	
	///确认加入后触发
	///@param	pSysNetPartyLinkAddrChange	已经加入的SysNetPartyLinkAddrChange
	virtual void commitAdd(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange);

	///确认更新后触发
	///@param	pSysNetPartyLinkAddrChange	被刷新的CSysNetPartyLinkAddrChange
	///@param	poldSysNetPartyLinkAddrChange	原来的值
	virtual void commitUpdate(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange, CWriteableSysNetPartyLinkAddrChange *pOldSysNetPartyLinkAddrChange);
	
	///确认删除后触发
	///@param	pSysNetPartyLinkAddrChange	已经删除的CSysNetPartyLinkAddrChange
	virtual void commitRemove(CWriteableSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange);

	///所有相关的触发器
	vector<CSysNetPartyLinkAddrChangeActionTrigger *> *pActionTriggers;
	vector<CSysNetPartyLinkAddrChangeCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetPartyLinkAddrChange compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionAttrFactory是一个监控动作指标对照表的对象工厂。它包含了一批监控动作指标对照表，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对监控动作指标对照表的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionAttrFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetMonitorActionAttrFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetMonitorActionAttr，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetMonitorActionAttrFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorActionAttrFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetMonitorActionAttr
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetMonitorActionAttr，文件名将根据配置文件中的定义SysNetMonitorActionAttrCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetMonitorActionAttr
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetMonitorActionAttr，文件名将根据配置文件中的定义SysNetMonitorActionAttrCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetMonitorActionAttrResource;

	///将一个CSysNetMonitorActionAttr加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetMonitorActionAttr	要加入的SysNetMonitorActionAttr
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetMonitorActionAttr *add(CWriteableSysNetMonitorActionAttr *pSysNetMonitorActionAttr, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetMonitorActionAttr的值
	///@param	pSysNetMonitorActionAttr	被刷新的CSysNetMonitorActionAttr
	///@param	pNewSysNetMonitorActionAttr	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr, CWriteableSysNetMonitorActionAttr *pNewSysNetMonitorActionAttr, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetMonitorActionAttr	  需要被刷新或者新增的CSysNetMonitorActionAttr,等于NULL表示是需要新增的
	///@param	pNewSysNetMonitorActionAttr	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetMonitorActionAttr* addOrUpdate(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr, CWriteableSysNetMonitorActionAttr *pNewSysNetMonitorActionAttr, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetMonitorActionAttr，同时删除其索引
	///@param	pSysNetMonitorActionAttr	要删除的CSysNetMonitorActionAttr
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetMonitorActionAttr
	///@param	pSysNetMonitorActionAttr	要读取的CSysNetMonitorActionAttr
	///@param	pTragetSysNetMonitorActionAttr	存放结果的CSysNetMonitorActionAttr
	void retrieve(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr, CWriteableSysNetMonitorActionAttr *pTargetSysNetMonitorActionAttr);
	
	///获取第一个CSysNetMonitorActionAttr
	///@return	得到的第一个CSysNetMonitorActionAttr，如果没有，则返回NULL
	CSysNetMonitorActionAttr *getFirst(void);
	
	///获取下一个CSysNetMonitorActionAttr
	///@return	得到下一个CSysNetMonitorActionAttr，如果没有，则返回NULL
	CSysNetMonitorActionAttr *getNext(void);
	
	///结束获取CSysNetMonitorActionAttr
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetMonitorActionAttrActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetMonitorActionAttrActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetMonitorActionAttrCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetMonitorActionAttrCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetMonitorActionAttrIteratorByAll;

	///开始寻找CSysNetMonitorActionAttr
	///@return	满足条件的地一个CSysNetMonitorActionAttr，如果找不到，返回NULL
	CSysNetMonitorActionAttr *startFindByAll();

	///寻找下一个符合条件的CSysNetMonitorActionAttr，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetMonitorActionAttr，如果已经没有一个满足要求了，则返回NULL
	CSysNetMonitorActionAttr *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetMonitorActionAttr
	///@param	ID	
	///@return	找到的CSysNetMonitorActionAttr，如果找不到，返回NULL
	CSysNetMonitorActionAttr *findByOne( const CReadOnlyVolumeType&  ID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetMonitorActionAttr加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetMonitorActionAttr	要加入的SysNetMonitorActionAttr
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetMonitorActionAttr *internalAdd(CWriteableSysNetMonitorActionAttr *pSysNetMonitorActionAttr, bool bNoTransaction);
	
	
	///刷新该CSysNetMonitorActionAttr的键值
	///@param	pSysNetMonitorActionAttr	被刷新的CSysNetMonitorActionAttr
	///@param	pNewSysNetMonitorActionAttr	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr, CWriteableSysNetMonitorActionAttr *pNewSysNetMonitorActionAttr, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetMonitorActionAttr，同时删除其索引
	///@param	pSysNetMonitorActionAttr	要删除的CSysNetMonitorActionAttr
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr, bool bNoTransaction);
/*
	///检查某个CSysNetMonitorActionAttr是否属于本对象工厂
	///@param	pSysNetMonitorActionAttr	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetMonitorActionAttr	要加入的SysNetMonitorActionAttr
	virtual void beforeAdd(CWriteableSysNetMonitorActionAttr *pSysNetMonitorActionAttr);
	
	///加入后触发
	///@param	pSysNetMonitorActionAttr	已经加入的SysNetMonitorActionAttr
	virtual void afterAdd(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr);

	///更新前触发	
	///@param	pSysNetMonitorActionAttr	被刷新的CSysNetMonitorActionAttr
	///@param	pNewSysNetMonitorActionAttr	新的值
	virtual void beforeUpdate(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr, CWriteableSysNetMonitorActionAttr *pNewSysNetMonitorActionAttr);
	
	///更新后触发
	///@param	pSysNetMonitorActionAttr	被刷新的CSysNetMonitorActionAttr
	virtual void afterUpdate(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr);
	
	///删除前触发
	///@param	pSysNetMonitorActionAttr	要删除的CSysNetMonitorActionAttr
	virtual void beforeRemove(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr);
	
	///确认加入后触发
	///@param	pSysNetMonitorActionAttr	已经加入的SysNetMonitorActionAttr
	virtual void commitAdd(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr);

	///确认更新后触发
	///@param	pSysNetMonitorActionAttr	被刷新的CSysNetMonitorActionAttr
	///@param	poldSysNetMonitorActionAttr	原来的值
	virtual void commitUpdate(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr, CWriteableSysNetMonitorActionAttr *pOldSysNetMonitorActionAttr);
	
	///确认删除后触发
	///@param	pSysNetMonitorActionAttr	已经删除的CSysNetMonitorActionAttr
	virtual void commitRemove(CWriteableSysNetMonitorActionAttr *pSysNetMonitorActionAttr);

	///所有相关的触发器
	vector<CSysNetMonitorActionAttrActionTrigger *> *pActionTriggers;
	vector<CSysNetMonitorActionAttrCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetMonitorActionAttr compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetModuleFactory是一个模块的对象工厂。它包含了一批模块，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///	SysDeviceIDTypeIndex
///	SysObjectIDTypeIndex
///使用本对象工厂，可以完成对模块的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///		使用startFindByDeviceID，findNextByDeviceID和endFindByDeviceID完成查询操作
///		使用findByObjectID，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetModuleFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetModuleFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetModule，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetModuleFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetModuleFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetModule
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetModule，文件名将根据配置文件中的定义SysNetModuleCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetModule
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetModule，文件名将根据配置文件中的定义SysNetModuleCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetModuleResource;

	///将一个CSysNetModule加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetModule	要加入的SysNetModule
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetModule *add(CWriteableSysNetModule *pSysNetModule, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetModule的值
	///@param	pSysNetModule	被刷新的CSysNetModule
	///@param	pNewSysNetModule	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetModule *pSysNetModule, CWriteableSysNetModule *pNewSysNetModule, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetModule	  需要被刷新或者新增的CSysNetModule,等于NULL表示是需要新增的
	///@param	pNewSysNetModule	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetModule* addOrUpdate(CSysNetModule *pSysNetModule, CWriteableSysNetModule *pNewSysNetModule, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetModule，同时删除其索引
	///@param	pSysNetModule	要删除的CSysNetModule
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetModule *pSysNetModule, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetModule
	///@param	pSysNetModule	要读取的CSysNetModule
	///@param	pTragetSysNetModule	存放结果的CSysNetModule
	void retrieve(CSysNetModule *pSysNetModule, CWriteableSysNetModule *pTargetSysNetModule);
	
	///获取第一个CSysNetModule
	///@return	得到的第一个CSysNetModule，如果没有，则返回NULL
	CSysNetModule *getFirst(void);
	
	///获取下一个CSysNetModule
	///@return	得到下一个CSysNetModule，如果没有，则返回NULL
	CSysNetModule *getNext(void);
	
	///结束获取CSysNetModule
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetModuleActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetModuleActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetModuleCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetModuleCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetModuleIteratorByAll;

	///开始寻找CSysNetModule
	///@return	满足条件的地一个CSysNetModule，如果找不到，返回NULL
	CSysNetModule *startFindByAll();

	///寻找下一个符合条件的CSysNetModule，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetModule，如果已经没有一个满足要求了，则返回NULL
	CSysNetModule *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetModule
	///@param	ID	
	///@return	找到的CSysNetModule，如果找不到，返回NULL
	CSysNetModule *findByOne( const CReadOnlyVolumeType&  ID);



	friend class CSysNetModuleIteratorByDeviceID;

	///开始寻找CSysNetModule
	///@param	DeviceID	
	///@return	满足条件的地一个CSysNetModule，如果找不到，返回NULL
	CSysNetModule *startFindByDeviceID( const CReadOnlyVolumeType& DeviceID);

	///寻找下一个符合条件的CSysNetModule，必须在startFindByDeviceID以后，endFindByDeviceID之前叫用
	///@return	下一个满足条件CSysNetModule，如果已经没有一个满足要求了，则返回NULL
	CSysNetModule *findNextByDeviceID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDeviceID(void);

	///寻找CSysNetModule
	///@param	ObjectID	
	///@return	找到的CSysNetModule，如果找不到，返回NULL
	CSysNetModule *findByObjectID( const CReadOnlyNetObjectIDType&  ObjectID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetModule加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetModule	要加入的SysNetModule
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetModule *internalAdd(CWriteableSysNetModule *pSysNetModule, bool bNoTransaction);
	
	
	///刷新该CSysNetModule的键值
	///@param	pSysNetModule	被刷新的CSysNetModule
	///@param	pNewSysNetModule	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetModule *pSysNetModule, CWriteableSysNetModule *pNewSysNetModule, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetModule，同时删除其索引
	///@param	pSysNetModule	要删除的CSysNetModule
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetModule *pSysNetModule, bool bNoTransaction);
/*
	///检查某个CSysNetModule是否属于本对象工厂
	///@param	pSysNetModule	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetModule *pSysNetModule);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	///基于DeviceID的索引
	CAVLTree *pSysDeviceIDTypeIndex;
	///基于ObjectID的索引
	CAVLTree *pSysObjectIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	///按照DeviceID检索时，存储的查询参数
	CVolumeType queryDeviceIDInSearchByDeviceID;
	
	///按照DeviceID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDeviceID;
	
	///加入前触发
	///@param	pSysNetModule	要加入的SysNetModule
	virtual void beforeAdd(CWriteableSysNetModule *pSysNetModule);
	
	///加入后触发
	///@param	pSysNetModule	已经加入的SysNetModule
	virtual void afterAdd(CSysNetModule *pSysNetModule);

	///更新前触发	
	///@param	pSysNetModule	被刷新的CSysNetModule
	///@param	pNewSysNetModule	新的值
	virtual void beforeUpdate(CSysNetModule *pSysNetModule, CWriteableSysNetModule *pNewSysNetModule);
	
	///更新后触发
	///@param	pSysNetModule	被刷新的CSysNetModule
	virtual void afterUpdate(CSysNetModule *pSysNetModule);
	
	///删除前触发
	///@param	pSysNetModule	要删除的CSysNetModule
	virtual void beforeRemove(CSysNetModule *pSysNetModule);
	
	///确认加入后触发
	///@param	pSysNetModule	已经加入的SysNetModule
	virtual void commitAdd(CSysNetModule *pSysNetModule);

	///确认更新后触发
	///@param	pSysNetModule	被刷新的CSysNetModule
	///@param	poldSysNetModule	原来的值
	virtual void commitUpdate(CSysNetModule *pSysNetModule, CWriteableSysNetModule *pOldSysNetModule);
	
	///确认删除后触发
	///@param	pSysNetModule	已经删除的CSysNetModule
	virtual void commitRemove(CWriteableSysNetModule *pSysNetModule);

	///所有相关的触发器
	vector<CSysNetModuleActionTrigger *> *pActionTriggers;
	vector<CSysNetModuleCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetModule compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventExprFactory是一个告警表达式信息表的对象工厂。它包含了一批告警表达式信息表，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对告警表达式信息表的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventExprFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetEventExprFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetEventExpr，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetEventExprFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetEventExprFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetEventExpr
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetEventExpr，文件名将根据配置文件中的定义SysNetEventExprCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetEventExpr
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetEventExpr，文件名将根据配置文件中的定义SysNetEventExprCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetEventExprResource;

	///将一个CSysNetEventExpr加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetEventExpr	要加入的SysNetEventExpr
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetEventExpr *add(CWriteableSysNetEventExpr *pSysNetEventExpr, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetEventExpr的值
	///@param	pSysNetEventExpr	被刷新的CSysNetEventExpr
	///@param	pNewSysNetEventExpr	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetEventExpr *pSysNetEventExpr, CWriteableSysNetEventExpr *pNewSysNetEventExpr, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetEventExpr	  需要被刷新或者新增的CSysNetEventExpr,等于NULL表示是需要新增的
	///@param	pNewSysNetEventExpr	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetEventExpr* addOrUpdate(CSysNetEventExpr *pSysNetEventExpr, CWriteableSysNetEventExpr *pNewSysNetEventExpr, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetEventExpr，同时删除其索引
	///@param	pSysNetEventExpr	要删除的CSysNetEventExpr
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetEventExpr *pSysNetEventExpr, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetEventExpr
	///@param	pSysNetEventExpr	要读取的CSysNetEventExpr
	///@param	pTragetSysNetEventExpr	存放结果的CSysNetEventExpr
	void retrieve(CSysNetEventExpr *pSysNetEventExpr, CWriteableSysNetEventExpr *pTargetSysNetEventExpr);
	
	///获取第一个CSysNetEventExpr
	///@return	得到的第一个CSysNetEventExpr，如果没有，则返回NULL
	CSysNetEventExpr *getFirst(void);
	
	///获取下一个CSysNetEventExpr
	///@return	得到下一个CSysNetEventExpr，如果没有，则返回NULL
	CSysNetEventExpr *getNext(void);
	
	///结束获取CSysNetEventExpr
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetEventExprActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetEventExprActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetEventExprCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetEventExprCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetEventExprIteratorByAll;

	///开始寻找CSysNetEventExpr
	///@return	满足条件的地一个CSysNetEventExpr，如果找不到，返回NULL
	CSysNetEventExpr *startFindByAll();

	///寻找下一个符合条件的CSysNetEventExpr，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetEventExpr，如果已经没有一个满足要求了，则返回NULL
	CSysNetEventExpr *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetEventExpr
	///@param	ID	
	///@return	找到的CSysNetEventExpr，如果找不到，返回NULL
	CSysNetEventExpr *findByOne( const CReadOnlyVolumeType&  ID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetEventExpr加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetEventExpr	要加入的SysNetEventExpr
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetEventExpr *internalAdd(CWriteableSysNetEventExpr *pSysNetEventExpr, bool bNoTransaction);
	
	
	///刷新该CSysNetEventExpr的键值
	///@param	pSysNetEventExpr	被刷新的CSysNetEventExpr
	///@param	pNewSysNetEventExpr	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetEventExpr *pSysNetEventExpr, CWriteableSysNetEventExpr *pNewSysNetEventExpr, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetEventExpr，同时删除其索引
	///@param	pSysNetEventExpr	要删除的CSysNetEventExpr
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetEventExpr *pSysNetEventExpr, bool bNoTransaction);
/*
	///检查某个CSysNetEventExpr是否属于本对象工厂
	///@param	pSysNetEventExpr	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetEventExpr *pSysNetEventExpr);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetEventExpr	要加入的SysNetEventExpr
	virtual void beforeAdd(CWriteableSysNetEventExpr *pSysNetEventExpr);
	
	///加入后触发
	///@param	pSysNetEventExpr	已经加入的SysNetEventExpr
	virtual void afterAdd(CSysNetEventExpr *pSysNetEventExpr);

	///更新前触发	
	///@param	pSysNetEventExpr	被刷新的CSysNetEventExpr
	///@param	pNewSysNetEventExpr	新的值
	virtual void beforeUpdate(CSysNetEventExpr *pSysNetEventExpr, CWriteableSysNetEventExpr *pNewSysNetEventExpr);
	
	///更新后触发
	///@param	pSysNetEventExpr	被刷新的CSysNetEventExpr
	virtual void afterUpdate(CSysNetEventExpr *pSysNetEventExpr);
	
	///删除前触发
	///@param	pSysNetEventExpr	要删除的CSysNetEventExpr
	virtual void beforeRemove(CSysNetEventExpr *pSysNetEventExpr);
	
	///确认加入后触发
	///@param	pSysNetEventExpr	已经加入的SysNetEventExpr
	virtual void commitAdd(CSysNetEventExpr *pSysNetEventExpr);

	///确认更新后触发
	///@param	pSysNetEventExpr	被刷新的CSysNetEventExpr
	///@param	poldSysNetEventExpr	原来的值
	virtual void commitUpdate(CSysNetEventExpr *pSysNetEventExpr, CWriteableSysNetEventExpr *pOldSysNetEventExpr);
	
	///确认删除后触发
	///@param	pSysNetEventExpr	已经删除的CSysNetEventExpr
	virtual void commitRemove(CWriteableSysNetEventExpr *pSysNetEventExpr);

	///所有相关的触发器
	vector<CSysNetEventExprActionTrigger *> *pActionTriggers;
	vector<CSysNetEventExprCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetEventExpr compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventTypeFactory是一个事件类型的对象工厂。它包含了一批事件类型，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对事件类型的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventTypeFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetEventTypeFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetEventType，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetEventTypeFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetEventTypeFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetEventType
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetEventType，文件名将根据配置文件中的定义SysNetEventTypeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetEventType
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetEventType，文件名将根据配置文件中的定义SysNetEventTypeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetEventTypeResource;

	///将一个CSysNetEventType加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetEventType	要加入的SysNetEventType
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetEventType *add(CWriteableSysNetEventType *pSysNetEventType, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetEventType的值
	///@param	pSysNetEventType	被刷新的CSysNetEventType
	///@param	pNewSysNetEventType	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetEventType *pSysNetEventType, CWriteableSysNetEventType *pNewSysNetEventType, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetEventType	  需要被刷新或者新增的CSysNetEventType,等于NULL表示是需要新增的
	///@param	pNewSysNetEventType	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetEventType* addOrUpdate(CSysNetEventType *pSysNetEventType, CWriteableSysNetEventType *pNewSysNetEventType, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetEventType，同时删除其索引
	///@param	pSysNetEventType	要删除的CSysNetEventType
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetEventType *pSysNetEventType, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetEventType
	///@param	pSysNetEventType	要读取的CSysNetEventType
	///@param	pTragetSysNetEventType	存放结果的CSysNetEventType
	void retrieve(CSysNetEventType *pSysNetEventType, CWriteableSysNetEventType *pTargetSysNetEventType);
	
	///获取第一个CSysNetEventType
	///@return	得到的第一个CSysNetEventType，如果没有，则返回NULL
	CSysNetEventType *getFirst(void);
	
	///获取下一个CSysNetEventType
	///@return	得到下一个CSysNetEventType，如果没有，则返回NULL
	CSysNetEventType *getNext(void);
	
	///结束获取CSysNetEventType
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetEventTypeActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetEventTypeActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetEventTypeCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetEventTypeCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetEventTypeIteratorByAll;

	///开始寻找CSysNetEventType
	///@return	满足条件的地一个CSysNetEventType，如果找不到，返回NULL
	CSysNetEventType *startFindByAll();

	///寻找下一个符合条件的CSysNetEventType，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetEventType，如果已经没有一个满足要求了，则返回NULL
	CSysNetEventType *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetEventType
	///@param	ID	
	///@return	找到的CSysNetEventType，如果找不到，返回NULL
	CSysNetEventType *findByOne( const CReadOnlyVolumeType&  ID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetEventType加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetEventType	要加入的SysNetEventType
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetEventType *internalAdd(CWriteableSysNetEventType *pSysNetEventType, bool bNoTransaction);
	
	
	///刷新该CSysNetEventType的键值
	///@param	pSysNetEventType	被刷新的CSysNetEventType
	///@param	pNewSysNetEventType	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetEventType *pSysNetEventType, CWriteableSysNetEventType *pNewSysNetEventType, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetEventType，同时删除其索引
	///@param	pSysNetEventType	要删除的CSysNetEventType
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetEventType *pSysNetEventType, bool bNoTransaction);
/*
	///检查某个CSysNetEventType是否属于本对象工厂
	///@param	pSysNetEventType	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetEventType *pSysNetEventType);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetEventType	要加入的SysNetEventType
	virtual void beforeAdd(CWriteableSysNetEventType *pSysNetEventType);
	
	///加入后触发
	///@param	pSysNetEventType	已经加入的SysNetEventType
	virtual void afterAdd(CSysNetEventType *pSysNetEventType);

	///更新前触发	
	///@param	pSysNetEventType	被刷新的CSysNetEventType
	///@param	pNewSysNetEventType	新的值
	virtual void beforeUpdate(CSysNetEventType *pSysNetEventType, CWriteableSysNetEventType *pNewSysNetEventType);
	
	///更新后触发
	///@param	pSysNetEventType	被刷新的CSysNetEventType
	virtual void afterUpdate(CSysNetEventType *pSysNetEventType);
	
	///删除前触发
	///@param	pSysNetEventType	要删除的CSysNetEventType
	virtual void beforeRemove(CSysNetEventType *pSysNetEventType);
	
	///确认加入后触发
	///@param	pSysNetEventType	已经加入的SysNetEventType
	virtual void commitAdd(CSysNetEventType *pSysNetEventType);

	///确认更新后触发
	///@param	pSysNetEventType	被刷新的CSysNetEventType
	///@param	poldSysNetEventType	原来的值
	virtual void commitUpdate(CSysNetEventType *pSysNetEventType, CWriteableSysNetEventType *pOldSysNetEventType);
	
	///确认删除后触发
	///@param	pSysNetEventType	已经删除的CSysNetEventType
	virtual void commitRemove(CWriteableSysNetEventType *pSysNetEventType);

	///所有相关的触发器
	vector<CSysNetEventTypeActionTrigger *> *pActionTriggers;
	vector<CSysNetEventTypeCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetEventType compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubEventTypeFactory是一个事件子类型的对象工厂。它包含了一批事件子类型，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对事件子类型的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubEventTypeFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetSubEventTypeFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetSubEventType，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetSubEventTypeFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetSubEventTypeFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetSubEventType
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetSubEventType，文件名将根据配置文件中的定义SysNetSubEventTypeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetSubEventType
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetSubEventType，文件名将根据配置文件中的定义SysNetSubEventTypeCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetSubEventTypeResource;

	///将一个CSysNetSubEventType加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetSubEventType	要加入的SysNetSubEventType
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetSubEventType *add(CWriteableSysNetSubEventType *pSysNetSubEventType, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetSubEventType的值
	///@param	pSysNetSubEventType	被刷新的CSysNetSubEventType
	///@param	pNewSysNetSubEventType	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetSubEventType *pSysNetSubEventType, CWriteableSysNetSubEventType *pNewSysNetSubEventType, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetSubEventType	  需要被刷新或者新增的CSysNetSubEventType,等于NULL表示是需要新增的
	///@param	pNewSysNetSubEventType	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetSubEventType* addOrUpdate(CSysNetSubEventType *pSysNetSubEventType, CWriteableSysNetSubEventType *pNewSysNetSubEventType, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetSubEventType，同时删除其索引
	///@param	pSysNetSubEventType	要删除的CSysNetSubEventType
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetSubEventType *pSysNetSubEventType, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetSubEventType
	///@param	pSysNetSubEventType	要读取的CSysNetSubEventType
	///@param	pTragetSysNetSubEventType	存放结果的CSysNetSubEventType
	void retrieve(CSysNetSubEventType *pSysNetSubEventType, CWriteableSysNetSubEventType *pTargetSysNetSubEventType);
	
	///获取第一个CSysNetSubEventType
	///@return	得到的第一个CSysNetSubEventType，如果没有，则返回NULL
	CSysNetSubEventType *getFirst(void);
	
	///获取下一个CSysNetSubEventType
	///@return	得到下一个CSysNetSubEventType，如果没有，则返回NULL
	CSysNetSubEventType *getNext(void);
	
	///结束获取CSysNetSubEventType
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetSubEventTypeActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetSubEventTypeActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetSubEventTypeCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetSubEventTypeCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetSubEventTypeIteratorByAll;

	///开始寻找CSysNetSubEventType
	///@return	满足条件的地一个CSysNetSubEventType，如果找不到，返回NULL
	CSysNetSubEventType *startFindByAll();

	///寻找下一个符合条件的CSysNetSubEventType，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetSubEventType，如果已经没有一个满足要求了，则返回NULL
	CSysNetSubEventType *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetSubEventType
	///@param	ID	
	///@return	找到的CSysNetSubEventType，如果找不到，返回NULL
	CSysNetSubEventType *findByOne( const CReadOnlyVolumeType&  ID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetSubEventType加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetSubEventType	要加入的SysNetSubEventType
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetSubEventType *internalAdd(CWriteableSysNetSubEventType *pSysNetSubEventType, bool bNoTransaction);
	
	
	///刷新该CSysNetSubEventType的键值
	///@param	pSysNetSubEventType	被刷新的CSysNetSubEventType
	///@param	pNewSysNetSubEventType	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetSubEventType *pSysNetSubEventType, CWriteableSysNetSubEventType *pNewSysNetSubEventType, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetSubEventType，同时删除其索引
	///@param	pSysNetSubEventType	要删除的CSysNetSubEventType
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetSubEventType *pSysNetSubEventType, bool bNoTransaction);
/*
	///检查某个CSysNetSubEventType是否属于本对象工厂
	///@param	pSysNetSubEventType	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetSubEventType *pSysNetSubEventType);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetSubEventType	要加入的SysNetSubEventType
	virtual void beforeAdd(CWriteableSysNetSubEventType *pSysNetSubEventType);
	
	///加入后触发
	///@param	pSysNetSubEventType	已经加入的SysNetSubEventType
	virtual void afterAdd(CSysNetSubEventType *pSysNetSubEventType);

	///更新前触发	
	///@param	pSysNetSubEventType	被刷新的CSysNetSubEventType
	///@param	pNewSysNetSubEventType	新的值
	virtual void beforeUpdate(CSysNetSubEventType *pSysNetSubEventType, CWriteableSysNetSubEventType *pNewSysNetSubEventType);
	
	///更新后触发
	///@param	pSysNetSubEventType	被刷新的CSysNetSubEventType
	virtual void afterUpdate(CSysNetSubEventType *pSysNetSubEventType);
	
	///删除前触发
	///@param	pSysNetSubEventType	要删除的CSysNetSubEventType
	virtual void beforeRemove(CSysNetSubEventType *pSysNetSubEventType);
	
	///确认加入后触发
	///@param	pSysNetSubEventType	已经加入的SysNetSubEventType
	virtual void commitAdd(CSysNetSubEventType *pSysNetSubEventType);

	///确认更新后触发
	///@param	pSysNetSubEventType	被刷新的CSysNetSubEventType
	///@param	poldSysNetSubEventType	原来的值
	virtual void commitUpdate(CSysNetSubEventType *pSysNetSubEventType, CWriteableSysNetSubEventType *pOldSysNetSubEventType);
	
	///确认删除后触发
	///@param	pSysNetSubEventType	已经删除的CSysNetSubEventType
	virtual void commitRemove(CWriteableSysNetSubEventType *pSysNetSubEventType);

	///所有相关的触发器
	vector<CSysNetSubEventTypeActionTrigger *> *pActionTriggers;
	vector<CSysNetSubEventTypeCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetSubEventType compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventLevelFactory是一个事件级别的对象工厂。它包含了一批事件级别，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对事件级别的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventLevelFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetEventLevelFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetEventLevel，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetEventLevelFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetEventLevelFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetEventLevel
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetEventLevel，文件名将根据配置文件中的定义SysNetEventLevelCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetEventLevel
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetEventLevel，文件名将根据配置文件中的定义SysNetEventLevelCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetEventLevelResource;

	///将一个CSysNetEventLevel加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetEventLevel	要加入的SysNetEventLevel
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetEventLevel *add(CWriteableSysNetEventLevel *pSysNetEventLevel, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetEventLevel的值
	///@param	pSysNetEventLevel	被刷新的CSysNetEventLevel
	///@param	pNewSysNetEventLevel	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetEventLevel *pSysNetEventLevel, CWriteableSysNetEventLevel *pNewSysNetEventLevel, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetEventLevel	  需要被刷新或者新增的CSysNetEventLevel,等于NULL表示是需要新增的
	///@param	pNewSysNetEventLevel	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetEventLevel* addOrUpdate(CSysNetEventLevel *pSysNetEventLevel, CWriteableSysNetEventLevel *pNewSysNetEventLevel, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetEventLevel，同时删除其索引
	///@param	pSysNetEventLevel	要删除的CSysNetEventLevel
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetEventLevel *pSysNetEventLevel, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetEventLevel
	///@param	pSysNetEventLevel	要读取的CSysNetEventLevel
	///@param	pTragetSysNetEventLevel	存放结果的CSysNetEventLevel
	void retrieve(CSysNetEventLevel *pSysNetEventLevel, CWriteableSysNetEventLevel *pTargetSysNetEventLevel);
	
	///获取第一个CSysNetEventLevel
	///@return	得到的第一个CSysNetEventLevel，如果没有，则返回NULL
	CSysNetEventLevel *getFirst(void);
	
	///获取下一个CSysNetEventLevel
	///@return	得到下一个CSysNetEventLevel，如果没有，则返回NULL
	CSysNetEventLevel *getNext(void);
	
	///结束获取CSysNetEventLevel
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetEventLevelActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetEventLevelActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetEventLevelCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetEventLevelCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetEventLevelIteratorByAll;

	///开始寻找CSysNetEventLevel
	///@return	满足条件的地一个CSysNetEventLevel，如果找不到，返回NULL
	CSysNetEventLevel *startFindByAll();

	///寻找下一个符合条件的CSysNetEventLevel，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetEventLevel，如果已经没有一个满足要求了，则返回NULL
	CSysNetEventLevel *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetEventLevel
	///@param	ID	
	///@return	找到的CSysNetEventLevel，如果找不到，返回NULL
	CSysNetEventLevel *findByOne( const CReadOnlyVolumeType&  ID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetEventLevel加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetEventLevel	要加入的SysNetEventLevel
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetEventLevel *internalAdd(CWriteableSysNetEventLevel *pSysNetEventLevel, bool bNoTransaction);
	
	
	///刷新该CSysNetEventLevel的键值
	///@param	pSysNetEventLevel	被刷新的CSysNetEventLevel
	///@param	pNewSysNetEventLevel	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetEventLevel *pSysNetEventLevel, CWriteableSysNetEventLevel *pNewSysNetEventLevel, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetEventLevel，同时删除其索引
	///@param	pSysNetEventLevel	要删除的CSysNetEventLevel
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetEventLevel *pSysNetEventLevel, bool bNoTransaction);
/*
	///检查某个CSysNetEventLevel是否属于本对象工厂
	///@param	pSysNetEventLevel	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetEventLevel *pSysNetEventLevel);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetEventLevel	要加入的SysNetEventLevel
	virtual void beforeAdd(CWriteableSysNetEventLevel *pSysNetEventLevel);
	
	///加入后触发
	///@param	pSysNetEventLevel	已经加入的SysNetEventLevel
	virtual void afterAdd(CSysNetEventLevel *pSysNetEventLevel);

	///更新前触发	
	///@param	pSysNetEventLevel	被刷新的CSysNetEventLevel
	///@param	pNewSysNetEventLevel	新的值
	virtual void beforeUpdate(CSysNetEventLevel *pSysNetEventLevel, CWriteableSysNetEventLevel *pNewSysNetEventLevel);
	
	///更新后触发
	///@param	pSysNetEventLevel	被刷新的CSysNetEventLevel
	virtual void afterUpdate(CSysNetEventLevel *pSysNetEventLevel);
	
	///删除前触发
	///@param	pSysNetEventLevel	要删除的CSysNetEventLevel
	virtual void beforeRemove(CSysNetEventLevel *pSysNetEventLevel);
	
	///确认加入后触发
	///@param	pSysNetEventLevel	已经加入的SysNetEventLevel
	virtual void commitAdd(CSysNetEventLevel *pSysNetEventLevel);

	///确认更新后触发
	///@param	pSysNetEventLevel	被刷新的CSysNetEventLevel
	///@param	poldSysNetEventLevel	原来的值
	virtual void commitUpdate(CSysNetEventLevel *pSysNetEventLevel, CWriteableSysNetEventLevel *pOldSysNetEventLevel);
	
	///确认删除后触发
	///@param	pSysNetEventLevel	已经删除的CSysNetEventLevel
	virtual void commitRemove(CWriteableSysNetEventLevel *pSysNetEventLevel);

	///所有相关的触发器
	vector<CSysNetEventLevelActionTrigger *> *pActionTriggers;
	vector<CSysNetEventLevelCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetEventLevel compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceTaskFactory是一个任务结果规则分析表的对象工厂。它包含了一批任务结果规则分析表，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对任务结果规则分析表的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用startFindByID，findNextByID和endFindByID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceTaskFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetMonitorDeviceTaskFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetMonitorDeviceTask，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetMonitorDeviceTaskFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorDeviceTaskFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetMonitorDeviceTask
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetMonitorDeviceTask，文件名将根据配置文件中的定义SysNetMonitorDeviceTaskCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetMonitorDeviceTask
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetMonitorDeviceTask，文件名将根据配置文件中的定义SysNetMonitorDeviceTaskCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetMonitorDeviceTaskResource;

	///将一个CSysNetMonitorDeviceTask加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetMonitorDeviceTask	要加入的SysNetMonitorDeviceTask
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetMonitorDeviceTask *add(CWriteableSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetMonitorDeviceTask的值
	///@param	pSysNetMonitorDeviceTask	被刷新的CSysNetMonitorDeviceTask
	///@param	pNewSysNetMonitorDeviceTask	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask, CWriteableSysNetMonitorDeviceTask *pNewSysNetMonitorDeviceTask, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetMonitorDeviceTask	  需要被刷新或者新增的CSysNetMonitorDeviceTask,等于NULL表示是需要新增的
	///@param	pNewSysNetMonitorDeviceTask	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetMonitorDeviceTask* addOrUpdate(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask, CWriteableSysNetMonitorDeviceTask *pNewSysNetMonitorDeviceTask, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetMonitorDeviceTask，同时删除其索引
	///@param	pSysNetMonitorDeviceTask	要删除的CSysNetMonitorDeviceTask
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetMonitorDeviceTask
	///@param	pSysNetMonitorDeviceTask	要读取的CSysNetMonitorDeviceTask
	///@param	pTragetSysNetMonitorDeviceTask	存放结果的CSysNetMonitorDeviceTask
	void retrieve(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask, CWriteableSysNetMonitorDeviceTask *pTargetSysNetMonitorDeviceTask);
	
	///获取第一个CSysNetMonitorDeviceTask
	///@return	得到的第一个CSysNetMonitorDeviceTask，如果没有，则返回NULL
	CSysNetMonitorDeviceTask *getFirst(void);
	
	///获取下一个CSysNetMonitorDeviceTask
	///@return	得到下一个CSysNetMonitorDeviceTask，如果没有，则返回NULL
	CSysNetMonitorDeviceTask *getNext(void);
	
	///结束获取CSysNetMonitorDeviceTask
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetMonitorDeviceTaskActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetMonitorDeviceTaskActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetMonitorDeviceTaskCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetMonitorDeviceTaskCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetMonitorDeviceTaskIteratorByAll;

	///开始寻找CSysNetMonitorDeviceTask
	///@return	满足条件的地一个CSysNetMonitorDeviceTask，如果找不到，返回NULL
	CSysNetMonitorDeviceTask *startFindByAll();

	///寻找下一个符合条件的CSysNetMonitorDeviceTask，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetMonitorDeviceTask，如果已经没有一个满足要求了，则返回NULL
	CSysNetMonitorDeviceTask *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	friend class CSysNetMonitorDeviceTaskIteratorByID;

	///开始寻找CSysNetMonitorDeviceTask
	///@param	ID	
	///@return	满足条件的地一个CSysNetMonitorDeviceTask，如果找不到，返回NULL
	CSysNetMonitorDeviceTask *startFindByID( const CReadOnlyVolumeType& ID);

	///寻找下一个符合条件的CSysNetMonitorDeviceTask，必须在startFindByID以后，endFindByID之前叫用
	///@return	下一个满足条件CSysNetMonitorDeviceTask，如果已经没有一个满足要求了，则返回NULL
	CSysNetMonitorDeviceTask *findNextByID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetMonitorDeviceTask加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetMonitorDeviceTask	要加入的SysNetMonitorDeviceTask
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetMonitorDeviceTask *internalAdd(CWriteableSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask, bool bNoTransaction);
	
	
	///刷新该CSysNetMonitorDeviceTask的键值
	///@param	pSysNetMonitorDeviceTask	被刷新的CSysNetMonitorDeviceTask
	///@param	pNewSysNetMonitorDeviceTask	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask, CWriteableSysNetMonitorDeviceTask *pNewSysNetMonitorDeviceTask, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetMonitorDeviceTask，同时删除其索引
	///@param	pSysNetMonitorDeviceTask	要删除的CSysNetMonitorDeviceTask
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask, bool bNoTransaction);
/*
	///检查某个CSysNetMonitorDeviceTask是否属于本对象工厂
	///@param	pSysNetMonitorDeviceTask	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID+SecondID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	///按照ID检索时，存储的查询参数
	CVolumeType queryIDInSearchByID;
	
	///按照ID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByID;
	
	///加入前触发
	///@param	pSysNetMonitorDeviceTask	要加入的SysNetMonitorDeviceTask
	virtual void beforeAdd(CWriteableSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask);
	
	///加入后触发
	///@param	pSysNetMonitorDeviceTask	已经加入的SysNetMonitorDeviceTask
	virtual void afterAdd(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask);

	///更新前触发	
	///@param	pSysNetMonitorDeviceTask	被刷新的CSysNetMonitorDeviceTask
	///@param	pNewSysNetMonitorDeviceTask	新的值
	virtual void beforeUpdate(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask, CWriteableSysNetMonitorDeviceTask *pNewSysNetMonitorDeviceTask);
	
	///更新后触发
	///@param	pSysNetMonitorDeviceTask	被刷新的CSysNetMonitorDeviceTask
	virtual void afterUpdate(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask);
	
	///删除前触发
	///@param	pSysNetMonitorDeviceTask	要删除的CSysNetMonitorDeviceTask
	virtual void beforeRemove(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask);
	
	///确认加入后触发
	///@param	pSysNetMonitorDeviceTask	已经加入的SysNetMonitorDeviceTask
	virtual void commitAdd(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask);

	///确认更新后触发
	///@param	pSysNetMonitorDeviceTask	被刷新的CSysNetMonitorDeviceTask
	///@param	poldSysNetMonitorDeviceTask	原来的值
	virtual void commitUpdate(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask, CWriteableSysNetMonitorDeviceTask *pOldSysNetMonitorDeviceTask);
	
	///确认删除后触发
	///@param	pSysNetMonitorDeviceTask	已经删除的CSysNetMonitorDeviceTask
	virtual void commitRemove(CWriteableSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask);

	///所有相关的触发器
	vector<CSysNetMonitorDeviceTaskActionTrigger *> *pActionTriggers;
	vector<CSysNetMonitorDeviceTaskCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetMonitorDeviceTask compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInstAttrsFactory是一个任务指令指标集表的对象工厂。它包含了一批任务指令指标集表，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对任务指令指标集表的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInstAttrsFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetMonitorTaskInstAttrsFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetMonitorTaskInstAttrs，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetMonitorTaskInstAttrsFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorTaskInstAttrsFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetMonitorTaskInstAttrs
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetMonitorTaskInstAttrs，文件名将根据配置文件中的定义SysNetMonitorTaskInstAttrsCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetMonitorTaskInstAttrs
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetMonitorTaskInstAttrs，文件名将根据配置文件中的定义SysNetMonitorTaskInstAttrsCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetMonitorTaskInstAttrsResource;

	///将一个CSysNetMonitorTaskInstAttrs加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetMonitorTaskInstAttrs	要加入的SysNetMonitorTaskInstAttrs
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetMonitorTaskInstAttrs *add(CWriteableSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetMonitorTaskInstAttrs的值
	///@param	pSysNetMonitorTaskInstAttrs	被刷新的CSysNetMonitorTaskInstAttrs
	///@param	pNewSysNetMonitorTaskInstAttrs	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs, CWriteableSysNetMonitorTaskInstAttrs *pNewSysNetMonitorTaskInstAttrs, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetMonitorTaskInstAttrs	  需要被刷新或者新增的CSysNetMonitorTaskInstAttrs,等于NULL表示是需要新增的
	///@param	pNewSysNetMonitorTaskInstAttrs	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetMonitorTaskInstAttrs* addOrUpdate(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs, CWriteableSysNetMonitorTaskInstAttrs *pNewSysNetMonitorTaskInstAttrs, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetMonitorTaskInstAttrs，同时删除其索引
	///@param	pSysNetMonitorTaskInstAttrs	要删除的CSysNetMonitorTaskInstAttrs
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetMonitorTaskInstAttrs
	///@param	pSysNetMonitorTaskInstAttrs	要读取的CSysNetMonitorTaskInstAttrs
	///@param	pTragetSysNetMonitorTaskInstAttrs	存放结果的CSysNetMonitorTaskInstAttrs
	void retrieve(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs, CWriteableSysNetMonitorTaskInstAttrs *pTargetSysNetMonitorTaskInstAttrs);
	
	///获取第一个CSysNetMonitorTaskInstAttrs
	///@return	得到的第一个CSysNetMonitorTaskInstAttrs，如果没有，则返回NULL
	CSysNetMonitorTaskInstAttrs *getFirst(void);
	
	///获取下一个CSysNetMonitorTaskInstAttrs
	///@return	得到下一个CSysNetMonitorTaskInstAttrs，如果没有，则返回NULL
	CSysNetMonitorTaskInstAttrs *getNext(void);
	
	///结束获取CSysNetMonitorTaskInstAttrs
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetMonitorTaskInstAttrsActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetMonitorTaskInstAttrsActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetMonitorTaskInstAttrsCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetMonitorTaskInstAttrsCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetMonitorTaskInstAttrsIteratorByAll;

	///开始寻找CSysNetMonitorTaskInstAttrs
	///@return	满足条件的地一个CSysNetMonitorTaskInstAttrs，如果找不到，返回NULL
	CSysNetMonitorTaskInstAttrs *startFindByAll();

	///寻找下一个符合条件的CSysNetMonitorTaskInstAttrs，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetMonitorTaskInstAttrs，如果已经没有一个满足要求了，则返回NULL
	CSysNetMonitorTaskInstAttrs *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetMonitorTaskInstAttrs加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetMonitorTaskInstAttrs	要加入的SysNetMonitorTaskInstAttrs
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetMonitorTaskInstAttrs *internalAdd(CWriteableSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs, bool bNoTransaction);
	
	
	///刷新该CSysNetMonitorTaskInstAttrs的键值
	///@param	pSysNetMonitorTaskInstAttrs	被刷新的CSysNetMonitorTaskInstAttrs
	///@param	pNewSysNetMonitorTaskInstAttrs	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs, CWriteableSysNetMonitorTaskInstAttrs *pNewSysNetMonitorTaskInstAttrs, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetMonitorTaskInstAttrs，同时删除其索引
	///@param	pSysNetMonitorTaskInstAttrs	要删除的CSysNetMonitorTaskInstAttrs
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs, bool bNoTransaction);
/*
	///检查某个CSysNetMonitorTaskInstAttrs是否属于本对象工厂
	///@param	pSysNetMonitorTaskInstAttrs	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetMonitorTaskInstAttrs	要加入的SysNetMonitorTaskInstAttrs
	virtual void beforeAdd(CWriteableSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs);
	
	///加入后触发
	///@param	pSysNetMonitorTaskInstAttrs	已经加入的SysNetMonitorTaskInstAttrs
	virtual void afterAdd(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs);

	///更新前触发	
	///@param	pSysNetMonitorTaskInstAttrs	被刷新的CSysNetMonitorTaskInstAttrs
	///@param	pNewSysNetMonitorTaskInstAttrs	新的值
	virtual void beforeUpdate(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs, CWriteableSysNetMonitorTaskInstAttrs *pNewSysNetMonitorTaskInstAttrs);
	
	///更新后触发
	///@param	pSysNetMonitorTaskInstAttrs	被刷新的CSysNetMonitorTaskInstAttrs
	virtual void afterUpdate(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs);
	
	///删除前触发
	///@param	pSysNetMonitorTaskInstAttrs	要删除的CSysNetMonitorTaskInstAttrs
	virtual void beforeRemove(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs);
	
	///确认加入后触发
	///@param	pSysNetMonitorTaskInstAttrs	已经加入的SysNetMonitorTaskInstAttrs
	virtual void commitAdd(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs);

	///确认更新后触发
	///@param	pSysNetMonitorTaskInstAttrs	被刷新的CSysNetMonitorTaskInstAttrs
	///@param	poldSysNetMonitorTaskInstAttrs	原来的值
	virtual void commitUpdate(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs, CWriteableSysNetMonitorTaskInstAttrs *pOldSysNetMonitorTaskInstAttrs);
	
	///确认删除后触发
	///@param	pSysNetMonitorTaskInstAttrs	已经删除的CSysNetMonitorTaskInstAttrs
	virtual void commitRemove(CWriteableSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs);

	///所有相关的触发器
	vector<CSysNetMonitorTaskInstAttrsActionTrigger *> *pActionTriggers;
	vector<CSysNetMonitorTaskInstAttrsCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetMonitorTaskInstAttrs compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineFactory是一个基线表的对象工厂。它包含了一批基线表，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对基线表的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用startFindByID，findNextByID和endFindByID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetBaseLineFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetBaseLine，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetBaseLineFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetBaseLineFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetBaseLine
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetBaseLine，文件名将根据配置文件中的定义SysNetBaseLineCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetBaseLine
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetBaseLine，文件名将根据配置文件中的定义SysNetBaseLineCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetBaseLineResource;

	///将一个CSysNetBaseLine加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetBaseLine	要加入的SysNetBaseLine
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetBaseLine *add(CWriteableSysNetBaseLine *pSysNetBaseLine, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetBaseLine的值
	///@param	pSysNetBaseLine	被刷新的CSysNetBaseLine
	///@param	pNewSysNetBaseLine	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetBaseLine *pSysNetBaseLine, CWriteableSysNetBaseLine *pNewSysNetBaseLine, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetBaseLine	  需要被刷新或者新增的CSysNetBaseLine,等于NULL表示是需要新增的
	///@param	pNewSysNetBaseLine	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetBaseLine* addOrUpdate(CSysNetBaseLine *pSysNetBaseLine, CWriteableSysNetBaseLine *pNewSysNetBaseLine, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetBaseLine，同时删除其索引
	///@param	pSysNetBaseLine	要删除的CSysNetBaseLine
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetBaseLine *pSysNetBaseLine, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetBaseLine
	///@param	pSysNetBaseLine	要读取的CSysNetBaseLine
	///@param	pTragetSysNetBaseLine	存放结果的CSysNetBaseLine
	void retrieve(CSysNetBaseLine *pSysNetBaseLine, CWriteableSysNetBaseLine *pTargetSysNetBaseLine);
	
	///获取第一个CSysNetBaseLine
	///@return	得到的第一个CSysNetBaseLine，如果没有，则返回NULL
	CSysNetBaseLine *getFirst(void);
	
	///获取下一个CSysNetBaseLine
	///@return	得到下一个CSysNetBaseLine，如果没有，则返回NULL
	CSysNetBaseLine *getNext(void);
	
	///结束获取CSysNetBaseLine
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetBaseLineActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetBaseLineActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetBaseLineCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetBaseLineCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetBaseLineIteratorByAll;

	///开始寻找CSysNetBaseLine
	///@return	满足条件的地一个CSysNetBaseLine，如果找不到，返回NULL
	CSysNetBaseLine *startFindByAll();

	///寻找下一个符合条件的CSysNetBaseLine，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetBaseLine，如果已经没有一个满足要求了，则返回NULL
	CSysNetBaseLine *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	friend class CSysNetBaseLineIteratorByID;

	///开始寻找CSysNetBaseLine
	///@param	ID	
	///@return	满足条件的地一个CSysNetBaseLine，如果找不到，返回NULL
	CSysNetBaseLine *startFindByID( const CReadOnlyVolumeType& ID);

	///寻找下一个符合条件的CSysNetBaseLine，必须在startFindByID以后，endFindByID之前叫用
	///@return	下一个满足条件CSysNetBaseLine，如果已经没有一个满足要求了，则返回NULL
	CSysNetBaseLine *findNextByID(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByID(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetBaseLine加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetBaseLine	要加入的SysNetBaseLine
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetBaseLine *internalAdd(CWriteableSysNetBaseLine *pSysNetBaseLine, bool bNoTransaction);
	
	
	///刷新该CSysNetBaseLine的键值
	///@param	pSysNetBaseLine	被刷新的CSysNetBaseLine
	///@param	pNewSysNetBaseLine	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetBaseLine *pSysNetBaseLine, CWriteableSysNetBaseLine *pNewSysNetBaseLine, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetBaseLine，同时删除其索引
	///@param	pSysNetBaseLine	要删除的CSysNetBaseLine
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetBaseLine *pSysNetBaseLine, bool bNoTransaction);
/*
	///检查某个CSysNetBaseLine是否属于本对象工厂
	///@param	pSysNetBaseLine	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetBaseLine *pSysNetBaseLine);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	///按照ID检索时，存储的查询参数
	CVolumeType queryIDInSearchByID;
	
	///按照ID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByID;
	
	///加入前触发
	///@param	pSysNetBaseLine	要加入的SysNetBaseLine
	virtual void beforeAdd(CWriteableSysNetBaseLine *pSysNetBaseLine);
	
	///加入后触发
	///@param	pSysNetBaseLine	已经加入的SysNetBaseLine
	virtual void afterAdd(CSysNetBaseLine *pSysNetBaseLine);

	///更新前触发	
	///@param	pSysNetBaseLine	被刷新的CSysNetBaseLine
	///@param	pNewSysNetBaseLine	新的值
	virtual void beforeUpdate(CSysNetBaseLine *pSysNetBaseLine, CWriteableSysNetBaseLine *pNewSysNetBaseLine);
	
	///更新后触发
	///@param	pSysNetBaseLine	被刷新的CSysNetBaseLine
	virtual void afterUpdate(CSysNetBaseLine *pSysNetBaseLine);
	
	///删除前触发
	///@param	pSysNetBaseLine	要删除的CSysNetBaseLine
	virtual void beforeRemove(CSysNetBaseLine *pSysNetBaseLine);
	
	///确认加入后触发
	///@param	pSysNetBaseLine	已经加入的SysNetBaseLine
	virtual void commitAdd(CSysNetBaseLine *pSysNetBaseLine);

	///确认更新后触发
	///@param	pSysNetBaseLine	被刷新的CSysNetBaseLine
	///@param	poldSysNetBaseLine	原来的值
	virtual void commitUpdate(CSysNetBaseLine *pSysNetBaseLine, CWriteableSysNetBaseLine *pOldSysNetBaseLine);
	
	///确认删除后触发
	///@param	pSysNetBaseLine	已经删除的CSysNetBaseLine
	virtual void commitRemove(CWriteableSysNetBaseLine *pSysNetBaseLine);

	///所有相关的触发器
	vector<CSysNetBaseLineActionTrigger *> *pActionTriggers;
	vector<CSysNetBaseLineCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetBaseLine compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineTaskFactory是一个基线任务表的对象工厂。它包含了一批基线任务表，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对基线任务表的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineTaskFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetBaseLineTaskFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetBaseLineTask，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetBaseLineTaskFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetBaseLineTaskFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetBaseLineTask
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetBaseLineTask，文件名将根据配置文件中的定义SysNetBaseLineTaskCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetBaseLineTask
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetBaseLineTask，文件名将根据配置文件中的定义SysNetBaseLineTaskCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetBaseLineTaskResource;

	///将一个CSysNetBaseLineTask加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetBaseLineTask	要加入的SysNetBaseLineTask
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetBaseLineTask *add(CWriteableSysNetBaseLineTask *pSysNetBaseLineTask, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetBaseLineTask的值
	///@param	pSysNetBaseLineTask	被刷新的CSysNetBaseLineTask
	///@param	pNewSysNetBaseLineTask	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetBaseLineTask *pSysNetBaseLineTask, CWriteableSysNetBaseLineTask *pNewSysNetBaseLineTask, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetBaseLineTask	  需要被刷新或者新增的CSysNetBaseLineTask,等于NULL表示是需要新增的
	///@param	pNewSysNetBaseLineTask	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetBaseLineTask* addOrUpdate(CSysNetBaseLineTask *pSysNetBaseLineTask, CWriteableSysNetBaseLineTask *pNewSysNetBaseLineTask, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetBaseLineTask，同时删除其索引
	///@param	pSysNetBaseLineTask	要删除的CSysNetBaseLineTask
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetBaseLineTask *pSysNetBaseLineTask, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetBaseLineTask
	///@param	pSysNetBaseLineTask	要读取的CSysNetBaseLineTask
	///@param	pTragetSysNetBaseLineTask	存放结果的CSysNetBaseLineTask
	void retrieve(CSysNetBaseLineTask *pSysNetBaseLineTask, CWriteableSysNetBaseLineTask *pTargetSysNetBaseLineTask);
	
	///获取第一个CSysNetBaseLineTask
	///@return	得到的第一个CSysNetBaseLineTask，如果没有，则返回NULL
	CSysNetBaseLineTask *getFirst(void);
	
	///获取下一个CSysNetBaseLineTask
	///@return	得到下一个CSysNetBaseLineTask，如果没有，则返回NULL
	CSysNetBaseLineTask *getNext(void);
	
	///结束获取CSysNetBaseLineTask
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetBaseLineTaskActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetBaseLineTaskActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetBaseLineTaskCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetBaseLineTaskCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetBaseLineTaskIteratorByAll;

	///开始寻找CSysNetBaseLineTask
	///@return	满足条件的地一个CSysNetBaseLineTask，如果找不到，返回NULL
	CSysNetBaseLineTask *startFindByAll();

	///寻找下一个符合条件的CSysNetBaseLineTask，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetBaseLineTask，如果已经没有一个满足要求了，则返回NULL
	CSysNetBaseLineTask *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetBaseLineTask加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetBaseLineTask	要加入的SysNetBaseLineTask
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetBaseLineTask *internalAdd(CWriteableSysNetBaseLineTask *pSysNetBaseLineTask, bool bNoTransaction);
	
	
	///刷新该CSysNetBaseLineTask的键值
	///@param	pSysNetBaseLineTask	被刷新的CSysNetBaseLineTask
	///@param	pNewSysNetBaseLineTask	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetBaseLineTask *pSysNetBaseLineTask, CWriteableSysNetBaseLineTask *pNewSysNetBaseLineTask, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetBaseLineTask，同时删除其索引
	///@param	pSysNetBaseLineTask	要删除的CSysNetBaseLineTask
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetBaseLineTask *pSysNetBaseLineTask, bool bNoTransaction);
/*
	///检查某个CSysNetBaseLineTask是否属于本对象工厂
	///@param	pSysNetBaseLineTask	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetBaseLineTask *pSysNetBaseLineTask);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetBaseLineTask	要加入的SysNetBaseLineTask
	virtual void beforeAdd(CWriteableSysNetBaseLineTask *pSysNetBaseLineTask);
	
	///加入后触发
	///@param	pSysNetBaseLineTask	已经加入的SysNetBaseLineTask
	virtual void afterAdd(CSysNetBaseLineTask *pSysNetBaseLineTask);

	///更新前触发	
	///@param	pSysNetBaseLineTask	被刷新的CSysNetBaseLineTask
	///@param	pNewSysNetBaseLineTask	新的值
	virtual void beforeUpdate(CSysNetBaseLineTask *pSysNetBaseLineTask, CWriteableSysNetBaseLineTask *pNewSysNetBaseLineTask);
	
	///更新后触发
	///@param	pSysNetBaseLineTask	被刷新的CSysNetBaseLineTask
	virtual void afterUpdate(CSysNetBaseLineTask *pSysNetBaseLineTask);
	
	///删除前触发
	///@param	pSysNetBaseLineTask	要删除的CSysNetBaseLineTask
	virtual void beforeRemove(CSysNetBaseLineTask *pSysNetBaseLineTask);
	
	///确认加入后触发
	///@param	pSysNetBaseLineTask	已经加入的SysNetBaseLineTask
	virtual void commitAdd(CSysNetBaseLineTask *pSysNetBaseLineTask);

	///确认更新后触发
	///@param	pSysNetBaseLineTask	被刷新的CSysNetBaseLineTask
	///@param	poldSysNetBaseLineTask	原来的值
	virtual void commitUpdate(CSysNetBaseLineTask *pSysNetBaseLineTask, CWriteableSysNetBaseLineTask *pOldSysNetBaseLineTask);
	
	///确认删除后触发
	///@param	pSysNetBaseLineTask	已经删除的CSysNetBaseLineTask
	virtual void commitRemove(CWriteableSysNetBaseLineTask *pSysNetBaseLineTask);

	///所有相关的触发器
	vector<CSysNetBaseLineTaskActionTrigger *> *pActionTriggers;
	vector<CSysNetBaseLineTaskCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetBaseLineTask compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoFactory是一个会员链路状态信息表的对象工厂。它包含了一批会员链路状态信息表，
///同时又建立了如下索引，以方便查询：
///	SysDateTimeIndex
///	DecIndex
///使用本对象工厂，可以完成对会员链路状态信息表的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByTime，findNextByTime和endFindByTime完成查询操作
///		使用startFindByDsc，findNextByDsc和endFindByDsc完成查询操作
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbNetPartyLinkStatusInfoFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysMdbNetPartyLinkStatusInfo，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbNetPartyLinkStatusInfoFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbNetPartyLinkStatusInfoFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysMdbNetPartyLinkStatusInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysMdbNetPartyLinkStatusInfo，文件名将根据配置文件中的定义SysMdbNetPartyLinkStatusInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysMdbNetPartyLinkStatusInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysMdbNetPartyLinkStatusInfo，文件名将根据配置文件中的定义SysMdbNetPartyLinkStatusInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysMdbNetPartyLinkStatusInfoResource;

	///将一个CSysMdbNetPartyLinkStatusInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbNetPartyLinkStatusInfo	要加入的SysMdbNetPartyLinkStatusInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbNetPartyLinkStatusInfo *add(CWriteableSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo, CTransaction *pTransaction=NULL);
	
	///刷新该CSysMdbNetPartyLinkStatusInfo的值
	///@param	pSysMdbNetPartyLinkStatusInfo	被刷新的CSysMdbNetPartyLinkStatusInfo
	///@param	pNewSysMdbNetPartyLinkStatusInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo, CWriteableSysMdbNetPartyLinkStatusInfo *pNewSysMdbNetPartyLinkStatusInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysMdbNetPartyLinkStatusInfo	  需要被刷新或者新增的CSysMdbNetPartyLinkStatusInfo,等于NULL表示是需要新增的
	///@param	pNewSysMdbNetPartyLinkStatusInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysMdbNetPartyLinkStatusInfo* addOrUpdate(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo, CWriteableSysMdbNetPartyLinkStatusInfo *pNewSysMdbNetPartyLinkStatusInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysMdbNetPartyLinkStatusInfo，同时删除其索引
	///@param	pSysMdbNetPartyLinkStatusInfo	要删除的CSysMdbNetPartyLinkStatusInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo, CTransaction *pTransaction=NULL);
	
	///获取某个CSysMdbNetPartyLinkStatusInfo
	///@param	pSysMdbNetPartyLinkStatusInfo	要读取的CSysMdbNetPartyLinkStatusInfo
	///@param	pTragetSysMdbNetPartyLinkStatusInfo	存放结果的CSysMdbNetPartyLinkStatusInfo
	void retrieve(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo, CWriteableSysMdbNetPartyLinkStatusInfo *pTargetSysMdbNetPartyLinkStatusInfo);
	
	///获取第一个CSysMdbNetPartyLinkStatusInfo
	///@return	得到的第一个CSysMdbNetPartyLinkStatusInfo，如果没有，则返回NULL
	CSysMdbNetPartyLinkStatusInfo *getFirst(void);
	
	///获取下一个CSysMdbNetPartyLinkStatusInfo
	///@return	得到下一个CSysMdbNetPartyLinkStatusInfo，如果没有，则返回NULL
	CSysMdbNetPartyLinkStatusInfo *getNext(void);
	
	///结束获取CSysMdbNetPartyLinkStatusInfo
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysMdbNetPartyLinkStatusInfoActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysMdbNetPartyLinkStatusInfoActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysMdbNetPartyLinkStatusInfoCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysMdbNetPartyLinkStatusInfoCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysMdbNetPartyLinkStatusInfoIteratorByTime;

	///开始寻找CSysMdbNetPartyLinkStatusInfo
	///@param	MonDate	
	///@param	MonTime	
	///@return	满足条件的地一个CSysMdbNetPartyLinkStatusInfo，如果找不到，返回NULL
	CSysMdbNetPartyLinkStatusInfo *startFindByTime( const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysMdbNetPartyLinkStatusInfo，必须在startFindByTime以后，endFindByTime之前叫用
	///@return	下一个满足条件CSysMdbNetPartyLinkStatusInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbNetPartyLinkStatusInfo *findNextByTime(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByTime(void);

	friend class CSysMdbNetPartyLinkStatusInfoIteratorByDsc;

	///开始寻找CSysMdbNetPartyLinkStatusInfo
	///@param	SubcriberID	
	///@return	满足条件的地一个CSysMdbNetPartyLinkStatusInfo，如果找不到，返回NULL
	CSysMdbNetPartyLinkStatusInfo *startFindByDsc( const CReadOnlyVolumeType& SubcriberID);

	///寻找下一个符合条件的CSysMdbNetPartyLinkStatusInfo，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbNetPartyLinkStatusInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbNetPartyLinkStatusInfo *findNextByDsc(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDsc(void);

	friend class CSysMdbNetPartyLinkStatusInfoIteratorByAll;

	///开始寻找CSysMdbNetPartyLinkStatusInfo
	///@return	满足条件的地一个CSysMdbNetPartyLinkStatusInfo，如果找不到，返回NULL
	CSysMdbNetPartyLinkStatusInfo *startFindByAll();

	///寻找下一个符合条件的CSysMdbNetPartyLinkStatusInfo，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysMdbNetPartyLinkStatusInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbNetPartyLinkStatusInfo *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysMdbNetPartyLinkStatusInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbNetPartyLinkStatusInfo	要加入的SysMdbNetPartyLinkStatusInfo
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbNetPartyLinkStatusInfo *internalAdd(CWriteableSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo, bool bNoTransaction);
	
	
	///刷新该CSysMdbNetPartyLinkStatusInfo的键值
	///@param	pSysMdbNetPartyLinkStatusInfo	被刷新的CSysMdbNetPartyLinkStatusInfo
	///@param	pNewSysMdbNetPartyLinkStatusInfo	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo, CWriteableSysMdbNetPartyLinkStatusInfo *pNewSysMdbNetPartyLinkStatusInfo, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysMdbNetPartyLinkStatusInfo，同时删除其索引
	///@param	pSysMdbNetPartyLinkStatusInfo	要删除的CSysMdbNetPartyLinkStatusInfo
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo, bool bNoTransaction);
/*
	///检查某个CSysMdbNetPartyLinkStatusInfo是否属于本对象工厂
	///@param	pSysMdbNetPartyLinkStatusInfo	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于MonDate+MonTime的索引
	CAVLTree *pSysDateTimeIndex;
	///基于SubcriberID+MonDate+MonTime的索引
	CAVLTree *pDecIndex;
	
	
	///按照MonDate，MonTime检索时，存储的查询参数
	CDateType queryMonDateInSearchByTime;
	CTimeType queryMonTimeInSearchByTime;
	
	///按照MonDate，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByTime;
	///按照SubcriberID检索时，存储的查询参数
	CVolumeType querySubcriberIDInSearchByDsc;
	
	///按照SubcriberID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDsc;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysMdbNetPartyLinkStatusInfo	要加入的SysMdbNetPartyLinkStatusInfo
	virtual void beforeAdd(CWriteableSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo);
	
	///加入后触发
	///@param	pSysMdbNetPartyLinkStatusInfo	已经加入的SysMdbNetPartyLinkStatusInfo
	virtual void afterAdd(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo);

	///更新前触发	
	///@param	pSysMdbNetPartyLinkStatusInfo	被刷新的CSysMdbNetPartyLinkStatusInfo
	///@param	pNewSysMdbNetPartyLinkStatusInfo	新的值
	virtual void beforeUpdate(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo, CWriteableSysMdbNetPartyLinkStatusInfo *pNewSysMdbNetPartyLinkStatusInfo);
	
	///更新后触发
	///@param	pSysMdbNetPartyLinkStatusInfo	被刷新的CSysMdbNetPartyLinkStatusInfo
	virtual void afterUpdate(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo);
	
	///删除前触发
	///@param	pSysMdbNetPartyLinkStatusInfo	要删除的CSysMdbNetPartyLinkStatusInfo
	virtual void beforeRemove(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo);
	
	///确认加入后触发
	///@param	pSysMdbNetPartyLinkStatusInfo	已经加入的SysMdbNetPartyLinkStatusInfo
	virtual void commitAdd(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo);

	///确认更新后触发
	///@param	pSysMdbNetPartyLinkStatusInfo	被刷新的CSysMdbNetPartyLinkStatusInfo
	///@param	poldSysMdbNetPartyLinkStatusInfo	原来的值
	virtual void commitUpdate(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo, CWriteableSysMdbNetPartyLinkStatusInfo *pOldSysMdbNetPartyLinkStatusInfo);
	
	///确认删除后触发
	///@param	pSysMdbNetPartyLinkStatusInfo	已经删除的CSysMdbNetPartyLinkStatusInfo
	virtual void commitRemove(CWriteableSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo);

	///所有相关的触发器
	vector<CSysMdbNetPartyLinkStatusInfoActionTrigger *> *pActionTriggers;
	vector<CSysMdbNetPartyLinkStatusInfoCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysMdbNetPartyLinkStatusInfo compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMemberSDHLineInfoFactory是一个会员SDH线路明细表的对象工厂。它包含了一批会员SDH线路明细表，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对会员SDH线路明细表的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMemberSDHLineInfoFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetMemberSDHLineInfoFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetMemberSDHLineInfo，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetMemberSDHLineInfoFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMemberSDHLineInfoFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetMemberSDHLineInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetMemberSDHLineInfo，文件名将根据配置文件中的定义SysNetMemberSDHLineInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetMemberSDHLineInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetMemberSDHLineInfo，文件名将根据配置文件中的定义SysNetMemberSDHLineInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetMemberSDHLineInfoResource;

	///将一个CSysNetMemberSDHLineInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetMemberSDHLineInfo	要加入的SysNetMemberSDHLineInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetMemberSDHLineInfo *add(CWriteableSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetMemberSDHLineInfo的值
	///@param	pSysNetMemberSDHLineInfo	被刷新的CSysNetMemberSDHLineInfo
	///@param	pNewSysNetMemberSDHLineInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo, CWriteableSysNetMemberSDHLineInfo *pNewSysNetMemberSDHLineInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetMemberSDHLineInfo	  需要被刷新或者新增的CSysNetMemberSDHLineInfo,等于NULL表示是需要新增的
	///@param	pNewSysNetMemberSDHLineInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetMemberSDHLineInfo* addOrUpdate(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo, CWriteableSysNetMemberSDHLineInfo *pNewSysNetMemberSDHLineInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetMemberSDHLineInfo，同时删除其索引
	///@param	pSysNetMemberSDHLineInfo	要删除的CSysNetMemberSDHLineInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetMemberSDHLineInfo
	///@param	pSysNetMemberSDHLineInfo	要读取的CSysNetMemberSDHLineInfo
	///@param	pTragetSysNetMemberSDHLineInfo	存放结果的CSysNetMemberSDHLineInfo
	void retrieve(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo, CWriteableSysNetMemberSDHLineInfo *pTargetSysNetMemberSDHLineInfo);
	
	///获取第一个CSysNetMemberSDHLineInfo
	///@return	得到的第一个CSysNetMemberSDHLineInfo，如果没有，则返回NULL
	CSysNetMemberSDHLineInfo *getFirst(void);
	
	///获取下一个CSysNetMemberSDHLineInfo
	///@return	得到下一个CSysNetMemberSDHLineInfo，如果没有，则返回NULL
	CSysNetMemberSDHLineInfo *getNext(void);
	
	///结束获取CSysNetMemberSDHLineInfo
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetMemberSDHLineInfoActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetMemberSDHLineInfoActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetMemberSDHLineInfoCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetMemberSDHLineInfoCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetMemberSDHLineInfoIteratorByAll;

	///开始寻找CSysNetMemberSDHLineInfo
	///@return	满足条件的地一个CSysNetMemberSDHLineInfo，如果找不到，返回NULL
	CSysNetMemberSDHLineInfo *startFindByAll();

	///寻找下一个符合条件的CSysNetMemberSDHLineInfo，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetMemberSDHLineInfo，如果已经没有一个满足要求了，则返回NULL
	CSysNetMemberSDHLineInfo *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetMemberSDHLineInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetMemberSDHLineInfo	要加入的SysNetMemberSDHLineInfo
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetMemberSDHLineInfo *internalAdd(CWriteableSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo, bool bNoTransaction);
	
	
	///刷新该CSysNetMemberSDHLineInfo的键值
	///@param	pSysNetMemberSDHLineInfo	被刷新的CSysNetMemberSDHLineInfo
	///@param	pNewSysNetMemberSDHLineInfo	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo, CWriteableSysNetMemberSDHLineInfo *pNewSysNetMemberSDHLineInfo, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetMemberSDHLineInfo，同时删除其索引
	///@param	pSysNetMemberSDHLineInfo	要删除的CSysNetMemberSDHLineInfo
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo, bool bNoTransaction);
/*
	///检查某个CSysNetMemberSDHLineInfo是否属于本对象工厂
	///@param	pSysNetMemberSDHLineInfo	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetMemberSDHLineInfo	要加入的SysNetMemberSDHLineInfo
	virtual void beforeAdd(CWriteableSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo);
	
	///加入后触发
	///@param	pSysNetMemberSDHLineInfo	已经加入的SysNetMemberSDHLineInfo
	virtual void afterAdd(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo);

	///更新前触发	
	///@param	pSysNetMemberSDHLineInfo	被刷新的CSysNetMemberSDHLineInfo
	///@param	pNewSysNetMemberSDHLineInfo	新的值
	virtual void beforeUpdate(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo, CWriteableSysNetMemberSDHLineInfo *pNewSysNetMemberSDHLineInfo);
	
	///更新后触发
	///@param	pSysNetMemberSDHLineInfo	被刷新的CSysNetMemberSDHLineInfo
	virtual void afterUpdate(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo);
	
	///删除前触发
	///@param	pSysNetMemberSDHLineInfo	要删除的CSysNetMemberSDHLineInfo
	virtual void beforeRemove(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo);
	
	///确认加入后触发
	///@param	pSysNetMemberSDHLineInfo	已经加入的SysNetMemberSDHLineInfo
	virtual void commitAdd(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo);

	///确认更新后触发
	///@param	pSysNetMemberSDHLineInfo	被刷新的CSysNetMemberSDHLineInfo
	///@param	poldSysNetMemberSDHLineInfo	原来的值
	virtual void commitUpdate(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo, CWriteableSysNetMemberSDHLineInfo *pOldSysNetMemberSDHLineInfo);
	
	///确认删除后触发
	///@param	pSysNetMemberSDHLineInfo	已经删除的CSysNetMemberSDHLineInfo
	virtual void commitRemove(CWriteableSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo);

	///所有相关的触发器
	vector<CSysNetMemberSDHLineInfoActionTrigger *> *pActionTriggers;
	vector<CSysNetMemberSDHLineInfoCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetMemberSDHLineInfo compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDDNLinkInfoFactory是一个DDN链路信息表的对象工厂。它包含了一批DDN链路信息表，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对DDN链路信息表的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDDNLinkInfoFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetDDNLinkInfoFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetDDNLinkInfo，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetDDNLinkInfoFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetDDNLinkInfoFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetDDNLinkInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetDDNLinkInfo，文件名将根据配置文件中的定义SysNetDDNLinkInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetDDNLinkInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetDDNLinkInfo，文件名将根据配置文件中的定义SysNetDDNLinkInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetDDNLinkInfoResource;

	///将一个CSysNetDDNLinkInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetDDNLinkInfo	要加入的SysNetDDNLinkInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetDDNLinkInfo *add(CWriteableSysNetDDNLinkInfo *pSysNetDDNLinkInfo, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetDDNLinkInfo的值
	///@param	pSysNetDDNLinkInfo	被刷新的CSysNetDDNLinkInfo
	///@param	pNewSysNetDDNLinkInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo, CWriteableSysNetDDNLinkInfo *pNewSysNetDDNLinkInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetDDNLinkInfo	  需要被刷新或者新增的CSysNetDDNLinkInfo,等于NULL表示是需要新增的
	///@param	pNewSysNetDDNLinkInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetDDNLinkInfo* addOrUpdate(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo, CWriteableSysNetDDNLinkInfo *pNewSysNetDDNLinkInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetDDNLinkInfo，同时删除其索引
	///@param	pSysNetDDNLinkInfo	要删除的CSysNetDDNLinkInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetDDNLinkInfo
	///@param	pSysNetDDNLinkInfo	要读取的CSysNetDDNLinkInfo
	///@param	pTragetSysNetDDNLinkInfo	存放结果的CSysNetDDNLinkInfo
	void retrieve(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo, CWriteableSysNetDDNLinkInfo *pTargetSysNetDDNLinkInfo);
	
	///获取第一个CSysNetDDNLinkInfo
	///@return	得到的第一个CSysNetDDNLinkInfo，如果没有，则返回NULL
	CSysNetDDNLinkInfo *getFirst(void);
	
	///获取下一个CSysNetDDNLinkInfo
	///@return	得到下一个CSysNetDDNLinkInfo，如果没有，则返回NULL
	CSysNetDDNLinkInfo *getNext(void);
	
	///结束获取CSysNetDDNLinkInfo
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetDDNLinkInfoActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetDDNLinkInfoActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetDDNLinkInfoCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetDDNLinkInfoCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetDDNLinkInfoIteratorByAll;

	///开始寻找CSysNetDDNLinkInfo
	///@return	满足条件的地一个CSysNetDDNLinkInfo，如果找不到，返回NULL
	CSysNetDDNLinkInfo *startFindByAll();

	///寻找下一个符合条件的CSysNetDDNLinkInfo，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetDDNLinkInfo，如果已经没有一个满足要求了，则返回NULL
	CSysNetDDNLinkInfo *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetDDNLinkInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetDDNLinkInfo	要加入的SysNetDDNLinkInfo
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetDDNLinkInfo *internalAdd(CWriteableSysNetDDNLinkInfo *pSysNetDDNLinkInfo, bool bNoTransaction);
	
	
	///刷新该CSysNetDDNLinkInfo的键值
	///@param	pSysNetDDNLinkInfo	被刷新的CSysNetDDNLinkInfo
	///@param	pNewSysNetDDNLinkInfo	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo, CWriteableSysNetDDNLinkInfo *pNewSysNetDDNLinkInfo, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetDDNLinkInfo，同时删除其索引
	///@param	pSysNetDDNLinkInfo	要删除的CSysNetDDNLinkInfo
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo, bool bNoTransaction);
/*
	///检查某个CSysNetDDNLinkInfo是否属于本对象工厂
	///@param	pSysNetDDNLinkInfo	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetDDNLinkInfo	要加入的SysNetDDNLinkInfo
	virtual void beforeAdd(CWriteableSysNetDDNLinkInfo *pSysNetDDNLinkInfo);
	
	///加入后触发
	///@param	pSysNetDDNLinkInfo	已经加入的SysNetDDNLinkInfo
	virtual void afterAdd(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo);

	///更新前触发	
	///@param	pSysNetDDNLinkInfo	被刷新的CSysNetDDNLinkInfo
	///@param	pNewSysNetDDNLinkInfo	新的值
	virtual void beforeUpdate(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo, CWriteableSysNetDDNLinkInfo *pNewSysNetDDNLinkInfo);
	
	///更新后触发
	///@param	pSysNetDDNLinkInfo	被刷新的CSysNetDDNLinkInfo
	virtual void afterUpdate(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo);
	
	///删除前触发
	///@param	pSysNetDDNLinkInfo	要删除的CSysNetDDNLinkInfo
	virtual void beforeRemove(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo);
	
	///确认加入后触发
	///@param	pSysNetDDNLinkInfo	已经加入的SysNetDDNLinkInfo
	virtual void commitAdd(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo);

	///确认更新后触发
	///@param	pSysNetDDNLinkInfo	被刷新的CSysNetDDNLinkInfo
	///@param	poldSysNetDDNLinkInfo	原来的值
	virtual void commitUpdate(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo, CWriteableSysNetDDNLinkInfo *pOldSysNetDDNLinkInfo);
	
	///确认删除后触发
	///@param	pSysNetDDNLinkInfo	已经删除的CSysNetDDNLinkInfo
	virtual void commitRemove(CWriteableSysNetDDNLinkInfo *pSysNetDDNLinkInfo);

	///所有相关的触发器
	vector<CSysNetDDNLinkInfoActionTrigger *> *pActionTriggers;
	vector<CSysNetDDNLinkInfoCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetDDNLinkInfo compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPseudMemberLinkInfoFactory是一个非会员线路使用信息的对象工厂。它包含了一批非会员线路使用信息，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对非会员线路使用信息的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPseudMemberLinkInfoFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetPseudMemberLinkInfoFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetPseudMemberLinkInfo，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetPseudMemberLinkInfoFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetPseudMemberLinkInfoFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetPseudMemberLinkInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetPseudMemberLinkInfo，文件名将根据配置文件中的定义SysNetPseudMemberLinkInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetPseudMemberLinkInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetPseudMemberLinkInfo，文件名将根据配置文件中的定义SysNetPseudMemberLinkInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetPseudMemberLinkInfoResource;

	///将一个CSysNetPseudMemberLinkInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetPseudMemberLinkInfo	要加入的SysNetPseudMemberLinkInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetPseudMemberLinkInfo *add(CWriteableSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetPseudMemberLinkInfo的值
	///@param	pSysNetPseudMemberLinkInfo	被刷新的CSysNetPseudMemberLinkInfo
	///@param	pNewSysNetPseudMemberLinkInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo, CWriteableSysNetPseudMemberLinkInfo *pNewSysNetPseudMemberLinkInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetPseudMemberLinkInfo	  需要被刷新或者新增的CSysNetPseudMemberLinkInfo,等于NULL表示是需要新增的
	///@param	pNewSysNetPseudMemberLinkInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetPseudMemberLinkInfo* addOrUpdate(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo, CWriteableSysNetPseudMemberLinkInfo *pNewSysNetPseudMemberLinkInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetPseudMemberLinkInfo，同时删除其索引
	///@param	pSysNetPseudMemberLinkInfo	要删除的CSysNetPseudMemberLinkInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetPseudMemberLinkInfo
	///@param	pSysNetPseudMemberLinkInfo	要读取的CSysNetPseudMemberLinkInfo
	///@param	pTragetSysNetPseudMemberLinkInfo	存放结果的CSysNetPseudMemberLinkInfo
	void retrieve(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo, CWriteableSysNetPseudMemberLinkInfo *pTargetSysNetPseudMemberLinkInfo);
	
	///获取第一个CSysNetPseudMemberLinkInfo
	///@return	得到的第一个CSysNetPseudMemberLinkInfo，如果没有，则返回NULL
	CSysNetPseudMemberLinkInfo *getFirst(void);
	
	///获取下一个CSysNetPseudMemberLinkInfo
	///@return	得到下一个CSysNetPseudMemberLinkInfo，如果没有，则返回NULL
	CSysNetPseudMemberLinkInfo *getNext(void);
	
	///结束获取CSysNetPseudMemberLinkInfo
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetPseudMemberLinkInfoActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetPseudMemberLinkInfoActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetPseudMemberLinkInfoCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetPseudMemberLinkInfoCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetPseudMemberLinkInfoIteratorByAll;

	///开始寻找CSysNetPseudMemberLinkInfo
	///@return	满足条件的地一个CSysNetPseudMemberLinkInfo，如果找不到，返回NULL
	CSysNetPseudMemberLinkInfo *startFindByAll();

	///寻找下一个符合条件的CSysNetPseudMemberLinkInfo，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetPseudMemberLinkInfo，如果已经没有一个满足要求了，则返回NULL
	CSysNetPseudMemberLinkInfo *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetPseudMemberLinkInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetPseudMemberLinkInfo	要加入的SysNetPseudMemberLinkInfo
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetPseudMemberLinkInfo *internalAdd(CWriteableSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo, bool bNoTransaction);
	
	
	///刷新该CSysNetPseudMemberLinkInfo的键值
	///@param	pSysNetPseudMemberLinkInfo	被刷新的CSysNetPseudMemberLinkInfo
	///@param	pNewSysNetPseudMemberLinkInfo	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo, CWriteableSysNetPseudMemberLinkInfo *pNewSysNetPseudMemberLinkInfo, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetPseudMemberLinkInfo，同时删除其索引
	///@param	pSysNetPseudMemberLinkInfo	要删除的CSysNetPseudMemberLinkInfo
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo, bool bNoTransaction);
/*
	///检查某个CSysNetPseudMemberLinkInfo是否属于本对象工厂
	///@param	pSysNetPseudMemberLinkInfo	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetPseudMemberLinkInfo	要加入的SysNetPseudMemberLinkInfo
	virtual void beforeAdd(CWriteableSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo);
	
	///加入后触发
	///@param	pSysNetPseudMemberLinkInfo	已经加入的SysNetPseudMemberLinkInfo
	virtual void afterAdd(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo);

	///更新前触发	
	///@param	pSysNetPseudMemberLinkInfo	被刷新的CSysNetPseudMemberLinkInfo
	///@param	pNewSysNetPseudMemberLinkInfo	新的值
	virtual void beforeUpdate(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo, CWriteableSysNetPseudMemberLinkInfo *pNewSysNetPseudMemberLinkInfo);
	
	///更新后触发
	///@param	pSysNetPseudMemberLinkInfo	被刷新的CSysNetPseudMemberLinkInfo
	virtual void afterUpdate(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo);
	
	///删除前触发
	///@param	pSysNetPseudMemberLinkInfo	要删除的CSysNetPseudMemberLinkInfo
	virtual void beforeRemove(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo);
	
	///确认加入后触发
	///@param	pSysNetPseudMemberLinkInfo	已经加入的SysNetPseudMemberLinkInfo
	virtual void commitAdd(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo);

	///确认更新后触发
	///@param	pSysNetPseudMemberLinkInfo	被刷新的CSysNetPseudMemberLinkInfo
	///@param	poldSysNetPseudMemberLinkInfo	原来的值
	virtual void commitUpdate(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo, CWriteableSysNetPseudMemberLinkInfo *pOldSysNetPseudMemberLinkInfo);
	
	///确认删除后触发
	///@param	pSysNetPseudMemberLinkInfo	已经删除的CSysNetPseudMemberLinkInfo
	virtual void commitRemove(CWriteableSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo);

	///所有相关的触发器
	vector<CSysNetPseudMemberLinkInfoActionTrigger *> *pActionTriggers;
	vector<CSysNetPseudMemberLinkInfoCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetPseudMemberLinkInfo compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOuterDeviceInfoFactory是一个远端设备信息的对象工厂。它包含了一批远端设备信息，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对远端设备信息的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOuterDeviceInfoFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetOuterDeviceInfoFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetOuterDeviceInfo，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetOuterDeviceInfoFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetOuterDeviceInfoFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetOuterDeviceInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetOuterDeviceInfo，文件名将根据配置文件中的定义SysNetOuterDeviceInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetOuterDeviceInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetOuterDeviceInfo，文件名将根据配置文件中的定义SysNetOuterDeviceInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetOuterDeviceInfoResource;

	///将一个CSysNetOuterDeviceInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetOuterDeviceInfo	要加入的SysNetOuterDeviceInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetOuterDeviceInfo *add(CWriteableSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetOuterDeviceInfo的值
	///@param	pSysNetOuterDeviceInfo	被刷新的CSysNetOuterDeviceInfo
	///@param	pNewSysNetOuterDeviceInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo, CWriteableSysNetOuterDeviceInfo *pNewSysNetOuterDeviceInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetOuterDeviceInfo	  需要被刷新或者新增的CSysNetOuterDeviceInfo,等于NULL表示是需要新增的
	///@param	pNewSysNetOuterDeviceInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetOuterDeviceInfo* addOrUpdate(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo, CWriteableSysNetOuterDeviceInfo *pNewSysNetOuterDeviceInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetOuterDeviceInfo，同时删除其索引
	///@param	pSysNetOuterDeviceInfo	要删除的CSysNetOuterDeviceInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetOuterDeviceInfo
	///@param	pSysNetOuterDeviceInfo	要读取的CSysNetOuterDeviceInfo
	///@param	pTragetSysNetOuterDeviceInfo	存放结果的CSysNetOuterDeviceInfo
	void retrieve(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo, CWriteableSysNetOuterDeviceInfo *pTargetSysNetOuterDeviceInfo);
	
	///获取第一个CSysNetOuterDeviceInfo
	///@return	得到的第一个CSysNetOuterDeviceInfo，如果没有，则返回NULL
	CSysNetOuterDeviceInfo *getFirst(void);
	
	///获取下一个CSysNetOuterDeviceInfo
	///@return	得到下一个CSysNetOuterDeviceInfo，如果没有，则返回NULL
	CSysNetOuterDeviceInfo *getNext(void);
	
	///结束获取CSysNetOuterDeviceInfo
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetOuterDeviceInfoActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetOuterDeviceInfoActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetOuterDeviceInfoCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetOuterDeviceInfoCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetOuterDeviceInfoIteratorByAll;

	///开始寻找CSysNetOuterDeviceInfo
	///@return	满足条件的地一个CSysNetOuterDeviceInfo，如果找不到，返回NULL
	CSysNetOuterDeviceInfo *startFindByAll();

	///寻找下一个符合条件的CSysNetOuterDeviceInfo，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetOuterDeviceInfo，如果已经没有一个满足要求了，则返回NULL
	CSysNetOuterDeviceInfo *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetOuterDeviceInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetOuterDeviceInfo	要加入的SysNetOuterDeviceInfo
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetOuterDeviceInfo *internalAdd(CWriteableSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo, bool bNoTransaction);
	
	
	///刷新该CSysNetOuterDeviceInfo的键值
	///@param	pSysNetOuterDeviceInfo	被刷新的CSysNetOuterDeviceInfo
	///@param	pNewSysNetOuterDeviceInfo	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo, CWriteableSysNetOuterDeviceInfo *pNewSysNetOuterDeviceInfo, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetOuterDeviceInfo，同时删除其索引
	///@param	pSysNetOuterDeviceInfo	要删除的CSysNetOuterDeviceInfo
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo, bool bNoTransaction);
/*
	///检查某个CSysNetOuterDeviceInfo是否属于本对象工厂
	///@param	pSysNetOuterDeviceInfo	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetOuterDeviceInfo	要加入的SysNetOuterDeviceInfo
	virtual void beforeAdd(CWriteableSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo);
	
	///加入后触发
	///@param	pSysNetOuterDeviceInfo	已经加入的SysNetOuterDeviceInfo
	virtual void afterAdd(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo);

	///更新前触发	
	///@param	pSysNetOuterDeviceInfo	被刷新的CSysNetOuterDeviceInfo
	///@param	pNewSysNetOuterDeviceInfo	新的值
	virtual void beforeUpdate(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo, CWriteableSysNetOuterDeviceInfo *pNewSysNetOuterDeviceInfo);
	
	///更新后触发
	///@param	pSysNetOuterDeviceInfo	被刷新的CSysNetOuterDeviceInfo
	virtual void afterUpdate(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo);
	
	///删除前触发
	///@param	pSysNetOuterDeviceInfo	要删除的CSysNetOuterDeviceInfo
	virtual void beforeRemove(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo);
	
	///确认加入后触发
	///@param	pSysNetOuterDeviceInfo	已经加入的SysNetOuterDeviceInfo
	virtual void commitAdd(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo);

	///确认更新后触发
	///@param	pSysNetOuterDeviceInfo	被刷新的CSysNetOuterDeviceInfo
	///@param	poldSysNetOuterDeviceInfo	原来的值
	virtual void commitUpdate(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo, CWriteableSysNetOuterDeviceInfo *pOldSysNetOuterDeviceInfo);
	
	///确认删除后触发
	///@param	pSysNetOuterDeviceInfo	已经删除的CSysNetOuterDeviceInfo
	virtual void commitRemove(CWriteableSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo);

	///所有相关的触发器
	vector<CSysNetOuterDeviceInfoActionTrigger *> *pActionTriggers;
	vector<CSysNetOuterDeviceInfoCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetOuterDeviceInfo compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysLocalPingResultInfoFactory是一个本地ping结果的对象工厂。它包含了一批本地ping结果，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对本地ping结果的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用startFindByIDType，findNextByIDType和endFindByIDType完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysLocalPingResultInfoFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysLocalPingResultInfoFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysLocalPingResultInfo，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysLocalPingResultInfoFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysLocalPingResultInfoFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysLocalPingResultInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysLocalPingResultInfo，文件名将根据配置文件中的定义SysLocalPingResultInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysLocalPingResultInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysLocalPingResultInfo，文件名将根据配置文件中的定义SysLocalPingResultInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysLocalPingResultInfoResource;

	///将一个CSysLocalPingResultInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysLocalPingResultInfo	要加入的SysLocalPingResultInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysLocalPingResultInfo *add(CWriteableSysLocalPingResultInfo *pSysLocalPingResultInfo, CTransaction *pTransaction=NULL);
	
	///刷新该CSysLocalPingResultInfo的值
	///@param	pSysLocalPingResultInfo	被刷新的CSysLocalPingResultInfo
	///@param	pNewSysLocalPingResultInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysLocalPingResultInfo *pSysLocalPingResultInfo, CWriteableSysLocalPingResultInfo *pNewSysLocalPingResultInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysLocalPingResultInfo	  需要被刷新或者新增的CSysLocalPingResultInfo,等于NULL表示是需要新增的
	///@param	pNewSysLocalPingResultInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysLocalPingResultInfo* addOrUpdate(CSysLocalPingResultInfo *pSysLocalPingResultInfo, CWriteableSysLocalPingResultInfo *pNewSysLocalPingResultInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysLocalPingResultInfo，同时删除其索引
	///@param	pSysLocalPingResultInfo	要删除的CSysLocalPingResultInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysLocalPingResultInfo *pSysLocalPingResultInfo, CTransaction *pTransaction=NULL);
	
	///获取某个CSysLocalPingResultInfo
	///@param	pSysLocalPingResultInfo	要读取的CSysLocalPingResultInfo
	///@param	pTragetSysLocalPingResultInfo	存放结果的CSysLocalPingResultInfo
	void retrieve(CSysLocalPingResultInfo *pSysLocalPingResultInfo, CWriteableSysLocalPingResultInfo *pTargetSysLocalPingResultInfo);
	
	///获取第一个CSysLocalPingResultInfo
	///@return	得到的第一个CSysLocalPingResultInfo，如果没有，则返回NULL
	CSysLocalPingResultInfo *getFirst(void);
	
	///获取下一个CSysLocalPingResultInfo
	///@return	得到下一个CSysLocalPingResultInfo，如果没有，则返回NULL
	CSysLocalPingResultInfo *getNext(void);
	
	///结束获取CSysLocalPingResultInfo
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysLocalPingResultInfoActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysLocalPingResultInfoActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysLocalPingResultInfoCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysLocalPingResultInfoCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysLocalPingResultInfoIteratorByAll;

	///开始寻找CSysLocalPingResultInfo
	///@return	满足条件的地一个CSysLocalPingResultInfo，如果找不到，返回NULL
	CSysLocalPingResultInfo *startFindByAll();

	///寻找下一个符合条件的CSysLocalPingResultInfo，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysLocalPingResultInfo，如果已经没有一个满足要求了，则返回NULL
	CSysLocalPingResultInfo *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	friend class CSysLocalPingResultInfoIteratorByIDType;

	///开始寻找CSysLocalPingResultInfo
	///@param	ID	
	///@return	满足条件的地一个CSysLocalPingResultInfo，如果找不到，返回NULL
	CSysLocalPingResultInfo *startFindByIDType( const CReadOnlyVolumeType& ID);

	///寻找下一个符合条件的CSysLocalPingResultInfo，必须在startFindByIDType以后，endFindByIDType之前叫用
	///@return	下一个满足条件CSysLocalPingResultInfo，如果已经没有一个满足要求了，则返回NULL
	CSysLocalPingResultInfo *findNextByIDType(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByIDType(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysLocalPingResultInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysLocalPingResultInfo	要加入的SysLocalPingResultInfo
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysLocalPingResultInfo *internalAdd(CWriteableSysLocalPingResultInfo *pSysLocalPingResultInfo, bool bNoTransaction);
	
	
	///刷新该CSysLocalPingResultInfo的键值
	///@param	pSysLocalPingResultInfo	被刷新的CSysLocalPingResultInfo
	///@param	pNewSysLocalPingResultInfo	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysLocalPingResultInfo *pSysLocalPingResultInfo, CWriteableSysLocalPingResultInfo *pNewSysLocalPingResultInfo, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysLocalPingResultInfo，同时删除其索引
	///@param	pSysLocalPingResultInfo	要删除的CSysLocalPingResultInfo
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysLocalPingResultInfo *pSysLocalPingResultInfo, bool bNoTransaction);
/*
	///检查某个CSysLocalPingResultInfo是否属于本对象工厂
	///@param	pSysLocalPingResultInfo	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysLocalPingResultInfo *pSysLocalPingResultInfo);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	///按照ID检索时，存储的查询参数
	CVolumeType queryIDInSearchByIDType;
	
	///按照ID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByIDType;
	
	///加入前触发
	///@param	pSysLocalPingResultInfo	要加入的SysLocalPingResultInfo
	virtual void beforeAdd(CWriteableSysLocalPingResultInfo *pSysLocalPingResultInfo);
	
	///加入后触发
	///@param	pSysLocalPingResultInfo	已经加入的SysLocalPingResultInfo
	virtual void afterAdd(CSysLocalPingResultInfo *pSysLocalPingResultInfo);

	///更新前触发	
	///@param	pSysLocalPingResultInfo	被刷新的CSysLocalPingResultInfo
	///@param	pNewSysLocalPingResultInfo	新的值
	virtual void beforeUpdate(CSysLocalPingResultInfo *pSysLocalPingResultInfo, CWriteableSysLocalPingResultInfo *pNewSysLocalPingResultInfo);
	
	///更新后触发
	///@param	pSysLocalPingResultInfo	被刷新的CSysLocalPingResultInfo
	virtual void afterUpdate(CSysLocalPingResultInfo *pSysLocalPingResultInfo);
	
	///删除前触发
	///@param	pSysLocalPingResultInfo	要删除的CSysLocalPingResultInfo
	virtual void beforeRemove(CSysLocalPingResultInfo *pSysLocalPingResultInfo);
	
	///确认加入后触发
	///@param	pSysLocalPingResultInfo	已经加入的SysLocalPingResultInfo
	virtual void commitAdd(CSysLocalPingResultInfo *pSysLocalPingResultInfo);

	///确认更新后触发
	///@param	pSysLocalPingResultInfo	被刷新的CSysLocalPingResultInfo
	///@param	poldSysLocalPingResultInfo	原来的值
	virtual void commitUpdate(CSysLocalPingResultInfo *pSysLocalPingResultInfo, CWriteableSysLocalPingResultInfo *pOldSysLocalPingResultInfo);
	
	///确认删除后触发
	///@param	pSysLocalPingResultInfo	已经删除的CSysLocalPingResultInfo
	virtual void commitRemove(CWriteableSysLocalPingResultInfo *pSysLocalPingResultInfo);

	///所有相关的触发器
	vector<CSysLocalPingResultInfoActionTrigger *> *pActionTriggers;
	vector<CSysLocalPingResultInfoCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysLocalPingResultInfo compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysRomotePingResultInfoFactory是一个远程ping结果的对象工厂。它包含了一批远程ping结果，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对远程ping结果的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用startFindByIDType，findNextByIDType和endFindByIDType完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysRomotePingResultInfoFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysRomotePingResultInfoFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysRomotePingResultInfo，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysRomotePingResultInfoFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysRomotePingResultInfoFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysRomotePingResultInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysRomotePingResultInfo，文件名将根据配置文件中的定义SysRomotePingResultInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysRomotePingResultInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysRomotePingResultInfo，文件名将根据配置文件中的定义SysRomotePingResultInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysRomotePingResultInfoResource;

	///将一个CSysRomotePingResultInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysRomotePingResultInfo	要加入的SysRomotePingResultInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysRomotePingResultInfo *add(CWriteableSysRomotePingResultInfo *pSysRomotePingResultInfo, CTransaction *pTransaction=NULL);
	
	///刷新该CSysRomotePingResultInfo的值
	///@param	pSysRomotePingResultInfo	被刷新的CSysRomotePingResultInfo
	///@param	pNewSysRomotePingResultInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysRomotePingResultInfo *pSysRomotePingResultInfo, CWriteableSysRomotePingResultInfo *pNewSysRomotePingResultInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysRomotePingResultInfo	  需要被刷新或者新增的CSysRomotePingResultInfo,等于NULL表示是需要新增的
	///@param	pNewSysRomotePingResultInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysRomotePingResultInfo* addOrUpdate(CSysRomotePingResultInfo *pSysRomotePingResultInfo, CWriteableSysRomotePingResultInfo *pNewSysRomotePingResultInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysRomotePingResultInfo，同时删除其索引
	///@param	pSysRomotePingResultInfo	要删除的CSysRomotePingResultInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysRomotePingResultInfo *pSysRomotePingResultInfo, CTransaction *pTransaction=NULL);
	
	///获取某个CSysRomotePingResultInfo
	///@param	pSysRomotePingResultInfo	要读取的CSysRomotePingResultInfo
	///@param	pTragetSysRomotePingResultInfo	存放结果的CSysRomotePingResultInfo
	void retrieve(CSysRomotePingResultInfo *pSysRomotePingResultInfo, CWriteableSysRomotePingResultInfo *pTargetSysRomotePingResultInfo);
	
	///获取第一个CSysRomotePingResultInfo
	///@return	得到的第一个CSysRomotePingResultInfo，如果没有，则返回NULL
	CSysRomotePingResultInfo *getFirst(void);
	
	///获取下一个CSysRomotePingResultInfo
	///@return	得到下一个CSysRomotePingResultInfo，如果没有，则返回NULL
	CSysRomotePingResultInfo *getNext(void);
	
	///结束获取CSysRomotePingResultInfo
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysRomotePingResultInfoActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysRomotePingResultInfoActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysRomotePingResultInfoCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysRomotePingResultInfoCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysRomotePingResultInfoIteratorByAll;

	///开始寻找CSysRomotePingResultInfo
	///@return	满足条件的地一个CSysRomotePingResultInfo，如果找不到，返回NULL
	CSysRomotePingResultInfo *startFindByAll();

	///寻找下一个符合条件的CSysRomotePingResultInfo，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysRomotePingResultInfo，如果已经没有一个满足要求了，则返回NULL
	CSysRomotePingResultInfo *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	friend class CSysRomotePingResultInfoIteratorByIDType;

	///开始寻找CSysRomotePingResultInfo
	///@param	ID	
	///@return	满足条件的地一个CSysRomotePingResultInfo，如果找不到，返回NULL
	CSysRomotePingResultInfo *startFindByIDType( const CReadOnlyVolumeType& ID);

	///寻找下一个符合条件的CSysRomotePingResultInfo，必须在startFindByIDType以后，endFindByIDType之前叫用
	///@return	下一个满足条件CSysRomotePingResultInfo，如果已经没有一个满足要求了，则返回NULL
	CSysRomotePingResultInfo *findNextByIDType(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByIDType(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysRomotePingResultInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysRomotePingResultInfo	要加入的SysRomotePingResultInfo
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysRomotePingResultInfo *internalAdd(CWriteableSysRomotePingResultInfo *pSysRomotePingResultInfo, bool bNoTransaction);
	
	
	///刷新该CSysRomotePingResultInfo的键值
	///@param	pSysRomotePingResultInfo	被刷新的CSysRomotePingResultInfo
	///@param	pNewSysRomotePingResultInfo	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysRomotePingResultInfo *pSysRomotePingResultInfo, CWriteableSysRomotePingResultInfo *pNewSysRomotePingResultInfo, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysRomotePingResultInfo，同时删除其索引
	///@param	pSysRomotePingResultInfo	要删除的CSysRomotePingResultInfo
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysRomotePingResultInfo *pSysRomotePingResultInfo, bool bNoTransaction);
/*
	///检查某个CSysRomotePingResultInfo是否属于本对象工厂
	///@param	pSysRomotePingResultInfo	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysRomotePingResultInfo *pSysRomotePingResultInfo);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	///按照ID检索时，存储的查询参数
	CVolumeType queryIDInSearchByIDType;
	
	///按照ID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByIDType;
	
	///加入前触发
	///@param	pSysRomotePingResultInfo	要加入的SysRomotePingResultInfo
	virtual void beforeAdd(CWriteableSysRomotePingResultInfo *pSysRomotePingResultInfo);
	
	///加入后触发
	///@param	pSysRomotePingResultInfo	已经加入的SysRomotePingResultInfo
	virtual void afterAdd(CSysRomotePingResultInfo *pSysRomotePingResultInfo);

	///更新前触发	
	///@param	pSysRomotePingResultInfo	被刷新的CSysRomotePingResultInfo
	///@param	pNewSysRomotePingResultInfo	新的值
	virtual void beforeUpdate(CSysRomotePingResultInfo *pSysRomotePingResultInfo, CWriteableSysRomotePingResultInfo *pNewSysRomotePingResultInfo);
	
	///更新后触发
	///@param	pSysRomotePingResultInfo	被刷新的CSysRomotePingResultInfo
	virtual void afterUpdate(CSysRomotePingResultInfo *pSysRomotePingResultInfo);
	
	///删除前触发
	///@param	pSysRomotePingResultInfo	要删除的CSysRomotePingResultInfo
	virtual void beforeRemove(CSysRomotePingResultInfo *pSysRomotePingResultInfo);
	
	///确认加入后触发
	///@param	pSysRomotePingResultInfo	已经加入的SysRomotePingResultInfo
	virtual void commitAdd(CSysRomotePingResultInfo *pSysRomotePingResultInfo);

	///确认更新后触发
	///@param	pSysRomotePingResultInfo	被刷新的CSysRomotePingResultInfo
	///@param	poldSysRomotePingResultInfo	原来的值
	virtual void commitUpdate(CSysRomotePingResultInfo *pSysRomotePingResultInfo, CWriteableSysRomotePingResultInfo *pOldSysRomotePingResultInfo);
	
	///确认删除后触发
	///@param	pSysRomotePingResultInfo	已经删除的CSysRomotePingResultInfo
	virtual void commitRemove(CWriteableSysRomotePingResultInfo *pSysRomotePingResultInfo);

	///所有相关的触发器
	vector<CSysRomotePingResultInfoActionTrigger *> *pActionTriggers;
	vector<CSysRomotePingResultInfoCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysRomotePingResultInfo compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticTradeOrderStatesFactory是一个会员席位交易状态的对象工厂。它包含了一批会员席位交易状态，
///同时又建立了如下索引，以方便查询：
///	MemUsrIndex
///使用本对象工厂，可以完成对会员席位交易状态的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///		使用startFindByUserID，findNextByUserID和endFindByUserID完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticTradeOrderStatesFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysParticTradeOrderStatesFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysParticTradeOrderStates，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysParticTradeOrderStatesFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysParticTradeOrderStatesFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysParticTradeOrderStates
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysParticTradeOrderStates，文件名将根据配置文件中的定义SysParticTradeOrderStatesCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysParticTradeOrderStates
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysParticTradeOrderStates，文件名将根据配置文件中的定义SysParticTradeOrderStatesCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysParticTradeOrderStatesResource;

	///将一个CSysParticTradeOrderStates加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysParticTradeOrderStates	要加入的SysParticTradeOrderStates
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysParticTradeOrderStates *add(CWriteableSysParticTradeOrderStates *pSysParticTradeOrderStates, CTransaction *pTransaction=NULL);
	
	///刷新该CSysParticTradeOrderStates的值
	///@param	pSysParticTradeOrderStates	被刷新的CSysParticTradeOrderStates
	///@param	pNewSysParticTradeOrderStates	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysParticTradeOrderStates *pSysParticTradeOrderStates, CWriteableSysParticTradeOrderStates *pNewSysParticTradeOrderStates, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysParticTradeOrderStates	  需要被刷新或者新增的CSysParticTradeOrderStates,等于NULL表示是需要新增的
	///@param	pNewSysParticTradeOrderStates	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysParticTradeOrderStates* addOrUpdate(CSysParticTradeOrderStates *pSysParticTradeOrderStates, CWriteableSysParticTradeOrderStates *pNewSysParticTradeOrderStates, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysParticTradeOrderStates，同时删除其索引
	///@param	pSysParticTradeOrderStates	要删除的CSysParticTradeOrderStates
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysParticTradeOrderStates *pSysParticTradeOrderStates, CTransaction *pTransaction=NULL);
	
	///获取某个CSysParticTradeOrderStates
	///@param	pSysParticTradeOrderStates	要读取的CSysParticTradeOrderStates
	///@param	pTragetSysParticTradeOrderStates	存放结果的CSysParticTradeOrderStates
	void retrieve(CSysParticTradeOrderStates *pSysParticTradeOrderStates, CWriteableSysParticTradeOrderStates *pTargetSysParticTradeOrderStates);
	
	///获取第一个CSysParticTradeOrderStates
	///@return	得到的第一个CSysParticTradeOrderStates，如果没有，则返回NULL
	CSysParticTradeOrderStates *getFirst(void);
	
	///获取下一个CSysParticTradeOrderStates
	///@return	得到下一个CSysParticTradeOrderStates，如果没有，则返回NULL
	CSysParticTradeOrderStates *getNext(void);
	
	///结束获取CSysParticTradeOrderStates
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysParticTradeOrderStatesActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysParticTradeOrderStatesActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysParticTradeOrderStatesCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysParticTradeOrderStatesCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysParticTradeOrderStatesIteratorByAll;

	///开始寻找CSysParticTradeOrderStates
	///@return	满足条件的地一个CSysParticTradeOrderStates，如果找不到，返回NULL
	CSysParticTradeOrderStates *startFindByAll();

	///寻找下一个符合条件的CSysParticTradeOrderStates，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysParticTradeOrderStates，如果已经没有一个满足要求了，则返回NULL
	CSysParticTradeOrderStates *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysParticTradeOrderStates
	///@param	ParticipantID	
	///@param	UserID	
	///@param	MonDate	
	///@param	MonTime	
	///@return	找到的CSysParticTradeOrderStates，如果找不到，返回NULL
	CSysParticTradeOrderStates *findByOne( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyUserIDType&  UserID,  const CReadOnlyDateType&  MonDate,  const CReadOnlyTimeType&  MonTime);



	friend class CSysParticTradeOrderStatesIteratorByUserID;

	///开始寻找CSysParticTradeOrderStates
	///@param	ParticipantID	
	///@param	UserID	
	///@param	MonDate	
	///@param	MonTime	
	///@return	满足条件的地一个CSysParticTradeOrderStates，如果找不到，返回NULL
	CSysParticTradeOrderStates *startFindByUserID( const CReadOnlyParticipantIDType& ParticipantID,  const CReadOnlyUserIDType& UserID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysParticTradeOrderStates，必须在startFindByUserID以后，endFindByUserID之前叫用
	///@return	下一个满足条件CSysParticTradeOrderStates，如果已经没有一个满足要求了，则返回NULL
	CSysParticTradeOrderStates *findNextByUserID(void);

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
	
	
	///将一个CSysParticTradeOrderStates加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysParticTradeOrderStates	要加入的SysParticTradeOrderStates
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysParticTradeOrderStates *internalAdd(CWriteableSysParticTradeOrderStates *pSysParticTradeOrderStates, bool bNoTransaction);
	
	
	///刷新该CSysParticTradeOrderStates的键值
	///@param	pSysParticTradeOrderStates	被刷新的CSysParticTradeOrderStates
	///@param	pNewSysParticTradeOrderStates	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysParticTradeOrderStates *pSysParticTradeOrderStates, CWriteableSysParticTradeOrderStates *pNewSysParticTradeOrderStates, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysParticTradeOrderStates，同时删除其索引
	///@param	pSysParticTradeOrderStates	要删除的CSysParticTradeOrderStates
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysParticTradeOrderStates *pSysParticTradeOrderStates, bool bNoTransaction);
/*
	///检查某个CSysParticTradeOrderStates是否属于本对象工厂
	///@param	pSysParticTradeOrderStates	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysParticTradeOrderStates *pSysParticTradeOrderStates);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ParticipantID+UserID+MonDate+MonTime的索引
	CAVLTree *pMemUsrIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	///按照ParticipantID，UserID，MonDate，MonTime检索时，存储的查询参数
	CParticipantIDType queryParticipantIDInSearchByUserID;
	CUserIDType queryUserIDInSearchByUserID;
	CDateType queryMonDateInSearchByUserID;
	CTimeType queryMonTimeInSearchByUserID;
	
	///按照ParticipantID，UserID，MonDate，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByUserID;
	
	///加入前触发
	///@param	pSysParticTradeOrderStates	要加入的SysParticTradeOrderStates
	virtual void beforeAdd(CWriteableSysParticTradeOrderStates *pSysParticTradeOrderStates);
	
	///加入后触发
	///@param	pSysParticTradeOrderStates	已经加入的SysParticTradeOrderStates
	virtual void afterAdd(CSysParticTradeOrderStates *pSysParticTradeOrderStates);

	///更新前触发	
	///@param	pSysParticTradeOrderStates	被刷新的CSysParticTradeOrderStates
	///@param	pNewSysParticTradeOrderStates	新的值
	virtual void beforeUpdate(CSysParticTradeOrderStates *pSysParticTradeOrderStates, CWriteableSysParticTradeOrderStates *pNewSysParticTradeOrderStates);
	
	///更新后触发
	///@param	pSysParticTradeOrderStates	被刷新的CSysParticTradeOrderStates
	virtual void afterUpdate(CSysParticTradeOrderStates *pSysParticTradeOrderStates);
	
	///删除前触发
	///@param	pSysParticTradeOrderStates	要删除的CSysParticTradeOrderStates
	virtual void beforeRemove(CSysParticTradeOrderStates *pSysParticTradeOrderStates);
	
	///确认加入后触发
	///@param	pSysParticTradeOrderStates	已经加入的SysParticTradeOrderStates
	virtual void commitAdd(CSysParticTradeOrderStates *pSysParticTradeOrderStates);

	///确认更新后触发
	///@param	pSysParticTradeOrderStates	被刷新的CSysParticTradeOrderStates
	///@param	poldSysParticTradeOrderStates	原来的值
	virtual void commitUpdate(CSysParticTradeOrderStates *pSysParticTradeOrderStates, CWriteableSysParticTradeOrderStates *pOldSysParticTradeOrderStates);
	
	///确认删除后触发
	///@param	pSysParticTradeOrderStates	已经删除的CSysParticTradeOrderStates
	virtual void commitRemove(CWriteableSysParticTradeOrderStates *pSysParticTradeOrderStates);

	///所有相关的触发器
	vector<CSysParticTradeOrderStatesActionTrigger *> *pActionTriggers;
	vector<CSysParticTradeOrderStatesCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysParticTradeOrderStates compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoFactory是一个系统路由信息的对象工厂。它包含了一批系统路由信息，
///同时又建立了如下索引，以方便查询：
///	SysHostNameIndex
///	DecIndex
///使用本对象工厂，可以完成对系统路由信息的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByHostName，findNextByHostName和endFindByHostName完成查询操作
///		使用startFindByDsc，findNextByDsc和endFindByDsc完成查询操作
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///		使用startFindByDataDelete，findNextByDataDelete和endFindByDataDelete完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbRouterInfoFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysMdbRouterInfo，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbRouterInfoFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbRouterInfoFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysMdbRouterInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysMdbRouterInfo，文件名将根据配置文件中的定义SysMdbRouterInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysMdbRouterInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysMdbRouterInfo，文件名将根据配置文件中的定义SysMdbRouterInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysMdbRouterInfoResource;

	///将一个CSysMdbRouterInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbRouterInfo	要加入的SysMdbRouterInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbRouterInfo *add(CWriteableSysMdbRouterInfo *pSysMdbRouterInfo, CTransaction *pTransaction=NULL);
	
	///刷新该CSysMdbRouterInfo的值
	///@param	pSysMdbRouterInfo	被刷新的CSysMdbRouterInfo
	///@param	pNewSysMdbRouterInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysMdbRouterInfo *pSysMdbRouterInfo, CWriteableSysMdbRouterInfo *pNewSysMdbRouterInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysMdbRouterInfo	  需要被刷新或者新增的CSysMdbRouterInfo,等于NULL表示是需要新增的
	///@param	pNewSysMdbRouterInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysMdbRouterInfo* addOrUpdate(CSysMdbRouterInfo *pSysMdbRouterInfo, CWriteableSysMdbRouterInfo *pNewSysMdbRouterInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysMdbRouterInfo，同时删除其索引
	///@param	pSysMdbRouterInfo	要删除的CSysMdbRouterInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysMdbRouterInfo *pSysMdbRouterInfo, CTransaction *pTransaction=NULL);
	
	///获取某个CSysMdbRouterInfo
	///@param	pSysMdbRouterInfo	要读取的CSysMdbRouterInfo
	///@param	pTragetSysMdbRouterInfo	存放结果的CSysMdbRouterInfo
	void retrieve(CSysMdbRouterInfo *pSysMdbRouterInfo, CWriteableSysMdbRouterInfo *pTargetSysMdbRouterInfo);
	
	///获取第一个CSysMdbRouterInfo
	///@return	得到的第一个CSysMdbRouterInfo，如果没有，则返回NULL
	CSysMdbRouterInfo *getFirst(void);
	
	///获取下一个CSysMdbRouterInfo
	///@return	得到下一个CSysMdbRouterInfo，如果没有，则返回NULL
	CSysMdbRouterInfo *getNext(void);
	
	///结束获取CSysMdbRouterInfo
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysMdbRouterInfoActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysMdbRouterInfoActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysMdbRouterInfoCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysMdbRouterInfoCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysMdbRouterInfoIteratorByHostName;

	///开始寻找CSysMdbRouterInfo
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	///@return	满足条件的地一个CSysMdbRouterInfo，如果找不到，返回NULL
	CSysMdbRouterInfo *startFindByHostName( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysMdbRouterInfo，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CSysMdbRouterInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbRouterInfo *findNextByHostName(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByHostName(void);

	friend class CSysMdbRouterInfoIteratorByDsc;

	///开始寻找CSysMdbRouterInfo
	///@param	SubcriberID	
	///@return	满足条件的地一个CSysMdbRouterInfo，如果找不到，返回NULL
	CSysMdbRouterInfo *startFindByDsc( const CReadOnlyVolumeType& SubcriberID);

	///寻找下一个符合条件的CSysMdbRouterInfo，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbRouterInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbRouterInfo *findNextByDsc(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDsc(void);

	friend class CSysMdbRouterInfoIteratorBytheAll;

	///开始寻找CSysMdbRouterInfo
	///@return	满足条件的地一个CSysMdbRouterInfo，如果找不到，返回NULL
	CSysMdbRouterInfo *startFindBytheAll();

	///寻找下一个符合条件的CSysMdbRouterInfo，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbRouterInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbRouterInfo *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

	friend class CSysMdbRouterInfoIteratorByDataDelete;

	///开始寻找CSysMdbRouterInfo
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	///@return	满足条件的地一个CSysMdbRouterInfo，如果找不到，返回NULL
	CSysMdbRouterInfo *startFindByDataDelete( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysMdbRouterInfo，必须在startFindByDataDelete以后，endFindByDataDelete之前叫用
	///@return	下一个满足条件CSysMdbRouterInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbRouterInfo *findNextByDataDelete(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDataDelete(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysMdbRouterInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbRouterInfo	要加入的SysMdbRouterInfo
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbRouterInfo *internalAdd(CWriteableSysMdbRouterInfo *pSysMdbRouterInfo, bool bNoTransaction);
	
	
	///刷新该CSysMdbRouterInfo的键值
	///@param	pSysMdbRouterInfo	被刷新的CSysMdbRouterInfo
	///@param	pNewSysMdbRouterInfo	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysMdbRouterInfo *pSysMdbRouterInfo, CWriteableSysMdbRouterInfo *pNewSysMdbRouterInfo, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysMdbRouterInfo，同时删除其索引
	///@param	pSysMdbRouterInfo	要删除的CSysMdbRouterInfo
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysMdbRouterInfo *pSysMdbRouterInfo, bool bNoTransaction);
/*
	///检查某个CSysMdbRouterInfo是否属于本对象工厂
	///@param	pSysMdbRouterInfo	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysMdbRouterInfo *pSysMdbRouterInfo);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于SubcriberID+MonDate+MonTime的索引
	CAVLTree *pSysHostNameIndex;
	///基于SubcriberID+MonDate+MonTime的索引
	CAVLTree *pDecIndex;
	
	
	///按照SubcriberID，MonDate，MonTime检索时，存储的查询参数
	CVolumeType querySubcriberIDInSearchByHostName;
	CDateType queryMonDateInSearchByHostName;
	CTimeType queryMonTimeInSearchByHostName;
	
	///按照SubcriberID，MonDate，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByHostName;
	///按照SubcriberID检索时，存储的查询参数
	CVolumeType querySubcriberIDInSearchByDsc;
	
	///按照SubcriberID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDsc;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	///按照SubcriberID，MonDate，MonTime检索时，存储的查询参数
	CVolumeType querySubcriberIDInSearchByDataDelete;
	CDateType queryMonDateInSearchByDataDelete;
	CTimeType queryMonTimeInSearchByDataDelete;
	
	///按照SubcriberID，MonDate，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDataDelete;
	
	///加入前触发
	///@param	pSysMdbRouterInfo	要加入的SysMdbRouterInfo
	virtual void beforeAdd(CWriteableSysMdbRouterInfo *pSysMdbRouterInfo);
	
	///加入后触发
	///@param	pSysMdbRouterInfo	已经加入的SysMdbRouterInfo
	virtual void afterAdd(CSysMdbRouterInfo *pSysMdbRouterInfo);

	///更新前触发	
	///@param	pSysMdbRouterInfo	被刷新的CSysMdbRouterInfo
	///@param	pNewSysMdbRouterInfo	新的值
	virtual void beforeUpdate(CSysMdbRouterInfo *pSysMdbRouterInfo, CWriteableSysMdbRouterInfo *pNewSysMdbRouterInfo);
	
	///更新后触发
	///@param	pSysMdbRouterInfo	被刷新的CSysMdbRouterInfo
	virtual void afterUpdate(CSysMdbRouterInfo *pSysMdbRouterInfo);
	
	///删除前触发
	///@param	pSysMdbRouterInfo	要删除的CSysMdbRouterInfo
	virtual void beforeRemove(CSysMdbRouterInfo *pSysMdbRouterInfo);
	
	///确认加入后触发
	///@param	pSysMdbRouterInfo	已经加入的SysMdbRouterInfo
	virtual void commitAdd(CSysMdbRouterInfo *pSysMdbRouterInfo);

	///确认更新后触发
	///@param	pSysMdbRouterInfo	被刷新的CSysMdbRouterInfo
	///@param	poldSysMdbRouterInfo	原来的值
	virtual void commitUpdate(CSysMdbRouterInfo *pSysMdbRouterInfo, CWriteableSysMdbRouterInfo *pOldSysMdbRouterInfo);
	
	///确认删除后触发
	///@param	pSysMdbRouterInfo	已经删除的CSysMdbRouterInfo
	virtual void commitRemove(CWriteableSysMdbRouterInfo *pSysMdbRouterInfo);

	///所有相关的触发器
	vector<CSysMdbRouterInfoActionTrigger *> *pActionTriggers;
	vector<CSysMdbRouterInfoCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysMdbRouterInfo compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIOFactory是一个磁盘I/O信息的对象工厂。它包含了一批磁盘I/O信息，
///同时又建立了如下索引，以方便查询：
///	SysHostNameIndex
///	DecIndex
///使用本对象工厂，可以完成对磁盘I/O信息的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByHostName，findNextByHostName和endFindByHostName完成查询操作
///		使用startFindByDsc，findNextByDsc和endFindByDsc完成查询操作
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///		使用startFindByDataDelete，findNextByDataDelete和endFindByDataDelete完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIOFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbDiskIOFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysMdbDiskIO，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbDiskIOFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbDiskIOFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysMdbDiskIO
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysMdbDiskIO，文件名将根据配置文件中的定义SysMdbDiskIOCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysMdbDiskIO
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysMdbDiskIO，文件名将根据配置文件中的定义SysMdbDiskIOCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysMdbDiskIOResource;

	///将一个CSysMdbDiskIO加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbDiskIO	要加入的SysMdbDiskIO
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbDiskIO *add(CWriteableSysMdbDiskIO *pSysMdbDiskIO, CTransaction *pTransaction=NULL);
	
	///刷新该CSysMdbDiskIO的值
	///@param	pSysMdbDiskIO	被刷新的CSysMdbDiskIO
	///@param	pNewSysMdbDiskIO	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysMdbDiskIO *pSysMdbDiskIO, CWriteableSysMdbDiskIO *pNewSysMdbDiskIO, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysMdbDiskIO	  需要被刷新或者新增的CSysMdbDiskIO,等于NULL表示是需要新增的
	///@param	pNewSysMdbDiskIO	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysMdbDiskIO* addOrUpdate(CSysMdbDiskIO *pSysMdbDiskIO, CWriteableSysMdbDiskIO *pNewSysMdbDiskIO, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysMdbDiskIO，同时删除其索引
	///@param	pSysMdbDiskIO	要删除的CSysMdbDiskIO
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysMdbDiskIO *pSysMdbDiskIO, CTransaction *pTransaction=NULL);
	
	///获取某个CSysMdbDiskIO
	///@param	pSysMdbDiskIO	要读取的CSysMdbDiskIO
	///@param	pTragetSysMdbDiskIO	存放结果的CSysMdbDiskIO
	void retrieve(CSysMdbDiskIO *pSysMdbDiskIO, CWriteableSysMdbDiskIO *pTargetSysMdbDiskIO);
	
	///获取第一个CSysMdbDiskIO
	///@return	得到的第一个CSysMdbDiskIO，如果没有，则返回NULL
	CSysMdbDiskIO *getFirst(void);
	
	///获取下一个CSysMdbDiskIO
	///@return	得到下一个CSysMdbDiskIO，如果没有，则返回NULL
	CSysMdbDiskIO *getNext(void);
	
	///结束获取CSysMdbDiskIO
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysMdbDiskIOActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysMdbDiskIOActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysMdbDiskIOCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysMdbDiskIOCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysMdbDiskIOIteratorByHostName;

	///开始寻找CSysMdbDiskIO
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	///@return	满足条件的地一个CSysMdbDiskIO，如果找不到，返回NULL
	CSysMdbDiskIO *startFindByHostName( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysMdbDiskIO，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CSysMdbDiskIO，如果已经没有一个满足要求了，则返回NULL
	CSysMdbDiskIO *findNextByHostName(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByHostName(void);

	friend class CSysMdbDiskIOIteratorByDsc;

	///开始寻找CSysMdbDiskIO
	///@param	SubcriberID	
	///@return	满足条件的地一个CSysMdbDiskIO，如果找不到，返回NULL
	CSysMdbDiskIO *startFindByDsc( const CReadOnlyVolumeType& SubcriberID);

	///寻找下一个符合条件的CSysMdbDiskIO，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbDiskIO，如果已经没有一个满足要求了，则返回NULL
	CSysMdbDiskIO *findNextByDsc(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDsc(void);

	friend class CSysMdbDiskIOIteratorBytheAll;

	///开始寻找CSysMdbDiskIO
	///@return	满足条件的地一个CSysMdbDiskIO，如果找不到，返回NULL
	CSysMdbDiskIO *startFindBytheAll();

	///寻找下一个符合条件的CSysMdbDiskIO，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbDiskIO，如果已经没有一个满足要求了，则返回NULL
	CSysMdbDiskIO *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

	friend class CSysMdbDiskIOIteratorByDataDelete;

	///开始寻找CSysMdbDiskIO
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	///@return	满足条件的地一个CSysMdbDiskIO，如果找不到，返回NULL
	CSysMdbDiskIO *startFindByDataDelete( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysMdbDiskIO，必须在startFindByDataDelete以后，endFindByDataDelete之前叫用
	///@return	下一个满足条件CSysMdbDiskIO，如果已经没有一个满足要求了，则返回NULL
	CSysMdbDiskIO *findNextByDataDelete(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDataDelete(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysMdbDiskIO加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbDiskIO	要加入的SysMdbDiskIO
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbDiskIO *internalAdd(CWriteableSysMdbDiskIO *pSysMdbDiskIO, bool bNoTransaction);
	
	
	///刷新该CSysMdbDiskIO的键值
	///@param	pSysMdbDiskIO	被刷新的CSysMdbDiskIO
	///@param	pNewSysMdbDiskIO	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysMdbDiskIO *pSysMdbDiskIO, CWriteableSysMdbDiskIO *pNewSysMdbDiskIO, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysMdbDiskIO，同时删除其索引
	///@param	pSysMdbDiskIO	要删除的CSysMdbDiskIO
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysMdbDiskIO *pSysMdbDiskIO, bool bNoTransaction);
/*
	///检查某个CSysMdbDiskIO是否属于本对象工厂
	///@param	pSysMdbDiskIO	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysMdbDiskIO *pSysMdbDiskIO);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于SubcriberID+MonDate+MonTime的索引
	CAVLTree *pSysHostNameIndex;
	///基于SubcriberID+MonDate+MonTime的索引
	CAVLTree *pDecIndex;
	
	
	///按照SubcriberID，MonDate，MonTime检索时，存储的查询参数
	CVolumeType querySubcriberIDInSearchByHostName;
	CDateType queryMonDateInSearchByHostName;
	CTimeType queryMonTimeInSearchByHostName;
	
	///按照SubcriberID，MonDate，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByHostName;
	///按照SubcriberID检索时，存储的查询参数
	CVolumeType querySubcriberIDInSearchByDsc;
	
	///按照SubcriberID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDsc;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	///按照SubcriberID，MonDate，MonTime检索时，存储的查询参数
	CVolumeType querySubcriberIDInSearchByDataDelete;
	CDateType queryMonDateInSearchByDataDelete;
	CTimeType queryMonTimeInSearchByDataDelete;
	
	///按照SubcriberID，MonDate，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDataDelete;
	
	///加入前触发
	///@param	pSysMdbDiskIO	要加入的SysMdbDiskIO
	virtual void beforeAdd(CWriteableSysMdbDiskIO *pSysMdbDiskIO);
	
	///加入后触发
	///@param	pSysMdbDiskIO	已经加入的SysMdbDiskIO
	virtual void afterAdd(CSysMdbDiskIO *pSysMdbDiskIO);

	///更新前触发	
	///@param	pSysMdbDiskIO	被刷新的CSysMdbDiskIO
	///@param	pNewSysMdbDiskIO	新的值
	virtual void beforeUpdate(CSysMdbDiskIO *pSysMdbDiskIO, CWriteableSysMdbDiskIO *pNewSysMdbDiskIO);
	
	///更新后触发
	///@param	pSysMdbDiskIO	被刷新的CSysMdbDiskIO
	virtual void afterUpdate(CSysMdbDiskIO *pSysMdbDiskIO);
	
	///删除前触发
	///@param	pSysMdbDiskIO	要删除的CSysMdbDiskIO
	virtual void beforeRemove(CSysMdbDiskIO *pSysMdbDiskIO);
	
	///确认加入后触发
	///@param	pSysMdbDiskIO	已经加入的SysMdbDiskIO
	virtual void commitAdd(CSysMdbDiskIO *pSysMdbDiskIO);

	///确认更新后触发
	///@param	pSysMdbDiskIO	被刷新的CSysMdbDiskIO
	///@param	poldSysMdbDiskIO	原来的值
	virtual void commitUpdate(CSysMdbDiskIO *pSysMdbDiskIO, CWriteableSysMdbDiskIO *pOldSysMdbDiskIO);
	
	///确认删除后触发
	///@param	pSysMdbDiskIO	已经删除的CSysMdbDiskIO
	virtual void commitRemove(CWriteableSysMdbDiskIO *pSysMdbDiskIO);

	///所有相关的触发器
	vector<CSysMdbDiskIOActionTrigger *> *pActionTriggers;
	vector<CSysMdbDiskIOCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysMdbDiskIO compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoFactory是一个系统状态信息的对象工厂。它包含了一批系统状态信息，
///同时又建立了如下索引，以方便查询：
///	SysHostNameIndex
///	DecIndex
///使用本对象工厂，可以完成对系统状态信息的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByHostName，findNextByHostName和endFindByHostName完成查询操作
///		使用startFindByDsc，findNextByDsc和endFindByDsc完成查询操作
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///		使用startFindByDataDelete，findNextByDataDelete和endFindByDataDelete完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbStatInfoFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysMdbStatInfo，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbStatInfoFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbStatInfoFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysMdbStatInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysMdbStatInfo，文件名将根据配置文件中的定义SysMdbStatInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysMdbStatInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysMdbStatInfo，文件名将根据配置文件中的定义SysMdbStatInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysMdbStatInfoResource;

	///将一个CSysMdbStatInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbStatInfo	要加入的SysMdbStatInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbStatInfo *add(CWriteableSysMdbStatInfo *pSysMdbStatInfo, CTransaction *pTransaction=NULL);
	
	///刷新该CSysMdbStatInfo的值
	///@param	pSysMdbStatInfo	被刷新的CSysMdbStatInfo
	///@param	pNewSysMdbStatInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysMdbStatInfo *pSysMdbStatInfo, CWriteableSysMdbStatInfo *pNewSysMdbStatInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysMdbStatInfo	  需要被刷新或者新增的CSysMdbStatInfo,等于NULL表示是需要新增的
	///@param	pNewSysMdbStatInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysMdbStatInfo* addOrUpdate(CSysMdbStatInfo *pSysMdbStatInfo, CWriteableSysMdbStatInfo *pNewSysMdbStatInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysMdbStatInfo，同时删除其索引
	///@param	pSysMdbStatInfo	要删除的CSysMdbStatInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysMdbStatInfo *pSysMdbStatInfo, CTransaction *pTransaction=NULL);
	
	///获取某个CSysMdbStatInfo
	///@param	pSysMdbStatInfo	要读取的CSysMdbStatInfo
	///@param	pTragetSysMdbStatInfo	存放结果的CSysMdbStatInfo
	void retrieve(CSysMdbStatInfo *pSysMdbStatInfo, CWriteableSysMdbStatInfo *pTargetSysMdbStatInfo);
	
	///获取第一个CSysMdbStatInfo
	///@return	得到的第一个CSysMdbStatInfo，如果没有，则返回NULL
	CSysMdbStatInfo *getFirst(void);
	
	///获取下一个CSysMdbStatInfo
	///@return	得到下一个CSysMdbStatInfo，如果没有，则返回NULL
	CSysMdbStatInfo *getNext(void);
	
	///结束获取CSysMdbStatInfo
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysMdbStatInfoActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysMdbStatInfoActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysMdbStatInfoCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysMdbStatInfoCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysMdbStatInfoIteratorByHostName;

	///开始寻找CSysMdbStatInfo
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	///@return	满足条件的地一个CSysMdbStatInfo，如果找不到，返回NULL
	CSysMdbStatInfo *startFindByHostName( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysMdbStatInfo，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CSysMdbStatInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbStatInfo *findNextByHostName(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByHostName(void);

	friend class CSysMdbStatInfoIteratorByDsc;

	///开始寻找CSysMdbStatInfo
	///@param	SubcriberID	
	///@return	满足条件的地一个CSysMdbStatInfo，如果找不到，返回NULL
	CSysMdbStatInfo *startFindByDsc( const CReadOnlyVolumeType& SubcriberID);

	///寻找下一个符合条件的CSysMdbStatInfo，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbStatInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbStatInfo *findNextByDsc(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDsc(void);

	friend class CSysMdbStatInfoIteratorBytheAll;

	///开始寻找CSysMdbStatInfo
	///@return	满足条件的地一个CSysMdbStatInfo，如果找不到，返回NULL
	CSysMdbStatInfo *startFindBytheAll();

	///寻找下一个符合条件的CSysMdbStatInfo，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbStatInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbStatInfo *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

	friend class CSysMdbStatInfoIteratorByDataDelete;

	///开始寻找CSysMdbStatInfo
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	///@return	满足条件的地一个CSysMdbStatInfo，如果找不到，返回NULL
	CSysMdbStatInfo *startFindByDataDelete( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysMdbStatInfo，必须在startFindByDataDelete以后，endFindByDataDelete之前叫用
	///@return	下一个满足条件CSysMdbStatInfo，如果已经没有一个满足要求了，则返回NULL
	CSysMdbStatInfo *findNextByDataDelete(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDataDelete(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysMdbStatInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbStatInfo	要加入的SysMdbStatInfo
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbStatInfo *internalAdd(CWriteableSysMdbStatInfo *pSysMdbStatInfo, bool bNoTransaction);
	
	
	///刷新该CSysMdbStatInfo的键值
	///@param	pSysMdbStatInfo	被刷新的CSysMdbStatInfo
	///@param	pNewSysMdbStatInfo	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysMdbStatInfo *pSysMdbStatInfo, CWriteableSysMdbStatInfo *pNewSysMdbStatInfo, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysMdbStatInfo，同时删除其索引
	///@param	pSysMdbStatInfo	要删除的CSysMdbStatInfo
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysMdbStatInfo *pSysMdbStatInfo, bool bNoTransaction);
/*
	///检查某个CSysMdbStatInfo是否属于本对象工厂
	///@param	pSysMdbStatInfo	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysMdbStatInfo *pSysMdbStatInfo);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于SubcriberID+MonDate+MonTime的索引
	CAVLTree *pSysHostNameIndex;
	///基于SubcriberID+MonDate+MonTime的索引
	CAVLTree *pDecIndex;
	
	
	///按照SubcriberID，MonDate，MonTime检索时，存储的查询参数
	CVolumeType querySubcriberIDInSearchByHostName;
	CDateType queryMonDateInSearchByHostName;
	CTimeType queryMonTimeInSearchByHostName;
	
	///按照SubcriberID，MonDate，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByHostName;
	///按照SubcriberID检索时，存储的查询参数
	CVolumeType querySubcriberIDInSearchByDsc;
	
	///按照SubcriberID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDsc;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	///按照SubcriberID，MonDate，MonTime检索时，存储的查询参数
	CVolumeType querySubcriberIDInSearchByDataDelete;
	CDateType queryMonDateInSearchByDataDelete;
	CTimeType queryMonTimeInSearchByDataDelete;
	
	///按照SubcriberID，MonDate，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDataDelete;
	
	///加入前触发
	///@param	pSysMdbStatInfo	要加入的SysMdbStatInfo
	virtual void beforeAdd(CWriteableSysMdbStatInfo *pSysMdbStatInfo);
	
	///加入后触发
	///@param	pSysMdbStatInfo	已经加入的SysMdbStatInfo
	virtual void afterAdd(CSysMdbStatInfo *pSysMdbStatInfo);

	///更新前触发	
	///@param	pSysMdbStatInfo	被刷新的CSysMdbStatInfo
	///@param	pNewSysMdbStatInfo	新的值
	virtual void beforeUpdate(CSysMdbStatInfo *pSysMdbStatInfo, CWriteableSysMdbStatInfo *pNewSysMdbStatInfo);
	
	///更新后触发
	///@param	pSysMdbStatInfo	被刷新的CSysMdbStatInfo
	virtual void afterUpdate(CSysMdbStatInfo *pSysMdbStatInfo);
	
	///删除前触发
	///@param	pSysMdbStatInfo	要删除的CSysMdbStatInfo
	virtual void beforeRemove(CSysMdbStatInfo *pSysMdbStatInfo);
	
	///确认加入后触发
	///@param	pSysMdbStatInfo	已经加入的SysMdbStatInfo
	virtual void commitAdd(CSysMdbStatInfo *pSysMdbStatInfo);

	///确认更新后触发
	///@param	pSysMdbStatInfo	被刷新的CSysMdbStatInfo
	///@param	poldSysMdbStatInfo	原来的值
	virtual void commitUpdate(CSysMdbStatInfo *pSysMdbStatInfo, CWriteableSysMdbStatInfo *pOldSysMdbStatInfo);
	
	///确认删除后触发
	///@param	pSysMdbStatInfo	已经删除的CSysMdbStatInfo
	virtual void commitRemove(CWriteableSysMdbStatInfo *pSysMdbStatInfo);

	///所有相关的触发器
	vector<CSysMdbStatInfoActionTrigger *> *pActionTriggers;
	vector<CSysMdbStatInfoCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysMdbStatInfo compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatFactory是一个交易系统前置报单响应信息的对象工厂。它包含了一批交易系统前置报单响应信息，
///同时又建立了如下索引，以方便查询：
///	SysHostNameIndex
///	DecIndex
///使用本对象工厂，可以完成对交易系统前置报单响应信息的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByFrontIndex，findNextByFrontIndex和endFindByFrontIndex完成查询操作
///		使用startFindByDsc，findNextByDsc和endFindByDsc完成查询操作
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///		使用findByTheOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbTradeFrontOrderRttStatFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysMdbTradeFrontOrderRttStat，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMdbTradeFrontOrderRttStatFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbTradeFrontOrderRttStatFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysMdbTradeFrontOrderRttStat
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysMdbTradeFrontOrderRttStat，文件名将根据配置文件中的定义SysMdbTradeFrontOrderRttStatCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysMdbTradeFrontOrderRttStat
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysMdbTradeFrontOrderRttStat，文件名将根据配置文件中的定义SysMdbTradeFrontOrderRttStatCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysMdbTradeFrontOrderRttStatResource;

	///将一个CSysMdbTradeFrontOrderRttStat加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbTradeFrontOrderRttStat	要加入的SysMdbTradeFrontOrderRttStat
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbTradeFrontOrderRttStat *add(CWriteableSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat, CTransaction *pTransaction=NULL);
	
	///刷新该CSysMdbTradeFrontOrderRttStat的值
	///@param	pSysMdbTradeFrontOrderRttStat	被刷新的CSysMdbTradeFrontOrderRttStat
	///@param	pNewSysMdbTradeFrontOrderRttStat	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat, CWriteableSysMdbTradeFrontOrderRttStat *pNewSysMdbTradeFrontOrderRttStat, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysMdbTradeFrontOrderRttStat	  需要被刷新或者新增的CSysMdbTradeFrontOrderRttStat,等于NULL表示是需要新增的
	///@param	pNewSysMdbTradeFrontOrderRttStat	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysMdbTradeFrontOrderRttStat* addOrUpdate(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat, CWriteableSysMdbTradeFrontOrderRttStat *pNewSysMdbTradeFrontOrderRttStat, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysMdbTradeFrontOrderRttStat，同时删除其索引
	///@param	pSysMdbTradeFrontOrderRttStat	要删除的CSysMdbTradeFrontOrderRttStat
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat, CTransaction *pTransaction=NULL);
	
	///获取某个CSysMdbTradeFrontOrderRttStat
	///@param	pSysMdbTradeFrontOrderRttStat	要读取的CSysMdbTradeFrontOrderRttStat
	///@param	pTragetSysMdbTradeFrontOrderRttStat	存放结果的CSysMdbTradeFrontOrderRttStat
	void retrieve(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat, CWriteableSysMdbTradeFrontOrderRttStat *pTargetSysMdbTradeFrontOrderRttStat);
	
	///获取第一个CSysMdbTradeFrontOrderRttStat
	///@return	得到的第一个CSysMdbTradeFrontOrderRttStat，如果没有，则返回NULL
	CSysMdbTradeFrontOrderRttStat *getFirst(void);
	
	///获取下一个CSysMdbTradeFrontOrderRttStat
	///@return	得到下一个CSysMdbTradeFrontOrderRttStat，如果没有，则返回NULL
	CSysMdbTradeFrontOrderRttStat *getNext(void);
	
	///结束获取CSysMdbTradeFrontOrderRttStat
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysMdbTradeFrontOrderRttStatActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysMdbTradeFrontOrderRttStatActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysMdbTradeFrontOrderRttStatCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysMdbTradeFrontOrderRttStatCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex;

	///开始寻找CSysMdbTradeFrontOrderRttStat
	///@param	ObjectID	
	///@param	MonTime	
	///@return	满足条件的地一个CSysMdbTradeFrontOrderRttStat，如果找不到，返回NULL
	CSysMdbTradeFrontOrderRttStat *startFindByFrontIndex( const CReadOnlyTypeObjectIDType& ObjectID,  const CReadOnlyTimeType& MonTime);

	///寻找下一个符合条件的CSysMdbTradeFrontOrderRttStat，必须在startFindByFrontIndex以后，endFindByFrontIndex之前叫用
	///@return	下一个满足条件CSysMdbTradeFrontOrderRttStat，如果已经没有一个满足要求了，则返回NULL
	CSysMdbTradeFrontOrderRttStat *findNextByFrontIndex(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByFrontIndex(void);

	friend class CSysMdbTradeFrontOrderRttStatIteratorByDsc;

	///开始寻找CSysMdbTradeFrontOrderRttStat
	///@param	SubcriberID	
	///@return	满足条件的地一个CSysMdbTradeFrontOrderRttStat，如果找不到，返回NULL
	CSysMdbTradeFrontOrderRttStat *startFindByDsc( const CReadOnlyVolumeType& SubcriberID);

	///寻找下一个符合条件的CSysMdbTradeFrontOrderRttStat，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbTradeFrontOrderRttStat，如果已经没有一个满足要求了，则返回NULL
	CSysMdbTradeFrontOrderRttStat *findNextByDsc(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByDsc(void);

	friend class CSysMdbTradeFrontOrderRttStatIteratorBytheAll;

	///开始寻找CSysMdbTradeFrontOrderRttStat
	///@return	满足条件的地一个CSysMdbTradeFrontOrderRttStat，如果找不到，返回NULL
	CSysMdbTradeFrontOrderRttStat *startFindBytheAll();

	///寻找下一个符合条件的CSysMdbTradeFrontOrderRttStat，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbTradeFrontOrderRttStat，如果已经没有一个满足要求了，则返回NULL
	CSysMdbTradeFrontOrderRttStat *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

	///寻找CSysMdbTradeFrontOrderRttStat
	///@param	ObjectID	
	///@param	MonTime	
	///@return	找到的CSysMdbTradeFrontOrderRttStat，如果找不到，返回NULL
	CSysMdbTradeFrontOrderRttStat *findByTheOne( const CReadOnlyTypeObjectIDType&  ObjectID,  const CReadOnlyTimeType&  MonTime);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysMdbTradeFrontOrderRttStat加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMdbTradeFrontOrderRttStat	要加入的SysMdbTradeFrontOrderRttStat
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMdbTradeFrontOrderRttStat *internalAdd(CWriteableSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat, bool bNoTransaction);
	
	
	///刷新该CSysMdbTradeFrontOrderRttStat的键值
	///@param	pSysMdbTradeFrontOrderRttStat	被刷新的CSysMdbTradeFrontOrderRttStat
	///@param	pNewSysMdbTradeFrontOrderRttStat	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat, CWriteableSysMdbTradeFrontOrderRttStat *pNewSysMdbTradeFrontOrderRttStat, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysMdbTradeFrontOrderRttStat，同时删除其索引
	///@param	pSysMdbTradeFrontOrderRttStat	要删除的CSysMdbTradeFrontOrderRttStat
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat, bool bNoTransaction);
/*
	///检查某个CSysMdbTradeFrontOrderRttStat是否属于本对象工厂
	///@param	pSysMdbTradeFrontOrderRttStat	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ObjectID+MonTime的索引
	CAVLTree *pSysHostNameIndex;
	///基于SubcriberID+MonDate+MonTime的索引
	CAVLTree *pDecIndex;
	
	
	///按照ObjectID，MonTime检索时，存储的查询参数
	CTypeObjectIDType queryObjectIDInSearchByFrontIndex;
	CTimeType queryMonTimeInSearchByFrontIndex;
	
	///按照ObjectID，MonTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByFrontIndex;
	///按照SubcriberID检索时，存储的查询参数
	CVolumeType querySubcriberIDInSearchByDsc;
	
	///按照SubcriberID检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByDsc;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	
	///加入前触发
	///@param	pSysMdbTradeFrontOrderRttStat	要加入的SysMdbTradeFrontOrderRttStat
	virtual void beforeAdd(CWriteableSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat);
	
	///加入后触发
	///@param	pSysMdbTradeFrontOrderRttStat	已经加入的SysMdbTradeFrontOrderRttStat
	virtual void afterAdd(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat);

	///更新前触发	
	///@param	pSysMdbTradeFrontOrderRttStat	被刷新的CSysMdbTradeFrontOrderRttStat
	///@param	pNewSysMdbTradeFrontOrderRttStat	新的值
	virtual void beforeUpdate(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat, CWriteableSysMdbTradeFrontOrderRttStat *pNewSysMdbTradeFrontOrderRttStat);
	
	///更新后触发
	///@param	pSysMdbTradeFrontOrderRttStat	被刷新的CSysMdbTradeFrontOrderRttStat
	virtual void afterUpdate(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat);
	
	///删除前触发
	///@param	pSysMdbTradeFrontOrderRttStat	要删除的CSysMdbTradeFrontOrderRttStat
	virtual void beforeRemove(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat);
	
	///确认加入后触发
	///@param	pSysMdbTradeFrontOrderRttStat	已经加入的SysMdbTradeFrontOrderRttStat
	virtual void commitAdd(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat);

	///确认更新后触发
	///@param	pSysMdbTradeFrontOrderRttStat	被刷新的CSysMdbTradeFrontOrderRttStat
	///@param	poldSysMdbTradeFrontOrderRttStat	原来的值
	virtual void commitUpdate(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat, CWriteableSysMdbTradeFrontOrderRttStat *pOldSysMdbTradeFrontOrderRttStat);
	
	///确认删除后触发
	///@param	pSysMdbTradeFrontOrderRttStat	已经删除的CSysMdbTradeFrontOrderRttStat
	virtual void commitRemove(CWriteableSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat);

	///所有相关的触发器
	vector<CSysMdbTradeFrontOrderRttStatActionTrigger *> *pActionTriggers;
	vector<CSysMdbTradeFrontOrderRttStatCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysMdbTradeFrontOrderRttStat compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysInstrumentStatusFactory是一个合约状态切换的对象工厂。它包含了一批合约状态切换，
///同时又建立了如下索引，以方便查询：
///	SysTradeTimeIndex
///使用本对象工厂，可以完成对合约状态切换的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByActionTime，findNextByActionTime和endFindByActionTime完成查询操作
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstrumentStatusFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysInstrumentStatusFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysInstrumentStatus，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysInstrumentStatusFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysInstrumentStatusFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysInstrumentStatus
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysInstrumentStatus，文件名将根据配置文件中的定义SysInstrumentStatusCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysInstrumentStatus
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysInstrumentStatus，文件名将根据配置文件中的定义SysInstrumentStatusCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysInstrumentStatusResource;

	///将一个CSysInstrumentStatus加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysInstrumentStatus	要加入的SysInstrumentStatus
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysInstrumentStatus *add(CWriteableSysInstrumentStatus *pSysInstrumentStatus, CTransaction *pTransaction=NULL);
	
	///刷新该CSysInstrumentStatus的值
	///@param	pSysInstrumentStatus	被刷新的CSysInstrumentStatus
	///@param	pNewSysInstrumentStatus	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysInstrumentStatus *pSysInstrumentStatus, CWriteableSysInstrumentStatus *pNewSysInstrumentStatus, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysInstrumentStatus	  需要被刷新或者新增的CSysInstrumentStatus,等于NULL表示是需要新增的
	///@param	pNewSysInstrumentStatus	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysInstrumentStatus* addOrUpdate(CSysInstrumentStatus *pSysInstrumentStatus, CWriteableSysInstrumentStatus *pNewSysInstrumentStatus, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysInstrumentStatus，同时删除其索引
	///@param	pSysInstrumentStatus	要删除的CSysInstrumentStatus
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysInstrumentStatus *pSysInstrumentStatus, CTransaction *pTransaction=NULL);
	
	///获取某个CSysInstrumentStatus
	///@param	pSysInstrumentStatus	要读取的CSysInstrumentStatus
	///@param	pTragetSysInstrumentStatus	存放结果的CSysInstrumentStatus
	void retrieve(CSysInstrumentStatus *pSysInstrumentStatus, CWriteableSysInstrumentStatus *pTargetSysInstrumentStatus);
	
	///获取第一个CSysInstrumentStatus
	///@return	得到的第一个CSysInstrumentStatus，如果没有，则返回NULL
	CSysInstrumentStatus *getFirst(void);
	
	///获取下一个CSysInstrumentStatus
	///@return	得到下一个CSysInstrumentStatus，如果没有，则返回NULL
	CSysInstrumentStatus *getNext(void);
	
	///结束获取CSysInstrumentStatus
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysInstrumentStatusActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysInstrumentStatusActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysInstrumentStatusCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysInstrumentStatusCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysInstrumentStatusIteratorByActionTime;

	///开始寻找CSysInstrumentStatus
	///@param	EnterTime	
	///@return	满足条件的地一个CSysInstrumentStatus，如果找不到，返回NULL
	CSysInstrumentStatus *startFindByActionTime( const CReadOnlyTimeType& EnterTime);

	///寻找下一个符合条件的CSysInstrumentStatus，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysInstrumentStatus，如果已经没有一个满足要求了，则返回NULL
	CSysInstrumentStatus *findNextByActionTime(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByActionTime(void);

	friend class CSysInstrumentStatusIteratorBytheAll;

	///开始寻找CSysInstrumentStatus
	///@return	满足条件的地一个CSysInstrumentStatus，如果找不到，返回NULL
	CSysInstrumentStatus *startFindBytheAll();

	///寻找下一个符合条件的CSysInstrumentStatus，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysInstrumentStatus，如果已经没有一个满足要求了，则返回NULL
	CSysInstrumentStatus *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysInstrumentStatus加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysInstrumentStatus	要加入的SysInstrumentStatus
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysInstrumentStatus *internalAdd(CWriteableSysInstrumentStatus *pSysInstrumentStatus, bool bNoTransaction);
	
	
	///刷新该CSysInstrumentStatus的键值
	///@param	pSysInstrumentStatus	被刷新的CSysInstrumentStatus
	///@param	pNewSysInstrumentStatus	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysInstrumentStatus *pSysInstrumentStatus, CWriteableSysInstrumentStatus *pNewSysInstrumentStatus, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysInstrumentStatus，同时删除其索引
	///@param	pSysInstrumentStatus	要删除的CSysInstrumentStatus
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysInstrumentStatus *pSysInstrumentStatus, bool bNoTransaction);
/*
	///检查某个CSysInstrumentStatus是否属于本对象工厂
	///@param	pSysInstrumentStatus	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysInstrumentStatus *pSysInstrumentStatus);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于EnterTime的索引
	CAVLTree *pSysTradeTimeIndex;
	
	
	///按照EnterTime检索时，存储的查询参数
	CTimeType queryEnterTimeInSearchByActionTime;
	
	///按照EnterTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByActionTime;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	
	///加入前触发
	///@param	pSysInstrumentStatus	要加入的SysInstrumentStatus
	virtual void beforeAdd(CWriteableSysInstrumentStatus *pSysInstrumentStatus);
	
	///加入后触发
	///@param	pSysInstrumentStatus	已经加入的SysInstrumentStatus
	virtual void afterAdd(CSysInstrumentStatus *pSysInstrumentStatus);

	///更新前触发	
	///@param	pSysInstrumentStatus	被刷新的CSysInstrumentStatus
	///@param	pNewSysInstrumentStatus	新的值
	virtual void beforeUpdate(CSysInstrumentStatus *pSysInstrumentStatus, CWriteableSysInstrumentStatus *pNewSysInstrumentStatus);
	
	///更新后触发
	///@param	pSysInstrumentStatus	被刷新的CSysInstrumentStatus
	virtual void afterUpdate(CSysInstrumentStatus *pSysInstrumentStatus);
	
	///删除前触发
	///@param	pSysInstrumentStatus	要删除的CSysInstrumentStatus
	virtual void beforeRemove(CSysInstrumentStatus *pSysInstrumentStatus);
	
	///确认加入后触发
	///@param	pSysInstrumentStatus	已经加入的SysInstrumentStatus
	virtual void commitAdd(CSysInstrumentStatus *pSysInstrumentStatus);

	///确认更新后触发
	///@param	pSysInstrumentStatus	被刷新的CSysInstrumentStatus
	///@param	poldSysInstrumentStatus	原来的值
	virtual void commitUpdate(CSysInstrumentStatus *pSysInstrumentStatus, CWriteableSysInstrumentStatus *pOldSysInstrumentStatus);
	
	///确认删除后触发
	///@param	pSysInstrumentStatus	已经删除的CSysInstrumentStatus
	virtual void commitRemove(CWriteableSysInstrumentStatus *pSysInstrumentStatus);

	///所有相关的触发器
	vector<CSysInstrumentStatusActionTrigger *> *pActionTriggers;
	vector<CSysInstrumentStatusCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysInstrumentStatus compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysCurrTradingSegmentAttrFactory是一个合约交易节信息的对象工厂。它包含了一批合约交易节信息，
///同时又建立了如下索引，以方便查询：
///	SysTradeTimeIndex
///使用本对象工厂，可以完成对合约交易节信息的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByActionTime，findNextByActionTime和endFindByActionTime完成查询操作
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysCurrTradingSegmentAttrFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysCurrTradingSegmentAttrFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysCurrTradingSegmentAttr，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysCurrTradingSegmentAttrFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysCurrTradingSegmentAttrFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysCurrTradingSegmentAttr
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysCurrTradingSegmentAttr，文件名将根据配置文件中的定义SysCurrTradingSegmentAttrCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysCurrTradingSegmentAttr
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysCurrTradingSegmentAttr，文件名将根据配置文件中的定义SysCurrTradingSegmentAttrCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysCurrTradingSegmentAttrResource;

	///将一个CSysCurrTradingSegmentAttr加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysCurrTradingSegmentAttr	要加入的SysCurrTradingSegmentAttr
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysCurrTradingSegmentAttr *add(CWriteableSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr, CTransaction *pTransaction=NULL);
	
	///刷新该CSysCurrTradingSegmentAttr的值
	///@param	pSysCurrTradingSegmentAttr	被刷新的CSysCurrTradingSegmentAttr
	///@param	pNewSysCurrTradingSegmentAttr	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr, CWriteableSysCurrTradingSegmentAttr *pNewSysCurrTradingSegmentAttr, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysCurrTradingSegmentAttr	  需要被刷新或者新增的CSysCurrTradingSegmentAttr,等于NULL表示是需要新增的
	///@param	pNewSysCurrTradingSegmentAttr	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysCurrTradingSegmentAttr* addOrUpdate(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr, CWriteableSysCurrTradingSegmentAttr *pNewSysCurrTradingSegmentAttr, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysCurrTradingSegmentAttr，同时删除其索引
	///@param	pSysCurrTradingSegmentAttr	要删除的CSysCurrTradingSegmentAttr
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr, CTransaction *pTransaction=NULL);
	
	///获取某个CSysCurrTradingSegmentAttr
	///@param	pSysCurrTradingSegmentAttr	要读取的CSysCurrTradingSegmentAttr
	///@param	pTragetSysCurrTradingSegmentAttr	存放结果的CSysCurrTradingSegmentAttr
	void retrieve(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr, CWriteableSysCurrTradingSegmentAttr *pTargetSysCurrTradingSegmentAttr);
	
	///获取第一个CSysCurrTradingSegmentAttr
	///@return	得到的第一个CSysCurrTradingSegmentAttr，如果没有，则返回NULL
	CSysCurrTradingSegmentAttr *getFirst(void);
	
	///获取下一个CSysCurrTradingSegmentAttr
	///@return	得到下一个CSysCurrTradingSegmentAttr，如果没有，则返回NULL
	CSysCurrTradingSegmentAttr *getNext(void);
	
	///结束获取CSysCurrTradingSegmentAttr
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysCurrTradingSegmentAttrActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysCurrTradingSegmentAttrActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysCurrTradingSegmentAttrCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysCurrTradingSegmentAttrCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysCurrTradingSegmentAttrIteratorByActionTime;

	///开始寻找CSysCurrTradingSegmentAttr
	///@param	StartTime	
	///@return	满足条件的地一个CSysCurrTradingSegmentAttr，如果找不到，返回NULL
	CSysCurrTradingSegmentAttr *startFindByActionTime( const CReadOnlyTimeType& StartTime);

	///寻找下一个符合条件的CSysCurrTradingSegmentAttr，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysCurrTradingSegmentAttr，如果已经没有一个满足要求了，则返回NULL
	CSysCurrTradingSegmentAttr *findNextByActionTime(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByActionTime(void);

	friend class CSysCurrTradingSegmentAttrIteratorBytheAll;

	///开始寻找CSysCurrTradingSegmentAttr
	///@return	满足条件的地一个CSysCurrTradingSegmentAttr，如果找不到，返回NULL
	CSysCurrTradingSegmentAttr *startFindBytheAll();

	///寻找下一个符合条件的CSysCurrTradingSegmentAttr，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysCurrTradingSegmentAttr，如果已经没有一个满足要求了，则返回NULL
	CSysCurrTradingSegmentAttr *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysCurrTradingSegmentAttr加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysCurrTradingSegmentAttr	要加入的SysCurrTradingSegmentAttr
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysCurrTradingSegmentAttr *internalAdd(CWriteableSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr, bool bNoTransaction);
	
	
	///刷新该CSysCurrTradingSegmentAttr的键值
	///@param	pSysCurrTradingSegmentAttr	被刷新的CSysCurrTradingSegmentAttr
	///@param	pNewSysCurrTradingSegmentAttr	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr, CWriteableSysCurrTradingSegmentAttr *pNewSysCurrTradingSegmentAttr, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysCurrTradingSegmentAttr，同时删除其索引
	///@param	pSysCurrTradingSegmentAttr	要删除的CSysCurrTradingSegmentAttr
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr, bool bNoTransaction);
/*
	///检查某个CSysCurrTradingSegmentAttr是否属于本对象工厂
	///@param	pSysCurrTradingSegmentAttr	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于StartTime的索引
	CAVLTree *pSysTradeTimeIndex;
	
	
	///按照StartTime检索时，存储的查询参数
	CTimeType queryStartTimeInSearchByActionTime;
	
	///按照StartTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByActionTime;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	
	///加入前触发
	///@param	pSysCurrTradingSegmentAttr	要加入的SysCurrTradingSegmentAttr
	virtual void beforeAdd(CWriteableSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr);
	
	///加入后触发
	///@param	pSysCurrTradingSegmentAttr	已经加入的SysCurrTradingSegmentAttr
	virtual void afterAdd(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr);

	///更新前触发	
	///@param	pSysCurrTradingSegmentAttr	被刷新的CSysCurrTradingSegmentAttr
	///@param	pNewSysCurrTradingSegmentAttr	新的值
	virtual void beforeUpdate(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr, CWriteableSysCurrTradingSegmentAttr *pNewSysCurrTradingSegmentAttr);
	
	///更新后触发
	///@param	pSysCurrTradingSegmentAttr	被刷新的CSysCurrTradingSegmentAttr
	virtual void afterUpdate(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr);
	
	///删除前触发
	///@param	pSysCurrTradingSegmentAttr	要删除的CSysCurrTradingSegmentAttr
	virtual void beforeRemove(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr);
	
	///确认加入后触发
	///@param	pSysCurrTradingSegmentAttr	已经加入的SysCurrTradingSegmentAttr
	virtual void commitAdd(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr);

	///确认更新后触发
	///@param	pSysCurrTradingSegmentAttr	被刷新的CSysCurrTradingSegmentAttr
	///@param	poldSysCurrTradingSegmentAttr	原来的值
	virtual void commitUpdate(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr, CWriteableSysCurrTradingSegmentAttr *pOldSysCurrTradingSegmentAttr);
	
	///确认删除后触发
	///@param	pSysCurrTradingSegmentAttr	已经删除的CSysCurrTradingSegmentAttr
	virtual void commitRemove(CWriteableSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr);

	///所有相关的触发器
	vector<CSysCurrTradingSegmentAttrActionTrigger *> *pActionTriggers;
	vector<CSysCurrTradingSegmentAttrCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysCurrTradingSegmentAttr compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostFactory是一个会员链路费用表的对象工厂。它包含了一批会员链路费用表，
///同时又建立了如下索引，以方便查询：
///	SysPayTimeIndex
///使用本对象工厂，可以完成对会员链路费用表的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByPayTime，findNextByPayTime和endFindByPayTime完成查询操作
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMemberLinkCostFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysMemberLinkCost，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysMemberLinkCostFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysMemberLinkCostFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysMemberLinkCost
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysMemberLinkCost，文件名将根据配置文件中的定义SysMemberLinkCostCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysMemberLinkCost
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysMemberLinkCost，文件名将根据配置文件中的定义SysMemberLinkCostCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysMemberLinkCostResource;

	///将一个CSysMemberLinkCost加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMemberLinkCost	要加入的SysMemberLinkCost
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMemberLinkCost *add(CWriteableSysMemberLinkCost *pSysMemberLinkCost, CTransaction *pTransaction=NULL);
	
	///刷新该CSysMemberLinkCost的值
	///@param	pSysMemberLinkCost	被刷新的CSysMemberLinkCost
	///@param	pNewSysMemberLinkCost	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysMemberLinkCost *pSysMemberLinkCost, CWriteableSysMemberLinkCost *pNewSysMemberLinkCost, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysMemberLinkCost	  需要被刷新或者新增的CSysMemberLinkCost,等于NULL表示是需要新增的
	///@param	pNewSysMemberLinkCost	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysMemberLinkCost* addOrUpdate(CSysMemberLinkCost *pSysMemberLinkCost, CWriteableSysMemberLinkCost *pNewSysMemberLinkCost, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysMemberLinkCost，同时删除其索引
	///@param	pSysMemberLinkCost	要删除的CSysMemberLinkCost
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysMemberLinkCost *pSysMemberLinkCost, CTransaction *pTransaction=NULL);
	
	///获取某个CSysMemberLinkCost
	///@param	pSysMemberLinkCost	要读取的CSysMemberLinkCost
	///@param	pTragetSysMemberLinkCost	存放结果的CSysMemberLinkCost
	void retrieve(CSysMemberLinkCost *pSysMemberLinkCost, CWriteableSysMemberLinkCost *pTargetSysMemberLinkCost);
	
	///获取第一个CSysMemberLinkCost
	///@return	得到的第一个CSysMemberLinkCost，如果没有，则返回NULL
	CSysMemberLinkCost *getFirst(void);
	
	///获取下一个CSysMemberLinkCost
	///@return	得到下一个CSysMemberLinkCost，如果没有，则返回NULL
	CSysMemberLinkCost *getNext(void);
	
	///结束获取CSysMemberLinkCost
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysMemberLinkCostActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysMemberLinkCostActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysMemberLinkCostCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysMemberLinkCostCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysMemberLinkCostIteratorByPayTime;

	///开始寻找CSysMemberLinkCost
	///@param	Pay_Date	
	///@return	满足条件的地一个CSysMemberLinkCost，如果找不到，返回NULL
	CSysMemberLinkCost *startFindByPayTime( const CReadOnlyCfgNameType& Pay_Date);

	///寻找下一个符合条件的CSysMemberLinkCost，必须在startFindByPayTime以后，endFindByPayTime之前叫用
	///@return	下一个满足条件CSysMemberLinkCost，如果已经没有一个满足要求了，则返回NULL
	CSysMemberLinkCost *findNextByPayTime(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByPayTime(void);

	friend class CSysMemberLinkCostIteratorBytheAll;

	///开始寻找CSysMemberLinkCost
	///@return	满足条件的地一个CSysMemberLinkCost，如果找不到，返回NULL
	CSysMemberLinkCost *startFindBytheAll();

	///寻找下一个符合条件的CSysMemberLinkCost，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMemberLinkCost，如果已经没有一个满足要求了，则返回NULL
	CSysMemberLinkCost *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

	friend class CSysMemberLinkCostIteratorByAll;

	///开始寻找CSysMemberLinkCost
	///@return	满足条件的地一个CSysMemberLinkCost，如果找不到，返回NULL
	CSysMemberLinkCost *startFindByAll();

	///寻找下一个符合条件的CSysMemberLinkCost，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysMemberLinkCost，如果已经没有一个满足要求了，则返回NULL
	CSysMemberLinkCost *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysMemberLinkCost加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysMemberLinkCost	要加入的SysMemberLinkCost
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysMemberLinkCost *internalAdd(CWriteableSysMemberLinkCost *pSysMemberLinkCost, bool bNoTransaction);
	
	
	///刷新该CSysMemberLinkCost的键值
	///@param	pSysMemberLinkCost	被刷新的CSysMemberLinkCost
	///@param	pNewSysMemberLinkCost	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysMemberLinkCost *pSysMemberLinkCost, CWriteableSysMemberLinkCost *pNewSysMemberLinkCost, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysMemberLinkCost，同时删除其索引
	///@param	pSysMemberLinkCost	要删除的CSysMemberLinkCost
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysMemberLinkCost *pSysMemberLinkCost, bool bNoTransaction);
/*
	///检查某个CSysMemberLinkCost是否属于本对象工厂
	///@param	pSysMemberLinkCost	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysMemberLinkCost *pSysMemberLinkCost);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于Pay_Date的索引
	CAVLTree *pSysPayTimeIndex;
	
	
	///按照Pay_Date检索时，存储的查询参数
	CCfgNameType queryPay_DateInSearchByPayTime;
	
	///按照Pay_Date检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByPayTime;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysMemberLinkCost	要加入的SysMemberLinkCost
	virtual void beforeAdd(CWriteableSysMemberLinkCost *pSysMemberLinkCost);
	
	///加入后触发
	///@param	pSysMemberLinkCost	已经加入的SysMemberLinkCost
	virtual void afterAdd(CSysMemberLinkCost *pSysMemberLinkCost);

	///更新前触发	
	///@param	pSysMemberLinkCost	被刷新的CSysMemberLinkCost
	///@param	pNewSysMemberLinkCost	新的值
	virtual void beforeUpdate(CSysMemberLinkCost *pSysMemberLinkCost, CWriteableSysMemberLinkCost *pNewSysMemberLinkCost);
	
	///更新后触发
	///@param	pSysMemberLinkCost	被刷新的CSysMemberLinkCost
	virtual void afterUpdate(CSysMemberLinkCost *pSysMemberLinkCost);
	
	///删除前触发
	///@param	pSysMemberLinkCost	要删除的CSysMemberLinkCost
	virtual void beforeRemove(CSysMemberLinkCost *pSysMemberLinkCost);
	
	///确认加入后触发
	///@param	pSysMemberLinkCost	已经加入的SysMemberLinkCost
	virtual void commitAdd(CSysMemberLinkCost *pSysMemberLinkCost);

	///确认更新后触发
	///@param	pSysMemberLinkCost	被刷新的CSysMemberLinkCost
	///@param	poldSysMemberLinkCost	原来的值
	virtual void commitUpdate(CSysMemberLinkCost *pSysMemberLinkCost, CWriteableSysMemberLinkCost *pOldSysMemberLinkCost);
	
	///确认删除后触发
	///@param	pSysMemberLinkCost	已经删除的CSysMemberLinkCost
	virtual void commitRemove(CWriteableSysMemberLinkCost *pSysMemberLinkCost);

	///所有相关的触发器
	vector<CSysMemberLinkCostActionTrigger *> *pActionTriggers;
	vector<CSysMemberLinkCostCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysMemberLinkCost compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentFactory是一个会员链路月租表的对象工厂。它包含了一批会员链路月租表，
///同时又建立了如下索引，以方便查询：
///	SysLineNameIndex
///使用本对象工厂，可以完成对会员链路月租表的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByLineName，findNextByLineName和endFindByLineName完成查询操作
///		使用startFindBytheAll，findNextBytheAll和endFindBytheAll完成查询操作
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetPartylinkMonthlyRentFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetPartylinkMonthlyRent，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetPartylinkMonthlyRentFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetPartylinkMonthlyRentFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetPartylinkMonthlyRent
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetPartylinkMonthlyRent，文件名将根据配置文件中的定义SysNetPartylinkMonthlyRentCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetPartylinkMonthlyRent
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetPartylinkMonthlyRent，文件名将根据配置文件中的定义SysNetPartylinkMonthlyRentCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetPartylinkMonthlyRentResource;

	///将一个CSysNetPartylinkMonthlyRent加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetPartylinkMonthlyRent	要加入的SysNetPartylinkMonthlyRent
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetPartylinkMonthlyRent *add(CWriteableSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetPartylinkMonthlyRent的值
	///@param	pSysNetPartylinkMonthlyRent	被刷新的CSysNetPartylinkMonthlyRent
	///@param	pNewSysNetPartylinkMonthlyRent	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent, CWriteableSysNetPartylinkMonthlyRent *pNewSysNetPartylinkMonthlyRent, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetPartylinkMonthlyRent	  需要被刷新或者新增的CSysNetPartylinkMonthlyRent,等于NULL表示是需要新增的
	///@param	pNewSysNetPartylinkMonthlyRent	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetPartylinkMonthlyRent* addOrUpdate(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent, CWriteableSysNetPartylinkMonthlyRent *pNewSysNetPartylinkMonthlyRent, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetPartylinkMonthlyRent，同时删除其索引
	///@param	pSysNetPartylinkMonthlyRent	要删除的CSysNetPartylinkMonthlyRent
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetPartylinkMonthlyRent
	///@param	pSysNetPartylinkMonthlyRent	要读取的CSysNetPartylinkMonthlyRent
	///@param	pTragetSysNetPartylinkMonthlyRent	存放结果的CSysNetPartylinkMonthlyRent
	void retrieve(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent, CWriteableSysNetPartylinkMonthlyRent *pTargetSysNetPartylinkMonthlyRent);
	
	///获取第一个CSysNetPartylinkMonthlyRent
	///@return	得到的第一个CSysNetPartylinkMonthlyRent，如果没有，则返回NULL
	CSysNetPartylinkMonthlyRent *getFirst(void);
	
	///获取下一个CSysNetPartylinkMonthlyRent
	///@return	得到下一个CSysNetPartylinkMonthlyRent，如果没有，则返回NULL
	CSysNetPartylinkMonthlyRent *getNext(void);
	
	///结束获取CSysNetPartylinkMonthlyRent
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetPartylinkMonthlyRentActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetPartylinkMonthlyRentActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetPartylinkMonthlyRentCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetPartylinkMonthlyRentCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetPartylinkMonthlyRentIteratorByLineName;

	///开始寻找CSysNetPartylinkMonthlyRent
	///@param	LineName	
	///@return	满足条件的地一个CSysNetPartylinkMonthlyRent，如果找不到，返回NULL
	CSysNetPartylinkMonthlyRent *startFindByLineName( const CReadOnlyParticipantNameType& LineName);

	///寻找下一个符合条件的CSysNetPartylinkMonthlyRent，必须在startFindByLineName以后，endFindByLineName之前叫用
	///@return	下一个满足条件CSysNetPartylinkMonthlyRent，如果已经没有一个满足要求了，则返回NULL
	CSysNetPartylinkMonthlyRent *findNextByLineName(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByLineName(void);

	friend class CSysNetPartylinkMonthlyRentIteratorBytheAll;

	///开始寻找CSysNetPartylinkMonthlyRent
	///@return	满足条件的地一个CSysNetPartylinkMonthlyRent，如果找不到，返回NULL
	CSysNetPartylinkMonthlyRent *startFindBytheAll();

	///寻找下一个符合条件的CSysNetPartylinkMonthlyRent，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysNetPartylinkMonthlyRent，如果已经没有一个满足要求了，则返回NULL
	CSysNetPartylinkMonthlyRent *findNextBytheAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindBytheAll(void);

	friend class CSysNetPartylinkMonthlyRentIteratorByAll;

	///开始寻找CSysNetPartylinkMonthlyRent
	///@return	满足条件的地一个CSysNetPartylinkMonthlyRent，如果找不到，返回NULL
	CSysNetPartylinkMonthlyRent *startFindByAll();

	///寻找下一个符合条件的CSysNetPartylinkMonthlyRent，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetPartylinkMonthlyRent，如果已经没有一个满足要求了，则返回NULL
	CSysNetPartylinkMonthlyRent *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetPartylinkMonthlyRent加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetPartylinkMonthlyRent	要加入的SysNetPartylinkMonthlyRent
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetPartylinkMonthlyRent *internalAdd(CWriteableSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent, bool bNoTransaction);
	
	
	///刷新该CSysNetPartylinkMonthlyRent的键值
	///@param	pSysNetPartylinkMonthlyRent	被刷新的CSysNetPartylinkMonthlyRent
	///@param	pNewSysNetPartylinkMonthlyRent	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent, CWriteableSysNetPartylinkMonthlyRent *pNewSysNetPartylinkMonthlyRent, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetPartylinkMonthlyRent，同时删除其索引
	///@param	pSysNetPartylinkMonthlyRent	要删除的CSysNetPartylinkMonthlyRent
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent, bool bNoTransaction);
/*
	///检查某个CSysNetPartylinkMonthlyRent是否属于本对象工厂
	///@param	pSysNetPartylinkMonthlyRent	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于LineName的索引
	CAVLTree *pSysLineNameIndex;
	
	
	///按照LineName检索时，存储的查询参数
	CParticipantNameType queryLineNameInSearchByLineName;
	
	///按照LineName检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByLineName;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchBytheAll;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetPartylinkMonthlyRent	要加入的SysNetPartylinkMonthlyRent
	virtual void beforeAdd(CWriteableSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent);
	
	///加入后触发
	///@param	pSysNetPartylinkMonthlyRent	已经加入的SysNetPartylinkMonthlyRent
	virtual void afterAdd(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent);

	///更新前触发	
	///@param	pSysNetPartylinkMonthlyRent	被刷新的CSysNetPartylinkMonthlyRent
	///@param	pNewSysNetPartylinkMonthlyRent	新的值
	virtual void beforeUpdate(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent, CWriteableSysNetPartylinkMonthlyRent *pNewSysNetPartylinkMonthlyRent);
	
	///更新后触发
	///@param	pSysNetPartylinkMonthlyRent	被刷新的CSysNetPartylinkMonthlyRent
	virtual void afterUpdate(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent);
	
	///删除前触发
	///@param	pSysNetPartylinkMonthlyRent	要删除的CSysNetPartylinkMonthlyRent
	virtual void beforeRemove(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent);
	
	///确认加入后触发
	///@param	pSysNetPartylinkMonthlyRent	已经加入的SysNetPartylinkMonthlyRent
	virtual void commitAdd(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent);

	///确认更新后触发
	///@param	pSysNetPartylinkMonthlyRent	被刷新的CSysNetPartylinkMonthlyRent
	///@param	poldSysNetPartylinkMonthlyRent	原来的值
	virtual void commitUpdate(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent, CWriteableSysNetPartylinkMonthlyRent *pOldSysNetPartylinkMonthlyRent);
	
	///确认删除后触发
	///@param	pSysNetPartylinkMonthlyRent	已经删除的CSysNetPartylinkMonthlyRent
	virtual void commitRemove(CWriteableSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent);

	///所有相关的触发器
	vector<CSysNetPartylinkMonthlyRentActionTrigger *> *pActionTriggers;
	vector<CSysNetPartylinkMonthlyRentCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetPartylinkMonthlyRent compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetNonPartyLinkInfoFactory是一个会员链路月租表的对象工厂。它包含了一批会员链路月租表，
///同时又建立了如下索引，以方便查询：
///	SysIDTypeIndex
///使用本对象工厂，可以完成对会员链路月租表的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///		使用findByOne，唯一找到对象
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetNonPartyLinkInfoFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetNonPartyLinkInfoFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxSysNetNonPartyLinkInfo，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CSysNetNonPartyLinkInfoFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetNonPartyLinkInfoFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的SysNetNonPartyLinkInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的SysNetNonPartyLinkInfo，文件名将根据配置文件中的定义SysNetNonPartyLinkInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的SysNetNonPartyLinkInfo
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的SysNetNonPartyLinkInfo，文件名将根据配置文件中的定义SysNetNonPartyLinkInfoCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CSysNetNonPartyLinkInfoResource;

	///将一个CSysNetNonPartyLinkInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetNonPartyLinkInfo	要加入的SysNetNonPartyLinkInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetNonPartyLinkInfo *add(CWriteableSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo, CTransaction *pTransaction=NULL);
	
	///刷新该CSysNetNonPartyLinkInfo的值
	///@param	pSysNetNonPartyLinkInfo	被刷新的CSysNetNonPartyLinkInfo
	///@param	pNewSysNetNonPartyLinkInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo, CWriteableSysNetNonPartyLinkInfo *pNewSysNetNonPartyLinkInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pSysNetNonPartyLinkInfo	  需要被刷新或者新增的CSysNetNonPartyLinkInfo,等于NULL表示是需要新增的
	///@param	pNewSysNetNonPartyLinkInfo	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CSysNetNonPartyLinkInfo* addOrUpdate(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo, CWriteableSysNetNonPartyLinkInfo *pNewSysNetNonPartyLinkInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CSysNetNonPartyLinkInfo，同时删除其索引
	///@param	pSysNetNonPartyLinkInfo	要删除的CSysNetNonPartyLinkInfo
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo, CTransaction *pTransaction=NULL);
	
	///获取某个CSysNetNonPartyLinkInfo
	///@param	pSysNetNonPartyLinkInfo	要读取的CSysNetNonPartyLinkInfo
	///@param	pTragetSysNetNonPartyLinkInfo	存放结果的CSysNetNonPartyLinkInfo
	void retrieve(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo, CWriteableSysNetNonPartyLinkInfo *pTargetSysNetNonPartyLinkInfo);
	
	///获取第一个CSysNetNonPartyLinkInfo
	///@return	得到的第一个CSysNetNonPartyLinkInfo，如果没有，则返回NULL
	CSysNetNonPartyLinkInfo *getFirst(void);
	
	///获取下一个CSysNetNonPartyLinkInfo
	///@return	得到下一个CSysNetNonPartyLinkInfo，如果没有，则返回NULL
	CSysNetNonPartyLinkInfo *getNext(void);
	
	///结束获取CSysNetNonPartyLinkInfo
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CSysNetNonPartyLinkInfoActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CSysNetNonPartyLinkInfoActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CSysNetNonPartyLinkInfoCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CSysNetNonPartyLinkInfoCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CSysNetNonPartyLinkInfoIteratorByAll;

	///开始寻找CSysNetNonPartyLinkInfo
	///@return	满足条件的地一个CSysNetNonPartyLinkInfo，如果找不到，返回NULL
	CSysNetNonPartyLinkInfo *startFindByAll();

	///寻找下一个符合条件的CSysNetNonPartyLinkInfo，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetNonPartyLinkInfo，如果已经没有一个满足要求了，则返回NULL
	CSysNetNonPartyLinkInfo *findNextByAll(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByAll(void);

	///寻找CSysNetNonPartyLinkInfo
	///@param	ID	
	///@return	找到的CSysNetNonPartyLinkInfo，如果找不到，返回NULL
	CSysNetNonPartyLinkInfo *findByOne( const CReadOnlyVolumeType&  ID);



private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CSysNetNonPartyLinkInfo加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pSysNetNonPartyLinkInfo	要加入的SysNetNonPartyLinkInfo
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CSysNetNonPartyLinkInfo *internalAdd(CWriteableSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo, bool bNoTransaction);
	
	
	///刷新该CSysNetNonPartyLinkInfo的键值
	///@param	pSysNetNonPartyLinkInfo	被刷新的CSysNetNonPartyLinkInfo
	///@param	pNewSysNetNonPartyLinkInfo	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo, CWriteableSysNetNonPartyLinkInfo *pNewSysNetNonPartyLinkInfo, bool updateIndex,bool bNoTransaction);
	
	///删除一个CSysNetNonPartyLinkInfo，同时删除其索引
	///@param	pSysNetNonPartyLinkInfo	要删除的CSysNetNonPartyLinkInfo
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo, bool bNoTransaction);
/*
	///检查某个CSysNetNonPartyLinkInfo是否属于本对象工厂
	///@param	pSysNetNonPartyLinkInfo	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于ID的索引
	CAVLTree *pSysIDTypeIndex;
	
	
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pSysNetNonPartyLinkInfo	要加入的SysNetNonPartyLinkInfo
	virtual void beforeAdd(CWriteableSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo);
	
	///加入后触发
	///@param	pSysNetNonPartyLinkInfo	已经加入的SysNetNonPartyLinkInfo
	virtual void afterAdd(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo);

	///更新前触发	
	///@param	pSysNetNonPartyLinkInfo	被刷新的CSysNetNonPartyLinkInfo
	///@param	pNewSysNetNonPartyLinkInfo	新的值
	virtual void beforeUpdate(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo, CWriteableSysNetNonPartyLinkInfo *pNewSysNetNonPartyLinkInfo);
	
	///更新后触发
	///@param	pSysNetNonPartyLinkInfo	被刷新的CSysNetNonPartyLinkInfo
	virtual void afterUpdate(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo);
	
	///删除前触发
	///@param	pSysNetNonPartyLinkInfo	要删除的CSysNetNonPartyLinkInfo
	virtual void beforeRemove(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo);
	
	///确认加入后触发
	///@param	pSysNetNonPartyLinkInfo	已经加入的SysNetNonPartyLinkInfo
	virtual void commitAdd(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo);

	///确认更新后触发
	///@param	pSysNetNonPartyLinkInfo	被刷新的CSysNetNonPartyLinkInfo
	///@param	poldSysNetNonPartyLinkInfo	原来的值
	virtual void commitUpdate(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo, CWriteableSysNetNonPartyLinkInfo *pOldSysNetNonPartyLinkInfo);
	
	///确认删除后触发
	///@param	pSysNetNonPartyLinkInfo	已经删除的CSysNetNonPartyLinkInfo
	virtual void commitRemove(CWriteableSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo);

	///所有相关的触发器
	vector<CSysNetNonPartyLinkInfoActionTrigger *> *pActionTriggers;
	vector<CSysNetNonPartyLinkInfoCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableSysNetNonPartyLinkInfo compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

#endif
