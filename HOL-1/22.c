#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {

    int r = fork();
    if (r < 0) {
        perror("Could not create new process, exiting");
        exit(1);
    }

    if (r == 0) {
        // Child simply exits
		printf("%d\n",getpid());
        exit(0);
    } else {
		printf("%d\n",getpid());
        // Parent then enters a loop
        for (int i = 0; i < 100; i++)
            printf("%d\n",i),
            sleep(1);
    }

    return 0;
}
