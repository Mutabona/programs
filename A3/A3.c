#include <stdio.h>
#include <math.h>

int main() {
    double x1, y1, x2, y2, otv, m1, m2, scp;
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    scp = x1*x2+y1*y2;
    m1 = sqrt(x1*x1+y1*y1);
    m2 = sqrt(x2*x2+y2*y2);
    otv = scp/(m1*m2);
    otv = acos(otv);
    printf("%f", otv);
    return 0;
}