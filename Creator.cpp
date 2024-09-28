#include <iostream>
#include <cstring>
#include <fstream>
#include "employee.h"

using namespace std;

int main(int args, char* argv[]){
    if(args < 3){
        cout << "there is no enough args in Creator.cpp" << endl;
        return 101;
    }

    string nameOfFile = argv[1];
    int amountOfRecords = stoi(argv[2]);
    ofstream outFile(nameOfFile, ios::binary);
    if (!outFile) {
        cout << "Error opening file for writing in Creator.cpp" << endl;
        return 102;
    }
    employee empl;
    while(amountOfRecords--){
        cout << "there are " << amountOfRecords+1 << " employeers remain to be inputed(num, name, addres)" << endl;
        cin >> empl.num >> empl.name >> empl.hours;
        if(cin.fail()){
            cout << "ошибка ввода";
            return 3;
        }
        outFile.write(reinterpret_cast<const char*>(&empl), sizeof(empl));
    }
    outFile.close();
    cout << "Creator complited succesfully" << endl;
    return 0;
}