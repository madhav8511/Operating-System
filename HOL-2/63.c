#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    // Child Process
    if (!fork())
    {
        sleep(5);
        printf("Initial Parent id : %d\n",getppid());
        printf("Child is waiting, pid: %d\n", getpid());
        kill(getppid(), 9);
        printf("Parent process killed\n");
        printf("New parent id : %d\n",getppid());
        sleep(10);
    }
    else
    {
        printf("Parent Process, pid: %d\n", getpid());
        sleep(15);
    }

    return 0;
}