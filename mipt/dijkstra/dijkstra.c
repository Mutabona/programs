#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int n;

void vl(int **a, int *v, int i, int p) {
    for (int j = 0; j < n; j++) {
        if (a[i][j]) {
            if (a[i][j] + p < v[j]) {
                v[j] = a[i][j] + p;
            }
            a[i][j] = 0;
            vl(a, v, j, v[j]);
        }
    }
}

int main() {
    int m, b, c;
    scanf("%d %d", &n, &m);
    int *v = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        v[i] = INT_MAX;
    }
    int **a = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        a[i] = (int*)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &b, &c);
        scanf("%d", &a[b][c]);
        a[c][b] = a[b][c];
    }
    scanf("%d", &b);
    v[b] = 0;
    vl(a, v, b, 0);
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    free(v);
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
    return 0;
}