#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>

void handler1()
{
    printf("Segmentation fault caught\n");
    exit(0);
}

int main()
{
    signal(SIGSEGV, handler1);

    char *str;
    str = NULL;
    printf("%c\n", *(str + 1));

    printf("No segmentation fault\n");
}