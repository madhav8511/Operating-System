
#include<stdio.h>
#include<unistd.h>

int main()
{
    printf("Executes ls -Rl using execv");
    char* arr[] = {"ls", "-R", "-l", NULL};
    execvp("ls", arr);
}