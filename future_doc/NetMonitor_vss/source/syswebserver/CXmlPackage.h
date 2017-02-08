/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CXmlIterator.h
///@brief	定义了XML数据包类
///@history 
///20080810	周建军		创建该文件

#ifndef REF_CXMLPACKAGE_H
#define REF_CXMLPACKAGE_H

#include "Package.h"

/**域迭代器类
*/
class CXmlIterator
{
public:
	/**构造函数
	* @param pHead 包内数据的头指针
	* @param pEnd 包内数据的尾指针
	*/
	CXmlIterator(char *pHead, char *pEnd)
	{
		m_pData = NULL;
		m_pCurr = pHead;
		m_pEnd = pEnd;
		
		Next();
	}

	/**迭代器指到下一个域
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
	
	/**是否还有更多的域
	* @return true 没有更多的域\n
	* @return false 还有更多的域
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
	/**获得包的上层协议ID，用来路由
	* @return 返回包的上层协议ID
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
		//新域加入后，包长不能超过缓冲区的长度
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

	/**创建一个FTDC包，并分配空间。空间大小为保留空间＋FTDC最大报文件长度
	* @param nReserve package保留空间大小
	* @retrun 创建出的FTDC包
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