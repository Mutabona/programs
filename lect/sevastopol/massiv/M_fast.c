#include <stdio.h>
int main()
{
	register unsigned long long a, b, c, d, i;
	unsigned long long n;
	a = 1;
	b = 1;
	c = 1;
	d = 1;
	scanf("%llu", &n);
	for(i = 3; i <= n; i++)
	{
		d = a + b + c;
		a = b;
		b = c;
		c = d;
	}
	printf("%llu\n", d);
	return 0;
}
/*
x^4 + 2 x^3 + 3x*sqrt(x) + 4 ln(x)
O(x^4) C * x^4

O(exp(x))
O(x)

*/
