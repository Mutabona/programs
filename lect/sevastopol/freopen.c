#include <stdio.h>
#include <stdlib.h>
//#define FILES
int main(int argc, char *argv[], char *envp[])
{
	int a, i;

#ifdef FILES
	freopen("otkuda", "rt", stdin);
#endif
	scanf("%d", &a);

#ifdef FILES
	freopen("kuda", "wt", stdout);
#endif
	printf("%d\n", a);
	FILE *f;
	f = fopen("tuda", "wt");
	fprintf(f, "result = %d\n", a);
	fclose(f);
	printf("%d\n", argc);
	for(i=0; i < argc; i++)
		printf("%s\n", argv[i]);
	for(i=0; envp[i]; i++)
	       printf("%s\n", envp[i]);
	printf("%s\n", getenv("NAME"));
}
