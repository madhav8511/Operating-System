#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>

void handler2()
{
    printf("\nSIGINT received\n");
    exit(0);
}

int main()
{
    signal(SIGINT, handler2);
    printf("Waiting 5 seconds for SIGINT\n");
    sleep(5);
}