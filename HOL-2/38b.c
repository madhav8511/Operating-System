#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
    int fd1,fd2;
    fd1=open("myfifo",O_WRONLY);
    fd2 = open("myfifo1",O_RDONLY);
    char buf1[100],buf2[100];
    read(fd2,buf2,sizeof(buf2));
    printf("The data from other prog is : %s\n",buf2);
    printf("Enter the data for other program\n");
    scanf("%[^\n]s",buf1);
    write(fd1,buf1,sizeof(buf1));
    close(fd1);
    close(fd2);
}