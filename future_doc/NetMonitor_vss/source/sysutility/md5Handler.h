/////////////////////////////////////////////////////////////////////////
///@system �ײ�֧��
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file md5Handler.h
///@brief	������md5�㷨�Ľӿ�
///@history
///20080425	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////
#ifndef MD5_H
#define MD5_H

#include "platform.h"

///md5ժҪֵ�ó���
#define MD5_DIGEST_LEN	16

/* Type define */
typedef unsigned char byte;
typedef unsigned int uint32;

/////////////////////////////////////////////////////////////////////////
///CMD5Handler��һ������MD5�㷨����Ĵ�����
///@author	���ض�
///@version	1.0,20080425
/////////////////////////////////////////////////////////////////////////
class CMD5Handler
{
	/* */
	public:
		///���췽����û�����ó�ʼֵ
		CMD5Handler(void);

		///���췽���������ó�ʼֵ
			///@param	input	������ַ���
			///@param	length	�ַ����ĳ��ȣ����Ϊ-1��ʾ�ַ�����'\0'��β
		CMD5Handler(const char *input, int length = -1);

		///����һ���ַ���
			///@param	input	������ַ���
			///@param	length	�ַ����ĳ��ȣ����Ϊ-1��ʾ�ַ�����'\0'��β
		void update(const char *input, int length = -1);

		///��ȡժҪֵ
			///@return	�õ���ժҪֵ������һ��ΪMD5_DIGEST_LEN(16)���ֽ�
		const char	*digest(void);

		///���ֵ
		void reset(void);

	/* */
	private:
		///������ղ��裬����ժҪֵ
		void final(void);

		///MD5�㷨ʹ�õ��ڲ�����
		void transform(const char block[64]);
		void encode(const uint32 *input, byte *output, size_t length);
		void decode(const byte *input, uint32 *output, size_t length);

		///��ֹ���ƶ�����ķ���
			///@param	v	Ҫ���Ƶ�Դ
		CMD5Handler(const CMD5Handler &v)
		{
		}

		///��ֹ���ڶ�����ķ���
			///@param	v	Ҫ���Ƶ�Դ
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

///У��MD5��麯��
///@param	srcFileName	Դ�ļ�ȫ·������
///@param	md5FileName	����У������ļ�ȫ·������
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
