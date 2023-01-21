#include <iostream>
#include <sys/types.h>
#include <sys/time.h>

class A{
    public:
    static A* getA() {
        if(instance == nullptr) {
            instance = new A;
        }
        ++k;
        return instance;
    }
    int64_t time() {
        return t;
    }
    A(const A&) = delete;
    void operator=(const A&) = delete;
    private:
    static int k;
    static A *instance;
    static int64_t t;
    A() {
        timeval tv{};
        gettimeofday(&tv, NULL);
        t = (int64_t)tv.tv_usec + tv.tv_sec*1000000;
    }
};
A *A::instance = nullptr;
int A::k = 0;
int64_t A::t = 0;

int main() {
    std::cout<<(*A::getA()).time()<<'\n';
    std::cout<<(*A::getA()).time();
    return 0;
}