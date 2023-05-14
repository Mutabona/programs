#ifndef TRAIN_H
#define TRAIN_H

#include <stdio.h>
#include "time.h"

struct TRAIN {
    char from[20];
    char to[20];
    int number;
    struct time time;
};

struct TRAIN setTrain();
void printTrain (struct TRAIN train);

#endif