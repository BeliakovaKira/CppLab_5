#include "FileTasks.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

void FileTasks::task2_2() {
    cout << "\n=== Задание 2.2 ===" << endl;
    cout << "Копирование в квадратную матрицу и замена мин/макс в столбцах" << endl;
    
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
    
    string sizeStr;
    int n;
    
    do {
        cout << "Введите размер квадратной матрицы n (положительное число): ";
        cin >> sizeStr;
    } while (!isValidPositiveNumber(sizeStr));
    
    n = stoi(sizeStr);
    
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Ошибка открытия файла: " << filename << endl;
        return;
    }
    
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int row = 0, col = 0;
    int num;
    
    while (file.read(reinterpret_cast<char*>(&num), sizeof(num)) && row < n) {
        matrix[row][col] = num;
        col++;
        if (col == n) {
            col = 0;
            row++;
        }
    }
    
    file.close();
    
    cout << "\nИсходная матрица " << n << "x" << n << ":" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
    
    for (int j = 0; j < n; j++) {
        int minVal = matrix[0][j];
        int maxVal = matrix[0][j];
        int minRow = 0, maxRow = 0;
        
        for (int i = 1; i < n; i++) {
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
                minRow = i;
            }
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
                maxRow = i;
            }
        }
        
        if (minRow != maxRow) {
            swap(matrix[minRow][j], matrix[maxRow][j]);
        }
    }
    
    cout << "\nМатрица после замены мин и макс в каждом столбце:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
}