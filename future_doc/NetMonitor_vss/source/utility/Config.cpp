//
//////////////////////////////////////////////////////////////////////
#include "CBaseObject.h"
#include "Config.h"

#define CONFIG_MAX_LEN			128

void GetConfigString(const char *filename, char *key, char *val, int size)
{
	char    msg[100];
	char    buffer[CONFIG_MAX_LEN+10];
	char 	*tkey,*tval;

	FILE  *fp=mfopen(filename, "r");
	if (fp == NULL)
	{
		sprintf(msg,"config file [%s] not found", filename);
		RAISE_RUNTIME_ERROR(msg);
		return;
	}

	while (fgets(buffer, CONFIG_MAX_LEN, fp)!=NULL)
	{
		if (strtok(buffer,"\n\r")==NULL)
		{
			continue;	
		}

		if (buffer[0]=='#')
		{
			continue;
		}

		tkey = strtok(buffer, "\n\r=");
		tval = strtok(NULL, "\n\r");
		if (tkey == NULL)
		{
			sprintf(msg,"error in config file:[%s]-[%s]", filename, key);
			RAISE_RUNTIME_ERROR(msg);
			return ;
		}
		if (strcmp(key, tkey) == 0)
		{
			fclose(fp);	
			if (tval == NULL)
			{
				strncpy(val, "", size);
			}
			else
			{
				strncpy(val, tval, size);
			}
			return;
		}
	}
	
	fclose(fp);
	
	sprintf(msg,"can not get this config:[%s]-[%s]", filename, key);
	RAISE_RUNTIME_ERROR(msg);
}

int GetConfigInt(const char *filename, char *key)
{
	char buf[CONFIG_MAX_LEN];
	GetConfigString(filename, key, buf, sizeof(buf));
	return atoi(buf);
}
