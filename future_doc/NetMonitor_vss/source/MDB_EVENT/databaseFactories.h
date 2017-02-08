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

class CMonitorEntityFactory;
class CMonitorEntityResource;
class CEventEntityFactory;
class CEventEntityResource;

/////////////////////////////////////////////////////////////////////////
///CMonitorEntityFactory是一个监控实体的对象工厂。它包含了一批监控实体，
///同时又建立了如下索引，以方便查询：
///	KeyIndex
///使用本对象工厂，可以完成对监控实体的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用findByKey，唯一找到对象
///		使用startFindByTime，findNextByTime和endFindByTime完成查询操作
///		使用findByKey1，唯一找到对象
///		使用startFindByAll，findNextByAll和endFindByAll完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMonitorEntityFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CMonitorEntityFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxMonitorEntity，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CMonitorEntityFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CMonitorEntityFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的MonitorEntity
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的MonitorEntity，文件名将根据配置文件中的定义MonitorEntityCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的MonitorEntity
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的MonitorEntity，文件名将根据配置文件中的定义MonitorEntityCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CMonitorEntityResource;

	///将一个CMonitorEntity加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pMonitorEntity	要加入的MonitorEntity
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CMonitorEntity *add(CWriteableMonitorEntity *pMonitorEntity, CTransaction *pTransaction=NULL);
	
	///刷新该CMonitorEntity的值
	///@param	pMonitorEntity	被刷新的CMonitorEntity
	///@param	pNewMonitorEntity	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CMonitorEntity *pMonitorEntity, CWriteableMonitorEntity *pNewMonitorEntity, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pMonitorEntity	  需要被刷新或者新增的CMonitorEntity,等于NULL表示是需要新增的
	///@param	pNewMonitorEntity	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CMonitorEntity* addOrUpdate(CMonitorEntity *pMonitorEntity, CWriteableMonitorEntity *pNewMonitorEntity, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CMonitorEntity，同时删除其索引
	///@param	pMonitorEntity	要删除的CMonitorEntity
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CMonitorEntity *pMonitorEntity, CTransaction *pTransaction=NULL);
	
	///获取某个CMonitorEntity
	///@param	pMonitorEntity	要读取的CMonitorEntity
	///@param	pTragetMonitorEntity	存放结果的CMonitorEntity
	void retrieve(CMonitorEntity *pMonitorEntity, CWriteableMonitorEntity *pTargetMonitorEntity);
	
	///获取第一个CMonitorEntity
	///@return	得到的第一个CMonitorEntity，如果没有，则返回NULL
	CMonitorEntity *getFirst(void);
	
	///获取下一个CMonitorEntity
	///@return	得到下一个CMonitorEntity，如果没有，则返回NULL
	CMonitorEntity *getNext(void);
	
	///结束获取CMonitorEntity
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CMonitorEntityActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CMonitorEntityActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CMonitorEntityCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CMonitorEntityCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	///寻找CMonitorEntity
	///@param	MonitorObject	监控对象
	///@param	MonitorItem	监控指标项
	///@param	MonitorTime	监控时间
	///@return	找到的CMonitorEntity，如果找不到，返回NULL
	CMonitorEntity *findByKey( const CReadOnlyMonitorObjectType&  MonitorObject,  const CReadOnlyMonitorItemType&  MonitorItem,  const CReadOnlyMonitorTimeType&  MonitorTime);



	friend class CMonitorEntityIteratorByTime;

	///开始寻找CMonitorEntity
	///@param	MonitorObject	监控对象
	///@param	MonitorItem	监控指标项
	///@param	MonitorTime	监控时间
	///@return	满足条件的地一个CMonitorEntity，如果找不到，返回NULL
	CMonitorEntity *startFindByTime( const CReadOnlyMonitorObjectType& MonitorObject,  const CReadOnlyMonitorItemType& MonitorItem,  const CReadOnlyMonitorTimeType& MonitorTime);

	///寻找下一个符合条件的CMonitorEntity，必须在startFindByTime以后，endFindByTime之前叫用
	///@return	下一个满足条件CMonitorEntity，如果已经没有一个满足要求了，则返回NULL
	CMonitorEntity *findNextByTime(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByTime(void);

	///寻找CMonitorEntity
	///@param	MonitorObject	监控对象
	///@param	MonitorItem	监控指标项
	///@return	找到的CMonitorEntity，如果找不到，返回NULL
	CMonitorEntity *findByKey1( const CReadOnlyMonitorObjectType&  MonitorObject,  const CReadOnlyMonitorItemType&  MonitorItem);



	friend class CMonitorEntityIteratorByAll;

	///开始寻找CMonitorEntity
	///@return	满足条件的地一个CMonitorEntity，如果找不到，返回NULL
	CMonitorEntity *startFindByAll();

	///寻找下一个符合条件的CMonitorEntity，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CMonitorEntity，如果已经没有一个满足要求了，则返回NULL
	CMonitorEntity *findNextByAll(void);

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
	
	
	///将一个CMonitorEntity加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pMonitorEntity	要加入的MonitorEntity
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CMonitorEntity *internalAdd(CWriteableMonitorEntity *pMonitorEntity, bool bNoTransaction);
	
	
	///刷新该CMonitorEntity的键值
	///@param	pMonitorEntity	被刷新的CMonitorEntity
	///@param	pNewMonitorEntity	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CMonitorEntity *pMonitorEntity, CWriteableMonitorEntity *pNewMonitorEntity, bool updateIndex,bool bNoTransaction);
	
	///删除一个CMonitorEntity，同时删除其索引
	///@param	pMonitorEntity	要删除的CMonitorEntity
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CMonitorEntity *pMonitorEntity, bool bNoTransaction);
/*
	///检查某个CMonitorEntity是否属于本对象工厂
	///@param	pMonitorEntity	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CMonitorEntity *pMonitorEntity);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于MonitorObject+MonitorItem+MonitorTime的索引
	CAVLTree *pKeyIndex;
	
	
	///按照MonitorObject，MonitorItem，MonitorTime检索时，存储的查询参数
	CMonitorObjectType queryMonitorObjectInSearchByTime;
	CMonitorItemType queryMonitorItemInSearchByTime;
	CMonitorTimeType queryMonitorTimeInSearchByTime;
	
	///按照MonitorObject，MonitorItem，MonitorTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByTime;
	///按照检索时，存储的查询参数
	
	///按照检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByAll;
	
	///加入前触发
	///@param	pMonitorEntity	要加入的MonitorEntity
	virtual void beforeAdd(CWriteableMonitorEntity *pMonitorEntity);
	
	///加入后触发
	///@param	pMonitorEntity	已经加入的MonitorEntity
	virtual void afterAdd(CMonitorEntity *pMonitorEntity);

	///更新前触发	
	///@param	pMonitorEntity	被刷新的CMonitorEntity
	///@param	pNewMonitorEntity	新的值
	virtual void beforeUpdate(CMonitorEntity *pMonitorEntity, CWriteableMonitorEntity *pNewMonitorEntity);
	
	///更新后触发
	///@param	pMonitorEntity	被刷新的CMonitorEntity
	virtual void afterUpdate(CMonitorEntity *pMonitorEntity);
	
	///删除前触发
	///@param	pMonitorEntity	要删除的CMonitorEntity
	virtual void beforeRemove(CMonitorEntity *pMonitorEntity);
	
	///确认加入后触发
	///@param	pMonitorEntity	已经加入的MonitorEntity
	virtual void commitAdd(CMonitorEntity *pMonitorEntity);

	///确认更新后触发
	///@param	pMonitorEntity	被刷新的CMonitorEntity
	///@param	poldMonitorEntity	原来的值
	virtual void commitUpdate(CMonitorEntity *pMonitorEntity, CWriteableMonitorEntity *pOldMonitorEntity);
	
	///确认删除后触发
	///@param	pMonitorEntity	已经删除的CMonitorEntity
	virtual void commitRemove(CWriteableMonitorEntity *pMonitorEntity);

	///所有相关的触发器
	vector<CMonitorEntityActionTrigger *> *pActionTriggers;
	vector<CMonitorEntityCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableMonitorEntity compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CEventEntityFactory是一个事件实体的对象工厂。它包含了一批事件实体，
///同时又建立了如下索引，以方便查询：
///	KeyIndex
///	KeyObject
///使用本对象工厂，可以完成对事件实体的增删改查操作。具体方法如下：
///	增加：叫用add，完成加入
///	删除：叫用remove就可以删除
///	查询：有如下方法可以查询：
///		使用startFindByKey，findNextByKey和endFindByKey完成查询操作
///		使用startFindByObject，findNextByObject和endFindByObject完成查询操作
///	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
///	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
///		在retrieve时，也可以指定事务，此时将取出经过update的新数据
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CEventEntityFactory :public CDatabaseDataFactory
{
public:
	///构造方法
	///@param	maxUnit	初始的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CEventEntityFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///构造方法
	///@param	pConfig	当前的配置文件，本对象将根据配置文件中的定义MaxEventEntity，设置最到的对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	CEventEntityFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CEventEntityFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///从CSV文件中读取所有的EventEntity
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(char *filename);

	///从CSV文件中读取所有的EventEntity，文件名将根据配置文件中的定义EventEntityCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int readCSV(CConfig *pConfig);
	
	///向CSV文件中写出所有的EventEntity
	///@param	filename	文件名
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(char *filename);

	///向CSV文件中写出所有的EventEntity，文件名将根据配置文件中的定义EventEntityCSVFile
	///@param	pConfig	当前的配置文件
	///@return	1表示完成，0表示没有完成
	virtual int writeCSV(CConfig *pConfig);

	///将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	///将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	///清空所有的记录
	virtual void clearAll(void);

	friend class CEventEntityResource;

	///将一个CEventEntity加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pEventEntity	要加入的EventEntity
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CEventEntity *add(CWriteableEventEntity *pEventEntity, CTransaction *pTransaction=NULL);
	
	///刷新该CEventEntity的值
	///@param	pEventEntity	被刷新的CEventEntity
	///@param	pNewEventEntity	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	是否需要更新索引
	void update(CEventEntity *pEventEntity, CWriteableEventEntity *pNewEventEntity, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///增加或者更新数据
	///@param	pEventEntity	  需要被刷新或者新增的CEventEntity,等于NULL表示是需要新增的
	///@param	pNewEventEntity	新的值
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	///@param	updateIndex	  是否需要更新索引
	///@param	新增或者修改后的数据
	CEventEntity* addOrUpdate(CEventEntity *pEventEntity, CWriteableEventEntity *pNewEventEntity, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///删除一个CEventEntity，同时删除其索引
	///@param	pEventEntity	要删除的CEventEntity
	///@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	void remove(CEventEntity *pEventEntity, CTransaction *pTransaction=NULL);
	
	///获取某个CEventEntity
	///@param	pEventEntity	要读取的CEventEntity
	///@param	pTragetEventEntity	存放结果的CEventEntity
	void retrieve(CEventEntity *pEventEntity, CWriteableEventEntity *pTargetEventEntity);
	
	///获取第一个CEventEntity
	///@return	得到的第一个CEventEntity，如果没有，则返回NULL
	CEventEntity *getFirst(void);
	
	///获取下一个CEventEntity
	///@return	得到下一个CEventEntity，如果没有，则返回NULL
	CEventEntity *getNext(void);
	
	///结束获取CEventEntity
	void endGet(void);

	///加入一个操作触发器
	///@param	pTrigger	要加入的操作触发器
	///@return	1表示成功，0表示失败
	int addActionTrigger(CEventEntityActionTrigger *pTrigger);
	
	///删除一个操作触发器
	///@param	pTrigger	要删除的操作触发器
	///@return	1表示成功，0表示失败
	int removeActionTrigger(CEventEntityActionTrigger *pTrigger);

	///加入一个确认触发器
	///@param	pTrigger	要加入的确认触发器
	///@return	1表示成功，0表示失败
	int addCommitTrigger(CEventEntityCommitTrigger *pTrigger);
	
	///删除一个确认触发器
	///@param	pTrigger	要删除的确认触发器
	///@return	1表示成功，0表示失败
	int removeCommitTrigger(CEventEntityCommitTrigger *pTrigger);
	
	///激活确认触发器，缺省是激活的
	///@param	activation	true表示要激活，false表示要停用
	void activeCommitTrigger(bool activation);

	friend class CEventEntityIteratorByKey;

	///开始寻找CEventEntity
	///@param	EventName	事件名
	///@param	MonitorTime	监控时间
	///@return	满足条件的地一个CEventEntity，如果找不到，返回NULL
	CEventEntity *startFindByKey( const CReadOnlyMonitorItemType& EventName,  const CReadOnlyMonitorTimeType& MonitorTime);

	///寻找下一个符合条件的CEventEntity，必须在startFindByKey以后，endFindByKey之前叫用
	///@return	下一个满足条件CEventEntity，如果已经没有一个满足要求了，则返回NULL
	CEventEntity *findNextByKey(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByKey(void);

	friend class CEventEntityIteratorByObject;

	///开始寻找CEventEntity
	///@param	MonitorObject	对象名
	///@param	EventName	事件名
	///@param	MonitorTime	监控时间
	///@return	满足条件的地一个CEventEntity，如果找不到，返回NULL
	CEventEntity *startFindByObject( const CReadOnlyMonitorObjectType& MonitorObject,  const CReadOnlyMonitorItemType& EventName,  const CReadOnlyMonitorTimeType& MonitorTime);

	///寻找下一个符合条件的CEventEntity，必须在startFindByObject以后，endFindByObject之前叫用
	///@return	下一个满足条件CEventEntity，如果已经没有一个满足要求了，则返回NULL
	CEventEntity *findNextByObject(void);

	///结束这一次查询，在完成查询后必须叫用本方法
	void endFindByObject(void);

private:
	///完成自己的初始化工作
	///@param	maxUnit	最多的数据对象个数
	///@param	pAllocator	进行内存管理的分配器
	///@param	pIndexMap	索引名称和内存编号的对应表，在非重用时会写入，在重用时只读出
	///@param	reuse	是否重用
	///@param	reuseID	重用编号，非重用时应当置为-1
	///@param	readOnly	1表示该CFixMem是只读的，0表示可以读写
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///将一个CEventEntity加入到该对象工厂，实质上是完成修改索引的工作
	///@param	pEventEntity	要加入的EventEntity
	///@param	bNoTransaction 是否不属于任何事务
	///@return	加入后该对象的位置，当pTransaction!=NULL时，总是返回NULL
	CEventEntity *internalAdd(CWriteableEventEntity *pEventEntity, bool bNoTransaction);
	
	
	///刷新该CEventEntity的键值
	///@param	pEventEntity	被刷新的CEventEntity
	///@param	pNewEventEntity	新的值
	///@param	updateIndex	是否需要更新索引
	///@param	bNoTransaction 是否不属于任何事务
	void internalUpdate(CEventEntity *pEventEntity, CWriteableEventEntity *pNewEventEntity, bool updateIndex,bool bNoTransaction);
	
	///删除一个CEventEntity，同时删除其索引
	///@param	pEventEntity	要删除的CEventEntity
	///@param	bNoTransaction 是否不属于任何事务
	void internalRemove(CEventEntity *pEventEntity, bool bNoTransaction);
/*
	///检查某个CEventEntity是否属于本对象工厂
	///@param	pEventEntity	要检查的对象
	///@exception	CDesignError	如果不属于，则抛出此异常
	void checkAddress(CEventEntity *pEventEntity);
*/
	///使用的配置文件
	CConfig *m_pConfig;

	///基于EventName+MonitorTime的索引
	CAVLTree *pKeyIndex;
	///基于MonitorObject+EventName+MonitorTime的索引
	CAVLTree *pKeyObject;
	
	
	///按照EventName，MonitorTime检索时，存储的查询参数
	CMonitorItemType queryEventNameInSearchByKey;
	CMonitorTimeType queryMonitorTimeInSearchByKey;
	
	///按照EventName，MonitorTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByKey;
	///按照MonitorObject，EventName，MonitorTime检索时，存储的查询参数
	CMonitorObjectType queryMonitorObjectInSearchByObject;
	CMonitorItemType queryEventNameInSearchByObject;
	CMonitorTimeType queryMonitorTimeInSearchByObject;
	
	///按照MonitorObject，EventName，MonitorTime检索时，存储最后一次找到的索引节点
	CAVLNode *pLastFoundInSearchByObject;
	
	///加入前触发
	///@param	pEventEntity	要加入的EventEntity
	virtual void beforeAdd(CWriteableEventEntity *pEventEntity);
	
	///加入后触发
	///@param	pEventEntity	已经加入的EventEntity
	virtual void afterAdd(CEventEntity *pEventEntity);

	///更新前触发	
	///@param	pEventEntity	被刷新的CEventEntity
	///@param	pNewEventEntity	新的值
	virtual void beforeUpdate(CEventEntity *pEventEntity, CWriteableEventEntity *pNewEventEntity);
	
	///更新后触发
	///@param	pEventEntity	被刷新的CEventEntity
	virtual void afterUpdate(CEventEntity *pEventEntity);
	
	///删除前触发
	///@param	pEventEntity	要删除的CEventEntity
	virtual void beforeRemove(CEventEntity *pEventEntity);
	
	///确认加入后触发
	///@param	pEventEntity	已经加入的EventEntity
	virtual void commitAdd(CEventEntity *pEventEntity);

	///确认更新后触发
	///@param	pEventEntity	被刷新的CEventEntity
	///@param	poldEventEntity	原来的值
	virtual void commitUpdate(CEventEntity *pEventEntity, CWriteableEventEntity *pOldEventEntity);
	
	///确认删除后触发
	///@param	pEventEntity	已经删除的CEventEntity
	virtual void commitRemove(CWriteableEventEntity *pEventEntity);

	///所有相关的触发器
	vector<CEventEntityActionTrigger *> *pActionTriggers;
	vector<CEventEntityCommitTrigger *> *pCommitTriggers;
	
	///进行查询时，用于比较的对象
	CWriteableEventEntity compareObject;
	
	///是否激活确认触发器
	bool m_activeCommitTrigger;
};

#endif
