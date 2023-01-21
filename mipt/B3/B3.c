#include <stdio.h>
#include <math.h>

struct point{
    long double x;
    long double y;
};

int main() {
    struct point dr;
    struct point st;
    struct point en;
    long double t, l;
    scanf("%Lf %Lf %Lf %Lf %Lf %Lf", &dr.x, &dr.y, &st.x, &st.y, &en.x, &en.y);
    t = ((dr.x - st.x)*(en.x - st.x)+(dr.y - st.y)*(en.y - st.y))/((en.x-st.x)*(en.x-st.x)+(en.y-st.y)*(en.y-st.y));
    t = t<0?0:t>1?1:t;
    l = sqrt(pow(st.x-dr.x+(en.x-st.x)*t, 2) + pow(st.y-dr.y+(en.y-st.y)*t, 2));
    printf("%Lf", l);
}