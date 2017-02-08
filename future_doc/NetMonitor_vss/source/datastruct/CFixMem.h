/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CFixMem.h
///@brief	��������CFixMem
///@history 
///20020214	���ض�		�������ļ�
///20020524	���ض�		������DEBUG�õ�dump����
///20041003	���ض�		ͨ��������ΪgetFirst/getNext/endGet�������Ч��
///20050626 �ż���		�޸��˱�ʾ�鱻ʹ�õķ�����ͬʱ�������Զ������Ĺ���
/////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
/// ���е����ݽṹ˵��
/// 1. ��ֻ��һ���ڴ汻�����ʱ��
///     ____________________________________________________________________________
///	    |TFixMemHeadStruct | ��ʹ�õ���Ϣ		|(��ʹ�õĿ�) | δ��ʹ�õ��ڴ��� 	|																
///		|(������Ϣ)		   |(��С (size-1)/8*8	|			  | ָ��ָ����һ������	|
///		|__________________|____________________|_____________|_____________________|
/// 
/// 2.������ڴ����򱻷����ʱ��,��һ������Ľṹͬ��,�����������ڴ���������ͼ
///     ________________________________________________________________________
///	    |FixMemLinker| ��ʹ�õ���Ϣ			|(��ʹ�õĿ�) | δ��ʹ�õ��ڴ��� 	|																
///		|(������Ϣ)	 |(��С (size-1)/8*8	|			  | ָ��ָ����һ������	|
///		|___________ |______________________|_____________|_____________________|
///
/// 3.��ʹ���ļ������,���ļ��б���Ľṹ����:
///     __________________________________________________________________________________
///	    |int ��ʾ����	| ��ʹ�õ���Ϣ		| ������	| ��ʹ�õ���Ϣ		| ������	  |														
///		|Chunk������	|(��С (size-1)/8*8	|			| (��С (size-1)/8*8|			  |......
///		|_______________|___________________|___________|___________________|_____________|
///
//////////////////////////////////////////////////////////////////////////


#ifndef CFIXMEM_H
#define CFIXMEM_H

#include "platform.h"
#include "CBaseObject.h"
#include "Allocator.h"
#include <vector>
using namespace std;

#define RESERVE_ID			1024	///������ID,�Լ����õ�MemID����С�����ֵ

///��ʾ�ڴ���еĽṹ
typedef struct TFreeHeadStruct
{
	struct TFreeHeadStruct *pNext;	///ָ����һ������λ�õ�ָ��
}	TFreeHead;


struct FixMemLinker
{
//	int allocCounnt;				///���Chunk�ж������򱻷���ʹ��
//	int dummy;
	TFreeHead *pHead;
	FixMemLinker* pNextChunk;
};

typedef struct TFixMemHeadStruct	
{
	///���浥λ��С�����λ��
	int unitSize, maxUnit;
	
	///ʵ�ʱ���ĵ�λ��С
	int storeUnitSize;
		
	///�Ѿ�����Ĵ�С
	int allocCount;
	
	int dummy;

	///�Ѿ�����Ŀ�����
	int chunkNumber;

	///���ж��е�ͷ��β
	TFreeHead *pHead;
	
	///ָ����һ�����ָ��
	FixMemLinker *pNextChunk;

}	TFixMemHead;


///���к�����˵��CFixMem������ʲôλ��
///NORMAL_MEMORYָ������ͨʹ�õ��ڴ�
#define NORMAL_MEMORY 1
///SHARE_MEMORYָ����ϵͳ�ṩ�Ĺ����ڴ�
#define SHARE_MEMORY 2
///FILE_MEMORYָ������ͨʹ�õ��ڴ棬������Ҫͬʱд�ļ�
#define FILE_MEMORY 3

/////////////////////////////////////////////////////////////////////////
///CFixMem��һ���̶���λ��С���̶����޵��ڴ��������������������󡢾����޸ġ�
///��������޵Ĺ̶����ݽṹ���ڴ��������
///@author	���ض�
///@version	1.0,20020214
/////////////////////////////////////////////////////////////////////////
class CFixMem : public CBaseObject
{
public:
	///���췽��������ռ䣬���ó�ֵ���������п�����
	///@param	unitSize	ÿ����λ�Ĵ�С�����ֽڼƣ�����4�ֽ�
	///@param	maxUnit	�������ĵ�λ������Ӧ������0
	///@param   initUnit ��ʼ�����Ŀ���,��ʼ��СΪ10
	///@param	reuse	˵������洢�Ƿ���Ҫ����
	///@param	reuseID	ָ��������Ҫ�����Ĵ洢��λ�ã�ֻ�е�����ͨ�ڴ棬�����õ�����£����ֵ������
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	///@exception	CDesignError	�������������Ҫ�����׳����쳣
	///@exception	CRuntimeError	����ڴ治�������׳����쳣
	CFixMem(int unitSize, int maxUnit,IMemoryAllocator *pAllocator,bool reuse=false, int reuseID = -1, int readOnly=0,int initUnit=1);

	///�����������ͷ����пռ�
	virtual ~CFixMem(void);

	virtual int isA(char *objectType);
	virtual char *getType(void);
	virtual void output(CLogger *pLogger,int indent=0);

	///����һ����λ��С
	///@exception	CRuntimeError	�����������Ѿ��ﵽmaxUnit�����׳����쳣
	virtual void *alloc(void);

	///�ͷ�һ����λ
	///@param	pObject	 Ҫ�ͷŵĵ�λ��ַ
	///@exception	CDesignError	���pObject�����ϱ�CFixMem�����ĵ�ַ�����׳����쳣
	virtual void free(const void *pObject);

	///�ͷ�n����λ
	///@param	pObject	 Ҫ�ͷŵĵ�λ��ַ
	///@param	pObject	 ������N��
	///@exception	CDesignError	���pObject�����ϱ�CFixMem�����ĵ�ַ�����׳����쳣
	void free(const void *pObject,int n);

	///ȫ���ͷ�
	virtual void freeAll(void);

	///��ȡ��CFixMem���Ѿ��еļ�¼����
	///@return	��¼����
	virtual int getCount(void);

	///��ȡ��һ����¼������Ĵ����ǲ�һ���ģ�ֻ��һ��������б��ϵģ������������ֻ���룬
	///�Ӳ��ͷţ���ô��ȡ�Ĵ����д��Ĵ�������ͬ�ġ�
	///@return	��һ����¼�ĵ�ַ�����û�м�¼���򷵻�NULL
	virtual const void *getFirst(void);

	///��ȡ��һ����¼������Ĵ����ǲ�һ���ģ�ֻ��һ��������б��ϵģ������������ֻ���룬
	///�Ӳ��ͷţ���ô��ȡ�Ĵ����д��Ĵ�������ͬ�ġ�
	///@return	��һ����¼�ĵ�ַ�����û����һ����¼���򷵻�NULL
	virtual const void *getNext(void);

	///����������¼
	virtual void endGet(void);

	///�����±귽ʽ����ȡ��¼
	///@param	id	��¼�ı�ţ���ΧӦ����0��maxUnt-1
	///@return	�ñ�ŵļ�¼������ü�¼�Ѿ�ɾ���ˣ���ô����NULL
	virtual const void *getObject(const int id);

	///��ʾCFixMem��ϵͳ�޸���pObjectָ������ݣ�����FILE_MEMORY���������Ҫд��
	///@param	pObject	��ʾ�޸ĵĶ����ַ
	virtual void updateObject(const void *pObject);

	///��ȡ����õ����ڴ���׵�ַ
	///@return	�׵�ַ
	virtual const void *getStartAddress(void);

	///��ȡ��Ϊ�����ڴ淽ʽ�õ��Ĺ����ڴ��
	///@return	�����ڴ�ţ������ʹ�ù����ڴ棬�򷵻�-1
	virtual const int getMemoryBlockID(void);

	///��鱾CFixMem�Ƿ�����
	///@param	freeCount	Ҫȷ�Ͽ��еĿ������Ǵ�ֵ���������-1����ʾ������������
	///@return	1��ʾ������0��ʾ������
	//	virtual int isValid(int freeCount=-1);

	///������д���ļ���,����DEBUG
	void dump(FILE *);
private:
	///�����ڴ��
	///@param blockID �ڴ���ID,��0��ʼ
	///@param reuse   �Ƿ�����
	///@param	space	ָ��������Ҫ�����Ĵ洢��λ�ã�ֻ�е�����ͨ�ڴ棬�����õ�����£����ֵ������
	///		��media=NORMAL_MEMORYʱ��spaceָ���ڴ��е�ʵ�ʿռ�
	///		��media=SHARE_MEMORYʱ��space�ǹ����ڴ��ŵ�����ָ��
	///		��media=FILE_MEMORYʱ��spaceָ���ļ���
	void InitialMemoryBlock(int blockID,bool reuse,int reuseID,bool isInit = false);

	///�����ڴ��������ü���
	///@param �����õ��ڴ��ַ
	void IncreaseUseCount(const void *pObject);

	///�����ڴ��������ü���
	///@param �����õ��ڴ��ַ
	void DecreaseUseCount(const void *pObject);

	///���pObject�Ƿ�ָ��CFixMem��һ���Ϸ��Ķ���
	///@param	pObject	Ҫ���ĵ�ַ
	///@return	1��ʾ�Ϸ���0��ʾ�Ƿ�
	virtual int checkAddress(const void *pObject);

	int	getIDByAddress(const void* pObject);

private:
	///�����ڴ�ı�ţ����ڷǹ����ڴ棬��ֵΪ-1
	int reuseID;

	///ͷ˵�����λ��
	TFixMemHead *m_head;

	///ʵ�����ݵĿռ��׵�ַ
	//char *m_myMemory;
	vector<char *> m_myMemoryVect;

	///ʹ��getFirst��getNext��endGetʱ������һ�η���ֵ
	int m_lastId;

	///��ʾ��CFixMem�Ƿ�ֻ��
	int m_readOnly;

	///��ʾ���ν���getFirst,getNext���������˼��������ڶԴ˺��������Ż�
	//int gotCount;

	///��ʾ��CFixMem�д��ڵ�����ţ�����֤�ñ����ֵ�����Ǳ�֤���ڵ��ڸñ�ŵ�û��ֵ
	int m_largestID;

	///��ʾ������Щ�鱻ʹ�õ���Ϣ���׵�ַ����ֹ���̽�������������¼��ʱ��Ҫ��������������
	char *m_pUsedBlockInfoOffset;

	///��ʾ��ʾ�ڴ�ʹ��״�����б�Ĵ�С
	int   m_blockIndexSize;

	///��ʾ�洢�Ķ���Ĵ�С
	int   m_unitSize;

	///ÿһ�������Դ洢���ڴ���С
	int   m_maxUnit;


	int	  m_initUnit;


	int	  m_firstBlockID;

	IMemoryAllocator *m_pMemoryAllocator;

	int   m_reuseID;

public:		//����������public ��Ϊ�˲��ԣ�������ĳ�private		
	///���õ�n�����ʹ��״̬
	///@param	blockID	�ڴ��ı�ʾ
	///@param	bUsed	ʹ��״̬,true ��ʾʹ�ã�false ��ʾfree
	void SetBlockUsedState(int blockID,bool bUsed);

	///��ȡ��n�����ʹ��״̬
	///@param	blockID	�ڴ��ı�ʾ
	///@return	true��ʾ�ѱ�ʹ�ã�false��ʾδ��ʹ��
	bool GetBlockUsedState(int blockID);

	///���õ�n�����ʹ��״̬
	///@param	pvoid	�ڴ���ַ
	///@param	bUsed	ʹ��״̬,true ��ʾʹ�ã�false ��ʾfree
	void SetBlockUsedState(const void *pvoid,bool bUsed);

	///��ȡ��n�����ʹ��״̬
	///@param	pvoid	�ڴ���ַ
	///@return	true��ʾ�ѱ�ʹ�ã�false��ʾδ��ʹ��
	bool GetBlockUsedState(const void *pvoid);

	///���ݵ�ַȡ���ڴ������б��
	///@param	pvoid	�ڴ���ַ
	///@return	�ڴ������
	int  GetBlockID(const void *pvoid);

	///��ȡ���õĿ��
	///@return	���ñ��
	int GetReuseID();

	///��ȡ����������ָ��
	///@return	����������ָ��
	const int *GetCountPtr(void);
};


#endif
