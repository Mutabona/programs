#ifndef TRAINLIST_H
#define TRAINLIST_H

#include "train.h"
#include <stdio.h>
#include <stdlib.h>

struct trainList {
    struct TRAIN train;
    struct trainList* next;
};

struct trainList* addTrainToStart(struct trainList* trainList);
struct trainList* addTrain(struct trainList* trainList);
void printAllTrains(struct trainList* train);
struct trainList* setList();
void saveTrain(struct trainList* train, FILE* file);
void saveList(struct trainList* train);
struct trainList* deleteFirstTrain(struct trainList* trainList);
void freeList(struct trainList* train);
struct trainList* makeList(struct trainList* trainList);
void variantFunction(struct trainList* trainList);
int run();

#endif