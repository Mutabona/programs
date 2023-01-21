#include <stdio.h>

int main() {
    int n;
    long long a = 1, b = 1, c = 1;
    scanf("%d", &n);
    for (int i = 1; i<=n; i++) {
        c = a;
        a += b;
        b = c;
    }
    printf("%lld", a);
}