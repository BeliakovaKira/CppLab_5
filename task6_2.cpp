#include "FileTasks.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

void FileTasks::task6_2() {
    using namespace std;

    cout << "\n=== Задание 6.2 ===" << endl;
    
    string inputFilename = "text_input.txt";
    ofstream inputFile(inputFilename);
    
    if (!inputFile) {
        cerr << "Ошибка создания файла: " << inputFilename << endl;
        return;
    }
    
    inputFile << "cat" << endl;
    inputFile << "dog" << endl;
    inputFile << "banana" << endl;
    inputFile << "apple" << endl;
    inputFile << "hello" << endl;
    inputFile << "world" << endl;
    inputFile << "sun" << endl;
    inputFile << "moon" << endl;
    inputFile << "star" << endl;
    inputFile << "book" << endl;
    inputFile << "pen" << endl;
    inputFile << "car" << endl;
    inputFile << "house" << endl;
    inputFile << "tree" << endl;
    inputFile << "water" << endl;
    
    inputFile.close();
    cout << "Исходный файл создан: " << inputFilename << endl;
    
    ifstream inFileForDisplay(inputFilename);
    if (!inFileForDisplay) {
        cerr << "Ошибка открытия файла: " << inputFilename << endl;
        return;
    }
    
    cout << "\nСодержание файла " << inputFilename << ":" << endl;
    cout << "=========================================" << endl;
    
    string line;
    int totalLines = 0;
    
    while (getline(inFileForDisplay, line)) {
        size_t length = line.length();
        cout << line << " (" << length << " симв.)" << endl;
        totalLines++;
    }
    
    inFileForDisplay.close();
    
    cout << "\nВсего строк в файле: " << totalLines << endl;
    
    string lengthStr;
    int m;
    
    do {
        cout << "\nВведите длину строки: ";
        cin >> lengthStr;
    } while (!isValidPositiveNumber(lengthStr));
    
    m = stoi(lengthStr);
    
    ifstream inFile(inputFilename);
    if (!inFile) {
        cerr << "Ошибка открытия файла: " << inputFilename << endl;
        return;
    }
    
    string outputFilename = "text_output.txt";
    ofstream outFile(outputFilename);
    
    if (!outFile) {
        cerr << "Ошибка создания файла: " << outputFilename << endl;
        inFile.close();
        return;
    }
    
    int foundCount = 0;
    
    cout << "\nСтроки длиной " << m << " символов:" << endl;
    cout << "=========================================" << endl;
    
    while (getline(inFile, line)) {
        size_t length = line.length();
        if (length == m) {
            cout << line << endl;
            outFile << line << endl;
            foundCount++;
        }
    }
    
    inFile.close();
    outFile.close();
    
    cout << "Количество строк длины " << m << ": " << foundCount << endl;
    
    if (foundCount > 0) {
        cout << "Результат записан в файл: " << outputFilename << endl;
    } else {
        cout << "Не найдено строк заданной длины." << endl;
        remove(outputFilename.c_str());
    }
}
