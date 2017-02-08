/////////////////////////////////////////////////////////////////////////
///@system ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file ThreadPool.h
///@brief �����̳߳أ�Ϊ���������ṩ����
///@history
///20110701	��־ΰ   �������ļ�
/////////////////////////////////////////////////////////////////////////
#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H

#include "PrjCommon.h"
#include <Mutex.h>
#include <vector>

class PooledThread;

/// �̳߳��е��߳�ÿ���첽���еĶ���
class Runnable
{
	/* */
	public:
		Runnable(void)
		{
		}

		virtual~Runnable(void)
		{
		}

		/// ������Ҫͨ���̳߳��е��߳����еĶ��󣬾�Ҫ���ش˷�����ʵ�־���Ĳ���
		virtual void Run(void) = 0;
};

class ThreadPool
{
	/* */
	public:
		/**�̳߳صĹ��캯��
	* @param minCapacity �̳߳��ڿ�ͬʱ���е��̵߳���С������Ĭ��Ϊ2
	* @param maxCapacity  �̳߳��ڿ����е��̵߳����������Ĭ��Ϊ8
	* @param idleTime  �̳߳��ڵ��̴߳���idle״̬���ʱ�䣬��λΪ�롣������ʱ�䣬�̱߳���ֹ�����ա�
	*/
		ThreadPool(int minCapacity = 2, int maxCapacity = 8);

		~ ThreadPool(void);

		/**ͨ���̳߳�����Runnable�����ϵ�Run������
    * �÷�������һ���������߳������С����̳߳��п����е��̴߳ﵽ����ʱ��
    * ���׳��̳߳������쳣��
	* @param func �첽ִ�еĺ�����һ���������޷���ֵ��
	*/
		void Run(Runnable &callback);

		/**ͨ���̳߳�����Runnable�����ϵ�Run������
    * �÷�������һ���������߳������С����̳߳��п����е��̴߳ﵽ����ʱ��
    * ��ȴ�ֱ���п����߳�ִ��Runnable���󷽷�Ϊֹ��
	* @param func �첽ִ�еĺ�����һ���������޷���ֵ��
	*/
		void RunWithoutThrow(Runnable &callback);

		/**��ֹ�̳߳��������̣߳�Ȼ�����������߳���Դ��
    * �̳߳������������е��̣߳���ȴ��߳���ɵ�ǰ������Ȼ������ֹ�̡߳�
	*/
		void StopAndCleanAll(void);

	/* */
	private:
		PooledThread *getAvailThread(void);

		PooledThread *createAndStartThread(void);

		DISALLOW_COPY_AND_ASSIGN(ThreadPool);

		typedef std::vector<PooledThread *> ThreadContainer;

		/// �̳߳����̵߳�����
		ThreadContainer m_threadSet;

		/// �̳߳����ṩ������ʵ���
		CMutex m_mutex;

		/// �̳߳������ٵ��߳�����
		int m_minCapacity;

		/// �̳߳��������߳�����
		int m_maxCapacity;
};
#endif // _THREAD_POOL_H
