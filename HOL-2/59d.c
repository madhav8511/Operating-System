#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>

void handler(int signum)
{
    printf("Signal received (alarm related)\n");
    // exit(0);
}

int main()
{
    signal(SIGALRM, handler);

    while (1)
    {
        printf("Alarm set\n");
        alarm(2);
        sleep(3);
    }
}