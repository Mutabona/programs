#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getIndex(char **m, char *s, int n) {
    int i;
    for (i = 0; i < n * 2; i+=2) {
        if (!strcmp(m[i], s)) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, max = 0, c;
    int a;
    scanf("%d", &n);
    char **m = (char**)malloc(n * sizeof(char*) * 2);
    for (int i = 0; i < n * 2; i++) {
        scanf("%ms", &m[i]);
    }
    for (int i = 0; i < n * 2; i+=2) {
        c = 0;
        a = i;
        for (int j = 0; j < n; j++) {
            a = getIndex(m, m[a+1], n);
            c++;
            if (a == -1) {
                break;
            }
            else if (!strcmp(m[a], m[i])) {
                if (c > max) {
                    max = c;
                }
                break;
            }
        }
    }
    if (max == 2) {
        max = 0;
    }
    printf("%d", max);
    for (int i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);
    return 0;
}