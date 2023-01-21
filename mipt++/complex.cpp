#include <iostream>
#include <math.h>

class C{
public:
    double re;
    double im;

    double abs() {
        return sqrt(re*re+im*im);
    }
    C(double re_=0, double im_=0): re(re_), im(im_) {}
    C(const C& comp): re(comp.re), im(comp.im) {}

    C operator=(const C& comp) {
        re = comp.re;
        im = comp.im;
        return *this;
    }

    bool operator==(const C& comp) {
        if (re == comp.re && im == comp.im) return true;
        return false;
    } 
    bool operator!=(const C& comp) {
        if (re == comp.re && im == comp.im) return false;
        return true;
    }
    friend std::ostream& operator<<(std::ostream &out, const C &comp);
};

C operator/(const C& a, const C& comp) {
    C result;
    result.re = (a.re * comp.re + a.im * comp.im)/(comp.re * comp.re + comp.im * comp.im);
    result.im = (comp.re * a.im - a.re * comp.im)/(comp.re * comp.re + comp.im * comp.im);
    return result;
}

C operator*(const C& comp, const C& a) {
    C result;
    result.re = a.re * comp.re - a.im * comp.im;
    result.im = comp.re * a.im + a.re * comp.im;
    return result;
}

C operator+(const C& a, const C& comp) {
    C result;
    result.re = comp.re + a.re;
    result.im = comp.im + a.im;
    return result;
}

C operator-(const C& a, const C& comp) {
    C result;
    result.re = comp.re - a.re;
    result.im = comp.im - a.im;
    return result;
}

bool operator==(const C& comp, const C& comp1) {
    if (comp1.re == comp.re && comp1.im == comp.im) return true;
        return false;
    } 
bool operator!=(const C& comp, const C& comp1) {
    if (comp1.re == comp.re && comp1.im == comp.im) return false;
        return true;
    }
std::ostream& operator<<(std::ostream &out, const C &comp) {
    out << comp.re << ' ' << comp.im;
    return out;
}

int main() {
    double a = 9;
    C comp(3, 4);
    C comp2(comp);
    comp2 = comp * comp;
    if (comp != comp2) {
        std::cout<<comp2;
    }
}