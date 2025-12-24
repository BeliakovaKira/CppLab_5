#include "FileTasks.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

struct BaggageItem {
    char name[50];
    double weight;
};

struct Passenger {
    vector<BaggageItem> items;
    int id;
};

void FileTasks::task3_2() {
    using namespace std;

    cout << "\n=== Задание 3.2 ===" << endl;
    cout << "Анализ багажа пассажиров" << endl;
    
    // структура для хранения данных
    vector<Passenger> passengers;
    
    BaggageItem items1[] = {
        {"Чемодан", 15.5},
        {"Сумка", 7.2},
        {"Рюкзак", 5.0}
    };
    
    BaggageItem items2[] = {
        {"Чемодан", 20.0}
    };
    
    BaggageItem items3[] = {
        {"Коробка", 3.5},
        {"Чемодан", 18.0},
        {"Сумка", 8.5},
        {"Пакет", 1.2}
    };
    
    BaggageItem items4[] = {
        {"Рюкзак", 4.0},
        {"Сумка", 6.5}
    };
    
    Passenger p1, p2, p3, p4;
    p1.id = 1;
    p2.id = 2;
    p3.id = 3;
    p4.id = 4;
    
    p1.items = vector<BaggageItem>(items1, items1 + 3);
    p2.items = vector<BaggageItem>(items2, items2 + 1);
    p3.items = vector<BaggageItem>(items3, items3 + 4);
    p4.items = vector<BaggageItem>(items4, items4 + 2);
    
    passengers.push_back(p1);
    passengers.push_back(p2);
    passengers.push_back(p3);
    passengers.push_back(p4);
    
    // записываем в файл
    string filename = "baggage.dat";
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Ошибка создания файла: " << filename << endl;
        return;
    }
    
    for (const auto& passenger : passengers) {
        // кол-во предметов
        int itemCount = passenger.items.size();
        outFile.write(reinterpret_cast<const char*>(&itemCount), sizeof(itemCount));
        
        // id пассажира
        outFile.write(reinterpret_cast<const char*>(&passenger.id), sizeof(passenger.id));
        
        // предметы
        for (const auto& item : passenger.items) {
            outFile.write(reinterpret_cast<const char*>(&item), sizeof(BaggageItem));
        }
    }
    
    outFile.close();
    cout << "Тестовые данные записаны в файл: " << filename << endl;
    
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Ошибка открытия файла: " << filename << endl;
        return;
    }
    
    vector<Passenger> readPassengers;
    int totalItems = 0;
    int totalPassengers = 0;
    
    while (inFile.peek() != EOF) {
        Passenger p;
        int itemCount;
        
        inFile.read(reinterpret_cast<char*>(&itemCount), sizeof(itemCount));
        inFile.read(reinterpret_cast<char*>(&p.id), sizeof(p.id));
        
        for (int i = 0; i < itemCount; i++) {
            BaggageItem item;
            inFile.read(reinterpret_cast<char*>(&item), sizeof(BaggageItem));
            p.items.push_back(item);
        }
        
        readPassengers.push_back(p);
        totalItems += itemCount;
        totalPassengers++;
    }
    
    inFile.close();
    
    double avgItemsPerPassenger = static_cast<double>(totalItems) / totalPassengers;
    
    int passengersWithMoreThanTwo = 0;
    int passengersAboveAverage = 0;
    
    cout << "\nСтатистика по пассажирам:" << endl;
    cout << "-------------------------" << endl;
    
    for (const auto& p : readPassengers) {
        int itemCount = p.items.size();
        
        cout << "Пассажир " << p.id << ": " << itemCount << " предметов" << endl;
        
        if (itemCount > 2) {
            passengersWithMoreThanTwo++;
        }
        
        if (itemCount > avgItemsPerPassenger) {
            passengersAboveAverage++;
        }
    }
    
    cout << "\nРезультаты:" << endl;
    cout << "-------------------------" << endl;
    cout << "Среднее количество предметов на пассажира: " << avgItemsPerPassenger << endl;
    cout << "Пассажиров с более чем 2 предметами: " << passengersWithMoreThanTwo << endl;
    cout << "Пассажиров с количеством предметов выше среднего: " << passengersAboveAverage << endl;
}