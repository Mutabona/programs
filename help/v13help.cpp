#include <iostream> //Подключение библиотеки iostream

using namespace std; //Подлкючаем пространство имён std

//Функция создания матрицы
int** sozdat_mat(int n, int m) {
    //Выделение памяти
    int **mat = new int* [n];
    for (int i = 0; i < n; i++) {
        mat[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout<<"Введите "<<j<<" элемент "<<i<<" строки: ";
            cin>>mat[i][j]; //Считывание элементов матрицы
        }
    }
    return mat;
}

//Функция подсчёта произведений
void pr(int** mat, int n, int m) {
    long long proizv;
    for(int j = 0; j < m; j++) {
        proizv = 1;
        for(int i = 0; i < n; i++) {
            proizv*=mat[i][j]; //Нахождение прозведений столбцов
        }
        cout<<"Произведение элементов в столбце " <<j<<" = "<<proizv<<'\n'; //Вывод произведений
    }
}

//Функциия замены элементов
void zamenit(int** mat, int n, int m) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            mat[i][j] = 0; //Замена элементов ниже главной диагонали нулями
        }
    }
}

//ФФункция вывода матрицы
void outmat(int** mat, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout<<mat[i][j]<<' '; //Вывод элементов матрицы
        }
        cout<<'\n';
    }
}

//Функция освобождения памяти
void freepamyat(int** mat, int n) {
    //Освобождение памяти
    for(int i = 0; i < n; i++) {
        delete[] mat[i]; 
    }
    delete[] mat;
}

int main() {
    //Считывание размерности матрицы
    int n, m;
    cout<<"Введите количество строк: ";
    cin>>n;
    cout<<"Введите количество столбцов: ";
    cin>>m;
    //Вызов функции создания матрицы
    int** mat = sozdat_mat(n, m);
    //Вызов функции произведений столбцов матрицы
    pr(mat, n, m);
    //Вызов функции ззамены элементов матрицы
    zamenit(mat, n, m);
    //Вызов функции вывода элементов матрицы
    outmat(mat, n, m);
    //Вызов функции освобождения памяти
    freepamyat(mat, n);
    return 0;
}