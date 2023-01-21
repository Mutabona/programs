#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, c = 0;
    scanf("%d", &n);
    int **m = (int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++) {
        m[i] = (int*)malloc(n*sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (m[i][j] == 1) {
                c++;
            }
        }
    }
    printf("%d", c);
    for (int i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);
    return 0;
}