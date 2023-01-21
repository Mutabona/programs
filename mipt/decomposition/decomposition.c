#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    long long p[101][101];
    for (int i = 0; i <= n; i++) {
        p[1][i] = 1;
        p[i][1] = 1;
        p[0][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        p[i][0] = 0;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            if (i < j) {
                p[i][j] = p[i][j-1];
            }
            else {
                p[i][j] = p[i][j-1] + p[i-j][j];
            }
        }
    }
    printf("%lld", p[n][n]);
    return 0;
}
/*
/ 0 1 2 3 4 5
0 1 1 1 1 1 1
1 0 1 1 1 1 1
2 0 1 2 2 2 2
3 0 1 2 3 3 3
4 0 1 3 4 5 5
5 0 1 3 5 6 7
*/