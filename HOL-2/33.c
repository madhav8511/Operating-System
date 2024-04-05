#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd1[2];
    int fd2[2];

    pipe(fd1);
    pipe(fd2);

    char buf[100];
    char buffer[100];

    if(!fork())
    {
        //Child....
        close(fd1[0]);
        close(fd2[1]);

        printf("Enter message to parent: \n");
        scanf("%[^\n]",buf);
        write(fd1[1],buf,sizeof(buf));

        read(fd2[0],buffer,sizeof(buffer));
        printf("Message from parent : %s\n",buffer);

    }
    else{
        //Parent...
        close(fd1[1]);
        close(fd2[0]);

        printf("Enter message to child: \n");
        scanf("%[^\n]",buf);
        write(fd2[1],buf,sizeof(buf));

        read(fd1[0],buffer,sizeof(buffer));
        printf("Message from child : %s\n",buffer);

    }
    wait(0);
}
