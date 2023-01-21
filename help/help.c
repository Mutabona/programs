#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int temp;
    int z = m>n?m:n;
    int **a = (int**)malloc(z * sizeof(int*));
    for (int i = 0; i < n; i++) {
        a[i] = (int*)malloc(z * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    if (n > m)
        a = (int**)realloc(a, m * sizeof(int*));
    else
    for (int i = 0; i < m; i++)
        a[i] = (int*)realloc(a[i], n * sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < m; j++) {
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}