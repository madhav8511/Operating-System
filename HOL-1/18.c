#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/stat.h>
#include <fcntl.h> 

int main()
{
    int arr[] = {0, 0, 0};
    int fd = open("18.txt", O_RDWR);
    write(fd, arr, sizeof(arr));
    close(fd);
}