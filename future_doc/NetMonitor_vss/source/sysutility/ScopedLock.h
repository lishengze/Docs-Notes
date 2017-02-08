/////////////////////////////////////////////////////////////////////////
///@system ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file ScopedLock.h
///@brief ������mutex��RAII��
///@history
///20110701	��־ΰ   �������ļ�
/////////////////////////////////////////////////////////////////////////
#ifndef _SCOPED_LOCK_H
#define _SCOPED_LOCK_H

#include "PrjCommon.h"

template<typename T>
class ScopeLock
{
	/* */
	public:

		/// ���캯��
		    ///@param lock ����Դ���Զ�������Դ������
		ScopeLock(T &lock) :
		m_lock(lock)
		{
			m_lock.Lock();
		}

		/// �����������Զ�������Դ����
		~ScopeLock(void)
		{
			m_lock.UnLock();
		}

	/* */
	private:
		DISALLOW_COPY_AND_ASSIGN(ScopeLock);

		/// ����Դ
		T &m_lock;
};
#endif //_SCOPED_LOCK_H
