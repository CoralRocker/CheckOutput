//DEV BRANCH VERSION
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

void CO(char* restrict cmd, char* restrict buf)
{
	FILE *p = popen(cmd, "r");
	if(p == NULL)
	{
		char buffer[256];
		strerror_r(errno, buffer, 256);
		printf("ERROR: %s\n", buffer);
		exit(-1);
	}
	char c;
	size_t len = 0;
	while((c = fgetc(p))!=EOF)
		len += sprintf(buf + len, "%c", c);
	pclose(p);
}

int COn(char* restrict cmd, char* restrict buf, size_t bufSize)
{
	FILE *p = popen(cmd, "r");
	if(p == NULL)
	{
		char buffer[256];
		strerror_r(errno, buffer, 256);
		printf("ERROR: %s\n", buffer);
		exit(-1);
	}
	char c;
	size_t len = 0;
	while((c = fgetc(p))!=EOF)
	{
		if(len + 2 > bufSize)
			return -1;
		len += sprintf(buf + len, "%c", c);
	}
	pclose(p);
	return 0;
}
int sCOn(char* restrict cmd, char* restrict buf, size_t bufSize)
{
	FILE *p = popen(cmd, "r");
	if(p == NULL)
	{	
		char buffer[256];
		strerror_r(errno, buffer, 256);
		printf("ERROR: %s\n", buffer);
		exit(-1);
	}
	char c;
	size_t len = 0;
	while((c = fgetc(p))!=EOF)
	{
		if(len + 2 == bufSize)
		{
			sprintf(buf + len, 0x00);
			return -1;
		}
		len += sprintf(buf + len, "%c", c);
	}
	pclose(p);
	return 0;
}
