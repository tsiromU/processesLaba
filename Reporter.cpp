#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "employee.h"


using namespace std;

int main(int args, char* argv[]){
    if(args < 4){
        cout << "there is no enough arguments in reporter.cpp";
    }
    string binaryFile = argv[1];
    string reportFile = argv[2];
    double payPerHour = stod(argv[3]);

    ifstream inputFile(binaryFile, ios::binary);
    ofstream outputFile(reportFile);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Error with files in reporter.cpp" << endl;
        return 6;
    }

    outputFile << "Отчет по файлу \"" << binaryFile << "\"";
    outputFile << endl;
    outputFile << setw(17) << "Name" << "|"; 
    outputFile << setw(17) << "Ident. number" << "|"; 
    outputFile << setw(17) << "H'ours" << "|"; 
    outputFile << setw(17) << "Wage" << endl; 

    employee emp;
    while (inputFile.read(reinterpret_cast<char*>(&emp), sizeof(emp))) {
        double wage = emp.hours * payPerHour;
        outputFile << setw(17) << emp.name << "|"; 
        outputFile << setw(17) << emp.num << "|"; 
        outputFile << setw(17) << emp.hours << "|";
        outputFile << setw(17) << wage << endl;
    }

    inputFile.close();
    outputFile.close();
    cout << "Reporter complited succesfully" << endl;
    return 0;
}