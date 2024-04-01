#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(){    
    int i, stat;
    int pid[3];
    for (i = 0; i < 3; i++)
    {
        pid[i] = fork();
        if (pid[i] == 0)
        {
            printf("child %d, %d\n", i, getpid());
            if(i == 1){
                sleep(10);
            }
            exit(100 + i);
        }
    }
    int cpid_to_wait = waitpid(pid[1], &stat, 0);
    printf("Child %d terminated with status: %d\n", cpid_to_wait, WEXITSTATUS(stat));
    return 0;
}