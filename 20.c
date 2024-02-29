#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int pid = fork();

    if (pid == -1) {
        // Fork failed
        perror("Fork failed");
        return 1;
    } else if (pid > 0) {
        // Parent process
        printf("Parent process: My PID is %d\n", getpid());
    } else {
        // Child process
        printf("Child process: My PID is %d\n", getpid());
    }

    return 0;
}