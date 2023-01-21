#include <iostream>

class Lin{
  public:
   int cm; // сантиметры
   int mm; // миллиметры
};

Lin convertToLin(int kletki) {
    Lin b;
    b.cm = kletki/2;
    b.mm = kletki%2*5;
    return b;
}

void printLin(Lin a) {
    std::cout<<a.cm<<' '<<a.mm;
}

int main() {
    Lin a;
    int kletki;
    std::cin>>kletki;
    a = convertToLin(kletki);
    printLin(a);
    return 0;
}