#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct p {
    int x;
    int y;
};

int main() {
    struct p * pp;
    int n, p1, p2;
    long double s = 0;
    scanf("%d", &n);
    pp = malloc(n*sizeof(struct p));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pp[i].x, &pp[i].y);
    }
    for (int i = 0; i < n; i++) {
        p1 = pp[i].x;
        p2 = i<(n-1)?pp[i+1].y:pp[0].y;
        s += p1*p2;
    }
    for (int i = 0; i < n; i++) {
        p1 = pp[i].y;
        p2 = i<(n-1)?pp[i+1].x:pp[0].x;
        s -= p1*p2;
    }
    s = fabs(s)/2;
    printf("%Lg", s);
    free(pp);
    return 0;
}