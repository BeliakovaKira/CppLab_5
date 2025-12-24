#include "FileTasks.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

void showMenu() {
    cout << "1. Задание 1.2: Произведение нечетных отрицательных чисел" << endl;
    cout << "2. Задание 2.2: Квадратная матрица с заменой в столбцах" << endl;
    cout << "3. Задание 3.2: Анализ багажа пассажиров" << endl;
    cout << "4. Задание 4.2: Сумма квадратов элементов" << endl;
    cout << "5. Задание 5.2: Произведение элементов" << endl;
    cout << "6. Задание 6.2: Строки заданной длины" << endl;
    cout << "0. Выход" << endl;
}

int main() {
    int choice;
    
    do {
        showMenu();
        cout << "Выберите задание (0-6): ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода! Пожалуйста, введите число от 0 до 6." << endl;
            continue;
        }
        
        switch (choice) {
            case 1:
                FileTasks::task1_2();
                break;
            case 2:
                FileTasks::task2_2();
                break;
            case 3:
                FileTasks::task3_2();
                break;
            case 4:
                FileTasks::task4_2();
                break;
            case 5:
                FileTasks::task5_2();
                break;
            case 6:
                FileTasks::task6_2();
                break;
            case 0:
                cout << "Выход из программы." << endl;
                break;
            default:
                cout << "Неверный выбор! Пожалуйста, выберите от 0 до 6." << endl;
        }
        
        if (choice != 0) {
            cout << "\nНажмите Enter для продолжения...";
            cin.ignore();
            cin.get();
        }
        
    } while (choice != 0);
    
    return 0;
}