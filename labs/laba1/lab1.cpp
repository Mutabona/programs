//Подключение заголовочных файлов
#include <iostream>
#include <fstream>

//Пространство имён std
using namespace std;

int main() {
    const int STRING_SIZE = 80; //Создание константы длины строки
    ifstream fileInput("input.txt", ios::in); //Вызов конструктора класса ifstream
    if(!fileInput) { //Проверка на удачное открытие потока
        printf("Failed to open the file");
        return 1; //Выход из программы
    }
    char string[STRING_SIZE]; //Создание массива строки
    int counter = 0; //Счётчик
    while(fileInput.getline(string, STRING_SIZE)) { //Проверка на удачное считывание строки
        if(string[0] == ' ') //Проверка на начало строки с пробела
            counter++; //Инкрементация счётчика
    }
    cout<<counter; //Вывод счётчика
    fileInput.close(); //Закрытие потока
    return 0; //Выход из программы
}