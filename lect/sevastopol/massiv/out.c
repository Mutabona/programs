#include <stdio.h>
#define RAZMER 16000000
int massiv[RAZMER];
int main()
{
	register int i;
	for(i = 0; i < RAZMER; i++)
		massiv[i] = i * i;
	printf("%d\n", massiv[RAZMER - 1]);
	return 0;
}
