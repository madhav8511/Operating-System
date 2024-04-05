#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include <sys/wait.h>

int main()
{
    int fd[2];
    pipe(fd);

    if(!fork())
    {
        //Child....
        close(fd[1]);
        char buf[100];
        read(fd[0],buf,sizeof(buf));
        printf("Message child get : %s\n",buf);
    }
    else
    {
        close(fd[0]);
        char buf[100];
        printf("Message from parent to child : ");
        scanf("%[^\n]",buf);
        write(fd[1],buf,sizeof(buf));
    }
}