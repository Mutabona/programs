#ifndef TIME_H
#define TIME_H

#include <stdio.h>

struct time {
    int hours;
    int minutes;
};

struct time setTime();

#endif