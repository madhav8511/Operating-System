

#include<stdio.h>
#include<unistd.h>

int main()
{
    printf("Executes ls -Rl using execl\n");
    execl("/bin/ls", "/bin/ls", "-R", "-l", NULL);
    return(0);
}