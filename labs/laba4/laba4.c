#include <stdio.h>
#include <stdlib.h>

struct time {
    int hours;
    int minutes;
};

struct TRAIN {
    char from[20];
    char to[20];
    int number;
    struct time time;
};

struct Node {
    struct TRAIN train;
    struct Node* left;
    struct Node* right;
};

struct TRAIN setTrain();
struct time setTime();
struct Node* addTrain(struct Node* Node);
struct Node* addNode(struct Node* Node, struct TRAIN train);
void printTrain (struct TRAIN train);
void printAllTrains(struct Node* train);
void printTree(struct Node* node, int otstup);
void saveTrain(struct Node* train, FILE* file);
void saveTree(struct Node* train);
void freeTree(struct Node* train);
struct Node* makeTree(struct Node* Node);

int main() {
    struct Node* Node = NULL;
    int isActive = 1;
    while (isActive) {
        int choice;
        printf("%s\n", "1 - Add train");
        printf("%s\n", "2 - Print struct tree");
        printf("%s\n", "3 - Print all trains");
        printf("%s\n", "4 - Make tree");
        printf("%s\n", "8 - saveTree");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                Node = addTrain(Node);
                break;
            case 2:
                printTree(Node);
                break;
            case 3:
                printAllTrains(Node);
                break;
            case 4:
                Node = makeTree(Node);
            case 8:
                saveTree(Node);
                break;
        }
    }
    freeTree(Node);
    return 0;
}

struct TRAIN setTrain() {
    struct TRAIN newTrain;
    printf("From: "); scanf("%s", newTrain.from);
    printf("To: "); scanf("%s", newTrain.to);
    printf("Number: "); scanf("%d", &(newTrain.number));
    newTrain.time = setTime();
    return newTrain;
}

struct time setTime() {
    struct time time;
    printf("Hours: "); scanf("%d", &time.hours);
    printf("Minutes: "); scanf("%d", &time.minutes);
    return time;
}

struct Node* addTrain(struct Node* node) {
    struct TRAIN train = setTrain();
    node = addNode(node, train);
    return node;
}

struct Node* addNode(struct Node* Node, struct TRAIN train) {
    if (!Node) {
        Node = (struct Node*)malloc(sizeof(struct Node));
        Node->train = train;
        Node->left=NULL;
        Node->right=NULL;
    }
    else if (Node->train.number > train.number){
        Node->left = addNode(Node->left, train);
    }
    else {
        Node->right = addNode(Node->right, train);
    }
    return Node;
}

struct Node* deleteNode(struct Node* node) {

}

void printTrain (struct TRAIN train) {
    printf("From: %s\n", train.from);
    printf("To: %s\n", train.to);
    printf("Number: %d\n", train.number);
    printf("Time: %02d:%02d\n", train.time.hours, train.time.minutes);
    printf("\n");
    return;
}

void printAllTrains(struct Node* Node) {
    if (!Node)
        return;
    printAllTrains(Node->left);
    printTrain(Node->train);
    printAllTrain(Node->right);
    return;
}

void printTree(struct Node *node, int otstup) {
    if (node) {
        otstup+=3;
        otobr(node->right, otstup);
        for(int i=0; i < otstup; i++) printf(" ");
        printf("%d\n",node->train.number);
        otobr(node->left,otstup);
    }
}

void saveTrain(struct Node* Node, FILE* file) {
    if (!Node)
        return;
    fwrite(Node, sizeof(struct Node), 1, file);
    saveTrain(Node->left, file);
    saveeTrain(Node->right, file);
    return;
}

void saveTree(struct Node* Node) {
    FILE* file = fopen("trainData.dat", "wb");
    saveTrain(Node, file);
    printf("%s\n", "Data saved");
    fclose(file);
}

void freeTree(struct Node* Node) {
    if (!Node)
        return;
    freeTree(Node->left);
    freeTree(Node->right);
    free(Node);
    return;
}

struct Node* makeTree(struct Node* Node) {
    freeTree(Node);
    printf("\tOld tree deleted\n");
    Node = NULL;
    int choice = 0;
    do
    {
        Node = addTrain(Node);
        printf("1 - next, 0 - stop\n");
        scanf("%d", &choice);
    } while (choice);
    return Node;
}