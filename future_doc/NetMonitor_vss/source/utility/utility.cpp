/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file utility.h
///@briefʵ������ϵͳ�����Եĺ���
///@history 
///20020214	 ���ض�		�������ļ�
///20020330  ���ض�		����DEBUG�õ�һЩ����
///20020409  ���ض�		�޸�trim , ���⵽�˵�һ���ַ����ǿո��޷�trim�������
///20120726  ����       ���ڲ���ȫ���������˶�Ӧ��ȫ�汾�ķ�װ��localtime
/////////////////////////////////////////////////////////////////////////

#include "platform.h"
#include "utility.h"

//static FILE *fpDebugOutput=NULL; ///����DEBUG�����֮��,��ΪNULL,����Ϊ��stdout

char *trim(char *s)
{
	char *p=s+strlen(s)-1;
	while (p>s)
	{
		if (*p==' ')
		{
			*p='\0';
			p--;
		}
		else
			break;
	}
	if (*p==' ') *p='\0'; ///gyd 20020409 ���⵽�˵�һ���ַ����ǿո��޷�trim�������
	return s;
}

int getTimeZoneOffset(void)
{
	time_t timesec;
	struct tm tm_time;
	time(&timesec);
	GMTime(&timesec, &tm_time);
	return mktime(&tm_time) - timesec;	
}

char *getLongTime(void)
{
	time_t ltime;
	struct tm now;
	static char timeBuffer[21];
	
	time(&ltime);
	LocalTime(&ltime, &now);
	
	struct timeb tb;
	ftime(&tb);
	sprintf(timeBuffer,"%04d%02d%02d%02d%02d%02d%02d",
		now.tm_year+1900,
		now.tm_mon+1,
		now.tm_mday,
		now.tm_hour,
		now.tm_min,
		now.tm_sec,
		tb.millitm/10);
	return timeBuffer;
}

char *getShortTime(void)
{
	time_t ltime;
	struct tm now;
	static char timeBuffer[21];
	
	time(&ltime);
	LocalTime(&ltime, &now);

	sprintf(timeBuffer,"%04d%02d%02d%02d%02d%02d",
		now.tm_year+1900,
		now.tm_mon+1,
		now.tm_mday,
		now.tm_hour,
		now.tm_min,
		now.tm_sec);
	return timeBuffer;
}

/*
int dbgOpen(char *strFileName){
	fpDebugOutput = mfopen(strFileName,"a+b");
	return 0;	
}

int dbgPrint(char *strBuffer)
{

	FILE *fp;
	fp = fpDebugOutput==NULL?stdout:fpDebugOutput;	
	fprintf(fp,"%s", strBuffer);
	fflush(fp);
	return 0;
	
}

int dbgClose()
{
	if (fpDebugOutput!=NULL){
		fclose(fpDebugOutput);
		fpDebugOutput=NULL;
	}	
	return 0;
}	

FILE *getFpDebugOutput()
{
	return  fpDebugOutput==NULL?stdout:fpDebugOutput;	

}
*/

 
int isValidNumber(char *str1)
/*
���ܣ� ��������str�Ƿ��Ƿ������±�׼����ֵ��
    û��С���������
    �����һ��С����ĸ�����
    ������TRIM���ܣ�����пո񣬷��ط�
return 0: ��
rerurn 1: ��
*/
{   
	char str[100];
	strcpy(str,str1);
	trim(str);
	int length=strlen(str);
    int dotnumber = 0,digitnumber = 0;
///���length==0���ط�
    if(length == 0 )
         return 0;
///���ÿһ���ַ������ֻ���С���㣬������С����ĸ���,��������쳣�ַ����Ҳ��������ţ�ֱ�ӷ��ط�
    for (int i=0;i < length ;i ++)
    {   if( !isdigit(str[i]))
        {   if( str[i] == '.' )
                dotnumber++;
            else
            {   if((str[i] == '-' || str[i] == '+')&& i == 0 )
                          ;
                else
                    return 0;
            }
        }
        else
            digitnumber ++;
    }
///���û�����֣����ط�
    if(digitnumber == 0)
        return 0;
///���С����ĸ�������һ���ط�
    if( dotnumber > 1)
        return 0;
///������
    return 1;
}
 

int isValidDate(char *str1)
/*
���ܣ�����ַ����Ƿ�Ϸ������ڸ�ʽyyyymmdd
    ע���ȷ�ǺϷ������ڣ�����������229�Ŀ��ǣ�
���أ�
    return 0: ��
    rerurn 1: ��
 
*/
{   
	char str[100];
	strcpy(str,str1);
	trim(str);

	
	int length=strlen(str);
    char buffer[10];
    struct tm time_check;
    int year, month, day;
///����ַ������Ȳ���ȷ��ֱ�ӷ���
    if(length != 8)
       return 0;
///���ÿһ���ַ�������
    for (int i=0;i < length ;i ++)
    {   if( !isdigit(str[i]))
                return 0;
    }
 
///�ж��������ںϷ��ķ�Χ�� 9999 > year > 1900 12 >= month >= 1 31>=day>=1
    memset(buffer,0,sizeof(buffer));
    memcpy(buffer,str,4);
    year = atoi(buffer);
    memset(buffer,0,sizeof(buffer));
    buffer[0]=str[4];
    buffer[1]=str[5];
    month = atoi(buffer);
    memset(buffer,0,sizeof(buffer));
    buffer[0]=str[6];
    buffer[1]=str[7];
    day = atoi(buffer);
///������Ч
    time_check.tm_year = year - 1900;
    time_check.tm_mon  = month - 1;
    time_check.tm_mday = day;
    time_check.tm_hour = 0;
    time_check.tm_min  = 0;
    time_check.tm_sec  = 1;
    time_check.tm_isdst = -1;
    if ( mktime(&time_check) == -1)
       return 0;
///ת��������Ӧ����ԭ�����ַ���һ��
    memset(buffer,0,sizeof(buffer));
    strftime(buffer,sizeof(buffer) - 1,"%Y%m%d",&time_check);
    if(strcmp(buffer,str)!=0)
      return 0;
    return 1;
}
 

int isValidTime(char *str)
/*
���ܣ�����ַ����Ƿ�Ϸ���ʱ���ʽhhmmss
���أ�
    return 0: ��
    rerurn 1: ��
*/
{
    int length=strlen(str);
    int result;
    char buffer[10];
    if(length != 6)
       return 0;
///���ÿһ���ַ�������
    for (int i=0;i < length ;i ++)
    {   if( !isdigit(str[i]))
                return 0;
    }
///��� 0<=hh<=23 0<=mm<=59 0<=ss<=59
    memset(buffer,0,sizeof(buffer));
    buffer[0]=str[0];
    buffer[1]=str[1];
    result = atoi(buffer);
    if(!(result >= 0 && result <=23))
       return 0;
    memset(buffer,0,sizeof(buffer));
    buffer[0]=str[2];
    buffer[1]=str[3];
    result = atoi(buffer);
    if(!(result >= 0 && result <=59))
       return 0;
    memset(buffer,0,sizeof(buffer));
    buffer[0]=str[4];
    buffer[1]=str[5];
    result = atoi(buffer);
    if(!(result >= 0 && result <=59))
       return 0;
   return 1;
}

bool CheckIpAddressMatch(const char *pIpAddress, 
						 const char *pIpMatch, 
						 const char *pIpMask)
{
	return CheckIpAddressMatch(inet_addr(pIpAddress), 
		inet_addr(pIpMatch),
		inet_addr(pIpMask));
}

bool CheckIpAddressMatch(const unsigned long ulIpAddress, 
						 const unsigned long ulIpMatch, 
						 const unsigned long ulpMask)
{
	return (ulIpAddress&ulpMask) == (ulIpMatch&ulpMask);
}

bool isRecovery(int argc, char *argv[])
{
	if (!strcmp(argv[argc-1],"recovery"))
	{
		return true;
	}
	return false;
}
