#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, c = 0, cn = 0;
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
        c = 0;
        for (int j = 0; j < n; j++) {
            if (m[i][j] && i!=j) {
                c+=m[i][j];
            }
        }
        if (c == 1) {
            cn = 12;
            break;
        }
        if (c%2) {
            cn++;
        }
    }
    if (cn == 2 || cn == 0) {
        printf("YES");
    }
    else {
        printf("NO");
    }
    for (int i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);
    return 0;
}