#include <stdio.h>
#include <unistd.h> //allows to use dup(),open()
#include <fcntl.h> // provides functions and constants to work with file descriptors 

int main()
{
    int fd1=open("11.txt",O_WRONLY | O_APPEND);
    int fd2=dup(fd1);
    write(fd1,"Start\n",6);
    write(fd2,"Another dup\n",12);
    dup2(fd1,4);
    write(4,"Through dup2\n",13);
    int fd3=fcntl(fd1,F_DUPFD,0);
    write(fd3,"EXIT\n",5);
    close(fd1);
    close(fd2);
    close(fd3);
}