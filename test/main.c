#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>

int g = 0;
// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *myThreadFun(void *vargp)
{
    int *myid = (int *)vargp;
    static int s = 0;
    ++s;
    ++g;
    printf("Thread ID: %d, Static: %d, Global: %d\n", *myid, ++s, ++g);

    // sleep(1);
    // printf("Printing GeeksQuiz from Thread \n");
    return NULL;
}

int main()
{
    pthread_t thread_id;
    printf("Before Thread\n");
    for (int i = 0; i < 3; i++)
    {
        pthread_create(&thread_id, NULL, myThreadFun, (void *)&thread_id);
    }
    // pthread_create(&thread_id, NULL, myThreadFun, NULL);
    // pthread_join(thread_id, NULL);
    pthread_exit(NULL);
    printf("After Thread\n");
    exit(0);
}