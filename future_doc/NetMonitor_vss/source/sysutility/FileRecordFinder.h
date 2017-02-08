/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	FileRecordFinder.h
///@brief	����һ��ʱ���ַ�����λ���ļ��еļ�¼λ��
///@history
///20080527	����		�������ļ�
/////////////////////////////////////////////////////////////////////////
//-------------- ��ϸ�ļ���˵�� --------------------------------//
/*

����
��һ��ʱ��������ļ��У���λһ��λ�ã���λ����������������
����һ����Ҫ���ҵ�ʱ�䣺
1 �����׼ȷƥ��ģ����ҵ���һ������ ƥ��ļ�¼
2 ���û��ƥ��ļ�¼�����ҵ���һ�����ڸ� ʱ��ļ�¼
ʵ�ַ�ʽ��
1 �������ƶ��ֲ��ҵķ�ʽ��ÿ�ζ������۰�����
1.1 ����ȷ���ļ��Ĵ�С ��һ����ģ�£���ֱ�ӽ��ж�ȡ ���ο��ߴ硿
1.2 ��λ���ļ��м䣬��ȡһ������ ����ߴ��С��
��λ�ò�һ������ͷ����Ҫ���е������ҵ����ʵļ�¼��
�ڼ�¼���ҵ�ʱ����Ϊ�����Ѿ���ȡ��һ�����ݣ�����ͬʱ������һ�����ݿ�ͷ����β�ļ�¼�� ��ͷ��¼��key position��β��¼��key position����
1.3 ������ҵ�keyС�ڵ�ǰ���������ļ���ǰ�沿�֣������������沿�֣�

===========================================================================
Binary Search Algorithm

http://en.wikipedia.org/wiki/Binary_search
Recursive:
BinarySearch(A[0..N-1], value, low, high) {
if (high < low)
return -1 // not found
mid = (low + high) / 2
if (A[mid] > value)
return BinarySearch(A, value, low, mid-1)
else if (A[mid] < value)
return BinarySearch(A, value, mid+1, high)
else
return mid // found
}

Iterative:
BinarySearch(A[0..N-1], value) {
low = 0
high = N - 1
while (low <= high) {
mid = (low + high) / 2
if (A[mid] > value)
high = mid - 1
else if (A[mid] < value)
low = mid + 1
else
return mid // found
}
return -1 // not found
}

Other:
low = 0
high = N
while (low < high) {
mid = (low + high)/2;
if (A[mid] < value)
low = mid + 1; 
else
//can't be high = mid-1: here A[mid] >= value,
//so high can't be < mid if A[mid] == value
high = mid; 
}
// high == low, using high or low depends on taste 
if ((low < N) && (A[low] == value))
return low // found
else
return -1 // not found        

This algorithm has two other advantages. 
At the end of the loop, low points to the first entry greater than or equal to value, 
so a new entry can be inserted if no match is found. Moreover, 
it only requires one comparison; which could be significant for complex keys in languages which do not allow the result of a comparison to be saved.

In practice, one frequently uses a three-way comparison instead of two comparisons per loop. 
Also, real implementations using fixed-width integers with modular arithmetic need to account for the possibility of overflow. 
One frequently-used technique for this is to compute mid, so that two smaller numbers are ultimately added:
===========================================================================

*/
/*
Sample File:
Jun 03 13:36:32 kf4640 qkernel 1[18449]: event Config 5 tresult SubjectID=[1001] Item=[0] Type=[tresult] Address=[udp://172.16.30.255:26003]
Jun 03 13:36:32 kf4640 qkernel 1[18449]: TotalVolume 0
Jun 03 13:36:32 kf4640 qkernel 1[18449]: TotalAmount 0.000000
Jun 03 13:36:32 kf4640 qkernel 1[18449]: XTPPub 
Jun 03 13:36:32 kf4640 qkernel 1[18449]: IsActive 1
Jun 03 13:36:32 kf4640 qkernel 1[18449]: Version 20080515.23:27:22
Jun 03 13:36:32 kf4640 qkernel 1[18449]: tseriesLen 39
Jun 03 13:36:32 kf4640 qkernel 1[18449]: tresultLen 0
Jun 03 13:36:32 kf4640 qkernel 1[18449]: MemoryDatabase 103
Jun 03 13:36:32 kf4640 qkernel 1[18449]: MemoryDatabaseUsage 34.33%
Jun 03 13:36:32 kf4640 qkernel 1[18449]: MDBBlock 1014
Jun 03 13:36:32 kf4640 qkernel 1[18449]: MDBBlockUsage 5.07%
Jun 03 13:36:32 kf4640 qkernel 1[18449]: OrderSize 0
Jun 03 13:36:32 kf4640 qkernel 1[18449]: TradeSize 0
Jun 03 13:36:32 kf4640 qkernel 1[18449]: ClientSize 0
Jun 03 13:36:32 kf4640 qkernel 1[18449]: PartClientSize 0
Jun 03 13:36:32 kf4640 qkernel 1[18449]: ClientPositionSize 0
Jun 03 13:36:32 kf4640 qkernel 1[18449]: UserSessionSize 0
Jun 03 13:36:32 kf4640 qkernel 1[18449]: HandleInput 0
Jun 03 13:36:32 kf4640 qkernel 1[18449]: HandleInputTotal 0
*/
/*
	��Ƶĺ����޶���
		1 ���ڲ�����ȫ���ַ����㷨����Ϊ�ڽӽ�Ŀ���ʱ�򣬲��ӱ�С�ˣ����¶��̴������Ӻܿ�
		2 ��Ϊһ�ζ�ȡ����һ���������򣬲��� �� β ͬʱ��ȡ���ݵķ�ʽ���Ա��ܹ��ӿ�ӽ����ٶȣ����Ǵ�ʵ��Ч���������Ľ����٣����ҳ�����д��ø�����

		������õ��ǣ� �ڶ��ַ������жϵ�ʱ���ṩһ���ο������high-low С��һ�������Ĵ�С�����Ǿʹ�low��ʼ������˳�����



*/
#ifndef _FILE_RECORD_FINDER_H_
#define _FILE_RECORD_FINDER_H_

#pragma warning(disable : 4267 4996)
#pragma warning(disable : 4786)
#include <stdio.h>
#include <stdlib.h>

//#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>
#include <errno.h>
#include <utility>
#include <map>

using std:: map;
using std:: string;
using std:: pair;
using std:: make_pair;

#include "platform.h"

#define MASK_MON			0x3F000000	//0b00111111000000000000000000000000
#define MASK_DAY			0x00FC0000	//0b00000000111111000000000000000000
#define MASK_HOUR			0x0003F000	//0b00000000000000111111000000000000
#define MASK_MIN			0x00000FC0	//0b00000000000000000000111111000000
#define MASK_SEC			0x0000003F	//0b00000000000000000000000000111111
#define LEN_DATATIME_STAMP	16			// ʱ�������ֵ������[Jun 03 13:38:56]
enum POS_TYPE
{
	POS_HEAD	= 0,
	POS_FIRST,
	POS_LAST,
};

class CFileRecordFinder
{
	/* */
	public:
		/// Constructor && DeConstructor
		CFileRecordFinder(const char *filename);
		CFileRecordFinder(FILE *file);
		~ CFileRecordFinder(void);

		///����һ���ַ���
			///@param keyStr ʱ���ַ�������ʽ����[Jun 03 13:38:56]������ǰ׺ 0 ���Բ�Ҫ
			///@return -1 û���ҵ�
		long Search(const char *keyStr);

		///����һ��ʱ����
			///��һ������[Jun 03 13:38:56]��ʱ�䴮ת��Ϊһ������
			///month|day|hour|minute|second
			///4bits|5bits|5bits|6bits|6bits = 26bits
			///bits: 6|6|6|6|6 = 30bits final design
			///@return 0 ˵��û���ܹ���ȷ�Ľ�����ʱ��
			///@return -1 û���ҵ�
		long Search(long key);

		// add by cao.ning
		long SearchNew(long key, bool isSysLog = false);

		/// �ƶ��ļ�ָ�뵽�ض�λ��
		void moveFilePoint(size_t pos);

		///��һ������[Jun 03 13:38:56]��ʱ�䴮ת��Ϊһ������
			///month|day|hour|minute|second
			///4bits|5bits|5bits|6bits|6bits = 26bits
			///bits: 6|6|6|6|6 = 30bits final design
			///@return 0 ˵��û���ܹ���ȷ�Ľ�����ʱ��
		static long DateStringToLong(const char *str);

		///��һ����ת���ĳ����ε�ʱ�仹ԭΪһ���ִ�
			///@return 0 ˵��û���ܹ���ȷ�Ľ�����ʱ��
		static char *LongToDateString(long lDatetime);

		///��ʼ���ļ��ߴ�Ͷ�λ�ļ�ָ�뵽��ʼλ��
			///@return -1 ��ȡ�ļ��ߴ���Ϣʧ��
		int init(void);

	/* */
	private:
		/// �ҵ��ļ��е�Ŀ��λ��
			/// return ����Ŀ��λ�ã�һ���ɳɹ�����
		size_t	find(
					long l_key,
					size_t	blockSize,
					size_t	pos_low,
					size_t	pos_high,
					long l_low,
					long l_high);

		///@return -1 not found
		long find(long key, size_t blockSize);

		///@return -1 not found
		long findNew(long key, size_t blockSize, bool isSysLog = false);

		///�ж�һ��ʱ�����ڴ��ĸ�ʽ�Ƿ�Ϸ�
			/// @return true �ǺϷ���ʱ������ false ���ǺϷ���ʱ������
		static bool IsValidDateTime(char *buf);

		///��ȡһ��������ʱ�����������Ϣ�룬���ڱȽ�
			/// @return ������ʱ�����������Ϣ��
		long getDateCode(long lDatatime);

		///�ҵ�Ŀ�������ڳ��ֵ��׸����ڼ�¼
			///@param pos_low	��������ļ�λ����(IN)
			///@param pos_high	�����Ҳ��ļ�λ����(IN)
			///@param pos_dest	�ҵ���Ŀ���¼λ����(IN,OUT)
			///@param szTime	�ҵ���Ŀ���¼ʱ���ִ�(IN,OUT)
			///@param iTimeLen	�ҵ���Ŀ���¼ʱ���ִ�����(IN)
			///@param l_Time	��Ҫ������Ŀ�곤����ʱ��(IN)
			///@return bool true:�ҵ��˲�С��Ŀ��ʱ��ļ�¼, false:û���ҵ�
		bool getRecordPos(
				size_t	pos_low,
				size_t	pos_high,
				size_t	&pos_dest,
				char *szTime,
				int iTimeLen,
				long l_Time);

		// add by cao.ning
			// ������������ʱ�����ʱ������Ľ���һ����¼��Ϊ��Ŀ���¼�����
			///@param pos_low	��������ļ�λ����(IN)
			///@param pos_high	�����Ҳ��ļ�λ����(IN)
			///@param pos_dest	�ҵ���Ŀ���¼λ����(IN,OUT)
			///@param szTime	�ҵ���Ŀ���¼ʱ���ִ�(IN,OUT)
			///@param iTimeLen	�ҵ���Ŀ���¼ʱ���ִ�����(IN)
			///@param l_Time	��Ҫ������Ŀ�곤����ʱ��(IN)
			///@return bool true:�ҵ��˲�С��Ŀ��ʱ��ļ�¼, false:û���ҵ�
		bool getRecordPosNew(
			size_t	pos_low,
			size_t	pos_high,
			size_t	&pos_dest,
			char *szTime,
			int iTimeLen,
			long l_Time);

		///�ҵ�Ŀ�������ڳ��ֵ��׸����ڼ�¼
			///@param pos_low	��������ļ�λ����(IN)
			///@param pos_high	�����Ҳ��ļ�λ����(IN)
			///@param pos_dest	�ҵ���Ŀ���¼λ����(IN,OUT)
			///@param szTime	�ҵ���Ŀ���¼ʱ���ִ�(IN,OUT)
			///@param iTimeLen	�ҵ���Ŀ���¼ʱ���ִ�����(IN)
			///@param bHead	��ǰ�Ƿ�Ϊ�ļ���(IN),true:��ʾ��ǰλ�����ļ���
			///@return bool true:�ҵ���, false:û���ҵ�
		bool getRecordPosL(
				size_t	pos_low,
				size_t	pos_high,
				size_t	&pos_dest,
				char *szTime,
				int iTimeLen,
				bool bHead = true);

		///�ҵ�Ŀ�������ڳ��ֵ�δ�����ڼ�¼
			///@param pos_low	��������ļ�λ����(IN)
			///@param pos_high	�����Ҳ��ļ�λ����(IN)
			///@param pos_dest	�ҵ���Ŀ���¼λ����(IN,OUT)
			///@param szTime	�ҵ���Ŀ���¼ʱ���ִ�(IN,OUT)
			///@param iTimeLen	�ҵ���Ŀ���¼ʱ���ִ�����(IN)
			///@return bool true:�ҵ���, false:û���ҵ�
		bool getRecordPosR(
				size_t	pos_low,
				size_t	pos_high,
				size_t	&pos_dest,
				char *szTime,
				int iTimeLen);

		///��Ŀ����������ȡһ���ļ�����
			///@param pos_low	��������ļ�λ����(IN)
			///@param pos_high	�����Ҳ��ļ�λ����(IN)
			///@param pos_offset	�ҵ���Ŀ���¼λ����(IN,OUT)
			///@param szBuf	���ڴ���ļ����ݵĻ�����(IN,OUT)
			///@param iBufSize	���ڴ���ļ����ݵĻ���������(IN)
			///@return int ���ض�ȡ���ֽ���
		int readBufL(
				size_t	pos_low,
				size_t	pos_high,
				size_t	&pos_offset,
				char *szBuf,
				int iBufSize);

		///��Ŀ�������Ҳ��ȡһ���ļ�����
			///@param pos_low	��������ļ�λ����(IN)
			///@param pos_high	�����Ҳ��ļ�λ����(IN)
			///@param pos_offset	�ҵ���Ŀ���¼λ����(IN)
			///@param szBuf	���ڴ���ļ����ݵĻ�����(IN,OUT)
			///@param iBufSize	���ڴ���ļ����ݵĻ���������(IN)
			///@return int ���ض�ȡ���ֽ���
		int readBufR(
				size_t	pos_low,
				size_t	pos_high,
				size_t	pos_offset,
				char *szBuf,
				int iBufSize);

		///��Ŀ�껺������Ѱ�Ҽ�¼ʱ����Ϣ
			///@param szBuf	���ڴ���ļ����ݵĻ�����(IN,OUT)
			///@param szTime	�ҵ���Ŀ���¼ʱ���ִ�(IN,OUT)
			///@param iTimeLen	�ҵ���Ŀ���¼ʱ���ִ�����(IN)
			///@param posType	Ѱ��Ŀ���λ������(IN) POS_HEAD:�ҵ�ͷ����(�����) POS_FIRST:�ҵ���ǰ��һ�� POS_LAST:�ҵ����һ��
			///@return int ����Ŀ�껺������ʱ����Ϣ��ƫ����
		int getCompKey(
				char *szBuf,
				char *szTime,
				int iTimeLen,
				POS_TYPE posType);

	/* */
	public:
		///��Ҫ���ҵ�ʱ�䴮
		long m_lKey;

		///������¼��ʱ�䴮
		long m_lFirst;

		///ĩ����¼��ʱ�䴮
		long m_lLast;

		///��Ҫ���ҵ��ļ�
		FILE *m_fd;

		///�ļ��ĳߴ�
		size_t	m_size;

		///�ļ�������޸�ʱ��
		time_t	m_modtime;

		/// ������¼��ƫ����
		size_t	m_posFirst;

		/// ĩ����¼��ƫ����
		size_t	m_posLast;

		///�ļ�����
		char m_filename[256];	// _MAX_FNAME 256
		
			///�·ݼ�д����ֵ�Ķ�ӦJan=1 ... Nov=12

		//static map<string,int> m_month;
		//static string a;
};

//-------------  ʹ�÷��� ----------------------------//
/*
char *key="Jun 03 13:38:56";
FILE *fp = NULL;
fp = fopen("Keyfile.log","r+");
//CFileRecordFinder finder("Keyfile.log",key);
CFileRecordFinder finder(fp,key);

printf("key length=%d\n",strlen(key));

int pos = finder.Search(key);
printf("result=%d\n",pos);
if ( pos > -1 ) {
		char buf[2048];
		finder.moveFilePoint(pos);
		int p = fread(buf,1,200,finder.m_fd);
		buf[p]=0; 
		printf("%s",buf);

}
*/
#endif //_FILE_RECORD_FINDER_H_
