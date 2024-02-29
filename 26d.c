
#include<stdio.h>
#include<unistd.h>

int main()
{
    printf("Executes ls -Rl using execv");
    char* arr[] = {"/bin/ls", "/bin/ls", "-R", "-l", NULL};
    execv(arr[0], arr);
}