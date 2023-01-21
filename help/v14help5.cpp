#include <iostream> //Подключение заголовочного файла

using namespace std; //Пространство имён std

//Обьявление фнукций
int** vvesti_mat(int);
int summa(int**, int);
void replace(int**, int);
void osvobodit(int**, int);
void vivesti(int**, int);

//Основная функция main
int main() {
    int n;
    cout<<"Введите размер квадратной матрицы: ";
    cin>>n;
    //Вызов функции создания квадратной матрицы
    int** mat = vvesti_mat(n);
    //Вызов функции вычисления суммы элементов главной диагонали
    int sum = summa(mat, n);
    cout<<"Сумма элементов главной диагонали = "<<sum<<'\n';
    //Вызов функции замены
    replace(mat, n);
    //Вызов функции вывода матрицы
    vivesti(mat, n);
    //Вызов функции освобождения памяти
    osvobodit(mat, n);
    return 0;
}

//Определение функций

int summa(int** mat, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum+=mat[i][i]; //Складываем все элементы главной диагонали
    }
    return sum; //Возвращаем сумму
}

int** vvesti_mat(int n) {
    //Выделение памяти
    int **mat = new int* [n];
    for (int i = 0; i < n; i++) {
        mat[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout<<"Введите "<<j<<" элемент "<<i<<" строки: ";
            cin>>mat[i][j]; //Считывание элемента матрицы
        }
    }
    return mat;
}

void replace(int** mat, int n) {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (!(i%2) || !(j%2)) {
                temp = mat[i][j];
                mat[i][j] = mat[j][i]; //Замена нечётных столбцов нечётными строками(т.к. у нас они начинаются с нулевой делаем наоборот)
                mat[j][i] = temp;
            }
        }
    }
}

void vivesti(int** mat, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<<mat[i][j]<<' '; //Вывод элементов матрицы
        }
        cout<<'\n';
    }
}

void osvobodit(int** mat, int n) {
    //Освобождение памяти
    for(int i = 0; i < n; i++) {
        delete[] mat[i];
    }
    delete[] mat;
}