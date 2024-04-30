#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <bits/sigaction.h>

void catch (int sig)
{
    printf("Signal Caught - %d\n", sig);
    exit(0);
}

int main()
{
    printf("pid (reciever): %d\n", getpid());

    struct sigaction ac;
    memset(&ac, 0, sizeof(ac));
    
    // The handler will be ignored, as SIGSTOP and SIGKILL can not be caught.
    ac.sa_handler = catch;
    for (;;)
    {
        sigaction(SIGSTOP, &ac, NULL);
    }
    return (0);
}