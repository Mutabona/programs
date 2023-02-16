#include <stdlib.h>
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int n = 0;

struct bank_client {
    int number;
    string surName;
    string name;
    string otchestvo;
    string city;
    int street;
    int house;
    int flat;
};

void sort(bank_client* bc) {
    int imin;
    bank_client temp;
    for (int i = 0; i < n - 1; i++) {
        temp = bc[i];
        imin = i;
        for (int j = i + 1; j < n; j++) {
            if (bc[j].street < temp.street) {
                imin = j;
                temp = bc[j];
            }
        }
        bc[imin] = bc[i];
        bc[i] = temp;
    }
}

void addClients(bank_client* bc) {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    for (int i = 0; i < n; i++) {
        bc[i].number = i;
        cout << "Фамиля: "; cin >> bc[i].surName;
        cout << "Имя: "; cin >> bc[i].name;
        cout << "Отчествя: "; cin >> bc[i].otchestvo;
        cout << "Городя: "; cin >> bc[i].city;
        cout << "Улиця: "; cin >> bc[i].street;
        cout << "Домя: "; cin >> bc[i].house;
        cout << "Квартиря: "; cin >> bc[i].flat;
    }
}

void printBC(bank_client* bc) {
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    for (int i = 0; i < n; i++) {
        cout << bc[i].number << endl;
        cout << bc[i].name << endl;
        cout << bc[i].surName << endl;
        cout << bc[i].otchestvo << endl;
        cout << bc[i].city << endl;
        cout << bc[i].street << endl;
        cout << bc[i].house << endl;
        cout << bc[i].flat << endl;
        cout << '\n';
    }
}

int find(bank_client* bc, char c) {
    bool f = 0;
    int count = 0;
    bank_client temp;
    for (int i = 0; i < n; i++) {
        if (bc[i].surName[0] == c) {
            if (!f) {
                temp = bc[i];
                f = 1;
                count++;
            }
            else {
                if ((temp.city == bc[i].city) && (temp.street == bc[i].street) && (temp.house == bc[i].house)) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    bank_client* bancClients = NULL;
    int t = 0;
    do {
        cout << "1 Поиск" << endl;
        cout << "2 Завод" << endl;
        cout << "3 СортировОчка" << endl;
        cout << "4 Вывод" << endl;
        cout << "5 Смэрть" << endl;
        cin >> t;
        switch (t) {
        case 1: {
            char c; cout << "Буква: "; cin >> c;
            cout << find(bancClients, c) << endl;
            break;
        }
        case 2: {
            if (!bancClients) {
                cout << "Скока? "; cin >> n;
                bancClients = new bank_client[n];
                addClients(bancClients);
            }
            break;
        }
        case 3: {
            sort(bancClients);
            break;
        }
        case 4: {
            printBC(bancClients);
            break;
        }
        case 5: {
            delete[] bancClients;
            break;
        }
        }
    } while (t != 5);
    return 0;
}