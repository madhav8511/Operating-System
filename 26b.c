
#include<stdio.h>
#include<unistd.h>

int main()
{
    printf("Executes ls -Rl using execlp\n");
    execlp("ls", "ls","-R", "-l", NULL);
    return(0);
}