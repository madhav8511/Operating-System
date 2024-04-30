#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>

void handler3()
{
    printf("Floating point error caught\n");
    exit(0);
}

int main()
{
    int x = 3;
    int y = 0;
    signal(SIGFPE, handler3);
    printf("%d\n", x / y);

    printf("No error\n");
}