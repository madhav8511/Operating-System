
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 

int main()
{
    FILE *file = fopen("12.txt", "a");
    int fd = fileno(file);
    int mode = fcntl(fd, F_GETFL);

    switch(mode){
        case 32768 : printf("read-mode\n"); break;
        case 32769 : printf("write-mode\n"); break;
        case 33793 : printf("append-mode\n"); break;
        case 32770 : printf("r+ || w+\n"); break;
        case 32794 : printf("a+\n"); break;
    }
}