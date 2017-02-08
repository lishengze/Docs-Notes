/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CAVLTree.h
///@brief��������CAVLTree
///@history 
///20020214	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef CAVLTREE_H
#define CAVLTREE_H

#include "platform.h"
#include "CBaseObject.h"
#include "CFixMem.h"
#include "Allocator.h"

///TCompareFunc��һ���ȽϺ���ָ������
typedef int (* TCompareFunc)(const void *,const void *);

/////////////////////////////////////////////////////////////////////////
///CAVLNode��һ��ƽ�����ڵ����
///@author	���ض�
///@version	1.0,20020214
/////////////////////////////////////////////////////////////////////////
class CAVLNode
{
public:
	///���汾�ڵ��а����Ķ���
	const void *pObject;
	///���汾�ڵ�ĸ��ڵ㡢����ӽڵ���Ҷ��ӽڵ�
	CAVLNode *father, *left, *right;
	///ƽ��״��
	int depth;
};

/////////////////////////////////////////////////////////////////////////
///CAVLTree��һ�������������������Ƕ�ĳ�����͵����ݽṹ���Լ����ϵ�һ�ֱȽϺ�����
///���ɵ�ƽ������
///@author	���ض�
///@version	1.0,20020214
/////////////////////////////////////////////////////////////////////////
class CAVLTree : public CBaseObject
{
public:
	///���캯��������ռ䣬����һ�ÿյ�ƽ����
	///@param	maxUnit	��൥λ��
	///@param	compareFunc	�ȽϺ���ָ��
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	reuse	˵������洢�Ƿ���Ҫ����
	///@param	reuseID	������ʱ���������õı�ţ���������Ӧ��ʹ��-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CAVLTree(int maxUnit, TCompareFunc compareFunc,IMemoryAllocator *pAllocator,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���������������ͷſռ�
	virtual ~CAVLTree(void);
	
	virtual int isA(char *objectType);
	virtual char *getType(void);
	virtual void output(CLogger *pLogger,int indent=0);
	
	///�ڱ�ƽ�����м���һ���µĶ���ڵ�
	///@param	pObject	�µĶ�����׵�ַ
	///@return	������������˶���Ľڵ�
	CAVLNode *addObject(const void *pObject);
	
	///��ȡ��С��һ���ڵ�
	///@return	��С��һ���ڵ㣬�����û�нڵ㣬�򷵻�NULL
	CAVLNode *getSmallest(void);
	
	///��ȡ����һ���ڵ�
	///@return	����һ���ڵ㣬�����û�нڵ㣬�򷵻�NULL
	CAVLNode *getLargest(void);

	///Ѱ�ҵ�һ�����ڵ��ڴ˶���Ľڵ�
	///@param pObject	�Ƚ�ʱ�õĶ���
	///@return	��һ�����ڵ��ڴ˶���Ľڵ㣬��������ڴ˽ڵ㣬�򷵻�NULL
	CAVLNode *searchFirstGreatEqual(const void *pObject);
	
	///Ѱ�ҵ�һ�����ڴ˶���Ľڵ�
	///@param pObject	�Ƚ�ʱ�õĶ���
	///@return	��һ�����ڴ˶���Ľڵ㣬��������ڴ˽ڵ㣬�򷵻�NULL
	CAVLNode *searchFirstGreat(const void *pObject);
	
	///Ѱ�����һ��С�ڵ��ڴ˶���Ľڵ�
	///@param pObject	�Ƚ�ʱ�õĶ���
	///@return	���һ��С�ڵ��ڴ˶���Ľڵ㣬��������ڴ˽ڵ㣬�򷵻�NULL
	CAVLNode *searchLastLessEqual(const void *pObject);
	
	///Ѱ�����һ��С�ڴ˶���Ľڵ�
	///@param pObject	�Ƚ�ʱ�õĶ���
	///@return	���һ��С�ڴ˶���Ľڵ㣬��������ڴ˽ڵ㣬�򷵻�NULL
	CAVLNode *searchLastLess(const void *pObject);
	
	///Ѱ�ҵ�һ�����ڴ˶���Ľڵ�
	///@param pObject	�Ƚ�ʱ�õĶ���
	///@return	��һ�����ڴ˶���Ľڵ㣬��������ڴ˽ڵ㣬�򷵻�NULL
	CAVLNode *searchFirstEqual(const void *pObject);
	
	///Ѱ�����һ�����ڴ˶���Ľڵ�
	///@param pObject	�Ƚ�ʱ�õĶ���
	///@return	���һ�����ڴ˶���Ľڵ㣬��������ڴ˽ڵ㣬�򷵻�NULL
	CAVLNode *searchLastEqual(const void *pObject);
	
	///Ѱ����һ���ڵ㣬�����ڴ˽ڵ�ĵ�һ���ڵ�
	///@param pNode	Ŀǰ�ڵ�
	///@return	���ڴ˽ڵ�ĵ�һ���ڵ㣬��������ڴ˽ڵ㣬�򷵻�NULL
	CAVLNode *getNextNode(CAVLNode *pNode);
	
	///Ѱ��ǰһ���ڵ㣬��С�ڴ˽ڵ�����һ���ڵ�
	///@param pNode	Ŀǰ�ڵ�
	///@return	С�ڴ˽ڵ�����һ���ڵ㣬��������ڴ˽ڵ㣬�򷵻�NULL
	CAVLNode *getPrevNode(CAVLNode *pNode);
	
	///Ѱ�ҵ��ڴ˶���Ľڵ㣬����������ָ��ַ�����
	///@param pObject	�Ƚ�ʱ�õĶ���
	///@return	���ڴ˶���Ľڵ㣬��������ڴ˽ڵ㣬�򷵻�NULL
	CAVLNode *findObject(const void *pObject);

	///ɾ��ָ���ڵ�
	///@param	pNode	Ҫɾ���Ľڵ�
	void removeNode(CAVLNode *pNode);
	
	///ɾ������ָ������Ľڵ�
	///@param	pObject	Ҫɾ���Ķ���
	void removeObject(const void *pObject);
	
	///ȫ��ɾ��
	void removeAll(void);

	///ָ���ڵ��еĶ������˱仯����Ҫ���¼�������ƽ�����е�λ��
	///@param	pNode	�����仯�Ľڵ�
	///@return	�µĽڵ�
	CAVLNode *updateNode(CAVLNode *pNode);
	
	///ָ���������˱仯����Ҫ���¼�������ƽ�����е�λ��
	///@param pObject	�����仯�Ķ���
	///@return	�µĽڵ�
	CAVLNode *updateObject(const void *pObject);
	
	///�ж�Ŀǰ��ƽ�����Ƿ�Ϸ����˺�������������
	///@param	count	��ʾҪ����ƽ�����Ľڵ�����Ƿ�Ϊcount�����Ϊ-1�ͱ�ʾ�����
	///@return	NULL��ʾ�Ϸ������������ʾ�����������Ϣ
	char *isValid(int count=-1);

	///��ȡ���ñ��
	///@param	�����������ñ��
	int getReuseID(void);
private:
	///�洢�洢ƽ������CFixMem
	CFixMem *pIndexMem;
	
	///�洢�ȽϺ���ָ��
	TCompareFunc compareFunc;
	
	///��������ƽ��ṹ����ָ���ڵ㿪ʼ���ϵ���
	///@param	thisNode	��ʼ�����Ľڵ�
	void alterTree(CAVLNode *thisNode);
	
	///���ñ�ƽ�����ĸ�
	///@param	pNode	Ҫ����Ϊ���Ľڵ�
	void setRoot(CAVLNode *pNode);
	
	///��ȡ��ƽ�����ĸ�
	///@return	��ǰ�ĸ��ڵ�
	CAVLNode *getRoot(void);
};

#endif
