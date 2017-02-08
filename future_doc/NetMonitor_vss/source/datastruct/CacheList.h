// CacheList.h: interface for the CCacheList class .
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CACHELIST_H__188D8F8C_ADDC_49EF_81A3_4FA6B1F753F7__INCLUDED_)
#define AFX_CACHELIST_H__188D8F8C_ADDC_49EF_81A3_4FA6B1F753F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCacheNode;

/**������һ�����ݿ����
*/
class  CCacheList  
{
public:
	/**���캯��
	* @param nDataBlockSize ÿ�����ɴ������ݵĳ��ȣ�ȱʡֵΪ20K
	*/
	CCacheList(int nDataBlockSize = 4096);
	
	/**�����캯��
	*/
	virtual ~CCacheList();

	/**ȡ������ͷ�ϵ�һ������
	* @param len ���룺ϣ��ȡ�������ݳ��ȣ������ʵ��ȡ���ĳ��ȣ��������������
	* @return ȡ�������ݡ���δȡ��������Ϊ��
	*/
	void *GetData(int &len);

	/**��������ǰ��������ƶ���
	* @param len �������ݵĳ���
	* @return ʵ�ʶ������ݵĳ���
	*/
	int PopFront(int len);
	
	/**�����β������һ������
	* @param pData �������ݵ�ָ��
	* @param nDataLen �������ݵĳ���
	* @return ���뻺�����ĵ�ַ
	*/
	void *PushBack(void *pData, int nDataLen);
	
	/**�������Ƿ�Ϊ��
	* @return true ������������ false ������������
	*/
	bool IsEmpty();
	
	/**������е�����
	*/
	void Clear();
protected:
	CCacheNode *m_pCacheHead;	/**< ͷ��� */

	CCacheNode *m_pCacheTail;	/**< β��� */
	
	int m_nDataBlockSize;		/**< ÿ�����ɴ������ݵĳ���*/
};

#endif // !defined(AFX_CACHELIST_H__188D8F8C_ADDC_49EF_81A3_4FA6B1F753F7__INCLUDED_)
