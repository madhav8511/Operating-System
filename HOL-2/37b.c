#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    char buf[100];
    int fd = open("/tmp/myfifo",O_RDONLY);

    int k = read(fd,buf,sizeof(buf));
    printf("Message : %s\n",buf);
}