/////////////////////////////////////////////////////////////////////////
///@system 执行引擎系统
///@company 上海期货信息技术有限公司
///@file BaseDataStruct.h
///@brief定义了内存数据库用的基本数据结构类，以及iterator、trigger的基类
///@history 
///20060128	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef BASEDATASTRUCT_H
#define BASEDATASTRUCT_H

#include "platform.h"
#include "CBaseObject.h"
#include "customDataType.h"
#include "CTransaction.h"

///判断结果是否满足条件
extern bool satisfy(int value,int type);

///字符串比较函数
///@param	s1	字符串1
///@param	s2	字符串2
///@return	1表示大于，0表示等于，-1表示小于
int compare(const char *s1, const char *s2);

///整数比较函数
///@param	v1	整数1
///@param	v2	整数2
///@return	1表示大于，0表示等于，-1表示小于
int compare(const int v1,const int v2);

///64位无符号整数比较函数
///@param	v1	整数1
///@param	v2	整数2
///@return	1表示大于，0表示等于，-1表示小于
int compare(const QWORD v1,const QWORD v2);

///浮点数比较函数
///@param	v1	浮点数1
///@param	v2	浮点数2
///@return	1表示大于，0表示等于，-1表示小于
int compare(const double v1,const double v2);

///从buffer中获取下一个token，这里的token是以逗号或者换行分隔的
///在使用时，第一次应当传入指定的buffer，以后应当反复传入NULL，
///这样可以依次取出所有的token。本函数将改变buffer中的内容，叫用
///方有责任自己保护数据。本函数有重入问题，在一个取token的序列结
///束前，开始新的一个取token序列，将影响前面一个的结果。此问题和
///strtok的问题类似
///@param	buffer	要取token的buffer，NULL表示从上次取的buffer中取下一个
///@return	得到的token
char *getNextToken(char *buffer);

class CWriteableMonitorEntity;
class CMonitorEntityFactory;
class CWriteableEventEntity;
class CEventEntityFactory;

/////////////////////////////////////////////////////////////////////////
///CWriteableMonitorEntity是一个存储监控实体的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableMonitorEntity
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! MonitorObject.isValid())
			return 0;
		if (! MonitorItem.isValid())
			return 0;
		if (! MonitorTime.isValid())
			return 0;
		if (! Time.isValid())
			return 0;
		if (! ValueType.isValid())
			return 0;
		if (! AttrValue.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableMonitorEntity *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///监控对象
	CMonitorObjectType MonitorObject;
	///监控指标项
	CMonitorItemType MonitorItem;
	///监控时间
	CMonitorTimeType MonitorTime;
	///时间字符串格式
	CTimeType Time;
	///监控指标的值类型
	CValueTypeType ValueType;
	///监控指标的具体值
	CAttrValueType AttrValue;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableMonitorEntity CMonitorEntity;

/////////////////////////////////////////////////////////////////////////
///CMonitorEntityActionTrigger是操作监控实体时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMonitorEntityActionTrigger
{
public:
	///构造方法
	CMonitorEntityActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CMonitorEntityActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CMonitorEntityFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pMonitorEntity	要加入的MonitorEntity
	virtual void beforeAdd(CWriteableMonitorEntity *pMonitorEntity)
	{
		return;
	}
	
	///加入后触发
	///@param	pMonitorEntity	已经加入的MonitorEntity
	virtual void afterAdd(CMonitorEntity *pMonitorEntity)
	{
		return;
	}

	///更新前触发	
	///@param	pMonitorEntity	被刷新的CMonitorEntity
	///@param	pNewMonitorEntity	新的值
	virtual void beforeUpdate(CMonitorEntity *pMonitorEntity, CWriteableMonitorEntity *pNewMonitorEntity)
	{
		return;
	}
	
	///更新后触发
	///@param	pMonitorEntity	被刷新的CMonitorEntity
	virtual void afterUpdate(CMonitorEntity *pMonitorEntity)
	{
		return;
	}
	
	///删除前触发
	///@param	pMonitorEntity	要删除的CMonitorEntity
	virtual void beforeRemove(CMonitorEntity *pMonitorEntity)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CMonitorEntityFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMonitorEntityCommitTrigger是确认监控实体时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMonitorEntityCommitTrigger
{
public:
	///构造方法
	CMonitorEntityCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CMonitorEntityCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CMonitorEntityFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pMonitorEntity	已经加入的MonitorEntity
	virtual void commitAdd(CMonitorEntity *pMonitorEntity)
	{
		return;
	}

	///更新后触发
	///@param	pMonitorEntity	被刷新的CMonitorEntity
	///@param	poldMonitorEntity	原来的值
	virtual void commitUpdate(CMonitorEntity *pMonitorEntity, CWriteableMonitorEntity *pOldMonitorEntity)
	{
		return;
	}
	
	///删除后触发
	///@param	pMonitorEntity	已经删除的CMonitorEntity
	virtual void commitRemove(CWriteableMonitorEntity *pMonitorEntity)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CMonitorEntityFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMonitorEntityIterator是一个对监控实体的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMonitorEntityIterator
{
public:
	///构造方法
	CMonitorEntityIterator(void)
	{
	}

	///构造方法
	CMonitorEntityIterator(CMonitorEntityFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CMonitorEntityIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个MonitorEntity
	///@return	下一个满足条件CMonitorEntity，如果已经没有一个满足要求了，则返回NULL
	virtual CMonitorEntity *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CMonitorEntityFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pMonitorEntity 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMonitorEntity * pMonitorEntity,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CMonitorEntityFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableEventEntity是一个存储事件实体的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableEventEntity
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! MonitorTime.isValid())
			return 0;
		if (! EventName.isValid())
			return 0;
		if (! MonitorObject.isValid())
			return 0;
		if (! EventDes.isValid())
			return 0;
		if (! ProcessFlag.isValid())
			return 0;
		if (! Time.isValid())
			return 0;
		if (! WarningLevel.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableEventEntity *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///监控时间
	CMonitorTimeType MonitorTime;
	///事件名
	CMonitorItemType EventName;
	///监控对象ID
	CMonitorObjectType MonitorObject;
	///事件描述
	CTypeDescriptionType EventDes;
	///事件持续标记
	CTypeProcessFlagType ProcessFlag;
	///时间字符串格式
	CTimeType Time;
	///日志事件级别
	CTypeWarningLevelType WarningLevel;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableEventEntity CEventEntity;

/////////////////////////////////////////////////////////////////////////
///CEventEntityActionTrigger是操作事件实体时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CEventEntityActionTrigger
{
public:
	///构造方法
	CEventEntityActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CEventEntityActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CEventEntityFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pEventEntity	要加入的EventEntity
	virtual void beforeAdd(CWriteableEventEntity *pEventEntity)
	{
		return;
	}
	
	///加入后触发
	///@param	pEventEntity	已经加入的EventEntity
	virtual void afterAdd(CEventEntity *pEventEntity)
	{
		return;
	}

	///更新前触发	
	///@param	pEventEntity	被刷新的CEventEntity
	///@param	pNewEventEntity	新的值
	virtual void beforeUpdate(CEventEntity *pEventEntity, CWriteableEventEntity *pNewEventEntity)
	{
		return;
	}
	
	///更新后触发
	///@param	pEventEntity	被刷新的CEventEntity
	virtual void afterUpdate(CEventEntity *pEventEntity)
	{
		return;
	}
	
	///删除前触发
	///@param	pEventEntity	要删除的CEventEntity
	virtual void beforeRemove(CEventEntity *pEventEntity)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CEventEntityFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CEventEntityCommitTrigger是确认事件实体时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CEventEntityCommitTrigger
{
public:
	///构造方法
	CEventEntityCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CEventEntityCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CEventEntityFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pEventEntity	已经加入的EventEntity
	virtual void commitAdd(CEventEntity *pEventEntity)
	{
		return;
	}

	///更新后触发
	///@param	pEventEntity	被刷新的CEventEntity
	///@param	poldEventEntity	原来的值
	virtual void commitUpdate(CEventEntity *pEventEntity, CWriteableEventEntity *pOldEventEntity)
	{
		return;
	}
	
	///删除后触发
	///@param	pEventEntity	已经删除的CEventEntity
	virtual void commitRemove(CWriteableEventEntity *pEventEntity)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CEventEntityFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CEventEntityIterator是一个对事件实体的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CEventEntityIterator
{
public:
	///构造方法
	CEventEntityIterator(void)
	{
	}

	///构造方法
	CEventEntityIterator(CEventEntityFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CEventEntityIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个EventEntity
	///@return	下一个满足条件CEventEntity，如果已经没有一个满足要求了，则返回NULL
	virtual CEventEntity *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CEventEntityFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pEventEntity 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableEventEntity * pEventEntity,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CEventEntityFactory *m_Factory;	
};


#include "databaseFactories.h"

#endif


