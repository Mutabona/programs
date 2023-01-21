#include <stdio.h>
static unsigned long long int count;
unsigned long long  fibonacci(int n) { 
    count++;
    if (n == 1 || n == 2 || n == 3) {
        return 1; // первые 3 числа равны 1
    }
    return fibonacci(n - 1) + fibonacci(n - 2) + fibonacci(n - 3);
}

int main() {
    unsigned long long  n;
    count = 0;
    scanf("%d", &n);
    n ++;
    printf("%llu\n", fibonacci(n));
    printf("%llu\n", count);
    return 0;
}
