#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void main(){

	int r = fork();
	if ( r < 0 )  {
		perror("Couldnt create new processes, exiting");
		exit(1);
	}
	if ( r != 0) {
        printf("Parent PID:%d\n",getpid());
		exit(0);

	} else {
        printf("Child PID:%d\n",getpid());
		for(int i=0;i<1000;i++);
        printf("Parent PID after old parent exit:%d\n",getppid());
    }
}