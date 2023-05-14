#include "trainList.h"
#include "train.h"

struct trainList* addTrainToStart(struct trainList* trainList) {
    struct trainList* newTrain = (struct trainList*)malloc(sizeof(struct trainList));
    newTrain->train = setTrain();
    newTrain->next = trainList;
    return newTrain;
}

struct trainList* addTrain(struct trainList* trainList) {
    if (!trainList) {
        trainList = (struct trainList*)malloc(sizeof(struct trainList));
        trainList->train=setTrain();
        trainList->next=NULL;
        return trainList;
    }
    else {
        trainList->next = addTrain(trainList->next);
    }
    return trainList;
}

void printAllTrains(struct trainList* trainList) {
    if (!trainList)
        return;
    printTrain(trainList->train);
    printAllTrains(trainList->next);
    return;
}

struct trainList* setList() {
    FILE* file = fopen("trainData.dat", "rb");    
    if (!file)
        return NULL;
    fseek(file, 0, 2);
    int trainCount = ftell(file)/sizeof(struct trainList);
    struct trainList* readTrain = NULL;
    struct trainList* trainList = NULL;
    rewind(file);
    for (int i = 0; i < trainCount; i++) {
        if (!readTrain)
            readTrain = (struct trainList*)malloc(sizeof(struct trainList));
        fread(readTrain, sizeof(struct trainList), 1, file);
        if (!trainList) {
            trainList = readTrain;
        }
        if (i < trainCount - 1) {
            readTrain->next = (struct trainList*)malloc(sizeof(struct trainList));
            readTrain = readTrain->next;
        }
    }
    fclose(file);
    printf("%s\n", "Data loaded");
    return trainList;
}

void saveTrain(struct trainList* trainList, FILE* file) {
    if (!trainList)
        return;
    fwrite(trainList, sizeof(struct trainList), 1, file);
    saveTrain(trainList->next, file);
    return;
}

void saveList(struct trainList* trainList) {
    FILE* file = fopen("trainData.dat", "wb");
    saveTrain(trainList, file);
    printf("%s\n", "Data saved");
    fclose(file);
}

struct trainList* deleteFirstTrain(struct trainList* trainList) {
    if (!trainList)
        return NULL;
    struct trainList* newFirst = trainList->next;
    free(trainList);
    return newFirst;
}

void freeList(struct trainList* trainList) {
    if (!trainList)
        return;
    freeList(trainList->next);
    free(trainList);
    return;
}

struct trainList* makeList(struct trainList* trainList) {
    freeList(trainList);
    trainList = NULL;
    int choice = 0;
    do
    {
        trainList = addTrain(trainList);
        printf("1 - next, 0 - stop\n");
        scanf("%d", &choice);
    } while (choice);
    return trainList;
}

void variantFunction(struct trainList* trainList) {
    if (!trainList)
        return;
    struct trainList* train1 = trainList;
    struct trainList* train2 = NULL;
    while (train1->next) {
        train2 = train1;
        train1 = train1->next;
    }
    struct trainList* newTrain = (struct trainList*)malloc(sizeof(struct trainList));
    newTrain->train=setTrain();
    newTrain->next=NULL;
    train2->next = newTrain;
    newTrain->next = (struct trainList*)malloc(sizeof(struct trainList));
    newTrain->next->train=setTrain();
    newTrain->next->next=train1;
    return;
}

int run() {
    struct trainList* trainList = setList();
    int isActive = 1;
    while (isActive) {
        int choice;
        printf("%s\n", "1 - Add first train");
        printf("%s\n", "2 - Add last train");
        printf("%s\n", "3 - Print all trains");
        printf("%s\n", "4 - Delete first train");
        printf("%s\n", "5 - Make list");
        printf("%s\n", "6 - Variant function");
        printf("%s\n", "7 - Exit");
        printf("%s\n", "8 - Save list");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                trainList = addTrainToStart(trainList);
                break;
            case 2:
                trainList = addTrain(trainList);
                break;
            case 3:
                printAllTrains(trainList);
                break;
            case 4:
                trainList = deleteFirstTrain(trainList);
                break;
            case 5:
                trainList = makeList(trainList);
                break;
            case 6:
                variantFunction(trainList);
                break;
            case 7:
                
                freeList(trainList);
                isActive = 0;
                break;
            case 8:
                saveList(trainList);
                break;
        }
    }
    return 0;
}