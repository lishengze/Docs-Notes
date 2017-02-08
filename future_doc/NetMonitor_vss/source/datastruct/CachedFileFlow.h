// CachedFileFlow.h: interface for the CCachedFileFlow class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CACHEDFILEFLOW_H__1A86ED0A_F5FE_4A27_A7AC_BCF24B77DCFA__INCLUDED_)
#define AFX_CACHEDFILEFLOW_H__1A86ED0A_F5FE_4A27_A7AC_BCF24B77DCFA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CachedFlow.h"

/**CCachedFileFlow�Ǵ�������ļ�������������CCahcedFlow��ͬʱ�ҽ���һ��CFileFlow
*/
class CCachedFileFlow : public CCachedFlow  
{
public:
	/**���캯��
	* @param pszFlowName ���ļ������ƣ��������ļ������������Զ�����"id"��"con"����չ��
	* @param pszFlowPath ���ļ�������Ŀ¼
	* @param bReuse �Ƿ��������ļ�
	* @param nMaxObjects ��������������
	* @param nDataBlockSize CacheListʹ�õ����������С����ҪС��һ�����ݰ��ĳ���
	*/
	CCachedFileFlow(const char *pszFlowName, const char *pszFlowPath, bool bReuse, int nMaxObjects, int nDataBlockSize);

	/**���캯��
	* @param nFlowID ���ֱ�ʾ�����ļ������ƣ�nFlowID�ᰴ16����ת�����ַ�����Ϊ�ļ���
	* @param pszFlowPath ���ļ�������Ŀ¼
	* @param bReuse �Ƿ��������ļ�
	* @param nMaxObjects ��������������
	* @param nDataBlockSize CacheListʹ�õ����������С����ҪС��һ�����ݰ��ĳ���
	*/
	CCachedFileFlow(int nFlowID, const char *pszFlowPath, bool bReuse, int nMaxObjects, int nDataBlockSize);

	/**��������
	*/
	virtual ~CCachedFileFlow();

	/**�ҽ���һ����
	* @param pFlow ��Ҫ�ҽӵ���
	* @return ԭ�ҽӵ���
	* @remark �����Ѿ��ҽӺ����ļ��������ñ������ᵼ���׳��쳣
	*/
	virtual int AttachUnderFlow(CFlow *pFlow);

};

#endif // !defined(AFX_CACHEDFILEFLOW_H__1A86ED0A_F5FE_4A27_A7AC_BCF24B77DCFA__INCLUDED_)
