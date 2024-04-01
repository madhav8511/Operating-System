#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int x = fork();  // Fork a child process
    int wstat;
    if (x< 0) 
        printf("Fork failed\n");

    else if (x == 0) {
        
        printf("Child process: PID=%d\n", getpid());

        // Perform some work
        printf("Child process is running...\n");
        sleep(5); 
        printf("Child process is stopped\n");
        // Exit
        exit(0);
    } 
    else 
    {
        // Parent process
        printf("Parent process: PID=%d, Child PID=%d\n", getpid(), x);

        // Wait for the child to complete
        int status;
        x=wait(&wstat);
        if (WIFEXITED(wstat)) 
            printf("Child process exited normally with status %d\n", WEXITSTATUS(wstat));
        else 
            printf("Child process exited abnormally\n");
    }
}