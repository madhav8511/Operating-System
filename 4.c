#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = open("4.txt",O_EXCL | O_RDWR);
    if(fd == -1){
        printf("File not exist\n");
    }
    else{
        printf("File exist already in system\n");
    }
    printf("fd: %d\n",fd);
}