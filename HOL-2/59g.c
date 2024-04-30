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
    struct itimerval it;
    // Set timer value.
    it.it_value.tv_sec = 2;
    it.it_value.tv_usec = 0;

    // Reset value on timer after completion.
    it.it_interval.tv_sec = 2;
    it.it_interval.tv_usec = 0;
    
    signal(SIGVTALRM, handler);
    setitimer(ITIMER_VIRTUAL, &it, NULL);

    while (1)
    {
    }
}