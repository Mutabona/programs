#include <stdio.h>
int f(int x);
int main()
{
    int a;
    scanf("%d", &a);
    printf("%d", f(a));
}
int f(int x)
{
    printf("Called with x = %d\n", x);
    if (x == 1 || x == 2)
        return 1;
    if (x == 3)
        return 3;
    if (x < 1)
        return 0;
    return f[x - 1] + f[x - 2] + f[x - 3];
} 
