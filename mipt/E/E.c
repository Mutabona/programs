#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, a, b, i, j = 0;
    scanf("%d", &n);
    int **m = NULL;
    for (i = 0; i < n; i++) {
        scanf("%d", &a);
        if (j <= a) {
            m = (int**)realloc(m, (a + 1) * sizeof(int*));
            for (; j <= a; j++) {
                m[j] = (int*)malloc(2 * sizeof(int));
                m[j][0] = 0;
                m[j][1] = 0;
            }
        }
        m[a][0]++;
        scanf("%d %d", &b, &b);
        m[a][1] += b;
    }
    for (i = 0; i < j; i++) {
        printf("%d %d %d\n", i, m[i][0], m[i][1]);
    }
    for (i = 0; i < j; i++) {
        free(m[i]);
    }
    free(m);
    return 0;
}