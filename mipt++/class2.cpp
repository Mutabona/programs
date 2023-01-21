#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

class Time{
  public:
   int hour;
   int min;
};

int isEqual(Time a, int min) {
    if (a.hour * 60 + a.min == min) {
        return 1;
    }
    return 0;
}

int main() {
    Time a,newtime;
    int min;
    int res;



    cin>>a.hour>>a.min;

    cin>>min;
    res = isEqual(a,min);
    cout <<res<< endl;
}