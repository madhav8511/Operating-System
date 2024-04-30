#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    int pid;
    printf("Enter pid of process to stop\n");
    scanf("%d", &pid);

    printf("Sending SIGSTOP signal to process: %d\n", pid);
    kill(pid, SIGSTOP);

    printf("SIGSTOP signal sent\n");
    printf("Exiting current process (sender)\n");
    return (0);
}