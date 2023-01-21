#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 500
int main()
{
	char stroka[SIZE];
	int i;
	//stroka[0]=0;
	scanf("%s", stroka);
	for(i=0; stroka[i]; i++);
	printf("%d\n", i);
	char *string;
	int retcode;
	retcode = scanf("%m[^*]%n", &string, &i);
	printf("retcode = %d\n", retcode);
	printf("Строка ");
	printf(string);
	printf("  длиной  %d\n", i);
	if(strcmp(stroka, "abc") == 0)
		printf("abc found!\n");
	free(string);
	return 0;

}
	
