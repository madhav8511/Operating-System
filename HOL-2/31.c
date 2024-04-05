#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include <sys/wait.h>

int main()
{
    int fd[2];
    pipe(fd);

    char buffer[100];
    printf("Enter Message : ");
    scanf("%[^\n]",buffer);
    write(fd[1],buffer,sizeof(buffer));

    close(fd[1]);
    char buf[100];
    read(fd[0],buf,sizeof(buf));
    printf("Messsage : %s\n",buf);
}