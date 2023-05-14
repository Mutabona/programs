#ifndef NODE_H
#define NODE_H
#include <stdlib.h>
#include <stdio.h>
#include "train.h"

struct Node {
    struct TRAIN train;
    struct Node* left;
    struct Node* right;
};

struct Node* addTrain(struct Node* Node);
struct Node* addNode(struct Node* Node, struct Node* newNode);
void printAllTrains(struct Node* train);
void printTree(struct Node* node, int otstup);
void saveTrain(struct Node* train, FILE* file);
void saveTree(struct Node* train);
void freeTree(struct Node* train);
struct Node* makeTree(struct Node* Node);
struct Node* deleteNode(struct Node* node, int number);
struct Node* loadData(struct Node* node);
struct Node* loadTree(struct Node* Node, FILE* file);
struct Node* changeNumbers (struct Node* node, int number);
int printTrainsByLetter(struct Node* node, char letter);
int run();

#endif