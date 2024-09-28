#include <iostream>
#include <sys/wait.h>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

void execute_command(const string& command) {
    char* cmd = new char[command.length() + 1];
    strcpy(cmd, command.c_str());
    std::vector<char*> args;

    char* token = strtok(cmd, " ");
    while (token != nullptr) {
        args.push_back(token);
        token = strtok(nullptr, " ");
    }
    args.push_back(nullptr);

    pid_t pid = fork();
    if (pid == 0) {// child process
        execvp(args[0], args.data());
        cout << "execvp failed calling " << args[0] << endl; 
        exit(2);
    } else if (pid > 0) {//parent process
        int status;
        waitpid(pid, &status, 0);
    } else {// Fork failed
        cout << "fork failed" << endl;
        exit(1);
    }
    delete[] cmd;
}


int main(){
    string binFile, reportFile;
    string PathToCreatorFile("./Creator");
    string PathToReporterFile("./Reporter");
    int recordCount;
    double payPerHour;

    cout << "Enter binary file name: ";
    cin >> binFile;
    cout << "Enter number of emloyeers: ";
    cin >> recordCount;
    execute_command(PathToCreatorFile + " " + binFile + " " + to_string(recordCount));
    cout << "Enter report file name: ";
    cin >> reportFile;
    cout << "Enter pay per hour: ";
    cin >> payPerHour;
    execute_command(PathToReporterFile + " " + binFile + " " + reportFile + " " + to_string(payPerHour));

    return 0;
    
}