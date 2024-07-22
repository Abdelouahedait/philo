#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Thread function
void* fun1(void* arg)
{
    long *i = (void*) arg;
    printf("add : %ld\n", (*i - 1));
    return NULL;
    return NULL;
}
void* fun2(void* arg)
{
    long *i = (void*) arg;
    printf("add : %ld\n", *i - 1) ;
    return NULL;
}
int main()
{
    pthread_t thread;
    pthread_t thread1;
    long arg = 42;

    pthread_create(&thread, NULL, fun2, (void*)&arg);
        pthread_join(thread., NULL);

    pthread_create(&thread1, NULL, fun1, (void*)&arg);
    // fun1(&arg);
    // fun2(&arg);
    pthread_join(thread1, NULL);
    return 0;
}
