#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    //create_fifo();
    int fd = open("/tmp/myfifo",O_WRONLY | O_CREAT);

    char buffer[100];
    printf("Enter Message : ");
    scanf("%[^\n]",buffer);

    write(fd,buffer,sizeof(buffer));
}