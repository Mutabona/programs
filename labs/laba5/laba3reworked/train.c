#include "train.h"

struct TRAIN setTrain() {
    struct TRAIN newTrain;
    printf("From: "); scanf("%s", newTrain.from);
    printf("To: "); scanf("%s", newTrain.to);
    printf("Number: "); scanf("%d", &(newTrain.number));
    newTrain.time = setTime();
    return newTrain;
}

void printTrain (struct TRAIN train) {
    printf("From: %s\n", train.from);
    printf("To: %s\n", train.to);
    printf("Number: %d\n", train.number);
    printf("Time: %02d:%02d\n", train.time.hours, train.time.minutes);
    printf("\n");
    return;
}