#include <iostream>

class Coord{
public:
   int x;
   int y;
};

// Класс треугольник
class Triangle{
public:
  Coord p1,p2,p3;
};

Coord getPoint() {
    Coord a;
    std::cin>>a.x>>a.y;
    return a;
}

void getTri(Triangle& tri) {
    tri.p1 = getPoint();
    tri.p2 = getPoint();
    tri.p3 = getPoint();
}

int cmp(Triangle a, Triangle b) {
    double s1 = ((a.p1.x - a.p3.x) * (a.p2.y - a.p3.y) - (a.p2.x - a.p3.x) * (a.p1.y - a.p3.y))/2;
    double s2 = ((b.p1.x - b.p3.x) * (b.p2.y - b.p3.y) - (b.p2.x - b.p3.x) * (b.p1.y - b.p3.y))/2;
    if (s1 == s2) return 1;
    return 0;
}

int main() {
    Triangle a,c;
    getTri(a);
    getTri(c);
    std::cout<<cmp(a, c);
}