#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
    int fd1 = open("myfifo",O_RDONLY);
    int fd2 = open("myfifo1",O_WRONLY);
    char buf1[100],buf2[100];
    printf("Enter the data for other program\n");
    scanf("%[^\n]s",buf2);
    write(fd2,buf2,sizeof(buf2));
    read(fd1,buf1,sizeof(buf1));
    printf("The data from other program: %s\n",buf1);
    close(fd1);
    close(fd2);
}