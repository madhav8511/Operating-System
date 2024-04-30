#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    long PIPE_BUFFER, OPEN_MAXIMUM;
    
    PIPE_BUFFER = pathconf(".", _PC_PIPE_BUF);
    OPEN_MAXIMUM = sysconf(_SC_OPEN_MAX);

    printf("Pipe_buf = %ld\nOpen_max = %ld\n", PIPE_BUFFER, OPEN_MAXIMUM);
    
    return(0);
}