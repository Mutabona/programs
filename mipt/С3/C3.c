#include <stdio.h>

struct point {
    double x;
    double y;
};
int main() {
    struct point p[4];
    for (int i = 0; i < 4; i++) {
        scanf("%lf %lf", &p[i].x, &p[i].y);
    }
    if (((p[0].x == p[2].x) && (p[0].y == p[2].y)) || ((p[0].x == p[3].x) && (p[0].y == p[3].y)) || ((p[1].x == p[3].x) && (p[1].y == p[3].y)) || ((p[1].x == p[2].x) && (p[1].y == p[2].y))) {
        printf("YES");
        return 0;
    }
    struct point v[2];
    v[0].x = p[1].x - p[0].x; v[0].y = p[1].y - p[0].y;
    v[1].x = p[3].x - p[2].x; v[1].y = p[3].y - p[2].y;
    if ((v[0].x * v[1].y + v[0].y * v[1].x) == 0) {
        printf("NO");
    }
    else {
        printf("YES");
    }
    return 0;
}