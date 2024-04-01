#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int fd[2];
    char buf[20];
    char buf_1[20];

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    close(fd[0]); // Close read end in parent

    printf("Enter a message: ");
    fgets(buf, sizeof(buf), stdin);

    if (write(fd[1], buf, strlen(buf)) == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    close(fd[1]); // Close write end in parent

    read(fd[0], buf_1, sizeof(buf_1));
    write(1, buf_1, sizeof(buf_1));
    printf("\n");  // Add a newline to flush the buffer

    return 0;
}
