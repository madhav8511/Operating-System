// Daemon Process -> works in the background that runs independently of the controlling terminal

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        printf("Error in fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        // Parent Process
        exit(0);
    }
    else {
        // Child Process
        setsid();// Create a new session and get it detached from the terminal
        chdir("/");// Change the working directory to root
        umask(0);// Change the file mode mask
        // This allows the daemon files to create files with any permissions
        printf("PID : %d\n",getpid());
        int fd_value = open("daemon_process_file", O_RDWR|O_CREAT, 0644);
        // 0644 stands for : 
        // owner has read and write permissions
        // group has read only permissions
        // others have read only permissions


        while(1) {
            sleep(10);
            printf("Into the daemon process\n");
        }
        close(fd_value);
    }   
    return 0;
}