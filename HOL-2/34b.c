#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include<sys/wait.h>

int main()
{
    int fd[2];
    pipe(fd);

    if(!fork())
    {
        //Child process....
        dup2(fd[1],1);
        close(fd[0]);
        execlp("ls","ls","-l",(char *) NULL);
        return 0;
    }
    else
    {
        //Parent process..
        dup2(fd[0],0);
        close(fd[1]);
        execlp("wc","wc",(char *)NULL);
        return 0;
    }
}