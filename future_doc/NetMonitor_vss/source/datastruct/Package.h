// Package.h: interface for the Package class .
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PACKAGE_H__54CC91F7_BA47_4C55_BD02_05662493565C__INCLUDED_)
#define AFX_PACKAGE_H__54CC91F7_BA47_4C55_BD02_05662493565C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/**CPackageBuffer����CPackage�����������Ĵ�ŵط�������¼
*��CPackage���󣬶����ݻ���ȡ�����ø���
*/
class  CPackageBuffer
{
public:
	/**���캯��
	* @param length���������ݻ������Ĵ�С 
	* @remark ʹ�øù��캯���������������������ɱ��������
	*/
	CPackageBuffer(int length);
	
	/**���캯��
	* @param pData �ѷ���Ļ�������ַ
	* @param length ���������ݻ������Ĵ�С 
	* @remark ʹ�øù��캯���������󲻹�����������������
	*/
	CPackageBuffer(char *pData, int length);

	/**��������
	* �ͷ����ݻ����� 
	*/
	virtual ~CPackageBuffer();
	
	/**���ػ��������׵�ַ
	* @return  �������ĵ�ַ
	*/
	inline char *Data();
	
	/**��������
	* @return  �������ĳ���
	*/
	inline int Length();
	
	/**���Ӷ����������������
	*/
	void AddRef();
	
	/**�ͷ����������
	*/
	void Release();
protected:
	char *m_pData;		/**< ָ�򻺳������ݵ�ָ�� */
	int m_nLength;		/**< ���������� */
	int m_nRefCount;	/**< �����������ø��� */
	bool m_bReleaseData;/**< �Ƿ������������������*/
};

inline char *CPackageBuffer::Data()
{
	return m_pData;
}

inline int CPackageBuffer::Length()
{
	return m_nLength;
}

/**������һ��ͨѶ���ݰ��Ļ���
*/
class  CPackage  
{
public:
	/**���캯��
	*/
	CPackage();
	
	/**������ݰ�
	*/
	void Clear();
	
	/**���ݰ��ϴ�ʱ���ϲ�Э��ı�ţ��������ʵ�ִ˺���
	* @return �ϲ�Э��ı��
	*/
	virtual DWORD GetActiveID();

	/** �����������Ƿ񹹳�һ�������İ������ж�������ݣ���ص���
	* @return >=0 ��һ�������İ� 
	* @return -1 ���ݰ�������
	* @return <-1 ���ݰ��д���
	* @remark ������һ��Ҫ���ظú�����ʵ�����Ѷ����ݵ�У��
	*/
	virtual int ValidPackage();

	/**��װ���ݰ�
	* @return 0 ��װ�ɹ�
	* @return <0 ��װʧ��
	* @remark ������һ��Ҫ���ظú�������ɰ�װ��ͷ�ȹ���
	*/
	virtual int MakePackage();

	/**ָ��PackageBuffer��������ָ��m_pHeadǰ��size����
	* @param size ָ���ƶ��Ĵ�С
	* @return �����ƶ�m_pHead��ĵ�ַ
	*/
	char *Push(int size);
	
	/**ָ��PackageBuffer��������ָ��m_pHead����size����
	* @param size ָ���ƶ��Ĵ�С
	* @return �����ƶ�m_pHead��ĵ�ַ
	*/
	char *Pop(int size);
	
	/**�������д�����ݵĳ���
	* @return ������ݵĳ���
	*/
	inline int Length();
	
	/**�������д�����ݵĵ�ַ
	* @return ������ݵĵ�ַ
	*/
	inline char *Address();
	
	/**����һ�����Ļ�����������������
	* @param pPackage ָ��Դ����ָ��
	*/
	void BufAddRef(CPackage *pPackage);
	
	/**���뱾����Buff������
	* @return ����Buff�ĵ�ַ
	*/
	CPackageBuffer *BufRelease();
	
	/**ʵ��Ϊpackage����ռ�
	* @param nCapacity package�Ŀ��ÿռ��С
	* @param nReserve package�����ռ��С
	*/
	void ConstructAllocate(int nCapacity, int nReserve);
	
	/**�ӹ�����PackagBuffer�Ϸ���һ��ռ�
	* @param length ����ռ�Ĵ�С
	* @return ����ռ���׵�ַ����δ����PackgeBuffer��PackageBuffer�ռ䲻�㣬�򷵻�NULL
	*/
	char *Allocate(int length);

	/**�ӹ�����PackagBuffer�Ϸ������ռ�
	* @return ����ռ���׵�ַ����δ����PackgeBuffer��PackageBuffer�ռ䲻�㣬�򷵻�NULL
	*/
	char * AllocateMax();

	/**������β����ȥһ��
	* @param newLength ������β����ȥ�ĳ���
	*/
	void Truncate(int newLength);
	
	/**���ٶԱ��������ã�������Ϊ0ʱ������������
	*/
	void Release();
	
	/**���ӶԱ���������
	*/
	void AddRef();

	void DupPackageBuffer(CPackage *pSrcPackage);
	
	/**��Դ�������ݿ�����������
	* @param pSrcPackage Դ��
	* @remark ���������Ѿ��������㹻�Ŀռ�
	*/
	void DupPackage(CPackage *pSrcPackage);

	/**��Դ�������ݿ�����������
	* @param pSrcPackage Դ��
	* @remark ���������Ѿ��������㹻�Ŀռ�
	*/
	void AttachBuffer(CPackageBuffer *pPackageBuffer);
	
	/**���ð��е�����
	*@param pData ָ�����ݵ�ָ��
	*@param nDataLen ���ݵĳ���
	*@remark �ú����������PackageBuffer��ֻ��������ͷ��βָ�룬
	*@remark ��ˣ�����ֻ�����ڶ�ȡ����������д������
	*/
	void SetData(char *pData, int nDataLen);
protected:
	/**��������
	*/
	virtual ~CPackage();
protected:
	CPackageBuffer *m_pPackageBuffer;  /**< ָ�����ݻ�������ָ��*/
	char *m_pHead;			   /**< ָ�����ݻ�������ͷָ��*/
	char *m_pTail;			   /**< ָ�����ݻ�������βָ��*/
	int m_nRefCount;		   /**< �Ա��������ø��� */	
	int m_nReserve;				/**< �����ռ��С��������ͷʹ��*/
};

inline int CPackage::Length()
{
	return m_pTail-m_pHead;
}

inline char *CPackage::Address()
{
	return m_pHead;
}

#endif // !defined(AFX_PACKAGE_H__54CC91F7_BA47_4C55_BD02_05662493565C__INCLUDED_)
