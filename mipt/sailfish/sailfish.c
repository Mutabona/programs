#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, a, b, c;
    scanf("%d", &n);
    int m[65536] = {0};
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (m[i] == 0 || m[i] > m[i-1] + a) {
            m[i] = m[i-1] + a;
        }
        if (m[i+1] == 0 || m[i+1] > m[i-1] + b) {
            m[i+1] = m[i-1] + b;
        }
        if (m[i+2] == 0 || m[i+2] > m[i-1] + c) {
            m[i+2] = m[i-1] + c;
        }
    }
    printf("%d", m[n]);
}