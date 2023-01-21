//Подключение заголовочных файлов
#include <iostream>
#include <iomanip>

using namespace std; //Подключение пространства имён std

//Обьявление функций
void sordMD(int**, int);
void matD(int**, int, int**, int);
void zeroMat(int**, int);
void printMat(int**, int);
int** getMat(int, char);
void randMat(int**, int);
void freeMat(int**, int);

int main() {
    int** mat6 = getMat(6, 'r'); //Создание матрицы 6 на 6
    printMat(mat6, 6); //Вывод созданной матрицы
    cout<<'\n';
    int** mat36 = getMat(36, '0'); // Создание матрицы 36 на 36
    matD(mat6, 6, mat36, 36); //Заполнение матрицы 36 на 36
    printMat(mat36, 36); //Вывод матрицы
    freeMat(mat6, 6); //Освобождение памяти
    freeMat(mat36, 36); //Освобождение памяти
    return 0;
}

//Функция сортировки диогонали матрицы
void sortMD(int** mat, int n) {
    for (int i = 0; i < n - 1; i++) {
        int imin = i;
        int temp = mat[n-1-i][i];
        for (int j = i + 1; j < n; j++) {
            if (temp > mat[n-1-j][j]) {
                imin = j;
                temp = mat[n-1-j][j];
            }
        }
        mat[n-1-imin][imin] = mat[n-1-i][i];
        mat[n-1-i][i] = temp;
    }
}

//Функция заполнения матрицы от другой матрицы
void matD(int** from, int n, int** to, int n2) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            to[n2-1-(i*n+j)][i*n+j] = from[i][j];
        }
    }
    sortMD(to, n2); //Сортировка
}

//Функция вывода
void printMat(int** mat, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<<setw(2)<<mat[i][j]<<' '; //Вывод
        }
        cout<<'\n';
    }
}

//Функция заполнения рандомными числами
void randMat(int** mat, int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {         
            mat[i][j] = rand()%100; //Заполнение рандомными числами до 100
        }
    }
}

//Заполнение нудями
void zeroMat(int** mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = 0;
        }
    }
}

//Создание матрицы
int** getMat(int n, char mode) {
    //Выделение памяти
    int **mat = new int* [n];
    for (int i = 0; i < n; i++) {
        mat[i] = new int[n];
    }
    switch(mode) {
        case 'r':
            randMat(mat, n); //Вызов функции рандомного заполнения
            break;
        case '0':
            zeroMat(mat, n); //Вызов функции заполнения нулями
            break;
    }
    return mat; //Возврат матрицы
}

//Функция освобождения памяти
void freeMat(int** mat, int n) {
    for(int i = 0; i < n; i++) {
        delete[] mat[i];
    }
    delete[] mat;
}