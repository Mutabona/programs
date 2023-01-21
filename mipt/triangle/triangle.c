#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, temp, max = 0;
    scanf("%d", &n);
    int **m = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        m[i] = (int*)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    int **m1 = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        m1[i] = (int*)malloc(n * sizeof(int));
    }
    m1[0][0] = m[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                m1[i][j] = m[i][j] + m1[i-1][j];
            }
            else if (j == i) {
                m1[i][j] = m[i][j] + m1[i-1][j-1];
            }
            else {
                temp = m1[i-1][j]>=m1[i-1][j-1]?m1[i-1][j]:m1[i-1][j-1];
                m1[i][j] = m[i][j] + temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (m1[n-1][i] > max) {
            max = m1[n-1][i];
        }
    }
    printf("%d", max);
    for (int i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);
    for (int i = 0; i < n; i++) {
        free(m1[i]);
    }
    free(m1);
    return 0;
}