#include <math.h>
#include <iostream>

class C{
public: //обойдёмся пока БЕЗ инкапсуляции
    double re; //поле
    double im; 

    double abs() { //метод
        return hypot(re, im);
    }

    C(double re_=0, double im_=0): re(re_), im(im_) {} //полиморфный конструктор
    C(const C* comp): re(comp->re), im((*comp).im) {comp++;} //мучения с указателями

	/*Конструктор копирования*/
    C(const C& comp): re(comp.re), im(comp.im) {/*comp.re=42;*/} //ссылку менять нельзя!
    
    C(C& comp): re(comp.re), im(comp.im) {/*comp.re=42;*/} //А данные по ссылке...

    //С a, b; a=b.sdelay_kopiju();  a=b => a.operator=(b);  перегруженный оператор присваивания
    C operator=(const C& comp) {
        re = comp.re;
        im = comp.im;
        return *this; //this - указатель на этот объект, от которого вызыван метод
    } 

   friend std::ostream& operator<<(std::ostream &out, const C &comp); //без this
    
}; //класс закончился


C operator+(const C& a, const C& comp) { //перегруженный оператор
    C result;
    result.re = comp.re + a.re;
    result.im = comp.im + a.im;
    return result;
}

using namespace std; //пространство имён

int main()
{
C a(-1, 2); //сконструировали
cout << a + 5 << endl; //вызываем конструктор, затем перегруженные операторы + и  <<
cout << 6 + a << endl;
}

std::ostream& operator<<(std::ostream &out, const C &comp) {
    out << comp.re << ' ' << comp.im;
    return out;
}

//  cout << 1/(z4*3 + 7) << endl;
