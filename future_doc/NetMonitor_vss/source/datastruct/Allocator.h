#ifndef _ALLOCATOR_H_
#define _ALLOCATOR_H_

struct MemoryAllocatorHead;

#define	RESERVE_BLOCK_ID	5				//Ԥ����ͷ

///�ڴ����Ľӿ�
class IMemoryAllocator
{
public:
	virtual ~IMemoryAllocator(void)
	{
	}

	/// ����ƶ���С�Ŀ�����
	///@param size ��ȡָ����С���ڴ�
	///@param reuseID ��ʾָ���Ŀ�� -1��ʾ��ϵͳ����
	///@param isReuse �Ƿ���Ҫ����	
	virtual void* alloc(int size,int &reuseID,bool isReuse = false) = 0;

	///��ʼ������
	virtual void init(bool reuse) = 0;
};

///��ͨ�ڴ������
class CMemoryAllocator:public IMemoryAllocator
{
public:
	/// ����ƶ���С�Ŀ�����
	///@param size ��ȡָ����С���ڴ�
	///@param reuseID ��ʾָ���Ŀ�� -1��ʾ��ϵͳ����
	///@param isReuse �Ƿ���Ҫ����	
	virtual void* alloc(int size,int &reuseID,bool isReuse = false);

	///��ʼ���ڴ�
	///@param reuse �Ƿ�Ϊ����
	virtual void init(bool reuse);	

	bool	isValid();
	
protected:
	CMemoryAllocator();

	char *m_startPosition;				///�ڴ����׵�ַ
	MemoryAllocatorHead* m_pHead;		///������ڴ�ͷ
	char *m_maxEndPosition;

protected:
	///������ʹ�õĿ���
	void	UpdateUseCount(int value);	
	///��ȡ��ʹ�õĿ���
	int		GetUseCount();
	///������һ�����ڴ����׵�ַ
	void	UpdateEmptyAddress(char *Address);
	///��ȡ��һ�����ڴ����׵�ַ
	char*	GetEmptyAddress();
	///���ĳһ���Ƿ��ѱ�ʹ��
	///@param blockID ����
	///@return true �ѱ�ʹ�� falseδ��ʹ��
	bool	IsBlockUsed(int blockID);	
	~CMemoryAllocator();

	void writeLog();
};

///��ͨ�ڴ������
class CNormalMemoryAllocator:public CMemoryAllocator
{
public:
	CNormalMemoryAllocator();
	///��ʼ���ڴ�
	///@param reuse �Ƿ�Ϊ����
	virtual void init(bool reuse);	
};

///�����ڴ������
class CShareMemoryAllocator:public CMemoryAllocator
{
public:
	CShareMemoryAllocator();
	///��ʼ���ڴ�
	///@param reuse �Ƿ�Ϊ����
	virtual void init(bool reuse);	
};

#endif
