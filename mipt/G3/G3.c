#include <stdio.h>

struct p {
    long double x;
    long double y;
};

long double scp() {
    return 
}

int main() {
    struct p pp[4];
    long double p1, p2, p3;
    scanf("%Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &o.x, &o.y);
    p1 = (a.x-o.x)*(b.y-a.y)-(b.x-a.x)*(a.y-o.y);
    p2 = (b.x-o.x)*(c.y-b.y)-(c.x-b.x)*(b.y-o.y);
    p3 = (c.x-o.x)*(a.y-c.y)-(a.x-c.x)*(c.y-o.y);
    if ((p1>0 && p2>0 && p3>0) || (p1<0 && p2<0 && p3<0) || p1 == 0 || p2 == 0 || p3 == 0) {
        printf("In");
    }
    else {
        printf("Out");
    }
    return 0;
}