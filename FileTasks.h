#ifndef FILETASKS_H
#define FILETASKS_H

#include <string>
#include <vector>

class FileTasks {
private:
    static bool isValidNumber(const std::string& str);
    static bool isValidPositiveNumber(const std::string& str);
    static bool isValidAge(int age);
    
public:
    static void task1_2();
    static void task2_2();
    static void task3_2();
    static void task4_2();
    static void task5_2();
    static void task6_2();
    
    static void fillBinaryFileWithNumbers(const std::string& filename, int count);
    static void fillTextFileOnePerLine(const std::string& filename, int count);
    static void fillTextFileMultiplePerLine(const std::string& filename, int lines, int maxNumbersPerLine);
};

#endif