/*
     64			 1000
0...2   - 1		3

15	0
16	1
17	2
18	3

CODE - '0'

*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
	char *stroka;
	unsigned dlina;
	register unsigned res = 0;
	scanf("%m[0-9]%n", &stroka, &dlina);
	for(register unsigned i=0; i < dlina; i++)
		res += stroka[i] - '0';
	printf(res % 3 ? "NO\n" : "YES\n");
	free(stroka);
	return 0;
}
