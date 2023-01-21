#include <iostream>

using namespace std;

int** getMat(int);
int countN(int**, int);
void change(int**, int);
void freeMat(int**, int);
void printMat(int**, int);

int main() {
    int n;
    cin>>n;
    int** mat = getMat(n);
    int cn = countN(mat, n);
    change(mat, n);
    printMat(mat, n);
    freeMat(mat, n);
    return 0;
}

int countN(int** mat, int n) {
    bool f;
    int cn = 0;
    for (int i = 0; i < n; i++) {
        f = 0;
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                f = 1;
            }
        }
        if (f)
            cn++;
    }
    return cn;
}

int** getMat(int n) {
    int **mat = new int* [n];
    for (int i = 0; i < n; i++) {
        mat[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>>mat[i][j];
        }
    }
    return mat;
}

void change(int** mat, int n) {
    int temp;
    for (int i = 0; i < n; i++) {
        temp = mat[i][0];
        mat[i][0] = mat[n-1][n-i-1];
        mat[n-1][n-i-1] = temp;
    }
}

void printMat(int** mat, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<<mat[i][j]<<' ';
        }
        cout<<'\n';
    }
}

void freeMat(int** mat, int n) {
    for(int i = 0; i < n; i++) {
        delete[] mat[i];
    }
    delete[] mat;
}