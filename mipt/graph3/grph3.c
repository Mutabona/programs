#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, n1;
    scanf("%d", &n);
    scanf("%d", &n1);
    int **m = (int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++) {
        m[i] = (int*)malloc(n*sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = 0;
        }
    }
    for (int i = 0, b, a; i < n1; i++) {
        scanf("%d %d", &a, &b);
        m[a][b] = 1;
        m[b][a] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);
    return 0;
}