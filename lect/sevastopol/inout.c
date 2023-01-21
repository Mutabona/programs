#include <stdio.h>
int main()
{
	int x;
	scanf("%o", &x); //&x - Где x? По указателю
	//o = octal, x = heXadecimal, d = Decimal
	printf("%x\n", x % 3); //копия x -  по значению.
	return 0;
}
