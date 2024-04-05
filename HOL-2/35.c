
#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include<sys/wait.h>

int main(){
    int fd1[2];
    int fd2[2];

    if(pipe(fd1) == -1 || pipe(fd2) == -1){
        printf("Pipe Error\n");
        return 0;
    }

    if(!fork()){
        //Child ....
        dup2(fd1[1],1); 
        close(fd1[0]); 
        close(fd2[1]);
        close(fd2[0]);
        execlp("ls","ls","-Rl",(char *) NULL); //Write to fd1 pipe....
        return 0;
    }
    else{

        if(!fork()){
            //Another child....
            dup2(fd1[0],0);
            dup2(fd2[1],1); 
            close(fd1[1]); 
            close(fd2[0]); 
            execlp("grep","grep","^d",(char *) NULL); //read from fd1 and write to fd2 pipe....
            return 0;

        }

        else{
            //Parent.....
            dup2(fd2[0],0);
            close(fd2[1]); 
            close(fd1[0]); 
            close(fd1[1]); 
            execlp("wc","wc","-l",(char *)NULL); // read from fd2 pipe....
        }

    }
    return 0;
}