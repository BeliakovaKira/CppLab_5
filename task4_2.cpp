#include "FileTasks.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void FileTasks::task4_2() {
    cout << "\n=== Задание 4.2 ===" << endl;
    cout << "Нахождение суммы квадратов элементов в текстовом файле" << endl;
    
    string filename;
    cout << "Введите имя текстового файла: ";
    cin >> filename;
    
    string countStr;
    int numCount;
    
    do {
        cout << "Введите количество чисел для генерации (положительное число): ";
        cin >> countStr;
    } while (!isValidPositiveNumber(countStr));
    
    numCount = stoi(countStr);
    fillTextFileOnePerLine(filename, numCount);
    
    ifstream file(filename);
    if (!file) {
        cerr << "Ошибка открытия файла: " << filename << endl;
        return;
    }
    
    long long sumOfSquares = 0;
    int num;
    int count = 0;
    
    cout << "\nЧисла из файла и их квадраты:" << endl;
    cout << "------------------------------" << endl;
    
    while (file >> num) {
        int square = num * num;
        sumOfSquares += square;
        count++;
        
        cout << "Число: " << num << ", Квадрат: " << square << endl;
    }
    
    file.close();
    
    cout << "\nРезультат:" << endl;
    cout << "------------------------------" << endl;
    cout << "Прочитано чисел: " << count << endl;
    cout << "Сумма квадратов: " << sumOfSquares << endl;
}