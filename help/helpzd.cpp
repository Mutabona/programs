#include <iostream>

using namespace std;

void printMat(int**);
int** getMat();
void randMat(int**);
void replace(int**);

int main() {
    int **mat = getMat();
    printMat(mat);
    cout<<'\n';
    replace(mat);
    printMat(mat);
    return 0;
}

void printMat(int** mat) {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout<<mat[i][j]<<' ';
        }
        cout<<'\n';
    }
}

void randMat(int** mat) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            mat[i][j] = rand()%100;
        }
    }
}

int** getMat() {
    int **mat = new int* [10];
    for (int i = 0; i < 10; i++) {
        mat[i] = new int[10];
    }
    randMat(mat);
    return mat;
}

void replace(int** mat) {
    int temp;
    int k=4;
    for (int i = 0; i < 10;) {
        for (int j = 0; j < 10; j++) {
            temp = mat[j][i];
            mat[j][i] = mat[j][i+k];
            mat[j][i+k] = temp;
        }
        if(i%2) {
            i+=4;
            k=4;
        }
        else {
            i++;
            k=2;
        }
    }
}