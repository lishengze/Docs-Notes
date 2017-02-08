// ServiceName.h: interface for the CServiceName class .
//
///20080727 �Ժ�� NT-0048:���캯��������Ϊconst, ���ͶԴ��������Ҫ��
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SERVICENAME_H__FE5CED63_6EC3_11D7_BB64_444553540000__INCLUDED_)
#define AFX_SERVICENAME_H__FE5CED63_6EC3_11D7_BB64_444553540000__INCLUDED_

/**CServiceName�Ǳ�ʾһ������������ƵĶ���������������URL������������������
*�������Ĳ�����ɣ�channel��ʾ����ͨѶ�����ͣ�host��ʾ������port��ʾ�˿ںţ�
*name��ʾ�ڲ����ļ����߷�����������ͨѶ�����Ǳ����е�ֵ��������ֵ���Ը�������
*ͨѶ��Ҫ����������ĳЩ���֡��������TCP��host��port��������ģ�����name
*��û�����塣
*/
class  CServiceName
{
public:
	/**���캯��������һ���µķ�������
	*@����	location	�������ƣ����ʾ��ʽΪchannel://host:port/name
	*			��򻯷�ʽ����
	*			channel://host/name
	*			channel://host:port
	*			channel://:port/name
	*			channel://host
	*			channel:///name
	*			channel://:port
	*/
	CServiceName(const char *location);
		
	/**��������
	*/
	virtual ~CServiceName();
	
	/**��ȡ����ͨѶ����
	* @return 	����ͨѶ����
	*/
	inline char *GetChannel(void);
	
	/**��ȡ���������ַ
	* @return	���������ַ
	*/
	inline char *GetHost(void);
	
	/**��ȡ�˿ں�
	* @return  �˿ں�
	*/
	inline int GetPort(void);
	
	/**��ȡ�ļ����������
	* @return	�ļ����������
	*/
	inline char *GetName(void);

	/**��ȡ��������
	*/
	inline char *GetLocation(void);
private:
	char *m_pLocation;	/**< ��ŷ������ƵĴ� */

	char *m_pBuffer;	/**< �������õķ�������*/

	char *m_pChannel;	/**< �洢����ͨѶ���� */
	
	char *m_pHost;		/**< �洢���������ַ */
	
	int m_nPort;		/**< ��ȡ�˿ں� */
	
	char *m_pServiceName;   /**< ��ȡ�ļ���������� */
};

inline char *CServiceName::GetChannel(void)
{
	return m_pChannel;
}
	
inline char *CServiceName::GetHost(void)
{
	return m_pHost;
}

inline int CServiceName::GetPort(void)
{
	return m_nPort;
}
	
inline char *CServiceName::GetName(void)
{
	return m_pServiceName;
}

inline char *CServiceName::GetLocation(void)
{
	return m_pLocation;
}


#endif // !defined(AFX_SERVICENAME_H__FE5CED63_6EC3_11D7_BB64_444553540000__INCLUDED_)
