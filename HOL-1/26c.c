
#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[], char *envp[])
{
    printf("Executes ls -Rl using execle");
    execle("/bin/ls", "/bin/ls", "-R", "-l", NULL, envp);
    return(0);
}