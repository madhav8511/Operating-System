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
        int k = dup(1);
        close(1);
        k = dup(fd[1]);
        close(fd[0]);
        execlp("ls","ls","-l",(char *) NULL);
        return 0;
    }
    else
    {
        int k = dup(0);
        close(0);
        k = dup(fd[0]);
        close(fd[1]);
        execlp("wc","wc",(char *)NULL);
        return 0;
    }
}