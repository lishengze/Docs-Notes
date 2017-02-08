/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	FileRecordFinder.h
///@brief	利用一个时间字符串定位在文件中的记录位置
///@history
///20080527	武玉波		创建该文件
/////////////////////////////////////////////////////////////////////////
//-------------- 详细的技术说明 --------------------------------//
/*

需求：
在一个时间有序的文件中，定位一个位置，该位置满足这样的条件
对于一个需要查找的时间：
1 如果是准确匹配的，就找到第一条满足 匹配的记录
2 如果没有匹配的记录，就找到第一条大于该 时间的记录
实现方式：
1 采用类似二分查找的方式，每次都进行折半搜索
1.1 首先确定文件的大小 在一定规模下，就直接进行读取 【参考尺寸】
1.2 定位到文件中间，读取一块数据 【快尺寸大小】
该位置不一定是行头，需要进行调整，找到合适的记录；
在记录查找的时候，因为我们已经读取了一块数据，可以同时查找这一块数据开头，结尾的记录； 【头记录『key position』尾记录『key position』】
1.3 如果查找的key小于当前，就搜索文件的前面部分，否则搜索后面部分；

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
	设计的后期修订：
		1 对于采用完全二分法的算法，因为在接近目标的时候，步子变小了，导致读盘次数增加很快
		2 因为一次读取的是一块数据区域，采用 首 尾 同时提取数据的方式，以便能够加快接近的速度，但是从实际效果来看，改进很少，并且程序书写变得复杂了

		这里采用的是： 在二分法进行判断的时候，提供一个参考，如果high-low 小于一个给定的大小，我们就从low开始，进行顺序查找



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
#define LEN_DATATIME_STAMP	16			// 时间戳长度值，形如[Jun 03 13:38:56]
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

		///搜索一个字符串
			///@param keyStr 时间字符串，格式形如[Jun 03 13:38:56]，其中前缀 0 可以不要
			///@return -1 没有找到
		long Search(const char *keyStr);

		///搜索一个时间数
			///把一个形如[Jun 03 13:38:56]的时间串转换为一个整数
			///month|day|hour|minute|second
			///4bits|5bits|5bits|6bits|6bits = 26bits
			///bits: 6|6|6|6|6 = 30bits final design
			///@return 0 说明没有能够正确的解析出时间
			///@return -1 没有找到
		long Search(long key);

		// add by cao.ning
		long SearchNew(long key, bool isSysLog = false);

		/// 移动文件指针到特定位置
		void moveFilePoint(size_t pos);

		///把一个形如[Jun 03 13:38:56]的时间串转换为一个整数
			///month|day|hour|minute|second
			///4bits|5bits|5bits|6bits|6bits = 26bits
			///bits: 6|6|6|6|6 = 30bits final design
			///@return 0 说明没有能够正确的解析出时间
		static long DateStringToLong(const char *str);

		///把一个已转化的长整形的时间还原为一个字串
			///@return 0 说明没有能够正确的解析出时间
		static char *LongToDateString(long lDatetime);

		///初始化文件尺寸和定位文件指针到开始位置
			///@return -1 获取文件尺寸信息失败
		int init(void);

	/* */
	private:
		/// 找到文件中的目标位置
			/// return 返回目标位置，一定可成功返回
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

		///判断一个时间日期串的格式是否合法
			/// @return true 是合法的时间日期 false 不是合法的时间日期
		static bool IsValidDateTime(char *buf);

		///获取一个长整形时间戳的日期信息码，用于比较
			/// @return 长整形时间戳的日期信息码
		long getDateCode(long lDatatime);

		///找到目标区段内出现的首个日期记录
			///@param pos_low	区段左侧文件位移量(IN)
			///@param pos_high	区段右侧文件位移量(IN)
			///@param pos_dest	找到的目标记录位移量(IN,OUT)
			///@param szTime	找到的目标记录时间字串(IN,OUT)
			///@param iTimeLen	找到的目标记录时间字串长度(IN)
			///@param l_Time	需要检索的目标长整形时间(IN)
			///@return bool true:找到了不小于目标时间的记录, false:没有找到
		bool getRecordPos(
				size_t	pos_low,
				size_t	pos_high,
				size_t	&pos_dest,
				char *szTime,
				int iTimeLen,
				long l_Time);

		// add by cao.ning
			// 修正了区段内时间跨年时，错误的将第一条记录认为是目标记录的情况
			///@param pos_low	区段左侧文件位移量(IN)
			///@param pos_high	区段右侧文件位移量(IN)
			///@param pos_dest	找到的目标记录位移量(IN,OUT)
			///@param szTime	找到的目标记录时间字串(IN,OUT)
			///@param iTimeLen	找到的目标记录时间字串长度(IN)
			///@param l_Time	需要检索的目标长整形时间(IN)
			///@return bool true:找到了不小于目标时间的记录, false:没有找到
		bool getRecordPosNew(
			size_t	pos_low,
			size_t	pos_high,
			size_t	&pos_dest,
			char *szTime,
			int iTimeLen,
			long l_Time);

		///找到目标区段内出现的首个日期记录
			///@param pos_low	区段左侧文件位移量(IN)
			///@param pos_high	区段右侧文件位移量(IN)
			///@param pos_dest	找到的目标记录位移量(IN,OUT)
			///@param szTime	找到的目标记录时间字串(IN,OUT)
			///@param iTimeLen	找到的目标记录时间字串长度(IN)
			///@param bHead	当前是否为文件首(IN),true:表示当前位置是文件首
			///@return bool true:找到了, false:没有找到
		bool getRecordPosL(
				size_t	pos_low,
				size_t	pos_high,
				size_t	&pos_dest,
				char *szTime,
				int iTimeLen,
				bool bHead = true);

		///找到目标区段内出现的未个日期记录
			///@param pos_low	区段左侧文件位移量(IN)
			///@param pos_high	区段右侧文件位移量(IN)
			///@param pos_dest	找到的目标记录位移量(IN,OUT)
			///@param szTime	找到的目标记录时间字串(IN,OUT)
			///@param iTimeLen	找到的目标记录时间字串长度(IN)
			///@return bool true:找到了, false:没有找到
		bool getRecordPosR(
				size_t	pos_low,
				size_t	pos_high,
				size_t	&pos_dest,
				char *szTime,
				int iTimeLen);

		///从目标区段左侧读取一段文件内容
			///@param pos_low	区段左侧文件位移量(IN)
			///@param pos_high	区段右侧文件位移量(IN)
			///@param pos_offset	找到的目标记录位移量(IN,OUT)
			///@param szBuf	用于存放文件内容的缓冲区(IN,OUT)
			///@param iBufSize	用于存放文件内容的缓冲区长度(IN)
			///@return int 返回读取的字节数
		int readBufL(
				size_t	pos_low,
				size_t	pos_high,
				size_t	&pos_offset,
				char *szBuf,
				int iBufSize);

		///从目标区段右侧读取一段文件内容
			///@param pos_low	区段左侧文件位移量(IN)
			///@param pos_high	区段右侧文件位移量(IN)
			///@param pos_offset	找到的目标记录位移量(IN)
			///@param szBuf	用于存放文件内容的缓冲区(IN,OUT)
			///@param iBufSize	用于存放文件内容的缓冲区长度(IN)
			///@return int 返回读取的字节数
		int readBufR(
				size_t	pos_low,
				size_t	pos_high,
				size_t	pos_offset,
				char *szBuf,
				int iBufSize);

		///从目标缓冲区中寻找记录时间信息
			///@param szBuf	用于存放文件内容的缓冲区(IN,OUT)
			///@param szTime	找到的目标记录时间字串(IN,OUT)
			///@param iTimeLen	找到的目标记录时间字串长度(IN)
			///@param posType	寻找目标的位置类型(IN) POS_HEAD:找到头部的(如果有) POS_FIRST:找到最前的一个 POS_LAST:找到最后一个
			///@return int 返回目标缓冲区中时间信息的偏移量
		int getCompKey(
				char *szBuf,
				char *szTime,
				int iTimeLen,
				POS_TYPE posType);

	/* */
	public:
		///需要查找的时间串
		long m_lKey;

		///首条记录的时间串
		long m_lFirst;

		///末条记录的时间串
		long m_lLast;

		///需要查找的文件
		FILE *m_fd;

		///文件的尺寸
		size_t	m_size;

		///文件的最后修改时间
		time_t	m_modtime;

		/// 首条记录的偏移量
		size_t	m_posFirst;

		/// 末条记录的偏移量
		size_t	m_posLast;

		///文件名称
		char m_filename[256];	// _MAX_FNAME 256
		
			///月份简写和数值的对应Jan=1 ... Nov=12

		//static map<string,int> m_month;
		//static string a;
};

//-------------  使用范例 ----------------------------//
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
