#include <stdio.h> //Подключение заголовочного файла
#define STRING_SIZE 80 //Определение константы длинны строки

int main() {
    FILE* fileInput = fopen("input.txt", "rt"); //Открытие файла
    if (!fileInput) { //Проверка на успешное открытие файла
        printf("Failed to open the file");
        return 1; //Выход из программы
    }
    int counter = 0; //Создание счётчика
    char string[STRING_SIZE]; //Создание массива для строки
    while(fgets(string, STRING_SIZE, fileInput)) { //Проверка на удачное считывание строки
        if (string[0] == ' ') //Проверка начала строки
            counter++; //Инкрементация счётчика
    }
    printf("%d", counter); //Вывод счётчика
    fclose(fileInput); //Закрытие файла
    return 0; //Выход из программы
}