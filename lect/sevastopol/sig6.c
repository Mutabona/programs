#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,m;
    scanf("%d %d", &n, &m);
    n++;
    m++;
    int **p = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        p[i] = (int*)malloc(m * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        p[i][0] = 1;
    }
    for (int j = 0; j < m; j++) {
        p[0][j] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            p[i][j] = p[i-1][j] + p[i][j-1];
        }
    }
    printf("%d", p[n-1][m-1]);
    for (int i = 0; i < n; i++) {
        free(p[i]);
    }
    free(p);
}
