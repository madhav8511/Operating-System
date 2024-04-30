#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void create_fifo()
{
    int n = mkfifo("myfifo-1",0);
    if(n == 0)
    {
        printf("Fifo created successfully\n");
    }
    else{
        printf("Fifo not created\n");
    }
}

int main()
{
    create_fifo();
}