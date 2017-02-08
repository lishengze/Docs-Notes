/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CXmlIterator.h
///@brief	������XML���ݰ���
///@history 
///20080810	�ܽ���		�������ļ�

#ifndef REF_CXMLPACKAGE_H
#define REF_CXMLPACKAGE_H

#include "Package.h"

/**���������
*/
class CXmlIterator
{
public:
	/**���캯��
	* @param pHead �������ݵ�ͷָ��
	* @param pEnd �������ݵ�βָ��
	*/
	CXmlIterator(char *pHead, char *pEnd)
	{
		m_pData = NULL;
		m_pCurr = pHead;
		m_pEnd = pEnd;
		
		Next();
	}

	/**������ָ����һ����
	*/
	void Next()
	{
		m_pData = NULL;
		while (m_pData == NULL)
		{
			if(DataRemain() < 1)
			{
				break;
			}
			m_pData = m_pCurr;
			int len = strlen(m_pCurr)+1;
			if (len > (m_pEnd - m_pCurr))
			{
				m_pData = NULL;
				break;
			}
			m_pCurr += len;
		}
	}
	
	/**�Ƿ��и������
	* @return true û�и������\n
	* @return false ���и������
	*/
	inline bool IsEnd()
	{
		return m_pData == NULL;
	}

	int Retrieve(void *pStruct)
	{
		if(m_pData == NULL)
		{
			return 0;
		}
		strcpy((char *)pStruct, m_pData);
		return strlen(m_pData);
	}
	inline int DataRemain()
	{
		return m_pEnd - m_pCurr;
	}
private:
protected:
	char *m_pEnd;
	char *m_pCurr;
	char *m_pData;
};

class CXmlPackage:public CPackage
{
public:
	CXmlPackage()
	{
		version=1;
	}
	virtual ~CXmlPackage()
	{
	}
	/**��ð����ϲ�Э��ID������·��
	* @return ���ذ����ϲ�Э��ID
	*/
	virtual DWORD GetActiveID()
	{
		return 1;
	}
	
	virtual int ValidPackage()
	{
		if(Length()<=0) 
		{
			return -1;
		}
		return Length();
	}
	
	virtual int MakePackage()
	{
		return 0;
	}
	
	inline BYTE GetVersion()
	{
		return version;
	}
	
	inline char * GetXmlValue()
	{
		return m_pHead;
	}

	inline CXmlIterator GetNamedFieldIterator()
	{
		return CXmlIterator(m_pHead, m_pTail);
	}

	void PreparePackage()
	{
		AllocateMax();
		Truncate(0);
	}
	char * AllocField(WORD wSize)
	{
		//�������󣬰������ܳ����������ĳ���
		if (m_pTail+wSize >= 
			m_pPackageBuffer->Data()+m_pPackageBuffer->Length()) 
		{
			return NULL;
		}

		char *pBuf = m_pTail ;
		m_pTail += wSize;
		return pBuf;
	}
	
	int AddField(char *pBuffer, int nBuffLen)
	{
		char *buf=AllocField(nBuffLen);
		if (buf==NULL)
		{
			return -1;
		}
		memcpy(buf, pBuffer, nBuffLen);
		return nBuffLen;
	}

	/**����һ��FTDC����������ռ䡣�ռ��СΪ�����ռ䣫FTDC����ļ�����
	* @param nReserve package�����ռ��С
	* @retrun ��������FTDC��
	*/
	static CXmlPackage *CreatePackage(int nHeaderReserve)
	{
		CXmlPackage *pPackage = new CXmlPackage;
		pPackage->ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, nHeaderReserve);
		return pPackage;
	}

private:
	int version;
};


#endif