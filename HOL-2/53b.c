#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void handler()
{
    printf("Signal received\n");
}

int main()
{
    struct itimerval it;
    signal(SIGVTALRM, handler);

    /* Time to the next timer expiration.  */
    it.it_value.tv_sec = 10;
    it.it_value.tv_usec = 10;

    /* Value to put into `it_value' when the timer expires.  */
    it.it_interval.tv_sec = 10;
    it.it_interval.tv_usec = 10;

    setitimer(ITIMER_VIRTUAL, &it, NULL);

    while (1)
    {
    }
}