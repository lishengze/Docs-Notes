//**********************************************************************
//�ļ�����CRuntimeError.h
//��Ҫ����:��������CRuntimeError
//�޸���ʷ��
//**********************************************************************

#ifndef CRUNTIMEERROR_H
#define CRUNTIMEERROR_H

/**CRuntimeError��һ��˵������ʱ�����쳣�Ķ��󣬹�����������Ҽ��ʱ�׳���
*/
class  CRuntimeError
{
public:
	/**���캯�������ڴ������쳣����
	* @param	msg	���쳣�Ĵ�����Ϣ�����಻���ƴ��ַ����ռ�
	* @param	file	����������ļ��������಻���ƴ��ַ����ռ�
	* @param	lineno	����������ļ��к�
	*/
	CRuntimeError(char *pszMsg, char *pszFile, int nLineNo);
	
	/**����������û��ʵ�ʹ���
	*/
	~CRuntimeError();
	
	/**��ȡ������Ϣ
	* @return	������Ϣ
	*/
	char *GetMsg(void);
	
	/**��ȡ����������ļ���
	* @return	�ļ���
	*/
	char *GetFile(void);
	
	/**��ȡ����������ļ��к�
	* @return �ļ��к�
	*/
	int GetLineNo(void);
private:
	
	char *m_pszMsg;	/**< ���ڴ洢������Ϣ */
	
	char *m_pszFile;     /**< ���ڴ洢����������ļ��� */

	int m_nLineNo;     /**< ���ڴ洢����������к� */
};

#endif
