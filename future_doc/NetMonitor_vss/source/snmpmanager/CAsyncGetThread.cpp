/////////////////////////////////////////////////////////////////////////
///@system	������ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CAyncGetThread.cpp
///@brief	ʵ����CAyncGetThreadʹ�õ���
///@history
///20100920	�ܽ���		�������ļ�
#include "CAsyncGetThread.h"

/**�麯�����������һЩʵ��������
* @return true:�����ɹ� false:����ʧ��
*/
bool CAyncGetThread::InitInstance(void)
{
	return true;
}

/**�麯�����������ʵ��
*/
void CAyncGetThread::ExitInstance(void)
{
}

/**�߳̿�ʼ���У����麯�����������̳�ʵ��
*/
void CAyncGetThread::Run(void)
{
	while (1)
	{
		time_t	timep;
		time(&timep);
#ifdef PACKAGE_OUTPUT
		//printf("\t start %s ", ctime(&timep));
		//printf("start m_nThreadNum %d\n", m_nThreadNum);
#endif

		// ѭ����ʼ���ȴ�������е������豸���OID
		//getMonDevice();
		//getMonDeviceNew();
		m_cAsyncIns.startAllHost((int)(timep));
		m_cAsyncIns.run((int)(timep));

		//m_cAsyncIns.genDataField( datas );
#ifdef PACKAGE_OUTPUT
		time(&timep);

		//printf("\t end   %s ", ctime(&timep));
		//printf("end   m_nThreadNum %d\n\n\n", m_nThreadNum);
#endif
		SLEEP(2 * 1000);
	}
}

void CAyncGetThread::GetSpi(void)
{
	return;
}
