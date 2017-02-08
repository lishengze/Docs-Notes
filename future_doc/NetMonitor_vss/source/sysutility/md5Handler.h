/////////////////////////////////////////////////////////////////////////
///@system 底层支持
///@company 上海期货信息技术有限公司
///@file md5Handler.h
///@brief	定义了md5算法的接口
///@history
///20080425	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////
#ifndef MD5_H
#define MD5_H

#include "platform.h"

///md5摘要值得长度
#define MD5_DIGEST_LEN	16

/* Type define */
typedef unsigned char byte;
typedef unsigned int uint32;

/////////////////////////////////////////////////////////////////////////
///CMD5Handler是一个进行MD5算法计算的处理器
///@author	王肇东
///@version	1.0,20080425
/////////////////////////////////////////////////////////////////////////
class CMD5Handler
{
	/* */
	public:
		///构造方法，没有设置初始值
		CMD5Handler(void);

		///构造方法，有设置初始值
			///@param	input	输入的字符串
			///@param	length	字符串的长度，如果为-1表示字符串以'\0'结尾
		CMD5Handler(const char *input, int length = -1);

		///加入一个字符串
			///@param	input	输入的字符串
			///@param	length	字符串的长度，如果为-1表示字符串以'\0'结尾
		void update(const char *input, int length = -1);

		///获取摘要值
			///@return	得到的摘要值，长度一定为MD5_DIGEST_LEN(16)个字节
		const char	*digest(void);

		///清空值
		void reset(void);

	/* */
	private:
		///完成最终步骤，产生摘要值
		void final(void);

		///MD5算法使用的内部方法
		void transform(const char block[64]);
		void encode(const uint32 *input, byte *output, size_t length);
		void decode(const byte *input, uint32 *output, size_t length);

		///禁止复制而定义的方法
			///@param	v	要复制的源
		CMD5Handler(const CMD5Handler &v)
		{
		}

		///禁止等于而定义的方法
			///@param	v	要复制的源
		CMD5Handler &operator=(const CMD5Handler &v)
		{
		}

	/* */
	private:
		uint32	_state[4];	/* state (ABCD) */
		uint32	_count[2];	/* number of bits, modulo 2^64 (low-order word first) */
		char _buffer[64];	/* input buffer */
		char _digest[16];	/* message digest */
		bool _finished;		/* calculate finished ? */
};

inline int GenMD5(char *pBuffer, int length, char *pDigest)
{
	unsigned char digest[MD5_DIGEST_LEN + 1];

	memset(digest, 0, MD5_DIGEST_LEN + 1);

	CMD5Handler theMD5;
	theMD5.update(pBuffer, length);
	memcpy(digest, theMD5.digest(), MD5_DIGEST_LEN);

	for (int i = 0; i < MD5_DIGEST_LEN; i++)
	{
		sprintf((char *)(pDigest + 2 * i), "%02x", digest[i]);
	}

	return 0;
}

///校验MD5检查函数
///@param	srcFileName	源文件全路径名称
///@param	md5FileName	保存校验码的文件全路径名称
inline int GenMD5File(const char *srcFileName, const char *md5FileName)
{
	FILE *fp;
	FILE *md5fp;
	struct stat st;
	char *buffer;
	int length;
	char oldDigest[MD5_DIGEST_LEN * 2 + 1];
	char nowDigest[MD5_DIGEST_LEN * 2 + 1];

	memset(oldDigest, 0, MD5_DIGEST_LEN * 2 + 1);
	memset(nowDigest, 0, MD5_DIGEST_LEN * 2 + 1);

	if (stat(srcFileName, &st) == -1)
	{
		return -1;
	}

	if ((fp = fopen(srcFileName, "r")) == NULL)
	{
		return -1;
	}

	buffer = (char *)new char[st.st_size];
	if ((length = fread(buffer, 1, st.st_size, fp)) <= 0)
	{
		delete buffer;
		fclose(fp);
		return -1;
	}
	else
	{
		GenMD5(buffer, length, nowDigest);
		delete buffer;
		fclose(fp);

		if ((md5fp = fopen(md5FileName, "r")) == NULL)
		{
			return -1;
		}

		if (MD5_DIGEST_LEN * 2 != fread(
				oldDigest,
			1,
			MD5_DIGEST_LEN * 2,
			md5fp))
		{
			fclose(md5fp);
			return -2;
		}

		if (strncmp((char *)nowDigest, (char *)oldDigest, MD5_DIGEST_LEN * 2))
		{
			fclose(md5fp);
			return -2;
		}

		fclose(md5fp);
		return 0;
	}
}

#endif
