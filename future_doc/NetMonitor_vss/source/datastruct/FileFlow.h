// FileFlow.h: interface for the CFileFlow class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILEFLOW_H__32B28836_A01C_4923_BBF0_10B313ED400C__INCLUDED_)
#define AFX_FILEFLOW_H__32B28836_A01C_4923_BBF0_10B313ED400C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "platform.h"
#include "Flow.h"

/**CFileFlow���ļ����࣬��ʹ�������ļ�����������һ���ļ��������ƫ������
* ��һ���ļ�����������ݡ�Ϊ������ٶȣ�ÿBLOCK_SIZE��������һ��ƫ������
* �ļ������ļ���������Ŀ¼�ڹ���ʱָ����
*/
class CFileFlow : public CFlow  
{
public:
	/**���캯��
	* @param pszFlowName ���ļ������ƣ��������ļ������������Զ�����"id"��"con"����չ��
	* @param pszPath ���ļ�������Ŀ¼
	* @param bReuse	�Ƿ����ô��ļ�,true�����ļ���falseԭ�ļ��������ڣ���������
	* @�쳣	CRuntimeError	����ļ���Ϊ�ջ��ļ���д�������׳����쳣
	* @remark ��������ļ�������ʱ������ļ��ĺϷ��ԡ�
	*/
	CFileFlow(const char *pszFlowName, const char *pszPath, bool bReuse);
	
	/**���캯��
	* @param nFlowID ���ֱ�ʾ�����ļ������ƣ�nFlowID�ᰴ16����ת�����ַ�����Ϊ�ļ���
	* @param pszFlowPath ���ļ�������Ŀ¼
	* @param bReuse �Ƿ��������ļ�
	* @param nMaxObjects ��������������
	* @param nDataBlockSize CacheListʹ�õ����������С����ҪС��һ�����ݰ��ĳ���
	*/
	CFileFlow(int nFlowID, const char *pszPath, bool bReuse);
	
	virtual ~CFileFlow();

	/**��ȡ�����Ѿ��еİ��ĸ���
	*@return ���ĸ���
	*/
	virtual int GetCount(void);
	
	/**��ȡָ��������ȵ�ָ��
	*@return	ָ��������ȵ�ָ��
	*/
	virtual const int *GetCountPtr(void);

	/**��ȡ����ͨѶ�׶����
	*@return ����ͨѶ�׶����
	*/
	virtual WORD GetCommPhaseNo();

	/**��������ͨѶ�׶����
	*@param nCommPhaseNo Ҫ���õ�����ͨѶ�׶����
	*/
	virtual void SetCommPhaseNo(WORD nCommPhaseNo);

	/**����β���İ��ص�
	*@param nCount �����İ��ĸ���
	*/
	virtual bool Truncate(int nCount); 
	
	/**����������һ������
	*@param	pObject Ҫ���ӵĶ���
	*@param length �������ݵĳ���
	*@return ���������е���ţ�С��0��ʾ����ʧ��
	*/
	virtual int Append(void *pObject, int length);

	/**��ȡָ����ŵĶ���
	*@param	id	�������
	*@param pObject ��ȡ����Ļ�����
	*@param length ��������С
	*@return ȡ������ĳ���
	*/
 	virtual int Get(int id, void *pObject, int length);

protected:	
	/**��ʼ�����������ļ�
	* @return true ��ʼ���ɹ�  false ��ʼ��ʧ��
	*/
	bool InitFile();
	
	/**��ȡ����ȫ�������ܳ���
	*@return ����ȫ�������ܳ���
	*/
	fpos_t GetContentSize(void);

	/**���´����ļ�
	*@param	szIdFilename	�洢��ַ���ļ���
	*@param	szContentFilename	�洢���ݵ��ļ���
	*@param	bReuse	�Ƿ����ô��ļ�
	*@�쳣	CRuntimeError	����ļ���Ϊ�ջ��ļ���д�������׳����쳣
	*/
	void OpenFile(const char *pszFlowName, const char *pszPath, bool bReuse);

	/**�رմ��������ļ�
	*/
	void CloseFile();

	/**��ȡ���Ϊid���������е�ƫ����
	*@param	id	�������
	*@return ���Ϊid���������е�ƫ����
	*/
	fpos_t GetOffset(int id);

	/**
	 * ����һ����
	 * @param pszIdFileName id�ļ���
	 * @param pszConFileName con�ļ���
	 * @return �Ƿ������ɹ�
	 */
	static void Valid(const char * pszIdFileName, const char * pszConFileName);

	/**
	 * �õ����ļ�����
	 * @param file �ļ�ָ��
	 * @param length �ļ�����
	 */
	static void GetLength(FILE* file, QWORD& length);

	/**
	 * �������ļ�����
	 * @param file �ļ�ָ��
	 * @param length �ļ�����
	 */
	static void SetLength(FILE* file, QWORD length);

private:
	FILE *m_fpIdFile;				/**< �洢ƫ�������ļ� */
	FILE *m_fpContentFile;			/**< �洢���ݵ��ļ� */
	vector<fpos_t> m_BlockOffset;		/**< ������ƫ���� */
	int m_nCount;					/**< �Ѿ����ڵİ����� */
	fpos_t m_nContentSize;			/**< �������а������ݳ����ܺ� */
	int m_nReadId;					/**< ���һ�ζ�ȡ�İ������*/
	fpos_t m_nReadOffset;			/**< ���һ�ζ�ȡ�İ����ļ��е�ƫ����*/
	WORD m_nCommPhaseNo;			/**< ͨѶ�׶α��*/

	CRITICAL_VAR m_criticalVar;		/**< �ٽ������� */
	
};

#endif // !defined(AFX_FILEFLOW_H__32B28836_A01C_4923_BBF0_10B313ED400C__INCLUDED_)
