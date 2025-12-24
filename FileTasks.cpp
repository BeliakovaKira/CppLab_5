#include "FileTasks.h"
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

bool FileTasks::isValidNumber(const string& str) {
    if (str.empty()) return false;
    
    size_t start = 0;
    if (str[0] == '-' && str.length() > 1) {
        start = 1;
    }
    
    for (size_t i = start; i < str.length(); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

bool FileTasks::isValidPositiveNumber(const string& str) {
    if (str.empty()) return false;
    
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    
    int num = stoi(str);
    return num > 0;
}

bool FileTasks::isValidAge(int age) {
    return age >= 0 && age <= 18;
}

void FileTasks::fillBinaryFileWithNumbers(const string& filename, int count) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cerr << "Ошибка создания файла: " << filename << endl;
        return;
    }
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(-10, 10);
    
    for (int i = 0; i < count; i++) {
        int num = dist(gen);
        file.write(reinterpret_cast<char*>(&num), sizeof(num));
    }
    
    file.close();
    cout << "Файл " << filename << " заполнен " << count << " случайными числами" << endl;
}

void FileTasks::fillTextFileOnePerLine(const string& filename, int count) {
    ofstream file(filename);
    if (!file) {
        cerr << "Ошибка создания файла: " << filename << endl;
        return;
    }
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(-10, 10);
    
    for (int i = 0; i < count; i++) {
        file << dist(gen) << endl;
    }
    
    file.close();
    cout << "Файл " << filename << " заполнен " << count << " числами (по одному в строке)" << endl;
}

void FileTasks::fillTextFileMultiplePerLine(const string& filename, int lines, int maxNumbersPerLine) {
    ofstream file(filename);
    if (!file) {
        cerr << "Ошибка создания файла: " << filename << endl;
        return;
    }
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(-10, 10);
    uniform_int_distribution<int> countDist(1, maxNumbersPerLine);
    
    for (int i = 0; i < lines; i++) {
        int numbersInLine = countDist(gen);
        for (int j = 0; j < numbersInLine; j++) {
            file << dist(gen);
            if (j < numbersInLine - 1) {
                file << " ";
            }
        }
        file << endl;
    }
    
    file.close();
    cout << "Файл " << filename << " заполнен " << lines << " строками с числами" << endl;
}