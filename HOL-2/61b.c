#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <bits/sigaction.h>

void catch (int sig){
    printf("Signal Caught - %d\n", sig);
    exit(0);
}

int main()
{
    struct sigaction ac;
    memset(&ac, 0, sizeof(ac));
    ac.sa_handler = catch;

    sigaction(SIGINT, &ac, NULL);
    for (;;);
}