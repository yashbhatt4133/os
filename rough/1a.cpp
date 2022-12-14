#include <iostream>
#include <unistd.h>
#include <stdlib.h>
using namespace std;
int main(){
    pid_t p1, p2;
    p1 = getpid();
    p2 = fork();
    if (p2 < 0){
        cout << "Error in creating child process" << endl;
        return 1;
    }
    cout << "Fork ID = " << p2 << endl;
    cout << "Process ID = " << p1 << endl;
    return 0;
}
