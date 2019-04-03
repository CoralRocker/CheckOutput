#include <stdio.h>
#include <stdlib.h>
#include "../CheckOutput.h"

int main()
{
	/* 3 c-strings: A, B, C of size 64 bytes */
	size_t stringSize = 64;
	char *A = (char*)malloc(sizeof(char)*stringSize),
	     *B = (char*)malloc(sizeof(char)*stringSize),
	     *C = (char*)malloc(sizeof(char)*stringSize);
	
	/* Command to run */
	char* cmd = "ls -la";

	/* Test COn(char*, char*, size_t) */
	COn(cmd, A, stringSize);
	printf("---COn(char*,char*,size_t)---\n%s\n", A);
	free(A);

	/* Test sCOn(char*, char*, size_t) */
	sCOn(cmd, B, stringSize);
	printf("---sCOn(char*,char*,size_t)---\n%s\n", B);
	free(B);

	/* Test CO(char*, char*) */
	CO(cmd, C);
	printf("---CO(char*,char*)---\n%s\n", C);
	free(C);
}
