#include "FileTasks.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>


void FileTasks::task5_2() {
    using namespace std;

    cout << "\n=== Задание 5.2 ===" << endl;
    cout << "Вычисление произведения элементов в текстовом файле" << endl;
    
    string filename;
    cout << "Введите имя текстового файла: ";
    cin >> filename;
    
    string linesStr;
    int lines;
    
    do {
        cout << "Введите количество строк для генерации: ";
        cin >> linesStr;
    } while (!isValidPositiveNumber(linesStr));
    
    lines = stoi(linesStr);
    fillTextFileMultiplePerLine(filename, lines, 3);
    
    ifstream file(filename);
    if (!file) {
        cerr << "Ошибка открытия файла: " << filename << endl;
        return;
    }
    
    long long product = 1;
    int totalNumbers = 0;
    string line;
    int lineNum = 1;
    
    cout << "\nСодержимое файла:" << endl;
    cout << "-----------------" << endl;
    
    while (getline(file, line)) {
        cout << "Строка " << lineNum << ": " << line << endl;
        
        istringstream iss(line);
        int num;
        
        while (iss >> num) {
            product *= num;
            totalNumbers++;
        }
        
        lineNum++;
    }
    
    file.close();
    
    cout << "\nРезультат:" << endl;
    cout << "-----------------" << endl;
    cout << "Всего чисел: " << totalNumbers << endl;
    cout << "Произведение всех чисел: " << product << endl;
}