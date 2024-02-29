#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <fcntl.h>

int main(void){
    int fd = creat("3.txt",0744);
    printf("file descriptor value : %d\n",fd);
}