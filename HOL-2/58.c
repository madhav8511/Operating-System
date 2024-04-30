#include <pthread.h>
#include <stdio.h>
// Use gcc 58.c -lpthread

void show_thread(void)
{
    pthread_t tid = pthread_self();
    printf("This is a thread with id : %ld\n",(unsigned long)tid);
}

int main()
{
    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL, (void *)show_thread, NULL);
    pthread_create(&t2, NULL, (void *)show_thread, NULL);
    pthread_create(&t3, NULL, (void *)show_thread, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    return 0;
}