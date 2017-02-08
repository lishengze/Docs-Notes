// ***************************************************************
//  CompressUtil   version:  1.0   ��  date: 06/20/2006
//  -------------------------------------------------------------
//  
//  -------------------------------------------------------------
//  Copyright (C) 2006 - All Rights Reserved
// ***************************************************************
// 
// ***************************************************************

#include "public.h"
#include "platform.h"
#include "CompressUtil.h"


CompressUtil::CompressUtil(void)
{
}

CompressUtil::~CompressUtil(void)
{
}

/********************************************************************
	created      :	2006/06/20
	created      :	20:6:2006   16:06
	author       :	Chen.F
	function name: 	Zerocompress
	function para:	inputBuffer [in,const] -- ������
	                inputNumBytes [in] -- �������ĳ���
					outputBuffer [out] -- �������
					outputNumBytes [in,out] -- ����������󳤶�, ����������ĳ���
	
	purpose   :	
	           ������rsp����0�ĸ�����ѹ��rsp��, ���0��������n��, ��0xEn����ʾ�������ֵ�0,(n = 1,...,F)
			   ��0xE0��ת��0xEn(n=0,..,F)
			   ��������Ҫ��outputBufferΪ�����߷���, �ռ�Ĵ�С�ɵ�����������.
    history   : 
	           2006/06/20  V1.0
*********************************************************************/
int CompressUtil::Zerocompress(unsigned char const *inputBuffer,unsigned long inputNumBytes,unsigned char *outputBuffer, unsigned long &outputNumBytes)
{
	assert(NULL != outputBuffer);

	int retValue = 0;

	long iteratorIn;
	long iteratorOut;

	iteratorIn = 0;
	iteratorOut = 0;
	while(iteratorIn < inputNumBytes)
	{
		assert(iteratorOut < outputNumBytes);

		//�����E0,E1,E2,...,EF���ַ�Ҫ����ת��, ǰ���E0
		if((inputBuffer[iteratorIn] > 0xDF) &&(inputBuffer[iteratorIn]<0xF0))
		{
			outputBuffer[iteratorOut++] = 0xE0;
			outputBuffer[iteratorOut++] = inputBuffer[iteratorIn];
			iteratorIn ++;
			continue;
		}

		//�����0, ��ô����Ҫ�ҵ�0�Ĳ���,���15��(F)
		if (0x00 == inputBuffer[iteratorIn])
		{
			long step = iteratorIn+1;
			while((0x00 == inputBuffer[step]) && ((step-iteratorIn)<15)
				&& step < inputNumBytes)
			{
				step ++;
			}

			unsigned char tempChar = (unsigned char)(step - iteratorIn);

			tempChar |= 0xE0;

			outputBuffer[iteratorOut++] = tempChar;

			iteratorIn = step;
			continue;

		}

		//ʣ�µ��ַ���������
		outputBuffer[iteratorOut++] = inputBuffer[iteratorIn++];

	}

	outputNumBytes = iteratorOut;

	return retValue;
}

/********************************************************************
		created      :	2006/06/20
		created      :	20:6:2006   16:06
		author       :	Chen.F
		function name: 	Zerodecompress
		function para:	inputBuffer [in,const] -- ������
						inputNumBytes [in] -- �������ĳ���
						outputBuffer [out] -- �������
						outputNumBytes [in,out] -- ����������󳤶�, ����������ĳ���

		purpose   :	
						������rsp����0�ĸ�����ѹ��rsp��, ���0��������n��, ��0xEn����ʾ�������ֵ�0,(n = 1,...,F)
						��0xE0��ת��0xEn(n=0,..,F)
						��������Ҫ��outputBufferΪ�����߷���, �ռ�Ĵ�С�ɵ�����������.
		history   : 
						2006/06/20  V1.0
*********************************************************************/
int CompressUtil::Zerodecompress(unsigned char const *inputBuffer,unsigned long inputNumBytes,unsigned char *outputBuffer, unsigned long &outputNumBytes)
{
	assert(NULL != outputBuffer);

	//we assume that outputBuffer is big enough
	int retValue = 0;

	long iteratorIn;
	long iteratorOut;

	iteratorIn = 0;
	iteratorOut = 0;
	while(iteratorIn < inputNumBytes)
	{
		//���ﴦ����Ⱥ�˳�����Ҫ
		//���ȿ��ǲ���0xE0,�����E0, ��ô�����ת���ַ�
		assert(iteratorOut < outputNumBytes);

		if (inputBuffer[iteratorIn] == 0xE0)
		{
			outputBuffer[iteratorOut++] = inputBuffer[iteratorIn+1];
			iteratorIn += 2;
			continue;
		}

		//�������û��0xE0��ͷ��E1,...,EF, ��ô����0�ĸ���
		if ((inputBuffer[iteratorIn] > 0xE0) &&(inputBuffer[iteratorIn]<0xF0))
		{
			int tempChar = (int)(inputBuffer[iteratorIn] & 0x0F);
			for(int i=0;i<tempChar;i++)
			{
				outputBuffer[iteratorOut++] = 0x00;
			}
			iteratorIn ++;
			continue;
		}

		//�����ַ���������
		outputBuffer[iteratorOut++] = inputBuffer[iteratorIn++];


	}

	outputNumBytes = iteratorOut;

	return retValue;
}
