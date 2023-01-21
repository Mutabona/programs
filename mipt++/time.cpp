#include <iostream>
#include <iomanip>

class Time{
    public:
    int hours;
    int minutes;
    Time(): minutes(0), hours(0) {}
    Time(int hours_, int minutes_) {
        if (hours_ > 12 || minutes_ > 59) {
            hours = 0;
            minutes = 0;
        }
        else {
            hours = hours_;
            minutes = minutes_;
        }
    }
    bool operator==(Time t2) {
        if (hours == t2.hours && minutes == t2.minutes) {
            return true;
        }
        return false;
    }
    Time operator+(Time t2) {
        Time result;
        result.minutes = minutes + t2.minutes;
        result.hours = result.minutes/60 + hours + t2.hours;
        result.minutes %= 60;
        if (result.hours >= 13)
            result.hours %= 12;
        return result;
    }
    friend std::ostream& operator<<(std::ostream& out, const Time& t);
};

std::ostream& operator<<(std::ostream& out, const Time& t) {
    out<<t.hours<<'.'<<std::setfill('0')<<std::setw(2)<<t.minutes;
    return out;
}

int main() {
    Time t1(10, 12);
    Time t2(2, 3);
    std::cout<<t1 + t2;
}