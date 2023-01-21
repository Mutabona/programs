#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, imin;
    long long c, a, counter = 0;
    long long temp[1000];
    scanf("%d", &n);
    long long m[101];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &m[i]);
    }
    scanf("%lld", &c);
    for (int i = 0; i < n - 1; i++) {
        imin = i;
        a = m[i];
        for (int j = i+1; j < n; j++) {
            if (m[j] < a) {
                imin = j;
                a = m[imin];
            }
        }
        m[imin] = m[i];
        m[i] = a;
    }
    while (c > 0) {
        for (int i = n-1; i >= 0; i--) {
            if (c >= m[i]) {
                c -= m[i];
                temp[counter] = m[i];
                counter++;
                break;
            }
        }
    }
    printf("%lld\n", counter);
    for (int i = 0; i < counter; i++) {
        printf("%lld ", temp[i]);
    }
    return 0;
}