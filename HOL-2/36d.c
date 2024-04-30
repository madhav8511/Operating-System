#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void create_fifo()
{
    int n = mknod("myfifo", __S_IFIFO, 0);
    if (n == 0)
    {
        printf("FIFO created successfully\n");
    }
    else
    {
        printf("FIFO creation failed\n");
    }
}

int main()
{
    create_fifo();
}