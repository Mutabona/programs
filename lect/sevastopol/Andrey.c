//D
#include <stdio.h>
int main() {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d", b % a);
        return 0;
}

//F
#include <stdio.h>
int main() {
        double x1, y1, x2, y2, x3, y3, xm, ym;
        scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
        printf("%lf %lf\n", (x1 + x2 + x3) / 3, (y1 + y2 + y3) / 3);

        return 0;
}
