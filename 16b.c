#include <stdio.h>
#include <unistd.h> 
#include <fcntl.h>  

int main()
{
    int fd = open("16.txt",O_RDONLY);

    // Define a file lock structure for reading
    struct flock readlk;
    readlk.l_type=F_RDLCK; // Set the lock type to read lock
    readlk.l_whence=SEEK_SET; // set starting offset to lock to beginning of file
    readlk.l_start=0; // set the starting offset to zero
    readlk.l_len=0; // set the length of lock to zero
    readlk.l_pid=getpid(); // set process id of locking process

    // Set a read lock on file
    int status = fcntl(fd,F_SETLKW,&readlk);
    if(status==-1)
        printf("could not lock the file\n");
    else
        printf("Read Lock implemented\n");

    // Unlocking the file
    printf("Enter to Unlock\n");
    getchar();

    readlk.l_type=F_UNLCK;
    status = fcntl(fd,F_SETLKW,&readlk);
    if(status==-1)
        printf("The file could not be unlocked\n");
    else
    printf("The file is now unlocked\n");
    close(fd);
}