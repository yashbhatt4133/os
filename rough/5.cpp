#include <iostream>
#include <unistd.h>
#include <fcntl.h>
using namespace std;
int main(int argc, char *argv[]){
    if (argc < 3){
        cout << "NOT ENOUGH ARGUEMENTS GIVEN" << endl;
        return 0;
    }
    char buffer_char;
    int fd1;
    int fd2;
    fd1 = open(argv[1] , O_RDONLY);
    if (fd1 == -1){
        cout << "Read file does not exist" << endl;
        close(fd1);
        return 0;
    }
    fd2 = open(argv[2] , O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    while (read(fd1 , &buffer_char, 1)){
        write(fd2, &buffer_char , 1);
    }
    cout << "Successful copy" << endl;
    close(fd1);
    close(fd2);
    return 0;
}
