#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

class Time{
  public:
   int hour;
   int min;
};

Time add(Time a, int min){
    a.min += min;
    a.hour += a.min/60;
    a.min %= 60;
    a.hour %= 24;
    return a;
}


int main() {
    Time a,newtime;
    int min;

    cin>>a.hour>>a.min;

    cin>>min;
    newtime = add(a,min);
    cout << newtime.hour << ":" << newtime.min << endl;
}