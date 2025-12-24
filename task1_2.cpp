#include "FileTasks.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

void FileTasks::task1_2() {
    using namespace std;

    cout << "\n=== Задание 1.2 ===" << endl;
    cout << "Вычисление произведения нечетных отрицательных чисел в бинарном файле" << endl;
    
    string filename;
    cout << "Введите имя бинарного файла: ";
    cin >> filename;
    
    string countStr;
    int numCount;
    
    do {
        cout << "Введите количество чисел для генерации (положительное число): ";
        cin >> countStr;
    } while (!isValidPositiveNumber(countStr));
    
    numCount = stoi(countStr);
    fillBinaryFileWithNumbers(filename, numCount);
    
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Ошибка открытия файла: " << filename << endl;
        return;
    }
    
    long long product = 1;
    bool found = false;
    int num;
    
    cout << "Нечетные отрицательные числа: ";
    while (file.read(reinterpret_cast<char*>(&num), sizeof(num))) {
        if (num < 0 && num % 2 != 0) {
            cout << num << " ";
            product *= num;
            found = true;
        }
    }
    
    file.close();
    
    if (!found) {
        cout << "Нет нечетных отрицательных чисел" << endl;
        product = 0;
    }
    
    cout << "\nПроизведение нечетных отрицательных чисел: " << product << endl;
}